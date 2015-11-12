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

static CGAffineTransform* getTransform(UIBezierPath* path);

@implementation UIBezierPath {
    float _lineWidth;
    CGLineJoin _lineJoin;
    CGPathRef _path;
    BOOL _usesEvenOddFillRule;

    float* _pattern;
    NSInteger _patternCount;
    float _dashPhase;

    bool _hasTransform;
    CGAffineTransform _transform;
}

CGAffineTransform* getTransform(UIBezierPath* path) {
    if (path->_hasTransform) {
        return &path->_transform;
    } else {
        return NULL;
    }
}

/**
 @Status Interoperable
*/
+ (instancetype)bezierPathWithRoundedRect:(CGRect)rect byRoundingCorners:(UIRectCorner)roundingCorners cornerRadii:(CGSize)size {
    UIBezierPath* ret = [self new];

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

    CGPathMoveToPoint(ret->_path, getTransform(ret), innerRect.origin.x, outside_top);

    CGPathAddLineToPoint(ret->_path, getTransform(ret), inside_right, outside_top);
    CGPathAddArcToPoint(ret->_path, getTransform(ret), outside_right, outside_top, outside_right, inside_top, radius);
    CGPathAddLineToPoint(ret->_path, getTransform(ret), outside_right, inside_bottom);
    CGPathAddArcToPoint(ret->_path, getTransform(ret), outside_right, outside_bottom, inside_right, outside_bottom, radius);

    CGPathAddLineToPoint(ret->_path, getTransform(ret), innerRect.origin.x, outside_bottom);
    CGPathAddArcToPoint(ret->_path, NULL, outside_left, outside_bottom, outside_left, inside_bottom, radius);
    CGPathAddLineToPoint(ret->_path, NULL, outside_left, inside_top);
    CGPathAddArcToPoint(ret->_path, NULL, outside_left, outside_top, innerRect.origin.x, outside_top, radius);

    CGPathCloseSubpath(ret->_path);

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)bezierPathWithRoundedRect:(CGRect)rect cornerRadius:(CGFloat)radius {
    UIBezierPath* ret = [self new];

    CGRect innerRect;

    innerRect = CGRectInset(rect, radius, radius);

    CGFloat inside_right = innerRect.origin.x + innerRect.size.width;
    CGFloat outside_right = rect.origin.x + rect.size.width;
    CGFloat inside_bottom = innerRect.origin.y + innerRect.size.height;
    CGFloat outside_bottom = rect.origin.y + rect.size.height;

    CGFloat inside_top = innerRect.origin.y;
    CGFloat outside_top = rect.origin.y;
    CGFloat outside_left = rect.origin.x;

    CGPathMoveToPoint(ret->_path, NULL, innerRect.origin.x, outside_top);

    CGPathAddLineToPoint(ret->_path, NULL, inside_right, outside_top);
    CGPathAddArcToPoint(ret->_path, NULL, outside_right, outside_top, outside_right, inside_top, radius);
    CGPathAddLineToPoint(ret->_path, NULL, outside_right, inside_bottom);
    CGPathAddArcToPoint(ret->_path, NULL, outside_right, outside_bottom, inside_right, outside_bottom, radius);

    CGPathAddLineToPoint(ret->_path, NULL, innerRect.origin.x, outside_bottom);
    CGPathAddArcToPoint(ret->_path, NULL, outside_left, outside_bottom, outside_left, inside_bottom, radius);
    CGPathAddLineToPoint(ret->_path, NULL, outside_left, inside_top);
    CGPathAddArcToPoint(ret->_path, NULL, outside_left, outside_top, innerRect.origin.x, outside_top, radius);

    CGPathCloseSubpath(ret->_path);

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)bezierPathWithArcCenter:(CGPoint)center
                                 radius:(CGFloat)radius
                             startAngle:(CGFloat)startAngle
                               endAngle:(CGFloat)endAngle
                              clockwise:(BOOL)clockwise {
    UIBezierPath* ret = [self new];

    CGPathAddArc(ret->_path, NULL, center.x, center.y, radius, startAngle, endAngle, clockwise == FALSE);

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)bezierPathWithRect:(CGRect)rect {
    UIBezierPath* ret = [self new];

    CGPathAddRect(ret->_path, NULL, rect);

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)bezierPathWithCGPath:(CGPathRef)path {
    UIBezierPath* ret = [self new];

    CGPathAddPath(ret->_path, NULL, path);

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)bezierPathWithOvalInRect:(CGRect)rect {
    UIBezierPath* ret = [self new];

    CGPathAddEllipseInRect(ret->_path, NULL, rect);

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)bezierPath {
    return [[self new] autorelease];
}

