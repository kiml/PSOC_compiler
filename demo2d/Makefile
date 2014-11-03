#DEVICE_NAME = PSOC5LP-xxx
CONFIG_HEX_PATH = config.hex
CONFIG_SRC = config.conf
OBJS = main.o startup_ARMCM3.o startup.o systeminit.o app_config.o

COMMON_INC_DIRS = hw psoc minilibc cmsis

LIBS += -lcmsis

CONFIG_BIN = $(CONFIG_SRC:%.conf=%.bin)
CONFIG_HEX = $(CONFIG_SRC:%.conf=%.hex)


all::  $(CONFIG_HEX)

clean::
	$(RM) $(CONFIG_HEX) $(CONFIG_BIN)

$(CONFIG_HEX): $(CONFIG_SRC)
	$(UTILSPATH)/bin/gen_config.py -i $< | $(UTILSPATH)/bin/freehex2other.py -f intelhex -o $@

# Testing

# This is a host (eg X86) debug compile - uses printf etc
# avoid creating an X86 .o version of app_config.o (rather than an ARM version)
app_config:  app_config.c
	gcc -D DEBUG app_config.c -o $@

$(CONFIG_BIN): $(CONFIG_SRC)
	$(UTILSPATH)/bin/gen_config.py -i $(CONFIG_SRC) | $(UTILSPATH)/bin/freehex2other.py -f binary -o $(CONFIG_BIN)

test: test_app_config $(CONFIG_BIN)
	./test_app_config $(CONFIG_BIN)

clean::
	$(RM) app_config

include ../common/conf/demo.mk
