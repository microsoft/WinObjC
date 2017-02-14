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
#pragma once

#import <QuartzCore/CoreAnimationExport.h>
#import <Foundation/Foundation.h>
#import <ApplicationServices/ApplicationServices.h>
#import <QuartzCore/CATransform3D.h>
#import <QuartzCore/CAAction.h>
#import <QuartzCore/CAMediaTiming.h>

@class CAAnimation, CALayerContext;

typedef enum {
    kCALayerLeftEdge = 1U << 0,
    kCALayerRightEdge = 1U << 1,
    kCALayerBottomEdge = 1U << 2,
    kCALayerTopEdge = 1U << 3,
} CAEdgeAntialiasingMask;

enum {
    kCALayerNotSizable = 0x00,
    kCALayerMinXMargin = 0x01,
    kCALayerWidthSizable = 0x02,
    kCALayerMaxXMargin = 0x04,
    kCALayerMinYMargin = 0x08,
    kCALayerHeightSizable = 0x10,
    kCALayerMaxYMargin = 0x20,
};

CA_EXPORT NSString* const kCAOnOrderIn;
CA_EXPORT NSString* const kCAOnOrderOut;
CA_EXPORT NSString* const kCATransition;

CA_EXPORT NSString* const kCAGravityCenter;
CA_EXPORT NSString* const kCAGravityTop;
CA_EXPORT NSString* const kCAGravityBottom;
CA_EXPORT NSString* const kCAGravityLeft;
CA_EXPORT NSString* const kCAGravityRight;
CA_EXPORT NSString* const kCAGravityTopLeft;
CA_EXPORT NSString* const kCAGravityTopRight;
CA_EXPORT NSString* const kCAGravityBottomLeft;
CA_EXPORT NSString* const kCAGravityBottomRight;
CA_EXPORT NSString* const kCAGravityResize;
CA_EXPORT NSString* const kCAGravityResizeAspect;
CA_EXPORT NSString* const kCAGravityResizeAspectFill;
// CA_EXPORT const CATransform3D CATransform3DIdentity; -- See CATransform3D.h
CA_EXPORT NSString* const kCAFilterLinear;
CA_EXPORT NSString* const kCAFilterNearest;
CA_EXPORT NSString* const kCAFilterTrilinear;

@class WXFrameworkElement;

CA_EXPORT_CLASS
@interface CALayer : NSObject <NSCoding, CAMediaTiming> {
}

// Creation
+ (instancetype)layer;
- (instancetype)init;
- (instancetype)initWithLayer:(id)layer;

// Layer-related objects
- (id)presentationLayer STUB_METHOD;
- (id)modelLayer STUB_METHOD;

// Delegates
@property (assign) id delegate;

// Content
@property (retain) id contents;
@property CGRect contentsRect;
@property CGRect contentsCenter;
- (void)display;
- (void)drawInContext:(CGContextRef)ctx;

// Appearance
@property (copy) NSString* contentsGravity;
@property float opacity;
@property (getter=isHidden) BOOL hidden;
@property BOOL masksToBounds;
@property (retain) CALayer* mask STUB_PROPERTY;
@property (getter=isDoubleSided) BOOL doubleSided STUB_PROPERTY;
@property CGFloat cornerRadius STUB_PROPERTY;
@property CGFloat borderWidth;
@property CGColorRef borderColor;
@property CGColorRef backgroundColor;
@property float shadowOpacity STUB_PROPERTY;
@property CGFloat shadowRadius STUB_PROPERTY;
@property CGSize shadowOffset STUB_PROPERTY;
@property CGColorRef shadowColor STUB_PROPERTY;
@property CGPathRef shadowPath STUB_PROPERTY;
@property (copy) NSDictionary* style STUB_PROPERTY;
@property BOOL allowsEdgeAntialiasing STUB_PROPERTY;
@property BOOL allowsGroupOpacity STUB_PROPERTY;

// Filters
@property (copy) NSArray* filters STUB_PROPERTY;
@property (strong) id compositingFilter STUB_PROPERTY;
@property (copy) NSArray* backgroundFilters STUB_PROPERTY;
@property (copy) NSString* minificationFilter STUB_PROPERTY;
@property float minificationFilterBias STUB_PROPERTY;
@property (copy) NSString* magnificationFilter STUB_PROPERTY;

