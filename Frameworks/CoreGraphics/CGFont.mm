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

#import <StubReturn.h>
#import <Starboard.h>

#import <CFRuntime.h>
#import <CoreGraphics/DWriteWrapper.h>

#include <COMIncludes.h>
#import <DWrite_3.h>
#import <wrl/client.h>
#include <COMIncludes_End.h>

#import "LoggingNative.h"

const CFStringRef kCGFontVariationAxisName = static_cast<CFStringRef>(@"kCGFontVariationAxisName");
const CFStringRef kCGFontVariationAxisMinValue = static_cast<CFStringRef>(@"kCGFontVariationAxisMinValue");
const CFStringRef kCGFontVariationAxisMaxValue = static_cast<CFStringRef>(@"kCGFontVariationAxisMaxValue");
const CFStringRef kCGFontVariationAxisDefaultValue = static_cast<CFStringRef>(@"kCGFontVariationAxisDefaultValue");

using namespace Microsoft::WRL;

static const wchar_t* g_logTag = L"CGFont";

struct __CGFont {
    CFRuntimeBase _base;
    ComPtr<IDWriteFontFace> _dwriteFontFace;

    struct DWRITE_FONT_METRICS _metrics;
    bool _cachedMetrics; // Set to true when _metrics is init'd
};

static Boolean __CGFontEqual(CFTypeRef cf1, CFTypeRef cf2) {
    struct __CGFont* font1 = (struct __CGFont*)cf1;
    struct __CGFont* font2 = (struct __CGFont*)cf2;

    return CFEqual(CFAutorelease(CGFontCopyPostScriptName(font1)), CFAutorelease(CGFontCopyPostScriptName(font2)));
}

static CFHashCode __CGFontHash(CFTypeRef cf) {
    CGFontRef font = (CGFontRef)cf;
    return CFHash(CFAutorelease(CGFontCopyPostScriptName(font)));
}

static CFStringRef __CGFontCopyDescription(CFTypeRef cf) {
    CGFontRef font = (CGFontRef)cf;
    return CFStringCreateWithFormat(kCFAllocatorSystemDefault, NULL, CFSTR("<CGFont %p>{%@}"), cf, CFAutorelease(CGFontCopyFullName(font)));
}

static void __CGFontInit(CFTypeRef cf) {
    CGFontRef font = (CGFontRef)cf;
    // ComPtr needs to be manually new'd, to avoid calling Create functions to an incomplete out-pointer
    struct __CGFont* mutableFont = const_cast<struct __CGFont*>(font);
    new (std::addressof(mutableFont->_dwriteFontFace)) ComPtr<IDWriteFontFace>();
}

static void __CGFontDeallocate(CFTypeRef cf) {
    CGFontRef font = (CGFontRef)cf;
    // ComPtr needs to be manually destructed, since CFTypes do a memset(0) on dealloc
    font->_dwriteFontFace.~ComPtr();
}

static const CFRuntimeClass __CGFontClass = { 0,
                                              "CGFont",
                                              __CGFontInit, // init
                                              NULL, // copy
                                              __CGFontDeallocate, // deallocate
                                              __CGFontEqual,
                                              __CGFontHash,
                                              NULL, //
                                              __CGFontCopyDescription };

/**
 @Status Interoperable
*/
void CGFontRelease(CGFontRef font) {
    CFRelease(font);
}

/**
 @Status Interoperable
*/
CGFontRef CGFontRetain(CGFontRef font) {
    CFRetain(font);
    return font;
}

/**
 @Status Stub
*/
CGFontRef CGFontCreateWithDataProvider(CGDataProviderRef cgDataProvider) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
CGFontRef CGFontCreateWithFontName(CFStringRef name) {
    size_t memSize = sizeof(struct __CGFont) - sizeof(CFRuntimeBase);
    CGFontRef ret = static_cast<CGFontRef>(_CFRuntimeCreateInstance(kCFAllocatorDefault, CGFontGetTypeID(), memSize, NULL));
    CFAutorelease(ret);
    struct __CGFont* mutableRet = const_cast<struct __CGFont*>(ret);

    RETURN_NULL_IF_FAILED(_DWriteCreateFontFaceWithName(name, &mutableRet->_dwriteFontFace));

    return static_cast<CGFontRef>(CFRetain(ret));
}

/**
 @Status Stub
 @Notes
*/
CGFontRef CGFontCreateCopyWithVariations(CGFontRef font, CFDictionaryRef variations) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
CFStringRef CGFontCopyPostScriptName(CGFontRef font) {
    RETURN_NULL_IF(!font);
    return _DWriteFontCopyInformationalString(font->_dwriteFontFace, DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_NAME);
}

