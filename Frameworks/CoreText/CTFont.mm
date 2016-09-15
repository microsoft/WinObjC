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

#import <CoreText/CTFont.h>
#import <CGFontInternal.h>
#import <LoggingNative.h>
#import <Starboard.h>
#import <StubReturn.h>
#import <CoreFoundation/CFString.h>
#import <CFRuntime.h>
#import <CoreText/DWriteWrapper.h>
#import "UIFontInternal.h"

extern "C" {
#include <ft2build.h>
#include FT_FREETYPE_H
#include <ftglyph.h>
#include <tttables.h>
#include <ftadvanc.h>
#include <ftsizes.h>
#include <ftsnames.h>
#include <ttnameid.h>
}

#include <COMIncludes.h>
#import <DWrite_3.h>
#import <wrl/client.h>
#include <COMIncludes_End.h>

#import <map>
#import <memory>
#import <vector>

static const wchar_t* g_logTag = L"CTFont";

static IWLazyClassLookup _LazyUIFont("UIFont");

static const std::map<const CFStringRef, FT_UInt> g_nameIdMap = {
    { kCTFontCopyrightNameKey, 0 },
    { kCTFontFamilyNameKey, 1 },
    { kCTFontSubFamilyNameKey, 2 },
    { kCTFontUniqueNameKey, 3 },
    { kCTFontFullNameKey, 4 },
    { kCTFontVersionNameKey, 5 },
    { kCTFontPostScriptNameKey, 6 },
    { kCTFontTrademarkNameKey, 7 },
    { kCTFontManufacturerNameKey, 8 },
    { kCTFontDesignerNameKey, 9 },
    { kCTFontDescriptionNameKey, 10 },
    { kCTFontVendorURLNameKey, 11 },
    { kCTFontDesignerURLNameKey, 12 },
    { kCTFontLicenseNameKey, 13 },
    { kCTFontLicenseURLNameKey, 14 },

    // https://developer.apple.com/fonts/TrueType-Reference-Manual/RM06/Chap6name.html
    // Name index 15 is reserved.
    // Name index 16 is not a CTFont name specifier constant.
    // Name index 17 is not a CTFont name specifier constant.
    // Name index 18 is not a CTFont name specifier constant.

    { kCTFontSampleTextNameKey, 19 },

    // http://scripts.sil.org/cms/scripts/page.php?item_id=IWS-Chapter08
    { kCTFontPostScriptCIDNameKey, 20 },
};

const CFStringRef kCTFontCopyrightNameKey = CFSTR("CTFontCopyrightName");
const CFStringRef kCTFontFamilyNameKey = CFSTR("CTFontFamilyName");
const CFStringRef kCTFontSubFamilyNameKey = CFSTR("CTFontSubFamilyName");
const CFStringRef kCTFontStyleNameKey = CFSTR("CTFontStyleName");
const CFStringRef kCTFontUniqueNameKey = CFSTR("CTFontUniqueName");
const CFStringRef kCTFontFullNameKey = CFSTR("CTFontFullName");
const CFStringRef kCTFontVersionNameKey = CFSTR("CTFontVersionName");
const CFStringRef kCTFontPostScriptNameKey = CFSTR("CTFontPostScriptName");
const CFStringRef kCTFontTrademarkNameKey = CFSTR("CTFontTrademarkName");
const CFStringRef kCTFontManufacturerNameKey = CFSTR("CTFontManufacturerName");
const CFStringRef kCTFontDesignerNameKey = CFSTR("CTFontDesignerName");
const CFStringRef kCTFontDescriptionNameKey = CFSTR("CTFontDescriptionName");
const CFStringRef kCTFontVendorURLNameKey = CFSTR("CTFontVendorURLName");
const CFStringRef kCTFontDesignerURLNameKey = CFSTR("CTFontDesignerURLName");
const CFStringRef kCTFontLicenseNameKey = CFSTR("CTFontLicenseName");
const CFStringRef kCTFontLicenseURLNameKey = CFSTR("CTFontLicenseURLName");
const CFStringRef kCTFontSampleTextNameKey = CFSTR("CTFontSampleTextName");
const CFStringRef kCTFontPostScriptCIDNameKey = CFSTR("CTFontPostScriptCIDName");
const CFStringRef kCTFontVariationAxisIdentifierKey = CFSTR("CTFontVariationAxisIdentifier");
const CFStringRef kCTFontVariationAxisMinimumValueKey = CFSTR("CTFontVariationAxisMinimumValue");
const CFStringRef kCTFontVariationAxisMaximumValueKey = CFSTR("CTFontVariationAxisMaximumValue");
const CFStringRef kCTFontVariationAxisDefaultValueKey = CFSTR("CTFontVariationAxisDefaultValue");
const CFStringRef kCTFontVariationAxisNameKey = CFSTR("CTFontVariationAxisName");
const CFStringRef kCTFontFeatureTypeIdentifierKey = CFSTR("CTFontFeatureTypeIdentifier");
const CFStringRef kCTFontFeatureTypeNameKey = CFSTR("CTFontFeatureTypeName");
const CFStringRef kCTFontFeatureTypeExclusiveKey = CFSTR("CTFontFeatureTypeExclusive");
const CFStringRef kCTFontFeatureTypeSelectorsKey = CFSTR("CTFontFeatureTypeSelectors");
const CFStringRef kCTFontFeatureSelectorIdentifierKey = CFSTR("CTFontFeatureSelectorIdentifier");
const CFStringRef kCTFontFeatureSelectorNameKey = CFSTR("CTFontFeatureSelectorName");
const CFStringRef kCTFontFeatureSelectorDefaultKey = CFSTR("CTFontFeatureSelectorDefault");
const CFStringRef kCTFontFeatureSelectorSettingKey = CFSTR("CTFontFeatureSelectorSetting");

