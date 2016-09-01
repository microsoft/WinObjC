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

#include <COMIncludes.h>
#import <wrl/implements.h>
#include <COMIncludes_End.h>
#import <mutex>
#import <vector>
#import <algorithm>
#import <CoreFoundation/CFBase.h>
#import "CoreTextInternal.h"
#import "DWriteWrapper.h"

using namespace std;
using namespace Microsoft::WRL;

static const wchar_t* TAG = L"_DWriteWrapper";

// TODO::
// These should be removed once CTFont and UIFont are bridged.
static IWLazyClassLookup s_lazyUIFont("UIFont");
static const float c_defaultSystemFontSize = 15.0f;

static ComPtr<IDWriteFactory> CreateDWriteFactoryInstance() {
    ComPtr<IDWriteFactory> dwriteFactory;
    THROW_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED,
                                        __uuidof(IDWriteFactory),
                                        reinterpret_cast<IUnknown**>(dwriteFactory.GetAddressOf())));
    return dwriteFactory;
}

static ComPtr<IDWriteFactory> GetDWriteFactoryInstance() {
    static ComPtr<IDWriteFactory> s_dwriteFactory = CreateDWriteFactoryInstance();
    return s_dwriteFactory;
}

/**
 * Helper method to return the user set default locale string.
 *
 * @return use set locale string as wstring.
 */
static wstring _getUserDefaultLocaleName() {
    wchar_t localeName[LOCALE_NAME_MAX_LENGTH];
    int defaultLocaleSuccess = GetUserDefaultLocaleName(localeName, LOCALE_NAME_MAX_LENGTH);

    // If the default locale is returned, find that locale name, otherwise use "en-us".
    if (defaultLocaleSuccess) {
        return wstring(localeName);
    } else {
        return wstring(L"en-us");
    }
}

/**
 * Helper method to convert IDWriteLocalizedStrings object to NSString object.
 *
 * @parameter localizedString IDWriteLocalizedStrings object to convert.
 *
 * @return NSString object.
 */
static NSString* _convertLocalizedStringToNSString(IDWriteLocalizedStrings* localizedString) {
    if (localizedString == NULL) {
        TraceError(TAG, L"The input parameter is invalid!");
        return nil;
    }

    // Get the default locale for this user.
    wstring localeName = _getUserDefaultLocaleName();

    uint32_t index = 0;
    BOOL exists = false;

    // If the default locale is returned, find that locale name, otherwise use "en-us".
    THROW_IF_FAILED(localizedString->FindLocaleName(localeName.c_str(), &index, &exists));
    if (!exists) {
        THROW_IF_FAILED(localizedString->FindLocaleName(L"en-us", &index, &exists));
    }

    // If the specified locale doesn't exist, select the first on the list.
    if (!exists) {
        index = 0;
    }

    // Get the string length.
    uint32_t length = 0;
    THROW_IF_FAILED(localizedString->GetStringLength(index, &length));

    // Get the string.
    auto wcharString = make_unique<wchar_t[]>(length + 1);
    THROW_IF_FAILED(localizedString->GetString(index, &wcharString[0], length + 1));

    return [[[NSString alloc] initWithBytesNoCopy:&wcharString[0] length:length + 1 encoding:NSUTF16StringEncoding freeWhenDone:YES]
        autorelease];
}

/**
 * Helper method to create a IDWriteTextFormat object given _CTTypesetter object and string range.
 *
 * @parameter ts _CTTypesetter object.
 * @parameter range string range to consider for rendering.
 *
 * @return the created IDWriteTextFormat object.
 */
