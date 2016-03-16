// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//


/*	CFURLComponents.h
	Copyright (c) 2015, Apple Inc. All rights reserved.
*/

#ifndef __COREFOUNDATION_CFURLCOMPONENTS__
#define __COREFOUNDATION_CFURLCOMPONENTS__

// This file is for the use of NSURLComponents only.

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFURL.h>
#include <CoreFoundation/CFString.h>
#include <CoreFoundation/CFNumber.h>

CF_IMPLICIT_BRIDGING_ENABLED
CF_EXTERN_C_BEGIN
CF_ASSUME_NONNULL_BEGIN

typedef struct __CFURLComponents *CFURLComponentsRef;

CF_EXPORT CFTypeID _CFURLComponentsGetTypeID(void);

// URLComponents are always mutable.
CF_EXPORT _Nullable CFURLComponentsRef _CFURLComponentsCreate(CFAllocatorRef alloc);

CF_EXPORT _Nullable CFURLComponentsRef _CFURLComponentsCreateWithURL(CFAllocatorRef alloc, CFURLRef url, Boolean resolveAgainstBaseURL);

CF_EXPORT _Nullable CFURLComponentsRef _CFURLComponentsCreateWithString(CFAllocatorRef alloc, CFStringRef string);

CF_EXPORT _Nullable CFURLComponentsRef _CFURLComponentsCreateCopy(CFAllocatorRef alloc, CFURLComponentsRef components);

CF_EXPORT _Nullable CFURLRef _CFURLComponentsCopyURL(CFURLComponentsRef components);

CF_EXPORT _Nullable CFURLRef _CFURLComponentsCopyURLRelativeToURL(CFURLComponentsRef components, _Nullable CFURLRef relativeToURL);

CF_EXPORT _Nullable CFStringRef _CFURLComponentsCopyString(CFURLComponentsRef components);

CF_EXPORT _Nullable CFStringRef _CFURLComponentsCopyScheme(CFURLComponentsRef components);
CF_EXPORT _Nullable CFStringRef _CFURLComponentsCopyUser(CFURLComponentsRef components);
CF_EXPORT _Nullable CFStringRef _CFURLComponentsCopyPassword(CFURLComponentsRef components);
CF_EXPORT _Nullable CFStringRef _CFURLComponentsCopyHost(CFURLComponentsRef components);
CF_EXPORT _Nullable CFNumberRef _CFURLComponentsCopyPort(CFURLComponentsRef components);
CF_EXPORT _Nullable CFStringRef _CFURLComponentsCopyPath(CFURLComponentsRef components);
CF_EXPORT _Nullable CFStringRef _CFURLComponentsCopyQuery(CFURLComponentsRef components);
CF_EXPORT _Nullable CFStringRef _CFURLComponentsCopyFragment(CFURLComponentsRef components);

// These return false if the conversion fails
CF_EXPORT Boolean _CFURLComponentsSetScheme(CFURLComponentsRef components, _Nullable CFStringRef scheme);
CF_EXPORT Boolean _CFURLComponentsSetUser(CFURLComponentsRef components, _Nullable CFStringRef user);
CF_EXPORT Boolean _CFURLComponentsSetPassword(CFURLComponentsRef components, _Nullable CFStringRef password);
CF_EXPORT Boolean _CFURLComponentsSetHost(CFURLComponentsRef components, _Nullable CFStringRef host);
CF_EXPORT Boolean _CFURLComponentsSetPort(CFURLComponentsRef components, _Nullable CFNumberRef port);
CF_EXPORT Boolean _CFURLComponentsSetPath(CFURLComponentsRef components, _Nullable CFStringRef path);
CF_EXPORT Boolean _CFURLComponentsSetQuery(CFURLComponentsRef components, _Nullable CFStringRef query);
CF_EXPORT Boolean _CFURLComponentsSetFragment(CFURLComponentsRef components, _Nullable CFStringRef fragment);

