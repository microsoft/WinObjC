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

#import <CoreText/CTRun.h>
#import <StubReturn.h>
#include <COMIncludes.h>
#import <Wincodec.h>
#import <D2d1.h>
#include <COMIncludes_End.h>
#import "DWriteWrapper_CoreText.h"
#import "CoreTextInternal.h"
#import "CGContextInternal.h"
#import <CppUtils.h>

#include <numeric>
#include <algorithm>
#include <functional>

const CFStringRef kCTBackgroundStrokeColorAttributeName = CFSTR("kCTBackgroundStrokeColorAttributeName");
const CFStringRef kCTBackgroundFillColorAttributeName = CFSTR("kCTBackgroundFillColorAttributeName");
const CFStringRef kCTBackgroundCornerRadiusAttributeName = CFSTR("kCTBackgroundCornerRadiusAttributeName");
const CFStringRef kCTBackgroundLineWidthAttributeName = CFSTR("kCTBackgroundLineWidthAttributeName");

@implementation _CTRun : NSObject
- (void)dealloc {
    _stringFragment = nil;
    _attributes = nil;
    _SafeRelease(&_dwriteGlyphRun.fontFace);
    delete[] _dwriteGlyphRun.glyphIndices;
    delete[] _dwriteGlyphRun.glyphAdvances;
    delete[] _dwriteGlyphRun.glyphOffsets;
    [super dealloc];
}

- (id)init {
    if (self = [super init]) {
        _attributes.attach([NSMutableDictionary new]);
        _textMatrix = CGAffineTransformIdentity;
    }

    return self;
}

- (instancetype)copyWithZone:(NSZone*)zone {
    _CTRun* ret = [_CTRun new];
    ret->_attributes.attach([_attributes copy]);
    ret->_range = _range;
    ret->_stringFragment.attach([_stringFragment copy]);
    _CloneDWriteGlyphRun(&_dwriteGlyphRun, &(ret->_dwriteGlyphRun));
    ret->_stringIndices = _stringIndices;
    ret->_glyphOrigins = _glyphOrigins;
    ret->_glyphAdvances = _glyphAdvances;
    ret->_relativeXOffset = _relativeXOffset;
    ret->_relativeYOffset = _relativeYOffset;
    return ret;
}

@end

// Helper method to produce a DWRITE_GLYPH_RUN for drawing
// Shares memory with the original, so should NOT be deleted
// Expects range parameter to be verified to work with glyph run
DWRITE_GLYPH_RUN __GetGlyphRunForDrawingInRange(const DWRITE_GLYPH_RUN& run, const CFRange& range) {
    return DWRITE_GLYPH_RUN{ run.fontFace,
                             run.fontEmSize,
                             range.length,
                             run.glyphIndices ? run.glyphIndices + range.location : nullptr,
                             run.glyphAdvances ? run.glyphAdvances + range.location : nullptr,
                             run.glyphOffsets ? run.glyphOffsets + range.location : nullptr,
                             run.isSideways,
                             run.bidiLevel };
}

/**
@Status Interoperable
*/
CFIndex CTRunGetGlyphCount(CTRunRef run) {
    return run ? static_cast<_CTRun*>(run)->_dwriteGlyphRun.glyphCount : 0;
}

/**
@Status Interoperable
*/
CFDictionaryRef CTRunGetAttributes(CTRunRef run) {
    return run ? static_cast<CFDictionaryRef>(static_cast<_CTRun*>(run)->_attributes.get()) : nil;
}

/**
 @Status Interoperable
 @Notes
*/
CTRunStatus CTRunGetStatus(CTRunRef runRef) {
    CTRunStatus ret = kCTRunStatusNoStatus;
    if (runRef) {
        _CTRun* run = static_cast<_CTRun*>(runRef);

        if (_GlyphRunIsRTL(run->_dwriteGlyphRun)) {
            ret |= kCTRunStatusRightToLeft;
            if (!std::is_sorted(run->_stringIndices.cbegin(), run->_stringIndices.cend(), std::greater<UINT16>())) {
                ret |= kCTRunStatusNonMonotonic;
            }
        } else if (!std::is_sorted(run->_stringIndices.cbegin(), run->_stringIndices.cend())) {
            ret |= kCTRunStatusNonMonotonic;
        }

        if (run->_textMatrix != CGAffineTransformIdentity) {
            ret |= kCTRunStatusHasNonIdentityMatrix;
        }
    }

    return ret;
}

