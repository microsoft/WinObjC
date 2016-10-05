//******************************************************************************
//
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

#import <StubReturn.h>
#import <Starboard.h>
#import <math.h>
#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGPath.h>
#import <CoreGraphics/CGLayer.h>
#import "CGColorSpaceInternal.h"
#import "CGContextInternal.h"
#include "LoggingNative.h"
#import "_CGLifetimeBridgingType.h"
#import <CoreGraphics/CGAffineTransform.h>
#import <CoreGraphics/CGGradient.h>
#import <Foundation/NSString.h>
#import <UIKit/UIImage.h>
#import <UIKit/UIFont.h>
#import <UIKit/UIColor.h>
#import "CGSurfaceInfoInternal.h"
#import <pthread.h>

#import <CFRuntime.h>

#include <COMIncludes.h>
#import <d2d1.h>
#import <d2d1_1.h>
#import <wrl/client.h>
#include <COMIncludes_end.h>

using namespace Microsoft::WRL;

struct __CGContextImpl {
    ComPtr<ID2D1RenderTarget> _renderTarget;
};

struct __CGContext {
    CFRuntimeBase _base;

    // Use an inline impl struct so that we don't need to placement new each element.
    __CGContextImpl _impl;
    CGContextImpl* (*Backing)(void);
};

static Boolean __CGContextEqual(CFTypeRef cf1, CFTypeRef cf2) {
    return FALSE;
}

static CFHashCode __CGContextHash(CFTypeRef cf) {
    return (CFHashCode)cf;
}

static CFStringRef __CGContextCopyDescription(CFTypeRef cf) {
    return CFStringCreateWithFormat(kCFAllocatorSystemDefault, NULL, CFSTR("<CGContext %p>"), cf);
}

static void __CGContextInit(CFTypeRef cf) {
    CGContextRef context = (CGContextRef)cf;
    struct __CGContext* mutableContext = const_cast<struct __CGContext*>(context);
    new (std::addressof(mutableContext->_impl)) __CGContextImpl();
}

static void __CGContextDeallocate(CFTypeRef cf) {
    CGContextRef context = (CGContextRef)cf;
    context->_impl.~__CGContextImpl();
}

static CFTypeID __kCGContextTypeID = _kCFRuntimeNotATypeID;

static const CFRuntimeClass __CGContextClass = { 0,
                                                 "CGContext",
                                                 __CGContextInit, // init
                                                 NULL,
                                                 __CGContextDeallocate, // deallocate
                                                 NULL,
                                                 NULL,
                                                 NULL,
                                                 __CGContextCopyDescription };

/**
 @Status Interoperable
*/
CFTypeID CGContextGetTypeID() {
    static dispatch_once_t initOnce = 0;
    dispatch_once(&initOnce, ^{
        __kCGContextTypeID = _CFRuntimeRegisterClass(&__CGContextClass);
    });
    return __kCGContextTypeID;
}

static const wchar_t* TAG = L"CGContext";

template <typename T, typename B = decltype(std::declval<T>()->_base)>
T _CFRuntimeCreateInstance(CFTypeID typeID, CFAllocatorRef allocator = kCFAllocatorDefault) {
    return static_cast<T>(const_cast<void*>(_CFRuntimeCreateInstance(allocator, typeID, sizeof(T) - sizeof(B), nullptr)));
}

CGContextRef _CGContextCreateWithD2DRenderTarget(ID2D1RenderTarget* renderTarget) {
    THROW_HR_IF_NULL(E_INVALIDARG, renderTarget);
    CGContextRef context = _CFRuntimeCreateInstance<CGContextRef>(CGContextGetTypeID());
    context->_impl._renderTarget = renderTarget;
    return context;
}

/**
 @Status Interoperable
*/
CGContextRef CGContextRetain(CGContextRef ctx) {
    CFRetain((CFTypeRef)ctx);
    return ctx;
}

