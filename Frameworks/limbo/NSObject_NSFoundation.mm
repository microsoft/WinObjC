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

#include <stdio.h>
#include <stdlib.h>
#import "Foundation/Foundation.h"
#import "NSObjectInternal.h"
#include "../objcrt/runtime.h"

#include "CoreGraphics/CGAffineTransform.h"
#include "QuartzCore/CATransform3D.h"

@implementation NSObject (Foundation)
static bool tryGetAccessor(NSObject* self, NSString* key, id* ret) {
    SEL sel = sel_registerName([key UTF8String]);
    IMP foo = class_getMethodImplementation(object_getClass(self), sel);
    if (!foo) {
        return false;
    }

    NSMethodSignature* sig = [self methodSignatureForSelector:sel];
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:sig];

    [invocation setTarget:self];
    [invocation setSelector:sel];
    [invocation invoke];

    const char* returnType = [sig methodReturnType];

    if (strcmp(returnType, "@") == 0) {
        [invocation getReturnValue:&ret];
        return true;
    } else if (strcmp(returnType, "f") == 0) {
        float retVal;
        [invocation getReturnValue:&retVal];

        *ret = [NSNumber numberWithFloat:retVal];
        return true;
    } else if (strcmp(returnType, "d") == 0) {
        double retVal = 0.0f;
        [invocation getReturnValue:&retVal];

        *ret = [NSNumber numberWithDouble:retVal];
        return true;
    } else if (strncmp(returnType, "{CATransform3D" /*"=ffffffffffffffff}"*/, 10) == 0) {
        CATransform3D transform;
        [invocation getReturnValue:&transform];

        *ret = [NSValue valueWithCATransform3DPtr:&transform];
        return true;
    } else if (strncmp(returnType, "{CGPoint=", 9) == 0) {
        CGPoint point;
        [invocation getReturnValue:&point];

        CGPoint p = { point.x, point.y };
        *ret = [NSValue valueWithCGPoint:p];
        return true;
    } else if (strncmp(returnType, "{CGRect=", 8) == 0) {
        CGRect rect;
        [invocation getReturnValue:&rect];

        *ret = [NSValue valueWithCGRect:rect];
        return true;
    } else if (strncmp(returnType, "{CGSize=", 8) == 0) {
        CGSize rect;
        [invocation getReturnValue:&rect];

        *ret = [NSValue valueWithCGSize:rect];
        return true;
    } else if (strcmp(returnType, "i") == 0 || strcmp(returnType, "c") == 0 || strcmp(returnType, "I") == 0) {
        int retVal = 0;
        [invocation getReturnValue:&retVal];

        *ret = [NSNumber numberWithInt:retVal];
        return true;
    } else {
        printf("Unknown return type on %s, %s\n", [key UTF8String], returnType);
        assert(0);
    }

    return false;
}

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
        if (strcmp(curPath, "@count") == 0) {
            ret = [NSNumber numberWithInt:[ret count]];
            break;
        }

        ret = [ret valueForKey:[NSString stringWithCString:curPath]];

        curPath = strtok_s(NULL, ".", &save);
    }

    free(dup);

    return ret;
}

- (id)valueForKey:(NSString*)key {
    id ret = nil;
    if (!tryGetAccessor(self, key, &ret)) {
        ret = [self valueForUndefinedKey:key];
    }

    if (!ret)
        printf("Failed to find getter %s::%s\n", object_getClassName(self), [key UTF8String]);

    return ret;
}

static bool setDirectProperty(id var, const char* propName, id newVal) {
    Class cls = object_getClass(var);

    while (cls != NULL) {
        struct objc_ivar_list* list = (struct objc_ivar_list*)cls->ivars;

        char propName2[255];
        sprintf(propName2, "_%s", propName);

        if (list) {
            for (unsigned int i = 0; i < list->count; i++) {
                struct objc_ivar* curIvar = &list->ivars[i];
                if (strcmp(curIvar->name, propName) == 0 || strcmp(curIvar->name, propName2) == 0) {
                    uint32_t offset = curIvar->offset;
                    char* argType = (char*)curIvar->type;

                    if (argType[0] == '@') {
                        uint32_t oldVal = *((uint32_t*)((char*)var + offset));

                        *((id*)((char*)var + offset)) = newVal;
                        [newVal retain];
                        if (oldVal)
                            [oldVal release];
                    } else if (strcmp(argType, "i") == 0) {
                        int param;

                        param = [(NSNumber*)newVal intValue];
                        *((uint32_t*)((char*)var + offset)) = param;
                    } else if (strcmp(argType, "c") == 0) {
                        int param;

                        param = [(NSNumber*)newVal intValue];
                        *((char*)((char*)var + offset)) = param & 0xFF;
                    } else {
                        assert(0);
                    }
                    printf("Setting property %s@%d to 0x%08x\n", propName, offset, newVal);

                    return true;
                }
            }

            // assert(0);
        }

        cls = cls->superclass;
    }

    printf("Object %s has no ivar %s\n", class_getName(object_getClass(var)), propName);

    return false;
}

