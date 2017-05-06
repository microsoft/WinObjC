//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

#import <StubReturn.h>
#import <Starboard.h>
#import <NSRaise.h>
#import <UIKit/UIColor.h>
#import <UIKit/UIGraphics.h>
#import <UIKit/UIImage.h>
#import <UIKit/UIView.h>

#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGAffineTransform.h>
#import <CoreGraphics/CGPattern.h>

#import <Foundation/NSString.h>
#import <Foundation/NSMutableDictionary.h>

#import "CGContextInternal.h"
#import "CGPatternInternal.h"
#import "UIColorInternal.h"
#import "UICGColor.h"

#import <math.h>
#import <LoggingNative.h>
#import <BridgeHelpers.h>
#import "CGColorInternal.h"

static const wchar_t* TAG = L"UIColor";

@implementation UIColor

BASE_CLASS_REQUIRED_IMPLS(UIColor, UICGColorPrototype, CGColorGetTypeID);

/**
 @Status Interoperable
*/
+ (UIColor*)colorWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a {
    return [[[self alloc] initWithRed:r green:g blue:b alpha:a] autorelease];
}

/**
 @Status Interoperable
*/
+ (UIColor*)colorWithHue:(CGFloat)h saturation:(CGFloat)s brightness:(CGFloat)v alpha:(CGFloat)a {
    return [[[self alloc] initWithHue:h saturation:s brightness:v alpha:a] autorelease];
}

/**
 @Status Interoperable
*/
+ (UIColor*)colorWithWhite:(CGFloat)gray alpha:(CGFloat)alpha {
    return [[[self alloc] initWithWhite:gray alpha:alpha] autorelease];
}

/**
 @Status Interoperable
*/
+ (UIColor*)colorWithPatternImage:(UIImage*)image {
    return [[[self alloc] initWithPatternImage:image] autorelease];
}

/**
 @Status Interoperable
*/
+ (UIColor*)colorWithCGColor:(CGColorRef)clr {
    return [[[self alloc] initWithCGColor:clr] autorelease];
}

/**
 @Status Interoperable
*/
- (CGColorRef)CGColor {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Stub
*/
- (instancetype)initWithCGColor:(CGColorRef)cgColor {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)initWithHue:(CGFloat)h saturation:(CGFloat)s brightness:(CGFloat)v alpha:(CGFloat)a {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)initWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)initWithWhite:(CGFloat)gray alpha:(CGFloat)alpha {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)initWithPatternImage:(UIImage*)image {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Stub
*/
- (instancetype)initWithCIColor:(CIColor*)ciColor {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (UIColor*)colorWithAlphaComponent:(CGFloat)alpha {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (void)set {
    NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)setFill {
    NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)setStroke {
    NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
+ (UIColor*)groupTableViewBackgroundColor {
    return [self colorWithRed:197.f / 255.f green:204.f / 255.f blue:210.f / 255.f alpha:1.0f];
}

/**
 @Status Stub
*/
+ (UIColor*)viewFlipsideBackgroundColor {
    return [self whiteColor];
}

/**
 @Status Stub
*/
+ (UIColor*)windowsControlFocusedColor {
    return [self colorWithRed:0.19f green:0.46f blue:0.73f alpha:1.0f];
}

/**
 @Status Stub
*/
+ (UIColor*)windowsControlDefaultBackgroundColor {
    return [self colorWithRed:0.95f green:0.95f blue:0.95f alpha:1.0f];
}

+ (UIColor*)_windowsTableViewCellSelectionBackgroundColor {
    return [self colorWithRed:0.63 green:0.79 blue:0.89 alpha:1.0];
}

/**
 @Status Stub
*/
+ (UIColor*)windowsTableViewSelectionBackgroundColor {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (BOOL)getHue:(CGFloat*)h saturation:(CGFloat*)s brightness:(CGFloat*)v alpha:(CGFloat*)a {
    CGColorRef cgColor = [self CGColor];
    RETURN_RESULT_IF(!cgColor, NO);

    const CGFloat* components = CGColorGetComponents(cgColor);
    RETURN_RESULT_IF(components == nullptr, NO);

    hsv out;
    rgb in;

    in.r = components[0];
    in.b = components[1];
    in.g = components[2];

    out = rgb2hsv(in);

    if (h) {
        *h = (CGFloat)(out.h / 360.0);
    }
    if (s) {
        *s = (CGFloat)out.s;
    }
    if (v) {
        *v = (CGFloat)out.v;
    }
    if (a) {
        *a = components[3];
    }

    return YES;
}

/**
@Status Caveat
@Notes only supports grayscale colorspace
*/
- (BOOL)getWhite:(CGFloat*)white alpha:(CGFloat*)alpha {
    CGColorRef cgColor = [self CGColor];
    RETURN_RESULT_IF(!cgColor, NO);

    const CGFloat* components = CGColorGetComponents(cgColor);
    RETURN_RESULT_IF(components == nullptr, NO);
    if (white) {
        *white = components[0];
    }
    if (alpha) {
        *alpha = components[3];
    }

    return YES;
}

/**
 @Status Interoperable
*/
- (BOOL)getRed:(CGFloat*)r green:(CGFloat*)g blue:(CGFloat*)b alpha:(CGFloat*)a {
    CGColorRef cgColor = [self CGColor];
    RETURN_RESULT_IF(!cgColor, NO);

    const CGFloat* components = CGColorGetComponents(cgColor);
    RETURN_RESULT_IF(components == nullptr, NO);
    if (r) {
        *r = components[0];
    }
    if (g) {
        *g = components[1];
    }
    if (b) {
        *b = components[2];
    }
    if (a) {
        *a = components[3];
    }

    return YES;
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(UIColor*)other {
    if (![other isKindOfClass:[UIColor class]]) {
        return NO;
    }

    CGColorRef cgColor = [self CGColor];
    CGColorRef otherCGColor = [other CGColor];
    if (cgColor == otherCGColor) {
        return YES;
    }

    if (CFEqual(cgColor, otherCGColor)) {
        return YES;
    }

    return NO;
}

/**
 @Status Stub
*/
+ (UIColor*)colorWithCIColor:(CIColor*)ciColor {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
+ (UIColor*)scrollViewTexturedBackgroundColor {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
+ (UIColor*)underPageBackgroundColor {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Stub
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Only supports non-pattern color in grayscale and RGB
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    NSString* pattern = [coder decodeObjectForKey:@"UIPatternSelector"];
    if (pattern == nil) {
        pattern = [coder decodeObjectForKey:@"UISystemColorName"];
    }

    if (pattern != nil) {
        const char* pPattern = [pattern UTF8String];
        TraceVerbose(TAG, L"Selecting pattern %hs", pPattern);

        return [[[self class] performSelector:NSSelectorFromString(pattern)] retain];
    } else {
        CGFloat alpha = ([coder containsValueForKey:@"UIAlpha"]) ? [coder decodeFloatForKey:@"UIAlpha"] : 1.0f;
        if ([coder containsValueForKey:@"UIWhite"]) {
            return [self initWithWhite:[coder decodeFloatForKey:@"UIWhite"] alpha:alpha];
        }
        return [self initWithRed:[coder decodeFloatForKey:@"UIRed"]
                           green:[coder decodeFloatForKey:@"UIGreen"]
                            blue:[coder decodeFloatForKey:@"UIBlue"]
                           alpha:alpha];
    }

    return nullptr;
}

/**
 @Status Caveat
 @Notes Only supports non-pattern color in grayscale and RGB
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    CGColorRef cgColor = [self CGColor];
    if (CGColorGetPattern(cgColor) == nullptr) {
        const CGFloat* components = CGColorGetComponents(cgColor);
        RETURN_IF(components == nullptr);

        if (CGColorSpaceGetModel(CGColorGetColorSpace(cgColor)) == kCGColorSpaceModelMonochrome) {
            [coder encodeFloat:components[0] forKey:@"UIWhite"];
        } else {
            [coder encodeFloat:components[0] forKey:@"UIRed"];
            [coder encodeFloat:components[1] forKey:@"UIGreen"];
            [coder encodeFloat:components[2] forKey:@"UIBlue"];
        }

        [coder encodeFloat:components[3] forKey:@"UIAlpha"];
    }
}

#pragma region PreDefinedColor

/**
@Status Interoperable
*/
+ (UIColor*)blackColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithWhite:0.0f alpha:1.0f] };
    return color;
}

/**
@Status Interoperable
*/
+ (UIColor*)blueColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithRed:0.0f green:0.0f blue:1.0f alpha:1.0f] };
    return color;
}

/**
@Status Interoperable
*/
+ (UIColor*)brownColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithRed:0.65f green:0.35f blue:0.0f alpha:1.0f] };
    return color;
}

