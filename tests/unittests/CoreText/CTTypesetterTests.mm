
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

#import <UIKit/UIKit.h>
#include <TestFramework.h>
#import <CoreFoundation/CoreFoundation.h>

static NSAttributedString* getMultilineAttributedString() {
    UIFontDescriptor* fontDescriptor = [UIFontDescriptor fontDescriptorWithName:@"Segoe UI" size:40];
    UIFont* font = [UIFont fontWithDescriptor:fontDescriptor size:40];

    NSRange wholeRange = NSMakeRange(0, 20);
    NSMutableAttributedString* string = [[[NSMutableAttributedString alloc] initWithString:@"hello \nworld goodbye"] autorelease];
    [string addAttribute:NSForegroundColorAttributeName value:[UIColor redColor] range:wholeRange];
    [string addAttribute:NSFontAttributeName value:font range:wholeRange];

    return string;
}

TEST(CTTypeSetter, SuggestLineBreak) {
    const double errorDelta = 1;
    CFAttributedStringRef string = (__bridge CFAttributedStringRef)getMultilineAttributedString();
    CTTypesetterRef ts = CTTypesetterCreateWithAttributedString(string);
    CFIndex index = CTTypesetterSuggestLineBreak(ts, 0, 50.0f);
    EXPECT_EQ_MSG(2, index, "SuggestLineBreak should break up word when no soft line breaks are possible");

    index = CTTypesetterSuggestLineBreak(ts, 0, 100.0f);
    EXPECT_EQ_MSG(7, index, "SuggestLineBreak should end line when hard line break is hit");

    index = CTTypesetterSuggestLineBreak(ts, 7, 275.0f);
    EXPECT_EQ_MSG(13,
                  index,
                  "SuggestLineBreak should end line at space when soft line break is possible and the text is longer than the width");

    CFRelease(ts);
}

TEST(CTTypeSetter, CreateLineShouldTrimHardLineBreak) {
    const double errorDelta = 1;
    CFAttributedStringRef string = (__bridge CFAttributedStringRef)getMultilineAttributedString();
    CTTypesetterRef ts = CTTypesetterCreateWithAttributedString(string);
    CFRange range = { 0, 7 };
    CTLineRef line = CTTypesetterCreateLine(ts, range);
    ASSERT_EQ_MSG(6, CTLineGetGlyphCount(line), "CreateLine should trim hard line break from the end of the line");
    CFRelease(ts);
    CFRelease(line);
}

TEST(CTTypeSetter, LinesShouldDefaultToZeroOffset) {
    const double errorDelta = 1;
    CFAttributedStringRef string = (__bridge CFAttributedStringRef)getMultilineAttributedString();
    CTTypesetterRef ts = CTTypesetterCreateWithAttributedString(string);

    CFIndex lineBreak = CTTypesetterSuggestLineBreak(ts, 0, 100.0f);
    CFIndex lineBreakWithOffset = CTTypesetterSuggestLineBreakWithOffset(ts, 0, 100.0f, 0.0f);
    EXPECT_EQ(lineBreak, lineBreakWithOffset);

    CFRange range = { 0, lineBreak };
    CTLineRef line = CTTypesetterCreateLine(ts, range);
    CTLineRef lineWithOffset = CTTypesetterCreateLineWithOffset(ts, range, 0.0f);
    EXPECT_EQ(CTLineGetGlyphCount(lineWithOffset), CTLineGetGlyphCount(line));

    CGFloat ascent, descent, leading, ascentWithOffset, descentWithOffset, leadingWithOffset;
    double width = CTLineGetTypographicBounds(line, &ascent, &descent, &leading);
    double widthWithOffset = CTLineGetTypographicBounds(line, &ascentWithOffset, &descentWithOffset, &leadingWithOffset);

    EXPECT_EQ(widthWithOffset, width);
    EXPECT_EQ(ascentWithOffset, ascent);
    EXPECT_EQ(descentWithOffset, descent);
    EXPECT_EQ(leadingWithOffset, leading);
    CFRelease(ts);
    CFRelease(line);
    CFRelease(lineWithOffset);
}