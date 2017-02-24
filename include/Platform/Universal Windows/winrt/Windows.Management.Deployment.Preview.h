// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Management.Deployment.Preview.3.h"
#include "Windows.Management.Deployment.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Management::Deployment::Preview::IClassicAppManagerStatics> : produce_base<D, Windows::Management::Deployment::Preview::IClassicAppManagerStatics>
{
    HRESULT __stdcall abi_FindInstalledApp(impl::abi_arg_in<hstring> appUninstallKey, impl::abi_arg_out<Windows::Management::Deployment::Preview::IInstalledClassicAppInfo> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindInstalledApp(*reinterpret_cast<const hstring *>(&appUninstallKey)));
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
struct produce<D, Windows::Management::Deployment::Preview::IInstalledClassicAppInfo> : produce_base<D, Windows::Management::Deployment::Preview::IInstalledClassicAppInfo>
{
    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayVersion(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayVersion());
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

namespace Windows::Management::Deployment::Preview {

template <typename D> hstring impl_IInstalledClassicAppInfo<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IInstalledClassicAppInfo)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IInstalledClassicAppInfo<D>::DisplayVersion() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IInstalledClassicAppInfo)->get_DisplayVersion(put_abi(value)));
    return value;
}

template <typename D> Windows::Management::Deployment::Preview::InstalledClassicAppInfo impl_IClassicAppManagerStatics<D>::FindInstalledApp(hstring_view appUninstallKey) const
{
    Windows::Management::Deployment::Preview::InstalledClassicAppInfo result { nullptr };
    check_hresult(WINRT_SHIM(IClassicAppManagerStatics)->abi_FindInstalledApp(get_abi(appUninstallKey), put_abi(result)));
    return result;
}

inline Windows::Management::Deployment::Preview::InstalledClassicAppInfo ClassicAppManager::FindInstalledApp(hstring_view appUninstallKey)
{
    return get_activation_factory<ClassicAppManager, IClassicAppManagerStatics>().FindInstalledApp(appUninstallKey);
}

}

}
#pragma warning(pop)
