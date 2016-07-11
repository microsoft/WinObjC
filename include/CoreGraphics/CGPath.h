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
#pragma once

#import <CoreGraphics/CGAffineTransform.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CoreGraphicsExport.h>

typedef enum { kCGPathFill, kCGPathEOFill, kCGPathStroke, kCGPathFillStroke, kCGPathEOFillStroke } CGPathDrawingMode;

typedef enum {
    kCGPathElementMoveToPoint,
    kCGPathElementAddLineToPoint,
    kCGPathElementAddQuadCurveToPoint,
    kCGPathElementAddCurveToPoint,
    kCGPathElementCloseSubpath,
} CGPathElementType;

typedef struct {
    CGPathElementType type;
    CGPoint* points;
} CGPathElement;

typedef enum {
    kCGLineCapButt,
    kCGLineCapRound,
    kCGLineCapSquare,
} CGLineCap;

typedef enum {
    kCGLineJoinMiter,
    kCGLineJoinRound,
    kCGLineJoinBevel,
} CGLineJoin;

typedef void (*CGPathApplierFunction)(void* info, const CGPathElement* element);

COREGRAPHICS_EXPORT CGMutablePathRef CGPathCreateMutable();
COREGRAPHICS_EXPORT CGPathRef CGPathCreateWithEllipseInRect(CGRect rect, const CGAffineTransform* transform);
COREGRAPHICS_EXPORT CGPathRef CGPathCreateWithRect(CGRect rect, const CGAffineTransform* transform);

COREGRAPHICS_EXPORT CGPathRef CGPathCreateWithRoundedRect(CGRect rect,
                                                          CGFloat cornerWidth,
                                                          CGFloat cornerHeight,
                                                          const CGAffineTransform* transform) STUB_METHOD;

COREGRAPHICS_EXPORT CGPathRef CGPathCreateCopy(CGPathRef path);

COREGRAPHICS_EXPORT CGPathRef CGPathCreateCopyByTransformingPath(CGPathRef path, const CGAffineTransform* transform) STUB_METHOD;

COREGRAPHICS_EXPORT CGPathRef CGPathCreateCopyByDashingPath(
    CGPathRef path, const CGAffineTransform* transform, CGFloat phase, const CGFloat* lengths, size_t count) STUB_METHOD;
COREGRAPHICS_EXPORT CGPathRef CGPathCreateCopyByStrokingPath(CGPathRef path,
                                                             const CGAffineTransform* transform,
                                                             CGFloat lineWidth,
                                                             CGLineCap lineCap,
                                                             CGLineJoin lineJoin,
                                                             CGFloat miterLimit) STUB_METHOD;

COREGRAPHICS_EXPORT CGMutablePathRef CGPathCreateMutableCopy(CGPathRef path);

COREGRAPHICS_EXPORT CGMutablePathRef CGPathCreateMutableCopyByTransformingPath(CGPathRef path,
                                                                               const CGAffineTransform* transform) STUB_METHOD;

COREGRAPHICS_EXPORT void CGPathRelease(CGPathRef path);
COREGRAPHICS_EXPORT CGPathRef CGPathRetain(CGPathRef path);

COREGRAPHICS_EXPORT void CGPathAddArc(CGMutablePathRef path,
                                      const CGAffineTransform* m,
                                      CGFloat x,
                                      CGFloat y,
                                      CGFloat radius,
                                      CGFloat startAngle,
                                      CGFloat endAngle,
                                      bool clockwise);

COREGRAPHICS_EXPORT void CGPathAddRelativeArc(CGMutablePathRef path,
                                              const CGAffineTransform* matrix,
                                              CGFloat x,
                                              CGFloat y,
                                              CGFloat radius,
                                              CGFloat startAngle,
                                              CGFloat delta) STUB_METHOD;

COREGRAPHICS_EXPORT void CGPathAddArcToPoint(
    CGMutablePathRef path, const CGAffineTransform* m, CGFloat x1, CGFloat y1, CGFloat x2, CGFloat y2, CGFloat radius);
COREGRAPHICS_EXPORT void CGPathAddCurveToPoint(
    CGMutablePathRef path, const CGAffineTransform* m, CGFloat cp1x, CGFloat cp1y, CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y);
COREGRAPHICS_EXPORT void CGPathAddLines(CGMutablePathRef path, const CGAffineTransform* m, const CGPoint* points, size_t count);
COREGRAPHICS_EXPORT void CGPathAddLineToPoint(CGMutablePathRef path, const CGAffineTransform* m, CGFloat x, CGFloat y);
COREGRAPHICS_EXPORT void CGPathAddPath(CGMutablePathRef path1, const CGAffineTransform* m, CGPathRef path2);
COREGRAPHICS_EXPORT void CGPathAddQuadCurveToPoint(
    CGMutablePathRef path, const CGAffineTransform* m, CGFloat cpx, CGFloat cpy, CGFloat x, CGFloat y);
COREGRAPHICS_EXPORT void CGPathAddRect(CGMutablePathRef path, const CGAffineTransform* m, CGRect rect);

COREGRAPHICS_EXPORT void CGPathAddRects(CGMutablePathRef path, const CGAffineTransform* m, const CGRect* rects, size_t count) STUB_METHOD;
COREGRAPHICS_EXPORT void CGPathAddRoundedRect(
    CGMutablePathRef path, const CGAffineTransform* transform, CGRect rect, CGFloat cornerWidth, CGFloat cornerHeight) STUB_METHOD;
COREGRAPHICS_EXPORT void CGPathApply(CGPathRef path, void* info, CGPathApplierFunction function);

COREGRAPHICS_EXPORT void CGPathMoveToPoint(CGMutablePathRef path, const CGAffineTransform* m, CGFloat x, CGFloat y);
COREGRAPHICS_EXPORT void CGPathCloseSubpath(CGMutablePathRef path);
COREGRAPHICS_EXPORT void CGPathAddEllipseInRect(CGMutablePathRef path, const CGAffineTransform* m, CGRect rect);

COREGRAPHICS_EXPORT bool CGPathEqualToPath(CGPathRef path1, CGPathRef path2);

COREGRAPHICS_EXPORT CGRect CGPathGetBoundingBox(CGPathRef path);

COREGRAPHICS_EXPORT CGRect CGPathGetPathBoundingBox(CGPathRef path) STUB_METHOD;
COREGRAPHICS_EXPORT CGPoint CGPathGetCurrentPoint(CGPathRef path);
COREGRAPHICS_EXPORT CFTypeID CGPathGetTypeID() STUB_METHOD;

COREGRAPHICS_EXPORT bool CGPathIsEmpty(CGPathRef path);
COREGRAPHICS_EXPORT bool CGPathIsRect(CGPathRef path, CGRect* rect) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPathContainsPoint(CGPathRef path, const CGAffineTransform* m, CGPoint point, bool eoFill);