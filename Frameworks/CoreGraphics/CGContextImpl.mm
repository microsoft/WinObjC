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

#import <CoreGraphics/CGContext.h>
#import <Starboard.h>

#import "CGContextInternal.h"
#import "CGFontInternal.h"
#import "CGPathInternal.h"
#import "CGPatternInternal.h"
#import "CoreGraphics/CGGeometry.h"
#import "UIColorInternal.h"
#import "UIFontInternal.h"
#import "cairo-ft.h"

extern "C" {
#import <ft2build.h>
#import FT_FREETYPE_H
#import <ftadvanc.h>
#import <ftglyph.h>
#import <ftsizes.h>
#import <tttables.h>
}

#include "LoggingNative.h"

static const wchar_t* TAG = L"CGContextImpl";

static IWLazyClassLookup _LazyUIFont("UIFont");

id CGContextState::getCurFont() {
    if (curFont == nil) {
        curFont = [_LazyUIFont defaultFont];
    }

    return curFont;
}

void CGContextState::setCurFont(id font) {
    curFont = font;
}

CGContextImpl::CGContextImpl(CGContextRef base, CGImageRef destinationImage) {
    _rootContext = base;
    _isDirty = false;

    curStateNum = 0;
    curState = &states[curStateNum];
    // curState->curTransform.Rotate(5.0f);

    curState->_imgClip = NULL;
    curState->_imgMask = NULL;
    curState->curTextPosition.x = 0.0f;
    curState->curTextPosition.y = 0.0f;
    curState->fontSize = 10.0f;
    curState->lineCap = 0;
    curState->lineWidth = 1.0f;
    curState->setCurFont(nil);
    curState->curFillColor.r = 0.0f;
    curState->curFillColor.g = 0.0f;
    curState->curFillColor.b = 0.0f;
    curState->curFillColor.a = 1.0f;
    curState->curFillColorObject = nil;
    curState->curStrokeColor.r = 1.0f;
    curState->curStrokeColor.g = 1.0f;
    curState->curStrokeColor.b = 1.0f;
    curState->curStrokeColor.a = 1.0f;
    curState->textDrawingMode = kCGTextFill;
    curState->curBlendMode = kCGBlendModeNormal;

    curPathPosition.x = 0;
    curPathPosition.y = 0;

    curState->curTextMatrix = CGAffineTransformMakeTranslation(0.0f, 0.0f);
    curState->curTransform = CGAffineTransformMakeTranslation(0.0f, 0.0f);

    _imgDest = destinationImage;

    curState->shadowOffset = CGSizeMake(0, 0);
    curState->shadowBlur = 0.0f;
    curState->shadowColor = NULL;

    CGImageRetain(_imgDest);
}

CGContextImpl::~CGContextImpl() {
    for (DWORD i = 0; i <= curStateNum; i++) {
        if (states[i]._imgClip != NULL) {
            delete states[i]._imgClip;
        }
        if (states[i]._imgMask != NULL) {
            delete states[i]._imgMask;
        }
        if (states[i].shadowColor != NULL) {
            CGColorRelease(states[i].shadowColor);
        }
    }
    ReleaseLock();
    CGImageRelease(_imgDest);
}

CGImageRef CGContextImpl::DestImage() {
    return _imgDest;
}

void CGContextImpl::ObtainLock() {
}

void CGContextImpl::ReleaseLock() {
}

bool CGContextImpl::isDirty() {
    return _isDirty;
}

void CGContextImpl::setDirty(bool dirty) {
    _isDirty = dirty;
}

void CGContextImpl::Clear(float r, float g, float b, float a) {
}

void CGContextImpl::DrawImage(CGImageRef img, CGRect src, CGRect dest, bool tiled) {
}

void CGContextImpl::CGContextSetBlendMode(CGBlendMode mode) {
    curState->curBlendMode = mode;
}

CGBlendMode CGContextImpl::CGContextGetBlendMode() {
    return curState->curBlendMode;
}

void CGContextImpl::CGContextShowTextAtPoint(float x, float y, const char* str, DWORD length) {
    WORD* glyphs = (WORD*)IwMalloc(length * sizeof(WORD));
    DWORD i;

    for (i = 0; i < length; i++) {
        glyphs[i] = str[i];
    }

    CGFontGetGlyphs(curState->getCurFont(), glyphs, length, glyphs);
    CGContextShowGlyphsAtPoint(x, y, glyphs, length);

    IwFree(glyphs);
}

