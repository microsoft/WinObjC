//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#pragma once

#include <Foundation/NSString.h>
#include <Foundation/NSMutableArray.h>
#include <Foundation/NSMutableOrderedSet.h>
#include <Foundation/NSMutableSet.h>

#include <string>

NSString* _NSKVCSplitKeypath(NSString* keyPath, NSString* __autoreleasing* pRemainder);
struct objc_ivar* KVCIvarForPropertyName(NSObject* self, const char* propName);
SEL KVCGetterForPropertyName(NSObject* self, const char* key);
bool KVCGetViaAccessor(NSObject* self, SEL getter, id* ret);
bool KVCGetViaIvar(id self, struct objc_ivar* ivar, id* ret);
SEL KVCSetterForPropertyName(NSObject* self, const char* key);
bool KVCSetViaAccessor(NSObject* self, SEL setter, id value, NSString* key = nil);
bool KVCSetViaIvar(NSObject* self, struct objc_ivar* ivar, id value, NSString* key = nil);

// calls a method identified by a selector, given the specified arguments
template <typename Ret, typename... Args>
inline Ret _call(id target, SEL cmd, Args... args) {
    auto imp = objc_msg_lookup(target, cmd);
    return reinterpret_cast<Ret (*)(id, SEL, Args...)>(imp)(target, cmd, args...);
}

// This wraps the getter/s.
inline id _get(id target, SEL get, objc_ivar* ivar, NSString* key) {
    id object = nil;
    if (get) {
        KVCGetViaAccessor(target, get, &object);
    } else if (ivar) {
        KVCGetViaIvar(target, ivar, &object);
    } else {
        object = [target valueForKey:key];
    }
    return object;
}

inline void _set(id newValue, id target, SEL set, objc_ivar* ivar, NSString* key) {
    if (set) {
        KVCSetViaAccessor(target, set, newValue);
    } else if (ivar) {
        KVCSetViaIvar(target, ivar, newValue);
    } else {
        [target setValue:newValue forKey:key];
    }
}

inline void setIfResponds(id target, const std::string& selectorString, SEL* out) {
    SEL sel = sel_registerName(selectorString.c_str());
    *out = [target respondsToSelector:sel] ? sel : nullptr;
}

@interface _NSMutableKeyProxyArray : NSMutableArray
+ (instancetype)proxyArrayForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar;
@end

@interface _NSKeyProxyArray : NSArray
+ (instancetype)proxyArrayForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar;
- (_NSMutableKeyProxyArray*)_mutableProxy;
@end

@interface _NSMutableKeyProxySet : NSMutableSet
+ (instancetype)proxySetForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar;
@end

@interface _NSKeyProxySet : NSSet
+ (instancetype)proxySetForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar;
- (_NSMutableKeyProxySet*)_mutableProxy;
@end

@interface _NSMutableKeyProxyOrderedSet : NSMutableOrderedSet
+ (instancetype)proxyOrderedSetForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar;
@end
