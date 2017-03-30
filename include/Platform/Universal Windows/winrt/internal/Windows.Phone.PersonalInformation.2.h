// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.PersonalInformation.1.h"

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


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_ef60385f_be78_584b_aaef_7829ada2b0de
#define WINRT_GENERIC_ef60385f_be78_584b_aaef_7829ada2b0de
template <> struct __declspec(uuid("ef60385f-be78-584b-aaef-7829ada2b0de")) __declspec(novtable) IAsyncOperation<uint32_t> : impl_IAsyncOperation<uint32_t> {};
#endif

#ifndef WINRT_GENERIC_430ecece_1418_5d19_81b2_5ddb381603cc
#define WINRT_GENERIC_430ecece_1418_5d19_81b2_5ddb381603cc
template <> struct __declspec(uuid("430ecece-1418-5d19-81b2-5ddb381603cc")) __declspec(novtable) IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> : impl_IAsyncOperation<Windows::Storage::Streams::IRandomAccessStream> {};
#endif

#ifndef WINRT_GENERIC_9adc7f28_4610_588c_a1a7_2d5a3d46db2e
#define WINRT_GENERIC_9adc7f28_4610_588c_a1a7_2d5a3d46db2e
template <> struct __declspec(uuid("9adc7f28-4610-588c-a1a7-2d5a3d46db2e")) __declspec(novtable) IAsyncOperation<Windows::Phone::PersonalInformation::ContactInformation> : impl_IAsyncOperation<Windows::Phone::PersonalInformation::ContactInformation> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_3a58770f_84bd_525c_8bd2_e3fa5ba336b3
#define WINRT_GENERIC_3a58770f_84bd_525c_8bd2_e3fa5ba336b3
template <> struct __declspec(uuid("3a58770f-84bd-525c-8bd2-e3fa5ba336b3")) __declspec(novtable) IVectorView<Windows::Phone::PersonalInformation::StoredContact> : impl_IVectorView<Windows::Phone::PersonalInformation::StoredContact> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_40f6e9ed_afca_52ef_ad40_4d47e34b2475
#define WINRT_GENERIC_40f6e9ed_afca_52ef_ad40_4d47e34b2475
template <> struct __declspec(uuid("40f6e9ed-afca-52ef-ad40-4d47e34b2475")) __declspec(novtable) IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact> : impl_IAsyncOperation<Windows::Phone::PersonalInformation::StoredContact> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_5738a7d6_8147_599b_b222_215c88ac7662
#define WINRT_GENERIC_5738a7d6_8147_599b_b222_215c88ac7662
template <> struct __declspec(uuid("5738a7d6-8147-599b-b222-215c88ac7662")) __declspec(novtable) IVectorView<Windows::Phone::PersonalInformation::ContactChangeRecord> : impl_IVectorView<Windows::Phone::PersonalInformation::ContactChangeRecord> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_1fae53d9_138f_5e60_b7b6_1a454ca61afe
#define WINRT_GENERIC_1fae53d9_138f_5e60_b7b6_1a454ca61afe
template <> struct __declspec(uuid("1fae53d9-138f-5e60-b7b6-1a454ca61afe")) __declspec(novtable) IAsyncOperation<Windows::Phone::PersonalInformation::ContactStore> : impl_IAsyncOperation<Windows::Phone::PersonalInformation::ContactStore> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_9343b6e7_e3d2_5e4a_ab2d_2bce4919a6a4
#define WINRT_GENERIC_9343b6e7_e3d2_5e4a_ab2d_2bce4919a6a4
template <> struct __declspec(uuid("9343b6e7-e3d2-5e4a-ab2d-2bce4919a6a4")) __declspec(novtable) AsyncOperationCompletedHandler<uint32_t> : impl_AsyncOperationCompletedHandler<uint32_t> {};
#endif

