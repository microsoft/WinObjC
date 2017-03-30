// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Networking.NetworkOperators.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Networking::NetworkOperators {

struct FdnAccessManager
{
    FdnAccessManager() = delete;
    static Windows::Foundation::IAsyncOperation<bool> RequestUnlockAsync(hstring_view contactListId);
};

struct WINRT_EBO HotspotAuthenticationContext :
    Windows::Networking::NetworkOperators::IHotspotAuthenticationContext,
    impl::require<HotspotAuthenticationContext, Windows::Networking::NetworkOperators::IHotspotAuthenticationContext2>
{
    HotspotAuthenticationContext(std::nullptr_t) noexcept {}
    static bool TryGetAuthenticationContext(hstring_view evenToken, Windows::Networking::NetworkOperators::HotspotAuthenticationContext & context);
};

struct WINRT_EBO HotspotAuthenticationEventDetails :
    Windows::Networking::NetworkOperators::IHotspotAuthenticationEventDetails
{
    HotspotAuthenticationEventDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HotspotCredentialsAuthenticationResult :
    Windows::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult
{
    HotspotCredentialsAuthenticationResult(std::nullptr_t) noexcept {}
};

struct KnownCSimFilePaths
{
    KnownCSimFilePaths() = delete;
    static Windows::Foundation::Collections::IVectorView<uint32_t> EFSpn();
    static Windows::Foundation::Collections::IVectorView<uint32_t> Gid1();
    static Windows::Foundation::Collections::IVectorView<uint32_t> Gid2();
};

struct KnownRuimFilePaths
{
    KnownRuimFilePaths() = delete;
    static Windows::Foundation::Collections::IVectorView<uint32_t> EFSpn();
    static Windows::Foundation::Collections::IVectorView<uint32_t> Gid1();
    static Windows::Foundation::Collections::IVectorView<uint32_t> Gid2();
};

struct KnownSimFilePaths
{
    KnownSimFilePaths() = delete;
    static Windows::Foundation::Collections::IVectorView<uint32_t> EFOns();
    static Windows::Foundation::Collections::IVectorView<uint32_t> EFSpn();
    static Windows::Foundation::Collections::IVectorView<uint32_t> Gid1();
    static Windows::Foundation::Collections::IVectorView<uint32_t> Gid2();
};

struct KnownUSimFilePaths
{
    KnownUSimFilePaths() = delete;
    static Windows::Foundation::Collections::IVectorView<uint32_t> EFSpn();
    static Windows::Foundation::Collections::IVectorView<uint32_t> EFOpl();
    static Windows::Foundation::Collections::IVectorView<uint32_t> EFPnn();
    static Windows::Foundation::Collections::IVectorView<uint32_t> Gid1();
    static Windows::Foundation::Collections::IVectorView<uint32_t> Gid2();
};

struct WINRT_EBO MobileBroadbandAccount :
    Windows::Networking::NetworkOperators::IMobileBroadbandAccount,
    impl::require<MobileBroadbandAccount, Windows::Networking::NetworkOperators::IMobileBroadbandAccount2>
{
    MobileBroadbandAccount(std::nullptr_t) noexcept {}
    static Windows::Foundation::Collections::IVectorView<hstring> AvailableNetworkAccountIds();
    static Windows::Networking::NetworkOperators::MobileBroadbandAccount CreateFromNetworkAccountId(hstring_view networkAccountId);
};

struct WINRT_EBO MobileBroadbandAccountEventArgs :
    Windows::Networking::NetworkOperators::IMobileBroadbandAccountEventArgs
{
    MobileBroadbandAccountEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandAccountUpdatedEventArgs :
    Windows::Networking::NetworkOperators::IMobileBroadbandAccountUpdatedEventArgs
{
    MobileBroadbandAccountUpdatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandAccountWatcher :
    Windows::Networking::NetworkOperators::IMobileBroadbandAccountWatcher
{
    MobileBroadbandAccountWatcher(std::nullptr_t) noexcept {}
    MobileBroadbandAccountWatcher();
};

struct WINRT_EBO MobileBroadbandDeviceInformation :
    Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation,
    impl::require<MobileBroadbandDeviceInformation, Windows::Networking::NetworkOperators::IMobileBroadbandDeviceInformation2>
{
    MobileBroadbandDeviceInformation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandDeviceService :
    Windows::Networking::NetworkOperators::IMobileBroadbandDeviceService
{
    MobileBroadbandDeviceService(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandDeviceServiceCommandResult :
    Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandResult
{
    MobileBroadbandDeviceServiceCommandResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandDeviceServiceCommandSession :
    Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession
{
    MobileBroadbandDeviceServiceCommandSession(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandDeviceServiceDataReceivedEventArgs :
    Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataReceivedEventArgs
{
    MobileBroadbandDeviceServiceDataReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandDeviceServiceDataSession :
    Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession
{
    MobileBroadbandDeviceServiceDataSession(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandDeviceServiceInformation :
    Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceInformation
{
    MobileBroadbandDeviceServiceInformation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandDeviceServiceTriggerDetails :
    Windows::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails
{
    MobileBroadbandDeviceServiceTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandModem :
    Windows::Networking::NetworkOperators::IMobileBroadbandModem
{
    MobileBroadbandModem(std::nullptr_t) noexcept {}
    static hstring GetDeviceSelector();
    static Windows::Networking::NetworkOperators::MobileBroadbandModem FromId(hstring_view deviceId);
    static Windows::Networking::NetworkOperators::MobileBroadbandModem GetDefault();
};

struct WINRT_EBO MobileBroadbandModemConfiguration :
    Windows::Networking::NetworkOperators::IMobileBroadbandModemConfiguration
{
    MobileBroadbandModemConfiguration(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandNetwork :
    Windows::Networking::NetworkOperators::IMobileBroadbandNetwork,
    impl::require<MobileBroadbandNetwork, Windows::Networking::NetworkOperators::IMobileBroadbandNetwork2>
{
    MobileBroadbandNetwork(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandNetworkRegistrationStateChange :
    Windows::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChange
{
    MobileBroadbandNetworkRegistrationStateChange(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandNetworkRegistrationStateChangeTriggerDetails :
    Windows::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails
{
    MobileBroadbandNetworkRegistrationStateChangeTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandPin :
    Windows::Networking::NetworkOperators::IMobileBroadbandPin
{
    MobileBroadbandPin(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandPinLockStateChange :
    Windows::Networking::NetworkOperators::IMobileBroadbandPinLockStateChange
{
    MobileBroadbandPinLockStateChange(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandPinLockStateChangeTriggerDetails :
    Windows::Networking::NetworkOperators::IMobileBroadbandPinLockStateChangeTriggerDetails
{
    MobileBroadbandPinLockStateChangeTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandPinManager :
    Windows::Networking::NetworkOperators::IMobileBroadbandPinManager
{
    MobileBroadbandPinManager(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandPinOperationResult :
    Windows::Networking::NetworkOperators::IMobileBroadbandPinOperationResult
{
    MobileBroadbandPinOperationResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandRadioStateChange :
    Windows::Networking::NetworkOperators::IMobileBroadbandRadioStateChange
{
    MobileBroadbandRadioStateChange(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandRadioStateChangeTriggerDetails :
    Windows::Networking::NetworkOperators::IMobileBroadbandRadioStateChangeTriggerDetails
{
    MobileBroadbandRadioStateChangeTriggerDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandUicc :
    Windows::Networking::NetworkOperators::IMobileBroadbandUicc
{
    MobileBroadbandUicc(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandUiccApp :
    Windows::Networking::NetworkOperators::IMobileBroadbandUiccApp
{
    MobileBroadbandUiccApp(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandUiccAppReadRecordResult :
    Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppReadRecordResult
{
    MobileBroadbandUiccAppReadRecordResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandUiccAppRecordDetailsResult :
    Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult
{
    MobileBroadbandUiccAppRecordDetailsResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MobileBroadbandUiccAppsResult :
    Windows::Networking::NetworkOperators::IMobileBroadbandUiccAppsResult
{
    MobileBroadbandUiccAppsResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO NetworkOperatorNotificationEventDetails :
    Windows::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails,
    impl::require<NetworkOperatorNotificationEventDetails, Windows::Networking::NetworkOperators::INetworkOperatorTetheringEntitlementCheck>
{
    NetworkOperatorNotificationEventDetails(std::nullptr_t) noexcept {}
};

struct WINRT_EBO NetworkOperatorTetheringAccessPointConfiguration :
    Windows::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration
{
    NetworkOperatorTetheringAccessPointConfiguration(std::nullptr_t) noexcept {}
    NetworkOperatorTetheringAccessPointConfiguration();
};

struct WINRT_EBO NetworkOperatorTetheringClient :
    Windows::Networking::NetworkOperators::INetworkOperatorTetheringClient
{
    NetworkOperatorTetheringClient(std::nullptr_t) noexcept {}
};

struct WINRT_EBO NetworkOperatorTetheringManager :
    Windows::Networking::NetworkOperators::INetworkOperatorTetheringManager,
    impl::require<NetworkOperatorTetheringManager, Windows::Networking::NetworkOperators::INetworkOperatorTetheringClientManager>
{
    NetworkOperatorTetheringManager(std::nullptr_t) noexcept {}
    static Windows::Networking::NetworkOperators::TetheringCapability GetTetheringCapability(hstring_view networkAccountId);
    static Windows::Networking::NetworkOperators::NetworkOperatorTetheringManager CreateFromNetworkAccountId(hstring_view networkAccountId);
    static Windows::Networking::NetworkOperators::TetheringCapability GetTetheringCapabilityFromConnectionProfile(const Windows::Networking::Connectivity::ConnectionProfile & profile);
    static Windows::Networking::NetworkOperators::NetworkOperatorTetheringManager CreateFromConnectionProfile(const Windows::Networking::Connectivity::ConnectionProfile & profile);
    static Windows::Networking::NetworkOperators::NetworkOperatorTetheringManager CreateFromConnectionProfile(const Windows::Networking::Connectivity::ConnectionProfile & profile, const Windows::Networking::Connectivity::NetworkAdapter & adapter);
};

struct WINRT_EBO NetworkOperatorTetheringOperationResult :
    Windows::Networking::NetworkOperators::INetworkOperatorTetheringOperationResult
{
    NetworkOperatorTetheringOperationResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ProvisionFromXmlDocumentResults :
    Windows::Networking::NetworkOperators::IProvisionFromXmlDocumentResults
{
    ProvisionFromXmlDocumentResults(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ProvisionedProfile :
    Windows::Networking::NetworkOperators::IProvisionedProfile
{
    ProvisionedProfile(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ProvisioningAgent :
    Windows::Networking::NetworkOperators::IProvisioningAgent
{
    ProvisioningAgent(std::nullptr_t) noexcept {}
    ProvisioningAgent();
    static Windows::Networking::NetworkOperators::ProvisioningAgent CreateFromNetworkAccountId(hstring_view networkAccountId);
};

struct WINRT_EBO UssdMessage :
    Windows::Networking::NetworkOperators::IUssdMessage
{
    UssdMessage(std::nullptr_t) noexcept {}
    UssdMessage(hstring_view messageText);
};

struct WINRT_EBO UssdReply :
    Windows::Networking::NetworkOperators::IUssdReply
{
    UssdReply(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UssdSession :
    Windows::Networking::NetworkOperators::IUssdSession
{
    UssdSession(std::nullptr_t) noexcept {}
    static Windows::Networking::NetworkOperators::UssdSession CreateFromNetworkAccountId(hstring_view networkAccountId);
    static Windows::Networking::NetworkOperators::UssdSession CreateFromNetworkInterfaceId(hstring_view networkInterfaceId);
};

}

}
