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

#import <CoreMedia/CMBlockBuffer.h>
#import <StubReturn.h>
#import "AssertARCEnabled.h"

/**
 @Status Stub
*/
OSStatus CMBlockBufferAccessDataBytes(
    CMBlockBufferRef theBuffer, size_t offset, size_t length, void* temporaryBlock, char* _Nullable* returnedPointer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBlockBufferAppendBufferReference(
    CMBlockBufferRef theBuffer, CMBlockBufferRef targetBBuf, size_t offsetToData, size_t dataLength, CMBlockBufferFlags flags) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBlockBufferAppendMemoryBlock(CMBlockBufferRef theBuffer,
                                        void* memoryBlock,
                                        size_t blockLength,
                                        CFAllocatorRef blockAllocator,
                                        const CMBlockBufferCustomBlockSource* customBlockSource,
                                        size_t offsetToData,
                                        size_t dataLength,
                                        CMBlockBufferFlags flags) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBlockBufferAssureBlockMemory(CMBlockBufferRef theBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBlockBufferCopyDataBytes(CMBlockBufferRef theSourceBuffer, size_t offsetToData, size_t dataLength, void* destination) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBlockBufferCreateContiguous(CFAllocatorRef structureAllocator,
                                       CMBlockBufferRef sourceBuffer,
                                       CFAllocatorRef blockAllocator,
                                       const CMBlockBufferCustomBlockSource* customBlockSource,
                                       size_t offsetToData,
                                       size_t dataLength,
                                       CMBlockBufferFlags flags,
                                       CMBlockBufferRef _Nullable* newBBufOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBlockBufferCreateEmpty(CFAllocatorRef structureAllocator,
                                  uint32_t subBlockCapacity,
                                  CMBlockBufferFlags flags,
                                  CMBlockBufferRef _Nullable* newBBufOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBlockBufferCreateWithBufferReference(CFAllocatorRef structureAllocator,
                                                CMBlockBufferRef targetBuffer,
                                                size_t offsetToData,
                                                size_t dataLength,
                                                CMBlockBufferFlags flags,
                                                CMBlockBufferRef _Nullable* newBBufOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBlockBufferCreateWithMemoryBlock(CFAllocatorRef structureAllocator,
                                            void* memoryBlock,
                                            size_t blockLength,
                                            CFAllocatorRef blockAllocator,
                                            const CMBlockBufferCustomBlockSource* customBlockSource,
                                            size_t offsetToData,
                                            size_t dataLength,
                                            CMBlockBufferFlags flags,
                                            CMBlockBufferRef _Nullable* newBBufOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBlockBufferFillDataBytes(char fillByte, CMBlockBufferRef destinationBuffer, size_t offsetIntoDestination, size_t dataLength) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
size_t CMBlockBufferGetDataLength(CMBlockBufferRef theBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBlockBufferGetDataPointer(
    CMBlockBufferRef theBuffer, size_t offset, size_t* lengthAtOffset, size_t* totalLength, char* _Nullable* dataPointer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CFTypeID CMBlockBufferGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Boolean CMBlockBufferIsEmpty(CMBlockBufferRef theBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Boolean CMBlockBufferIsRangeContiguous(CMBlockBufferRef theBuffer, size_t offset, size_t length) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMBlockBufferReplaceDataBytes(const void* sourceBytes,
                                       CMBlockBufferRef destinationBuffer,
                                       size_t offsetIntoDestination,
                                       size_t dataLength) {
    UNIMPLEMENTED();
    return StubReturn();
}