void CGContextImpl::CGContextShowGlyphsAtPoint(float x, float y, WORD* glyphs, int count) {
    CGSize size;

    _isDirty = true;

    switch (curState->textDrawingMode) {
        case kCGTextFill:
        case kCGTextStroke:
        case kCGTextFillStroke:
        case kCGTextFillClip:
        case kCGTextStrokeClip:
        case kCGTextFillStrokeClip:
            size = CGFontDrawGlyphsToContext(glyphs, count, x, y);
            break;

        case kCGTextClip:
        case kCGTextInvisible:
            CGFontMeasureGlyphs(curState->getCurFont(), curState->fontSize, glyphs, count, &size);
            break;
    }

    curState->curTextPosition.x = x + size.width;
    curState->curTextPosition.y = y;
}

void CGContextImpl::CGContextShowGlyphsWithAdvances(WORD* glyphs, CGSize* advances, int count) {
    CGPoint curPos = { curState->curTextPosition.x, curState->curTextPosition.y };
    _isDirty = true;

    for (int i = 0; i < count; i++) {
        CGFontDrawGlyphsToContext(&glyphs[i], 1, curPos.x, curPos.y);
        curPos.x += advances[i].width;
        curPos.y += advances[i].height;
    }
    curState->curTextPosition = curPos;
}

void CGContextImpl::CGContextShowGlyphs(WORD* glyphs, int count) {
    CGContextShowGlyphsAtPoint(curState->curTextPosition.x, curState->curTextPosition.y, glyphs, count);
}

void CGContextImpl::CGContextSetFont(id font) {
    curState->setCurFont(font);
}

void CGContextImpl::CGContextSetFontSize(float ptSize) {
    curState->fontSize = ptSize;
}

void CGContextImpl::CGContextSetTextMatrix(CGAffineTransform matrix) {
    curState->curTextMatrix = matrix;
}

void CGContextImpl::CGContextGetTextMatrix(CGAffineTransform* ret) {
    *ret = curState->curTextMatrix;
}

void CGContextImpl::CGContextSetTextPosition(float x, float y) {
    curState->curTextPosition.x = x;
    curState->curTextPosition.y = y;
}

void CGContextImpl::CGContextSetTextDrawingMode(CGTextDrawingMode mode) {
    curState->textDrawingMode = mode;
}

void CGContextImpl::CGContextTranslateCTM(float x, float y) {
    curState->curTransform = CGAffineTransformTranslate(curState->curTransform, x, y);
}

void CGContextImpl::CGContextScaleCTM(float sx, float sy) {
    curState->curTransform = CGAffineTransformScale(curState->curTransform, sx, sy);
}

void CGContextImpl::CGContextRotateCTM(float angle) {
    curState->curTransform = CGAffineTransformRotate(curState->curTransform, angle);
}

void CGContextImpl::CGContextConcatCTM(CGAffineTransform t) {
    curState->curTransform = CGAffineTransformConcat(t, curState->curTransform);
}

CGAffineTransform CGContextImpl::CGContextGetCTM() {
    return curState->curTransform;
}

void CGContextImpl::CGContextSetCTM(CGAffineTransform transform) {
    curState->curTransform = transform;
}

void CGContextImpl::CGContextDrawImage(CGRect rct, CGImageRef img) {
    if (img == NULL) {
        TraceWarning(TAG, L"Img == NULL!");
        return;
    }

    ObtainLock();
    _isDirty = true;

    CGRect src;

    src = rct;
    src.origin.x = 0;
    src.origin.y = 0;
    src.size.width = (float)img->Backing()->Width();
    src.size.height = (float)img->Backing()->Height();

    // rct.origin.y = (_imgDest->_height - rct.origin.y) - img->_height;

    DrawImage(img, src, rct);
}

void CGContextImpl::CGContextDrawImageRect(CGImageRef img, CGRect src, CGRect rct) {
    if (img == NULL) {
        TraceWarning(TAG, L"Img == NULL!");
        return;
    }

    ObtainLock();
    _isDirty = true;

    DrawImage(img, src, rct);
}

