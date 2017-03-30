// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.DialProtocol.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
#define WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
template <> struct __declspec(uuid("98b9acc1-4b56-532e-ac73-03d5291cca90")) __declspec(novtable) IVector<hstring> : impl_IVector<hstring> {};
#endif

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_4512c15e_1fc4_5648_bd49_51533a3fe6b4
#define WINRT_GENERIC_4512c15e_1fc4_5648_bd49_51533a3fe6b4
template <> struct __declspec(uuid("4512c15e-1fc4-5648-bd49-51533a3fe6b4")) __declspec(novtable) IAsyncOperation<winrt::Windows::Media::DialProtocol::DialAppLaunchResult> : impl_IAsyncOperation<winrt::Windows::Media::DialProtocol::DialAppLaunchResult> {};
#endif

#ifndef WINRT_GENERIC_8598f24e_0d62_517a_961c_31fca73acedd
#define WINRT_GENERIC_8598f24e_0d62_517a_961c_31fca73acedd
template <> struct __declspec(uuid("8598f24e-0d62-517a-961c-31fca73acedd")) __declspec(novtable) IAsyncOperation<winrt::Windows::Media::DialProtocol::DialAppStopResult> : impl_IAsyncOperation<winrt::Windows::Media::DialProtocol::DialAppStopResult> {};
#endif

#ifndef WINRT_GENERIC_e50a07a2_2cef_5fc7_b14c_d6dd8517c58e
#define WINRT_GENERIC_e50a07a2_2cef_5fc7_b14c_d6dd8517c58e
template <> struct __declspec(uuid("e50a07a2-2cef-5fc7-b14c-d6dd8517c58e")) __declspec(novtable) IAsyncOperation<Windows::Media::DialProtocol::DialAppStateDetails> : impl_IAsyncOperation<Windows::Media::DialProtocol::DialAppStateDetails> {};
#endif

#ifndef WINRT_GENERIC_471cada5_1ee4_51c0_b6b5_bf72f5f50422
#define WINRT_GENERIC_471cada5_1ee4_51c0_b6b5_bf72f5f50422
template <> struct __declspec(uuid("471cada5-1ee4-51c0-b6b5-bf72f5f50422")) __declspec(novtable) IAsyncOperation<Windows::Media::DialProtocol::DialDevice> : impl_IAsyncOperation<Windows::Media::DialProtocol::DialDevice> {};
#endif

#ifndef WINRT_GENERIC_8375c0d7_e7c3_56bc_9880_46b69ca10d45
#define WINRT_GENERIC_8375c0d7_e7c3_56bc_9880_46b69ca10d45
template <> struct __declspec(uuid("8375c0d7-e7c3-56bc-9880-46b69ca10d45")) __declspec(novtable) TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDeviceSelectedEventArgs> : impl_TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDeviceSelectedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_13492af0_1c7f_57e8_b57e_a5ae8f2c462e
#define WINRT_GENERIC_13492af0_1c7f_57e8_b57e_a5ae8f2c462e
template <> struct __declspec(uuid("13492af0-1c7f-57e8-b57e-a5ae8f2c462e")) __declspec(novtable) TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDisconnectButtonClickedEventArgs> : impl_TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Media::DialProtocol::DialDisconnectButtonClickedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_dac94028_1b44_5f45_b9e3_abcf4ab044bf
#define WINRT_GENERIC_dac94028_1b44_5f45_b9e3_abcf4ab044bf
template <> struct __declspec(uuid("dac94028-1b44-5f45-b9e3-abcf4ab044bf")) __declspec(novtable) TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Media::DialProtocol::DialDevicePicker, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
#define WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
template <> struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a")) __declspec(novtable) AsyncOperationCompletedHandler<bool> : impl_AsyncOperationCompletedHandler<bool> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_164c0aa8_3d2b_579b_94a3_cc4925c695ec
#define WINRT_GENERIC_164c0aa8_3d2b_579b_94a3_cc4925c695ec
template <> struct __declspec(uuid("164c0aa8-3d2b-579b-94a3-cc4925c695ec")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::Media::DialProtocol::DialAppLaunchResult> : impl_AsyncOperationCompletedHandler<winrt::Windows::Media::DialProtocol::DialAppLaunchResult> {};
#endif

#ifndef WINRT_GENERIC_c755f54a_ef7b_563a_9b14_462e72d9665a
#define WINRT_GENERIC_c755f54a_ef7b_563a_9b14_462e72d9665a
template <> struct __declspec(uuid("c755f54a-ef7b-563a-9b14-462e72d9665a")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::Media::DialProtocol::DialAppStopResult> : impl_AsyncOperationCompletedHandler<winrt::Windows::Media::DialProtocol::DialAppStopResult> {};
#endif

#ifndef WINRT_GENERIC_38c62dd5_1f16_55c0_8ec7_ca0fc841d614
#define WINRT_GENERIC_38c62dd5_1f16_55c0_8ec7_ca0fc841d614
template <> struct __declspec(uuid("38c62dd5-1f16-55c0-8ec7-ca0fc841d614")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Media::DialProtocol::DialAppStateDetails> : impl_AsyncOperationCompletedHandler<Windows::Media::DialProtocol::DialAppStateDetails> {};
#endif

#ifndef WINRT_GENERIC_81bc7d1b_7d06_555f_811b_42ec0fa71b55
#define WINRT_GENERIC_81bc7d1b_7d06_555f_811b_42ec0fa71b55
template <> struct __declspec(uuid("81bc7d1b-7d06-555f-811b-42ec0fa71b55")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Media::DialProtocol::DialDevice> : impl_AsyncOperationCompletedHandler<Windows::Media::DialProtocol::DialDevice> {};
#endif


}

namespace Windows::Media::DialProtocol {

struct IDialApp :
    Windows::Foundation::IInspectable,
    impl::consume<IDialApp>
{
    IDialApp(std::nullptr_t = nullptr) noexcept {}
};

struct IDialAppStateDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IDialAppStateDetails>
{
    IDialAppStateDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IDialDevice :
    Windows::Foundation::IInspectable,
    impl::consume<IDialDevice>
{
    IDialDevice(std::nullptr_t = nullptr) noexcept {}
};

struct IDialDevice2 :
    Windows::Foundation::IInspectable,
    impl::consume<IDialDevice2>
{
    IDialDevice2(std::nullptr_t = nullptr) noexcept {}
};

struct IDialDevicePicker :
    Windows::Foundation::IInspectable,
    impl::consume<IDialDevicePicker>
{
    IDialDevicePicker(std::nullptr_t = nullptr) noexcept {}
};

struct IDialDevicePickerFilter :
    Windows::Foundation::IInspectable,
    impl::consume<IDialDevicePickerFilter>
{
    IDialDevicePickerFilter(std::nullptr_t = nullptr) noexcept {}
};

struct IDialDeviceSelectedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IDialDeviceSelectedEventArgs>
{
    IDialDeviceSelectedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IDialDeviceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IDialDeviceStatics>
{
    IDialDeviceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IDialDisconnectButtonClickedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IDialDisconnectButtonClickedEventArgs>
{
    IDialDisconnectButtonClickedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

}

}
