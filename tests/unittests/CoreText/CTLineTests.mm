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

TEST(CTLine, CTLineGetStringIndexForPosition) {
    CFAttributedStringRef string = (__bridge CFAttributedStringRef)getAttributedString(@"hello");
    CTLineRef line = CTLineCreateWithAttributedString(string);

    // testing with position < 0
    CGPoint position = { -1, 0 };
    CFIndex index = CTLineGetStringIndexForPosition(line, position);
    EXPECT_EQ_MSG(index, 0, "Failed: Wrong Index for given position");

    // testing with position > length of line.
    position = { 873214, 0 };
    index = CTLineGetStringIndexForPosition(line, position);
    EXPECT_EQ_MSG(index, CFAttributedStringGetLength(string), "Failed: Wrong Index for given position");

    position = { 23, 0 };
    index = CTLineGetStringIndexForPosition(line, position);
    EXPECT_EQ_MSG(index, 1, "Failed: Wrong Index for given position");

    position = { 44, 0 };
    index = CTLineGetStringIndexForPosition(line, position);
    EXPECT_EQ_MSG(index, 2, "Failed: Wrong Index for given position");
}

TEST(CTLine, CTLineGetOffsetForStringIndex) {
    const double errorDelta = 1;
    CFAttributedStringRef string = (__bridge CFAttributedStringRef)getAttributedString(@"hello");
    CTLineRef line = CTLineCreateWithAttributedString(string);

    CGFloat secOffset;
    // testing with index < 0
    CGFloat offset = CTLineGetOffsetForStringIndex(line, -1, &secOffset);
    EXPECT_EQ_MSG(offset, 0, "Failed: Wrong offset for given index");

    // testing with index = 0
    offset = CTLineGetOffsetForStringIndex(line, 0, &secOffset);
    EXPECT_EQ_MSG(offset, 0, "Failed: Wrong offset for given index");

    // testing with index > last index.
    offset = CTLineGetOffsetForStringIndex(line, 928347, &secOffset);
    EXPECT_GT_MSG(offset, 58, "Failed: Wrong offset for given index");

    offset = CTLineGetOffsetForStringIndex(line, 2, &secOffset);
    EXPECT_NEAR_MSG(43.55, offset, errorDelta, "Failed: Wrong offset for given index");

    offset = CTLineGetOffsetForStringIndex(line, 4, &secOffset);
    EXPECT_NEAR_MSG(62.93, offset, errorDelta, "Failed: Wrong offset for given index");

    // passing secondaryOffset reference as NULL
    offset = CTLineGetOffsetForStringIndex(line, 4, NULL);
    EXPECT_NEAR_MSG(62.93, offset, errorDelta, "Failed: Wrong offset for given index");

    // comparing secondaryOffset and offset.
    offset = CTLineGetOffsetForStringIndex(line, 4, &secOffset);
    EXPECT_EQ_MSG(offset, secOffset, "Failed: Wrong offset for given index");
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
    CFRelease(line);
}

TEST(CTLine, CreateTruncatedLineNoTruncationToken) {
    NSMutableAttributedString* string = getAttributedString(@"ABCDEF");
    [string addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:20] range:NSMakeRange(0, 6)];
    CTLineRef line = CTLineCreateWithAttributedString(static_cast<CFAttributedStringRef>(string));

    // "ABCDEF"
    const CGGlyph* originalGlyphs = CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(line), 0)));

    CTLineRef startTruncated = CTLineCreateTruncatedLine(line, 40.0, kCTLineTruncationStart, NULL);
    EXPECT_EQ(3, CTLineGetGlyphCount(startTruncated));

    // Truncated should be DEF in one run
    const CGGlyph* startTruncatedGlyphs =
        CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(startTruncated), 0)));
    EXPECT_EQ(*(originalGlyphs + 3), *startTruncatedGlyphs);
    EXPECT_EQ(*(originalGlyphs + 5), *(startTruncatedGlyphs + 2));
    CFRelease(startTruncated);

    CTLineRef endTruncated = CTLineCreateTruncatedLine(line, 40.0, kCTLineTruncationEnd, NULL);
    EXPECT_EQ(3, CTLineGetGlyphCount(endTruncated));

    // Truncated should be ABC in one run
    const CGGlyph* endTruncatedGlyphs =
        CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(endTruncated), 0)));
    EXPECT_EQ(*originalGlyphs, *endTruncatedGlyphs);
    EXPECT_EQ(*(originalGlyphs + 2), *(endTruncatedGlyphs + 2));
    CFRelease(endTruncated);

    CTLineRef middleTruncated = CTLineCreateTruncatedLine(line, 40.0, kCTLineTruncationMiddle, NULL);
    EXPECT_EQ(3, CTLineGetGlyphCount(middleTruncated));

    // Truncated should be AEF in one run
    const CGGlyph* middleTruncatedGlyphs =
        CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(middleTruncated), 0)));
    EXPECT_EQ(*originalGlyphs, *middleTruncatedGlyphs);
    EXPECT_EQ(*(originalGlyphs + 4), *(middleTruncatedGlyphs + 1));
    EXPECT_EQ(*(originalGlyphs + 5), *(middleTruncatedGlyphs + 2));
    CFRelease(middleTruncated);
    CFRelease(line);
}

