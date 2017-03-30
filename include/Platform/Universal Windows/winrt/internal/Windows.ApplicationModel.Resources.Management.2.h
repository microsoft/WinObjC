// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.Resources.Management.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_60310303_49c5_52e6_abc6_a9b36eccc716
#define WINRT_GENERIC_60310303_49c5_52e6_abc6_a9b36eccc716
template <> struct __declspec(uuid("60310303-49c5-52e6-abc6-a9b36eccc716")) __declspec(novtable) IKeyValuePair<hstring, hstring> : impl_IKeyValuePair<hstring, hstring> {};
#endif

#ifndef WINRT_GENERIC_ac7f26f2_feb7_5b2a_8ac4_345bc62caede
#define WINRT_GENERIC_ac7f26f2_feb7_5b2a_8ac4_345bc62caede
template <> struct __declspec(uuid("ac7f26f2-feb7-5b2a-8ac4-345bc62caede")) __declspec(novtable) IMapView<hstring, hstring> : impl_IMapView<hstring, hstring> {};
#endif

#ifndef WINRT_GENERIC_1da243f1_bb95_543e_95c6_5fd196b34b6f
#define WINRT_GENERIC_1da243f1_bb95_543e_95c6_5fd196b34b6f
template <> struct __declspec(uuid("1da243f1-bb95-543e-95c6-5fd196b34b6f")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate> : impl_IVectorView<Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate> {};
#endif

#ifndef WINRT_GENERIC_239ded48_ce04_51f2_b2c9_a5e5ab671b8d
#define WINRT_GENERIC_239ded48_ce04_51f2_b2c9_a5e5ab671b8d
template <> struct __declspec(uuid("239ded48-ce04-51f2-b2c9-a5e5ab671b8d")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Resources::Management::IndexedResourceQualifier> : impl_IVectorView<Windows::ApplicationModel::Resources::Management::IndexedResourceQualifier> {};
#endif

#ifndef WINRT_GENERIC_6b6f3ab9_1593_5852_b6bb_17a217e12f9f
#define WINRT_GENERIC_6b6f3ab9_1593_5852_b6bb_17a217e12f9f
template <> struct __declspec(uuid("6b6f3ab9-1593-5852-b6bb-17a217e12f9f")) __declspec(novtable) IIterator<Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate> : impl_IIterator<Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate> {};
#endif

#ifndef WINRT_GENERIC_0fcb4184_1489_5774_9910_bab326bb50f6
#define WINRT_GENERIC_0fcb4184_1489_5774_9910_bab326bb50f6
template <> struct __declspec(uuid("0fcb4184-1489-5774-9910-bab326bb50f6")) __declspec(novtable) IIterable<Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate> : impl_IIterable<Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate> {};
#endif

#ifndef WINRT_GENERIC_1a22ebee_7992_5198_972b_054580945741
#define WINRT_GENERIC_1a22ebee_7992_5198_972b_054580945741
template <> struct __declspec(uuid("1a22ebee-7992-5198-972b-054580945741")) __declspec(novtable) IIterator<Windows::ApplicationModel::Resources::Management::IndexedResourceQualifier> : impl_IIterator<Windows::ApplicationModel::Resources::Management::IndexedResourceQualifier> {};
#endif

#ifndef WINRT_GENERIC_e16e0455_7341_55c0_a024_26d9ad43c8cc
#define WINRT_GENERIC_e16e0455_7341_55c0_a024_26d9ad43c8cc
template <> struct __declspec(uuid("e16e0455-7341-55c0-a024-26d9ad43c8cc")) __declspec(novtable) IIterable<Windows::ApplicationModel::Resources::Management::IndexedResourceQualifier> : impl_IIterable<Windows::ApplicationModel::Resources::Management::IndexedResourceQualifier> {};
#endif

#ifndef WINRT_GENERIC_e9bdaaf0_cbf6_5c72_be90_29cbf3a1319b
#define WINRT_GENERIC_e9bdaaf0_cbf6_5c72_be90_29cbf3a1319b
template <> struct __declspec(uuid("e9bdaaf0-cbf6-5c72-be90-29cbf3a1319b")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_d2d41b8a_6616_5de8_aaf9_32ae51f67fcb
#define WINRT_GENERIC_d2d41b8a_6616_5de8_aaf9_32ae51f67fcb
template <> struct __declspec(uuid("d2d41b8a-6616-5de8-aaf9-32ae51f67fcb")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate>> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_05eb86f1_7140_5517_b88d_cbaebe57e6b1
#define WINRT_GENERIC_05eb86f1_7140_5517_b88d_cbaebe57e6b1
template <> struct __declspec(uuid("05eb86f1-7140-5517-b88d-cbaebe57e6b1")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, hstring>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_4f2b3869_d059_5739_906c_9eb2729c2fde
#define WINRT_GENERIC_4f2b3869_d059_5739_906c_9eb2729c2fde
template <> struct __declspec(uuid("4f2b3869-d059-5739-906c-9eb2729c2fde")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Resources::Management::IndexedResourceCandidate>> {};
#endif


}

namespace Windows::ApplicationModel::Resources::Management {

struct IIndexedResourceCandidate :
    Windows::Foundation::IInspectable,
    impl::consume<IIndexedResourceCandidate>
{
    IIndexedResourceCandidate(std::nullptr_t = nullptr) noexcept {}
};

struct IIndexedResourceQualifier :
    Windows::Foundation::IInspectable,
    impl::consume<IIndexedResourceQualifier>
{
    IIndexedResourceQualifier(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceIndexer :
    Windows::Foundation::IInspectable,
    impl::consume<IResourceIndexer>
{
    IResourceIndexer(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceIndexerFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IResourceIndexerFactory>
{
    IResourceIndexerFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IResourceIndexerFactory2 :
    Windows::Foundation::IInspectable,
    impl::consume<IResourceIndexerFactory2>
{
    IResourceIndexerFactory2(std::nullptr_t = nullptr) noexcept {}
};

}

}
