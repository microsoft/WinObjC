#
# Copyright (c) Microsoft. All rights reserved.
#

all: CoreGraphics.Drawing.UnitTests.exe
.PHONY: all

include $(CLEAR_VARS)

CLANG := clang++
OSX_VERSION_MIN := 10.10

SRCDIR := .
SRCFILES := $(wildcard $(SRCDIR)/*.m*) $(wildcard $(SRCDIR)/*.cpp)

OUTDIR := $(SRCDIR)/../../../build/Tests/UnitTests/CoreGraphics.Drawing/OSX

OUT_OBJ_DIR := $(OUTDIR)/Objects

OUTTARGETS := $(addsuffix .o, $(addprefix $(OUT_OBJ_DIR)/, $(basename $(notdir $(SRCFILES)))))

RESOURCE_DIR := $(SRCDIR)/data
RESOURCE_FILES := $(addprefix data/, $(notdir $(wildcard $(RESOURCE_DIR)/*)))
COPY_FILES := $(addprefix $(OUTDIR)/, $(RESOURCE_FILES))

INC := $(SRCDIR)/../../frameworks/include $(SRCDIR)/../../frameworks/gtest $(SRCDIR)/../../frameworks/gtest/include 
INC += $(SRCDIR)/../../frameworks/OSXShims/include $(SRCDIR)/../../../include/xplat
INC_PARAMS := $(INC:%=-I %)

CFLAGS := -std=c++14
CFLAGS += $(INC_PARAMS)
CFLAGS += -DTARGET_OS_MAC
CFLAGS += -DWINOBJCRT_IMPEXP=
CFLAGS += -DLOGGING_IMPEXP=
CFLAGS += -mmacosx-version-min=$(OSX_VERSION_MIN)

FRAMEWORKS := CoreFoundation CoreGraphics ImageIO Foundation
LDFLAGS := -mmacosx-version-min=$(OSX_VERSION_MIN)
LDFLAGS += $(foreach o,$(FRAMEWORKS),-framework $(o))

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
	$(CLANG) -c -o $@ $(CFLAGS) -x objective-c $^

$(OUT_OBJ_DIR)/%.o : $(SRCDIR)/%.mm
	mkdir -p $(OUTDIR)/Objects
	$(CLANG) -c -o $@ $(CFLAGS) -x objective-c++ $^

$(OUT_OBJ_DIR)/%.o : $(SRCDIR)/%.cpp
	mkdir -p $(OUTDIR)/Objects
	$(CLANG) -c -o $@ $(CFLAGS) -x c++ $^

.PHONY: clean

clean:
	- $(RM) -r $(OUT_OBJ_DIR) $(OUTDIR)

$(OUTDIR)/data/% :
	mkdir -p $(OUTDIR)/data
	cp -f $(RESOURCE_DIR)/$* $@

$(OUTDIR)/% :
	cp -f $(RF_RESOURCE_DIR)/$* $@

$(OUTDIR)/CoreGraphics.Drawing.UnitTests.exe : $(SHIMS) $(OUTTARGETS) $(COPY_FILES)
	$(CLANG) -o $@ -std=c++14 $(INC_PARAMS) $(SRCDIR)/../../frameworks/gtest/src/gtest-all.cc \
	$(LDFLAGS) $(SRCDIR)/../../../build/Tests/UnitTests/CoreGraphics.Drawing/OSX/Objects/*.o
	@echo "\nDone, please run from $(shell CDPATH="" cd "$(dir $@)"; pwd)/$(notdir $@)"

.PHONY: CoreGraphics.Drawing.UnitTests.exe

CoreGraphics.Drawing.UnitTests.exe : $(OUTDIR)/CoreGraphics.Drawing.UnitTests.exe
