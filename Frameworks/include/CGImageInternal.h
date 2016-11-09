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
#import "DisplayTexture.h"

#include <COMIncludes.h>
#import <D2d1.h>
#import "Wincodec.h"
#import <wrl/client.h>
#include <COMIncludes_End.h>

class CGContextImpl;

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

static const std::map<GUID, __CGImagePixelProperties, GuidPixelLess> s_PixelFormats = {
    /*Alpha First,Last*/
    { GUID_WICPixelFormat32bppRGBA, { kCGColorSpaceModelRGB, (kCGImageAlphaLast | kCGBitmapByteOrderDefault), 8, 32 } },
    { GUID_WICPixelFormat32bppBGRA, { kCGColorSpaceModelRGB, (kCGImageAlphaLast | kCGBitmapByteOrderDefault), 8, 32 } },
    { GUID_WICPixelFormat64bppRGBA, { kCGColorSpaceModelRGB, (kCGImageAlphaLast | kCGBitmapByteOrderDefault), 16, 64 } },
    { GUID_WICPixelFormat64bppBGRA, { kCGColorSpaceModelRGB, (kCGImageAlphaLast | kCGBitmapByteOrderDefault), 16, 64 } },
    /*Alpha Premultiplied Last/First */
    { GUID_WICPixelFormat32bppPRGBA, { kCGColorSpaceModelRGB, (kCGImageAlphaPremultipliedLast | kCGBitmapByteOrderDefault), 8, 32 } },
    { GUID_WICPixelFormat32bppPBGRA, { kCGColorSpaceModelRGB, (kCGImageAlphaPremultipliedLast | kCGBitmapByteOrderDefault), 8, 32 } },
    { GUID_WICPixelFormat64bppPRGBA, { kCGColorSpaceModelRGB, (kCGImageAlphaPremultipliedLast | kCGBitmapByteOrderDefault), 16, 64 } },
    { GUID_WICPixelFormat64bppPBGRA, { kCGColorSpaceModelRGB, (kCGImageAlphaPremultipliedLast | kCGBitmapByteOrderDefault), 16, 64 } },
    /*Alpha None, AlphaNoneSkipFirst, AlphaNoneSkipLast*/
    { GUID_WICPixelFormat24bppRGB, { kCGColorSpaceModelRGB, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 8, 24 } },
    { GUID_WICPixelFormat24bppBGR, { kCGColorSpaceModelRGB, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 8, 24 } },
    { GUID_WICPixelFormat32bppRGB, { kCGColorSpaceModelRGB, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 8, 32 } },
    { GUID_WICPixelFormat32bppBGR, { kCGColorSpaceModelRGB, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 8, 32 } },
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
    { GUID_WICPixelFormat2bppIndexed, { kCGColorSpaceModelIndexed, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 1, 2 } },
    { GUID_WICPixelFormat4bppIndexed, { kCGColorSpaceModelIndexed, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 1, 4 } },
    { GUID_WICPixelFormat8bppIndexed, { kCGColorSpaceModelIndexed, (kCGImageAlphaNone | kCGBitmapByteOrderDefault), 1, 8 } }
};

struct __CGImageImpl {
    Microsoft::WRL::ComPtr<IWICBitmap> bitmapImageSource;
    bool isMask;
    bool interpolate;
    woc::unique_cf<CGColorSpaceRef> colorSpace;
    CGImageAlphaInfo alphaInfo;
    size_t height;
    size_t width;
    size_t bitsPerPixel;
    size_t bitsPerComponent;
    size_t bytesPerRow;
    CGBitmapInfo bitmapInfo;
    CGColorRenderingIntent renderingIntent;

    __CGImageImpl() {
        height = 0;
        width = 0;
        bitsPerComponent = 0;
        bitsPerPixel = 0;
        bytesPerRow = 0;
        bitmapInfo = kCGBitmapByteOrderDefault;
        alphaInfo = kCGImageAlphaNone;
        isMask = false;
        interpolate = false;
        renderingIntent = kCGRenderingIntentDefault;
    }

    inline WICPixelFormatGUID PixelFormat() const {
        WICPixelFormatGUID pixelFormat;
        RETURN_RESULT_IF_FAILED(bitmapImageSource->GetPixelFormat(&pixelFormat), GUID_WICPixelFormatUndefined);
        return pixelFormat;
    }

    inline const __CGImagePixelProperties* Properties() const {
        WICPixelFormatGUID pixelFormat = PixelFormat();
        RETURN_NULL_IF(pixelFormat == GUID_WICPixelFormatUndefined);

        auto iterator = s_PixelFormats.find(pixelFormat);
        RETURN_NULL_IF(iterator == s_PixelFormats.end());

        return &iterator->second;
    }

    inline size_t BitsPerPixel() const {
        const __CGImagePixelProperties* properties = Properties();
        RETURN_RESULT_IF_NULL(properties, 0);
        return properties->bitsPerPixel;
    }

