#ifndef _CMSIS_ALT_H
#define _CMSIS_ALT_H

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


// Create two functions that are compatible with CMSIS library
// but don't clash with the it if header file is not sued.
// These exist here because they are the only functions needed
// for a simple setup that are also in the CMSIS library.

#define __enable_irq    enable_irq
#define __disable_irq   disable_irq

void enable_irq(void);
void disable_irq(void);

#endif
