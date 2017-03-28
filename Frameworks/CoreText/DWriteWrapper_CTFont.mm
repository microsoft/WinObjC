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

#import "DWriteWrapper_CoreText.h"

#import <LoggingNative.h>

using namespace Microsoft::WRL;

static const wchar_t* TAG = L"_DWriteWrapper_CTFont";

// Represents a mapping between multiple representations of the same font weight across DWrite and CoreText
// Some loss of precision here as CT presents fewer values than DWrite
// Note also that Thin and Ultra/Extra-Light are in opposite order in DWrite and CoreText/UIKit constants
// (However, "Thin" fonts on the reference platform have UIFontWeightUltraLight...)
static const struct {
    DWRITE_FONT_WEIGHT dwriteValue;
    CGFloat ctValue;
} c_weightMap[] = { { DWRITE_FONT_WEIGHT_THIN, kCTFontWeightUltraLight },    { DWRITE_FONT_WEIGHT_EXTRA_LIGHT, kCTFontWeightThin },
                    { DWRITE_FONT_WEIGHT_ULTRA_LIGHT, kCTFontWeightThin },   { DWRITE_FONT_WEIGHT_LIGHT, kCTFontWeightLight },
                    { DWRITE_FONT_WEIGHT_SEMI_LIGHT, kCTFontWeightLight },   { DWRITE_FONT_WEIGHT_NORMAL, kCTFontWeightRegular },
                    { DWRITE_FONT_WEIGHT_REGULAR, kCTFontWeightRegular },    { DWRITE_FONT_WEIGHT_MEDIUM, kCTFontWeightMedium },
                    { DWRITE_FONT_WEIGHT_DEMI_BOLD, kCTFontWeightSemibold }, { DWRITE_FONT_WEIGHT_SEMI_BOLD, kCTFontWeightSemibold },
                    { DWRITE_FONT_WEIGHT_BOLD, kCTFontWeightBold },          { DWRITE_FONT_WEIGHT_EXTRA_BOLD, kCTFontWeightHeavy },
                    { DWRITE_FONT_WEIGHT_ULTRA_BOLD, kCTFontWeightHeavy },   { DWRITE_FONT_WEIGHT_BLACK, kCTFontWeightBlack },
                    { DWRITE_FONT_WEIGHT_HEAVY, kCTFontWeightBlack },        { DWRITE_FONT_WEIGHT_EXTRA_BLACK, kCTFontWeightBlack },
                    { DWRITE_FONT_WEIGHT_ULTRA_BLACK, kCTFontWeightBlack } };

/**
 * Helper function that efficiently compares two CFStringRef and returns true if they are equal (case insensitive)
 */
static inline bool __CFStringEqual(CFStringRef left, CFStringRef right) {
    return CFStringCompare(left, right, kCFCompareCaseInsensitive) == kCFCompareEqualTo;
}

/**
 * Helper function that converts a DWRITE_FONT_WEIGHT into a float usable for kCTFontWeightTrait.
 */
static CGFloat __DWriteFontWeightToCT(DWRITE_FONT_WEIGHT weight) {
    for (const auto& weightMapping : c_weightMap) {
        if (weight == weightMapping.dwriteValue) {
            return weightMapping.ctValue;
        }
    }

    return kCTFontWeightRegular;
}

/**
 * Helper function that converts a kCTFontWeightTrait-eligible CGFloat into a DWRITE_FONT_WEIGHT
 */
static DWRITE_FONT_WEIGHT __CTFontWeightToDWrite(CGFloat weight) {
    for (const auto& weightMapping : c_weightMap) {
        if (weight == weightMapping.ctValue) {
            return weightMapping.dwriteValue;
        }
    }

    return DWRITE_FONT_WEIGHT_NORMAL;
}

/**
 * Helper function that converts a DWRITE_FONT_STRETCH into a float usable for kCTFontWidthTrait.
 */
