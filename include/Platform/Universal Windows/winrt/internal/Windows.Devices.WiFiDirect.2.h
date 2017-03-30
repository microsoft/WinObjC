// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.WiFiDirect.1.h"
#include "Windows.Devices.Enumeration.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_dad01b61_a82d_566c_ba82_224c11500669
#define WINRT_GENERIC_dad01b61_a82d_566c_ba82_224c11500669
template <> struct __declspec(uuid("dad01b61-a82d-566c-ba82-224c11500669")) __declspec(novtable) IAsyncOperation<Windows::Devices::WiFiDirect::WiFiDirectDevice> : impl_IAsyncOperation<Windows::Devices::WiFiDirect::WiFiDirectDevice> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_b8c55492_e4de_5ba7_8476_d3bab557cdd6
#define WINRT_GENERIC_b8c55492_e4de_5ba7_8476_d3bab557cdd6
template <> struct __declspec(uuid("b8c55492-e4de-5ba7-8476-d3bab557cdd6")) __declspec(novtable) IVector<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> : impl_IVector<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> {};
#endif

#ifndef WINRT_GENERIC_9b498bc0_b474_5587_b65c_e600965f8fd0
#define WINRT_GENERIC_9b498bc0_b474_5587_b65c_e600965f8fd0
template <> struct __declspec(uuid("9b498bc0-b474-5587-b65c-e600965f8fd0")) __declspec(novtable) IVector<winrt::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod> : impl_IVector<winrt::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_de73cba7_370d_550c_b23a_53dd0b4e480d
#define WINRT_GENERIC_de73cba7_370d_550c_b23a_53dd0b4e480d
template <> struct __declspec(uuid("de73cba7-370d-550c-b23a-53dd0b4e480d")) __declspec(novtable) TypedEventHandler<Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisher, Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatusChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisher, Windows::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatusChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_d04b0403_1fe2_532f_8e47_4823a14e624f
#define WINRT_GENERIC_d04b0403_1fe2_532f_8e47_4823a14e624f
template <> struct __declspec(uuid("d04b0403-1fe2-532f-8e47-4823a14e624f")) __declspec(novtable) TypedEventHandler<Windows::Devices::WiFiDirect::WiFiDirectConnectionListener, Windows::Devices::WiFiDirect::WiFiDirectConnectionRequestedEventArgs> : impl_TypedEventHandler<Windows::Devices::WiFiDirect::WiFiDirectConnectionListener, Windows::Devices::WiFiDirect::WiFiDirectConnectionRequestedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8780a851_6d48_5006_9288_81f3d7045a96
#define WINRT_GENERIC_8780a851_6d48_5006_9288_81f3d7045a96
template <> struct __declspec(uuid("8780a851-6d48-5006-9288-81f3d7045a96")) __declspec(novtable) IVectorView<Windows::Networking::EndpointPair> : impl_IVectorView<Windows::Networking::EndpointPair> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_9208929a_2a3c_50ad_aa08_a0a986edbabe
#define WINRT_GENERIC_9208929a_2a3c_50ad_aa08_a0a986edbabe
template <> struct __declspec(uuid("9208929a-2a3c-50ad-aa08-a0a986edbabe")) __declspec(novtable) TypedEventHandler<Windows::Devices::WiFiDirect::WiFiDirectDevice, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Devices::WiFiDirect::WiFiDirectDevice, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_d7ec83c4_a17b_51bf_8997_aa33b9102dc9
#define WINRT_GENERIC_d7ec83c4_a17b_51bf_8997_aa33b9102dc9
template <> struct __declspec(uuid("d7ec83c4-a17b-51bf-8997-aa33b9102dc9")) __declspec(novtable) IIterable<Windows::Networking::EndpointPair> : impl_IIterable<Windows::Networking::EndpointPair> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_d34abe17_fb19_57be_bc41_0eb83dea151c
#define WINRT_GENERIC_d34abe17_fb19_57be_bc41_0eb83dea151c
template <> struct __declspec(uuid("d34abe17-fb19-57be-bc41-0eb83dea151c")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::WiFiDirect::WiFiDirectDevice> : impl_AsyncOperationCompletedHandler<Windows::Devices::WiFiDirect::WiFiDirectDevice> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_cf806026_c915_553e_af3c_8da43871b693
#define WINRT_GENERIC_cf806026_c915_553e_af3c_8da43871b693
template <> struct __declspec(uuid("cf806026-c915-553e-af3c-8da43871b693")) __declspec(novtable) IIterator<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> : impl_IIterator<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> {};
#endif

#ifndef WINRT_GENERIC_19c1ca4e_9561_5253_96d9_dbaf28d47d89
#define WINRT_GENERIC_19c1ca4e_9561_5253_96d9_dbaf28d47d89
template <> struct __declspec(uuid("19c1ca4e-9561-5253-96d9-dbaf28d47d89")) __declspec(novtable) IIterable<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> : impl_IIterable<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> {};
#endif

#ifndef WINRT_GENERIC_6dcffadb_04c5_535e_add4_1389b3be6eca
#define WINRT_GENERIC_6dcffadb_04c5_535e_add4_1389b3be6eca
template <> struct __declspec(uuid("6dcffadb-04c5-535e-add4-1389b3be6eca")) __declspec(novtable) IVectorView<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> : impl_IVectorView<Windows::Devices::WiFiDirect::WiFiDirectInformationElement> {};
#endif

#ifndef WINRT_GENERIC_201940f9_a368_57f4_9ef2_3f64e243e0a4
#define WINRT_GENERIC_201940f9_a368_57f4_9ef2_3f64e243e0a4
template <> struct __declspec(uuid("201940f9-a368-57f4-9ef2-3f64e243e0a4")) __declspec(novtable) IIterator<winrt::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod> : impl_IIterator<winrt::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod> {};
#endif

#ifndef WINRT_GENERIC_794f12da_2dc6_5277_82dc_b0781610537b
#define WINRT_GENERIC_794f12da_2dc6_5277_82dc_b0781610537b
template <> struct __declspec(uuid("794f12da-2dc6-5277-82dc-b0781610537b")) __declspec(novtable) IIterable<winrt::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod> : impl_IIterable<winrt::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod> {};
#endif

#ifndef WINRT_GENERIC_61a32670_04d3_551d_ad66_bd04e9ef5c78
#define WINRT_GENERIC_61a32670_04d3_551d_ad66_bd04e9ef5c78
template <> struct __declspec(uuid("61a32670-04d3-551d-ad66-bd04e9ef5c78")) __declspec(novtable) IVectorView<winrt::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod> : impl_IVectorView<winrt::Windows::Devices::WiFiDirect::WiFiDirectConfigurationMethod> {};
#endif

#ifndef WINRT_GENERIC_c899ff9f_e6f5_5673_810c_04e2ff98704f
#define WINRT_GENERIC_c899ff9f_e6f5_5673_810c_04e2ff98704f
template <> struct __declspec(uuid("c899ff9f-e6f5-5673-810c-04e2ff98704f")) __declspec(novtable) IIterator<Windows::Networking::EndpointPair> : impl_IIterator<Windows::Networking::EndpointPair> {};
#endif


}

