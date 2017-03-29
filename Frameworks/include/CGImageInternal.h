//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Copyright (c) Microsoft. All rights reserved.
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

#import <Starboard.h>
#import "CoreGraphicsInternal.h"
#import <CoreGraphics/CGImage.h>
#import <objc/runtime.h>
#import <Foundation/NSData.h>
#import <CFRuntime.h>
#import <CFCppBase.h>
#import <map>
#import <windows.h>
#import <CGColorSpaceInternal.h>
#import <utility>

#include <COMIncludes.h>
#import <D2d1.h>
#import "Wincodec.h"
#import <wrl/client.h>
#import <IDisplayTexture.h>
#include <COMIncludes_End.h>

typedef struct {
    CGColorSpaceModel colorSpaceModel;
    CGBitmapInfo bitmapInfo;
    BYTE bitsPerComponent;
    BYTE bitsPerPixel;
} __CGImagePixelProperties;

struct GuidPixelLess : public std::binary_function<GUID, GUID, bool> {
    bool operator()(const GUID& left, const GUID& right) const {
        return memcmp(&left, &right, sizeof(GUID)) < 0;
    }
};

static const std::map<GUID, int, GuidPixelLess> s_ValidRenderTargetPixelFormat = { { GUID_WICPixelFormat8bppAlpha, 1 }, // A8 Straight
                                                                                   { GUID_WICPixelFormat32bppRGB, 1 }, // RGBX
                                                                                   { GUID_WICPixelFormat32bppPRGBA,
                                                                                     1 }, // RGBA Premultiplied
                                                                                   { GUID_WICPixelFormat32bppBGR, 1 }, // BGRX
                                                                                   { GUID_WICPixelFormat32bppPBGRA,
                                                                                     1 } }; // BGRX Premultiplied

