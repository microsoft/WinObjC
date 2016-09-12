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

#import <UIKit/UIKit.h>
#include <TestFramework.h>
#import <CoreFoundation/CoreFoundation.h>

NSMutableAttributedString* getAttributedString(NSString* str) {
    UIFontDescriptor* fontDescriptor = [UIFontDescriptor fontDescriptorWithName:@"Times New Roman" size:40];
    UIFont* font = [UIFont fontWithDescriptor:fontDescriptor size:40];

    NSRange wholeRange = NSMakeRange(0, str.length);
    NSMutableAttributedString* string = [[[NSMutableAttributedString alloc] initWithString:str] autorelease];
    [string addAttribute:NSForegroundColorAttributeName value:[UIColor redColor] range:wholeRange];
    [string addAttribute:NSFontAttributeName value:font range:wholeRange];

    return string;
}

extern bool isValid(double testValue, double expectedValue, double delta);

TEST(CTLine, CTLineGetStringIndexForPosition) {
    CFAttributedStringRef string = (__bridge CFAttributedStringRef)getAttributedString(@"hello");
    CTTypesetterRef ts = CTTypesetterCreateWithAttributedString(string);
    CFRange range = { 0, CFAttributedStringGetLength(string) };
    CTLineRef line = CTTypesetterCreateLine(ts, range);

    // testing with position < 0
    CGPoint position = { -1, 0 };
    CFIndex index = CTLineGetStringIndexForPosition(line, position);
    ASSERT_EQ_MSG(index, 0, "Failed: Wrong Index for given position");

    // testing with position > length of line.
    position = { 873214, 0 };
    index = CTLineGetStringIndexForPosition(line, position);
    ASSERT_EQ_MSG(index, CFAttributedStringGetLength(string), "Failed: Wrong Index for given position");

    // On ios platform, for the sample string "hello", the starting positions of characters as obtained from the function CTRunGetPositions
    // are, {0, 22.2, 44.4, 53.37, 62.26}  .
    // These values are very close to values obtained on our implementation. Here we are using these values as source of truth for our test
    // cases.
    position = { 23, 0 };
    index = CTLineGetStringIndexForPosition(line, position);
    ASSERT_EQ_MSG(index, 1, "Failed: Wrong Index for given position");

    position = { 62, 0 };
    index = CTLineGetStringIndexForPosition(line, position);
    ASSERT_EQ_MSG(index, 3, "Failed: Wrong Index for given position");
}

TEST(CTLine, CTLineGetOffsetForStringIndex) {
    const double errorDelta = 1;
    CFAttributedStringRef string = (__bridge CFAttributedStringRef)getAttributedString(@"hello");
    CTTypesetterRef ts = CTTypesetterCreateWithAttributedString(string);
    CFRange range = { 0, CFAttributedStringGetLength(string) };
    CTLineRef line = CTTypesetterCreateLine(ts, range);

    CGFloat secOffset;
    // testing with index < 0
    CGFloat offset = CTLineGetOffsetForStringIndex(line, -1, &secOffset);
    ASSERT_EQ_MSG(offset, 0, "Failed: Wrong offset for given index");

    // testing with index = 0
    offset = CTLineGetOffsetForStringIndex(line, 0, &secOffset);
    ASSERT_EQ_MSG(offset, 0, "Failed: Wrong offset for given index");

    // testing with index > last index.
    offset = CTLineGetOffsetForStringIndex(line, 928347, &secOffset);
    ASSERT_GT_MSG(offset, 62, "Failed: Wrong offset for given index");

    // On ios platform, for the sample string "hello", the starting positions of characters as obtained from the function CTRunGetPositions
    // are, {0, 22.2, 44.4, 53.37, 62.26}  .
    // These values are very close to values obtained on our implementation. Here we are using these values as source of truth for our test
    // cases.
    offset = CTLineGetOffsetForStringIndex(line, 2, &secOffset);
    ASSERT_TRUE_MSG(isValid(offset, 44.4, errorDelta), "Failed: Wrong offset for given index");

    offset = CTLineGetOffsetForStringIndex(line, 4, &secOffset);
    ASSERT_TRUE_MSG(isValid(offset, 62.26, errorDelta), "Failed: Wrong offset for given index");

    // passing secondaryOffset reference as NULL
    offset = CTLineGetOffsetForStringIndex(line, 4, NULL);
    ASSERT_TRUE_MSG(isValid(offset, 62.26, errorDelta), "Failed: Wrong offset for given index");

    // comparing secondaryOffset and offset.
    offset = CTLineGetOffsetForStringIndex(line, 4, &secOffset);
    ASSERT_EQ_MSG(offset, secOffset, "Failed: Wrong offset for given index");
}

