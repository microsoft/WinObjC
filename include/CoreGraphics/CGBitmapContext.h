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
#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGColorSpace.h>
#import <CoreGraphics/CGImage.h>

typedef void (*CGBitmapContextReleaseDataCallback)(void* releaseInfo, void* data);

COREGRAPHICS_EXPORT CGContextRef CGBitmapContextCreate(
    void* data, size_t width, size_t height, size_t bitsPerComponent, size_t bytesPerRow, CGColorSpaceRef space, CGBitmapInfo bitmapInfo);

COREGRAPHICS_EXPORT CGImageRef CGBitmapContextCreateImage(CGContextRef self);
COREGRAPHICS_EXPORT CGImageAlphaInfo CGBitmapContextGetAlphaInfo(CGContextRef context);
COREGRAPHICS_EXPORT void* CGBitmapContextGetData(CGContextRef context);
COREGRAPHICS_EXPORT size_t CGBitmapContextGetHeight(CGContextRef context);
COREGRAPHICS_EXPORT size_t CGBitmapContextGetWidth(CGContextRef context);
COREGRAPHICS_EXPORT size_t CGBitmapContextGetBitsPerComponent(CGContextRef context);
COREGRAPHICS_EXPORT size_t CGBitmapContextGetBytesPerRow(CGContextRef context);

COREGRAPHICS_EXPORT CGContextRef CGBitmapContextCreateWithData(void* data,
    size_t width,
    size_t height,
    size_t bitsPerComponent,
    size_t bytesPerRow,
    CGColorSpaceRef space,
    uint32_t bitmapInfo,
    CGBitmapContextReleaseDataCallback releaseCallback,
    void* releaseInfo) STUB_METHOD;

COREGRAPHICS_EXPORT CGBitmapInfo CGBitmapContextGetBitmapInfo(CGContextRef context);
COREGRAPHICS_EXPORT size_t CGBitmapContextGetBitsPerPixel(CGContextRef context);
COREGRAPHICS_EXPORT CGColorSpaceRef CGBitmapContextGetColorSpace(CGContextRef context) STUB_METHOD;
