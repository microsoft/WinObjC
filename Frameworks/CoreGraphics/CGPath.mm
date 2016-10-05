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

#import "CGContextInternal.h"
#import "CGPathInternal.h"
#import "CGPathInternal.h"
#include "LoggingNative.h"
#import <CoreGraphics/CGBitmapContext.h>
#import <CoreGraphics/CGColorSpace.h>
#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGImage.h>
#import <CoreGraphics/CoreGraphicsExport.h>
#import <Starboard.h>
#import <StubReturn.h>
#import <algorithm>
#import <vector>

#import <CoreFoundation/CoreFoundation.h>
#import <CFRuntime.h>
#import "D2DWrapper.h"

#include <COMIncludes.h>
#import <wrl/client.h>
#import <D2d1.h>
#include <COMIncludes_End.h>

static const wchar_t* TAG = L"CGPath";

using namespace std;
using namespace Microsoft::WRL;

struct __CGPath {
    CFRuntimeBase _base;

    ComPtr<ID2D1PathGeometry> _pathGeometry;
    ComPtr<ID2D1GeometrySink> _geometrySink;

    bool _isPathClosed;
    CGPoint _currentPoint;
    CGPoint _startingPoint;
};

// A private helper function for re-opening a path geometry.
static void __preparePathForEditing(CGPathRef path) {
    if (path->_isPathClosed) {
        // Re-open this geometry.
        ComPtr<ID2D1Factory> factory = _CreateD2DFactoryInstance();
        if (FAILED(factory->CreatePathGeometry(&path->_pathGeometry))) {
            return;
        }
        if (FAILED(path->_pathGeometry->Open(&path->_geometrySink))) {
            return;
        }

        // This path is no longer closed.
        path->_isPathClosed = false;
    }
}

static void __closePath(CGPathRef path) {
    if (!path->_isPathClosed) {
        path->_geometrySink->Close();
        path->_isPathClosed = true;
    }
}

static Boolean __CGPathEqual(CFTypeRef cf1, CFTypeRef cf2) {
    struct __CGPath* path1 = (struct __CGPath*)cf1;
    struct __CGPath* path2 = (struct __CGPath*)cf2;

    return true;
}

static void __CGPathInit(CFTypeRef cf) {
    CGPathRef path = (CGPathRef)cf;
    // ComPtr needs to be manually new'd, to avoid calling Create functions to an incomplete out-pointer
    struct __CGPath* mutablePath = const_cast<struct __CGPath*>(path);
    new (std::addressof(mutablePath->_pathGeometry)) ComPtr<ID2D1PathGeometry>();
    new (std::addressof(mutablePath->_geometrySink)) ComPtr<ID2D1GeometrySink>();
}

static void __CGPathDeallocate(CFTypeRef cf) {
    CGPathRef path = (CGPathRef)cf;
    // ComPtr needs to be manually destructed, since CFTypes do a memset(0) on dealloc
    path->_pathGeometry.~ComPtr();
    path->_geometrySink.~ComPtr();
}

static const CFRuntimeClass __CGPathClass = { 0,
                                              "CGPath",
                                              __CGPathInit, // init
                                              NULL, // copy
                                              __CGPathDeallocate, // deallocate
                                              NULL,
                                              NULL,
                                              NULL, //
                                              NULL };

CFTypeID CGPathGetTypeID() {
    static CFTypeID __kCGPathTypeID = _CFRuntimeRegisterClass(&__CGPathClass);
    return __kCGPathTypeID;
}

class BBox {
public:
    float x, y, x1, y1;
    bool xset, yset, x1set, y1set;

    BBox() {
        x = y = x1 = y1 = 0;
        xset = yset = x1set = y1set = false;
    }

    void addPoint(float ptX, float ptY) {
        if (ptX < x || !xset) {
            x = ptX;
            xset = true;
        }
        if (ptY < y || !yset) {
            y = ptY;
            yset = true;
        }

        if (ptX > x1 || !x1set) {
            x1 = ptX;
            x1set = true;
        }

        if (ptY > y1 || !y1set) {
            y1 = ptY;
            y1set = true;
        }
    }
};

