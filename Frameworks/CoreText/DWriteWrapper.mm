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

// Do not move this block, it has to come first for some reason
#include <COMIncludes.h>
#import <wrl/implements.h>
#include <COMIncludes_End.h>

#import <CoreText/DWriteWrapper.h>
#import <Starboard.h>

#import <CoreFoundation/CFBase.h>
#import "CoreTextInternal.h"

#import <LoggingNative.h>
#import <mutex>
#import <vector>

using namespace std;
using namespace Microsoft::WRL;

static const wchar_t* TAG = L"_DWriteWrapper";
static const wchar_t* c_defaultUserLanguage = L"en-us";
static const wchar_t* c_defaultFontName = L"Gabriola";

// TODO::
// These should be removed once CTFont and UIFont are bridged.
static IWLazyClassLookup s_lazyUIFont("UIFont");
static const float c_defaultSystemFontSize = 15.0f;

// Private helper for creating a DWriteFactory
static ComPtr<IDWriteFactory> __CreateDWriteFactoryInstance() {
    ComPtr<IDWriteFactory> dwriteFactory;
    THROW_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));
    return dwriteFactory;
}

// Private helper for accessing a single static DWriteFactory instance
static ComPtr<IDWriteFactory> __GetDWriteFactoryInstance() {
    static ComPtr<IDWriteFactory> s_dwriteFactory = __CreateDWriteFactoryInstance();
    return s_dwriteFactory;
}

/**
 * Helper method to return the user set default locale string.
 *
 * @return use set locale string as wstring.
 */
static wstring __GetUserDefaultLocaleName() {
    wchar_t localeName[LOCALE_NAME_MAX_LENGTH];
    int defaultLocaleSuccess = GetUserDefaultLocaleName(localeName, LOCALE_NAME_MAX_LENGTH);

    // If the default locale is returned, find that locale name, otherwise use "en-us".
    if (defaultLocaleSuccess) {
        return wstring(localeName);
    } else {
        return wstring(c_defaultUserLanguage);
    }
}

/**
 * Helper method to convert IDWriteLocalizedStrings object to NSString object.
 *
 * @parameter localizedString IDWriteLocalizedStrings object to convert.
 *
 * @return NSString object.
 */
static NSString* _ConvertLocalizedStringToNSString(IDWriteLocalizedStrings* localizedString) {
    if (localizedString == NULL) {
        TraceError(TAG, L"The input parameter is invalid!");
        return nil;
    }

    // Get the default locale for this user.
    wstring localeName = __GetUserDefaultLocaleName();

    uint32_t index = 0;
    BOOL exists = false;

    // If the default locale is returned, find that locale name, otherwise use "en-us".
    THROW_IF_FAILED(localizedString->FindLocaleName(localeName.c_str(), &index, &exists));
    if (!exists) {
        THROW_IF_FAILED(localizedString->FindLocaleName(c_defaultUserLanguage, &index, &exists));
    }

    // If the specified locale doesn't exist, select the first on the list.
    if (!exists) {
        index = 0;
    }

    // Get the string length.
    uint32_t length = 0;
    THROW_IF_FAILED(localizedString->GetStringLength(index, &length));

    // Get the string.
    vector<wchar_t> wcharString = std::vector<wchar_t>(length + 1);
    THROW_IF_FAILED(localizedString->GetString(index, wcharString.data(), length + 1));

    return [NSString stringWithCharacters:reinterpret_cast<UniChar*>(wcharString.data()) length:length];
}

/**
 * Helper method to create a IDWriteTextFormat object given _CTTypesetter object and string range.
 *
 * @parameter ts _CTTypesetter object.
 * @parameter range string range to consider for rendering.
 *
 * @return the created IDWriteTextFormat object.
 */
