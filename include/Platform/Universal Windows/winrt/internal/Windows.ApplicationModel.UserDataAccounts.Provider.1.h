// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.UserDataAccounts.Provider.0.h"
#include "Windows.ApplicationModel.UserDataAccounts.0.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::UserDataAccounts::Provider {

struct __declspec(uuid("5f200037-f6ef-4ec3-8630-012c59c1149f")) __declspec(novtable) IUserDataAccountPartnerAccountInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Priority(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_AccountKind(winrt::Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderPartnerAccountKind * value) = 0;
};

struct __declspec(uuid("b9c72530-3f84-4b5d-8eaa-45e97aa842ed")) __declspec(novtable) IUserDataAccountProviderAddAccountOperation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContentKinds(winrt::Windows::ApplicationModel::UserDataAccounts::UserDataAccountContentKinds * value) = 0;
    virtual HRESULT __stdcall get_PartnerAccountInfos(Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountPartnerAccountInfo> ** value) = 0;
    virtual HRESULT __stdcall abi_ReportCompleted(hstring userDataAccountId) = 0;
};

struct __declspec(uuid("a20aad63-888c-4a62-a3dd-34d07a802b2b")) __declspec(novtable) IUserDataAccountProviderOperation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Kind(winrt::Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderOperationKind * value) = 0;
};

struct __declspec(uuid("6235dc15-bfcb-41e1-9957-9759a28846cc")) __declspec(novtable) IUserDataAccountProviderResolveErrorsOperation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UserDataAccountId(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompleted() = 0;
};

struct __declspec(uuid("92034db7-8648-4f30-acfa-3002658ca80d")) __declspec(novtable) IUserDataAccountProviderSettingsOperation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UserDataAccountId(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompleted() = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountPartnerAccountInfo> { using default_interface = Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo; };
template <> struct traits<Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderAddAccountOperation> { using default_interface = Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation; };
template <> struct traits<Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderResolveErrorsOperation> { using default_interface = Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation; };
template <> struct traits<Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderSettingsOperation> { using default_interface = Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation; };

}

namespace Windows::ApplicationModel::UserDataAccounts::Provider {

template <typename D>
struct WINRT_EBO impl_IUserDataAccountPartnerAccountInfo
{
    hstring DisplayName() const;
    uint32_t Priority() const;
    Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderPartnerAccountKind AccountKind() const;
};

template <typename D>
struct WINRT_EBO impl_IUserDataAccountProviderAddAccountOperation
{
    Windows::ApplicationModel::UserDataAccounts::UserDataAccountContentKinds ContentKinds() const;
    Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountPartnerAccountInfo> PartnerAccountInfos() const;
    void ReportCompleted(hstring_view userDataAccountId) const;
};

template <typename D>
struct WINRT_EBO impl_IUserDataAccountProviderOperation
{
    Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderOperationKind Kind() const;
};

template <typename D>
struct WINRT_EBO impl_IUserDataAccountProviderResolveErrorsOperation
{
    hstring UserDataAccountId() const;
    void ReportCompleted() const;
};

template <typename D>
struct WINRT_EBO impl_IUserDataAccountProviderSettingsOperation
{
    hstring UserDataAccountId() const;
    void ReportCompleted() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo;
    template <typename D> using consume = Windows::ApplicationModel::UserDataAccounts::Provider::impl_IUserDataAccountPartnerAccountInfo<D>;
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation;
    template <typename D> using consume = Windows::ApplicationModel::UserDataAccounts::Provider::impl_IUserDataAccountProviderAddAccountOperation<D>;
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation;
    template <typename D> using consume = Windows::ApplicationModel::UserDataAccounts::Provider::impl_IUserDataAccountProviderOperation<D>;
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation;
    template <typename D> using consume = Windows::ApplicationModel::UserDataAccounts::Provider::impl_IUserDataAccountProviderResolveErrorsOperation<D>;
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation;
    template <typename D> using consume = Windows::ApplicationModel::UserDataAccounts::Provider::impl_IUserDataAccountProviderSettingsOperation<D>;
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountPartnerAccountInfo>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountPartnerAccountInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.UserDataAccounts.Provider.UserDataAccountPartnerAccountInfo"; }
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderAddAccountOperation>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderAddAccountOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.UserDataAccounts.Provider.UserDataAccountProviderAddAccountOperation"; }
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderResolveErrorsOperation>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderResolveErrorsOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.UserDataAccounts.Provider.UserDataAccountProviderResolveErrorsOperation"; }
};

template <> struct traits<Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderSettingsOperation>
{
    using abi = ABI::Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderSettingsOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.UserDataAccounts.Provider.UserDataAccountProviderSettingsOperation"; }
};

}

}
