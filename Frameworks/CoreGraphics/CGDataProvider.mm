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

#import <StubReturn.h>
#import <Starboard.h>
#import <CoreGraphics/CGDataProvider.h>
#import "CGDataProviderInternal.h"
#import <CFCppBase.h>

// Required so we can use CFHashBytes rather than trying our own hash algorithm
#import <ForFoundationOnly.h>

#import <vector>
#import <mutex>
#import <functional>

// Determines what amount of bytes to try and read at a time for indirect access data providers
static constexpr size_t c_streamSize = 2048;

#pragma region __CGDataProviderInternal

// Internal implementations for CGDataProvider
// Use mutable for internal members because as far as the consumer is concerned we generate data on construction
// But allows us to lazily get data once and keep const constract with consumer
class __CGDataProviderInternal {
    mutable CFHashCode m_hashValue;
    mutable std::once_flag m_hashFlag;
    void SetHash() const {
        m_hashValue = CFHashBytes((UInt8*)GetData(), GetSize());
    }

public:
    virtual ~__CGDataProviderInternal() {
    }
    virtual const void* GetData() const = 0;
    virtual size_t GetSize() const = 0;
    bool operator==(const __CGDataProviderInternal& rhs) const {
        if (GetSize() != rhs.GetSize()) {
            return false;
        }

        if (Hash() != rhs.Hash()) {
            return false;
        }

        return memcmp(GetData(), rhs.GetData(), GetSize()) == 0;
    }

    CFHashCode Hash() const {
        std::call_once(m_hashFlag, &__CGDataProviderInternal::SetHash, this);
        return m_hashValue;
    }
};

template <typename TSkipBytes>
struct __CGDataProviderSequentialCallbacksInternal {
    CGDataProviderGetBytesCallback getBytes = nullptr;
    TSkipBytes skipBytes = nullptr;
    CGDataProviderRewindCallback rewind = nullptr;
    CGDataProviderReleaseInfoCallback releaseInfo = nullptr;
    __CGDataProviderSequentialCallbacksInternal(const CGDataProviderCallbacks* callbacks) {
        if (callbacks != nullptr) {
            getBytes = callbacks->getBytes;
            skipBytes = callbacks->skipBytes;
            rewind = callbacks->rewind;
            releaseInfo = callbacks->releaseProvider;
        }
    }

    __CGDataProviderSequentialCallbacksInternal(const CGDataProviderSequentialCallbacks* callbacks) {
        if (callbacks != nullptr) {
            getBytes = callbacks->getBytes;
            skipBytes = callbacks->skipForward;
            rewind = callbacks->rewind;
            releaseInfo = callbacks->releaseInfo;
        }
    }
};

template <typename TSkipBytes>
class __SequentialDataProvider : public __CGDataProviderInternal {
    mutable void* m_info;
    mutable __CGDataProviderSequentialCallbacksInternal<TSkipBytes> m_callbacks;
    mutable std::vector<unsigned char> m_data;
    mutable std::once_flag m_dataFlag;
    void GenerateData() const {
        if (m_callbacks.getBytes) {
            size_t count = 0, delta = 0;
            do {
                m_data.resize(m_data.size() + c_streamSize);
                delta = m_callbacks.getBytes(m_info, m_data.data() + count, c_streamSize);
                count += delta;
                if (m_callbacks.skipBytes != nullptr) {
                    m_callbacks.skipBytes(m_info, delta);
                }
            } while (delta == c_streamSize);
            m_data.resize(count);
        }
    }

public:
    __SequentialDataProvider(void* info, const CGDataProviderCallbacks* callbacks) : m_info(info), m_callbacks(callbacks) {
    }
    __SequentialDataProvider(void* info, const CGDataProviderSequentialCallbacks* callbacks) : m_info(info), m_callbacks(callbacks) {
    }

    const void* GetData() const override {
        std::call_once(m_dataFlag, &__SequentialDataProvider::GenerateData, this);
        return m_data.data();
    }

    size_t GetSize() const override {
        if (m_data.empty()) {
            GetData();
        }

        return m_data.size();
    }

    ~__SequentialDataProvider() {
        if (m_callbacks.releaseInfo != nullptr) {
            m_callbacks.releaseInfo(m_info);
        }
    }
};

class __RawDataProvider : public __CGDataProviderInternal {
    void* m_info;
    const void* m_data;
    size_t m_size;
    CGDataProviderReleaseDataCallback m_releaseData;

public:
    __RawDataProvider(void* info, const void* data, size_t size, CGDataProviderReleaseDataCallback releaseData)
        : m_info(info), m_data(data), m_size(size), m_releaseData(releaseData) {
    }

    const void* GetData() const override {
        return m_data;
    }

    size_t GetSize() const override {
        return m_size;
    }

    ~__RawDataProvider() {
        if (m_releaseData) {
            m_releaseData(m_info, m_data, m_size);
        }
    }
};