static CGFloat __DWriteFontStretchToCT(DWRITE_FONT_STRETCH stretch) {
    // kCTFontWidthTrait is documented to range from -1.0 to 1.0, centered at 0,
    // with 'Condensed' fonts returning -0.2 on the reference platform
    // DWrite stretch ranges from 0-9, centered at 5

    // Reference platform lacks fonts with stretch besides 'normal' or 'condensed',
    // and it is not yet clear how these values are used
    // Do an approximate conversion for now
    return (static_cast<float>(stretch) / 10.0f) - 0.5f;
}

/**
 * Private helper that examines a traits dict, then returns a struct of DWRITE_FONT_WEIGHT, _STRETCH, _STYLE,
 * derived from that traits dict.
 *
 * Note that the name fields in the _DWriteFontProperties are left as blank
 */
static _DWriteFontProperties __DWriteFontPropertiesFromTraits(CFDictionaryRef traits) {
    _DWriteFontProperties ret = {};

    if (!traits) {
        return ret;
    }

    // kCTFontWeightTrait, kCTFontWidthTrait, kCTFontSlantTrait take precedence over symbolic traits
    CFNumberRef weightTrait = static_cast<CFNumberRef>(CFDictionaryGetValue(traits, kCTFontWeightTrait));
    CFNumberRef widthTrait = static_cast<CFNumberRef>(CFDictionaryGetValue(traits, kCTFontWidthTrait));
    CFNumberRef slantTrait = static_cast<CFNumberRef>(CFDictionaryGetValue(traits, kCTFontSlantTrait));

    CFNumberRef cfSymbolicTrait = static_cast<CFNumberRef>(CFDictionaryGetValue(traits, kCTFontSymbolicTrait));
    uint32_t symbolicTrait = cfSymbolicTrait ? _CTFontSymbolicTraitsFromCFNumber(cfSymbolicTrait) : 0;

    // Check numeric weightTrait first, otherwise defer to symbolic traits, otherwise leave as _NORMAL
    if (weightTrait) {
        CGFloat weightFloat;
        CFNumberGetValue(weightTrait, kCFNumberCGFloatType, &weightFloat);
        ret.weight = __CTFontWeightToDWrite(weightFloat);
    } else if (symbolicTrait & kCTFontBoldTrait) {
        ret.weight = DWRITE_FONT_WEIGHT_BOLD;
    }

    // Check numeric widthTrait first, otherwise defer to symbolic traits, otherwise leave as _NORMAL
    if (widthTrait) {
        CGFloat widthFloat;
        CFNumberGetValue(widthTrait, kCFNumberCGFloatType, &widthFloat);

        // Treat above 0 as expanded, below 0 as condensed
        if (widthFloat > 0) {
            ret.stretch = DWRITE_FONT_STRETCH_EXPANDED;
        } else if (widthFloat < 0) {
            ret.stretch = DWRITE_FONT_STRETCH_CONDENSED;
        }
    } else if (symbolicTrait & kCTFontExpandedTrait) {
        ret.stretch = DWRITE_FONT_STRETCH_EXPANDED;
    } else if (symbolicTrait & kCTFontCondensedTrait) {
        ret.stretch = DWRITE_FONT_STRETCH_CONDENSED;
    }

    // Check numeric slantTrait first, otherwise defer to symbolic traits, otherwise leave as _NORMAL
    if (slantTrait) {
        CGFloat slantFloat;
        CFNumberGetValue(slantTrait, kCFNumberCGFloatType, &slantFloat);

        // Treat anything above 0 as italic
        if (slantFloat > 0) {
            ret.style = DWRITE_FONT_STYLE_ITALIC;
        }
    } else if (symbolicTrait & kCTFontItalicTrait) {
        ret.style = DWRITE_FONT_STYLE_ITALIC;
    }

    return ret;
}

/**
 * Helper function to box a CTFontSymbolicTraits in a CFNumber
 */
