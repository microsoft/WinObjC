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
#include "CGContextInternal.h"

#include "CoreGraphics/CGPath.h"
#include "CoreGraphics/CGLayer.h"
#include "CoreGraphics/CGGradient.h"
#include "CoreGraphics/CGShading.h"
#include "UIKit/UIColor.h"
#include "UIKit/UIFont.h"

typedef struct {
    id curFillColorObject;
    ColorQuad curFillColor, curTextColor, curStrokeColor;
    ColorQuad curPenColor, curForegroundColor;
    CGImageRef _imgClip, _imgMask;
    CGRect _imgMaskRect;
    CGAffineTransform curTransform;
    CGPoint curTextPosition;
    CGTextDrawingMode textDrawingMode;
    uint32_t lineCap;
    float lineWidth;
    float fontSize;
    CGAffineTransform curTextMatrix;
    CGBlendMode curBlendMode;

    id getCurFont();
    void setCurFont(id font);

private:
    id curFont;
} CGContextState;

#define MAX_CG_STATES 16

class CGContextImpl {
protected:
    CGContextRef _rootContext;
    CGImageRef _imgDest;
    bool _isDirty;
    CGContextState* curState;
    DWORD curStateNum;
    CGContextState states[MAX_CG_STATES];
    CGPoint curPathPosition;

    virtual void ObtainLock();

public:
    virtual void ReleaseLock();

    virtual void DrawImage(CGImageRef img, CGRect src, CGRect dest, bool tiled = false);
    virtual void Clear(float r, float g, float b, float a);
    virtual bool isDirty();
    virtual void setDirty(bool dirty);

    CGContextImpl();
    CGContextImpl(CGContextRef base, CGImageRef destinationImage);
    virtual ~CGContextImpl();

    virtual CGImageRef DestImage();

    virtual void CGContextSetBlendMode(CGBlendMode mode);
    virtual CGBlendMode CGContextGetBlendMode();
    virtual void CGContextShowTextAtPoint(float x, float y, const char* str, DWORD length);
    virtual void CGContextShowGlyphsAtPoint(float x, float y, WORD* glyphs, int count);
    virtual void CGContextShowGlyphsWithAdvances(WORD* glyphs, CGSize* advances, int count);
    virtual void CGContextShowGlyphs(WORD* glyphs, int count);
    virtual void CGContextSetFont(id font);
    virtual void CGContextSetFontSize(float ptSize);
    virtual void CGContextSetTextMatrix(CGAffineTransform matrix);
    virtual void CGContextGetTextMatrix(CGAffineTransform* ret);
    virtual void CGContextSetTextPosition(float x, float y);
    virtual void CGContextSetTextDrawingMode(CGTextDrawingMode mode);
    virtual void CGContextTranslateCTM(float x, float y);
    virtual void CGContextScaleCTM(float sx, float sy);
    virtual void CGContextRotateCTM(float angle);
    virtual void CGContextConcatCTM(CGAffineTransform t);
    virtual CGAffineTransform CGContextGetCTM();
    virtual void CGContextSetCTM(CGAffineTransform transform);
    virtual void CGContextDrawImage(CGRect rct, CGImageRef img);
    virtual void CGContextDrawImageRect(CGImageRef img, CGRect src, CGRect dst);
    virtual void CGContextDrawTiledImage(CGRect rct, CGImageRef img);
    virtual void CGContextClipToMask(CGRect dest, CGImageRef img);
    virtual void CGContextSaveGState();
    virtual void CGContextRestoreGState();
    virtual void CGContextSetGrayFillColor(float gray, float alpha);
    virtual void CGContextSetStrokeColor(float* components);
    virtual void CGContextSetStrokeColorWithColor(id color);
    virtual void CGContextSetFillColorWithColor(id color);
    virtual void CGContextSetFillColor(float* components);
    virtual void CGContextSetFillPattern(CGPatternRef pattern, const float* components);
    virtual void CGContextSelectFont(char* name, float size, DWORD encoding);
    virtual void CGContextGetTextPosition(CGPoint* pos);

    virtual void CGContextClearRect(CGRect rct);
    virtual void CGContextFillRect(CGRect rct);
    virtual void CGContextClosePath();
    virtual void CGContextAddRect(CGRect rct);
    virtual void CGContextAddLineToPoint(float x, float y);
    virtual void CGContextAddCurveToPoint(float cp1x, float cp1y, float cp2x, float cp2y, float x, float y);
    virtual void CGContextAddQuadCurveToPoint(float cpx, float cpy, float x, float y);
    virtual void CGContextMoveToPoint(float x, float y);
    virtual void CGContextAddArc(float x, float y, float radius, float startAngle, float endAngle, int clockwise);
    virtual void CGContextAddArcToPoint(float x1, float y1, float x2, float y2, float radius);
    virtual void CGContextAddEllipseInRect(CGRect rct);
    virtual void CGContextStrokeEllipseInRect(CGRect rct);
    virtual void CGContextFillEllipseInRect(CGRect rct);
    virtual void CGContextAddPath(id path);
    virtual void CGContextStrokePath();
    virtual void CGContextStrokeRect(CGRect rct);
    virtual void CGContextStrokeRectWithWidth(CGRect rct, float width);
    virtual void CGContextFillPath();
    virtual void CGContextEOFillPath();
    virtual void CGContextEOClip();
    virtual void CGContextDrawPath(CGPathDrawingMode mode);
    virtual BOOL CGContextIsPathEmpty();
    virtual void CGContextBeginPath();
    virtual void CGContextDrawLinearGradient(CGGradientRef gradient, CGPoint startPoint, CGPoint endPoint, DWORD options);
    virtual void CGContextDrawRadialGradient(
        CGGradientRef gradient, CGPoint startCenter, float startRadius, CGPoint endCenter, float endRadius, DWORD options);
    virtual void CGContextDrawLayerInRect(CGRect destRect, CGLayerRef layer);
    virtual void CGContextDrawLayerAtPoint(CGPoint destPoint, CGLayerRef layer);
    virtual void CGContextSetLineDash(float phase, float* lengths, DWORD count);
    virtual void CGContextSetMiterLimit(float limit);
    virtual void CGContextSetLineJoin(DWORD lineJoin);
    virtual void CGContextSetLineCap(DWORD lineCap);
    virtual void CGContextSetLineWidth(float width);
    virtual void CGContextSetShouldAntialias(DWORD shouldAntialias);
    virtual void CGContextClip();
    virtual void CGContextGetClipBoundingBox(CGRect* ret);
    virtual void CGContextGetPathBoundingBox(CGRect* ret);
    virtual void CGContextClipToRect(CGRect rect);

    virtual void CGContextBeginTransparencyLayer(id auxInfo);
    virtual void CGContextEndTransparencyLayer();

    virtual void CGContextSetGrayStrokeColor(float gray, float alpha);
    virtual void CGContextSetAlpha(float a);
    virtual void CGContextSetRGBFillColor(float r, float g, float b, float a);
    virtual void CGContextSetRGBStrokeColor(float r, float g, float b, float a);

    virtual CGSize CGFontDrawGlyphsToContext(WORD* glyphs, DWORD length, float x, float y);
};

#define LOCK_CAIRO() EbrLockEnter(_cairoLock);
#define UNLOCK_CAIRO() EbrLockLeave(_cairoLock);
extern EbrLock _cairoLock;
