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

// #1207: Do not move this block, it has to come first for some reason
#include <COMIncludes.h>
#import <wrl/implements.h>
#include <COMIncludes_End.h>

#import <CoreGraphics/DWriteWrapper.h>
#import <Starboard.h>

#import <vector>

using namespace std;
using namespace Microsoft::WRL;

static const wchar_t* TAG = L"_DWriteWrapper";
static const wchar_t* c_defaultUserLanguage = L"en-us";

/**
 * Private helper method to return the user set default locale string.
 *
 * @return use set locale string as wstring.
 */
static wstring __GetUserDefaultLocaleName() {
    wchar_t localeName[LOCALE_NAME_MAX_LENGTH];
    int defaultLocaleSuccess = GetUserDefaultLocaleName(localeName, LOCALE_NAME_MAX_LENGTH);

    // If the default locale is returned, find that locale name, otherwise use "en-us".
    return wstring(defaultLocaleSuccess ? localeName : c_defaultUserLanguage);
}

/**
 * Helper method to convert IDWriteLocalizedStrings object to CFString object.
 *
 * @parameter localizedString IDWriteLocalizedStrings object to convert.
 *
 * @return CFString object.
 */
CFStringRef _CFStringFromLocalizedString(IDWriteLocalizedStrings* localizedString) {
    if (localizedString == NULL) {
        TraceError(TAG, L"The input parameter is invalid!");
        return nil;
    }

    // Get the default locale for this user.
    wstring localeName = __GetUserDefaultLocaleName();

    uint32_t index = 0;
    BOOL exists = false;

    // If the default locale is returned, find that locale name, otherwise use "en-us".
    RETURN_NULL_IF_FAILED(localizedString->FindLocaleName(localeName.c_str(), &index, &exists));
    if (!exists) {
        RETURN_NULL_IF_FAILED(localizedString->FindLocaleName(c_defaultUserLanguage, &index, &exists));
    }

    // If the specified locale doesn't exist, select the first on the list.
    if (!exists) {
        index = 0;
    }

    // Get the string length.
    uint32_t length = 0;
    RETURN_NULL_IF_FAILED(localizedString->GetStringLength(index, &length));

    // Get the string.
    vector<wchar_t> wcharString = std::vector<wchar_t>(length + 1, 0);
    RETURN_NULL_IF_FAILED(localizedString->GetString(index, wcharString.data(), length + 1));

    // Strip out unnecessary null terminator
    return (CFStringRef)CFAutorelease(
        CFStringCreateWithCharacters(kCFAllocatorSystemDefault, reinterpret_cast<UniChar*>(wcharString.data()), length));
}

/**
 * Helper method to retrieve font family names installed in the system.
 *
 * @return Immutable array of font family name strings that are installed in the system.
 */
CFArrayRef _DWriteCopyFontFamilyNames() {
    woc::unique_cf<CFMutableArrayRef> fontFamilyNames(CFArrayCreateMutable(kCFAllocatorSystemDefault, 0, &kCFTypeArrayCallBacks));

    // Get the direct write factory instance
    ComPtr<IDWriteFactory> dwriteFactory;
    RETURN_NULL_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));

    // Get the system font collection.
    ComPtr<IDWriteFontCollection> fontCollection;
    RETURN_NULL_IF_FAILED(dwriteFactory->GetSystemFontCollection(&fontCollection));

    // Get the number of font families in the collection.
    uint32_t count = 0;
    count = fontCollection->GetFontFamilyCount();

    for (uint32_t i = 0; i < count; ++i) {
        // Get the font family.
        ComPtr<IDWriteFontFamily> fontFamily;
        RETURN_NULL_IF_FAILED(fontCollection->GetFontFamily(i, &fontFamily));

        // Get a list of localized strings for the family name.
        ComPtr<IDWriteLocalizedStrings> familyNames;
        RETURN_NULL_IF_FAILED(fontFamily->GetFamilyNames(&familyNames));

        CFStringRef name = _CFStringFromLocalizedString(familyNames.Get());
        if (CFStringGetLength(name) == 0) {
            TraceError(TAG, L"Failed to convert the localized string to wide string.");
            continue;
        }

        CFArrayAppendValue(fontFamilyNames.get(), name);
    }

    return fontFamilyNames.release();
}

