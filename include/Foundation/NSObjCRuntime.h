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

#ifndef _NSOBJCRUNTIME_H_
#define _NSOBJCRUNTIME_H_

#import <objc/objc.h>
#import <stdarg.h>
#import <stdint.h>
#import <limits.h>
#import <TargetConditionals.h>
#import <Foundation/FoundationExport.h>
#import <Availability.h>
#import <StarboardExport.h>

#define NS_INLINE static inline

// FIXME: do we really need all of these conditions
#if (__cplusplus && __cplusplus >= 201103L && (__has_extension(cxx_strong_enums) || __has_feature(objc_fixed_enum))) || \
    (!__cplusplus && __has_feature(objc_fixed_enum))
#define NS_ENUM(_type, _name) \
    enum _name : _type _name; \
    enum _name : _type
#else
#define NS_ENUM(_type, _name) \
    _type _name;              \
    enum
#endif

#if !defined(NS_REQUIRES_NIL_TERMINATION)
#define NS_REQUIRES_NIL_TERMINATION __attribute__((sentinel(0, 1)))
#endif

#ifndef NS_RETURNS_RETAINED
#if __has_feature(attribute_ns_returns_retained)
#define NS_RETURNS_RETAINED __attribute__((ns_returns_retained))
#else
#define NS_RETURNS_RETAINED
#endif
#endif

#ifndef NS_RETURNS_NOT_RETAINED
#if __has_feature(attribute_ns_returns_not_retained)
#define NS_RETURNS_NOT_RETAINED __attribute__((ns_returns_not_retained))
#else
#define NS_RETURNS_NOT_RETAINED
#endif
#endif

#ifndef CF_RETURNS_RETAINED
#if __has_feature(attribute_cf_returns_retained)
#define CF_RETURNS_RETAINED __attribute__((cf_returns_retained))
#else
#define CF_RETURNS_RETAINED
#endif
#endif

#ifndef CF_RETURNS_NOT_RETAINED
#if __has_feature(attribute_cf_returns_not_retained)
#define CF_RETURNS_NOT_RETAINED __attribute__((cf_returns_not_retained))
#else
#define CF_RETURNS_NOT_RETAINED
#endif
#endif

#ifndef NS_CONSUMED
#if __has_feature(attribute_ns_consumed)
#define NS_CONSUMED __attribute__((ns_consumed))
#else
#define NS_CONSUMED
#endif
#endif

#ifndef CF_CONSUMED
#if __has_feature(attribute_cf_consumed)
#define CF_CONSUMED __attribute__((cf_consumed))
#else
#define CF_CONSUMED
#endif
#endif

#ifndef NS_FORMAT_ARGUMENT
#ifdef __clang__
#define NS_FORMAT_ARGUMENT(x) __attribute__((format_arg(x)))
#else
#define NS_FORMAT_ARGUMENT(x)
#endif
#endif

#if __has_attribute(objc_requires_property_definitions)
#define NS_REQUIRES_PROPERTY_DEFINITIONS __attribute__((objc_requires_property_definitions))
#else
#define NS_REQUIRES_PROPERTY_DEFINITIONS
#endif

@class NSString;

#define NSINTEGER_DEFINED 1

#if defined(__LP64__)
typedef long NSInteger;
typedef unsigned long NSUInteger;
#define NSIntegerMax LONG_MAX
#define NSIntegerMin LONG_MIN
#define NSUIntegerMax ULONG_MAX
#else
typedef int NSInteger;
typedef unsigned int NSUInteger;
#define NSIntegerMax INT_MAX
#define NSIntegerMin INT_MIN
#define NSUIntegerMax UINT_MAX
#endif

enum {
    NSOrderedAscending = -1,
    NSOrderedSame = 0,
    NSOrderedDescending = 1,
};

typedef NSInteger NSComparisonResult;

typedef NSComparisonResult (^NSComparator)(id obj1, id obj2);

#define NSNotFound NSIntegerMax

#ifndef MIN
#define MIN(a, b)               \
    ({                          \
        __typeof__(a) _a = (a); \
        __typeof__(b) _b = (b); \
        (_a < _b) ? _a : _b;    \
    })
