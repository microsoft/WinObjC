// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.UserDataAccounts.SystemAccess.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_3e1fe603_f897_5263_b328_0806426b8a79
#define WINRT_GENERIC_3e1fe603_f897_5263_b328_0806426b8a79
template <> struct __declspec(uuid("3e1fe603-f897-5263-b328-0806426b8a79")) __declspec(novtable) IAsyncOperation<hstring> : impl_IAsyncOperation<hstring> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif

#ifndef WINRT_GENERIC_a9c3ea6e_9dd9_52fe_9d27_f9e4dedd4d3f
#define WINRT_GENERIC_a9c3ea6e_9dd9_52fe_9d27_f9e4dedd4d3f
template <> struct __declspec(uuid("a9c3ea6e-9dd9-52fe-9d27-f9e4dedd4d3f")) __declspec(novtable) IIterable<Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> : impl_IIterable<Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_469859f3_6b7b_5399_8a8c_fe615b95ae07
#define WINRT_GENERIC_469859f3_6b7b_5399_8a8c_fe615b95ae07
template <> struct __declspec(uuid("469859f3-6b7b-5399-8a8c-fe615b95ae07")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> : impl_IAsyncOperation<Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> {};
#endif

#ifndef WINRT_GENERIC_b79a741f_7fb5_50ae_9e99_911201ec3d41
#define WINRT_GENERIC_b79a741f_7fb5_50ae_9e99_911201ec3d41
template <> struct __declspec(uuid("b79a741f-7fb5-50ae-9e99-911201ec3d41")) __declspec(novtable) AsyncOperationCompletedHandler<hstring> : impl_AsyncOperationCompletedHandler<hstring> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_51705a87_8dcb_5971_8d6b_ca8ae6a955ad
#define WINRT_GENERIC_51705a87_8dcb_5971_8d6b_ca8ae6a955ad
template <> struct __declspec(uuid("51705a87-8dcb-5971-8d6b-ca8ae6a955ad")) __declspec(novtable) IIterator<Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> : impl_IIterator<Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cbee2c48_e3ed_5ebd_a4ae_56583388a49a
#define WINRT_GENERIC_cbee2c48_e3ed_5ebd_a4ae_56583388a49a
template <> struct __declspec(uuid("cbee2c48-e3ed-5ebd-a4ae-56583388a49a")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::UserDataAccounts::SystemAccess::DeviceAccountConfiguration> {};
#endif

#ifndef WINRT_GENERIC_2f92b529_119b_575a_a419_3904b4e41af2
#define WINRT_GENERIC_2f92b529_119b_575a_a419_3904b4e41af2
template <> struct __declspec(uuid("2f92b529-119b-575a-a419-3904b4e41af2")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> {};
#endif

#ifndef WINRT_GENERIC_7c7899be_5f2e_5bf3_ade5_ad98b772c7cd
#define WINRT_GENERIC_7c7899be_5f2e_5bf3_ade5_ad98b772c7cd
template <> struct __declspec(uuid("7c7899be-5f2e-5bf3-ade5-ad98b772c7cd")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<hstring>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<hstring>> {};
#endif


}

namespace Windows::ApplicationModel::UserDataAccounts::SystemAccess {

struct IDeviceAccountConfiguration :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceAccountConfiguration>
{
    IDeviceAccountConfiguration(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceAccountConfiguration2 :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceAccountConfiguration2>
{
    IDeviceAccountConfiguration2(std::nullptr_t = nullptr) noexcept {}
};

struct IUserDataAccountSystemAccessManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IUserDataAccountSystemAccessManagerStatics>
{
    IUserDataAccountSystemAccessManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IUserDataAccountSystemAccessManagerStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IUserDataAccountSystemAccessManagerStatics2>
{
    IUserDataAccountSystemAccessManagerStatics2(std::nullptr_t = nullptr) noexcept {}
};

}

}