void CGContextImpl::CGContextDrawTiledImage(CGRect rct, CGImageRef img) {
    if (img == NULL) {
        TraceWarning(TAG, L"Img == NULL!");
        return;
    }

    ObtainLock();
    _isDirty = true;

    CGRect src;

    src = rct;
    src.origin.x = 0;
    src.origin.y = 0;
    src.size.width = (float)img->Backing()->Width();
    src.size.height = (float)img->Backing()->Height();

    // rct.origin.y = (_imgDest->_height - rct.origin.y) - img->_height;

    DrawImage(img, src, rct, true);
}

void CGContextImpl::CGContextClipToMask(CGRect dest, CGImageRef img) {
    ObtainLock();

    if (curState->_imgMask != NULL) {
        delete curState->_imgMask;
        curState->_imgMask = NULL;
    }

    if (img->Backing()->SurfaceFormat() != _ColorGrayscale) {
        curState->_imgMask = img->Backing()->Copy();
    } else {
        CGBitmapImage* pNewImage = new CGBitmapImage(img->Backing()->Width(), img->Backing()->Height(), _ColorRGBA);

        BYTE* imgData = (BYTE*)img->Backing()->LockImageData();
        BYTE* newImgData = (BYTE*)pNewImage->Backing()->LockImageData();

        for (int y = 0; y < img->Backing()->Height(); y++) {
            BYTE* imageIn = ((BYTE*)imgData) + y * img->Backing()->BytesPerRow();
            BYTE* curScanline = ((BYTE*)newImgData) + y * pNewImage->Backing()->BytesPerRow();
            for (int x = 0; x < img->Backing()->Width(); x++) {
                *curScanline++ = 0;
                *curScanline++ = 0;
                *curScanline++ = 0;
                *curScanline++ = *imageIn++;
            }
        }

        img->Backing()->ReleaseImageData();
        pNewImage->Backing()->ReleaseImageData();

        curState->_imgMask = pNewImage;
    }
}

void CGContextImpl::CGContextSetGrayFillColor(float gray, float alpha) {
    curState->curFillColor.r = gray;
    curState->curFillColor.g = gray;
    curState->curFillColor.b = gray;
    curState->curFillColor.a = alpha;
}

void CGContextImpl::CGContextSetStrokeColor(float* components) {
    curState->curStrokeColor.r = components[0];
    curState->curStrokeColor.g = components[1];
    curState->curStrokeColor.b = components[2];
    curState->curStrokeColor.a = components[3];
}

void CGContextImpl::CGContextSetStrokeColorWithColor(id color) {
    if (color) {
        curState->curStrokeColor = *[(UIColor*)color _getColors];
    } else {
        _ClearColorQuad(curState->curStrokeColor);
    }
}

void CGContextImpl::CGContextSetFillColorWithColor(id color) {
    if ((int)[(UIColor*)color _type] == solidBrush) {
        if (color) {
            curState->curFillColor = *[(UIColor*)color _getColors];
        } else {
            _ClearColorQuad(curState->curFillColor);
        }
        curState->curFillColorObject = nil;
    } else {
        curState->curFillColorObject = [color retain];
    }
}

void CGContextImpl::CGContextSetFillColor(float* components) {
    // TODO: Components based on colorspace.
    curState->curFillColor.r = components[0];
    curState->curFillColor.g = components[1];
    curState->curFillColor.b = components[2];
    curState->curFillColor.a = components[3];
}

void CGContextImpl::CGContextSetFillPattern(CGPatternRef pattern, const float* components) {
    CGPattern* intPattern = (CGPattern*)pattern;
    curState->curFillColorObject = [pattern retain];
    switch (intPattern->surfaceFmt) {
        case _ColorRGB:
        case _Color565:
            curState->curFillColor.r = 1.0f;
            curState->curFillColor.g = 1.0f;
            curState->curFillColor.b = 1.0f;
            curState->curFillColor.a = *components;
            break;
        case _ColorGrayscale:
        case _ColorA8:
            curState->curFillColor.r = components[0];
            curState->curFillColor.g = components[1];
            curState->curFillColor.b = components[2];
            curState->curFillColor.a = components[3];
            break;
        default:
            curState->curFillColor.r = 1.0f;
            curState->curFillColor.g = 1.0f;
            curState->curFillColor.b = 1.0f;
            curState->curFillColor.a = 1.0f;
            break;
    }
}

