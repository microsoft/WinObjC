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

// WindowsSecurityAuthenticationIdentityCore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Security.Authentication.Identity.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSecurityAuthenticationIdentityCore.h"
#include "WindowsSecurityAuthenticationIdentityCore_priv.h"

@implementation WSAICMicrosoftAccountMultiFactorSessionInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)userAccountId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserAccountId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)sessionId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SessionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displaySessionId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplaySessionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSAICMicrosoftAccountMultiFactorSessionApprovalStatus)approvalStatus {
    ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionApprovalStatus unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApprovalStatus(&unmarshalledReturn));
    return (WSAICMicrosoftAccountMultiFactorSessionApprovalStatus)unmarshalledReturn;
}

- (WSAICMicrosoftAccountMultiFactorAuthenticationType)authenticationType {
    ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AuthenticationType(&unmarshalledReturn));
    return (WSAICMicrosoftAccountMultiFactorAuthenticationType)unmarshalledReturn;
}

- (WFDateTime*)requestTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFDateTime*)expirationTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

@end

@implementation WSAICMicrosoftAccountMultiFactorOneTimeCodedInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)code {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Code(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFTimeSpan*)timeInterval {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeInterval(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)timeToLive {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeToLive(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WSAICMicrosoftAccountMultiFactorServiceResponse)serviceResponse {
    ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceResponse(&unmarshalledReturn));
    return (WSAICMicrosoftAccountMultiFactorServiceResponse)unmarshalledReturn;
}

@end

@implementation WSAICMicrosoftAccountMultiFactorGetSessionsResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WSAICMicrosoftAccountMultiFactorSessionInfo* */)sessions {
    ComPtr<IVectorView<ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo*>> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Sessions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSAICMicrosoftAccountMultiFactorSessionInfo_create(unmarshalledReturn.Get());
}

- (WSAICMicrosoftAccountMultiFactorServiceResponse)serviceResponse {
    ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceResponse(&unmarshalledReturn));
    return (WSAICMicrosoftAccountMultiFactorServiceResponse)unmarshalledReturn;
}

@end

@implementation WSAICMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>
        defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WSAICMicrosoftAccountMultiFactorSessionInfo* */)sessions {
    ComPtr<IVectorView<ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Sessions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSAICMicrosoftAccountMultiFactorSessionInfo_create(unmarshalledReturn.Get());
}

- (NSArray* /* NSString * */)unregisteredAccounts {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnregisteredAccounts(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (WSAICMicrosoftAccountMultiFactorServiceResponse)serviceResponse {
    ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceResponse(&unmarshalledReturn));
    return (WSAICMicrosoftAccountMultiFactorServiceResponse)unmarshalledReturn;
}

@end

@implementation WSAICMicrosoftAccountMultiFactorAuthenticationManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics>
WSAICIMicrosoftAccountMultiFactorAuthenticatorStatics_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorAuthenticationManager").Get(),
        &inst));
    return inst;
}

