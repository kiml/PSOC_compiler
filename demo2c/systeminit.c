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

#include "cmsis_alt.h"
#include "psoc5.h"
#include "config.h"

extern void app_config(void);

static void clock_setup(void)
{
    // Enable/initialise device clocks

    // Configure Internal Low freq Oscillator (ILO)
    // Enable 1KHz clock and route to central timewheel (sleep timer) and watchdog timer.
    // PSoC TRM Section 16.3
    REG_SET_8(REG_SLOWCLK_ILO_CR0, SLOWCLK_ILO__EN_1K);
    REG_SET_8(REG_CLKDIST_CR, CLKDIST__ILO_OUT__1K);

    // Configure Internal Main Oscillator (IMO)
    // No fast start, no high precision USB clock. (TRM 1.3.31)
    REG_SET_8(REG_FASTCLK_IMO_CR, CONFIG_IMO_FREQ_ENUM);
    // REG_SET_8(CYREG_IMO_TR1, REG_8(REG_FLSHID_CUST_TABLES_IMO_3MHZ));

    // Configure PLL
    // freq_out = freq_in * (P/(Q+1)).
    // Eg:   => freq_out ~ 63/3 * freq_in.  So freq_out ~ 21 * 3MHz ~ 63MHz
    //REG_SET_16(REG_FASTCLK_PLL_P, 0x023F); // set P and Q counters (Q=0x02, P=0x3F)
    REG_SET_8(REG_FASTCLK_PLL_P, CONFIG_FASTCLK_PLL_P);
    REG_SET_8(REG_FASTCLK_PLL_Q, CONFIG_FASTCLK_PLL_Q);
    REG_SET_16(REG_FASTCLK_PLL_CFG0, 0x1051); // Set params and Enable PLL

    // Wait up to 250us for the PLL to lock
    reg8 pllLock = 0;
    reg32  timeout;
//    reg32* timeout_p = &timeout; // Is this to avoid a weird optimisation !?
//    for (timeout = 250 / 10; *timeout_p && (pllLock != 0x03u); timeout--)
    for (timeout = 250 / 10; timeout && (pllLock != 0x03u); timeout--)
    { 
        pllLock = 0x03u & ((pllLock << 1) | ((REG_8(REG_FASTCLK_PLL_SR) & FASTCLK_PLL_SR__LOCKDET) >> 0));
        delay_cycles(10 * CONFIG_SYSTEM_CLOCK_MHZ); /* Delay 10us based on 63MHz clock */
    }

    // Configure Master, Bus Clocks
    // IMO (3MHz) -> PLL (*21 -> 63MHz) -> Master(System) Clock (/1) -> Bus Clock (/1)
    REG_SET_16(REG_CLKDIST_MSTR0, 0x0100); // sets MSTR1 source = 01 PLL, Divider = 1
    //REG_SET_8(REG_CLKDIST_MSTR0, 0x07); // sets Divider = 8 (but resets to 1 below)
    //REG_SET_8(REG_CLKDIST_BCFG0, 0x00); // LSB Divider value
    //REG_SET_8(REG_CLKDIST_BCFG1, 0x00); // MSB Divider value
    REG_SET_8(REG_CLKDIST_BCFG2, (CLKDIST__SSS|CLKDIST__SYNC)); // sync bus to master
    //REG_SET_8(REG_CLKDIST_MSTR0, 0x00); // divider value -1 : 0 == source / 1
    REG_SET_8(REG_CLKDIST_LD, CLKDIST_LD__SYNC_EN); // restart master clock dividers in phase !?

    // Specify clock ticks for delay library routines (not the hardware)
    set_delay_freq(CONFIG_SYSTEM_CLOCK_HZ);
}


void SystemInit(void)
{
    // NVIC Setup
    REG_SET_32(REG_NVIC_APPLN_INTR, (NVIC_APPLN_INTR__VECTKEY__KEY | CONFIG_NVIC_PRIORITY_GROUP));
    REG_OR_32(REG_NVIC_CFG_CONTROL, NVIC_CFG_CONTROL__STKALIGN);

    __disable_irq();

    // Enable cache and set flash_cycles assuming max clock (50-67MHz)
    REG_SET_8(REG_CACHE_CC_CTL, ((CONFIG_INSTRUCTION_CACHE_ENABLED) ? 0x01 : 0x00));

    clock_setup();

    app_config();
}
