#include <stdint.h>
#include <stdbool.h>

#include "psoc_regmacro.h"
#include "psoc_registers.h"

#include "psoc_support.h"


void soft_reset(void) 
{
    REG_SET_8(REG_RESET_CR2, 0x01);
}

void halt(void)
{
    __asm("BKPT 0x01");
}
