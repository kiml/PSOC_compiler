The CMSIS library code (1.3 and possibly 2.0) has a bug in it under at least the GCC compiler
When compiling under GCC we get the assembler errors:

Error: registers may not be the same -- `strexb r3,r2,[r3]'
Error: registers may not be the same -- `strexh r3,r2,[r3]'

It is illegal on this architecture to have the three strex registers identical.
This has been fixed by using "=&r" rather than "=r".
The & ensures the register is not the same as that of the source operands.