CFNumberRef _CFNumberCreateFromSymbolicTraits(CTFontSymbolicTraits symbolicTraits) {
    // symbolic traits are an unsigned 32-bit int
    // CFNumber doesn't support unsigned ints
    // get around this by storing in a signed 64-bit int
    int64_t signedTraits = static_cast<int64_t>(symbolicTraits);
    return CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt64Type, &signedTraits);
}

/**
 * Helper function to unbox a CTFontSymbolicTraits from a CFNumber
 */
CTFontSymbolicTraits _CTFontSymbolicTraitsFromCFNumber(CFNumberRef num) {
    // symbolic traits are an unsigned 32-bit int, but were stored in a signed 64-bit int
    int64_t ret;
    CFNumberGetValue(static_cast<CFNumberRef>(num), kCFNumberSInt64Type, &ret);
    return static_cast<CTFontSymbolicTraits>(ret);
}

/**
 * Creates an IDWriteFontFace given the attributes of a CTFontDescriptor
 * Currently, font name, family name, kCTFontWeight/Slant/Width, and part of SymbolicTrait, are taken into account
 */
HRESULT _DWriteCreateFontFaceWithFontDescriptor(CTFontDescriptorRef fontDescriptor, IDWriteFontFace** fontFace) {
    woc::unique_cf<CFStringRef> fontName(static_cast<CFStringRef>(CTFontDescriptorCopyAttribute(fontDescriptor, kCTFontNameAttribute)));
    woc::unique_cf<CFStringRef> familyName(
        static_cast<CFStringRef>(CTFontDescriptorCopyAttribute(fontDescriptor, kCTFontFamilyNameAttribute)));

    // font name takes precedence
    if (fontName.get()) {
        if (familyName.get() && !CFEqual(familyName.get(), _DWriteGetFontPropertiesFromName(fontName.get())->familyName.get())) {
            TraceError(TAG,
                       L"Mismatched font name (kCTFontNameAttribute) and family name (kCTFontFamilyNameAttribute) in "
                       L"_DWriteCreateFontFaceWithFontDescriptor");
            return E_INVALIDARG;
        }

        // familyName is either valid for fontName, or unspecified
        // just use fontName, then
        return _DWriteCreateFontFaceWithName(fontName.get(), fontFace);
    }

    // otherwise, look at family name and other attributes
    if (familyName.get()) {
        ComPtr<IDWriteFontFamily> fontFamily;
        RETURN_IF_FAILED(_DWriteCreateFontFamilyWithName(familyName.get(), &fontFamily));
        RETURN_HR_IF_NULL(E_INVALIDARG, fontFamily);

        // Look for traits that may specify weight, stretch, style
        woc::unique_cf<CFDictionaryRef> traits(
            static_cast<CFDictionaryRef>(CTFontDescriptorCopyAttribute(fontDescriptor, kCTFontTraitsAttribute)));
        _DWriteFontProperties properties = __DWriteFontPropertiesFromTraits(traits.get());

        // Create a best matching font based on the family name and weight/stretch/style
        ComPtr<IDWriteFont> font;
        RETURN_IF_FAILED(fontFamily->GetFirstMatchingFont(properties.weight, properties.stretch, properties.style, &font));

        return font->CreateFontFace(fontFace);
    }

    TraceError(TAG, L"Must specify either kCTFontFamilyNameAttribute or kCTFontNameAttribute in font descriptor");
    return E_INVALIDARG;
}

// Helper methods for removing fonts that do not match given attributes for CTFontDescriptorCreateMatchingFontDescriptors
#pragma region Helper Filter Methods

static void __FilterFontsByTraits(const std::vector<ComPtr<IDWriteFont>>& fonts,
                                  CFDictionaryRef traits,
                                  std::vector<ComPtr<IDWriteFont>>& matchingFonts) {
    _DWriteFontProperties properties = __DWriteFontPropertiesFromTraits(traits);
    for (auto& font : fonts) {
        if (font->GetWeight() == properties.weight && font->GetStretch() == properties.stretch && font->GetStyle() == properties.style) {
            matchingFonts.emplace_back(font);
        }
    }
}