/**
 * Helper method to retrieve names of individual fonts under a font family.
 */
CFArrayRef _DWriteCopyFontNamesForFamilyName(CFStringRef familyName) {
    woc::unique_cf<CFMutableArrayRef> fontNames(CFArrayCreateMutable(kCFAllocatorSystemDefault, 0, &kCFTypeArrayCallBacks));

    ComPtr<IDWriteFactory> dwriteFactory;
    RETURN_NULL_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));

    // Get the system font collection.
    ComPtr<IDWriteFontCollection> fontCollection;
    RETURN_NULL_IF_FAILED(dwriteFactory->GetSystemFontCollection(&fontCollection));

    // Get the font family.
    CFIndex familyNameLength = CFStringGetLength(familyName);
    std::vector<UniChar> unicharFamilyName(familyNameLength + 1);
    CFStringGetCharacters(familyName, CFRangeMake(0, familyNameLength), unicharFamilyName.data());

    size_t index = 0;
    BOOL exists = false;

    RETURN_NULL_IF_FAILED(fontCollection->FindFamilyName(reinterpret_cast<wchar_t*>(unicharFamilyName.data()), &index, &exists));
    if (!exists) {
        TraceError(TAG, L"Failed to find the font family name.");
        return fontNames.release();
    }

    ComPtr<IDWriteFontFamily> fontFamily;
    RETURN_NULL_IF_FAILED(fontCollection->GetFontFamily(index, &fontFamily));

    ComPtr<IDWriteFontList> fontList;
    RETURN_NULL_IF_FAILED(
        fontFamily->GetMatchingFonts(DWRITE_FONT_WEIGHT_THIN, DWRITE_FONT_STRETCH_UNDEFINED, DWRITE_FONT_STYLE_NORMAL, &fontList));

    size_t count = fontList->GetFontCount();

    for (size_t i = 0; i < count; i++) {
        ComPtr<IDWriteFont> font;
        RETURN_NULL_IF_FAILED(fontList->GetFont(i, &font));

        ComPtr<IDWriteLocalizedStrings> fullName;
        BOOL exist = FALSE;
        RETURN_NULL_IF_FAILED(font->GetInformationalStrings(DWRITE_INFORMATIONAL_STRING_FULL_NAME, &fullName, &exist));

        if (exist) {
            CFStringRef name = _CFStringFromLocalizedString(fullName.Get());
            if (CFStringGetLength(name) == 0) {
                TraceError(TAG, L"Failed to convert the localized string to wide string.");
                continue;
            }

            CFArrayAppendValue(fontNames.get(), name);
        }
    }

    return fontNames.release();
}

/**
 * Helper method that maps a font name to the name of its family.
 *
 * Note: This function currently uses a cache, meaning that fonts installed during runtime will not be reflected
 */
CFStringRef _DWriteGetFamilyNameForFontName(CFStringRef fontName) {
    static CFDictionaryRef fontToFamilyMap = []() {
        woc::unique_cf<CFLocaleRef> locale(CFLocaleCopyCurrent());

        // initialize fontToFamilyMap
        woc::unique_cf<CFMutableDictionaryRef> initMap(
            CFDictionaryCreateMutable(kCFAllocatorSystemDefault, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks));

        woc::unique_cf<CFArrayRef> familyNames(_DWriteCopyFontFamilyNames());

        for (size_t i = 0; i < CFArrayGetCount(familyNames.get()); ++i) {
            CFStringRef familyName = static_cast<CFStringRef>(CFArrayGetValueAtIndex(familyNames.get(), i));
            woc::unique_cf<CFArrayRef> fontNames(_DWriteCopyFontNamesForFamilyName(familyName));

            for (size_t j = 0; j < CFArrayGetCount(fontNames.get()); j++) {
                CFStringRef systemFontName = static_cast<CFStringRef>(CFArrayGetValueAtIndex(fontNames.get(), j));
                woc::unique_cf<CFMutableStringRef> upperSystemFontName(
                    CFStringCreateMutableCopy(nullptr, CFStringGetLength(systemFontName), systemFontName));
                CFStringUppercase(upperSystemFontName.get(), locale.get());
                CFDictionaryAddValue(initMap.get(), upperSystemFontName.get(), familyName);
            }
        }

        return CFDictionaryCreateCopy(kCFAllocatorSystemDefault, initMap.get());
    }();

    woc::unique_cf<CFLocaleRef> locale(CFLocaleCopyCurrent());

    woc::unique_cf<CFMutableStringRef> upperFontName(CFStringCreateMutableCopy(nullptr, CFStringGetLength(fontName), fontName));
    CFStringUppercase(upperFontName.get(), locale.get());
    return static_cast<CFStringRef>(CFDictionaryGetValue(fontToFamilyMap, upperFontName.get()));
}

