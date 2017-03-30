// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.System.RemoteDesktop.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::System::RemoteDesktop {

struct __declspec(uuid("60884631-dd3a-4576-9c8d-e8027618bdce")) __declspec(novtable) IInteractiveSessionStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsRemote(bool * value) = 0;
};

}

namespace ABI {


}

namespace Windows::System::RemoteDesktop {

template <typename D>
struct WINRT_EBO impl_IInteractiveSessionStatics
{
    bool IsRemote() const;
};

}

namespace impl {

template <> struct traits<Windows::System::RemoteDesktop::IInteractiveSessionStatics>
{
    using abi = ABI::Windows::System::RemoteDesktop::IInteractiveSessionStatics;
    template <typename D> using consume = Windows::System::RemoteDesktop::impl_IInteractiveSessionStatics<D>;
};

template <> struct traits<Windows::System::RemoteDesktop::InteractiveSession>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.RemoteDesktop.InteractiveSession"; }
};

}

}
