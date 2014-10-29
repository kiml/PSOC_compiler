#include <stdint.h>
#include <stdbool.h>

#include "psoc_regmacro.h"
#include "psoc_registers.h"

#include "baselib.h"


static uint32_t Ticks_per_ms;
static uint8_t  Ticks_per_us;
static uint32_t Delay_32k_ms_ticks; // specific delay of 32k ms in units of ticks


void global_interrupts_enable(bool enable)
{
    if (enable)
        __asm("CPSIE i");
    else
        __asm("CPSID i");
}

void halt(void)
{
    __asm("BKPT 0x01");
}


void soft_reset(void) 
{
    REG_SET_8(REG_RESET_CR2, 0x01);
}


//  Note: Delay funcs assume instruction cache is enabled.
//  If not actual delays are twice expected.
//  If the bus clock frequency is a small non-integer number, the actual delay
//  can be up to twice as long as the nominal value. The actual delay cannot be
//  shorter than the nominal value.

void delay_ms(uint32_t milliseconds)
{
    // NOTE: This function is essentially copied from Cypress published source

    // Loop prevents overflow.
    // At 100MHz, milliseconds * Ticks_per_ms overflows at about 42 seconds.
     
    while (milliseconds > 32768)
    {
        delay_cycles(Delay_32k_ms_ticks);
        milliseconds -= 32768;
    }

    delay_cycles(milliseconds * Ticks_per_ms); // remainder
}


void delay_us(uint16_t microseconds)
{
    delay_cycles((uint32_t)microseconds * Ticks_per_us);
}


void set_delay_freq(uint32_t freq_hz)
{
    // freq_hz: Frequency of bus clock in Hertz.
    // NOTE: This function is essentially copied from Cypress published source

#if 0
    if (freq_hz == 0) freq_hz = DEFAULT_MASTER_CLOCK__HZ;
#endif
    Ticks_per_us = (uint8_t)((freq_hz + 999999u) / 1000000u); // nearest M
    Ticks_per_ms = (freq_hz + 999u) / 1000u; // integer round to nearest K
    Delay_32k_ms_ticks   = 32768 * Ticks_per_ms;
}