void CGContextImpl::CGContextSetPatternPhase(CGSize phase) {
    if ([curState->curFillColorObject isKindOfClass:[CGPattern class]]) {
        CGPattern* pattern = curState->curFillColorObject;
        CGAffineTransform matrix = pattern->matrix;
        matrix.tx += phase.width;
        matrix.ty += phase.height;
        pattern->matrix = matrix;
    }
}

void CGContextImpl::CGContextSelectFont(char* name, float size, DWORD encoding) {
    // curState->curFont = [UIFont class]("fontWithName:size:", @name, size);
    curState->fontSize = size;
}

void CGContextImpl::CGContextGetTextPosition(CGPoint* pos) {
    pos->x = curState->curTextPosition.x;
    pos->y = curState->curTextPosition.y;
}

void CGContextImpl::CGContextSaveGState() {
    curStateNum++;
    assert(curStateNum < MAX_CG_STATES);

    states[curStateNum].curFillColorObject = curState->curFillColorObject;
    states[curStateNum].curFillColor = curState->curFillColor;
    states[curStateNum].curStrokeColor = curState->curStrokeColor;
    states[curStateNum].curTextColor = curState->curTextColor;
    states[curStateNum].curPenColor = curState->curPenColor;
    states[curStateNum].curForegroundColor = curState->curForegroundColor;
    states[curStateNum].setCurFont(curState->getCurFont());
    states[curStateNum].fontSize = curState->fontSize;
    states[curStateNum].textDrawingMode = curState->textDrawingMode;
    states[curStateNum].curTextMatrix = curState->curTextMatrix;
    states[curStateNum].curTextPosition = curState->curTextPosition;
    states[curStateNum].curBlendMode = curState->curBlendMode;
    states[curStateNum]._imgClip = NULL;
    states[curStateNum]._imgMask = NULL;
    states[curStateNum].shadowOffset = curState->shadowOffset;
    states[curStateNum].shadowBlur = curState->shadowBlur;
    states[curStateNum].shadowColor = NULL;

    if (curState->_imgClip) {
        states[curStateNum]._imgClip = curState->_imgClip->Backing()->Copy();
    }
    if (curState->_imgMask) {
        states[curStateNum]._imgMask = curState->_imgMask->Backing()->Copy();
    }
    if (curState->shadowColor) {
        states[curStateNum].shadowColor = CGColorCreateCopy(curState->shadowColor);
    }

    memcpy(&states[curStateNum].curTransform, &curState->curTransform, sizeof(curState->curTransform));

    curState = &states[curStateNum];
}

void CGContextImpl::CGContextRestoreGState() {
    if (curStateNum == 0) {
        TraceWarning(TAG, L"CGContextRestoreGState: no state to restore!");
        return;
    }

    if (curState->_imgClip) {
        delete curState->_imgClip;
    }
    if (curState->_imgMask) {
        delete curState->_imgMask;
    }
    if (curState->shadowColor) {
        CGColorRelease(curState->shadowColor);
    }
    curStateNum--;
    curState = &states[curStateNum];
}

void CGContextImpl::CGContextClearRect(CGRect rct) {
}

void CGContextImpl::CGContextFillRect(CGRect rct) {
}

void CGContextImpl::CGContextClosePath() {
}

void CGContextImpl::CGContextAddRect(CGRect rct) {
}

void CGContextImpl::CGContextAddLineToPoint(float x, float y) {
    curPathPosition.x = x;
    curPathPosition.y = y;
}

void CGContextImpl::CGContextAddCurveToPoint(float cp1x, float cp1y, float cp2x, float cp2y, float x, float y) {
    curPathPosition.x = x;
    curPathPosition.y = y;
}

void CGContextImpl::CGContextAddQuadCurveToPoint(float cpx, float cpy, float x, float y) {
    CGPoint curr = curPathPosition;

    CGContextAddCurveToPoint((curr.x / 3.0f) + (2.0f * cpx / 3.0f),
                             (curr.y / 3.0f) + (2.0f * cpy / 3.0f),
                             (2.0f * cpx / 3.0f) + (x / 3.0f),
                             (2.0f * cpy / 3.0f) + (y / 3.0f),
                             x,
                             y);

    curPathPosition.x = x;
    curPathPosition.y = y;
}

void CGContextImpl::CGContextMoveToPoint(float x, float y) {
    curPathPosition.x = x;
    curPathPosition.y = y;
}