/**
 @Status Interoperable
 @Notes
*/
const CGGlyph* CTRunGetGlyphsPtr(CTRunRef run) {
    _CTRun* runPtr = static_cast<_CTRun*>(run);
    return (runPtr && runPtr->_dwriteGlyphRun.glyphCount) ? runPtr->_dwriteGlyphRun.glyphIndices : nullptr;
}

/**
 @Status Interoperable
 @Notes
*/
void CTRunGetGlyphs(CTRunRef run, CFRange range, CGGlyph buffer[]) {
    _CTRun* runPtr = static_cast<_CTRun*>(run);
    if (runPtr) {
        _boundedCopy(range, runPtr->_dwriteGlyphRun.glyphCount, runPtr->_dwriteGlyphRun.glyphIndices, buffer);
    }
}

/**
 @Status Interoperable
 @Notes
*/
const CGPoint* CTRunGetPositionsPtr(CTRunRef run) {
    _CTRun* runPtr = static_cast<_CTRun*>(run);
    return (runPtr && runPtr->_glyphOrigins.size()) ? runPtr->_glyphOrigins.data() : nullptr;
}

/**
 @Status Interoperable
 @Notes
*/
void CTRunGetPositions(CTRunRef run, CFRange runRange, CGPoint outPositions[]) {
    _CTRun* curRun = (_CTRun*)run;
    if (curRun) {
        _boundedCopy(runRange, curRun->_glyphOrigins.size(), curRun->_glyphOrigins.data(), outPositions);
    }
}

/**
 @Status Interoperable
 @Notes
*/
const CGSize* CTRunGetAdvancesPtr(CTRunRef run) {
    _CTRun* runPtr = static_cast<_CTRun*>(run);
    return (runPtr && runPtr->_glyphAdvances.size()) ? runPtr->_glyphAdvances.data() : nullptr;
}

/**
 @Status Interoperable
*/
void CTRunGetAdvances(CTRunRef run, CFRange runRange, CGSize outAdvances[]) {
    _CTRun* runPtr = static_cast<_CTRun*>(run);
    if (runPtr) {
        _boundedCopy(runRange, runPtr->_glyphAdvances.size(), runPtr->_glyphAdvances.data(), outAdvances);
    }
}

/**
 @Status Interoperable
 @Notes
*/
const CFIndex* CTRunGetStringIndicesPtr(CTRunRef run) {
    _CTRun* runPtr = static_cast<_CTRun*>(run);
    return (runPtr && runPtr->_stringIndices.size()) ? runPtr->_stringIndices.data() : nullptr;
}

/**
 @Status Interoperable
 @Notes
*/
void CTRunGetStringIndices(CTRunRef run, CFRange range, CFIndex buffer[]) {
    _CTRun* runPtr = static_cast<_CTRun*>(run);
    if (runPtr) {
        _boundedCopy(range, runPtr->_stringIndices.size(), runPtr->_stringIndices.data(), buffer);
    }
}

/**
 @Status Interoperable
*/
CFRange CTRunGetStringRange(CTRunRef run) {
    return run ? static_cast<_CTRun*>(run)->_range : CFRangeMake(0, 0);
}