    inline size_t BitsPerComponent() const {
        const __CGImagePixelProperties* properties = Properties();
        RETURN_RESULT_IF_NULL(properties, 0);
        return properties->bitsPerComponent;
    }

    inline CGBitmapInfo BitmapInfo() const {
        const __CGImagePixelProperties* properties = Properties();
        RETURN_RESULT_IF_NULL(properties, 0);
        return properties->bitmapInfo;
    }

    inline CGImageAlphaInfo AlphaInfo() const {
        return static_cast<CGImageAlphaInfo>(BitmapInfo() & kCGBitmapAlphaInfoMask);
    }

    inline CGColorSpaceRef ColorSpace() {
        const __CGImagePixelProperties* properties = Properties();
        RETURN_NULL_IF(!properties);
        return _CGColorSpaceCreate(properties->colorSpaceModel);
    }

    inline void SetImageSource(Microsoft::WRL::ComPtr<IWICBitmap> source) {
        bitmapImageSource = std::move(source);
        // populate the image info.
        if (FAILED(bitmapImageSource->GetSize(&width, &height))) {
            height = 0;
            width = 0;
        }

        bitmapInfo = BitmapInfo();
        alphaInfo = AlphaInfo();
        bitsPerPixel = BitsPerPixel();
        bitsPerComponent = BitsPerComponent();
        bytesPerRow = (bitsPerPixel >> 3) * width;
        if (!colorSpace) {
            colorSpace.reset(ColorSpace());
        }
    }
};

struct __CGImage : CoreFoundation::CppBase<__CGImage, __CGImageImpl> {
    inline Microsoft::WRL::ComPtr<IWICBitmap>& ImageSource() {
        return _impl.bitmapImageSource;
    }

    inline void* Data() const {
        Microsoft::WRL::ComPtr<IWICBitmapLock> lock;
        RETURN_NULL_IF_FAILED(_impl.bitmapImageSource->Lock(nullptr, WICBitmapLockWrite, &lock));
        BYTE* data;
        UINT size;
        RETURN_NULL_IF_FAILED(lock->GetDataPointer(&size, &data));
        return static_cast<void*>(data);
    }

    inline size_t Height() const {
        return _impl.height;
    }

    inline size_t Width() const {
        return _impl.width;
    }

    inline bool IsMask() const {
        return _impl.isMask;
    }

    inline bool Interpolate() const {
        return _impl.interpolate;
    }

    inline CGColorSpaceRef ColorSpace() {
        return _impl.colorSpace.get();
    }

    inline CGColorRenderingIntent RenderingIntent() const {
        return _impl.renderingIntent;
    }

    inline CGBitmapInfo BitmapInfo() const {
        return _impl.bitmapInfo;
    }

    inline CGImageAlphaInfo AlphaInfo() const {
        return _impl.alphaInfo;
    }

    inline size_t BitsPerPixel() const {
        return _impl.bitsPerPixel;
    }

    inline size_t BytesPerRow() const {
        return _impl.bytesPerRow;
    }

    inline size_t BitsPerComponent() const {
        return _impl.bitsPerComponent;
    }

    inline WICPixelFormatGUID PixelFormat() const {
        return _impl.PixelFormat();
    }

    inline __CGImage& SetImageSource(Microsoft::WRL::ComPtr<IWICBitmap> source) {
        _impl.SetImageSource(source);
        return *this;
    }

    inline __CGImage& SetIsMask(bool mask) {
        _impl.isMask = mask;
        return *this;
    }

    inline __CGImage& SetInterpolate(bool interpolate) {
        _impl.interpolate = interpolate;
        return *this;
    }

    inline __CGImage& SetColorSpace(CGColorSpaceRef space) {
        _impl.colorSpace.reset(space);
        CGColorSpaceRetain(space);
        return *this;
    }

    inline __CGImage& SetRenderingIntent(CGColorRenderingIntent intent) {
        _impl.renderingIntent = intent;
        return *this;
    }
};

//--Helpers--

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

COREGRAPHICS_EXPORT IWICBitmap* _CGImageGetImageSource(CGImageRef image);

// Obtain a direct pointer to the data.
COREGRAPHICS_EXPORT void* _CGImageGetRawBytes(CGImageRef image);

// Obtain the associated DisplayTexture, return null for images that lack them.
COREGRAPHICS_EXPORT DisplayTexture* _CGImageGetDisplayTexture(CGImageRef image);

REFGUID _CGImageGetWICPixelFormatFromImageProperties(unsigned int bitsPerComponent,
                                                     unsigned int bitsPerPixel,
                                                     CGColorSpaceRef colorSpace,
                                                     CGBitmapInfo bitmapInfo);

// If the image is of the same format, the image is retained and returned.
COREGRAPHICS_EXPORT CGImageRef _CGImageCreateCopyWithPixelFormat(CGImageRef image, WICPixelFormatGUID pixelFormat);

typedef void (*CGImageDestructionListener)(CGImageRef img);
COREGRAPHICS_EXPORT void CGImageAddDestructionListener(CGImageDestructionListener listener);
