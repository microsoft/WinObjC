// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.HumanInterfaceDevice.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_ef60385f_be78_584b_aaef_7829ada2b0de
#define WINRT_GENERIC_ef60385f_be78_584b_aaef_7829ada2b0de
template <> struct __declspec(uuid("ef60385f-be78-584b-aaef-7829ada2b0de")) __declspec(novtable) IAsyncOperation<uint32_t> : impl_IAsyncOperation<uint32_t> {};
#endif

#ifndef WINRT_GENERIC_a76a4fbf_5177_5256_84a8_b31a8dcf1048
#define WINRT_GENERIC_a76a4fbf_5177_5256_84a8_b31a8dcf1048
template <> struct __declspec(uuid("a76a4fbf-5177-5256-84a8-b31a8dcf1048")) __declspec(novtable) IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidDevice> : impl_IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidDevice> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_96f1faac_348f_5b8f_a71d_2d650e0b11f2
#define WINRT_GENERIC_96f1faac_348f_5b8f_a71d_2d650e0b11f2
template <> struct __declspec(uuid("96f1faac-348f-5b8f-a71d-2d650e0b11f2")) __declspec(novtable) IVectorView<Windows::Devices::HumanInterfaceDevice::HidCollection> : impl_IVectorView<Windows::Devices::HumanInterfaceDevice::HidCollection> {};
#endif

#ifndef WINRT_GENERIC_0e417dac_591a_5de0_afd6_0b2c04c304e7
#define WINRT_GENERIC_0e417dac_591a_5de0_afd6_0b2c04c304e7
template <> struct __declspec(uuid("0e417dac-591a-5de0-afd6-0b2c04c304e7")) __declspec(novtable) IVectorView<Windows::Devices::HumanInterfaceDevice::HidBooleanControl> : impl_IVectorView<Windows::Devices::HumanInterfaceDevice::HidBooleanControl> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_b3e28917_cd48_57b3_a0b1_321432e85bd6
#define WINRT_GENERIC_b3e28917_cd48_57b3_a0b1_321432e85bd6
template <> struct __declspec(uuid("b3e28917-cd48-57b3-a0b1-321432e85bd6")) __declspec(novtable) IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidInputReport> : impl_IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidInputReport> {};
#endif

#ifndef WINRT_GENERIC_d72fb6f9_42f6_5f45_bfe3_29af247c2e85
#define WINRT_GENERIC_d72fb6f9_42f6_5f45_bfe3_29af247c2e85
template <> struct __declspec(uuid("d72fb6f9-42f6-5f45-bfe3-29af247c2e85")) __declspec(novtable) IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidFeatureReport> : impl_IAsyncOperation<Windows::Devices::HumanInterfaceDevice::HidFeatureReport> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_aab72786_ec34_536f_a7c5_27394753df2c
#define WINRT_GENERIC_aab72786_ec34_536f_a7c5_27394753df2c
template <> struct __declspec(uuid("aab72786-ec34-536f-a7c5-27394753df2c")) __declspec(novtable) IVectorView<Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription> : impl_IVectorView<Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription> {};
#endif

#ifndef WINRT_GENERIC_e02ca66c_610a_51b4_aef9_3707b697b985
#define WINRT_GENERIC_e02ca66c_610a_51b4_aef9_3707b697b985
template <> struct __declspec(uuid("e02ca66c-610a-51b4-aef9-3707b697b985")) __declspec(novtable) IVectorView<Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription> : impl_IVectorView<Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_31e757c8_8f6a_540b_938b_aba79b6f03ec
#define WINRT_GENERIC_31e757c8_8f6a_540b_938b_aba79b6f03ec
template <> struct __declspec(uuid("31e757c8-8f6a-540b-938b-aba79b6f03ec")) __declspec(novtable) TypedEventHandler<Windows::Devices::HumanInterfaceDevice::HidDevice, Windows::Devices::HumanInterfaceDevice::HidInputReportReceivedEventArgs> : impl_TypedEventHandler<Windows::Devices::HumanInterfaceDevice::HidDevice, Windows::Devices::HumanInterfaceDevice::HidInputReportReceivedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_9343b6e7_e3d2_5e4a_ab2d_2bce4919a6a4
#define WINRT_GENERIC_9343b6e7_e3d2_5e4a_ab2d_2bce4919a6a4
template <> struct __declspec(uuid("9343b6e7-e3d2-5e4a-ab2d-2bce4919a6a4")) __declspec(novtable) AsyncOperationCompletedHandler<uint32_t> : impl_AsyncOperationCompletedHandler<uint32_t> {};
#endif

