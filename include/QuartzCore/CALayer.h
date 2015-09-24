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

#ifndef _CALAYER_H_
#define _CALAYER_H_

#import <Foundation/Foundation.h>
#import <ApplicationServices/ApplicationServices.h>
#import <QuartzCore/CATransform3D.h>
#import <QuartzCore/CAAction.h>
#import <QuartzCore/CAMediaTiming.h>
#import <UIKit/UIColor.h>

@class CAAnimation, CALayerContext;

enum {
    kCALayerNotSizable    = 0x00,
    kCALayerMinXMargin    = 0x01,
    kCALayerWidthSizable  = 0x02,
    kCALayerMaxXMargin    = 0x04,
    kCALayerMinYMargin    = 0x08,
    kCALayerHeightSizable = 0x10,
    kCALayerMaxYMargin    = 0x20,
};

CA_EXPORT NSString *const kCAFilterLinear;
CA_EXPORT NSString *const kCAFilterNearest;
CA_EXPORT NSString *const kCAFilterTrilinear;

CA_EXPORT NSString * const kCAOnOrderIn;
CA_EXPORT NSString * const kCAOnOrderOut;
CA_EXPORT NSString * const kCATransition;

CA_EXPORT NSString * const kCAGravityCenter;
CA_EXPORT NSString * const kCAGravityTop;
CA_EXPORT NSString * const kCAGravityBottom;
CA_EXPORT NSString * const kCAGravityLeft;
CA_EXPORT NSString * const kCAGravityRight;
CA_EXPORT NSString * const kCAGravityTopLeft;
CA_EXPORT NSString * const kCAGravityTopRight;
CA_EXPORT NSString * const kCAGravityBottomLeft;
CA_EXPORT NSString * const kCAGravityBottomRight;
CA_EXPORT NSString * const kCAGravityResize;
CA_EXPORT NSString * const kCAGravityResizeAspect;
CA_EXPORT NSString * const kCAGravityResizeAspectFill;

@class WXFrameworkElement;

#if defined( __cplusplus )
class CAPrivateInfo;
#else
typedef void *CAPrivateInfo;
#endif

CA_EXPORT_CLASS
@interface CALayer : NSObject <NSCoding, CAMediaTiming> {
    @public
    CAPrivateInfo *priv;
}

+ (id)layer;
+ (BOOL)needsDisplayForKey:(NSString *)key;

@property(readonly) CALayer *superlayer;
@property(copy) NSArray *sublayers;
@property(assign) id delegate;
@property CGPoint anchorPoint;
@property CGPoint position;
@property CGRect bounds;
@property CGRect frame;
@property float opacity;
@property BOOL opaque;
@property(retain) id contents;
@property CATransform3D transform;
@property CATransform3D sublayerTransform;
@property CGRect contentsCenter;
@property(copy) NSString *contentsGravity;
@property(copy) NSString *name;
@property BOOL drawsAsynchronously;

@property(copy) NSString *minificationFilter;
@property(copy) NSString *magnificationFilter;
@property CGSize shadowOffset;
@property CGColorRef shadowColor;
@property float shadowOpacity;
@property CGFloat shadowRadius;
@property CGFloat rasterizationScale;
@property BOOL shouldRasterize;
@property CGFloat cornerRadius;
@property BOOL masksToBounds;
@property CGPathRef shadowPath;
@property CGColorRef backgroundColor;
@property (retain) CALayer *mask;
@property (getter=isHidden) BOOL hidden;
@property CGFloat zPosition;
@property BOOL needsDisplayOnBoundsChange;
@property CGColorRef borderColor;
@property CGFloat borderWidth;
@property (readonly) CGRect visibleRect;
@property CGFloat contentsScale;
@property (getter=isDoubleSided) BOOL doubleSided;
@property(copy) NSDictionary *actions;

@property WXFrameworkElement *contentsElement;

- (id)init;
- (id)initWithLayer:(id)layer;

-(void)addSublayer:(CALayer *)layer;
-(void)replaceSublayer:(CALayer *)layer with:(CALayer *)other;
-(void)display;
-(void)displayIfNeeded;
-(void)drawInContext:(CGContextRef)context;
-(BOOL)needsDisplay;
-(void)removeFromSuperlayer;
-(void)setNeedsDisplay;
-(void)setNeedsDisplayInRect:(CGRect)rect;

-(void)addAnimation:(CAAnimation *)animation forKey:(NSString *)key;
-(CAAnimation *)animationForKey:(NSString *)key;
-(void)removeAllAnimations;
-(void)removeAnimationForKey:(NSString *)key;
-(NSArray *)animationKeys;

-(id <CAAction>)actionForKey:(NSString *)key;
-(CGAffineTransform)affineTransform;
-(void)setAffineTransform:(CGAffineTransform)T;
-(CFTimeInterval)convertTime:(CFTimeInterval)timeInterval fromLayer:(CALayer *)layer;
-(void)insertSublayer:(CALayer *)aLayer atIndex:(unsigned)index;
-(void)insertSublayer:(CALayer *)aLayer above:(CALayer *)sublayer;

- (void)renderInContext:(CGContextRef)ctx;

- (CGRect)convertRect:(CGRect)aRect toLayer:(CALayer *)layer;
- (CGRect)convertRect:(CGRect)aRect fromLayer:(CALayer *)layer;
- (CGPoint)convertPoint:(CGPoint)point toLayer:(CALayer *)layer;
- (CGPoint)convertPoint:(CGPoint)point fromLayer:(CALayer *)layer;

- (void)layoutSublayers;
- (BOOL)needsLayout;
- (void)setNeedsLayout;
- (void)layoutIfNeeded;
- (void)insertSublayer:(CALayer *)aLayer below:(CALayer *)sublayer;
- (id)presentationLayer;

+ (CGPoint)convertPoint:(CGPoint)point fromLayer:(CALayer *)layer toLayer:(CALayer *)layer;

@end

@interface NSObject(CALayerDelegate)

-(void)displayLayer:(CALayer *)layer;
-(void)drawLayer:(CALayer *)layer inContext:(CGContextRef)context;

-(id<CAAction>)actionForLayer:(CALayer *)layer forKey:(NSString *)key;

@end

#endif /* _CALAYER_H_ */
