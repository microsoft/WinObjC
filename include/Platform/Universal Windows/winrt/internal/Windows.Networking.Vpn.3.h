// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Networking.Vpn.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Networking::Vpn {

struct WINRT_EBO VpnAppId :
    Windows::Networking::Vpn::IVpnAppId
{
    VpnAppId(std::nullptr_t) noexcept {}
    VpnAppId(Windows::Networking::Vpn::VpnAppIdType type, hstring_view value);
};

struct WINRT_EBO VpnChannel :
    Windows::Networking::Vpn::IVpnChannel,
    impl::require<VpnChannel, Windows::Networking::Vpn::IVpnChannel2>
{
    VpnChannel(std::nullptr_t) noexcept {}
    static void ProcessEventAsync(const Windows::Foundation::IInspectable & thirdPartyPlugIn, const Windows::Foundation::IInspectable & event);
};

struct WINRT_EBO VpnChannelActivityEventArgs :
    Windows::Networking::Vpn::IVpnChannelActivityEventArgs
{
    VpnChannelActivityEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VpnChannelActivityStateChangedArgs :
    Windows::Networking::Vpn::IVpnChannelActivityStateChangedArgs
{
    VpnChannelActivityStateChangedArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VpnChannelConfiguration :
    Windows::Networking::Vpn::IVpnChannelConfiguration,
    impl::require<VpnChannelConfiguration, Windows::Networking::Vpn::IVpnChannelConfiguration2>
{
    VpnChannelConfiguration(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VpnCredential :
    Windows::Networking::Vpn::IVpnCredential
{
    VpnCredential(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VpnCustomCheckBox :
    Windows::Networking::Vpn::IVpnCustomCheckBox
{
    VpnCustomCheckBox(std::nullptr_t) noexcept {}
    VpnCustomCheckBox();
};

struct WINRT_EBO VpnCustomComboBox :
    Windows::Networking::Vpn::IVpnCustomComboBox
{
    VpnCustomComboBox(std::nullptr_t) noexcept {}
    VpnCustomComboBox();
};

struct WINRT_EBO VpnCustomEditBox :
    Windows::Networking::Vpn::IVpnCustomEditBox
{
    VpnCustomEditBox(std::nullptr_t) noexcept {}
    VpnCustomEditBox();
};

struct WINRT_EBO VpnCustomErrorBox :
    Windows::Networking::Vpn::IVpnCustomErrorBox
{
    VpnCustomErrorBox(std::nullptr_t) noexcept {}
    VpnCustomErrorBox();
};

struct WINRT_EBO VpnCustomPromptBooleanInput :
    Windows::Networking::Vpn::IVpnCustomPromptBooleanInput
{
    VpnCustomPromptBooleanInput(std::nullptr_t) noexcept {}
    VpnCustomPromptBooleanInput();
};

struct WINRT_EBO VpnCustomPromptOptionSelector :
    Windows::Networking::Vpn::IVpnCustomPromptOptionSelector
{
    VpnCustomPromptOptionSelector(std::nullptr_t) noexcept {}
    VpnCustomPromptOptionSelector();
};

struct WINRT_EBO VpnCustomPromptText :
    Windows::Networking::Vpn::IVpnCustomPromptText
{
    VpnCustomPromptText(std::nullptr_t) noexcept {}
    VpnCustomPromptText();
};

struct WINRT_EBO VpnCustomPromptTextInput :
    Windows::Networking::Vpn::IVpnCustomPromptTextInput
{
    VpnCustomPromptTextInput(std::nullptr_t) noexcept {}
    VpnCustomPromptTextInput();
};

struct WINRT_EBO VpnCustomTextBox :
    Windows::Networking::Vpn::IVpnCustomTextBox
{
    VpnCustomTextBox(std::nullptr_t) noexcept {}
    VpnCustomTextBox();
};

struct WINRT_EBO VpnDomainNameAssignment :
    Windows::Networking::Vpn::IVpnDomainNameAssignment
{
    VpnDomainNameAssignment(std::nullptr_t) noexcept {}
    VpnDomainNameAssignment();
};

struct WINRT_EBO VpnDomainNameInfo :
    Windows::Networking::Vpn::IVpnDomainNameInfo,
    impl::require<VpnDomainNameInfo, Windows::Networking::Vpn::IVpnDomainNameInfo2>
{
    VpnDomainNameInfo(std::nullptr_t) noexcept {}
    VpnDomainNameInfo(hstring_view name, Windows::Networking::Vpn::VpnDomainNameType nameType, iterable<Windows::Networking::HostName> dnsServerList, iterable<Windows::Networking::HostName> proxyServerList);
};

struct WINRT_EBO VpnInterfaceId :
    Windows::Networking::Vpn::IVpnInterfaceId
{
    VpnInterfaceId(std::nullptr_t) noexcept {}
    VpnInterfaceId(array_view<const uint8_t> address);
};

struct WINRT_EBO VpnManagementAgent :
    Windows::Networking::Vpn::IVpnManagementAgent
{
    VpnManagementAgent(std::nullptr_t) noexcept {}
    VpnManagementAgent();
};

struct WINRT_EBO VpnNamespaceAssignment :
    Windows::Networking::Vpn::IVpnNamespaceAssignment
{
    VpnNamespaceAssignment(std::nullptr_t) noexcept {}
    VpnNamespaceAssignment();
};

struct WINRT_EBO VpnNamespaceInfo :
    Windows::Networking::Vpn::IVpnNamespaceInfo
{
    VpnNamespaceInfo(std::nullptr_t) noexcept {}
    VpnNamespaceInfo(hstring_view name, const Windows::Foundation::Collections::IVector<Windows::Networking::HostName> & dnsServerList, const Windows::Foundation::Collections::IVector<Windows::Networking::HostName> & proxyServerList);
};

struct WINRT_EBO VpnNativeProfile :
    Windows::Networking::Vpn::IVpnNativeProfile,
    impl::require<VpnNativeProfile, Windows::Networking::Vpn::IVpnNativeProfile2>
{
    VpnNativeProfile(std::nullptr_t) noexcept {}
    VpnNativeProfile();
};

struct WINRT_EBO VpnPacketBuffer :
    Windows::Networking::Vpn::IVpnPacketBuffer,
    impl::require<VpnPacketBuffer, Windows::Networking::Vpn::IVpnPacketBuffer2>
{
    VpnPacketBuffer(std::nullptr_t) noexcept {}
    VpnPacketBuffer(const Windows::Networking::Vpn::VpnPacketBuffer & parentBuffer, uint32_t offset, uint32_t length);
};

struct WINRT_EBO VpnPacketBufferList :
    Windows::Networking::Vpn::IVpnPacketBufferList
{
    VpnPacketBufferList(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VpnPickedCredential :
    Windows::Networking::Vpn::IVpnPickedCredential
{
    VpnPickedCredential(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VpnPlugInProfile :
    Windows::Networking::Vpn::IVpnPlugInProfile,
    impl::require<VpnPlugInProfile, Windows::Networking::Vpn::IVpnPlugInProfile2>
{
    VpnPlugInProfile(std::nullptr_t) noexcept {}
    VpnPlugInProfile();
};

struct WINRT_EBO VpnRoute :
    Windows::Networking::Vpn::IVpnRoute
{
    VpnRoute(std::nullptr_t) noexcept {}
    VpnRoute(const Windows::Networking::HostName & address, uint8_t prefixSize);
};

struct WINRT_EBO VpnRouteAssignment :
    Windows::Networking::Vpn::IVpnRouteAssignment
{
    VpnRouteAssignment(std::nullptr_t) noexcept {}
    VpnRouteAssignment();
};

struct WINRT_EBO VpnSystemHealth :
    Windows::Networking::Vpn::IVpnSystemHealth
{
    VpnSystemHealth(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VpnTrafficFilter :
    Windows::Networking::Vpn::IVpnTrafficFilter
{
    VpnTrafficFilter(std::nullptr_t) noexcept {}
    VpnTrafficFilter(const Windows::Networking::Vpn::VpnAppId & appId);
};

struct WINRT_EBO VpnTrafficFilterAssignment :
    Windows::Networking::Vpn::IVpnTrafficFilterAssignment
{
    VpnTrafficFilterAssignment(std::nullptr_t) noexcept {}
    VpnTrafficFilterAssignment();
};

}

}
