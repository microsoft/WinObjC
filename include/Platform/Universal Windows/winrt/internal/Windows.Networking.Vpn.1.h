// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Networking.Vpn.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Networking.0.h"
#include "Windows.Security.Credentials.0.h"
#include "Windows.Security.Cryptography.Certificates.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Networking.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Networking::Vpn {

struct __declspec(uuid("7b06a635-5c58-41d9-94a7-bfbcf1d8ca54")) __declspec(novtable) IVpnAppId : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Type(winrt::Windows::Networking::Vpn::VpnAppIdType * value) = 0;
    virtual HRESULT __stdcall put_Type(winrt::Windows::Networking::Vpn::VpnAppIdType value) = 0;
    virtual HRESULT __stdcall get_Value(hstring * value) = 0;
    virtual HRESULT __stdcall put_Value(hstring value) = 0;
};

struct __declspec(uuid("46adfd2a-0aab-4fdb-821d-d3ddc919788b")) __declspec(novtable) IVpnAppIdFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::Networking::Vpn::VpnAppIdType type, hstring value, Windows::Networking::Vpn::IVpnAppId ** result) = 0;
};

struct __declspec(uuid("4ac78d07-d1a8-4303-a091-c8d2e0915bc3")) __declspec(novtable) IVpnChannel : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AssociateTransport(Windows::Foundation::IInspectable * mainOuterTunnelTransport, Windows::Foundation::IInspectable * optionalOuterTunnelTransport) = 0;
    virtual HRESULT __stdcall abi_Start(Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> * assignedClientIPv4list, Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> * assignedClientIPv6list, Windows::Networking::Vpn::IVpnInterfaceId * vpnInterfaceId, Windows::Networking::Vpn::IVpnRouteAssignment * routeScope, Windows::Networking::Vpn::IVpnNamespaceAssignment * namespaceScope, uint32_t mtuSize, uint32_t maxFrameSize, bool optimizeForLowCostNetwork, Windows::Foundation::IInspectable * mainOuterTunnelTransport, Windows::Foundation::IInspectable * optionalOuterTunnelTransport) = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
    virtual HRESULT __stdcall abi_RequestCredentials(winrt::Windows::Networking::Vpn::VpnCredentialType credType, bool isRetry, bool isSingleSignOnCredential, Windows::Security::Cryptography::Certificates::ICertificate * certificate, Windows::Networking::Vpn::IVpnPickedCredential ** credential) = 0;
    virtual HRESULT __stdcall abi_RequestVpnPacketBuffer(winrt::Windows::Networking::Vpn::VpnDataPathType type, Windows::Networking::Vpn::IVpnPacketBuffer ** vpnPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_LogDiagnosticMessage(hstring message) = 0;
    virtual HRESULT __stdcall get_Id(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_Configuration(Windows::Networking::Vpn::IVpnChannelConfiguration ** value) = 0;
    virtual HRESULT __stdcall add_ActivityChange(Windows::Foundation::TypedEventHandler<Windows::Networking::Vpn::VpnChannel, Windows::Networking::Vpn::VpnChannelActivityEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ActivityChange(event_token token) = 0;
    virtual HRESULT __stdcall put_PlugInContext(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_PlugInContext(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_SystemHealth(Windows::Networking::Vpn::IVpnSystemHealth ** value) = 0;
    virtual HRESULT __stdcall abi_RequestCustomPrompt(Windows::Foundation::Collections::IVectorView<Windows::Networking::Vpn::IVpnCustomPrompt> * customPrompt) = 0;
    virtual HRESULT __stdcall abi_SetErrorMessage(hstring message) = 0;
    virtual HRESULT __stdcall abi_SetAllowedSslTlsVersions(Windows::Foundation::IInspectable * tunnelTransport, bool useTls12) = 0;
};

struct __declspec(uuid("2255d165-993b-4629-ad60-f1c3f3537f50")) __declspec(novtable) IVpnChannel2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_StartWithMainTransport(Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> * assignedClientIPv4list, Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> * assignedClientIPv6list, Windows::Networking::Vpn::IVpnInterfaceId * vpnInterfaceId, Windows::Networking::Vpn::IVpnRouteAssignment * assignedRoutes, Windows::Networking::Vpn::IVpnDomainNameAssignment * assignedDomainName, uint32_t mtuSize, uint32_t maxFrameSize, bool Reserved, Windows::Foundation::IInspectable * mainOuterTunnelTransport) = 0;
    virtual HRESULT __stdcall abi_StartExistingTransports(Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> * assignedClientIPv4list, Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> * assignedClientIPv6list, Windows::Networking::Vpn::IVpnInterfaceId * vpnInterfaceId, Windows::Networking::Vpn::IVpnRouteAssignment * assignedRoutes, Windows::Networking::Vpn::IVpnDomainNameAssignment * assignedDomainName, uint32_t mtuSize, uint32_t maxFrameSize, bool Reserved) = 0;
    virtual HRESULT __stdcall add_ActivityStateChange(Windows::Foundation::TypedEventHandler<Windows::Networking::Vpn::VpnChannel, Windows::Networking::Vpn::VpnChannelActivityStateChangedArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ActivityStateChange(event_token token) = 0;
    virtual HRESULT __stdcall abi_GetVpnSendPacketBuffer(Windows::Networking::Vpn::IVpnPacketBuffer ** vpnSendPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_GetVpnReceivePacketBuffer(Windows::Networking::Vpn::IVpnPacketBuffer ** vpnReceivePacketBuffer) = 0;
    virtual HRESULT __stdcall abi_RequestCustomPromptAsync(Windows::Foundation::Collections::IVectorView<Windows::Networking::Vpn::IVpnCustomPromptElement> * customPromptElement, Windows::Foundation::IAsyncAction ** action) = 0;
    virtual HRESULT __stdcall abi_RequestCredentialsWithCertificateAsync(winrt::Windows::Networking::Vpn::VpnCredentialType credType, uint32_t credOptions, Windows::Security::Cryptography::Certificates::ICertificate * certificate, Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential> ** credential) = 0;
    virtual HRESULT __stdcall abi_RequestCredentialsWithOptionsAsync(winrt::Windows::Networking::Vpn::VpnCredentialType credType, uint32_t credOptions, Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential> ** credential) = 0;
    virtual HRESULT __stdcall abi_RequestCredentialsSimpleAsync(winrt::Windows::Networking::Vpn::VpnCredentialType credType, Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential> ** credential) = 0;
    virtual HRESULT __stdcall abi_TerminateConnection(hstring message) = 0;
    virtual HRESULT __stdcall abi_StartWithTrafficFilter(Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> * assignedClientIpv4List, Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> * assignedClientIpv6List, Windows::Networking::Vpn::IVpnInterfaceId * vpnInterfaceId, Windows::Networking::Vpn::IVpnRouteAssignment * assignedRoutes, Windows::Networking::Vpn::IVpnDomainNameAssignment * assignedNamespace, uint32_t mtuSize, uint32_t maxFrameSize, bool reserved, Windows::Foundation::IInspectable * mainOuterTunnelTransport, Windows::Foundation::IInspectable * optionalOuterTunnelTransport, Windows::Networking::Vpn::IVpnTrafficFilterAssignment * assignedTrafficFilters) = 0;
};

struct __declspec(uuid("a36c88f2-afdc-4775-855d-d4ac0a35fc55")) __declspec(novtable) IVpnChannelActivityEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Type(winrt::Windows::Networking::Vpn::VpnChannelActivityEventType * value) = 0;
};

struct __declspec(uuid("3d750565-fdc0-4bbe-a23b-45fffc6d97a1")) __declspec(novtable) IVpnChannelActivityStateChangedArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ActivityState(winrt::Windows::Networking::Vpn::VpnChannelActivityEventType * value) = 0;
};

struct __declspec(uuid("0e2ddca2-2012-4fe4-b179-8c652c6d107e")) __declspec(novtable) IVpnChannelConfiguration : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServerServiceName(hstring * value) = 0;
    virtual HRESULT __stdcall get_ServerHostNameList(Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> ** value) = 0;
    virtual HRESULT __stdcall get_CustomField(hstring * value) = 0;
};

struct __declspec(uuid("f30b574c-7824-471c-a118-63dbc93ae4c7")) __declspec(novtable) IVpnChannelConfiguration2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServerUris(Windows::Foundation::Collections::IVectorView<Windows::Foundation::Uri> ** value) = 0;
};

struct __declspec(uuid("88eb062d-e818-4ffd-98a6-363e3736c95d")) __declspec(novtable) IVpnChannelStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ProcessEventAsync(Windows::Foundation::IInspectable * thirdPartyPlugIn, Windows::Foundation::IInspectable * event) = 0;
};

