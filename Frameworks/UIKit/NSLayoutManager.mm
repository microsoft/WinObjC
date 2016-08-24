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

#include <StubReturn.h>
#include "Starboard.h"

#include "UIKit/NSLayoutManager.h"

#include "CoreTextInternal.h"

#include <vector>

@implementation NSLayoutManager {
    NSMutableArray* _textContainers;
    idretaintype(NSTextStorage) _textStorage;
    NSMutableArray* _ctLines;
    std::vector<CGPoint> _lineOrigins;
    CGSize _totalSize;
    BOOL _needsLayout;
}

typedef float (^CalcWidthBlock)(CFIndex idx, float offset, float height);

static float invokeWidthBlock(void* opaque, CFIndex idx, float offset, float height) {
    CalcWidthBlock cwb = (CalcWidthBlock)opaque;
    return cwb(idx, offset, height);
}

- (void)_layoutAllText {
    [_ctLines removeAllObjects];
    _lineOrigins.clear();

    CTTypesetterRef ts = CTTypesetterCreateWithAttributedString((CFAttributedStringRef)(NSTextStorage*)_textStorage);

    _totalSize.width = 0;
    _totalSize.height = 0;

    NSTextContainer* container = (NSTextContainer*)_textContainers[0];
    CGSize containerSize = container.size;
    float y = 0.0f;
    CFIndex curIdx = 0;
    NSString* string = [_textStorage string];
    CFIndex stringRange = [string length];
    bool lastRunWasLineBreak = false;
    __block float lastFontHeight = 0.0f;

    while (curIdx < [string length]) {
        float maxLineHeight = 0.0f;
        __block float maxFontHeight = 0.0f;
        __block bool stop = false;
        float curX = container.lineFragmentPadding;
        float maxAscent = 0.0f;

        lastRunWasLineBreak = false;
        int numLines = _lineOrigins.size();

        while (curIdx < [string length] && !stop) {
            CGPoint startPoint = CGPointMake(curX, y);
            __block float newX = curX;
            __block float lastProposedSize = 0.0f;

            //  Ask the typesetter to fit and characters within a given width; it will call us
            //  to ask what the maximum width is, once it figures out the height it needs to put
            //  a single character in
            CFIndex pos =
                _CTTypesetterSuggestLineBreakWithOffsetAndCallback(ts,
                                                                   curIdx,
                                                                   0,
                                                                   invokeWidthBlock,
                                                                   ^float(CFIndex idx, float offset, float height) {
                                                                       lastFontHeight = height;
                                                                       if (height > maxFontHeight) {
                                                                           maxFontHeight = height;
                                                                       }
                                                                       CGRect proposed = CGRectMake(curX + offset,
                                                                                                    y + maxFontHeight - height,
                                                                                                    containerSize.width - (curX + offset),
                                                                                                    height);
                                                                       CGRect lineRect = [container
                                                                           lineFragmentRectForProposedRect:proposed
                                                                                                   atIndex:idx
                                                                                          writingDirection:NSWritingDirectionLeftToRight
                                                                                             remainingRect:&proposed];

                                                                       if (lineRect.size.width == 0.0f) {
                                                                           stop = true;
                                                                           return 0.0f;
                                                                       }

                                                                       if (lineRect.origin.x != curX + offset) {
                                                                           newX = lineRect.origin.x;
                                                                           return 0.0f;
                                                                       }
                                                                       if (lineRect.origin.x + lineRect.size.width > newX) {
                                                                           newX = lineRect.origin.x + lineRect.size.width;
                                                                       }

                                                                       float ret = lineRect.size.width;
                                                                       if (ret < 0.0f) {
                                                                           ret = 0.0f;
                                                                       }
                                                                       if (ret > 0.0f) {
                                                                           lastProposedSize = ret;
                                                                       }
                                                                       return ret;
                                                                   });

            //  Always advance at least 5px
            curX = newX;
            if (curX <= startPoint.x + 5.0f) {
                curX = startPoint.x + 5.0f;
            }

            //  In the case that the typesetter cannot fit one character into the container, and the
            //  proposed size is the full width of the container (there are no exclusions) draw one
            //  glyph. One caveat is this does not take into account exclusion zones outside the
            //  container.
            if ((pos == curIdx) && ((lastProposedSize + container.lineFragmentPadding) >= containerSize.width)) {
                pos = curIdx + 1;
            }

            //  Did we determine that we can fit at least one character?
            if (pos != curIdx) {
                //  Yes, we will record what the (x,y) origin is and create a new CTLine from it
                CFRange lineRange;
                lineRange.location = curIdx;
                lineRange.length = pos - curIdx;

                CTLineRef line = CTTypesetterCreateLine(ts, lineRange);

                float ascent = 0.0f, descent = 0.0f, leading = 0.0f;
                float width = CTLineGetTypographicBounds(line, &ascent, &descent, &leading);
                float lineHeight = ascent - descent + leading;

                CGPoint lineOrigin;
                lineOrigin = startPoint;
                [_ctLines addObject:(id)line];
                _lineOrigins.push_back(lineOrigin);
                CFRelease(line);

                //  Record what the height of the line was; we'll need to adjust all lines that fit within
                curIdx = pos;
                if (lineOrigin.x + width > _totalSize.width) {
                    _totalSize.width = lineOrigin.x + width;
                }
                if (lineHeight > maxLineHeight) {
                    maxLineHeight = lineHeight;
                }
                if (ascent > maxAscent) {
                    maxAscent = ascent;
                }
            }

            //  If the last character was a line break, exit this line early
            if (curIdx > 0) {
                unichar c = [string characterAtIndex:curIdx - 1];
                if (c == 10 || c == 13) {
                    lastRunWasLineBreak = true;
                    break;
                }
            }

            if (curX >= containerSize.width) {
                break;
            }
        }

        //  Align baselines for all runs added to this line
        for (int curIdx = numLines; curIdx < _lineOrigins.size(); curIdx++) {
            float ascent = 0.0f, descent = 0.0f, leading = 0.0f;
            CTLineGetTypographicBounds((CTLineRef)[_ctLines objectAtIndex:curIdx], &ascent, &descent, &leading);

            _lineOrigins[curIdx].y += maxAscent - ascent;
        }

        if (maxLineHeight > 0) {
            y += maxLineHeight;
        } else {
            y += maxFontHeight;
        }

        if (y > containerSize.height) {
            break;
        }
    }

    //  Calculate the insertion point
    if (lastRunWasLineBreak) {
        CGRect rect;

        rect.origin.x = 0.0f;
        rect.origin.y = y;
        rect.size.height = lastFontHeight;
        rect.size.width = 5;

        _extraLineFragmentRect = rect;

        y += lastFontHeight;
        _totalSize.height = y;
    } else {
        _totalSize.height = y;

        CGRect rect;

        rect = [self boundingRectForGlyphRange:NSMakeRange([string length] - 1, 1) inTextContainer:container];
        rect.origin.x += rect.size.width;
        rect.size.width = 2;

        _extraLineFragmentRect = rect;
    }

    CFRelease(ts);
}

