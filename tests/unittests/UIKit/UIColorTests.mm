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

#include <TestFramework.h>
#import <UIKit/UIColor.h>

TEST(UIColor, ColorTests) {
    UIColor* color = [UIColor redColor];
    UIColor* color2 = [UIColor colorWithRed:1 green:0 blue:0 alpha:1];
    EXPECT_OBJCEQ(color, color2);

    color = [UIColor blackColor];
    color2 = [UIColor colorWithWhite:0 alpha:1];
    EXPECT_OBJCEQ(color, color2);

    color = [UIColor blackColor];
    color2 = [UIColor colorWithRed:0 green:0 blue:0 alpha:1];
    EXPECT_OBJCNE(color, color2);
}

static void __EncodeAndDecodeColor(UIColor* color) {
    NSMutableData* data = [NSMutableData data];

    StrongId<NSKeyedArchiver> coder{ woc::TakeOwnership, [[NSKeyedArchiver alloc] initForWritingWithMutableData:data] };
    [color encodeWithCoder:coder];
    [coder finishEncoding];

    StrongId<NSKeyedUnarchiver> decoder{ woc::TakeOwnership, [[NSKeyedUnarchiver alloc] initForReadingWithData:data] };
    StrongId<UIColor> decodedColor{ woc::TakeOwnership, [[UIColor alloc] initWithCoder:decoder] };
    EXPECT_OBJCEQ(color, decodedColor);
}

TEST(UIColor, EncodeDecodeUIColor) {
    // GrayScale
    __EncodeAndDecodeColor([UIColor grayColor]);
    __EncodeAndDecodeColor([UIColor colorWithWhite:0.5 alpha:0.98]);
    __EncodeAndDecodeColor([UIColor colorWithWhite:0 alpha:1]);
    __EncodeAndDecodeColor([UIColor colorWithWhite:1 alpha:1]);

    // RGB
    __EncodeAndDecodeColor([UIColor redColor]);
    __EncodeAndDecodeColor([UIColor colorWithRed:1 green:0.5 blue:0.34 alpha:0.89]);
    __EncodeAndDecodeColor([UIColor colorWithRed:1 green:0.4 blue:0.34 alpha:1.0]);
}

TEST(UIColor, ColorWithCGColor) {
    CGColorRef cgColor = CGColorGetConstantColor(kCGColorBlack);
    UIColor* blackColor = [UIColor blackColor];
    // NOTE: you should never cast CGColor into a UIColor or vice versa
    // This is only to support CoreText related attribute functionality
    EXPECT_OBJCEQ(static_cast<UIColor*>(cgColor), blackColor);
    EXPECT_TRUE(CGColorEqualToColor(static_cast<CGColorRef>(blackColor), cgColor));

    UIColor* color1 = [UIColor colorWithCGColor:cgColor];
    EXPECT_OBJCEQ(color1, blackColor);

    color1 = [UIColor colorWithCGColor:[blackColor CGColor]];
    EXPECT_OBJCEQ(color1, blackColor);

    color1 = [UIColor colorWithCGColor:[[UIColor yellowColor] CGColor]];
    EXPECT_OBJCEQ(color1, [UIColor yellowColor]);

    auto cgColorRed = woc::MakeStrongCF<CGColorRef>(CGColorCreateGenericRGB(1, 0, 0, 1));
    color1 = [UIColor colorWithCGColor:cgColorRed];
    EXPECT_OBJCEQ(color1, [UIColor redColor]);
    EXPECT_OBJCEQ(color1, [UIColor colorWithRed:1 green:0 blue:0 alpha:1]);

    auto cgColorGray = woc::MakeStrongCF<CGColorRef>(CGColorCreateGenericGray(0.5, 1));
    color1 = [UIColor colorWithCGColor:cgColorGray];
    EXPECT_OBJCEQ(color1, [UIColor grayColor]);
    EXPECT_OBJCNE(color1, [UIColor colorWithRed:1 green:0 blue:0 alpha:1]);
    EXPECT_OBJCEQ(color1, [UIColor colorWithWhite:0.5 alpha:1]);
}

TEST(UIColor, SameColorInDifferentColorSpaces) {
    EXPECT_OBJCNE([UIColor colorWithWhite:0.5 alpha:1], [UIColor colorWithRed:0.5 green:0.5 blue:0.5 alpha:1]);
}