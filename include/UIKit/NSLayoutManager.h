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
#import <UIKit/NSTextStorage.h>
#import <CoreGraphics/CGFont.h>
#import <CoreGraphics/CGAffineTransform.h>
#import <CoreGraphics/CGContext.h>
#import <UIKit/UIKitTypes.h>

typedef NSInteger NSTextLayoutOrientation;
typedef NSInteger NSGlyphProperty;
typedef NSInteger NSControlCharacterAction;
enum {
    NSTextLayoutOrientationHorizontal = 0,
    NSTextLayoutOrientationVertical = 1,
};
enum {
    NSGlyphPropertyNull = (1 << 0),
    NSGlyphPropertyControlCharacter = (1 << 1),
    NSGlyphPropertyElastic = (1 << 2),
    NSGlyphPropertyNonBaseCharacter = (1 << 3)
};
enum {
    NSControlCharacterZeroAdvancementAction = (1 << 0),
    NSControlCharacterWhitespaceAction = (1 << 1),
    NSControlCharacterHorizontalTabAction = (1 << 2),
    NSControlCharacterLineBreakAction = (1 << 3),
    NSControlCharacterParagraphBreakAction = (1 << 4),
    NSControlCharacterContainerBreakAction = (1 << 5)
};

@class NSTextStorage;
@class NSTextContainer;
@class NSArray;
@protocol NSLayoutManagerDelegate;
@class UIFont;
@class UIColor;
@class NSDictionary;

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

@property (readonly, nonatomic) NSArray* textContainers STUB_PROPERTY;
- (void)insertTextContainer:(NSTextContainer*)container atIndex:(NSUInteger)index STUB_METHOD;
- (void)removeTextContainerAtIndex:(NSUInteger)index STUB_METHOD;
- (void)setTextContainer:(NSTextContainer*)container forGlyphRange:(NSRange)glyphRange STUB_METHOD;
@property (nonatomic) BOOL allowsNonContiguousLayout STUB_PROPERTY;
@property (readonly, nonatomic) BOOL hasNonContiguousLayout STUB_PROPERTY;
@property (nonatomic) CGFloat hyphenationFactor STUB_PROPERTY;
@property (nonatomic) BOOL showsControlCharacters STUB_PROPERTY;
@property (nonatomic) BOOL showsInvisibleCharacters STUB_PROPERTY;
@property (nonatomic) BOOL usesFontLeading STUB_PROPERTY;
- (void)invalidateDisplayForGlyphRange:(NSRange)glyphRange STUB_METHOD;
- (void)invalidateGlyphsForCharacterRange:(NSRange)charRange
                           changeInLength:(NSInteger)delta
                     actualCharacterRange:(NSRangePointer)actualCharRange STUB_METHOD;
- (void)invalidateLayoutForCharacterRange:(NSRange)charRange actualCharacterRange:(NSRangePointer)actualCharRange STUB_METHOD;
- (void)ensureGlyphsForCharacterRange:(NSRange)charRange STUB_METHOD;
- (void)ensureGlyphsForGlyphRange:(NSRange)glyphRange STUB_METHOD;
- (void)ensureLayoutForBoundingRect:(CGRect)bounds inTextContainer:(NSTextContainer*)container STUB_METHOD;
- (void)ensureLayoutForCharacterRange:(NSRange)charRange STUB_METHOD;
- (void)ensureLayoutForGlyphRange:(NSRange)glyphRange STUB_METHOD;
- (void)ensureLayoutForTextContainer:(NSTextContainer*)container STUB_METHOD;
- (void)setGlyphs:(const CGGlyph*)glyphs
       properties:(const NSGlyphProperty*)props
 characterIndexes:(const NSUInteger*)charIndexes
             font:(UIFont*)aFont
    forGlyphRange:(NSRange)glyphRange STUB_METHOD;
- (NSUInteger)characterIndexForGlyphAtIndex:(NSUInteger)glyphIndex STUB_METHOD;
- (NSUInteger)getGlyphsInRange:(NSRange)glyphRange
                        glyphs:(CGGlyph*)glyphBuffer
                    properties:(NSGlyphProperty*)props
              characterIndexes:(NSUInteger*)charIndexBuffer
                    bidiLevels:(unsigned char*)bidiLevelBuffer STUB_METHOD;
