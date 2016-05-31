//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <Foundation/Foundation.h>
#import <Foundation/NSKeyValueCoding.h>
#import <Starboard/String.h>

#import "NSArrayInternal.h"
#import "NSDelayedPerform.h"
#import "NSObject_NSKeyValueArrayAdapter-Internal.h"
#import "NSObject_NSKeyValueCoding-Internal.h"
#import "NSRunLoop+Internal.h"
#import "NSThread-Internal.h"
#import "NSValueTransformers.h"
#import "Starboard.h"
#include "StubReturn.h"

#import <unicode/utf8.h>

#include <functional>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
#include <vector>

NSString* const NSUndefinedKeyException = @"NSUndefinedKeyException";
NSString* const NSTargetObjectUserInfoKey = @"NSTargetObjectUserInfoKey";
NSString* const NSUnknownUserInfoKey = @"NSUnknownUserInfoKey";
NSString* const NSAverageKeyValueOperator = @"NSAverageKeyValueOperator";
NSString* const NSCountKeyValueOperator = @"NSCountKeyValueOperator";
NSString* const NSDistinctUnionOfArraysKeyValueOperator = @"NSDistinctUnionOfArraysKeyValueOperator";
NSString* const NSDistinctUnionOfObjectsKeyValueOperator = @"NSDistinctUnionOfObjectsKeyValueOperator";
NSString* const NSDistinctUnionOfSetsKeyValueOperator = @"NSDistinctUnionOfSetsKeyValueOperator";
NSString* const NSMaximumKeyValueOperator = @"NSMaximumKeyValueOperator";
NSString* const NSMinimumKeyValueOperator = @"NSMinimumKeyValueOperator";
NSString* const NSSumKeyValueOperator = @"NSSumKeyValueOperator";
NSString* const NSUnionOfArraysKeyValueOperator = @"NSUnionOfArraysKeyValueOperator";
NSString* const NSUnionOfObjectsKeyValueOperator = @"NSUnionOfObjectsKeyValueOperator";
NSString* const NSUnionOfSetsKeyValueOperator = @"NSUnionOfSetsKeyValueOperator";

NSString* _NSKVCSplitKeypath(NSString* keyPath, NSString* __autoreleasing* pRemainder) {
    NSData* utf8String = [keyPath dataUsingEncoding:NSUTF8StringEncoding];
    const char* buffer = static_cast<const char*>(utf8String.bytes);
    NSInteger length = utf8String.length;
    int i = 0;
    UChar32 currentCharacter = 0;
    while (i < length) {
        U8_NEXT(buffer, i, length, currentCharacter);
        if (currentCharacter == '.') {
            *pRemainder = [[[NSString alloc] initWithBytesNoCopy:const_cast<char*>(buffer + i)
                                                          length:length - i
                                                        encoding:NSUTF8StringEncoding
                                                    freeWhenDone:NO] autorelease];
            return
                [[[NSString alloc] initWithBytesNoCopy:const_cast<char*>(buffer) length:i - 1 encoding:NSUTF8StringEncoding freeWhenDone:NO]
                    autorelease];
        }
    }
    *pRemainder = nil;
    return keyPath;
}

@implementation NSObject (NSKeyValueCoding)

/**
 @Status Interoperable
*/
+ (BOOL)accessInstanceVariablesDirectly {
    return YES;
}

// clang-format off
static bool _ivarIsKVCCompliant(Ivar ivar, const char* propName) {
    // For a given property x, our search order should be:
    // _x, _isX, x, isX.
    // If none of these is found, we don't support KVC for this key.
    // Key length is caller-checked.
    char upper = toupper(propName[0]);
    const char* ivarName = ivar_getName(ivar);
    return (
        /* (has _) */ ivarName[0] == '_' && (
        /* _prop   */ (strcmp(ivarName + 1, propName) == 0)
        /* _isProp */ || (ivarName[1] == 'i' && ivarName[2] == 's' && ivarName[3] == upper && (strcmp(ivarName + 4, propName + 1) == 0))
        /* (no _)  */ ))
        /* prop    */ || (strcmp(ivarName, propName) == 0
        /* isProp  */ || (ivarName[0] == 'i' && ivarName[1] == 's' && ivarName[2] == upper && (strcmp(ivarName + 3, propName + 1) == 0)));
}
// clang-format on

