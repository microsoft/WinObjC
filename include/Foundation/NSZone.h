/* Copyright (c) 2006-2008 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSZONE_H_
#define _NSZONE_H_

//#import <objc/runtime.h>
#import <Foundation/NSObjCRuntime.h>
#import <CoreFoundation/CFBase.h>

@class NSString;

@class NSZone;

FOUNDATION_EXPORT NSUInteger NSPageSize(void) STUB_METHOD;
FOUNDATION_EXPORT NSUInteger NSLogPageSize(void) STUB_METHOD;
FOUNDATION_EXPORT NSUInteger NSRoundDownToMultipleOfPageSize(NSUInteger byteCount) STUB_METHOD;
FOUNDATION_EXPORT NSUInteger NSRoundUpToMultipleOfPageSize(NSUInteger byteCount) STUB_METHOD;
FOUNDATION_EXPORT NSUInteger NSRealMemoryAvailable(void) STUB_METHOD;

FOUNDATION_EXPORT void* NSAllocateMemoryPages(NSUInteger byteCount) STUB_METHOD;
FOUNDATION_EXPORT void NSDeallocateMemoryPages(void* pointer, NSUInteger byteCount) STUB_METHOD;
FOUNDATION_EXPORT void NSCopyMemoryPages(const void* src, void* dst, NSUInteger byteCount) STUB_METHOD;

FOUNDATION_EXPORT NSZone* NSCreateZone(NSUInteger startSize, NSUInteger granularity, BOOL canFree) STUB_METHOD;
FOUNDATION_EXPORT NSZone* NSDefaultMallocZone(void) STUB_METHOD;
FOUNDATION_EXPORT void NSRecycleZone(NSZone* zone) STUB_METHOD;
FOUNDATION_EXPORT void NSSetZoneName(NSZone* zone, NSString* name) STUB_METHOD;
FOUNDATION_EXPORT NSString* NSZoneName(NSZone* zone) STUB_METHOD;
FOUNDATION_EXPORT NSZone* NSZoneFromPointer(void* pointer) STUB_METHOD;

FOUNDATION_EXPORT void* NSZoneCalloc(NSZone* zone, NSUInteger numElems, NSUInteger numBytes) STUB_METHOD;
FOUNDATION_EXPORT void NSZoneFree(NSZone* zone, void* pointer) STUB_METHOD;
FOUNDATION_EXPORT void* NSZoneMalloc(NSZone* zone, NSUInteger size) STUB_METHOD;
FOUNDATION_EXPORT void* NSZoneRealloc(NSZone* zone, void* pointer, NSUInteger size) STUB_METHOD;

FOUNDATION_EXPORT id NSAllocateObject(Class aClass, NSUInteger extraBytes, NSZone* zone);
FOUNDATION_EXPORT void NSDeallocateObject(id object);
FOUNDATION_EXPORT id NSCopyObject(id object, NSUInteger extraBytes, NSZone* zone) STUB_METHOD;
FOUNDATION_EXPORT BOOL NSShouldRetainWithZone(id object, NSZone* zone) STUB_METHOD;

FOUNDATION_EXPORT void NSIncrementExtraRefCount(id object) STUB_METHOD;
FOUNDATION_EXPORT BOOL NSDecrementExtraRefCountWasZero(id object) STUB_METHOD;
FOUNDATION_EXPORT NSUInteger NSExtraRefCount(id object) STUB_METHOD;

/**
 @Status Interoperable
*/
static inline id NSMakeCollectable(CFTypeRef cf) {
    id ret = nil;
#if !__has_feature(objc_arc)
    ret = cf ? (id)CFMakeCollectable(cf) : nil;
#endif
    return ret;
}

#endif // _NSZONE_H_