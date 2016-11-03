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

#import "DWriteWrapper_CoreText.h"
#import "CoreTextInternal.h"

#import <Starboard.h>

#import <CoreFoundation/CFBase.h>

#import <LoggingNative.h>
#import <vector>
#import <iterator>
#import <numeric>

using namespace std;
using namespace Microsoft::WRL;

static const wchar_t* TAG = L"_DWriteWrapper_CoreText";

static DWRITE_TEXT_ALIGNMENT __CoreTextAlignmentToDwrite(CTTextAlignment alignment) {
    switch (alignment) {
        case kCTRightTextAlignment:
            return DWRITE_TEXT_ALIGNMENT_TRAILING;
        case kCTCenterTextAlignment:
            return DWRITE_TEXT_ALIGNMENT_CENTER;
        case kCTJustifiedTextAlignment:
            return DWRITE_TEXT_ALIGNMENT_JUSTIFIED;
        case kCTLeftTextAlignment:
        case kCTNaturalTextAlignment:
        default:
            return DWRITE_TEXT_ALIGNMENT_LEADING;
    }
}

template <typename TElement>
bool __CloneArray(_In_reads_opt_(count) TElement const* source,
                  _In_ size_t count,
                  _Outptr_result_buffer_all_maybenull_(count) TElement const** result) {
    bool ret = true;

    *result = nullptr;

    if (source != nullptr) {
        TElement* array = new TElement[count];
        ret = (array != nullptr) ? true : false;
        if (ret) {
            memcpy(array, source, sizeof(TElement) * count);
            *result = array;
        }
    }

    return ret;
}

bool _CloneDWriteGlyphRun(_In_ DWRITE_GLYPH_RUN const* src, _Out_ DWRITE_GLYPH_RUN* dest) {
    bool ret = true;

    if (src) {
        dest->fontFace = src->fontFace;
        dest->fontFace->AddRef();

        dest->fontEmSize = src->fontEmSize;
        dest->glyphCount = src->glyphCount;
        dest->isSideways = src->isSideways;
        dest->bidiLevel = src->bidiLevel;

        bool ret = __CloneArray(src->glyphIndices, src->glyphCount, &dest->glyphIndices);
        if (ret) {
            ret = __CloneArray(src->glyphAdvances, src->glyphCount, &dest->glyphAdvances);
        }
        if (ret) {
            ret = __CloneArray(src->glyphOffsets, src->glyphCount, &dest->glyphOffsets);
        }
    }

    return ret;
}

/**
 * Helper method to create a IDWriteTextFormat object given _CTTypesetter object and string range.
 *
 * @parameter ts _CTTypesetter object.
 * @parameter range string range to consider for rendering.
 *
 * @return the created IDWriteTextFormat object.
 */
