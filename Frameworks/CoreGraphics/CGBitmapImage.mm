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
#include "CGContextImpl.h"
#include "CGContextCairo.h"

#include <cairoint.h>

#pragma warning(push)
#pragma warning(disable : 4146)

// NOTE: the negative strides below are to convert from bitmap file format
// (which are generally bottom-up) to in-memory layout.

int imgDataCount = 0, imgDataSize = 0;

CGImageData::CGImageData(DWORD width, DWORD height, surfaceFormat fmt, void* data) {
    EbrIncrement((volatile int*)&imgDataCount);

    _refCount = 1;
    _width = width;
    _height = height;
    _imageData = data;
    _internalWidth = width;
    _internalHeight = height;
    _bottomOrientation = FALSE;
    _freeWhenDone = FALSE;

    // EbrDebugLog("Creating bitmap\n");

    switch (fmt) {
        case _Color565:
            if (!_imageData) {
                _imageData = (void*)EbrCalloc(_width * height, 2);
                _freeWhenDone = TRUE;

                _bytesPerPixel = 2;
                _bytesPerRow = _width * _bytesPerPixel;
                // assert((_bytesPerRow & 3) == 0);
                //_surface = _cairo_image_surface_create_with_pixman_format((unsigned char
                //*) _imageData, PIXMAN_r5g6b5,
                // width, height, width * 2);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + width * (height - 1) * 2,
                                                                          PIXMAN_r5g6b5,
                                                                          width,
                                                                          height,
                                                                          -width * 2);
                _pixmanFmt = PIXMAN_r5g6b5;
            } else {
                _bytesPerPixel = 2;
                _bytesPerRow = _width * _bytesPerPixel;
                // assert((_bytesPerRow & 3) == 0);
                //_surface = _cairo_image_surface_create_with_pixman_format((unsigned char
                //*) _imageData, PIXMAN_r5g6b5,
                // width, height, width * 2);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + width * (height - 1) * 2,
                                                                          PIXMAN_r5g6b5,
                                                                          width,
                                                                          height,
                                                                          -width * 2);
                _pixmanFmt = PIXMAN_r5g6b5;
            }
            break;

        case _ColorRGB32:
            if (!_imageData) {
                _imageData = (void*)EbrCalloc(_width * height, 4);
                _freeWhenDone = TRUE;

                _bytesPerPixel = 4;
                _bytesPerRow = _width * _bytesPerPixel;
                //_surface = _cairo_image_surface_create_with_pixman_format(((unsigned
                // char *) _imageData) + width *
                //(height - 1) * 4, PIXMAN_x8r8g8b8, width, height, -width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + width * (height - 1) * 4,
                                                                          PIXMAN_b8g8r8x8,
                                                                          width,
                                                                          height,
                                                                          -width * 4);
                _pixmanFmt = PIXMAN_b8g8r8x8;
            } else {
                _bytesPerPixel = 4;
                _bytesPerRow = _width * _bytesPerPixel;
                //_surface = _cairo_image_surface_create_with_pixman_format(((unsigned
                // char *) _imageData) + width *
                //(height - 1) * 4, PIXMAN_x8r8g8b8, width, height, -width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + width * (height - 1) * 4,
                                                                          PIXMAN_b8g8r8x8,
                                                                          width,
                                                                          height,
                                                                          -width * 4);
                _pixmanFmt = PIXMAN_b8g8r8x8;
            }
            break;

        case _ColorRGB32HE:
            if (!_imageData) {
                _imageData = (void*)EbrCalloc(_width * height, 4);
                _freeWhenDone = TRUE;

                _bytesPerPixel = 4;
                _bytesPerRow = _width * _bytesPerPixel;
                //_surface = _cairo_image_surface_create_with_pixman_format(((unsigned
                // char *) _imageData) + width *
                //(height - 1) * 4, PIXMAN_b8g8r8x8, width, height, -width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + width * (height - 1) * 4,
                                                                          PIXMAN_x8b8g8r8,
                                                                          width,
                                                                          height,
                                                                          -width * 4);
                _pixmanFmt = PIXMAN_x8b8g8r8;
            } else {
                _bytesPerPixel = 4;
                _bytesPerRow = _width * _bytesPerPixel;
                //_surface = _cairo_image_surface_create_with_pixman_format(((unsigned
                // char *) _imageData) + width *
                //(height - 1) * 4, PIXMAN_b8g8r8x8, width, height, -width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + width * (height - 1) * 4,
                                                                          PIXMAN_x8b8g8r8,
                                                                          width,
                                                                          height,
                                                                          -width * 4);
                _pixmanFmt = PIXMAN_x8b8g8r8;
            }
            break;

        case _ColorARGB:
            if (!_imageData) {
                //_internalWidth = 1 << log2Ceil(width);
                //_internalHeight = 1 << log2Ceil(height);

                _imageData = (void*)EbrCalloc(_internalWidth * _internalHeight, 4);
                _freeWhenDone = TRUE;

                _bytesPerPixel = 4;
                _bytesPerRow = _internalWidth * _bytesPerPixel;
                //_surface = _cairo_image_surface_create_with_pixman_format((unsigned char
                //*) _imageData,
                // PIXMAN_a8r8g8b8, width, height, width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _internalWidth * (height - 1) * 4,
                                                                          PIXMAN_a8r8g8b8,
                                                                          width,
                                                                          height,
                                                                          -_internalWidth * 4);
                _pixmanFmt = PIXMAN_a8r8g8b8;
            } else {
                _bytesPerPixel = 4;
                _bytesPerRow = _width * _bytesPerPixel;
                //_surface = _cairo_image_surface_create_with_pixman_format((unsigned char
                //*) _imageData,
                // PIXMAN_a8r8g8b8, width, height, width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + width * (height - 1) * 4,
                                                                          PIXMAN_a8r8g8b8,
                                                                          width,
                                                                          height,
                                                                          -width * 4);
                _pixmanFmt = PIXMAN_a8r8g8b8;
            }
            break;

        case _ColorRGBA:
            if (!_imageData) {
                //_internalWidth = 1 << log2Ceil(width);
                //_internalHeight = 1 << log2Ceil(height);

                _imageData = (void*)EbrCalloc(_internalWidth * _internalHeight, 4);
                _freeWhenDone = TRUE;

                _bytesPerPixel = 4;
                _bytesPerRow = _internalWidth * _bytesPerPixel;
                //_surface = _cairo_image_surface_create_with_pixman_format((unsigned char
                //*) _imageData,
                // PIXMAN_a8r8g8b8, width, height, width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _internalWidth * (height - 1) * 4,
                                                                          PIXMAN_a8b8g8r8,
                                                                          width,
                                                                          height,
                                                                          -_internalWidth * 4);
                _pixmanFmt = PIXMAN_a8b8g8r8;
            } else {
                _bytesPerPixel = 4;
                _bytesPerRow = _width * _bytesPerPixel;
                //_surface = _cairo_image_surface_create_with_pixman_format((unsigned char
                //*) _imageData,
                // PIXMAN_a8r8g8b8, width, height, width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + width * (height - 1) * 4,
                                                                          PIXMAN_a8b8g8r8,
                                                                          width,
                                                                          height,
                                                                          -width * 4);
                _pixmanFmt = PIXMAN_a8b8g8r8;
            }
            break;

        case _ColorRGB:
            if (!_imageData) {
                //_internalWidth = 1 << log2Ceil(width);
                //_internalHeight = 1 << log2Ceil(height);
                _internalWidth = (_internalWidth + 3) & ~3;

                _bytesPerPixel = 3;
                _bytesPerRow = _internalWidth * _bytesPerPixel;

                _imageData = (void*)EbrCalloc(_internalWidth * _internalHeight, 3);
                _freeWhenDone = TRUE;

                //_surface = _cairo_image_surface_create_with_pixman_format((unsigned char
                //*) _imageData,
                // PIXMAN_a8r8g8b8, width, height, width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) +
                                                                              _internalWidth * (height - 1) * _bytesPerPixel,
                                                                          PIXMAN_b8g8r8,
                                                                          width,
                                                                          height,
                                                                          -_internalWidth * _bytesPerPixel);
                _pixmanFmt = PIXMAN_b8g8r8;
            } else {
                _bytesPerPixel = 3;
                _bytesPerRow = _width * _bytesPerPixel;

                // assert((_bytesPerRow & 3) == 0);
                //_surface = _cairo_image_surface_create_with_pixman_format((unsigned char
                //*) _imageData,
                // PIXMAN_a8r8g8b8, width, height, width * 4);
                _surface =
                    _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + width * (height - 1) * _bytesPerPixel,
                                                                   PIXMAN_b8g8r8,
                                                                   width,
                                                                   height,
                                                                   -width * 3);
                _pixmanFmt = PIXMAN_b8g8r8;
            }
            break;

        case _ColorGrayscale:
            EbrDebugLog("*** Warning: Grayscale not properly implemented ***\n");
            if (!_imageData) {
                _imageData = (void*)EbrCalloc(_width * height, 1);
                _freeWhenDone = TRUE;

                _bytesPerPixel = 1;
                _bytesPerRow = _width * _bytesPerPixel;
                // assert((_bytesPerRow & 3) == 0);
                /*** BEWARE: pixman doesn't fully support unaligned g8 format .. more work
                 * must be done ***/
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + width * (height - 1) * 1,
                                                                          PIXMAN_g8,
                                                                          width,
                                                                          height,
                                                                          -width * 1);
                _pixmanFmt = PIXMAN_g8;
            } else {
                _bytesPerPixel = 1;
                // assert((_bytesPerRow & 3) == 0);
                _bytesPerRow = _width * _bytesPerPixel;
                /*** BEWARE: pixman doesn't fully support unaligned g8 format .. more work
                 * must be done ***/
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + width * (height - 1) * 1,
                                                                          PIXMAN_g8,
                                                                          width,
                                                                          height,
                                                                          -width * 1);
                _pixmanFmt = PIXMAN_g8;
            }
            break;

        case _ColorA8:
            if (!_imageData) {
                _imageData = (void*)EbrCalloc(_width * height, 1);
                _freeWhenDone = TRUE;
            }
            _bytesPerPixel = 1;
            _bytesPerRow = _width * _bytesPerPixel;
            _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + width * (height - 1) * 1,
                                                                      PIXMAN_a8,
                                                                      width,
                                                                      height,
                                                                      -width * 1);
            _pixmanFmt = PIXMAN_a8;
            break;

        default:
            assert(0);
            break;
    }

    EbrDebugLog("Constructed image from addr:%x\n", _imageData);
    imgDataSize += _internalWidth * _height * _bytesPerPixel;
    EbrDebugLog("Allocated %dx%dx%d Number of images: %d (%dKB)\n", _width, _height, _bytesPerPixel, imgDataCount, imgDataSize / 1024);

    _bitmapFmt = fmt;
}

