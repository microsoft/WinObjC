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

#include <new>
#include "Accelerate\vImage.h"

/**
@Status Interoperable
*/

vImage_Error vImageBoxConvolve_ARGB8888(const vImage_Buffer* src,
                                        const vImage_Buffer* dest,
                                        void* tempBuffer,
                                        vImagePixelCount srcOffsetToROI_X,
                                        vImagePixelCount srcOffsetToROI_Y,
                                        uint32_t kernel_height,
                                        uint32_t kernel_width,
                                        const Pixel_8888 backgroundColor,
                                        vImage_Flags flags) {
    if (src == nullptr || dest == nullptr || src->data == nullptr || dest->data == nullptr) {
        return kvImageNullPointerArgument;
    } else if (!(kernel_height & kernel_width & 1)) {
        return kvImageInvalidKernelSize;
    } else if (srcOffsetToROI_X > src->width) {
        return kvImageInvalidOffset_X;
    } else if (srcOffsetToROI_Y > src->height) {
        return kvImageInvalidOffset_Y;
    } else if ((srcOffsetToROI_Y + dest->height > src->height) || (srcOffsetToROI_X + dest->width > src->width)) {
        return kvImageRoiLargerThanInputBuffer;
    } else if (!(flags & kvImageCopyInPlace) && !(flags & kvImageBackgroundColorFill) &&
               !(flags & kvImageEdgeExtend) && !(flags & kvImageTruncateKernel)) {
        return kvImageInvalidEdgeStyle;
    }

    const unsigned long maxVal = 2147483647;

    //  Caveat: We return kvImageInvalidParameter for height, width, srcOffsetToROI_X, and srcOffsetToROI_Y >=2^31
    //  For 32 bit OS, we don't expect size >= 2^31. Hence it is not supported in current release.
    //  TODO for 64-bit
    if (src->height > maxVal || src->width > maxVal || dest->height > maxVal || dest->width > maxVal
        || srcOffsetToROI_X > maxVal || srcOffsetToROI_Y > maxVal || kernel_height> maxVal || kernel_width > maxVal) {
        return kvImageInvalidParameter;
    }
    
    int KW_d2 = kernel_width / 2;
    int KH_d2 = kernel_height / 2;

    //  The following 4 variable denote the location of the first and last pixel to have the kernel
    //  completely overlapping with source image
    uint32_t start_i = 0;
    uint32_t start_j = 0;
    uint32_t end_i = dest->height - 1;
    uint32_t end_j = dest->width - 1;

    if (static_cast<int>(srcOffsetToROI_Y) < KH_d2) {
        start_i = KH_d2 - srcOffsetToROI_Y;
    }

    if (static_cast<int>(srcOffsetToROI_X) < KW_d2) {
        start_j = KW_d2 - srcOffsetToROI_X;
    }

    if (src->height < (srcOffsetToROI_Y + dest->height + KH_d2)) {
        end_i = src->height - srcOffsetToROI_Y - KH_d2 - 1;
    }

    if (src->width < (srcOffsetToROI_X + dest->width + KW_d2)) {
        end_j = src->width - srcOffsetToROI_X - KW_d2 - 1;
    }

    //  The following two variable denote the no of rows required for temporary storage for first pass
    //  above and below the RoI
    int top = KH_d2 - start_i;
    int below = end_i + 1 + KH_d2 - dest->height;

    //  returns the size of temporary buffer data
    if (flags & kvImageGetTempBufferSize) {
        return (dest->height + (top + below) * dest->width) * sizeof(Pixel_8888_s);
    }

    //  Pointer to access the temporary buffer data.
    Pixel_8888_s* temp_buf;
    bool tempBuffer_flag = 0;
    if (tempBuffer == nullptr) {
        temp_buf = new(std::nothrow) Pixel_8888_s[(dest->height + (top + below) * dest->width)];
        if (temp_buf == nullptr) {
            return kvImageMemoryAllocationError;
        }
        tempBuffer_flag = 1;
    } else {
        temp_buf = static_cast<Pixel_8888_s*>(tempBuffer);
    }

    uint32_t sum[4] = { 0 };
    uint32_t src_i;
    uint32_t src_j;
    Pixel_8888_s* src_buf = static_cast<Pixel_8888_s*>(src->data);
    Pixel_8888_s* dest_buf = static_cast<Pixel_8888_s*>(dest->data);
    size_t src_rowstride = src->rowBytes / sizeof(Pixel_8888);
    size_t dest_rowstride = dest->rowBytes / sizeof(Pixel_8888);

    //  This block deals with code for flag kvImageCopyInPlace, which require the pixel to be copied as is 
    //  from source image when the kernel does not overlap with the image data
    if (flags & kvImageCopyInPlace) {
        bool sum_flag = 0;

        //  First pass (horizontal)
        for (uint32_t i = 0; i < dest->height; ++i) {
            src_i = srcOffsetToROI_Y + i;
            src_j = srcOffsetToROI_X;
            sum_flag = 0;
            sum[0] = 0;
            sum[1] = 0;
            sum[2] = 0;
            sum[3] = 0;

            for (uint32_t j = 0; j < dest->width; ++j, src_j++) {

                //  Copying the pixel data as is from source for no kernel overlap section
                if (j < start_j || j > end_j) {
                    dest_buf[i * dest_rowstride + j] = src_buf[src_i * src_rowstride + src_j];
                } else {
                    if (sum_flag == 0) {
                        sum_flag = 1;
                        for (int k = -KW_d2; k <= KW_d2; ++k) {
                            sum[0] += src_buf[src_i * src_rowstride + src_j + k].val[0];
                            sum[1] += src_buf[src_i * src_rowstride + src_j + k].val[1];
                            sum[2] += src_buf[src_i * src_rowstride + src_j + k].val[2];
                            sum[3] += src_buf[src_i * src_rowstride + src_j + k].val[3];
                        }
                    } else {
                        sum[0] += -src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[0]
                            + src_buf[src_i * src_rowstride + src_j + KW_d2].val[0];
                        sum[1] += -src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[1]
                            + src_buf[src_i * src_rowstride + src_j + KW_d2].val[1];
                        sum[2] += -src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[2]
                            + src_buf[src_i * src_rowstride + src_j + KW_d2].val[2];
                        sum[3] += -src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[3]
                            + src_buf[src_i * src_rowstride + src_j + KW_d2].val[3];
                    }

                    dest_buf[i * dest_rowstride + j].val[0] = sum[0] > (255 * kernel_width) ? 255 : sum[0] / kernel_width;
                    dest_buf[i * dest_rowstride + j].val[1] = sum[1] > (255 * kernel_width) ? 255 : sum[1] / kernel_width;
                    dest_buf[i * dest_rowstride + j].val[2] = sum[2] > (255 * kernel_width) ? 255 : sum[2] / kernel_width;
                    dest_buf[i * dest_rowstride + j].val[3] = sum[3] > (255 * kernel_width) ? 255 : sum[3] / kernel_width;
                }
            }
        }

        //  first pass above("top") the RoI
        for (int i = start_i - KH_d2; i < 0; ++i) {
            src_i = srcOffsetToROI_Y + i;
            src_j = srcOffsetToROI_X;
            sum_flag = 0;
            sum[0] = 0;
            sum[1] = 0;
            sum[2] = 0;
            sum[3] = 0;

            for (uint32_t j = 0; j < dest->width; ++j, src_j++) {

                //  Copying the pixel data as is from source for no kernel overlap section
                if (j < start_j || j > end_j) {
                    temp_buf[(top + i)*dest_rowstride] = src_buf[src_i * src_rowstride + src_j];
                } else {
                    if (sum_flag == 0) {
                        sum_flag = 1;
                        for (int k = -KW_d2; k <= KW_d2; ++k) {
                            sum[0] += src_buf[src_i * src_rowstride + src_j + k].val[0];
                            sum[1] += src_buf[src_i * src_rowstride + src_j + k].val[1];
                            sum[2] += src_buf[src_i * src_rowstride + src_j + k].val[2];
                            sum[3] += src_buf[src_i * src_rowstride + src_j + k].val[3];
                        }
                    } else {
                        sum[0] = sum[0] - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[0]
                            + src_buf[src_i * src_rowstride + src_j + KW_d2].val[0];
                        sum[1] = sum[1] - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[1]
                            + src_buf[src_i * src_rowstride + src_j + KW_d2].val[1];
                        sum[2] = sum[2] - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[2]
                            + src_buf[src_i * src_rowstride + src_j + KW_d2].val[2];
                        sum[3] = sum[3] - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[3]
                            + src_buf[src_i * src_rowstride + src_j + KW_d2].val[3];
                    }

                    temp_buf[(top + i) * dest_rowstride + j].val[0] = sum[0] > (255 * kernel_width) ? 255 : sum[0] / kernel_width;
                    temp_buf[(top + i) * dest_rowstride + j].val[1] = sum[1] > (255 * kernel_width) ? 255 : sum[1] / kernel_width;
                    temp_buf[(top + i) * dest_rowstride + j].val[2] = sum[2] > (255 * kernel_width) ? 255 : sum[2] / kernel_width;
                    temp_buf[(top + i) * dest_rowstride + j].val[3] = sum[3] > (255 * kernel_width) ? 255 : sum[3] / kernel_width;
                }
            }
        }

        //  first pass below the RoI
        for (uint32_t i = dest->height; i <= end_i + KH_d2; ++i) {
            src_i = srcOffsetToROI_Y + i;
            src_j = srcOffsetToROI_X;
            sum_flag = 0;
            sum[0] = 0;
            sum[1] = 0;
            sum[2] = 0;
            sum[3] = 0;

            for (uint32_t j = 0; j < dest->width; ++j, src_j++) {

                //  Copying the pixel data as is from source for no kernel overlap section
                if (j < start_j || j > end_j) {
                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j] = src_buf[src_i * src_rowstride + src_j];
                } else {
                    if (sum_flag == 0) {
                        sum_flag = 1;
                        for (int k = -KW_d2; k <= KW_d2; ++k) {
                            sum[0] += src_buf[src_i * src_rowstride + src_j + k].val[0];
                            sum[1] += src_buf[src_i * src_rowstride + src_j + k].val[1];
                            sum[2] += src_buf[src_i * src_rowstride + src_j + k].val[2];
                            sum[3] += src_buf[src_i * src_rowstride + src_j + k].val[3];
                        }
                    } else {
                        sum[0] = sum[0] - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[0]
                            + src_buf[src_i * src_rowstride + src_j + KW_d2].val[0];
                        sum[1] = sum[1] - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[1]
                            + src_buf[src_i * src_rowstride + src_j + KW_d2].val[1];
                        sum[2] = sum[2] - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[2]
                            + src_buf[src_i * src_rowstride + src_j + KW_d2].val[2];
                        sum[3] = sum[3] - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[3]
                            + src_buf[src_i * src_rowstride + src_j + KW_d2].val[3];
                    }

                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j].val[0]
                        = sum[0] > (255 * kernel_width) ? 255 : sum[0] / kernel_width;
                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j].val[1]
                        = sum[1] > (255 * kernel_width) ? 255 : sum[1] / kernel_width;
                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j].val[2]
                        = sum[2] > (255 * kernel_width) ? 255 : sum[2] / kernel_width;
                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j].val[3]
                        = sum[3] > (255 * kernel_width) ? 255 : sum[3] / kernel_width;
                }
            }
        }

        //  Second pass (vertical)
        for (uint32_t j = start_j; j <= end_j; ++j) {
            sum_flag = 0;
            sum[0] = 0;
            sum[1] = 0;
            sum[2] = 0;
            sum[3] = 0;

            for (int i = start_i; i <= static_cast<int>(end_i); ++i) {
                if (sum_flag == 0) {
                    sum_flag = 1;
                    for (int k = -KH_d2; k <= KH_d2; ++k) {
                        if (i + k < 0) {
                            sum[0] += temp_buf[(top + (i + k)) * dest_rowstride + j].val[0];
                            sum[1] += temp_buf[(top + (i + k)) * dest_rowstride + j].val[1];
                            sum[2] += temp_buf[(top + (i + k)) * dest_rowstride + j].val[2];
                            sum[3] += temp_buf[(top + (i + k)) * dest_rowstride + j].val[3];
                        } else {
                            sum[0] += dest_buf[(i + k) * dest_rowstride + j].val[0];
                            sum[1] += dest_buf[(i + k) * dest_rowstride + j].val[1];
                            sum[2] += dest_buf[(i + k) * dest_rowstride + j].val[2];
                            sum[3] += dest_buf[(i + k) * dest_rowstride + j].val[3];
                        }
                    }
                } else {
                    if (i - KH_d2 - 1 < 0) {
                        sum[0] -= temp_buf[(top + (i - KH_d2 - 1)) * dest_rowstride + j].val[0];
                        sum[1] -= temp_buf[(top + (i - KH_d2 - 1)) * dest_rowstride + j].val[1];
                        sum[2] -= temp_buf[(top + (i - KH_d2 - 1)) * dest_rowstride + j].val[2];
                        sum[3] -= temp_buf[(top + (i - KH_d2 - 1)) * dest_rowstride + j].val[3];
                    } else {
                        sum[0] -= dest_buf[(i - KH_d2 - 1) * dest_rowstride + j].val[0];
                        sum[1] -= dest_buf[(i - KH_d2 - 1) * dest_rowstride + j].val[1];
                        sum[2] -= dest_buf[(i - KH_d2 - 1) * dest_rowstride + j].val[2];
                        sum[3] -= dest_buf[(i - KH_d2 - 1) * dest_rowstride + j].val[3];
                    }

                    if (i + KH_d2 >= static_cast<int>(dest->height)) {
                        sum[0] += temp_buf[(top + (i + KH_d2) - dest->height) * dest_rowstride + j].val[0];
                        sum[1] += temp_buf[(top + (i + KH_d2) - dest->height) * dest_rowstride + j].val[1];
                        sum[2] += temp_buf[(top + (i + KH_d2) - dest->height) * dest_rowstride + j].val[2];
                        sum[3] += temp_buf[(top + (i + KH_d2) - dest->height) * dest_rowstride + j].val[3];
                    } else {
                        sum[0] += dest_buf[(i + KH_d2) * dest_rowstride + j].val[0];
                        sum[1] += dest_buf[(i + KH_d2) * dest_rowstride + j].val[1];
                        sum[2] += dest_buf[(i + KH_d2) * dest_rowstride + j].val[2];
                        sum[3] += dest_buf[(i + KH_d2) * dest_rowstride + j].val[3];
                    }
                }

                temp_buf[(top + below) * dest_rowstride + i - start_i].val[0]
                    = sum[0] > (255 * kernel_height) ? 255 : sum[0] / kernel_height;
                temp_buf[(top + below) * dest_rowstride + i - start_i].val[1]
                    = sum[1] > (255 * kernel_height) ? 255 : sum[1] / kernel_height;
                temp_buf[(top + below) * dest_rowstride + i - start_i].val[2]
                    = sum[2] > (255 * kernel_height) ? 255 : sum[2] / kernel_height;
                temp_buf[(top + below) * dest_rowstride + i - start_i].val[3]
                    = sum[3] > (255 * kernel_height) ? 255 : sum[3] / kernel_height;
            }

            for (uint32_t i = start_i; i <= end_i; ++i) {
                dest_buf[i * dest_rowstride + j] = temp_buf[(top + below) * dest_rowstride + i - start_i];
            }
        }

        for (uint32_t i = 0; i < start_i; ++i) {
            src_i = srcOffsetToROI_Y + i;
            src_j = srcOffsetToROI_X + start_j;
            for (uint32_t j = start_j; j <= end_j; ++j, src_j++) {
                dest_buf[i * dest_rowstride + j] = src_buf[src_i * src_rowstride + src_j];
            }
        }

        for (uint32_t i = end_i + 1; i < dest->height; ++i) {
            src_i = srcOffsetToROI_Y + i;
            src_j = srcOffsetToROI_X + start_j;
            for (uint32_t j = start_j; j <= end_j; ++j, src_j++) {
                dest_buf[i * dest_rowstride + j] = src_buf[src_i * src_rowstride + src_j];
            }
        }
    }

    //  This block deals with code for flag kvImageTruncateKernel, which require the kernel to be truncated 
    //  when it does not overlap with the image data
    else if (flags & kvImageTruncateKernel) {
        uint32_t divisor;

        //  First pass (horizontal)
        for (int i = static_cast<int>(start_i) - KH_d2; i <= static_cast<int>(end_i) + KH_d2; ++i) {
            src_i = srcOffsetToROI_Y + i;
            src_j = srcOffsetToROI_X;
            sum[0] = 0;
            sum[1] = 0;
            sum[2] = 0;
            sum[3] = 0;
            divisor = kernel_width - start_j;

            for (int k = start_j - KW_d2; k <= KW_d2; ++k) {
                sum[0] += src_buf[src_i * src_rowstride + src_j + k].val[0];
                sum[1] += src_buf[src_i * src_rowstride + src_j + k].val[1];
                sum[2] += src_buf[src_i * src_rowstride + src_j + k].val[2];
                sum[3] += src_buf[src_i * src_rowstride + src_j + k].val[3];
            }

            if (i<0) {
                temp_buf[(top + i) * dest_rowstride].val[0] = sum[0] > (255 * divisor) ? 255 : sum[0] / divisor;
                temp_buf[(top + i) * dest_rowstride].val[1] = sum[1] > (255 * divisor) ? 255 : sum[1] / divisor;
                temp_buf[(top + i) * dest_rowstride].val[2] = sum[2] > (255 * divisor) ? 255 : sum[2] / divisor;
                temp_buf[(top + i) * dest_rowstride].val[3] = sum[3] > (255 * divisor) ? 255 : sum[3] / divisor;
            } else if (i >= static_cast<int>(dest->height)) {
                temp_buf[(top + (i - dest->height)) * dest_rowstride].val[0] = sum[0] > (255 * divisor) ? 255 : sum[0] / divisor;
                temp_buf[(top + (i - dest->height)) * dest_rowstride].val[1] = sum[1] > (255 * divisor) ? 255 : sum[1] / divisor;
                temp_buf[(top + (i - dest->height)) * dest_rowstride].val[2] = sum[2] > (255 * divisor) ? 255 : sum[2] / divisor;
                temp_buf[(top + (i - dest->height)) * dest_rowstride].val[3] = sum[3] > (255 * divisor) ? 255 : sum[3] / divisor;
            } else {
                dest_buf[i * dest_rowstride].val[0] = sum[0] > (255 * divisor) ? 255 : sum[0] / divisor;
                dest_buf[i * dest_rowstride].val[1] = sum[1] > (255 * divisor) ? 255 : sum[1] / divisor;
                dest_buf[i * dest_rowstride].val[2] = sum[2] > (255 * divisor) ? 255 : sum[2] / divisor;
                dest_buf[i * dest_rowstride].val[3] = sum[3] > (255 * divisor) ? 255 : sum[3] / divisor;
            }

            src_j++;

            for (uint32_t j = 1; j < dest->width; ++j, src_j++) {
                if (j <= start_j) {
                    divisor++;
                    sum[0] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[0];
                    sum[1] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[1];
                    sum[2] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[2];
                    sum[3] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[3];
                } else if (j <= end_j) {
                    sum[0] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[0]
                        - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[0];
                    sum[1] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[1]
                        - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[1];
                    sum[2] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[2]
                        - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[2];
                    sum[3] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[3]
                        - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[3];
                } else {
                    divisor--;
                    sum[0] -= src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[0];
                    sum[1] -= src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[1];
                    sum[2] -= src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[2];
                    sum[3] -= src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[3];
                }

                if (i < 0) {
                    temp_buf[(top + i) * dest_rowstride + j].val[0] = sum[0] > (255 * divisor) ? 255 : sum[0] / divisor;
                    temp_buf[(top + i) * dest_rowstride + j].val[1] = sum[1] > (255 * divisor) ? 255 : sum[1] / divisor;
                    temp_buf[(top + i) * dest_rowstride + j].val[2] = sum[2] > (255 * divisor) ? 255 : sum[2] / divisor;
                    temp_buf[(top + i) * dest_rowstride + j].val[3] = sum[3] > (255 * divisor) ? 255 : sum[3] / divisor;
                } else if (i >= static_cast<int>(dest->height)) {
                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j].val[0]
                        = sum[0] > (255 * divisor) ? 255 : sum[0] / divisor;
                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j].val[1]
                        = sum[1] > (255 * divisor) ? 255 : sum[1] / divisor;
                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j].val[2]
                        = sum[2] > (255 * divisor) ? 255 : sum[2] / divisor;
                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j].val[3]
                        = sum[3] > (255 * divisor) ? 255 : sum[3] / divisor;
                } else {
                    dest_buf[i * dest_rowstride + j].val[0] = sum[0] > (255 * divisor) ? 255 : sum[0] / divisor;
                    dest_buf[i * dest_rowstride + j].val[1] = sum[1] > (255 * divisor) ? 255 : sum[1] / divisor;
                    dest_buf[i * dest_rowstride + j].val[2] = sum[2] > (255 * divisor) ? 255 : sum[2] / divisor;
                    dest_buf[i * dest_rowstride + j].val[3] = sum[3] > (255 * divisor) ? 255 : sum[3] / divisor;
                }
            }
        }

        //  Second pass (vertical)
        for (uint32_t j = 0; j < dest->width; ++j) {
            sum[0] = 0;
            sum[1] = 0;
            sum[2] = 0;
            sum[3] = 0;
            divisor = kernel_height - start_i;

            for (int k = start_i - KH_d2; k < 0; ++k) {
                sum[0] += temp_buf[(top + k) * dest_rowstride + j].val[0];
                sum[1] += temp_buf[(top + k) * dest_rowstride + j].val[1];
                sum[2] += temp_buf[(top + k) * dest_rowstride + j].val[2];
                sum[3] += temp_buf[(top + k) * dest_rowstride + j].val[3];
            }

            for (int k = 0; k <= KH_d2; ++k) {
                sum[0] += dest_buf[k * dest_rowstride + j].val[0];
                sum[1] += dest_buf[k * dest_rowstride + j].val[1];
                sum[2] += dest_buf[k * dest_rowstride + j].val[2];
                sum[3] += dest_buf[k * dest_rowstride + j].val[3];
            }

            temp_buf[(top + below) * dest_rowstride].val[0] = sum[0] > (255 * divisor) ? 255 : sum[0] / divisor;
            temp_buf[(top + below) * dest_rowstride].val[1] = sum[1] > (255 * divisor) ? 255 : sum[1] / divisor;
            temp_buf[(top + below) * dest_rowstride].val[2] = sum[2] > (255 * divisor) ? 255 : sum[2] / divisor;
            temp_buf[(top + below) * dest_rowstride].val[3] = sum[3] > (255 * divisor) ? 255 : sum[3] / divisor;

            for (int i = 1; i < static_cast<int>(dest->height); ++i) {
                if (i > static_cast<int>(start_i)) {
                    divisor--;
                    if (i - KH_d2 - 1 < 0) {
                        sum[0] -= temp_buf[(top + (i - KH_d2 - 1)) * dest_rowstride + j].val[0];
                        sum[1] -= temp_buf[(top + (i - KH_d2 - 1)) * dest_rowstride + j].val[1];
                        sum[2] -= temp_buf[(top + (i - KH_d2 - 1)) * dest_rowstride + j].val[2];
                        sum[3] -= temp_buf[(top + (i - KH_d2 - 1)) * dest_rowstride + j].val[3];
                    } else {
                        sum[0] -= dest_buf[(i - KH_d2 - 1) * dest_rowstride + j].val[0];
                        sum[1] -= dest_buf[(i - KH_d2 - 1) * dest_rowstride + j].val[1];
                        sum[2] -= dest_buf[(i - KH_d2 - 1) * dest_rowstride + j].val[2];
                        sum[3] -= dest_buf[(i - KH_d2 - 1) * dest_rowstride + j].val[3];
                    }
                }

                if (i <= static_cast<int>(end_i)) {
                    divisor++;
                    if (i + KH_d2 >= static_cast<int>(dest->height)) {
                        sum[0] += temp_buf[(top + (i + KH_d2) - dest->height) * dest_rowstride + j].val[0];
                        sum[1] += temp_buf[(top + (i + KH_d2) - dest->height) * dest_rowstride + j].val[1];
                        sum[2] += temp_buf[(top + (i + KH_d2) - dest->height) * dest_rowstride + j].val[2];
                        sum[3] += temp_buf[(top + (i + KH_d2) - dest->height) * dest_rowstride + j].val[3];
                    } else {
                        sum[0] += dest_buf[(i + KH_d2) * dest_rowstride + j].val[0];
                        sum[1] += dest_buf[(i + KH_d2) * dest_rowstride + j].val[1];
                        sum[2] += dest_buf[(i + KH_d2) * dest_rowstride + j].val[2];
                        sum[3] += dest_buf[(i + KH_d2) * dest_rowstride + j].val[3];
                    }
                }

                temp_buf[(top + below) * dest_rowstride + i].val[0] = sum[0] > (255 * divisor) ? 255 : sum[0] / divisor;
                temp_buf[(top + below) * dest_rowstride + i].val[1] = sum[1] > (255 * divisor) ? 255 : sum[1] / divisor;
                temp_buf[(top + below) * dest_rowstride + i].val[2] = sum[2] > (255 * divisor) ? 255 : sum[2] / divisor;
                temp_buf[(top + below) * dest_rowstride + i].val[3] = sum[3] > (255 * divisor) ? 255 : sum[3] / divisor;
            }

            for (uint32_t i = 0; i < dest->height; ++i) {
                dest_buf[i * dest_rowstride + j] = temp_buf[(top + below) * dest_rowstride + i];
            }
        }
    }

    //  This block deals with code for flag kvImageBackgroundColorFill, which requires all pixels outside image to be  
    //  set to the parameter backgroundColor
    else if (flags & kvImageBackgroundColorFill) {
        
        if (backgroundColor == nullptr) {
            return kvImageNullPointerArgument;
        }

        //  First pass (horizontal)
        for (int i = static_cast<int>(start_i) - KH_d2; i <= static_cast<int>(end_i) + KH_d2; ++i) {
            src_i = srcOffsetToROI_Y + i;
            src_j = srcOffsetToROI_X;
            sum[0] = backgroundColor[0] * start_j;
            sum[1] = backgroundColor[1] * start_j;
            sum[2] = backgroundColor[2] * start_j;
            sum[3] = backgroundColor[3] * start_j;

            for (int k = start_j - KW_d2; k <= KW_d2; ++k) {
                sum[0] += src_buf[src_i * src_rowstride + src_j + k].val[0];
                sum[1] += src_buf[src_i * src_rowstride + src_j + k].val[1];
                sum[2] += src_buf[src_i * src_rowstride + src_j + k].val[2];
                sum[3] += src_buf[src_i * src_rowstride + src_j + k].val[3];
            }

            if (i<0) {
                temp_buf[(top + i) * dest_rowstride].val[0] = sum[0] > (255 * kernel_width) ? 255 : sum[0] / kernel_width;
                temp_buf[(top + i) * dest_rowstride].val[1] = sum[1] > (255 * kernel_width) ? 255 : sum[1] / kernel_width;
                temp_buf[(top + i) * dest_rowstride].val[2] = sum[2] > (255 * kernel_width) ? 255 : sum[2] / kernel_width;
                temp_buf[(top + i) * dest_rowstride].val[3] = sum[3] > (255 * kernel_width) ? 255 : sum[3] / kernel_width;
            } else if (i >= static_cast<int>(dest->height)) {
                temp_buf[(top + (i - dest->height)) * dest_rowstride].val[0]
                    = sum[0] > (255 * kernel_width) ? 255 : sum[0] / kernel_width;
                temp_buf[(top + (i - dest->height)) * dest_rowstride].val[1]
                    = sum[1] > (255 * kernel_width) ? 255 : sum[1] / kernel_width;
                temp_buf[(top + (i - dest->height)) * dest_rowstride].val[2]
                    = sum[2] > (255 * kernel_width) ? 255 : sum[2] / kernel_width;
                temp_buf[(top + (i - dest->height)) * dest_rowstride].val[3]
                    = sum[3] > (255 * kernel_width) ? 255 : sum[3] / kernel_width;
            } else {
                dest_buf[i * dest_rowstride].val[0] = sum[0] > (255 * kernel_width) ? 255 : sum[0] / kernel_width;
                dest_buf[i * dest_rowstride].val[1] = sum[1] > (255 * kernel_width) ? 255 : sum[1] / kernel_width;
                dest_buf[i * dest_rowstride].val[2] = sum[2] > (255 * kernel_width) ? 255 : sum[2] / kernel_width;
                dest_buf[i * dest_rowstride].val[3] = sum[3] > (255 * kernel_width) ? 255 : sum[3] / kernel_width;
            }

            src_j++;

            for (uint32_t j = 1; j < dest->width; ++j, src_j++) {
                if (j <= start_j) {
                    sum[0] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[0] - backgroundColor[0];
                    sum[1] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[1] - backgroundColor[1];
                    sum[2] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[2] - backgroundColor[2];
                    sum[3] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[3] - backgroundColor[3];
                } else if (j <= end_j) {
                    sum[0] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[0]
                        - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[0];
                    sum[1] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[1]
                        - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[1];
                    sum[2] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[2]
                        - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[2];
                    sum[3] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[3]
                        - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[3];
                } else {
                    sum[0] += -src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[0] + backgroundColor[0];
                    sum[1] += -src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[1] + backgroundColor[1];
                    sum[2] += -src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[2] + backgroundColor[2];
                    sum[3] += -src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[3] + backgroundColor[3];
                }

                if (i < 0) {
                    temp_buf[(top + i) * dest_rowstride + j].val[0] = sum[0] > (255 * kernel_width) ? 255 : sum[0] / kernel_width;
                    temp_buf[(top + i) * dest_rowstride + j].val[1] = sum[1] > (255 * kernel_width) ? 255 : sum[1] / kernel_width;
                    temp_buf[(top + i) * dest_rowstride + j].val[2] = sum[2] > (255 * kernel_width) ? 255 : sum[2] / kernel_width;
                    temp_buf[(top + i) * dest_rowstride + j].val[3] = sum[3] > (255 * kernel_width) ? 255 : sum[3] / kernel_width;
                } else if (i >= static_cast<int>(dest->height)) {
                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j].val[0]
                        = sum[0] > (255 * kernel_width) ? 255 : sum[0] / kernel_width;
                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j].val[1]
                        = sum[1] > (255 * kernel_width) ? 255 : sum[1] / kernel_width;
                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j].val[2]
                        = sum[2] > (255 * kernel_width) ? 255 : sum[2] / kernel_width;
                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j].val[3]
                        = sum[3] > (255 * kernel_width) ? 255 : sum[3] / kernel_width;
                } else {
                    dest_buf[i * dest_rowstride + j].val[0] = sum[0] > (255 * kernel_width) ? 255 : sum[0] / kernel_width;
                    dest_buf[i * dest_rowstride + j].val[1] = sum[1] > (255 * kernel_width) ? 255 : sum[1] / kernel_width;
                    dest_buf[i * dest_rowstride + j].val[2] = sum[2] > (255 * kernel_width) ? 255 : sum[2] / kernel_width;
                    dest_buf[i * dest_rowstride + j].val[3] = sum[3] > (255 * kernel_width) ? 255 : sum[3] / kernel_width;
                }
            }
        }

        //  Second pass (vertical)
        for (uint32_t j = 0; j < dest->width; ++j) {
            sum[0] = backgroundColor[0] * start_i;
            sum[1] = backgroundColor[1] * start_i;
            sum[2] = backgroundColor[2] * start_i;
            sum[3] = backgroundColor[3] * start_i;

            for (int k = start_i - KH_d2; k < 0; ++k) {
                sum[0] += temp_buf[(top + k) * dest_rowstride + j].val[0];
                sum[1] += temp_buf[(top + k) * dest_rowstride + j].val[1];
                sum[2] += temp_buf[(top + k) * dest_rowstride + j].val[2];
                sum[3] += temp_buf[(top + k) * dest_rowstride + j].val[3];
            }

            for (int k = 0; k <= KH_d2; ++k) {
                sum[0] += dest_buf[k * dest_rowstride + j].val[0];
                sum[1] += dest_buf[k * dest_rowstride + j].val[1];
                sum[2] += dest_buf[k * dest_rowstride + j].val[2];
                sum[3] += dest_buf[k * dest_rowstride + j].val[3];
            }

            temp_buf[(top + below) * dest_rowstride].val[0] = sum[0] > (255 * kernel_height) ? 255 : sum[0] / kernel_height;
            temp_buf[(top + below) * dest_rowstride].val[1] = sum[1] > (255 * kernel_height) ? 255 : sum[1] / kernel_height;
            temp_buf[(top + below) * dest_rowstride].val[2] = sum[2] > (255 * kernel_height) ? 255 : sum[2] / kernel_height;
            temp_buf[(top + below) * dest_rowstride].val[3] = sum[3] > (255 * kernel_height) ? 255 : sum[3] / kernel_height;

            for (int i = 1; i < static_cast<int>(dest->height); ++i) {
                if (i <= static_cast<int>(start_i)) {
                    sum[0] -= backgroundColor[0];
                    sum[1] -= backgroundColor[1];
                    sum[2] -= backgroundColor[2];
                    sum[3] -= backgroundColor[3];
                } else if (i <= KH_d2) {
                    sum[0] -= temp_buf[(top + (i - KH_d2 - 1)) * dest_rowstride + j].val[0];
                    sum[1] -= temp_buf[(top + (i - KH_d2 - 1)) * dest_rowstride + j].val[1];
                    sum[2] -= temp_buf[(top + (i - KH_d2 - 1)) * dest_rowstride + j].val[2];
                    sum[3] -= temp_buf[(top + (i - KH_d2 - 1)) * dest_rowstride + j].val[3];
                } else {
                    sum[0] -= dest_buf[(i - KH_d2 - 1) * dest_rowstride + j].val[0];
                    sum[1] -= dest_buf[(i - KH_d2 - 1) * dest_rowstride + j].val[1];
                    sum[2] -= dest_buf[(i - KH_d2 - 1) * dest_rowstride + j].val[2];
                    sum[3] -= dest_buf[(i - KH_d2 - 1) * dest_rowstride + j].val[3];
                }

                if (i > static_cast<int>(end_i)) {
                    sum[0] += backgroundColor[0];
                    sum[1] += backgroundColor[1];
                    sum[2] += backgroundColor[2];
                    sum[3] += backgroundColor[3];
                } else if (i >= static_cast<int>(dest->height) - KH_d2) {
                    sum[0] += temp_buf[(top + (i + KH_d2) - dest->height) * dest_rowstride + j].val[0];
                    sum[1] += temp_buf[(top + (i + KH_d2) - dest->height) * dest_rowstride + j].val[1];
                    sum[2] += temp_buf[(top + (i + KH_d2) - dest->height) * dest_rowstride + j].val[2];
                    sum[3] += temp_buf[(top + (i + KH_d2) - dest->height) * dest_rowstride + j].val[3];
                } else {
                    sum[0] += dest_buf[(i + KH_d2) * dest_rowstride + j].val[0];
                    sum[1] += dest_buf[(i + KH_d2) * dest_rowstride + j].val[1];
                    sum[2] += dest_buf[(i + KH_d2) * dest_rowstride + j].val[2];
                    sum[3] += dest_buf[(i + KH_d2) * dest_rowstride + j].val[3];
                }

                temp_buf[(top + below) * dest_rowstride + i].val[0] = sum[0] > (255 * kernel_height) ? 255 : sum[0] / kernel_height;
                temp_buf[(top + below) * dest_rowstride + i].val[1] = sum[1] > (255 * kernel_height) ? 255 : sum[1] / kernel_height;
                temp_buf[(top + below) * dest_rowstride + i].val[2] = sum[2] > (255 * kernel_height) ? 255 : sum[2] / kernel_height;
                temp_buf[(top + below) * dest_rowstride + i].val[3] = sum[3] > (255 * kernel_height) ? 255 : sum[3] / kernel_height;
            }

            for (uint32_t i = 0; i < dest->height; ++i) {
                dest_buf[i * dest_rowstride + j] = temp_buf[(top + below) * dest_rowstride + i];
            }
        }
    }

    //  This block deals with code for flag kvImageEdgeExtend, which requires all pixels outside image to be  
    //  replicated by the edges of the image outwards.
    else if (flags & kvImageEdgeExtend) {

        //  For storing the first and the last pixel if the image is to be extended
        Pixel_8888_s first_pixel;
        Pixel_8888_s last_pixel;

        //  First pass (horizontal)
        for (int i = static_cast<int>(start_i) - KH_d2; i <= static_cast<int>(end_i) + KH_d2; ++i) {
            src_i = srcOffsetToROI_Y + i;
            src_j = srcOffsetToROI_X;
            first_pixel = src_buf[src_i * src_rowstride + src_j + (start_j - KW_d2)];
            last_pixel = src_buf[src_i * src_rowstride + src_j + end_j + KW_d2];
            sum[0] = first_pixel.val[0] * start_j;
            sum[1] = first_pixel.val[1] * start_j;
            sum[2] = first_pixel.val[2] * start_j;
            sum[3] = first_pixel.val[3] * start_j;

            for (int k = start_j - KW_d2; k <= KW_d2; ++k) {
                sum[0] += src_buf[src_i * src_rowstride + src_j + k].val[0];
                sum[1] += src_buf[src_i * src_rowstride + src_j + k].val[1];
                sum[2] += src_buf[src_i * src_rowstride + src_j + k].val[2];
                sum[3] += src_buf[src_i * src_rowstride + src_j + k].val[3];
            }

            if (i<0) {
                temp_buf[(top + i) * dest_rowstride].val[0] = sum[0] > (255 * kernel_width) ? 255 : sum[0] / kernel_width;
                temp_buf[(top + i) * dest_rowstride].val[1] = sum[1] > (255 * kernel_width) ? 255 : sum[1] / kernel_width;
                temp_buf[(top + i) * dest_rowstride].val[2] = sum[2] > (255 * kernel_width) ? 255 : sum[2] / kernel_width;
                temp_buf[(top + i) * dest_rowstride].val[3] = sum[3] > (255 * kernel_width) ? 255 : sum[3] / kernel_width;
            } else if (i >= static_cast<int>(dest->height)) {
                temp_buf[(top + (i - dest->height)) * dest_rowstride].val[0]
                    = sum[0] > (255 * kernel_width) ? 255 : sum[0] / kernel_width;
                temp_buf[(top + (i - dest->height)) * dest_rowstride].val[1]
                    = sum[1] > (255 * kernel_width) ? 255 : sum[1] / kernel_width;
                temp_buf[(top + (i - dest->height)) * dest_rowstride].val[2]
                    = sum[2] > (255 * kernel_width) ? 255 : sum[2] / kernel_width;
                temp_buf[(top + (i - dest->height)) * dest_rowstride].val[3]
                    = sum[3] > (255 * kernel_width) ? 255 : sum[3] / kernel_width;
            } else {
                dest_buf[i * dest_rowstride].val[0] = sum[0] > (255 * kernel_width) ? 255 : sum[0] / kernel_width;
                dest_buf[i * dest_rowstride].val[1] = sum[1] > (255 * kernel_width) ? 255 : sum[1] / kernel_width;
                dest_buf[i * dest_rowstride].val[2] = sum[2] > (255 * kernel_width) ? 255 : sum[2] / kernel_width;
                dest_buf[i * dest_rowstride].val[3] = sum[3] > (255 * kernel_width) ? 255 : sum[3] / kernel_width;
            }

            src_j++;

            for (uint32_t j = 1; j < dest->width; ++j, src_j++) {
                if (j <= start_j) {
                    sum[0] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[0] - first_pixel.val[0];
                    sum[1] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[1] - first_pixel.val[1];
                    sum[2] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[2] - first_pixel.val[2];
                    sum[3] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[3] - first_pixel.val[3];
                } else if (j <= end_j) {
                    sum[0] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[0]
                        - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[0];
                    sum[1] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[1]
                        - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[1];
                    sum[2] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[2]
                        - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[2];
                    sum[3] += src_buf[src_i * src_rowstride + src_j + KW_d2].val[3]
                       - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[3];
                } else {
                    sum[0] += last_pixel.val[0] - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[0];
                    sum[1] += last_pixel.val[1] - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[1];
                    sum[2] += last_pixel.val[2] - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[2];
                    sum[3] += last_pixel.val[3] - src_buf[src_i * src_rowstride + src_j - KW_d2 - 1].val[3];
                }

                if (i < 0) {
                    temp_buf[(top + i) * dest_rowstride + j].val[0] = sum[0] > (255 * kernel_width) ? 255 : sum[0] / kernel_width;
                    temp_buf[(top + i) * dest_rowstride + j].val[1] = sum[1] > (255 * kernel_width) ? 255 : sum[1] / kernel_width;
                    temp_buf[(top + i) * dest_rowstride + j].val[2] = sum[2] > (255 * kernel_width) ? 255 : sum[2] / kernel_width;
                    temp_buf[(top + i) * dest_rowstride + j].val[3] = sum[3] > (255 * kernel_width) ? 255 : sum[3] / kernel_width;
                } else if (i >= static_cast<int>(dest->height)) {
                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j].val[0]
                        = sum[0] > (255 * kernel_width) ? 255 : sum[0] / kernel_width;
                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j].val[1]
                        = sum[1] > (255 * kernel_width) ? 255 : sum[1] / kernel_width;
                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j].val[2]
                        = sum[2] > (255 * kernel_width) ? 255 : sum[2] / kernel_width;
                    temp_buf[(top + (i - dest->height)) * dest_rowstride + j].val[3]
                        = sum[3] > (255 * kernel_width) ? 255 : sum[3] / kernel_width;
                } else {
                    dest_buf[i * dest_rowstride + j].val[0] = sum[0] > (255 * kernel_width) ? 255 : sum[0] / kernel_width;
                    dest_buf[i * dest_rowstride + j].val[1] = sum[1] > (255 * kernel_width) ? 255 : sum[1] / kernel_width;
                    dest_buf[i * dest_rowstride + j].val[2] = sum[2] > (255 * kernel_width) ? 255 : sum[2] / kernel_width;
                    dest_buf[i * dest_rowstride + j].val[3] = sum[3] > (255 * kernel_width) ? 255 : sum[3] / kernel_width;
                }
            }
        }

        //  Second pass (vertical)
        for (uint32_t j = 0; j < dest->width; ++j) {
            if (top > 0) {
                first_pixel = temp_buf[j];
            } else {
                first_pixel = dest_buf[j];
            }

            if (below > 0) {
                last_pixel = temp_buf[(top + below - 1) * dest_rowstride + j];
            } else {
                last_pixel = dest_buf[(dest->height - 1) * dest_rowstride + j];
            }

            sum[0] = first_pixel.val[0] * start_i;
            sum[1] = first_pixel.val[1] * start_i;
            sum[2] = first_pixel.val[2] * start_i;
            sum[3] = first_pixel.val[3] * start_i;

            for (int k = start_i - KH_d2; k < 0; ++k) {
                sum[0] += temp_buf[(top + k) * dest_rowstride + j].val[0];
                sum[1] += temp_buf[(top + k) * dest_rowstride + j].val[1];
                sum[2] += temp_buf[(top + k) * dest_rowstride + j].val[2];
                sum[3] += temp_buf[(top + k) * dest_rowstride + j].val[3];
            }

            for (int k = 0; k <= KH_d2; ++k) {
                sum[0] += dest_buf[k * dest_rowstride + j].val[0];
                sum[1] += dest_buf[k * dest_rowstride + j].val[1];
                sum[2] += dest_buf[k * dest_rowstride + j].val[2];
                sum[3] += dest_buf[k * dest_rowstride + j].val[3];
            }

            temp_buf[(top + below) * dest_rowstride].val[0] = sum[0] > (255 * kernel_height) ? 255 : sum[0] / kernel_height;
            temp_buf[(top + below) * dest_rowstride].val[1] = sum[1] > (255 * kernel_height) ? 255 : sum[1] / kernel_height;
            temp_buf[(top + below) * dest_rowstride].val[2] = sum[2] > (255 * kernel_height) ? 255 : sum[2] / kernel_height;
            temp_buf[(top + below) * dest_rowstride].val[3] = sum[3] > (255 * kernel_height) ? 255 : sum[3] / kernel_height;

            for (int i = 1; i < static_cast<int>(dest->height); ++i) {
                if (i <= static_cast<int>(start_i)) {
                    sum[0] -= first_pixel.val[0];
                    sum[1] -= first_pixel.val[1];
                    sum[2] -= first_pixel.val[2];
                    sum[3] -= first_pixel.val[3];
                } else if (i <= KH_d2) {
                    sum[0] -= temp_buf[(top + (i - KH_d2 - 1)) * dest_rowstride + j].val[0];
                    sum[1] -= temp_buf[(top + (i - KH_d2 - 1)) * dest_rowstride + j].val[1];
                    sum[2] -= temp_buf[(top + (i - KH_d2 - 1)) * dest_rowstride + j].val[2];
                    sum[3] -= temp_buf[(top + (i - KH_d2 - 1)) * dest_rowstride + j].val[3];
                } else {
                    sum[0] -= dest_buf[(i - KH_d2 - 1) * dest_rowstride + j].val[0];
                    sum[1] -= dest_buf[(i - KH_d2 - 1) * dest_rowstride + j].val[1];
                    sum[2] -= dest_buf[(i - KH_d2 - 1) * dest_rowstride + j].val[2];
                    sum[3] -= dest_buf[(i - KH_d2 - 1) * dest_rowstride + j].val[3];
                }

                if (i > static_cast<int>(end_i)) {
                    sum[0] += last_pixel.val[0];
                    sum[1] += last_pixel.val[1];
                    sum[2] += last_pixel.val[2];
                    sum[3] += last_pixel.val[3];
                } else if (i >= static_cast<int>(dest->height) - KH_d2) {
                    sum[0] += temp_buf[(top + (i + KH_d2) - dest->height) * dest_rowstride + j].val[0];
                    sum[1] += temp_buf[(top + (i + KH_d2) - dest->height) * dest_rowstride + j].val[1];
                    sum[2] += temp_buf[(top + (i + KH_d2) - dest->height) * dest_rowstride + j].val[2];
                    sum[3] += temp_buf[(top + (i + KH_d2) - dest->height) * dest_rowstride + j].val[3];
                } else {
                    sum[0] += dest_buf[(i + KH_d2) * dest_rowstride + j].val[0];
                    sum[1] += dest_buf[(i + KH_d2) * dest_rowstride + j].val[1];
                    sum[2] += dest_buf[(i + KH_d2) * dest_rowstride + j].val[2];
                    sum[3] += dest_buf[(i + KH_d2) * dest_rowstride + j].val[3];
                }

                temp_buf[(top + below) * dest_rowstride + i].val[0] = sum[0] > (255 * kernel_height) ? 255 : sum[0] / kernel_height;
                temp_buf[(top + below) * dest_rowstride + i].val[1] = sum[1] > (255 * kernel_height) ? 255 : sum[1] / kernel_height;
                temp_buf[(top + below) * dest_rowstride + i].val[2] = sum[2] > (255 * kernel_height) ? 255 : sum[2] / kernel_height;
                temp_buf[(top + below) * dest_rowstride + i].val[3] = sum[3] > (255 * kernel_height) ? 255 : sum[3] / kernel_height;
            }

            for (uint32_t i = 0; i < dest->height; ++i) {
                dest_buf[i * dest_rowstride + j] = temp_buf[(top + below) * dest_rowstride + i];
            }
        }
    } else {
        return kvImageUnknownFlagsBit;
    }

    //  Deallocating the temporary buffer
    if (tempBuffer_flag == 1) {
        delete[] temp_buf;
    }

    return kvImageNoError;
}


