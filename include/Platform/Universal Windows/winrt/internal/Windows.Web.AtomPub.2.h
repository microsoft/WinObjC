// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Web.AtomPub.1.h"
#include "Windows.Web.Syndication.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif

#ifndef WINRT_GENERIC_a1ac007c_9d94_552e_840e_139f109a9b88
#define WINRT_GENERIC_a1ac007c_9d94_552e_840e_139f109a9b88
template <> struct __declspec(uuid("a1ac007c-9d94-552e-840e-139f109a9b88")) __declspec(novtable) IVectorView<Windows::Web::Syndication::SyndicationCategory> : impl_IVectorView<Windows::Web::Syndication::SyndicationCategory> {};
#endif

#ifndef WINRT_GENERIC_32f021c7_368b_5cfa_829c_4acf8a36c810
#define WINRT_GENERIC_32f021c7_368b_5cfa_829c_4acf8a36c810
template <> struct __declspec(uuid("32f021c7-368b-5cfa-829c-4acf8a36c810")) __declspec(novtable) IVectorView<Windows::Web::AtomPub::ResourceCollection> : impl_IVectorView<Windows::Web::AtomPub::ResourceCollection> {};
#endif

#ifndef WINRT_GENERIC_d0d7b58d_d97e_5761_be66_42b85b3d19c8
#define WINRT_GENERIC_d0d7b58d_d97e_5761_be66_42b85b3d19c8
template <> struct __declspec(uuid("d0d7b58d-d97e-5761-be66-42b85b3d19c8")) __declspec(novtable) IVectorView<Windows::Web::AtomPub::Workspace> : impl_IVectorView<Windows::Web::AtomPub::Workspace> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_da07abf4_91fa_5c96_84cb_459ea97b934d
#define WINRT_GENERIC_da07abf4_91fa_5c96_84cb_459ea97b934d
template <> struct __declspec(uuid("da07abf4-91fa-5c96-84cb-459ea97b934d")) __declspec(novtable) IAsyncOperationWithProgress<Windows::Web::AtomPub::ServiceDocument, Windows::Web::Syndication::RetrievalProgress> : impl_IAsyncOperationWithProgress<Windows::Web::AtomPub::ServiceDocument, Windows::Web::Syndication::RetrievalProgress> {};
#endif

#ifndef WINRT_GENERIC_f71cff65_e737_5345_b38f_fd445d2dc7e2
#define WINRT_GENERIC_f71cff65_e737_5345_b38f_fd445d2dc7e2
template <> struct __declspec(uuid("f71cff65-e737-5345-b38f-fd445d2dc7e2")) __declspec(novtable) IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, Windows::Web::Syndication::RetrievalProgress> : impl_IAsyncOperationWithProgress<Windows::Storage::Streams::IInputStream, Windows::Web::Syndication::RetrievalProgress> {};
#endif

#ifndef WINRT_GENERIC_44fa5a15_1204_521c_85e5_01259301d527
#define WINRT_GENERIC_44fa5a15_1204_521c_85e5_01259301d527
template <> struct __declspec(uuid("44fa5a15-1204-521c-85e5-01259301d527")) __declspec(novtable) IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::RetrievalProgress> : impl_IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::RetrievalProgress> {};
#endif

#ifndef WINRT_GENERIC_e57d0717_27c0_561e_b4b3_72aa2b1e3fc9
#define WINRT_GENERIC_e57d0717_27c0_561e_b4b3_72aa2b1e3fc9
template <> struct __declspec(uuid("e57d0717-27c0-561e-b4b3-72aa2b1e3fc9")) __declspec(novtable) IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::TransferProgress> : impl_IAsyncOperationWithProgress<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::TransferProgress> {};
#endif

#ifndef WINRT_GENERIC_b7eb83f5_a746_50f2_b91f_31803161ccc7
#define WINRT_GENERIC_b7eb83f5_a746_50f2_b91f_31803161ccc7
template <> struct __declspec(uuid("b7eb83f5-a746-50f2-b91f-31803161ccc7")) __declspec(novtable) IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> : impl_IAsyncActionWithProgress<Windows::Web::Syndication::TransferProgress> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_2a9228fa_b088_5690_bb38_b7044e0b502b
#define WINRT_GENERIC_2a9228fa_b088_5690_bb38_b7044e0b502b
template <> struct __declspec(uuid("2a9228fa-b088-5690-bb38-b7044e0b502b")) __declspec(novtable) IIterator<Windows::Web::Syndication::SyndicationCategory> : impl_IIterator<Windows::Web::Syndication::SyndicationCategory> {};
#endif

