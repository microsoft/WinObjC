// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.ExchangeActiveSyncProvisioning.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_fc3a733a_7ded_5e92_a569_b43389ee8827
#define WINRT_GENERIC_fc3a733a_7ded_5e92_a569_b43389ee8827
template <> struct __declspec(uuid("fc3a733a-7ded-5e92-a569-b43389ee8827")) __declspec(novtable) IAsyncOperation<Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults> : impl_IAsyncOperation<Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults> {};
#endif

#ifndef WINRT_GENERIC_24a4131a_ed31_5eff_972e_750b956404d0
#define WINRT_GENERIC_24a4131a_ed31_5eff_972e_750b956404d0
template <> struct __declspec(uuid("24a4131a-ed31-5eff-972e-750b956404d0")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults> : impl_AsyncOperationCompletedHandler<Windows::Security::ExchangeActiveSyncProvisioning::EasComplianceResults> {};
#endif


}

namespace Windows::Security::ExchangeActiveSyncProvisioning {

struct IEasClientDeviceInformation :
    Windows::Foundation::IInspectable,
    impl::consume<IEasClientDeviceInformation>
{
    IEasClientDeviceInformation(std::nullptr_t = nullptr) noexcept {}
};

struct IEasClientDeviceInformation2 :
    Windows::Foundation::IInspectable,
    impl::consume<IEasClientDeviceInformation2>,
    impl::require<IEasClientDeviceInformation2, Windows::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>
{
    IEasClientDeviceInformation2(std::nullptr_t = nullptr) noexcept {}
};

struct IEasClientSecurityPolicy :
    Windows::Foundation::IInspectable,
    impl::consume<IEasClientSecurityPolicy>
{
    IEasClientSecurityPolicy(std::nullptr_t = nullptr) noexcept {}
};

struct IEasComplianceResults :
    Windows::Foundation::IInspectable,
    impl::consume<IEasComplianceResults>
{
    IEasComplianceResults(std::nullptr_t = nullptr) noexcept {}
};

struct IEasComplianceResults2 :
    Windows::Foundation::IInspectable,
    impl::consume<IEasComplianceResults2>,
    impl::require<IEasComplianceResults2, Windows::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>
{
    IEasComplianceResults2(std::nullptr_t = nullptr) noexcept {}
};

}

}