/**
 @Status Interoperable
*/
void CGContextRelease(CGContextRef ctx) {
    if (!ctx) {
        return;
    }

    CFRelease((CFTypeRef)ctx);
}

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
#if 0
#define DEBUG_CONTEXT_COUNT

int contextCount = 0;
static IWLazyClassLookup _LazyUIImage("UIImage"), _LazyUIScreen("UIScreen");

pthread_mutex_t _cairoLock = PTHREAD_MUTEX_INITIALIZER;

@interface CGNSContext : _CGLifetimeBridgingType
@end

@implementation CGNSContext
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-missing-super-calls"
- (void)dealloc {
    delete (__CGContext*)self;
}
#pragma clang diagnostic pop
@end

__CGContext::__CGContext(CGImageRef pDest) {
    contextCount++;

#ifdef DEBUG_CONTEXT_COUNT
    TraceVerbose(TAG, L"contextCount: %d", contextCount);
#endif
    object_setClass((id) this, [CGNSContext class]);
    scale = 1.0f;
    _backing = pDest->Backing()->CreateDrawingContext(this);
}

__CGContext::~__CGContext() {
    contextCount--;

    delete _backing;
}

CGContextImpl* __CGContext::Backing() {
    return _backing;
}
#endif

/**
 @Status Interoperable
*/
void CGContextSetBlendMode(CGContextRef ctx, CGBlendMode mode) {
    UNIMPLEMENTED();
}

