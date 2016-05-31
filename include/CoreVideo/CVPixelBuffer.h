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

#import <CoreVideo/CoreVideoExport.h>
#import <CoreFoundation/CFBase.h>
#import <CoreFoundation/CFDictionary.h>

#import <CoreVideo/CVImageBuffer.h>
#import <CoreFoundation/CFString.h>

typedef UInt64 CVOptionFlags;
typedef SInt32 CVReturn;

struct CVPlanarComponentInfo {
    int32_t offset;
    uint32_t rowBytes;
};
typedef struct CVPlanarComponentInfo CVPlanarComponentInfo;

struct CVPlanarPixelBufferInfo {
    CVPlanarComponentInfo componentInfo[1];
};
typedef struct CVPlanarPixelBufferInfo CVPlanarPixelBufferInfo;

struct CVPlanarPixelBufferInfo_YCbCrPlanar {
    CVPlanarComponentInfo componentInfoY;
    CVPlanarComponentInfo componentInfoCb;
    CVPlanarComponentInfo componentInfoCr;
};
typedef struct CVPlanarPixelBufferInfo_YCbCrPlanar CVPlanarPixelBufferInfo_YCbCrPlanar;

struct CVPlanarPixelBufferInfo_YCbCrBiPlanar {
    CVPlanarComponentInfo componentInfoY;
    CVPlanarComponentInfo componentInfoCbCr;
};
typedef struct CVPlanarPixelBufferInfo_YCbCrBiPlanar CVPlanarPixelBufferInfo_YCbCrBiPlanar;

typedef CVImageBufferRef CVPixelBufferRef;
typedef void (*CVPixelBufferReleaseBytesCallback)(void* releaseRefCon, const void* baseAddress);
typedef void (*CVPixelBufferReleasePlanarBytesCallback)(
    void* releaseRefCon, const void* dataPtr, size_t dataSize, size_t numberOfPlanes, const void* planeAddresses[]);

typedef CF_ENUM(UInt32, CVPixelBufferLockFlags) {
    kCVPixelBufferLock_ReadOnly = 0x00000001,
};

COREVIDEO_EXPORT CVReturn CVPixelBufferCreate(CFAllocatorRef allocator,
                                              size_t width,
                                              size_t height,
                                              OSType pixelFormatType,
                                              CFDictionaryRef pixelBufferAttributes,
                                              CVPixelBufferRef _Nullable* pixelBufferOut) STUB_METHOD;
COREVIDEO_EXPORT CVReturn CVPixelBufferCreateResolvedAttributesDictionary(CFAllocatorRef allocator,
                                                                          CFArrayRef attributes,
                                                                          CFDictionaryRef _Nullable* resolvedDictionaryOut) STUB_METHOD;
COREVIDEO_EXPORT CVReturn CVPixelBufferCreateWithBytes(CFAllocatorRef allocator,
                                                       size_t width,
                                                       size_t height,
                                                       OSType pixelFormatType,
                                                       void* baseAddress,
                                                       size_t bytesPerRow,
                                                       CVPixelBufferReleaseBytesCallback releaseCallback,
                                                       void* releaseRefCon,
                                                       CFDictionaryRef pixelBufferAttributes,
                                                       CVPixelBufferRef _Nullable* pixelBufferOut) STUB_METHOD;
COREVIDEO_EXPORT CVReturn CVPixelBufferCreateWithPlanarBytes(CFAllocatorRef allocator,
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
                                                             CVPixelBufferRef _Nullable* pixelBufferOut) STUB_METHOD;
COREVIDEO_EXPORT CVReturn CVPixelBufferFillExtendedPixels(CVPixelBufferRef pixelBuffer) STUB_METHOD;
COREVIDEO_EXPORT void* CVPixelBufferGetBaseAddress(CVPixelBufferRef pixelBuffer) STUB_METHOD;
COREVIDEO_EXPORT void* CVPixelBufferGetBaseAddressOfPlane(CVPixelBufferRef pixelBuffer, size_t planeIndex) STUB_METHOD;
COREVIDEO_EXPORT size_t CVPixelBufferGetBytesPerRow(CVPixelBufferRef pixelBuffer) STUB_METHOD;
COREVIDEO_EXPORT size_t CVPixelBufferGetBytesPerRowOfPlane(CVPixelBufferRef pixelBuffer, size_t planeIndex) STUB_METHOD;
COREVIDEO_EXPORT size_t CVPixelBufferGetDataSize(CVPixelBufferRef pixelBuffer) STUB_METHOD;
COREVIDEO_EXPORT void CVPixelBufferGetExtendedPixels(CVPixelBufferRef pixelBuffer,
                                                     size_t* extraColumnsOnLeft,
                                                     size_t* extraColumnsOnRight,
                                                     size_t* extraRowsOnTop,
                                                     size_t* extraRowsOnBottom) STUB_METHOD;
COREVIDEO_EXPORT size_t CVPixelBufferGetHeight(CVPixelBufferRef pixelBuffer) STUB_METHOD;
COREVIDEO_EXPORT size_t CVPixelBufferGetHeightOfPlane(CVPixelBufferRef pixelBuffer, size_t planeIndex) STUB_METHOD;
COREVIDEO_EXPORT OSType CVPixelBufferGetPixelFormatType(CVPixelBufferRef pixelBuffer) STUB_METHOD;
COREVIDEO_EXPORT size_t CVPixelBufferGetPlaneCount(CVPixelBufferRef pixelBuffer) STUB_METHOD;
COREVIDEO_EXPORT CFTypeID CVPixelBufferGetTypeID() STUB_METHOD;
COREVIDEO_EXPORT size_t CVPixelBufferGetWidth(CVPixelBufferRef pixelBuffer) STUB_METHOD;
COREVIDEO_EXPORT size_t CVPixelBufferGetWidthOfPlane(CVPixelBufferRef pixelBuffer, size_t planeIndex) STUB_METHOD;
COREVIDEO_EXPORT Boolean CVPixelBufferIsPlanar(CVPixelBufferRef pixelBuffer) STUB_METHOD;
COREVIDEO_EXPORT CVReturn CVPixelBufferLockBaseAddress(CVPixelBufferRef pixelBuffer, CVPixelBufferLockFlags lockFlags) STUB_METHOD;
COREVIDEO_EXPORT void CVPixelBufferRelease(CVPixelBufferRef texture) STUB_METHOD;
COREVIDEO_EXPORT CVPixelBufferRef CVPixelBufferRetain(CVPixelBufferRef texture) STUB_METHOD;
COREVIDEO_EXPORT CVReturn CVPixelBufferUnlockBaseAddress(CVPixelBufferRef pixelBuffer, CVPixelBufferLockFlags unlockFlags) STUB_METHOD;

COREVIDEO_EXPORT const CFStringRef kCVPixelBufferPixelFormatTypeKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferMemoryAllocatorKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferWidthKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferHeightKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferExtendedPixelsLeftKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferExtendedPixelsTopKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferExtendedPixelsRightKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferExtendedPixelsBottomKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferBytesPerRowAlignmentKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferCGBitmapContextCompatibilityKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferCGImageCompatibilityKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferOpenGLCompatibilityKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferPlaneAlignmentKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferIOSurfacePropertiesKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferOpenGLESCompatibilityKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferMetalCompatibilityKey;