- (void)layoutIfNeeded {
    if (_needsLayout) {
        _needsLayout = FALSE;
        [self _layoutAllText];
    }
}

/**
 @Status Interoperable
*/

- (instancetype)init {
    _textContainers = [NSMutableArray new];
    _ctLines = [NSMutableArray new];
    _needsLayout = TRUE;
    return self;
}

/**
 @Status Interoperable
*/

- (void)addTextContainer:(NSTextContainer*)container {
    [_textContainers addObject:container];
    container.layoutManager = self;
    _needsLayout = TRUE;
}

/**
 @Status Interoperable
*/

- (void)setTextStorage:(NSTextStorage*)storage {
    _textStorage = storage;
    [_textStorage addLayoutManager:self];
}

/**
 @Status Interoperable
*/

- (NSTextStorage*)textStorage {
    return _textStorage;
}

/**
 @Status Interoperable
*/

- (void)drawBackgroundForGlyphRange:(NSRange)range atPoint:(CGPoint)position {
}

/**
 @Status Caveat

 @Notes range parameter is not supported
*/

- (void)drawGlyphsForGlyphRange:(NSRange)range atPoint:(CGPoint)position {
    [self layoutIfNeeded];

    CGContextRef curCtx = UIGraphicsGetCurrentContext();
    CGContextSaveGState(curCtx);

    CGContextSetTextPosition(curCtx, 0, 0);
    CGContextTranslateCTM(curCtx, position.x, position.y);

    int count = [_ctLines count];
    CGAffineTransform t;

    t = CGAffineTransformMakeScale(1.0, -1.0);
    CGContextSetTextMatrix(curCtx, t);
    for (int curLine = 0; curLine < count; curLine++) {
        CTLineRef line = (CTLineRef)_ctLines[curLine];

        float ascent, descent, leading;
        CTLineGetTypographicBounds(line, &ascent, &descent, &leading);

        CGContextSaveGState(curCtx);
        CGContextTranslateCTM(curCtx, _lineOrigins[curLine].x, _lineOrigins[curLine].y + ascent);
        CTLineDraw(line, curCtx);
        CGContextRestoreGState(curCtx);
    }
    CGContextRestoreGState(curCtx);
}

