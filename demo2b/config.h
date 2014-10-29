#ifndef _CONFIG_H
#define _CONFIG_H

#include "psoc_registers.h"


// CLOCK SETUP
// ===========
#define CONFIG_SYSTEM_CLOCK_MHZ 63
#define CONFIG_SYSTEM_CLOCK_HZ (CONFIG_SYSTEM_CLOCK_MHZ * 1000000)

// Next two must match
#define CONFIG_IMO_FREQ_MHZ     3
#define CONFIG_IMO_FREQ_ENUM    FASTCLK_IMO__F_RANGE__3MHz

#define CONFIG_FASTCLK_PLL_P   CONFIG_SYSTEM_CLOCK_MHZ
#define CONFIG_FASTCLK_PLL_Q   0x02


// OTHER SETUP
// ===========
// Note: delay_cycles() assumes instruction cache enabled. Refer source.
#define CONFIG_INSTRUCTION_CACHE_ENABLED 1

#define CONFIG_NVIC_PRIORITY_GROUP  NVIC_APPLN_INTR__PRIGROUP__3_5


// CONFIG DATA SETUP
// =================

#define CONFIG_ADDR_TABLE_ADDR 0x48000000
#define CONFIG_ADDR_TABLE_NELTS 1

#define CONFIG_DATA_TABLE_ADDR 0x48000004

// Init by copy 0 (data from config.hex)
#define CONFIG_INITCOPY_0_SRC_ADDR    0x48000008
#define CONFIG_INITCOPY_0_DEST_ADDR   (REG_PRT0_DR + 0)
#define CONFIG_INITCOPY_0_LEN         10

// Init by copy 1 (data from config.hex)
#define CONFIG_INITCOPY_1_SRC_ADDR    0x48000014
#define CONFIG_INITCOPY_1_DEST_ADDR   (REG_PRT2_DR + 2)
#define CONFIG_INITCOPY_1_LEN         8

#if 0
// Init by copy 2
#define CONFIG_INITCOPY_2_SRC_ADDR    REG_PM_ACT_CFG0
#define CONFIG_INITCOPY_2_DEST_ADDR   REG_PM_STBY_CFG0
#define CONFIG_INITCOPY_2_LEN         PM_CFG_NREGS
#endif

#endif
