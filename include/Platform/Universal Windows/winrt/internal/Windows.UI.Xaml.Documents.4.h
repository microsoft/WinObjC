// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Documents {

template <typename D, typename A = ABI::Windows::UI::Xaml::Documents::ITextElementOverrides>
class ITextElementOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using ITextElementOverrides = winrt::Windows::UI::Xaml::Documents::ITextElementOverrides;

    void OnDisconnectVisualChildren()
    {
        shim().as<ITextElementOverrides>().OnDisconnectVisualChildren();
    }

    HRESULT __stdcall abi_OnDisconnectVisualChildren() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnDisconnectVisualChildren();
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
