// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Authentication.Identity.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_3b631cbb_63f8_5eff_8815_69c822c09ce1
#define WINRT_GENERIC_3b631cbb_63f8_5eff_8815_69c822c09ce1
template <> struct __declspec(uuid("3b631cbb-63f8-5eff-8815-69c822c09ce1")) __declspec(novtable) IVectorView<Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo> : impl_IVectorView<Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo> {};
#endif

#ifndef WINRT_GENERIC_e3497259_1737_5fad_803b_9d2d29273e3b
#define WINRT_GENERIC_e3497259_1737_5fad_803b_9d2d29273e3b
template <> struct __declspec(uuid("e3497259-1737-5fad-803b-9d2d29273e3b")) __declspec(novtable) IIterator<Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo> : impl_IIterator<Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo> {};
#endif

#ifndef WINRT_GENERIC_e7eea796_77f9_5473_a913_734ea0e3ff46
#define WINRT_GENERIC_e7eea796_77f9_5473_a913_734ea0e3ff46
template <> struct __declspec(uuid("e7eea796-77f9-5473-a913-734ea0e3ff46")) __declspec(novtable) IIterable<Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo> : impl_IIterable<Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_0bd64c2f_8b1d_56d4_a707_fab5315e7278
#define WINRT_GENERIC_0bd64c2f_8b1d_56d4_a707_fab5315e7278
template <> struct __declspec(uuid("0bd64c2f-8b1d-56d4-a707-fab5315e7278")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo>> {};
#endif

#ifndef WINRT_GENERIC_67746c40_ade0_5981_ae23_104891748853
#define WINRT_GENERIC_67746c40_ade0_5981_ae23_104891748853
template <> struct __declspec(uuid("67746c40-ade0-5981-ae23-104891748853")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo>> {};
#endif


}

namespace Windows::Security::Authentication::Identity {

struct IEnterpriseKeyCredentialRegistrationInfo :
    Windows::Foundation::IInspectable,
    impl::consume<IEnterpriseKeyCredentialRegistrationInfo>
{
    IEnterpriseKeyCredentialRegistrationInfo(std::nullptr_t = nullptr) noexcept {}
};

struct IEnterpriseKeyCredentialRegistrationManager :
    Windows::Foundation::IInspectable,
    impl::consume<IEnterpriseKeyCredentialRegistrationManager>
{
    IEnterpriseKeyCredentialRegistrationManager(std::nullptr_t = nullptr) noexcept {}
};

struct IEnterpriseKeyCredentialRegistrationManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IEnterpriseKeyCredentialRegistrationManagerStatics>
{
    IEnterpriseKeyCredentialRegistrationManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
