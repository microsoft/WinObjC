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
#import <Foundation/NSString.h>
#import <Foundation/NSMethodSignature.h>

#import <Starboard/String.h>
#import <StringHelpers.h>
#import <ErrorHandling.h>
#import <LoggingNative.h>
#import <StubReturn.h>

#import <mutex>

#import "ForFoundationOnly.h"
#import "CFFoundationInternal.h"
#import "NSInvocationInternal.h"

static void _NSObjCEnumerationMutation(id object) {
    [NSException raise:NSInternalInconsistencyException format:@"Collection <%s %p> mutated while being enumerated!", object_getClassName(object), object];
}

static BOOL _NSSelectorNotFoundIsNonFatal;
static const wchar_t* TAG = L"Objective-C";

@class NSZone;

@protocol _NSObjectInformal
- (id)copyWithZone:(NSZone*)zone;
- (id)mutableCopyWithZone:(NSZone*)zone;
@end

@implementation NSObject
/**
 @Status Interoperable
*/
+ (void)initialize {
    // does nothing (by design).
}

/**
 @Status Interoperable
*/
+ (id) new {
    return [[self alloc] init];
}

/**
 @Status Interoperable
*/
+ (id)alloc {
    return [self allocWithZone:nil];
}

/**
 @Status Interoperable
*/
+ (id)allocWithZone:(NSZone*)zone {
    return class_createInstance(self, 0);
}

/**
 @Status Interoperable
 @Notes Zones are not supported.
*/
- (NSZone*)zone {
    return nullptr;
}

/**
 @Status Interoperable
*/
- (id)init {
    return self;
}

/**
 @Status Interoperable
*/
- (void)finalize {
}