static ComPtr<IDWriteTextFormat> __CreateDWriteTextFormat(CFAttributedStringRef string, CFRange range) {
    // TODO::
    // Note here we only look at attribute value at first index of the specified range as we can get a default faont size to use here.
    // Per string range attribute handling will be done in _CreateDWriteTextLayout.

    NSDictionary* attribs = [static_cast<NSAttributedString*>(string) attributesAtIndex:range.location effectiveRange:NULL];

    CGFloat fontSize = kCTFontSystemFontSize;
    CTFontRef font = static_cast<CTFontRef>([attribs objectForKey:static_cast<NSString*>(kCTFontAttributeName)]);
    std::vector<wchar_t> familyName;

    _DWriteFontProperties properties = { DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STRETCH_NORMAL, DWRITE_FONT_STYLE_NORMAL, nullptr };

    if (font) {
        fontSize = CTFontGetSize(font);
        CFStringRef fontFullName = CTFontCopyName(font, kCTFontFullNameKey);
        CFAutorelease(fontFullName);
        properties = _DWriteGetFontPropertiesFromName(fontFullName);
    }

    familyName.resize(CFStringGetLength(properties.familyName) + 1, 0);
    CFStringGetCharacters(properties.familyName, CFRangeMake(0, familyName.size()), reinterpret_cast<UniChar*>(familyName.data()));

    ComPtr<IDWriteTextFormat> textFormat;
    RETURN_NULL_IF_FAILED(
        _DWriteCreateTextFormat(familyName.data(), properties.weight, properties.style, properties.stretch, fontSize, &textFormat));

    CTParagraphStyleRef settings =
        static_cast<CTParagraphStyleRef>([attribs valueForKey:static_cast<NSString*>(kCTParagraphStyleAttributeName)]);
    if (settings) {
        CTTextAlignment alignment = kCTNaturalTextAlignment;
        if (CTParagraphStyleGetValueForSpecifier(settings, kCTParagraphStyleSpecifierAlignment, sizeof(CTTextAlignment), &alignment)) {
            DWRITE_TEXT_ALIGNMENT dwriteAlignment = __CoreTextAlignmentToDwrite(alignment);
            RETURN_NULL_IF_FAILED(textFormat->SetTextAlignment(dwriteAlignment));
        }

        CTWritingDirection direction;
        if (CTParagraphStyleGetValueForSpecifier(settings, kCTParagraphStyleSpecifierBaseWritingDirection, sizeof(direction), &direction)) {
            DWRITE_READING_DIRECTION dwriteDirection = DWRITE_READING_DIRECTION_LEFT_TO_RIGHT;
            if (direction == kCTWritingDirectionRightToLeft) {
                dwriteDirection = DWRITE_READING_DIRECTION_RIGHT_TO_LEFT;

                // DWrite alignment is based upon reading direction whereas CoreText alignment is constant
                // so we have to flip the writing direction
                if (alignment == kCTRightTextAlignment || alignment == kCTNaturalTextAlignment) {
                    RETURN_NULL_IF_FAILED(textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING));
                } else if (alignment == kCTLeftTextAlignment) {
                    RETURN_NULL_IF_FAILED(textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_TRAILING));
                }
            }

            RETURN_NULL_IF_FAILED(textFormat->SetReadingDirection(dwriteDirection));
        }
    }

    return textFormat;
}

/**
 * Helper method to create a IDWriteTextLayout object given _CTTypesetter object, string range and frame size constrain.
 *
 * @parameter CFAttributedStringRef string with text and attributes
 * @parameter range string range to consider for rendering.
 * @parameter frameSize frame constrains to render the text on.
 *
 * @return the created IDWriteTextLayout object.
 */
