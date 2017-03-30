// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Activation.0.h"
#include "Windows.ApplicationModel.Appointments.AppointmentsProvider.0.h"
#include "Windows.ApplicationModel.Background.0.h"
#include "Windows.ApplicationModel.Calls.0.h"
#include "Windows.ApplicationModel.Contacts.0.h"
#include "Windows.ApplicationModel.Contacts.Provider.0.h"
#include "Windows.ApplicationModel.DataTransfer.ShareTarget.0.h"
#include "Windows.ApplicationModel.Search.0.h"
#include "Windows.ApplicationModel.UserDataAccounts.Provider.0.h"
#include "Windows.ApplicationModel.Wallet.0.h"
#include "Windows.Devices.Enumeration.0.h"
#include "Windows.Devices.Printers.Extensions.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.0.h"
#include "Windows.Media.SpeechRecognition.0.h"
#include "Windows.Security.Authentication.Web.0.h"
#include "Windows.Security.Authentication.Web.Provider.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Storage.Pickers.Provider.0.h"
#include "Windows.Storage.Provider.0.h"
#include "Windows.Storage.Search.0.h"
#include "Windows.System.0.h"
#include "Windows.UI.ViewManagement.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Storage.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.UI.Notifications.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Activation {

struct __declspec(uuid("cf651713-cd08-4fd8-b697-a281b6544e2e")) __declspec(novtable) IActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Kind(winrt::Windows::ApplicationModel::Activation::ActivationKind * value) = 0;
    virtual HRESULT __stdcall get_PreviousExecutionState(winrt::Windows::ApplicationModel::Activation::ApplicationExecutionState * value) = 0;
    virtual HRESULT __stdcall get_SplashScreen(Windows::ApplicationModel::Activation::ISplashScreen ** value) = 0;
};

struct __declspec(uuid("1cf09b9e-9962-4936-80ff-afc8e8ae5c8c")) __declspec(novtable) IActivatedEventArgsWithUser : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_User(Windows::System::IUser ** value) = 0;
};

struct __declspec(uuid("930cef4b-b829-40fc-88f4-8513e8a64738")) __declspec(novtable) IApplicationViewActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CurrentlyShownApplicationViewId(int32_t * value) = 0;
};

struct __declspec(uuid("3364c405-933c-4e7d-a034-500fb8dcd9f3")) __declspec(novtable) IAppointmentsProviderActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Verb(hstring * value) = 0;
};

struct __declspec(uuid("a2861367-cee5-4e4d-9ed7-41c34ec18b02")) __declspec(novtable) IAppointmentsProviderAddAppointmentActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AddAppointmentOperation(Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation ** value) = 0;
};

struct __declspec(uuid("751f3ab8-0b8e-451c-9f15-966e699bac25")) __declspec(novtable) IAppointmentsProviderRemoveAppointmentActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RemoveAppointmentOperation(Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation ** value) = 0;
};

struct __declspec(uuid("1551b7d4-a981-4067-8a62-0524e4ade121")) __declspec(novtable) IAppointmentsProviderReplaceAppointmentActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ReplaceAppointmentOperation(Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation ** value) = 0;
};

struct __declspec(uuid("3958f065-9841-4ca5-999b-885198b9ef2a")) __declspec(novtable) IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InstanceStartDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_LocalId(hstring * value) = 0;
    virtual HRESULT __stdcall get_RoamingId(hstring * value) = 0;
};

struct __declspec(uuid("9baeaba6-0e0b-49aa-babc-12b1dc774986")) __declspec(novtable) IAppointmentsProviderShowTimeFrameActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TimeToShow(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_Duration(Windows::Foundation::TimeSpan * value) = 0;
};

struct __declspec(uuid("ab14bee0-e760-440e-a91c-44796de3a92d")) __declspec(novtable) IBackgroundActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TaskInstance(Windows::ApplicationModel::Background::IBackgroundTaskInstance ** value) = 0;
};

struct __declspec(uuid("d06eb1c7-3805-4ecb-b757-6cf15e26fef3")) __declspec(novtable) ICachedFileUpdaterActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CachedFileUpdaterUI(Windows::Storage::Provider::ICachedFileUpdaterUI ** value) = 0;
};

struct __declspec(uuid("fb67a508-2dad-490a-9170-dca036eb114b")) __declspec(novtable) ICameraSettingsActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_VideoDeviceController(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_VideoDeviceExtension(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("d627a1c4-c025-4c41-9def-f1eafad075e7")) __declspec(novtable) IContactActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Verb(hstring * value) = 0;
};

