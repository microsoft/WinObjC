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

#import <math.h>
#import <stdlib.h>
#import <Starboard.h>

#import "CGContextImpl.h"
#import "CGContextCairo.h"
#import "CGSurfaceInfoInternal.h"
#import "CGIWICBitmap.h"

#import "LoggingNative.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-register"

#import <cairoint.h> // uses 'register int'

#pragma clang diagnostic pop

#pragma warning(push)
#pragma warning(disable : 4146)

static const wchar_t* TAG = L"CGBitmapImage";

// NOTE: the negative strides below are to convert from bitmap file format
// (which are generally bottom-up) to in-memory layout.

int imgDataCount = 0, imgDataSize = 0;

CGImageData::CGImageData(const __CGSurfaceInfo& surfaceInfo) {
    EbrIncrement((volatile int*)&imgDataCount);

    _refCount = 1;
    _width = surfaceInfo.width;
    _height = surfaceInfo.height;
    _imageData = surfaceInfo.surfaceData;
    _internalWidth = surfaceInfo.width;
    _internalHeight = surfaceInfo.height;
    _bottomOrientation = FALSE;
    _freeWhenDone = FALSE;
    _bitmapInfo = surfaceInfo.bitmapInfo;
    _bitmapFmt = surfaceInfo.format;
    _bitsPerComponent = surfaceInfo.bitsPerComponent;
    _colorSpaceModel = surfaceInfo.colorSpaceModel;
    _bytesPerPixel = surfaceInfo.bytesPerPixel;

    switch (_bitmapFmt) {
        case _Color565:
            if (!_imageData) {
                _imageData = (void*)IwCalloc(_width * _height, 2);
                _freeWhenDone = TRUE;
                _bytesPerRow = _width * _bytesPerPixel;
                // assert((_bytesPerRow & 3) == 0);
                //_surface = _cairo_image_surface_create_with_pixman_format((unsigned char
                //*) _imageData, PIXMAN_r5g6b5,
                // _width, _height, _width * 2);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _width * (_height - 1) * 2,
                                                                          PIXMAN_r5g6b5,
                                                                          _width,
                                                                          _height,
                                                                          -_width * 2);
                _pixmanFmt = PIXMAN_r5g6b5;
            } else {
                _bytesPerRow = _width * _bytesPerPixel;
                // assert((_bytesPerRow & 3) == 0);
                //_surface = _cairo_image_surface_create_with_pixman_format((unsigned char
                //*) _imageData, PIXMAN_r5g6b5,
                // _width, _height, _width * 2);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _width * (_height - 1) * 2,
                                                                          PIXMAN_r5g6b5,
                                                                          _width,
                                                                          _height,
                                                                          -_width * 2);
                _pixmanFmt = PIXMAN_r5g6b5;
            }
            break;

        case _ColorBGRX:
            if (!_imageData) {
                _imageData = (void*)IwCalloc(_width * _height, 4);
                _freeWhenDone = TRUE;

                _bytesPerRow = _width * _bytesPerPixel;
                //_surface = _cairo_image_surface_create_with_pixman_format(((unsigned
                // char *) _imageData) + _width *
                //(_height - 1) * 4, PIXMAN_x8r8g8b8, _width, _height, -_width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _width * (_height - 1) * 4,
                                                                          PIXMAN_b8g8r8x8,
                                                                          _width,
                                                                          _height,
                                                                          -_width * 4);
                _pixmanFmt = PIXMAN_b8g8r8x8;
            } else {
                _bytesPerRow = _width * _bytesPerPixel;
                //_surface = _cairo_image_surface_create_with_pixman_format(((unsigned
                // char *) _imageData) + _width *
                //(_height - 1) * 4, PIXMAN_x8r8g8b8, _width, _height, -_width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _width * (_height - 1) * 4,
                                                                          PIXMAN_b8g8r8x8,
                                                                          _width,
                                                                          _height,
                                                                          -_width * 4);
                _pixmanFmt = PIXMAN_b8g8r8x8;
            }
            break;

        case _ColorXBGR:
            if (!_imageData) {
                _imageData = (void*)IwCalloc(_width * _height, 4);
                _freeWhenDone = TRUE;

                _bytesPerRow = _width * _bytesPerPixel;
                //_surface = _cairo_image_surface_create_with_pixman_format(((unsigned
                // char *) _imageData) + _width *
                //(_height - 1) * 4, PIXMAN_b8g8r8x8, _width, _height, -_width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _width * (_height - 1) * 4,
                                                                          PIXMAN_x8b8g8r8,
                                                                          _width,
                                                                          _height,
                                                                          -_width * 4);
                _pixmanFmt = PIXMAN_x8b8g8r8;
            } else {
                _bytesPerRow = _width * _bytesPerPixel;
                //_surface = _cairo_image_surface_create_with_pixman_format(((unsigned
                // char *) _imageData) + _width *
                //(_height - 1) * 4, PIXMAN_b8g8r8x8, _width, _height, -_width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _width * (_height - 1) * 4,
                                                                          PIXMAN_x8b8g8r8,
                                                                          _width,
                                                                          _height,
                                                                          -_width * 4);
                _pixmanFmt = PIXMAN_x8b8g8r8;
            }
            break;

        case _ColorARGB:
            if (!_imageData) {
                //_internalWidth = 1 << log2Ceil(width);
                //_internalHeight = 1 << log2Ceil(_height);

                _imageData = (void*)IwCalloc(_internalWidth * _internalHeight, 4);
                _freeWhenDone = TRUE;

                _bytesPerRow = _internalWidth * _bytesPerPixel;
                //_surface = _cairo_image_surface_create_with_pixman_format((unsigned char
                //*) _imageData,
                // PIXMAN_a8r8g8b8, _width, _height, _width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _internalWidth * (_height - 1) * 4,
                                                                          PIXMAN_a8r8g8b8,
                                                                          _width,
                                                                          _height,
                                                                          -_internalWidth * 4);
                _pixmanFmt = PIXMAN_a8r8g8b8;
            } else {
                _bytesPerRow = _width * _bytesPerPixel;
                //_surface = _cairo_image_surface_create_with_pixman_format((unsigned char
                //*) _imageData,
                // PIXMAN_a8r8g8b8, _width, _height, _width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _width * (_height - 1) * 4,
                                                                          PIXMAN_a8r8g8b8,
                                                                          _width,
                                                                          _height,
                                                                          -_width * 4);
                _pixmanFmt = PIXMAN_a8r8g8b8;
            }
            break;

        case _ColorABGR:
            if (!_imageData) {
                //_internalWidth = 1 << log2Ceil(width);
                //_internalHeight = 1 << log2Ceil(_height);

                _imageData = (void*)IwCalloc(_internalWidth * _internalHeight, 4);
                _freeWhenDone = TRUE;

                _bytesPerRow = _internalWidth * _bytesPerPixel;
                //_surface = _cairo_image_surface_create_with_pixman_format((unsigned char
                //*) _imageData,
                // PIXMAN_a8r8g8b8, _width, _height, _width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _internalWidth * (_height - 1) * 4,
                                                                          PIXMAN_a8b8g8r8,
                                                                          _width,
                                                                          _height,
                                                                          -_internalWidth * 4);
                _pixmanFmt = PIXMAN_a8b8g8r8;
            } else {
                _bytesPerRow = _width * _bytesPerPixel;
                //_surface = _cairo_image_surface_create_with_pixman_format((unsigned char
                //*) _imageData,
                // PIXMAN_a8r8g8b8, _width, _height, _width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _width * (_height - 1) * 4,
                                                                          PIXMAN_a8b8g8r8,
                                                                          _width,
                                                                          _height,
                                                                          -_width * 4);
                _pixmanFmt = PIXMAN_a8b8g8r8;
            }
            break;

        case _ColorBGR:
            if (!_imageData) {
                //_internalWidth = 1 << log2Ceil(_width);
                //_internalHeight = 1 << log2Ceil(_height);
                _internalWidth = (_internalWidth + 3) & ~3;

                _bytesPerRow = _internalWidth * _bytesPerPixel;

                _imageData = (void*)IwCalloc(_internalWidth * _internalHeight, 3);
                _freeWhenDone = TRUE;

                //_surface = _cairo_image_surface_create_with_pixman_format((unsigned char
                //*) _imageData,
                // PIXMAN_a8r8g8b8, _width, _height, _width * 4);
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) +
                                                                              _internalWidth * (_height - 1) * _bytesPerPixel,
                                                                          PIXMAN_b8g8r8,
                                                                          _width,
                                                                          _height,
                                                                          -_internalWidth * _bytesPerPixel);
                _pixmanFmt = PIXMAN_b8g8r8;
            } else {
                _bytesPerRow = _width * _bytesPerPixel;

                // assert((_bytesPerRow & 3) == 0);
                //_surface = _cairo_image_surface_create_with_pixman_format((unsigned char
                //*) _imageData,
                // PIXMAN_a8r8g8b8, _width, _height, _width * 4);
                _surface =
                    _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _width * (_height - 1) * _bytesPerPixel,
                                                                   PIXMAN_b8g8r8,
                                                                   _width,
                                                                   _height,
                                                                   -_width * 3);
                _pixmanFmt = PIXMAN_b8g8r8;
            }
            break;

        case _ColorGrayscale:

            TraceWarning(TAG, L"*** Warning: Grayscale not properly implemented ***");
            if (!_imageData) {
                _imageData = (void*)IwCalloc(_width * _height, 1);
                _freeWhenDone = TRUE;

                _bytesPerRow = _width * _bytesPerPixel;
                // assert((_bytesPerRow & 3) == 0);
                /*** BEWARE: pixman doesn't fully support unaligned g8 format .. more work
                * must be done ***/
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _width * (_height - 1) * 1,
                                                                          PIXMAN_g8,
                                                                          _width,
                                                                          _height,
                                                                          -_width * 1);
                _pixmanFmt = PIXMAN_g8;
            } else {
                // assert((_bytesPerRow & 3) == 0);
                _bytesPerRow = _width * _bytesPerPixel;
                /*** BEWARE: pixman doesn't fully support unaligned g8 format .. more work
                * must be done ***/
                _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _width * (_height - 1) * 1,
                                                                          PIXMAN_g8,
                                                                          _width,
                                                                          _height,
                                                                          -_width * 1);
                _pixmanFmt = PIXMAN_g8;
            }
            break;

        case _ColorA8:
            if (!_imageData) {
                _imageData = (void*)IwCalloc(_width * _height, 1);
                _freeWhenDone = TRUE;
            }
            _bytesPerRow = _width * _bytesPerPixel;
            _surface = _cairo_image_surface_create_with_pixman_format(((unsigned char*)_imageData) + _width * (_height - 1) * 1,
                                                                      PIXMAN_a8,
                                                                      _width,
                                                                      _height,
                                                                      -_width * 1);
            _pixmanFmt = PIXMAN_a8;
            break;

        default:
            assert(0);
            break;
    }

    TraceVerbose(TAG, L"Constructed image from addr:%x", _imageData);
    imgDataSize += _internalWidth * _height * _bytesPerPixel;
    TraceVerbose(TAG, L"Allocated %dx%dx%d Number of images: %d (%dKB)", _width, _height, _bytesPerPixel, imgDataCount, imgDataSize / 1024);
}

