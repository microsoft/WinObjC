// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Security.ExchangeActiveSyncProvisioning.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation> : produce_base<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>
{
    HRESULT __stdcall get_Id(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OperatingSystem(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OperatingSystem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FriendlyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FriendlyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemManufacturer(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemManufacturer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemProductName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemProductName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemSku(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemSku());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2> : produce_base<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2>
{
    HRESULT __stdcall get_SystemHardwareVersion(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemHardwareVersion());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemFirmwareVersion(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemFirmwareVersion());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy> : produce_base<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy>
{
    HRESULT __stdcall get_RequireEncryption(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequireEncryption());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RequireEncryption(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequireEncryption(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinPasswordLength(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinPasswordLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MinPasswordLength(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinPasswordLength(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisallowConvenienceLogon(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisallowConvenienceLogon());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisallowConvenienceLogon(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisallowConvenienceLogon(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinPasswordComplexCharacters(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinPasswordComplexCharacters());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MinPasswordComplexCharacters(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinPasswordComplexCharacters(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PasswordExpiration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PasswordExpiration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PasswordExpiration(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PasswordExpiration(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PasswordHistory(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PasswordHistory());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PasswordHistory(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PasswordHistory(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxPasswordFailedAttempts(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPasswordFailedAttempts());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxPasswordFailedAttempts(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxPasswordFailedAttempts(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxInactivityTimeLock(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxInactivityTimeLock());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxInactivityTimeLock(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxInactivityTimeLock(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CheckCompliance(impl::abi_arg_out<Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CheckCompliance());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ApplyAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ApplyAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults> : produce_base<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>
{
    HRESULT __stdcall get_Compliant(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Compliant());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RequireEncryptionResult(Windows::Security::ExchangeActiveSyncProvisioning::EasRequireEncryptionResult * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequireEncryptionResult());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinPasswordLengthResult(Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordLengthResult * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinPasswordLengthResult());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisallowConvenienceLogonResult(Windows::Security::ExchangeActiveSyncProvisioning::EasDisallowConvenienceLogonResult * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisallowConvenienceLogonResult());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinPasswordComplexCharactersResult(Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordComplexCharactersResult * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinPasswordComplexCharactersResult());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PasswordExpirationResult(Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordExpirationResult * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PasswordExpirationResult());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PasswordHistoryResult(Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordHistoryResult * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PasswordHistoryResult());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxPasswordFailedAttemptsResult(Windows::Security::ExchangeActiveSyncProvisioning::EasMaxPasswordFailedAttemptsResult * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxPasswordFailedAttemptsResult());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxInactivityTimeLockResult(Windows::Security::ExchangeActiveSyncProvisioning::EasMaxInactivityTimeLockResult * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxInactivityTimeLockResult());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2> : produce_base<D, Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2>
{
    HRESULT __stdcall get_EncryptionProviderType(Windows::Security::ExchangeActiveSyncProvisioning::EasEncryptionProviderType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EncryptionProviderType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Security::ExchangeActiveSyncProvisioning {

template <typename D> GUID impl_IEasClientDeviceInformation<D>::Id() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IEasClientDeviceInformation)->get_Id(&value));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation<D>::OperatingSystem() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEasClientDeviceInformation)->get_OperatingSystem(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation<D>::FriendlyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEasClientDeviceInformation)->get_FriendlyName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation<D>::SystemManufacturer() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEasClientDeviceInformation)->get_SystemManufacturer(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation<D>::SystemProductName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEasClientDeviceInformation)->get_SystemProductName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation<D>::SystemSku() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEasClientDeviceInformation)->get_SystemSku(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation2<D>::SystemHardwareVersion() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEasClientDeviceInformation2)->get_SystemHardwareVersion(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IEasClientDeviceInformation2<D>::SystemFirmwareVersion() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IEasClientDeviceInformation2)->get_SystemFirmwareVersion(put_abi(value)));
    return value;
}

template <typename D> bool impl_IEasClientSecurityPolicy<D>::RequireEncryption() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->get_RequireEncryption(&value));
    return value;
}

template <typename D> void impl_IEasClientSecurityPolicy<D>::RequireEncryption(bool value) const
{
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->put_RequireEncryption(value));
}

template <typename D> uint8_t impl_IEasClientSecurityPolicy<D>::MinPasswordLength() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->get_MinPasswordLength(&value));
    return value;
}

template <typename D> void impl_IEasClientSecurityPolicy<D>::MinPasswordLength(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->put_MinPasswordLength(value));
}

template <typename D> bool impl_IEasClientSecurityPolicy<D>::DisallowConvenienceLogon() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->get_DisallowConvenienceLogon(&value));
    return value;
}

template <typename D> void impl_IEasClientSecurityPolicy<D>::DisallowConvenienceLogon(bool value) const
{
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->put_DisallowConvenienceLogon(value));
}

template <typename D> uint8_t impl_IEasClientSecurityPolicy<D>::MinPasswordComplexCharacters() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->get_MinPasswordComplexCharacters(&value));
    return value;
}

template <typename D> void impl_IEasClientSecurityPolicy<D>::MinPasswordComplexCharacters(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->put_MinPasswordComplexCharacters(value));
}

template <typename D> Windows::Foundation::TimeSpan impl_IEasClientSecurityPolicy<D>::PasswordExpiration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->get_PasswordExpiration(put_abi(value)));
    return value;
}

template <typename D> void impl_IEasClientSecurityPolicy<D>::PasswordExpiration(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->put_PasswordExpiration(get_abi(value)));
}

template <typename D> uint32_t impl_IEasClientSecurityPolicy<D>::PasswordHistory() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->get_PasswordHistory(&value));
    return value;
}

template <typename D> void impl_IEasClientSecurityPolicy<D>::PasswordHistory(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->put_PasswordHistory(value));
}

template <typename D> uint8_t impl_IEasClientSecurityPolicy<D>::MaxPasswordFailedAttempts() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->get_MaxPasswordFailedAttempts(&value));
    return value;
}