- (void)setValue:(id)val forKey:(NSString*)key {
    const char* pKeyName = [key UTF8String];

    char keyName[255];
    char szAccessorName[255];

    strcpy(keyName, pKeyName);

    //  Try set<Key>
    keyName[0] = toupper(keyName[0]);
    sprintf(szAccessorName, "set%s:", keyName);
    /*
    if ( trySetAccessor(self, szAccessorName, val) ) {
    return self;
    }
    */

    SEL sel = sel_registerName(szAccessorName);
    IMP foo = class_getMethodImplementation(object_getClass(self), sel);
    if (!foo) {
        if (!setDirectProperty(self, pKeyName, val)) {
            printf("Failed to find setter %s::%s\n", object_getClassName(self), pKeyName);
        }
        return;
    }

    foo(self, sel, val);
}

- (Class)classForArchiver {
    return [self class];
}

- (Class)classForKeyedArchiver {
    return [self classForArchiver];
}

- (id)replacementObjectForArchiver:(id)a {
    return self;
}

- (id)replacementObjectForKeyedArchiver:(id)a {
    return [self replacementObjectForArchiver:a];
}

- (void)performSelectorOnMainThread:(SEL)selector withObject:(id)obj1 waitUntilDone:(BOOL)wait {
    id modes = [[NSArray alloc] initWithObject:@"kCFRunLoopDefaultMode"];
    [self performSelectorOnMainThread:selector withObject:obj1 waitUntilDone:wait modes:modes];
    selector, [modes release];
}

- (void)performSelectorOnMainThread:(SEL)selector withObject:(id)obj waitUntilDone:(BOOL)wait modes:(NSArray*)modes {
    [self performSelector:selector onThread:[NSThread mainThread] withObject:obj waitUntilDone:wait modes:modes];
}

- (void)performSelectorInBackground:(SEL)selector withObject:(id)obj {
    [NSThread detachNewThreadSelector:selector toTarget:self withObject:obj];
}

+ (void)performSelectorInBackground:(SEL)selector withObject:(id)obj {
    [NSThread detachNewThreadSelector:selector toTarget:self withObject:obj];
}

- (void)willChangeValueForKey:(NSString*)key {
}

- (void)didChangeValueForKey:(NSString*)key {
}

- (void)_performSelectorAndSignal:(NSArray*)args {
    NSConditionLock* waitingLock = args[0];
    SEL selector = NSSelectorFromString(args[1]);
    id object = (id)[args[2] pointerValue];

    [waitingLock lockWhenCondition:0];

    [self performSelector:selector withObject:object];

    [waitingLock unlockWithCondition:1];
    [args release];
}

- (void)performSelector:(SEL)selector
               onThread:(NSThread*)thread
             withObject:(id)obj
          waitUntilDone:(BOOL)waitUntilDone
                  modes:(id)modes {
    NSRunLoop* runloop = [thread _runLoop];

    if (waitUntilDone) {
        if (thread == [NSThread currentThread]) {
            [self performSelector:selector withObject:obj];
        } else {
            if (!runloop) {
                [NSException
                     raise:NSInvalidArgumentException
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
            [NSException
                 raise:NSInvalidArgumentException
                format:@"Can't perform selector %2: Thread %@ has no runloop", NSStringFromSelector(_cmd), thread];
        }

        [runloop performSelector:selector target:self argument:obj order:0 modes:modes];
    }
}

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

+ (void)object:(id)object
    performSelector:(SEL)selector
         withObject:(id)argument
         afterDelay:(double)delay
            inModes:(NSArray*)modes {
    NSDelayedPerform* delayed = [NSDelayedPerform delayedPerformWithObject:object selector:selector argument:argument];
    NSTimer* timer = [NSTimer timerWithTimeInterval:delay
                                             target:[NSObject class]
                                           selector:@selector(_delayedPerform:)
                                           userInfo:delayed
                                            repeats:NO];
    int i, count = [modes count];

    for (i = 0; i < count; i++) {
        [[NSRunLoop currentRunLoop] addTimer:timer forMode:[modes objectAtIndex:i]];
    }
}

- (void)performSelector:(SEL)selector withObject:(id)obj1 afterDelay:(double)delay {
    [[self class] object:self
         performSelector:selector
              withObject:obj1
              afterDelay:delay
                 inModes:[NSArray arrayWithObject:@"kCFRunLoopDefaultMode"]];
}

- (NSMethodSignature*)methodSignatureForSelector:(SEL)selector {
    return [[self class] instanceMethodSignatureForSelector:selector];
}

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

- (void)addObserver:(NSObject*)anObserver
         forKeyPath:(NSString*)keyPath
            options:(NSKeyValueObservingOptions)options
            context:(void*)context {
}

- (void)removeObserver:(NSObject*)anObserver forKeyPath:(NSString*)keyPath {
}

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