static ComPtr<IDWriteTextFormat> __CreateDWriteTextFormat(_CTTypesetter* ts, CFRange range) {
    // Get the direct write factory instance
    ComPtr<IDWriteFactory> dwriteFactory = __GetDWriteFactoryInstance();

    // TODO::
    // Get font family name details so that can be used here. For now this is hardcoded to "Gabriola".

    // Note here we only look at attribute value at first index of the specified range as we can get a default faont size to use here.
    // Per string range attribute handling will be done in _CreateDWriteTextLayout.
    NSDictionary* attribs = [ts->_attributedString attributesAtIndex:range.location effectiveRange:NULL];
    UIFont* font = [attribs objectForKey:static_cast<NSString*>(kCTFontAttributeName)];
    if (font == nil) {
        font = [s_lazyUIFont systemFontOfSize:c_defaultSystemFontSize];
    }
    float fontSize = [font pointSize];

    ComPtr<IDWriteTextFormat> textFormat;
    THROW_IF_FAILED(dwriteFactory->CreateTextFormat(c_defaultFontName,
                                                    NULL,
                                                    DWRITE_FONT_WEIGHT_REGULAR,
                                                    DWRITE_FONT_STYLE_NORMAL,
                                                    DWRITE_FONT_STRETCH_NORMAL,
                                                    fontSize,
                                                    c_defaultUserLanguage,
                                                    &textFormat));

    return textFormat;
}

/**
 * Helper method to create a IDWriteTextLayout object given _CTTypesetter object, string range and frame size constrain.
 *
 * @parameter ts _CTTypesetter object.
 * @parameter range string range to consider for rendering.
 * @parameter frameSize frame constrains to render the text on.
 *
 * @return the created IDWriteTextLayout object.
 */
static ComPtr<IDWriteTextLayout> __CreateDWriteTextLayout(_CTTypesetter* ts, CFRange range, CGRect frameSize) {
    ComPtr<IDWriteTextFormat> textFormat = __CreateDWriteTextFormat(ts, range);

    // TODO::
    // Iterate through all attributed string ranges and identify attributes so they can be used to -
    //  - set indentation
    //  - set font characteristics
    //  - etc.
    //  These can be done using the DWrite IDWriteTextFormat range property methods.
    NSRange curRange = NSMakeRangeFromCF(range);
    /*
    NSDictionary* attribs = [ts->_attributedString attributesAtIndex:0 effectiveRange:&curRange];
    UIFont* font = [attribs objectForKey:static_cast<NSString*>(kCTFontAttributeName)];
    if (font == nil) {
        font = [s_lazyUIFont systemFontOfSize:c_defaultSystemFontSize];
    }
    float fontSize = [font pointSize];
    */

    wchar_t* wcharString = reinterpret_cast<wchar_t*>(
        const_cast<char*>([[ts->_string substringWithRange:curRange] cStringUsingEncoding:NSUTF16StringEncoding]));

    // TODO::
    // We need too support widthFunc semantic to be able to support NSLayout*. We could either change the API signature of this API or
    // create a new API to support dynamic width support.
    //
    // float width = widthFunc(widthParam, 0, 0, fontSize);

    // Get the direct write factory instance
    ComPtr<IDWriteFactory> dwriteFactory = __GetDWriteFactoryInstance();

    ComPtr<IDWriteTextLayout> textLayout;
    THROW_IF_FAILED(dwriteFactory->CreateTextLayout(
        wcharString, ts->_charactersLen, textFormat.Get(), frameSize.size.width, frameSize.size.height, &textLayout));

    return textLayout;
}

/**
 * Custom IDWriteTextRenderer class that captures the glyph runs generated by DWrite for the given TextLayout and TextRenderer constraints.
 */
class CustomDWriteTextRenderer : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IDWriteTextRenderer> {
protected:
    InspectableClass(L"Windows.Bridge.DirectWrite", TrustLevel::BaseTrust);

public:
    CustomDWriteTextRenderer();

    HRESULT RuntimeClassInitialize();