/**
 @Status Caveat

 @Notes Text container parameter is not supported
*/

- (CGRect)usedRectForTextContainer:(NSTextContainer*)tc {
    [self layoutIfNeeded];

    CGRect ret;

    ret.origin.x = 0;
    ret.origin.y = 0;
    ret.size = _totalSize;
    return ret;
}

static NSRange NSRangeFromCFRange(CFRange range) {
    NSRange ret;

    ret.location = range.location;
    ret.length = range.length;

    return ret;
}

- (CGRect)_rectForLine:(NSUInteger)lineIdx {
    CGPoint origin = _lineOrigins[lineIdx];
    CGRect ret;

    ret.origin = _lineOrigins[lineIdx];

    CGFloat ascent, descent, leading;

    ret.size.width = _totalSize.width;

    CTLineGetTypographicBounds((CTLineRef)_ctLines[lineIdx], &ascent, &descent, &leading);
    ret.size.height = ascent - descent + leading;

    return ret;
}

/**
 @Status Caveat

 @Notes There is currently no distinction between character ranges and glyph ranges.
*/

- (NSRange)characterRangeForGlyphRange:(NSRange)range actualGlyphRange:(NSRange*)actualRange {
    [self layoutIfNeeded];

    /*** Caveat: Character ranges and glyph ranges are the same ***/
    if (actualRange) {
        *actualRange = range;
    }
    return range;
}

/**
 @Status Caveat

 @Notes There is currently no distinction between character ranges and glyph ranges.
*/

- (NSRange)glyphRangeForCharacterRange:(NSRange)range actualCharacterRange:(NSRange*)actualRange {
    [self layoutIfNeeded];

    /*** Caveat: Character ranges and glyph ranges are the same ***/
    if (actualRange) {
        *actualRange = range;
    }
    return range;
}

/**
 @Status Caveat

 @Notes Only one text container is supported - this method returns text container zero, effectiveRange is not supported, effectiveRange
 parameter not supported.
*/

- (NSTextContainer*)textContainerForGlyphAtIndex:(NSUInteger)glyphIndex effectiveRange:(NSRange*)effectiveRange {
    [self layoutIfNeeded];

    /*** Caveat: We can only handle one text container ***/
    NSTextContainer* ret = [_textContainers objectAtIndex:0];

    if (effectiveRange) {
        UNIMPLEMENTED_WITH_MSG("effectiveRange parameter not supported.");
    }

    return ret;
}

/**
 @Status Caveat

 @Notes The text container parameter is ignored.
*/

