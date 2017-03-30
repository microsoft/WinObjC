// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Media::Animation {

template <typename D, typename A = ABI::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides>
class INavigationTransitionInfoOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using INavigationTransitionInfoOverrides = winrt::Windows::UI::Xaml::Media::Animation::INavigationTransitionInfoOverrides;

    hstring GetNavigationStateCore()
    {
        return shim().as<INavigationTransitionInfoOverrides>().GetNavigationStateCore();
    }

    void SetNavigationStateCore(hstring_view navigationState)
    {
        shim().as<INavigationTransitionInfoOverrides>().SetNavigationStateCore(navigationState);
    }

    HRESULT __stdcall abi_GetNavigationStateCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNavigationStateCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetNavigationStateCore(impl::abi_arg_in<hstring> navigationState) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetNavigationStateCore(*reinterpret_cast<const hstring *>(&navigationState));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

}
