// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Security.Credentials.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.ApplicationModel.UserDataAccounts.SystemAccess.3.h"
#include "Windows.ApplicationModel.UserDataAccounts.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration> : produce_base<D, Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration>
{
    HRESULT __stdcall get_AccountName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccountName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AccountName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccountName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceAccountTypeId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceAccountTypeId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DeviceAccountTypeId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeviceAccountTypeId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServerType(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountServerType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ServerType(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountServerType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServerType(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EmailAddress(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EmailAddress(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EmailAddress(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Domain(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Domain());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Domain(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Domain(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EmailSyncEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EmailSyncEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EmailSyncEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EmailSyncEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ContactsSyncEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContactsSyncEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ContactsSyncEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContactsSyncEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CalendarSyncEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CalendarSyncEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CalendarSyncEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CalendarSyncEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncomingServerAddress(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncomingServerAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IncomingServerAddress(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncomingServerAddress(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncomingServerPort(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncomingServerPort());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IncomingServerPort(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncomingServerPort(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncomingServerRequiresSsl(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncomingServerRequiresSsl());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IncomingServerRequiresSsl(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncomingServerRequiresSsl(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncomingServerUsername(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncomingServerUsername());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IncomingServerUsername(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncomingServerUsername(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutgoingServerAddress(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutgoingServerAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutgoingServerAddress(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutgoingServerAddress(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutgoingServerPort(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutgoingServerPort());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutgoingServerPort(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutgoingServerPort(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutgoingServerRequiresSsl(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutgoingServerRequiresSsl());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutgoingServerRequiresSsl(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutgoingServerRequiresSsl(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutgoingServerUsername(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutgoingServerUsername());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutgoingServerUsername(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutgoingServerUsername(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2> : produce_base<D, Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration2>
{
    HRESULT __stdcall get_IncomingServerCredential(impl::abi_arg_out<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncomingServerCredential());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IncomingServerCredential(impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncomingServerCredential(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutgoingServerCredential(impl::abi_arg_out<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutgoingServerCredential());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutgoingServerCredential(impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutgoingServerCredential(*reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OAuthRefreshToken(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OAuthRefreshToken());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OAuthRefreshToken(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OAuthRefreshToken(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsExternallyManaged(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsExternallyManaged());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsExternallyManaged(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsExternallyManaged(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccountIconId(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountIconId * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AccountIconId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AccountIconId(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountIconId value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccountIconId(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AuthenticationType(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountAuthenticationType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AuthenticationType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AuthenticationType(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountAuthenticationType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthenticationType(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSsoAuthenticationSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSsoAuthenticationSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SsoAccountId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SsoAccountId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SsoAccountId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SsoAccountId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlwaysDownloadFullMessage(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlwaysDownloadFullMessage());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AlwaysDownloadFullMessage(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlwaysDownloadFullMessage(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DoesPolicyAllowMailSync(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DoesPolicyAllowMailSync());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SyncScheduleKind(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SyncScheduleKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SyncScheduleKind(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SyncScheduleKind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MailAgeFilter(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountMailAgeFilter * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MailAgeFilter());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MailAgeFilter(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountMailAgeFilter value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MailAgeFilter(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsClientAuthenticationCertificateRequired(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsClientAuthenticationCertificateRequired());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsClientAuthenticationCertificateRequired(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsClientAuthenticationCertificateRequired(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoSelectAuthenticationCertificate(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoSelectAuthenticationCertificate());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutoSelectAuthenticationCertificate(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoSelectAuthenticationCertificate(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AuthenticationCertificateId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AuthenticationCertificateId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AuthenticationCertificateId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthenticationCertificateId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CardDavSyncScheduleKind(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CardDavSyncScheduleKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CardDavSyncScheduleKind(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CardDavSyncScheduleKind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CalDavSyncScheduleKind(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CalDavSyncScheduleKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CalDavSyncScheduleKind(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CalDavSyncScheduleKind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CardDavServerUrl(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CardDavServerUrl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CardDavServerUrl(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CardDavServerUrl(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CardDavRequiresSsl(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CardDavRequiresSsl());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CardDavRequiresSsl(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CardDavRequiresSsl(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CalDavServerUrl(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CalDavServerUrl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CalDavServerUrl(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CalDavServerUrl(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CalDavRequiresSsl(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CalDavRequiresSsl());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CalDavRequiresSsl(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CalDavRequiresSsl(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WasModifiedByUser(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WasModifiedByUser());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_WasModifiedByUser(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WasModifiedByUser(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WasIncomingServerCertificateHashConfirmed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WasIncomingServerCertificateHashConfirmed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_WasIncomingServerCertificateHashConfirmed(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WasIncomingServerCertificateHashConfirmed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncomingServerCertificateHash(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncomingServerCertificateHash());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IncomingServerCertificateHash(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncomingServerCertificateHash(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsOutgoingServerAuthenticationRequired(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOutgoingServerAuthenticationRequired());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsOutgoingServerAuthenticationRequired(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsOutgoingServerAuthenticationRequired(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsOutgoingServerAuthenticationEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOutgoingServerAuthenticationEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsOutgoingServerAuthenticationEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsOutgoingServerAuthenticationEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WasOutgoingServerCertificateHashConfirmed(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WasOutgoingServerCertificateHashConfirmed());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_WasOutgoingServerCertificateHashConfirmed(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WasOutgoingServerCertificateHashConfirmed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutgoingServerCertificateHash(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutgoingServerCertificateHash());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutgoingServerCertificateHash(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutgoingServerCertificateHash(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsSyncScheduleManagedBySystem(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSyncScheduleManagedBySystem());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsSyncScheduleManagedBySystem(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsSyncScheduleManagedBySystem(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics> : produce_base<D, Windows::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics>
{
    HRESULT __stdcall abi_AddAndShowDeviceAccountsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration>> accounts, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().AddAndShowDeviceAccountsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> *>(&accounts)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics2> : produce_base<D, Windows::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics2>
{
    HRESULT __stdcall abi_SuppressLocalAccountWithAccountAsync(impl::abi_arg_in<hstring> userDataAccountId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SuppressLocalAccountWithAccountAsync(*reinterpret_cast<const hstring *>(&userDataAccountId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateDeviceAccountAsync(impl::abi_arg_in<Windows::ApplicationModel::UserDataAccounts::SystemAccess::IDeviceAccountConfiguration> account, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateDeviceAccountAsync(*reinterpret_cast<const Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration *>(&account)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteDeviceAccountAsync(impl::abi_arg_in<hstring> accountId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DeleteDeviceAccountAsync(*reinterpret_cast<const hstring *>(&accountId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceAccountConfigurationAsync(impl::abi_arg_in<hstring> accountId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDeviceAccountConfigurationAsync(*reinterpret_cast<const hstring *>(&accountId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::UserDataAccounts::SystemAccess {

template <typename D> hstring impl_IDeviceAccountConfiguration<D>::AccountName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->get_AccountName(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration<D>::AccountName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->put_AccountName(get_abi(value)));
}

template <typename D> hstring impl_IDeviceAccountConfiguration<D>::DeviceAccountTypeId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->get_DeviceAccountTypeId(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration<D>::DeviceAccountTypeId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->put_DeviceAccountTypeId(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountServerType impl_IDeviceAccountConfiguration<D>::ServerType() const
{
    Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountServerType value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->get_ServerType(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration<D>::ServerType(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountServerType value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->put_ServerType(value));
}

template <typename D> hstring impl_IDeviceAccountConfiguration<D>::EmailAddress() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->get_EmailAddress(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration<D>::EmailAddress(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->put_EmailAddress(get_abi(value)));
}

template <typename D> hstring impl_IDeviceAccountConfiguration<D>::Domain() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->get_Domain(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration<D>::Domain(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->put_Domain(get_abi(value)));
}

template <typename D> bool impl_IDeviceAccountConfiguration<D>::EmailSyncEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->get_EmailSyncEnabled(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration<D>::EmailSyncEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->put_EmailSyncEnabled(value));
}

template <typename D> bool impl_IDeviceAccountConfiguration<D>::ContactsSyncEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->get_ContactsSyncEnabled(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration<D>::ContactsSyncEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->put_ContactsSyncEnabled(value));
}

template <typename D> bool impl_IDeviceAccountConfiguration<D>::CalendarSyncEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->get_CalendarSyncEnabled(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration<D>::CalendarSyncEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->put_CalendarSyncEnabled(value));
}

template <typename D> hstring impl_IDeviceAccountConfiguration<D>::IncomingServerAddress() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->get_IncomingServerAddress(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration<D>::IncomingServerAddress(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->put_IncomingServerAddress(get_abi(value)));
}

template <typename D> int32_t impl_IDeviceAccountConfiguration<D>::IncomingServerPort() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->get_IncomingServerPort(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration<D>::IncomingServerPort(int32_t value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->put_IncomingServerPort(value));
}

template <typename D> bool impl_IDeviceAccountConfiguration<D>::IncomingServerRequiresSsl() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->get_IncomingServerRequiresSsl(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration<D>::IncomingServerRequiresSsl(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->put_IncomingServerRequiresSsl(value));
}

template <typename D> hstring impl_IDeviceAccountConfiguration<D>::IncomingServerUsername() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->get_IncomingServerUsername(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration<D>::IncomingServerUsername(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->put_IncomingServerUsername(get_abi(value)));
}

template <typename D> hstring impl_IDeviceAccountConfiguration<D>::OutgoingServerAddress() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->get_OutgoingServerAddress(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration<D>::OutgoingServerAddress(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->put_OutgoingServerAddress(get_abi(value)));
}

template <typename D> int32_t impl_IDeviceAccountConfiguration<D>::OutgoingServerPort() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->get_OutgoingServerPort(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration<D>::OutgoingServerPort(int32_t value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->put_OutgoingServerPort(value));
}

template <typename D> bool impl_IDeviceAccountConfiguration<D>::OutgoingServerRequiresSsl() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->get_OutgoingServerRequiresSsl(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration<D>::OutgoingServerRequiresSsl(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->put_OutgoingServerRequiresSsl(value));
}

template <typename D> hstring impl_IDeviceAccountConfiguration<D>::OutgoingServerUsername() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->get_OutgoingServerUsername(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration<D>::OutgoingServerUsername(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration)->put_OutgoingServerUsername(get_abi(value)));
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_IDeviceAccountConfiguration2<D>::IncomingServerCredential() const
{
    Windows::Security::Credentials::PasswordCredential value { nullptr };
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_IncomingServerCredential(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::IncomingServerCredential(const Windows::Security::Credentials::PasswordCredential & value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_IncomingServerCredential(get_abi(value)));
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_IDeviceAccountConfiguration2<D>::OutgoingServerCredential() const
{
    Windows::Security::Credentials::PasswordCredential value { nullptr };
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_OutgoingServerCredential(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::OutgoingServerCredential(const Windows::Security::Credentials::PasswordCredential & value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_OutgoingServerCredential(get_abi(value)));
}

template <typename D> hstring impl_IDeviceAccountConfiguration2<D>::OAuthRefreshToken() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_OAuthRefreshToken(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::OAuthRefreshToken(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_OAuthRefreshToken(get_abi(value)));
}

template <typename D> bool impl_IDeviceAccountConfiguration2<D>::IsExternallyManaged() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_IsExternallyManaged(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::IsExternallyManaged(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_IsExternallyManaged(value));
}

template <typename D> Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountIconId impl_IDeviceAccountConfiguration2<D>::AccountIconId() const
{
    Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountIconId value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_AccountIconId(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::AccountIconId(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountIconId value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_AccountIconId(value));
}

template <typename D> Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountAuthenticationType impl_IDeviceAccountConfiguration2<D>::AuthenticationType() const
{
    Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountAuthenticationType value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_AuthenticationType(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::AuthenticationType(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountAuthenticationType value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_AuthenticationType(value));
}

template <typename D> bool impl_IDeviceAccountConfiguration2<D>::IsSsoAuthenticationSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_IsSsoAuthenticationSupported(&value));
    return value;
}

template <typename D> hstring impl_IDeviceAccountConfiguration2<D>::SsoAccountId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_SsoAccountId(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::SsoAccountId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_SsoAccountId(get_abi(value)));
}

template <typename D> bool impl_IDeviceAccountConfiguration2<D>::AlwaysDownloadFullMessage() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_AlwaysDownloadFullMessage(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::AlwaysDownloadFullMessage(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_AlwaysDownloadFullMessage(value));
}

template <typename D> bool impl_IDeviceAccountConfiguration2<D>::DoesPolicyAllowMailSync() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_DoesPolicyAllowMailSync(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind impl_IDeviceAccountConfiguration2<D>::SyncScheduleKind() const
{
    Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_SyncScheduleKind(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::SyncScheduleKind(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_SyncScheduleKind(value));
}

template <typename D> Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountMailAgeFilter impl_IDeviceAccountConfiguration2<D>::MailAgeFilter() const
{
    Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountMailAgeFilter value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_MailAgeFilter(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::MailAgeFilter(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountMailAgeFilter value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_MailAgeFilter(value));
}

template <typename D> bool impl_IDeviceAccountConfiguration2<D>::IsClientAuthenticationCertificateRequired() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_IsClientAuthenticationCertificateRequired(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::IsClientAuthenticationCertificateRequired(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_IsClientAuthenticationCertificateRequired(value));
}

template <typename D> bool impl_IDeviceAccountConfiguration2<D>::AutoSelectAuthenticationCertificate() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_AutoSelectAuthenticationCertificate(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::AutoSelectAuthenticationCertificate(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_AutoSelectAuthenticationCertificate(value));
}

template <typename D> hstring impl_IDeviceAccountConfiguration2<D>::AuthenticationCertificateId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_AuthenticationCertificateId(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::AuthenticationCertificateId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_AuthenticationCertificateId(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind impl_IDeviceAccountConfiguration2<D>::CardDavSyncScheduleKind() const
{
    Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_CardDavSyncScheduleKind(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::CardDavSyncScheduleKind(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_CardDavSyncScheduleKind(value));
}

template <typename D> Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind impl_IDeviceAccountConfiguration2<D>::CalDavSyncScheduleKind() const
{
    Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_CalDavSyncScheduleKind(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::CalDavSyncScheduleKind(Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountSyncScheduleKind value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_CalDavSyncScheduleKind(value));
}

template <typename D> Windows::Foundation::Uri impl_IDeviceAccountConfiguration2<D>::CardDavServerUrl() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_CardDavServerUrl(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::CardDavServerUrl(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_CardDavServerUrl(get_abi(value)));
}

template <typename D> bool impl_IDeviceAccountConfiguration2<D>::CardDavRequiresSsl() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_CardDavRequiresSsl(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::CardDavRequiresSsl(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_CardDavRequiresSsl(value));
}

template <typename D> Windows::Foundation::Uri impl_IDeviceAccountConfiguration2<D>::CalDavServerUrl() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_CalDavServerUrl(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::CalDavServerUrl(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_CalDavServerUrl(get_abi(value)));
}

template <typename D> bool impl_IDeviceAccountConfiguration2<D>::CalDavRequiresSsl() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_CalDavRequiresSsl(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::CalDavRequiresSsl(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_CalDavRequiresSsl(value));
}

template <typename D> bool impl_IDeviceAccountConfiguration2<D>::WasModifiedByUser() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_WasModifiedByUser(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::WasModifiedByUser(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_WasModifiedByUser(value));
}

template <typename D> bool impl_IDeviceAccountConfiguration2<D>::WasIncomingServerCertificateHashConfirmed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_WasIncomingServerCertificateHashConfirmed(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::WasIncomingServerCertificateHashConfirmed(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_WasIncomingServerCertificateHashConfirmed(value));
}

template <typename D> hstring impl_IDeviceAccountConfiguration2<D>::IncomingServerCertificateHash() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_IncomingServerCertificateHash(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::IncomingServerCertificateHash(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_IncomingServerCertificateHash(get_abi(value)));
}

template <typename D> bool impl_IDeviceAccountConfiguration2<D>::IsOutgoingServerAuthenticationRequired() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_IsOutgoingServerAuthenticationRequired(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::IsOutgoingServerAuthenticationRequired(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_IsOutgoingServerAuthenticationRequired(value));
}

template <typename D> bool impl_IDeviceAccountConfiguration2<D>::IsOutgoingServerAuthenticationEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_IsOutgoingServerAuthenticationEnabled(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::IsOutgoingServerAuthenticationEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_IsOutgoingServerAuthenticationEnabled(value));
}

template <typename D> bool impl_IDeviceAccountConfiguration2<D>::WasOutgoingServerCertificateHashConfirmed() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_WasOutgoingServerCertificateHashConfirmed(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::WasOutgoingServerCertificateHashConfirmed(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_WasOutgoingServerCertificateHashConfirmed(value));
}

template <typename D> hstring impl_IDeviceAccountConfiguration2<D>::OutgoingServerCertificateHash() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_OutgoingServerCertificateHash(put_abi(value)));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::OutgoingServerCertificateHash(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_OutgoingServerCertificateHash(get_abi(value)));
}

template <typename D> bool impl_IDeviceAccountConfiguration2<D>::IsSyncScheduleManagedBySystem() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->get_IsSyncScheduleManagedBySystem(&value));
    return value;
}

template <typename D> void impl_IDeviceAccountConfiguration2<D>::IsSyncScheduleManagedBySystem(bool value) const
{
    check_hresult(WINRT_SHIM(IDeviceAccountConfiguration2)->put_IsSyncScheduleManagedBySystem(value));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> impl_IUserDataAccountSystemAccessManagerStatics<D>::AddAndShowDeviceAccountsAsync(iterable<Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> accounts) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> result;
    check_hresult(WINRT_SHIM(IUserDataAccountSystemAccessManagerStatics)->abi_AddAndShowDeviceAccountsAsync(get_abi(accounts), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IUserDataAccountSystemAccessManagerStatics2<D>::SuppressLocalAccountWithAccountAsync(hstring_view userDataAccountId) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IUserDataAccountSystemAccessManagerStatics2)->abi_SuppressLocalAccountWithAccountAsync(get_abi(userDataAccountId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IUserDataAccountSystemAccessManagerStatics2<D>::CreateDeviceAccountAsync(const Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration & account) const
{
    Windows::Foundation::IAsyncOperation<hstring> result;
    check_hresult(WINRT_SHIM(IUserDataAccountSystemAccessManagerStatics2)->abi_CreateDeviceAccountAsync(get_abi(account), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IUserDataAccountSystemAccessManagerStatics2<D>::DeleteDeviceAccountAsync(hstring_view accountId) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IUserDataAccountSystemAccessManagerStatics2)->abi_DeleteDeviceAccountAsync(get_abi(accountId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> impl_IUserDataAccountSystemAccessManagerStatics2<D>::GetDeviceAccountConfigurationAsync(hstring_view accountId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> result;
    check_hresult(WINRT_SHIM(IUserDataAccountSystemAccessManagerStatics2)->abi_GetDeviceAccountConfigurationAsync(get_abi(accountId), put_abi(result)));
    return result;
}

inline DeviceAccountConfiguration::DeviceAccountConfiguration() :
    DeviceAccountConfiguration(activate_instance<DeviceAccountConfiguration>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> UserDataAccountSystemAccessManager::AddAndShowDeviceAccountsAsync(iterable<Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> accounts)
{
    return get_activation_factory<UserDataAccountSystemAccessManager, IUserDataAccountSystemAccessManagerStatics>().AddAndShowDeviceAccountsAsync(accounts);
}

inline Windows::Foundation::IAsyncAction UserDataAccountSystemAccessManager::SuppressLocalAccountWithAccountAsync(hstring_view userDataAccountId)
{
    return get_activation_factory<UserDataAccountSystemAccessManager, IUserDataAccountSystemAccessManagerStatics2>().SuppressLocalAccountWithAccountAsync(userDataAccountId);
}

inline Windows::Foundation::IAsyncOperation<hstring> UserDataAccountSystemAccessManager::CreateDeviceAccountAsync(const Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration & account)
{
    return get_activation_factory<UserDataAccountSystemAccessManager, IUserDataAccountSystemAccessManagerStatics2>().CreateDeviceAccountAsync(account);
}

inline Windows::Foundation::IAsyncAction UserDataAccountSystemAccessManager::DeleteDeviceAccountAsync(hstring_view accountId)
{
    return get_activation_factory<UserDataAccountSystemAccessManager, IUserDataAccountSystemAccessManagerStatics2>().DeleteDeviceAccountAsync(accountId);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> UserDataAccountSystemAccessManager::GetDeviceAccountConfigurationAsync(hstring_view accountId)
{
    return get_activation_factory<UserDataAccountSystemAccessManager, IUserDataAccountSystemAccessManagerStatics2>().GetDeviceAccountConfigurationAsync(accountId);
}

}

}
#pragma warning(pop)