static ComPtr<IDWriteTextLayout> __CreateDWriteTextLayout(CFAttributedStringRef string, CFRange range, CGRect frameSize) {
    ComPtr<IDWriteTextFormat> textFormat = __CreateDWriteTextFormat(string, range);

    NSRange curRange = NSMakeRangeFromCF(range);
    NSString* subString = [static_cast<NSString*>(CFAttributedStringGetString(string)) substringWithRange:curRange];
    wchar_t* wcharString = reinterpret_cast<wchar_t*>(const_cast<char*>([subString cStringUsingEncoding:NSUTF16StringEncoding]));

    // TODO::
    // We need too support widthFunc semantic to be able to support NSLayout*. We could either change the API signature of this API or
    // create a new API to support dynamic width support.
    //
    // float width = widthFunc(widthParam, 0, 0, fontSize);

    // Get the direct write factory instance
    ComPtr<IDWriteFactory> dwriteFactory;
    RETURN_NULL_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));

    ComPtr<IDWriteTextLayout> textLayout;
    RETURN_NULL_IF_FAILED(dwriteFactory->CreateTextLayout(
        wcharString, [subString length], textFormat.Get(), frameSize.size.width, frameSize.size.height, &textLayout));

    // TODO::
    // Iterate through all attributed string ranges and identify attributes so they can be used to -
    //  - set indentation
    //  - etc.
    //  These can be done using the DWrite IDWriteTextFormat range property methods.

    // Used to separate runs for attributes which DWrite does not handle until drawing (e.g. Foreground Color)
    uint32_t incompatibleAttributeFlag = 0;

    NSRange attributeRange;
    for (size_t i = 0; i < [subString length]; i += attributeRange.length) {
        NSDictionary* attribs = [static_cast<NSAttributedString*>(string) attributesAtIndex:i + range.location
                                                                      longestEffectiveRange:&attributeRange
                                                                                    inRange:{ i + range.location, [subString length] }];

        const DWRITE_TEXT_RANGE dwriteRange = { attributeRange.location, attributeRange.length };

        CTFontRef font = static_cast<CTFontRef>([attribs objectForKey:static_cast<NSString*>(kCTFontAttributeName)]);
        CGFloat fontSize = kCTFontSystemFontSize;
        if (font != nil) {
            fontSize = CTFontGetSize(font);
            _DWriteFontProperties properties = _DWriteGetFontPropertiesFromName(CTFontCopyName(font, kCTFontFullNameKey));
            std::vector<wchar_t> familyName(CFStringGetLength(properties.familyName) + 1);
            CFStringGetCharacters(properties.familyName, CFRangeMake(0, familyName.size()), reinterpret_cast<UniChar*>(familyName.data()));

            RETURN_NULL_IF_FAILED(textLayout->SetFontSize(fontSize, dwriteRange));
            RETURN_NULL_IF_FAILED(textLayout->SetFontWeight(properties.weight, dwriteRange));
            RETURN_NULL_IF_FAILED(textLayout->SetFontStretch(properties.stretch, dwriteRange));
            RETURN_NULL_IF_FAILED(textLayout->SetFontStyle(properties.style, dwriteRange));
            RETURN_NULL_IF_FAILED(textLayout->SetFontFamilyName(familyName.data(), dwriteRange));
        }

        ComPtr<IDWriteTypography> typography;
        RETURN_NULL_IF_FAILED(textLayout->GetTypography(dwriteRange.startPosition, &typography));
        if (!typography.Get()) {
            RETURN_NULL_IF_FAILED(dwriteFactory->CreateTypography(&typography));
        }

        CFNumberRef extraKerningRef = static_cast<CFNumberRef>([attribs objectForKey:static_cast<NSString*>(kCTKernAttributeName)]);
        if (extraKerningRef) {
            ComPtr<IDWriteTextLayout1> textLayout1;
            RETURN_NULL_IF_FAILED(textLayout.As(&textLayout1));
            CGFloat leadingSpacing, trailingSpacing, minimumAdvanceWidth;
            RETURN_NULL_IF_FAILED(
                textLayout1->GetCharacterSpacing(dwriteRange.startPosition, &leadingSpacing, &trailingSpacing, &minimumAdvanceWidth));

            CGFloat extraKerning;
            CFNumberGetValue(extraKerningRef, kCFNumberFloatType, &extraKerning);
            trailingSpacing += extraKerning;

            RETURN_NULL_IF_FAILED(textLayout1->SetCharacterSpacing(leadingSpacing, trailingSpacing, minimumAdvanceWidth, dwriteRange));

            // Setting kern disables default kerning
            RETURN_NULL_IF_FAILED(typography->AddFontFeature({ DWRITE_FONT_FEATURE_TAG_KERNING, 0 }));
        }

        // Forces run breaks without interfering with any layout features
        // Necessary for attributes which DWrite does not support during layout (e.g. Color)
        RETURN_NULL_IF_FAILED(typography->AddFontFeature({ DWRITE_FONT_FEATURE_TAG_DEFAULT, ++incompatibleAttributeFlag }));
        RETURN_NULL_IF_FAILED(textLayout->SetTypography(typography.Get(), dwriteRange));
    }

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

        DWRITE_GLYPH_RUN dwriteGlyphRun = {};
        _CloneDWriteGlyphRun(glyphRun, &dwriteGlyphRun);
        glyphs->_dwriteGlyphRun.push_back(dwriteGlyphRun);

        glyphs->_baselineOriginX.push_back(baselineOriginX);
        glyphs->_baselineOriginY.push_back(baselineOriginY);

        _DWriteGlyphRunDescription glyphRunDescriptionInfo;
        glyphRunDescriptionInfo._stringLength = glyphRunDescription->stringLength;
        glyphRunDescriptionInfo._textPosition = glyphRunDescription->textPosition;
        std::transform(glyphRunDescription->clusterMap,
                       glyphRunDescription->clusterMap + glyphRun->glyphCount,
                       std::back_inserter(glyphRunDescriptionInfo._clusterMap),
                       [startIndex = glyphRunDescription->textPosition](uint16_t index) { return index + startIndex; });
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
 * Helper method to create _CTLine object given a CFAttributedStringRef
 *
 * @parameter string CFAttributedStringRef containing text and styling
 *
 * @return Unmutable array of _CTLine objects created with the requested parameters.
 */
