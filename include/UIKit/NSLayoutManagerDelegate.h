//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <UIKit/UIKitExport.h>
#import <CoreGraphics/CGGeometry.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CGFont.h>
#import <UIKit/NSLayoutManager.h>

@class NSLayoutManager;
@class NSTextContainer;
@class UIFont;

@protocol NSLayoutManagerDelegate <NSObject>
@optional
- (BOOL)layoutManager:(NSLayoutManager*)layoutManager shouldBreakLineByHyphenatingBeforeCharacterAtIndex:(NSUInteger)charIndex;
- (BOOL)layoutManager:(NSLayoutManager*)layoutManager shouldBreakLineByWordBeforeCharacterAtIndex:(NSUInteger)charIndex;
- (CGFloat)layoutManager:(NSLayoutManager*)layoutManager
    lineSpacingAfterGlyphAtIndex:(NSUInteger)glyphIndex
    withProposedLineFragmentRect:(CGRect)rect;
- (CGFloat)layoutManager:(NSLayoutManager*)layoutManager
    paragraphSpacingAfterGlyphAtIndex:(NSUInteger)glyphIndex
         withProposedLineFragmentRect:(CGRect)rect;
- (CGFloat)layoutManager:(NSLayoutManager*)layoutManager
    paragraphSpacingBeforeGlyphAtIndex:(NSUInteger)glyphIndex
          withProposedLineFragmentRect:(CGRect)rect;
- (CGRect)layoutManager:(NSLayoutManager*)layoutManager
    boundingBoxForControlGlyphAtIndex:(NSUInteger)glyphIndex
                     forTextContainer:(NSTextContainer*)textContainer
                 proposedLineFragment:(CGRect)proposedRect
                        glyphPosition:(CGPoint)glyphPosition
                       characterIndex:(NSUInteger)charIndex;
- (void)layoutManager:(NSLayoutManager*)layoutManager
    didCompleteLayoutForTextContainer:(NSTextContainer*)textContainer
                                atEnd:(BOOL)layoutFinishedFlag;
- (void)layoutManager:(NSLayoutManager*)layoutManager
                textContainer:(NSTextContainer*)textContainer
    didChangeGeometryFromSize:(CGSize)oldSize;
- (NSUInteger)layoutManager:(NSLayoutManager*)layoutManager
       shouldGenerateGlyphs:(const CGGlyph*)glyphs
                 properties:(const NSGlyphProperty*)props
           characterIndexes:(const NSUInteger*)charIndexes
                       font:(UIFont*)aFont
              forGlyphRange:(NSRange)glyphRange;
- (NSControlCharacterAction)layoutManager:(NSLayoutManager*)layoutManager
                          shouldUseAction:(NSControlCharacterAction)action
               forControlCharacterAtIndex:(NSUInteger)charIndex;
- (void)layoutManagerDidInvalidateLayout:(NSLayoutManager*)sender;
;
@end
