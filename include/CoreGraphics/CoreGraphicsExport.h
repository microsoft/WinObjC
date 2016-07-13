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

#ifndef COREGRAPHICS_IMPEXP
#define COREGRAPHICS_IMPEXP __declspec(dllimport)
#endif

#ifndef COREGRAPHICS_EXPORT
#ifdef __cplusplus
#define COREGRAPHICS_EXPORT COREGRAPHICS_IMPEXP extern "C"
#else
#define COREGRAPHICS_EXPORT COREGRAPHICS_IMPEXP extern
#endif
#endif

#ifndef COREGRAPHICS_EXTERNC_BEGIN
#if defined(__cplusplus)
#define COREGRAPHICS_EXTERNC_BEGIN extern "C" {
#define COREGRAPHICS_EXTERNC_END }
#else
#define COREGRAPHICS_EXTERNC_BEGIN
#define COREGRAPHICS_EXTERNC_END
#endif
#endif

// import CoreGraphis opaque types here to avoid ugly public header
// and to avoid compiler errors caused by import ordering
typedef struct __CGColor* CGColorRef;
typedef struct __CGColorSpace* CGColorSpaceRef;
typedef struct __CGContext* CGContextRef;
typedef struct __CGDataConsumer* CGDataConsumerRef;
typedef struct __CGFunction* CGFunctionRef;
typedef struct __CGGradient* CGGradientRef;
typedef struct __CGLayer* CGLayerRef;
typedef struct __CGPDFContentStream* CGPDFContentStreamRef;
typedef struct __CGPDFContext* CGPDFContextRef;
typedef struct __CGPDFString* CGPDFStringRef;
typedef struct __CGPDFArray* CGPDFArrayRef;
typedef struct __CGPDFDictionary* CGPDFDictionaryRef;
typedef struct __CGPDFDocument* CGPDFDocumentRef;
typedef struct __CGPDFOperatorTable* CGPDFOperatorTableRef;
typedef struct __CGPDFPage* CGPDFPageRef;
typedef struct __CGPDFScanner* CGPDFScannerRef;
typedef struct __CGPDFStream* CGPDFStreamRef;
typedef union __CGPDFObject* CGPDFObjectRef;
typedef struct __CGImage* CGImageRef;
typedef struct __CGShading* CGShadingRef;
typedef struct __CGPath* CGPathRef;
typedef struct __CGPath* CGMutablePathRef;

// TODO: following opaque types can not use form of
// typedef struct __Foo* FooRef;
// indiciating backing code need some clean up
typedef void* CGDataProviderRef;

#if defined(__clang__)
typedef id CGFontRef;
typedef id CGPatternRef;
#endif

typedef enum {
    kCGImageAlphaNone,
    kCGImageAlphaPremultipliedLast,
    kCGImageAlphaPremultipliedFirst,
    kCGImageAlphaLast,
    kCGImageAlphaFirst,
    kCGImageAlphaNoneSkipLast,
    kCGImageAlphaNoneSkipFirst,
    kCGImageAlphaOnly
} CGImageAlphaInfo;
enum {
    kCGBitmapAlphaInfoMask = 0x1F,
    kCGBitmapFloatComponents = (1 << 8),
    kCGBitmapByteOrderMask = 0x7000,
    kCGBitmapByteOrderDefault = (0 << 12),
    kCGBitmapByteOrder16Little = (1 << 12),
    kCGBitmapByteOrder32Little = (2 << 12),
    kCGBitmapByteOrder16Big = (3 << 12),
    kCGBitmapByteOrder32Big = (4 << 12)
};
typedef int CGBitmapInfo;

typedef enum {
    kCGRenderingIntentDefault,
    kCGRenderingIntentAbsoluteColorimetric,
    kCGRenderingIntentRelativeColorimetric,
    kCGRenderingIntentSaturation,
    kCGRenderingIntentPerceptual,
} CGColorRenderingIntent;

typedef enum {
    kCGColorSpaceModelUnknown = -1,
    kCGColorSpaceModelMonochrome,
    kCGColorSpaceModelRGB,
    kCGColorSpaceModelCMYK,
    kCGColorSpaceModelLab,
    kCGColorSpaceModelDeviceN,
    kCGColorSpaceModelIndexed,
    kCGColorSpaceModelPattern,
} CGColorSpaceModel;

typedef enum {
    _Color565 = 0,
    _ColorARGB,
    _ColorABGR,
    _ColorBGRX,
    _ColorXBGR,
    _ColorGrayscale,
    _ColorBGR,
    _ColorA8,
    _ColorIndexed,
    _ColorMax,
    _ColorRGBA = _ColorABGR
} surfaceFormat;

typedef struct {
    CGColorSpaceModel colorSpaceModel;
    CGBitmapInfo bitmapInfo;
    unsigned int bitsPerComponent;
    unsigned int bytesPerPixel;
} __CGFormatProperties;

static const __CGFormatProperties c_FormatTable[_ColorMax] = {
    { kCGColorSpaceModelRGB, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 5, 2 }, //_Color565,
    { kCGColorSpaceModelRGB, (kCGImageAlphaFirst | kCGBitmapByteOrderDefault), 8, 4 }, //_ColorARGB,
    { kCGColorSpaceModelRGB, (kCGImageAlphaLast | kCGBitmapByteOrder32Little), 8, 4 }, //_ColorABGR,
    { kCGColorSpaceModelRGB, (kCGImageAlphaNoneSkipFirst | kCGBitmapByteOrderDefault), 8, 4 }, //_ColorBGRX,
    { kCGColorSpaceModelRGB, (kCGImageAlphaNoneSkipLast | kCGBitmapByteOrder32Little), 8, 4 }, //_ColorXBGR,
    { kCGColorSpaceModelMonochrome, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 8, 1 }, //_ColorGrayscale,
    { kCGColorSpaceModelRGB, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 8, 3 }, //_ColorBGR,
    { kCGColorSpaceModelPattern, (kCGImageAlphaOnly | kCGBitmapByteOrderDefault), 8, 1 }, //_ColorA8,
    { kCGColorSpaceModelIndexed, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 8, 2 }, //_ColorIndexed,
};

struct __CGSurfaceInfo {
    size_t width;
    size_t height;
    size_t bitsPerComponent;
    size_t bytesPerPixel;
    size_t bytesPerRow;
    void* surfaceData;
    CGColorSpaceModel colorSpaceModel;
    CGBitmapInfo bitmapInfo;
    surfaceFormat format;
};