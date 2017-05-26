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

// WindowsDataText.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Data.Text.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDataText.h"
#include "WindowsDataText_priv.h"

@implementation WDTSemanticTextQuery

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Text::ISemanticTextQuery> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Data::Text::ISemanticTextQueryFactory> WDTISemanticTextQueryFactory_inst() {
    ComPtr<ABI::Windows::Data::Text::ISemanticTextQueryFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Data.Text.SemanticTextQuery").Get(), &inst));
    return inst;
}

+ (WDTSemanticTextQuery*)make:(NSString*)aqsFilter {
    ComPtr<ABI::Windows::Data::Text::ISemanticTextQuery> unmarshalledReturn;
    auto _comInst = WDTISemanticTextQueryFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(aqsFilter).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDTSemanticTextQuery>(unmarshalledReturn.Get()) retain];
}

+ (WDTSemanticTextQuery*)makeWithLanguage:(NSString*)aqsFilter filterLanguage:(NSString*)filterLanguage {
    ComPtr<ABI::Windows::Data::Text::ISemanticTextQuery> unmarshalledReturn;
    auto _comInst = WDTISemanticTextQueryFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithLanguage(nsStrToHstr(aqsFilter).Get(), nsStrToHstr(filterLanguage).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDTSemanticTextQuery>(unmarshalledReturn.Get()) retain];
}

