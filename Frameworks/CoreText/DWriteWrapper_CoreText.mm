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

#include <COMIncludes.h>
#import <wrl/implements.h>
#include <COMIncludes_End.h>

#import "DWriteWrapper_CoreText.h"
#import "CoreTextInternal.h"
#import "CGContextInternal.h"

#import <LoggingNative.h>
#import <StringHelpers.h>
#import <vector>
#import <iterator>
#import <numeric>

using namespace std;
using namespace Microsoft::WRL;

static const wchar_t* TAG = L"_DWriteWrapper_CoreText";

static inline DWRITE_TEXT_ALIGNMENT __CTAlignmentToDWrite(CTTextAlignment alignment) {
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

static inline DWRITE_WORD_WRAPPING __CTLineBreakModeToDWrite(CTLineBreakMode lineBreakMode) {
    switch (lineBreakMode) {
        // TODO 1121:: DWrite does not support line breaking by truncation, so just use clipping for now
        case kCTLineBreakByTruncatingHead:
        case kCTLineBreakByTruncatingTail:
        case kCTLineBreakByTruncatingMiddle:
        case kCTLineBreakByClipping:
            return DWRITE_WORD_WRAPPING_NO_WRAP;
        case kCTLineBreakByCharWrapping:
            return DWRITE_WORD_WRAPPING_CHARACTER;
        case kCTLineBreakByWordWrapping:
        default:
            return DWRITE_WORD_WRAPPING_WRAP;
    }
}

template <typename TElement>
static bool __CloneArray(_In_reads_opt_(count) TElement const* source,
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

bool _CloneDWriteGlyphRun(_In_ DWRITE_GLYPH_RUN const* src, _Outptr_ DWRITE_GLYPH_RUN* dest) {
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
 * Private helper that applies a CTParagraphStyleRef to an IDWriteTextFormat
 */
static inline HRESULT __DWriteTextFormatApplyParagraphStyle(const ComPtr<IDWriteTextFormat>& textFormat, CTParagraphStyleRef settings) {
    CTTextAlignment alignment = kCTNaturalTextAlignment;
    if (CTParagraphStyleGetValueForSpecifier(settings, kCTParagraphStyleSpecifierAlignment, sizeof(CTTextAlignment), &alignment)) {
        if (alignment != kCTNaturalTextAlignment) {
            RETURN_IF_FAILED(textFormat->SetTextAlignment(__CTAlignmentToDWrite(alignment)));
        }
    }

    CTWritingDirection direction;
    if (CTParagraphStyleGetValueForSpecifier(settings, kCTParagraphStyleSpecifierBaseWritingDirection, sizeof(direction), &direction)) {
        if (direction != kCTWritingDirectionNatural) {
            DWRITE_READING_DIRECTION dwriteDirection = DWRITE_READING_DIRECTION_LEFT_TO_RIGHT;
            if (direction == kCTWritingDirectionRightToLeft) {
                dwriteDirection = DWRITE_READING_DIRECTION_RIGHT_TO_LEFT;

                // DWrite alignment is based upon reading direction whereas CoreText alignment is constant
                // so we have to flip the writing direction
                if (alignment == kCTRightTextAlignment || alignment == kCTNaturalTextAlignment) {
                    RETURN_IF_FAILED(textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING));
                } else if (alignment == kCTLeftTextAlignment) {
                    RETURN_IF_FAILED(textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_TRAILING));
                }
            }

            RETURN_IF_FAILED(textFormat->SetReadingDirection(dwriteDirection));
        }
    }

    CTLineBreakMode lineBreakMode;
    if (CTParagraphStyleGetValueForSpecifier(settings, kCTParagraphStyleSpecifierLineBreakMode, sizeof(lineBreakMode), &lineBreakMode)) {
        RETURN_IF_FAILED(textFormat->SetWordWrapping(__CTLineBreakModeToDWrite(lineBreakMode)));
    }

    return S_OK;
}

/**
 * Private helper that applies a CTFontRef to an IDWriteTextLayout within the specified range.
 */
static inline HRESULT __DWriteTextLayoutApplyFont(const ComPtr<IDWriteTextLayout>& textLayout, CTFontRef font, DWRITE_TEXT_RANGE range) {
    auto fontName = woc::MakeAutoCF<CFStringRef>(CTFontCopyName(font, kCTFontFullNameKey));
    std::shared_ptr<const _DWriteFontProperties> properties = _DWriteGetFontPropertiesFromName(fontName);
    RETURN_IF_FAILED(textLayout->SetFontWeight(properties->weight, range));
    RETURN_IF_FAILED(textLayout->SetFontStretch(properties->stretch, range));
    RETURN_IF_FAILED(textLayout->SetFontStyle(properties->style, range));

    RETURN_IF_FAILED(textLayout->SetFontSize(CTFontGetSize(font), range));
    RETURN_IF_FAILED(
        textLayout->SetFontFamilyName(reinterpret_cast<wchar_t*>(Strings::VectorFromCFString(properties->familyName.get()).data()), range));

    return S_OK;
}

/**
 * Private helper that applies extra kerning to an IDWriteTextLayout within the specified range.
 */
static inline HRESULT __DWriteTextLayoutApplyExtraKerning(const ComPtr<IDWriteTextLayout>& textLayout,
                                                          const ComPtr<IDWriteTypography>& typography,
                                                          CFNumberRef extraKerningRef,
                                                          DWRITE_TEXT_RANGE range) {
    ComPtr<IDWriteTextLayout1> textLayout1;
    RETURN_IF_FAILED(textLayout.As(&textLayout1));

    CGFloat extraKerning;
    CFNumberGetValue(extraKerningRef, kCFNumberFloatType, &extraKerning);

    CGFloat leadingSpacing, trailingSpacing, minimumAdvanceWidth;
    RETURN_IF_FAILED(textLayout1->GetCharacterSpacing(range.startPosition, &leadingSpacing, &trailingSpacing, &minimumAdvanceWidth));
    RETURN_IF_FAILED(textLayout1->SetCharacterSpacing(leadingSpacing, trailingSpacing + extraKerning, minimumAdvanceWidth, range));

    // Setting kern disables default kerning
    RETURN_IF_FAILED(typography->AddFontFeature({ DWRITE_FONT_FEATURE_TAG_KERNING, 0 }));

    return S_OK;
}

/**
 * Helper method to create a IDWriteTextFormat object given _CTTypesetter object and string range.
 *
 * @parameter ts _CTTypesetter object.
 * @parameter range string range to consider for rendering.
 * @parameter outTextFormat outpointer for creating the text format
 *
 * @return whether the creation was successful
 */
static HRESULT __DWriteTextFormatCreate(CFAttributedStringRef string, CFRange range, IDWriteTextFormat** outTextFormat) {
    RETURN_HR_IF_NULL(E_POINTER, outTextFormat);

    // TODO::
    // Note here we only look at attribute value at first index of the specified range as we can get a default font size to use here.
    // Per string range attribute handling will be done in _CreateDWriteTextLayout.
    CTFontRef font = static_cast<CTFontRef>(CFAttributedStringGetAttribute(string, range.location, kCTFontAttributeName, nullptr));

    woc::unique_cf<CFStringRef> fontFullName;
    CGFloat fontSize = kCTFontSystemFontSize;

    if (font) {
        fontFullName.reset(CTFontCopyName(font, kCTFontFullNameKey));
        fontSize = CTFontGetSize(font);
    }

    ComPtr<IDWriteTextFormat> textFormat;
    RETURN_IF_FAILED(_DWriteCreateTextFormatWithFontNameAndSize(fontFullName.get(), fontSize, &textFormat));

    // Apply paragraph style if one exists in the attributed string
    CTParagraphStyleRef settings =
        static_cast<CTParagraphStyleRef>(CFAttributedStringGetAttribute(string, range.location, kCTParagraphStyleAttributeName, nullptr));
    if (settings) {
        RETURN_IF_FAILED(__DWriteTextFormatApplyParagraphStyle(textFormat, settings));
    }

    *outTextFormat = textFormat.Detach();
    return S_OK;
}

/**
 * Helper method to create a IDWriteTextLayout object given _CTTypesetter object, string range and frame size constrain.
 *
 * @parameter CFAttributedStringRef string with text and attributes
 * @parameter range string range to consider for rendering.
 * @parameter frameSize frame constrains to render the text on.
 * @parameter outTextLayout outpointer for creating the text layout
 *
 * @return whether the creation was successful
 */
static HRESULT __DWriteTextLayoutCreate(CFAttributedStringRef string, CFRange range, CGRect frameSize, IDWriteTextLayout** outTextLayout) {
    RETURN_HR_IF_NULL(E_POINTER, outTextLayout);

    ComPtr<IDWriteTextFormat> textFormat;
    RETURN_IF_FAILED(__DWriteTextFormatCreate(string, range, &textFormat));

    // TODO::
    // We need too support widthFunc semantic to be able to support NSLayout*. We could either change the API signature of this API or
    // create a new API to support dynamic width support.
    //
    // float width = widthFunc(widthParam, 0, 0, fontSize);

    // Get the direct write factory instance
    ComPtr<IDWriteFactory> dwriteFactory;
    RETURN_IF_FAILED(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &dwriteFactory));

    woc::unique_cf<CFStringRef> substring(CFStringCreateWithSubstring(kCFAllocatorDefault, CFAttributedStringGetString(string), range));
    ComPtr<IDWriteTextLayout> textLayout;
    RETURN_IF_FAILED(dwriteFactory->CreateTextLayout(reinterpret_cast<wchar_t*>(Strings::VectorFromCFString(substring.get()).data()),
                                                     CFStringGetLength(substring.get()),
                                                     textFormat.Get(),
                                                     frameSize.size.width,
                                                     frameSize.size.height,
                                                     &textLayout));

    // TODO::
    // Iterate through all attributed string ranges and identify attributes so they can be used to -
    //  - set indentation
    //  - etc.
    //  These can be done using the DWrite IDWriteTextFormat range property methods.
    CFIndex rangeEnd = range.location + range.length;

    // Used to separate runs for attributes which DWrite does not handle until drawing (e.g. Foreground Color)
    uint32_t incompatibleAttributeFlag = 0;
    CFRange attributeRange;
    for (CFIndex index = range.location; index < rangeEnd; index += attributeRange.length) {
        CTFontRef font = static_cast<CTFontRef>(CFAttributedStringGetAttribute(string, index, kCTFontAttributeName, &attributeRange));

        // attributeRange is populated even if this attribute is not found
        const DWRITE_TEXT_RANGE dwriteRange = { attributeRange.location, attributeRange.length };
        if (font) {
            RETURN_IF_FAILED(__DWriteTextLayoutApplyFont(textLayout, font, dwriteRange));
        }

        ComPtr<IDWriteTypography> typography;
        RETURN_IF_FAILED(textLayout->GetTypography(dwriteRange.startPosition, &typography));
        if (!typography.Get()) {
            RETURN_IF_FAILED(dwriteFactory->CreateTypography(&typography));
        }

        CFNumberRef extraKerningRef =
            static_cast<CFNumberRef>(CFAttributedStringGetAttribute(string, index, kCTKernAttributeName, nullptr));
        if (extraKerningRef) {
            RETURN_IF_FAILED(__DWriteTextLayoutApplyExtraKerning(textLayout, typography, extraKerningRef, dwriteRange));
        } else {
            // Otherwise set kerning to true, as it will default to no kerning and this can be used to signify noncompatible features
            // Forces run breaks without interfering with any layout features
            // Necessary for attributes which DWrite does not support during layout (e.g. Color)
            RETURN_IF_FAILED(typography->AddFontFeature({ DWRITE_FONT_FEATURE_TAG_KERNING, ++incompatibleAttributeFlag }));
        }

        RETURN_IF_FAILED(textLayout->SetTypography(typography.Get(), dwriteRange));
    }

    *outTextLayout = textLayout.Detach();
    return S_OK;
}

