#ifndef _BASELIB_H
#define _BASELIB_H

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
#include <stdbool.h>

void delay_cycles(uint32_t cycles); // defined in delay.s

void global_interrupts_enable(bool enable);
void halt(void);
void soft_reset(void) ;
void delay_ms(uint32_t milliseconds);
void delay_us(uint16_t microseconds);
void set_delay_freq(uint32_t freq);

#endif
