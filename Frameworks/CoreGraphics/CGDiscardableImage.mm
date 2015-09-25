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
#include "CoreGraphics/CGContext.h"
#include "CGContextImpl.h"

CGContextImpl* CGDiscardableImageBacking::CreateDrawingContext(CGContextRef base) {
    return _forward->CreateDrawingContext(base);
}

CGDiscardableImageBacking::CGDiscardableImageBacking() {
    _forward = NULL;
    _hasCachedInfo = false;
    _cachedSurfaceFormat = _Color565;
    _cachedWidth = -1;
    _cachedHeight = -1;
}

CGDiscardableImageBacking::~CGDiscardableImageBacking() {
    if (_forward) {
        delete _forward;
    }
}

void CGDiscardableImageBacking::ConstructIfNeeded() {
    if (_forward == NULL) {
        _forward = ConstructBacking();
        _cachedWidth = _forward->Width();
        _cachedHeight = _forward->Height();
    }
}

void CGDiscardableImageBacking::DiscardIfPossible() {
    if (_forward != NULL && _cairoLocks == 0 && _imageLocks == 0) {
        delete _forward;
        _forward = NULL;
    }
}

CGImageRef CGDiscardableImageBacking::Copy() {
    ConstructIfNeeded();

    return _forward->Copy();
}

int CGDiscardableImageBacking::Width() {
    if (!_forward) {
        if (_cachedWidth != -1) {
            return _cachedWidth;
        }
    }
    ConstructIfNeeded();

    return _forward->Width();
}

int CGDiscardableImageBacking::Height() {
    if (!_forward) {
        if (_cachedHeight != -1) {
            return _cachedHeight;
        }
    }
    ConstructIfNeeded();

    return _forward->Height();
}

int CGDiscardableImageBacking::InternalWidth() {
    ConstructIfNeeded();

    return _forward->InternalWidth();
}

int CGDiscardableImageBacking::InternalHeight() {
    ConstructIfNeeded();

    return _forward->InternalHeight();
}

int CGDiscardableImageBacking::BytesPerRow() {
    ConstructIfNeeded();

    return _forward->BytesPerRow();
}

int CGDiscardableImageBacking::BytesPerPixel() {
    ConstructIfNeeded();

    return _forward->BytesPerPixel();
}

surfaceFormat CGDiscardableImageBacking::SurfaceFormat() {
    if (!_forward) {
        if (_hasCachedInfo) {
            return _cachedSurfaceFormat;
        }
    }

    ConstructIfNeeded();

    return _forward->SurfaceFormat();
}

void* CGDiscardableImageBacking::LockImageData() {
    ConstructIfNeeded();

    return _forward->LockImageData();
}

void* CGDiscardableImageBacking::StaticImageData() {
    ConstructIfNeeded();

    return _forward->StaticImageData();
}

void CGDiscardableImageBacking::ReleaseImageData() {
    ConstructIfNeeded();

    return _forward->ReleaseImageData();
}

cairo_surface_t* CGDiscardableImageBacking::LockCairoSurface() {
    ConstructIfNeeded();

    return _forward->LockCairoSurface();
}

void CGDiscardableImageBacking::ReleaseCairoSurface() {
    ConstructIfNeeded();

    return _forward->ReleaseCairoSurface();
}

void CGDiscardableImageBacking::SetFreeWhenDone(bool freeWhenDone) {
    ConstructIfNeeded();

    _forward->SetFreeWhenDone(freeWhenDone);
}

void CGDiscardableImageBacking::GetPixel(int x, int y, float& r, float& g, float& b, float& a) {
    ConstructIfNeeded();

    _forward->GetPixel(x, y, r, g, b, a);
}

ImageDataStreamFile::ImageDataStreamFile(EbrFile* in) {
    fpIn = in;
}

ImageDataStreamFile::~ImageDataStreamFile() {
    EbrFclose(fpIn);
}

int ImageDataStreamFile::readData(void* in, int len) {
    int ret = EbrFread(in, 1, len, fpIn);

    return ret;
}

ImageDataStreamMemory::ImageDataStreamMemory(const void* in, int len) {
    data = (char*)in;
    dataLeft = len;
}

int ImageDataStreamMemory::readData(void* in, int len) {
    int toCopy = dataLeft > len ? len : dataLeft;

    memcpy(in, data, toCopy);
    data += toCopy;
    dataLeft -= toCopy;

    return toCopy;
}
