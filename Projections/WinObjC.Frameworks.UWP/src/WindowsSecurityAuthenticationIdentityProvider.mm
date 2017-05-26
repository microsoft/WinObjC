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

// WindowsSecurityAuthenticationIdentityProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Security.Authentication.Identity.Provider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSecurityAuthenticationIdentityProvider.h"
#include "WindowsSecurityAuthenticationIdentityProvider_priv.h"

@implementation WSAIPSecondaryAuthenticationFactorRegistration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics>
WSAIPISecondaryAuthenticationFactorRegistrationStatics_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorRegistration").Get(),
        &inst));
    return inst;
}

+ (void)requestStartRegisteringDeviceAsync:(NSString*)deviceId
                              capabilities:(WSAIPSecondaryAuthenticationFactorDeviceCapabilities)capabilities
                        deviceFriendlyName:(NSString*)deviceFriendlyName
                         deviceModelNumber:(NSString*)deviceModelNumber
                                 deviceKey:(RTObject<WSSIBuffer>*)deviceKey
                   mutualAuthenticationKey:(RTObject<WSSIBuffer>*)mutualAuthenticationKey
                                   success:(void (^)(WSAIPSecondaryAuthenticationFactorRegistrationResult*))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult*>>
        unmarshalledReturn;
    auto _comInst = WSAIPISecondaryAuthenticationFactorRegistrationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestStartRegisteringDeviceAsync(
        nsStrToHstr(deviceId).Get(),
        (ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceCapabilities)capabilities,
        nsStrToHstr(deviceFriendlyName).Get(),
        nsStrToHstr(deviceModelNumber).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(deviceKey).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(mutualAuthenticationKey).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
            ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult*>,
        FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<
            ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSAIPSecondaryAuthenticationFactorRegistrationResult>(result.Get()));
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

+ (void)findAllRegisteredDeviceInfoAsync:(WSAIPSecondaryAuthenticationFactorDeviceFindScope)queryType
                                 success:(void (^)(NSArray* /* WSAIPSecondaryAuthenticationFactorInfo* */))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        IVectorView<ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo*>*>>
        unmarshalledReturn;
    auto _comInst = WSAIPISecondaryAuthenticationFactorRegistrationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllRegisteredDeviceInfoAsync(
        (ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceFindScope)queryType,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                         ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo*>*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<
            IVectorView<ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo*>*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_WSAIPSecondaryAuthenticationFactorInfo_create(result.Get()));
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

