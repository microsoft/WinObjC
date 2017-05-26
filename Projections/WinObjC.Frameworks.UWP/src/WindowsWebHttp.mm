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

// WindowsWebHttp.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Web.Http.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsWebHttp.h"
#include "WindowsWebHttp_priv.h"

@implementation WWHIHttpContent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WWHHHttpContentHeaderCollection*)headers {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Headers(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpContentHeaderCollection>(unmarshalledReturn.Get());
}

- (void)bufferAllAsyncWithSuccess:(void (^)(uint64_t))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->BufferAllAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
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

- (void)readAsBufferAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsBufferAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>* op,
                         uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

- (void)readAsInputStreamAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success
                                 progress:(void (^)(uint64_t))progress
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsInputStreamAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>* op,
                         uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IInputStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIInputStream>(result.Get()));
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

- (void)readAsStringAsyncWithSuccess:(void (^)(NSString*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsStringAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<HSTRING, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<HSTRING, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>* op, AsyncStatus status) {
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

- (BOOL)tryComputeLength:(uint64_t*)length {
    uint64_t lengthOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->TryComputeLength(&lengthOutUnmarshaled, &unmarshalledReturn));
    *length = lengthOutUnmarshaled;
    return (BOOL)unmarshalledReturn;
}

- (void)writeToStreamAsync:(RTObject<WSSIOutputStream>*)outputStream
                   success:(void (^)(uint64_t))success
                  progress:(void (^)(uint64_t))progress
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->WriteToStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(outputStream).Get(),
                                                    &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WWHHttpRequestMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::IHttpRequestMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::IHttpRequestMessageFactory> WWHIHttpRequestMessageFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::IHttpRequestMessageFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.HttpRequestMessage").Get(), &inst));
    return inst;
}

+ (WWHHttpRequestMessage*)make:(WWHHttpMethod*)method uri:(WFUri*)uri {
    ComPtr<ABI::Windows::Web::Http::IHttpRequestMessage> unmarshalledReturn;
    auto _comInst = WWHIHttpRequestMessageFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(_getRtInterface<ABI::Windows::Web::Http::IHttpMethod>(method).Get(),
                                        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHttpRequestMessage>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Http.HttpRequestMessage").Get(), &out));
    return [_createRtProxy<WWHHttpRequestMessage>(out.Get()) retain];
}

- (RTObject<WWHIHttpContent>*)content {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpRequestMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHIHttpContent>(unmarshalledReturn.Get());
}

- (void)setContent:(RTObject<WWHIHttpContent>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpRequestMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Content(_getRtInterface<ABI::Windows::Web::Http::IHttpContent>(value).Get()));
}

- (WWHHHttpRequestHeaderCollection*)headers {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpRequestMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Headers(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpRequestHeaderCollection>(unmarshalledReturn.Get());
}

- (WWHHttpMethod*)method {
    ComPtr<ABI::Windows::Web::Http::IHttpMethod> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpRequestMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Method(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpMethod>(unmarshalledReturn.Get());
}

- (void)setMethod:(WWHHttpMethod*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpRequestMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Method(_getRtInterface<ABI::Windows::Web::Http::IHttpMethod>(value).Get()));
}

- (NSMutableDictionary* /* NSString *, RTObject* */)properties {
    ComPtr<IMap<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpRequestMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

- (WFUri*)requestUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpRequestMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setRequestUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpRequestMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_RequestUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WWHHttpTransportInformation*)transportInformation {
    ComPtr<ABI::Windows::Web::Http::IHttpTransportInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpRequestMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransportInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpTransportInformation>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHttpResponseMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::IHttpResponseMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Http.HttpResponseMessage").Get(), &out));
    return [_createRtProxy<WWHHttpResponseMessage>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Web::Http::IHttpResponseMessageFactory> WWHIHttpResponseMessageFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::IHttpResponseMessageFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.HttpResponseMessage").Get(), &inst));
    return inst;
}

+ (WWHHttpResponseMessage*)make:(WWHHttpStatusCode)statusCode {
    ComPtr<ABI::Windows::Web::Http::IHttpResponseMessage> unmarshalledReturn;
    auto _comInst = WWHIHttpResponseMessageFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create((ABI::Windows::Web::Http::HttpStatusCode)statusCode, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHttpResponseMessage>(unmarshalledReturn.Get()) retain];
}

- (RTObject<WWHIHttpContent>*)content {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpResponseMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHIHttpContent>(unmarshalledReturn.Get());
}

- (void)setContent:(RTObject<WWHIHttpContent>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpResponseMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Content(_getRtInterface<ABI::Windows::Web::Http::IHttpContent>(value).Get()));
}

- (WWHHHttpResponseHeaderCollection*)headers {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpResponseHeaderCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpResponseMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Headers(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpResponseHeaderCollection>(unmarshalledReturn.Get());
}

- (BOOL)isSuccessStatusCode {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpResponseMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSuccessStatusCode(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)reasonPhrase {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpResponseMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReasonPhrase(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setReasonPhrase:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpResponseMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReasonPhrase(nsStrToHstr(value).Get()));
}

- (WWHHttpRequestMessage*)requestMessage {
    ComPtr<ABI::Windows::Web::Http::IHttpRequestMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpResponseMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpRequestMessage>(unmarshalledReturn.Get());
}

- (void)setRequestMessage:(WWHHttpRequestMessage*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpResponseMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_RequestMessage(_getRtInterface<ABI::Windows::Web::Http::IHttpRequestMessage>(value).Get()));
}

- (WWHHttpResponseMessageSource)source {
    ABI::Windows::Web::Http::HttpResponseMessageSource unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpResponseMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(&unmarshalledReturn));
    return (WWHHttpResponseMessageSource)unmarshalledReturn;
}

- (void)setSource:(WWHHttpResponseMessageSource)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpResponseMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Source((ABI::Windows::Web::Http::HttpResponseMessageSource)value));
}

