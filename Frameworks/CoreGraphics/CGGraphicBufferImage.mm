//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include <math.h>
#include <stdlib.h>

#include "Starboard.h"
#include "CGContextCairo.h"

#include <cairoint.h>

extern int imgDataCount;

CGGraphicBufferImage::CGGraphicBufferImage(DWORD width, DWORD height, surfaceFormat fmt) {
    _img = new CGBitmapImageBacking(width, height, fmt);
    _img->_parent = this;
    _imgType = CGImageTypeBitmap;

    _img->_parent = this;
}

CGGraphicBufferImage::CGGraphicBufferImage(
    DWORD width, DWORD height, surfaceFormat fmt, DisplayTexture* nativeTexture, DisplayTextureLocking* locking) {
    _img = new CGGraphicBufferImageBacking(width, height, fmt, nativeTexture, locking);
    _imgType = CGImageTypeGraphicBuffer;
    _img->_parent = this;
}

CGGraphicBufferImageBacking::CGGraphicBufferImageBacking(
    DWORD width, DWORD height, surfaceFormat fmt, DisplayTexture* nativeTexture, DisplayTextureLocking* locking) {
    EbrIncrement((volatile int*)&imgDataCount);
    EbrDebugLog("Number of images: %d\n", imgDataCount);

    _imageLocks = 0;
    _cairoLocks = 0;
    _width = width;
    _height = height;
    _internalHeight = height;
    _internalWidth = 0;
    _imageData = NULL;
    _surface = NULL;

    _bitmapFmt = fmt;
    switch (_bitmapFmt) {
        case _Color565:
            _bytesPerPixel = 2;
            break;

        case _ColorRGB32:
            _bytesPerPixel = 4;
            break;

        case _ColorRGB32HE:
            _bytesPerPixel = 4;
            break;

        case _ColorARGB:
            _bytesPerPixel = 4;
            break;

        case _ColorRGBA:
            _bytesPerPixel = 4;
            break;

        case _ColorRGB:
            _bytesPerPixel = 4;
            break;

        case _ColorGrayscale:
        case _ColorA8:
            _bytesPerPixel = 1;
            break;
    }
    _bytesPerRow = 0;
    _nativeTexture = nativeTexture;
    _nativeTextureLocking = locking;
    _nativeTextureLocking->RetainDisplayTexture(_nativeTexture);
}

CGGraphicBufferImageBacking::~CGGraphicBufferImageBacking() {
    EbrDecrement((volatile int*)&imgDataCount);
    EbrDebugLog("Destroyed (freeing fasttexture 0x%x) - Number of images: %d\n", _nativeTexture, imgDataCount);

    while (_cairoLocks > 0) {
        EbrDebugLog("Warning: surface lock not released cnt=%d\n", _cairoLocks);
        ReleaseCairoSurface();
    }
    while (_imageLocks > 0) {
        EbrDebugLog("Warning: image lock not released cnt=%d\n", _imageLocks);
        ReleaseImageData();
    }
    if (_nativeTexture)
        _nativeTextureLocking->ReleaseDisplayTexture(_nativeTexture);
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
        _bytesPerPixel = 4;
        _bytesPerRow = stride;
        _internalWidth = stride / _bytesPerPixel;
        _nativeTextureLocking->UnlockWritableBitmapTexture(_nativeTexture);
    }
    return _bytesPerRow;
}

int CGGraphicBufferImageBacking::BytesPerPixel() {
    return _bytesPerPixel;
}

surfaceFormat CGGraphicBufferImageBacking::SurfaceFormat() {
    return _bitmapFmt;
}

void* CGGraphicBufferImageBacking::LockImageData() {
    _imageLocks++;

    if (_imageData)
        return _imageData;

    int stride;
    _imageData = _nativeTextureLocking->LockWritableBitmapTexture(_nativeTexture, &stride);
    _bytesPerPixel = 4;
    _bytesPerRow = stride;
    _internalWidth = stride / _bytesPerPixel;
    return _imageData;
}

void* CGGraphicBufferImageBacking::StaticImageData() {
    assert(0);
    *((char*)0) = 0;
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
        EbrDebugLog("Warning: Image lock over-released\n");
    }
}

cairo_surface_t* CGGraphicBufferImageBacking::LockCairoSurface() {
    _cairoLocks++;
    if (_surface)
        return _surface;

    void* ptr = LockImageData();

    switch (_bitmapFmt) {
        case _ColorARGB:
            _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) +
                                                                          _internalWidth * (_height - 1) * 4,
                                                                      PIXMAN_a8r8g8b8,
                                                                      _width,
                                                                      _height,
                                                                      -_internalWidth * 4);
            break;

        case _ColorRGBA:
            _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) +
                                                                          _internalWidth * (_height - 1) * 4,
                                                                      PIXMAN_a8b8g8r8,
                                                                      _width,
                                                                      _height,
                                                                      -_internalWidth * 4);
            break;

        case _ColorRGB:
            _surface = _cairo_image_surface_create_with_pixman_format(
                ((unsigned char*)_imageData) + _internalWidth * (_height - 1) * _bytesPerPixel,
                PIXMAN_x8b8g8r8,
                _width,
                _height,
                -_internalWidth * _bytesPerPixel);
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
        EbrDebugLog("Warning: surface lock not released cnt=%d\n", _cairoLocks);
        ReleaseCairoSurface();
    }
    while (_imageLocks > 0) {
        EbrDebugLog("Warning: image lock not released cnt=%d\n", _imageLocks);
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

        case _ColorRGBA: {
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
