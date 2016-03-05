/* Copyright (c) 2008-2009 Christopher J. W. Lloyd

Copyright (c) 2015 Microsoft Corporation. All rights reserved.

Permission is hereby granted,free of charge,to any person obtaining a copy of this software and associated documentation files (the
"Software"),to deal in the Software without restriction,including without limitation the rights to
use,copy,modify,merge,publish,distribute,sublicense,and/or sell copies of the Software,and to permit persons to whom the Software is
furnished to do so,subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS",WITHOUT WARRANTY OF ANY KIND,EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY,FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM,DAMAGES OR OTHER LIABILITY,WHETHER IN AN ACTION OF CONTRACT,TORT OR OTHERWISE,ARISING FROM,OUT OF OR IN CONNECTION WITH THE SOFTWARE
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _CFURL_H_
#define _CFURL_H_

#import <StubIncludes.h>
#import "CoreFoundation/CFBase.h"
#import "CoreFoundation/CFError.h"
#import "CoreFoundation/CFData.h"
#import "CoreFoundation/CFString.h"

COREFOUNDATION_EXTERNC_BEGIN

@class NSURL;
typedef NSURL* CFURLRef;

typedef enum {
    kCFURLComponentScheme = 1,
    kCFURLComponentNetLocation = 2,
    kCFURLComponentPath = 3,
    kCFURLComponentResourceSpecifier = 4,
    kCFURLComponentUser = 5,
    kCFURLComponentPassword = 6,
    kCFURLComponentUserInfo = 7,
    kCFURLComponentHost = 8,
    kCFURLComponentPort = 9,
    kCFURLComponentParameterString = 10,
    kCFURLComponentQuery = 11,
    kCFURLComponentFragment = 12,
} CFURLComponentType;

typedef enum {
    kCFURLPOSIXPathStyle = 0,
    kCFURLHFSPathStyle = 1,
    kCFURLWindowsPathStyle = 2,
} CFURLPathStyle;

enum {
    kCFURLBookmarkCreationPreferFileIDResolutionMask = (1UL << 8),
    kCFURLBookmarkCreationMinimalBookmarkMask = (1UL << 9),
    kCFURLBookmarkCreationSuitableForBookmarkFile = (1UL << 10),
    kCFURLBookmarkCreationWithSecurityScope = (1UL << 11),
    kCFURLBookmarkCreationSecurityScopeAllowOnlyReadAccess = (1UL << 12)
};
typedef CFOptionFlags CFURLBookmarkCreationOptions;

enum {
    kCFBookmarkResolutionWithoutUIMask = (1UL << 8),
    kCFBookmarkResolutionWithoutMountingMask = (1UL << 9),
    kCFURLBookmarkResolutionWithSecurityScope = (1UL << 10)
};
typedef CFOptionFlags CFURLBookmarkResolutionOptions;
typedef CFOptionFlags CFURLBookmarkFileCreationOptions;

COREFOUNDATION_EXPORT CFTypeID CFURLGetTypeID(void) STUB_METHOD;

COREFOUNDATION_EXPORT CFURLRef CFURLCreateAbsoluteURLWithBytes(CFAllocatorRef allocator,
                                                               const uint8_t* bytes,
                                                               CFIndex length,
                                                               CFStringEncoding encoding,
                                                               CFURLRef baseURL,
                                                               Boolean useCompatibilityMode) STUB_METHOD;

COREFOUNDATION_EXPORT CFURLRef CFURLCreateByResolvingBookmarkData(CFAllocatorRef allocator,
                                                                  CFDataRef bookmark,
                                                                  CFURLBookmarkResolutionOptions options,
                                                                  CFURLRef relativeToURL,
                                                                  CFArrayRef resourcePropertiesToInclude,
                                                                  Boolean* isStale,
                                                                  CFErrorRef* error) STUB_METHOD;

COREFOUNDATION_EXPORT CFDictionaryRef CFURLCopyResourcePropertiesForKeys(CFURLRef url, CFArrayRef keys, CFErrorRef* error) STUB_METHOD;

COREFOUNDATION_EXPORT Boolean CFURLCopyResourcePropertyForKey(CFURLRef url,
                                                              CFStringRef key,
                                                              void* propertyValueTypeRefPtr,
                                                              CFErrorRef* error) STUB_METHOD;

COREFOUNDATION_EXPORT void CFURLStopAccessingSecurityScopedResource(CFURLRef url) STUB_METHOD;

COREFOUNDATION_EXPORT Boolean CFURLSetResourcePropertiesForKeys(CFURLRef url,
                                                                CFDictionaryRef keyedPropertyValues,
                                                                CFErrorRef* error) STUB_METHOD;

COREFOUNDATION_EXPORT CFDataRef CFURLCreateBookmarkData(CFAllocatorRef allocator,
                                                        CFURLRef url,
                                                        CFURLBookmarkCreationOptions options,
                                                        CFArrayRef resourcePropertiesToInclude,
                                                        CFURLRef relativeToURL,
                                                        CFErrorRef* error) STUB_METHOD;

COREFOUNDATION_EXPORT CFDataRef CFURLCreateBookmarkDataFromFile(CFAllocatorRef allocator,
                                                                CFURLRef fileURL,
                                                                CFErrorRef* errorRef) STUB_METHOD;

COREFOUNDATION_EXPORT Boolean CFURLWriteBookmarkDataToFile(CFDataRef bookmarkRef,
                                                           CFURLRef fileURL,
                                                           CFURLBookmarkFileCreationOptions options,
                                                           CFErrorRef* errorRef) STUB_METHOD;

COREFOUNDATION_EXPORT Boolean CFURLStartAccessingSecurityScopedResource(CFURLRef url) STUB_METHOD;

COREFOUNDATION_EXPORT void CFURLSetTemporaryResourcePropertyForKey(CFURLRef url, CFStringRef key, CFTypeRef propertyValue) STUB_METHOD;

COREFOUNDATION_EXPORT Boolean CFURLSetResourcePropertyForKey(CFURLRef url, CFStringRef key, CFTypeRef propertyValue, CFErrorRef* error)
    STUB_METHOD;

COREFOUNDATION_EXPORT CFDictionaryRef CFURLCreateResourcePropertiesForKeysFromBookmarkData(CFAllocatorRef allocator,
                                                                                           CFArrayRef resourcePropertiesToReturn,
                                                                                           CFDataRef bookmark) STUB_METHOD;

COREFOUNDATION_EXPORT CFTypeRef CFURLCreateResourcePropertyForKeyFromBookmarkData(CFAllocatorRef allocator,
                                                                                  CFStringRef resourcePropertyKey,
                                                                                  CFDataRef bookmark) STUB_METHOD;

COREFOUNDATION_EXPORT CFURLRef CFURLCreateWithFileSystemPath(CFAllocatorRef allocator,
                                                             CFStringRef path,
                                                             CFURLPathStyle pathStyle,
                                                             Boolean isDirectory) STUB_METHOD;

COREFOUNDATION_EXPORT Boolean CFURLResourceIsReachable(CFURLRef url, CFErrorRef* error) STUB_METHOD;

COREFOUNDATION_EXPORT void CFURLClearResourcePropertyCache(CFURLRef url) STUB_METHOD;

COREFOUNDATION_EXPORT void CFURLClearResourcePropertyCacheForKey(CFURLRef url, CFStringRef key) STUB_METHOD;

COREFOUNDATION_EXPORT CFURLRef CFURLCreateWithFileSystemPathRelativeToBase(
    CFAllocatorRef allocator, CFStringRef path, CFURLPathStyle pathStyle, Boolean isDirectory, CFURLRef baseURL) STUB_METHOD;

COREFOUNDATION_EXPORT CFURLRef CFURLCreateWithString(CFAllocatorRef allocator, CFStringRef string, CFURLRef baseURL) STUB_METHOD;
COREFOUNDATION_EXPORT CFURLRef CFURLCreateFromFileSystemRepresentation(CFAllocatorRef allocator,
                                                                       const uint8_t* buffer,
                                                                       CFIndex length,
                                                                       Boolean isDirectory) STUB_METHOD;

COREFOUNDATION_EXPORT CFURLRef CFURLCreateFromFSRef(CFAllocatorRef allocator, const struct FSRef* fsRef) STUB_METHOD;

COREFOUNDATION_EXPORT CFURLRef CFURLCreateWithBytes(
    CFAllocatorRef allocator, const UInt8* URLBytes, CFIndex length, CFStringEncoding encoding, CFURLRef baseURL) STUB_METHOD;

COREFOUNDATION_EXPORT CFURLRef CFURLCreateFromFileSystemRepresentationRelativeToBase(
    CFAllocatorRef allocator, const uint8_t* buffer, CFIndex length, Boolean isDirectory, CFURLRef baseURL) STUB_METHOD;

COREFOUNDATION_EXPORT CFURLRef CFURLCopyAbsoluteURL(CFURLRef url) STUB_METHOD;

COREFOUNDATION_EXPORT CFStringRef CFURLGetString(CFURLRef self) STUB_METHOD;
COREFOUNDATION_EXPORT CFURLRef CFURLGetBaseURL(CFURLRef self) STUB_METHOD;
COREFOUNDATION_EXPORT Boolean CFURLCanBeDecomposed(CFURLRef self) STUB_METHOD;
COREFOUNDATION_EXPORT CFStringRef CFURLCopyFileSystemPath(CFURLRef self, CFURLPathStyle pathStyle) STUB_METHOD;
COREFOUNDATION_EXPORT CFStringRef CFURLCopyFragment(CFURLRef self, CFStringRef charactersToLeaveEscaped) STUB_METHOD;
COREFOUNDATION_EXPORT CFStringRef CFURLCopyHostName(CFURLRef self) STUB_METHOD;
COREFOUNDATION_EXPORT CFStringRef CFURLCopyLastPathComponent(CFURLRef self) STUB_METHOD;
COREFOUNDATION_EXPORT CFStringRef CFURLCopyNetLocation(CFURLRef self) STUB_METHOD;
COREFOUNDATION_EXPORT CFStringRef CFURLCopyParameterString(CFURLRef self, CFStringRef charactersToLeaveEscaped) STUB_METHOD;
COREFOUNDATION_EXPORT CFStringRef CFURLCopyPassword(CFURLRef self) STUB_METHOD;
COREFOUNDATION_EXPORT CFStringRef CFURLCopyPathExtension(CFURLRef self);
COREFOUNDATION_EXPORT CFStringRef CFURLCopyQueryString(CFURLRef self, CFStringRef charactersToLeaveEscaped) STUB_METHOD;
COREFOUNDATION_EXPORT CFStringRef CFURLCopyResourceSpecifier(CFURLRef self) STUB_METHOD;
COREFOUNDATION_EXPORT CFStringRef CFURLCopyScheme(CFURLRef self) STUB_METHOD;
COREFOUNDATION_EXPORT CFStringRef CFURLCopyStrictPath(CFURLRef self, Boolean* isAbsolute) STUB_METHOD;
COREFOUNDATION_EXPORT CFStringRef CFURLCopyUserName(CFURLRef self) STUB_METHOD;
COREFOUNDATION_EXPORT SInt32 CFURLGetPortNumber(CFURLRef self) STUB_METHOD;
COREFOUNDATION_EXPORT Boolean CFURLHasDirectoryPath(CFURLRef self) STUB_METHOD;

COREFOUNDATION_EXPORT CFURLRef CFURLCreateCopyAppendingPathComponent(CFAllocatorRef allocator,
                                                                     CFURLRef self,
                                                                     CFStringRef pathComponent,
                                                                     Boolean isDirectory) STUB_METHOD;

COREFOUNDATION_EXPORT CFURLRef CFURLCreateCopyAppendingPathExtension(CFAllocatorRef allocator,
                                                                     CFURLRef self,
                                                                     CFStringRef extension) STUB_METHOD;

COREFOUNDATION_EXPORT Boolean CFURLGetFSRef(CFURLRef url, struct FSRef* fsRef) STUB_METHOD;

COREFOUNDATION_EXPORT CFURLRef CFURLCreateCopyDeletingLastPathComponent(CFAllocatorRef allocator, CFURLRef self) STUB_METHOD;
COREFOUNDATION_EXPORT CFURLRef CFURLCreateCopyDeletingPathExtension(CFAllocatorRef allocator, CFURLRef self) STUB_METHOD;
COREFOUNDATION_EXPORT CFDataRef CFURLCreateData(CFAllocatorRef allocator,
                                                CFURLRef self,
                                                CFStringEncoding encoding,
                                                Boolean escapeWhitespace) STUB_METHOD;

COREFOUNDATION_EXPORT CFURLRef CFURLCreateFileReferenceURL(CFAllocatorRef allocator, CFURLRef url, CFErrorRef* error) STUB_METHOD;

COREFOUNDATION_EXPORT CFURLRef CFURLCreateFilePathURL(CFAllocatorRef allocator, CFURLRef url, CFErrorRef* error) STUB_METHOD;

COREFOUNDATION_EXPORT CFRange CFURLGetByteRangeForComponent(CFURLRef self,
                                                            CFURLComponentType component,
                                                            CFRange* rangeIncludingSeparators) STUB_METHOD;

COREFOUNDATION_EXPORT CFIndex CFURLGetBytes(CFURLRef self, uint8_t* buffer, CFIndex bufferLength) STUB_METHOD;
COREFOUNDATION_EXPORT Boolean CFURLGetFileSystemRepresentation(CFURLRef self,
                                                               Boolean resolveAgainstBase,
                                                               uint8_t* buffer,
                                                               CFIndex bufferLength) STUB_METHOD;

ENABLE_IMPLICIT_BRIDGING
COREFOUNDATION_EXPORT CFStringRef CFURLCreateStringByAddingPercentEscapes(CFAllocatorRef allocator,
                                                                          CFStringRef string,
                                                                          CFStringRef charactersToLeaveUnescaped,
                                                                          CFStringRef charactersToBeEscaped,
                                                                          CFStringEncoding encoding);

COREFOUNDATION_EXPORT CFStringRef CFURLCreateStringByReplacingPercentEscapes(CFAllocatorRef allocator,
                                                                             CFStringRef string,
                                                                             CFStringRef charactersToLeaveEscaped);

COREFOUNDATION_EXPORT CFStringRef CFURLCreateStringByReplacingPercentEscapesUsingEncoding(CFAllocatorRef allocator,
                                                                                          CFStringRef string,
                                                                                          CFStringRef charactersToLeaveEscaped,
                                                                                          CFStringEncoding encoding);

COREFOUNDATION_EXPORT CFStringRef CFURLCopyPath(CFURLRef self);
DISABLE_IMPLICIT_BRIDGING

COREFOUNDATION_EXTERNC_END

#endif /* _CFURL_H_ */
