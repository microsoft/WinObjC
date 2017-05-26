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

// WindowsApplicationModelAppExtensions.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.AppExtensions.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelAppExtensions.h"
#include "WindowsApplicationModelAppExtensions_priv.h"

@implementation WAAAppExtensionCatalog

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalogStatics> WAAIAppExtensionCatalogStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalogStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.AppExtensions.AppExtensionCatalog").Get(), &inst));
    return inst;
}

+ (WAAAppExtensionCatalog*)open:(NSString*)appExtensionName {
    ComPtr<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog> unmarshalledReturn;
    auto _comInst = WAAIAppExtensionCatalogStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Open(nsStrToHstr(appExtensionName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAAppExtensionCatalog>(unmarshalledReturn.Get());
}

- (void)findAllAsyncWithSuccess:(void (^)(NSArray* /* WAAAppExtension* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::AppExtensions::AppExtension*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->FindAllAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::ApplicationModel::AppExtensions::AppExtension*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::AppExtensions::AppExtension*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::AppExtensions::AppExtension*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAAAppExtension_create(result.Get()));
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

- (void)requestRemovePackageAsync:(NSString*)packageFullName success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->RequestRemovePackageAsync(nsStrToHstr(packageFullName).Get(), &unmarshalledReturn));

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

- (EventRegistrationToken)addPackageInstalledEvent:(void (^)(WAAAppExtensionCatalog*, WAAAppExtensionPackageInstalledEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->add_PackageInstalled(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageInstalledEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePackageInstalledEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PackageInstalled(token));
}

- (EventRegistrationToken)addPackageUpdatingEvent:(void (^)(WAAAppExtensionCatalog*, WAAAppExtensionPackageUpdatingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->add_PackageUpdating(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUpdatingEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePackageUpdatingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PackageUpdating(token));
}

- (EventRegistrationToken)addPackageUpdatedEvent:(void (^)(WAAAppExtensionCatalog*, WAAAppExtensionPackageUpdatedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->add_PackageUpdated(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUpdatedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePackageUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PackageUpdated(token));
}

- (EventRegistrationToken)addPackageUninstallingEvent:(void (^)(WAAAppExtensionCatalog*,
                                                                WAAAppExtensionPackageUninstallingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->add_PackageUninstalling(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageUninstallingEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePackageUninstallingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PackageUninstalling(token));
}

- (EventRegistrationToken)addPackageStatusChangedEvent:(void (^)(WAAAppExtensionCatalog*,
                                                                 WAAAppExtensionPackageStatusChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->add_PackageStatusChanged(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_AppExtensions_AppExtensionCatalog_Windows_ApplicationModel_AppExtensions_AppExtensionPackageStatusChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePackageStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PackageStatusChanged(token));
}

@end

@implementation WAAAppExtension

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::AppExtensions::IAppExtension> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtension>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtension>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtension>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAPackage*)package {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtension>(self);
    THROW_NS_IF_FAILED(_comInst->get_Package(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

- (WAAppInfo*)appInfo {
    ComPtr<ABI::Windows::ApplicationModel::IAppInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtension>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAppInfo>(unmarshalledReturn.Get());
}

- (void)getExtensionPropertiesAsyncWithSuccess:(void (^)(RTObject<WFCIPropertySet>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Foundation::Collections::IPropertySet*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtension>(self);
    THROW_NS_IF_FAILED(_comInst->GetExtensionPropertiesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Foundation::Collections::IPropertySet*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Foundation::Collections::IPropertySet*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WFCIPropertySet>(result.Get()));
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

- (void)getPublicFolderAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtension>(self);
    THROW_NS_IF_FAILED(_comInst->GetPublicFolderAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFolder*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFolder*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFolder> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFolder>(result.Get()));
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

@implementation WAAAppExtensionPackageInstalledEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)appExtensionName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppExtensionName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAPackage*)package {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Package(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

- (NSArray* /* WAAAppExtension* */)extensions {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::AppExtensions::AppExtension*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Extensions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WAAAppExtension_create(unmarshalledReturn.Get());
}

@end

@implementation WAAAppExtensionPackageUpdatingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)appExtensionName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppExtensionName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAPackage*)package {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Package(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

@end

@implementation WAAAppExtensionPackageUpdatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)appExtensionName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppExtensionName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAPackage*)package {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Package(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

- (NSArray* /* WAAAppExtension* */)extensions {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::AppExtensions::AppExtension*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Extensions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WAAAppExtension_create(unmarshalledReturn.Get());
}

@end

@implementation WAAAppExtensionPackageUninstallingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)appExtensionName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppExtensionName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAPackage*)package {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Package(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

@end

@implementation WAAAppExtensionPackageStatusChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)appExtensionName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppExtensionName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAPackage*)package {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Package(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_WAAAppExtension_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::AppExtensions::AppExtension*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::AppExtensions::IAppExtension*,
                                                    IVectorView<ABI::Windows::ApplicationModel::AppExtensions::AppExtension*>,
                                                    WAAAppExtension,
                                                    ABI::Windows::ApplicationModel::AppExtensions::AppExtension*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
