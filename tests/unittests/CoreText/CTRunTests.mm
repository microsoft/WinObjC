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

TEST(CoreText, TypographicBounds) {
    const double errorDelta = 0.0005;
    const float ascentExpected = 13.0f;
    const float descentExpected = -3.0f;
    const float leadingExpected = 0.0f;
    const double widthExpected = 14.125f;
    const double reducedWidthExpected = 7.0625f;

    NSString* testString = @"bp";
    NSInteger textLength = CFStringGetLength((CFStringRef)testString);
    CFRange currentRange = CFRangeMake(0, textLength);

    CFAttributedStringRef attributedStringRef =
        static_cast<CFAttributedStringRef>([[NSMutableAttributedString alloc] initWithString:testString]);

    UIFont* font = [UIFont fontWithName:@"SegoeUI" size:12.0];
    ASSERT_TRUE_MSG(font != nullptr, "FAILED: Font not available!");

    CTFontRef fontRef = CTFontCreateWithName(static_cast<CFStringRef>(font.fontName), font.pointSize, NULL);
    ASSERT_TRUE_MSG(fontRef != nullptr, "FAILED: Could not create font!");

    CFAttributedStringSetAttribute(attributedStringRef, currentRange, kCTFontAttributeName, fontRef);
    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(attributedStringRef);
    ASSERT_TRUE_MSG(framesetter != nullptr, "FAILED: Could not create frame setter!");

    CGRect frameRect = CGRectMake(0, 0, 80, 80);
    CGPathRef pathRef = CGPathCreateWithRect(frameRect, NULL);
    CTFrameRef frameRef = CTFramesetterCreateFrame(framesetter, currentRange, pathRef, NULL);
    CFArrayRef lines = CTFrameGetLines(frameRef);

    const __CTLine* line = static_cast<const __CTLine*>(CFArrayGetValueAtIndex(lines, 0));
    CFArrayRef runs = CTLineGetGlyphRuns(const_cast<__CTLine*>(line));
    const __CTRun* run = static_cast<const __CTRun*>(CFArrayGetValueAtIndex(runs, 0));
    CFRange runRange = CTRunGetStringRange(const_cast<__CTRun*>(run));

    CGFloat ascent = 0.0;
    CGFloat descent = 0.0;
    CGFloat leading = 0.0;

    // Valid Range
    // Expected: All valid values.
    double width = CTRunGetTypographicBounds(run, runRange, &ascent, &descent, &leading);
    ASSERT_TRUE_MSG(isValid(ascent, ascentExpected, errorDelta), "Failed: Run ascent value is incorrect");
    ASSERT_TRUE_MSG(isValid(descent, descentExpected, errorDelta), "Failed: Run descent value is incorrect");
    ASSERT_TRUE_MSG(isValid(leading, leadingExpected, errorDelta), "Failed: Run leading value is incorrect");
    ASSERT_TRUE_MSG(isValid(width, widthExpected, errorDelta), "Failed: Typographic width is incorrect");

    // Invalid Range (range is greater than range of characters in run)
    // Expected: width is 0.
    CFRange invalidRange = CFRangeMake(0, textLength + 1);
    width = CTRunGetTypographicBounds(run, invalidRange, &ascent, &descent, &leading);
    ASSERT_EQ_MSG(width, 0, "Failed: Typographic width is incorrect");

    // location < 0 and length > 0 with location + length > 0
    // Expected: valid values for ascent, descent and leading. range should start at 0 and length be reduced by location value.
    runRange.location = -1;
    runRange.length = 2;
    width = CTRunGetTypographicBounds(run, runRange, &ascent, &descent, &leading);
    ASSERT_TRUE_MSG(isValid(ascent, ascentExpected, errorDelta), "Failed: Run ascent value is incorrect");
    ASSERT_TRUE_MSG(isValid(descent, descentExpected, errorDelta), "Failed: Run descent value is incorrect");
    ASSERT_TRUE_MSG(isValid(leading, leadingExpected, errorDelta), "Failed: Run leading value is incorrect");
    ASSERT_TRUE_MSG(isValid(width, reducedWidthExpected, errorDelta), "Failed: Typographic width is incorrect");

    // location < 0 and length > 0 with location + length <= 0
    // Expected: valid values for ascent, descent and leading. width should be 0.
    runRange.location = -1;
    runRange.length = 1;
    width = CTRunGetTypographicBounds(run, runRange, &ascent, &descent, &leading);
    ASSERT_TRUE_MSG(isValid(ascent, ascentExpected, errorDelta), "Failed: Run ascent value is incorrect");
    ASSERT_TRUE_MSG(isValid(descent, descentExpected, errorDelta), "Failed: Run descent value is incorrect");
    ASSERT_TRUE_MSG(isValid(leading, leadingExpected, errorDelta), "Failed: Run leading value is incorrect");
    ASSERT_TRUE_MSG(isValid(width, 0, errorDelta), "Failed: Typographic width is incorrect");

    // length = 0
    // Expected: All valid values.
    runRange.length = 0;
    width = CTRunGetTypographicBounds(run, runRange, &ascent, &descent, &leading);
    ASSERT_TRUE_MSG(isValid(ascent, ascentExpected, errorDelta), "Failed: Run ascent value is incorrect");
    ASSERT_TRUE_MSG(isValid(descent, descentExpected, errorDelta), "Failed: Run descent value is incorrect");
    ASSERT_TRUE_MSG(isValid(leading, leadingExpected, errorDelta), "Failed: Run leading value is incorrect");
    ASSERT_TRUE_MSG(isValid(width, widthExpected, errorDelta), "Failed: Typographic width is incorrect");

    // length < 0
    // Expected: exception
    runRange.location = 2;
    runRange.length = -1;
    NSString* actualExceptionName = @"";
    @try {
        try {
            CTRunGetTypographicBounds(run, runRange, &ascent, &descent, &leading);
        }
        CATCH_THROW_NSEXCEPTION();
    } @catch (NSException* exception) {
        actualExceptionName = exception.name;
    }
    ASSERT_OBJCEQ(actualExceptionName, NSInvalidArgumentException);

    CGPathRelease(pathRef);
    CFRelease(attributedStringRef);
    CFRelease(frameRef);
    CFRelease(framesetter);
}

