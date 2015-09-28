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

#include "Starboard.h"
#include "UIKit/UIView.h"
#include "UIKit/UIColor.h"
#include "CoreGraphics/CGContext.h"
#include "CGContextInternal.h"
#include "Foundation/NSString.h"
#include "Foundation/NSMutableDictionary.h"
#include "CGPatternInternal.h"
#include "CoreGraphics/CGAffineTransform.h"
#include "CoreGraphics/CGPattern.h"

#include <math.h>

typedef struct {
    double r; // percent
    double g; // percent
    double b; // percent
} rgb;

typedef struct {
    double h; // angle in degrees
    double s; // percent
    double v; // percent
} hsv;

static hsv rgb2hsv(rgb in);
static rgb hsv2rgb(hsv in);

#if defined(WIN32) || defined(WINPHONE)
int isnan(double x) {
    return x != x;
}
#ifndef NAN
static const unsigned long __nan[2] = { 0xffffffff, 0x7fffffff };
#define NAN (*(const float*)__nan)
#endif
#endif

hsv rgb2hsv(rgb in) {
    hsv out;
    double min, max, delta;

    min = in.r < in.g ? in.r : in.g;
    min = min < in.b ? min : in.b;

    max = in.r > in.g ? in.r : in.g;
    max = max > in.b ? max : in.b;

    out.v = max; // v
    delta = max - min;
    if (max > 0.0) {
        out.s = (delta / max); // s
    } else {
        // r = g = b = 0                        // s = 0, v is undefined
        out.s = 0.0;
        out.h = NAN; // its now undefined
        return out;
    }
    if (in.r >= max) // > is bogus, just keeps compilor happy
        out.h = (in.g - in.b) / delta; // between yellow & magenta
    else if (in.g >= max)
        out.h = 2.0 + (in.b - in.r) / delta; // between cyan & yellow
    else
        out.h = 4.0 + (in.r - in.g) / delta; // between magenta & cyan

    out.h *= 60.0; // degrees

    if (out.h < 0.0)
        out.h += 360.0;

    return out;
}

rgb hsv2rgb(hsv in) {
    double hh, p, q, t, ff;
    long i;
    rgb out;

    if (in.s <= 0.0) { // < is bogus, just shuts up warnings
        if (isnan(in.h)) { // in.h == NAN
            out.r = in.v;
            out.g = in.v;
            out.b = in.v;
            return out;
        }
        // error - should never happen
        out.r = 0.0;
        out.g = 0.0;
        out.b = 0.0;
        return out;
    }
    hh = in.h;
    if (hh >= 360.0)
        hh = 0.0;
    hh /= 60.0;
    i = (long)hh;
    ff = hh - i;
    p = in.v * (1.0 - in.s);
    q = in.v * (1.0 - (in.s * ff));
    t = in.v * (1.0 - (in.s * (1.0 - ff)));

    switch (i) {
        case 0:
            out.r = in.v;
            out.g = t;
            out.b = p;
            break;
        case 1:
            out.r = q;
            out.g = in.v;
            out.b = p;
            break;
        case 2:
            out.r = p;
            out.g = in.v;
            out.b = t;
            break;

        case 3:
            out.r = p;
            out.g = q;
            out.b = in.v;
            break;
        case 4:
            out.r = t;
            out.g = p;
            out.b = in.v;
            break;
        case 5:
        default:
            out.r = in.v;
            out.g = p;
            out.b = q;
            break;
    }
    return out;
}

static id _cachedColorsDict;

#define CACHED_COLOR(var, name, ...)                              \
    if (((var) = [_cachedColorsDict objectForKey:name]) == nil) { \
        (var) = __VA_ARGS__;                                      \
        [_cachedColorsDict setObject:(id)(var) forKey:(name)];    \
    }                                                             \
    [var retain];

