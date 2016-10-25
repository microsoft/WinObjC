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
#import <CoreText/CTParagraphStyle.h>
#import <CoreText/CoreText.h>

TEST(CoreText, CTParagraphStyle) {
    CTParagraphStyleRef paragraphStyle = CTParagraphStyleCreate(nullptr, 0);
    ASSERT_TRUE_MSG(paragraphStyle != nullptr, "FAILED: Could not create paragraph style");

    CGFloat val = 2.0f;
    CTParagraphStyleSetting settings[1] = { {.spec = kCTParagraphStyleSpecifierTailIndent, .valueSize = sizeof(CGFloat), .value = &val } };
    paragraphStyle = CTParagraphStyleCreate(settings, 1);
    ASSERT_TRUE_MSG(paragraphStyle != nullptr, "FAILED: Could not create paragraph style");

    CGFloat bufferFloat;
    bool success =
        CTParagraphStyleGetValueForSpecifier(paragraphStyle, kCTParagraphStyleSpecifierTailIndent, sizeof(CGFloat), &bufferFloat);
    ASSERT_TRUE_MSG(success == true, "FAILED: Could not found the specifier that was set.");
    ASSERT_TRUE_MSG(fabs(bufferFloat - val) < 0.00001, "FAILED: Incorrect specifier value received");

    CTParagraphStyleRef paragraphStyleCopy = CTParagraphStyleCreateCopy(nil);
    ASSERT_TRUE_MSG(paragraphStyleCopy == nil, "FAILED: Incorrect copy received");

    paragraphStyleCopy = CTParagraphStyleCreateCopy(paragraphStyle);
    bufferFloat = 3.0f;
    success = CTParagraphStyleGetValueForSpecifier(paragraphStyleCopy, kCTParagraphStyleSpecifierTailIndent, sizeof(CGFloat), &bufferFloat);
    ASSERT_TRUE_MSG(success, "FAILED: Could not found the specifier that was set.");
    ASSERT_TRUE_MSG(fabs(bufferFloat - val) < 0.00001, "FAILED: Incorrect specifier value received");

    CTTextAlignment defaultTextAlignment = kCTJustifiedTextAlignment;
    val = 9.0f;
    CTParagraphStyleSetting settings2[2] = { {.spec = kCTParagraphStyleSpecifierAlignment,
                                              .valueSize = sizeof(CTTextAlignment),
                                              .value = &defaultTextAlignment },
                                             {.spec = kCTParagraphStyleSpecifierTailIndent, .valueSize = sizeof(CGFloat), .value = &val } };
    paragraphStyle = CTParagraphStyleCreate(settings2, 2);
    ASSERT_TRUE_MSG(paragraphStyle != nullptr, "FAILED: Could not create paragraph style");

    CTTextAlignment buffer;
    success = CTParagraphStyleGetValueForSpecifier(paragraphStyle, kCTParagraphStyleSpecifierAlignment, sizeof(CTTextAlignment), &buffer);
    ASSERT_TRUE_MSG(success == true, "FAILED: Could not found the specifier that was set.");
    ASSERT_TRUE_MSG(buffer == kCTJustifiedTextAlignment, "FAILED: Incorrect specifier value received");

    paragraphStyleCopy = CTParagraphStyleCreateCopy(paragraphStyle);
    success =
        CTParagraphStyleGetValueForSpecifier(paragraphStyleCopy, kCTParagraphStyleSpecifierAlignment, sizeof(CTTextAlignment), &buffer);
    ASSERT_TRUE_MSG(success, "FAILED: Could not found the specifier that was set.");
    ASSERT_TRUE_MSG(buffer == kCTJustifiedTextAlignment, "FAILED: Incorrect specifier value received");

    success = CTParagraphStyleGetValueForSpecifier(paragraphStyleCopy, kCTParagraphStyleSpecifierTailIndent, sizeof(CGFloat), &bufferFloat);
    ASSERT_TRUE_MSG(success, "FAILED: Could not find the specifier that was set");
    ASSERT_TRUE_MSG(fabs(bufferFloat - val) < 0.00001, "FAILED: Incorrect specifier value received");

    success = CTParagraphStyleGetValueForSpecifier(paragraphStyleCopy,
                                                   kCTParagraphStyleSpecifierLineHeightMultiple,
                                                   sizeof(CGFloat),
                                                   &bufferFloat);
    ASSERT_TRUE_MSG(!success, "FAILED: Incorrectly found the specifier that was not set.");
    ASSERT_TRUE_MSG(fabs(bufferFloat - 0.0f) < 0.00001, "FAILED: Incorrect specifier value received");

    success = CTParagraphStyleGetValueForSpecifier(paragraphStyleCopy,
                                                   kCTParagraphStyleSpecifierMaximumLineSpacing,
                                                   sizeof(CGFloat),
                                                   &bufferFloat);
    ASSERT_TRUE_MSG(!success, "FAILED: Incorrectly found the specifier that was not set.");
    ASSERT_TRUE_MSG(fabs(bufferFloat - 10000000.0f) < 0.00001, "FAILED: Incorrect specifier value received");

    success = CTParagraphStyleGetValueForSpecifier(paragraphStyleCopy,
                                                   kCTParagraphStyleSpecifierLineHeightMultiple,
                                                   sizeof(CGFloat),
                                                   &bufferFloat);
    ASSERT_TRUE_MSG(!success, "FAILED: Incorrectly found the specifier that was not set.");

    success = CTParagraphStyleGetValueForSpecifier(paragraphStyleCopy, 513, sizeof(CGFloat), nullptr);
    ASSERT_TRUE_MSG(!success, "FAILED: An invalid specifier crash should not occur.");
}

