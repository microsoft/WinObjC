
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
#include "Starboard.h"
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreText/CoreText.h>
#import <CoreFoundation/CFAttributedString.h>

static NSAttributedString* getAttributedString(NSString* str) {
    UIFontDescriptor* fontDescriptor = [UIFontDescriptor fontDescriptorWithName:@"Times New Roman" size:40];
    UIFont* font = [UIFont fontWithDescriptor:fontDescriptor size:40];

    NSRange wholeRange = NSMakeRange(0, str.length);
    NSMutableAttributedString* string = [[[NSMutableAttributedString alloc] initWithString:str] autorelease];
    [string addAttribute:NSForegroundColorAttributeName value:[UIColor redColor] range:wholeRange];
    [string addAttribute:NSFontAttributeName value:font range:wholeRange];

    return string;
}

TEST(CTFrame, GetStringRange) {
    EXPECT_EQ(0, CTFrameGetStringRange(nil).location);
    EXPECT_EQ(0, CTFrameGetStringRange(nil).length);
    EXPECT_EQ(0, CTFrameGetVisibleStringRange(nil).location);
    EXPECT_EQ(0, CTFrameGetVisibleStringRange(nil).length);

    CFAttributedStringRef string = (__bridge CFAttributedStringRef)getAttributedString(@"");
    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(string);
    CGMutablePathRef path = CGPathCreateMutable();
    CGPathAddRect(path, NULL, CGRectMake(0, 0, 100, 50));
    CTFrameRef frame = CTFramesetterCreateFrame(framesetter, CFRangeMake(0, 0), path, NULL);
    EXPECT_EQ(0, CTFrameGetStringRange(frame).location);
    EXPECT_EQ(0, CTFrameGetStringRange(frame).length);
    EXPECT_EQ(0, CTFrameGetVisibleStringRange(frame).location);
    EXPECT_EQ(0, CTFrameGetVisibleStringRange(frame).length);
    CFRelease(framesetter);
    CFRelease(frame);

    // Can fit all of the text in frame, so visible range should be equal to string range
    string = (__bridge CFAttributedStringRef)getAttributedString(@"foo");
    framesetter = CTFramesetterCreateWithAttributedString(string);
    frame = CTFramesetterCreateFrame(framesetter, CFRangeMake(0, 0), path, NULL);
    EXPECT_EQ(0, CTFrameGetStringRange(frame).location);
    EXPECT_EQ(3, CTFrameGetStringRange(frame).length);
    EXPECT_EQ(0, CTFrameGetVisibleStringRange(frame).location);
    EXPECT_EQ(3, CTFrameGetVisibleStringRange(frame).length);
    CFRelease(framesetter);
    CFRelease(frame);

    // Can only fit "foob" so visible range and string range should NOT be equal
    string = (__bridge CFAttributedStringRef)getAttributedString(@"foobar");
    framesetter = CTFramesetterCreateWithAttributedString(string);
    frame = CTFramesetterCreateFrame(framesetter, CFRangeMake(0, 0), path, NULL);
    EXPECT_EQ(0, CTFrameGetStringRange(frame).location);
    EXPECT_EQ(6, CTFrameGetStringRange(frame).length);
    EXPECT_EQ(0, CTFrameGetVisibleStringRange(frame).location);
    EXPECT_EQ(4, CTFrameGetVisibleStringRange(frame).length);

    CFRelease(framesetter);
    CFRelease(frame);
    CGPathRelease(path);
}