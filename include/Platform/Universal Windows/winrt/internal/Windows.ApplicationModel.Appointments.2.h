// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Appointments.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif

#ifndef WINRT_GENERIC_3e1fe603_f897_5263_b328_0806426b8a79
#define WINRT_GENERIC_3e1fe603_f897_5263_b328_0806426b8a79
template <> struct __declspec(uuid("3e1fe603-f897-5263-b328-0806426b8a79")) __declspec(novtable) IAsyncOperation<hstring> : impl_IAsyncOperation<hstring> {};
#endif

#ifndef WINRT_GENERIC_63798415_4d1f_5fc7_8729_79a282bceca4
#define WINRT_GENERIC_63798415_4d1f_5fc7_8729_79a282bceca4
template <> struct __declspec(uuid("63798415-4d1f-5fc7-8729-79a282bceca4")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentStore> : impl_IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentStore> {};
#endif

#ifndef WINRT_GENERIC_513ef3af_e784_5325_a91e_97c2b8111cf3
#define WINRT_GENERIC_513ef3af_e784_5325_a91e_97c2b8111cf3
template <> struct __declspec(uuid("513ef3af-e784-5325-a91e-97c2b8111cf3")) __declspec(novtable) IReference<uint32_t> : impl_IReference<uint32_t> {};
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

#ifndef WINRT_GENERIC_70f4b32e_f91e_55bb_9a92_0246da734bb0
#define WINRT_GENERIC_70f4b32e_f91e_55bb_9a92_0246da734bb0
template <> struct __declspec(uuid("70f4b32e-f91e-55bb-9a92-0246da734bb0")) __declspec(novtable) IVector<Windows::ApplicationModel::Appointments::AppointmentInvitee> : impl_IVector<Windows::ApplicationModel::Appointments::AppointmentInvitee> {};
#endif

#ifndef WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
#define WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
template <> struct __declspec(uuid("98b9acc1-4b56-532e-ac73-03d5291cca90")) __declspec(novtable) IVector<hstring> : impl_IVector<hstring> {};
#endif

#ifndef WINRT_GENERIC_61021758_9e37_5a86_a832_aab31f32692b
#define WINRT_GENERIC_61021758_9e37_5a86_a832_aab31f32692b
template <> struct __declspec(uuid("61021758-9e37-5a86-a832-aab31f32692b")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Appointments::Appointment> : impl_IVectorView<Windows::ApplicationModel::Appointments::Appointment> {};
#endif

#ifndef WINRT_GENERIC_e5030866_08d8_56be_a21b_c5bf80d70360
#define WINRT_GENERIC_e5030866_08d8_56be_a21b_c5bf80d70360
template <> struct __declspec(uuid("e5030866-08d8-56be-a21b-c5bf80d70360")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Appointments::AppointmentException> : impl_IVectorView<Windows::ApplicationModel::Appointments::AppointmentException> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_0c5732f8_5bb9_5bb3_93e5_b87e43e0cd6a
#define WINRT_GENERIC_0c5732f8_5bb9_5bb3_93e5_b87e43e0cd6a
template <> struct __declspec(uuid("0c5732f8-5bb9-5bb3-93e5-b87e43e0cd6a")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Appointments::Appointment> : impl_IAsyncOperation<Windows::ApplicationModel::Appointments::Appointment> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_fb9718a9_f059_52b0_a904_1a65e4281e40
#define WINRT_GENERIC_fb9718a9_f059_52b0_a904_1a65e4281e40
template <> struct __declspec(uuid("fb9718a9-f059-52b0-a904-1a65e4281e40")) __declspec(novtable) IIterable<Windows::ApplicationModel::Appointments::AppointmentInvitee> : impl_IIterable<Windows::ApplicationModel::Appointments::AppointmentInvitee> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_bd1308de_6d2e_5541_b254_bdb61839bac1
#define WINRT_GENERIC_bd1308de_6d2e_5541_b254_bdb61839bac1
template <> struct __declspec(uuid("bd1308de-6d2e-5541-b254-bdb61839bac1")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Appointments::AppointmentCalendarSyncManager, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::ApplicationModel::Appointments::AppointmentCalendarSyncManager, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_4f9dd4e5_c3ae_5269_aff5_fe35cd50c3bb
#define WINRT_GENERIC_4f9dd4e5_c3ae_5269_aff5_fe35cd50c3bb
template <> struct __declspec(uuid("4f9dd4e5-c3ae-5269-aff5-fe35cd50c3bb")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Appointments::AppointmentStoreChange> : impl_IVectorView<Windows::ApplicationModel::Appointments::AppointmentStoreChange> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_6bb17a95_918e_5ad0_bbc2_bcc5fa1ff936
#define WINRT_GENERIC_6bb17a95_918e_5ad0_bbc2_bcc5fa1ff936
template <> struct __declspec(uuid("6bb17a95-918e-5ad0-bbc2-bcc5fa1ff936")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentCalendar> : impl_IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentCalendar> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_774512d3_a564_5f8d_b104_3ec8f2a1104f
#define WINRT_GENERIC_774512d3_a564_5f8d_b104_3ec8f2a1104f
template <> struct __declspec(uuid("774512d3-a564-5f8d-b104-3ec8f2a1104f")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Appointments::AppointmentCalendar> : impl_IVectorView<Windows::ApplicationModel::Appointments::AppointmentCalendar> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_b376080f_e5b2_5ae2_9901_86cf77ba5d00
#define WINRT_GENERIC_b376080f_e5b2_5ae2_9901_86cf77ba5d00
template <> struct __declspec(uuid("b376080f-e5b2-5ae2-9901-86cf77ba5d00")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentConflictResult> : impl_IAsyncOperation<Windows::ApplicationModel::Appointments::AppointmentConflictResult> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_9e628351_c639_5cef_ab1d_8beae9d75d52
#define WINRT_GENERIC_9e628351_c639_5cef_ab1d_8beae9d75d52
template <> struct __declspec(uuid("9e628351-c639-5cef-ab1d-8beae9d75d52")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Appointments::AppointmentStore, Windows::ApplicationModel::Appointments::AppointmentStoreChangedEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Appointments::AppointmentStore, Windows::ApplicationModel::Appointments::AppointmentStoreChangedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_ba2f633a_5182_5eda_8e2e_a66e55b320ce
#define WINRT_GENERIC_ba2f633a_5182_5eda_8e2e_a66e55b320ce
template <> struct __declspec(uuid("ba2f633a-5182-5eda-8e2e-a66e55b320ce")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Appointments::AppointmentInvitee> : impl_IVectorView<Windows::ApplicationModel::Appointments::AppointmentInvitee> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
#define WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
template <> struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a")) __declspec(novtable) AsyncOperationCompletedHandler<bool> : impl_AsyncOperationCompletedHandler<bool> {};
#endif

#ifndef WINRT_GENERIC_b79a741f_7fb5_50ae_9e99_911201ec3d41
#define WINRT_GENERIC_b79a741f_7fb5_50ae_9e99_911201ec3d41
template <> struct __declspec(uuid("b79a741f-7fb5-50ae-9e99-911201ec3d41")) __declspec(novtable) AsyncOperationCompletedHandler<hstring> : impl_AsyncOperationCompletedHandler<hstring> {};
#endif

#ifndef WINRT_GENERIC_bccf6d2a_ab72_5f23_b7d5_4c2c9bd45b79
#define WINRT_GENERIC_bccf6d2a_ab72_5f23_b7d5_4c2c9bd45b79
template <> struct __declspec(uuid("bccf6d2a-ab72-5f23-b7d5-4c2c9bd45b79")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Appointments::AppointmentStore> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Appointments::AppointmentStore> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_57e35198_1b41_54da_adaf_50ef1e93fded
#define WINRT_GENERIC_57e35198_1b41_54da_adaf_50ef1e93fded
template <> struct __declspec(uuid("57e35198-1b41-54da-adaf-50ef1e93fded")) __declspec(novtable) IIterator<Windows::ApplicationModel::Appointments::AppointmentInvitee> : impl_IIterator<Windows::ApplicationModel::Appointments::AppointmentInvitee> {};
#endif

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_386a5922_49fc_53b6_8bed_4c9ff9fe6e01
#define WINRT_GENERIC_386a5922_49fc_53b6_8bed_4c9ff9fe6e01
template <> struct __declspec(uuid("386a5922-49fc-53b6-8bed-4c9ff9fe6e01")) __declspec(novtable) IIterator<Windows::ApplicationModel::Appointments::Appointment> : impl_IIterator<Windows::ApplicationModel::Appointments::Appointment> {};
#endif

#ifndef WINRT_GENERIC_b9802bba_ff53_5d37_8cd7_e56162f12156
#define WINRT_GENERIC_b9802bba_ff53_5d37_8cd7_e56162f12156
template <> struct __declspec(uuid("b9802bba-ff53-5d37-8cd7-e56162f12156")) __declspec(novtable) IIterable<Windows::ApplicationModel::Appointments::Appointment> : impl_IIterable<Windows::ApplicationModel::Appointments::Appointment> {};
#endif

#ifndef WINRT_GENERIC_e58c63db_d9d5_5fa5_8790_29846de54fa4
#define WINRT_GENERIC_e58c63db_d9d5_5fa5_8790_29846de54fa4
template <> struct __declspec(uuid("e58c63db-d9d5-5fa5-8790-29846de54fa4")) __declspec(novtable) IIterator<Windows::ApplicationModel::Appointments::AppointmentException> : impl_IIterator<Windows::ApplicationModel::Appointments::AppointmentException> {};
#endif

#ifndef WINRT_GENERIC_caac41d6_6c65_5fd8_b783_eb9d9a4272b8
#define WINRT_GENERIC_caac41d6_6c65_5fd8_b783_eb9d9a4272b8
template <> struct __declspec(uuid("caac41d6-6c65-5fd8-b783-eb9d9a4272b8")) __declspec(novtable) IIterable<Windows::ApplicationModel::Appointments::AppointmentException> : impl_IIterable<Windows::ApplicationModel::Appointments::AppointmentException> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_b640ed04_9331_5b28_9247_0146bcf5b72a
#define WINRT_GENERIC_b640ed04_9331_5b28_9247_0146bcf5b72a
template <> struct __declspec(uuid("b640ed04-9331-5b28-9247-0146bcf5b72a")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Appointments::Appointment> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Appointments::Appointment> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_16a427bf_e5b0_5662_9279_caa8ed8481a6
#define WINRT_GENERIC_16a427bf_e5b0_5662_9279_caa8ed8481a6
template <> struct __declspec(uuid("16a427bf-e5b0-5662-9279-caa8ed8481a6")) __declspec(novtable) IIterator<Windows::ApplicationModel::Appointments::AppointmentStoreChange> : impl_IIterator<Windows::ApplicationModel::Appointments::AppointmentStoreChange> {};
#endif

#ifndef WINRT_GENERIC_7b657ca2_e02e_5026_a032_9905e49682fd
#define WINRT_GENERIC_7b657ca2_e02e_5026_a032_9905e49682fd
template <> struct __declspec(uuid("7b657ca2-e02e-5026-a032-9905e49682fd")) __declspec(novtable) IIterable<Windows::ApplicationModel::Appointments::AppointmentStoreChange> : impl_IIterable<Windows::ApplicationModel::Appointments::AppointmentStoreChange> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_6d9cb651_5af6_51b0_9cd3_45dd51f17949
#define WINRT_GENERIC_6d9cb651_5af6_51b0_9cd3_45dd51f17949
template <> struct __declspec(uuid("6d9cb651-5af6-51b0-9cd3-45dd51f17949")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Appointments::AppointmentCalendar> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Appointments::AppointmentCalendar> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_f40a879d_b6b7_5f92_beb1_6a8e7ce54120
#define WINRT_GENERIC_f40a879d_b6b7_5f92_beb1_6a8e7ce54120
template <> struct __declspec(uuid("f40a879d-b6b7-5f92-beb1-6a8e7ce54120")) __declspec(novtable) IIterator<Windows::ApplicationModel::Appointments::AppointmentCalendar> : impl_IIterator<Windows::ApplicationModel::Appointments::AppointmentCalendar> {};
#endif

#ifndef WINRT_GENERIC_d3fb010b_b692_5130_9d16_2cfdabcb6dec
#define WINRT_GENERIC_d3fb010b_b692_5130_9d16_2cfdabcb6dec
template <> struct __declspec(uuid("d3fb010b-b692-5130-9d16-2cfdabcb6dec")) __declspec(novtable) IIterable<Windows::ApplicationModel::Appointments::AppointmentCalendar> : impl_IIterable<Windows::ApplicationModel::Appointments::AppointmentCalendar> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_82fb40fe_05b1_523c_9b53_b3dd759c9f75
#define WINRT_GENERIC_82fb40fe_05b1_523c_9b53_b3dd759c9f75
template <> struct __declspec(uuid("82fb40fe-05b1-523c-9b53-b3dd759c9f75")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Appointments::AppointmentConflictResult> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Appointments::AppointmentConflictResult> {};
#endif

#ifndef WINRT_GENERIC_a6bb6962_e2c1_5da2_9938_15ef82cbd1cc
#define WINRT_GENERIC_a6bb6962_e2c1_5da2_9938_15ef82cbd1cc
template <> struct __declspec(uuid("a6bb6962-e2c1-5da2-9938-15ef82cbd1cc")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> {};
#endif

#ifndef WINRT_GENERIC_87e171ac_53fe_50ea_beb3_0589993ac984
#define WINRT_GENERIC_87e171ac_53fe_50ea_beb3_0589993ac984
template <> struct __declspec(uuid("87e171ac-53fe-50ea-beb3-0589993ac984")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentException>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentException>> {};
#endif

#ifndef WINRT_GENERIC_d54944b9_b72e_50bc_a64a_19396e0d1bcc
#define WINRT_GENERIC_d54944b9_b72e_50bc_a64a_19396e0d1bcc
template <> struct __declspec(uuid("d54944b9-b72e-50bc-a64a-19396e0d1bcc")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentStoreChange>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentStoreChange>> {};
#endif

#ifndef WINRT_GENERIC_d26021ac_99b4_5c40_b0d2_d6835d2e9202
#define WINRT_GENERIC_d26021ac_99b4_5c40_b0d2_d6835d2e9202
template <> struct __declspec(uuid("d26021ac-99b4-5c40-b0d2-d6835d2e9202")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentCalendar>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentCalendar>> {};
#endif

#ifndef WINRT_GENERIC_2f92b529_119b_575a_a419_3904b4e41af2
#define WINRT_GENERIC_2f92b529_119b_575a_a419_3904b4e41af2
template <> struct __declspec(uuid("2f92b529-119b-575a-a419-3904b4e41af2")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<hstring>> {};
#endif

#ifndef WINRT_GENERIC_f626345f_7bfc_5418_9f47_f1d86306e06b
#define WINRT_GENERIC_f626345f_7bfc_5418_9f47_f1d86306e06b
template <> struct __declspec(uuid("f626345f-7bfc-5418-9f47-f1d86306e06b")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::Appointment>> {};
#endif

#ifndef WINRT_GENERIC_60e2023c_c2a9_5d3c_86b1_cd221c308a5e
#define WINRT_GENERIC_60e2023c_c2a9_5d3c_86b1_cd221c308a5e
template <> struct __declspec(uuid("60e2023c-c2a9-5d3c-86b1-cd221c308a5e")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentException>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentException>> {};
#endif

#ifndef WINRT_GENERIC_3fe84fc8_da80_5fab_8b46_3720f7646345
#define WINRT_GENERIC_3fe84fc8_da80_5fab_8b46_3720f7646345
template <> struct __declspec(uuid("3fe84fc8-da80-5fab-8b46-3720f7646345")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentStoreChange>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentStoreChange>> {};
#endif

#ifndef WINRT_GENERIC_f478469b_9777_553d_beab_1bb5eee1ca8b
#define WINRT_GENERIC_f478469b_9777_553d_beab_1bb5eee1ca8b
template <> struct __declspec(uuid("f478469b-9777-553d-beab-1bb5eee1ca8b")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentCalendar>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Appointments::AppointmentCalendar>> {};
#endif

#ifndef WINRT_GENERIC_7c7899be_5f2e_5bf3_ade5_ad98b772c7cd
#define WINRT_GENERIC_7c7899be_5f2e_5bf3_ade5_ad98b772c7cd
template <> struct __declspec(uuid("7c7899be-5f2e-5bf3-ade5-ad98b772c7cd")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<hstring>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<hstring>> {};
#endif


}

namespace Windows::ApplicationModel::Appointments {

struct IAppointment :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointment>
{
    IAppointment(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointment2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointment2>,
    impl::require<IAppointment2, Windows::ApplicationModel::Appointments::IAppointment>
{
    IAppointment2(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointment3 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointment3>,
    impl::require<IAppointment3, Windows::ApplicationModel::Appointments::IAppointment, Windows::ApplicationModel::Appointments::IAppointment2>
{
    IAppointment3(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentCalendar :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentCalendar>
{
    IAppointmentCalendar(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentCalendar2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentCalendar2>,
    impl::require<IAppointmentCalendar2, Windows::ApplicationModel::Appointments::IAppointmentCalendar>
{
    IAppointmentCalendar2(std::nullptr_t = nullptr) noexcept {}
    using impl_IAppointmentCalendar::DisplayColor;
    using impl_IAppointmentCalendar::IsHidden;
    using impl_IAppointmentCalendar2::DisplayColor;
    using impl_IAppointmentCalendar2::IsHidden;
};

struct IAppointmentCalendar3 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentCalendar3>
{
    IAppointmentCalendar3(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentCalendarSyncManager :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentCalendarSyncManager>
{
    IAppointmentCalendarSyncManager(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentCalendarSyncManager2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentCalendarSyncManager2>
{
    IAppointmentCalendarSyncManager2(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentConflictResult :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentConflictResult>
{
    IAppointmentConflictResult(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentException :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentException>
{
    IAppointmentException(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentInvitee :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentInvitee>,
    impl::require<IAppointmentInvitee, Windows::ApplicationModel::Appointments::IAppointmentParticipant>
{
    IAppointmentInvitee(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentManagerForUser :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentManagerForUser>
{
    IAppointmentManagerForUser(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentManagerStatics>
{
    IAppointmentManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentManagerStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentManagerStatics2>
{
    IAppointmentManagerStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentManagerStatics3 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentManagerStatics3>
{
    IAppointmentManagerStatics3(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentParticipant :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentParticipant>
{
    IAppointmentParticipant(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentPropertiesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentPropertiesStatics>
{
    IAppointmentPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentPropertiesStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentPropertiesStatics2>,
    impl::require<IAppointmentPropertiesStatics2, Windows::ApplicationModel::Appointments::IAppointmentPropertiesStatics>
{
    IAppointmentPropertiesStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentRecurrence :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentRecurrence>
{
    IAppointmentRecurrence(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentRecurrence2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentRecurrence2>,
    impl::require<IAppointmentRecurrence2, Windows::ApplicationModel::Appointments::IAppointmentRecurrence>
{
    IAppointmentRecurrence2(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentRecurrence3 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentRecurrence3>,
    impl::require<IAppointmentRecurrence3, Windows::ApplicationModel::Appointments::IAppointmentRecurrence, Windows::ApplicationModel::Appointments::IAppointmentRecurrence2>
{
    IAppointmentRecurrence3(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentStore :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentStore>
{
    IAppointmentStore(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentStore2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentStore2>,
    impl::require<IAppointmentStore2, Windows::ApplicationModel::Appointments::IAppointmentStore>
{
    IAppointmentStore2(std::nullptr_t = nullptr) noexcept {}
    using impl_IAppointmentStore::CreateAppointmentCalendarAsync;
    using impl_IAppointmentStore2::CreateAppointmentCalendarAsync;
};

struct IAppointmentStoreChange :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentStoreChange>
{
    IAppointmentStoreChange(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentStoreChange2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentStoreChange2>,
    impl::require<IAppointmentStoreChange2, Windows::ApplicationModel::Appointments::IAppointmentStoreChange>
{
    IAppointmentStoreChange2(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentStoreChangeReader :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentStoreChangeReader>
{
    IAppointmentStoreChangeReader(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentStoreChangeTracker :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentStoreChangeTracker>
{
    IAppointmentStoreChangeTracker(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentStoreChangedDeferral :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentStoreChangedDeferral>
{
    IAppointmentStoreChangedDeferral(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentStoreChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentStoreChangedEventArgs>
{
    IAppointmentStoreChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAppointmentStoreNotificationTriggerDetails :
    Windows::Foundation::IInspectable,
    impl::consume<IAppointmentStoreNotificationTriggerDetails>
{
    IAppointmentStoreNotificationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
};

struct IFindAppointmentsOptions :
    Windows::Foundation::IInspectable,
    impl::consume<IFindAppointmentsOptions>
{
    IFindAppointmentsOptions(std::nullptr_t = nullptr) noexcept {}
};

}

}