- (CGRect)boundingRectForGlyphRange:(NSRange)range inTextContainer:(NSTextContainer*)tc {
    [self layoutIfNeeded];

    CGRect ret = CGRectNull;
    int count = [_ctLines count];

    for (int curLineIdx = 0; curLineIdx < count; curLineIdx++) {
        CTLineRef curLine = (CTLineRef)_ctLines[curLineIdx];

        NSRange lineRange = NSRangeFromCFRange(CTLineGetStringRange(curLine));

        if (NSIntersectionRange(lineRange, range).length > 0) {
            CFArrayRef runs = CTLineGetGlyphRuns(curLine);
            int runCount = CFArrayGetCount(runs);

            for (int curRunIdx = 0; curRunIdx < runCount; curRunIdx++) {
                CTRunRef curRun = (CTRunRef)CFArrayGetValueAtIndex(runs, curRunIdx);

                CFRange runRange = CTRunGetStringRange(curRun);
                NSRange intersection = NSIntersectionRange(NSRangeFromCFRange(runRange), range);
                if (intersection.length > 0) {
                    CGRect lineRect = [self _rectForLine:curLineIdx];

                    NSRange runIntersection;

                    runIntersection.location = intersection.location - runRange.location;
                    runIntersection.length = intersection.length;

                    CGPoint firstLetterPosition, lastLetterPosition;

                    CFRange pos;

                    pos.location = runIntersection.location;
                    pos.length = 1;
                    CTRunGetPositions(curRun, pos, &firstLetterPosition);

                    pos.location = runIntersection.location + runIntersection.length - 1;
                    pos.length = 1;
                    CTRunGetPositions(curRun, pos, &lastLetterPosition);

                    CGSize lastLetterAdvance;
                    CTRunGetAdvances(curRun, pos, &lastLetterAdvance);

                    //  Construct a rectangle and union it with our current rectangle
                    CGRect runRect;
                    runRect.origin.x = lineRect.origin.x + firstLetterPosition.x;
                    runRect.origin.y = lineRect.origin.y;
                    runRect.size.width = (lastLetterPosition.x + lastLetterAdvance.width) - firstLetterPosition.x;
                    runRect.size.height = lineRect.size.height;

                    ret = CGRectUnion(ret, runRect);
                }
            }
        }
    }

    if (CGRectIsNull(ret)) {
        ret = CGRectMake(0, 0, 0, 0);
    }

    return ret;
}

/**
 @Status Caveat

 @Notes fraction is always returned as 0.0
*/

- (NSUInteger)glyphIndexForPoint:(CGPoint)pt inTextContainer:(NSTextContainer*)container fractionOfDistanceThroughGlyph:(CGFloat*)fraction {
    /*** Caveat: Fraction is not returned ***/

    [self layoutIfNeeded];

    int lineCount = [_ctLines count];

    if (lineCount == 0)
        return 0;
    int ret = 0;

    //  Find the closest line
    int closestLine = 0;
    float closestDistance = FLT_MAX;
    CGRect lineRect = CGRectMake(0, 0, 0, 0);

    for (int curLineIdx = 0; curLineIdx < lineCount; curLineIdx++) {
        CGRect rect = [self _rectForLine:curLineIdx];

        if (CGRectContainsPoint(rect, pt)) {
            closestLine = curLineIdx;
            lineRect = rect;
            break;
        }

        float dist1 = fabs(rect.origin.y - pt.y);
        if (dist1 < closestDistance) {
            closestLine = curLineIdx;
            closestDistance = dist1;
            lineRect = rect;
        }
        float dist2 = fabs(rect.origin.y + rect.size.height - pt.y);
        if (dist2 < closestDistance) {
            closestLine = curLineIdx;
            closestDistance = dist2;
            lineRect = rect;
        }
    }

    //  Find the closest glyph within this run
    closestDistance = FLT_MAX;
    CFArrayRef runs = CTLineGetGlyphRuns((CTLineRef)_ctLines[closestLine]);
    int runCount = CFArrayGetCount(runs);
    bool stop = false;

    for (int curRunIdx = 0; curRunIdx < runCount && !stop; curRunIdx++) {
        CTRunRef curRun = (CTRunRef)CFArrayGetValueAtIndex(runs, curRunIdx);

        CFRange runRange = CTRunGetStringRange(curRun);
        CGPoint* glyphPositions = (CGPoint*)IwMalloc(sizeof(CGPoint) * runRange.length);
        CGSize* glyphSizes = (CGSize*)IwMalloc(sizeof(CGSize) * runRange.length);

        CFRange indexes;
        indexes.location = 0;
        indexes.length = runRange.length;

        CTRunGetPositions(curRun, indexes, glyphPositions);
        CTRunGetAdvances(curRun, indexes, glyphSizes);

        for (int curCharIdx = 0; curCharIdx < indexes.length; curCharIdx++) {
            //  Construct a rectangle for this glyph
            CGRect glyphRect;
            glyphRect.origin.x = lineRect.origin.x + glyphPositions[curCharIdx].x;
            glyphRect.origin.y = lineRect.origin.y;
            glyphRect.size.width = glyphSizes[curCharIdx].width;
            glyphRect.size.height = lineRect.size.height;

            if (CGRectContainsPoint(glyphRect, pt)) {
                ret = runRange.location + curCharIdx;
                stop = true;
                break;
            }

            float dist1 = fabs(glyphRect.origin.x - pt.x);
            if (dist1 < closestDistance) {
                ret = runRange.location + curCharIdx;
                closestDistance = dist1;
            }
            float dist2 = fabs(glyphRect.origin.x + glyphRect.size.width - pt.x);
            if (dist2 < closestDistance) {
                ret = runRange.location + curCharIdx;
                closestDistance = dist2;
            }
        }

        IwFree(glyphPositions);
        IwFree(glyphSizes);
    }

    return ret;
}

