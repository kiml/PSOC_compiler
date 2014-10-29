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


#if DEBUG
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#endif


// Config Table Types
#define CFG_TT_END 0
#define CFG_TT_CF 1
#define CFG_TT_OV 2
#define CFG_TT_DA 3
#define CFG_TT_AC 4

#define config_base_addr ((const uint8_t *)0x48000000)

static void cfg_set_regions(const uint8_t *cfg_base_addr)
{
    // Note: count is [cc]cc + 1. Zero is not allowed except in END case.

    // table: [ ttcc aaaa aaaa <element> ]* 0000 0000 
    //          tt = type, cc = value|00
    // element: tt == 1:  constant fill subtable
    //           ccvv   # cccc
    // element: tt == 2:  offset value subtable
    //           [ oovv ]+(cc)
    // element: tt == 3:  data array subtable
    //           [ vv ]+(cc)
    // element: tt == 4:  address copy subtable
    //           ssss ssss

    //uint32_t *tablebase = &config_base_addr[0];
    // WARNING for compactness 32 bit addresses are NOT aligned on relevant memory boundaries.
    // easiest way to manage data is 8 bit chunks. (unless I pad case 3 for cc == 1)

    const uint8_t *tbl = cfg_base_addr;
    while(1)
    {
        uint8_t table_type = tbl[0];
        uint32_t count = tbl[1] + 1; // Note + 1. uint32_t to handle count=63336. 

#if DEBUG
        printf("Table Type: %d\n", table_type);
#endif
        if (table_type == CFG_TT_END) break;

        uint32_t addr = (tbl[5] << 24) | (tbl[4] << 16) | (tbl[3] << 8) | tbl[2];
        uint8_t *ap = (uint8_t *)(intptr_t)addr;
       
        tbl += 6;

        if (table_type == CFG_TT_CF)
        {
            // constant fill: ccvv
            uint8_t count_hi = tbl[0];
            uint8_t value = tbl[1];
            count += (count_hi << 8);
#if DEBUG
            printf("  CF: %p = 0x%02x * %d\n", ap, value, count);
#else
            memset(ap, value, count);
#endif
            tbl += 2;
        }
        else if (table_type == CFG_TT_OV)
        {
            // offset value: [ oovv ]+(count)
            uint8_t i;
            for(i=0; i<count; i++)
            {
                uint8_t offset = tbl[0];
                uint8_t value = tbl[1];
#if DEBUG
                printf("  OV %d/%d: %p[%d] = 0x%02x\n", i, count, ap, offset, value);
#else
                ap[offset] = value;
#endif
                tbl += 2;
            }
        }
        else if (table_type == CFG_TT_DA)
        {
            // data array: [ vv ]+(cc)
#if DEBUG
            printf("  DA: %p (%d) = ", ap, count);
            int i;
            for(i=0; i<count; i++)
                printf("%02x ", tbl[i]);
            printf("\n");
#else
            memcpy(ap, tbl, count);
#endif
            tbl += count;
        }
        else if (table_type == CFG_TT_AC)
        {
            // copy mem: ssss ssss
            uint32_t saddr = (tbl[3] << 24) | (tbl[2] << 16) | (tbl[1] << 8) | tbl[0];
            uint8_t *sap = (uint8_t *)(intptr_t)saddr;
#if DEBUG
            printf("  DA: %p = %p * %d\n", ap, sap, count);
#else
            memcpy(ap, sap, count);
#endif
            tbl += 4;
        }
#if DEBUG
        else
        {
            printf("  Error: Unknown type", table_type);
        }
#endif
    }
}



void app_config(void)
{
    cfg_set_regions(config_base_addr);
}


#if DEBUG
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "%s CONFIG.BIN", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1],"r");
    if (!fp)
    {
        fprintf(stderr, "Failed to open file: %s", argv[1]);
        exit(1);
    }
    
    struct stat st;
    if (fstat(fileno(fp), &st) != 0)
    {
        fprintf(stderr, "File stat failed: %s", argv[1]);
        fclose(fp);
        exit(1);
    }

    uint8_t *buf = calloc(st.st_size, 1);
    fread(buf, st.st_size, 1, fp);
    fclose(fp);

    cfg_set_regions(buf);
    free(buf);
}
#endif
