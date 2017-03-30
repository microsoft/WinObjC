// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Bluetooth {

struct IBluetoothClassOfDevice;
struct IBluetoothClassOfDeviceStatics;
struct IBluetoothDevice;
struct IBluetoothDevice2;
struct IBluetoothDevice3;
struct IBluetoothDeviceStatics;
struct IBluetoothDeviceStatics2;
struct IBluetoothLEAppearance;
struct IBluetoothLEAppearanceCategoriesStatics;
struct IBluetoothLEAppearanceStatics;
struct IBluetoothLEAppearanceSubcategoriesStatics;
struct IBluetoothLEDevice;
struct IBluetoothLEDevice2;
struct IBluetoothLEDeviceStatics;
struct IBluetoothLEDeviceStatics2;
struct IBluetoothSignalStrengthFilter;
struct BluetoothClassOfDevice;
struct BluetoothDevice;
struct BluetoothLEAppearance;
struct BluetoothLEDevice;
struct BluetoothSignalStrengthFilter;

}

namespace Windows::Devices::Bluetooth {

struct IBluetoothClassOfDevice;
struct IBluetoothClassOfDeviceStatics;
struct IBluetoothDevice;
struct IBluetoothDevice2;
struct IBluetoothDevice3;
struct IBluetoothDeviceStatics;
struct IBluetoothDeviceStatics2;
struct IBluetoothLEAppearance;
struct IBluetoothLEAppearanceCategoriesStatics;
struct IBluetoothLEAppearanceStatics;
struct IBluetoothLEAppearanceSubcategoriesStatics;
struct IBluetoothLEDevice;
struct IBluetoothLEDevice2;
struct IBluetoothLEDeviceStatics;
struct IBluetoothLEDeviceStatics2;
struct IBluetoothSignalStrengthFilter;
struct BluetoothClassOfDevice;
struct BluetoothDevice;
struct BluetoothLEAppearance;
struct BluetoothLEAppearanceCategories;
struct BluetoothLEAppearanceSubcategories;
struct BluetoothLEDevice;
struct BluetoothSignalStrengthFilter;

}

namespace Windows::Devices::Bluetooth {

template <typename T> struct impl_IBluetoothClassOfDevice;
template <typename T> struct impl_IBluetoothClassOfDeviceStatics;
template <typename T> struct impl_IBluetoothDevice;
template <typename T> struct impl_IBluetoothDevice2;
template <typename T> struct impl_IBluetoothDevice3;
template <typename T> struct impl_IBluetoothDeviceStatics;
template <typename T> struct impl_IBluetoothDeviceStatics2;
template <typename T> struct impl_IBluetoothLEAppearance;
template <typename T> struct impl_IBluetoothLEAppearanceCategoriesStatics;
template <typename T> struct impl_IBluetoothLEAppearanceStatics;
template <typename T> struct impl_IBluetoothLEAppearanceSubcategoriesStatics;
template <typename T> struct impl_IBluetoothLEDevice;
template <typename T> struct impl_IBluetoothLEDevice2;
template <typename T> struct impl_IBluetoothLEDeviceStatics;
template <typename T> struct impl_IBluetoothLEDeviceStatics2;
template <typename T> struct impl_IBluetoothSignalStrengthFilter;

}

namespace Windows::Devices::Bluetooth {

enum class BluetoothAddressType
{
    Public = 0,
    Random = 1,
};

enum class BluetoothCacheMode
{
    Cached = 0,
    Uncached = 1,
};

enum class BluetoothConnectionStatus
{
    Disconnected = 0,
    Connected = 1,
};

enum class BluetoothError
{
    Success = 0,
    RadioNotAvailable = 1,
    ResourceInUse = 2,
    DeviceNotConnected = 3,
    OtherError = 4,
    DisabledByPolicy = 5,
    NotSupported = 6,
    DisabledByUser = 7,
    ConsentRequired = 8,
};

enum class BluetoothMajorClass
{
    Miscellaneous = 0,
    Computer = 1,
    Phone = 2,
    NetworkAccessPoint = 3,
    AudioVideo = 4,
    Peripheral = 5,
    Imaging = 6,
    Wearable = 7,
    Toy = 8,
    Health = 9,
};

enum class BluetoothMinorClass
{
    Uncategorized = 0,
    ComputerDesktop = 1,
    ComputerServer = 2,
    ComputerLaptop = 3,
    ComputerHandheld = 4,
    ComputerPalmSize = 5,
    ComputerWearable = 6,
    ComputerTablet = 7,
    PhoneCellular = 1,
    PhoneCordless = 2,
    PhoneSmartPhone = 3,
    PhoneWired = 4,
    PhoneIsdn = 5,
    NetworkFullyAvailable = 0,
    NetworkUsed01To17Percent = 8,
    NetworkUsed17To33Percent = 16,
    NetworkUsed33To50Percent = 24,
    NetworkUsed50To67Percent = 32,
    NetworkUsed67To83Percent = 40,
    NetworkUsed83To99Percent = 48,
    NetworkNoServiceAvailable = 56,
    AudioVideoWearableHeadset = 1,
    AudioVideoHandsFree = 2,
    AudioVideoMicrophone = 4,
    AudioVideoLoudspeaker = 5,
    AudioVideoHeadphones = 6,
    AudioVideoPortableAudio = 7,
    AudioVideoCarAudio = 8,
    AudioVideoSetTopBox = 9,
    AudioVideoHifiAudioDevice = 10,
    AudioVideoVcr = 11,
    AudioVideoVideoCamera = 12,
    AudioVideoCamcorder = 13,
    AudioVideoVideoMonitor = 14,
    AudioVideoVideoDisplayAndLoudspeaker = 15,
    AudioVideoVideoConferencing = 16,
    AudioVideoGamingOrToy = 18,
    PeripheralJoystick = 1,
    PeripheralGamepad = 2,
    PeripheralRemoteControl = 3,
    PeripheralSensing = 4,
    PeripheralDigitizerTablet = 5,
    PeripheralCardReader = 6,
    PeripheralDigitalPen = 7,
    PeripheralHandheldScanner = 8,
    PeripheralHandheldGesture = 9,
    WearableWristwatch = 1,
    WearablePager = 2,
    WearableJacket = 3,
    WearableHelmet = 4,
    WearableGlasses = 5,
    ToyRobot = 1,
    ToyVehicle = 2,
    ToyDoll = 3,
    ToyController = 4,
    ToyGame = 5,
    HealthBloodPressureMonitor = 1,
    HealthThermometer = 2,
    HealthWeighingScale = 3,
    HealthGlucoseMeter = 4,
    HealthPulseOximeter = 5,
    HealthHeartRateMonitor = 6,
    HealthHealthDataDisplay = 7,
    HealthStepCounter = 8,
    HealthBodyCompositionAnalyzer = 9,
    HealthPeakFlowMonitor = 10,
    HealthMedicationMonitor = 11,
    HealthKneeProsthesis = 12,
    HealthAnkleProsthesis = 13,
    HealthGenericHealthManager = 14,
    HealthPersonalMobilityDevice = 15,
};

enum class BluetoothServiceCapabilities : unsigned
{
    None = 0x0,
    LimitedDiscoverableMode = 0x1,
    PositioningService = 0x8,
    NetworkingService = 0x10,
    RenderingService = 0x20,
    CapturingService = 0x40,
    ObjectTransferService = 0x80,
    AudioService = 0x100,
    TelephoneService = 0x200,
    InformationService = 0x400,
};

DEFINE_ENUM_FLAG_OPERATORS(BluetoothServiceCapabilities)

}

}
