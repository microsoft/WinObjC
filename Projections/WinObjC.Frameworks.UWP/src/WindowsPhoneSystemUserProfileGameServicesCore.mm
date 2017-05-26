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

// WindowsPhoneSystemUserProfileGameServicesCore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Phone.System.UserProfile.GameServices.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPhoneSystemUserProfileGameServicesCore.h"
#include "WindowsPhoneSystemUserProfileGameServicesCore_priv.h"

@implementation WPSUGCGameServicePropertyCollection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::System::UserProfile::GameServices::Core::IGameServicePropertyCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getPropertyAsync:(NSString*)propertyName success:(void (^)(RTObject*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::System::UserProfile::GameServices::Core::IGameServicePropertyCollection>(self);
    THROW_NS_IF_FAILED(_comInst->GetPropertyAsync(nsStrToHstr(propertyName).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IInspectable*>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IInspectable*>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        ComPtr<IInspectable> result;
                        HRESULT hr = op->GetResults(result.GetAddressOf());
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(_createBareRTObj(result.Get()));
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

@implementation WPSUGCGameService

ComPtr<ABI::Windows::Phone::System::UserProfile::GameServices::Core::IGameService> WPSUGCIGameService_inst() {
    ComPtr<ABI::Windows::Phone::System::UserProfile::GameServices::Core::IGameService> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Phone.System.UserProfile.GameServices.Core.GameService").Get(), &inst));
    return inst;
}

+ (WFUri*)serviceUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = WPSUGCIGameService_inst();
    THROW_NS_IF_FAILED(_comInst->get_ServiceUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

+ (void)getGamerProfileAsyncWithSuccess:(void (^)(WPSUGCGameServicePropertyCollection*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection*>>
        unmarshalledReturn;
    auto _comInst = WPSUGCIGameService_inst();
    THROW_NS_IF_FAILED(_comInst->GetGamerProfileAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   ABI::Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Phone::System::UserProfile::GameServices::Core::IGameServicePropertyCollection> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WPSUGCGameServicePropertyCollection>(result.Get()));
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

+ (void)getInstalledGameItemsAsyncWithSuccess:(void (^)(WPSUGCGameServicePropertyCollection*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection*>>
        unmarshalledReturn;
    auto _comInst = WPSUGCIGameService_inst();
    THROW_NS_IF_FAILED(_comInst->GetInstalledGameItemsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   ABI::Windows::Phone::System::UserProfile::GameServices::Core::GameServicePropertyCollection*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Phone::System::UserProfile::GameServices::Core::IGameServicePropertyCollection> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WPSUGCGameServicePropertyCollection>(result.Get()));
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

+ (void)getPartnerTokenAsync:(WFUri*)audienceUri success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WPSUGCIGameService_inst();
    THROW_NS_IF_FAILED(_comInst->GetPartnerTokenAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(audienceUri).Get(),
                                                      &unmarshalledReturn));

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

+ (void)getPrivilegesAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WPSUGCIGameService_inst();
    THROW_NS_IF_FAILED(_comInst->GetPrivilegesAsync(&unmarshalledReturn));

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

+ (void)grantAchievement:(unsigned int)achievementId {
    auto _comInst = WPSUGCIGameService_inst();
    THROW_NS_IF_FAILED(_comInst->GrantAchievement(achievementId));
}

+ (void)grantAvatarAward:(unsigned int)avatarAwardId {
    auto _comInst = WPSUGCIGameService_inst();
    THROW_NS_IF_FAILED(_comInst->GrantAvatarAward(avatarAwardId));
}

+ (void)postResult:(unsigned int)gameVariant
         scoreKind:(WPSUGCGameServiceScoreKind)scoreKind
        scoreValue:(int64_t)scoreValue
       gameOutcome:(WPSUGCGameServiceGameOutcome)gameOutcome
            buffer:(RTObject<WSSIBuffer>*)buffer {
    auto _comInst = WPSUGCIGameService_inst();
    THROW_NS_IF_FAILED(
        _comInst->PostResult(gameVariant,
                             (ABI::Windows::Phone::System::UserProfile::GameServices::Core::GameServiceScoreKind)scoreKind,
                             scoreValue,
                             (ABI::Windows::Phone::System::UserProfile::GameServices::Core::GameServiceGameOutcome)gameOutcome,
                             _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get()));
}

ComPtr<ABI::Windows::Phone::System::UserProfile::GameServices::Core::IGameService2> WPSUGCIGameService2_inst() {
    ComPtr<ABI::Windows::Phone::System::UserProfile::GameServices::Core::IGameService2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Phone.System.UserProfile.GameServices.Core.GameService").Get(), &inst));
    return inst;
}

+ (void)notifyPartnerTokenExpired:(WFUri*)audienceUri {
    auto _comInst = WPSUGCIGameService2_inst();
    THROW_NS_IF_FAILED(_comInst->NotifyPartnerTokenExpired(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(audienceUri).Get()));
}

+ (unsigned int)getAuthenticationStatus {
    unsigned int unmarshalledReturn;
    auto _comInst = WPSUGCIGameService2_inst();
    THROW_NS_IF_FAILED(_comInst->GetAuthenticationStatus(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end
