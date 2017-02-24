// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.ApplicationModel.Appointments.AppointmentsProvider.3.h"
#include "internal/Windows.ApplicationModel.UserDataAccounts.Provider.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.UI.ViewManagement.3.h"
#include "internal/Windows.ApplicationModel.Search.3.h"
#include "internal/Windows.ApplicationModel.DataTransfer.ShareTarget.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.Search.3.h"
#include "internal/Windows.Storage.Pickers.Provider.3.h"
#include "internal/Windows.Storage.Provider.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Security.Authentication.Web.3.h"
#include "internal/Windows.Security.Authentication.Web.Provider.3.h"
#include "internal/Windows.ApplicationModel.Background.3.h"
#include "internal/Windows.Devices.Enumeration.3.h"
#include "internal/Windows.Media.SpeechRecognition.3.h"
#include "internal/Windows.Devices.Printers.Extensions.3.h"
#include "internal/Windows.ApplicationModel.Calls.3.h"
#include "internal/Windows.ApplicationModel.Contacts.Provider.3.h"
#include "internal/Windows.ApplicationModel.Contacts.3.h"
#include "internal/Windows.ApplicationModel.Wallet.3.h"
#include "internal/Windows.ApplicationModel.Activation.3.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IActivatedEventArgs>
{
    HRESULT __stdcall get_Kind(Windows::ApplicationModel::Activation::ActivationKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PreviousExecutionState(Windows::ApplicationModel::Activation::ApplicationExecutionState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PreviousExecutionState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SplashScreen(impl::abi_arg_out<Windows::ApplicationModel::Activation::ISplashScreen> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SplashScreen());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser> : produce_base<D, Windows::ApplicationModel::Activation::IActivatedEventArgsWithUser>
{
    HRESULT __stdcall get_User(impl::abi_arg_out<Windows::System::IUser> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().User());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>
{
    HRESULT __stdcall get_CurrentlyShownApplicationViewId(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CurrentlyShownApplicationViewId());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>
{
    HRESULT __stdcall get_Verb(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Verb());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs>
{
    HRESULT __stdcall get_AddAppointmentOperation(impl::abi_arg_out<Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AddAppointmentOperation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs>
{
    HRESULT __stdcall get_RemoveAppointmentOperation(impl::abi_arg_out<Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoveAppointmentOperation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs>
{
    HRESULT __stdcall get_ReplaceAppointmentOperation(impl::abi_arg_out<Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReplaceAppointmentOperation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs>
{
    HRESULT __stdcall get_InstanceStartDate(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InstanceStartDate());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LocalId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LocalId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RoamingId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RoamingId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs>
{
    HRESULT __stdcall get_TimeToShow(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TimeToShow());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs>
{
    HRESULT __stdcall get_TaskInstance(impl::abi_arg_out<Windows::ApplicationModel::Background::IBackgroundTaskInstance> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TaskInstance());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs>
{
    HRESULT __stdcall get_CachedFileUpdaterUI(impl::abi_arg_out<Windows::Storage::Provider::ICachedFileUpdaterUI> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CachedFileUpdaterUI());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs>
{
    HRESULT __stdcall get_VideoDeviceController(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoDeviceController());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_VideoDeviceExtension(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().VideoDeviceExtension());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IContactActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IContactActivatedEventArgs>
{
    HRESULT __stdcall get_Verb(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Verb());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IContactCallActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IContactCallActivatedEventArgs>
{
    HRESULT __stdcall get_ServiceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceUserId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceUserId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Contact(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContact> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Contact());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IContactMapActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IContactMapActivatedEventArgs>
{
    HRESULT __stdcall get_Address(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContactAddress> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Address());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Contact(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContact> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Contact());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IContactMessageActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IContactMessageActivatedEventArgs>
{
    HRESULT __stdcall get_ServiceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceUserId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceUserId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Contact(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContact> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Contact());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IContactPickerActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IContactPickerActivatedEventArgs>
{
    HRESULT __stdcall get_ContactPickerUI(impl::abi_arg_out<Windows::ApplicationModel::Contacts::Provider::IContactPickerUI> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContactPickerUI());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IContactPostActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IContactPostActivatedEventArgs>
{
    HRESULT __stdcall get_ServiceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceUserId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceUserId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Contact(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContact> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Contact());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs>
{
    HRESULT __stdcall get_ServiceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ServiceUserId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ServiceUserId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Contact(impl::abi_arg_out<Windows::ApplicationModel::Contacts::IContact> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Contact());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IContactsProviderActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IContactsProviderActivatedEventArgs>
{
    HRESULT __stdcall get_Verb(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Verb());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IContinuationActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IContinuationActivatedEventArgs>
{
    HRESULT __stdcall get_ContinuationData(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContinuationData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IDeviceActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IDeviceActivatedEventArgs>
{
    HRESULT __stdcall get_DeviceInformationId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceInformationId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Verb(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Verb());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IDevicePairingActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IDevicePairingActivatedEventArgs>
{
    HRESULT __stdcall get_DeviceInformation(impl::abi_arg_out<Windows::Devices::Enumeration::IDeviceInformation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IDialReceiverActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IDialReceiverActivatedEventArgs>
{
    HRESULT __stdcall get_AppName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IFileActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IFileActivatedEventArgs>
{
    HRESULT __stdcall get_Files(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Files());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Verb(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Verb());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithCallerPackageFamilyName> : produce_base<D, Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithCallerPackageFamilyName>
{
    HRESULT __stdcall get_CallerPackageFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CallerPackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithNeighboringFiles> : produce_base<D, Windows::ApplicationModel::Activation::IFileActivatedEventArgsWithNeighboringFiles>
{
    HRESULT __stdcall get_NeighboringFilesQuery(impl::abi_arg_out<Windows::Storage::Search::IStorageFileQueryResult> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NeighboringFilesQuery());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs>
{
    HRESULT __stdcall get_FileOpenPickerUI(impl::abi_arg_out<Windows::Storage::Pickers::Provider::IFileOpenPickerUI> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FileOpenPickerUI());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs2> : produce_base<D, Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs2>
{
    HRESULT __stdcall get_CallerPackageFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CallerPackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs>
{
    HRESULT __stdcall get_Files(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Files());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs>
{
    HRESULT __stdcall get_FileSavePickerUI(impl::abi_arg_out<Windows::Storage::Pickers::Provider::IFileSavePickerUI> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FileSavePickerUI());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs2> : produce_base<D, Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs2>
{
    HRESULT __stdcall get_CallerPackageFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CallerPackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EnterpriseId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnterpriseId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs>
{
    HRESULT __stdcall get_File(impl::abi_arg_out<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().File());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IFolderPickerContinuationEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IFolderPickerContinuationEventArgs>
{
    HRESULT __stdcall get_Folder(impl::abi_arg_out<Windows::Storage::IStorageFolder> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Folder());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs>
{
    HRESULT __stdcall get_Arguments(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Arguments());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TileId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TileId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs2> : produce_base<D, Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs2>
{
    HRESULT __stdcall get_TileActivatedInfo(impl::abi_arg_out<Windows::ApplicationModel::Activation::ITileActivatedInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TileActivatedInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::ILockScreenActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::ILockScreenActivatedEventArgs>
{
    HRESULT __stdcall get_Info(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Info());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs>
{
    HRESULT __stdcall get_CallUI(impl::abi_arg_out<Windows::ApplicationModel::Calls::ILockScreenCallUI> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CallUI());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs>
{
    HRESULT __stdcall get_PickerOperationId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PickerOperationId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IPrelaunchActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IPrelaunchActivatedEventArgs>
{
    HRESULT __stdcall get_PrelaunchActivated(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PrelaunchActivated());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs>
{
    HRESULT __stdcall get_Workflow(impl::abi_arg_out<Windows::Devices::Printers::Extensions::IPrint3DWorkflow> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Workflow());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs>
{
    HRESULT __stdcall get_Configuration(impl::abi_arg_out<Windows::Devices::Printers::Extensions::IPrintTaskConfiguration> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Configuration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IProtocolActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IProtocolActivatedEventArgs>
{
    HRESULT __stdcall get_Uri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData> : produce_base<D, Windows::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData>
{
    HRESULT __stdcall get_CallerPackageFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CallerPackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Data(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Data());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs>
{
    HRESULT __stdcall get_ProtocolForResultsOperation(impl::abi_arg_out<Windows::System::IProtocolForResultsOperation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ProtocolForResultsOperation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs>
{
    HRESULT __stdcall get_SharedContext(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SharedContext());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::ISearchActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::ISearchActivatedEventArgs>
{
    HRESULT __stdcall get_QueryText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().QueryText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Language(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::ISearchActivatedEventArgsWithLinguisticDetails> : produce_base<D, Windows::ApplicationModel::Activation::ISearchActivatedEventArgsWithLinguisticDetails>
{
    HRESULT __stdcall get_LinguisticDetails(impl::abi_arg_out<Windows::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LinguisticDetails());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs>
{
    HRESULT __stdcall get_ShareOperation(impl::abi_arg_out<Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShareOperation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::ISplashScreen> : produce_base<D, Windows::ApplicationModel::Activation::ISplashScreen>
{
    HRESULT __stdcall get_ImageLocation(impl::abi_arg_out<Windows::Foundation::Rect> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ImageLocation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Dismissed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Activation::SplashScreen, Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().Dismissed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Activation::SplashScreen, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Dismissed(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Dismissed(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::ITileActivatedInfo> : produce_base<D, Windows::ApplicationModel::Activation::ITileActivatedInfo>
{
    HRESULT __stdcall get_RecentlyShownNotifications(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ShownTileNotification>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RecentlyShownNotifications());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IToastNotificationActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IToastNotificationActivatedEventArgs>
{
    HRESULT __stdcall get_Argument(impl::abi_arg_out<hstring> argument) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *argument = detach_abi(this->shim().Argument());
            return S_OK;
        }
        catch (...)
        {
            *argument = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserInput(impl::abi_arg_out<Windows::Foundation::Collections::IPropertySet> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserInput());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs>
{
    HRESULT __stdcall get_Operation(impl::abi_arg_out<Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Operation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IViewSwitcherProvider> : produce_base<D, Windows::ApplicationModel::Activation::IViewSwitcherProvider>
{
    HRESULT __stdcall get_ViewSwitcher(impl::abi_arg_out<Windows::UI::ViewManagement::IActivationViewSwitcher> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ViewSwitcher());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs>
{
    HRESULT __stdcall get_Result(impl::abi_arg_out<Windows::Media::SpeechRecognition::ISpeechRecognitionResult> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Result());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IWalletActionActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IWalletActionActivatedEventArgs>
{
    HRESULT __stdcall get_ItemId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ItemId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActionKind(Windows::ApplicationModel::Wallet::WalletActionKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActionKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ActionId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActionId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs>
{
    HRESULT __stdcall get_Operation(impl::abi_arg_out<Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Operation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs> : produce_base<D, Windows::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs>
{
    HRESULT __stdcall get_WebAuthenticationResult(impl::abi_arg_out<Windows::Security::Authentication::Web::IWebAuthenticationResult> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().WebAuthenticationResult());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Activation {

template <typename D> Windows::Foundation::Rect impl_ISplashScreen<D>::ImageLocation() const
{
    Windows::Foundation::Rect value {};
    check_hresult(WINRT_SHIM(ISplashScreen)->get_ImageLocation(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ISplashScreen<D>::Dismissed(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Activation::SplashScreen, Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ISplashScreen)->add_Dismissed(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ISplashScreen> impl_ISplashScreen<D>::Dismissed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Activation::SplashScreen, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, ISplashScreen>(this, &ABI::Windows::ApplicationModel::Activation::ISplashScreen::remove_Dismissed, Dismissed(handler));
}

template <typename D> void impl_ISplashScreen<D>::Dismissed(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ISplashScreen)->remove_Dismissed(cookie));
}

template <typename D> Windows::ApplicationModel::Activation::ActivationKind impl_IActivatedEventArgs<D>::Kind() const
{
    Windows::ApplicationModel::Activation::ActivationKind value {};
    check_hresult(WINRT_SHIM(IActivatedEventArgs)->get_Kind(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Activation::ApplicationExecutionState impl_IActivatedEventArgs<D>::PreviousExecutionState() const
{
    Windows::ApplicationModel::Activation::ApplicationExecutionState value {};
    check_hresult(WINRT_SHIM(IActivatedEventArgs)->get_PreviousExecutionState(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Activation::SplashScreen impl_IActivatedEventArgs<D>::SplashScreen() const
{
    Windows::ApplicationModel::Activation::SplashScreen value { nullptr };
    check_hresult(WINRT_SHIM(IActivatedEventArgs)->get_SplashScreen(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentsProviderActivatedEventArgs<D>::Verb() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentsProviderActivatedEventArgs)->get_Verb(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentsProvider::AddAppointmentOperation impl_IAppointmentsProviderAddAppointmentActivatedEventArgs<D>::AddAppointmentOperation() const
{
    Windows::ApplicationModel::Appointments::AppointmentsProvider::AddAppointmentOperation value { nullptr };
    check_hresult(WINRT_SHIM(IAppointmentsProviderAddAppointmentActivatedEventArgs)->get_AddAppointmentOperation(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentsProvider::ReplaceAppointmentOperation impl_IAppointmentsProviderReplaceAppointmentActivatedEventArgs<D>::ReplaceAppointmentOperation() const
{
    Windows::ApplicationModel::Appointments::AppointmentsProvider::ReplaceAppointmentOperation value { nullptr };
    check_hresult(WINRT_SHIM(IAppointmentsProviderReplaceAppointmentActivatedEventArgs)->get_ReplaceAppointmentOperation(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentsProvider::RemoveAppointmentOperation impl_IAppointmentsProviderRemoveAppointmentActivatedEventArgs<D>::RemoveAppointmentOperation() const
{
    Windows::ApplicationModel::Appointments::AppointmentsProvider::RemoveAppointmentOperation value { nullptr };
    check_hresult(WINRT_SHIM(IAppointmentsProviderRemoveAppointmentActivatedEventArgs)->get_RemoveAppointmentOperation(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs<D>::InstanceStartDate() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs)->get_InstanceStartDate(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs<D>::LocalId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs)->get_LocalId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs<D>::RoamingId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs)->get_RoamingId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IAppointmentsProviderShowTimeFrameActivatedEventArgs<D>::TimeToShow() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IAppointmentsProviderShowTimeFrameActivatedEventArgs)->get_TimeToShow(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IAppointmentsProviderShowTimeFrameActivatedEventArgs<D>::Duration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IAppointmentsProviderShowTimeFrameActivatedEventArgs)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation impl_IUserDataAccountProviderActivatedEventArgs<D>::Operation() const
{
    Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation value;
    check_hresult(WINRT_SHIM(IUserDataAccountProviderActivatedEventArgs)->get_Operation(put_abi(value)));
    return value;
}

template <typename D> Windows::System::User impl_IActivatedEventArgsWithUser<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IActivatedEventArgsWithUser)->get_User(put_abi(value)));
    return value;
}

template <typename D> int32_t impl_IApplicationViewActivatedEventArgs<D>::CurrentlyShownApplicationViewId() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IApplicationViewActivatedEventArgs)->get_CurrentlyShownApplicationViewId(&value));
    return value;
}

template <typename D> Windows::UI::ViewManagement::ActivationViewSwitcher impl_IViewSwitcherProvider<D>::ViewSwitcher() const
{
    Windows::UI::ViewManagement::ActivationViewSwitcher value { nullptr };
    check_hresult(WINRT_SHIM(IViewSwitcherProvider)->get_ViewSwitcher(put_abi(value)));
    return value;
}

template <typename D> bool impl_IPrelaunchActivatedEventArgs<D>::PrelaunchActivated() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IPrelaunchActivatedEventArgs)->get_PrelaunchActivated(&value));
    return value;
}

template <typename D> hstring impl_ILaunchActivatedEventArgs<D>::Arguments() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILaunchActivatedEventArgs)->get_Arguments(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ILaunchActivatedEventArgs<D>::TileId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ILaunchActivatedEventArgs)->get_TileId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Activation::TileActivatedInfo impl_ILaunchActivatedEventArgs2<D>::TileActivatedInfo() const
{
    Windows::ApplicationModel::Activation::TileActivatedInfo value { nullptr };
    check_hresult(WINRT_SHIM(ILaunchActivatedEventArgs2)->get_TileActivatedInfo(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISearchActivatedEventArgs<D>::QueryText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISearchActivatedEventArgs)->get_QueryText(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISearchActivatedEventArgs<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISearchActivatedEventArgs)->get_Language(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Search::SearchPaneQueryLinguisticDetails impl_ISearchActivatedEventArgsWithLinguisticDetails<D>::LinguisticDetails() const
{
    Windows::ApplicationModel::Search::SearchPaneQueryLinguisticDetails value { nullptr };
    check_hresult(WINRT_SHIM(ISearchActivatedEventArgsWithLinguisticDetails)->get_LinguisticDetails(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::DataTransfer::ShareTarget::ShareOperation impl_IShareTargetActivatedEventArgs<D>::ShareOperation() const
{
    Windows::ApplicationModel::DataTransfer::ShareTarget::ShareOperation value { nullptr };
    check_hresult(WINRT_SHIM(IShareTargetActivatedEventArgs)->get_ShareOperation(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem> impl_IFileActivatedEventArgs<D>::Files() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem> value;
    check_hresult(WINRT_SHIM(IFileActivatedEventArgs)->get_Files(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IFileActivatedEventArgs<D>::Verb() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileActivatedEventArgs)->get_Verb(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Search::StorageFileQueryResult impl_IFileActivatedEventArgsWithNeighboringFiles<D>::NeighboringFilesQuery() const
{
    Windows::Storage::Search::StorageFileQueryResult value { nullptr };
    check_hresult(WINRT_SHIM(IFileActivatedEventArgsWithNeighboringFiles)->get_NeighboringFilesQuery(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IFileActivatedEventArgsWithCallerPackageFamilyName<D>::CallerPackageFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileActivatedEventArgsWithCallerPackageFamilyName)->get_CallerPackageFamilyName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_IProtocolActivatedEventArgs<D>::Uri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IProtocolActivatedEventArgs)->get_Uri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData<D>::CallerPackageFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData)->get_CallerPackageFamilyName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::ValueSet impl_IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData<D>::Data() const
{
    Windows::Foundation::Collections::ValueSet value { nullptr };
    check_hresult(WINRT_SHIM(IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData)->get_Data(put_abi(value)));
    return value;
}

template <typename D> Windows::System::ProtocolForResultsOperation impl_IProtocolForResultsActivatedEventArgs<D>::ProtocolForResultsOperation() const
{
    Windows::System::ProtocolForResultsOperation value { nullptr };
    check_hresult(WINRT_SHIM(IProtocolForResultsActivatedEventArgs)->get_ProtocolForResultsOperation(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Pickers::Provider::FileOpenPickerUI impl_IFileOpenPickerActivatedEventArgs<D>::FileOpenPickerUI() const
{
    Windows::Storage::Pickers::Provider::FileOpenPickerUI value { nullptr };
    check_hresult(WINRT_SHIM(IFileOpenPickerActivatedEventArgs)->get_FileOpenPickerUI(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IFileOpenPickerActivatedEventArgs2<D>::CallerPackageFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileOpenPickerActivatedEventArgs2)->get_CallerPackageFamilyName(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Pickers::Provider::FileSavePickerUI impl_IFileSavePickerActivatedEventArgs<D>::FileSavePickerUI() const
{
    Windows::Storage::Pickers::Provider::FileSavePickerUI value { nullptr };
    check_hresult(WINRT_SHIM(IFileSavePickerActivatedEventArgs)->get_FileSavePickerUI(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IFileSavePickerActivatedEventArgs2<D>::CallerPackageFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileSavePickerActivatedEventArgs2)->get_CallerPackageFamilyName(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IFileSavePickerActivatedEventArgs2<D>::EnterpriseId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IFileSavePickerActivatedEventArgs2)->get_EnterpriseId(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Provider::CachedFileUpdaterUI impl_ICachedFileUpdaterActivatedEventArgs<D>::CachedFileUpdaterUI() const
{
    Windows::Storage::Provider::CachedFileUpdaterUI value { nullptr };
    check_hresult(WINRT_SHIM(ICachedFileUpdaterActivatedEventArgs)->get_CachedFileUpdaterUI(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDeviceActivatedEventArgs<D>::DeviceInformationId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceActivatedEventArgs)->get_DeviceInformationId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDeviceActivatedEventArgs<D>::Verb() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDeviceActivatedEventArgs)->get_Verb(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IPickerReturnedActivatedEventArgs<D>::PickerOperationId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IPickerReturnedActivatedEventArgs)->get_PickerOperationId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IRestrictedLaunchActivatedEventArgs<D>::SharedContext() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IRestrictedLaunchActivatedEventArgs)->get_SharedContext(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_ILockScreenActivatedEventArgs<D>::Info() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(ILockScreenActivatedEventArgs)->get_Info(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::ValueSet impl_IContinuationActivatedEventArgs<D>::ContinuationData() const
{
    Windows::Foundation::Collections::ValueSet value { nullptr };
    check_hresult(WINRT_SHIM(IContinuationActivatedEventArgs)->get_ContinuationData(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile> impl_IFileOpenPickerContinuationEventArgs<D>::Files() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile> value;
    check_hresult(WINRT_SHIM(IFileOpenPickerContinuationEventArgs)->get_Files(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFile impl_IFileSavePickerContinuationEventArgs<D>::File() const
{
    Windows::Storage::StorageFile value { nullptr };
    check_hresult(WINRT_SHIM(IFileSavePickerContinuationEventArgs)->get_File(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::StorageFolder impl_IFolderPickerContinuationEventArgs<D>::Folder() const
{
    Windows::Storage::StorageFolder value { nullptr };
    check_hresult(WINRT_SHIM(IFolderPickerContinuationEventArgs)->get_Folder(put_abi(value)));
    return value;
}

template <typename D> Windows::Security::Authentication::Web::WebAuthenticationResult impl_IWebAuthenticationBrokerContinuationEventArgs<D>::WebAuthenticationResult() const
{
    Windows::Security::Authentication::Web::WebAuthenticationResult result { nullptr };
    check_hresult(WINRT_SHIM(IWebAuthenticationBrokerContinuationEventArgs)->get_WebAuthenticationResult(put_abi(result)));
    return result;
}

template <typename D> Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation impl_IWebAccountProviderActivatedEventArgs<D>::Operation() const
{
    Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation value;
    check_hresult(WINRT_SHIM(IWebAccountProviderActivatedEventArgs)->get_Operation(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IToastNotificationActivatedEventArgs<D>::Argument() const
{
    hstring argument;
    check_hresult(WINRT_SHIM(IToastNotificationActivatedEventArgs)->get_Argument(put_abi(argument)));
    return argument;
}

template <typename D> Windows::Foundation::Collections::ValueSet impl_IToastNotificationActivatedEventArgs<D>::UserInput() const
{
    Windows::Foundation::Collections::ValueSet value { nullptr };
    check_hresult(WINRT_SHIM(IToastNotificationActivatedEventArgs)->get_UserInput(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IDialReceiverActivatedEventArgs<D>::AppName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDialReceiverActivatedEventArgs)->get_AppName(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ShownTileNotification> impl_ITileActivatedInfo<D>::RecentlyShownNotifications() const
{
    Windows::Foundation::Collections::IVectorView<Windows::UI::Notifications::ShownTileNotification> value;
    check_hresult(WINRT_SHIM(ITileActivatedInfo)->get_RecentlyShownNotifications(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Background::IBackgroundTaskInstance impl_IBackgroundActivatedEventArgs<D>::TaskInstance() const
{
    Windows::ApplicationModel::Background::IBackgroundTaskInstance value;
    check_hresult(WINRT_SHIM(IBackgroundActivatedEventArgs)->get_TaskInstance(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Enumeration::DeviceInformation impl_IDevicePairingActivatedEventArgs<D>::DeviceInformation() const
{
    Windows::Devices::Enumeration::DeviceInformation value { nullptr };
    check_hresult(WINRT_SHIM(IDevicePairingActivatedEventArgs)->get_DeviceInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionResult impl_IVoiceCommandActivatedEventArgs<D>::Result() const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionResult value { nullptr };
    check_hresult(WINRT_SHIM(IVoiceCommandActivatedEventArgs)->get_Result(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Printers::Extensions::PrintTaskConfiguration impl_IPrintTaskSettingsActivatedEventArgs<D>::Configuration() const
{
    Windows::Devices::Printers::Extensions::PrintTaskConfiguration value { nullptr };
    check_hresult(WINRT_SHIM(IPrintTaskSettingsActivatedEventArgs)->get_Configuration(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Printers::Extensions::Print3DWorkflow impl_IPrint3DWorkflowActivatedEventArgs<D>::Workflow() const
{
    Windows::Devices::Printers::Extensions::Print3DWorkflow value { nullptr };
    check_hresult(WINRT_SHIM(IPrint3DWorkflowActivatedEventArgs)->get_Workflow(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Calls::LockScreenCallUI impl_ILockScreenCallActivatedEventArgs<D>::CallUI() const
{
    Windows::ApplicationModel::Calls::LockScreenCallUI value { nullptr };
    check_hresult(WINRT_SHIM(ILockScreenCallActivatedEventArgs)->get_CallUI(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_ICameraSettingsActivatedEventArgs<D>::VideoDeviceController() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(ICameraSettingsActivatedEventArgs)->get_VideoDeviceController(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_ICameraSettingsActivatedEventArgs<D>::VideoDeviceExtension() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(ICameraSettingsActivatedEventArgs)->get_VideoDeviceExtension(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::Provider::ContactPickerUI impl_IContactPickerActivatedEventArgs<D>::ContactPickerUI() const
{
    Windows::ApplicationModel::Contacts::Provider::ContactPickerUI value { nullptr };
    check_hresult(WINRT_SHIM(IContactPickerActivatedEventArgs)->get_ContactPickerUI(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactActivatedEventArgs<D>::Verb() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactActivatedEventArgs)->get_Verb(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactCallActivatedEventArgs<D>::ServiceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactCallActivatedEventArgs)->get_ServiceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactCallActivatedEventArgs<D>::ServiceUserId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactCallActivatedEventArgs)->get_ServiceUserId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::Contact impl_IContactCallActivatedEventArgs<D>::Contact() const
{
    Windows::ApplicationModel::Contacts::Contact value { nullptr };
    check_hresult(WINRT_SHIM(IContactCallActivatedEventArgs)->get_Contact(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactMessageActivatedEventArgs<D>::ServiceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactMessageActivatedEventArgs)->get_ServiceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactMessageActivatedEventArgs<D>::ServiceUserId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactMessageActivatedEventArgs)->get_ServiceUserId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::Contact impl_IContactMessageActivatedEventArgs<D>::Contact() const
{
    Windows::ApplicationModel::Contacts::Contact value { nullptr };
    check_hresult(WINRT_SHIM(IContactMessageActivatedEventArgs)->get_Contact(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::ContactAddress impl_IContactMapActivatedEventArgs<D>::Address() const
{
    Windows::ApplicationModel::Contacts::ContactAddress value { nullptr };
    check_hresult(WINRT_SHIM(IContactMapActivatedEventArgs)->get_Address(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::Contact impl_IContactMapActivatedEventArgs<D>::Contact() const
{
    Windows::ApplicationModel::Contacts::Contact value { nullptr };
    check_hresult(WINRT_SHIM(IContactMapActivatedEventArgs)->get_Contact(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactPostActivatedEventArgs<D>::ServiceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactPostActivatedEventArgs)->get_ServiceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactPostActivatedEventArgs<D>::ServiceUserId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactPostActivatedEventArgs)->get_ServiceUserId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::Contact impl_IContactPostActivatedEventArgs<D>::Contact() const
{
    Windows::ApplicationModel::Contacts::Contact value { nullptr };
    check_hresult(WINRT_SHIM(IContactPostActivatedEventArgs)->get_Contact(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactVideoCallActivatedEventArgs<D>::ServiceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactVideoCallActivatedEventArgs)->get_ServiceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactVideoCallActivatedEventArgs<D>::ServiceUserId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactVideoCallActivatedEventArgs)->get_ServiceUserId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Contacts::Contact impl_IContactVideoCallActivatedEventArgs<D>::Contact() const
{
    Windows::ApplicationModel::Contacts::Contact value { nullptr };
    check_hresult(WINRT_SHIM(IContactVideoCallActivatedEventArgs)->get_Contact(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContactsProviderActivatedEventArgs<D>::Verb() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContactsProviderActivatedEventArgs)->get_Verb(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IWalletActionActivatedEventArgs<D>::ItemId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWalletActionActivatedEventArgs)->get_ItemId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Wallet::WalletActionKind impl_IWalletActionActivatedEventArgs<D>::ActionKind() const
{
    Windows::ApplicationModel::Wallet::WalletActionKind value {};
    check_hresult(WINRT_SHIM(IWalletActionActivatedEventArgs)->get_ActionKind(&value));
    return value;
}

template <typename D> hstring impl_IWalletActionActivatedEventArgs<D>::ActionId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IWalletActionActivatedEventArgs)->get_ActionId(put_abi(value)));
    return value;
}

}

}
#pragma warning(pop)