void _CGPathAddElement(
    CGPathRef path, CGPathElementType type, CGPoint p0 = CGPointZero, CGPoint p1 = CGPointZero, CGPoint p2 = CGPointZero) {
}

/**
 @Status Interoperable
*/
CGMutablePathRef CGPathCreateMutable() {
    size_t memSize = sizeof(struct __CGPath) - sizeof(CFRuntimeBase);
    CGPathRef ret = ((CGPathRef)(_CFRuntimeCreateInstance(kCFAllocatorDefault, CGPathGetTypeID(), memSize, NULL)));
    struct __CGPath* mutableRet = const_cast<struct __CGPath*>(ret);

    ComPtr<ID2D1Factory> factory = _CreateD2DFactoryInstance();

    if (FAILED(factory->CreatePathGeometry(&mutableRet->_pathGeometry))) {
        return nullptr;
    }
    if (FAILED(mutableRet->_pathGeometry->Open(&mutableRet->_geometrySink))) {
        return nullptr;
    }

    mutableRet->_currentPoint = { 0, 0 };
    mutableRet->_startingPoint = { 0, 0 };

    return mutableRet;
}

/**
 @Status Caveat
 @Notes Creates a mutable copy
*/
CGPathRef CGPathCreateCopy(CGPathRef path) {
    if (path == NULL) {
        return NULL;
    }

    return CGPathCreateMutableCopy(path);
}

/**
@Status Interoperable
@Notes
*/
CGMutablePathRef CGPathCreateMutableCopy(CGPathRef path) {
    if (path == NULL) {
        return NULL;
    }

    size_t memSize = sizeof(struct __CGPath) - sizeof(CFRuntimeBase);
    CGPathRef ret = ((CGPathRef)(_CFRuntimeCreateInstance(kCFAllocatorDefault, CGPathGetTypeID(), memSize, NULL)));
    struct __CGPath* mutableRet = const_cast<struct __CGPath*>(ret);

    ComPtr<ID2D1Factory> factory = _CreateD2DFactoryInstance();

    if (FAILED(factory->CreatePathGeometry(&mutableRet->_pathGeometry))) {
        CFRelease(mutableRet);
        return nullptr;
    }
    if (FAILED(mutableRet->_pathGeometry->Open(&mutableRet->_geometrySink))) {
        CFRelease(mutableRet);
        return nullptr;
    }

    __closePath(path);
    if (FAILED(path->_pathGeometry->Stream(mutableRet->_geometrySink.Get()))) {
        CFRelease(mutableRet);
        return nullptr;
    }

    mutableRet->_currentPoint = { path->_currentPoint.x, path->_currentPoint.y };
    // Always create an open copy as opening a closed copy would be more expensive.
    mutableRet->_isPathClosed = false;

    return mutableRet;
}

/**
 @Status Interoperable
*/
void CGPathAddLineToPoint(CGMutablePathRef path, const CGAffineTransform* m, float x, float y) {
    if (path == NULL) {
        return;
    }

    __preparePathForEditing(path);

    CGPoint pt;
    pt.x = x;
    pt.y = y;
    if (m) {
        pt = CGPointApplyAffineTransform(pt, *m);
    }

    path->_geometrySink->BeginFigure(D2D1::Point2F(path->_currentPoint.x, path->_currentPoint.y), D2D1_FIGURE_BEGIN_FILLED);
    path->_geometrySink->AddLine(D2D1::Point2F(pt.x, pt.y));
    path->_geometrySink->EndFigure(D2D1_FIGURE_END_CLOSED);

    path->_currentPoint = pt;
}

