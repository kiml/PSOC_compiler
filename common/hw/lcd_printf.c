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

#include <stdarg.h>
#include <string.h>


// quick and dirty printf 
// note there is a stdarg-printf.c out there etc

static int print_escape(const char **escape_code);
static int int2string(int value, char *buf);


int LCD_printf(const char *fmt, ...)
{
    va_list ap;
    int count = 0;

    va_start(ap, fmt);

    while (*fmt)
    {
        switch(*fmt)
        {
            case '%':
                switch(*++fmt)
                {
                    case 's':
                        {
                            char *s = va_arg(ap, char *);
                            LCD_write_string(s);
                            count += strlen(s);
                        }
                        break;

                    case 'd':
                        {
                            char tmp[15];
                            int d = va_arg(ap, int);
                            int len = int2string(d, tmp);
                            LCD_write_stringn(tmp, len);
                            count += len;
                        }
                        break;

                    case 'c':
                       LCD_write_data((int)va_arg(ap, int)); // char -> int
                       count++;
                       break;

                    default:
                       LCD_write_data(*fmt);
                       count++;
                       break;
                }

                //fmt++;
                //print_value(++fmt);
                break;

            case '\\':
                fmt++;
                count += print_escape(&fmt);
                break;

            default: // FIXME ok or return error ?
                LCD_write_data(*fmt);
                count++;
                break;
        }

        fmt++;
    }

    va_end(ap);

    return count;
}


int print_escape(const char **fmt)
{
    switch(**fmt)
    {
        // case 'a': break;
        // case 'b': break;
        // case 'c': break;
        // case 'f': break;
        // case 'n': break;
        // case 'r': break;
        // case 't': break;
        // case 'v': break;
        case '\'':
        case '\\':
                LCD_write_data(**fmt);
                break;
        // default:
//                is_digit();
//                break;
    }

    *fmt++;
    return 1;
}


int int2string(int value, char *buf)
{
    int count = 0;
    char *bp = buf;
    if (value < 0)
    {
        *bp++ = '-';
        value = -value; // won't handle max neg
        count++;
    }

    char tmp[15];
    int i=0;
    while (value > 0)
    {
        tmp[i++] = value % 10;
        value /= 10;
    }
    count += i;

    while(i)
    {
        *bp++ = tmp[--i] + '0';
    }
    *bp = 0;

    return count;
}
