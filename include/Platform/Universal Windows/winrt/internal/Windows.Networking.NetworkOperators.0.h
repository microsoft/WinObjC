// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Networking::NetworkOperators {

struct ProfileUsage;

}

namespace Windows::Networking::NetworkOperators {

using ProfileUsage = ABI::Windows::Networking::NetworkOperators::ProfileUsage;

}

namespace ABI::Windows::Networking::NetworkOperators {

struct IFdnAccessManagerStatics;
struct IHotspotAuthenticationContext;
struct IHotspotAuthenticationContext2;
struct IHotspotAuthenticationContextStatics;
struct IHotspotAuthenticationEventDetails;
struct IHotspotCredentialsAuthenticationResult;
struct IKnownCSimFilePathsStatics;
struct IKnownRuimFilePathsStatics;
struct IKnownSimFilePathsStatics;
struct IKnownUSimFilePathsStatics;
struct IMobileBroadbandAccount;
struct IMobileBroadbandAccount2;
struct IMobileBroadbandAccountEventArgs;
struct IMobileBroadbandAccountStatics;
struct IMobileBroadbandAccountUpdatedEventArgs;
struct IMobileBroadbandAccountWatcher;
struct IMobileBroadbandDeviceInformation;
struct IMobileBroadbandDeviceInformation2;
struct IMobileBroadbandDeviceService;
struct IMobileBroadbandDeviceServiceCommandResult;
struct IMobileBroadbandDeviceServiceCommandSession;
struct IMobileBroadbandDeviceServiceDataReceivedEventArgs;
struct IMobileBroadbandDeviceServiceDataSession;
struct IMobileBroadbandDeviceServiceInformation;
struct IMobileBroadbandDeviceServiceTriggerDetails;
struct IMobileBroadbandModem;
struct IMobileBroadbandModemConfiguration;
struct IMobileBroadbandModemStatics;
struct IMobileBroadbandNetwork;
struct IMobileBroadbandNetwork2;
struct IMobileBroadbandNetworkRegistrationStateChange;
struct IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails;
struct IMobileBroadbandPin;
struct IMobileBroadbandPinLockStateChange;
struct IMobileBroadbandPinLockStateChangeTriggerDetails;
struct IMobileBroadbandPinManager;
struct IMobileBroadbandPinOperationResult;
struct IMobileBroadbandRadioStateChange;
struct IMobileBroadbandRadioStateChangeTriggerDetails;
struct IMobileBroadbandUicc;
struct IMobileBroadbandUiccApp;
struct IMobileBroadbandUiccAppReadRecordResult;
struct IMobileBroadbandUiccAppRecordDetailsResult;
struct IMobileBroadbandUiccAppsResult;
struct INetworkOperatorNotificationEventDetails;
struct INetworkOperatorTetheringAccessPointConfiguration;
struct INetworkOperatorTetheringClient;
struct INetworkOperatorTetheringClientManager;
struct INetworkOperatorTetheringEntitlementCheck;
struct INetworkOperatorTetheringManager;
struct INetworkOperatorTetheringManagerStatics;
struct INetworkOperatorTetheringManagerStatics2;
struct INetworkOperatorTetheringManagerStatics3;
struct INetworkOperatorTetheringOperationResult;
struct IProvisionFromXmlDocumentResults;
struct IProvisionedProfile;
struct IProvisioningAgent;
struct IProvisioningAgentStaticMethods;
struct IUssdMessage;
struct IUssdMessageFactory;
struct IUssdReply;
struct IUssdSession;
struct IUssdSessionStatics;
struct HotspotAuthenticationContext;
struct HotspotAuthenticationEventDetails;
struct HotspotCredentialsAuthenticationResult;
struct MobileBroadbandAccount;
struct MobileBroadbandAccountEventArgs;
struct MobileBroadbandAccountUpdatedEventArgs;
struct MobileBroadbandAccountWatcher;
struct MobileBroadbandDeviceInformation;
struct MobileBroadbandDeviceService;
struct MobileBroadbandDeviceServiceCommandResult;
struct MobileBroadbandDeviceServiceCommandSession;
struct MobileBroadbandDeviceServiceDataReceivedEventArgs;
struct MobileBroadbandDeviceServiceDataSession;
struct MobileBroadbandDeviceServiceInformation;
struct MobileBroadbandDeviceServiceTriggerDetails;
struct MobileBroadbandModem;
struct MobileBroadbandModemConfiguration;
struct MobileBroadbandNetwork;
struct MobileBroadbandNetworkRegistrationStateChange;
struct MobileBroadbandNetworkRegistrationStateChangeTriggerDetails;
struct MobileBroadbandPin;
struct MobileBroadbandPinLockStateChange;
struct MobileBroadbandPinLockStateChangeTriggerDetails;
struct MobileBroadbandPinManager;
struct MobileBroadbandPinOperationResult;
struct MobileBroadbandRadioStateChange;
struct MobileBroadbandRadioStateChangeTriggerDetails;
struct MobileBroadbandUicc;
struct MobileBroadbandUiccApp;
struct MobileBroadbandUiccAppReadRecordResult;
struct MobileBroadbandUiccAppRecordDetailsResult;
struct MobileBroadbandUiccAppsResult;
struct NetworkOperatorNotificationEventDetails;
struct NetworkOperatorTetheringAccessPointConfiguration;
struct NetworkOperatorTetheringClient;
struct NetworkOperatorTetheringManager;
struct NetworkOperatorTetheringOperationResult;
struct ProvisionFromXmlDocumentResults;
struct ProvisionedProfile;
struct ProvisioningAgent;
struct UssdMessage;
struct UssdReply;
struct UssdSession;

}

