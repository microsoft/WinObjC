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

#ifndef __CGIMAGEINTERNAL_H
#define __CGIMAGEINTERNAL_H

#include "Starboard.h"
#include "CoreGraphics/CGImage.h"

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

class CGImageBacking {
protected:
    int _imageLocks;
    int _cairoLocks;

public:
    CGImageRef _parent;

    virtual ~CGImageBacking() {
    }

    virtual CGImageRef Copy() = 0;

    virtual CGContextImpl* CreateDrawingContext(CGContextRef base) = 0;
    virtual void GetPixel(int x, int y, float& r, float& g, float& b, float& a) = 0;
    virtual int InternalWidth() = 0;
    virtual int InternalHeight() = 0;
    virtual int Width() = 0;
    virtual int Height() = 0;
    virtual int BytesPerRow() = 0;
    virtual int BytesPerPixel() = 0;
    virtual surfaceFormat SurfaceFormat() = 0;
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

class __CGImage {
protected:
    id isa;
    CGImageBacking* _img;

public:
    bool _has32BitAlpha;
    CGImageType _imgType;
    idretain _provider;

    __CGImage();
    ~__CGImage();

    CGImageBacking* Backing() const {
        return _img;
    }
    CGImageBacking* DetachBacking(CGImageRef newParent);
};

#include "CGBitmapImage.h"
#include "CGGraphicBufferImage.h"
#include "CGVectorImage.h"
#include "CGDiscardableImage.h"
#include "CGPNGDecoderImage.h"
#include "CGJPEGDecoderImage.h"

typedef void (*CGImageDestructionListener)(CGImageRef img);
COREGRAPHICS_EXPORT void CGImageAddDestructionListener(CGImageDestructionListener listener);

#endif