/**
 @Status Interoperable
*/
- (void)appendPath:(UIBezierPath*)path {
    CGPathAddPath(_path, getTransform(self), path->_path);
}

/**
 @Status Interoperable
*/
- (void)addArcWithCenter:(CGPoint)center
                  radius:(CGFloat)radius
              startAngle:(CGFloat)startAngle
                endAngle:(CGFloat)endAngle
               clockwise:(BOOL)clockwise {
    CGPathAddArc(_path, NULL, center.x, center.y, radius, startAngle, endAngle, clockwise == FALSE);
}

/**
 @Status Interoperable
*/
- (void)addLineToPoint:(CGPoint)pt {
    CGPathAddLineToPoint(_path, getTransform(self), pt.x, pt.y);
}

/**
 @Status Interoperable
*/
- (void)moveToPoint:(CGPoint)pt {
    CGPathMoveToPoint(_path, getTransform(self), pt.x, pt.y);
}

/**
 @Status Interoperable
*/
- (void)closePath {
    CGPathCloseSubpath(_path);
}

/**
 @Status Interoperable
*/
- (CGPathRef)CGPath {
    return _path;
}

/**
 @Status Interoperable
*/
- (void)setCGPath:(CGPathRef)path {
    CGPathRetain(path);
    CGPathRelease(_path);
    _path = path;
}

/**
 @Status Interoperable
*/
- (void)addQuadCurveToPoint:(CGPoint)endPoint controlPoint:(CGPoint)controlPoint {
    CGPathAddQuadCurveToPoint(_path, getTransform(self), controlPoint.x, controlPoint.y, endPoint.x, endPoint.y);
}

/**
 @Status Interoperable
*/
- (void)addCurveToPoint:(CGPoint)endPoint controlPoint1:(CGPoint)controlPoint1 controlPoint2:(CGPoint)controlPoint2 {
    CGPathAddCurveToPoint(
        _path, getTransform(self), controlPoint1.x, controlPoint1.y, controlPoint2.x, controlPoint2.y, endPoint.x, endPoint.y);
}

/**
 @Status Interoperable
*/
- (void)applyTransform:(CGAffineTransform)transform {
    _transform = transform;
    _hasTransform = true;
}

- (instancetype)init {
    _path = CGPathCreateMutable();
    _lineWidth = 1.0f;

    return self;
}

/**
 @Status Interoperable
*/
- (void)fill {
    CGContextRef ctx = UIGraphicsGetCurrentContext();
    CGContextSaveGState(ctx);
    CGContextBeginPath(ctx);
    CGContextAddPath(ctx, _path);

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
    CGContextAddPath(ctx, _path);

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
    CGContextAddPath(ctx, _path);
    CGContextSetLineWidth(ctx, _lineWidth);
    CGContextSetLineJoin(ctx, _lineJoin);
    if (_pattern) {
        CGContextSetLineDash(ctx, _dashPhase, _pattern, _patternCount);
    }
    CGContextStrokePath(ctx);
    CGContextRestoreGState(ctx);
}

- (void)dealloc {
    if (_pattern) {
        free(_pattern);
        _pattern = NULL;
    }

    CGPathRelease(_path);
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (void)setLineWidth:(CGFloat)width {
    _lineWidth = width;
}

/**
 @Status Interoperable
*/
- (CGFloat)lineWidth {
    return _lineWidth;
}

/**
 @Status Interoperable
*/
- (void)setLineJoinStyle:(CGLineJoin)join {
    _lineJoin = join;
}

/**
 @Status Interoperable
*/
- (void)setUsesEvenOddFillRule:(BOOL)usesEvenOdd {
    _usesEvenOddFillRule = usesEvenOdd;
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

    assert(sizeof(float) == sizeof(CGFloat));
    if (count > 0) {
        _pattern = (float*)malloc(sizeof(float) * count);
        memcpy(_pattern, pattern, sizeof(float) * count);
    }
}

@end
