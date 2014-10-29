/*
    Copyright (C) 2014 Kim Lester
    http://www.dfusion.com.au/

    This Program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This Program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this Program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>

#include "libc.h"
#include "psoc5.h"
#include "config.h"


// Note: I believe most unaligned data accesses are supported on Cortex M3 (ARMv7-M cores). I think a register may have to be set as well (CP15 ?)

typedef struct {
	void *address;
	uint16_t size;
} PACKED cfg_memset_t;


// Defines the layout and meaning of each entry in the cfg_memcpy_list used for initializing registers
typedef struct {
	void *dest;
	const void *src;
	uint16_t size;
} PACKED cfg_memcpy_t;


typedef struct {
	uint8_t offset;
	uint8_t value;
} PACKED cfg_data_t;


// Contains the regions of memory that must be zeroed during configuration
// Whilst we could zero all registers in a region the preference seems to
// be to only zero those that aren't about to be configured, possibly to
// better handle IO during some reset conditions (or it may be irrelevant in
// which case we could simplify things here)

static const cfg_memset_t cfg_memset_list [] = {
	/* address, size */
        // PRTx: Don't reset ports 0, 2 (we config and use those later)
	{(void *)(REG_PRTx_BASE(1)), PRTx_REG_SIZE},
	{(void *)(REG_PRTx_BASE(3)), 4 * PRTx_REG_SIZE}, // 3 - 6
	{(void *)(REG_PRTx_BASE(12)), PRTx_REG_SIZE},
	{(void *)(REG_PRTx_BASE(15)), PRTx_REG_SIZE},
	{(void *)(REG_UDB_CFG_B0_BASE), REG_UDB_CFG_Bi_SIZE},
	{(void *)(REG_UDB_CFG_B1_IMPLEMENTED_BASE), REG_UDB_CFG_B1_IMPLEMENTED_SIZE},
	{(void *)(REG_UDB_CFG_DSI_BASE), REG_UDB_CFG_DSI_SIZE}, // ignored gap in middle
	{(void *)(REG_BCTL_BASE), 2 * REG_BCTLi_SIZE},
};


static void cfg_zero_regions(void)
{
    // Zero out critical memory blocks before beginning configuration

    uint8_t i;
    uint8_t len = sizeof(cfg_memset_list)/sizeof(*cfg_memset_list);

    for (i = 0; i < len; i++)
    {
        const cfg_memset_t *ms = &cfg_memset_list[i];
        memset(ms->address, 0, ms->size);
    }
}


static void cfg_sparse_regions(void)
{
    // For 32-bit little-endian architectures
    // Writes chip sparse configuration - index, value

    unsigned int i, j = 0;
    for (i = 0; i < CONFIG_ADDR_TABLE_NELTS; i++)
    {
        uint32_t baseAddr = ((const uint32_t *)CONFIG_ADDR_TABLE_ADDR)[i];
        uint8_t count = baseAddr & 0xFFu;
        baseAddr &= 0xFFFFFF00u;
        while (count--)
        {
            const cfg_data_t *data_item = &((const cfg_data_t *)CONFIG_DATA_TABLE_ADDR)[j];
            REG_SET_8((baseAddr + data_item->offset), data_item->value);
            j++;
        }
    }
}


static void cfg_copy_regions(void)
{
    memcpy(((void *)CONFIG_INITCOPY_0_DEST_ADDR), (void *)(CONFIG_INITCOPY_0_SRC_ADDR),
        CONFIG_INITCOPY_0_LEN);

    memcpy(((void *)CONFIG_INITCOPY_1_DEST_ADDR), (void *)(CONFIG_INITCOPY_1_SRC_ADDR),
        CONFIG_INITCOPY_1_LEN);

#if 0
    memcpy(((void *)CONFIG_INITCOPY_2_DEST_ADDR), (void *)(CONFIG_INITCOPY_2_SRC_ADDR),
        CONFIG_INITCOPY_2_LEN);
#endif
}


void app_config(void)
{
        cfg_zero_regions(); // must come first (in case of overlaps)
        cfg_sparse_regions();
        cfg_copy_regions();
}