+ (RTObject<WFIAsyncAction>*)unregisterDeviceAsync:(NSString*)deviceId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSAIPISecondaryAuthenticationFactorRegistrationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->UnregisterDeviceAsync(nsStrToHstr(deviceId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)updateDeviceConfigurationDataAsync:(NSString*)deviceId
                                        deviceConfigurationData:(RTObject<WSSIBuffer>*)deviceConfigurationData {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSAIPISecondaryAuthenticationFactorRegistrationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->UpdateDeviceConfigurationDataAsync(
        nsStrToHstr(deviceId).Get(),
        _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(deviceConfigurationData).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)finishRegisteringDeviceAsync:(RTObject<WSSIBuffer>*)deviceConfigurationData {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration>(self);
    THROW_NS_IF_FAILED(
        _comInst->FinishRegisteringDeviceAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(deviceConfigurationData).Get(),
                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)abortRegisteringDeviceAsync:(NSString*)errorLogMessage {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration>(self);
    THROW_NS_IF_FAILED(_comInst->AbortRegisteringDeviceAsync(nsStrToHstr(errorLogMessage).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSAIPSecondaryAuthenticationFactorRegistrationResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSAIPSecondaryAuthenticationFactorRegistrationStatus)status {
    ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationStatus unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSAIPSecondaryAuthenticationFactorRegistrationStatus)unmarshalledReturn;
}

- (WSAIPSecondaryAuthenticationFactorRegistration*)registration {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_Registration(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAIPSecondaryAuthenticationFactorRegistration>(unmarshalledReturn.Get());
}

@end

@implementation WSAIPSecondaryAuthenticationFactorAuthentication

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics>
WSAIPISecondaryAuthenticationFactorAuthenticationStatics_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthentication").Get(),
        &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)showNotificationMessageAsync:(NSString*)deviceName
                                                  message:(WSAIPSecondaryAuthenticationFactorAuthenticationMessage)message {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSAIPISecondaryAuthenticationFactorAuthenticationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowNotificationMessageAsync(
        nsStrToHstr(deviceName).Get(),
        (ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationMessage)message,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)startAuthenticationAsync:(NSString*)deviceId
      serviceAuthenticationNonce:(RTObject<WSSIBuffer>*)serviceAuthenticationNonce
                         success:(void (^)(WSAIPSecondaryAuthenticationFactorAuthenticationResult*))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult*>>
        unmarshalledReturn;
    auto _comInst = WSAIPISecondaryAuthenticationFactorAuthenticationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->StartAuthenticationAsync(nsStrToHstr(deviceId).Get(),
                                           _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(serviceAuthenticationNonce).Get(),
                                           &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
            ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<
                        ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult>
                        result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSAIPSecondaryAuthenticationFactorAuthenticationResult>(result.Get()));
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

+ (EventRegistrationToken)addAuthenticationStageChangedEvent:
    (void (^)(RTObject*, WSAIPSecondaryAuthenticationFactorAuthenticationStageChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSAIPISecondaryAuthenticationFactorAuthenticationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_AuthenticationStageChanged(
        Make<
            EventHandler_Windows_Security_Authentication_Identity_Provider_SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeAuthenticationStageChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WSAIPISecondaryAuthenticationFactorAuthenticationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_AuthenticationStageChanged(token));
}

+ (void)getAuthenticationStageInfoAsyncWithSuccess:(void (^)(WSAIPSecondaryAuthenticationFactorAuthenticationStageInfo*))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo*>>
        unmarshalledReturn;
    auto _comInst = WSAIPISecondaryAuthenticationFactorAuthenticationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetAuthenticationStageInfoAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
            ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo*>,
        FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<
            ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo>
                    result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSAIPSecondaryAuthenticationFactorAuthenticationStageInfo>(result.Get()));
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

- (RTObject<WSSIBuffer>*)serviceAuthenticationHmac {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceAuthenticationHmac(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)sessionNonce {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication>(self);
    THROW_NS_IF_FAILED(_comInst->get_SessionNonce(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)deviceNonce {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceNonce(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)deviceConfigurationData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceConfigurationData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)finishAuthenticationAsync:(RTObject<WSSIBuffer>*)deviceHmac
                      sessionHmac:(RTObject<WSSIBuffer>*)sessionHmac
                          success:(void (^)(WSAIPSecondaryAuthenticationFactorFinishAuthenticationStatus))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorFinishAuthenticationStatus>>
        unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication>(self);
    THROW_NS_IF_FAILED(_comInst->FinishAuthenticationAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(deviceHmac).Get(),
                                                           _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(sessionHmac).Get(),
                                                           &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
            ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorFinishAuthenticationStatus>,
        FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<
            ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorFinishAuthenticationStatus>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorFinishAuthenticationStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WSAIPSecondaryAuthenticationFactorFinishAuthenticationStatus)result);
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

- (RTObject<WFIAsyncAction>*)abortAuthenticationAsync:(NSString*)errorLogMessage {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication>(self);
    THROW_NS_IF_FAILED(_comInst->AbortAuthenticationAsync(nsStrToHstr(errorLogMessage).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSAIPSecondaryAuthenticationFactorAuthenticationResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSAIPSecondaryAuthenticationFactorAuthenticationStatus)status {
    ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStatus unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSAIPSecondaryAuthenticationFactorAuthenticationStatus)unmarshalledReturn;
}

- (WSAIPSecondaryAuthenticationFactorAuthentication*)authentication {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_Authentication(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAIPSecondaryAuthenticationFactorAuthentication>(unmarshalledReturn.Get());
}

@end

@implementation WSAIPSecondaryAuthenticationFactorInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)deviceFriendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceFriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)deviceModelNumber {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceModelNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WSSIBuffer>*)deviceConfigurationData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceConfigurationData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WSAIPSecondaryAuthenticationFactorAuthenticationStageChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs>
        defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSAIPSecondaryAuthenticationFactorAuthenticationStageInfo*)stageInfo {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs>(
        self);
    THROW_NS_IF_FAILED(_comInst->get_StageInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAIPSecondaryAuthenticationFactorAuthenticationStageInfo>(unmarshalledReturn.Get());
}

@end

@implementation WSAIPSecondaryAuthenticationFactorAuthenticationStageInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo>
        defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSAIPSecondaryAuthenticationFactorAuthenticationStage)stage {
    ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStage unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Stage(&unmarshalledReturn));
    return (WSAIPSecondaryAuthenticationFactorAuthenticationStage)unmarshalledReturn;
}

- (WSAIPSecondaryAuthenticationFactorAuthenticationScenario)scenario {
    ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationScenario unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Scenario(&unmarshalledReturn));
    return (WSAIPSecondaryAuthenticationFactorAuthenticationScenario)unmarshalledReturn;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<
        ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

id RTProxiedNSArray_WSAIPSecondaryAuthenticationFactorInfo_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<
        IVectorView<ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo*>,
        RTArrayObj<ABI::Windows::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo*,
                   IVectorView<ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo*>,
                   WSAIPSecondaryAuthenticationFactorInfo,
                   ABI::Windows::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo*,
                   dummyObjCCreator,
                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
