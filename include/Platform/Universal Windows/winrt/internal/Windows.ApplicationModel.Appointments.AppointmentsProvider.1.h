// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.ApplicationModel.Appointments.AppointmentsProvider.0.h"
#include "Windows.ApplicationModel.Appointments.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider {

struct __declspec(uuid("ec4a9af3-620d-4c69-add7-9794e918081f")) __declspec(novtable) IAddAppointmentOperation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppointmentInformation(Windows::ApplicationModel::Appointments::IAppointment ** value) = 0;
    virtual HRESULT __stdcall get_SourcePackageFamilyName(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompleted(hstring itemId) = 0;
    virtual HRESULT __stdcall abi_ReportCanceled() = 0;
    virtual HRESULT __stdcall abi_ReportError(hstring value) = 0;
    virtual HRESULT __stdcall abi_DismissUI() = 0;
};

struct __declspec(uuid("36dbba28-9e2e-49c6-8ef7-3ab7a5dcc8b8")) __declspec(novtable) IAppointmentsProviderLaunchActionVerbsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AddAppointment(hstring * value) = 0;
    virtual HRESULT __stdcall get_ReplaceAppointment(hstring * value) = 0;
    virtual HRESULT __stdcall get_RemoveAppointment(hstring * value) = 0;
    virtual HRESULT __stdcall get_ShowTimeFrame(hstring * value) = 0;
};

struct __declspec(uuid("ef9049a4-af21-473c-88dc-76cd89f60ca5")) __declspec(novtable) IAppointmentsProviderLaunchActionVerbsStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ShowAppointmentDetails(hstring * value) = 0;
};

struct __declspec(uuid("08b66aba-fe33-46cd-a50c-a8ffb3260537")) __declspec(novtable) IRemoveAppointmentOperation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppointmentId(hstring * value) = 0;
    virtual HRESULT __stdcall get_InstanceStartDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_SourcePackageFamilyName(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompleted() = 0;
    virtual HRESULT __stdcall abi_ReportCanceled() = 0;
    virtual HRESULT __stdcall abi_ReportError(hstring value) = 0;
    virtual HRESULT __stdcall abi_DismissUI() = 0;
};

struct __declspec(uuid("f4903d9b-9e61-4de2-a732-2687c07d1de8")) __declspec(novtable) IReplaceAppointmentOperation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AppointmentId(hstring * value) = 0;
    virtual HRESULT __stdcall get_AppointmentInformation(Windows::ApplicationModel::Appointments::IAppointment ** value) = 0;
    virtual HRESULT __stdcall get_InstanceStartDate(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_SourcePackageFamilyName(hstring * value) = 0;
    virtual HRESULT __stdcall abi_ReportCompleted(hstring itemId) = 0;
    virtual HRESULT __stdcall abi_ReportCanceled() = 0;
    virtual HRESULT __stdcall abi_ReportError(hstring value) = 0;
    virtual HRESULT __stdcall abi_DismissUI() = 0;
};

}

namespace ABI {

template <> struct traits<Windows::ApplicationModel::Appointments::AppointmentsProvider::AddAppointmentOperation> { using default_interface = Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation; };
template <> struct traits<Windows::ApplicationModel::Appointments::AppointmentsProvider::RemoveAppointmentOperation> { using default_interface = Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation; };
template <> struct traits<Windows::ApplicationModel::Appointments::AppointmentsProvider::ReplaceAppointmentOperation> { using default_interface = Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation; };

}

namespace Windows::ApplicationModel::Appointments::AppointmentsProvider {

template <typename D>
struct WINRT_EBO impl_IAddAppointmentOperation
{
    Windows::ApplicationModel::Appointments::Appointment AppointmentInformation() const;
    hstring SourcePackageFamilyName() const;
    void ReportCompleted(hstring_view itemId) const;
    void ReportCanceled() const;
    void ReportError(hstring_view value) const;
    void DismissUI() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentsProviderLaunchActionVerbsStatics
{
    hstring AddAppointment() const;
    hstring ReplaceAppointment() const;
    hstring RemoveAppointment() const;
    hstring ShowTimeFrame() const;
};

template <typename D>
struct WINRT_EBO impl_IAppointmentsProviderLaunchActionVerbsStatics2
{
    hstring ShowAppointmentDetails() const;
};

template <typename D>
struct WINRT_EBO impl_IRemoveAppointmentOperation
{
    hstring AppointmentId() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> InstanceStartDate() const;
    hstring SourcePackageFamilyName() const;
    void ReportCompleted() const;
    void ReportCanceled() const;
    void ReportError(hstring_view value) const;
    void DismissUI() const;
};

template <typename D>
struct WINRT_EBO impl_IReplaceAppointmentOperation
{
    hstring AppointmentId() const;
    Windows::ApplicationModel::Appointments::Appointment AppointmentInformation() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> InstanceStartDate() const;
    hstring SourcePackageFamilyName() const;
    void ReportCompleted(hstring_view itemId) const;
    void ReportCanceled() const;
    void ReportError(hstring_view value) const;
    void DismissUI() const;
};

}

namespace impl {

template <> struct traits<Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::AppointmentsProvider::impl_IAddAppointmentOperation<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::AppointmentsProvider::impl_IAppointmentsProviderLaunchActionVerbsStatics<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::AppointmentsProvider::impl_IAppointmentsProviderLaunchActionVerbsStatics2<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::AppointmentsProvider::impl_IRemoveAppointmentOperation<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation;
    template <typename D> using consume = Windows::ApplicationModel::Appointments::AppointmentsProvider::impl_IReplaceAppointmentOperation<D>;
};

template <> struct traits<Windows::ApplicationModel::Appointments::AppointmentsProvider::AddAppointmentOperation>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::AddAppointmentOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.AppointmentsProvider.AddAppointmentOperation"; }
};

template <> struct traits<Windows::ApplicationModel::Appointments::AppointmentsProvider::AppointmentsProviderLaunchActionVerbs>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.AppointmentsProvider.AppointmentsProviderLaunchActionVerbs"; }
};

template <> struct traits<Windows::ApplicationModel::Appointments::AppointmentsProvider::RemoveAppointmentOperation>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::RemoveAppointmentOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.AppointmentsProvider.RemoveAppointmentOperation"; }
};

template <> struct traits<Windows::ApplicationModel::Appointments::AppointmentsProvider::ReplaceAppointmentOperation>
{
    using abi = ABI::Windows::ApplicationModel::Appointments::AppointmentsProvider::ReplaceAppointmentOperation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.ApplicationModel.Appointments.AppointmentsProvider.ReplaceAppointmentOperation"; }
};

}

}
