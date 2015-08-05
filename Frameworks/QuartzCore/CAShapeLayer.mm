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
#include "CGGraphicBufferImage.h"
#include "QuartzCore/CAShapeLayer.h"

@implementation CAShapeLayer {
    CGPathRef _path;
    float _lineWidth;
    CGColorRef _strokeColor, _fillColor;

    CGRect curBounds;
    BOOL created;
}
    -(void) setPath:(CGPathRef)path {
        path = [path copy];
        [_path release];
        _path = path;
        [self setNeedsDisplay];

        priv->forceOverrideBounds = TRUE;
        CGRect bbox = CGPathGetBoundingBox(_path);

        bbox.size.width += _lineWidth * 2.0f;
        bbox.size.height += _lineWidth * 2.0f;
        bbox.origin.x -= _lineWidth;
        bbox.origin.y -= _lineWidth;

        if (!created) {
            curBounds = bbox;
            created = true;
        } else {
            if (bbox.size.width > curBounds.size.width)
                curBounds.size.width = bbox.size.width;
            if (bbox.size.height > curBounds.size.height)
                curBounds.size.height = bbox.size.height;
        }

        curBounds.origin.x = bbox.origin.x;
        curBounds.origin.y = bbox.origin.y;

        priv->overrideBounds.origin.x = curBounds.size.width / 2.0f + curBounds.origin.x;
        priv->overrideBounds.origin.y = curBounds.size.height / 2.0f + curBounds.origin.y;
        priv->overrideBounds.size = curBounds.size;

        NSValue *newBoundsValue = [NSValue valueWithCGRect: priv->overrideBounds];
        [CATransaction _setPropertyForLayer: self name: @"overrideBounds" value: newBoundsValue];
    }

    -(CGPathRef) path {
        return _path;
    }

    -(void) setFillColor:(CGColorRef)color {
        CGColorRetain(color);
        CGColorRelease(_fillColor);
        _fillColor = color;
    }

    -(void) setStrokeColor:(CGColorRef)color {
        CGColorRetain(color);
        CGColorRelease(_strokeColor);
        _strokeColor = color;
    }

    -(void) setLineWidth:(float)width {
        if ( _lineWidth == width ) return;

        _lineWidth = width;

        // We need to resize our surface, which is done on path assignment.
        [self setPath:_path];
    }

    /* annotate with type */ -(id) setLineDashPattern:(id)pattern {
        return self;
    }

    /* annotate with type */ -(id) setLineCap:(id)cap {
        return self;
    }

    -(void) setLineJoin:(id)join {
    }

    -(void) setFillRule:(id)rule {
    }

    -(id) init {
        [super init];

        _fillColor = (CGColorRef) CGColorGetConstantColor((CFStringRef) @"BLACK");
        CGColorRetain(_fillColor);
        [self setDelegate:self];
        _lineWidth = 1.0f;

        return self;
    }

    -(void) drawLayer:(id)layer inContext:(CGContextRef)context {
        // I can't decide if it matters where we do the actual shape drawing. Seems drawInContext is
        // as good a place as any...
    }

    -(void) drawInContext:(CGContextRef)context {
        CGContextTranslateCTM(context, -curBounds.origin.x, -curBounds.origin.y);

        [_path _applyPath:context];

        if (_fillColor) {
            CGContextSetFillColorWithColor(context, _fillColor);
            CGContextEOFillPath(context);
        }

        if (_strokeColor) {
            CGContextSetStrokeColorWithColor(context, _strokeColor);
            CGContextSetLineWidth(context, _lineWidth);
            CGContextStrokePath(context);
        }
    }

    -(void) dealloc{
        CGPathRelease(_path);
        _path = nil;
        CGColorRelease(_strokeColor);
        _strokeColor = nil;
        CGColorRelease(_fillColor);
        _fillColor = nil;
    }
    
@end

