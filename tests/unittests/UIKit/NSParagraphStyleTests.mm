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

#include <TestFramework.h>
#import <Foundation/Foundation.h>
#import <CoreText/CTParagraphStyle.h>
#import <UIKit/NSMutableParagraphStyle.h>
#import "NSParagraphStyleInternal.h"
#import "Starboard/SmartTypes.h"

TEST(NSParagraphStyle, ShouldConvertToCTParagraphStyle) {
    NSMutableParagraphStyle* style = [[NSMutableParagraphStyle new] autorelease];
    style.alignment = NSTextAlignmentCenter;
    style.lineSpacing = 10.0;
    woc::unique_cf<CTParagraphStyleRef> convertedStyle{[style _convertToCTParagraphStyle] };
    CTTextAlignment alignment;
    EXPECT_TRUE(CTParagraphStyleGetValueForSpecifier(convertedStyle.get(),
                                                     kCTParagraphStyleSpecifierAlignment,
                                                     sizeof(CTTextAlignment),
                                                     &alignment));
    EXPECT_EQ(kCTCenterTextAlignment, alignment);

    CGFloat lineSpacing;
    EXPECT_TRUE(
        CTParagraphStyleGetValueForSpecifier(convertedStyle.get(), kCTParagraphStyleSpecifierLineSpacing, sizeof(CGFloat), &lineSpacing));
    EXPECT_NEAR(10.0, lineSpacing, .0001);

    CGFloat maximumLineHeight = 123545.67;
    EXPECT_TRUE(CTParagraphStyleGetValueForSpecifier(convertedStyle.get(),
                                                     kCTParagraphStyleSpecifierMaximumLineHeight,
                                                     sizeof(CGFloat),
                                                     &maximumLineHeight));
    EXPECT_NEAR(0.0, maximumLineHeight, .0001);

    NSParagraphStyle* copiedStyle = [[style copy] autorelease];
    convertedStyle.reset([copiedStyle _convertToCTParagraphStyle]);
    EXPECT_TRUE(CTParagraphStyleGetValueForSpecifier(convertedStyle.get(),
                                                     kCTParagraphStyleSpecifierAlignment,
                                                     sizeof(CTTextAlignment),
                                                     &alignment));
    EXPECT_EQ(kCTCenterTextAlignment, alignment);

    EXPECT_TRUE(
        CTParagraphStyleGetValueForSpecifier(convertedStyle.get(), kCTParagraphStyleSpecifierLineSpacing, sizeof(CGFloat), &lineSpacing));
    EXPECT_NEAR(10.0, lineSpacing, .0001);

    EXPECT_TRUE(CTParagraphStyleGetValueForSpecifier(convertedStyle.get(),
                                                     kCTParagraphStyleSpecifierMaximumLineHeight,
                                                     sizeof(CGFloat),
                                                     &maximumLineHeight));
    EXPECT_NEAR(0.0, maximumLineHeight, .0001);
}