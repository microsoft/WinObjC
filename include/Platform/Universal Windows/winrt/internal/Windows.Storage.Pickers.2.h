// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.Pickers.1.h"

WINRT_EXPORT namespace winrt {

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

#ifndef WINRT_GENERIC_6be9e7d7_e83a_5cbc_802c_1768960b52c3
#define WINRT_GENERIC_6be9e7d7_e83a_5cbc_802c_1768960b52c3
template <> struct __declspec(uuid("6be9e7d7-e83a-5cbc-802c-1768960b52c3")) __declspec(novtable) IAsyncOperation<Windows::Storage::StorageFolder> : impl_IAsyncOperation<Windows::Storage::StorageFolder> {};
#endif

#ifndef WINRT_GENERIC_5e52f8ce_aced_5a42_95b4_f674dd84885e
#define WINRT_GENERIC_5e52f8ce_aced_5a42_95b4_f674dd84885e
template <> struct __declspec(uuid("5e52f8ce-aced-5a42-95b4-f674dd84885e")) __declspec(novtable) IAsyncOperation<Windows::Storage::StorageFile> : impl_IAsyncOperation<Windows::Storage::StorageFile> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_80646519_5e2a_595d_a8cd_2a24b4067f1b
#define WINRT_GENERIC_80646519_5e2a_595d_a8cd_2a24b4067f1b
template <> struct __declspec(uuid("80646519-5e2a-595d-a8cd-2a24b4067f1b")) __declspec(novtable) IVectorView<Windows::Storage::StorageFile> : impl_IVectorView<Windows::Storage::StorageFile> {};
#endif

#ifndef WINRT_GENERIC_9ac00304_83ea_5688_87b6_ae38aab65d0b
#define WINRT_GENERIC_9ac00304_83ea_5688_87b6_ae38aab65d0b
template <> struct __declspec(uuid("9ac00304-83ea-5688-87b6-ae38aab65d0b")) __declspec(novtable) IIterable<Windows::Storage::StorageFile> : impl_IIterable<Windows::Storage::StorageFile> {};
#endif

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c211026e_9e63_5452_ba54_3a07d6a96874
#define WINRT_GENERIC_c211026e_9e63_5452_ba54_3a07d6a96874
template <> struct __declspec(uuid("c211026e-9e63-5452-ba54-3a07d6a96874")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::StorageFolder> : impl_AsyncOperationCompletedHandler<Windows::Storage::StorageFolder> {};
#endif

#ifndef WINRT_GENERIC_e521c894_2c26_5946_9e61_2b5e188d01ed
#define WINRT_GENERIC_e521c894_2c26_5946_9e61_2b5e188d01ed
template <> struct __declspec(uuid("e521c894-2c26-5946-9e61-2b5e188d01ed")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::StorageFile> : impl_AsyncOperationCompletedHandler<Windows::Storage::StorageFile> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_43e29f53_0298_55aa_a6c8_4edd323d9598
#define WINRT_GENERIC_43e29f53_0298_55aa_a6c8_4edd323d9598
template <> struct __declspec(uuid("43e29f53-0298-55aa-a6c8-4edd323d9598")) __declspec(novtable) IIterator<Windows::Storage::StorageFile> : impl_IIterator<Windows::Storage::StorageFile> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_03362e33_e413_5f29_97d0_48a4780935f9
#define WINRT_GENERIC_03362e33_e413_5f29_97d0_48a4780935f9
template <> struct __declspec(uuid("03362e33-e413-5f29-97d0-48a4780935f9")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_e475ca9d_6afb_5992_993e_53e6ef7a9ecd
#define WINRT_GENERIC_e475ca9d_6afb_5992_993e_53e6ef7a9ecd
template <> struct __declspec(uuid("e475ca9d-6afb-5992-993e-53e6ef7a9ecd")) __declspec(novtable) IMap<hstring, Windows::Foundation::Collections::IVector<hstring>> : impl_IMap<hstring, Windows::Foundation::Collections::IVector<hstring>> {};
#endif

#ifndef WINRT_GENERIC_174f26c7_79ea_5f7c_bd70_ac4457f2cac8
#define WINRT_GENERIC_174f26c7_79ea_5f7c_bd70_ac4457f2cac8
template <> struct __declspec(uuid("174f26c7-79ea-5f7c-bd70-ac4457f2cac8")) __declspec(novtable) IKeyValuePair<hstring, Windows::Foundation::Collections::IVector<hstring>> : impl_IKeyValuePair<hstring, Windows::Foundation::Collections::IVector<hstring>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cb4206c5_0988_5104_afa9_253c298f86fd
#define WINRT_GENERIC_cb4206c5_0988_5104_afa9_253c298f86fd
template <> struct __declspec(uuid("cb4206c5-0988-5104-afa9-253c298f86fd")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Storage::StorageFile>> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_153f9c9c_d22a_5c9e_9c74_8b85c908b000
#define WINRT_GENERIC_153f9c9c_d22a_5c9e_9c74_8b85c908b000
template <> struct __declspec(uuid("153f9c9c-d22a-5c9e-9c74-8b85c908b000")) __declspec(novtable) IMapView<hstring, Windows::Foundation::Collections::IVector<hstring>> : impl_IMapView<hstring, Windows::Foundation::Collections::IVector<hstring>> {};
#endif

#ifndef WINRT_GENERIC_4fed2669_d0d3_59f6_91d9_95902d728d6a
#define WINRT_GENERIC_4fed2669_d0d3_59f6_91d9_95902d728d6a
template <> struct __declspec(uuid("4fed2669-d0d3-59f6-91d9-95902d728d6a")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::Collections::IVector<hstring>>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::Collections::IVector<hstring>>> {};
#endif

#ifndef WINRT_GENERIC_a11824c9_e458_502a_afd8_ce3ce0abd6fe
#define WINRT_GENERIC_a11824c9_e458_502a_afd8_ce3ce0abd6fe
template <> struct __declspec(uuid("a11824c9-e458-502a-afd8-ce3ce0abd6fe")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::Collections::IVector<hstring>>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::Collections::IVector<hstring>>> {};
#endif


}

namespace Windows::Storage::Pickers {

struct IFileOpenPicker :
    Windows::Foundation::IInspectable,
    impl::consume<IFileOpenPicker>
{
    IFileOpenPicker(std::nullptr_t = nullptr) noexcept {}
};

struct IFileOpenPicker2 :
    Windows::Foundation::IInspectable,
    impl::consume<IFileOpenPicker2>,
    impl::require<IFileOpenPicker2, Windows::Storage::Pickers::IFileOpenPicker>
{
    IFileOpenPicker2(std::nullptr_t = nullptr) noexcept {}
};

struct IFileOpenPickerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IFileOpenPickerStatics>
{
    IFileOpenPickerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IFileOpenPickerWithOperationId :
    Windows::Foundation::IInspectable,
    impl::consume<IFileOpenPickerWithOperationId>
{
    IFileOpenPickerWithOperationId(std::nullptr_t = nullptr) noexcept {}
};

struct IFileSavePicker :
    Windows::Foundation::IInspectable,
    impl::consume<IFileSavePicker>
{
    IFileSavePicker(std::nullptr_t = nullptr) noexcept {}
};

struct IFileSavePicker2 :
    Windows::Foundation::IInspectable,
    impl::consume<IFileSavePicker2>,
    impl::require<IFileSavePicker2, Windows::Storage::Pickers::IFileSavePicker>
{
    IFileSavePicker2(std::nullptr_t = nullptr) noexcept {}
};

struct IFileSavePicker3 :
    Windows::Foundation::IInspectable,
    impl::consume<IFileSavePicker3>,
    impl::require<IFileSavePicker3, Windows::Storage::Pickers::IFileSavePicker>
{
    IFileSavePicker3(std::nullptr_t = nullptr) noexcept {}
};

struct IFolderPicker :
    Windows::Foundation::IInspectable,
    impl::consume<IFolderPicker>
{
    IFolderPicker(std::nullptr_t = nullptr) noexcept {}
};

struct IFolderPicker2 :
    Windows::Foundation::IInspectable,
    impl::consume<IFolderPicker2>,
    impl::require<IFolderPicker2, Windows::Storage::Pickers::IFolderPicker>
{
    IFolderPicker2(std::nullptr_t = nullptr) noexcept {}
};

}

}
