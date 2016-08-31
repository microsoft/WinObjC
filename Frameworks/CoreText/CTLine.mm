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
#import "NSStringInternal.h"
#import "CoreTextInternal.h"
#import "CGContextInternal.h"
#import <CoreText/CTTypesetter.h>

static NSMutableAttributedString* _getTruncatedStringFromSourceLine(CTLineRef line,
                                                                    CTLineTruncationType truncationType,
                                                                    double widthToExtract);

@implementation _CTLine : NSObject
- (void)dealloc {
    _runs = nil;
    [super dealloc];
}

- (instancetype)copyWithZone:(NSZone*)zone {
    _CTLine* ret = [_CTLine new];
    ret->_strRange = _strRange;
    ret->_width = _width;
    ret->_ascent = _ascent;
    ret->_descent = _descent;
    ret->_leading = _leading;
    ret->_runs = [_runs copy];

    return ret;
}
@end

/**
 @Status Stub
*/
CTLineRef CTLineCreateWithAttributedString(CFAttributedStringRef string) {
    UNIMPLEMENTED();
    NSString* str = [(NSAttributedString*)string string];
    NSRange lineRange;
    lineRange.location = 0;
    lineRange.length = [str length];

    _CTLine* line = [_CTLine new];
    line->_strRange = lineRange;

    return (CTLineRef)line;
}

/**
 @Status Interoperable
*/
CTLineRef CTLineCreateTruncatedLine(CTLineRef sourceLine, double width, CTLineTruncationType truncationType, CTLineRef truncationToken) {
    if (sourceLine == nil) {
        return nil;
    }

    // get the truncationToken width, use it to calculate the exact width that should be extracted from the sourceLine.
    CGFloat truncationTokenWidth;
    if (truncationToken == nil) {
        truncationTokenWidth = 0.0f;
    } else {
        truncationTokenWidth = (static_cast<_CTLine*>(truncationToken))->_width;
    }

    if (width <= 0 || truncationTokenWidth > width) {
        return nil;
    }

    CGFloat sourceLineWidth = static_cast<_CTLine*>(sourceLine)->_width;
    if (width >= sourceLineWidth || sourceLineWidth == truncationTokenWidth) {
        // return a copy of sourceLine
        return static_cast<CTLineRef>([static_cast<_CTLine*>(sourceLine) copy]);
    }

    // widthToExtract is the width that will be extracted from the sourceLine and merged with truncationToken finally
    double widthToExtract;
    if (truncationToken == nil) {
        widthToExtract = width;
    } else {
        widthToExtract = width - truncationTokenWidth;
    }

    // get an NSAttributed string from truncationToken by looping across its runs and extracting the run attribuets.
    NSMutableAttributedString* stringFromToken = [NSMutableAttributedString new];
    CFArrayRef tokenRuns = CTLineGetGlyphRuns(truncationToken);
    if (tokenRuns != nil) {
        CFIndex numberOfRuns = CFArrayGetCount(tokenRuns);
        for (int i = 0; i < numberOfRuns; ++i) {
            CTRunRef run = static_cast<CTRunRef>(CFArrayGetValueAtIndex(tokenRuns, i));
            CFDictionaryRef attribs = CTRunGetAttributes(run);
            NSAttributedString* string =
                [[NSAttributedString alloc] initWithString:(static_cast<_CTRun*>(run))->_stringFragment attributes:(NSDictionary*)attribs];
            [stringFromToken appendAttributedString:string];
            [string release];
        }
    }

    NSMutableAttributedString* finalString = nil;
    NSMutableAttributedString* truncatedStringFromLeft = nil;
    NSMutableAttributedString* truncatedStringFromRight = nil;

    switch (truncationType) {
        case kCTLineTruncationStart:
            truncatedStringFromRight = _getTruncatedStringFromSourceLine(sourceLine, kCTLineTruncationStart, widthToExtract);
            [stringFromToken appendAttributedString:truncatedStringFromRight];
            finalString = stringFromToken;

            break;
        case kCTLineTruncationMiddle:
            widthToExtract = widthToExtract / 2;
            truncatedStringFromLeft = _getTruncatedStringFromSourceLine(sourceLine, kCTLineTruncationEnd, widthToExtract);
            truncatedStringFromRight = _getTruncatedStringFromSourceLine(sourceLine, kCTLineTruncationStart, widthToExtract);
            [truncatedStringFromLeft appendAttributedString:stringFromToken];
            [truncatedStringFromLeft appendAttributedString:truncatedStringFromRight];
            finalString = truncatedStringFromLeft;

            break;
        case kCTLineTruncationEnd:
            truncatedStringFromLeft = _getTruncatedStringFromSourceLine(sourceLine, kCTLineTruncationEnd, widthToExtract);
            [truncatedStringFromLeft appendAttributedString:stringFromToken];
            finalString = truncatedStringFromLeft;

            break;
        default:
            return nil;
    }

    CTTypesetterRef typeSetter = CTTypesetterCreateWithAttributedString(static_cast<CFAttributedStringRef>(finalString));
    CFRange range = { 0, finalString.length };
    CTLineRef ret = static_cast<CTLineRef>(CTTypesetterCreateLine(typeSetter, range));
    CFRelease(typeSetter);
    [stringFromToken release];

    return ret;
}

