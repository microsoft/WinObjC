#
# Copyright (c) Microsoft. All rights reserved.
#

include $(CLEAR_VARS)

CLANG := clang++
OSX_VERSION_MIN := 10.10

SRCDIR := .
SRCFILES := $(wildcard $(SRCDIR)/*.m*)
RF_SRCFILES := $(wildcard $(SRCDIR)/ReferenceFoundation/*.mm)

OUTDIR := $(SRCDIR)/../../../build/Tests/UnitTests/Foundation/OSX

OUT_OBJ_DIR := $(OUTDIR)/Objects

OUTTARGETS := $(addsuffix .o, $(addprefix $(OUT_OBJ_DIR)/, $(basename $(notdir $(SRCFILES)))))
OUTTARGETS += $(addsuffix .o, $(addprefix $(OUT_OBJ_DIR)/ReferenceFoundation_, $(basename $(notdir $(RF_SRCFILES)))))

RESOURCE_DIR := $(SRCDIR)/data
RF_RESOURCE_DIR := $(SRCDIR)/ReferenceFoundation/Resources
RESOURCE_FILES := $(addprefix data/, $(notdir $(wildcard $(RESOURCE_DIR)/*))) $(notdir $(wildcard $(RF_RESOURCE_DIR)/*))
COPY_FILES := $(addprefix $(OUTDIR)/, $(RESOURCE_FILES))

INC := $(SRCDIR)/../../frameworks/include $(SRCDIR)/../../frameworks/gtest $(SRCDIR)/../../frameworks/gtest/include 
INC += $(SRCDIR)/../../frameworks/OSXShims/include $(SRCDIR)/ReferenceFoundation $(SRCDIR)/../../../include/xplat
INC_PARAMS := $(INC:%=-I %)

CFLAGS := -std=c++14
CFLAGS += -x objective-c++
CFLAGS += $(INC_PARAMS)
CFLAGS += -DTARGET_OS_MAC
CFLAGS += -DWINOBJCRT_IMPEXP=
CFLAGS += -DLOGGING_IMPEXP=
CFLAGS += -mmacosx-version-min=$(OSX_VERSION_MIN)

LDFLAGS := -framework Foundation -mmacosx-version-min=$(OSX_VERSION_MIN)

SHIMS := $(OUT_OBJ_DIR)/windows.o $(OUT_OBJ_DIR)/IwMalloc.o $(OUT_OBJ_DIR)/LoggingNative.o

$(OUT_OBJ_DIR)/IwMalloc.o : $(SRCDIR)/../../../Frameworks/WinObjCRT/MemoryManagement.cpp
	mkdir -p $(OUTDIR)/Objects
	$(CLANG) -c -o $@ $(CFLAGS) $<

$(OUT_OBJ_DIR)/windows.o : $(SRCDIR)/../../frameworks/OSXShims/src/windows.cpp
	mkdir -p $(OUTDIR)/Objects
	$(CLANG) -c -o $@ $(CFLAGS) $<

$(OUT_OBJ_DIR)/LoggingNative.o : $(SRCDIR)/../../frameworks/OSXShims/src/LoggingNative.mm
	mkdir -p $(OUTDIR)/Objects
	$(CLANG) -c -o $@ $(CFLAGS) $<

$(OUT_OBJ_DIR)/%.o : $(SRCDIR)/%.m
	mkdir -p $(OUTDIR)/Objects
	$(CLANG) -c -o $@ $(CFLAGS) $^

$(OUT_OBJ_DIR)/%.o : $(SRCDIR)/%.mm
	mkdir -p $(OUTDIR)/Objects
	$(CLANG) -c -o $@ $(CFLAGS) $^

$(OUT_OBJ_DIR)/ReferenceFoundation_TestUtils.o : $(SRCDIR)/ReferenceFoundation/TestUtils.mm
	mkdir -p $(OUTDIR)/Objects
	$(CLANG) -c -o $@ $(CFLAGS) $<

$(OUT_OBJ_DIR)/ReferenceFoundation_%.o : $(OUT_OBJ_DIR)/ReferenceFoundation_TestUtils.o $(SRCDIR)/ReferenceFoundation/%.mm
	mkdir -p $(OUTDIR)
	$(CLANG) -c -o $@ $(CFLAGS) $(word 2,$^) 

.PHONY: clean

clean:
	- $(RM) -r $(OUT_OBJ_DIR) $(OUTDIR)

$(OUTDIR)/data/% :
	mkdir -p $(OUTDIR)/data
	cp -f $(RESOURCE_DIR)/$* $@

$(OUTDIR)/% :
	cp -f $(RF_RESOURCE_DIR)/$* $@

$(OUTDIR)/Foundation.UnitTests.exe : $(SHIMS) $(OUTTARGETS) $(COPY_FILES)
	$(CLANG) -o $@ -std=c++14 $(INC_PARAMS) $(SRCDIR)/../EntryPoint.cpp $(SRCDIR)/../../frameworks/gtest/src/gtest-all.cc \
	$(LDFLAGS) $(SRCDIR)/../../../build/Tests/UnitTests/Foundation/OSX/Objects/*.o
	@echo "\nDone, please run from $(shell CDPATH="" cd "$(dir $@)"; pwd)/$(notdir $@)"

.PHONY: Foundation.UnitTests.exe

Foundation.UnitTests.exe : $(OUTDIR)/Foundation.UnitTests.exe
