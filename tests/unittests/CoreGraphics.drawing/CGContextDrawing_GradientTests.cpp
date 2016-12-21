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
DRAW_TEST_F(CGGradient, LinearGradient, UIKitMimicTest) {
    CGContextRef context = GetDrawingContext();

    CGFloat locations[2] = { 0, 1 };
    CGFloat components[8] = { 0.0, 0.0, 1, 1.0, 1.0, 0, 0, 1.0 };
    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGGradientRef gradient = CGGradientCreateWithColorComponents(colorspace, components, locations, 2);

    CGPoint startPoint = CGPointMake(0, 0);
    CGPoint endPoint = CGPointMake(512, 1024);

    CGContextDrawLinearGradient(context, gradient, startPoint, endPoint, kCGGradientDrawsBeforeStartLocation);
    CFRelease(colorspace);
    CFRelease(gradient);
}

static void _drawShortLinearGradientWithOptions(CGContextRef context, CGRect bounds, CGGradientDrawingOptions option) {
    CGFloat locations[2] = { 0, 1 };
    CGFloat components[8] = { 0.0, 1, 0.0, 1.0, 1.0, 0, 0, 1.0 };

    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGGradientRef gradient = CGGradientCreateWithColorComponents(colorspace, components, locations, 2);

    CGRect borderRect = CGRectInset(bounds, 30, 50);

    CGContextDrawLinearGradient(context, gradient, borderRect.origin, CGPointMake(borderRect.size.width, borderRect.size.height), option);

    CFRelease(colorspace);
    CFRelease(gradient);
}

DRAW_TEST_F(CGGradient, LinearGradientShortBothSides_Options_0, UIKitMimicTest) {
    _drawShortLinearGradientWithOptions(GetDrawingContext(), GetDrawingBounds(), 0);
}

DRAW_TEST_F(CGGradient, LinearGradientShortBothSides_Options_kCGGradientDrawsBeforeStartLocation, UIKitMimicTest) {
    _drawShortLinearGradientWithOptions(GetDrawingContext(), GetDrawingBounds(), kCGGradientDrawsBeforeStartLocation);
}

DRAW_TEST_F(CGGradient, LinearGradientShortBothSides_Options_kCGGradientDrawsAfterEndLocation, UIKitMimicTest) {
    _drawShortLinearGradientWithOptions(GetDrawingContext(), GetDrawingBounds(), kCGGradientDrawsAfterEndLocation);
}

DRAW_TEST_F(CGGradient, LinearGradientInvalidCount, UIKitMimicTest) {
    CGContextRef context = GetDrawingContext();

    CGFloat locations[] = { 0.0 };

    CGFloat components[] = {
        0.85, 0, 0, 1.0,
    };

    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGGradientRef gradient = CGGradientCreateWithColorComponents(colorspace, components, locations, 0);
    CGPoint startPoint = CGPointMake(0, 0);
    CGPoint endPoint = CGPointMake(512, 1024);

    CGContextDrawLinearGradient(context, gradient, startPoint, endPoint, kCGGradientDrawsBeforeStartLocation);
    CFRelease(colorspace);
    CFRelease(gradient);
}

DRAW_TEST_F(CGGradient, LinearGradient2, UIKitMimicTest) {
    CGContextRef context = GetDrawingContext();

    CGFloat locations[] = { 0.0, 0.33, 0.66, 1.0 };

    CGFloat components[] = {
        0.85, 0, 0, 1.0, 1, 0, 0, 1.0, 0.85, 0.3, 0, 1.0, 0.1, 0, 0.9, 1.0,
    };

    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGGradientRef gradient = CGGradientCreateWithColorComponents(colorspace, components, locations, 4);
    CGPoint startPoint = CGPointMake(0, 0);
    CGPoint endPoint = CGPointMake(512, 1024);

    CGContextDrawLinearGradient(context, gradient, startPoint, endPoint, kCGGradientDrawsBeforeStartLocation);
    CFRelease(colorspace);
    CFRelease(gradient);
}