static NSMutableAttributedString* _getTruncatedStringFromSourceLine(CTLineRef sourceLine,
                                                                    CTLineTruncationType truncationType,
                                                                    double widthToExtract) {
    NSMutableAttributedString* ret = [NSMutableAttributedString new];
    CFArrayRef glyphRuns = CTLineGetGlyphRuns(sourceLine);
    CFIndex numberOfRuns = CFArrayGetCount(glyphRuns);
    double extractedWidth = 0;
    bool done = 0;

    for (int i = 0; i < numberOfRuns; ++i) {
        int runIndex;
        if (truncationType == kCTLineTruncationStart) {
            runIndex = numberOfRuns - i - 1;
        } else if (truncationType == kCTLineTruncationEnd) {
            runIndex = i;
        }

        CTRunRef currentRun = static_cast<CTRunRef>(CFArrayGetValueAtIndex(glyphRuns, runIndex));
        _CTRun* run = static_cast<_CTRun*>(currentRun);
        NSMutableString* runString = [NSMutableString new];

        int numberOfGlyphs = run->_glyphAdvances.size();
        for (int j = 0; j < numberOfGlyphs; ++j) {
            int glyphIndex;
            if (truncationType == kCTLineTruncationStart) {
                glyphIndex = numberOfGlyphs - j - 1;
            } else if (truncationType == kCTLineTruncationEnd) {
                glyphIndex = j;
            }

            if (extractedWidth + run->_glyphAdvances[glyphIndex].width > widthToExtract) {
                done = 1;
                break;
            }

            extractedWidth += run->_glyphAdvances[glyphIndex].width;
            char glyph = [run->_stringFragment characterAtIndex:glyphIndex];
            [runString appendString:[NSString stringWithFormat:@"%c", glyph]];
        }

        CFDictionaryRef attribs = CTRunGetAttributes(currentRun);

        if (truncationType == kCTLineTruncationStart) {
            NSString* reverse = [runString _reverseString];
            NSAttributedString* string = [[NSAttributedString alloc] initWithString:reverse attributes:(NSDictionary*)attribs];
            [ret insertAttributedString:string atIndex:0];
            [string release];
        } else if (truncationType == kCTLineTruncationEnd) {
            NSAttributedString* string = [[NSAttributedString alloc] initWithString:runString attributes:(NSDictionary*)attribs];
            [ret appendAttributedString:string];
            [string release];
        }
        [runString release];
        if (done) {
            break;
        }
    }

    return [ret autorelease];
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
    if (!lineRef) {
        return;
    }

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
    if (!line) {
        return nil;
    }
    return (CFArrayRef)[((_CTLine*)line)->_runs retain];
}

/**
 @Status Interoperable
*/
CFRange CTLineGetStringRange(CTLineRef line) {
    if (!line) {
        return { 0, 0 };
    }

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
    if (!lineRef) {
        return 0;
    }

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
