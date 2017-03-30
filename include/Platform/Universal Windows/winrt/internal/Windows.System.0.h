// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::System {

struct IAppMemoryReport;
struct IAppMemoryUsageLimitChangingEventArgs;
struct IFolderLauncherOptions;
struct IKnownUserPropertiesStatics;
struct ILaunchUriResult;
struct ILauncherOptions;
struct ILauncherOptions2;
struct ILauncherOptions3;
struct ILauncherStatics;
struct ILauncherStatics2;
struct ILauncherStatics3;
struct ILauncherStatics4;
struct ILauncherUIOptions;
struct ILauncherViewOptions;
struct IMemoryManagerStatics;
struct IMemoryManagerStatics2;
struct IMemoryManagerStatics3;
struct IProcessLauncherOptions;
struct IProcessLauncherResult;
struct IProcessLauncherStatics;
struct IProcessMemoryReport;
struct IProtocolForResultsOperation;
struct IRemoteLauncherOptions;
struct IRemoteLauncherStatics;
struct IShutdownManagerStatics;
struct ITimeZoneSettingsStatics;
struct IUser;
struct IUserAuthenticationStatusChangeDeferral;
struct IUserAuthenticationStatusChangingEventArgs;
struct IUserChangedEventArgs;
struct IUserDeviceAssociationChangedEventArgs;
struct IUserDeviceAssociationStatics;
struct IUserPicker;
struct IUserPickerStatics;
struct IUserStatics;
struct IUserWatcher;
struct AppMemoryReport;
struct AppMemoryUsageLimitChangingEventArgs;
struct FolderLauncherOptions;
struct LaunchUriResult;
struct LauncherOptions;
struct LauncherUIOptions;
struct ProcessLauncherOptions;
struct ProcessLauncherResult;
struct ProcessMemoryReport;
struct ProtocolForResultsOperation;
struct RemoteLauncherOptions;
struct User;
struct UserAuthenticationStatusChangeDeferral;
struct UserAuthenticationStatusChangingEventArgs;
struct UserChangedEventArgs;
struct UserDeviceAssociationChangedEventArgs;
struct UserPicker;
struct UserWatcher;

}

namespace Windows::System {

struct IAppMemoryReport;
struct IAppMemoryUsageLimitChangingEventArgs;
struct IFolderLauncherOptions;
struct IKnownUserPropertiesStatics;
struct ILaunchUriResult;
struct ILauncherOptions;
struct ILauncherOptions2;
struct ILauncherOptions3;
struct ILauncherStatics;
struct ILauncherStatics2;
struct ILauncherStatics3;
struct ILauncherStatics4;
struct ILauncherUIOptions;
struct ILauncherViewOptions;
struct IMemoryManagerStatics;
struct IMemoryManagerStatics2;
struct IMemoryManagerStatics3;
struct IProcessLauncherOptions;
struct IProcessLauncherResult;
struct IProcessLauncherStatics;
struct IProcessMemoryReport;
struct IProtocolForResultsOperation;
struct IRemoteLauncherOptions;
struct IRemoteLauncherStatics;
struct IShutdownManagerStatics;
struct ITimeZoneSettingsStatics;
struct IUser;
struct IUserAuthenticationStatusChangeDeferral;
struct IUserAuthenticationStatusChangingEventArgs;
struct IUserChangedEventArgs;
struct IUserDeviceAssociationChangedEventArgs;
struct IUserDeviceAssociationStatics;
struct IUserPicker;
struct IUserPickerStatics;
struct IUserStatics;
struct IUserWatcher;
struct AppMemoryReport;
struct AppMemoryUsageLimitChangingEventArgs;
struct FolderLauncherOptions;
struct KnownUserProperties;
struct LaunchUriResult;
struct Launcher;
struct LauncherOptions;
struct LauncherUIOptions;
struct MemoryManager;
struct ProcessLauncher;
struct ProcessLauncherOptions;
struct ProcessLauncherResult;
struct ProcessMemoryReport;
struct ProtocolForResultsOperation;
struct RemoteLauncher;
struct RemoteLauncherOptions;
struct ShutdownManager;
struct TimeZoneSettings;
struct User;
struct UserAuthenticationStatusChangeDeferral;
struct UserAuthenticationStatusChangingEventArgs;
struct UserChangedEventArgs;
struct UserDeviceAssociation;
struct UserDeviceAssociationChangedEventArgs;
struct UserPicker;
struct UserWatcher;

}