/**
 * Custom IDWriteTextRenderer class that captures the glyph runs generated by DWrite for the given TextLayout and TextRenderer constraints.
 */
class CustomDWriteTextRenderer : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IDWriteTextRenderer> {
protected:
    InspectableClass(L"Windows.Bridge.DirectWrite.CustomDWriteTextRenderer", TrustLevel::BaseTrust);

public:
    CustomDWriteTextRenderer() {
    }

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
        glyphRunDescriptionInfo._clusterMap.reserve(glyphRun->glyphCount);
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
        *transform = { 1, 0, 0, 1, 0, 0 };
        return S_OK;
    };

    HRESULT STDMETHODCALLTYPE GetPixelsPerDip(_In_opt_ void* clientDrawingContext, _Out_ float* pixelsPerDip) throw() {
        *pixelsPerDip = 1.0;
        return S_OK;
    };
};

/**
 * Helper method to create _CTLine object given a CFAttributedStringRef
 *
 * @parameter string CFAttributedStringRef containing text and styling
 *
 * @return Unmutable array of _CTLine objects created with the requested parameters.
 */
static CTLineRef _DWriteCreateLine(CFAttributedStringRef string) {
    CFRange range = CFRangeMake(0, CFAttributedStringGetLength(string));
    CTFrameRef frame = _DWriteGetFrame(string, range, CGRectMake(0, 0, FLT_MAX, FLT_MAX));
    if (CFArrayGetCount(frame->_lines) > 0) {
        return static_cast<CTLineRef>(CFRetain(CFArrayGetValueAtIndex(frame->_lines, 0)));
    }

    return _CTLineCreate();
}

