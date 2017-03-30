// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Activation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5541d8a7_497c_5aa4_86fc_7713adbf2a2c
#define WINRT_GENERIC_5541d8a7_497c_5aa4_86fc_7713adbf2a2c
template <> struct __declspec(uuid("5541d8a7-497c-5aa4-86fc-7713adbf2a2c")) __declspec(novtable) IReference<Windows::Foundation::DateTime> : impl_IReference<Windows::Foundation::DateTime> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_85575a41_06cb_58d0_b98a_7c8f06e6e9d7
#define WINRT_GENERIC_85575a41_06cb_58d0_b98a_7c8f06e6e9d7
template <> struct __declspec(uuid("85575a41-06cb-58d0-b98a-7c8f06e6e9d7")) __declspec(novtable) IVectorView<Windows::Storage::IStorageItem> : impl_IVectorView<Windows::Storage::IStorageItem> {};
#endif

#ifndef WINRT_GENERIC_bb8b8418_65d1_544b_b083_6d172f568c73
#define WINRT_GENERIC_bb8b8418_65d1_544b_b083_6d172f568c73
template <> struct __declspec(uuid("bb8b8418-65d1-544b-b083-6d172f568c73")) __declspec(novtable) IIterable<Windows::Storage::IStorageItem> : impl_IIterable<Windows::Storage::IStorageItem> {};
#endif

#ifndef WINRT_GENERIC_80646519_5e2a_595d_a8cd_2a24b4067f1b
#define WINRT_GENERIC_80646519_5e2a_595d_a8cd_2a24b4067f1b
template <> struct __declspec(uuid("80646519-5e2a-595d-a8cd-2a24b4067f1b")) __declspec(novtable) IVectorView<Windows::Storage::StorageFile> : impl_IVectorView<Windows::Storage::StorageFile> {};
#endif

#ifndef WINRT_GENERIC_9ac00304_83ea_5688_87b6_ae38aab65d0b
#define WINRT_GENERIC_9ac00304_83ea_5688_87b6_ae38aab65d0b
template <> struct __declspec(uuid("9ac00304-83ea-5688-87b6-ae38aab65d0b")) __declspec(novtable) IIterable<Windows::Storage::StorageFile> : impl_IIterable<Windows::Storage::StorageFile> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_7725b2a5_287d_5ed2_a789_2a6a2673c7fe
#define WINRT_GENERIC_7725b2a5_287d_5ed2_a789_2a6a2673c7fe
template <> struct __declspec(uuid("7725b2a5-287d-5ed2-a789-2a6a2673c7fe")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Activation::SplashScreen, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::ApplicationModel::Activation::SplashScreen, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2b23baa9_1d54_5440_bd32_86ed70f15c9e
#define WINRT_GENERIC_2b23baa9_1d54_5440_bd32_86ed70f15c9e
template <> struct __declspec(uuid("2b23baa9-1d54-5440-bd32-86ed70f15c9e")) __declspec(novtable) IVectorView<Windows::UI::Notifications::ShownTileNotification> : impl_IVectorView<Windows::UI::Notifications::ShownTileNotification> {};
#endif

#ifndef WINRT_GENERIC_05b487c2_3830_5d3c_98da_25fa11542dbd
#define WINRT_GENERIC_05b487c2_3830_5d3c_98da_25fa11542dbd
template <> struct __declspec(uuid("05b487c2-3830-5d3c-98da-25fa11542dbd")) __declspec(novtable) IIterator<Windows::Storage::IStorageItem> : impl_IIterator<Windows::Storage::IStorageItem> {};
#endif

#ifndef WINRT_GENERIC_43e29f53_0298_55aa_a6c8_4edd323d9598
#define WINRT_GENERIC_43e29f53_0298_55aa_a6c8_4edd323d9598
template <> struct __declspec(uuid("43e29f53-0298-55aa-a6c8-4edd323d9598")) __declspec(novtable) IIterator<Windows::Storage::StorageFile> : impl_IIterator<Windows::Storage::StorageFile> {};
#endif

#ifndef WINRT_GENERIC_04d8d70b_7c15_5f60_9894_b21366b427c2
#define WINRT_GENERIC_04d8d70b_7c15_5f60_9894_b21366b427c2
template <> struct __declspec(uuid("04d8d70b-7c15-5f60-9894-b21366b427c2")) __declspec(novtable) IIterator<Windows::UI::Notifications::ShownTileNotification> : impl_IIterator<Windows::UI::Notifications::ShownTileNotification> {};
#endif

#ifndef WINRT_GENERIC_1863baee_44f1_5e51_bcdf_a3cdab826a15
#define WINRT_GENERIC_1863baee_44f1_5e51_bcdf_a3cdab826a15
template <> struct __declspec(uuid("1863baee-44f1-5e51-bcdf-a3cdab826a15")) __declspec(novtable) IIterable<Windows::UI::Notifications::ShownTileNotification> : impl_IIterable<Windows::UI::Notifications::ShownTileNotification> {};
#endif


}

