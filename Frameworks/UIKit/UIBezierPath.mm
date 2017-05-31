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

#import "UIKit/UIKit.h"
#import "CoreGraphics/CGPath.h"
#import "CoreGraphics/CGGeometry.h"
#import "CoreGraphics/CGContext.h"
#import "StubReturn.h"

@implementation UIBezierPath {
    float* _pattern;
    NSInteger _patternCount;
    float _dashPhase;

    CGMutablePathRef _workingPath;
}

/**
 @Status Caveat
 @Notes Ignores UIRectCorner options and cornerRadii height.
        TODO : GH#2749
*/
+ (instancetype)bezierPathWithRoundedRect:(CGRect)rect byRoundingCorners:(UIRectCorner)roundingCorners cornerRadii:(CGSize)size {
    UIBezierPath* ret = [[[self alloc] init] autorelease];

    CGRect innerRect;

    float radius = size.width;
    innerRect = CGRectInset(rect, float(radius), float(radius));

    CGFloat inside_right = innerRect.origin.x + innerRect.size.width;
    CGFloat outside_right = rect.origin.x + rect.size.width;
    CGFloat inside_bottom = innerRect.origin.y + innerRect.size.height;
    CGFloat outside_bottom = rect.origin.y + rect.size.height;

    CGFloat inside_top = innerRect.origin.y;
    CGFloat outside_top = rect.origin.y;
    CGFloat outside_left = rect.origin.x;

    CGPathMoveToPoint(ret->_workingPath, NULL, innerRect.origin.x, outside_top);

    CGPathAddLineToPoint(ret->_workingPath, NULL, inside_right, outside_top);
    CGPathAddArcToPoint(ret->_workingPath, NULL, outside_right, outside_top, outside_right, inside_top, radius);
    CGPathAddLineToPoint(ret->_workingPath, NULL, outside_right, inside_bottom);
    CGPathAddArcToPoint(ret->_workingPath, NULL, outside_right, outside_bottom, inside_right, outside_bottom, radius);

    CGPathAddLineToPoint(ret->_workingPath, NULL, innerRect.origin.x, outside_bottom);
    CGPathAddArcToPoint(ret->_workingPath, NULL, outside_left, outside_bottom, outside_left, inside_bottom, radius);
    CGPathAddLineToPoint(ret->_workingPath, NULL, outside_left, inside_top);
    CGPathAddArcToPoint(ret->_workingPath, NULL, outside_left, outside_top, innerRect.origin.x, outside_top, radius);
    CGPathCloseSubpath(ret->_workingPath);

    return ret;
}

/**
 @Status Interoperable
*/
+ (instancetype)bezierPathWithRoundedRect:(CGRect)rect cornerRadius:(CGFloat)radius {
    UIBezierPath* ret = [[[self alloc] init] autorelease];

    CGPathAddRoundedRect(ret->_workingPath, nullptr, rect, radius, radius);

    return ret;
}

/**
 @Status Interoperable
*/
+ (instancetype)bezierPathWithArcCenter:(CGPoint)center
                                 radius:(CGFloat)radius
                             startAngle:(CGFloat)startAngle
                               endAngle:(CGFloat)endAngle
                              clockwise:(BOOL)clockwise {
    UIBezierPath* ret = [[[self alloc] init] autorelease];

    // Path needs to move to the actual start of the arc location otherwise CGPathAddArc will draw a line to this
    // start point instead.
    CGPathMoveToPoint(ret->_workingPath, NULL, center.x + cos(startAngle) * radius, center.y + sin(startAngle) * radius);
    CGPathAddArc(ret->_workingPath, NULL, center.x, center.y, radius, startAngle, endAngle, clockwise == FALSE);

    return ret;
}

/**
 @Status Interoperable
*/
+ (instancetype)bezierPathWithRect:(CGRect)rect {
    UIBezierPath* ret = [[[self alloc] init] autorelease];

    CGPathAddRect(ret->_workingPath, NULL, rect);

    return ret;
}

/**
 @Status Interoperable
*/
+ (instancetype)bezierPathWithCGPath:(CGPathRef)path {
    UIBezierPath* ret = [[[self alloc] init] autorelease];

    CGPathAddPath(ret->_workingPath, NULL, path);

    return ret;
}

/**
 @Status Interoperable
*/
+ (instancetype)bezierPathWithOvalInRect:(CGRect)rect {
    UIBezierPath* ret = [[[self alloc] init] autorelease];

    CGPathAddEllipseInRect(ret->_workingPath, NULL, rect);

    return ret;
}

/**
 @Status Interoperable
*/
+ (instancetype)bezierPath {
    return [[[self alloc] init] autorelease];
}

/**
 @Status Interoperable
*/
- (void)appendPath:(UIBezierPath*)path {
    CGPathAddPath(_workingPath, NULL, path.CGPath);
}

/**
 @Status Interoperable
*/
- (void)addArcWithCenter:(CGPoint)center
                  radius:(CGFloat)radius
              startAngle:(CGFloat)startAngle
                endAngle:(CGFloat)endAngle
               clockwise:(BOOL)clockwise {
    CGPathAddArc(_workingPath, NULL, center.x, center.y, radius, startAngle, endAngle, clockwise == TRUE);
}