struct objc_ivar* KVCIvarForPropertyName(NSObject* self, const char* propName) {
    Class cls = object_getClass(self);
    if (![cls accessInstanceVariablesDirectly]) {
        return nullptr;
    }

    // Walk up the class hierarchy looking for matching ivars.
    for (; cls; cls = class_getSuperclass(cls)) {
        unsigned int ivarCount = 0;
        std::unique_ptr<Ivar, std::function<void(Ivar*)>> ivars(class_copyIvarList(cls, &ivarCount), IwFree);
        auto foundIvar =
            std::find_if(ivars.get(), ivars.get() + ivarCount, [propName](const Ivar ivar) { return _ivarIsKVCCompliant(ivar, propName); });
        if (foundIvar != ivars.get() + ivarCount) {
            return *foundIvar;
        }
    }

    return nullptr;
}

// clang-format off
SEL KVCGetterForPropertyName(NSObject* self, const char* key) {
    // The possible getter selectors for a key x are -getX, -x, and -isX.
    // If we can't find any of these, we fall back to ivar lookup.
    // Key length is caller-checked.
    std::vector<SEL (^)()> possibleSelectors {
        ^SEL{ return sel_registerName(woc::string::format("get%c%s", toupper(key[0]), &key[1]).c_str()); },
        ^SEL{ return sel_registerName(key); },
        ^SEL{ return sel_registerName(woc::string::format("is%c%s", toupper(key[0]), &key[1]).c_str()); },
    };

    Class cls = object_getClass(self);
    for (auto& possibleSelGenerator : possibleSelectors) {
        SEL possibleSelector = possibleSelGenerator();
        if ([cls instancesRespondToSelector:possibleSelector]) {
            return possibleSelector;
        }
    }

    return nullptr;
}
// clang-format on

bool KVCGetViaAccessor(NSObject* self, SEL getter, id* ret) {
    if (!getter) {
        return false;
    }

    NSMethodSignature* sig = [self methodSignatureForSelector:getter];

    const char* valueType = [sig methodReturnType];
    // We can't box or unbox char* or arbitrary pointers.
    if (valueType[0] == '*' || valueType[0] == '^' || valueType[0] == '?') {
        return false;
    }

    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:sig];

    [invocation setTarget:self];
    [invocation setSelector:getter];
    [invocation invoke];

    NSInteger len = [sig methodReturnLength];
    id val = nil;

    if (len <= 16) { // Don't allocate for <= 16 bytes, we can handle that on the stack.
        uint8_t buf[16];
        [invocation getReturnValue:&buf[0]];
        val = woc::valueFromDataWithType(&buf[0], valueType);
    } else {
        std::vector<uint8_t> data(static_cast<size_t>(len));
        [invocation getReturnValue:data.data()];
        val = woc::valueFromDataWithType(data.data(), valueType);
    }

    if (val) {
        *ret = val;
    }

    // The return value here signals that an accessor was found, not that it produced a value.
    // That is to say: a getter can return nil and not be considered a failure.
    return true;
}

bool KVCGetViaIvar(id self, struct objc_ivar* ivar, id* ret) {
    if (!ivar) {
        return false;
    }

    const char* ivarType = ivar_getTypeEncoding(ivar);
    void* data = reinterpret_cast<char*>(self) + ivar_getOffset(ivar);

    // We can't box or unbox char* or arbitrary pointers.
    if (ivarType[0] == '*' || ivarType[0] == '^' || ivarType[0] == '?') {
        return false;
    }

    *ret = woc::valueFromDataWithType(data, ivarType);
    return true;
}

static bool tryGetArrayAdapter(id self, const char* key, id* ret) {
    auto countSelectorString(woc::string::format("countOf%c%s", toupper(key[0]), &key[1]));
    auto objectInAtSelectorString(woc::string::format("objectIn%c%sAtIndex:", toupper(key[0]), &key[1]));
    auto objectsAtSelectorString(woc::string::format("%sAtIndexes:", key));

    auto countSelector(sel_registerName(countSelectorString.c_str()));
    auto objectInAtSelector(sel_registerName(objectInAtSelectorString.c_str()));
    auto objectsAtSelector(sel_registerName(objectsAtSelectorString.c_str()));

    // If it doesn't respond to countOfX, or it doesn't respond to either
    // objectIn or objectsAt, bail.
    if (![self respondsToSelector:countSelector] ||
        !([self respondsToSelector:objectInAtSelector] || [self respondsToSelector:objectsAtSelector])) {
        return false;
    }

    *ret = [_NSKeyProxyArray proxyArrayForObject:self key:[NSString stringWithUTF8String:key] ivar:nullptr];
    return true;
}

