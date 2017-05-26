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

// WindowsNetworkingPushNotifications.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Networking.PushNotifications.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsNetworkingPushNotifications.h"
#include "WindowsNetworkingPushNotifications_priv.h"

@implementation WNPPushNotificationChannel

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::PushNotifications::IPushNotificationChannel> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)uri {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IPushNotificationChannel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFDateTime*)expirationTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IPushNotificationChannel>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IPushNotificationChannel>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (EventRegistrationToken)addPushNotificationReceivedEvent:(void (^)(WNPPushNotificationChannel*,
                                                                     WNPPushNotificationReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IPushNotificationChannel>(self);
    THROW_NS_IF_FAILED(_comInst->add_PushNotificationReceived(
        Make<
            ITypedEventHandler_Windows_Networking_PushNotifications_PushNotificationChannel_Windows_Networking_PushNotifications_PushNotificationReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePushNotificationReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IPushNotificationChannel>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PushNotificationReceived(token));
}

@end

@implementation WNPPushNotificationChannelManagerForUser

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::PushNotifications::IPushNotificationChannelManagerForUser> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)createPushNotificationChannelForApplicationAsyncWithSuccess:(void (^)(WNPPushNotificationChannel*))success
                                                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IPushNotificationChannelManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->CreatePushNotificationChannelForApplicationAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Networking::PushNotifications::IPushNotificationChannel> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WNPPushNotificationChannel>(result.Get()));
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

- (void)createPushNotificationChannelForApplicationAsyncWithId:(NSString*)applicationId
                                                       success:(void (^)(WNPPushNotificationChannel*))success
                                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IPushNotificationChannelManagerForUser>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreatePushNotificationChannelForApplicationAsyncWithId(nsStrToHstr(applicationId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Networking::PushNotifications::IPushNotificationChannel> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WNPPushNotificationChannel>(result.Get()));
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

- (void)createPushNotificationChannelForSecondaryTileAsync:(NSString*)tileId
                                                   success:(void (^)(WNPPushNotificationChannel*))success
                                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IPushNotificationChannelManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->CreatePushNotificationChannelForSecondaryTileAsync(nsStrToHstr(tileId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Networking::PushNotifications::IPushNotificationChannel> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WNPPushNotificationChannel>(result.Get()));
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

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IPushNotificationChannelManagerForUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WNPPushNotificationReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::PushNotifications::IPushNotificationReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setCancel:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IPushNotificationReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Cancel((boolean)value));
}

- (BOOL)cancel {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IPushNotificationReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cancel(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WNPPushNotificationType)notificationType {
    ABI::Windows::Networking::PushNotifications::PushNotificationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IPushNotificationReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NotificationType(&unmarshalledReturn));
    return (WNPPushNotificationType)unmarshalledReturn;
}

- (WUNToastNotification*)toastNotification {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotification> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IPushNotificationReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToastNotification(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNToastNotification>(unmarshalledReturn.Get());
}

- (WUNTileNotification*)tileNotification {
    ComPtr<ABI::Windows::UI::Notifications::ITileNotification> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IPushNotificationReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TileNotification(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileNotification>(unmarshalledReturn.Get());
}

- (WUNBadgeNotification*)badgeNotification {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeNotification> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IPushNotificationReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_BadgeNotification(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNBadgeNotification>(unmarshalledReturn.Get());
}

- (WNPRawNotification*)rawNotification {
    ComPtr<ABI::Windows::Networking::PushNotifications::IRawNotification> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IPushNotificationReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawNotification(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNPRawNotification>(unmarshalledReturn.Get());
}

@end

@implementation WNPRawNotification

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::PushNotifications::IRawNotification> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)content {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::PushNotifications::IRawNotification>(self);
    THROW_NS_IF_FAILED(_comInst->get_Content(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNPPushNotificationChannelManager

ComPtr<ABI::Windows::Networking::PushNotifications::IPushNotificationChannelManagerStatics2>
WNPIPushNotificationChannelManagerStatics2_inst() {
    ComPtr<ABI::Windows::Networking::PushNotifications::IPushNotificationChannelManagerStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.PushNotifications.PushNotificationChannelManager").Get(), &inst));
    return inst;
}

+ (WNPPushNotificationChannelManagerForUser*)getForUser:(WSUser*)user {
    ComPtr<ABI::Windows::Networking::PushNotifications::IPushNotificationChannelManagerForUser> unmarshalledReturn;
    auto _comInst = WNPIPushNotificationChannelManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetForUser(_getRtInterface<ABI::Windows::System::IUser>(user).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNPPushNotificationChannelManagerForUser>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Networking::PushNotifications::IPushNotificationChannelManagerStatics>
WNPIPushNotificationChannelManagerStatics_inst() {
    ComPtr<ABI::Windows::Networking::PushNotifications::IPushNotificationChannelManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Networking.PushNotifications.PushNotificationChannelManager").Get(), &inst));
    return inst;
}

+ (void)createPushNotificationChannelForApplicationAsyncWithSuccess:(void (^)(WNPPushNotificationChannel*))success
                                                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>>
        unmarshalledReturn;
    auto _comInst = WNPIPushNotificationChannelManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreatePushNotificationChannelForApplicationAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Networking::PushNotifications::IPushNotificationChannel> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WNPPushNotificationChannel>(result.Get()));
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

+ (void)createPushNotificationChannelForApplicationAsyncWithId:(NSString*)applicationId
                                                       success:(void (^)(WNPPushNotificationChannel*))success
                                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>>
        unmarshalledReturn;
    auto _comInst = WNPIPushNotificationChannelManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreatePushNotificationChannelForApplicationAsyncWithId(nsStrToHstr(applicationId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Networking::PushNotifications::IPushNotificationChannel> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WNPPushNotificationChannel>(result.Get()));
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

+ (void)createPushNotificationChannelForSecondaryTileAsync:(NSString*)tileId
                                                   success:(void (^)(WNPPushNotificationChannel*))success
                                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>>
        unmarshalledReturn;
    auto _comInst = WNPIPushNotificationChannelManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreatePushNotificationChannelForSecondaryTileAsync(nsStrToHstr(tileId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Networking::PushNotifications::PushNotificationChannel*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Networking::PushNotifications::IPushNotificationChannel> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WNPPushNotificationChannel>(result.Get()));
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
