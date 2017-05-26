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

// WindowsWebHttpFilters.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Web.Http.Filters.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsWebHttpFilters.h"
#include "WindowsWebHttpFilters_priv.h"

@implementation WWHFIHttpFilter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Filters::IHttpFilter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)sendRequestAsync:(WWHHttpRequestMessage*)request
                 success:(void (^)(WWHHttpResponseMessage*))success
                progress:(void (^)(WWHHttpProgress*))progress
                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                 ABI::Windows::Web::Http::HttpProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpFilter>(self);
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WWHFHttpCacheControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Filters::IHttpCacheControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WWHFHttpCacheReadBehavior)readBehavior {
    ABI::Windows::Web::Http::Filters::HttpCacheReadBehavior unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpCacheControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadBehavior(&unmarshalledReturn));
    return (WWHFHttpCacheReadBehavior)unmarshalledReturn;
}

- (void)setReadBehavior:(WWHFHttpCacheReadBehavior)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpCacheControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReadBehavior((ABI::Windows::Web::Http::Filters::HttpCacheReadBehavior)value));
}

- (WWHFHttpCacheWriteBehavior)writeBehavior {
    ABI::Windows::Web::Http::Filters::HttpCacheWriteBehavior unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpCacheControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_WriteBehavior(&unmarshalledReturn));
    return (WWHFHttpCacheWriteBehavior)unmarshalledReturn;
}

- (void)setWriteBehavior:(WWHFHttpCacheWriteBehavior)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpCacheControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_WriteBehavior((ABI::Windows::Web::Http::Filters::HttpCacheWriteBehavior)value));
}

@end

@implementation WWHFHttpBaseProtocolFilter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Web.Http.Filters.HttpBaseProtocolFilter").Get(), &out));
    return [_createRtProxy<WWHFHttpBaseProtocolFilter>(out.Get()) retain];
}

- (BOOL)allowAutoRedirect {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowAutoRedirect(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowAutoRedirect:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowAutoRedirect((boolean)value));
}

- (BOOL)allowUI {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowUI(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowUI:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowUI((boolean)value));
}

- (BOOL)automaticDecompression {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutomaticDecompression(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAutomaticDecompression:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutomaticDecompression((boolean)value));
}

- (WWHFHttpCacheControl*)cacheControl {
    ComPtr<ABI::Windows::Web::Http::Filters::IHttpCacheControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_CacheControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHFHttpCacheControl>(unmarshalledReturn.Get());
}

- (WWHHttpCookieManager*)cookieManager {
    ComPtr<ABI::Windows::Web::Http::IHttpCookieManager> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_CookieManager(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpCookieManager>(unmarshalledReturn.Get());
}

- (WSCCCertificate*)clientCertificate {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClientCertificate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (void)setClientCertificate:(WSCCCertificate*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ClientCertificate(_getRtInterface<ABI::Windows::Security::Cryptography::Certificates::ICertificate>(value).Get()));
}

- (NSMutableArray* /* WSCCChainValidationResult */)ignorableServerCertificateErrors {
    ComPtr<IVector<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IgnorableServerCertificateErrors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WSCCChainValidationResult_create(unmarshalledReturn.Get());
}

- (unsigned int)maxConnectionsPerServer {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxConnectionsPerServer(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMaxConnectionsPerServer:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxConnectionsPerServer(value));
}

- (WSCPasswordCredential*)proxyCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProxyCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setProxyCredential:(WSCPasswordCredential*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ProxyCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(value).Get()));
}

- (WSCPasswordCredential*)serverCredential {
    ComPtr<ABI::Windows::Security::Credentials::IPasswordCredential> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCredential(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCPasswordCredential>(unmarshalledReturn.Get());
}

- (void)setServerCredential:(WSCPasswordCredential*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ServerCredential(_getRtInterface<ABI::Windows::Security::Credentials::IPasswordCredential>(value).Get()));
}

