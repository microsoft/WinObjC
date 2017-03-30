// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.ExtendedExecution.Foreground.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::ExtendedExecution::Foreground {

struct __declspec(uuid("b07cd940-9557-aea4-2c99-bdd56d9be461")) __declspec(novtable) IExtendedExecutionForegroundRevokedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reason(winrt::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedReason * value) = 0;
};

struct __declspec(uuid("fbf440e1-9d10-4201-b01e-c83275296f2e")) __declspec(novtable) IExtendedExecutionForegroundSession : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall put_Description(hstring value) = 0;
    virtual HRESULT __stdcall add_Revoked(Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Revoked(event_token token) = 0;
    virtual HRESULT __stdcall abi_RequestExtensionAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult> ** operation) = 0;
    virtual HRESULT __stdcall get_Reason(winrt::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason * value) = 0;
    virtual HRESULT __stdcall put_Reason(winrt::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs> { using default_interface = Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs; };
template <> struct traits<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundSession> { using default_interface = Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession; };

}

namespace Windows::ApplicationModel::ExtendedExecution::Foreground {

template <typename D>
struct WINRT_EBO impl_IExtendedExecutionForegroundRevokedEventArgs
{
    Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedReason Reason() const;
};

template <typename D>
struct WINRT_EBO impl_IExtendedExecutionForegroundSession
{
    hstring Description() const;
    void Description(hstring_view value) const;
    event_token Revoked(const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs> & handler) const;
    using Revoked_revoker = event_revoker<IExtendedExecutionForegroundSession>;
    Revoked_revoker Revoked(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Foundation::IInspectable, Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs> & handler) const;
    void Revoked(event_token token) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult> RequestExtensionAsync() const;
    Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason Reason() const;
    void Reason(Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason value) const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::ExtendedExecution::Foreground::impl_IExtendedExecutionForegroundRevokedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>
{
    using abi = ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession;
    template <typename D> using consume = Windows::ApplicationModel::ExtendedExecution::Foreground::impl_IExtendedExecutionForegroundSession<D>;
};

template <> struct traits<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.ExtendedExecution.Foreground.ExtendedExecutionForegroundRevokedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundSession>
{
    using abi = ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundSession;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.ExtendedExecution.Foreground.ExtendedExecutionForegroundSession"; }
};

}

}