struct __declspec(uuid("c2df14c7-30eb-41c6-b3bc-5b1694f9dab3")) __declspec(novtable) IContactCallActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServiceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_ServiceUserId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Contact(Windows::ApplicationModel::Contacts::IContact ** value) = 0;
};

struct __declspec(uuid("b32bf870-eee7-4ad2-aaf1-a87effcf00a4")) __declspec(novtable) IContactMapActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Address(Windows::ApplicationModel::Contacts::IContactAddress ** value) = 0;
    virtual HRESULT __stdcall get_Contact(Windows::ApplicationModel::Contacts::IContact ** value) = 0;
};

struct __declspec(uuid("de598db2-0e03-43b0-bf56-bcc40b3162df")) __declspec(novtable) IContactMessageActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServiceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_ServiceUserId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Contact(Windows::ApplicationModel::Contacts::IContact ** value) = 0;
};

struct __declspec(uuid("ce57aae7-6449-45a7-971f-d113be7a8936")) __declspec(novtable) IContactPickerActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContactPickerUI(Windows::ApplicationModel::Contacts::Provider::IContactPickerUI ** value) = 0;
};

struct __declspec(uuid("b35a3c67-f1e7-4655-ad6e-4857588f552f")) __declspec(novtable) IContactPostActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServiceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_ServiceUserId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Contact(Windows::ApplicationModel::Contacts::IContact ** value) = 0;
};

struct __declspec(uuid("61079db8-e3e7-4b4f-858d-5c63a96ef684")) __declspec(novtable) IContactVideoCallActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ServiceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_ServiceUserId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Contact(Windows::ApplicationModel::Contacts::IContact ** value) = 0;
};

struct __declspec(uuid("4580dca8-5750-4916-aa52-c0829521eb94")) __declspec(novtable) IContactsProviderActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Verb(hstring * value) = 0;
};

struct __declspec(uuid("e58106b5-155f-4a94-a742-c7e08f4e188c")) __declspec(novtable) IContinuationActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContinuationData(Windows::Foundation::Collections::IPropertySet ** value) = 0;
};

struct __declspec(uuid("cd50b9a9-ce10-44d2-8234-c355a073ef33")) __declspec(novtable) IDeviceActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceInformationId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Verb(hstring * value) = 0;
};

struct __declspec(uuid("eba0d1e4-ecc6-4148-94ed-f4b37ec05b3e")) __declspec(novtable) IDevicePairingActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DeviceInformation(Windows::Devices::Enumeration::IDeviceInformation ** value) = 0;
};

struct __declspec(uuid("fb777ed7-85ee-456e-a44d-85d730e70aed")) __declspec(novtable) IDialReceiverActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppName(hstring * value) = 0;
};

struct __declspec(uuid("bb2afc33-93b1-42ed-8b26-236dd9c78496")) __declspec(novtable) IFileActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Files(Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem> ** value) = 0;
    virtual HRESULT __stdcall get_Verb(hstring * value) = 0;
};

struct __declspec(uuid("2d60f06b-d25f-4d25-8653-e1c5e1108309")) __declspec(novtable) IFileActivatedEventArgsWithCallerPackageFamilyName : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CallerPackageFamilyName(hstring * value) = 0;
};

struct __declspec(uuid("433ba1a4-e1e2-48fd-b7fc-b5d6eee65033")) __declspec(novtable) IFileActivatedEventArgsWithNeighboringFiles : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NeighboringFilesQuery(Windows::Storage::Search::IStorageFileQueryResult ** value) = 0;
};

struct __declspec(uuid("72827082-5525-4bf2-bc09-1f5095d4964d")) __declspec(novtable) IFileOpenPickerActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FileOpenPickerUI(Windows::Storage::Pickers::Provider::IFileOpenPickerUI ** value) = 0;
};

struct __declspec(uuid("5e731f66-8d1f-45fb-af1d-73205c8fc7a1")) __declspec(novtable) IFileOpenPickerActivatedEventArgs2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CallerPackageFamilyName(hstring * value) = 0;
};

struct __declspec(uuid("f0fa3f3a-d4e8-4ad3-9c34-2308f32fcec9")) __declspec(novtable) IFileOpenPickerContinuationEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Files(Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile> ** value) = 0;
};

struct __declspec(uuid("81c19cf1-74e6-4387-82eb-bb8fd64b4346")) __declspec(novtable) IFileSavePickerActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FileSavePickerUI(Windows::Storage::Pickers::Provider::IFileSavePickerUI ** value) = 0;
};