#ifndef WINRT_GENERIC_d151f7d1_eabd_5300_b55c_149eb289cc71
#define WINRT_GENERIC_d151f7d1_eabd_5300_b55c_149eb289cc71
template <> struct __declspec(uuid("d151f7d1-eabd-5300-b55c-149eb289cc71")) __declspec(novtable) IIterable<Windows::Web::Syndication::SyndicationCategory> : impl_IIterable<Windows::Web::Syndication::SyndicationCategory> {};
#endif

#ifndef WINRT_GENERIC_2b175876_0920_52f0_80bf_dfe79744128d
#define WINRT_GENERIC_2b175876_0920_52f0_80bf_dfe79744128d
template <> struct __declspec(uuid("2b175876-0920-52f0-80bf-dfe79744128d")) __declspec(novtable) IIterator<Windows::Web::AtomPub::ResourceCollection> : impl_IIterator<Windows::Web::AtomPub::ResourceCollection> {};
#endif

#ifndef WINRT_GENERIC_d4372a2d_7ab0_5d8e_bd5c_6e9c0a67a8d8
#define WINRT_GENERIC_d4372a2d_7ab0_5d8e_bd5c_6e9c0a67a8d8
template <> struct __declspec(uuid("d4372a2d-7ab0-5d8e-bd5c-6e9c0a67a8d8")) __declspec(novtable) IIterable<Windows::Web::AtomPub::ResourceCollection> : impl_IIterable<Windows::Web::AtomPub::ResourceCollection> {};
#endif

#ifndef WINRT_GENERIC_0cc8c426_d68a_5136_9741_de326764ca32
#define WINRT_GENERIC_0cc8c426_d68a_5136_9741_de326764ca32
template <> struct __declspec(uuid("0cc8c426-d68a-5136-9741-de326764ca32")) __declspec(novtable) IIterator<Windows::Web::AtomPub::Workspace> : impl_IIterator<Windows::Web::AtomPub::Workspace> {};
#endif

#ifndef WINRT_GENERIC_f02d0ebe_eac2_502f_9836_1c5482333bfe
#define WINRT_GENERIC_f02d0ebe_eac2_502f_9836_1c5482333bfe
template <> struct __declspec(uuid("f02d0ebe-eac2-502f-9836-1c5482333bfe")) __declspec(novtable) IIterable<Windows::Web::AtomPub::Workspace> : impl_IIterable<Windows::Web::AtomPub::Workspace> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_dd2a6d54_55aa_5d09_b790_9520d4eb4f19
#define WINRT_GENERIC_dd2a6d54_55aa_5d09_b790_9520d4eb4f19
template <> struct __declspec(uuid("dd2a6d54-55aa-5d09-b790-9520d4eb4f19")) __declspec(novtable) AsyncOperationProgressHandler<Windows::Web::AtomPub::ServiceDocument, Windows::Web::Syndication::RetrievalProgress> : impl_AsyncOperationProgressHandler<Windows::Web::AtomPub::ServiceDocument, Windows::Web::Syndication::RetrievalProgress> {};
#endif

#ifndef WINRT_GENERIC_5f03b1d3_470d_5be7_8176_1c9a46010900
#define WINRT_GENERIC_5f03b1d3_470d_5be7_8176_1c9a46010900
template <> struct __declspec(uuid("5f03b1d3-470d-5be7-8176-1c9a46010900")) __declspec(novtable) AsyncOperationWithProgressCompletedHandler<Windows::Web::AtomPub::ServiceDocument, Windows::Web::Syndication::RetrievalProgress> : impl_AsyncOperationWithProgressCompletedHandler<Windows::Web::AtomPub::ServiceDocument, Windows::Web::Syndication::RetrievalProgress> {};
#endif

#ifndef WINRT_GENERIC_6136b327_4152_54e3_aa34_38a0c121dc4d
#define WINRT_GENERIC_6136b327_4152_54e3_aa34_38a0c121dc4d
template <> struct __declspec(uuid("6136b327-4152-54e3-aa34-38a0c121dc4d")) __declspec(novtable) AsyncOperationProgressHandler<Windows::Storage::Streams::IInputStream, Windows::Web::Syndication::RetrievalProgress> : impl_AsyncOperationProgressHandler<Windows::Storage::Streams::IInputStream, Windows::Web::Syndication::RetrievalProgress> {};
#endif

#ifndef WINRT_GENERIC_76772ec1_c26f_5f6e_8d3b_8314107cefeb
#define WINRT_GENERIC_76772ec1_c26f_5f6e_8d3b_8314107cefeb
template <> struct __declspec(uuid("76772ec1-c26f-5f6e-8d3b-8314107cefeb")) __declspec(novtable) AsyncOperationWithProgressCompletedHandler<Windows::Storage::Streams::IInputStream, Windows::Web::Syndication::RetrievalProgress> : impl_AsyncOperationWithProgressCompletedHandler<Windows::Storage::Streams::IInputStream, Windows::Web::Syndication::RetrievalProgress> {};
#endif

