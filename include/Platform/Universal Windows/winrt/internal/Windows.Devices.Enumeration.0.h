// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Enumeration {

struct IDeviceAccessChangedEventArgs;
struct IDeviceAccessChangedEventArgs2;
struct IDeviceAccessInformation;
struct IDeviceAccessInformationStatics;
struct IDeviceConnectionChangeTriggerDetails;
struct IDeviceDisconnectButtonClickedEventArgs;
struct IDeviceInformation;
struct IDeviceInformation2;
struct IDeviceInformationCustomPairing;
struct IDeviceInformationPairing;
struct IDeviceInformationPairing2;
struct IDeviceInformationPairingStatics;
struct IDeviceInformationStatics;
struct IDeviceInformationStatics2;
struct IDeviceInformationUpdate;
struct IDeviceInformationUpdate2;
struct IDevicePairingRequestedEventArgs;
struct IDevicePairingResult;
struct IDevicePairingSettings;
struct IDevicePicker;
struct IDevicePickerAppearance;
struct IDevicePickerFilter;
struct IDeviceSelectedEventArgs;
struct IDeviceUnpairingResult;
struct IDeviceWatcher;
struct IDeviceWatcher2;
struct IDeviceWatcherEvent;
struct IDeviceWatcherTriggerDetails;
struct IEnclosureLocation;
struct IEnclosureLocation2;
struct DeviceAccessChangedEventArgs;
struct DeviceAccessInformation;
struct DeviceConnectionChangeTriggerDetails;
struct DeviceDisconnectButtonClickedEventArgs;
struct DeviceInformation;
struct DeviceInformationCollection;
struct DeviceInformationCustomPairing;
struct DeviceInformationPairing;
struct DeviceInformationUpdate;
struct DevicePairingRequestedEventArgs;
struct DevicePairingResult;
struct DevicePicker;
struct DevicePickerAppearance;
struct DevicePickerFilter;
struct DeviceSelectedEventArgs;
struct DeviceThumbnail;
struct DeviceUnpairingResult;
struct DeviceWatcher;
struct DeviceWatcherEvent;
struct DeviceWatcherTriggerDetails;
struct EnclosureLocation;

}

namespace Windows::Devices::Enumeration {

struct IDeviceAccessChangedEventArgs;
struct IDeviceAccessChangedEventArgs2;
struct IDeviceAccessInformation;
struct IDeviceAccessInformationStatics;
struct IDeviceConnectionChangeTriggerDetails;
struct IDeviceDisconnectButtonClickedEventArgs;
struct IDeviceInformation;
struct IDeviceInformation2;
struct IDeviceInformationCustomPairing;
struct IDeviceInformationPairing;
struct IDeviceInformationPairing2;
struct IDeviceInformationPairingStatics;
struct IDeviceInformationStatics;
struct IDeviceInformationStatics2;
struct IDeviceInformationUpdate;
struct IDeviceInformationUpdate2;
struct IDevicePairingRequestedEventArgs;
struct IDevicePairingResult;
struct IDevicePairingSettings;
struct IDevicePicker;
struct IDevicePickerAppearance;
struct IDevicePickerFilter;
struct IDeviceSelectedEventArgs;
struct IDeviceUnpairingResult;
struct IDeviceWatcher;
struct IDeviceWatcher2;
struct IDeviceWatcherEvent;
struct IDeviceWatcherTriggerDetails;
struct IEnclosureLocation;
struct IEnclosureLocation2;
struct DeviceAccessChangedEventArgs;
struct DeviceAccessInformation;
struct DeviceConnectionChangeTriggerDetails;
struct DeviceDisconnectButtonClickedEventArgs;
struct DeviceInformation;
struct DeviceInformationCollection;
struct DeviceInformationCustomPairing;
struct DeviceInformationPairing;
struct DeviceInformationUpdate;
struct DevicePairingRequestedEventArgs;
struct DevicePairingResult;
struct DevicePicker;
struct DevicePickerAppearance;
struct DevicePickerFilter;
struct DeviceSelectedEventArgs;
struct DeviceThumbnail;
struct DeviceUnpairingResult;
struct DeviceWatcher;
struct DeviceWatcherEvent;
struct DeviceWatcherTriggerDetails;
struct EnclosureLocation;

}

