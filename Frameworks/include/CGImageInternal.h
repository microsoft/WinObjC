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

#include <COMIncludes.h>
#import <D2d1.h>
#import "Wincodec.h"
#import <wrl/client.h>
#include <COMIncludes_End.h>

struct _cairo_surface;
typedef struct _cairo_surface cairo_surface_t;

class CGContextImpl;
class DisplayTexture;

class DisplayTextureLocking {
public:
    virtual void* LockWritableBitmapTexture(DisplayTexture* tex, int* stride) = 0;
    virtual void UnlockWritableBitmapTexture(DisplayTexture* tex) = 0;
    virtual void RetainDisplayTexture(DisplayTexture* tex) = 0;
    virtual void ReleaseDisplayTexture(DisplayTexture* tex) = 0;
};

// TODO #1124: Remove CGImageBacking
class CGImageBacking {
protected:
    int _imageLocks;
    int _cairoLocks;

public:
    CGImageRef _parent;

    virtual ~CGImageBacking() {
    }

    virtual CGImageRef Copy() = 0;

    virtual void GetPixel(int x, int y, float& r, float& g, float& b, float& a) = 0;
    virtual int InternalWidth() = 0;
    virtual int InternalHeight() = 0;
    virtual int Width() = 0;
    virtual int Height() = 0;
    virtual int BytesPerRow() = 0;
    virtual int BytesPerPixel() = 0;
    virtual int BitsPerComponent() = 0;
    virtual ID2D1RenderTarget* GetRenderTarget() = 0;
    virtual void GetSurfaceInfoWithoutPixelPtr(__CGSurfaceInfo* surfaceInfo) = 0;
    virtual __CGSurfaceFormat SurfaceFormat() = 0;
    virtual CGColorSpaceModel ColorSpaceModel() = 0;
    virtual CGBitmapInfo BitmapInfo() = 0;
    virtual void* StaticImageData() = 0;
    virtual void* LockImageData() = 0;
    virtual void ReleaseImageData() = 0;
    virtual cairo_surface_t* LockCairoSurface() = 0;
    virtual void ReleaseCairoSurface() = 0;
    virtual void SetFreeWhenDone(bool freeWhenDone) = 0;
    virtual DisplayTexture* GetDisplayTexture() {
        return NULL;
    }

    virtual void DiscardIfPossible() {
    }
    virtual void ConstructIfNeeded() {
    }
    virtual bool DrawDirectlyToContext(CGContextImpl* ctx, CGRect src, CGRect dest) {
        return false;
    }
    virtual CGImageRef CopyOnWrite();
};

typedef enum {
    CGImageTypeBitmap,
    CGImageTypeGraphicBuffer,
    CGImageTypeNoData,
    CGImageTypeOpenGL,
    CGImageTypeVector,
    CGImageTypePNG,
    CGImageTypeJPEG
} CGImageType;

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
    Microsoft::WRL::ComPtr<IWICBitmapSource> bitmapImageSource;
    bool isMask;
    bool interpolate;
    woc::unique_cf<CGColorSpaceRef> colorSpace;
    CGColorRenderingIntent renderingIntent;

    __CGImageImpl() {
        isMask = false;
        interpolate = false;
        renderingIntent = kCGRenderingIntentDefault;
    }

    inline size_t Height() const {
        size_t width = 0;
        size_t height = 0;
        RETURN_RESULT_IF_FAILED(bitmapImageSource->GetSize(&width, &height), 0);

        return height;
    }

    inline size_t Width() const {
        size_t width = 0;
        size_t height = 0;
        RETURN_RESULT_IF_FAILED(bitmapImageSource->GetSize(&width, &height), 0);

        return width;
    }

    // TODO: Add cavet everywhere for how format changes
    inline WICPixelFormatGUID PixelFormat() const {
        WICPixelFormatGUID pixelFormat;
        RETURN_RESULT_IF_FAILED(bitmapImageSource->GetPixelFormat(&pixelFormat), GUID_WICPixelFormatUndefined);
        return pixelFormat;
    }

    inline const __CGImagePixelProperties* __Properties() const {
        WICPixelFormatGUID pixelFormat = PixelFormat();
        RETURN_NULL_IF(pixelFormat == GUID_WICPixelFormatUndefined);

        auto iterator = s_PixelFormats.find(pixelFormat);
        RETURN_NULL_IF(iterator == s_PixelFormats.end());

        return &iterator->second;
    }

    inline const __CGImagePixelProperties* Properties() const {
        static const __CGImagePixelProperties* properties = __Properties();
        return properties;
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
        if (colorSpace.get()) {
            const __CGImagePixelProperties* properties = Properties();
            RETURN_NULL_IF(!properties);
            colorSpace.reset(_CGColorSpaceCreate(properties->colorSpaceModel));
        }
        return colorSpace.get();
    }
};

struct __CGImage : CoreFoundation::CppBase<__CGImage, __CGImageImpl> {
    inline Microsoft::WRL::ComPtr<IWICBitmapSource>& ImageSource() {
        return _impl.bitmapImageSource;
    }

    inline size_t Height() const {
        static size_t height = _impl.Height();
        return height;
    }

    inline size_t Width() const {
        static size_t width = _impl.Width();
        return width;
    }

    inline bool IsMask() const {
        return _impl.isMask;
    }

    inline bool Interpolate() const {
        return _impl.interpolate;
    }

    inline CGColorSpaceRef ColorSpace() {
        static CGColorSpaceRef colorSpace = _impl.ColorSpace();
        return colorSpace;
    }

    inline CGColorRenderingIntent RenderingIntent() const {
        return _impl.renderingIntent;
    }

    inline CGBitmapInfo BitmapInfo() const {
        static CGBitmapInfo bitmapInfo = _impl.BitmapInfo();
        return bitmapInfo;
    }

    inline CGImageAlphaInfo AlphaInfo() const {
        static CGImageAlphaInfo alphaInfo = _impl.AlphaInfo();
        return alphaInfo;
    }

    inline size_t BitsPerPixel() const {
        size_t bitsPerPixel = _impl.BitsPerPixel();
        return bitsPerPixel;
    }

    inline size_t BitsPerComponent() const {
        size_t bitsPerComponent = _impl.BitsPerComponent();
        return bitsPerComponent;
    }

    inline __CGImage& SetImageSource(Microsoft::WRL::ComPtr<IWICBitmapSource> source) {
        _impl.bitmapImageSource = source;
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

    //---Old to be removed //
    CGImageBacking* _img;
    bool _has32BitAlpha;
    CGImageType _imgType;
    idretain _provider;

    inline CGImageBacking* Backing() const {
        return _img;
    }

    inline CGImageBacking* DetachBacking(CGImageRef newParent) {
        CGImageBacking* ret = _img;

        _img->_parent = newParent;
        _img = NULL;

        return ret;
    }
    //--End Old code //
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

REFGUID _CGImageGetWICPixelFormat(unsigned int bitsPerComponent,
                                  unsigned int bitsPerPixel,
                                  CGColorSpaceRef colorSpace,
                                  CGBitmapInfo bitmapInfo);

#import "CGBitmapImage.h"
#import "CGGraphicBufferImage.h"
#import "CGVectorImage.h"
#import "CGDiscardableImage.h"
#import "CGPNGDecoderImage.h"
#import "CGJPEGDecoderImage.h"

typedef void (*CGImageDestructionListener)(CGImageRef img);
COREGRAPHICS_EXPORT void CGImageAddDestructionListener(CGImageDestructionListener listener);
