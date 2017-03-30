// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.System.Threading.Core.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.System.Threading.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::System::Threading::Core {

struct __declspec(uuid("b6daa9fc-bc5b-401a-a8b2-6e754d14daa6")) __declspec(novtable) IPreallocatedWorkItem : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RunAsync(Windows::Foundation::IAsyncAction ** operation) = 0;
};

struct __declspec(uuid("e3d32b45-dfea-469b-82c5-f6e3cefdeafb")) __declspec(novtable) IPreallocatedWorkItemFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWorkItem(Windows::System::Threading::WorkItemHandler * handler, Windows::System::Threading::Core::IPreallocatedWorkItem ** workItem) = 0;
    virtual HRESULT __stdcall abi_CreateWorkItemWithPriority(Windows::System::Threading::WorkItemHandler * handler, winrt::Windows::System::Threading::WorkItemPriority priority, Windows::System::Threading::Core::IPreallocatedWorkItem ** WorkItem) = 0;
    virtual HRESULT __stdcall abi_CreateWorkItemWithPriorityAndOptions(Windows::System::Threading::WorkItemHandler * handler, winrt::Windows::System::Threading::WorkItemPriority priority, winrt::Windows::System::Threading::WorkItemOptions options, Windows::System::Threading::Core::IPreallocatedWorkItem ** WorkItem) = 0;
};

struct __declspec(uuid("14285e06-63a7-4713-b6d9-62f64b56fb8b")) __declspec(novtable) ISignalNotifier : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Enable() = 0;
    virtual HRESULT __stdcall abi_Terminate() = 0;
};

struct __declspec(uuid("1c4e4566-8400-46d3-a115-7d0c0dfc9f62")) __declspec(novtable) ISignalNotifierStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AttachToEvent(hstring name, Windows::System::Threading::Core::SignalHandler * handler, Windows::System::Threading::Core::ISignalNotifier ** signalNotifier) = 0;
    virtual HRESULT __stdcall abi_AttachToEventWithTimeout(hstring name, Windows::System::Threading::Core::SignalHandler * handler, Windows::Foundation::TimeSpan timeout, Windows::System::Threading::Core::ISignalNotifier ** signalNotifier) = 0;
    virtual HRESULT __stdcall abi_AttachToSemaphore(hstring name, Windows::System::Threading::Core::SignalHandler * handler, Windows::System::Threading::Core::ISignalNotifier ** signalNotifier) = 0;
    virtual HRESULT __stdcall abi_AttachToSemaphoreWithTimeout(hstring name, Windows::System::Threading::Core::SignalHandler * handler, Windows::Foundation::TimeSpan timeout, Windows::System::Threading::Core::ISignalNotifier ** signalNotifier) = 0;
};

struct __declspec(uuid("923c402e-4721-440e-9dda-55b6f2e07710")) __declspec(novtable) SignalHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::System::Threading::Core::ISignalNotifier * signalNotifier, bool timedOut) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::System::Threading::Core::PreallocatedWorkItem> { using default_interface = Windows::System::Threading::Core::IPreallocatedWorkItem; };
template <> struct traits<Windows::System::Threading::Core::SignalNotifier> { using default_interface = Windows::System::Threading::Core::ISignalNotifier; };

}

namespace Windows::System::Threading::Core {

template <typename D>
struct WINRT_EBO impl_IPreallocatedWorkItem
{
    Windows::Foundation::IAsyncAction RunAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IPreallocatedWorkItemFactory
{
    Windows::System::Threading::Core::PreallocatedWorkItem CreateWorkItem(const Windows::System::Threading::WorkItemHandler & handler) const;
    Windows::System::Threading::Core::PreallocatedWorkItem CreateWorkItemWithPriority(const Windows::System::Threading::WorkItemHandler & handler, Windows::System::Threading::WorkItemPriority priority) const;
    Windows::System::Threading::Core::PreallocatedWorkItem CreateWorkItemWithPriorityAndOptions(const Windows::System::Threading::WorkItemHandler & handler, Windows::System::Threading::WorkItemPriority priority, Windows::System::Threading::WorkItemOptions options) const;
};

template <typename D>
struct WINRT_EBO impl_ISignalNotifier
{
    void Enable() const;
    void Terminate() const;
};

template <typename D>
struct WINRT_EBO impl_ISignalNotifierStatics
{
    Windows::System::Threading::Core::SignalNotifier AttachToEvent(hstring_view name, const Windows::System::Threading::Core::SignalHandler & handler) const;
    Windows::System::Threading::Core::SignalNotifier AttachToEvent(hstring_view name, const Windows::System::Threading::Core::SignalHandler & handler, const Windows::Foundation::TimeSpan & timeout) const;
    Windows::System::Threading::Core::SignalNotifier AttachToSemaphore(hstring_view name, const Windows::System::Threading::Core::SignalHandler & handler) const;
    Windows::System::Threading::Core::SignalNotifier AttachToSemaphore(hstring_view name, const Windows::System::Threading::Core::SignalHandler & handler, const Windows::Foundation::TimeSpan & timeout) const;
};

}

namespace impl {

template <> struct traits<Windows::System::Threading::Core::IPreallocatedWorkItem>
{
    using abi = ABI::Windows::System::Threading::Core::IPreallocatedWorkItem;
    template <typename D> using consume = Windows::System::Threading::Core::impl_IPreallocatedWorkItem<D>;
};

template <> struct traits<Windows::System::Threading::Core::IPreallocatedWorkItemFactory>
{
    using abi = ABI::Windows::System::Threading::Core::IPreallocatedWorkItemFactory;
    template <typename D> using consume = Windows::System::Threading::Core::impl_IPreallocatedWorkItemFactory<D>;
};

template <> struct traits<Windows::System::Threading::Core::ISignalNotifier>
{
    using abi = ABI::Windows::System::Threading::Core::ISignalNotifier;
    template <typename D> using consume = Windows::System::Threading::Core::impl_ISignalNotifier<D>;
};

template <> struct traits<Windows::System::Threading::Core::ISignalNotifierStatics>
{
    using abi = ABI::Windows::System::Threading::Core::ISignalNotifierStatics;
    template <typename D> using consume = Windows::System::Threading::Core::impl_ISignalNotifierStatics<D>;
};

template <> struct traits<Windows::System::Threading::Core::SignalHandler>
{
    using abi = ABI::Windows::System::Threading::Core::SignalHandler;
};

template <> struct traits<Windows::System::Threading::Core::PreallocatedWorkItem>
{
    using abi = ABI::Windows::System::Threading::Core::PreallocatedWorkItem;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Threading.Core.PreallocatedWorkItem"; }
};

template <> struct traits<Windows::System::Threading::Core::SignalNotifier>
{
    using abi = ABI::Windows::System::Threading::Core::SignalNotifier;
    static constexpr const wchar_t * name() noexcept { return L"Windows.System.Threading.Core.SignalNotifier"; }
};

}

}
