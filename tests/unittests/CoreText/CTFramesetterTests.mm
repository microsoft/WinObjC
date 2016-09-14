
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