CGImageData::~CGImageData() {
    EbrDecrement((volatile int*)&imgDataCount);
    imgDataSize -= _internalWidth * _height * _bytesPerPixel;
    EbrDebugLog("Destroyed (freeing 0x%x) - Number of images: %d (%dKB total)\n", _imageData, imgDataCount, imgDataSize / 1024);

    assert(_refCount == 0);
    if (_imageData) {
        if (_freeWhenDone)
            EbrFree(_imageData);
        cairo_surface_destroy(_surface);
    }
}

CGImageData* CGImageData::Duplicate() {
    CGImageData* ret = new CGImageData(_width, _height, _bitmapFmt, NULL);

    BYTE* imgIn = (BYTE*)_imageData;
    BYTE* imgOut = (BYTE*)ret->_imageData;
    for (unsigned y = 0; y < _height; y++) {
        memcpy(imgOut, imgIn, ret->_bytesPerRow);
        imgIn += ret->_bytesPerRow;
        imgOut += _bytesPerRow;
    }

    return ret;
}

CGBitmapImage::CGBitmapImage(DWORD width, DWORD height, surfaceFormat fmt) {
    _img = new CGBitmapImageBacking(width, height, fmt);
    _img->_parent = this;
    _imgType = CGImageTypeBitmap;
}

