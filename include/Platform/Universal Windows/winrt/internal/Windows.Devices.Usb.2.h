// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Usb.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_ef60385f_be78_584b_aaef_7829ada2b0de
#define WINRT_GENERIC_ef60385f_be78_584b_aaef_7829ada2b0de
template <> struct __declspec(uuid("ef60385f-be78-584b-aaef-7829ada2b0de")) __declspec(novtable) IAsyncOperation<uint32_t> : impl_IAsyncOperation<uint32_t> {};
#endif

#ifndef WINRT_GENERIC_3bee8834_b9a7_5a80_a746_5ef097227878
#define WINRT_GENERIC_3bee8834_b9a7_5a80_a746_5ef097227878
template <> struct __declspec(uuid("3bee8834-b9a7-5a80-a746-5ef097227878")) __declspec(novtable) IAsyncOperation<Windows::Storage::Streams::IBuffer> : impl_IAsyncOperation<Windows::Storage::Streams::IBuffer> {};
#endif

#ifndef WINRT_GENERIC_e5198cc8_2873_55f5_b0a1_84ff9e4aad62
#define WINRT_GENERIC_e5198cc8_2873_55f5_b0a1_84ff9e4aad62
template <> struct __declspec(uuid("e5198cc8-2873-55f5-b0a1-84ff9e4aad62")) __declspec(novtable) IReference<uint8_t> : impl_IReference<uint8_t> {};
#endif

#ifndef WINRT_GENERIC_2138c5ed_b71a_5166_9948_d55792748f5c
#define WINRT_GENERIC_2138c5ed_b71a_5166_9948_d55792748f5c
template <> struct __declspec(uuid("2138c5ed-b71a-5166-9948-d55792748f5c")) __declspec(novtable) IAsyncOperation<Windows::Devices::Usb::UsbDevice> : impl_IAsyncOperation<Windows::Devices::Usb::UsbDevice> {};
#endif

#ifndef WINRT_GENERIC_e6db9449_f36a_50f2_926c_2afd85c49f01
#define WINRT_GENERIC_e6db9449_f36a_50f2_926c_2afd85c49f01
template <> struct __declspec(uuid("e6db9449-f36a-50f2-926c-2afd85c49f01")) __declspec(novtable) TypedEventHandler<Windows::Devices::Usb::UsbInterruptInPipe, Windows::Devices::Usb::UsbInterruptInEventArgs> : impl_TypedEventHandler<Windows::Devices::Usb::UsbInterruptInPipe, Windows::Devices::Usb::UsbInterruptInEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_9c69ec7f_2e42_58cd_a74a_f4974811134d
#define WINRT_GENERIC_9c69ec7f_2e42_58cd_a74a_f4974811134d
template <> struct __declspec(uuid("9c69ec7f-2e42-58cd-a74a-f4974811134d")) __declspec(novtable) IVectorView<Windows::Devices::Usb::UsbInterface> : impl_IVectorView<Windows::Devices::Usb::UsbInterface> {};
#endif

#ifndef WINRT_GENERIC_5408baa2_291e_537a_b61f_137062f7ff7d
#define WINRT_GENERIC_5408baa2_291e_537a_b61f_137062f7ff7d
template <> struct __declspec(uuid("5408baa2-291e-537a-b61f-137062f7ff7d")) __declspec(novtable) IVectorView<Windows::Devices::Usb::UsbDescriptor> : impl_IVectorView<Windows::Devices::Usb::UsbDescriptor> {};
#endif

#ifndef WINRT_GENERIC_a93c84bc_6484_5959_b61a_703cc7115f6f
#define WINRT_GENERIC_a93c84bc_6484_5959_b61a_703cc7115f6f
template <> struct __declspec(uuid("a93c84bc-6484-5959-b61a-703cc7115f6f")) __declspec(novtable) IVectorView<Windows::Devices::Usb::UsbBulkInPipe> : impl_IVectorView<Windows::Devices::Usb::UsbBulkInPipe> {};
#endif

