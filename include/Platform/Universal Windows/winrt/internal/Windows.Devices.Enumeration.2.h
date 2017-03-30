// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.Enumeration.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Storage.Streams.1.h"
#include "Windows.Storage.Streams.2.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
#define WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
template <> struct __declspec(uuid("09335560-6c6b-5a26-9348-97b781132b20")) __declspec(novtable) IKeyValuePair<hstring, Windows::Foundation::IInspectable> : impl_IKeyValuePair<hstring, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
#define WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
template <> struct __declspec(uuid("98b9acc1-4b56-532e-ac73-03d5291cca90")) __declspec(novtable) IVector<hstring> : impl_IVector<hstring> {};
#endif

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
#define WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
template <> struct __declspec(uuid("bb78502a-f79d-54fa-92c9-90c5039fdf7e")) __declspec(novtable) IMapView<hstring, Windows::Foundation::IInspectable> : impl_IMapView<hstring, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif

#ifndef WINRT_GENERIC_ee662d37_b0eb_5729_9832_156fd2889d48
#define WINRT_GENERIC_ee662d37_b0eb_5729_9832_156fd2889d48
template <> struct __declspec(uuid("ee662d37-b0eb-5729-9832-156fd2889d48")) __declspec(novtable) IVector<winrt::Windows::Devices::Enumeration::DeviceClass> : impl_IVector<winrt::Windows::Devices::Enumeration::DeviceClass> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_47e48c88_1c56_5b58_96a2_8e813d25077a
#define WINRT_GENERIC_47e48c88_1c56_5b58_96a2_8e813d25077a
template <> struct __declspec(uuid("47e48c88-1c56-5b58-96a2-8e813d25077a")) __declspec(novtable) TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceSelectedEventArgs> : impl_TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceSelectedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_35dd0319_5723_506c_8896_1a28b82be798
#define WINRT_GENERIC_35dd0319_5723_506c_8896_1a28b82be798
template <> struct __declspec(uuid("35dd0319-5723-506c-8896-1a28b82be798")) __declspec(novtable) TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceDisconnectButtonClickedEventArgs> : impl_TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Devices::Enumeration::DeviceDisconnectButtonClickedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_62c6d98c_57ee_5bb8_a41c_958d20c3f3e8
#define WINRT_GENERIC_62c6d98c_57ee_5bb8_a41c_958d20c3f3e8
template <> struct __declspec(uuid("62c6d98c-57ee-5bb8-a41c-958d20c3f3e8")) __declspec(novtable) TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Devices::Enumeration::DevicePicker, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_07faa053_eb2f_5cba_b25b_d9d57be6715f
#define WINRT_GENERIC_07faa053_eb2f_5cba_b25b_d9d57be6715f
template <> struct __declspec(uuid("07faa053-eb2f-5cba-b25b-d9d57be6715f")) __declspec(novtable) IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> : impl_IAsyncOperation<Windows::Devices::Enumeration::DeviceInformation> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_e170688f_3495_5bf6_aab5_9cac17e0f10f
#define WINRT_GENERIC_e170688f_3495_5bf6_aab5_9cac17e0f10f
template <> struct __declspec(uuid("e170688f-3495-5bf6-aab5-9cac17e0f10f")) __declspec(novtable) IVectorView<Windows::Devices::Enumeration::DeviceInformation> : impl_IVectorView<Windows::Devices::Enumeration::DeviceInformation> {};
#endif

#ifndef WINRT_GENERIC_dd9f8a5d_ec98_5f4b_a3ea_9c8b5ad53c4b
#define WINRT_GENERIC_dd9f8a5d_ec98_5f4b_a3ea_9c8b5ad53c4b
template <> struct __declspec(uuid("dd9f8a5d-ec98-5f4b-a3ea-9c8b5ad53c4b")) __declspec(novtable) IIterable<Windows::Devices::Enumeration::DeviceInformation> : impl_IIterable<Windows::Devices::Enumeration::DeviceInformation> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_03c5a07b_990c_5d09_b0b8_5734eaa38222
#define WINRT_GENERIC_03c5a07b_990c_5d09_b0b8_5734eaa38222
template <> struct __declspec(uuid("03c5a07b-990c-5d09-b0b8-5734eaa38222")) __declspec(novtable) TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformation> : impl_TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformation> {};
#endif

#ifndef WINRT_GENERIC_906f1254_79ad_54fc_93c4_cdb99b437899
#define WINRT_GENERIC_906f1254_79ad_54fc_93c4_cdb99b437899
template <> struct __declspec(uuid("906f1254-79ad-54fc-93c4-cdb99b437899")) __declspec(novtable) TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> : impl_TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Devices::Enumeration::DeviceInformationUpdate> {};
#endif

