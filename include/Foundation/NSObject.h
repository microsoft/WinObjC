/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <Foundation/NSObjCRuntime.h>
#import <Foundation/NSZone.h>

@class NSCoder,NSInvocation,NSMethodSignature,NSString;

@protocol NSObject

-(NSZone *)zone;

-(id)self;
-(Class)class;
-(Class)superclass;

-autorelease;
-(oneway void)release;
-retain;
-(NSUInteger)retainCount;

-(NSUInteger)hash;
-(BOOL)isEqual:object;

-(BOOL)isKindOfClass:(Class)aClass;
-(BOOL)isMemberOfClass:(Class)aClass;
-(BOOL)conformsToProtocol:(Protocol *)protocol;

-(BOOL)respondsToSelector:(SEL)selector;
-performSelector:(SEL)selector;
-performSelector:(SEL)selector withObject:object0;
-performSelector:(SEL)selector withObject:object0 withObject:object1;

-(BOOL)isProxy;

-(NSString *)description;
- (NSString *)debugDescription;

@end

@protocol NSCopying
-copyWithZone:(NSZone *)zone;
@end

@protocol NSMutableCopying
-mutableCopyWithZone:(NSZone *)zone;
@end

@protocol NSCoding
-initWithCoder:(NSCoder *)coder;
-(void)encodeWithCoder:(NSCoder *)coder;
@end

@protocol NSDiscardableContent
- (BOOL)beginContentAccess;
- (void)endContentAccess;
- (BOOL)isContentDiscarded;
- (void)discardContentIfPossible;
@end

/* The root implementation of NSObject is contained in objcrt */
__declspec(dllimport)
@interface NSObject <NSObject> {
@public
#ifdef IW_NO_WINRT_ISA
    Class isa;
#else
    WinRT_isa isa;
#endif
}

+(NSInteger)version;
+(void)setVersion:(NSInteger)version;

+(void)load;

+(void)initialize;

+(Class)superclass;
+(Class)class;
+(BOOL)isSubclassOfClass:(Class)cls;

+(BOOL)instancesRespondToSelector:(SEL)selector;
+(BOOL)conformsToProtocol:(Protocol *)protocol;

+(IMP)instanceMethodForSelector:(SEL)selector;
+(NSMethodSignature *)instanceMethodSignatureForSelector:(SEL)selector;
+(BOOL)resolveClassMethod:(SEL)selector;
+(BOOL)resolveInstanceMethod:(SEL)selector;

+copyWithZone:(NSZone *)zone;
+mutableCopyWithZone:(NSZone *)zone;

+(NSString *)description;

+alloc;
+allocWithZone:(NSZone *)zone;

-init;
+new;
-(void)dealloc;
-(void)finalize;

-copy;
-mutableCopy;

-(Class)classForCoder;
-(Class)classForArchiver;
-(Class)classForKeyedArchiver;

-replacementObjectForCoder:(NSCoder *)coder;
-awakeAfterUsingCoder:(NSCoder *)coder;

-(IMP)methodForSelector:(SEL)selector;

-(void)doesNotRecognizeSelector:(SEL)selector;

-(NSMethodSignature *)methodSignatureForSelector:(SEL)selector;
-(void)forwardInvocation:(NSInvocation *)invocation;

-(NSString *)className;
-(id)forwardingTargetForSelector:(SEL)aSelector;

@end

#if __has_feature(objc_arc)
NS_INLINE NS_RETURNS_RETAINED CFTypeRef CFBridgingRetain(id X) {
    return (__bridge_retained CFTypeRef)X;
}

NS_INLINE id CFBridgingRelease(CFTypeRef CF_CONSUMED X) {
    return (__bridge_transfer id)X;
}
#else
#pragma clang diagnostic ignored "-Wignored-attributes"
NS_INLINE NS_RETURNS_RETAINED CFTypeRef CFBridgingRetain(id X) {
    return X ? CFRetain((CFTypeRef)X) : NULL;
}

NS_INLINE id CFBridgingRelease(CFTypeRef CF_CONSUMED X) {
    return [(id)CFMakeCollectable(X) autorelease];
}
#endif

#ifdef __cplusplus
template<typename objtype>
class idretaint
{
public:
    objtype *_val;

    idretaint()
    {
        _val = nil;
    }

    idretaint(id val)
    {
        _val = [val retain];
    }

    idretaint(const idretaint<objtype>&)=delete;

    ~idretaint()
    {
        [_val release];
        _val = nil;
    }

    operator objtype *()
    {
        return _val;
    }

    operator const objtype *() const
    {
        return _val;
    }

    void attach(id val)
    {
        id newVal = val;
        [_val release];
        _val = newVal;
    }

    idretaint<objtype>& operator =(id val)
    {
        if ( _val == val ) return *this;

        id newVal = [val retain];
        [_val release];
        _val = newVal;

        return *this;
    }

    idretaint<objtype>& operator =(const idretaint<objtype>& val)
    {
        return *this = val._val;
    }

    template<typename K>
    bool operator !=(const K& other)
    {
        return ((id) other) != (id) _val;
    }

    template<typename K>
    bool operator ==(const K& other)
    {
        return ((id) other) == (id) _val;
    }

    objtype *operator ->()
    {
        return _val;
    }
};

template<typename objtype>
class idretainp
{
public:
    objtype _val;

    idretainp()
    {
        _val = nil;
    }

    idretainp(id val)
    {
        _val = [val retain];
    }

    idretainp(const idretainp<objtype>&)=delete;

    ~idretainp()
    {
        [_val release];
        _val = nil;
    }

    operator objtype ()
    {
        return _val;
    }

    operator const objtype () const
    {
        return _val;
    }

    void attach(id val)
    {
        id newVal = val;
        [_val release];
        _val = newVal;
    }

    idretainp<objtype>& operator =(id val)
    {
        if ( _val == val ) return *this;

        id newVal = [val retain];
        [_val release];
        _val = newVal;

        return *this;
    }

    template<typename K>
    bool operator !=(const K& other)
    {
        return ((id) other) != (id) _val;
    }

    template<typename K>
    bool operator ==(const K& other)
    {
        return ((id) other) == (id) _val;
    }
};

template<typename K, typename T>
bool operator ==(const K other, idretaint<T>& val)
{
    return other == (id) val._val;
}

typedef idretaint<NSObject> idretain;

template<typename objtype>
class idtype
{
public:
    objtype *_val;

    idtype() : _val(0) {}

    idtype(id val)
    {
        _val = val;
    }

    ~idtype()
    {
        _val = nil;
    }

    operator objtype *()
    {
        return _val;
    }

    idtype<objtype>& operator =(id val)
    {
        if ( _val == val ) return *this;

        _val = val;

        return *this;
    }

    objtype *operator ->()
    {
        return _val;
    }
};

#define idretaintype(type) idretaint<type>
#define idretainproto(type) idretainp<id<type>>
#else
#define idretain __unsafe_unretained id
#define idretaintype(type) __unsafe_unretained id
#define idretainproto(type) id<type>
#endif