#define RETURN_CACHED(name, ...)                 \
    {                                            \
        id ret;                                  \
        CACHED_COLOR(ret, @name, ##__VA_ARGS__); \
        return ret;                              \
    }

@implementation UIColor {
@public
    enum BrushType _type;
    UIImage* _image;
    id _pattern;
    float _r, _g, _b, _a;
}
- (id)initWithCoder:(NSCoder*)coder {
    _type = solidBrush;

    NSString* pattern = [coder decodeObjectForKey:@"UIPatternSelector"];
    if (pattern != nil) {
        const char* pPattern = [pattern UTF8String];
        EbrDebugLog("Selecting pattern %s\n", pPattern);

        return [[[self class] performSelector:NSSelectorFromString(pattern)] retain];
    } else {
        if ([coder containsValueForKey:@"UIWhite"]) {
            _r = _g = _b = [coder decodeFloatForKey:@"UIWhite"];
        } else {
            _r = [coder decodeFloatForKey:@"UIRed"];
            _g = [coder decodeFloatForKey:@"UIGreen"];
            _b = [coder decodeFloatForKey:@"UIBlue"];
        }
        if ([coder containsValueForKey:@"UIAlpha"]) {
            _a = [coder decodeFloatForKey:@"UIAlpha"];
        } else {
            _a = 1.0f;
        }

        return self;
    }
}

- (void)encodeWithCoder:(NSCoder*)coder {
    assert(_type == solidBrush);

    [coder encodeFloat:_r forKey:@"UIRed"];
    [coder encodeFloat:_g forKey:@"UIGreen"];
    [coder encodeFloat:_b forKey:@"UIBlue"];
    [coder encodeFloat:_a forKey:@"UIAlpha"];
}

+ (UIColor*)grayColor {
    RETURN_CACHED("gray", [self colorWithRed:0.5f green:0.5f blue:0.5f alpha:1.0f]);
}

+ (UIColor*)cyanColor {
    RETURN_CACHED("cyan", [self colorWithRed:0.0f green:1.0f blue:1.0f alpha:1.0f]);
}

+ (UIColor*)magentaColor {
    RETURN_CACHED("magenta", [self colorWithRed:1.0f green:0.0f blue:1.0f alpha:1.0f]);
}

+ (UIColor*)lightGrayColor {
    RETURN_CACHED("lightGray", [self colorWithRed:0.75f green:0.75f blue:0.75f alpha:1.0f]);
}

+ (UIColor*)darkGrayColor {
    RETURN_CACHED("darkGray", [self colorWithRed:0.25f green:0.25f blue:0.25f alpha:1.0f]);
}

+ (UIColor*)clearColor {
    RETURN_CACHED("clear", [self colorWithRed:0.0f green:0.0f blue:0.0f alpha:0.0f]);
}

+ (UIColor*)blackColor {
    RETURN_CACHED("black", [self colorWithRed:0.0f green:0.0f blue:0.0f alpha:1.0f]);
}

+ (UIColor*)redColor {
    RETURN_CACHED("red", [self colorWithRed:1.0f green:0.0f blue:0.0f alpha:1.0f]);
}

+ (UIColor*)blueColor {
    RETURN_CACHED("blue", [self colorWithRed:0.0f green:0.0f blue:1.0f alpha:1.0f]);
}

+ (UIColor*)cornflowerBlueColor {
    RETURN_CACHED("cornflowerBlue", [self colorWithRed:0.0f green:0.737f blue:0.949f alpha:1.0f]);
}

+ (UIColor*)whiteColor {
    RETURN_CACHED("white", [self colorWithRed:1.0f green:1.0f blue:1.0f alpha:1.0f]);
}

+ (UIColor*)yellowColor {
    RETURN_CACHED("yellow", [self colorWithRed:1.0f green:1.0f blue:0.0f alpha:1.0f]);
}

+ (UIColor*)brownColor {
    RETURN_CACHED("brown", [self colorWithRed:0.65f green:0.35f blue:0.0f alpha:1.0f]);
}

+ (UIColor*)greenColor {
    RETURN_CACHED("green", [self colorWithRed:0.0f green:1.0f blue:0.0f alpha:1.0f]);
}

+ (UIColor*)orangeColor {
    RETURN_CACHED("orange", [self colorWithRed:1.0f green:0.5f blue:0.0f alpha:1.0f]);
}

+ (UIColor*)purpleColor {
    RETURN_CACHED("purple", [self colorWithRed:0.7f green:0.2f blue:0.9f alpha:1.0f]);
}

+ (UIColor*)lightTextColor {
    RETURN_CACHED("lightText", [self colorWithRed:0.75f green:0.75f blue:0.75f alpha:1.0f]);
}

+ (UIColor*)darkTextColor {
    RETURN_CACHED("darkText", [self colorWithRed:0.0f green:0.0f blue:0.0f alpha:1.0f]);
}

- (CGColorRef)CGColor {
    return (CGColorRef)self;
}

+ (UIColor*)colorWithRed:(float)r green:(float)g blue:(float)b alpha:(float)a {
    UIColor* ret = [self alloc];
    ret->_r = r;
    ret->_g = g;
    ret->_b = b;
    ret->_a = a;
    ret->_type = solidBrush;

    return [ret autorelease];
}

+ (UIColor*)colorWithHue:(float)h saturation:(float)s brightness:(float)v alpha:(float)a {
    UIColor* ret = [self alloc];

    return [[ret initWithHue:h saturation:s brightness:v alpha:a] autorelease];
}

- (UIColor*)initWithHue:(float)h saturation:(float)s brightness:(float)v alpha:(float)a {
    hsv in;
    rgb out;

    in.h = h * 360.0f;
    in.s = s;
    in.v = v;

    out = hsv2rgb(in);

    _r = (float)out.r;
    _g = (float)out.g;
    _b = (float)out.b;
    _a = (float)a;
    _type = solidBrush;

    return self;
}

- (UIColor*)initWithRed:(float)r green:(float)g blue:(float)b alpha:(float)a {
    _r = r;
    _g = g;
    _b = b;
    _a = a;
    _type = solidBrush;
    return self;
}

- (UIColor*)initWithPatternImage:(UIImage*)image {
    CGRect bounds = { 0 };

    bounds.size = [image size];
    CGAffineTransform m;

    CGImageRef pImg = (CGImageRef)[image CGImage];

    if (pImg == NULL) {
        return nil;
    }

#if 0
if ( bounds.size.width < 256 || bounds.size.height < 256 ) {
m = CGAffineTransformMakeTranslation(0, 0);
CGPatternCallbacks callbacks;

callbacks.version = 0;
callbacks.releaseInfo = 0;
callbacks.drawPattern = __UIColorPatternFill;

_pattern = (id) CGPatternCreateColorspace(self, bounds, m, bounds.size.width, bounds.size.height, 0, FALSE, &callbacks, pImg->_has32BitAlpha ? _ColorRGBA : _ColorRGB);
} else {
_pattern = (id) CGPatternCreateFromImage(pImg);
}
#else
    _pattern = (id)CGPatternCreateFromImage(pImg);
#endif
    _image = [image retain];
    _type = cgPatternBrush;

    _r = 0;
    _g = 0;
    _b = 0;
    _a = 0;

    return self;
}

+ (UIColor*)colorWithWhite:(float)gray alpha:(float)alpha {
    return [self colorWithRed:gray green:gray blue:gray alpha:alpha];
}

- (UIColor*)initWithWhite:(float)gray alpha:(float)alpha {
    return [self initWithRed:gray green:gray blue:gray alpha:alpha];
}

+ (UIColor*)colorWithPatternImage:(UIImage*)image {
    UIColor* ret = [self alloc];

    return [[ret initWithPatternImage:image] autorelease];
}

+ (UIColor*)colorWithCGPattern:(CGPatternRef)pattern {
    UIColor* ret = [self alloc];

    ret->_type = cgPatternBrush;
    ret->_pattern = [(id)pattern retain];

    return [ret autorelease];
}

- (UIColor*)colorWithAlphaComponent:(float)alpha {
    return [UIColor colorWithRed:_r green:_g blue:_b alpha:alpha];
}

+ (UIColor*)colorWithColor:(UIColor*)copyclr {
    if (copyclr == nil)
        return nil;

    UIColor* ret = [self alloc];

    ret->_type = copyclr->_type;
    ret->_pattern = [copyclr->_pattern retain];
    ret->_r = copyclr->_r;
    ret->_g = copyclr->_g;
    ret->_b = copyclr->_b;
    ret->_a = copyclr->_a;

    return [ret autorelease];
}

+ (UIColor*)colorWithCGColor:(CGColorRef)clr {
    UIColor* copyclr = (id)clr;
    if (copyclr == nil)
        return nil;

    UIColor* ret = [self alloc];

    ret->_type = copyclr->_type;
    ret->_pattern = [copyclr->_pattern retain];
    ret->_r = copyclr->_r;
    ret->_g = copyclr->_g;
    ret->_b = copyclr->_b;
    ret->_a = copyclr->_a;

    return [ret autorelease];
}

- (void)getColors:(float*)colors {
    colors[0] = _r;
    colors[1] = _g;
    colors[2] = _b;
    colors[3] = _a;
}

- (void)set {
    //  Set current context color
    if (UIGraphicsGetCurrentContext()) {
        CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), (CGColorRef)self);
        CGContextSetStrokeColorWithColor(UIGraphicsGetCurrentContext(), (CGColorRef)self);
    } else {
        EbrDebugLog("UIColor::set - context not set\n");
    }
}

