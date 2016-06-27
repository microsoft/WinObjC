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

#import "CGPathInternal.h"
#include "LoggingNative.h"
#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGGeometry.h>
#import <Starboard.h>
#import <StubReturn.h>
#import <algorithm>
#import <vector>

static const wchar_t* TAG = L"CGPath";

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

__CGPath::~__CGPath() {
    if (_components) {
        for (unsigned i = 0; i < _count; i++) {
            CGPoint* points = _components[i].points;
            if (points) {
                IwFree(points);
            }
        }
        IwFree(_components);
    }
}

void __CGPath::_applyPath(CGContextRef context) {
    for (unsigned i = 0; i < _count; i++) {
        switch (_components[i].type) {
            case kCGPathElementMoveToPoint:
                TraceVerbose(TAG, L"Move to %d, %d", (int)_components[i].points[0].x, (int)_components[i].points[0].y);
                CGContextMoveToPoint(context, _components[i].points[0].x, _components[i].points[0].y);
                break;

            case kCGPathElementAddLineToPoint:
                TraceVerbose(TAG, L"Line to %d, %d", (int)_components[i].points[0].x, (int)_components[i].points[0].y);
                CGContextAddLineToPoint(context, _components[i].points[0].x, _components[i].points[0].y);
                break;

            case kCGPathElementAddCurveToPoint:
                CGContextAddCurveToPoint(context,
                                         _components[i].points[0].x,
                                         _components[i].points[0].y,
                                         _components[i].points[1].x,
                                         _components[i].points[1].y,
                                         _components[i].points[2].x,
                                         _components[i].points[2].y);
                break;

            case kCGPathElementAddQuadCurveToPoint:
                CGContextAddQuadCurveToPoint(context,
                                             _components[i].points[0].x,
                                             _components[i].points[0].y,
                                             _components[i].points[1].x,
                                             _components[i].points[1].y);
                break;

            case kCGPathElementCloseSubpath:
                CGContextClosePath(context);
                break;

            default:
                assert(0);
                break;
        }
    }
}

void __CGPath::_getBoundingBox(CGRect* rectOut) {
    BBox bbox;

    for (unsigned i = 0; i < _count; i++) {
        switch (_components[i].type) {
            case kCGPathElementMoveToPoint:
            case kCGPathElementAddLineToPoint:
                bbox.addPoint(_components[i].points[0].x, _components[i].points[0].y);
                break;

            case kCGPathElementAddCurveToPoint:
                bbox.addPoint(_components[i].points[0].x, _components[i].points[0].y);
                bbox.addPoint(_components[i].points[1].x, _components[i].points[1].y);
                bbox.addPoint(_components[i].points[2].x, _components[i].points[2].y);
                break;

            case kCGPathElementAddQuadCurveToPoint:
                bbox.addPoint(_components[i].points[0].x, _components[i].points[0].y);
                bbox.addPoint(_components[i].points[1].x, _components[i].points[1].y);
                break;

            case kCGPathElementCloseSubpath:
                break;

            default:
                assert(false);
        }
    }

    rectOut->origin.x = bbox.x;
    rectOut->origin.y = bbox.y;
    rectOut->size.width = bbox.x1 - bbox.x;
    rectOut->size.height = bbox.y1 - bbox.y;
}

void _CGPathApplyPath(CGPathRef pathref, CGContextRef context) {
    pathref->_applyPath(context);
}

// Not sure why this is necessary in addition to the public version, need to dig further
void _CGPathGetBoundingBoxInternal(CGPathRef pathref, CGRect* rectOut) {
    pathref->_getBoundingBox(rectOut);
}

/**
 @Status Interoperable
*/
CGMutablePathRef CGPathCreateMutable() {
    return __CGPath::alloc(nil);
}

/**
 @Status Caveat
 @Notes Creates a mutable copy
*/
CGPathRef CGPathCreateCopy(CGPathRef path) {
    return CGPathCreateMutableCopy(path);
}

/**
 @Status Interoperable
*/
CGMutablePathRef CGPathCreateMutableCopy(CGPathRef path) {
    auto ret = __CGPath::alloc(nil);
    ret->_max = path->_max;
    ret->_count = path->_count;
    ret->_components = (CGPathElement*)IwRealloc(ret->_components, ret->_max * sizeof(CGPathElement));
    memcpy(ret->_components, path->_components, path->_count * sizeof(CGPathElement));
    return ret;
}

