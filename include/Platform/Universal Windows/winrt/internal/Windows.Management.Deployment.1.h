// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Management.Deployment.0.h"
#include "Windows.ApplicationModel.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.ApplicationModel.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Management::Deployment {

struct DeploymentProgress
{
    winrt::Windows::Management::Deployment::DeploymentProgressState state;
    uint32_t percentage;
};

}

namespace Windows::Management::Deployment {

using DeploymentProgress = ABI::Windows::Management::Deployment::DeploymentProgress;

}

namespace ABI::Windows::Management::Deployment {

struct __declspec(uuid("2563b9ae-b77d-4c1f-8a7b-20e6ad515ef3")) __declspec(novtable) IDeploymentResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ErrorText(hstring * value) = 0;
    virtual HRESULT __stdcall get_ActivityId(GUID * value) = 0;
    virtual HRESULT __stdcall get_ExtendedErrorCode(HRESULT * value) = 0;
};

struct __declspec(uuid("9a7d4b65-5e8f-4fc7-a2e5-7f6925cb8b53")) __declspec(novtable) IPackageManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AddPackageAsync(Windows::Foundation::IUriRuntimeClass * packageUri, Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> * dependencyPackageUris, winrt::Windows::Management::Deployment::DeploymentOptions deploymentOptions, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
    virtual HRESULT __stdcall abi_UpdatePackageAsync(Windows::Foundation::IUriRuntimeClass * packageUri, Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> * dependencyPackageUris, winrt::Windows::Management::Deployment::DeploymentOptions deploymentOptions, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
    virtual HRESULT __stdcall abi_RemovePackageAsync(hstring packageFullName, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
    virtual HRESULT __stdcall abi_StagePackageAsync(Windows::Foundation::IUriRuntimeClass * packageUri, Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> * dependencyPackageUris, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
    virtual HRESULT __stdcall abi_RegisterPackageAsync(Windows::Foundation::IUriRuntimeClass * manifestUri, Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> * dependencyPackageUris, winrt::Windows::Management::Deployment::DeploymentOptions deploymentOptions, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
    virtual HRESULT __stdcall abi_FindPackages(Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByUserSecurityId(hstring userSecurityId, Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByNamePublisher(hstring packageName, hstring packagePublisher, Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByUserSecurityIdNamePublisher(hstring userSecurityId, hstring packageName, hstring packagePublisher, Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindUsers(hstring packageFullName, Windows::Foundation::Collections::IIterable<Windows::Management::Deployment::PackageUserInformation> ** users) = 0;
    virtual HRESULT __stdcall abi_SetPackageState(hstring packageFullName, winrt::Windows::Management::Deployment::PackageState packageState) = 0;
    virtual HRESULT __stdcall abi_FindPackageByPackageFullName(hstring packageFullName, Windows::ApplicationModel::IPackage ** packageInformation) = 0;
    virtual HRESULT __stdcall abi_CleanupPackageForUserAsync(hstring packageName, hstring userSecurityId, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByPackageFamilyName(hstring packageFamilyName, Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByUserSecurityIdPackageFamilyName(hstring userSecurityId, hstring packageFamilyName, Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackageByUserSecurityIdPackageFullName(hstring userSecurityId, hstring packageFullName, Windows::ApplicationModel::IPackage ** packageInformation) = 0;
};

struct __declspec(uuid("f7aad08d-0840-46f2-b5d8-cad47693a095")) __declspec(novtable) IPackageManager2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RemovePackageWithOptionsAsync(hstring packageFullName, winrt::Windows::Management::Deployment::RemovalOptions removalOptions, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
    virtual HRESULT __stdcall abi_StagePackageWithOptionsAsync(Windows::Foundation::IUriRuntimeClass * packageUri, Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> * dependencyPackageUris, winrt::Windows::Management::Deployment::DeploymentOptions deploymentOptions, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
    virtual HRESULT __stdcall abi_RegisterPackageByFullNameAsync(hstring mainPackageFullName, Windows::Foundation::Collections::IIterable<hstring> * dependencyPackageFullNames, winrt::Windows::Management::Deployment::DeploymentOptions deploymentOptions, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
    virtual HRESULT __stdcall abi_FindPackagesWithPackageTypes(winrt::Windows::Management::Deployment::PackageTypes packageTypes, Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByUserSecurityIdWithPackageTypes(hstring userSecurityId, winrt::Windows::Management::Deployment::PackageTypes packageTypes, Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByNamePublisherWithPackageTypes(hstring packageName, hstring packagePublisher, winrt::Windows::Management::Deployment::PackageTypes packageTypes, Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByUserSecurityIdNamePublisherWithPackageTypes(hstring userSecurityId, hstring packageName, hstring packagePublisher, winrt::Windows::Management::Deployment::PackageTypes packageTypes, Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByPackageFamilyNameWithPackageTypes(hstring packageFamilyName, winrt::Windows::Management::Deployment::PackageTypes packageTypes, Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByUserSecurityIdPackageFamilyNameWithPackageTypes(hstring userSecurityId, hstring packageFamilyName, winrt::Windows::Management::Deployment::PackageTypes packageTypes, Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_StageUserDataAsync(hstring packageFullName, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
};

struct __declspec(uuid("daad9948-36f1-41a7-9188-bc263e0dcb72")) __declspec(novtable) IPackageManager3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AddPackageVolumeAsync(hstring packageStorePath, Windows::Foundation::IAsyncOperation<Windows::Management::Deployment::PackageVolume> ** packageVolume) = 0;
    virtual HRESULT __stdcall abi_AddPackageToVolumeAsync(Windows::Foundation::IUriRuntimeClass * packageUri, Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> * dependencyPackageUris, winrt::Windows::Management::Deployment::DeploymentOptions deploymentOptions, Windows::Management::Deployment::IPackageVolume * targetVolume, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
    virtual HRESULT __stdcall abi_ClearPackageStatus(hstring packageFullName, winrt::Windows::Management::Deployment::PackageStatus status) = 0;
    virtual HRESULT __stdcall abi_RegisterPackageWithAppDataVolumeAsync(Windows::Foundation::IUriRuntimeClass * manifestUri, Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> * dependencyPackageUris, winrt::Windows::Management::Deployment::DeploymentOptions deploymentOptions, Windows::Management::Deployment::IPackageVolume * appDataVolume, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
    virtual HRESULT __stdcall abi_FindPackageVolumeByName(hstring volumeName, Windows::Management::Deployment::IPackageVolume ** volume) = 0;
    virtual HRESULT __stdcall abi_FindPackageVolumes(Windows::Foundation::Collections::IIterable<Windows::Management::Deployment::PackageVolume> ** volumeCollection) = 0;
    virtual HRESULT __stdcall abi_GetDefaultPackageVolume(Windows::Management::Deployment::IPackageVolume ** volume) = 0;
    virtual HRESULT __stdcall abi_MovePackageToVolumeAsync(hstring packageFullName, winrt::Windows::Management::Deployment::DeploymentOptions deploymentOptions, Windows::Management::Deployment::IPackageVolume * targetVolume, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
    virtual HRESULT __stdcall abi_RemovePackageVolumeAsync(Windows::Management::Deployment::IPackageVolume * volume, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
    virtual HRESULT __stdcall abi_SetDefaultPackageVolume(Windows::Management::Deployment::IPackageVolume * volume) = 0;
    virtual HRESULT __stdcall abi_SetPackageStatus(hstring packageFullName, winrt::Windows::Management::Deployment::PackageStatus status) = 0;
    virtual HRESULT __stdcall abi_SetPackageVolumeOfflineAsync(Windows::Management::Deployment::IPackageVolume * packageVolume, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
    virtual HRESULT __stdcall abi_SetPackageVolumeOnlineAsync(Windows::Management::Deployment::IPackageVolume * packageVolume, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
    virtual HRESULT __stdcall abi_StagePackageToVolumeAsync(Windows::Foundation::IUriRuntimeClass * packageUri, Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> * dependencyPackageUris, winrt::Windows::Management::Deployment::DeploymentOptions deploymentOptions, Windows::Management::Deployment::IPackageVolume * targetVolume, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
    virtual HRESULT __stdcall abi_StageUserDataWithOptionsAsync(hstring packageFullName, winrt::Windows::Management::Deployment::DeploymentOptions deploymentOptions, Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> ** deploymentOperation) = 0;
};

struct __declspec(uuid("3c719963-bab6-46bf-8ff7-da4719230ae6")) __declspec(novtable) IPackageManager4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetPackageVolumesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Management::Deployment::PackageVolume>> ** operation) = 0;
};

struct __declspec(uuid("f6383423-fa09-4cbc-9055-15ca275e2e7e")) __declspec(novtable) IPackageUserInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UserSecurityId(hstring * value) = 0;
    virtual HRESULT __stdcall get_InstallState(winrt::Windows::Management::Deployment::PackageInstallState * value) = 0;
};

struct __declspec(uuid("cf2672c3-1a40-4450-9739-2ace2e898853")) __declspec(novtable) IPackageVolume : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsOffline(bool * value) = 0;
    virtual HRESULT __stdcall get_IsSystemVolume(bool * value) = 0;
    virtual HRESULT __stdcall get_MountPoint(hstring * value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_PackageStorePath(hstring * value) = 0;
    virtual HRESULT __stdcall get_SupportsHardLinks(bool * value) = 0;
    virtual HRESULT __stdcall abi_FindPackages(Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByNamePublisher(hstring packageName, hstring packagePublisher, Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByPackageFamilyName(hstring packageFamilyName, Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesWithPackageTypes(winrt::Windows::Management::Deployment::PackageTypes packageTypes, Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByNamePublisherWithPackagesTypes(winrt::Windows::Management::Deployment::PackageTypes packageTypes, hstring packageName, hstring packagePublisher, Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByPackageFamilyNameWithPackageTypes(winrt::Windows::Management::Deployment::PackageTypes packageTypes, hstring packageFamilyName, Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackageByPackageFullName(hstring packageFullName, Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByUserSecurityId(hstring userSecurityId, Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByUserSecurityIdNamePublisher(hstring userSecurityId, hstring packageName, hstring packagePublisher, Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByUserSecurityIdPackageFamilyName(hstring userSecurityId, hstring packageFamilyName, Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByUserSecurityIdWithPackageTypes(hstring userSecurityId, winrt::Windows::Management::Deployment::PackageTypes packageTypes, Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByUserSecurityIdNamePublisherWithPackageTypes(hstring userSecurityId, winrt::Windows::Management::Deployment::PackageTypes packageTypes, hstring packageName, hstring packagePublisher, Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackagesByUserSecurityIdPackageFamilyNameWithPackagesTypes(hstring userSecurityId, winrt::Windows::Management::Deployment::PackageTypes packageTypes, hstring packageFamilyName, Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> ** packageCollection) = 0;
    virtual HRESULT __stdcall abi_FindPackageByUserSecurityIdPackageFullName(hstring userSecurityId, hstring packageFullName, Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> ** packageCollection) = 0;
};

struct __declspec(uuid("46abcf2e-9dd4-47a2-ab8c-c6408349bcd8")) __declspec(novtable) IPackageVolume2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsFullTrustPackageSupported(bool * value) = 0;
    virtual HRESULT __stdcall get_IsAppxInstallSupported(bool * value) = 0;
    virtual HRESULT __stdcall abi_GetAvailableSpaceAsync(Windows::Foundation::IAsyncOperation<uint64_t> ** operation) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Management::Deployment::DeploymentResult> { using default_interface = Windows::Management::Deployment::IDeploymentResult; };
template <> struct traits<Windows::Management::Deployment::PackageManager> { using default_interface = Windows::Management::Deployment::IPackageManager; };
template <> struct traits<Windows::Management::Deployment::PackageUserInformation> { using default_interface = Windows::Management::Deployment::IPackageUserInformation; };
template <> struct traits<Windows::Management::Deployment::PackageVolume> { using default_interface = Windows::Management::Deployment::IPackageVolume; };

}

namespace Windows::Management::Deployment {

template <typename D>
struct WINRT_EBO impl_IDeploymentResult
{
    hstring ErrorText() const;
    GUID ActivityId() const;
    HRESULT ExtendedErrorCode() const;
};

template <typename D>
struct WINRT_EBO impl_IPackageManager
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> AddPackageAsync(const Windows::Foundation::Uri & packageUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> UpdatePackageAsync(const Windows::Foundation::Uri & packageUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> RemovePackageAsync(hstring_view packageFullName) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> StagePackageAsync(const Windows::Foundation::Uri & packageUri, iterable<Windows::Foundation::Uri> dependencyPackageUris) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> RegisterPackageAsync(const Windows::Foundation::Uri & manifestUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions) const;
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> FindPackages() const;
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> FindPackagesForUser(hstring_view userSecurityId) const;
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> FindPackages(hstring_view packageName, hstring_view packagePublisher) const;
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> FindPackagesForUser(hstring_view userSecurityId, hstring_view packageName, hstring_view packagePublisher) const;
    Windows::Foundation::Collections::IIterable<Windows::Management::Deployment::PackageUserInformation> FindUsers(hstring_view packageFullName) const;
    void SetPackageState(hstring_view packageFullName, Windows::Management::Deployment::PackageState packageState) const;
    Windows::ApplicationModel::Package FindPackage(hstring_view packageFullName) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> CleanupPackageForUserAsync(hstring_view packageName, hstring_view userSecurityId) const;
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> FindPackages(hstring_view packageFamilyName) const;
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> FindPackagesForUser(hstring_view userSecurityId, hstring_view packageFamilyName) const;
    Windows::ApplicationModel::Package FindPackageForUser(hstring_view userSecurityId, hstring_view packageFullName) const;
};

template <typename D>
struct WINRT_EBO impl_IPackageManager2
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> RemovePackageAsync(hstring_view packageFullName, Windows::Management::Deployment::RemovalOptions removalOptions) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> StagePackageAsync(const Windows::Foundation::Uri & packageUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> RegisterPackageByFullNameAsync(hstring_view mainPackageFullName, iterable<hstring> dependencyPackageFullNames, Windows::Management::Deployment::DeploymentOptions deploymentOptions) const;
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> FindPackagesWithPackageTypes(Windows::Management::Deployment::PackageTypes packageTypes) const;
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> FindPackagesForUserWithPackageTypes(hstring_view userSecurityId, Windows::Management::Deployment::PackageTypes packageTypes) const;
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> FindPackagesWithPackageTypes(hstring_view packageName, hstring_view packagePublisher, Windows::Management::Deployment::PackageTypes packageTypes) const;
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> FindPackagesForUserWithPackageTypes(hstring_view userSecurityId, hstring_view packageName, hstring_view packagePublisher, Windows::Management::Deployment::PackageTypes packageTypes) const;
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> FindPackagesWithPackageTypes(hstring_view packageFamilyName, Windows::Management::Deployment::PackageTypes packageTypes) const;
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> FindPackagesForUserWithPackageTypes(hstring_view userSecurityId, hstring_view packageFamilyName, Windows::Management::Deployment::PackageTypes packageTypes) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> StageUserDataAsync(hstring_view packageFullName) const;
};

template <typename D>
struct WINRT_EBO impl_IPackageManager3
{
    Windows::Foundation::IAsyncOperation<Windows::Management::Deployment::PackageVolume> AddPackageVolumeAsync(hstring_view packageStorePath) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> AddPackageAsync(const Windows::Foundation::Uri & packageUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions, const Windows::Management::Deployment::PackageVolume & targetVolume) const;
    void ClearPackageStatus(hstring_view packageFullName, Windows::Management::Deployment::PackageStatus status) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> RegisterPackageAsync(const Windows::Foundation::Uri & manifestUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions, const Windows::Management::Deployment::PackageVolume & appDataVolume) const;
    Windows::Management::Deployment::PackageVolume FindPackageVolume(hstring_view volumeName) const;
    Windows::Foundation::Collections::IIterable<Windows::Management::Deployment::PackageVolume> FindPackageVolumes() const;
    Windows::Management::Deployment::PackageVolume GetDefaultPackageVolume() const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> MovePackageToVolumeAsync(hstring_view packageFullName, Windows::Management::Deployment::DeploymentOptions deploymentOptions, const Windows::Management::Deployment::PackageVolume & targetVolume) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> RemovePackageVolumeAsync(const Windows::Management::Deployment::PackageVolume & volume) const;
    void SetDefaultPackageVolume(const Windows::Management::Deployment::PackageVolume & volume) const;
    void SetPackageStatus(hstring_view packageFullName, Windows::Management::Deployment::PackageStatus status) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> SetPackageVolumeOfflineAsync(const Windows::Management::Deployment::PackageVolume & packageVolume) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> SetPackageVolumeOnlineAsync(const Windows::Management::Deployment::PackageVolume & packageVolume) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> StagePackageAsync(const Windows::Foundation::Uri & packageUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions, const Windows::Management::Deployment::PackageVolume & targetVolume) const;
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> StageUserDataAsync(hstring_view packageFullName, Windows::Management::Deployment::DeploymentOptions deploymentOptions) const;
};

template <typename D>
struct WINRT_EBO impl_IPackageManager4
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Management::Deployment::PackageVolume>> GetPackageVolumesAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IPackageUserInformation
{
    hstring UserSecurityId() const;
    Windows::Management::Deployment::PackageInstallState InstallState() const;
};

template <typename D>
struct WINRT_EBO impl_IPackageVolume
{
    bool IsOffline() const;
    bool IsSystemVolume() const;
    hstring MountPoint() const;
    hstring Name() const;
    hstring PackageStorePath() const;
    bool SupportsHardLinks() const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> FindPackages() const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> FindPackages(hstring_view packageName, hstring_view packagePublisher) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> FindPackages(hstring_view packageFamilyName) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> FindPackagesWithPackageTypes(Windows::Management::Deployment::PackageTypes packageTypes) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> FindPackagesWithPackageTypes(Windows::Management::Deployment::PackageTypes packageTypes, hstring_view packageName, hstring_view packagePublisher) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> FindPackagesWithPackageTypes(Windows::Management::Deployment::PackageTypes packageTypes, hstring_view packageFamilyName) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> FindPackage(hstring_view packageFullName) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> FindPackagesForUser(hstring_view userSecurityId) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> FindPackagesForUser(hstring_view userSecurityId, hstring_view packageName, hstring_view packagePublisher) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> FindPackagesForUser(hstring_view userSecurityId, hstring_view packageFamilyName) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> FindPackagesForUserWithPackageTypes(hstring_view userSecurityId, Windows::Management::Deployment::PackageTypes packageTypes) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> FindPackagesForUserWithPackageTypes(hstring_view userSecurityId, Windows::Management::Deployment::PackageTypes packageTypes, hstring_view packageName, hstring_view packagePublisher) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> FindPackagesForUserWithPackageTypes(hstring_view userSecurityId, Windows::Management::Deployment::PackageTypes packageTypes, hstring_view packageFamilyName) const;
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> FindPackageForUser(hstring_view userSecurityId, hstring_view packageFullName) const;
};

template <typename D>
struct WINRT_EBO impl_IPackageVolume2
{
    bool IsFullTrustPackageSupported() const;
    bool IsAppxInstallSupported() const;
    Windows::Foundation::IAsyncOperation<uint64_t> GetAvailableSpaceAsync() const;
};

}

namespace impl {

template <> struct traits<Windows::Management::Deployment::IDeploymentResult>
{
    using abi = ABI::Windows::Management::Deployment::IDeploymentResult;
    template <typename D> using consume = Windows::Management::Deployment::impl_IDeploymentResult<D>;
};

template <> struct traits<Windows::Management::Deployment::IPackageManager>
{
    using abi = ABI::Windows::Management::Deployment::IPackageManager;
    template <typename D> using consume = Windows::Management::Deployment::impl_IPackageManager<D>;
};

template <> struct traits<Windows::Management::Deployment::IPackageManager2>
{
    using abi = ABI::Windows::Management::Deployment::IPackageManager2;
    template <typename D> using consume = Windows::Management::Deployment::impl_IPackageManager2<D>;
};

template <> struct traits<Windows::Management::Deployment::IPackageManager3>
{
    using abi = ABI::Windows::Management::Deployment::IPackageManager3;
    template <typename D> using consume = Windows::Management::Deployment::impl_IPackageManager3<D>;
};

template <> struct traits<Windows::Management::Deployment::IPackageManager4>
{
    using abi = ABI::Windows::Management::Deployment::IPackageManager4;
    template <typename D> using consume = Windows::Management::Deployment::impl_IPackageManager4<D>;
};

template <> struct traits<Windows::Management::Deployment::IPackageUserInformation>
{
    using abi = ABI::Windows::Management::Deployment::IPackageUserInformation;
    template <typename D> using consume = Windows::Management::Deployment::impl_IPackageUserInformation<D>;
};

template <> struct traits<Windows::Management::Deployment::IPackageVolume>
{
    using abi = ABI::Windows::Management::Deployment::IPackageVolume;
    template <typename D> using consume = Windows::Management::Deployment::impl_IPackageVolume<D>;
};

template <> struct traits<Windows::Management::Deployment::IPackageVolume2>
{
    using abi = ABI::Windows::Management::Deployment::IPackageVolume2;
    template <typename D> using consume = Windows::Management::Deployment::impl_IPackageVolume2<D>;
};

template <> struct traits<Windows::Management::Deployment::DeploymentResult>
{
    using abi = ABI::Windows::Management::Deployment::DeploymentResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Management.Deployment.DeploymentResult"; }
};

template <> struct traits<Windows::Management::Deployment::PackageManager>
{
    using abi = ABI::Windows::Management::Deployment::PackageManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Management.Deployment.PackageManager"; }
};

template <> struct traits<Windows::Management::Deployment::PackageUserInformation>
{
    using abi = ABI::Windows::Management::Deployment::PackageUserInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Management.Deployment.PackageUserInformation"; }
};

template <> struct traits<Windows::Management::Deployment::PackageVolume>
{
    using abi = ABI::Windows::Management::Deployment::PackageVolume;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Management.Deployment.PackageVolume"; }
};

}

}