struct __declspec(uuid("b7e78af3-a46d-404b-8729-1832522853ac")) __declspec(novtable) IVpnCredential : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PasskeyCredential(Windows::Security::Credentials::IPasswordCredential ** value) = 0;
    virtual HRESULT __stdcall get_CertificateCredential(Windows::Security::Cryptography::Certificates::ICertificate ** value) = 0;
    virtual HRESULT __stdcall get_AdditionalPin(hstring * value) = 0;
    virtual HRESULT __stdcall get_OldPasswordCredential(Windows::Security::Credentials::IPasswordCredential ** value) = 0;
};

struct __declspec(uuid("43878753-03c5-4e61-93d7-a957714c4282")) __declspec(novtable) IVpnCustomCheckBox : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_InitialCheckState(bool value) = 0;
    virtual HRESULT __stdcall get_InitialCheckState(bool * value) = 0;
    virtual HRESULT __stdcall get_Checked(bool * value) = 0;
};

struct __declspec(uuid("9a24158e-dba1-4c6f-8270-dcf3c9761c4c")) __declspec(novtable) IVpnCustomComboBox : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_OptionsText(Windows::Foundation::Collections::IVectorView<hstring> * value) = 0;
    virtual HRESULT __stdcall get_OptionsText(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Selected(uint32_t * value) = 0;
};

struct __declspec(uuid("3002d9a0-cfbf-4c0b-8f3c-66f503c20b39")) __declspec(novtable) IVpnCustomEditBox : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_DefaultText(hstring value) = 0;
    virtual HRESULT __stdcall get_DefaultText(hstring * value) = 0;
    virtual HRESULT __stdcall put_NoEcho(bool value) = 0;
    virtual HRESULT __stdcall get_NoEcho(bool * value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
};

struct __declspec(uuid("9ec4efb2-c942-42af-b223-588b48328721")) __declspec(novtable) IVpnCustomErrorBox : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("9b2ebe7b-87d5-433c-b4f6-eee6aa68a244")) __declspec(novtable) IVpnCustomPrompt : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Label(hstring value) = 0;
    virtual HRESULT __stdcall get_Label(hstring * value) = 0;
    virtual HRESULT __stdcall put_Compulsory(bool value) = 0;
    virtual HRESULT __stdcall get_Compulsory(bool * value) = 0;
    virtual HRESULT __stdcall put_Bordered(bool value) = 0;
    virtual HRESULT __stdcall get_Bordered(bool * value) = 0;
};

struct __declspec(uuid("c4c9a69e-ff47-4527-9f27-a49292019979")) __declspec(novtable) IVpnCustomPromptBooleanInput : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_InitialValue(bool value) = 0;
    virtual HRESULT __stdcall get_InitialValue(bool * value) = 0;
    virtual HRESULT __stdcall get_Value(bool * value) = 0;
};

struct __declspec(uuid("73bd5638-6f04-404d-93dd-50a44924a38b")) __declspec(novtable) IVpnCustomPromptElement : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_DisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall put_Compulsory(bool value) = 0;
    virtual HRESULT __stdcall get_Compulsory(bool * value) = 0;
    virtual HRESULT __stdcall put_Emphasized(bool value) = 0;
    virtual HRESULT __stdcall get_Emphasized(bool * value) = 0;
};

struct __declspec(uuid("3b8f34d9-8ec1-4e95-9a4e-7ba64d38f330")) __declspec(novtable) IVpnCustomPromptOptionSelector : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Options(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_SelectedIndex(uint32_t * value) = 0;
};

struct __declspec(uuid("3bc8bdee-3a42-49a3-abdd-07b2edea752d")) __declspec(novtable) IVpnCustomPromptText : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Text(hstring value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
};

struct __declspec(uuid("c9da9c75-913c-47d5-88ba-48fc48930235")) __declspec(novtable) IVpnCustomPromptTextInput : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_PlaceholderText(hstring value) = 0;
    virtual HRESULT __stdcall get_PlaceholderText(hstring * value) = 0;
    virtual HRESULT __stdcall put_IsTextHidden(bool value) = 0;
    virtual HRESULT __stdcall get_IsTextHidden(bool * value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
};

struct __declspec(uuid("daa4c3ca-8f23-4d36-91f1-76d937827942")) __declspec(novtable) IVpnCustomTextBox : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_DisplayText(hstring value) = 0;
    virtual HRESULT __stdcall get_DisplayText(hstring * value) = 0;
};

struct __declspec(uuid("4135b141-ccdb-49b5-9401-039a8ae767e9")) __declspec(novtable) IVpnDomainNameAssignment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DomainNameList(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnDomainNameInfo> ** value) = 0;
    virtual HRESULT __stdcall put_ProxyAutoConfigurationUri(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_ProxyAutoConfigurationUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
};

struct __declspec(uuid("ad2eb82f-ea8e-4f7a-843e-1a87e32e1b9a")) __declspec(novtable) IVpnDomainNameInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_DomainName(Windows::Networking::IHostName * value) = 0;
    virtual HRESULT __stdcall get_DomainName(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall put_DomainNameType(winrt::Windows::Networking::Vpn::VpnDomainNameType value) = 0;
    virtual HRESULT __stdcall get_DomainNameType(winrt::Windows::Networking::Vpn::VpnDomainNameType * value) = 0;
    virtual HRESULT __stdcall get_DnsServers(Windows::Foundation::Collections::IVector<Windows::Networking::HostName> ** value) = 0;
    virtual HRESULT __stdcall get_WebProxyServers(Windows::Foundation::Collections::IVector<Windows::Networking::HostName> ** value) = 0;
};

struct __declspec(uuid("ab871151-6c53-4828-9883-d886de104407")) __declspec(novtable) IVpnDomainNameInfo2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_WebProxyUris(Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> ** value) = 0;
};

struct __declspec(uuid("2507bb75-028f-4688-8d3a-c4531df37da8")) __declspec(novtable) IVpnDomainNameInfoFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateVpnDomainNameInfo(hstring name, winrt::Windows::Networking::Vpn::VpnDomainNameType nameType, Windows::Foundation::Collections::IIterable<Windows::Networking::HostName> * dnsServerList, Windows::Foundation::Collections::IIterable<Windows::Networking::HostName> * proxyServerList, Windows::Networking::Vpn::IVpnDomainNameInfo ** domainNameInfo) = 0;
};

struct __declspec(uuid("9e2ddca2-1712-4ce4-b179-8c652c6d1011")) __declspec(novtable) IVpnInterfaceId : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAddressInfo(uint32_t * __idSize, uint8_t ** id) = 0;
};

struct __declspec(uuid("9e2ddca2-1712-4ce4-b179-8c652c6d1000")) __declspec(novtable) IVpnInterfaceIdFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateVpnInterfaceId(uint32_t __addressSize, uint8_t * address, Windows::Networking::Vpn::IVpnInterfaceId ** vpnInterfaceId) = 0;
};