static const std::map<GUID, __CGImagePixelProperties, GuidPixelLess> s_PixelFormats = {
    // RGB(A) formats

    // + 16bpp
    // IN-MEMORY PIXEL LAYOUTS
    //                  | Alpha First         | Alpha Last
    //                  +---------------------+------------
    // Conceptual Model | A RRRRR GGGGG BBBBB | DOES NOT EXIST
    //                  +---------------------+------------
    //                  | Stored As
    //                  +---------------------+------------
    // Little Endian    | GGGBBBBB ARRRRRGG   | -
    // Big Endian       | ARRRRRGG GGGBBBBB   | -
    //                  +---------------------+------------
    //                    A = X where skipped.
    // -+ No alpha
    // There are no mappable 16bpp formats. CoreGraphics supports ARGB in big and little endian.
    // WIC only supports BGRA in one endianness. Since this isn't like 32bpp RGB(A) where component
    // values divide clearly along byte boundaries, we can't tolerate the RGB<->BGR swap.
    // Where WIC would store    BBBBBGGG GGRRRRRA,
    // CoreGraphics would store ARRRRRGG GGGBBBBB.

    // + 24bpp (CoreGraphics has limited support for these.)
    // -+ Skipped alpha
    { GUID_WICPixelFormat24bppRGB, { kCGColorSpaceModelRGB, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 8, 24 } },
    { GUID_WICPixelFormat24bppBGR, { kCGColorSpaceModelRGB, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 8, 24 } },

    // + 32bpp
    // IN-MEMORY PIXEL LAYOUTS
    //                  | Alpha First | Alpha Last
    //                  +-------------+------------
    // Conceptual Model | A R G B     | R G B A
    //                  +-------------+------------
    //                  | Stored As
    //                  +-------------+------------
    // Little Endian    | B G R A     | A B G R
    // Big Endian       | A R G B     | R G B A
    //                  +-------------+------------
    //                    A = X where skipped.
    // -+ Non-premultiplied alpha (not natively supported by D2D)
    { GUID_WICPixelFormat32bppRGBA, { kCGColorSpaceModelRGB, (kCGImageAlphaLast | kCGBitmapByteOrder32Big), 8, 32 } },
    { GUID_WICPixelFormat32bppBGRA, { kCGColorSpaceModelRGB, (kCGImageAlphaFirst | kCGBitmapByteOrder32Little), 8, 32 } },
    // -+ Premultiplied alpha
    { GUID_WICPixelFormat32bppPRGBA, { kCGColorSpaceModelRGB, (kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big), 8, 32 } },
    { GUID_WICPixelFormat32bppPBGRA, { kCGColorSpaceModelRGB, (kCGImageAlphaPremultipliedFirst | kCGBitmapByteOrder32Little), 8, 32 } },
    // -+ Skipped alpha
    { GUID_WICPixelFormat32bppRGB, { kCGColorSpaceModelRGB, (kCGImageAlphaNoneSkipLast | kCGBitmapByteOrder32Big), 8, 32 } },
    { GUID_WICPixelFormat32bppBGR, { kCGColorSpaceModelRGB, (kCGImageAlphaNoneSkipFirst | kCGBitmapByteOrder32Little), 8, 32 } },

    // + 48bpp (CoreGraphics has limited support for these.)
    // -+ No alpha
    { GUID_WICPixelFormat48bppRGB, { kCGColorSpaceModelRGB, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 16, 48 } },
    { GUID_WICPixelFormat48bppBGR, { kCGColorSpaceModelRGB, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 16, 48 } },

    // 64bpp (CoreGraphics has limited support for these.)
    // -+ Non-premultiplied alpha (not natively supported by D2D)
    { GUID_WICPixelFormat64bppRGBA, { kCGColorSpaceModelRGB, (kCGImageAlphaLast | kCGBitmapByteOrderDefault), 16, 64 } },
    { GUID_WICPixelFormat64bppBGRA, { kCGColorSpaceModelRGB, (kCGImageAlphaLast | kCGBitmapByteOrderDefault), 16, 64 } },
    // -+ Premultiplied alpha
    { GUID_WICPixelFormat64bppPRGBA, { kCGColorSpaceModelRGB, (kCGImageAlphaPremultipliedLast | kCGBitmapByteOrderDefault), 16, 64 } },
    { GUID_WICPixelFormat64bppPBGRA, { kCGColorSpaceModelRGB, (kCGImageAlphaPremultipliedLast | kCGBitmapByteOrderDefault), 16, 64 } },
    // -+ Skipped alpha
    { GUID_WICPixelFormat64bppRGB, { kCGColorSpaceModelRGB, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 16, 64 } },

    // A formats
    // + 8bpp
    // -+ Alpha only
    { GUID_WICPixelFormat8bppAlpha, { kCGColorSpaceModelMonochrome, (kCGImageAlphaOnly | kCGBitmapByteOrderDefault), 8, 8 } },

    // G formats
    // + 1bpp
    { GUID_WICPixelFormatBlackWhite, { kCGColorSpaceModelMonochrome, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 1, 1 } },
    // + 2bpp
    { GUID_WICPixelFormat2bppGray, { kCGColorSpaceModelMonochrome, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 2, 2 } },
    // + 4bpp
    { GUID_WICPixelFormat4bppGray, { kCGColorSpaceModelMonochrome, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 4, 4 } },
    // + 8bpp
    { GUID_WICPixelFormat8bppGray, { kCGColorSpaceModelMonochrome, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 8, 8 } },
    // + 16bpp
    { GUID_WICPixelFormat16bppGray, { kCGColorSpaceModelMonochrome, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 16, 16 } },
    // + 32bpp (float)
    { GUID_WICPixelFormat32bppGrayFloat, { kCGColorSpaceModelMonochrome, (kCGImageAlphaNone | kCGBitmapFloatComponents), 32, 32 } },

    // CMYK formats
    // + 32bpp
    { GUID_WICPixelFormat32bppCMYK, { kCGColorSpaceModelCMYK, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 8, 32 } },
    // + 40bpp
    { GUID_WICPixelFormat40bppCMYKAlpha, { kCGColorSpaceModelCMYK, (kCGImageAlphaLast | kCGBitmapByteOrderDefault), 8, 40 } },
    // + 64bpp
    { GUID_WICPixelFormat64bppCMYK, { kCGColorSpaceModelCMYK, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 16, 64 } },
    // + 80bpp
    { GUID_WICPixelFormat80bppCMYKAlpha, { kCGColorSpaceModelCMYK, (kCGImageAlphaLast | kCGBitmapByteOrderDefault), 16, 80 } },

    // Indexed formats
    // + 1bpp
    { GUID_WICPixelFormat1bppIndexed, { kCGColorSpaceModelIndexed, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 1, 1 } },
    // + 2bpp
    { GUID_WICPixelFormat2bppIndexed, { kCGColorSpaceModelIndexed, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 2, 2 } },
    // + 4bpp
    { GUID_WICPixelFormat4bppIndexed, { kCGColorSpaceModelIndexed, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 4, 4 } },
    // + 8bpp
    { GUID_WICPixelFormat8bppIndexed, { kCGColorSpaceModelIndexed, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 8, 8 } }
};

