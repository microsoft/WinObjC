#
# Copyright (c) Microsoft. All rights reserved.
#

include $(CLEAR_VARS)

CLANG := clang++

SRCDIR := Foundation
SRCFILES := $(wildcard $(SRCDIR)/*.m*)
RF_SRCFILES := $(wildcard $(SRCDIR)/ReferenceFoundation/*.mm)

OUTDIR := ../../build/Tests/UnitTests/Foundation/OSX
OUTTARGETS := $(addsuffix .o, $(addprefix $(OUTDIR)/, $(basename $(notdir $(SRCFILES)))))
OUTTARGETS += $(addsuffix .o, $(addprefix $(OUTDIR)/ReferenceFoundation_, $(basename $(notdir $(RF_SRCFILES)))))

INC := ./Foundation/ReferenceFoundation ../frameworks/include ../frameworks/gtest ../frameworks/gtest/include 
INC += ../frameworks/OSXShims/include Foundation/ReferenceFoundation ../../include/xplat
INC_PARAMS := $(INC:%=-I %)

CFLAGS += -std=c++14
CFLAGS += -x objective-c++
CFLAGS += $(INC_PARAMS)
CFLAGS += -DTARGET_OS_MAC
CFLAGS += -DWINOBJCRT_IMPEXP -DWINOBJCRT_EXPORT=

LDFLAGS := -framework Foundation

Shims : $(OUTDIR)/windows.o $(OUTDIR)/IwMalloc.o $(OUTDIR)/LoggingNative.o

$(OUTDIR)/IwMalloc.o : ../../Frameworks/WinObjCRT/MemoryManagement.cpp
	mkdir -p $(OUTDIR)
	$(CLANG) -c -o $@ $(CFLAGS) $<

$(OUTDIR)/windows.o : ../frameworks/OSXShims/src/windows.cpp
	mkdir -p $(OUTDIR)
	$(CLANG) -c -o $@ $(CFLAGS) $<

$(OUTDIR)/LoggingNative.o : ../frameworks/OSXShims/src/LoggingNative.mm
	mkdir -p $(OUTDIR)
	$(CLANG) -c -o $@ $(CFLAGS) $<

$(OUTDIR)/%.o : $(SRCDIR)/%.m
	mkdir -p $(OUTDIR)
	$(CLANG) -c -o $@ $(CFLAGS) $^

$(OUTDIR)/%.o : $(SRCDIR)/%.mm
	mkdir -p $(OUTDIR)
	$(CLANG) -c -o $@ $(CFLAGS) $^

$(OUTDIR)/ReferenceFoundation_TestUtils.o : $(SRCDIR)/ReferenceFoundation/TestUtils.mm
	mkdir -p $(OUTDIR)
	$(CLANG) -c -o $@ $(CFLAGS) $<

$(OUTDIR)/ReferenceFoundation_%.o : $(OUTDIR)/ReferenceFoundation_TestUtils.o $(SRCDIR)/ReferenceFoundation/%.mm
	mkdir -p $(OUTDIR)
	$(CLANG) -c -o $@ $(CFLAGS) $(word 2,$^) 

.PHONY: clean Shims

clean:
	$(RM) $(OUTDIR)/*.o
	$(RM) Foundation.UnitTests.exe

Foundation.UnitTests.exe : Shims $(OUTTARGETS)
	$(CLANG) -o $@ -std=c++14 $(INC_PARAMS) EntryPoint.cpp ../frameworks/gtest/src/gtest-all.cc $(LDFLAGS) ../../build/Tests/UnitTests/Foundation/OSX/*.o