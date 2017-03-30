// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Contacts.Provider.0.h"
#include "Windows.ApplicationModel.Contacts.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.ApplicationModel.Contacts.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Contacts::Provider {

struct __declspec(uuid("e2cc1366-cf66-43c4-a96a-a5a112db4746")) __declspec(novtable) IContactPickerUI : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AddContact(hstring id, Windows::ApplicationModel::Contacts::IContact * contact, winrt::Windows::ApplicationModel::Contacts::Provider::AddContactResult * result) = 0;
    virtual HRESULT __stdcall abi_RemoveContact(hstring id) = 0;
    virtual HRESULT __stdcall abi_ContainsContact(hstring id, bool * isContained) = 0;
    virtual HRESULT __stdcall get_DesiredFields(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_SelectionMode(winrt::Windows::ApplicationModel::Contacts::ContactSelectionMode * value) = 0;
    virtual HRESULT __stdcall add_ContactRemoved(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::Provider::ContactPickerUI, Windows::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ContactRemoved(event_token token) = 0;
};

struct __declspec(uuid("6e449e28-7b25-4999-9b0b-875400a1e8c8")) __declspec(novtable) IContactPickerUI2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AddContact(Windows::ApplicationModel::Contacts::IContact * contact, winrt::Windows::ApplicationModel::Contacts::Provider::AddContactResult * result) = 0;
    virtual HRESULT __stdcall get_DesiredFieldsWithContactFieldType(Windows::Foundation::Collections::IVector<winrt::Windows::ApplicationModel::Contacts::ContactFieldType> ** value) = 0;
};

struct __declspec(uuid("6f354338-3302-4d13-ad8d-adcc0ff9e47c")) __declspec(novtable) IContactRemovedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Contacts::Provider::ContactPickerUI> { using default_interface = Windows::ApplicationModel::Contacts::Provider::IContactPickerUI; };
template <> struct traits<Windows::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs> { using default_interface = Windows::ApplicationModel::Contacts::Provider::IContactRemovedEventArgs; };

}

namespace Windows::ApplicationModel::Contacts::Provider {

template <typename D>
struct WINRT_EBO impl_IContactPickerUI
{
    [[deprecated("AddContact may be altered or unavailable for releases after Windows 8.1. Instead, use AddContact without the ID.")]] Windows::ApplicationModel::Contacts::Provider::AddContactResult AddContact(hstring_view id, const Windows::ApplicationModel::Contacts::Contact & contact) const;
    void RemoveContact(hstring_view id) const;
    bool ContainsContact(hstring_view id) const;
    [[deprecated("DesiredFields may be altered or unavailable for releases after Windows 8.1. Instead, use DesiredFieldsWithContactFieldType.")]] Windows::Foundation::Collections::IVectorView<hstring> DesiredFields() const;
    Windows::ApplicationModel::Contacts::ContactSelectionMode SelectionMode() const;
    event_token ContactRemoved(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::Provider::ContactPickerUI, Windows::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs> & handler) const;
    using ContactRemoved_revoker = event_revoker<IContactPickerUI>;
    ContactRemoved_revoker ContactRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Contacts::Provider::ContactPickerUI, Windows::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs> & handler) const;
    void ContactRemoved(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IContactPickerUI2
{
    Windows::ApplicationModel::Contacts::Provider::AddContactResult AddContact(const Windows::ApplicationModel::Contacts::Contact & contact) const;
    Windows::Foundation::Collections::IVector<winrt::Windows::ApplicationModel::Contacts::ContactFieldType> DesiredFieldsWithContactFieldType() const;
};

template <typename D>
struct WINRT_EBO impl_IContactRemovedEventArgs
{
    hstring Id() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Contacts::Provider::IContactPickerUI>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::Provider::IContactPickerUI;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::Provider::impl_IContactPickerUI<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::Provider::IContactPickerUI2>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::Provider::IContactPickerUI2;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::Provider::impl_IContactPickerUI2<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::Provider::IContactRemovedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::Provider::IContactRemovedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Contacts::Provider::impl_IContactRemovedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Contacts::Provider::ContactPickerUI>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::Provider::ContactPickerUI;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.Provider.ContactPickerUI"; }
};

template <> struct traits<Windows::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Contacts.Provider.ContactRemovedEventArgs"; }
};

}

}