struct __declspec(uuid("193696cd-a5c4-4abe-852b-785be4cb3e34")) __declspec(novtable) IVpnManagementAgent : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AddProfileFromXmlAsync(hstring xml, Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_AddProfileFromObjectAsync(Windows::Networking::Vpn::IVpnProfile * profile, Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_UpdateProfileFromXmlAsync(hstring xml, Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_UpdateProfileFromObjectAsync(Windows::Networking::Vpn::IVpnProfile * profile, Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetProfilesAsync(Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Vpn::IVpnProfile>> ** operation) = 0;
    virtual HRESULT __stdcall abi_DeleteProfileAsync(Windows::Networking::Vpn::IVpnProfile * profile, Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_ConnectProfileAsync(Windows::Networking::Vpn::IVpnProfile * profile, Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_ConnectProfileWithPasswordCredentialAsync(Windows::Networking::Vpn::IVpnProfile * profile, Windows::Security::Credentials::IPasswordCredential * passwordCredential, Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ** operation) = 0;
    virtual HRESULT __stdcall abi_DisconnectProfileAsync(Windows::Networking::Vpn::IVpnProfile * profile, Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ** operation) = 0;
};

struct __declspec(uuid("d7f7db18-307d-4c0e-bd62-8fa270bbadd6")) __declspec(novtable) IVpnNamespaceAssignment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_NamespaceList(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnNamespaceInfo> * value) = 0;
    virtual HRESULT __stdcall get_NamespaceList(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnNamespaceInfo> ** value) = 0;
    virtual HRESULT __stdcall put_ProxyAutoConfigUri(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_ProxyAutoConfigUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
};

struct __declspec(uuid("30edfb43-444f-44c5-8167-a35a91f1af94")) __declspec(novtable) IVpnNamespaceInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Namespace(hstring value) = 0;
    virtual HRESULT __stdcall get_Namespace(hstring * value) = 0;
    virtual HRESULT __stdcall put_DnsServers(Windows::Foundation::Collections::IVector<Windows::Networking::HostName> * value) = 0;
    virtual HRESULT __stdcall get_DnsServers(Windows::Foundation::Collections::IVector<Windows::Networking::HostName> ** value) = 0;
    virtual HRESULT __stdcall put_WebProxyServers(Windows::Foundation::Collections::IVector<Windows::Networking::HostName> * value) = 0;
    virtual HRESULT __stdcall get_WebProxyServers(Windows::Foundation::Collections::IVector<Windows::Networking::HostName> ** value) = 0;
};

struct __declspec(uuid("cb3e951a-b0ce-442b-acbb-5f99b202c31c")) __declspec(novtable) IVpnNamespaceInfoFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateVpnNamespaceInfo(hstring name, Windows::Foundation::Collections::IVector<Windows::Networking::HostName> * dnsServerList, Windows::Foundation::Collections::IVector<Windows::Networking::HostName> * proxyServerList, Windows::Networking::Vpn::IVpnNamespaceInfo ** namespaceInfo) = 0;
};

struct __declspec(uuid("a4aee29e-6417-4333-9842-f0a66db69802")) __declspec(novtable) IVpnNativeProfile : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Servers(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_RoutingPolicyType(winrt::Windows::Networking::Vpn::VpnRoutingPolicyType * value) = 0;
    virtual HRESULT __stdcall put_RoutingPolicyType(winrt::Windows::Networking::Vpn::VpnRoutingPolicyType value) = 0;
    virtual HRESULT __stdcall get_NativeProtocolType(winrt::Windows::Networking::Vpn::VpnNativeProtocolType * value) = 0;
    virtual HRESULT __stdcall put_NativeProtocolType(winrt::Windows::Networking::Vpn::VpnNativeProtocolType value) = 0;
    virtual HRESULT __stdcall get_UserAuthenticationMethod(winrt::Windows::Networking::Vpn::VpnAuthenticationMethod * value) = 0;
    virtual HRESULT __stdcall put_UserAuthenticationMethod(winrt::Windows::Networking::Vpn::VpnAuthenticationMethod value) = 0;
    virtual HRESULT __stdcall get_TunnelAuthenticationMethod(winrt::Windows::Networking::Vpn::VpnAuthenticationMethod * value) = 0;
    virtual HRESULT __stdcall put_TunnelAuthenticationMethod(winrt::Windows::Networking::Vpn::VpnAuthenticationMethod value) = 0;
    virtual HRESULT __stdcall get_EapConfiguration(hstring * Value) = 0;
    virtual HRESULT __stdcall put_EapConfiguration(hstring value) = 0;
};

struct __declspec(uuid("0fec2467-cdb5-4ac7-b5a3-0afb5ec47682")) __declspec(novtable) IVpnNativeProfile2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RequireVpnClientAppUI(bool * value) = 0;
    virtual HRESULT __stdcall put_RequireVpnClientAppUI(bool value) = 0;
    virtual HRESULT __stdcall get_ConnectionStatus(winrt::Windows::Networking::Vpn::VpnManagementConnectionStatus * value) = 0;
};

struct __declspec(uuid("c2f891fc-4d5c-4a63-b70d-4e307eacce55")) __declspec(novtable) IVpnPacketBuffer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Buffer(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall put_Status(winrt::Windows::Networking::Vpn::VpnPacketBufferStatus value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Networking::Vpn::VpnPacketBufferStatus * value) = 0;
    virtual HRESULT __stdcall put_TransportAffinity(uint32_t value) = 0;
    virtual HRESULT __stdcall get_TransportAffinity(uint32_t * value) = 0;
};

struct __declspec(uuid("665e91f0-8805-4bf5-a619-2e84882e6b4f")) __declspec(novtable) IVpnPacketBuffer2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppId(Windows::Networking::Vpn::IVpnAppId ** value) = 0;
};

struct __declspec(uuid("9e2ddca2-1712-4ce4-b179-8c652c6d9999")) __declspec(novtable) IVpnPacketBufferFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateVpnPacketBuffer(Windows::Networking::Vpn::IVpnPacketBuffer * parentBuffer, uint32_t offset, uint32_t length, Windows::Networking::Vpn::IVpnPacketBuffer ** vpnPacketBuffer) = 0;
};

