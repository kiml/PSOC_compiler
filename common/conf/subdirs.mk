SUBDIRS ?=

.PHONY: all install clean

all install clean::
	@for dir in $(SUBDIRS); do \
	    echo Make $@ in subdir: $$dir; \
	    $(MAKE) -C $$dir $(DEFS) $@; \
	done
