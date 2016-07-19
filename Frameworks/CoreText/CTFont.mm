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

#include <map>

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

const CFStringRef kCTFontCopyrightNameKey = static_cast<CFStringRef>(@"kCTFontCopyrightNameKey");
const CFStringRef kCTFontFamilyNameKey = static_cast<CFStringRef>(@"kCTFontFamilyNameKey");
const CFStringRef kCTFontSubFamilyNameKey = static_cast<CFStringRef>(@"kCTFontSubFamilyNameKey");
const CFStringRef kCTFontStyleNameKey = static_cast<CFStringRef>(@"kCTFontStyleNameKey");
const CFStringRef kCTFontUniqueNameKey = static_cast<CFStringRef>(@"kCTFontUniqueNameKey");
const CFStringRef kCTFontFullNameKey = static_cast<CFStringRef>(@"kCTFontFullNameKey");
const CFStringRef kCTFontVersionNameKey = static_cast<CFStringRef>(@"kCTFontVersionNameKey");
const CFStringRef kCTFontPostScriptNameKey = static_cast<CFStringRef>(@"kCTFontPostScriptNameKey");
const CFStringRef kCTFontTrademarkNameKey = static_cast<CFStringRef>(@"kCTFontTrademarkNameKey");
const CFStringRef kCTFontManufacturerNameKey = static_cast<CFStringRef>(@"kCTFontManufacturerNameKey");
const CFStringRef kCTFontDesignerNameKey = static_cast<CFStringRef>(@"kCTFontDesignerNameKey");
const CFStringRef kCTFontDescriptionNameKey = static_cast<CFStringRef>(@"kCTFontDescriptionNameKey");
const CFStringRef kCTFontVendorURLNameKey = static_cast<CFStringRef>(@"kCTFontVendorURLNameKey");
const CFStringRef kCTFontDesignerURLNameKey = static_cast<CFStringRef>(@"kCTFontDesignerURLNameKey");
const CFStringRef kCTFontLicenseNameKey = static_cast<CFStringRef>(@"kCTFontLicenseNameKey");
const CFStringRef kCTFontLicenseURLNameKey = static_cast<CFStringRef>(@"kCTFontLicenseURLNameKey");
const CFStringRef kCTFontSampleTextNameKey = static_cast<CFStringRef>(@"kCTFontSampleTextNameKey");
const CFStringRef kCTFontPostScriptCIDNameKey = static_cast<CFStringRef>(@"kCTFontPostScriptCIDNameKey");
const CFStringRef kCTFontVariationAxisIdentifierKey = static_cast<CFStringRef>(@"kCTFontVariationAxisIdentifierKey");
const CFStringRef kCTFontVariationAxisMinimumValueKey = static_cast<CFStringRef>(@"kCTFontVariationAxisMinimumValueKey");
const CFStringRef kCTFontVariationAxisMaximumValueKey = static_cast<CFStringRef>(@"kCTFontVariationAxisMaximumValueKey");
const CFStringRef kCTFontVariationAxisDefaultValueKey = static_cast<CFStringRef>(@"kCTFontVariationAxisDefaultValueKey");
const CFStringRef kCTFontVariationAxisNameKey = static_cast<CFStringRef>(@"kCTFontVariationAxisNameKey");
const CFStringRef kCTFontFeatureTypeIdentifierKey = static_cast<CFStringRef>(@"kCTFontFeatureTypeIdentifierKey");
const CFStringRef kCTFontFeatureTypeNameKey = static_cast<CFStringRef>(@"kCTFontFeatureTypeNameKey");
const CFStringRef kCTFontFeatureTypeExclusiveKey = static_cast<CFStringRef>(@"kCTFontFeatureTypeExclusiveKey");
const CFStringRef kCTFontFeatureTypeSelectorsKey = static_cast<CFStringRef>(@"kCTFontFeatureTypeSelectorsKey");
const CFStringRef kCTFontFeatureSelectorIdentifierKey = static_cast<CFStringRef>(@"kCTFontFeatureSelectorIdentifierKey");
const CFStringRef kCTFontFeatureSelectorNameKey = static_cast<CFStringRef>(@"kCTFontFeatureSelectorNameKey");
const CFStringRef kCTFontFeatureSelectorDefaultKey = static_cast<CFStringRef>(@"kCTFontFeatureSelectorDefaultKey");
const CFStringRef kCTFontFeatureSelectorSettingKey = static_cast<CFStringRef>(@"kCTFontFeatureSelectorSettingKey");

/**
 @Status Caveat
 @Notes matrix parameter not supported
*/
CTFontRef CTFontCreateWithName(CFStringRef name, CGFloat size, const CGAffineTransform* matrix) {
    if (size == 0.0f) {
        size = 12.0f;
    }

    UIFont* ret = [[_LazyUIFont fontWithName:(NSString*)name size:size] retain];
    return (CTFontRef)ret;
}

