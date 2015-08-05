/* Copyright (c) 2007 Christopher J. W. Lloyd

Permission is hereby granted,free of charge,to any person obtaining a copy of this software and associated documentation files (the "Software"),to deal in the Software without restriction,including without limitation the rights to use,copy,modify,merge,publish,distribute,sublicense,and/or sell copies of the Software,and to permit persons to whom the Software is furnished to do so,subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS",WITHOUT WARRANTY OF ANY KIND,EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,DAMAGES OR OTHER LIABILITY,WHETHER IN AN ACTION OF CONTRACT,TORT OR OTHERWISE,ARISING FROM,OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _CFBASE_H_
#define _CFBASE_H_

#import <limits.h>
#import <stdint.h>
#import <math.h>
#import <stdbool.h>
#import <MacTypes.h>
#ifdef __ISLANDWOOD_COMPAT
 #import <mach/mach_types.h>
#endif
#import <TargetConditionals.h>
#import <Block.h>
#import <CoreFoundation/CoreFoundationExport.h>
#import <StarboardExport.h>

/* Apple's Foundation imports CoreGraphics in order to get some of the basic CG* types, unfortunately
   this is a hassle on platforms where you just want to use Foundation, so we put them in CoreFoundation and see what happens
*/

#ifndef ENABLE_IMPLICIT_BRIDGING
#if __has_feature(arc_cf_code_audited)
#define ENABLE_IMPLICIT_BRIDGING _Pragma("clang arc_cf_code_audited begin")
#else
#define ENABLE_IMPLICIT_BRIDGING
#endif
#endif

#ifndef DISABLE_IMPLICIT_BRIDGING
#if __has_feature(arc_cf_code_audited)
#define DISABLE_IMPLICIT_BRIDGING _Pragma("clang arc_cf_code_audited end")
#else
#define DISABLE_IMPLICIT_BRIDGING
#endif
#endif

COREFOUNDATION_EXTERNC_BEGIN

typedef const struct __CFString * CFStringRef;
typedef struct __CFString * CFMutableStringRef;
 
enum {
    kCFNotFound = LONG_MAX
};

#ifdef __LP64__
typedef double CGFloat;
#define CGFLOAT_MIN DBL_MIN
#define CGFLOAT_MAX DBL_MAX
#else
typedef float CGFloat;
#define CGFLOAT_MIN FLT_MIN
#define CGFLOAT_MAX FLT_MAX
#endif

#ifdef __cplusplus
struct CGPoint {
    CGFloat x, y;

    CGPoint operator+(const CGPoint& v) const
    {
        CGPoint ret = { x + v.x, y + v.y };
        return ret;
    }

    CGPoint operator-() const
    {
        CGPoint ret = { -x, -y };
        return ret;
    }

    CGPoint operator-(const CGPoint& v) const
    {
        CGPoint ret = { x - v.x, y - v.y };
        return ret;
    }