/**
 @Status Interoperable
*/
- (id)self {
    return self;
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
- (void)_ARCCompliantRetainRelease {
}

/**
 @Status Interoperable
*/
- (id)autorelease {
    [NSAutoreleasePool addObject:self];
    return self;
}

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
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
*/
- (NSUInteger)retainCount {
    // account for the implicit retain on object creation
    return *(((intptr_t*)self) - 1) + 1;
}

/**
 @Status Interoperable
*/
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
static id _NSWeakLoad(id obj) {
    if ([obj retainCount] <= 0) {
        return nil;
    }
    return obj;
}

/**
 @Status Interoperable
*/
- (Class) class {
    return object_getClass(self);
}

    /**
     @Status Interoperable
    */
    - (Class)superclass {
    return class_getSuperclass(object_getClass(self));
}

/**
 @Status Interoperable
*/
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

/**
 @Status Interoperable
*/
- (BOOL)isKindOfClass:(Class)classRef {
    return [object_getClass(self) isSubclassOfClass:classRef];
}

/**
 @Status Interoperable
*/
- (BOOL)isMemberOfClass:(Class)classRef {
    return object_getClass(self) == classRef;
}

/**
 @Status Interoperable
*/
+ (BOOL)conformsToProtocol:(Protocol*)protocol {
    return class_conformsToProtocol(self, protocol);
}

/**
 @Status Interoperable
*/
- (BOOL)conformsToProtocol:(Protocol*)protocol {
    return [object_getClass(self) conformsToProtocol:protocol];
}

/**
 @Status Interoperable
*/
- (id)performSelector:(SEL)selector {
    return ((id (*)(id, SEL))objc_msgSend)(self, selector);
}

/**
 @Status Interoperable
*/
- (id)performSelector:(SEL)selector withObject:(id)obj1 {
    return ((id (*)(id, SEL, id))objc_msgSend)(self, selector, obj1);
}

/**
 @Status Interoperable
*/
- (id)performSelector:(SEL)selector withObject:(id)obj1 withObject:(id)obj2 {
    return ((id (*)(id, SEL, id, id))objc_msgSend)(self, selector, obj1, obj2);
}

/**
 @Status Interoperable
*/
- (id)performSelector:(SEL)selector withObject:(id)obj1 withObject:(id)obj2 withObject:(id)obj3 {
    return ((id (*)(id, SEL, id, id, id))objc_msgSend)(self, selector, obj1, obj2, obj3);
}

/**
 @Status Interoperable
*/
+ (BOOL)instancesRespondToSelector:(SEL)selector {
    BOOL responds = class_respondsToSelector(self, selector);
    return responds || [self resolveInstanceMethod:selector];
}

/**
 @Status Interoperable
*/
+ (BOOL)respondsToSelector:(SEL)selector {
    BOOL responds = class_respondsToSelector(object_getClass(self), selector);
    return responds || [self resolveClassMethod:selector];
}

/**
 @Status Interoperable
*/
- (BOOL)respondsToSelector:(SEL)selector {
    return [object_getClass(self) instancesRespondToSelector:selector];
}

/**
 @Status Interoperable
*/
- (IMP)methodForSelector:(SEL)selector {
    return objc_msg_lookup(self, selector);
}

/**
 @Status Interoperable
*/
+ (NSMethodSignature*)methodSignatureForSelector:(SEL)selector {
    Class metaClass = object_getClass(self);
    Method method = class_getInstanceMethod(metaClass, selector);

    if (!method && [self resolveClassMethod:selector]) {
        method = class_getInstanceMethod(metaClass, selector);
    }

    if (!method) {
        TraceWarning(L"Objective-C", L"+[%hs %hs]: unrecognized selector in signature lookup.", class_getName(self), sel_getName(selector));
        return nil;
    }

    const char* methodTypes = method_getTypeEncoding(method);

    return [NSMethodSignature signatureWithObjCTypes:methodTypes];
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
    Method method = class_getInstanceMethod(self, selector);

    if (!method && [self resolveInstanceMethod:selector]) {
        method = class_getInstanceMethod(self, selector);
    }

    if (!method) {
        TraceWarning(L"Objective-C", L"-[%hs %hs]: unrecognized selector in signature lookup.", class_getName(self), sel_getName(selector));
        return nil;
    }

    const char* methodTypes = method_getTypeEncoding(method);

    return [NSMethodSignature signatureWithObjCTypes:methodTypes];
}

/**
 @Status Interoperable
*/
+ (IMP)instanceMethodForSelector:(SEL)selector {
    IMP ret = class_getMethodImplementation(self, selector);
    return ret;
}

// NOTE: long return value to allow nonfatal continuation to get a "valid" result (for non-fpret/non-stret calls)
static long _throwUnrecognizedSelectorException(id self, Class isa, SEL sel) {
    std::string reason;
    BOOL isMeta = class_isMetaClass(isa);
    if (isMeta) {
        reason = woc::string::format("+[%s %s]: unrecognized selector sent to class.", class_getName(isa), sel_getName(sel));
    } else {
        reason = woc::string::format("-[%s %s]: unrecognized selector sent to instance %p.", class_getName(isa), sel_getName(sel), self);
    }

    if (_NSSelectorNotFoundIsNonFatal) {
        TraceWarning(TAG, L"%hs", reason.c_str());
    } else {
        THROW_NS_HR_MSG(HRESULT_FROM_WIN32(ERROR_NOT_FOUND), "%hs", reason.c_str());
    }

    return 0;
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
*/
- (void)forwardInvocation:(NSInvocation*)invocation {
    [self doesNotRecognizeSelector:[invocation selector]];
}

/**
 @Status Interoperable
*/
+ (BOOL)resolveClassMethod:(SEL)name {
    return NO;
}

/**
 @Status Interoperable
*/
+ (BOOL)resolveInstanceMethod:(SEL)name {
    return NO;
}

/**
 @Status Interoperable
*/
- (id)forwardingTargetForSelector:(SEL)selector {
    return nil;
}

static id _NSForwardingDestination(id object, SEL selector) {
    Class cls = object_getClass(object);
    if (class_isMetaClass(cls) && class_respondsToSelector(cls, @selector(resolveClassMethod:)) && [object resolveClassMethod:selector]) {
        return object;
    }

    if (class_respondsToSelector(object_getClass(cls), @selector(resolveInstanceMethod:)) && [cls resolveInstanceMethod:selector]) {
        return object;
    }

    if (class_respondsToSelector(cls, @selector(forwardingTargetForSelector:))) {
        return [(NSObject*)object forwardingTargetForSelector:selector];
    }

    return nil;
}

static inline void _forwardThrowStret(void* structReturn, id object, SEL selector) {
    if (class_respondsToSelector(object_getClass(object), @selector(doesNotRecognizeSelector:))) {
        [object doesNotRecognizeSelector:selector];
        return;
    }
    _throwUnrecognizedSelectorException(object, object_getClass(object), selector);
}

static void _forwardThrow(id object, SEL selector) {
    _forwardThrowStret(nullptr, object, selector);
}

static const char* _typesFromSelector(SEL selector) {
    const char* types = sel_getType_np(selector);
    if (!types) {
        SEL typedSelector = nullptr;
        sel_copyTypedSelectors_np(sel_getName(selector), &typedSelector, 1);
        if (typedSelector) {
            types = sel_getType_np(typedSelector);
        }
    }
    return types;
}

static struct objc_slot _NSForwardSlot = { Nil, Nil, 0, 1, (IMP)_forwardThrow };
static struct objc_slot _NSForwardStretSlot = { Nil, Nil, 0, 1, (IMP)_forwardThrowStret };
static struct objc_slot _NSInvocationSlot = { Nil, Nil, 0, 1, (IMP)_NSInvocation_ForwardingBridgeNoStret };
static struct objc_slot _NSInvocationStretSlot = { Nil, Nil, 0, 1, (IMP)_NSInvocation_ForwardingBridge };
static struct objc_slot* _NSSlotForward(id object, SEL selector) {
    Class cls = object_getClass(object);
    const char* types = _typesFromSelector(selector);
    bool structReturn = false;

    if (!types) {
        TraceWarning(TAG,
                     L"%c[%hs %hs]: attempting to forward method of unknown type; preferring POD return.",
                     class_isMetaClass(cls) ? '+' : '-',
                     class_getName(cls),
                     sel_getName(selector));
    } else {
        structReturn = _NSInvocationTypeEncodingMandatesStructReturn(types);
    }

    if (class_respondsToSelector(cls, @selector(forwardInvocation:))) {
        if (class_respondsToSelector(cls, @selector(methodSignatureForSelector:))) {
            return structReturn ? &_NSInvocationStretSlot : &_NSInvocationSlot;
        } else {
            TraceWarning(TAG,
                         L"%hs responds to %cforwardInvocation but not %cmethodSignatureForSelector:. This will not end well.",
                         class_getName(cls),
                         class_isMetaClass(cls) ? '+' : '-',
                         class_isMetaClass(cls) ? '+' : '-');
        }
    }

    return structReturn ? &_NSForwardStretSlot : &_NSForwardSlot;
}

static IMP _NSIMPForward(id object, SEL selector) {
    // _NSSlotForward does the heavy lifting for forwarding.
    // _NSIMPForward is just a compatibility adapter for non-msgSend consumers.
    return _NSSlotForward(object, selector)->method;
}


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

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(id)other {
    return self == other;
}

/**
 @Status Interoperable
*/
- (unsigned int)hash {
    return reinterpret_cast<unsigned int>(self);
}

/**
 @Status Interoperable
*/
- (id)copy {
    return [(id<_NSObjectInformal>)self copyWithZone:nil];
}

/**
 @Status Interoperable
*/
- (id)mutableCopy {
    return [(id<_NSObjectInformal>)self mutableCopyWithZone:nil];
}

/*
 * As the NSObject class is the root class for all classes, it has to conform to the
 * NSObject protocol itself. This allows classes to be used in collections, "reference-counted",
 * copied, etc.
 */

/**
 @Status Interoperable
*/
+ (id)self {
    return (id)self;
}

/**
 @Status Interoperable
*/
+ (Class) class {
    return self;
}

    /**
     @Status Interoperable
    */
    + (Class)superclass {
    return class_getSuperclass(self);
}

/**
 @Status Interoperable
*/
+ (id)copyWithZone:(NSZone*)zone {
    return self;
}

/**
 @Status Interoperable
*/
+ (id)mutableCopyWithZone:(NSZone*)zone {
    return self;
}

/**
 @Status Interoperable
*/
+ (id)autorelease {
    return self;
}

/**
 @Status Interoperable
*/
+ (id)retain {
    return self;
}

/**
 @Status Interoperable
*/
+ (void)release {
}

/**
 @Status Interoperable
*/
+ (NSUInteger)retainCount {
    // This is a class, so it cannot be retained or released. As such, it has no realistic retain count.
    return UINT_MAX;
}

/**
 @Status Interoperable
*/
+ (void)dealloc {
}

/**
 @Status Interoperable
*/
+ (NSString*)description {
    return NSStringFromClass(self);
}

/**
 @Status Interoperable
*/
+ (void)load {
    class_setSuperclass(objc_getClass("_NSCFType"), self);

    objc_proxy_lookup = _NSForwardingDestination;
    __objc_msg_forward2 = _NSIMPForward;
    __objc_msg_forward3 = _NSSlotForward;
    _objc_weak_load = _NSWeakLoad;
    _objc_enumeration_mutation = _NSObjCEnumerationMutation;

#if defined(OBJC_APP_BRINGUP)
    _NSSelectorNotFoundIsNonFatal = YES;
#endif
}

/**
 @Status Interoperable
*/
+ (void)setVersion:(NSInteger)aVersion {
    class_setVersion(self, aVersion);
}

/**
 @Status Interoperable
*/
+ (NSInteger)version {
    return class_getVersion(self);
}

/**
 @Status Stub
 @Notes
*/
+ (void)cancelPreviousPerformRequestsWithTarget:(id)aTarget {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (void)cancelPreviousPerformRequestsWithTarget:(id)aTarget selector:(SEL)aSelector object:(id)anArgument {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isProxy {
    UNIMPLEMENTED();
    return StubReturn();
}

- (id)autoContentAccessingProxy {
    UNIMPLEMENTED();
    return StubReturn();
}

- (CFTypeID)_cfTypeID {
    return CFTypeGetTypeID();
}

@end

void WinObjC_SetMissingSelectorFatal(BOOL fatal) {
    _NSSelectorNotFoundIsNonFatal = !fatal;
}

#pragma region NSZombie Support
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-objc-isa-usage" // We are knowingly accessing ->isa directly.
__attribute__((objc_root_class)) @interface NSZombie {
    Class isa;
}
@end

static void _dealloc_zombify(id self, SEL _cmd); // forward declaration

static void _NSCFZombifyHook(id object) {
    _dealloc_zombify(object, nullptr);
}

@implementation NSZombie
+ (void)load {
    __CFZombifyNSObjectHook = _NSCFZombifyHook;
}

// This implementation is required by CF, but NSZombie is a root class and does not inherit
// NSObject's version.
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
/**
 @Status Interoperable
*/
- (void)doesNotRecognizeSelector: (SEL)selector {
    // NSZombie subclasses store the original class as a class variable. Retrieve it here.
    Class oldIsa = reinterpret_cast<Class*>(object_getIndexedIvars(isa))[0];
    THROW_NS_HR_MSG(HRESULT_FROM_WIN32(ERROR_INVALID_HANDLE),
                    "-[%hs %hs]: message sent to deallocated instance %p.",
                    class_getName(oldIsa),
                    sel_getName(selector),
                    self);
}
@end

static void
_dealloc_dispose(id self, SEL _cmd) {
    object_dispose(self);
}

static void _dealloc_zombify(id self, SEL _cmd) {
    static Class zombieClass = objc_getClass("NSZombie");
    static std::mutex s_zombieMutex;

    // For every zombified class, we allocate a subclass of NSZombie that stores the
    // original class pointer as a cvar. Zombie subclass creation is guarded by
    // s_zombieMutex to ensure that we don't leak allocated subclasses in case
    // we get here in multiple threads.
    std::string className = woc::string::format("_NSZombie_%s", class_getName(self->isa));
    Class zombieSubclass = Nil;
    if (!(zombieSubclass = objc_getClass(className.c_str()))) {
        std::lock_guard<std::mutex> lock(s_zombieMutex);
        if (!(zombieSubclass = objc_getClass(className.c_str()))) {
            zombieSubclass = objc_allocateClassPair(zombieClass, className.c_str(), sizeof(Class));
            // Store the original isa in the sizeof(Class) extra bytes allocated at the end of the class.
            reinterpret_cast<Class*>(object_getIndexedIvars(zombieSubclass))[0] = self->isa;
            objc_registerClassPair(zombieSubclass);
        }
    }
    self->isa = zombieSubclass;
}
#pragma clang diagnostic pop

void WinObjC_SetZombiesEnabled(BOOL enabled) {
    // We do these acrobatics here to avoid adding a branch and overhead to -dealloc.
    // By switching out the implementation at runtime, we can keep the codepath for dealloc itself linear.
    IMP targetDeallocIMP = enabled ? (IMP)_dealloc_zombify : (IMP)_dealloc_dispose;

    Method dealloc = class_getInstanceMethod([NSObject class], @selector(dealloc));
    if (dealloc) {
        method_setImplementation(dealloc, targetDeallocIMP);
    }

    if (enabled) {
        _CFEnableZombies();
    } else {
        _CFDisableZombies();
    }
}
#pragma endregion
