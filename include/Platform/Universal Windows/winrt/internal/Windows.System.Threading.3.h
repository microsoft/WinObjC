// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Threading.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::Threading {

template <typename H> struct impl_TimerDestroyedHandler : implements<impl_TimerDestroyedHandler<H>, abi<TimerDestroyedHandler>>, H
{
    impl_TimerDestroyedHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::System::Threading::IThreadPoolTimer> timer) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::System::Threading::ThreadPoolTimer *>(&timer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_TimerElapsedHandler : implements<impl_TimerElapsedHandler<H>, abi<TimerElapsedHandler>>, H
{
    impl_TimerElapsedHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::System::Threading::IThreadPoolTimer> timer) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::System::Threading::ThreadPoolTimer *>(&timer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_WorkItemHandler : implements<impl_WorkItemHandler<H>, abi<WorkItemHandler>>, H
{
    impl_WorkItemHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IAsyncAction> operation) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IAsyncAction *>(&operation));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::System::Threading {

struct ThreadPool
{
    ThreadPool() = delete;
    static Windows::Foundation::IAsyncAction RunAsync(const Windows::System::Threading::WorkItemHandler & handler);
    static Windows::Foundation::IAsyncAction RunAsync(const Windows::System::Threading::WorkItemHandler & handler, Windows::System::Threading::WorkItemPriority priority);
    static Windows::Foundation::IAsyncAction RunAsync(const Windows::System::Threading::WorkItemHandler & handler, Windows::System::Threading::WorkItemPriority priority, Windows::System::Threading::WorkItemOptions options);
};

struct WINRT_EBO ThreadPoolTimer :
    Windows::System::Threading::IThreadPoolTimer
{
    ThreadPoolTimer(std::nullptr_t) noexcept {}
    static Windows::System::Threading::ThreadPoolTimer CreatePeriodicTimer(const Windows::System::Threading::TimerElapsedHandler & handler, const Windows::Foundation::TimeSpan & period);
    static Windows::System::Threading::ThreadPoolTimer CreateTimer(const Windows::System::Threading::TimerElapsedHandler & handler, const Windows::Foundation::TimeSpan & delay);
    static Windows::System::Threading::ThreadPoolTimer CreatePeriodicTimer(const Windows::System::Threading::TimerElapsedHandler & handler, const Windows::Foundation::TimeSpan & period, const Windows::System::Threading::TimerDestroyedHandler & destroyed);
    static Windows::System::Threading::ThreadPoolTimer CreateTimer(const Windows::System::Threading::TimerElapsedHandler & handler, const Windows::Foundation::TimeSpan & delay, const Windows::System::Threading::TimerDestroyedHandler & destroyed);
};

}

}