namespace Windows::Devices::WiFiDirect {

struct IWiFiDirectAdvertisement :
    Windows::Foundation::IInspectable,
    impl::consume<IWiFiDirectAdvertisement>
{
    IWiFiDirectAdvertisement(std::nullptr_t = nullptr) noexcept {}
};

struct IWiFiDirectAdvertisement2 :
    Windows::Foundation::IInspectable,
    impl::consume<IWiFiDirectAdvertisement2>
{
    IWiFiDirectAdvertisement2(std::nullptr_t = nullptr) noexcept {}
};

struct IWiFiDirectAdvertisementPublisher :
    Windows::Foundation::IInspectable,
    impl::consume<IWiFiDirectAdvertisementPublisher>
{
    IWiFiDirectAdvertisementPublisher(std::nullptr_t = nullptr) noexcept {}
};

struct IWiFiDirectAdvertisementPublisherStatusChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IWiFiDirectAdvertisementPublisherStatusChangedEventArgs>
{
    IWiFiDirectAdvertisementPublisherStatusChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IWiFiDirectConnectionListener :
    Windows::Foundation::IInspectable,
    impl::consume<IWiFiDirectConnectionListener>
{
    IWiFiDirectConnectionListener(std::nullptr_t = nullptr) noexcept {}
};

struct IWiFiDirectConnectionParameters :
    Windows::Foundation::IInspectable,
    impl::consume<IWiFiDirectConnectionParameters>
{
    IWiFiDirectConnectionParameters(std::nullptr_t = nullptr) noexcept {}
};

struct IWiFiDirectConnectionParameters2 :
    Windows::Foundation::IInspectable,
    impl::consume<IWiFiDirectConnectionParameters2>
{
    IWiFiDirectConnectionParameters2(std::nullptr_t = nullptr) noexcept {}
};

struct IWiFiDirectConnectionParametersStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IWiFiDirectConnectionParametersStatics>
{
    IWiFiDirectConnectionParametersStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IWiFiDirectConnectionRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IWiFiDirectConnectionRequest>,
    impl::require<IWiFiDirectConnectionRequest, Windows::Foundation::IClosable>
{
    IWiFiDirectConnectionRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IWiFiDirectConnectionRequestedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IWiFiDirectConnectionRequestedEventArgs>
{
    IWiFiDirectConnectionRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IWiFiDirectDevice :
    Windows::Foundation::IInspectable,
    impl::consume<IWiFiDirectDevice>,
    impl::require<IWiFiDirectDevice, Windows::Foundation::IClosable>
{
    IWiFiDirectDevice(std::nullptr_t = nullptr) noexcept {}
};

struct IWiFiDirectDeviceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IWiFiDirectDeviceStatics>
{
    IWiFiDirectDeviceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IWiFiDirectDeviceStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IWiFiDirectDeviceStatics2>
{
    IWiFiDirectDeviceStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IWiFiDirectInformationElement :
    Windows::Foundation::IInspectable,
    impl::consume<IWiFiDirectInformationElement>
{
    IWiFiDirectInformationElement(std::nullptr_t = nullptr) noexcept {}
};

struct IWiFiDirectInformationElementStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IWiFiDirectInformationElementStatics>
{
    IWiFiDirectInformationElementStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IWiFiDirectLegacySettings :
    Windows::Foundation::IInspectable,
    impl::consume<IWiFiDirectLegacySettings>
{
    IWiFiDirectLegacySettings(std::nullptr_t = nullptr) noexcept {}
};

}

}
