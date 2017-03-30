// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.CommunicationBlocking.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::CommunicationBlocking {

struct __declspec(uuid("1c969998-9d2a-5db7-edd5-0ce407fc2595")) __declspec(novtable) ICommunicationBlockingAccessManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsBlockingActive(bool * value) = 0;
    virtual HRESULT __stdcall abi_IsBlockedNumberAsync(hstring number, Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
    virtual HRESULT __stdcall abi_ShowBlockNumbersUI(Windows::Foundation::Collections::IIterable<hstring> * phoneNumbers, bool * value) = 0;
    virtual HRESULT __stdcall abi_ShowUnblockNumbersUI(Windows::Foundation::Collections::IIterable<hstring> * phoneNumbers, bool * value) = 0;
    virtual HRESULT __stdcall abi_ShowBlockedCallsUI() = 0;
    virtual HRESULT __stdcall abi_ShowBlockedMessagesUI() = 0;
};

struct __declspec(uuid("77db58ec-14a6-4baa-942a-6a673d999bf2")) __declspec(novtable) ICommunicationBlockingAppManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsCurrentAppActiveBlockingApp(bool * value) = 0;
    virtual HRESULT __stdcall abi_ShowCommunicationBlockingSettingsUI() = 0;
};

struct __declspec(uuid("14a68edd-ed88-457a-a364-a3634d6f166d")) __declspec(novtable) ICommunicationBlockingAppManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestSetAsActiveBlockingAppAsync(Windows::Foundation::IAsyncOperation<bool> ** result) = 0;
};

}

namespace ABI {


}

namespace Windows::ApplicationModel::CommunicationBlocking {

template <typename D>
struct WINRT_EBO impl_ICommunicationBlockingAccessManagerStatics
{
    bool IsBlockingActive() const;
    Windows::Foundation::IAsyncOperation<bool> IsBlockedNumberAsync(hstring_view number) const;
    bool ShowBlockNumbersUI(iterable<hstring> phoneNumbers) const;
    bool ShowUnblockNumbersUI(iterable<hstring> phoneNumbers) const;
    void ShowBlockedCallsUI() const;
    void ShowBlockedMessagesUI() const;
};

template <typename D>
struct WINRT_EBO impl_ICommunicationBlockingAppManagerStatics
{
    bool IsCurrentAppActiveBlockingApp() const;
    void ShowCommunicationBlockingSettingsUI() const;
};

template <typename D>
struct WINRT_EBO impl_ICommunicationBlockingAppManagerStatics2
{
    Windows::Foundation::IAsyncOperation<bool> RequestSetAsActiveBlockingAppAsync() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAccessManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::CommunicationBlocking::impl_ICommunicationBlockingAccessManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::CommunicationBlocking::impl_ICommunicationBlockingAppManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2>
{
    using abi = ABI::Windows::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2;
    template <typename D> using consume = Windows::ApplicationModel::CommunicationBlocking::impl_ICommunicationBlockingAppManagerStatics2<D>;
};

template <> struct traits<Windows::ApplicationModel::CommunicationBlocking::CommunicationBlockingAccessManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.CommunicationBlocking.CommunicationBlockingAccessManager"; }
};

template <> struct traits<Windows::ApplicationModel::CommunicationBlocking::CommunicationBlockingAppManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.CommunicationBlocking.CommunicationBlockingAppManager"; }
};

}

}
