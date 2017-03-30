// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Threading.Core.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::Threading::Core {

template <typename H> struct impl_SignalHandler : implements<impl_SignalHandler<H>, abi<SignalHandler>>, H
{
    impl_SignalHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::System::Threading::Core::ISignalNotifier> signalNotifier, bool timedOut) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::System::Threading::Core::SignalNotifier *>(&signalNotifier), timedOut);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::System::Threading::Core {

struct WINRT_EBO PreallocatedWorkItem :
    Windows::System::Threading::Core::IPreallocatedWorkItem
{
    PreallocatedWorkItem(std::nullptr_t) noexcept {}
    PreallocatedWorkItem(const Windows::System::Threading::WorkItemHandler & handler);
    PreallocatedWorkItem(const Windows::System::Threading::WorkItemHandler & handler, Windows::System::Threading::WorkItemPriority priority);
    PreallocatedWorkItem(const Windows::System::Threading::WorkItemHandler & handler, Windows::System::Threading::WorkItemPriority priority, Windows::System::Threading::WorkItemOptions options);
};

struct WINRT_EBO SignalNotifier :
    Windows::System::Threading::Core::ISignalNotifier
{
    SignalNotifier(std::nullptr_t) noexcept {}
    static Windows::System::Threading::Core::SignalNotifier AttachToEvent(hstring_view name, const Windows::System::Threading::Core::SignalHandler & handler);
    static Windows::System::Threading::Core::SignalNotifier AttachToEvent(hstring_view name, const Windows::System::Threading::Core::SignalHandler & handler, const Windows::Foundation::TimeSpan & timeout);
    static Windows::System::Threading::Core::SignalNotifier AttachToSemaphore(hstring_view name, const Windows::System::Threading::Core::SignalHandler & handler);
    static Windows::System::Threading::Core::SignalNotifier AttachToSemaphore(hstring_view name, const Windows::System::Threading::Core::SignalHandler & handler, const Windows::Foundation::TimeSpan & timeout);
};

}

}
