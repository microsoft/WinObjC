// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Activation {

struct IActivatedEventArgs;
struct IActivatedEventArgsWithUser;
struct IApplicationViewActivatedEventArgs;
struct IAppointmentsProviderActivatedEventArgs;
struct IAppointmentsProviderAddAppointmentActivatedEventArgs;
struct IAppointmentsProviderRemoveAppointmentActivatedEventArgs;
struct IAppointmentsProviderReplaceAppointmentActivatedEventArgs;
struct IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs;
struct IAppointmentsProviderShowTimeFrameActivatedEventArgs;
struct IBackgroundActivatedEventArgs;
struct ICachedFileUpdaterActivatedEventArgs;
struct ICameraSettingsActivatedEventArgs;
struct IContactActivatedEventArgs;
struct IContactCallActivatedEventArgs;
struct IContactMapActivatedEventArgs;
struct IContactMessageActivatedEventArgs;
struct IContactPickerActivatedEventArgs;
struct IContactPostActivatedEventArgs;
struct IContactVideoCallActivatedEventArgs;
struct IContactsProviderActivatedEventArgs;
struct IContinuationActivatedEventArgs;
struct IDeviceActivatedEventArgs;
struct IDevicePairingActivatedEventArgs;
struct IDialReceiverActivatedEventArgs;
struct IFileActivatedEventArgs;
struct IFileActivatedEventArgsWithCallerPackageFamilyName;
struct IFileActivatedEventArgsWithNeighboringFiles;
struct IFileOpenPickerActivatedEventArgs;
struct IFileOpenPickerActivatedEventArgs2;
struct IFileOpenPickerContinuationEventArgs;
struct IFileSavePickerActivatedEventArgs;
struct IFileSavePickerActivatedEventArgs2;
struct IFileSavePickerContinuationEventArgs;
struct IFolderPickerContinuationEventArgs;
struct ILaunchActivatedEventArgs;
struct ILaunchActivatedEventArgs2;
struct ILockScreenActivatedEventArgs;
struct ILockScreenCallActivatedEventArgs;
struct IPickerReturnedActivatedEventArgs;
struct IPrelaunchActivatedEventArgs;
struct IPrint3DWorkflowActivatedEventArgs;
struct IPrintTaskSettingsActivatedEventArgs;
struct IProtocolActivatedEventArgs;
struct IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData;
struct IProtocolForResultsActivatedEventArgs;
struct IRestrictedLaunchActivatedEventArgs;
struct ISearchActivatedEventArgs;
struct ISearchActivatedEventArgsWithLinguisticDetails;
struct IShareTargetActivatedEventArgs;
struct ISplashScreen;
struct ITileActivatedInfo;
struct IToastNotificationActivatedEventArgs;
struct IUserDataAccountProviderActivatedEventArgs;
struct IViewSwitcherProvider;
struct IVoiceCommandActivatedEventArgs;
struct IWalletActionActivatedEventArgs;
struct IWebAccountProviderActivatedEventArgs;
struct IWebAuthenticationBrokerContinuationEventArgs;
struct AppointmentsProviderAddAppointmentActivatedEventArgs;
struct AppointmentsProviderRemoveAppointmentActivatedEventArgs;
struct AppointmentsProviderReplaceAppointmentActivatedEventArgs;
struct AppointmentsProviderShowAppointmentDetailsActivatedEventArgs;
struct AppointmentsProviderShowTimeFrameActivatedEventArgs;
struct BackgroundActivatedEventArgs;
struct CachedFileUpdaterActivatedEventArgs;
struct CameraSettingsActivatedEventArgs;
struct ContactCallActivatedEventArgs;
struct ContactMapActivatedEventArgs;
struct ContactMessageActivatedEventArgs;
struct ContactPickerActivatedEventArgs;
struct ContactPostActivatedEventArgs;
struct ContactVideoCallActivatedEventArgs;
struct DeviceActivatedEventArgs;
struct DevicePairingActivatedEventArgs;
struct DialReceiverActivatedEventArgs;
struct FileActivatedEventArgs;
struct FileOpenPickerActivatedEventArgs;
struct FileOpenPickerContinuationEventArgs;
struct FileSavePickerActivatedEventArgs;
struct FileSavePickerContinuationEventArgs;
struct FolderPickerContinuationEventArgs;
struct LaunchActivatedEventArgs;
struct LockScreenActivatedEventArgs;
struct LockScreenCallActivatedEventArgs;
struct PickerReturnedActivatedEventArgs;
struct Print3DWorkflowActivatedEventArgs;
struct PrintTaskSettingsActivatedEventArgs;
struct ProtocolActivatedEventArgs;
struct ProtocolForResultsActivatedEventArgs;
struct RestrictedLaunchActivatedEventArgs;
struct SearchActivatedEventArgs;
struct ShareTargetActivatedEventArgs;
struct SplashScreen;
struct TileActivatedInfo;
struct ToastNotificationActivatedEventArgs;
struct UserDataAccountProviderActivatedEventArgs;
struct VoiceCommandActivatedEventArgs;
struct WalletActionActivatedEventArgs;
struct WebAccountProviderActivatedEventArgs;
struct WebAuthenticationBrokerContinuationEventArgs;

}

