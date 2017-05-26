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

// WindowsSecurityAuthenticationWebCore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Security.Authentication.Web.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSecurityAuthenticationWebCore.h"
#include "WindowsSecurityAuthenticationWebCore_priv.h"

@implementation WSAWCWebAccountEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebAccountEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSCWebAccount*)account {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccount> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebAccountEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Account(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCWebAccount>(unmarshalledReturn.Get());
}

@end

@implementation WSAWCWebTokenRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequestFactory> WSAWCIWebTokenRequestFactory_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequestFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Web.Core.WebTokenRequest").Get(), &inst));
    return inst;
}

+ (WSAWCWebTokenRequest*)make:(WSCWebAccountProvider*)provider scope:(NSString*)scope clientId:(NSString*)clientId {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest> unmarshalledReturn;
    auto _comInst = WSAWCIWebTokenRequestFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccountProvider>(provider).Get(),
                                        nsStrToHstr(scope).Get(),
                                        nsStrToHstr(clientId).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSAWCWebTokenRequest>(unmarshalledReturn.Get()) retain];
}

+ (WSAWCWebTokenRequest*)makeWithPromptType:(WSCWebAccountProvider*)provider
                                      scope:(NSString*)scope
                                   clientId:(NSString*)clientId
                                 promptType:(WSAWCWebTokenRequestPromptType)promptType {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest> unmarshalledReturn;
    auto _comInst = WSAWCIWebTokenRequestFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithPromptType(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccountProvider>(provider).Get(),
                                       nsStrToHstr(scope).Get(),
                                       nsStrToHstr(clientId).Get(),
                                       (ABI::Windows::Security::Authentication::Web::Core::WebTokenRequestPromptType)promptType,
                                       unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSAWCWebTokenRequest>(unmarshalledReturn.Get()) retain];
}

+ (WSAWCWebTokenRequest*)makeWithProvider:(WSCWebAccountProvider*)provider {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest> unmarshalledReturn;
    auto _comInst = WSAWCIWebTokenRequestFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithProvider(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccountProvider>(provider).Get(),
                                     unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSAWCWebTokenRequest>(unmarshalledReturn.Get()) retain];
}

+ (WSAWCWebTokenRequest*)makeWithScope:(WSCWebAccountProvider*)provider scope:(NSString*)scope {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest> unmarshalledReturn;
    auto _comInst = WSAWCIWebTokenRequestFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithScope(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccountProvider>(provider).Get(),
                                                 nsStrToHstr(scope).Get(),
                                                 unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSAWCWebTokenRequest>(unmarshalledReturn.Get()) retain];
}

- (WSCWebAccountProvider*)webAccountProvider {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccountProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebAccountProvider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCWebAccountProvider>(unmarshalledReturn.Get());
}

- (NSString*)scope {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Scope(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)clientId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClientId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSAWCWebTokenRequestPromptType)promptType {
    ABI::Windows::Security::Authentication::Web::Core::WebTokenRequestPromptType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_PromptType(&unmarshalledReturn));
    return (WSAWCWebTokenRequestPromptType)unmarshalledReturn;
}

