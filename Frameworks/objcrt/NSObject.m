#include <stdio.h>
#include <stdlib.h>
#include "runtime.h"

@class NSZone;
@class NSAutoreleasePool;

@interface NSObject {
@public
    WinRT_isa isa;
}
@end

#include "NSObjectInternal.h"

@implementation NSObject
- (id)init {
    return self;
}

+ (id) new {
    return [[self alloc] init];
}

+ (id) class {
    return self;
}

    - (id) class {
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

        curClass = curClass->superclass;
    }

    return NO;
}

- (BOOL)isMemberOfClass:(Class)classRef {
    return object_getClass(self) == classRef;
}

- (BOOL)isKindOfClass:(Class)classRef {
    Class curClass = object_getClass(self);

    while (curClass != nil) {
        if (curClass == classRef) {
            return YES;
        }

        curClass = class_getSuperclass(curClass);
    }

    return NO;
}

- (BOOL)respondsToSelector:(SEL)selector {
    return class_respondsToSelector(object_getClass(self), selector);
}

+ (BOOL)instancesRespondToSelector:(SEL)selector {
    return class_respondsToSelector(self, selector);
}

+ (void)_raiseSelectorNotFoundError:(SEL)selector format:(const char*)format, ... {
    abort();
}

- (id)performSelector:(SEL)selector {
    id (*imp)(id, SEL) = (id (*)(id, SEL))[self methodForSelector:selector];
    if (imp == NULL) {
        [NSObject _raiseSelectorNotFoundError:selector
                                       format:"Unable to find selector %s on class %s (object 0x%x)",
                                              sel_getName(selector),
                                              object_getClassName(self),
                                              self];
    }

    return imp(self, selector);
}

- (id)performSelector:(SEL)selector withObject:(id)obj1 {
    id (*imp)(id, SEL, id) = (id (*)(id, SEL, id))[self methodForSelector:selector];

    if (imp == NULL) {
        [NSObject _raiseSelectorNotFoundError:selector
                                       format:"Unable to find selector %s on class %s (object 0x%x withObject 0x%x)",
                                              sel_getName(selector),
                                              object_getClassName(self),
                                              self,
                                              obj1];
    }

    return imp(self, selector, obj1);
}

- (id)performSelector:(SEL)selector withObject:(id)obj1 withObject:(id)obj2 {
    id (*imp)(id, SEL, id, id) = (id (*)(id, SEL, id, id))[self methodForSelector:selector];

    if (imp == NULL) {
        [NSObject _raiseSelectorNotFoundError:selector
                                       format:"Unable to find selector %s on class %s (object 0x%x withObject 0x%0x 0x%x)",
                                              sel_getName(selector),
                                              object_getClassName(self),
                                              self,
                                              obj1,
                                              obj2];
    }

    return imp(self, selector, obj1, obj2);
}

- (id)performSelector:(SEL)selector withObject:(id)obj1 withObject:(id)obj2 withObject:(id)obj3 {
    id (*imp)(id, SEL, id, id, id) = (id (*)(id, SEL, id, id, id))[self methodForSelector:selector];

    if (imp == NULL) {
        [NSObject _raiseSelectorNotFoundError:selector
                                       format:"Unable to find selector %s on class %s (object 0x%x withObject 0x%0x 0x%x 0x%x)",
                                              sel_getName(selector),
                                              object_getClassName(self),
                                              self,
                                              obj1,
                                              obj2,
                                              obj3];
    }

    return imp(self, selector, obj1, obj2, obj3);
}

- (IMP)methodForSelector:(SEL)selector {
    IMP ret = class_getMethodImplementation(object_getClass(self), selector);
    if (!ret)
        printf("Failed to lookup SEL(class %s): %s\n", sel_getName(selector), object_getClassName(self));
    return ret;
}

+ (IMP)instanceMethodForSelector:(SEL)selector {
    IMP ret = class_getMethodImplementation(self, selector);
    if (!ret)
        printf("Failed to lookup SEL(class %s): %s\n", sel_getName(selector), object_getClassName(self));
    return ret;
}

/**
 @Status Stub
*/
+ (void)cancelPreviousPerformRequestsWithTarget:(id)aTarget {
    // TODO: implement
    printf("cancelPreviousPerformRequestsWithTarget has not been implemented\n");
}

/**
 @Status Stub
*/
+ (void)cancelPreviousPerformRequestsWithTarget:(id)aTarget selector:(SEL)aSelector object:(id)anArgument {
    // TODO: implement
    printf("cancelPreviousPerformRequestsWithTarget:selector:object has not been implemented\n");
}

- (instancetype)self {
    return self;
}

+ (instancetype)self {
    return self;
}

+ (id)allocWithZone:(NSZone*)zone {
    id ret = objc_allocateObject(self, 0);

    return ret;
}

+ (id)alloc {
    return [self allocWithZone:nil];
}

+ (void)dealloc{}

    + (id)retain {
    return self;
}

+ (void)release{}

    - (void)dealloc {
    objc_deallocateObject(self);
}

- (id)autorelease {
    [NSAutoreleasePool addObject:self];
    return self;
}

- (id)retain {
    return (id)objc_retain_ref(self);
}

- (void)release {
    objc_release_ref(self);
}

- (id)mutableCopy {
    return [self mutableCopyWithZone:nil];
}

- (id)copy {
    return [self copyWithZone:nil];
}

- (unsigned int)hash {
    return (unsigned int)self;
}

+ (id)copyWithZone:(NSZone*)zone {
    return self;
}

+ (BOOL)conformsToProtocol:(Protocol*)protocol {
    Class c;

    for (c = self; c != Nil; c = class_getSuperclass(c))
        if (class_conformsToProtocol(c, protocol))
            return YES;

    return NO;
}

- (BOOL)conformsToProtocol:(Protocol*)protocol {
    return [object_getClass(self) conformsToProtocol:protocol];
}
@end
