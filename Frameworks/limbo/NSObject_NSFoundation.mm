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

#import "Starboard.h"
#include <stdio.h>
#include <stdlib.h>
#import "Foundation/Foundation.h"
#include <Starboard/String.h>
#import "NSObjectInternal.h"
#include "../UnifiedFoundation/Foundation/NSValueTransformers.h"
#include "NSObject_NSKeyValueArrayAdapter-Internal.h"
#include "../objcrt/runtime.h"

#include "CoreGraphics/CGAffineTransform.h"
#include "QuartzCore/CATransform3D.h"

#include <memory>
#include <vector>
#include <unordered_set>
#include <functional>

@implementation NSObject (KeyValueCoding)

/**
 @Status Interoperable
*/
+ (BOOL)accessInstanceVariablesDirectly {
    return YES;
}

struct objc_ivar* KVCIvarForPropertyName(NSObject* self, const char* propName) {
    Class cls = object_getClass(self);
    if (![cls accessInstanceVariablesDirectly]) {
        return nullptr;
    }

    // For a given property x, our search order should be:
    // _x, _isX, x, isX.
    // If none of these is found, we don't support KVC for this key.
    // Key length is caller-checked.
    std::vector<std::string> searchIvars{
        woc::string::format("_%s", propName),
        woc::string::format("_is%c%s", toupper(propName[0]), &propName[1]),
        propName,
        woc::string::format("is%c%s", toupper(propName[0]), &propName[1]),
    };

    // Walk up the class hierarchy looking for matching ivars.
    for (; cls; cls = class_getSuperclass(cls)) {
        unsigned int ivarCount = 0;
        std::unique_ptr<Ivar, std::function<void(Ivar*)>> ivars(class_copyIvarList(cls, &ivarCount), free);
        auto foundIvar = std::find_if(ivars.get(),
                                      ivars.get() + ivarCount,
                                      [&searchIvars](const Ivar ivar) {
                                          // by using find_if, we avoid constructing a very short-lived std::string
                                          // for every ivar we iterate over.
                                          return std::find_if(searchIvars.cbegin(),
                                                              searchIvars.cend(),
                                                              [&ivar](const std::string& wantedIvarName) -> bool {
                                                                  return strcmp(ivar_getName(ivar), wantedIvarName.c_str()) == 0;
                                                              }) != searchIvars.cend();
                                      });
        if (foundIvar != ivars.get() + ivarCount) {
            return *foundIvar;
        }
    }

    return nullptr;
}

SEL KVCGetterForPropertyName(NSObject* self, const char* key) {
    // The possible getter selectors for a key x are -getX, -x, and -isX.
    // If we can't find any of these, we fall back to ivar lookup.
    // Key length is caller-checked.
    std::vector<std::string> possibleSelectors{
        woc::string::format("get%c%s", toupper(key[0]), &key[1]), key, woc::string::format("is%c%s", toupper(key[0]), &key[1]),
    };

    Class cls = object_getClass(self);
    for (auto& possibleSelString : possibleSelectors) {
        auto possibleSelector = sel_registerName(possibleSelString.c_str());
        if ([cls instancesRespondToSelector:possibleSelector]) {
            return possibleSelector;
        }
    }

    return nullptr;
}

bool KVCGetViaAccessor(NSObject* self, SEL getter, id* ret) {
    if (!getter) {
        return false;
    }

    NSMethodSignature* sig = [self methodSignatureForSelector:getter];
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:sig];

    [invocation setTarget:self];
    [invocation setSelector:getter];
    [invocation invoke];

    const char* valueType = [sig methodReturnType];
    NSInteger len = [sig methodReturnLength];

    std::vector<uint8_t> data(static_cast<size_t>(len));
    [invocation getReturnValue:data.data()];

    // We can't box or unbox char* or arbitrary pointers.
    if (valueType[0] == '*' || valueType[0] == '^' || valueType[0] == '?') {
        return false;
    }

    id val = woc::valueFromDataWithType(data.data(), valueType);

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

    const char* ivarType = ivar->type;
    void* data = reinterpret_cast<char*>(self) + ivar->offset;

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