#ifndef WINRT_GENERIC_b0e8e149_0cb6_55a7_bcc1_d996324d65c4
#define WINRT_GENERIC_b0e8e149_0cb6_55a7_bcc1_d996324d65c4
template <> struct __declspec(uuid("b0e8e149-0cb6-55a7-bcc1-d996324d65c4")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::HumanInterfaceDevice::HidDevice> : impl_AsyncOperationCompletedHandler<Windows::Devices::HumanInterfaceDevice::HidDevice> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_cefcee70_c7ff_57c1_a675_a0df8976a988
#define WINRT_GENERIC_cefcee70_c7ff_57c1_a675_a0df8976a988
template <> struct __declspec(uuid("cefcee70-c7ff-57c1-a675-a0df8976a988")) __declspec(novtable) IIterator<Windows::Devices::HumanInterfaceDevice::HidCollection> : impl_IIterator<Windows::Devices::HumanInterfaceDevice::HidCollection> {};
#endif

#ifndef WINRT_GENERIC_bbeada0f_708f_5b5e_a017_5c64ffb96b69
#define WINRT_GENERIC_bbeada0f_708f_5b5e_a017_5c64ffb96b69
template <> struct __declspec(uuid("bbeada0f-708f-5b5e-a017-5c64ffb96b69")) __declspec(novtable) IIterable<Windows::Devices::HumanInterfaceDevice::HidCollection> : impl_IIterable<Windows::Devices::HumanInterfaceDevice::HidCollection> {};
#endif

#ifndef WINRT_GENERIC_5cde3c23_d054_53d6_abf1_41e73379b472
#define WINRT_GENERIC_5cde3c23_d054_53d6_abf1_41e73379b472
template <> struct __declspec(uuid("5cde3c23-d054-53d6-abf1-41e73379b472")) __declspec(novtable) IIterator<Windows::Devices::HumanInterfaceDevice::HidBooleanControl> : impl_IIterator<Windows::Devices::HumanInterfaceDevice::HidBooleanControl> {};
#endif

#ifndef WINRT_GENERIC_1111e585_5ab0_5d2b_8aed_b6d6186d1c3f
#define WINRT_GENERIC_1111e585_5ab0_5d2b_8aed_b6d6186d1c3f
template <> struct __declspec(uuid("1111e585-5ab0-5d2b-8aed-b6d6186d1c3f")) __declspec(novtable) IIterable<Windows::Devices::HumanInterfaceDevice::HidBooleanControl> : impl_IIterable<Windows::Devices::HumanInterfaceDevice::HidBooleanControl> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_01c83770_03ab_5576_98b4_8d75ce1a9885
#define WINRT_GENERIC_01c83770_03ab_5576_98b4_8d75ce1a9885
template <> struct __declspec(uuid("01c83770-03ab-5576-98b4-8d75ce1a9885")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::HumanInterfaceDevice::HidInputReport> : impl_AsyncOperationCompletedHandler<Windows::Devices::HumanInterfaceDevice::HidInputReport> {};
#endif

#ifndef WINRT_GENERIC_db643555_3d16_57fe_b7ef_2bdbd719fdbf
#define WINRT_GENERIC_db643555_3d16_57fe_b7ef_2bdbd719fdbf
template <> struct __declspec(uuid("db643555-3d16-57fe-b7ef-2bdbd719fdbf")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::HumanInterfaceDevice::HidFeatureReport> : impl_AsyncOperationCompletedHandler<Windows::Devices::HumanInterfaceDevice::HidFeatureReport> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_203203b0_b7f4_542d_b0d0_9caa1fb55d7f
#define WINRT_GENERIC_203203b0_b7f4_542d_b0d0_9caa1fb55d7f
template <> struct __declspec(uuid("203203b0-b7f4-542d-b0d0-9caa1fb55d7f")) __declspec(novtable) IIterator<Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription> : impl_IIterator<Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription> {};
#endif

#ifndef WINRT_GENERIC_d0ff0fed_a156_58bf_9411_5777df9d57bf
#define WINRT_GENERIC_d0ff0fed_a156_58bf_9411_5777df9d57bf
template <> struct __declspec(uuid("d0ff0fed-a156-58bf-9411-5777df9d57bf")) __declspec(novtable) IIterable<Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription> : impl_IIterable<Windows::Devices::HumanInterfaceDevice::HidBooleanControlDescription> {};
#endif

#ifndef WINRT_GENERIC_52b9c36e_7d95_5d1c_acab_23c19ea76f01
#define WINRT_GENERIC_52b9c36e_7d95_5d1c_acab_23c19ea76f01
template <> struct __declspec(uuid("52b9c36e-7d95-5d1c-acab-23c19ea76f01")) __declspec(novtable) IIterator<Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription> : impl_IIterator<Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription> {};
#endif

#ifndef WINRT_GENERIC_868f060d_e0d4_571b_b2f7_431d6984a513
#define WINRT_GENERIC_868f060d_e0d4_571b_b2f7_431d6984a513
template <> struct __declspec(uuid("868f060d-e0d4-571b-b2f7-431d6984a513")) __declspec(novtable) IIterable<Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription> : impl_IIterable<Windows::Devices::HumanInterfaceDevice::HidNumericControlDescription> {};
#endif


}

namespace Windows::Devices::HumanInterfaceDevice {

struct IHidBooleanControl :
    Windows::Foundation::IInspectable,
    impl::consume<IHidBooleanControl>
{
    IHidBooleanControl(std::nullptr_t = nullptr) noexcept {}
};

struct IHidBooleanControlDescription :
    Windows::Foundation::IInspectable,
    impl::consume<IHidBooleanControlDescription>
{
    IHidBooleanControlDescription(std::nullptr_t = nullptr) noexcept {}
};

struct IHidBooleanControlDescription2 :
    Windows::Foundation::IInspectable,
    impl::consume<IHidBooleanControlDescription2>
{
    IHidBooleanControlDescription2(std::nullptr_t = nullptr) noexcept {}
};

struct IHidCollection :
    Windows::Foundation::IInspectable,
    impl::consume<IHidCollection>
{
    IHidCollection(std::nullptr_t = nullptr) noexcept {}
};

struct IHidDevice :
    Windows::Foundation::IInspectable,
    impl::consume<IHidDevice>,
    impl::require<IHidDevice, Windows::Foundation::IClosable>
{
    IHidDevice(std::nullptr_t = nullptr) noexcept {}
};

struct IHidDeviceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IHidDeviceStatics>
{
    IHidDeviceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IHidFeatureReport :
    Windows::Foundation::IInspectable,
    impl::consume<IHidFeatureReport>
{
    IHidFeatureReport(std::nullptr_t = nullptr) noexcept {}
};

struct IHidInputReport :
    Windows::Foundation::IInspectable,
    impl::consume<IHidInputReport>
{
    IHidInputReport(std::nullptr_t = nullptr) noexcept {}
};

struct IHidInputReportReceivedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IHidInputReportReceivedEventArgs>
{
    IHidInputReportReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IHidNumericControl :
    Windows::Foundation::IInspectable,
    impl::consume<IHidNumericControl>
{
    IHidNumericControl(std::nullptr_t = nullptr) noexcept {}
};

struct IHidNumericControlDescription :
    Windows::Foundation::IInspectable,
    impl::consume<IHidNumericControlDescription>
{
    IHidNumericControlDescription(std::nullptr_t = nullptr) noexcept {}
};

struct IHidOutputReport :
    Windows::Foundation::IInspectable,
    impl::consume<IHidOutputReport>
{
    IHidOutputReport(std::nullptr_t = nullptr) noexcept {}
};

}

}
