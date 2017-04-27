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

#import "Starboard.h"
#include "Accelerate/AccelerateExport.h"
#import <Accelerate/Accelerate.h>
#import <CoreGraphics/CGImage.h>
#import <CoreGraphics/CoreGraphics.h>
#import "CoreGraphics/CGDataProvider.h"
#import "CGDataProviderInternal.h"
#import <Foundation/Foundation.h>

static const wchar_t* TAG = L"vImage";

/**
@Status Caveat
@Notes BitmapInfo, ColorSpace, flags and freeing function ignored
*/
vImage_Error vImageBuffer_InitWithCGImage(
    vImage_Buffer* buffer, const vImage_CGImageFormat* format, void* unknown, CGImageRef image, vImage_Flags flags) {
    // Check for fatal errors
    if (buffer == nullptr || format == nullptr || image == nullptr) {
        TraceError(TAG, L"One or more NULL pointer arguments passed in.");
        return kvImageNullPointerArgument;
    } else if (format->bitsPerPixel == 0) {
        TraceError(TAG, L"Invalid bits per pixel argument passed in.");
        return kvImageInvalidParameter;
    } else if ((flags & ~(kvImageNoFlags | kvImageNoAllocate | kvImagePrintDiagnosticsToConsole | kvImageDoNotTile)) != 0) {
        TraceError(TAG, L"Invalid flag(s) passed in.");
        return kvImageUnknownFlagsBit;
    } else if (format->version != 0 || format->decode != nullptr ||
               _vImageBitsPerComponentIsValidFromCgImage(format->bitsPerComponent) == false) {
        TraceError(TAG, L"Invalid version or bitsPerComponent value or a decode pointer was specified.");
        return kvImageInvalidParameter;
    }

    // Issue warnings that some features may not be supported
    if (format->renderingIntent != kCGRenderingIntentDefault) {
        TraceWarning(TAG, L"Unsupported rendering intent.");
    }

    if (format->colorSpace != nullptr) {
        CGColorSpaceRef srcColorSpace = CGImageGetColorSpace(image);

        const CGColorSpaceModel dstCsModel = CGColorSpaceGetModel(format->colorSpace);
        const CGColorSpaceModel srcCsModel = CGColorSpaceGetModel(srcColorSpace);
        const CGBitmapInfo srcBitmapInfo = CGImageGetBitmapInfo(image);

        if (srcCsModel != dstCsModel) {
            TraceWarning(TAG, L"Colorspace conversions are not yet supported.");
        }
    }

    const uint32_t width = CGImageGetWidth(image);
    const uint32_t height = CGImageGetHeight(image);

    vImage_Error result;

    if ((flags & kvImageNoAllocate) == kvImageNoAllocate) {
        if (buffer->data == nullptr || buffer->rowBytes == 0 || width != buffer->width || height != buffer->height) {
            TraceError(TAG, L"Invalid buffer passed in.");
            result = kvImageInvalidParameter;
        } else {
            result = kvImageNoError;
        }
    } else {
        result = vImageBuffer_Init(buffer, height, width, format->bitsPerPixel, flags);
    }

    if (result == kvImageNoError) {
        const uint32_t srcPitch = CGImageGetBytesPerRow(image);
        const uint32_t dstPitch = buffer->rowBytes;
        const BYTE* srcData = static_cast<const BYTE*>(_CGDataProviderGetData(CGImageGetDataProvider(image)));
        BYTE* dstData = reinterpret_cast<BYTE*>(buffer->data);
        const uint32_t bytesPerPixel = format->bitsPerPixel >> 3;
        const uint32_t bytesToCopy = width * bytesPerPixel;

        assert(srcPitch >= bytesToCopy);
        assert(dstPitch >= bytesToCopy);

        for (uint32_t i = 0; i < height; i++) {
            memcpy(dstData, srcData, bytesToCopy);

            srcData += srcPitch;
            dstData += dstPitch;
        }
    }

    return result;
}

