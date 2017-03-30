// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.Search.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_1b0d3570_0877_5ec2_8a2c_3b9539506aca
#define WINRT_GENERIC_1b0d3570_0877_5ec2_8a2c_3b9539506aca
template <> struct __declspec(uuid("1b0d3570-0877-5ec2-8a2c-3b9539506aca")) __declspec(novtable) IMap<hstring, Windows::Foundation::IInspectable> : impl_IMap<hstring, Windows::Foundation::IInspectable> {};
#endif

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

#ifndef WINRT_GENERIC_2f245f9d_eb5f_5641_9dcc_6ab1946cc7e6
#define WINRT_GENERIC_2f245f9d_eb5f_5641_9dcc_6ab1946cc7e6
template <> struct __declspec(uuid("2f245f9d-eb5f-5641-9dcc-6ab1946cc7e6")) __declspec(novtable) IVectorView<Windows::Data::Text::TextSegment> : impl_IVectorView<Windows::Data::Text::TextSegment> {};
#endif

#ifndef WINRT_GENERIC_85575a41_06cb_58d0_b98a_7c8f06e6e9d7
#define WINRT_GENERIC_85575a41_06cb_58d0_b98a_7c8f06e6e9d7
template <> struct __declspec(uuid("85575a41-06cb-58d0-b98a-7c8f06e6e9d7")) __declspec(novtable) IVectorView<Windows::Storage::IStorageItem> : impl_IVectorView<Windows::Storage::IStorageItem> {};
#endif

#ifndef WINRT_GENERIC_bb8b8418_65d1_544b_b083_6d172f568c73
#define WINRT_GENERIC_bb8b8418_65d1_544b_b083_6d172f568c73
template <> struct __declspec(uuid("bb8b8418-65d1-544b-b083-6d172f568c73")) __declspec(novtable) IIterable<Windows::Storage::IStorageItem> : impl_IIterable<Windows::Storage::IStorageItem> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_ef60385f_be78_584b_aaef_7829ada2b0de
#define WINRT_GENERIC_ef60385f_be78_584b_aaef_7829ada2b0de
template <> struct __declspec(uuid("ef60385f-be78-584b-aaef-7829ada2b0de")) __declspec(novtable) IAsyncOperation<uint32_t> : impl_IAsyncOperation<uint32_t> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_35aff6f9_ef75_5280_bb84_a2bf8317cf35
#define WINRT_GENERIC_35aff6f9_ef75_5280_bb84_a2bf8317cf35
template <> struct __declspec(uuid("35aff6f9-ef75-5280-bb84-a2bf8317cf35")) __declspec(novtable) IIterable<Windows::Storage::Search::SortEntry> : impl_IIterable<Windows::Storage::Search::SortEntry> {};
#endif

#ifndef WINRT_GENERIC_f4512416_6bb8_5c6f_b83a_bf8a2788ce9f
#define WINRT_GENERIC_f4512416_6bb8_5c6f_b83a_bf8a2788ce9f
template <> struct __declspec(uuid("f4512416-6bb8-5c6f-b83a-bf8a2788ce9f")) __declspec(novtable) IVectorView<Windows::Storage::Search::IIndexableContent> : impl_IVectorView<Windows::Storage::Search::IIndexableContent> {};
#endif

#ifndef WINRT_GENERIC_80646519_5e2a_595d_a8cd_2a24b4067f1b
#define WINRT_GENERIC_80646519_5e2a_595d_a8cd_2a24b4067f1b
template <> struct __declspec(uuid("80646519-5e2a-595d-a8cd-2a24b4067f1b")) __declspec(novtable) IVectorView<Windows::Storage::StorageFile> : impl_IVectorView<Windows::Storage::StorageFile> {};
#endif

#ifndef WINRT_GENERIC_e20debc6_dc4e_542e_a2e7_a24d19c8dd62
#define WINRT_GENERIC_e20debc6_dc4e_542e_a2e7_a24d19c8dd62
template <> struct __declspec(uuid("e20debc6-dc4e-542e-a2e7-a24d19c8dd62")) __declspec(novtable) IVectorView<Windows::Storage::StorageFolder> : impl_IVectorView<Windows::Storage::StorageFolder> {};
#endif

