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

#include "lcd.h"
#include "lcd_hd44780.h"
#include "lcd_hw.h"


// Convenience functions

// Used by LCD_moveto()
// Notes:
//    Assumes each row is contiguous from start address. Not all are.
//    Last two in particular depend on variant. Eg see http://www.8052.com/tutlcd2.php
static uint8_t LCD_row_table[] = {0x00, 0x40, 0x00, 0x00}; // last two not set


void LCD_write_string(uint8_t *str)
{
    uint8_t *bp = str;

    while(*bp)
    {
        LCD_write_byte(*bp++, LCD_DATA);
    }
}


void LCD_write_stringn(uint8_t *str, int n)
{
    uint8_t *bp = str;

    while(n--)
    {
        LCD_write_byte(*bp++, LCD_DATA);
    }
}


void LCD_write_cmd(uint8_t data)
{
    LCD_write_byte(data, LCD_CONTROL);
}


void LCD_write_data(uint8_t data)
{
    LCD_write_byte(data, LCD_DATA);
}


void LCD_clear(void)
{
    LCD_write_byte(HD44780_DISPLAY_CLEAR, LCD_CONTROL);
}


void LCD_home(void)
{
    LCD_write_byte(HD44780_HOME, LCD_CONTROL);
}


void LCD_display_on(bool enable)
{
    uint8_t data = HD44780_DISPLAY;
    data |= (enable ? HD44870_D_DISP_ON : HD44870_D_DISP_OFF);

    LCD_write_byte(data, LCD_CONTROL);
}


void LCD_cursor(bool cursor_en, bool blinking_en)
{
    // Note: forces display on too (since we need to set D to something)
    uint8_t data = HD44780_DISPLAY;
    data |= HD44870_D_DISP_ON;
    data |= (cursor_en ? HD44870_D_CURS_ON : HD44870_D_CURS_OFF);
    data |= (blinking_en ? HD44870_D_BLINK_ON : HD44870_D_BLINK_OFF);

    LCD_write_byte(data, LCD_CONTROL);
}


void LCD_moveto(uint8_t x, uint8_t y)
{
    // Note: not bounds checking x,y
    if (y > 3) return; // better to do nothing

    LCD_write_byte(HD44780_DDRAM_ADDR | (LCD_row_table[y] + x), LCD_CONTROL);
}



// Core interface

void LCD_write_byte(uint8_t data, uint8_t type)
{
    // type: 0 control, 1: data
    // Assume E == 0

    LCD_write_nibble((data >> 4), type); // write hi first
    LCD_write_nibble((data & 0x0F), type); // write lo
}


void LCD_init_4bit(uint8_t lines, uint8_t font)
{
    // Note: Only supports 1,2 line displays
    // font: LCD_FONT_* (Note: Many displays can't do 5x10)

    // At reset:
    // Config: 8 bit, 1 line, 5x8 font
    // Display clear, Display off, Cursor off, Blinking off
    // Entry mode: Inc, No shift

    // At end of this func we just turn display on

    LCD_port_write_mode();

#if 1
    // This for re-init (note BF can't be checked hence fixed timings)
    delay_ms(100); // some say >= 40ms some say 100ms
    LCD_write_nibble(0x3, LCD_CONTROL); // 8 bit mode - just one nibble
    delay_ms(5);  // >= 4.1ms
    LCD_write_nibble(0x3, LCD_CONTROL); // 8 bit mode - just one nibble
    delay_us(1);  // >= 100us

    LCD_write_nibble(0x3, LCD_CONTROL); // 8 bit mode - just one nibble
    delay_us(1);  // >= 100us assumed
#endif
    LCD_write_nibble(0x2, LCD_CONTROL); // 4 bit mode - just one nibble
    //delay_us(1);  // >= 100us assumed

    uint8_t data = HD44780_FUNC;
    data |= (lines ? HD44870_F_LINES_2 : HD44870_F_LINES_1); 
    data |= (font == LCD_FONT_5x10 ? HD44870_F_FONT_5x10 : HD44870_F_FONT_5x8); 
    LCD_write_byte(data, LCD_CONTROL); // lines and font

    LCD_display_on(true);
}


