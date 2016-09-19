//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

#include <inttypes.h>
#include <BaseTsd.h>
#include "AccelerateExport.h"
#include <memory.h>

#if !defined(__clang__)
#ifndef __attribute__
#define __attribute__(x)
#endif

#include "CoreGraphics/CoreGraphicsExport.h"

typedef __CGColorSpace* CGColorSpaceRef;
typedef float CGFloat;
#else
#import <CoreGraphics/CoreGraphics.h>
#import <CoreGraphics/CGBitmapContext.h>
#import <CoreGraphics/CGImage.h>
#import <CoreImage/CIImage.h>
#import <CoreImage/CIContext.h>
#endif

#if !defined(__clang__)
#if defined(_M_IX86) || defined(_M_X64)
#define VIMAGE_SSE 1
static const uint32_t c_vImageBlockSizeBytes = 16;
#include <emmintrin.h>
#include <xmmintrin.h>
#else
#define VIMAGE_SSE 0
static const uint32_t c_vImageBlockSizeBytes = 1;
#endif

static bool c_vImagePadAllocs = (VIMAGE_SSE == 1);
static bool c_vImageUseSse2 = c_vImagePadAllocs && (VIMAGE_SSE == 1);

#endif

enum {
    kvImageNoError = 0,
    kvImageRoiLargerThanInputBuffer = -21766,
    kvImageInvalidKernelSize = -21767,
    kvImageInvalidEdgeStyle = -21768,
    kvImageInvalidOffset_X = -21769,
    kvImageInvalidOffset_Y = -21770,
    kvImageMemoryAllocationError = -21771,
    kvImageNullPointerArgument = -21772,
    kvImageInvalidParameter = -21773,
    kvImageBufferSizeMismatch = -21774,
    kvImageUnknownFlagsBit = -21775,
    kvImageInternalError = -21776,
    kvImageInvalidRowBytes = -21777,
    kvImageInvalidImageFormat = -21778,
    kvImageColorSyncIsAbsent = -21779,
    kvImageOutOfPlaceOperationRequired = -21780
};

enum {
    kvImageNoFlags = 0,
    kvImageLeaveAlphaUnchanged = 1,
    kvImageCopyInPlace = 2,
    kvImageBackgroundColorFill = 4,
    kvImageEdgeExtend = 8,
    kvImageDoNotTile = 16,
    kvImageHighQualityResampling = 32,
    kvImageTruncateKernel = 64,
    kvImageGetTempBufferSize = 128,
    kvImagePrintDiagnosticsToConsole = 256,
    kvImageNoAllocate = 512,
};

typedef unsigned long vImagePixelCount;

typedef SSIZE_T vImage_Error;

typedef uint32_t vImage_Flags;

typedef float Pixel_F;

typedef uint8_t Pixel_8888[4];

typedef struct _vImage_Buffer {
    void* data;
    vImagePixelCount height;
    vImagePixelCount width;
    size_t rowBytes;
} vImage_Buffer;

typedef struct Pixel_8888_s { Pixel_8888 val; } Pixel_8888_s;

typedef struct _vImage_CGImageFormat {
    uint32_t bitsPerComponent;
    uint32_t bitsPerPixel;
    CGColorSpaceRef colorSpace;
    CGBitmapInfo bitmapInfo;
    uint32_t version;
    const CGFloat* decode;
    CGColorRenderingIntent renderingIntent;
} vImage_CGImageFormat;

struct Pixel_888_s {
    uint8_t val[3];
};

ACCELERATE_EXPORT vImage_Error vImageBoxConvolve_ARGB8888(const vImage_Buffer* src,
                                                          const vImage_Buffer* dest,
                                                          void* tempBuffer,
                                                          vImagePixelCount srcOffsetToROI_X,
                                                          vImagePixelCount srcOffsetToROI_Y,
                                                          uint32_t kernel_height,
                                                          uint32_t kernel_width,
                                                          const Pixel_8888 backgroundColor,
                                                          vImage_Flags flags);

ACCELERATE_EXPORT vImage_Error vImageMatrixMultiply_ARGB8888(const vImage_Buffer* src,
                                                             const vImage_Buffer* dest,
                                                             const int16_t matrix[16],
                                                             int32_t divisor,
                                                             const int16_t* pre_bias_p,
                                                             const int32_t* post_bias_p,
                                                             vImage_Flags flags);

ACCELERATE_EXPORT vImage_Error vImageConvert_ARGB8888toPlanar8(const vImage_Buffer* srcARGB,
                                                               const vImage_Buffer* destA,
                                                               const vImage_Buffer* destR,
                                                               const vImage_Buffer* destG,
                                                               const vImage_Buffer* destB,
                                                               vImage_Flags flags);

// vImageConvert_BGRA8888toPlanar8 and vImageConvert_RGBA8888toPlanar8 have nearly identical functionality to
// vImageConvert_ARGB8888toPlanar8. The only difference is that the client swizzles the input so they can be
// safely aliased using _vImageFunctionInterfaceCvt8888ToPlanar8
typedef vImage_Error (*_vImageFunctionInterfaceCvt8888ToPlanar8)(
    const vImage_Buffer*, const vImage_Buffer*, const vImage_Buffer*, const vImage_Buffer*, const vImage_Buffer*, vImage_Flags);

