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

#import <CoreText/CTRun.h>
#import <StubReturn.h>
#include <COMIncludes.h>
#import <Wincodec.h>
#import <D2d1.h>
#include <COMIncludes_End.h>
#import <CoreText/DWriteWrapper.h>
#import "CoreTextInternal.h"
#import "CGContextInternal.h"
#import "CGFontInternal.h"

#include <algorithm>

// Helper method for validating range and copying internal data to given outData
template <typename T>
void __boundedCopy(CFRange range, const std::vector<T>& inData, T outData[]) {
    if (outData && range.location < inData.size()) {
        range.location = std::max(range.location, (CFIndex)0);
        if (range.length <= 0 || range.location + range.length >= inData.size()) {
            range.length = inData.size() - range.location;
        }

        memcpy(outData, inData.data() + range.location, sizeof(T) * range.length);
    }
}

const CFStringRef kCTBackgroundStrokeColorAttributeName = static_cast<CFStringRef>(@"kCTBackgroundStrokeColorAttributeName");
const CFStringRef kCTBackgroundFillColorAttributeName = static_cast<CFStringRef>(@"kCTBackgroundFillColorAttributeName");
const CFStringRef kCTBackgroundCornerRadiusAttributeName = static_cast<CFStringRef>(@"kCTBackgroundCornerRadiusAttributeName");
const CFStringRef kCTBackgroundLineWidthAttributeName = static_cast<CFStringRef>(@"kCTBackgroundLineWidthAttributeName");

static IWLazyClassLookup _LazyUIColor("UIColor");

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
    if ((self = [super init])) {
        _attributes.attach([NSMutableDictionary new]);
    }

    return self;
}

- (instancetype)copyWithZone:(NSZone*)zone {
    _CTRun* ret = [_CTRun new];
    ret->_attributes.attach([_attributes copy]);
    ret->_range = _range;
    ret->_xPos = _xPos;
    ret->_stringFragment = [_stringFragment copy];
    ret->_glyphOrigins = _glyphOrigins;
    ret->_glyphAdvances = _glyphAdvances;
    ret->_glyphs = _glyphs;
    ret->_stringIndices = _stringIndices;
    return ret;
}

@end

/**
@Status Interoperable
*/
CFIndex CTRunGetGlyphCount(CTRunRef run) {
    _CTRun* ctRun = (_CTRun*)run;
    return ctRun ? ctRun->_dwriteGlyphRun.glyphCount : 0;
}

/**
@Status Interoperable
*/
CFDictionaryRef CTRunGetAttributes(CTRunRef run) {
    if (run == nil) {
        return nil;
    }

    return (__bridge CFDictionaryRef)(NSDictionary*)(static_cast<_CTRun*>(run))->_attributes;
}

/**
 @Status Stub
 @Notes
*/
CTRunStatus CTRunGetStatus(CTRunRef run) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
const CGGlyph* CTRunGetGlyphsPtr(CTRunRef run) {
    _CTRun* runPtr = static_cast<_CTRun*>(run);
    return runPtr && runPtr->_glyphs.size() ? runPtr->_glyphs.data() : nullptr;
}

/**
 @Status Interoperable
 @Notes
*/
void CTRunGetGlyphs(CTRunRef run, CFRange range, CGGlyph buffer[]) {
    _CTRun* runPtr = static_cast<_CTRun*>(run);
    if (runPtr) {
        __boundedCopy(range, runPtr->_glyphs, buffer);
    }
}

/**
 @Status Interoperable
 @Notes
*/
const CGPoint* CTRunGetPositionsPtr(CTRunRef run) {
    _CTRun* runPtr = static_cast<_CTRun*>(run);
    return runPtr && runPtr->_glyphOrigins.size() ? runPtr->_glyphOrigins.data() : nullptr;
}

/**
 @Status Interoperable
 @Notes
*/
void CTRunGetPositions(CTRunRef run, CFRange runRange, CGPoint outPositions[]) {
    _CTRun* curRun = (_CTRun*)run;
    if (curRun) {
        __boundedCopy(runRange, curRun->_glyphOrigins, outPositions);
    }
}

