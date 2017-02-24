// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Phone.System.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Phone::System::ISystemProtectionStatics> : produce_base<D, Windows::Phone::System::ISystemProtectionStatics>
{
    HRESULT __stdcall get_ScreenLocked(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ScreenLocked());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Phone::System::ISystemProtectionUnlockStatics> : produce_base<D, Windows::Phone::System::ISystemProtectionUnlockStatics>
{
    HRESULT __stdcall abi_RequestScreenUnlock() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestScreenUnlock();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Phone::System {

template <typename D> bool impl_ISystemProtectionStatics<D>::ScreenLocked() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISystemProtectionStatics)->get_ScreenLocked(&value));
    return value;
}

template <typename D> void impl_ISystemProtectionUnlockStatics<D>::RequestScreenUnlock() const
{
    check_hresult(WINRT_SHIM(ISystemProtectionUnlockStatics)->abi_RequestScreenUnlock());
}

inline bool SystemProtection::ScreenLocked()
{
    return get_activation_factory<SystemProtection, ISystemProtectionStatics>().ScreenLocked();
}

inline void SystemProtection::RequestScreenUnlock()
{
    get_activation_factory<SystemProtection, ISystemProtectionUnlockStatics>().RequestScreenUnlock();
}

}

}
#pragma warning(pop)
