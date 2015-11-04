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

#include "Starboard.h"
#include "CoreGraphics/CGContext.h"
#include "CGContextInternal.h"
#include "CGColorSpaceInternal.h"
#include "UIKit/UIImage.h"
#include "UIKit/UIFont.h"
#include "UIKit/UIColor.h"

#include "Foundation/NSString.h"
#include "CoreGraphics/CGPath.h"
#include "CoreGraphics/CGLayer.h"
#include "CoreGraphics/CGAffineTransform.h"
#include "CoreGraphics/CGGradient.h"

#define DEBUG_CONTEXT_COUNT

int contextCount = 0;
static IWLazyClassLookup _LazyUIImage("UIImage"), _LazyUIScreen("UIScreen");

EbrLock _cairoLock = EBRLOCK_INITIALIZE;

@interface CGNSContext : NSObject {
}
@end

@implementation CGNSContext
- (void)dealloc {
    delete (__CGContext*)self;
}
@end

__CGContext::__CGContext(CGImageRef pDest) {
    contextCount++;

#ifdef DEBUG_CONTEXT_COUNT
    EbrDebugLog("contextCount: %d\n", contextCount);
#endif
    isa = NULL;
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

/**
 @Status Interoperable
*/
void CGContextSetBlendMode(CGContextRef ctx, CGBlendMode mode) {
    ctx->Backing()->CGContextSetBlendMode(mode);
}

CGBlendMode CGContextGetBlendMode(CGContextRef ctx) {
    return ctx->Backing()->CGContextGetBlendMode();
}

/**
 @Status Interoperable
*/
void CGContextSetFillPattern(CGContextRef ctx, CGPatternRef pattern, const float* components) {
    return ctx->Backing()->CGContextSetFillPattern(pattern, components);
}

/**
 @Status Stub
*/
void CGContextSetPatternPhase(CGContextRef ctx, CGSize phase) {
    UNIMPLEMENTED();
    EbrDebugLog("CGContextSetPatternPhase not implemented\n");
}

/**
 @Status Stub
*/
void CGContextSetCharacterSpacing(CGContextRef ctx, float spacing) {
    UNIMPLEMENTED();
    EbrDebugLog("CGContextSetCharacterSpacing not implemented\n");
}

/**
 @Status Interoperable
*/
void CGContextShowTextAtPoint(CGContextRef pContext, float x, float y, const char* str, size_t length) {
    pContext->Backing()->CGContextShowTextAtPoint(x, y, str, length);
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphsAtPoint(CGContextRef ctx, float x, float y, const CGGlyph* glyphs, unsigned count) {
    ctx->Backing()->CGContextShowGlyphsAtPoint(x, y, (WORD*)glyphs, count);
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphsWithAdvances(CGContextRef ctx, const CGGlyph* glyphs, CGSize* advances, unsigned count) {
    ctx->Backing()->CGContextShowGlyphsWithAdvances((WORD*)glyphs, advances, count);
}

/**
 @Status Interoperable
*/
void CGContextShowGlyphs(CGContextRef ctx, const CGGlyph* glyphs, unsigned count) {
    ctx->Backing()->CGContextShowGlyphs((WORD*)glyphs, count);
}

/**
 @Status Interoperable
*/
void CGContextSetFont(CGContextRef ctx, CGFontRef font) {
    ctx->Backing()->CGContextSetFont((id)font);
}

/**
 @Status Interoperable
*/
void CGContextSetFontSize(CGContextRef ctx, float ptSize) {
    ctx->Backing()->CGContextSetFontSize(ptSize);
}

/**
 @Status Interoperable
*/
void CGContextSetTextMatrix(CGContextRef ctx, CGAffineTransform matrix) {
    ctx->Backing()->CGContextSetTextMatrix(matrix);
}

/**
 @Status Interoperable
*/
CGAffineTransform CGContextGetTextMatrix(CGContextRef ctx) {
    CGAffineTransform ret;

    ctx->Backing()->CGContextGetTextMatrix(&ret);

    return ret;
}

/**
 @Status Interoperable
*/
void CGContextSetTextPosition(CGContextRef ctx, float x, float y) {
    ctx->Backing()->CGContextSetTextPosition(x, y);
}

/**
 @Status Interoperable
*/
void CGContextSetTextDrawingMode(CGContextRef ctx, CGTextDrawingMode mode) {
    ctx->Backing()->CGContextSetTextDrawingMode(mode);
}

/**
 @Status Interoperable
*/
CGAffineTransform CGContextGetCTM(CGContextRef ctx) {
    return ctx->Backing()->CGContextGetCTM();
}

/**
 @Status Interoperable
*/
void CGContextTranslateCTM(CGContextRef ctx, float x, float y) {
    ctx->Backing()->CGContextTranslateCTM(x, y);
}

/**
 @Status Interoperable
*/
void CGContextScaleCTM(CGContextRef ctx, float sx, float sy) {
    ctx->Backing()->CGContextScaleCTM(sx, sy);
}

/**
 @Status Interoperable
*/
void CGContextRotateCTM(CGContextRef ctx, float angle) {
    ctx->Backing()->CGContextRotateCTM(angle);
}

/**
 @Status Interoperable
*/
void CGContextConcatCTM(CGContextRef ctx, CGAffineTransform t) {
    ctx->Backing()->CGContextConcatCTM(t);
}

/**
 @Status Interoperable
*/
void CGContextSetCTM(CGContextRef ctx, CGAffineTransform transform) {
    ctx->Backing()->CGContextSetCTM(transform);
}

/**
 @Status Interoperable
*/
void CGContextRelease(CGContextRef ctx) {
    if (!ctx) {
        EbrDebugLog("CGCOntextRelease NULL!\n");
        return;
    }

    CFRelease((id)ctx);
}

/**
 @Status Interoperable
*/
void CGContextDrawImage(CGContextRef ctx, CGRect rct, CGImageRef img) {
    if (img == NULL) {
        EbrDebugLog("Img == NULL!\n");
        return;
    }
    if (ctx == NULL) {
        EbrDebugLog("CGContextDrawImage: ctx == NULL!\n");
        return;
    }

    ctx->Backing()->CGContextDrawImage(rct, img);
}

void CGContextDrawImageRect(CGContextRef ctx, CGImageRef img, CGRect src, CGRect dst) {
    ctx->Backing()->CGContextDrawImageRect(img, src, dst);
}

/**
 @Status Interoperable
*/
void CGContextDrawTiledImage(CGContextRef ctx, CGRect rct, CGImageRef img) {
    ctx->Backing()->CGContextDrawTiledImage(rct, img);
}

/**
 @Status Caveat
 @Notes Limited bitmap format support
*/
void CGContextClipToMask(CGContextRef ctx, CGRect dest, CGImageRef img) {
    ctx->Backing()->CGContextClipToMask(dest, img);
}

/**
 @Status Interoperable
*/
void CGContextSetGrayFillColor(CGContextRef ctx, float gray, float alpha) {
    ctx->Backing()->CGContextSetGrayFillColor(gray, alpha);
}

/**
 @Status Interoperable
*/
void CGContextSetStrokeColor(CGContextRef ctx, const float* components) {
    ctx->Backing()->CGContextSetStrokeColor((float*)components);
}

/**
 @Status Interoperable
*/
void CGContextSetStrokeColorWithColor(CGContextRef ctx, CGColorRef color) {
    ctx->Backing()->CGContextSetStrokeColorWithColor((id)color);
}

/**
 @Status Interoperable
*/
void CGContextSetFillColorWithColor(CGContextRef ctx, CGColorRef color) {
    ctx->Backing()->CGContextSetFillColorWithColor((id)color);
}

/**
 @Status Interoperable
*/
void CGContextSetFillColor(CGContextRef ctx, const float* components) {
    ctx->Backing()->CGContextSetFillColor((float*)components);
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
void CGContextSelectFont(CGContextRef ctx, const char* name, float size, CGTextEncoding encoding) {
    ctx->Backing()->CGContextSelectFont((char*)name, size, encoding);
}

/**
 @Status Interoperable
*/
CGPoint CGContextGetTextPosition(CGContextRef ctx) {
    CGPoint ret;
    ctx->Backing()->CGContextGetTextPosition(&ret);

    return ret;
}

/**
 @Status Interoperable
*/
void CGContextSaveGState(CGContextRef ctx) {
    ctx->Backing()->CGContextSaveGState();
}

/**
 @Status Interoperable
*/
void CGContextRestoreGState(CGContextRef ctx) {
    ctx->Backing()->CGContextRestoreGState();
}

/**
 @Status Interoperable
*/
void CGContextClearRect(CGContextRef ctx, CGRect rct) {
    if (!ctx) {
        return;
    }

    ctx->Backing()->CGContextClearRect(rct);
}

/**
 @Status Interoperable
*/
void CGContextFillRect(CGContextRef ctx, CGRect rct) {
    ctx->Backing()->CGContextFillRect(rct);
}

/**
 @Status Interoperable
*/
void CGContextClosePath(CGContextRef ctx) {
    ctx->Backing()->CGContextClosePath();
}

/**
 @Status Interoperable
*/
void CGContextAddRect(CGContextRef ctx, CGRect rct) {
    ctx->Backing()->CGContextAddRect(rct);
}

/**
 @Status Interoperable
*/
void CGContextAddRects(CGContextRef ctx, const CGRect* rct, unsigned count) {
    for (unsigned i = 0; i < count; i++) {
        CGContextAddRect(ctx, rct[i]);
    }
}

/**
 @Status Interoperable
*/
void CGContextAddLineToPoint(CGContextRef ctx, float x, float y) {
    ctx->Backing()->CGContextAddLineToPoint(x, y);
}

/**
 @Status Interoperable
*/
void CGContextAddCurveToPoint(CGContextRef ctx, float cp1x, float cp1y, float cp2x, float cp2y, float x, float y) {
    ctx->Backing()->CGContextAddCurveToPoint(cp1x, cp1y, cp2x, cp2y, x, y);
}

/**
 @Status Interoperable
*/
void CGContextAddQuadCurveToPoint(CGContextRef ctx, float cpx, float cpy, float x, float y) {
    ctx->Backing()->CGContextAddQuadCurveToPoint(cpx, cpy, x, y);
}

/**
 @Status Interoperable
*/
void CGContextMoveToPoint(CGContextRef ctx, float x, float y) {
    ctx->Backing()->CGContextMoveToPoint(x, y);
}

/**
 @Status Interoperable
*/
void CGContextAddArc(CGContextRef ctx, float x, float y, float radius, float startAngle, float endAngle, bool clockwise) {
    ctx->Backing()->CGContextAddArc(x, y, radius, startAngle, endAngle, clockwise);
}

/**
 @Status Interoperable
*/
void CGContextAddArcToPoint(CGContextRef ctx, float x1, float y1, float x2, float y2, float radius) {
    ctx->Backing()->CGContextAddArcToPoint(x1, y1, x2, y2, radius);
}

/**
 @Status Interoperable
*/
void CGContextAddEllipseInRect(CGContextRef ctx, CGRect rct) {
    ctx->Backing()->CGContextAddEllipseInRect(rct);
}

/**
 @Status Interoperable
*/
void CGContextStrokeEllipseInRect(CGContextRef ctx, CGRect rct) {
    ctx->Backing()->CGContextStrokeEllipseInRect(rct);
}

/**
 @Status Interoperable
*/
void CGContextFillEllipseInRect(CGContextRef ctx, CGRect rct) {
    ctx->Backing()->CGContextFillEllipseInRect(rct);
}

/**
 @Status Interoperable
*/
void CGContextAddPath(CGContextRef ctx, CGPathRef path) {
    ctx->Backing()->CGContextAddPath((id)path);
}

/**
 @Status Interoperable
*/
void CGContextStrokePath(CGContextRef ctx) {
    ctx->Backing()->CGContextStrokePath();
}

/**
 @Status Interoperable
*/
void CGContextStrokeRect(CGContextRef ctx, CGRect rct) {
    ctx->Backing()->CGContextStrokeRect(rct);
}

/**
 @Status Interoperable
*/
void CGContextStrokeRectWithWidth(CGContextRef ctx, CGRect rct, float width) {
    ctx->Backing()->CGContextStrokeRectWithWidth(rct, width);
}

/**
 @Status Interoperable
*/
void CGContextFillPath(CGContextRef ctx) {
    ctx->Backing()->CGContextFillPath();
}

/**
 @Status Interoperable
*/
void CGContextEOFillPath(CGContextRef ctx) {
    ctx->Backing()->CGContextEOFillPath();
}

/**
 @Status Interoperable
*/
void CGContextEOClip(CGContextRef ctx) {
    ctx->Backing()->CGContextEOClip();
}

/**
 @Status Interoperable
*/
void CGContextDrawPath(CGContextRef ctx, CGPathDrawingMode mode) {
    ctx->Backing()->CGContextDrawPath(mode);
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
    return ctx->Backing()->CGContextIsPathEmpty() != FALSE;
}

/**
 @Status Interoperable
*/
void CGContextBeginPath(CGContextRef ctx) {
    ctx->Backing()->CGContextBeginPath();
}

/**
 @Status Interoperable
*/
void CGContextDrawLinearGradient(
    CGContextRef ctx, CGGradientRef gradient, CGPoint startPoint, CGPoint endPoint, CGGradientDrawingOptions options) {
    ctx->Backing()->CGContextDrawLinearGradient(gradient, startPoint, endPoint, options);
}

/**
 @Status Interoperable
*/
void CGContextDrawRadialGradient(CGContextRef ctx,
                                 CGGradientRef gradient,
                                 CGPoint startCenter,
                                 float startRadius,
                                 CGPoint endCenter,
                                 float endRadius,
                                 CGGradientDrawingOptions options) {
    ctx->Backing()->CGContextDrawRadialGradient(gradient, startCenter, startRadius, endCenter, endRadius, options);
}

/**
 @Status Stub
*/
void CGContextDrawShading(CGContextRef ctx, CGShadingRef shading) {
    UNIMPLEMENTED();
    // CGContextDrawLinearGradient(ctx, (CGGradientRef) shading->_gradient,
    // shading->_start, shading->_end, 0);
}

/**
 @Status Stub
*/
void CGContextDrawLayerInRect(CGContextRef ctx, CGRect destRect, CGLayerRef layer) {
    UNIMPLEMENTED();
    ctx->Backing()->CGContextDrawLayerInRect(destRect, layer);
}

/**
 @Status Stub
*/
void CGContextDrawLayerAtPoint(CGContextRef ctx, CGPoint destPoint, CGLayerRef layer) {
    UNIMPLEMENTED();
    ctx->Backing()->CGContextDrawLayerAtPoint(destPoint, layer);
}

/**
 @Status Interoperable
*/
void CGContextSetLineDash(CGContextRef ctx, float phase, const float* lengths, unsigned count) {
    ctx->Backing()->CGContextSetLineDash(phase, (float*)lengths, count);
}

/**
 @Status Stub
*/
void CGContextSetMiterLimit(CGContextRef ctx, float limit) {
    UNIMPLEMENTED();
    ctx->Backing()->CGContextSetMiterLimit(limit);
}

/**
 @Status Interoperable
*/
void CGContextSetLineJoin(CGContextRef ctx, CGLineJoin lineJoin) {
    ctx->Backing()->CGContextSetLineJoin(lineJoin);
}

/**
 @Status Interoperable
*/
void CGContextSetLineCap(CGContextRef ctx, CGLineCap lineCap) {
    ctx->Backing()->CGContextSetLineCap(lineCap);
}

/**
 @Status Interoperable
*/
void CGContextSetLineWidth(CGContextRef ctx, float width) {
    if (!ctx) {
        EbrDebugLog("CGContextSetLineWidth: no context!\n");
        return;
    }

    ctx->Backing()->CGContextSetLineWidth(width);
}

/**
 @Status Stub
*/
void CGContextSetShouldAntialias(CGContextRef ctx, bool shouldAntialias) {
    UNIMPLEMENTED();
    ctx->Backing()->CGContextSetShouldAntialias(shouldAntialias);
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
 @Status Stub
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
 @Status Stub
*/
void CGContextSetShadow(CGContextRef context, CGSize offset, float blur) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CGContextReplacePathWithStrokedPath(CGContextRef context) {
    UNIMPLEMENTED();
    EbrDebugLog("CGContextReplacePathWithStrokedPath not implemented\n");
}

/**
 @Status Interoperable
*/
void CGContextClip(CGContextRef ctx) {
    ctx->Backing()->CGContextClip();
}

/**
 @Status Interoperable
*/
CGRect CGContextGetClipBoundingBox(CGContextRef ctx) {
    CGRect ret;
    ctx->Backing()->CGContextGetClipBoundingBox(&ret);

    return ret;
}

/**
 @Status Interoperable
*/
CGRect CGContextGetPathBoundingBox(CGContextRef ctx) {
    CGRect ret;
    ctx->Backing()->CGContextGetPathBoundingBox(&ret);

    return ret;
}

/**
 @Status Interoperable
*/
void CGContextClipToRect(CGContextRef ctx, CGRect rct) {
    CGContextBeginPath(ctx);
    CGContextAddRect(ctx, rct);
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
 @Status Interoperable
*/
void CGContextAddLines(CGContextRef pContext, const CGPoint* pt, unsigned count) {
    CGContextMoveToPoint(pContext, pt[0].x, pt[0].y);
    for (unsigned i = 1; i < count; i++) {
        CGContextAddLineToPoint(pContext, pt[i].x, pt[i].y);
    }
}

/**
 @Status Stub
*/
void CGContextBeginTransparencyLayer(CGContextRef ctx, CFDictionaryRef auxInfo) {
    UNIMPLEMENTED();
    ctx->Backing()->CGContextBeginTransparencyLayer((id)auxInfo);
}

/**
 @Status Stub
*/
void CGContextEndTransparencyLayer(CGContextRef ctx) {
    UNIMPLEMENTED();
    ctx->Backing()->CGContextEndTransparencyLayer();
}

/**
 @Status Stub
 @Notes Always returns RGBA
*/
CGColorSpaceRef CGBitmapContextGetColorSpace(CGContextRef context) {
    UNIMPLEMENTED();
    return (CGColorSpaceRef) new __CGColorSpace(_ColorRGBA);
}

/**
 @Status Caveat
 @Notes Limited bitmap formats available
*/
CGContextRef CGBitmapContextCreate(void* data,
                                   size_t width,
                                   size_t height,
                                   size_t bitsPerComponent,
                                   size_t bytesPerRow,
                                   CGColorSpaceRef colorSpace,
                                   CGBitmapInfo bitmapInfo) {
    CGImageRef newImage = NULL;
    DWORD alphaType = bitmapInfo & 0x1F;
    DWORD byteOrder = bitmapInfo & kCGBitmapByteOrderMask;

    if (byteOrder != 0) {
        EbrDebugLog("CGBitmapContextCreate needs to process byte ordering\n");
    }

    if (colorSpace == NULL) {
        EbrDebugLog("Warning: colorSpace = NULL, assuming grayscale\n");
        newImage = new CGBitmapImage(width, height, _ColorGrayscale, data);

        CGContextRef ret = new __CGContext(newImage);
        CFRelease((id)newImage);

        return ret;
    }

    if (((__CGColorSpace*)colorSpace)->colorSpace == _ColorRGBA || ((__CGColorSpace*)colorSpace)->colorSpace == _ColorRGB32) {
        switch (bitsPerComponent) {
            case 8:
                switch (alphaType) {
                    case kCGImageAlphaNoneSkipFirst:
                        newImage = new CGBitmapImage(width, height, _ColorRGB32, data);
                        break;

                    case kCGImageAlphaNoneSkipLast:
                        newImage = new CGBitmapImage(width, height, _ColorRGB32HE, data);
                        break;

                    case kCGImageAlphaFirst:
                    case kCGImageAlphaPremultipliedLast: //  [TODO: Make this true]
                    case kCGImageAlphaPremultipliedFirst: //  [TODO: Make this true]
                        newImage = new CGBitmapImage(width, height, _ColorRGBA, data);
                        break;

                    case kCGImageAlphaNone:
                        newImage = new CGBitmapImage(width, height, _ColorRGB, data);
                        break;

                    default:
                        assert(0);
                        break;
                }
                break;

            case 5:
                switch (alphaType) {
                    case kCGImageAlphaNone:
                    case kCGImageAlphaNoneSkipFirst:
                        newImage = new CGBitmapImage(width, height, _Color565, data);
                        break;

                    default:
                        assert(0);
                        break;
                }
                break;

            case 0:
                EbrDebugLog(
                    "Warning: Invalid number of bits per component passed to "
                    "CGBitmapContextCreate\n");
                return 0;

            default:
                assert(0);
        }
    } else {
        newImage = new CGBitmapImage(width, height, ((__CGColorSpace*)colorSpace)->colorSpace, data);
    }

    CGContextRef ret = new __CGContext(newImage);
    CFRelease((id)newImage);

    return ret;
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
 @Status Stub
*/
CGInterpolationQuality CGContextGetInterpolationQuality(CGContextRef ctx) {
    UNIMPLEMENTED();
    return (CGInterpolationQuality)0;
}

void EbrCenterTextInRectVertically(CGRect* rect, CGSize* textSize, id font) {
    //  We want to center around the cap height. The character will appear at
    //  origin.y + ascent, so we need to adjust it
    //  so that the capHeight is
    //  centered
    float ascender = [font ascender];
    float capHeight = [font capHeight];
    float diff = ascender - capHeight;

    rect->origin.y += rect->size.height / 2.0f - ((textSize->height + [font descender] + diff) / 2.0f);
    rect->size.height = textSize->height;
}

/**
 @Status Interoperable
*/
void CGContextSetGrayStrokeColor(CGContextRef ctx, float gray, float alpha) {
    ctx->Backing()->CGContextSetGrayStrokeColor(gray, alpha);
}

/**
 @Status Stub
*/
void CGContextSetStrokeColorSpace(CGContextRef pContext, CGColorSpaceRef colorSpace) {
    UNIMPLEMENTED();
    [colorSpace retain];
}

/**
 @Status Interoperable
*/
void CGContextSetAlpha(CGContextRef ctx, float a) {
    ctx->Backing()->CGContextSetAlpha(a);
}

/**
 @Status Stub
*/
CGRect CGContextConvertRectToDeviceSpace(CGContextRef ctx, CGRect rct) {
    UNIMPLEMENTED();
    return rct;
}

/**
 @Status Stub
*/
CGRect CGContextConvertRectToUserSpace(CGContextRef ctx, CGRect rct) {
    UNIMPLEMENTED();
    return rct;
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
CGPoint CGContextConvertPointToDeviceSpace(CGContextRef ctx, CGPoint pt) {
    UNIMPLEMENTED();
    return pt;
}

/**
 @Status Interoperable
*/
void CGContextSetRGBFillColor(CGContextRef ctx, float r, float g, float b, float a) {
    ctx->Backing()->CGContextSetRGBFillColor(r, g, b, a);
}

/**
 @Status Interoperable
*/
void CGContextSetRGBStrokeColor(CGContextRef ctx, float r, float g, float b, float a) {
    if (!ctx) {
        EbrDebugLog("CGContextSetRGBStrokeColor: no context!\n");
        return;
    }

    ctx->Backing()->CGContextSetRGBStrokeColor(r, g, b, a);
}

/**
 @Status Interoperable
*/
void CGContextShowText(CGContextRef ctx, const char* str, unsigned count) {
}

/**
 @Status Interoperable
*/
CGContextRef CGContextRetain(CGContextRef ctx) {
    CFRetain((id)ctx);
    return ctx;
}

/**
 @Status Stub
*/
void CGContextSetShadowWithColor(CGContextRef ctx, CGSize offset, float blur, CGColorRef color) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetWidth(CGContextRef ctx) {
    return ctx->Backing()->DestImage()->Backing()->Width();
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetHeight(CGContextRef ctx) {
    return ctx->Backing()->DestImage()->Backing()->Height();
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetBytesPerRow(CGContextRef ctx) {
    return ctx->Backing()->DestImage()->Backing()->BytesPerRow();
}

/**
 @Status Caveat
 @Notes Only returns kCGImageAlphaFirst or kCGImageAlphaLast
*/
CGImageAlphaInfo CGBitmapContextGetAlphaInfo(CGContextRef ctx) {
    if (!ctx) {
        EbrDebugLog("CGBitmapContextGetAlphaInfo: nil!\n");
        return (CGImageAlphaInfo)0;
    }

    uint32_t ret = 0;

    switch (ctx->Backing()->DestImage()->Backing()->SurfaceFormat()) {
        case _ColorARGB:
            ret |= kCGImageAlphaLast;
            break;

        case _ColorRGBA:
            ret |= kCGImageAlphaFirst;
            break;
    }

    return (CGImageAlphaInfo)ret;
}

/**
 @Status Interoperable
*/
void* CGBitmapContextGetData(CGContextRef ctx) {
    return ctx->Backing()->DestImage()->Backing()->StaticImageData();
}

/**
 @Status Caveat
 @Notes Has no copy-on-write semantics; bitmap returned is the source bitmap representing
        the CGContext
*/
CGImageRef CGBitmapContextCreateImage(CGContextRef ctx) {
    if (!ctx) {
        EbrDebugLog("CGBitmapContextCreateImage: NULL context provided!\n");
        return nil;
    }

#if 0 //  [blamb] Note: To be used when CopyOnWrite() actually copies on write]
CGImageRef ret = ctx->Backing()->DestImage()->Backing()->CopyOnWrite();

return H2E(ret);
#else
    CGImageRef newImage;

    newImage = new CGBitmapImage(ctx->Backing()->DestImage());

    return newImage;
#endif
}

CGImageRef CGBitmapContextGetImage(CGContextRef ctx) {
    return ctx->Backing()->DestImage();
}

CGContextRef CGBitmapContextCreate32(int width, int height, DisplayTexture* texture, DisplayTextureLocking* locking) {
    CGImageRef newImage = nil;
    if (texture) {
        newImage = new CGGraphicBufferImage(width, height, _ColorARGB, texture, locking);
    } else {
        newImage = new CGBitmapImage(width, height, _ColorARGB);
    }

    CGContextRef context = new __CGContext(newImage);
    CGImageRelease(newImage);

    return context;
}

CGContextRef CGBitmapContextCreate24(int width, int height) {
    CGImageRef newImage = new CGBitmapImage(width, height, _ColorRGB);
    CGContextRef context = new __CGContext(newImage);
    CGImageRelease(newImage);

    return context;
}

void CGContextClearToColor(CGContextRef ctx, float r, float g, float b, float a) {
    ctx->Backing()->Clear(r, g, b, a);
}

bool CGContextIsDirty(CGContextRef ctx) {
    return ctx->Backing()->isDirty();
}

void CGContextSetDirty(CGContextRef ctx, bool dirty) {
    return ctx->Backing()->setDirty(dirty);
}

void CGContextReleaseLock(CGContextRef ctx) {
    return ctx->Backing()->ReleaseLock();
}

CGContextImpl* CGContextGetBacking(CGContextRef ctx) {
    return ctx->Backing();
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
