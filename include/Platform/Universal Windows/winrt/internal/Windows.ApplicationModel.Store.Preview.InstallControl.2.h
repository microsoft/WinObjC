// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Store.Preview.InstallControl.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif

#ifndef WINRT_GENERIC_92730467_501e_5b05_8826_926f86925b03
#define WINRT_GENERIC_92730467_501e_5b05_8826_926f86925b03
template <> struct __declspec(uuid("92730467-501e-5b05-8826-926f86925b03")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_48d7f874_a83c_55db_b2e6_940be9569869
#define WINRT_GENERIC_48d7f874_a83c_55db_b2e6_940be9569869
template <> struct __declspec(uuid("48d7f874-a83c-55db-b2e6-940be9569869")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> : impl_IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_abf1c837_dacd_5446_a032_3ee902880244
#define WINRT_GENERIC_abf1c837_dacd_5446_a032_3ee902880244
template <> struct __declspec(uuid("abf1c837-dacd-5446-a032-3ee902880244")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManager, Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManagerItemEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManager, Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallManagerItemEventArgs> {};
#endif

#ifndef WINRT_GENERIC_83b51cbf_35e0_59ad_ab3e_ffb3f03704f9
#define WINRT_GENERIC_83b51cbf_35e0_59ad_ab3e_ffb3f03704f9
template <> struct __declspec(uuid("83b51cbf-35e0-59ad-ab3e-ffb3f03704f9")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> : impl_IAsyncOperation<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> {};
#endif

#ifndef WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
#define WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
template <> struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a")) __declspec(novtable) AsyncOperationCompletedHandler<bool> : impl_AsyncOperationCompletedHandler<bool> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_ccaca81b_6cf7_56f0_b7ff_8ac5191e79bf
#define WINRT_GENERIC_ccaca81b_6cf7_56f0_b7ff_8ac5191e79bf
template <> struct __declspec(uuid("ccaca81b-6cf7-56f0-b7ff-8ac5191e79bf")) __declspec(novtable) IIterator<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> : impl_IIterator<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> {};
#endif

#ifndef WINRT_GENERIC_93e1cdc8_503f_55b1_915b_c0dc7888ce31
#define WINRT_GENERIC_93e1cdc8_503f_55b1_915b_c0dc7888ce31
template <> struct __declspec(uuid("93e1cdc8-503f-55b1-915b-c0dc7888ce31")) __declspec(novtable) IIterable<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> : impl_IIterable<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_a85c1ceb_0e8c_5422_b2ef_ad48ed338706
#define WINRT_GENERIC_a85c1ceb_0e8c_5422_b2ef_ad48ed338706
template <> struct __declspec(uuid("a85c1ceb-0e8c-5422-b2ef-ad48ed338706")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem> {};
#endif

#ifndef WINRT_GENERIC_9267e107_2ac6_5e0d_86e9_3154f616c68b
#define WINRT_GENERIC_9267e107_2ac6_5e0d_86e9_3154f616c68b
template <> struct __declspec(uuid("9267e107-2ac6-5e0d-86e9-3154f616c68b")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> {};
#endif

#ifndef WINRT_GENERIC_f92bfe4e_cf96_54cf_ab89_388ca004b5a9
#define WINRT_GENERIC_f92bfe4e_cf96_54cf_ab89_388ca004b5a9
template <> struct __declspec(uuid("f92bfe4e-cf96-54cf-ab89-388ca004b5a9")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Store::Preview::InstallControl::AppInstallItem>> {};
#endif


}

namespace Windows::ApplicationModel::Store::Preview::InstallControl {

struct IAppInstallItem :
    Windows::Foundation::IInspectable,
    impl::consume<IAppInstallItem>
{
    IAppInstallItem(std::nullptr_t = nullptr) noexcept {}
};

struct IAppInstallItem2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppInstallItem2>
{
    IAppInstallItem2(std::nullptr_t = nullptr) noexcept {}
};

struct IAppInstallManager :
    Windows::Foundation::IInspectable,
    impl::consume<IAppInstallManager>
{
    IAppInstallManager(std::nullptr_t = nullptr) noexcept {}
};

struct IAppInstallManager2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppInstallManager2>
{
    IAppInstallManager2(std::nullptr_t = nullptr) noexcept {}
};

struct IAppInstallManager3 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppInstallManager3>
{
    IAppInstallManager3(std::nullptr_t = nullptr) noexcept {}
};

struct IAppInstallManagerItemEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAppInstallManagerItemEventArgs>
{
    IAppInstallManagerItemEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAppInstallStatus :
    Windows::Foundation::IInspectable,
    impl::consume<IAppInstallStatus>
{
    IAppInstallStatus(std::nullptr_t = nullptr) noexcept {}
};

struct IAppInstallStatus2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppInstallStatus2>
{
    IAppInstallStatus2(std::nullptr_t = nullptr) noexcept {}
};

}

}
