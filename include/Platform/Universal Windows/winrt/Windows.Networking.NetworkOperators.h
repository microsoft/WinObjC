// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Devices.Sms.3.h"
#include "internal/Windows.Networking.Connectivity.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Data.Xml.Dom.3.h"
#include "internal/Windows.Networking.NetworkOperators.3.h"
#include "Windows.Networking.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IFdnAccessManagerStatics> : produce_base<D, Windows::Networking::NetworkOperators::IFdnAccessManagerStatics>
{
    HRESULT __stdcall abi_RequestUnlockAsync(impl::abi_arg_in<hstring> contactListId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().RequestUnlockAsync(*reinterpret_cast<const hstring *>(&contactListId)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IHotspotAuthenticationContext> : produce_base<D, Windows::Networking::NetworkOperators::IHotspotAuthenticationContext>
{
    HRESULT __stdcall get_WirelessNetworkId(uint32_t * __valueSize, impl::abi_arg_out<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().WirelessNetworkId());
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NetworkAdapter(impl::abi_arg_out<Windows::Networking::Connectivity::INetworkAdapter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkAdapter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RedirectMessageUrl(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RedirectMessageUrl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RedirectMessageXml(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocument> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RedirectMessageXml());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AuthenticationUrl(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AuthenticationUrl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IssueCredentials(impl::abi_arg_in<hstring> userName, impl::abi_arg_in<hstring> password, impl::abi_arg_in<hstring> extraParameters, bool markAsManualConnectOnFailure) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IssueCredentials(*reinterpret_cast<const hstring *>(&userName), *reinterpret_cast<const hstring *>(&password), *reinterpret_cast<const hstring *>(&extraParameters), markAsManualConnectOnFailure);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AbortAuthentication(bool markAsManual) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AbortAuthentication(markAsManual);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SkipAuthentication() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SkipAuthentication();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TriggerAttentionRequired(impl::abi_arg_in<hstring> packageRelativeApplicationId, impl::abi_arg_in<hstring> applicationParameters) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TriggerAttentionRequired(*reinterpret_cast<const hstring *>(&packageRelativeApplicationId), *reinterpret_cast<const hstring *>(&applicationParameters));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IHotspotAuthenticationContext2> : produce_base<D, Windows::Networking::NetworkOperators::IHotspotAuthenticationContext2>
{
    HRESULT __stdcall abi_IssueCredentialsAsync(impl::abi_arg_in<hstring> userName, impl::abi_arg_in<hstring> password, impl::abi_arg_in<hstring> extraParameters, bool markAsManualConnectOnFailure, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::HotspotCredentialsAuthenticationResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().IssueCredentialsAsync(*reinterpret_cast<const hstring *>(&userName), *reinterpret_cast<const hstring *>(&password), *reinterpret_cast<const hstring *>(&extraParameters), markAsManualConnectOnFailure));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IHotspotAuthenticationContextStatics> : produce_base<D, Windows::Networking::NetworkOperators::IHotspotAuthenticationContextStatics>
{
    HRESULT __stdcall abi_TryGetAuthenticationContext(impl::abi_arg_in<hstring> evenToken, impl::abi_arg_out<Windows::Networking::NetworkOperators::IHotspotAuthenticationContext> context, bool * isValid) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *isValid = detach_abi(this->shim().TryGetAuthenticationContext(*reinterpret_cast<const hstring *>(&evenToken), *context));
            return S_OK;
        }
        catch (...)
        {
            *context = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IHotspotAuthenticationEventDetails> : produce_base<D, Windows::Networking::NetworkOperators::IHotspotAuthenticationEventDetails>
{
    HRESULT __stdcall get_EventToken(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EventToken());
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
struct produce<D, Windows::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult> : produce_base<D, Windows::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult>
{
    HRESULT __stdcall get_HasNetworkErrorOccurred(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasNetworkErrorOccurred());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResponseCode(Windows::Networking::NetworkOperators::HotspotAuthenticationResponseCode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResponseCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LogoffUrl(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LogoffUrl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AuthenticationReplyXml(impl::abi_arg_out<Windows::Data::Xml::Dom::IXmlDocument> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AuthenticationReplyXml());
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
struct produce<D, Windows::Networking::NetworkOperators::IKnownCSimFilePathsStatics> : produce_base<D, Windows::Networking::NetworkOperators::IKnownCSimFilePathsStatics>
{
    HRESULT __stdcall get_EFSpn(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EFSpn());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gid1(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gid1());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gid2(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gid2());
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
struct produce<D, Windows::Networking::NetworkOperators::IKnownRuimFilePathsStatics> : produce_base<D, Windows::Networking::NetworkOperators::IKnownRuimFilePathsStatics>
{
    HRESULT __stdcall get_EFSpn(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EFSpn());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gid1(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gid1());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gid2(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gid2());
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
struct produce<D, Windows::Networking::NetworkOperators::IKnownSimFilePathsStatics> : produce_base<D, Windows::Networking::NetworkOperators::IKnownSimFilePathsStatics>
{
    HRESULT __stdcall get_EFOns(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EFOns());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EFSpn(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EFSpn());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gid1(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gid1());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gid2(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gid2());
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
struct produce<D, Windows::Networking::NetworkOperators::IKnownUSimFilePathsStatics> : produce_base<D, Windows::Networking::NetworkOperators::IKnownUSimFilePathsStatics>
{
    HRESULT __stdcall get_EFSpn(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EFSpn());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EFOpl(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EFOpl());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EFPnn(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EFPnn());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gid1(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gid1());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Gid2(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Gid2());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandAccount> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandAccount>
{
    HRESULT __stdcall get_NetworkAccountId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkAccountId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceProviderGuid(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceProviderGuid());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceProviderName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceProviderName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentNetwork(impl::abi_arg_out<Windows::Networking::NetworkOperators::IMobileBroadbandNetwork> network) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *network = detach_abi(this->shim().CurrentNetwork());
            return S_OK;
        }
        catch (...)
        {
            *network = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentDeviceInformation(impl::abi_arg_out<Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation> deviceInformation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *deviceInformation = detach_abi(this->shim().CurrentDeviceInformation());
            return S_OK;
        }
        catch (...)
        {
            *deviceInformation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandAccount2> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandAccount2>
{
    HRESULT __stdcall abi_GetConnectionProfiles(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::ConnectionProfile>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetConnectionProfiles());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandAccountEventArgs> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandAccountEventArgs>
{
    HRESULT __stdcall get_NetworkAccountId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkAccountId());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandAccountStatics> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandAccountStatics>
{
    HRESULT __stdcall get_AvailableNetworkAccountIds(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> ppAccountIds) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ppAccountIds = detach_abi(this->shim().AvailableNetworkAccountIds());
            return S_OK;
        }
        catch (...)
        {
            *ppAccountIds = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromNetworkAccountId(impl::abi_arg_in<hstring> networkAccountId, impl::abi_arg_out<Windows::Networking::NetworkOperators::IMobileBroadbandAccount> ppAccount) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ppAccount = detach_abi(this->shim().CreateFromNetworkAccountId(*reinterpret_cast<const hstring *>(&networkAccountId)));
            return S_OK;
        }
        catch (...)
        {
            *ppAccount = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandAccountUpdatedEventArgs> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandAccountUpdatedEventArgs>
{
    HRESULT __stdcall get_NetworkAccountId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkAccountId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasDeviceInformationChanged(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasDeviceInformationChanged());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasNetworkChanged(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasNetworkChanged());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher>
{
    HRESULT __stdcall add_AccountAdded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Networking::NetworkOperators::MobileBroadbandAccountEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().AccountAdded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Networking::NetworkOperators::MobileBroadbandAccountEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AccountAdded(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccountAdded(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AccountUpdated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Networking::NetworkOperators::MobileBroadbandAccountUpdatedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().AccountUpdated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Networking::NetworkOperators::MobileBroadbandAccountUpdatedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AccountUpdated(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccountUpdated(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_AccountRemoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Networking::NetworkOperators::MobileBroadbandAccountEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().AccountRemoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Networking::NetworkOperators::MobileBroadbandAccountEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_AccountRemoved(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccountRemoved(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_EnumerationCompleted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().EnumerationCompleted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_EnumerationCompleted(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Stopped(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().Stopped(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Stopped(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcherStatus * status) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation>
{
    HRESULT __stdcall get_NetworkDeviceStatus(Windows::Networking::NetworkOperators::NetworkDeviceStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkDeviceStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Manufacturer(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Manufacturer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Model(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Model());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FirmwareInformation(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FirmwareInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CellularClass(Windows::Devices::Sms::CellularClass * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CellularClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DataClasses(Windows::Networking::NetworkOperators::DataClasses * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataClasses());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CustomDataClass(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CustomDataClass());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MobileEquipmentId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MobileEquipmentId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TelephoneNumbers(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TelephoneNumbers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SubscriberId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SubscriberId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SimIccId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SimIccId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceType(Windows::Networking::NetworkOperators::MobileBroadbandDeviceType * pDeviceType) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pDeviceType = detach_abi(this->shim().DeviceType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentRadioState(Windows::Networking::NetworkOperators::MobileBroadbandRadioState * pCurrentState) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pCurrentState = detach_abi(this->shim().CurrentRadioState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation2> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation2>
{
    HRESULT __stdcall get_PinManager(impl::abi_arg_out<Windows::Networking::NetworkOperators::IMobileBroadbandPinManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PinManager());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Revision(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Revision());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SerialNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SerialNumber());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceService> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceService>
{
    HRESULT __stdcall get_DeviceServiceId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceServiceId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedCommands(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedCommands());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenDataSession(impl::abi_arg_out<Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpenDataSession());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_OpenCommandSession(impl::abi_arg_out<Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OpenCommandSession());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandResult> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandResult>
{
    HRESULT __stdcall get_StatusCode(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StatusCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResponseData(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResponseData());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession>
{
    HRESULT __stdcall abi_SendQueryCommandAsync(uint32_t commandId, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> data, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().SendQueryCommandAsync(commandId, *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&data)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SendSetCommandAsync(uint32_t commandId, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> data, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().SendSetCommandAsync(commandId, *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&data)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CloseSession() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CloseSession();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataReceivedEventArgs> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataReceivedEventArgs>
{
    HRESULT __stdcall get_ReceivedData(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReceivedData());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession>
{
    HRESULT __stdcall abi_WriteDataAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> value, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().WriteDataAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CloseSession() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CloseSession();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DataReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataSession, Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataReceivedEventArgs>> eventHandler, event_token * eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_abi(this->shim().DataReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataSession, Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataReceivedEventArgs> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DataReceived(event_token eventCookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataReceived(eventCookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceInformation> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceInformation>
{
    HRESULT __stdcall get_DeviceServiceId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceServiceId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDataReadSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDataReadSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDataWriteSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDataWriteSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceServiceId(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceServiceId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReceivedData(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReceivedData());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandModem> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandModem>
{
    HRESULT __stdcall get_CurrentAccount(impl::abi_arg_out<Windows::Networking::NetworkOperators::IMobileBroadbandAccount> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentAccount());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceInformation(impl::abi_arg_out<Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxDeviceServiceCommandSizeInBytes(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxDeviceServiceCommandSizeInBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxDeviceServiceDataSizeInBytes(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxDeviceServiceDataSizeInBytes());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DeviceServices(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceInformation>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceServices());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceService(GUID deviceServiceId, impl::abi_arg_out<Windows::Networking::NetworkOperators::IMobileBroadbandDeviceService> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceService(deviceServiceId));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsResetSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsResetSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ResetAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().ResetAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentConfigurationAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandModemConfiguration>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetCurrentConfigurationAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CurrentNetwork(impl::abi_arg_out<Windows::Networking::NetworkOperators::IMobileBroadbandNetwork> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentNetwork());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandModemConfiguration> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandModemConfiguration>
{
    HRESULT __stdcall get_Uicc(impl::abi_arg_out<Windows::Networking::NetworkOperators::IMobileBroadbandUicc> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uicc());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HomeProviderId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HomeProviderId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HomeProviderName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HomeProviderName());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandModemStatics> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandModemStatics>
{
    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromId(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Networking::NetworkOperators::IMobileBroadbandModem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromId(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Networking::NetworkOperators::IMobileBroadbandModem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDefault());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandNetwork> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandNetwork>
{
    HRESULT __stdcall get_NetworkAdapter(impl::abi_arg_out<Windows::Networking::Connectivity::INetworkAdapter> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkAdapter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NetworkRegistrationState(Windows::Networking::NetworkOperators::NetworkRegistrationState * registrationState) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *registrationState = detach_abi(this->shim().NetworkRegistrationState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RegistrationNetworkError(uint32_t * networkError) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *networkError = detach_abi(this->shim().RegistrationNetworkError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PacketAttachNetworkError(uint32_t * networkError) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *networkError = detach_abi(this->shim().PacketAttachNetworkError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActivationNetworkError(uint32_t * networkError) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *networkError = detach_abi(this->shim().ActivationNetworkError());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AccessPointName(impl::abi_arg_out<hstring> apn) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *apn = detach_abi(this->shim().AccessPointName());
            return S_OK;
        }
        catch (...)
        {
            *apn = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RegisteredDataClass(Windows::Networking::NetworkOperators::DataClasses * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RegisteredDataClass());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RegisteredProviderId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RegisteredProviderId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RegisteredProviderName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RegisteredProviderName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowConnectionUI() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowConnectionUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandNetwork2> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandNetwork2>
{
    HRESULT __stdcall abi_GetVoiceCallSupportAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetVoiceCallSupportAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RegistrationUiccApps(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandUiccApp>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RegistrationUiccApps());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChange> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChange>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Network(impl::abi_arg_out<Windows::Networking::NetworkOperators::IMobileBroadbandNetwork> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Network());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails>
{
    HRESULT __stdcall get_NetworkRegistrationStateChanges(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandNetworkRegistrationStateChange>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkRegistrationStateChanges());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandPin> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandPin>
{
    HRESULT __stdcall get_Type(Windows::Networking::NetworkOperators::MobileBroadbandPinType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LockState(Windows::Networking::NetworkOperators::MobileBroadbandPinLockState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LockState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Format(Windows::Networking::NetworkOperators::MobileBroadbandPinFormat * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Format());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Enabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Enabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxLength(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MinLength(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AttemptsRemaining(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AttemptsRemaining());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EnableAsync(impl::abi_arg_in<hstring> currentPin, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().EnableAsync(*reinterpret_cast<const hstring *>(&currentPin)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DisableAsync(impl::abi_arg_in<hstring> currentPin, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().DisableAsync(*reinterpret_cast<const hstring *>(&currentPin)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EnterAsync(impl::abi_arg_in<hstring> currentPin, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().EnterAsync(*reinterpret_cast<const hstring *>(&currentPin)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ChangeAsync(impl::abi_arg_in<hstring> currentPin, impl::abi_arg_in<hstring> newPin, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().ChangeAsync(*reinterpret_cast<const hstring *>(&currentPin), *reinterpret_cast<const hstring *>(&newPin)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnblockAsync(impl::abi_arg_in<hstring> pinUnblockKey, impl::abi_arg_in<hstring> newPin, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().UnblockAsync(*reinterpret_cast<const hstring *>(&pinUnblockKey), *reinterpret_cast<const hstring *>(&newPin)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandPinLockStateChange> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandPinLockStateChange>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PinType(Windows::Networking::NetworkOperators::MobileBroadbandPinType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PinType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PinLockState(Windows::Networking::NetworkOperators::MobileBroadbandPinLockState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PinLockState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandPinLockStateChangeTriggerDetails> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandPinLockStateChangeTriggerDetails>
{
    HRESULT __stdcall get_PinLockStateChanges(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandPinLockStateChange>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PinLockStateChanges());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandPinManager> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandPinManager>
{
    HRESULT __stdcall get_SupportedPins(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Networking::NetworkOperators::MobileBroadbandPinType>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SupportedPins());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPin(Windows::Networking::NetworkOperators::MobileBroadbandPinType pinType, impl::abi_arg_out<Windows::Networking::NetworkOperators::IMobileBroadbandPin> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetPin(pinType));
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandPinOperationResult> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandPinOperationResult>
{
    HRESULT __stdcall get_IsSuccessful(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsSuccessful());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AttemptsRemaining(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AttemptsRemaining());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandRadioStateChange> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandRadioStateChange>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RadioState(Windows::Networking::NetworkOperators::MobileBroadbandRadioState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RadioState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandRadioStateChangeTriggerDetails> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandRadioStateChangeTriggerDetails>
{
    HRESULT __stdcall get_RadioStateChanges(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandRadioStateChange>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RadioStateChanges());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandUicc> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandUicc>
{
    HRESULT __stdcall get_SimIccId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SimIccId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetUiccAppsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandUiccAppsResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetUiccAppsAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandUiccApp> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandUiccApp>
{
    HRESULT __stdcall get_Id(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::Networking::NetworkOperators::UiccAppKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetRecordDetailsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<uint32_t>> uiccFilePath, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandUiccAppRecordDetailsResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().GetRecordDetailsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<uint32_t> *>(&uiccFilePath)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadRecordAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<uint32_t>> uiccFilePath, int32_t recordIndex, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandUiccAppReadRecordResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().ReadRecordAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<uint32_t> *>(&uiccFilePath), recordIndex));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppReadRecordResult> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppReadRecordResult>
{
    HRESULT __stdcall get_Status(Windows::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Data(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Data());
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
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult>
{
    HRESULT __stdcall get_Status(Windows::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::Networking::NetworkOperators::UiccAppRecordKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RecordCount(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RecordCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RecordSize(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RecordSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReadAccessCondition(Windows::Networking::NetworkOperators::UiccAccessCondition * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadAccessCondition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WriteAccessCondition(Windows::Networking::NetworkOperators::UiccAccessCondition * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WriteAccessCondition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppsResult> : produce_base<D, Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppsResult>
{
    HRESULT __stdcall get_Status(Windows::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UiccApps(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandUiccApp>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UiccApps());
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
struct produce<D, Windows::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails> : produce_base<D, Windows::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails>
{
    HRESULT __stdcall get_NotificationType(Windows::Networking::NetworkOperators::NetworkOperatorEventMessageType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NotificationType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NetworkAccountId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NetworkAccountId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EncodingType(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EncodingType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Message(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Message());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RuleId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RuleId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SmsMessage(impl::abi_arg_out<Windows::Devices::Sms::ISmsMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmsMessage());
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
struct produce<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration> : produce_base<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration>
{
    HRESULT __stdcall get_Ssid(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ssid());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Ssid(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Ssid(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Passphrase(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Passphrase());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Passphrase(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Passphrase(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringClient> : produce_base<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringClient>
{
    HRESULT __stdcall get_MacAddress(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MacAddress());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HostNames(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HostNames());
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
struct produce<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringClientManager> : produce_base<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringClientManager>
{
    HRESULT __stdcall abi_GetTetheringClients(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::NetworkOperatorTetheringClient>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetTetheringClients());
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
struct produce<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringEntitlementCheck> : produce_base<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringEntitlementCheck>
{
    HRESULT __stdcall abi_AuthorizeTethering(bool allow, impl::abi_arg_in<hstring> entitlementFailureReason) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthorizeTethering(allow, *reinterpret_cast<const hstring *>(&entitlementFailureReason));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager> : produce_base<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager>
{
    HRESULT __stdcall get_MaxClientCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxClientCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ClientCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ClientCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TetheringOperationalState(Windows::Networking::NetworkOperators::TetheringOperationalState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TetheringOperationalState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetCurrentAccessPointConfiguration(impl::abi_arg_out<Windows::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration> configuration) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *configuration = detach_abi(this->shim().GetCurrentAccessPointConfiguration());
            return S_OK;
        }
        catch (...)
        {
            *configuration = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConfigureAccessPointAsync(impl::abi_arg_in<Windows::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration> configuration, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().ConfigureAccessPointAsync(*reinterpret_cast<const Windows::Networking::NetworkOperators::NetworkOperatorTetheringAccessPointConfiguration *>(&configuration)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartTetheringAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().StartTetheringAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopTetheringAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().StopTetheringAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics> : produce_base<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics>
{
    HRESULT __stdcall abi_GetTetheringCapability(impl::abi_arg_in<hstring> networkAccountId, Windows::Networking::NetworkOperators::TetheringCapability * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetTetheringCapability(*reinterpret_cast<const hstring *>(&networkAccountId)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromNetworkAccountId(impl::abi_arg_in<hstring> networkAccountId, impl::abi_arg_out<Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager> ppManager) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ppManager = detach_abi(this->shim().CreateFromNetworkAccountId(*reinterpret_cast<const hstring *>(&networkAccountId)));
            return S_OK;
        }
        catch (...)
        {
            *ppManager = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics2> : produce_base<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics2>
{
    HRESULT __stdcall abi_GetTetheringCapabilityFromConnectionProfile(impl::abi_arg_in<Windows::Networking::Connectivity::IConnectionProfile> profile, Windows::Networking::NetworkOperators::TetheringCapability * result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetTetheringCapabilityFromConnectionProfile(*reinterpret_cast<const Windows::Networking::Connectivity::ConnectionProfile *>(&profile)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromConnectionProfile(impl::abi_arg_in<Windows::Networking::Connectivity::IConnectionProfile> profile, impl::abi_arg_out<Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager> ppManager) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ppManager = detach_abi(this->shim().CreateFromConnectionProfile(*reinterpret_cast<const Windows::Networking::Connectivity::ConnectionProfile *>(&profile)));
            return S_OK;
        }
        catch (...)
        {
            *ppManager = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics3> : produce_base<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics3>
{
    HRESULT __stdcall abi_CreateFromConnectionProfileWithTargetAdapter(impl::abi_arg_in<Windows::Networking::Connectivity::IConnectionProfile> profile, impl::abi_arg_in<Windows::Networking::Connectivity::INetworkAdapter> adapter, impl::abi_arg_out<Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager> ppManager) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ppManager = detach_abi(this->shim().CreateFromConnectionProfile(*reinterpret_cast<const Windows::Networking::Connectivity::ConnectionProfile *>(&profile), *reinterpret_cast<const Windows::Networking::Connectivity::NetworkAdapter *>(&adapter)));
            return S_OK;
        }
        catch (...)
        {
            *ppManager = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringOperationResult> : produce_base<D, Windows::Networking::NetworkOperators::INetworkOperatorTetheringOperationResult>
{
    HRESULT __stdcall get_Status(Windows::Networking::NetworkOperators::TetheringOperationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AdditionalErrorMessage(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AdditionalErrorMessage());
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
struct produce<D, Windows::Networking::NetworkOperators::IProvisionFromXmlDocumentResults> : produce_base<D, Windows::Networking::NetworkOperators::IProvisionFromXmlDocumentResults>
{
    HRESULT __stdcall get_AllElementsProvisioned(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllElementsProvisioned());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProvisionResultsXml(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProvisionResultsXml());
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
struct produce<D, Windows::Networking::NetworkOperators::IProvisionedProfile> : produce_base<D, Windows::Networking::NetworkOperators::IProvisionedProfile>
{
    HRESULT __stdcall abi_UpdateCost(Windows::Networking::Connectivity::NetworkCostType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateCost(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateUsage(impl::abi_arg_in<Windows::Networking::NetworkOperators::ProfileUsage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateUsage(*reinterpret_cast<const Windows::Networking::NetworkOperators::ProfileUsage *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IProvisioningAgent> : produce_base<D, Windows::Networking::NetworkOperators::IProvisioningAgent>
{
    HRESULT __stdcall abi_ProvisionFromXmlDocumentAsync(impl::abi_arg_in<hstring> provisioningXmlDocument, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::ProvisionFromXmlDocumentResults>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().ProvisionFromXmlDocumentAsync(*reinterpret_cast<const hstring *>(&provisioningXmlDocument)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetProvisionedProfile(Windows::Networking::NetworkOperators::ProfileMediaType mediaType, impl::abi_arg_in<hstring> profileName, impl::abi_arg_out<Windows::Networking::NetworkOperators::IProvisionedProfile> provisionedProfile) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *provisionedProfile = detach_abi(this->shim().GetProvisionedProfile(mediaType, *reinterpret_cast<const hstring *>(&profileName)));
            return S_OK;
        }
        catch (...)
        {
            *provisionedProfile = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IProvisioningAgentStaticMethods> : produce_base<D, Windows::Networking::NetworkOperators::IProvisioningAgentStaticMethods>
{
    HRESULT __stdcall abi_CreateFromNetworkAccountId(impl::abi_arg_in<hstring> networkAccountId, impl::abi_arg_out<Windows::Networking::NetworkOperators::IProvisioningAgent> provisioningAgent) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *provisioningAgent = detach_abi(this->shim().CreateFromNetworkAccountId(*reinterpret_cast<const hstring *>(&networkAccountId)));
            return S_OK;
        }
        catch (...)
        {
            *provisioningAgent = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IUssdMessage> : produce_base<D, Windows::Networking::NetworkOperators::IUssdMessage>
{
    HRESULT __stdcall get_DataCodingScheme(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DataCodingScheme());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DataCodingScheme(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataCodingScheme(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPayload(uint32_t * __valueSize, impl::abi_arg_out<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().GetPayload());
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPayload(uint32_t __valueSize, impl::abi_arg_in<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPayload(array_view<const uint8_t>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PayloadAsText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PayloadAsText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PayloadAsText(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PayloadAsText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IUssdMessageFactory> : produce_base<D, Windows::Networking::NetworkOperators::IUssdMessageFactory>
{
    HRESULT __stdcall abi_CreateMessage(impl::abi_arg_in<hstring> messageText, impl::abi_arg_out<Windows::Networking::NetworkOperators::IUssdMessage> ussdMessage) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ussdMessage = detach_abi(this->shim().CreateMessage(*reinterpret_cast<const hstring *>(&messageText)));
            return S_OK;
        }
        catch (...)
        {
            *ussdMessage = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IUssdReply> : produce_base<D, Windows::Networking::NetworkOperators::IUssdReply>
{
    HRESULT __stdcall get_ResultCode(Windows::Networking::NetworkOperators::UssdResultCode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResultCode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Message(impl::abi_arg_out<Windows::Networking::NetworkOperators::IUssdMessage> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Message());
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
struct produce<D, Windows::Networking::NetworkOperators::IUssdSession> : produce_base<D, Windows::Networking::NetworkOperators::IUssdSession>
{
    HRESULT __stdcall abi_SendMessageAndGetReplyAsync(impl::abi_arg_in<Windows::Networking::NetworkOperators::IUssdMessage> message, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::UssdReply>> asyncInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_abi(this->shim().SendMessageAndGetReplyAsync(*reinterpret_cast<const Windows::Networking::NetworkOperators::UssdMessage *>(&message)));
            return S_OK;
        }
        catch (...)
        {
            *asyncInfo = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Close() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Close();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::NetworkOperators::IUssdSessionStatics> : produce_base<D, Windows::Networking::NetworkOperators::IUssdSessionStatics>
{
    HRESULT __stdcall abi_CreateFromNetworkAccountId(impl::abi_arg_in<hstring> networkAccountId, impl::abi_arg_out<Windows::Networking::NetworkOperators::IUssdSession> ussdSession) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ussdSession = detach_abi(this->shim().CreateFromNetworkAccountId(*reinterpret_cast<const hstring *>(&networkAccountId)));
            return S_OK;
        }
        catch (...)
        {
            *ussdSession = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromNetworkInterfaceId(impl::abi_arg_in<hstring> networkInterfaceId, impl::abi_arg_out<Windows::Networking::NetworkOperators::IUssdSession> ussdSession) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *ussdSession = detach_abi(this->shim().CreateFromNetworkInterfaceId(*reinterpret_cast<const hstring *>(&networkInterfaceId)));
            return S_OK;
        }
        catch (...)
        {
            *ussdSession = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Networking::NetworkOperators {

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IMobileBroadbandAccountStatics<D>::AvailableNetworkAccountIds() const
{
    Windows::Foundation::Collections::IVectorView<hstring> ppAccountIds;
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountStatics)->get_AvailableNetworkAccountIds(put_abi(ppAccountIds)));
    return ppAccountIds;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandAccount impl_IMobileBroadbandAccountStatics<D>::CreateFromNetworkAccountId(hstring_view networkAccountId) const
{
    Windows::Networking::NetworkOperators::MobileBroadbandAccount ppAccount { nullptr };
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountStatics)->abi_CreateFromNetworkAccountId(get_abi(networkAccountId), put_abi(ppAccount)));
    return ppAccount;
}

template <typename D> hstring impl_IMobileBroadbandAccount<D>::NetworkAccountId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandAccount)->get_NetworkAccountId(put_abi(value)));
    return value;
}

template <typename D> GUID impl_IMobileBroadbandAccount<D>::ServiceProviderGuid() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandAccount)->get_ServiceProviderGuid(&value));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandAccount<D>::ServiceProviderName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandAccount)->get_ServiceProviderName(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandNetwork impl_IMobileBroadbandAccount<D>::CurrentNetwork() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandNetwork network { nullptr };
    check_hresult(WINRT_SHIM(IMobileBroadbandAccount)->get_CurrentNetwork(put_abi(network)));
    return network;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandDeviceInformation impl_IMobileBroadbandAccount<D>::CurrentDeviceInformation() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandDeviceInformation deviceInformation { nullptr };
    check_hresult(WINRT_SHIM(IMobileBroadbandAccount)->get_CurrentDeviceInformation(put_abi(deviceInformation)));
    return deviceInformation;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::ConnectionProfile> impl_IMobileBroadbandAccount2<D>::GetConnectionProfiles() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::Connectivity::ConnectionProfile> value;
    check_hresult(WINRT_SHIM(IMobileBroadbandAccount2)->abi_GetConnectionProfiles(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::NetworkDeviceStatus impl_IMobileBroadbandDeviceInformation<D>::NetworkDeviceStatus() const
{
    Windows::Networking::NetworkOperators::NetworkDeviceStatus value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation)->get_NetworkDeviceStatus(&value));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandDeviceInformation<D>::Manufacturer() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation)->get_Manufacturer(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandDeviceInformation<D>::Model() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation)->get_Model(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandDeviceInformation<D>::FirmwareInformation() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation)->get_FirmwareInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::CellularClass impl_IMobileBroadbandDeviceInformation<D>::CellularClass() const
{
    Windows::Devices::Sms::CellularClass value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation)->get_CellularClass(&value));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::DataClasses impl_IMobileBroadbandDeviceInformation<D>::DataClasses() const
{
    Windows::Networking::NetworkOperators::DataClasses value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation)->get_DataClasses(&value));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandDeviceInformation<D>::CustomDataClass() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation)->get_CustomDataClass(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandDeviceInformation<D>::MobileEquipmentId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation)->get_MobileEquipmentId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IMobileBroadbandDeviceInformation<D>::TelephoneNumbers() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation)->get_TelephoneNumbers(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandDeviceInformation<D>::SubscriberId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation)->get_SubscriberId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandDeviceInformation<D>::SimIccId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation)->get_SimIccId(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandDeviceType impl_IMobileBroadbandDeviceInformation<D>::DeviceType() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandDeviceType pDeviceType {};
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation)->get_DeviceType(&pDeviceType));
    return pDeviceType;
}

template <typename D> hstring impl_IMobileBroadbandDeviceInformation<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandRadioState impl_IMobileBroadbandDeviceInformation<D>::CurrentRadioState() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandRadioState pCurrentState {};
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation)->get_CurrentRadioState(&pCurrentState));
    return pCurrentState;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandPinManager impl_IMobileBroadbandDeviceInformation2<D>::PinManager() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandPinManager value { nullptr };
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation2)->get_PinManager(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandDeviceInformation2<D>::Revision() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation2)->get_Revision(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandDeviceInformation2<D>::SerialNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceInformation2)->get_SerialNumber(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::Connectivity::NetworkAdapter impl_IMobileBroadbandNetwork<D>::NetworkAdapter() const
{
    Windows::Networking::Connectivity::NetworkAdapter value { nullptr };
    check_hresult(WINRT_SHIM(IMobileBroadbandNetwork)->get_NetworkAdapter(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::NetworkRegistrationState impl_IMobileBroadbandNetwork<D>::NetworkRegistrationState() const
{
    Windows::Networking::NetworkOperators::NetworkRegistrationState registrationState {};
    check_hresult(WINRT_SHIM(IMobileBroadbandNetwork)->get_NetworkRegistrationState(&registrationState));
    return registrationState;
}

template <typename D> uint32_t impl_IMobileBroadbandNetwork<D>::RegistrationNetworkError() const
{
    uint32_t networkError {};
    check_hresult(WINRT_SHIM(IMobileBroadbandNetwork)->get_RegistrationNetworkError(&networkError));
    return networkError;
}

template <typename D> uint32_t impl_IMobileBroadbandNetwork<D>::PacketAttachNetworkError() const
{
    uint32_t networkError {};
    check_hresult(WINRT_SHIM(IMobileBroadbandNetwork)->get_PacketAttachNetworkError(&networkError));
    return networkError;
}

template <typename D> uint32_t impl_IMobileBroadbandNetwork<D>::ActivationNetworkError() const
{
    uint32_t networkError {};
    check_hresult(WINRT_SHIM(IMobileBroadbandNetwork)->get_ActivationNetworkError(&networkError));
    return networkError;
}

template <typename D> hstring impl_IMobileBroadbandNetwork<D>::AccessPointName() const
{
    hstring apn;
    check_hresult(WINRT_SHIM(IMobileBroadbandNetwork)->get_AccessPointName(put_abi(apn)));
    return apn;
}

template <typename D> Windows::Networking::NetworkOperators::DataClasses impl_IMobileBroadbandNetwork<D>::RegisteredDataClass() const
{
    Windows::Networking::NetworkOperators::DataClasses value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandNetwork)->get_RegisteredDataClass(&value));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandNetwork<D>::RegisteredProviderId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandNetwork)->get_RegisteredProviderId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandNetwork<D>::RegisteredProviderName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandNetwork)->get_RegisteredProviderName(put_abi(value)));
    return value;
}

template <typename D> void impl_IMobileBroadbandNetwork<D>::ShowConnectionUI() const
{
    check_hresult(WINRT_SHIM(IMobileBroadbandNetwork)->abi_ShowConnectionUI());
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IMobileBroadbandNetwork2<D>::GetVoiceCallSupportAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> asyncInfo;
    check_hresult(WINRT_SHIM(IMobileBroadbandNetwork2)->abi_GetVoiceCallSupportAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandUiccApp> impl_IMobileBroadbandNetwork2<D>::RegistrationUiccApps() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandUiccApp> value;
    check_hresult(WINRT_SHIM(IMobileBroadbandNetwork2)->get_RegistrationUiccApps(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INetworkOperatorTetheringAccessPointConfiguration<D>::Ssid() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringAccessPointConfiguration)->get_Ssid(put_abi(value)));
    return value;
}

template <typename D> void impl_INetworkOperatorTetheringAccessPointConfiguration<D>::Ssid(hstring_view value) const
{
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringAccessPointConfiguration)->put_Ssid(get_abi(value)));
}

template <typename D> hstring impl_INetworkOperatorTetheringAccessPointConfiguration<D>::Passphrase() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringAccessPointConfiguration)->get_Passphrase(put_abi(value)));
    return value;
}

template <typename D> void impl_INetworkOperatorTetheringAccessPointConfiguration<D>::Passphrase(hstring_view value) const
{
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringAccessPointConfiguration)->put_Passphrase(get_abi(value)));
}

template <typename D> Windows::Networking::NetworkOperators::TetheringOperationStatus impl_INetworkOperatorTetheringOperationResult<D>::Status() const
{
    Windows::Networking::NetworkOperators::TetheringOperationStatus value {};
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringOperationResult)->get_Status(&value));
    return value;
}

template <typename D> hstring impl_INetworkOperatorTetheringOperationResult<D>::AdditionalErrorMessage() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringOperationResult)->get_AdditionalErrorMessage(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::TetheringCapability impl_INetworkOperatorTetheringManagerStatics<D>::GetTetheringCapability(hstring_view networkAccountId) const
{
    Windows::Networking::NetworkOperators::TetheringCapability value {};
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringManagerStatics)->abi_GetTetheringCapability(get_abi(networkAccountId), &value));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::NetworkOperatorTetheringManager impl_INetworkOperatorTetheringManagerStatics<D>::CreateFromNetworkAccountId(hstring_view networkAccountId) const
{
    Windows::Networking::NetworkOperators::NetworkOperatorTetheringManager ppManager { nullptr };
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringManagerStatics)->abi_CreateFromNetworkAccountId(get_abi(networkAccountId), put_abi(ppManager)));
    return ppManager;
}

template <typename D> Windows::Networking::NetworkOperators::TetheringCapability impl_INetworkOperatorTetheringManagerStatics2<D>::GetTetheringCapabilityFromConnectionProfile(const Windows::Networking::Connectivity::ConnectionProfile & profile) const
{
    Windows::Networking::NetworkOperators::TetheringCapability result {};
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringManagerStatics2)->abi_GetTetheringCapabilityFromConnectionProfile(get_abi(profile), &result));
    return result;
}

template <typename D> Windows::Networking::NetworkOperators::NetworkOperatorTetheringManager impl_INetworkOperatorTetheringManagerStatics2<D>::CreateFromConnectionProfile(const Windows::Networking::Connectivity::ConnectionProfile & profile) const
{
    Windows::Networking::NetworkOperators::NetworkOperatorTetheringManager ppManager { nullptr };
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringManagerStatics2)->abi_CreateFromConnectionProfile(get_abi(profile), put_abi(ppManager)));
    return ppManager;
}

template <typename D> Windows::Networking::NetworkOperators::NetworkOperatorTetheringManager impl_INetworkOperatorTetheringManagerStatics3<D>::CreateFromConnectionProfile(const Windows::Networking::Connectivity::ConnectionProfile & profile, const Windows::Networking::Connectivity::NetworkAdapter & adapter) const
{
    Windows::Networking::NetworkOperators::NetworkOperatorTetheringManager ppManager { nullptr };
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringManagerStatics3)->abi_CreateFromConnectionProfileWithTargetAdapter(get_abi(profile), get_abi(adapter), put_abi(ppManager)));
    return ppManager;
}

template <typename D> uint32_t impl_INetworkOperatorTetheringManager<D>::MaxClientCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringManager)->get_MaxClientCount(&value));
    return value;
}

template <typename D> uint32_t impl_INetworkOperatorTetheringManager<D>::ClientCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringManager)->get_ClientCount(&value));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::TetheringOperationalState impl_INetworkOperatorTetheringManager<D>::TetheringOperationalState() const
{
    Windows::Networking::NetworkOperators::TetheringOperationalState value {};
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringManager)->get_TetheringOperationalState(&value));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::NetworkOperatorTetheringAccessPointConfiguration impl_INetworkOperatorTetheringManager<D>::GetCurrentAccessPointConfiguration() const
{
    Windows::Networking::NetworkOperators::NetworkOperatorTetheringAccessPointConfiguration configuration { nullptr };
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringManager)->abi_GetCurrentAccessPointConfiguration(put_abi(configuration)));
    return configuration;
}

template <typename D> Windows::Foundation::IAsyncAction impl_INetworkOperatorTetheringManager<D>::ConfigureAccessPointAsync(const Windows::Networking::NetworkOperators::NetworkOperatorTetheringAccessPointConfiguration & configuration) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringManager)->abi_ConfigureAccessPointAsync(get_abi(configuration), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult> impl_INetworkOperatorTetheringManager<D>::StartTetheringAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult> asyncInfo;
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringManager)->abi_StartTetheringAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult> impl_INetworkOperatorTetheringManager<D>::StopTetheringAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult> asyncInfo;
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringManager)->abi_StopTetheringAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> hstring impl_INetworkOperatorTetheringClient<D>::MacAddress() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringClient)->get_MacAddress(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> impl_INetworkOperatorTetheringClient<D>::HostNames() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> value;
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringClient)->get_HostNames(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::NetworkOperatorTetheringClient> impl_INetworkOperatorTetheringClientManager<D>::GetTetheringClients() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::NetworkOperatorTetheringClient> value;
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringClientManager)->abi_GetTetheringClients(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandAccountEventArgs<D>::NetworkAccountId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountEventArgs)->get_NetworkAccountId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandAccountUpdatedEventArgs<D>::NetworkAccountId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountUpdatedEventArgs)->get_NetworkAccountId(put_abi(value)));
    return value;
}

template <typename D> bool impl_IMobileBroadbandAccountUpdatedEventArgs<D>::HasDeviceInformationChanged() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountUpdatedEventArgs)->get_HasDeviceInformationChanged(&value));
    return value;
}

template <typename D> bool impl_IMobileBroadbandAccountUpdatedEventArgs<D>::HasNetworkChanged() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountUpdatedEventArgs)->get_HasNetworkChanged(&value));
    return value;
}

template <typename D> event_token impl_IMobileBroadbandAccountWatcher<D>::AccountAdded(const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Networking::NetworkOperators::MobileBroadbandAccountEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountWatcher)->add_AccountAdded(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMobileBroadbandAccountWatcher> impl_IMobileBroadbandAccountWatcher<D>::AccountAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Networking::NetworkOperators::MobileBroadbandAccountEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMobileBroadbandAccountWatcher>(this, &ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher::remove_AccountAdded, AccountAdded(handler));
}

template <typename D> void impl_IMobileBroadbandAccountWatcher<D>::AccountAdded(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountWatcher)->remove_AccountAdded(cookie));
}

template <typename D> event_token impl_IMobileBroadbandAccountWatcher<D>::AccountUpdated(const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Networking::NetworkOperators::MobileBroadbandAccountUpdatedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountWatcher)->add_AccountUpdated(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMobileBroadbandAccountWatcher> impl_IMobileBroadbandAccountWatcher<D>::AccountUpdated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Networking::NetworkOperators::MobileBroadbandAccountUpdatedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMobileBroadbandAccountWatcher>(this, &ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher::remove_AccountUpdated, AccountUpdated(handler));
}

template <typename D> void impl_IMobileBroadbandAccountWatcher<D>::AccountUpdated(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountWatcher)->remove_AccountUpdated(cookie));
}

template <typename D> event_token impl_IMobileBroadbandAccountWatcher<D>::AccountRemoved(const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Networking::NetworkOperators::MobileBroadbandAccountEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountWatcher)->add_AccountRemoved(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMobileBroadbandAccountWatcher> impl_IMobileBroadbandAccountWatcher<D>::AccountRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Networking::NetworkOperators::MobileBroadbandAccountEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IMobileBroadbandAccountWatcher>(this, &ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher::remove_AccountRemoved, AccountRemoved(handler));
}

template <typename D> void impl_IMobileBroadbandAccountWatcher<D>::AccountRemoved(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountWatcher)->remove_AccountRemoved(cookie));
}

template <typename D> event_token impl_IMobileBroadbandAccountWatcher<D>::EnumerationCompleted(const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountWatcher)->add_EnumerationCompleted(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMobileBroadbandAccountWatcher> impl_IMobileBroadbandAccountWatcher<D>::EnumerationCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMobileBroadbandAccountWatcher>(this, &ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher::remove_EnumerationCompleted, EnumerationCompleted(handler));
}

template <typename D> void impl_IMobileBroadbandAccountWatcher<D>::EnumerationCompleted(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountWatcher)->remove_EnumerationCompleted(cookie));
}

template <typename D> event_token impl_IMobileBroadbandAccountWatcher<D>::Stopped(const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountWatcher)->add_Stopped(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<IMobileBroadbandAccountWatcher> impl_IMobileBroadbandAccountWatcher<D>::Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcher, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IMobileBroadbandAccountWatcher>(this, &ABI::Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher::remove_Stopped, Stopped(handler));
}

template <typename D> void impl_IMobileBroadbandAccountWatcher<D>::Stopped(event_token cookie) const
{
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountWatcher)->remove_Stopped(cookie));
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcherStatus impl_IMobileBroadbandAccountWatcher<D>::Status() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandAccountWatcherStatus status {};
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountWatcher)->get_Status(&status));
    return status;
}

template <typename D> void impl_IMobileBroadbandAccountWatcher<D>::Start() const
{
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountWatcher)->abi_Start());
}

template <typename D> void impl_IMobileBroadbandAccountWatcher<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IMobileBroadbandAccountWatcher)->abi_Stop());
}

template <typename D> hstring impl_IMobileBroadbandModemStatics<D>::GetDeviceSelector() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandModemStatics)->abi_GetDeviceSelector(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandModem impl_IMobileBroadbandModemStatics<D>::FromId(hstring_view deviceId) const
{
    Windows::Networking::NetworkOperators::MobileBroadbandModem value { nullptr };
    check_hresult(WINRT_SHIM(IMobileBroadbandModemStatics)->abi_FromId(get_abi(deviceId), put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandModem impl_IMobileBroadbandModemStatics<D>::GetDefault() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandModem value { nullptr };
    check_hresult(WINRT_SHIM(IMobileBroadbandModemStatics)->abi_GetDefault(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandUicc impl_IMobileBroadbandModemConfiguration<D>::Uicc() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandUicc value { nullptr };
    check_hresult(WINRT_SHIM(IMobileBroadbandModemConfiguration)->get_Uicc(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandModemConfiguration<D>::HomeProviderId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandModemConfiguration)->get_HomeProviderId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandModemConfiguration<D>::HomeProviderName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandModemConfiguration)->get_HomeProviderName(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandAccount impl_IMobileBroadbandModem<D>::CurrentAccount() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandAccount value { nullptr };
    check_hresult(WINRT_SHIM(IMobileBroadbandModem)->get_CurrentAccount(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandDeviceInformation impl_IMobileBroadbandModem<D>::DeviceInformation() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandDeviceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IMobileBroadbandModem)->get_DeviceInformation(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IMobileBroadbandModem<D>::MaxDeviceServiceCommandSizeInBytes() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandModem)->get_MaxDeviceServiceCommandSizeInBytes(&value));
    return value;
}

template <typename D> uint32_t impl_IMobileBroadbandModem<D>::MaxDeviceServiceDataSizeInBytes() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandModem)->get_MaxDeviceServiceDataSizeInBytes(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceInformation> impl_IMobileBroadbandModem<D>::DeviceServices() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceInformation> value;
    check_hresult(WINRT_SHIM(IMobileBroadbandModem)->get_DeviceServices(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandDeviceService impl_IMobileBroadbandModem<D>::GetDeviceService(GUID deviceServiceId) const
{
    Windows::Networking::NetworkOperators::MobileBroadbandDeviceService value { nullptr };
    check_hresult(WINRT_SHIM(IMobileBroadbandModem)->abi_GetDeviceService(deviceServiceId, put_abi(value)));
    return value;
}

template <typename D> bool impl_IMobileBroadbandModem<D>::IsResetSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandModem)->get_IsResetSupported(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMobileBroadbandModem<D>::ResetAsync() const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMobileBroadbandModem)->abi_ResetAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandModemConfiguration> impl_IMobileBroadbandModem<D>::GetCurrentConfigurationAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandModemConfiguration> asyncInfo;
    check_hresult(WINRT_SHIM(IMobileBroadbandModem)->abi_GetCurrentConfigurationAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandNetwork impl_IMobileBroadbandModem<D>::CurrentNetwork() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandNetwork value { nullptr };
    check_hresult(WINRT_SHIM(IMobileBroadbandModem)->get_CurrentNetwork(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Networking::NetworkOperators::MobileBroadbandPinType> impl_IMobileBroadbandPinManager<D>::SupportedPins() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Networking::NetworkOperators::MobileBroadbandPinType> value;
    check_hresult(WINRT_SHIM(IMobileBroadbandPinManager)->get_SupportedPins(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandPin impl_IMobileBroadbandPinManager<D>::GetPin(Windows::Networking::NetworkOperators::MobileBroadbandPinType pinType) const
{
    Windows::Networking::NetworkOperators::MobileBroadbandPin value { nullptr };
    check_hresult(WINRT_SHIM(IMobileBroadbandPinManager)->abi_GetPin(pinType, put_abi(value)));
    return value;
}

template <typename D> bool impl_IMobileBroadbandPinOperationResult<D>::IsSuccessful() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandPinOperationResult)->get_IsSuccessful(&value));
    return value;
}

template <typename D> uint32_t impl_IMobileBroadbandPinOperationResult<D>::AttemptsRemaining() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandPinOperationResult)->get_AttemptsRemaining(&value));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandPinType impl_IMobileBroadbandPin<D>::Type() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandPinType value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandPin)->get_Type(&value));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandPinLockState impl_IMobileBroadbandPin<D>::LockState() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandPinLockState value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandPin)->get_LockState(&value));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandPinFormat impl_IMobileBroadbandPin<D>::Format() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandPinFormat value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandPin)->get_Format(&value));
    return value;
}

template <typename D> bool impl_IMobileBroadbandPin<D>::Enabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandPin)->get_Enabled(&value));
    return value;
}

template <typename D> uint32_t impl_IMobileBroadbandPin<D>::MaxLength() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandPin)->get_MaxLength(&value));
    return value;
}

template <typename D> uint32_t impl_IMobileBroadbandPin<D>::MinLength() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandPin)->get_MinLength(&value));
    return value;
}

template <typename D> uint32_t impl_IMobileBroadbandPin<D>::AttemptsRemaining() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandPin)->get_AttemptsRemaining(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult> impl_IMobileBroadbandPin<D>::EnableAsync(hstring_view currentPin) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult> asyncInfo;
    check_hresult(WINRT_SHIM(IMobileBroadbandPin)->abi_EnableAsync(get_abi(currentPin), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult> impl_IMobileBroadbandPin<D>::DisableAsync(hstring_view currentPin) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult> asyncInfo;
    check_hresult(WINRT_SHIM(IMobileBroadbandPin)->abi_DisableAsync(get_abi(currentPin), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult> impl_IMobileBroadbandPin<D>::EnterAsync(hstring_view currentPin) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult> asyncInfo;
    check_hresult(WINRT_SHIM(IMobileBroadbandPin)->abi_EnterAsync(get_abi(currentPin), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult> impl_IMobileBroadbandPin<D>::ChangeAsync(hstring_view currentPin, hstring_view newPin) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult> asyncInfo;
    check_hresult(WINRT_SHIM(IMobileBroadbandPin)->abi_ChangeAsync(get_abi(currentPin), get_abi(newPin), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult> impl_IMobileBroadbandPin<D>::UnblockAsync(hstring_view pinUnblockKey, hstring_view newPin) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandPinOperationResult> asyncInfo;
    check_hresult(WINRT_SHIM(IMobileBroadbandPin)->abi_UnblockAsync(get_abi(pinUnblockKey), get_abi(newPin), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> GUID impl_IMobileBroadbandDeviceServiceInformation<D>::DeviceServiceId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceServiceInformation)->get_DeviceServiceId(&value));
    return value;
}

template <typename D> bool impl_IMobileBroadbandDeviceServiceInformation<D>::IsDataReadSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceServiceInformation)->get_IsDataReadSupported(&value));
    return value;
}

template <typename D> bool impl_IMobileBroadbandDeviceServiceInformation<D>::IsDataWriteSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceServiceInformation)->get_IsDataWriteSupported(&value));
    return value;
}

template <typename D> GUID impl_IMobileBroadbandDeviceService<D>::DeviceServiceId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceService)->get_DeviceServiceId(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IMobileBroadbandDeviceService<D>::SupportedCommands() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceService)->get_SupportedCommands(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataSession impl_IMobileBroadbandDeviceService<D>::OpenDataSession() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataSession value { nullptr };
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceService)->abi_OpenDataSession(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandSession impl_IMobileBroadbandDeviceService<D>::OpenCommandSession() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandSession value { nullptr };
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceService)->abi_OpenCommandSession(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IMobileBroadbandDeviceServiceDataReceivedEventArgs<D>::ReceivedData() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceServiceDataReceivedEventArgs)->get_ReceivedData(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IMobileBroadbandDeviceServiceDataSession<D>::WriteDataAsync(const Windows::Storage::Streams::IBuffer & value) const
{
    Windows::Foundation::IAsyncAction asyncInfo;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceServiceDataSession)->abi_WriteDataAsync(get_abi(value), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> void impl_IMobileBroadbandDeviceServiceDataSession<D>::CloseSession() const
{
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceServiceDataSession)->abi_CloseSession());
}

template <typename D> event_token impl_IMobileBroadbandDeviceServiceDataSession<D>::DataReceived(const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataSession, Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataReceivedEventArgs> & eventHandler) const
{
    event_token eventCookie {};
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceServiceDataSession)->add_DataReceived(get_abi(eventHandler), &eventCookie));
    return eventCookie;
}

template <typename D> event_revoker<IMobileBroadbandDeviceServiceDataSession> impl_IMobileBroadbandDeviceServiceDataSession<D>::DataReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataSession, Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataReceivedEventArgs> & eventHandler) const
{
    return impl::make_event_revoker<D, IMobileBroadbandDeviceServiceDataSession>(this, &ABI::Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession::remove_DataReceived, DataReceived(eventHandler));
}

template <typename D> void impl_IMobileBroadbandDeviceServiceDataSession<D>::DataReceived(event_token eventCookie) const
{
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceServiceDataSession)->remove_DataReceived(eventCookie));
}

template <typename D> uint32_t impl_IMobileBroadbandDeviceServiceCommandResult<D>::StatusCode() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceServiceCommandResult)->get_StatusCode(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IMobileBroadbandDeviceServiceCommandResult<D>::ResponseData() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceServiceCommandResult)->get_ResponseData(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult> impl_IMobileBroadbandDeviceServiceCommandSession<D>::SendQueryCommandAsync(uint32_t commandId, const Windows::Storage::Streams::IBuffer & data) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult> asyncInfo;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceServiceCommandSession)->abi_SendQueryCommandAsync(commandId, get_abi(data), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult> impl_IMobileBroadbandDeviceServiceCommandSession<D>::SendSetCommandAsync(uint32_t commandId, const Windows::Storage::Streams::IBuffer & data) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult> asyncInfo;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceServiceCommandSession)->abi_SendSetCommandAsync(commandId, get_abi(data), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> void impl_IMobileBroadbandDeviceServiceCommandSession<D>::CloseSession() const
{
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceServiceCommandSession)->abi_CloseSession());
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus impl_IMobileBroadbandUiccAppsResult<D>::Status() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandUiccAppsResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandUiccApp> impl_IMobileBroadbandUiccAppsResult<D>::UiccApps() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandUiccApp> value;
    check_hresult(WINRT_SHIM(IMobileBroadbandUiccAppsResult)->get_UiccApps(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandUicc<D>::SimIccId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandUicc)->get_SimIccId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandUiccAppsResult> impl_IMobileBroadbandUicc<D>::GetUiccAppsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandUiccAppsResult> asyncInfo;
    check_hresult(WINRT_SHIM(IMobileBroadbandUicc)->abi_GetUiccAppsAsync(put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus impl_IMobileBroadbandUiccAppRecordDetailsResult<D>::Status() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandUiccAppRecordDetailsResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::UiccAppRecordKind impl_IMobileBroadbandUiccAppRecordDetailsResult<D>::Kind() const
{
    Windows::Networking::NetworkOperators::UiccAppRecordKind value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandUiccAppRecordDetailsResult)->get_Kind(&value));
    return value;
}

template <typename D> int32_t impl_IMobileBroadbandUiccAppRecordDetailsResult<D>::RecordCount() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandUiccAppRecordDetailsResult)->get_RecordCount(&value));
    return value;
}

template <typename D> int32_t impl_IMobileBroadbandUiccAppRecordDetailsResult<D>::RecordSize() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandUiccAppRecordDetailsResult)->get_RecordSize(&value));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::UiccAccessCondition impl_IMobileBroadbandUiccAppRecordDetailsResult<D>::ReadAccessCondition() const
{
    Windows::Networking::NetworkOperators::UiccAccessCondition value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandUiccAppRecordDetailsResult)->get_ReadAccessCondition(&value));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::UiccAccessCondition impl_IMobileBroadbandUiccAppRecordDetailsResult<D>::WriteAccessCondition() const
{
    Windows::Networking::NetworkOperators::UiccAccessCondition value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandUiccAppRecordDetailsResult)->get_WriteAccessCondition(&value));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus impl_IMobileBroadbandUiccAppReadRecordResult<D>::Status() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandUiccAppReadRecordResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IMobileBroadbandUiccAppReadRecordResult<D>::Data() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IMobileBroadbandUiccAppReadRecordResult)->get_Data(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IMobileBroadbandUiccApp<D>::Id() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IMobileBroadbandUiccApp)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::UiccAppKind impl_IMobileBroadbandUiccApp<D>::Kind() const
{
    Windows::Networking::NetworkOperators::UiccAppKind value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandUiccApp)->get_Kind(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandUiccAppRecordDetailsResult> impl_IMobileBroadbandUiccApp<D>::GetRecordDetailsAsync(iterable<uint32_t> uiccFilePath) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandUiccAppRecordDetailsResult> asyncInfo;
    check_hresult(WINRT_SHIM(IMobileBroadbandUiccApp)->abi_GetRecordDetailsAsync(get_abi(uiccFilePath), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandUiccAppReadRecordResult> impl_IMobileBroadbandUiccApp<D>::ReadRecordAsync(iterable<uint32_t> uiccFilePath, int32_t recordIndex) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::MobileBroadbandUiccAppReadRecordResult> asyncInfo;
    check_hresult(WINRT_SHIM(IMobileBroadbandUiccApp)->abi_ReadRecordAsync(get_abi(uiccFilePath), recordIndex, put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> hstring impl_IMobileBroadbandNetworkRegistrationStateChange<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandNetworkRegistrationStateChange)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandNetwork impl_IMobileBroadbandNetworkRegistrationStateChange<D>::Network() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandNetwork value { nullptr };
    check_hresult(WINRT_SHIM(IMobileBroadbandNetworkRegistrationStateChange)->get_Network(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandNetworkRegistrationStateChange> impl_IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails<D>::NetworkRegistrationStateChanges() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandNetworkRegistrationStateChange> value;
    check_hresult(WINRT_SHIM(IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails)->get_NetworkRegistrationStateChanges(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandRadioStateChange<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandRadioStateChange)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandRadioState impl_IMobileBroadbandRadioStateChange<D>::RadioState() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandRadioState value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandRadioStateChange)->get_RadioState(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandRadioStateChange> impl_IMobileBroadbandRadioStateChangeTriggerDetails<D>::RadioStateChanges() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandRadioStateChange> value;
    check_hresult(WINRT_SHIM(IMobileBroadbandRadioStateChangeTriggerDetails)->get_RadioStateChanges(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandPinLockStateChange<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandPinLockStateChange)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandPinType impl_IMobileBroadbandPinLockStateChange<D>::PinType() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandPinType value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandPinLockStateChange)->get_PinType(&value));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::MobileBroadbandPinLockState impl_IMobileBroadbandPinLockStateChange<D>::PinLockState() const
{
    Windows::Networking::NetworkOperators::MobileBroadbandPinLockState value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandPinLockStateChange)->get_PinLockState(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandPinLockStateChange> impl_IMobileBroadbandPinLockStateChangeTriggerDetails<D>::PinLockStateChanges() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::NetworkOperators::MobileBroadbandPinLockStateChange> value;
    check_hresult(WINRT_SHIM(IMobileBroadbandPinLockStateChangeTriggerDetails)->get_PinLockStateChanges(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IMobileBroadbandDeviceServiceTriggerDetails<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceServiceTriggerDetails)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> GUID impl_IMobileBroadbandDeviceServiceTriggerDetails<D>::DeviceServiceId() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceServiceTriggerDetails)->get_DeviceServiceId(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IMobileBroadbandDeviceServiceTriggerDetails<D>::ReceivedData() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IMobileBroadbandDeviceServiceTriggerDetails)->get_ReceivedData(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IKnownCSimFilePathsStatics<D>::EFSpn() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IKnownCSimFilePathsStatics)->get_EFSpn(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IKnownCSimFilePathsStatics<D>::Gid1() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IKnownCSimFilePathsStatics)->get_Gid1(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IKnownCSimFilePathsStatics<D>::Gid2() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IKnownCSimFilePathsStatics)->get_Gid2(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IKnownRuimFilePathsStatics<D>::EFSpn() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IKnownRuimFilePathsStatics)->get_EFSpn(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IKnownRuimFilePathsStatics<D>::Gid1() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IKnownRuimFilePathsStatics)->get_Gid1(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IKnownRuimFilePathsStatics<D>::Gid2() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IKnownRuimFilePathsStatics)->get_Gid2(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IKnownSimFilePathsStatics<D>::EFOns() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IKnownSimFilePathsStatics)->get_EFOns(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IKnownSimFilePathsStatics<D>::EFSpn() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IKnownSimFilePathsStatics)->get_EFSpn(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IKnownSimFilePathsStatics<D>::Gid1() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IKnownSimFilePathsStatics)->get_Gid1(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IKnownSimFilePathsStatics<D>::Gid2() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IKnownSimFilePathsStatics)->get_Gid2(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IKnownUSimFilePathsStatics<D>::EFSpn() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IKnownUSimFilePathsStatics)->get_EFSpn(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IKnownUSimFilePathsStatics<D>::EFOpl() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IKnownUSimFilePathsStatics)->get_EFOpl(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IKnownUSimFilePathsStatics<D>::EFPnn() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IKnownUSimFilePathsStatics)->get_EFPnn(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IKnownUSimFilePathsStatics<D>::Gid1() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IKnownUSimFilePathsStatics)->get_Gid1(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<uint32_t> impl_IKnownUSimFilePathsStatics<D>::Gid2() const
{
    Windows::Foundation::Collections::IVectorView<uint32_t> value;
    check_hresult(WINRT_SHIM(IKnownUSimFilePathsStatics)->get_Gid2(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IHotspotAuthenticationEventDetails<D>::EventToken() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IHotspotAuthenticationEventDetails)->get_EventToken(put_abi(value)));
    return value;
}

template <typename D> bool impl_IHotspotAuthenticationContextStatics<D>::TryGetAuthenticationContext(hstring_view evenToken, Windows::Networking::NetworkOperators::HotspotAuthenticationContext & context) const
{
    bool isValid {};
    check_hresult(WINRT_SHIM(IHotspotAuthenticationContextStatics)->abi_TryGetAuthenticationContext(get_abi(evenToken), put_abi(context), &isValid));
    return isValid;
}

template <typename D> com_array<uint8_t> impl_IHotspotAuthenticationContext<D>::WirelessNetworkId() const
{
    com_array<uint8_t> value {};
    check_hresult(WINRT_SHIM(IHotspotAuthenticationContext)->get_WirelessNetworkId(impl::put_size_abi(value), put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::Connectivity::NetworkAdapter impl_IHotspotAuthenticationContext<D>::NetworkAdapter() const
{
    Windows::Networking::Connectivity::NetworkAdapter value { nullptr };
    check_hresult(WINRT_SHIM(IHotspotAuthenticationContext)->get_NetworkAdapter(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IHotspotAuthenticationContext<D>::RedirectMessageUrl() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IHotspotAuthenticationContext)->get_RedirectMessageUrl(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::XmlDocument impl_IHotspotAuthenticationContext<D>::RedirectMessageXml() const
{
    Windows::Data::Xml::Dom::XmlDocument value { nullptr };
    check_hresult(WINRT_SHIM(IHotspotAuthenticationContext)->get_RedirectMessageXml(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IHotspotAuthenticationContext<D>::AuthenticationUrl() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IHotspotAuthenticationContext)->get_AuthenticationUrl(put_abi(value)));
    return value;
}

template <typename D> void impl_IHotspotAuthenticationContext<D>::IssueCredentials(hstring_view userName, hstring_view password, hstring_view extraParameters, bool markAsManualConnectOnFailure) const
{
    check_hresult(WINRT_SHIM(IHotspotAuthenticationContext)->abi_IssueCredentials(get_abi(userName), get_abi(password), get_abi(extraParameters), markAsManualConnectOnFailure));
}

template <typename D> void impl_IHotspotAuthenticationContext<D>::AbortAuthentication(bool markAsManual) const
{
    check_hresult(WINRT_SHIM(IHotspotAuthenticationContext)->abi_AbortAuthentication(markAsManual));
}

template <typename D> void impl_IHotspotAuthenticationContext<D>::SkipAuthentication() const
{
    check_hresult(WINRT_SHIM(IHotspotAuthenticationContext)->abi_SkipAuthentication());
}

template <typename D> void impl_IHotspotAuthenticationContext<D>::TriggerAttentionRequired(hstring_view packageRelativeApplicationId, hstring_view applicationParameters) const
{
    check_hresult(WINRT_SHIM(IHotspotAuthenticationContext)->abi_TriggerAttentionRequired(get_abi(packageRelativeApplicationId), get_abi(applicationParameters)));
}

template <typename D> bool impl_IHotspotCredentialsAuthenticationResult<D>::HasNetworkErrorOccurred() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IHotspotCredentialsAuthenticationResult)->get_HasNetworkErrorOccurred(&value));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::HotspotAuthenticationResponseCode impl_IHotspotCredentialsAuthenticationResult<D>::ResponseCode() const
{
    Windows::Networking::NetworkOperators::HotspotAuthenticationResponseCode value {};
    check_hresult(WINRT_SHIM(IHotspotCredentialsAuthenticationResult)->get_ResponseCode(&value));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IHotspotCredentialsAuthenticationResult<D>::LogoffUrl() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IHotspotCredentialsAuthenticationResult)->get_LogoffUrl(put_abi(value)));
    return value;
}

template <typename D> Windows::Data::Xml::Dom::XmlDocument impl_IHotspotCredentialsAuthenticationResult<D>::AuthenticationReplyXml() const
{
    Windows::Data::Xml::Dom::XmlDocument value { nullptr };
    check_hresult(WINRT_SHIM(IHotspotCredentialsAuthenticationResult)->get_AuthenticationReplyXml(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::HotspotCredentialsAuthenticationResult> impl_IHotspotAuthenticationContext2<D>::IssueCredentialsAsync(hstring_view userName, hstring_view password, hstring_view extraParameters, bool markAsManualConnectOnFailure) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::HotspotCredentialsAuthenticationResult> asyncInfo;
    check_hresult(WINRT_SHIM(IHotspotAuthenticationContext2)->abi_IssueCredentialsAsync(get_abi(userName), get_abi(password), get_abi(extraParameters), markAsManualConnectOnFailure, put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> bool impl_IProvisionFromXmlDocumentResults<D>::AllElementsProvisioned() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IProvisionFromXmlDocumentResults)->get_AllElementsProvisioned(&value));
    return value;
}

template <typename D> hstring impl_IProvisionFromXmlDocumentResults<D>::ProvisionResultsXml() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProvisionFromXmlDocumentResults)->get_ProvisionResultsXml(put_abi(value)));
    return value;
}

template <typename D> void impl_IProvisionedProfile<D>::UpdateCost(Windows::Networking::Connectivity::NetworkCostType value) const
{
    check_hresult(WINRT_SHIM(IProvisionedProfile)->abi_UpdateCost(value));
}

template <typename D> void impl_IProvisionedProfile<D>::UpdateUsage(const Windows::Networking::NetworkOperators::ProfileUsage & value) const
{
    check_hresult(WINRT_SHIM(IProvisionedProfile)->abi_UpdateUsage(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::ProvisionFromXmlDocumentResults> impl_IProvisioningAgent<D>::ProvisionFromXmlDocumentAsync(hstring_view provisioningXmlDocument) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::ProvisionFromXmlDocumentResults> asyncInfo;
    check_hresult(WINRT_SHIM(IProvisioningAgent)->abi_ProvisionFromXmlDocumentAsync(get_abi(provisioningXmlDocument), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> Windows::Networking::NetworkOperators::ProvisionedProfile impl_IProvisioningAgent<D>::GetProvisionedProfile(Windows::Networking::NetworkOperators::ProfileMediaType mediaType, hstring_view profileName) const
{
    Windows::Networking::NetworkOperators::ProvisionedProfile provisionedProfile { nullptr };
    check_hresult(WINRT_SHIM(IProvisioningAgent)->abi_GetProvisionedProfile(mediaType, get_abi(profileName), put_abi(provisionedProfile)));
    return provisionedProfile;
}

template <typename D> Windows::Networking::NetworkOperators::ProvisioningAgent impl_IProvisioningAgentStaticMethods<D>::CreateFromNetworkAccountId(hstring_view networkAccountId) const
{
    Windows::Networking::NetworkOperators::ProvisioningAgent provisioningAgent { nullptr };
    check_hresult(WINRT_SHIM(IProvisioningAgentStaticMethods)->abi_CreateFromNetworkAccountId(get_abi(networkAccountId), put_abi(provisioningAgent)));
    return provisioningAgent;
}

template <typename D> uint8_t impl_IUssdMessage<D>::DataCodingScheme() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IUssdMessage)->get_DataCodingScheme(&value));
    return value;
}

template <typename D> void impl_IUssdMessage<D>::DataCodingScheme(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IUssdMessage)->put_DataCodingScheme(value));
}

template <typename D> com_array<uint8_t> impl_IUssdMessage<D>::GetPayload() const
{
    com_array<uint8_t> value {};
    check_hresult(WINRT_SHIM(IUssdMessage)->abi_GetPayload(impl::put_size_abi(value), put_abi(value)));
    return value;
}

template <typename D> void impl_IUssdMessage<D>::SetPayload(array_view<const uint8_t> value) const
{
    check_hresult(WINRT_SHIM(IUssdMessage)->abi_SetPayload(value.size(), get_abi(value)));
}

template <typename D> hstring impl_IUssdMessage<D>::PayloadAsText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IUssdMessage)->get_PayloadAsText(put_abi(value)));
    return value;
}

template <typename D> void impl_IUssdMessage<D>::PayloadAsText(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IUssdMessage)->put_PayloadAsText(get_abi(value)));
}

template <typename D> Windows::Networking::NetworkOperators::UssdMessage impl_IUssdMessageFactory<D>::CreateMessage(hstring_view messageText) const
{
    Windows::Networking::NetworkOperators::UssdMessage ussdMessage { nullptr };
    check_hresult(WINRT_SHIM(IUssdMessageFactory)->abi_CreateMessage(get_abi(messageText), put_abi(ussdMessage)));
    return ussdMessage;
}

template <typename D> Windows::Networking::NetworkOperators::UssdResultCode impl_IUssdReply<D>::ResultCode() const
{
    Windows::Networking::NetworkOperators::UssdResultCode value {};
    check_hresult(WINRT_SHIM(IUssdReply)->get_ResultCode(&value));
    return value;
}

template <typename D> Windows::Networking::NetworkOperators::UssdMessage impl_IUssdReply<D>::Message() const
{
    Windows::Networking::NetworkOperators::UssdMessage value { nullptr };
    check_hresult(WINRT_SHIM(IUssdReply)->get_Message(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::UssdReply> impl_IUssdSession<D>::SendMessageAndGetReplyAsync(const Windows::Networking::NetworkOperators::UssdMessage & message) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::NetworkOperators::UssdReply> asyncInfo;
    check_hresult(WINRT_SHIM(IUssdSession)->abi_SendMessageAndGetReplyAsync(get_abi(message), put_abi(asyncInfo)));
    return asyncInfo;
}

template <typename D> void impl_IUssdSession<D>::Close() const
{
    check_hresult(WINRT_SHIM(IUssdSession)->abi_Close());
}

template <typename D> Windows::Networking::NetworkOperators::UssdSession impl_IUssdSessionStatics<D>::CreateFromNetworkAccountId(hstring_view networkAccountId) const
{
    Windows::Networking::NetworkOperators::UssdSession ussdSession { nullptr };
    check_hresult(WINRT_SHIM(IUssdSessionStatics)->abi_CreateFromNetworkAccountId(get_abi(networkAccountId), put_abi(ussdSession)));
    return ussdSession;
}

template <typename D> Windows::Networking::NetworkOperators::UssdSession impl_IUssdSessionStatics<D>::CreateFromNetworkInterfaceId(hstring_view networkInterfaceId) const
{
    Windows::Networking::NetworkOperators::UssdSession ussdSession { nullptr };
    check_hresult(WINRT_SHIM(IUssdSessionStatics)->abi_CreateFromNetworkInterfaceId(get_abi(networkInterfaceId), put_abi(ussdSession)));
    return ussdSession;
}

template <typename D> Windows::Networking::NetworkOperators::NetworkOperatorEventMessageType impl_INetworkOperatorNotificationEventDetails<D>::NotificationType() const
{
    Windows::Networking::NetworkOperators::NetworkOperatorEventMessageType value {};
    check_hresult(WINRT_SHIM(INetworkOperatorNotificationEventDetails)->get_NotificationType(&value));
    return value;
}

template <typename D> hstring impl_INetworkOperatorNotificationEventDetails<D>::NetworkAccountId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INetworkOperatorNotificationEventDetails)->get_NetworkAccountId(put_abi(value)));
    return value;
}

template <typename D> uint8_t impl_INetworkOperatorNotificationEventDetails<D>::EncodingType() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(INetworkOperatorNotificationEventDetails)->get_EncodingType(&value));
    return value;
}

template <typename D> hstring impl_INetworkOperatorNotificationEventDetails<D>::Message() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INetworkOperatorNotificationEventDetails)->get_Message(put_abi(value)));
    return value;
}

template <typename D> hstring impl_INetworkOperatorNotificationEventDetails<D>::RuleId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(INetworkOperatorNotificationEventDetails)->get_RuleId(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Sms::ISmsMessage impl_INetworkOperatorNotificationEventDetails<D>::SmsMessage() const
{
    Windows::Devices::Sms::ISmsMessage value;
    check_hresult(WINRT_SHIM(INetworkOperatorNotificationEventDetails)->get_SmsMessage(put_abi(value)));
    return value;
}

template <typename D> void impl_INetworkOperatorTetheringEntitlementCheck<D>::AuthorizeTethering(bool allow, hstring_view entitlementFailureReason) const
{
    check_hresult(WINRT_SHIM(INetworkOperatorTetheringEntitlementCheck)->abi_AuthorizeTethering(allow, get_abi(entitlementFailureReason)));
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IFdnAccessManagerStatics<D>::RequestUnlockAsync(hstring_view contactListId) const
{
    Windows::Foundation::IAsyncOperation<bool> returnValue;
    check_hresult(WINRT_SHIM(IFdnAccessManagerStatics)->abi_RequestUnlockAsync(get_abi(contactListId), put_abi(returnValue)));
    return returnValue;
}

inline Windows::Foundation::IAsyncOperation<bool> FdnAccessManager::RequestUnlockAsync(hstring_view contactListId)
{
    return get_activation_factory<FdnAccessManager, IFdnAccessManagerStatics>().RequestUnlockAsync(contactListId);
}

inline bool HotspotAuthenticationContext::TryGetAuthenticationContext(hstring_view evenToken, Windows::Networking::NetworkOperators::HotspotAuthenticationContext & context)
{
    return get_activation_factory<HotspotAuthenticationContext, IHotspotAuthenticationContextStatics>().TryGetAuthenticationContext(evenToken, context);
}

inline Windows::Foundation::Collections::IVectorView<uint32_t> KnownCSimFilePaths::EFSpn()
{
    return get_activation_factory<KnownCSimFilePaths, IKnownCSimFilePathsStatics>().EFSpn();
}

inline Windows::Foundation::Collections::IVectorView<uint32_t> KnownCSimFilePaths::Gid1()
{
    return get_activation_factory<KnownCSimFilePaths, IKnownCSimFilePathsStatics>().Gid1();
}

inline Windows::Foundation::Collections::IVectorView<uint32_t> KnownCSimFilePaths::Gid2()
{
    return get_activation_factory<KnownCSimFilePaths, IKnownCSimFilePathsStatics>().Gid2();
}

inline Windows::Foundation::Collections::IVectorView<uint32_t> KnownRuimFilePaths::EFSpn()
{
    return get_activation_factory<KnownRuimFilePaths, IKnownRuimFilePathsStatics>().EFSpn();
}

inline Windows::Foundation::Collections::IVectorView<uint32_t> KnownRuimFilePaths::Gid1()
{
    return get_activation_factory<KnownRuimFilePaths, IKnownRuimFilePathsStatics>().Gid1();
}

inline Windows::Foundation::Collections::IVectorView<uint32_t> KnownRuimFilePaths::Gid2()
{
    return get_activation_factory<KnownRuimFilePaths, IKnownRuimFilePathsStatics>().Gid2();
}

inline Windows::Foundation::Collections::IVectorView<uint32_t> KnownSimFilePaths::EFOns()
{
    return get_activation_factory<KnownSimFilePaths, IKnownSimFilePathsStatics>().EFOns();
}

inline Windows::Foundation::Collections::IVectorView<uint32_t> KnownSimFilePaths::EFSpn()
{
    return get_activation_factory<KnownSimFilePaths, IKnownSimFilePathsStatics>().EFSpn();
}

inline Windows::Foundation::Collections::IVectorView<uint32_t> KnownSimFilePaths::Gid1()
{
    return get_activation_factory<KnownSimFilePaths, IKnownSimFilePathsStatics>().Gid1();
}

inline Windows::Foundation::Collections::IVectorView<uint32_t> KnownSimFilePaths::Gid2()
{
    return get_activation_factory<KnownSimFilePaths, IKnownSimFilePathsStatics>().Gid2();
}

inline Windows::Foundation::Collections::IVectorView<uint32_t> KnownUSimFilePaths::EFSpn()
{
    return get_activation_factory<KnownUSimFilePaths, IKnownUSimFilePathsStatics>().EFSpn();
}

inline Windows::Foundation::Collections::IVectorView<uint32_t> KnownUSimFilePaths::EFOpl()
{
    return get_activation_factory<KnownUSimFilePaths, IKnownUSimFilePathsStatics>().EFOpl();
}

inline Windows::Foundation::Collections::IVectorView<uint32_t> KnownUSimFilePaths::EFPnn()
{
    return get_activation_factory<KnownUSimFilePaths, IKnownUSimFilePathsStatics>().EFPnn();
}

inline Windows::Foundation::Collections::IVectorView<uint32_t> KnownUSimFilePaths::Gid1()
{
    return get_activation_factory<KnownUSimFilePaths, IKnownUSimFilePathsStatics>().Gid1();
}

inline Windows::Foundation::Collections::IVectorView<uint32_t> KnownUSimFilePaths::Gid2()
{
    return get_activation_factory<KnownUSimFilePaths, IKnownUSimFilePathsStatics>().Gid2();
}

inline Windows::Foundation::Collections::IVectorView<hstring> MobileBroadbandAccount::AvailableNetworkAccountIds()
{
    return get_activation_factory<MobileBroadbandAccount, IMobileBroadbandAccountStatics>().AvailableNetworkAccountIds();
}

inline Windows::Networking::NetworkOperators::MobileBroadbandAccount MobileBroadbandAccount::CreateFromNetworkAccountId(hstring_view networkAccountId)
{
    return get_activation_factory<MobileBroadbandAccount, IMobileBroadbandAccountStatics>().CreateFromNetworkAccountId(networkAccountId);
}

inline MobileBroadbandAccountWatcher::MobileBroadbandAccountWatcher() :
    MobileBroadbandAccountWatcher(activate_instance<MobileBroadbandAccountWatcher>())
{}

inline hstring MobileBroadbandModem::GetDeviceSelector()
{
    return get_activation_factory<MobileBroadbandModem, IMobileBroadbandModemStatics>().GetDeviceSelector();
}

inline Windows::Networking::NetworkOperators::MobileBroadbandModem MobileBroadbandModem::FromId(hstring_view deviceId)
{
    return get_activation_factory<MobileBroadbandModem, IMobileBroadbandModemStatics>().FromId(deviceId);
}

inline Windows::Networking::NetworkOperators::MobileBroadbandModem MobileBroadbandModem::GetDefault()
{
    return get_activation_factory<MobileBroadbandModem, IMobileBroadbandModemStatics>().GetDefault();
}

inline NetworkOperatorTetheringAccessPointConfiguration::NetworkOperatorTetheringAccessPointConfiguration() :
    NetworkOperatorTetheringAccessPointConfiguration(activate_instance<NetworkOperatorTetheringAccessPointConfiguration>())
{}

inline Windows::Networking::NetworkOperators::TetheringCapability NetworkOperatorTetheringManager::GetTetheringCapability(hstring_view networkAccountId)
{
    return get_activation_factory<NetworkOperatorTetheringManager, INetworkOperatorTetheringManagerStatics>().GetTetheringCapability(networkAccountId);
}

inline Windows::Networking::NetworkOperators::NetworkOperatorTetheringManager NetworkOperatorTetheringManager::CreateFromNetworkAccountId(hstring_view networkAccountId)
{
    return get_activation_factory<NetworkOperatorTetheringManager, INetworkOperatorTetheringManagerStatics>().CreateFromNetworkAccountId(networkAccountId);
}

inline Windows::Networking::NetworkOperators::TetheringCapability NetworkOperatorTetheringManager::GetTetheringCapabilityFromConnectionProfile(const Windows::Networking::Connectivity::ConnectionProfile & profile)
{
    return get_activation_factory<NetworkOperatorTetheringManager, INetworkOperatorTetheringManagerStatics2>().GetTetheringCapabilityFromConnectionProfile(profile);
}

inline Windows::Networking::NetworkOperators::NetworkOperatorTetheringManager NetworkOperatorTetheringManager::CreateFromConnectionProfile(const Windows::Networking::Connectivity::ConnectionProfile & profile)
{
    return get_activation_factory<NetworkOperatorTetheringManager, INetworkOperatorTetheringManagerStatics2>().CreateFromConnectionProfile(profile);
}

inline Windows::Networking::NetworkOperators::NetworkOperatorTetheringManager NetworkOperatorTetheringManager::CreateFromConnectionProfile(const Windows::Networking::Connectivity::ConnectionProfile & profile, const Windows::Networking::Connectivity::NetworkAdapter & adapter)
{
    return get_activation_factory<NetworkOperatorTetheringManager, INetworkOperatorTetheringManagerStatics3>().CreateFromConnectionProfile(profile, adapter);
}

inline ProvisioningAgent::ProvisioningAgent() :
    ProvisioningAgent(activate_instance<ProvisioningAgent>())
{}

inline Windows::Networking::NetworkOperators::ProvisioningAgent ProvisioningAgent::CreateFromNetworkAccountId(hstring_view networkAccountId)
{
    return get_activation_factory<ProvisioningAgent, IProvisioningAgentStaticMethods>().CreateFromNetworkAccountId(networkAccountId);
}

inline UssdMessage::UssdMessage(hstring_view messageText) :
    UssdMessage(get_activation_factory<UssdMessage, IUssdMessageFactory>().CreateMessage(messageText))
{}

inline Windows::Networking::NetworkOperators::UssdSession UssdSession::CreateFromNetworkAccountId(hstring_view networkAccountId)
{
    return get_activation_factory<UssdSession, IUssdSessionStatics>().CreateFromNetworkAccountId(networkAccountId);
}

inline Windows::Networking::NetworkOperators::UssdSession UssdSession::CreateFromNetworkInterfaceId(hstring_view networkInterfaceId)
{
    return get_activation_factory<UssdSession, IUssdSessionStatics>().CreateFromNetworkInterfaceId(networkInterfaceId);
}

}

}
#pragma warning(pop)