// Represents a mapping between multiple representations of the same font weight across font names, DWrite, and CoreText
// eg: CFSTR("BOLD") = DWRITE_FONT_WEIGHT_BOLD = kCTFontWeightBold
struct WeightMapping {
    CFStringRef stringValue;
    DWRITE_FONT_WEIGHT dwriteValue;
};

// Mapping for weight
// Some loss of precision here as CT presents fewer values than DWrite
// Note also that Thin and Ultra/Extra-Light are in opposite order in DWrite and CoreText/UIKit constants
// (However, "Thin" fonts on the reference platform have UIFontWeightUltraLight...)
static const struct WeightMapping c_weightMap[] = { { CFSTR("THIN"), DWRITE_FONT_WEIGHT_THIN },
                                                    { CFSTR("EXTRALIGHT"), DWRITE_FONT_WEIGHT_EXTRA_LIGHT },
                                                    { CFSTR("ULTRALIGHT"), DWRITE_FONT_WEIGHT_ULTRA_LIGHT },
                                                    { CFSTR("LIGHT"), DWRITE_FONT_WEIGHT_LIGHT },
                                                    { CFSTR("SEMILIGHT"), DWRITE_FONT_WEIGHT_SEMI_LIGHT },
                                                    { CFSTR("NORMAL"), DWRITE_FONT_WEIGHT_NORMAL },
                                                    { CFSTR("REGULAR"), DWRITE_FONT_WEIGHT_REGULAR },
                                                    { CFSTR("MEDIUM"), DWRITE_FONT_WEIGHT_REGULAR },
                                                    { CFSTR("DEMIBOLD"), DWRITE_FONT_WEIGHT_DEMI_BOLD },
                                                    { CFSTR("DEMI"), DWRITE_FONT_WEIGHT_DEMI_BOLD },
                                                    { CFSTR("SEMIBOLD"), DWRITE_FONT_WEIGHT_SEMI_BOLD },
                                                    { CFSTR("BOLD"), DWRITE_FONT_WEIGHT_BOLD },
                                                    { CFSTR("EXTRABOLD"), DWRITE_FONT_WEIGHT_EXTRA_BOLD },
                                                    { CFSTR("ULTRABOLD"), DWRITE_FONT_WEIGHT_ULTRA_BOLD },
                                                    { CFSTR("BLACK"), DWRITE_FONT_WEIGHT_BLACK },
                                                    { CFSTR("HEAVY"), DWRITE_FONT_WEIGHT_HEAVY },
                                                    { CFSTR("EXTRABLACK"), DWRITE_FONT_WEIGHT_EXTRA_BLACK },
                                                    { CFSTR("ULTRABLACK"), DWRITE_FONT_WEIGHT_ULTRA_BLACK } };

/**
 * Helper that parses a font name, and returns appropriate weight, stretch, style, and family name values
 */
