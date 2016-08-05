//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

#import "CGColorSpaceInternal.h"
#import "CoreGraphics/CoreGraphicsExport.h"
#import "CoreGraphicsInternal.h"

static inline __CGSurfaceInfo _CGSurfaceInfoInit(unsigned int width,
                                                 unsigned int height,
                                                 __CGSurfaceFormat fmt,
                                                 void* data = NULL,
                                                 unsigned int bytesPerRow = 0,
                                                 CGBitmapInfo bitmapInfo = c_kCGBitmapInfoInvalidBits) {
    __CGSurfaceInfo surfaceInfo;

    surfaceInfo.format = fmt;
    surfaceInfo.width = width;
    surfaceInfo.height = height;
    surfaceInfo.surfaceData = data;

    surfaceInfo.colorSpaceModel = c_FormatTable[fmt].colorSpaceModel;
    surfaceInfo.bitsPerComponent = c_FormatTable[fmt].bitsPerComponent;
    surfaceInfo.bytesPerPixel = c_FormatTable[fmt].bytesPerPixel;

    // Set bitmapInfo if passed in, otherwise set the default value for the surface format
    if (bitmapInfo != c_kCGBitmapInfoInvalidBits) {
        surfaceInfo.bitmapInfo = bitmapInfo;
    } else {
        surfaceInfo.bitmapInfo = c_FormatTable[fmt].bitmapInfo;
    }

    // Set bytesPerRow if necessary
    if ((data != NULL) && (bytesPerRow == 0)) {
        surfaceInfo.bytesPerRow = width * surfaceInfo.bytesPerPixel;
    }

    return surfaceInfo;
}

static inline __CGSurfaceFormat _CGImageGetFormat(unsigned int bitsPerComponent,
                                                  unsigned int bitsPerPixel,
                                                  CGColorSpaceRef colorSpace,
                                                  CGBitmapInfo bitmapInfo) {
    CGColorSpaceModel colorSpaceModel = ((__CGColorSpace*)colorSpace)->colorSpaceModel;
    __CGSurfaceFormat fmt;
    unsigned int alphaInfo = bitmapInfo & kCGBitmapAlphaInfoMask;
    unsigned int byteOrder = bitmapInfo & kCGBitmapByteOrderMask;

    assert((bitmapInfo & kCGBitmapFloatComponents) == 0);

    if (colorSpaceModel == kCGColorSpaceModelRGB) {
        if (byteOrder == kCGBitmapByteOrder32Big) {
            switch (alphaInfo) {
                case kCGImageAlphaNoneSkipFirst:
                    UNIMPLEMENTED_WITH_MSG("XRGB pixelformat unsupported");
                    fmt = _ColorARGB;
                    break;
                case kCGImageAlphaFirst:
                case kCGImageAlphaPremultipliedFirst:
                    fmt = _ColorARGB;
                    break;
                case kCGImageAlphaNone:
                    if (bitsPerPixel == 32) {
                        // TODO: verify
                        fmt = _ColorARGB;
                    } else if (bitsPerComponent == 5) {
                        fmt = _Color565;
                    } else if (bitsPerPixel == 24) {
                        UNIMPLEMENTED_WITH_MSG("RGB pixelformat unsupported");
                        fmt = _ColorBGR;
                    } else {
                        UNIMPLEMENTED_WITH_MSG("Unknown pixelformat");
                        fmt = _ColorARGB;
                    }
                    break;
                case kCGImageAlphaNoneSkipLast:
                case kCGImageAlphaLast:
                case kCGImageAlphaPremultipliedLast:
                default:
                    UNIMPLEMENTED_WITH_MSG("RGBX and RGBA pixelformats unsupported");
                    fmt = _ColorARGB;
                    break;
            }
        } else {
            assert(byteOrder == kCGBitmapByteOrder32Little || byteOrder == kCGBitmapByteOrderDefault);

            switch (alphaInfo) {
                case kCGImageAlphaLast:
                case kCGImageAlphaPremultipliedLast:
                    fmt = _ColorABGR;
                    break;
                case kCGImageAlphaNoneSkipLast:
                    fmt = _ColorXBGR;
                    break;
                case kCGImageAlphaNoneSkipFirst:
                    fmt = _ColorBGRX;
                    break;
                case kCGImageAlphaNone:
                    if (bitsPerPixel == 32) {
                        fmt = _ColorXBGR;
                    } else if (bitsPerPixel == 24) {
                        fmt = _ColorBGR;
                    } else if (bitsPerComponent == 5) {
                        UNIMPLEMENTED_WITH_MSG("BGR565 Pixel format unsupported");
                        fmt = _Color565;
                    }
                    break;
                default:
                    UNIMPLEMENTED_WITH_MSG("Pixel format unsupported");
                    fmt = _ColorABGR;
                    break;
            }
        }
    } else if (colorSpaceModel == kCGColorSpaceModelPattern) {
        fmt = _ColorA8;
    } else if (colorSpaceModel == kCGColorSpaceModelMonochrome) {
        fmt = _ColorGrayscale;
    } else if (colorSpaceModel == kCGColorSpaceModelIndexed) {
        fmt = _ColorIndexed;
    }

    return fmt;
}