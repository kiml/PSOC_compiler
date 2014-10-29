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
#include <string.h>
//#include <stdarg.h>

#include "libc.h"


void *sbrk(int incr)
{
    extern uint8_t __HeapStart;         // Defined by the linker
    extern uint8_t __StackLimit;        // Defined by the linker

    static uint8_t *heap_end = 0;

    if (heap_end == 0)
    {
        heap_end = &__HeapStart;
    }

    if (incr < 0)
    {
        return (void *) -1;
    }

    uint8_t *prev_heap_end = heap_end;

    if (heap_end + incr > &__StackLimit)
    {
        // Heap hit the stack
        // FIXME: Should set errno to ENOMEM
        return (void *) -1;
    }

    heap_end += incr;

    return (void *) prev_heap_end;
}


void *memset(void *addr, int value, size_t len)
{
    int i;
    uint8_t *ap = (uint8_t *)addr;
    for (i=0; i<len; i++)
    {
        *(ap++) = value;
    }
    return addr;
}


void *memcpy(void *__restrict__ dest, const void *__restrict__ src, size_t len)
{
    int i;
    uint8_t *dp = (uint8_t *)dest;
    const uint8_t *sp = (uint8_t *)src;
    for (i=0; i<len; i++)
    {
        *(dp++) = *(sp++);
    }
    return dest;
}


size_t strlen(const char *str)
{
    const char *bp = str;
    while(*bp++)
        ;
    return (bp - str - 1);
}


#if 0
void exit(int status)
{
    // Not much point on baremetal
    // atexit funcs...
    // close open streams ...

    _exit(status);
}


void _exit(int status)
{
    for(;;) {}  // or reset !?
}
#endif