#ifndef WINRT_GENERIC_37469574_b4c5_5ba0_9616_894dd822ff5b
#define WINRT_GENERIC_37469574_b4c5_5ba0_9616_894dd822ff5b
template <> struct __declspec(uuid("37469574-b4c5-5ba0-9616-894dd822ff5b")) __declspec(novtable) IVectorView<Windows::Devices::Usb::UsbInterruptInPipe> : impl_IVectorView<Windows::Devices::Usb::UsbInterruptInPipe> {};
#endif

#ifndef WINRT_GENERIC_0a873512_15f1_5e8e_a72a_045cfd7a5e83
#define WINRT_GENERIC_0a873512_15f1_5e8e_a72a_045cfd7a5e83
template <> struct __declspec(uuid("0a873512-15f1-5e8e-a72a-045cfd7a5e83")) __declspec(novtable) IVectorView<Windows::Devices::Usb::UsbBulkOutPipe> : impl_IVectorView<Windows::Devices::Usb::UsbBulkOutPipe> {};
#endif

#ifndef WINRT_GENERIC_748196c8_83bf_5ec3_8d28_a3112b3ee3cc
#define WINRT_GENERIC_748196c8_83bf_5ec3_8d28_a3112b3ee3cc
template <> struct __declspec(uuid("748196c8-83bf-5ec3-8d28-a3112b3ee3cc")) __declspec(novtable) IVectorView<Windows::Devices::Usb::UsbInterruptOutPipe> : impl_IVectorView<Windows::Devices::Usb::UsbInterruptOutPipe> {};
#endif

#ifndef WINRT_GENERIC_71194af7_77c2_54d5_a116_287f0b7fd53f
#define WINRT_GENERIC_71194af7_77c2_54d5_a116_287f0b7fd53f
template <> struct __declspec(uuid("71194af7-77c2-54d5-a116-287f0b7fd53f")) __declspec(novtable) IVectorView<Windows::Devices::Usb::UsbInterfaceSetting> : impl_IVectorView<Windows::Devices::Usb::UsbInterfaceSetting> {};
#endif

#ifndef WINRT_GENERIC_9c69ac78_309e_5763_af26_9706ffa47ec0
#define WINRT_GENERIC_9c69ac78_309e_5763_af26_9706ffa47ec0
template <> struct __declspec(uuid("9c69ac78-309e-5763-af26-9706ffa47ec0")) __declspec(novtable) IVectorView<Windows::Devices::Usb::UsbBulkInEndpointDescriptor> : impl_IVectorView<Windows::Devices::Usb::UsbBulkInEndpointDescriptor> {};
#endif

#ifndef WINRT_GENERIC_3fc7f890_218e_5057_904d_6387c591cc93
#define WINRT_GENERIC_3fc7f890_218e_5057_904d_6387c591cc93
template <> struct __declspec(uuid("3fc7f890-218e-5057-904d-6387c591cc93")) __declspec(novtable) IVectorView<Windows::Devices::Usb::UsbInterruptInEndpointDescriptor> : impl_IVectorView<Windows::Devices::Usb::UsbInterruptInEndpointDescriptor> {};
#endif

#ifndef WINRT_GENERIC_22a53676_a3ea_5dcd_bb39_b28a5327c4a3
#define WINRT_GENERIC_22a53676_a3ea_5dcd_bb39_b28a5327c4a3
template <> struct __declspec(uuid("22a53676-a3ea-5dcd-bb39-b28a5327c4a3")) __declspec(novtable) IVectorView<Windows::Devices::Usb::UsbBulkOutEndpointDescriptor> : impl_IVectorView<Windows::Devices::Usb::UsbBulkOutEndpointDescriptor> {};
#endif