_DWriteFontProperties _DWriteGetFontPropertiesFromName(CFStringRef fontName) {
    // Set some defaults for when weight/stretch/style are not mentioned in the name
    _DWriteFontProperties ret{ DWRITE_FONT_WEIGHT_NORMAL,
                               DWRITE_FONT_STRETCH_NORMAL,
                               DWRITE_FONT_STYLE_NORMAL,
                               _DWriteGetFamilyNameForFontName(fontName) };

    // Relationship of family name -> font name not always consistent
    // Usually, properties are added to the end (eg: Arial -> Arial Narrow Bold)
    // However, this is not always the case (eg: Eras ITC -> Eras Bold ITC)
    // In addition, some fonts with properties are occasionally placed into their own family (eg: Segoe WP SemiLight -> Segoe WP SemiLight)
    // Try to be more prudent about these edge cases, by looking only at the difference between the font name and family name
    woc::unique_cf<CFArrayRef> fontNameTokens(CFStringCreateArrayBySeparatingStrings(kCFAllocatorDefault, fontName, CFSTR(" ")));
    woc::unique_cf<CFMutableSetRef> propertyTokens(CFSetCreateMutable(kCFAllocatorDefault, 0, &kCFTypeSetCallBacks));

    for (size_t i = 0; i < CFArrayGetCount(fontNameTokens.get()); ++i) {
        CFSetAddValue(propertyTokens.get(), CFArrayGetValueAtIndex(fontNameTokens.get(), i));
    }

    if (ret.familyName) {
        woc::unique_cf<CFArrayRef> familyNameTokens(
            CFStringCreateArrayBySeparatingStrings(kCFAllocatorDefault, ret.familyName, CFSTR(" ")));
        for (size_t i = 0; i < CFArrayGetCount(familyNameTokens.get()); ++i) {
            CFSetRemoveValue(propertyTokens.get(), CFArrayGetValueAtIndex(familyNameTokens.get(), i));
        }
    }

    CFSetApplierFunction initPropertyFromToken = [](const void* value, void* context) {
        CFMutableStringRef propertyToken = CFStringCreateMutableCopy(kCFAllocatorDefault, 0, static_cast<CFStringRef>(value));
        _DWriteFontProperties* properties = reinterpret_cast<_DWriteFontProperties*>(context);

        // Font names are not always consistent about capitalization (SemiLight vs Semilight)
        // Standardize on uppercase
        CFStringUppercase(propertyToken, CFLocaleGetSystem());

        // Possible optimization here that can be done by using a dictionary,
        // but seems excessive given that font names generally don't have more than three modifiers
        for (const auto& weightMapping : c_weightMap) {
            if (CFEqual(propertyToken, weightMapping.stringValue)) {
                properties->weight = weightMapping.dwriteValue;
                break;
            }
        }

        if (CFEqual(propertyToken, CFSTR("UNDEFINED"))) {
            properties->stretch = DWRITE_FONT_STRETCH_UNDEFINED;
        } else if (CFEqual(propertyToken, CFSTR("ULTRACONDENSED"))) {
            properties->stretch = DWRITE_FONT_STRETCH_ULTRA_CONDENSED;
        } else if (CFEqual(propertyToken, CFSTR("EXTRACONDENSED"))) {
            properties->stretch = DWRITE_FONT_STRETCH_EXTRA_CONDENSED;
        } else if (CFEqual(propertyToken, CFSTR("CONDENSED")) || CFEqual(propertyToken, CFSTR("NARROW")) ||
                   CFEqual(propertyToken, CFSTR("COND"))) {
            properties->stretch = DWRITE_FONT_STRETCH_CONDENSED;
        } else if (CFEqual(propertyToken, CFSTR("SEMICONDENSED"))) {
            properties->stretch = DWRITE_FONT_STRETCH_SEMI_CONDENSED;
            // skip since this is the default
            // } else if (CFEqual(propertyToken, CFSTR("NORMAL"))) {
            //     properties->stretch = DWRITE_FONT_STRETCH_NORMAL;

        } else if (CFEqual(propertyToken, CFSTR("SEMIEXPANDED"))) {
            properties->stretch = DWRITE_FONT_STRETCH_SEMI_EXPANDED;
        } else if (CFEqual(propertyToken, CFSTR("EXPANDED"))) {
            properties->stretch = DWRITE_FONT_STRETCH_EXPANDED;
        } else if (CFEqual(propertyToken, CFSTR("EXTRAEXPANDED"))) {
            properties->stretch = DWRITE_FONT_STRETCH_EXTRA_EXPANDED;
        } else if (CFEqual(propertyToken, CFSTR("ULTRAEXPANDED"))) {
            properties->stretch = DWRITE_FONT_STRETCH_ULTRA_EXPANDED;

            // skip since this is the default
            // } else if (CFEqual(propertyToken, CFSTR("NORMAL"))) {
            //     properties->style = DWRITE_FONT_STYLE_NORMAL;
        } else if (CFEqual(propertyToken, CFSTR("OBLIQUE"))) {
            properties->style = DWRITE_FONT_STYLE_OBLIQUE;
        } else if (CFEqual(propertyToken, CFSTR("ITALIC"))) {
            properties->style = DWRITE_FONT_STYLE_ITALIC;
        }
    };

    CFSetApplyFunction(propertyTokens.get(), initPropertyFromToken, &ret);
    return ret;
}

