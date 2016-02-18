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
#import <algorithm>
#import <vector>
#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGGeometry.h>
#import "CGPathInternal.h"

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

@implementation CGPath : NSObject
- (void)dealloc {
    if (_components) {
        EbrFree(_components);
    }

    [super dealloc];
}

- (void)_applyPath:(CGContextRef)context {
    for (unsigned i = 0; i < _count; i++) {
        switch (_components[i].type) {
            case pathComponentRectangle:
                CGContextAddRect(context, _components[i].rect);
                break;

            case pathComponentMove:
                EbrDebugLog("Move to %d, %d\n", (int)_components[i].point.x, (int)_components[i].point.y);
                CGContextMoveToPoint(context, _components[i].point.x, _components[i].point.y);
                break;

            case pathComponentLineTo:
                EbrDebugLog("Line to %d, %d\n", (int)_components[i].point.x, (int)_components[i].point.y);
                CGContextAddLineToPoint(context, _components[i].point.x, _components[i].point.y);
                break;

            case pathComponentArcToPoint:
                CGContextAddArcToPoint(context,
                                       _components[i].atp.x1,
                                       _components[i].atp.y1,
                                       _components[i].atp.x2,
                                       _components[i].atp.y2,
                                       _components[i].atp.radius);
                break;

            case pathComponentArcAngle:
                CGContextAddArc(context,
                                _components[i].aa.x,
                                _components[i].aa.y,
                                _components[i].aa.radius,
                                _components[i].aa.startAngle,
                                _components[i].aa.endAngle,
                                _components[i].aa.clockwise);
                break;

            case pathComponentCurve:
                CGContextAddCurveToPoint(context,
                                         _components[i].ctp.x1,
                                         _components[i].ctp.y1,
                                         _components[i].ctp.x2,
                                         _components[i].ctp.y2,
                                         _components[i].ctp.x,
                                         _components[i].ctp.y);
                break;

            case pathComponentEllipseInRect:
                CGContextAddEllipseInRect(context, _components[i].eir.rect);
                break;

            case pathComponentQuadCurve:
                CGContextAddQuadCurveToPoint(context,
                                             _components[i].qtp.cpx,
                                             _components[i].qtp.cpy,
                                             _components[i].qtp.x,
                                             _components[i].qtp.y);
                break;

            case pathComponentClose:
                CGContextClosePath(context);
                break;

            default:
                assert(0);
                break;
        }
    }
}

- (void)_measurePath:(CGSize*)sizeOut {
    sizeOut->width = 0;
    sizeOut->height = 0;

    for (unsigned i = 0; i < _count; i++) {
        switch (_components[i].type) {
            case pathComponentRectangle:
                if (_components[i].rect.origin.x + _components[i].rect.size.width > sizeOut->width) {
                    sizeOut->width = _components[i].rect.origin.x + _components[i].rect.size.width;
                }
                if (_components[i].rect.origin.y + _components[i].rect.size.height > sizeOut->height) {
                    sizeOut->height = _components[i].rect.origin.y + _components[i].rect.size.height;
                }
                break;

            case pathComponentMove:
                if (_components[i].point.x > sizeOut->width) {
                    sizeOut->width = _components[i].point.x;
                }
                if (_components[i].point.y > sizeOut->height) {
                    sizeOut->height = _components[i].point.y;
                }
                break;

            case pathComponentLineTo:
                if (_components[i].point.x > sizeOut->width) {
                    sizeOut->width = _components[i].point.x;
                }
                if (_components[i].point.y > sizeOut->height) {
                    sizeOut->height = _components[i].point.y;
                }
                break;

            default:
                assert(0);
                break;
        }
    }
}