namespace Windows::Networking::NetworkOperators {

struct IFdnAccessManagerStatics;
struct IHotspotAuthenticationContext;
struct IHotspotAuthenticationContext2;
struct IHotspotAuthenticationContextStatics;
struct IHotspotAuthenticationEventDetails;
struct IHotspotCredentialsAuthenticationResult;
struct IKnownCSimFilePathsStatics;
struct IKnownRuimFilePathsStatics;
struct IKnownSimFilePathsStatics;
struct IKnownUSimFilePathsStatics;
struct IMobileBroadbandAccount;
struct IMobileBroadbandAccount2;
struct IMobileBroadbandAccountEventArgs;
struct IMobileBroadbandAccountStatics;
struct IMobileBroadbandAccountUpdatedEventArgs;
struct IMobileBroadbandAccountWatcher;
struct IMobileBroadbandDeviceInformation;
struct IMobileBroadbandDeviceInformation2;
struct IMobileBroadbandDeviceService;
struct IMobileBroadbandDeviceServiceCommandResult;
struct IMobileBroadbandDeviceServiceCommandSession;
struct IMobileBroadbandDeviceServiceDataReceivedEventArgs;
struct IMobileBroadbandDeviceServiceDataSession;
struct IMobileBroadbandDeviceServiceInformation;
struct IMobileBroadbandDeviceServiceTriggerDetails;
struct IMobileBroadbandModem;
struct IMobileBroadbandModemConfiguration;
struct IMobileBroadbandModemStatics;
struct IMobileBroadbandNetwork;
struct IMobileBroadbandNetwork2;
struct IMobileBroadbandNetworkRegistrationStateChange;
struct IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails;
struct IMobileBroadbandPin;
struct IMobileBroadbandPinLockStateChange;
struct IMobileBroadbandPinLockStateChangeTriggerDetails;
struct IMobileBroadbandPinManager;
struct IMobileBroadbandPinOperationResult;
struct IMobileBroadbandRadioStateChange;
struct IMobileBroadbandRadioStateChangeTriggerDetails;
struct IMobileBroadbandUicc;
struct IMobileBroadbandUiccApp;
struct IMobileBroadbandUiccAppReadRecordResult;
struct IMobileBroadbandUiccAppRecordDetailsResult;
struct IMobileBroadbandUiccAppsResult;
struct INetworkOperatorNotificationEventDetails;
struct INetworkOperatorTetheringAccessPointConfiguration;
struct INetworkOperatorTetheringClient;
struct INetworkOperatorTetheringClientManager;
struct INetworkOperatorTetheringEntitlementCheck;
struct INetworkOperatorTetheringManager;
struct INetworkOperatorTetheringManagerStatics;
struct INetworkOperatorTetheringManagerStatics2;
struct INetworkOperatorTetheringManagerStatics3;
struct INetworkOperatorTetheringOperationResult;
struct IProvisionFromXmlDocumentResults;
struct IProvisionedProfile;
struct IProvisioningAgent;
struct IProvisioningAgentStaticMethods;
struct IUssdMessage;
struct IUssdMessageFactory;
struct IUssdReply;
struct IUssdSession;
struct IUssdSessionStatics;
struct FdnAccessManager;
struct HotspotAuthenticationContext;
struct HotspotAuthenticationEventDetails;
struct HotspotCredentialsAuthenticationResult;
struct KnownCSimFilePaths;
struct KnownRuimFilePaths;
struct KnownSimFilePaths;
struct KnownUSimFilePaths;
struct MobileBroadbandAccount;
struct MobileBroadbandAccountEventArgs;
struct MobileBroadbandAccountUpdatedEventArgs;
struct MobileBroadbandAccountWatcher;
struct MobileBroadbandDeviceInformation;
struct MobileBroadbandDeviceService;
struct MobileBroadbandDeviceServiceCommandResult;
struct MobileBroadbandDeviceServiceCommandSession;
struct MobileBroadbandDeviceServiceDataReceivedEventArgs;
struct MobileBroadbandDeviceServiceDataSession;
struct MobileBroadbandDeviceServiceInformation;
struct MobileBroadbandDeviceServiceTriggerDetails;
struct MobileBroadbandModem;
struct MobileBroadbandModemConfiguration;
struct MobileBroadbandNetwork;
struct MobileBroadbandNetworkRegistrationStateChange;
struct MobileBroadbandNetworkRegistrationStateChangeTriggerDetails;
struct MobileBroadbandPin;
struct MobileBroadbandPinLockStateChange;
struct MobileBroadbandPinLockStateChangeTriggerDetails;
struct MobileBroadbandPinManager;
struct MobileBroadbandPinOperationResult;
struct MobileBroadbandRadioStateChange;
struct MobileBroadbandRadioStateChangeTriggerDetails;
struct MobileBroadbandUicc;
struct MobileBroadbandUiccApp;
struct MobileBroadbandUiccAppReadRecordResult;
struct MobileBroadbandUiccAppRecordDetailsResult;
struct MobileBroadbandUiccAppsResult;
struct NetworkOperatorNotificationEventDetails;
struct NetworkOperatorTetheringAccessPointConfiguration;
struct NetworkOperatorTetheringClient;
struct NetworkOperatorTetheringManager;
struct NetworkOperatorTetheringOperationResult;
struct ProvisionFromXmlDocumentResults;
struct ProvisionedProfile;
struct ProvisioningAgent;
struct UssdMessage;
struct UssdReply;
struct UssdSession;

}

