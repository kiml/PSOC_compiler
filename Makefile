FILEDIR := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
export PSOC_PROG_DIR = $(FILEDIR)/../PSOC_programmer

include common/conf/subdirs.mk

DEMOS = demo1 demo2a demo2b demo2c demo2d demo3a demo3b

SUBDIRS = common $(DEMOS)
