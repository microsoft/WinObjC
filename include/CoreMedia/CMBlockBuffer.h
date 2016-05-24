//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <CoreMedia/CoreMediaExport.h>

#import <CoreFoundation/CFBase.h>

typedef struct OpaqueCMBlockBuffer* CMBlockBufferRef;
typedef uint32_t CMBlockBufferFlags;
typedef struct {
    uint32_t version;
    void* (*AllocateBlock)(void* refCon, size_t sizeInBytes);
    void (*FreeBlock)(void* refCon, void* doomedMemoryBlock, size_t sizeInBytes);
    void* refCon;
} CMBlockBufferCustomBlockSource;

COREMEDIA_EXPORT OSStatus CMBlockBufferAccessDataBytes(
    CMBlockBufferRef theBuffer, size_t offset, size_t length, void* temporaryBlock, char* _Nullable* returnedPointer) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBlockBufferAppendBufferReference(
    CMBlockBufferRef theBuffer, CMBlockBufferRef targetBBuf, size_t offsetToData, size_t dataLength, CMBlockBufferFlags flags) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBlockBufferAppendMemoryBlock(CMBlockBufferRef theBuffer,
                                                         void* memoryBlock,
                                                         size_t blockLength,
                                                         CFAllocatorRef blockAllocator,
                                                         const CMBlockBufferCustomBlockSource* customBlockSource,
                                                         size_t offsetToData,
                                                         size_t dataLength,
                                                         CMBlockBufferFlags flags) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBlockBufferAssureBlockMemory(CMBlockBufferRef theBuffer) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBlockBufferCopyDataBytes(CMBlockBufferRef theSourceBuffer,
                                                     size_t offsetToData,
                                                     size_t dataLength,
                                                     void* destination) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBlockBufferCreateContiguous(CFAllocatorRef structureAllocator,
                                                        CMBlockBufferRef sourceBuffer,
                                                        CFAllocatorRef blockAllocator,
                                                        const CMBlockBufferCustomBlockSource* customBlockSource,
                                                        size_t offsetToData,
                                                        size_t dataLength,
                                                        CMBlockBufferFlags flags,
                                                        CMBlockBufferRef _Nullable* newBBufOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBlockBufferCreateEmpty(CFAllocatorRef structureAllocator,
                                                   uint32_t subBlockCapacity,
                                                   CMBlockBufferFlags flags,
                                                   CMBlockBufferRef _Nullable* newBBufOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBlockBufferCreateWithBufferReference(CFAllocatorRef structureAllocator,
                                                                 CMBlockBufferRef targetBuffer,
                                                                 size_t offsetToData,
                                                                 size_t dataLength,
                                                                 CMBlockBufferFlags flags,
                                                                 CMBlockBufferRef _Nullable* newBBufOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBlockBufferCreateWithMemoryBlock(CFAllocatorRef structureAllocator,
                                                             void* memoryBlock,
                                                             size_t blockLength,
                                                             CFAllocatorRef blockAllocator,
                                                             const CMBlockBufferCustomBlockSource* customBlockSource,
                                                             size_t offsetToData,
                                                             size_t dataLength,
                                                             CMBlockBufferFlags flags,
                                                             CMBlockBufferRef _Nullable* newBBufOut) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBlockBufferFillDataBytes(char fillByte,
                                                     CMBlockBufferRef destinationBuffer,
                                                     size_t offsetIntoDestination,
                                                     size_t dataLength) STUB_METHOD;
COREMEDIA_EXPORT size_t CMBlockBufferGetDataLength(CMBlockBufferRef theBuffer) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBlockBufferGetDataPointer(
    CMBlockBufferRef theBuffer, size_t offset, size_t* lengthAtOffset, size_t* totalLength, char* _Nullable* dataPointer) STUB_METHOD;
COREMEDIA_EXPORT CFTypeID CMBlockBufferGetTypeID() STUB_METHOD;
COREMEDIA_EXPORT Boolean CMBlockBufferIsEmpty(CMBlockBufferRef theBuffer) STUB_METHOD;
COREMEDIA_EXPORT Boolean CMBlockBufferIsRangeContiguous(CMBlockBufferRef theBuffer, size_t offset, size_t length) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMBlockBufferReplaceDataBytes(const void* sourceBytes,
                                                        CMBlockBufferRef destinationBuffer,
                                                        size_t offsetIntoDestination,
                                                        size_t dataLength) STUB_METHOD;

enum { kCMBlockBufferCustomBlockSourceVersion = 0 };

enum {
    kCMBlockBufferAssureMemoryNowFlag = (1L << 0),
    kCMBlockBufferAlwaysCopyDataFlag = (1L << 1),
    kCMBlockBufferDontOptimizeDepthFlag = (1L << 2),
    kCMBlockBufferPermitEmptyReferenceFlag = (1L << 3)
};