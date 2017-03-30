// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Resources.Core.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_f6d1f700_49c2_52ae_8154_826f9908773c
#define WINRT_GENERIC_f6d1f700_49c2_52ae_8154_826f9908773c
template <> struct __declspec(uuid("f6d1f700-49c2-52ae-8154-826f9908773c")) __declspec(novtable) IMap<hstring, hstring> : impl_IMap<hstring, hstring> {};
#endif

#ifndef WINRT_GENERIC_60310303_49c5_52e6_abc6_a9b36eccc716
#define WINRT_GENERIC_60310303_49c5_52e6_abc6_a9b36eccc716
template <> struct __declspec(uuid("60310303-49c5-52e6-abc6-a9b36eccc716")) __declspec(novtable) IKeyValuePair<hstring, hstring> : impl_IKeyValuePair<hstring, hstring> {};
#endif

#ifndef WINRT_GENERIC_1e036276_2f60_55f6_b7f3_f86079e6900b
#define WINRT_GENERIC_1e036276_2f60_55f6_b7f3_f86079e6900b
template <> struct __declspec(uuid("1e036276-2f60-55f6-b7f3-f86079e6900b")) __declspec(novtable) IObservableMap<hstring, hstring> : impl_IObservableMap<hstring, hstring> {};
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

#ifndef WINRT_GENERIC_430ecece_1418_5d19_81b2_5ddb381603cc
#define WINRT_GENERIC_430ecece_1418_5d19_81b2_5ddb381603cc
template <> struct __declspec(uuid("430ecece-1418-5d19-81b2-5ddb381603cc")) __declspec(novtable) IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> : impl_IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> {};
#endif

#ifndef WINRT_GENERIC_5e52f8ce_aced_5a42_95b4_f674dd84885e
#define WINRT_GENERIC_5e52f8ce_aced_5a42_95b4_f674dd84885e
template <> struct __declspec(uuid("5e52f8ce-aced-5a42-95b4-f674dd84885e")) __declspec(novtable) IAsyncOperation<Windows::Storage::StorageFile> : impl_IAsyncOperation<Windows::Storage::StorageFile> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_d4349ade_93b1_5325_ba5c_05f35eeffc55
#define WINRT_GENERIC_d4349ade_93b1_5325_ba5c_05f35eeffc55
template <> struct __declspec(uuid("d4349ade-93b1-5325-ba5c-05f35eeffc55")) __declspec(novtable) IMapView<hstring, Windows::ApplicationModel::Resources::Core::ResourceMap> : impl_IMapView<hstring, Windows::ApplicationModel::Resources::Core::ResourceMap> {};
#endif

#ifndef WINRT_GENERIC_76d43c7e_fd09_5908_a2b9_a49b4848294b
#define WINRT_GENERIC_76d43c7e_fd09_5908_a2b9_a49b4848294b
template <> struct __declspec(uuid("76d43c7e-fd09-5908-a2b9-a49b4848294b")) __declspec(novtable) IIterable<Windows::Storage::IStorageFile> : impl_IIterable<Windows::Storage::IStorageFile> {};
#endif

#ifndef WINRT_GENERIC_4825d6c4_835a_5da1_9bdd_12e97e16fb7a
#define WINRT_GENERIC_4825d6c4_835a_5da1_9bdd_12e97e16fb7a
template <> struct __declspec(uuid("4825d6c4-835a-5da1-9bdd-12e97e16fb7a")) __declspec(novtable) IMapView<hstring, Windows::ApplicationModel::Resources::Core::NamedResource> : impl_IMapView<hstring, Windows::ApplicationModel::Resources::Core::NamedResource> {};
#endif

#ifndef WINRT_GENERIC_bd4b0143_3a22_5ee2_92ed_7bc3c129e52b
#define WINRT_GENERIC_bd4b0143_3a22_5ee2_92ed_7bc3c129e52b
template <> struct __declspec(uuid("bd4b0143-3a22-5ee2-92ed-7bc3c129e52b")) __declspec(novtable) IKeyValuePair<hstring, Windows::ApplicationModel::Resources::Core::NamedResource> : impl_IKeyValuePair<hstring, Windows::ApplicationModel::Resources::Core::NamedResource> {};
#endif