    HRESULT STDMETHODCALLTYPE DrawGlyphRun(_In_ void* clientDrawingContext,
                                           _In_ float baselineOriginX,
                                           _In_ float baselineOriginY,
                                           DWRITE_MEASURING_MODE measuringMode,
                                           _In_ DWRITE_GLYPH_RUN const* glyphRun,
                                           _In_ DWRITE_GLYPH_RUN_DESCRIPTION const* glyphRunDescription,
                                           _In_ IUnknown* clientDrawingEffects) throw() {
        _DWriteGlyphRunDetails* glyphs = static_cast<_DWriteGlyphRunDetails*>(clientDrawingContext);
        glyphs->_baselineOriginX.push_back(baselineOriginX);
        glyphs->_baselineOriginY.push_back(baselineOriginY);

        _DWriteGlyphRun glyphRunInfo;
        glyphRunInfo._glyphCount = glyphRun->glyphCount;
        for (int index = 0; index < glyphRun->glyphCount; index++) {
            glyphRunInfo._glyphIndices.push_back(glyphRun->glyphIndices[index]);
            glyphRunInfo._glyphAdvances.push_back(CGSizeMake(glyphRun->glyphAdvances[index], 0));
        }
        glyphs->_glyphRuns.push_back(glyphRunInfo);

        _DWriteGlyphRunDescription glyphRunDescriptionInfo;
        glyphRunDescriptionInfo._stringLength = glyphRunDescription->stringLength;
        glyphRunDescriptionInfo._textPosition = glyphRunDescription->textPosition;
        glyphs->_glyphRunDescriptions.push_back(glyphRunDescriptionInfo);

        return S_OK;
    };

    HRESULT STDMETHODCALLTYPE DrawUnderline(_In_ void* clientDrawingContext,
                                            _In_ float baselineOriginX,
                                            _In_ float baselineOriginY,
                                            _In_ DWRITE_UNDERLINE const* underline,
                                            _In_ IUnknown* clientDrawingEffects) throw() {
        return S_OK;
    };

    HRESULT STDMETHODCALLTYPE DrawStrikethrough(_In_ void* clientDrawingContext,
                                                _In_ float baselineOriginX,
                                                _In_ float baselineOriginY,
                                                _In_ DWRITE_STRIKETHROUGH const* strikethrough,
                                                _In_ IUnknown* clientDrawingEffects) throw() {
        return S_OK;
    };

    HRESULT STDMETHODCALLTYPE DrawInlineObject(_In_ void* clientDrawingContext,
                                               _In_ float originX,
                                               _In_ float originY,
                                               _In_ IDWriteInlineObject* inlineObject,
                                               _In_ BOOL isSideways,
                                               _In_ BOOL isRightToLeft,
                                               _In_ IUnknown* clientDrawingEffects) throw() {
        return S_OK;
    };

    HRESULT STDMETHODCALLTYPE IsPixelSnappingDisabled(_In_opt_ void* clientDrawingContext, _Out_ BOOL* isDisabled) throw() {
        *isDisabled = FALSE;
        return S_OK;
    };

    HRESULT STDMETHODCALLTYPE GetCurrentTransform(_In_opt_ void* clientDrawingContext, _Out_ DWRITE_MATRIX* transform) throw() {
        return S_OK;
    };

    HRESULT STDMETHODCALLTYPE GetPixelsPerDip(_In_opt_ void* clientDrawingContext, _Out_ float* pixelsPerDip) throw() {
        *pixelsPerDip = 1.0;
        return S_OK;
    };
};

CustomDWriteTextRenderer::CustomDWriteTextRenderer() {
}

HRESULT CustomDWriteTextRenderer::RuntimeClassInitialize() {
    return S_OK;
}

/**
 * Helper method that will create a TextLayout and TextRenderer object with the given _CTTypesetter object, string range and frame size
 * to render to.
 *
 * @parameter ts _CTTypesetter object.
 * @parameter range string range to consider for rendering.
 * @parameter frameSize frame constrains to render the text on.
 * @parameter glyphDetails pointer to the _DWriteGlyphRunDetails object that contains the glyph run details that was rendeered.
 */
static void __GetGlyphRunDetails(_CTTypesetter* ts, CFRange range, CGRect frameSize, _DWriteGlyphRunDetails* glyphDetails) {
    ComPtr<IDWriteTextLayout> textLayout = __CreateDWriteTextLayout(ts, range, frameSize);
    ComPtr<CustomDWriteTextRenderer> textRenderer = Make<CustomDWriteTextRenderer>();
    textLayout->Draw(glyphDetails, textRenderer.Get(), 0, 0);
}

/**
 * Helper method to create _CTLine objects given a _CTTypesetter, attributed string range to use and frame size to fit in.
 *
 * @parameter ts _CTTypesetter object to use.
 * @parameter range attributed string range to use.
 * @parameter frameSize size parameters of the frame to fit the text into.
 *
 * @return Unmutable array of _CTLine objects created with the requested parameters.
 */
