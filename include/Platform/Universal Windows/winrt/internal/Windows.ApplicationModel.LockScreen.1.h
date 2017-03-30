// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.LockScreen.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::LockScreen {

struct __declspec(uuid("38ee31ad-d94f-4e7c-81fa-4f4436506281")) __declspec(novtable) ILockApplicationHost : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestUnlock() = 0;
    virtual HRESULT __stdcall add_Unlocking(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockApplicationHost, Windows::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Unlocking(event_token token) = 0;
};

struct __declspec(uuid("f48fab8e-23d7-4e63-96a1-666ff52d3b2c")) __declspec(novtable) ILockApplicationHostStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForCurrentView(Windows::ApplicationModel::LockScreen::ILockApplicationHost ** result) = 0;
};

struct __declspec(uuid("e95105d9-2bff-4db0-9b4f-3824778b9c9a")) __declspec(novtable) ILockScreenBadge : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Logo(Windows::Storage::Streams::IRandomAccessStream ** value) = 0;
    virtual HRESULT __stdcall get_Glyph(Windows::Storage::Streams::IRandomAccessStream ** value) = 0;
    virtual HRESULT __stdcall get_Number(Windows::Foundation::IReference<uint32_t> ** value) = 0;
    virtual HRESULT __stdcall get_AutomationName(hstring * value) = 0;
    virtual HRESULT __stdcall abi_LaunchApp() = 0;
};

struct __declspec(uuid("f59aa65c-9711-4dc9-a630-95b6cb8cdad0")) __declspec(novtable) ILockScreenInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_LockScreenImageChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockScreenInfo, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_LockScreenImageChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_LockScreenImage(Windows::Storage::Streams::IRandomAccessStream ** value) = 0;
    virtual HRESULT __stdcall add_BadgesChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockScreenInfo, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BadgesChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_Badges(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::LockScreen::LockScreenBadge> ** value) = 0;
    virtual HRESULT __stdcall add_DetailTextChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockScreenInfo, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DetailTextChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_DetailText(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall add_AlarmIconChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockScreenInfo, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AlarmIconChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_AlarmIcon(Windows::Storage::Streams::IRandomAccessStream ** value) = 0;
};

struct __declspec(uuid("7e7d1ad6-5203-43e7-9bd6-7c3947d1e3fe")) __declspec(novtable) ILockScreenUnlockingDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("44e6c007-75fb-4abb-9f8b-824748900c71")) __declspec(novtable) ILockScreenUnlockingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeferral(Windows::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral ** deferral) = 0;
    virtual HRESULT __stdcall get_Deadline(Windows::Foundation::DateTime * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::LockScreen::LockApplicationHost> { using default_interface = Windows::ApplicationModel::LockScreen::ILockApplicationHost; };
template <> struct traits<Windows::ApplicationModel::LockScreen::LockScreenBadge> { using default_interface = Windows::ApplicationModel::LockScreen::ILockScreenBadge; };
template <> struct traits<Windows::ApplicationModel::LockScreen::LockScreenInfo> { using default_interface = Windows::ApplicationModel::LockScreen::ILockScreenInfo; };
template <> struct traits<Windows::ApplicationModel::LockScreen::LockScreenUnlockingDeferral> { using default_interface = Windows::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral; };
template <> struct traits<Windows::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs> { using default_interface = Windows::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs; };

}