#ifndef WINRT_GENERIC_984e7e15_c5ac_5140_a3c0_b583190085d7
#define WINRT_GENERIC_984e7e15_c5ac_5140_a3c0_b583190085d7
template <> struct __declspec(uuid("984e7e15-c5ac-5140-a3c0-b583190085d7")) __declspec(novtable) IVectorView<Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor> : impl_IVectorView<Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_9343b6e7_e3d2_5e4a_ab2d_2bce4919a6a4
#define WINRT_GENERIC_9343b6e7_e3d2_5e4a_ab2d_2bce4919a6a4
template <> struct __declspec(uuid("9343b6e7-e3d2-5e4a-ab2d-2bce4919a6a4")) __declspec(novtable) AsyncOperationCompletedHandler<uint32_t> : impl_AsyncOperationCompletedHandler<uint32_t> {};
#endif

#ifndef WINRT_GENERIC_51c3d2fd_b8a1_5620_b746_7ee6d533aca3
#define WINRT_GENERIC_51c3d2fd_b8a1_5620_b746_7ee6d533aca3
template <> struct __declspec(uuid("51c3d2fd-b8a1-5620-b746-7ee6d533aca3")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::Streams::IBuffer> : impl_AsyncOperationCompletedHandler<Windows::Storage::Streams::IBuffer> {};
#endif

#ifndef WINRT_GENERIC_7331254f_6caf_587d_9c2a_018c66d312db
#define WINRT_GENERIC_7331254f_6caf_587d_9c2a_018c66d312db
template <> struct __declspec(uuid("7331254f-6caf-587d-9c2a-018c66d312db")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Usb::UsbDevice> : impl_AsyncOperationCompletedHandler<Windows::Devices::Usb::UsbDevice> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_216b5a5f_63e3_5a9b_9c99_b09cbc0ff3b1
#define WINRT_GENERIC_216b5a5f_63e3_5a9b_9c99_b09cbc0ff3b1
template <> struct __declspec(uuid("216b5a5f-63e3-5a9b-9c99-b09cbc0ff3b1")) __declspec(novtable) IIterator<Windows::Devices::Usb::UsbInterface> : impl_IIterator<Windows::Devices::Usb::UsbInterface> {};
#endif

#ifndef WINRT_GENERIC_f54037ed_92e9_590d_b904_3ad7bfa9a621
#define WINRT_GENERIC_f54037ed_92e9_590d_b904_3ad7bfa9a621
template <> struct __declspec(uuid("f54037ed-92e9-590d-b904-3ad7bfa9a621")) __declspec(novtable) IIterable<Windows::Devices::Usb::UsbInterface> : impl_IIterable<Windows::Devices::Usb::UsbInterface> {};
#endif

#ifndef WINRT_GENERIC_521598ed_0167_528e_990d_52abb712f072
#define WINRT_GENERIC_521598ed_0167_528e_990d_52abb712f072
template <> struct __declspec(uuid("521598ed-0167-528e-990d-52abb712f072")) __declspec(novtable) IIterator<Windows::Devices::Usb::UsbDescriptor> : impl_IIterator<Windows::Devices::Usb::UsbDescriptor> {};
#endif

#ifndef WINRT_GENERIC_989909a5_5a03_51fb_bd94_84da7bda8819
#define WINRT_GENERIC_989909a5_5a03_51fb_bd94_84da7bda8819
template <> struct __declspec(uuid("989909a5-5a03-51fb-bd94-84da7bda8819")) __declspec(novtable) IIterable<Windows::Devices::Usb::UsbDescriptor> : impl_IIterable<Windows::Devices::Usb::UsbDescriptor> {};
#endif

#ifndef WINRT_GENERIC_d7af2c5b_528d_5cbb_a997_d830ade704c7
#define WINRT_GENERIC_d7af2c5b_528d_5cbb_a997_d830ade704c7
template <> struct __declspec(uuid("d7af2c5b-528d-5cbb-a997-d830ade704c7")) __declspec(novtable) IIterator<Windows::Devices::Usb::UsbBulkInPipe> : impl_IIterator<Windows::Devices::Usb::UsbBulkInPipe> {};
#endif

#ifndef WINRT_GENERIC_2201a671_42d2_508d_a848_64b5447083c8
#define WINRT_GENERIC_2201a671_42d2_508d_a848_64b5447083c8
template <> struct __declspec(uuid("2201a671-42d2-508d-a848-64b5447083c8")) __declspec(novtable) IIterable<Windows::Devices::Usb::UsbBulkInPipe> : impl_IIterable<Windows::Devices::Usb::UsbBulkInPipe> {};
#endif

#ifndef WINRT_GENERIC_e3a7b1c0_74f6_5292_a22a_672aa2b49985
#define WINRT_GENERIC_e3a7b1c0_74f6_5292_a22a_672aa2b49985
template <> struct __declspec(uuid("e3a7b1c0-74f6-5292-a22a-672aa2b49985")) __declspec(novtable) IIterator<Windows::Devices::Usb::UsbInterruptInPipe> : impl_IIterator<Windows::Devices::Usb::UsbInterruptInPipe> {};
#endif

#ifndef WINRT_GENERIC_39aef336_18aa_5be4_86d9_e332fe2632f3
#define WINRT_GENERIC_39aef336_18aa_5be4_86d9_e332fe2632f3
template <> struct __declspec(uuid("39aef336-18aa-5be4-86d9-e332fe2632f3")) __declspec(novtable) IIterable<Windows::Devices::Usb::UsbInterruptInPipe> : impl_IIterable<Windows::Devices::Usb::UsbInterruptInPipe> {};
#endif

#ifndef WINRT_GENERIC_46dd2f6a_573b_5c45_b168_9223038491dd
#define WINRT_GENERIC_46dd2f6a_573b_5c45_b168_9223038491dd
template <> struct __declspec(uuid("46dd2f6a-573b-5c45-b168-9223038491dd")) __declspec(novtable) IIterator<Windows::Devices::Usb::UsbBulkOutPipe> : impl_IIterator<Windows::Devices::Usb::UsbBulkOutPipe> {};
#endif

#ifndef WINRT_GENERIC_9824caba_5ca6_5c2d_80cf_1949026d7857
#define WINRT_GENERIC_9824caba_5ca6_5c2d_80cf_1949026d7857
template <> struct __declspec(uuid("9824caba-5ca6-5c2d-80cf-1949026d7857")) __declspec(novtable) IIterable<Windows::Devices::Usb::UsbBulkOutPipe> : impl_IIterable<Windows::Devices::Usb::UsbBulkOutPipe> {};
#endif

#ifndef WINRT_GENERIC_cbd8d8a8_2286_5cbd_a6e4_962742ffd91a
#define WINRT_GENERIC_cbd8d8a8_2286_5cbd_a6e4_962742ffd91a
template <> struct __declspec(uuid("cbd8d8a8-2286-5cbd-a6e4-962742ffd91a")) __declspec(novtable) IIterator<Windows::Devices::Usb::UsbInterruptOutPipe> : impl_IIterator<Windows::Devices::Usb::UsbInterruptOutPipe> {};
#endif

#ifndef WINRT_GENERIC_e61a011e_4abe_53f2_83b3_ed4a949d2e3f
#define WINRT_GENERIC_e61a011e_4abe_53f2_83b3_ed4a949d2e3f
template <> struct __declspec(uuid("e61a011e-4abe-53f2-83b3-ed4a949d2e3f")) __declspec(novtable) IIterable<Windows::Devices::Usb::UsbInterruptOutPipe> : impl_IIterable<Windows::Devices::Usb::UsbInterruptOutPipe> {};
#endif

#ifndef WINRT_GENERIC_71267ec7_5697_5dea_b2f8_14cf698ec0ad
#define WINRT_GENERIC_71267ec7_5697_5dea_b2f8_14cf698ec0ad
template <> struct __declspec(uuid("71267ec7-5697-5dea-b2f8-14cf698ec0ad")) __declspec(novtable) IIterator<Windows::Devices::Usb::UsbInterfaceSetting> : impl_IIterator<Windows::Devices::Usb::UsbInterfaceSetting> {};
#endif

#ifndef WINRT_GENERIC_1aaf5739_9c2c_533e_a0e9_d53fdb45d15d
#define WINRT_GENERIC_1aaf5739_9c2c_533e_a0e9_d53fdb45d15d
template <> struct __declspec(uuid("1aaf5739-9c2c-533e-a0e9-d53fdb45d15d")) __declspec(novtable) IIterable<Windows::Devices::Usb::UsbInterfaceSetting> : impl_IIterable<Windows::Devices::Usb::UsbInterfaceSetting> {};
#endif

#ifndef WINRT_GENERIC_ea511030_89c4_503d_8caf_667f4230d2a9
#define WINRT_GENERIC_ea511030_89c4_503d_8caf_667f4230d2a9
template <> struct __declspec(uuid("ea511030-89c4-503d-8caf-667f4230d2a9")) __declspec(novtable) IIterator<Windows::Devices::Usb::UsbBulkInEndpointDescriptor> : impl_IIterator<Windows::Devices::Usb::UsbBulkInEndpointDescriptor> {};
#endif

#ifndef WINRT_GENERIC_101b1fd9_f1c9_5dda_9ad4_71176fa839b2
#define WINRT_GENERIC_101b1fd9_f1c9_5dda_9ad4_71176fa839b2
template <> struct __declspec(uuid("101b1fd9-f1c9-5dda-9ad4-71176fa839b2")) __declspec(novtable) IIterable<Windows::Devices::Usb::UsbBulkInEndpointDescriptor> : impl_IIterable<Windows::Devices::Usb::UsbBulkInEndpointDescriptor> {};
#endif

#ifndef WINRT_GENERIC_6717500f_ec1c_5b12_bf33_0e3e3d244587
#define WINRT_GENERIC_6717500f_ec1c_5b12_bf33_0e3e3d244587
template <> struct __declspec(uuid("6717500f-ec1c-5b12-bf33-0e3e3d244587")) __declspec(novtable) IIterator<Windows::Devices::Usb::UsbInterruptInEndpointDescriptor> : impl_IIterator<Windows::Devices::Usb::UsbInterruptInEndpointDescriptor> {};
#endif

#ifndef WINRT_GENERIC_8a7bac69_1f10_59c7_9837_72cfed7154a4
#define WINRT_GENERIC_8a7bac69_1f10_59c7_9837_72cfed7154a4
template <> struct __declspec(uuid("8a7bac69-1f10-59c7-9837-72cfed7154a4")) __declspec(novtable) IIterable<Windows::Devices::Usb::UsbInterruptInEndpointDescriptor> : impl_IIterable<Windows::Devices::Usb::UsbInterruptInEndpointDescriptor> {};
#endif

#ifndef WINRT_GENERIC_a8b89ab3_883d_5361_9903_f489cc62bea5
#define WINRT_GENERIC_a8b89ab3_883d_5361_9903_f489cc62bea5
template <> struct __declspec(uuid("a8b89ab3-883d-5361-9903-f489cc62bea5")) __declspec(novtable) IIterator<Windows::Devices::Usb::UsbBulkOutEndpointDescriptor> : impl_IIterator<Windows::Devices::Usb::UsbBulkOutEndpointDescriptor> {};
#endif

#ifndef WINRT_GENERIC_b80beb39_62b3_5f59_b3e7_882cc9c5b0c0
#define WINRT_GENERIC_b80beb39_62b3_5f59_b3e7_882cc9c5b0c0
template <> struct __declspec(uuid("b80beb39-62b3-5f59-b3e7-882cc9c5b0c0")) __declspec(novtable) IIterable<Windows::Devices::Usb::UsbBulkOutEndpointDescriptor> : impl_IIterable<Windows::Devices::Usb::UsbBulkOutEndpointDescriptor> {};
#endif

#ifndef WINRT_GENERIC_4b6426db_db32_5b51_adad_04532ea94acd
#define WINRT_GENERIC_4b6426db_db32_5b51_adad_04532ea94acd
template <> struct __declspec(uuid("4b6426db-db32-5b51-adad-04532ea94acd")) __declspec(novtable) IIterator<Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor> : impl_IIterator<Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor> {};
#endif

#ifndef WINRT_GENERIC_09393d62_2316_536b_8a10_7038884ab2a7
#define WINRT_GENERIC_09393d62_2316_536b_8a10_7038884ab2a7
template <> struct __declspec(uuid("09393d62-2316-536b-8a10-7038884ab2a7")) __declspec(novtable) IIterable<Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor> : impl_IIterable<Windows::Devices::Usb::UsbInterruptOutEndpointDescriptor> {};
#endif


}

namespace Windows::Devices::Usb {

struct IUsbBulkInEndpointDescriptor :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbBulkInEndpointDescriptor>
{
    IUsbBulkInEndpointDescriptor(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbBulkInPipe :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbBulkInPipe>
{
    IUsbBulkInPipe(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbBulkOutEndpointDescriptor :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbBulkOutEndpointDescriptor>
{
    IUsbBulkOutEndpointDescriptor(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbBulkOutPipe :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbBulkOutPipe>
{
    IUsbBulkOutPipe(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbConfiguration :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbConfiguration>
{
    IUsbConfiguration(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbConfigurationDescriptor :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbConfigurationDescriptor>
{
    IUsbConfigurationDescriptor(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbConfigurationDescriptorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbConfigurationDescriptorStatics>
{
    IUsbConfigurationDescriptorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbControlRequestType :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbControlRequestType>
{
    IUsbControlRequestType(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbDescriptor :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbDescriptor>
{
    IUsbDescriptor(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbDevice :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbDevice>,
    impl::require<IUsbDevice, Windows::Foundation::IClosable>
{
    IUsbDevice(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbDeviceClass :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbDeviceClass>
{
    IUsbDeviceClass(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbDeviceClasses :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbDeviceClasses>
{
    IUsbDeviceClasses(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbDeviceClassesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbDeviceClassesStatics>
{
    IUsbDeviceClassesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbDeviceDescriptor :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbDeviceDescriptor>
{
    IUsbDeviceDescriptor(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbDeviceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbDeviceStatics>
{
    IUsbDeviceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbEndpointDescriptor :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbEndpointDescriptor>
{
    IUsbEndpointDescriptor(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbEndpointDescriptorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbEndpointDescriptorStatics>
{
    IUsbEndpointDescriptorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbInterface :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbInterface>
{
    IUsbInterface(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbInterfaceDescriptor :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbInterfaceDescriptor>
{
    IUsbInterfaceDescriptor(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbInterfaceDescriptorStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbInterfaceDescriptorStatics>
{
    IUsbInterfaceDescriptorStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbInterfaceSetting :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbInterfaceSetting>
{
    IUsbInterfaceSetting(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbInterruptInEndpointDescriptor :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbInterruptInEndpointDescriptor>
{
    IUsbInterruptInEndpointDescriptor(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbInterruptInEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbInterruptInEventArgs>
{
    IUsbInterruptInEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbInterruptInPipe :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbInterruptInPipe>
{
    IUsbInterruptInPipe(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbInterruptOutEndpointDescriptor :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbInterruptOutEndpointDescriptor>
{
    IUsbInterruptOutEndpointDescriptor(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbInterruptOutPipe :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbInterruptOutPipe>
{
    IUsbInterruptOutPipe(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbSetupPacket :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbSetupPacket>
{
    IUsbSetupPacket(std::nullptr_t = nullptr) noexcept {}
};

struct IUsbSetupPacketFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IUsbSetupPacketFactory>
{
    IUsbSetupPacketFactory(std::nullptr_t = nullptr) noexcept {}
};

}

}