struct __declspec(uuid("c2f891fc-4d5c-4a63-b70d-4e307eacce77")) __declspec(novtable) IVpnPacketBufferList : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Append(Windows::Networking::Vpn::IVpnPacketBuffer * nextVpnPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_AddAtBegin(Windows::Networking::Vpn::IVpnPacketBuffer * nextVpnPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_RemoveAtEnd(Windows::Networking::Vpn::IVpnPacketBuffer ** nextVpnPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_RemoveAtBegin(Windows::Networking::Vpn::IVpnPacketBuffer ** nextVpnPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_Clear() = 0;
    virtual HRESULT __stdcall put_Status(winrt::Windows::Networking::Vpn::VpnPacketBufferStatus value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Networking::Vpn::VpnPacketBufferStatus * value) = 0;
    virtual HRESULT __stdcall get_Size(uint32_t * value) = 0;
};

struct __declspec(uuid("3e7acfe5-ea1e-482a-8d98-c065f57d89ea")) __declspec(novtable) IVpnPacketBufferList2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AddLeadingPacket(Windows::Networking::Vpn::IVpnPacketBuffer * nextVpnPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_RemoveLeadingPacket(Windows::Networking::Vpn::IVpnPacketBuffer ** nextVpnPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_AddTrailingPacket(Windows::Networking::Vpn::IVpnPacketBuffer * nextVpnPacketBuffer) = 0;
    virtual HRESULT __stdcall abi_RemoveTrailingPacket(Windows::Networking::Vpn::IVpnPacketBuffer ** nextVpnPacketBuffer) = 0;
};

struct __declspec(uuid("9a793ac7-8854-4e52-ad97-24dd9a842bce")) __declspec(novtable) IVpnPickedCredential : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PasskeyCredential(Windows::Security::Credentials::IPasswordCredential ** value) = 0;
    virtual HRESULT __stdcall get_AdditionalPin(hstring * value) = 0;
    virtual HRESULT __stdcall get_OldPasswordCredential(Windows::Security::Credentials::IPasswordCredential ** value) = 0;
};

struct __declspec(uuid("ceb78d07-d0a8-4703-a091-c8c2c0915bc4")) __declspec(novtable) IVpnPlugIn : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Connect(Windows::Networking::Vpn::IVpnChannel * channel) = 0;
    virtual HRESULT __stdcall abi_Disconnect(Windows::Networking::Vpn::IVpnChannel * channel) = 0;
    virtual HRESULT __stdcall abi_GetKeepAlivePayload(Windows::Networking::Vpn::IVpnChannel * channel, Windows::Networking::Vpn::IVpnPacketBuffer ** keepAlivePacket) = 0;
    virtual HRESULT __stdcall abi_Encapsulate(Windows::Networking::Vpn::IVpnChannel * channel, Windows::Networking::Vpn::IVpnPacketBufferList * packets, Windows::Networking::Vpn::IVpnPacketBufferList * encapulatedPackets) = 0;
    virtual HRESULT __stdcall abi_Decapsulate(Windows::Networking::Vpn::IVpnChannel * channel, Windows::Networking::Vpn::IVpnPacketBuffer * encapBuffer, Windows::Networking::Vpn::IVpnPacketBufferList * decapsulatedPackets, Windows::Networking::Vpn::IVpnPacketBufferList * controlPacketsToSend) = 0;
};

struct __declspec(uuid("0edf0da4-4f00-4589-8d7b-4bf988f6542c")) __declspec(novtable) IVpnPlugInProfile : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServerUris(Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> ** value) = 0;
    virtual HRESULT __stdcall get_CustomConfiguration(hstring * value) = 0;
    virtual HRESULT __stdcall put_CustomConfiguration(hstring value) = 0;
    virtual HRESULT __stdcall get_VpnPluginPackageFamilyName(hstring * value) = 0;
    virtual HRESULT __stdcall put_VpnPluginPackageFamilyName(hstring value) = 0;
};

struct __declspec(uuid("611c4892-cf94-4ad6-ba99-00f4ff34565e")) __declspec(novtable) IVpnPlugInProfile2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RequireVpnClientAppUI(bool * value) = 0;
    virtual HRESULT __stdcall put_RequireVpnClientAppUI(bool value) = 0;
    virtual HRESULT __stdcall get_ConnectionStatus(winrt::Windows::Networking::Vpn::VpnManagementConnectionStatus * value) = 0;
};

struct __declspec(uuid("7875b751-b0d7-43db-8a93-d3fe2479e56a")) __declspec(novtable) IVpnProfile : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ProfileName(hstring * value) = 0;
    virtual HRESULT __stdcall put_ProfileName(hstring value) = 0;
    virtual HRESULT __stdcall get_AppTriggers(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnAppId> ** value) = 0;
    virtual HRESULT __stdcall get_Routes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> ** value) = 0;
    virtual HRESULT __stdcall get_DomainNameInfoList(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnDomainNameInfo> ** value) = 0;
    virtual HRESULT __stdcall get_TrafficFilters(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnTrafficFilter> ** value) = 0;
    virtual HRESULT __stdcall get_RememberCredentials(bool * value) = 0;
    virtual HRESULT __stdcall put_RememberCredentials(bool value) = 0;
    virtual HRESULT __stdcall get_AlwaysOn(bool * value) = 0;
    virtual HRESULT __stdcall put_AlwaysOn(bool value) = 0;
};

struct __declspec(uuid("b5731b83-0969-4699-938e-7776db29cfb3")) __declspec(novtable) IVpnRoute : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Address(Windows::Networking::IHostName * value) = 0;
    virtual HRESULT __stdcall get_Address(Windows::Networking::IHostName ** value) = 0;
    virtual HRESULT __stdcall put_PrefixSize(uint8_t value) = 0;
    virtual HRESULT __stdcall get_PrefixSize(uint8_t * value) = 0;
};

struct __declspec(uuid("db64de22-ce39-4a76-9550-f61039f80e48")) __declspec(novtable) IVpnRouteAssignment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Ipv4InclusionRoutes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> * value) = 0;
    virtual HRESULT __stdcall put_Ipv6InclusionRoutes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> * value) = 0;
    virtual HRESULT __stdcall get_Ipv4InclusionRoutes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> ** value) = 0;
    virtual HRESULT __stdcall get_Ipv6InclusionRoutes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> ** value) = 0;
    virtual HRESULT __stdcall put_Ipv4ExclusionRoutes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> * value) = 0;
    virtual HRESULT __stdcall put_Ipv6ExclusionRoutes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> * value) = 0;
    virtual HRESULT __stdcall get_Ipv4ExclusionRoutes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> ** value) = 0;
    virtual HRESULT __stdcall get_Ipv6ExclusionRoutes(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> ** value) = 0;
    virtual HRESULT __stdcall put_ExcludeLocalSubnets(bool value) = 0;
    virtual HRESULT __stdcall get_ExcludeLocalSubnets(bool * value) = 0;
};

struct __declspec(uuid("bdeab5ff-45cf-4b99-83fb-db3bc2672b02")) __declspec(novtable) IVpnRouteFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateVpnRoute(Windows::Networking::IHostName * address, uint8_t prefixSize, Windows::Networking::Vpn::IVpnRoute ** route) = 0;
};

struct __declspec(uuid("99a8f8af-c0ee-4e75-817a-f231aee5123d")) __declspec(novtable) IVpnSystemHealth : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_StatementOfHealth(Windows::Storage::Streams::IBuffer ** value) = 0;
};