bool _CGIsValidRenderTargetPixelFormat(WICPixelFormatGUID pixelFormat);
COREGRAPHICS_EXPORT const __CGImagePixelProperties* _CGGetPixelFormatProperties(WICPixelFormatGUID pixelFormat);

WICPixelFormatGUID _CGImageGetWICPixelFormat(CGImageRef image);

COREGRAPHICS_EXPORT CGImageRef _CGImageLoadGIF(void* bytes, int length);

COREGRAPHICS_EXPORT CGImageRef _CGImageLoadBMP(void* bytes, size_t length);

COREGRAPHICS_EXPORT CGImageRef _CGImageLoadTIFF(void* bytes, int length);

COREGRAPHICS_EXPORT CGImageRef _CGImageLoadPNG(void* bytes, int length);

COREGRAPHICS_EXPORT CGImageRef _CGImageLoadJPEG(void* bytes, int length);

COREGRAPHICS_EXPORT CGImageRef _CGImageLoadImageWithWICDecoder(REFGUID decoderCls, void* bytes, int length);

COREGRAPHICS_EXPORT CGImageRef _CGImageGetImageFromData(void* data, int length);

COREGRAPHICS_EXPORT CGImageRef _CGImageCreateWithWICBitmap(IWICBitmap* bitmap);

COREGRAPHICS_EXPORT HRESULT _CGImageGetWICImageSource(CGImageRef image, IWICBitmap** source);

// Obtain a direct pointer to the data.
COREGRAPHICS_EXPORT void* _CGImageGetRawBytes(CGImageRef image);

COREGRAPHICS_EXPORT CGImageRef _CGImageCreateFromDataProvider(CGDataProviderRef provider);

COREGRAPHICS_EXPORT CGImageRef _CGImageCreateFromFileWithWICFormat(CFStringRef filename, WICPixelFormatGUID format);

// Obtain the associated DisplayTexture
__declspec(dllexport) std::shared_ptr<IDisplayTexture> _CGImageGetDisplayTexture(CGImageRef image);

size_t _CGImageImputeBitsPerPixelFromFormat(CGColorSpaceRef colorSpace, size_t bitsPerComponent, CGBitmapInfo bitmapInfo);
HRESULT _CGImageGetWICPixelFormatFromImageProperties(
    unsigned int bitsPerComponent, unsigned int bitsPerPixel, CGColorSpaceRef colorSpace, CGBitmapInfo bitmapInfo, GUID* pixelFormat);

// If the image is of the same format, the image is retained and returned.
COREGRAPHICS_EXPORT CGImageRef _CGImageCreateCopyWithPixelFormat(CGImageRef image, WICPixelFormatGUID pixelFormat);

typedef void (*CGImageDestructionListener)(CGImageRef img);
COREGRAPHICS_EXPORT void _CGImageAddDestructionListener(CGImageDestructionListener listener);

HRESULT _CGImageConvertToMaskCompatibleWICBitmap(CGImageRef image, IWICBitmap** pBitmap);