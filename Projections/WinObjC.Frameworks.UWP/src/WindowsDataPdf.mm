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

// WindowsDataPdf.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Data.Pdf.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDataPdf.h"
#include "WindowsDataPdf_priv.h"

@implementation WDPPdfPageRenderOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Pdf::IPdfPageRenderOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Data.Pdf.PdfPageRenderOptions").Get(), &out));
    return [_createRtProxy<WDPPdfPageRenderOptions>(out.Get()) retain];
}

- (WFRect*)sourceRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageRenderOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)setSourceRect:(WFRect*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageRenderOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_SourceRect(*[value internalStruct]));
}

- (unsigned int)destinationWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageRenderOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_DestinationWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDestinationWidth:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageRenderOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_DestinationWidth(value));
}

- (unsigned int)destinationHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageRenderOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_DestinationHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDestinationHeight:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageRenderOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_DestinationHeight(value));
}

- (WUColor*)backgroundColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageRenderOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackgroundColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setBackgroundColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageRenderOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_BackgroundColor(*[value internalStruct]));
}

- (BOOL)isIgnoringHighContrast {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageRenderOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsIgnoringHighContrast(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsIgnoringHighContrast:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageRenderOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsIgnoringHighContrast((boolean)value));
}

- (WFGUID*)bitmapEncoderId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageRenderOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapEncoderId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (void)setBitmapEncoderId:(WFGUID*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageRenderOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_BitmapEncoderId(value.guidValue));
}

@end

@implementation WDPPdfPageDimensions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Pdf::IPdfPageDimensions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFRect*)mediaBox {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageDimensions>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaBox(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFRect*)cropBox {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageDimensions>(self);
    THROW_NS_IF_FAILED(_comInst->get_CropBox(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFRect*)bleedBox {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageDimensions>(self);
    THROW_NS_IF_FAILED(_comInst->get_BleedBox(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFRect*)trimBox {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageDimensions>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrimBox(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WFRect*)artBox {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPageDimensions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ArtBox(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

@end

@implementation WDPPdfPage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Pdf::IPdfPage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WFIAsyncAction>*)renderToStreamAsync:(RTObject<WSSIRandomAccessStream>*)outputStream {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPage>(self);
    THROW_NS_IF_FAILED(
        _comInst->RenderToStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(outputStream).Get(),
                                      unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)renderWithOptionsToStreamAsync:(RTObject<WSSIRandomAccessStream>*)outputStream
                                                    options:(WDPPdfPageRenderOptions*)options {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPage>(self);
    THROW_NS_IF_FAILED(
        _comInst->RenderWithOptionsToStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(outputStream).Get(),
                                                 _getRtInterface<ABI::Windows::Data::Pdf::IPdfPageRenderOptions>(options).Get(),
                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)preparePageAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPage>(self);
    THROW_NS_IF_FAILED(_comInst->PreparePageAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (unsigned int)index {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Index(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFSize*)size {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WDPPdfPageDimensions*)dimensions {
    ComPtr<ABI::Windows::Data::Pdf::IPdfPageDimensions> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Dimensions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPdfPageDimensions>(unmarshalledReturn.Get());
}

- (WDPPdfPageRotation)rotation {
    ABI::Windows::Data::Pdf::PdfPageRotation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Rotation(&unmarshalledReturn));
    return (WDPPdfPageRotation)unmarshalledReturn;
}

- (float)preferredZoom {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfPage>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreferredZoom(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDPPdfDocument

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Pdf::IPdfDocument> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Data::Pdf::IPdfDocumentStatics> WDPIPdfDocumentStatics_inst() {
    ComPtr<ABI::Windows::Data::Pdf::IPdfDocumentStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Data.Pdf.PdfDocument").Get(), &inst));
    return inst;
}

+ (void)loadFromFileAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(WDPPdfDocument*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Data::Pdf::PdfDocument*>> unmarshalledReturn;
    auto _comInst = WDPIPdfDocumentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LoadFromFileAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Data::Pdf::PdfDocument*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Data::Pdf::PdfDocument*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Data::Pdf::IPdfDocument> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDPPdfDocument>(result.Get()));
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

+ (void)loadFromFileWithPasswordAsync:(RTObject<WSIStorageFile>*)file
                             password:(NSString*)password
                              success:(void (^)(WDPPdfDocument*))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Data::Pdf::PdfDocument*>> unmarshalledReturn;
    auto _comInst = WDPIPdfDocumentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LoadFromFileWithPasswordAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                               nsStrToHstr(password).Get(),
                                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Data::Pdf::PdfDocument*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Data::Pdf::PdfDocument*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Data::Pdf::IPdfDocument> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDPPdfDocument>(result.Get()));
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

+ (void)loadFromStreamAsync:(RTObject<WSSIRandomAccessStream>*)inputStream
                    success:(void (^)(WDPPdfDocument*))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Data::Pdf::PdfDocument*>> unmarshalledReturn;
    auto _comInst = WDPIPdfDocumentStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->LoadFromStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(inputStream).Get(),
                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Data::Pdf::PdfDocument*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Data::Pdf::PdfDocument*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Data::Pdf::IPdfDocument> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDPPdfDocument>(result.Get()));
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

+ (void)loadFromStreamWithPasswordAsync:(RTObject<WSSIRandomAccessStream>*)inputStream
                               password:(NSString*)password
                                success:(void (^)(WDPPdfDocument*))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Data::Pdf::PdfDocument*>> unmarshalledReturn;
    auto _comInst = WDPIPdfDocumentStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->LoadFromStreamWithPasswordAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(inputStream).Get(),
                                                  nsStrToHstr(password).Get(),
                                                  &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Data::Pdf::PdfDocument*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Data::Pdf::PdfDocument*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Data::Pdf::IPdfDocument> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDPPdfDocument>(result.Get()));
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

- (WDPPdfPage*)getPage:(unsigned int)pageIndex {
    ComPtr<ABI::Windows::Data::Pdf::IPdfPage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfDocument>(self);
    THROW_NS_IF_FAILED(_comInst->GetPage(pageIndex, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPdfPage>(unmarshalledReturn.Get());
}

- (unsigned int)pageCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfDocument>(self);
    THROW_NS_IF_FAILED(_comInst->get_PageCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isPasswordProtected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Pdf::IPdfDocument>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPasswordProtected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end