#ifndef WINRT_GENERIC_9234630f_1ff4_54f6_9e3f_ac20369b7725
#define WINRT_GENERIC_9234630f_1ff4_54f6_9e3f_ac20369b7725
template <> struct __declspec(uuid("9234630f-1ff4-54f6-9e3f-ac20369b7725")) __declspec(novtable) TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Devices::Enumeration::DeviceWatcher, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_f04365ab_d3f3_5f85_a7da_dc19cff73d86
#define WINRT_GENERIC_f04365ab_d3f3_5f85_a7da_dc19cff73d86
template <> struct __declspec(uuid("f04365ab-d3f3-5f85-a7da-dc19cff73d86")) __declspec(novtable) IIterable<winrt::Windows::Devices::Enumeration::DeviceWatcherEventKind> : impl_IIterable<winrt::Windows::Devices::Enumeration::DeviceWatcherEventKind> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_45180254_082e_5274_b2e7_ac0517f44d07
#define WINRT_GENERIC_45180254_082e_5274_b2e7_ac0517f44d07
template <> struct __declspec(uuid("45180254-082e-5274-b2e7-ac0517f44d07")) __declspec(novtable) IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> : impl_IAsyncOperation<Windows::Devices::Enumeration::DeviceInformationCollection> {};
#endif

#ifndef WINRT_GENERIC_bac083a3_3a19_5072_9d90_133323a049ba
#define WINRT_GENERIC_bac083a3_3a19_5072_9d90_133323a049ba
template <> struct __declspec(uuid("bac083a3-3a19-5072-9d90-133323a049ba")) __declspec(novtable) IAsyncOperation<Windows::Devices::Enumeration::DeviceThumbnail> : impl_IAsyncOperation<Windows::Devices::Enumeration::DeviceThumbnail> {};
#endif

#ifndef WINRT_GENERIC_1002db74_8948_591e_815d_e40b667599a3
#define WINRT_GENERIC_1002db74_8948_591e_815d_e40b667599a3
template <> struct __declspec(uuid("1002db74-8948-591e-815d-e40b667599a3")) __declspec(novtable) IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> : impl_IAsyncOperation<Windows::Devices::Enumeration::DevicePairingResult> {};
#endif

#ifndef WINRT_GENERIC_fa65231f_4178_5de1_b2cc_03e22d7702b4
#define WINRT_GENERIC_fa65231f_4178_5de1_b2cc_03e22d7702b4
template <> struct __declspec(uuid("fa65231f-4178-5de1-b2cc-03e22d7702b4")) __declspec(novtable) TypedEventHandler<Windows::Devices::Enumeration::DeviceInformationCustomPairing, Windows::Devices::Enumeration::DevicePairingRequestedEventArgs> : impl_TypedEventHandler<Windows::Devices::Enumeration::DeviceInformationCustomPairing, Windows::Devices::Enumeration::DevicePairingRequestedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_2bb4df3d_bd7e_5fe0_9020_56dc0d30b935
#define WINRT_GENERIC_2bb4df3d_bd7e_5fe0_9020_56dc0d30b935
template <> struct __declspec(uuid("2bb4df3d-bd7e-5fe0-9020-56dc0d30b935")) __declspec(novtable) IAsyncOperation<Windows::Devices::Enumeration::DeviceUnpairingResult> : impl_IAsyncOperation<Windows::Devices::Enumeration::DeviceUnpairingResult> {};
#endif

#ifndef WINRT_GENERIC_4c71d028_b793_5bce_ae59_fa77f45a40d8
#define WINRT_GENERIC_4c71d028_b793_5bce_ae59_fa77f45a40d8
template <> struct __declspec(uuid("4c71d028-b793-5bce-ae59-fa77f45a40d8")) __declspec(novtable) TypedEventHandler<Windows::Devices::Enumeration::DeviceAccessInformation, Windows::Devices::Enumeration::DeviceAccessChangedEventArgs> : impl_TypedEventHandler<Windows::Devices::Enumeration::DeviceAccessInformation, Windows::Devices::Enumeration::DeviceAccessChangedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8f994d37_8fab_51c6_a1e0_c93f68a20ef0
#define WINRT_GENERIC_8f994d37_8fab_51c6_a1e0_c93f68a20ef0
template <> struct __declspec(uuid("8f994d37-8fab-51c6-a1e0-c93f68a20ef0")) __declspec(novtable) IVectorView<Windows::Devices::Enumeration::DeviceWatcherEvent> : impl_IVectorView<Windows::Devices::Enumeration::DeviceWatcherEvent> {};
#endif

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_c3807283_1416_593c_955c_0b4a286ff7bb
#define WINRT_GENERIC_c3807283_1416_593c_955c_0b4a286ff7bb
template <> struct __declspec(uuid("c3807283-1416-593c-955c-0b4a286ff7bb")) __declspec(novtable) IIterator<winrt::Windows::Devices::Enumeration::DeviceClass> : impl_IIterator<winrt::Windows::Devices::Enumeration::DeviceClass> {};
#endif

