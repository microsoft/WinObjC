// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.ApplicationModel.Store.LicenseManagement.3.h"
#include "Windows.ApplicationModel.Store.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics> : produce_base<D, Windows::ApplicationModel::Store::LicenseManagement::ILicenseManagerStatics>
{
    HRESULT __stdcall abi_AddLicenseAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> license, impl::abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *action = detach_abi(this->shim().AddLicenseAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&license)));
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSatisfactionInfosAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> contentIds, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> keyIds, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetSatisfactionInfosAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&contentIds), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&keyIds)));
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
struct produce<D, Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo> : produce_base<D, Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo>
{
    HRESULT __stdcall get_SatisfiedByDevice(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SatisfiedByDevice());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SatisfiedByOpenLicense(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SatisfiedByOpenLicense());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SatisfiedByTrial(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SatisfiedByTrial());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SatisfiedByPass(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SatisfiedByPass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SatisfiedByInstallMedia(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SatisfiedByInstallMedia());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SatisfiedBySignedInUser(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SatisfiedBySignedInUser());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSatisfied(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSatisfied());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult> : produce_base<D, Windows::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult>
{
    HRESULT __stdcall get_LicenseSatisfactionInfos(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LicenseSatisfactionInfos());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExtendedError(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExtendedError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Store::LicenseManagement {

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo> impl_ILicenseSatisfactionResult<D>::LicenseSatisfactionInfos() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo> value;
    check_hresult(WINRT_SHIM(ILicenseSatisfactionResult)->get_LicenseSatisfactionInfos(put_abi(value)));
    return value;
}

template <typename D> HRESULT impl_ILicenseSatisfactionResult<D>::ExtendedError() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(ILicenseSatisfactionResult)->get_ExtendedError(&value));
    return value;
}

template <typename D> bool impl_ILicenseSatisfactionInfo<D>::SatisfiedByDevice() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILicenseSatisfactionInfo)->get_SatisfiedByDevice(&value));
    return value;
}

template <typename D> bool impl_ILicenseSatisfactionInfo<D>::SatisfiedByOpenLicense() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILicenseSatisfactionInfo)->get_SatisfiedByOpenLicense(&value));
    return value;
}

template <typename D> bool impl_ILicenseSatisfactionInfo<D>::SatisfiedByTrial() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILicenseSatisfactionInfo)->get_SatisfiedByTrial(&value));
    return value;
}

template <typename D> bool impl_ILicenseSatisfactionInfo<D>::SatisfiedByPass() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILicenseSatisfactionInfo)->get_SatisfiedByPass(&value));
    return value;
}

template <typename D> bool impl_ILicenseSatisfactionInfo<D>::SatisfiedByInstallMedia() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILicenseSatisfactionInfo)->get_SatisfiedByInstallMedia(&value));
    return value;
}

template <typename D> bool impl_ILicenseSatisfactionInfo<D>::SatisfiedBySignedInUser() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILicenseSatisfactionInfo)->get_SatisfiedBySignedInUser(&value));
    return value;
}

template <typename D> bool impl_ILicenseSatisfactionInfo<D>::IsSatisfied() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ILicenseSatisfactionInfo)->get_IsSatisfied(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ILicenseManagerStatics<D>::AddLicenseAsync(const Windows::Storage::Streams::IBuffer & license) const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(WINRT_SHIM(ILicenseManagerStatics)->abi_AddLicenseAsync(get_abi(license), put_abi(action)));
    return action;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult> impl_ILicenseManagerStatics<D>::GetSatisfactionInfosAsync(iterable<hstring> contentIds, iterable<hstring> keyIds) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult> operation;
    check_hresult(WINRT_SHIM(ILicenseManagerStatics)->abi_GetSatisfactionInfosAsync(get_abi(contentIds), get_abi(keyIds), put_abi(operation)));
    return operation;
}

inline Windows::Foundation::IAsyncAction LicenseManager::AddLicenseAsync(const Windows::Storage::Streams::IBuffer & license)
{
    return get_activation_factory<LicenseManager, ILicenseManagerStatics>().AddLicenseAsync(license);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult> LicenseManager::GetSatisfactionInfosAsync(iterable<hstring> contentIds, iterable<hstring> keyIds)
{
    return get_activation_factory<LicenseManager, ILicenseManagerStatics>().GetSatisfactionInfosAsync(contentIds, keyIds);
}

}

}
#pragma warning(pop)
