// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Storage.Compression.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Storage::Compression {

struct __declspec(uuid("0ac3645a-57ac-4ee1-b702-84d39d5424e0")) __declspec(novtable) ICompressor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FinishAsync(Windows::Foundation::IAsyncOperation<bool> ** operation) = 0;
    virtual HRESULT __stdcall abi_DetachStream(Windows::Storage::Streams::IOutputStream ** stream) = 0;
};

struct __declspec(uuid("5f3d96a4-2cfb-442c-a8ba-d7d11b039da0")) __declspec(novtable) ICompressorFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateCompressor(Windows::Storage::Streams::IOutputStream * underlyingStream, Windows::Storage::Compression::ICompressor ** createdCompressor) = 0;
    virtual HRESULT __stdcall abi_CreateCompressorEx(Windows::Storage::Streams::IOutputStream * underlyingStream, winrt::Windows::Storage::Compression::CompressAlgorithm algorithm, uint32_t blockSize, Windows::Storage::Compression::ICompressor ** createdCompressor) = 0;
};

struct __declspec(uuid("b883fe46-d68a-4c8b-ada0-4ee813fc5283")) __declspec(novtable) IDecompressor : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_DetachStream(Windows::Storage::Streams::IInputStream ** stream) = 0;
};

struct __declspec(uuid("5337e252-1da2-42e1-8834-0379d28d742f")) __declspec(novtable) IDecompressorFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateDecompressor(Windows::Storage::Streams::IInputStream * underlyingStream, Windows::Storage::Compression::IDecompressor ** createdDecompressor) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Storage::Compression::Compressor> { using default_interface = Windows::Storage::Compression::ICompressor; };
template <> struct traits<Windows::Storage::Compression::Decompressor> { using default_interface = Windows::Storage::Compression::IDecompressor; };

}

namespace Windows::Storage::Compression {

template <typename D>
struct WINRT_EBO impl_ICompressor
{
    Windows::Foundation::IAsyncOperation<bool> FinishAsync() const;
    Windows::Storage::Streams::IOutputStream DetachStream() const;
};

template <typename D>
struct WINRT_EBO impl_ICompressorFactory
{
    Windows::Storage::Compression::Compressor CreateCompressor(const Windows::Storage::Streams::IOutputStream & underlyingStream) const;
    Windows::Storage::Compression::Compressor CreateCompressorEx(const Windows::Storage::Streams::IOutputStream & underlyingStream, Windows::Storage::Compression::CompressAlgorithm algorithm, uint32_t blockSize) const;
};

template <typename D>
struct WINRT_EBO impl_IDecompressor
{
    Windows::Storage::Streams::IInputStream DetachStream() const;
};

template <typename D>
struct WINRT_EBO impl_IDecompressorFactory
{
    Windows::Storage::Compression::Decompressor CreateDecompressor(const Windows::Storage::Streams::IInputStream & underlyingStream) const;
};

}

namespace impl {

template <> struct traits<Windows::Storage::Compression::ICompressor>
{
    using abi = ABI::Windows::Storage::Compression::ICompressor;
    template <typename D> using consume = Windows::Storage::Compression::impl_ICompressor<D>;
};

template <> struct traits<Windows::Storage::Compression::ICompressorFactory>
{
    using abi = ABI::Windows::Storage::Compression::ICompressorFactory;
    template <typename D> using consume = Windows::Storage::Compression::impl_ICompressorFactory<D>;
};

template <> struct traits<Windows::Storage::Compression::IDecompressor>
{
    using abi = ABI::Windows::Storage::Compression::IDecompressor;
    template <typename D> using consume = Windows::Storage::Compression::impl_IDecompressor<D>;
};

template <> struct traits<Windows::Storage::Compression::IDecompressorFactory>
{
    using abi = ABI::Windows::Storage::Compression::IDecompressorFactory;
    template <typename D> using consume = Windows::Storage::Compression::impl_IDecompressorFactory<D>;
};

template <> struct traits<Windows::Storage::Compression::Compressor>
{
    using abi = ABI::Windows::Storage::Compression::Compressor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.Compression.Compressor"; }
};

template <> struct traits<Windows::Storage::Compression::Decompressor>
{
    using abi = ABI::Windows::Storage::Compression::Decompressor;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Storage.Compression.Decompressor"; }
};

}

}
