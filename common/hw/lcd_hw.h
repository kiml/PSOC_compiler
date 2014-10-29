#ifndef _LCD_HW_H
#define _LCD_HW_H

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

#include "psoc_registers.h"

#define LCD_PORT_DR_REG         ((uint8_t *) REG_PRT2_DR)
#define LCD_PORT_DM0_REG        ((uint8_t *) REG_PRT2_DM0)
#define LCD_PORT_DM1_REG        ((uint8_t *) REG_PRT2_DM1)
#define LCD_PORT_DM2_REG        ((uint8_t *) REG_PRT2_DM2)
#define LCD_PORT_PS_REG         ((uint8_t *) REG_PRT2_PS)

#define LCD_HIGH_Z_DM0  0xFF
#define LCD_HIGH_Z_DM1  0x00
#define LCD_HIGH_Z_DM2  0x00

#define LCD_STRONG_DM0  0x00
#define LCD_STRONG_DM1  0xFF
#define LCD_STRONG_DM2  0xFF

#define LCD_DATA_OFFSET    0
#define LCD_DATA_MASK_4BIT (0x0F << LCD_DATA_OFFSET)
#define LCD_E              0x10
#define LCD_RS             0x20
#define LCD_RW             0x40

#endif
