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
#include "../objcrt/runtime.h"

#include "Platform/EbrPlatform.h"

/**
 @Status Interoperable
*/
void CFRelease(CFTypeRef obj) {
    objc_release_ref((id)obj);
}

/**
 @Status Interoperable
*/
CFTypeRef CFRetain(CFTypeRef obj) {
    return objc_retain_ref((id)obj);
}

/**
 @Status Interoperable
*/
CFIndex CFGetRetainCount(CFTypeRef obj) {
    return (CFIndex)objc_getRetainCount((id)obj);
}

BOOL CFIsRetained(CFTypeRef obj) {
    return objc_isRetained((id)obj);
}

/**
 @Status Interoperable
*/
Boolean CFEqual(CFTypeRef obj1, CFTypeRef obj2) {
    return (BOOL)[(id)obj1 isEqual:(id)obj2];
}

/**
 @Status Interoperable
 @Notes May not return an identically compatible value
*/
uint32_t CFHash(CFTypeRef obj) {
    return (uint32_t)[(id)obj hash];
}

/**
 @Status Stub
*/
void CFShow(CFTypeRef obj) {
    UNIMPLEMENTED();
    EbrDebugLog("CFShow: %s\n", object_getClassName((id)obj));
}

/**
 @Status Interoperable
 @Notes No-op; garbage collection is not supported in WinObjC
*/
CFTypeRef CFMakeCollectable(CFTypeRef obj) {
    return obj;
}

/**
 @Status Caveat
 @Notes NSZone not supported
*/
__declspec(dllexport) id NSAllocateObject(Class classRef, NSUInteger extraBytes, NSZone* zone) {
    assert(zone == nil);

    return objc_allocateObject(classRef, extraBytes);
}

/**
 @Status Interoperable
*/
__declspec(dllexport) void NSDeallocateObject(id obj) {
    return objc_deallocateObject(obj);
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