/**
 @Status Interoperable
*/
double CTRunGetTypographicBounds(CTRunRef run, CFRange range, CGFloat* ascent, CGFloat* descent, CGFloat* leading) {
    if (run == nullptr || range.length < 0L) {
        return 0.0;
    }

    _CTRun* curRun = static_cast<_CTRun*>(run);

    if (range.length == 0L) {
        range = curRun->_range;
    }

    if (range.location < 0L) {
        range.length += range.location;
        range.location = 0L;
    }

    if ((range.location + range.length) > (curRun->_range.location + curRun->_range.length) || range.length <= 0L) {
        return 0.0;
    }

    if (ascent || descent || leading) {
        CTFontRef font = static_cast<CTFontRef>([curRun->_attributes objectForKey:static_cast<NSString*>(kCTFontAttributeName)]);
        CGFloat pointSize = font ? CTFontGetSize(font) : kCTFontSystemFontSize;

        DWRITE_FONT_METRICS fontMetrics;
        curRun->_dwriteGlyphRun.fontFace->GetMetrics(&fontMetrics);

        // Need scaling factor to convert from design units to pointSize
        CGFloat scalingFactor = pointSize / fontMetrics.designUnitsPerEm;

        DWRITE_GLYPH_METRICS glyphMetrics[range.length];
        THROW_IF_FAILED(curRun->_dwriteGlyphRun.fontFace->GetDesignGlyphMetrics(curRun->_dwriteGlyphRun.glyphIndices + range.location -
                                                                                    curRun->_range.location,
                                                                                range.length,
                                                                                glyphMetrics,
                                                                                curRun->_dwriteGlyphRun.isSideways));

        CGFloat newAscent = -FLT_MAX;
        CGFloat newDescent = -FLT_MAX;
        for (size_t i = 0; i < range.length; ++i) {
            // CoreText ascent is equivalent of DWrite verticalOriginY, and descent the value of bottomSideBearing
            // which are in designUnits, so they need to be converted to points for CoreText
            // The ascent and descent of the run are the max of the respective values per glyph
            newAscent = std::max(newAscent, glyphMetrics[i].verticalOriginY * scalingFactor);
            newDescent = std::max(newDescent, glyphMetrics[i].bottomSideBearing * scalingFactor);
        }

        if (ascent) {
            *ascent = newAscent;
        }

        if (descent) {
            *descent = newDescent;
        }

        // CoreText leading is equivalent to DWrite lineGap, which are based solely upon the font
        if (leading) {
            *leading = fontMetrics.lineGap * scalingFactor;
        }
    }

    return std::accumulate(curRun->_dwriteGlyphRun.glyphAdvances + range.location - curRun->_range.location,
                           curRun->_dwriteGlyphRun.glyphAdvances + range.location + range.length - curRun->_range.location,
                           0.0);
}

/**
 @Status Interoperable
 @Notes
*/
CGRect CTRunGetImageBounds(CTRunRef runRef, CGContextRef context, CFRange range) {
    _CTRun* run = static_cast<_CTRun*>(runRef);
    if (!run || !context || range.location < 0L || range.length < 0L || range.location + range.length > run->_dwriteGlyphRun.glyphCount) {
        return CGRectNull;
    }

    if (range.location == 0L) {
        range.location = run->_dwriteGlyphRun.glyphCount - range.location;
    }

    CGFloat ascent, descent;
    double width = CTRunGetTypographicBounds(runRef, range, &ascent, &descent, nullptr);
    return { CGContextGetTextPosition(context), { width, ascent - descent } };
}

/**
 @Status Interoperable
 @Notes
*/
void CTRunDraw(CTRunRef run, CGContextRef ctx, CFRange textRange) {
    _CTRun* curRun = static_cast<_CTRun*>(run);
    if (!curRun || textRange.length < 0L || textRange.location < 0L ||
        textRange.location + textRange.length > curRun->_dwriteGlyphRun.glyphCount) {
        return;
    }

    if (textRange.location == 0L && (textRange.length == 0L || textRange.length == curRun->_dwriteGlyphRun.glyphCount)) {
        // Print the whole glyph run
        GlyphRunData data{ &curRun->_dwriteGlyphRun, CGPointZero, (CFDictionaryRef)curRun->_attributes.get() };
        _CGContextDrawGlyphRuns(ctx, &data, 1);
    } else {
        if (textRange.length == 0L) {
            textRange.length = curRun->_dwriteGlyphRun.glyphCount - textRange.location;
        }

        // Only print glyphs in range
        DWRITE_GLYPH_RUN runInRange = __GetGlyphRunForDrawingInRange(curRun->_dwriteGlyphRun, textRange);
        GlyphRunData data{ &runInRange, CGPointZero, (CFDictionaryRef)curRun->_attributes.get() };
        _CGContextDrawGlyphRuns(ctx, &data, 1);
    }
}

/**
 @Status Caveat
 @Notes CTRunRef will only ever have CGAffineTransformIdentity until #1987
*/
CGAffineTransform CTRunGetTextMatrix(CTRunRef run) {
    return run ? static_cast<_CTRun*>(run)->_textMatrix : CGAffineTransformIdentity;
}

/**
 @Status NotInPlan
 @Notes this would require us to move to using bridged type implementation, seems of little value at this point
*/
CFTypeID CTRunGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
