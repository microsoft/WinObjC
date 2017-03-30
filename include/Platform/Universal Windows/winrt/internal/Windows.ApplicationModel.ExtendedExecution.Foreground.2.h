// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.ExtendedExecution.Foreground.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_f874197a_bf19_5482_9ab1_34923de6738d
#define WINRT_GENERIC_f874197a_bf19_5482_9ab1_34923de6738d
template <> struct __declspec(uuid("f874197a-bf19-5482-9ab1-34923de6738d")) __declspec(novtable) TypedEventHandler<Windows::Foundation::IInspectable, Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs> : impl_TypedEventHandler<Windows::Foundation::IInspectable, Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_b18ea00f_8c20_5ac2_9246_3ef405271f1a
#define WINRT_GENERIC_b18ea00f_8c20_5ac2_9246_3ef405271f1a
template <> struct __declspec(uuid("b18ea00f-8c20-5ac2-9246-3ef405271f1a")) __declspec(novtable) IAsyncOperation<winrt::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult> : impl_IAsyncOperation<winrt::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult> {};
#endif

#ifndef WINRT_GENERIC_07e1dc01_18ba_596a_b745_79f9cde44ccc
#define WINRT_GENERIC_07e1dc01_18ba_596a_b745_79f9cde44ccc
template <> struct __declspec(uuid("07e1dc01-18ba-596a-b745-79f9cde44ccc")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult> : impl_AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult> {};
#endif


}

namespace Windows::ApplicationModel::ExtendedExecution::Foreground {

struct IExtendedExecutionForegroundRevokedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IExtendedExecutionForegroundRevokedEventArgs>
{
    IExtendedExecutionForegroundRevokedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IExtendedExecutionForegroundSession :
    Windows::Foundation::IInspectable,
    impl::consume<IExtendedExecutionForegroundSession>,
    impl::require<IExtendedExecutionForegroundSession, Windows::Foundation::IClosable>
{
    IExtendedExecutionForegroundSession(std::nullptr_t = nullptr) noexcept {}
};

}

}