static _CTLine* _DWriteGetLine(CFAttributedStringRef string) {
    CFRange range = CFRangeMake(0, CFAttributedStringGetLength(string));
    _CTFrame* frame = _DWriteGetFrame(string, range, CGRectMake(0, 0, FLT_MAX, FLT_MAX));
    if ([frame->_lines count] > 0) {
        return [[frame->_lines firstObject] retain];
    }

    return [_CTLine new];
}

/**
 * Helper method to create _CTLine objects given a CFAttributedStringRef, attributed string range to use and frame size to fit in.
 *
 * @parameter CFAttributedStringRef with text and attributes
 * @parameter range attributed string range to use.
 * @parameter frameSize size parameters of the frame to fit the text into.
 *
 * @return _CTFrame* created using the given parameters
 */
static _CTFrame* _DWriteGetFrame(CFAttributedStringRef string, CFRange range, CGRect frameSize) {
    RETURN_NULL_IF(!string);

    _CTFrame* frame = [[_CTFrame new] autorelease];
    if (range.length <= 0) {
        return frame;
    }

    // Call custom renderer to get all glyph run details
    ComPtr<IDWriteTextLayout> textLayout = __CreateDWriteTextLayout(string, range, frameSize);
    ComPtr<CustomDWriteTextRenderer> textRenderer = Make<CustomDWriteTextRenderer>();
    _DWriteGlyphRunDetails glyphRunDetails = {};
    textLayout->Draw(&glyphRunDetails, textRenderer.Get(), 0, 0);
    DWRITE_TEXT_METRICS textMetrics;
    RETURN_NULL_IF_FAILED(textLayout->GetMetrics(&textMetrics));
    frame->_frameRect = frameSize;

    // TODO:: find more precise value than 1.0 to increase width by to fully enclose frame
    frame->_frameRect.size.width = std::min(frameSize.size.width, textMetrics.widthIncludingTrailingWhitespace + 1.0f);
    frame->_frameRect.size.height = std::min(frameSize.size.height, textMetrics.height);

    // Create _CTLine objects from the the obtained glyph run details
    int numOfGlyphRuns = glyphRunDetails._dwriteGlyphRun.size();
    int i = 0;
    int j = 0;

    // Relative offsets for each run and line that will be used by CTLineDraw and CTRunDRaw methods to render.
    float prevXPosForDraw = 0;
    float prevYPosForDraw = 0;

    while (j < numOfGlyphRuns) {
        _CTLine* line = [[_CTLine new] autorelease];
        NSMutableArray<_CTRun*>* runs = [NSMutableArray array];
        uint32_t stringRange = 0;
        uint32_t glyphCount = 0;
        prevXPosForDraw = 0;

        float xPos;
        float yPos;

        // These are created lazily in the first call to CTLineGetTypographicBounds, so initialize with impossible values
        line->_ascent = -FLT_MAX;
        line->_descent = FLT_MAX;
        line->_leading = -FLT_MAX;

        // Glyph runs that have the same _baselineOriginY value are part of the the same Line.
        while ((j < numOfGlyphRuns) && (glyphRunDetails._baselineOriginY[i] == glyphRunDetails._baselineOriginY[j])) {
            j++;
        }
        while (i < j) {
            // Create _CTRun objects and make them part of _CTLine
            _CTRun* run = [[_CTRun new] autorelease];
            run->_range.location = glyphRunDetails._glyphRunDescriptions[i]._textPosition;
            run->_range.length = glyphRunDetails._glyphRunDescriptions[i]._stringLength;
            run->_stringFragment = [static_cast<NSString*>(CFAttributedStringGetString(string))
                substringWithRange:NSMakeRange(range.location + run->_range.location, run->_range.length)];
            run->_dwriteGlyphRun = move(glyphRunDetails._dwriteGlyphRun[i]);
            run->_stringIndices = move(glyphRunDetails._glyphRunDescriptions[i]._clusterMap);
            run->_attributes =
                [static_cast<NSAttributedString*>(string) attributesAtIndex:(range.location + run->_range.location) effectiveRange:NULL];

            xPos = glyphRunDetails._baselineOriginX[i];
            yPos = glyphRunDetails._baselineOriginY[i];

            // Calculate the relative offset of each glyph run and store it. This will be useful while drawing individual glpyh runs or
            // lines.
            run->_relativeXOffset = xPos - prevXPosForDraw;
            run->_relativeYOffset = yPos - prevYPosForDraw;
            prevXPosForDraw = xPos;

            // TODO::
            // This is a temp workaround until we can have actual glyph origins
            for (int index = 0; index < glyphRunDetails._dwriteGlyphRun[i].glyphCount; index++) {
                run->_glyphOrigins.emplace_back(CGPoint{ xPos, yPos });
                run->_glyphAdvances.emplace_back(CGSize{ glyphRunDetails._dwriteGlyphRun[i].glyphAdvances[index], 0.0f });
                xPos += glyphRunDetails._dwriteGlyphRun[i].glyphAdvances[index];
                line->_width += glyphRunDetails._dwriteGlyphRun[i].glyphAdvances[index];
            }

            [runs addObject:run];
            stringRange += run->_range.length;
            glyphCount += glyphRunDetails._dwriteGlyphRun[i].glyphCount;
            i++;
        }

        if ([runs count] > 0) {
            prevYPosForDraw = yPos;
            line->_runs = runs;
            line->_strRange.location = static_cast<_CTRun*>(line->_runs[0])->_range.location;
            line->_strRange.length = stringRange;
            line->_glyphCount = glyphCount;
            line->_relativeXOffset = static_cast<_CTRun*>(line->_runs[0])->_relativeXOffset;
            line->_relativeYOffset = static_cast<_CTRun*>(line->_runs[0])->_relativeYOffset;
            if (static_cast<_CTRun*>([line->_runs objectAtIndex:0])->_dwriteGlyphRun.glyphCount != 0) {
                line->_lineOrigin.x = static_cast<_CTRun*>(line->_runs[0])->_glyphOrigins[0].x;
                line->_lineOrigin.y = static_cast<_CTRun*>(line->_runs[0])->_glyphOrigins[0].y;
            }

            [frame->_lines addObject:line];
            frame->_lineOrigins.emplace_back(line->_lineOrigin);
        }
    }

    return frame;
}

