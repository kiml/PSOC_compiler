FILEDIR := $(dir $(lastword $(MAKEFILE_LIST)))

#Requires following variables:
# OBJS =
PROG ?= demo

include $(FILEDIR)program.mk

DEVICE_NAME ?= PSOC5LP-xxx

COMMON_INC_DIRS ?= hw psoc minilibc

INCS += $(COMMON_INC_DIRS:%=-I$(FILEDIR)../%)
LIBS += -L $(FILEDIR)../libs  -lhw -lpsoc -lc