DRAW_TEST_F(CGGradient, LinearGradient2Short, UIKitMimicTest) {
    CGContextRef context = GetDrawingContext();

    CGFloat locations[] = { 0.0, 0.33, 1.0 };

    CGFloat components[] = { 0.85, 0, 0, 1.0, 1, 0, 0, 1.0, 0.85, 0.3, 0, 1.0 };

    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGGradientRef gradient = CGGradientCreateWithColorComponents(colorspace, components, locations, 3);
    CGPoint startPoint = CGPointMake(120, 200);
    CGPoint endPoint = CGPointMake(350, 800);

    CGContextDrawLinearGradient(context, gradient, startPoint, endPoint, kCGGradientDrawsBeforeStartLocation);
    CFRelease(colorspace);
    CFRelease(gradient);
}

DRAW_TEST_F(CGGradient, LinearGradient3, UIKitMimicTest) {
    CGContextRef context = GetDrawingContext();

    CGFloat locations[] = { 0.0, 0.5, 1 };

    CGFloat components[] = {
        1, 0, 0, 1.0, 0, 1, 0, 1.0, 0, 0, 1, 1.0,
    };

    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGGradientRef gradient = CGGradientCreateWithColorComponents(colorspace, components, locations, 3);
    CGPoint startPoint = CGPointMake(0, 0);
    CGPoint endPoint = CGPointMake(512, 1024);

    CGContextDrawLinearGradient(context, gradient, startPoint, endPoint, kCGGradientDrawsBeforeStartLocation);
    CFRelease(colorspace);
    CFRelease(gradient);
}

DRAW_TEST_F(CGGradient, LinearGradientWithLowOpacity, UIKitMimicTest) {
    CGContextRef context = GetDrawingContext();

    CGFloat locations[] = { 0.0, 0.5, 1 };

    CGFloat components[] = {
        1, 0, 0, 0.1, 0, 1, 0, 0.9, 0, 0, 1, 0.8,
    };

    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGGradientRef gradient = CGGradientCreateWithColorComponents(colorspace, components, locations, 3);
    CGPoint startPoint = CGPointMake(300, 750);
    CGPoint endPoint = CGPointMake(0, 0);

    CGContextDrawLinearGradient(context, gradient, startPoint, endPoint, kCGGradientDrawsBeforeStartLocation);
    CFRelease(colorspace);
    CFRelease(gradient);
}

DRAW_TEST_F(CGGradient, LinearGradientWithAlpha, UIKitMimicTest) {
    CGContextRef context = GetDrawingContext();

    CGFloat locations[] = { 0.0, 0.25, 0.5, 0.6, 0.8, 0.9, 1 };

    CGFloat components[] = {
        1, 0, 0, 1, 0.4, 0.1, 0.5, 1, 0.50, 0.2, 0.99, 1, 0.41, 0.56, 0, 1, 0.12, 0.12, .3, 1, 0.9, 0.4, 1, 1, 0.2, 0.3, 0.8, 1,
    };

    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGGradientRef gradient = CGGradientCreateWithColorComponents(colorspace, components, locations, 7);
    CGPoint startPoint = CGPointMake(512, 1024);
    CGPoint endPoint = CGPointMake(0, 0);

    CGContextSetAlpha(context, 0.75);
    CGContextDrawLinearGradient(context, gradient, startPoint, endPoint, kCGGradientDrawsBeforeStartLocation);
    CFRelease(colorspace);
    CFRelease(gradient);
}

DRAW_TEST_F(CGGradient, LinearGradientWithLowOpacityShort, UIKitMimicTest) {
    CGContextRef context = GetDrawingContext();

    CGFloat locations[] = { 0.0, 0.5, 1 };

    CGFloat components[] = {
        1, 0, 0, 0.8, 0, 1, 0, 0.9, 0, 0, 1, 0.1,
    };

    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGGradientRef gradient = CGGradientCreateWithColorComponents(colorspace, components, locations, 3);
    CGPoint startPoint = CGPointMake(250, 300);
    CGPoint endPoint = CGPointMake(0, 0);
    CGContextDrawLinearGradient(context, gradient, startPoint, endPoint, kCGGradientDrawsAfterEndLocation);

    CFRelease(colorspace);
    CFRelease(gradient);
}

#pragma endregion LinearGradient