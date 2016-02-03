/* Copyright (c) 2006-2007 Christopher J. W. Lloyd
   Copyright (c) 2015 Microsoft Corporation. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <Foundation/NSObjCRuntime.h>
#import <Foundation/NSZone.h>

@class NSCoder, NSInvocation, NSMethodSignature, NSString, NSArray, NSThread, NSKeyedArchiver, NSArchiver, NSTimer;

@protocol NSObject

- (Class) class;
@property (readonly) Class superclass;
- (BOOL)isEqual:(id)anObject;
@property (readonly) NSUInteger hash;
- (instancetype)self;
- (BOOL)isKindOfClass:(Class)aClass;
- (BOOL)isMemberOfClass:(Class)aClass;
- (BOOL)respondsToSelector:(SEL)aSelector;
- (BOOL)conformsToProtocol:(Protocol*)aProtocol;
@property (readonly, copy) NSString* description;
@property (readonly, copy) NSString* debugDescription;
- (id)performSelector:(SEL)aSelector;
- (id)performSelector:(SEL)aSelector withObject:(id)anObject;
- (id)performSelector:(SEL)aSelector withObject:(id)anObject withObject:(id)anotherObject;
- (BOOL)isProxy STUB_METHOD;
- (instancetype)retain;
- (oneway void)release;
- (instancetype)autorelease;
- (NSUInteger)retainCount;
- (NSZone*)zone;

@end

FOUNDATION_EXPORT_CLASS
__attribute__((objc_root_class)) @interface NSObject<NSObject> {
@public
    Class isa;
}

+ (void)initialize STUB_METHOD;
+ (void)load;
+ (instancetype)alloc;
+ (instancetype)allocWithZone:(NSZone*)zone;
- (instancetype)init;
- (id)copy;
+ (id)copyWithZone:(NSZone*)zone;
- (id)mutableCopy;
+ (id)mutableCopyWithZone:(NSZone*)zone;
- (void)dealloc;
+ (instancetype) new;
+ (Class) class;
+ (Class)superclass;
+ (BOOL)isSubclassOfClass:(Class)aClass;
+ (BOOL)instancesRespondToSelector:(SEL)aSelector;
+ (BOOL)conformsToProtocol:(Protocol*)aProtocol;
- (IMP)methodForSelector:(SEL)aSelector;
+ (IMP)instanceMethodForSelector:(SEL)aSelector;
+ (NSMethodSignature*)instanceMethodSignatureForSelector:(SEL)selector STUB_METHOD;
- (NSMethodSignature*)methodSignatureForSelector:(SEL)selector STUB_METHOD;
+ (NSString*)description;
@property (readonly, copy) NSString* description;
@property (readonly, retain) id autoContentAccessingProxy STUB_PROPERTY;
+ (void)cancelPreviousPerformRequestsWithTarget:(id)aTarget STUB_METHOD;
+ (void)cancelPreviousPerformRequestsWithTarget:(id)aTarget selector:(SEL)aSelector object:(id)anArgument STUB_METHOD;
- (id)forwardingTargetForSelector:(SEL)aSelector;
- (void)forwardInvocation:(NSInvocation*)invocation STUB_METHOD;
+ (BOOL)resolveClassMethod:(SEL)selector STUB_METHOD;
+ (BOOL)resolveInstanceMethod:(SEL)selector STUB_METHOD;
- (void)doesNotRecognizeSelector:(SEL)aSelector;
+ (NSInteger)version STUB_METHOD;
+ (void)setVersion:(NSInteger)version STUB_METHOD;
- (void)finalize;

@end

// clang-format off
@interface NSObject (NSCoding)
- (Class) classForCoder; // really should be a property but *bad* things happen if an ivar is produced.
- (id)replacementObjectForCoder:(NSCoder*)coder;
- (id)awakeAfterUsingCoder:(NSCoder*)coder;
@end

@interface NSObject (NSArchiver)
- (Class)classForArchiver;
- (id)replacementObjectForArchiver:(NSArchiver*)archiver;
@end

@interface NSObject (NSKeyedArchiver)
- (Class)classForKeyedArchiver;
+ (Class)classForKeyedUnarchiver;
+ (NSArray*)classFallbacksForKeyedArchiver;
- (id)replacementObjectForKeyedArchiver:(NSKeyedArchiver*)archiver;
@end

@interface NSObject (Foundation)
- (void)performSelectorOnMainThread:(SEL)selector withObject:(id)obj1 waitUntilDone:(BOOL)wait;
- (void)performSelectorOnMainThread:(SEL)selector withObject:(id)obj waitUntilDone:(BOOL)wait modes:(NSArray*)modes;
- (void)performSelectorInBackground:(SEL)selector withObject:(id)obj;
+ (void)performSelectorInBackground:(SEL)selector withObject:(id)obj;
- (void)_performSelectorAndSignal:(NSArray*)args;
- (void)performSelector:(SEL)selector onThread:(NSThread*)thread withObject:(id)obj waitUntilDone:(BOOL)waitUntilDone modes:(id)modes;
- (void)performSelector:(SEL)selector onThread:(id)thread withObject:(id)obj waitUntilDone:(BOOL)wait;
+ (void)_delayedPerform:(NSTimer*)timer;
+ (void)object:(id)object performSelector:(SEL)selector withObject:(id)argument afterDelay:(NSTimeInterval)delay inModes:(NSArray*)modes;
- (void)performSelector:(SEL)selector withObject:(id)obj1 afterDelay:(NSTimeInterval)delay;
- (void)performSelector:(SEL)selector withObject:(id)obj1 afterDelay:(NSTimeInterval)delay inModes:(NSArray*)modes;
- (NSMethodSignature*)methodSignatureForSelector:(SEL)selector;
+ (NSMethodSignature*)instanceMethodSignatureForSelector:(SEL)selector;
@end
// clang-format on

@protocol NSCoding <NSObject>
- (instancetype)initWithCoder:(NSCoder*)decoder;
- (void)encodeWithCoder:(NSCoder*)encoder;
@end

@protocol NSSecureCoding <NSCoding>
+ (BOOL)supportsSecureCoding;
@end

@protocol NSCopying
- (id)copyWithZone:(NSZone*)zone;
@end

@protocol NSMutableCopying
- (id)mutableCopyWithZone:(NSZone*)zone;
@end

#if __has_feature(objc_arc)
    NS_INLINE NS_RETURNS_RETAINED CFTypeRef
    CFBridgingRetain(id X) {
    return (__bridge_retained CFTypeRef)X;
}

NS_INLINE id CFBridgingRelease(CFTypeRef CF_CONSUMED X) {
    return (__bridge_transfer id)X;
}
#else
#pragma clang diagnostic ignored "-Wignored-attributes"
    NS_INLINE NS_RETURNS_RETAINED CFTypeRef
    CFBridgingRetain(id X) {
    return X ? CFRetain((CFTypeRef)X) : NULL;
}

NS_INLINE id CFBridgingRelease(CFTypeRef CF_CONSUMED X) {
    return [(id)CFMakeCollectable(X) autorelease];
}
#endif

// [WinObjC Extension]
// WinObjC_SetMissingSelectorFatal allows a developer to turn off the missing selector exception.
// It's intended to be used to gather an API use depth measurement to determine hotspots in
// an application. Nonexistent methods called with this disengaged will return nil / 0 / 0L.
// Defaults to YES: missing selectors will cause an exception to be thrown.
FOUNDATION_EXPORT void WinObjC_SetMissingSelectorFatal(BOOL);
