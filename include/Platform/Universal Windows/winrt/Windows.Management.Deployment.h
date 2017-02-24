// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.ApplicationModel.3.h"
#include "internal/Windows.Management.Deployment.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Management::Deployment::IDeploymentResult> : produce_base<D, Windows::Management::Deployment::IDeploymentResult>
{
    HRESULT __stdcall get_ErrorText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ErrorText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActivityId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActivityId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedErrorCode(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedErrorCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Management::Deployment::IPackageManager> : produce_base<D, Windows::Management::Deployment::IPackageManager>
{
    HRESULT __stdcall abi_AddPackageAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> packageUri, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri>> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().AddPackageAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&packageUri), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> *>(&dependencyPackageUris), deploymentOptions));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdatePackageAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> packageUri, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri>> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().UpdatePackageAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&packageUri), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> *>(&dependencyPackageUris), deploymentOptions));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemovePackageAsync(impl::abi_arg_in<hstring> packageFullName, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().RemovePackageAsync(*reinterpret_cast<const hstring *>(&packageFullName)));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StagePackageAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> packageUri, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri>> dependencyPackageUris, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().StagePackageAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&packageUri), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> *>(&dependencyPackageUris)));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterPackageAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> manifestUri, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri>> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().RegisterPackageAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&manifestUri), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> *>(&dependencyPackageUris), deploymentOptions));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackages(impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackages());
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByUserSecurityId(impl::abi_arg_in<hstring> userSecurityId, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesForUser(*reinterpret_cast<const hstring *>(&userSecurityId)));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByNamePublisher(impl::abi_arg_in<hstring> packageName, impl::abi_arg_in<hstring> packagePublisher, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackages(*reinterpret_cast<const hstring *>(&packageName), *reinterpret_cast<const hstring *>(&packagePublisher)));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByUserSecurityIdNamePublisher(impl::abi_arg_in<hstring> userSecurityId, impl::abi_arg_in<hstring> packageName, impl::abi_arg_in<hstring> packagePublisher, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesForUser(*reinterpret_cast<const hstring *>(&userSecurityId), *reinterpret_cast<const hstring *>(&packageName), *reinterpret_cast<const hstring *>(&packagePublisher)));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindUsers(impl::abi_arg_in<hstring> packageFullName, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::Management::Deployment::PackageUserInformation>> users) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *users = detach_abi(this->shim().FindUsers(*reinterpret_cast<const hstring *>(&packageFullName)));
            return S_OK;
        }
        catch (...)
        {
            *users = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPackageState(impl::abi_arg_in<hstring> packageFullName, Windows::Management::Deployment::PackageState packageState) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPackageState(*reinterpret_cast<const hstring *>(&packageFullName), packageState);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackageByPackageFullName(impl::abi_arg_in<hstring> packageFullName, impl::abi_arg_out<Windows::ApplicationModel::IPackage> packageInformation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageInformation = detach_abi(this->shim().FindPackage(*reinterpret_cast<const hstring *>(&packageFullName)));
            return S_OK;
        }
        catch (...)
        {
            *packageInformation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CleanupPackageForUserAsync(impl::abi_arg_in<hstring> packageName, impl::abi_arg_in<hstring> userSecurityId, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().CleanupPackageForUserAsync(*reinterpret_cast<const hstring *>(&packageName), *reinterpret_cast<const hstring *>(&userSecurityId)));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByPackageFamilyName(impl::abi_arg_in<hstring> packageFamilyName, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackages(*reinterpret_cast<const hstring *>(&packageFamilyName)));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByUserSecurityIdPackageFamilyName(impl::abi_arg_in<hstring> userSecurityId, impl::abi_arg_in<hstring> packageFamilyName, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesForUser(*reinterpret_cast<const hstring *>(&userSecurityId), *reinterpret_cast<const hstring *>(&packageFamilyName)));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackageByUserSecurityIdPackageFullName(impl::abi_arg_in<hstring> userSecurityId, impl::abi_arg_in<hstring> packageFullName, impl::abi_arg_out<Windows::ApplicationModel::IPackage> packageInformation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageInformation = detach_abi(this->shim().FindPackageForUser(*reinterpret_cast<const hstring *>(&userSecurityId), *reinterpret_cast<const hstring *>(&packageFullName)));
            return S_OK;
        }
        catch (...)
        {
            *packageInformation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Management::Deployment::IPackageManager2> : produce_base<D, Windows::Management::Deployment::IPackageManager2>
{
    HRESULT __stdcall abi_RemovePackageWithOptionsAsync(impl::abi_arg_in<hstring> packageFullName, Windows::Management::Deployment::RemovalOptions removalOptions, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().RemovePackageAsync(*reinterpret_cast<const hstring *>(&packageFullName), removalOptions));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StagePackageWithOptionsAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> packageUri, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri>> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().StagePackageAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&packageUri), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> *>(&dependencyPackageUris), deploymentOptions));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterPackageByFullNameAsync(impl::abi_arg_in<hstring> mainPackageFullName, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> dependencyPackageFullNames, Windows::Management::Deployment::DeploymentOptions deploymentOptions, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().RegisterPackageByFullNameAsync(*reinterpret_cast<const hstring *>(&mainPackageFullName), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&dependencyPackageFullNames), deploymentOptions));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesWithPackageTypes(Windows::Management::Deployment::PackageTypes packageTypes, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesWithPackageTypes(packageTypes));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByUserSecurityIdWithPackageTypes(impl::abi_arg_in<hstring> userSecurityId, Windows::Management::Deployment::PackageTypes packageTypes, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesForUserWithPackageTypes(*reinterpret_cast<const hstring *>(&userSecurityId), packageTypes));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByNamePublisherWithPackageTypes(impl::abi_arg_in<hstring> packageName, impl::abi_arg_in<hstring> packagePublisher, Windows::Management::Deployment::PackageTypes packageTypes, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesWithPackageTypes(*reinterpret_cast<const hstring *>(&packageName), *reinterpret_cast<const hstring *>(&packagePublisher), packageTypes));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByUserSecurityIdNamePublisherWithPackageTypes(impl::abi_arg_in<hstring> userSecurityId, impl::abi_arg_in<hstring> packageName, impl::abi_arg_in<hstring> packagePublisher, Windows::Management::Deployment::PackageTypes packageTypes, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesForUserWithPackageTypes(*reinterpret_cast<const hstring *>(&userSecurityId), *reinterpret_cast<const hstring *>(&packageName), *reinterpret_cast<const hstring *>(&packagePublisher), packageTypes));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByPackageFamilyNameWithPackageTypes(impl::abi_arg_in<hstring> packageFamilyName, Windows::Management::Deployment::PackageTypes packageTypes, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesWithPackageTypes(*reinterpret_cast<const hstring *>(&packageFamilyName), packageTypes));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByUserSecurityIdPackageFamilyNameWithPackageTypes(impl::abi_arg_in<hstring> userSecurityId, impl::abi_arg_in<hstring> packageFamilyName, Windows::Management::Deployment::PackageTypes packageTypes, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesForUserWithPackageTypes(*reinterpret_cast<const hstring *>(&userSecurityId), *reinterpret_cast<const hstring *>(&packageFamilyName), packageTypes));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StageUserDataAsync(impl::abi_arg_in<hstring> packageFullName, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().StageUserDataAsync(*reinterpret_cast<const hstring *>(&packageFullName)));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Management::Deployment::IPackageManager3> : produce_base<D, Windows::Management::Deployment::IPackageManager3>
{
    HRESULT __stdcall abi_AddPackageVolumeAsync(impl::abi_arg_in<hstring> packageStorePath, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Management::Deployment::PackageVolume>> packageVolume) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageVolume = detach_abi(this->shim().AddPackageVolumeAsync(*reinterpret_cast<const hstring *>(&packageStorePath)));
            return S_OK;
        }
        catch (...)
        {
            *packageVolume = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddPackageToVolumeAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> packageUri, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri>> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions, impl::abi_arg_in<Windows::Management::Deployment::IPackageVolume> targetVolume, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().AddPackageAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&packageUri), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> *>(&dependencyPackageUris), deploymentOptions, *reinterpret_cast<const Windows::Management::Deployment::PackageVolume *>(&targetVolume)));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ClearPackageStatus(impl::abi_arg_in<hstring> packageFullName, Windows::Management::Deployment::PackageStatus status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearPackageStatus(*reinterpret_cast<const hstring *>(&packageFullName), status);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterPackageWithAppDataVolumeAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> manifestUri, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri>> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions, impl::abi_arg_in<Windows::Management::Deployment::IPackageVolume> appDataVolume, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().RegisterPackageAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&manifestUri), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> *>(&dependencyPackageUris), deploymentOptions, *reinterpret_cast<const Windows::Management::Deployment::PackageVolume *>(&appDataVolume)));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackageVolumeByName(impl::abi_arg_in<hstring> volumeName, impl::abi_arg_out<Windows::Management::Deployment::IPackageVolume> volume) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *volume = detach_abi(this->shim().FindPackageVolume(*reinterpret_cast<const hstring *>(&volumeName)));
            return S_OK;
        }
        catch (...)
        {
            *volume = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackageVolumes(impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::Management::Deployment::PackageVolume>> volumeCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *volumeCollection = detach_abi(this->shim().FindPackageVolumes());
            return S_OK;
        }
        catch (...)
        {
            *volumeCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDefaultPackageVolume(impl::abi_arg_out<Windows::Management::Deployment::IPackageVolume> volume) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *volume = detach_abi(this->shim().GetDefaultPackageVolume());
            return S_OK;
        }
        catch (...)
        {
            *volume = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MovePackageToVolumeAsync(impl::abi_arg_in<hstring> packageFullName, Windows::Management::Deployment::DeploymentOptions deploymentOptions, impl::abi_arg_in<Windows::Management::Deployment::IPackageVolume> targetVolume, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().MovePackageToVolumeAsync(*reinterpret_cast<const hstring *>(&packageFullName), deploymentOptions, *reinterpret_cast<const Windows::Management::Deployment::PackageVolume *>(&targetVolume)));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemovePackageVolumeAsync(impl::abi_arg_in<Windows::Management::Deployment::IPackageVolume> volume, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().RemovePackageVolumeAsync(*reinterpret_cast<const Windows::Management::Deployment::PackageVolume *>(&volume)));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetDefaultPackageVolume(impl::abi_arg_in<Windows::Management::Deployment::IPackageVolume> volume) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDefaultPackageVolume(*reinterpret_cast<const Windows::Management::Deployment::PackageVolume *>(&volume));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPackageStatus(impl::abi_arg_in<hstring> packageFullName, Windows::Management::Deployment::PackageStatus status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPackageStatus(*reinterpret_cast<const hstring *>(&packageFullName), status);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPackageVolumeOfflineAsync(impl::abi_arg_in<Windows::Management::Deployment::IPackageVolume> packageVolume, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().SetPackageVolumeOfflineAsync(*reinterpret_cast<const Windows::Management::Deployment::PackageVolume *>(&packageVolume)));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPackageVolumeOnlineAsync(impl::abi_arg_in<Windows::Management::Deployment::IPackageVolume> packageVolume, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().SetPackageVolumeOnlineAsync(*reinterpret_cast<const Windows::Management::Deployment::PackageVolume *>(&packageVolume)));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StagePackageToVolumeAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> packageUri, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri>> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions, impl::abi_arg_in<Windows::Management::Deployment::IPackageVolume> targetVolume, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().StagePackageAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&packageUri), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> *>(&dependencyPackageUris), deploymentOptions, *reinterpret_cast<const Windows::Management::Deployment::PackageVolume *>(&targetVolume)));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StageUserDataWithOptionsAsync(impl::abi_arg_in<hstring> packageFullName, Windows::Management::Deployment::DeploymentOptions deploymentOptions, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress>> deploymentOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deploymentOperation = detach_abi(this->shim().StageUserDataAsync(*reinterpret_cast<const hstring *>(&packageFullName), deploymentOptions));
            return S_OK;
        }
        catch (...)
        {
            *deploymentOperation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Management::Deployment::IPackageManager4> : produce_base<D, Windows::Management::Deployment::IPackageManager4>
{
    HRESULT __stdcall abi_GetPackageVolumesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Management::Deployment::PackageVolume>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetPackageVolumesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Management::Deployment::IPackageUserInformation> : produce_base<D, Windows::Management::Deployment::IPackageUserInformation>
{
    HRESULT __stdcall get_UserSecurityId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserSecurityId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InstallState(Windows::Management::Deployment::PackageInstallState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InstallState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Management::Deployment::IPackageVolume> : produce_base<D, Windows::Management::Deployment::IPackageVolume>
{
    HRESULT __stdcall get_IsOffline(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOffline());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSystemVolume(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSystemVolume());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MountPoint(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MountPoint());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PackageStorePath(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PackageStorePath());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportsHardLinks(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportsHardLinks());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackages(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackages());
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByNamePublisher(impl::abi_arg_in<hstring> packageName, impl::abi_arg_in<hstring> packagePublisher, impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackages(*reinterpret_cast<const hstring *>(&packageName), *reinterpret_cast<const hstring *>(&packagePublisher)));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByPackageFamilyName(impl::abi_arg_in<hstring> packageFamilyName, impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackages(*reinterpret_cast<const hstring *>(&packageFamilyName)));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesWithPackageTypes(Windows::Management::Deployment::PackageTypes packageTypes, impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesWithPackageTypes(packageTypes));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByNamePublisherWithPackagesTypes(Windows::Management::Deployment::PackageTypes packageTypes, impl::abi_arg_in<hstring> packageName, impl::abi_arg_in<hstring> packagePublisher, impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesWithPackageTypes(packageTypes, *reinterpret_cast<const hstring *>(&packageName), *reinterpret_cast<const hstring *>(&packagePublisher)));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByPackageFamilyNameWithPackageTypes(Windows::Management::Deployment::PackageTypes packageTypes, impl::abi_arg_in<hstring> packageFamilyName, impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesWithPackageTypes(packageTypes, *reinterpret_cast<const hstring *>(&packageFamilyName)));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackageByPackageFullName(impl::abi_arg_in<hstring> packageFullName, impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackage(*reinterpret_cast<const hstring *>(&packageFullName)));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByUserSecurityId(impl::abi_arg_in<hstring> userSecurityId, impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesForUser(*reinterpret_cast<const hstring *>(&userSecurityId)));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByUserSecurityIdNamePublisher(impl::abi_arg_in<hstring> userSecurityId, impl::abi_arg_in<hstring> packageName, impl::abi_arg_in<hstring> packagePublisher, impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesForUser(*reinterpret_cast<const hstring *>(&userSecurityId), *reinterpret_cast<const hstring *>(&packageName), *reinterpret_cast<const hstring *>(&packagePublisher)));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByUserSecurityIdPackageFamilyName(impl::abi_arg_in<hstring> userSecurityId, impl::abi_arg_in<hstring> packageFamilyName, impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesForUser(*reinterpret_cast<const hstring *>(&userSecurityId), *reinterpret_cast<const hstring *>(&packageFamilyName)));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByUserSecurityIdWithPackageTypes(impl::abi_arg_in<hstring> userSecurityId, Windows::Management::Deployment::PackageTypes packageTypes, impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesForUserWithPackageTypes(*reinterpret_cast<const hstring *>(&userSecurityId), packageTypes));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByUserSecurityIdNamePublisherWithPackageTypes(impl::abi_arg_in<hstring> userSecurityId, Windows::Management::Deployment::PackageTypes packageTypes, impl::abi_arg_in<hstring> packageName, impl::abi_arg_in<hstring> packagePublisher, impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesForUserWithPackageTypes(*reinterpret_cast<const hstring *>(&userSecurityId), packageTypes, *reinterpret_cast<const hstring *>(&packageName), *reinterpret_cast<const hstring *>(&packagePublisher)));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByUserSecurityIdPackageFamilyNameWithPackagesTypes(impl::abi_arg_in<hstring> userSecurityId, Windows::Management::Deployment::PackageTypes packageTypes, impl::abi_arg_in<hstring> packageFamilyName, impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackagesForUserWithPackageTypes(*reinterpret_cast<const hstring *>(&userSecurityId), packageTypes, *reinterpret_cast<const hstring *>(&packageFamilyName)));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackageByUserSecurityIdPackageFullName(impl::abi_arg_in<hstring> userSecurityId, impl::abi_arg_in<hstring> packageFullName, impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package>> packageCollection) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *packageCollection = detach_abi(this->shim().FindPackageForUser(*reinterpret_cast<const hstring *>(&userSecurityId), *reinterpret_cast<const hstring *>(&packageFullName)));
            return S_OK;
        }
        catch (...)
        {
            *packageCollection = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Management::Deployment::IPackageVolume2> : produce_base<D, Windows::Management::Deployment::IPackageVolume2>
{
    HRESULT __stdcall get_IsFullTrustPackageSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsFullTrustPackageSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsAppxInstallSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAppxInstallSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAvailableSpaceAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<uint64_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetAvailableSpaceAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Management::Deployment {

template <typename D> hstring impl_IDeploymentResult<D>::ErrorText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeploymentResult)->get_ErrorText(put_abi(value)));
    return value;
}

template <typename D> GUID impl_IDeploymentResult<D>::ActivityId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IDeploymentResult)->get_ActivityId(&value));
    return value;
}

template <typename D> HRESULT impl_IDeploymentResult<D>::ExtendedErrorCode() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(IDeploymentResult)->get_ExtendedErrorCode(&value));
    return value;
}