/**
 @Status Caveat
 @Notes Does not support aggregate functions.
*/
- (id)valueForKeyPath:(NSString*)keyPath {
    NSString* key = nil;
    NSString* restOfKeypath;
    key = _NSKVCSplitKeypath(keyPath, &restOfKeypath);

    id val = [self valueForKey:key];

    if (restOfKeypath) {
        // We must recurse here, as any class may override valueForKeyPath.
        return [val valueForKeyPath:restOfKeypath];
    }

    return val;
}

/**
 @Status Caveat
 @Notes Does not support set adapters
*/
- (id)valueForKey:(NSString*)key {
    if ([key length] == 0) {
        // Bail quickly
        return [self valueForUndefinedKey:key];
    }

    const char* rawKey = [key UTF8String];
    auto accessor = KVCGetterForPropertyName(self, rawKey);
    id ret = nil;
    if (KVCGetViaAccessor(self, accessor, &ret)) {
        return ret;
    }

    if (tryGetArrayAdapter(self, rawKey, &ret)) {
        return ret;
    }
    // TODO: Add NSMutableSet adapter and its support machinery.

    auto ivar = KVCIvarForPropertyName(self, rawKey);
    if (ivar && KVCGetViaIvar(self, ivar, &ret)) {
        return ret;
    }

    return [self valueForUndefinedKey:key];
}

/**
 @Status Interoperable
*/
- (NSMutableArray*)mutableArrayValueForKey:(NSString*)key {
    if ([key length] == 0) {
        // Bail quickly
        return [self valueForUndefinedKey:key];
    }

    const char* rawKey = [key UTF8String];

    auto accessor = KVCGetterForPropertyName(self, rawKey);
    struct objc_ivar* ivar = KVCIvarForPropertyName(self, rawKey);

    return [_NSMutableKeyProxyArray proxyArrayForObject:self key:key ivar:ivar];
}

/**
 @Status Interoperable
*/
- (NSMutableArray*)mutableArrayValueForKeyPath:(NSString*)keyPath {
    NSString* key = nil;
    NSString* restOfKeypath;
    key = _NSKVCSplitKeypath(keyPath, &restOfKeypath);

    if (restOfKeypath) {
        id val = [self valueForKey:key];
        return [val mutableArrayValueForKeyPath:restOfKeypath];
    }

    return [self mutableArrayValueForKey:key];
}

/**
 @Status Interoperable
 @Notes These throw exceptions. That's what they're supposed to do.
*/
- (id)valueForUndefinedKey:(NSString*)key {
    [NSException raise:NSInvalidArgumentException format:@"Class %s is not KVC compliant for key %@.", class_getName([self class]), key];
    return nil;
}

SEL KVCSetterForPropertyName(NSObject* self, const char* key) {
    auto accessorName(woc::string::format("set%c%s:", toupper(key[0]), &key[1]));
    auto sel = sel_registerName(accessorName.c_str());
    if ([[self class] instancesRespondToSelector:sel]) {
        return sel;
    }

    return nullptr;
}

bool KVCSetViaAccessor(NSObject* self, SEL setter, id value) {
    if (!setter) {
        return false;
    }

    NSMethodSignature* sig = [self methodSignatureForSelector:setter];

    // 3 arguments: self, selector, new value.
    if (sig && [sig numberOfArguments] == 3) {
        NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:sig];

        const char* valueType = [sig getArgumentTypeAtIndex:2];
        std::vector<uint8_t> data(objc_sizeof_type(valueType));
        if (!woc::dataWithTypeFromValue(data.data(), valueType, value)) {
            return false;
        }

        [invocation setTarget:self];
        [invocation setSelector:setter];
        [invocation setArgument:data.data() atIndex:2];
        [invocation invoke];
        return true;
    }
    return false;
}

bool KVCSetViaIvar(NSObject* self, struct objc_ivar* ivar, id value) {
    if (!ivar) {
        return false;
    }

    uint32_t offset = ivar_getOffset(ivar);
    const char* argType = ivar_getTypeEncoding(ivar);

    void* destination = reinterpret_cast<char*>(self) + offset;
    if (!woc::dataWithTypeFromValue(destination, argType, value)) {
        return false;
    }
    if (argType[0] == '@') {
        // retain object-type ivar, old value is _not_ released (iOS/OS X behavior)
        [*reinterpret_cast<id*>(destination) retain];
    }

    return true;
}