void CGContextImpl::CGContextAddArc(float x, float y, float radius, float startAngle, float endAngle, int clockwise) {
}

void CGContextImpl::CGContextAddArcToPoint(float x1, float y1, float x2, float y2, float radius) {
    double x0, y0;
    double dx0, dy0, dx2, dy2, xl0, xl2;
    double san, n0x, n0y, n2x, n2y, t;

    x0 = curPathPosition.x;
    y0 = curPathPosition.y;

    dx0 = x0 - x1;
    dy0 = y0 - y1;
    xl0 = sqrt(dx0 * dx0 + dy0 * dy0);
    if (xl0 == 0)
        return;

    dx2 = x2 - x1;
    dy2 = y2 - y1;
    xl2 = sqrt(dx2 * dx2 + dy2 * dy2);

    san = dx2 * dy0 - dx0 * dy2;
    if (san == 0) {
        CGContextAddLineToPoint(x1, y1);
        return;
    }

    if (san < 0) {
        n0x = -dy0 / xl0;
        n0y = dx0 / xl0;
        n2x = dy2 / xl2;
        n2y = -dx2 / xl2;
    } else {
        n0x = dy0 / xl0;
        n0y = -dx0 / xl0;
        n2x = -dy2 / xl2;
        n2y = dx2 / xl2;
    }
    t = (dx2 * n2y - dx2 * n0y - dy2 * n2x + dy2 * n0x) / san;
    CGContextAddArc((float)(x1 + radius * (t * dx0 + n0x)),
                    (float)(y1 + radius * (t * dy0 + n0y)),
                    radius,
                    (float)atan2(-n0y, -n0x),
                    (float)atan2(-n2y, -n2x),
                    (san < 0));
}

void CGContextImpl::CGContextAddEllipseInRect(CGRect rct) {
}

void CGContextImpl::CGContextStrokeEllipseInRect(CGRect rct) {
}

void CGContextImpl::CGContextFillEllipseInRect(CGRect rct) {
}

void CGContextImpl::CGContextAddPath(CGPathRef path) {
    _CGPathApplyPath(path, _rootContext);
}

void CGContextImpl::CGContextStrokePath() {
}

void CGContextImpl::CGContextStrokeRect(CGRect rct) {
}

void CGContextImpl::CGContextStrokeRectWithWidth(CGRect rct, float width) {
}

void CGContextImpl::CGContextFillPath() {
}

void CGContextImpl::CGContextEOFillPath() {
}

void CGContextImpl::CGContextEOClip() {
}

void CGContextImpl::CGContextDrawPath(CGPathDrawingMode mode) {
}

BOOL CGContextImpl::CGContextIsPathEmpty() {
    return TRUE;
}

void CGContextImpl::CGContextBeginPath() {
}

void CGContextImpl::CGContextDrawLinearGradient(CGGradientRef gradient, CGPoint startPoint, CGPoint endPoint, DWORD options) {
}

void CGContextImpl::CGContextDrawRadialGradient(
    CGGradientRef gradient, CGPoint startCenter, float startRadius, CGPoint endCenter, float endRadius, DWORD options) {
}

void CGContextImpl::CGContextDrawLayerInRect(CGRect destRect, CGLayerRef layer) {
#if 0
ObtainLock();

_isDirty = true;

CGRect src;

src.origin.x = 0;
src.origin.y = 0;
src.size.width = (float) layer->_layerBacking->Backing()->Width();
src.size.height = (float) layer->_layerBacking->Backing()->Height();

DrawImage(layer->_layerBacking, src, destRect);
#endif
}

void CGContextImpl::CGContextDrawLayerAtPoint(CGPoint destPoint, CGLayerRef layer) {
#if 0
ObtainLock();

_isDirty = true;

CGRect src, destRect;

src.origin.x = 0;
src.origin.y = 0;
src.size.width = (float) layer->_layerBacking->Backing()->Width();
src.size.height = (float) layer->_layerBacking->Backing()->Height();

destRect.origin = destPoint;
destRect.size.width = (float) layer->_layerBacking->Backing()->Width();
destRect.size.height = (float) layer->_layerBacking->Backing()->Height();

DrawImage(layer->_layerBacking, src, destRect);
#endif
}

CGInterpolationQuality CGContextImpl::CGContextGetInterpolationQuality() {
    // CGContext could be backed by CGContextImpl or CGContextCairo.
    // CGContextImpl is not being currently used but, by convention we add the method here.
    return kCGInterpolationDefault;
}

