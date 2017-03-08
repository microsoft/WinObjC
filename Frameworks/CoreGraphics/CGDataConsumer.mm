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
#import <CoreGraphics/CGDataConsumer.h>
#import <CFCppBase.h>
#import <Starboard/SmartTypes.h>
#import "CGDataConsumerInternal.h"

#pragma region __CGDataConsumer

class __CGDataConsumerInternal {
public:
    virtual size_t WriteData(const void* data, size_t size) = 0;
};

class __GeneralDataConsumer : public __CGDataConsumerInternal {
public:
    __GeneralDataConsumer(void* info, const CGDataConsumerCallbacks* callbacks) : m_info(info), m_callbacks(*callbacks) {
    }
    size_t WriteData(const void* data, size_t size) override {
        return m_callbacks.putBytes ? m_callbacks.putBytes(m_info, data, size) : 0;
    }
    ~__GeneralDataConsumer() {
        if (m_callbacks.releaseConsumer) {
            m_callbacks.releaseConsumer(m_info);
        }
    }

private:
    void* m_info;
    CGDataConsumerCallbacks m_callbacks;
};

class __CFDataDataConsumer : public __CGDataConsumerInternal {
public:
    __CFDataDataConsumer(CFMutableDataRef data) : m_data(data) {
    }
    size_t WriteData(const void* data, size_t size) override {
        CFDataAppendBytes(m_data, (const UInt8*)data, size);
        return size;
    }

private:
    woc::AutoCF<CFMutableDataRef> m_data;
};

class __CFURLDataConsumer : public __CGDataConsumerInternal {
public:
    __CFURLDataConsumer(CFURLRef url) : m_url(url), m_stream(CFWriteStreamCreateWithFile(nullptr, m_url)) {
    }

    size_t WriteData(const void* data, size_t size) override {
        if (CFWriteStreamGetStatus(m_stream) != kCFStreamStatusOpen) {
            CFWriteStreamOpen(m_stream);
        }

        CFIndex totalWritten = CFWriteStreamWrite(m_stream, (const UInt8*)data, size);

        // Write returns -1 for failure, return 0 bytes written
        return totalWritten < 0 ? 0 : totalWritten;
    }

    ~__CFURLDataConsumer() {
        CFWriteStreamClose(m_stream);
    }

private:
    woc::AutoCF<CFURLRef> m_url;
    woc::AutoCF<CFWriteStreamRef> m_stream;
};

struct __CGDataConsumer : CoreFoundation::CppBase<__CGDataConsumer> {
    __CGDataConsumer(void* info, const CGDataConsumerCallbacks* callbacks) : m_internal(new __GeneralDataConsumer(info, callbacks)) {
    }
    __CGDataConsumer(CFMutableDataRef data) : m_internal(new __CFDataDataConsumer(data)) {
    }
    __CGDataConsumer(CFURLRef url) : m_internal(new __CFURLDataConsumer(url)) {
    }

    size_t WriteData(const void* data, size_t size) {
        return m_internal->WriteData(data, size);
    }

private:
    std::unique_ptr<__CGDataConsumerInternal> m_internal;
};

#pragma endregion // __CGDataConsumer

#pragma region CGDataConsumer Functions

/**
 @Status Interoperable
*/
CGDataConsumerRef CGDataConsumerCreate(void* info, const CGDataConsumerCallbacks* callbacks) {
    return callbacks ? __CGDataConsumer::CreateInstance(nullptr, info, callbacks) : nullptr;
}

/**
 @Status Interoperable
*/
CGDataConsumerRef CGDataConsumerCreateWithURL(CFURLRef url) {
    return url ? __CGDataConsumer::CreateInstance(nullptr, url) : nullptr;
}

/**
 @Status Interoperable
*/
CGDataConsumerRef CGDataConsumerCreateWithCFData(CFMutableDataRef data) {
    return data ? __CGDataConsumer::CreateInstance(nullptr, data) : nullptr;
}

/**
 @Status Interoperable
*/
CFTypeID CGDataConsumerGetTypeID() {
    return __CGDataConsumer::GetTypeID();
}

/**
 @Status Interoperable
*/
void CGDataConsumerRelease(CGDataConsumerRef consumer) {
    CFRelease(consumer);
}

/**
 @Status Interoperable
*/
CGDataConsumerRef CGDataConsumerRetain(CGDataConsumerRef consumer) {
    CFRetain(consumer);
    return consumer;
}

#pragma endregion // CGDataConsumer Functions

#pragma region Internal CGDataConsumer Functions

size_t _CGDataConsumerWriteData(CGDataConsumerRef consumer, const void* data, size_t size) {
    return consumer ? consumer->WriteData(data, size) : 0;
}

#pragma endregion // Internal CGDataConsumer Functions
