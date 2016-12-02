//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import "DWriteFontBinaryDataLoader.h"

using namespace Microsoft::WRL;

/**
 * Private class.
 * Custom implementation of IDWriteFontFileStream that implements Read in terms of an underlying CFDataRef
 *
 * While IDWriteFontFileStream normally frees its underlying data bit by bit through ReleaseFileFragment(),
 * for WinObjC purposes, it is easier to rely on existing mechanisms for CFData's destruction.
 * Thus, this class releases its CFData all at once, at the time of its destruction.
 */
class DWriteFontBinaryDataStream : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IDWriteFontFileStream> {
protected:
    InspectableClass(L"Windows.Bridge.DirectWrite", TrustLevel::BaseTrust);

public:
    DWriteFontBinaryDataStream() {
    }

    HRESULT RuntimeClassInitialize(CFDataRef data) {
        CFRetain(data);
        m_data.reset(data);

        // Just use current time for m_lastWriteTime
        FILETIME fileTime;
        GetSystemTimeAsFileTime(&fileTime);

        // Concat filetime into a single uint64_t
        m_lastWriteTime = 0;
        m_lastWriteTime |= static_cast<uint64_t>(fileTime.dwLowDateTime);
        m_lastWriteTime |= static_cast<uint64_t>(fileTime.dwHighDateTime) << 32;
        return S_OK;
    }

    HRESULT STDMETHODCALLTYPE GetFileSize(_Out_ uint64_t* fileSize) {
        RETURN_HR_IF_NULL(E_INVALIDARG, fileSize);
        *fileSize = CFDataGetLength(m_data.get());
        return S_OK;
    };

    HRESULT STDMETHODCALLTYPE GetLastWriteTime(_Out_ uint64_t* lastWriteTime) {
        RETURN_HR_IF_NULL(E_INVALIDARG, lastWriteTime);
        *lastWriteTime = m_lastWriteTime;
        return S_OK;
    };

    HRESULT STDMETHODCALLTYPE ReadFileFragment(_Out_ const void** fragmentStart,
                                               uint64_t fileOffset,
                                               uint64_t fragmentSize,
                                               _Out_ void** fragmentContext) {
        if (fileOffset + fragmentSize > CFDataGetLength(m_data.get())) {
            return E_INVALIDARG;
        }

        if (fragmentStart) {
            const uint8_t* underlyingBuffer = CFDataGetBytePtr(m_data.get());
            *fragmentStart = reinterpret_cast<const void*>(&(underlyingBuffer[fileOffset]));
        }

        if (fragmentContext) {
            // Deliberately unused: this is meant to be passed to ReleaseFileFragment() below to free part of the data,
            // but this stream frees all the underlying CFData at once
            *fragmentContext = nullptr;
        }

        return S_OK;
    };

    void STDMETHODCALLTYPE ReleaseFileFragment(void* fragmentContext){
        // Deliberate no-op: data is released alongside the m_data member with the destruction of this object
    };

private:
    woc::unique_cf<CFDataRef> m_data;
    uint64_t m_lastWriteTime;
};

// DWriteFontBinaryDataLoader member functions

DWriteFontBinaryDataLoader::DWriteFontBinaryDataLoader() {
    // Deliberate no-op
}

HRESULT DWriteFontBinaryDataLoader::RuntimeClassInitialize(CFDataRef data) {
    CFRetain(data);
    m_data.reset(data);
    return S_OK;
}

// Ignores first two params, just return the same kind of stream always
// Stream returned is dictated by dataProvider passed in at initialization time
HRESULT STDMETHODCALLTYPE DWriteFontBinaryDataLoader::CreateStreamFromKey(_In_ const void* fontFileReferenceKey,
                                                                          uint32_t fontFileReferenceKeySize,
                                                                          _Out_ IDWriteFontFileStream** fontFileStream) {
    RETURN_HR_IF_NULL(E_INVALIDARG, fontFileStream);

    ComPtr<DWriteFontBinaryDataStream> ret;
    RETURN_IF_FAILED(MakeAndInitialize<DWriteFontBinaryDataStream>(&ret, m_data.get()));

    *fontFileStream = ret.Detach();
    return S_OK;
}