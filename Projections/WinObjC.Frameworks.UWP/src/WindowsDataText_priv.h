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

// WindowsDataText_priv.h
// Forward decls for private object generation
#pragma once

static ComPtr<ABI::Windows::Data::Text::ISemanticTextQueryFactory> WDTISemanticTextQueryFactory_inst();
ComPtr<ABI::Windows::Data::Text::IUnicodeCharactersStatics> WDTIUnicodeCharactersStatics_inst();
static ComPtr<ABI::Windows::Data::Text::IWordsSegmenterFactory> WDTIWordsSegmenterFactory_inst();
static ComPtr<ABI::Windows::Data::Text::ISelectableWordsSegmenterFactory> WDTISelectableWordsSegmenterFactory_inst();
static ComPtr<ABI::Windows::Data::Text::ITextPredictionGeneratorFactory> WDTITextPredictionGeneratorFactory_inst();
static ComPtr<ABI::Windows::Data::Text::ITextConversionGeneratorFactory> WDTITextConversionGeneratorFactory_inst();
static ComPtr<ABI::Windows::Data::Text::ITextReverseConversionGeneratorFactory> WDTITextReverseConversionGeneratorFactory_inst();
@interface WDTTextSegment (Internal)
+ (instancetype)createWith:(ABI::Windows::Data::Text::TextSegment)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Data::Text::TextSegment*)internalStruct;
@end
inline WDTTextSegment* WDTTextSegment_create(ABI::Windows::Data::Text::TextSegment val) {
    return [WDTTextSegment createWith:val];
}

id RTProxiedIterableNSArray_WDTSelectableWordSegment_create(IInspectable* val);
id RTProxiedIterableNSArray_WDTWordSegment_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WDTAlternateWordForm_create(IInspectable* val);
id RTProxiedNSArray_WDTSelectableWordSegment_create(IInspectable* val);
id RTProxiedNSArray_WDTTextPhoneme_create(IInspectable* val);
id RTProxiedNSArray_WDTTextSegment_create(IInspectable* val);
id RTProxiedNSArray_WDTWordSegment_create(IInspectable* val);

@class RTProxiedIterableNSArray_WDTSelectableWordSegment, RTProxiedIterableNSArray_WDTWordSegment, RTProxiedNSArray_NSString,
    RTProxiedNSArray_WDTAlternateWordForm;
@class RTProxiedNSArray_WDTSelectableWordSegment, RTProxiedNSArray_WDTTextPhoneme, RTProxiedNSArray_WDTTextSegment,
    RTProxiedNSArray_WDTWordSegment;

#ifndef __WDTSelectableWordSegmentsTokenizingHandler_shim__DEFINED
#define __WDTSelectableWordSegmentsTokenizingHandler_shim__DEFINED
class WDTSelectableWordSegmentsTokenizingHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Data::Text::ISelectableWordSegmentsTokenizingHandler> {
    void (^_delegate)(id<NSFastEnumeration> /* WDTSelectableWordSegment* */, id<NSFastEnumeration> /* WDTSelectableWordSegment* */);

public:
    WDTSelectableWordSegmentsTokenizingHandler_shim(void (^del)(id<NSFastEnumeration> /* WDTSelectableWordSegment* */,
                                                                id<NSFastEnumeration> /* WDTSelectableWordSegment* */))
        : _delegate([del copy]) {
    }
    ~WDTSelectableWordSegmentsTokenizingHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IIterable<ABI::Windows::Data::Text::SelectableWordSegment*>* arg0,
                                             IIterable<ABI::Windows::Data::Text::SelectableWordSegment*>* arg1) override {
        @autoreleasepool {
            _delegate(RTProxiedIterableNSArray_WDTSelectableWordSegment_create(arg0),
                      RTProxiedIterableNSArray_WDTSelectableWordSegment_create(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WDTWordSegmentsTokenizingHandler_shim__DEFINED
#define __WDTWordSegmentsTokenizingHandler_shim__DEFINED
class WDTWordSegmentsTokenizingHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Data::Text::IWordSegmentsTokenizingHandler> {
    void (^_delegate)(id<NSFastEnumeration> /* WDTWordSegment* */, id<NSFastEnumeration> /* WDTWordSegment* */);

public:
    WDTWordSegmentsTokenizingHandler_shim(void (^del)(id<NSFastEnumeration> /* WDTWordSegment* */,
                                                      id<NSFastEnumeration> /* WDTWordSegment* */))
        : _delegate([del copy]) {
    }
    ~WDTWordSegmentsTokenizingHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IIterable<ABI::Windows::Data::Text::WordSegment*>* arg0,
                                             IIterable<ABI::Windows::Data::Text::WordSegment*>* arg1) override {
        @autoreleasepool {
            _delegate(RTProxiedIterableNSArray_WDTWordSegment_create(arg0), RTProxiedIterableNSArray_WDTWordSegment_create(arg1));
            return 0;
        };
    }
};
#endif
