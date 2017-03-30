// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::System::Threading::Core {

struct IPreallocatedWorkItem;
struct IPreallocatedWorkItemFactory;
struct ISignalNotifier;
struct ISignalNotifierStatics;
struct SignalHandler;
struct PreallocatedWorkItem;
struct SignalNotifier;

}

namespace Windows::System::Threading::Core {

struct SignalHandler;
struct IPreallocatedWorkItem;
struct IPreallocatedWorkItemFactory;
struct ISignalNotifier;
struct ISignalNotifierStatics;
struct PreallocatedWorkItem;
struct SignalNotifier;

}

namespace Windows::System::Threading::Core {

template <typename T> struct impl_IPreallocatedWorkItem;
template <typename T> struct impl_IPreallocatedWorkItemFactory;
template <typename T> struct impl_ISignalNotifier;
template <typename T> struct impl_ISignalNotifierStatics;
template <typename T> struct impl_SignalHandler;

}

}
