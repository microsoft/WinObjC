// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Management.Core.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Management::Core::IApplicationDataManager> : produce_base<D, Windows::Management::Core::IApplicationDataManager>
{};

template <typename D>
struct produce<D, Windows::Management::Core::IApplicationDataManagerStatics> : produce_base<D, Windows::Management::Core::IApplicationDataManagerStatics>
{
    HRESULT __stdcall abi_CreateForPackageFamily(impl::abi_arg_in<hstring> packageFamilyName, impl::abi_arg_out<Windows::Storage::IApplicationData> applicationData) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *applicationData = detach_abi(this->shim().CreateForPackageFamily(*reinterpret_cast<const hstring *>(&packageFamilyName)));
            return S_OK;
        }
        catch (...)
        {
            *applicationData = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Management::Core {

template <typename D> Windows::Storage::ApplicationData impl_IApplicationDataManagerStatics<D>::CreateForPackageFamily(hstring_view packageFamilyName) const
{
    Windows::Storage::ApplicationData applicationData { nullptr };
    check_hresult(WINRT_SHIM(IApplicationDataManagerStatics)->abi_CreateForPackageFamily(get_abi(packageFamilyName), put_abi(applicationData)));
    return applicationData;
}

inline Windows::Storage::ApplicationData ApplicationDataManager::CreateForPackageFamily(hstring_view packageFamilyName)
{
    return get_activation_factory<ApplicationDataManager, IApplicationDataManagerStatics>().CreateForPackageFamily(packageFamilyName);
}

}

}
#pragma warning(pop)
