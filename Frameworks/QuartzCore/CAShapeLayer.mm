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

#import <Starboard/SmartTypes.h>
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/CAShapeLayer.h>

NSString* const kCAFillRuleNonZero = @"kCAFillRuleNonZero";
NSString* const kCAFillRuleEvenOdd = @"kCAFillRuleEvenOdd";

NSString* const kCALineJoinMiter = @"kCALineJoinMiter";
NSString* const kCALineJoinRound = @"kCALineJoinRound";
NSString* const kCALineJoinBevel = @"kCALineJoinBevel";

NSString* const kCALineCapButt = @"kCALineCapButt";
NSString* const kCALineCapRound = @"kCALineCapRound";
NSString* const kCALineCapSquare = @"kCALineCapSquare";

@interface CAShapeLayer () {
    woc::StrongCF<CGPathRef> _path;
    woc::StrongCF<CGColorRef> _strokeColor;
    woc::StrongCF<CGColorRef> _fillColor;

    CGPathDrawingMode _fillMode;
    CGLineCap _lineCap;
    float _lineWidth;
}
@end

@implementation CAShapeLayer
- (instancetype)init {
    if (self = [super init]) {
        _fillColor = CGColorGetConstantColor(kCGColorBlack);
        _lineWidth = 1.0f;
        _fillMode = kCGPathFill;
        _lineCap = kCGLineCapButt;
    }

    return self;
}

- (void)drawInContext:(CGContextRef)context {
    if (!_path) {
        return;
    }

    CGPathDrawingMode drawMode = 0;

    if (_strokeColor) {
        CGContextSetStrokeColorWithColor(context, _strokeColor);
        CGContextSetLineWidth(context, _lineWidth);
        drawMode = kCGPathStroke;
    }

    if (_fillColor) {
        CGContextSetFillColorWithColor(context, _fillColor);
        drawMode |= _fillMode;
    }

    if (drawMode) {
        CGContextSetLineCap(context, _lineCap);
        CGContextAddPath(context, _path);
        CGContextDrawPath(context, drawMode);
    }
}

/**
 @Status Interoperable
*/
- (void)setPath:(CGPathRef)path {
    if (_path != path) {
        _path.attach(CGPathCreateCopy(path));

        [self setNeedsDisplay];
    }
}

/**
 @Status Interoperable
*/
- (CGPathRef)path {
    return _path;
}

/**
 @Status Interoperable
*/
- (void)setFillColor:(CGColorRef)color {
    if (_fillColor != color) {
        _fillColor = color;

        [self setNeedsDisplay];
    }
}

/**
 @Status Interoperable
*/
- (CGColorRef)fillColor {
    return _fillColor;
}

/**
 @Status Interoperable
*/
- (void)setStrokeColor:(CGColorRef)color {
    if (_strokeColor != color) {
        _strokeColor = color;

        [self setNeedsDisplay];
    }
}

/**
 @Status Interoperable
*/
- (CGColorRef)strokeColor {
    return _strokeColor;
}

/**
 @Status Interoperable
*/
- (void)setLineWidth:(float)width {
    if (_lineWidth != width) {
        _lineWidth = width;

        [self setNeedsDisplay];
    }
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
- (void)setFillRule:(NSString*)fillRule {
    CGPathDrawingMode newFillMode = kCGPathFill;
    if ([kCAFillRuleEvenOdd isEqual:fillRule]) {
        newFillMode = kCGPathEOFill;
    }

    if (_fillMode != newFillMode) {
        _fillMode = newFillMode;
        [self setNeedsDisplay];
    }
}

/**
 @Status Interoperable
*/
- (NSString*)fillRule {
    return _fillMode == kCGPathFill ? kCAFillRuleNonZero : kCAFillRuleEvenOdd;
}

/**
 @Status Interoperable
*/
- (void)setLineCap:(NSString*)lineCap {
    CGLineCap newLineCap = kCGLineCapButt;
    if ([kCALineCapRound isEqual:lineCap]) {
        newLineCap = kCGLineCapRound;
    } else if ([kCALineCapSquare isEqual:lineCap]) {
        newLineCap = kCGLineCapSquare;
    }

    if (_lineCap != newLineCap) {
        _lineCap = newLineCap;
        [self setNeedsDisplay];
    }
}

/**
 @Status Interoperable
*/
- (NSString*)lineCap {
    return _lineCap == kCGLineCapSquare ? kCALineCapSquare : (_lineCap == kCGLineCapRound ? kCALineCapRound : kCALineCapButt);
}

@end