/**
 * Creates a DWrite text format object using the system font collection
 */
HRESULT _DWriteCreateTextFormat(const wchar_t* fontFamilyName,
                                DWRITE_FONT_WEIGHT weight,
                                DWRITE_FONT_STYLE style,
                                DWRITE_FONT_STRETCH stretch,
                                float fontSize,
                                IDWriteTextFormat** outTextFormat) {
    // Get the direct write factory instance
    ComPtr<IDWriteFactory> dwriteFactory;
    RETURN_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));

    return dwriteFactory->CreateTextFormat(fontFamilyName,
                                           nullptr,
                                           weight,
                                           style,
                                           stretch,
                                           fontSize,
                                           __GetUserDefaultLocaleName().data(),
                                           outTextFormat); //
}

/**
 * Helper that creates a IDWriteFontFamily object for a given family name
 */
HRESULT _DWriteCreateFontFamilyWithName(CFStringRef familyName, IDWriteFontFamily** outFontFamily) {
    ComPtr<IDWriteFactory> dwriteFactory;
    RETURN_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));

    ComPtr<IDWriteFontCollection> systemFontCollection;
    RETURN_IF_FAILED(dwriteFactory->GetSystemFontCollection(&systemFontCollection));

    CFIndex familyNameLength = CFStringGetLength(familyName);
    std::vector<UniChar> unicharFamilyName(familyNameLength + 1);
    CFStringGetCharacters(familyName, CFRangeMake(0, familyNameLength), unicharFamilyName.data());

    size_t fontFamilyIndex;
    BOOL fontFamilyExists;

    RETURN_IF_FAILED(systemFontCollection->FindFamilyName(reinterpret_cast<const wchar_t*>(unicharFamilyName.data()),
                                                          &fontFamilyIndex,
                                                          &fontFamilyExists));

    RETURN_HR_IF(E_INVALIDARG, !fontFamilyExists);

    return systemFontCollection->GetFontFamily(fontFamilyIndex, outFontFamily);
}

/**
 * Helper function that creates an IDWriteFontFace object for a given font name.
 */
HRESULT _DWriteCreateFontFaceWithName(CFStringRef name, IDWriteFontFace** outFontFace) {
    // Parse the font name for font weight, stretch, and style
    // Eg: Bold, Condensed, Light, Italic
    _DWriteFontProperties properties = _DWriteGetFontPropertiesFromName(name);

    // TODO: #1250: Need to be able to load fonts from the app's bundle
    // For now return a default font to avoid crashes in case of missing fonts
    // When #1250 is completed, remove this
    if (!properties.familyName) {
        name = CFSTR("Segoe UI");
        properties = _DWriteGetFontPropertiesFromName(name);
    }

    RETURN_HR_IF_NULL(E_INVALIDARG, properties.familyName);

    ComPtr<IDWriteFontFamily> fontFamily;
    RETURN_IF_FAILED(_DWriteCreateFontFamilyWithName(properties.familyName, &fontFamily));
    RETURN_HR_IF_NULL(E_INVALIDARG, fontFamily);

    ComPtr<IDWriteFont> font;
    RETURN_IF_FAILED(fontFamily->GetFirstMatchingFont(properties.weight, properties.stretch, properties.style, &font));

    return font->CreateFontFace(outFontFace);
}

/**
 * Gets an informational string as a CFString from a DWrite font face.
 */
CFStringRef _DWriteFontCopyInformationalString(const ComPtr<IDWriteFontFace>& fontFace,
                                               DWRITE_INFORMATIONAL_STRING_ID informationalStringId) {
    RETURN_NULL_IF(!fontFace);

    ComPtr<IDWriteFontFace3> dwriteFontFace3;
    RETURN_NULL_IF_FAILED(fontFace.As(&dwriteFontFace3));

    ComPtr<IDWriteLocalizedStrings> name;
    BOOL exists;

    RETURN_NULL_IF_FAILED(dwriteFontFace3->GetInformationalStrings(informationalStringId, &name, &exists));
    return exists ? static_cast<CFStringRef>(CFRetain(_CFStringFromLocalizedString(name.Get()))) : nullptr;
}

/**
 * Gets a font table as a CFDataRef from a DWrite font face
 */