namespace Windows::ApplicationModel::Activation {

struct IActivatedEventArgs;
struct IActivatedEventArgsWithUser;
struct IApplicationViewActivatedEventArgs;
struct IAppointmentsProviderActivatedEventArgs;
struct IAppointmentsProviderAddAppointmentActivatedEventArgs;
struct IAppointmentsProviderRemoveAppointmentActivatedEventArgs;
struct IAppointmentsProviderReplaceAppointmentActivatedEventArgs;
struct IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs;
struct IAppointmentsProviderShowTimeFrameActivatedEventArgs;
struct IBackgroundActivatedEventArgs;
struct ICachedFileUpdaterActivatedEventArgs;
struct ICameraSettingsActivatedEventArgs;
struct IContactActivatedEventArgs;
struct IContactCallActivatedEventArgs;
struct IContactMapActivatedEventArgs;
struct IContactMessageActivatedEventArgs;
struct IContactPickerActivatedEventArgs;
struct IContactPostActivatedEventArgs;
struct IContactVideoCallActivatedEventArgs;
struct IContactsProviderActivatedEventArgs;
struct IContinuationActivatedEventArgs;
struct IDeviceActivatedEventArgs;
struct IDevicePairingActivatedEventArgs;
struct IDialReceiverActivatedEventArgs;
struct IFileActivatedEventArgs;
struct IFileActivatedEventArgsWithCallerPackageFamilyName;
struct IFileActivatedEventArgsWithNeighboringFiles;
struct IFileOpenPickerActivatedEventArgs;
struct IFileOpenPickerActivatedEventArgs2;
struct IFileOpenPickerContinuationEventArgs;
struct IFileSavePickerActivatedEventArgs;
struct IFileSavePickerActivatedEventArgs2;
struct IFileSavePickerContinuationEventArgs;
struct IFolderPickerContinuationEventArgs;
struct ILaunchActivatedEventArgs;
struct ILaunchActivatedEventArgs2;
struct ILockScreenActivatedEventArgs;
struct ILockScreenCallActivatedEventArgs;
struct IPickerReturnedActivatedEventArgs;
struct IPrelaunchActivatedEventArgs;
struct IPrint3DWorkflowActivatedEventArgs;
struct IPrintTaskSettingsActivatedEventArgs;
struct IProtocolActivatedEventArgs;
struct IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData;
struct IProtocolForResultsActivatedEventArgs;
struct IRestrictedLaunchActivatedEventArgs;
struct ISearchActivatedEventArgs;
struct ISearchActivatedEventArgsWithLinguisticDetails;
struct IShareTargetActivatedEventArgs;
struct ISplashScreen;
struct ITileActivatedInfo;
struct IToastNotificationActivatedEventArgs;
struct IUserDataAccountProviderActivatedEventArgs;
struct IViewSwitcherProvider;
struct IVoiceCommandActivatedEventArgs;
struct IWalletActionActivatedEventArgs;
struct IWebAccountProviderActivatedEventArgs;
struct IWebAuthenticationBrokerContinuationEventArgs;
struct AppointmentsProviderAddAppointmentActivatedEventArgs;
struct AppointmentsProviderRemoveAppointmentActivatedEventArgs;
struct AppointmentsProviderReplaceAppointmentActivatedEventArgs;
struct AppointmentsProviderShowAppointmentDetailsActivatedEventArgs;
struct AppointmentsProviderShowTimeFrameActivatedEventArgs;
struct BackgroundActivatedEventArgs;
struct CachedFileUpdaterActivatedEventArgs;
struct CameraSettingsActivatedEventArgs;
struct ContactCallActivatedEventArgs;
struct ContactMapActivatedEventArgs;
struct ContactMessageActivatedEventArgs;
struct ContactPickerActivatedEventArgs;
struct ContactPostActivatedEventArgs;
struct ContactVideoCallActivatedEventArgs;
struct DeviceActivatedEventArgs;
struct DevicePairingActivatedEventArgs;
struct DialReceiverActivatedEventArgs;
struct FileActivatedEventArgs;
struct FileOpenPickerActivatedEventArgs;
struct FileOpenPickerContinuationEventArgs;
struct FileSavePickerActivatedEventArgs;
struct FileSavePickerContinuationEventArgs;
struct FolderPickerContinuationEventArgs;
struct LaunchActivatedEventArgs;
struct LockScreenActivatedEventArgs;
struct LockScreenCallActivatedEventArgs;
struct PickerReturnedActivatedEventArgs;
struct Print3DWorkflowActivatedEventArgs;
struct PrintTaskSettingsActivatedEventArgs;
struct ProtocolActivatedEventArgs;
struct ProtocolForResultsActivatedEventArgs;
struct RestrictedLaunchActivatedEventArgs;
struct SearchActivatedEventArgs;
struct ShareTargetActivatedEventArgs;
struct SplashScreen;
struct TileActivatedInfo;
struct ToastNotificationActivatedEventArgs;
struct UserDataAccountProviderActivatedEventArgs;
struct VoiceCommandActivatedEventArgs;
struct WalletActionActivatedEventArgs;
struct WebAccountProviderActivatedEventArgs;
struct WebAuthenticationBrokerContinuationEventArgs;

}