/**
 @Status Stub
 @Notes
*/
bool CGFontCanCreatePostScriptSubset(CGFontRef font, CGFontPostScriptFormat format) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDataRef CGFontCreatePostScriptSubset(CGFontRef font,
                                       CFStringRef subsetName,
                                       CGFontPostScriptFormat format,
                                       const CGGlyph* glyphs,
                                       size_t count,
                                       const CGGlyph encoding[256]) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDataRef CGFontCreatePostScriptEncoding(CGFontRef font, const CGGlyph encoding[256]) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CGFontCopyTableTags(CGFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
CFDataRef CGFontCopyTableForTag(CGFontRef font, uint32_t tag) {
    return _DWriteFontCopyTable(font->_dwriteFontFace, tag);
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CGFontCopyVariationAxes(CGFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CGFontCopyVariations(CGFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Returns family name
*/
CFStringRef CGFontCopyFullName(CGFontRef font) {
    RETURN_NULL_IF(!font);
    return _DWriteFontCopyInformationalString(font->_dwriteFontFace, DWRITE_INFORMATIONAL_STRING_FULL_NAME);
}

// Private helper for getting a DWRITE_FONT_METRICS struct, to avoid code duplication
static struct DWRITE_FONT_METRICS __CGFontGetDWriteMetrics(CGFontRef font) {
    if (!font->_cachedMetrics) {
        font->_dwriteFontFace->GetMetrics(&const_cast<struct __CGFont*>(font)->_metrics);
    }
    return font->_metrics;
}

/**
 @Status Interoperable
*/
int CGFontGetAscent(CGFontRef font) {
    // Value for CGFont metrics are specified in 'glyph space units', which appear to be the same as DWrite's 'design units'
    return font ? __CGFontGetDWriteMetrics(font).ascent : 0;
}

/**
 @Status Interoperable
*/
int CGFontGetDescent(CGFontRef font) {
    // Value for CGFont metrics are specified in 'glyph space units', which appear to be the same as DWrite's 'design units'
    return font ? __CGFontGetDWriteMetrics(font).descent : 0;
}

/**
 @Status Interoperable
*/
int CGFontGetLeading(CGFontRef font) {
    // Value for CGFont metrics are specified in 'glyph space units', which appear to be the same as DWrite's 'design units'
    return font ? __CGFontGetDWriteMetrics(font).lineGap : 0;
}

/**
 @Status Interoperable
*/
int CGFontGetCapHeight(CGFontRef font) {
    // Value for CGFont metrics are specified in 'glyph space units', which appear to be the same as DWrite's 'design units'
    return font ? __CGFontGetDWriteMetrics(font).capHeight : 0;
}

/**
 @Status Interoperable
*/
int CGFontGetXHeight(CGFontRef font) {
    // Value for CGFont metrics are specified in 'glyph space units', which appear to be the same as DWrite's 'design units'
    return font ? __CGFontGetDWriteMetrics(font).xHeight : 0;
}

/**
 @Status Interoperable
*/
CGRect CGFontGetFontBBox(CGFontRef font) {
    if (!font) {
        return {};
    }
    return _DWriteFontGetBoundingBox(font->_dwriteFontFace);
}

/**
 @Status Interoperable
 @Notes
*/
CGFloat CGFontGetItalicAngle(CGFontRef font) {
    return font ? _DWriteFontGetSlantDegrees(font->_dwriteFontFace) : 0;
}

/**
 @Status Stub
 @Notes
*/
CGFloat CGFontGetStemV(CGFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
bool CGFontGetGlyphBBoxes(CGFontRef font, const CGGlyph* glyphs, size_t count, CGRect* bboxes) {
    if (!font || !glyphs || !bboxes || FAILED(_DWriteFontGetBoundingBoxesForGlyphs(font->_dwriteFontFace, glyphs, bboxes, count, false))) {
        TraceError(g_logTag, L"Unable to get glyph bounding boxes");
        return false;
    }

    return true;
}

/**
 @Status Stub
 @Notes
*/
CGGlyph CGFontGetGlyphWithGlyphName(CGFontRef font, CFStringRef name) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CGFontCopyGlyphNameForGlyph(CGFontRef font, CGGlyph glyph) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
size_t CGFontGetNumberOfGlyphs(CGFontRef font) {
    return font ? font->_dwriteFontFace->GetGlyphCount() : 0;
}

/**
 @Status Interoperable
*/
bool CGFontGetGlyphAdvances(CGFontRef font, const CGGlyph* glyphs, size_t count, int* advances) {
    RETURN_FALSE_IF(!font);

    ComPtr<IDWriteFontFace1> fontFace1;
    font->_dwriteFontFace.As(&fontFace1);

    if (FAILED(fontFace1->GetDesignGlyphAdvances(count, glyphs, advances, false))) {
        TraceError(g_logTag, L"Unable to get glyph advances");
        return false;
    }

    return true;
}

/**
 @Status Interoperable
*/
int CGFontGetUnitsPerEm(CGFontRef font) {
    return font ? __CGFontGetDWriteMetrics(font).designUnitsPerEm : 0;
}

/**
 @Status Interoperable
 @Notes
*/
CFTypeID CGFontGetTypeID() {
    static CFTypeID __kCGFontTypeID = _CFRuntimeRegisterClass(&__CGFontClass);
    return __kCGFontTypeID;
}