struct __declspec(uuid("2f691b60-6c9f-47f5-ac36-bb1b042e2c50")) __declspec(novtable) IVpnTrafficFilter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppId(Windows::Networking::Vpn::IVpnAppId ** value) = 0;
    virtual HRESULT __stdcall put_AppId(Windows::Networking::Vpn::IVpnAppId * value) = 0;
    virtual HRESULT __stdcall get_AppClaims(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_Protocol(winrt::Windows::Networking::Vpn::VpnIPProtocol * value) = 0;
    virtual HRESULT __stdcall put_Protocol(winrt::Windows::Networking::Vpn::VpnIPProtocol value) = 0;
    virtual HRESULT __stdcall get_LocalPortRanges(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_RemotePortRanges(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_LocalAddressRanges(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_RemoteAddressRanges(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_RoutingPolicyType(winrt::Windows::Networking::Vpn::VpnRoutingPolicyType * value) = 0;
    virtual HRESULT __stdcall put_RoutingPolicyType(winrt::Windows::Networking::Vpn::VpnRoutingPolicyType value) = 0;
};

struct __declspec(uuid("56ccd45c-e664-471e-89cd-601603b9e0f3")) __declspec(novtable) IVpnTrafficFilterAssignment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TrafficFilterList(Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnTrafficFilter> ** value) = 0;
    virtual HRESULT __stdcall get_AllowOutbound(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowOutbound(bool value) = 0;
    virtual HRESULT __stdcall get_AllowInbound(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowInbound(bool value) = 0;
};

struct __declspec(uuid("480d41d5-7f99-474c-86ee-96df168318f1")) __declspec(novtable) IVpnTrafficFilterFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Networking::Vpn::IVpnAppId * appId, Windows::Networking::Vpn::IVpnTrafficFilter ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Networking::Vpn::VpnAppId> { using default_interface = Windows::Networking::Vpn::IVpnAppId; };
template <> struct traits<Windows::Networking::Vpn::VpnChannel> { using default_interface = Windows::Networking::Vpn::IVpnChannel; };
template <> struct traits<Windows::Networking::Vpn::VpnChannelActivityEventArgs> { using default_interface = Windows::Networking::Vpn::IVpnChannelActivityEventArgs; };
template <> struct traits<Windows::Networking::Vpn::VpnChannelActivityStateChangedArgs> { using default_interface = Windows::Networking::Vpn::IVpnChannelActivityStateChangedArgs; };
template <> struct traits<Windows::Networking::Vpn::VpnChannelConfiguration> { using default_interface = Windows::Networking::Vpn::IVpnChannelConfiguration; };
template <> struct traits<Windows::Networking::Vpn::VpnCredential> { using default_interface = Windows::Networking::Vpn::IVpnCredential; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomCheckBox> { using default_interface = Windows::Networking::Vpn::IVpnCustomCheckBox; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomComboBox> { using default_interface = Windows::Networking::Vpn::IVpnCustomComboBox; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomEditBox> { using default_interface = Windows::Networking::Vpn::IVpnCustomEditBox; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomErrorBox> { using default_interface = Windows::Networking::Vpn::IVpnCustomErrorBox; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomPromptBooleanInput> { using default_interface = Windows::Networking::Vpn::IVpnCustomPromptBooleanInput; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomPromptOptionSelector> { using default_interface = Windows::Networking::Vpn::IVpnCustomPromptOptionSelector; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomPromptText> { using default_interface = Windows::Networking::Vpn::IVpnCustomPromptText; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomPromptTextInput> { using default_interface = Windows::Networking::Vpn::IVpnCustomPromptTextInput; };
template <> struct traits<Windows::Networking::Vpn::VpnCustomTextBox> { using default_interface = Windows::Networking::Vpn::IVpnCustomTextBox; };
template <> struct traits<Windows::Networking::Vpn::VpnDomainNameAssignment> { using default_interface = Windows::Networking::Vpn::IVpnDomainNameAssignment; };
template <> struct traits<Windows::Networking::Vpn::VpnDomainNameInfo> { using default_interface = Windows::Networking::Vpn::IVpnDomainNameInfo; };
template <> struct traits<Windows::Networking::Vpn::VpnInterfaceId> { using default_interface = Windows::Networking::Vpn::IVpnInterfaceId; };
template <> struct traits<Windows::Networking::Vpn::VpnManagementAgent> { using default_interface = Windows::Networking::Vpn::IVpnManagementAgent; };
template <> struct traits<Windows::Networking::Vpn::VpnNamespaceAssignment> { using default_interface = Windows::Networking::Vpn::IVpnNamespaceAssignment; };
template <> struct traits<Windows::Networking::Vpn::VpnNamespaceInfo> { using default_interface = Windows::Networking::Vpn::IVpnNamespaceInfo; };
template <> struct traits<Windows::Networking::Vpn::VpnNativeProfile> { using default_interface = Windows::Networking::Vpn::IVpnNativeProfile; };
template <> struct traits<Windows::Networking::Vpn::VpnPacketBuffer> { using default_interface = Windows::Networking::Vpn::IVpnPacketBuffer; };
template <> struct traits<Windows::Networking::Vpn::VpnPacketBufferList> { using default_interface = Windows::Networking::Vpn::IVpnPacketBufferList; };
template <> struct traits<Windows::Networking::Vpn::VpnPickedCredential> { using default_interface = Windows::Networking::Vpn::IVpnPickedCredential; };
template <> struct traits<Windows::Networking::Vpn::VpnPlugInProfile> { using default_interface = Windows::Networking::Vpn::IVpnPlugInProfile; };
template <> struct traits<Windows::Networking::Vpn::VpnRoute> { using default_interface = Windows::Networking::Vpn::IVpnRoute; };
template <> struct traits<Windows::Networking::Vpn::VpnRouteAssignment> { using default_interface = Windows::Networking::Vpn::IVpnRouteAssignment; };
template <> struct traits<Windows::Networking::Vpn::VpnSystemHealth> { using default_interface = Windows::Networking::Vpn::IVpnSystemHealth; };
template <> struct traits<Windows::Networking::Vpn::VpnTrafficFilter> { using default_interface = Windows::Networking::Vpn::IVpnTrafficFilter; };
template <> struct traits<Windows::Networking::Vpn::VpnTrafficFilterAssignment> { using default_interface = Windows::Networking::Vpn::IVpnTrafficFilterAssignment; };

}

namespace Windows::Networking::Vpn {

template <typename D>
struct WINRT_EBO impl_IVpnAppId
{
    Windows::Networking::Vpn::VpnAppIdType Type() const;
    void Type(Windows::Networking::Vpn::VpnAppIdType value) const;
    hstring Value() const;
    void Value(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnAppIdFactory
{
    Windows::Networking::Vpn::VpnAppId Create(Windows::Networking::Vpn::VpnAppIdType type, hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnChannel
{
    void AssociateTransport(const Windows::Foundation::IInspectable & mainOuterTunnelTransport, const Windows::Foundation::IInspectable & optionalOuterTunnelTransport) const;
    void Start(vector_view<Windows::Networking::HostName> assignedClientIPv4list, vector_view<Windows::Networking::HostName> assignedClientIPv6list, const Windows::Networking::Vpn::VpnInterfaceId & vpnInterfaceId, const Windows::Networking::Vpn::VpnRouteAssignment & routeScope, const Windows::Networking::Vpn::VpnNamespaceAssignment & namespaceScope, uint32_t mtuSize, uint32_t maxFrameSize, bool optimizeForLowCostNetwork, const Windows::Foundation::IInspectable & mainOuterTunnelTransport, const Windows::Foundation::IInspectable & optionalOuterTunnelTransport) const;
    void Stop() const;
    Windows::Networking::Vpn::VpnPickedCredential RequestCredentials(Windows::Networking::Vpn::VpnCredentialType credType, bool isRetry, bool isSingleSignOnCredential, const Windows::Security::Cryptography::Certificates::Certificate & certificate) const;
    void RequestVpnPacketBuffer(Windows::Networking::Vpn::VpnDataPathType type, Windows::Networking::Vpn::VpnPacketBuffer & vpnPacketBuffer) const;
    void LogDiagnosticMessage(hstring_view message) const;
    uint32_t Id() const;
    Windows::Networking::Vpn::VpnChannelConfiguration Configuration() const;
    event_token ActivityChange(const Windows::Foundation::TypedEventHandler<Windows::Networking::Vpn::VpnChannel, Windows::Networking::Vpn::VpnChannelActivityEventArgs> & handler) const;
    using ActivityChange_revoker = event_revoker<IVpnChannel>;
    ActivityChange_revoker ActivityChange(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::Vpn::VpnChannel, Windows::Networking::Vpn::VpnChannelActivityEventArgs> & handler) const;
    void ActivityChange(event_token token) const;
    void PlugInContext(const Windows::Foundation::IInspectable & value) const;
    Windows::Foundation::IInspectable PlugInContext() const;
    Windows::Networking::Vpn::VpnSystemHealth SystemHealth() const;
    void RequestCustomPrompt(vector_view<Windows::Networking::Vpn::IVpnCustomPrompt> customPrompt) const;
    void SetErrorMessage(hstring_view message) const;
    void SetAllowedSslTlsVersions(const Windows::Foundation::IInspectable & tunnelTransport, bool useTls12) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnChannel2
{
    void StartWithMainTransport(vector_view<Windows::Networking::HostName> assignedClientIPv4list, vector_view<Windows::Networking::HostName> assignedClientIPv6list, const Windows::Networking::Vpn::VpnInterfaceId & vpnInterfaceId, const Windows::Networking::Vpn::VpnRouteAssignment & assignedRoutes, const Windows::Networking::Vpn::VpnDomainNameAssignment & assignedDomainName, uint32_t mtuSize, uint32_t maxFrameSize, bool Reserved, const Windows::Foundation::IInspectable & mainOuterTunnelTransport) const;
    void StartExistingTransports(vector_view<Windows::Networking::HostName> assignedClientIPv4list, vector_view<Windows::Networking::HostName> assignedClientIPv6list, const Windows::Networking::Vpn::VpnInterfaceId & vpnInterfaceId, const Windows::Networking::Vpn::VpnRouteAssignment & assignedRoutes, const Windows::Networking::Vpn::VpnDomainNameAssignment & assignedDomainName, uint32_t mtuSize, uint32_t maxFrameSize, bool Reserved) const;
    event_token ActivityStateChange(const Windows::Foundation::TypedEventHandler<Windows::Networking::Vpn::VpnChannel, Windows::Networking::Vpn::VpnChannelActivityStateChangedArgs> & handler) const;
    using ActivityStateChange_revoker = event_revoker<IVpnChannel2>;
    ActivityStateChange_revoker ActivityStateChange(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Networking::Vpn::VpnChannel, Windows::Networking::Vpn::VpnChannelActivityStateChangedArgs> & handler) const;
    void ActivityStateChange(event_token token) const;
    Windows::Networking::Vpn::VpnPacketBuffer GetVpnSendPacketBuffer() const;
    Windows::Networking::Vpn::VpnPacketBuffer GetVpnReceivePacketBuffer() const;
    Windows::Foundation::IAsyncAction RequestCustomPromptAsync(vector_view<Windows::Networking::Vpn::IVpnCustomPromptElement> customPromptElement) const;
    Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential> RequestCredentialsAsync(Windows::Networking::Vpn::VpnCredentialType credType, uint32_t credOptions, const Windows::Security::Cryptography::Certificates::Certificate & certificate) const;
    Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential> RequestCredentialsAsync(Windows::Networking::Vpn::VpnCredentialType credType, uint32_t credOptions) const;
    Windows::Foundation::IAsyncOperation<Windows::Networking::Vpn::VpnCredential> RequestCredentialsAsync(Windows::Networking::Vpn::VpnCredentialType credType) const;
    void TerminateConnection(hstring_view message) const;
    void StartWithTrafficFilter(vector_view<Windows::Networking::HostName> assignedClientIpv4List, vector_view<Windows::Networking::HostName> assignedClientIpv6List, const Windows::Networking::Vpn::VpnInterfaceId & vpnInterfaceId, const Windows::Networking::Vpn::VpnRouteAssignment & assignedRoutes, const Windows::Networking::Vpn::VpnDomainNameAssignment & assignedNamespace, uint32_t mtuSize, uint32_t maxFrameSize, bool reserved, const Windows::Foundation::IInspectable & mainOuterTunnelTransport, const Windows::Foundation::IInspectable & optionalOuterTunnelTransport, const Windows::Networking::Vpn::VpnTrafficFilterAssignment & assignedTrafficFilters) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnChannelActivityEventArgs
{
    Windows::Networking::Vpn::VpnChannelActivityEventType Type() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnChannelActivityStateChangedArgs
{
    Windows::Networking::Vpn::VpnChannelActivityEventType ActivityState() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnChannelConfiguration
{
    hstring ServerServiceName() const;
    Windows::Foundation::Collections::IVectorView<Windows::Networking::HostName> ServerHostNameList() const;
    hstring CustomField() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnChannelConfiguration2
{
    Windows::Foundation::Collections::IVectorView<Windows::Foundation::Uri> ServerUris() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnChannelStatics
{
    void ProcessEventAsync(const Windows::Foundation::IInspectable & thirdPartyPlugIn, const Windows::Foundation::IInspectable & event) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnCredential
{
    Windows::Security::Credentials::PasswordCredential PasskeyCredential() const;
    Windows::Security::Cryptography::Certificates::Certificate CertificateCredential() const;
    hstring AdditionalPin() const;
    Windows::Security::Credentials::PasswordCredential OldPasswordCredential() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnCustomCheckBox
{
    void InitialCheckState(bool value) const;
    bool InitialCheckState() const;
    bool Checked() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnCustomComboBox
{
    void OptionsText(const Windows::Foundation::Collections::IVectorView<hstring> & value) const;
    Windows::Foundation::Collections::IVectorView<hstring> OptionsText() const;
    uint32_t Selected() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnCustomEditBox
{
    void DefaultText(hstring_view value) const;
    hstring DefaultText() const;
    void NoEcho(bool value) const;
    bool NoEcho() const;
    hstring Text() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnCustomErrorBox
{
};

template <typename D>
struct WINRT_EBO impl_IVpnCustomPrompt
{
    void Label(hstring_view value) const;
    hstring Label() const;
    void Compulsory(bool value) const;
    bool Compulsory() const;
    void Bordered(bool value) const;
    bool Bordered() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnCustomPromptBooleanInput
{
    void InitialValue(bool value) const;
    bool InitialValue() const;
    bool Value() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnCustomPromptElement
{
    void DisplayName(hstring_view value) const;
    hstring DisplayName() const;
    void Compulsory(bool value) const;
    bool Compulsory() const;
    void Emphasized(bool value) const;
    bool Emphasized() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnCustomPromptOptionSelector
{
    Windows::Foundation::Collections::IVector<hstring> Options() const;
    uint32_t SelectedIndex() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnCustomPromptText
{
    void Text(hstring_view value) const;
    hstring Text() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnCustomPromptTextInput
{
    void PlaceholderText(hstring_view value) const;
    hstring PlaceholderText() const;
    void IsTextHidden(bool value) const;
    bool IsTextHidden() const;
    hstring Text() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnCustomTextBox
{
    void DisplayText(hstring_view value) const;
    hstring DisplayText() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnDomainNameAssignment
{
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnDomainNameInfo> DomainNameList() const;
    void ProxyAutoConfigurationUri(const Windows::Foundation::Uri & value) const;
    Windows::Foundation::Uri ProxyAutoConfigurationUri() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnDomainNameInfo
{
    void DomainName(const Windows::Networking::HostName & value) const;
    Windows::Networking::HostName DomainName() const;
    void DomainNameType(Windows::Networking::Vpn::VpnDomainNameType value) const;
    Windows::Networking::Vpn::VpnDomainNameType DomainNameType() const;
    Windows::Foundation::Collections::IVector<Windows::Networking::HostName> DnsServers() const;
    Windows::Foundation::Collections::IVector<Windows::Networking::HostName> WebProxyServers() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnDomainNameInfo2
{
    Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> WebProxyUris() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnDomainNameInfoFactory
{
    Windows::Networking::Vpn::VpnDomainNameInfo CreateVpnDomainNameInfo(hstring_view name, Windows::Networking::Vpn::VpnDomainNameType nameType, iterable<Windows::Networking::HostName> dnsServerList, iterable<Windows::Networking::HostName> proxyServerList) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnInterfaceId
{
    void GetAddressInfo(com_array<uint8_t> & id) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnInterfaceIdFactory
{
    Windows::Networking::Vpn::VpnInterfaceId CreateVpnInterfaceId(array_view<const uint8_t> address) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnManagementAgent
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> AddProfileFromXmlAsync(hstring_view xml) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> AddProfileFromObjectAsync(const Windows::Networking::Vpn::IVpnProfile & profile) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> UpdateProfileFromXmlAsync(hstring_view xml) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> UpdateProfileFromObjectAsync(const Windows::Networking::Vpn::IVpnProfile & profile) const;
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Networking::Vpn::IVpnProfile>> GetProfilesAsync() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> DeleteProfileAsync(const Windows::Networking::Vpn::IVpnProfile & profile) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ConnectProfileAsync(const Windows::Networking::Vpn::IVpnProfile & profile) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> ConnectProfileWithPasswordCredentialAsync(const Windows::Networking::Vpn::IVpnProfile & profile, const Windows::Security::Credentials::PasswordCredential & passwordCredential) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Networking::Vpn::VpnManagementErrorStatus> DisconnectProfileAsync(const Windows::Networking::Vpn::IVpnProfile & profile) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnNamespaceAssignment
{
    void NamespaceList(const Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnNamespaceInfo> & value) const;
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnNamespaceInfo> NamespaceList() const;
    void ProxyAutoConfigUri(const Windows::Foundation::Uri & value) const;
    Windows::Foundation::Uri ProxyAutoConfigUri() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnNamespaceInfo
{
    void Namespace(hstring_view value) const;
    hstring Namespace() const;
    void DnsServers(const Windows::Foundation::Collections::IVector<Windows::Networking::HostName> & value) const;
    Windows::Foundation::Collections::IVector<Windows::Networking::HostName> DnsServers() const;
    void WebProxyServers(const Windows::Foundation::Collections::IVector<Windows::Networking::HostName> & value) const;
    Windows::Foundation::Collections::IVector<Windows::Networking::HostName> WebProxyServers() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnNamespaceInfoFactory
{
    Windows::Networking::Vpn::VpnNamespaceInfo CreateVpnNamespaceInfo(hstring_view name, const Windows::Foundation::Collections::IVector<Windows::Networking::HostName> & dnsServerList, const Windows::Foundation::Collections::IVector<Windows::Networking::HostName> & proxyServerList) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnNativeProfile
{
    Windows::Foundation::Collections::IVector<hstring> Servers() const;
    Windows::Networking::Vpn::VpnRoutingPolicyType RoutingPolicyType() const;
    void RoutingPolicyType(Windows::Networking::Vpn::VpnRoutingPolicyType value) const;
    Windows::Networking::Vpn::VpnNativeProtocolType NativeProtocolType() const;
    void NativeProtocolType(Windows::Networking::Vpn::VpnNativeProtocolType value) const;
    Windows::Networking::Vpn::VpnAuthenticationMethod UserAuthenticationMethod() const;
    void UserAuthenticationMethod(Windows::Networking::Vpn::VpnAuthenticationMethod value) const;
    Windows::Networking::Vpn::VpnAuthenticationMethod TunnelAuthenticationMethod() const;
    void TunnelAuthenticationMethod(Windows::Networking::Vpn::VpnAuthenticationMethod value) const;
    hstring EapConfiguration() const;
    void EapConfiguration(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnNativeProfile2
{
    bool RequireVpnClientAppUI() const;
    void RequireVpnClientAppUI(bool value) const;
    Windows::Networking::Vpn::VpnManagementConnectionStatus ConnectionStatus() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnPacketBuffer
{
    Windows::Storage::Streams::Buffer Buffer() const;
    void Status(Windows::Networking::Vpn::VpnPacketBufferStatus value) const;
    Windows::Networking::Vpn::VpnPacketBufferStatus Status() const;
    void TransportAffinity(uint32_t value) const;
    uint32_t TransportAffinity() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnPacketBuffer2
{
    Windows::Networking::Vpn::VpnAppId AppId() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnPacketBufferFactory
{
    Windows::Networking::Vpn::VpnPacketBuffer CreateVpnPacketBuffer(const Windows::Networking::Vpn::VpnPacketBuffer & parentBuffer, uint32_t offset, uint32_t length) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnPacketBufferList
{
    void Append(const Windows::Networking::Vpn::VpnPacketBuffer & nextVpnPacketBuffer) const;
    void AddAtBegin(const Windows::Networking::Vpn::VpnPacketBuffer & nextVpnPacketBuffer) const;
    Windows::Networking::Vpn::VpnPacketBuffer RemoveAtEnd() const;
    Windows::Networking::Vpn::VpnPacketBuffer RemoveAtBegin() const;
    void Clear() const;
    void Status(Windows::Networking::Vpn::VpnPacketBufferStatus value) const;
    Windows::Networking::Vpn::VpnPacketBufferStatus Status() const;
    uint32_t Size() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnPacketBufferList2
{
    void AddLeadingPacket(const Windows::Networking::Vpn::VpnPacketBuffer & nextVpnPacketBuffer) const;
    Windows::Networking::Vpn::VpnPacketBuffer RemoveLeadingPacket() const;
    void AddTrailingPacket(const Windows::Networking::Vpn::VpnPacketBuffer & nextVpnPacketBuffer) const;
    Windows::Networking::Vpn::VpnPacketBuffer RemoveTrailingPacket() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnPickedCredential
{
    Windows::Security::Credentials::PasswordCredential PasskeyCredential() const;
    hstring AdditionalPin() const;
    Windows::Security::Credentials::PasswordCredential OldPasswordCredential() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnPlugIn
{
    void Connect(const Windows::Networking::Vpn::VpnChannel & channel) const;
    void Disconnect(const Windows::Networking::Vpn::VpnChannel & channel) const;
    void GetKeepAlivePayload(const Windows::Networking::Vpn::VpnChannel & channel, Windows::Networking::Vpn::VpnPacketBuffer & keepAlivePacket) const;
    void Encapsulate(const Windows::Networking::Vpn::VpnChannel & channel, const Windows::Networking::Vpn::VpnPacketBufferList & packets, const Windows::Networking::Vpn::VpnPacketBufferList & encapulatedPackets) const;
    void Decapsulate(const Windows::Networking::Vpn::VpnChannel & channel, const Windows::Networking::Vpn::VpnPacketBuffer & encapBuffer, const Windows::Networking::Vpn::VpnPacketBufferList & decapsulatedPackets, const Windows::Networking::Vpn::VpnPacketBufferList & controlPacketsToSend) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnPlugInProfile
{
    Windows::Foundation::Collections::IVector<Windows::Foundation::Uri> ServerUris() const;
    hstring CustomConfiguration() const;
    void CustomConfiguration(hstring_view value) const;
    hstring VpnPluginPackageFamilyName() const;
    void VpnPluginPackageFamilyName(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnPlugInProfile2
{
    bool RequireVpnClientAppUI() const;
    void RequireVpnClientAppUI(bool value) const;
    Windows::Networking::Vpn::VpnManagementConnectionStatus ConnectionStatus() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnProfile
{
    hstring ProfileName() const;
    void ProfileName(hstring_view value) const;
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnAppId> AppTriggers() const;
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> Routes() const;
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnDomainNameInfo> DomainNameInfoList() const;
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnTrafficFilter> TrafficFilters() const;
    bool RememberCredentials() const;
    void RememberCredentials(bool value) const;
    bool AlwaysOn() const;
    void AlwaysOn(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnRoute
{
    void Address(const Windows::Networking::HostName & value) const;
    Windows::Networking::HostName Address() const;
    void PrefixSize(uint8_t value) const;
    uint8_t PrefixSize() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnRouteAssignment
{
    void Ipv4InclusionRoutes(const Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> & value) const;
    void Ipv6InclusionRoutes(const Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> & value) const;
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> Ipv4InclusionRoutes() const;
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> Ipv6InclusionRoutes() const;
    void Ipv4ExclusionRoutes(const Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> & value) const;
    void Ipv6ExclusionRoutes(const Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> & value) const;
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> Ipv4ExclusionRoutes() const;
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnRoute> Ipv6ExclusionRoutes() const;
    void ExcludeLocalSubnets(bool value) const;
    bool ExcludeLocalSubnets() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnRouteFactory
{
    Windows::Networking::Vpn::VpnRoute CreateVpnRoute(const Windows::Networking::HostName & address, uint8_t prefixSize) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnSystemHealth
{
    Windows::Storage::Streams::Buffer StatementOfHealth() const;
};

template <typename D>
struct WINRT_EBO impl_IVpnTrafficFilter
{
    Windows::Networking::Vpn::VpnAppId AppId() const;
    void AppId(const Windows::Networking::Vpn::VpnAppId & value) const;
    Windows::Foundation::Collections::IVector<hstring> AppClaims() const;
    Windows::Networking::Vpn::VpnIPProtocol Protocol() const;
    void Protocol(Windows::Networking::Vpn::VpnIPProtocol value) const;
    Windows::Foundation::Collections::IVector<hstring> LocalPortRanges() const;
    Windows::Foundation::Collections::IVector<hstring> RemotePortRanges() const;
    Windows::Foundation::Collections::IVector<hstring> LocalAddressRanges() const;
    Windows::Foundation::Collections::IVector<hstring> RemoteAddressRanges() const;
    Windows::Networking::Vpn::VpnRoutingPolicyType RoutingPolicyType() const;
    void RoutingPolicyType(Windows::Networking::Vpn::VpnRoutingPolicyType value) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnTrafficFilterAssignment
{
    Windows::Foundation::Collections::IVector<Windows::Networking::Vpn::VpnTrafficFilter> TrafficFilterList() const;
    bool AllowOutbound() const;
    void AllowOutbound(bool value) const;
    bool AllowInbound() const;
    void AllowInbound(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IVpnTrafficFilterFactory
{
    Windows::Networking::Vpn::VpnTrafficFilter Create(const Windows::Networking::Vpn::VpnAppId & appId) const;
};

}

namespace impl {

template <> struct traits<Windows::Networking::Vpn::IVpnAppId>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnAppId;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnAppId<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnAppIdFactory>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnAppIdFactory;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnAppIdFactory<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnChannel>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnChannel;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnChannel<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnChannel2>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnChannel2;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnChannel2<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnChannelActivityEventArgs>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnChannelActivityEventArgs;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnChannelActivityEventArgs<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnChannelActivityStateChangedArgs>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnChannelActivityStateChangedArgs;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnChannelActivityStateChangedArgs<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnChannelConfiguration>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnChannelConfiguration;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnChannelConfiguration<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnChannelConfiguration2>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnChannelConfiguration2;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnChannelConfiguration2<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnChannelStatics>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnChannelStatics;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnChannelStatics<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCredential>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCredential;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCredential<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomCheckBox>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomCheckBox;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomCheckBox<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomComboBox>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomComboBox;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomComboBox<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomEditBox>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomEditBox;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomEditBox<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomErrorBox>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomErrorBox;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomErrorBox<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomPrompt>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomPrompt;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomPrompt<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomPromptBooleanInput>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomPromptBooleanInput;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomPromptBooleanInput<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomPromptElement>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomPromptElement;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomPromptElement<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomPromptOptionSelector>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomPromptOptionSelector;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomPromptOptionSelector<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomPromptText>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomPromptText;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomPromptText<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomPromptTextInput>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomPromptTextInput;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomPromptTextInput<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnCustomTextBox>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnCustomTextBox;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnCustomTextBox<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnDomainNameAssignment>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnDomainNameAssignment;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnDomainNameAssignment<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnDomainNameInfo>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnDomainNameInfo;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnDomainNameInfo<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnDomainNameInfo2>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnDomainNameInfo2;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnDomainNameInfo2<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnDomainNameInfoFactory>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnDomainNameInfoFactory;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnDomainNameInfoFactory<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnInterfaceId>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnInterfaceId;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnInterfaceId<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnInterfaceIdFactory>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnInterfaceIdFactory;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnInterfaceIdFactory<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnManagementAgent>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnManagementAgent;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnManagementAgent<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnNamespaceAssignment>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnNamespaceAssignment;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnNamespaceAssignment<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnNamespaceInfo>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnNamespaceInfo;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnNamespaceInfo<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnNamespaceInfoFactory>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnNamespaceInfoFactory;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnNamespaceInfoFactory<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnNativeProfile>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnNativeProfile;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnNativeProfile<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnNativeProfile2>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnNativeProfile2;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnNativeProfile2<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPacketBuffer>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPacketBuffer;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPacketBuffer<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPacketBuffer2>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPacketBuffer2;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPacketBuffer2<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPacketBufferFactory>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPacketBufferFactory;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPacketBufferFactory<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPacketBufferList>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPacketBufferList;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPacketBufferList<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPacketBufferList2>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPacketBufferList2;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPacketBufferList2<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPickedCredential>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPickedCredential;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPickedCredential<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPlugIn>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPlugIn;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPlugIn<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPlugInProfile>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPlugInProfile;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPlugInProfile<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnPlugInProfile2>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnPlugInProfile2;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnPlugInProfile2<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnProfile>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnProfile;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnProfile<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnRoute>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnRoute;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnRoute<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnRouteAssignment>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnRouteAssignment;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnRouteAssignment<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnRouteFactory>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnRouteFactory;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnRouteFactory<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnSystemHealth>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnSystemHealth;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnSystemHealth<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnTrafficFilter>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnTrafficFilter;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnTrafficFilter<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnTrafficFilterAssignment>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnTrafficFilterAssignment;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnTrafficFilterAssignment<D>;
};

template <> struct traits<Windows::Networking::Vpn::IVpnTrafficFilterFactory>
{
    using abi = ABI::Windows::Networking::Vpn::IVpnTrafficFilterFactory;
    template <typename D> using consume = Windows::Networking::Vpn::impl_IVpnTrafficFilterFactory<D>;
};

template <> struct traits<Windows::Networking::Vpn::VpnAppId>
{
    using abi = ABI::Windows::Networking::Vpn::VpnAppId;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnAppId"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnChannel>
{
    using abi = ABI::Windows::Networking::Vpn::VpnChannel;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnChannel"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnChannelActivityEventArgs>
{
    using abi = ABI::Windows::Networking::Vpn::VpnChannelActivityEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnChannelActivityEventArgs"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnChannelActivityStateChangedArgs>
{
    using abi = ABI::Windows::Networking::Vpn::VpnChannelActivityStateChangedArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnChannelActivityStateChangedArgs"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnChannelConfiguration>
{
    using abi = ABI::Windows::Networking::Vpn::VpnChannelConfiguration;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnChannelConfiguration"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCredential>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCredential;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCredential"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomCheckBox>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomCheckBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomCheckBox"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomComboBox>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomComboBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomComboBox"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomEditBox>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomEditBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomEditBox"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomErrorBox>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomErrorBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomErrorBox"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomPromptBooleanInput>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomPromptBooleanInput;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomPromptBooleanInput"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomPromptOptionSelector>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomPromptOptionSelector;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomPromptOptionSelector"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomPromptText>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomPromptText;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomPromptText"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomPromptTextInput>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomPromptTextInput;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomPromptTextInput"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnCustomTextBox>
{
    using abi = ABI::Windows::Networking::Vpn::VpnCustomTextBox;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnCustomTextBox"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnDomainNameAssignment>
{
    using abi = ABI::Windows::Networking::Vpn::VpnDomainNameAssignment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnDomainNameAssignment"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnDomainNameInfo>
{
    using abi = ABI::Windows::Networking::Vpn::VpnDomainNameInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnDomainNameInfo"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnInterfaceId>
{
    using abi = ABI::Windows::Networking::Vpn::VpnInterfaceId;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnInterfaceId"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnManagementAgent>
{
    using abi = ABI::Windows::Networking::Vpn::VpnManagementAgent;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnManagementAgent"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnNamespaceAssignment>
{
    using abi = ABI::Windows::Networking::Vpn::VpnNamespaceAssignment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnNamespaceAssignment"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnNamespaceInfo>
{
    using abi = ABI::Windows::Networking::Vpn::VpnNamespaceInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnNamespaceInfo"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnNativeProfile>
{
    using abi = ABI::Windows::Networking::Vpn::VpnNativeProfile;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnNativeProfile"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnPacketBuffer>
{
    using abi = ABI::Windows::Networking::Vpn::VpnPacketBuffer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnPacketBuffer"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnPacketBufferList>
{
    using abi = ABI::Windows::Networking::Vpn::VpnPacketBufferList;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnPacketBufferList"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnPickedCredential>
{
    using abi = ABI::Windows::Networking::Vpn::VpnPickedCredential;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnPickedCredential"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnPlugInProfile>
{
    using abi = ABI::Windows::Networking::Vpn::VpnPlugInProfile;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnPlugInProfile"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnRoute>
{
    using abi = ABI::Windows::Networking::Vpn::VpnRoute;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnRoute"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnRouteAssignment>
{
    using abi = ABI::Windows::Networking::Vpn::VpnRouteAssignment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnRouteAssignment"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnSystemHealth>
{
    using abi = ABI::Windows::Networking::Vpn::VpnSystemHealth;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnSystemHealth"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnTrafficFilter>
{
    using abi = ABI::Windows::Networking::Vpn::VpnTrafficFilter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnTrafficFilter"; }
};

template <> struct traits<Windows::Networking::Vpn::VpnTrafficFilterAssignment>
{
    using abi = ABI::Windows::Networking::Vpn::VpnTrafficFilterAssignment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Networking.Vpn.VpnTrafficFilterAssignment"; }
};

}

}