struct __declspec(uuid("6b73fe13-2cf2-4d48-8cbc-af67d23f1ce7")) __declspec(novtable) IFileSavePickerActivatedEventArgs2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CallerPackageFamilyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_EnterpriseId(hstring * value) = 0;
};

struct __declspec(uuid("2c846fe1-3bad-4f33-8c8b-e46fae824b4b")) __declspec(novtable) IFileSavePickerContinuationEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_File(Windows::Storage::IStorageFile ** value) = 0;
};

struct __declspec(uuid("51882366-9f4b-498f-beb0-42684f6e1c29")) __declspec(novtable) IFolderPickerContinuationEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Folder(Windows::Storage::IStorageFolder ** value) = 0;
};

struct __declspec(uuid("fbc93e26-a14a-4b4f-82b0-33bed920af52")) __declspec(novtable) ILaunchActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Arguments(hstring * value) = 0;
    virtual HRESULT __stdcall get_TileId(hstring * value) = 0;
};

struct __declspec(uuid("0fd37ebc-9dc9-46b5-9ace-bd95d4565345")) __declspec(novtable) ILaunchActivatedEventArgs2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TileActivatedInfo(Windows::ApplicationModel::Activation::ITileActivatedInfo ** value) = 0;
};

struct __declspec(uuid("3ca77966-6108-4a41-8220-ee7d133c8532")) __declspec(novtable) ILockScreenActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Info(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("06f37fbe-b5f2-448b-b13e-e328ac1c516a")) __declspec(novtable) ILockScreenCallActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CallUI(Windows::ApplicationModel::Calls::ILockScreenCallUI ** value) = 0;
};

struct __declspec(uuid("360defb9-a9d3-4984-a4ed-9ec734604921")) __declspec(novtable) IPickerReturnedActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PickerOperationId(hstring * value) = 0;
};

struct __declspec(uuid("0c44717b-19f7-48d6-b046-cf22826eaa74")) __declspec(novtable) IPrelaunchActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PrelaunchActivated(bool * value) = 0;
};

struct __declspec(uuid("3f57e78b-f2ac-4619-8302-ef855e1c9b90")) __declspec(novtable) IPrint3DWorkflowActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Workflow(Windows::Devices::Printers::Extensions::IPrint3DWorkflow ** value) = 0;
};

struct __declspec(uuid("ee30a0c9-ce56-4865-ba8e-8954ac271107")) __declspec(novtable) IPrintTaskSettingsActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Configuration(Windows::Devices::Printers::Extensions::IPrintTaskConfiguration ** value) = 0;
};

struct __declspec(uuid("6095f4dd-b7c0-46ab-81fe-d90f36d00d24")) __declspec(novtable) IProtocolActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Uri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
};

struct __declspec(uuid("d84a0c12-5c8f-438c-83cb-c28fcc0b2fdb")) __declspec(novtable) IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CallerPackageFamilyName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Data(Windows::Foundation::Collections::IPropertySet ** value) = 0;
};

struct __declspec(uuid("e75132c2-7ae7-4517-80ac-dbe8d7cc5b9c")) __declspec(novtable) IProtocolForResultsActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ProtocolForResultsOperation(Windows::System::IProtocolForResultsOperation ** value) = 0;
};

struct __declspec(uuid("e0b7ac81-bfc3-4344-a5da-19fd5a27baae")) __declspec(novtable) IRestrictedLaunchActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SharedContext(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("8cb36951-58c8-43e3-94bc-41d33f8b630e")) __declspec(novtable) ISearchActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_QueryText(hstring * value) = 0;
    virtual HRESULT __stdcall get_Language(hstring * value) = 0;
};

struct __declspec(uuid("c09f33da-08ab-4931-9b7c-451025f21f81")) __declspec(novtable) ISearchActivatedEventArgsWithLinguisticDetails : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_LinguisticDetails(Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails ** value) = 0;
};

struct __declspec(uuid("4bdaf9c8-cdb2-4acb-bfc3-6648563378ec")) __declspec(novtable) IShareTargetActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ShareOperation(Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation ** value) = 0;
};

struct __declspec(uuid("ca4d975c-d4d6-43f0-97c0-0833c6391c24")) __declspec(novtable) ISplashScreen : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ImageLocation(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall add_Dismissed(Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Activation::SplashScreen, Windows::Foundation::IInspectable> * handler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_Dismissed(event_token cookie) = 0;
};

struct __declspec(uuid("80e4a3b1-3980-4f17-b738-89194e0b8f65")) __declspec(novtable) ITileActivatedInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RecentlyShownNotifications(Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ShownTileNotification> ** value) = 0;
};