#ifndef WINRT_GENERIC_d8ea401b_47b3_5254_84f4_eea10c4cf068
#define WINRT_GENERIC_d8ea401b_47b3_5254_84f4_eea10c4cf068
template <> struct __declspec(uuid("d8ea401b-47b3-5254-84f4-eea10c4cf068")) __declspec(novtable) IVector<Windows::Storage::Search::SortEntry> : impl_IVector<Windows::Storage::Search::SortEntry> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_4ba22861_00c4_597f_b6bf_3af516f3b870
#define WINRT_GENERIC_4ba22861_00c4_597f_b6bf_3af516f3b870
template <> struct __declspec(uuid("4ba22861-00c4-597f-b6bf-3af516f3b870")) __declspec(novtable) TypedEventHandler<Windows::Storage::Search::IStorageQueryResultBase, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Storage::Search::IStorageQueryResultBase, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_88694b1f_f380_574d_8a05_4f67bd52cd11
#define WINRT_GENERIC_88694b1f_f380_574d_8a05_4f67bd52cd11
template <> struct __declspec(uuid("88694b1f-f380-574d-8a05-4f67bd52cd11")) __declspec(novtable) IAsyncOperation<winrt::Windows::Storage::Search::IndexedState> : impl_IAsyncOperation<winrt::Windows::Storage::Search::IndexedState> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_9ac00304_83ea_5688_87b6_ae38aab65d0b
#define WINRT_GENERIC_9ac00304_83ea_5688_87b6_ae38aab65d0b
template <> struct __declspec(uuid("9ac00304-83ea-5688-87b6-ae38aab65d0b")) __declspec(novtable) IIterable<Windows::Storage::StorageFile> : impl_IIterable<Windows::Storage::StorageFile> {};
#endif

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_645a39b4_f001_5272_9015_fb4a327179ae
#define WINRT_GENERIC_645a39b4_f001_5272_9015_fb4a327179ae
template <> struct __declspec(uuid("645a39b4-f001-5272-9015-fb4a327179ae")) __declspec(novtable) IIterator<Windows::Data::Text::TextSegment> : impl_IIterator<Windows::Data::Text::TextSegment> {};
#endif

#ifndef WINRT_GENERIC_5498f4f3_cee4_5b72_9729_815c4ad7b9dc
#define WINRT_GENERIC_5498f4f3_cee4_5b72_9729_815c4ad7b9dc
template <> struct __declspec(uuid("5498f4f3-cee4-5b72-9729-815c4ad7b9dc")) __declspec(novtable) IIterable<Windows::Data::Text::TextSegment> : impl_IIterable<Windows::Data::Text::TextSegment> {};
#endif

#ifndef WINRT_GENERIC_05b487c2_3830_5d3c_98da_25fa11542dbd
#define WINRT_GENERIC_05b487c2_3830_5d3c_98da_25fa11542dbd
template <> struct __declspec(uuid("05b487c2-3830-5d3c-98da-25fa11542dbd")) __declspec(novtable) IIterator<Windows::Storage::IStorageItem> : impl_IIterator<Windows::Storage::IStorageItem> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_9343b6e7_e3d2_5e4a_ab2d_2bce4919a6a4
#define WINRT_GENERIC_9343b6e7_e3d2_5e4a_ab2d_2bce4919a6a4
template <> struct __declspec(uuid("9343b6e7-e3d2-5e4a-ab2d-2bce4919a6a4")) __declspec(novtable) AsyncOperationCompletedHandler<uint32_t> : impl_AsyncOperationCompletedHandler<uint32_t> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_520434a2_acf7_58c9_b47a_2741f2fac2c2
#define WINRT_GENERIC_520434a2_acf7_58c9_b47a_2741f2fac2c2
template <> struct __declspec(uuid("520434a2-acf7-58c9-b47a-2741f2fac2c2")) __declspec(novtable) IIterator<Windows::Storage::Search::SortEntry> : impl_IIterator<Windows::Storage::Search::SortEntry> {};
#endif

#ifndef WINRT_GENERIC_6cdb32ba_2361_57a8_a39d_be1df041bdb8
#define WINRT_GENERIC_6cdb32ba_2361_57a8_a39d_be1df041bdb8
template <> struct __declspec(uuid("6cdb32ba-2361-57a8-a39d-be1df041bdb8")) __declspec(novtable) IIterator<Windows::Storage::Search::IIndexableContent> : impl_IIterator<Windows::Storage::Search::IIndexableContent> {};
#endif