#ifndef WINRT_GENERIC_47d4be05_58f1_522e_81c6_975eb4131bb9
#define WINRT_GENERIC_47d4be05_58f1_522e_81c6_975eb4131bb9
template <> struct __declspec(uuid("47d4be05-58f1-522e-81c6-975eb4131bb9")) __declspec(novtable) IIterable<winrt::Windows::Devices::Enumeration::DeviceClass> : impl_IIterable<winrt::Windows::Devices::Enumeration::DeviceClass> {};
#endif

#ifndef WINRT_GENERIC_01a80a97_bd87_5c8a_97fd_d449c98bdac6
#define WINRT_GENERIC_01a80a97_bd87_5c8a_97fd_d449c98bdac6
template <> struct __declspec(uuid("01a80a97-bd87-5c8a-97fd-d449c98bdac6")) __declspec(novtable) IVectorView<winrt::Windows::Devices::Enumeration::DeviceClass> : impl_IVectorView<winrt::Windows::Devices::Enumeration::DeviceClass> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_bb483df2_7bb6_5923_a28d_8342ec30046b
#define WINRT_GENERIC_bb483df2_7bb6_5923_a28d_8342ec30046b
template <> struct __declspec(uuid("bb483df2-7bb6-5923-a28d-8342ec30046b")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Enumeration::DeviceInformation> : impl_AsyncOperationCompletedHandler<Windows::Devices::Enumeration::DeviceInformation> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_6f85d843_e8ab_5b46_85d7_327c58d18712
#define WINRT_GENERIC_6f85d843_e8ab_5b46_85d7_327c58d18712
template <> struct __declspec(uuid("6f85d843-e8ab-5b46-85d7-327c58d18712")) __declspec(novtable) IIterator<Windows::Devices::Enumeration::DeviceInformation> : impl_IIterator<Windows::Devices::Enumeration::DeviceInformation> {};
#endif

#ifndef WINRT_GENERIC_cb5ca9db_ccd6_5103_a93d_c925c908838d
#define WINRT_GENERIC_cb5ca9db_ccd6_5103_a93d_c925c908838d
template <> struct __declspec(uuid("cb5ca9db-ccd6-5103-a93d-c925c908838d")) __declspec(novtable) IIterator<winrt::Windows::Devices::Enumeration::DeviceWatcherEventKind> : impl_IIterator<winrt::Windows::Devices::Enumeration::DeviceWatcherEventKind> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_4a458732_527e_5c73_9a68_a73da370f782
#define WINRT_GENERIC_4a458732_527e_5c73_9a68_a73da370f782
template <> struct __declspec(uuid("4a458732-527e-5c73-9a68-a73da370f782")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Enumeration::DeviceInformationCollection> : impl_AsyncOperationCompletedHandler<Windows::Devices::Enumeration::DeviceInformationCollection> {};
#endif

#ifndef WINRT_GENERIC_86d455b2_d795_554c_9c31_bf6539349c19
#define WINRT_GENERIC_86d455b2_d795_554c_9c31_bf6539349c19
template <> struct __declspec(uuid("86d455b2-d795-554c-9c31-bf6539349c19")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Enumeration::DeviceThumbnail> : impl_AsyncOperationCompletedHandler<Windows::Devices::Enumeration::DeviceThumbnail> {};
#endif

#ifndef WINRT_GENERIC_7ee0247f_5f57_5cb2_b40e_18b5a211d6c3
#define WINRT_GENERIC_7ee0247f_5f57_5cb2_b40e_18b5a211d6c3
template <> struct __declspec(uuid("7ee0247f-5f57-5cb2-b40e-18b5a211d6c3")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Enumeration::DevicePairingResult> : impl_AsyncOperationCompletedHandler<Windows::Devices::Enumeration::DevicePairingResult> {};
#endif

#ifndef WINRT_GENERIC_9bbe6eb9_db2d_5160_a20c_f0c265f20d8e
#define WINRT_GENERIC_9bbe6eb9_db2d_5160_a20c_f0c265f20d8e
template <> struct __declspec(uuid("9bbe6eb9-db2d-5160-a20c-f0c265f20d8e")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Devices::Enumeration::DeviceUnpairingResult> : impl_AsyncOperationCompletedHandler<Windows::Devices::Enumeration::DeviceUnpairingResult> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_74f7d6cc_9c20_5bb9_bace_b2ffa38687f9
#define WINRT_GENERIC_74f7d6cc_9c20_5bb9_bace_b2ffa38687f9
template <> struct __declspec(uuid("74f7d6cc-9c20-5bb9-bace-b2ffa38687f9")) __declspec(novtable) IIterator<Windows::Devices::Enumeration::DeviceWatcherEvent> : impl_IIterator<Windows::Devices::Enumeration::DeviceWatcherEvent> {};
#endif

#ifndef WINRT_GENERIC_b48fd051_eafa_523f_a66e_9d4151c5d522
#define WINRT_GENERIC_b48fd051_eafa_523f_a66e_9d4151c5d522
template <> struct __declspec(uuid("b48fd051-eafa-523f-a66e-9d4151c5d522")) __declspec(novtable) IIterable<Windows::Devices::Enumeration::DeviceWatcherEvent> : impl_IIterable<Windows::Devices::Enumeration::DeviceWatcherEvent> {};
#endif

#ifndef WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
#define WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
template <> struct __declspec(uuid("fe2f3d47-5d47-5499-8374-430c7cda0204")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif

#ifndef WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
#define WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
template <> struct __declspec(uuid("5db5fa32-707c-5849-a06b-91c8eb9d10e8")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace Windows::Devices::Enumeration {

struct IDeviceAccessChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceAccessChangedEventArgs>
{
    IDeviceAccessChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceAccessChangedEventArgs2 :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceAccessChangedEventArgs2>,
    impl::require<IDeviceAccessChangedEventArgs2, Windows::Devices::Enumeration::IDeviceAccessChangedEventArgs>
{
    IDeviceAccessChangedEventArgs2(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceAccessInformation :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceAccessInformation>
{
    IDeviceAccessInformation(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceAccessInformationStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceAccessInformationStatics>
{
    IDeviceAccessInformationStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceConnectionChangeTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceConnectionChangeTriggerDetails>
{
    IDeviceConnectionChangeTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceDisconnectButtonClickedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceDisconnectButtonClickedEventArgs>
{
    IDeviceDisconnectButtonClickedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceInformation :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceInformation>
{
    IDeviceInformation(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceInformation2 :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceInformation2>
{
    IDeviceInformation2(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceInformationCustomPairing :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceInformationCustomPairing>
{
    IDeviceInformationCustomPairing(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceInformationPairing :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceInformationPairing>
{
    IDeviceInformationPairing(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceInformationPairing2 :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceInformationPairing2>
{
    IDeviceInformationPairing2(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceInformationPairingStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceInformationPairingStatics>
{
    IDeviceInformationPairingStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceInformationStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceInformationStatics>
{
    IDeviceInformationStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceInformationStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceInformationStatics2>
{
    IDeviceInformationStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceInformationUpdate :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceInformationUpdate>
{
    IDeviceInformationUpdate(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceInformationUpdate2 :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceInformationUpdate2>
{
    IDeviceInformationUpdate2(std::nullptr_t = nullptr) noexcept {}
};

struct IDevicePairingRequestedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IDevicePairingRequestedEventArgs>
{
    IDevicePairingRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IDevicePairingResult :
    Windows::Foundation::IInspectable,
    impl::consume<IDevicePairingResult>
{
    IDevicePairingResult(std::nullptr_t = nullptr) noexcept {}
};

struct IDevicePairingSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IDevicePairingSettings>
{
    IDevicePairingSettings(std::nullptr_t = nullptr) noexcept {}
};

struct IDevicePicker :
    Windows::Foundation::IInspectable,
    impl::consume<IDevicePicker>
{
    IDevicePicker(std::nullptr_t = nullptr) noexcept {}
};

struct IDevicePickerAppearance :
    Windows::Foundation::IInspectable,
    impl::consume<IDevicePickerAppearance>
{
    IDevicePickerAppearance(std::nullptr_t = nullptr) noexcept {}
};

struct IDevicePickerFilter :
    Windows::Foundation::IInspectable,
    impl::consume<IDevicePickerFilter>
{
    IDevicePickerFilter(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceSelectedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceSelectedEventArgs>
{
    IDeviceSelectedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceUnpairingResult :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceUnpairingResult>
{
    IDeviceUnpairingResult(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceWatcher :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceWatcher>
{
    IDeviceWatcher(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceWatcher2 :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceWatcher2>
{
    IDeviceWatcher2(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceWatcherEvent :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceWatcherEvent>
{
    IDeviceWatcherEvent(std::nullptr_t = nullptr) noexcept {}
};

struct IDeviceWatcherTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IDeviceWatcherTriggerDetails>
{
    IDeviceWatcherTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IEnclosureLocation :
    Windows::Foundation::IInspectable,
    impl::consume<IEnclosureLocation>
{
    IEnclosureLocation(std::nullptr_t = nullptr) noexcept {}
};

struct IEnclosureLocation2 :
    Windows::Foundation::IInspectable,
    impl::consume<IEnclosureLocation2>,
    impl::require<IEnclosureLocation2, Windows::Devices::Enumeration::IEnclosureLocation>
{
    IEnclosureLocation2(std::nullptr_t = nullptr) noexcept {}
};

}

}
