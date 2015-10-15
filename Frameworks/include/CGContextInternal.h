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

#ifndef __CGCONTEXTINTERNAL_H
#define __CGCONTEXTINTERNAL_H

#include "Starboard.h"
#include "CoreGraphics/CGContext.h"
#include "CGImageInternal.h"

class CGContextImpl;
COREGRAPHICS_EXPORT void EbrCenterTextInRectVertically(CGRect* rect, CGSize* textSize, id font);
COREGRAPHICS_EXPORT CGContextRef CGBitmapContextCreate32(int width,
                                                         int height,
                                                         DisplayTexture* texture = NULL,
                                                         DisplayTextureLocking* locking = NULL);
COREGRAPHICS_EXPORT CGContextRef CGBitmapContextCreate24(int width, int height);
COREGRAPHICS_EXPORT CGImageRef CGBitmapContextGetImage(CGContextRef ctx);
COREGRAPHICS_EXPORT void CGContextDrawImageRect(CGContextRef ctx, CGImageRef img, CGRect src, CGRect dst);
COREGRAPHICS_EXPORT void CGContextClearToColor(CGContextRef ctx, float r, float g, float b, float a);
COREGRAPHICS_EXPORT bool CGContextIsDirty(CGContextRef ctx);
COREGRAPHICS_EXPORT void CGContextSetDirty(CGContextRef ctx, bool dirty);
COREGRAPHICS_EXPORT void CGContextReleaseLock(CGContextRef ctx);
COREGRAPHICS_EXPORT CGContextImpl* CGContextGetBacking(CGContextRef ctx);
COREGRAPHICS_EXPORT CGBlendMode CGContextGetBlendMode(CGContextRef ctx);

COREGRAPHICS_EXPORT CGImageRef CGPNGImageCreateFromFile(NSString* path);
COREGRAPHICS_EXPORT CGImageRef CGPNGImageCreateFromData(NSData* data);

COREGRAPHICS_EXPORT CGImageRef CGJPEGImageCreateFromFile(NSString* path);
COREGRAPHICS_EXPORT CGImageRef CGJPEGImageCreateFromData(NSData* data);

class __CGContext {
public:
    id isa;
    float scale;
    CGContextImpl* _backing;

    __CGContext(CGImageRef pDest);
    ~__CGContext();

    CGContextImpl* Backing();
};
#include "CGContextImpl.h"

#endif
