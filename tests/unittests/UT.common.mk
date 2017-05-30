#
# Copyright (c) Microsoft. All rights reserved.
#

.PHONY: all

ifeq ($(strip $(UT_NAME)),)
all::
	@echo "error: no UT_NAME specified." >& 2; exit 1
endif

ifeq ($(strip $(UT_FILES)),)
all::
	@echo "error: no source files specified in UT_FILES." >& 2; exit 1
endif

_UT_PROJECT_DIR := $(shell pwd)
_UT_BASE_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
_UT_OUT_DIR := $(_UT_BASE_DIR)/../../build/Tests/UnitTests/$(UT_NAME)/OSX
_UT_OBJ_DIR := $(_UT_OUT_DIR)/Objects
_UT_FILENAME := $(UT_NAME).UnitTests.exe

all:: $(_UT_OUT_DIR)/$(_UT_FILENAME)

CLANG := clang++
OSX_VERSION_MIN := 10.10

_UT_OBJECTS := $(addsuffix .o,$(addprefix $(_UT_OBJ_DIR)/,$(subst $(_UT_PROJECT_DIR)/,,$(UT_FILES))))

# Common shims for all tests.
_UT_OBJECTS += $(_UT_OBJ_DIR)/windows.o
ifeq ($(strip $(filter EntryPoint.cpp,$(UT_FILES))),)
_UT_OBJECTS += $(_UT_OBJ_DIR)/EntryPoint.o
endif

ifneq ($(strip $(filter %.m %.mm,$(UT_FILES))),)
_UT_OBJECTS += $(patsubst %.mm,$(_UT_OBJ_DIR)/helpers-%.mm.o,$(notdir $(wildcard $(_UT_BASE_DIR)/../helpers/*.mm)))
endif

_INC := $(_UT_BASE_DIR)/../frameworks/include $(_UT_BASE_DIR)/../frameworks/gtest $(_UT_BASE_DIR)/../frameworks/gtest/include
_INC += $(_UT_BASE_DIR)/../frameworks/OSXShims/include $(_UT_BASE_DIR)/../../include/xplat $(_UT_BASE_DIR)/../../tools/include/xplat

_ALL_CXXFLAGS := -std=c++14
_ALL_CXXFLAGS += $(UT_CXXFLAGS) $(UT_CCFLAGS)
_ALL_CXXFLAGS += $(CXXFLAGS) $(CCFLAGS)

_ALL_CFLAGS := $(foreach i,$(_INC),-I $(i))
_ALL_CFLAGS += -DTARGET_OS_MAC
_ALL_CFLAGS += -DWINOBJCRT_IMPEXP=
_ALL_CFLAGS += -DLOGGING_IMPEXP=
_ALL_CFLAGS += -mmacosx-version-min=$(OSX_VERSION_MIN)
_ALL_CFLAGS += $(UT_CFLAGS)

# CFLAGS from the commandline (to make certain build scenarios easier.)
_ALL_CFLAGS += $(CFLAGS)

_UT_FRAMEWORKS := CoreFoundation Foundation $(UT_FRAMEWORKS)
_ALL_LDFLAGS := -mmacosx-version-min=$(OSX_VERSION_MIN)
_ALL_LDFLAGS += $(foreach o,$(_UT_FRAMEWORKS),-framework $(o))
_ALL_LDFLAGS += $(UT_LDFLAGS)

# LDFLAGS from the commandline (to make certain build scenarios easier.)
_ALL_LDFLAGS += $(LDFLAGS)

ECHO_CC = @(echo "[ CC ] $^";
ECHO_LD = @(echo "[ LD ] $@";
ECHO_RES = @(echo "[ RES ] $^";
ECHO_RESDIR = @(echo "[ DIR ] $^";
ECHO_END = )

$(_UT_OBJ_DIR)/windows.o : $(_UT_BASE_DIR)/../frameworks/OSXShims/src/windows.cpp
	@mkdir -p $(dir $@)
	$(ECHO_CC)$(CLANG) -c -o $@ $(_ALL_CFLAGS) $(_ALL_CXXFLAGS) $<$(ECHO_END)

$(_UT_OBJ_DIR)/EntryPoint.o : $(_UT_BASE_DIR)/EntryPoint.cpp
	@mkdir -p $(dir $@)
	$(ECHO_CC)$(CLANG) -c -o $@ $(_ALL_CFLAGS) $(_ALL_CXXFLAGS) -x c++ $<$(ECHO_END)

$(_UT_OBJ_DIR)/%.m.o : %.m
	@mkdir -p $(dir $@)
	$(ECHO_CC)$(CLANG) -c -o $@ $(_ALL_CFLAGS) $(_ALL_CXXFLAGS) -x objective-c++ $^$(ECHO_END)

$(_UT_OBJ_DIR)/helpers-%.mm.o : $(_UT_BASE_DIR)/../helpers/%.mm
	@mkdir -p $(dir $@)
	$(ECHO_CC)$(CLANG) -c -o $@ $(_ALL_CFLAGS) $(_ALL_CXXFLAGS) -x objective-c++ $^$(ECHO_END)

$(_UT_OBJ_DIR)/%.mm.o : %.mm
	@mkdir -p $(dir $@)
	$(ECHO_CC)$(CLANG) -c -o $@ $(_ALL_CFLAGS) $(_ALL_CXXFLAGS) -x objective-c++ $^$(ECHO_END)

$(_UT_OBJ_DIR)/%.cpp.o : %.cpp
	@mkdir -p $(dir $@)
	$(ECHO_CC)$(CLANG) -c -o $@ $(_ALL_CFLAGS) $(_ALL_CXXFLAGS) -x c++ $^$(ECHO_END)

.PHONY: clean
clean:
	-$(RM) -r $(_UT_OUT_DIR)/*
	-$(RM) -r $(_UT_OUT_DIR)/.*.stamp

_UT_RESOURCES := $(strip $(subst $(_UT_PROJECT_DIR)/,,$(UT_RESOURCES)))
_UT_RESOURCE_DIRS := $(strip $(subst $(_UT_PROJECT_DIR)/,,$(UT_RESOURCE_DIRS)))
export _UT_RESOURCES _UT_RESOURCE_DIRS

$(_UT_OUT_DIR)/.resfiles.stamp: $(_UT_RESOURCES)
ifneq ($(_UT_RESOURCES),)
	$(ECHO_RES)cp -r $$_UT_RESOURCES "$(_UT_OUT_DIR)"$(ECHO_END)
endif
	@touch "$@"

$(_UT_OUT_DIR)/.resdirs.stamp: $(_UT_RESOURCE_DIRS)
ifneq ($(_UT_RESOURCE_DIRS),)
	$(ECHO_RESDIR)for d in $$_UT_RESOURCE_DIRS; do \
		rsync -r "$$d/" "$(_UT_OUT_DIR)/"; \
	done$(ECHO_END)
endif
	@touch "$@"

$(_UT_OUT_DIR)/$(_UT_FILENAME) : $(SHIMS) $(_UT_OBJECTS) $(_UT_OUT_DIR)/.resfiles.stamp $(_UT_OUT_DIR)/.resdirs.stamp
	$(ECHO_LD)$(CLANG) -o $@ $(_ALL_CFLAGS) $(_ALL_CXXFLAGS) $(_UT_BASE_DIR)/../frameworks/gtest/src/gtest-all.cc \
	$(_ALL_LDFLAGS) $(_UT_OBJECTS)$(ECHO_END)
	@echo "\nDone, please run from $(shell CDPATH="" cd "$(dir $@)"; pwd)/$(notdir $@)"