    CGPoint operator-=(const CGPoint& v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    CGPoint operator+=(const CGPoint& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    bool operator==(const CGPoint& v)
    {
        return x == v.x && y == v.y;
    }

    bool operator!=(const CGPoint& v)
    {
        return x != v.x || y != v.y;
    }

    CGPoint operator*(float scalar) const
    {
        CGPoint ret = { x * scalar, y * scalar };
        return ret;
    }

    CGPoint operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    CGPoint operator/(float scalar) const
    {
        CGPoint ret = { x / scalar, y / scalar };
        return ret;
    }

    CGPoint operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    CGFloat distSq(const CGPoint& v) const
    {
        CGPoint delta = *this - v;
        return delta.dot(delta);
    }

    CGFloat dist(const CGPoint& v) const
    {
        return sqrt(distSq(v));
    }

    bool distGr(const CGPoint& v, CGFloat dist) const
    {
        return distSq(v) > dist*dist;
    }

    CGFloat lenSq() const
    {
        return dot(*this);
    }

    CGFloat len() const
    {
        return sqrt(lenSq());
    }

    bool lenGe(float len)
    {
        return lenSq() >= len*len;
    }

    bool lenLe(float len)
    {
        return lenSq() < len*len;
    }

    CGFloat dot(const CGPoint& v) const
    {
        return v.x*x + v.y*y;
    }

    CGPoint normalized() const
    {
        float l = len();

        if ( l != 0 ) {
            CGPoint ret = { x / l, y / l };
            return ret;
        } else {
            CGPoint ret = { 0, 0 };
            return ret;
        }
    }

   static inline CGPoint point(float x, float y) {
       CGPoint ret;

       ret.x = x;
       ret.y = y;

       return ret;
   }
};
#else
typedef struct CGPoint {
   CGFloat x;
   CGFloat y;
} CGPoint;
#endif

typedef struct CGSize {
   CGFloat width;
   CGFloat height;
} CGSize;

typedef struct CGRect {
   CGPoint origin;
   CGSize  size;
} CGRect;
 

typedef unsigned short UniChar;
typedef unsigned long UTF32Char;
typedef float Float32;
typedef double Float64;
// ---

typedef const void *CFTypeRef;
typedef UInt32 CFTypeID;
typedef UInt32 CFHashCode;
//typedef char       Boolean;
typedef SInt32  CFIndex;
typedef UInt32 CFOptionFlags;

typedef SInt32 OSStatus;
typedef SInt16 OSErr;

typedef UInt32 FourCharCode;
typedef FourCharCode OSType;

typedef struct {
   CFIndex location;
   CFIndex length;
} CFRange;

static inline CFRange CFRangeMake(CFIndex loc,CFIndex len){
   CFRange result={loc,len};
   
   return result;
}

#ifndef TRUE
#define TRUE ((Boolean)1)
#endif

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif

typedef enum  {
   kCFCompareLessThan  = -1,
   kCFCompareEqualTo   = 0,
   kCFCompareGreaterThan= 1
} CFComparisonResult;

typedef CFComparisonResult (*CFComparatorFunction)(const void *value,const void *other,void *context);

typedef struct CFAllocator *CFAllocatorRef;

typedef void       *(*CFAllocatorAllocateCallBack)(CFIndex size,CFOptionFlags hint,void *info);
typedef CFStringRef (*CFAllocatorCopyDescriptionCallBack)(const void *info);
typedef void        (*CFAllocatorDeallocateCallBack)(void *ptr,void *info);
typedef CFIndex     (*CFAllocatorPreferredSizeCallBack)(CFIndex size,CFOptionFlags hint,void *info);
typedef void       *(*CFAllocatorReallocateCallBack)(void *ptr,CFIndex size,CFOptionFlags hint,void *info);
typedef void        (*CFAllocatorReleaseCallBack)(const void *info);
typedef const void *(*CFAllocatorRetainCallBack)(const void *info);

typedef struct {
   CFIndex                            version;
   void                              *info;
   CFAllocatorRetainCallBack          retain;
   CFAllocatorReleaseCallBack         release;
   CFAllocatorCopyDescriptionCallBack copyDescription;
   CFAllocatorAllocateCallBack        allocate;
   CFAllocatorReallocateCallBack      reallocate;
   CFAllocatorDeallocateCallBack      deallocate;
   CFAllocatorPreferredSizeCallBack   preferredSize;
} CFAllocatorContext;

COREFOUNDATION_EXPORT const CFAllocatorRef kCFAllocatorDefault;
COREFOUNDATION_EXPORT const CFAllocatorRef kCFAllocatorSystemDefault;
COREFOUNDATION_EXPORT const CFAllocatorRef kCFAllocatorMalloc;
COREFOUNDATION_EXPORT const CFAllocatorRef kCFAllocatorMallocZone;
COREFOUNDATION_EXPORT const CFAllocatorRef kCFAllocatorNull;
COREFOUNDATION_EXPORT const CFAllocatorRef kCFAllocatorUseContext;

COREFOUNDATION_EXPORT CFAllocatorRef CFAllocatorGetDefault(void);
COREFOUNDATION_EXPORT void           CFAllocatorSetDefault(CFAllocatorRef self);

COREFOUNDATION_EXPORT CFTypeID       CFAllocatorGetTypeID(void);

COREFOUNDATION_EXPORT CFAllocatorRef CFAllocatorCreate(CFAllocatorRef self,CFAllocatorContext *context);

COREFOUNDATION_EXPORT void           CFAllocatorGetContext(CFAllocatorRef self,CFAllocatorContext *context);
COREFOUNDATION_EXPORT CFIndex        CFAllocatorGetPreferredSizeForSize(CFAllocatorRef self,CFIndex size,CFOptionFlags hint);

COREFOUNDATION_EXPORT void          *CFAllocatorAllocate(CFAllocatorRef self,CFIndex size,CFOptionFlags hint);
COREFOUNDATION_EXPORT void           CFAllocatorDeallocate(CFAllocatorRef self,void *ptr);
COREFOUNDATION_EXPORT void          *CFAllocatorReallocate(CFAllocatorRef self,void *ptr,CFIndex size,CFOptionFlags hint);

COREFOUNDATION_EXPORT CFTypeRef      CFMakeCollectable(CFTypeRef self);

COREFOUNDATION_EXPORT double kCFCoreFoundationVersionNumber;

typedef const struct __CFNull *CFNullRef;
COREFOUNDATION_EXPORT const CFNullRef kCFNull;

ENABLE_IMPLICIT_BRIDGING

COREFOUNDATION_EXPORT CFTypeID       CFGetTypeID(CFTypeRef self);
COREFOUNDATION_EXPORT CFHashCode     CFHash(CFTypeRef self);
COREFOUNDATION_EXPORT Boolean        CFEqual(CFTypeRef self,CFTypeRef other);
COREFOUNDATION_EXPORT CFStringRef    CFCopyTypeIDDescription(CFTypeID typeID);
COREFOUNDATION_EXPORT CFStringRef    CFCopyDescription(CFTypeRef self);
COREFOUNDATION_EXPORT CFTypeRef      CFRetain(CFTypeRef self);
COREFOUNDATION_EXPORT void           CFRelease(CFTypeRef self);
COREFOUNDATION_EXPORT CFIndex        CFGetRetainCount(CFTypeRef self);
COREFOUNDATION_EXPORT CFAllocatorRef CFGetAllocator(CFTypeRef self);

DISABLE_IMPLICIT_BRIDGING

COREFOUNDATION_EXTERNC_END

#endif /* _CFBASE_H_ */
