// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.SocialInfo.Provider.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_36cd5297_36c3_56a7_9656_ec9d5bde7aba
#define WINRT_GENERIC_36cd5297_36c3_56a7_9656_ec9d5bde7aba
template <> struct __declspec(uuid("36cd5297-36c3-56a7-9656-ec9d5bde7aba")) __declspec(novtable) IVector<Windows::ApplicationModel::SocialInfo::SocialFeedItem> : impl_IVector<Windows::ApplicationModel::SocialInfo::SocialFeedItem> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_4efa4da9_c556_59f4_9d99_e7801c5b0f45
#define WINRT_GENERIC_4efa4da9_c556_59f4_9d99_e7801c5b0f45
template <> struct __declspec(uuid("4efa4da9-c556-59f4-9d99-e7801c5b0f45")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater> : impl_IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater> {};
#endif

#ifndef WINRT_GENERIC_8bbca9a4_a4fc_5fe2_b6b1_0e5a75d05b07
#define WINRT_GENERIC_8bbca9a4_a4fc_5fe2_b6b1_0e5a75d05b07
template <> struct __declspec(uuid("8bbca9a4-a4fc-5fe2-b6b1-0e5a75d05b07")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater> : impl_IAsyncOperation<Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater> {};
#endif

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_e7c8cd1f_3907_5da8_9d72_90426dc37072
#define WINRT_GENERIC_e7c8cd1f_3907_5da8_9d72_90426dc37072
template <> struct __declspec(uuid("e7c8cd1f-3907-5da8-9d72-90426dc37072")) __declspec(novtable) IIterator<Windows::ApplicationModel::SocialInfo::SocialFeedItem> : impl_IIterator<Windows::ApplicationModel::SocialInfo::SocialFeedItem> {};
#endif

#ifndef WINRT_GENERIC_ad33d864_9569_5e2d_bd72_182a8ff50cf6
#define WINRT_GENERIC_ad33d864_9569_5e2d_bd72_182a8ff50cf6
template <> struct __declspec(uuid("ad33d864-9569-5e2d-bd72-182a8ff50cf6")) __declspec(novtable) IIterable<Windows::ApplicationModel::SocialInfo::SocialFeedItem> : impl_IIterable<Windows::ApplicationModel::SocialInfo::SocialFeedItem> {};
#endif

#ifndef WINRT_GENERIC_e6be2bb8_fc75_585c_836c_34f3ff87680f
#define WINRT_GENERIC_e6be2bb8_fc75_585c_836c_34f3ff87680f
template <> struct __declspec(uuid("e6be2bb8-fc75-585c-836c-34f3ff87680f")) __declspec(novtable) IVectorView<Windows::ApplicationModel::SocialInfo::SocialFeedItem> : impl_IVectorView<Windows::ApplicationModel::SocialInfo::SocialFeedItem> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_0b227474_80c0_5f33_9ff9_234403abd6fa
#define WINRT_GENERIC_0b227474_80c0_5f33_9ff9_234403abd6fa
template <> struct __declspec(uuid("0b227474-80c0-5f33-9ff9-234403abd6fa")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater> {};
#endif

#ifndef WINRT_GENERIC_33cfd9aa_6c3c_50df_bbc8_34c22a0e5b6b
#define WINRT_GENERIC_33cfd9aa_6c3c_50df_bbc8_34c22a0e5b6b
template <> struct __declspec(uuid("33cfd9aa-6c3c-50df-bbc8-34c22a0e5b6b")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater> {};
#endif

#ifndef WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
#define WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
template <> struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a")) __declspec(novtable) AsyncOperationCompletedHandler<bool> : impl_AsyncOperationCompletedHandler<bool> {};
#endif


}

namespace Windows::ApplicationModel::SocialInfo::Provider {

struct ISocialDashboardItemUpdater :
    Windows::Foundation::IInspectable,
    impl::consume<ISocialDashboardItemUpdater>
{
    ISocialDashboardItemUpdater(std::nullptr_t = nullptr) noexcept {}
};

struct ISocialFeedUpdater :
    Windows::Foundation::IInspectable,
    impl::consume<ISocialFeedUpdater>
{
    ISocialFeedUpdater(std::nullptr_t = nullptr) noexcept {}
};

struct ISocialInfoProviderManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISocialInfoProviderManagerStatics>
{
    ISocialInfoProviderManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