/**
@Status Interoperable
*/
+ (UIColor*)clearColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithWhite:0.0f alpha:0.0f] };
    return color;
}

/**
@Status Interoperable
*/
+ (UIColor*)cyanColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithRed:0.0f green:1.0f blue:1.0f alpha:1.0f] };
    return color;
}

/**
@Status Interoperable
*/
+ (UIColor*)darkGrayColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithRed:0.25f green:0.25f blue:0.25f alpha:1.0f] };
    return color;
}

/**
@Status Interoperable
*/
+ (UIColor*)greenColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithRed:0.0f green:1.0f blue:0.0f alpha:1.0f] };
    return color;
}

/**
@Status Interoperable
*/
+ (UIColor*)lightGrayColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithRed:0.75f green:0.75f blue:0.75f alpha:1.0f] };
    return color;
}

/**
@Status Interoperable
*/
+ (UIColor*)magentaColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithRed:1.0f green:0.0f blue:1.0f alpha:1.0f] };
    return color;
}

/**
@Status Interoperable
*/
+ (UIColor*)orangeColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithRed:1.0f green:0.5f blue:0.0f alpha:1.0f] };
    return color;
}

/**
@Status Interoperable
*/
+ (UIColor*)purpleColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithRed:0.7f green:0.2f blue:0.9f alpha:1.0f] };
    return color;
}

/**
@Status Interoperable
*/
+ (UIColor*)redColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithRed:1.0f green:0.0f blue:0.0f alpha:1.0f] };
    return color;
}

/**
@Status Interoperable
*/
+ (UIColor*)whiteColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithWhite:1.0f alpha:1.0f] };
    return color;
}

/**
@Status Interoperable
*/
+ (UIColor*)yellowColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithRed:1.0f green:1.0f blue:0.0f alpha:1.0f] };
    return color;
}

/**
@Status Interoperable
*/
+ (UIColor*)cornflowerBlueColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithRed:0.0f green:0.737f blue:0.949f alpha:1.0f] };
    return color;
}

/**
@Status Interoperable
*/
+ (UIColor*)grayColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithWhite:0.5f alpha:1.0f] };
    return color;
}

#pragma endregion PreDefinedColor

#pragma region SystemColor

/**
@Status Interoperable
*/
+ (UIColor*)lightTextColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithWhite:0.75f alpha:1.0f] };
    return color;
}

/**
@Status Interoperable
*/
+ (UIColor*)darkTextColor {
    static StrongId<UIColor> color{ [_UIColorConcreteConst colorWithWhite:0.0f alpha:1.0f] };
    return color;
}

#pragma endregion SystemColor

@end