// clang-format off

// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//


/*	CFUniCharPriv.h
	Copyright (c) 1998 - 2015 Apple Inc. and the Swift project authors
*/

#if !defined(__COREFOUNDATION_CFUNICHARPRIV__)
#define __COREFOUNDATION_CFUNICHARPRIV__ 1

#include <CoreFoundation/CFBase.h>
#include "CFUniChar.h"

#define kCFUniCharRecursiveDecompositionFlag	(1UL << 30)
#define kCFUniCharNonBmpFlag			(1UL << 31)
#define CFUniCharConvertCountToFlag(count)	((count & 0x1F) << 24)
#define CFUniCharConvertFlagToCount(flag)	((flag >> 24) & 0x1F)

enum {
    kCFUniCharCanonicalDecompMapping = (kCFUniCharCaseFold + 1),
    kCFUniCharCanonicalPrecompMapping,
    kCFUniCharCompatibilityDecompMapping
};

CF_EXPORT const void *CFUniCharGetMappingData(uint32_t type);

#endif /* ! __COREFOUNDATION_CFUNICHARPRIV__ */

// clang-format on