namespace Windows::ApplicationModel::LockScreen {

template <typename D>
struct WINRT_EBO impl_ILockApplicationHost
{
    void RequestUnlock() const;
    event_token Unlocking(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockApplicationHost, Windows::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs> & handler) const;
    using Unlocking_revoker = event_revoker<ILockApplicationHost>;
    Unlocking_revoker Unlocking(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockApplicationHost, Windows::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs> & handler) const;
    void Unlocking(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_ILockApplicationHostStatics
{
    Windows::ApplicationModel::LockScreen::LockApplicationHost GetForCurrentView() const;
};

template <typename D>
struct WINRT_EBO impl_ILockScreenBadge
{
    Windows::Storage::Streams::IRandomAccessStream Logo() const;
    Windows::Storage::Streams::IRandomAccessStream Glyph() const;
    Windows::Foundation::IReference<uint32_t> Number() const;
    hstring AutomationName() const;
    void LaunchApp() const;
};

template <typename D>
struct WINRT_EBO impl_ILockScreenInfo
{
    event_token LockScreenImageChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockScreenInfo, Windows::Foundation::IInspectable> & handler) const;
    using LockScreenImageChanged_revoker = event_revoker<ILockScreenInfo>;
    LockScreenImageChanged_revoker LockScreenImageChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockScreenInfo, Windows::Foundation::IInspectable> & handler) const;
    void LockScreenImageChanged(event_token token) const;
    Windows::Storage::Streams::IRandomAccessStream LockScreenImage() const;
    event_token BadgesChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockScreenInfo, Windows::Foundation::IInspectable> & handler) const;
    using BadgesChanged_revoker = event_revoker<ILockScreenInfo>;
    BadgesChanged_revoker BadgesChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockScreenInfo, Windows::Foundation::IInspectable> & handler) const;
    void BadgesChanged(event_token token) const;
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::LockScreen::LockScreenBadge> Badges() const;
    event_token DetailTextChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockScreenInfo, Windows::Foundation::IInspectable> & handler) const;
    using DetailTextChanged_revoker = event_revoker<ILockScreenInfo>;
    DetailTextChanged_revoker DetailTextChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockScreenInfo, Windows::Foundation::IInspectable> & handler) const;
    void DetailTextChanged(event_token token) const;
    Windows::Foundation::Collections::IVectorView<hstring> DetailText() const;
    event_token AlarmIconChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockScreenInfo, Windows::Foundation::IInspectable> & handler) const;
    using AlarmIconChanged_revoker = event_revoker<ILockScreenInfo>;
    AlarmIconChanged_revoker AlarmIconChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::LockScreen::LockScreenInfo, Windows::Foundation::IInspectable> & handler) const;
    void AlarmIconChanged(event_token token) const;
    Windows::Storage::Streams::IRandomAccessStream AlarmIcon() const;
};

template <typename D>
struct WINRT_EBO impl_ILockScreenUnlockingDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_ILockScreenUnlockingEventArgs
{
    Windows::ApplicationModel::LockScreen::LockScreenUnlockingDeferral GetDeferral() const;
    Windows::Foundation::DateTime Deadline() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::LockScreen::ILockApplicationHost>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::ILockApplicationHost;
    template <typename D> using consume = Windows::ApplicationModel::LockScreen::impl_ILockApplicationHost<D>;
};

template <> struct traits<Windows::ApplicationModel::LockScreen::ILockApplicationHostStatics>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::ILockApplicationHostStatics;
    template <typename D> using consume = Windows::ApplicationModel::LockScreen::impl_ILockApplicationHostStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::LockScreen::ILockScreenBadge>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::ILockScreenBadge;
    template <typename D> using consume = Windows::ApplicationModel::LockScreen::impl_ILockScreenBadge<D>;
};

template <> struct traits<Windows::ApplicationModel::LockScreen::ILockScreenInfo>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::ILockScreenInfo;
    template <typename D> using consume = Windows::ApplicationModel::LockScreen::impl_ILockScreenInfo<D>;
};

template <> struct traits<Windows::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral;
    template <typename D> using consume = Windows::ApplicationModel::LockScreen::impl_ILockScreenUnlockingDeferral<D>;
};

template <> struct traits<Windows::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::LockScreen::impl_ILockScreenUnlockingEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::LockScreen::LockApplicationHost>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::LockApplicationHost;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.LockScreen.LockApplicationHost"; }
};

template <> struct traits<Windows::ApplicationModel::LockScreen::LockScreenBadge>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::LockScreenBadge;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.LockScreen.LockScreenBadge"; }
};

template <> struct traits<Windows::ApplicationModel::LockScreen::LockScreenInfo>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::LockScreenInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.LockScreen.LockScreenInfo"; }
};

template <> struct traits<Windows::ApplicationModel::LockScreen::LockScreenUnlockingDeferral>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::LockScreenUnlockingDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.LockScreen.LockScreenUnlockingDeferral"; }
};

template <> struct traits<Windows::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::LockScreen::LockScreenUnlockingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.LockScreen.LockScreenUnlockingEventArgs"; }
};

}

}