vImage_Error vImageMatrixMultiply_ARGB8888(const vImage_Buffer* src,
                                           const vImage_Buffer* dest,
                                           const int16_t matrix[16],
                                           int32_t divisor,
                                           const int16_t* pre_bias_p,
                                           const int32_t* post_bias_p,
                                           vImage_Flags flags) {
    int32_t m00 = matrix[0];
    int32_t m01 = matrix[1];
    int32_t m02 = matrix[2];
    int32_t m03 = matrix[3];
    int32_t m10 = matrix[4];
    int32_t m11 = matrix[5];
    int32_t m12 = matrix[6];
    int32_t m13 = matrix[7];
    int32_t m20 = matrix[8];
    int32_t m21 = matrix[9];
    int32_t m22 = matrix[10];
    int32_t m23 = matrix[11];
    int32_t m30 = matrix[12];
    int32_t m31 = matrix[13];
    int32_t m32 = matrix[14];
    int32_t m33 = matrix[15];
    int32_t post_b0 = post_bias_p ? post_bias_p[0] : 0;
    int32_t post_b1 = post_bias_p ? post_bias_p[1] : 0;
    int32_t post_b2 = post_bias_p ? post_bias_p[2] : 0;
    int32_t post_b3 = post_bias_p ? post_bias_p[3] : 0;
    vImagePixelCount height = src->height;
    vImagePixelCount width = src->width;
    const Pixel_8888_s* in = static_cast<Pixel_8888_s*>(src->data);
    size_t in_rowstride = src->rowBytes / sizeof(Pixel_8888);
    Pixel_8888_s* out = static_cast<Pixel_8888_s*>(dest->data);
    size_t out_rowstride = dest->rowBytes / sizeof(Pixel_8888);

    if (!in || !out) {
        return kvImageNullPointerArgument;
    } else if (height != dest->height || width != dest->width) {
        return kvImageInvalidParameter;
    }

    if (pre_bias_p) {
        int32_t pre_b0 = pre_bias_p[0];
        int32_t pre_b1 = pre_bias_p[1];
        int32_t pre_b2 = pre_bias_p[2];
        int32_t pre_b3 = pre_bias_p[3];

        for (vImagePixelCount i = 0; i < height; ++i) {

            for (vImagePixelCount j = 0; j < width; ++j) {
                struct Pixel_8888_s pixel = in[i * in_rowstride + j];
                int32_t prod[4];
                pixel.val[0] += pre_b0;
                pixel.val[1] += pre_b1;
                pixel.val[2] += pre_b2;
                pixel.val[3] += pre_b3;
                prod[0] = pixel.val[0] * m00 + pixel.val[1] * m10 + pixel.val[2] * m20 + pixel.val[3] * m30 + post_b0;
                prod[1] = pixel.val[0] * m01 + pixel.val[1] * m11 + pixel.val[2] * m21 + pixel.val[3] * m31 + post_b1;
                prod[2] = pixel.val[0] * m02 + pixel.val[1] * m12 + pixel.val[2] * m22 + pixel.val[3] * m32 + post_b2;
                prod[3] = pixel.val[0] * m03 + pixel.val[1] * m13 + pixel.val[2] * m23 + pixel.val[3] * m33 + post_b3;

                if (divisor != 1) {
                    prod[0] /= divisor;
                    prod[1] /= divisor;
                    prod[2] /= divisor;
                    prod[3] /= divisor;
                }

                pixel.val[0] = prod[0] > 255 ? 255 : prod[0] < 0 ? 0 : prod[0];
                pixel.val[1] = prod[1] > 255 ? 255 : prod[1] < 0 ? 0 : prod[1];
                pixel.val[2] = prod[2] > 255 ? 255 : prod[2] < 0 ? 0 : prod[2];
                pixel.val[3] = prod[3] > 255 ? 255 : prod[3] < 0 ? 0 : prod[3];

                out[i * out_rowstride + j] = pixel;
            }
        }
    } else {

        for (vImagePixelCount i = 0; i < height; ++i) {

            for (vImagePixelCount j = 0; j < width; ++j) {
                struct Pixel_8888_s pixel = in[i * in_rowstride + j];
                int32_t prod[4];
                prod[0] = pixel.val[0] * m00 + pixel.val[1] * m10 + pixel.val[2] * m20 + pixel.val[3] * m30 + post_b0;
                prod[1] = pixel.val[0] * m01 + pixel.val[1] * m11 + pixel.val[2] * m21 + pixel.val[3] * m31 + post_b1;
                prod[2] = pixel.val[0] * m02 + pixel.val[1] * m12 + pixel.val[2] * m22 + pixel.val[3] * m32 + post_b2;
                prod[3] = pixel.val[0] * m03 + pixel.val[1] * m13 + pixel.val[2] * m23 + pixel.val[3] * m33 + post_b3;

                if (divisor != 1) {
                    prod[0] /= divisor;
                    prod[1] /= divisor;
                    prod[2] /= divisor;
                    prod[3] /= divisor;
                }

                pixel.val[0] = prod[0] > 255 ? 255 : prod[0] < 0 ? 0 : prod[0];
                pixel.val[1] = prod[1] > 255 ? 255 : prod[1] < 0 ? 0 : prod[1];
                pixel.val[2] = prod[2] > 255 ? 255 : prod[2] < 0 ? 0 : prod[2];
                pixel.val[3] = prod[3] > 255 ? 255 : prod[3] < 0 ? 0 : prod[3];

                out[i * out_rowstride + j] = pixel;
            }
        }
    }

    return kvImageNoError;
}