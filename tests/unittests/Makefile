#
# Copyright (c) Microsoft. All rights reserved.
#

include $(CLEAR_VARS)

TESTS_TO_BUILD := Foundation

# Makefile Entrypoint: for running `make` without an argument.
.PHONY: all
all: $(foreach t,$(TESTS_TO_BUILD),$(t).UnitTests.exe)

.PHONY: $(TESTS_TO_BUILD)

Foundation.UnitTests.exe :
	make -C Foundation Foundation.UnitTests.exe

.PHONY: clean

clean:
	make -C Foundation clean