namespace Windows::Networking::NetworkOperators {

template <typename T> struct impl_IFdnAccessManagerStatics;
template <typename T> struct impl_IHotspotAuthenticationContext;
template <typename T> struct impl_IHotspotAuthenticationContext2;
template <typename T> struct impl_IHotspotAuthenticationContextStatics;
template <typename T> struct impl_IHotspotAuthenticationEventDetails;
template <typename T> struct impl_IHotspotCredentialsAuthenticationResult;
template <typename T> struct impl_IKnownCSimFilePathsStatics;
template <typename T> struct impl_IKnownRuimFilePathsStatics;
template <typename T> struct impl_IKnownSimFilePathsStatics;
template <typename T> struct impl_IKnownUSimFilePathsStatics;
template <typename T> struct impl_IMobileBroadbandAccount;
template <typename T> struct impl_IMobileBroadbandAccount2;
template <typename T> struct impl_IMobileBroadbandAccountEventArgs;
template <typename T> struct impl_IMobileBroadbandAccountStatics;
template <typename T> struct impl_IMobileBroadbandAccountUpdatedEventArgs;
template <typename T> struct impl_IMobileBroadbandAccountWatcher;
template <typename T> struct impl_IMobileBroadbandDeviceInformation;
template <typename T> struct impl_IMobileBroadbandDeviceInformation2;
template <typename T> struct impl_IMobileBroadbandDeviceService;
template <typename T> struct impl_IMobileBroadbandDeviceServiceCommandResult;
template <typename T> struct impl_IMobileBroadbandDeviceServiceCommandSession;
template <typename T> struct impl_IMobileBroadbandDeviceServiceDataReceivedEventArgs;
template <typename T> struct impl_IMobileBroadbandDeviceServiceDataSession;
template <typename T> struct impl_IMobileBroadbandDeviceServiceInformation;
template <typename T> struct impl_IMobileBroadbandDeviceServiceTriggerDetails;
template <typename T> struct impl_IMobileBroadbandModem;
template <typename T> struct impl_IMobileBroadbandModemConfiguration;
template <typename T> struct impl_IMobileBroadbandModemStatics;
template <typename T> struct impl_IMobileBroadbandNetwork;
template <typename T> struct impl_IMobileBroadbandNetwork2;
template <typename T> struct impl_IMobileBroadbandNetworkRegistrationStateChange;
template <typename T> struct impl_IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails;
template <typename T> struct impl_IMobileBroadbandPin;
template <typename T> struct impl_IMobileBroadbandPinLockStateChange;
template <typename T> struct impl_IMobileBroadbandPinLockStateChangeTriggerDetails;
template <typename T> struct impl_IMobileBroadbandPinManager;
template <typename T> struct impl_IMobileBroadbandPinOperationResult;
template <typename T> struct impl_IMobileBroadbandRadioStateChange;
template <typename T> struct impl_IMobileBroadbandRadioStateChangeTriggerDetails;
template <typename T> struct impl_IMobileBroadbandUicc;
template <typename T> struct impl_IMobileBroadbandUiccApp;
template <typename T> struct impl_IMobileBroadbandUiccAppReadRecordResult;
template <typename T> struct impl_IMobileBroadbandUiccAppRecordDetailsResult;
template <typename T> struct impl_IMobileBroadbandUiccAppsResult;
template <typename T> struct impl_INetworkOperatorNotificationEventDetails;
template <typename T> struct impl_INetworkOperatorTetheringAccessPointConfiguration;
template <typename T> struct impl_INetworkOperatorTetheringClient;
template <typename T> struct impl_INetworkOperatorTetheringClientManager;
template <typename T> struct impl_INetworkOperatorTetheringEntitlementCheck;
template <typename T> struct impl_INetworkOperatorTetheringManager;
template <typename T> struct impl_INetworkOperatorTetheringManagerStatics;
template <typename T> struct impl_INetworkOperatorTetheringManagerStatics2;
template <typename T> struct impl_INetworkOperatorTetheringManagerStatics3;
template <typename T> struct impl_INetworkOperatorTetheringOperationResult;
template <typename T> struct impl_IProvisionFromXmlDocumentResults;
template <typename T> struct impl_IProvisionedProfile;
template <typename T> struct impl_IProvisioningAgent;
template <typename T> struct impl_IProvisioningAgentStaticMethods;
template <typename T> struct impl_IUssdMessage;
template <typename T> struct impl_IUssdMessageFactory;
template <typename T> struct impl_IUssdReply;
template <typename T> struct impl_IUssdSession;
template <typename T> struct impl_IUssdSessionStatics;

}

