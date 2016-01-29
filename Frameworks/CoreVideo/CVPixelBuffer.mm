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

#import <StubReturn.h>
#import <CoreVideo/CVPixelBuffer.h>

const CFStringRef kCVPixelBufferPixelFormatTypeKey = static_cast<CFStringRef>(@"kCVPixelBufferPixelFormatTypeKey");
const CFStringRef kCVPixelBufferMemoryAllocatorKey = static_cast<CFStringRef>(@"kCVPixelBufferMemoryAllocatorKey");
const CFStringRef kCVPixelBufferWidthKey = static_cast<CFStringRef>(@"kCVPixelBufferWidthKey");
const CFStringRef kCVPixelBufferHeightKey = static_cast<CFStringRef>(@"kCVPixelBufferHeightKey");
const CFStringRef kCVPixelBufferExtendedPixelsLeftKey = static_cast<CFStringRef>(@"kCVPixelBufferExtendedPixelsLeftKey");
const CFStringRef kCVPixelBufferExtendedPixelsTopKey = static_cast<CFStringRef>(@"kCVPixelBufferExtendedPixelsTopKey");
const CFStringRef kCVPixelBufferExtendedPixelsRightKey = static_cast<CFStringRef>(@"kCVPixelBufferExtendedPixelsRightKey");
const CFStringRef kCVPixelBufferExtendedPixelsBottomKey = static_cast<CFStringRef>(@"kCVPixelBufferExtendedPixelsBottomKey");
const CFStringRef kCVPixelBufferBytesPerRowAlignmentKey = static_cast<CFStringRef>(@"kCVPixelBufferBytesPerRowAlignmentKey");
const CFStringRef kCVPixelBufferCGBitmapContextCompatibilityKey =
    static_cast<CFStringRef>(@"kCVPixelBufferCGBitmapContextCompatibilityKey");
const CFStringRef kCVPixelBufferCGImageCompatibilityKey = static_cast<CFStringRef>(@"kCVPixelBufferCGImageCompatibilityKey");
const CFStringRef kCVPixelBufferOpenGLCompatibilityKey = static_cast<CFStringRef>(@"kCVPixelBufferOpenGLCompatibilityKey");
const CFStringRef kCVPixelBufferPlaneAlignmentKey = static_cast<CFStringRef>(@"kCVPixelBufferPlaneAlignmentKey");
const CFStringRef kCVPixelBufferIOSurfacePropertiesKey = static_cast<CFStringRef>(@"kCVPixelBufferIOSurfacePropertiesKey");
const CFStringRef kCVPixelBufferOpenGLESCompatibilityKey = static_cast<CFStringRef>(@"kCVPixelBufferOpenGLESCompatibilityKey");
const CFStringRef kCVPixelBufferMetalCompatibilityKey = static_cast<CFStringRef>(@"kCVPixelBufferMetalCompatibilityKey");

/**
 @Status Stub
 @Notes
*/
CVReturn CVPixelBufferCreate(CFAllocatorRef allocator,
                             size_t width,
                             size_t height,
                             OSType pixelFormatType,
                             CFDictionaryRef pixelBufferAttributes,
                             CVPixelBufferRef _Nullable* pixelBufferOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CVReturn CVPixelBufferCreateResolvedAttributesDictionary(CFAllocatorRef allocator,
                                                         CFArrayRef attributes,
                                                         CFDictionaryRef _Nullable* resolvedDictionaryOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CVReturn CVPixelBufferCreateWithBytes(CFAllocatorRef allocator,
                                      size_t width,
                                      size_t height,
                                      OSType pixelFormatType,
                                      void* baseAddress,
                                      size_t bytesPerRow,
                                      CVPixelBufferReleaseBytesCallback releaseCallback,
                                      void* releaseRefCon,
                                      CFDictionaryRef pixelBufferAttributes,
                                      CVPixelBufferRef _Nullable* pixelBufferOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CVReturn CVPixelBufferCreateWithPlanarBytes(CFAllocatorRef allocator,
                                            size_t width,
                                            size_t height,
                                            OSType pixelFormatType,
                                            void* dataPtr,
                                            size_t dataSize,
                                            size_t numberOfPlanes,
                                            void* _Nullable planeBaseAddress[],
                                            size_t planeWidth[],
                                            size_t planeHeight[],
                                            size_t planeBytesPerRow[],
                                            CVPixelBufferReleasePlanarBytesCallback releaseCallback,
                                            void* releaseRefCon,
                                            CFDictionaryRef pixelBufferAttributes,
                                            CVPixelBufferRef _Nullable* pixelBufferOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CVReturn CVPixelBufferFillExtendedPixels(CVPixelBufferRef pixelBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void* CVPixelBufferGetBaseAddress(CVPixelBufferRef pixelBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void* CVPixelBufferGetBaseAddressOfPlane(CVPixelBufferRef pixelBuffer, size_t planeIndex) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
size_t CVPixelBufferGetBytesPerRow(CVPixelBufferRef pixelBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
size_t CVPixelBufferGetBytesPerRowOfPlane(CVPixelBufferRef pixelBuffer, size_t planeIndex) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
size_t CVPixelBufferGetDataSize(CVPixelBufferRef pixelBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CVPixelBufferGetExtendedPixels(CVPixelBufferRef pixelBuffer,
                                    size_t* extraColumnsOnLeft,
                                    size_t* extraColumnsOnRight,
                                    size_t* extraRowsOnTop,
                                    size_t* extraRowsOnBottom) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
size_t CVPixelBufferGetHeight(CVPixelBufferRef pixelBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
size_t CVPixelBufferGetHeightOfPlane(CVPixelBufferRef pixelBuffer, size_t planeIndex) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSType CVPixelBufferGetPixelFormatType(CVPixelBufferRef pixelBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
size_t CVPixelBufferGetPlaneCount(CVPixelBufferRef pixelBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CVPixelBufferGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
size_t CVPixelBufferGetWidth(CVPixelBufferRef pixelBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
size_t CVPixelBufferGetWidthOfPlane(CVPixelBufferRef pixelBuffer, size_t planeIndex) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CVPixelBufferIsPlanar(CVPixelBufferRef pixelBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CVReturn CVPixelBufferLockBaseAddress(CVPixelBufferRef pixelBuffer, CVPixelBufferLockFlags lockFlags) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CVPixelBufferRelease(CVPixelBufferRef texture) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CVPixelBufferRef CVPixelBufferRetain(CVPixelBufferRef texture) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CVReturn CVPixelBufferUnlockBaseAddress(CVPixelBufferRef pixelBuffer, CVPixelBufferLockFlags unlockFlags) {
    UNIMPLEMENTED();
    return StubReturn();
}