- (BOOL)useProxy {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(_comInst->get_UseProxy(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setUseProxy:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter>(self);
    THROW_NS_IF_FAILED(_comInst->put_UseProxy((boolean)value));
}

- (void)sendRequestAsync:(WWHHttpRequestMessage*)request
                 success:(void (^)(WWHHttpResponseMessage*))success
                progress:(void (^)(WWHHttpProgress*))progress
                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Web::Http::HttpResponseMessage*,
                                                                 ABI::Windows::Web::Http::HttpProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpFilter>(self);
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (WWHHttpVersion)maxVersion {
    ABI::Windows::Web::Http::HttpVersion unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxVersion(&unmarshalledReturn));
    return (WWHHttpVersion)unmarshalledReturn;
}

- (void)setMaxVersion:(WWHHttpVersion)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter2>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxVersion((ABI::Windows::Web::Http::HttpVersion)value));
}

- (WWHFHttpCookieUsageBehavior)cookieUsageBehavior {
    ABI::Windows::Web::Http::Filters::HttpCookieUsageBehavior unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter3>(self);
    THROW_NS_IF_FAILED(_comInst->get_CookieUsageBehavior(&unmarshalledReturn));
    return (WWHFHttpCookieUsageBehavior)unmarshalledReturn;
}

- (void)setCookieUsageBehavior:(WWHFHttpCookieUsageBehavior)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter3>(self);
    THROW_NS_IF_FAILED(_comInst->put_CookieUsageBehavior((ABI::Windows::Web::Http::Filters::HttpCookieUsageBehavior)value));
}

- (EventRegistrationToken)addServerCustomValidationRequestedEvent:
    (void (^)(WWHFHttpBaseProtocolFilter*, WWHFHttpServerCustomValidationRequestedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter4>(self);
    THROW_NS_IF_FAILED(_comInst->add_ServerCustomValidationRequested(
        Make<
            ITypedEventHandler_Windows_Web_Http_Filters_HttpBaseProtocolFilter_Windows_Web_Http_Filters_HttpServerCustomValidationRequestedEventArgs>(
            eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeServerCustomValidationRequestedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter4>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ServerCustomValidationRequested(eventCookie));
}

- (void)clearAuthenticationCache {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpBaseProtocolFilter4>(self);
    THROW_NS_IF_FAILED(_comInst->ClearAuthenticationCache());
}

@end

@implementation WWHFHttpServerCustomValidationRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WWHHttpRequestMessage*)requestMessage {
    ComPtr<ABI::Windows::Web::Http::IHttpRequestMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpRequestMessage>(unmarshalledReturn.Get());
}

- (WSCCCertificate*)serverCertificate {
    ComPtr<ABI::Windows::Security::Cryptography::Certificates::ICertificate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCCCertificate>(unmarshalledReturn.Get());
}

- (WNSSocketSslErrorSeverity)serverCertificateErrorSeverity {
    ABI::Windows::Networking::Sockets::SocketSslErrorSeverity unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificateErrorSeverity(&unmarshalledReturn));
    return (WNSSocketSslErrorSeverity)unmarshalledReturn;
}

- (NSArray* /* WSCCChainValidationResult */)serverCertificateErrors {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerCertificateErrors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCChainValidationResult_create(unmarshalledReturn.Get());
}

- (NSArray* /* WSCCCertificate* */)serverIntermediateCertificates {
    ComPtr<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServerIntermediateCertificates(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCCCertificate_create(unmarshalledReturn.Get());
}

- (void)reject {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->Reject());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_WSCCCertificate_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>,
                                         RTArrayObj<ABI::Windows::Security::Cryptography::Certificates::ICertificate*,
                                                    IVectorView<ABI::Windows::Security::Cryptography::Certificates::Certificate*>,
                                                    WSCCCertificate,
                                                    ABI::Windows::Security::Cryptography::Certificates::Certificate*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSCCChainValidationResult_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>,
                                         RTArrayObj<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult,
                                                    IVectorView<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>,
                                                    WSCCChainValidationResult,
                                                    ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WSCCChainValidationResult_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>,
                               RTMutableArrayObj<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult,
                                                 IVector<ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult>,
                                                 WSCCChainValidationResult,
                                                 ABI::Windows::Security::Cryptography::Certificates::ChainValidationResult,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
