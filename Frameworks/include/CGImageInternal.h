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

// TODO: Remove CGImageBacking
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

// TODO: use for reverse mapping of GetPixelFormat
typedef struct {
    CGColorSpaceModel colorSpaceModel;
    CGBitmapInfo bitmapInfo;
    BYTE bitsPerComponent;
    BYTE bytesPerPixel;
} __CGImagePixelProperties;

struct __CGImageImpl {
    Microsoft::WRL::ComPtr<IWICBitmapSource> bitmapImageSource;
    CGBitmapInfo bitmapInfo;
    bool isMask;
    bool interpolate;
    CGColorSpaceRef colorSpace;
    CGColorRenderingIntent renderingIntent;

    ~__CGImageImpl() {
        if (colorSpace) {
            CGColorSpaceRelease(colorSpace);
        }
    }
};

struct __CGImage : CoreFoundation::CppBase<__CGImage, __CGImageImpl> {
    inline Microsoft::WRL::ComPtr<IWICBitmapSource>& ImageSource() {
        return _impl.bitmapImageSource;
    }

    inline size_t Height() {
        size_t width, height;
        if (FAILED(_impl.bitmapImageSource->GetSize(&width, &height))) {
            return 0;
        }

        return height;
    }

    inline size_t Width() {
        size_t width, height;
        if (FAILED(_impl.bitmapImageSource->GetSize(&width, &height))) {
            return 0;
        }

        return width;
    }

    inline bool IsMask() {
        return _impl.isMask;
    }

    inline bool Interpolate() {
        return _impl.interpolate;
    }

    inline CGColorSpaceRef ColorSpace() {
        return _impl.colorSpace;
    }

    inline CGColorRenderingIntent RenderingIntent() {
        return _impl.renderingIntent;
    }

    inline CGBitmapInfo BitmapInfo() {
        return _impl.bitmapInfo;
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
        if (_impl.colorSpace) {
            CGColorSpaceRelease(_impl.colorSpace);
        }
        _impl.colorSpace = space;
        CGColorSpaceRetain(space);
        return *this;
    }

    inline __CGImage& SetRenderingIntent(CGColorRenderingIntent intent) {
        _impl.renderingIntent = intent;
        return *this;
    }

    inline __CGImage& SetBitmapInfo(CGBitmapInfo info) {
        _impl.bitmapInfo = info;
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
COREGRAPHICS_EXPORT NSData* _CGImageJPEGRepresentation(CGImageRef image);
COREGRAPHICS_EXPORT NSData* _CGImageRepresentation(CGImageRef image, REFGUID guid);

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
