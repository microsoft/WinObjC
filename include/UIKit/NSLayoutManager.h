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

#ifndef _NSLAYOUTMANAGER_H
#define _NSLAYOUTMANAGER_H

#import <UIKit/UIKitExport.h>
#import <UIKit/NSTextStorage.h>

@class NSTextStorage;
@class NSLayoutManager;
@class NSTextContainer;

@protocol NSLayoutManagerDelegate <NSObject>
- (void)layoutManagerDidInvalidateLayout:(NSLayoutManager*)sender;
@end

UIKIT_EXPORT_CLASS
@interface NSLayoutManager : NSObject
@property (assign, nonatomic) NSTextStorage* textStorage;
@property (assign, nonatomic) id<NSLayoutManagerDelegate> delegate;
@property (readonly, nonatomic) CGRect extraLineFragmentRect;

- (void)addTextContainer:(NSTextContainer*)container;
- (void)textContainerChangedGeometry:(NSTextContainer*)container;
- (void)drawGlyphsForGlyphRange:(NSRange)range atPoint:(CGPoint)position;
- (void)drawBackgroundForGlyphRange:(NSRange)range atPoint:(CGPoint)position;

- (CGRect)usedRectForTextContainer:(NSTextContainer*)tc;
- (CGPoint)locationForGlyphAtIndex:(NSUInteger)idx;
- (CGRect)boundingRectForGlyphRange:(NSRange)range inTextContainer:(NSTextContainer*)tc;
- (CGRect)lineFragmentRectForGlyphAtIndex:(NSUInteger)idx effectiveRange:(NSRange*)outGlyphRange;
- (NSUInteger)glyphIndexForPoint:(CGPoint)pt inTextContainer:(NSTextContainer*)container fractionOfDistanceThroughGlyph:(CGFloat*)fraction;
- (NSRange)characterRangeForGlyphRange:(NSRange)range actualGlyphRange:(NSRange*)actualRange;

- (NSRange)glyphRangeForCharacterRange:(NSRange)range actualCharacterRange:(NSRange*)actualRange;
- (NSTextContainer*)textContainerForGlyphAtIndex:(NSUInteger)glyphIndex effectiveRange:(NSRange*)effectiveRange;
- (void)invalidateDisplayForCharacterRange:(NSRange)range;
- (void)processEditingForTextStorage:(NSTextStorage*)textStorage
                              edited:(NSTextStorageEditActions)actions
                               range:(NSRange)editRange
                      changeInLength:(NSInteger)deltaLen
                    invalidatedRange:(NSRange)invalidRange;
- (NSUInteger)characterIndexForPoint:(CGPoint)point
                             inTextContainer:(NSTextContainer*)container
    fractionOfDistanceBetweenInsertionPoints:(CGFloat*)distance;
@end

#endif /* _NSLAYOUTMANAGER_H */