static HRESULT __FilterFontsByStyleName(const std::vector<ComPtr<IDWriteFont>>& fonts,
                                        CFStringRef styleName,
                                        std::vector<ComPtr<IDWriteFont>>& matchingFonts) {
    for (auto& font : fonts) {
        ComPtr<IDWriteLocalizedStrings> dwriteFontName;
        RETURN_IF_FAILED(font->GetFaceNames(&dwriteFontName));
        CFStringRef name = _CFStringFromLocalizedString(dwriteFontName.Get());
        if (__CFStringEqual(styleName, name)) {
            matchingFonts.emplace_back(font);
        }
    }

    return S_OK;
}

static HRESULT __FilterFontsByFamilyName(const std::vector<ComPtr<IDWriteFont>>& fonts,
                                         CFStringRef familyName,
                                         std::vector<ComPtr<IDWriteFont>>& matchingFonts) {
    for (auto& font : fonts) {
        // Need to create font family to get correct name
        ComPtr<IDWriteFontFamily> family;
        RETURN_IF_FAILED(font->GetFontFamily(&family));
        ComPtr<IDWriteLocalizedStrings> dwriteFamilyName;
        RETURN_IF_FAILED(family->GetFamilyNames(&dwriteFamilyName));
        CFStringRef fontFamilyName = _CFStringFromLocalizedString(dwriteFamilyName.Get());
        if (__CFStringEqual(familyName, fontFamilyName)) {
            matchingFonts.emplace_back(font);
        }
    }

    return S_OK;
}

static HRESULT __FilterFontsByInformationalString(const std::vector<ComPtr<IDWriteFont>>& fonts,
                                                  CFStringRef infoString,
                                                  DWRITE_INFORMATIONAL_STRING_ID id,
                                                  std::vector<ComPtr<IDWriteFont>>& matchingFonts) {
    for (auto& font : fonts) {
        BOOL exists;
        ComPtr<IDWriteLocalizedStrings> dwriteString;
        RETURN_IF_FAILED(font->GetInformationalStrings(id, &dwriteString, &exists));
        if (exists) {
            CFStringRef fontInfoString = _CFStringFromLocalizedString(dwriteString.Get());
            if (__CFStringEqual(infoString, fontInfoString)) {
                matchingFonts.emplace_back(font);
            }
        }
    }

    return S_OK;
}

static HRESULT __FilterFontsByKeyAndValue(std::vector<ComPtr<IDWriteFont>>& fonts, CFStringRef key, CFTypeRef value, bool forceMatch) {
    if (__CFStringEqual(key, kCTFontSizeAttribute)) {
        // Ignored on reference platform so simply return here
        return S_OK;
    }

    std::vector<ComPtr<IDWriteFont>> matchingFonts;
    matchingFonts.reserve(fonts.size());
    CFRange range{ 0, CFStringGetLength(key) };
    if (__CFStringEqual(key, kCTFontFamilyNameAttribute)) {
        RETURN_IF_FAILED(__FilterFontsByFamilyName(fonts, static_cast<CFStringRef>(value), matchingFonts));
    } else if (__CFStringEqual(key, kCTFontNameAttribute)) {
        RETURN_IF_FAILED(__FilterFontsByInformationalString(fonts,
                                                            static_cast<CFStringRef>(value),
                                                            DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_NAME,
                                                            matchingFonts));
    } else if (__CFStringEqual(key, kCTFontDisplayNameAttribute)) {
        RETURN_IF_FAILED(__FilterFontsByInformationalString(fonts,
                                                            static_cast<CFStringRef>(value),
                                                            DWRITE_INFORMATIONAL_STRING_FULL_NAME,
                                                            matchingFonts));
    } else if (__CFStringEqual(key, kCTFontStyleNameAttribute)) {
        RETURN_IF_FAILED(__FilterFontsByStyleName(fonts, static_cast<CFStringRef>(value), matchingFonts));
    } else if (__CFStringEqual(key, kCTFontTraitsAttribute)) {
        __FilterFontsByTraits(fonts, static_cast<CFDictionaryRef>(value), matchingFonts);
    } else {
        // Other attributes are currently unsupported by CTFont
        CFIndex length = CFStringGetLength(key);
        std::unique_ptr<UniChar[]> keyChars{ new UniChar[length] };
        CFStringGetCharacters(key, { 0, length }, keyChars.get());
        UNIMPLEMENTED_WITH_MSG("Unsupported matching font descriptor attribute %ls", keyChars.get());
    }

    // Do not filter if there's no match and forceMatch isn't true
    // Used to share filtering between mandatory and optional attributes
    if (!matchingFonts.empty() || forceMatch) {
        fonts = std::move(matchingFonts);
    }

    return S_OK;
}

