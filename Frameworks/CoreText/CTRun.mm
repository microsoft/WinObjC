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
#import <numeric>
#import <algorithm>
#import <functional>

const CFStringRef kCTBackgroundStrokeColorAttributeName = CFSTR("kCTBackgroundStrokeColorAttributeName");
const CFStringRef kCTBackgroundFillColorAttributeName = CFSTR("kCTBackgroundFillColorAttributeName");
const CFStringRef kCTBackgroundCornerRadiusAttributeName = CFSTR("kCTBackgroundCornerRadiusAttributeName");
const CFStringRef kCTBackgroundLineWidthAttributeName = CFSTR("kCTBackgroundLineWidthAttributeName");

CTRunRef _CTRunCreate() {
    return __CTRun::CreateInstance(kCFAllocatorDefault);
}

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
    RETURN_RESULT_IF_NULL(run, 0);
    return run->_dwriteGlyphRun.glyphCount;
}

/**
@Status Interoperable
*/
CFDictionaryRef CTRunGetAttributes(CTRunRef run) {
    RETURN_NULL_IF(!run);
    return run->_attributes;
}

/**
 @Status Interoperable
*/
CTRunStatus CTRunGetStatus(CTRunRef run) {
    RETURN_RESULT_IF_NULL(run, kCTRunStatusNoStatus);

    CTRunStatus ret = kCTRunStatusNoStatus;

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

    return ret;
}

/**
 @Status Interoperable
*/
const CGGlyph* CTRunGetGlyphsPtr(CTRunRef run) {
    RETURN_NULL_IF(!run || !run->_dwriteGlyphRun.glyphCount);
    return run->_dwriteGlyphRun.glyphIndices;
}

/**
 @Status Interoperable
*/
void CTRunGetGlyphs(CTRunRef run, CFRange range, CGGlyph buffer[]) {
    RETURN_IF(!run);
    _boundedCopy(range, run->_dwriteGlyphRun.glyphCount, run->_dwriteGlyphRun.glyphIndices, buffer);
}

/**
 @Status Interoperable
*/
const CGPoint* CTRunGetPositionsPtr(CTRunRef run) {
    RETURN_NULL_IF(!run || !run->_glyphOrigins.size());
    return run->_glyphOrigins.data();
}

/**
 @Status Interoperable
*/
void CTRunGetPositions(CTRunRef run, CFRange runRange, CGPoint outPositions[]) {
    RETURN_IF(!run);
    _boundedCopy(runRange, run->_glyphOrigins.size(), run->_glyphOrigins.data(), outPositions);
}

/**
 @Status Interoperable
*/
const CGSize* CTRunGetAdvancesPtr(CTRunRef run) {
    RETURN_NULL_IF(!run || !run->_glyphAdvances.size());
    return run->_glyphAdvances.data();
}

/**
 @Status Interoperable
*/
void CTRunGetAdvances(CTRunRef run, CFRange runRange, CGSize outAdvances[]) {
    RETURN_IF(!run);
    _boundedCopy(runRange, run->_glyphAdvances.size(), run->_glyphAdvances.data(), outAdvances);
}

/**
 @Status Interoperable
*/
const CFIndex* CTRunGetStringIndicesPtr(CTRunRef run) {
    RETURN_NULL_IF(!run || !run->_stringIndices.size());
    return run->_stringIndices.data();
}

/**
 @Status Interoperable
*/
void CTRunGetStringIndices(CTRunRef run, CFRange range, CFIndex buffer[]) {
    RETURN_IF(!run);
    _boundedCopy(range, run->_stringIndices.size(), run->_stringIndices.data(), buffer);
}

/**
 @Status Interoperable
*/
CFRange CTRunGetStringRange(CTRunRef run) {
    RETURN_RESULT_IF_NULL(run, CFRangeMake(0, 0));
    return run->_range;
}

