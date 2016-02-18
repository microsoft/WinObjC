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

#import <CoreText/CTLine.h>
#import <StubReturn.h>

#include "CoreTextInternal.h"
#include "CGContextInternal.h"

@implementation _CTLine : NSObject
- (void)dealloc {
    _runs = nil;
    [super dealloc];
}
@end

/**
 @Status Interoperable
*/
CTLineRef CTLineCreateWithAttributedString(CFAttributedStringRef string) {
    NSString* str = [(NSAttributedString*)string string];
    NSRange lineRange;
    lineRange.location = 0;
    lineRange.length = [str length];

    _CTLine* line = [_CTLine new];
    line->_strRange = lineRange;

    return (CTLineRef)line;
}

/**
 @Status Stub
 @Notes Line is not truncated
*/
CTLineRef CTLineCreateTruncatedLine(CTLineRef line, double width, CTLineTruncationType truncationType, CTLineRef truncationToken) {
    UNIMPLEMENTED();
    NSRange lineRange = ((_CTLine*)line)->_strRange;

    _CTLine* ret = [_CTLine new];
    ret->_strRange = lineRange;

    return (CTLineRef)ret;
}

/**
 @Status Stub
 @Notes
*/
CTLineRef CTLineCreateJustifiedLine(CTLineRef line, CGFloat justificationFactor, double justificationWidth) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CTLineDraw(CTLineRef lineRef, CGContextRef ctx) {
    _CTLine* line = (_CTLine*)lineRef;

    CGPoint start = CGContextGetTextPosition(ctx);

    for (_CTRun* curRun in(NSArray*)line->_runs) {
        CFRange range = { 0 };

        CGPoint outputPoint = start;
        if (curRun->_glyphOrigins.size() > 0) {
            outputPoint = CGPointMake(start.x + curRun->_glyphOrigins[0].x, start.y + +curRun->_glyphOrigins[0].y);
        }

        CGContextSetTextPosition(ctx, outputPoint.x, outputPoint.y);

        CTRunDraw((CTRunRef)curRun, ctx, range);
    }
}

/**
 @Status Interoperable
*/
CFIndex CTLineGetGlyphCount(CTLineRef lineRef) {
    if (lineRef == nil) {
        return 0;
    }

    _CTLine* line = (_CTLine*)lineRef;
    return (line->_strRange).length;
}

/**
 @Status Interoperable
*/
CFArrayRef CTLineGetGlyphRuns(CTLineRef line) {
    return (CFArrayRef)[((_CTLine*)line)->_runs retain];
}

/**
 @Status Interoperable
*/
CFRange CTLineGetStringRange(CTLineRef line) {
    CFRange ret;
    NSRange range = ((_CTLine*)line)->_strRange;
    ret.length = range.length;
    ret.location = range.location;

    return ret;
}

/**
 @Status Stub
 @Notes Returns 0.0
*/
double CTLineGetPenOffsetForFlush(CTLineRef line, CGFloat flushFactor, double flushWidth) {
    UNIMPLEMENTED();
    return 0.0;
}

/**
 @Status Stub
 @Notes
*/
CGRect CTLineGetImageBounds(CTLineRef line, CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Values only reflect the typographical maximums for the font - string is only evaulated
        for width
*/
double CTLineGetTypographicBounds(CTLineRef lineRef, CGFloat* ascent, CGFloat* descent, CGFloat* leading) {
    _CTLine* line = (_CTLine*)lineRef;
    if (ascent) {
        *ascent = line->_ascent;
    }
    if (descent) {
        *descent = line->_descent;
    }
    if (leading) {
        *leading = line->_leading;
    }

    return line->_width;
}

/**
 @Status Stub
 @Notes
*/
double CTLineGetTrailingWhitespaceWidth(CTLineRef line) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
CFIndex CTLineGetStringIndexForPosition(CTLineRef lineRef, CGPoint position) {
    if (CTLineGetGlyphCount(lineRef) == 0 || lineRef == nil) {
        return kCFNotFound;
    }

    CFRange lineRange = CTLineGetStringRange(lineRef);
    CFIndex ret = lineRange.location - 1;
    CGFloat currPos = 0;
    CFArrayRef glyphRuns = CTLineGetGlyphRuns(lineRef);
    CFIndex numberOfRuns = CFArrayGetCount(glyphRuns);

    for (int i = 0; i < numberOfRuns; i++) {
        CTRunRef run = (CTRunRef)CFArrayGetValueAtIndex(glyphRuns, i);
        CFIndex glyphsCount = CTRunGetGlyphCount(run);

        for (int i = 0; i < glyphsCount; i++) {
            ret++;
            currPos += ((_CTRun*)run)->_glyphAdvances[i].width;
            if (currPos >= position.x) {
                return ret;
            }
        }
    }

    // if the given input position is beyond the length of line, return last string index plus one
    if (currPos < position.x) {
        return CTLineGetGlyphCount(lineRef) + lineRange.location;
    }

    return kCFNotFound;
}

/**
 @Status Interoperable
*/
CGFloat CTLineGetOffsetForStringIndex(CTLineRef lineRef, CFIndex charIndex, CGFloat* secondaryOffset) {
    CGFloat ret = 0.0;
    if (secondaryOffset) {
        *secondaryOffset = 0.0;
    }

    if (lineRef == nil || charIndex < 0) {
        return ret;
    }

    // if charIndex is greater than the last string index, return line's width as offset
    if (charIndex > (CTLineGetGlyphCount(lineRef) - 1)) {
        ret = (static_cast<_CTLine*>(lineRef))->_width;
        if (secondaryOffset) {
            *secondaryOffset = ret;
        }

        return ret;
    }

    CFArrayRef glyphRuns = CTLineGetGlyphRuns(lineRef);
    CFIndex numberOfRuns = CFArrayGetCount(glyphRuns);
    CFIndex currentIndex = -1;

    for (int i = 0; i < numberOfRuns; i++) {
        CTRunRef currRun = (CTRunRef)CFArrayGetValueAtIndex(glyphRuns, i);
        CFIndex glyphCount = CTRunGetGlyphCount(currRun);

        if (currentIndex + glyphCount >= charIndex) {
            ret = (static_cast<_CTRun*>(currRun))->_glyphOrigins[charIndex - currentIndex - 1].x;
            if (secondaryOffset) {
                *secondaryOffset = ret;
            }
            return ret;
        }

        currentIndex += glyphCount;
    }

    return ret;
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CTLineGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