/**
@Status Caveat
@Notes Flags and cleanup function ignored
*/
CGImageRef vImageCreateCGImageFromBuffer(vImage_Buffer* buffer,
                                         vImage_CGImageFormat* format,
                                         void* cleanupFunction,
                                         void* cleanupFunctionParams,
                                         vImage_Flags flags,
                                         void* error) {
    static const wchar_t* TAG = L"vImageCreateCGImageFromBuffer";
    vImage_Error result = kvImageNoError;

    if (buffer == nullptr || format == nullptr) {
        TraceError(TAG, L"One or more NULL pointer arguments passed in.");
        result = kvImageNullPointerArgument;
    } else if (format->bitsPerPixel == 0) {
        TraceError(TAG, L"Invalid bits per pixel argument passed in.");
        result = kvImageInvalidParameter;
    } else if ((flags & ~(kvImageNoFlags | kvImageNoAllocate | kvImagePrintDiagnosticsToConsole | kvImageDoNotTile)) != 0) {
        TraceError(TAG, L"Invalid flag(s) passed in.");
        result = kvImageUnknownFlagsBit;
    } else if (format->version != 0 || format->decode != nullptr ||
               _vImageBitsPerComponentIsValidToCGImage(format->bitsPerComponent) == false) {
        TraceError(TAG, L"Invalid version or bitsPerComponent value or a decode pointer was specified.");
        result = kvImageInvalidParameter;
    }

    if (result != kvImageNoError) {
        if (error != nullptr) {
            *(reinterpret_cast<vImage_Error*>(error)) = result;
        }

        return nullptr;
    }

    const uint32_t packedWidthInBytes = buffer->width * (format->bitsPerPixel >> 3);
    void* packedBuffer;
    bool packedBufferAllocated;

    if (packedWidthInBytes < buffer->rowBytes) {
        // packing needed
        packedBuffer = malloc(buffer->height * packedWidthInBytes);

        if (packedBuffer != nil) {
            packedBufferAllocated = true;

            char* srcRow = (char*)buffer->data;
            char* dstRow = (char*)packedBuffer;

            for (int i = 0; i < buffer->height; i++) {
                memcpy(dstRow, srcRow, packedWidthInBytes);
                srcRow += buffer->rowBytes;
                dstRow += packedWidthInBytes;
            }
        } else {
            result = kvImageMemoryAllocationError;

            if (error != nullptr) {
                *(reinterpret_cast<vImage_Error*>(error)) = result;
            }

            return nullptr;
        }
    } else {
        // Data is packed so pass it directly into
        packedBuffer = buffer->data;
        packedBufferAllocated = false;
    }

    if ((flags & kvImageNoAllocate) != 0) { // Client is self-allocating buffer.
        if (packedBufferAllocated) {
            TraceWarning(TAG,
                         L"kvImageNoAllocate flag ignored since padded buffer passed in. Packed buffer allocated and used since padded "
                         L"buffers can't be used in CGImage.");
        }
    }

    const size_t bufferSize = packedWidthInBytes * buffer->height;
    CGDataProviderRef dataProvider = CGDataProviderCreateWithData(nullptr, packedBuffer, bufferSize, nullptr);

    CGImageRef imageRef = CGImageCreate((size_t)buffer->width,
                                        (size_t)buffer->height,
                                        (size_t)format->bitsPerComponent,
                                        (size_t)format->bitsPerPixel,
                                        (size_t)packedWidthInBytes,
                                        format->colorSpace,
                                        format->bitmapInfo,
                                        dataProvider,
                                        NULL,
                                        false,
                                        format->renderingIntent);

    CGDataProviderRelease(dataProvider);

    if (packedBufferAllocated == true) {
        free(packedBuffer);
    }

    if (imageRef == nullptr) {
        result = kvImageMemoryAllocationError;
    }

    if (error != nullptr) {
        *(reinterpret_cast<vImage_Error*>(error)) = result;
    }

    return imageRef;
}