#pragma endregion // Helper Filter Methods

/**
 * Creates a CFArray of CTFontDescriptors values for all fonts that match the given attributes best and completely match mandatoryKeys
 */
HRESULT _DWriteCreateMatchingFontDescriptors(CFDictionaryRef attributes, CFSetRef mandatoryKeys, CFArrayRef* matchingNames) {
    RETURN_HR_IF(E_POINTER, !attributes || !matchingNames);
    *matchingNames = nullptr;

    std::vector<ComPtr<IDWriteFont>> fonts;
    if (CFDictionaryContainsKey(attributes, kCTFontNameAttribute) &&
        (!mandatoryKeys || CFSetContainsValue(mandatoryKeys, kCTFontNameAttribute))) {
        // Font name is either mandatory or there are no mandatory keys, so we can start match from font
        ComPtr<IDWriteFont> matchingFont;
        if (SUCCEEDED(_DWriteCreateFontWithName(static_cast<CFStringRef>(CFDictionaryGetValue(attributes, kCTFontNameAttribute)),
                                                &matchingFont))) {
            fonts.emplace_back(matchingFont);
        } else {
            // Not matching is not a fatal error, but we can just return now rather than try to match against any other attributes
            RETURN_HR_IF(S_FALSE, mandatoryKeys != nullptr);
        }
    }

    if (fonts.empty() && CFDictionaryContainsKey(attributes, kCTFontFamilyNameAttribute) &&
        (!mandatoryKeys || CFSetContainsValue(mandatoryKeys, kCTFontFamilyNameAttribute))) {
        // Family name is either mandatory or there are no mandatory keys, so we can start match from family
        ComPtr<IDWriteFontFamily> fontFamily;
        if (SUCCEEDED(
                _DWriteCreateFontFamilyWithName(static_cast<CFStringRef>(CFDictionaryGetValue(attributes, kCTFontFamilyNameAttribute)),
                                                &fontFamily))) {
            ComPtr<IDWriteFontList> fontList;
            RETURN_IF_FAILED(
                fontFamily->GetMatchingFonts(DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STRETCH_NORMAL, DWRITE_FONT_STYLE_NORMAL, &fontList));
            uint32_t fontCount = fontList->GetFontCount();
            fonts.reserve(fontCount);
            for (size_t i = 0; i < fontCount; ++i) {
                ComPtr<IDWriteFont> font;
                RETURN_IF_FAILED(fontList->GetFont(i, &font));
                fonts.emplace_back(font);
            }
        } else {
            // Not matching is not a fatal error, but we can just return now rather than try to match against any other attributes
            RETURN_HR_IF(S_FALSE, mandatoryKeys != nullptr);
        }
    }

    if (fonts.empty()) {
        // Could not get a list of matching fonts from font or family names, so need to get a list of all fonts
        RETURN_IF_FAILED(_DWriteGetAllFonts(fonts));
    }

    if (mandatoryKeys) {
        // Filter by the mandatory keys first
        CFIndex count = CFSetGetCount(mandatoryKeys);
        std::vector<CFStringRef> keys(count);
        CFSetGetValues(mandatoryKeys, (const void**)keys.data());
        for (auto& key : keys) {
            if (!CFDictionaryContainsKey(attributes, key)) {
                // Mandatory key does not exist, so no fonts can match
                return S_OK;
            }

            RETURN_IF_FAILED(__FilterFontsByKeyAndValue(fonts, key, CFDictionaryGetValue(attributes, key), true));
            if (fonts.empty()) {
                // No fonts that match mandatory keys, can stop filtering now
                return S_OK;
            }
        }
    }

    // Left with list of fonts matching mandatoryKeys, can now try to match any non-mandatory attributes
    CFIndex count = CFDictionaryGetCount(attributes);
    if (count > 0L) {
        std::vector<CFStringRef> keys(count);
        std::vector<CFTypeRef> values(count);
        CFDictionaryGetKeysAndValues(attributes, (const void**)keys.data(), (const void**)values.data());
        for (size_t i = 0; i < count; ++i) {
            if (!mandatoryKeys || !CFSetContainsValue(mandatoryKeys, keys[i])) {
                RETURN_IF_FAILED(__FilterFontsByKeyAndValue(fonts, keys[i], values[i], false));
            }
        }
    }

    auto outArray = woc::MakeAutoCF<CFMutableArrayRef>(CFArrayCreateMutable(nullptr, fonts.size(), &kCFTypeArrayCallBacks));
    for (size_t i = 0; i < fonts.size(); ++i) {
        BOOL exists;
        ComPtr<IDWriteLocalizedStrings> dwriteString;
        RETURN_IF_FAILED(fonts[i]->GetInformationalStrings(DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_NAME, &dwriteString, &exists));
        CFStringRef name = _CFStringFromLocalizedString(dwriteString.Get());
        auto descriptor = woc::MakeAutoCF<CTFontDescriptorRef>(CTFontDescriptorCreateWithNameAndSize(name, kCTFontSystemFontSize));
        CFArrayAppendValue(outArray, descriptor);
    }

    *matchingNames = outArray.detach();
    return S_OK;
}