static ComPtr<IDWriteTextFormat> _createDWriteTextFormat(_CTTypesetter* ts, CFRange range) {
    // Get the direct write factory instance
    ComPtr<IDWriteFactory> dwriteFactory = GetDWriteFactoryInstance();

    // TODO::
    // Get font family name details so that can be used here. For now this is hardcoded to "Gabriola".

    // Note here we only look at attribute value at first index of the specified range as we can get a default faont size to use here.
    // Per string range attribute handling will be done in _createDWriteTextLayout.
    NSRange curRange = NSMakeRangeFromCF(range);
    NSDictionary* attribs = [ts->_attributedString attributesAtIndex:curRange.location effectiveRange:NULL];
    UIFont* font = [attribs objectForKey:static_cast<NSString*>(kCTFontAttributeName)];
    if (font == nil) {
        font = [s_lazyUIFont systemFontOfSize:c_defaultSystemFontSize];
    }
    float fontSize = [font pointSize];

    ComPtr<IDWriteTextFormat> textFormat;
    THROW_IF_FAILED(dwriteFactory->CreateTextFormat(L"Gabriola",
                                                    NULL,
                                                    DWRITE_FONT_WEIGHT_REGULAR,
                                                    DWRITE_FONT_STYLE_NORMAL,
                                                    DWRITE_FONT_STRETCH_NORMAL,
                                                    fontSize,
                                                    L"en-us",
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
static ComPtr<IDWriteTextLayout> _createDWriteTextLayout(_CTTypesetter* ts, CFRange range, CGRect frameSize) {
    ComPtr<IDWriteTextFormat> textFormat = _createDWriteTextFormat(ts, range);

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
    ComPtr<IDWriteFactory> dwriteFactory = GetDWriteFactoryInstance();

    ComPtr<IDWriteTextLayout> textLayout;
    THROW_IF_FAILED(dwriteFactory->CreateTextLayout(
        wcharString, ts->_charactersLen, textFormat.Get(), frameSize.size.width, frameSize.size.height, &textLayout));

    return textLayout;
}

/**
 * Custom IDWriteTextRenderer class that cpatures the glyph runs generated by DWrite for the given TextLayout and TextRenderer constrains.
 */
class CustomTargetTextRenderer
    : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::WinRtClassicComMix>, IDWriteTextRenderer> {
protected:
    InspectableClass(L"Windows.Bridge.DirectWrite", TrustLevel::BaseTrust);

public:
    CustomTargetTextRenderer();

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
        *isDisabled = false;
        return S_OK;
    };

    HRESULT STDMETHODCALLTYPE GetCurrentTransform(_In_opt_ void* clientDrawingContext, _Out_ DWRITE_MATRIX* transform) throw() {
        return S_OK;
    };

    HRESULT STDMETHODCALLTYPE GetPixelsPerDip(_In_opt_ void* clientDrawingContext, _Out_ float* pixelsPerDip) throw() {
        *pixelsPerDip = 1.0;
        return S_OK;
    };

private:
    ComPtr<IDWriteFactory> _dwriteFactory;
};

CustomTargetTextRenderer::CustomTargetTextRenderer() {
    _dwriteFactory = GetDWriteFactoryInstance();
}

HRESULT CustomTargetTextRenderer::RuntimeClassInitialize() {
    _dwriteFactory = GetDWriteFactoryInstance();
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
static void _callCustomRender(_CTTypesetter* ts, CFRange range, CGRect frameSize, _DWriteGlyphRunDetails* glyphDetails) {
    ComPtr<IDWriteTextLayout> textLayout = _createDWriteTextLayout(ts, range, frameSize);
    ComPtr<CustomTargetTextRenderer> textRenderer = Make<CustomTargetTextRenderer>();
    textLayout->Draw(glyphDetails, textRenderer.Get(), 0, 0);
}

/**
 * Helper method to retrieve font fmaly names installed in the system.
 *
 * @return Unmutable array of font family name strings that are installed in the system.
 */
static NSArray<NSString*>* _dwriteGetFamilyNames() {
    NSMutableArray<NSString*>* fontFamilyNames = [NSMutableArray<NSString*> array];

    // Get the direct write factory instance
    ComPtr<IDWriteFactory> dwriteFactory = GetDWriteFactoryInstance();

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

        [fontFamilyNames addObject:_convertLocalizedStringToNSString(familyNames.Get())];
    }

    return [fontFamilyNames autorelease];
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
static NSArray<_CTLine*>* _dwriteGetLines(_CTTypesetter* ts, CFRange range, CGRect frameSize) {
    // Call custom renderer to get all glyph run details
    _DWriteGlyphRunDetails glyphRunDetails;
    _callCustomRender(ts, range, frameSize, &glyphRunDetails);

    // Create _CTLine objects from the the obtained glyph run details
    int numOfGlyphRuns = glyphRunDetails._glyphRuns.size();
    int i = 0;
    int j = 0;

    NSMutableArray<_CTLine*>* lines = [[NSMutableArray alloc] init];

    while (j < numOfGlyphRuns) {
        _CTLine* line = [[_CTLine new] autorelease];
        NSMutableArray<_CTRun*>* runs = [[NSMutableArray alloc] init];
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

        line->_typeSetter = [ts retain];
        line->_runs.attach(runs);
        line->_strRange.location = static_cast<_CTRun*>(line->_runs[0])->_range.location;
        line->_lineOrigin.x = static_cast<_CTRun*>(line->_runs[0])->_xPos;
        line->_lineOrigin.y = static_cast<_CTRun*>(line->_runs[0])->_yPos;
        line->_strRange.length = stringRange;
        [lines addObject:line];
    }

    return [lines autorelease];
}