- (CGGlyph)glyphAtIndex:(NSUInteger)glyphIndex STUB_METHOD;
- (CGGlyph)glyphAtIndex:(NSUInteger)glyphIndex isValidIndex:(BOOL*)isValidIndex STUB_METHOD;
- (NSUInteger)glyphIndexForCharacterAtIndex:(NSUInteger)charIndex STUB_METHOD;
- (BOOL)isValidGlyphIndex:(NSUInteger)glyphIndex STUB_METHOD;
@property (readonly, nonatomic) NSUInteger numberOfGlyphs STUB_PROPERTY;
- (NSGlyphProperty)propertyForGlyphAtIndex:(NSUInteger)glyphIndex STUB_METHOD;
- (void)setAttachmentSize:(CGSize)attachmentSize forGlyphRange:(NSRange)glyphRange STUB_METHOD;
- (void)setDrawsOutsideLineFragment:(BOOL)flag forGlyphAtIndex:(NSUInteger)glyphIndex STUB_METHOD;
- (void)setExtraLineFragmentRect:(CGRect)fragmentRect usedRect:(CGRect)usedRect textContainer:(NSTextContainer*)container STUB_METHOD;
- (void)setLineFragmentRect:(CGRect)fragmentRect forGlyphRange:(NSRange)glyphRange usedRect:(CGRect)usedRect STUB_METHOD;
- (void)setLocation:(CGPoint)location forStartOfGlyphRange:(NSRange)glyphRange STUB_METHOD;
- (void)setNotShownAttribute:(BOOL)flag forGlyphAtIndex:(NSUInteger)glyphIndex STUB_METHOD;
- (CGSize)attachmentSizeForGlyphAtIndex:(NSUInteger)glyphIndex STUB_METHOD;
- (BOOL)drawsOutsideLineFragmentForGlyphAtIndex:(NSUInteger)glyphIndex STUB_METHOD;
@property (readonly, nonatomic) NSTextContainer* extraLineFragmentTextContainer STUB_PROPERTY;
@property (readonly, nonatomic) CGRect extraLineFragmentUsedRect STUB_PROPERTY;
- (NSUInteger)firstUnlaidCharacterIndex STUB_METHOD;
- (NSUInteger)firstUnlaidGlyphIndex STUB_METHOD;
- (void)getFirstUnlaidCharacterIndex:(NSUInteger*)charIndex glyphIndex:(NSUInteger*)glyphIndex STUB_METHOD;
- (CGRect)lineFragmentUsedRectForGlyphAtIndex:(NSUInteger)glyphIndex effectiveRange:(NSRangePointer)effectiveGlyphRange STUB_METHOD;
- (BOOL)notShownAttributeForGlyphAtIndex:(NSUInteger)glyphIndex STUB_METHOD;
- (NSRange)truncatedGlyphRangeInLineFragmentForGlyphAtIndex:(NSUInteger)glyphIndex STUB_METHOD;
- (void)enumerateEnclosingRectsForGlyphRange:(NSRange)glyphRange
                    withinSelectedGlyphRange:(NSRange)selectedRange
                             inTextContainer:(NSTextContainer*)textContainer
                                  usingBlock:(void (^)(CGRect, BOOL*))block STUB_METHOD;
- (void)enumerateLineFragmentsForGlyphRange:(NSRange)glyphRange
                                 usingBlock:(void (^)(CGRect, CGRect, NSTextContainer*, NSRange, BOOL*))block STUB_METHOD;
- (CGFloat)fractionOfDistanceThroughGlyphForPoint:(CGPoint)point inTextContainer:(NSTextContainer*)container STUB_METHOD;
- (NSUInteger)getLineFragmentInsertionPointsForCharacterAtIndex:(NSUInteger)charIndex
                                             alternatePositions:(BOOL)aFlag
                                                 inDisplayOrder:(BOOL)dFlag
                                                      positions:(CGFloat*)positions
                                               characterIndexes:(NSUInteger*)charIndexes STUB_METHOD;
- (NSUInteger)glyphIndexForPoint:(CGPoint)point inTextContainer:(NSTextContainer*)container STUB_METHOD;
- (NSRange)glyphRangeForBoundingRect:(CGRect)bounds inTextContainer:(NSTextContainer*)container STUB_METHOD;
- (NSRange)glyphRangeForBoundingRectWithoutAdditionalLayout:(CGRect)bounds inTextContainer:(NSTextContainer*)container STUB_METHOD;
- (NSRange)glyphRangeForTextContainer:(NSTextContainer*)container STUB_METHOD;
- (NSRange)rangeOfNominallySpacedGlyphsContainingIndex:(NSUInteger)glyphIndex STUB_METHOD;
- (void)drawStrikethroughForGlyphRange:(NSRange)glyphRange
                     strikethroughType:(NSUnderlineStyle)strikethroughVal
                        baselineOffset:(CGFloat)baselineOffset
                      lineFragmentRect:(CGRect)lineRect
                lineFragmentGlyphRange:(NSRange)lineGlyphRange
                       containerOrigin:(CGPoint)containerOrigin STUB_METHOD;
- (void)drawUnderlineForGlyphRange:(NSRange)glyphRange
                     underlineType:(NSUnderlineStyle)underlineVal
                    baselineOffset:(CGFloat)baselineOffset
                  lineFragmentRect:(CGRect)lineRect
            lineFragmentGlyphRange:(NSRange)lineGlyphRange
                   containerOrigin:(CGPoint)containerOrigin STUB_METHOD;
- (void)fillBackgroundRectArray:(const CGRect*)rectArray
                          count:(NSUInteger)rectCount
              forCharacterRange:(NSRange)charRange
                          color:(UIColor*)color STUB_METHOD;
- (void)showCGGlyphs:(const CGGlyph*)glyphs
           positions:(const CGPoint*)positions
               count:(NSUInteger)glyphCount
                font:(UIFont*)font
              matrix:(CGAffineTransform)textMatrix
          attributes:(NSDictionary*)attributes
           inContext:(CGContextRef)graphicsContext STUB_METHOD;
- (void)strikethroughGlyphRange:(NSRange)glyphRange
              strikethroughType:(NSUnderlineStyle)strikethroughVal
               lineFragmentRect:(CGRect)lineRect
         lineFragmentGlyphRange:(NSRange)lineGlyphRange
                containerOrigin:(CGPoint)containerOrigin STUB_METHOD;
- (void)underlineGlyphRange:(NSRange)glyphRange
              underlineType:(NSUnderlineStyle)underlineVal
           lineFragmentRect:(CGRect)lineRect
     lineFragmentGlyphRange:(NSRange)lineGlyphRange
            containerOrigin:(CGPoint)containerOrigin STUB_METHOD;
@end