static NSArray<_CTLine*>* _DWriteGetLines(_CTTypesetter* ts, CFRange range, CGRect frameSize) {
    // Call custom renderer to get all glyph run details
    _DWriteGlyphRunDetails glyphRunDetails;
    __GetGlyphRunDetails(ts, range, frameSize, &glyphRunDetails);

    // Create _CTLine objects from the the obtained glyph run details
    int numOfGlyphRuns = glyphRunDetails._glyphRuns.size();
    int i = 0;
    int j = 0;

    NSMutableArray<_CTLine*>* lines = [NSMutableArray array];

    while (j < numOfGlyphRuns) {
        _CTLine* line = [[_CTLine new] autorelease];
        NSMutableArray<_CTRun*>* runs = [NSMutableArray array];
        uint32_t stringRange = 0;
        // Glyph runs that have the same _baselineOriginY value are part of the the same Line.
        while ((j < numOfGlyphRuns) && (glyphRunDetails._baselineOriginY[i] == glyphRunDetails._baselineOriginY[j])) {
            j++;
        }
        while (i < j) {
            // Create _CTRun objects and make them part of _CTLine
            _CTRun* run = [[_CTRun new] autorelease];
            run->_range.location = glyphRunDetails._glyphRunDescriptions[i]._textPosition;
            run->_range.length = glyphRunDetails._glyphRunDescriptions[i]._stringLength;
            run->_stringFragment = [ts->_string substringWithRange:NSMakeRangeFromCF(run->_range)];
            run->_xPos = frameSize.origin.x + glyphRunDetails._baselineOriginX[i];
            // TODO::
            // This is a temp work around to get DWrite measurements to be usable with Cairo FreeType rasterizer. Remove this when
            // we move away from Cairo Freetype. We need this workaround because DWrite coordinate system begins from top left but
            // Cairo FreeType has its from bottom left.
            run->_yPos = frameSize.origin.y + frameSize.size.height - glyphRunDetails._baselineOriginY[i];
            run->_attributes = [ts->_attributedString attributesAtIndex:run->_range.location effectiveRange:NULL];
            run->_glyphAdvances = move(glyphRunDetails._glyphRuns[i]._glyphAdvances);

            [runs addObject:run];
            stringRange += run->_range.length;
            i++;
        }

        line->_runs = runs;
        line->_strRange.location = static_cast<_CTRun*>(line->_runs[0])->_range.location;
        line->_lineOrigin.x = static_cast<_CTRun*>(line->_runs[0])->_xPos;
        line->_lineOrigin.y = static_cast<_CTRun*>(line->_runs[0])->_yPos;
        line->_strRange.length = stringRange;
        [lines addObject:line];
    }

    return lines;
}

/**
 * Helper method to retrieve font fmaly names installed in the system.
 *
 * @return Unmutable array of font family name strings that are installed in the system.
 */
static NSArray<NSString*>* _DWriteGetFontFamilyNames() {
    NSMutableArray<NSString*>* fontFamilyNames = [NSMutableArray<NSString*> array];

    // Get the direct write factory instance
    ComPtr<IDWriteFactory> dwriteFactory = __GetDWriteFactoryInstance();

    // Get the system font collection.
    ComPtr<IDWriteFontCollection> fontCollection;
    THROW_IF_FAILED(dwriteFactory->GetSystemFontCollection(&fontCollection));

    // Get the number of font families in the collection.
    uint32_t count = 0;
    count = fontCollection->GetFontFamilyCount();

    for (uint32_t i = 0; i < count; ++i) {
        // Get the font family.
        ComPtr<IDWriteFontFamily> fontFamily;
        THROW_IF_FAILED(fontCollection->GetFontFamily(i, &fontFamily));

        // Get a list of localized strings for the family name.
        ComPtr<IDWriteLocalizedStrings> familyNames;
        THROW_IF_FAILED(fontFamily->GetFamilyNames(&familyNames));

        [fontFamilyNames addObject:_ConvertLocalizedStringToNSString(familyNames.Get())];
    }

    return fontFamilyNames;
}

