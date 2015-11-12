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

#ifndef _CVPIXELBUFFER_H_
#define _CVPIXELBUFFER_H_

#import <CoreVideo/CVImageBuffer.h>
#import <StarboardExport.h>

typedef CVImageBufferRef CVPixelBufferRef;
typedef UInt64 CVOptionFlags;
typedef SInt32 CVReturn;

enum {
    kCVPixelFormatType_1Monochrome = 0x00000001,
    kCVPixelFormatType_2Indexed = 0x00000002,
    kCVPixelFormatType_4Indexed = 0x00000004,
    kCVPixelFormatType_8Indexed = 0x00000008,
    kCVPixelFormatType_1IndexedGray_WhiteIsZero = 0x00000021,
    kCVPixelFormatType_2IndexedGray_WhiteIsZero = 0x00000022,
    kCVPixelFormatType_4IndexedGray_WhiteIsZero = 0x00000024,
    kCVPixelFormatType_8IndexedGray_WhiteIsZero = 0x00000028,
    kCVPixelFormatType_16BE555 = 0x00000010,
    kCVPixelFormatType_16LE555 = 'L555',
    kCVPixelFormatType_16LE5551 = '5551',
    kCVPixelFormatType_16BE565 = 'B565',
    kCVPixelFormatType_16LE565 = 'L565',
    kCVPixelFormatType_24RGB = 0x00000018,
    kCVPixelFormatType_24BGR = '24BG',
    kCVPixelFormatType_32ARGB = 0x00000020,
    kCVPixelFormatType_32BGRA = 'BGRA',
    kCVPixelFormatType_32ABGR = 'ABGR',
    kCVPixelFormatType_32RGBA = 'RGBA',
    kCVPixelFormatType_64ARGB = 'b64a',
    kCVPixelFormatType_48RGB = 'b48r',
    kCVPixelFormatType_32AlphaGray = 'b32a',
    kCVPixelFormatType_16Gray = 'b16g',
    kCVPixelFormatType_30RGB = 'R10k',
    kCVPixelFormatType_422YpCbCr8 = '2vuy',
    kCVPixelFormatType_4444YpCbCrA8 = 'v408',
    kCVPixelFormatType_4444YpCbCrA8R = 'r408',
    kCVPixelFormatType_4444AYpCbCr8 = 'y408',
    kCVPixelFormatType_4444AYpCbCr16 = 'y416',
    kCVPixelFormatType_444YpCbCr8 = 'v308',
    kCVPixelFormatType_422YpCbCr16 = 'v216',
    kCVPixelFormatType_422YpCbCr10 = 'v210',
    kCVPixelFormatType_444YpCbCr10 = 'v410',
    kCVPixelFormatType_420YpCbCr8Planar = 'y420',
    kCVPixelFormatType_420YpCbCr8PlanarFullRange = 'f420',
    kCVPixelFormatType_422YpCbCr_4A_8BiPlanar = 'a2vy',
    kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange = '420v',
    kCVPixelFormatType_420YpCbCr8BiPlanarFullRange = '420f',
    kCVPixelFormatType_422YpCbCr8_yuvs = 'yuvs',
    kCVPixelFormatType_422YpCbCr8FullRange = 'yuvf',
    kCVPixelFormatType_OneComponent8 = 'L008',
    kCVPixelFormatType_TwoComponent8 = '2C08',
    kCVPixelFormatType_OneComponent16Half = 'L00h',
    kCVPixelFormatType_OneComponent32Float = 'L00f',
    kCVPixelFormatType_TwoComponent16Half = '2C0h',
    kCVPixelFormatType_TwoComponent32Float = '2C0f',
    kCVPixelFormatType_64RGBAHalf = 'RGhA',
    kCVPixelFormatType_128RGBAFloat = 'RGfA',
};

enum CVPixelBufferLockFlags {
    kCVPixelBufferLock_ReadOnly = 0x00000001,
};

SB_EXPORT const CFStringRef kCVPixelBufferPixelFormatTypeKey;
SB_EXPORT const CFStringRef kCVPixelBufferMemoryAllocatorKey;
SB_EXPORT const CFStringRef kCVPixelBufferWidthKey;
SB_EXPORT const CFStringRef kCVPixelBufferHeightKey;
SB_EXPORT const CFStringRef kCVPixelBufferExtendedPixelsLeftKey;
SB_EXPORT const CFStringRef kCVPixelBufferExtendedPixelsTopKey;
SB_EXPORT const CFStringRef kCVPixelBufferExtendedPixelsRightKey;
SB_EXPORT const CFStringRef kCVPixelBufferExtendedPixelsBottomKey;
SB_EXPORT const CFStringRef kCVPixelBufferBytesPerRowAlignmentKey;
SB_EXPORT const CFStringRef kCVPixelBufferCGBitmapContextCompatibilityKey;
SB_EXPORT const CFStringRef kCVPixelBufferCGImageCompatibilityKey;
SB_EXPORT const CFStringRef kCVPixelBufferOpenGLCompatibilityKey;
SB_EXPORT const CFStringRef kCVPixelBufferPlaneAlignmentKey;
SB_EXPORT const CFStringRef kCVPixelBufferIOSurfacePropertiesKey;
SB_EXPORT const CFStringRef kCVPixelBufferOpenGLESCompatibilityKey;

SB_EXPORT CVReturn CVPixelBufferLockBaseAddress(CVPixelBufferRef pixelBuffer, CVOptionFlags lockFlags);
SB_EXPORT CVReturn CVPixelBufferUnlockBaseAddress(CVPixelBufferRef pixelBuffer, CVOptionFlags unlockFlags);
SB_EXPORT size_t CVPixelBufferGetBytesPerRow(CVPixelBufferRef pixelBuffer);
SB_EXPORT size_t CVPixelBufferGetWidth(CVPixelBufferRef pixelBuffer);
SB_EXPORT size_t CVPixelBufferGetHeight(CVPixelBufferRef pixelBuffer);
SB_EXPORT void* CVPixelBufferGetBaseAddress(CVPixelBufferRef pixelBuffer);
SB_EXPORT OSType CVPixelBufferGetPixelFormatType(CVPixelBufferRef pixelBuffer);
SB_EXPORT size_t CVPixelBufferGetPlaneCount(CVPixelBufferRef pixelBuffer);
SB_EXPORT size_t CVPixelBufferGetBytesPerRowOfPlane(CVPixelBufferRef pixelBuffer, size_t planeIndex);
SB_EXPORT size_t CVPixelBufferGetHeightOfPlane(CVPixelBufferRef pixelBuffer, size_t planeIndex);
SB_EXPORT void* CVPixelBufferGetBaseAddressOfPlane(CVPixelBufferRef pixelBuffer, size_t planeIndex);
SB_EXPORT CVPixelBufferRef CVPixelBufferRetain(CVPixelBufferRef buffer);
SB_EXPORT void CVPixelBufferRelease(CVPixelBufferRef buffer);

#endif /* _CVPIXELBUFFER_H_ */