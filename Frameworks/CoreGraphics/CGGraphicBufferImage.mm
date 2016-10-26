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

#import <Starboard.h>
#import <math.h>
#import <stdlib.h>
#import "CGContextCairo.h"
#import "CGSurfaceInfoInternal.h"
#import "CGIWICBitmap.h"

#import "LoggingNative.h"
#import <CGGraphicBufferImage.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-register"

#import <cairoint.h> // uses 'register int'

#pragma clang diagnostic pop

using namespace Microsoft::WRL;

static const wchar_t* TAG = L"CGGraphicBufferImage";
extern int imgDataCount;

CGGraphicBufferImage::CGGraphicBufferImage(int width, int height, __CGSurfaceFormat fmt) {
    __CGSurfaceInfo surfaceInfo = _CGSurfaceInfoInit(width, height, fmt);

    _img = new CGBitmapImageBacking(surfaceInfo);
    _img->_parent = this;
    _imgType = CGImageTypeBitmap;

    _img->_parent = this;
}

CGGraphicBufferImage::CGGraphicBufferImage(const __CGSurfaceInfo& surfaceInfo) {
    _img = new CGBitmapImageBacking(surfaceInfo);
    _img->_parent = this;
    _imgType = CGImageTypeBitmap;

    _img->_parent = this;
}

CGGraphicBufferImage::CGGraphicBufferImage(const __CGSurfaceInfo& surfaceInfo,
                                           DisplayTexture* nativeTexture,
                                           DisplayTextureLocking* locking) {
    _img = new CGGraphicBufferImageBacking(surfaceInfo, nativeTexture, locking);
    _imgType = CGImageTypeGraphicBuffer;
    _img->_parent = this;
}

CGGraphicBufferImageBacking::CGGraphicBufferImageBacking(const __CGSurfaceInfo& surfaceInfo,
                                                         DisplayTexture* nativeTexture,
                                                         DisplayTextureLocking* locking) {
    EbrIncrement((volatile int*)&imgDataCount);
    TraceVerbose(TAG, L"Number of images: %d", imgDataCount);

    _imageLocks = 0;
    _cairoLocks = 0;
    _width = surfaceInfo.width;
    _height = surfaceInfo.height;
    _internalHeight = surfaceInfo.height;
    _internalWidth = 0;
    _imageData = NULL;
    _surface = NULL;
    _bitmapFmt = surfaceInfo.format;
    _bitsPerComponent = surfaceInfo.bitsPerComponent;
    _colorSpaceModel = surfaceInfo.colorSpaceModel;
    _bytesPerPixel = surfaceInfo.bytesPerPixel;
    _bitmapInfo = surfaceInfo.bitmapInfo;
    _bytesPerRow = 0;
    _nativeTexture = nativeTexture;
    _nativeTextureLocking = locking;
    _nativeTextureLocking->RetainDisplayTexture(_nativeTexture);
    _renderTarget = nullptr;
}

CGGraphicBufferImageBacking::~CGGraphicBufferImageBacking() {
    EbrDecrement((volatile int*)&imgDataCount);
    TraceVerbose(TAG, L"Destroyed (freeing fasttexture 0x%x) - Number of images: %d", _nativeTexture, imgDataCount);

    if (_renderTarget != nullptr) {
        _renderTarget->Release();
    }
    while (_cairoLocks > 0) {
        TraceWarning(TAG, L"Warning: surface lock not released cnt=%d", _cairoLocks);
        ReleaseCairoSurface();
    }
    while (_imageLocks > 0) {
        TraceWarning(TAG, L"Warning: image lock not released cnt=%d", _imageLocks);
        ReleaseImageData();
    }
    if (_nativeTexture) {
        _nativeTextureLocking->ReleaseDisplayTexture(_nativeTexture);
    }
}

CGContextImpl* CGGraphicBufferImageBacking::CreateDrawingContext(CGContextRef base) {
    return new CGContextCairo(base, _parent);
}

CGImageRef CGGraphicBufferImageBacking::Copy() {
    CGBitmapImage* ret = new CGBitmapImage(this->_parent);

    return ret;
}

int CGGraphicBufferImageBacking::Width() {
    return _width;
}

