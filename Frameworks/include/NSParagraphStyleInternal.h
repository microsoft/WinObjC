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

#pragma once

#import <UIKit/NSMutableParagraphStyle.h>
#import <CoreText/CTParagraphStyle.h>

@interface NSParagraphStyle ()
@property (nonatomic) NSTextAlignment alignment;
@property (nonatomic) CGFloat firstLineHeadIndent;
@property (nonatomic) CGFloat headIndent;
@property (nonatomic) CGFloat tailIndent;
@property (nonatomic) NSLineBreakMode lineBreakMode;
@property (nonatomic) CGFloat maximumLineHeight;
@property (nonatomic) CGFloat minimumLineHeight;
@property (nonatomic) CGFloat lineSpacing;
@property (nonatomic) CGFloat paragraphSpacing;
@property (nonatomic) CGFloat paragraphSpacingBefore;
@property (nonatomic) NSWritingDirection baseWritingDirection;
@property (nonatomic) CGFloat lineHeightMultiple;
@property (copy, nonatomic) NSArray* tabStops;
@property (nonatomic) CGFloat defaultTabInterval;
@property (nonatomic) float hyphenationFactor;
- (CTParagraphStyleRef)_convertToCTParagraphStyle;
@end

// The values of right and center CTTextAlignment and NSTextAlignment do not correspond so they can't be simply cast
inline CTTextAlignment _NSTextAlignmentToCTTextAlignment(NSTextAlignment alignment) {
    switch (alignment) {
        case UITextAlignmentRight:
            return kCTRightTextAlignment;
        case UITextAlignmentCenter:
            return kCTCenterTextAlignment;
        default:
            return alignment;
    }
}