/**
 @Status Interoperable
*/
- (void)addLineToPoint:(CGPoint)pt {
    CGPathAddLineToPoint(_workingPath, NULL, pt.x, pt.y);
}

/**
 @Status Interoperable
*/
- (void)moveToPoint:(CGPoint)pt {
    CGPathMoveToPoint(_workingPath, NULL, pt.x, pt.y);
}

/**
 @Status Interoperable
*/
- (void)closePath {
    CGPathCloseSubpath(_workingPath);
}

/**
 @Status Interoperable
*/
- (CGPathRef)CGPath {
    return CGPathCreateCopy(_workingPath);
}

/**
 @Status Interoperable
*/
- (void)setCGPath:(CGPathRef)path {
    CGPathRelease(_workingPath);
    _workingPath = CGPathCreateMutableCopy(path);
}

/**
 @Status Interoperable
*/
- (void)addQuadCurveToPoint:(CGPoint)endPoint controlPoint:(CGPoint)controlPoint {
    CGPathAddQuadCurveToPoint(_workingPath, NULL, controlPoint.x, controlPoint.y, endPoint.x, endPoint.y);
}

/**
 @Status Interoperable
*/
- (void)addCurveToPoint:(CGPoint)endPoint controlPoint1:(CGPoint)controlPoint1 controlPoint2:(CGPoint)controlPoint2 {
    CGPathAddCurveToPoint(_workingPath, NULL, controlPoint1.x, controlPoint1.y, controlPoint2.x, controlPoint2.y, endPoint.x, endPoint.y);
}

/**
 @Status Interoperable
*/
- (void)applyTransform:(CGAffineTransform)transform {
    CGPathRef transformedPath = CGPathCreateMutableCopyByTransformingPath(_workingPath, &transform);
    CGPathRelease(_workingPath);
    _workingPath = transformedPath;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self = [super init]) {
        _workingPath = CGPathCreateMutable();
        _lineWidth = 1.0f;
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)fill {
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    CGContextSaveGState(ctx);
    CGContextBeginPath(ctx);
    CGContextAddPath(ctx, _workingPath);

    if (_usesEvenOddFillRule) {
        CGContextEOFillPath(ctx);
    } else {
        CGContextFillPath(ctx);
    }
    CGContextRestoreGState(ctx);
}

/**
 @Status Interoperable
*/
- (void)addClip {
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    CGContextBeginPath(ctx);
    CGContextAddPath(ctx, _workingPath);

    if (_usesEvenOddFillRule) {
        CGContextEOClip(ctx);
    } else {
        CGContextClip(ctx);
    }
    CGContextBeginPath(ctx);
}

/**
 @Status Interoperable
*/
- (void)stroke {
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    CGContextSaveGState(ctx);
    CGContextBeginPath(ctx);
    CGContextAddPath(ctx, _workingPath);
    CGContextSetLineWidth(ctx, _lineWidth);
    CGContextSetLineJoin(ctx, _lineJoinStyle);
    if (_pattern) {
        CGContextSetLineDash(ctx, _dashPhase, _pattern, _patternCount);
    }
    CGContextStrokePath(ctx);
    CGContextRestoreGState(ctx);
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    if (_pattern) {
        free(_pattern);
        _pattern = NULL;
    }

    CGPathRelease(_workingPath);
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (void)setLineDash:(const CGFloat*)pattern count:(NSInteger)count phase:(CGFloat)phase {
    if (_pattern) {
        free(_pattern);
        _pattern = NULL;
    }

    _patternCount = count;
    _dashPhase = phase;

    if (count > 0) {
        _pattern = (CGFloat*)malloc(sizeof(CGFloat) * count);
        memcpy(_pattern, pattern, sizeof(CGFloat) * count);
    }
}

/**
 @Status Interoperable
*/
- (void)removeAllPoints {
    CGPathRelease(_workingPath);
    _workingPath = CGPathCreateMutable();
}

/**
 @Status Interoperable
*/
- (void)getLineDash:(CGFloat*)pattern count:(NSInteger*)count phase:(CGFloat*)phase {
    if (phase) {
        *phase = _dashPhase;
    }
    if (count) {
        *count = _patternCount;
    }

    if (pattern && _patternCount > 0) {
        memcpy(pattern, _pattern, sizeof(CGFloat) * _patternCount);
    }
}

/**
 @Status Stub
*/
- (void)fillWithBlendMode:(CGBlendMode)blendMode alpha:(CGFloat)alpha {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)strokeWithBlendMode:(CGBlendMode)blendMode alpha:(CGFloat)alpha {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (BOOL)containsPoint:(CGPoint)point {
    return CGPathContainsPoint(_workingPath, NULL, point, _usesEvenOddFillRule);
}

/**
 @Status Interoperable
*/
- (BOOL)isEmpty {
    return CGPathIsEmpty(_workingPath);
}

/**
 @Status Interoperable
*/
- (CGPoint)currentPoint {
    return CGPathGetCurrentPoint(_workingPath);
}

@end
