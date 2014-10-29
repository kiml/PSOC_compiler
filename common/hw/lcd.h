#ifndef _LCD_H
#define _LCD_H

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

// convenience function
void LCD_write_string(uint8_t *str);
void LCD_write_stringn(uint8_t *str, int n);
void LCD_write_cmd(uint8_t data);
void LCD_write_data(uint8_t data);
void LCD_clear(void);
void LCD_home(void);
void LCD_display_on(bool enable);
void LCD_cursor(bool cursor_en, bool blinking_en);
void LCD_moveto(uint8_t x, uint8_t y);
int LCD_printf(const char *fmt, ...);

// Core interface

//#define LCD_IO_4_BIT     0
//#define LCD_IO_8_BIT     1
#define LCD_FONT_5x8     0
#define LCD_FONT_5x10    1
void LCD_init_4bit(uint8_t lines, uint8_t font);

#define LCD_CONTROL     0
#define LCD_DATA        1
void LCD_write_byte(uint8_t data, uint8_t type);
void LCD_write_nibble(uint8_t nibble, uint8_t type);

void LCD_port_read_mode(void);
void LCD_port_write_mode(void);
void LCD_wait_ready(void);
uint8_t LCD_read_byte(void);

#endif
