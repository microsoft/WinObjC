//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************
#pragma once
#include <windows.h>
#include "wil/result.h"
#include "RawBuffer.h"
#include <wrl/client.h>
#include <wrl/implements.h>
#include <Windows.Storage.streams.h>

using namespace Microsoft::WRL;
using namespace ABI::Windows::Storage::Streams;

/// <summary>
/// Provides an implementation of IBuffer and IBufferByteAccess over caller-specified blobs of memory.
/// </summary>
class RawBuffer : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::WinRtClassicComMix>,
                                                      ABI::Windows::Storage::Streams::IBuffer,
                                                      IBufferByteAccess,
                                                      Microsoft::WRL::FtmBase> {
protected:
    InspectableClass(L"Windows.Storage.Streams.Buffer", TrustLevel::BaseTrust);

public:
    // Constructs an empty buffer. Zero length & capacity, nullptr data.
    RawBuffer();

    // Constructs a buffer from a caller-owned block of memory.
    RawBuffer(unsigned char* bytes, UINT32 length, UINT32 capacity);

    HRESULT RuntimeClassInitialize(unsigned char* bytes, UINT32 length, UINT32 capacity);

    // IBuffer Methods
    IFACEMETHOD(get_Capacity)(_Out_ UINT32* pCapacity);
    IFACEMETHOD(get_Length)(_Out_ UINT32* pLength);
    IFACEMETHOD(put_Length)(UINT32 size);

    // IBufferByteAccess Methods
    IFACEMETHOD(Buffer)(_Outptr_ byte** ppData);

private:
    unsigned long m_capacity;
    unsigned long m_length;
    unsigned char* m_data;
};

RawBuffer::RawBuffer(unsigned char* bytes, UINT32 length, UINT32 capacity) : m_capacity(capacity), m_length(length), m_data(bytes) {
}

RawBuffer::RawBuffer() : RawBuffer(nullptr, 0, 0) {
}

HRESULT RawBuffer::RuntimeClassInitialize(unsigned char* bytes, UINT32 length, UINT32 capacity) {
    m_capacity = capacity;
    m_length = length;
    m_data = bytes;

    return S_OK;
}

IFACEMETHODIMP RawBuffer::get_Capacity(UINT32* capacity) {
    *capacity = m_capacity;
    return S_OK;
}

IFACEMETHODIMP RawBuffer::get_Length(UINT32* length) {
    *length = m_length;
    return S_OK;
}

IFACEMETHODIMP RawBuffer::put_Length(UINT32 size) {
    RETURN_HR_IF_TRUE(E_INVALIDARG, size > m_capacity);

    m_length = size;
    return S_OK;
}

IFACEMETHODIMP RawBuffer::Buffer(unsigned char** outData) {
    *outData = m_data;
    return S_OK;
}

ComPtr<IBuffer> BufferFromRawData(unsigned char* data, unsigned int length) {
    ComPtr<RawBuffer> rawBuffer;
    HRESULT makeResult = MakeAndInitialize<RawBuffer>(&rawBuffer, data, length, length);

    if (FAILED_LOG(makeResult)) {
        return nullptr;
    }

    ComPtr<ABI::Windows::Storage::Streams::IBuffer> wrlBuffer;
    HRESULT result = rawBuffer.As(&wrlBuffer);

    if (FAILED_LOG(result)) {
        return nullptr;
    }

    return wrlBuffer;
}
