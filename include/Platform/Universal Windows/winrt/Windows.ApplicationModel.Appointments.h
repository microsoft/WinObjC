// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Popups.3.h"
#include "internal/Windows.System.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.UI.3.h"
#include "internal/Windows.ApplicationModel.Appointments.3.h"
#include "Windows.ApplicationModel.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointment> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointment>
{
    HRESULT __stdcall get_StartTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_StartTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
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

    HRESULT __stdcall put_Duration(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Duration(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Location(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Location(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Location(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Subject(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Subject());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Subject(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Subject(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Details(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Details());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Details(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Details(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Reminder(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Reminder());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Reminder(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::TimeSpan>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Reminder(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::TimeSpan> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Organizer(impl::abi_arg_out<Windows::ApplicationModel::Appointments::IAppointmentParticipant> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Organizer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Organizer(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointmentParticipant> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Organizer(*reinterpret_cast<const Windows::ApplicationModel::Appointments::AppointmentOrganizer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Invitees(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Appointments::AppointmentInvitee>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Invitees());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Recurrence(impl::abi_arg_out<Windows::ApplicationModel::Appointments::IAppointmentRecurrence> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Recurrence());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Recurrence(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointmentRecurrence> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Recurrence(*reinterpret_cast<const Windows::ApplicationModel::Appointments::AppointmentRecurrence *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BusyStatus(Windows::ApplicationModel::Appointments::AppointmentBusyStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BusyStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BusyStatus(Windows::ApplicationModel::Appointments::AppointmentBusyStatus value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BusyStatus(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllDay(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllDay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllDay(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllDay(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Sensitivity(Windows::ApplicationModel::Appointments::AppointmentSensitivity * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Sensitivity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Sensitivity(Windows::ApplicationModel::Appointments::AppointmentSensitivity value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Sensitivity(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall put_Uri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Uri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointment2> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointment2>
{
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

    HRESULT __stdcall get_CalendarId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CalendarId());
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

    HRESULT __stdcall put_RoamingId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RoamingId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OriginalStartTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OriginalStartTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsResponseRequested(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsResponseRequested());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsResponseRequested(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsResponseRequested(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowNewTimeProposal(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowNewTimeProposal());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowNewTimeProposal(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowNewTimeProposal(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OnlineMeetingLink(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OnlineMeetingLink());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OnlineMeetingLink(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnlineMeetingLink(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReplyTime(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReplyTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ReplyTime(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReplyTime(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserResponse(Windows::ApplicationModel::Appointments::AppointmentParticipantResponse * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserResponse());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UserResponse(Windows::ApplicationModel::Appointments::AppointmentParticipantResponse value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UserResponse(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasInvitees(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasInvitees());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCanceledMeeting(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCanceledMeeting());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsCanceledMeeting(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsCanceledMeeting(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsOrganizedByUser(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOrganizedByUser());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsOrganizedByUser(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsOrganizedByUser(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointment3> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointment3>
{
    HRESULT __stdcall get_ChangeNumber(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChangeNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemoteChangeNumber(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteChangeNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RemoteChangeNumber(uint64_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteChangeNumber(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DetailsKind(Windows::ApplicationModel::Appointments::AppointmentDetailsKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DetailsKind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DetailsKind(Windows::ApplicationModel::Appointments::AppointmentDetailsKind value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DetailsKind(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentCalendar> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentCalendar>
{
    HRESULT __stdcall get_DisplayColor(impl::abi_arg_out<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayColor());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
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

    HRESULT __stdcall get_IsHidden(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsHidden());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OtherAppReadAccess(Windows::ApplicationModel::Appointments::AppointmentCalendarOtherAppReadAccess * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OtherAppReadAccess());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OtherAppReadAccess(Windows::ApplicationModel::Appointments::AppointmentCalendarOtherAppReadAccess value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OtherAppReadAccess(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OtherAppWriteAccess(Windows::ApplicationModel::Appointments::AppointmentCalendarOtherAppWriteAccess * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OtherAppWriteAccess());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OtherAppWriteAccess(Windows::ApplicationModel::Appointments::AppointmentCalendarOtherAppWriteAccess value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OtherAppWriteAccess(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceDisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceDisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SummaryCardView(Windows::ApplicationModel::Appointments::AppointmentSummaryCardView * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SummaryCardView());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SummaryCardView(Windows::ApplicationModel::Appointments::AppointmentSummaryCardView value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SummaryCardView(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAppointmentsAsync(impl::abi_arg_in<Windows::Foundation::DateTime> rangeStart, impl::abi_arg_in<Windows::Foundation::TimeSpan> rangeLength, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindAppointmentsAsync(*reinterpret_cast<const Windows::Foundation::DateTime *>(&rangeStart), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&rangeLength)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAppointmentsAsyncWithOptions(impl::abi_arg_in<Windows::Foundation::DateTime> rangeStart, impl::abi_arg_in<Windows::Foundation::TimeSpan> rangeLength, impl::abi_arg_in<Windows::ApplicationModel::Appointments::IFindAppointmentsOptions> options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindAppointmentsAsync(*reinterpret_cast<const Windows::Foundation::DateTime *>(&rangeStart), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&rangeLength), *reinterpret_cast<const Windows::ApplicationModel::Appointments::FindAppointmentsOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindExceptionsFromMasterAsync(impl::abi_arg_in<hstring> masterLocalId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentException>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FindExceptionsFromMasterAsync(*reinterpret_cast<const hstring *>(&masterLocalId)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllInstancesAsync(impl::abi_arg_in<hstring> masterLocalId, impl::abi_arg_in<Windows::Foundation::DateTime> rangeStart, impl::abi_arg_in<Windows::Foundation::TimeSpan> rangeLength, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FindAllInstancesAsync(*reinterpret_cast<const hstring *>(&masterLocalId), *reinterpret_cast<const Windows::Foundation::DateTime *>(&rangeStart), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&rangeLength)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllInstancesAsyncWithOptions(impl::abi_arg_in<hstring> masterLocalId, impl::abi_arg_in<Windows::Foundation::DateTime> rangeStart, impl::abi_arg_in<Windows::Foundation::TimeSpan> rangeLength, impl::abi_arg_in<Windows::ApplicationModel::Appointments::IFindAppointmentsOptions> pOptions, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FindAllInstancesAsync(*reinterpret_cast<const hstring *>(&masterLocalId), *reinterpret_cast<const Windows::Foundation::DateTime *>(&rangeStart), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&rangeLength), *reinterpret_cast<const Windows::ApplicationModel::Appointments::FindAppointmentsOptions *>(&pOptions)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAppointmentAsync(impl::abi_arg_in<hstring> localId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::Appointment>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetAppointmentAsync(*reinterpret_cast<const hstring *>(&localId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAppointmentInstanceAsync(impl::abi_arg_in<hstring> localId, impl::abi_arg_in<Windows::Foundation::DateTime> instanceStartTime, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::Appointment>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetAppointmentInstanceAsync(*reinterpret_cast<const hstring *>(&localId), *reinterpret_cast<const Windows::Foundation::DateTime *>(&instanceStartTime)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindUnexpandedAppointmentsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindUnexpandedAppointmentsAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindUnexpandedAppointmentsAsyncWithOptions(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IFindAppointmentsOptions> options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindUnexpandedAppointmentsAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::FindAppointmentsOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_abi(this->shim().DeleteAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncAction = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_abi(this->shim().SaveAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncAction = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAppointmentAsync(impl::abi_arg_in<hstring> localId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_abi(this->shim().DeleteAppointmentAsync(*reinterpret_cast<const hstring *>(&localId)));
            return S_OK;
        }
        catch (...)
        {
            *asyncAction = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteAppointmentInstanceAsync(impl::abi_arg_in<hstring> localId, impl::abi_arg_in<Windows::Foundation::DateTime> instanceStartTime, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_abi(this->shim().DeleteAppointmentInstanceAsync(*reinterpret_cast<const hstring *>(&localId), *reinterpret_cast<const Windows::Foundation::DateTime *>(&instanceStartTime)));
            return S_OK;
        }
        catch (...)
        {
            *asyncAction = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SaveAppointmentAsync(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> pAppointment, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_abi(this->shim().SaveAppointmentAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&pAppointment)));
            return S_OK;
        }
        catch (...)
        {
            *asyncAction = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentCalendar2> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentCalendar2>
{
    HRESULT __stdcall get_SyncManager(impl::abi_arg_out<Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SyncManager());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemoteId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RemoteId(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoteId(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayColor(impl::abi_arg_in<Windows::UI::Color> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayColor(*reinterpret_cast<const Windows::UI::Color *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsHidden(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsHidden(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserDataAccountId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserDataAccountId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanCreateOrUpdateAppointments(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanCreateOrUpdateAppointments());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanCreateOrUpdateAppointments(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanCreateOrUpdateAppointments(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanCancelMeetings(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanCancelMeetings());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanCancelMeetings(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanCancelMeetings(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanForwardMeetings(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanForwardMeetings());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanForwardMeetings(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanForwardMeetings(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanProposeNewTimeForMeetings(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanProposeNewTimeForMeetings());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanProposeNewTimeForMeetings(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanProposeNewTimeForMeetings(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanUpdateMeetingResponses(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanUpdateMeetingResponses());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanUpdateMeetingResponses(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanUpdateMeetingResponses(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanNotifyInvitees(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanNotifyInvitees());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CanNotifyInvitees(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CanNotifyInvitees(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MustNofityInvitees(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MustNofityInvitees());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MustNofityInvitees(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MustNofityInvitees(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryCreateOrUpdateAppointmentAsync(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, bool notifyInvitees, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryCreateOrUpdateAppointmentAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment), notifyInvitees));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryCancelMeetingAsync(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> meeting, impl::abi_arg_in<hstring> subject, impl::abi_arg_in<hstring> comment, bool notifyInvitees, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryCancelMeetingAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&meeting), *reinterpret_cast<const hstring *>(&subject), *reinterpret_cast<const hstring *>(&comment), notifyInvitees));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryForwardMeetingAsync(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> meeting, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Appointments::AppointmentInvitee>> invitees, impl::abi_arg_in<hstring> subject, impl::abi_arg_in<hstring> forwardHeader, impl::abi_arg_in<hstring> comment, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryForwardMeetingAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&meeting), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::ApplicationModel::Appointments::AppointmentInvitee> *>(&invitees), *reinterpret_cast<const hstring *>(&subject), *reinterpret_cast<const hstring *>(&forwardHeader), *reinterpret_cast<const hstring *>(&comment)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryProposeNewTimeForMeetingAsync(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> meeting, impl::abi_arg_in<Windows::Foundation::DateTime> newStartTime, impl::abi_arg_in<Windows::Foundation::TimeSpan> newDuration, impl::abi_arg_in<hstring> subject, impl::abi_arg_in<hstring> comment, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryProposeNewTimeForMeetingAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&meeting), *reinterpret_cast<const Windows::Foundation::DateTime *>(&newStartTime), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&newDuration), *reinterpret_cast<const hstring *>(&subject), *reinterpret_cast<const hstring *>(&comment)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryUpdateMeetingResponseAsync(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> meeting, Windows::ApplicationModel::Appointments::AppointmentParticipantResponse response, impl::abi_arg_in<hstring> subject, impl::abi_arg_in<hstring> comment, bool sendUpdate, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryUpdateMeetingResponseAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&meeting), response, *reinterpret_cast<const hstring *>(&subject), *reinterpret_cast<const hstring *>(&comment), sendUpdate));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentCalendar3> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentCalendar3>
{
    HRESULT __stdcall abi_RegisterSyncManagerAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RegisterSyncManagerAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager>
{
    HRESULT __stdcall get_Status(Windows::ApplicationModel::Appointments::AppointmentCalendarSyncStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastSuccessfulSyncTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastSuccessfulSyncTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastAttemptedSyncTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastAttemptedSyncTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SyncAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SyncAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_SyncStatusChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::AppointmentCalendarSyncManager, Windows::Foundation::IInspectable>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().SyncStatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::AppointmentCalendarSyncManager, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_SyncStatusChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SyncStatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager2> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager2>
{
    HRESULT __stdcall put_Status(Windows::ApplicationModel::Appointments::AppointmentCalendarSyncStatus value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Status(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LastSuccessfulSyncTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LastSuccessfulSyncTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LastAttemptedSyncTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LastAttemptedSyncTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentConflictResult> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentConflictResult>
{
    HRESULT __stdcall get_Type(Windows::ApplicationModel::Appointments::AppointmentConflictType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Date(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Date());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentException> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentException>
{
    HRESULT __stdcall get_Appointment(impl::abi_arg_out<Windows::ApplicationModel::Appointments::IAppointment> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Appointment());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ExceptionProperties(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExceptionProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsDeleted(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsDeleted());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentInvitee> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentInvitee>
{
    HRESULT __stdcall get_Role(Windows::ApplicationModel::Appointments::AppointmentParticipantRole * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Role());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Role(Windows::ApplicationModel::Appointments::AppointmentParticipantRole value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Role(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Response(Windows::ApplicationModel::Appointments::AppointmentParticipantResponse * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Response());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Response(Windows::ApplicationModel::Appointments::AppointmentParticipantResponse value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Response(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentManagerForUser> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentManagerForUser>
{
    HRESULT __stdcall abi_ShowAddAppointmentAsync(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_in<Windows::Foundation::Rect> selection, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShowAddAppointmentAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAddAppointmentWithPlacementAsync(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShowAddAppointmentAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowReplaceAppointmentAsync(impl::abi_arg_in<hstring> appointmentId, impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_in<Windows::Foundation::Rect> selection, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShowReplaceAppointmentAsync(*reinterpret_cast<const hstring *>(&appointmentId), *reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowReplaceAppointmentWithPlacementAsync(impl::abi_arg_in<hstring> appointmentId, impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShowReplaceAppointmentAsync(*reinterpret_cast<const hstring *>(&appointmentId), *reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowReplaceAppointmentWithPlacementAndDateAsync(impl::abi_arg_in<hstring> appointmentId, impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_in<Windows::Foundation::DateTime> instanceStartDate, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShowReplaceAppointmentAsync(*reinterpret_cast<const hstring *>(&appointmentId), *reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement, *reinterpret_cast<const Windows::Foundation::DateTime *>(&instanceStartDate)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowRemoveAppointmentAsync(impl::abi_arg_in<hstring> appointmentId, impl::abi_arg_in<Windows::Foundation::Rect> selection, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShowRemoveAppointmentAsync(*reinterpret_cast<const hstring *>(&appointmentId), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowRemoveAppointmentWithPlacementAsync(impl::abi_arg_in<hstring> appointmentId, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShowRemoveAppointmentAsync(*reinterpret_cast<const hstring *>(&appointmentId), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowRemoveAppointmentWithPlacementAndDateAsync(impl::abi_arg_in<hstring> appointmentId, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_in<Windows::Foundation::DateTime> instanceStartDate, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShowRemoveAppointmentAsync(*reinterpret_cast<const hstring *>(&appointmentId), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement, *reinterpret_cast<const Windows::Foundation::DateTime *>(&instanceStartDate)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowTimeFrameAsync(impl::abi_arg_in<Windows::Foundation::DateTime> timeToShow, impl::abi_arg_in<Windows::Foundation::TimeSpan> duration, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShowTimeFrameAsync(*reinterpret_cast<const Windows::Foundation::DateTime *>(&timeToShow), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&duration)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAppointmentDetailsAsync(impl::abi_arg_in<hstring> appointmentId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShowAppointmentDetailsAsync(*reinterpret_cast<const hstring *>(&appointmentId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAppointmentDetailsWithDateAsync(impl::abi_arg_in<hstring> appointmentId, impl::abi_arg_in<Windows::Foundation::DateTime> instanceStartDate, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShowAppointmentDetailsAsync(*reinterpret_cast<const hstring *>(&appointmentId), *reinterpret_cast<const Windows::Foundation::DateTime *>(&instanceStartDate)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowEditNewAppointmentAsync(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ShowEditNewAppointmentAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestStoreAsync(Windows::ApplicationModel::Appointments::AppointmentStoreAccessType options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentStore>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestStoreAsync(options));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

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
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentManagerStatics> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentManagerStatics>
{
    HRESULT __stdcall abi_ShowAddAppointmentAsync(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_in<Windows::Foundation::Rect> selection, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowAddAppointmentAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAddAppointmentWithPlacementAsync(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowAddAppointmentAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowReplaceAppointmentAsync(impl::abi_arg_in<hstring> appointmentId, impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_in<Windows::Foundation::Rect> selection, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowReplaceAppointmentAsync(*reinterpret_cast<const hstring *>(&appointmentId), *reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowReplaceAppointmentWithPlacementAsync(impl::abi_arg_in<hstring> appointmentId, impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowReplaceAppointmentAsync(*reinterpret_cast<const hstring *>(&appointmentId), *reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowReplaceAppointmentWithPlacementAndDateAsync(impl::abi_arg_in<hstring> appointmentId, impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_in<Windows::Foundation::DateTime> instanceStartDate, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowReplaceAppointmentAsync(*reinterpret_cast<const hstring *>(&appointmentId), *reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement, *reinterpret_cast<const Windows::Foundation::DateTime *>(&instanceStartDate)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowRemoveAppointmentAsync(impl::abi_arg_in<hstring> appointmentId, impl::abi_arg_in<Windows::Foundation::Rect> selection, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowRemoveAppointmentAsync(*reinterpret_cast<const hstring *>(&appointmentId), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowRemoveAppointmentWithPlacementAsync(impl::abi_arg_in<hstring> appointmentId, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowRemoveAppointmentAsync(*reinterpret_cast<const hstring *>(&appointmentId), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowRemoveAppointmentWithPlacementAndDateAsync(impl::abi_arg_in<hstring> appointmentId, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_in<Windows::Foundation::DateTime> instanceStartDate, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowRemoveAppointmentAsync(*reinterpret_cast<const hstring *>(&appointmentId), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement, *reinterpret_cast<const Windows::Foundation::DateTime *>(&instanceStartDate)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowTimeFrameAsync(impl::abi_arg_in<Windows::Foundation::DateTime> timeToShow, impl::abi_arg_in<Windows::Foundation::TimeSpan> duration, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_abi(this->shim().ShowTimeFrameAsync(*reinterpret_cast<const Windows::Foundation::DateTime *>(&timeToShow), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&duration)));
            return S_OK;
        }
        catch (...)
        {
            *asyncAction = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentManagerStatics2> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentManagerStatics2>
{
    HRESULT __stdcall abi_ShowAppointmentDetailsAsync(impl::abi_arg_in<hstring> appointmentId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_abi(this->shim().ShowAppointmentDetailsAsync(*reinterpret_cast<const hstring *>(&appointmentId)));
            return S_OK;
        }
        catch (...)
        {
            *asyncAction = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAppointmentDetailsWithDateAsync(impl::abi_arg_in<hstring> appointmentId, impl::abi_arg_in<Windows::Foundation::DateTime> instanceStartDate, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_abi(this->shim().ShowAppointmentDetailsAsync(*reinterpret_cast<const hstring *>(&appointmentId), *reinterpret_cast<const Windows::Foundation::DateTime *>(&instanceStartDate)));
            return S_OK;
        }
        catch (...)
        {
            *asyncAction = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowEditNewAppointmentAsync(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowEditNewAppointmentAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestStoreAsync(Windows::ApplicationModel::Appointments::AppointmentStoreAccessType options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentStore>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().RequestStoreAsync(options));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentManagerStatics3> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentManagerStatics3>
{
    HRESULT __stdcall abi_GetForUser(impl::abi_arg_in<Windows::System::IUser> user, impl::abi_arg_out<Windows::ApplicationModel::Appointments::IAppointmentManagerForUser> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetForUser(*reinterpret_cast<const Windows::System::User *>(&user)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentParticipant> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentParticipant>
{
    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Address(impl::abi_arg_out<hstring> value) noexcept override
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

    HRESULT __stdcall put_Address(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Address(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentPropertiesStatics> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentPropertiesStatics>
{
    HRESULT __stdcall get_Subject(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Subject());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Location(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Location());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_StartTime(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Duration(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Duration());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Reminder(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Reminder());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BusyStatus(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BusyStatus());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Sensitivity(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Sensitivity());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OriginalStartTime(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OriginalStartTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsResponseRequested(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsResponseRequested());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllowNewTimeProposal(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowNewTimeProposal());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AllDay(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllDay());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Details(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Details());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OnlineMeetingLink(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OnlineMeetingLink());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReplyTime(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReplyTime());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Organizer(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Organizer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UserResponse(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UserResponse());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_HasInvitees(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().HasInvitees());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsCanceledMeeting(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsCanceledMeeting());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsOrganizedByUser(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsOrganizedByUser());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Recurrence(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Recurrence());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Uri(impl::abi_arg_out<hstring> value) noexcept override
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

    HRESULT __stdcall get_Invitees(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Invitees());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DefaultProperties(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DefaultProperties());
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
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentPropertiesStatics2> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentPropertiesStatics2>
{
    HRESULT __stdcall get_ChangeNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChangeNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemoteChangeNumber(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoteChangeNumber());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DetailsKind(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DetailsKind());
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
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentRecurrence> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentRecurrence>
{
    HRESULT __stdcall get_Unit(Windows::ApplicationModel::Appointments::AppointmentRecurrenceUnit * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Unit());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Unit(Windows::ApplicationModel::Appointments::AppointmentRecurrenceUnit value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Unit(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Occurrences(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Occurrences());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Occurrences(impl::abi_arg_in<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Occurrences(*reinterpret_cast<const Windows::Foundation::IReference<uint32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Until(impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Until());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Until(impl::abi_arg_in<Windows::Foundation::IReference<Windows::Foundation::DateTime>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Until(*reinterpret_cast<const Windows::Foundation::IReference<Windows::Foundation::DateTime> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Interval(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Interval());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Interval(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Interval(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DaysOfWeek(Windows::ApplicationModel::Appointments::AppointmentDaysOfWeek * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DaysOfWeek());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DaysOfWeek(Windows::ApplicationModel::Appointments::AppointmentDaysOfWeek value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DaysOfWeek(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_WeekOfMonth(Windows::ApplicationModel::Appointments::AppointmentWeekOfMonth * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().WeekOfMonth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_WeekOfMonth(Windows::ApplicationModel::Appointments::AppointmentWeekOfMonth value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WeekOfMonth(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Month(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Month());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Month(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Month(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Day(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Day());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Day(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Day(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentRecurrence2> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentRecurrence2>
{
    HRESULT __stdcall get_RecurrenceType(Windows::ApplicationModel::Appointments::RecurrenceType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RecurrenceType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TimeZone(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TimeZone());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TimeZone(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TimeZone(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentRecurrence3> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentRecurrence3>
{
    HRESULT __stdcall get_CalendarIdentifier(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CalendarIdentifier());
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
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentStore> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentStore>
{
    HRESULT __stdcall get_ChangeTracker(impl::abi_arg_out<Windows::ApplicationModel::Appointments::IAppointmentStoreChangeTracker> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChangeTracker());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAppointmentCalendarAsync(impl::abi_arg_in<hstring> name, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentCalendar>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateAppointmentCalendarAsync(*reinterpret_cast<const hstring *>(&name)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAppointmentCalendarAsync(impl::abi_arg_in<hstring> calendarId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentCalendar>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetAppointmentCalendarAsync(*reinterpret_cast<const hstring *>(&calendarId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAppointmentAsync(impl::abi_arg_in<hstring> localId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::Appointment>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetAppointmentAsync(*reinterpret_cast<const hstring *>(&localId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAppointmentInstanceAsync(impl::abi_arg_in<hstring> localId, impl::abi_arg_in<Windows::Foundation::DateTime> instanceStartTime, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::Appointment>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetAppointmentInstanceAsync(*reinterpret_cast<const hstring *>(&localId), *reinterpret_cast<const Windows::Foundation::DateTime *>(&instanceStartTime)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAppointmentCalendarsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentCalendar>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindAppointmentCalendarsAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAppointmentCalendarsAsyncWithOptions(Windows::ApplicationModel::Appointments::FindAppointmentCalendarsOptions options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentCalendar>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindAppointmentCalendarsAsync(options));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAppointmentsAsync(impl::abi_arg_in<Windows::Foundation::DateTime> rangeStart, impl::abi_arg_in<Windows::Foundation::TimeSpan> rangeLength, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindAppointmentsAsync(*reinterpret_cast<const Windows::Foundation::DateTime *>(&rangeStart), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&rangeLength)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAppointmentsAsyncWithOptions(impl::abi_arg_in<Windows::Foundation::DateTime> rangeStart, impl::abi_arg_in<Windows::Foundation::TimeSpan> rangeLength, impl::abi_arg_in<Windows::ApplicationModel::Appointments::IFindAppointmentsOptions> options, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindAppointmentsAsync(*reinterpret_cast<const Windows::Foundation::DateTime *>(&rangeStart), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&rangeLength), *reinterpret_cast<const Windows::ApplicationModel::Appointments::FindAppointmentsOptions *>(&options)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindConflictAsync(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentConflictResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindConflictAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindConflictAsyncWithInstanceStart(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_in<Windows::Foundation::DateTime> instanceStartTime, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentConflictResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindConflictAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment), *reinterpret_cast<const Windows::Foundation::DateTime *>(&instanceStartTime)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MoveAppointmentAsync(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointmentCalendar> destinationCalendar, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_abi(this->shim().MoveAppointmentAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment), *reinterpret_cast<const Windows::ApplicationModel::Appointments::AppointmentCalendar *>(&destinationCalendar)));
            return S_OK;
        }
        catch (...)
        {
            *asyncAction = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAddAppointmentAsync(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_in<Windows::Foundation::Rect> selection, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowAddAppointmentAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowReplaceAppointmentAsync(impl::abi_arg_in<hstring> localId, impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_in<Windows::Foundation::Rect> selection, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowReplaceAppointmentAsync(*reinterpret_cast<const hstring *>(&localId), *reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowReplaceAppointmentWithPlacementAndDateAsync(impl::abi_arg_in<hstring> localId, impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_in<Windows::Foundation::DateTime> instanceStartDate, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowReplaceAppointmentAsync(*reinterpret_cast<const hstring *>(&localId), *reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement, *reinterpret_cast<const Windows::Foundation::DateTime *>(&instanceStartDate)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowRemoveAppointmentAsync(impl::abi_arg_in<hstring> localId, impl::abi_arg_in<Windows::Foundation::Rect> selection, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowRemoveAppointmentAsync(*reinterpret_cast<const hstring *>(&localId), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowRemoveAppointmentWithPlacementAndDateAsync(impl::abi_arg_in<hstring> localId, impl::abi_arg_in<Windows::Foundation::Rect> selection, Windows::UI::Popups::Placement preferredPlacement, impl::abi_arg_in<Windows::Foundation::DateTime> instanceStartDate, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowRemoveAppointmentAsync(*reinterpret_cast<const hstring *>(&localId), *reinterpret_cast<const Windows::Foundation::Rect *>(&selection), preferredPlacement, *reinterpret_cast<const Windows::Foundation::DateTime *>(&instanceStartDate)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAppointmentDetailsAsync(impl::abi_arg_in<hstring> localId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_abi(this->shim().ShowAppointmentDetailsAsync(*reinterpret_cast<const hstring *>(&localId)));
            return S_OK;
        }
        catch (...)
        {
            *asyncAction = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowAppointmentDetailsWithDateAsync(impl::abi_arg_in<hstring> localId, impl::abi_arg_in<Windows::Foundation::DateTime> instanceStartDate, impl::abi_arg_out<Windows::Foundation::IAsyncAction> asyncAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_abi(this->shim().ShowAppointmentDetailsAsync(*reinterpret_cast<const hstring *>(&localId), *reinterpret_cast<const Windows::Foundation::DateTime *>(&instanceStartDate)));
            return S_OK;
        }
        catch (...)
        {
            *asyncAction = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ShowEditNewAppointmentAsync(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointment> appointment, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ShowEditNewAppointmentAsync(*reinterpret_cast<const Windows::ApplicationModel::Appointments::Appointment *>(&appointment)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindLocalIdsFromRoamingIdAsync(impl::abi_arg_in<hstring> roamingId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FindLocalIdsFromRoamingIdAsync(*reinterpret_cast<const hstring *>(&roamingId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentStore2> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentStore2>
{
    HRESULT __stdcall add_StoreChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::AppointmentStore, Windows::ApplicationModel::Appointments::AppointmentStoreChangedEventArgs>> pHandler, event_token * pToken) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *pToken = detach_abi(this->shim().StoreChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::AppointmentStore, Windows::ApplicationModel::Appointments::AppointmentStoreChangedEventArgs> *>(&pHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StoreChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StoreChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAppointmentCalendarInAccountAsync(impl::abi_arg_in<hstring> name, impl::abi_arg_in<hstring> userDataAccountId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentCalendar>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CreateAppointmentCalendarAsync(*reinterpret_cast<const hstring *>(&name), *reinterpret_cast<const hstring *>(&userDataAccountId)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentStoreChange> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentStoreChange>
{
    HRESULT __stdcall get_Appointment(impl::abi_arg_out<Windows::ApplicationModel::Appointments::IAppointment> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Appointment());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ChangeType(Windows::ApplicationModel::Appointments::AppointmentStoreChangeType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChangeType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentStoreChange2> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentStoreChange2>
{
    HRESULT __stdcall get_AppointmentCalendar(impl::abi_arg_out<Windows::ApplicationModel::Appointments::IAppointmentCalendar> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppointmentCalendar());
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
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentStoreChangeReader> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentStoreChangeReader>
{
    HRESULT __stdcall abi_ReadBatchAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentStoreChange>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ReadBatchAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AcceptChanges() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcceptChanges();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AcceptChangesThrough(impl::abi_arg_in<Windows::ApplicationModel::Appointments::IAppointmentStoreChange> lastChangeToAccept) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcceptChangesThrough(*reinterpret_cast<const Windows::ApplicationModel::Appointments::AppointmentStoreChange *>(&lastChangeToAccept));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentStoreChangeTracker> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentStoreChangeTracker>
{
    HRESULT __stdcall abi_GetChangeReader(impl::abi_arg_out<Windows::ApplicationModel::Appointments::IAppointmentStoreChangeReader> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetChangeReader());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Enable() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Enable();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Reset() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Reset();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentStoreChangedDeferral> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentStoreChangedDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentStoreChangedEventArgs> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentStoreChangedEventArgs>
{
    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::ApplicationModel::Appointments::IAppointmentStoreChangedDeferral> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IAppointmentStoreNotificationTriggerDetails> : produce_base<D, Windows::ApplicationModel::Appointments::IAppointmentStoreNotificationTriggerDetails>
{};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::IFindAppointmentsOptions> : produce_base<D, Windows::ApplicationModel::Appointments::IFindAppointmentsOptions>
{
    HRESULT __stdcall get_CalendarIds(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CalendarIds());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_FetchProperties(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FetchProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IncludeHidden(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IncludeHidden());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IncludeHidden(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IncludeHidden(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxCount(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxCount());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxCount(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxCount(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Appointments {

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IAppointmentManagerStatics<D>::ShowAddAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IAppointmentManagerStatics)->abi_ShowAddAppointmentAsync(get_abi(appointment), get_abi(selection), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IAppointmentManagerStatics<D>::ShowAddAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IAppointmentManagerStatics)->abi_ShowAddAppointmentWithPlacementAsync(get_abi(appointment), get_abi(selection), preferredPlacement, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IAppointmentManagerStatics<D>::ShowReplaceAppointmentAsync(hstring_view appointmentId, const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IAppointmentManagerStatics)->abi_ShowReplaceAppointmentAsync(get_abi(appointmentId), get_abi(appointment), get_abi(selection), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IAppointmentManagerStatics<D>::ShowReplaceAppointmentAsync(hstring_view appointmentId, const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IAppointmentManagerStatics)->abi_ShowReplaceAppointmentWithPlacementAsync(get_abi(appointmentId), get_abi(appointment), get_abi(selection), preferredPlacement, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IAppointmentManagerStatics<D>::ShowReplaceAppointmentAsync(hstring_view appointmentId, const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::Foundation::DateTime & instanceStartDate) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IAppointmentManagerStatics)->abi_ShowReplaceAppointmentWithPlacementAndDateAsync(get_abi(appointmentId), get_abi(appointment), get_abi(selection), preferredPlacement, get_abi(instanceStartDate), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppointmentManagerStatics<D>::ShowRemoveAppointmentAsync(hstring_view appointmentId, const Windows::Foundation::Rect & selection) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IAppointmentManagerStatics)->abi_ShowRemoveAppointmentAsync(get_abi(appointmentId), get_abi(selection), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppointmentManagerStatics<D>::ShowRemoveAppointmentAsync(hstring_view appointmentId, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IAppointmentManagerStatics)->abi_ShowRemoveAppointmentWithPlacementAsync(get_abi(appointmentId), get_abi(selection), preferredPlacement, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppointmentManagerStatics<D>::ShowRemoveAppointmentAsync(hstring_view appointmentId, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::Foundation::DateTime & instanceStartDate) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IAppointmentManagerStatics)->abi_ShowRemoveAppointmentWithPlacementAndDateAsync(get_abi(appointmentId), get_abi(selection), preferredPlacement, get_abi(instanceStartDate), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAppointmentManagerStatics<D>::ShowTimeFrameAsync(const Windows::Foundation::DateTime & timeToShow, const Windows::Foundation::TimeSpan & duration) const
{
    Windows::Foundation::IAsyncAction asyncAction;
    check_hresult(WINRT_SHIM(IAppointmentManagerStatics)->abi_ShowTimeFrameAsync(get_abi(timeToShow), get_abi(duration), put_abi(asyncAction)));
    return asyncAction;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAppointmentManagerStatics2<D>::ShowAppointmentDetailsAsync(hstring_view appointmentId) const
{
    Windows::Foundation::IAsyncAction asyncAction;
    check_hresult(WINRT_SHIM(IAppointmentManagerStatics2)->abi_ShowAppointmentDetailsAsync(get_abi(appointmentId), put_abi(asyncAction)));
    return asyncAction;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAppointmentManagerStatics2<D>::ShowAppointmentDetailsAsync(hstring_view appointmentId, const Windows::Foundation::DateTime & instanceStartDate) const
{
    Windows::Foundation::IAsyncAction asyncAction;
    check_hresult(WINRT_SHIM(IAppointmentManagerStatics2)->abi_ShowAppointmentDetailsWithDateAsync(get_abi(appointmentId), get_abi(instanceStartDate), put_abi(asyncAction)));
    return asyncAction;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IAppointmentManagerStatics2<D>::ShowEditNewAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IAppointmentManagerStatics2)->abi_ShowEditNewAppointmentAsync(get_abi(appointment), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentStore> impl_IAppointmentManagerStatics2<D>::RequestStoreAsync(Windows::ApplicationModel::Appointments::AppointmentStoreAccessType options) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentStore> operation;
    check_hresult(WINRT_SHIM(IAppointmentManagerStatics2)->abi_RequestStoreAsync(options, put_abi(operation)));
    return operation;
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentManagerForUser impl_IAppointmentManagerStatics3<D>::GetForUser(const Windows::System::User & user) const
{
    Windows::ApplicationModel::Appointments::AppointmentManagerForUser result { nullptr };
    check_hresult(WINRT_SHIM(IAppointmentManagerStatics3)->abi_GetForUser(get_abi(user), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IAppointmentManagerForUser<D>::ShowAddAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection) const
{
    Windows::Foundation::IAsyncOperation<hstring> result;
    check_hresult(WINRT_SHIM(IAppointmentManagerForUser)->abi_ShowAddAppointmentAsync(get_abi(appointment), get_abi(selection), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IAppointmentManagerForUser<D>::ShowAddAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const
{
    Windows::Foundation::IAsyncOperation<hstring> result;
    check_hresult(WINRT_SHIM(IAppointmentManagerForUser)->abi_ShowAddAppointmentWithPlacementAsync(get_abi(appointment), get_abi(selection), preferredPlacement, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IAppointmentManagerForUser<D>::ShowReplaceAppointmentAsync(hstring_view appointmentId, const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection) const
{
    Windows::Foundation::IAsyncOperation<hstring> result;
    check_hresult(WINRT_SHIM(IAppointmentManagerForUser)->abi_ShowReplaceAppointmentAsync(get_abi(appointmentId), get_abi(appointment), get_abi(selection), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IAppointmentManagerForUser<D>::ShowReplaceAppointmentAsync(hstring_view appointmentId, const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const
{
    Windows::Foundation::IAsyncOperation<hstring> result;
    check_hresult(WINRT_SHIM(IAppointmentManagerForUser)->abi_ShowReplaceAppointmentWithPlacementAsync(get_abi(appointmentId), get_abi(appointment), get_abi(selection), preferredPlacement, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IAppointmentManagerForUser<D>::ShowReplaceAppointmentAsync(hstring_view appointmentId, const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::Foundation::DateTime & instanceStartDate) const
{
    Windows::Foundation::IAsyncOperation<hstring> result;
    check_hresult(WINRT_SHIM(IAppointmentManagerForUser)->abi_ShowReplaceAppointmentWithPlacementAndDateAsync(get_abi(appointmentId), get_abi(appointment), get_abi(selection), preferredPlacement, get_abi(instanceStartDate), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppointmentManagerForUser<D>::ShowRemoveAppointmentAsync(hstring_view appointmentId, const Windows::Foundation::Rect & selection) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IAppointmentManagerForUser)->abi_ShowRemoveAppointmentAsync(get_abi(appointmentId), get_abi(selection), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppointmentManagerForUser<D>::ShowRemoveAppointmentAsync(hstring_view appointmentId, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IAppointmentManagerForUser)->abi_ShowRemoveAppointmentWithPlacementAsync(get_abi(appointmentId), get_abi(selection), preferredPlacement, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppointmentManagerForUser<D>::ShowRemoveAppointmentAsync(hstring_view appointmentId, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::Foundation::DateTime & instanceStartDate) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IAppointmentManagerForUser)->abi_ShowRemoveAppointmentWithPlacementAndDateAsync(get_abi(appointmentId), get_abi(selection), preferredPlacement, get_abi(instanceStartDate), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAppointmentManagerForUser<D>::ShowTimeFrameAsync(const Windows::Foundation::DateTime & timeToShow, const Windows::Foundation::TimeSpan & duration) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IAppointmentManagerForUser)->abi_ShowTimeFrameAsync(get_abi(timeToShow), get_abi(duration), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAppointmentManagerForUser<D>::ShowAppointmentDetailsAsync(hstring_view appointmentId) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IAppointmentManagerForUser)->abi_ShowAppointmentDetailsAsync(get_abi(appointmentId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAppointmentManagerForUser<D>::ShowAppointmentDetailsAsync(hstring_view appointmentId, const Windows::Foundation::DateTime & instanceStartDate) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IAppointmentManagerForUser)->abi_ShowAppointmentDetailsWithDateAsync(get_abi(appointmentId), get_abi(instanceStartDate), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IAppointmentManagerForUser<D>::ShowEditNewAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment) const
{
    Windows::Foundation::IAsyncOperation<hstring> result;
    check_hresult(WINRT_SHIM(IAppointmentManagerForUser)->abi_ShowEditNewAppointmentAsync(get_abi(appointment), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentStore> impl_IAppointmentManagerForUser<D>::RequestStoreAsync(Windows::ApplicationModel::Appointments::AppointmentStoreAccessType options) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentStore> result;
    check_hresult(WINRT_SHIM(IAppointmentManagerForUser)->abi_RequestStoreAsync(options, put_abi(result)));
    return result;
}

template <typename D> Windows::System::User impl_IAppointmentManagerForUser<D>::User() const
{
    Windows::System::User value { nullptr };
    check_hresult(WINRT_SHIM(IAppointmentManagerForUser)->get_User(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentParticipant<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentParticipant)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointmentParticipant<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAppointmentParticipant)->put_DisplayName(get_abi(value)));
}

template <typename D> hstring impl_IAppointmentParticipant<D>::Address() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentParticipant)->get_Address(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointmentParticipant<D>::Address(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAppointmentParticipant)->put_Address(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentParticipantRole impl_IAppointmentInvitee<D>::Role() const
{
    Windows::ApplicationModel::Appointments::AppointmentParticipantRole value {};
    check_hresult(WINRT_SHIM(IAppointmentInvitee)->get_Role(&value));
    return value;
}

template <typename D> void impl_IAppointmentInvitee<D>::Role(Windows::ApplicationModel::Appointments::AppointmentParticipantRole value) const
{
    check_hresult(WINRT_SHIM(IAppointmentInvitee)->put_Role(value));
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentParticipantResponse impl_IAppointmentInvitee<D>::Response() const
{
    Windows::ApplicationModel::Appointments::AppointmentParticipantResponse value {};
    check_hresult(WINRT_SHIM(IAppointmentInvitee)->get_Response(&value));
    return value;
}

template <typename D> void impl_IAppointmentInvitee<D>::Response(Windows::ApplicationModel::Appointments::AppointmentParticipantResponse value) const
{
    check_hresult(WINRT_SHIM(IAppointmentInvitee)->put_Response(value));
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentRecurrenceUnit impl_IAppointmentRecurrence<D>::Unit() const
{
    Windows::ApplicationModel::Appointments::AppointmentRecurrenceUnit value {};
    check_hresult(WINRT_SHIM(IAppointmentRecurrence)->get_Unit(&value));
    return value;
}

template <typename D> void impl_IAppointmentRecurrence<D>::Unit(Windows::ApplicationModel::Appointments::AppointmentRecurrenceUnit value) const
{
    check_hresult(WINRT_SHIM(IAppointmentRecurrence)->put_Unit(value));
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_IAppointmentRecurrence<D>::Occurrences() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(IAppointmentRecurrence)->get_Occurrences(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointmentRecurrence<D>::Occurrences(const optional<uint32_t> & value) const
{
    check_hresult(WINRT_SHIM(IAppointmentRecurrence)->put_Occurrences(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IAppointmentRecurrence<D>::Until() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IAppointmentRecurrence)->get_Until(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointmentRecurrence<D>::Until(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IAppointmentRecurrence)->put_Until(get_abi(value)));
}

template <typename D> uint32_t impl_IAppointmentRecurrence<D>::Interval() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IAppointmentRecurrence)->get_Interval(&value));
    return value;
}

template <typename D> void impl_IAppointmentRecurrence<D>::Interval(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IAppointmentRecurrence)->put_Interval(value));
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentDaysOfWeek impl_IAppointmentRecurrence<D>::DaysOfWeek() const
{
    Windows::ApplicationModel::Appointments::AppointmentDaysOfWeek value {};
    check_hresult(WINRT_SHIM(IAppointmentRecurrence)->get_DaysOfWeek(&value));
    return value;
}

template <typename D> void impl_IAppointmentRecurrence<D>::DaysOfWeek(Windows::ApplicationModel::Appointments::AppointmentDaysOfWeek value) const
{
    check_hresult(WINRT_SHIM(IAppointmentRecurrence)->put_DaysOfWeek(value));
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentWeekOfMonth impl_IAppointmentRecurrence<D>::WeekOfMonth() const
{
    Windows::ApplicationModel::Appointments::AppointmentWeekOfMonth value {};
    check_hresult(WINRT_SHIM(IAppointmentRecurrence)->get_WeekOfMonth(&value));
    return value;
}

template <typename D> void impl_IAppointmentRecurrence<D>::WeekOfMonth(Windows::ApplicationModel::Appointments::AppointmentWeekOfMonth value) const
{
    check_hresult(WINRT_SHIM(IAppointmentRecurrence)->put_WeekOfMonth(value));
}

template <typename D> uint32_t impl_IAppointmentRecurrence<D>::Month() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IAppointmentRecurrence)->get_Month(&value));
    return value;
}

template <typename D> void impl_IAppointmentRecurrence<D>::Month(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IAppointmentRecurrence)->put_Month(value));
}

template <typename D> uint32_t impl_IAppointmentRecurrence<D>::Day() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IAppointmentRecurrence)->get_Day(&value));
    return value;
}

template <typename D> void impl_IAppointmentRecurrence<D>::Day(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IAppointmentRecurrence)->put_Day(value));
}

template <typename D> Windows::ApplicationModel::Appointments::RecurrenceType impl_IAppointmentRecurrence2<D>::RecurrenceType() const
{
    Windows::ApplicationModel::Appointments::RecurrenceType value {};
    check_hresult(WINRT_SHIM(IAppointmentRecurrence2)->get_RecurrenceType(&value));
    return value;
}

template <typename D> hstring impl_IAppointmentRecurrence2<D>::TimeZone() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentRecurrence2)->get_TimeZone(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointmentRecurrence2<D>::TimeZone(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAppointmentRecurrence2)->put_TimeZone(get_abi(value)));
}

template <typename D> hstring impl_IAppointmentRecurrence3<D>::CalendarIdentifier() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentRecurrence3)->get_CalendarIdentifier(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IAppointment<D>::StartTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IAppointment)->get_StartTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointment<D>::StartTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IAppointment)->put_StartTime(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_IAppointment<D>::Duration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IAppointment)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointment<D>::Duration(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IAppointment)->put_Duration(get_abi(value)));
}

template <typename D> hstring impl_IAppointment<D>::Location() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointment)->get_Location(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointment<D>::Location(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAppointment)->put_Location(get_abi(value)));
}

template <typename D> hstring impl_IAppointment<D>::Subject() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointment)->get_Subject(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointment<D>::Subject(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAppointment)->put_Subject(get_abi(value)));
}

template <typename D> hstring impl_IAppointment<D>::Details() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointment)->get_Details(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointment<D>::Details(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAppointment)->put_Details(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::TimeSpan> impl_IAppointment<D>::Reminder() const
{
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> value;
    check_hresult(WINRT_SHIM(IAppointment)->get_Reminder(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointment<D>::Reminder(const optional<Windows::Foundation::TimeSpan> & value) const
{
    check_hresult(WINRT_SHIM(IAppointment)->put_Reminder(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentOrganizer impl_IAppointment<D>::Organizer() const
{
    Windows::ApplicationModel::Appointments::AppointmentOrganizer value { nullptr };
    check_hresult(WINRT_SHIM(IAppointment)->get_Organizer(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointment<D>::Organizer(const Windows::ApplicationModel::Appointments::AppointmentOrganizer & value) const
{
    check_hresult(WINRT_SHIM(IAppointment)->put_Organizer(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Appointments::AppointmentInvitee> impl_IAppointment<D>::Invitees() const
{
    Windows::Foundation::Collections::IVector<Windows::ApplicationModel::Appointments::AppointmentInvitee> value;
    check_hresult(WINRT_SHIM(IAppointment)->get_Invitees(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentRecurrence impl_IAppointment<D>::Recurrence() const
{
    Windows::ApplicationModel::Appointments::AppointmentRecurrence value { nullptr };
    check_hresult(WINRT_SHIM(IAppointment)->get_Recurrence(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointment<D>::Recurrence(const Windows::ApplicationModel::Appointments::AppointmentRecurrence & value) const
{
    check_hresult(WINRT_SHIM(IAppointment)->put_Recurrence(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentBusyStatus impl_IAppointment<D>::BusyStatus() const
{
    Windows::ApplicationModel::Appointments::AppointmentBusyStatus value {};
    check_hresult(WINRT_SHIM(IAppointment)->get_BusyStatus(&value));
    return value;
}

template <typename D> void impl_IAppointment<D>::BusyStatus(Windows::ApplicationModel::Appointments::AppointmentBusyStatus value) const
{
    check_hresult(WINRT_SHIM(IAppointment)->put_BusyStatus(value));
}

template <typename D> bool impl_IAppointment<D>::AllDay() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppointment)->get_AllDay(&value));
    return value;
}

template <typename D> void impl_IAppointment<D>::AllDay(bool value) const
{
    check_hresult(WINRT_SHIM(IAppointment)->put_AllDay(value));
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentSensitivity impl_IAppointment<D>::Sensitivity() const
{
    Windows::ApplicationModel::Appointments::AppointmentSensitivity value {};
    check_hresult(WINRT_SHIM(IAppointment)->get_Sensitivity(&value));
    return value;
}

template <typename D> void impl_IAppointment<D>::Sensitivity(Windows::ApplicationModel::Appointments::AppointmentSensitivity value) const
{
    check_hresult(WINRT_SHIM(IAppointment)->put_Sensitivity(value));
}

template <typename D> Windows::Foundation::Uri impl_IAppointment<D>::Uri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IAppointment)->get_Uri(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointment<D>::Uri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IAppointment)->put_Uri(get_abi(value)));
}

template <typename D> hstring impl_IAppointment2<D>::LocalId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointment2)->get_LocalId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointment2<D>::CalendarId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointment2)->get_CalendarId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointment2<D>::RoamingId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointment2)->get_RoamingId(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointment2<D>::RoamingId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAppointment2)->put_RoamingId(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IAppointment2<D>::OriginalStartTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IAppointment2)->get_OriginalStartTime(put_abi(value)));
    return value;
}

template <typename D> bool impl_IAppointment2<D>::IsResponseRequested() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppointment2)->get_IsResponseRequested(&value));
    return value;
}

template <typename D> void impl_IAppointment2<D>::IsResponseRequested(bool value) const
{
    check_hresult(WINRT_SHIM(IAppointment2)->put_IsResponseRequested(value));
}

template <typename D> bool impl_IAppointment2<D>::AllowNewTimeProposal() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppointment2)->get_AllowNewTimeProposal(&value));
    return value;
}

template <typename D> void impl_IAppointment2<D>::AllowNewTimeProposal(bool value) const
{
    check_hresult(WINRT_SHIM(IAppointment2)->put_AllowNewTimeProposal(value));
}

template <typename D> hstring impl_IAppointment2<D>::OnlineMeetingLink() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointment2)->get_OnlineMeetingLink(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointment2<D>::OnlineMeetingLink(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAppointment2)->put_OnlineMeetingLink(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IAppointment2<D>::ReplyTime() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IAppointment2)->get_ReplyTime(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointment2<D>::ReplyTime(const optional<Windows::Foundation::DateTime> & value) const
{
    check_hresult(WINRT_SHIM(IAppointment2)->put_ReplyTime(get_abi(value)));
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentParticipantResponse impl_IAppointment2<D>::UserResponse() const
{
    Windows::ApplicationModel::Appointments::AppointmentParticipantResponse value {};
    check_hresult(WINRT_SHIM(IAppointment2)->get_UserResponse(&value));
    return value;
}

template <typename D> void impl_IAppointment2<D>::UserResponse(Windows::ApplicationModel::Appointments::AppointmentParticipantResponse value) const
{
    check_hresult(WINRT_SHIM(IAppointment2)->put_UserResponse(value));
}

template <typename D> bool impl_IAppointment2<D>::HasInvitees() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppointment2)->get_HasInvitees(&value));
    return value;
}

template <typename D> bool impl_IAppointment2<D>::IsCanceledMeeting() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppointment2)->get_IsCanceledMeeting(&value));
    return value;
}

template <typename D> void impl_IAppointment2<D>::IsCanceledMeeting(bool value) const
{
    check_hresult(WINRT_SHIM(IAppointment2)->put_IsCanceledMeeting(value));
}

template <typename D> bool impl_IAppointment2<D>::IsOrganizedByUser() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppointment2)->get_IsOrganizedByUser(&value));
    return value;
}

template <typename D> void impl_IAppointment2<D>::IsOrganizedByUser(bool value) const
{
    check_hresult(WINRT_SHIM(IAppointment2)->put_IsOrganizedByUser(value));
}

template <typename D> uint64_t impl_IAppointment3<D>::ChangeNumber() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IAppointment3)->get_ChangeNumber(&value));
    return value;
}

template <typename D> uint64_t impl_IAppointment3<D>::RemoteChangeNumber() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IAppointment3)->get_RemoteChangeNumber(&value));
    return value;
}

template <typename D> void impl_IAppointment3<D>::RemoteChangeNumber(uint64_t value) const
{
    check_hresult(WINRT_SHIM(IAppointment3)->put_RemoteChangeNumber(value));
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentDetailsKind impl_IAppointment3<D>::DetailsKind() const
{
    Windows::ApplicationModel::Appointments::AppointmentDetailsKind value {};
    check_hresult(WINRT_SHIM(IAppointment3)->get_DetailsKind(&value));
    return value;
}

template <typename D> void impl_IAppointment3<D>::DetailsKind(Windows::ApplicationModel::Appointments::AppointmentDetailsKind value) const
{
    check_hresult(WINRT_SHIM(IAppointment3)->put_DetailsKind(value));
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IFindAppointmentsOptions<D>::CalendarIds() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IFindAppointmentsOptions)->get_CalendarIds(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IFindAppointmentsOptions<D>::FetchProperties() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IFindAppointmentsOptions)->get_FetchProperties(put_abi(value)));
    return value;
}

template <typename D> bool impl_IFindAppointmentsOptions<D>::IncludeHidden() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IFindAppointmentsOptions)->get_IncludeHidden(&value));
    return value;
}

template <typename D> void impl_IFindAppointmentsOptions<D>::IncludeHidden(bool value) const
{
    check_hresult(WINRT_SHIM(IFindAppointmentsOptions)->put_IncludeHidden(value));
}

template <typename D> uint32_t impl_IFindAppointmentsOptions<D>::MaxCount() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IFindAppointmentsOptions)->get_MaxCount(&value));
    return value;
}

template <typename D> void impl_IFindAppointmentsOptions<D>::MaxCount(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IFindAppointmentsOptions)->put_MaxCount(value));
}

template <typename D> Windows::UI::Color impl_IAppointmentCalendar<D>::DisplayColor() const
{
    Windows::UI::Color value {};
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->get_DisplayColor(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentCalendar<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointmentCalendar<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->put_DisplayName(get_abi(value)));
}

template <typename D> hstring impl_IAppointmentCalendar<D>::LocalId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->get_LocalId(put_abi(value)));
    return value;
}

template <typename D> bool impl_IAppointmentCalendar<D>::IsHidden() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->get_IsHidden(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentCalendarOtherAppReadAccess impl_IAppointmentCalendar<D>::OtherAppReadAccess() const
{
    Windows::ApplicationModel::Appointments::AppointmentCalendarOtherAppReadAccess value {};
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->get_OtherAppReadAccess(&value));
    return value;
}

template <typename D> void impl_IAppointmentCalendar<D>::OtherAppReadAccess(Windows::ApplicationModel::Appointments::AppointmentCalendarOtherAppReadAccess value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->put_OtherAppReadAccess(value));
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentCalendarOtherAppWriteAccess impl_IAppointmentCalendar<D>::OtherAppWriteAccess() const
{
    Windows::ApplicationModel::Appointments::AppointmentCalendarOtherAppWriteAccess value {};
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->get_OtherAppWriteAccess(&value));
    return value;
}

template <typename D> void impl_IAppointmentCalendar<D>::OtherAppWriteAccess(Windows::ApplicationModel::Appointments::AppointmentCalendarOtherAppWriteAccess value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->put_OtherAppWriteAccess(value));
}

template <typename D> hstring impl_IAppointmentCalendar<D>::SourceDisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->get_SourceDisplayName(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentSummaryCardView impl_IAppointmentCalendar<D>::SummaryCardView() const
{
    Windows::ApplicationModel::Appointments::AppointmentSummaryCardView value {};
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->get_SummaryCardView(&value));
    return value;
}

template <typename D> void impl_IAppointmentCalendar<D>::SummaryCardView(Windows::ApplicationModel::Appointments::AppointmentSummaryCardView value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->put_SummaryCardView(value));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> impl_IAppointmentCalendar<D>::FindAppointmentsAsync(const Windows::Foundation::DateTime & rangeStart, const Windows::Foundation::TimeSpan & rangeLength) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> result;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->abi_FindAppointmentsAsync(get_abi(rangeStart), get_abi(rangeLength), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> impl_IAppointmentCalendar<D>::FindAppointmentsAsync(const Windows::Foundation::DateTime & rangeStart, const Windows::Foundation::TimeSpan & rangeLength, const Windows::ApplicationModel::Appointments::FindAppointmentsOptions & options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> result;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->abi_FindAppointmentsAsyncWithOptions(get_abi(rangeStart), get_abi(rangeLength), get_abi(options), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentException>> impl_IAppointmentCalendar<D>::FindExceptionsFromMasterAsync(hstring_view masterLocalId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentException>> value;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->abi_FindExceptionsFromMasterAsync(get_abi(masterLocalId), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> impl_IAppointmentCalendar<D>::FindAllInstancesAsync(hstring_view masterLocalId, const Windows::Foundation::DateTime & rangeStart, const Windows::Foundation::TimeSpan & rangeLength) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> value;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->abi_FindAllInstancesAsync(get_abi(masterLocalId), get_abi(rangeStart), get_abi(rangeLength), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> impl_IAppointmentCalendar<D>::FindAllInstancesAsync(hstring_view masterLocalId, const Windows::Foundation::DateTime & rangeStart, const Windows::Foundation::TimeSpan & rangeLength, const Windows::ApplicationModel::Appointments::FindAppointmentsOptions & pOptions) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> value;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->abi_FindAllInstancesAsyncWithOptions(get_abi(masterLocalId), get_abi(rangeStart), get_abi(rangeLength), get_abi(pOptions), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::Appointment> impl_IAppointmentCalendar<D>::GetAppointmentAsync(hstring_view localId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::Appointment> result;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->abi_GetAppointmentAsync(get_abi(localId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::Appointment> impl_IAppointmentCalendar<D>::GetAppointmentInstanceAsync(hstring_view localId, const Windows::Foundation::DateTime & instanceStartTime) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::Appointment> result;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->abi_GetAppointmentInstanceAsync(get_abi(localId), get_abi(instanceStartTime), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> impl_IAppointmentCalendar<D>::FindUnexpandedAppointmentsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> result;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->abi_FindUnexpandedAppointmentsAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> impl_IAppointmentCalendar<D>::FindUnexpandedAppointmentsAsync(const Windows::ApplicationModel::Appointments::FindAppointmentsOptions & options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> result;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->abi_FindUnexpandedAppointmentsAsyncWithOptions(get_abi(options), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAppointmentCalendar<D>::DeleteAsync() const
{
    Windows::Foundation::IAsyncAction asyncAction;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->abi_DeleteAsync(put_abi(asyncAction)));
    return asyncAction;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAppointmentCalendar<D>::SaveAsync() const
{
    Windows::Foundation::IAsyncAction asyncAction;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->abi_SaveAsync(put_abi(asyncAction)));
    return asyncAction;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAppointmentCalendar<D>::DeleteAppointmentAsync(hstring_view localId) const
{
    Windows::Foundation::IAsyncAction asyncAction;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->abi_DeleteAppointmentAsync(get_abi(localId), put_abi(asyncAction)));
    return asyncAction;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAppointmentCalendar<D>::DeleteAppointmentInstanceAsync(hstring_view localId, const Windows::Foundation::DateTime & instanceStartTime) const
{
    Windows::Foundation::IAsyncAction asyncAction;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->abi_DeleteAppointmentInstanceAsync(get_abi(localId), get_abi(instanceStartTime), put_abi(asyncAction)));
    return asyncAction;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAppointmentCalendar<D>::SaveAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & pAppointment) const
{
    Windows::Foundation::IAsyncAction asyncAction;
    check_hresult(WINRT_SHIM(IAppointmentCalendar)->abi_SaveAppointmentAsync(get_abi(pAppointment), put_abi(asyncAction)));
    return asyncAction;
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentCalendarSyncManager impl_IAppointmentCalendar2<D>::SyncManager() const
{
    Windows::ApplicationModel::Appointments::AppointmentCalendarSyncManager value { nullptr };
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->get_SyncManager(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentCalendar2<D>::RemoteId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->get_RemoteId(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointmentCalendar2<D>::RemoteId(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->put_RemoteId(get_abi(value)));
}

template <typename D> void impl_IAppointmentCalendar2<D>::DisplayColor(const Windows::UI::Color & value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->put_DisplayColor(get_abi(value)));
}

template <typename D> void impl_IAppointmentCalendar2<D>::IsHidden(bool value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->put_IsHidden(value));
}

template <typename D> hstring impl_IAppointmentCalendar2<D>::UserDataAccountId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->get_UserDataAccountId(put_abi(value)));
    return value;
}

template <typename D> bool impl_IAppointmentCalendar2<D>::CanCreateOrUpdateAppointments() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->get_CanCreateOrUpdateAppointments(&value));
    return value;
}

template <typename D> void impl_IAppointmentCalendar2<D>::CanCreateOrUpdateAppointments(bool value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->put_CanCreateOrUpdateAppointments(value));
}

template <typename D> bool impl_IAppointmentCalendar2<D>::CanCancelMeetings() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->get_CanCancelMeetings(&value));
    return value;
}

template <typename D> void impl_IAppointmentCalendar2<D>::CanCancelMeetings(bool value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->put_CanCancelMeetings(value));
}

template <typename D> bool impl_IAppointmentCalendar2<D>::CanForwardMeetings() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->get_CanForwardMeetings(&value));
    return value;
}

template <typename D> void impl_IAppointmentCalendar2<D>::CanForwardMeetings(bool value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->put_CanForwardMeetings(value));
}

template <typename D> bool impl_IAppointmentCalendar2<D>::CanProposeNewTimeForMeetings() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->get_CanProposeNewTimeForMeetings(&value));
    return value;
}

template <typename D> void impl_IAppointmentCalendar2<D>::CanProposeNewTimeForMeetings(bool value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->put_CanProposeNewTimeForMeetings(value));
}

template <typename D> bool impl_IAppointmentCalendar2<D>::CanUpdateMeetingResponses() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->get_CanUpdateMeetingResponses(&value));
    return value;
}

template <typename D> void impl_IAppointmentCalendar2<D>::CanUpdateMeetingResponses(bool value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->put_CanUpdateMeetingResponses(value));
}

template <typename D> bool impl_IAppointmentCalendar2<D>::CanNotifyInvitees() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->get_CanNotifyInvitees(&value));
    return value;
}

template <typename D> void impl_IAppointmentCalendar2<D>::CanNotifyInvitees(bool value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->put_CanNotifyInvitees(value));
}

template <typename D> bool impl_IAppointmentCalendar2<D>::MustNofityInvitees() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->get_MustNofityInvitees(&value));
    return value;
}

template <typename D> void impl_IAppointmentCalendar2<D>::MustNofityInvitees(bool value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->put_MustNofityInvitees(value));
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppointmentCalendar2<D>::TryCreateOrUpdateAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment, bool notifyInvitees) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->abi_TryCreateOrUpdateAppointmentAsync(get_abi(appointment), notifyInvitees, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppointmentCalendar2<D>::TryCancelMeetingAsync(const Windows::ApplicationModel::Appointments::Appointment & meeting, hstring_view subject, hstring_view comment, bool notifyInvitees) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->abi_TryCancelMeetingAsync(get_abi(meeting), get_abi(subject), get_abi(comment), notifyInvitees, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppointmentCalendar2<D>::TryForwardMeetingAsync(const Windows::ApplicationModel::Appointments::Appointment & meeting, iterable<Windows::ApplicationModel::Appointments::AppointmentInvitee> invitees, hstring_view subject, hstring_view forwardHeader, hstring_view comment) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->abi_TryForwardMeetingAsync(get_abi(meeting), get_abi(invitees), get_abi(subject), get_abi(forwardHeader), get_abi(comment), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppointmentCalendar2<D>::TryProposeNewTimeForMeetingAsync(const Windows::ApplicationModel::Appointments::Appointment & meeting, const Windows::Foundation::DateTime & newStartTime, const Windows::Foundation::TimeSpan & newDuration, hstring_view subject, hstring_view comment) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->abi_TryProposeNewTimeForMeetingAsync(get_abi(meeting), get_abi(newStartTime), get_abi(newDuration), get_abi(subject), get_abi(comment), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppointmentCalendar2<D>::TryUpdateMeetingResponseAsync(const Windows::ApplicationModel::Appointments::Appointment & meeting, Windows::ApplicationModel::Appointments::AppointmentParticipantResponse response, hstring_view subject, hstring_view comment, bool sendUpdate) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IAppointmentCalendar2)->abi_TryUpdateMeetingResponseAsync(get_abi(meeting), response, get_abi(subject), get_abi(comment), sendUpdate, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAppointmentCalendar3<D>::RegisterSyncManagerAsync() const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(IAppointmentCalendar3)->abi_RegisterSyncManagerAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentCalendarSyncStatus impl_IAppointmentCalendarSyncManager<D>::Status() const
{
    Windows::ApplicationModel::Appointments::AppointmentCalendarSyncStatus value {};
    check_hresult(WINRT_SHIM(IAppointmentCalendarSyncManager)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IAppointmentCalendarSyncManager<D>::LastSuccessfulSyncTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IAppointmentCalendarSyncManager)->get_LastSuccessfulSyncTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IAppointmentCalendarSyncManager<D>::LastAttemptedSyncTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IAppointmentCalendarSyncManager)->get_LastAttemptedSyncTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppointmentCalendarSyncManager<D>::SyncAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(IAppointmentCalendarSyncManager)->abi_SyncAsync(put_abi(result)));
    return result;
}

template <typename D> event_token impl_IAppointmentCalendarSyncManager<D>::SyncStatusChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::AppointmentCalendarSyncManager, Windows::Foundation::IInspectable> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IAppointmentCalendarSyncManager)->add_SyncStatusChanged(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<IAppointmentCalendarSyncManager> impl_IAppointmentCalendarSyncManager<D>::SyncStatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::AppointmentCalendarSyncManager, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, IAppointmentCalendarSyncManager>(this, &ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager::remove_SyncStatusChanged, SyncStatusChanged(handler));
}

template <typename D> void impl_IAppointmentCalendarSyncManager<D>::SyncStatusChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendarSyncManager)->remove_SyncStatusChanged(token));
}

template <typename D> void impl_IAppointmentCalendarSyncManager2<D>::Status(Windows::ApplicationModel::Appointments::AppointmentCalendarSyncStatus value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendarSyncManager2)->put_Status(value));
}

template <typename D> void impl_IAppointmentCalendarSyncManager2<D>::LastSuccessfulSyncTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendarSyncManager2)->put_LastSuccessfulSyncTime(get_abi(value)));
}

template <typename D> void impl_IAppointmentCalendarSyncManager2<D>::LastAttemptedSyncTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IAppointmentCalendarSyncManager2)->put_LastAttemptedSyncTime(get_abi(value)));
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::Subject() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_Subject(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::Location() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_Location(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::StartTime() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_StartTime(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::Duration() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::Reminder() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_Reminder(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::BusyStatus() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_BusyStatus(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::Sensitivity() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_Sensitivity(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::OriginalStartTime() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_OriginalStartTime(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::IsResponseRequested() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_IsResponseRequested(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::AllowNewTimeProposal() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_AllowNewTimeProposal(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::AllDay() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_AllDay(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::Details() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_Details(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::OnlineMeetingLink() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_OnlineMeetingLink(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::ReplyTime() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_ReplyTime(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::Organizer() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_Organizer(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::UserResponse() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_UserResponse(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::HasInvitees() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_HasInvitees(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::IsCanceledMeeting() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_IsCanceledMeeting(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::IsOrganizedByUser() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_IsOrganizedByUser(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::Recurrence() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_Recurrence(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::Uri() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_Uri(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics<D>::Invitees() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_Invitees(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_IAppointmentPropertiesStatics<D>::DefaultProperties() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics)->get_DefaultProperties(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics2<D>::ChangeNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics2)->get_ChangeNumber(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics2<D>::RemoteChangeNumber() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics2)->get_RemoteChangeNumber(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentPropertiesStatics2<D>::DetailsKind() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentPropertiesStatics2)->get_DetailsKind(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentConflictType impl_IAppointmentConflictResult<D>::Type() const
{
    Windows::ApplicationModel::Appointments::AppointmentConflictType value {};
    check_hresult(WINRT_SHIM(IAppointmentConflictResult)->get_Type(&value));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IAppointmentConflictResult<D>::Date() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IAppointmentConflictResult)->get_Date(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Appointments::Appointment impl_IAppointmentStoreChange<D>::Appointment() const
{
    Windows::ApplicationModel::Appointments::Appointment value { nullptr };
    check_hresult(WINRT_SHIM(IAppointmentStoreChange)->get_Appointment(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentStoreChangeType impl_IAppointmentStoreChange<D>::ChangeType() const
{
    Windows::ApplicationModel::Appointments::AppointmentStoreChangeType value {};
    check_hresult(WINRT_SHIM(IAppointmentStoreChange)->get_ChangeType(&value));
    return value;
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentCalendar impl_IAppointmentStoreChange2<D>::AppointmentCalendar() const
{
    Windows::ApplicationModel::Appointments::AppointmentCalendar value { nullptr };
    check_hresult(WINRT_SHIM(IAppointmentStoreChange2)->get_AppointmentCalendar(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentStoreChange>> impl_IAppointmentStoreChangeReader<D>::ReadBatchAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentStoreChange>> result;
    check_hresult(WINRT_SHIM(IAppointmentStoreChangeReader)->abi_ReadBatchAsync(put_abi(result)));
    return result;
}

template <typename D> void impl_IAppointmentStoreChangeReader<D>::AcceptChanges() const
{
    check_hresult(WINRT_SHIM(IAppointmentStoreChangeReader)->abi_AcceptChanges());
}

template <typename D> void impl_IAppointmentStoreChangeReader<D>::AcceptChangesThrough(const Windows::ApplicationModel::Appointments::AppointmentStoreChange & lastChangeToAccept) const
{
    check_hresult(WINRT_SHIM(IAppointmentStoreChangeReader)->abi_AcceptChangesThrough(get_abi(lastChangeToAccept)));
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentStoreChangeReader impl_IAppointmentStoreChangeTracker<D>::GetChangeReader() const
{
    Windows::ApplicationModel::Appointments::AppointmentStoreChangeReader value { nullptr };
    check_hresult(WINRT_SHIM(IAppointmentStoreChangeTracker)->abi_GetChangeReader(put_abi(value)));
    return value;
}

template <typename D> void impl_IAppointmentStoreChangeTracker<D>::Enable() const
{
    check_hresult(WINRT_SHIM(IAppointmentStoreChangeTracker)->abi_Enable());
}

template <typename D> void impl_IAppointmentStoreChangeTracker<D>::Reset() const
{
    check_hresult(WINRT_SHIM(IAppointmentStoreChangeTracker)->abi_Reset());
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentStoreChangedDeferral impl_IAppointmentStoreChangedEventArgs<D>::GetDeferral() const
{
    Windows::ApplicationModel::Appointments::AppointmentStoreChangedDeferral result { nullptr };
    check_hresult(WINRT_SHIM(IAppointmentStoreChangedEventArgs)->abi_GetDeferral(put_abi(result)));
    return result;
}

template <typename D> void impl_IAppointmentStoreChangedDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(IAppointmentStoreChangedDeferral)->abi_Complete());
}

template <typename D> Windows::ApplicationModel::Appointments::AppointmentStoreChangeTracker impl_IAppointmentStore<D>::ChangeTracker() const
{
    Windows::ApplicationModel::Appointments::AppointmentStoreChangeTracker value { nullptr };
    check_hresult(WINRT_SHIM(IAppointmentStore)->get_ChangeTracker(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentCalendar> impl_IAppointmentStore<D>::CreateAppointmentCalendarAsync(hstring_view name) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentCalendar> operation;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_CreateAppointmentCalendarAsync(get_abi(name), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentCalendar> impl_IAppointmentStore<D>::GetAppointmentCalendarAsync(hstring_view calendarId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentCalendar> result;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_GetAppointmentCalendarAsync(get_abi(calendarId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::Appointment> impl_IAppointmentStore<D>::GetAppointmentAsync(hstring_view localId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::Appointment> result;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_GetAppointmentAsync(get_abi(localId), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::Appointment> impl_IAppointmentStore<D>::GetAppointmentInstanceAsync(hstring_view localId, const Windows::Foundation::DateTime & instanceStartTime) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::Appointment> result;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_GetAppointmentInstanceAsync(get_abi(localId), get_abi(instanceStartTime), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentCalendar>> impl_IAppointmentStore<D>::FindAppointmentCalendarsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentCalendar>> result;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_FindAppointmentCalendarsAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentCalendar>> impl_IAppointmentStore<D>::FindAppointmentCalendarsAsync(Windows::ApplicationModel::Appointments::FindAppointmentCalendarsOptions options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentCalendar>> result;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_FindAppointmentCalendarsAsyncWithOptions(options, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> impl_IAppointmentStore<D>::FindAppointmentsAsync(const Windows::Foundation::DateTime & rangeStart, const Windows::Foundation::TimeSpan & rangeLength) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> result;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_FindAppointmentsAsync(get_abi(rangeStart), get_abi(rangeLength), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> impl_IAppointmentStore<D>::FindAppointmentsAsync(const Windows::Foundation::DateTime & rangeStart, const Windows::Foundation::TimeSpan & rangeLength, const Windows::ApplicationModel::Appointments::FindAppointmentsOptions & options) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> result;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_FindAppointmentsAsyncWithOptions(get_abi(rangeStart), get_abi(rangeLength), get_abi(options), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentConflictResult> impl_IAppointmentStore<D>::FindConflictAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentConflictResult> result;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_FindConflictAsync(get_abi(appointment), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentConflictResult> impl_IAppointmentStore<D>::FindConflictAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::DateTime & instanceStartTime) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentConflictResult> result;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_FindConflictAsyncWithInstanceStart(get_abi(appointment), get_abi(instanceStartTime), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAppointmentStore<D>::MoveAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::ApplicationModel::Appointments::AppointmentCalendar & destinationCalendar) const
{
    Windows::Foundation::IAsyncAction asyncAction;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_MoveAppointmentAsync(get_abi(appointment), get_abi(destinationCalendar), put_abi(asyncAction)));
    return asyncAction;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IAppointmentStore<D>::ShowAddAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_ShowAddAppointmentAsync(get_abi(appointment), get_abi(selection), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IAppointmentStore<D>::ShowReplaceAppointmentAsync(hstring_view localId, const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_ShowReplaceAppointmentAsync(get_abi(localId), get_abi(appointment), get_abi(selection), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IAppointmentStore<D>::ShowReplaceAppointmentAsync(hstring_view localId, const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::Foundation::DateTime & instanceStartDate) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_ShowReplaceAppointmentWithPlacementAndDateAsync(get_abi(localId), get_abi(appointment), get_abi(selection), preferredPlacement, get_abi(instanceStartDate), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppointmentStore<D>::ShowRemoveAppointmentAsync(hstring_view localId, const Windows::Foundation::Rect & selection) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_ShowRemoveAppointmentAsync(get_abi(localId), get_abi(selection), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IAppointmentStore<D>::ShowRemoveAppointmentAsync(hstring_view localId, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::Foundation::DateTime & instanceStartDate) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_ShowRemoveAppointmentWithPlacementAndDateAsync(get_abi(localId), get_abi(selection), preferredPlacement, get_abi(instanceStartDate), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAppointmentStore<D>::ShowAppointmentDetailsAsync(hstring_view localId) const
{
    Windows::Foundation::IAsyncAction asyncAction;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_ShowAppointmentDetailsAsync(get_abi(localId), put_abi(asyncAction)));
    return asyncAction;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IAppointmentStore<D>::ShowAppointmentDetailsAsync(hstring_view localId, const Windows::Foundation::DateTime & instanceStartDate) const
{
    Windows::Foundation::IAsyncAction asyncAction;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_ShowAppointmentDetailsWithDateAsync(get_abi(localId), get_abi(instanceStartDate), put_abi(asyncAction)));
    return asyncAction;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_IAppointmentStore<D>::ShowEditNewAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment) const
{
    Windows::Foundation::IAsyncOperation<hstring> operation;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_ShowEditNewAppointmentAsync(get_abi(appointment), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> impl_IAppointmentStore<D>::FindLocalIdsFromRoamingIdAsync(hstring_view roamingId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> operation;
    check_hresult(WINRT_SHIM(IAppointmentStore)->abi_FindLocalIdsFromRoamingIdAsync(get_abi(roamingId), put_abi(operation)));
    return operation;
}

template <typename D> event_token impl_IAppointmentStore2<D>::StoreChanged(const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::AppointmentStore, Windows::ApplicationModel::Appointments::AppointmentStoreChangedEventArgs> & pHandler) const
{
    event_token pToken {};
    check_hresult(WINRT_SHIM(IAppointmentStore2)->add_StoreChanged(get_abi(pHandler), &pToken));
    return pToken;
}

template <typename D> event_revoker<IAppointmentStore2> impl_IAppointmentStore2<D>::StoreChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::ApplicationModel::Appointments::AppointmentStore, Windows::ApplicationModel::Appointments::AppointmentStoreChangedEventArgs> & pHandler) const
{
    return impl::make_event_revoker<D, IAppointmentStore2>(this, &ABI::Windows::ApplicationModel::Appointments::IAppointmentStore2::remove_StoreChanged, StoreChanged(pHandler));
}

template <typename D> void impl_IAppointmentStore2<D>::StoreChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IAppointmentStore2)->remove_StoreChanged(token));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentCalendar> impl_IAppointmentStore2<D>::CreateAppointmentCalendarAsync(hstring_view name, hstring_view userDataAccountId) const
{
    Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentCalendar> operation;
    check_hresult(WINRT_SHIM(IAppointmentStore2)->abi_CreateAppointmentCalendarInAccountAsync(get_abi(name), get_abi(userDataAccountId), put_abi(operation)));
    return operation;
}

template <typename D> Windows::ApplicationModel::Appointments::Appointment impl_IAppointmentException<D>::Appointment() const
{
    Windows::ApplicationModel::Appointments::Appointment value { nullptr };
    check_hresult(WINRT_SHIM(IAppointmentException)->get_Appointment(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_IAppointmentException<D>::ExceptionProperties() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(IAppointmentException)->get_ExceptionProperties(put_abi(value)));
    return value;
}

template <typename D> bool impl_IAppointmentException<D>::IsDeleted() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IAppointmentException)->get_IsDeleted(&value));
    return value;
}

inline Appointment::Appointment() :
    Appointment(activate_instance<Appointment>())
{}

inline AppointmentInvitee::AppointmentInvitee() :
    AppointmentInvitee(activate_instance<AppointmentInvitee>())
{}

inline Windows::Foundation::IAsyncOperation<hstring> AppointmentManager::ShowAddAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection)
{
    return get_activation_factory<AppointmentManager, IAppointmentManagerStatics>().ShowAddAppointmentAsync(appointment, selection);
}

inline Windows::Foundation::IAsyncOperation<hstring> AppointmentManager::ShowAddAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement)
{
    return get_activation_factory<AppointmentManager, IAppointmentManagerStatics>().ShowAddAppointmentAsync(appointment, selection, preferredPlacement);
}

inline Windows::Foundation::IAsyncOperation<hstring> AppointmentManager::ShowReplaceAppointmentAsync(hstring_view appointmentId, const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection)
{
    return get_activation_factory<AppointmentManager, IAppointmentManagerStatics>().ShowReplaceAppointmentAsync(appointmentId, appointment, selection);
}

inline Windows::Foundation::IAsyncOperation<hstring> AppointmentManager::ShowReplaceAppointmentAsync(hstring_view appointmentId, const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement)
{
    return get_activation_factory<AppointmentManager, IAppointmentManagerStatics>().ShowReplaceAppointmentAsync(appointmentId, appointment, selection, preferredPlacement);
}

inline Windows::Foundation::IAsyncOperation<hstring> AppointmentManager::ShowReplaceAppointmentAsync(hstring_view appointmentId, const Windows::ApplicationModel::Appointments::Appointment & appointment, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::Foundation::DateTime & instanceStartDate)
{
    return get_activation_factory<AppointmentManager, IAppointmentManagerStatics>().ShowReplaceAppointmentAsync(appointmentId, appointment, selection, preferredPlacement, instanceStartDate);
}

inline Windows::Foundation::IAsyncOperation<bool> AppointmentManager::ShowRemoveAppointmentAsync(hstring_view appointmentId, const Windows::Foundation::Rect & selection)
{
    return get_activation_factory<AppointmentManager, IAppointmentManagerStatics>().ShowRemoveAppointmentAsync(appointmentId, selection);
}

inline Windows::Foundation::IAsyncOperation<bool> AppointmentManager::ShowRemoveAppointmentAsync(hstring_view appointmentId, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement)
{
    return get_activation_factory<AppointmentManager, IAppointmentManagerStatics>().ShowRemoveAppointmentAsync(appointmentId, selection, preferredPlacement);
}

inline Windows::Foundation::IAsyncOperation<bool> AppointmentManager::ShowRemoveAppointmentAsync(hstring_view appointmentId, const Windows::Foundation::Rect & selection, Windows::UI::Popups::Placement preferredPlacement, const Windows::Foundation::DateTime & instanceStartDate)
{
    return get_activation_factory<AppointmentManager, IAppointmentManagerStatics>().ShowRemoveAppointmentAsync(appointmentId, selection, preferredPlacement, instanceStartDate);
}

inline Windows::Foundation::IAsyncAction AppointmentManager::ShowTimeFrameAsync(const Windows::Foundation::DateTime & timeToShow, const Windows::Foundation::TimeSpan & duration)
{
    return get_activation_factory<AppointmentManager, IAppointmentManagerStatics>().ShowTimeFrameAsync(timeToShow, duration);
}

inline Windows::Foundation::IAsyncAction AppointmentManager::ShowAppointmentDetailsAsync(hstring_view appointmentId)
{
    return get_activation_factory<AppointmentManager, IAppointmentManagerStatics2>().ShowAppointmentDetailsAsync(appointmentId);
}

inline Windows::Foundation::IAsyncAction AppointmentManager::ShowAppointmentDetailsAsync(hstring_view appointmentId, const Windows::Foundation::DateTime & instanceStartDate)
{
    return get_activation_factory<AppointmentManager, IAppointmentManagerStatics2>().ShowAppointmentDetailsAsync(appointmentId, instanceStartDate);
}

inline Windows::Foundation::IAsyncOperation<hstring> AppointmentManager::ShowEditNewAppointmentAsync(const Windows::ApplicationModel::Appointments::Appointment & appointment)
{
    return get_activation_factory<AppointmentManager, IAppointmentManagerStatics2>().ShowEditNewAppointmentAsync(appointment);
}

inline Windows::Foundation::IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentStore> AppointmentManager::RequestStoreAsync(Windows::ApplicationModel::Appointments::AppointmentStoreAccessType options)
{
    return get_activation_factory<AppointmentManager, IAppointmentManagerStatics2>().RequestStoreAsync(options);
}

inline Windows::ApplicationModel::Appointments::AppointmentManagerForUser AppointmentManager::GetForUser(const Windows::System::User & user)
{
    return get_activation_factory<AppointmentManager, IAppointmentManagerStatics3>().GetForUser(user);
}

inline AppointmentOrganizer::AppointmentOrganizer() :
    AppointmentOrganizer(activate_instance<AppointmentOrganizer>())
{}

inline hstring AppointmentProperties::Subject()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().Subject();
}

inline hstring AppointmentProperties::Location()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().Location();
}

inline hstring AppointmentProperties::StartTime()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().StartTime();
}

inline hstring AppointmentProperties::Duration()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().Duration();
}

inline hstring AppointmentProperties::Reminder()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().Reminder();
}

inline hstring AppointmentProperties::BusyStatus()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().BusyStatus();
}

inline hstring AppointmentProperties::Sensitivity()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().Sensitivity();
}

inline hstring AppointmentProperties::OriginalStartTime()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().OriginalStartTime();
}

inline hstring AppointmentProperties::IsResponseRequested()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().IsResponseRequested();
}

inline hstring AppointmentProperties::AllowNewTimeProposal()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().AllowNewTimeProposal();
}

inline hstring AppointmentProperties::AllDay()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().AllDay();
}

inline hstring AppointmentProperties::Details()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().Details();
}

inline hstring AppointmentProperties::OnlineMeetingLink()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().OnlineMeetingLink();
}

inline hstring AppointmentProperties::ReplyTime()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().ReplyTime();
}

inline hstring AppointmentProperties::Organizer()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().Organizer();
}

inline hstring AppointmentProperties::UserResponse()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().UserResponse();
}

inline hstring AppointmentProperties::HasInvitees()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().HasInvitees();
}

inline hstring AppointmentProperties::IsCanceledMeeting()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().IsCanceledMeeting();
}

inline hstring AppointmentProperties::IsOrganizedByUser()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().IsOrganizedByUser();
}

inline hstring AppointmentProperties::Recurrence()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().Recurrence();
}

inline hstring AppointmentProperties::Uri()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().Uri();
}

inline hstring AppointmentProperties::Invitees()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().Invitees();
}

inline Windows::Foundation::Collections::IVector<hstring> AppointmentProperties::DefaultProperties()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics>().DefaultProperties();
}

inline hstring AppointmentProperties::ChangeNumber()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics2>().ChangeNumber();
}

inline hstring AppointmentProperties::RemoteChangeNumber()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics2>().RemoteChangeNumber();
}

inline hstring AppointmentProperties::DetailsKind()
{
    return get_activation_factory<AppointmentProperties, IAppointmentPropertiesStatics2>().DetailsKind();
}

inline AppointmentRecurrence::AppointmentRecurrence() :
    AppointmentRecurrence(activate_instance<AppointmentRecurrence>())
{}

inline FindAppointmentsOptions::FindAppointmentsOptions() :
    FindAppointmentsOptions(activate_instance<FindAppointmentsOptions>())
{}

}

}
#pragma warning(pop)