CF_EXPORT _Nullable CFStringRef _CFURLComponentsCopyPercentEncodedUser(CFURLComponentsRef components);
CF_EXPORT _Nullable CFStringRef _CFURLComponentsCopyPercentEncodedPassword(CFURLComponentsRef components);
CF_EXPORT _Nullable CFStringRef _CFURLComponentsCopyPercentEncodedHost(CFURLComponentsRef components);
CF_EXPORT _Nullable CFStringRef _CFURLComponentsCopyPercentEncodedPath(CFURLComponentsRef components);
CF_EXPORT _Nullable CFStringRef _CFURLComponentsCopyPercentEncodedQuery(CFURLComponentsRef components);
CF_EXPORT _Nullable CFStringRef _CFURLComponentsCopyPercentEncodedFragment(CFURLComponentsRef components);

// These return false if the conversion fails
CF_EXPORT Boolean _CFURLComponentsSetPercentEncodedUser(CFURLComponentsRef components, _Nullable CFStringRef user);
CF_EXPORT Boolean _CFURLComponentsSetPercentEncodedPassword(CFURLComponentsRef components, _Nullable CFStringRef password);
CF_EXPORT Boolean _CFURLComponentsSetPercentEncodedHost(CFURLComponentsRef components, _Nullable CFStringRef host);
CF_EXPORT Boolean _CFURLComponentsSetPercentEncodedPath(CFURLComponentsRef components, _Nullable CFStringRef path);
CF_EXPORT Boolean _CFURLComponentsSetPercentEncodedQuery(CFURLComponentsRef components, _Nullable CFStringRef query);
CF_EXPORT Boolean _CFURLComponentsSetPercentEncodedFragment(CFURLComponentsRef components, _Nullable CFStringRef fragment);

CF_EXPORT CFRange _CFURLComponentsGetRangeOfScheme(CFURLComponentsRef components);
CF_EXPORT CFRange _CFURLComponentsGetRangeOfUser(CFURLComponentsRef components);
CF_EXPORT CFRange _CFURLComponentsGetRangeOfPassword(CFURLComponentsRef components);
CF_EXPORT CFRange _CFURLComponentsGetRangeOfHost(CFURLComponentsRef components);
CF_EXPORT CFRange _CFURLComponentsGetRangeOfPort(CFURLComponentsRef components);
CF_EXPORT CFRange _CFURLComponentsGetRangeOfPath(CFURLComponentsRef components);
CF_EXPORT CFRange _CFURLComponentsGetRangeOfQuery(CFURLComponentsRef components);
CF_EXPORT CFRange _CFURLComponentsGetRangeOfFragment(CFURLComponentsRef components);

CF_EXPORT CFStringRef _CFStringCreateByAddingPercentEncodingWithAllowedCharacters(CFAllocatorRef alloc, CFStringRef string, CFCharacterSetRef allowedCharacters);
CF_EXPORT CFStringRef _Nullable _CFStringCreateByRemovingPercentEncoding(CFAllocatorRef alloc, CFStringRef string);

// These return singletons
CF_EXPORT CFCharacterSetRef _CFURLComponentsGetURLUserAllowedCharacterSet();
CF_EXPORT CFCharacterSetRef _CFURLComponentsGetURLPasswordAllowedCharacterSet();
CF_EXPORT CFCharacterSetRef _CFURLComponentsGetURLHostAllowedCharacterSet();
CF_EXPORT CFCharacterSetRef _CFURLComponentsGetURLPathAllowedCharacterSet();
CF_EXPORT CFCharacterSetRef _CFURLComponentsGetURLQueryAllowedCharacterSet();
CF_EXPORT CFCharacterSetRef _CFURLComponentsGetURLFragmentAllowedCharacterSet();

CF_EXPORT _Nullable CFArrayRef _CFURLComponentsCopyQueryItems(CFURLComponentsRef components);
CF_EXPORT void _CFURLComponentsSetQueryItems(CFURLComponentsRef components, CFArrayRef names, CFArrayRef values);

CF_ASSUME_NONNULL_END
CF_EXTERN_C_END
CF_IMPLICIT_BRIDGING_DISABLED

#endif // __COREFOUNDATION_CFURLCOMPONENTS__