TEST(CoreText, KernAttribute) {
    const static float c_errorDelta = 0.001f;
    const static float c_diff = 2.0f;
    NSMutableAttributedString* string = [[[NSMutableAttributedString alloc] initWithString:@"TESTTESTTEST"] autorelease];
    [string setAttributes:@{ static_cast<NSString*>(kCTKernAttributeName) : [NSNumber numberWithFloat:0.0f] } range:NSMakeRange(0, 4)];
    [string setAttributes:@{ static_cast<NSString*>(kCTKernAttributeName) : [NSNumber numberWithFloat:c_diff] } range:NSMakeRange(4, 4)];
    [string setAttributes:@{ static_cast<NSString*>(kCTKernAttributeName) : [NSNumber numberWithFloat:-c_diff] } range:NSMakeRange(8, 4)];
    CTLineRef line = CTLineCreateWithAttributedString(static_cast<CFAttributedStringRef>(string));
    CFAutorelease(line);
    CFArrayRef runs = CTLineGetGlyphRuns(line);
    ASSERT_EQ(3, CFArrayGetCount(runs));

    CTRunRef firstRun = static_cast<CTRunRef>(CFArrayGetValueAtIndex(runs, 0));
    CTRunRef secondRun = static_cast<CTRunRef>(CFArrayGetValueAtIndex(runs, 1));
    CTRunRef thirdRun = static_cast<CTRunRef>(CFArrayGetValueAtIndex(runs, 2));

    CGSize firstAdvances[4], secondAdvances[4], thirdAdvances[4];
    CTRunGetAdvances(firstRun, { 0, 0 }, firstAdvances);
    CTRunGetAdvances(secondRun, { 0, 0 }, secondAdvances);
    CTRunGetAdvances(thirdRun, { 0, 0 }, thirdAdvances);

    EXPECT_NEAR(secondAdvances[0].width, firstAdvances[0].width + c_diff, c_errorDelta);
    EXPECT_NEAR(secondAdvances[1].width, firstAdvances[1].width + c_diff, c_errorDelta);
    EXPECT_NEAR(secondAdvances[2].width, firstAdvances[2].width + c_diff, c_errorDelta);
    EXPECT_NEAR(secondAdvances[3].width, firstAdvances[3].width + c_diff, c_errorDelta);
    EXPECT_NEAR(thirdAdvances[0].width, firstAdvances[0].width - c_diff, c_errorDelta);
    EXPECT_NEAR(thirdAdvances[1].width, firstAdvances[1].width - c_diff, c_errorDelta);
    EXPECT_NEAR(thirdAdvances[2].width, firstAdvances[2].width - c_diff, c_errorDelta);
    EXPECT_NEAR(thirdAdvances[3].width, firstAdvances[3].width - c_diff, c_errorDelta);
}