// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::Cryptography {

struct ICryptographicBufferStatics;

}

namespace Windows::Security::Cryptography {

struct ICryptographicBufferStatics;
struct CryptographicBuffer;

}

namespace Windows::Security::Cryptography {

template <typename T> struct impl_ICryptographicBufferStatics;

}

namespace Windows::Security::Cryptography {

enum class BinaryStringEncoding
{
    Utf8 = 0,
    Utf16LE = 1,
    Utf16BE = 2,
};

}

}
