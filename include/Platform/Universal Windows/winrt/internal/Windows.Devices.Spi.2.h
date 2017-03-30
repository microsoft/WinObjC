// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Spi.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8d720cdf_3934_5d3f_9a55_40e8063b086a
#define WINRT_GENERIC_8d720cdf_3934_5d3f_9a55_40e8063b086a
template <> struct __declspec(uuid("8d720cdf-3934-5d3f-9a55-40e8063b086a")) __declspec(novtable) IVectorView<int32_t> : impl_IVectorView<int32_t> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_feb8466a_878f_577b_bbca_89575cfc56e4
#define WINRT_GENERIC_feb8466a_878f_577b_bbca_89575cfc56e4
template <> struct __declspec(uuid("feb8466a-878f-577b-bbca-89575cfc56e4")) __declspec(novtable) IAsyncOperation<Windows::Devices::Spi::SpiDevice> : impl_IAsyncOperation<Windows::Devices::Spi::SpiDevice> {};
#endif

#ifndef WINRT_GENERIC_b6b0df6f_c097_5844_93bd_7821998fdb8e
#define WINRT_GENERIC_b6b0df6f_c097_5844_93bd_7821998fdb8e
template <> struct __declspec(uuid("b6b0df6f-c097-5844-93bd-7821998fdb8e")) __declspec(novtable) IAsyncOperation<Windows::Devices::Spi::SpiController> : impl_IAsyncOperation<Windows::Devices::Spi::SpiController> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_35fec489_44a2_5543_8a0c_b52e2f9cf87c
#define WINRT_GENERIC_35fec489_44a2_5543_8a0c_b52e2f9cf87c
template <> struct __declspec(uuid("35fec489-44a2-5543-8a0c-b52e2f9cf87c")) __declspec(novtable) IVectorView<Windows::Devices::Spi::SpiController> : impl_IVectorView<Windows::Devices::Spi::SpiController> {};
#endif

#ifndef WINRT_GENERIC_bfea7f78_50c2_5f1d_a6ea_9e978d2699ff
#define WINRT_GENERIC_bfea7f78_50c2_5f1d_a6ea_9e978d2699ff
template <> struct __declspec(uuid("bfea7f78-50c2-5f1d-a6ea-9e978d2699ff")) __declspec(novtable) IIterator<int32_t> : impl_IIterator<int32_t> {};
#endif

#ifndef WINRT_GENERIC_81a643fb_f51c_5565_83c4_f96425777b66
#define WINRT_GENERIC_81a643fb_f51c_5565_83c4_f96425777b66
template <> struct __declspec(uuid("81a643fb-f51c-5565-83c4-f96425777b66")) __declspec(novtable) IIterable<int32_t> : impl_IIterable<int32_t> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_a88a28ba_6966_55e7_8c81_7c65f74e39c0
#define WINRT_GENERIC_a88a28ba_6966_55e7_8c81_7c65f74e39c0
template <> struct __declspec(uuid("a88a28ba-6966-55e7-8c81-7c65f74e39c0")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Spi::SpiDevice> : impl_AsyncOperationCompletedHandler<Windows::Devices::Spi::SpiDevice> {};
#endif

#ifndef WINRT_GENERIC_5e94d949_a844_5b25_a3cc_afabeb18c1d2
#define WINRT_GENERIC_5e94d949_a844_5b25_a3cc_afabeb18c1d2
template <> struct __declspec(uuid("5e94d949-a844-5b25-a3cc-afabeb18c1d2")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Spi::SpiController> : impl_AsyncOperationCompletedHandler<Windows::Devices::Spi::SpiController> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_fd7d5997_544c_5be9_b0fa_1d0efbfc4a03
#define WINRT_GENERIC_fd7d5997_544c_5be9_b0fa_1d0efbfc4a03
template <> struct __declspec(uuid("fd7d5997-544c-5be9-b0fa-1d0efbfc4a03")) __declspec(novtable) IIterator<Windows::Devices::Spi::SpiController> : impl_IIterator<Windows::Devices::Spi::SpiController> {};
#endif

#ifndef WINRT_GENERIC_7b076938_dc1b_5368_9003_059291d37f35
#define WINRT_GENERIC_7b076938_dc1b_5368_9003_059291d37f35
template <> struct __declspec(uuid("7b076938-dc1b-5368-9003-059291d37f35")) __declspec(novtable) IIterable<Windows::Devices::Spi::SpiController> : impl_IIterable<Windows::Devices::Spi::SpiController> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_89624331_f802_56f7_9b33_17c616ecbcfa
#define WINRT_GENERIC_89624331_f802_56f7_9b33_17c616ecbcfa
template <> struct __declspec(uuid("89624331-f802-56f7-9b33-17c616ecbcfa")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Spi::SpiController>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Spi::SpiController>> {};
#endif

#ifndef WINRT_GENERIC_c8afc9cb_6807_57ec_84c9_9f3dbc003450
#define WINRT_GENERIC_c8afc9cb_6807_57ec_84c9_9f3dbc003450
template <> struct __declspec(uuid("c8afc9cb-6807-57ec-84c9-9f3dbc003450")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Spi::SpiController>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Spi::SpiController>> {};
#endif


}

namespace Windows::Devices::Spi {

struct ISpiBusInfo :
    Windows::Foundation::IInspectable,
    impl::consume<ISpiBusInfo>
{
    ISpiBusInfo(std::nullptr_t = nullptr) noexcept {}
};

struct ISpiConnectionSettings :
    Windows::Foundation::IInspectable,
    impl::consume<ISpiConnectionSettings>
{
    ISpiConnectionSettings(std::nullptr_t = nullptr) noexcept {}
};

struct ISpiConnectionSettingsFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ISpiConnectionSettingsFactory>
{
    ISpiConnectionSettingsFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ISpiController :
    Windows::Foundation::IInspectable,
    impl::consume<ISpiController>
{
    ISpiController(std::nullptr_t = nullptr) noexcept {}
};

struct ISpiControllerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISpiControllerStatics>
{
    ISpiControllerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISpiDevice :
    Windows::Foundation::IInspectable,
    impl::consume<ISpiDevice>,
    impl::require<ISpiDevice, Windows::Foundation::IClosable>
{
    ISpiDevice(std::nullptr_t = nullptr) noexcept {}
};

struct ISpiDeviceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISpiDeviceStatics>
{
    ISpiDeviceStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