- (void)_getBoundingBox:(CGRect*)rectOut {
    BBox bbox;

    for (unsigned i = 0; i < _count; i++) {
        switch (_components[i].type) {
            case pathComponentMove:
            case pathComponentLineTo:
                bbox.addPoint(_components[i].point.x, _components[i].point.y);
                break;

            case pathComponentArcToPoint:
                bbox.addPoint(_components[i].atp.x1, _components[i].atp.y1);
                bbox.addPoint(_components[i].atp.x2, _components[i].atp.y2);
                break;

            case pathComponentCurve:
                bbox.addPoint(_components[i].ctp.x1, _components[i].ctp.y1);
                bbox.addPoint(_components[i].ctp.x2, _components[i].ctp.y2);
                bbox.addPoint(_components[i].ctp.x, _components[i].ctp.y);
                break;

            case pathComponentArcAngle:
                bbox.addPoint(_components[i].aa.x - _components[i].aa.radius, _components[i].aa.y - _components[i].aa.radius);
                bbox.addPoint(_components[i].aa.x + _components[i].aa.radius, _components[i].aa.y + _components[i].aa.radius);
                break;

            case pathComponentQuadCurve:
                bbox.addPoint(_components[i].qtp.cpx, _components[i].qtp.cpy);
                bbox.addPoint(_components[i].qtp.x, _components[i].qtp.y);
                break;

            case pathComponentEllipseInRect:
                bbox.addPoint(_components[i].eir.rect.origin.x, _components[i].eir.rect.origin.y);
                bbox.addPoint(_components[i].eir.rect.origin.x + _components[i].eir.rect.size.width,
                              _components[i].eir.rect.origin.y + _components[i].eir.rect.size.height);
                break;

            case pathComponentClose:
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

- (instancetype)copyWithZone:(NSZone*)zone {
    return [self mutableCopyWithZone:zone];
}

- (instancetype)mutableCopyWithZone:(NSZone*)zone {
    CGPath* ret = [CGPath alloc];
    ret->_max = _max;
    ret->_count = _count;
    ret->_components = (pathComponent*)EbrRealloc(ret->_components, ret->_max * sizeof(pathComponent));
    memcpy(ret->_components, _components, _count * sizeof(pathComponent));

    return ret;
}

@end

/**
 @Status Interoperable
*/
CGMutablePathRef CGPathCreateMutable() {
    return [CGPath new];
}

/**
 @Status Caveat
 @Notes Creates a mutable copy
*/
CGPathRef CGPathCreateCopy(CGPathRef path) {
    return [path mutableCopy];
}

/**
 @Status Interoperable
*/
CGMutablePathRef CGPathCreateMutableCopy(CGPathRef path) {
    return [path mutableCopy];
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

    CGPath* pathObj = path;

    if (pathObj->_count + 1 >= pathObj->_max) {
        pathObj->_max += 32;
        pathObj->_components = (pathComponent*)EbrRealloc(pathObj->_components, pathObj->_max * sizeof(pathComponent));
    }

    pathObj->_components[pathObj->_count].type = pathComponentLineTo;
    pathObj->_components[pathObj->_count].point.x = x;
    pathObj->_components[pathObj->_count].point.y = y;

    pathObj->_count++;
}

/**
 @Status Caveat
 @Notes transform property not supported
*/
void CGPathAddArcToPoint(CGMutablePathRef path, const CGAffineTransform* m, float x1, float y1, float x2, float y2, float radius) {
    if (m) {
        assert(0);
    }

    CGPath* pathObj = path;

    if (pathObj->_count + 1 >= pathObj->_max) {
        pathObj->_max += 32;
        pathObj->_components = (pathComponent*)EbrRealloc(pathObj->_components, pathObj->_max * sizeof(pathComponent));
    }

    pathObj->_components[pathObj->_count].type = pathComponentArcToPoint;
    pathObj->_components[pathObj->_count].atp.x1 = x1;
    pathObj->_components[pathObj->_count].atp.y1 = y1;
    pathObj->_components[pathObj->_count].atp.x2 = x2;
    pathObj->_components[pathObj->_count].atp.y2 = y2;
    pathObj->_components[pathObj->_count].atp.radius = radius;

    pathObj->_count++;
}

/**
 @Status Caveat
 @Notes transform property not supported
*/
void CGPathAddArc(CGMutablePathRef path,
                  const CGAffineTransform* m,
                  CGFloat x,
                  CGFloat y,
                  CGFloat radius,
                  CGFloat startAngle,
                  CGFloat endAngle,
                  bool clockwise) {
    assert(!m);

    CGPath* pathObj = path;

    if (pathObj->_count + 1 >= pathObj->_max) {
        pathObj->_max += 32;
        pathObj->_components = (pathComponent*)EbrRealloc(pathObj->_components, pathObj->_max * sizeof(pathComponent));
    }

    pathObj->_components[pathObj->_count].type = pathComponentArcAngle;
    pathObj->_components[pathObj->_count].aa.x = x;
    pathObj->_components[pathObj->_count].aa.y = y;
    pathObj->_components[pathObj->_count].aa.radius = radius;
    pathObj->_components[pathObj->_count].aa.startAngle = startAngle;
    pathObj->_components[pathObj->_count].aa.endAngle = endAngle;
    pathObj->_components[pathObj->_count].aa.clockwise = clockwise;

    pathObj->_count++;
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

    CGPath* pathObj = path;

    if (pathObj->_count + 1 >= pathObj->_max) {
        pathObj->_max += 32;
        pathObj->_components = (pathComponent*)EbrRealloc(pathObj->_components, pathObj->_max * sizeof(pathComponent));
    }

    pathObj->_components[pathObj->_count].type = pathComponentMove;
    pathObj->_components[pathObj->_count].point.x = x;
    pathObj->_components[pathObj->_count].point.y = y;

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
    if (m) {
        rect = CGRectApplyAffineTransform(rect, *m);
    }

    /*
    CGPath* pathObj = path;

    if ( pathObj->_count + 1 >= pathObj->_max ) {
    pathObj->_max += 32;
    pathObj->_components = (pathComponent *) EbrRealloc(pathObj->_components, pathObj->_max * sizeof(pathComponent));
    }

    pathObj->_components[pathObj->_count].type = pathComponentRectangle;
    pathObj->_components[pathObj->_count].rect = rect;

    pathObj->_count ++;
    */

    CGPathMoveToPoint(path, m, CGRectGetMinX(rect), CGRectGetMinY(rect));

    CGPathAddLineToPoint(path, m, CGRectGetMaxX(rect), CGRectGetMinY(rect));
    CGPathAddLineToPoint(path, m, CGRectGetMaxX(rect), CGRectGetMaxY(rect));
    CGPathAddLineToPoint(path, m, CGRectGetMinX(rect), CGRectGetMaxY(rect));
    CGPathAddLineToPoint(path, m, CGRectGetMinX(rect), CGRectGetMinY(rect));
}

/**
 @Status Interoperable
*/
void CGPathAddPath(CGMutablePathRef path, const CGAffineTransform* m, CGPathRef toAdd) {
    CGPath* pathObj = path;
    CGPath* copyObj = toAdd;

    if (pathObj->_count + copyObj->_count >= pathObj->_max) {
        pathObj->_max += copyObj->_count;
        pathObj->_components = (pathComponent*)EbrRealloc(pathObj->_components, pathObj->_max * sizeof(pathComponent));
    }

    for (unsigned i = 0; i < copyObj->_count; i++) {
        pathComponent c = copyObj->_components[i];

        if (m) {
            switch (c.type) {
                case pathComponentMove:
                case pathComponentLineTo:
                    c.point = CGPointApplyAffineTransform(c.point, *m);
                    break;
            }
        }

        pathObj->_components[pathObj->_count] = c;
        pathObj->_count++;
    }
}

/**
 @Status Caveat
 @Notes transform property not supported
*/
void CGPathAddEllipseInRect(CGMutablePathRef path, const CGAffineTransform* m, CGRect rect) {
    CGPathCloseSubpath(path);

    if (m) {
        assert(0);
    }

    CGPath* pathObj = path;

    if (pathObj->_count + 1 >= pathObj->_max) {
        pathObj->_max += 32;
        pathObj->_components = (pathComponent*)EbrRealloc(pathObj->_components, pathObj->_max * sizeof(pathComponent));
    }

    pathObj->_components[pathObj->_count].type = pathComponentEllipseInRect;
    pathObj->_components[pathObj->_count].eir.rect = rect;

    pathObj->_count++;

    CGPathCloseSubpath(path);
    CGPathMoveToPoint(path, m, rect.origin.x + rect.size.width, rect.origin.y + rect.size.height / 2.0f);
}

/**
 @Status Interoperable
*/
void CGPathCloseSubpath(CGMutablePathRef path) {
    CGPath* pathObj = path;

    if (pathObj->_count + 1 >= pathObj->_max) {
        pathObj->_max += 32;
        pathObj->_components = (pathComponent*)EbrRealloc(pathObj->_components, pathObj->_max * sizeof(pathComponent));
    }

    pathObj->_components[pathObj->_count].type = pathComponentClose;

    pathObj->_count++;
}

/**
 @Status Interoperable
*/
CGRect CGPathGetBoundingBox(CGPathRef path) {
    CGRect ret;

    auto context = CGBitmapContextCreate(0, 1, 1, 1, 1, 0, 0);
    [path _applyPath:context];
    ret = CGContextGetPathBoundingBox(context);
    CGContextRelease(context);

    return ret;
}

/**
 @Status Interoperable
*/
bool CGPathIsEmpty(CGPathRef path) {
    CGPath* pathObj = path;
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
    CGPath* pathObj = path;

    CGPoint p = { x, y };
    CGPoint cp = { cpx, cpy };

    if (pathObj->_count + 1 >= pathObj->_max) {
        pathObj->_max += 32;
        pathObj->_components = (pathComponent*)EbrRealloc(pathObj->_components, pathObj->_max * sizeof(pathComponent));
    }

    int count = pathObj->_count;

    pathObj->_components[count].type = pathComponentQuadCurve;
    pathObj->_components[count].qtp.cpx = cp.x;
    pathObj->_components[count].qtp.cpy = cp.y;
    pathObj->_components[count].qtp.x = p.x;
    pathObj->_components[count].qtp.y = p.y;

    pathObj->_count++;
}

/**
 @Status Caveat
 @Notes transform property not supported
*/
void CGPathAddCurveToPoint(
    CGMutablePathRef path, const CGAffineTransform* m, CGFloat cp1x, CGFloat cp1y, CGFloat cp2x, CGFloat cp2y, CGFloat x, CGFloat y) {
    CGPath* pathObj = path;

    assert(!m);

    if (pathObj->_count + 1 >= pathObj->_max) {
        pathObj->_max += 32;
        pathObj->_components = (pathComponent*)EbrRealloc(pathObj->_components, pathObj->_max * sizeof(pathComponent));
    }

    int count = pathObj->_count;

    pathObj->_components[count].type = pathComponentCurve;
    pathObj->_components[count].ctp.x1 = cp1x;
    pathObj->_components[count].ctp.y1 = cp1y;
    pathObj->_components[count].ctp.x2 = cp2x;
    pathObj->_components[count].ctp.y2 = cp2y;
    pathObj->_components[count].ctp.x = x;
    pathObj->_components[count].ctp.y = y;

    pathObj->_count++;
}

/**
 @Status Interoperable
*/
CGPathRef CGPathCreateWithRect(CGRect rect, const CGAffineTransform* trans) {
    CGMutablePathRef ret = (CGMutablePathRef)[CGPath new];
    CGPathAddRect(ret, trans, rect);

    return (CGPathRef)ret;
}

/**
 @Status Interoperable
*/
CGPathRef CGPathCreateWithEllipseInRect(CGRect rect, const CGAffineTransform* transform) {
    printf("Tried to create an ellipse, not implemented, creating rect..\n");

    CGMutablePathRef ret = (CGMutablePathRef)[CGPath new];
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

/**
 @Status Stub
 @Notes
*/
void CGPathApply(CGPathRef path, void* info, CGPathApplierFunction function) {
    UNIMPLEMENTED();
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
 @Status Stub
 @Notes
*/
CGPoint CGPathGetCurrentPoint(CGPathRef path) {
    UNIMPLEMENTED();
    return StubReturn();
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
    CGPath* path = pathref;

    ScanlineCalculator s;
    s.SetExtents(rect.origin.y, maxSize.width, rect.size.height, padding);

    CGPoint curPoint = { 0, 0 };
    CGPoint startPoint = { 0, 0 };
    bool startPointSet = false;

    for (unsigned i = 0; i < path->_count; i++) {
        switch (path->_components[i].type) {
            case pathComponentMove:
                if (!startPointSet) {
                    startPoint = path->_components[i].point;
                    startPointSet = true;
                }
                curPoint = path->_components[i].point;
                break;

            case pathComponentLineTo:
                if (!startPointSet) {
                    startPoint = path->_components[i].point;
                    startPointSet = true;
                }
                s.AddLine(curPoint, path->_components[i].point);
                curPoint = path->_components[i].point;
                break;

            case pathComponentClose:
                if (startPointSet) {
                    s.AddLine(curPoint, startPoint);
                }
                break;
        }
    }

    if (s.FindLargestRect(rect.origin, rect.size.height, rect)) {
        return rect;
    } else {
        return CGRectMake(0, 0, 0, 0);
    }
}