TEST(CTLine, CTLineCreateWithAttributedString) {
    NSMutableAttributedString* attrString = getAttributedString(@"hello");
    [attrString addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:20] range:NSMakeRange(3, 2)];
    CFAttributedStringRef string = (__bridge CFAttributedStringRef)attrString;

    CTLineRef line = CTLineCreateWithAttributedString(string);
    EXPECT_NE(line, nil);

    EXPECT_EQ(0, CTLineGetStringRange(line).location);
    EXPECT_EQ(5, CTLineGetStringRange(line).length);
    EXPECT_EQ(5, CTLineGetGlyphCount(line));
    CFArrayRef runs = CTLineGetGlyphRuns(line);

    EXPECT_NE(runs, nil);
    EXPECT_EQ_MSG(2, CFArrayGetCount(runs), "CTLine should create multiple runs when attributed string has multiple attribute ranges");
    EXPECT_EQ(3, CTRunGetGlyphCount(static_cast<CTRunRef>(CFArrayGetValueAtIndex(runs, 0))));
    EXPECT_EQ(2, CTRunGetGlyphCount(static_cast<CTRunRef>(CFArrayGetValueAtIndex(runs, 1))));

    // Glyphs for h, e, and l respectively
    const CGGlyph* helGlyphs = CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(runs, 0)));
    ASSERT_NE(nullptr, helGlyphs);

    std::vector<WORD> characters(4);
    [@"hel" getCharacters:characters.data()];
    std::vector<CGGlyph> actualGlyphs(4);
    UIFontDescriptor* fontDescriptor = [UIFontDescriptor fontDescriptorWithName:@"Times New Roman" size:40];
    UIFont* font = [UIFont fontWithDescriptor:fontDescriptor size:40];
    CTFontGetGlyphsForCharacters(static_cast<CTFontRef>(font), characters.data(), actualGlyphs.data(), 3);

    EXPECT_EQ(actualGlyphs[0], *helGlyphs);
    EXPECT_EQ(actualGlyphs[1], *(++helGlyphs));
    EXPECT_EQ(actualGlyphs[2], *(++helGlyphs));

    // Glyphs for l and o respectively
    const CGGlyph* loGlyphs = CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(runs, 1)));
    ASSERT_NE(nullptr, loGlyphs);

    [@"lo" getCharacters:characters.data()];
    CTFontGetGlyphsForCharacters(static_cast<CTFontRef>([UIFont systemFontOfSize:20]), characters.data(), actualGlyphs.data(), 2);

    EXPECT_EQ(actualGlyphs[0], *loGlyphs);
    EXPECT_EQ(actualGlyphs[1], *(++loGlyphs));

    CFRelease(runs);
    CFRelease(line);

    string = (__bridge CFAttributedStringRef)getAttributedString(@"");
    line = CTLineCreateWithAttributedString(string);
    EXPECT_NE(line, nil);
    EXPECT_EQ(0, CTLineGetStringRange(line).location);
    EXPECT_EQ(0, CTLineGetStringRange(line).length);
    EXPECT_EQ(0, CTLineGetGlyphCount(line));

    runs = CTLineGetGlyphRuns(line);
    EXPECT_NE(runs, nil);
    EXPECT_EQ(0, CFArrayGetCount(runs));
    CFRelease(runs);
    CFRelease(line);
}

