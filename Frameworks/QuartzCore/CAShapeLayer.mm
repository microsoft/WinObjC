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

#include "Starboard.h"
#include "QuartzCore/CALayer.h"
#include "CALayerInternal.h"
#include "CoreGraphics/CGContext.h"
#include "Foundation/NSString.h"
#include "CoreGraphics/CGPath.h"
#include "CoreGraphics/CGImage.h"
#include "CGPathInternal.h"
#include "CGContextInternal.h"
#include "CGGraphicBufferImage.h"
#include "QuartzCore/CAShapeLayer.h"

CGContextRef CreateLayerContentsBitmapContext32(int width, int height);

@implementation CAShapeLayer {
    CGPathRef _path;
    float _lineWidth;
    CGColorRef _strokeColor, _fillColor;
    CALayer* _shapeImage;
    BOOL _needsRender;
}
- (id<CAAction>)actionForLayer:(CALayer*)layer forKey:(NSString*)key {
    if (layer == _shapeImage) {
        //  We do not want any animations on our shape bitmap sublayer
        return (id<CAAction>)[NSNull null];
    }

    return nil;
}

//  Performed in layoutSublayers because we need to reposition _shapeImage
- (void)layoutSublayers {
    if (_needsRender == NO) {
        return;
    }

    if (_path == nil) {
        _shapeImage.contents = nil;
        return;
    }

    CGRect bbox = CGPathGetBoundingBox(_path);
    if (bbox.size.width == 0 || bbox.size.height == 0) {
        _shapeImage.contents = nil;
        return;
    }

    bbox.size.width += _lineWidth * 2.0f;
    bbox.size.height += _lineWidth * 2.0f;
    bbox.origin.x -= _lineWidth;
    bbox.origin.y -= _lineWidth;

    bbox = CGRectStandardize(bbox);
    bbox = CGRectIntegral(bbox);

    float scale = _shapeImage.contentsScale;
    int width = (int)(bbox.size.width * scale);
    int height = (int)(bbox.size.height * scale);

    CGContextRef drawContext = CreateLayerContentsBitmapContext32(width, height);

    CGContextTranslateCTM(drawContext, 0, height);
    if (scale != 1.0f) {
        CGContextScaleCTM(drawContext, scale, scale);
    }

    CGContextScaleCTM(drawContext, 1.0f, -1.0f);
    CGContextTranslateCTM(drawContext, -bbox.origin.x, -bbox.origin.y);

    _shapeImage.position = bbox.origin;

    CGContextAddPath(drawContext, _path);

    if (_fillColor) {
        CGContextSetFillColorWithColor(drawContext, _fillColor);
        CGContextEOFillPath(drawContext);
    }

    if (_strokeColor) {
        CGContextSetStrokeColorWithColor(drawContext, _strokeColor);
        CGContextSetLineWidth(drawContext, _lineWidth);
        CGContextStrokePath(drawContext);
    }

    CGImageRef target = CGBitmapContextGetImage(drawContext);

    _shapeImage.contents = (id)target;

    CGContextRelease(drawContext);
}

- (void)setPath:(CGPathRef)path {
    if (_path == path) {
        return;
    }

    path = [path copy];
    [_path release];
    _path = path;
    _needsRender = TRUE;
    [self setNeedsLayout];
}

- (CGPathRef)path {
    return _path;
}

- (void)setFillColor:(CGColorRef)color {
    if (_fillColor == color) {
        return;
    }

    CGColorRetain(color);
    CGColorRelease(_fillColor);
    _fillColor = color;

    _needsRender = TRUE;
    [self setNeedsLayout];
}

- (CGColorRef)fillColor {
    return _fillColor;
}

- (void)setStrokeColor:(CGColorRef)color {
    if (_strokeColor == color) {
        return;
    }

    CGColorRetain(color);
    CGColorRelease(_strokeColor);
    _strokeColor = color;

    _needsRender = TRUE;
    [self setNeedsDisplay];
}

- (CGColorRef)strokeColor {
    return _strokeColor;
}

- (void)setLineWidth:(float)width {
    if (_lineWidth == width) {
        return;
    }

    _lineWidth = width;

    _needsRender = TRUE;
    [self setNeedsLayout];
}

- (CGFloat)lineWidth {
    return _lineWidth;
}

- (void)setLineDashPattern:(id)pattern {
}

- (void)setLineCap:(NSString*)cap {
}

- (void)setLineJoin:(id)join {
}

- (void)setFillRule:(id)rule {
}

- (instancetype)init {
    [super init];

    _shapeImage = [CALayer new];
    _shapeImage.anchorPoint = CGPointMake(0.0f, 0.0f);
    _shapeImage.contentsGravity = kCAGravityBottomLeft;
    _shapeImage.contentsScale = self.contentsScale;
    _shapeImage.delegate = self;

    [self addSublayer:_shapeImage];
    _fillColor = (CGColorRef)CGColorGetConstantColor((CFStringRef) @"BLACK");
    CGColorRetain(_fillColor);
    _lineWidth = 1.0f;

    return self;
}

- (void)setContentsScale:(float)scale {
    [super setContentsScale:scale];
    [_shapeImage setContentsScale:scale];
}

- (void)dealloc {
    CGPathRelease(_path);
    _path = nil;
    CGColorRelease(_strokeColor);
    _strokeColor = nil;
    CGColorRelease(_fillColor);
    _fillColor = nil;
    [_shapeImage release];
    _shapeImage = nil;

    [super dealloc];
}
@end
