//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#include "Starboard.h"
#include "CoreFoundation/CFType.h"
#include "Foundation/NSString.h"

#include "objc/runtime.h"
#include "objc/objc.h"
#include "objc/objc-arc.h"

#include "Platform/EbrPlatform.h"

/**
 @Status Interoperable
*/
void CFRelease(CFTypeRef obj) {
    objc_release(static_cast<id>(obj));
}

/**
 @Status Interoperable
*/
void CFAutorelease(CFTypeRef obj) {
    objc_autorelease(static_cast<id>(obj));
}

/**
 @Status Interoperable
*/
CFTypeRef CFRetain(CFTypeRef obj) {
    return objc_retain(static_cast<id>(obj));
}

/**
 @Status Interoperable
*/
CFIndex CFGetRetainCount(CFTypeRef obj) {
    return [reinterpret_cast<id>(const_cast<void*>(obj)) retainCount];
}

BOOL CFIsRetained(CFTypeRef obj) {
    return CFGetRetainCount(obj) >= 1;
}

/**
 @Status Interoperable
*/
Boolean CFEqual(CFTypeRef obj1, CFTypeRef obj2) {
    return (BOOL)[static_cast<id>(obj1) isEqual:static_cast<id>(obj2)];
}

/**
 @Status Interoperable
 @Notes May not return an identically compatible value
*/
uint32_t CFHash(CFTypeRef obj) {
    return (uint32_t)[static_cast<id>(obj) hash];
}

/**
 @Status Stub
*/
void CFShow(CFTypeRef obj) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
 @Notes No-op; garbage collection is not supported in WinObjC
*/
CFTypeRef CFMakeCollectable(CFTypeRef obj) {
    return obj;
}

/**
 @Status Interoperable
 @Notes As on the reference platform, NSZone is ignored.
*/
id NSAllocateObject(Class classRef, NSUInteger extraBytes, NSZone* zone) {
    return class_createInstance(classRef, extraBytes);
}

/**
 @Status Interoperable
*/
void NSDeallocateObject(id obj) {
    objc_delete_weak_refs(obj);
    object_dispose(obj);
}

DWORD _NSSetLogCStringFunction(DWORD func) {
    EbrDebugLog("NSSetLogCStringFunction not implemented\n");

    return 0;
}

#if 0
enum {
CFUnknownType,
CFStringType,
CFDictionaryType,
CFArrayType,
CFNumberType,
CFBooleanType,
CGLayerType,
CFBundleType,
CFBinaryHeap,
} CFTypeIDs;

DWORD CFGetTypeID(id cfobj)
{
id objType = cfobj;
if ( [objType isKindOfClass:[NSString class]] ) {
return CFStringType;
}
if ( [objType isKindOfClass:[NSDictionary class]] ) {
return CFDictionaryType;
}
if ( [objType isKindOfClass:[CFBinaryHeap class]] ) {
return CFBinaryHeap;
}
if ( [objType isKindOfClass:[NSArray class]] ) {
return CFArrayType;
}
if ( [objType isKindOfClass:[NSNumber class]] ) {
if ( [objType _isBool] ) {
return CFBooleanType;
}

return CFNumberType;
}
if ( [objType isKindOfClass:[CGLayer class]] ) {
return CGLayerType;
}
if ( [objType isKindOfClass:[NSBundle class]] ) {
return CFBundleType;
}
assert(0);

return 0;
}

DWORD CFBinaryHeapGetTypeID()
{
return CFBinaryHeap;
}

DWORD CFDictionaryGetTypeID()
{
return CFDictionaryType;
}

DWORD CFArrayGetTypeID()
{
return CFArrayType;
}

DWORD CFStringGetTypeID()
{
return CFStringType;
}

DWORD CFBooleanGetTypeID()
{
return CFBooleanType;
}

DWORD CFNumberGetTypeID()
{
return CFNumberType;
}

DWORD CGLayerGetTypeID()
{
return CGLayerType;
}

DWORD CFBundleGetTypeID()
{
return CFBundleType;
}

DWORD CFDateCreate(id allocator, double abstime)
{
id ret = [[NSDate alloc] initWithTimeIntervalSinceReferenceDate:abstime];

return ret;
}

static id defaultZone = nil;

DWORD NSDefaultMallocZone()
{
if ( defaultZone == nil ) {
defaultZone = [NSObject new];
}

return defaultZone;
}

DWORD NSZoneFromPointer(void *ptr)
{
if ( defaultZone == nil ) {
defaultZone = [NSObject new];
}

return defaultZone;
}
#endif

id CFNSRetain(id allocator, id obj) {
    return [obj retain];
}

id CFNSRelease(id allocator, id obj) {
    [obj release];

    return obj;
}