/**
 @Status Caveat
*/
- (void)setValue:(id)val forKey:(NSString*)key {
    if ([key length] == 0) {
        // Bail quickly
        [self setValue:val forUndefinedKey:key];
        return;
    }

    const char* rawKey = [key UTF8String];
    if (KVCSetViaAccessor(self, KVCSetterForPropertyName(self, rawKey), val)) {
        return;
    }

    auto ivar = KVCIvarForPropertyName(self, rawKey);
    if (ivar) {
        BOOL shouldNotify = [[self class] automaticallyNotifiesObserversForKey:key];

        if (shouldNotify) {
            [self willChangeValueForKey:key];
        }

        if (KVCSetViaIvar(self, ivar, val)) {
            if (shouldNotify) {
                [self didChangeValueForKey:key];
            }
            return;
        }
    }

    [self setValue:val forUndefinedKey:key];
}

/**
 @Status Interoperable
*/
- (void)setValue:(id)value forKeyPath:(NSString*)keyPath {
    NSString* key = nil;
    NSString* restOfKeypath;
    key = _NSKVCSplitKeypath(keyPath, &restOfKeypath);

    if (restOfKeypath) {
        // We must recurse here, as any class may override valueForKeyPath.
        id val = [self valueForKey:key];
        return [val setValue:value forKeyPath:restOfKeypath];
    }

    [self setValue:value forKey:key];
}

/**
 @Status Interoperable
 @Notes These throw exceptions. That's what they're supposed to do.
*/
- (void)setValue:(id)value forUndefinedKey:(NSString*)key {
    [NSException raise:NSInvalidArgumentException format:@"Class %s is not KVC compliant for key %@.", class_getName([self class]), key];
}

/**
 @Status Interoperable
*/
- (void)setValuesForKeysWithDictionary:(NSDictionary*)keyedValues {
    for (NSString* key in keyedValues) {
        id value = [keyedValues objectForKey:key];
        if (value == [NSNull null]) {
            value = nil;
        }
        [self setValue:value forKey:key];
    }
}

/**
 @Status Interoperable
*/
- (NSDictionary*)dictionaryWithValuesForKeys:(NSArray*)keys {
    NSDictionary* results = [NSMutableDictionary dictionaryWithCapacity:keys.count];

    for (NSString* key in keys) {
        id retValue = [self valueForKey:key];
        [results setValue:(retValue ?: [NSNull null]) forKey:key];
    }

    return [[results copy] autorelease];
}

/**
 @Status Stub
 @Notes
*/
- (NSMutableSet*)mutableSetValueForKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSMutableSet*)mutableSetValueForKeyPath:(NSString*)keyPath {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSMutableOrderedSet*)mutableOrderedSetValueForKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSMutableOrderedSet*)mutableOrderedSetValueForKeyPath:(NSString*)keyPath {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setNilValueForKey:(NSString*)key {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)validateValue:(id _Nullable*)ioValue forKey:(NSString*)key error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)validateValue:(id _Nullable*)ioValue forKeyPath:(NSString*)key error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

@end

@implementation NSObject (Foundation)
/**
 @Status Interoperable
*/
- (void)performSelectorOnMainThread:(SEL)selector withObject:(id)obj1 waitUntilDone:(BOOL)wait {
    [self performSelectorOnMainThread:selector withObject:obj1 waitUntilDone:wait modes:@[ @"kCFRunLoopDefaultMode" ]];
}

/**
 @Status Interoperable
*/
- (void)performSelectorOnMainThread:(SEL)selector withObject:(id)obj waitUntilDone:(BOOL)wait modes:(NSArray*)modes {
    [self performSelector:selector onThread:[NSThread mainThread] withObject:obj waitUntilDone:wait modes:modes];
}

/**
 @Status Interoperable
*/
- (void)performSelectorInBackground:(SEL)selector withObject:(id)obj {
    [NSThread detachNewThreadSelector:selector toTarget:self withObject:obj];
}

+ (void)performSelectorInBackground:(SEL)selector withObject:(id)obj {
    [NSThread detachNewThreadSelector:selector toTarget:self withObject:obj];
}

