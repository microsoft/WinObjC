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

#import <CoreGraphics/CoreGraphicsExport.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGDataProvider.h>

typedef const struct __CGFont* CGFontRef;

typedef unsigned short CGFontIndex;
typedef CGFontIndex CGGlyph;

typedef enum {
    kCGFontPostScriptFormatType1 = 1,
    kCGFontPostScriptFormatType3 = 3,
    kCGFontPostScriptFormatType42 = 42
} CGFontPostScriptFormat;

COREGRAPHICS_EXPORT const CFStringRef kCGFontVariationAxisName;
COREGRAPHICS_EXPORT const CFStringRef kCGFontVariationAxisMinValue;
COREGRAPHICS_EXPORT const CFStringRef kCGFontVariationAxisMaxValue;
COREGRAPHICS_EXPORT const CFStringRef kCGFontVariationAxisDefaultValue;

COREGRAPHICS_EXPORT void CGFontRelease(CGFontRef font);
COREGRAPHICS_EXPORT CGFontRef CGFontRetain(CGFontRef font);
COREGRAPHICS_EXPORT CGFontRef CGFontCreateWithDataProvider(CGDataProviderRef provider) STUB_METHOD;
COREGRAPHICS_EXPORT CGFontRef CGFontCreateWithFontName(CFStringRef name);

COREGRAPHICS_EXPORT CGFontRef CGFontCreateCopyWithVariations(CGFontRef font, CFDictionaryRef variations) STUB_METHOD;
COREGRAPHICS_EXPORT CFStringRef CGFontCopyPostScriptName(CGFontRef font);
COREGRAPHICS_EXPORT bool CGFontCanCreatePostScriptSubset(CGFontRef font, CGFontPostScriptFormat format) STUB_METHOD;
COREGRAPHICS_EXPORT CFDataRef CGFontCreatePostScriptSubset(CGFontRef font,
                                                           CFStringRef subsetName,
                                                           CGFontPostScriptFormat format,
                                                           const CGGlyph* glyphs,
                                                           size_t count,
                                                           const CGGlyph encoding[256]) STUB_METHOD;
COREGRAPHICS_EXPORT CFDataRef CGFontCreatePostScriptEncoding(CGFontRef font, const CGGlyph encoding[256]) STUB_METHOD;
COREGRAPHICS_EXPORT CFArrayRef CGFontCopyTableTags(CGFontRef font) STUB_METHOD;

COREGRAPHICS_EXPORT CFDataRef CGFontCopyTableForTag(CGFontRef font, uint32_t tag);

COREGRAPHICS_EXPORT CFTypeID CGFontGetTypeID();
COREGRAPHICS_EXPORT CFArrayRef CGFontCopyVariationAxes(CGFontRef font) STUB_METHOD;
COREGRAPHICS_EXPORT CFDictionaryRef CGFontCopyVariations(CGFontRef font) STUB_METHOD;

COREGRAPHICS_EXPORT CFStringRef CGFontCopyFullName(CGFontRef font);

COREGRAPHICS_EXPORT int CGFontGetAscent(CGFontRef font);
COREGRAPHICS_EXPORT int CGFontGetDescent(CGFontRef font);

COREGRAPHICS_EXPORT int CGFontGetLeading(CGFontRef font);
COREGRAPHICS_EXPORT int CGFontGetCapHeight(CGFontRef font);

COREGRAPHICS_EXPORT int CGFontGetXHeight(CGFontRef font);
COREGRAPHICS_EXPORT CGRect CGFontGetFontBBox(CGFontRef font);

COREGRAPHICS_EXPORT CGFloat CGFontGetItalicAngle(CGFontRef font);
COREGRAPHICS_EXPORT CGFloat CGFontGetStemV(CGFontRef font) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGFontGetGlyphBBoxes(CGFontRef font, const CGGlyph* glyphs, size_t count, CGRect* bboxes);
COREGRAPHICS_EXPORT CGGlyph CGFontGetGlyphWithGlyphName(CGFontRef font, CFStringRef name) STUB_METHOD;
COREGRAPHICS_EXPORT CFStringRef CGFontCopyGlyphNameForGlyph(CGFontRef font, CGGlyph glyph) STUB_METHOD;
COREGRAPHICS_EXPORT size_t CGFontGetNumberOfGlyphs(CGFontRef font);
COREGRAPHICS_EXPORT bool CGFontGetGlyphAdvances(CGFontRef font, const CGGlyph* glyphs, size_t count, int* advances);
COREGRAPHICS_EXPORT int CGFontGetUnitsPerEm(CGFontRef font);

enum { kCGFontIndexMax = ((1 << 16) - 2), kCGFontIndexInvalid = ((1 << 16) - 1), kCGGlyphMax = kCGFontIndexMax };

enum { CGGlyphMin = 0, CGGlyphMax = kCGGlyphMax };