/**
 @Status Interoperable
 @Notes
*/
const CGSize* CTRunGetAdvancesPtr(CTRunRef run) {
    _CTRun* runPtr = static_cast<_CTRun*>(run);
    return runPtr && runPtr->_glyphAdvances.size() ? runPtr->_glyphAdvances.data() : nullptr;
}

/**
 @Status Interoperable
*/
void CTRunGetAdvances(CTRunRef run, CFRange runRange, CGSize outAdvances[]) {
    _CTRun* curRun = (_CTRun*)run;
    if (curRun) {
        __boundedCopy(runRange, curRun->_glyphAdvances, outAdvances);
    }
}

/**
 @Status Interoperable
 @Notes
*/
const CFIndex* CTRunGetStringIndicesPtr(CTRunRef run) {
    _CTRun* runPtr = static_cast<_CTRun*>(run);
    return runPtr && runPtr->_stringIndices.size() ? runPtr->_stringIndices.data() : nullptr;
}

/**
 @Status Interoperable
 @Notes
*/
void CTRunGetStringIndices(CTRunRef run, CFRange range, CFIndex buffer[]) {
    _CTRun* curRun = (_CTRun*)run;
    if (curRun) {
        __boundedCopy(range, curRun->_stringIndices, buffer);
    }
}

/**
 @Status Interoperable
*/
CFRange CTRunGetStringRange(CTRunRef run) {
    _CTRun* curRun = (_CTRun*)run;
    return curRun ? curRun->_range : CFRangeMake(0, 0);
}

/**
 @Status Interoperable
*/
double CTRunGetTypographicBounds(CTRunRef run, CFRange range, CGFloat* ascent, CGFloat* descent, CGFloat* leading) {
    if (run == nullptr) {
        return 0;
    }

    if (range.length < 0) {
        THROW_NS_HR(E_INVALIDARG);
    }

    _CTRun* curRun = static_cast<_CTRun*>(run);

    if (range.length == 0) {
        range = curRun->_range;
    }

    if (range.location < 0) {
        range.length += range.location;
        range.location = 0;
    }

    if ((range.location + range.length) > (curRun->_range.location + curRun->_range.length)) {
        return 0;
    }

    UIFont* font = [curRun->_attributes objectForKey:(id)kCTFontAttributeName];
    if (ascent) {
        *ascent = [font ascender];
    }

    if (descent) {
        *descent = [font descender];
    }

    if (leading) {
        *leading = [font leading];
    }

    if (range.length < 0) {
        return 0;
    }

    // Calculate the typographic width for the specified range
    double typographicWidth = 0;
    for (int index = range.location; index < curRun->_dwriteGlyphRun.glyphCount; index++) {
        typographicWidth += curRun->_dwriteGlyphRun.glyphAdvances[index];
    }

    return typographicWidth;
}

/**
 @Status Stub
 @Notes
*/
CGRect CTRunGetImageBounds(CTRunRef run, CGContextRef context, CFRange range) {
    UNIMPLEMENTED();
    return StubReturn();
}

void _CTRunDraw(CTRunRef run, CGContextRef ctx, CFRange textRange, bool adjustTextPosition) {
    if (!run) {
        return;
    }

    _CTRun* curRun = (_CTRun*)run;
    if (adjustTextPosition) {
        CGPoint curTextPos = CGContextGetTextPosition(ctx);
        CGContextSetTextPosition(ctx, curTextPos.x + curRun->_relativeXOffset, curTextPos.y + curRun->_relativeYOffset);
    }

    // TODO::
    // Fix this once CTFont and UIFont become bridgable classes.
    id fontColor = [curRun->_attributes objectForKey:(id)kCTForegroundColorAttributeName];
    if (fontColor == nil) {
        fontColor = [_LazyUIColor blackColor];
    }
    CGContextSetFillColorWithColor(ctx, reinterpret_cast<CGColorRef>(fontColor));
    CGContextDrawGlyphRun(ctx, &curRun->_dwriteGlyphRun);
}

/**
 @Status Caveat
 @Notes textRange parameter not supported
*/
void CTRunDraw(CTRunRef run, CGContextRef ctx, CFRange textRange) {
    _CTRunDraw(run, ctx, textRange, true);
}

/**
 @Status Stub
 @Notes
*/
CGAffineTransform CTRunGetTextMatrix(CTRunRef run) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CTRunGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
