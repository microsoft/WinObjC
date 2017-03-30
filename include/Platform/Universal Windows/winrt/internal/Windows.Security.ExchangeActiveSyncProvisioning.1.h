// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Security.ExchangeActiveSyncProvisioning.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::ExchangeActiveSyncProvisioning {

struct __declspec(uuid("54dfd981-1968-4ca3-b958-e595d16505eb")) __declspec(novtable) IEasClientDeviceInformation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(GUID * value) = 0;
    virtual HRESULT __stdcall get_OperatingSystem(hstring * value) = 0;
    virtual HRESULT __stdcall get_FriendlyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_SystemManufacturer(hstring * value) = 0;
    virtual HRESULT __stdcall get_SystemProductName(hstring * value) = 0;
    virtual HRESULT __stdcall get_SystemSku(hstring * value) = 0;
};

struct __declspec(uuid("ffb35923-bb26-4d6a-81bc-165aee0ad754")) __declspec(novtable) IEasClientDeviceInformation2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SystemHardwareVersion(hstring * value) = 0;
    virtual HRESULT __stdcall get_SystemFirmwareVersion(hstring * value) = 0;
};

struct __declspec(uuid("45b72362-dfba-4a9b-aced-6fe2adcb6420")) __declspec(novtable) IEasClientSecurityPolicy : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RequireEncryption(bool * value) = 0;
    virtual HRESULT __stdcall put_RequireEncryption(bool value) = 0;
    virtual HRESULT __stdcall get_MinPasswordLength(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_MinPasswordLength(uint8_t value) = 0;
    virtual HRESULT __stdcall get_DisallowConvenienceLogon(bool * value) = 0;
    virtual HRESULT __stdcall put_DisallowConvenienceLogon(bool value) = 0;
    virtual HRESULT __stdcall get_MinPasswordComplexCharacters(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_MinPasswordComplexCharacters(uint8_t value) = 0;
    virtual HRESULT __stdcall get_PasswordExpiration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_PasswordExpiration(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_PasswordHistory(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_PasswordHistory(uint32_t value) = 0;
    virtual HRESULT __stdcall get_MaxPasswordFailedAttempts(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_MaxPasswordFailedAttempts(uint8_t value) = 0;
    virtual HRESULT __stdcall get_MaxInactivityTimeLock(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_MaxInactivityTimeLock(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall abi_CheckCompliance(Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults ** result) = 0;
    virtual HRESULT __stdcall abi_ApplyAsync(Windows::Foundation::IAsyncOperation<Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults> ** operation) = 0;
};

struct __declspec(uuid("463c299c-7f19-4c66-b403-cb45dd57a2b3")) __declspec(novtable) IEasComplianceResults : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Compliant(bool * value) = 0;
    virtual HRESULT __stdcall get_RequireEncryptionResult(winrt::Windows::Security::ExchangeActiveSyncProvisioning::EasRequireEncryptionResult * value) = 0;
    virtual HRESULT __stdcall get_MinPasswordLengthResult(winrt::Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordLengthResult * value) = 0;
    virtual HRESULT __stdcall get_DisallowConvenienceLogonResult(winrt::Windows::Security::ExchangeActiveSyncProvisioning::EasDisallowConvenienceLogonResult * value) = 0;
    virtual HRESULT __stdcall get_MinPasswordComplexCharactersResult(winrt::Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordComplexCharactersResult * value) = 0;
    virtual HRESULT __stdcall get_PasswordExpirationResult(winrt::Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordExpirationResult * value) = 0;
    virtual HRESULT __stdcall get_PasswordHistoryResult(winrt::Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordHistoryResult * value) = 0;
    virtual HRESULT __stdcall get_MaxPasswordFailedAttemptsResult(winrt::Windows::Security::ExchangeActiveSyncProvisioning::EasMaxPasswordFailedAttemptsResult * value) = 0;
    virtual HRESULT __stdcall get_MaxInactivityTimeLockResult(winrt::Windows::Security::ExchangeActiveSyncProvisioning::EasMaxInactivityTimeLockResult * value) = 0;
};

struct __declspec(uuid("2fbe60c9-1aa8-47f5-88bb-cb3ef0bffb15")) __declspec(novtable) IEasComplianceResults2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EncryptionProviderType(winrt::Windows::Security::ExchangeActiveSyncProvisioning::EasEncryptionProviderType * value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation> { using default_interface = Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation; };
template <> struct traits<Windows::Security::ExchangeActiveSyncProvisioning::EasClientSecurityPolicy> { using default_interface = Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy; };
template <> struct traits<Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults> { using default_interface = Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults; };

}

namespace Windows::Security::ExchangeActiveSyncProvisioning {

template <typename D>
struct WINRT_EBO impl_IEasClientDeviceInformation
{
    GUID Id() const;
    hstring OperatingSystem() const;
    hstring FriendlyName() const;
    hstring SystemManufacturer() const;
    hstring SystemProductName() const;
    hstring SystemSku() const;
};

template <typename D>
struct WINRT_EBO impl_IEasClientDeviceInformation2
{
    hstring SystemHardwareVersion() const;
    hstring SystemFirmwareVersion() const;
};

template <typename D>
struct WINRT_EBO impl_IEasClientSecurityPolicy
{
    bool RequireEncryption() const;
    void RequireEncryption(bool value) const;
    uint8_t MinPasswordLength() const;
    void MinPasswordLength(uint8_t value) const;
    bool DisallowConvenienceLogon() const;
    void DisallowConvenienceLogon(bool value) const;
    uint8_t MinPasswordComplexCharacters() const;
    void MinPasswordComplexCharacters(uint8_t value) const;
    Windows::Foundation::TimeSpan PasswordExpiration() const;
    void PasswordExpiration(const Windows::Foundation::TimeSpan & value) const;
    uint32_t PasswordHistory() const;
    void PasswordHistory(uint32_t value) const;
    uint8_t MaxPasswordFailedAttempts() const;
    void MaxPasswordFailedAttempts(uint8_t value) const;
    Windows::Foundation::TimeSpan MaxInactivityTimeLock() const;
    void MaxInactivityTimeLock(const Windows::Foundation::TimeSpan & value) const;
    Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults CheckCompliance() const;
    Windows::Foundation::IAsyncOperation<Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults> ApplyAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IEasComplianceResults
{
    bool Compliant() const;
    Windows::Security::ExchangeActiveSyncProvisioning::EasRequireEncryptionResult RequireEncryptionResult() const;
    Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordLengthResult MinPasswordLengthResult() const;
    Windows::Security::ExchangeActiveSyncProvisioning::EasDisallowConvenienceLogonResult DisallowConvenienceLogonResult() const;
    Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordComplexCharactersResult MinPasswordComplexCharactersResult() const;
    Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordExpirationResult PasswordExpirationResult() const;
    Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordHistoryResult PasswordHistoryResult() const;
    Windows::Security::ExchangeActiveSyncProvisioning::EasMaxPasswordFailedAttemptsResult MaxPasswordFailedAttemptsResult() const;
    Windows::Security::ExchangeActiveSyncProvisioning::EasMaxInactivityTimeLockResult MaxInactivityTimeLockResult() const;
};

template <typename D>
struct WINRT_EBO impl_IEasComplianceResults2
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasEncryptionProviderType EncryptionProviderType() const;
};

}

namespace impl {

template <> struct traits<Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>
{
    using abi = ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation;
    template <typename D> using consume = Windows::Security::ExchangeActiveSyncProvisioning::impl_IEasClientDeviceInformation<D>;
};

template <> struct traits<Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2>
{
    using abi = ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2;
    template <typename D> using consume = Windows::Security::ExchangeActiveSyncProvisioning::impl_IEasClientDeviceInformation2<D>;
};

template <> struct traits<Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>
{
    using abi = ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy;
    template <typename D> using consume = Windows::Security::ExchangeActiveSyncProvisioning::impl_IEasClientSecurityPolicy<D>;
};

template <> struct traits<Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>
{
    using abi = ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults;
    template <typename D> using consume = Windows::Security::ExchangeActiveSyncProvisioning::impl_IEasComplianceResults<D>;
};

template <> struct traits<Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2>
{
    using abi = ABI::Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2;
    template <typename D> using consume = Windows::Security::ExchangeActiveSyncProvisioning::impl_IEasComplianceResults2<D>;
};

template <> struct traits<Windows::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation>
{
    using abi = ABI::Windows::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.ExchangeActiveSyncProvisioning.EasClientDeviceInformation"; }
};

template <> struct traits<Windows::Security::ExchangeActiveSyncProvisioning::EasClientSecurityPolicy>
{
    using abi = ABI::Windows::Security::ExchangeActiveSyncProvisioning::EasClientSecurityPolicy;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.ExchangeActiveSyncProvisioning.EasClientSecurityPolicy"; }
};

template <> struct traits<Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults>
{
    using abi = ABI::Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.ExchangeActiveSyncProvisioning.EasComplianceResults"; }
};

}

}
