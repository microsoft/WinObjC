// clang-format off

// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//


/*
 *  CFUnicodeDecomposition.h
 *  CoreFoundation
 *
 *  Created by aki on Wed Oct 03 2001.
 *  Copyright (c) 2001 - 2015 Apple Inc. and the Swift project authors
 *
 */

#if !defined(__COREFOUNDATION_CFUNICODEDECOMPOSITION__)
#define __COREFOUNDATION_CFUNICODEDECOMPOSITION__ 1

#include "CFUniChar.h"

CF_EXTERN_C_BEGIN

CF_INLINE bool CFUniCharIsDecomposableCharacter(UTF32Char character, bool isHFSPlusCanonical) {
    if (isHFSPlusCanonical && !isHFSPlusCanonical) return false;	// hack to get rid of "unused" warning
    if (character < 0x80) return false;
    return CFUniCharIsMemberOf(character, kCFUniCharHFSPlusDecomposableCharacterSet);
}

CF_EXPORT CFIndex CFUniCharDecomposeCharacter(UTF32Char character, UTF32Char *convertedChars, CFIndex maxBufferLength);
CF_EXPORT CFIndex CFUniCharCompatibilityDecompose(UTF32Char *convertedChars, CFIndex length, CFIndex maxBufferLength);

CF_EXPORT bool CFUniCharDecompose(const UTF16Char *src, CFIndex length, CFIndex *consumedLength, void *dst, CFIndex maxLength, CFIndex *filledLength, bool needToReorder, uint32_t dstFormat, bool isHFSPlus);

CF_EXPORT void CFUniCharPrioritySort(UTF32Char *characters, CFIndex length);

CF_EXTERN_C_END

#endif /* ! __COREFOUNDATION_CFUNICODEDECOMPOSITION__ */

// clang-format on