/**
 @Status Interoperable
*/
double CTRunGetTypographicBounds(CTRunRef run, CFRange range, CGFloat* ascent, CGFloat* descent, CGFloat* leading) {
    RETURN_RESULT_IF(!run || (range.length < 0L), 0.0);

    if (range.length == 0L) {
        range = run->_range;
    }

    if (range.location < 0L) {
        range.length += range.location;
        range.location = 0L;
    }

    if ((range.location + range.length) > (run->_range.location + run->_range.length) || range.length <= 0L) {
        return 0.0;
    }

    if (ascent || descent || leading) {
        CTFontRef font = static_cast<CTFontRef>(CFDictionaryGetValue(run->_attributes, kCTFontAttributeName));
        CGFloat pointSize = font ? CTFontGetSize(font) : kCTFontSystemFontSize;

        DWRITE_FONT_METRICS fontMetrics;
        run->_dwriteGlyphRun.fontFace->GetMetrics(&fontMetrics);

        // Need scaling factor to convert from design units to pointSize
        CGFloat scalingFactor = pointSize / fontMetrics.designUnitsPerEm;

        DWRITE_GLYPH_METRICS glyphMetrics[range.length];
        THROW_IF_FAILED(
            run->_dwriteGlyphRun.fontFace->GetDesignGlyphMetrics(run->_dwriteGlyphRun.glyphIndices + range.location - run->_range.location,
                                                                 range.length,
                                                                 glyphMetrics,
                                                                 run->_dwriteGlyphRun.isSideways));

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

    return std::accumulate(run->_dwriteGlyphRun.glyphAdvances + range.location - run->_range.location,
                           run->_dwriteGlyphRun.glyphAdvances + range.location + range.length - run->_range.location,
                           0.0);
}

/**
 @Status Interoperable
*/
CGRect CTRunGetImageBounds(CTRunRef run, CGContextRef context, CFRange range) {
    RETURN_RESULT_IF(!run || !context || (range.location < 0L) || (range.length < 0L) ||
                         (range.location + range.length > run->_dwriteGlyphRun.glyphCount),
                     CGRectNull);

    if (range.location == 0L) {
        range.location = run->_dwriteGlyphRun.glyphCount - range.location;
    }

    CGFloat ascent, descent;
    double width = CTRunGetTypographicBounds(run, range, &ascent, &descent, nullptr);
    return { CGContextGetTextPosition(context), { width, ascent - descent } };
}

/**
 @Status Interoperable
*/
void CTRunDraw(CTRunRef runRef, CGContextRef ctx, CFRange textRange) {
    RETURN_IF(!runRef || (textRange.length < 0L) || (textRange.location < 0L) ||
              (textRange.location + textRange.length > runRef->_dwriteGlyphRun.glyphCount));

    __CTRun* run = const_cast<__CTRun*>(runRef);
    if (textRange.location == 0L && (textRange.length == 0L || textRange.length == run->_dwriteGlyphRun.glyphCount)) {
        // Print the whole glyph run
        GlyphRunData data{ &run->_dwriteGlyphRun, CGPointZero, run->_attributes };
        _CGContextDrawGlyphRuns(ctx, &data, 1);
    } else {
        if (textRange.length == 0L) {
            textRange.length = run->_dwriteGlyphRun.glyphCount - textRange.location;
        }

        // Only print glyphs in range
        DWRITE_GLYPH_RUN runInRange = __GetGlyphRunForDrawingInRange(run->_dwriteGlyphRun, textRange);
        GlyphRunData data{ &runInRange, CGPointZero, run->_attributes };
        _CGContextDrawGlyphRuns(ctx, &data, 1);
    }
}

/**
 @Status Caveat
 @Notes CTRunRef will only ever have CGAffineTransformIdentity until #1987
*/
CGAffineTransform CTRunGetTextMatrix(CTRunRef run) {
    RETURN_RESULT_IF_NULL(run, CGAffineTransformIdentity);
    return run->_textMatrix;
}

/**
 @Status Interoperable
*/
CFTypeID CTRunGetTypeID() {
    return __CTRun::GetTypeID();
}