namespace Windows::System {

template <typename T> struct impl_IAppMemoryReport;
template <typename T> struct impl_IAppMemoryUsageLimitChangingEventArgs;
template <typename T> struct impl_IFolderLauncherOptions;
template <typename T> struct impl_IKnownUserPropertiesStatics;
template <typename T> struct impl_ILaunchUriResult;
template <typename T> struct impl_ILauncherOptions;
template <typename T> struct impl_ILauncherOptions2;
template <typename T> struct impl_ILauncherOptions3;
template <typename T> struct impl_ILauncherStatics;
template <typename T> struct impl_ILauncherStatics2;
template <typename T> struct impl_ILauncherStatics3;
template <typename T> struct impl_ILauncherStatics4;
template <typename T> struct impl_ILauncherUIOptions;
template <typename T> struct impl_ILauncherViewOptions;
template <typename T> struct impl_IMemoryManagerStatics;
template <typename T> struct impl_IMemoryManagerStatics2;
template <typename T> struct impl_IMemoryManagerStatics3;
template <typename T> struct impl_IProcessLauncherOptions;
template <typename T> struct impl_IProcessLauncherResult;
template <typename T> struct impl_IProcessLauncherStatics;
template <typename T> struct impl_IProcessMemoryReport;
template <typename T> struct impl_IProtocolForResultsOperation;
template <typename T> struct impl_IRemoteLauncherOptions;
template <typename T> struct impl_IRemoteLauncherStatics;
template <typename T> struct impl_IShutdownManagerStatics;
template <typename T> struct impl_ITimeZoneSettingsStatics;
template <typename T> struct impl_IUser;
template <typename T> struct impl_IUserAuthenticationStatusChangeDeferral;
template <typename T> struct impl_IUserAuthenticationStatusChangingEventArgs;
template <typename T> struct impl_IUserChangedEventArgs;
template <typename T> struct impl_IUserDeviceAssociationChangedEventArgs;
template <typename T> struct impl_IUserDeviceAssociationStatics;
template <typename T> struct impl_IUserPicker;
template <typename T> struct impl_IUserPickerStatics;
template <typename T> struct impl_IUserStatics;
template <typename T> struct impl_IUserWatcher;

}

