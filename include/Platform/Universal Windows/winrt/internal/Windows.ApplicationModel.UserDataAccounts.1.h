// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.UserDataAccounts.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.System.0.h"
#include "Windows.ApplicationModel.Appointments.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.ApplicationModel.Email.1.h"
#include "Windows.ApplicationModel.Contacts.1.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::UserDataAccounts {

struct __declspec(uuid("b9c4367e-b348-4910-be94-4ad4bba6dea7")) __declspec(novtable) IUserDataAccount : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall get_UserDisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall put_UserDisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_OtherAppReadAccess(winrt::Windows::ApplicationModel::UserDataAccounts::UserDataAccountOtherAppReadAccess * value) = 0;
    virtual HRESULT __stdcall put_OtherAppReadAccess(winrt::Windows::ApplicationModel::UserDataAccounts::UserDataAccountOtherAppReadAccess value) = 0;
    virtual HRESULT __stdcall get_Icon(Windows::Storage::Streams::IRandomAccessStreamReference ** value) = 0;
    virtual HRESULT __stdcall get_DeviceAccountTypeId(hstring * value) = 0;
    virtual HRESULT __stdcall get_PackageFamilyName(hstring * value) = 0;
    virtual HRESULT __stdcall abi_SaveAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_DeleteAsync(Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_FindAppointmentCalendarsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentCalendar>> ** result) = 0;
    virtual HRESULT __stdcall abi_FindEmailMailboxesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailbox>> ** result) = 0;
    virtual HRESULT __stdcall abi_FindContactListsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactList>> ** result) = 0;
    virtual HRESULT __stdcall abi_FindContactAnnotationListsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotationList>> ** result) = 0;
};

struct __declspec(uuid("078cd89f-de82-404b-8195-c8a3ac198f60")) __declspec(novtable) IUserDataAccount2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EnterpriseId(hstring * value) = 0;
    virtual HRESULT __stdcall get_IsProtectedUnderLock(bool * value) = 0;
};

struct __declspec(uuid("01533845-6c43-4286-9d69-3e1709a1f266")) __declspec(novtable) IUserDataAccount3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ExplictReadAccessPackageFamilyNames(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayName(hstring value) = 0;
};

struct __declspec(uuid("56a6e8db-db8f-41ab-a65f-8c5971aac982")) __declspec(novtable) IUserDataAccountManagerForUser : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestStoreAsync(winrt::Windows::ApplicationModel::UserDataAccounts::UserDataAccountStoreAccessType storeAccessType, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::UserDataAccountStore> ** result) = 0;
    virtual HRESULT __stdcall get_User(Windows::System::IUser ** value) = 0;
};

struct __declspec(uuid("0d9b89ea-1928-4a20-86d5-3c737f7dc3b0")) __declspec(novtable) IUserDataAccountManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RequestStoreAsync(winrt::Windows::ApplicationModel::UserDataAccounts::UserDataAccountStoreAccessType storeAccessType, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::UserDataAccountStore> ** result) = 0;
    virtual HRESULT __stdcall abi_ShowAddAccountAsync(winrt::Windows::ApplicationModel::UserDataAccounts::UserDataAccountContentKinds contentKinds, Windows::Foundation::IAsyncOperation<hstring> ** result) = 0;
    virtual HRESULT __stdcall abi_ShowAccountSettingsAsync(hstring id, Windows::Foundation::IAsyncAction ** result) = 0;
    virtual HRESULT __stdcall abi_ShowAccountErrorResolverAsync(hstring id, Windows::Foundation::IAsyncAction ** result) = 0;
};

struct __declspec(uuid("6a3ded88-316b-435e-b534-f7d4b4b7dba6")) __declspec(novtable) IUserDataAccountManagerStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetForUser(Windows::System::IUser * user, Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerForUser ** result) = 0;
};

struct __declspec(uuid("2073b0ad-7d0a-4e76-bf45-2368f978a59a")) __declspec(novtable) IUserDataAccountStore : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FindAccountsAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::UserDataAccounts::UserDataAccount>> ** result) = 0;
    virtual HRESULT __stdcall abi_GetAccountAsync(hstring id, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::UserDataAccount> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateAccountAsync(hstring userDisplayName, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::UserDataAccount> ** result) = 0;
};

struct __declspec(uuid("b1e0aef7-9560-4631-8af0-061d30161469")) __declspec(novtable) IUserDataAccountStore2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateAccountWithPackageRelativeAppIdAsync(hstring userDisplayName, hstring packageRelativeAppId, Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::UserDataAccount> ** result) = 0;
    virtual HRESULT __stdcall add_StoreChanged(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::UserDataAccounts::UserDataAccountStore, Windows::ApplicationModel::UserDataAccounts::UserDataAccountStoreChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_StoreChanged(event_token token) = 0;
};

struct __declspec(uuid("84e3e2e5-8820-4512-b1f6-2e035be1072c")) __declspec(novtable) IUserDataAccountStoreChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::UserDataAccount> { using default_interface = Windows::ApplicationModel::UserDataAccounts::IUserDataAccount; };
template <> struct traits<Windows::ApplicationModel::UserDataAccounts::UserDataAccountManagerForUser> { using default_interface = Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerForUser; };
template <> struct traits<Windows::ApplicationModel::UserDataAccounts::UserDataAccountStore> { using default_interface = Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore; };
template <> struct traits<Windows::ApplicationModel::UserDataAccounts::UserDataAccountStoreChangedEventArgs> { using default_interface = Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStoreChangedEventArgs; };

}

