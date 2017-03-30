// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Storage::Compression {

struct ICompressor;
struct ICompressorFactory;
struct IDecompressor;
struct IDecompressorFactory;
struct Compressor;
struct Decompressor;

}

namespace Windows::Storage::Compression {

struct ICompressor;
struct ICompressorFactory;
struct IDecompressor;
struct IDecompressorFactory;
struct Compressor;
struct Decompressor;

}

namespace Windows::Storage::Compression {

template <typename T> struct impl_ICompressor;
template <typename T> struct impl_ICompressorFactory;
template <typename T> struct impl_IDecompressor;
template <typename T> struct impl_IDecompressorFactory;

}

namespace Windows::Storage::Compression {

enum class CompressAlgorithm
{
    InvalidAlgorithm = 0,
    NullAlgorithm = 1,
    Mszip = 2,
    Xpress = 3,
    XpressHuff = 4,
    Lzms = 5,
};

}

}
