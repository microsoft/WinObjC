// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.Streams.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Storage::Streams {

struct WINRT_EBO Buffer :
    Windows::Storage::Streams::IBuffer
{
    Buffer(std::nullptr_t) noexcept {}
    Buffer(uint32_t capacity);
    static Windows::Storage::Streams::Buffer CreateCopyFromMemoryBuffer(const Windows::Foundation::IMemoryBuffer & input);
    static Windows::Foundation::MemoryBuffer CreateMemoryBufferOverIBuffer(const Windows::Storage::Streams::IBuffer & input);
};

struct WINRT_EBO DataReader :
    Windows::Storage::Streams::IDataReader,
    impl::require<DataReader, Windows::Foundation::IClosable>
{
    DataReader(std::nullptr_t) noexcept {}
    DataReader(const Windows::Storage::Streams::IInputStream & inputStream);
    static Windows::Storage::Streams::DataReader FromBuffer(const Windows::Storage::Streams::IBuffer & buffer);
};

struct WINRT_EBO DataReaderLoadOperation :
    Windows::Foundation::IAsyncOperation<uint32_t>
{
    DataReaderLoadOperation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DataWriter :
    Windows::Storage::Streams::IDataWriter,
    impl::require<DataWriter, Windows::Foundation::IClosable>
{
    DataWriter(std::nullptr_t) noexcept {}
    DataWriter();
    DataWriter(const Windows::Storage::Streams::IOutputStream & outputStream);
};

struct WINRT_EBO DataWriterStoreOperation :
    Windows::Foundation::IAsyncOperation<uint32_t>
{
    DataWriterStoreOperation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FileInputStream :
    Windows::Storage::Streams::IInputStream
{
    FileInputStream(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FileOutputStream :
    Windows::Storage::Streams::IOutputStream
{
    FileOutputStream(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FileRandomAccessStream :
    Windows::Storage::Streams::IRandomAccessStream
{
    FileRandomAccessStream(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InMemoryRandomAccessStream :
    Windows::Storage::Streams::IRandomAccessStream
{
    InMemoryRandomAccessStream(std::nullptr_t) noexcept {}
    InMemoryRandomAccessStream();
};

struct WINRT_EBO InputStreamOverStream :
    Windows::Storage::Streams::IInputStream
{
    InputStreamOverStream(std::nullptr_t) noexcept {}
};

struct WINRT_EBO OutputStreamOverStream :
    Windows::Storage::Streams::IOutputStream
{
    OutputStreamOverStream(std::nullptr_t) noexcept {}
};

struct RandomAccessStream
{
    RandomAccessStream() = delete;
    static Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> CopyAsync(const Windows::Storage::Streams::IInputStream & source, const Windows::Storage::Streams::IOutputStream & destination);
    static Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> CopyAsync(const Windows::Storage::Streams::IInputStream & source, const Windows::Storage::Streams::IOutputStream & destination, uint64_t bytesToCopy);
    static Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> CopyAndCloseAsync(const Windows::Storage::Streams::IInputStream & source, const Windows::Storage::Streams::IOutputStream & destination);
};

struct WINRT_EBO RandomAccessStreamOverStream :
    Windows::Storage::Streams::IRandomAccessStream
{
    RandomAccessStreamOverStream(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RandomAccessStreamReference :
    Windows::Storage::Streams::IRandomAccessStreamReference
{
    RandomAccessStreamReference(std::nullptr_t) noexcept {}
    static Windows::Storage::Streams::RandomAccessStreamReference CreateFromFile(const Windows::Storage::IStorageFile & file);
    static Windows::Storage::Streams::RandomAccessStreamReference CreateFromUri(const Windows::Foundation::Uri & uri);
    static Windows::Storage::Streams::RandomAccessStreamReference CreateFromStream(const Windows::Storage::Streams::IRandomAccessStream & stream);
};

}

}
