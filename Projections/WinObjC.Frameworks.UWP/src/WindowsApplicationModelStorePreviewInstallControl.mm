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

// WindowsApplicationModelStorePreviewInstallControl.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Store.Preview.InstallControl.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelStorePreviewInstallControl.h"
#include "WindowsApplicationModelStorePreviewInstallControl_priv.h"

@implementation WASPIAppInstallStatus

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WASPIAppInstallState)installState {
    ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstallState(&unmarshalledReturn));
    return (WASPIAppInstallState)unmarshalledReturn;
}

- (uint64_t)downloadSizeInBytes {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_DownloadSizeInBytes(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)bytesDownloaded {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_BytesDownloaded(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)percentComplete {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_PercentComplete(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus2>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

- (BOOL)readyForLaunch {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadyForLaunch(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WASPIAppInstallItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)productId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProductId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)packageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_PackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WASPIAppInstallType)installType {
    ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstallType(&unmarshalledReturn));
    return (WASPIAppInstallType)unmarshalledReturn;
}

- (BOOL)isUserInitiated {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsUserInitiated(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WASPIAppInstallStatus*)getCurrentStatus {
    ComPtr<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallStatus> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentStatus(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASPIAppInstallStatus>(unmarshalledReturn.Get());
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

- (void)pause {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem>(self);
    THROW_NS_IF_FAILED(_comInst->Pause());
}

- (void)restart {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem>(self);
    THROW_NS_IF_FAILED(_comInst->Restart());
}

- (EventRegistrationToken)addCompletedEvent:(void (^)(WASPIAppInstallItem*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem>(self);
    THROW_NS_IF_FAILED(_comInst->add_Completed(
        Make<ITypedEventHandler_Windows_ApplicationModel_Store_Preview_InstallControl_AppInstallItem_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Completed(token));
}

- (EventRegistrationToken)addStatusChangedEvent:(void (^)(WASPIAppInstallItem*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem>(self);
    THROW_NS_IF_FAILED(_comInst->add_StatusChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_Store_Preview_InstallControl_AppInstallItem_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StatusChanged(token));
}

- (void)cancelWithTelemetry:(NSString*)correlationVector {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem2>(self);
    THROW_NS_IF_FAILED(_comInst->CancelWithTelemetry(nsStrToHstr(correlationVector).Get()));
}

- (void)pauseWithTelemetry:(NSString*)correlationVector {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem2>(self);
    THROW_NS_IF_FAILED(_comInst->PauseWithTelemetry(nsStrToHstr(correlationVector).Get()));
}

- (void)restartWithTelemetry:(NSString*)correlationVector {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem2>(self);
    THROW_NS_IF_FAILED(_comInst->RestartWithTelemetry(nsStrToHstr(correlationVector).Get()));
}

@end

@implementation WASPIAppInstallManagerItemEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManagerItemEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WASPIAppInstallItem*)item {
    ComPtr<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManagerItemEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Item(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASPIAppInstallItem>(unmarshalledReturn.Get());
}

@end

@implementation WASPIAppInstallManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.Store.Preview.InstallControl.AppInstallManager").Get(), &out));
    return [_createRtProxy<WASPIAppInstallManager>(out.Get()) retain];
}

- (NSArray* /* WASPIAppInstallItem* */)appInstallItems {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppInstallItems(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WASPIAppInstallItem_create(unmarshalledReturn.Get());
}

- (void)cancel:(NSString*)productId {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel(nsStrToHstr(productId).Get()));
}

- (void)pause:(NSString*)productId {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->Pause(nsStrToHstr(productId).Get()));
}

- (void)restart:(NSString*)productId {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->Restart(nsStrToHstr(productId).Get()));
}

- (EventRegistrationToken)addItemCompletedEvent:(void (^)(WASPIAppInstallManager*, WASPIAppInstallManagerItemEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_ItemCompleted(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Store_Preview_InstallControl_AppInstallManager_Windows_ApplicationModel_Store_Preview_InstallControl_AppInstallManagerItemEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeItemCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ItemCompleted(token));
}

- (EventRegistrationToken)addItemStatusChangedEvent:(void (^)(WASPIAppInstallManager*, WASPIAppInstallManagerItemEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_ItemStatusChanged(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Store_Preview_InstallControl_AppInstallManager_Windows_ApplicationModel_Store_Preview_InstallControl_AppInstallManagerItemEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeItemStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ItemStatusChanged(token));
}

- (WASPIAutoUpdateSetting)autoUpdateSetting {
    ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AutoUpdateSetting unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoUpdateSetting(&unmarshalledReturn));
    return (WASPIAutoUpdateSetting)unmarshalledReturn;
}

- (void)setAutoUpdateSetting:(WASPIAutoUpdateSetting)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_AutoUpdateSetting((ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AutoUpdateSetting)value));
}

- (NSString*)acquisitionIdentity {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_AcquisitionIdentity(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAcquisitionIdentity:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->put_AcquisitionIdentity(nsStrToHstr(value).Get()));
}

- (void)getIsApplicableAsync:(NSString*)productId
                       skuId:(NSString*)skuId
                     success:(void (^)(BOOL))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->GetIsApplicableAsync(nsStrToHstr(productId).Get(), nsStrToHstr(skuId).Get(), &unmarshalledReturn));

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

- (void)startAppInstallAsync:(NSString*)productId
                            skuId:(NSString*)skuId
                           repair:(BOOL)repair
    forceUseOfNonRemovableStorage:(BOOL)forceUseOfNonRemovableStorage
                          success:(void (^)(WASPIAppInstallItem*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->StartAppInstallAsync(nsStrToHstr(productId).Get(),
                                                      nsStrToHstr(skuId).Get(),
                                                      (boolean)repair,
                                                      (boolean)forceUseOfNonRemovableStorage,
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WASPIAppInstallItem>(result.Get()));
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

- (void)updateAppByPackageFamilyNameAsync:(NSString*)packageFamilyName
                                  success:(void (^)(WASPIAppInstallItem*))success
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateAppByPackageFamilyNameAsync(nsStrToHstr(packageFamilyName).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WASPIAppInstallItem>(result.Get()));
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

- (void)searchForUpdatesAsync:(NSString*)productId
                        skuId:(NSString*)skuId
                      success:(void (^)(WASPIAppInstallItem*))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->SearchForUpdatesAsync(nsStrToHstr(productId).Get(), nsStrToHstr(skuId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WASPIAppInstallItem>(result.Get()));
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

- (void)searchForAllUpdatesAsyncWithSuccess:(void (^)(NSArray* /* WASPIAppInstallItem* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->SearchForAllUpdatesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WASPIAppInstallItem_create(result.Get()));
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

- (void)isStoreBlockedByPolicyAsync:(NSString*)storeClientName
               storeClientPublisher:(NSString*)storeClientPublisher
                            success:(void (^)(BOOL))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->IsStoreBlockedByPolicyAsync(nsStrToHstr(storeClientName).Get(),
                                                             nsStrToHstr(storeClientPublisher).Get(),
                                                             &unmarshalledReturn));

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

- (void)getIsAppAllowedToInstallAsync:(NSString*)productId success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager>(self);
    THROW_NS_IF_FAILED(_comInst->GetIsAppAllowedToInstallAsync(nsStrToHstr(productId).Get(), &unmarshalledReturn));

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

- (void)startAppInstallWithTelemetryAsync:(NSString*)productId
                                    skuId:(NSString*)skuId
                                   repair:(BOOL)repair
            forceUseOfNonRemovableStorage:(BOOL)forceUseOfNonRemovableStorage
                                catalogId:(NSString*)catalogId
                                 bundleId:(NSString*)bundleId
                        correlationVector:(NSString*)correlationVector
                                  success:(void (^)(WASPIAppInstallItem*))success
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>(self);
    THROW_NS_IF_FAILED(_comInst->StartAppInstallWithTelemetryAsync(nsStrToHstr(productId).Get(),
                                                                   nsStrToHstr(skuId).Get(),
                                                                   (boolean)repair,
                                                                   (boolean)forceUseOfNonRemovableStorage,
                                                                   nsStrToHstr(catalogId).Get(),
                                                                   nsStrToHstr(bundleId).Get(),
                                                                   nsStrToHstr(correlationVector).Get(),
                                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WASPIAppInstallItem>(result.Get()));
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

- (void)updateAppByPackageFamilyNameWithTelemetryAsync:(NSString*)packageFamilyName
                                     correlationVector:(NSString*)correlationVector
                                               success:(void (^)(WASPIAppInstallItem*))success
                                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateAppByPackageFamilyNameWithTelemetryAsync(nsStrToHstr(packageFamilyName).Get(),
                                                                                nsStrToHstr(correlationVector).Get(),
                                                                                &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WASPIAppInstallItem>(result.Get()));
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

- (void)searchForUpdatesWithTelemetryAsync:(NSString*)productId
                                     skuId:(NSString*)skuId
                                 catalogId:(NSString*)catalogId
                         correlationVector:(NSString*)correlationVector
                                   success:(void (^)(WASPIAppInstallItem*))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>(self);
    THROW_NS_IF_FAILED(_comInst->SearchForUpdatesWithTelemetryAsync(nsStrToHstr(productId).Get(),
                                                                    nsStrToHstr(skuId).Get(),
                                                                    nsStrToHstr(catalogId).Get(),
                                                                    nsStrToHstr(correlationVector).Get(),
                                                                    &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WASPIAppInstallItem>(result.Get()));
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

- (void)searchForAllUpdatesWithTelemetryAsync:(NSString*)correlationVector
                                      success:(void (^)(NSArray* /* WASPIAppInstallItem* */))success
                                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>(self);
    THROW_NS_IF_FAILED(_comInst->SearchForAllUpdatesWithTelemetryAsync(nsStrToHstr(correlationVector).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WASPIAppInstallItem_create(result.Get()));
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

- (void)getIsAppAllowedToInstallWithTelemetryAsync:(NSString*)productId
                                             skuId:(NSString*)skuId
                                         catalogId:(NSString*)catalogId
                                 correlationVector:(NSString*)correlationVector
                                           success:(void (^)(BOOL))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>(self);
    THROW_NS_IF_FAILED(_comInst->GetIsAppAllowedToInstallWithTelemetryAsync(nsStrToHstr(productId).Get(),
                                                                            nsStrToHstr(skuId).Get(),
                                                                            nsStrToHstr(catalogId).Get(),
                                                                            nsStrToHstr(correlationVector).Get(),
                                                                            &unmarshalledReturn));

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

- (void)cancelWithTelemetry:(NSString*)productId correlationVector:(NSString*)correlationVector {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>(self);
    THROW_NS_IF_FAILED(_comInst->CancelWithTelemetry(nsStrToHstr(productId).Get(), nsStrToHstr(correlationVector).Get()));
}

- (void)pauseWithTelemetry:(NSString*)productId correlationVector:(NSString*)correlationVector {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>(self);
    THROW_NS_IF_FAILED(_comInst->PauseWithTelemetry(nsStrToHstr(productId).Get(), nsStrToHstr(correlationVector).Get()));
}

- (void)restartWithTelemetry:(NSString*)productId correlationVector:(NSString*)correlationVector {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager2>(self);
    THROW_NS_IF_FAILED(_comInst->RestartWithTelemetry(nsStrToHstr(productId).Get(), nsStrToHstr(correlationVector).Get()));
}

- (void)startProductInstallAsync:(NSString*)productId
                        catalogId:(NSString*)catalogId
                         flightId:(NSString*)flightId
                         clientId:(NSString*)clientId
                           repair:(BOOL)repair
    forceUseOfNonRemovableStorage:(BOOL)forceUseOfNonRemovableStorage
                correlationVector:(NSString*)correlationVector
                     targetVolume:(WMDPackageVolume*)targetVolume
                          success:(void (^)(NSArray* /* WASPIAppInstallItem* */))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager3>(self);
    THROW_NS_IF_FAILED(
        _comInst->StartProductInstallAsync(nsStrToHstr(productId).Get(),
                                           nsStrToHstr(catalogId).Get(),
                                           nsStrToHstr(flightId).Get(),
                                           nsStrToHstr(clientId).Get(),
                                           (boolean)repair,
                                           (boolean)forceUseOfNonRemovableStorage,
                                           nsStrToHstr(correlationVector).Get(),
                                           _getRtInterface<ABI::Windows::Management::Deployment::IPackageVolume>(targetVolume).Get(),
                                           &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WASPIAppInstallItem_create(result.Get()));
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

- (void)startProductInstallForUserAsync:(WSUser*)user
                              productId:(NSString*)productId
                              catalogId:(NSString*)catalogId
                               flightId:(NSString*)flightId
                               clientId:(NSString*)clientId
                                 repair:(BOOL)repair
          forceUseOfNonRemovableStorage:(BOOL)forceUseOfNonRemovableStorage
                      correlationVector:(NSString*)correlationVector
                           targetVolume:(WMDPackageVolume*)targetVolume
                                success:(void (^)(NSArray* /* WASPIAppInstallItem* */))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager3>(self);
    THROW_NS_IF_FAILED(
        _comInst->StartProductInstallForUserAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                  nsStrToHstr(productId).Get(),
                                                  nsStrToHstr(catalogId).Get(),
                                                  nsStrToHstr(flightId).Get(),
                                                  nsStrToHstr(clientId).Get(),
                                                  (boolean)repair,
                                                  (boolean)forceUseOfNonRemovableStorage,
                                                  nsStrToHstr(correlationVector).Get(),
                                                  _getRtInterface<ABI::Windows::Management::Deployment::IPackageVolume>(targetVolume).Get(),
                                                  &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WASPIAppInstallItem_create(result.Get()));
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

- (void)updateAppByPackageFamilyNameForUserAsync:(WSUser*)user
                               packageFamilyName:(NSString*)packageFamilyName
                               correlationVector:(NSString*)correlationVector
                                         success:(void (^)(WASPIAppInstallItem*))success
                                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager3>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateAppByPackageFamilyNameForUserAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                                          nsStrToHstr(packageFamilyName).Get(),
                                                                          nsStrToHstr(correlationVector).Get(),
                                                                          &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WASPIAppInstallItem>(result.Get()));
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

- (void)searchForUpdatesForUserAsync:(WSUser*)user
                           productId:(NSString*)productId
                               skuId:(NSString*)skuId
                           catalogId:(NSString*)catalogId
                   correlationVector:(NSString*)correlationVector
                             success:(void (^)(WASPIAppInstallItem*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager3>(self);
    THROW_NS_IF_FAILED(_comInst->SearchForUpdatesForUserAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                              nsStrToHstr(productId).Get(),
                                                              nsStrToHstr(skuId).Get(),
                                                              nsStrToHstr(catalogId).Get(),
                                                              nsStrToHstr(correlationVector).Get(),
                                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WASPIAppInstallItem>(result.Get()));
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

- (void)searchForAllUpdatesForUserAsync:(WSUser*)user
                      correlationVector:(NSString*)correlationVector
                                success:(void (^)(NSArray* /* WASPIAppInstallItem* */))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager3>(self);
    THROW_NS_IF_FAILED(_comInst->SearchForAllUpdatesForUserAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                                 nsStrToHstr(correlationVector).Get(),
                                                                 &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WASPIAppInstallItem_create(result.Get()));
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

- (void)getIsAppAllowedToInstallForUserAsync:(WSUser*)user
                                   productId:(NSString*)productId
                                       skuId:(NSString*)skuId
                                   catalogId:(NSString*)catalogId
                           correlationVector:(NSString*)correlationVector
                                     success:(void (^)(BOOL))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager3>(self);
    THROW_NS_IF_FAILED(_comInst->GetIsAppAllowedToInstallForUserAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                                      nsStrToHstr(productId).Get(),
                                                                      nsStrToHstr(skuId).Get(),
                                                                      nsStrToHstr(catalogId).Get(),
                                                                      nsStrToHstr(correlationVector).Get(),
                                                                      &unmarshalledReturn));

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

- (void)getIsApplicableForUserAsync:(WSUser*)user
                          productId:(NSString*)productId
                              skuId:(NSString*)skuId
                            success:(void (^)(BOOL))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager3>(self);
    THROW_NS_IF_FAILED(_comInst->GetIsApplicableForUserAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                             nsStrToHstr(productId).Get(),
                                                             nsStrToHstr(skuId).Get(),
                                                             &unmarshalledReturn));

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

- (void)moveToFrontOfDownloadQueue:(NSString*)productId correlationVector:(NSString*)correlationVector {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallManager3>(self);
    THROW_NS_IF_FAILED(_comInst->MoveToFrontOfDownloadQueue(nsStrToHstr(productId).Get(), nsStrToHstr(correlationVector).Get()));
}

@end

id RTProxiedNSArray_WASPIAppInstallItem_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>,
                        RTArrayObj<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::IAppInstallItem*,
                                   IVectorView<ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*>,
                                   WASPIAppInstallItem,
                                   ABI::Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
