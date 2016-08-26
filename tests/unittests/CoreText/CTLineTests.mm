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

NSAttributedString* getAttributedString() {
    UIFontDescriptor* fontDescriptor = [UIFontDescriptor fontDescriptorWithName:@"Times New Roman" size:40];
    UIFont* font = [UIFont fontWithDescriptor:fontDescriptor size:40];

    NSRange wholeRange = NSMakeRange(0, 5);
    NSMutableAttributedString* string = [[[NSMutableAttributedString alloc] initWithString:@"hello"] autorelease];
    [string addAttribute:NSForegroundColorAttributeName value:[UIColor redColor] range:wholeRange];
    [string addAttribute:NSFontAttributeName value:font range:wholeRange];

    return string;
}

extern bool isValid(double testValue, double expectedValue, double delta);

TEST(CoreText, CTLineGetStringIndexForPosition) {
    CFAttributedStringRef string = (__bridge CFAttributedStringRef)getAttributedString();
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

TEST(CoreGraphics, CTLineGetOffsetForStringIndex) {
    const double errorDelta = 1;
    CFAttributedStringRef string = (__bridge CFAttributedStringRef)getAttributedString();
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