#ifndef WINRT_GENERIC_398c4183_793d_5b00_819b_4aef92485e94
#define WINRT_GENERIC_398c4183_793d_5b00_819b_4aef92485e94
template <> struct __declspec(uuid("398c4183-793d-5b00-819b-4aef92485e94")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::Streams::IRandomAccessStream> : impl_AsyncOperationCompletedHandler<Windows::Storage::Streams::IRandomAccessStream> {};
#endif

#ifndef WINRT_GENERIC_c99c97d5_9bf5_545a_bb17_4f1f0c7a2359
#define WINRT_GENERIC_c99c97d5_9bf5_545a_bb17_4f1f0c7a2359
template <> struct __declspec(uuid("c99c97d5-9bf5-545a-bb17-4f1f0c7a2359")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Phone::PersonalInformation::ContactInformation> : impl_AsyncOperationCompletedHandler<Windows::Phone::PersonalInformation::ContactInformation> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8d97c17a_5781_5198_a459_437f84a1d101
#define WINRT_GENERIC_8d97c17a_5781_5198_a459_437f84a1d101
template <> struct __declspec(uuid("8d97c17a-5781-5198-a459-437f84a1d101")) __declspec(novtable) IIterator<Windows::Phone::PersonalInformation::StoredContact> : impl_IIterator<Windows::Phone::PersonalInformation::StoredContact> {};
#endif

#ifndef WINRT_GENERIC_1a213316_53aa_5205_a8f0_6970cea3236c
#define WINRT_GENERIC_1a213316_53aa_5205_a8f0_6970cea3236c
template <> struct __declspec(uuid("1a213316-53aa-5205-a8f0-6970cea3236c")) __declspec(novtable) IIterable<Windows::Phone::PersonalInformation::StoredContact> : impl_IIterable<Windows::Phone::PersonalInformation::StoredContact> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c4b696d5_2d7b_50bc_8dc9_d267e87a1908
#define WINRT_GENERIC_c4b696d5_2d7b_50bc_8dc9_d267e87a1908
template <> struct __declspec(uuid("c4b696d5-2d7b-50bc-8dc9-d267e87a1908")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Phone::PersonalInformation::StoredContact> : impl_AsyncOperationCompletedHandler<Windows::Phone::PersonalInformation::StoredContact> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_72cc5afc_1154_56c5_a9c3_10d7aefc5380
#define WINRT_GENERIC_72cc5afc_1154_56c5_a9c3_10d7aefc5380
template <> struct __declspec(uuid("72cc5afc-1154-56c5-a9c3-10d7aefc5380")) __declspec(novtable) IIterator<Windows::Phone::PersonalInformation::ContactChangeRecord> : impl_IIterator<Windows::Phone::PersonalInformation::ContactChangeRecord> {};
#endif

#ifndef WINRT_GENERIC_987bdf50_f00e_5fa7_951e_32b5eeb1070d
#define WINRT_GENERIC_987bdf50_f00e_5fa7_951e_32b5eeb1070d
template <> struct __declspec(uuid("987bdf50-f00e-5fa7-951e-32b5eeb1070d")) __declspec(novtable) IIterable<Windows::Phone::PersonalInformation::ContactChangeRecord> : impl_IIterable<Windows::Phone::PersonalInformation::ContactChangeRecord> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_ff0854c3_b419_54e9_93dd_a03f6c5302ad
#define WINRT_GENERIC_ff0854c3_b419_54e9_93dd_a03f6c5302ad
template <> struct __declspec(uuid("ff0854c3-b419-54e9-93dd-a03f6c5302ad")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Phone::PersonalInformation::ContactStore> : impl_AsyncOperationCompletedHandler<Windows::Phone::PersonalInformation::ContactStore> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
#define WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
template <> struct __declspec(uuid("fe2f3d47-5d47-5499-8374-430c7cda0204")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_127e39c7_07c1_58e5_b48e_3a4729839fec
#define WINRT_GENERIC_127e39c7_07c1_58e5_b48e_3a4729839fec
template <> struct __declspec(uuid("127e39c7-07c1-58e5-b48e-3a4729839fec")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> : impl_IAsyncOperation<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> {};
#endif

#ifndef WINRT_GENERIC_b6724abf_1a00_5d1a_aef8_9e85a4e5cea8
#define WINRT_GENERIC_b6724abf_1a00_5d1a_aef8_9e85a4e5cea8
template <> struct __declspec(uuid("b6724abf-1a00-5d1a-aef8-9e85a4e5cea8")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::StoredContact>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::StoredContact>> {};
#endif

#ifndef WINRT_GENERIC_b1472970_8155_505e_9225_35889d584db0
#define WINRT_GENERIC_b1472970_8155_505e_9225_35889d584db0
template <> struct __declspec(uuid("b1472970-8155-505e-9225-35889d584db0")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::ContactChangeRecord>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::ContactChangeRecord>> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
#define WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
template <> struct __declspec(uuid("5db5fa32-707c-5849-a06b-91c8eb9d10e8")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_7344f356_8399_5756_a2f8_abd50c4146ff
#define WINRT_GENERIC_7344f356_8399_5756_a2f8_abd50c4146ff
template <> struct __declspec(uuid("7344f356-8399-5756-a2f8-abd50c4146ff")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IMap<hstring, Windows::Foundation::IInspectable>> {};
#endif

#ifndef WINRT_GENERIC_7abe3867_891d_5ee1_aeb0_c673e2c856de
#define WINRT_GENERIC_7abe3867_891d_5ee1_aeb0_c673e2c856de
template <> struct __declspec(uuid("7abe3867-891d-5ee1-aeb0-c673e2c856de")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::StoredContact>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::StoredContact>> {};
#endif

#ifndef WINRT_GENERIC_4cc06c54_47a0_5949_8640_e257ce0eef1e
#define WINRT_GENERIC_4cc06c54_47a0_5949_8640_e257ce0eef1e
template <> struct __declspec(uuid("4cc06c54-47a0-5949-8640-e257ce0eef1e")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::ContactChangeRecord>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Phone::PersonalInformation::ContactChangeRecord>> {};
#endif


}

namespace Windows::Phone::PersonalInformation {

struct IContactAddress :
    Windows::Foundation::IInspectable,
    impl::consume<IContactAddress>
{
    IContactAddress(std::nullptr_t = nullptr) noexcept {}
};

struct IContactChangeRecord :
    Windows::Foundation::IInspectable,
    impl::consume<IContactChangeRecord>
{
    IContactChangeRecord(std::nullptr_t = nullptr) noexcept {}
};

struct IContactInformation :
    Windows::Foundation::IInspectable,
    impl::consume<IContactInformation>
{
    IContactInformation(std::nullptr_t = nullptr) noexcept {}
};

struct IContactInformation2 :
    Windows::Foundation::IInspectable,
    impl::consume<IContactInformation2>
{
    IContactInformation2(std::nullptr_t = nullptr) noexcept {}
};

struct IContactInformationStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IContactInformationStatics>
{
    IContactInformationStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IContactQueryOptions :
    Windows::Foundation::IInspectable,
    impl::consume<IContactQueryOptions>
{
    IContactQueryOptions(std::nullptr_t = nullptr) noexcept {}
};

struct IContactQueryResult :
    Windows::Foundation::IInspectable,
    impl::consume<IContactQueryResult>
{
    IContactQueryResult(std::nullptr_t = nullptr) noexcept {}
};

struct IContactStore :
    Windows::Foundation::IInspectable,
    impl::consume<IContactStore>
{
    IContactStore(std::nullptr_t = nullptr) noexcept {}
};

struct IContactStore2 :
    Windows::Foundation::IInspectable,
    impl::consume<IContactStore2>
{
    IContactStore2(std::nullptr_t = nullptr) noexcept {}
};

struct IContactStoreStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IContactStoreStatics>
{
    IContactStoreStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IKnownContactPropertiesStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IKnownContactPropertiesStatics>
{
    IKnownContactPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IStoredContact :
    Windows::Foundation::IInspectable,
    impl::consume<IStoredContact>,
    impl::require<IStoredContact, Windows::Phone::PersonalInformation::IContactInformation>
{
    IStoredContact(std::nullptr_t = nullptr) noexcept {}
};

struct IStoredContactFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IStoredContactFactory>
{
    IStoredContactFactory(std::nullptr_t = nullptr) noexcept {}
};

}

}
