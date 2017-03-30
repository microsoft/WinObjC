// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Radios.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_65066c36_090b_5466_b8e5_e7565dc34175
#define WINRT_GENERIC_65066c36_090b_5466_b8e5_e7565dc34175
template <> struct __declspec(uuid("65066c36-090b-5466-b8e5-e7565dc34175")) __declspec(novtable) IVectorView<Windows::Devices::Radios::Radio> : impl_IVectorView<Windows::Devices::Radios::Radio> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_eac62c40_8dbc_5854_8ba0_b7b9940e7389
#define WINRT_GENERIC_eac62c40_8dbc_5854_8ba0_b7b9940e7389
template <> struct __declspec(uuid("eac62c40-8dbc-5854-8ba0-b7b9940e7389")) __declspec(novtable) IAsyncOperation<Windows::Devices::Radios::Radio> : impl_IAsyncOperation<Windows::Devices::Radios::Radio> {};
#endif

#ifndef WINRT_GENERIC_21fb30ef_072f_502c_9898_d0c3b2cd9ac5
#define WINRT_GENERIC_21fb30ef_072f_502c_9898_d0c3b2cd9ac5
template <> struct __declspec(uuid("21fb30ef-072f-502c-9898-d0c3b2cd9ac5")) __declspec(novtable) IAsyncOperation<winrt::Windows::Devices::Radios::RadioAccessStatus> : impl_IAsyncOperation<winrt::Windows::Devices::Radios::RadioAccessStatus> {};
#endif

#ifndef WINRT_GENERIC_fc6aa329_b586_5ebb_9e85_3f6b84ebdf18
#define WINRT_GENERIC_fc6aa329_b586_5ebb_9e85_3f6b84ebdf18
template <> struct __declspec(uuid("fc6aa329-b586-5ebb-9e85-3f6b84ebdf18")) __declspec(novtable) TypedEventHandler<Windows::Devices::Radios::Radio, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Devices::Radios::Radio, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_cf37ede7_eaec_5b8f_ad31_4d51abd9db05
#define WINRT_GENERIC_cf37ede7_eaec_5b8f_ad31_4d51abd9db05
template <> struct __declspec(uuid("cf37ede7-eaec-5b8f-ad31-4d51abd9db05")) __declspec(novtable) IIterator<Windows::Devices::Radios::Radio> : impl_IIterator<Windows::Devices::Radios::Radio> {};
#endif

#ifndef WINRT_GENERIC_e82500af_1f53_504e_b8be_dac4fbb69084
#define WINRT_GENERIC_e82500af_1f53_504e_b8be_dac4fbb69084
template <> struct __declspec(uuid("e82500af-1f53-504e-b8be-dac4fbb69084")) __declspec(novtable) IIterable<Windows::Devices::Radios::Radio> : impl_IIterable<Windows::Devices::Radios::Radio> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_8a5c7e3a_80e2_585b_8630_7a8e777f0354
#define WINRT_GENERIC_8a5c7e3a_80e2_585b_8630_7a8e777f0354
template <> struct __declspec(uuid("8a5c7e3a-80e2-585b-8630-7a8e777f0354")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Radios::Radio> : impl_AsyncOperationCompletedHandler<Windows::Devices::Radios::Radio> {};
#endif

#ifndef WINRT_GENERIC_bd248e73_f05f_574c_ae3d_9b95c4bf282a
#define WINRT_GENERIC_bd248e73_f05f_574c_ae3d_9b95c4bf282a
template <> struct __declspec(uuid("bd248e73-f05f-574c-ae3d-9b95c4bf282a")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::Devices::Radios::RadioAccessStatus> : impl_AsyncOperationCompletedHandler<winrt::Windows::Devices::Radios::RadioAccessStatus> {};
#endif

#ifndef WINRT_GENERIC_040b54a1_203e_58f5_943f_c1cca86bd532
#define WINRT_GENERIC_040b54a1_203e_58f5_943f_c1cca86bd532
template <> struct __declspec(uuid("040b54a1-203e-58f5-943f-c1cca86bd532")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Radios::Radio>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::Radios::Radio>> {};
#endif

#ifndef WINRT_GENERIC_d30691e6_60a0_59c9_8965_5bbe282e8208
#define WINRT_GENERIC_d30691e6_60a0_59c9_8965_5bbe282e8208
template <> struct __declspec(uuid("d30691e6-60a0-59c9-8965-5bbe282e8208")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Radios::Radio>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Devices::Radios::Radio>> {};
#endif


}

namespace Windows::Devices::Radios {

struct IRadio :
    Windows::Foundation::IInspectable,
    impl::consume<IRadio>
{
    IRadio(std::nullptr_t = nullptr) noexcept {}
};

struct IRadioStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IRadioStatics>
{
    IRadioStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