- (id)_valueForKeyPath:(NSString*)path finalGetter:(SEL)finalGetterSelector {
    std::string keyPath([path UTF8String]);

    auto pointPosition = keyPath.find('.');
    if (pointPosition == std::string::npos && keyPath.find('@') == std::string::npos) {
        return [self performSelector:finalGetterSelector withObject:path];
    }

    std::string keyComponent(keyPath, 0, pointPosition);
    keyPath.erase(0, pointPosition + 1);

    id subValue = [self valueForKey:[NSString stringWithUTF8String:keyComponent.c_str()]];
    return [subValue _valueForKeyPath:[NSString stringWithUTF8String:keyPath.c_str()] finalGetter:finalGetterSelector];
}

/**
 @Status Caveat
 @Notes Does not support aggregate functions.
*/
- (id)valueForKeyPath:(NSString*)path {
    return [self _valueForKeyPath:path finalGetter:@selector(valueForKey:)];
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
    return [self _valueForKeyPath:keyPath finalGetter:@selector(mutableArrayValueForKey:)];
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
        std::vector<uint8_t> data(getArgumentSize(valueType));
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

    uint32_t offset = ivar->offset;
    const char* argType = ivar->type;

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
- (void)setValue:(id)value forKeyPath:(NSString*)path {
    std::string keyPath([path UTF8String]);

    auto pointPosition = keyPath.find('.');
    if (pointPosition == std::string::npos && keyPath.find('@') == std::string::npos) {
        [self setValue:value forKey:path];
        return;
    }

    std::string keyComponent(keyPath, 0, pointPosition);

    id subValue = [self valueForKey:[NSString stringWithUTF8String:keyComponent.c_str()]];
    [subValue setValue:value forKeyPath:[NSString stringWithUTF8String:keyPath.c_str() + pointPosition + 1]];
}

/**
 @Status Interoperable
 @Notes These throw exceptions. That's what they're supposed to do.
*/
- (void)setValue:(id)value forUndefinedKey:(NSString*)key {
    [NSException raise:NSInvalidArgumentException format:@"Class %s is not KVC compliant for key %@.", class_getName([self class]), key];
}
@end

@implementation NSObject (Foundation)
/**
 @Status Interoperable
*/
- (void)performSelectorOnMainThread:(SEL)selector withObject:(id)obj1 waitUntilDone:(BOOL)wait {
    id modes = [[NSArray alloc] initWithObject:@"kCFRunLoopDefaultMode"];
    [self performSelectorOnMainThread:selector withObject:obj1 waitUntilDone:wait modes:modes];
    selector, [modes release];
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
- (NSMethodSignature*)methodSignatureForSelector:(SEL)selector {
    return [[self class] instanceMethodSignatureForSelector:selector];
}

/**
 @Status Interoperable
*/
+ (NSMethodSignature*)instanceMethodSignatureForSelector:(SEL)selector {
    id cls = self;
    const char* methodTypes;
    while (cls) {
        methodTypes = objc_get_type_encoding(cls, selector);
        if (methodTypes)
            break;

        // Couldn't find it..
        cls = [cls superclass];
        if (!cls)
            return nil;
    }

    if (!methodTypes) {
        printf("Cannot find selector %s::%s\n", class_getName(self), sel_getName(selector));
        return nil;
    }

    return [NSMethodSignature signatureWithObjCTypes:methodTypes];
}

/**
 @Status Interoperable
*/
+ (NSString*)description {
    return NSStringFromClass([self class]);
}

- (NSString*)description {
    return [NSString stringWithFormat:@"<%@: %p>", NSStringFromClass([self class]), self];
}

+ (void)_raiseSelectorNotFoundError:(SEL)selector format:(const char*)format, ... {
    va_list va;
    va_start(va, format);
    NSString* err = [[[NSString alloc] initWithFormat:[NSString stringWithCString:format] arguments:va] autorelease];
    va_end(va);

    [NSException raiseWithLogging:@"SelectorNotFound" format:@"%@", err];
}
@end

/** Included to force TU to be linked - remove once exported as DLL **/
extern "C" void NSObjForceinclude() {
}
