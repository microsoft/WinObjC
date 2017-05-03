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

#import "UICGColor.h"
#import "CGPatternInternal.h"
#import <CFFoundationInternal.h>
#import <CoreFoundation/CoreFoundation.h>
#import <BridgeHelpers.h>
#import <UIKit/UIGraphics.h>
#import "UIColorInternal.h"

#pragma region helpers

static const wchar_t* TAG = L"UIColor";

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
    if (in.r >= max) { // > is bogus, just keeps compilor happy
        out.h = (in.g - in.b) / delta; // between yellow & magenta
    } else if (in.g >= max) {
        out.h = 2.0 + (in.b - in.r) / delta; // between cyan & yellow
    } else {
        out.h = 4.0 + (in.r - in.g) / delta; // between magenta & cyan
    }

    out.h *= 60.0; // degrees

    if (out.h < 0.0) {
        out.h += 360.0;
    }

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
    if (hh >= 360.0) {
        hh = 0.0;
    }
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

#pragma endregion helpers

#pragma region Inits

@implementation UICGColorPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS(_UIColorConcrete)

- (instancetype)init {
    return [self initWithRed:0 green:0 blue:0 alpha:0];
}

- (instancetype)initWithHue:(CGFloat)h saturation:(CGFloat)s brightness:(CGFloat)v alpha:(CGFloat)a {
    hsv in;
    rgb out;

    in.h = h * 360.0f;
    in.s = s;
    in.v = v;

    out = hsv2rgb(in);

    return [self initWithRed:static_cast<float>(out.r) green:static_cast<float>(out.g) blue:static_cast<float>(out.b) alpha:a];
}

- (instancetype)initWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a {
    return reinterpret_cast<UICGColorPrototype*>(CGColorCreateGenericRGB(r, g, b, a));
}

- (instancetype)initWithWhite:(CGFloat)gray alpha:(CGFloat)alpha {
    return reinterpret_cast<UICGColorPrototype*>(CGColorCreateGenericGray(gray, alpha));
}

- (instancetype)initWithPatternImage:(UIImage*)image {
    CGImageRef img = static_cast<CGImageRef>([image CGImage]);
    auto pattern = woc::MakeStrongCF<CGPatternRef>(_CGPatternCreateFromImage(img));
    return reinterpret_cast<UICGColorPrototype*>(CGColorCreateWithPattern(CGImageGetColorSpace(img), pattern, nullptr));
}

- (instancetype)initWithCGColor:(CGColorRef)cgColor {
    return reinterpret_cast<UICGColorPrototype*>(CGColorCreateCopy(cgColor));
}

@end

@implementation _UIColorConcrete

BRIDGED_CLASS_REQUIRED_IMPLS(CGColorRef, CGColorGetTypeID, UIColor, _UIColorConcrete)

#pragma endregion Inits

- (void)set {
    //  Set current context color
    if (UIGraphicsGetCurrentContext()) {
        CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), reinterpret_cast<CGColorRef>(self));
        CGContextSetStrokeColorWithColor(UIGraphicsGetCurrentContext(), reinterpret_cast<CGColorRef>(self));
    } else {
        TraceVerbose(TAG, L"UIColor::set - context not set");
    }
}

- (void)setFill {
    //  Set current context color
    if (UIGraphicsGetCurrentContext()) {
        CGContextSetFillColorWithColor(UIGraphicsGetCurrentContext(), reinterpret_cast<CGColorRef>(self));
    } else {
        TraceVerbose(TAG, L"UIColor::setFill - context not set");
    }
}

- (void)setStroke {
    //  Set current context color
    CGContextSetStrokeColorWithColor(UIGraphicsGetCurrentContext(), reinterpret_cast<CGColorRef>(self));
}

- (UIColor*)colorWithAlphaComponent:(CGFloat)alpha {
    auto color = woc::MakeStrongCF<CGColorRef>(CGColorCreateCopyWithAlpha(reinterpret_cast<CGColorRef>(self), alpha));
    return [UIColor colorWithCGColor:color];
}

- (CGColorRef)CGColor {
    return reinterpret_cast<CGColorRef>(self);
}

@end

// Const colors are expected to be a singleton
@implementation _UIColorConcreteConst

+ (id)alloc {
    return static_cast<id>([UIColor allocWithZone:nil]);
}

- (id)autorelease {
    return self;
}

- (id)retain {
    return self;
}

- (oneway void)release {
}

- (NSUInteger)retainCount {
    return NSUIntegerMax;
}

- (void)dealloc {
    [super dealloc];
}

@end