#ifndef WINRT_GENERIC_b670d335_e83b_58b1_ad7b_840396085c65
#define WINRT_GENERIC_b670d335_e83b_58b1_ad7b_840396085c65
template <> struct __declspec(uuid("b670d335-e83b-58b1-ad7b-840396085c65")) __declspec(novtable) AsyncOperationProgressHandler<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::RetrievalProgress> : impl_AsyncOperationProgressHandler<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::RetrievalProgress> {};
#endif

#ifndef WINRT_GENERIC_9de7422b_4bc3_5546_87b8_2eebfd60be48
#define WINRT_GENERIC_9de7422b_4bc3_5546_87b8_2eebfd60be48
template <> struct __declspec(uuid("9de7422b-4bc3-5546-87b8-2eebfd60be48")) __declspec(novtable) AsyncOperationWithProgressCompletedHandler<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::RetrievalProgress> : impl_AsyncOperationWithProgressCompletedHandler<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::RetrievalProgress> {};
#endif

#ifndef WINRT_GENERIC_1ffb57b2_d2de_5559_8de2_50109c63539b
#define WINRT_GENERIC_1ffb57b2_d2de_5559_8de2_50109c63539b
template <> struct __declspec(uuid("1ffb57b2-d2de-5559-8de2-50109c63539b")) __declspec(novtable) AsyncOperationProgressHandler<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::TransferProgress> : impl_AsyncOperationProgressHandler<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::TransferProgress> {};
#endif

#ifndef WINRT_GENERIC_8a796ea9_ff95_50ef_93ea_711bf7946473
#define WINRT_GENERIC_8a796ea9_ff95_50ef_93ea_711bf7946473
template <> struct __declspec(uuid("8a796ea9-ff95-50ef-93ea-711bf7946473")) __declspec(novtable) AsyncOperationWithProgressCompletedHandler<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::TransferProgress> : impl_AsyncOperationWithProgressCompletedHandler<Windows::Web::Syndication::SyndicationItem, Windows::Web::Syndication::TransferProgress> {};
#endif

#ifndef WINRT_GENERIC_c1610085_94d0_5706_9ac6_10179d7deb92
#define WINRT_GENERIC_c1610085_94d0_5706_9ac6_10179d7deb92
template <> struct __declspec(uuid("c1610085-94d0-5706-9ac6-10179d7deb92")) __declspec(novtable) AsyncActionProgressHandler<Windows::Web::Syndication::TransferProgress> : impl_AsyncActionProgressHandler<Windows::Web::Syndication::TransferProgress> {};
#endif

#ifndef WINRT_GENERIC_f1c031c8_90bf_5cae_adf6_155b4aedfb60
#define WINRT_GENERIC_f1c031c8_90bf_5cae_adf6_155b4aedfb60
template <> struct __declspec(uuid("f1c031c8-90bf-5cae-adf6-155b4aedfb60")) __declspec(novtable) AsyncActionWithProgressCompletedHandler<Windows::Web::Syndication::TransferProgress> : impl_AsyncActionWithProgressCompletedHandler<Windows::Web::Syndication::TransferProgress> {};
#endif


}

namespace Windows::Web::AtomPub {

struct IAtomPubClient :
    Windows::Foundation::IInspectable,
    impl::consume<IAtomPubClient>,
    impl::require<IAtomPubClient, Windows::Web::Syndication::ISyndicationClient>
{
    IAtomPubClient(std::nullptr_t = nullptr) noexcept {}
};

struct IAtomPubClientFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IAtomPubClientFactory>
{
    IAtomPubClientFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceCollection :
    Windows::Foundation::IInspectable,
    impl::consume<IResourceCollection>,
    impl::require<IResourceCollection, Windows::Web::Syndication::ISyndicationNode>
{
    IResourceCollection(std::nullptr_t = nullptr) noexcept {}
};

struct IServiceDocument :
    Windows::Foundation::IInspectable,
    impl::consume<IServiceDocument>,
    impl::require<IServiceDocument, Windows::Web::Syndication::ISyndicationNode>
{
    IServiceDocument(std::nullptr_t = nullptr) noexcept {}
};

struct IWorkspace :
    Windows::Foundation::IInspectable,
    impl::consume<IWorkspace>,
    impl::require<IWorkspace, Windows::Web::Syndication::ISyndicationNode>
{
    IWorkspace(std::nullptr_t = nullptr) noexcept {}
};

}

}
