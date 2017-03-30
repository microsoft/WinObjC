// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Security.Authentication.Identity.Core.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::Authentication::Identity::Core {

struct __declspec(uuid("0fd340a5-f574-4320-a08e-0a19a82322aa")) __declspec(novtable) IMicrosoftAccountMultiFactorAuthenticationManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetOneTimePassCodeAsync(hstring userAccountId, uint32_t codeLength, Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_AddDeviceAsync(hstring userAccountId, hstring authenticationToken, hstring wnsChannelId, Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_RemoveDeviceAsync(hstring userAccountId, Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_UpdateWnsChannelAsync(hstring userAccountId, hstring channelUri, Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_GetSessionsAsync(Windows::Foundation::Collections::IIterable<hstring> * userAccountIdList, Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_GetSessionsAndUnregisteredAccountsAsync(Windows::Foundation::Collections::IIterable<hstring> * userAccountIdList, Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_ApproveSessionUsingAuthSessionInfoAsync(winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus sessionAuthentictionStatus, Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo * authenticationSessionInfo, Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_ApproveSessionAsync(winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus sessionAuthentictionStatus, hstring userAccountId, hstring sessionId, winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType sessionAuthenticationType, Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_DenySessionUsingAuthSessionInfoAsync(Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo * authenticationSessionInfo, Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_DenySessionAsync(hstring userAccountId, hstring sessionId, winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType sessionAuthenticationType, Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> ** asyncOperation) = 0;
};

struct __declspec(uuid("d964c2e6-f446-4c71-8b79-6ea4024aa9b8")) __declspec(novtable) IMicrosoftAccountMultiFactorAuthenticatorStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Current(Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager ** value) = 0;
};

struct __declspec(uuid("4e23a9a0-e9fa-497a-95de-6d5747bf974c")) __declspec(novtable) IMicrosoftAccountMultiFactorGetSessionsResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Sessions(Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo> ** value) = 0;
    virtual HRESULT __stdcall get_ServiceResponse(winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse * value) = 0;
};

struct __declspec(uuid("82ba264b-d87c-4668-a976-40cfae547d08")) __declspec(novtable) IMicrosoftAccountMultiFactorOneTimeCodedInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Code(hstring * value) = 0;
    virtual HRESULT __stdcall get_TimeInterval(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_TimeToLive(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_ServiceResponse(winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse * value) = 0;
};

struct __declspec(uuid("5f7eabb4-a278-4635-b765-b494eb260af4")) __declspec(novtable) IMicrosoftAccountMultiFactorSessionInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UserAccountId(hstring * value) = 0;
    virtual HRESULT __stdcall get_SessionId(hstring * value) = 0;
    virtual HRESULT __stdcall get_DisplaySessionId(hstring * value) = 0;
    virtual HRESULT __stdcall get_ApprovalStatus(winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionApprovalStatus * value) = 0;
    virtual HRESULT __stdcall get_AuthenticationType(winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType * value) = 0;
    virtual HRESULT __stdcall get_RequestTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_ExpirationTime(Windows::Foundation::DateTime * value) = 0;
};

struct __declspec(uuid("aa7ec5fb-da3f-4088-a20d-5618afadb2e5")) __declspec(novtable) IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Sessions(Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo> ** value) = 0;
    virtual HRESULT __stdcall get_UnregisteredAccounts(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_ServiceResponse(winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager> { using default_interface = Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager; };
template <> struct traits<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult> { using default_interface = Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult; };
template <> struct traits<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo> { using default_interface = Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo; };
template <> struct traits<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo> { using default_interface = Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo; };
template <> struct traits<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> { using default_interface = Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo; };

}

namespace Windows::Security::Authentication::Identity::Core {

template <typename D>
struct WINRT_EBO impl_IMicrosoftAccountMultiFactorAuthenticationManager
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo> GetOneTimePassCodeAsync(hstring_view userAccountId, uint32_t codeLength) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> AddDeviceAsync(hstring_view userAccountId, hstring_view authenticationToken, hstring_view wnsChannelId) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> RemoveDeviceAsync(hstring_view userAccountId) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> UpdateWnsChannelAsync(hstring_view userAccountId, hstring_view channelUri) const;
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult> GetSessionsAsync(iterable<hstring> userAccountIdList) const;
    Windows::Foundation::IAsyncOperation<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo> GetSessionsAndUnregisteredAccountsAsync(iterable<hstring> userAccountIdList) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> ApproveSessionAsync(Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus sessionAuthentictionStatus, const Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo & authenticationSessionInfo) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> ApproveSessionAsync(Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionAuthenticationStatus sessionAuthentictionStatus, hstring_view userAccountId, hstring_view sessionId, Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType sessionAuthenticationType) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> DenySessionAsync(const Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo & authenticationSessionInfo) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse> DenySessionAsync(hstring_view userAccountId, hstring_view sessionId, Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType sessionAuthenticationType) const;
};

template <typename D>
struct WINRT_EBO impl_IMicrosoftAccountMultiFactorAuthenticatorStatics
{
    Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager Current() const;
};

template <typename D>
struct WINRT_EBO impl_IMicrosoftAccountMultiFactorGetSessionsResult
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo> Sessions() const;
    Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse ServiceResponse() const;
};

template <typename D>
struct WINRT_EBO impl_IMicrosoftAccountMultiFactorOneTimeCodedInfo
{
    hstring Code() const;
    Windows::Foundation::TimeSpan TimeInterval() const;
    Windows::Foundation::TimeSpan TimeToLive() const;
    Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse ServiceResponse() const;
};

template <typename D>
struct WINRT_EBO impl_IMicrosoftAccountMultiFactorSessionInfo
{
    hstring UserAccountId() const;
    hstring SessionId() const;
    hstring DisplaySessionId() const;
    Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionApprovalStatus ApprovalStatus() const;
    Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationType AuthenticationType() const;
    Windows::Foundation::DateTime RequestTime() const;
    Windows::Foundation::DateTime ExpirationTime() const;
};

template <typename D>
struct WINRT_EBO impl_IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo
{
    Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo> Sessions() const;
    Windows::Foundation::Collections::IVectorView<hstring> UnregisteredAccounts() const;
    Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorServiceResponse ServiceResponse() const;
};

}

namespace impl {

template <> struct traits<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticationManager;
    template <typename D> using consume = Windows::Security::Authentication::Identity::Core::impl_IMicrosoftAccountMultiFactorAuthenticationManager<D>;
};

template <> struct traits<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorAuthenticatorStatics;
    template <typename D> using consume = Windows::Security::Authentication::Identity::Core::impl_IMicrosoftAccountMultiFactorAuthenticatorStatics<D>;
};

template <> struct traits<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorGetSessionsResult;
    template <typename D> using consume = Windows::Security::Authentication::Identity::Core::impl_IMicrosoftAccountMultiFactorGetSessionsResult<D>;
};

template <> struct traits<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorOneTimeCodedInfo;
    template <typename D> using consume = Windows::Security::Authentication::Identity::Core::impl_IMicrosoftAccountMultiFactorOneTimeCodedInfo<D>;
};

template <> struct traits<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorSessionInfo;
    template <typename D> using consume = Windows::Security::Authentication::Identity::Core::impl_IMicrosoftAccountMultiFactorSessionInfo<D>;
};

template <> struct traits<Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Core::IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo;
    template <typename D> using consume = Windows::Security::Authentication::Identity::Core::impl_IMicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo<D>;
};

template <> struct traits<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorAuthenticationManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorAuthenticationManager"; }
};

template <> struct traits<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorGetSessionsResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorGetSessionsResult"; }
};

template <> struct traits<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorOneTimeCodedInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorOneTimeCodedInfo"; }
};

template <> struct traits<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorSessionInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorSessionInfo"; }
};

template <> struct traits<Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo>
{
    using abi = ABI::Windows::Security::Authentication::Identity::Core::MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Authentication.Identity.Core.MicrosoftAccountMultiFactorUnregisteredAccountsAndSessionInfo"; }
};

}

}
