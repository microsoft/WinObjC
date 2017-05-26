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

// WindowsManagementDeployment.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Management.Deployment.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsManagementDeployment.h"
#include "WindowsManagementDeployment_priv.h"

@implementation WMDDeploymentResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IDeploymentResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFGUID*)activityId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IDeploymentResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivityId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (HRESULT)extendedErrorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IDeploymentResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WMDPackageUserInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Management::Deployment::IPackageUserInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)userSecurityId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageUserInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserSecurityId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMDPackageInstallState)installState {
    ABI::Windows::Management::Deployment::PackageInstallState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageUserInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstallState(&unmarshalledReturn));
    return (WMDPackageInstallState)unmarshalledReturn;
}

@end

@implementation WMDPackageVolume

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Management::Deployment::IPackageVolume> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isOffline {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOffline(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isSystemVolume {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSystemVolume(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)mountPoint {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(_comInst->get_MountPoint(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)packageStorePath {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(_comInst->get_PackageStorePath(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)supportsHardLinks {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportsHardLinks(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSMutableArray* /* WAPackage* */)findPackages {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAPackage_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WAPackage* */)findPackagesByNamePublisher:(NSString*)packageName packagePublisher:(NSString*)packagePublisher {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackagesByNamePublisher(nsStrToHstr(packageName).Get(),
                                                             nsStrToHstr(packagePublisher).Get(),
                                                             unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAPackage_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WAPackage* */)findPackagesByPackageFamilyName:(NSString*)packageFamilyName {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackagesByPackageFamilyName(nsStrToHstr(packageFamilyName).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAPackage_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WAPackage* */)findPackagesWithPackageTypes:(WMDPackageTypes)packageTypes {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackagesWithPackageTypes((ABI::Windows::Management::Deployment::PackageTypes)packageTypes,
                                                              unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAPackage_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WAPackage* */)findPackagesByNamePublisherWithPackagesTypes:(WMDPackageTypes)packageTypes
                                                                     packageName:(NSString*)packageName
                                                                packagePublisher:(NSString*)packagePublisher {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindPackagesByNamePublisherWithPackagesTypes((ABI::Windows::Management::Deployment::PackageTypes)packageTypes,
                                                               nsStrToHstr(packageName).Get(),
                                                               nsStrToHstr(packagePublisher).Get(),
                                                               unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAPackage_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WAPackage* */)findPackagesByPackageFamilyNameWithPackageTypes:(WMDPackageTypes)packageTypes
                                                                  packageFamilyName:(NSString*)packageFamilyName {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindPackagesByPackageFamilyNameWithPackageTypes((ABI::Windows::Management::Deployment::PackageTypes)packageTypes,
                                                                  nsStrToHstr(packageFamilyName).Get(),
                                                                  unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAPackage_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WAPackage* */)findPackageByPackageFullName:(NSString*)packageFullName {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackageByPackageFullName(nsStrToHstr(packageFullName).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAPackage_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WAPackage* */)findPackagesByUserSecurityId:(NSString*)userSecurityId {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackagesByUserSecurityId(nsStrToHstr(userSecurityId).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAPackage_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WAPackage* */)findPackagesByUserSecurityIdNamePublisher:(NSString*)userSecurityId
                                                                  packageName:(NSString*)packageName
                                                             packagePublisher:(NSString*)packagePublisher {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackagesByUserSecurityIdNamePublisher(nsStrToHstr(userSecurityId).Get(),
                                                                           nsStrToHstr(packageName).Get(),
                                                                           nsStrToHstr(packagePublisher).Get(),
                                                                           unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAPackage_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WAPackage* */)findPackagesByUserSecurityIdPackageFamilyName:(NSString*)userSecurityId
                                                                packageFamilyName:(NSString*)packageFamilyName {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackagesByUserSecurityIdPackageFamilyName(nsStrToHstr(userSecurityId).Get(),
                                                                               nsStrToHstr(packageFamilyName).Get(),
                                                                               unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAPackage_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WAPackage* */)findPackagesByUserSecurityIdWithPackageTypes:(NSString*)userSecurityId
                                                                    packageTypes:(WMDPackageTypes)packageTypes {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindPackagesByUserSecurityIdWithPackageTypes(nsStrToHstr(userSecurityId).Get(),
                                                               (ABI::Windows::Management::Deployment::PackageTypes)packageTypes,
                                                               unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAPackage_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WAPackage* */)findPackagesByUserSecurityIdNamePublisherWithPackageTypes:(NSString*)userSecurityId
                                                                                 packageTypes:(WMDPackageTypes)packageTypes
                                                                                  packageName:(NSString*)packageName
                                                                             packagePublisher:(NSString*)packagePublisher {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindPackagesByUserSecurityIdNamePublisherWithPackageTypes(nsStrToHstr(userSecurityId).Get(),
                                                                            (ABI::Windows::Management::Deployment::PackageTypes)
                                                                                packageTypes,
                                                                            nsStrToHstr(packageName).Get(),
                                                                            nsStrToHstr(packagePublisher).Get(),
                                                                            unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAPackage_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WAPackage* */)findPackagesByUserSecurityIdPackageFamilyNameWithPackagesTypes:(NSString*)userSecurityId
                                                                                      packageTypes:(WMDPackageTypes)packageTypes
                                                                                 packageFamilyName:(NSString*)packageFamilyName {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindPackagesByUserSecurityIdPackageFamilyNameWithPackagesTypes(nsStrToHstr(userSecurityId).Get(),
                                                                                 (ABI::Windows::Management::Deployment::PackageTypes)
                                                                                     packageTypes,
                                                                                 nsStrToHstr(packageFamilyName).Get(),
                                                                                 unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAPackage_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WAPackage* */)findPackageByUserSecurityIdPackageFullName:(NSString*)userSecurityId
                                                               packageFullName:(NSString*)packageFullName {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackageByUserSecurityIdPackageFullName(nsStrToHstr(userSecurityId).Get(),
                                                                            nsStrToHstr(packageFullName).Get(),
                                                                            unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAPackage_create(unmarshalledReturn.Get());
}

- (BOOL)isFullTrustPackageSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsFullTrustPackageSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isAppxInstallSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsAppxInstallSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)getAvailableSpaceAsyncWithSuccess:(void (^)(uint64_t))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageVolume2>(self);
    THROW_NS_IF_FAILED(_comInst->GetAvailableSpaceAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<uint64_t>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<uint64_t>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        uint64_t result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(result);
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

@implementation WMDPackageManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Management::Deployment::IPackageManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Management.Deployment.PackageManager").Get(), &out));
    return [_createRtProxy<WMDPackageManager>(out.Get()) retain];
}

- (void)addPackageAsync:(WFUri*)packageUri
    dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris
        deploymentOptions:(WMDDeploymentOptions)deploymentOptions
                  success:(void (^)(WMDDeploymentResult*))success
                 progress:(void (^)(WMDDeploymentProgress*))progress
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager>(self);
    THROW_NS_IF_FAILED(_comInst->AddPackageAsync(
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(packageUri).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                              ABI::Windows::Foundation::IUriRuntimeClass*>>::type>*>(
            ConvertToIterable<WFUri,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                                                ABI::Windows::Foundation::IUriRuntimeClass*>>(
                dependencyPackageUris)
                .Get()),
        (ABI::Windows::Management::Deployment::DeploymentOptions)deploymentOptions,
        &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (void)updatePackageAsync:(WFUri*)packageUri
     dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris
         deploymentOptions:(WMDDeploymentOptions)deploymentOptions
                   success:(void (^)(WMDDeploymentResult*))success
                  progress:(void (^)(WMDDeploymentProgress*))progress
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager>(self);
    THROW_NS_IF_FAILED(_comInst->UpdatePackageAsync(
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(packageUri).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                              ABI::Windows::Foundation::IUriRuntimeClass*>>::type>*>(
            ConvertToIterable<WFUri,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                                                ABI::Windows::Foundation::IUriRuntimeClass*>>(
                dependencyPackageUris)
                .Get()),
        (ABI::Windows::Management::Deployment::DeploymentOptions)deploymentOptions,
        &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (void)removePackageAsync:(NSString*)packageFullName
                   success:(void (^)(WMDDeploymentResult*))success
                  progress:(void (^)(WMDDeploymentProgress*))progress
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager>(self);
    THROW_NS_IF_FAILED(_comInst->RemovePackageAsync(nsStrToHstr(packageFullName).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (void)stagePackageAsync:(WFUri*)packageUri
    dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris
                  success:(void (^)(WMDDeploymentResult*))success
                 progress:(void (^)(WMDDeploymentProgress*))progress
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager>(self);
    THROW_NS_IF_FAILED(_comInst->StagePackageAsync(
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(packageUri).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                              ABI::Windows::Foundation::IUriRuntimeClass*>>::type>*>(
            ConvertToIterable<WFUri,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                                                ABI::Windows::Foundation::IUriRuntimeClass*>>(
                dependencyPackageUris)
                .Get()),
        &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (void)registerPackageAsync:(WFUri*)manifestUri
       dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris
           deploymentOptions:(WMDDeploymentOptions)deploymentOptions
                     success:(void (^)(WMDDeploymentResult*))success
                    progress:(void (^)(WMDDeploymentProgress*))progress
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterPackageAsync(
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(manifestUri).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                              ABI::Windows::Foundation::IUriRuntimeClass*>>::type>*>(
            ConvertToIterable<WFUri,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                                                ABI::Windows::Foundation::IUriRuntimeClass*>>(
                dependencyPackageUris)
                .Get()),
        (ABI::Windows::Management::Deployment::DeploymentOptions)deploymentOptions,
        &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (id<NSFastEnumeration> /* WAPackage* */)findPackages {
    ComPtr<IIterable<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WAPackage_create(unmarshalledReturn.Get());
}

- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByUserSecurityId:(NSString*)userSecurityId {
    ComPtr<IIterable<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackagesByUserSecurityId(nsStrToHstr(userSecurityId).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WAPackage_create(unmarshalledReturn.Get());
}

- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByNamePublisher:(NSString*)packageName packagePublisher:(NSString*)packagePublisher {
    ComPtr<IIterable<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackagesByNamePublisher(nsStrToHstr(packageName).Get(),
                                                             nsStrToHstr(packagePublisher).Get(),
                                                             unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WAPackage_create(unmarshalledReturn.Get());
}

- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByUserSecurityIdNamePublisher:(NSString*)userSecurityId
                                                                        packageName:(NSString*)packageName
                                                                   packagePublisher:(NSString*)packagePublisher {
    ComPtr<IIterable<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackagesByUserSecurityIdNamePublisher(nsStrToHstr(userSecurityId).Get(),
                                                                           nsStrToHstr(packageName).Get(),
                                                                           nsStrToHstr(packagePublisher).Get(),
                                                                           unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WAPackage_create(unmarshalledReturn.Get());
}

- (id<NSFastEnumeration> /* WMDPackageUserInformation* */)findUsers:(NSString*)packageFullName {
    ComPtr<IIterable<ABI::Windows::Management::Deployment::PackageUserInformation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager>(self);
    THROW_NS_IF_FAILED(_comInst->FindUsers(nsStrToHstr(packageFullName).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WMDPackageUserInformation_create(unmarshalledReturn.Get());
}

- (void)setPackageState:(NSString*)packageFullName packageState:(WMDPackageState)packageState {
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetPackageState(nsStrToHstr(packageFullName).Get(), (ABI::Windows::Management::Deployment::PackageState)packageState));
}

- (WAPackage*)findPackageByPackageFullName:(NSString*)packageFullName {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackageByPackageFullName(nsStrToHstr(packageFullName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

- (void)cleanupPackageForUserAsync:(NSString*)packageName
                    userSecurityId:(NSString*)userSecurityId
                           success:(void (^)(WMDDeploymentResult*))success
                          progress:(void (^)(WMDDeploymentProgress*))progress
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->CleanupPackageForUserAsync(nsStrToHstr(packageName).Get(), nsStrToHstr(userSecurityId).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByPackageFamilyName:(NSString*)packageFamilyName {
    ComPtr<IIterable<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackagesByPackageFamilyName(nsStrToHstr(packageFamilyName).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WAPackage_create(unmarshalledReturn.Get());
}

- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByUserSecurityIdPackageFamilyName:(NSString*)userSecurityId
                                                                      packageFamilyName:(NSString*)packageFamilyName {
    ComPtr<IIterable<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackagesByUserSecurityIdPackageFamilyName(nsStrToHstr(userSecurityId).Get(),
                                                                               nsStrToHstr(packageFamilyName).Get(),
                                                                               unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WAPackage_create(unmarshalledReturn.Get());
}

- (WAPackage*)findPackageByUserSecurityIdPackageFullName:(NSString*)userSecurityId packageFullName:(NSString*)packageFullName {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackageByUserSecurityIdPackageFullName(nsStrToHstr(userSecurityId).Get(),
                                                                            nsStrToHstr(packageFullName).Get(),
                                                                            unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

- (void)removePackageWithOptionsAsync:(NSString*)packageFullName
                       removalOptions:(WMDRemovalOptions)removalOptions
                              success:(void (^)(WMDDeploymentResult*))success
                             progress:(void (^)(WMDDeploymentProgress*))progress
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager2>(self);
    THROW_NS_IF_FAILED(_comInst->RemovePackageWithOptionsAsync(nsStrToHstr(packageFullName).Get(),
                                                               (ABI::Windows::Management::Deployment::RemovalOptions)removalOptions,
                                                               &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (void)stagePackageWithOptionsAsync:(WFUri*)packageUri
               dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris
                   deploymentOptions:(WMDDeploymentOptions)deploymentOptions
                             success:(void (^)(WMDDeploymentResult*))success
                            progress:(void (^)(WMDDeploymentProgress*))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager2>(self);
    THROW_NS_IF_FAILED(_comInst->StagePackageWithOptionsAsync(
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(packageUri).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                              ABI::Windows::Foundation::IUriRuntimeClass*>>::type>*>(
            ConvertToIterable<WFUri,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                                                ABI::Windows::Foundation::IUriRuntimeClass*>>(
                dependencyPackageUris)
                .Get()),
        (ABI::Windows::Management::Deployment::DeploymentOptions)deploymentOptions,
        &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (void)registerPackageByFullNameAsync:(NSString*)mainPackageFullName
            dependencyPackageFullNames:(id<NSFastEnumeration> /* NSString * */)dependencyPackageFullNames
                     deploymentOptions:(WMDDeploymentOptions)deploymentOptions
                               success:(void (^)(WMDDeploymentResult*))success
                              progress:(void (^)(WMDDeploymentProgress*))progress
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager2>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterPackageByFullNameAsync(
        nsStrToHstr(mainPackageFullName).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(dependencyPackageFullNames).Get()),
        (ABI::Windows::Management::Deployment::DeploymentOptions)deploymentOptions,
        &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (id<NSFastEnumeration> /* WAPackage* */)findPackagesWithPackageTypes:(WMDPackageTypes)packageTypes {
    ComPtr<IIterable<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager2>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackagesWithPackageTypes((ABI::Windows::Management::Deployment::PackageTypes)packageTypes,
                                                              unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WAPackage_create(unmarshalledReturn.Get());
}

- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByUserSecurityIdWithPackageTypes:(NSString*)userSecurityId
                                                                          packageTypes:(WMDPackageTypes)packageTypes {
    ComPtr<IIterable<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager2>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindPackagesByUserSecurityIdWithPackageTypes(nsStrToHstr(userSecurityId).Get(),
                                                               (ABI::Windows::Management::Deployment::PackageTypes)packageTypes,
                                                               unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WAPackage_create(unmarshalledReturn.Get());
}

- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByNamePublisherWithPackageTypes:(NSString*)packageName
                                                                     packagePublisher:(NSString*)packagePublisher
                                                                         packageTypes:(WMDPackageTypes)packageTypes {
    ComPtr<IIterable<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager2>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindPackagesByNamePublisherWithPackageTypes(nsStrToHstr(packageName).Get(),
                                                              nsStrToHstr(packagePublisher).Get(),
                                                              (ABI::Windows::Management::Deployment::PackageTypes)packageTypes,
                                                              unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WAPackage_create(unmarshalledReturn.Get());
}

- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByUserSecurityIdNamePublisherWithPackageTypes:(NSString*)userSecurityId
                                                                                        packageName:(NSString*)packageName
                                                                                   packagePublisher:(NSString*)packagePublisher
                                                                                       packageTypes:(WMDPackageTypes)packageTypes {
    ComPtr<IIterable<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager2>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindPackagesByUserSecurityIdNamePublisherWithPackageTypes(nsStrToHstr(userSecurityId).Get(),
                                                                            nsStrToHstr(packageName).Get(),
                                                                            nsStrToHstr(packagePublisher).Get(),
                                                                            (ABI::Windows::Management::Deployment::PackageTypes)
                                                                                packageTypes,
                                                                            unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WAPackage_create(unmarshalledReturn.Get());
}

- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByPackageFamilyNameWithPackageTypes:(NSString*)packageFamilyName
                                                                             packageTypes:(WMDPackageTypes)packageTypes {
    ComPtr<IIterable<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager2>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindPackagesByPackageFamilyNameWithPackageTypes(nsStrToHstr(packageFamilyName).Get(),
                                                                  (ABI::Windows::Management::Deployment::PackageTypes)packageTypes,
                                                                  unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WAPackage_create(unmarshalledReturn.Get());
}

- (id<NSFastEnumeration> /* WAPackage* */)findPackagesByUserSecurityIdPackageFamilyNameWithPackageTypes:(NSString*)userSecurityId
                                                                                      packageFamilyName:(NSString*)packageFamilyName
                                                                                           packageTypes:(WMDPackageTypes)packageTypes {
    ComPtr<IIterable<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager2>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindPackagesByUserSecurityIdPackageFamilyNameWithPackageTypes(nsStrToHstr(userSecurityId).Get(),
                                                                                nsStrToHstr(packageFamilyName).Get(),
                                                                                (ABI::Windows::Management::Deployment::PackageTypes)
                                                                                    packageTypes,
                                                                                unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WAPackage_create(unmarshalledReturn.Get());
}

- (void)stageUserDataAsync:(NSString*)packageFullName
                   success:(void (^)(WMDDeploymentResult*))success
                  progress:(void (^)(WMDDeploymentProgress*))progress
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager2>(self);
    THROW_NS_IF_FAILED(_comInst->StageUserDataAsync(nsStrToHstr(packageFullName).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (void)addPackageVolumeAsync:(NSString*)packageStorePath success:(void (^)(WMDPackageVolume*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Management::Deployment::PackageVolume*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager3>(self);
    THROW_NS_IF_FAILED(_comInst->AddPackageVolumeAsync(nsStrToHstr(packageStorePath).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Management::Deployment::PackageVolume*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Management::Deployment::PackageVolume*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IPackageVolume> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDPackageVolume>(result.Get()));
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

- (void)addPackageToVolumeAsync:(WFUri*)packageUri
          dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris
              deploymentOptions:(WMDDeploymentOptions)deploymentOptions
                   targetVolume:(WMDPackageVolume*)targetVolume
                        success:(void (^)(WMDDeploymentResult*))success
                       progress:(void (^)(WMDDeploymentProgress*))progress
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager3>(self);
    THROW_NS_IF_FAILED(_comInst->AddPackageToVolumeAsync(
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(packageUri).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                              ABI::Windows::Foundation::IUriRuntimeClass*>>::type>*>(
            ConvertToIterable<WFUri,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                                                ABI::Windows::Foundation::IUriRuntimeClass*>>(
                dependencyPackageUris)
                .Get()),
        (ABI::Windows::Management::Deployment::DeploymentOptions)deploymentOptions,
        _getRtInterface<ABI::Windows::Management::Deployment::IPackageVolume>(targetVolume).Get(),
        &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (void)clearPackageStatus:(NSString*)packageFullName status:(WMDPackageStatus)status {
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager3>(self);
    THROW_NS_IF_FAILED(
        _comInst->ClearPackageStatus(nsStrToHstr(packageFullName).Get(), (ABI::Windows::Management::Deployment::PackageStatus)status));
}

- (void)registerPackageWithAppDataVolumeAsync:(WFUri*)manifestUri
                        dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris
                            deploymentOptions:(WMDDeploymentOptions)deploymentOptions
                                appDataVolume:(WMDPackageVolume*)appDataVolume
                                      success:(void (^)(WMDDeploymentResult*))success
                                     progress:(void (^)(WMDDeploymentProgress*))progress
                                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager3>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterPackageWithAppDataVolumeAsync(
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(manifestUri).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                              ABI::Windows::Foundation::IUriRuntimeClass*>>::type>*>(
            ConvertToIterable<WFUri,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                                                ABI::Windows::Foundation::IUriRuntimeClass*>>(
                dependencyPackageUris)
                .Get()),
        (ABI::Windows::Management::Deployment::DeploymentOptions)deploymentOptions,
        _getRtInterface<ABI::Windows::Management::Deployment::IPackageVolume>(appDataVolume).Get(),
        &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (WMDPackageVolume*)findPackageVolumeByName:(NSString*)volumeName {
    ComPtr<ABI::Windows::Management::Deployment::IPackageVolume> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager3>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackageVolumeByName(nsStrToHstr(volumeName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDPackageVolume>(unmarshalledReturn.Get());
}

- (id<NSFastEnumeration> /* WMDPackageVolume* */)findPackageVolumes {
    ComPtr<IIterable<ABI::Windows::Management::Deployment::PackageVolume*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager3>(self);
    THROW_NS_IF_FAILED(_comInst->FindPackageVolumes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WMDPackageVolume_create(unmarshalledReturn.Get());
}

- (WMDPackageVolume*)getDefaultPackageVolume {
    ComPtr<ABI::Windows::Management::Deployment::IPackageVolume> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager3>(self);
    THROW_NS_IF_FAILED(_comInst->GetDefaultPackageVolume(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDPackageVolume>(unmarshalledReturn.Get());
}

- (void)movePackageToVolumeAsync:(NSString*)packageFullName
               deploymentOptions:(WMDDeploymentOptions)deploymentOptions
                    targetVolume:(WMDPackageVolume*)targetVolume
                         success:(void (^)(WMDDeploymentResult*))success
                        progress:(void (^)(WMDDeploymentProgress*))progress
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager3>(self);
    THROW_NS_IF_FAILED(
        _comInst->MovePackageToVolumeAsync(nsStrToHstr(packageFullName).Get(),
                                           (ABI::Windows::Management::Deployment::DeploymentOptions)deploymentOptions,
                                           _getRtInterface<ABI::Windows::Management::Deployment::IPackageVolume>(targetVolume).Get(),
                                           &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (void)removePackageVolumeAsync:(WMDPackageVolume*)volume
                         success:(void (^)(WMDDeploymentResult*))success
                        progress:(void (^)(WMDDeploymentProgress*))progress
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager3>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemovePackageVolumeAsync(_getRtInterface<ABI::Windows::Management::Deployment::IPackageVolume>(volume).Get(),
                                           &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (void)setDefaultPackageVolume:(WMDPackageVolume*)volume {
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager3>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetDefaultPackageVolume(_getRtInterface<ABI::Windows::Management::Deployment::IPackageVolume>(volume).Get()));
}

- (void)setPackageStatus:(NSString*)packageFullName status:(WMDPackageStatus)status {
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager3>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetPackageStatus(nsStrToHstr(packageFullName).Get(), (ABI::Windows::Management::Deployment::PackageStatus)status));
}

- (void)setPackageVolumeOfflineAsync:(WMDPackageVolume*)packageVolume
                             success:(void (^)(WMDDeploymentResult*))success
                            progress:(void (^)(WMDDeploymentProgress*))progress
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager3>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetPackageVolumeOfflineAsync(_getRtInterface<ABI::Windows::Management::Deployment::IPackageVolume>(packageVolume).Get(),
                                               &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (void)setPackageVolumeOnlineAsync:(WMDPackageVolume*)packageVolume
                            success:(void (^)(WMDDeploymentResult*))success
                           progress:(void (^)(WMDDeploymentProgress*))progress
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager3>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetPackageVolumeOnlineAsync(_getRtInterface<ABI::Windows::Management::Deployment::IPackageVolume>(packageVolume).Get(),
                                              &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (void)stagePackageToVolumeAsync:(WFUri*)packageUri
            dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris
                deploymentOptions:(WMDDeploymentOptions)deploymentOptions
                     targetVolume:(WMDPackageVolume*)targetVolume
                          success:(void (^)(WMDDeploymentResult*))success
                         progress:(void (^)(WMDDeploymentProgress*))progress
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager3>(self);
    THROW_NS_IF_FAILED(_comInst->StagePackageToVolumeAsync(
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(packageUri).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                              ABI::Windows::Foundation::IUriRuntimeClass*>>::type>*>(
            ConvertToIterable<WFUri,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Foundation::Uri*,
                                                                                ABI::Windows::Foundation::IUriRuntimeClass*>>(
                dependencyPackageUris)
                .Get()),
        (ABI::Windows::Management::Deployment::DeploymentOptions)deploymentOptions,
        _getRtInterface<ABI::Windows::Management::Deployment::IPackageVolume>(targetVolume).Get(),
        &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (void)stageUserDataWithOptionsAsync:(NSString*)packageFullName
                    deploymentOptions:(WMDDeploymentOptions)deploymentOptions
                              success:(void (^)(WMDDeploymentResult*))success
                             progress:(void (^)(WMDDeploymentProgress*))progress
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                 ABI::Windows::Management::Deployment::DeploymentProgress>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager3>(self);
    THROW_NS_IF_FAILED(_comInst->StageUserDataWithOptionsAsync(nsStrToHstr(packageFullName).Get(),
                                                               (ABI::Windows::Management::Deployment::DeploymentOptions)deploymentOptions,
                                                               &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                     ABI::Windows::Management::Deployment::DeploymentProgress>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                  ABI::Windows::Management::Deployment::DeploymentProgress>* op,
            ABI::Windows::Management::Deployment::DeploymentProgress status) {
            @autoreleasepool {
                progressRc(WMDDeploymentProgress_create(status));
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                              ABI::Windows::Management::Deployment::DeploymentProgress>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Management::Deployment::DeploymentResult*,
                                                                          ABI::Windows::Management::Deployment::DeploymentProgress>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Management::Deployment::IDeploymentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMDDeploymentResult>(result.Get()));
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

- (void)getPackageVolumesAsyncWithSuccess:(void (^)(NSArray* /* WMDPackageVolume* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Management::Deployment::PackageVolume*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::IPackageManager4>(self);
    THROW_NS_IF_FAILED(_comInst->GetPackageVolumesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Management::Deployment::PackageVolume*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Management::Deployment::PackageVolume*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Management::Deployment::PackageVolume*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WMDPackageVolume_create(result.Get()));
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

@implementation WMDDeploymentProgress {
    ABI::Windows::Management::Deployment::DeploymentProgress structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Management::Deployment::DeploymentProgress)s {
    WMDDeploymentProgress* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Management::Deployment::DeploymentProgress*)internalStruct {
    return &structVal;
}
- (WMDDeploymentProgressState)state {
    return (WMDDeploymentProgressState)structVal.state;
}
- (void)setState:(WMDDeploymentProgressState)val {
    structVal.state = (ABI::Windows::Management::Deployment::DeploymentProgressState)val;
}
- (unsigned int)percentage {
    return structVal.percentage;
}
- (void)setPercentage:(unsigned int)val {
    structVal.percentage = val;
}
@end
id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WAPackage_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::ApplicationModel::Package*>,
                                                 RTIterableObj<ABI::Windows::ApplicationModel::IPackage*,
                                                               IIterable<ABI::Windows::ApplicationModel::Package*>,
                                                               WAPackage,
                                                               ABI::Windows::ApplicationModel::Package*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WFUri_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Foundation::Uri*>,
                                                 RTIterableObj<ABI::Windows::Foundation::IUriRuntimeClass*,
                                                               IIterable<ABI::Windows::Foundation::Uri*>,
                                                               WFUri,
                                                               ABI::Windows::Foundation::Uri*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WMDPackageUserInformation_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Management::Deployment::PackageUserInformation*>,
                                                 RTIterableObj<ABI::Windows::Management::Deployment::IPackageUserInformation*,
                                                               IIterable<ABI::Windows::Management::Deployment::PackageUserInformation*>,
                                                               WMDPackageUserInformation,
                                                               ABI::Windows::Management::Deployment::PackageUserInformation*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WMDPackageVolume_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Management::Deployment::PackageVolume*>,
                                                 RTIterableObj<ABI::Windows::Management::Deployment::IPackageVolume*,
                                                               IIterable<ABI::Windows::Management::Deployment::PackageVolume*>,
                                                               WMDPackageVolume,
                                                               ABI::Windows::Management::Deployment::PackageVolume*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMDPackageVolume_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Management::Deployment::PackageVolume*>,
                                         RTArrayObj<ABI::Windows::Management::Deployment::IPackageVolume*,
                                                    IVectorView<ABI::Windows::Management::Deployment::PackageVolume*>,
                                                    WMDPackageVolume,
                                                    ABI::Windows::Management::Deployment::PackageVolume*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WAPackage_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::Package*>,
                                                RTMutableArrayObj<ABI::Windows::ApplicationModel::IPackage*,
                                                                  IVector<ABI::Windows::ApplicationModel::Package*>,
                                                                  WAPackage,
                                                                  ABI::Windows::ApplicationModel::Package*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