CGFloat _CGPathControlPointOffsetMultiplier(CGFloat angle) {
    // Constant used to approximate circles with bezier curves.
    // An n-piece cubic Bezier curve can approximate a circle,
    // when each inner control point is the distance 4/3 * tan(t/4)
    // from an outer control point on a unit circle, where t is 360/n degrees, and n > 2
    return (4.0f / 3.0f) * tan(angle / 4.0f);
}

/**
 @Status Caveat
 @Notes transform property not supported
*/
void CGPathAddArcToPoint(CGMutablePathRef path, const CGAffineTransform* m, float x1, float y1, float x2, float y2, float radius) {
    bool isEmpty = CGPathIsEmpty(path);

    if (isEmpty) {
        return;
    }

    CGPoint curPathPosition = CGPathGetCurrentPoint(path);
    // TODO: Deduplicate this code from CGContextImpl::CGContextAddArcToPoint and
    // CGContextCairo::CGContextAddArcToPoint
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
        CGPathAddLineToPoint(path, m, x1, y1);
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
    CGPathAddArc(path,
                 m,
                 (float)(x1 + radius * (t * dx0 + n0x)),
                 (float)(y1 + radius * (t * dy0 + n0y)),
                 radius,
                 (float)atan2(-n0y, -n0x),
                 (float)atan2(-n2y, -n2x),
                 (san < 0));
}

// Internal function to break down Arcs into pieces smaller than pi/2.
void _CGPathAddArc(CGMutablePathRef path,
                   const CGAffineTransform* m,
                   CGFloat x,
                   CGFloat y,
                   CGFloat radius,
                   CGFloat startAngle,
                   CGFloat endAngle,
                   bool clockwise) {
    // Get the difference between the start and end angle for this arc
    CGFloat delta = endAngle - startAngle;

    // If the difference is larger than pi/2 then this arc needs to be
    // broken down into more pieces
    // .00001f is used instead of epsilon here to avoid infinite loops with
    // values close to pi/2
    if ((fabs(delta) > M_PI_2) && (fabs((M_PI_2 - fabs(delta))) > 0.00001f)) {
        // Calculate the angle in the middle of the start & end angle.
        CGFloat midAngle = startAngle + (M_PI_2 * (delta < 0 ? -1.0f : 1.0f));

        // Call this function again now with the smaller arcs
        _CGPathAddArc(path, m, x, y, radius, startAngle, midAngle, clockwise);
        _CGPathAddArc(path, m, x, y, radius, midAngle, endAngle, clockwise);
        return;
    }

    // The start and end points for the arc, not yet adjusted with the center of the arc
    CGPoint arcStartRelative = CGPointMake((cos(startAngle) * radius), (sin(startAngle) * radius));
    CGPoint arcEndRelative = CGPointMake((cos(endAngle) * radius), (sin(endAngle) * radius));

    // The start and end points of the arc, adjuste for the center.
    CGPoint arcStart = CGPointMake(arcStartRelative.x + x, arcStartRelative.y + y);
    CGPoint arcEnd = CGPointMake(arcEndRelative.x + x, arcEndRelative.y + y);

    // Use the angle size to determine the offset for control points
    CGFloat offsetMultiplier = _CGPathControlPointOffsetMultiplier(delta);

    // Create the curve with the control points properly offset
    CGPathAddCurveToPoint(path,
                          m,
                          arcStart.x - (offsetMultiplier * arcStartRelative.y),
                          arcStart.y + (offsetMultiplier * arcStartRelative.x),
                          arcEnd.x + (offsetMultiplier * arcEndRelative.y),
                          arcEnd.y - (offsetMultiplier * arcEndRelative.x),
                          arcEnd.x,
                          arcEnd.y);
}

