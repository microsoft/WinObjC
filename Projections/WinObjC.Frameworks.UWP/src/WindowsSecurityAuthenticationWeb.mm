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

// WindowsSecurityAuthenticationWeb.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Security.Authentication.Web.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSecurityAuthenticationWeb.h"
#include "WindowsSecurityAuthenticationWeb_priv.h"

@implementation WSAWWebAuthenticationResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::IWebAuthenticationResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)responseData {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::IWebAuthenticationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseData(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSAWWebAuthenticationStatus)responseStatus {
    ABI::Windows::Security::Authentication::Web::WebAuthenticationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::IWebAuthenticationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseStatus(&unmarshalledReturn));
    return (WSAWWebAuthenticationStatus)unmarshalledReturn;
}

- (unsigned int)responseErrorDetail {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::IWebAuthenticationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseErrorDetail(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WSAWWebAuthenticationBroker

ComPtr<ABI::Windows::Security::Authentication::Web::IWebAuthenticationBrokerStatics2> WSAWIWebAuthenticationBrokerStatics2_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Web::IWebAuthenticationBrokerStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Web.WebAuthenticationBroker").Get(), &inst));
    return inst;
}

+ (void)authenticateAndContinue:(WFUri*)requestUri {
    auto _comInst = WSAWIWebAuthenticationBrokerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->AuthenticateAndContinue(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(requestUri).Get()));
}

+ (void)authenticateWithCallbackUriAndContinue:(WFUri*)requestUri callbackUri:(WFUri*)callbackUri {
    auto _comInst = WSAWIWebAuthenticationBrokerStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->AuthenticateWithCallbackUriAndContinue(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(requestUri).Get(),
                                                         _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(callbackUri).Get()));
}

+ (void)authenticateWithCallbackUriContinuationDataAndOptionsAndContinue:(WFUri*)requestUri
                                                             callbackUri:(WFUri*)callbackUri
                                                        continuationData:(WFCValueSet*)continuationData
                                                                 options:(WSAWWebAuthenticationOptions)options {
    auto _comInst = WSAWIWebAuthenticationBrokerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->AuthenticateWithCallbackUriContinuationDataAndOptionsAndContinue(
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(requestUri).Get(),
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(callbackUri).Get(),
        _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(continuationData).Get(),
        (ABI::Windows::Security::Authentication::Web::WebAuthenticationOptions)options));
}

+ (void)authenticateSilentlyAsync:(WFUri*)requestUri
                          success:(void (^)(WSAWWebAuthenticationResult*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Authentication::Web::WebAuthenticationResult*>>
        unmarshalledReturn;
    auto _comInst = WSAWIWebAuthenticationBrokerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->AuthenticateSilentlyAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(requestUri).Get(),
                                                           &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Authentication::Web::WebAuthenticationResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Authentication::Web::WebAuthenticationResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Authentication::Web::IWebAuthenticationResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSAWWebAuthenticationResult>(result.Get()));
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

+ (void)authenticateSilentlyWithOptionsAsync:(WFUri*)requestUri
                                     options:(WSAWWebAuthenticationOptions)options
                                     success:(void (^)(WSAWWebAuthenticationResult*))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Authentication::Web::WebAuthenticationResult*>>
        unmarshalledReturn;
    auto _comInst = WSAWIWebAuthenticationBrokerStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->AuthenticateSilentlyWithOptionsAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(requestUri).Get(),
                                                       (ABI::Windows::Security::Authentication::Web::WebAuthenticationOptions)options,
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Authentication::Web::WebAuthenticationResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Authentication::Web::WebAuthenticationResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Authentication::Web::IWebAuthenticationResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSAWWebAuthenticationResult>(result.Get()));
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

ComPtr<ABI::Windows::Security::Authentication::Web::IWebAuthenticationBrokerStatics> WSAWIWebAuthenticationBrokerStatics_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Web::IWebAuthenticationBrokerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Web.WebAuthenticationBroker").Get(), &inst));
    return inst;
}

+ (void)authenticateWithCallbackUriAsync:(WSAWWebAuthenticationOptions)options
                              requestUri:(WFUri*)requestUri
                             callbackUri:(WFUri*)callbackUri
                                 success:(void (^)(WSAWWebAuthenticationResult*))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Authentication::Web::WebAuthenticationResult*>>
        unmarshalledReturn;
    auto _comInst = WSAWIWebAuthenticationBrokerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->AuthenticateWithCallbackUriAsync((ABI::Windows::Security::Authentication::Web::WebAuthenticationOptions)options,
                                                   _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(requestUri).Get(),
                                                   _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(callbackUri).Get(),
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Authentication::Web::WebAuthenticationResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Authentication::Web::WebAuthenticationResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Authentication::Web::IWebAuthenticationResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSAWWebAuthenticationResult>(result.Get()));
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

+ (void)authenticateWithoutCallbackUriAsync:(WSAWWebAuthenticationOptions)options
                                 requestUri:(WFUri*)requestUri
                                    success:(void (^)(WSAWWebAuthenticationResult*))success
                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Authentication::Web::WebAuthenticationResult*>>
        unmarshalledReturn;
    auto _comInst = WSAWIWebAuthenticationBrokerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->AuthenticateWithoutCallbackUriAsync((ABI::Windows::Security::Authentication::Web::WebAuthenticationOptions)options,
                                                      _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(requestUri).Get(),
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Authentication::Web::WebAuthenticationResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Authentication::Web::WebAuthenticationResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Authentication::Web::IWebAuthenticationResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSAWWebAuthenticationResult>(result.Get()));
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

+ (WFUri*)getCurrentApplicationCallbackUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = WSAWIWebAuthenticationBrokerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetCurrentApplicationCallbackUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

@end