NSArray<NSString*>* _DWriteGetFontNamesForFamilyName(NSString* familyName) {
    NSMutableArray<NSString*>* fontNames = [NSMutableArray<NSString*> array];

    ComPtr<IDWriteFactory> dwriteFactory = __GetDWriteFactoryInstance();

    // Get the system font collection.
    ComPtr<IDWriteFontCollection> fontCollection;
    THROW_IF_FAILED(dwriteFactory->GetSystemFontCollection(&fontCollection));

    // Get the font family.
    UINT32 index = 0;
    BOOL exists = false;

    NSUInteger familyNameLength = familyName.length;
    std::vector<UniChar> unicharFamilyName(familyNameLength + 1);
    [familyName getCharacters:unicharFamilyName.data() range:NSMakeRange(0, familyNameLength)];

    THROW_IF_FAILED(fontCollection->FindFamilyName(reinterpret_cast<wchar_t*>(unicharFamilyName.data()), &index, &exists));
    if (!exists) {
        TraceError(TAG, L"Failed to find the font family name.");
        return fontNames;
    }

    ComPtr<IDWriteFontFamily> fontFamily;
    THROW_IF_FAILED(fontCollection->GetFontFamily(index, &fontFamily));

    ComPtr<IDWriteFontList> fontList;
    THROW_IF_FAILED(
        fontFamily->GetMatchingFonts(DWRITE_FONT_WEIGHT_THIN, DWRITE_FONT_STRETCH_UNDEFINED, DWRITE_FONT_STYLE_NORMAL, &fontList));

    UINT32 count = 0;
    count = fontList->GetFontCount();

    for (UINT32 i = 0; i < count; i++) {
        ComPtr<IDWriteFont> font;
        THROW_IF_FAILED(fontList->GetFont(i, &font));

        ComPtr<IDWriteLocalizedStrings> fullName;
        BOOL exist = FALSE;
        THROW_IF_FAILED(font->GetInformationalStrings(DWRITE_INFORMATIONAL_STRING_FULL_NAME, &fullName, &exist));

        if (exist) {
            NSString* name = _ConvertLocalizedStringToNSString(fullName.Get());
            if (name.length == 0) {
                TraceError(TAG, L"Failed to convert the localized string to wide string.");
                return fontNames;
            }

            [fontNames addObject:name];
        }
    }

    return fontNames;
}

NSString* _DWriteGetFamilyNameForFontName(CFStringRef fontName) {
    static NSDictionary<NSString*, NSString*>* fontToFamilyMap = nil;

    static dispatch_once_t initOnce = 0;
    dispatch_once(&initOnce,
                  ^{
                      // initialize fontToFamilyMap
                      NSMutableDictionary<NSString*, NSString*>* initMap = [NSMutableDictionary<NSString*, NSString*> dictionary];
                      NSArray<NSString*>* familyNames = _DWriteGetFontFamilyNames();

                      for (NSString* familyName in familyNames) {
                          NSArray<NSString*>* fontNames = _DWriteGetFontNamesForFamilyName(familyName);

                          for (NSString* fontName in fontNames) {
                              [initMap setObject:familyName forKey:fontName];
                          }
                      }

                      fontToFamilyMap = [initMap copy];
                  });

    return [fontToFamilyMap objectForKey:(__bridge NSString*)fontName];
}

// Private helper that acquires an IDWriteFontFamily object for a given family name
static ComPtr<IDWriteFontFamily> __GetDWriteFontFamily(NSString* familyName) {
    ComPtr<IDWriteFontFamily> fontFamily;

    ComPtr<IDWriteFactory> factory = __GetDWriteFactoryInstance();

    ComPtr<IDWriteFontCollection> systemFontCollection;
    THROW_IF_FAILED(factory->GetSystemFontCollection(&systemFontCollection));

    NSUInteger familyNameLength = familyName.length;
    std::vector<UniChar> unicharFamilyName(familyNameLength + 1);
    [familyName getCharacters:unicharFamilyName.data() range:NSMakeRange(0, familyNameLength)];

    UINT32 fontFamilyIndex;
    BOOL fontFamilyExists;

    THROW_IF_FAILED(systemFontCollection->FindFamilyName(reinterpret_cast<const wchar_t*>(unicharFamilyName.data()),
                                                         &fontFamilyIndex,
                                                         &fontFamilyExists));

    if (!fontFamilyExists) {
        TraceError(TAG, L"Unable to find font family \"%ws\"", unicharFamilyName.data());
        return fontFamily;
    }

    THROW_IF_FAILED(systemFontCollection->GetFontFamily(fontFamilyIndex, &fontFamily));
    return fontFamily;
}

