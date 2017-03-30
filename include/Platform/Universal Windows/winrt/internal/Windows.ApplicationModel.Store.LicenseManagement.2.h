// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Store.LicenseManagement.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif

#ifndef WINRT_GENERIC_19df5e64_c2b2_5bfd_a259_f02c23574cd3
#define WINRT_GENERIC_19df5e64_c2b2_5bfd_a259_f02c23574cd3
template <> struct __declspec(uuid("19df5e64-c2b2-5bfd-a259-f02c23574cd3")) __declspec(novtable) IMapView<hstring, Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo> : impl_IMapView<hstring, Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_b8447bc9_a9f8_5867_8b30_cd34720edc31
#define WINRT_GENERIC_b8447bc9_a9f8_5867_8b30_cd34720edc31
template <> struct __declspec(uuid("b8447bc9-a9f8-5867-8b30-cd34720edc31")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult> : impl_IAsyncOperation<Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_69426b8f_88d8_5546_92ee_53f75307845b
#define WINRT_GENERIC_69426b8f_88d8_5546_92ee_53f75307845b
template <> struct __declspec(uuid("69426b8f-88d8-5546-92ee-53f75307845b")) __declspec(novtable) IKeyValuePair<hstring, Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo> : impl_IKeyValuePair<hstring, Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_936e8471_252f_5339_89c3_9428412086ca
#define WINRT_GENERIC_936e8471_252f_5339_89c3_9428412086ca
template <> struct __declspec(uuid("936e8471-252f-5339-89c3-9428412086ca")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionResult> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_168d4306_e80a_5e37_ae46_2ceecdd7fc9a
#define WINRT_GENERIC_168d4306_e80a_5e37_ae46_2ceecdd7fc9a
template <> struct __declspec(uuid("168d4306-e80a-5e37-ae46-2ceecdd7fc9a")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo>> {};
#endif

#ifndef WINRT_GENERIC_ac935021_e04b_5226_8119_5b73d0b8be5b
#define WINRT_GENERIC_ac935021_e04b_5226_8119_5b73d0b8be5b
template <> struct __declspec(uuid("ac935021-e04b-5226-8119-5b73d0b8be5b")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::ApplicationModel::Store::LicenseManagement::LicenseSatisfactionInfo>> {};
#endif


}

namespace Windows::ApplicationModel::Store::LicenseManagement {

struct ILicenseManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ILicenseManagerStatics>
{
    ILicenseManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ILicenseSatisfactionInfo :
    Windows::Foundation::IInspectable,
    impl::consume<ILicenseSatisfactionInfo>
{
    ILicenseSatisfactionInfo(std::nullptr_t = nullptr) noexcept {}
};

struct ILicenseSatisfactionResult :
    Windows::Foundation::IInspectable,
    impl::consume<ILicenseSatisfactionResult>
{
    ILicenseSatisfactionResult(std::nullptr_t = nullptr) noexcept {}
};

}

}
