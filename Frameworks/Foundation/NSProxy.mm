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

#import <Foundation/NSProxy.h>

#import <Foundation/NSAutoreleasePool.h>
#import <Foundation/NSException.h>
#import <Foundation/NSInvocation.h>
#import <Foundation/NSString.h>

#import <Starboard/String.h>
#import <ErrorHandling.h>

#import <objc/objc-arc.h>
#import <string>

#import "NSObjectInternal.h"

#define RAISE_NSPROXY_ABSTRACT_FUNCTION_EXCEPTION \
    [NSException raise:NSInvalidArgumentException \
                format:@"%hs was called directly. It must be overridden in a subclass.", __PRETTY_FUNCTION__]

@implementation NSProxy

#pragma region NSProxy member functions

/**
 @Status Interoperable
 @Notes
*/
+ (id)alloc {
    return [self allocWithZone:nil];
}

/**
 @Status Interoperable
 @Notes
*/
+ (id)allocWithZone:(NSZone*)zone {
    return class_createInstance(self, 0);
}

/**
 @Status Interoperable
 @Notes
*/
- (void)dealloc {
    object_dispose(self);
}

/**
 @Status Interoperable
 @Notes
*/
- (void)finalize {
}

/**
 @Status Interoperable
 @Notes  Must be overridden in a subclass
*/
- (void)forwardInvocation:(NSInvocation*)anInvocation {
    RAISE_NSPROXY_ABSTRACT_FUNCTION_EXCEPTION;
}

/**
 @Status Interoperable
 @Notes  Must be overridden in a subclass
*/
- (NSMethodSignature*)methodSignatureForSelector:(SEL)aSelector {
    RAISE_NSPROXY_ABSTRACT_FUNCTION_EXCEPTION;
    return nil;
}

/**
 @Status Interoperable
 @Notes
*/
+ (BOOL)respondsToSelector:(SEL)aSelector {
    return class_respondsToSelector(self, aSelector);
}

// clang format doesn't play well with 'class' here, so turn it off
// clang-format off

/**
 @Status Interoperable
 @Notes
*/
+ (Class)class {
    return self;
}


/**
 @Status Interoperable
*/
+ (Class)superclass {
    return class_getSuperclass(self);
}

// clang-format on

/**
 @Status Interoperable
*/

- (NSString*)description {
    return [NSString stringWithFormat:@"<%@: %p>", NSStringFromClass([self class]), self];
}

/**
 @Status Interoperable
*/
- (NSString*)debugDescription {
    return [self description];
}

#pragma endregion

#pragma region NSObject protocol functions

// clang format doesn't play well with 'class' here, so turn it off
// clang-format off

/**
 @Status Interoperable
 @Notes
*/
- (Class)class {
    return object_getClass(self);
}

/**
 @Status Interoperable
 @Notes
*/
- (Class)superclass {
    return class_getSuperclass([self class]);
}

// clang-format on

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)isEqual:(id)anObject {
    return self == anObject;
}

/**
 @Status Interoperable
*/
- (NSUInteger)hash {
    return reinterpret_cast<NSUInteger>(self);
}

/**
 @Status Interoperable
 @Notes
*/
- (instancetype)self {
    return self;
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)isKindOfClass:(Class)aClass {
    Class forwardClass = static_cast<Class>([self performSelector:@selector(class)]);
    return [forwardClass isSubclassOfClass:aClass];
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)isMemberOfClass:(Class)aClass {
    Class forwardClass = static_cast<Class>([self performSelector:@selector(class)]);
    return aClass == forwardClass;
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)respondsToSelector:(SEL)aSelector {
    return [self methodSignatureForSelector:aSelector] != nil;
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)conformsToProtocol:(Protocol*)aProtocol {
    Class forwardClass = static_cast<Class>([self performSelector:@selector(class)]);
    return class_conformsToProtocol(forwardClass, aProtocol);
}

/**
 @Status Interoperable
*/
- (void)doesNotRecognizeSelector:(SEL)selector {
    Class cls = object_getClass(self);
    _throwUnrecognizedSelectorException(self, cls, selector);
}

/**
 @Status Interoperable
 @Notes
*/
- (id)performSelector:(SEL)aSelector {
    NSMethodSignature* methodSignature = [self methodSignatureForSelector:aSelector];
    if (!methodSignature) {
        [self doesNotRecognizeSelector:aSelector];
    }

    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
    invocation.selector = aSelector;
    [self forwardInvocation:invocation];

    id ret;
    [invocation getReturnValue:&ret];
    return ret;
}

/**
 @Status Interoperable
 @Notes
*/
- (id)performSelector:(SEL)aSelector withObject:(id)anObject {
    NSMethodSignature* methodSignature = [self methodSignatureForSelector:aSelector];
    if (!methodSignature) {
        [self doesNotRecognizeSelector:aSelector];
    }

    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
    invocation.selector = aSelector;
    [invocation setArgument:anObject atIndex:2];
    [self forwardInvocation:invocation];

    id ret;
    [invocation getReturnValue:&ret];
    return ret;
}

/**
 @Status Interoperable
 @Notes
*/
- (id)performSelector:(SEL)aSelector withObject:(id)anObject withObject:(id)anotherObject {
    NSMethodSignature* methodSignature = [self methodSignatureForSelector:aSelector];
    if (!methodSignature) {
        [self doesNotRecognizeSelector:aSelector];
    }

    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
    invocation.selector = aSelector;
    [invocation setArgument:anObject atIndex:2];
    [invocation setArgument:anotherObject atIndex:3];
    [self forwardInvocation:invocation];

    id ret;
    [invocation getReturnValue:&ret];
    return ret;
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)isProxy {
    return YES;
}

/**
 @Status Interoperable
 @Notes
*/
- (instancetype)retain {
    intptr_t* refCount = ((intptr_t*)self) - 1;
    // Note: this should be an atomic read, so that a sufficiently clever
    // compiler doesn't notice that there's no happens-before relationship
    // here.
    if (*refCount >= 0) {
        __sync_add_and_fetch(refCount, 1);
    }
    return self;
}

/**
 @Status Interoperable
 @Notes
*/
- (oneway void)release {
    intptr_t* refCount = ((intptr_t*)self) - 1;
    // We allow refcounts to run into the negative, but should only
    // deallocate once.
    if (__sync_sub_and_fetch(refCount, 1) == -1) {
        objc_delete_weak_refs(self);
        [self dealloc];
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (instancetype)autorelease {
    [NSAutoreleasePool addObject:self];
    return self;
}

/**
 @Status Interoperable
 @Notes
*/
- (NSUInteger)retainCount {
    // account for the implicit retain on object creation
    return *(((intptr_t*)self) - 1) + 1;
}

/**
 @Status Interoperable
 @Notes Zones are not supported.
*/
- (NSZone*)zone {
    return nil;
}

#pragma endregion

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
- (void)_ARCCompliantRetainRelease {
}

@end