namespace Windows::Devices::Enumeration {

template <typename T> struct impl_IDeviceAccessChangedEventArgs;
template <typename T> struct impl_IDeviceAccessChangedEventArgs2;
template <typename T> struct impl_IDeviceAccessInformation;
template <typename T> struct impl_IDeviceAccessInformationStatics;
template <typename T> struct impl_IDeviceConnectionChangeTriggerDetails;
template <typename T> struct impl_IDeviceDisconnectButtonClickedEventArgs;
template <typename T> struct impl_IDeviceInformation;
template <typename T> struct impl_IDeviceInformation2;
template <typename T> struct impl_IDeviceInformationCustomPairing;
template <typename T> struct impl_IDeviceInformationPairing;
template <typename T> struct impl_IDeviceInformationPairing2;
template <typename T> struct impl_IDeviceInformationPairingStatics;
template <typename T> struct impl_IDeviceInformationStatics;
template <typename T> struct impl_IDeviceInformationStatics2;
template <typename T> struct impl_IDeviceInformationUpdate;
template <typename T> struct impl_IDeviceInformationUpdate2;
template <typename T> struct impl_IDevicePairingRequestedEventArgs;
template <typename T> struct impl_IDevicePairingResult;
template <typename T> struct impl_IDevicePairingSettings;
template <typename T> struct impl_IDevicePicker;
template <typename T> struct impl_IDevicePickerAppearance;
template <typename T> struct impl_IDevicePickerFilter;
template <typename T> struct impl_IDeviceSelectedEventArgs;
template <typename T> struct impl_IDeviceUnpairingResult;
template <typename T> struct impl_IDeviceWatcher;
template <typename T> struct impl_IDeviceWatcher2;
template <typename T> struct impl_IDeviceWatcherEvent;
template <typename T> struct impl_IDeviceWatcherTriggerDetails;
template <typename T> struct impl_IEnclosureLocation;
template <typename T> struct impl_IEnclosureLocation2;

}

namespace Windows::Devices::Enumeration {

enum class DeviceAccessStatus
{
    Unspecified = 0,
    Allowed = 1,
    DeniedByUser = 2,
    DeniedBySystem = 3,
};

enum class DeviceClass
{
    All = 0,
    AudioCapture = 1,
    AudioRender = 2,
    PortableStorageDevice = 3,
    VideoCapture = 4,
    ImageScanner = 5,
    Location = 6,
};

enum class DeviceInformationKind
{
    Unknown = 0,
    DeviceInterface = 1,
    DeviceContainer = 2,
    Device = 3,
    DeviceInterfaceClass = 4,
    AssociationEndpoint = 5,
    AssociationEndpointContainer = 6,
    AssociationEndpointService = 7,
};

enum class DevicePairingKinds : unsigned
{
    None = 0x0,
    ConfirmOnly = 0x1,
    DisplayPin = 0x2,
    ProvidePin = 0x4,
    ConfirmPinMatch = 0x8,
};

DEFINE_ENUM_FLAG_OPERATORS(DevicePairingKinds)

enum class DevicePairingProtectionLevel
{
    Default = 0,
    None = 1,
    Encryption = 2,
    EncryptionAndAuthentication = 3,
};

enum class DevicePairingResultStatus
{
    Paired = 0,
    NotReadyToPair = 1,
    NotPaired = 2,
    AlreadyPaired = 3,
    ConnectionRejected = 4,
    TooManyConnections = 5,
    HardwareFailure = 6,
    AuthenticationTimeout = 7,
    AuthenticationNotAllowed = 8,
    AuthenticationFailure = 9,
    NoSupportedProfiles = 10,
    ProtectionLevelCouldNotBeMet = 11,
    AccessDenied = 12,
    InvalidCeremonyData = 13,
    PairingCanceled = 14,
    OperationAlreadyInProgress = 15,
    RequiredHandlerNotRegistered = 16,
    RejectedByHandler = 17,
    RemoteDeviceHasAssociation = 18,
    Failed = 19,
};

enum class DevicePickerDisplayStatusOptions : unsigned
{
    None = 0x0,
    ShowProgress = 0x1,
    ShowDisconnectButton = 0x2,
    ShowRetryButton = 0x4,
};

DEFINE_ENUM_FLAG_OPERATORS(DevicePickerDisplayStatusOptions)

enum class DeviceUnpairingResultStatus
{
    Unpaired = 0,
    AlreadyUnpaired = 1,
    OperationAlreadyInProgress = 2,
    AccessDenied = 3,
    Failed = 4,
};

enum class DeviceWatcherEventKind
{
    Add = 0,
    Update = 1,
    Remove = 2,
};

enum class DeviceWatcherStatus
{
    Created = 0,
    Started = 1,
    EnumerationCompleted = 2,
    Stopping = 3,
    Stopped = 4,
    Aborted = 5,
};

enum class Panel
{
    Unknown = 0,
    Front = 1,
    Back = 2,
    Top = 3,
    Bottom = 4,
    Left = 5,
    Right = 6,
};

}

}