/**
 @Status Interoperable
*/

- (CGRect)lineFragmentRectForGlyphAtIndex:(NSUInteger)idx effectiveRange:(NSRange*)outGlyphRange {
    [self layoutIfNeeded];

    int count = [_ctLines count];

    for (int curLineIdx = 0; curLineIdx < count; curLineIdx++) {
        CTLineRef curLine = (CTLineRef)_ctLines[curLineIdx];

        CFRange lineRange = CTLineGetStringRange(curLine);

        if (lineRange.location <= idx && lineRange.location + lineRange.length > idx) {
            CGRect ret = [self _rectForLine:curLineIdx];

            if (outGlyphRange) {
                outGlyphRange->location = lineRange.location;
                outGlyphRange->length = lineRange.length;
            }

            return ret;
        }
    }

    CGRect ret = { 0 };
    return ret;
}

/**
 @Status Interoperable
*/

- (CGPoint)locationForGlyphAtIndex:(NSUInteger)idx {
    [self layoutIfNeeded];

    int count = [_ctLines count];

    for (int curLineIdx = 0; curLineIdx < count; curLineIdx++) {
        CTLineRef curLine = (CTLineRef)_ctLines[curLineIdx];

        CFRange lineRange = CTLineGetStringRange(curLine);

        if (lineRange.location <= idx && lineRange.location + lineRange.length > idx) {
            CFArrayRef runs = CTLineGetGlyphRuns(curLine);
            int runCount = CFArrayGetCount(runs);

            for (int curRunIdx = 0; curRunIdx < runCount; curRunIdx++) {
                CTRunRef curRun = (CTRunRef)CFArrayGetValueAtIndex(runs, curRunIdx);

                CFRange runRange = CTRunGetStringRange(curRun);
                if (runRange.location <= idx && runRange.location + runRange.length > idx) {
                    CGPoint ret;

                    CFRange pos;
                    pos.location = idx - runRange.location;
                    pos.length = 1;

                    CTRunGetPositions(curRun, pos, &ret);

                    return ret;
                }
            }
        }
    }

    CGPoint ret;

    ret.x = 0;
    ret.y = 0;
    return ret;
}

/**
 @Status Caveat

 @Notes This call always invalidates the entire text range
*/

- (void)invalidateDisplayForCharacterRange:(NSRange)range {
    _needsLayout = TRUE;
    [_delegate layoutManagerDidInvalidateLayout:self];
}

/**
 @Status Interoperable
*/