TEST(CoreText, CTRunGetAttributes) {
    CFAttributedStringRef string = (__bridge CFAttributedStringRef)getString();
    CTTypesetterRef ts = CTTypesetterCreateWithAttributedString(string);
    CFRange range = { 0, CFAttributedStringGetLength(string) };
    CTLineRef line = CTTypesetterCreateLineWithOffset(ts, range, 0.0f);
    CFArrayRef runsArray = CTLineGetGlyphRuns(line);
    CTRunRef run = (CTRunRef)CFArrayGetValueAtIndex(runsArray, 0);

    CFDictionaryRef dictionary = CTRunGetAttributes(run);
    id font = [dictionary objectForKey:(NSString*)NSFontAttributeName];
    ASSERT_TRUE_MSG([font isKindOfClass:[UIFont class]], "Failed: Wrong object type in dictionary");
    NSString* fontName = ((UIFont*)font).fontName;
    ASSERT_OBJCEQ_MSG(fontName, @"Times New Roman", "Failed: Wrong data in dictionary");

    id color = [dictionary objectForKey:NSForegroundColorAttributeName];
    ASSERT_TRUE_MSG([color isKindOfClass:[UIColor class]], "Failed: Wrong object type in dictionary");
    ASSERT_TRUE_MSG([color isEqual:[UIColor redColor]], "Failed: Wrong object type in dictionary");

    color = [dictionary objectForKey:@"testKey"];
    ASSERT_TRUE_MSG([color isKindOfClass:[UIColor class]], "Failed: Wrong object type in dictionary");
    ASSERT_TRUE_MSG([color isEqual:[UIColor blueColor]], "Failed: Wrong object type in dictionary");
}