void CGContextImpl::CGContextSetInterpolationQuality(CGInterpolationQuality) {
    // CGContext could be backed by CGContextImpl or CGContextCairo.
    // CGContextImpl is not being currently used but, by convention we add the method here
}

void CGContextImpl::CGContextSetLineDash(float phase, float* lengths, DWORD count) {
}

void CGContextImpl::CGContextSetMiterLimit(float limit) {
}

void CGContextImpl::CGContextSetLineJoin(DWORD lineJoin) {
}

void CGContextImpl::CGContextSetLineCap(DWORD lineCap) {
}

void CGContextImpl::CGContextSetLineWidth(float width) {
    curState->lineWidth = width;
}

void CGContextImpl::CGContextSetShouldAntialias(DWORD shouldAntialias) {
}

void CGContextImpl::CGContextClip() {
}

void CGContextImpl::CGContextGetClipBoundingBox(CGRect* ret) {
    CGRect pixSize = { 0, 0, (float)DestImage()->Backing()->Width(), (float)DestImage()->Backing()->Height() };

    CGAffineTransform inv;

    inv = CGAffineTransformInvert(curState->curTransform);
    pixSize = CGRectApplyAffineTransform(pixSize, inv);

    *ret = pixSize;
}

void CGContextImpl::CGContextGetPathBoundingBox(CGRect* ret) {
    memset(ret, 0, sizeof(CGRect));
}

void CGContextImpl::CGContextClipToRect(CGRect rect) {
}

void CGContextImpl::CGContextBeginTransparencyLayer(id auxInfo) {
}

void CGContextImpl::CGContextBeginTransparencyLayerWithRect(CGRect rect, id auxInfo) {
}

void CGContextImpl::CGContextEndTransparencyLayer() {
}

void CGContextImpl::CGContextSetGrayStrokeColor(float gray, float alpha) {
    curState->curStrokeColor.r = gray;
    curState->curStrokeColor.g = gray;
    curState->curStrokeColor.b = gray;
    curState->curStrokeColor.a = alpha;
}

void CGContextImpl::CGContextSetAlpha(float a) {
    curState->curFillColor.a = a;
}

void CGContextImpl::CGContextSetRGBFillColor(float r, float g, float b, float a) {
    curState->curFillColor.r = r;
    curState->curFillColor.g = g;
    curState->curFillColor.b = b;
    curState->curFillColor.a = a;
}

void CGContextImpl::CGContextSetRGBStrokeColor(float r, float g, float b, float a) {
    curState->curStrokeColor.r = r;
    curState->curStrokeColor.g = g;
    curState->curStrokeColor.b = b;
    curState->curStrokeColor.a = a;
}

CGSize CGContextImpl::CGFontDrawGlyphsToContext(WORD* glyphs, DWORD length, float x, float y) {
    CGSize ret = { 0, 0 };

    return ret;
}

void CGContextImpl::CGContextSetShadowWithColor(CGSize offset, float blur, CGColorRef color) {
    if (blur < 0) {
        blur = 0;
    }
    curState->shadowOffset = offset;
    curState->shadowBlur = blur;

    CGColorRef old = curState->shadowColor;
    if (color != NULL) {
        curState->shadowColor = CGColorRetain(color);
    } else {
        curState->shadowColor = NULL;
    }

    if (old != NULL) {
        CGColorRelease(old);
    }
}

void CGContextImpl::CGContextSetShadow(CGSize offset, float blur) {
    CGFloat components[4] = { 0, 0, 0, 1.0 / 3.0 };

    CGColorSpaceRef clrRgb = CGColorSpaceCreateDeviceRGB();
    CGColorRef shadowColor = (CGColorRef)CGColorCreate(clrRgb, components);
    CGColorSpaceRelease(clrRgb);

    CGContextSetShadowWithColor(offset, blur, shadowColor);

    CGColorRelease(shadowColor);
}

bool CGContextImpl::CGContextIsPointInPath(bool eoFill, float x, float y) {
    // CGContext could be backed by CGContextImpl or CGContextCairo.
    // CGContextImpl is not being currently used but, by convention we add the method here.
    return false;
}
CGPathRef CGContextImpl::CGContextCopyPath(void) {
    return NULL;
}
