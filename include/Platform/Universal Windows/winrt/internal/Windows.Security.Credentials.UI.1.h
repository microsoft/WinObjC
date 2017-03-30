// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Security.Credentials.UI.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::Credentials::UI {

struct __declspec(uuid("965a0b4c-95fa-467f-992b-0b22e5859bf6")) __declspec(novtable) ICredentialPickerOptions : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Caption(hstring value) = 0;
    virtual HRESULT __stdcall get_Caption(hstring * value) = 0;
    virtual HRESULT __stdcall put_Message(hstring value) = 0;
    virtual HRESULT __stdcall get_Message(hstring * value) = 0;
    virtual HRESULT __stdcall put_ErrorCode(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ErrorCode(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_TargetName(hstring value) = 0;
    virtual HRESULT __stdcall get_TargetName(hstring * value) = 0;
    virtual HRESULT __stdcall put_AuthenticationProtocol(winrt::Windows::Security::Credentials::UI::AuthenticationProtocol value) = 0;
    virtual HRESULT __stdcall get_AuthenticationProtocol(winrt::Windows::Security::Credentials::UI::AuthenticationProtocol * value) = 0;
    virtual HRESULT __stdcall put_CustomAuthenticationProtocol(hstring value) = 0;
    virtual HRESULT __stdcall get_CustomAuthenticationProtocol(hstring * value) = 0;
    virtual HRESULT __stdcall put_PreviousCredential(Windows::Storage::Streams::IBuffer * value) = 0;
    virtual HRESULT __stdcall get_PreviousCredential(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_AlwaysDisplayDialog(bool value) = 0;
    virtual HRESULT __stdcall get_AlwaysDisplayDialog(bool * value) = 0;
    virtual HRESULT __stdcall put_CallerSavesCredential(bool value) = 0;
    virtual HRESULT __stdcall get_CallerSavesCredential(bool * value) = 0;
    virtual HRESULT __stdcall put_CredentialSaveOption(winrt::Windows::Security::Credentials::UI::CredentialSaveOption value) = 0;
    virtual HRESULT __stdcall get_CredentialSaveOption(winrt::Windows::Security::Credentials::UI::CredentialSaveOption * value) = 0;
};

struct __declspec(uuid("1948f99a-cc30-410c-9c38-cc0884c5b3d7")) __declspec(novtable) ICredentialPickerResults : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ErrorCode(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_CredentialSaveOption(winrt::Windows::Security::Credentials::UI::CredentialSaveOption * value) = 0;
    virtual HRESULT __stdcall get_CredentialSaved(bool * value) = 0;
    virtual HRESULT __stdcall get_Credential(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall get_CredentialDomainName(hstring * value) = 0;
    virtual HRESULT __stdcall get_CredentialUserName(hstring * value) = 0;
    virtual HRESULT __stdcall get_CredentialPassword(hstring * value) = 0;
};

struct __declspec(uuid("aa3a5c73-c9ea-4782-99fb-e6d7e938e12d")) __declspec(novtable) ICredentialPickerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_PickWithOptionsAsync(Windows::Security::Credentials::UI::ICredentialPickerOptions * options, Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> ** operation) = 0;
    virtual HRESULT __stdcall abi_PickWithMessageAsync(hstring targetName, hstring message, Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> ** operation) = 0;
    virtual HRESULT __stdcall abi_PickWithCaptionAsync(hstring targetName, hstring message, hstring caption, Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> ** operation) = 0;
};

struct __declspec(uuid("af4f3f91-564c-4ddc-b8b5-973447627c65")) __declspec(novtable) IUserConsentVerifierStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CheckAvailabilityAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerifierAvailability> ** result) = 0;
    virtual HRESULT __stdcall abi_RequestVerificationAsync(hstring message, Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerificationResult> ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Security::Credentials::UI::CredentialPickerOptions> { using default_interface = Windows::Security::Credentials::UI::ICredentialPickerOptions; };
template <> struct traits<Windows::Security::Credentials::UI::CredentialPickerResults> { using default_interface = Windows::Security::Credentials::UI::ICredentialPickerResults; };

}

namespace Windows::Security::Credentials::UI {

template <typename D>
struct WINRT_EBO impl_ICredentialPickerOptions
{
    void Caption(hstring_view value) const;
    hstring Caption() const;
    void Message(hstring_view value) const;
    hstring Message() const;
    void ErrorCode(uint32_t value) const;
    uint32_t ErrorCode() const;
    void TargetName(hstring_view value) const;
    hstring TargetName() const;
    void AuthenticationProtocol(Windows::Security::Credentials::UI::AuthenticationProtocol value) const;
    Windows::Security::Credentials::UI::AuthenticationProtocol AuthenticationProtocol() const;
    void CustomAuthenticationProtocol(hstring_view value) const;
    hstring CustomAuthenticationProtocol() const;
    void PreviousCredential(const Windows::Storage::Streams::IBuffer & value) const;
    Windows::Storage::Streams::IBuffer PreviousCredential() const;
    void AlwaysDisplayDialog(bool value) const;
    bool AlwaysDisplayDialog() const;
    void CallerSavesCredential(bool value) const;
    bool CallerSavesCredential() const;
    void CredentialSaveOption(Windows::Security::Credentials::UI::CredentialSaveOption value) const;
    Windows::Security::Credentials::UI::CredentialSaveOption CredentialSaveOption() const;
};

template <typename D>
struct WINRT_EBO impl_ICredentialPickerResults
{
    uint32_t ErrorCode() const;
    Windows::Security::Credentials::UI::CredentialSaveOption CredentialSaveOption() const;
    bool CredentialSaved() const;
    Windows::Storage::Streams::IBuffer Credential() const;
    hstring CredentialDomainName() const;
    hstring CredentialUserName() const;
    hstring CredentialPassword() const;
};

template <typename D>
struct WINRT_EBO impl_ICredentialPickerStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> PickAsync(const Windows::Security::Credentials::UI::CredentialPickerOptions & options) const;
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> PickAsync(hstring_view targetName, hstring_view message) const;
    Windows::Foundation::IAsyncOperation<Windows::Security::Credentials::UI::CredentialPickerResults> PickAsync(hstring_view targetName, hstring_view message, hstring_view caption) const;
};

template <typename D>
struct WINRT_EBO impl_IUserConsentVerifierStatics
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerifierAvailability> CheckAvailabilityAsync() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Security::Credentials::UI::UserConsentVerificationResult> RequestVerificationAsync(hstring_view message) const;
};

}

