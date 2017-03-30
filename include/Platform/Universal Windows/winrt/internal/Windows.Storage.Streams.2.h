// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.Streams.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif

#ifndef WINRT_GENERIC_c4a57c5e_32b0_55b3_ad13_ce1c23041ed6
#define WINRT_GENERIC_c4a57c5e_32b0_55b3_ad13_ce1c23041ed6
template <> struct __declspec(uuid("c4a57c5e-32b0-55b3-ad13-ce1c23041ed6")) __declspec(novtable) IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> : impl_IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> {};
#endif

#ifndef WINRT_GENERIC_ef60385f_be78_584b_aaef_7829ada2b0de
#define WINRT_GENERIC_ef60385f_be78_584b_aaef_7829ada2b0de
template <> struct __declspec(uuid("ef60385f-be78-584b-aaef-7829ada2b0de")) __declspec(novtable) IAsyncOperation<uint32_t> : impl_IAsyncOperation<uint32_t> {};
#endif

#ifndef WINRT_GENERIC_8f1db6e3_6556_5516_825c_1021ee27cd0c
#define WINRT_GENERIC_8f1db6e3_6556_5516_825c_1021ee27cd0c
template <> struct __declspec(uuid("8f1db6e3-6556-5516-825c-1021ee27cd0c")) __declspec(novtable) IAsyncOperationWithProgress<uint64_t, uint64_t> : impl_IAsyncOperationWithProgress<uint64_t, uint64_t> {};
#endif

#ifndef WINRT_GENERIC_a8fe0732_556d_5841_b7ee_b3450fb52666
#define WINRT_GENERIC_a8fe0732_556d_5841_b7ee_b3450fb52666
template <> struct __declspec(uuid("a8fe0732-556d-5841-b7ee-b3450fb52666")) __declspec(novtable) IAsyncOperation<Windows::Storage::Streams::IInputStream> : impl_IAsyncOperation<Windows::Storage::Streams::IInputStream> {};
#endif

#ifndef WINRT_GENERIC_d26b2819_897f_5c7d_84d6_56d796561431
#define WINRT_GENERIC_d26b2819_897f_5c7d_84d6_56d796561431
template <> struct __declspec(uuid("d26b2819-897f-5c7d-84d6-56d796561431")) __declspec(novtable) IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer, uint32_t> : impl_IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer, uint32_t> {};
#endif

#ifndef WINRT_GENERIC_eccb574a_c684_5572_a679_6b0842cfb57f
#define WINRT_GENERIC_eccb574a_c684_5572_a679_6b0842cfb57f
template <> struct __declspec(uuid("eccb574a-c684-5572-a679-6b0842cfb57f")) __declspec(novtable) IAsyncOperationWithProgress<uint32_t, uint32_t> : impl_IAsyncOperationWithProgress<uint32_t, uint32_t> {};
#endif

#ifndef WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
#define WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
template <> struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a")) __declspec(novtable) AsyncOperationCompletedHandler<bool> : impl_AsyncOperationCompletedHandler<bool> {};
#endif