/**
 @Status Stub
 @Notes
*/
CTFontRef CTFontCreateWithNameAndOptions(CFStringRef name, CGFloat size, const CGAffineTransform* matrix, CTFontOptions options) {
    UNIMPLEMENTED();
    return StubReturn();
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
 @Status Caveat
 @Notes matrix parameter not supported
*/
CTFontRef CTFontCreateCopyWithSymbolicTraits(
    CTFontRef font, CGFloat size, const CGAffineTransform* matrix, CTFontSymbolicTraits symTraitValue, CTFontSymbolicTraits symTraitMask) {
    if (font == nil) {
        return nullptr;
    }

    UIFontDescriptorSymbolicTraits existingTraits = [(UIFont*)font fontDescriptor].symbolicTraits;
    UIFontDescriptor* newFontDescriptor =
        [[(UIFont*)font fontDescriptor] fontDescriptorWithSymbolicTraits:(existingTraits | symTraitValue) & symTraitMask];

    if (size == 0.0f) {
        size = ((UIFont*)font).pointSize;
    }
    UIFont* ret = [[_LazyUIFont fontWithDescriptor:newFontDescriptor size:size] retain];

    return (CTFontRef)ret;
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
float CTFontGetSize(CTFontRef font) {
    float ret = [(UIFont*)font pointSize];

    return ret;
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
 @Status Caveat
 @Notes Always returns font family name
*/
CFStringRef CTFontCopyPostScriptName(CTFontRef font) {
    return (CFStringRef)[[(UIFont*)font fontName] retain];
}

/**
 @Status Interoperable
*/
CFStringRef CTFontCopyFamilyName(CTFontRef font) {
    return (CFStringRef)[[(UIFont*)font fontName] retain];
}

/**
 @Status Caveat
 @Notes Calls CTFontCopyName which supports limited encodings.
*/
CFStringRef CTFontCopyFullName(CTFontRef font) {
    return CTFontCopyName(font, kCTFontFullNameKey);
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CTFontCopyDisplayName(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Supports only English language and limited encodings.
*/
CFStringRef CTFontCopyName(CTFontRef font, CFStringRef nameKey) {
    if (nameKey == nullptr || font == nullptr) {
        return nullptr;
    }

    //  Get the font
    FT_Face face = reinterpret_cast<FT_Face>([(UIFont*)font _sizingFontHandle]);

    // Style name is not present in the name table associated with the font.
    // It is stored in FT_Face.
    if (nameKey == kCTFontStyleNameKey) {
        return static_cast<CFStringRef>([[NSString stringWithCString:face->style_name] retain]);
    }

    auto it = g_nameIdMap.find(nameKey);
    if (it == g_nameIdMap.end()) {
        // Specified nameKey is not a CTFont name specifier constant.
        return nullptr;
    }

    FT_UInt nameId = it->second;
    FT_CharMap charMap = face->charmap;

    // For now only Microsoft platform is supported.
    if (charMap->platform_id != TT_PLATFORM_MICROSOFT) {
        TraceInfo(g_logTag, L"Unsupported platform %u", charMap->platform_id);
        return nullptr;
    }

    FT_ULong languageId = FT_Get_CMap_Language_ID(charMap);
    if (languageId == TT_MAC_LANGID_ENGLISH) {
        // In case of error FT_Get_CMap_Language_ID returns a value of 0 which defaults to English on Mac.
        // For Microsoft platform switch this default value as per the language Ids defined for Microsoft.
        languageId = TT_MS_LANGID_ENGLISH_UNITED_STATES;
    }

    // For now only English language is supported.
    const FT_ULong languageIdSuffixMask = 0xFF;
    const FT_ULong englishLanguageIdSuffix = 0x09;
    if ((languageId & languageIdSuffixMask) != englishLanguageIdSuffix) {
        TraceInfo(g_logTag, L"Unsupported language %u", languageId);
        return nullptr;
    }

    CFStringRef fontName = nullptr;
    FT_UInt nameCount = FT_Get_Sfnt_Name_Count(face);
    for (FT_UInt i = 0; i < nameCount; i++) {
        // Get entry at index i from name table.
        FT_SfntName fontNameInfo = {};
        FT_Error error = FT_Get_Sfnt_Name(face, i, &fontNameInfo);
        if (error) {
            continue;
        }

        NSStringEncoding stringEncoding{};
        if (TT_PLATFORM_MICROSOFT == fontNameInfo.platform_id && charMap->encoding_id == fontNameInfo.encoding_id &&
            languageId == fontNameInfo.language_id && nameId == fontNameInfo.name_id) {
            // FreeType thinks we are running on Mac and returns the bytes in big endian format even when
            // we are on Microsoft platform so we adjust the encoding id accordingly.
            switch (charMap->encoding_id) {
                case TT_MS_ID_UNICODE_CS: // Unicode BMP
                    stringEncoding = NSUTF16BigEndianStringEncoding;
                    break;

                case TT_MS_ID_UCS_4: // Unicode UCS-4
                    stringEncoding = NSUTF32BigEndianStringEncoding;
                    break;

                default:
                    TraceInfo(g_logTag, L"Unsupported encoding %u", charMap->encoding_id);
                    break;
            }

            if (stringEncoding) {
                NSData* data = [NSData dataWithBytesNoCopy:fontNameInfo.string length:fontNameInfo.string_len freeWhenDone:NO];
                fontName = static_cast<CFStringRef>([[NSString alloc] initWithData:data encoding:stringEncoding]);
            }

            break;
        }
    }

    return fontName;
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

/**
 @Status Interoperable
 @Notes
*/
CGFloat CTFontGetAscent(CTFontRef font) {
    //  Get the font
    return [(UIFont*)font ascender];
}

/**
 @Status Interoperable
 @Notes
*/
CGFloat CTFontGetDescent(CTFontRef font) {
    return [(UIFont*)font descender];
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
 @Status Stub
 @Notes
*/
unsigned int CTFontGetUnitsPerEm(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFIndex CTFontGetGlyphCount(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
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
 @Status Stub
 @Notes
*/
CGFloat CTFontGetUnderlinePosition(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGFloat CTFontGetUnderlineThickness(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
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
 @Status Stub
 @Notes
*/
CGFloat CTFontGetCapHeight(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGFloat CTFontGetXHeight(CTFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
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
 @Status Stub
 @Notes
*/
CFTypeID CTFontGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