#else
#warning MIN is already defined, MIN(a, b) may not behave as expected.
#endif

#ifndef MAX
#define MAX(a, b)               \
    ({                          \
        __typeof__(a) _a = (a); \
        __typeof__(b) _b = (b); \
        (_a > _b) ? _a : _b;    \
    })
#else
#warning MAX is already defined, MAX(a, b) may not not behave as expected.
#endif

#ifndef ABS
#define ABS(a)                  \
    ({                          \
        __typeof__(a) _a = (a); \
        (_a < 0) ? -_a : _a;    \
    })
#else
#warning ABS is already defined, ABS(a) may not behave as expected.
#endif

FOUNDATION_EXPORT void NSLog(NSString* format, ...);
FOUNDATION_EXPORT void NSLogv(NSString* format, va_list args);

FOUNDATION_EXPORT const char* NSGetSizeAndAlignment(const char* type, NSUInteger* size, NSUInteger* alignment);

FOUNDATION_EXPORT SEL NSSelectorFromString(NSString* selectorName);
FOUNDATION_EXPORT NSString* NSStringFromSelector(SEL selector);

FOUNDATION_EXPORT Class NSClassFromString(NSString* className);
FOUNDATION_EXPORT NSString* NSStringFromClass(Class aClass);
FOUNDATION_EXPORT NSString* NSStringFromProtocol(Protocol* proto);

#ifndef NS_FORMAT_FUNCTION
#define NS_FORMAT_FUNCTION(F, A)
#endif

#ifndef NS_BLOCKS_AVAILABLE
#if __BLOCKS__
#define NS_BLOCKS_AVAILABLE 1
#else
#define NS_BLOCKS_AVAILABLE 0
#endif
#endif

#ifndef NS_UNAVAILABLE
#define NS_UNAVAILABLE UNAVAILABLE_ATTRIBUTE
#endif

#define NS_AVAILABLE_IOS(x)
#define NS_DEPRECATED_IOS(x, y)

#ifdef __cplusplus
#define NS_OPTIONS(_t, __n) \
    _t _n;                  \
    enum : _t
#else
#define NS_OPTIONS(_t, _n) \
    enum _n : _t _n;       \
    enum _n : _t
#endif

enum {
    NSSortConcurrent = 1UL,
    NSSortStable = 16UL,
};
typedef uint32_t NSSortOptions;

enum {
    NSEnumerationConcurrent = 1,
    NSEnumerationReverse = 2,
};
typedef uint32_t NSEnumerationOptions;

FOUNDATION_EXPORT double NSFoundationVersionNumber;

#define NSFoundationVersionNumber_iPhoneOS_2_0 678.24
#define NSFoundationVersionNumber_iPhoneOS_2_1 678.26
#define NSFoundationVersionNumber_iPhoneOS_2_2 678.29
#define NSFoundationVersionNumber_iPhoneOS_3_0 678.47
#define NSFoundationVersionNumber_iPhoneOS_3_1 678.51
#define NSFoundationVersionNumber_iPhoneOS_3_2 678.60
#define NSFoundationVersionNumber_iOS_4_0 751.32
#define NSFoundationVersionNumber_iOS_4_1 751.37
#define NSFoundationVersionNumber_iOS_4_2 751.49
#define NSFoundationVersionNumber_iOS_4_3 751.49
#define NSFoundationVersionNumber_iOS_5_0 881.00
#define NSFoundationVersionNumber_iOS_5_1 890.10
#define NSFoundationVersionNumber_iOS_6_0 993.00
#define NSFoundationVersionNumber_iOS_6_1 993.00

#ifndef NS_VALID_UNTIL_END_OF_SCOPE
#define NS_VALID_UNTIL_END_OF_SCOPE __attribute__((objc_precise_lifetime))
#endif

#ifndef NS_RETURNS_INNER_POINTER
#define NS_RETURNS_INNER_POINTER __attribute__((objc_returns_inner_pointer))
#endif

#endif /* _NSOBJCRUNTIME_H_ */