struct __CGDataProviderDirectCallbacksInternal {
    CGDataProviderGetBytePointerCallback getBytePointer = nullptr;
    CGDataProviderReleaseBytePointerCallback releaseBytePointer = nullptr;
    CGDataProviderReleaseInfoCallback releaseInfo = nullptr;
    __CGDataProviderDirectCallbacksInternal(const CGDataProviderDirectCallbacks* callbacks) {
        if (callbacks != nullptr) {
            getBytePointer = callbacks->getBytePointer;
            releaseBytePointer = callbacks->releaseBytePointer;
            releaseInfo = callbacks->releaseInfo;
        }
    }

    __CGDataProviderDirectCallbacksInternal(const CGDataProviderDirectAccessCallbacks* callbacks) {
        if (callbacks != nullptr) {
            getBytePointer = callbacks->getBytePointer;
            releaseBytePointer = callbacks->releaseBytePointer;
            releaseInfo = callbacks->releaseProvider;
        }
    }
};

class __DirectDataProvider : public __CGDataProviderInternal {
    void* m_info;
    off_t m_size;
    __CGDataProviderDirectCallbacksInternal m_callbacks;
    mutable const void* m_data = nullptr;
    mutable std::once_flag m_dataFlag;
    void GenerateData() const {
        if (m_callbacks.getBytePointer != nullptr) {
            m_data = m_callbacks.getBytePointer(m_info);
        }
    }

public:
    __DirectDataProvider(void* info, off_t size, const CGDataProviderDirectCallbacks* callbacks)
        : m_info(info), m_size(size), m_callbacks(callbacks) {
    }

    __DirectDataProvider(void* info, off_t size, const CGDataProviderDirectAccessCallbacks* callbacks)
        : m_info(info), m_size(size), m_callbacks(callbacks) {
    }

    const void* GetData() const override {
        std::call_once(m_dataFlag, &__DirectDataProvider::GenerateData, this);
        return m_data;
    }

    size_t GetSize() const override {
        return m_size;
    }

    ~__DirectDataProvider() {
        if (m_data != nullptr && m_callbacks.releaseBytePointer != nullptr) {
            m_callbacks.releaseBytePointer(m_info, m_data);
        }

        if (m_callbacks.releaseInfo != nullptr) {
            m_callbacks.releaseInfo(m_info);
        }
    }
};

class __CFDataDataProvider : public __CGDataProviderInternal {
    woc::unique_cf<CFDataRef> m_data;

public:
    __CFDataDataProvider(CFDataRef data) : m_data(CFDataCreateCopy(nullptr, data)) {
    }
    const void* GetData() const override {
        return CFDataGetBytePtr(m_data.get());
    }

    size_t GetSize() const override {
        return CFDataGetLength(m_data.get());
    }
};

class __CFURLDataProvider : public __CGDataProviderInternal {
    woc::unique_cf<CFURLRef> m_url;
    mutable woc::unique_cf<CFDataRef> m_data;

public:
    __CFURLDataProvider(CFURLRef url) : m_url((CFURLRef)CFRetain(url)) {
    }
    const void* GetData() const override {
        if (!m_data) {
            CFDataRef data;
            if (CFURLCreateDataAndPropertiesFromResource(nullptr, m_url.get(), &data, nullptr, nullptr, nullptr)) {
                m_data.reset(data);
            }
        }

        return CFDataGetBytePtr(m_data.get());
    }

    size_t GetSize() const override {
        if (!m_data) {
            GetData();
        }

        return CFDataGetLength(m_data.get());
    }
};
#pragma endregion // __CGDataProviderInternal

#pragma region __CGDataProvider
struct __CGDataProvider : CoreFoundation::CppBase<__CGDataProvider> {
    __CGDataProvider(void* info, const CGDataProviderCallbacks* callbacks)
        : m_internal(new __SequentialDataProvider<CGDataProviderSkipBytesCallback>(info, callbacks)) {
    }

    __CGDataProvider(void* info, size_t size, const CGDataProviderDirectAccessCallbacks* callbacks)
        : m_internal(new __DirectDataProvider(info, size, callbacks)) {
    }

    __CGDataProvider(void* info, off_t size, const CGDataProviderDirectCallbacks* callbacks)
        : m_internal(new __DirectDataProvider(info, size, callbacks)) {
    }

    __CGDataProvider(void* info, const CGDataProviderSequentialCallbacks* callbacks)
        : m_internal(new __SequentialDataProvider<CGDataProviderSkipForwardCallback>(info, callbacks)) {
    }

    __CGDataProvider(void* info, const void* data, size_t size, CGDataProviderReleaseDataCallback releaseData)
        : m_internal(new __RawDataProvider(info, data, size, releaseData)) {
    }

    __CGDataProvider(CFURLRef url) : m_internal(new __CFURLDataProvider(url)) {
    }

    __CGDataProvider(CFDataRef data) : m_internal(new __CFDataDataProvider(data)) {
    }