- (BrushType)_type {
    return _type;
}

- (CGImageRef)getPatternImage {
    return (CGImageRef)[_pattern getPatternImage];
}

- (void)setFill {
    //  Set current context color
    if (UIGraphicsGetCurrentContext()) {
        CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), (CGColorRef)self);
    } else {
        EbrDebugLog("UIColor::setFill - context not set\n");
    }
}

- (void)setStroke {
    //  Set current context color
    CGContextSetStrokeColorWithColor(UIGraphicsGetCurrentContext(), (CGColorRef)self);
}

+ (UIColor*)groupTableViewBackgroundColor {
    return [self colorWithRed:197.f / 255.f green:204.f / 255.f blue:210.f / 255.f alpha:1.0f];
}

+ (UIColor*)viewFlipsideBackgroundColor {
    return [self whiteColor];
}

- (BOOL)getHue:(float*)h saturation:(float*)s brightness:(float*)v alpha:(float*)a {
    hsv out;
    rgb in;

    in.r = _r;
    in.b = _b;
    in.g = _g;

    out = rgb2hsv(in);

    if (h)
        *h = (float)(out.h / 360.0);
    if (s)
        *s = (float)out.s;
    if (v)
        *v = (float)out.v;
    if (a)
        *a = _a;

    return TRUE;
}

- (BOOL)getRed:(float*)r green:(float*)g blue:(float*)b alpha:(float*)a {
    if (r)
        *r = _r;
    if (g)
        *g = _g;
    if (b)
        *b = _b;
    if (a)
        *a = _a;

    return TRUE;
}

- (BOOL)isEqual:(UIColor*)other {
    if (![other isKindOfClass:[UIColor class]])
        return FALSE;

    if (_type == other->_type && _image == other->_image && _pattern == other->_pattern && _r == other->_r &&
        _g == other->_g && _b == other->_b) {
        return TRUE;
    } else {
        return FALSE;
    }
}

- (void)dealloc {
    [_image release];
    [_pattern release];
    [super dealloc];
}

+ (void)initialize {
    _cachedColorsDict = [NSMutableDictionary new];
}

@end

DWORD _UIColorPatternFill(UIColor* color, CGContextRef ctx) {
    CGRect bounds = { 0 };

    bounds.size = [color->_image size];
    CGContextDrawImage(ctx, bounds, (CGImageRef)[color->_image CGImage]);
    return 0;
}