template <typename D> void impl_IEasClientSecurityPolicy<D>::MaxPasswordFailedAttempts(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->put_MaxPasswordFailedAttempts(value));
}

template <typename D> Windows::Foundation::TimeSpan impl_IEasClientSecurityPolicy<D>::MaxInactivityTimeLock() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->get_MaxInactivityTimeLock(put_abi(value)));
    return value;
}

template <typename D> void impl_IEasClientSecurityPolicy<D>::MaxInactivityTimeLock(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->put_MaxInactivityTimeLock(get_abi(value)));
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults impl_IEasClientSecurityPolicy<D>::CheckCompliance() const
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults result { nullptr };
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->abi_CheckCompliance(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults> impl_IEasClientSecurityPolicy<D>::ApplyAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults> operation;
    check_hresult(WINRT_SHIM(IEasClientSecurityPolicy)->abi_ApplyAsync(put_abi(operation)));
    return operation;
}

template <typename D> bool impl_IEasComplianceResults<D>::Compliant() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IEasComplianceResults)->get_Compliant(&value));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasRequireEncryptionResult impl_IEasComplianceResults<D>::RequireEncryptionResult() const
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasRequireEncryptionResult value {};
    check_hresult(WINRT_SHIM(IEasComplianceResults)->get_RequireEncryptionResult(&value));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordLengthResult impl_IEasComplianceResults<D>::MinPasswordLengthResult() const
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordLengthResult value {};
    check_hresult(WINRT_SHIM(IEasComplianceResults)->get_MinPasswordLengthResult(&value));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasDisallowConvenienceLogonResult impl_IEasComplianceResults<D>::DisallowConvenienceLogonResult() const
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasDisallowConvenienceLogonResult value {};
    check_hresult(WINRT_SHIM(IEasComplianceResults)->get_DisallowConvenienceLogonResult(&value));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordComplexCharactersResult impl_IEasComplianceResults<D>::MinPasswordComplexCharactersResult() const
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasMinPasswordComplexCharactersResult value {};
    check_hresult(WINRT_SHIM(IEasComplianceResults)->get_MinPasswordComplexCharactersResult(&value));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordExpirationResult impl_IEasComplianceResults<D>::PasswordExpirationResult() const
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordExpirationResult value {};
    check_hresult(WINRT_SHIM(IEasComplianceResults)->get_PasswordExpirationResult(&value));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordHistoryResult impl_IEasComplianceResults<D>::PasswordHistoryResult() const
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasPasswordHistoryResult value {};
    check_hresult(WINRT_SHIM(IEasComplianceResults)->get_PasswordHistoryResult(&value));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasMaxPasswordFailedAttemptsResult impl_IEasComplianceResults<D>::MaxPasswordFailedAttemptsResult() const
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasMaxPasswordFailedAttemptsResult value {};
    check_hresult(WINRT_SHIM(IEasComplianceResults)->get_MaxPasswordFailedAttemptsResult(&value));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasMaxInactivityTimeLockResult impl_IEasComplianceResults<D>::MaxInactivityTimeLockResult() const
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasMaxInactivityTimeLockResult value {};
    check_hresult(WINRT_SHIM(IEasComplianceResults)->get_MaxInactivityTimeLockResult(&value));
    return value;
}

template <typename D> Windows::Security::ExchangeActiveSyncProvisioning::EasEncryptionProviderType impl_IEasComplianceResults2<D>::EncryptionProviderType() const
{
    Windows::Security::ExchangeActiveSyncProvisioning::EasEncryptionProviderType value {};
    check_hresult(WINRT_SHIM(IEasComplianceResults2)->get_EncryptionProviderType(&value));
    return value;
}

inline EasClientDeviceInformation::EasClientDeviceInformation() :
    EasClientDeviceInformation(activate_instance<EasClientDeviceInformation>())
{}

inline EasClientSecurityPolicy::EasClientSecurityPolicy() :
    EasClientSecurityPolicy(activate_instance<EasClientSecurityPolicy>())
{}

}

}
#pragma warning(pop)
