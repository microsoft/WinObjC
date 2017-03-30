// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Storage.Compression.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Storage::Compression {

struct WINRT_EBO Compressor :
    Windows::Storage::Compression::ICompressor
{
    Compressor(std::nullptr_t) noexcept {}
    Compressor(const Windows::Storage::Streams::IOutputStream & underlyingStream);
    Compressor(const Windows::Storage::Streams::IOutputStream & underlyingStream, Windows::Storage::Compression::CompressAlgorithm algorithm, uint32_t blockSize);
};

struct WINRT_EBO Decompressor :
    Windows::Storage::Compression::IDecompressor
{
    Decompressor(std::nullptr_t) noexcept {}
    Decompressor(const Windows::Storage::Streams::IInputStream & underlyingStream);
};

}

}