CGBlendMode CGContextGetBlendMode(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGContextSetFillPattern(CGContextRef ctx, CGPatternRef pattern, const CGFloat* components) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetPatternPhase(CGContextRef ctx, CGSize phase) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetCharacterSpacing(CGContextRef ctx, CGFloat spacing) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextShowTextAtPoint(CGContextRef pContext, CGFloat x, CGFloat y, const char* str, size_t length) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphsAtPoint(CGContextRef ctx, CGFloat x, CGFloat y, const CGGlyph* glyphs, unsigned count) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphsWithAdvances(CGContextRef ctx, const CGGlyph* glyphs, CGSize* advances, unsigned count) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphs(CGContextRef ctx, const CGGlyph* glyphs, unsigned count) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetFont(CGContextRef ctx, CGFontRef font) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetFontSize(CGContextRef ctx, CGFloat ptSize) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetTextMatrix(CGContextRef ctx, CGAffineTransform matrix) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
CGAffineTransform CGContextGetTextMatrix(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGContextSetTextPosition(CGContextRef ctx, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetTextDrawingMode(CGContextRef ctx, CGTextDrawingMode mode) {
    UNIMPLEMENTED();
}

/// TODO(DH): USERSPACE COORDINATE TRANSFORMATION
/**
 @Status Interoperable
*/
CGAffineTransform CGContextGetCTM(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGContextTranslateCTM(CGContextRef ctx, CGFloat x, CGFloat y) {
    CGContextConcatCTM(ctx, CGAffineTransformMakeTranslation(x, y));
}

/**
 @Status Interoperable
*/
void CGContextScaleCTM(CGContextRef ctx, CGFloat sx, CGFloat sy) {
    CGContextConcatCTM(ctx, CGAffineTransformMakeScale(sx, sy));
}

/**
 @Status Interoperable
*/
void CGContextRotateCTM(CGContextRef ctx, CGFloat angle) {
    CGContextConcatCTM(ctx, CGAffineTransformMakeRotation(angle));
}

/**
 @Status Interoperable
*/
void CGContextConcatCTM(CGContextRef ctx, CGAffineTransform t) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetCTM(CGContextRef ctx, CGAffineTransform transform) {
    UNIMPLEMENTED();
}

/// TODO(DH): IMAGE DRAWING
/**
 @Status Interoperable
*/
void CGContextDrawImage(CGContextRef ctx, CGRect rect, CGImageRef image) {
    if (!image) {
        TraceWarning(TAG, L"Img == NULL!");
        return;
    }
    if (!ctx) {
        TraceWarning(TAG, L"CGContextDrawImage: ctx == NULL!");
        return;
    }

    {
    UNIMPLEMENTED();
    }
}

void CGContextDrawImageRect(CGContextRef ctx, CGImageRef image, CGRect src, CGRect dst) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextDrawTiledImage(CGContextRef ctx, CGRect rect, CGImageRef image) {
    UNIMPLEMENTED();
}

/// TODO(DH): CLIPPING AND MASKING
/**
 @Status Interoperable
*/
void CGContextClip(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextClipToRect(CGContextRef ctx, CGRect rect) {
    CGContextBeginPath(ctx);
    CGContextAddRect(ctx, rect);
    CGContextClip(ctx);
}

/**
 @Status Interoperable
*/
void CGContextClipToRects(CGContextRef ctx, const CGRect* rects, unsigned count) {
    CGContextBeginPath(ctx);
    CGContextAddRects(ctx, rects, count);
    CGContextClip(ctx);
}

/**
 @Status Caveat
 @Notes Limited bitmap format support
*/
void CGContextClipToMask(CGContextRef ctx, CGRect dest, CGImageRef image) {
    UNIMPLEMENTED();
}

/// TODO(DH): STROKE COLORS
/**
 @Status Interoperable
*/
void CGContextSetStrokeColor(CGContextRef ctx, const CGFloat* components) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetStrokeColorWithColor(CGContextRef ctx, CGColorRef color) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetStrokeColorSpace(CGContextRef pContext, CGColorSpaceRef colorSpace) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetGrayStrokeColor(CGContextRef ctx, CGFloat gray, CGFloat alpha) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetRGBStrokeColor(CGContextRef ctx, CGFloat r, CGFloat g, CGFloat b, CGFloat a) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextSetCMYKStrokeColor(CGContextRef c, CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha) {
    UNIMPLEMENTED();
}

/// TODO(DH): FILL COLORS
/**
 @Status Interoperable
*/
void CGContextSetFillColor(CGContextRef ctx, const CGFloat* components) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetFillColorWithColor(CGContextRef ctx, CGColorRef color) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetFillColorSpace(CGContextRef pContext, CGColorSpaceRef colorSpace) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetGrayFillColor(CGContextRef ctx, CGFloat gray, CGFloat alpha) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetRGBFillColor(CGContextRef ctx, CGFloat r, CGFloat g, CGFloat b, CGFloat a) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextSetCMYKFillColor(CGContextRef c, CGFloat cyan, CGFloat magenta, CGFloat yellow, CGFloat black, CGFloat alpha) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSelectFont(CGContextRef ctx, const char* name, CGFloat size, CGTextEncoding encoding) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
CGPoint CGContextGetTextPosition(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGContextSaveGState(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextRestoreGState(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextClearRect(CGContextRef ctx, CGRect rect) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextFillRect(CGContextRef ctx, CGRect rect) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextClosePath(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddRect(CGContextRef ctx, CGRect rect) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddRects(CGContextRef ctx, const CGRect* rect, unsigned count) {
    for (unsigned i = 0; i < count; i++) {
        CGContextAddRect(ctx, rect[i]);
    }
}

/**
 @Status Interoperable
*/
void CGContextAddLineToPoint(CGContextRef ctx, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddCurveToPoint(CGContextRef ctx, CGFloat cp1x, CGFloat cp1y, CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddQuadCurveToPoint(CGContextRef ctx, CGFloat cpx, CGFloat cpy, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextMoveToPoint(CGContextRef ctx, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddArc(CGContextRef ctx, CGFloat x, CGFloat y, CGFloat radius, CGFloat startAngle, CGFloat endAngle, int clockwise) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddArcToPoint(CGContextRef ctx, CGFloat x1, CGFloat y1, CGFloat x2, CGFloat y2, CGFloat radius) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddEllipseInRect(CGContextRef ctx, CGRect rect) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextStrokeEllipseInRect(CGContextRef ctx, CGRect rect) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextFillEllipseInRect(CGContextRef ctx, CGRect rect) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextAddPath(CGContextRef ctx, CGPathRef path) {
    // The Apple SDK docs imply that passing a NULL path is valid.
    // So avoid calling into the backing if NULL.
    if (path) {
        UNIMPLEMENTED();
    }
}

/**
 @Status Interoperable
*/
void CGContextStrokePath(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextStrokeRect(CGContextRef ctx, CGRect rect) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextStrokeRectWithWidth(CGContextRef ctx, CGRect rect, CGFloat width) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextFillPath(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextEOFillPath(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextEOClip(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextDrawPath(CGContextRef ctx, CGPathDrawingMode mode) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextFlush(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
bool CGContextIsPathEmpty(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGContextBeginPath(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextDrawLinearGradient(
    CGContextRef ctx, CGGradientRef gradient, CGPoint startPoint, CGPoint endPoint, CGGradientDrawingOptions options) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextDrawRadialGradient(CGContextRef ctx,
                                 CGGradientRef gradient,
                                 CGPoint startCenter,
                                 CGFloat startRadius,
                                 CGPoint endCenter,
                                 CGFloat endRadius,
                                 CGGradientDrawingOptions options) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextDrawShading(CGContextRef ctx, CGShadingRef shading) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextDrawLayerInRect(CGContextRef ctx, CGRect destRect, CGLayerRef layer) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextDrawLayerAtPoint(CGContextRef ctx, CGPoint destPoint, CGLayerRef layer) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetLineDash(CGContextRef ctx, CGFloat phase, const CGFloat* lengths, unsigned count) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetMiterLimit(CGContextRef ctx, CGFloat limit) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetLineJoin(CGContextRef ctx, CGLineJoin lineJoin) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetLineCap(CGContextRef ctx, CGLineCap lineCap) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetLineWidth(CGContextRef ctx, CGFloat width) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetShouldAntialias(CGContextRef ctx, bool shouldAntialias) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetAllowsAntialiasing(CGContextRef context, bool allows) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetAllowsFontSmoothing(CGContextRef context, bool allows) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetAllowsFontSubpixelPositioning(CGContextRef context, bool allows) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetShouldSubpixelPositionFonts(CGContextRef context, bool subpixel) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetAllowsFontSubpixelQuantization(CGContextRef context, bool allows) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetShouldSubpixelQuantizeFonts(CGContextRef context, bool subpixel) {
    UNIMPLEMENTED();
}

/**
 @Status interoperable
*/
void CGContextSetInterpolationQuality(CGContextRef context, CGInterpolationQuality quality) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetShouldSmoothFonts(CGContextRef context, bool shouldSmooth) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextSetRenderingIntent(CGContextRef context, CGColorRenderingIntent intent) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetShadow(CGContextRef context, CGSize offset, CGFloat blur) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextReplacePathWithStrokedPath(CGContextRef context) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
CGRect CGContextGetClipBoundingBox(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
CGRect CGContextGetPathBoundingBox(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGContextAddLines(CGContextRef pContext, const CGPoint* pt, unsigned count) {
    CGContextMoveToPoint(pContext, pt[0].x, pt[0].y);
    for (unsigned i = 1; i < count; i++) {
        CGContextAddLineToPoint(pContext, pt[i].x, pt[i].y);
    }
}

/**
 @Status Interoperable
*/
void CGContextBeginTransparencyLayer(CGContextRef ctx, CFDictionaryRef auxInfo) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextEndTransparencyLayer(CGContextRef ctx) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextStrokeLineSegments(CGContextRef ctx, const CGPoint* segments, unsigned count) {
    CGContextBeginPath(ctx);
    for (unsigned k = 0; k < count; k += 2) {
        CGContextMoveToPoint(ctx, segments[k].x, segments[k].y);
        CGContextAddLineToPoint(ctx, segments[k + 1].x, segments[k + 1].y);
    }
    CGContextStrokePath(ctx);
}

/**
 @Status Interoperable
*/
CGInterpolationQuality CGContextGetInterpolationQuality(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGContextSetAlpha(CGContextRef ctx, CGFloat a) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
CGRect CGContextConvertRectToDeviceSpace(CGContextRef ctx, CGRect rect) {
    UNIMPLEMENTED();
    return rect;
}

/**
 @Status Stub
*/
CGRect CGContextConvertRectToUserSpace(CGContextRef ctx, CGRect rect) {
    UNIMPLEMENTED();
    return rect;
}

/**
 @Status Stub
*/
CGPoint CGContextConvertPointToUserSpace(CGContextRef ctx, CGPoint pt) {
    UNIMPLEMENTED();
    return pt;
}

/**
 @Status Stub
*/
CGSize CGContextConvertSizeToUserSpace(CGContextRef c, CGSize size) {
    UNIMPLEMENTED();
    return size;
}

/**
 @Status Stub
*/
CGSize CGContextConvertSizeToDeviceSpace(CGContextRef ctx, CGSize size) {
    UNIMPLEMENTED();
    return size;
}

/**
 @Status Stub
*/
CGPoint CGContextConvertPointToDeviceSpace(CGContextRef ctx, CGPoint pt) {
    UNIMPLEMENTED();
    return pt;
}

/**
 @Status Stub
*/
void CGContextShowText(CGContextRef ctx, const char* str, unsigned count) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGContextSetShadowWithColor(CGContextRef ctx, CGSize offset, CGFloat blur, CGColorRef color) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextBeginPage(CGContextRef c, const CGRect* mediaBox) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
 @Notes
*/
void CGContextBeginTransparencyLayerWithRect(CGContextRef ctx, CGRect rect, CFDictionaryRef auxInfo) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
 @Notes
*/
CGPathRef CGContextCopyPath(CGContextRef c) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGContextDrawPDFPage(CGContextRef c, CGPDFPageRef page) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextEndPage(CGContextRef c) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextFillRects(CGContextRef c, const CGRect* rects, size_t count) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CGPoint CGContextGetPathCurrentPoint(CGContextRef c) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGAffineTransform CGContextGetUserSpaceToDeviceSpaceTransform(CGContextRef c) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGContextPathContainsPoint(CGContextRef c, CGPoint point, CGPathDrawingMode mode) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGContextSetFlatness(CGContextRef c, CGFloat flatness) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextSetStrokePattern(CGContextRef c, CGPatternRef pattern, const CGFloat* components) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextShowGlyphsAtPositions(CGContextRef c, const CGGlyph* glyphs, const CGPoint* Lpositions, size_t count) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextShowGlyphsWithAdvances(CGContextRef c, const CGGlyph* glyphs, const CGSize* advances, size_t count) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGContextSynchronize(CGContextRef c) {
    UNIMPLEMENTED();
}

// TODO: functions below are not part of offical exports, but they are also exported
// to be used by other framework components, we should consider moving them to a shared library
void CGContextClearToColor(CGContextRef ctx, CGFloat r, CGFloat g, CGFloat b, CGFloat a) {
    UNIMPLEMENTED();
}

bool CGContextIsDirty(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

void CGContextSetDirty(CGContextRef ctx, bool dirty) {
    UNIMPLEMENTED();
}

void CGContextReleaseLock(CGContextRef ctx) {
    UNIMPLEMENTED();
}

CGContextImpl* CGContextGetBacking(CGContextRef ctx) {
    UNIMPLEMENTED();
    return nullptr;
}

bool CGContextIsPointInPath(CGContextRef c, bool eoFill, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
    return StubReturn();
}

void CGContextDrawGlyphRun(CGContextRef ctx, const DWRITE_GLYPH_RUN* glyphRun) {
    ctx->Backing()->CGContextDrawGlyphRun(glyphRun);
}

CGImageRef CGPNGImageCreateFromFile(NSString* path) {
    return new CGPNGDecoderImage([path UTF8String]);
}

CGImageRef CGPNGImageCreateFromData(NSData* data) {
    return new CGPNGDecoderImage(data);
}

CGImageRef CGJPEGImageCreateFromFile(NSString* path) {
    return new CGJPEGDecoderImage([path UTF8String]);
}

CGImageRef CGJPEGImageCreateFromData(NSData* data) {
    return new CGJPEGDecoderImage(data);
}

/**
 @Status Interoperable
*/
CGColorSpaceRef CGBitmapContextGetColorSpace(CGContextRef ctx) {
    // TODO: Consider caching colorspaceRef in CGImageRef
    return (CGColorSpaceRef) new __CGColorSpace(ctx->Backing()->DestImage()->Backing()->ColorSpaceModel());
}

/**
 @Status Caveat
 @Notes Limited bitmap formats available. Decode, shouldInterpolate, intent parameters
 and some byte orders ignored.
 */
CGContextRef CGBitmapContextCreate(void* data,
                                   size_t width,
                                   size_t height,
                                   size_t bitsPerComponent,
                                   size_t bytesPerRow,
                                   CGColorSpaceRef colorSpace,
                                   CGBitmapInfo bitmapInfo) {
#if 0
    CGImageRef newImage = NULL;
    DWORD alphaType = bitmapInfo & kCGBitmapAlphaInfoMask;

    bool colorSpaceAllocated = false;

    if (!colorSpace) {
        if (bytesPerRow >= (width * 3)) {
            TraceWarning(TAG, L"Warning: colorSpace = NULL, assuming RGB based on bytesPerRow.");
            colorSpace = CGColorSpaceCreateDeviceRGB();
        } else {
            TraceWarning(TAG, L"Warning: colorSpace = NULL, assuming Gray based on bytesPerRow.");
            colorSpace = CGColorSpaceCreateDeviceGray();
        }

        colorSpaceAllocated = true;
    }

    const unsigned int numColorComponents = CGColorSpaceGetNumberOfComponents(colorSpace);
    const unsigned int numComponents = numColorComponents + ((alphaType == kCGImageAlphaNone) ? 0 : 1);
    const unsigned int bitsPerPixel = (bitsPerComponent == 5) ? 16 : numComponents * bitsPerComponent;

    __CGSurfaceFormat format = _CGImageGetFormat(bitsPerComponent, bitsPerPixel, colorSpace, bitmapInfo);

    __CGSurfaceInfo surfaceInfo = __CGSurfaceInfo(((__CGColorSpace*)colorSpace)->colorSpaceModel,
                                                  bitmapInfo,
                                                  bitsPerComponent,
                                                  bitsPerPixel >> 3,
                                                  width,
                                                  height,
                                                  bytesPerRow,
                                                  data,
                                                  format);

    newImage = new CGBitmapImage(surfaceInfo);

    CGContextRef ret = new __CGContext(newImage);
    CFRelease((id)newImage);

    if (colorSpaceAllocated == true) {
        CGColorSpaceRelease(colorSpace);
    }

    return ret;
#endif
    return nullptr;
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetWidth(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetHeight(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetBytesPerRow(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void* CGBitmapContextGetData(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Has no copy-on-write semantics; bitmap returned is the source bitmap representing
        the CGContext
*/
CGImageRef CGBitmapContextCreateImage(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

CGImageRef CGBitmapContextGetImage(CGContextRef ctx) {
    UNIMPLEMENTED();
    return StubReturn();
}

CGContextRef _CGBitmapContextCreateWithTexture(int width, int height, DisplayTexture* texture, DisplayTextureLocking* locking) {
    UNIMPLEMENTED();
    return StubReturn();
}

CGContextRef _CGBitmapContextCreateWithFormat(int width, int height, __CGSurfaceFormat fmt) {
    UNIMPLEMENTED();
    return StubReturn();
}

