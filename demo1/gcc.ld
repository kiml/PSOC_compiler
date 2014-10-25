/* This linker script does NOT support
 *   - C++
 *   - exception handling
 *   - debugging
 */

MEMORY
{
  FLASH (rx) : ORIGIN = 0x0, LENGTH = 0x40000 /* 256K */
  RAM (rwx)  : ORIGIN = 0x20000000 - (0x10000 / 2), LENGTH = 0x10000 /* 64K */
}

__StackSize = 0x1000;
__HeapSize  = 0x1000;


ENTRY(Reset_Handler)

SECTIONS
{
	.text :
	{
            . = ALIGN(4);
            *(.isr_vector)

            *(.text)

            /*
            *(.init)
            *(.fini)
            */

            *(.rodata)

            . = ALIGN(4);
            __etext = .;

	} > FLASH

		
	.data : AT (__etext)
	{
            . = ALIGN(4);
            __data_start__ = .;
            *(.data)
            . = ALIGN(4);
            __data_end__ = .;

	} > RAM  /* AT>FLASH */

	.bss :
	{
            . = ALIGN(4);
            __bss_start__ = .;
            *(.bss)
            *(COMMON)
            . = ALIGN(4);
            __bss_end__ = .;
	} > RAM
	
	/* Set stack at top end of RAM */

	__StackTop = ORIGIN(RAM) + LENGTH(RAM);
	__StackLimit = __StackTop - __StackSize;
/*	PROVIDE(__stack = __StackTop); */
	
        __HeapStart = __bss_end__; /* use highest/last RAM section */
	__HeapLimit = __HeapStart + __HeapSize;

	/* Check if data + heap + stack exceeds RAM limit */
	ASSERT(__HeapLimit < __StackLimit, "Heap overlaps Stack")
}