/**
 * Helper method to create _CTLine objects given a CFAttributedStringRef, attributed string range to use and frame size to fit in.
 *
 * @parameter CFAttributedStringRef with text and attributes
 * @parameter range attributed string range to use.
 * @parameter frameSize size parameters of the frame to fit the text into.
 *
 * @return CTFrameRef created using the given parameters
 */
static CTFrameRef _DWriteGetFrame(CFAttributedStringRef string, CFRange range, CGRect frameSize) {
    RETURN_NULL_IF(!string);

    __CTFrame* frame = __CTFrame::CreateInstance(kCFAllocatorDefault);
    CFAutorelease(frame);

    RETURN_RESULT_IF(range.length <= 0, frame);

    ComPtr<IDWriteTextLayout> textLayout;
    RETURN_NULL_IF_FAILED(__DWriteTextLayoutCreate(string, range, frameSize, &textLayout));

    // Call custom renderer to get all glyph run details
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

    // Relative offsets for each run and line that will be used by CTLineDraw and CTRunDraw methods to render.
    float prevXPosForDraw = 0;
    float prevYPosForDraw = 0;

    while (i < numOfGlyphRuns) {
        auto line = woc::MakeStrongCF<__CTLine*>(const_cast<__CTLine*>(_CTLineCreate()));

        auto runs = woc::MakeStrongCF<CFMutableArrayRef>(CFArrayCreateMutable(kCFAllocatorDefault, 0, &kCFTypeArrayCallBacks));
        uint32_t stringRange = 0;
        uint32_t glyphCount = 0;
        prevXPosForDraw = 0;

        float xPos;
        float yPos;

        // These are created lazily in the first call to CTLineGetTypographicBounds, so initialize with impossible values
        line->_ascent = -FLT_MAX;
        line->_descent = -FLT_MAX;
        line->_leading = -FLT_MAX;

        // Glyph runs that have the same _baselineOriginY value are part of the the same Line.
        float baselineOriginYForCurrentLine = glyphRunDetails._baselineOriginY[i];

        // Iterate through runs on the current line
        for (j = i; (j < numOfGlyphRuns) && (glyphRunDetails._baselineOriginY[j] == baselineOriginYForCurrentLine); ++j) {
            // Create _CTRun objects and make them part of _CTLine
            auto runRef = woc::MakeStrongCF<CTRunRef>(_CTRunCreate());
            __CTRun* run = const_cast<__CTRun*>(runRef.get());

            run->_range.location = glyphRunDetails._glyphRunDescriptions[j]._textPosition;
            run->_range.length = glyphRunDetails._glyphRunDescriptions[j]._stringLength;

            run->_stringFragment.attach(
                CFStringCreateWithSubstring(nullptr,
                                            CFAttributedStringGetString(string),
                                            CFRangeMake(range.location + run->_range.location, run->_range.length)));
            run->_dwriteGlyphRun = move(glyphRunDetails._dwriteGlyphRun[j]);
            run->_stringIndices = move(glyphRunDetails._glyphRunDescriptions[j]._clusterMap);
            run->_attributes = const_cast<CFMutableDictionaryRef>(
                CFAttributedStringGetAttributes(string, (range.location + run->_range.location), nullptr));

            xPos = glyphRunDetails._baselineOriginX[j];
            yPos = glyphRunDetails._baselineOriginY[j];

            // Calculate the relative offset of each glyph run and store it. This will be useful while drawing individual glpyh runs or
            // lines.
            run->_relativeXOffset = xPos - prevXPosForDraw;
            run->_relativeYOffset = yPos - prevYPosForDraw;
            prevXPosForDraw = xPos;

            // TODO::
            // This is a temp workaround until we can have actual glyph origins
            run->_glyphOrigins.reserve(glyphRunDetails._dwriteGlyphRun[j].glyphCount);
            run->_glyphAdvances.reserve(glyphRunDetails._dwriteGlyphRun[j].glyphCount);
            for (int index = 0; index < glyphRunDetails._dwriteGlyphRun[j].glyphCount; index++) {
                run->_glyphOrigins.emplace_back(CGPoint{ xPos, yPos });
                run->_glyphAdvances.emplace_back(CGSize{ glyphRunDetails._dwriteGlyphRun[j].glyphAdvances[index], 0.0f });
                xPos += glyphRunDetails._dwriteGlyphRun[j].glyphAdvances[index];
                line->_width += glyphRunDetails._dwriteGlyphRun[j].glyphAdvances[index];
            }

            CFArrayAppendValue(runs, run);
            stringRange += run->_range.length;
            glyphCount += glyphRunDetails._dwriteGlyphRun[j].glyphCount;
        }

        // Fast-forward i to start on the next line
        i = j;

        if (CFArrayGetCount(runs) > 0) {
            prevYPosForDraw = yPos;
            line->_runs = runs.get();
            CTRunRef firstRun = static_cast<CTRunRef>(CFArrayGetValueAtIndex(runs, 0));
            line->_strRange.location = firstRun->_range.location;
            line->_strRange.length = stringRange;
            line->_glyphCount = glyphCount;
            line->_relativeXOffset = firstRun->_relativeXOffset;
            if (_GlyphRunIsRTL(firstRun->_dwriteGlyphRun)) {
                // First run is RTL so line's offset is position isn't the same
                line->_relativeXOffset -= line->_width;
            }

            CGPoint lineOrigin = CGPointZero;
            if (firstRun->_dwriteGlyphRun.glyphCount != 0) {
                lineOrigin = { firstRun->_glyphOrigins[0].x, firstRun->_glyphOrigins[0].y };
            }

            CFArrayAppendValue(frame->_lines, line);
            frame->_lineOrigins.emplace_back(lineOrigin);
        }
    }

    return frame;
}

