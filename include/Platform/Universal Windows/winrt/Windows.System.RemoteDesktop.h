// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.System.RemoteDesktop.3.h"
#include "Windows.System.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::System::RemoteDesktop::IInteractiveSessionStatics> : produce_base<D, Windows::System::RemoteDesktop::IInteractiveSessionStatics>
{
    HRESULT __stdcall get_IsRemote(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsRemote());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::System::RemoteDesktop {

template <typename D> bool impl_IInteractiveSessionStatics<D>::IsRemote() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IInteractiveSessionStatics)->get_IsRemote(&value));
    return value;
}

inline bool InteractiveSession::IsRemote()
{
    return get_activation_factory<InteractiveSession, IInteractiveSessionStatics>().IsRemote();
}

}

}
#pragma warning(pop)
