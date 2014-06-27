# Top level makefile, real work in src/Makefile

default: all

.DEFAULT:
	cd src && $(MAKE) $@

install:
	cd src && $(MAKE) $@

.PHONY: install
