// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Resources {

template <typename D, typename A = ABI::Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides>
class ICustomXamlResourceLoaderOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using ICustomXamlResourceLoaderOverrides = winrt::Windows::UI::Xaml::Resources::ICustomXamlResourceLoaderOverrides;

    Windows::Foundation::IInspectable GetResource(hstring_view resourceId, hstring_view objectType, hstring_view propertyName, hstring_view propertyType)
    {
        return shim().as<ICustomXamlResourceLoaderOverrides>().GetResource(resourceId, objectType, propertyName, propertyType);
    }

    HRESULT __stdcall abi_GetResource(impl::abi_arg_in<hstring> resourceId, impl::abi_arg_in<hstring> objectType, impl::abi_arg_in<hstring> propertyName, impl::abi_arg_in<hstring> propertyType, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetResource(*reinterpret_cast<const hstring *>(&resourceId), *reinterpret_cast<const hstring *>(&objectType), *reinterpret_cast<const hstring *>(&propertyName), *reinterpret_cast<const hstring *>(&propertyType)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

}

}
