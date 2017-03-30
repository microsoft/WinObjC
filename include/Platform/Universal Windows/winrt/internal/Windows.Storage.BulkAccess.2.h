// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.BulkAccess.1.h"
#include "Windows.Storage.1.h"
#include "Windows.Storage.Search.1.h"
#include "Windows.Storage.Streams.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5b98b352_e0cf_58de_b2ec_4fd786bbb5a7
#define WINRT_GENERIC_5b98b352_e0cf_58de_b2ec_4fd786bbb5a7
template <> struct __declspec(uuid("5b98b352-e0cf-58de-b2ec-4fd786bbb5a7")) __declspec(novtable) TypedEventHandler<Windows::Storage::BulkAccess::IStorageItemInformation, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Storage::BulkAccess::IStorageItemInformation, Windows::Foundation::IInspectable> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_da3a4ef8_d315_529b_a73b_524490573f7e
#define WINRT_GENERIC_da3a4ef8_d315_529b_a73b_524490573f7e
template <> struct __declspec(uuid("da3a4ef8-d315-529b-a73b-524490573f7e")) __declspec(novtable) IVectorView<Windows::Storage::BulkAccess::IStorageItemInformation> : impl_IVectorView<Windows::Storage::BulkAccess::IStorageItemInformation> {};
#endif

#ifndef WINRT_GENERIC_50bcd975_67ba_53b7_a5a7_1fb59f04bbb3
#define WINRT_GENERIC_50bcd975_67ba_53b7_a5a7_1fb59f04bbb3
template <> struct __declspec(uuid("50bcd975-67ba-53b7-a5a7-1fb59f04bbb3")) __declspec(novtable) IVectorView<Windows::Storage::BulkAccess::FileInformation> : impl_IVectorView<Windows::Storage::BulkAccess::FileInformation> {};
#endif

#ifndef WINRT_GENERIC_506f1329_dbdc_5a37_91d5_b047cb24276d
#define WINRT_GENERIC_506f1329_dbdc_5a37_91d5_b047cb24276d
template <> struct __declspec(uuid("506f1329-dbdc-5a37-91d5-b047cb24276d")) __declspec(novtable) IVectorView<Windows::Storage::BulkAccess::FolderInformation> : impl_IVectorView<Windows::Storage::BulkAccess::FolderInformation> {};
#endif

#ifndef WINRT_GENERIC_3da6401d_1279_55a1_962c_25cd23b99b27
#define WINRT_GENERIC_3da6401d_1279_55a1_962c_25cd23b99b27
template <> struct __declspec(uuid("3da6401d-1279-55a1-962c-25cd23b99b27")) __declspec(novtable) IIterator<Windows::Storage::BulkAccess::IStorageItemInformation> : impl_IIterator<Windows::Storage::BulkAccess::IStorageItemInformation> {};
#endif

#ifndef WINRT_GENERIC_43bc252e_a3d6_5f00_a12c_b088d3b912d4
#define WINRT_GENERIC_43bc252e_a3d6_5f00_a12c_b088d3b912d4
template <> struct __declspec(uuid("43bc252e-a3d6-5f00-a12c-b088d3b912d4")) __declspec(novtable) IIterable<Windows::Storage::BulkAccess::IStorageItemInformation> : impl_IIterable<Windows::Storage::BulkAccess::IStorageItemInformation> {};
#endif

#ifndef WINRT_GENERIC_bf2f6543_230e_50bf_9c57_9e4ba8635903
#define WINRT_GENERIC_bf2f6543_230e_50bf_9c57_9e4ba8635903
template <> struct __declspec(uuid("bf2f6543-230e-50bf-9c57-9e4ba8635903")) __declspec(novtable) IIterator<Windows::Storage::BulkAccess::FileInformation> : impl_IIterator<Windows::Storage::BulkAccess::FileInformation> {};
#endif