// Private helper that parses a font name, and returns appropriate weight, stretch, and style values for DWrite accordingly
static void __InitDWriteFontPropertiesFromName(CFStringRef fontName,
                                               DWRITE_FONT_WEIGHT* weight,
                                               DWRITE_FONT_STRETCH* stretch,
                                               DWRITE_FONT_STYLE* style) {
    // Set some defaults for when weight/stretch/style are not mentioned in the name
    *weight = DWRITE_FONT_WEIGHT_NORMAL;
    *stretch = DWRITE_FONT_STRETCH_NORMAL;
    *style = DWRITE_FONT_STYLE_NORMAL;

    NSString* familyName = _DWriteGetFamilyNameForFontName(fontName);

    // Relationship of family name -> font name not always consistent
    // Usually, properties are added to the end (eg: Arial -> Arial Narrow Bold)
    // However, this is not always the case (eg: Eras ITC -> Eras Bold ITC)
    // In addition, some fonts with properties are occasionally placed into their own family (eg: Segoe WP SemiLight -> Segoe WP SemiLight)
    // Try to be more prudent about these edge cases, by looking only at the difference between the font name and family name
    NSArray<NSString*>* fontNameTokens = [(__bridge NSString*)fontName componentsSeparatedByString:@" "];
    NSMutableSet<NSString*>* propertyTokens = [NSMutableSet<NSString*> setWithArray:fontNameTokens];

    if (familyName) {
        NSArray<NSString*>* familyNameTokens = [familyName componentsSeparatedByString:@" "];
        [propertyTokens minusSet:[NSSet setWithArray:familyNameTokens]];
    }

    for (NSString* propertyToken in propertyTokens) {
        NSString* upperPropertyToken = [propertyToken uppercaseString];

        if ([upperPropertyToken isEqual:@"THIN"]) {
            *weight = DWRITE_FONT_WEIGHT_THIN;
        } else if ([upperPropertyToken isEqual:@"EXTRALIGHT"]) {
            *weight = DWRITE_FONT_WEIGHT_EXTRA_LIGHT;
        } else if ([upperPropertyToken isEqual:@"ULTRALIGHT"]) {
            *weight = DWRITE_FONT_WEIGHT_ULTRA_LIGHT;
        } else if ([upperPropertyToken isEqual:@"LIGHT"]) {
            *weight = DWRITE_FONT_WEIGHT_LIGHT;
        } else if ([upperPropertyToken isEqual:@"SEMILIGHT"]) {
            *weight = DWRITE_FONT_WEIGHT_SEMI_LIGHT;
            // skip since this is the default
            // } else if ([upperPropertyToken isEqual:@"NORMAL"]) {
            //     *weight = DWRITE_FONT_WEIGHT_NORMAL;
        } else if ([upperPropertyToken isEqual:@"REGULAR"]) {
            *weight = DWRITE_FONT_WEIGHT_REGULAR;
        } else if ([upperPropertyToken isEqual:@"MEDIUM"]) {
            *weight = DWRITE_FONT_WEIGHT_MEDIUM;
        } else if ([upperPropertyToken isEqual:@"DEMIBOLD"]) {
            *weight = DWRITE_FONT_WEIGHT_DEMI_BOLD;
        } else if ([upperPropertyToken isEqual:@"SEMIBOLD"]) {
            *weight = DWRITE_FONT_WEIGHT_SEMI_BOLD;
        } else if ([upperPropertyToken isEqual:@"BOLD"]) {
            *weight = DWRITE_FONT_WEIGHT_BOLD;
        } else if ([upperPropertyToken isEqual:@"EXTRABOLD"]) {
            *weight = DWRITE_FONT_WEIGHT_EXTRA_BOLD;
        } else if ([upperPropertyToken isEqual:@"ULTRABOLD"]) {
            *weight = DWRITE_FONT_WEIGHT_ULTRA_BOLD;
        } else if ([upperPropertyToken isEqual:@"BLACK"]) {
            *weight = DWRITE_FONT_WEIGHT_BLACK;
        } else if ([upperPropertyToken isEqual:@"HEAVY"]) {
            *weight = DWRITE_FONT_WEIGHT_HEAVY;
        } else if ([upperPropertyToken isEqual:@"EXTRABLACK"]) {
            *weight = DWRITE_FONT_WEIGHT_EXTRA_BLACK;
        } else if ([upperPropertyToken isEqual:@"ULTRABLACK"]) {
            *weight = DWRITE_FONT_WEIGHT_ULTRA_BLACK;

        } else if ([upperPropertyToken isEqual:@"UNDEFINED"]) {
            *stretch = DWRITE_FONT_STRETCH_UNDEFINED;
        } else if ([upperPropertyToken isEqual:@"ULTRACONDENSED"]) {
            *stretch = DWRITE_FONT_STRETCH_ULTRA_CONDENSED;
        } else if ([upperPropertyToken isEqual:@"EXTRACONDENSED"]) {
            *stretch = DWRITE_FONT_STRETCH_EXTRA_CONDENSED;
        } else if ([upperPropertyToken isEqual:@"CONDENSED"] || [upperPropertyToken isEqual:@"NARROW"]) {
            *stretch = DWRITE_FONT_STRETCH_CONDENSED;
        } else if ([upperPropertyToken isEqual:@"SEMICONDENSED"]) {
            *stretch = DWRITE_FONT_STRETCH_SEMI_CONDENSED;
            // skip since this is the default
            // } else if ([upperPropertyToken isEqual:@"NORMAL"]) {
            //     *stretch = DWRITE_FONT_STRETCH_NORMAL;
        } else if ([upperPropertyToken isEqual:@"MEDIUM"]) {
            *stretch = DWRITE_FONT_STRETCH_MEDIUM;
        } else if ([upperPropertyToken isEqual:@"SEMIEXPANDED"]) {
            *stretch = DWRITE_FONT_STRETCH_SEMI_EXPANDED;
        } else if ([upperPropertyToken isEqual:@"EXPANDED"]) {
            *stretch = DWRITE_FONT_STRETCH_EXPANDED;
        } else if ([upperPropertyToken isEqual:@"EXTRAEXPANDED"]) {
            *stretch = DWRITE_FONT_STRETCH_EXTRA_EXPANDED;
        } else if ([upperPropertyToken isEqual:@"ULTRAEXPANDED"]) {
            *stretch = DWRITE_FONT_STRETCH_ULTRA_EXPANDED;

            // skip since this is the default
            // } else if ([upperPropertyToken isEqual:@"NORMAL"]) {
            //     *style = DWRITE_FONT_STYLE_NORMAL;
        } else if ([upperPropertyToken isEqual:@"OBLIQUE"]) {
            *style = DWRITE_FONT_STYLE_OBLIQUE;
        } else if ([upperPropertyToken isEqual:@"ITALIC"]) {
            *style = DWRITE_FONT_STYLE_ITALIC;
        }
    }
}

HRESULT _DWriteCreateFontWithName(CFStringRef name, IDWriteFont** outFont) {
    // Parse the font name for font weight, stretch, and style
    // Eg: Bold, Condensed, Light, Italic
    DWRITE_FONT_WEIGHT weight = DWRITE_FONT_WEIGHT_NORMAL;
    DWRITE_FONT_STRETCH stretch = DWRITE_FONT_STRETCH_NORMAL;
    DWRITE_FONT_STYLE style = DWRITE_FONT_STYLE_NORMAL;

    __InitDWriteFontPropertiesFromName(name, &weight, &stretch, &style);

    NSString* familyName = _DWriteGetFamilyNameForFontName(name);
    if (!familyName) {
        TraceError(TAG, L"Unable to find family for font name \"%hs\"", [static_cast<NSString*>(name) UTF8String]);
        return E_INVALIDARG;
    }

    ComPtr<IDWriteFontFamily> fontFamily = __GetDWriteFontFamily(familyName);
    if (!fontFamily) {
        TraceError(TAG, L"Unable to find family for font name \"%hs\"", [static_cast<NSString*>(name) UTF8String]);
        return E_INVALIDARG;
    }

    return fontFamily->GetFirstMatchingFont(weight, stretch, style, outFont);
}