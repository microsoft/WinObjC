/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Copyright (c) Microsoft. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#pragma once

#import <CoreGraphics/CoreGraphicsExport.h>
#import <CoreGraphics/CGBase.h>
#import <CoreFoundation/CFDictionary.h>
#import <stdbool.h>

#if defined(__LP64__) && __LP64__
#define CGFLOAT_MIN 2.2250738585072014e-308
#define CGFLOAT_MAX 1.7976931348623157e+308
#define CGFLOAT_IS_DOUBLE 1
#else
#define CGFLOAT_MIN 1.17549435e-38F
#define CGFLOAT_MAX 3.40282347e+38F
#define CGFLOAT_IS_DOUBLE 0
#endif

typedef struct {
    CGFloat dx;
    CGFloat dy;
} CGVector;
typedef enum { CGRectMinXEdge, CGRectMinYEdge, CGRectMaxXEdge, CGRectMaxYEdge } CGRectEdge;

COREGRAPHICS_EXPORT const CGRect CGRectInfinite;
COREGRAPHICS_EXPORT const CGPoint CGPointZero;
COREGRAPHICS_EXPORT const CGRect CGRectZero;
COREGRAPHICS_EXPORT const CGSize CGSizeZero;
COREGRAPHICS_EXPORT const CGRect CGRectNull;

/**
@Status Interoperable
*/
static inline CGRect CGRectMake(CGFloat x, CGFloat y, CGFloat width, CGFloat height) {
    CGRect result = { { x, y }, { width, height } };
    return result;
}

/**
@Status Interoperable
*/
static inline CGPoint CGPointMake(CGFloat x, CGFloat y) {
    CGPoint result = { x, y };
    return result;
}

/**
@Status Interoperable
*/
static inline CGSize CGSizeMake(CGFloat x, CGFloat y) {
    CGSize result = { x, y };
    return result;
}

/**
@Status Interoperable
*/
static inline CGVector CGVectorMake(CGFloat dx, CGFloat dy) {
    CGVector result = { dx, dy };
    return result;
}

/**
@Status Interoperable
*/
static inline bool CGSizeEqualToSize(CGSize a, CGSize b) {
    return a.width == b.width && a.height == b.height;
}

/**
@Status Interoperable
*/
static inline CGFloat CGRectGetMinX(CGRect rect) {
    return rect.origin.x;
}

/**
@Status Interoperable
*/
static inline CGFloat CGRectGetMaxX(CGRect rect) {
    return rect.origin.x + rect.size.width;
}

/**
@Status Interoperable
*/
static inline CGFloat CGRectGetMidX(CGRect rect) {
    return CGRectGetMinX(rect) + ((CGRectGetMaxX(rect) - CGRectGetMinX(rect)) / 2.f);
}

/**
@Status Interoperable
*/
static inline CGFloat CGRectGetMinY(CGRect rect) {
    return rect.origin.y;
}

/**
@Status Interoperable
*/
static inline CGFloat CGRectGetMaxY(CGRect rect) {
    return rect.origin.y + rect.size.height;
}

/**
@Status Interoperable
*/
static inline CGFloat CGRectGetMidY(CGRect rect) {
    return CGRectGetMinY(rect) + ((CGRectGetMaxY(rect) - CGRectGetMinY(rect)) / 2.f);
}

/**
@Status Interoperable
*/
static inline CGFloat CGRectGetWidth(CGRect rect) {
    return rect.size.width;
}

/**
@Status Interoperable
*/
static inline CGFloat CGRectGetHeight(CGRect rect) {
    return rect.size.height;
}

/**
@Status Interoperable
*/
static inline bool CGRectContainsPoint(CGRect rect, CGPoint point) {
    return (point.x >= CGRectGetMinX(rect) && point.x <= CGRectGetMaxX(rect)) &&
           (point.y >= CGRectGetMinY(rect) && point.y <= CGRectGetMaxY(rect));
}

/**
@Status Interoperable
*/
static inline bool CGPointEqualToPoint(CGPoint a, CGPoint b) {
    return ((a.x == b.x) && (a.y == b.y)) ? TRUE : FALSE;
}

/**
@Status Interoperable
*/
static inline CGRect CGRectInset(CGRect rect, CGFloat dx, CGFloat dy) {
    rect.origin.x += dx;
    rect.origin.y += dy;
    rect.size.width -= dx * 2;
    rect.size.height -= dy * 2;
    return rect;
}

/**
@Status Interoperable
*/
static inline CGRect CGRectOffset(CGRect rect, CGFloat dx, CGFloat dy) {
    rect.origin.x += dx;
    rect.origin.y += dy;
    return rect;
}

/**
@Status Interoperable
*/
static inline bool CGRectIsEmpty(CGRect rect) {
    return ((rect.size.width == 0) && (rect.size.height == 0));
}

/**
@Status Interoperable
*/
static inline bool CGRectIntersectsRect(CGRect a, CGRect b) {
    return !((b.origin.x > a.origin.x + a.size.width) || (b.origin.y > a.origin.y + a.size.height) ||
             (a.origin.x > b.origin.x + b.size.width) || (a.origin.y > b.origin.y + b.size.height));
}

/**
@Status Interoperable
*/
static inline bool CGRectEqualToRect(CGRect a, CGRect b) {
    return CGPointEqualToPoint(a.origin, b.origin) && CGSizeEqualToSize(a.size, b.size);
}

/**
@Status Interoperable
*/
static inline bool CGRectIsNull(CGRect rect) {
    return CGRectEqualToRect(rect, CGRectNull);
}

/**
@Status Interoperable
*/
static inline bool CGRectIsInfinite(CGRect rect) {
    return (isinf(rect.origin.x) || isinf(rect.origin.y) || isinf(rect.size.width) || isinf(rect.size.height));
}

/**
@Status Interoperable
*/
static inline bool CGRectContainsRect(CGRect a, CGRect b) {
    return (CGRectGetMinX(b) >= CGRectGetMinX(a) && CGRectGetMaxX(b) <= CGRectGetMaxX(a) && CGRectGetMinY(b) >= CGRectGetMinY(a) &&
            CGRectGetMaxY(b) <= CGRectGetMaxY(a));
}

COREGRAPHICS_EXPORT CGRect CGRectIntegral(CGRect rect);
COREGRAPHICS_EXPORT CGRect CGRectIntersection(CGRect r1, CGRect r2);
COREGRAPHICS_EXPORT CGRect CGRectStandardize(CGRect rect);
COREGRAPHICS_EXPORT CGRect CGRectUnion(CGRect a, CGRect b);
COREGRAPHICS_EXPORT CGRect CGRectStandardize(CGRect rect);

COREGRAPHICS_EXPORT CFDictionaryRef CGPointCreateDictionaryRepresentation(CGPoint point) STUB_METHOD;
COREGRAPHICS_EXPORT CFDictionaryRef CGSizeCreateDictionaryRepresentation(CGSize size) STUB_METHOD;
COREGRAPHICS_EXPORT CFDictionaryRef CGRectCreateDictionaryRepresentation(CGRect) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPointMakeWithDictionaryRepresentation(CFDictionaryRef dict, CGPoint* point) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGSizeMakeWithDictionaryRepresentation(CFDictionaryRef dict, CGSize* size) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGRectMakeWithDictionaryRepresentation(CFDictionaryRef dict, CGRect* rect) STUB_METHOD;
COREGRAPHICS_EXPORT void CGRectDivide(CGRect rect, CGRect* slice, CGRect* remainder, CGFloat amount, CGRectEdge edge) STUB_METHOD;
