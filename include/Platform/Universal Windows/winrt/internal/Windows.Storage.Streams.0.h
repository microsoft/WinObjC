// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Storage::Streams {

struct IBuffer;
struct IBufferFactory;
struct IBufferStatics;
struct IContentTypeProvider;
struct IDataReader;
struct IDataReaderFactory;
struct IDataReaderStatics;
struct IDataWriter;
struct IDataWriterFactory;
struct IInputStream;
struct IInputStreamReference;
struct IOutputStream;
struct IRandomAccessStream;
struct IRandomAccessStreamReference;
struct IRandomAccessStreamReferenceStatics;
struct IRandomAccessStreamStatics;
struct IRandomAccessStreamWithContentType;
struct Buffer;
struct DataReader;
struct DataReaderLoadOperation;
struct DataWriter;
struct DataWriterStoreOperation;
struct FileInputStream;
struct FileOutputStream;
struct FileRandomAccessStream;
struct InMemoryRandomAccessStream;
struct InputStreamOverStream;
struct OutputStreamOverStream;
struct RandomAccessStreamOverStream;
struct RandomAccessStreamReference;

}

namespace Windows::Storage::Streams {

struct IBuffer;
struct IBufferFactory;
struct IBufferStatics;
struct IContentTypeProvider;
struct IDataReader;
struct IDataReaderFactory;
struct IDataReaderStatics;
struct IDataWriter;
struct IDataWriterFactory;
struct IInputStream;
struct IInputStreamReference;
struct IOutputStream;
struct IRandomAccessStream;
struct IRandomAccessStreamReference;
struct IRandomAccessStreamReferenceStatics;
struct IRandomAccessStreamStatics;
struct IRandomAccessStreamWithContentType;
struct Buffer;
struct DataReader;
struct DataReaderLoadOperation;
struct DataWriter;
struct DataWriterStoreOperation;
struct FileInputStream;
struct FileOutputStream;
struct FileRandomAccessStream;
struct InMemoryRandomAccessStream;
struct InputStreamOverStream;
struct OutputStreamOverStream;
struct RandomAccessStream;
struct RandomAccessStreamOverStream;
struct RandomAccessStreamReference;

}

namespace Windows::Storage::Streams {

template <typename T> struct impl_IBuffer;
template <typename T> struct impl_IBufferFactory;
template <typename T> struct impl_IBufferStatics;
template <typename T> struct impl_IContentTypeProvider;
template <typename T> struct impl_IDataReader;
template <typename T> struct impl_IDataReaderFactory;
template <typename T> struct impl_IDataReaderStatics;
template <typename T> struct impl_IDataWriter;
template <typename T> struct impl_IDataWriterFactory;
template <typename T> struct impl_IInputStream;
template <typename T> struct impl_IInputStreamReference;
template <typename T> struct impl_IOutputStream;
template <typename T> struct impl_IRandomAccessStream;
template <typename T> struct impl_IRandomAccessStreamReference;
template <typename T> struct impl_IRandomAccessStreamReferenceStatics;
template <typename T> struct impl_IRandomAccessStreamStatics;
template <typename T> struct impl_IRandomAccessStreamWithContentType;

}

namespace Windows::Storage::Streams {

enum class ByteOrder
{
    LittleEndian = 0,
    BigEndian = 1,
};

enum class InputStreamOptions : unsigned
{
    None = 0x0,
    Partial = 0x1,
    ReadAhead = 0x2,
};

DEFINE_ENUM_FLAG_OPERATORS(InputStreamOptions)

enum class UnicodeEncoding
{
    Utf8 = 0,
    Utf16LE = 1,
    Utf16BE = 2,
};

}

}
