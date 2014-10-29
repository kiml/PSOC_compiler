FILEDIR := $(dir $(lastword $(MAKEFILE_LIST)))

include $(FILEDIR)armgcc.mk
include $(FILEDIR)utils.mk


# Required vars:
# LIBNAME = lblah.a
# INCS = -I . -I  ...
# OBJS = ...
# INSTALL_DIR = ...


all: $(LIBNAME) install

$(LIBNAME):  $(OBJS)
	$(RM) $@
	$(AR) -rs $@ $(OBJS) 

install:
	$(RM) $(INSTALL_DIR)/$(LIBNAME)
	$(CP) $(LIBNAME) $(INSTALL_DIR)

clean::
	$(RM) *.o $(LIBNAME)
