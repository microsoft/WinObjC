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
#include "../Foundation/NSValueTransformers.h"
#include "../objcrt/runtime.h"

#include "CoreGraphics/CGAffineTransform.h"
#include "QuartzCore/CATransform3D.h"

#include <memory>
#include <vector>
#include <unordered_set>
#include <functional>

@implementation NSObject (Foundation)

/**
 @Status Interoperable
*/
+ (BOOL)accessInstanceVariablesDirectly {
    return YES;
}

static struct objc_ivar* ivarForPropertyName(Class cls, const char* propName) {
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

static bool tryGetViaAccessor(NSObject* self, const char* key, id* ret) {
    // The possible getter selectors for a key x are -getX, -x, and -isX.
    // If we can't find any of these, we fall back to ivar lookup.
    // Key length is caller-checked.
    std::vector<std::string> possibleSelectors{
        woc::string::format("get%c%s", toupper(key[0]), &key[1]), key, woc::string::format("is%c%s", toupper(key[0]), &key[1]),
    };

    SEL selector = nullptr;
    for (auto& possibleSelString : possibleSelectors) {
        auto possibleSelector = sel_registerName(possibleSelString.c_str());
        if ([object_getClass(self) instancesRespondToSelector:possibleSelector]) {
            selector = possibleSelector;
            break;
        }
    }

    if (!selector) {
        return false;
    }

    NSMethodSignature* sig = [self methodSignatureForSelector:selector];
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:sig];

    [invocation setTarget:self];
    [invocation setSelector:selector];
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

static bool tryGetViaIvar(id self, const char* propName, id* ret) {
    Class cls = object_getClass(self);
    auto curIvar = ivarForPropertyName(cls, propName);
    if (!curIvar) {
        return false;
    }

    const char* ivarType = curIvar->type;
    void* data = reinterpret_cast<char*>(self) + curIvar->offset;

    // We can't box or unbox char* or arbitrary pointers.
    if (ivarType[0] == '*' || ivarType[0] == '^' || ivarType[0] == '?') {
        return false;
    }

    *ret = woc::valueFromDataWithType(data, ivarType);
    return true;
}

/**
 @Status Caveat
 @Notes Does not support aggregate functions.
*/
- (id)valueForKeyPath:(NSString*)path {
    const char* keyPath = [path UTF8String];

    if (strstr(keyPath, ".") == NULL && strstr(keyPath, "@") == NULL) {
        return [self valueForKey:path];
    }

    char* dup = _strdup(keyPath);
    char* save;
    char* curPath = strtok_s(dup, ".", &save);
    id ret = self;

    while (curPath) {
        ret = [ret valueForKey:[NSString stringWithUTF8String:curPath]];
        curPath = strtok_s(NULL, ".", &save);
    }

    free(dup);

    return ret;
}

/**
 @Status Caveat
 @Notes Does not support set/array adapters
*/
- (id)valueForKey:(NSString*)key {
    if ([key length] == 0) {
        // Bail quickly
        return [self valueForUndefinedKey:key];
    }

    const char* rawKey = [key UTF8String];
    id ret = nil;
    if (tryGetViaAccessor(self, rawKey, &ret)) {
        return ret;
    }

    // TODO: Add NSMutableArray and NSMutableSet adapters and their support machinery.

    if ([[self class] accessInstanceVariablesDirectly] && tryGetViaIvar(self, rawKey, &ret)) {
        return ret;
    }

    return [self valueForUndefinedKey:key];
}

/**
 @Status Interoperable
 @Notes These throw exceptions. That's what they're supposed to do.
*/
- (id)valueForUndefinedKey:(NSString*)key {
    [NSException raise:NSInvalidArgumentException format:@"Class %s is not KVC compliant for key %@.", class_getName([self class]), key];
    return nil;
}

static bool trySetViaAccessor(NSObject* self, const char* key, id value) {
    auto accessorName(woc::string::format("set%c%s:", toupper(key[0]), &key[1]));
    auto sel = sel_registerName(accessorName.c_str());
    NSMethodSignature* sig = [self methodSignatureForSelector:sel];

    // 3 arguments: self, selector, new value.
    if (sig && [sig numberOfArguments] == 3) {
        NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:sig];

        const char* valueType = [sig getArgumentTypeAtIndex:2];
        std::vector<uint8_t> data(getArgumentSize(valueType));
        if (valueType[0] == '@') { // Method is expecting an object: give it the object directly
            memcpy(data.data(), &value, sizeof(id));
        } else if (valueType[0] == '*' || valueType[0] == '^' || valueType[0] == '?') {
            // We can't box or unbox char* or arbitrary pointers.
            return false;
        } else if ([value isKindOfClass:[NSValue class]]) {
            [static_cast<NSValue*>(value) getValue:data.data()];
        }

        [invocation setTarget:self];
        [invocation setSelector:sel];
        [invocation setArgument:data.data() atIndex:2];
        [invocation invoke];
        return true;
    }
    return false;
}

