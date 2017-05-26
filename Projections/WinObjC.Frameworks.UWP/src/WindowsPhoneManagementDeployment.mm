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

// WindowsPhoneManagementDeployment.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Phone.Management.Deployment.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPhoneManagementDeployment.h"
#include "WindowsPhoneManagementDeployment_priv.h"

@implementation WPMDEnterprise

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Management::Deployment::IEnterprise> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)id {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Management::Deployment::IEnterprise>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Management::Deployment::IEnterprise>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)workplaceId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Management::Deployment::IEnterprise>(self);
    THROW_NS_IF_FAILED(_comInst->get_WorkplaceId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFDateTime*)enrollmentValidFrom {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Management::Deployment::IEnterprise>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnrollmentValidFrom(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFDateTime*)enrollmentValidTo {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Management::Deployment::IEnterprise>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnrollmentValidTo(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WPMDEnterpriseStatus)status {
    ABI::Windows::Phone::Management::Deployment::EnterpriseStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Management::Deployment::IEnterprise>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WPMDEnterpriseStatus)unmarshalledReturn;
}

@end

@implementation WPMDEnterpriseEnrollmentResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WPMDEnterprise*)enrolledEnterprise {
    ComPtr<ABI::Windows::Phone::Management::Deployment::IEnterprise> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnrolledEnterprise(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPMDEnterprise>(unmarshalledReturn.Get());
}

- (WPMDEnterpriseEnrollmentStatus)status {
    ABI::Windows::Phone::Management::Deployment::EnterpriseEnrollmentStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WPMDEnterpriseEnrollmentStatus)unmarshalledReturn;
}

@end

@implementation WPMDPackageInstallResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Management::Deployment::IPackageInstallResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)productId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Management::Deployment::IPackageInstallResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProductId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMDPackageInstallState)installState {
    ABI::Windows::Management::Deployment::PackageInstallState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Management::Deployment::IPackageInstallResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstallState(&unmarshalledReturn));
    return (WMDPackageInstallState)unmarshalledReturn;
}

- (NSString*)errorText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Management::Deployment::IPackageInstallResult2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WPMDInstallationManager

ComPtr<ABI::Windows::Phone::Management::Deployment::IInstallationManagerStatics> WPMDIInstallationManagerStatics_inst() {
    ComPtr<ABI::Windows::Phone::Management::Deployment::IInstallationManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Phone.Management.Deployment.InstallationManager").Get(), &inst));
    return inst;
}

