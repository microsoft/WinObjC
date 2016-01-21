// clang-format off

// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//


/*	CFStringEncodingConverterPriv.h
	Copyright (c) 1998 - 2015 Apple Inc. and the Swift project authors
*/

#if !defined(__COREFOUNDATION_CFSTRINGENCODINGCONVERTERPRIV__)
#define __COREFOUNDATION_CFSTRINGENCODINGCONVERTERPRIV__ 1

#include <CoreFoundation/CFBase.h>
#include "CFStringEncodingConverterExt.h"

extern  const CFStringEncodingConverter __CFConverterASCII;
extern  const CFStringEncodingConverter __CFConverterISOLatin1;
extern  const CFStringEncodingConverter __CFConverterMacRoman;
extern  const CFStringEncodingConverter __CFConverterWinLatin1;
extern  const CFStringEncodingConverter __CFConverterNextStepLatin;
extern  const CFStringEncodingConverter __CFConverterUTF8;

extern  CFStringEncoding *__CFStringEncodingCreateListOfAvailablePlatformConverters(CFAllocatorRef allocator, CFIndex *numberOfConverters);
extern  const CFStringEncodingConverter *__CFStringEncodingGetExternalConverter(uint32_t encoding);
extern  CFIndex __CFStringEncodingPlatformUnicodeToBytes(uint32_t encoding, uint32_t flags, const UniChar *characters, CFIndex numChars, CFIndex *usedCharLen, uint8_t *bytes, CFIndex maxByteLen, CFIndex *usedByteLen);
extern  CFIndex __CFStringEncodingPlatformBytesToUnicode(uint32_t encoding, uint32_t flags, const uint8_t *bytes, CFIndex numBytes, CFIndex *usedByteLen, UniChar *characters, CFIndex maxCharLen, CFIndex *usedCharLen);
extern  CFIndex __CFStringEncodingPlatformCharLengthForBytes(uint32_t encoding, uint32_t flags, const uint8_t *bytes, CFIndex numBytes);
extern  CFIndex __CFStringEncodingPlatformByteLengthForCharacters(uint32_t encoding, uint32_t flags, const UniChar *characters, CFIndex numChars);

#endif /* ! __COREFOUNDATION_CFSTRINGENCODINGCONVERTERPRIV__ */

// clang-format on
