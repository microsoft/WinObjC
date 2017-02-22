//******************************************************************************
//
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

#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGImage.h>

#include <COMIncludes.h>
#import <DWrite.h>
#import <D2d1.h>
#import <wincodec.h>
#include <COMIncludes_End.h>

#import "CoreGraphicsInternal.h"

// Context Internal
COREGRAPHICS_EXPORT CGContextRef _CGContextCreateWithD2DRenderTarget(ID2D1RenderTarget* renderTarget);
COREGRAPHICS_EXPORT void _CGContextSetShadowProjectionTransform(CGContextRef context, CGAffineTransform transform);
COREGRAPHICS_EXPORT void _CGContextDrawImageRect(CGContextRef ctx, CGImageRef img, CGRect src, CGRect dst);
COREGRAPHICS_EXPORT void CGContextClearToColor(CGContextRef ctx, float r, float g, float b, float a);
COREGRAPHICS_EXPORT bool CGContextIsDirty(CGContextRef ctx);
COREGRAPHICS_EXPORT void CGContextSetDirty(CGContextRef ctx, bool dirty);
COREGRAPHICS_EXPORT void CGContextReleaseLock(CGContextRef ctx);
COREGRAPHICS_EXPORT CGBlendMode CGContextGetBlendMode(CGContextRef ctx);
COREGRAPHICS_EXPORT bool CGContextIsPointInPath(CGContextRef c, bool eoFill, float x, float y);

// Bitmap Context Internal
COREGRAPHICS_EXPORT CGContextRef _CGBitmapContextCreateWithRenderTarget(ID2D1RenderTarget* renderTarget,
                                                                        CGImageRef img,
                                                                        WICPixelFormatGUID outputPixelFormat);
COREGRAPHICS_EXPORT CGContextRef _CGBitmapContextCreateWithFormat(int width, int height, __CGSurfaceFormat fmt);
COREGRAPHICS_EXPORT CGImageRef CGBitmapContextGetImage(CGContextRef ctx);

// Reduces the number of BeginDraw() and EndDraw() calls needed, by counting in a stack-like manner,
// and only calling BeginDraw()/EndDraw() when the stack is empty/emptied
COREGRAPHICS_EXPORT void _CGContextPushBeginDraw(CGContextRef ctx);
COREGRAPHICS_EXPORT void _CGContextPopEndDraw(CGContextRef ctx);

// Struct used to hold information about glyph run for drawing in _CGContextDrawGlyphRuns
// TODO #1987: Add support for CTRun text matrix
struct GlyphRunData {
    DWRITE_GLYPH_RUN* run;
    CGPoint relativePosition;
    CFDictionaryRef attributes;
};

COREGRAPHICS_EXPORT void _CGContextDrawGlyphRuns(CGContextRef ctx, GlyphRunData* glyphRuns, size_t runCount);

inline bool _GlyphRunIsRTL(const DWRITE_GLYPH_RUN& run) {
    return (run.bidiLevel & 1);
}

COREGRAPHICS_EXPORT const CFStringRef _kCGCharacterShapeAttributeName;
COREGRAPHICS_EXPORT const CFStringRef _kCGFontAttributeName;
COREGRAPHICS_EXPORT const CFStringRef _kCGKernAttributeName;
COREGRAPHICS_EXPORT const CFStringRef _kCGLigatureAttributeName;
COREGRAPHICS_EXPORT const CFStringRef _kCGForegroundColorAttributeName;
COREGRAPHICS_EXPORT const CFStringRef _kCGForegroundColorFromContextAttributeName;
COREGRAPHICS_EXPORT const CFStringRef _kCGParagraphStyleAttributeName;
COREGRAPHICS_EXPORT const CFStringRef _kCGStrokeWidthAttributeName;
COREGRAPHICS_EXPORT const CFStringRef _kCGStrokeColorAttributeName;
COREGRAPHICS_EXPORT const CFStringRef _kCGSuperscriptAttributeName;
COREGRAPHICS_EXPORT const CFStringRef _kCGUnderlineColorAttributeName;
COREGRAPHICS_EXPORT const CFStringRef _kCGUnderlineStyleAttributeName;
COREGRAPHICS_EXPORT const CFStringRef _kCGVerticalFormsAttributeName;
COREGRAPHICS_EXPORT const CFStringRef _kCGGlyphInfoAttributeName;
COREGRAPHICS_EXPORT const CFStringRef _kCGRunDelegateAttributeName;