static CGSize _DWriteGetFrameSize(CFAttributedStringRef string, CFRange range, CGSize maxSize, CFRange* fitRange) {
    CGSize ret = CGSizeZero;

    // Treat range.length of 0 as unlimited length
    if (range.length == 0L) {
        range.length = CFAttributedStringGetLength(string) - range.location;
    }

    // No text to draw, just return CGSizeZero
    if (!string || range.length <= 0L) {
        return ret;
    }

    ComPtr<IDWriteTextLayout> textLayout;
    if (FAILED(__DWriteTextLayoutCreate(string, range, { CGPointZero, maxSize }, &textLayout))) {
        return ret;
    }

    DWRITE_TEXT_METRICS textMetrics;
    if (FAILED(textLayout->GetMetrics(&textMetrics))) {
        return ret;
    }

    // TODO:: find more precise value than 1.0 to increase width by to fully enclose frame
    ret.width = std::min(maxSize.width, textMetrics.widthIncludingTrailingWhitespace + 1.0f);
    ret.height = std::min(maxSize.height, textMetrics.height);

    if (fitRange) {
        *fitRange = { range.location, 0L };
        uint32_t lineCount = 0;

        // Should return E_NOT_SUFFICIENT_BUFFER and popluate lineCount
        if (textLayout->GetLineMetrics(nullptr, 0, &lineCount) != E_NOT_SUFFICIENT_BUFFER) {
            return ret;
        }

        std::vector<DWRITE_LINE_METRICS> metrics(lineCount);
        if (FAILED(textLayout->GetLineMetrics(metrics.data(), lineCount, &lineCount))) {
            return ret;
        }

        float totalHeight = 0;
        CFIndex endPos = range.location;
        for (auto metric : metrics) {
            totalHeight += metric.baseline;
            if (totalHeight > ret.height) {
                break;
            }
            endPos += metric.length;
        }

        fitRange->length = endPos;
    }

    return ret;
}