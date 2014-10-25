ALL: prog

ARCH=arm-none-eabi-

CC=$(ARCH)gcc
LD=$(ARCH)ld
AS=$(ARCH)as
AR=$(ARCH)ar
RANLIB=$(ARCH)ranlib
STRIP=$(ARCH)strip

INCS = -I .
# CDEFS= -D__STARTUP_CLEAR_BSS -nostdlib -nostartupfiles
# CDEFS= -D__STARTUP_CLEAR_BSS
CDEFS=
ASDEFS=
ARCHFLAGS = -mcpu=cortex-m3 -march=armv7-m -mthumb -mthumb-interwork
CFLAGS  = $(ARCHFLAGS) $(INCS) $(CDEFS) $(DEFS)
ASFLAGS = $(ARCHFLAGS) $(INCS) $(ASDEFS) $(DEFS)
LDSCRIPT = -T gcc.ld

OBJS = main.o startup.o startup_ARMCM3.o

prog:  $(OBJS) gcc.ld
	$(LD) $(LDSCRIPT) $(OBJS) -o $@

clean:
	rm -f *.o prog
