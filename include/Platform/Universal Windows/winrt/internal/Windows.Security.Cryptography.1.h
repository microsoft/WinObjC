// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Security.Cryptography.0.h"
#include "Windows.Storage.Streams.0.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Security::Cryptography {

struct __declspec(uuid("320b7e22-3cb0-4cdf-8663-1d28910065eb")) __declspec(novtable) ICryptographicBufferStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Compare(Windows::Storage::Streams::IBuffer * object1, Windows::Storage::Streams::IBuffer * object2, bool * isEqual) = 0;
    virtual HRESULT __stdcall abi_GenerateRandom(uint32_t length, Windows::Storage::Streams::IBuffer ** buffer) = 0;
    virtual HRESULT __stdcall abi_GenerateRandomNumber(uint32_t * value) = 0;
    virtual HRESULT __stdcall abi_CreateFromByteArray(uint32_t __valueSize, uint8_t * value, Windows::Storage::Streams::IBuffer ** buffer) = 0;
    virtual HRESULT __stdcall abi_CopyToByteArray(Windows::Storage::Streams::IBuffer * buffer, uint32_t * __valueSize, uint8_t ** value) = 0;
    virtual HRESULT __stdcall abi_DecodeFromHexString(hstring value, Windows::Storage::Streams::IBuffer ** buffer) = 0;
    virtual HRESULT __stdcall abi_EncodeToHexString(Windows::Storage::Streams::IBuffer * buffer, hstring * value) = 0;
    virtual HRESULT __stdcall abi_DecodeFromBase64String(hstring value, Windows::Storage::Streams::IBuffer ** buffer) = 0;
    virtual HRESULT __stdcall abi_EncodeToBase64String(Windows::Storage::Streams::IBuffer * buffer, hstring * value) = 0;
    virtual HRESULT __stdcall abi_ConvertStringToBinary(hstring value, winrt::Windows::Security::Cryptography::BinaryStringEncoding encoding, Windows::Storage::Streams::IBuffer ** buffer) = 0;
    virtual HRESULT __stdcall abi_ConvertBinaryToString(winrt::Windows::Security::Cryptography::BinaryStringEncoding encoding, Windows::Storage::Streams::IBuffer * buffer, hstring * value) = 0;
};

}

namespace ABI {


}

namespace Windows::Security::Cryptography {

template <typename D>
struct WINRT_EBO impl_ICryptographicBufferStatics
{
    bool Compare(const Windows::Storage::Streams::IBuffer & object1, const Windows::Storage::Streams::IBuffer & object2) const;
    Windows::Storage::Streams::IBuffer GenerateRandom(uint32_t length) const;
    uint32_t GenerateRandomNumber() const;
    Windows::Storage::Streams::IBuffer CreateFromByteArray(array_view<const uint8_t> value) const;
    void CopyToByteArray(const Windows::Storage::Streams::IBuffer & buffer, com_array<uint8_t> & value) const;
    Windows::Storage::Streams::IBuffer DecodeFromHexString(hstring_view value) const;
    hstring EncodeToHexString(const Windows::Storage::Streams::IBuffer & buffer) const;
    Windows::Storage::Streams::IBuffer DecodeFromBase64String(hstring_view value) const;
    hstring EncodeToBase64String(const Windows::Storage::Streams::IBuffer & buffer) const;
    Windows::Storage::Streams::IBuffer ConvertStringToBinary(hstring_view value, Windows::Security::Cryptography::BinaryStringEncoding encoding) const;
    hstring ConvertBinaryToString(Windows::Security::Cryptography::BinaryStringEncoding encoding, const Windows::Storage::Streams::IBuffer & buffer) const;
};

}

namespace impl {

template <> struct traits<Windows::Security::Cryptography::ICryptographicBufferStatics>
{
    using abi = ABI::Windows::Security::Cryptography::ICryptographicBufferStatics;
    template <typename D> using consume = Windows::Security::Cryptography::impl_ICryptographicBufferStatics<D>;
};

template <> struct traits<Windows::Security::Cryptography::CryptographicBuffer>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Security.Cryptography.CryptographicBuffer"; }
};

}

}