TEST(CTLine, CreateTruncatedLineTest) {
    NSMutableAttributedString* string = getAttributedString(@"ABCDEF");
    [string addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:20] range:NSMakeRange(0, 6)];
    CTLineRef line = CTLineCreateWithAttributedString(static_cast<CFAttributedStringRef>(string));

    // "ABCDEF"
    const CGGlyph* originalGlyphs = CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(line), 0)));

    CTLineRef startTruncated = CTLineCreateTruncatedLine(line, 40.0, kCTLineTruncationStart, NULL);
    EXPECT_EQ(4, CTLineGetGlyphCount(startTruncated));

    // Truncated should be CDEF in one run
    const CGGlyph* startTruncatedGlyphs =
        CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(startTruncated), 0)));
    EXPECT_EQ(*(originalGlyphs + 2), *startTruncatedGlyphs);
    EXPECT_EQ(*(originalGlyphs + 5), *(startTruncatedGlyphs + 3));
    CFRelease(startTruncated);

    CTLineRef endTruncated = CTLineCreateTruncatedLine(line, 40.0, kCTLineTruncationEnd, NULL);
    EXPECT_EQ(4, CTLineGetGlyphCount(endTruncated));

    // Truncated should be ABCD in one run
    const CGGlyph* endTruncatedGlyphs =
        CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(endTruncated), 0)));
    EXPECT_EQ(*originalGlyphs, *endTruncatedGlyphs);
    EXPECT_EQ(*(originalGlyphs + 3), *(endTruncatedGlyphs + 3));
    CFRelease(endTruncated);

    CTLineRef middleTruncated = CTLineCreateTruncatedLine(line, 40.0, kCTLineTruncationMiddle, NULL);
    EXPECT_EQ(4, CTLineGetGlyphCount(middleTruncated));

    // Truncated should be ABEF in one run
    const CGGlyph* middleTruncatedGlyphs =
        CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(middleTruncated), 0)));
    EXPECT_EQ(*originalGlyphs, *middleTruncatedGlyphs);
    EXPECT_EQ(*(originalGlyphs + 1), *(middleTruncatedGlyphs + 1));
    EXPECT_EQ(*(originalGlyphs + 4), *(middleTruncatedGlyphs + 2));
    EXPECT_EQ(*(originalGlyphs + 5), *(middleTruncatedGlyphs + 3));
    CFRelease(middleTruncated);

    CFAttributedStringRef ellipsisString = (__bridge CFAttributedStringRef)getAttributedString(@"...");
    CTLineRef ellipsis = CTLineCreateWithAttributedString(ellipsisString);
    const CGGlyph* ellipsisGlyphs = CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(ellipsis), 0)));

    startTruncated = CTLineCreateTruncatedLine(line, 40.0, kCTLineTruncationStart, ellipsis);
    EXPECT_EQ(5, CTLineGetGlyphCount(startTruncated));

    // Truncated should be ...EF in two runs (..., EF)
    startTruncatedGlyphs = CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(startTruncated), 0)));
    EXPECT_EQ(*ellipsisGlyphs, *startTruncatedGlyphs);
    EXPECT_EQ(*ellipsisGlyphs, *(startTruncatedGlyphs + 2));

    startTruncatedGlyphs = CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(startTruncated), 1)));
    EXPECT_EQ(*(originalGlyphs + 4), *startTruncatedGlyphs);
    EXPECT_EQ(*(originalGlyphs + 5), *(startTruncatedGlyphs + 1));
    CFRelease(startTruncated);

    endTruncated = CTLineCreateTruncatedLine(line, 40.0, kCTLineTruncationEnd, ellipsis);
    EXPECT_EQ(5, CTLineGetGlyphCount(endTruncated));

    // Truncated should be AB... in two runs (AB, ...)
    endTruncatedGlyphs = CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(endTruncated), 0)));
    EXPECT_EQ(*originalGlyphs, *endTruncatedGlyphs);
    EXPECT_EQ(*(originalGlyphs + 1), *(endTruncatedGlyphs + 1));

    endTruncatedGlyphs = CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(endTruncated), 1)));
    EXPECT_EQ(*ellipsisGlyphs, *endTruncatedGlyphs);
    EXPECT_EQ(*ellipsisGlyphs, *(endTruncatedGlyphs + 2));
    CFRelease(endTruncated);

    middleTruncated = CTLineCreateTruncatedLine(line, 40.0, kCTLineTruncationMiddle, ellipsis);
    EXPECT_EQ(5, CTLineGetGlyphCount(middleTruncated));

    // Truncated should be A...F in three runs (A, ..., F)
    middleTruncatedGlyphs = CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(middleTruncated), 0)));
    EXPECT_EQ(*originalGlyphs, *middleTruncatedGlyphs);

    middleTruncatedGlyphs = CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(middleTruncated), 1)));
    EXPECT_EQ(*ellipsisGlyphs, *middleTruncatedGlyphs);
    EXPECT_EQ(*ellipsisGlyphs, *(middleTruncatedGlyphs + 2));

    middleTruncatedGlyphs = CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(middleTruncated), 2)));
    EXPECT_EQ(*(originalGlyphs + 5), *middleTruncatedGlyphs);
    CFRelease(middleTruncated);

    CFRelease(ellipsis);
    CFRelease(line);
}