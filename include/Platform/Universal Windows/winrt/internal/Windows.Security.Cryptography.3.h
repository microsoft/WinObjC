// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Security.Cryptography.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Security::Cryptography {

struct CryptographicBuffer
{
    CryptographicBuffer() = delete;
    static bool Compare(const Windows::Storage::Streams::IBuffer & object1, const Windows::Storage::Streams::IBuffer & object2);
    static Windows::Storage::Streams::IBuffer GenerateRandom(uint32_t length);
    static uint32_t GenerateRandomNumber();
    static Windows::Storage::Streams::IBuffer CreateFromByteArray(array_view<const uint8_t> value);
    static void CopyToByteArray(const Windows::Storage::Streams::IBuffer & buffer, com_array<uint8_t> & value);
    static Windows::Storage::Streams::IBuffer DecodeFromHexString(hstring_view value);
    static hstring EncodeToHexString(const Windows::Storage::Streams::IBuffer & buffer);
    static Windows::Storage::Streams::IBuffer DecodeFromBase64String(hstring_view value);
    static hstring EncodeToBase64String(const Windows::Storage::Streams::IBuffer & buffer);
    static Windows::Storage::Streams::IBuffer ConvertStringToBinary(hstring_view value, Windows::Security::Cryptography::BinaryStringEncoding encoding);
    static hstring ConvertBinaryToString(Windows::Security::Cryptography::BinaryStringEncoding encoding, const Windows::Storage::Streams::IBuffer & buffer);
};

}

}