/**
 @Status Interoperable
*/
void CGPathAddArc(CGMutablePathRef path,
                  const CGAffineTransform* m,
                  CGFloat x,
                  CGFloat y,
                  CGFloat radius,
                  CGFloat startAngle,
                  CGFloat endAngle,
                  bool clockwise) {
    if (path == NULL) {
        return;
    }

    // Normalize the start angle so it's between 0 and 2*pi
    startAngle = fmod(startAngle, 2.0f * M_PI);
    if (startAngle < 0.0f) {
        startAngle += 2.0f * M_PI;
    }

    // Normalize the end angle so it's between 0 and 2*pi
    endAngle = fmod(endAngle, 2.0f * M_PI);
    if (endAngle < 0.0f) {
        endAngle += 2.0f * M_PI;
    }

    // Calculate the starting point of the arc
    CGPoint arcStart = CGPointMake((cos(startAngle) * radius) + x, (sin(startAngle) * radius) + y);

    // Either draw a line to or move to the start of the arc
    if (!CGPathIsEmpty(path)) {
        CGPathAddLineToPoint(path, m, arcStart.x, arcStart.y);
    } else {
        CGPathMoveToPoint(path, m, arcStart.x, arcStart.y);
    }

    // Adjust the start/endangles to force the arc
    // to be pieced together clockwise or counter-clockwise
    if (clockwise && endAngle > startAngle) {
        startAngle += 2.0f * M_PI;
    } else if (!clockwise && startAngle > endAngle) {
        endAngle += 2.0f * M_PI;
    }

    // Call the internal function for breaking the arcs down into smaller segments
    _CGPathAddArc(path, m, x, y, radius, startAngle, endAngle, clockwise);
}

/**
 @Status Interoperable
*/
void CGPathMoveToPoint(CGMutablePathRef path, const CGAffineTransform* m, float x, float y) {
    CGPoint pt;
    pt.x = x;
    pt.y = y;
    if (m) {
        pt = CGPointApplyAffineTransform(pt, *m);
    }
    path->_startingPoint = pt;
    path->_currentPoint = pt;
}

/**
 @Status Interoperable
*/
void CGPathAddLines(CGMutablePathRef path, const CGAffineTransform* m, const CGPoint* points, size_t count) {
    if (count == 0 || points == NULL || path == NULL) {
        return;
    }

    CGPathMoveToPoint(path, m, points[0].x, points[0].y);
    for (int i = 1; i < count; i++) {
        CGPathAddLineToPoint(path, m, points[i].x, points[i].y);
    }
}

/**
 @Status Interoperable
*/
void CGPathAddRect(CGMutablePathRef path, const CGAffineTransform* m, CGRect rect) {
    if (path == NULL) {
        return;
    }

    CGPathMoveToPoint(path, m, CGRectGetMinX(rect), CGRectGetMinY(rect));

    CGPathAddLineToPoint(path, m, CGRectGetMaxX(rect), CGRectGetMinY(rect));
    CGPathAddLineToPoint(path, m, CGRectGetMaxX(rect), CGRectGetMaxY(rect));
    CGPathAddLineToPoint(path, m, CGRectGetMinX(rect), CGRectGetMaxY(rect));
    CGPathCloseSubpath(path);
}

/**
 @Status Stub
 @Notes
*/
void CGPathAddPath(CGMutablePathRef path, const CGAffineTransform* m, CGPathRef toAdd) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
void CGPathAddEllipseInRect(CGMutablePathRef path, const CGAffineTransform* m, CGRect rect) {
    if (path == NULL) {
        return;
    }

    // Determine the control point offset multiplier to create 4 arcs
    CGFloat offsetMultiplier = _CGPathControlPointOffsetMultiplier(M_PI_2);

    CGFloat xControlPointOffset = offsetMultiplier * CGRectGetWidth(rect) / 2.0;
    CGFloat yControlPointOffset = offsetMultiplier * CGRectGetHeight(rect) / 2.0;

    CGFloat minX = CGRectGetMinX(rect);
    CGFloat midX = CGRectGetMidX(rect);
    CGFloat maxX = CGRectGetMaxX(rect);

    CGFloat minY = CGRectGetMinY(rect);
    CGFloat midY = CGRectGetMidY(rect);
    CGFloat maxY = CGRectGetMaxY(rect);

    // Move to the center of the ellipse
    CGPathMoveToPoint(path, m, maxX, midY);

    // Add the 4 curves for the ellipse
    CGPathAddCurveToPoint(path, m, maxX, midY + yControlPointOffset, midX + xControlPointOffset, maxY, midX, maxY);
    CGPathAddCurveToPoint(path, m, midX - xControlPointOffset, maxY, minX, midY + yControlPointOffset, minX, midY);
    CGPathAddCurveToPoint(path, m, minX, midY - yControlPointOffset, midX - xControlPointOffset, minY, midX, minY);
    CGPathAddCurveToPoint(path, m, midX + xControlPointOffset, minY, maxX, midY - yControlPointOffset, maxX, midY);

    CGPathCloseSubpath(path);
}