ACCELERATE_EXPORT _vImageFunctionInterfaceCvt8888ToPlanar8 vImageConvert_BGRA8888toPlanar8;
ACCELERATE_EXPORT _vImageFunctionInterfaceCvt8888ToPlanar8 vImageConvert_RGBA8888toPlanar8;

ACCELERATE_EXPORT vImage_Error vImageConvert_Planar8toARGB8888(const vImage_Buffer* srcA,
                                                               const vImage_Buffer* srcR,
                                                               const vImage_Buffer* srcG,
                                                               const vImage_Buffer* srcB,
                                                               const vImage_Buffer* dest,
                                                               vImage_Flags flags);

ACCELERATE_EXPORT vImage_Error
vImageConvert_Planar8toPlanarF(const vImage_Buffer* src, const vImage_Buffer* dest, Pixel_F maxFloat, Pixel_F minFloat, vImage_Flags flags);

ACCELERATE_EXPORT vImage_Error vImageConvert_Planar8toRGB888(const vImage_Buffer* planarRed,
                                                             const vImage_Buffer* planarGreen,
                                                             const vImage_Buffer* planarBlue,
                                                             const vImage_Buffer* rgbDest,
                                                             vImage_Flags flags);

ACCELERATE_EXPORT vImage_Error
vImageConvert_PlanarFtoPlanar8(const vImage_Buffer* src, const vImage_Buffer* dest, Pixel_F maxFloat, Pixel_F minFloat, vImage_Flags flags);

ACCELERATE_EXPORT vImage_Error vImageUnpremultiplyData_RGBA8888(const vImage_Buffer* src, const vImage_Buffer* dest, vImage_Flags flags);

ACCELERATE_EXPORT vImage_Error vImageUnpremultiplyData_BGRA8888(const vImage_Buffer* src, const vImage_Buffer* dest, vImage_Flags flags);

ACCELERATE_EXPORT vImage_Error vImageUnpremultiplyData_ARGB8888(const vImage_Buffer* src, const vImage_Buffer* dest, vImage_Flags flags);

ACCELERATE_EXPORT vImage_Error
vImageBuffer_Init(vImage_Buffer* buffer, vImagePixelCount height, vImagePixelCount width, uint32_t bitsPerFragment, vImage_Flags flags);

static inline unsigned char _vImageClipConvertAndSaturateFloatToUint8(const Pixel_F val, const Pixel_F minFloat, const Pixel_F maxFloat) {
    if (val < minFloat) {
        return 0;
    } else if (val < maxFloat) {
        return (unsigned char)((val - minFloat) / (maxFloat - minFloat) * 255.0f);
    } else {
        return 255;
    }
}

static inline float _vImageMinFloat(const float val1, const float val2) {
    return ((val1 > val2) ? val2 : val1);
}

static inline float _vImageMaxFloat(const float val1, const float val2) {
    return ((val1 > val2) ? val1 : val2);
}

static inline unsigned char _vImageDivideAndSaturateUint8(const unsigned int val1, const unsigned int val2) {
    if (val2 == 0) {
        return 0;
    } else {
        return ((((val1 > val2) ? val2 : val1) * 255 + (val2 >> 1)) / val2);
    }
}

static inline Pixel_F _vImageConvertAndClampUint8ToFloat(const unsigned char val, const Pixel_F minFloat, const Pixel_F maxFloat) {
    return ((Pixel_F)(val) * (maxFloat - minFloat) / 255.0f + minFloat);
}

static inline size_t _vImageAlignSizeT(const size_t val, const size_t alignment) {
    return ((val + alignment - 1) & (~(alignment - 1)));
}

static inline uint32_t _vImageAlignUInt(const uint32_t val, const uint32_t alignment) {
    return ((val + alignment - 1) & (~(alignment - 1)));
}

static inline bool _vImageBitsPerComponentIsValidFromCgImage(const uint32_t bitsPerComp) {
    return (bitsPerComp == 0 || bitsPerComp == 1 || bitsPerComp == 2 || bitsPerComp == 4 || bitsPerComp == 5 || bitsPerComp == 8 ||
            bitsPerComp == 16 || bitsPerComp == 32);
}

static inline bool _vImageBitsPerComponentIsValidToCGImage(const uint32_t bitsPerComp) {
    return (bitsPerComp == 5 || bitsPerComp == 8 || bitsPerComp == 16 || bitsPerComp == 32);
}

ACCELERATE_EXPORT void _vImageSetSimdOptmizationsState(const bool newState);

#if defined(__clang__)
ACCELERATE_EXPORT vImage_Error vImageBuffer_InitWithCGImage(
    vImage_Buffer* destImageBuffer, const vImage_CGImageFormat* format, void* unknown, CGImageRef image, vImage_Flags flags);
ACCELERATE_EXPORT CGImageRef vImageCreateCGImageFromBuffer(vImage_Buffer* buffer,
                                                           vImage_CGImageFormat* format,
                                                           void* pCleanupFunction,
                                                           void* pCleanupFunctionParams,
                                                           vImage_Flags flags,
                                                           void* error);
#endif