#ifndef WINRT_GENERIC_4a6edbfe_0c41_5042_ac58_a885a8fc7928
#define WINRT_GENERIC_4a6edbfe_0c41_5042_ac58_a885a8fc7928
template <> struct __declspec(uuid("4a6edbfe-0c41-5042-ac58-a885a8fc7928")) __declspec(novtable) IIterable<Windows::Storage::Search::IIndexableContent> : impl_IIterable<Windows::Storage::Search::IIndexableContent> {};
#endif

#ifndef WINRT_GENERIC_5aac96fb_b3b9_5a7f_a920_4b5a8df81168
#define WINRT_GENERIC_5aac96fb_b3b9_5a7f_a920_4b5a8df81168
template <> struct __declspec(uuid("5aac96fb-b3b9-5a7f-a920-4b5a8df81168")) __declspec(novtable) IIterator<Windows::Storage::StorageFolder> : impl_IIterator<Windows::Storage::StorageFolder> {};
#endif

#ifndef WINRT_GENERIC_4669befc_ae5c_52b1_8a97_5466ce61e94e
#define WINRT_GENERIC_4669befc_ae5c_52b1_8a97_5466ce61e94e
template <> struct __declspec(uuid("4669befc-ae5c-52b1-8a97-5466ce61e94e")) __declspec(novtable) IIterable<Windows::Storage::StorageFolder> : impl_IIterable<Windows::Storage::StorageFolder> {};
#endif

#ifndef WINRT_GENERIC_43e29f53_0298_55aa_a6c8_4edd323d9598
#define WINRT_GENERIC_43e29f53_0298_55aa_a6c8_4edd323d9598
template <> struct __declspec(uuid("43e29f53-0298-55aa-a6c8-4edd323d9598")) __declspec(novtable) IIterator<Windows::Storage::StorageFile> : impl_IIterator<Windows::Storage::StorageFile> {};
#endif