namespace Windows::System {

enum class AppMemoryUsageLevel
{
    Low = 0,
    Medium = 1,
    High = 2,
    OverLimit = 3,
};

enum class LaunchFileStatus
{
    Success = 0,
    AppUnavailable = 1,
    DeniedByPolicy = 2,
    FileTypeNotSupported = 3,
    Unknown = 4,
};

enum class LaunchQuerySupportStatus
{
    Available = 0,
    AppNotInstalled = 1,
    AppUnavailable = 2,
    NotSupported = 3,
    Unknown = 4,
};

enum class LaunchQuerySupportType
{
    Uri = 0,
    UriForResults = 1,
};

enum class LaunchUriStatus
{
    Success = 0,
    AppUnavailable = 1,
    ProtocolUnavailable = 2,
    Unknown = 3,
};

enum class ProcessorArchitecture
{
    X86 = 0,
    Arm = 5,
    X64 = 9,
    Neutral = 11,
    Unknown = 65535,
};

enum class RemoteLaunchUriStatus
{
    Unknown = 0,
    Success = 1,
    AppUnavailable = 2,
    ProtocolUnavailable = 3,
    RemoteSystemUnavailable = 4,
    ValueSetTooLarge = 5,
    DeniedByLocalSystem = 6,
    DeniedByRemoteSystem = 7,
};

enum class ShutdownKind
{
    Shutdown = 0,
    Restart = 1,
};

enum class UserAuthenticationStatus
{
    Unauthenticated = 0,
    LocallyAuthenticated = 1,
    RemotelyAuthenticated = 2,
};

enum class UserPictureSize
{
    Size64x64 = 0,
    Size208x208 = 1,
    Size424x424 = 2,
    Size1080x1080 = 3,
};

enum class UserType
{
    LocalUser = 0,
    RemoteUser = 1,
    LocalGuest = 2,
    RemoteGuest = 3,
};

enum class UserWatcherStatus
{
    Created = 0,
    Started = 1,
    EnumerationCompleted = 2,
    Stopping = 3,
    Stopped = 4,
    Aborted = 5,
};

enum class VirtualKey
{
    None = 0,
    LeftButton = 1,
    RightButton = 2,
    Cancel = 3,
    MiddleButton = 4,
    XButton1 = 5,
    XButton2 = 6,
    Back = 8,
    Tab = 9,
    Clear = 12,
    Enter = 13,
    Shift = 16,
    Control = 17,
    Menu = 18,
    Pause = 19,
    CapitalLock = 20,
    Kana = 21,
    Hangul = 21,
    Junja = 23,
    Final = 24,
    Hanja = 25,
    Kanji = 25,
    Escape = 27,
    Convert = 28,
    NonConvert = 29,
    Accept = 30,
    ModeChange = 31,
    Space = 32,
    PageUp = 33,
    PageDown = 34,
    End = 35,
    Home = 36,
    Left = 37,
    Up = 38,
    Right = 39,
    Down = 40,
    Select = 41,
    Print = 42,
    Execute = 43,
    Snapshot = 44,
    Insert = 45,
    Delete = 46,
    Help = 47,
    Number0 = 48,
    Number1 = 49,
    Number2 = 50,
    Number3 = 51,
    Number4 = 52,
    Number5 = 53,
    Number6 = 54,
    Number7 = 55,
    Number8 = 56,
    Number9 = 57,
    A = 65,
    B = 66,
    C = 67,
    D = 68,
    E = 69,
    F = 70,
    G = 71,
    H = 72,
    I = 73,
    J = 74,
    K = 75,
    L = 76,
    M = 77,
    N = 78,
    O = 79,
    P = 80,
    Q = 81,
    R = 82,
    S = 83,
    T = 84,
    U = 85,
    V = 86,
    W = 87,
    X = 88,
    Y = 89,
    Z = 90,
    LeftWindows = 91,
    RightWindows = 92,
    Application = 93,
    Sleep = 95,
    NumberPad0 = 96,
    NumberPad1 = 97,
    NumberPad2 = 98,
    NumberPad3 = 99,
    NumberPad4 = 100,
    NumberPad5 = 101,
    NumberPad6 = 102,
    NumberPad7 = 103,
    NumberPad8 = 104,
    NumberPad9 = 105,
    Multiply = 106,
    Add = 107,
    Separator = 108,
    Subtract = 109,
    Decimal = 110,
    Divide = 111,
    F1 = 112,
    F2 = 113,
    F3 = 114,
    F4 = 115,
    F5 = 116,
    F6 = 117,
    F7 = 118,
    F8 = 119,
    F9 = 120,
    F10 = 121,
    F11 = 122,
    F12 = 123,
    F13 = 124,
    F14 = 125,
    F15 = 126,
    F16 = 127,
    F17 = 128,
    F18 = 129,
    F19 = 130,
    F20 = 131,
    F21 = 132,
    F22 = 133,
    F23 = 134,
    F24 = 135,
    NavigationView = 136,
    NavigationMenu = 137,
    NavigationUp = 138,
    NavigationDown = 139,
    NavigationLeft = 140,
    NavigationRight = 141,
    NavigationAccept = 142,
    NavigationCancel = 143,
    NumberKeyLock = 144,
    Scroll = 145,
    LeftShift = 160,
    RightShift = 161,
    LeftControl = 162,
    RightControl = 163,
    LeftMenu = 164,
    RightMenu = 165,
    GoBack = 166,
    GoForward = 167,
    Refresh = 168,
    Stop = 169,
    Search = 170,
    Favorites = 171,
    GoHome = 172,
    GamepadA = 195,
    GamepadB = 196,
    GamepadX = 197,
    GamepadY = 198,
    GamepadRightShoulder = 199,
    GamepadLeftShoulder = 200,
    GamepadLeftTrigger = 201,
    GamepadRightTrigger = 202,
    GamepadDPadUp = 203,
    GamepadDPadDown = 204,
    GamepadDPadLeft = 205,
    GamepadDPadRight = 206,
    GamepadMenu = 207,
    GamepadView = 208,
    GamepadLeftThumbstickButton = 209,
    GamepadRightThumbstickButton = 210,
    GamepadLeftThumbstickUp = 211,
    GamepadLeftThumbstickDown = 212,
    GamepadLeftThumbstickRight = 213,
    GamepadLeftThumbstickLeft = 214,
    GamepadRightThumbstickUp = 215,
    GamepadRightThumbstickDown = 216,
    GamepadRightThumbstickRight = 217,
    GamepadRightThumbstickLeft = 218,
};

enum class VirtualKeyModifiers : unsigned
{
    None = 0x0,
    Control = 0x1,
    Menu = 0x2,
    Shift = 0x4,
    Windows = 0x8,
};

DEFINE_ENUM_FLAG_OPERATORS(VirtualKeyModifiers)

}

}