#ifndef WINRT_GENERIC_3dddecf4_1d39_58e8_83b1_dbed541c7f35
#define WINRT_GENERIC_3dddecf4_1d39_58e8_83b1_dbed541c7f35
template <> struct __declspec(uuid("3dddecf4-1d39-58e8-83b1-dbed541c7f35")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::Streams::IRandomAccessStreamWithContentType> : impl_AsyncOperationCompletedHandler<Windows::Storage::Streams::IRandomAccessStreamWithContentType> {};
#endif

#ifndef WINRT_GENERIC_9343b6e7_e3d2_5e4a_ab2d_2bce4919a6a4
#define WINRT_GENERIC_9343b6e7_e3d2_5e4a_ab2d_2bce4919a6a4
template <> struct __declspec(uuid("9343b6e7-e3d2-5e4a-ab2d-2bce4919a6a4")) __declspec(novtable) AsyncOperationCompletedHandler<uint32_t> : impl_AsyncOperationCompletedHandler<uint32_t> {};
#endif

#ifndef WINRT_GENERIC_ffb2b65d_4120_5d13_826d_107851e6bb1c
#define WINRT_GENERIC_ffb2b65d_4120_5d13_826d_107851e6bb1c
template <> struct __declspec(uuid("ffb2b65d-4120-5d13-826d-107851e6bb1c")) __declspec(novtable) AsyncOperationProgressHandler<uint64_t, uint64_t> : impl_AsyncOperationProgressHandler<uint64_t, uint64_t> {};
#endif

#ifndef WINRT_GENERIC_d2024e41_5500_5b5a_ba46_cb7009596a2f
#define WINRT_GENERIC_d2024e41_5500_5b5a_ba46_cb7009596a2f
template <> struct __declspec(uuid("d2024e41-5500-5b5a-ba46-cb7009596a2f")) __declspec(novtable) AsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t> : impl_AsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t> {};
#endif

#ifndef WINRT_GENERIC_d0bd0125_9049_57a3_bd66_e2525d98c814
#define WINRT_GENERIC_d0bd0125_9049_57a3_bd66_e2525d98c814
template <> struct __declspec(uuid("d0bd0125-9049-57a3-bd66-e2525d98c814")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Storage::Streams::IInputStream> : impl_AsyncOperationCompletedHandler<Windows::Storage::Streams::IInputStream> {};
#endif

#ifndef WINRT_GENERIC_bf666554_7605_5d9a_b14e_18d8c8472afe
#define WINRT_GENERIC_bf666554_7605_5d9a_b14e_18d8c8472afe
template <> struct __declspec(uuid("bf666554-7605-5d9a-b14e-18d8c8472afe")) __declspec(novtable) AsyncOperationProgressHandler<Windows::Storage::Streams::IBuffer, uint32_t> : impl_AsyncOperationProgressHandler<Windows::Storage::Streams::IBuffer, uint32_t> {};
#endif

#ifndef WINRT_GENERIC_06386a7a_e009_5b0b_ab68_a8e48b516647
#define WINRT_GENERIC_06386a7a_e009_5b0b_ab68_a8e48b516647
template <> struct __declspec(uuid("06386a7a-e009-5b0b-ab68-a8e48b516647")) __declspec(novtable) AsyncOperationWithProgressCompletedHandler<Windows::Storage::Streams::IBuffer, uint32_t> : impl_AsyncOperationWithProgressCompletedHandler<Windows::Storage::Streams::IBuffer, uint32_t> {};
#endif

#ifndef WINRT_GENERIC_ea0fe405_d432_5ac7_9ef8_5a65e1f97d7e
#define WINRT_GENERIC_ea0fe405_d432_5ac7_9ef8_5a65e1f97d7e
template <> struct __declspec(uuid("ea0fe405-d432-5ac7-9ef8-5a65e1f97d7e")) __declspec(novtable) AsyncOperationProgressHandler<uint32_t, uint32_t> : impl_AsyncOperationProgressHandler<uint32_t, uint32_t> {};
#endif

#ifndef WINRT_GENERIC_1e466dc5_840f_54f9_b877_5e3a9f4b6c74
#define WINRT_GENERIC_1e466dc5_840f_54f9_b877_5e3a9f4b6c74
template <> struct __declspec(uuid("1e466dc5-840f-54f9-b877-5e3a9f4b6c74")) __declspec(novtable) AsyncOperationWithProgressCompletedHandler<uint32_t, uint32_t> : impl_AsyncOperationWithProgressCompletedHandler<uint32_t, uint32_t> {};
#endif


}

namespace Windows::Storage::Streams {

struct IBuffer :
    Windows::Foundation::IInspectable,
    impl::consume<IBuffer>
{
    IBuffer(std::nullptr_t = nullptr) noexcept {}
};

struct IBufferFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IBufferFactory>
{
    IBufferFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IBufferStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IBufferStatics>
{
    IBufferStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IContentTypeProvider :
    Windows::Foundation::IInspectable,
    impl::consume<IContentTypeProvider>
{
    IContentTypeProvider(std::nullptr_t = nullptr) noexcept {}
};

struct IDataReader :
    Windows::Foundation::IInspectable,
    impl::consume<IDataReader>
{
    IDataReader(std::nullptr_t = nullptr) noexcept {}
};

struct IDataReaderFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IDataReaderFactory>
{
    IDataReaderFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IDataReaderStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IDataReaderStatics>
{
    IDataReaderStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IDataWriter :
    Windows::Foundation::IInspectable,
    impl::consume<IDataWriter>
{
    IDataWriter(std::nullptr_t = nullptr) noexcept {}
};

struct IDataWriterFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IDataWriterFactory>
{
    IDataWriterFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IInputStream :
    Windows::Foundation::IInspectable,
    impl::consume<IInputStream>,
    impl::require<IInputStream, Windows::Foundation::IClosable>
{
    IInputStream(std::nullptr_t = nullptr) noexcept {}
};

struct IInputStreamReference :
    Windows::Foundation::IInspectable,
    impl::consume<IInputStreamReference>
{
    IInputStreamReference(std::nullptr_t = nullptr) noexcept {}
};

struct IOutputStream :
    Windows::Foundation::IInspectable,
    impl::consume<IOutputStream>,
    impl::require<IOutputStream, Windows::Foundation::IClosable>
{
    IOutputStream(std::nullptr_t = nullptr) noexcept {}
};

struct IRandomAccessStream :
    Windows::Foundation::IInspectable,
    impl::consume<IRandomAccessStream>,
    impl::require<IRandomAccessStream, Windows::Foundation::IClosable, Windows::Storage::Streams::IInputStream, Windows::Storage::Streams::IOutputStream>
{
    IRandomAccessStream(std::nullptr_t = nullptr) noexcept {}
};

struct IRandomAccessStreamReference :
    Windows::Foundation::IInspectable,
    impl::consume<IRandomAccessStreamReference>
{
    IRandomAccessStreamReference(std::nullptr_t = nullptr) noexcept {}
};

struct IRandomAccessStreamReferenceStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IRandomAccessStreamReferenceStatics>
{
    IRandomAccessStreamReferenceStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IRandomAccessStreamStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IRandomAccessStreamStatics>
{
    IRandomAccessStreamStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IRandomAccessStreamWithContentType :
    Windows::Foundation::IInspectable,
    impl::consume<IRandomAccessStreamWithContentType>,
    impl::require<IRandomAccessStreamWithContentType, Windows::Foundation::IClosable, Windows::Storage::Streams::IContentTypeProvider, Windows::Storage::Streams::IInputStream, Windows::Storage::Streams::IOutputStream, Windows::Storage::Streams::IRandomAccessStream>
{
    IRandomAccessStreamWithContentType(std::nullptr_t = nullptr) noexcept {}
};

}

}
