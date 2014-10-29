#ifndef _PSOC_REG_H
#define _PSOC_REG_H

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

typedef volatile uint8_t reg8;
typedef volatile uint16_t reg16;
typedef volatile uint32_t reg32;

#define REG_8(addr)      (*((reg8  *)(void *)(addr)))
#define REG_16(addr)     (*((reg16 *)(void *)(addr)))
#define REG_32(addr)     (*((reg32 *)(void *)(addr)))

#define REG_CLEAR_BITS_8(addr, mask) \
        ( REG_8(addr) = (REG_8(addr) & ~(mask)) )

#define REG_CLEAR_BITS_16(addr, mask) \
        ( REG_16(addr) = (REG_16(addr) & ~(mask)) )

#define REG_CLEAR_BITS_32(addr, mask) \
        ( REG_32(addr) = (REG_32(addr) & ~(mask)) )


#define REG_OR_8(addr, value)       ( REG_8(addr)  |= (uint8_t)(value))
#define REG_OR_16(addr, value)      ( REG_16(addr) |= (uint16_t)(value))
#define REG_OR_32(addr, value)      ( REG_32(addr) |= (uint32_t)(value))


#define REG_SET_8(addr, value)      ( REG_8(addr)  = (uint8_t)(value))
#define REG_SET_16(addr, value)     ( REG_16(addr) = (uint16_t)(value))
#define REG_SET_32(addr, value)     ( REG_32(addr) = (uint32_t)(value))


#define REG_SET_BITS_8(addr, mask, sbits) \
        ( REG_8(addr) = ((REG_8(addr) & ~(mask)) | ((sbits) & (mask))) )

#define REG_SET_BITS_16(addr, mask, sbits) \
        ( REG_16(addr) = ((REG_16(addr) & ~(mask)) | ((sbits) & (mask))) )

#define REG_SET_BITS_32(addr, mask, sbits) \
        ( REG_32(addr) = ((REG_32(addr) & ~(mask)) | ((sbits) & (mask))) )

        
//#define PSOC_SET_REG_APINT(addr, value)     (PSOC_SET_REG32((addr),(APINT_VECTKEY | (value))))


#endif