namespace Windows::ApplicationModel::Activation {

struct IActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IActivatedEventArgs>
{
    IActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IActivatedEventArgsWithUser :
    Windows::Foundation::IInspectable,
    impl::consume<IActivatedEventArgsWithUser>,
    impl::require<IActivatedEventArgsWithUser, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IActivatedEventArgsWithUser(std::nullptr_t = nullptr) noexcept {}
};

struct IApplicationViewActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IApplicationViewActivatedEventArgs>,
    impl::require<IApplicationViewActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IApplicationViewActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentsProviderActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentsProviderActivatedEventArgs>,
    impl::require<IAppointmentsProviderActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IAppointmentsProviderActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentsProviderAddAppointmentActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentsProviderAddAppointmentActivatedEventArgs>,
    impl::require<IAppointmentsProviderAddAppointmentActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>
{
    IAppointmentsProviderAddAppointmentActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentsProviderRemoveAppointmentActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentsProviderRemoveAppointmentActivatedEventArgs>,
    impl::require<IAppointmentsProviderRemoveAppointmentActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>
{
    IAppointmentsProviderRemoveAppointmentActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentsProviderReplaceAppointmentActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentsProviderReplaceAppointmentActivatedEventArgs>,
    impl::require<IAppointmentsProviderReplaceAppointmentActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>
{
    IAppointmentsProviderReplaceAppointmentActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs>,
    impl::require<IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>
{
    IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentsProviderShowTimeFrameActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentsProviderShowTimeFrameActivatedEventArgs>,
    impl::require<IAppointmentsProviderShowTimeFrameActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>
{
    IAppointmentsProviderShowTimeFrameActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IBackgroundActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IBackgroundActivatedEventArgs>
{
    IBackgroundActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ICachedFileUpdaterActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ICachedFileUpdaterActivatedEventArgs>,
    impl::require<ICachedFileUpdaterActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    ICachedFileUpdaterActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ICameraSettingsActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ICameraSettingsActivatedEventArgs>,
    impl::require<ICameraSettingsActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    ICameraSettingsActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IContactActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IContactActivatedEventArgs>,
    impl::require<IContactActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IContactActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IContactCallActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IContactCallActivatedEventArgs>,
    impl::require<IContactCallActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::IContactActivatedEventArgs>
{
    IContactCallActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IContactMapActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IContactMapActivatedEventArgs>,
    impl::require<IContactMapActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::IContactActivatedEventArgs>
{
    IContactMapActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IContactMessageActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IContactMessageActivatedEventArgs>,
    impl::require<IContactMessageActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::IContactActivatedEventArgs>
{
    IContactMessageActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IContactPickerActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IContactPickerActivatedEventArgs>,
    impl::require<IContactPickerActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IContactPickerActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IContactPostActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IContactPostActivatedEventArgs>,
    impl::require<IContactPostActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::IContactActivatedEventArgs>
{
    IContactPostActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IContactVideoCallActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IContactVideoCallActivatedEventArgs>,
    impl::require<IContactVideoCallActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::IContactActivatedEventArgs>
{
    IContactVideoCallActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IContactsProviderActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IContactsProviderActivatedEventArgs>,
    impl::require<IContactsProviderActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IContactsProviderActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IContinuationActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IContinuationActivatedEventArgs>,
    impl::require<IContinuationActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IContinuationActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceActivatedEventArgs>,
    impl::require<IDeviceActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IDeviceActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IDevicePairingActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IDevicePairingActivatedEventArgs>,
    impl::require<IDevicePairingActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IDevicePairingActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IDialReceiverActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IDialReceiverActivatedEventArgs>,
    impl::require<IDialReceiverActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs>
{
    IDialReceiverActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IFileActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IFileActivatedEventArgs>,
    impl::require<IFileActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IFileActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IFileActivatedEventArgsWithCallerPackageFamilyName :
    Windows::Foundation::IInspectable,
    impl::consume<IFileActivatedEventArgsWithCallerPackageFamilyName>,
    impl::require<IFileActivatedEventArgsWithCallerPackageFamilyName, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IFileActivatedEventArgsWithCallerPackageFamilyName(std::nullptr_t = nullptr) noexcept {}
};

struct IFileActivatedEventArgsWithNeighboringFiles :
    Windows::Foundation::IInspectable,
    impl::consume<IFileActivatedEventArgsWithNeighboringFiles>,
    impl::require<IFileActivatedEventArgsWithNeighboringFiles, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::IFileActivatedEventArgs>
{
    IFileActivatedEventArgsWithNeighboringFiles(std::nullptr_t = nullptr) noexcept {}
};

struct IFileOpenPickerActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IFileOpenPickerActivatedEventArgs>,
    impl::require<IFileOpenPickerActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IFileOpenPickerActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IFileOpenPickerActivatedEventArgs2 :
    Windows::Foundation::IInspectable,
    impl::consume<IFileOpenPickerActivatedEventArgs2>
{
    IFileOpenPickerActivatedEventArgs2(std::nullptr_t = nullptr) noexcept {}
};

struct IFileOpenPickerContinuationEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IFileOpenPickerContinuationEventArgs>,
    impl::require<IFileOpenPickerContinuationEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::IContinuationActivatedEventArgs>
{
    IFileOpenPickerContinuationEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IFileSavePickerActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IFileSavePickerActivatedEventArgs>,
    impl::require<IFileSavePickerActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IFileSavePickerActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IFileSavePickerActivatedEventArgs2 :
    Windows::Foundation::IInspectable,
    impl::consume<IFileSavePickerActivatedEventArgs2>
{
    IFileSavePickerActivatedEventArgs2(std::nullptr_t = nullptr) noexcept {}
};

struct IFileSavePickerContinuationEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IFileSavePickerContinuationEventArgs>,
    impl::require<IFileSavePickerContinuationEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::IContinuationActivatedEventArgs>
{
    IFileSavePickerContinuationEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IFolderPickerContinuationEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IFolderPickerContinuationEventArgs>,
    impl::require<IFolderPickerContinuationEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::IContinuationActivatedEventArgs>
{
    IFolderPickerContinuationEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ILaunchActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ILaunchActivatedEventArgs>,
    impl::require<ILaunchActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    ILaunchActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ILaunchActivatedEventArgs2 :
    Windows::Foundation::IInspectable,
    impl::consume<ILaunchActivatedEventArgs2>,
    impl::require<ILaunchActivatedEventArgs2, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs>
{
    ILaunchActivatedEventArgs2(std::nullptr_t = nullptr) noexcept {}
};

struct ILockScreenActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ILockScreenActivatedEventArgs>,
    impl::require<ILockScreenActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    ILockScreenActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ILockScreenCallActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ILockScreenCallActivatedEventArgs>,
    impl::require<ILockScreenCallActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs>
{
    ILockScreenCallActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPickerReturnedActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPickerReturnedActivatedEventArgs>,
    impl::require<IPickerReturnedActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IPickerReturnedActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPrelaunchActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPrelaunchActivatedEventArgs>,
    impl::require<IPrelaunchActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IPrelaunchActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPrint3DWorkflowActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPrint3DWorkflowActivatedEventArgs>,
    impl::require<IPrint3DWorkflowActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IPrint3DWorkflowActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskSettingsActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskSettingsActivatedEventArgs>,
    impl::require<IPrintTaskSettingsActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IPrintTaskSettingsActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IProtocolActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IProtocolActivatedEventArgs>,
    impl::require<IProtocolActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IProtocolActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData :
    Windows::Foundation::IInspectable,
    impl::consume<IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData>,
    impl::require<IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData(std::nullptr_t = nullptr) noexcept {}
};

struct IProtocolForResultsActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IProtocolForResultsActivatedEventArgs>,
    impl::require<IProtocolForResultsActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IProtocolForResultsActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IRestrictedLaunchActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IRestrictedLaunchActivatedEventArgs>,
    impl::require<IRestrictedLaunchActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IRestrictedLaunchActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISearchActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ISearchActivatedEventArgs>,
    impl::require<ISearchActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    ISearchActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISearchActivatedEventArgsWithLinguisticDetails :
    Windows::Foundation::IInspectable,
    impl::consume<ISearchActivatedEventArgsWithLinguisticDetails>
{
    ISearchActivatedEventArgsWithLinguisticDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IShareTargetActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IShareTargetActivatedEventArgs>,
    impl::require<IShareTargetActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IShareTargetActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISplashScreen :
    Windows::Foundation::IInspectable,
    impl::consume<ISplashScreen>
{
    ISplashScreen(std::nullptr_t = nullptr) noexcept {}
};

struct ITileActivatedInfo :
    Windows::Foundation::IInspectable,
    impl::consume<ITileActivatedInfo>
{
    ITileActivatedInfo(std::nullptr_t = nullptr) noexcept {}
};

struct IToastNotificationActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IToastNotificationActivatedEventArgs>,
    impl::require<IToastNotificationActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IToastNotificationActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IUserDataAccountProviderActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IUserDataAccountProviderActivatedEventArgs>,
    impl::require<IUserDataAccountProviderActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IUserDataAccountProviderActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IViewSwitcherProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IViewSwitcherProvider>,
    impl::require<IViewSwitcherProvider, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IViewSwitcherProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IVoiceCommandActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IVoiceCommandActivatedEventArgs>,
    impl::require<IVoiceCommandActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IVoiceCommandActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IWalletActionActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IWalletActionActivatedEventArgs>,
    impl::require<IWalletActionActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IWalletActionActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IWebAccountProviderActivatedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IWebAccountProviderActivatedEventArgs>,
    impl::require<IWebAccountProviderActivatedEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    IWebAccountProviderActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IWebAuthenticationBrokerContinuationEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IWebAuthenticationBrokerContinuationEventArgs>,
    impl::require<IWebAuthenticationBrokerContinuationEventArgs, Windows::ApplicationModel::Activation::IActivatedEventArgs, Windows::ApplicationModel::Activation::IContinuationActivatedEventArgs>
{
    IWebAuthenticationBrokerContinuationEventArgs(std::nullptr_t = nullptr) noexcept {}
};

}

}
