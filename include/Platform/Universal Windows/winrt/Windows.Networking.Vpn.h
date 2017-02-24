// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Networking.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Security.Credentials.3.h"
#include "internal/Windows.Security.Cryptography.Certificates.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Networking.Vpn.3.h"
#include "Windows.Networking.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnAppId> : produce_base<D, Windows::Networking::Vpn::IVpnAppId>
{
    HRESULT __stdcall get_Type(Windows::Networking::Vpn::VpnAppIdType * value) noexcept override
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

    HRESULT __stdcall put_Type(Windows::Networking::Vpn::VpnAppIdType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Type(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Value(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnAppIdFactory> : produce_base<D, Windows::Networking::Vpn::IVpnAppIdFactory>
{
    HRESULT __stdcall abi_Create(Windows::Networking::Vpn::VpnAppIdType type, impl::abi_arg_in<hstring> value, impl::abi_arg_out<Windows::Networking::Vpn::IVpnAppId> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(type, *reinterpret_cast<const hstring *>(&value)));
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
struct produce<D, Windows::Networking::Vpn::IVpnChannel> : produce_base<D, Windows::Networking::Vpn::IVpnChannel>
{
    HRESULT __stdcall abi_AssociateTransport(impl::abi_arg_in<Windows::Foundation::IInspectable> mainOuterTunnelTransport, impl::abi_arg_in<Windows::Foundation::IInspectable> optionalOuterTunnelTransport) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AssociateTransport(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&mainOuterTunnelTransport), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&optionalOuterTunnelTransport));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Start(impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName>> assignedClientIPv4list, impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName>> assignedClientIPv6list, impl::abi_arg_in<Windows::Networking::Vpn::IVpnInterfaceId> vpnInterfaceId, impl::abi_arg_in<Windows::Networking::Vpn::IVpnRouteAssignment> routeScope, impl::abi_arg_in<Windows::Networking::Vpn::IVpnNamespaceAssignment> namespaceScope, uint32_t mtuSize, uint32_t maxFrameSize, bool optimizeForLowCostNetwork, impl::abi_arg_in<Windows::Foundation::IInspectable> mainOuterTunnelTransport, impl::abi_arg_in<Windows::Foundation::IInspectable> optionalOuterTunnelTransport) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start(*reinterpret_cast<const Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> *>(&assignedClientIPv4list), *reinterpret_cast<const Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> *>(&assignedClientIPv6list), *reinterpret_cast<const Windows::Networking::Vpn::VpnInterfaceId *>(&vpnInterfaceId), *reinterpret_cast<const Windows::Networking::Vpn::VpnRouteAssignment *>(&routeScope), *reinterpret_cast<const Windows::Networking::Vpn::VpnNamespaceAssignment *>(&namespaceScope), mtuSize, maxFrameSize, optimizeForLowCostNetwork, *reinterpret_cast<const Windows::Foundation::IInspectable *>(&mainOuterTunnelTransport), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&optionalOuterTunnelTransport));
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

    HRESULT __stdcall abi_RequestCredentials(Windows::Networking::Vpn::VpnCredentialType credType, bool isRetry, bool isSingleSignOnCredential, impl::abi_arg_in<Windows::Security::Cryptography::Certificates::ICertificate> certificate, impl::abi_arg_out<Windows::Networking::Vpn::IVpnPickedCredential> credential) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *credential = detach_abi(this->shim().RequestCredentials(credType, isRetry, isSingleSignOnCredential, *reinterpret_cast<const Windows::Security::Cryptography::Certificates::Certificate *>(&certificate)));
            return S_OK;
        }
        catch (...)
        {
            *credential = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestVpnPacketBuffer(Windows::Networking::Vpn::VpnDataPathType type, impl::abi_arg_out<Windows::Networking::Vpn::IVpnPacketBuffer> vpnPacketBuffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestVpnPacketBuffer(type, *vpnPacketBuffer);
            return S_OK;
        }
        catch (...)
        {
            *vpnPacketBuffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LogDiagnosticMessage(impl::abi_arg_in<hstring> message) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogDiagnosticMessage(*reinterpret_cast<const hstring *>(&message));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Id(uint32_t * value) noexcept override
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

    HRESULT __stdcall get_Configuration(impl::abi_arg_out<Windows::Networking::Vpn::IVpnChannelConfiguration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Configuration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ActivityChange(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::Vpn::VpnChannel, Windows::Networking::Vpn::VpnChannelActivityEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ActivityChange(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::Vpn::VpnChannel, Windows::Networking::Vpn::VpnChannelActivityEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ActivityChange(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ActivityChange(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PlugInContext(impl::abi_arg_in<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlugInContext(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PlugInContext(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlugInContext());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SystemHealth(impl::abi_arg_out<Windows::Networking::Vpn::IVpnSystemHealth> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SystemHealth());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestCustomPrompt(impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<Windows::Networking::Vpn::IVpnCustomPrompt>> customPrompt) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestCustomPrompt(*reinterpret_cast<const Windows::Foundation::Collections::IVectorView<Windows::Networking::Vpn::IVpnCustomPrompt> *>(&customPrompt));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetErrorMessage(impl::abi_arg_in<hstring> message) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetErrorMessage(*reinterpret_cast<const hstring *>(&message));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetAllowedSslTlsVersions(impl::abi_arg_in<Windows::Foundation::IInspectable> tunnelTransport, bool useTls12) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetAllowedSslTlsVersions(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&tunnelTransport), useTls12);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnChannel2> : produce_base<D, Windows::Networking::Vpn::IVpnChannel2>
{
    HRESULT __stdcall abi_StartWithMainTransport(impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName>> assignedClientIPv4list, impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName>> assignedClientIPv6list, impl::abi_arg_in<Windows::Networking::Vpn::IVpnInterfaceId> vpnInterfaceId, impl::abi_arg_in<Windows::Networking::Vpn::IVpnRouteAssignment> assignedRoutes, impl::abi_arg_in<Windows::Networking::Vpn::IVpnDomainNameAssignment> assignedDomainName, uint32_t mtuSize, uint32_t maxFrameSize, bool Reserved, impl::abi_arg_in<Windows::Foundation::IInspectable> mainOuterTunnelTransport) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartWithMainTransport(*reinterpret_cast<const Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> *>(&assignedClientIPv4list), *reinterpret_cast<const Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> *>(&assignedClientIPv6list), *reinterpret_cast<const Windows::Networking::Vpn::VpnInterfaceId *>(&vpnInterfaceId), *reinterpret_cast<const Windows::Networking::Vpn::VpnRouteAssignment *>(&assignedRoutes), *reinterpret_cast<const Windows::Networking::Vpn::VpnDomainNameAssignment *>(&assignedDomainName), mtuSize, maxFrameSize, Reserved, *reinterpret_cast<const Windows::Foundation::IInspectable *>(&mainOuterTunnelTransport));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartExistingTransports(impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName>> assignedClientIPv4list, impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName>> assignedClientIPv6list, impl::abi_arg_in<Windows::Networking::Vpn::IVpnInterfaceId> vpnInterfaceId, impl::abi_arg_in<Windows::Networking::Vpn::IVpnRouteAssignment> assignedRoutes, impl::abi_arg_in<Windows::Networking::Vpn::IVpnDomainNameAssignment> assignedDomainName, uint32_t mtuSize, uint32_t maxFrameSize, bool Reserved) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartExistingTransports(*reinterpret_cast<const Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> *>(&assignedClientIPv4list), *reinterpret_cast<const Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> *>(&assignedClientIPv6list), *reinterpret_cast<const Windows::Networking::Vpn::VpnInterfaceId *>(&vpnInterfaceId), *reinterpret_cast<const Windows::Networking::Vpn::VpnRouteAssignment *>(&assignedRoutes), *reinterpret_cast<const Windows::Networking::Vpn::VpnDomainNameAssignment *>(&assignedDomainName), mtuSize, maxFrameSize, Reserved);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ActivityStateChange(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Networking::Vpn::VpnChannel, Windows::Networking::Vpn::VpnChannelActivityStateChangedArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ActivityStateChange(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Networking::Vpn::VpnChannel, Windows::Networking::Vpn::VpnChannelActivityStateChangedArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ActivityStateChange(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ActivityStateChange(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetVpnSendPacketBuffer(impl::abi_arg_out<Windows::Networking::Vpn::IVpnPacketBuffer> vpnSendPacketBuffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *vpnSendPacketBuffer = detach_abi(this->shim().GetVpnSendPacketBuffer());
            return S_OK;
        }
        catch (...)
        {
            *vpnSendPacketBuffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetVpnReceivePacketBuffer(impl::abi_arg_out<Windows::Networking::Vpn::IVpnPacketBuffer> vpnReceivePacketBuffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *vpnReceivePacketBuffer = detach_abi(this->shim().GetVpnReceivePacketBuffer());
            return S_OK;
        }
        catch (...)
        {
            *vpnReceivePacketBuffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestCustomPromptAsync(impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<Windows::Networking::Vpn::IVpnCustomPromptElement>> customPromptElement, impl::abi_arg_out<Windows::Foundation::IAsyncAction> action) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *action = detach_abi(this->shim().RequestCustomPromptAsync(*reinterpret_cast<const Windows::Foundation::Collections::IVectorView<Windows::Networking::Vpn::IVpnCustomPromptElement> *>(&customPromptElement)));
            return S_OK;
        }
        catch (...)
        {
            *action = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestCredentialsWithCertificateAsync(Windows::Networking::Vpn::VpnCredentialType credType, uint32_t credOptions, impl::abi_arg_in<Windows::Security::Cryptography::Certificates::ICertificate> certificate, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential>> credential) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *credential = detach_abi(this->shim().RequestCredentialsAsync(credType, credOptions, *reinterpret_cast<const Windows::Security::Cryptography::Certificates::Certificate *>(&certificate)));
            return S_OK;
        }
        catch (...)
        {
            *credential = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestCredentialsWithOptionsAsync(Windows::Networking::Vpn::VpnCredentialType credType, uint32_t credOptions, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential>> credential) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *credential = detach_abi(this->shim().RequestCredentialsAsync(credType, credOptions));
            return S_OK;
        }
        catch (...)
        {
            *credential = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestCredentialsSimpleAsync(Windows::Networking::Vpn::VpnCredentialType credType, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential>> credential) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *credential = detach_abi(this->shim().RequestCredentialsAsync(credType));
            return S_OK;
        }
        catch (...)
        {
            *credential = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TerminateConnection(impl::abi_arg_in<hstring> message) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TerminateConnection(*reinterpret_cast<const hstring *>(&message));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartWithTrafficFilter(impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName>> assignedClientIpv4List, impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName>> assignedClientIpv6List, impl::abi_arg_in<Windows::Networking::Vpn::IVpnInterfaceId> vpnInterfaceId, impl::abi_arg_in<Windows::Networking::Vpn::IVpnRouteAssignment> assignedRoutes, impl::abi_arg_in<Windows::Networking::Vpn::IVpnDomainNameAssignment> assignedNamespace, uint32_t mtuSize, uint32_t maxFrameSize, bool reserved, impl::abi_arg_in<Windows::Foundation::IInspectable> mainOuterTunnelTransport, impl::abi_arg_in<Windows::Foundation::IInspectable> optionalOuterTunnelTransport, impl::abi_arg_in<Windows::Networking::Vpn::IVpnTrafficFilterAssignment> assignedTrafficFilters) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartWithTrafficFilter(*reinterpret_cast<const Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> *>(&assignedClientIpv4List), *reinterpret_cast<const Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> *>(&assignedClientIpv6List), *reinterpret_cast<const Windows::Networking::Vpn::VpnInterfaceId *>(&vpnInterfaceId), *reinterpret_cast<const Windows::Networking::Vpn::VpnRouteAssignment *>(&assignedRoutes), *reinterpret_cast<const Windows::Networking::Vpn::VpnDomainNameAssignment *>(&assignedNamespace), mtuSize, maxFrameSize, reserved, *reinterpret_cast<const Windows::Foundation::IInspectable *>(&mainOuterTunnelTransport), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&optionalOuterTunnelTransport), *reinterpret_cast<const Windows::Networking::Vpn::VpnTrafficFilterAssignment *>(&assignedTrafficFilters));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnChannelActivityEventArgs> : produce_base<D, Windows::Networking::Vpn::IVpnChannelActivityEventArgs>
{
    HRESULT __stdcall get_Type(Windows::Networking::Vpn::VpnChannelActivityEventType * value) noexcept override
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
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnChannelActivityStateChangedArgs> : produce_base<D, Windows::Networking::Vpn::IVpnChannelActivityStateChangedArgs>
{
    HRESULT __stdcall get_ActivityState(Windows::Networking::Vpn::VpnChannelActivityEventType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActivityState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnChannelConfiguration> : produce_base<D, Windows::Networking::Vpn::IVpnChannelConfiguration>
{
    HRESULT __stdcall get_ServerServiceName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerServiceName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServerHostNameList(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerHostNameList());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CustomField(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CustomField());
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
struct produce<D, Windows::Networking::Vpn::IVpnChannelConfiguration2> : produce_base<D, Windows::Networking::Vpn::IVpnChannelConfiguration2>
{
    HRESULT __stdcall get_ServerUris(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Foundation::Uri>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerUris());
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
struct produce<D, Windows::Networking::Vpn::IVpnChannelStatics> : produce_base<D, Windows::Networking::Vpn::IVpnChannelStatics>
{
    HRESULT __stdcall abi_ProcessEventAsync(impl::abi_arg_in<Windows::Foundation::IInspectable> thirdPartyPlugIn, impl::abi_arg_in<Windows::Foundation::IInspectable> event) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProcessEventAsync(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&thirdPartyPlugIn), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&event));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnCredential> : produce_base<D, Windows::Networking::Vpn::IVpnCredential>
{
    HRESULT __stdcall get_PasskeyCredential(impl::abi_arg_out<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PasskeyCredential());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CertificateCredential(impl::abi_arg_out<Windows::Security::Cryptography::Certificates::ICertificate> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CertificateCredential());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AdditionalPin(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AdditionalPin());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OldPasswordCredential(impl::abi_arg_out<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OldPasswordCredential());
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
struct produce<D, Windows::Networking::Vpn::IVpnCustomCheckBox> : produce_base<D, Windows::Networking::Vpn::IVpnCustomCheckBox>
{
    HRESULT __stdcall put_InitialCheckState(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialCheckState(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InitialCheckState(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InitialCheckState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Checked(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Checked());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnCustomComboBox> : produce_base<D, Windows::Networking::Vpn::IVpnCustomComboBox>
{
    HRESULT __stdcall put_OptionsText(impl::abi_arg_in<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OptionsText(*reinterpret_cast<const Windows::Foundation::Collections::IVectorView<hstring> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OptionsText(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OptionsText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Selected(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Selected());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnCustomEditBox> : produce_base<D, Windows::Networking::Vpn::IVpnCustomEditBox>
{
    HRESULT __stdcall put_DefaultText(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NoEcho(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NoEcho(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NoEcho(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NoEcho());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
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
struct produce<D, Windows::Networking::Vpn::IVpnCustomErrorBox> : produce_base<D, Windows::Networking::Vpn::IVpnCustomErrorBox>
{};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnCustomPrompt> : produce_base<D, Windows::Networking::Vpn::IVpnCustomPrompt>
{
    HRESULT __stdcall put_Label(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Label(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Label(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Label());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Compulsory(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Compulsory(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Compulsory(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Compulsory());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Bordered(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Bordered(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Bordered(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Bordered());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnCustomPromptBooleanInput> : produce_base<D, Windows::Networking::Vpn::IVpnCustomPromptBooleanInput>
{
    HRESULT __stdcall put_InitialValue(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialValue(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InitialValue(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InitialValue());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Value(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Value());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnCustomPromptElement> : produce_base<D, Windows::Networking::Vpn::IVpnCustomPromptElement>
{
    HRESULT __stdcall put_DisplayName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Compulsory(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Compulsory(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Compulsory(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Compulsory());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Emphasized(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Emphasized(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Emphasized(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Emphasized());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnCustomPromptOptionSelector> : produce_base<D, Windows::Networking::Vpn::IVpnCustomPromptOptionSelector>
{
    HRESULT __stdcall get_Options(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Options());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SelectedIndex(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SelectedIndex());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnCustomPromptText> : produce_base<D, Windows::Networking::Vpn::IVpnCustomPromptText>
{
    HRESULT __stdcall put_Text(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Text(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
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
struct produce<D, Windows::Networking::Vpn::IVpnCustomPromptTextInput> : produce_base<D, Windows::Networking::Vpn::IVpnCustomPromptTextInput>
{
    HRESULT __stdcall put_PlaceholderText(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaceholderText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PlaceholderText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PlaceholderText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsTextHidden(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsTextHidden(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsTextHidden(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsTextHidden());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
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
struct produce<D, Windows::Networking::Vpn::IVpnCustomTextBox> : produce_base<D, Windows::Networking::Vpn::IVpnCustomTextBox>
{
    HRESULT __stdcall put_DisplayText(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayText());
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
struct produce<D, Windows::Networking::Vpn::IVpnDomainNameAssignment> : produce_base<D, Windows::Networking::Vpn::IVpnDomainNameAssignment>
{
    HRESULT __stdcall get_DomainNameList(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnDomainNameInfo>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DomainNameList());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProxyAutoConfigurationUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProxyAutoConfigurationUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProxyAutoConfigurationUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProxyAutoConfigurationUri());
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
struct produce<D, Windows::Networking::Vpn::IVpnDomainNameInfo> : produce_base<D, Windows::Networking::Vpn::IVpnDomainNameInfo>
{
    HRESULT __stdcall put_DomainName(impl::abi_arg_in<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DomainName(*reinterpret_cast<const Windows::Networking::HostName *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DomainName(impl::abi_arg_out<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DomainName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DomainNameType(Windows::Networking::Vpn::VpnDomainNameType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DomainNameType(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DomainNameType(Windows::Networking::Vpn::VpnDomainNameType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DomainNameType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DnsServers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Networking::HostName>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DnsServers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WebProxyServers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Networking::HostName>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WebProxyServers());
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
struct produce<D, Windows::Networking::Vpn::IVpnDomainNameInfo2> : produce_base<D, Windows::Networking::Vpn::IVpnDomainNameInfo2>
{
    HRESULT __stdcall get_WebProxyUris(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Foundation::Uri>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WebProxyUris());
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
struct produce<D, Windows::Networking::Vpn::IVpnDomainNameInfoFactory> : produce_base<D, Windows::Networking::Vpn::IVpnDomainNameInfoFactory>
{
    HRESULT __stdcall abi_CreateVpnDomainNameInfo(impl::abi_arg_in<hstring> name, Windows::Networking::Vpn::VpnDomainNameType nameType, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Networking::HostName>> dnsServerList, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Networking::HostName>> proxyServerList, impl::abi_arg_out<Windows::Networking::Vpn::IVpnDomainNameInfo> domainNameInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *domainNameInfo = detach_abi(this->shim().CreateVpnDomainNameInfo(*reinterpret_cast<const hstring *>(&name), nameType, *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Networking::HostName> *>(&dnsServerList), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Networking::HostName> *>(&proxyServerList)));
            return S_OK;
        }
        catch (...)
        {
            *domainNameInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnInterfaceId> : produce_base<D, Windows::Networking::Vpn::IVpnInterfaceId>
{
    HRESULT __stdcall abi_GetAddressInfo(uint32_t * __idSize, impl::abi_arg_out<uint8_t> * id) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetAddressInfo(detach_abi<uint8_t>(__idSize, id));
            return S_OK;
        }
        catch (...)
        {
            *__idSize = 0;
            *id = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnInterfaceIdFactory> : produce_base<D, Windows::Networking::Vpn::IVpnInterfaceIdFactory>
{
    HRESULT __stdcall abi_CreateVpnInterfaceId(uint32_t __addressSize, impl::abi_arg_in<uint8_t> * address, impl::abi_arg_out<Windows::Networking::Vpn::IVpnInterfaceId> vpnInterfaceId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *vpnInterfaceId = detach_abi(this->shim().CreateVpnInterfaceId(array_view<const uint8_t>(address, address + __addressSize)));
            return S_OK;
        }
        catch (...)
        {
            *vpnInterfaceId = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnManagementAgent> : produce_base<D, Windows::Networking::Vpn::IVpnManagementAgent>
{
    HRESULT __stdcall abi_AddProfileFromXmlAsync(impl::abi_arg_in<hstring> xml, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().AddProfileFromXmlAsync(*reinterpret_cast<const hstring *>(&xml)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddProfileFromObjectAsync(impl::abi_arg_in<Windows::Networking::Vpn::IVpnProfile> profile, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().AddProfileFromObjectAsync(*reinterpret_cast<const Windows::Networking::Vpn::IVpnProfile *>(&profile)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateProfileFromXmlAsync(impl::abi_arg_in<hstring> xml, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().UpdateProfileFromXmlAsync(*reinterpret_cast<const hstring *>(&xml)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UpdateProfileFromObjectAsync(impl::abi_arg_in<Windows::Networking::Vpn::IVpnProfile> profile, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().UpdateProfileFromObjectAsync(*reinterpret_cast<const Windows::Networking::Vpn::IVpnProfile *>(&profile)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetProfilesAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Vpn::IVpnProfile>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().GetProfilesAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteProfileAsync(impl::abi_arg_in<Windows::Networking::Vpn::IVpnProfile> profile, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().DeleteProfileAsync(*reinterpret_cast<const Windows::Networking::Vpn::IVpnProfile *>(&profile)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConnectProfileAsync(impl::abi_arg_in<Windows::Networking::Vpn::IVpnProfile> profile, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ConnectProfileAsync(*reinterpret_cast<const Windows::Networking::Vpn::IVpnProfile *>(&profile)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConnectProfileWithPasswordCredentialAsync(impl::abi_arg_in<Windows::Networking::Vpn::IVpnProfile> profile, impl::abi_arg_in<Windows::Security::Credentials::IPasswordCredential> passwordCredential, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ConnectProfileWithPasswordCredentialAsync(*reinterpret_cast<const Windows::Networking::Vpn::IVpnProfile *>(&profile), *reinterpret_cast<const Windows::Security::Credentials::PasswordCredential *>(&passwordCredential)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DisconnectProfileAsync(impl::abi_arg_in<Windows::Networking::Vpn::IVpnProfile> profile, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().DisconnectProfileAsync(*reinterpret_cast<const Windows::Networking::Vpn::IVpnProfile *>(&profile)));
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
struct produce<D, Windows::Networking::Vpn::IVpnNamespaceAssignment> : produce_base<D, Windows::Networking::Vpn::IVpnNamespaceAssignment>
{
    HRESULT __stdcall put_NamespaceList(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnNamespaceInfo>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NamespaceList(*reinterpret_cast<const Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnNamespaceInfo> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NamespaceList(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnNamespaceInfo>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NamespaceList());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProxyAutoConfigUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProxyAutoConfigUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ProxyAutoConfigUri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProxyAutoConfigUri());
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
struct produce<D, Windows::Networking::Vpn::IVpnNamespaceInfo> : produce_base<D, Windows::Networking::Vpn::IVpnNamespaceInfo>
{
    HRESULT __stdcall put_Namespace(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Namespace(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Namespace(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Namespace());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DnsServers(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::Networking::HostName>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DnsServers(*reinterpret_cast<const Windows::Foundation::Collections::IVector<Windows::Networking::HostName> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DnsServers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Networking::HostName>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DnsServers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_WebProxyServers(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::Networking::HostName>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WebProxyServers(*reinterpret_cast<const Windows::Foundation::Collections::IVector<Windows::Networking::HostName> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WebProxyServers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Networking::HostName>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WebProxyServers());
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
struct produce<D, Windows::Networking::Vpn::IVpnNamespaceInfoFactory> : produce_base<D, Windows::Networking::Vpn::IVpnNamespaceInfoFactory>
{
    HRESULT __stdcall abi_CreateVpnNamespaceInfo(impl::abi_arg_in<hstring> name, impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::Networking::HostName>> dnsServerList, impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::Networking::HostName>> proxyServerList, impl::abi_arg_out<Windows::Networking::Vpn::IVpnNamespaceInfo> namespaceInfo) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *namespaceInfo = detach_abi(this->shim().CreateVpnNamespaceInfo(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const Windows::Foundation::Collections::IVector<Windows::Networking::HostName> *>(&dnsServerList), *reinterpret_cast<const Windows::Foundation::Collections::IVector<Windows::Networking::HostName> *>(&proxyServerList)));
            return S_OK;
        }
        catch (...)
        {
            *namespaceInfo = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnNativeProfile> : produce_base<D, Windows::Networking::Vpn::IVpnNativeProfile>
{
    HRESULT __stdcall get_Servers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Servers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RoutingPolicyType(Windows::Networking::Vpn::VpnRoutingPolicyType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoutingPolicyType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RoutingPolicyType(Windows::Networking::Vpn::VpnRoutingPolicyType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RoutingPolicyType(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NativeProtocolType(Windows::Networking::Vpn::VpnNativeProtocolType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NativeProtocolType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_NativeProtocolType(Windows::Networking::Vpn::VpnNativeProtocolType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NativeProtocolType(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserAuthenticationMethod(Windows::Networking::Vpn::VpnAuthenticationMethod * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserAuthenticationMethod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UserAuthenticationMethod(Windows::Networking::Vpn::VpnAuthenticationMethod value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UserAuthenticationMethod(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TunnelAuthenticationMethod(Windows::Networking::Vpn::VpnAuthenticationMethod * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TunnelAuthenticationMethod());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TunnelAuthenticationMethod(Windows::Networking::Vpn::VpnAuthenticationMethod value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TunnelAuthenticationMethod(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EapConfiguration(impl::abi_arg_out<hstring> Value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *Value = detach_abi(this->shim().EapConfiguration());
            return S_OK;
        }
        catch (...)
        {
            *Value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EapConfiguration(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EapConfiguration(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnNativeProfile2> : produce_base<D, Windows::Networking::Vpn::IVpnNativeProfile2>
{
    HRESULT __stdcall get_RequireVpnClientAppUI(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequireVpnClientAppUI());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RequireVpnClientAppUI(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequireVpnClientAppUI(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConnectionStatus(Windows::Networking::Vpn::VpnManagementConnectionStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectionStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnPacketBuffer> : produce_base<D, Windows::Networking::Vpn::IVpnPacketBuffer>
{
    HRESULT __stdcall get_Buffer(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Buffer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Status(Windows::Networking::Vpn::VpnPacketBufferStatus value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Status(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Networking::Vpn::VpnPacketBufferStatus * value) noexcept override
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

    HRESULT __stdcall put_TransportAffinity(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransportAffinity(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TransportAffinity(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TransportAffinity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnPacketBuffer2> : produce_base<D, Windows::Networking::Vpn::IVpnPacketBuffer2>
{
    HRESULT __stdcall get_AppId(impl::abi_arg_out<Windows::Networking::Vpn::IVpnAppId> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppId());
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
struct produce<D, Windows::Networking::Vpn::IVpnPacketBufferFactory> : produce_base<D, Windows::Networking::Vpn::IVpnPacketBufferFactory>
{
    HRESULT __stdcall abi_CreateVpnPacketBuffer(impl::abi_arg_in<Windows::Networking::Vpn::IVpnPacketBuffer> parentBuffer, uint32_t offset, uint32_t length, impl::abi_arg_out<Windows::Networking::Vpn::IVpnPacketBuffer> vpnPacketBuffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *vpnPacketBuffer = detach_abi(this->shim().CreateVpnPacketBuffer(*reinterpret_cast<const Windows::Networking::Vpn::VpnPacketBuffer *>(&parentBuffer), offset, length));
            return S_OK;
        }
        catch (...)
        {
            *vpnPacketBuffer = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnPacketBufferList> : produce_base<D, Windows::Networking::Vpn::IVpnPacketBufferList>
{
    HRESULT __stdcall abi_Append(impl::abi_arg_in<Windows::Networking::Vpn::IVpnPacketBuffer> nextVpnPacketBuffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Append(*reinterpret_cast<const Windows::Networking::Vpn::VpnPacketBuffer *>(&nextVpnPacketBuffer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddAtBegin(impl::abi_arg_in<Windows::Networking::Vpn::IVpnPacketBuffer> nextVpnPacketBuffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddAtBegin(*reinterpret_cast<const Windows::Networking::Vpn::VpnPacketBuffer *>(&nextVpnPacketBuffer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveAtEnd(impl::abi_arg_out<Windows::Networking::Vpn::IVpnPacketBuffer> nextVpnPacketBuffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *nextVpnPacketBuffer = detach_abi(this->shim().RemoveAtEnd());
            return S_OK;
        }
        catch (...)
        {
            *nextVpnPacketBuffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveAtBegin(impl::abi_arg_out<Windows::Networking::Vpn::IVpnPacketBuffer> nextVpnPacketBuffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *nextVpnPacketBuffer = detach_abi(this->shim().RemoveAtBegin());
            return S_OK;
        }
        catch (...)
        {
            *nextVpnPacketBuffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clear() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Status(Windows::Networking::Vpn::VpnPacketBufferStatus value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Status(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Status(Windows::Networking::Vpn::VpnPacketBufferStatus * value) noexcept override
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

    HRESULT __stdcall get_Size(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Size());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnPacketBufferList2> : produce_base<D, Windows::Networking::Vpn::IVpnPacketBufferList2>
{
    HRESULT __stdcall abi_AddLeadingPacket(impl::abi_arg_in<Windows::Networking::Vpn::IVpnPacketBuffer> nextVpnPacketBuffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddLeadingPacket(*reinterpret_cast<const Windows::Networking::Vpn::VpnPacketBuffer *>(&nextVpnPacketBuffer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveLeadingPacket(impl::abi_arg_out<Windows::Networking::Vpn::IVpnPacketBuffer> nextVpnPacketBuffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *nextVpnPacketBuffer = detach_abi(this->shim().RemoveLeadingPacket());
            return S_OK;
        }
        catch (...)
        {
            *nextVpnPacketBuffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AddTrailingPacket(impl::abi_arg_in<Windows::Networking::Vpn::IVpnPacketBuffer> nextVpnPacketBuffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddTrailingPacket(*reinterpret_cast<const Windows::Networking::Vpn::VpnPacketBuffer *>(&nextVpnPacketBuffer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RemoveTrailingPacket(impl::abi_arg_out<Windows::Networking::Vpn::IVpnPacketBuffer> nextVpnPacketBuffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *nextVpnPacketBuffer = detach_abi(this->shim().RemoveTrailingPacket());
            return S_OK;
        }
        catch (...)
        {
            *nextVpnPacketBuffer = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnPickedCredential> : produce_base<D, Windows::Networking::Vpn::IVpnPickedCredential>
{
    HRESULT __stdcall get_PasskeyCredential(impl::abi_arg_out<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PasskeyCredential());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AdditionalPin(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AdditionalPin());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OldPasswordCredential(impl::abi_arg_out<Windows::Security::Credentials::IPasswordCredential> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OldPasswordCredential());
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
struct produce<D, Windows::Networking::Vpn::IVpnPlugIn> : produce_base<D, Windows::Networking::Vpn::IVpnPlugIn>
{
    HRESULT __stdcall abi_Connect(impl::abi_arg_in<Windows::Networking::Vpn::IVpnChannel> channel) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Connect(*reinterpret_cast<const Windows::Networking::Vpn::VpnChannel *>(&channel));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Disconnect(impl::abi_arg_in<Windows::Networking::Vpn::IVpnChannel> channel) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Disconnect(*reinterpret_cast<const Windows::Networking::Vpn::VpnChannel *>(&channel));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetKeepAlivePayload(impl::abi_arg_in<Windows::Networking::Vpn::IVpnChannel> channel, impl::abi_arg_out<Windows::Networking::Vpn::IVpnPacketBuffer> keepAlivePacket) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetKeepAlivePayload(*reinterpret_cast<const Windows::Networking::Vpn::VpnChannel *>(&channel), *keepAlivePacket);
            return S_OK;
        }
        catch (...)
        {
            *keepAlivePacket = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Encapsulate(impl::abi_arg_in<Windows::Networking::Vpn::IVpnChannel> channel, impl::abi_arg_in<Windows::Networking::Vpn::IVpnPacketBufferList> packets, impl::abi_arg_in<Windows::Networking::Vpn::IVpnPacketBufferList> encapulatedPackets) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Encapsulate(*reinterpret_cast<const Windows::Networking::Vpn::VpnChannel *>(&channel), *reinterpret_cast<const Windows::Networking::Vpn::VpnPacketBufferList *>(&packets), *reinterpret_cast<const Windows::Networking::Vpn::VpnPacketBufferList *>(&encapulatedPackets));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Decapsulate(impl::abi_arg_in<Windows::Networking::Vpn::IVpnChannel> channel, impl::abi_arg_in<Windows::Networking::Vpn::IVpnPacketBuffer> encapBuffer, impl::abi_arg_in<Windows::Networking::Vpn::IVpnPacketBufferList> decapsulatedPackets, impl::abi_arg_in<Windows::Networking::Vpn::IVpnPacketBufferList> controlPacketsToSend) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Decapsulate(*reinterpret_cast<const Windows::Networking::Vpn::VpnChannel *>(&channel), *reinterpret_cast<const Windows::Networking::Vpn::VpnPacketBuffer *>(&encapBuffer), *reinterpret_cast<const Windows::Networking::Vpn::VpnPacketBufferList *>(&decapsulatedPackets), *reinterpret_cast<const Windows::Networking::Vpn::VpnPacketBufferList *>(&controlPacketsToSend));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnPlugInProfile> : produce_base<D, Windows::Networking::Vpn::IVpnPlugInProfile>
{
    HRESULT __stdcall get_ServerUris(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Foundation::Uri>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServerUris());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CustomConfiguration(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CustomConfiguration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CustomConfiguration(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CustomConfiguration(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VpnPluginPackageFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VpnPluginPackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_VpnPluginPackageFamilyName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VpnPluginPackageFamilyName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnPlugInProfile2> : produce_base<D, Windows::Networking::Vpn::IVpnPlugInProfile2>
{
    HRESULT __stdcall get_RequireVpnClientAppUI(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequireVpnClientAppUI());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RequireVpnClientAppUI(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequireVpnClientAppUI(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConnectionStatus(Windows::Networking::Vpn::VpnManagementConnectionStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectionStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnProfile> : produce_base<D, Windows::Networking::Vpn::IVpnProfile>
{
    HRESULT __stdcall get_ProfileName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProfileName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ProfileName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProfileName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppTriggers(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnAppId>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppTriggers());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Routes(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Routes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DomainNameInfoList(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnDomainNameInfo>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DomainNameInfoList());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TrafficFilters(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnTrafficFilter>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrafficFilters());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RememberCredentials(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RememberCredentials());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RememberCredentials(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RememberCredentials(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AlwaysOn(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AlwaysOn());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AlwaysOn(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlwaysOn(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnRoute> : produce_base<D, Windows::Networking::Vpn::IVpnRoute>
{
    HRESULT __stdcall put_Address(impl::abi_arg_in<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Address(*reinterpret_cast<const Windows::Networking::HostName *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Address(impl::abi_arg_out<Windows::Networking::IHostName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Address());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_PrefixSize(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrefixSize(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PrefixSize(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrefixSize());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnRouteAssignment> : produce_base<D, Windows::Networking::Vpn::IVpnRouteAssignment>
{
    HRESULT __stdcall put_Ipv4InclusionRoutes(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Ipv4InclusionRoutes(*reinterpret_cast<const Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Ipv6InclusionRoutes(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Ipv6InclusionRoutes(*reinterpret_cast<const Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ipv4InclusionRoutes(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ipv4InclusionRoutes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ipv6InclusionRoutes(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ipv6InclusionRoutes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Ipv4ExclusionRoutes(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Ipv4ExclusionRoutes(*reinterpret_cast<const Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Ipv6ExclusionRoutes(impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Ipv6ExclusionRoutes(*reinterpret_cast<const Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ipv4ExclusionRoutes(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ipv4ExclusionRoutes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Ipv6ExclusionRoutes(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Ipv6ExclusionRoutes());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExcludeLocalSubnets(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExcludeLocalSubnets(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExcludeLocalSubnets(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExcludeLocalSubnets());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnRouteFactory> : produce_base<D, Windows::Networking::Vpn::IVpnRouteFactory>
{
    HRESULT __stdcall abi_CreateVpnRoute(impl::abi_arg_in<Windows::Networking::IHostName> address, uint8_t prefixSize, impl::abi_arg_out<Windows::Networking::Vpn::IVpnRoute> route) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *route = detach_abi(this->shim().CreateVpnRoute(*reinterpret_cast<const Windows::Networking::HostName *>(&address), prefixSize));
            return S_OK;
        }
        catch (...)
        {
            *route = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnSystemHealth> : produce_base<D, Windows::Networking::Vpn::IVpnSystemHealth>
{
    HRESULT __stdcall get_StatementOfHealth(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StatementOfHealth());
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
struct produce<D, Windows::Networking::Vpn::IVpnTrafficFilter> : produce_base<D, Windows::Networking::Vpn::IVpnTrafficFilter>
{
    HRESULT __stdcall get_AppId(impl::abi_arg_out<Windows::Networking::Vpn::IVpnAppId> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AppId(impl::abi_arg_in<Windows::Networking::Vpn::IVpnAppId> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppId(*reinterpret_cast<const Windows::Networking::Vpn::VpnAppId *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppClaims(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppClaims());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Protocol(Windows::Networking::Vpn::VpnIPProtocol * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Protocol());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Protocol(Windows::Networking::Vpn::VpnIPProtocol value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Protocol(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocalPortRanges(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalPortRanges());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemotePortRanges(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemotePortRanges());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocalAddressRanges(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalAddressRanges());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemoteAddressRanges(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteAddressRanges());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RoutingPolicyType(Windows::Networking::Vpn::VpnRoutingPolicyType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoutingPolicyType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RoutingPolicyType(Windows::Networking::Vpn::VpnRoutingPolicyType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RoutingPolicyType(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnTrafficFilterAssignment> : produce_base<D, Windows::Networking::Vpn::IVpnTrafficFilterAssignment>
{
    HRESULT __stdcall get_TrafficFilterList(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnTrafficFilter>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TrafficFilterList());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowOutbound(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowOutbound());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowOutbound(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowOutbound(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowInbound(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowInbound());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowInbound(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowInbound(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Networking::Vpn::IVpnTrafficFilterFactory> : produce_base<D, Windows::Networking::Vpn::IVpnTrafficFilterFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Networking::Vpn::IVpnAppId> appId, impl::abi_arg_out<Windows::Networking::Vpn::IVpnTrafficFilter> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Networking::Vpn::VpnAppId *>(&appId)));
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

namespace Windows::Networking::Vpn {

template <typename D> void impl_IVpnPlugIn<D>::Connect(const Windows::Networking::Vpn::VpnChannel & channel) const
{
    check_hresult(WINRT_SHIM(IVpnPlugIn)->abi_Connect(get_abi(channel)));
}

template <typename D> void impl_IVpnPlugIn<D>::Disconnect(const Windows::Networking::Vpn::VpnChannel & channel) const
{
    check_hresult(WINRT_SHIM(IVpnPlugIn)->abi_Disconnect(get_abi(channel)));
}

template <typename D> void impl_IVpnPlugIn<D>::GetKeepAlivePayload(const Windows::Networking::Vpn::VpnChannel & channel, Windows::Networking::Vpn::VpnPacketBuffer & keepAlivePacket) const
{
    check_hresult(WINRT_SHIM(IVpnPlugIn)->abi_GetKeepAlivePayload(get_abi(channel), put_abi(keepAlivePacket)));
}

template <typename D> void impl_IVpnPlugIn<D>::Encapsulate(const Windows::Networking::Vpn::VpnChannel & channel, const Windows::Networking::Vpn::VpnPacketBufferList & packets, const Windows::Networking::Vpn::VpnPacketBufferList & encapulatedPackets) const
{
    check_hresult(WINRT_SHIM(IVpnPlugIn)->abi_Encapsulate(get_abi(channel), get_abi(packets), get_abi(encapulatedPackets)));
}

template <typename D> void impl_IVpnPlugIn<D>::Decapsulate(const Windows::Networking::Vpn::VpnChannel & channel, const Windows::Networking::Vpn::VpnPacketBuffer & encapBuffer, const Windows::Networking::Vpn::VpnPacketBufferList & decapsulatedPackets, const Windows::Networking::Vpn::VpnPacketBufferList & controlPacketsToSend) const
{
    check_hresult(WINRT_SHIM(IVpnPlugIn)->abi_Decapsulate(get_abi(channel), get_abi(encapBuffer), get_abi(decapsulatedPackets), get_abi(controlPacketsToSend)));
}

template <typename D> void impl_IVpnCustomPrompt<D>::Label(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVpnCustomPrompt)->put_Label(get_abi(value)));
}

template <typename D> hstring impl_IVpnCustomPrompt<D>::Label() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnCustomPrompt)->get_Label(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnCustomPrompt<D>::Compulsory(bool value) const
{
    check_hresult(WINRT_SHIM(IVpnCustomPrompt)->put_Compulsory(value));
}

template <typename D> bool impl_IVpnCustomPrompt<D>::Compulsory() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnCustomPrompt)->get_Compulsory(&value));
    return value;
}

template <typename D> void impl_IVpnCustomPrompt<D>::Bordered(bool value) const
{
    check_hresult(WINRT_SHIM(IVpnCustomPrompt)->put_Bordered(value));
}

template <typename D> bool impl_IVpnCustomPrompt<D>::Bordered() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnCustomPrompt)->get_Bordered(&value));
    return value;
}

template <typename D> void impl_IVpnCustomEditBox<D>::DefaultText(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVpnCustomEditBox)->put_DefaultText(get_abi(value)));
}

template <typename D> hstring impl_IVpnCustomEditBox<D>::DefaultText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnCustomEditBox)->get_DefaultText(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnCustomEditBox<D>::NoEcho(bool value) const
{
    check_hresult(WINRT_SHIM(IVpnCustomEditBox)->put_NoEcho(value));
}

template <typename D> bool impl_IVpnCustomEditBox<D>::NoEcho() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnCustomEditBox)->get_NoEcho(&value));
    return value;
}

template <typename D> hstring impl_IVpnCustomEditBox<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnCustomEditBox)->get_Text(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnCustomComboBox<D>::OptionsText(const Windows::Foundation::Collections::IVectorView<hstring> & value) const
{
    check_hresult(WINRT_SHIM(IVpnCustomComboBox)->put_OptionsText(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IVpnCustomComboBox<D>::OptionsText() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IVpnCustomComboBox)->get_OptionsText(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IVpnCustomComboBox<D>::Selected() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IVpnCustomComboBox)->get_Selected(&value));
    return value;
}

template <typename D> void impl_IVpnCustomTextBox<D>::DisplayText(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVpnCustomTextBox)->put_DisplayText(get_abi(value)));
}

template <typename D> hstring impl_IVpnCustomTextBox<D>::DisplayText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnCustomTextBox)->get_DisplayText(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnCustomCheckBox<D>::InitialCheckState(bool value) const
{
    check_hresult(WINRT_SHIM(IVpnCustomCheckBox)->put_InitialCheckState(value));
}

template <typename D> bool impl_IVpnCustomCheckBox<D>::InitialCheckState() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnCustomCheckBox)->get_InitialCheckState(&value));
    return value;
}

template <typename D> bool impl_IVpnCustomCheckBox<D>::Checked() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnCustomCheckBox)->get_Checked(&value));
    return value;
}

template <typename D> Windows::Networking::Vpn::VpnRoute impl_IVpnRouteFactory<D>::CreateVpnRoute(const Windows::Networking::HostName & address, uint8_t prefixSize) const
{
    Windows::Networking::Vpn::VpnRoute route { nullptr };
    check_hresult(WINRT_SHIM(IVpnRouteFactory)->abi_CreateVpnRoute(get_abi(address), prefixSize, put_abi(route)));
    return route;
}

template <typename D> void impl_IVpnRoute<D>::Address(const Windows::Networking::HostName & value) const
{
    check_hresult(WINRT_SHIM(IVpnRoute)->put_Address(get_abi(value)));
}

template <typename D> Windows::Networking::HostName impl_IVpnRoute<D>::Address() const
{
    Windows::Networking::HostName value { nullptr };
    check_hresult(WINRT_SHIM(IVpnRoute)->get_Address(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnRoute<D>::PrefixSize(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IVpnRoute)->put_PrefixSize(value));
}

template <typename D> uint8_t impl_IVpnRoute<D>::PrefixSize() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IVpnRoute)->get_PrefixSize(&value));
    return value;
}

template <typename D> void impl_IVpnRouteAssignment<D>::Ipv4InclusionRoutes(const Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> & value) const
{
    check_hresult(WINRT_SHIM(IVpnRouteAssignment)->put_Ipv4InclusionRoutes(get_abi(value)));
}

template <typename D> void impl_IVpnRouteAssignment<D>::Ipv6InclusionRoutes(const Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> & value) const
{
    check_hresult(WINRT_SHIM(IVpnRouteAssignment)->put_Ipv6InclusionRoutes(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> impl_IVpnRouteAssignment<D>::Ipv4InclusionRoutes() const
{
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> value;
    check_hresult(WINRT_SHIM(IVpnRouteAssignment)->get_Ipv4InclusionRoutes(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> impl_IVpnRouteAssignment<D>::Ipv6InclusionRoutes() const
{
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> value;
    check_hresult(WINRT_SHIM(IVpnRouteAssignment)->get_Ipv6InclusionRoutes(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnRouteAssignment<D>::Ipv4ExclusionRoutes(const Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> & value) const
{
    check_hresult(WINRT_SHIM(IVpnRouteAssignment)->put_Ipv4ExclusionRoutes(get_abi(value)));
}

template <typename D> void impl_IVpnRouteAssignment<D>::Ipv6ExclusionRoutes(const Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> & value) const
{
    check_hresult(WINRT_SHIM(IVpnRouteAssignment)->put_Ipv6ExclusionRoutes(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> impl_IVpnRouteAssignment<D>::Ipv4ExclusionRoutes() const
{
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> value;
    check_hresult(WINRT_SHIM(IVpnRouteAssignment)->get_Ipv4ExclusionRoutes(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> impl_IVpnRouteAssignment<D>::Ipv6ExclusionRoutes() const
{
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> value;
    check_hresult(WINRT_SHIM(IVpnRouteAssignment)->get_Ipv6ExclusionRoutes(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnRouteAssignment<D>::ExcludeLocalSubnets(bool value) const
{
    check_hresult(WINRT_SHIM(IVpnRouteAssignment)->put_ExcludeLocalSubnets(value));
}

template <typename D> bool impl_IVpnRouteAssignment<D>::ExcludeLocalSubnets() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnRouteAssignment)->get_ExcludeLocalSubnets(&value));
    return value;
}

template <typename D> Windows::Networking::Vpn::VpnNamespaceInfo impl_IVpnNamespaceInfoFactory<D>::CreateVpnNamespaceInfo(hstring_view name, const Windows::Foundation::Collections::IVector<Windows::Networking::HostName> & dnsServerList, const Windows::Foundation::Collections::IVector<Windows::Networking::HostName> & proxyServerList) const
{
    Windows::Networking::Vpn::VpnNamespaceInfo namespaceInfo { nullptr };
    check_hresult(WINRT_SHIM(IVpnNamespaceInfoFactory)->abi_CreateVpnNamespaceInfo(get_abi(name), get_abi(dnsServerList), get_abi(proxyServerList), put_abi(namespaceInfo)));
    return namespaceInfo;
}

template <typename D> void impl_IVpnNamespaceInfo<D>::Namespace(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVpnNamespaceInfo)->put_Namespace(get_abi(value)));
}

template <typename D> hstring impl_IVpnNamespaceInfo<D>::Namespace() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnNamespaceInfo)->get_Namespace(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnNamespaceInfo<D>::DnsServers(const Windows::Foundation::Collections::IVector<Windows::Networking::HostName> & value) const
{
    check_hresult(WINRT_SHIM(IVpnNamespaceInfo)->put_DnsServers(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Networking::HostName> impl_IVpnNamespaceInfo<D>::DnsServers() const
{
    Windows::Foundation::Collections::IVector<Windows::Networking::HostName> value;
    check_hresult(WINRT_SHIM(IVpnNamespaceInfo)->get_DnsServers(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnNamespaceInfo<D>::WebProxyServers(const Windows::Foundation::Collections::IVector<Windows::Networking::HostName> & value) const
{
    check_hresult(WINRT_SHIM(IVpnNamespaceInfo)->put_WebProxyServers(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Networking::HostName> impl_IVpnNamespaceInfo<D>::WebProxyServers() const
{
    Windows::Foundation::Collections::IVector<Windows::Networking::HostName> value;
    check_hresult(WINRT_SHIM(IVpnNamespaceInfo)->get_WebProxyServers(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnNamespaceAssignment<D>::NamespaceList(const Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnNamespaceInfo> & value) const
{
    check_hresult(WINRT_SHIM(IVpnNamespaceAssignment)->put_NamespaceList(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnNamespaceInfo> impl_IVpnNamespaceAssignment<D>::NamespaceList() const
{
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnNamespaceInfo> value;
    check_hresult(WINRT_SHIM(IVpnNamespaceAssignment)->get_NamespaceList(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnNamespaceAssignment<D>::ProxyAutoConfigUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IVpnNamespaceAssignment)->put_ProxyAutoConfigUri(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_IVpnNamespaceAssignment<D>::ProxyAutoConfigUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IVpnNamespaceAssignment)->get_ProxyAutoConfigUri(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::Vpn::VpnInterfaceId impl_IVpnInterfaceIdFactory<D>::CreateVpnInterfaceId(array_view<const uint8_t> address) const
{
    Windows::Networking::Vpn::VpnInterfaceId vpnInterfaceId { nullptr };
    check_hresult(WINRT_SHIM(IVpnInterfaceIdFactory)->abi_CreateVpnInterfaceId(address.size(), get_abi(address), put_abi(vpnInterfaceId)));
    return vpnInterfaceId;
}

template <typename D> void impl_IVpnInterfaceId<D>::GetAddressInfo(com_array<uint8_t> & id) const
{
    check_hresult(WINRT_SHIM(IVpnInterfaceId)->abi_GetAddressInfo(impl::put_size_abi(id), put_abi(id)));
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_IVpnPickedCredential<D>::PasskeyCredential() const
{
    Windows::Security::Credentials::PasswordCredential value { nullptr };
    check_hresult(WINRT_SHIM(IVpnPickedCredential)->get_PasskeyCredential(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVpnPickedCredential<D>::AdditionalPin() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnPickedCredential)->get_AdditionalPin(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_IVpnPickedCredential<D>::OldPasswordCredential() const
{
    Windows::Security::Credentials::PasswordCredential value { nullptr };
    check_hresult(WINRT_SHIM(IVpnPickedCredential)->get_OldPasswordCredential(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_IVpnCredential<D>::PasskeyCredential() const
{
    Windows::Security::Credentials::PasswordCredential value { nullptr };
    check_hresult(WINRT_SHIM(IVpnCredential)->get_PasskeyCredential(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Cryptography::Certificates::Certificate impl_IVpnCredential<D>::CertificateCredential() const
{
    Windows::Security::Cryptography::Certificates::Certificate value { nullptr };
    check_hresult(WINRT_SHIM(IVpnCredential)->get_CertificateCredential(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVpnCredential<D>::AdditionalPin() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnCredential)->get_AdditionalPin(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Credentials::PasswordCredential impl_IVpnCredential<D>::OldPasswordCredential() const
{
    Windows::Security::Credentials::PasswordCredential value { nullptr };
    check_hresult(WINRT_SHIM(IVpnCredential)->get_OldPasswordCredential(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::Buffer impl_IVpnSystemHealth<D>::StatementOfHealth() const
{
    Windows::Storage::Streams::Buffer value { nullptr };
    check_hresult(WINRT_SHIM(IVpnSystemHealth)->get_StatementOfHealth(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVpnChannelConfiguration<D>::ServerServiceName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnChannelConfiguration)->get_ServerServiceName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> impl_IVpnChannelConfiguration<D>::ServerHostNameList() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> value;
    check_hresult(WINRT_SHIM(IVpnChannelConfiguration)->get_ServerHostNameList(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVpnChannelConfiguration<D>::CustomField() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnChannelConfiguration)->get_CustomField(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Foundation::Uri> impl_IVpnChannelConfiguration2<D>::ServerUris() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Foundation::Uri> value;
    check_hresult(WINRT_SHIM(IVpnChannelConfiguration2)->get_ServerUris(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::Vpn::VpnChannelActivityEventType impl_IVpnChannelActivityEventArgs<D>::Type() const
{
    Windows::Networking::Vpn::VpnChannelActivityEventType value {};
    check_hresult(WINRT_SHIM(IVpnChannelActivityEventArgs)->get_Type(&value));
    return value;
}

template <typename D> void impl_IVpnChannel<D>::AssociateTransport(const Windows::Foundation::IInspectable & mainOuterTunnelTransport, const Windows::Foundation::IInspectable & optionalOuterTunnelTransport) const
{
    check_hresult(WINRT_SHIM(IVpnChannel)->abi_AssociateTransport(get_abi(mainOuterTunnelTransport), get_abi(optionalOuterTunnelTransport)));
}

template <typename D> void impl_IVpnChannel<D>::Start(vector_view<Windows::Networking::HostName> assignedClientIPv4list, vector_view<Windows::Networking::HostName> assignedClientIPv6list, const Windows::Networking::Vpn::VpnInterfaceId & vpnInterfaceId, const Windows::Networking::Vpn::VpnRouteAssignment & routeScope, const Windows::Networking::Vpn::VpnNamespaceAssignment & namespaceScope, uint32_t mtuSize, uint32_t maxFrameSize, bool optimizeForLowCostNetwork, const Windows::Foundation::IInspectable & mainOuterTunnelTransport, const Windows::Foundation::IInspectable & optionalOuterTunnelTransport) const
{
    check_hresult(WINRT_SHIM(IVpnChannel)->abi_Start(get_abi(assignedClientIPv4list), get_abi(assignedClientIPv6list), get_abi(vpnInterfaceId), get_abi(routeScope), get_abi(namespaceScope), mtuSize, maxFrameSize, optimizeForLowCostNetwork, get_abi(mainOuterTunnelTransport), get_abi(optionalOuterTunnelTransport)));
}

template <typename D> void impl_IVpnChannel<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IVpnChannel)->abi_Stop());
}

template <typename D> Windows::Networking::Vpn::VpnPickedCredential impl_IVpnChannel<D>::RequestCredentials(Windows::Networking::Vpn::VpnCredentialType credType, bool isRetry, bool isSingleSignOnCredential, const Windows::Security::Cryptography::Certificates::Certificate & certificate) const
{
    Windows::Networking::Vpn::VpnPickedCredential credential { nullptr };
    check_hresult(WINRT_SHIM(IVpnChannel)->abi_RequestCredentials(credType, isRetry, isSingleSignOnCredential, get_abi(certificate), put_abi(credential)));
    return credential;
}

template <typename D> void impl_IVpnChannel<D>::RequestVpnPacketBuffer(Windows::Networking::Vpn::VpnDataPathType type, Windows::Networking::Vpn::VpnPacketBuffer & vpnPacketBuffer) const
{
    check_hresult(WINRT_SHIM(IVpnChannel)->abi_RequestVpnPacketBuffer(type, put_abi(vpnPacketBuffer)));
}

template <typename D> void impl_IVpnChannel<D>::LogDiagnosticMessage(hstring_view message) const
{
    check_hresult(WINRT_SHIM(IVpnChannel)->abi_LogDiagnosticMessage(get_abi(message)));
}

template <typename D> uint32_t impl_IVpnChannel<D>::Id() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IVpnChannel)->get_Id(&value));
    return value;
}

template <typename D> Windows::Networking::Vpn::VpnChannelConfiguration impl_IVpnChannel<D>::Configuration() const
{
    Windows::Networking::Vpn::VpnChannelConfiguration value { nullptr };
    check_hresult(WINRT_SHIM(IVpnChannel)->get_Configuration(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IVpnChannel<D>::ActivityChange(const Windows::Foundation::TypedEventHandler<Windows::Networking::Vpn::VpnChannel, Windows::Networking::Vpn::VpnChannelActivityEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVpnChannel)->add_ActivityChange(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IVpnChannel> impl_IVpnChannel<D>::ActivityChange(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::Vpn::VpnChannel, Windows::Networking::Vpn::VpnChannelActivityEventArgs> & handler) const
{
    return impl::make_event_revoker<D, IVpnChannel>(this, &ABI::Windows::Networking::Vpn::IVpnChannel::remove_ActivityChange, ActivityChange(handler));
}

template <typename D> void impl_IVpnChannel<D>::ActivityChange(event_token token) const
{
    check_hresult(WINRT_SHIM(IVpnChannel)->remove_ActivityChange(token));
}

template <typename D> void impl_IVpnChannel<D>::PlugInContext(const Windows::Foundation::IInspectable & value) const
{
    check_hresult(WINRT_SHIM(IVpnChannel)->put_PlugInContext(get_abi(value)));
}

template <typename D> Windows::Foundation::IInspectable impl_IVpnChannel<D>::PlugInContext() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IVpnChannel)->get_PlugInContext(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::Vpn::VpnSystemHealth impl_IVpnChannel<D>::SystemHealth() const
{
    Windows::Networking::Vpn::VpnSystemHealth value { nullptr };
    check_hresult(WINRT_SHIM(IVpnChannel)->get_SystemHealth(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnChannel<D>::RequestCustomPrompt(vector_view<Windows::Networking::Vpn::IVpnCustomPrompt> customPrompt) const
{
    check_hresult(WINRT_SHIM(IVpnChannel)->abi_RequestCustomPrompt(get_abi(customPrompt)));
}

template <typename D> void impl_IVpnChannel<D>::SetErrorMessage(hstring_view message) const
{
    check_hresult(WINRT_SHIM(IVpnChannel)->abi_SetErrorMessage(get_abi(message)));
}

template <typename D> void impl_IVpnChannel<D>::SetAllowedSslTlsVersions(const Windows::Foundation::IInspectable & tunnelTransport, bool useTls12) const
{
    check_hresult(WINRT_SHIM(IVpnChannel)->abi_SetAllowedSslTlsVersions(get_abi(tunnelTransport), useTls12));
}

template <typename D> void impl_IVpnChannel2<D>::StartWithMainTransport(vector_view<Windows::Networking::HostName> assignedClientIPv4list, vector_view<Windows::Networking::HostName> assignedClientIPv6list, const Windows::Networking::Vpn::VpnInterfaceId & vpnInterfaceId, const Windows::Networking::Vpn::VpnRouteAssignment & assignedRoutes, const Windows::Networking::Vpn::VpnDomainNameAssignment & assignedDomainName, uint32_t mtuSize, uint32_t maxFrameSize, bool Reserved, const Windows::Foundation::IInspectable & mainOuterTunnelTransport) const
{
    check_hresult(WINRT_SHIM(IVpnChannel2)->abi_StartWithMainTransport(get_abi(assignedClientIPv4list), get_abi(assignedClientIPv6list), get_abi(vpnInterfaceId), get_abi(assignedRoutes), get_abi(assignedDomainName), mtuSize, maxFrameSize, Reserved, get_abi(mainOuterTunnelTransport)));
}

template <typename D> void impl_IVpnChannel2<D>::StartExistingTransports(vector_view<Windows::Networking::HostName> assignedClientIPv4list, vector_view<Windows::Networking::HostName> assignedClientIPv6list, const Windows::Networking::Vpn::VpnInterfaceId & vpnInterfaceId, const Windows::Networking::Vpn::VpnRouteAssignment & assignedRoutes, const Windows::Networking::Vpn::VpnDomainNameAssignment & assignedDomainName, uint32_t mtuSize, uint32_t maxFrameSize, bool Reserved) const
{
    check_hresult(WINRT_SHIM(IVpnChannel2)->abi_StartExistingTransports(get_abi(assignedClientIPv4list), get_abi(assignedClientIPv6list), get_abi(vpnInterfaceId), get_abi(assignedRoutes), get_abi(assignedDomainName), mtuSize, maxFrameSize, Reserved));
}

template <typename D> event_token impl_IVpnChannel2<D>::ActivityStateChange(const Windows::Foundation::TypedEventHandler<Windows::Networking::Vpn::VpnChannel, Windows::Networking::Vpn::VpnChannelActivityStateChangedArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IVpnChannel2)->add_ActivityStateChange(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IVpnChannel2> impl_IVpnChannel2<D>::ActivityStateChange(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::Vpn::VpnChannel, Windows::Networking::Vpn::VpnChannelActivityStateChangedArgs> & handler) const
{
    return impl::make_event_revoker<D, IVpnChannel2>(this, &ABI::Windows::Networking::Vpn::IVpnChannel2::remove_ActivityStateChange, ActivityStateChange(handler));
}

template <typename D> void impl_IVpnChannel2<D>::ActivityStateChange(event_token token) const
{
    check_hresult(WINRT_SHIM(IVpnChannel2)->remove_ActivityStateChange(token));
}

template <typename D> Windows::Networking::Vpn::VpnPacketBuffer impl_IVpnChannel2<D>::GetVpnSendPacketBuffer() const
{
    Windows::Networking::Vpn::VpnPacketBuffer vpnSendPacketBuffer { nullptr };
    check_hresult(WINRT_SHIM(IVpnChannel2)->abi_GetVpnSendPacketBuffer(put_abi(vpnSendPacketBuffer)));
    return vpnSendPacketBuffer;
}

template <typename D> Windows::Networking::Vpn::VpnPacketBuffer impl_IVpnChannel2<D>::GetVpnReceivePacketBuffer() const
{
    Windows::Networking::Vpn::VpnPacketBuffer vpnReceivePacketBuffer { nullptr };
    check_hresult(WINRT_SHIM(IVpnChannel2)->abi_GetVpnReceivePacketBuffer(put_abi(vpnReceivePacketBuffer)));
    return vpnReceivePacketBuffer;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVpnChannel2<D>::RequestCustomPromptAsync(vector_view<Windows::Networking::Vpn::IVpnCustomPromptElement> customPromptElement) const
{
    Windows::Foundation::IAsyncAction action;
    check_hresult(WINRT_SHIM(IVpnChannel2)->abi_RequestCustomPromptAsync(get_abi(customPromptElement), put_abi(action)));
    return action;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential> impl_IVpnChannel2<D>::RequestCredentialsAsync(Windows::Networking::Vpn::VpnCredentialType credType, uint32_t credOptions, const Windows::Security::Cryptography::Certificates::Certificate & certificate) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential> credential;
    check_hresult(WINRT_SHIM(IVpnChannel2)->abi_RequestCredentialsWithCertificateAsync(credType, credOptions, get_abi(certificate), put_abi(credential)));
    return credential;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential> impl_IVpnChannel2<D>::RequestCredentialsAsync(Windows::Networking::Vpn::VpnCredentialType credType, uint32_t credOptions) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential> credential;
    check_hresult(WINRT_SHIM(IVpnChannel2)->abi_RequestCredentialsWithOptionsAsync(credType, credOptions, put_abi(credential)));
    return credential;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential> impl_IVpnChannel2<D>::RequestCredentialsAsync(Windows::Networking::Vpn::VpnCredentialType credType) const
{
    Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential> credential;
    check_hresult(WINRT_SHIM(IVpnChannel2)->abi_RequestCredentialsSimpleAsync(credType, put_abi(credential)));
    return credential;
}

template <typename D> void impl_IVpnChannel2<D>::TerminateConnection(hstring_view message) const
{
    check_hresult(WINRT_SHIM(IVpnChannel2)->abi_TerminateConnection(get_abi(message)));
}

template <typename D> void impl_IVpnChannel2<D>::StartWithTrafficFilter(vector_view<Windows::Networking::HostName> assignedClientIpv4List, vector_view<Windows::Networking::HostName> assignedClientIpv6List, const Windows::Networking::Vpn::VpnInterfaceId & vpnInterfaceId, const Windows::Networking::Vpn::VpnRouteAssignment & assignedRoutes, const Windows::Networking::Vpn::VpnDomainNameAssignment & assignedNamespace, uint32_t mtuSize, uint32_t maxFrameSize, bool reserved, const Windows::Foundation::IInspectable & mainOuterTunnelTransport, const Windows::Foundation::IInspectable & optionalOuterTunnelTransport, const Windows::Networking::Vpn::VpnTrafficFilterAssignment & assignedTrafficFilters) const
{
    check_hresult(WINRT_SHIM(IVpnChannel2)->abi_StartWithTrafficFilter(get_abi(assignedClientIpv4List), get_abi(assignedClientIpv6List), get_abi(vpnInterfaceId), get_abi(assignedRoutes), get_abi(assignedNamespace), mtuSize, maxFrameSize, reserved, get_abi(mainOuterTunnelTransport), get_abi(optionalOuterTunnelTransport), get_abi(assignedTrafficFilters)));
}

template <typename D> void impl_IVpnCustomPromptElement<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVpnCustomPromptElement)->put_DisplayName(get_abi(value)));
}

template <typename D> hstring impl_IVpnCustomPromptElement<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnCustomPromptElement)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnCustomPromptElement<D>::Compulsory(bool value) const
{
    check_hresult(WINRT_SHIM(IVpnCustomPromptElement)->put_Compulsory(value));
}

template <typename D> bool impl_IVpnCustomPromptElement<D>::Compulsory() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnCustomPromptElement)->get_Compulsory(&value));
    return value;
}

template <typename D> void impl_IVpnCustomPromptElement<D>::Emphasized(bool value) const
{
    check_hresult(WINRT_SHIM(IVpnCustomPromptElement)->put_Emphasized(value));
}

template <typename D> bool impl_IVpnCustomPromptElement<D>::Emphasized() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnCustomPromptElement)->get_Emphasized(&value));
    return value;
}

template <typename D> void impl_IVpnChannelStatics<D>::ProcessEventAsync(const Windows::Foundation::IInspectable & thirdPartyPlugIn, const Windows::Foundation::IInspectable & event) const
{
    check_hresult(WINRT_SHIM(IVpnChannelStatics)->abi_ProcessEventAsync(get_abi(thirdPartyPlugIn), get_abi(event)));
}

template <typename D> Windows::Networking::Vpn::VpnPacketBuffer impl_IVpnPacketBufferFactory<D>::CreateVpnPacketBuffer(const Windows::Networking::Vpn::VpnPacketBuffer & parentBuffer, uint32_t offset, uint32_t length) const
{
    Windows::Networking::Vpn::VpnPacketBuffer vpnPacketBuffer { nullptr };
    check_hresult(WINRT_SHIM(IVpnPacketBufferFactory)->abi_CreateVpnPacketBuffer(get_abi(parentBuffer), offset, length, put_abi(vpnPacketBuffer)));
    return vpnPacketBuffer;
}

template <typename D> Windows::Storage::Streams::Buffer impl_IVpnPacketBuffer<D>::Buffer() const
{
    Windows::Storage::Streams::Buffer value { nullptr };
    check_hresult(WINRT_SHIM(IVpnPacketBuffer)->get_Buffer(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnPacketBuffer<D>::Status(Windows::Networking::Vpn::VpnPacketBufferStatus value) const
{
    check_hresult(WINRT_SHIM(IVpnPacketBuffer)->put_Status(value));
}

template <typename D> Windows::Networking::Vpn::VpnPacketBufferStatus impl_IVpnPacketBuffer<D>::Status() const
{
    Windows::Networking::Vpn::VpnPacketBufferStatus value {};
    check_hresult(WINRT_SHIM(IVpnPacketBuffer)->get_Status(&value));
    return value;
}

template <typename D> void impl_IVpnPacketBuffer<D>::TransportAffinity(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IVpnPacketBuffer)->put_TransportAffinity(value));
}

template <typename D> uint32_t impl_IVpnPacketBuffer<D>::TransportAffinity() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IVpnPacketBuffer)->get_TransportAffinity(&value));
    return value;
}

template <typename D> Windows::Networking::Vpn::VpnAppId impl_IVpnPacketBuffer2<D>::AppId() const
{
    Windows::Networking::Vpn::VpnAppId value { nullptr };
    check_hresult(WINRT_SHIM(IVpnPacketBuffer2)->get_AppId(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnPacketBufferList<D>::Append(const Windows::Networking::Vpn::VpnPacketBuffer & nextVpnPacketBuffer) const
{
    check_hresult(WINRT_SHIM(IVpnPacketBufferList)->abi_Append(get_abi(nextVpnPacketBuffer)));
}

template <typename D> void impl_IVpnPacketBufferList<D>::AddAtBegin(const Windows::Networking::Vpn::VpnPacketBuffer & nextVpnPacketBuffer) const
{
    check_hresult(WINRT_SHIM(IVpnPacketBufferList)->abi_AddAtBegin(get_abi(nextVpnPacketBuffer)));
}

template <typename D> Windows::Networking::Vpn::VpnPacketBuffer impl_IVpnPacketBufferList<D>::RemoveAtEnd() const
{
    Windows::Networking::Vpn::VpnPacketBuffer nextVpnPacketBuffer { nullptr };
    check_hresult(WINRT_SHIM(IVpnPacketBufferList)->abi_RemoveAtEnd(put_abi(nextVpnPacketBuffer)));
    return nextVpnPacketBuffer;
}

template <typename D> Windows::Networking::Vpn::VpnPacketBuffer impl_IVpnPacketBufferList<D>::RemoveAtBegin() const
{
    Windows::Networking::Vpn::VpnPacketBuffer nextVpnPacketBuffer { nullptr };
    check_hresult(WINRT_SHIM(IVpnPacketBufferList)->abi_RemoveAtBegin(put_abi(nextVpnPacketBuffer)));
    return nextVpnPacketBuffer;
}

template <typename D> void impl_IVpnPacketBufferList<D>::Clear() const
{
    check_hresult(WINRT_SHIM(IVpnPacketBufferList)->abi_Clear());
}

template <typename D> void impl_IVpnPacketBufferList<D>::Status(Windows::Networking::Vpn::VpnPacketBufferStatus value) const
{
    check_hresult(WINRT_SHIM(IVpnPacketBufferList)->put_Status(value));
}

template <typename D> Windows::Networking::Vpn::VpnPacketBufferStatus impl_IVpnPacketBufferList<D>::Status() const
{
    Windows::Networking::Vpn::VpnPacketBufferStatus value {};
    check_hresult(WINRT_SHIM(IVpnPacketBufferList)->get_Status(&value));
    return value;
}

template <typename D> uint32_t impl_IVpnPacketBufferList<D>::Size() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IVpnPacketBufferList)->get_Size(&value));
    return value;
}

template <typename D> void impl_IVpnPacketBufferList2<D>::AddLeadingPacket(const Windows::Networking::Vpn::VpnPacketBuffer & nextVpnPacketBuffer) const
{
    check_hresult(WINRT_SHIM(IVpnPacketBufferList2)->abi_AddLeadingPacket(get_abi(nextVpnPacketBuffer)));
}

template <typename D> Windows::Networking::Vpn::VpnPacketBuffer impl_IVpnPacketBufferList2<D>::RemoveLeadingPacket() const
{
    Windows::Networking::Vpn::VpnPacketBuffer nextVpnPacketBuffer { nullptr };
    check_hresult(WINRT_SHIM(IVpnPacketBufferList2)->abi_RemoveLeadingPacket(put_abi(nextVpnPacketBuffer)));
    return nextVpnPacketBuffer;
}

template <typename D> void impl_IVpnPacketBufferList2<D>::AddTrailingPacket(const Windows::Networking::Vpn::VpnPacketBuffer & nextVpnPacketBuffer) const
{
    check_hresult(WINRT_SHIM(IVpnPacketBufferList2)->abi_AddTrailingPacket(get_abi(nextVpnPacketBuffer)));
}

template <typename D> Windows::Networking::Vpn::VpnPacketBuffer impl_IVpnPacketBufferList2<D>::RemoveTrailingPacket() const
{
    Windows::Networking::Vpn::VpnPacketBuffer nextVpnPacketBuffer { nullptr };
    check_hresult(WINRT_SHIM(IVpnPacketBufferList2)->abi_RemoveTrailingPacket(put_abi(nextVpnPacketBuffer)));
    return nextVpnPacketBuffer;
}

template <typename D> void impl_IVpnCustomPromptTextInput<D>::PlaceholderText(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVpnCustomPromptTextInput)->put_PlaceholderText(get_abi(value)));
}

template <typename D> hstring impl_IVpnCustomPromptTextInput<D>::PlaceholderText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnCustomPromptTextInput)->get_PlaceholderText(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnCustomPromptTextInput<D>::IsTextHidden(bool value) const
{
    check_hresult(WINRT_SHIM(IVpnCustomPromptTextInput)->put_IsTextHidden(value));
}

template <typename D> bool impl_IVpnCustomPromptTextInput<D>::IsTextHidden() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnCustomPromptTextInput)->get_IsTextHidden(&value));
    return value;
}

template <typename D> hstring impl_IVpnCustomPromptTextInput<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnCustomPromptTextInput)->get_Text(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IVpnCustomPromptOptionSelector<D>::Options() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IVpnCustomPromptOptionSelector)->get_Options(put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IVpnCustomPromptOptionSelector<D>::SelectedIndex() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IVpnCustomPromptOptionSelector)->get_SelectedIndex(&value));
    return value;
}

template <typename D> void impl_IVpnCustomPromptBooleanInput<D>::InitialValue(bool value) const
{
    check_hresult(WINRT_SHIM(IVpnCustomPromptBooleanInput)->put_InitialValue(value));
}

template <typename D> bool impl_IVpnCustomPromptBooleanInput<D>::InitialValue() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnCustomPromptBooleanInput)->get_InitialValue(&value));
    return value;
}

template <typename D> bool impl_IVpnCustomPromptBooleanInput<D>::Value() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnCustomPromptBooleanInput)->get_Value(&value));
    return value;
}

template <typename D> void impl_IVpnCustomPromptText<D>::Text(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVpnCustomPromptText)->put_Text(get_abi(value)));
}

template <typename D> hstring impl_IVpnCustomPromptText<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnCustomPromptText)->get_Text(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::Vpn::VpnChannelActivityEventType impl_IVpnChannelActivityStateChangedArgs<D>::ActivityState() const
{
    Windows::Networking::Vpn::VpnChannelActivityEventType value {};
    check_hresult(WINRT_SHIM(IVpnChannelActivityStateChangedArgs)->get_ActivityState(&value));
    return value;
}

template <typename D> Windows::Networking::Vpn::VpnDomainNameInfo impl_IVpnDomainNameInfoFactory<D>::CreateVpnDomainNameInfo(hstring_view name, Windows::Networking::Vpn::VpnDomainNameType nameType, iterable<Windows::Networking::HostName> dnsServerList, iterable<Windows::Networking::HostName> proxyServerList) const
{
    Windows::Networking::Vpn::VpnDomainNameInfo domainNameInfo { nullptr };
    check_hresult(WINRT_SHIM(IVpnDomainNameInfoFactory)->abi_CreateVpnDomainNameInfo(get_abi(name), nameType, get_abi(dnsServerList), get_abi(proxyServerList), put_abi(domainNameInfo)));
    return domainNameInfo;
}

template <typename D> void impl_IVpnDomainNameInfo<D>::DomainName(const Windows::Networking::HostName & value) const
{
    check_hresult(WINRT_SHIM(IVpnDomainNameInfo)->put_DomainName(get_abi(value)));
}

template <typename D> Windows::Networking::HostName impl_IVpnDomainNameInfo<D>::DomainName() const
{
    Windows::Networking::HostName value { nullptr };
    check_hresult(WINRT_SHIM(IVpnDomainNameInfo)->get_DomainName(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnDomainNameInfo<D>::DomainNameType(Windows::Networking::Vpn::VpnDomainNameType value) const
{
    check_hresult(WINRT_SHIM(IVpnDomainNameInfo)->put_DomainNameType(value));
}

template <typename D> Windows::Networking::Vpn::VpnDomainNameType impl_IVpnDomainNameInfo<D>::DomainNameType() const
{
    Windows::Networking::Vpn::VpnDomainNameType value {};
    check_hresult(WINRT_SHIM(IVpnDomainNameInfo)->get_DomainNameType(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Networking::HostName> impl_IVpnDomainNameInfo<D>::DnsServers() const
{
    Windows::Foundation::Collections::IVector<Windows::Networking::HostName> value;
    check_hresult(WINRT_SHIM(IVpnDomainNameInfo)->get_DnsServers(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Networking::HostName> impl_IVpnDomainNameInfo<D>::WebProxyServers() const
{
    Windows::Foundation::Collections::IVector<Windows::Networking::HostName> value;
    check_hresult(WINRT_SHIM(IVpnDomainNameInfo)->get_WebProxyServers(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> impl_IVpnDomainNameInfo2<D>::WebProxyUris() const
{
    Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> value;
    check_hresult(WINRT_SHIM(IVpnDomainNameInfo2)->get_WebProxyUris(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnDomainNameInfo> impl_IVpnDomainNameAssignment<D>::DomainNameList() const
{
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnDomainNameInfo> value;
    check_hresult(WINRT_SHIM(IVpnDomainNameAssignment)->get_DomainNameList(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnDomainNameAssignment<D>::ProxyAutoConfigurationUri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IVpnDomainNameAssignment)->put_ProxyAutoConfigurationUri(get_abi(value)));
}

template <typename D> Windows::Foundation::Uri impl_IVpnDomainNameAssignment<D>::ProxyAutoConfigurationUri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IVpnDomainNameAssignment)->get_ProxyAutoConfigurationUri(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::Vpn::VpnAppId impl_IVpnAppIdFactory<D>::Create(Windows::Networking::Vpn::VpnAppIdType type, hstring_view value) const
{
    Windows::Networking::Vpn::VpnAppId result { nullptr };
    check_hresult(WINRT_SHIM(IVpnAppIdFactory)->abi_Create(type, get_abi(value), put_abi(result)));
    return result;
}

template <typename D> Windows::Networking::Vpn::VpnAppIdType impl_IVpnAppId<D>::Type() const
{
    Windows::Networking::Vpn::VpnAppIdType value {};
    check_hresult(WINRT_SHIM(IVpnAppId)->get_Type(&value));
    return value;
}

template <typename D> void impl_IVpnAppId<D>::Type(Windows::Networking::Vpn::VpnAppIdType value) const
{
    check_hresult(WINRT_SHIM(IVpnAppId)->put_Type(value));
}

template <typename D> hstring impl_IVpnAppId<D>::Value() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnAppId)->get_Value(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnAppId<D>::Value(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVpnAppId)->put_Value(get_abi(value)));
}

template <typename D> Windows::Networking::Vpn::VpnTrafficFilter impl_IVpnTrafficFilterFactory<D>::Create(const Windows::Networking::Vpn::VpnAppId & appId) const
{
    Windows::Networking::Vpn::VpnTrafficFilter result { nullptr };
    check_hresult(WINRT_SHIM(IVpnTrafficFilterFactory)->abi_Create(get_abi(appId), put_abi(result)));
    return result;
}

template <typename D> Windows::Networking::Vpn::VpnAppId impl_IVpnTrafficFilter<D>::AppId() const
{
    Windows::Networking::Vpn::VpnAppId value { nullptr };
    check_hresult(WINRT_SHIM(IVpnTrafficFilter)->get_AppId(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnTrafficFilter<D>::AppId(const Windows::Networking::Vpn::VpnAppId & value) const
{
    check_hresult(WINRT_SHIM(IVpnTrafficFilter)->put_AppId(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IVpnTrafficFilter<D>::AppClaims() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IVpnTrafficFilter)->get_AppClaims(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::Vpn::VpnIPProtocol impl_IVpnTrafficFilter<D>::Protocol() const
{
    Windows::Networking::Vpn::VpnIPProtocol value {};
    check_hresult(WINRT_SHIM(IVpnTrafficFilter)->get_Protocol(&value));
    return value;
}

template <typename D> void impl_IVpnTrafficFilter<D>::Protocol(Windows::Networking::Vpn::VpnIPProtocol value) const
{
    check_hresult(WINRT_SHIM(IVpnTrafficFilter)->put_Protocol(value));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IVpnTrafficFilter<D>::LocalPortRanges() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IVpnTrafficFilter)->get_LocalPortRanges(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IVpnTrafficFilter<D>::RemotePortRanges() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IVpnTrafficFilter)->get_RemotePortRanges(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IVpnTrafficFilter<D>::LocalAddressRanges() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IVpnTrafficFilter)->get_LocalAddressRanges(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IVpnTrafficFilter<D>::RemoteAddressRanges() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IVpnTrafficFilter)->get_RemoteAddressRanges(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::Vpn::VpnRoutingPolicyType impl_IVpnTrafficFilter<D>::RoutingPolicyType() const
{
    Windows::Networking::Vpn::VpnRoutingPolicyType value {};
    check_hresult(WINRT_SHIM(IVpnTrafficFilter)->get_RoutingPolicyType(&value));
    return value;
}

template <typename D> void impl_IVpnTrafficFilter<D>::RoutingPolicyType(Windows::Networking::Vpn::VpnRoutingPolicyType value) const
{
    check_hresult(WINRT_SHIM(IVpnTrafficFilter)->put_RoutingPolicyType(value));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnTrafficFilter> impl_IVpnTrafficFilterAssignment<D>::TrafficFilterList() const
{
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnTrafficFilter> value;
    check_hresult(WINRT_SHIM(IVpnTrafficFilterAssignment)->get_TrafficFilterList(put_abi(value)));
    return value;
}

template <typename D> bool impl_IVpnTrafficFilterAssignment<D>::AllowOutbound() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnTrafficFilterAssignment)->get_AllowOutbound(&value));
    return value;
}

template <typename D> void impl_IVpnTrafficFilterAssignment<D>::AllowOutbound(bool value) const
{
    check_hresult(WINRT_SHIM(IVpnTrafficFilterAssignment)->put_AllowOutbound(value));
}

template <typename D> bool impl_IVpnTrafficFilterAssignment<D>::AllowInbound() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnTrafficFilterAssignment)->get_AllowInbound(&value));
    return value;
}

template <typename D> void impl_IVpnTrafficFilterAssignment<D>::AllowInbound(bool value) const
{
    check_hresult(WINRT_SHIM(IVpnTrafficFilterAssignment)->put_AllowInbound(value));
}

template <typename D> hstring impl_IVpnProfile<D>::ProfileName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnProfile)->get_ProfileName(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnProfile<D>::ProfileName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVpnProfile)->put_ProfileName(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnAppId> impl_IVpnProfile<D>::AppTriggers() const
{
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnAppId> value;
    check_hresult(WINRT_SHIM(IVpnProfile)->get_AppTriggers(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> impl_IVpnProfile<D>::Routes() const
{
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> value;
    check_hresult(WINRT_SHIM(IVpnProfile)->get_Routes(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnDomainNameInfo> impl_IVpnProfile<D>::DomainNameInfoList() const
{
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnDomainNameInfo> value;
    check_hresult(WINRT_SHIM(IVpnProfile)->get_DomainNameInfoList(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnTrafficFilter> impl_IVpnProfile<D>::TrafficFilters() const
{
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnTrafficFilter> value;
    check_hresult(WINRT_SHIM(IVpnProfile)->get_TrafficFilters(put_abi(value)));
    return value;
}

template <typename D> bool impl_IVpnProfile<D>::RememberCredentials() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnProfile)->get_RememberCredentials(&value));
    return value;
}

template <typename D> void impl_IVpnProfile<D>::RememberCredentials(bool value) const
{
    check_hresult(WINRT_SHIM(IVpnProfile)->put_RememberCredentials(value));
}

template <typename D> bool impl_IVpnProfile<D>::AlwaysOn() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnProfile)->get_AlwaysOn(&value));
    return value;
}

template <typename D> void impl_IVpnProfile<D>::AlwaysOn(bool value) const
{
    check_hresult(WINRT_SHIM(IVpnProfile)->put_AlwaysOn(value));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> impl_IVpnPlugInProfile<D>::ServerUris() const
{
    Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> value;
    check_hresult(WINRT_SHIM(IVpnPlugInProfile)->get_ServerUris(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVpnPlugInProfile<D>::CustomConfiguration() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnPlugInProfile)->get_CustomConfiguration(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnPlugInProfile<D>::CustomConfiguration(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVpnPlugInProfile)->put_CustomConfiguration(get_abi(value)));
}

template <typename D> hstring impl_IVpnPlugInProfile<D>::VpnPluginPackageFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVpnPlugInProfile)->get_VpnPluginPackageFamilyName(put_abi(value)));
    return value;
}

template <typename D> void impl_IVpnPlugInProfile<D>::VpnPluginPackageFamilyName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVpnPlugInProfile)->put_VpnPluginPackageFamilyName(get_abi(value)));
}

template <typename D> bool impl_IVpnPlugInProfile2<D>::RequireVpnClientAppUI() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnPlugInProfile2)->get_RequireVpnClientAppUI(&value));
    return value;
}

template <typename D> void impl_IVpnPlugInProfile2<D>::RequireVpnClientAppUI(bool value) const
{
    check_hresult(WINRT_SHIM(IVpnPlugInProfile2)->put_RequireVpnClientAppUI(value));
}

template <typename D> Windows::Networking::Vpn::VpnManagementConnectionStatus impl_IVpnPlugInProfile2<D>::ConnectionStatus() const
{
    Windows::Networking::Vpn::VpnManagementConnectionStatus value {};
    check_hresult(WINRT_SHIM(IVpnPlugInProfile2)->get_ConnectionStatus(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IVpnNativeProfile<D>::Servers() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IVpnNativeProfile)->get_Servers(put_abi(value)));
    return value;
}

template <typename D> Windows::Networking::Vpn::VpnRoutingPolicyType impl_IVpnNativeProfile<D>::RoutingPolicyType() const
{
    Windows::Networking::Vpn::VpnRoutingPolicyType value {};
    check_hresult(WINRT_SHIM(IVpnNativeProfile)->get_RoutingPolicyType(&value));
    return value;
}

template <typename D> void impl_IVpnNativeProfile<D>::RoutingPolicyType(Windows::Networking::Vpn::VpnRoutingPolicyType value) const
{
    check_hresult(WINRT_SHIM(IVpnNativeProfile)->put_RoutingPolicyType(value));
}

template <typename D> Windows::Networking::Vpn::VpnNativeProtocolType impl_IVpnNativeProfile<D>::NativeProtocolType() const
{
    Windows::Networking::Vpn::VpnNativeProtocolType value {};
    check_hresult(WINRT_SHIM(IVpnNativeProfile)->get_NativeProtocolType(&value));
    return value;
}

template <typename D> void impl_IVpnNativeProfile<D>::NativeProtocolType(Windows::Networking::Vpn::VpnNativeProtocolType value) const
{
    check_hresult(WINRT_SHIM(IVpnNativeProfile)->put_NativeProtocolType(value));
}

template <typename D> Windows::Networking::Vpn::VpnAuthenticationMethod impl_IVpnNativeProfile<D>::UserAuthenticationMethod() const
{
    Windows::Networking::Vpn::VpnAuthenticationMethod value {};
    check_hresult(WINRT_SHIM(IVpnNativeProfile)->get_UserAuthenticationMethod(&value));
    return value;
}

template <typename D> void impl_IVpnNativeProfile<D>::UserAuthenticationMethod(Windows::Networking::Vpn::VpnAuthenticationMethod value) const
{
    check_hresult(WINRT_SHIM(IVpnNativeProfile)->put_UserAuthenticationMethod(value));
}

template <typename D> Windows::Networking::Vpn::VpnAuthenticationMethod impl_IVpnNativeProfile<D>::TunnelAuthenticationMethod() const
{
    Windows::Networking::Vpn::VpnAuthenticationMethod value {};
    check_hresult(WINRT_SHIM(IVpnNativeProfile)->get_TunnelAuthenticationMethod(&value));
    return value;
}

template <typename D> void impl_IVpnNativeProfile<D>::TunnelAuthenticationMethod(Windows::Networking::Vpn::VpnAuthenticationMethod value) const
{
    check_hresult(WINRT_SHIM(IVpnNativeProfile)->put_TunnelAuthenticationMethod(value));
}

template <typename D> hstring impl_IVpnNativeProfile<D>::EapConfiguration() const
{
    hstring Value;
    check_hresult(WINRT_SHIM(IVpnNativeProfile)->get_EapConfiguration(put_abi(Value)));
    return Value;
}

template <typename D> void impl_IVpnNativeProfile<D>::EapConfiguration(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IVpnNativeProfile)->put_EapConfiguration(get_abi(value)));
}

template <typename D> bool impl_IVpnNativeProfile2<D>::RequireVpnClientAppUI() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IVpnNativeProfile2)->get_RequireVpnClientAppUI(&value));
    return value;
}

template <typename D> void impl_IVpnNativeProfile2<D>::RequireVpnClientAppUI(bool value) const
{
    check_hresult(WINRT_SHIM(IVpnNativeProfile2)->put_RequireVpnClientAppUI(value));
}

template <typename D> Windows::Networking::Vpn::VpnManagementConnectionStatus impl_IVpnNativeProfile2<D>::ConnectionStatus() const
{
    Windows::Networking::Vpn::VpnManagementConnectionStatus value {};
    check_hresult(WINRT_SHIM(IVpnNativeProfile2)->get_ConnectionStatus(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> impl_IVpnManagementAgent<D>::AddProfileFromXmlAsync(hstring_view xml) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> operation;
    check_hresult(WINRT_SHIM(IVpnManagementAgent)->abi_AddProfileFromXmlAsync(get_abi(xml), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> impl_IVpnManagementAgent<D>::AddProfileFromObjectAsync(const Windows::Networking::Vpn::IVpnProfile & profile) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> operation;
    check_hresult(WINRT_SHIM(IVpnManagementAgent)->abi_AddProfileFromObjectAsync(get_abi(profile), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> impl_IVpnManagementAgent<D>::UpdateProfileFromXmlAsync(hstring_view xml) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> operation;
    check_hresult(WINRT_SHIM(IVpnManagementAgent)->abi_UpdateProfileFromXmlAsync(get_abi(xml), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> impl_IVpnManagementAgent<D>::UpdateProfileFromObjectAsync(const Windows::Networking::Vpn::IVpnProfile & profile) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> operation;
    check_hresult(WINRT_SHIM(IVpnManagementAgent)->abi_UpdateProfileFromObjectAsync(get_abi(profile), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Vpn::IVpnProfile>> impl_IVpnManagementAgent<D>::GetProfilesAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Vpn::IVpnProfile>> operation;
    check_hresult(WINRT_SHIM(IVpnManagementAgent)->abi_GetProfilesAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> impl_IVpnManagementAgent<D>::DeleteProfileAsync(const Windows::Networking::Vpn::IVpnProfile & profile) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> operation;
    check_hresult(WINRT_SHIM(IVpnManagementAgent)->abi_DeleteProfileAsync(get_abi(profile), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> impl_IVpnManagementAgent<D>::ConnectProfileAsync(const Windows::Networking::Vpn::IVpnProfile & profile) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> operation;
    check_hresult(WINRT_SHIM(IVpnManagementAgent)->abi_ConnectProfileAsync(get_abi(profile), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> impl_IVpnManagementAgent<D>::ConnectProfileWithPasswordCredentialAsync(const Windows::Networking::Vpn::IVpnProfile & profile, const Windows::Security::Credentials::PasswordCredential & passwordCredential) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> operation;
    check_hresult(WINRT_SHIM(IVpnManagementAgent)->abi_ConnectProfileWithPasswordCredentialAsync(get_abi(profile), get_abi(passwordCredential), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> impl_IVpnManagementAgent<D>::DisconnectProfileAsync(const Windows::Networking::Vpn::IVpnProfile & profile) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> operation;
    check_hresult(WINRT_SHIM(IVpnManagementAgent)->abi_DisconnectProfileAsync(get_abi(profile), put_abi(operation)));
    return operation;
}

inline VpnAppId::VpnAppId(Windows::Networking::Vpn::VpnAppIdType type, hstring_view value) :
    VpnAppId(get_activation_factory<VpnAppId, IVpnAppIdFactory>().Create(type, value))
{}

inline void VpnChannel::ProcessEventAsync(const Windows::Foundation::IInspectable & thirdPartyPlugIn, const Windows::Foundation::IInspectable & event)
{
    get_activation_factory<VpnChannel, IVpnChannelStatics>().ProcessEventAsync(thirdPartyPlugIn, event);
}

inline VpnCustomCheckBox::VpnCustomCheckBox() :
    VpnCustomCheckBox(activate_instance<VpnCustomCheckBox>())
{}

inline VpnCustomComboBox::VpnCustomComboBox() :
    VpnCustomComboBox(activate_instance<VpnCustomComboBox>())
{}

inline VpnCustomEditBox::VpnCustomEditBox() :
    VpnCustomEditBox(activate_instance<VpnCustomEditBox>())
{}

inline VpnCustomErrorBox::VpnCustomErrorBox() :
    VpnCustomErrorBox(activate_instance<VpnCustomErrorBox>())
{}

inline VpnCustomPromptBooleanInput::VpnCustomPromptBooleanInput() :
    VpnCustomPromptBooleanInput(activate_instance<VpnCustomPromptBooleanInput>())
{}

inline VpnCustomPromptOptionSelector::VpnCustomPromptOptionSelector() :
    VpnCustomPromptOptionSelector(activate_instance<VpnCustomPromptOptionSelector>())
{}

inline VpnCustomPromptText::VpnCustomPromptText() :
    VpnCustomPromptText(activate_instance<VpnCustomPromptText>())
{}

inline VpnCustomPromptTextInput::VpnCustomPromptTextInput() :
    VpnCustomPromptTextInput(activate_instance<VpnCustomPromptTextInput>())
{}

inline VpnCustomTextBox::VpnCustomTextBox() :
    VpnCustomTextBox(activate_instance<VpnCustomTextBox>())
{}

inline VpnDomainNameAssignment::VpnDomainNameAssignment() :
    VpnDomainNameAssignment(activate_instance<VpnDomainNameAssignment>())
{}

inline VpnDomainNameInfo::VpnDomainNameInfo(hstring_view name, Windows::Networking::Vpn::VpnDomainNameType nameType, iterable<Windows::Networking::HostName> dnsServerList, iterable<Windows::Networking::HostName> proxyServerList) :
    VpnDomainNameInfo(get_activation_factory<VpnDomainNameInfo, IVpnDomainNameInfoFactory>().CreateVpnDomainNameInfo(name, nameType, dnsServerList, proxyServerList))
{}

inline VpnInterfaceId::VpnInterfaceId(array_view<const uint8_t> address) :
    VpnInterfaceId(get_activation_factory<VpnInterfaceId, IVpnInterfaceIdFactory>().CreateVpnInterfaceId(address))
{}

inline VpnManagementAgent::VpnManagementAgent() :
    VpnManagementAgent(activate_instance<VpnManagementAgent>())
{}

inline VpnNamespaceAssignment::VpnNamespaceAssignment() :
    VpnNamespaceAssignment(activate_instance<VpnNamespaceAssignment>())
{}

inline VpnNamespaceInfo::VpnNamespaceInfo(hstring_view name, const Windows::Foundation::Collections::IVector<Windows::Networking::HostName> & dnsServerList, const Windows::Foundation::Collections::IVector<Windows::Networking::HostName> & proxyServerList) :
    VpnNamespaceInfo(get_activation_factory<VpnNamespaceInfo, IVpnNamespaceInfoFactory>().CreateVpnNamespaceInfo(name, dnsServerList, proxyServerList))
{}

inline VpnNativeProfile::VpnNativeProfile() :
    VpnNativeProfile(activate_instance<VpnNativeProfile>())
{}

inline VpnPacketBuffer::VpnPacketBuffer(const Windows::Networking::Vpn::VpnPacketBuffer & parentBuffer, uint32_t offset, uint32_t length) :
    VpnPacketBuffer(get_activation_factory<VpnPacketBuffer, IVpnPacketBufferFactory>().CreateVpnPacketBuffer(parentBuffer, offset, length))
{}

inline VpnPlugInProfile::VpnPlugInProfile() :
    VpnPlugInProfile(activate_instance<VpnPlugInProfile>())
{}

inline VpnRoute::VpnRoute(const Windows::Networking::HostName & address, uint8_t prefixSize) :
    VpnRoute(get_activation_factory<VpnRoute, IVpnRouteFactory>().CreateVpnRoute(address, prefixSize))
{}

inline VpnRouteAssignment::VpnRouteAssignment() :
    VpnRouteAssignment(activate_instance<VpnRouteAssignment>())
{}

inline VpnTrafficFilter::VpnTrafficFilter(const Windows::Networking::Vpn::VpnAppId & appId) :
    VpnTrafficFilter(get_activation_factory<VpnTrafficFilter, IVpnTrafficFilterFactory>().Create(appId))
{}

inline VpnTrafficFilterAssignment::VpnTrafficFilterAssignment() :
    VpnTrafficFilterAssignment(activate_instance<VpnTrafficFilterAssignment>())
{}

}

}
#pragma warning(pop)
