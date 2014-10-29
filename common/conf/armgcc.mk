FILEDIR := $(dir $(lastword $(MAKEFILE_LIST)))

ARCH=arm-none-eabi-

CC=$(ARCH)gcc
LD=$(ARCH)ld
AS=$(ARCH)as
AR=$(ARCH)ar
CPP=$(ARCH)cpp
RANLIB=$(ARCH)ranlib
STRIP=$(ARCH)strip
OBJCOPY=$(ARCH)objcopy
OBJDUMP=$(ARCH)objdump
NM=$(ARCH)nm

# CDEFS= -D__STARTUP_CLEAR_BSS -nostdlib -nostartupfiles
# CDEFS= -D__STARTUP_CLEAR_BSS
CDEFS=
ASDEFS=
ARCHFLAGS = -mcpu=cortex-m3 -march=armv7-m -mthumb -mthumb-interwork
CFLAGS  = $(ARCHFLAGS) $(INCS) $(CDEFS) $(DEFS)
ASFLAGS = $(ARCHFLAGS) $(INCS) $(ASDEFS) $(DEFS)
LDSCRIPT = $(FILEDIR)gcc.ld
