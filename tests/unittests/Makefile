#
# Copyright (c) Microsoft. All rights reserved.
#

include $(CLEAR_VARS)

TESTS_TO_BUILD := Foundation
export TESTS_TO_BUILD

# Makefile Entrypoint: for running `make` without an argument.
.PHONY: all
all: $(foreach t,$(TESTS_TO_BUILD),$(t).UnitTests.exe)

.PHONY: $(TESTS_TO_BUILD)

%.UnitTests.exe: %
	make -C $^ all

.PHONY: clean

clean:
	for d in $$TESTS_TO_BUILD; do \
		make -C "$$d" clean; \
	done
