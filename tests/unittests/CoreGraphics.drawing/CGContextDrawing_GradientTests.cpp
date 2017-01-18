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

#include "DrawingTest.h"

#pragma region LinearGradient

static void _drawLinearGradient(CGContextRef context,
                                CGPoint startPoint,
                                CGPoint endPoint,
                                CGFloat components[],
                                CGFloat locations[],
                                CGGradientDrawingOptions options) {
    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGGradientRef gradient =
        CGGradientCreateWithColorComponents(colorspace, components, locations, std::extent<decltype(locations)>::value);

    CGContextDrawLinearGradient(context, gradient, startPoint, endPoint, options);
    CFRelease(colorspace);
    CFRelease(gradient);
}

static void _drawShortLinearGradientWithOptions(CGContextRef context, CGRect bounds, CGGradientDrawingOptions option) {
    CGFloat locations[2] = { 0, 1 };
    CGFloat components[8] = { 0.0, 1, 0.0, 1.0, 1.0, 0, 0, 1.0 };

    CGRect borderRect = CGRectInset(bounds, 30, 50);

    _drawLinearGradient(context,
                        borderRect.origin,
                        CGPointMake(borderRect.size.width, borderRect.size.height),
                        components,
                        locations,
                        option);
}

DISABLED_DRAW_TEST_F(CGGradient, LinearGradient, UIKitMimicTest<>) {
    CGFloat locations[2] = { 0, 1 };
    CGFloat components[8] = { 0.0, 0.0, 1, 1.0, 1.0, 0, 0, 1.0 };
    _drawLinearGradient(GetDrawingContext(),
                        CGPointMake(0, 0),
                        CGPointMake(512, 1024),
                        components,
                        locations,
                        kCGGradientDrawsBeforeStartLocation);
}

DISABLED_DRAW_TEST_F(CGGradient, LinearGradientShortBothSides_Options_0, UIKitMimicTest<>) {
    _drawShortLinearGradientWithOptions(GetDrawingContext(), GetDrawingBounds(), 0);
}

DISABLED_DRAW_TEST_F(CGGradient, LinearGradientShortBothSides_Options_kCGGradientDrawsBeforeStartLocation, UIKitMimicTest<>) {
    _drawShortLinearGradientWithOptions(GetDrawingContext(), GetDrawingBounds(), kCGGradientDrawsBeforeStartLocation);
}

DISABLED_DRAW_TEST_F(CGGradient, LinearGradientShortBothSides_Options_kCGGradientDrawsAfterEndLocation, UIKitMimicTest<>) {
    _drawShortLinearGradientWithOptions(GetDrawingContext(), GetDrawingBounds(), kCGGradientDrawsAfterEndLocation);
}

DRAW_TEST_F(CGGradient, LinearGradientInvalidCount, UIKitMimicTest<>) {
    CGFloat locations[] = { 0.0 };

    CGFloat components[] = {
        0.85, 0, 0, 1.0,
    };

    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGGradientRef gradient = CGGradientCreateWithColorComponents(colorspace, components, locations, 0);

    CGContextDrawLinearGradient(GetDrawingContext(),
                                gradient,
                                CGPointMake(0, 0),
                                CGPointMake(512, 1024),
                                kCGGradientDrawsBeforeStartLocation);
    CFRelease(colorspace);
    CFRelease(gradient);
}

DISABLED_DRAW_TEST_F(CGGradient, LinearGradient2, UIKitMimicTest<>) {
    CGFloat locations[] = { 0.0, 0.33, 0.66, 1.0 };

    CGFloat components[] = {
        0.85, 0, 0, 1.0, 1, 0, 0, 1.0, 0.85, 0.3, 0, 1.0, 0.1, 0, 0.9, 1.0,
    };

    _drawLinearGradient(GetDrawingContext(),
                        CGPointMake(0, 0),
                        CGPointMake(512, 1024),
                        components,
                        locations,
                        kCGGradientDrawsBeforeStartLocation);
}

DISABLED_DRAW_TEST_F(CGGradient, LinearGradient2Short, UIKitMimicTest<>) {
    CGFloat locations[] = { 0.0, 0.33, 1.0 };

    CGFloat components[] = { 0.85, 0, 0, 1.0, 1, 0, 0, 1.0, 0.85, 0.3, 0, 1.0 };
    _drawLinearGradient(GetDrawingContext(),
                        CGPointMake(120, 200),
                        CGPointMake(350, 800),
                        components,
                        locations,
                        kCGGradientDrawsBeforeStartLocation);
}

DISABLED_DRAW_TEST_F(CGGradient, LinearGradient3, UIKitMimicTest<>) {
    CGFloat locations[] = { 0.0, 0.5, 1 };

    CGFloat components[] = {
        1, 0, 0, 1.0, 0, 1, 0, 1.0, 0, 0, 1, 1.0,
    };
    _drawLinearGradient(GetDrawingContext(),
                        CGPointMake(0, 0),
                        CGPointMake(512, 1024),
                        components,
                        locations,
                        kCGGradientDrawsBeforeStartLocation);
}

DISABLED_DRAW_TEST_F(CGGradient, LinearGradientWithLowOpacity, UIKitMimicTest<>) {
    CGFloat locations[] = { 0.0, 0.5, 1 };

    CGFloat components[] = {
        1, 0, 0, 0.1, 0, 1, 0, 0.9, 0, 0, 1, 0.8,
    };

    _drawLinearGradient(GetDrawingContext(),
                        CGPointMake(300, 750),
                        CGPointMake(0, 0),
                        components,
                        locations,
                        kCGGradientDrawsBeforeStartLocation);
}

DISABLED_DRAW_TEST_F(CGGradient, LinearGradientWithAlpha, UIKitMimicTest<>) {
    CGFloat locations[] = { 0.0, 0.25, 0.5, 0.6, 0.8, 0.9, 1 };

    CGFloat components[] = {
        1, 0, 0, 1, 0.4, 0.1, 0.5, 1, 0.50, 0.2, 0.99, 1, 0.41, 0.56, 0, 1, 0.12, 0.12, .3, 1, 0.9, 0.4, 1, 1, 0.2, 0.3, 0.8, 1,
    };

    CGContextSetAlpha(GetDrawingContext(), 0.75);
    _drawLinearGradient(GetDrawingContext(),
                        CGPointMake(0, 0),
                        CGPointMake(512, 1024),
                        components,
                        locations,
                        kCGGradientDrawsBeforeStartLocation);
}

DISABLED_DRAW_TEST_F(CGGradient, LinearGradientWithLowOpacityShort, UIKitMimicTest<>) {
    CGFloat locations[] = { 0.0, 0.5, 1 };

    CGFloat components[] = {
        1, 0, 0, 0.8, 0, 1, 0, 0.9, 0, 0, 1, 0.1,
    };

    _drawLinearGradient(GetDrawingContext(),
                        CGPointMake(250, 300),
                        CGPointMake(0, 0),
                        components,
                        locations,
                        kCGGradientDrawsAfterEndLocation);
}

#pragma endregion LinearGradient