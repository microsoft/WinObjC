// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Storage.Compression.3.h"
#include "Windows.Storage.h"
#include "Windows.Foundation.h"
#include "Windows.Storage.Streams.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Storage::Compression::ICompressor> : produce_base<D, Windows::Storage::Compression::ICompressor>
{
    HRESULT __stdcall abi_FinishAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FinishAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DetachStream(impl::abi_arg_out<Windows::Storage::Streams::IOutputStream> stream) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *stream = detach_abi(this->shim().DetachStream());
            return S_OK;
        }
        catch (...)
        {
            *stream = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Compression::ICompressorFactory> : produce_base<D, Windows::Storage::Compression::ICompressorFactory>
{
    HRESULT __stdcall abi_CreateCompressor(impl::abi_arg_in<Windows::Storage::Streams::IOutputStream> underlyingStream, impl::abi_arg_out<Windows::Storage::Compression::ICompressor> createdCompressor) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *createdCompressor = detach_abi(this->shim().CreateCompressor(*reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&underlyingStream)));
            return S_OK;
        }
        catch (...)
        {
            *createdCompressor = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCompressorEx(impl::abi_arg_in<Windows::Storage::Streams::IOutputStream> underlyingStream, Windows::Storage::Compression::CompressAlgorithm algorithm, uint32_t blockSize, impl::abi_arg_out<Windows::Storage::Compression::ICompressor> createdCompressor) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *createdCompressor = detach_abi(this->shim().CreateCompressorEx(*reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&underlyingStream), algorithm, blockSize));
            return S_OK;
        }
        catch (...)
        {
            *createdCompressor = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Compression::IDecompressor> : produce_base<D, Windows::Storage::Compression::IDecompressor>
{
    HRESULT __stdcall abi_DetachStream(impl::abi_arg_out<Windows::Storage::Streams::IInputStream> stream) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *stream = detach_abi(this->shim().DetachStream());
            return S_OK;
        }
        catch (...)
        {
            *stream = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Compression::IDecompressorFactory> : produce_base<D, Windows::Storage::Compression::IDecompressorFactory>
{
    HRESULT __stdcall abi_CreateDecompressor(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> underlyingStream, impl::abi_arg_out<Windows::Storage::Compression::IDecompressor> createdDecompressor) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *createdDecompressor = detach_abi(this->shim().CreateDecompressor(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&underlyingStream)));
            return S_OK;
        }
        catch (...)
        {
            *createdDecompressor = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Storage::Compression {

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ICompressor<D>::FinishAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ICompressor)->abi_FinishAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Storage::Streams::IOutputStream impl_ICompressor<D>::DetachStream() const
{
    Windows::Storage::Streams::IOutputStream stream;
    check_hresult(WINRT_SHIM(ICompressor)->abi_DetachStream(put_abi(stream)));
    return stream;
}

template <typename D> Windows::Storage::Streams::IInputStream impl_IDecompressor<D>::DetachStream() const
{
    Windows::Storage::Streams::IInputStream stream;
    check_hresult(WINRT_SHIM(IDecompressor)->abi_DetachStream(put_abi(stream)));
    return stream;
}

template <typename D> Windows::Storage::Compression::Compressor impl_ICompressorFactory<D>::CreateCompressor(const Windows::Storage::Streams::IOutputStream & underlyingStream) const
{
    Windows::Storage::Compression::Compressor createdCompressor { nullptr };
    check_hresult(WINRT_SHIM(ICompressorFactory)->abi_CreateCompressor(get_abi(underlyingStream), put_abi(createdCompressor)));
    return createdCompressor;
}

template <typename D> Windows::Storage::Compression::Compressor impl_ICompressorFactory<D>::CreateCompressorEx(const Windows::Storage::Streams::IOutputStream & underlyingStream, Windows::Storage::Compression::CompressAlgorithm algorithm, uint32_t blockSize) const
{
    Windows::Storage::Compression::Compressor createdCompressor { nullptr };
    check_hresult(WINRT_SHIM(ICompressorFactory)->abi_CreateCompressorEx(get_abi(underlyingStream), algorithm, blockSize, put_abi(createdCompressor)));
    return createdCompressor;
}

template <typename D> Windows::Storage::Compression::Decompressor impl_IDecompressorFactory<D>::CreateDecompressor(const Windows::Storage::Streams::IInputStream & underlyingStream) const
{
    Windows::Storage::Compression::Decompressor createdDecompressor { nullptr };
    check_hresult(WINRT_SHIM(IDecompressorFactory)->abi_CreateDecompressor(get_abi(underlyingStream), put_abi(createdDecompressor)));
    return createdDecompressor;
}

inline Compressor::Compressor(const Windows::Storage::Streams::IOutputStream & underlyingStream) :
    Compressor(get_activation_factory<Compressor, ICompressorFactory>().CreateCompressor(underlyingStream))
{}

inline Compressor::Compressor(const Windows::Storage::Streams::IOutputStream & underlyingStream, Windows::Storage::Compression::CompressAlgorithm algorithm, uint32_t blockSize) :
    Compressor(get_activation_factory<Compressor, ICompressorFactory>().CreateCompressorEx(underlyingStream, algorithm, blockSize))
{}

inline Decompressor::Decompressor(const Windows::Storage::Streams::IInputStream & underlyingStream) :
    Decompressor(get_activation_factory<Decompressor, IDecompressorFactory>().CreateDecompressor(underlyingStream))
{}

}

}
#pragma warning(pop)
