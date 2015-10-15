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

#ifndef __CGPATHINTERNAL_H
#define __CGPATHINTERNAL_H

#include "CoreGraphics/CGPath.h"

enum pathComponentType {
    pathComponentRectangle,
    pathComponentMove,
    pathComponentLineTo,
    pathComponentArcToPoint,
    pathComponentQuadCurve,
    pathComponentBezierCurve,
    pathComponentCurve,
    pathComponentEllipseInRect,
    pathComponentClose,
    pathComponentArcAngle,
};

typedef struct {
    float x1, y1, x2, y2;
    float radius;
} arcToPoint;

typedef struct {
    float x, y, startAngle, endAngle;
    float radius;
    BOOL clockwise;
} arcAngle;

struct curveToPoint {
    float x1, y1; // tangent from start
    float x2, y2; // tangent to end
    float x, y; // end pos
};

struct quadCurveToPoint {
    float cpx, cpy;
    float x, y;
};

struct ellipseInRect {
    CGRect rect;
};

typedef struct {
    pathComponentType type;

    union {
        CGRect rect;
        CGPoint point;
        arcToPoint atp;
        curveToPoint ctp;
        ellipseInRect eir;
        quadCurveToPoint qtp;
        arcAngle aa;
    };
} pathComponent;

@interface CGPath : NSObject {
@public
    pathComponent* _components;
    NSUInteger _count;
    NSUInteger _max;
}
@end

#endif