- (void)_performSelectorAndSignal:(NSArray*)args {
    NSConditionLock* waitingLock = args[0];
    SEL selector = NSSelectorFromString(args[1]);
    id object = (id)[args[2] pointerValue];

    [waitingLock lockWhenCondition:0];

    [self performSelector:selector withObject:object];

    [waitingLock unlockWithCondition:1];
}

/**
 @Status Interoperable
*/
- (void)performSelector:(SEL)selector onThread:(NSThread*)thread withObject:(id)obj waitUntilDone:(BOOL)waitUntilDone modes:(id)modes {
    NSRunLoop* runloop = [thread _runLoop];

    if (waitUntilDone) {
        if (thread == [NSThread currentThread]) {
            [self performSelector:selector withObject:obj];
        } else {
            if (!runloop) {
                [NSException raise:NSInvalidArgumentException
                            format:@"Can't perform selector %@: Thread %@ has no runloop", NSStringFromSelector(_cmd), thread];
            }

            NSConditionLock* waitingLock = [[NSConditionLock alloc] initWithCondition:0];

            [runloop performSelector:@selector(_performSelectorAndSignal:)
                              target:self
                            argument:@[ waitingLock, NSStringFromSelector(selector), [NSValue valueWithPointer:obj] ]
                               order:0
                               modes:modes];

            [waitingLock lockWhenCondition:TRUE];
            [waitingLock unlock];
            [waitingLock release];
        }
    } else {
        if (runloop == nil) {
            [NSException raise:NSInvalidArgumentException
                        format:@"Can't perform selector %2: Thread %@ has no runloop", NSStringFromSelector(_cmd), thread];
        }

        [runloop performSelector:selector target:self argument:obj order:0 modes:modes];
    }
}

/**
 @Status Interoperable
*/
- (void)performSelector:(SEL)selector onThread:(id)thread withObject:(id)obj waitUntilDone:(BOOL)wait {
    [self performSelector:selector
                 onThread:thread
               withObject:obj
            waitUntilDone:wait
                    modes:[NSArray arrayWithObject:@"kCFRunLoopDefaultMode"]];
}

+ (void)_delayedPerform:(NSTimer*)timer {
    id delayed = [timer userInfo];
    [delayed perform];
}

+ (void)object:(id)object performSelector:(SEL)selector withObject:(id)argument afterDelay:(double)delay inModes:(NSArray*)modes {
    NSDelayedPerform* delayed = [NSDelayedPerform delayedPerformWithObject:object selector:selector argument:argument];
    NSTimer* timer =
        [NSTimer timerWithTimeInterval:delay target:[NSObject class] selector:@selector(_delayedPerform:) userInfo:delayed repeats:NO];
    int i, count = [modes count];

    for (i = 0; i < count; i++) {
        [[NSRunLoop currentRunLoop] addTimer:timer forMode:[modes objectAtIndex:i]];
    }
}

/**
 @Status Interoperable
*/
- (void)performSelector:(SEL)selector withObject:(id)obj1 afterDelay:(double)delay {
    [[self class] object:self
         performSelector:selector
              withObject:obj1
              afterDelay:delay
                 inModes:[NSArray arrayWithObject:@"kCFRunLoopDefaultMode"]];
}

/**
 @Status Interoperable
*/
- (void)performSelector:(SEL)selector withObject:(id)obj1 afterDelay:(double)delay inModes:(NSArray*)modes {
    [[self class] object:self performSelector:selector withObject:obj1 afterDelay:delay inModes:modes];
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"
// We're temporarily disabling the warning about implementing a non-category method
// in a category until we determine where to put the NSObject threading extensions.

/**
 @Status Interoperable
*/
+ (void)cancelPreviousPerformRequestsWithTarget:(id)aTarget {
    [self cancelPreviousPerformRequestsWithTarget:aTarget selector:NULL object:nil];
}

/**
 @Status Interoperable
*/
+ (void)cancelPreviousPerformRequestsWithTarget:(id)aTarget selector:(SEL)aSelector object:(id)anArgument {
    NSDelayedPerform* delayed = [[NSDelayedPerform alloc] initWithObject:aTarget selector:aSelector argument:anArgument];
    [[NSRunLoop currentRunLoop] _invalidateTimerWithDelayedPerform:delayed];
    [delayed release];
}
#pragma clang diagnostic pop

@end