int CGGraphicBufferImageBacking::Height() {
    return _height;
}

int CGGraphicBufferImageBacking::InternalWidth() {
    BytesPerRow();
    return _internalWidth;
}

int CGGraphicBufferImageBacking::InternalHeight() {
    return _internalHeight;
}

int CGGraphicBufferImageBacking::BytesPerRow() {
    if (_bytesPerRow == 0) {
        int stride;
        _nativeTextureLocking->LockWritableBitmapTexture(_nativeTexture, &stride);
        _bytesPerRow = stride;
        _internalWidth = stride / _bytesPerPixel;
        _nativeTextureLocking->UnlockWritableBitmapTexture(_nativeTexture);
    }
    return _bytesPerRow;
}

int CGGraphicBufferImageBacking::BytesPerPixel() {
    return _bytesPerPixel;
}

int CGGraphicBufferImageBacking::BitsPerComponent() {
    return _bitsPerComponent;
}

ID2D1RenderTarget* CGGraphicBufferImageBacking::GetRenderTarget() {
    if (_renderTarget == nullptr) {
        BYTE* imageData = static_cast<BYTE*>(LockImageData());
        ComPtr<IWICBitmap> wicBitmap = Make<CGIWICBitmap>(this, SurfaceFormat());
        ComPtr<ID2D1Factory> d2dFactory;
        THROW_IF_FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, __uuidof(ID2D1Factory), &d2dFactory));
        ComPtr<ID2D1RenderTarget> renderTarget;
        THROW_IF_FAILED(d2dFactory->CreateWicBitmapRenderTarget(wicBitmap.Get(), D2D1::RenderTargetProperties(), &renderTarget));
        _renderTarget = renderTarget.Detach();
        ReleaseImageData();
    }

    return _renderTarget;
}

void CGGraphicBufferImageBacking::GetSurfaceInfoWithoutPixelPtr(__CGSurfaceInfo* surfaceInfo) {
    surfaceInfo->width = _width;
    surfaceInfo->height = _height;
    surfaceInfo->bitsPerComponent = _bitsPerComponent;
    surfaceInfo->bytesPerPixel = _bytesPerPixel;
    surfaceInfo->bytesPerRow = 0;
    surfaceInfo->surfaceData = NULL;
    surfaceInfo->colorSpaceModel = _colorSpaceModel;
    surfaceInfo->bitmapInfo = _bitmapInfo;
    surfaceInfo->format = _bitmapFmt;
}

__CGSurfaceFormat CGGraphicBufferImageBacking::SurfaceFormat() {
    return _bitmapFmt;
}

CGColorSpaceModel CGGraphicBufferImageBacking::ColorSpaceModel() {
    return _colorSpaceModel;
}

CGBitmapInfo CGGraphicBufferImageBacking::BitmapInfo() {
    return _bitmapInfo;
}

void* CGGraphicBufferImageBacking::LockImageData() {
    _imageLocks++;

    if (_imageData)
        return _imageData;

    int stride;
    _imageData = _nativeTextureLocking->LockWritableBitmapTexture(_nativeTexture, &stride);
    _bytesPerRow = stride;
    _internalWidth = stride / _bytesPerPixel;
    return _imageData;
}

void* CGGraphicBufferImageBacking::StaticImageData() {
    UNIMPLEMENTED();
    return _imageData;
}

void CGGraphicBufferImageBacking::ReleaseImageData() {
    if (_imageLocks > 0) {
        _imageLocks--;

        if (_imageLocks == 0) {
            _nativeTextureLocking->UnlockWritableBitmapTexture(_nativeTexture);
            _imageData = NULL;
        }
    } else {
        TraceWarning(TAG, L"Warning: Image lock over-released");
    }
}