/**
 @Status Interoperable
*/
void CGPathAddLineToPoint(CGMutablePathRef path, const CGAffineTransform* m, float x, float y) {
    if (m) {
        CGPoint pt;

        pt.x = x;
        pt.y = y;

        pt = CGPointApplyAffineTransform(pt, *m);

        x = pt.x;
        y = pt.y;
    }

    CGPathRef pathObj = path;

    if (pathObj->_count + 1 >= pathObj->_max) {
        pathObj->_max += 32;
        pathObj->_components = (CGPathElement*)IwRealloc(pathObj->_components, pathObj->_max * sizeof(CGPathElement));
    }

    pathObj->_components[pathObj->_count].type = kCGPathElementAddLineToPoint;

    pathObj->_components[pathObj->_count].points = (CGPoint*)IwCalloc(1, sizeof(CGPoint));
    pathObj->_components[pathObj->_count].points[0] = { x, y };

    pathObj->_count++;
}

CGFloat _CGPathControlPointOffsetMultiplier(CGFloat angle) {
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

void _CGPathAddArc(CGMutablePathRef path,
                   const CGAffineTransform* m,
                   CGFloat x,
                   CGFloat y,
                   CGFloat radius,
                   CGFloat startAngle,
                   CGFloat endAngle,
                   bool clockwise) {
    CGFloat delta = endAngle - startAngle;

    if ((fabs(delta) > M_PI_2) && (fabs((M_PI_2 - fabs(delta))) > 0.00001f)) {
        CGFloat midAngle = startAngle + (M_PI_2 * (delta < 0 ? -1.0f : 1.0f));

        _CGPathAddArc(path, m, x, y, radius, startAngle, midAngle, clockwise);
        _CGPathAddArc(path, m, x, y, radius, midAngle, endAngle, clockwise);
        return;
    }

    CGPoint arcStartRelative = CGPointMake((cos(startAngle) * radius), (sin(startAngle) * radius));
    CGPoint arcEndRelative = CGPointMake((cos(endAngle) * radius), (sin(endAngle) * radius));

    CGPoint arcStart = CGPointMake(arcStartRelative.x + x, arcStartRelative.y + y);
    CGPoint arcEnd = CGPointMake(arcEndRelative.x + x, arcEndRelative.y + y);

    CGFloat offsetMultiplier = _CGPathControlPointOffsetMultiplier(delta);

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
    startAngle = fmod(startAngle, 2.0f * M_PI);
    if (startAngle < 0.0f) {
        startAngle += 2.0f * M_PI;
    }

    endAngle = fmod(endAngle, 2.0f * M_PI);
    if (endAngle < 0.0f) {
        endAngle += 2.0f * M_PI;
    }

    CGPoint arcStart = CGPointMake((cos(startAngle) * radius) + x, (sin(startAngle) * radius) + y);

    if (!CGPathIsEmpty(path)) {
        CGPathAddLineToPoint(path, m, arcStart.x, arcStart.y);
    } else {
        CGPathMoveToPoint(path, m, arcStart.x, arcStart.y);
    }

    if (clockwise && endAngle > startAngle) {
        startAngle += 2.0f * M_PI;
    } else if (!clockwise && startAngle > endAngle) {
        endAngle += 2.0f * M_PI;
    }

    _CGPathAddArc(path, m, x, y, radius, startAngle, endAngle, clockwise);
}

/**
 @Status Interoperable
*/
void CGPathMoveToPoint(CGMutablePathRef path, const CGAffineTransform* m, float x, float y) {
    if (m) {
        CGPoint pt;

        pt.x = x;
        pt.y = y;

        pt = CGPointApplyAffineTransform(pt, *m);

        x = pt.x;
        y = pt.y;
    }

    CGPathRef pathObj = path;

    if (pathObj->_count + 1 >= pathObj->_max) {
        pathObj->_max += 32;
        pathObj->_components = (CGPathElement*)IwRealloc(pathObj->_components, pathObj->_max * sizeof(CGPathElement));
    }

    pathObj->_components[pathObj->_count].type = kCGPathElementMoveToPoint;
    pathObj->_components[pathObj->_count].points = (CGPoint*)IwCalloc(1, sizeof(CGPoint));
    pathObj->_components[pathObj->_count].points[0] = { x, y };

    pathObj->_count++;
}

/**
 @Status Interoperable
*/
void CGPathAddLines(CGMutablePathRef path, const CGAffineTransform* m, CGPoint* points, int count) {
    if (count == 0) {
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
    CGPathMoveToPoint(path, m, CGRectGetMinX(rect), CGRectGetMinY(rect));

    CGPathAddLineToPoint(path, m, CGRectGetMaxX(rect), CGRectGetMinY(rect));
    CGPathAddLineToPoint(path, m, CGRectGetMaxX(rect), CGRectGetMaxY(rect));
    CGPathAddLineToPoint(path, m, CGRectGetMinX(rect), CGRectGetMaxY(rect));
    CGPathCloseSubpath(path);
}

/**
 @Status Interoperable
*/
void CGPathAddPath(CGMutablePathRef path, const CGAffineTransform* m, CGPathRef toAdd) {
    CGPathRef pathObj = path;
    CGPathRef copyObj = toAdd;

    if (pathObj->_count + copyObj->_count >= pathObj->_max) {
        pathObj->_max += copyObj->_count;
        pathObj->_components = (CGPathElement*)IwRealloc(pathObj->_components, pathObj->_max * sizeof(CGPathElement));
    }

    for (unsigned i = 0; i < copyObj->_count; i++) {
        CGPathElement c = copyObj->_components[i];

        if (m) {
            switch (c.type) {
                case kCGPathElementMoveToPoint:
                case kCGPathElementAddLineToPoint:
                    c.points[0] = CGPointApplyAffineTransform(c.points[0], *m);
                    break;
                default:
                    // Append the path anyway, without transforming.
                    break;
            }
        }

        pathObj->_components[pathObj->_count] = c;
        pathObj->_count++;
    }
}

/**
 @Status Interoperable
*/
void CGPathAddEllipseInRect(CGMutablePathRef path, const CGAffineTransform* m, CGRect rect) {
    CGFloat offsetMultiplier = _CGPathControlPointOffsetMultiplier(M_PI_2);

    CGFloat xControlPointOffset = offsetMultiplier * CGRectGetWidth(rect) / 2.0;
    CGFloat yControlPointOffset = offsetMultiplier * CGRectGetHeight(rect) / 2.0;

    CGFloat minX = CGRectGetMinX(rect);
    CGFloat midX = CGRectGetMidX(rect);
    CGFloat maxX = CGRectGetMaxX(rect);

    CGFloat minY = CGRectGetMinY(rect);
    CGFloat midY = CGRectGetMidY(rect);
    CGFloat maxY = CGRectGetMaxY(rect);

    CGPathMoveToPoint(path, m, maxX, midY);

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
    CGPathRef pathObj = path;

    if (pathObj->_count + 1 >= pathObj->_max) {
        pathObj->_max += 32;
        pathObj->_components = (CGPathElement*)IwRealloc(pathObj->_components, pathObj->_max * sizeof(CGPathElement));
    }

    pathObj->_components[pathObj->_count].type = kCGPathElementCloseSubpath;

    pathObj->_components[pathObj->_count].points = NULL;
    pathObj->_count++;
}

/**
 @Status Interoperable
*/
CGRect CGPathGetBoundingBox(CGPathRef path) {
    CGRect ret;

    auto context = CGBitmapContextCreate(0, 1, 1, 1, 1, 0, 0);
    path->_applyPath(context);
    ret = CGContextGetPathBoundingBox(context);
    CGContextRelease(context);

    return ret;
}

/**
 @Status Interoperable
*/
bool CGPathIsEmpty(CGPathRef path) {
    CGPathRef pathObj = path;
    return pathObj->_count == 0;
}

/**
 @Status Interoperable
*/
void CGPathRelease(CGPathRef path) {
    CFRelease(path);
}

/**
 @Status Interoperable
*/
CGPathRef CGPathRetain(CGPathRef path) {
    CFRetain(path);

    return path;
}

/**
 @Status Caveat
 @Notes transform property not supported
*/
void CGPathAddQuadCurveToPoint(CGMutablePathRef path, const CGAffineTransform* m, CGFloat cpx, CGFloat cpy, CGFloat x, CGFloat y) {
    assert(!m);
    CGPathRef pathObj = path;

    CGPoint p = { x, y };
    CGPoint cp = { cpx, cpy };

    if (pathObj->_count + 1 >= pathObj->_max) {
        pathObj->_max += 32;
        pathObj->_components = (CGPathElement*)IwRealloc(pathObj->_components, pathObj->_max * sizeof(CGPathElement));
    }

    int count = pathObj->_count;

    pathObj->_components[count].type = kCGPathElementAddQuadCurveToPoint;

    pathObj->_components[count].points = (CGPoint*)IwCalloc(2, sizeof(CGPoint));
    pathObj->_components[pathObj->_count].points[0] = cp;
    pathObj->_components[pathObj->_count].points[1] = p;

    pathObj->_count++;
}

/**
 @Status Interoperable
*/
void CGPathAddCurveToPoint(
    CGMutablePathRef path, const CGAffineTransform* m, CGFloat cp1x, CGFloat cp1y, CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y) {
    CGPathRef pathObj = path;

    CGPoint cp1 = CGPointMake(cp1x, cp1y);
    CGPoint cp2 = CGPointMake(cp2x, cp2y);
    CGPoint end = CGPointMake(x, y);

    if (m) {
        cp1 = CGPointApplyAffineTransform(cp1, *m);
        cp2 = CGPointApplyAffineTransform(cp2, *m);
        end = CGPointApplyAffineTransform(end, *m);
    }

    if (pathObj->_count + 1 >= pathObj->_max) {
        pathObj->_max += 32;
        pathObj->_components = (CGPathElement*)IwRealloc(pathObj->_components, pathObj->_max * sizeof(CGPathElement));
    }

    int count = pathObj->_count;

    pathObj->_components[count].type = kCGPathElementAddCurveToPoint;
    pathObj->_components[count].points = (CGPoint*)IwCalloc(3, sizeof(CGPoint));
    pathObj->_components[count].points[0] = cp1;
    pathObj->_components[count].points[1] = cp2;
    pathObj->_components[count].points[2] = end;

    pathObj->_count++;
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
    printf("Tried to create an ellipse, not implemented, creating rect..\n");

    CGMutablePathRef ret = CGPathCreateMutable();
    CGPathAddRect(ret, 0, rect);

    return (CGPathRef)ret;
}

/**
 @Status Stub
*/
CGRect CGPathGetPathBoundingBox(CGPathRef self) {
    UNIMPLEMENTED();

    CGRect ret;
    return ret;
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
 @Status Interoperable
*/
void CGPathApply(CGPathRef path, void* info, CGPathApplierFunction function) {
    if (path == NULL) {
        return;
    }

    for (unsigned i = 0; i < path->_count; i++) {
        CGPathElement element = path->_components[i];
        CGPathElement returnElement;
        returnElement.type = element.type;
        int pointCount = _CGPathPointCountForElementType(element.type);
        returnElement.points = (CGPoint*)IwCalloc(pointCount, sizeof(CGPoint));
        memcpy(returnElement.points, element.points, pointCount * sizeof(CGPoint));
        function(info, &returnElement);
        if (returnElement.points) {
            IwFree(returnElement.points);
        }
    }
}

/**
 @Status Stub
 @Notes
*/
bool CGPathContainsPoint(CGPathRef path, const CGAffineTransform* m, CGPoint point, bool eoFill) {
    UNIMPLEMENTED();
    return StubReturn();
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
 @Notes
*/
bool CGPathEqualToPath(CGPathRef path1, CGPathRef path2) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
CGPoint CGPathGetCurrentPoint(CGPathRef path) {
    if (path->_count > 0) {
        CGPathElement c = path->_components[path->_count - 1];
        switch (c.type) {
            case kCGPathElementMoveToPoint:
            case kCGPathElementAddLineToPoint:
                return c.points[0];
            case kCGPathElementAddQuadCurveToPoint:
                return c.points[1];
            case kCGPathElementAddCurveToPoint:
                return c.points[2];
            default:
                return CGPointZero;
        }
    }

    return CGPointZero;
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CGPathGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
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
    CGPathRef path = pathref;

    ScanlineCalculator s;
    s.SetExtents(rect.origin.y, maxSize.width, rect.size.height, padding);

    CGPoint curPoint = { 0, 0 };
    CGPoint startPoint = { 0, 0 };
    bool startPointSet = false;

    for (unsigned i = 0; i < path->_count; i++) {
        switch (path->_components[i].type) {
            case kCGPathElementMoveToPoint:
                if (!startPointSet) {
                    startPoint = path->_components[i].points[0];
                    startPointSet = true;
                }
                curPoint = path->_components[i].points[0];
                break;

            case kCGPathElementAddLineToPoint:
                if (!startPointSet) {
                    startPoint = path->_components[i].points[0];
                    startPointSet = true;
                }
                s.AddLine(curPoint, path->_components[i].points[0]);
                curPoint = path->_components[i].points[0];
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
}
