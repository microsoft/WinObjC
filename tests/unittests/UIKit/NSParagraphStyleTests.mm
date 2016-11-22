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

static constexpr double c_errorDelta = .0001;

TEST(NSParagraphStyle, ShouldConvertToCTParagraphStyle) {
    NSMutableParagraphStyle* style = [[NSMutableParagraphStyle new] autorelease];
    style.alignment = NSTextAlignmentCenter;
    style.lineSpacing = 10.0;
    woc::unique_cf<CTParagraphStyleRef> convertedStyle{[style _createCTParagraphStyle] };
    CTTextAlignment alignment;
    EXPECT_TRUE(CTParagraphStyleGetValueForSpecifier(convertedStyle.get(),
                                                     kCTParagraphStyleSpecifierAlignment,
                                                     sizeof(CTTextAlignment),
                                                     &alignment));
    EXPECT_EQ(kCTCenterTextAlignment, alignment);

    CGFloat lineSpacing;
    EXPECT_TRUE(
        CTParagraphStyleGetValueForSpecifier(convertedStyle.get(), kCTParagraphStyleSpecifierLineSpacing, sizeof(CGFloat), &lineSpacing));
    EXPECT_NEAR(10.0, lineSpacing, c_errorDelta);

    CGFloat maximumLineHeight = 123545.67;
    EXPECT_TRUE(CTParagraphStyleGetValueForSpecifier(convertedStyle.get(),
                                                     kCTParagraphStyleSpecifierMaximumLineHeight,
                                                     sizeof(CGFloat),
                                                     &maximumLineHeight));
    EXPECT_NEAR(0.0, maximumLineHeight, c_errorDelta);

    NSParagraphStyle* copiedStyle = [[style copy] autorelease];
    convertedStyle.reset([copiedStyle _createCTParagraphStyle]);
    EXPECT_TRUE(CTParagraphStyleGetValueForSpecifier(convertedStyle.get(),
                                                     kCTParagraphStyleSpecifierAlignment,
                                                     sizeof(CTTextAlignment),
                                                     &alignment));
    EXPECT_EQ(kCTCenterTextAlignment, alignment);

    EXPECT_TRUE(
        CTParagraphStyleGetValueForSpecifier(convertedStyle.get(), kCTParagraphStyleSpecifierLineSpacing, sizeof(CGFloat), &lineSpacing));
    EXPECT_NEAR(10.0, lineSpacing, c_errorDelta);

    EXPECT_TRUE(CTParagraphStyleGetValueForSpecifier(convertedStyle.get(),
                                                     kCTParagraphStyleSpecifierMaximumLineHeight,
                                                     sizeof(CGFloat),
                                                     &maximumLineHeight));
    EXPECT_NEAR(0.0, maximumLineHeight, c_errorDelta);
}

TEST(NSParagraphStyle, CopyShouldBeImmutable) {
    NSMutableParagraphStyle* style = [[NSMutableParagraphStyle new] autorelease];
    style.alignment = NSTextAlignmentCenter;
    style.lineSpacing = 10.0;
    id copiedStyle = [[style copy] autorelease];
    EXPECT_ANY_THROW([copiedStyle setParagraphStyle:style]);

    style.lineSpacing = 20.0;
    EXPECT_NEAR(10.0, [copiedStyle lineSpacing], c_errorDelta);
}