/**
 @Status Interoperable
*/
void CGPathCloseSubpath(CGMutablePathRef path) {
    // If we need to, close the path.
    if (path->_startingPoint.x != path->_currentPoint.x || path->_startingPoint.y != path->_currentPoint.y) {
        CGPathAddLineToPoint(path, nullptr, path->_startingPoint.x, path->_startingPoint.y);
    }
    __closePath(path);
}

/**
@Status Stub
@Notes
*/
CGRect CGPathGetBoundingBox(CGPathRef path) {
    D2D1_RECT_F bounds;

    __closePath(path);

    if (FAILED(path->_pathGeometry->GetBounds(D2D1::IdentityMatrix(), &bounds))) {
        return CGRectMake(0, 0, 0, 0);
    }

    CGFloat x = bounds.left;
    CGFloat y = bounds.top;
    CGFloat width = bounds.right - x;
    CGFloat height = bounds.bottom - y;

    return CGRectMake(x, y, width, height);
}

/**
@Status Stub
@Notes
*/
bool CGPathIsEmpty(CGPathRef path) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGPathRelease(CGPathRef path) {
    if (path == NULL) {
        return;
    }

    CFRelease(path);
}

/**
 @Status Interoperable
*/
CGPathRef CGPathRetain(CGPathRef path) {
    if (path == NULL) {
        return NULL;
    }

    CFRetain(path);

    return path;
}