/**
 All these values are fixed number in IOS no matter on iphone* or ipad*.
 */
const CGFloat kCTFontLabelFontSize = 17.0f;
const CGFloat kCTFontButtonFontSize = 14.0f;
const CGFloat kCTFontSmallSystemFontSize = 12.0f;
const CGFloat kCTFontSystemFontSize = 14.0f;

using namespace Microsoft::WRL;

struct __CTFont {
    CFRuntimeBase _base;
    ComPtr<IDWriteFontFace> _dwriteFontFace;
    CGFloat _pointSize;

    struct DWRITE_FONT_METRICS _metrics;
    bool _cachedMetrics; // Set to true when _metrics is init'd
};

static Boolean __CTFontEqual(CFTypeRef cf1, CFTypeRef cf2) {
    struct __CTFont* font1 = (struct __CTFont*)cf1;
    struct __CTFont* font2 = (struct __CTFont*)cf2;

    if (font1->_pointSize != font2->_pointSize) {
        return false;
    }

    return font1->_dwriteFontFace == font2->_dwriteFontFace;
}

static CFHashCode __CTFontHash(CFTypeRef cf) {
    CTFontRef font = (CTFontRef)cf;
    return CFHash(CFAutorelease(CTFontCopyFullName(font))) * CTFontGetSize(font);
}

static CFStringRef __CTFontCopyDescription(CFTypeRef cf) {
    CTFontRef font = (CTFontRef)cf;
    return CFStringCreateWithFormat(kCFAllocatorSystemDefault,
                                    NULL,
                                    CFSTR("<CTFont %p>{font-family: %@; font-size: %.2f}"),
                                    cf,
                                    CFAutorelease(CTFontCopyFamilyName(font)),
                                    CTFontGetSize(font));
}

static void __CTFontInit(CFTypeRef cf) {
    CTFontRef font = (CTFontRef)cf;
    // ComPtr needs to be manually new'd, to avoid calling Create functions to an incomplete out-pointer
    struct __CTFont* mutableFont = const_cast<struct __CTFont*>(font);
    new (std::addressof(mutableFont->_dwriteFontFace)) ComPtr<IDWriteFontFace>();
}

static void __CTFontDeallocate(CFTypeRef cf) {
    CTFontRef font = (CTFontRef)cf;
    // ComPtr needs to be manually destructed, since CFTypes do a memset(0) on dealloc
    font->_dwriteFontFace.~ComPtr();
}

static CFTypeID __kCTFontTypeID = _kCFRuntimeNotATypeID;

static const CFRuntimeClass __CTFontClass = { 0,
                                              "CTFont",
                                              __CTFontInit, // init
                                              NULL, // copy
                                              __CTFontDeallocate, // deallocate
                                              __CTFontEqual,
                                              __CTFontHash,
                                              NULL, //
                                              __CTFontCopyDescription };

/**
 @Status Caveat
 @Notes matrix parameter not supported
*/
CTFontRef CTFontCreateWithName(CFStringRef name, CGFloat size, const CGAffineTransform* matrix) {
    return CTFontCreateWithNameAndOptions(name, size, matrix, kCTFontOptionsDefault);
}