// Represents a mapping between multiple representations of the same font weight across DWrite and CoreText
// DWRITE_FONT_WEIGHT_BOLD = kCTFontWeightBold
struct WeightMapping {
    DWRITE_FONT_WEIGHT dwriteValue;
    CGFloat ctValue;
};

// Mapping for weight
// Some loss of precision here as CT presents fewer values than DWrite
// Note also that Thin and Ultra/Extra-Light are in opposite order in DWrite and CoreText/UIKit constants
// (However, "Thin" fonts on the reference platform have UIFontWeightUltraLight...)
// clang-format off
static const struct WeightMapping c_weightMap[] = { { DWRITE_FONT_WEIGHT_THIN, kCTFontWeightUltraLight },
                                                    { DWRITE_FONT_WEIGHT_EXTRA_LIGHT, kCTFontWeightThin },
                                                    { DWRITE_FONT_WEIGHT_ULTRA_LIGHT, kCTFontWeightThin },
                                                    { DWRITE_FONT_WEIGHT_LIGHT, kCTFontWeightLight },
                                                    { DWRITE_FONT_WEIGHT_SEMI_LIGHT, kCTFontWeightLight },
                                                    { DWRITE_FONT_WEIGHT_NORMAL, kCTFontWeightRegular },
                                                    { DWRITE_FONT_WEIGHT_REGULAR, kCTFontWeightRegular },
                                                    { DWRITE_FONT_WEIGHT_MEDIUM, kCTFontWeightMedium },
                                                    { DWRITE_FONT_WEIGHT_DEMI_BOLD, kCTFontWeightSemibold },
                                                    { DWRITE_FONT_WEIGHT_SEMI_BOLD, kCTFontWeightSemibold },
                                                    { DWRITE_FONT_WEIGHT_BOLD, kCTFontWeightBold },
                                                    { DWRITE_FONT_WEIGHT_EXTRA_BOLD, kCTFontWeightHeavy },
                                                    { DWRITE_FONT_WEIGHT_ULTRA_BOLD, kCTFontWeightHeavy },
                                                    { DWRITE_FONT_WEIGHT_BLACK, kCTFontWeightBlack },
                                                    { DWRITE_FONT_WEIGHT_HEAVY, kCTFontWeightBlack },
                                                    { DWRITE_FONT_WEIGHT_EXTRA_BLACK, kCTFontWeightBlack },
                                                    { DWRITE_FONT_WEIGHT_ULTRA_BLACK, kCTFontWeightBlack } };