// Rendering
@property (getter=isOpaque) BOOL opaque;
@property CAEdgeAntialiasingMask edgeAntialiasingMask STUB_PROPERTY;
- (BOOL)contentsAreFlipped STUB_METHOD;
@property (getter=isGeometryFlipped) BOOL geometryFlipped STUB_PROPERTY;
@property BOOL drawsAsynchronously STUB_PROPERTY;
@property BOOL shouldRasterize;
@property CGFloat rasterizationScale STUB_PROPERTY;
- (void)renderInContext:(CGContextRef)ctx;

// Geometry
@property CGRect frame;
@property CGRect bounds;
@property CGPoint position;
@property CGFloat zPosition STUB_PROPERTY;
@property CGFloat anchorPointZ STUB_PROPERTY;
@property CGPoint anchorPoint;
@property CGFloat contentsScale;

@property CATransform3D transform;
@property CATransform3D sublayerTransform STUB_PROPERTY;
- (CGAffineTransform)affineTransform;
- (void)setAffineTransform:(CGAffineTransform)m;

@property (copy) NSArray* sublayers;
@property (readonly) CALayer* superlayer;
- (void)addSublayer:(CALayer*)aLayer;
- (void)removeFromSuperlayer;
- (void)insertSublayer:(CALayer*)aLayer atIndex:(unsigned int)index;
- (void)insertSublayer:(CALayer*)aLayer below:(CALayer*)sublayer;
- (void)insertSublayer:(CALayer*)aLayer above:(CALayer*)sublayer;
- (void)replaceSublayer:(CALayer*)oldLayer with:(CALayer*)newLayer;

- (void)setNeedsDisplay;
- (void)setNeedsDisplayInRect:(CGRect)theRect;
@property BOOL needsDisplayOnBoundsChange;
- (void)displayIfNeeded;
- (BOOL)needsDisplay;
+ (BOOL)needsDisplayForKey:(NSString*)key;

- (void)addAnimation:(CAAnimation*)anim forKey:(NSString*)key;
- (CAAnimation*)animationForKey:(NSString*)key;
- (void)removeAllAnimations;
- (void)removeAnimationForKey:(NSString*)key;
- (NSArray*)animationKeys;

- (void)setNeedsLayout;
- (void)layoutSublayers;
- (void)layoutIfNeeded;
- (BOOL)needsLayout;
- (CGSize)preferredFrameSize STUB_METHOD;

- (id<CAAction>)actionForKey:(NSString*)key;
@property (copy) NSDictionary* actions;
+ (id<CAAction>)defaultActionForKey:(NSString*)key;

- (CGPoint)convertPoint:(CGPoint)aPoint fromLayer:(CALayer*)layer;
- (CGPoint)convertPoint:(CGPoint)aPoint toLayer:(CALayer*)layer;
- (CGRect)convertRect:(CGRect)aRect fromLayer:(CALayer*)layer;
- (CGRect)convertRect:(CGRect)aRect toLayer:(CALayer*)layer;
- (CFTimeInterval)convertTime:(CFTimeInterval)timeInterval fromLayer:(CALayer*)layer STUB_METHOD;
- (CFTimeInterval)convertTime:(CFTimeInterval)timeInterval toLayer:(CALayer*)layer STUB_METHOD;

- (CALayer*)hitTest:(CGPoint)thePoint;
- (BOOL)containsPoint:(CGPoint)thePoint;

@property (readonly) CGRect visibleRect STUB_METHOD;
- (void)scrollPoint:(CGPoint)thePoint STUB_METHOD;
- (void)scrollRectToVisible:(CGRect)theRect STUB_METHOD;

@property (copy) NSString* name;

- (BOOL)shouldArchiveValueForKey:(NSString*)key STUB_METHOD;
+ (id)defaultValueForKey:(NSString*)key STUB_METHOD;

// CAMediaTiming
@property BOOL autoreverses STUB_PROPERTY;
@property CFTimeInterval beginTime STUB_PROPERTY;
@property CFTimeInterval duration STUB_PROPERTY;
@property (copy) NSString* fillMode STUB_PROPERTY;
@property float repeatCount STUB_PROPERTY;
@property CFTimeInterval repeatDuration STUB_PROPERTY;
@property float speed STUB_PROPERTY;
@property CFTimeInterval timeOffset STUB_PROPERTY;

@end