/**
 * Helper function that reads certain properties from a DWrite font face,
 * then parses them into a dictionary suitable for kCTFontTraitsAttribute
 */
static CFDictionaryRef _DWriteFontCreateTraitsDict(const ComPtr<IDWriteFontFace>& fontFace) {
    // Get pointers for the additional FontFace interfaces
    ComPtr<IDWriteFontFace1> fontFace1;
    RETURN_NULL_IF_FAILED(fontFace.As(&fontFace1));
    ComPtr<IDWriteFontFace3> fontFace3;
    RETURN_NULL_IF_FAILED(fontFace.As(&fontFace3));

    DWRITE_FONT_WEIGHT weight = fontFace3->GetWeight();
    DWRITE_FONT_STRETCH stretch = fontFace3->GetStretch();
    DWRITE_FONT_STYLE style = fontFace3->GetStyle();

    CGFloat weightTrait = __DWriteFontWeightToCT(weight);
    CGFloat widthTrait = __DWriteFontStretchToCT(stretch);

    // kCTFontSlantTrait appears scaled to be 1.0 = 180 degrees, rather than = 30 degrees as documentation claims
    CGFloat slantTrait = _DWriteFontGetSlantDegrees(fontFace) / -180.0f; // kCTFontSlantTrait is positive for negative angles

    // symbolic traits are a bit mask - evaluate the trueness of each flag
    CTFontSymbolicTraits symbolicTraits = 0;

    if (style != DWRITE_FONT_STYLE_NORMAL) {
        symbolicTraits |= kCTFontItalicTrait;
    }

    if (weight > DWRITE_FONT_WEIGHT_MEDIUM) {
        symbolicTraits |= kCTFontBoldTrait;
    }

    if (stretch > DWRITE_FONT_STRETCH_MEDIUM) {
        symbolicTraits |= kCTFontExpandedTrait;
    } else if (stretch < DWRITE_FONT_STRETCH_NORMAL) {
        symbolicTraits |= kCTFontCondensedTrait;
    }

    if (fontFace1->IsMonospacedFont()) {
        symbolicTraits |= kCTFontMonoSpaceTrait;
    }

    if (fontFace1->HasVerticalGlyphVariants()) {
        symbolicTraits |= kCTFontVerticalTrait;
    }

    if (fontFace3->IsColorFont()) {
        symbolicTraits |= kCTFontColorGlyphsTrait;
    }

    // TODO: The symbolic traits below are poorly documented/have no clear DWrite mapping
    // kCTFontUIOptimizedTrait
    // kCTFontCompositeTrait

    // TODO: The upper 16 bits of symbolic traits describe stylistic aspects of a font, specifically its serifs,
    // such as modern, ornamental, or sans (no serifs)
    // DWrite has no such API for characterizing fonts

    // Keys and values for the final trait dictionary
    CFTypeRef traitKeys[] = { kCTFontSymbolicTrait, kCTFontWeightTrait, kCTFontWidthTrait, kCTFontSlantTrait };
    CFTypeRef traitValues[] = { CFAutorelease(_CFNumberCreateFromSymbolicTraits(symbolicTraits)),
                                CFAutorelease(CFNumberCreate(kCFAllocatorDefault, kCFNumberCGFloatType, &weightTrait)),
                                CFAutorelease(CFNumberCreate(kCFAllocatorDefault, kCFNumberCGFloatType, &widthTrait)),
                                CFAutorelease(CFNumberCreate(kCFAllocatorDefault, kCFNumberCGFloatType, &slantTrait)) };

    return CFDictionaryCreate(kCFAllocatorDefault,
                              traitKeys,
                              traitValues,
                              4,
                              &kCFTypeDictionaryKeyCallBacks,
                              &kCFTypeDictionaryValueCallBacks);
}