#ifndef WINRT_GENERIC_dd96d7e9_892b_5932_b677_5bc32588008f
#define WINRT_GENERIC_dd96d7e9_892b_5932_b677_5bc32588008f
template <> struct __declspec(uuid("dd96d7e9-892b-5932-b677-5bc32588008f")) __declspec(novtable) IIterable<Windows::Storage::BulkAccess::FileInformation> : impl_IIterable<Windows::Storage::BulkAccess::FileInformation> {};
#endif

#ifndef WINRT_GENERIC_ff68b5b6_caad_553a_9808_95eea700c9de
#define WINRT_GENERIC_ff68b5b6_caad_553a_9808_95eea700c9de
template <> struct __declspec(uuid("ff68b5b6-caad-553a-9808-95eea700c9de")) __declspec(novtable) IIterator<Windows::Storage::BulkAccess::FolderInformation> : impl_IIterator<Windows::Storage::BulkAccess::FolderInformation> {};
#endif

#ifndef WINRT_GENERIC_5c720bf5_7636_51fd_9ef7_d5f57f071a9b
#define WINRT_GENERIC_5c720bf5_7636_51fd_9ef7_d5f57f071a9b
template <> struct __declspec(uuid("5c720bf5-7636-51fd-9ef7-d5f57f071a9b")) __declspec(novtable) IIterable<Windows::Storage::BulkAccess::FolderInformation> : impl_IIterable<Windows::Storage::BulkAccess::FolderInformation> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_413d160c_3e1a_5603_acba_1e176d6a6082
#define WINRT_GENERIC_413d160c_3e1a_5603_acba_1e176d6a6082
template <> struct __declspec(uuid("413d160c-3e1a-5603-acba-1e176d6a6082")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::IStorageItemInformation>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::IStorageItemInformation>> {};
#endif

#ifndef WINRT_GENERIC_222f6bb6_e71e_55cb_885d_e051e35995dc
#define WINRT_GENERIC_222f6bb6_e71e_55cb_885d_e051e35995dc
template <> struct __declspec(uuid("222f6bb6-e71e-55cb-885d-e051e35995dc")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::FileInformation>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::FileInformation>> {};
#endif

#ifndef WINRT_GENERIC_7f10e569_2bf7_5752_8f75_602809a7d304
#define WINRT_GENERIC_7f10e569_2bf7_5752_8f75_602809a7d304
template <> struct __declspec(uuid("7f10e569-2bf7-5752-8f75-602809a7d304")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::FolderInformation>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::FolderInformation>> {};
#endif

#ifndef WINRT_GENERIC_ff163034_ece9_55be_a6f8_08c72aae56b4
#define WINRT_GENERIC_ff163034_ece9_55be_a6f8_08c72aae56b4
template <> struct __declspec(uuid("ff163034-ece9-55be-a6f8-08c72aae56b4")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::IStorageItemInformation>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::IStorageItemInformation>> {};
#endif

#ifndef WINRT_GENERIC_ebdb2c85_d27a_5c93_a1b3_6ca3651ada5d
#define WINRT_GENERIC_ebdb2c85_d27a_5c93_a1b3_6ca3651ada5d
template <> struct __declspec(uuid("ebdb2c85-d27a-5c93-a1b3-6ca3651ada5d")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::FileInformation>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::FileInformation>> {};
#endif

#ifndef WINRT_GENERIC_020713ec_604a_5e45_b03f_1b9e65253804
#define WINRT_GENERIC_020713ec_604a_5e45_b03f_1b9e65253804
template <> struct __declspec(uuid("020713ec-604a-5e45-b03f-1b9e65253804")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::FolderInformation>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Storage::BulkAccess::FolderInformation>> {};
#endif


}

namespace Windows::Storage::BulkAccess {

struct IFileInformationFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IFileInformationFactory>
{
    IFileInformationFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IFileInformationFactoryFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IFileInformationFactoryFactory>
{
    IFileInformationFactoryFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IStorageItemInformation :
    Windows::Foundation::IInspectable,
    impl::consume<IStorageItemInformation>
{
    IStorageItemInformation(std::nullptr_t = nullptr) noexcept {}
};

}

}