- (NSArray* /* WDTTextSegment* */)find:(NSString*)content {
    ComPtr<IVectorView<ABI::Windows::Data::Text::TextSegment>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ISemanticTextQuery>(self);
    THROW_NS_IF_FAILED(_comInst->Find(nsStrToHstr(content).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDTTextSegment_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDTTextSegment* */)findInProperty:(NSString*)propertyContent propertyName:(NSString*)propertyName {
    ComPtr<IVectorView<ABI::Windows::Data::Text::TextSegment>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ISemanticTextQuery>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindInProperty(nsStrToHstr(propertyContent).Get(), nsStrToHstr(propertyName).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDTTextSegment_create(unmarshalledReturn.Get());
}

@end

@implementation WDTUnicodeCharacters

ComPtr<ABI::Windows::Data::Text::IUnicodeCharactersStatics> WDTIUnicodeCharactersStatics_inst() {
    ComPtr<ABI::Windows::Data::Text::IUnicodeCharactersStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Data.Text.UnicodeCharacters").Get(), &inst));
    return inst;
}

+ (unsigned int)getCodepointFromSurrogatePair:(unsigned int)highSurrogate lowSurrogate:(unsigned int)lowSurrogate {
    unsigned int unmarshalledReturn;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetCodepointFromSurrogatePair(highSurrogate, lowSurrogate, &unmarshalledReturn));
    return unmarshalledReturn;
}

+ (void)getSurrogatePairFromCodepoint:(unsigned int)codepoint highSurrogate:(wchar_t*)highSurrogate lowSurrogate:(wchar_t*)lowSurrogate {
    wchar_t highSurrogateOutUnmarshaled;
    wchar_t lowSurrogateOutUnmarshaled;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetSurrogatePairFromCodepoint(codepoint, &highSurrogateOutUnmarshaled, &lowSurrogateOutUnmarshaled));
    *highSurrogate = highSurrogateOutUnmarshaled;
    *lowSurrogate = lowSurrogateOutUnmarshaled;
}

+ (BOOL)isHighSurrogate:(unsigned int)codepoint {
    boolean unmarshalledReturn;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsHighSurrogate(codepoint, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isLowSurrogate:(unsigned int)codepoint {
    boolean unmarshalledReturn;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsLowSurrogate(codepoint, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isSupplementary:(unsigned int)codepoint {
    boolean unmarshalledReturn;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsSupplementary(codepoint, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isNoncharacter:(unsigned int)codepoint {
    boolean unmarshalledReturn;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsNoncharacter(codepoint, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isWhitespace:(unsigned int)codepoint {
    boolean unmarshalledReturn;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsWhitespace(codepoint, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isAlphabetic:(unsigned int)codepoint {
    boolean unmarshalledReturn;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsAlphabetic(codepoint, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isCased:(unsigned int)codepoint {
    boolean unmarshalledReturn;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsCased(codepoint, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isUppercase:(unsigned int)codepoint {
    boolean unmarshalledReturn;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsUppercase(codepoint, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isLowercase:(unsigned int)codepoint {
    boolean unmarshalledReturn;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsLowercase(codepoint, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isIdStart:(unsigned int)codepoint {
    boolean unmarshalledReturn;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsIdStart(codepoint, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isIdContinue:(unsigned int)codepoint {
    boolean unmarshalledReturn;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsIdContinue(codepoint, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isGraphemeBase:(unsigned int)codepoint {
    boolean unmarshalledReturn;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsGraphemeBase(codepoint, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isGraphemeExtend:(unsigned int)codepoint {
    boolean unmarshalledReturn;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsGraphemeExtend(codepoint, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (WDTUnicodeNumericType)getNumericType:(unsigned int)codepoint {
    ABI::Windows::Data::Text::UnicodeNumericType unmarshalledReturn;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetNumericType(codepoint, &unmarshalledReturn));
    return (WDTUnicodeNumericType)unmarshalledReturn;
}

+ (WDTUnicodeGeneralCategory)getGeneralCategory:(unsigned int)codepoint {
    ABI::Windows::Data::Text::UnicodeGeneralCategory unmarshalledReturn;
    auto _comInst = WDTIUnicodeCharactersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetGeneralCategory(codepoint, &unmarshalledReturn));
    return (WDTUnicodeGeneralCategory)unmarshalledReturn;
}

@end

@implementation WDTAlternateWordForm

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Text::IAlternateWordForm> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDTTextSegment*)sourceTextSegment {
    ABI::Windows::Data::Text::TextSegment unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::IAlternateWordForm>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceTextSegment(&unmarshalledReturn));
    return WDTTextSegment_create(unmarshalledReturn);
}

- (NSString*)alternateText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::IAlternateWordForm>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlternateText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDTAlternateNormalizationFormat)normalizationFormat {
    ABI::Windows::Data::Text::AlternateNormalizationFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::IAlternateWordForm>(self);
    THROW_NS_IF_FAILED(_comInst->get_NormalizationFormat(&unmarshalledReturn));
    return (WDTAlternateNormalizationFormat)unmarshalledReturn;
}

@end

@implementation WDTWordSegment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Text::IWordSegment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::IWordSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDTTextSegment*)sourceTextSegment {
    ABI::Windows::Data::Text::TextSegment unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::IWordSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceTextSegment(&unmarshalledReturn));
    return WDTTextSegment_create(unmarshalledReturn);
}

- (NSArray* /* WDTAlternateWordForm* */)alternateForms {
    ComPtr<IVectorView<ABI::Windows::Data::Text::AlternateWordForm*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::IWordSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlternateForms(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDTAlternateWordForm_create(unmarshalledReturn.Get());
}

@end

@implementation WDTWordsSegmenter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Text::IWordsSegmenter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Data::Text::IWordsSegmenterFactory> WDTIWordsSegmenterFactory_inst() {
    ComPtr<ABI::Windows::Data::Text::IWordsSegmenterFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Data.Text.WordsSegmenter").Get(), &inst));
    return inst;
}

+ (WDTWordsSegmenter*)makeWithLanguage:(NSString*)language {
    ComPtr<ABI::Windows::Data::Text::IWordsSegmenter> unmarshalledReturn;
    auto _comInst = WDTIWordsSegmenterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithLanguage(nsStrToHstr(language).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDTWordsSegmenter>(unmarshalledReturn.Get()) retain];
}

- (NSString*)resolvedLanguage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::IWordsSegmenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedLanguage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDTWordSegment*)getTokenAt:(NSString*)text startIndex:(unsigned int)startIndex {
    ComPtr<ABI::Windows::Data::Text::IWordSegment> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::IWordsSegmenter>(self);
    THROW_NS_IF_FAILED(_comInst->GetTokenAt(nsStrToHstr(text).Get(), startIndex, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDTWordSegment>(unmarshalledReturn.Get());
}

- (NSArray* /* WDTWordSegment* */)getTokens:(NSString*)text {
    ComPtr<IVectorView<ABI::Windows::Data::Text::WordSegment*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::IWordsSegmenter>(self);
    THROW_NS_IF_FAILED(_comInst->GetTokens(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDTWordSegment_create(unmarshalledReturn.Get());
}

- (void)tokenize:(NSString*)text startIndex:(unsigned int)startIndex handler:(WDTWordSegmentsTokenizingHandler)handler {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::IWordsSegmenter>(self);
    THROW_NS_IF_FAILED(_comInst->Tokenize(nsStrToHstr(text).Get(), startIndex, Make<WDTWordSegmentsTokenizingHandler_shim>(handler).Get()));
}

@end

@implementation WDTSelectableWordSegment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Text::ISelectableWordSegment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ISelectableWordSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDTTextSegment*)sourceTextSegment {
    ABI::Windows::Data::Text::TextSegment unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ISelectableWordSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceTextSegment(&unmarshalledReturn));
    return WDTTextSegment_create(unmarshalledReturn);
}

@end

@implementation WDTSelectableWordsSegmenter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Text::ISelectableWordsSegmenter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Data::Text::ISelectableWordsSegmenterFactory> WDTISelectableWordsSegmenterFactory_inst() {
    ComPtr<ABI::Windows::Data::Text::ISelectableWordsSegmenterFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Data.Text.SelectableWordsSegmenter").Get(), &inst));
    return inst;
}

+ (WDTSelectableWordsSegmenter*)makeWithLanguage:(NSString*)language {
    ComPtr<ABI::Windows::Data::Text::ISelectableWordsSegmenter> unmarshalledReturn;
    auto _comInst = WDTISelectableWordsSegmenterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithLanguage(nsStrToHstr(language).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDTSelectableWordsSegmenter>(unmarshalledReturn.Get()) retain];
}

- (NSString*)resolvedLanguage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ISelectableWordsSegmenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedLanguage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDTSelectableWordSegment*)getTokenAt:(NSString*)text startIndex:(unsigned int)startIndex {
    ComPtr<ABI::Windows::Data::Text::ISelectableWordSegment> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ISelectableWordsSegmenter>(self);
    THROW_NS_IF_FAILED(_comInst->GetTokenAt(nsStrToHstr(text).Get(), startIndex, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDTSelectableWordSegment>(unmarshalledReturn.Get());
}

- (NSArray* /* WDTSelectableWordSegment* */)getTokens:(NSString*)text {
    ComPtr<IVectorView<ABI::Windows::Data::Text::SelectableWordSegment*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ISelectableWordsSegmenter>(self);
    THROW_NS_IF_FAILED(_comInst->GetTokens(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDTSelectableWordSegment_create(unmarshalledReturn.Get());
}

- (void)tokenize:(NSString*)text startIndex:(unsigned int)startIndex handler:(WDTSelectableWordSegmentsTokenizingHandler)handler {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ISelectableWordsSegmenter>(self);
    THROW_NS_IF_FAILED(
        _comInst->Tokenize(nsStrToHstr(text).Get(), startIndex, Make<WDTSelectableWordSegmentsTokenizingHandler_shim>(handler).Get()));
}

@end

@implementation WDTTextPredictionGenerator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Text::ITextPredictionGenerator> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Data::Text::ITextPredictionGeneratorFactory> WDTITextPredictionGeneratorFactory_inst() {
    ComPtr<ABI::Windows::Data::Text::ITextPredictionGeneratorFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Data.Text.TextPredictionGenerator").Get(), &inst));
    return inst;
}

+ (WDTTextPredictionGenerator*)make:(NSString*)languageTag {
    ComPtr<ABI::Windows::Data::Text::ITextPredictionGenerator> unmarshalledReturn;
    auto _comInst = WDTITextPredictionGeneratorFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(languageTag).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDTTextPredictionGenerator>(unmarshalledReturn.Get()) retain];
}

- (NSString*)resolvedLanguage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ITextPredictionGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedLanguage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)languageAvailableButNotInstalled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ITextPredictionGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->get_LanguageAvailableButNotInstalled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)getCandidatesAsync:(NSString*)input success:(void (^)(NSArray* /* NSString * */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<HSTRING>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ITextPredictionGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->GetCandidatesAsync(nsStrToHstr(input).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<HSTRING>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<HSTRING>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<HSTRING>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_NSString_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getCandidatesWithMaxCountAsync:(NSString*)input
                         maxCandidates:(unsigned int)maxCandidates
                               success:(void (^)(NSArray* /* NSString * */))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<HSTRING>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ITextPredictionGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->GetCandidatesWithMaxCountAsync(nsStrToHstr(input).Get(), maxCandidates, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<HSTRING>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<HSTRING>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<HSTRING>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_NSString_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WDTTextConversionGenerator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Text::ITextConversionGenerator> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Data::Text::ITextConversionGeneratorFactory> WDTITextConversionGeneratorFactory_inst() {
    ComPtr<ABI::Windows::Data::Text::ITextConversionGeneratorFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Data.Text.TextConversionGenerator").Get(), &inst));
    return inst;
}

+ (WDTTextConversionGenerator*)make:(NSString*)languageTag {
    ComPtr<ABI::Windows::Data::Text::ITextConversionGenerator> unmarshalledReturn;
    auto _comInst = WDTITextConversionGeneratorFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(languageTag).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDTTextConversionGenerator>(unmarshalledReturn.Get()) retain];
}

- (NSString*)resolvedLanguage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ITextConversionGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedLanguage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)languageAvailableButNotInstalled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ITextConversionGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->get_LanguageAvailableButNotInstalled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)getCandidatesAsync:(NSString*)input success:(void (^)(NSArray* /* NSString * */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<HSTRING>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ITextConversionGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->GetCandidatesAsync(nsStrToHstr(input).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<HSTRING>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<HSTRING>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<HSTRING>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_NSString_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getCandidatesWithMaxCountAsync:(NSString*)input
                         maxCandidates:(unsigned int)maxCandidates
                               success:(void (^)(NSArray* /* NSString * */))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<HSTRING>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ITextConversionGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->GetCandidatesWithMaxCountAsync(nsStrToHstr(input).Get(), maxCandidates, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<HSTRING>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<HSTRING>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<HSTRING>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_NSString_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WDTTextReverseConversionGenerator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Text::ITextReverseConversionGenerator> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Data::Text::ITextReverseConversionGeneratorFactory> WDTITextReverseConversionGeneratorFactory_inst() {
    ComPtr<ABI::Windows::Data::Text::ITextReverseConversionGeneratorFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Data.Text.TextReverseConversionGenerator").Get(),
                                                       &inst));
    return inst;
}

+ (WDTTextReverseConversionGenerator*)make:(NSString*)languageTag {
    ComPtr<ABI::Windows::Data::Text::ITextReverseConversionGenerator> unmarshalledReturn;
    auto _comInst = WDTITextReverseConversionGeneratorFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(languageTag).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDTTextReverseConversionGenerator>(unmarshalledReturn.Get()) retain];
}

- (NSString*)resolvedLanguage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ITextReverseConversionGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedLanguage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)languageAvailableButNotInstalled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ITextReverseConversionGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->get_LanguageAvailableButNotInstalled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)convertBackAsync:(NSString*)input success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ITextReverseConversionGenerator>(self);
    THROW_NS_IF_FAILED(_comInst->ConvertBackAsync(nsStrToHstr(input).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getPhonemesAsync:(NSString*)input success:(void (^)(NSArray* /* WDTTextPhoneme* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Data::Text::TextPhoneme*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ITextReverseConversionGenerator2>(self);
    THROW_NS_IF_FAILED(_comInst->GetPhonemesAsync(nsStrToHstr(input).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Data::Text::TextPhoneme*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Data::Text::TextPhoneme*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Data::Text::TextPhoneme*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WDTTextPhoneme_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WDTTextPhoneme

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Text::ITextPhoneme> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)displayText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ITextPhoneme>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)readingText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Text::ITextPhoneme>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadingText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDTTextSegment {
    ABI::Windows::Data::Text::TextSegment structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Data::Text::TextSegment)s {
    WDTTextSegment* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Data::Text::TextSegment*)internalStruct {
    return &structVal;
}
- (unsigned int)startPosition {
    return structVal.StartPosition;
}
- (void)setStartPosition:(unsigned int)val {
    structVal.StartPosition = val;
}
- (unsigned int)length {
    return structVal.Length;
}
- (void)setLength:(unsigned int)val {
    structVal.Length = val;
}
@end
id RTProxiedIterableNSArray_WDTSelectableWordSegment_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Data::Text::SelectableWordSegment*>,
                                                 RTIterableObj<ABI::Windows::Data::Text::ISelectableWordSegment*,
                                                               IIterable<ABI::Windows::Data::Text::SelectableWordSegment*>,
                                                               WDTSelectableWordSegment,
                                                               ABI::Windows::Data::Text::SelectableWordSegment*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WDTWordSegment_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Data::Text::WordSegment*>,
                                                 RTIterableObj<ABI::Windows::Data::Text::IWordSegment*,
                                                               IIterable<ABI::Windows::Data::Text::WordSegment*>,
                                                               WDTWordSegment,
                                                               ABI::Windows::Data::Text::WordSegment*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDTAlternateWordForm_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Data::Text::AlternateWordForm*>,
                                         RTArrayObj<ABI::Windows::Data::Text::IAlternateWordForm*,
                                                    IVectorView<ABI::Windows::Data::Text::AlternateWordForm*>,
                                                    WDTAlternateWordForm,
                                                    ABI::Windows::Data::Text::AlternateWordForm*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDTSelectableWordSegment_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Data::Text::SelectableWordSegment*>,
                                         RTArrayObj<ABI::Windows::Data::Text::ISelectableWordSegment*,
                                                    IVectorView<ABI::Windows::Data::Text::SelectableWordSegment*>,
                                                    WDTSelectableWordSegment,
                                                    ABI::Windows::Data::Text::SelectableWordSegment*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDTTextPhoneme_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Data::Text::TextPhoneme*>,
                                                                             RTArrayObj<ABI::Windows::Data::Text::ITextPhoneme*,
                                                                                        IVectorView<ABI::Windows::Data::Text::TextPhoneme*>,
                                                                                        WDTTextPhoneme,
                                                                                        ABI::Windows::Data::Text::TextPhoneme*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDTTextSegment_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Data::Text::TextSegment>,
                                                                             RTArrayObj<ABI::Windows::Data::Text::TextSegment,
                                                                                        IVectorView<ABI::Windows::Data::Text::TextSegment>,
                                                                                        WDTTextSegment,
                                                                                        ABI::Windows::Data::Text::TextSegment,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDTWordSegment_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Data::Text::WordSegment*>,
                                                                             RTArrayObj<ABI::Windows::Data::Text::IWordSegment*,
                                                                                        IVectorView<ABI::Windows::Data::Text::WordSegment*>,
                                                                                        WDTWordSegment,
                                                                                        ABI::Windows::Data::Text::WordSegment*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