- (WWHHttpStatusCode)statusCode {
    ABI::Windows::Web::Http::HttpStatusCode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpResponseMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_StatusCode(&unmarshalledReturn));
    return (WWHHttpStatusCode)unmarshalledReturn;
}

- (void)setStatusCode:(WWHHttpStatusCode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpResponseMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_StatusCode((ABI::Windows::Web::Http::HttpStatusCode)value));
}

- (WWHHttpVersion)Version {
    ABI::Windows::Web::Http::HttpVersion unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpResponseMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Version(&unmarshalledReturn));
    return (WWHHttpVersion)unmarshalledReturn;
}

- (void)SetVersion:(WWHHttpVersion)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpResponseMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_Version((ABI::Windows::Web::Http::HttpVersion)value));
}

- (WWHHttpResponseMessage*)ensureSuccessStatusCode {
    ComPtr<ABI::Windows::Web::Http::IHttpResponseMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpResponseMessage>(self);
    THROW_NS_IF_FAILED(_comInst->EnsureSuccessStatusCode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpResponseMessage>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHttpClient

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::IHttpClient> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Http.HttpClient").Get(), &out));
    return [_createRtProxy<WWHHttpClient>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Web::Http::IHttpClientFactory> WWHIHttpClientFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::IHttpClientFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.HttpClient").Get(), &inst));
    return inst;
}

+ (WWHHttpClient*)make:(RTObject<WWHFIHttpFilter>*)filter {
    ComPtr<ABI::Windows::Web::Http::IHttpClient> unmarshalledReturn;
    auto _comInst = WWHIHttpClientFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Web::Http::Filters::IHttpFilter>(filter).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHttpClient>(unmarshalledReturn.Get()) retain];
}

- (void)deleteAsync:(WFUri*)uri
            success:(void (^)(WWHHttpResponseMessage*))success
           progress:(void (^)(WWHHttpProgress*))progress
            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                 ABI::Windows::Web::Http::HttpProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpClient>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                     ABI::Windows::Web::Http::HttpProgress>,
            FtmBase>>([progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                                         ABI::Windows::Web::Http::HttpProgress>* op,
                                   ABI::Windows::Web::Http::HttpProgress status) {
            @autoreleasepool {
                progressRc(WWHHttpProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                              ABI::Windows::Web::Http::HttpProgress>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                                     ABI::Windows::Web::Http::HttpProgress>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Web::Http::IHttpResponseMessage> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WWHHttpResponseMessage>(result.Get()));
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

- (void)getAsync:(WFUri*)uri
         success:(void (^)(WWHHttpResponseMessage*))success
        progress:(void (^)(WWHHttpProgress*))progress
         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                 ABI::Windows::Web::Http::HttpProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpClient>(self);
    THROW_NS_IF_FAILED(_comInst->GetAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                     ABI::Windows::Web::Http::HttpProgress>,
            FtmBase>>([progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                                         ABI::Windows::Web::Http::HttpProgress>* op,
                                   ABI::Windows::Web::Http::HttpProgress status) {
            @autoreleasepool {
                progressRc(WWHHttpProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                              ABI::Windows::Web::Http::HttpProgress>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                                     ABI::Windows::Web::Http::HttpProgress>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Web::Http::IHttpResponseMessage> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WWHHttpResponseMessage>(result.Get()));
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

- (void)getWithOptionAsync:(WFUri*)uri
          completionOption:(WWHHttpCompletionOption)completionOption
                   success:(void (^)(WWHHttpResponseMessage*))success
                  progress:(void (^)(WWHHttpProgress*))progress
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                 ABI::Windows::Web::Http::HttpProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpClient>(self);
    THROW_NS_IF_FAILED(_comInst->GetWithOptionAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                    (ABI::Windows::Web::Http::HttpCompletionOption)completionOption,
                                                    &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                     ABI::Windows::Web::Http::HttpProgress>,
            FtmBase>>([progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                                         ABI::Windows::Web::Http::HttpProgress>* op,
                                   ABI::Windows::Web::Http::HttpProgress status) {
            @autoreleasepool {
                progressRc(WWHHttpProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                              ABI::Windows::Web::Http::HttpProgress>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                                     ABI::Windows::Web::Http::HttpProgress>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Web::Http::IHttpResponseMessage> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WWHHttpResponseMessage>(result.Get()));
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

- (void)getBufferAsync:(WFUri*)uri
               success:(void (^)(RTObject<WSSIBuffer>*))success
              progress:(void (^)(WWHHttpProgress*))progress
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*,
                                                                 ABI::Windows::Web::Http::HttpProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpClient>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetBufferAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IBuffer*,
                                                                                                  ABI::Windows::Web::Http::HttpProgress>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*,
                                                                               ABI::Windows::Web::Http::HttpProgress>* op,
                         ABI::Windows::Web::Http::HttpProgress status) {
                @autoreleasepool {
                    progressRc(WWHHttpProgress_create(status));
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*,
                                                                              ABI::Windows::Web::Http::HttpProgress>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*,
                                                                                     ABI::Windows::Web::Http::HttpProgress>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

- (void)getInputStreamAsync:(WFUri*)uri
                    success:(void (^)(RTObject<WSSIInputStream>*))success
                   progress:(void (^)(WWHHttpProgress*))progress
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*,
                                                                 ABI::Windows::Web::Http::HttpProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpClient>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetInputStreamAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IInputStream*,
                                                                     ABI::Windows::Web::Http::HttpProgress>,
            FtmBase>>([progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*,
                                                                                         ABI::Windows::Web::Http::HttpProgress>* op,
                                   ABI::Windows::Web::Http::HttpProgress status) {
            @autoreleasepool {
                progressRc(WWHHttpProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IInputStream*,
                                                                              ABI::Windows::Web::Http::HttpProgress>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*,
                                                                                     ABI::Windows::Web::Http::HttpProgress>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IInputStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIInputStream>(result.Get()));
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

- (void)getStringAsync:(WFUri*)uri
               success:(void (^)(NSString*))success
              progress:(void (^)(WWHHttpProgress*))progress
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, ABI::Windows::Web::Http::HttpProgress>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpClient>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetStringAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<HSTRING, ABI::Windows::Web::Http::HttpProgress>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, ABI::Windows::Web::Http::HttpProgress>* op,
                         ABI::Windows::Web::Http::HttpProgress status) {
                @autoreleasepool {
                    progressRc(WWHHttpProgress_create(status));
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<HSTRING, ABI::Windows::Web::Http::HttpProgress>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, ABI::Windows::Web::Http::HttpProgress>* op,
                               AsyncStatus status) {
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

- (void)postAsync:(WFUri*)uri
          content:(RTObject<WWHIHttpContent>*)content
          success:(void (^)(WWHHttpResponseMessage*))success
         progress:(void (^)(WWHHttpProgress*))progress
          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                 ABI::Windows::Web::Http::HttpProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpClient>(self);
    THROW_NS_IF_FAILED(_comInst->PostAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                           _getRtInterface<ABI::Windows::Web::Http::IHttpContent>(content).Get(),
                                           &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                     ABI::Windows::Web::Http::HttpProgress>,
            FtmBase>>([progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                                         ABI::Windows::Web::Http::HttpProgress>* op,
                                   ABI::Windows::Web::Http::HttpProgress status) {
            @autoreleasepool {
                progressRc(WWHHttpProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                              ABI::Windows::Web::Http::HttpProgress>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                                     ABI::Windows::Web::Http::HttpProgress>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Web::Http::IHttpResponseMessage> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WWHHttpResponseMessage>(result.Get()));
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

- (void)putAsync:(WFUri*)uri
         content:(RTObject<WWHIHttpContent>*)content
         success:(void (^)(WWHHttpResponseMessage*))success
        progress:(void (^)(WWHHttpProgress*))progress
         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                 ABI::Windows::Web::Http::HttpProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpClient>(self);
    THROW_NS_IF_FAILED(_comInst->PutAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                          _getRtInterface<ABI::Windows::Web::Http::IHttpContent>(content).Get(),
                                          &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                     ABI::Windows::Web::Http::HttpProgress>,
            FtmBase>>([progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                                         ABI::Windows::Web::Http::HttpProgress>* op,
                                   ABI::Windows::Web::Http::HttpProgress status) {
            @autoreleasepool {
                progressRc(WWHHttpProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                              ABI::Windows::Web::Http::HttpProgress>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                                     ABI::Windows::Web::Http::HttpProgress>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Web::Http::IHttpResponseMessage> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WWHHttpResponseMessage>(result.Get()));
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

- (void)sendRequestAsync:(WWHHttpRequestMessage*)request
                 success:(void (^)(WWHHttpResponseMessage*))success
                progress:(void (^)(WWHHttpProgress*))progress
                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                 ABI::Windows::Web::Http::HttpProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpClient>(self);
    THROW_NS_IF_FAILED(
        _comInst->SendRequestAsync(_getRtInterface<ABI::Windows::Web::Http::IHttpRequestMessage>(request).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                     ABI::Windows::Web::Http::HttpProgress>,
            FtmBase>>([progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                                         ABI::Windows::Web::Http::HttpProgress>* op,
                                   ABI::Windows::Web::Http::HttpProgress status) {
            @autoreleasepool {
                progressRc(WWHHttpProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                              ABI::Windows::Web::Http::HttpProgress>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                                     ABI::Windows::Web::Http::HttpProgress>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Web::Http::IHttpResponseMessage> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WWHHttpResponseMessage>(result.Get()));
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

- (void)sendRequestWithOptionAsync:(WWHHttpRequestMessage*)request
                  completionOption:(WWHHttpCompletionOption)completionOption
                           success:(void (^)(WWHHttpResponseMessage*))success
                          progress:(void (^)(WWHHttpProgress*))progress
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                 ABI::Windows::Web::Http::HttpProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpClient>(self);
    THROW_NS_IF_FAILED(_comInst->SendRequestWithOptionAsync(_getRtInterface<ABI::Windows::Web::Http::IHttpRequestMessage>(request).Get(),
                                                            (ABI::Windows::Web::Http::HttpCompletionOption)completionOption,
                                                            &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                     ABI::Windows::Web::Http::HttpProgress>,
            FtmBase>>([progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                                         ABI::Windows::Web::Http::HttpProgress>* op,
                                   ABI::Windows::Web::Http::HttpProgress status) {
            @autoreleasepool {
                progressRc(WWHHttpProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                              ABI::Windows::Web::Http::HttpProgress>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                                     ABI::Windows::Web::Http::HttpProgress>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Web::Http::IHttpResponseMessage> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WWHHttpResponseMessage>(result.Get()));
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

- (WWHHHttpRequestHeaderCollection*)defaultRequestHeaders {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpRequestHeaderCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpClient>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultRequestHeaders(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpRequestHeaderCollection>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHttpCookie

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::IHttpCookie> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::IHttpCookieFactory> WWHIHttpCookieFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::IHttpCookieFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.HttpCookie").Get(), &inst));
    return inst;
}

+ (WWHHttpCookie*)make:(NSString*)name domain:(NSString*)domain path:(NSString*)path {
    ComPtr<ABI::Windows::Web::Http::IHttpCookie> unmarshalledReturn;
    auto _comInst = WWHIHttpCookieFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(nsStrToHstr(name).Get(), nsStrToHstr(domain).Get(), nsStrToHstr(path).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHttpCookie>(unmarshalledReturn.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpCookie>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)domain {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpCookie>(self);
    THROW_NS_IF_FAILED(_comInst->get_Domain(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)path {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpCookie>(self);
    THROW_NS_IF_FAILED(_comInst->get_Path(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id /* WFDateTime* */)expires {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpCookie>(self);
    THROW_NS_IF_FAILED(_comInst->get_Expires(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (void)setExpires:(id /* WFDateTime* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpCookie>(self);
    THROW_NS_IF_FAILED(_comInst->put_Expires(BuildNullable<ABI::Windows::Foundation::DateTime>(value)));
}

- (BOOL)httpOnly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpCookie>(self);
    THROW_NS_IF_FAILED(_comInst->get_HttpOnly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHttpOnly:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpCookie>(self);
    THROW_NS_IF_FAILED(_comInst->put_HttpOnly((boolean)value));
}

- (BOOL)secure {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpCookie>(self);
    THROW_NS_IF_FAILED(_comInst->get_Secure(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSecure:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpCookie>(self);
    THROW_NS_IF_FAILED(_comInst->put_Secure((boolean)value));
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpCookie>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setValue:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpCookie>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(nsStrToHstr(value).Get()));
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHttpCookieCollection {
    RTArrayObj<ABI::Windows::Web::Http::IHttpCookie*,
               IVectorView<ABI::Windows::Web::Http::HttpCookie*>,
               WWHHttpCookie,
               ABI::Windows::Web::Http::HttpCookie*,
               dummyObjCCreator,
               dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTORVIEW_FULL(self.comObj, WWHHttpCookie, ABI::Windows::Web::Http::IHttpCookie*, ABI::Windows::Web::Http::HttpCookie*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVectorView<ABI::Windows::Web::Http::HttpCookie*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WWHHttpMethod

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::IHttpMethod> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::IHttpMethodFactory> WWHIHttpMethodFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::IHttpMethodFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.HttpMethod").Get(), &inst));
    return inst;
}

+ (WWHHttpMethod*)make:(NSString*)method {
    ComPtr<ABI::Windows::Web::Http::IHttpMethod> unmarshalledReturn;
    auto _comInst = WWHIHttpMethodFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(method).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHttpMethod>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Web::Http::IHttpMethodStatics> WWHIHttpMethodStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::IHttpMethodStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.HttpMethod").Get(), &inst));
    return inst;
}

+ (WWHHttpMethod*)Delete {
    ComPtr<ABI::Windows::Web::Http::IHttpMethod> unmarshalledReturn;
    auto _comInst = WWHIHttpMethodStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Delete(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpMethod>(unmarshalledReturn.Get());
}

+ (WWHHttpMethod*)get {
    ComPtr<ABI::Windows::Web::Http::IHttpMethod> unmarshalledReturn;
    auto _comInst = WWHIHttpMethodStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Get(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpMethod>(unmarshalledReturn.Get());
}

+ (WWHHttpMethod*)head {
    ComPtr<ABI::Windows::Web::Http::IHttpMethod> unmarshalledReturn;
    auto _comInst = WWHIHttpMethodStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Head(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpMethod>(unmarshalledReturn.Get());
}

+ (WWHHttpMethod*)options {
    ComPtr<ABI::Windows::Web::Http::IHttpMethod> unmarshalledReturn;
    auto _comInst = WWHIHttpMethodStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Options(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpMethod>(unmarshalledReturn.Get());
}

+ (WWHHttpMethod*)patch {
    ComPtr<ABI::Windows::Web::Http::IHttpMethod> unmarshalledReturn;
    auto _comInst = WWHIHttpMethodStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Patch(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpMethod>(unmarshalledReturn.Get());
}

+ (WWHHttpMethod*)post {
    ComPtr<ABI::Windows::Web::Http::IHttpMethod> unmarshalledReturn;
    auto _comInst = WWHIHttpMethodStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Post(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpMethod>(unmarshalledReturn.Get());
}

+ (WWHHttpMethod*)put {
    ComPtr<ABI::Windows::Web::Http::IHttpMethod> unmarshalledReturn;
    auto _comInst = WWHIHttpMethodStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Put(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpMethod>(unmarshalledReturn.Get());
}

- (NSString*)method {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpMethod>(self);
    THROW_NS_IF_FAILED(_comInst->get_Method(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHttpTransportInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::IHttpTransportInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSCCCertificate*)serverCertificate {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpTransportInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (WNSSocketSslErrorSeverity)serverCertificateErrorSeverity {
    ABI::Windows::Networking::Sockets::SocketSslErrorSeverity unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpTransportInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificateErrorSeverity(&unmarshalledReturn));
    return (WNSSocketSslErrorSeverity)unmarshalledReturn;
}

- (NSArray* /* WSCCChainValidationResult */)serverCertificateErrors {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpTransportInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificateErrors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCChainValidationResult_create(unmarshalledReturn.Get());
}

- (NSArray* /* WSCCCertificate* */)serverIntermediateCertificates {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpTransportInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerIntermediateCertificates(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCCertificate_create(unmarshalledReturn.Get());
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHttpStringContent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::IHttpStringContentFactory> WWHIHttpStringContentFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::IHttpStringContentFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.HttpStringContent").Get(), &inst));
    return inst;
}

+ (WWHHttpStringContent*)makeFromString:(NSString*)content {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> unmarshalledReturn;
    auto _comInst = WWHIHttpStringContentFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromString(nsStrToHstr(content).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHttpStringContent>(unmarshalledReturn.Get()) retain];
}

+ (WWHHttpStringContent*)makeFromStringWithEncoding:(NSString*)content encoding:(WSSUnicodeEncoding)encoding {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> unmarshalledReturn;
    auto _comInst = WWHIHttpStringContentFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromStringWithEncoding(nsStrToHstr(content).Get(),
                                                              (ABI::Windows::Storage::Streams::UnicodeEncoding)encoding,
                                                              unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHttpStringContent>(unmarshalledReturn.Get()) retain];
}

+ (WWHHttpStringContent*)makeFromStringWithEncodingAndMediaType:(NSString*)content
                                                       encoding:(WSSUnicodeEncoding)encoding
                                                      mediaType:(NSString*)mediaType {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> unmarshalledReturn;
    auto _comInst = WWHIHttpStringContentFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromStringWithEncodingAndMediaType(nsStrToHstr(content).Get(),
                                                                          (ABI::Windows::Storage::Streams::UnicodeEncoding)encoding,
                                                                          nsStrToHstr(mediaType).Get(),
                                                                          unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHttpStringContent>(unmarshalledReturn.Get()) retain];
}

- (WWHHHttpContentHeaderCollection*)headers {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Headers(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpContentHeaderCollection>(unmarshalledReturn.Get());
}

- (void)bufferAllAsyncWithSuccess:(void (^)(uint64_t))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->BufferAllAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
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

- (void)readAsBufferAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsBufferAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>* op,
                         uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

- (void)readAsInputStreamAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success
                                 progress:(void (^)(uint64_t))progress
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsInputStreamAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>* op,
                         uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IInputStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIInputStream>(result.Get()));
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

- (void)readAsStringAsyncWithSuccess:(void (^)(NSString*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsStringAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<HSTRING, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<HSTRING, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>* op, AsyncStatus status) {
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

- (BOOL)tryComputeLength:(uint64_t*)length {
    uint64_t lengthOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->TryComputeLength(&lengthOutUnmarshaled, &unmarshalledReturn));
    *length = lengthOutUnmarshaled;
    return (BOOL)unmarshalledReturn;
}

- (void)writeToStreamAsync:(RTObject<WSSIOutputStream>*)outputStream
                   success:(void (^)(uint64_t))success
                  progress:(void (^)(uint64_t))progress
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->WriteToStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(outputStream).Get(),
                                                    &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHttpBufferContent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::IHttpBufferContentFactory> WWHIHttpBufferContentFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::IHttpBufferContentFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.HttpBufferContent").Get(), &inst));
    return inst;
}

+ (WWHHttpBufferContent*)makeFromBuffer:(RTObject<WSSIBuffer>*)content {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> unmarshalledReturn;
    auto _comInst = WWHIHttpBufferContentFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(content).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHttpBufferContent>(unmarshalledReturn.Get()) retain];
}

+ (WWHHttpBufferContent*)makeFromBufferWithOffset:(RTObject<WSSIBuffer>*)content offset:(unsigned int)offset count:(unsigned int)count {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> unmarshalledReturn;
    auto _comInst = WWHIHttpBufferContentFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromBufferWithOffset(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(content).Get(),
                                                            offset,
                                                            count,
                                                            unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHttpBufferContent>(unmarshalledReturn.Get()) retain];
}

- (WWHHHttpContentHeaderCollection*)headers {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Headers(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpContentHeaderCollection>(unmarshalledReturn.Get());
}

- (void)bufferAllAsyncWithSuccess:(void (^)(uint64_t))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->BufferAllAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
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

- (void)readAsBufferAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsBufferAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>* op,
                         uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

- (void)readAsInputStreamAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success
                                 progress:(void (^)(uint64_t))progress
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsInputStreamAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>* op,
                         uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IInputStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIInputStream>(result.Get()));
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

- (void)readAsStringAsyncWithSuccess:(void (^)(NSString*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsStringAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<HSTRING, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<HSTRING, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>* op, AsyncStatus status) {
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

- (BOOL)tryComputeLength:(uint64_t*)length {
    uint64_t lengthOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->TryComputeLength(&lengthOutUnmarshaled, &unmarshalledReturn));
    *length = lengthOutUnmarshaled;
    return (BOOL)unmarshalledReturn;
}

- (void)writeToStreamAsync:(RTObject<WSSIOutputStream>*)outputStream
                   success:(void (^)(uint64_t))success
                  progress:(void (^)(uint64_t))progress
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->WriteToStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(outputStream).Get(),
                                                    &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHttpStreamContent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::IHttpStreamContentFactory> WWHIHttpStreamContentFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::IHttpStreamContentFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.HttpStreamContent").Get(), &inst));
    return inst;
}

+ (WWHHttpStreamContent*)makeFromInputStream:(RTObject<WSSIInputStream>*)content {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> unmarshalledReturn;
    auto _comInst = WWHIHttpStreamContentFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromInputStream(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(content).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHttpStreamContent>(unmarshalledReturn.Get()) retain];
}

- (WWHHHttpContentHeaderCollection*)headers {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Headers(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpContentHeaderCollection>(unmarshalledReturn.Get());
}

- (void)bufferAllAsyncWithSuccess:(void (^)(uint64_t))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->BufferAllAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
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

- (void)readAsBufferAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsBufferAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>* op,
                         uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

- (void)readAsInputStreamAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success
                                 progress:(void (^)(uint64_t))progress
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsInputStreamAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>* op,
                         uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IInputStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIInputStream>(result.Get()));
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

- (void)readAsStringAsyncWithSuccess:(void (^)(NSString*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsStringAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<HSTRING, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<HSTRING, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>* op, AsyncStatus status) {
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

- (BOOL)tryComputeLength:(uint64_t*)length {
    uint64_t lengthOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->TryComputeLength(&lengthOutUnmarshaled, &unmarshalledReturn));
    *length = lengthOutUnmarshaled;
    return (BOOL)unmarshalledReturn;
}

- (void)writeToStreamAsync:(RTObject<WSSIOutputStream>*)outputStream
                   success:(void (^)(uint64_t))success
                  progress:(void (^)(uint64_t))progress
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->WriteToStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(outputStream).Get(),
                                                    &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHttpFormUrlEncodedContent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::IHttpFormUrlEncodedContentFactory> WWHIHttpFormUrlEncodedContentFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::IHttpFormUrlEncodedContentFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.HttpFormUrlEncodedContent").Get(), &inst));
    return inst;
}

+ (WWHHttpFormUrlEncodedContent*)make:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, NSString * > */)content {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> unmarshalledReturn;
    auto _comInst = WWHIHttpFormUrlEncodedContentFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, HSTRING>*, IKeyValuePair<HSTRING, HSTRING>*>>::type>*>(
            ConvertToIterable<
                RTProxiedKeyValuePair,
                ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, HSTRING>*, IKeyValuePair<HSTRING, HSTRING>*>,
                RTProxiedKeyValuePair_NSString_NSString_create>(content)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHttpFormUrlEncodedContent>(unmarshalledReturn.Get()) retain];
}

- (WWHHHttpContentHeaderCollection*)headers {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Headers(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpContentHeaderCollection>(unmarshalledReturn.Get());
}

- (void)bufferAllAsyncWithSuccess:(void (^)(uint64_t))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->BufferAllAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
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

- (void)readAsBufferAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsBufferAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>* op,
                         uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

- (void)readAsInputStreamAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success
                                 progress:(void (^)(uint64_t))progress
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsInputStreamAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>* op,
                         uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IInputStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIInputStream>(result.Get()));
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

- (void)readAsStringAsyncWithSuccess:(void (^)(NSString*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsStringAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<HSTRING, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<HSTRING, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>* op, AsyncStatus status) {
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

- (BOOL)tryComputeLength:(uint64_t*)length {
    uint64_t lengthOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->TryComputeLength(&lengthOutUnmarshaled, &unmarshalledReturn));
    *length = lengthOutUnmarshaled;
    return (BOOL)unmarshalledReturn;
}

- (void)writeToStreamAsync:(RTObject<WSSIOutputStream>*)outputStream
                   success:(void (^)(uint64_t))success
                  progress:(void (^)(uint64_t))progress
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->WriteToStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(outputStream).Get(),
                                                    &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHttpMultipartContent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Web::Http::IHttpMultipartContentFactory> WWHIHttpMultipartContentFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::IHttpMultipartContentFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.HttpMultipartContent").Get(), &inst));
    return inst;
}

+ (WWHHttpMultipartContent*)makeWithSubtype:(NSString*)subtype {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> unmarshalledReturn;
    auto _comInst = WWHIHttpMultipartContentFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithSubtype(nsStrToHstr(subtype).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHttpMultipartContent>(unmarshalledReturn.Get()) retain];
}

+ (WWHHttpMultipartContent*)makeWithSubtypeAndBoundary:(NSString*)subtype boundary:(NSString*)boundary {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> unmarshalledReturn;
    auto _comInst = WWHIHttpMultipartContentFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithSubtypeAndBoundary(nsStrToHstr(subtype).Get(), nsStrToHstr(boundary).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHttpMultipartContent>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Http.HttpMultipartContent").Get(), &out));
    return [_createRtProxy<WWHHttpMultipartContent>(out.Get()) retain];
}

- (WWHHHttpContentHeaderCollection*)headers {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Headers(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpContentHeaderCollection>(unmarshalledReturn.Get());
}

- (void)bufferAllAsyncWithSuccess:(void (^)(uint64_t))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->BufferAllAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
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

- (void)readAsBufferAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsBufferAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>* op,
                         uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

- (void)readAsInputStreamAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success
                                 progress:(void (^)(uint64_t))progress
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsInputStreamAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>* op,
                         uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IInputStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIInputStream>(result.Get()));
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

- (void)readAsStringAsyncWithSuccess:(void (^)(NSString*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsStringAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<HSTRING, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<HSTRING, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>* op, AsyncStatus status) {
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

- (BOOL)tryComputeLength:(uint64_t*)length {
    uint64_t lengthOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->TryComputeLength(&lengthOutUnmarshaled, &unmarshalledReturn));
    *length = lengthOutUnmarshaled;
    return (BOOL)unmarshalledReturn;
}

- (void)writeToStreamAsync:(RTObject<WSSIOutputStream>*)outputStream
                   success:(void (^)(uint64_t))success
                  progress:(void (^)(uint64_t))progress
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->WriteToStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(outputStream).Get(),
                                                    &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (void)add:(RTObject<WWHIHttpContent>*)content {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpMultipartContent>(self);
    THROW_NS_IF_FAILED(_comInst->Add(_getRtInterface<ABI::Windows::Web::Http::IHttpContent>(content).Get()));
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHttpMultipartFormDataContent

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Http.HttpMultipartFormDataContent").Get(), &out));
    return [_createRtProxy<WWHHttpMultipartFormDataContent>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Web::Http::IHttpMultipartFormDataContentFactory> WWHIHttpMultipartFormDataContentFactory_inst() {
    ComPtr<ABI::Windows::Web::Http::IHttpMultipartFormDataContentFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.HttpMultipartFormDataContent").Get(),
                                                       &inst));
    return inst;
}

+ (WWHHttpMultipartFormDataContent*)makeWithBoundary:(NSString*)boundary {
    ComPtr<ABI::Windows::Web::Http::IHttpContent> unmarshalledReturn;
    auto _comInst = WWHIHttpMultipartFormDataContentFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithBoundary(nsStrToHstr(boundary).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WWHHttpMultipartFormDataContent>(unmarshalledReturn.Get()) retain];
}

- (WWHHHttpContentHeaderCollection*)headers {
    ComPtr<ABI::Windows::Web::Http::Headers::IHttpContentHeaderCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->get_Headers(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHHttpContentHeaderCollection>(unmarshalledReturn.Get());
}

- (void)bufferAllAsyncWithSuccess:(void (^)(uint64_t))success progress:(void (^)(uint64_t))progress failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->BufferAllAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
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

- (void)readAsBufferAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsBufferAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>* op,
                         uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, uint64_t>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

- (void)readAsInputStreamAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success
                                 progress:(void (^)(uint64_t))progress
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsInputStreamAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>* op,
                         uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IInputStream*, uint64_t>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IInputStream> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIInputStream>(result.Get()));
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

- (void)readAsStringAsyncWithSuccess:(void (^)(NSString*))success
                            progress:(void (^)(uint64_t))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsStringAsync(&unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<HSTRING, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<HSTRING, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<HSTRING, uint64_t>* op, AsyncStatus status) {
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

- (BOOL)tryComputeLength:(uint64_t*)length {
    uint64_t lengthOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->TryComputeLength(&lengthOutUnmarshaled, &unmarshalledReturn));
    *length = lengthOutUnmarshaled;
    return (BOOL)unmarshalledReturn;
}

- (void)writeToStreamAsync:(RTObject<WSSIOutputStream>*)outputStream
                   success:(void (^)(uint64_t))success
                  progress:(void (^)(uint64_t))progress
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpContent>(self);
    THROW_NS_IF_FAILED(_comInst->WriteToStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(outputStream).Get(),
                                                    &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (void)add:(RTObject<WWHIHttpContent>*)content {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpMultipartFormDataContent>(self);
    THROW_NS_IF_FAILED(_comInst->Add(_getRtInterface<ABI::Windows::Web::Http::IHttpContent>(content).Get()));
}

- (void)addWithName:(RTObject<WWHIHttpContent>*)content name:(NSString*)name {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpMultipartFormDataContent>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddWithName(_getRtInterface<ABI::Windows::Web::Http::IHttpContent>(content).Get(), nsStrToHstr(name).Get()));
}

- (void)addWithNameAndFileName:(RTObject<WWHIHttpContent>*)content name:(NSString*)name fileName:(NSString*)fileName {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpMultipartFormDataContent>(self);
    THROW_NS_IF_FAILED(_comInst->AddWithNameAndFileName(_getRtInterface<ABI::Windows::Web::Http::IHttpContent>(content).Get(),
                                                        nsStrToHstr(name).Get(),
                                                        nsStrToHstr(fileName).Get()));
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WWHHttpCookieManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::IHttpCookieManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)setCookie:(WWHHttpCookie*)cookie {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpCookieManager>(self);
    THROW_NS_IF_FAILED(_comInst->SetCookie(_getRtInterface<ABI::Windows::Web::Http::IHttpCookie>(cookie).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)setCookieWithThirdParty:(WWHHttpCookie*)cookie thirdParty:(BOOL)thirdParty {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpCookieManager>(self);
    THROW_NS_IF_FAILED(_comInst->SetCookieWithThirdParty(_getRtInterface<ABI::Windows::Web::Http::IHttpCookie>(cookie).Get(),
                                                         (boolean)thirdParty,
                                                         &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)deleteCookie:(WWHHttpCookie*)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpCookieManager>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteCookie(_getRtInterface<ABI::Windows::Web::Http::IHttpCookie>(cookie).Get()));
}

- (WWHHttpCookieCollection*)getCookies:(WFUri*)uri {
    ComPtr<IVectorView<ABI::Windows::Web::Http::HttpCookie*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::IHttpCookieManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetCookies(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpCookieCollection>(unmarshalledReturn.Get());
}

@end

@implementation WWHHttpProgress {
    ABI::Windows::Web::Http::HttpProgress structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Web::Http::HttpProgress)s {
    WWHHttpProgress* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Web::Http::HttpProgress*)internalStruct {
    return &structVal;
}
- (WWHHttpProgressStage)stage {
    return (WWHHttpProgressStage)structVal.Stage;
}
- (void)setStage:(WWHHttpProgressStage)val {
    structVal.Stage = (ABI::Windows::Web::Http::HttpProgressStage)val;
}
- (uint64_t)bytesSent {
    return structVal.BytesSent;
}
- (void)setBytesSent:(uint64_t)val {
    structVal.BytesSent = val;
}
- (id /* uint64_t */)totalBytesToSend {
    return MakeFromNullable<uint64_t, uint64_t>::convert(structVal.TotalBytesToSend);
}
- (void)setTotalBytesToSend:(id /* uint64_t */)val {
    structVal.TotalBytesToSend = BuildNullable<uint64_t>(val);
}
- (uint64_t)bytesReceived {
    return structVal.BytesReceived;
}
- (void)setBytesReceived:(uint64_t)val {
    structVal.BytesReceived = val;
}
- (id /* uint64_t */)totalBytesToReceive {
    return MakeFromNullable<uint64_t, uint64_t>::convert(structVal.TotalBytesToReceive);
}
- (void)setTotalBytesToReceive:(id /* uint64_t */)val {
    structVal.TotalBytesToReceive = BuildNullable<uint64_t>(val);
}
- (unsigned int)retries {
    return structVal.Retries;
}
- (void)setRetries:(unsigned int)val {
    structVal.Retries = val;
}
@end
id RTProxiedIterableNSArray_RTProxiedKeyValuePair_NSString_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<IterableArrayAdapterObj<
        IIterable<IKeyValuePair_HSTRING_HSTRING_Ptr>,
        RTIterableObj<IKeyValuePair_HSTRING_HSTRING_Ptr,
                      IIterable<IKeyValuePair_HSTRING_HSTRING_Ptr>,
                      RTProxiedKeyValuePair,
                      IKeyValuePair_HSTRING_HSTRING_Ptr,
                      RTProxiedKeyValuePair_NSString_NSString_create,
                      ConvertToIterable<RTProxiedKeyValuePair,
                                        ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, HSTRING>*,
                                                                                          IKeyValuePair<HSTRING, HSTRING>*>,
                                        RTProxiedKeyValuePair_NSString_NSString_create>>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedKeyValuePair_NSString_NSString_create(IInspectable* val) {
    std::unique_ptr<KeyValuePairAdapter> adapter = std::make_unique<KeyValuePairAdapterObj<
        RTKeyValuePairObj<HSTRING, HSTRING, HSTRING, HSTRING, NSString, NSString, dummyObjCCreator, dummyObjCCreator>>>();
    return _createRtProxyWithAdapter<RTProxiedKeyValuePair, KeyValuePairAdapter>(val, std::move(adapter));
    ;
}

id RTProxiedNSMutableDictionary_NSString_RTObject_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<
        MutableDictionaryAdapterObj<IMap<HSTRING, IInspectable*>,
                                    DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, IInspectable*>>,
                                    RTMapObj<HSTRING,
                                             HSTRING,
                                             IInspectable*,
                                             IInspectable*,
                                             NSString,
                                             RTObject,
                                             IMap<HSTRING, IInspectable*>,
                                             dummyObjCCreator,
                                             dummyObjCCreator,
                                             dummyWRLCreator,
                                             dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