// clang-format on

/**
 * Creates an IDWriteFontFace given the attributes of a CTFontDescriptor
 * Currently, font name, family name, kCTFontWeight/Slant/Width, and part of SymbolicTrait, are taken into account
 */
HRESULT _DWriteCreateFontFaceWithFontDescriptor(CTFontDescriptorRef fontDescriptor, IDWriteFontFace** outFontFace) {
    CFStringRef fontName = static_cast<CFStringRef>(CFAutorelease(CTFontDescriptorCopyAttribute(fontDescriptor, kCTFontNameAttribute)));
    CFStringRef familyName =
        static_cast<CFStringRef>(CFAutorelease(CTFontDescriptorCopyAttribute(fontDescriptor, kCTFontFamilyNameAttribute)));

    // font name takes precedence
    if (fontName) {
        if (familyName && !CFEqual(familyName, _DWriteGetFamilyNameForFontName(fontName))) {
            TraceError(TAG,
                       L"Mismatched font name \"%hs\" and family name \"%hs\"",
                       [static_cast<NSString*>(fontName) UTF8String],
                       [static_cast<NSString*>(familyName) UTF8String]);
            return E_INVALIDARG;
        }

        // familyName is either valid for fontName, or unspecified
        // just use fontName, then
        return _DWriteCreateFontFaceWithName(fontName, outFontFace);
    }

    // otherwise, look at family name and other attributes
    if (familyName) {
        DWRITE_FONT_WEIGHT weight = DWRITE_FONT_WEIGHT_NORMAL;
        DWRITE_FONT_STRETCH stretch = DWRITE_FONT_STRETCH_NORMAL;
        DWRITE_FONT_STYLE style = DWRITE_FONT_STYLE_NORMAL;

        // Look for traits that may specify weight, stretch, style
        CFDictionaryRef traits =
            static_cast<CFDictionaryRef>(CFAutorelease(CTFontDescriptorCopyAttribute(fontDescriptor, kCTFontTraitsAttribute)));

        if (traits) {
            // kCTFontWeightTrait, kCTFontWidthTrait, kCTFontSlantTrait take precedence over symbolic traits
            CFNumberRef weightTrait = static_cast<CFNumberRef>(CFDictionaryGetValue(traits, kCTFontWeightTrait));
            CFNumberRef widthTrait = static_cast<CFNumberRef>(CFDictionaryGetValue(traits, kCTFontWidthTrait));
            CFNumberRef slantTrait = static_cast<CFNumberRef>(CFDictionaryGetValue(traits, kCTFontSlantTrait));

            CFNumberRef cfSymbolicTrait = static_cast<CFNumberRef>(CFDictionaryGetValue(traits, kCTFontSymbolicTrait));
            uint32_t symbolicTrait = cfSymbolicTrait ? _CTFontSymbolicTraitsFromCFNumber(cfSymbolicTrait) : 0;

            if (weightTrait) {
                CGFloat weightFloat;
                CFNumberGetValue(weightTrait, kCFNumberCGFloatType, &weightFloat);

                // Consult c_weightMap
                for (const auto& weightMapping : c_weightMap) {
                    if (weightFloat == weightMapping.ctValue) {
                        weight = weightMapping.dwriteValue;
                        break;
                    }
                }
            } else if (symbolicTrait & kCTFontBoldTrait) {
                weight = DWRITE_FONT_WEIGHT_BOLD;
            }

            if (widthTrait) {
                CGFloat widthFloat;
                CFNumberGetValue(widthTrait, kCFNumberCGFloatType, &widthFloat);

                // Treat above 0 as expanded, below 0 as condensed
                if (widthFloat > 0) {
                    stretch = DWRITE_FONT_STRETCH_EXPANDED;
                } else if (widthFloat < 0) {
                    stretch = DWRITE_FONT_STRETCH_CONDENSED;
                }
            } else if (symbolicTrait & kCTFontExpandedTrait) {
                stretch = DWRITE_FONT_STRETCH_EXPANDED;
            } else if (symbolicTrait & kCTFontCondensedTrait) {
                stretch = DWRITE_FONT_STRETCH_CONDENSED;
            }

            if (slantTrait) {
                CGFloat slantFloat;
                CFNumberGetValue(slantTrait, kCFNumberCGFloatType, &slantFloat);

                // Treat anything above 0 as italic
                if (slantFloat > 0) {
                    style = DWRITE_FONT_STYLE_ITALIC;
                }
            } else if (symbolicTrait & kCTFontItalicTrait) {
                style = DWRITE_FONT_STYLE_ITALIC;
            }
        }

        // Create a best matching font based on the family name and weight/stretch/style
        ComPtr<IDWriteFontFamily> fontFamily;
        RETURN_IF_FAILED(_DWriteCreateFontFamilyWithName(familyName, &fontFamily));
        RETURN_HR_IF_NULL(E_INVALIDARG, fontFamily);

        ComPtr<IDWriteFont> font;
        RETURN_IF_FAILED(fontFamily->GetFirstMatchingFont(weight, stretch, style, &font));

        return font->CreateFontFace(outFontFace);
    }

    TraceError(TAG, L"Must specify either kCTFontFamilyNameAttribute or kCTFontNameAttribute in font descriptor");
    return E_INVALIDARG;
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
 * Helper function that converts a DWRITE_FONT_WEIGHT into a float usable for kCTFontWeightTrait.
 */
CGFloat __DWriteGetCTFontWeight(DWRITE_FONT_WEIGHT weight) {
    for (const auto& weightMapping : c_weightMap) {
        if (weight == weightMapping.dwriteValue) {
            return weightMapping.ctValue;
        }
    }

    return kCTFontWeightRegular;
}

/**
 * Helper function that converts a DWRITE_FONT_STRETCH into a float usable for kCTFontWidthTrait.
 */
CGFloat __DWriteGetCTFontWidth(DWRITE_FONT_STRETCH stretch) {
    // kCTFontWidthTrait is documented to range from -1.0 to 1.0, centered at 0,
    // with 'Condensed' fonts returning -0.2 on the reference platform
    // DWrite stretch ranges from 0-9, centered at 5

    // Reference platform lacks fonts with stretch besides 'normal' or 'condensed',
    // and it is not yet clear how these values are used
    // Do an approximate conversion for now
    return (static_cast<float>(stretch) / 10.0f) - 0.5f;
}

/**
 * Helper function that reads certain properties from a DWrite font face,
 * then parses them into a dictionary suitable for kCTFontTraitsAttribute
 */
static CFDictionaryRef _DWriteFontCreateTraitsDict(const ComPtr<IDWriteFontFace>& fontFace) {
    // Get pointers for the additional FontFace interfaces
    ComPtr<IDWriteFontFace1> fontFace1;
    RETURN_NULL_IF_FAILED(fontFace.As(&fontFace1));
    ComPtr<IDWriteFontFace2> fontFace2;
    RETURN_NULL_IF_FAILED(fontFace.As(&fontFace2));
    ComPtr<IDWriteFontFace3> fontFace3;
    RETURN_NULL_IF_FAILED(fontFace.As(&fontFace3));

    DWRITE_FONT_WEIGHT weight = fontFace3->GetWeight();
    DWRITE_FONT_STRETCH stretch = fontFace3->GetStretch();
    DWRITE_FONT_STYLE style = fontFace3->GetStyle();

    CGFloat weightTrait = __DWriteGetCTFontWeight(weight);
    CGFloat widthTrait = __DWriteGetCTFontWidth(stretch);

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

    if (fontFace2->IsColorFont()) {
        symbolicTraits |= kCTFontColorGlyphsTrait;
    }

    // TODO: The symbolic traits below are poorly documented/have no clear DWrite mapping
    // if (fontFace->IsFoo()) {
    //     symbolicTraits |= kCTFontUIOptimizedTrait;
    // }
    // if (fontFace->IsFoo()) {
    //     symbolicTraits |= kCTFontCompositeTrait;
    // }

    // TODO: The upper 16 bits of symbolic traits describe stylistic aspects of a font, specifically its serifs,
    // such as modern, ornamental, or sans (no serifs)
    // DWrite has no such API for characterizing fonts
    // if (fontFace->IsFoo()) {
    //     symbolicTraits |= kCTFontOldStyleSerifsClass;
    // }

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
CFStringRef _DWriteFontCopyName(const ComPtr<IDWriteFontFace>& fontFace, CFStringRef nameKey) {
    if (nameKey == nullptr || fontFace == nullptr) {
        return nullptr;
    }

    DWRITE_INFORMATIONAL_STRING_ID informationalStringId;

    if (CFEqual(nameKey, kCTFontCopyrightNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_COPYRIGHT_NOTICE;
    } else if (CFEqual(nameKey, kCTFontFamilyNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_WIN32_FAMILY_NAMES;
    } else if (CFEqual(nameKey, kCTFontSubFamilyNameKey)) {
        informationalStringId = DWRITE_INFORMATIONAL_STRING_WIN32_SUBFAMILY_NAMES;
    } else if (CFEqual(nameKey, kCTFontStyleNameKey)) {
        ComPtr<IDWriteFontFace3> dwriteFontFace3;
        RETURN_NULL_IF_FAILED(fontFace.As(&dwriteFontFace3));
        ComPtr<IDWriteLocalizedStrings> name;
        RETURN_NULL_IF_FAILED(dwriteFontFace3->GetFaceNames(&name));
        return static_cast<CFStringRef>(CFRetain(_CFStringFromLocalizedString(name.Get())));

    } else if (CFEqual(nameKey, kCTFontUniqueNameKey)) {
        return CFStringCreateWithFormat(kCFAllocatorDefault,
                                        nullptr,
                                        CFSTR("%@ %@"),
                                        CFAutorelease(_DWriteFontCopyName(fontFace, kCTFontFullNameKey)),
                                        CFAutorelease(_DWriteFontCopyName(fontFace, kCTFontStyleNameKey)));

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

    return _DWriteFontCopyInformationalString(fontFace, informationalStringId);
}