cairo_surface_t* CGGraphicBufferImageBacking::LockCairoSurface() {
    _cairoLocks++;
    if (_surface)
        return _surface;

    void* ptr = LockImageData();

    switch (_bitmapFmt) {
        case _ColorARGB:
            _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _internalWidth * (_height - 1) * 4,
                                                                      PIXMAN_a8r8g8b8,
                                                                      _width,
                                                                      _height,
                                                                      -_internalWidth * 4);
            break;

        case _ColorABGR:
            _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _internalWidth * (_height - 1) * 4,
                                                                      PIXMAN_a8b8g8r8,
                                                                      _width,
                                                                      _height,
                                                                      -_internalWidth * 4);
            break;

        case _ColorBGR:
            _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) +
                                                                          _internalWidth * (_height - 1) * _bytesPerPixel,
                                                                      PIXMAN_b8g8r8,
                                                                      _width,
                                                                      _height,
                                                                      -_internalWidth * _bytesPerPixel);
            break;
        case _ColorXBGR:
            _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) +
                                                                          _internalWidth * (_height - 1) * _bytesPerPixel,
                                                                      PIXMAN_x8b8g8r8,
                                                                      _width,
                                                                      _height,
                                                                      -_internalWidth * _bytesPerPixel);
            break;

        case _Color565:
        case _ColorBGRX:
        case _ColorGrayscale:
        case _ColorA8:
        case _ColorIndexed:
        default:
            UNIMPLEMENTED_WITH_MSG("Unsupported bitmap format %d", _bitmapFmt);
            break;
    }

    return _surface;
}

void CGGraphicBufferImageBacking::ReleaseCairoSurface() {
    _cairoLocks--;
    assert(_cairoLocks >= 0);
    if (_cairoLocks == 0) {
        cairo_surface_destroy(_surface);
        _surface = NULL;
        ReleaseImageData();
    }
}

void CGGraphicBufferImageBacking::SetFreeWhenDone(bool freeWhenDone) {
}

DisplayTexture* CGGraphicBufferImageBacking::GetDisplayTexture() {
    while (_cairoLocks > 0) {
        TraceWarning(TAG, L"Warning: surface lock not released cnt=%d", _cairoLocks);
        ReleaseCairoSurface();
    }
    while (_imageLocks > 0) {
        TraceWarning(TAG, L"Warning: image lock not released cnt=%d", _imageLocks);
        ReleaseImageData();
    }

    return _nativeTexture;
}

void CGGraphicBufferImageBacking::GetPixel(int x, int y, float& r, float& g, float& b, float& a) {
    if (x < 0 || x >= Width() || y < 0 || y >= Height()) {
        r = g = b = a = 0.0f;
        return;
    }

    switch (SurfaceFormat()) {
        case _Color565: {
            WORD srcPixel = *(((WORD*)LockImageData()) + (Height() - y - 1) * (BytesPerRow() >> 1) + x);
            ReleaseImageData();

            r = ((float)(srcPixel & 0x1F)) / 31.0f;
            g = (float)((srcPixel >> 5) & 0x3F) / 63.0f;
            b = (float)((srcPixel >> 11) & 0x1F) / 31.0f;
            a = 1.0f;
        } break;

        case _ColorARGB: {
            DWORD srcPixel = *(((DWORD*)LockImageData()) + (Height() - y - 1) * (BytesPerRow() >> 2) + x);
            ReleaseImageData();

            r = ((float)(srcPixel & 0xFF)) / 255.0f;
            g = (float)((srcPixel >> 8) & 0xFF) / 255.0f;
            b = (float)((srcPixel >> 16) & 0xFF) / 255.0f;
            a = (float)((srcPixel >> 24) & 0xFF) / 255.0f;
        } break;

        case _ColorABGR: {
            DWORD srcPixel = *(((DWORD*)LockImageData()) + (Height() - y - 1) * (BytesPerRow() >> 2) + x);
            ReleaseImageData();

            a = ((float)(srcPixel & 0xFF)) / 255.0f;
            b = (float)((srcPixel >> 8) & 0xFF) / 255.0f;
            g = (float)((srcPixel >> 16) & 0xFF) / 255.0f;
            r = (float)((srcPixel >> 24) & 0xFF) / 255.0f;
        } break;

        case _ColorGrayscale: {
            BYTE srcPixel = *(((BYTE*)LockImageData()) + (Height() - y - 1) * BytesPerRow() + x);
            ReleaseImageData();

            a = 1.0f;
            r = ((float)srcPixel) / 255.0f;
            g = ((float)srcPixel) / 255.0f;
            b = ((float)srcPixel) / 255.0f;
        } break;

        default:
            assert(0);
    }
}
