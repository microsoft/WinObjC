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
#include "Starboard.h"
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreText/CoreText.h>
#import <CoreFoundation/CFAttributedString.h>

#include <functional>

bool isValid(double testValue, double expectedValue, double delta) {
    double upperBound = testValue + delta;
    double lowerBound = testValue - delta;
    return ((expectedValue <= upperBound) && (expectedValue >= lowerBound));
}

NSAttributedString* getString() {
    UIFontDescriptor* fontDescriptor = [UIFontDescriptor fontDescriptorWithName:@"Times New Roman" size:40];
    UIFont* font = [UIFont fontWithDescriptor:fontDescriptor size:40];

    NSRange wholeRange = NSMakeRange(0, 5);
    NSMutableAttributedString* string = [[NSMutableAttributedString alloc] initWithString:@"hello"];
    [string addAttribute:NSForegroundColorAttributeName value:[UIColor redColor] range:wholeRange];
    [string addAttribute:NSFontAttributeName value:font range:wholeRange];
    [string addAttribute:@"testKey" value:[UIColor blueColor] range:wholeRange];

    return string;
}

class TypographicBounds : public ::testing::TestWithParam<::testing::tuple<std::function<CFRange(CFRange)>, double>> {
public:
    explicit TypographicBounds()
        : _frameRef(nullptr),
          _framesetter(nullptr),
          _pathRef(nullptr),
          _attributedStringRef(nullptr),
          _textLength(0),
          _run(nullptr),
          _runRange{ 0, 0 },
          ::testing::TestWithParam<::testing::tuple<std::function<CFRange(CFRange)>, double>>() {
    }

protected:
    virtual void SetUp() {
        _textLength = CFStringGetLength((CFStringRef)c_testString);
        CFRange currentRange = CFRangeMake(0, _textLength);

        _attributedStringRef = static_cast<CFAttributedStringRef>([[NSMutableAttributedString alloc] initWithString:c_testString]);

        UIFont* font = [UIFont fontWithName:@"SegoeUI" size:12.0];
        ASSERT_TRUE_MSG(font != nullptr, "FAILED: Font not available!");

        CTFontRef fontRef = CTFontCreateWithName(static_cast<CFStringRef>(font.fontName), font.pointSize, NULL);
        ASSERT_TRUE_MSG(fontRef != nullptr, "FAILED: Could not create font!");

        CFAttributedStringSetAttribute(const_cast<__CFAttributedString*>(_attributedStringRef),
                                       currentRange,
                                       kCTFontAttributeName,
                                       fontRef);
        _framesetter = CTFramesetterCreateWithAttributedString(_attributedStringRef);
        ASSERT_TRUE_MSG(_framesetter != nullptr, "FAILED: Could not create frame setter!");

        CGRect frameRect = CGRectMake(0, 0, 80, 80);
        CGPathRef _pathRef = CGPathCreateWithRect(frameRect, NULL);
        CTFrameRef _frameRef = CTFramesetterCreateFrame(_framesetter, currentRange, _pathRef, NULL);
        CFArrayRef lines = CTFrameGetLines(_frameRef);

        const __CTLine* line = static_cast<const __CTLine*>(CFArrayGetValueAtIndex(lines, 0));
        CFArrayRef runs = CTLineGetGlyphRuns(const_cast<__CTLine*>(line));
        _run = static_cast<const __CTRun*>(CFArrayGetValueAtIndex(runs, 0));
        _runRange = CTRunGetStringRange(const_cast<__CTRun*>(_run));
    }

    virtual void TearDown() {
        if (_pathRef) {
            CGPathRelease(_pathRef);
        }
        if (_attributedStringRef) {
            CFRelease(_attributedStringRef);
        }
        if (_frameRef) {
            CFRelease(_frameRef);
        }
        if (_framesetter) {
            CFRelease(_framesetter);
        }
    }

    CTFrameRef _frameRef;
    CTFramesetterRef _framesetter;
    CGPathRef _pathRef;
    CFAttributedStringRef _attributedStringRef;
    NSInteger _textLength;
    const __CTRun* _run;
    CFRange _runRange;

    static constexpr NSString* const c_testString = @"bp";
    static constexpr double c_errorDelta = 0.0005;
    static constexpr float c_ascentExpected = 13.0f;
    static constexpr float c_descentExpected = -3.0f;
    static constexpr float c_leadingExpected = 0.0f;
};

