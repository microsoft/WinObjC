//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

#import <CoreGraphics/CoreGraphicsExport.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGColorSpace.h>
#import <CoreGraphics/CGDataProvider.h>

#ifdef __BIG_ENDIAN__
#define kCGBitmapByteOrder16Host kCGBitmapByteOrder16Big
#define kCGBitmapByteOrder32Host kCGBitmapByteOrder32Big
#else
#define kCGBitmapByteOrder16Host kCGBitmapByteOrder16Little
#define kCGBitmapByteOrder32Host kCGBitmapByteOrder32Little
#endif

COREGRAPHICS_EXPORT CGImageRef CGImageCreate(size_t width,
                                             size_t height,
                                             size_t bitsPerComponent,
                                             size_t bitsPerPixel,
                                             size_t bytesPerRow,
                                             CGColorSpaceRef space,
                                             CGBitmapInfo bitmapInfo,
                                             CGDataProviderRef provider,
                                             const CGFloat* decode,
                                             bool shouldInterpolate,
                                             CGColorRenderingIntent intent);
COREGRAPHICS_EXPORT CGImageRef CGImageCreateCopy(CGImageRef image);
COREGRAPHICS_EXPORT CGImageRef CGImageCreateCopyWithColorSpace(CGImageRef image, CGColorSpaceRef space);

COREGRAPHICS_EXPORT CGImageRef CGImageCreateWithJPEGDataProvider(CGDataProviderRef source,
                                                                 const CGFloat* decode,
                                                                 bool shouldInterpolate,
                                                                 CGColorRenderingIntent intent);
COREGRAPHICS_EXPORT CGImageRef CGImageCreateWithPNGDataProvider(CGDataProviderRef source,
                                                                const CGFloat* decode,
                                                                bool shouldInterpolate,
                                                                CGColorRenderingIntent intent);

COREGRAPHICS_EXPORT CGImageRef CGImageCreateWithImageInRect(CGImageRef image, CGRect rect);
COREGRAPHICS_EXPORT CGImageRef CGImageCreateWithMask(CGImageRef image, CGImageRef mask);

COREGRAPHICS_EXPORT CGImageRef CGImageCreateWithMaskingColors(CGImageRef image, const CGFloat* components) STUB_METHOD;

COREGRAPHICS_EXPORT CGImageRef CGImageMaskCreate(size_t width,
                                                 size_t height,
                                                 size_t bitsPerComponent,
                                                 size_t bitsPerPixel,
                                                 size_t bytesPerRow,
                                                 CGDataProviderRef provider,
                                                 const CGFloat* decode,
                                                 bool shouldInterpolate);
COREGRAPHICS_EXPORT CGImageRef CGImageRetain(CGImageRef image);
COREGRAPHICS_EXPORT void CGImageRelease(CGImageRef image);

COREGRAPHICS_EXPORT CFTypeID CGImageGetTypeID() STUB_METHOD;

COREGRAPHICS_EXPORT CGImageAlphaInfo CGImageGetAlphaInfo(CGImageRef image);
COREGRAPHICS_EXPORT CGBitmapInfo CGImageGetBitmapInfo(CGImageRef image);
COREGRAPHICS_EXPORT size_t CGImageGetBitsPerComponent(CGImageRef image);
COREGRAPHICS_EXPORT size_t CGImageGetBitsPerPixel(CGImageRef image);
COREGRAPHICS_EXPORT size_t CGImageGetBytesPerRow(CGImageRef image);
COREGRAPHICS_EXPORT CGColorSpaceRef CGImageGetColorSpace(CGImageRef image);
COREGRAPHICS_EXPORT CGDataProviderRef CGImageGetDataProvider(CGImageRef image);
COREGRAPHICS_EXPORT void* _CGImageGetData(CGImageRef image);

COREGRAPHICS_EXPORT const CGFloat* CGImageGetDecode(CGImageRef image) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGImageGetShouldInterpolate(CGImageRef image) STUB_METHOD;
COREGRAPHICS_EXPORT CGColorRenderingIntent CGImageGetRenderingIntent(CGImageRef image) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGImageIsMask(CGImageRef image) STUB_METHOD;

COREGRAPHICS_EXPORT size_t CGImageGetHeight(CGImageRef image);
COREGRAPHICS_EXPORT size_t CGImageGetWidth(CGImageRef image);
