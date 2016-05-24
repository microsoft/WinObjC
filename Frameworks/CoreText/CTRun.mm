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

#include "CoreTextInternal.h"
#include "CGContextInternal.h"
#include "CGFontInternal.h"

const CFStringRef kCTBackgroundStrokeColorAttributeName = static_cast<CFStringRef>(@"kCTBackgroundStrokeColorAttributeName");
const CFStringRef kCTBackgroundFillColorAttributeName = static_cast<CFStringRef>(@"kCTBackgroundFillColorAttributeName");
const CFStringRef kCTBackgroundCornerRadiusAttributeName = static_cast<CFStringRef>(@"kCTBackgroundCornerRadiusAttributeName");
const CFStringRef kCTBackgroundLineWidthAttributeName = static_cast<CFStringRef>(@"kCTBackgroundLineWidthAttributeName");

static IWLazyClassLookup _LazyUIColor("UIColor");

@implementation _CTRun : NSObject
- (void)dealloc {
    _stringFragment = nil;
    _attributes = nil;

    [super dealloc];
}

- (id)init {
    if ((self = [super init])) {
        _attributes.attach([NSMutableDictionary new]);
    }

    return self;
}

@end

/**
@Status Interoperable
*/
CFIndex CTRunGetGlyphCount(CTRunRef run) {
    if (run == nil) {
        return 0;
    }

    _CTRun* ctRun = (_CTRun*)run;
    return ctRun->_characters.size();
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
 @Status Stub
 @Notes
*/
const CGGlyph* CTRunGetGlyphsPtr(CTRunRef run) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CTRunGetGlyphs(CTRunRef run, CFRange range, CGGlyph buffer[]) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
const CGPoint* CTRunGetPositionsPtr(CTRunRef run) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Only font face, size and text color attributes are supported.  Background fill is
        always white.
*/
void CTRunGetPositions(CTRunRef run, CFRange runRange, CGPoint* outPositions) {
    _CTRun* curRun = (_CTRun*)run;

    if (runRange.length == 0) {
        runRange.location = 0;
        runRange.length = curRun->_range.length;
    }

    memcpy(outPositions, &curRun->_glyphOrigins[runRange.location], sizeof(CGPoint) * runRange.length);
}

/**
 @Status Stub
 @Notes
*/
const CGSize* CTRunGetAdvancesPtr(CTRunRef run) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CTRunGetAdvances(CTRunRef run, CFRange runRange, CGSize* outAdvances) {
    _CTRun* curRun = (_CTRun*)run;

    if (runRange.length == 0) {
        runRange.location = 0;
        runRange.length = curRun->_range.length;
    }

    memcpy(outAdvances, &curRun->_glyphAdvances[runRange.location], sizeof(CGSize) * runRange.length);
}

/**
 @Status Stub
 @Notes
*/
const CFIndex* CTRunGetStringIndicesPtr(CTRunRef run) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CTRunGetStringIndices(CTRunRef run, CFRange range, CFIndex buffer[]) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
CFRange CTRunGetStringRange(CTRunRef run) {
    _CTRun* curRun = (_CTRun*)run;

    return curRun->_range;
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
    auto it = curRun->_glyphAdvances.begin() + range.location;
    auto rangeEnd = it + range.length;
    while (it != rangeEnd) {
        typographicWidth += it->width;
        it++;
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

/**
 @Status Caveat
 @Notes textRange parameter not supported
*/
void CTRunDraw(CTRunRef run, CGContextRef ctx, CFRange textRange) {
    if (!run) {
        return;
    }

    _CTRun* curRun = (_CTRun*)run;

    NSString* string = curRun->_stringFragment;

    NSRange range;
    range.location = textRange.location;
    range.length = textRange.length;

    if (range.length == 0) {
        range.location = 0;
        range.length = [string length];
    }

    int numGlyphs = curRun->_characters.size();
    WORD* glyphs = (WORD*)IwMalloc(sizeof(WORD) * numGlyphs);

    id font = [curRun->_attributes objectForKey:(id)kCTFontAttributeName];
    CGFontGetGlyphsForUnichars(font, curRun->_characters.data(), glyphs, numGlyphs);
    CGContextSetFont(ctx, font);
    CGContextSetFontSize(ctx, [font pointSize]);

    id fontColor = [curRun->_attributes objectForKey:(id)kCTForegroundColorAttributeName];
    if (fontColor == nil) {
        fontColor = [_LazyUIColor blackColor];
    }
    CGContextSetFillColorWithColor(ctx, (CGColorRef)fontColor);
    CGContextSetStrokeColorWithColor(ctx, (CGColorRef)(id)CGColorGetConstantColor((CFStringRef) @"WHITE"));

    CGPoint curTextPos = CGContextGetTextPosition(ctx);
    CGContextShowGlyphsAtPoint(ctx, curTextPos.x, curTextPos.y, glyphs, numGlyphs);
    IwFree(glyphs);
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