namespace Windows::ApplicationModel::Activation {

template <typename T> struct impl_IActivatedEventArgs;
template <typename T> struct impl_IActivatedEventArgsWithUser;
template <typename T> struct impl_IApplicationViewActivatedEventArgs;
template <typename T> struct impl_IAppointmentsProviderActivatedEventArgs;
template <typename T> struct impl_IAppointmentsProviderAddAppointmentActivatedEventArgs;
template <typename T> struct impl_IAppointmentsProviderRemoveAppointmentActivatedEventArgs;
template <typename T> struct impl_IAppointmentsProviderReplaceAppointmentActivatedEventArgs;
template <typename T> struct impl_IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs;
template <typename T> struct impl_IAppointmentsProviderShowTimeFrameActivatedEventArgs;
template <typename T> struct impl_IBackgroundActivatedEventArgs;
template <typename T> struct impl_ICachedFileUpdaterActivatedEventArgs;
template <typename T> struct impl_ICameraSettingsActivatedEventArgs;
template <typename T> struct impl_IContactActivatedEventArgs;
template <typename T> struct impl_IContactCallActivatedEventArgs;
template <typename T> struct impl_IContactMapActivatedEventArgs;
template <typename T> struct impl_IContactMessageActivatedEventArgs;
template <typename T> struct impl_IContactPickerActivatedEventArgs;
template <typename T> struct impl_IContactPostActivatedEventArgs;
template <typename T> struct impl_IContactVideoCallActivatedEventArgs;
template <typename T> struct impl_IContactsProviderActivatedEventArgs;
template <typename T> struct impl_IContinuationActivatedEventArgs;
template <typename T> struct impl_IDeviceActivatedEventArgs;
template <typename T> struct impl_IDevicePairingActivatedEventArgs;
template <typename T> struct impl_IDialReceiverActivatedEventArgs;
template <typename T> struct impl_IFileActivatedEventArgs;
template <typename T> struct impl_IFileActivatedEventArgsWithCallerPackageFamilyName;
template <typename T> struct impl_IFileActivatedEventArgsWithNeighboringFiles;
template <typename T> struct impl_IFileOpenPickerActivatedEventArgs;
template <typename T> struct impl_IFileOpenPickerActivatedEventArgs2;
template <typename T> struct impl_IFileOpenPickerContinuationEventArgs;
template <typename T> struct impl_IFileSavePickerActivatedEventArgs;
template <typename T> struct impl_IFileSavePickerActivatedEventArgs2;
template <typename T> struct impl_IFileSavePickerContinuationEventArgs;
template <typename T> struct impl_IFolderPickerContinuationEventArgs;
template <typename T> struct impl_ILaunchActivatedEventArgs;
template <typename T> struct impl_ILaunchActivatedEventArgs2;
template <typename T> struct impl_ILockScreenActivatedEventArgs;
template <typename T> struct impl_ILockScreenCallActivatedEventArgs;
template <typename T> struct impl_IPickerReturnedActivatedEventArgs;
template <typename T> struct impl_IPrelaunchActivatedEventArgs;
template <typename T> struct impl_IPrint3DWorkflowActivatedEventArgs;
template <typename T> struct impl_IPrintTaskSettingsActivatedEventArgs;
template <typename T> struct impl_IProtocolActivatedEventArgs;
template <typename T> struct impl_IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData;
template <typename T> struct impl_IProtocolForResultsActivatedEventArgs;
template <typename T> struct impl_IRestrictedLaunchActivatedEventArgs;
template <typename T> struct impl_ISearchActivatedEventArgs;
template <typename T> struct impl_ISearchActivatedEventArgsWithLinguisticDetails;
template <typename T> struct impl_IShareTargetActivatedEventArgs;
template <typename T> struct impl_ISplashScreen;
template <typename T> struct impl_ITileActivatedInfo;
template <typename T> struct impl_IToastNotificationActivatedEventArgs;
template <typename T> struct impl_IUserDataAccountProviderActivatedEventArgs;
template <typename T> struct impl_IViewSwitcherProvider;
template <typename T> struct impl_IVoiceCommandActivatedEventArgs;
template <typename T> struct impl_IWalletActionActivatedEventArgs;
template <typename T> struct impl_IWebAccountProviderActivatedEventArgs;
template <typename T> struct impl_IWebAuthenticationBrokerContinuationEventArgs;

}