TEST(CTLine, CreateTruncatedLineTruncationToken) {
    NSMutableAttributedString* string = getAttributedString(@"ABCDEF");
    [string addAttribute:NSFontAttributeName value:[UIFont systemFontOfSize:20] range:NSMakeRange(0, 6)];
    CTLineRef line = CTLineCreateWithAttributedString(static_cast<CFAttributedStringRef>(string));

    // "ABCDEF"
    const CGGlyph* originalGlyphs = CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(line), 0)));

    CFAttributedStringRef ellipsisString = (__bridge CFAttributedStringRef)getAttributedString(@"...");
    CTLineRef ellipsis = CTLineCreateWithAttributedString(ellipsisString);
    const CGGlyph* ellipsisGlyphs = CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(ellipsis), 0)));

    CTLineRef startTruncated = CTLineCreateTruncatedLine(line, 40.0, kCTLineTruncationStart, ellipsis);
    EXPECT_EQ(4, CTLineGetGlyphCount(startTruncated));

    // Truncated should be ...F in two runs (..., F)
    const CGGlyph* startTruncatedGlyphs =
        CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(startTruncated), 0)));
    EXPECT_EQ(*ellipsisGlyphs, *startTruncatedGlyphs);
    EXPECT_EQ(*ellipsisGlyphs, *(startTruncatedGlyphs + 2));

    startTruncatedGlyphs = CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(startTruncated), 1)));
    EXPECT_EQ(*(originalGlyphs + 5), *startTruncatedGlyphs);
    CFRelease(startTruncated);

    CTLineRef endTruncated = CTLineCreateTruncatedLine(line, 40.0, kCTLineTruncationEnd, ellipsis);
    EXPECT_EQ(4, CTLineGetGlyphCount(endTruncated));

    // Truncated should be A... in two runs (A, ...)
    const CGGlyph* endTruncatedGlyphs =
        CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(endTruncated), 0)));
    EXPECT_EQ(*originalGlyphs, *endTruncatedGlyphs);

    endTruncatedGlyphs = CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(endTruncated), 1)));
    EXPECT_EQ(*ellipsisGlyphs, *endTruncatedGlyphs);
    EXPECT_EQ(*ellipsisGlyphs, *(endTruncatedGlyphs + 2));
    CFRelease(endTruncated);

    CTLineRef middleTruncated = CTLineCreateTruncatedLine(line, 60.0, kCTLineTruncationMiddle, ellipsis);
    EXPECT_EQ(5, CTLineGetGlyphCount(middleTruncated));

    // Truncated should be A...F in three runs (A, ..., F)
    const CGGlyph* middleTruncatedGlyphs =
        CTRunGetGlyphsPtr(static_cast<CTRunRef>(CFArrayGetValueAtIndex(CTLineGetGlyphRuns(middleTruncated), 0)));
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

TEST(CTLine, CTLineGetGlyphCount) {
    EXPECT_EQ(0, CTLineGetGlyphCount(nil));

    CFAttributedStringRef string = (__bridge CFAttributedStringRef)getAttributedString(@"");
    CTLineRef line = CTLineCreateWithAttributedString(string);
    EXPECT_EQ(0, CTLineGetGlyphCount(line));
    CFRelease(line);

    string = (__bridge CFAttributedStringRef)getAttributedString(@"foobarbaz");
    line = CTLineCreateWithAttributedString(string);
    EXPECT_EQ(9, CTLineGetGlyphCount(line));
    CFRelease(line);
}