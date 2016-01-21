// clang-format off

// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//


/*	CFError_Private.h
        Copyright (c) 2006 - 2015 Apple Inc. and the Swift project authors
	
	This is Apple-internal SPI for CFError.
*/

#if !defined(__COREFOUNDATION_CFERRORPRIVATE__)
#define __COREFOUNDATION_CFERRORPRIVATE__ 1

#include <CoreFoundation/CFError.h>

CF_EXTERN_C_BEGIN


/* A key for "true" debugging descriptions which should never be shown to the user. It's only used when the CFError is shown to the console, and nothing else is available. For instance the rather terse and techie OSStatus descriptions are in this boat.
*/
CF_EXPORT const CFStringRef kCFErrorDebugDescriptionKey CF_AVAILABLE(10_5, 2_0);


CF_EXTERN_C_END

#endif /* ! __COREFOUNDATION_CFERRORPRIVATE__ */

// clang-format on