struct __declspec(uuid("92a86f82-5290-431d-be85-c4aaeeb8685f")) __declspec(novtable) IToastNotificationActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Argument(hstring * argument) = 0;
    virtual HRESULT __stdcall get_UserInput(Windows::Foundation::Collections::IPropertySet ** value) = 0;
};

struct __declspec(uuid("1bc9f723-8ef1-4a51-a63a-fe711eeab607")) __declspec(novtable) IUserDataAccountProviderActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Operation(Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation ** value) = 0;
};

struct __declspec(uuid("33f288a6-5c2c-4d27-bac7-7536088f1219")) __declspec(novtable) IViewSwitcherProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ViewSwitcher(Windows::UI::ViewManagement::IActivationViewSwitcher ** value) = 0;
};

struct __declspec(uuid("ab92dcfd-8d43-4de6-9775-20704b581b00")) __declspec(novtable) IVoiceCommandActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Result(Windows::Media::SpeechRecognition::ISpeechRecognitionResult ** value) = 0;
};

struct __declspec(uuid("fcfc027b-1a1a-4d22-923f-ae6f45fa52d9")) __declspec(novtable) IWalletActionActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ItemId(hstring * value) = 0;
    virtual HRESULT __stdcall get_ActionKind(winrt::Windows::ApplicationModel::Wallet::WalletActionKind * value) = 0;
    virtual HRESULT __stdcall get_ActionId(hstring * value) = 0;
};

struct __declspec(uuid("72b71774-98ea-4ccf-9752-46d9051004f1")) __declspec(novtable) IWebAccountProviderActivatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Operation(Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation ** value) = 0;
};

struct __declspec(uuid("75dda3d4-7714-453d-b7ff-b95e3a1709da")) __declspec(novtable) IWebAuthenticationBrokerContinuationEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_WebAuthenticationResult(Windows::Security::Authentication::Web::IWebAuthenticationResult ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Activation::AppointmentsProviderAddAppointmentActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::AppointmentsProviderRemoveAppointmentActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::AppointmentsProviderReplaceAppointmentActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::AppointmentsProviderShowAppointmentDetailsActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::AppointmentsProviderShowTimeFrameActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::CachedFileUpdaterActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::CameraSettingsActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::ContactCallActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IContactCallActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::ContactMapActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IContactMapActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::ContactMessageActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IContactMessageActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::ContactPickerActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IContactPickerActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::ContactPostActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IContactPostActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::ContactVideoCallActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::DeviceActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IDeviceActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::DevicePairingActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IDevicePairingActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::DialReceiverActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IDialReceiverActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::FileActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IFileActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::FileOpenPickerActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::FileOpenPickerContinuationEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::FileSavePickerActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::FileSavePickerContinuationEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::FolderPickerContinuationEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IFolderPickerContinuationEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::LaunchActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::LockScreenActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::ILockScreenActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::LockScreenCallActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::PickerReturnedActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::Print3DWorkflowActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::PrintTaskSettingsActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::ProtocolActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IProtocolActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::ProtocolForResultsActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::RestrictedLaunchActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::SearchActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::ISearchActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::ShareTargetActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::SplashScreen> { using default_interface = Windows::ApplicationModel::Activation::ISplashScreen; };
template <> struct traits<Windows::ApplicationModel::Activation::TileActivatedInfo> { using default_interface = Windows::ApplicationModel::Activation::ITileActivatedInfo; };
template <> struct traits<Windows::ApplicationModel::Activation::ToastNotificationActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IToastNotificationActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::UserDataAccountProviderActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::VoiceCommandActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::WalletActionActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IWalletActionActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::WebAccountProviderActivatedEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs; };
template <> struct traits<Windows::ApplicationModel::Activation::WebAuthenticationBrokerContinuationEventArgs> { using default_interface = Windows::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs; };

}