CGBitmapImage::CGBitmapImage(DWORD width, DWORD height, surfaceFormat fmt, void* dataptr) {
    _img = new CGBitmapImageBacking(width, height, fmt, dataptr);
    _img->_parent = this;
    _imgType = CGImageTypeBitmap;
}

CGBitmapImage::CGBitmapImage(CGImageRef img) {
    _img = new CGBitmapImageBacking(img);
    _img->_parent = this;
    _imgType = CGImageTypeBitmap;
}

CGContextImpl* CGBitmapImageBacking::CreateDrawingContext(CGContextRef base) {
    return new CGContextCairo(base, _parent);
}

CGBitmapImageBacking::CGBitmapImageBacking(DWORD width, DWORD height, surfaceFormat fmt) {
    _imageLocks = 0;
    _cairoLocks = 0;

    _data = new CGImageData(width, height, fmt, NULL);
}

CGBitmapImageBacking::CGBitmapImageBacking(DWORD width, DWORD height, surfaceFormat fmt, void* dataptr) {
    _imageLocks = 0;
    _cairoLocks = 0;

    _data = new CGImageData(width, height, fmt, dataptr);
}

CGBitmapImageBacking::CGBitmapImageBacking(CGImageRef img) {
    _imageLocks = 0;
    _cairoLocks = 0;

    if (img->_imgType == CGImageTypeBitmap) {
        _data = ((CGBitmapImageBacking*)img->Backing())->_data->Duplicate();
    } else {
        _data = new CGImageData(img->Backing()->Width(), img->Backing()->Height(), img->Backing()->SurfaceFormat(), NULL);

        cairo_t* drawContext = cairo_create(LockCairoSurface());
        cairo_surface_t* copySurface = img->Backing()->LockCairoSurface();

        cairo_pattern_t* p = cairo_pattern_create_for_surface(copySurface);
        cairo_set_source(drawContext, p);
        cairo_rectangle(drawContext, 0, 0, img->Backing()->Width(), img->Backing()->Height());
        cairo_paint(drawContext);
        cairo_pattern_destroy(p);
        cairo_destroy(drawContext);

        ReleaseCairoSurface();
        img->Backing()->ReleaseCairoSurface();
    }
}