static bool trySetViaIvar(NSObject* self, const char* key, id value) {
    Class cls = object_getClass(self);
    auto curIvar = ivarForPropertyName(cls, key);
    if (!curIvar) {
        return false;
    }

    uint32_t offset = curIvar->offset;
    const char* argType = curIvar->type;

    void* destination = reinterpret_cast<char*>(self) + offset;
    switch (argType[0]) {
        case '@':
            [*reinterpret_cast<id*>(destination) release];
            woc::ValueTransformer<id>::store(value, destination);
            break;
        case '#':
            woc::ValueTransformer<Class>::store(value, destination);
            break;
        case 'c':
            woc::ValueTransformer<char>::store(value, destination);
            break;
        case 'i':
            woc::ValueTransformer<int>::store(value, destination);
            break;
        case 's':
            woc::ValueTransformer<short>::store(value, destination);
            break;
        case 'l':
            woc::ValueTransformer<long>::store(value, destination);
            break;
        case 'q':
            woc::ValueTransformer<long long>::store(value, destination);
            break;
        case 'C':
            woc::ValueTransformer<unsigned char>::store(value, destination);
            break;
        case 'I':
            woc::ValueTransformer<unsigned int>::store(value, destination);
            break;
        case 'S':
            woc::ValueTransformer<unsigned short>::store(value, destination);
            break;
        case 'L':
            woc::ValueTransformer<unsigned long>::store(value, destination);
            break;
        case 'Q':
            woc::ValueTransformer<unsigned long long>::store(value, destination);
            break;
        case 'f':
            woc::ValueTransformer<float>::store(value, destination);
            break;
        case 'd':
            woc::ValueTransformer<double>::store(value, destination);
            break;
        case 'B':
            woc::ValueTransformer<bool>::store(value, destination);
            break;
        case '*':
        case '^':
        case '?':
            // We cannot box/unbox arbitrary pointers or char*.
            return false;
        default:
            NSValue* nsv = static_cast<NSValue*>(value);
            if (getArgumentSize(argType) == getArgumentSize([nsv objCType])) {
                [nsv getValue:destination];
            } else {
                // If the argument types don't match in size, we just say
                // that this key can't be coded.
                return false;
            }
            break;
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
    if (trySetViaAccessor(self, rawKey, val)) {
        return;
    }

    if ([[self class] accessInstanceVariablesDirectly]) {
        BOOL shouldNotify = [[self class] automaticallyNotifiesObserversForKey:key];

        if (shouldNotify) {
            [self willChangeValueForKey:key];
        }

        if (trySetViaIvar(self, rawKey, val)) {
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
 @Notes These throw exceptions. That's what they're supposed to do.
*/
- (void)setValue:(id)value forUndefinedKey:(NSString*)key {
    [NSException raise:NSInvalidArgumentException format:@"Class %s is not KVC compliant for key %@.", class_getName([self class]), key];
}

/**
 @Status Stub
*/
- (Class)classForArchiver {
    UNIMPLEMENTED();
    return [self class];
}

/**
 @Status Interoperable
*/
- (Class)classForKeyedArchiver {
    return [self classForArchiver];
}

/**
 @Status Stub
*/
- (id)replacementObjectForArchiver:(id)a {
    UNIMPLEMENTED();
    return self;
}

/**
 @Status Interoperable
*/
- (id)replacementObjectForKeyedArchiver:(id)a {
    return [self replacementObjectForArchiver:a];
}

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
__declspec(dllexport) void NSObjForceinclude() {
}
