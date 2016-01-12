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

#include <stdio.h>
#include <stdlib.h>

#import <objc/runtime.h>
#import <objc/objc-arc.h>
#import <objc/blocks_runtime.h>
#import <objc/slot.h>
#import <objc/hooks.h>

#import <Foundation/NSObject.h>
#import <Foundation/NSAutoreleasePool.h>
#import <Foundation/NSException.h>

@class NSZone;
@class NSAutoreleasePool;

@protocol _NSObjectInformal
- (id)copyWithZone:(NSZone*)zone;
- (id)mutableCopyWithZone:(NSZone*)zone;
@end

@implementation NSObject
- (id)init {
    return self;
}

+ (id) new {
    return [[self alloc] init];
}

+ (Class) class {
    return self;
}

- (Class) class {
    return object_getClass(self);
}

    - (BOOL)isEqual : (id)other {
    return self == other;
}

+ (Class)superclass {
    return class_getSuperclass(self);
}

+ (BOOL)isSubclassOfClass:(Class)classRef {
    Class curClass = self;

    while (curClass != nil) {
        if (curClass == classRef) {
            return YES;
        }

        curClass = class_getSuperclass(curClass);
    }

    return NO;
}

- (BOOL)isMemberOfClass:(Class)classRef {
    return object_getClass(self) == classRef;
}

- (BOOL)isKindOfClass:(Class)classRef {
    return [object_getClass(self) isSubclassOfClass:classRef];
}

- (BOOL)respondsToSelector:(SEL)selector {
    return class_respondsToSelector(object_getClass(self), selector);
}

+ (BOOL)instancesRespondToSelector:(SEL)selector {
    return class_respondsToSelector(self, selector);
}

- (id)performSelector:(SEL)selector {
    id (*imp)(id, SEL) = (id (*)(id, SEL))[self methodForSelector:selector];
    if (imp == NULL) {
        [self doesNotRecognizeSelector:selector];
    }

    return imp(self, selector);
}

- (id)performSelector:(SEL)selector withObject:(id)obj1 {
    id (*imp)(id, SEL, id) = (id (*)(id, SEL, id))[self methodForSelector:selector];

    if (imp == NULL) {
        [self doesNotRecognizeSelector:selector];
    }

    return imp(self, selector, obj1);
}

- (id)performSelector:(SEL)selector withObject:(id)obj1 withObject:(id)obj2 {
    id (*imp)(id, SEL, id, id) = (id (*)(id, SEL, id, id))[self methodForSelector:selector];

    if (imp == NULL) {
        [self doesNotRecognizeSelector:selector];
    }

    return imp(self, selector, obj1, obj2);
}

- (id)performSelector:(SEL)selector withObject:(id)obj1 withObject:(id)obj2 withObject:(id)obj3 {
    id (*imp)(id, SEL, id, id, id) = (id (*)(id, SEL, id, id, id))[self methodForSelector:selector];

    if (imp == NULL) {
        [self doesNotRecognizeSelector:selector];
    }

    return imp(self, selector, obj1, obj2, obj3);
}

- (IMP)methodForSelector:(SEL)selector {
    IMP ret = class_getMethodImplementation(object_getClass(self), selector);
    return ret;
}

+ (IMP)instanceMethodForSelector:(SEL)selector {
    IMP ret = class_getMethodImplementation(self, selector);
    return ret;
}

- (instancetype)self {
    return self;
}

+ (instancetype)self {
    return (NSObject*)self;
}

+ (id)allocWithZone:(NSZone*)zone {
    return class_createInstance(self, 0);
}

+ (id)alloc {
    return [self allocWithZone:nil];
}

+ (id)copyWithZone:(NSZone*)zone {
    return self;
}

+ (id)autorelease {
    return self;
}

+ (id)retain {
    return self;
}

+ (void)release {
}

+ (NSUInteger)retainCount {
    return UINT_MAX;
}

+ (void)dealloc {
}

