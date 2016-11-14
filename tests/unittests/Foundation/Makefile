#
# Copyright (c) Microsoft. All rights reserved.
#

# Foundation.UnitTests.exe
UT_NAME = Foundation

# Built from every .m and .mm file in this directory ...
UT_FILES := $(wildcard *.m) $(wildcard *.mm)

# ... and in ReferenceFoundation.
UT_FILES += $(wildcard ReferenceFoundation/*.mm)

# "Resources" are copied directly into the output directory.
# By specifying directories, we ensure that we get out/data and out/Resources.
UT_RESOURCES := data ReferenceFoundation/Resources

include ../UT.common.mk