#ifndef WINRT_GENERIC_823c7604_b37b_5465_a169_29497893cdb9
#define WINRT_GENERIC_823c7604_b37b_5465_a169_29497893cdb9
template <> struct __declspec(uuid("823c7604-b37b-5465-a169-29497893cdb9")) __declspec(novtable) IVectorView<Windows::Storage::Search::SortEntry> : impl_IVectorView<Windows::Storage::Search::SortEntry> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_b67a3cba_f5f7_5e51_968a_385126d1f918
#define WINRT_GENERIC_b67a3cba_f5f7_5e51_968a_385126d1f918
template <> struct __declspec(uuid("b67a3cba-f5f7-5e51-968a-385126d1f918")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::Storage::Search::IndexedState> : impl_AsyncOperationCompletedHandler<winrt::Windows::Storage::Search::IndexedState> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
#define WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
template <> struct __declspec(uuid("fe2f3d47-5d47-5499-8374-430c7cda0204")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_4b1c0fd7_7a01_5e7a_a6fe_be4500283f23
#define WINRT_GENERIC_4b1c0fd7_7a01_5e7a_a6fe_be4500283f23
template <> struct __declspec(uuid("4b1c0fd7-7a01-5e7a-a6fe-be4500283f23")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> {};
#endif

#ifndef WINRT_GENERIC_5dcbee48_9965_51da_a461_177c885be7e5
#define WINRT_GENERIC_5dcbee48_9965_51da_a461_177c885be7e5
template <> struct __declspec(uuid("5dcbee48-9965-51da-a461-177c885be7e5")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> : impl_IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_172a655b_b3b8_5eae_bc2e_a6a1f1708b4b
#define WINRT_GENERIC_172a655b_b3b8_5eae_bc2e_a6a1f1708b4b
template <> struct __declspec(uuid("172a655b-b3b8-5eae-bc2e-a6a1f1708b4b")) __declspec(novtable) IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> : impl_IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_919850e1_084b_5f9b_a0a0_50db0cd5da91
#define WINRT_GENERIC_919850e1_084b_5f9b_a0a0_50db0cd5da91
template <> struct __declspec(uuid("919850e1-084b-5f9b-a0a0-50db0cd5da91")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::Search::IIndexableContent>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::Search::IIndexableContent>> {};
#endif

#ifndef WINRT_GENERIC_03362e33_e413_5f29_97d0_48a4780935f9
#define WINRT_GENERIC_03362e33_e413_5f29_97d0_48a4780935f9
template <> struct __declspec(uuid("03362e33-e413-5f29-97d0-48a4780935f9")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> {};
#endif

#ifndef WINRT_GENERIC_ca40b21b_aeb1_5a61_9e08_3bd5d9594023
#define WINRT_GENERIC_ca40b21b_aeb1_5a61_9e08_3bd5d9594023
template <> struct __declspec(uuid("ca40b21b-aeb1-5a61-9e08-3bd5d9594023")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_a31b6540_b2b1_536d_818f_8ade7051c3b3
#define WINRT_GENERIC_a31b6540_b2b1_536d_818f_8ade7051c3b3
template <> struct __declspec(uuid("a31b6540-b2b1-536d-818f-8ade7051c3b3")) __declspec(novtable) IMap<hstring, Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment>> : impl_IMap<hstring, Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment>> {};
#endif

#ifndef WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
#define WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
template <> struct __declspec(uuid("5db5fa32-707c-5849-a06b-91c8eb9d10e8")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_51436e75_ace1_5a68_b260_f843b846f0db
#define WINRT_GENERIC_51436e75_ace1_5a68_b260_f843b846f0db
template <> struct __declspec(uuid("51436e75-ace1-5a68-b260-f843b846f0db")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Storage::IStorageItem>> {};
#endif

#ifndef WINRT_GENERIC_89981889_1207_5ae6_9b28_ccc58f3aac6e
#define WINRT_GENERIC_89981889_1207_5ae6_9b28_ccc58f3aac6e
template <> struct __declspec(uuid("89981889-1207-5ae6-9b28-ccc58f3aac6e")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_53a2e825_9bf1_5083_8a7b_9d94f312dade
#define WINRT_GENERIC_53a2e825_9bf1_5083_8a7b_9d94f312dade
template <> struct __declspec(uuid("53a2e825-9bf1-5083-8a7b-9d94f312dade")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> : impl_IIterator<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> {};
#endif

#ifndef WINRT_GENERIC_e1670fae_49cd_5c47_a8c8_f6fa2c650c6c
#define WINRT_GENERIC_e1670fae_49cd_5c47_a8c8_f6fa2c650c6c
template <> struct __declspec(uuid("e1670fae-49cd-5c47-a8c8-f6fa2c650c6c")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> : impl_IIterable<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_6a29f493_efb7_5fdb_a13e_f2c28b4dab58
#define WINRT_GENERIC_6a29f493_efb7_5fdb_a13e_f2c28b4dab58
template <> struct __declspec(uuid("6a29f493-efb7-5fdb-a13e-f2c28b4dab58")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Storage::Search::IIndexableContent>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Storage::Search::IIndexableContent>> {};
#endif

#ifndef WINRT_GENERIC_cb4206c5_0988_5104_afa9_253c298f86fd
#define WINRT_GENERIC_cb4206c5_0988_5104_afa9_253c298f86fd
template <> struct __declspec(uuid("cb4206c5-0988-5104-afa9-253c298f86fd")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> {};
#endif

#ifndef WINRT_GENERIC_ed2d1d9b_26ec_5be7_a8a3_56458933d25f
#define WINRT_GENERIC_ed2d1d9b_26ec_5be7_a8a3_56458933d25f
template <> struct __declspec(uuid("ed2d1d9b-26ec-5be7-a8a3-56458933d25f")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFolder>> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_77b4daf4_4f4f_5568_90ee_1a32cf0caaea
#define WINRT_GENERIC_77b4daf4_4f4f_5568_90ee_1a32cf0caaea
template <> struct __declspec(uuid("77b4daf4-4f4f-5568-90ee-1a32cf0caaea")) __declspec(novtable) IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment>> : impl_IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment>> {};
#endif

#ifndef WINRT_GENERIC_91d443d6_3777_5102_b0bc_3d4183a26ff9
#define WINRT_GENERIC_91d443d6_3777_5102_b0bc_3d4183a26ff9
template <> struct __declspec(uuid("91d443d6-3777-5102-b0bc-3d4183a26ff9")) __declspec(novtable) IMapView<hstring, Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment>> : impl_IMapView<hstring, Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_fc227365_219d_5d59_8b5b_58eb0a91ca0a
#define WINRT_GENERIC_fc227365_219d_5d59_8b5b_58eb0a91ca0a
template <> struct __declspec(uuid("fc227365-219d-5d59-8b5b-58eb0a91ca0a")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>>> {};
#endif

#ifndef WINRT_GENERIC_a782a13a_16a0_5326_b985_c4ca49e54e77
#define WINRT_GENERIC_a782a13a_16a0_5326_b985_c4ca49e54e77
template <> struct __declspec(uuid("a782a13a-16a0-5326-b985-c4ca49e54e77")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>>> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_00078aa3_8676_5f06_adf5_ffe5d661d670
#define WINRT_GENERIC_00078aa3_8676_5f06_adf5_ffe5d661d670
template <> struct __declspec(uuid("00078aa3-8676-5f06-adf5-ffe5d661d670")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment>>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment>>> {};
#endif

#ifndef WINRT_GENERIC_f819a276_b3f5_54d4_b8fd_c9adb7f700e3
#define WINRT_GENERIC_f819a276_b3f5_54d4_b8fd_c9adb7f700e3
template <> struct __declspec(uuid("f819a276-b3f5-54d4-b8fd-c9adb7f700e3")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment>>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<Windows::Data::Text::TextSegment>>> {};
#endif


}

namespace Windows::Storage::Search {

struct IContentIndexer :
    Windows::Foundation::IInspectable,
    impl::consume<IContentIndexer>
{
    IContentIndexer(std::nullptr_t = nullptr) noexcept {}
};

struct IContentIndexerQuery :
    Windows::Foundation::IInspectable,
    impl::consume<IContentIndexerQuery>
{
    IContentIndexerQuery(std::nullptr_t = nullptr) noexcept {}
};

struct IContentIndexerQueryOperations :
    Windows::Foundation::IInspectable,
    impl::consume<IContentIndexerQueryOperations>
{
    IContentIndexerQueryOperations(std::nullptr_t = nullptr) noexcept {}
};

struct IContentIndexerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IContentIndexerStatics>
{
    IContentIndexerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IIndexableContent :
    Windows::Foundation::IInspectable,
    impl::consume<IIndexableContent>
{
    IIndexableContent(std::nullptr_t = nullptr) noexcept {}
};

struct IQueryOptions :
    Windows::Foundation::IInspectable,
    impl::consume<IQueryOptions>
{
    IQueryOptions(std::nullptr_t = nullptr) noexcept {}
};

struct IQueryOptionsFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IQueryOptionsFactory>
{
    IQueryOptionsFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IQueryOptionsWithProviderFilter :
    Windows::Foundation::IInspectable,
    impl::consume<IQueryOptionsWithProviderFilter>
{
    IQueryOptionsWithProviderFilter(std::nullptr_t = nullptr) noexcept {}
};

struct IStorageFileQueryResult :
    Windows::Foundation::IInspectable,
    impl::consume<IStorageFileQueryResult>,
    impl::require<IStorageFileQueryResult, Windows::Storage::Search::IStorageQueryResultBase>
{
    IStorageFileQueryResult(std::nullptr_t = nullptr) noexcept {}
};

struct IStorageFileQueryResult2 :
    Windows::Foundation::IInspectable,
    impl::consume<IStorageFileQueryResult2>,
    impl::require<IStorageFileQueryResult2, Windows::Storage::Search::IStorageQueryResultBase>
{
    IStorageFileQueryResult2(std::nullptr_t = nullptr) noexcept {}
};

struct IStorageFolderQueryOperations :
    Windows::Foundation::IInspectable,
    impl::consume<IStorageFolderQueryOperations>
{
    IStorageFolderQueryOperations(std::nullptr_t = nullptr) noexcept {}
};

struct IStorageFolderQueryResult :
    Windows::Foundation::IInspectable,
    impl::consume<IStorageFolderQueryResult>,
    impl::require<IStorageFolderQueryResult, Windows::Storage::Search::IStorageQueryResultBase>
{
    IStorageFolderQueryResult(std::nullptr_t = nullptr) noexcept {}
};

struct IStorageItemQueryResult :
    Windows::Foundation::IInspectable,
    impl::consume<IStorageItemQueryResult>,
    impl::require<IStorageItemQueryResult, Windows::Storage::Search::IStorageQueryResultBase>
{
    IStorageItemQueryResult(std::nullptr_t = nullptr) noexcept {}
};

struct IStorageLibraryContentChangedTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IStorageLibraryContentChangedTriggerDetails>
{
    IStorageLibraryContentChangedTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IStorageQueryResultBase :
    Windows::Foundation::IInspectable,
    impl::consume<IStorageQueryResultBase>
{
    IStorageQueryResultBase(std::nullptr_t = nullptr) noexcept {}
};

struct IValueAndLanguage :
    Windows::Foundation::IInspectable,
    impl::consume<IValueAndLanguage>
{
    IValueAndLanguage(std::nullptr_t = nullptr) noexcept {}
};

}

}
