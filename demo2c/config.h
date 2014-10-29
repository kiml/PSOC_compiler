#ifndef _CONFIG_H
#define _CONFIG_H


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

#endif