- (NSMutableDictionary* /* NSString *, NSString * */)properties {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableDictionary* /* NSString *, NSString * */)appProperties {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WSAWCWebAccountMonitor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebAccountMonitor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addUpdatedEvent:(void (^)(WSAWCWebAccountMonitor*, WSAWCWebAccountEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebAccountMonitor>(self);
    THROW_NS_IF_FAILED(_comInst->add_Updated(
        Make<
            ITypedEventHandler_Windows_Security_Authentication_Web_Core_WebAccountMonitor_Windows_Security_Authentication_Web_Core_WebAccountEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebAccountMonitor>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Updated(token));
}

- (EventRegistrationToken)addRemovedEvent:(void (^)(WSAWCWebAccountMonitor*, WSAWCWebAccountEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebAccountMonitor>(self);
    THROW_NS_IF_FAILED(_comInst->add_Removed(
        Make<
            ITypedEventHandler_Windows_Security_Authentication_Web_Core_WebAccountMonitor_Windows_Security_Authentication_Web_Core_WebAccountEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebAccountMonitor>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Removed(token));
}

- (EventRegistrationToken)addDefaultSignInAccountChangedEvent:(void (^)(WSAWCWebAccountMonitor*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebAccountMonitor>(self);
    THROW_NS_IF_FAILED(_comInst->add_DefaultSignInAccountChanged(
        Make<ITypedEventHandler_Windows_Security_Authentication_Web_Core_WebAccountMonitor_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDefaultSignInAccountChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebAccountMonitor>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DefaultSignInAccountChanged(token));
}

@end

@implementation WSAWCWebAuthenticationCoreManager

ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics3>
WSAWCIWebAuthenticationCoreManagerStatics3_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics3> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Web.Core.WebAuthenticationCoreManager").Get(), &inst));
    return inst;
}

+ (WSAWCWebAccountMonitor*)createWebAccountMonitor:(id<NSFastEnumeration> /* WSCWebAccount* */)webAccounts {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebAccountMonitor> unmarshalledReturn;
    auto _comInst = WSAWCIWebAuthenticationCoreManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWebAccountMonitor(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Security::Credentials::WebAccount*,
                                                              ABI::Windows::Security::Credentials::IWebAccount*>>::type>*>(
            ConvertToIterable<WSCWebAccount,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Security::Credentials::WebAccount*,
                                                                                ABI::Windows::Security::Credentials::IWebAccount*>>(
                webAccounts)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAWCWebAccountMonitor>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics2>
WSAWCIWebAuthenticationCoreManagerStatics2_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Web.Core.WebAuthenticationCoreManager").Get(), &inst));
    return inst;
}

+ (void)findAccountProviderWithAuthorityForUserAsync:(NSString*)webAccountProviderId
                                           authority:(NSString*)authority
                                                user:(WSUser*)user
                                             success:(void (^)(WSCWebAccountProvider*))success
                                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::WebAccountProvider*>> unmarshalledReturn;
    auto _comInst = WSAWCIWebAuthenticationCoreManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->FindAccountProviderWithAuthorityForUserAsync(nsStrToHstr(webAccountProviderId).Get(),
                                                                              nsStrToHstr(authority).Get(),
                                                                              _getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::WebAccountProvider*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::WebAccountProvider*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Credentials::IWebAccountProvider> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSCWebAccountProvider>(result.Get()));
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

ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics>
WSAWCIWebAuthenticationCoreManagerStatics_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Web.Core.WebAuthenticationCoreManager").Get(), &inst));
    return inst;
}

+ (void)getTokenSilentlyAsync:(WSAWCWebTokenRequest*)request
                      success:(void (^)(WSAWCWebTokenRequestResult*))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Authentication::Web::Core::WebTokenRequestResult*>>
        unmarshalledReturn;
    auto _comInst = WSAWCIWebAuthenticationCoreManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetTokenSilentlyAsync(_getRtInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest>(request).Get(),
                                        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Security::Authentication::Web::Core::WebTokenRequestResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Authentication::Web::Core::WebTokenRequestResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequestResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSAWCWebTokenRequestResult>(result.Get()));
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

+ (void)getTokenSilentlyWithWebAccountAsync:(WSAWCWebTokenRequest*)request
                                 webAccount:(WSCWebAccount*)webAccount
                                    success:(void (^)(WSAWCWebTokenRequestResult*))success
                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Authentication::Web::Core::WebTokenRequestResult*>>
        unmarshalledReturn;
    auto _comInst = WSAWCIWebAuthenticationCoreManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetTokenSilentlyWithWebAccountAsync(
        _getRtInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest>(request).Get(),
        _getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(webAccount).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Security::Authentication::Web::Core::WebTokenRequestResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Authentication::Web::Core::WebTokenRequestResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequestResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSAWCWebTokenRequestResult>(result.Get()));
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

+ (void)requestTokenAsync:(WSAWCWebTokenRequest*)request
                  success:(void (^)(WSAWCWebTokenRequestResult*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Authentication::Web::Core::WebTokenRequestResult*>>
        unmarshalledReturn;
    auto _comInst = WSAWCIWebAuthenticationCoreManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->RequestTokenAsync(_getRtInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest>(request).Get(),
                                    &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Security::Authentication::Web::Core::WebTokenRequestResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Authentication::Web::Core::WebTokenRequestResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequestResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSAWCWebTokenRequestResult>(result.Get()));
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

+ (void)requestTokenWithWebAccountAsync:(WSAWCWebTokenRequest*)request
                             webAccount:(WSCWebAccount*)webAccount
                                success:(void (^)(WSAWCWebTokenRequestResult*))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Authentication::Web::Core::WebTokenRequestResult*>>
        unmarshalledReturn;
    auto _comInst = WSAWCIWebAuthenticationCoreManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestTokenWithWebAccountAsync(
        _getRtInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest>(request).Get(),
        _getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(webAccount).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Security::Authentication::Web::Core::WebTokenRequestResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Authentication::Web::Core::WebTokenRequestResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequestResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSAWCWebTokenRequestResult>(result.Get()));
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

+ (void)findAccountAsync:(WSCWebAccountProvider*)provider
            webAccountId:(NSString*)webAccountId
                 success:(void (^)(WSCWebAccount*))success
                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::WebAccount*>> unmarshalledReturn;
    auto _comInst = WSAWCIWebAuthenticationCoreManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAccountAsync(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccountProvider>(provider).Get(),
                                                  nsStrToHstr(webAccountId).Get(),
                                                  &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::WebAccount*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::WebAccount*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Security::Credentials::IWebAccount> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSCWebAccount>(result.Get()));
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

+ (void)findAccountProviderAsync:(NSString*)webAccountProviderId
                         success:(void (^)(WSCWebAccountProvider*))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::WebAccountProvider*>> unmarshalledReturn;
    auto _comInst = WSAWCIWebAuthenticationCoreManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAccountProviderAsync(nsStrToHstr(webAccountProviderId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::WebAccountProvider*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::WebAccountProvider*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Credentials::IWebAccountProvider> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSCWebAccountProvider>(result.Get()));
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

+ (void)findAccountProviderWithAuthorityAsync:(NSString*)webAccountProviderId
                                    authority:(NSString*)authority
                                      success:(void (^)(WSCWebAccountProvider*))success
                                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::WebAccountProvider*>> unmarshalledReturn;
    auto _comInst = WSAWCIWebAuthenticationCoreManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAccountProviderWithAuthorityAsync(nsStrToHstr(webAccountProviderId).Get(),
                                                                       nsStrToHstr(authority).Get(),
                                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::WebAccountProvider*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::WebAccountProvider*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Credentials::IWebAccountProvider> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSCWebAccountProvider>(result.Get()));
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

@implementation WSAWCWebProviderError

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebProviderErrorFactory> WSAWCIWebProviderErrorFactory_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebProviderErrorFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Web.Core.WebProviderError").Get(), &inst));
    return inst;
}

+ (WSAWCWebProviderError*)make:(unsigned int)errorCode errorMessage:(NSString*)errorMessage {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError> unmarshalledReturn;
    auto _comInst = WSAWCIWebProviderErrorFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(errorCode, nsStrToHstr(errorMessage).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSAWCWebProviderError>(unmarshalledReturn.Get()) retain];
}

- (unsigned int)errorCode {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)errorMessage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorMessage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSMutableDictionary* /* NSString *, NSString * */)properties {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WSAWCWebTokenResponse

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenResponse> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenResponseFactory> WSAWCIWebTokenResponseFactory_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenResponseFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Web.Core.WebTokenResponse").Get(), &inst));
    return inst;
}

+ (WSAWCWebTokenResponse*)makeWithToken:(NSString*)token {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenResponse> unmarshalledReturn;
    auto _comInst = WSAWCIWebTokenResponseFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithToken(nsStrToHstr(token).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSAWCWebTokenResponse>(unmarshalledReturn.Get()) retain];
}

+ (WSAWCWebTokenResponse*)makeWithTokenAndAccount:(NSString*)token webAccount:(WSCWebAccount*)webAccount {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenResponse> unmarshalledReturn;
    auto _comInst = WSAWCIWebTokenResponseFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithTokenAndAccount(nsStrToHstr(token).Get(),
                                            _getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(webAccount).Get(),
                                            unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSAWCWebTokenResponse>(unmarshalledReturn.Get()) retain];
}

+ (WSAWCWebTokenResponse*)makeWithTokenAccountAndError:(NSString*)token
                                            webAccount:(WSCWebAccount*)webAccount
                                                 error:(WSAWCWebProviderError*)error {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenResponse> unmarshalledReturn;
    auto _comInst = WSAWCIWebTokenResponseFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithTokenAccountAndError(
        nsStrToHstr(token).Get(),
        _getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(webAccount).Get(),
        _getRtInterface<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError>(error).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSAWCWebTokenResponse>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Security.Authentication.Web.Core.WebTokenResponse").Get(),
                                              &out));
    return [_createRtProxy<WSAWCWebTokenResponse>(out.Get()) retain];
}

- (NSString*)token {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenResponse>(self);
    THROW_NS_IF_FAILED(_comInst->get_Token(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSAWCWebProviderError*)providerError {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenResponse>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProviderError(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAWCWebProviderError>(unmarshalledReturn.Get());
}

- (WSCWebAccount*)webAccount {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccount> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenResponse>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebAccount(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCWebAccount>(unmarshalledReturn.Get());
}

- (NSMutableDictionary* /* NSString *, NSString * */)properties {
    ComPtr<IMap<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenResponse>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WSAWCWebTokenRequestResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequestResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WSAWCWebTokenResponse* */)responseData {
    ComPtr<IVectorView<ABI::Windows::Security::Authentication::Web::Core::WebTokenResponse*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequestResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseData(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSAWCWebTokenResponse_create(unmarshalledReturn.Get());
}

- (WSAWCWebTokenRequestStatus)responseStatus {
    ABI::Windows::Security::Authentication::Web::Core::WebTokenRequestStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequestResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseStatus(&unmarshalledReturn));
    return (WSAWCWebTokenRequestStatus)unmarshalledReturn;
}

- (WSAWCWebProviderError*)responseError {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequestResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseError(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAWCWebProviderError>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)invalidateCacheAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequestResult>(self);
    THROW_NS_IF_FAILED(_comInst->InvalidateCacheAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

id RTProxiedIterableNSArray_WSCWebAccount_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Security::Credentials::WebAccount*>,
                                                 RTIterableObj<ABI::Windows::Security::Credentials::IWebAccount*,
                                                               IIterable<ABI::Windows::Security::Credentials::WebAccount*>,
                                                               WSCWebAccount,
                                                               ABI::Windows::Security::Credentials::WebAccount*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSAWCWebTokenResponse_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Security::Authentication::Web::Core::WebTokenResponse*>,
                                         RTArrayObj<ABI::Windows::Security::Authentication::Web::Core::IWebTokenResponse*,
                                                    IVectorView<ABI::Windows::Security::Authentication::Web::Core::WebTokenResponse*>,
                                                    WSAWCWebTokenResponse,
                                                    ABI::Windows::Security::Authentication::Web::Core::WebTokenResponse*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableDictionary_NSString_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<
        MutableDictionaryAdapterObj<IMap<HSTRING, HSTRING>,
                                    DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, HSTRING>>,
                                    RTMapObj<HSTRING,
                                             HSTRING,
                                             HSTRING,
                                             HSTRING,
                                             NSString,
                                             NSString,
                                             IMap<HSTRING, HSTRING>,
                                             dummyObjCCreator,
                                             dummyObjCCreator,
                                             dummyWRLCreator,
                                             dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
