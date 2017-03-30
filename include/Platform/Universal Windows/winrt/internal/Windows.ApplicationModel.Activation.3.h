// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Activation.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::Activation {

struct WINRT_EBO AppointmentsProviderAddAppointmentActivatedEventArgs :
    Windows::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs,
    impl::require<AppointmentsProviderAddAppointmentActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    AppointmentsProviderAddAppointmentActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppointmentsProviderRemoveAppointmentActivatedEventArgs :
    Windows::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs,
    impl::require<AppointmentsProviderRemoveAppointmentActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    AppointmentsProviderRemoveAppointmentActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppointmentsProviderReplaceAppointmentActivatedEventArgs :
    Windows::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs,
    impl::require<AppointmentsProviderReplaceAppointmentActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    AppointmentsProviderReplaceAppointmentActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppointmentsProviderShowAppointmentDetailsActivatedEventArgs :
    Windows::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs,
    impl::require<AppointmentsProviderShowAppointmentDetailsActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    AppointmentsProviderShowAppointmentDetailsActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppointmentsProviderShowTimeFrameActivatedEventArgs :
    Windows::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs,
    impl::require<AppointmentsProviderShowTimeFrameActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    AppointmentsProviderShowTimeFrameActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BackgroundActivatedEventArgs :
    Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs
{
    BackgroundActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CachedFileUpdaterActivatedEventArgs :
    Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs,
    impl::require<CachedFileUpdaterActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    CachedFileUpdaterActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CameraSettingsActivatedEventArgs :
    Windows::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs
{
    CameraSettingsActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactCallActivatedEventArgs :
    Windows::ApplicationModel::Activation::IContactCallActivatedEventArgs
{
    ContactCallActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactMapActivatedEventArgs :
    Windows::ApplicationModel::Activation::IContactMapActivatedEventArgs
{
    ContactMapActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactMessageActivatedEventArgs :
    Windows::ApplicationModel::Activation::IContactMessageActivatedEventArgs
{
    ContactMessageActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactPickerActivatedEventArgs :
    Windows::ApplicationModel::Activation::IContactPickerActivatedEventArgs
{
    ContactPickerActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactPostActivatedEventArgs :
    Windows::ApplicationModel::Activation::IContactPostActivatedEventArgs
{
    ContactPostActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ContactVideoCallActivatedEventArgs :
    Windows::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs
{
    ContactVideoCallActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DeviceActivatedEventArgs :
    Windows::ApplicationModel::Activation::IDeviceActivatedEventArgs,
    impl::require<DeviceActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser, Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, Windows::ApplicationModel::Activation::IViewSwitcherProvider>
{
    DeviceActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DevicePairingActivatedEventArgs :
    Windows::ApplicationModel::Activation::IDevicePairingActivatedEventArgs,
    impl::require<DevicePairingActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    DevicePairingActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DialReceiverActivatedEventArgs :
    Windows::ApplicationModel::Activation::IDialReceiverActivatedEventArgs,
    impl::require<DialReceiverActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser, Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, Windows::ApplicationModel::Activation::IViewSwitcherProvider>
{
    DialReceiverActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FileActivatedEventArgs :
    Windows::ApplicationModel::Activation::IFileActivatedEventArgs,
    impl::require<FileActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser, Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, Windows::ApplicationModel::Activation::IViewSwitcherProvider, Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithNeighboringFiles, Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithCallerPackageFamilyName>
{
    FileActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FileOpenPickerActivatedEventArgs :
    Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs,
    impl::require<FileOpenPickerActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser, Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs2>
{
    FileOpenPickerActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FileOpenPickerContinuationEventArgs :
    Windows::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs,
    impl::require<FileOpenPickerContinuationEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    FileOpenPickerContinuationEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FileSavePickerActivatedEventArgs :
    Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs,
    impl::require<FileSavePickerActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser, Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs2>
{
    FileSavePickerActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FileSavePickerContinuationEventArgs :
    Windows::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs,
    impl::require<FileSavePickerContinuationEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    FileSavePickerContinuationEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FolderPickerContinuationEventArgs :
    Windows::ApplicationModel::Activation::IFolderPickerContinuationEventArgs,
    impl::require<FolderPickerContinuationEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    FolderPickerContinuationEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LaunchActivatedEventArgs :
    Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs,
    impl::require<LaunchActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser, Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, Windows::ApplicationModel::Activation::IViewSwitcherProvider, Windows::ApplicationModel::Activation::IPrelaunchActivatedEventArgs, Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs2>
{
    LaunchActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LockScreenActivatedEventArgs :
    Windows::ApplicationModel::Activation::ILockScreenActivatedEventArgs,
    impl::require<LockScreenActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    LockScreenActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO LockScreenCallActivatedEventArgs :
    Windows::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs,
    impl::require<LockScreenCallActivatedEventArgs, Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, Windows::ApplicationModel::Activation::IViewSwitcherProvider>
{
    LockScreenCallActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PickerReturnedActivatedEventArgs :
    Windows::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs
{
    PickerReturnedActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Print3DWorkflowActivatedEventArgs :
    Windows::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs
{
    Print3DWorkflowActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PrintTaskSettingsActivatedEventArgs :
    Windows::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs
{
    PrintTaskSettingsActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ProtocolActivatedEventArgs :
    Windows::ApplicationModel::Activation::IProtocolActivatedEventArgs,
    impl::require<ProtocolActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser, Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, Windows::ApplicationModel::Activation::IViewSwitcherProvider, Windows::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData>
{
    ProtocolActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ProtocolForResultsActivatedEventArgs :
    Windows::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs,
    impl::require<ProtocolForResultsActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser, Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, Windows::ApplicationModel::Activation::IViewSwitcherProvider, Windows::ApplicationModel::Activation::IProtocolActivatedEventArgs, Windows::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData>
{
    ProtocolForResultsActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RestrictedLaunchActivatedEventArgs :
    Windows::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs,
    impl::require<RestrictedLaunchActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    RestrictedLaunchActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SearchActivatedEventArgs :
    Windows::ApplicationModel::Activation::ISearchActivatedEventArgs,
    impl::require<SearchActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser, Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, Windows::ApplicationModel::Activation::IViewSwitcherProvider, Windows::ApplicationModel::Activation::ISearchActivatedEventArgsWithLinguisticDetails>
{
    SearchActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ShareTargetActivatedEventArgs :
    Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs,
    impl::require<ShareTargetActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    ShareTargetActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SplashScreen :
    Windows::ApplicationModel::Activation::ISplashScreen
{
    SplashScreen(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TileActivatedInfo :
    Windows::ApplicationModel::Activation::ITileActivatedInfo
{
    TileActivatedInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ToastNotificationActivatedEventArgs :
    Windows::ApplicationModel::Activation::IToastNotificationActivatedEventArgs,
    impl::require<ToastNotificationActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    ToastNotificationActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UserDataAccountProviderActivatedEventArgs :
    Windows::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs
{
    UserDataAccountProviderActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VoiceCommandActivatedEventArgs :
    Windows::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs,
    impl::require<VoiceCommandActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    VoiceCommandActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WalletActionActivatedEventArgs :
    Windows::ApplicationModel::Activation::IWalletActionActivatedEventArgs
{
    WalletActionActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebAccountProviderActivatedEventArgs :
    Windows::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs,
    impl::require<WebAccountProviderActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    WebAccountProviderActivatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO WebAuthenticationBrokerContinuationEventArgs :
    Windows::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs
{
    WebAuthenticationBrokerContinuationEventArgs(std::nullptr_t) noexcept {}
};

}

}