// TODO 6697587: Re-enable this test once ARM exceptions are fixed.
ARM_DISABLED_TEST_F(TypographicBounds, NegativeLengthThrows) {
    CGFloat ascent = 0.0;
    CGFloat descent = 0.0;
    CGFloat leading = 0.0;

    NSString* actualExceptionName = @"";
    @try {
        try {
            CTRunGetTypographicBounds(_run, CFRangeMake(2, -1), &ascent, &descent, &leading);
        }
        CATCH_THROW_NSEXCEPTION();
    } @catch (NSException* exception) {
        actualExceptionName = exception.name;
    }
    ASSERT_OBJCEQ(actualExceptionName, NSInvalidArgumentException);
}

TEST_F(TypographicBounds, InvalidRange) {
    CGFloat ascent = 0.0;
    CGFloat descent = 0.0;
    CGFloat leading = 0.0;

    // Invalid Range (range is greater than range of characters in run)
    // Expected: width is 0.
    CFRange invalidRange = CFRangeMake(0, _textLength + 1);
    double width = CTRunGetTypographicBounds(_run, invalidRange, &ascent, &descent, &leading);
    ASSERT_EQ_MSG(width, 0, "Failed: Typographic width is incorrect");
}

TEST_P(TypographicBounds, VerifyBounds) {
    CGFloat ascent = 0.0;
    CGFloat descent = 0.0;
    CGFloat leading = 0.0;

    double width = CTRunGetTypographicBounds(_run, ::testing::get<0>(GetParam())(_runRange), &ascent, &descent, &leading);
    ASSERT_TRUE_MSG(isValid(ascent, c_ascentExpected, c_errorDelta), "Failed: Run ascent value is incorrect");
    ASSERT_TRUE_MSG(isValid(descent, c_descentExpected, c_errorDelta), "Failed: Run descent value is incorrect");
    ASSERT_TRUE_MSG(isValid(leading, c_leadingExpected, c_errorDelta), "Failed: Run leading value is incorrect");
    ASSERT_TRUE_MSG(isValid(width, ::testing::get<1>(GetParam()), c_errorDelta), "Failed: Typographic width is incorrect");
}

const double widthExpected = 14.125f;
const double reducedWidthExpected = 7.0625f;

INSTANTIATE_TEST_CASE_P(CoreText,
                        TypographicBounds,
                        ::testing::Values(::testing::make_tuple([](CFRange range) { return range; }, widthExpected),
                                          ::testing::make_tuple([](CFRange range) { return CFRangeMake(-1, 2); }, reducedWidthExpected),
                                          ::testing::make_tuple([](CFRange range) { return CFRangeMake(-1, 1); }, 0),
                                          ::testing::make_tuple([](CFRange range) { return CFRangeMake(-1, 0); }, widthExpected)));

TEST(CoreText, CTRunGetAttributes) {
    CFAttributedStringRef string = (__bridge CFAttributedStringRef)getString();
    CTTypesetterRef ts = CTTypesetterCreateWithAttributedString(string);
    CFRange range = { 0, CFAttributedStringGetLength(string) };
    CTLineRef line = CTTypesetterCreateLine(ts, range);
    CFArrayRef runsArray = CTLineGetGlyphRuns(line);
    CTRunRef run = (CTRunRef)CFArrayGetValueAtIndex(runsArray, 0);

    CFDictionaryRef dictionary = CTRunGetAttributes(run);
    UIFont* font = (UIFont*)CFDictionaryGetValue(dictionary, NSFontAttributeName);
    ASSERT_TRUE_MSG([font isKindOfClass:[UIFont class]], "Failed: Wrong object type in dictionary");
    NSString* fontName = ((UIFont*)font).fontName;
    ASSERT_OBJCEQ_MSG(fontName, @"Times New Roman", "Failed: Wrong data in dictionary");

    UIColor* color = (UIColor*)CFDictionaryGetValue(dictionary, NSForegroundColorAttributeName);
    ASSERT_TRUE_MSG([color isKindOfClass:[UIColor class]], "Failed: Wrong object type in dictionary");
    ASSERT_TRUE_MSG([color isEqual:[UIColor redColor]], "Failed: Wrong object type in dictionary");

    color = (UIColor*)CFDictionaryGetValue(dictionary, @"testKey");
    ASSERT_TRUE_MSG([color isKindOfClass:[UIColor class]], "Failed: Wrong object type in dictionary");
    ASSERT_TRUE_MSG([color isEqual:[UIColor blueColor]], "Failed: Wrong object type in dictionary");
}