/**
 *  _ARCCompliantRetainRelease signals to the runtime (libobjc2) that we are ARC-compliant.
 *
 *  When an ARC-compliant class is used with ARC code, it falls into the libobjc2 fast path:
 *  the runtime automatically increments the refcount without consulting the object, and
 *  calls dealloc when it crosses below 0.
 *
 *  The fast path is only engaged if retain, autorelease, and release are implemented at
 *  the same inheritance level as _ARCCompliantRetainRelease. Subclasses overriding this behaviour
 *  opt out of the fast path, and must implement both retain and release.
 *
 *  To actually be ARC compliant, we need to store our refcount sizeof(intptr_t) bytes before
 *  self->isa, and mimic the runtime's behaviour for direct invocations of retain/release.
 */
- (void)_ARCCompliantRetainRelease { }

- (id)autorelease {
    [NSAutoreleasePool addObject:self];
    return self;
}

- (id)retain {
    intptr_t* refCount = ((intptr_t*)self) - 1;
    // Note: this should be an atomic read, so that a sufficiently clever
    // compiler doesn't notice that there's no happens-before relationship
    // here.
    if (*refCount >= 0) {
        __sync_add_and_fetch(refCount, 1);
    }
    return self;
}

- (void)release {
    intptr_t* refCount = ((intptr_t*)self) - 1;
    // We allow refcounts to run into the negative, but should only
    // deallocate once.
    if (__sync_sub_and_fetch(refCount, 1) == -1) {
        objc_delete_weak_refs(self);
        [self dealloc];
    }
}

- (NSUInteger)retainCount {
    // account for the implicit retain on object creation
    return *(((intptr_t*)self) - 1) + 1;
}

- (void)dealloc {
    object_dispose(self);
}

/**
 * The ObjC weak load hook is called in a very narrow set of circumstances:
 * - The object has been de-refcounted.
 * - The object has not yet been deallocated (as deallocation clears all weak refs)
 * - A weak reference load is attempted.
 *
 * The object is still valid at this point, but as it has decreased below 0 total refs,
 * it must not be loaded into a weak pointer.
 */
id _NSWeakLoad(id obj) {
    if ([obj retainCount] <= 0) {
        return nil;
    }
    return obj;
}

- (id)mutableCopy {
    return [(id<_NSObjectInformal>)self mutableCopyWithZone:nil];
}

- (id)copy {
    return [(id<_NSObjectInformal>)self copyWithZone:nil];
}

- (unsigned int)hash {
    return (unsigned int)self;
}

+ (BOOL)conformsToProtocol:(Protocol*)protocol {
    return class_conformsToProtocol(self, protocol);
}

- (BOOL)conformsToProtocol:(Protocol*)protocol {
    return [object_getClass(self) conformsToProtocol:protocol];
}

static id _NSForwardingDestination(id object, SEL selector) {
    if (class_respondsToSelector(object_getClass(object), @selector(forwardingTargetForSelector:))) {
        return [(NSObject*)object forwardingTargetForSelector:selector];
    }
    return nil;
}

- (void)doesNotRecognizeSelector:(SEL)selector {
    Class cls = object_getClass(self);
    _throwUnrecognizedSelectorException(self, cls, selector);
}

static void _throwUnrecognizedSelectorException(id self, Class isa, SEL sel) {
    BOOL isMeta = class_isMetaClass(isa);
    if (isMeta) {
        [NSException raiseWithLogging:NSInvalidArgumentException
                               format:@"+[%s %s]: unrecognized selector sent to class.",
                               class_getName(isa),
                               sel_getName(sel)];
    } else {
        [NSException raiseWithLogging:NSInvalidArgumentException
                               format:@"-[%s %s]: unrecognized selector sent to instance %p.",
                               class_getName(isa),
                               sel_getName(sel),
                               self];
    }
}

void _forwardThrow(id object, SEL selector) {
    [object doesNotRecognizeSelector:selector];
}

IMP _NSIMPForward(id object, SEL selector) {
    return (IMP)&_forwardThrow;
}

static struct objc_slot _NSForwardSlot = { Nil, Nil, 0, 1, (IMP)_forwardThrow };
static struct objc_slot* _NSSlotForward(id object, SEL selector) {
    return &_NSForwardSlot;
}

+ (void)load {
    objc_proxy_lookup = _NSForwardingDestination;
    __objc_msg_forward2 = _NSIMPForward;
    __objc_msg_forward3 = _NSSlotForward;
    _objc_weak_load = _NSWeakLoad;
}
@end