// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Appointments.AppointmentsProvider.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5541d8a7_497c_5aa4_86fc_7713adbf2a2c
#define WINRT_GENERIC_5541d8a7_497c_5aa4_86fc_7713adbf2a2c
template <> struct __declspec(uuid("5541d8a7-497c-5aa4-86fc-7713adbf2a2c")) __declspec(novtable) IReference<Windows::Foundation::DateTime> : impl_IReference<Windows::Foundation::DateTime> {};
#endif


}

namespace Windows::ApplicationModel::Appointments::AppointmentsProvider {

struct IAddAppointmentOperation :
    Windows::Foundation::IInspectable,
    impl::consume<IAddAppointmentOperation>
{
    IAddAppointmentOperation(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentsProviderLaunchActionVerbsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentsProviderLaunchActionVerbsStatics>
{
    IAppointmentsProviderLaunchActionVerbsStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentsProviderLaunchActionVerbsStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentsProviderLaunchActionVerbsStatics2>
{
    IAppointmentsProviderLaunchActionVerbsStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IRemoveAppointmentOperation :
    Windows::Foundation::IInspectable,
    impl::consume<IRemoveAppointmentOperation>
{
    IRemoveAppointmentOperation(std::nullptr_t = nullptr) noexcept {}
};

struct IReplaceAppointmentOperation :
    Windows::Foundation::IInspectable,
    impl::consume<IReplaceAppointmentOperation>
{
    IReplaceAppointmentOperation(std::nullptr_t = nullptr) noexcept {}
};

}

}