CGBitmapImageBacking::~CGBitmapImageBacking() {
    if (_cairoLocks != 0 || _imageLocks != 0) {
        EbrDebugLog("Warning: Image data not unlocked (refcnt=%d, %d)\n", _cairoLocks, _imageLocks);

        while (_cairoLocks > 0) {
            ReleaseCairoSurface();
        }
        while (_imageLocks > 0) {
            ReleaseImageData();
        }
    }

    _data->_refCount--;

    if (_data->_refCount == 0) {
        delete _data;
    }
}

CGImageRef CGBitmapImageBacking::Copy() {
    CGBitmapImage* ret = new CGBitmapImage(this->_parent);

    return ret;
}

CGImageRef CGBitmapImageBacking::CopyOnWrite() {
    CGImageRef ret = _parent;
    CGImageRetain(ret);
    return ret;
}

int CGBitmapImageBacking::Width() {
    return _data->_width;
}

int CGBitmapImageBacking::Height() {
    return _data->_height;
}

int CGBitmapImageBacking::InternalWidth() {
    return _data->_internalWidth;
}

int CGBitmapImageBacking::InternalHeight() {
    return _data->_internalHeight;
}

int CGBitmapImageBacking::BytesPerRow() {
    return _data->_bytesPerRow;
}

int CGBitmapImageBacking::BytesPerPixel() {
    return _data->_bytesPerPixel;
}

surfaceFormat CGBitmapImageBacking::SurfaceFormat() {
    return _data->_bitmapFmt;
}

void* CGBitmapImageBacking::LockImageData() {
    EbrIncrement(&_imageLocks);
    return _data->_imageData;
}

void* CGBitmapImageBacking::StaticImageData() {
    return _data->_imageData;
}

void CGBitmapImageBacking::ReleaseImageData() {
    EbrDecrement(&_imageLocks);
    assert(_imageLocks >= 0);
}

cairo_surface_t* CGBitmapImageBacking::LockCairoSurface() {
    EbrIncrement(&_cairoLocks);
    return _data->_surface;
}

void CGBitmapImageBacking::ReleaseCairoSurface() {
    EbrDecrement(&_cairoLocks);
    assert(_cairoLocks >= 0);
}

void CGBitmapImageBacking::SetFreeWhenDone(bool freeWhenDone) {
    _data->_freeWhenDone = freeWhenDone;
}

void CGBitmapImageBacking::GetPixel(int x, int y, float& r, float& g, float& b, float& a) {
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

#pragma warning(pop)
