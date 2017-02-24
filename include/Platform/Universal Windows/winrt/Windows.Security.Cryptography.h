// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Security.Cryptography.3.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Security::Cryptography::ICryptographicBufferStatics> : produce_base<D, Windows::Security::Cryptography::ICryptographicBufferStatics>
{
    HRESULT __stdcall abi_Compare(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> object1, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> object2, bool * isEqual) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *isEqual = detach_abi(this->shim().Compare(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&object1), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&object2)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GenerateRandom(uint32_t length, impl::abi_arg_out<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *buffer = detach_abi(this->shim().GenerateRandom(length));
            return S_OK;
        }
        catch (...)
        {
            *buffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GenerateRandomNumber(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GenerateRandomNumber());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromByteArray(uint32_t __valueSize, impl::abi_arg_in<uint8_t> * value, impl::abi_arg_out<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *buffer = detach_abi(this->shim().CreateFromByteArray(array_view<const uint8_t>(value, value + __valueSize)));
            return S_OK;
        }
        catch (...)
        {
            *buffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyToByteArray(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer, uint32_t * __valueSize, impl::abi_arg_out<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CopyToByteArray(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer), detach_abi<uint8_t>(__valueSize, value));
            return S_OK;
        }
        catch (...)
        {
            *__valueSize = 0;
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DecodeFromHexString(impl::abi_arg_in<hstring> value, impl::abi_arg_out<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *buffer = detach_abi(this->shim().DecodeFromHexString(*reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *buffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EncodeToHexString(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EncodeToHexString(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DecodeFromBase64String(impl::abi_arg_in<hstring> value, impl::abi_arg_out<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *buffer = detach_abi(this->shim().DecodeFromBase64String(*reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            *buffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_EncodeToBase64String(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EncodeToBase64String(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConvertStringToBinary(impl::abi_arg_in<hstring> value, Windows::Security::Cryptography::BinaryStringEncoding encoding, impl::abi_arg_out<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *buffer = detach_abi(this->shim().ConvertStringToBinary(*reinterpret_cast<const hstring *>(&value), encoding));
            return S_OK;
        }
        catch (...)
        {
            *buffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ConvertBinaryToString(Windows::Security::Cryptography::BinaryStringEncoding encoding, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConvertBinaryToString(encoding, *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Security::Cryptography {

template <typename D> bool impl_ICryptographicBufferStatics<D>::Compare(const Windows::Storage::Streams::IBuffer & object1, const Windows::Storage::Streams::IBuffer & object2) const
{
    bool isEqual {};
    check_hresult(WINRT_SHIM(ICryptographicBufferStatics)->abi_Compare(get_abi(object1), get_abi(object2), &isEqual));
    return isEqual;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ICryptographicBufferStatics<D>::GenerateRandom(uint32_t length) const
{
    Windows::Storage::Streams::IBuffer buffer;
    check_hresult(WINRT_SHIM(ICryptographicBufferStatics)->abi_GenerateRandom(length, put_abi(buffer)));
    return buffer;
}

template <typename D> uint32_t impl_ICryptographicBufferStatics<D>::GenerateRandomNumber() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ICryptographicBufferStatics)->abi_GenerateRandomNumber(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ICryptographicBufferStatics<D>::CreateFromByteArray(array_view<const uint8_t> value) const
{
    Windows::Storage::Streams::IBuffer buffer;
    check_hresult(WINRT_SHIM(ICryptographicBufferStatics)->abi_CreateFromByteArray(value.size(), get_abi(value), put_abi(buffer)));
    return buffer;
}

template <typename D> void impl_ICryptographicBufferStatics<D>::CopyToByteArray(const Windows::Storage::Streams::IBuffer & buffer, com_array<uint8_t> & value) const
{
    check_hresult(WINRT_SHIM(ICryptographicBufferStatics)->abi_CopyToByteArray(get_abi(buffer), impl::put_size_abi(value), put_abi(value)));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ICryptographicBufferStatics<D>::DecodeFromHexString(hstring_view value) const
{
    Windows::Storage::Streams::IBuffer buffer;
    check_hresult(WINRT_SHIM(ICryptographicBufferStatics)->abi_DecodeFromHexString(get_abi(value), put_abi(buffer)));
    return buffer;
}

template <typename D> hstring impl_ICryptographicBufferStatics<D>::EncodeToHexString(const Windows::Storage::Streams::IBuffer & buffer) const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICryptographicBufferStatics)->abi_EncodeToHexString(get_abi(buffer), put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ICryptographicBufferStatics<D>::DecodeFromBase64String(hstring_view value) const
{
    Windows::Storage::Streams::IBuffer buffer;
    check_hresult(WINRT_SHIM(ICryptographicBufferStatics)->abi_DecodeFromBase64String(get_abi(value), put_abi(buffer)));
    return buffer;
}

template <typename D> hstring impl_ICryptographicBufferStatics<D>::EncodeToBase64String(const Windows::Storage::Streams::IBuffer & buffer) const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICryptographicBufferStatics)->abi_EncodeToBase64String(get_abi(buffer), put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ICryptographicBufferStatics<D>::ConvertStringToBinary(hstring_view value, Windows::Security::Cryptography::BinaryStringEncoding encoding) const
{
    Windows::Storage::Streams::IBuffer buffer;
    check_hresult(WINRT_SHIM(ICryptographicBufferStatics)->abi_ConvertStringToBinary(get_abi(value), encoding, put_abi(buffer)));
    return buffer;
}

template <typename D> hstring impl_ICryptographicBufferStatics<D>::ConvertBinaryToString(Windows::Security::Cryptography::BinaryStringEncoding encoding, const Windows::Storage::Streams::IBuffer & buffer) const
{
    hstring value;
    check_hresult(WINRT_SHIM(ICryptographicBufferStatics)->abi_ConvertBinaryToString(encoding, get_abi(buffer), put_abi(value)));
    return value;
}

inline bool CryptographicBuffer::Compare(const Windows::Storage::Streams::IBuffer & object1, const Windows::Storage::Streams::IBuffer & object2)
{
    return get_activation_factory<CryptographicBuffer, ICryptographicBufferStatics>().Compare(object1, object2);
}

inline Windows::Storage::Streams::IBuffer CryptographicBuffer::GenerateRandom(uint32_t length)
{
    return get_activation_factory<CryptographicBuffer, ICryptographicBufferStatics>().GenerateRandom(length);
}

inline uint32_t CryptographicBuffer::GenerateRandomNumber()
{
    return get_activation_factory<CryptographicBuffer, ICryptographicBufferStatics>().GenerateRandomNumber();
}

inline Windows::Storage::Streams::IBuffer CryptographicBuffer::CreateFromByteArray(array_view<const uint8_t> value)
{
    return get_activation_factory<CryptographicBuffer, ICryptographicBufferStatics>().CreateFromByteArray(value);
}

inline void CryptographicBuffer::CopyToByteArray(const Windows::Storage::Streams::IBuffer & buffer, com_array<uint8_t> & value)
{
    get_activation_factory<CryptographicBuffer, ICryptographicBufferStatics>().CopyToByteArray(buffer, value);
}

inline Windows::Storage::Streams::IBuffer CryptographicBuffer::DecodeFromHexString(hstring_view value)
{
    return get_activation_factory<CryptographicBuffer, ICryptographicBufferStatics>().DecodeFromHexString(value);
}

inline hstring CryptographicBuffer::EncodeToHexString(const Windows::Storage::Streams::IBuffer & buffer)
{
    return get_activation_factory<CryptographicBuffer, ICryptographicBufferStatics>().EncodeToHexString(buffer);
}

inline Windows::Storage::Streams::IBuffer CryptographicBuffer::DecodeFromBase64String(hstring_view value)
{
    return get_activation_factory<CryptographicBuffer, ICryptographicBufferStatics>().DecodeFromBase64String(value);
}

inline hstring CryptographicBuffer::EncodeToBase64String(const Windows::Storage::Streams::IBuffer & buffer)
{
    return get_activation_factory<CryptographicBuffer, ICryptographicBufferStatics>().EncodeToBase64String(buffer);
}

inline Windows::Storage::Streams::IBuffer CryptographicBuffer::ConvertStringToBinary(hstring_view value, Windows::Security::Cryptography::BinaryStringEncoding encoding)
{
    return get_activation_factory<CryptographicBuffer, ICryptographicBufferStatics>().ConvertStringToBinary(value, encoding);
}

inline hstring CryptographicBuffer::ConvertBinaryToString(Windows::Security::Cryptography::BinaryStringEncoding encoding, const Windows::Storage::Streams::IBuffer & buffer)
{
    return get_activation_factory<CryptographicBuffer, ICryptographicBufferStatics>().ConvertBinaryToString(encoding, buffer);
}

}

}
#pragma warning(pop)
