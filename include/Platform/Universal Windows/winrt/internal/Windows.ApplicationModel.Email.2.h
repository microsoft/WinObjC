// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Email.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif

#ifndef WINRT_GENERIC_5541d8a7_497c_5aa4_86fc_7713adbf2a2c
#define WINRT_GENERIC_5541d8a7_497c_5aa4_86fc_7713adbf2a2c
template <> struct __declspec(uuid("5541d8a7-497c-5aa4-86fc-7713adbf2a2c")) __declspec(novtable) IReference<Windows::Foundation::DateTime> : impl_IReference<Windows::Foundation::DateTime> {};
#endif

#ifndef WINRT_GENERIC_604d0c4c_91de_5c2a_935f_362f13eaf800
#define WINRT_GENERIC_604d0c4c_91de_5c2a_935f_362f13eaf800
template <> struct __declspec(uuid("604d0c4c-91de-5c2a-935f-362f13eaf800")) __declspec(novtable) IReference<Windows::Foundation::TimeSpan> : impl_IReference<Windows::Foundation::TimeSpan> {};
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

#ifndef WINRT_GENERIC_7c9df991_5d99_55b4_b439_064edd097ac4
#define WINRT_GENERIC_7c9df991_5d99_55b4_b439_064edd097ac4
template <> struct __declspec(uuid("7c9df991-5d99-55b4-b439-064edd097ac4")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Email::EmailStore> : impl_IAsyncOperation<Windows::ApplicationModel::Email::EmailStore> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_d4816e16_43c9_5b63_a444_6189acb56f6e
#define WINRT_GENERIC_d4816e16_43c9_5b63_a444_6189acb56f6e
template <> struct __declspec(uuid("d4816e16-43c9-5b63-a444-6189acb56f6e")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Email::EmailMailbox> : impl_IVectorView<Windows::ApplicationModel::Email::EmailMailbox> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_6f01f05e_988d_5b28_aba8_dbaabb4eb0d9
#define WINRT_GENERIC_6f01f05e_988d_5b28_aba8_dbaabb4eb0d9
template <> struct __declspec(uuid("6f01f05e-988d-5b28-aba8-dbaabb4eb0d9")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox> : impl_IAsyncOperation<Windows::ApplicationModel::Email::EmailMailbox> {};
#endif

#ifndef WINRT_GENERIC_6885966c_13b9_59cc_b358_adf82eec842a
#define WINRT_GENERIC_6885966c_13b9_59cc_b358_adf82eec842a
template <> struct __declspec(uuid("6885966c-13b9-59cc-b358-adf82eec842a")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Email::EmailConversation> : impl_IAsyncOperation<Windows::ApplicationModel::Email::EmailConversation> {};
#endif

#ifndef WINRT_GENERIC_6132274f_733d_5391_9077_0867fc330916
#define WINRT_GENERIC_6132274f_733d_5391_9077_0867fc330916
template <> struct __declspec(uuid("6132274f-733d-5391-9077-0867fc330916")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> : impl_IAsyncOperation<Windows::ApplicationModel::Email::EmailFolder> {};
#endif

#ifndef WINRT_GENERIC_73157119_fa58_5d2d_817c_b5630c1511e4
#define WINRT_GENERIC_73157119_fa58_5d2d_817c_b5630c1511e4
template <> struct __declspec(uuid("73157119-fa58-5d2d-817c-b5630c1511e4")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> : impl_IAsyncOperation<Windows::ApplicationModel::Email::EmailMessage> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_1151f664_39c5_5aaa_8a2e_3350e611624b
#define WINRT_GENERIC_1151f664_39c5_5aaa_8a2e_3350e611624b
template <> struct __declspec(uuid("1151f664-39c5-5aaa-8a2e-3350e611624b")) __declspec(novtable) IVector<Windows::ApplicationModel::Email::EmailRecipient> : impl_IVector<Windows::ApplicationModel::Email::EmailRecipient> {};
#endif

#ifndef WINRT_GENERIC_07b0ebc8_70af_5deb_9861_dc93e2b038e9
#define WINRT_GENERIC_07b0ebc8_70af_5deb_9861_dc93e2b038e9
template <> struct __declspec(uuid("07b0ebc8-70af-5deb-9861-dc93e2b038e9")) __declspec(novtable) IVector<Windows::ApplicationModel::Email::EmailAttachment> : impl_IVector<Windows::ApplicationModel::Email::EmailAttachment> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_433b124d_60e6_5b7a_96bc_8681de5f5e75
#define WINRT_GENERIC_433b124d_60e6_5b7a_96bc_8681de5f5e75
template <> struct __declspec(uuid("433b124d-60e6-5b7a-96bc-8681de5f5e75")) __declspec(novtable) IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeEncryptionAlgorithm> : impl_IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeEncryptionAlgorithm> {};
#endif

#ifndef WINRT_GENERIC_e498a622_f168_5104_a53b_faf996f51632
#define WINRT_GENERIC_e498a622_f168_5104_a53b_faf996f51632
template <> struct __declspec(uuid("e498a622-f168-5104-a53b-faf996f51632")) __declspec(novtable) IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeSigningAlgorithm> : impl_IReference<winrt::Windows::ApplicationModel::Email::EmailMailboxSmimeSigningAlgorithm> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_5f18cab2_236d_5ec5_bc64_e3e63d29e774
#define WINRT_GENERIC_5f18cab2_236d_5ec5_bc64_e3e63d29e774
template <> struct __declspec(uuid("5f18cab2-236d-5ec5-bc64-e3e63d29e774")) __declspec(novtable) IIterable<Windows::ApplicationModel::Email::EmailRecipient> : impl_IIterable<Windows::ApplicationModel::Email::EmailRecipient> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_20789b0d_1555_51fc_87a5_2222250b9b06
#define WINRT_GENERIC_20789b0d_1555_51fc_87a5_2222250b9b06
template <> struct __declspec(uuid("20789b0d-1555-51fc-87a5-2222250b9b06")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::EmailMailbox, Windows::ApplicationModel::Email::EmailMailboxChangedEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Email::EmailMailbox, Windows::ApplicationModel::Email::EmailMailboxChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_b354d4c4_e4a0_5a3c_b897_8deb458ac673
#define WINRT_GENERIC_b354d4c4_e4a0_5a3c_b897_8deb458ac673
template <> struct __declspec(uuid("b354d4c4-e4a0-5a3c-b897-8deb458ac673")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings> : impl_IAsyncOperation<Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_9307eb24_38f6_525e_ba0d_3b4e863fe0f8
#define WINRT_GENERIC_9307eb24_38f6_525e_ba0d_3b4e863fe0f8
template <> struct __declspec(uuid("9307eb24-38f6-525e-ba0d-3b4e863fe0f8")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Email::EmailRecipientResolutionResult> : impl_IVectorView<Windows::ApplicationModel::Email::EmailRecipientResolutionResult> {};
#endif

#ifndef WINRT_GENERIC_a5665ff7_b44e_57e3_bd7a_ef191aa5519c
#define WINRT_GENERIC_a5665ff7_b44e_57e3_bd7a_ef191aa5519c
template <> struct __declspec(uuid("a5665ff7-b44e-57e3-bd7a-ef191aa5519c")) __declspec(novtable) IVectorView<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus> : impl_IVectorView<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus> {};
#endif

#ifndef WINRT_GENERIC_0c7d1423_e8fd_5a91_b55c_8bfbe7ac2d40
#define WINRT_GENERIC_0c7d1423_e8fd_5a91_b55c_8bfbe7ac2d40
template <> struct __declspec(uuid("0c7d1423-e8fd-5a91-b55c-8bfbe7ac2d40")) __declspec(novtable) IIterable<Windows::Security::Cryptography::Certificates::Certificate> : impl_IIterable<Windows::Security::Cryptography::Certificates::Certificate> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_0033a74e_9baa_5f50_8d6e_238635e6fdd3
#define WINRT_GENERIC_0033a74e_9baa_5f50_8d6e_238635e6fdd3
template <> struct __declspec(uuid("0033a74e-9baa-5f50-8d6e-238635e6fdd3")) __declspec(novtable) IAsyncOperation<winrt::Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus> : impl_IAsyncOperation<winrt::Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus> {};
#endif

#ifndef WINRT_GENERIC_6d5a0e81_6949_50f9_bffb_92be1216724d
#define WINRT_GENERIC_6d5a0e81_6949_50f9_bffb_92be1216724d
template <> struct __declspec(uuid("6d5a0e81-6949-50f9-bffb-92be1216724d")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Email::EmailMailboxCreateFolderResult> : impl_IAsyncOperation<Windows::ApplicationModel::Email::EmailMailboxCreateFolderResult> {};
#endif

#ifndef WINRT_GENERIC_6860f87f_0297_5adf_aa16_9f1f08e2d950
#define WINRT_GENERIC_6860f87f_0297_5adf_aa16_9f1f08e2d950
template <> struct __declspec(uuid("6860f87f-0297-5adf-aa16-9f1f08e2d950")) __declspec(novtable) IAsyncOperation<winrt::Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus> : impl_IAsyncOperation<winrt::Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_963f7013_77c2_51c5_8038_b5bcef633edb
#define WINRT_GENERIC_963f7013_77c2_51c5_8038_b5bcef633edb
template <> struct __declspec(uuid("963f7013-77c2-51c5-8038-b5bcef633edb")) __declspec(novtable) IVectorView<Windows::Security::Cryptography::Certificates::Certificate> : impl_IVectorView<Windows::Security::Cryptography::Certificates::Certificate> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5cbe61bb_d615_5b82_bb11_412e32664c07
#define WINRT_GENERIC_5cbe61bb_d615_5b82_bb11_412e32664c07
template <> struct __declspec(uuid("5cbe61bb-d615-5b82-bb11-412e32664c07")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::EmailMailboxSyncManager, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::ApplicationModel::Email::EmailMailboxSyncManager, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_4e35d275_abdf_5e2c_b3e8_7546ed5ad573
#define WINRT_GENERIC_4e35d275_abdf_5e2c_b3e8_7546ed5ad573
template <> struct __declspec(uuid("4e35d275-abdf-5e2c-b3e8-7546ed5ad573")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Email::EmailFolder> : impl_IVectorView<Windows::ApplicationModel::Email::EmailFolder> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5856790d_5204_5a99_b69e_c7162fd25869
#define WINRT_GENERIC_5856790d_5204_5a99_b69e_c7162fd25869
template <> struct __declspec(uuid("5856790d-5204-5a99-b69e-c7162fd25869")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Email::EmailItemCounts> : impl_IAsyncOperation<Windows::ApplicationModel::Email::EmailItemCounts> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_51b8edf2_6ca6_55de_be45_1d1fc51df076
#define WINRT_GENERIC_51b8edf2_6ca6_55de_be45_1d1fc51df076
template <> struct __declspec(uuid("51b8edf2-6ca6-55de-be45-1d1fc51df076")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Email::EmailMessage> : impl_IVectorView<Windows::ApplicationModel::Email::EmailMessage> {};
#endif

#ifndef WINRT_GENERIC_0a7c62d7_fc19_5bd7_b37a_0d6242df48c0
#define WINRT_GENERIC_0a7c62d7_fc19_5bd7_b37a_0d6242df48c0
template <> struct __declspec(uuid("0a7c62d7-fc19-5bd7-b37a-0d6242df48c0")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Email::EmailConversation> : impl_IVectorView<Windows::ApplicationModel::Email::EmailConversation> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_7d87db9c_947d_5e0c_8cf2_245998d19d8f
#define WINRT_GENERIC_7d87db9c_947d_5e0c_8cf2_245998d19d8f
template <> struct __declspec(uuid("7d87db9c-947d-5e0c-8cf2-245998d19d8f")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Email::EmailConversationBatch> : impl_IAsyncOperation<Windows::ApplicationModel::Email::EmailConversationBatch> {};
#endif

#ifndef WINRT_GENERIC_37fea119_0f1e_5012_88bb_f0179f8f4de5
#define WINRT_GENERIC_37fea119_0f1e_5012_88bb_f0179f8f4de5
template <> struct __declspec(uuid("37fea119-0f1e-5012-88bb-f0179f8f4de5")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Email::EmailMessageBatch> : impl_IAsyncOperation<Windows::ApplicationModel::Email::EmailMessageBatch> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_4c954eb2_f15c_5869_abd7_2e328de4a4af
#define WINRT_GENERIC_4c954eb2_f15c_5869_abd7_2e328de4a4af
template <> struct __declspec(uuid("4c954eb2-f15c-5869-abd7-2e328de4a4af")) __declspec(novtable) IVector<Windows::ApplicationModel::Email::EmailMailboxAction> : impl_IVector<Windows::ApplicationModel::Email::EmailMailboxAction> {};
#endif

#ifndef WINRT_GENERIC_9ea98fb4_9e7e_5caa_a320_cc7ab5338084
#define WINRT_GENERIC_9ea98fb4_9e7e_5caa_a320_cc7ab5338084
template <> struct __declspec(uuid("9ea98fb4-9e7e-5caa-a320-cc7ab5338084")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Email::EmailMailboxChange> : impl_IVectorView<Windows::ApplicationModel::Email::EmailMailboxChange> {};
#endif

#ifndef WINRT_GENERIC_f6d6af60_f11a_5c03_80cc_473407a5aabf
#define WINRT_GENERIC_f6d6af60_f11a_5c03_80cc_473407a5aabf
template <> struct __declspec(uuid("f6d6af60-f11a-5c03-80cc-473407a5aabf")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Email::EmailRecipient> : impl_IVectorView<Windows::ApplicationModel::Email::EmailRecipient> {};
#endif

#ifndef WINRT_GENERIC_cae3c1c4_c689_5787_976f_1a158ffdd16b
#define WINRT_GENERIC_cae3c1c4_c689_5787_976f_1a158ffdd16b
template <> struct __declspec(uuid("cae3c1c4-c689-5787-976f-1a158ffdd16b")) __declspec(novtable) IIterable<Windows::ApplicationModel::Email::EmailRecipientResolutionResult> : impl_IIterable<Windows::ApplicationModel::Email::EmailRecipientResolutionResult> {};
#endif

#ifndef WINRT_GENERIC_7e326530_7449_51a7_b1bc_c43533a78e06
#define WINRT_GENERIC_7e326530_7449_51a7_b1bc_c43533a78e06
template <> struct __declspec(uuid("7e326530-7449-51a7-b1bc-c43533a78e06")) __declspec(novtable) IIterable<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus> : impl_IIterable<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus> {};
#endif


}

namespace ABI::Windows::Foundation {

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

#ifndef WINRT_GENERIC_ddb761d3_71b8_5c4b_ad8b_1e6522664921
#define WINRT_GENERIC_ddb761d3_71b8_5c4b_ad8b_1e6522664921
template <> struct __declspec(uuid("ddb761d3-71b8-5c4b-ad8b-1e6522664921")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailStore> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailStore> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_312f8d4a_0e85_566e_b7aa_dbd40a0343ff
#define WINRT_GENERIC_312f8d4a_0e85_566e_b7aa_dbd40a0343ff
template <> struct __declspec(uuid("312f8d4a-0e85-566e-b7aa-dbd40a0343ff")) __declspec(novtable) IIterator<Windows::ApplicationModel::Email::EmailMailbox> : impl_IIterator<Windows::ApplicationModel::Email::EmailMailbox> {};
#endif

#ifndef WINRT_GENERIC_8fc76b2e_f800_5f1d_a023_de47e5f306e0
#define WINRT_GENERIC_8fc76b2e_f800_5f1d_a023_de47e5f306e0
template <> struct __declspec(uuid("8fc76b2e-f800-5f1d-a023-de47e5f306e0")) __declspec(novtable) IIterable<Windows::ApplicationModel::Email::EmailMailbox> : impl_IIterable<Windows::ApplicationModel::Email::EmailMailbox> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_4d5f57df_e0dc_5cf5_b2e5_fa1e5c0006fa
#define WINRT_GENERIC_4d5f57df_e0dc_5cf5_b2e5_fa1e5c0006fa
template <> struct __declspec(uuid("4d5f57df-e0dc-5cf5-b2e5-fa1e5c0006fa")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailMailbox> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailMailbox> {};
#endif

#ifndef WINRT_GENERIC_0294c89d_8d98_5342_b82f_01102415c870
#define WINRT_GENERIC_0294c89d_8d98_5342_b82f_01102415c870
template <> struct __declspec(uuid("0294c89d-8d98-5342-b82f-01102415c870")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailConversation> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailConversation> {};
#endif

#ifndef WINRT_GENERIC_f1b66ef7_0525_5da5_a3d6_b25b3f533aa1
#define WINRT_GENERIC_f1b66ef7_0525_5da5_a3d6_b25b3f533aa1
template <> struct __declspec(uuid("f1b66ef7-0525-5da5-a3d6-b25b3f533aa1")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailFolder> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailFolder> {};
#endif

#ifndef WINRT_GENERIC_69d11d1e_f0bb_5f1b_acb5_120c26febded
#define WINRT_GENERIC_69d11d1e_f0bb_5f1b_acb5_120c26febded
template <> struct __declspec(uuid("69d11d1e-f0bb-5f1b-acb5-120c26febded")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailMessage> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailMessage> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_12238d88_1a2f_5e7a_89b1_8dc140536bac
#define WINRT_GENERIC_12238d88_1a2f_5e7a_89b1_8dc140536bac
template <> struct __declspec(uuid("12238d88-1a2f-5e7a-89b1-8dc140536bac")) __declspec(novtable) IIterator<Windows::ApplicationModel::Email::EmailRecipient> : impl_IIterator<Windows::ApplicationModel::Email::EmailRecipient> {};
#endif

#ifndef WINRT_GENERIC_44655b88_9a99_5994_8e0f_5b9640924120
#define WINRT_GENERIC_44655b88_9a99_5994_8e0f_5b9640924120
template <> struct __declspec(uuid("44655b88-9a99-5994-8e0f-5b9640924120")) __declspec(novtable) IIterator<Windows::ApplicationModel::Email::EmailAttachment> : impl_IIterator<Windows::ApplicationModel::Email::EmailAttachment> {};
#endif

#ifndef WINRT_GENERIC_a5ab00e4_0ed7_52ee_aacb_83d840d6f8fa
#define WINRT_GENERIC_a5ab00e4_0ed7_52ee_aacb_83d840d6f8fa
template <> struct __declspec(uuid("a5ab00e4-0ed7-52ee-aacb-83d840d6f8fa")) __declspec(novtable) IIterable<Windows::ApplicationModel::Email::EmailAttachment> : impl_IIterable<Windows::ApplicationModel::Email::EmailAttachment> {};
#endif

#ifndef WINRT_GENERIC_1d71b8e6_3f41_51cc_894b_dbc10ebc9d52
#define WINRT_GENERIC_1d71b8e6_3f41_51cc_894b_dbc10ebc9d52
template <> struct __declspec(uuid("1d71b8e6-3f41-51cc-894b-dbc10ebc9d52")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Email::EmailAttachment> : impl_IVectorView<Windows::ApplicationModel::Email::EmailAttachment> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_dfc1275a_c7b0_5fe4_9370_32b94ad0ba8e
#define WINRT_GENERIC_dfc1275a_c7b0_5fe4_9370_32b94ad0ba8e
template <> struct __declspec(uuid("dfc1275a-c7b0-5fe4-9370-32b94ad0ba8e")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailMailboxAutoReplySettings> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_5c040cd6_9593_5e74_9a5e_7284cd1b7200
#define WINRT_GENERIC_5c040cd6_9593_5e74_9a5e_7284cd1b7200
template <> struct __declspec(uuid("5c040cd6-9593-5e74-9a5e-7284cd1b7200")) __declspec(novtable) IIterator<Windows::ApplicationModel::Email::EmailRecipientResolutionResult> : impl_IIterator<Windows::ApplicationModel::Email::EmailRecipientResolutionResult> {};
#endif

#ifndef WINRT_GENERIC_1cfe3d41_16a5_5026_a6fe_2cb0a303a605
#define WINRT_GENERIC_1cfe3d41_16a5_5026_a6fe_2cb0a303a605
template <> struct __declspec(uuid("1cfe3d41-16a5-5026-a6fe-2cb0a303a605")) __declspec(novtable) IIterator<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus> : impl_IIterator<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus> {};
#endif

#ifndef WINRT_GENERIC_676fc159_f15c_58bd_91a7_28f7e795c756
#define WINRT_GENERIC_676fc159_f15c_58bd_91a7_28f7e795c756
template <> struct __declspec(uuid("676fc159-f15c-58bd-91a7-28f7e795c756")) __declspec(novtable) IIterator<Windows::Security::Cryptography::Certificates::Certificate> : impl_IIterator<Windows::Security::Cryptography::Certificates::Certificate> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_50333005_daed_567e_bb88_b1bc4663b075
#define WINRT_GENERIC_50333005_daed_567e_bb88_b1bc4663b075
template <> struct __declspec(uuid("50333005-daed-567e-bb88-b1bc4663b075")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus> : impl_AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::Email::EmailMailboxEmptyFolderStatus> {};
#endif

#ifndef WINRT_GENERIC_929f0fda_f350_55be_8555_e98d81eaf1a5
#define WINRT_GENERIC_929f0fda_f350_55be_8555_e98d81eaf1a5
template <> struct __declspec(uuid("929f0fda-f350-55be-8555-e98d81eaf1a5")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailMailboxCreateFolderResult> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailMailboxCreateFolderResult> {};
#endif

#ifndef WINRT_GENERIC_52604da6_485b_5445_8e6f_64cc13056045
#define WINRT_GENERIC_52604da6_485b_5445_8e6f_64cc13056045
template <> struct __declspec(uuid("52604da6-485b-5445-8e6f-64cc13056045")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus> : impl_AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::Email::EmailMailboxDeleteFolderStatus> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_95ae5494_43bc_5f6b_a02b_b6956d0c7069
#define WINRT_GENERIC_95ae5494_43bc_5f6b_a02b_b6956d0c7069
template <> struct __declspec(uuid("95ae5494-43bc-5f6b-a02b-b6956d0c7069")) __declspec(novtable) IIterator<Windows::ApplicationModel::Email::EmailFolder> : impl_IIterator<Windows::ApplicationModel::Email::EmailFolder> {};
#endif

#ifndef WINRT_GENERIC_6dcb53eb_8a35_54bf_8c8e_449bce9b3920
#define WINRT_GENERIC_6dcb53eb_8a35_54bf_8c8e_449bce9b3920
template <> struct __declspec(uuid("6dcb53eb-8a35-54bf-8c8e-449bce9b3920")) __declspec(novtable) IIterable<Windows::ApplicationModel::Email::EmailFolder> : impl_IIterable<Windows::ApplicationModel::Email::EmailFolder> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_02c54220_ded8_5495_841d_d432c879b826
#define WINRT_GENERIC_02c54220_ded8_5495_841d_d432c879b826
template <> struct __declspec(uuid("02c54220-ded8-5495-841d-d432c879b826")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailItemCounts> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailItemCounts> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_ca569bf8_d6d7_5411_9600_ab95ec065c72
#define WINRT_GENERIC_ca569bf8_d6d7_5411_9600_ab95ec065c72
template <> struct __declspec(uuid("ca569bf8-d6d7-5411-9600-ab95ec065c72")) __declspec(novtable) IIterator<Windows::ApplicationModel::Email::EmailMessage> : impl_IIterator<Windows::ApplicationModel::Email::EmailMessage> {};
#endif

#ifndef WINRT_GENERIC_a5fac823_8e6d_5bbe_ad16_8350aea446e0
#define WINRT_GENERIC_a5fac823_8e6d_5bbe_ad16_8350aea446e0
template <> struct __declspec(uuid("a5fac823-8e6d-5bbe-ad16-8350aea446e0")) __declspec(novtable) IIterable<Windows::ApplicationModel::Email::EmailMessage> : impl_IIterable<Windows::ApplicationModel::Email::EmailMessage> {};
#endif

#ifndef WINRT_GENERIC_fadada27_e629_5a34_b2e9_1d25c93544b5
#define WINRT_GENERIC_fadada27_e629_5a34_b2e9_1d25c93544b5
template <> struct __declspec(uuid("fadada27-e629-5a34-b2e9-1d25c93544b5")) __declspec(novtable) IIterator<Windows::ApplicationModel::Email::EmailConversation> : impl_IIterator<Windows::ApplicationModel::Email::EmailConversation> {};
#endif

#ifndef WINRT_GENERIC_d495f8dc_4327_5bca_a506_44b172d6d435
#define WINRT_GENERIC_d495f8dc_4327_5bca_a506_44b172d6d435
template <> struct __declspec(uuid("d495f8dc-4327-5bca-a506-44b172d6d435")) __declspec(novtable) IIterable<Windows::ApplicationModel::Email::EmailConversation> : impl_IIterable<Windows::ApplicationModel::Email::EmailConversation> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_f1406083_2a75_5726_ba48_90e32eadd7fa
#define WINRT_GENERIC_f1406083_2a75_5726_ba48_90e32eadd7fa
template <> struct __declspec(uuid("f1406083-2a75-5726-ba48-90e32eadd7fa")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailConversationBatch> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailConversationBatch> {};
#endif

#ifndef WINRT_GENERIC_b6674195_87f8_5575_9108_9c5621d529b1
#define WINRT_GENERIC_b6674195_87f8_5575_9108_9c5621d529b1
template <> struct __declspec(uuid("b6674195-87f8-5575-9108-9c5621d529b1")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailMessageBatch> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Email::EmailMessageBatch> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_b9d8eec0_f0e0_5a4d_88d0_758acbc6380f
#define WINRT_GENERIC_b9d8eec0_f0e0_5a4d_88d0_758acbc6380f
template <> struct __declspec(uuid("b9d8eec0-f0e0-5a4d-88d0-758acbc6380f")) __declspec(novtable) IIterator<Windows::ApplicationModel::Email::EmailMailboxAction> : impl_IIterator<Windows::ApplicationModel::Email::EmailMailboxAction> {};
#endif

#ifndef WINRT_GENERIC_26419311_1cd7_5bab_9c4a_e95884d5539c
#define WINRT_GENERIC_26419311_1cd7_5bab_9c4a_e95884d5539c
template <> struct __declspec(uuid("26419311-1cd7-5bab-9c4a-e95884d5539c")) __declspec(novtable) IIterable<Windows::ApplicationModel::Email::EmailMailboxAction> : impl_IIterable<Windows::ApplicationModel::Email::EmailMailboxAction> {};
#endif

#ifndef WINRT_GENERIC_f7bdef91_beff_5be2_8ef9_2f8112e59a6f
#define WINRT_GENERIC_f7bdef91_beff_5be2_8ef9_2f8112e59a6f
template <> struct __declspec(uuid("f7bdef91-beff-5be2-8ef9-2f8112e59a6f")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Email::EmailMailboxAction> : impl_IVectorView<Windows::ApplicationModel::Email::EmailMailboxAction> {};
#endif

#ifndef WINRT_GENERIC_b2b91198_5f8b_5e4a_85f8_ddca82ba0b7f
#define WINRT_GENERIC_b2b91198_5f8b_5e4a_85f8_ddca82ba0b7f
template <> struct __declspec(uuid("b2b91198-5f8b-5e4a-85f8-ddca82ba0b7f")) __declspec(novtable) IIterator<Windows::ApplicationModel::Email::EmailMailboxChange> : impl_IIterator<Windows::ApplicationModel::Email::EmailMailboxChange> {};
#endif

#ifndef WINRT_GENERIC_4630ccb6_dfce_57dc_a5d1_28b889c2c2b7
#define WINRT_GENERIC_4630ccb6_dfce_57dc_a5d1_28b889c2c2b7
template <> struct __declspec(uuid("4630ccb6-dfce-57dc-a5d1-28b889c2c2b7")) __declspec(novtable) IIterable<Windows::ApplicationModel::Email::EmailMailboxChange> : impl_IIterable<Windows::ApplicationModel::Email::EmailMailboxChange> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5bed07ec_f5d5_5b25_b067_9b22a4a762ea
#define WINRT_GENERIC_5bed07ec_f5d5_5b25_b067_9b22a4a762ea
template <> struct __declspec(uuid("5bed07ec-f5d5-5b25-b067-9b22a4a762ea")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailbox>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailbox>> {};
#endif

#ifndef WINRT_GENERIC_12a76f8e_ed11_5c2b_81c6_110296fc7a43
#define WINRT_GENERIC_12a76f8e_ed11_5c2b_81c6_110296fc7a43
template <> struct __declspec(uuid("12a76f8e-ed11-5c2b-81c6-110296fc7a43")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailRecipientResolutionResult>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailRecipientResolutionResult>> {};
#endif

#ifndef WINRT_GENERIC_f3e7ef5b_8894_5488_97ef_029ca4913947
#define WINRT_GENERIC_f3e7ef5b_8894_5488_97ef_029ca4913947
template <> struct __declspec(uuid("f3e7ef5b-8894-5488-97ef-029ca4913947")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>> {};
#endif

#ifndef WINRT_GENERIC_0c1ca8b9_7f85_534d_98f1_0f5cd8e72c1f
#define WINRT_GENERIC_0c1ca8b9_7f85_534d_98f1_0f5cd8e72c1f
template <> struct __declspec(uuid("0c1ca8b9-7f85-534d-98f1-0f5cd8e72c1f")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailFolder>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailFolder>> {};
#endif

#ifndef WINRT_GENERIC_47065121_dc80_59f9_8719_3f0c6eef8753
#define WINRT_GENERIC_47065121_dc80_59f9_8719_3f0c6eef8753
template <> struct __declspec(uuid("47065121-dc80-59f9-8719-3f0c6eef8753")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage>> {};
#endif

#ifndef WINRT_GENERIC_81153d29_d502_5050_af64_b1333462d16a
#define WINRT_GENERIC_81153d29_d502_5050_af64_b1333462d16a
template <> struct __declspec(uuid("81153d29-d502-5050-af64-b1333462d16a")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailboxChange>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailboxChange>> {};
#endif

#ifndef WINRT_GENERIC_478ddb6a_e122_5832_8263_f3d90a1f5377
#define WINRT_GENERIC_478ddb6a_e122_5832_8263_f3d90a1f5377
template <> struct __declspec(uuid("478ddb6a-e122-5832-8263-f3d90a1f5377")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailbox>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailbox>> {};
#endif

#ifndef WINRT_GENERIC_afee5c98_f2ed_5bbf_90fb_955f8e6c15e0
#define WINRT_GENERIC_afee5c98_f2ed_5bbf_90fb_955f8e6c15e0
template <> struct __declspec(uuid("afee5c98-f2ed-5bbf-90fb-955f8e6c15e0")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailRecipientResolutionResult>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailRecipientResolutionResult>> {};
#endif

#ifndef WINRT_GENERIC_7db1b498_0944_5b7f_8653_45d0d35ddff1
#define WINRT_GENERIC_7db1b498_0944_5b7f_8653_45d0d35ddff1
template <> struct __declspec(uuid("7db1b498-0944-5b7f-8653-45d0d35ddff1")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<winrt::Windows::ApplicationModel::Email::EmailCertificateValidationStatus>> {};
#endif

#ifndef WINRT_GENERIC_1e343987_cbb3_5260_a69d_cb00e17c8e52
#define WINRT_GENERIC_1e343987_cbb3_5260_a69d_cb00e17c8e52
template <> struct __declspec(uuid("1e343987-cbb3-5260-a69d-cb00e17c8e52")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailFolder>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailFolder>> {};
#endif

#ifndef WINRT_GENERIC_128697e6_231f_5c2f_917d_c330de1da69b
#define WINRT_GENERIC_128697e6_231f_5c2f_917d_c330de1da69b
template <> struct __declspec(uuid("128697e6-231f-5c2f-917d-c330de1da69b")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMessage>> {};
#endif

#ifndef WINRT_GENERIC_ece9e82b_bbc1_5d32_b306_1e4d4501b68a
#define WINRT_GENERIC_ece9e82b_bbc1_5d32_b306_1e4d4501b68a
template <> struct __declspec(uuid("ece9e82b-bbc1-5d32-b306-1e4d4501b68a")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailboxChange>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Email::EmailMailboxChange>> {};
#endif


}

namespace Windows::ApplicationModel::Email {

struct IEmailAttachment :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailAttachment>
{
    IEmailAttachment(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailAttachment2 :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailAttachment2>
{
    IEmailAttachment2(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailAttachmentFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailAttachmentFactory>
{
    IEmailAttachmentFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailAttachmentFactory2 :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailAttachmentFactory2>
{
    IEmailAttachmentFactory2(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailConversation :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailConversation>
{
    IEmailConversation(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailConversationBatch :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailConversationBatch>
{
    IEmailConversationBatch(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailConversationReader :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailConversationReader>
{
    IEmailConversationReader(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailFolder :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailFolder>
{
    IEmailFolder(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailIrmInfo :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailIrmInfo>
{
    IEmailIrmInfo(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailIrmInfoFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailIrmInfoFactory>
{
    IEmailIrmInfoFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailIrmTemplate :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailIrmTemplate>
{
    IEmailIrmTemplate(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailIrmTemplateFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailIrmTemplateFactory>
{
    IEmailIrmTemplateFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailItemCounts :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailItemCounts>
{
    IEmailItemCounts(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailbox :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailbox>
{
    IEmailMailbox(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailbox2 :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailbox2>,
    impl::require<IEmailMailbox2, Windows::ApplicationModel::Email::IEmailMailbox>
{
    IEmailMailbox2(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailbox3 :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailbox3>,
    impl::require<IEmailMailbox3, Windows::ApplicationModel::Email::IEmailMailbox, Windows::ApplicationModel::Email::IEmailMailbox2>
{
    IEmailMailbox3(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailbox4 :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailbox4>
{
    IEmailMailbox4(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxAction :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxAction>
{
    IEmailMailboxAction(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxAutoReply :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxAutoReply>
{
    IEmailMailboxAutoReply(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxAutoReplySettings :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxAutoReplySettings>
{
    IEmailMailboxAutoReplySettings(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxCapabilities :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxCapabilities>
{
    IEmailMailboxCapabilities(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxCapabilities2 :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxCapabilities2>
{
    IEmailMailboxCapabilities2(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxCapabilities3 :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxCapabilities3>
{
    IEmailMailboxCapabilities3(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxChange :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxChange>
{
    IEmailMailboxChange(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxChangeReader :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxChangeReader>
{
    IEmailMailboxChangeReader(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxChangeTracker :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxChangeTracker>
{
    IEmailMailboxChangeTracker(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxChangedDeferral :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxChangedDeferral>
{
    IEmailMailboxChangedDeferral(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxChangedEventArgs>
{
    IEmailMailboxChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxCreateFolderResult :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxCreateFolderResult>
{
    IEmailMailboxCreateFolderResult(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxPolicies :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxPolicies>
{
    IEmailMailboxPolicies(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxPolicies2 :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxPolicies2>
{
    IEmailMailboxPolicies2(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxPolicies3 :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxPolicies3>
{
    IEmailMailboxPolicies3(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxSyncManager :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxSyncManager>
{
    IEmailMailboxSyncManager(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxSyncManager2 :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxSyncManager2>
{
    IEmailMailboxSyncManager2(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailManagerForUser :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailManagerForUser>
{
    IEmailManagerForUser(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailManagerStatics>
{
    IEmailManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailManagerStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailManagerStatics2>
{
    IEmailManagerStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailManagerStatics3 :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailManagerStatics3>
{
    IEmailManagerStatics3(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMeetingInfo :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMeetingInfo>
{
    IEmailMeetingInfo(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMeetingInfo2 :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMeetingInfo2>
{
    IEmailMeetingInfo2(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMessage :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMessage>
{
    IEmailMessage(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMessage2 :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMessage2>
{
    IEmailMessage2(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMessage3 :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMessage3>
{
    IEmailMessage3(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMessageBatch :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMessageBatch>
{
    IEmailMessageBatch(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMessageReader :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMessageReader>
{
    IEmailMessageReader(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailQueryOptions :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailQueryOptions>
{
    IEmailQueryOptions(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailQueryOptionsFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailQueryOptionsFactory>
{
    IEmailQueryOptionsFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailQueryTextSearch :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailQueryTextSearch>
{
    IEmailQueryTextSearch(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailRecipient :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailRecipient>
{
    IEmailRecipient(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailRecipientFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailRecipientFactory>
{
    IEmailRecipientFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailRecipientResolutionResult :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailRecipientResolutionResult>
{
    IEmailRecipientResolutionResult(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailRecipientResolutionResult2 :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailRecipientResolutionResult2>
{
    IEmailRecipientResolutionResult2(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailStore :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailStore>
{
    IEmailStore(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailStoreNotificationTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailStoreNotificationTriggerDetails>
{
    IEmailStoreNotificationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

}

}