namespace Windows::ApplicationModel::UserDataAccounts {

template <typename D>
struct WINRT_EBO impl_IUserDataAccount
{
    hstring Id() const;
    hstring UserDisplayName() const;
    void UserDisplayName(hstring_view value) const;
    Windows::ApplicationModel::UserDataAccounts::UserDataAccountOtherAppReadAccess OtherAppReadAccess() const;
    void OtherAppReadAccess(Windows::ApplicationModel::UserDataAccounts::UserDataAccountOtherAppReadAccess value) const;
    Windows::Storage::Streams::IRandomAccessStreamReference Icon() const;
    hstring DeviceAccountTypeId() const;
    hstring PackageFamilyName() const;
    Windows::Foundation::IAsyncAction SaveAsync() const;
    Windows::Foundation::IAsyncAction DeleteAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentCalendar>> FindAppointmentCalendarsAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailbox>> FindEmailMailboxesAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactList>> FindContactListsAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Contacts::ContactAnnotationList>> FindContactAnnotationListsAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IUserDataAccount2
{
    hstring EnterpriseId() const;
    bool IsProtectedUnderLock() const;
};

template <typename D>
struct WINRT_EBO impl_IUserDataAccount3
{
    Windows::Foundation::Collections::IVector<hstring> ExplictReadAccessPackageFamilyNames() const;
    hstring DisplayName() const;
    void DisplayName(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IUserDataAccountManagerForUser
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::UserDataAccountStore> RequestStoreAsync(Windows::ApplicationModel::UserDataAccounts::UserDataAccountStoreAccessType storeAccessType) const;
    Windows::System::User User() const;
};

template <typename D>
struct WINRT_EBO impl_IUserDataAccountManagerStatics
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::UserDataAccountStore> RequestStoreAsync(Windows::ApplicationModel::UserDataAccounts::UserDataAccountStoreAccessType storeAccessType) const;
    Windows::Foundation::IAsyncOperation<hstring> ShowAddAccountAsync(Windows::ApplicationModel::UserDataAccounts::UserDataAccountContentKinds contentKinds) const;
    Windows::Foundation::IAsyncAction ShowAccountSettingsAsync(hstring_view id) const;
    Windows::Foundation::IAsyncAction ShowAccountErrorResolverAsync(hstring_view id) const;
};

template <typename D>
struct WINRT_EBO impl_IUserDataAccountManagerStatics2
{
    Windows::ApplicationModel::UserDataAccounts::UserDataAccountManagerForUser GetForUser(const Windows::System::User & user) const;
};

template <typename D>
struct WINRT_EBO impl_IUserDataAccountStore
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::UserDataAccounts::UserDataAccount>> FindAccountsAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::UserDataAccount> GetAccountAsync(hstring_view id) const;
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::UserDataAccount> CreateAccountAsync(hstring_view userDisplayName) const;
};

template <typename D>
struct WINRT_EBO impl_IUserDataAccountStore2
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::UserDataAccount> CreateAccountAsync(hstring_view userDisplayName, hstring_view packageRelativeAppId) const;
    event_token StoreChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::UserDataAccounts::UserDataAccountStore, Windows::ApplicationModel::UserDataAccounts::UserDataAccountStoreChangedEventArgs> & handler) const;
    using StoreChanged_revoker = event_revoker<IUserDataAccountStore2>;
    StoreChanged_revoker StoreChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::UserDataAccounts::UserDataAccountStore, Windows::ApplicationModel::UserDataAccounts::UserDataAccountStoreChangedEventArgs> & handler) const;
    void StoreChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IUserDataAccountStoreChangedEventArgs
{
    Windows::Foundation::Deferral GetDeferral() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::IUserDataAccount>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::IUserDataAccount;
    template <typename D> using consume = Windows::ApplicationModel::UserDataAccounts::impl_IUserDataAccount<D>;
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::IUserDataAccount2>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::IUserDataAccount2;
    template <typename D> using consume = Windows::ApplicationModel::UserDataAccounts::impl_IUserDataAccount2<D>;
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::IUserDataAccount3>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::IUserDataAccount3;
    template <typename D> using consume = Windows::ApplicationModel::UserDataAccounts::impl_IUserDataAccount3<D>;
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerForUser>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerForUser;
    template <typename D> using consume = Windows::ApplicationModel::UserDataAccounts::impl_IUserDataAccountManagerForUser<D>;
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics;
    template <typename D> using consume = Windows::ApplicationModel::UserDataAccounts::impl_IUserDataAccountManagerStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics2>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::IUserDataAccountManagerStatics2;
    template <typename D> using consume = Windows::ApplicationModel::UserDataAccounts::impl_IUserDataAccountManagerStatics2<D>;
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore;
    template <typename D> using consume = Windows::ApplicationModel::UserDataAccounts::impl_IUserDataAccountStore<D>;
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore2>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStore2;
    template <typename D> using consume = Windows::ApplicationModel::UserDataAccounts::impl_IUserDataAccountStore2<D>;
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStoreChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::IUserDataAccountStoreChangedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::UserDataAccounts::impl_IUserDataAccountStoreChangedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::UserDataAccount>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::UserDataAccount;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.UserDataAccounts.UserDataAccount"; }
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::UserDataAccountManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.UserDataAccounts.UserDataAccountManager"; }
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::UserDataAccountManagerForUser>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::UserDataAccountManagerForUser;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.UserDataAccounts.UserDataAccountManagerForUser"; }
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::UserDataAccountStore>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::UserDataAccountStore;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.UserDataAccounts.UserDataAccountStore"; }
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::UserDataAccountStoreChangedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::UserDataAccountStoreChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.UserDataAccounts.UserDataAccountStoreChangedEventArgs"; }
};

}

}