/**
 @Status Caveat
 @Notes matrix parameter not supported
*/
CTFontRef CTFontCreateWithNameAndOptions(CFStringRef name, CGFloat size, const CGAffineTransform* matrix, CTFontOptions options) {
    size_t memSize = sizeof(struct __CTFont) - sizeof(CFRuntimeBase);
    CTFontRef ret = static_cast<CTFontRef>(_CFRuntimeCreateInstance(kCFAllocatorDefault, CTFontGetTypeID(), memSize, NULL));
    struct __CTFont* mutableRet = const_cast<struct __CTFont*>(ret);

    if (FAILED(_DWriteCreateFontFaceWithName(name, &mutableRet->_dwriteFontFace))) {
        TraceError(g_logTag, L"Failed to create font.");
        CFRelease(ret);
        return nullptr;
    }

    mutableRet->_pointSize = size > 0 ? size : kCTFontSystemFontSize;
    return ret;
}

/**
 @Status Stub
 @Notes Always returns Helvetica 12-point font
*/
CTFontRef CTFontCreateWithFontDescriptor(CTFontDescriptorRef descriptor, CGFloat size, const CGAffineTransform* matrix) {
    UNIMPLEMENTED();
    if (size == 0.0f)
        size = 12.0f;
    id ret = [[_LazyUIFont fontWithName:@"Helvetica" size:size] retain];
    return (CTFontRef)ret;
}

