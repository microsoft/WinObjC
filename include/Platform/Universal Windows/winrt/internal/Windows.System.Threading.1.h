// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.System.Threading.0.h"
#include "Windows.Foundation.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::System::Threading {

struct __declspec(uuid("b6bf67dd-84bd-44f8-ac1c-93ebcb9dba91")) __declspec(novtable) IThreadPoolStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RunAsync(Windows::System::Threading::WorkItemHandler * handler, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_RunWithPriorityAsync(Windows::System::Threading::WorkItemHandler * handler, winrt::Windows::System::Threading::WorkItemPriority priority, Windows::Foundation::IAsyncAction ** operation) = 0;
    virtual HRESULT __stdcall abi_RunWithPriorityAndOptionsAsync(Windows::System::Threading::WorkItemHandler * handler, winrt::Windows::System::Threading::WorkItemPriority priority, winrt::Windows::System::Threading::WorkItemOptions options, Windows::Foundation::IAsyncAction ** operation) = 0;
};

struct __declspec(uuid("594ebe78-55ea-4a88-a50d-3402ae1f9cf2")) __declspec(novtable) IThreadPoolTimer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Period(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_Delay(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall abi_Cancel() = 0;
};

struct __declspec(uuid("1a8a9d02-e482-461b-b8c7-8efad1cce590")) __declspec(novtable) IThreadPoolTimerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreatePeriodicTimer(Windows::System::Threading::TimerElapsedHandler * handler, Windows::Foundation::TimeSpan period, Windows::System::Threading::IThreadPoolTimer ** timer) = 0;
    virtual HRESULT __stdcall abi_CreateTimer(Windows::System::Threading::TimerElapsedHandler * handler, Windows::Foundation::TimeSpan delay, Windows::System::Threading::IThreadPoolTimer ** timer) = 0;
    virtual HRESULT __stdcall abi_CreatePeriodicTimerWithCompletion(Windows::System::Threading::TimerElapsedHandler * handler, Windows::Foundation::TimeSpan period, Windows::System::Threading::TimerDestroyedHandler * destroyed, Windows::System::Threading::IThreadPoolTimer ** timer) = 0;
    virtual HRESULT __stdcall abi_CreateTimerWithCompletion(Windows::System::Threading::TimerElapsedHandler * handler, Windows::Foundation::TimeSpan delay, Windows::System::Threading::TimerDestroyedHandler * destroyed, Windows::System::Threading::IThreadPoolTimer ** timer) = 0;
};

struct __declspec(uuid("34ed19fa-8384-4eb9-8209-fb5094eeec35")) __declspec(novtable) TimerDestroyedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::System::Threading::IThreadPoolTimer * timer) = 0;
};

struct __declspec(uuid("faaea667-fbeb-49cb-adb2-71184c556e43")) __declspec(novtable) TimerElapsedHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::System::Threading::IThreadPoolTimer * timer) = 0;
};

struct __declspec(uuid("1d1a8b8b-fa66-414f-9cbd-b65fc99d17fa")) __declspec(novtable) WorkItemHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IAsyncAction * operation) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::System::Threading::ThreadPoolTimer> { using default_interface = Windows::System::Threading::IThreadPoolTimer; };

}

namespace Windows::System::Threading {

template <typename D>
struct WINRT_EBO impl_IThreadPoolStatics
{
    Windows::Foundation::IAsyncAction RunAsync(const Windows::System::Threading::WorkItemHandler & handler) const;
    Windows::Foundation::IAsyncAction RunAsync(const Windows::System::Threading::WorkItemHandler & handler, Windows::System::Threading::WorkItemPriority priority) const;
    Windows::Foundation::IAsyncAction RunAsync(const Windows::System::Threading::WorkItemHandler & handler, Windows::System::Threading::WorkItemPriority priority, Windows::System::Threading::WorkItemOptions options) const;
};

template <typename D>
struct WINRT_EBO impl_IThreadPoolTimer
{
    Windows::Foundation::TimeSpan Period() const;
    Windows::Foundation::TimeSpan Delay() const;
    void Cancel() const;
};

template <typename D>
struct WINRT_EBO impl_IThreadPoolTimerStatics
{
    Windows::System::Threading::ThreadPoolTimer CreatePeriodicTimer(const Windows::System::Threading::TimerElapsedHandler & handler, const Windows::Foundation::TimeSpan & period) const;
    Windows::System::Threading::ThreadPoolTimer CreateTimer(const Windows::System::Threading::TimerElapsedHandler & handler, const Windows::Foundation::TimeSpan & delay) const;
    Windows::System::Threading::ThreadPoolTimer CreatePeriodicTimer(const Windows::System::Threading::TimerElapsedHandler & handler, const Windows::Foundation::TimeSpan & period, const Windows::System::Threading::TimerDestroyedHandler & destroyed) const;
    Windows::System::Threading::ThreadPoolTimer CreateTimer(const Windows::System::Threading::TimerElapsedHandler & handler, const Windows::Foundation::TimeSpan & delay, const Windows::System::Threading::TimerDestroyedHandler & destroyed) const;
};

}

namespace impl {

template <> struct traits<Windows::System::Threading::IThreadPoolStatics>
{
    using abi = ABI::Windows::System::Threading::IThreadPoolStatics;
    template <typename D> using consume = Windows::System::Threading::impl_IThreadPoolStatics<D>;
};

template <> struct traits<Windows::System::Threading::IThreadPoolTimer>
{
    using abi = ABI::Windows::System::Threading::IThreadPoolTimer;
    template <typename D> using consume = Windows::System::Threading::impl_IThreadPoolTimer<D>;
};

template <> struct traits<Windows::System::Threading::IThreadPoolTimerStatics>
{
    using abi = ABI::Windows::System::Threading::IThreadPoolTimerStatics;
    template <typename D> using consume = Windows::System::Threading::impl_IThreadPoolTimerStatics<D>;
};

template <> struct traits<Windows::System::Threading::TimerDestroyedHandler>
{
    using abi = ABI::Windows::System::Threading::TimerDestroyedHandler;
};

template <> struct traits<Windows::System::Threading::TimerElapsedHandler>
{
    using abi = ABI::Windows::System::Threading::TimerElapsedHandler;
};

template <> struct traits<Windows::System::Threading::WorkItemHandler>
{
    using abi = ABI::Windows::System::Threading::WorkItemHandler;
};

template <> struct traits<Windows::System::Threading::ThreadPool>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Threading.ThreadPool"; }
};

template <> struct traits<Windows::System::Threading::ThreadPoolTimer>
{
    using abi = ABI::Windows::System::Threading::ThreadPoolTimer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Threading.ThreadPoolTimer"; }
};

}

}