namespace Windows::Networking::NetworkOperators {

enum class DataClasses : unsigned
{
    None = 0x0,
    Gprs = 0x1,
    Edge = 0x2,
    Umts = 0x4,
    Hsdpa = 0x8,
    Hsupa = 0x10,
    LteAdvanced = 0x20,
    Cdma1xRtt = 0x10000,
    Cdma1xEvdo = 0x20000,
    Cdma1xEvdoRevA = 0x40000,
    Cdma1xEvdv = 0x80000,
    Cdma3xRtt = 0x100000,
    Cdma1xEvdoRevB = 0x200000,
    CdmaUmb = 0x400000,
    Custom = 0x80000000,
};

DEFINE_ENUM_FLAG_OPERATORS(DataClasses)

enum class HotspotAuthenticationResponseCode
{
    NoError = 0,
    LoginSucceeded = 50,
    LoginFailed = 100,
    RadiusServerError = 102,
    NetworkAdministratorError = 105,
    LoginAborted = 151,
    AccessGatewayInternalError = 255,
};

enum class MobileBroadbandAccountWatcherStatus
{
    Created = 0,
    Started = 1,
    EnumerationCompleted = 2,
    Stopped = 3,
    Aborted = 4,
};

enum class MobileBroadbandDeviceType
{
    Unknown = 0,
    Embedded = 1,
    Removable = 2,
    Remote = 3,
};

enum class MobileBroadbandPinFormat
{
    Unknown = 0,
    Numeric = 1,
    Alphanumeric = 2,
};

enum class MobileBroadbandPinLockState
{
    Unknown = 0,
    Unlocked = 1,
    PinRequired = 2,
    PinUnblockKeyRequired = 3,
};

enum class MobileBroadbandPinType
{
    None = 0,
    Custom = 1,
    Pin1 = 2,
    Pin2 = 3,
    SimPin = 4,
    FirstSimPin = 5,
    NetworkPin = 6,
    NetworkSubsetPin = 7,
    ServiceProviderPin = 8,
    CorporatePin = 9,
    SubsidyLock = 10,
};

enum class MobileBroadbandRadioState
{
    Off = 0,
    On = 1,
};

enum class MobileBroadbandUiccAppOperationStatus
{
    Success = 0,
    InvalidUiccFilePath = 1,
    AccessConditionNotHeld = 2,
    UiccBusy = 3,
};

enum class NetworkDeviceStatus
{
    DeviceNotReady = 0,
    DeviceReady = 1,
    SimNotInserted = 2,
    BadSim = 3,
    DeviceHardwareFailure = 4,
    AccountNotActivated = 5,
    DeviceLocked = 6,
    DeviceBlocked = 7,
};

enum class NetworkOperatorEventMessageType
{
    Gsm = 0,
    Cdma = 1,
    Ussd = 2,
    DataPlanThresholdReached = 3,
    DataPlanReset = 4,
    DataPlanDeleted = 5,
    ProfileConnected = 6,
    ProfileDisconnected = 7,
    RegisteredRoaming = 8,
    RegisteredHome = 9,
    TetheringEntitlementCheck = 10,
    TetheringOperationalStateChanged = 11,
    TetheringNumberOfClientsChanged = 12,
};

enum class NetworkRegistrationState
{
    None = 0,
    Deregistered = 1,
    Searching = 2,
    Home = 3,
    Roaming = 4,
    Partner = 5,
    Denied = 6,
};

enum class ProfileMediaType
{
    Wlan = 0,
    Wwan = 1,
};

enum class TetheringCapability
{
    Enabled = 0,
    DisabledByGroupPolicy = 1,
    DisabledByHardwareLimitation = 2,
    DisabledByOperator = 3,
    DisabledBySku = 4,
    DisabledByRequiredAppNotInstalled = 5,
    DisabledDueToUnknownCause = 6,
    DisabledBySystemCapability = 7,
};

enum class TetheringOperationStatus
{
    Success = 0,
    Unknown = 1,
    MobileBroadbandDeviceOff = 2,
    WiFiDeviceOff = 3,
    EntitlementCheckTimeout = 4,
    EntitlementCheckFailure = 5,
    OperationInProgress = 6,
    BluetoothDeviceOff = 7,
    NetworkLimitedConnectivity = 8,
};

enum class TetheringOperationalState
{
    Unknown = 0,
    On = 1,
    Off = 2,
    InTransition = 3,
};

enum class UiccAccessCondition
{
    AlwaysAllowed = 0,
    Pin1 = 1,
    Pin2 = 2,
    Pin3 = 3,
    Pin4 = 4,
    Administrative5 = 5,
    Administrative6 = 6,
    NeverAllowed = 7,
};

enum class UiccAppKind
{
    Unknown = 0,
    MF = 1,
    MFSim = 2,
    MFRuim = 3,
    USim = 4,
    CSim = 5,
    ISim = 6,
};

enum class UiccAppRecordKind
{
    Unknown = 0,
    Transparent = 1,
    RecordOriented = 2,
};

enum class UssdResultCode
{
    NoActionRequired = 0,
    ActionRequired = 1,
    Terminated = 2,
    OtherLocalClient = 3,
    OperationNotSupported = 4,
    NetworkTimeout = 5,
};

}

}
