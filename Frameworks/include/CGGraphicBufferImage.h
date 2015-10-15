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

#pragma once

#include "CGImageInternal.h"

class CGGraphicBufferImage : public __CGImage {
public:
    CGGraphicBufferImage(DWORD width, DWORD height, surfaceFormat fmt);
    CGGraphicBufferImage(DWORD width, DWORD height, surfaceFormat fmt, DisplayTexture* nativeTexture, DisplayTextureLocking* locking);
};

class EbrFastTexture;

class CGGraphicBufferImageBacking : public CGImageBacking {
private:
    void* _imageData;
    cairo_surface_t* _surface;
    surfaceFormat _bitmapFmt;
    DWORD _width, _height;
    DWORD _internalWidth, _internalHeight;
    DWORD _bytesPerRow;
    DWORD _bytesPerPixel;

public:
    DisplayTexture* _nativeTexture;
    DisplayTextureLocking* _nativeTextureLocking;

    CGGraphicBufferImageBacking(
        DWORD width, DWORD height, surfaceFormat fmt, DisplayTexture* nativeTexture, DisplayTextureLocking* locking);
    ~CGGraphicBufferImageBacking();

    CGImageRef Copy();

    CGContextImpl* CreateDrawingContext(CGContextRef base);
    void GetPixel(int x, int y, float& r, float& g, float& b, float& a);
    int InternalWidth();
    int InternalHeight();
    int Width();
    int Height();
    int BytesPerRow();
    int BytesPerPixel();
    surfaceFormat SurfaceFormat();
    void* StaticImageData();
    void* LockImageData();
    void ReleaseImageData();
    cairo_surface_t* LockCairoSurface();
    void ReleaseCairoSurface();
    void SetFreeWhenDone(bool freeWhenDone);
    DisplayTexture* GetDisplayTexture();
};