CFDataRef _DWriteFontCopyTable(const ComPtr<IDWriteFontFace>& fontFace, uint32_t tag) {
    const void* tableData;
    uint32_t tableSize;
    void* tableContext;
    BOOL exists;

    RETURN_NULL_IF_FAILED(fontFace->TryGetFontTable(tag, &tableData, &tableSize, &tableContext, &exists));
    RETURN_NULL_IF(!exists);

    // Copy the font table's binary data to a CFDataRef
    woc::unique_cf<CFDataRef> ret(CFDataCreate(kCFAllocatorDefault, reinterpret_cast<const byte*>(tableData), tableSize));

    // As part of the contact for TryGetFontTable, tableContext must always be released via ReleaseFontTable
    if (tableContext) {
        fontFace->ReleaseFontTable(tableContext);
    }

    return ret.release();
}

/**
 * Helper function that gets the slant angle, in degrees, from a DWrite font face.
 */
CGFloat _DWriteFontGetSlantDegrees(const ComPtr<IDWriteFontFace>& fontFace) {
    ComPtr<IDWriteFontFace1> fontFace1;
    if (FAILED(fontFace.As(&fontFace1))) {
        return 0;
    }

    DWRITE_CARET_METRICS caretMetrics;
    fontFace1->GetCaretMetrics(&caretMetrics);
    if (caretMetrics.slopeRun && caretMetrics.slopeRise) {
        CGFloat riseOverRun = static_cast<CGFloat>(caretMetrics.slopeRise) / static_cast<CGFloat>(caretMetrics.slopeRun);
        return (atan(riseOverRun) * 180 / M_PI) - 90.0f; // Degrees returned by this function must be negative
    } else {
        // Avoid dividing by 0, skip math for dividing with 0
        return -0.0f;
    }
}

/**
 * Gets the accumulated bounding box of all the glyphs in a DWrite font face, as a CGRect
 * Returns in terms of design units
 */
CGRect _DWriteFontGetBoundingBox(const ComPtr<IDWriteFontFace>& fontFace) {
    ComPtr<IDWriteFontFace1> fontFace1;
    if (FAILED(fontFace.As(&fontFace1))) {
        return {};
    }

    DWRITE_FONT_METRICS1 fontMetrics;
    fontFace1->GetMetrics(&fontMetrics);

    // Convert from DWrite font metrics, which is in terms of top, left, right, and bottom,
    // to CGRect, which is in terms of origin and size.
    CGRect ret;
    ret.origin.x = fontMetrics.glyphBoxLeft;
    ret.origin.y = fontMetrics.glyphBoxBottom;
    ret.size.width = fontMetrics.glyphBoxRight - fontMetrics.glyphBoxLeft;
    ret.size.height = fontMetrics.glyphBoxTop - fontMetrics.glyphBoxBottom;

    return ret;
}

/**
 * Gets individual bounding boxes for specific glyphs in a DWrite font face, as a CGRect
 * Returns in terms of design units
 */
HRESULT _DWriteFontGetBoundingBoxesForGlyphs(
    const ComPtr<IDWriteFontFace>& fontFace, const CGGlyph* glyphs, CGRect* boundingRects, size_t count, bool isSideways) {
    std::vector<DWRITE_GLYPH_METRICS> glyphMetrics(count);

    HRESULT ret = fontFace->GetDesignGlyphMetrics(glyphs, count, glyphMetrics.data(), isSideways);
    RETURN_IF_FAILED(ret);

    // Convert from DWRITE_GLYPH_METRICS to CGRect
    std::transform(glyphMetrics.begin(), glyphMetrics.end(), boundingRects, [](DWRITE_GLYPH_METRICS metrics) {
        CGRect rect;
        rect.origin.x = metrics.leftSideBearing;

        // generally cast the unsigned advance width/height to signed to avoid underflow issues
        rect.origin.y = metrics.verticalOriginY - static_cast<int32_t>(metrics.advanceHeight) + metrics.bottomSideBearing;
        rect.size.width = static_cast<int32_t>(metrics.advanceWidth) - (metrics.leftSideBearing + metrics.rightSideBearing);
        rect.size.height = static_cast<int32_t>(metrics.advanceHeight) - (metrics.bottomSideBearing + metrics.topSideBearing);

        return rect;
    });

    return ret;
}