template <typename D> hstring impl_IPackageUserInformation<D>::UserSecurityId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPackageUserInformation)->get_UserSecurityId(put_abi(value)));
    return value;
}

template <typename D> Windows::Management::Deployment::PackageInstallState impl_IPackageUserInformation<D>::InstallState() const
{
    Windows::Management::Deployment::PackageInstallState value {};
    check_hresult(WINRT_SHIM(IPackageUserInformation)->get_InstallState(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager<D>::AddPackageAsync(const Windows::Foundation::Uri & packageUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager)->abi_AddPackageAsync(get_abi(packageUri), get_abi(dependencyPackageUris), deploymentOptions, put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager<D>::UpdatePackageAsync(const Windows::Foundation::Uri & packageUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager)->abi_UpdatePackageAsync(get_abi(packageUri), get_abi(dependencyPackageUris), deploymentOptions, put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager<D>::RemovePackageAsync(hstring_view packageFullName) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager)->abi_RemovePackageAsync(get_abi(packageFullName), put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager<D>::StagePackageAsync(const Windows::Foundation::Uri & packageUri, iterable<Windows::Foundation::Uri> dependencyPackageUris) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager)->abi_StagePackageAsync(get_abi(packageUri), get_abi(dependencyPackageUris), put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager<D>::RegisterPackageAsync(const Windows::Foundation::Uri & manifestUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager)->abi_RegisterPackageAsync(get_abi(manifestUri), get_abi(dependencyPackageUris), deploymentOptions, put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> impl_IPackageManager<D>::FindPackages() const
{
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageManager)->abi_FindPackages(put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> impl_IPackageManager<D>::FindPackagesForUser(hstring_view userSecurityId) const
{
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageManager)->abi_FindPackagesByUserSecurityId(get_abi(userSecurityId), put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> impl_IPackageManager<D>::FindPackages(hstring_view packageName, hstring_view packagePublisher) const
{
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageManager)->abi_FindPackagesByNamePublisher(get_abi(packageName), get_abi(packagePublisher), put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> impl_IPackageManager<D>::FindPackagesForUser(hstring_view userSecurityId, hstring_view packageName, hstring_view packagePublisher) const
{
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageManager)->abi_FindPackagesByUserSecurityIdNamePublisher(get_abi(userSecurityId), get_abi(packageName), get_abi(packagePublisher), put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::Management::Deployment::PackageUserInformation> impl_IPackageManager<D>::FindUsers(hstring_view packageFullName) const
{
    Windows::Foundation::Collections::IIterable<Windows::Management::Deployment::PackageUserInformation> users;
    check_hresult(WINRT_SHIM(IPackageManager)->abi_FindUsers(get_abi(packageFullName), put_abi(users)));
    return users;
}

template <typename D> void impl_IPackageManager<D>::SetPackageState(hstring_view packageFullName, Windows::Management::Deployment::PackageState packageState) const
{
    check_hresult(WINRT_SHIM(IPackageManager)->abi_SetPackageState(get_abi(packageFullName), packageState));
}

template <typename D> Windows::ApplicationModel::Package impl_IPackageManager<D>::FindPackage(hstring_view packageFullName) const
{
    Windows::ApplicationModel::Package packageInformation { nullptr };
    check_hresult(WINRT_SHIM(IPackageManager)->abi_FindPackageByPackageFullName(get_abi(packageFullName), put_abi(packageInformation)));
    return packageInformation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager<D>::CleanupPackageForUserAsync(hstring_view packageName, hstring_view userSecurityId) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager)->abi_CleanupPackageForUserAsync(get_abi(packageName), get_abi(userSecurityId), put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> impl_IPackageManager<D>::FindPackages(hstring_view packageFamilyName) const
{
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageManager)->abi_FindPackagesByPackageFamilyName(get_abi(packageFamilyName), put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> impl_IPackageManager<D>::FindPackagesForUser(hstring_view userSecurityId, hstring_view packageFamilyName) const
{
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageManager)->abi_FindPackagesByUserSecurityIdPackageFamilyName(get_abi(userSecurityId), get_abi(packageFamilyName), put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::ApplicationModel::Package impl_IPackageManager<D>::FindPackageForUser(hstring_view userSecurityId, hstring_view packageFullName) const
{
    Windows::ApplicationModel::Package packageInformation { nullptr };
    check_hresult(WINRT_SHIM(IPackageManager)->abi_FindPackageByUserSecurityIdPackageFullName(get_abi(userSecurityId), get_abi(packageFullName), put_abi(packageInformation)));
    return packageInformation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager2<D>::RemovePackageAsync(hstring_view packageFullName, Windows::Management::Deployment::RemovalOptions removalOptions) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager2)->abi_RemovePackageWithOptionsAsync(get_abi(packageFullName), removalOptions, put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager2<D>::StagePackageAsync(const Windows::Foundation::Uri & packageUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager2)->abi_StagePackageWithOptionsAsync(get_abi(packageUri), get_abi(dependencyPackageUris), deploymentOptions, put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager2<D>::RegisterPackageByFullNameAsync(hstring_view mainPackageFullName, iterable<hstring> dependencyPackageFullNames, Windows::Management::Deployment::DeploymentOptions deploymentOptions) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager2)->abi_RegisterPackageByFullNameAsync(get_abi(mainPackageFullName), get_abi(dependencyPackageFullNames), deploymentOptions, put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> impl_IPackageManager2<D>::FindPackagesWithPackageTypes(Windows::Management::Deployment::PackageTypes packageTypes) const
{
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageManager2)->abi_FindPackagesWithPackageTypes(packageTypes, put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> impl_IPackageManager2<D>::FindPackagesForUserWithPackageTypes(hstring_view userSecurityId, Windows::Management::Deployment::PackageTypes packageTypes) const
{
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageManager2)->abi_FindPackagesByUserSecurityIdWithPackageTypes(get_abi(userSecurityId), packageTypes, put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> impl_IPackageManager2<D>::FindPackagesWithPackageTypes(hstring_view packageName, hstring_view packagePublisher, Windows::Management::Deployment::PackageTypes packageTypes) const
{
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageManager2)->abi_FindPackagesByNamePublisherWithPackageTypes(get_abi(packageName), get_abi(packagePublisher), packageTypes, put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> impl_IPackageManager2<D>::FindPackagesForUserWithPackageTypes(hstring_view userSecurityId, hstring_view packageName, hstring_view packagePublisher, Windows::Management::Deployment::PackageTypes packageTypes) const
{
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageManager2)->abi_FindPackagesByUserSecurityIdNamePublisherWithPackageTypes(get_abi(userSecurityId), get_abi(packageName), get_abi(packagePublisher), packageTypes, put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> impl_IPackageManager2<D>::FindPackagesWithPackageTypes(hstring_view packageFamilyName, Windows::Management::Deployment::PackageTypes packageTypes) const
{
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageManager2)->abi_FindPackagesByPackageFamilyNameWithPackageTypes(get_abi(packageFamilyName), packageTypes, put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> impl_IPackageManager2<D>::FindPackagesForUserWithPackageTypes(hstring_view userSecurityId, hstring_view packageFamilyName, Windows::Management::Deployment::PackageTypes packageTypes) const
{
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageManager2)->abi_FindPackagesByUserSecurityIdPackageFamilyNameWithPackageTypes(get_abi(userSecurityId), get_abi(packageFamilyName), packageTypes, put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager2<D>::StageUserDataAsync(hstring_view packageFullName) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager2)->abi_StageUserDataAsync(get_abi(packageFullName), put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Management::Deployment::PackageVolume> impl_IPackageManager3<D>::AddPackageVolumeAsync(hstring_view packageStorePath) const
{
    Windows::Foundation::IAsyncOperation<Windows::Management::Deployment::PackageVolume> packageVolume;
    check_hresult(WINRT_SHIM(IPackageManager3)->abi_AddPackageVolumeAsync(get_abi(packageStorePath), put_abi(packageVolume)));
    return packageVolume;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager3<D>::AddPackageAsync(const Windows::Foundation::Uri & packageUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions, const Windows::Management::Deployment::PackageVolume & targetVolume) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager3)->abi_AddPackageToVolumeAsync(get_abi(packageUri), get_abi(dependencyPackageUris), deploymentOptions, get_abi(targetVolume), put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> void impl_IPackageManager3<D>::ClearPackageStatus(hstring_view packageFullName, Windows::Management::Deployment::PackageStatus status) const
{
    check_hresult(WINRT_SHIM(IPackageManager3)->abi_ClearPackageStatus(get_abi(packageFullName), status));
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager3<D>::RegisterPackageAsync(const Windows::Foundation::Uri & manifestUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions, const Windows::Management::Deployment::PackageVolume & appDataVolume) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager3)->abi_RegisterPackageWithAppDataVolumeAsync(get_abi(manifestUri), get_abi(dependencyPackageUris), deploymentOptions, get_abi(appDataVolume), put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> Windows::Management::Deployment::PackageVolume impl_IPackageManager3<D>::FindPackageVolume(hstring_view volumeName) const
{
    Windows::Management::Deployment::PackageVolume volume { nullptr };
    check_hresult(WINRT_SHIM(IPackageManager3)->abi_FindPackageVolumeByName(get_abi(volumeName), put_abi(volume)));
    return volume;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::Management::Deployment::PackageVolume> impl_IPackageManager3<D>::FindPackageVolumes() const
{
    Windows::Foundation::Collections::IIterable<Windows::Management::Deployment::PackageVolume> volumeCollection;
    check_hresult(WINRT_SHIM(IPackageManager3)->abi_FindPackageVolumes(put_abi(volumeCollection)));
    return volumeCollection;
}

template <typename D> Windows::Management::Deployment::PackageVolume impl_IPackageManager3<D>::GetDefaultPackageVolume() const
{
    Windows::Management::Deployment::PackageVolume volume { nullptr };
    check_hresult(WINRT_SHIM(IPackageManager3)->abi_GetDefaultPackageVolume(put_abi(volume)));
    return volume;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager3<D>::MovePackageToVolumeAsync(hstring_view packageFullName, Windows::Management::Deployment::DeploymentOptions deploymentOptions, const Windows::Management::Deployment::PackageVolume & targetVolume) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager3)->abi_MovePackageToVolumeAsync(get_abi(packageFullName), deploymentOptions, get_abi(targetVolume), put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager3<D>::RemovePackageVolumeAsync(const Windows::Management::Deployment::PackageVolume & volume) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager3)->abi_RemovePackageVolumeAsync(get_abi(volume), put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> void impl_IPackageManager3<D>::SetDefaultPackageVolume(const Windows::Management::Deployment::PackageVolume & volume) const
{
    check_hresult(WINRT_SHIM(IPackageManager3)->abi_SetDefaultPackageVolume(get_abi(volume)));
}

template <typename D> void impl_IPackageManager3<D>::SetPackageStatus(hstring_view packageFullName, Windows::Management::Deployment::PackageStatus status) const
{
    check_hresult(WINRT_SHIM(IPackageManager3)->abi_SetPackageStatus(get_abi(packageFullName), status));
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager3<D>::SetPackageVolumeOfflineAsync(const Windows::Management::Deployment::PackageVolume & packageVolume) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager3)->abi_SetPackageVolumeOfflineAsync(get_abi(packageVolume), put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager3<D>::SetPackageVolumeOnlineAsync(const Windows::Management::Deployment::PackageVolume & packageVolume) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager3)->abi_SetPackageVolumeOnlineAsync(get_abi(packageVolume), put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager3<D>::StagePackageAsync(const Windows::Foundation::Uri & packageUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions, const Windows::Management::Deployment::PackageVolume & targetVolume) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager3)->abi_StagePackageToVolumeAsync(get_abi(packageUri), get_abi(dependencyPackageUris), deploymentOptions, get_abi(targetVolume), put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> impl_IPackageManager3<D>::StageUserDataAsync(hstring_view packageFullName, Windows::Management::Deployment::DeploymentOptions deploymentOptions) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Management::Deployment::DeploymentResult, Windows::Management::Deployment::DeploymentProgress> deploymentOperation;
    check_hresult(WINRT_SHIM(IPackageManager3)->abi_StageUserDataWithOptionsAsync(get_abi(packageFullName), deploymentOptions, put_abi(deploymentOperation)));
    return deploymentOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Management::Deployment::PackageVolume>> impl_IPackageManager4<D>::GetPackageVolumesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Management::Deployment::PackageVolume>> operation;
    check_hresult(WINRT_SHIM(IPackageManager4)->abi_GetPackageVolumesAsync(put_abi(operation)));
    return operation;
}

template <typename D> bool impl_IPackageVolume<D>::IsOffline() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPackageVolume)->get_IsOffline(&value));
    return value;
}

template <typename D> bool impl_IPackageVolume<D>::IsSystemVolume() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPackageVolume)->get_IsSystemVolume(&value));
    return value;
}

template <typename D> hstring impl_IPackageVolume<D>::MountPoint() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPackageVolume)->get_MountPoint(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPackageVolume<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPackageVolume)->get_Name(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPackageVolume<D>::PackageStorePath() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPackageVolume)->get_PackageStorePath(put_abi(value)));
    return value;
}

template <typename D> bool impl_IPackageVolume<D>::SupportsHardLinks() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPackageVolume)->get_SupportsHardLinks(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> impl_IPackageVolume<D>::FindPackages() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageVolume)->abi_FindPackages(put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> impl_IPackageVolume<D>::FindPackages(hstring_view packageName, hstring_view packagePublisher) const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageVolume)->abi_FindPackagesByNamePublisher(get_abi(packageName), get_abi(packagePublisher), put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> impl_IPackageVolume<D>::FindPackages(hstring_view packageFamilyName) const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageVolume)->abi_FindPackagesByPackageFamilyName(get_abi(packageFamilyName), put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> impl_IPackageVolume<D>::FindPackagesWithPackageTypes(Windows::Management::Deployment::PackageTypes packageTypes) const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageVolume)->abi_FindPackagesWithPackageTypes(packageTypes, put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> impl_IPackageVolume<D>::FindPackagesWithPackageTypes(Windows::Management::Deployment::PackageTypes packageTypes, hstring_view packageName, hstring_view packagePublisher) const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageVolume)->abi_FindPackagesByNamePublisherWithPackagesTypes(packageTypes, get_abi(packageName), get_abi(packagePublisher), put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> impl_IPackageVolume<D>::FindPackagesWithPackageTypes(Windows::Management::Deployment::PackageTypes packageTypes, hstring_view packageFamilyName) const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageVolume)->abi_FindPackagesByPackageFamilyNameWithPackageTypes(packageTypes, get_abi(packageFamilyName), put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> impl_IPackageVolume<D>::FindPackage(hstring_view packageFullName) const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageVolume)->abi_FindPackageByPackageFullName(get_abi(packageFullName), put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> impl_IPackageVolume<D>::FindPackagesForUser(hstring_view userSecurityId) const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageVolume)->abi_FindPackagesByUserSecurityId(get_abi(userSecurityId), put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> impl_IPackageVolume<D>::FindPackagesForUser(hstring_view userSecurityId, hstring_view packageName, hstring_view packagePublisher) const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageVolume)->abi_FindPackagesByUserSecurityIdNamePublisher(get_abi(userSecurityId), get_abi(packageName), get_abi(packagePublisher), put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> impl_IPackageVolume<D>::FindPackagesForUser(hstring_view userSecurityId, hstring_view packageFamilyName) const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageVolume)->abi_FindPackagesByUserSecurityIdPackageFamilyName(get_abi(userSecurityId), get_abi(packageFamilyName), put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> impl_IPackageVolume<D>::FindPackagesForUserWithPackageTypes(hstring_view userSecurityId, Windows::Management::Deployment::PackageTypes packageTypes) const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageVolume)->abi_FindPackagesByUserSecurityIdWithPackageTypes(get_abi(userSecurityId), packageTypes, put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> impl_IPackageVolume<D>::FindPackagesForUserWithPackageTypes(hstring_view userSecurityId, Windows::Management::Deployment::PackageTypes packageTypes, hstring_view packageName, hstring_view packagePublisher) const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageVolume)->abi_FindPackagesByUserSecurityIdNamePublisherWithPackageTypes(get_abi(userSecurityId), packageTypes, get_abi(packageName), get_abi(packagePublisher), put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> impl_IPackageVolume<D>::FindPackagesForUserWithPackageTypes(hstring_view userSecurityId, Windows::Management::Deployment::PackageTypes packageTypes, hstring_view packageFamilyName) const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageVolume)->abi_FindPackagesByUserSecurityIdPackageFamilyNameWithPackagesTypes(get_abi(userSecurityId), packageTypes, get_abi(packageFamilyName), put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> impl_IPackageVolume<D>::FindPackageForUser(hstring_view userSecurityId, hstring_view packageFullName) const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Package> packageCollection;
    check_hresult(WINRT_SHIM(IPackageVolume)->abi_FindPackageByUserSecurityIdPackageFullName(get_abi(userSecurityId), get_abi(packageFullName), put_abi(packageCollection)));
    return packageCollection;
}

template <typename D> bool impl_IPackageVolume2<D>::IsFullTrustPackageSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPackageVolume2)->get_IsFullTrustPackageSupported(&value));
    return value;
}

template <typename D> bool impl_IPackageVolume2<D>::IsAppxInstallSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPackageVolume2)->get_IsAppxInstallSupported(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<uint64_t> impl_IPackageVolume2<D>::GetAvailableSpaceAsync() const
{
    Windows::Foundation::IAsyncOperation<uint64_t> operation;
    check_hresult(WINRT_SHIM(IPackageVolume2)->abi_GetAvailableSpaceAsync(put_abi(operation)));
    return operation;
}

inline PackageManager::PackageManager() :
    PackageManager(activate_instance<PackageManager>())
{}

}

}
#pragma warning(pop)
