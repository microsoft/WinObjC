//******************************************************************************
//
// Copyright (c) 2016, Intel Corporation
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

#include <inttypes.h>
#include <BaseTsd.h>
#include "AccelerateExport.h"

enum
{
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
    kvImageUnknownFlagsBit = -21775
};

enum
{
    kvImageNoFlags = 0,
    kvImageLeaveAlphaUnchanged = 1,
    kvImageCopyInPlace = 2,
    kvImageBackgroundColorFill = 4,
    kvImageEdgeExtend = 8,
    kvImageDoNotTile = 16,
    kvImageHighQualityResampling = 32,
    kvImageTruncateKernel = 64,
    kvImageGetTempBufferSize = 128
};

typedef unsigned long vImagePixelCount;

typedef struct {
    void* data;
    vImagePixelCount height;
    vImagePixelCount width;
    size_t rowBytes;
} vImage_Buffer;

typedef SSIZE_T vImage_Error;

typedef uint32_t vImage_Flags;

typedef uint8_t Pixel_8888[4];

typedef struct Pixel_8888_s {
    Pixel_8888 val;
} Pixel_8888_s;

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