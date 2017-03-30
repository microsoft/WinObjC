// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.Threading.Core.1.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::Threading::Core {

struct SignalHandler : Windows::Foundation::IUnknown
{
    SignalHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> SignalHandler(L lambda);
    template <typename F> SignalHandler (F * function);
    template <typename O, typename M> SignalHandler(O * object, M method);
    void operator()(const Windows::System::Threading::Core::SignalNotifier & signalNotifier, bool timedOut) const;
};

struct IPreallocatedWorkItem :
    Windows::Foundation::IInspectable,
    impl::consume<IPreallocatedWorkItem>
{
    IPreallocatedWorkItem(std::nullptr_t = nullptr) noexcept {}
};

struct IPreallocatedWorkItemFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IPreallocatedWorkItemFactory>
{
    IPreallocatedWorkItemFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ISignalNotifier :
    Windows::Foundation::IInspectable,
    impl::consume<ISignalNotifier>
{
    ISignalNotifier(std::nullptr_t = nullptr) noexcept {}
};

struct ISignalNotifierStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISignalNotifierStatics>
{
    ISignalNotifierStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
