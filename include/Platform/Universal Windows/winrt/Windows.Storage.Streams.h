// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "Windows.Storage.h"
#include "Windows.Foundation.h"
#include "Windows.Foundation.Collections.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Storage::Streams::IBuffer> : produce_base<D, Windows::Storage::Streams::IBuffer>
{
    HRESULT __stdcall get_Capacity(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Capacity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Length(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Length());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Length(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Length(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Streams::IBufferFactory> : produce_base<D, Windows::Storage::Streams::IBufferFactory>
{
    HRESULT __stdcall abi_Create(uint32_t capacity, impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Create(capacity));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Streams::IBufferStatics> : produce_base<D, Windows::Storage::Streams::IBufferStatics>
{
    HRESULT __stdcall abi_CreateCopyFromMemoryBuffer(impl::abi_arg_in<Windows::Foundation::IMemoryBuffer> input, impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateCopyFromMemoryBuffer(*reinterpret_cast<const Windows::Foundation::IMemoryBuffer *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateMemoryBufferOverIBuffer(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> input, impl::abi_arg_out<Windows::Foundation::IMemoryBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateMemoryBufferOverIBuffer(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&input)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Streams::IContentTypeProvider> : produce_base<D, Windows::Storage::Streams::IContentTypeProvider>
{
    HRESULT __stdcall get_ContentType(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContentType());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Streams::IDataReader> : produce_base<D, Windows::Storage::Streams::IDataReader>
{
    HRESULT __stdcall get_UnconsumedBufferLength(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnconsumedBufferLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UnicodeEncoding(Windows::Storage::Streams::UnicodeEncoding * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnicodeEncoding());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UnicodeEncoding(Windows::Storage::Streams::UnicodeEncoding value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnicodeEncoding(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ByteOrder(Windows::Storage::Streams::ByteOrder * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ByteOrder());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ByteOrder(Windows::Storage::Streams::ByteOrder value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ByteOrder(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InputStreamOptions(Windows::Storage::Streams::InputStreamOptions * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InputStreamOptions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InputStreamOptions(Windows::Storage::Streams::InputStreamOptions value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InputStreamOptions(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadByte(uint8_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadByte());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadBytes(uint32_t __valueSize, impl::abi_arg_out<uint8_t> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReadBytes(*value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadBuffer(uint32_t length, impl::abi_arg_out<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *buffer = detach_abi(this->shim().ReadBuffer(length));
            return S_OK;
        }
        catch (...)
        {
            *buffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadBoolean(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadBoolean());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadGuid(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadGuid());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadInt16(int16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadInt16());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadInt32(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadInt32());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadInt64(int64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadInt64());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadUInt16(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadUInt16());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadUInt32(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadUInt32());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadUInt64(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadUInt64());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadSingle(float * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadSingle());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadDouble(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadDouble());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadString(uint32_t codeUnitCount, impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadString(codeUnitCount));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadDateTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadDateTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ReadTimeSpan(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ReadTimeSpan());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_LoadAsync(uint32_t count, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<uint32_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().LoadAsync(count));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DetachBuffer(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *buffer = detach_abi(this->shim().DetachBuffer());
            return S_OK;
        }
        catch (...)
        {
            *buffer = nullptr;
            return impl::to_hresult();
        }
    }

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
struct produce<D, Windows::Storage::Streams::IDataReaderFactory> : produce_base<D, Windows::Storage::Streams::IDataReaderFactory>
{
    HRESULT __stdcall abi_CreateDataReader(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> inputStream, impl::abi_arg_out<Windows::Storage::Streams::IDataReader> dataReader) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *dataReader = detach_abi(this->shim().CreateDataReader(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&inputStream)));
            return S_OK;
        }
        catch (...)
        {
            *dataReader = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Streams::IDataReaderStatics> : produce_base<D, Windows::Storage::Streams::IDataReaderStatics>
{
    HRESULT __stdcall abi_FromBuffer(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer, impl::abi_arg_out<Windows::Storage::Streams::IDataReader> dataReader) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *dataReader = detach_abi(this->shim().FromBuffer(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer)));
            return S_OK;
        }
        catch (...)
        {
            *dataReader = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Streams::IDataWriter> : produce_base<D, Windows::Storage::Streams::IDataWriter>
{
    HRESULT __stdcall get_UnstoredBufferLength(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnstoredBufferLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UnicodeEncoding(Windows::Storage::Streams::UnicodeEncoding * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UnicodeEncoding());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UnicodeEncoding(Windows::Storage::Streams::UnicodeEncoding value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UnicodeEncoding(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ByteOrder(Windows::Storage::Streams::ByteOrder * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ByteOrder());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ByteOrder(Windows::Storage::Streams::ByteOrder value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ByteOrder(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteByte(uint8_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteByte(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteBytes(uint32_t __valueSize, impl::abi_arg_in<uint8_t> * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteBytes(array_view<const uint8_t>(value, value + __valueSize));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteBuffer(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteBuffer(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteBufferRange(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer, uint32_t start, uint32_t count) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteBuffer(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer), start, count);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteBoolean(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteBoolean(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteGuid(GUID value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteGuid(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteInt16(int16_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteInt16(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteInt32(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteInt32(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteInt64(int64_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteInt64(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteUInt16(uint16_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteUInt16(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteUInt32(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteUInt32(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteUInt64(uint64_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteUInt64(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteSingle(float value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteSingle(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteDouble(double value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteDouble(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteDateTime(impl::abi_arg_in<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteDateTime(*reinterpret_cast<const Windows::Foundation::DateTime *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteTimeSpan(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WriteTimeSpan(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_WriteString(impl::abi_arg_in<hstring> value, uint32_t * codeUnitCount) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *codeUnitCount = detach_abi(this->shim().WriteString(*reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_MeasureString(impl::abi_arg_in<hstring> value, uint32_t * codeUnitCount) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *codeUnitCount = detach_abi(this->shim().MeasureString(*reinterpret_cast<const hstring *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StoreAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<uint32_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().StoreAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FlushAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FlushAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DetachBuffer(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> buffer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *buffer = detach_abi(this->shim().DetachBuffer());
            return S_OK;
        }
        catch (...)
        {
            *buffer = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DetachStream(impl::abi_arg_out<Windows::Storage::Streams::IOutputStream> outputStream) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *outputStream = detach_abi(this->shim().DetachStream());
            return S_OK;
        }
        catch (...)
        {
            *outputStream = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Streams::IDataWriterFactory> : produce_base<D, Windows::Storage::Streams::IDataWriterFactory>
{
    HRESULT __stdcall abi_CreateDataWriter(impl::abi_arg_in<Windows::Storage::Streams::IOutputStream> outputStream, impl::abi_arg_out<Windows::Storage::Streams::IDataWriter> dataWriter) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *dataWriter = detach_abi(this->shim().CreateDataWriter(*reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&outputStream)));
            return S_OK;
        }
        catch (...)
        {
            *dataWriter = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Streams::IInputStream> : produce_base<D, Windows::Storage::Streams::IInputStream>
{
    HRESULT __stdcall abi_ReadAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer, uint32_t count, Windows::Storage::Streams::InputStreamOptions options, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer, uint32_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().ReadAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer), count, options));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Streams::IInputStreamReference> : produce_base<D, Windows::Storage::Streams::IInputStreamReference>
{
    HRESULT __stdcall abi_OpenSequentialReadAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IInputStream>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().OpenSequentialReadAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Streams::IOutputStream> : produce_base<D, Windows::Storage::Streams::IOutputStream>
{
    HRESULT __stdcall abi_WriteAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> buffer, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<uint32_t, uint32_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().WriteAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&buffer)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FlushAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().FlushAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Streams::IRandomAccessStream> : produce_base<D, Windows::Storage::Streams::IRandomAccessStream>
{
    HRESULT __stdcall get_Size(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Size());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Size(uint64_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Size(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetInputStreamAt(uint64_t position, impl::abi_arg_out<Windows::Storage::Streams::IInputStream> stream) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *stream = detach_abi(this->shim().GetInputStreamAt(position));
            return S_OK;
        }
        catch (...)
        {
            *stream = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetOutputStreamAt(uint64_t position, impl::abi_arg_out<Windows::Storage::Streams::IOutputStream> stream) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *stream = detach_abi(this->shim().GetOutputStreamAt(position));
            return S_OK;
        }
        catch (...)
        {
            *stream = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Position(uint64_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Seek(uint64_t position) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Seek(position);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CloneStream(impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStream> stream) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *stream = detach_abi(this->shim().CloneStream());
            return S_OK;
        }
        catch (...)
        {
            *stream = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanRead(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanRead());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CanWrite(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CanWrite());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Streams::IRandomAccessStreamReference> : produce_base<D, Windows::Storage::Streams::IRandomAccessStreamReference>
{
    HRESULT __stdcall abi_OpenReadAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().OpenReadAsync());
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Streams::IRandomAccessStreamReferenceStatics> : produce_base<D, Windows::Storage::Streams::IRandomAccessStreamReferenceStatics>
{
    HRESULT __stdcall abi_CreateFromFile(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> streamReference) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *streamReference = detach_abi(this->shim().CreateFromFile(*reinterpret_cast<const Windows::Storage::IStorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *streamReference = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromUri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uri, impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> streamReference) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *streamReference = detach_abi(this->shim().CreateFromUri(*reinterpret_cast<const Windows::Foundation::Uri *>(&uri)));
            return S_OK;
        }
        catch (...)
        {
            *streamReference = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateFromStream(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> stream, impl::abi_arg_out<Windows::Storage::Streams::IRandomAccessStreamReference> streamReference) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *streamReference = detach_abi(this->shim().CreateFromStream(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *streamReference = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Streams::IRandomAccessStreamStatics> : produce_base<D, Windows::Storage::Streams::IRandomAccessStreamStatics>
{
    HRESULT __stdcall abi_CopyAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> source, impl::abi_arg_in<Windows::Storage::Streams::IOutputStream> destination, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CopyAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&source), *reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&destination)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopySizeAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> source, impl::abi_arg_in<Windows::Storage::Streams::IOutputStream> destination, uint64_t bytesToCopy, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CopyAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&source), *reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&destination), bytesToCopy));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CopyAndCloseAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> source, impl::abi_arg_in<Windows::Storage::Streams::IOutputStream> destination, impl::abi_arg_out<Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().CopyAndCloseAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&source), *reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&destination)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Storage::Streams::IRandomAccessStreamWithContentType> : produce_base<D, Windows::Storage::Streams::IRandomAccessStreamWithContentType>
{};

}

namespace Windows::Storage::Streams {

template <typename D> uint32_t impl_IDataReader<D>::UnconsumedBufferLength() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IDataReader)->get_UnconsumedBufferLength(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::UnicodeEncoding impl_IDataReader<D>::UnicodeEncoding() const
{
    Windows::Storage::Streams::UnicodeEncoding value {};
    check_hresult(WINRT_SHIM(IDataReader)->get_UnicodeEncoding(&value));
    return value;
}

template <typename D> void impl_IDataReader<D>::UnicodeEncoding(Windows::Storage::Streams::UnicodeEncoding value) const
{
    check_hresult(WINRT_SHIM(IDataReader)->put_UnicodeEncoding(value));
}

template <typename D> Windows::Storage::Streams::ByteOrder impl_IDataReader<D>::ByteOrder() const
{
    Windows::Storage::Streams::ByteOrder value {};
    check_hresult(WINRT_SHIM(IDataReader)->get_ByteOrder(&value));
    return value;
}

template <typename D> void impl_IDataReader<D>::ByteOrder(Windows::Storage::Streams::ByteOrder value) const
{
    check_hresult(WINRT_SHIM(IDataReader)->put_ByteOrder(value));
}

template <typename D> Windows::Storage::Streams::InputStreamOptions impl_IDataReader<D>::InputStreamOptions() const
{
    Windows::Storage::Streams::InputStreamOptions value {};
    check_hresult(WINRT_SHIM(IDataReader)->get_InputStreamOptions(&value));
    return value;
}

template <typename D> void impl_IDataReader<D>::InputStreamOptions(Windows::Storage::Streams::InputStreamOptions value) const
{
    check_hresult(WINRT_SHIM(IDataReader)->put_InputStreamOptions(value));
}

template <typename D> uint8_t impl_IDataReader<D>::ReadByte() const
{
    uint8_t value {};
    check_hresult(WINRT_SHIM(IDataReader)->abi_ReadByte(&value));
    return value;
}

template <typename D> void impl_IDataReader<D>::ReadBytes(array_view<uint8_t> value) const
{
    check_hresult(WINRT_SHIM(IDataReader)->abi_ReadBytes(value.size(), get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IDataReader<D>::ReadBuffer(uint32_t length) const
{
    Windows::Storage::Streams::IBuffer buffer;
    check_hresult(WINRT_SHIM(IDataReader)->abi_ReadBuffer(length, put_abi(buffer)));
    return buffer;
}

template <typename D> bool impl_IDataReader<D>::ReadBoolean() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IDataReader)->abi_ReadBoolean(&value));
    return value;
}

template <typename D> GUID impl_IDataReader<D>::ReadGuid() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(IDataReader)->abi_ReadGuid(&value));
    return value;
}

template <typename D> int16_t impl_IDataReader<D>::ReadInt16() const
{
    int16_t value {};
    check_hresult(WINRT_SHIM(IDataReader)->abi_ReadInt16(&value));
    return value;
}

template <typename D> int32_t impl_IDataReader<D>::ReadInt32() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IDataReader)->abi_ReadInt32(&value));
    return value;
}

template <typename D> int64_t impl_IDataReader<D>::ReadInt64() const
{
    int64_t value {};
    check_hresult(WINRT_SHIM(IDataReader)->abi_ReadInt64(&value));
    return value;
}

template <typename D> uint16_t impl_IDataReader<D>::ReadUInt16() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(IDataReader)->abi_ReadUInt16(&value));
    return value;
}

template <typename D> uint32_t impl_IDataReader<D>::ReadUInt32() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IDataReader)->abi_ReadUInt32(&value));
    return value;
}

template <typename D> uint64_t impl_IDataReader<D>::ReadUInt64() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IDataReader)->abi_ReadUInt64(&value));
    return value;
}

template <typename D> float impl_IDataReader<D>::ReadSingle() const
{
    float value {};
    check_hresult(WINRT_SHIM(IDataReader)->abi_ReadSingle(&value));
    return value;
}

template <typename D> double impl_IDataReader<D>::ReadDouble() const
{
    double value {};
    check_hresult(WINRT_SHIM(IDataReader)->abi_ReadDouble(&value));
    return value;
}

template <typename D> hstring impl_IDataReader<D>::ReadString(uint32_t codeUnitCount) const
{
    hstring value;
    check_hresult(WINRT_SHIM(IDataReader)->abi_ReadString(codeUnitCount, put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_IDataReader<D>::ReadDateTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(IDataReader)->abi_ReadDateTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_IDataReader<D>::ReadTimeSpan() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(IDataReader)->abi_ReadTimeSpan(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::DataReaderLoadOperation impl_IDataReader<D>::LoadAsync(uint32_t count) const
{
    Windows::Storage::Streams::DataReaderLoadOperation operation { nullptr };
    check_hresult(WINRT_SHIM(IDataReader)->abi_LoadAsync(count, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IDataReader<D>::DetachBuffer() const
{
    Windows::Storage::Streams::IBuffer buffer;
    check_hresult(WINRT_SHIM(IDataReader)->abi_DetachBuffer(put_abi(buffer)));
    return buffer;
}

template <typename D> Windows::Storage::Streams::IInputStream impl_IDataReader<D>::DetachStream() const
{
    Windows::Storage::Streams::IInputStream stream;
    check_hresult(WINRT_SHIM(IDataReader)->abi_DetachStream(put_abi(stream)));
    return stream;
}

template <typename D> Windows::Storage::Streams::DataReader impl_IDataReaderFactory<D>::CreateDataReader(const Windows::Storage::Streams::IInputStream & inputStream) const
{
    Windows::Storage::Streams::DataReader dataReader { nullptr };
    check_hresult(WINRT_SHIM(IDataReaderFactory)->abi_CreateDataReader(get_abi(inputStream), put_abi(dataReader)));
    return dataReader;
}

template <typename D> Windows::Storage::Streams::DataReader impl_IDataReaderStatics<D>::FromBuffer(const Windows::Storage::Streams::IBuffer & buffer) const
{
    Windows::Storage::Streams::DataReader dataReader { nullptr };
    check_hresult(WINRT_SHIM(IDataReaderStatics)->abi_FromBuffer(get_abi(buffer), put_abi(dataReader)));
    return dataReader;
}

template <typename D> uint32_t impl_IDataWriter<D>::UnstoredBufferLength() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IDataWriter)->get_UnstoredBufferLength(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::UnicodeEncoding impl_IDataWriter<D>::UnicodeEncoding() const
{
    Windows::Storage::Streams::UnicodeEncoding value {};
    check_hresult(WINRT_SHIM(IDataWriter)->get_UnicodeEncoding(&value));
    return value;
}

template <typename D> void impl_IDataWriter<D>::UnicodeEncoding(Windows::Storage::Streams::UnicodeEncoding value) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->put_UnicodeEncoding(value));
}

template <typename D> Windows::Storage::Streams::ByteOrder impl_IDataWriter<D>::ByteOrder() const
{
    Windows::Storage::Streams::ByteOrder value {};
    check_hresult(WINRT_SHIM(IDataWriter)->get_ByteOrder(&value));
    return value;
}

template <typename D> void impl_IDataWriter<D>::ByteOrder(Windows::Storage::Streams::ByteOrder value) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->put_ByteOrder(value));
}

template <typename D> void impl_IDataWriter<D>::WriteByte(uint8_t value) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteByte(value));
}

template <typename D> void impl_IDataWriter<D>::WriteBytes(array_view<const uint8_t> value) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteBytes(value.size(), get_abi(value)));
}

template <typename D> void impl_IDataWriter<D>::WriteBuffer(const Windows::Storage::Streams::IBuffer & buffer) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteBuffer(get_abi(buffer)));
}

template <typename D> void impl_IDataWriter<D>::WriteBuffer(const Windows::Storage::Streams::IBuffer & buffer, uint32_t start, uint32_t count) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteBufferRange(get_abi(buffer), start, count));
}

template <typename D> void impl_IDataWriter<D>::WriteBoolean(bool value) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteBoolean(value));
}

template <typename D> void impl_IDataWriter<D>::WriteGuid(GUID value) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteGuid(value));
}

template <typename D> void impl_IDataWriter<D>::WriteInt16(int16_t value) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteInt16(value));
}

template <typename D> void impl_IDataWriter<D>::WriteInt32(int32_t value) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteInt32(value));
}

template <typename D> void impl_IDataWriter<D>::WriteInt64(int64_t value) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteInt64(value));
}

template <typename D> void impl_IDataWriter<D>::WriteUInt16(uint16_t value) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteUInt16(value));
}

template <typename D> void impl_IDataWriter<D>::WriteUInt32(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteUInt32(value));
}

template <typename D> void impl_IDataWriter<D>::WriteUInt64(uint64_t value) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteUInt64(value));
}

template <typename D> void impl_IDataWriter<D>::WriteSingle(float value) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteSingle(value));
}

template <typename D> void impl_IDataWriter<D>::WriteDouble(double value) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteDouble(value));
}

template <typename D> void impl_IDataWriter<D>::WriteDateTime(const Windows::Foundation::DateTime & value) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteDateTime(get_abi(value)));
}

template <typename D> void impl_IDataWriter<D>::WriteTimeSpan(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteTimeSpan(get_abi(value)));
}

template <typename D> uint32_t impl_IDataWriter<D>::WriteString(hstring_view value) const
{
    uint32_t codeUnitCount {};
    check_hresult(WINRT_SHIM(IDataWriter)->abi_WriteString(get_abi(value), &codeUnitCount));
    return codeUnitCount;
}

template <typename D> uint32_t impl_IDataWriter<D>::MeasureString(hstring_view value) const
{
    uint32_t codeUnitCount {};
    check_hresult(WINRT_SHIM(IDataWriter)->abi_MeasureString(get_abi(value), &codeUnitCount));
    return codeUnitCount;
}

template <typename D> Windows::Storage::Streams::DataWriterStoreOperation impl_IDataWriter<D>::StoreAsync() const
{
    Windows::Storage::Streams::DataWriterStoreOperation operation { nullptr };
    check_hresult(WINRT_SHIM(IDataWriter)->abi_StoreAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IDataWriter<D>::FlushAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IDataWriter)->abi_FlushAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IDataWriter<D>::DetachBuffer() const
{
    Windows::Storage::Streams::IBuffer buffer;
    check_hresult(WINRT_SHIM(IDataWriter)->abi_DetachBuffer(put_abi(buffer)));
    return buffer;
}

template <typename D> Windows::Storage::Streams::IOutputStream impl_IDataWriter<D>::DetachStream() const
{
    Windows::Storage::Streams::IOutputStream outputStream;
    check_hresult(WINRT_SHIM(IDataWriter)->abi_DetachStream(put_abi(outputStream)));
    return outputStream;
}

template <typename D> Windows::Storage::Streams::DataWriter impl_IDataWriterFactory<D>::CreateDataWriter(const Windows::Storage::Streams::IOutputStream & outputStream) const
{
    Windows::Storage::Streams::DataWriter dataWriter { nullptr };
    check_hresult(WINRT_SHIM(IDataWriterFactory)->abi_CreateDataWriter(get_abi(outputStream), put_abi(dataWriter)));
    return dataWriter;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> impl_IRandomAccessStreamReference<D>::OpenReadAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IRandomAccessStreamWithContentType> operation;
    check_hresult(WINRT_SHIM(IRandomAccessStreamReference)->abi_OpenReadAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> impl_IRandomAccessStreamStatics<D>::CopyAsync(const Windows::Storage::Streams::IInputStream & source, const Windows::Storage::Streams::IOutputStream & destination) const
{
    Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> operation;
    check_hresult(WINRT_SHIM(IRandomAccessStreamStatics)->abi_CopyAsync(get_abi(source), get_abi(destination), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> impl_IRandomAccessStreamStatics<D>::CopyAsync(const Windows::Storage::Streams::IInputStream & source, const Windows::Storage::Streams::IOutputStream & destination, uint64_t bytesToCopy) const
{
    Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> operation;
    check_hresult(WINRT_SHIM(IRandomAccessStreamStatics)->abi_CopySizeAsync(get_abi(source), get_abi(destination), bytesToCopy, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> impl_IRandomAccessStreamStatics<D>::CopyAndCloseAsync(const Windows::Storage::Streams::IInputStream & source, const Windows::Storage::Streams::IOutputStream & destination) const
{
    Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> operation;
    check_hresult(WINRT_SHIM(IRandomAccessStreamStatics)->abi_CopyAndCloseAsync(get_abi(source), get_abi(destination), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Storage::Streams::Buffer impl_IBufferFactory<D>::Create(uint32_t capacity) const
{
    Windows::Storage::Streams::Buffer value { nullptr };
    check_hresult(WINRT_SHIM(IBufferFactory)->abi_Create(capacity, put_abi(value)));
    return value;
}

template <typename D> uint32_t impl_IBuffer<D>::Capacity() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBuffer)->get_Capacity(&value));
    return value;
}

template <typename D> uint32_t impl_IBuffer<D>::Length() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(IBuffer)->get_Length(&value));
    return value;
}

template <typename D> void impl_IBuffer<D>::Length(uint32_t value) const
{
    check_hresult(WINRT_SHIM(IBuffer)->put_Length(value));
}

template <typename D> Windows::Storage::Streams::Buffer impl_IBufferStatics<D>::CreateCopyFromMemoryBuffer(const Windows::Foundation::IMemoryBuffer & input) const
{
    Windows::Storage::Streams::Buffer value { nullptr };
    check_hresult(WINRT_SHIM(IBufferStatics)->abi_CreateCopyFromMemoryBuffer(get_abi(input), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::MemoryBuffer impl_IBufferStatics<D>::CreateMemoryBufferOverIBuffer(const Windows::Storage::Streams::IBuffer & input) const
{
    Windows::Foundation::MemoryBuffer value { nullptr };
    check_hresult(WINRT_SHIM(IBufferStatics)->abi_CreateMemoryBufferOverIBuffer(get_abi(input), put_abi(value)));
    return value;
}

template <typename D> hstring impl_IContentTypeProvider<D>::ContentType() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IContentTypeProvider)->get_ContentType(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IInputStream> impl_IInputStreamReference<D>::OpenSequentialReadAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IInputStream> operation;
    check_hresult(WINRT_SHIM(IInputStreamReference)->abi_OpenSequentialReadAsync(put_abi(operation)));
    return operation;
}

template <typename D> Windows::Storage::Streams::RandomAccessStreamReference impl_IRandomAccessStreamReferenceStatics<D>::CreateFromFile(const Windows::Storage::IStorageFile & file) const
{
    Windows::Storage::Streams::RandomAccessStreamReference streamReference { nullptr };
    check_hresult(WINRT_SHIM(IRandomAccessStreamReferenceStatics)->abi_CreateFromFile(get_abi(file), put_abi(streamReference)));
    return streamReference;
}

template <typename D> Windows::Storage::Streams::RandomAccessStreamReference impl_IRandomAccessStreamReferenceStatics<D>::CreateFromUri(const Windows::Foundation::Uri & uri) const
{
    Windows::Storage::Streams::RandomAccessStreamReference streamReference { nullptr };
    check_hresult(WINRT_SHIM(IRandomAccessStreamReferenceStatics)->abi_CreateFromUri(get_abi(uri), put_abi(streamReference)));
    return streamReference;
}

template <typename D> Windows::Storage::Streams::RandomAccessStreamReference impl_IRandomAccessStreamReferenceStatics<D>::CreateFromStream(const Windows::Storage::Streams::IRandomAccessStream & stream) const
{
    Windows::Storage::Streams::RandomAccessStreamReference streamReference { nullptr };
    check_hresult(WINRT_SHIM(IRandomAccessStreamReferenceStatics)->abi_CreateFromStream(get_abi(stream), put_abi(streamReference)));
    return streamReference;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer, uint32_t> impl_IInputStream<D>::ReadAsync(const Windows::Storage::Streams::IBuffer & buffer, uint32_t count, Windows::Storage::Streams::InputStreamOptions options) const
{
    Windows::Foundation::IAsyncOperationWithProgress<Windows::Storage::Streams::IBuffer, uint32_t> operation;
    check_hresult(WINRT_SHIM(IInputStream)->abi_ReadAsync(get_abi(buffer), count, options, put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperationWithProgress<uint32_t, uint32_t> impl_IOutputStream<D>::WriteAsync(const Windows::Storage::Streams::IBuffer & buffer) const
{
    Windows::Foundation::IAsyncOperationWithProgress<uint32_t, uint32_t> operation;
    check_hresult(WINRT_SHIM(IOutputStream)->abi_WriteAsync(get_abi(buffer), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_IOutputStream<D>::FlushAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(IOutputStream)->abi_FlushAsync(put_abi(operation)));
    return operation;
}

template <typename D> uint64_t impl_IRandomAccessStream<D>::Size() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IRandomAccessStream)->get_Size(&value));
    return value;
}

template <typename D> void impl_IRandomAccessStream<D>::Size(uint64_t value) const
{
    check_hresult(WINRT_SHIM(IRandomAccessStream)->put_Size(value));
}

template <typename D> Windows::Storage::Streams::IInputStream impl_IRandomAccessStream<D>::GetInputStreamAt(uint64_t position) const
{
    Windows::Storage::Streams::IInputStream stream;
    check_hresult(WINRT_SHIM(IRandomAccessStream)->abi_GetInputStreamAt(position, put_abi(stream)));
    return stream;
}

template <typename D> Windows::Storage::Streams::IOutputStream impl_IRandomAccessStream<D>::GetOutputStreamAt(uint64_t position) const
{
    Windows::Storage::Streams::IOutputStream stream;
    check_hresult(WINRT_SHIM(IRandomAccessStream)->abi_GetOutputStreamAt(position, put_abi(stream)));
    return stream;
}

template <typename D> uint64_t impl_IRandomAccessStream<D>::Position() const
{
    uint64_t value {};
    check_hresult(WINRT_SHIM(IRandomAccessStream)->get_Position(&value));
    return value;
}

template <typename D> void impl_IRandomAccessStream<D>::Seek(uint64_t position) const
{
    check_hresult(WINRT_SHIM(IRandomAccessStream)->abi_Seek(position));
}

template <typename D> Windows::Storage::Streams::IRandomAccessStream impl_IRandomAccessStream<D>::CloneStream() const
{
    Windows::Storage::Streams::IRandomAccessStream stream;
    check_hresult(WINRT_SHIM(IRandomAccessStream)->abi_CloneStream(put_abi(stream)));
    return stream;
}

template <typename D> bool impl_IRandomAccessStream<D>::CanRead() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IRandomAccessStream)->get_CanRead(&value));
    return value;
}

template <typename D> bool impl_IRandomAccessStream<D>::CanWrite() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IRandomAccessStream)->get_CanWrite(&value));
    return value;
}

inline Buffer::Buffer(uint32_t capacity) :
    Buffer(get_activation_factory<Buffer, IBufferFactory>().Create(capacity))
{}

inline Windows::Storage::Streams::Buffer Buffer::CreateCopyFromMemoryBuffer(const Windows::Foundation::IMemoryBuffer & input)
{
    return get_activation_factory<Buffer, IBufferStatics>().CreateCopyFromMemoryBuffer(input);
}

inline Windows::Foundation::MemoryBuffer Buffer::CreateMemoryBufferOverIBuffer(const Windows::Storage::Streams::IBuffer & input)
{
    return get_activation_factory<Buffer, IBufferStatics>().CreateMemoryBufferOverIBuffer(input);
}

inline DataReader::DataReader(const Windows::Storage::Streams::IInputStream & inputStream) :
    DataReader(get_activation_factory<DataReader, IDataReaderFactory>().CreateDataReader(inputStream))
{}

inline Windows::Storage::Streams::DataReader DataReader::FromBuffer(const Windows::Storage::Streams::IBuffer & buffer)
{
    return get_activation_factory<DataReader, IDataReaderStatics>().FromBuffer(buffer);
}

inline DataWriter::DataWriter() :
    DataWriter(activate_instance<DataWriter>())
{}

inline DataWriter::DataWriter(const Windows::Storage::Streams::IOutputStream & outputStream) :
    DataWriter(get_activation_factory<DataWriter, IDataWriterFactory>().CreateDataWriter(outputStream))
{}

inline InMemoryRandomAccessStream::InMemoryRandomAccessStream() :
    InMemoryRandomAccessStream(activate_instance<InMemoryRandomAccessStream>())
{}

inline Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> RandomAccessStream::CopyAsync(const Windows::Storage::Streams::IInputStream & source, const Windows::Storage::Streams::IOutputStream & destination)
{
    return get_activation_factory<RandomAccessStream, IRandomAccessStreamStatics>().CopyAsync(source, destination);
}

inline Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> RandomAccessStream::CopyAsync(const Windows::Storage::Streams::IInputStream & source, const Windows::Storage::Streams::IOutputStream & destination, uint64_t bytesToCopy)
{
    return get_activation_factory<RandomAccessStream, IRandomAccessStreamStatics>().CopyAsync(source, destination, bytesToCopy);
}

inline Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t> RandomAccessStream::CopyAndCloseAsync(const Windows::Storage::Streams::IInputStream & source, const Windows::Storage::Streams::IOutputStream & destination)
{
    return get_activation_factory<RandomAccessStream, IRandomAccessStreamStatics>().CopyAndCloseAsync(source, destination);
}

inline Windows::Storage::Streams::RandomAccessStreamReference RandomAccessStreamReference::CreateFromFile(const Windows::Storage::IStorageFile & file)
{
    return get_activation_factory<RandomAccessStreamReference, IRandomAccessStreamReferenceStatics>().CreateFromFile(file);
}

inline Windows::Storage::Streams::RandomAccessStreamReference RandomAccessStreamReference::CreateFromUri(const Windows::Foundation::Uri & uri)
{
    return get_activation_factory<RandomAccessStreamReference, IRandomAccessStreamReferenceStatics>().CreateFromUri(uri);
}

inline Windows::Storage::Streams::RandomAccessStreamReference RandomAccessStreamReference::CreateFromStream(const Windows::Storage::Streams::IRandomAccessStream & stream)
{
    return get_activation_factory<RandomAccessStreamReference, IRandomAccessStreamReferenceStatics>().CreateFromStream(stream);
}

}

}
#pragma warning(pop)