/**
 @Status Stub
 @Notes
*/
CTFontRef CTFontCreateWithFontDescriptorAndOptions(CTFontDescriptorRef descriptor,
                                                   CGFloat size,
                                                   const CGAffineTransform* matrix,
                                                   CTFontOptions options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CTFontRef CTFontCreateUIFontForLanguage(CTFontUIFontType uiType, CGFloat size, CFStringRef language) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CTFontRef CTFontCreateCopyWithAttributes(CTFontRef font, CGFloat size, const CGAffineTransform* matrix, CTFontDescriptorRef attributes) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes matrix parameter not supported
*/
CTFontRef CTFontCreateCopyWithSymbolicTraits(
    CTFontRef font, CGFloat size, const CGAffineTransform* matrix, CTFontSymbolicTraits symTraitValue, CTFontSymbolicTraits symTraitMask) {
    if (font == nil) {
        return nullptr;
    }
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CTFontRef CTFontCreateCopyWithFamily(CTFontRef font, CGFloat size, const CGAffineTransform* matrix, CFStringRef family) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CTFontRef CTFontCreateForString(CTFontRef currentFont, CFStringRef string, CFRange range) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CTFontDescriptorRef CTFontCopyFontDescriptor(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeRef CTFontCopyAttribute(CTFontRef font, CFStringRef attribute) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
CGFloat CTFontGetSize(CTFontRef font) {
    return font->_pointSize;
}

/**
 @Status Stub
 @Notes
*/
CGAffineTransform CTFontGetMatrix(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CTFontSymbolicTraits CTFontGetSymbolicTraits(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CTFontCopyTraits(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
CFStringRef CTFontCopyPostScriptName(CTFontRef font) {
    return CTFontCopyName(font, kCTFontPostScriptNameKey);
}

/**
 @Status Interoperable
*/
CFStringRef CTFontCopyFamilyName(CTFontRef font) {
    return CTFontCopyName(font, kCTFontFamilyNameKey);
}

/**
 @Status Interoperable
*/
CFStringRef CTFontCopyFullName(CTFontRef font) {
    return CTFontCopyName(font, kCTFontFullNameKey);
}

/**
 @Status Interoperable
*/
CFStringRef CTFontCopyDisplayName(CTFontRef font) {
    // This should work okay as a display name
    return CTFontCopyName(font, kCTFontFullNameKey);
}

/**
 @Status Interoperable
*/
CFStringRef CTFontCopyName(CTFontRef font, CFStringRef nameKey) {
    if (nameKey == nullptr || font == nullptr) {
        return nullptr;
    }

    ComPtr<IDWriteLocalizedStrings> name;
    BOOL exists;
    DWRITE_INFORMATIONAL_STRING_ID informationalStringId;

    ComPtr<IDWriteFontFace3> dwriteFontFace3;
    font->_dwriteFontFace.As(&dwriteFontFace3);

    if (CFEqual(nameKey, kCTFontCopyrightNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_COPYRIGHT_NOTICE;
    } else if (CFEqual(nameKey, kCTFontFamilyNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_WIN32_FAMILY_NAMES;
    } else if (CFEqual(nameKey, kCTFontSubFamilyNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_WIN32_SUBFAMILY_NAMES;
    } else if (CFEqual(nameKey, kCTFontStyleNameKey)) {
        THROW_IF_FAILED(dwriteFontFace3->GetFaceNames(&name));
        return static_cast<CFStringRef>(CFRetain(_CFStringFromLocalizedString(name.Get())));

    } else if (CFEqual(nameKey, kCTFontUniqueNameKey)) {
        return CFStringCreateWithFormat(kCFAllocatorDefault,
                                        nullptr,
                                        CFSTR("%@ %@"),
                                        CFAutorelease(CTFontCopyName(font, kCTFontFullNameKey)),
                                        CFAutorelease(CTFontCopyName(font, kCTFontStyleNameKey)));

    } else if (CFEqual(nameKey, kCTFontFullNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_FULL_NAME;
    } else if (CFEqual(nameKey, kCTFontVersionNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_VERSION_STRINGS;
    } else if (CFEqual(nameKey, kCTFontPostScriptNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_NAME;
    } else if (CFEqual(nameKey, kCTFontTrademarkNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_TRADEMARK;
    } else if (CFEqual(nameKey, kCTFontManufacturerNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_MANUFACTURER;
    } else if (CFEqual(nameKey, kCTFontDesignerNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_DESIGNER;
    } else if (CFEqual(nameKey, kCTFontDescriptionNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_DESCRIPTION;
    } else if (CFEqual(nameKey, kCTFontVendorURLNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_FONT_VENDOR_URL;
    } else if (CFEqual(nameKey, kCTFontDesignerURLNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_DESIGNER_URL;
    } else if (CFEqual(nameKey, kCTFontLicenseNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_LICENSE_DESCRIPTION;
    } else if (CFEqual(nameKey, kCTFontLicenseURLNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_LICENSE_INFO_URL;
    } else if (CFEqual(nameKey, kCTFontSampleTextNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_SAMPLE_TEXT;
    } else if (CFEqual(nameKey, kCTFontPostScriptCIDNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_CID_NAME;
    } else {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_NONE;
    }

    THROW_IF_FAILED(dwriteFontFace3->GetInformationalStrings(informationalStringId, &name, &exists));
    return exists ? static_cast<CFStringRef>(CFRetain(_CFStringFromLocalizedString(name.Get()))) : nullptr;
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CTFontCopyLocalizedName(CTFontRef font, CFStringRef nameKey, CFStringRef _Nullable* actualLanguage) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFCharacterSetRef CTFontCopyCharacterSet(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFStringEncoding CTFontGetStringEncoding(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CTFontCopySupportedLanguages(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

// Private helper for getting a DWRITE_FONT_METRICS struct, to avoid code duplication
static struct DWRITE_FONT_METRICS __CTFontGetDWriteMetrics(CTFontRef font) {
    if (!font->_cachedMetrics) {
        font->_dwriteFontFace->GetMetrics(&const_cast<struct __CTFont*>(font)->_metrics);
    }
    return font->_metrics;
}

// Private helper for converting a DWRITE_FONT_METRIC unit to a CTFont API unit
// DWRITE_FONT_METRICS measures its metrics in 'design units'
// CTFont APIs generally return in terms of point size
static CGFloat __CTFontScaleMetric(CTFontRef font, CGFloat metric) {
    // design units * (pt / em) / (design units / em)
    // = design units * (pt / em) * (em / design units)
    // = pt * (design units / design units) * (em / em)
    // = pt
    return metric * font->_pointSize / CTFontGetUnitsPerEm(font);
}

/**
 @Status Interoperable
 @Notes
*/
CGFloat CTFontGetAscent(CTFontRef font) {
    return __CTFontScaleMetric(font, __CTFontGetDWriteMetrics(font).ascent);
}

/**
 @Status Interoperable
 @Notes
*/
CGFloat CTFontGetDescent(CTFontRef font) {
    // DWRITE_FONT_METRICS keeps an unsigned value for descent, but CTFontGetDescent is expected to return a negative value
    return -__CTFontScaleMetric(font, __CTFontGetDWriteMetrics(font).descent);
}

/**
 @Status Stub
 @Notes
*/
CGFloat CTFontGetLeading(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
unsigned int CTFontGetUnitsPerEm(CTFontRef font) {
    return __CTFontGetDWriteMetrics(font).designUnitsPerEm;
}

/**
 @Status Interoperable
 @Notes
*/
CFIndex CTFontGetGlyphCount(CTFontRef font) {
    return font->_dwriteFontFace->GetGlyphCount();
}

/**
 @Status Stub
 @Notes
*/
CGRect CTFontGetBoundingBox(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
CGFloat CTFontGetUnderlinePosition(CTFontRef font) {
    return __CTFontScaleMetric(font, __CTFontGetDWriteMetrics(font).underlinePosition);
}

/**
 @Status Interoperable
 @Notes
*/
CGFloat CTFontGetUnderlineThickness(CTFontRef font) {
    return __CTFontScaleMetric(font, __CTFontGetDWriteMetrics(font).underlineThickness);
}

/**
 @Status Stub
 @Notes
*/
CGFloat CTFontGetSlantAngle(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
CGFloat CTFontGetCapHeight(CTFontRef font) {
    return __CTFontScaleMetric(font, __CTFontGetDWriteMetrics(font).capHeight);
}

/**
 @Status Interoperable
 @Notes
*/
CGFloat CTFontGetXHeight(CTFontRef font) {
    return __CTFontScaleMetric(font, __CTFontGetDWriteMetrics(font).xHeight);
}

/**
 @Status Stub
 @Notes
*/
CGPathRef CTFontCreatePathForGlyph(CTFontRef font, CGGlyph glyph, const CGAffineTransform* matrix) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGGlyph CTFontGetGlyphWithName(CTFontRef font, CFStringRef glyphName) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGRect CTFontGetBoundingRectsForGlyphs(
    CTFontRef font, CTFontOrientation orientation, const CGGlyph glyphs[], CGRect* boundingRects, CFIndex count) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Orientation parameter is not supported
*/
double CTFontGetAdvancesForGlyphs(CTFontRef font, CTFontOrientation orientation, const CGGlyph glyphs[], CGSize* advances, CFIndex count) {
    DWORD i;
    double total = 0.0f;

    _CGFontLock();
    //  Get the font
    FT_Face face = (FT_Face)[(UIFont*)font _sizingFontHandle];
    CGFontSetFTFontSize((CGFontRef)font, face, [(UIFont*)font pointSize]);

    FT_Error error;
    FT_GlyphSlot slot = face->glyph;

    //  Lookup each glyph
    for (i = 0; i < count; i++) {
        error = FT_Load_Glyph(face, glyphs[i], FT_LOAD_NO_HINTING);
        FT_GlyphSlot slot = face->glyph;

        CGSize size = { 0, 0 };
        if (error == 0) {
            size.width = ((float)(slot->advance.x)) / 64.0f;
        }

        if (advances)
            advances[i] = size;
        total += size.width;
    }
    _CGFontUnlock();

    return total;
}

/**
 @Status Stub
 @Notes
*/
void CTFontGetVerticalTranslationsForGlyphs(CTFontRef font, const CGGlyph glyphs[], CGSize translations[], CFIndex count) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CTFontCopyVariationAxes(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CTFontCopyVariation(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CTFontCopyFeatures(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CTFontCopyFeatureSettings(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CTFontGetGlyphsForCharacters(CTFontRef font, const UniChar characters[], CGGlyph glyphs[], CFIndex count) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CTFontDrawGlyphs(CTFontRef font, const CGGlyph glyphs[], const CGPoint positions[], size_t count, CGContextRef context) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFIndex CTFontGetLigatureCaretPositions(CTFontRef font, CGGlyph glyph, CGFloat* positions, CFIndex maxPositions) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Attributes parameter is not supported
*/
CGFontRef CTFontCopyGraphicsFont(CTFontRef font, CTFontDescriptorRef _Nullable* attributes) {
    return (CGFontRef)[static_cast<UIFont*>(font) retain];
}

/**
 @Status Caveat
 @Notes transform and attributes parameters not supported
*/
CTFontRef CTFontCreateWithGraphicsFont(CGFontRef cgFont, CGFloat size, const CGAffineTransform* xform, CTFontDescriptorRef attributes) {
    if (size == 0.0f) {
        size = 12.0f;
    }

    id ret = [[(UIFont*)cgFont fontWithSize:size] retain];
    return (CTFontRef)ret;
}
/**
 @Status Stub
 @Notes
*/
CFArrayRef CTFontCopyAvailableTables(CTFontRef font, CTFontTableOptions options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDataRef CTFontCopyTable(CTFontRef font, CTFontTableTag table, CTFontTableOptions options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
CFTypeID CTFontGetTypeID() {
    static dispatch_once_t initOnce = 0;
    dispatch_once(&initOnce,
                  ^{
                      __kCTFontTypeID = _CFRuntimeRegisterClass(&__CTFontClass);
                  });
    return __kCTFontTypeID;
}