#ifndef WINRT_GENERIC_66c9da16_d345_5bdb_b953_d86dd9ea8409
#define WINRT_GENERIC_66c9da16_d345_5bdb_b953_d86dd9ea8409
template <> struct __declspec(uuid("66c9da16-d345-5bdb-b953-d86dd9ea8409")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Resources::Core::NamedResource> : impl_IVectorView<Windows::ApplicationModel::Resources::Core::NamedResource> {};
#endif

#ifndef WINRT_GENERIC_f2656ef5_fc27_5c24_a8c2_1697e0be736f
#define WINRT_GENERIC_f2656ef5_fc27_5c24_a8c2_1697e0be736f
template <> struct __declspec(uuid("f2656ef5-fc27-5c24-a8c2-1697e0be736f")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Resources::Core::ResourceMap> : impl_IVectorView<Windows::ApplicationModel::Resources::Core::ResourceMap> {};
#endif

#ifndef WINRT_GENERIC_2eee68e2_687c_5f7a_a14e_588c4d3089e1
#define WINRT_GENERIC_2eee68e2_687c_5f7a_a14e_588c4d3089e1
template <> struct __declspec(uuid("2eee68e2-687c-5f7a-a14e-588c4d3089e1")) __declspec(novtable) IIterable<Windows::ApplicationModel::Resources::Core::ResourceQualifier> : impl_IIterable<Windows::ApplicationModel::Resources::Core::ResourceQualifier> {};
#endif

#ifndef WINRT_GENERIC_b82c58dc_1cc0_53f0_b0f4_66ef39a81cd6
#define WINRT_GENERIC_b82c58dc_1cc0_53f0_b0f4_66ef39a81cd6
template <> struct __declspec(uuid("b82c58dc-1cc0-53f0-b0f4-66ef39a81cd6")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Resources::Core::ResourceQualifier> : impl_IVectorView<Windows::ApplicationModel::Resources::Core::ResourceQualifier> {};
#endif

#ifndef WINRT_GENERIC_e28e92f0_9ffb_5ea7_9fc9_a73bda471886
#define WINRT_GENERIC_e28e92f0_9ffb_5ea7_9fc9_a73bda471886
template <> struct __declspec(uuid("e28e92f0-9ffb-5ea7-9fc9-a73bda471886")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Resources::Core::ResourceCandidate> : impl_IVectorView<Windows::ApplicationModel::Resources::Core::ResourceCandidate> {};
#endif

#ifndef WINRT_GENERIC_159782ba_798d_5ae6_85c7_c7bb551aae61
#define WINRT_GENERIC_159782ba_798d_5ae6_85c7_c7bb551aae61
template <> struct __declspec(uuid("159782ba-798d-5ae6-85c7-c7bb551aae61")) __declspec(novtable) IKeyValuePair<hstring, Windows::ApplicationModel::Resources::Core::ResourceMap> : impl_IKeyValuePair<hstring, Windows::ApplicationModel::Resources::Core::ResourceMap> {};
#endif

#ifndef WINRT_GENERIC_ac7f26f2_feb7_5b2a_8ac4_345bc62caede
#define WINRT_GENERIC_ac7f26f2_feb7_5b2a_8ac4_345bc62caede
template <> struct __declspec(uuid("ac7f26f2-feb7-5b2a-8ac4-345bc62caede")) __declspec(novtable) IMapView<hstring, hstring> : impl_IMapView<hstring, hstring> {};
#endif

#ifndef WINRT_GENERIC_d89c9498_8869_57f8_a883_9c2dfeecb6c6
#define WINRT_GENERIC_d89c9498_8869_57f8_a883_9c2dfeecb6c6
template <> struct __declspec(uuid("d89c9498-8869-57f8-a883-9c2dfeecb6c6")) __declspec(novtable) IIterable<Windows::ApplicationModel::Resources::Core::ResourceCandidate> : impl_IIterable<Windows::ApplicationModel::Resources::Core::ResourceCandidate> {};
#endif

#ifndef WINRT_GENERIC_60141efb_f2f9_5377_96fd_f8c60d9558b5
#define WINRT_GENERIC_60141efb_f2f9_5377_96fd_f8c60d9558b5
template <> struct __declspec(uuid("60141efb-f2f9-5377-96fd-f8c60d9558b5")) __declspec(novtable) IMapChangedEventArgs<hstring> : impl_IMapChangedEventArgs<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2663f37_2e1b_500c_ad68_c3ed7a8f74c8
#define WINRT_GENERIC_e2663f37_2e1b_500c_ad68_c3ed7a8f74c8
template <> struct __declspec(uuid("e2663f37-2e1b-500c-ad68-c3ed7a8f74c8")) __declspec(novtable) MapChangedEventHandler<hstring, hstring> : impl_MapChangedEventHandler<hstring, hstring> {};
#endif

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_398c4183_793d_5b00_819b_4aef92485e94
#define WINRT_GENERIC_398c4183_793d_5b00_819b_4aef92485e94
template <> struct __declspec(uuid("398c4183-793d-5b00-819b-4aef92485e94")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::Streams::IRandomAccessStream> : impl_AsyncOperationCompletedHandler<Windows::Storage::Streams::IRandomAccessStream> {};
#endif

#ifndef WINRT_GENERIC_e521c894_2c26_5946_9e61_2b5e188d01ed
#define WINRT_GENERIC_e521c894_2c26_5946_9e61_2b5e188d01ed
template <> struct __declspec(uuid("e521c894-2c26-5946-9e61-2b5e188d01ed")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::StorageFile> : impl_AsyncOperationCompletedHandler<Windows::Storage::StorageFile> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_314d2318_74ee_535c_b361_2144dbc573a0
#define WINRT_GENERIC_314d2318_74ee_535c_b361_2144dbc573a0
template <> struct __declspec(uuid("314d2318-74ee-535c-b361-2144dbc573a0")) __declspec(novtable) IIterator<Windows::Storage::IStorageFile> : impl_IIterator<Windows::Storage::IStorageFile> {};
#endif

#ifndef WINRT_GENERIC_0c5a605f_a7f1_5030_a179_9fd363caf3b5
#define WINRT_GENERIC_0c5a605f_a7f1_5030_a179_9fd363caf3b5
template <> struct __declspec(uuid("0c5a605f-a7f1-5030-a179-9fd363caf3b5")) __declspec(novtable) IIterator<Windows::ApplicationModel::Resources::Core::NamedResource> : impl_IIterator<Windows::ApplicationModel::Resources::Core::NamedResource> {};
#endif

#ifndef WINRT_GENERIC_e80d3d9d_96c9_579e_8e42_d550700de925
#define WINRT_GENERIC_e80d3d9d_96c9_579e_8e42_d550700de925
template <> struct __declspec(uuid("e80d3d9d-96c9-579e-8e42-d550700de925")) __declspec(novtable) IIterable<Windows::ApplicationModel::Resources::Core::NamedResource> : impl_IIterable<Windows::ApplicationModel::Resources::Core::NamedResource> {};
#endif

#ifndef WINRT_GENERIC_3dedcae6_d048_5eaa_afa2_fb4a7970ef68
#define WINRT_GENERIC_3dedcae6_d048_5eaa_afa2_fb4a7970ef68
template <> struct __declspec(uuid("3dedcae6-d048-5eaa-afa2-fb4a7970ef68")) __declspec(novtable) IIterator<Windows::ApplicationModel::Resources::Core::ResourceMap> : impl_IIterator<Windows::ApplicationModel::Resources::Core::ResourceMap> {};
#endif

#ifndef WINRT_GENERIC_8bbe1154_19aa_53e7_9d6e_dc7d358580f4
#define WINRT_GENERIC_8bbe1154_19aa_53e7_9d6e_dc7d358580f4
template <> struct __declspec(uuid("8bbe1154-19aa-53e7-9d6e-dc7d358580f4")) __declspec(novtable) IIterable<Windows::ApplicationModel::Resources::Core::ResourceMap> : impl_IIterable<Windows::ApplicationModel::Resources::Core::ResourceMap> {};
#endif

#ifndef WINRT_GENERIC_fedb74db_e74f_597a_b9bf_704b0dadca38
#define WINRT_GENERIC_fedb74db_e74f_597a_b9bf_704b0dadca38
template <> struct __declspec(uuid("fedb74db-e74f-597a-b9bf-704b0dadca38")) __declspec(novtable) IIterator<Windows::ApplicationModel::Resources::Core::ResourceQualifier> : impl_IIterator<Windows::ApplicationModel::Resources::Core::ResourceQualifier> {};
#endif

#ifndef WINRT_GENERIC_e151bd8c_a286_57ab_bcea_79b7bc2687a1
#define WINRT_GENERIC_e151bd8c_a286_57ab_bcea_79b7bc2687a1
template <> struct __declspec(uuid("e151bd8c-a286-57ab-bcea-79b7bc2687a1")) __declspec(novtable) IIterator<Windows::ApplicationModel::Resources::Core::ResourceCandidate> : impl_IIterator<Windows::ApplicationModel::Resources::Core::ResourceCandidate> {};
#endif

#ifndef WINRT_GENERIC_e9bdaaf0_cbf6_5c72_be90_29cbf3a1319b
#define WINRT_GENERIC_e9bdaaf0_cbf6_5c72_be90_29cbf3a1319b
template <> struct __declspec(uuid("e9bdaaf0-cbf6-5c72-be90-29cbf3a1319b")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> {};
#endif

#ifndef WINRT_GENERIC_bf16482e_80ed_51f0_b9c9_3a804e2d6403
#define WINRT_GENERIC_bf16482e_80ed_51f0_b9c9_3a804e2d6403
template <> struct __declspec(uuid("bf16482e-80ed-51f0-b9c9-3a804e2d6403")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Resources::Core::NamedResource>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Resources::Core::NamedResource>> {};
#endif

#ifndef WINRT_GENERIC_7fdcc3d7_e13e_5f76_afc6_0769c4086399
#define WINRT_GENERIC_7fdcc3d7_e13e_5f76_afc6_0769c4086399
template <> struct __declspec(uuid("7fdcc3d7-e13e-5f76-afc6-0769c4086399")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Resources::Core::NamedResource>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Resources::Core::NamedResource>> {};
#endif

#ifndef WINRT_GENERIC_9895431e_a817_5509_91e6_d90a933ed830
#define WINRT_GENERIC_9895431e_a817_5509_91e6_d90a933ed830
template <> struct __declspec(uuid("9895431e-a817-5509-91e6-d90a933ed830")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Resources::Core::ResourceMap>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Resources::Core::ResourceMap>> {};
#endif

#ifndef WINRT_GENERIC_28cf8d5e_69f6_59f6_9865_bca97d59f74f
#define WINRT_GENERIC_28cf8d5e_69f6_59f6_9865_bca97d59f74f
template <> struct __declspec(uuid("28cf8d5e-69f6-59f6-9865-bca97d59f74f")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Resources::Core::ResourceMap>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Resources::Core::ResourceMap>> {};
#endif

#ifndef WINRT_GENERIC_05eb86f1_7140_5517_b88d_cbaebe57e6b1
#define WINRT_GENERIC_05eb86f1_7140_5517_b88d_cbaebe57e6b1
template <> struct __declspec(uuid("05eb86f1-7140-5517-b88d-cbaebe57e6b1")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> {};
#endif


}

namespace Windows::ApplicationModel::Resources::Core {

struct INamedResource :
    Windows::Foundation::IInspectable,
    impl::consume<INamedResource>
{
    INamedResource(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceCandidate :
    Windows::Foundation::IInspectable,
    impl::consume<IResourceCandidate>
{
    IResourceCandidate(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceCandidate2 :
    Windows::Foundation::IInspectable,
    impl::consume<IResourceCandidate2>
{
    IResourceCandidate2(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceContext :
    Windows::Foundation::IInspectable,
    impl::consume<IResourceContext>
{
    IResourceContext(std::nullptr_t = nullptr) noexcept {}
};

struct [[deprecated("CreateMatchingContext may be altered or unavailable for releases after Windows 8.1. Instead, use ResourceContext.GetForCurrentView.OverrideToMatch.")]] IResourceContextStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IResourceContextStatics>
{
    IResourceContextStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceContextStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IResourceContextStatics2>
{
    IResourceContextStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceContextStatics3 :
    Windows::Foundation::IInspectable,
    impl::consume<IResourceContextStatics3>
{
    IResourceContextStatics3(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceManager :
    Windows::Foundation::IInspectable,
    impl::consume<IResourceManager>
{
    IResourceManager(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceManager2 :
    Windows::Foundation::IInspectable,
    impl::consume<IResourceManager2>
{
    IResourceManager2(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IResourceManagerStatics>
{
    IResourceManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceMap :
    Windows::Foundation::IInspectable,
    impl::consume<IResourceMap>,
    impl::require<IResourceMap, Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Resources::Core::NamedResource>>, Windows::Foundation::Collections::IMapView<hstring, Windows::ApplicationModel::Resources::Core::NamedResource>>
{
    IResourceMap(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceQualifier :
    Windows::Foundation::IInspectable,
    impl::consume<IResourceQualifier>
{
    IResourceQualifier(std::nullptr_t = nullptr) noexcept {}
};

}

}
