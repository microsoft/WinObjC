// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Enumeration.Pnp.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
#define WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
template <> struct __declspec(uuid("09335560-6c6b-5a26-9348-97b781132b20")) __declspec(novtable) IKeyValuePair<hstring, Windows::Foundation::IInspectable> : impl_IKeyValuePair<hstring, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
#define WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
template <> struct __declspec(uuid("bb78502a-f79d-54fa-92c9-90c5039fdf7e")) __declspec(novtable) IMapView<hstring, Windows::Foundation::IInspectable> : impl_IMapView<hstring, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif

#ifndef WINRT_GENERIC_cce5a798_d269_5fce_99ce_ef0ae3cd0569
#define WINRT_GENERIC_cce5a798_d269_5fce_99ce_ef0ae3cd0569
template <> struct __declspec(uuid("cce5a798-d269-5fce-99ce-ef0ae3cd0569")) __declspec(novtable) IVectorView<Windows::Devices::Enumeration::Pnp::PnpObject> : impl_IVectorView<Windows::Devices::Enumeration::Pnp::PnpObject> {};
#endif

#ifndef WINRT_GENERIC_30b50092_36ee_53ff_9450_029004436c60
#define WINRT_GENERIC_30b50092_36ee_53ff_9450_029004436c60
template <> struct __declspec(uuid("30b50092-36ee-53ff-9450-029004436c60")) __declspec(novtable) IIterable<Windows::Devices::Enumeration::Pnp::PnpObject> : impl_IIterable<Windows::Devices::Enumeration::Pnp::PnpObject> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_d578eed2_58e5_5825_8af2_12f89387b656
#define WINRT_GENERIC_d578eed2_58e5_5825_8af2_12f89387b656
template <> struct __declspec(uuid("d578eed2-58e5-5825-8af2-12f89387b656")) __declspec(novtable) TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Devices::Enumeration::Pnp::PnpObject> : impl_TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Devices::Enumeration::Pnp::PnpObject> {};
#endif

#ifndef WINRT_GENERIC_af8f929d_8058_5c38_a3d8_30aa7a08b588
#define WINRT_GENERIC_af8f929d_8058_5c38_a3d8_30aa7a08b588
template <> struct __declspec(uuid("af8f929d-8058-5c38-a3d8-30aa7a08b588")) __declspec(novtable) TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Devices::Enumeration::Pnp::PnpObjectUpdate> : impl_TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Devices::Enumeration::Pnp::PnpObjectUpdate> {};
#endif

#ifndef WINRT_GENERIC_2ee2b4c9_b696_5ecc_b29b_f1e0ef5fe1f7
#define WINRT_GENERIC_2ee2b4c9_b696_5ecc_b29b_f1e0ef5fe1f7
template <> struct __declspec(uuid("2ee2b4c9-b696-5ecc-b29b-f1e0ef5fe1f7")) __declspec(novtable) TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Devices::Enumeration::Pnp::PnpObjectWatcher, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_22b0fb93_30e6_501a_bd3b_9fa3063e9c16
#define WINRT_GENERIC_22b0fb93_30e6_501a_bd3b_9fa3063e9c16
template <> struct __declspec(uuid("22b0fb93-30e6-501a-bd3b-9fa3063e9c16")) __declspec(novtable) IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObject> : impl_IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObject> {};
#endif

#ifndef WINRT_GENERIC_f383c2cc_f326_5bbe_95d1_cbc24714ef86
#define WINRT_GENERIC_f383c2cc_f326_5bbe_95d1_cbc24714ef86
template <> struct __declspec(uuid("f383c2cc-f326-5bbe-95d1-cbc24714ef86")) __declspec(novtable) IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObjectCollection> : impl_IAsyncOperation<Windows::Devices::Enumeration::Pnp::PnpObjectCollection> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_6bb6d2f1_b5fb_57f0_8251_f20cde5a6871
#define WINRT_GENERIC_6bb6d2f1_b5fb_57f0_8251_f20cde5a6871
template <> struct __declspec(uuid("6bb6d2f1-b5fb-57f0-8251-f20cde5a6871")) __declspec(novtable) IIterator<Windows::Devices::Enumeration::Pnp::PnpObject> : impl_IIterator<Windows::Devices::Enumeration::Pnp::PnpObject> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_9d615463_6879_521f_8e97_e66d3ddbc95e
#define WINRT_GENERIC_9d615463_6879_521f_8e97_e66d3ddbc95e
template <> struct __declspec(uuid("9d615463-6879-521f-8e97-e66d3ddbc95e")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Enumeration::Pnp::PnpObject> : impl_AsyncOperationCompletedHandler<Windows::Devices::Enumeration::Pnp::PnpObject> {};
#endif

#ifndef WINRT_GENERIC_811d834c_a15e_5522_b7f4_e53004fc58ff
#define WINRT_GENERIC_811d834c_a15e_5522_b7f4_e53004fc58ff
template <> struct __declspec(uuid("811d834c-a15e-5522-b7f4-e53004fc58ff")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Enumeration::Pnp::PnpObjectCollection> : impl_AsyncOperationCompletedHandler<Windows::Devices::Enumeration::Pnp::PnpObjectCollection> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
#define WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
template <> struct __declspec(uuid("fe2f3d47-5d47-5499-8374-430c7cda0204")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif

#ifndef WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
#define WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
template <> struct __declspec(uuid("5db5fa32-707c-5849-a06b-91c8eb9d10e8")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace Windows::Devices::Enumeration::Pnp {

struct IPnpObject :
    Windows::Foundation::IInspectable,
    impl::consume<IPnpObject>
{
    IPnpObject(std::nullptr_t = nullptr) noexcept {}
};

struct IPnpObjectStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPnpObjectStatics>
{
    IPnpObjectStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPnpObjectUpdate :
    Windows::Foundation::IInspectable,
    impl::consume<IPnpObjectUpdate>
{
    IPnpObjectUpdate(std::nullptr_t = nullptr) noexcept {}
};

struct IPnpObjectWatcher :
    Windows::Foundation::IInspectable,
    impl::consume<IPnpObjectWatcher>
{
    IPnpObjectWatcher(std::nullptr_t = nullptr) noexcept {}
};

}

}
