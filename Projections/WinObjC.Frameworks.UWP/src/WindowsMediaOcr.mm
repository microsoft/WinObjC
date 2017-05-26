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

// WindowsMediaOcr.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Ocr.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaOcr.h"
#include "WindowsMediaOcr_priv.h"

@implementation WMOOcrWord

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Ocr::IOcrWord> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFRect*)boundingRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Ocr::IOcrWord>(self);
    THROW_NS_IF_FAILED(_comInst->get_BoundingRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Ocr::IOcrWord>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMOOcrLine

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Ocr::IOcrLine> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WMOOcrWord* */)words {
    ComPtr<IVectorView<ABI::Windows::Media::Ocr::OcrWord*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Ocr::IOcrLine>(self);
    THROW_NS_IF_FAILED(_comInst->get_Words(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMOOcrWord_create(unmarshalledReturn.Get());
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Ocr::IOcrLine>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMOOcrResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Ocr::IOcrResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WMOOcrLine* */)lines {
    ComPtr<IVectorView<ABI::Windows::Media::Ocr::OcrLine*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Ocr::IOcrResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Lines(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMOOcrLine_create(unmarshalledReturn.Get());
}

- (id /* double */)textAngle {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Ocr::IOcrResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextAngle(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Ocr::IOcrResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMOOcrEngine

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Ocr::IOcrEngine> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::Ocr::IOcrEngineStatics> WMOIOcrEngineStatics_inst() {
    ComPtr<ABI::Windows::Media::Ocr::IOcrEngineStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Ocr.OcrEngine").Get(), &inst));
    return inst;
}

+ (unsigned int)maxImageDimension {
    unsigned int unmarshalledReturn;
    auto _comInst = WMOIOcrEngineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MaxImageDimension(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (NSArray* /* WGLanguage* */)availableRecognizerLanguages {
    ComPtr<IVectorView<ABI::Windows::Globalization::Language*>> unmarshalledReturn;
    auto _comInst = WMOIOcrEngineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AvailableRecognizerLanguages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGLanguage_create(unmarshalledReturn.Get());
}

+ (BOOL)isLanguageSupported:(WGLanguage*)language {
    boolean unmarshalledReturn;
    auto _comInst = WMOIOcrEngineStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->IsLanguageSupported(_getRtInterface<ABI::Windows::Globalization::ILanguage>(language).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (WMOOcrEngine*)tryCreateFromLanguage:(WGLanguage*)language {
    ComPtr<ABI::Windows::Media::Ocr::IOcrEngine> unmarshalledReturn;
    auto _comInst = WMOIOcrEngineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryCreateFromLanguage(_getRtInterface<ABI::Windows::Globalization::ILanguage>(language).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMOOcrEngine>(unmarshalledReturn.Get());
}

+ (WMOOcrEngine*)tryCreateFromUserProfileLanguages {
    ComPtr<ABI::Windows::Media::Ocr::IOcrEngine> unmarshalledReturn;
    auto _comInst = WMOIOcrEngineStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryCreateFromUserProfileLanguages(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMOOcrEngine>(unmarshalledReturn.Get());
}

- (void)recognizeAsync:(WGISoftwareBitmap*)bitmap success:(void (^)(WMOOcrResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Ocr::OcrResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Ocr::IOcrEngine>(self);
    THROW_NS_IF_FAILED(
        _comInst->RecognizeAsync(_getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(bitmap).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Ocr::OcrResult*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Ocr::OcrResult*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Ocr::IOcrResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMOOcrResult>(result.Get()));
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

- (WGLanguage*)recognizerLanguage {
    ComPtr<ABI::Windows::Globalization::ILanguage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Ocr::IOcrEngine>(self);
    THROW_NS_IF_FAILED(_comInst->get_RecognizerLanguage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGLanguage>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_WGLanguage_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Globalization::Language*>,
                                                                             RTArrayObj<ABI::Windows::Globalization::ILanguage*,
                                                                                        IVectorView<ABI::Windows::Globalization::Language*>,
                                                                                        WGLanguage,
                                                                                        ABI::Windows::Globalization::Language*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMOOcrLine_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Ocr::OcrLine*>,
                                                                             RTArrayObj<ABI::Windows::Media::Ocr::IOcrLine*,
                                                                                        IVectorView<ABI::Windows::Media::Ocr::OcrLine*>,
                                                                                        WMOOcrLine,
                                                                                        ABI::Windows::Media::Ocr::OcrLine*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMOOcrWord_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Ocr::OcrWord*>,
                                                                             RTArrayObj<ABI::Windows::Media::Ocr::IOcrWord*,
                                                                                        IVectorView<ABI::Windows::Media::Ocr::OcrWord*>,
                                                                                        WMOOcrWord,
                                                                                        ABI::Windows::Media::Ocr::OcrWord*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