void LCD_wait_ready(void)
{
    // wait until Busy Flag (BF) is 0
    // We have to change port pin directions for read

    LCD_port_read_mode();

    uint8_t data = 0;

#if 0
    delay_ms(2); // worst case (most are 40us)
#else
    // wait until Busy Flag is 0
    while ((data = LCD_read_byte()) & HD44870_BF)
        ;
#endif

    LCD_port_write_mode();
}


// HAL
// Assumes 4 bit mode, all IO lines in on one port, data bits contiguous. This can be changed manually

void LCD_write_nibble(uint8_t nibble, uint8_t type)
{
    // type: LCD_CONTROL:0, LCD_DATA:1
    // Assume E == 0

    LCD_wait_ready();

    // RW=0: write, RS = 0: control / 1: Data
    *LCD_PORT_DR_REG = (*LCD_PORT_DR_REG & ~(LCD_RW | LCD_RS) | (type ? LCD_RS : 0));

    // Addr (RS, R/nW to E) setup time 40ns min. These instructions are enough  !?
    *LCD_PORT_DR_REG = ((*LCD_PORT_DR_REG & ~LCD_DATA_MASK_4BIT) | ((nibble & 0x0F) << LCD_DATA_OFFSET)); // Set data

    *LCD_PORT_DR_REG |= LCD_E; // E=1, set data

    delay_us(1); // PWeh = 230ns

    *LCD_PORT_DR_REG &= ~LCD_E; // E = 0
}


uint8_t LCD_read_byte(void)
{
    // Assumes port I/O direction has been set to read first
    uint8_t data = 0;

    *LCD_PORT_DR_REG = (*LCD_PORT_DR_REG & ~LCD_RS) | LCD_RW; // RS=0: control, R/nW = 1: read

    // Addr (RS, R/nW to E) setup time 40ns min.  Need a short delay
    delay_us(0);

    // Min E period tcycE = 500ns

    *LCD_PORT_DR_REG |= LCD_E; // E = 1
    delay_us(1); // 230ns PWeh
    data = (*LCD_PORT_PS_REG << 4); // read upper 4 bits
    *LCD_PORT_DR_REG &= ~LCD_E; // E = 0

    delay_us(0);

    *LCD_PORT_DR_REG |= LCD_E; // E = 1
    delay_us(1); // 230ns PWeh
        data |= *LCD_PORT_PS_REG;
        *LCD_PORT_DR_REG &= ~LCD_E; // E = 0

        return data;
}


void LCD_port_read_mode(void)
{
    *LCD_PORT_DM0_REG = (*LCD_PORT_DM0_REG & ~LCD_DATA_MASK_4BIT)
                        | (LCD_HIGH_Z_DM0 & LCD_DATA_MASK_4BIT);
    *LCD_PORT_DM1_REG = (*LCD_PORT_DM1_REG & ~LCD_DATA_MASK_4BIT)
                        | (LCD_HIGH_Z_DM1 & LCD_DATA_MASK_4BIT);
    *LCD_PORT_DM2_REG = (*LCD_PORT_DM2_REG & ~LCD_DATA_MASK_4BIT)
                        | (LCD_HIGH_Z_DM2 & LCD_DATA_MASK_4BIT);
}


void LCD_port_write_mode(void)
{
    *LCD_PORT_DR_REG = 0; // E = 0 etc

    *LCD_PORT_DM0_REG = (*LCD_PORT_DM0_REG & ~LCD_DATA_MASK_4BIT)
                        | (LCD_STRONG_DM0 & LCD_DATA_MASK_4BIT);
    *LCD_PORT_DM1_REG = (*LCD_PORT_DM1_REG & ~LCD_DATA_MASK_4BIT)
                        | (LCD_STRONG_DM1 & LCD_DATA_MASK_4BIT);
    *LCD_PORT_DM2_REG = (*LCD_PORT_DM2_REG & ~LCD_DATA_MASK_4BIT)
                        | (LCD_STRONG_DM2 & LCD_DATA_MASK_4BIT);
}
