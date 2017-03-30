// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Management.Deployment.Preview.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Management::Deployment::Preview {

struct __declspec(uuid("e2fad668-882c-4f33-b035-0df7b90d67e6")) __declspec(novtable) IClassicAppManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindInstalledApp(hstring appUninstallKey, Windows::Management::Deployment::Preview::IInstalledClassicAppInfo ** result) = 0;
};

struct __declspec(uuid("0a7d3da3-65d0-4086-80d6-0610d760207d")) __declspec(novtable) IInstalledClassicAppInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplayVersion(hstring * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Management::Deployment::Preview::InstalledClassicAppInfo> { using default_interface = Windows::Management::Deployment::Preview::IInstalledClassicAppInfo; };

}

namespace Windows::Management::Deployment::Preview {

template <typename D>
struct WINRT_EBO impl_IClassicAppManagerStatics
{
    Windows::Management::Deployment::Preview::InstalledClassicAppInfo FindInstalledApp(hstring_view appUninstallKey) const;
};

template <typename D>
struct WINRT_EBO impl_IInstalledClassicAppInfo
{
    hstring DisplayName() const;
    hstring DisplayVersion() const;
};

}

namespace impl {

template <> struct traits<Windows::Management::Deployment::Preview::IClassicAppManagerStatics>
{
    using abi = ABI::Windows::Management::Deployment::Preview::IClassicAppManagerStatics;
    template <typename D> using consume = Windows::Management::Deployment::Preview::impl_IClassicAppManagerStatics<D>;
};

template <> struct traits<Windows::Management::Deployment::Preview::IInstalledClassicAppInfo>
{
    using abi = ABI::Windows::Management::Deployment::Preview::IInstalledClassicAppInfo;
    template <typename D> using consume = Windows::Management::Deployment::Preview::impl_IInstalledClassicAppInfo<D>;
};

template <> struct traits<Windows::Management::Deployment::Preview::ClassicAppManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Management.Deployment.Preview.ClassicAppManager"; }
};

template <> struct traits<Windows::Management::Deployment::Preview::InstalledClassicAppInfo>
{
    using abi = ABI::Windows::Management::Deployment::Preview::InstalledClassicAppInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Management.Deployment.Preview.InstalledClassicAppInfo"; }
};

}

}
