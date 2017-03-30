// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.PersonalInformation.Provisioning.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
#define WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
template <> struct __declspec(uuid("09335560-6c6b-5a26-9348-97b781132b20")) __declspec(novtable) IKeyValuePair<hstring, Windows::Foundation::IInspectable> : impl_IKeyValuePair<hstring, Windows::Foundation::IInspectable> {};
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

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
#define WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
template <> struct __declspec(uuid("fe2f3d47-5d47-5499-8374-430c7cda0204")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif

#ifndef WINRT_GENERIC_172a655b_b3b8_5eae_bc2e_a6a1f1708b4b
#define WINRT_GENERIC_172a655b_b3b8_5eae_bc2e_a6a1f1708b4b
template <> struct __declspec(uuid("172a655b-b3b8-5eae-bc2e-a6a1f1708b4b")) __declspec(novtable) IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> : impl_IVectorView<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> {};
#endif

#ifndef WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
#define WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
template <> struct __declspec(uuid("5db5fa32-707c-5849-a06b-91c8eb9d10e8")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif

#ifndef WINRT_GENERIC_53a2e825_9bf1_5083_8a7b_9d94f312dade
#define WINRT_GENERIC_53a2e825_9bf1_5083_8a7b_9d94f312dade
template <> struct __declspec(uuid("53a2e825-9bf1-5083-8a7b-9d94f312dade")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> : impl_IIterator<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> {};
#endif

#ifndef WINRT_GENERIC_e1670fae_49cd_5c47_a8c8_f6fa2c650c6c
#define WINRT_GENERIC_e1670fae_49cd_5c47_a8c8_f6fa2c650c6c
template <> struct __declspec(uuid("e1670fae-49cd-5c47-a8c8-f6fa2c650c6c")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> : impl_IIterable<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace Windows::Phone::PersonalInformation::Provisioning {

struct IContactPartnerProvisioningManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IContactPartnerProvisioningManagerStatics>
{
    IContactPartnerProvisioningManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IContactPartnerProvisioningManagerStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IContactPartnerProvisioningManagerStatics2>
{
    IContactPartnerProvisioningManagerStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IMessagePartnerProvisioningManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IMessagePartnerProvisioningManagerStatics>
{
    IMessagePartnerProvisioningManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
