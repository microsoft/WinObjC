// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.ContentRestrictions.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif

#ifndef WINRT_GENERIC_513ef3af_e784_5325_a91e_97c2b8111cf3
#define WINRT_GENERIC_513ef3af_e784_5325_a91e_97c2b8111cf3
template <> struct __declspec(uuid("513ef3af-e784-5325-a91e-97c2b8111cf3")) __declspec(novtable) IReference<uint32_t> : impl_IReference<uint32_t> {};
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


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
#define WINRT_GENERIC_c50898f6_c536_5f47_8583_8b2c2438a13b
template <> struct __declspec(uuid("c50898f6-c536-5f47-8583-8b2c2438a13b")) __declspec(novtable) EventHandler<Windows::Foundation::IInspectable> : impl_EventHandler<Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_ae3399b2_c7d5_5f1b_9fb9_f8bd81e9f9be
#define WINRT_GENERIC_ae3399b2_c7d5_5f1b_9fb9_f8bd81e9f9be
template <> struct __declspec(uuid("ae3399b2-c7d5-5f1b-9fb9-f8bd81e9f9be")) __declspec(novtable) IAsyncOperation<Windows::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy> : impl_IAsyncOperation<Windows::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy> {};
#endif

#ifndef WINRT_GENERIC_860c0179_be01_546d_a9ce_5956464c98ab
#define WINRT_GENERIC_860c0179_be01_546d_a9ce_5956464c98ab
template <> struct __declspec(uuid("860c0179-be01-546d-a9ce-5956464c98ab")) __declspec(novtable) IAsyncOperation<winrt::Windows::Media::ContentRestrictions::ContentAccessRestrictionLevel> : impl_IAsyncOperation<winrt::Windows::Media::ContentRestrictions::ContentAccessRestrictionLevel> {};
#endif

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

#ifndef WINRT_GENERIC_72ae1a16_c705_54e7_b1c4_fc05a0e07a77
#define WINRT_GENERIC_72ae1a16_c705_54e7_b1c4_fc05a0e07a77
template <> struct __declspec(uuid("72ae1a16-c705-54e7-b1c4-fc05a0e07a77")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy> : impl_AsyncOperationCompletedHandler<Windows::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy> {};
#endif

#ifndef WINRT_GENERIC_cf61be5d_40c3_5484_846a_3f82b8ba5738
#define WINRT_GENERIC_cf61be5d_40c3_5484_846a_3f82b8ba5738
template <> struct __declspec(uuid("cf61be5d-40c3-5484-846a-3f82b8ba5738")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::Media::ContentRestrictions::ContentAccessRestrictionLevel> : impl_AsyncOperationCompletedHandler<winrt::Windows::Media::ContentRestrictions::ContentAccessRestrictionLevel> {};
#endif


}

namespace Windows::Media::ContentRestrictions {

struct IContentRestrictionsBrowsePolicy :
    Windows::Foundation::IInspectable,
    impl::consume<IContentRestrictionsBrowsePolicy>
{
    IContentRestrictionsBrowsePolicy(std::nullptr_t = nullptr) noexcept {}
};

struct IRatedContentDescription :
    Windows::Foundation::IInspectable,
    impl::consume<IRatedContentDescription>
{
    IRatedContentDescription(std::nullptr_t = nullptr) noexcept {}
};

struct IRatedContentDescriptionFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IRatedContentDescriptionFactory>
{
    IRatedContentDescriptionFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IRatedContentRestrictions :
    Windows::Foundation::IInspectable,
    impl::consume<IRatedContentRestrictions>
{
    IRatedContentRestrictions(std::nullptr_t = nullptr) noexcept {}
};

struct IRatedContentRestrictionsFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IRatedContentRestrictionsFactory>
{
    IRatedContentRestrictionsFactory(std::nullptr_t = nullptr) noexcept {}
};

}

}
