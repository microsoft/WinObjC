// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Phone.System.Profile.3.h"
#include "Windows.Phone.System.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Phone::System::Profile::IRetailModeStatics> : produce_base<D, Windows::Phone::System::Profile::IRetailModeStatics>
{
    HRESULT __stdcall get_RetailModeEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RetailModeEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Phone::System::Profile {

template <typename D> bool impl_IRetailModeStatics<D>::RetailModeEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IRetailModeStatics)->get_RetailModeEnabled(&value));
    return value;
}

inline bool RetailMode::RetailModeEnabled()
{
    return get_activation_factory<RetailMode, IRetailModeStatics>().RetailModeEnabled();
}

}

}
#pragma warning(pop)
