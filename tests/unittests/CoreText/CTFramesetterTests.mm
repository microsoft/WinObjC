
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
#import <CoreText/CoreText.h>
#import <UIKit/UIKit.h>
#import <StubReturn.h>

static const float c_errorDelta = 0.0005f;

static NSAttributedString* getAttributedString(NSString* str) {
    UIFontDescriptor* fontDescriptor = [UIFontDescriptor fontDescriptorWithName:@"Times New Roman" size:40];
    UIFont* font = [UIFont fontWithDescriptor:fontDescriptor size:40];

    NSRange wholeRange = NSMakeRange(0, str.length);
    NSMutableAttributedString* string = [[[NSMutableAttributedString alloc] initWithString:str] autorelease];
    [string addAttribute:NSForegroundColorAttributeName value:[UIColor redColor] range:wholeRange];
    [string addAttribute:NSFontAttributeName value:font range:wholeRange];

    return string;
}

TEST(CTFramesetter, GetTypesetter) {
    CFAttributedStringRef string = (__bridge CFAttributedStringRef)getAttributedString(@"");
    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(string);
    CFAutorelease(framesetter);
    CTTypesetterRef typesetter = CTFramesetterGetTypesetter(framesetter);
    EXPECT_NE(nil, typesetter);

    string = (__bridge CFAttributedStringRef)getAttributedString(@"foobar");
    framesetter = CTFramesetterCreateWithAttributedString(string);
    CFAutorelease(framesetter);
    typesetter = CTFramesetterGetTypesetter(framesetter);
    EXPECT_NE(nil, typesetter);

    string = (__bridge CFAttributedStringRef)getAttributedString(@"视窗");
    framesetter = CTFramesetterCreateWithAttributedString(string);
    CFAutorelease(framesetter);
    typesetter = CTFramesetterGetTypesetter(framesetter);
    EXPECT_NE(nil, typesetter);
}

TEST(CTFramesetter, SuggestFrameSizeWithConstraints) {
    CFRange fitRange = { 0 };
    CGSize size = CTFramesetterSuggestFrameSizeWithConstraints(nil, CFRangeMake(0, 0), nil, CGSizeMake(FLT_MAX, FLT_MAX), &fitRange);
    EXPECT_NEAR(0.0f, size.height, c_errorDelta);
    EXPECT_NEAR(0.0f, size.width, c_errorDelta);
    EXPECT_EQ(0, fitRange.location);
    EXPECT_EQ(0, fitRange.length);

    CFAttributedStringRef string = (__bridge CFAttributedStringRef)getAttributedString(@"");
    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(string);
    CFAutorelease(framesetter);
    size = CTFramesetterSuggestFrameSizeWithConstraints(framesetter, CFRangeMake(0, 0), nil, CGSizeMake(FLT_MAX, FLT_MAX), &fitRange);
    EXPECT_NEAR(0.0f, size.height, c_errorDelta);
    EXPECT_NEAR(0.0f, size.width, c_errorDelta);
    EXPECT_EQ(0, fitRange.location);
    EXPECT_EQ(0, fitRange.length);

    string = (__bridge CFAttributedStringRef)getAttributedString(@"ABCD");
    framesetter = CTFramesetterCreateWithAttributedString(string);
    CFAutorelease(framesetter);
    size = CTFramesetterSuggestFrameSizeWithConstraints(framesetter, CFRangeMake(0, 0), nil, CGSizeMake(FLT_MAX, FLT_MAX), &fitRange);
    EXPECT_LT(size.height, FLT_MAX);
    EXPECT_LT(size.width, FLT_MAX);
    EXPECT_EQ(0, fitRange.location);
    EXPECT_EQ(4, fitRange.length);

    size = CTFramesetterSuggestFrameSizeWithConstraints(framesetter, CFRangeMake(0, 3), nil, CGSizeMake(FLT_MAX, FLT_MAX), &fitRange);
    EXPECT_LT(size.height, FLT_MAX);
    EXPECT_LT(size.width, FLT_MAX);
    EXPECT_EQ(0, fitRange.location);
    EXPECT_EQ(3, fitRange.length);

    size = CTFramesetterSuggestFrameSizeWithConstraints(framesetter, CFRangeMake(0, 0), nil, CGSizeMake(50, 50), &fitRange);
    EXPECT_LE(size.height, 50);
    EXPECT_LE(size.width, 50);
    EXPECT_EQ(0, fitRange.location);
    EXPECT_LT(fitRange.length, 4);
}

TEST(CTFramesetter, ShouldNotThrowWhenCreatingFrameWithEmptyLines) {
    CFAttributedStringRef string = (__bridge CFAttributedStringRef)getAttributedString(@"TEST\n \n\n\t\nTEST");
    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(string);
    CFAutorelease(framesetter);
    CGPathRef path = CGPathCreateWithRect(CGRectMake(0, 0, FLT_MAX, FLT_MAX), nullptr);
    CTFrameRef frame = nil;
    EXPECT_NO_THROW(frame = CTFramesetterCreateFrame(framesetter, {}, path, nullptr));
    EXPECT_EQ(5L, CFArrayGetCount(CTFrameGetLines(frame)));
    CFRelease(frame);
    CGPathRelease(path);
} 