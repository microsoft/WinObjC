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

#include <COMIncludes.h>
#import <DWrite.h>
#include <COMIncludes_End.h>

#import "CGImageInternal.h"
#import "CoreGraphics/CGContext.h"
#import "CoreGraphicsInternal.h"
#import "Starboard.h"

#import <objc/runtime.h>
#import <atomic>

class CGContextImpl;
COREGRAPHICS_EXPORT void EbrCenterTextInRectVertically(CGRect* rect, CGSize* textSize, id font);
COREGRAPHICS_EXPORT CGContextRef _CGBitmapContextCreateWithTexture(int width, int height, const std::shared_ptr<IDisplayTexture>& texture);
COREGRAPHICS_EXPORT CGContextRef _CGBitmapContextCreateWithFormat(int width, int height, __CGSurfaceFormat fmt);
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
COREGRAPHICS_EXPORT bool CGContextIsPointInPath(CGContextRef c, bool eoFill, float x, float y);

COREGRAPHICS_EXPORT void CGContextDrawGlyphRun(CGContextRef ctx, const DWRITE_GLYPH_RUN* glyphRun);

// Reduces the number of BeginDraw() and EndDraw() calls needed, by counting in a stack-like manner,
// and only calling BeginDraw()/EndDraw() when the stack is empty/emptied
COREGRAPHICS_EXPORT void _CGContextPushBeginDraw(CGContextRef ctx);
COREGRAPHICS_EXPORT void _CGContextPopEndDraw(CGContextRef ctx);

// If currently in a Begin/EndDraw stack, Escape will EndDraw(), Unescape will BeginDraw()
// For scenarios where a Begin/EndDraw pair needs to be temporarily escaped, to be returned to at a later time
// Ie:
//      - Switching render targets - Illegal to do so if currently in a Begin/EndDraw pair
//      - Cairo - ID2D1RenderTarget is considered to 'own' the bitmap during Begin/EndDraw,
//                unsafe to edit the same bitmap from cairo at this time
// Also counts in a stack-like manner, so that the escape and unescape only happen once
COREGRAPHICS_EXPORT void _CGContextEscapeBeginEndDrawStack(CGContextRef ctx);
COREGRAPHICS_EXPORT void _CGContextUnescapeBeginEndDrawStack(CGContextRef ctx);

// TODO 1077:: Remove once D2D render target is implemented
COREGRAPHICS_EXPORT void _CGContextSetScaleFactor(CGContextRef ctx, float scale);

class __CGContext : private objc_object {
public:
    float scale;
    CGContextImpl* _backing;

    // Keeps track of the depth of a 'stack' of PushBeginDraw/PopEndDraw calls
    // Since nothing needs to actually be put on a stack, just increment a counter insteads
    std::atomic_uint32_t _beginEndDrawDepth = { 0 };

    // Keeps track of the depth of a 'stack' of (Un)EscapeBeginEndDrawStack calls
    std::atomic_uint32_t _escapeBeginEndDrawDepth = { 0 };

    __CGContext(CGImageRef pDest);
    ~__CGContext();

    CGContextImpl* Backing();
};

#include "CGContextImpl.h"