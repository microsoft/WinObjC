// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.AppService.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_0d0e6663_2639_5a9a_9cbc_30d7d4ce533b
#define WINRT_GENERIC_0d0e6663_2639_5a9a_9cbc_30d7d4ce533b
template <> struct __declspec(uuid("0d0e6663-2639-5a9a-9cbc-30d7d4ce533b")) __declspec(novtable) IAsyncOperation<winrt::Windows::ApplicationModel::AppService::AppServiceConnectionStatus> : impl_IAsyncOperation<winrt::Windows::ApplicationModel::AppService::AppServiceConnectionStatus> {};
#endif

#ifndef WINRT_GENERIC_98fdb842_5a0b_539a_a35c_55ac5f228612
#define WINRT_GENERIC_98fdb842_5a0b_539a_a35c_55ac5f228612
template <> struct __declspec(uuid("98fdb842-5a0b-539a-a35c-55ac5f228612")) __declspec(novtable) IAsyncOperation<winrt::Windows::ApplicationModel::AppService::AppServiceResponseStatus> : impl_IAsyncOperation<winrt::Windows::ApplicationModel::AppService::AppServiceResponseStatus> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8246ed12_33e8_52b3_a5c5_19779de9999e
#define WINRT_GENERIC_8246ed12_33e8_52b3_a5c5_19779de9999e
template <> struct __declspec(uuid("8246ed12-33e8-52b3-a5c5-19779de9999e")) __declspec(novtable) IVectorView<Windows::ApplicationModel::AppInfo> : impl_IVectorView<Windows::ApplicationModel::AppInfo> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_48755a7c_c88f_5ef0_9b4c_876fcc2610b4
#define WINRT_GENERIC_48755a7c_c88f_5ef0_9b4c_876fcc2610b4
template <> struct __declspec(uuid("48755a7c-c88f-5ef0-9b4c-876fcc2610b4")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::AppService::AppServiceResponse> : impl_IAsyncOperation<Windows::ApplicationModel::AppService::AppServiceResponse> {};
#endif

#ifndef WINRT_GENERIC_18c67d61_4176_5553_b18d_d8f57fe79552
#define WINRT_GENERIC_18c67d61_4176_5553_b18d_d8f57fe79552
template <> struct __declspec(uuid("18c67d61-4176-5553-b18d-d8f57fe79552")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::AppService::AppServiceConnection, Windows::ApplicationModel::AppService::AppServiceRequestReceivedEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::AppService::AppServiceConnection, Windows::ApplicationModel::AppService::AppServiceRequestReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_e4efa98d_4bfc_5e61_a233_688f5f06521f
#define WINRT_GENERIC_e4efa98d_4bfc_5e61_a233_688f5f06521f
template <> struct __declspec(uuid("e4efa98d-4bfc-5e61-a233-688f5f06521f")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::AppService::AppServiceConnection, Windows::ApplicationModel::AppService::AppServiceClosedEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::AppService::AppServiceConnection, Windows::ApplicationModel::AppService::AppServiceClosedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_b6c6bbf2_72ca_5799_a651_d1990670097b
#define WINRT_GENERIC_b6c6bbf2_72ca_5799_a651_d1990670097b
template <> struct __declspec(uuid("b6c6bbf2-72ca-5799-a651-d1990670097b")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::AppService::AppServiceConnectionStatus> : impl_AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::AppService::AppServiceConnectionStatus> {};
#endif

#ifndef WINRT_GENERIC_b824383d_32e0_5579_8670_a06a61457f20
#define WINRT_GENERIC_b824383d_32e0_5579_8670_a06a61457f20
template <> struct __declspec(uuid("b824383d-32e0-5579-8670-a06a61457f20")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::AppService::AppServiceResponseStatus> : impl_AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::AppService::AppServiceResponseStatus> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_69cec62c_41eb_5d69_a475_29ee22323dd8
#define WINRT_GENERIC_69cec62c_41eb_5d69_a475_29ee22323dd8
template <> struct __declspec(uuid("69cec62c-41eb-5d69-a475-29ee22323dd8")) __declspec(novtable) IIterator<Windows::ApplicationModel::AppInfo> : impl_IIterator<Windows::ApplicationModel::AppInfo> {};
#endif

#ifndef WINRT_GENERIC_63d0bffe_0e34_55b3_83d5_314caff2b137
#define WINRT_GENERIC_63d0bffe_0e34_55b3_83d5_314caff2b137
template <> struct __declspec(uuid("63d0bffe-0e34-55b3-83d5-314caff2b137")) __declspec(novtable) IIterable<Windows::ApplicationModel::AppInfo> : impl_IIterable<Windows::ApplicationModel::AppInfo> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_7ea7d7ec_e164_52c3_8e32_bba7126d9028
#define WINRT_GENERIC_7ea7d7ec_e164_52c3_8e32_bba7126d9028
template <> struct __declspec(uuid("7ea7d7ec-e164-52c3-8e32-bba7126d9028")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::AppService::AppServiceResponse> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::AppService::AppServiceResponse> {};
#endif

#ifndef WINRT_GENERIC_07543d91_8610_5152_b0e4_43d6e4cdd0cb
#define WINRT_GENERIC_07543d91_8610_5152_b0e4_43d6e4cdd0cb
template <> struct __declspec(uuid("07543d91-8610-5152-b0e4-43d6e4cdd0cb")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> {};
#endif

#ifndef WINRT_GENERIC_07f25b6f_f054_5649_a5ce_b348ddc618b6
#define WINRT_GENERIC_07f25b6f_f054_5649_a5ce_b348ddc618b6
template <> struct __declspec(uuid("07f25b6f-f054-5649-a5ce-b348ddc618b6")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> {};
#endif


}

namespace Windows::ApplicationModel::AppService {

struct IAppServiceCatalogStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAppServiceCatalogStatics>
{
    IAppServiceCatalogStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IAppServiceClosedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAppServiceClosedEventArgs>
{
    IAppServiceClosedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAppServiceConnection :
    Windows::Foundation::IInspectable,
    impl::consume<IAppServiceConnection>,
    impl::require<IAppServiceConnection, Windows::Foundation::IClosable>
{
    IAppServiceConnection(std::nullptr_t = nullptr) noexcept {}
};

struct IAppServiceConnection2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppServiceConnection2>
{
    IAppServiceConnection2(std::nullptr_t = nullptr) noexcept {}
};

struct IAppServiceDeferral :
    Windows::Foundation::IInspectable,
    impl::consume<IAppServiceDeferral>
{
    IAppServiceDeferral(std::nullptr_t = nullptr) noexcept {}
};

struct IAppServiceRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IAppServiceRequest>
{
    IAppServiceRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IAppServiceRequestReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAppServiceRequestReceivedEventArgs>
{
    IAppServiceRequestReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAppServiceResponse :
    Windows::Foundation::IInspectable,
    impl::consume<IAppServiceResponse>
{
    IAppServiceResponse(std::nullptr_t = nullptr) noexcept {}
};

struct IAppServiceTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IAppServiceTriggerDetails>
{
    IAppServiceTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IAppServiceTriggerDetails2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppServiceTriggerDetails2>
{
    IAppServiceTriggerDetails2(std::nullptr_t = nullptr) noexcept {}
};

}

}