namespace Windows::ApplicationModel::Activation {

enum class ActivationKind
{
    Launch = 0,
    Search = 1,
    ShareTarget = 2,
    File = 3,
    Protocol = 4,
    FileOpenPicker = 5,
    FileSavePicker = 6,
    CachedFileUpdater = 7,
    ContactPicker = 8,
    Device = 9,
    PrintTaskSettings = 10,
    CameraSettings = 11,
    RestrictedLaunch = 12,
    AppointmentsProvider = 13,
    Contact = 14,
    LockScreenCall = 15,
    VoiceCommand = 16,
    LockScreen = 17,
    PickerReturned = 1000,
    WalletAction = 1001,
    PickFileContinuation = 1002,
    PickSaveFileContinuation = 1003,
    PickFolderContinuation = 1004,
    WebAuthenticationBrokerContinuation = 1005,
    WebAccountProvider = 1006,
    ComponentUI = 1007,
    ProtocolForResults = 1009,
    ToastNotification = 1010,
    Print3DWorkflow = 1011,
    DialReceiver = 1012,
    DevicePairing = 1013,
    UserDataAccountsProvider = 1014,
    FilePickerExperience = 1015,
};

enum class ApplicationExecutionState
{
    NotRunning = 0,
    Running = 1,
    Suspended = 2,
    Terminated = 3,
    ClosedByUser = 4,
};

}

}
