FILEDIR := $(dir $(lastword $(MAKEFILE_LIST)))

include $(FILEDIR)armgcc.mk 
include $(FILEDIR)programmer.mk

.PHONY: all map dump dis burn clean

OUTPUTS = $(PROG).hex $(PROG)_tmp.hex $(PROG).elf $(PROG).bin

all:: $(PROG).elf $(PROG).hex $(PROG).bin

$(PROG).elf:  $(OBJS)
	$(LD) -T $(LDSCRIPT) $(OBJS) $(LIBS) -o $@

map: $(OBJS)
	$(LD) -M -T $(LDSCRIPT) $(OBJS)

dump: $(PROG).elf
	$(OBJDUMP) -x $<
	#$(OBJDUMP) -sph $<

dis: $(PROG).elf
	$(OBJDUMP) -d $<

burn: $(PROG).hex
	$(BURNCMD) $<

clean::
	rm -f *.o $(OUTPUTS)