namespace impl {

template <> struct traits<Windows::Security::Credentials::UI::ICredentialPickerOptions>
{
    using abi = ABI::Windows::Security::Credentials::UI::ICredentialPickerOptions;
    template <typename D> using consume = Windows::Security::Credentials::UI::impl_ICredentialPickerOptions<D>;
};

template <> struct traits<Windows::Security::Credentials::UI::ICredentialPickerResults>
{
    using abi = ABI::Windows::Security::Credentials::UI::ICredentialPickerResults;
    template <typename D> using consume = Windows::Security::Credentials::UI::impl_ICredentialPickerResults<D>;
};

template <> struct traits<Windows::Security::Credentials::UI::ICredentialPickerStatics>
{
    using abi = ABI::Windows::Security::Credentials::UI::ICredentialPickerStatics;
    template <typename D> using consume = Windows::Security::Credentials::UI::impl_ICredentialPickerStatics<D>;
};

template <> struct traits<Windows::Security::Credentials::UI::IUserConsentVerifierStatics>
{
    using abi = ABI::Windows::Security::Credentials::UI::IUserConsentVerifierStatics;
    template <typename D> using consume = Windows::Security::Credentials::UI::impl_IUserConsentVerifierStatics<D>;
};

template <> struct traits<Windows::Security::Credentials::UI::CredentialPicker>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Credentials.UI.CredentialPicker"; }
};

template <> struct traits<Windows::Security::Credentials::UI::CredentialPickerOptions>
{
    using abi = ABI::Windows::Security::Credentials::UI::CredentialPickerOptions;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Credentials.UI.CredentialPickerOptions"; }
};

template <> struct traits<Windows::Security::Credentials::UI::CredentialPickerResults>
{
    using abi = ABI::Windows::Security::Credentials::UI::CredentialPickerResults;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Credentials.UI.CredentialPickerResults"; }
};

template <> struct traits<Windows::Security::Credentials::UI::UserConsentVerifier>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Credentials.UI.UserConsentVerifier"; }
};

}

}