+ (WSAICMicrosoftAccountMultiFactorAuthenticationManager*)current {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager> unmarshalledReturn;
    auto _comInst = WSAICIMicrosoftAccountMultiFactorAuthenticatorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Current(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAICMicrosoftAccountMultiFactorAuthenticationManager>(unmarshalledReturn.Get());
}

- (void)getOneTimePassCodeAsync:(NSString*)userAccountId
                     codeLength:(unsigned int)codeLength
                        success:(void (^)(WSAICMicrosoftAccountMultiFactorOneTimeCodedInfo*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo*>>
        unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>(self);
    THROW_NS_IF_FAILED(_comInst->GetOneTimePassCodeAsync(nsStrToHstr(userAccountId).Get(), codeLength, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
            ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                  ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSAICMicrosoftAccountMultiFactorOneTimeCodedInfo>(result.Get()));
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

- (void)addDeviceAsync:(NSString*)userAccountId
    authenticationToken:(NSString*)authenticationToken
           wnsChannelId:(NSString*)wnsChannelId
                success:(void (^)(WSAICMicrosoftAccountMultiFactorServiceResponse))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>>
        unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>(self);
    THROW_NS_IF_FAILED(_comInst->AddDeviceAsync(nsStrToHstr(userAccountId).Get(),
                                                nsStrToHstr(authenticationToken).Get(),
                                                nsStrToHstr(wnsChannelId).Get(),
                                                &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
            ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSAICMicrosoftAccountMultiFactorServiceResponse)result);
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

- (void)removeDeviceAsync:(NSString*)userAccountId
                  success:(void (^)(WSAICMicrosoftAccountMultiFactorServiceResponse))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>>
        unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveDeviceAsync(nsStrToHstr(userAccountId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
            ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSAICMicrosoftAccountMultiFactorServiceResponse)result);
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

- (void)updateWnsChannelAsync:(NSString*)userAccountId
                   channelUri:(NSString*)channelUri
                      success:(void (^)(WSAICMicrosoftAccountMultiFactorServiceResponse))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>>
        unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->UpdateWnsChannelAsync(nsStrToHstr(userAccountId).Get(), nsStrToHstr(channelUri).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
            ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSAICMicrosoftAccountMultiFactorServiceResponse)result);
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

- (void)getSessionsAsync:(id<NSFastEnumeration> /* NSString * */)userAccountIdList
                 success:(void (^)(WSAICMicrosoftAccountMultiFactorGetSessionsResult*))success
                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult*>>
        unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetSessionsAsync(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                       ConvertToIterable<NSString, HSTRING>(userAccountIdList).Get()),
                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
            ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<
                        ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSAICMicrosoftAccountMultiFactorGetSessionsResult>(result.Get()));
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

- (void)getSessionsAndUnregisteredAccountsAsync:(id<NSFastEnumeration> /* NSString * */)userAccountIdList
                                        success:(void (^)(WSAICMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo*))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo*>>
        unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>(self);
    THROW_NS_IF_FAILED(_comInst->GetSessionsAndUnregisteredAccountsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(userAccountIdList).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
            ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo*>,
        FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<
            ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<
                    ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>
                    result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSAICMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>(result.Get()));
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

- (void)approveSessionUsingAuthSessionInfoAsync:(WSAICMicrosoftAccountMultiFactorSessionAuthenticationStatus)sessionAuthentictionStatus
                      authenticationSessionInfo:(WSAICMicrosoftAccountMultiFactorSessionInfo*)authenticationSessionInfo
                                        success:(void (^)(WSAICMicrosoftAccountMultiFactorServiceResponse))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>>
        unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>(self);
    THROW_NS_IF_FAILED(_comInst->ApproveSessionUsingAuthSessionInfoAsync(
        (ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus)
            sessionAuthentictionStatus,
        _getRtInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo>(
            authenticationSessionInfo)
            .Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
            ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSAICMicrosoftAccountMultiFactorServiceResponse)result);
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

- (void)approveSessionAsync:(WSAICMicrosoftAccountMultiFactorSessionAuthenticationStatus)sessionAuthentictionStatus
                userAccountId:(NSString*)userAccountId
                    sessionId:(NSString*)sessionId
    sessionAuthenticationType:(WSAICMicrosoftAccountMultiFactorAuthenticationType)sessionAuthenticationType
                      success:(void (^)(WSAICMicrosoftAccountMultiFactorServiceResponse))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>>
        unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>(self);
    THROW_NS_IF_FAILED(_comInst->ApproveSessionAsync(
        (ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus)
            sessionAuthentictionStatus,
        nsStrToHstr(userAccountId).Get(),
        nsStrToHstr(sessionId).Get(),
        (ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType)sessionAuthenticationType,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
            ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSAICMicrosoftAccountMultiFactorServiceResponse)result);
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

- (void)denySessionUsingAuthSessionInfoAsync:(WSAICMicrosoftAccountMultiFactorSessionInfo*)authenticationSessionInfo
                                     success:(void (^)(WSAICMicrosoftAccountMultiFactorServiceResponse))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>>
        unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>(self);
    THROW_NS_IF_FAILED(_comInst->DenySessionUsingAuthSessionInfoAsync(
        _getRtInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo>(
            authenticationSessionInfo)
            .Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
            ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSAICMicrosoftAccountMultiFactorServiceResponse)result);
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

- (void)denySessionAsync:(NSString*)userAccountId
                    sessionId:(NSString*)sessionId
    sessionAuthenticationType:(WSAICMicrosoftAccountMultiFactorAuthenticationType)sessionAuthenticationType
                      success:(void (^)(WSAICMicrosoftAccountMultiFactorServiceResponse))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>>
        unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->DenySessionAsync(nsStrToHstr(userAccountId).Get(),
                                   nsStrToHstr(sessionId).Get(),
                                   (ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType)
                                       sessionAuthenticationType,
                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
            ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSAICMicrosoftAccountMultiFactorServiceResponse)result);
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

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSAICMicrosoftAccountMultiFactorSessionInfo_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<
        IVectorView<ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo*>,
        RTArrayObj<ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo*,
                   IVectorView<ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo*>,
                   WSAICMicrosoftAccountMultiFactorSessionInfo,
                   ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo*,
                   dummyObjCCreator,
                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