    __CGDataProvider(const char* filename) {
        woc::unique_cf<CFStringRef> string{ CFStringCreateWithCString(nullptr, filename, kCFStringEncodingUTF8) };
        woc::unique_cf<CFURLRef> url{ CFURLCreateWithFileSystemPath(nullptr, string.get(), kCFURLWindowsPathStyle, NO) };
        m_internal.reset(new __CFURLDataProvider(url.get()));
    }

    const void* GetData() const {
        return m_internal->GetData();
    }

    size_t GetSize() const {
        return m_internal->GetSize();
    }

    bool operator==(const __CGDataProvider& other) const {
        return *m_internal == *(other.m_internal);
    }

    // Have to override base version to use custom CFEqual, CFHash
    static CFTypeID GetTypeID() {
        static __CFRuntimeClass _cls{
            0, // Version
            typeid(__CGDataProvider).name(), // Class Name
            nullptr, // Init
            nullptr, // Copy (ill-defined for CF)
            &_CFFinalize, // Finalize
            &__CFEq, // Equals
            &__CFHash, // Hash
            nullptr, // Copy Description
            nullptr, // Copy Debug Description
        };
        static CFTypeID _id = _CFRuntimeRegisterClass(&_cls);
        return _id;
    }

private:
    std::unique_ptr<__CGDataProviderInternal> m_internal;

    static Boolean __CFEq(CFTypeRef lhs, CFTypeRef rhs) {
        return (*(__CGDataProvider*)lhs == *(__CGDataProvider*)rhs);
    }

    static CFHashCode __CFHash(CFTypeRef provider) {
        return ((__CGDataProvider*)provider)->m_internal->Hash();
    }
};

#pragma endregion // __CGDataProvider

#pragma region CGDataProvider Functions
/**
 @Status Interoperable
 @Notes
*/
CGDataProviderRef CGDataProviderCreate(void* info, const CGDataProviderCallbacks* callbacks) {
    return __CGDataProvider::CreateInstance(nullptr, info, callbacks);
}

/**
 @Status Interoperable
 @Notes
*/
CGDataProviderRef CGDataProviderCreateDirectAccess(void* info, size_t size, const CGDataProviderDirectAccessCallbacks* callbacks) {
    return __CGDataProvider::CreateInstance(nullptr, info, size, callbacks);
}
/**
 @Status Interoperable
 @Notes
*/
CGDataProviderRef CGDataProviderCreateDirect(void* info, off_t size, const CGDataProviderDirectCallbacks* callbacks) {
    return __CGDataProvider::CreateInstance(nullptr, info, size, callbacks);
}

/**
 @Status Interoperable
 @Notes
*/
CGDataProviderRef CGDataProviderCreateSequential(void* info, const CGDataProviderSequentialCallbacks* callbacks) {
    return __CGDataProvider::CreateInstance(nullptr, info, callbacks);
}

/**
# @Status Interoperable
*/
CGDataProviderRef CGDataProviderCreateWithData(void* info, const void* data, size_t size, CGDataProviderReleaseDataCallback releaseData) {
    return __CGDataProvider::CreateInstance(nullptr, info, data, size, releaseData);
}

/**
 @Status Caveat
 @Notes Only supports file:/// URLs
*/
CGDataProviderRef CGDataProviderCreateWithURL(CFURLRef url) {
    return __CGDataProvider::CreateInstance(nullptr, url);
}

/**
 @Status Interoperable
*/
CGDataProviderRef CGDataProviderCreateWithCFData(CFDataRef data) {
    return __CGDataProvider::CreateInstance(nullptr, data);
}

/**
 @Status Interoperable
*/
CGDataProviderRef CGDataProviderCreateWithFilename(const char* filename) {
    return __CGDataProvider::CreateInstance(nullptr, filename);
}

/**
 @Status Interoperable
*/
CFDataRef CGDataProviderCopyData(CGDataProviderRef provider) {
    RETURN_NULL_IF(provider == nullptr || provider->GetData() == nullptr);
    return CFDataCreate(nullptr, (const UInt8*)provider->GetData(), provider->GetSize());
}

/**
 @Status Interoperable
*/
void CGDataProviderRelease(CGDataProviderRef data) {
    CFRelease(data);
}

/**
 @Status Interoperable
 @Notes
*/
CGDataProviderRef CGDataProviderRetain(CGDataProviderRef provider) {
    CFRetain(provider);
    return provider;
}

/**
 @Status Interoperable
 @Notes
*/
CFTypeID CGDataProviderGetTypeID() {
    return __CGDataProvider::GetTypeID();
}

#pragma endregion // CGDataProvider Functions

#pragma region Internal CGDataProvider Functions

const void* _CGDataProviderGetData(CGDataProviderRef provider) {
    return provider ? provider->GetData() : nullptr;
}

size_t _CGDataProviderGetSize(CGDataProviderRef provider) {
    return provider ? provider->GetSize() : 0;
}

#pragma endregion // Internal CGDataProvider Functions