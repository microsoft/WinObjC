// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Email.DataProvider.1.h"

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

#ifndef WINRT_GENERIC_5f18cab2_236d_5ec5_bc64_e3e63d29e774
#define WINRT_GENERIC_5f18cab2_236d_5ec5_bc64_e3e63d29e774
template <> struct __declspec(uuid("5f18cab2-236d-5ec5-bc64-e3e63d29e774")) __declspec(novtable) IIterable<Windows::ApplicationModel::Email::EmailRecipient> : impl_IIterable<Windows::ApplicationModel::Email::EmailRecipient> {};
#endif

#ifndef WINRT_GENERIC_0c7d1423_e8fd_5a91_b55c_8bfbe7ac2d40
#define WINRT_GENERIC_0c7d1423_e8fd_5a91_b55c_8bfbe7ac2d40
template <> struct __declspec(uuid("0c7d1423-e8fd-5a91-b55c-8bfbe7ac2d40")) __declspec(novtable) IIterable<Windows::Security::Cryptography::Certificates::Certificate> : impl_IIterable<Windows::Security::Cryptography::Certificates::Certificate> {};
#endif

#ifndef WINRT_GENERIC_963f7013_77c2_51c5_8038_b5bcef633edb
#define WINRT_GENERIC_963f7013_77c2_51c5_8038_b5bcef633edb
template <> struct __declspec(uuid("963f7013-77c2-51c5-8038-b5bcef633edb")) __declspec(novtable) IVectorView<Windows::Security::Cryptography::Certificates::Certificate> : impl_IVectorView<Windows::Security::Cryptography::Certificates::Certificate> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_b65fc3ec_9476_51c4_ba70_1505d79826b9
#define WINRT_GENERIC_b65fc3ec_9476_51c4_ba70_1505d79826b9
template <> struct __declspec(uuid("b65fc3ec-9476-51c4-ba70-1505d79826b9")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSyncManagerSyncRequestEventArgs> {};
#endif

#ifndef WINRT_GENERIC_e1b59b2f_ddd5_5159_ae9a_14a866912095
#define WINRT_GENERIC_e1b59b2f_ddd5_5159_ae9a_14a866912095
template <> struct __declspec(uuid("e1b59b2f-ddd5-5159-ae9a-14a866912095")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadMessageRequestEventArgs> {};
#endif

#ifndef WINRT_GENERIC_d2e92019_b997_5cd6_8f88_4dbc6f969f15
#define WINRT_GENERIC_d2e92019_b997_5cd6_8f88_4dbc6f969f15
template <> struct __declspec(uuid("d2e92019-b997-5cd6-8f88-4dbc6f969f15")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDownloadAttachmentRequestEventArgs> {};
#endif

#ifndef WINRT_GENERIC_8c7db52d_496e_5419_bd78_b8b657cf4e66
#define WINRT_GENERIC_8c7db52d_496e_5419_bd78_b8b657cf4e66
template <> struct __declspec(uuid("8c7db52d-496e-5419-bd78-b8b657cf4e66")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxCreateFolderRequestEventArgs> {};
#endif

#ifndef WINRT_GENERIC_d962a9b6_bbb4_5d82_84b4_8f703bf3086f
#define WINRT_GENERIC_d962a9b6_bbb4_5d82_84b4_8f703bf3086f
template <> struct __declspec(uuid("d962a9b6-bbb4-5d82-84b4-8f703bf3086f")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxDeleteFolderRequestEventArgs> {};
#endif

#ifndef WINRT_GENERIC_9a851b84_bcb1_5121_ab61_3efe568f683d
#define WINRT_GENERIC_9a851b84_bcb1_5121_ab61_3efe568f683d
template <> struct __declspec(uuid("9a851b84-bcb1-5121-ab61-3efe568f683d")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxEmptyFolderRequestEventArgs> {};
#endif

#ifndef WINRT_GENERIC_2c6bf2c8_42f3_523d_80db_170e4fb1567f
#define WINRT_GENERIC_2c6bf2c8_42f3_523d_80db_170e4fb1567f
template <> struct __declspec(uuid("2c6bf2c8-42f3-523d-80db-170e4fb1567f")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxMoveFolderRequestEventArgs> {};
#endif

#ifndef WINRT_GENERIC_3274fbfd_c10a_5b30_adea_2b4b860b4a0d
#define WINRT_GENERIC_3274fbfd_c10a_5b30_adea_2b4b860b4a0d
template <> struct __declspec(uuid("3274fbfd-c10a-5b30-adea-2b4b860b4a0d")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxUpdateMeetingResponseRequestEventArgs> {};
#endif

#ifndef WINRT_GENERIC_9d6a017f_5a70_5d83_a680_d2806748ca0b
#define WINRT_GENERIC_9d6a017f_5a70_5d83_a680_d2806748ca0b
template <> struct __declspec(uuid("9d6a017f-5a70-5d83-a680-d2806748ca0b")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxForwardMeetingRequestEventArgs> {};
#endif

#ifndef WINRT_GENERIC_309d8bde_1e60_524b_828c_5a3d64a672aa
#define WINRT_GENERIC_309d8bde_1e60_524b_828c_5a3d64a672aa
template <> struct __declspec(uuid("309d8bde-1e60-524b-828c-5a3d64a672aa")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxProposeNewTimeForMeetingRequestEventArgs> {};
#endif

#ifndef WINRT_GENERIC_aa4f8fb3_05e0_54e6_afac_a28e853e756e
#define WINRT_GENERIC_aa4f8fb3_05e0_54e6_afac_a28e853e756e
template <> struct __declspec(uuid("aa4f8fb3-05e0-54e6-afac-a28e853e756e")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxSetAutoReplySettingsRequestEventArgs> {};
#endif

#ifndef WINRT_GENERIC_587c6f92_a969_57b3_895f_9a06b3650d3a
#define WINRT_GENERIC_587c6f92_a969_57b3_895f_9a06b3650d3a
template <> struct __declspec(uuid("587c6f92-a969-57b3-895f-9a06b3650d3a")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxGetAutoReplySettingsRequestEventArgs> {};
#endif

#ifndef WINRT_GENERIC_ec14e586_e4fb_5fc0_91fc_931ce17a3fc3
#define WINRT_GENERIC_ec14e586_e4fb_5fc0_91fc_931ce17a3fc3
template <> struct __declspec(uuid("ec14e586-e4fb-5fc0-91fc-931ce17a3fc3")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxResolveRecipientsRequestEventArgs> {};
#endif

#ifndef WINRT_GENERIC_de2625f7_e16f_512e_a8c6_b7445532bcc6
#define WINRT_GENERIC_de2625f7_e16f_512e_a8c6_b7445532bcc6
template <> struct __declspec(uuid("de2625f7-e16f-512e-a8c6-b7445532bcc6")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxValidateCertificatesRequestEventArgs> {};
#endif

#ifndef WINRT_GENERIC_f8bf9067_7d11_56a0_a303_163435c14016
#define WINRT_GENERIC_f8bf9067_7d11_56a0_a303_163435c14016
template <> struct __declspec(uuid("f8bf9067-7d11-56a0-a303-163435c14016")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequestEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Email::DataProvider::EmailDataProviderConnection, Windows::ApplicationModel::Email::DataProvider::EmailMailboxServerSearchReadBatchRequestEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

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

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_12238d88_1a2f_5e7a_89b1_8dc140536bac
#define WINRT_GENERIC_12238d88_1a2f_5e7a_89b1_8dc140536bac
template <> struct __declspec(uuid("12238d88-1a2f-5e7a-89b1-8dc140536bac")) __declspec(novtable) IIterator<Windows::ApplicationModel::Email::EmailRecipient> : impl_IIterator<Windows::ApplicationModel::Email::EmailRecipient> {};
#endif

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

namespace Windows::ApplicationModel::Email::DataProvider {

struct IEmailDataProviderConnection :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailDataProviderConnection>
{
    IEmailDataProviderConnection(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailDataProviderTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailDataProviderTriggerDetails>
{
    IEmailDataProviderTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxCreateFolderRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxCreateFolderRequest>
{
    IEmailMailboxCreateFolderRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxCreateFolderRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxCreateFolderRequestEventArgs>
{
    IEmailMailboxCreateFolderRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxDeleteFolderRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxDeleteFolderRequest>
{
    IEmailMailboxDeleteFolderRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxDeleteFolderRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxDeleteFolderRequestEventArgs>
{
    IEmailMailboxDeleteFolderRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxDownloadAttachmentRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxDownloadAttachmentRequest>
{
    IEmailMailboxDownloadAttachmentRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxDownloadAttachmentRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxDownloadAttachmentRequestEventArgs>
{
    IEmailMailboxDownloadAttachmentRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxDownloadMessageRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxDownloadMessageRequest>
{
    IEmailMailboxDownloadMessageRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxDownloadMessageRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxDownloadMessageRequestEventArgs>
{
    IEmailMailboxDownloadMessageRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxEmptyFolderRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxEmptyFolderRequest>
{
    IEmailMailboxEmptyFolderRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxEmptyFolderRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxEmptyFolderRequestEventArgs>
{
    IEmailMailboxEmptyFolderRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxForwardMeetingRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxForwardMeetingRequest>
{
    IEmailMailboxForwardMeetingRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxForwardMeetingRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxForwardMeetingRequestEventArgs>
{
    IEmailMailboxForwardMeetingRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxGetAutoReplySettingsRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxGetAutoReplySettingsRequest>
{
    IEmailMailboxGetAutoReplySettingsRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxGetAutoReplySettingsRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxGetAutoReplySettingsRequestEventArgs>
{
    IEmailMailboxGetAutoReplySettingsRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxMoveFolderRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxMoveFolderRequest>
{
    IEmailMailboxMoveFolderRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxMoveFolderRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxMoveFolderRequestEventArgs>
{
    IEmailMailboxMoveFolderRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxProposeNewTimeForMeetingRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxProposeNewTimeForMeetingRequest>
{
    IEmailMailboxProposeNewTimeForMeetingRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxProposeNewTimeForMeetingRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxProposeNewTimeForMeetingRequestEventArgs>
{
    IEmailMailboxProposeNewTimeForMeetingRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxResolveRecipientsRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxResolveRecipientsRequest>
{
    IEmailMailboxResolveRecipientsRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxResolveRecipientsRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxResolveRecipientsRequestEventArgs>
{
    IEmailMailboxResolveRecipientsRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxServerSearchReadBatchRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxServerSearchReadBatchRequest>
{
    IEmailMailboxServerSearchReadBatchRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxServerSearchReadBatchRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxServerSearchReadBatchRequestEventArgs>
{
    IEmailMailboxServerSearchReadBatchRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxSetAutoReplySettingsRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxSetAutoReplySettingsRequest>
{
    IEmailMailboxSetAutoReplySettingsRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxSetAutoReplySettingsRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxSetAutoReplySettingsRequestEventArgs>
{
    IEmailMailboxSetAutoReplySettingsRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxSyncManagerSyncRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxSyncManagerSyncRequest>
{
    IEmailMailboxSyncManagerSyncRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxSyncManagerSyncRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxSyncManagerSyncRequestEventArgs>
{
    IEmailMailboxSyncManagerSyncRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxUpdateMeetingResponseRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxUpdateMeetingResponseRequest>
{
    IEmailMailboxUpdateMeetingResponseRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxUpdateMeetingResponseRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxUpdateMeetingResponseRequestEventArgs>
{
    IEmailMailboxUpdateMeetingResponseRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxValidateCertificatesRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxValidateCertificatesRequest>
{
    IEmailMailboxValidateCertificatesRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IEmailMailboxValidateCertificatesRequestEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEmailMailboxValidateCertificatesRequestEventArgs>
{
    IEmailMailboxValidateCertificatesRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
};

}

}
