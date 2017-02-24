// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Management.Deployment.3.h"
#include "internal/Windows.Phone.Management.Deployment.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Phone::Management::Deployment::IEnterprise> : produce_base<D, Windows::Phone::Management::Deployment::IEnterprise>
{
    HRESULT __stdcall get_Id(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall get_WorkplaceId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WorkplaceId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnrollmentValidFrom(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnrollmentValidFrom());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnrollmentValidTo(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnrollmentValidTo());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Phone::Management::Deployment::EnterpriseStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::Management::Deployment::IEnterpriseEnrollmentManager> : produce_base<D, Windows::Phone::Management::Deployment::IEnterpriseEnrollmentManager>
{
    HRESULT __stdcall get_EnrolledEnterprises(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Phone::Management::Deployment::Enterprise>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().EnrolledEnterprises());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentEnterprise(impl::abi_arg_out<Windows::Phone::Management::Deployment::IEnterprise> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CurrentEnterprise());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ValidateEnterprisesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ValidateEnterprisesAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestEnrollmentAsync(impl::abi_arg_in<hstring> enrollmentToken, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Phone::Management::Deployment::EnterpriseEnrollmentResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestEnrollmentAsync(*reinterpret_cast<const hstring *>(&enrollmentToken)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestUnenrollmentAsync(impl::abi_arg_in<Windows::Phone::Management::Deployment::IEnterprise> enterprise, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestUnenrollmentAsync(*reinterpret_cast<const Windows::Phone::Management::Deployment::Enterprise *>(&enterprise)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult> : produce_base<D, Windows::Phone::Management::Deployment::IEnterpriseEnrollmentResult>
{
    HRESULT __stdcall get_EnrolledEnterprise(impl::abi_arg_out<Windows::Phone::Management::Deployment::IEnterprise> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().EnrolledEnterprise());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Phone::Management::Deployment::EnterpriseEnrollmentStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::Management::Deployment::IInstallationManagerStatics> : produce_base<D, Windows::Phone::Management::Deployment::IInstallationManagerStatics>
{
    HRESULT __stdcall abi_AddPackageAsync(impl::abi_arg_in<hstring> title, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> sourceLocation, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().AddPackageAsync(*reinterpret_cast<const hstring *>(&title), *reinterpret_cast<const Windows::Foundation::Uri *>(&sourceLocation)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddPackagePreloadedAsync(impl::abi_arg_in<hstring> title, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> sourceLocation, impl::abi_arg_in<hstring> instanceId, impl::abi_arg_in<hstring> offerId, impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> license, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().AddPackageAsync(*reinterpret_cast<const hstring *>(&title), *reinterpret_cast<const Windows::Foundation::Uri *>(&sourceLocation), *reinterpret_cast<const hstring *>(&instanceId), *reinterpret_cast<const hstring *>(&offerId), *reinterpret_cast<const Windows::Foundation::Uri *>(&license)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPendingPackageInstalls(impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t>>> items) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *items = detach_abi(this->shim().GetPendingPackageInstalls());
            return S_OK;
        }
        catch (...)
        {
            *items = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesForCurrentPublisher(impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package>> items) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *items = detach_abi(this->shim().FindPackagesForCurrentPublisher());
            return S_OK;
        }
        catch (...)
        {
            *items = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackages(impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package>> items) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *items = detach_abi(this->shim().FindPackages());
            return S_OK;
        }
        catch (...)
        {
            *items = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::Management::Deployment::IInstallationManagerStatics2> : produce_base<D, Windows::Phone::Management::Deployment::IInstallationManagerStatics2>
{
    HRESULT __stdcall abi_RemovePackageAsync(impl::abi_arg_in<hstring> packageFullName, Windows::Management::Deployment::RemovalOptions removalOptions, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().RemovePackageAsync(*reinterpret_cast<const hstring *>(&packageFullName), removalOptions));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterPackageAsync(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> manifestUri, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri>> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().RegisterPackageAsync(*reinterpret_cast<const Windows::Foundation::Uri *>(&manifestUri), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Uri> *>(&dependencyPackageUris), deploymentOptions));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindPackagesByNamePublisher(impl::abi_arg_in<hstring> packageName, impl::abi_arg_in<hstring> packagePublisher, impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package>> items) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *items = detach_abi(this->shim().FindPackages(*reinterpret_cast<const hstring *>(&packageName), *reinterpret_cast<const hstring *>(&packagePublisher)));
            return S_OK;
        }
        catch (...)
        {
            *items = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::Management::Deployment::IPackageInstallResult> : produce_base<D, Windows::Phone::Management::Deployment::IPackageInstallResult>
{
    HRESULT __stdcall get_ProductId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProductId());
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
struct produce<D, Windows::Phone::Management::Deployment::IPackageInstallResult2> : produce_base<D, Windows::Phone::Management::Deployment::IPackageInstallResult2>
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
};

}

namespace Windows::Phone::Management::Deployment {

template <typename D> GUID impl_IEnterprise<D>::Id() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IEnterprise)->get_Id(&value));
    return value;
}

template <typename D> hstring impl_IEnterprise<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEnterprise)->get_Name(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IEnterprise<D>::WorkplaceId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IEnterprise)->get_WorkplaceId(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IEnterprise<D>::EnrollmentValidFrom() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IEnterprise)->get_EnrollmentValidFrom(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IEnterprise<D>::EnrollmentValidTo() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IEnterprise)->get_EnrollmentValidTo(put_abi(value)));
    return value;
}

template <typename D> Windows::Phone::Management::Deployment::EnterpriseStatus impl_IEnterprise<D>::Status() const
{
    Windows::Phone::Management::Deployment::EnterpriseStatus value {};
    check_hresult(WINRT_SHIM(IEnterprise)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Phone::Management::Deployment::Enterprise> impl_IEnterpriseEnrollmentManager<D>::EnrolledEnterprises() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Phone::Management::Deployment::Enterprise> result;
    check_hresult(WINRT_SHIM(IEnterpriseEnrollmentManager)->get_EnrolledEnterprises(put_abi(result)));
    return result;
}

template <typename D> Windows::Phone::Management::Deployment::Enterprise impl_IEnterpriseEnrollmentManager<D>::CurrentEnterprise() const
{
    Windows::Phone::Management::Deployment::Enterprise result { nullptr };
    check_hresult(WINRT_SHIM(IEnterpriseEnrollmentManager)->get_CurrentEnterprise(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IEnterpriseEnrollmentManager<D>::ValidateEnterprisesAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IEnterpriseEnrollmentManager)->abi_ValidateEnterprisesAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Phone::Management::Deployment::EnterpriseEnrollmentResult> impl_IEnterpriseEnrollmentManager<D>::RequestEnrollmentAsync(hstring_view enrollmentToken) const
{
    Windows::Foundation::IAsyncOperation<Windows::Phone::Management::Deployment::EnterpriseEnrollmentResult> result;
    check_hresult(WINRT_SHIM(IEnterpriseEnrollmentManager)->abi_RequestEnrollmentAsync(get_abi(enrollmentToken), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IEnterpriseEnrollmentManager<D>::RequestUnenrollmentAsync(const Windows::Phone::Management::Deployment::Enterprise & enterprise) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IEnterpriseEnrollmentManager)->abi_RequestUnenrollmentAsync(get_abi(enterprise), put_abi(result)));
    return result;
}

template <typename D> hstring impl_IPackageInstallResult<D>::ProductId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPackageInstallResult)->get_ProductId(put_abi(value)));
    return value;
}

template <typename D> Windows::Management::Deployment::PackageInstallState impl_IPackageInstallResult<D>::InstallState() const
{
    Windows::Management::Deployment::PackageInstallState value {};
    check_hresult(WINRT_SHIM(IPackageInstallResult)->get_InstallState(&value));
    return value;
}

template <typename D> hstring impl_IPackageInstallResult2<D>::ErrorText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPackageInstallResult2)->get_ErrorText(put_abi(value)));
    return value;
}

template <typename D> Windows::Phone::Management::Deployment::Enterprise impl_IEnterpriseEnrollmentResult<D>::EnrolledEnterprise() const
{
    Windows::Phone::Management::Deployment::Enterprise result { nullptr };
    check_hresult(WINRT_SHIM(IEnterpriseEnrollmentResult)->get_EnrolledEnterprise(put_abi(result)));
    return result;
}

template <typename D> Windows::Phone::Management::Deployment::EnterpriseEnrollmentStatus impl_IEnterpriseEnrollmentResult<D>::Status() const
{
    Windows::Phone::Management::Deployment::EnterpriseEnrollmentStatus value {};
    check_hresult(WINRT_SHIM(IEnterpriseEnrollmentResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t> impl_IInstallationManagerStatics<D>::AddPackageAsync(hstring_view title, const Windows::Foundation::Uri & sourceLocation) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t> asyncInfo;
    check_hresult(WINRT_SHIM(IInstallationManagerStatics)->abi_AddPackageAsync(get_abi(title), get_abi(sourceLocation), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t> impl_IInstallationManagerStatics<D>::AddPackageAsync(hstring_view title, const Windows::Foundation::Uri & sourceLocation, hstring_view instanceId, hstring_view offerId, const Windows::Foundation::Uri & license) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t> asyncInfo;
    check_hresult(WINRT_SHIM(IInstallationManagerStatics)->abi_AddPackagePreloadedAsync(get_abi(title), get_abi(sourceLocation), get_abi(instanceId), get_abi(offerId), get_abi(license), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t>> impl_IInstallationManagerStatics<D>::GetPendingPackageInstalls() const
{
    Windows::Foundation::Collections::IIterable<Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t>> items;
    check_hresult(WINRT_SHIM(IInstallationManagerStatics)->abi_GetPendingPackageInstalls(put_abi(items)));
    return items;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> impl_IInstallationManagerStatics<D>::FindPackagesForCurrentPublisher() const
{
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> items;
    check_hresult(WINRT_SHIM(IInstallationManagerStatics)->abi_FindPackagesForCurrentPublisher(put_abi(items)));
    return items;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> impl_IInstallationManagerStatics<D>::FindPackages() const
{
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> items;
    check_hresult(WINRT_SHIM(IInstallationManagerStatics)->abi_FindPackages(put_abi(items)));
    return items;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t> impl_IInstallationManagerStatics2<D>::RemovePackageAsync(hstring_view packageFullName, Windows::Management::Deployment::RemovalOptions removalOptions) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t> asyncInfo;
    check_hresult(WINRT_SHIM(IInstallationManagerStatics2)->abi_RemovePackageAsync(get_abi(packageFullName), removalOptions, put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t> impl_IInstallationManagerStatics2<D>::RegisterPackageAsync(const Windows::Foundation::Uri & manifestUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t> asyncInfo;
    check_hresult(WINRT_SHIM(IInstallationManagerStatics2)->abi_RegisterPackageAsync(get_abi(manifestUri), get_abi(dependencyPackageUris), deploymentOptions, put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> impl_IInstallationManagerStatics2<D>::FindPackages(hstring_view packageName, hstring_view packagePublisher) const
{
    Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> items;
    check_hresult(WINRT_SHIM(IInstallationManagerStatics2)->abi_FindPackagesByNamePublisher(get_abi(packageName), get_abi(packagePublisher), put_abi(items)));
    return items;
}

inline Windows::Foundation::Collections::IVectorView<Windows::Phone::Management::Deployment::Enterprise> EnterpriseEnrollmentManager::EnrolledEnterprises()
{
    return get_activation_factory<EnterpriseEnrollmentManager, IEnterpriseEnrollmentManager>().EnrolledEnterprises();
}

inline Windows::Phone::Management::Deployment::Enterprise EnterpriseEnrollmentManager::CurrentEnterprise()
{
    return get_activation_factory<EnterpriseEnrollmentManager, IEnterpriseEnrollmentManager>().CurrentEnterprise();
}

inline Windows::Foundation::IAsyncAction EnterpriseEnrollmentManager::ValidateEnterprisesAsync()
{
    return get_activation_factory<EnterpriseEnrollmentManager, IEnterpriseEnrollmentManager>().ValidateEnterprisesAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Phone::Management::Deployment::EnterpriseEnrollmentResult> EnterpriseEnrollmentManager::RequestEnrollmentAsync(hstring_view enrollmentToken)
{
    return get_activation_factory<EnterpriseEnrollmentManager, IEnterpriseEnrollmentManager>().RequestEnrollmentAsync(enrollmentToken);
}

inline Windows::Foundation::IAsyncOperation<bool> EnterpriseEnrollmentManager::RequestUnenrollmentAsync(const Windows::Phone::Management::Deployment::Enterprise & enterprise)
{
    return get_activation_factory<EnterpriseEnrollmentManager, IEnterpriseEnrollmentManager>().RequestUnenrollmentAsync(enterprise);
}

inline Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t> InstallationManager::AddPackageAsync(hstring_view title, const Windows::Foundation::Uri & sourceLocation)
{
    return get_activation_factory<InstallationManager, IInstallationManagerStatics>().AddPackageAsync(title, sourceLocation);
}

inline Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t> InstallationManager::AddPackageAsync(hstring_view title, const Windows::Foundation::Uri & sourceLocation, hstring_view instanceId, hstring_view offerId, const Windows::Foundation::Uri & license)
{
    return get_activation_factory<InstallationManager, IInstallationManagerStatics>().AddPackageAsync(title, sourceLocation, instanceId, offerId, license);
}

inline Windows::Foundation::Collections::IIterable<Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t>> InstallationManager::GetPendingPackageInstalls()
{
    return get_activation_factory<InstallationManager, IInstallationManagerStatics>().GetPendingPackageInstalls();
}

inline Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> InstallationManager::FindPackagesForCurrentPublisher()
{
    return get_activation_factory<InstallationManager, IInstallationManagerStatics>().FindPackagesForCurrentPublisher();
}

inline Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> InstallationManager::FindPackages()
{
    return get_activation_factory<InstallationManager, IInstallationManagerStatics>().FindPackages();
}

inline Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t> InstallationManager::RemovePackageAsync(hstring_view packageFullName, Windows::Management::Deployment::RemovalOptions removalOptions)
{
    return get_activation_factory<InstallationManager, IInstallationManagerStatics2>().RemovePackageAsync(packageFullName, removalOptions);
}

inline Windows::Foundation::IAsyncOperationWithProgress<Windows::Phone::Management::Deployment::PackageInstallResult, uint32_t> InstallationManager::RegisterPackageAsync(const Windows::Foundation::Uri & manifestUri, iterable<Windows::Foundation::Uri> dependencyPackageUris, Windows::Management::Deployment::DeploymentOptions deploymentOptions)
{
    return get_activation_factory<InstallationManager, IInstallationManagerStatics2>().RegisterPackageAsync(manifestUri, dependencyPackageUris, deploymentOptions);
}

inline Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Package> InstallationManager::FindPackages(hstring_view packageName, hstring_view packagePublisher)
{
    return get_activation_factory<InstallationManager, IInstallationManagerStatics2>().FindPackages(packageName, packagePublisher);
}

}

}
#pragma warning(pop)
