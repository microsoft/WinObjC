// clang-format off

// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//


/*	CFUtilities.h
	Copyright (c) 2005 - 2015 Apple Inc. and the Swift project authors
*/

#if !defined(__COREFOUNDATION_CFUTILITIES__)
#define __COREFOUNDATION_CFUTILITIES__ 1

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFString.h>
#include <CoreFoundation/CFURL.h>

CF_IMPLICIT_BRIDGING_ENABLED
CF_EXTERN_C_BEGIN

CF_EXPORT
CFURLRef CFCopyHomeDirectoryURL(void) CF_AVAILABLE_IOS(5_0);

CF_EXTERN_C_END
CF_IMPLICIT_BRIDGING_DISABLED

#endif /* ! __COREFOUNDATION_CFUTILITIES__ */

// clang-format on
