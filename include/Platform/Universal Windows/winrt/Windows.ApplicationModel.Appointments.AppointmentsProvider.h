// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.ApplicationModel.Appointments.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.ApplicationModel.Appointments.AppointmentsProvider.3.h"
#include "Windows.ApplicationModel.Appointments.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation> : produce_base<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation>
{
    HRESULT __stdcall get_AppointmentInformation(impl::abi_arg_out<Windows::ApplicationModel::Appointments::IAppointment> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppointmentInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourcePackageFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourcePackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompleted(impl::abi_arg_in<hstring> itemId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted(*reinterpret_cast<const hstring *>(&itemId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCanceled() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCanceled();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportError(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportError(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DismissUI() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DismissUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics> : produce_base<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics>
{
    HRESULT __stdcall get_AddAppointment(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AddAppointment());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ReplaceAppointment(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReplaceAppointment());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemoveAppointment(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemoveAppointment());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShowTimeFrame(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShowTimeFrame());
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
struct produce<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2> : produce_base<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2>
{
    HRESULT __stdcall get_ShowAppointmentDetails(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShowAppointmentDetails());
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
struct produce<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation> : produce_base<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation>
{
    HRESULT __stdcall get_AppointmentId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppointmentId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_SourcePackageFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourcePackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompleted() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCanceled() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCanceled();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportError(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportError(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DismissUI() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DismissUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation> : produce_base<D, Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation>
{
    HRESULT __stdcall get_AppointmentId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppointmentId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppointmentInformation(impl::abi_arg_out<Windows::ApplicationModel::Appointments::IAppointment> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppointmentInformation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

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

    HRESULT __stdcall get_SourcePackageFamilyName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourcePackageFamilyName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCompleted(impl::abi_arg_in<hstring> itemId) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCompleted(*reinterpret_cast<const hstring *>(&itemId));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportCanceled() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCanceled();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReportError(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportError(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DismissUI() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DismissUI();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::ApplicationModel::Appointments::AppointmentsProvider {

template <typename D> hstring impl_IAppointmentsProviderLaunchActionVerbsStatics<D>::AddAppointment() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentsProviderLaunchActionVerbsStatics)->get_AddAppointment(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentsProviderLaunchActionVerbsStatics<D>::ReplaceAppointment() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentsProviderLaunchActionVerbsStatics)->get_ReplaceAppointment(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentsProviderLaunchActionVerbsStatics<D>::RemoveAppointment() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentsProviderLaunchActionVerbsStatics)->get_RemoveAppointment(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentsProviderLaunchActionVerbsStatics<D>::ShowTimeFrame() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentsProviderLaunchActionVerbsStatics)->get_ShowTimeFrame(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAppointmentsProviderLaunchActionVerbsStatics2<D>::ShowAppointmentDetails() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAppointmentsProviderLaunchActionVerbsStatics2)->get_ShowAppointmentDetails(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Appointments::Appointment impl_IAddAppointmentOperation<D>::AppointmentInformation() const
{
    Windows::ApplicationModel::Appointments::Appointment value { nullptr };
    check_hresult(WINRT_SHIM(IAddAppointmentOperation)->get_AppointmentInformation(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IAddAppointmentOperation<D>::SourcePackageFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IAddAppointmentOperation)->get_SourcePackageFamilyName(put_abi(value)));
    return value;
}

template <typename D> void impl_IAddAppointmentOperation<D>::ReportCompleted(hstring_view itemId) const
{
    check_hresult(WINRT_SHIM(IAddAppointmentOperation)->abi_ReportCompleted(get_abi(itemId)));
}

template <typename D> void impl_IAddAppointmentOperation<D>::ReportCanceled() const
{
    check_hresult(WINRT_SHIM(IAddAppointmentOperation)->abi_ReportCanceled());
}

template <typename D> void impl_IAddAppointmentOperation<D>::ReportError(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IAddAppointmentOperation)->abi_ReportError(get_abi(value)));
}

template <typename D> void impl_IAddAppointmentOperation<D>::DismissUI() const
{
    check_hresult(WINRT_SHIM(IAddAppointmentOperation)->abi_DismissUI());
}

template <typename D> hstring impl_IReplaceAppointmentOperation<D>::AppointmentId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IReplaceAppointmentOperation)->get_AppointmentId(put_abi(value)));
    return value;
}

template <typename D> Windows::ApplicationModel::Appointments::Appointment impl_IReplaceAppointmentOperation<D>::AppointmentInformation() const
{
    Windows::ApplicationModel::Appointments::Appointment value { nullptr };
    check_hresult(WINRT_SHIM(IReplaceAppointmentOperation)->get_AppointmentInformation(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IReplaceAppointmentOperation<D>::InstanceStartDate() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IReplaceAppointmentOperation)->get_InstanceStartDate(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IReplaceAppointmentOperation<D>::SourcePackageFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IReplaceAppointmentOperation)->get_SourcePackageFamilyName(put_abi(value)));
    return value;
}

template <typename D> void impl_IReplaceAppointmentOperation<D>::ReportCompleted(hstring_view itemId) const
{
    check_hresult(WINRT_SHIM(IReplaceAppointmentOperation)->abi_ReportCompleted(get_abi(itemId)));
}

template <typename D> void impl_IReplaceAppointmentOperation<D>::ReportCanceled() const
{
    check_hresult(WINRT_SHIM(IReplaceAppointmentOperation)->abi_ReportCanceled());
}

template <typename D> void impl_IReplaceAppointmentOperation<D>::ReportError(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IReplaceAppointmentOperation)->abi_ReportError(get_abi(value)));
}

template <typename D> void impl_IReplaceAppointmentOperation<D>::DismissUI() const
{
    check_hresult(WINRT_SHIM(IReplaceAppointmentOperation)->abi_DismissUI());
}

template <typename D> hstring impl_IRemoveAppointmentOperation<D>::AppointmentId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRemoveAppointmentOperation)->get_AppointmentId(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<Windows::Foundation::DateTime> impl_IRemoveAppointmentOperation<D>::InstanceStartDate() const
{
    Windows::Foundation::IReference<Windows::Foundation::DateTime> value;
    check_hresult(WINRT_SHIM(IRemoveAppointmentOperation)->get_InstanceStartDate(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IRemoveAppointmentOperation<D>::SourcePackageFamilyName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IRemoveAppointmentOperation)->get_SourcePackageFamilyName(put_abi(value)));
    return value;
}

template <typename D> void impl_IRemoveAppointmentOperation<D>::ReportCompleted() const
{
    check_hresult(WINRT_SHIM(IRemoveAppointmentOperation)->abi_ReportCompleted());
}

template <typename D> void impl_IRemoveAppointmentOperation<D>::ReportCanceled() const
{
    check_hresult(WINRT_SHIM(IRemoveAppointmentOperation)->abi_ReportCanceled());
}

template <typename D> void impl_IRemoveAppointmentOperation<D>::ReportError(hstring_view value) const
{
    check_hresult(WINRT_SHIM(IRemoveAppointmentOperation)->abi_ReportError(get_abi(value)));
}

template <typename D> void impl_IRemoveAppointmentOperation<D>::DismissUI() const
{
    check_hresult(WINRT_SHIM(IRemoveAppointmentOperation)->abi_DismissUI());
}

inline hstring AppointmentsProviderLaunchActionVerbs::AddAppointment()
{
    return get_activation_factory<AppointmentsProviderLaunchActionVerbs, IAppointmentsProviderLaunchActionVerbsStatics>().AddAppointment();
}

inline hstring AppointmentsProviderLaunchActionVerbs::ReplaceAppointment()
{
    return get_activation_factory<AppointmentsProviderLaunchActionVerbs, IAppointmentsProviderLaunchActionVerbsStatics>().ReplaceAppointment();
}

inline hstring AppointmentsProviderLaunchActionVerbs::RemoveAppointment()
{
    return get_activation_factory<AppointmentsProviderLaunchActionVerbs, IAppointmentsProviderLaunchActionVerbsStatics>().RemoveAppointment();
}

inline hstring AppointmentsProviderLaunchActionVerbs::ShowTimeFrame()
{
    return get_activation_factory<AppointmentsProviderLaunchActionVerbs, IAppointmentsProviderLaunchActionVerbsStatics>().ShowTimeFrame();
}

inline hstring AppointmentsProviderLaunchActionVerbs::ShowAppointmentDetails()
{
    return get_activation_factory<AppointmentsProviderLaunchActionVerbs, IAppointmentsProviderLaunchActionVerbsStatics2>().ShowAppointmentDetails();
}

}

}
#pragma warning(pop)