- (void)textContainerChangedGeometry:(NSTextContainer*)container {
    NSRange range;

    range.location = 0;
    range.length = [_textStorage length];

    [self invalidateDisplayForCharacterRange:range];
}

/**
 @Status Caveat

 @Notes This call always invalidates the entire text range
*/

- (void)processEditingForTextStorage:(NSTextStorage*)textStorage
                              edited:(NSTextStorageEditActions)actions
                               range:(NSRange)editRange
                      changeInLength:(NSInteger)deltaLen
                    invalidatedRange:(NSRange)invalidRange {
    [self invalidateDisplayForCharacterRange:invalidRange];
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_textContainers release];
    [_ctLines release];
    [super dealloc];
}

/**
 @Status Stub
 @Notes
*/
- (void)insertTextContainer:(NSTextContainer*)container atIndex:(NSUInteger)index {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeTextContainerAtIndex:(NSUInteger)index {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setTextContainer:(NSTextContainer*)container forGlyphRange:(NSRange)glyphRange {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)invalidateDisplayForGlyphRange:(NSRange)glyphRange {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)invalidateGlyphsForCharacterRange:(NSRange)charRange
                           changeInLength:(NSInteger)delta
                     actualCharacterRange:(NSRangePointer)actualCharRange {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)invalidateLayoutForCharacterRange:(NSRange)charRange actualCharacterRange:(NSRangePointer)actualCharRange {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)ensureGlyphsForCharacterRange:(NSRange)charRange {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)ensureGlyphsForGlyphRange:(NSRange)glyphRange {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)ensureLayoutForBoundingRect:(CGRect)bounds inTextContainer:(NSTextContainer*)container {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)ensureLayoutForCharacterRange:(NSRange)charRange {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)ensureLayoutForGlyphRange:(NSRange)glyphRange {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)ensureLayoutForTextContainer:(NSTextContainer*)container {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setGlyphs:(const CGGlyph*)glyphs
       properties:(const NSGlyphProperty*)props
 characterIndexes:(const NSUInteger*)charIndexes
             font:(UIFont*)aFont
    forGlyphRange:(NSRange)glyphRange {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)characterIndexForGlyphAtIndex:(NSUInteger)glyphIndex {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)getGlyphsInRange:(NSRange)glyphRange
                        glyphs:(CGGlyph*)glyphBuffer
                    properties:(NSGlyphProperty*)props
              characterIndexes:(NSUInteger*)charIndexBuffer
                    bidiLevels:(unsigned char*)bidiLevelBuffer {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (CGGlyph)glyphAtIndex:(NSUInteger)glyphIndex {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (CGGlyph)glyphAtIndex:(NSUInteger)glyphIndex isValidIndex:(BOOL*)isValidIndex {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)glyphIndexForCharacterAtIndex:(NSUInteger)charIndex {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isValidGlyphIndex:(NSUInteger)glyphIndex {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSGlyphProperty)propertyForGlyphAtIndex:(NSUInteger)glyphIndex {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setAttachmentSize:(CGSize)attachmentSize forGlyphRange:(NSRange)glyphRange {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setDrawsOutsideLineFragment:(BOOL)flag forGlyphAtIndex:(NSUInteger)glyphIndex {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setExtraLineFragmentRect:(CGRect)fragmentRect usedRect:(CGRect)usedRect textContainer:(NSTextContainer*)container {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setLineFragmentRect:(CGRect)fragmentRect forGlyphRange:(NSRange)glyphRange usedRect:(CGRect)usedRect {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setLocation:(CGPoint)location forStartOfGlyphRange:(NSRange)glyphRange {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setNotShownAttribute:(BOOL)flag forGlyphAtIndex:(NSUInteger)glyphIndex {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (CGSize)attachmentSizeForGlyphAtIndex:(NSUInteger)glyphIndex {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)drawsOutsideLineFragmentForGlyphAtIndex:(NSUInteger)glyphIndex {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)firstUnlaidCharacterIndex {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)firstUnlaidGlyphIndex {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)getFirstUnlaidCharacterIndex:(NSUInteger*)charIndex glyphIndex:(NSUInteger*)glyphIndex {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)notShownAttributeForGlyphAtIndex:(NSUInteger)glyphIndex {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSRange)truncatedGlyphRangeInLineFragmentForGlyphAtIndex:(NSUInteger)glyphIndex {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)characterIndexForPoint:(CGPoint)point
                             inTextContainer:(NSTextContainer*)container
    fractionOfDistanceBetweenInsertionPoints:(CGFloat*)partialFraction {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateEnclosingRectsForGlyphRange:(NSRange)glyphRange
                    withinSelectedGlyphRange:(NSRange)selectedRange
                             inTextContainer:(NSTextContainer*)textContainer
                                  usingBlock:(void (^)(CGRect, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateLineFragmentsForGlyphRange:(NSRange)glyphRange
                                 usingBlock:(void (^)(CGRect, CGRect, NSTextContainer*, NSRange, BOOL*))block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (CGFloat)fractionOfDistanceThroughGlyphForPoint:(CGPoint)point inTextContainer:(NSTextContainer*)container {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)getLineFragmentInsertionPointsForCharacterAtIndex:(NSUInteger)charIndex
                                             alternatePositions:(BOOL)aFlag
                                                 inDisplayOrder:(BOOL)dFlag
                                                      positions:(CGFloat*)positions
                                               characterIndexes:(NSUInteger*)charIndexes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)glyphIndexForPoint:(CGPoint)point inTextContainer:(NSTextContainer*)container {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSRange)glyphRangeForBoundingRect:(CGRect)bounds inTextContainer:(NSTextContainer*)container {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSRange)glyphRangeForBoundingRectWithoutAdditionalLayout:(CGRect)bounds inTextContainer:(NSTextContainer*)container {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSRange)glyphRangeForTextContainer:(NSTextContainer*)container {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSRange)rangeOfNominallySpacedGlyphsContainingIndex:(NSUInteger)glyphIndex {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)drawStrikethroughForGlyphRange:(NSRange)glyphRange
                     strikethroughType:(NSUnderlineStyle)strikethroughVal
                        baselineOffset:(CGFloat)baselineOffset
                      lineFragmentRect:(CGRect)lineRect
                lineFragmentGlyphRange:(NSRange)lineGlyphRange
                       containerOrigin:(CGPoint)containerOrigin {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)drawUnderlineForGlyphRange:(NSRange)glyphRange
                     underlineType:(NSUnderlineStyle)underlineVal
                    baselineOffset:(CGFloat)baselineOffset
                  lineFragmentRect:(CGRect)lineRect
            lineFragmentGlyphRange:(NSRange)lineGlyphRange
                   containerOrigin:(CGPoint)containerOrigin {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)fillBackgroundRectArray:(const CGRect*)rectArray
                          count:(NSUInteger)rectCount
              forCharacterRange:(NSRange)charRange
                          color:(UIColor*)color {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)showCGGlyphs:(const CGGlyph*)glyphs
           positions:(const CGPoint*)positions
               count:(NSUInteger)glyphCount
                font:(UIFont*)font
              matrix:(CGAffineTransform)textMatrix
          attributes:(NSDictionary*)attributes
           inContext:(CGContextRef)graphicsContext {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)strikethroughGlyphRange:(NSRange)glyphRange
              strikethroughType:(NSUnderlineStyle)strikethroughVal
               lineFragmentRect:(CGRect)lineRect
         lineFragmentGlyphRange:(NSRange)lineGlyphRange
                containerOrigin:(CGPoint)containerOrigin {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)underlineGlyphRange:(NSRange)glyphRange
              underlineType:(NSUnderlineStyle)underlineVal
           lineFragmentRect:(CGRect)lineRect
     lineFragmentGlyphRange:(NSRange)lineGlyphRange
            containerOrigin:(CGPoint)containerOrigin {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (CGRect)lineFragmentUsedRectForGlyphAtIndex:(NSUInteger)glyphIndex effectiveRange:(NSRangePointer)effectiveGlyphRange {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
