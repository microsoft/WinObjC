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

// WindowsPhoneStartScreen.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Phone.StartScreen.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPhoneStartScreen.h"
#include "WindowsPhoneStartScreen_priv.h"

@implementation WPSIToastNotificationManagerStatics3

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::StartScreen::IToastNotificationManagerStatics3> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUNToastNotifier*)createToastNotifierForSecondaryTile:(NSString*)tileId {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotifier> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::StartScreen::IToastNotificationManagerStatics3>(self);
    THROW_NS_IF_FAILED(_comInst->CreateToastNotifierForSecondaryTile(nsStrToHstr(tileId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNToastNotifier>(unmarshalledReturn.Get());
}

@end

@implementation WPSDualSimTile

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::StartScreen::IDualSimTile> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Phone.StartScreen.DualSimTile").Get(), &out));
    return [_createRtProxy<WPSDualSimTile>(out.Get()) retain];
}

ComPtr<ABI::Windows::Phone::StartScreen::IDualSimTileStatics> WPSIDualSimTileStatics_inst() {
    ComPtr<ABI::Windows::Phone::StartScreen::IDualSimTileStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Phone.StartScreen.DualSimTile").Get(), &inst));
    return inst;
}

+ (WPSDualSimTile*)getTileForSim2 {
    ComPtr<ABI::Windows::Phone::StartScreen::IDualSimTile> unmarshalledReturn;
    auto _comInst = WPSIDualSimTileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetTileForSim2(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSDualSimTile>(unmarshalledReturn.Get());
}

+ (void)updateDisplayNameForSim1Async:(NSString*)name success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WPSIDualSimTileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->UpdateDisplayNameForSim1Async(nsStrToHstr(name).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

+ (WUNTileUpdater*)createTileUpdaterForSim1 {
    ComPtr<ABI::Windows::UI::Notifications::ITileUpdater> unmarshalledReturn;
    auto _comInst = WPSIDualSimTileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateTileUpdaterForSim1(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileUpdater>(unmarshalledReturn.Get());
}

+ (WUNTileUpdater*)createTileUpdaterForSim2 {
    ComPtr<ABI::Windows::UI::Notifications::ITileUpdater> unmarshalledReturn;
    auto _comInst = WPSIDualSimTileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateTileUpdaterForSim2(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNTileUpdater>(unmarshalledReturn.Get());
}

+ (WUNBadgeUpdater*)createBadgeUpdaterForSim1 {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdater> unmarshalledReturn;
    auto _comInst = WPSIDualSimTileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateBadgeUpdaterForSim1(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNBadgeUpdater>(unmarshalledReturn.Get());
}

+ (WUNBadgeUpdater*)createBadgeUpdaterForSim2 {
    ComPtr<ABI::Windows::UI::Notifications::IBadgeUpdater> unmarshalledReturn;
    auto _comInst = WPSIDualSimTileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateBadgeUpdaterForSim2(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNBadgeUpdater>(unmarshalledReturn.Get());
}

+ (WUNToastNotifier*)createToastNotifierForSim1 {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotifier> unmarshalledReturn;
    auto _comInst = WPSIDualSimTileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateToastNotifierForSim1(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNToastNotifier>(unmarshalledReturn.Get());
}

+ (WUNToastNotifier*)createToastNotifierForSim2 {
    ComPtr<ABI::Windows::UI::Notifications::IToastNotifier> unmarshalledReturn;
    auto _comInst = WPSIDualSimTileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateToastNotifierForSim2(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUNToastNotifier>(unmarshalledReturn.Get());
}

- (void)setDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::StartScreen::IDualSimTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayName(nsStrToHstr(value).Get()));
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::StartScreen::IDualSimTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isPinnedToStart {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::StartScreen::IDualSimTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPinnedToStart(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)createAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::StartScreen::IDualSimTile>(self);
    THROW_NS_IF_FAILED(_comInst->CreateAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

- (void)updateAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::StartScreen::IDualSimTile>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

- (void)deleteAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::StartScreen::IDualSimTile>(self);
    THROW_NS_IF_FAILED(_comInst->DeleteAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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
