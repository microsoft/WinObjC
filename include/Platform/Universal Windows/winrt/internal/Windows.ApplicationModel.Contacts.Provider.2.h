// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Contacts.Provider.1.h"

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

#ifndef WINRT_GENERIC_6fdc2115_1649_54a4_8faa_3049cefb05a4
#define WINRT_GENERIC_6fdc2115_1649_54a4_8faa_3049cefb05a4
template <> struct __declspec(uuid("6fdc2115-1649-54a4-8faa-3049cefb05a4")) __declspec(novtable) IVector<winrt::Windows::ApplicationModel::Contacts::ContactFieldType> : impl_IVector<winrt::Windows::ApplicationModel::Contacts::ContactFieldType> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_a39aeb7e_765c_5e83_b231_84bead98e9a0
#define WINRT_GENERIC_a39aeb7e_765c_5e83_b231_84bead98e9a0
template <> struct __declspec(uuid("a39aeb7e-765c-5e83-b231-84bead98e9a0")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::Contacts::Provider::ContactPickerUI, Windows::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::Contacts::Provider::ContactPickerUI, Windows::ApplicationModel::Contacts::Provider::ContactRemovedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_2f6d856a_50d4_5173_abea_db6c6b8fc530
#define WINRT_GENERIC_2f6d856a_50d4_5173_abea_db6c6b8fc530
template <> struct __declspec(uuid("2f6d856a-50d4-5173-abea-db6c6b8fc530")) __declspec(novtable) IIterator<winrt::Windows::ApplicationModel::Contacts::ContactFieldType> : impl_IIterator<winrt::Windows::ApplicationModel::Contacts::ContactFieldType> {};
#endif

#ifndef WINRT_GENERIC_384b8b1b_ce8e_5781_b3dc_0776d684f658
#define WINRT_GENERIC_384b8b1b_ce8e_5781_b3dc_0776d684f658
template <> struct __declspec(uuid("384b8b1b-ce8e-5781-b3dc-0776d684f658")) __declspec(novtable) IIterable<winrt::Windows::ApplicationModel::Contacts::ContactFieldType> : impl_IIterable<winrt::Windows::ApplicationModel::Contacts::ContactFieldType> {};
#endif

#ifndef WINRT_GENERIC_39d6abda_a00a_5777_8611_82d7c326c18d
#define WINRT_GENERIC_39d6abda_a00a_5777_8611_82d7c326c18d
template <> struct __declspec(uuid("39d6abda-a00a-5777-8611-82d7c326c18d")) __declspec(novtable) IVectorView<winrt::Windows::ApplicationModel::Contacts::ContactFieldType> : impl_IVectorView<winrt::Windows::ApplicationModel::Contacts::ContactFieldType> {};
#endif


}

namespace Windows::ApplicationModel::Contacts::Provider {

struct IContactPickerUI :
    Windows::Foundation::IInspectable,
    impl::consume<IContactPickerUI>
{
    IContactPickerUI(std::nullptr_t = nullptr) noexcept {}
};

struct IContactPickerUI2 :
    Windows::Foundation::IInspectable,
    impl::consume<IContactPickerUI2>
{
    IContactPickerUI2(std::nullptr_t = nullptr) noexcept {}
};

struct IContactRemovedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IContactRemovedEventArgs>
{
    IContactRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

}

}
