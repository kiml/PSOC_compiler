#include <stdint.h>

#include "psoc_support.h"


// We need the included functionality. We don't need to follow the Cypress names
// and given these funcs are omitted from CMSISv1.3 BUT added to later CMSIS
// versions we might as well use the CMSIS function names.

void disable_irq(void)
{
    __asm("CPSID i");
}

void enable_irq(void)
{
    __asm("CPSIE i");
}