CGImageData::~CGImageData() {
    EbrDecrement((volatile int*)&imgDataCount);
    imgDataSize -= _internalWidth * _height * _bytesPerPixel;
    TraceVerbose(TAG, L"Destroyed (freeing 0x%x) - Number of images: %d (%dKB total)", _imageData, imgDataCount, imgDataSize / 1024);

    assert(_refCount == 0);
    if (_imageData) {
        if (_freeWhenDone)
            IwFree(_imageData);
        cairo_surface_destroy(_surface);
    }
}

CGImageData* CGImageData::Duplicate() {
    __CGSurfaceInfo surfaceInfo =
        __CGSurfaceInfo(_colorSpaceModel, _bitmapInfo, _bitsPerComponent, _bytesPerPixel, _width, _height, 0, NULL, _bitmapFmt);

    CGImageData* ret = new CGImageData(surfaceInfo);

    BYTE* imgIn = (BYTE*)_imageData;
    BYTE* imgOut = (BYTE*)ret->_imageData;
    for (unsigned y = 0; y < _height; y++) {
        memcpy(imgOut, imgIn, ret->_bytesPerRow);
        imgIn += ret->_bytesPerRow;
        imgOut += _bytesPerRow;
    }

    return ret;
}

CGBitmapImage::CGBitmapImage(const __CGSurfaceInfo& surfaceInfo) {
    _img = new CGBitmapImageBacking(surfaceInfo);
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

CGBitmapImageBacking::CGBitmapImageBacking(const __CGSurfaceInfo& surfaceInfo) {
    _imageLocks = 0;
    _cairoLocks = 0;
    _renderTarget = nullptr;

    _data = new CGImageData(surfaceInfo);
}

CGBitmapImageBacking::CGBitmapImageBacking(CGImageRef img) {
    _imageLocks = 0;
    _cairoLocks = 0;
    _renderTarget = nullptr;

    if (img->_imgType == CGImageTypeBitmap) {
        _data = ((CGBitmapImageBacking*)img->Backing())->_data->Duplicate();
    } else {
        __CGSurfaceInfo surfaceInfo;
        img->Backing()->GetSurfaceInfoWithoutPixelPtr(&surfaceInfo);

        _data = new CGImageData(surfaceInfo);

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
    // release the render target first as it may hold locks on the image
    if (_renderTarget != nullptr) {
        _renderTarget->Release();
    }

    if (_cairoLocks != 0 || _imageLocks != 0) {
        TraceWarning(TAG, L"Warning: Image data not unlocked (refcnt=%d, %d)", _cairoLocks, _imageLocks);

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

int CGBitmapImageBacking::BitsPerComponent() {
    return _data->_bitsPerComponent;
}

ID2D1RenderTarget* CGBitmapImageBacking::GetRenderTarget() {
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

void CGBitmapImageBacking::GetSurfaceInfoWithoutPixelPtr(__CGSurfaceInfo* surfaceInfo) {
    surfaceInfo->width = _data->_width;
    surfaceInfo->height = _data->_height;
    surfaceInfo->bitsPerComponent = _data->_bitsPerComponent;
    surfaceInfo->bytesPerPixel = _data->_bytesPerPixel;
    surfaceInfo->bytesPerRow = 0;
    surfaceInfo->surfaceData = NULL;
    surfaceInfo->colorSpaceModel = _data->_colorSpaceModel;
    surfaceInfo->bitmapInfo = _data->_bitmapInfo;
    surfaceInfo->format = _data->_bitmapFmt;
}

__CGSurfaceFormat CGBitmapImageBacking::SurfaceFormat() {
    return _data->_bitmapFmt;
}

CGColorSpaceModel CGBitmapImageBacking::ColorSpaceModel() {
    return _data->_colorSpaceModel;
}

CGBitmapInfo CGBitmapImageBacking::BitmapInfo() {
    return _data->_bitmapInfo;
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

#pragma warning(pop)
