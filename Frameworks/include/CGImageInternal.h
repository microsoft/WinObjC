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

static const std::map<GUID, int, GuidPixelLess> s_ValidRenderTargetPixelFormat = { { GUID_WICPixelFormat8bppAlpha, 1 },    // A8 Straight
                                                                                   { GUID_WICPixelFormat32bppRGB, 1 },     // RGBX
                                                                                   { GUID_WICPixelFormat32bppPRGBA, 1 },   // RGBA Premultiplied
                                                                                   { GUID_WICPixelFormat32bppBGR, 1 },     // BGRX
                                                                                   { GUID_WICPixelFormat32bppPBGRA, 1 } }; // BGRX Premultiplied

static const std::map<GUID, __CGImagePixelProperties, GuidPixelLess> s_PixelFormats = {
    // Last = RGBA, 32Little = forward: RGBA
    // First = ARGB, 32Big = backward: BGRA
    { GUID_WICPixelFormat32bppRGBA, { kCGColorSpaceModelRGB, (kCGImageAlphaLast | kCGBitmapByteOrder32Little), 8, 32 } },
    { GUID_WICPixelFormat32bppBGRA, { kCGColorSpaceModelRGB, (kCGImageAlphaFirst | kCGBitmapByteOrder32Big), 8, 32 } },
    { GUID_WICPixelFormat32bppPRGBA, { kCGColorSpaceModelRGB, (kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Little), 8, 32 } },
    { GUID_WICPixelFormat32bppPBGRA, { kCGColorSpaceModelRGB, (kCGImageAlphaPremultipliedFirst | kCGBitmapByteOrder32Big), 8, 32 } },

    // 64bpp formats (CoreGraphics has limited support for these.)
    { GUID_WICPixelFormat64bppRGBA, { kCGColorSpaceModelRGB, (kCGImageAlphaLast | kCGBitmapByteOrderDefault), 16, 64 } },
    { GUID_WICPixelFormat64bppBGRA, { kCGColorSpaceModelRGB, (kCGImageAlphaLast | kCGBitmapByteOrderDefault), 16, 64 } },
    { GUID_WICPixelFormat64bppPRGBA, { kCGColorSpaceModelRGB, (kCGImageAlphaPremultipliedLast | kCGBitmapByteOrderDefault), 16, 64 } },
    { GUID_WICPixelFormat64bppPBGRA, { kCGColorSpaceModelRGB, (kCGImageAlphaPremultipliedLast | kCGBitmapByteOrderDefault), 16, 64 } },

    // Non-alpha formats.
    { GUID_WICPixelFormat24bppRGB, { kCGColorSpaceModelRGB, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 8, 24 } },
    { GUID_WICPixelFormat24bppBGR, { kCGColorSpaceModelRGB, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 8, 24 } },
    // Alpha-Skip formats (32bpp, but has alpha)
    { GUID_WICPixelFormat32bppRGB, { kCGColorSpaceModelRGB, (kCGImageAlphaNoneSkipLast | kCGBitmapByteOrder32Little), 8, 32 } },
    { GUID_WICPixelFormat32bppBGR, { kCGColorSpaceModelRGB, (kCGImageAlphaNoneSkipFirst | kCGBitmapByteOrder32Big), 8, 32 } },
    { GUID_WICPixelFormat48bppRGB, { kCGColorSpaceModelRGB, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 16, 48 } },
    { GUID_WICPixelFormat48bppBGR, { kCGColorSpaceModelRGB, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 16, 48 } },
    { GUID_WICPixelFormat64bppRGB, { kCGColorSpaceModelRGB, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 16, 64 } },
    /*Alpha Only */
    { GUID_WICPixelFormat8bppAlpha, { kCGColorSpaceModelRGB, (kCGImageAlphaOnly | kCGBitmapByteOrderDefault), 8, 32 } },
    /* CYMK */
    { GUID_WICPixelFormat32bppCMYK, { kCGColorSpaceModelCMYK, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 8, 32 } },
    { GUID_WICPixelFormat64bppCMYK, { kCGColorSpaceModelCMYK, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 16, 64 } },
    { GUID_WICPixelFormat40bppCMYKAlpha, { kCGColorSpaceModelCMYK, (kCGImageAlphaLast | kCGBitmapByteOrderDefault), 8, 40 } },
    { GUID_WICPixelFormat80bppCMYKAlpha, { kCGColorSpaceModelCMYK, (kCGImageAlphaLast | kCGBitmapByteOrderDefault), 16, 64 } },
    /*Monochrome*/
    { GUID_WICPixelFormat4bppGray, { kCGColorSpaceModelMonochrome, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 4, 4 } },
    { GUID_WICPixelFormat8bppGray, { kCGColorSpaceModelMonochrome, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 8, 8 } },
    { GUID_WICPixelFormat16bppGray, { kCGColorSpaceModelMonochrome, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 16, 16 } },
    { GUID_WICPixelFormat32bppGrayFloat, { kCGColorSpaceModelMonochrome, (kCGImageAlphaNone | kCGBitmapFloatComponents), 32, 32 } },
    /*Indexed*/
    { GUID_WICPixelFormat1bppIndexed, { kCGColorSpaceModelIndexed, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 1, 1 } },
    { GUID_WICPixelFormat2bppIndexed, { kCGColorSpaceModelIndexed, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 2, 2 } },
    { GUID_WICPixelFormat4bppIndexed, { kCGColorSpaceModelIndexed, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 4, 4 } },
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

COREGRAPHICS_EXPORT NSData* _CGImagePNGRepresentation(CGImageRef image);
COREGRAPHICS_EXPORT NSData* _CGImageJPEGRepresentation(CGImageRef image, float quality);
COREGRAPHICS_EXPORT NSData* _CGImageRepresentation(CGImageRef image, REFGUID guid, float quality);

COREGRAPHICS_EXPORT CGImageRef _CGImageCreateWithWICBitmap(IWICBitmap* bitmap);

COREGRAPHICS_EXPORT HRESULT _CGImageGetWICImageSource(CGImageRef image, IWICBitmap** source);

// Obtain a direct pointer to the data.
COREGRAPHICS_EXPORT void* _CGImageGetRawBytes(CGImageRef image);

// Obtain the associated DisplayTexture
__declspec(dllexport) std::shared_ptr<IDisplayTexture> _CGImageGetDisplayTexture(CGImageRef image);

REFGUID _CGImageGetWICPixelFormatFromImageProperties(unsigned int bitsPerComponent,
                                                     unsigned int bitsPerPixel,
                                                     CGColorSpaceRef colorSpace,
                                                     CGBitmapInfo bitmapInfo);

// If the image is of the same format, the image is retained and returned.
COREGRAPHICS_EXPORT CGImageRef _CGImageCreateCopyWithPixelFormat(CGImageRef image, WICPixelFormatGUID pixelFormat);

typedef void (*CGImageDestructionListener)(CGImageRef img);
COREGRAPHICS_EXPORT void CGImageAddDestructionListener(CGImageDestructionListener listener);

HRESULT _CGImageConvertToMaskCompatibleWICBitmap(CGImageRef image, IWICBitmap** pBitmap);