/**
 * Gets a name/informational string from a DWrite font face corresponding to a CTFont constant
 */
CFStringRef _DWriteFontCopyName(const ComPtr<IDWriteFontFace>& fontFace, CFStringRef nameKey, CFStringRef* actualLanguage) {
    if (nameKey == nullptr || fontFace == nullptr) {
        return nullptr;
    }

    DWRITE_INFORMATIONAL_STRING_ID informationalStringId;

    if (CFEqual(nameKey, kCTFontCopyrightNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_COPYRIGHT_NOTICE;
    } else if (CFEqual(nameKey, kCTFontFamilyNameKey)) {
        // Instead of using DWRITE_INFORMATIONAL_STRING_WIN32_FAMILY_NAMES here, use GetFamilyNames(),
        // WIN32_FAMILY_NAMES may return a more specific name than needed (ie: Arial Narrow instead of Arial)
        // As it is limited by GDI allowing a maximum of four fonts per family
        ComPtr<IDWriteFontFace3> dwriteFontFace3;
        RETURN_NULL_IF_FAILED(fontFace.As(&dwriteFontFace3));
        ComPtr<IDWriteLocalizedStrings> name;
        RETURN_NULL_IF_FAILED(dwriteFontFace3->GetFamilyNames(&name));
        return static_cast<CFStringRef>(CFRetain(_CFStringFromLocalizedString(name.Get(), actualLanguage)));

    } else if (CFEqual(nameKey, kCTFontSubFamilyNameKey)) {
        // Similar to above, WIN32_SUBFAMILY_NAMES is limited to four fonts per family,
        // but PREFERRED_SUBFAMILY_NAMES is only sometimes present (if it differs from WIN32_SUBFAMILY_NAMES)
        // Try PREFERRED first
        CFStringRef ret =
            _DWriteFontCopyInformationalString(fontFace, DWRITE_INFORMATIONAL_STRING_PREFERRED_SUBFAMILY_NAMES, actualLanguage);
        if (ret) {
            return ret;
        }

        informationalStringId = DWRITE_INFORMATIONAL_STRING_WIN32_SUBFAMILY_NAMES;

    } else if (CFEqual(nameKey, kCTFontStyleNameKey)) {
        ComPtr<IDWriteFontFace3> dwriteFontFace3;
        RETURN_NULL_IF_FAILED(fontFace.As(&dwriteFontFace3));
        ComPtr<IDWriteLocalizedStrings> name;
        RETURN_NULL_IF_FAILED(dwriteFontFace3->GetFaceNames(&name));
        return static_cast<CFStringRef>(CFRetain(_CFStringFromLocalizedString(name.Get(), actualLanguage)));

    } else if (CFEqual(nameKey, kCTFontUniqueNameKey)) {
        return CFStringCreateWithFormat(kCFAllocatorDefault,
                                        nullptr,
                                        CFSTR("%@ %@"),
                                        // Only want to assign to actualLanguage once
                                        CFAutorelease(_DWriteFontCopyName(fontFace, kCTFontFullNameKey)),
                                        CFAutorelease(_DWriteFontCopyName(fontFace, kCTFontStyleNameKey, actualLanguage)));

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

    return _DWriteFontCopyInformationalString(fontFace, informationalStringId, actualLanguage);
}

static constexpr CTFontTableTag sc_tags[] = { kCTFontTableBASE, kCTFontTableCFF,  kCTFontTableDSIG, kCTFontTableEBDT, kCTFontTableEBLC,
                                              kCTFontTableEBSC, kCTFontTableGDEF, kCTFontTableGPOS, kCTFontTableGSUB, kCTFontTableJSTF,
                                              kCTFontTableLTSH, kCTFontTableOS2,  kCTFontTablePCLT, kCTFontTableVDMX, kCTFontTableVORG,
                                              kCTFontTableZapf, kCTFontTableAcnt, kCTFontTableAvar, kCTFontTableBdat, kCTFontTableBhed,
                                              kCTFontTableBloc, kCTFontTableBsln, kCTFontTableCmap, kCTFontTableCvar, kCTFontTableCvt,
                                              kCTFontTableFdsc, kCTFontTableFeat, kCTFontTableFmtx, kCTFontTableFpgm, kCTFontTableFvar,
                                              kCTFontTableGasp, kCTFontTableGlyf, kCTFontTableGvar, kCTFontTableHdmx, kCTFontTableHead,
                                              kCTFontTableHhea, kCTFontTableHmtx, kCTFontTableHsty, kCTFontTableJust, kCTFontTableKern,
                                              kCTFontTableKerx, kCTFontTableLcar, kCTFontTableLoca, kCTFontTableMaxp, kCTFontTableMort,
                                              kCTFontTableMorx, kCTFontTableName, kCTFontTableOpbd, kCTFontTablePost, kCTFontTablePrep,
                                              kCTFontTableProp, kCTFontTableSbit, kCTFontTableSbix, kCTFontTableTrak, kCTFontTableVhea,
                                              kCTFontTableVmtx };

CFArrayRef _DWriteCopyAvailableFontTables(const ComPtr<IDWriteFontFace>& fontFace) {
    auto ret = woc::MakeAutoCF<CFMutableArrayRef>(CFArrayCreateMutable(nullptr, 0, nullptr));
    for (CTFontTableTag tag : sc_tags) {
        const void* tableData;
        uint32_t tableSize;
        void* tableContext;
        BOOL exists;

        RETURN_NULL_IF_FAILED(fontFace->TryGetFontTable(_CTToDWriteFontTableTag(tag), &tableData, &tableSize, &tableContext, &exists));
        if (exists) {
            // Returned array is expected to have unboxed CTFontTableTag values
            CFArrayAppendValue(ret, (const void*)tag);
        }

        // As part of the contact for TryGetFontTable, tableContext must always be released via ReleaseFontTable
        if (tableContext) {
            fontFace->ReleaseFontTable(tableContext);
        }
    }

    return ret.detach();
}