/**
@Status Stub
@Notes
*/
void CGPathAddQuadCurveToPoint(CGMutablePathRef path, const CGAffineTransform* m, CGFloat cpx, CGFloat cpy, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
void CGPathAddCurveToPoint(
    CGMutablePathRef path, const CGAffineTransform* m, CGFloat cp1x, CGFloat cp1y, CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
CGPathRef CGPathCreateWithRect(CGRect rect, const CGAffineTransform* trans) {
    CGMutablePathRef ret = CGPathCreateMutable();
    CGPathAddRect(ret, trans, rect);

    return (CGPathRef)ret;
}

/**
 @Status Interoperable
*/
CGPathRef CGPathCreateWithEllipseInRect(CGRect rect, const CGAffineTransform* transform) {
    CGMutablePathRef ret = CGPathCreateMutable();
    CGPathAddEllipseInRect(ret, transform, rect);

    return (CGPathRef)ret;
}

/**
 @Status Stub
*/
CGRect CGPathGetPathBoundingBox(CGPathRef self) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGPathAddRects(CGMutablePathRef path, const CGAffineTransform* m, const CGRect* rects, size_t count) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGPathAddRelativeArc(
    CGMutablePathRef path, const CGAffineTransform* matrix, CGFloat x, CGFloat y, CGFloat radius, CGFloat startAngle, CGFloat delta) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGPathAddRoundedRect(
    CGMutablePathRef path, const CGAffineTransform* transform, CGRect rect, CGFloat cornerWidth, CGFloat cornerHeight) {
    UNIMPLEMENTED();
}

int _CGPathPointCountForElementType(CGPathElementType type) {
    int pointCount = 0;

    switch (type) {
        case kCGPathElementMoveToPoint:
        case kCGPathElementAddLineToPoint:
            pointCount = 1;
            break;
        case kCGPathElementAddQuadCurveToPoint:
            pointCount = 2;
            break;
        case kCGPathElementAddCurveToPoint:
            pointCount = 3;
            break;
        case kCGPathElementCloseSubpath:
            pointCount = 0;
            break;
    }
    return pointCount;
}

/**
 @Status Stub
*/
void CGPathApply(CGPathRef path, void* info, CGPathApplierFunction function) {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
 @Notes
*/
bool CGPathContainsPoint(CGPathRef path, const CGAffineTransform* m, CGPoint point, bool eoFill) {
    if (m) {
        point = CGPointApplyAffineTransform(point, *m);
    }
    // check if the point is outside this box already, if it is, return false
    CGRect boundingBox = CGPathGetBoundingBox(path);
    if (!CGRectContainsPoint(boundingBox, point)) {
        return false;
    }

    CGContextRef context =
        CGBitmapContextCreate(0, boundingBox.origin.x + boundingBox.size.width, boundingBox.origin.y + boundingBox.size.height, 1, 1, 0, 0);

    CGContextAddPath(context, path);

    bool inPath = CGContextIsPointInPath(context, eoFill, point.x, point.y);

    CGContextRelease(context);

    return inPath;
}

/**
 @Status Stub
 @Notes
*/
CGPathRef CGPathCreateCopyByDashingPath(
    CGPathRef path, const CGAffineTransform* transform, CGFloat phase, const CGFloat* lengths, size_t count) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGPathRef CGPathCreateCopyByStrokingPath(
    CGPathRef path, const CGAffineTransform* transform, CGFloat lineWidth, CGLineCap lineCap, CGLineJoin lineJoin, CGFloat miterLimit) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGPathRef CGPathCreateCopyByTransformingPath(CGPathRef path, const CGAffineTransform* transform) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGMutablePathRef CGPathCreateMutableCopyByTransformingPath(CGPathRef path, const CGAffineTransform* transform) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGPathRef CGPathCreateWithRoundedRect(CGRect rect, CGFloat cornerWidth, CGFloat cornerHeight, const CGAffineTransform* transform) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
bool CGPathEqualToPath(CGPathRef path1, CGPathRef path2) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
CGPoint CGPathGetCurrentPoint(CGPathRef path) {
    return path->_currentPoint;
}

/**
 @Status Stub
 @Notes
*/
bool CGPathIsRect(CGPathRef path, CGRect* rect) {
    UNIMPLEMENTED();
    return StubReturn();
}

class ScanlineCalculator {
    typedef std::vector<int> interceptList;
    interceptList _left, _right;

    int _originY, _height, _width, _padding;

public:
    void SetExtents(int y, int width, int height, int padding) {
        _originY = y;
        _width = width;
        _height = height;
        _padding = padding;
        _left.resize(_height);
        std::fill(_left.begin(), _left.end(), _width);
        _right.resize(_height);
        std::fill(_right.begin(), _right.end(), 0);
    }

    void AddLine(CGPoint start, CGPoint end) {
        AddLine(start.x, start.y, end.x, end.y);
    }

    void AddLine(float xstart, float ystart, float xend, float yend) {
        xstart = std::min(xstart, 65536.0f);
        ystart = std::min(ystart, 65536.0f);
        xend = std::min(xend, 65536.0f);
        yend = std::min(yend, 65536.0f);
        xstart = std::max(xstart, -65536.0f);
        ystart = std::max(ystart, -65536.0f);
        xend = std::max(xend, -65536.0f);
        yend = std::max(yend, -65536.0f);

        if (ystart < _originY && yend < _originY)
            return;
        if (ystart > _originY + _height - 1 && yend > _originY + _height - 1)
            return;

        int x = (int)floorf(xstart);
        int y = (int)floorf(ystart);
        int x2 = (int)ceilf(xend);
        int y2 = (int)ceilf(yend);

        int dx = x2 - x;
        int dy = y2 - y;

        if (dy == 0) {
            //  Straight line - simply add start and end points
            AddPoint(x, y);
            AddPoint(x2, y2);
            return;
        }

        int yStart = y;
        int yEnd = y2;
        if (yStart > yEnd) {
            std::swap(yStart, yEnd);
        }
        if (yStart < _originY) {
            yStart = _originY;
        }
        if (yEnd > _originY + _height) {
            yEnd = _originY + _height;
        }

        for (int curY = yStart; curY < yEnd; curY++) {
            int b = curY - y2;
            int xPos = x2 + b * dx / dy;
            AddPoint(xPos, curY);
        }
    }

    void AddPoint(int x, int y) {
        if (y >= _originY && y < _originY + _height) {
            if (_left[y - _originY] > x) {
                _left[y - _originY] = x;
            }
            if (_right[y - _originY] < x) {
                _right[y - _originY] = x;
            }
        }
    }

    bool FindLargestRect(CGPoint point, float rectHeight, CGRect& ret) {
        float xPos = point.x;
        int yPos = floorf(point.y);
        int yHeight = ceilf(rectHeight);

        //  Find the leftmost indexes of the scanlines that can fit the rectangle
        for (int y = yPos; y < yPos + yHeight; y++) {
            int yIdx = y - _originY;
            if (yIdx < 0 || yIdx >= _left.size())
                continue;

            int excludeStart = _left[yIdx] - _padding;
            int excludeEnd = _right[yIdx] + _padding;

            if (xPos >= excludeStart && xPos < excludeEnd) {
                xPos = excludeEnd;
            }
        }

        //  Find the maximum width of the overlap rectangle
        float x2Pos = _width - _padding;

        for (int y = yPos; y < yPos + yHeight; y++) {
            int yIdx = y - _originY;
            if (yIdx < 0 || yIdx >= _left.size())
                continue;

            //  If the end position intersections with an exclusion zone, bump it backward
            int excludeStart = _left[yIdx] - _padding;

            if (excludeStart > xPos && x2Pos >= excludeStart) {
                x2Pos = excludeStart;
            }
        }

        if (x2Pos <= xPos) {
            return false;
        } else {
            ret.origin.x = xPos;
            ret.origin.y = point.y;
            ret.size.width = x2Pos - xPos;
            ret.size.height = rectHeight;
        }

        return true;
    }
};

CGRect _CGPathFitRect(CGPathRef pathref, CGRect rect, CGSize maxSize, float padding) {
// This function is disabled for the time being due to our inability to access individual elements of a path at this time.
#if 0
    CGPathRef path = pathref;
    
    ScanlineCalculator s;
    s.SetExtents(rect.origin.y, maxSize.width, rect.size.height, padding);
    
    CGPoint curPoint = { 0, 0 };
    CGPoint startPoint = { 0, 0 };
    bool startPointSet = false;
    
    for (unsigned i = 0; i < path->_count; i++) {
        switch (path->_elements[i].type) {
            case kCGPathElementMoveToPoint:
                if (!startPointSet) {
                    startPoint = path->_elements[i].points[0];
                    startPointSet = true;
                }
                curPoint = path->_elements[i].points[0];
                break;
    
            case kCGPathElementAddLineToPoint:
                if (!startPointSet) {
                    startPoint = path->_elements[i].points[0];
                    startPointSet = true;
                }
                s.AddLine(curPoint, path->_elements[i].points[0]);
                curPoint = path->_elements[i].points[0];
                break;
    
            case kCGPathElementCloseSubpath:
                if (startPointSet) {
                    s.AddLine(curPoint, startPoint);
                }
                break;
    
            default:
                // The other path types don't effect bounding rects.
                break;
        }
    }
    
    if (s.FindLargestRect(rect.origin, rect.size.height, rect)) {
        return rect;
    } else {
        return CGRectMake(0, 0, 0, 0);
    }
#endif
    return { 0, 0, 0, 0 };
}
