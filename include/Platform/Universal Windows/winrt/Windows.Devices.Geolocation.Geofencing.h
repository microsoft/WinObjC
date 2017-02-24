// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Devices.Geolocation.3.h"
#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Devices.Geolocation.Geofencing.3.h"
#include "Windows.Devices.Geolocation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::Geolocation::Geofencing::IGeofence> : produce_base<D, Windows::Devices::Geolocation::Geofencing::IGeofence>
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

    HRESULT __stdcall get_DwellTime(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DwellTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Id(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MonitoredStates(Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MonitoredStates());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Geoshape(impl::abi_arg_out<Windows::Devices::Geolocation::IGeoshape> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Geoshape());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SingleUse(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SingleUse());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Geolocation::Geofencing::IGeofenceFactory> : produce_base<D, Windows::Devices::Geolocation::Geofencing::IGeofenceFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> id, impl::abi_arg_in<Windows::Devices::Geolocation::IGeoshape> geoshape, impl::abi_arg_out<Windows::Devices::Geolocation::Geofencing::IGeofence> geofence) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *geofence = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&id), *reinterpret_cast<const Windows::Devices::Geolocation::IGeoshape *>(&geoshape)));
            return S_OK;
        }
        catch (...)
        {
            *geofence = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithMonitorStates(impl::abi_arg_in<hstring> id, impl::abi_arg_in<Windows::Devices::Geolocation::IGeoshape> geoshape, Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates monitoredStates, bool singleUse, impl::abi_arg_out<Windows::Devices::Geolocation::Geofencing::IGeofence> geofence) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *geofence = detach_abi(this->shim().CreateWithMonitorStates(*reinterpret_cast<const hstring *>(&id), *reinterpret_cast<const Windows::Devices::Geolocation::IGeoshape *>(&geoshape), monitoredStates, singleUse));
            return S_OK;
        }
        catch (...)
        {
            *geofence = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithMonitorStatesAndDwellTime(impl::abi_arg_in<hstring> id, impl::abi_arg_in<Windows::Devices::Geolocation::IGeoshape> geoshape, Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates monitoredStates, bool singleUse, impl::abi_arg_in<Windows::Foundation::TimeSpan> dwellTime, impl::abi_arg_out<Windows::Devices::Geolocation::Geofencing::IGeofence> geofence) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *geofence = detach_abi(this->shim().CreateWithMonitorStatesAndDwellTime(*reinterpret_cast<const hstring *>(&id), *reinterpret_cast<const Windows::Devices::Geolocation::IGeoshape *>(&geoshape), monitoredStates, singleUse, *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&dwellTime)));
            return S_OK;
        }
        catch (...)
        {
            *geofence = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithMonitorStatesDwellTimeStartTimeAndDuration(impl::abi_arg_in<hstring> id, impl::abi_arg_in<Windows::Devices::Geolocation::IGeoshape> geoshape, Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates monitoredStates, bool singleUse, impl::abi_arg_in<Windows::Foundation::TimeSpan> dwellTime, impl::abi_arg_in<Windows::Foundation::DateTime> startTime, impl::abi_arg_in<Windows::Foundation::TimeSpan> duration, impl::abi_arg_out<Windows::Devices::Geolocation::Geofencing::IGeofence> geofence) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *geofence = detach_abi(this->shim().CreateWithMonitorStatesDwellTimeStartTimeAndDuration(*reinterpret_cast<const hstring *>(&id), *reinterpret_cast<const Windows::Devices::Geolocation::IGeoshape *>(&geoshape), monitoredStates, singleUse, *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&dwellTime), *reinterpret_cast<const Windows::Foundation::DateTime *>(&startTime), *reinterpret_cast<const Windows::Foundation::TimeSpan *>(&duration)));
            return S_OK;
        }
        catch (...)
        {
            *geofence = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor> : produce_base<D, Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor>
{
    HRESULT __stdcall get_Status(Windows::Devices::Geolocation::Geofencing::GeofenceMonitorStatus * value) noexcept override
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

    HRESULT __stdcall get_Geofences(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Devices::Geolocation::Geofencing::Geofence>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Geofences());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LastKnownGeoposition(impl::abi_arg_out<Windows::Devices::Geolocation::IGeoposition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LastKnownGeoposition());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_GeofenceStateChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geofencing::GeofenceMonitor, Windows::Foundation::IInspectable>> eventHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().GeofenceStateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geofencing::GeofenceMonitor, Windows::Foundation::IInspectable> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_GeofenceStateChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GeofenceStateChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadReports(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geofencing::GeofenceStateChangeReport>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadReports());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StatusChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geofencing::GeofenceMonitor, Windows::Foundation::IInspectable>> eventHandler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().StatusChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geofencing::GeofenceMonitor, Windows::Foundation::IInspectable> *>(&eventHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StatusChanged(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StatusChanged(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::Geolocation::Geofencing::IGeofenceMonitorStatics> : produce_base<D, Windows::Devices::Geolocation::Geofencing::IGeofenceMonitorStatics>
{
    HRESULT __stdcall get_Current(impl::abi_arg_out<Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Current());
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
struct produce<D, Windows::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport> : produce_base<D, Windows::Devices::Geolocation::Geofencing::IGeofenceStateChangeReport>
{
    HRESULT __stdcall get_NewState(Windows::Devices::Geolocation::Geofencing::GeofenceState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NewState());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Geofence(impl::abi_arg_out<Windows::Devices::Geolocation::Geofencing::IGeofence> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Geofence());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Geoposition(impl::abi_arg_out<Windows::Devices::Geolocation::IGeoposition> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Geoposition());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RemovalReason(Windows::Devices::Geolocation::Geofencing::GeofenceRemovalReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemovalReason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::Geolocation::Geofencing {

template <typename D> Windows::Devices::Geolocation::Geofencing::Geofence impl_IGeofenceFactory<D>::Create(hstring_view id, const Windows::Devices::Geolocation::IGeoshape & geoshape) const
{
    Windows::Devices::Geolocation::Geofencing::Geofence geofence { nullptr };
    check_hresult(WINRT_SHIM(IGeofenceFactory)->abi_Create(get_abi(id), get_abi(geoshape), put_abi(geofence)));
    return geofence;
}

template <typename D> Windows::Devices::Geolocation::Geofencing::Geofence impl_IGeofenceFactory<D>::CreateWithMonitorStates(hstring_view id, const Windows::Devices::Geolocation::IGeoshape & geoshape, Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates monitoredStates, bool singleUse) const
{
    Windows::Devices::Geolocation::Geofencing::Geofence geofence { nullptr };
    check_hresult(WINRT_SHIM(IGeofenceFactory)->abi_CreateWithMonitorStates(get_abi(id), get_abi(geoshape), monitoredStates, singleUse, put_abi(geofence)));
    return geofence;
}

template <typename D> Windows::Devices::Geolocation::Geofencing::Geofence impl_IGeofenceFactory<D>::CreateWithMonitorStatesAndDwellTime(hstring_view id, const Windows::Devices::Geolocation::IGeoshape & geoshape, Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates monitoredStates, bool singleUse, const Windows::Foundation::TimeSpan & dwellTime) const
{
    Windows::Devices::Geolocation::Geofencing::Geofence geofence { nullptr };
    check_hresult(WINRT_SHIM(IGeofenceFactory)->abi_CreateWithMonitorStatesAndDwellTime(get_abi(id), get_abi(geoshape), monitoredStates, singleUse, get_abi(dwellTime), put_abi(geofence)));
    return geofence;
}

template <typename D> Windows::Devices::Geolocation::Geofencing::Geofence impl_IGeofenceFactory<D>::CreateWithMonitorStatesDwellTimeStartTimeAndDuration(hstring_view id, const Windows::Devices::Geolocation::IGeoshape & geoshape, Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates monitoredStates, bool singleUse, const Windows::Foundation::TimeSpan & dwellTime, const Windows::Foundation::DateTime & startTime, const Windows::Foundation::TimeSpan & duration) const
{
    Windows::Devices::Geolocation::Geofencing::Geofence geofence { nullptr };
    check_hresult(WINRT_SHIM(IGeofenceFactory)->abi_CreateWithMonitorStatesDwellTimeStartTimeAndDuration(get_abi(id), get_abi(geoshape), monitoredStates, singleUse, get_abi(dwellTime), get_abi(startTime), get_abi(duration), put_abi(geofence)));
    return geofence;
}

template <typename D> Windows::Foundation::DateTime impl_IGeofence<D>::StartTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IGeofence)->get_StartTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IGeofence<D>::Duration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IGeofence)->get_Duration(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IGeofence<D>::DwellTime() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IGeofence)->get_DwellTime(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IGeofence<D>::Id() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IGeofence)->get_Id(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates impl_IGeofence<D>::MonitoredStates() const
{
    Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates value {};
    check_hresult(WINRT_SHIM(IGeofence)->get_MonitoredStates(&value));
    return value;
}

template <typename D> Windows::Devices::Geolocation::IGeoshape impl_IGeofence<D>::Geoshape() const
{
    Windows::Devices::Geolocation::IGeoshape value;
    check_hresult(WINRT_SHIM(IGeofence)->get_Geoshape(put_abi(value)));
    return value;
}

template <typename D> bool impl_IGeofence<D>::SingleUse() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IGeofence)->get_SingleUse(&value));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geofencing::GeofenceState impl_IGeofenceStateChangeReport<D>::NewState() const
{
    Windows::Devices::Geolocation::Geofencing::GeofenceState value {};
    check_hresult(WINRT_SHIM(IGeofenceStateChangeReport)->get_NewState(&value));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geofencing::Geofence impl_IGeofenceStateChangeReport<D>::Geofence() const
{
    Windows::Devices::Geolocation::Geofencing::Geofence value { nullptr };
    check_hresult(WINRT_SHIM(IGeofenceStateChangeReport)->get_Geofence(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geoposition impl_IGeofenceStateChangeReport<D>::Geoposition() const
{
    Windows::Devices::Geolocation::Geoposition value { nullptr };
    check_hresult(WINRT_SHIM(IGeofenceStateChangeReport)->get_Geoposition(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geofencing::GeofenceRemovalReason impl_IGeofenceStateChangeReport<D>::RemovalReason() const
{
    Windows::Devices::Geolocation::Geofencing::GeofenceRemovalReason value {};
    check_hresult(WINRT_SHIM(IGeofenceStateChangeReport)->get_RemovalReason(&value));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geofencing::GeofenceMonitor impl_IGeofenceMonitorStatics<D>::Current() const
{
    Windows::Devices::Geolocation::Geofencing::GeofenceMonitor value { nullptr };
    check_hresult(WINRT_SHIM(IGeofenceMonitorStatics)->get_Current(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geofencing::GeofenceMonitorStatus impl_IGeofenceMonitor<D>::Status() const
{
    Windows::Devices::Geolocation::Geofencing::GeofenceMonitorStatus value {};
    check_hresult(WINRT_SHIM(IGeofenceMonitor)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Devices::Geolocation::Geofencing::Geofence> impl_IGeofenceMonitor<D>::Geofences() const
{
    Windows::Foundation::Collections::IVector<Windows::Devices::Geolocation::Geofencing::Geofence> value;
    check_hresult(WINRT_SHIM(IGeofenceMonitor)->get_Geofences(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::Geolocation::Geoposition impl_IGeofenceMonitor<D>::LastKnownGeoposition() const
{
    Windows::Devices::Geolocation::Geoposition value { nullptr };
    check_hresult(WINRT_SHIM(IGeofenceMonitor)->get_LastKnownGeoposition(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IGeofenceMonitor<D>::GeofenceStateChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geofencing::GeofenceMonitor, Windows::Foundation::IInspectable> & eventHandler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGeofenceMonitor)->add_GeofenceStateChanged(get_abi(eventHandler), &token));
    return token;
}

template <typename D> event_revoker<IGeofenceMonitor> impl_IGeofenceMonitor<D>::GeofenceStateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geofencing::GeofenceMonitor, Windows::Foundation::IInspectable> & eventHandler) const
{
    return impl::make_event_revoker<D, IGeofenceMonitor>(this, &ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor::remove_GeofenceStateChanged, GeofenceStateChanged(eventHandler));
}

template <typename D> void impl_IGeofenceMonitor<D>::GeofenceStateChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IGeofenceMonitor)->remove_GeofenceStateChanged(token));
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geofencing::GeofenceStateChangeReport> impl_IGeofenceMonitor<D>::ReadReports() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Geolocation::Geofencing::GeofenceStateChangeReport> value;
    check_hresult(WINRT_SHIM(IGeofenceMonitor)->abi_ReadReports(put_abi(value)));
    return value;
}

template <typename D> event_token impl_IGeofenceMonitor<D>::StatusChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geofencing::GeofenceMonitor, Windows::Foundation::IInspectable> & eventHandler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IGeofenceMonitor)->add_StatusChanged(get_abi(eventHandler), &token));
    return token;
}

template <typename D> event_revoker<IGeofenceMonitor> impl_IGeofenceMonitor<D>::StatusChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::Geolocation::Geofencing::GeofenceMonitor, Windows::Foundation::IInspectable> & eventHandler) const
{
    return impl::make_event_revoker<D, IGeofenceMonitor>(this, &ABI::Windows::Devices::Geolocation::Geofencing::IGeofenceMonitor::remove_StatusChanged, StatusChanged(eventHandler));
}

template <typename D> void impl_IGeofenceMonitor<D>::StatusChanged(event_token token) const
{
    check_hresult(WINRT_SHIM(IGeofenceMonitor)->remove_StatusChanged(token));
}

inline Geofence::Geofence(hstring_view id, const Windows::Devices::Geolocation::IGeoshape & geoshape) :
    Geofence(get_activation_factory<Geofence, IGeofenceFactory>().Create(id, geoshape))
{}

inline Geofence::Geofence(hstring_view id, const Windows::Devices::Geolocation::IGeoshape & geoshape, Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates monitoredStates, bool singleUse) :
    Geofence(get_activation_factory<Geofence, IGeofenceFactory>().CreateWithMonitorStates(id, geoshape, monitoredStates, singleUse))
{}

inline Geofence::Geofence(hstring_view id, const Windows::Devices::Geolocation::IGeoshape & geoshape, Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates monitoredStates, bool singleUse, const Windows::Foundation::TimeSpan & dwellTime) :
    Geofence(get_activation_factory<Geofence, IGeofenceFactory>().CreateWithMonitorStatesAndDwellTime(id, geoshape, monitoredStates, singleUse, dwellTime))
{}

inline Geofence::Geofence(hstring_view id, const Windows::Devices::Geolocation::IGeoshape & geoshape, Windows::Devices::Geolocation::Geofencing::MonitoredGeofenceStates monitoredStates, bool singleUse, const Windows::Foundation::TimeSpan & dwellTime, const Windows::Foundation::DateTime & startTime, const Windows::Foundation::TimeSpan & duration) :
    Geofence(get_activation_factory<Geofence, IGeofenceFactory>().CreateWithMonitorStatesDwellTimeStartTimeAndDuration(id, geoshape, monitoredStates, singleUse, dwellTime, startTime, duration))
{}

inline Windows::Devices::Geolocation::Geofencing::GeofenceMonitor GeofenceMonitor::Current()
{
    return get_activation_factory<GeofenceMonitor, IGeofenceMonitorStatics>().Current();
}

}

}
#pragma warning(pop)
