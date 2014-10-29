#ifndef _LCD_HD44780_H
#define _LCD_HD44780_H

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

#define HD44780_DISPLAY_CLEAR      0x01
#define HD44780_HOME               0x02
#define HD44780_ENTRY_MODE         0x04
// 0x02 = I/D, 0x01 = S
#define HD44870_EM_CURS_DEC        (0 << 1)
#define HD44870_EM_CURS_INC        (1 << 1)
#define HD44870_EM_DISPLAY_FIXED   (0 << 0)
#define HD44870_EM_DISPLAY_SHIFT   (1 << 0)

#define HD44780_DISPLAY            0x08
// 0x04 display, 0x02 cursor, 0x01 blink
#define HD44870_D_DISP_OFF        (0 << 2)
#define HD44870_D_DISP_ON         (1 << 2)
#define HD44870_D_CURS_OFF        (0 << 1)
#define HD44870_D_CURS_ON         (1 << 1)
#define HD44870_D_BLINK_OFF       (0 << 0)
#define HD44870_D_BLINK_ON        (1 << 0)

#define HD44780_CURSOR             0x10
// 0x08 S/C, 0x04 R/L
#define HD44870_C_SHIFT_CURS      (0 << 3)
#define HD44870_C_SHIFT_DISP      (1 << 3)
#define HD44870_C_SHIFT_LEFT      (0 << 2)
#define HD44870_C_SHIFT_RIGHT     (1 << 2)

#define HD44780_FUNC               0x20
// 0x10 8/4bit(DL), 0x08 N, 0x04 F
#define HD44870_F_LINES_1         (0 << 3)
#define HD44870_F_LINES_2         (1 << 3)
#define HD44870_F_FONT_5x8        (0 << 2)
#define HD44870_F_FONT_5x10       (1 << 2)

#define HD44780_CGRAM_ADDR         0x40
#define HD44780_DDRAM_ADDR         0x80

#define HD44870_BF                 0x80
#define HD44870_AC_MASK            0x7F

#endif
