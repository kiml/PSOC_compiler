#ifndef _PSOC_SUPPORT_H
#define _PSOC_SUPPORT_H

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

#define PACKED __attribute__ ((packed))


#define Set_Pin_Drive_Mode(pin, mode) \
        REG_SET_BITS_8((pin), PRT_PC__DRIVE_MODE_MASK, (mode))
#define Set_Pin(pin)    REG_OR_8((pin), PRT_PC__DATA_OUT)
#define Clear_Pin(pin)  REG_CLEAR_BITS_8((pin), PRT_PC__DATA_OUT)

#define Read_Pin_Raw(pin)   (REG_8((pin)) & PRT_PC__PIN_STATE)
#define Read_Pin(pin)       (REG_8((pin)) & PRT_PC__PIN_STATE) >> PRT_PC__PIN_STATE_SBIT)

#endif