namespace Windows::ApplicationModel::Activation {

template <typename D>
struct WINRT_EBO impl_IActivatedEventArgs
{
    Windows::ApplicationModel::Activation::ActivationKind Kind() const;
    Windows::ApplicationModel::Activation::ApplicationExecutionState PreviousExecutionState() const;
    Windows::ApplicationModel::Activation::SplashScreen SplashScreen() const;
};

template <typename D>
struct WINRT_EBO impl_IActivatedEventArgsWithUser
{
    Windows::System::User User() const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationViewActivatedEventArgs
{
    int32_t CurrentlyShownApplicationViewId() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentsProviderActivatedEventArgs
{
    hstring Verb() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentsProviderAddAppointmentActivatedEventArgs
{
    Windows::ApplicationModel::Appointments::AppointmentsProvider::AddAppointmentOperation AddAppointmentOperation() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentsProviderRemoveAppointmentActivatedEventArgs
{
    Windows::ApplicationModel::Appointments::AppointmentsProvider::RemoveAppointmentOperation RemoveAppointmentOperation() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentsProviderReplaceAppointmentActivatedEventArgs
{
    Windows::ApplicationModel::Appointments::AppointmentsProvider::ReplaceAppointmentOperation ReplaceAppointmentOperation() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> InstanceStartDate() const;
    hstring LocalId() const;
    hstring RoamingId() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentsProviderShowTimeFrameActivatedEventArgs
{
    Windows::Foundation::DateTime TimeToShow() const;
    Windows::Foundation::TimeSpan Duration() const;
};

template <typename D>
struct WINRT_EBO impl_IBackgroundActivatedEventArgs
{
    Windows::ApplicationModel::Background::IBackgroundTaskInstance TaskInstance() const;
};

template <typename D>
struct WINRT_EBO impl_ICachedFileUpdaterActivatedEventArgs
{
    Windows::Storage::Provider::CachedFileUpdaterUI CachedFileUpdaterUI() const;
};

template <typename D>
struct WINRT_EBO impl_ICameraSettingsActivatedEventArgs
{
    Windows::Foundation::IInspectable VideoDeviceController() const;
    Windows::Foundation::IInspectable VideoDeviceExtension() const;
};

template <typename D>
struct WINRT_EBO impl_IContactActivatedEventArgs
{
    hstring Verb() const;
};

template <typename D>
struct WINRT_EBO impl_IContactCallActivatedEventArgs
{
    hstring ServiceId() const;
    hstring ServiceUserId() const;
    Windows::ApplicationModel::Contacts::Contact Contact() const;
};

template <typename D>
struct WINRT_EBO impl_IContactMapActivatedEventArgs
{
    Windows::ApplicationModel::Contacts::ContactAddress Address() const;
    Windows::ApplicationModel::Contacts::Contact Contact() const;
};

template <typename D>
struct WINRT_EBO impl_IContactMessageActivatedEventArgs
{
    hstring ServiceId() const;
    hstring ServiceUserId() const;
    Windows::ApplicationModel::Contacts::Contact Contact() const;
};

template <typename D>
struct WINRT_EBO impl_IContactPickerActivatedEventArgs
{
    Windows::ApplicationModel::Contacts::Provider::ContactPickerUI ContactPickerUI() const;
};

template <typename D>
struct WINRT_EBO impl_IContactPostActivatedEventArgs
{
    hstring ServiceId() const;
    hstring ServiceUserId() const;
    Windows::ApplicationModel::Contacts::Contact Contact() const;
};

template <typename D>
struct WINRT_EBO impl_IContactVideoCallActivatedEventArgs
{
    hstring ServiceId() const;
    hstring ServiceUserId() const;
    Windows::ApplicationModel::Contacts::Contact Contact() const;
};

template <typename D>
struct WINRT_EBO impl_IContactsProviderActivatedEventArgs
{
    hstring Verb() const;
};

template <typename D>
struct WINRT_EBO impl_IContinuationActivatedEventArgs
{
    Windows::Foundation::Collections::ValueSet ContinuationData() const;
};

template <typename D>
struct WINRT_EBO impl_IDeviceActivatedEventArgs
{
    hstring DeviceInformationId() const;
    hstring Verb() const;
};

template <typename D>
struct WINRT_EBO impl_IDevicePairingActivatedEventArgs
{
    Windows::Devices::Enumeration::DeviceInformation DeviceInformation() const;
};

template <typename D>
struct WINRT_EBO impl_IDialReceiverActivatedEventArgs
{
    hstring AppName() const;
};

template <typename D>
struct WINRT_EBO impl_IFileActivatedEventArgs
{
    Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem> Files() const;
    hstring Verb() const;
};

template <typename D>
struct WINRT_EBO impl_IFileActivatedEventArgsWithCallerPackageFamilyName
{
    hstring CallerPackageFamilyName() const;
};

template <typename D>
struct WINRT_EBO impl_IFileActivatedEventArgsWithNeighboringFiles
{
    Windows::Storage::Search::StorageFileQueryResult NeighboringFilesQuery() const;
};

template <typename D>
struct WINRT_EBO impl_IFileOpenPickerActivatedEventArgs
{
    Windows::Storage::Pickers::Provider::FileOpenPickerUI FileOpenPickerUI() const;
};

template <typename D>
struct WINRT_EBO impl_IFileOpenPickerActivatedEventArgs2
{
    hstring CallerPackageFamilyName() const;
};

template <typename D>
struct WINRT_EBO impl_IFileOpenPickerContinuationEventArgs
{
    Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile> Files() const;
};

template <typename D>
struct WINRT_EBO impl_IFileSavePickerActivatedEventArgs
{
    Windows::Storage::Pickers::Provider::FileSavePickerUI FileSavePickerUI() const;
};

template <typename D>
struct WINRT_EBO impl_IFileSavePickerActivatedEventArgs2
{
    hstring CallerPackageFamilyName() const;
    hstring EnterpriseId() const;
};

template <typename D>
struct WINRT_EBO impl_IFileSavePickerContinuationEventArgs
{
    Windows::Storage::StorageFile File() const;
};

template <typename D>
struct WINRT_EBO impl_IFolderPickerContinuationEventArgs
{
    Windows::Storage::StorageFolder Folder() const;
};

template <typename D>
struct WINRT_EBO impl_ILaunchActivatedEventArgs
{
    hstring Arguments() const;
    hstring TileId() const;
};

template <typename D>
struct WINRT_EBO impl_ILaunchActivatedEventArgs2
{
    Windows::ApplicationModel::Activation::TileActivatedInfo TileActivatedInfo() const;
};

template <typename D>
struct WINRT_EBO impl_ILockScreenActivatedEventArgs
{
    Windows::Foundation::IInspectable Info() const;
};

template <typename D>
struct WINRT_EBO impl_ILockScreenCallActivatedEventArgs
{
    Windows::ApplicationModel::Calls::LockScreenCallUI CallUI() const;
};

template <typename D>
struct WINRT_EBO impl_IPickerReturnedActivatedEventArgs
{
    hstring PickerOperationId() const;
};

template <typename D>
struct WINRT_EBO impl_IPrelaunchActivatedEventArgs
{
    bool PrelaunchActivated() const;
};

template <typename D>
struct WINRT_EBO impl_IPrint3DWorkflowActivatedEventArgs
{
    Windows::Devices::Printers::Extensions::Print3DWorkflow Workflow() const;
};

template <typename D>
struct WINRT_EBO impl_IPrintTaskSettingsActivatedEventArgs
{
    Windows::Devices::Printers::Extensions::PrintTaskConfiguration Configuration() const;
};

template <typename D>
struct WINRT_EBO impl_IProtocolActivatedEventArgs
{
    Windows::Foundation::Uri Uri() const;
};

template <typename D>
struct WINRT_EBO impl_IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData
{
    hstring CallerPackageFamilyName() const;
    Windows::Foundation::Collections::ValueSet Data() const;
};

template <typename D>
struct WINRT_EBO impl_IProtocolForResultsActivatedEventArgs
{
    Windows::System::ProtocolForResultsOperation ProtocolForResultsOperation() const;
};

template <typename D>
struct WINRT_EBO impl_IRestrictedLaunchActivatedEventArgs
{
    Windows::Foundation::IInspectable SharedContext() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchActivatedEventArgs
{
    hstring QueryText() const;
    hstring Language() const;
};

template <typename D>
struct WINRT_EBO impl_ISearchActivatedEventArgsWithLinguisticDetails
{
    Windows::ApplicationModel::Search::SearchPaneQueryLinguisticDetails LinguisticDetails() const;
};

template <typename D>
struct WINRT_EBO impl_IShareTargetActivatedEventArgs
{
    Windows::ApplicationModel::DataTransfer::ShareTarget::ShareOperation ShareOperation() const;
};

template <typename D>
struct WINRT_EBO impl_ISplashScreen
{
    Windows::Foundation::Rect ImageLocation() const;
    event_token Dismissed(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Activation::SplashScreen, Windows::Foundation::IInspectable> & handler) const;
    using Dismissed_revoker = event_revoker<ISplashScreen>;
    Dismissed_revoker Dismissed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Activation::SplashScreen, Windows::Foundation::IInspectable> & handler) const;
    void Dismissed(event_token cookie) const;
};

template <typename D>
struct WINRT_EBO impl_ITileActivatedInfo
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ShownTileNotification> RecentlyShownNotifications() const;
};

template <typename D>
struct WINRT_EBO impl_IToastNotificationActivatedEventArgs
{
    hstring Argument() const;
    Windows::Foundation::Collections::ValueSet UserInput() const;
};

template <typename D>
struct WINRT_EBO impl_IUserDataAccountProviderActivatedEventArgs
{
    Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation Operation() const;
};

template <typename D>
struct WINRT_EBO impl_IViewSwitcherProvider
{
    Windows::UI::ViewManagement::ActivationViewSwitcher ViewSwitcher() const;
};

template <typename D>
struct WINRT_EBO impl_IVoiceCommandActivatedEventArgs
{
    Windows::Media::SpeechRecognition::SpeechRecognitionResult Result() const;
};

template <typename D>
struct WINRT_EBO impl_IWalletActionActivatedEventArgs
{
    hstring ItemId() const;
    Windows::ApplicationModel::Wallet::WalletActionKind ActionKind() const;
    hstring ActionId() const;
};

template <typename D>
struct WINRT_EBO impl_IWebAccountProviderActivatedEventArgs
{
    Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation Operation() const;
};

template <typename D>
struct WINRT_EBO impl_IWebAuthenticationBrokerContinuationEventArgs
{
    Windows::Security::Authentication::Web::WebAuthenticationResult WebAuthenticationResult() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IActivatedEventArgsWithUser<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IApplicationViewActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IAppointmentsProviderActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IAppointmentsProviderAddAppointmentActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IAppointmentsProviderRemoveAppointmentActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IAppointmentsProviderReplaceAppointmentActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IAppointmentsProviderShowTimeFrameActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IBackgroundActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_ICachedFileUpdaterActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_ICameraSettingsActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IContactActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IContactActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IContactActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IContactCallActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IContactCallActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IContactCallActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IContactMapActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IContactMapActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IContactMapActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IContactMessageActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IContactMessageActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IContactMessageActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IContactPickerActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IContactPickerActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IContactPickerActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IContactPostActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IContactPostActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IContactPostActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IContactVideoCallActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IContactsProviderActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IContactsProviderActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IContactsProviderActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IContinuationActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IContinuationActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IContinuationActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IDeviceActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IDeviceActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IDeviceActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IDevicePairingActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IDevicePairingActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IDevicePairingActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IDialReceiverActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IDialReceiverActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IDialReceiverActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IFileActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IFileActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithCallerPackageFamilyName>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithCallerPackageFamilyName;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IFileActivatedEventArgsWithCallerPackageFamilyName<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithNeighboringFiles>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithNeighboringFiles;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IFileActivatedEventArgsWithNeighboringFiles<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IFileOpenPickerActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs2>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs2;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IFileOpenPickerActivatedEventArgs2<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IFileOpenPickerContinuationEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IFileSavePickerActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs2>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs2;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IFileSavePickerActivatedEventArgs2<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IFileSavePickerContinuationEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IFolderPickerContinuationEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IFolderPickerContinuationEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IFolderPickerContinuationEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_ILaunchActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs2>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs2;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_ILaunchActivatedEventArgs2<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::ILockScreenActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ILockScreenActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_ILockScreenActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_ILockScreenCallActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IPickerReturnedActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IPrelaunchActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IPrelaunchActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IPrelaunchActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IPrint3DWorkflowActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IPrintTaskSettingsActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IProtocolActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IProtocolActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IProtocolActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IProtocolForResultsActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IRestrictedLaunchActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::ISearchActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ISearchActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_ISearchActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::ISearchActivatedEventArgsWithLinguisticDetails>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ISearchActivatedEventArgsWithLinguisticDetails;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_ISearchActivatedEventArgsWithLinguisticDetails<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IShareTargetActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::ISplashScreen>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ISplashScreen;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_ISplashScreen<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::ITileActivatedInfo>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ITileActivatedInfo;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_ITileActivatedInfo<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IToastNotificationActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IToastNotificationActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IToastNotificationActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IUserDataAccountProviderActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IViewSwitcherProvider>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IViewSwitcherProvider;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IViewSwitcherProvider<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IVoiceCommandActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IWalletActionActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IWalletActionActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IWalletActionActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IWebAccountProviderActivatedEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs;
    template <typename D> using consume = Windows::ApplicationModel::Activation::impl_IWebAuthenticationBrokerContinuationEventArgs<D>;
};

template <> struct traits<Windows::ApplicationModel::Activation::AppointmentsProviderAddAppointmentActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::AppointmentsProviderAddAppointmentActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.AppointmentsProviderAddAppointmentActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::AppointmentsProviderRemoveAppointmentActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::AppointmentsProviderRemoveAppointmentActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.AppointmentsProviderRemoveAppointmentActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::AppointmentsProviderReplaceAppointmentActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::AppointmentsProviderReplaceAppointmentActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.AppointmentsProviderReplaceAppointmentActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::AppointmentsProviderShowAppointmentDetailsActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::AppointmentsProviderShowAppointmentDetailsActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.AppointmentsProviderShowAppointmentDetailsActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::AppointmentsProviderShowTimeFrameActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::AppointmentsProviderShowTimeFrameActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.AppointmentsProviderShowTimeFrameActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.BackgroundActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::CachedFileUpdaterActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::CachedFileUpdaterActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.CachedFileUpdaterActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::CameraSettingsActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::CameraSettingsActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.CameraSettingsActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::ContactCallActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ContactCallActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.ContactCallActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::ContactMapActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ContactMapActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.ContactMapActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::ContactMessageActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ContactMessageActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.ContactMessageActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::ContactPickerActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ContactPickerActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.ContactPickerActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::ContactPostActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ContactPostActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.ContactPostActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::ContactVideoCallActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ContactVideoCallActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.ContactVideoCallActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::DeviceActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::DeviceActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.DeviceActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::DevicePairingActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::DevicePairingActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.DevicePairingActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::DialReceiverActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::DialReceiverActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.DialReceiverActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::FileActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::FileActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.FileActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::FileOpenPickerActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::FileOpenPickerActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.FileOpenPickerActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::FileOpenPickerContinuationEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::FileOpenPickerContinuationEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.FileOpenPickerContinuationEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::FileSavePickerActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::FileSavePickerActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.FileSavePickerActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::FileSavePickerContinuationEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::FileSavePickerContinuationEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.FileSavePickerContinuationEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::FolderPickerContinuationEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::FolderPickerContinuationEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.FolderPickerContinuationEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::LaunchActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::LaunchActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.LaunchActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::LockScreenActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::LockScreenActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.LockScreenActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::LockScreenCallActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::LockScreenCallActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.LockScreenCallActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::PickerReturnedActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::PickerReturnedActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.PickerReturnedActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::Print3DWorkflowActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::Print3DWorkflowActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.Print3DWorkflowActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::PrintTaskSettingsActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::PrintTaskSettingsActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.PrintTaskSettingsActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::ProtocolActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ProtocolActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.ProtocolActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::ProtocolForResultsActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ProtocolForResultsActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.ProtocolForResultsActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::RestrictedLaunchActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::RestrictedLaunchActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.RestrictedLaunchActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::SearchActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::SearchActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.SearchActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::ShareTargetActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ShareTargetActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.ShareTargetActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::SplashScreen>
{
    using abi = ABI::Windows::ApplicationModel::Activation::SplashScreen;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.SplashScreen"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::TileActivatedInfo>
{
    using abi = ABI::Windows::ApplicationModel::Activation::TileActivatedInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.TileActivatedInfo"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::ToastNotificationActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::ToastNotificationActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.ToastNotificationActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::UserDataAccountProviderActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::UserDataAccountProviderActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.UserDataAccountProviderActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::VoiceCommandActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::VoiceCommandActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.VoiceCommandActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::WalletActionActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::WalletActionActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.WalletActionActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::WebAccountProviderActivatedEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::WebAccountProviderActivatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.WebAccountProviderActivatedEventArgs"; }
};

template <> struct traits<Windows::ApplicationModel::Activation::WebAuthenticationBrokerContinuationEventArgs>
{
    using abi = ABI::Windows::ApplicationModel::Activation::WebAuthenticationBrokerContinuationEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Activation.WebAuthenticationBrokerContinuationEventArgs"; }
};

}

}
