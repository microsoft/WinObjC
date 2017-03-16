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

static const CGDataConsumerCallbacks sc_CGDataConsumerCFDataCallbacks{ // CGDataConsumerPutBytesCallback
                                                                       [](void* info, const void* data, size_t size) {
                                                                           CFDataAppendBytes(static_cast<CFMutableDataRef>(info),
                                                                                             (const UInt8*)data,
                                                                                             size);
                                                                           return size;
                                                                       },

                                                                       // CGDataConsumerReleaseInfoCallback
                                                                       [](void* info) { CFRelease(static_cast<CFTypeRef>(info)); }
};

static const CGDataConsumerCallbacks sc_CGDataConsumerCFURLCallbacks{ // CGDataConsumerPutBytesCallback
                                                                      [](void* info, const void* data, size_t size) -> size_t {
                                                                          CFWriteStreamRef writeStream =
                                                                              static_cast<CFWriteStreamRef>(info);
                                                                          if (CFWriteStreamGetStatus(writeStream) != kCFStreamStatusOpen) {
                                                                              CFWriteStreamOpen(writeStream);
                                                                          }

                                                                          CFIndex written =
                                                                              CFWriteStreamWrite(writeStream, (const UInt8*)data, size);
                                                                          return (written < 0L) ? 0 : written;
                                                                      },

                                                                      // CGDataConsumerReleaseInfoCallback
                                                                      [](void* info) {
                                                                          CFWriteStreamRef writeStream =
                                                                              static_cast<CFWriteStreamRef>(info);
                                                                          CFWriteStreamClose(writeStream);
                                                                          CFRelease(writeStream);
                                                                      }
};

struct __CGDataConsumer : CoreFoundation::CppBase<__CGDataConsumer> {
    __CGDataConsumer(void* info, const CGDataConsumerCallbacks* callbacks) : m_info(info), m_callbacks(*callbacks) {
    }
    __CGDataConsumer(CFMutableDataRef data) : __CGDataConsumer((void*)CFRetain(data), &sc_CGDataConsumerCFDataCallbacks) {
    }
    __CGDataConsumer(CFURLRef url) : __CGDataConsumer((void*)CFWriteStreamCreateWithFile(nullptr, url), &sc_CGDataConsumerCFURLCallbacks) {
    }

    size_t WriteData(const void* data, size_t size) {
        return m_callbacks.putBytes ? m_callbacks.putBytes(m_info, data, size) : 0;
    }

    ~__CGDataConsumer() {
        if (m_callbacks.releaseConsumer != nullptr) {
            m_callbacks.releaseConsumer(m_info);
        }
    }

private:
    void* m_info;
    CGDataConsumerCallbacks m_callbacks;
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
    if (consumer) {
        CFRelease(consumer);
    }
}

/**
 @Status Interoperable
*/
CGDataConsumerRef CGDataConsumerRetain(CGDataConsumerRef consumer) {
    if (consumer) {
        CFRetain(consumer);
    }

    return consumer;
}

#pragma endregion // CGDataConsumer Functions

#pragma region Internal CGDataConsumer Functions

size_t _CGDataConsumerWriteData(CGDataConsumerRef consumer, const void* data, size_t size) {
    return consumer ? consumer->WriteData(data, size) : 0;
}

#pragma endregion // Internal CGDataConsumer Functions