+ (void)addPackageAsync:(NSString*)title
         sourceLocation:(WFUri*)sourceLocation
                success:(void (^)(WPMDPackageInstallResult*))success
               progress:(void (^)(unsigned int))progress
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                 unsigned int>>
        unmarshalledReturn;
    auto _comInst = WPMDIInstallationManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AddPackageAsync(nsStrToHstr(title).Get(),
                                                 _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(sourceLocation).Get(),
                                                 &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                     unsigned int>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                  unsigned int>* op,
            unsigned int status) {
            @autoreleasepool {
                progressRc(status);
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<
                                                                    ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                    unsigned int>>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                  unsigned int>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Phone::Management::Deployment::IPackageInstallResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WPMDPackageInstallResult>(result.Get()));
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

+ (void)addPackagePreloadedAsync:(NSString*)title
                  sourceLocation:(WFUri*)sourceLocation
                      instanceId:(NSString*)instanceId
                         offerId:(NSString*)offerId
                         license:(WFUri*)license
                         success:(void (^)(WPMDPackageInstallResult*))success
                        progress:(void (^)(unsigned int))progress
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                 unsigned int>>
        unmarshalledReturn;
    auto _comInst = WPMDIInstallationManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AddPackagePreloadedAsync(nsStrToHstr(title).Get(),
                                                          _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(sourceLocation).Get(),
                                                          nsStrToHstr(instanceId).Get(),
                                                          nsStrToHstr(offerId).Get(),
                                                          _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(license).Get(),
                                                          &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                     unsigned int>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                  unsigned int>* op,
            unsigned int status) {
            @autoreleasepool {
                progressRc(status);
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<
                                                                    ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                    unsigned int>>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                  unsigned int>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Phone::Management::Deployment::IPackageInstallResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WPMDPackageInstallResult>(result.Get()));
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

// Failed to generate GetPendingPackageInstalls (Can't marshal
// Windows.Foundation.IAsyncOperationWithProgress`2<Windows.Phone.Management.Deployment.PackageInstallResult,UInt32>)

+ (id<NSFastEnumeration> /* WAPackage* */)findPackagesForCurrentPublisher {
    ComPtr<IIterable<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = WPMDIInstallationManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindPackagesForCurrentPublisher(unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WAPackage_create(unmarshalledReturn.Get());
}

+ (id<NSFastEnumeration> /* WAPackage* */)findPackages {
    ComPtr<IIterable<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = WPMDIInstallationManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindPackages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WAPackage_create(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Phone::Management::Deployment::IInstallationManagerStatics2> WPMDIInstallationManagerStatics2_inst() {
    ComPtr<ABI::Windows::Phone::Management::Deployment::IInstallationManagerStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Phone.Management.Deployment.InstallationManager").Get(), &inst));
    return inst;
}

+ (void)removePackageAsync:(NSString*)packageFullName
            removalOptions:(WMDRemovalOptions)removalOptions
                   success:(void (^)(WPMDPackageInstallResult*))success
                  progress:(void (^)(unsigned int))progress
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                 unsigned int>>
        unmarshalledReturn;
    auto _comInst = WPMDIInstallationManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->RemovePackageAsync(nsStrToHstr(packageFullName).Get(),
                                                    (ABI::Windows::Management::Deployment::RemovalOptions)removalOptions,
                                                    &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                     unsigned int>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                  unsigned int>* op,
            unsigned int status) {
            @autoreleasepool {
                progressRc(status);
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<
                                                                    ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                    unsigned int>>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                  unsigned int>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Phone::Management::Deployment::IPackageInstallResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WPMDPackageInstallResult>(result.Get()));
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

+ (void)registerPackageAsync:(WFUri*)manifestUri
       dependencyPackageUris:(id<NSFastEnumeration> /* WFUri* */)dependencyPackageUris
           deploymentOptions:(WMDDeploymentOptions)deploymentOptions
                     success:(void (^)(WPMDPackageInstallResult*))success
                    progress:(void (^)(unsigned int))progress
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                 unsigned int>>
        unmarshalledReturn;
    auto _comInst = WPMDIInstallationManagerStatics2_inst();
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
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                     unsigned int>,
            FtmBase>>([progressRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                  unsigned int>* op,
            unsigned int status) {
            @autoreleasepool {
                progressRc(status);
                return S_OK;
            }
        });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<
                                                                    ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                    unsigned int>>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Phone::Management::Deployment::PackageInstallResult*,
                                                                  unsigned int>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Phone::Management::Deployment::IPackageInstallResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WPMDPackageInstallResult>(result.Get()));
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

+ (id<NSFastEnumeration> /* WAPackage* */)findPackagesByNamePublisher:(NSString*)packageName packagePublisher:(NSString*)packagePublisher {
    ComPtr<IIterable<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = WPMDIInstallationManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->FindPackagesByNamePublisher(nsStrToHstr(packageName).Get(),
                                                             nsStrToHstr(packagePublisher).Get(),
                                                             unmarshalledReturn.GetAddressOf()));
    return RTProxiedIterableNSArray_WAPackage_create(unmarshalledReturn.Get());
}

@end

@implementation WPMDEnterpriseEnrollmentManager

ComPtr<ABI::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentManager> WPMDIEnterpriseEnrollmentManager_inst() {
    ComPtr<ABI::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentManager> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Phone.Management.Deployment.EnterpriseEnrollmentManager").Get(), &inst));
    return inst;
}

+ (NSArray* /* WPMDEnterprise* */)enrolledEnterprises {
    ComPtr<IVectorView<ABI::Windows::Phone::Management::Deployment::Enterprise*>> unmarshalledReturn;
    auto _comInst = WPMDIEnterpriseEnrollmentManager_inst();
    THROW_NS_IF_FAILED(_comInst->get_EnrolledEnterprises(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WPMDEnterprise_create(unmarshalledReturn.Get());
}

+ (WPMDEnterprise*)currentEnterprise {
    ComPtr<ABI::Windows::Phone::Management::Deployment::IEnterprise> unmarshalledReturn;
    auto _comInst = WPMDIEnterpriseEnrollmentManager_inst();
    THROW_NS_IF_FAILED(_comInst->get_CurrentEnterprise(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPMDEnterprise>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)validateEnterprisesAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WPMDIEnterpriseEnrollmentManager_inst();
    THROW_NS_IF_FAILED(_comInst->ValidateEnterprisesAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)requestEnrollmentAsync:(NSString*)enrollmentToken
                       success:(void (^)(WPMDEnterpriseEnrollmentResult*))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Phone::Management::Deployment::EnterpriseEnrollmentResult*>>
        unmarshalledReturn;
    auto _comInst = WPMDIEnterpriseEnrollmentManager_inst();
    THROW_NS_IF_FAILED(_comInst->RequestEnrollmentAsync(nsStrToHstr(enrollmentToken).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Phone::Management::Deployment::EnterpriseEnrollmentResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Phone::Management::Deployment::EnterpriseEnrollmentResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WPMDEnterpriseEnrollmentResult>(result.Get()));
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

+ (void)requestUnenrollmentAsync:(WPMDEnterprise*)enterprise success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WPMDIEnterpriseEnrollmentManager_inst();
    THROW_NS_IF_FAILED(
        _comInst->RequestUnenrollmentAsync(_getRtInterface<ABI::Windows::Phone::Management::Deployment::IEnterprise>(enterprise).Get(),
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

@end

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

id RTProxiedNSArray_WPMDEnterprise_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Phone::Management::Deployment::Enterprise*>,
                                         RTArrayObj<ABI::Windows::Phone::Management::Deployment::IEnterprise*,
                                                    IVectorView<ABI::Windows::Phone::Management::Deployment::Enterprise*>,
                                                    WPMDEnterprise,
                                                    ABI::Windows::Phone::Management::Deployment::Enterprise*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
