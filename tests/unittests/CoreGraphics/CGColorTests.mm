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

#import <TestFramework.h>
#import <CoreGraphics/CoreGraphics.h>

// TODO #2243: Remove the UIKit dependency
#if WINOBJC
#include <UIKit/UIColor.h>
#endif

#define EXPECT_EQ_COMPONENTS(a, b) \
    EXPECT_EQ((a)[0], (b)[0]);     \
    EXPECT_EQ((a)[1], (b)[1]);     \
    EXPECT_EQ((a)[2], (b)[2]);     \
    EXPECT_EQ((a)[3], (b)[3])

TEST(CGColor, CGColorGetComponents) {
#if WINOBJC
    [UIColor class];
#endif
    CGFloat colors[] = { 1, 0, 0, 1 }; // bright red

    CGColorSpaceRef clrRgb = CGColorSpaceCreateDeviceRGB();
    CGColorRef clr = CGColorCreate(clrRgb, colors);
    CGColorRef copy = CGColorCreateCopyWithAlpha(clr, 0.5); // transparent red

    EXPECT_EQ(CGColorSpaceGetModel(clrRgb), CGColorSpaceGetModel(CGColorGetColorSpace(copy)));
    EXPECT_EQ(CGColorSpaceGetModel(clrRgb), CGColorSpaceGetModel(CGColorGetColorSpace(clr)));

    EXPECT_EQ(4, CGColorGetNumberOfComponents(clr));
    EXPECT_EQ(4, CGColorGetNumberOfComponents(copy));

    const CGFloat* components = CGColorGetComponents(copy);
    CGFloat expected[] = { 1, 0, 0, 0.5 };
    EXPECT_EQ_COMPONENTS(components, expected);

    components = CGColorGetComponents(clr);
    EXPECT_EQ_COMPONENTS(components, colors);

    CGColorRelease(clr);
    CGColorRelease(copy);
    CGColorSpaceRelease(clrRgb);
}

TEST(CGColor, CGColorEquals) {
#if WINOBJC
    [UIColor class];
#endif

    CGFloat colors[] = { 1, 0, 0, 1 }; // bright red

    CGColorSpaceRef clrRgb = CGColorSpaceCreateDeviceRGB();
    CGColorRef clr1 = CGColorCreate(clrRgb, colors);
    CGColorRef clr2 = CGColorCreateCopy(clr1);
    CGColorRef clr3 = CGColorCreateCopyWithAlpha(clr1, 0.9);
    CGColorRef clr4 = CGColorCreate(clrRgb, colors);

    EXPECT_EQ(CGColorSpaceGetModel(clrRgb), CGColorSpaceGetModel(CGColorGetColorSpace(clr1)));
    EXPECT_EQ(CGColorSpaceGetModel(clrRgb), CGColorSpaceGetModel(CGColorGetColorSpace(clr2)));
    EXPECT_EQ(CGColorSpaceGetModel(clrRgb), CGColorSpaceGetModel(CGColorGetColorSpace(clr3)));
    EXPECT_EQ(CGColorSpaceGetModel(clrRgb), CGColorSpaceGetModel(CGColorGetColorSpace(clr4)));

    EXPECT_EQ(4, CGColorGetNumberOfComponents(clr1));
    EXPECT_EQ(4, CGColorGetNumberOfComponents(clr2));
    EXPECT_EQ(4, CGColorGetNumberOfComponents(clr3));
    EXPECT_EQ(4, CGColorGetNumberOfComponents(clr4));

    EXPECT_TRUE(CGColorEqualToColor(clr1, clr1));
    EXPECT_TRUE(CGColorEqualToColor(clr1, clr2));
    EXPECT_TRUE(CGColorEqualToColor(clr1, clr4));
    EXPECT_FALSE(CGColorEqualToColor(clr1, clr3));

    CGColorRelease(clr1);
    CGColorRelease(clr2);
    CGColorRelease(clr3);
    CGColorRelease(clr4);
    CGColorSpaceRelease(clrRgb);
}

TEST(CGColor, GetColorSpace) {
#if WINOBJC
    [UIColor class];
#endif
    CGFloat colors[] = { 1, 0, 0, 1 }; // bright red

    CGColorSpaceRef clrRgb = CGColorSpaceCreateDeviceRGB();
    CGColorRef clr1 = CGColorCreate(clrRgb, colors);
    CGColorRef clr2 = CGColorCreateCopy(clr1);
    CGColorRef clr3 = CGColorCreateCopyWithAlpha(clr1, 0.9);
    CGColorRef clr4 = CGColorCreate(clrRgb, colors);

    EXPECT_TRUE(CGColorEqualToColor(clr1, clr1));
    EXPECT_TRUE(CGColorEqualToColor(clr1, clr2));
    EXPECT_TRUE(CGColorEqualToColor(clr1, clr4));
    EXPECT_FALSE(CGColorEqualToColor(clr1, clr3));

    CGColorRelease(clr1);
    CGColorRelease(clr2);
    CGColorRelease(clr3);
    CGColorRelease(clr4);
    CGColorSpaceRelease(clrRgb);
}

TEST(CGColor, GetConstantColor) {
#if WINOBJC
    [UIColor class];
#endif
    auto grayColorSpace = woc::MakeStrongCF<CGColorSpaceRef>(CGColorSpaceCreateDeviceGray());

    CFStringRef colors[] = { kCGColorWhite, kCGColorBlack, kCGColorClear };

    for (int i = 0; i < std::extent<decltype(colors)>::value; ++i) {
        CGColorRef col = CGColorGetConstantColor(colors[i]);
        EXPECT_EQ(CGColorSpaceGetModel(grayColorSpace), CGColorSpaceGetModel(CGColorGetColorSpace(col)));
        EXPECT_EQ(2, CGColorGetNumberOfComponents(col));
    }
}
