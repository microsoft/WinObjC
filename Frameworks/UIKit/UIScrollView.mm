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
#include "CoreGraphics/CGAffineTransform.h"
#include "Foundation/NSRunLoop.h"
#include "Foundation/NSString.h"
#include "UIKit/UIApplication.h"
#include "Foundation/NSSet.h"
#include "UIKit/UITouch.h"
#include "UIKit/UIEvent.h"
#include "CoreGraphics/CGGeometry.h"
#include "QuartzCore/CADisplayLink.h"
#include "UIKit/UIGestureRecognizer.h"
#include "UIKit/UIPanGestureRecognizer.h"
#include "QuartzCore/CALayer.h"
#include "UIKit/UIColor.h"
#include "QuartzCore/CABasicAnimation.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSTimer.h"

#include <cmath>

@interface __UIScrollerPosition : CALayer {
@public
    idretaintype(CAAnimation) _fadeAnimation;
}
@end

#include "UIKit/UIScrollView.h"

@implementation __UIScrollerPosition : CALayer

- (instancetype)init {
    [super init];

    [self setBackgroundColor:[[UIColor darkGrayColor] CGColor]];
    [self setOpacity:0.8f];

    return self;
}

- (void)_fadeEnded:(id)animation {
    if (_fadeAnimation != nil) {
        [self removeFromSuperlayer];
        _fadeAnimation = nil;
    }
}

- (void)_show {
    if (_fadeAnimation != nil) {
        _fadeAnimation = nil;
        [self removeAllAnimations];
    }
}

- (void)_hide {
    _fadeAnimation = [CABasicAnimation animationWithKeyPath:@"opacity"];
    [_fadeAnimation setFromValue:[NSNumber numberWithFloat:0.8f]];
    [_fadeAnimation setToValue:[NSNumber numberWithFloat:0.0f]];
    [_fadeAnimation setDuration:0.5f];
    [_fadeAnimation setTimingFunction:[CAMediaTimingFunction functionWithName:@"kCAMediaTimingFunctionLinear"]];
    [_fadeAnimation setDelegate:self];
    [_fadeAnimation _setFinishedSelector:@selector(_fadeEnded:)];
    [self addAnimation:_fadeAnimation forKey:@"HideScrollbar"];
}

- (id<CAAction>)actionForKey:(NSString*)key {
    return nil;
}

@end

#include "Etc.h"

@implementation UIScrollView : UIView {
    id _delegate;
    id _pressTimer;
    idretain _savedTouch, _savedEvent;
    idretain _zoomView;
    CGPoint _lastTouchPos;
    double _lastTouchTime;

    BOOL _showsVerticalScrollIndicator;
    idretain _verticalScroller;
    bool _shouldShowScroller;
    bool _scrollerVisible;

    CGPoint _panStart;

    CGPoint _contentOffset;
    CGSize _contentSize;
    UIEdgeInsets _contentInset;
    UIEdgeInsets _scrollIndicatorInsets;
    BOOL _isDragging;
    BOOL _pagingEnabled;
    BOOL _bounces;
    BOOL _alwaysBounceVertical;
    BOOL _alwaysBounceHorizontal;
    BOOL _canCancelContentTouches;
    BOOL _delaysContentTouches;
    BOOL _scrollEnabled;
    BOOL _forwardingTouch;
    BOOL _forwardsToSuperview;
    BOOL _scrollAnimation;
    bool _cancellableAnim;

    BOOL _sendingScrollEvent;

    float _zoomScale, _maximumZoomScale, _minimumZoomScale;
    float _savedZoomDistance, _savedZoomScale;
    CGRect _originalZoomRect;

    bool _xStuck, _yStuck;

    idretain _panGesture, _pinchGesture;

    float _enterPos, _enterDir;

    BOOL _isZooming, _isZoomingToRect;
    bool _lockVertical, _lockHorizontal;

    enum AnimationReason { ANIMATION_DECELERATING, ANIMATION_DECELERATING_TARGET, ANIMATION_BOUNCING, ANIMATION_PAGING, ANIMATION_USER };

    enum AnimationReason _animationReason;

    idretain _displayLink;

    double _scrollStartTime;
    int _scrollFrame;
    CGPoint _scrollVelocity, _scrollPosition;
    CGPoint _scrollDirection;

    CGPoint _scrollAnimStart, _scrollAnimDest;
    double _scrollAnimStartTime, _scrollAnimDecaySpeed;
}

static void commonInit(UIScrollView* self) {
    // Set up our defaults:
    self->_bounces = TRUE;
    self->_scrollEnabled = TRUE;
    self->_showsVerticalScrollIndicator = TRUE;
    self->_zoomScale = self->_maximumZoomScale = self->_minimumZoomScale = 1.0f;
    self->_alwaysBounceVertical = self->_alwaysBounceHorizontal = false;

    [self setMultipleTouchEnabled:TRUE];

    self->_pinchGesture.attach([[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(_didPinch:)]);
    [self->_pinchGesture setDelegate:self];
    [self addGestureRecognizer:self->_pinchGesture];

    self->_panGesture.attach([[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(_panGestureCallback:)]);
    [self->_panGesture setDelegate:self];
    [self addGestureRecognizer:self->_panGesture];
}

static void commonPostInit(UIScrollView* self) {
    self->_verticalScroller.attach([__UIScrollerPosition new]);
}

static void showScrollersAction(UIScrollView* self) {
    self->_shouldShowScroller = true;
}

static void hideScrollersAction(UIScrollView* self) {
    self->_shouldShowScroller = false;
    positionScrollers(self);
}

static void positionScrollers(UIScrollView* self) {
    if (self->_shouldShowScroller && self->_showsVerticalScrollIndicator) {
        if (!self->_scrollerVisible) {
            [[self layer] addSublayer:self->_verticalScroller];
            [self->_verticalScroller _show];
            self->_scrollerVisible = true;
        }
    } else {
        if (self->_scrollerVisible) {
            [self->_verticalScroller _hide];
            self->_scrollerVisible = false;
        }
    }

    if (self->_scrollerVisible) {
        CGPoint verticalPos = { 0, 0 };
        CGRect verticalSize = { 0, 0, 6, 100 };
        CGRect bounds;

        bounds = [self bounds];

        float scrollStart = self->_contentOffset.y;
        float scrollEnd = self->_contentOffset.y + bounds.size.height;

        const float margin = 6.0f;
        const float halfmargin = margin / 2.0f;

        float scaledHeight = 0.0f, scaledStart = margin;
        if (self->_contentSize.height > 0.0f) {
            scaledStart = scrollStart * (bounds.size.height - margin) / self->_contentSize.height;
            float scaledEnd = scrollEnd * (bounds.size.height - margin) / self->_contentSize.height;

            if (scaledStart < halfmargin) {
                scaledStart = halfmargin;
            }
            if (scaledEnd > bounds.size.height - halfmargin) {
                scaledEnd = bounds.size.height - halfmargin;
            }
            scaledHeight = scaledEnd - scaledStart;
            verticalSize.size.height = scaledHeight;
        }

        verticalPos.x = (bounds.origin.x + bounds.size.width - 8.0f) + verticalSize.size.width / 2.0f;
        verticalPos.y = (bounds.origin.y + scaledStart) + verticalSize.size.height / 2.0f;

        [self->_verticalScroller setPosition:verticalPos];
        [self->_verticalScroller setBounds:verticalSize];
        [[self layer] bringSublayerToFront:(id)self->_verticalScroller];
    }
}

- (id)initWithCoder:(NSCoder*)coder {
    commonInit(self);

    [super initWithCoder:coder];
    if ([coder containsValueForKey:@"UIDelaysContentTouches"]) {
        _delaysContentTouches = [coder decodeBoolForKey:@"UIDelaysContentTouches"];
    } else {
        _delaysContentTouches = TRUE;
    }
    _pagingEnabled = [coder decodeBoolForKey:@"UIPagingEnabled"];

    if ([coder containsValueForKey:@"UIBounces"]) {
        _bounces = [coder decodeBoolForKey:@"UIBounces"];
    }
    if ([coder containsValueForKey:@"UIAlwaysBounceVertically"]) {
        _alwaysBounceVertical = [coder decodeBoolForKey:@"UIAlwaysBounceVertical"];
    }
    if ([coder containsValueForKey:@"UIAlwaysBounceHorizontally"]) {
        _alwaysBounceHorizontal = [coder decodeBoolForKey:@"UIAlwaysBounceHorizontal"];
    }
    if ([coder containsValueForKey:@"UIScrollDisabled"]) {
        _scrollEnabled = [coder decodeBoolForKey:@"UIScrollDisabled"] == 0;
    }
    if ([coder containsValueForKey:@"UIShowsVerticalScrollIndicator"]) {
        _showsVerticalScrollIndicator = [coder decodeBoolForKey:@"UIShowsVerticalScrollIndicator"] == 0;
    }

    CGRect bounds;
    bounds = [self bounds];
    _contentSize = bounds.size;

    if ([coder containsValueForKey:@"UIContentInset"]) {
        id obj = [coder decodeObjectForKey:@"UIContentInset"];
        UIEdgeInsets inset = { 0 };
        if ([obj isKindOfClass:[NSString class]]) {
            const char* str = [obj UTF8String];
            sscanf_s(str, "{%f, %f, %f, %f}", &inset.top, &inset.left, &inset.bottom, &inset.right);
        } else {
            CGRect* pRect = (CGRect*)((char*)[obj bytes]) + 1;
            memcpy(&inset, pRect, sizeof(CGRect));
        }
        [self setContentInset:inset];
    }
    commonPostInit(self);

    return self;
}

- (instancetype)initWithFrame:(CGRect)pos {
    [super initWithFrame:pos];
    [self setClipsToBounds:1];
    [self setDelaysContentTouches:1];

    commonInit(self);
    commonPostInit(self);

    return self;
}

/**
 @Status Interoperable
*/
- (void)setScrollEnabled:(BOOL)enable {
    _scrollEnabled = enable;
}

/**
 @Status Interoperable
*/
- (BOOL)isScrollEnabled {
    return _scrollEnabled;
}

/**
 @Status Interoperable
*/
- (void)setPagingEnabled:(BOOL)enable {
    _pagingEnabled = enable;
}

/**
 @Status Interoperable
*/
- (void)setBounces:(BOOL)enable {
    _bounces = enable;
}

/**
 @Status Interoperable
*/
- (BOOL)bounces {
    return _bounces;
}

/**
 @Status Interoperable
*/
- (void)setAlwaysBounceVertical:(BOOL)enable {
    _alwaysBounceVertical = enable;
}

/**
 @Status Interoperable
*/
- (BOOL)alwaysBounceVertical {
    return _alwaysBounceVertical;
}

/**
 @Status Interoperable
*/
- (void)setAlwaysBounceHorizontal:(BOOL)enable {
    _alwaysBounceHorizontal = enable;
}

/**
 @Status Stub
*/
- (void)setDelaysContentTouches:(BOOL)delay {
    UNIMPLEMENTED();
    _delaysContentTouches = delay;
}

/**
 @Status Interoperable
*/
- (void)setContentSize:(CGSize)size {
    if (_contentSize.width != size.width || _contentSize.height != size.height) {
        _contentSize = size;
        if (_displayLink == nil || _animationReason != ANIMATION_USER) {
            [self setContentOffset:_contentOffset];
        }
        [self setNeedsLayout];
    }
}

/**
 @Status Interoperable
*/
- (CGSize)contentSize {
    return _contentSize;
}

/**
 @Status Interoperable
*/
- (CGPoint)contentOffset {
    return _contentOffset;
}

/**
 @Status Interoperable
*/
- (void)setContentOffset:(CGPoint)offset {
    [self setContentOffset:offset animated:NO];
}

static bool bounceClamp(float& val, float min, float max) {
    bool ret = false;
    if (val < min) {
        val = min - (min - val) / 2.0f;
        ret = true;
    }
    if (val > max) {
        val = (val - max) / 2.0f + max;
        ret = true;
    }

    return ret;
}

static void addPointWithBounce(UIScrollView* self, CGPoint& p, float amtX, float amtY) {
    CGRect bounds;
    bounds = [self bounds];

    bool bounceVertical = false;
    bool bounceHorizontal = false;
    if (self->_contentSize.width > bounds.size.width || self->_alwaysBounceHorizontal) {
        bounceHorizontal = true;
    }
    if (self->_contentSize.height > bounds.size.height || self->_alwaysBounceVertical) {
        bounceVertical = true;
    }

    if (p.x + amtX < findMinX(self)) {
        if (p.x > findMinX(self)) {
            amtX += p.x - findMinX(self);
            p.x = findMinX(self);
        }

        p.x += amtX / 2.0f;
    } else if (p.x + amtX > findMaxX(self)) {
        if (p.x < findMaxX(self)) {
            amtX -= (findMaxX(self)) - p.x;
            p.x = findMaxX(self);
        }

        p.x += amtX / 2.0f;
    } else {
        p.x += amtX;
    }

    if (p.y + amtY < findMinY(self)) {
        if (p.y > findMinY(self)) {
            amtY += p.y - findMinY(self);
            p.y = findMinY(self);
        }

        p.y += amtY / 2.0f;
    } else if (p.y + amtY > findMaxY(self)) {
        if (p.y < findMaxY(self)) {
            amtY -= findMaxY(self) - p.y;
            p.y = findMaxY(self);
        }

        p.y += amtY / 2.0f;
    } else {
        p.y += amtY;
    }
}

static void clipPoint(UIScrollView* o, CGPoint& p, bool bounce = true) {
    CGRect bounds;
    bounds = [o bounds];

    bool bounceVertical = false;
    bool bounceHorizontal = false;

    if (bounce) {
        if (o->_contentSize.width > bounds.size.width || o->_alwaysBounceHorizontal) {
            bounceHorizontal = true;
        }
        if (o->_contentSize.height > bounds.size.height || o->_alwaysBounceVertical) {
            bounceVertical = true;
        }
    }

    if (!bounceHorizontal) {
        clamp((float&)p.x, findMinX(o), max(findMaxX(o), findMinX(o)));
    }
    if (!bounceVertical) {
        clamp((float&)p.y, findMinY(o), max(findMaxY(o), findMinY(o)));
    }
}

- (void)_refreshOrigin {
    CGPoint boundsVal = _contentOffset;

    boundsVal.y = boundsVal.y;

    [self setBoundsOrigin:boundsVal];
    positionScrollers(self);
    [self setNeedsLayout];

    if (!_sendingScrollEvent) {
        //_sendingScrollEvent = TRUE;
        if ([_delegate respondsToSelector:@selector(scrollViewDidScroll:)]) {
            [_delegate scrollViewDidScroll:self];
        }
        //_sendingScrollEvent = FALSE;
    }
}

static void changeContentOffset(UIScrollView* self, CGPoint offset, BOOL animated, bool kvo = true) {
    if (animated == NO) {
        if (self->_contentOffset != offset) {
            if (kvo) {
                setContentOffsetKVOed(self, offset);
            } else {
                self->_contentOffset = offset;
            }
            [self _refreshOrigin];
        }
    } else {
        doAnimatedScroll(self, offset, ANIMATION_USER);
    }
}

/**
 @Status Interoperable
*/
- (void)setContentOffset:(CGPoint)offset animated:(BOOL)animated {
    if (offset != _contentOffset) {
        abortGestures(self);

        // Stop scrolling:
        if (_displayLink != nil) {
            hideScrollersAction(self);
            if (_animationReason == ANIMATION_USER) {
                if ([self.delegate respondsToSelector:@selector(scrollViewDidEndScrollingAnimation:)]) {
                    [self.delegate scrollViewDidEndScrollingAnimation:self];
                }
            }
        }
        [_displayLink invalidate];
        _displayLink = nil;

        changeContentOffset(self, offset, animated, false);
    }
}

/**
 @Status Stub
*/
- (void)setShowsHorizontalScrollIndicator:(BOOL)show {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)setShowsVerticalScrollIndicator:(BOOL)show {
    _showsVerticalScrollIndicator = show;
}

/**
 @Status Stub
*/
- (void)setScrollsToTop:(BOOL)scrollsToTop {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)setDelegate:(id)delegate {
    _delegate = delegate;
}

/**
 @Status Interoperable
*/
- (id)delegate {
    return _delegate;
}

/**
 @Status Interoperable
*/
- (void)scrollRectToVisible:(CGRect)rect animated:(BOOL)animated {
    CGRect contentRect = { 0, 0, _contentSize.width, _contentSize.height };
    CGRect visibleRect = { 0 };

    visibleRect = [self bounds];
    CGRect goalRect;

    goalRect = CGRectIntersection(rect, contentRect);

    if (!CGRectIsNull(goalRect) && !CGRectContainsRect(visibleRect, goalRect)) {
        goalRect.size.width = min(goalRect.size.width, visibleRect.size.width);
        goalRect.size.height = min(goalRect.size.height, visibleRect.size.height);

        CGPoint offset = _contentOffset;

        if (CGRectGetMaxY(goalRect) > CGRectGetMaxY(visibleRect)) {
            offset.y += CGRectGetMaxY(goalRect) - CGRectGetMaxY(visibleRect);
        } else if (CGRectGetMinY(goalRect) < CGRectGetMinY(visibleRect)) {
            offset.y += CGRectGetMinY(goalRect) - CGRectGetMinY(visibleRect);
        }

        if (CGRectGetMaxX(goalRect) > CGRectGetMaxX(visibleRect)) {
            offset.x += CGRectGetMaxX(goalRect) - CGRectGetMaxX(visibleRect);
        } else if (CGRectGetMinX(goalRect) < CGRectGetMinX(visibleRect)) {
            offset.x += CGRectGetMinX(goalRect) - CGRectGetMinX(visibleRect);
        }

        if (offset.x > findMaxX(self)) {
            offset.x = findMaxX(self);
        }
        if (offset.x < findMinX(self)) {
            offset.x = findMinX(self);
        }
        if (offset.y > findMaxY(self)) {
            offset.y = findMaxY(self);
        }
        if (offset.y < findMinY(self)) {
            offset.y = findMinY(self);
        }

        [self setContentOffset:offset animated:animated];
    }
}

- (void)touchesMoved:(id)touches withEvent:(id)event {
}

#define returntobaseconst 7.0f
#define bouncedecelerationconst 15000.0f
#define animationtimestep (1.0f / 60.0f)
#define decelerationconst 1300.0f

static bool applyAnimationToDimension(float& position, float& velocity, float decayCoefficient, float min, float max) {
    bool ret = false;

    if (position < min) {
        // If reach the top bound, bounce back
        if (velocity >= 0.0f) {
            // Return to 0 position
            velocity = returntobaseconst * fabs(min - position);
            if (velocity < 0.5f) {
                velocity = 0.0f;
            }
        } else {
            // Slow down in order to turn around
            if (velocity < -1000.0f) {
                velocity = -1000.0f;
            }
            float change = bouncedecelerationconst * animationtimestep;
            velocity += change;
        }
        ret = true;
    } else if (position > max) {
        // If reach bottom bound, bounce back
        if (velocity <= 0.0f) {
            // Return to bottom position
            velocity = -1.0f * returntobaseconst * fabs(position - max);
            if (velocity > -0.5f) {
                velocity = 0.0f;
            }
        } else {
            // Slow down
            if (velocity > 1000.0f) {
                velocity = 1000.0f;
            }
            float change = bouncedecelerationconst * animationtimestep;
            velocity -= change;
        }
        ret = true;
    } else {
        // Free scrolling. Decelerate gradually.
        float changevelocity = decelerationconst * animationtimestep;
        if (changevelocity > fabs(velocity)) {
            velocity = 0;
        } else {
            velocity -= (velocity > 0 ? decayCoefficient : -decayCoefficient) * changevelocity;
        }
    }

    return ret;
}

static CGPoint calcInertialDestination(UIScrollView* o, CGPoint start, CGPoint velocity) {
    CGPoint position = start;
    int i = 0;

    CGPoint direction = velocity / velocity.len();
    //  For safety's sake
    for (i = 0; i < 1000; i++) {
        applyAnimationToDimension(position.x, velocity.x, fabs(direction.x), findMinX(o), findMaxX(o));
        applyAnimationToDimension(position.y, velocity.y, fabs(direction.y), findMinY(o), findMaxY(o));

        if (fabs(velocity.y) == 0.0f && fabs(velocity.x) == 0.0f) {
            break;
        }

        position.x += velocity.x * animationtimestep;
        position.y += velocity.y * animationtimestep;
    }

    return position;
}

static void stopScrollAnimations(UIScrollView* self) {
    if (self->_displayLink != nil) {
        hideScrollersAction(self);
    }

    [self->_displayLink invalidate];
    self->_displayLink = nil;
}

- (void)_inertialAnimTimer {
    //  Skip frames as needed
    double curTime = EbrGetMediaTime();
    double elapsed = curTime - _scrollStartTime;

    elapsed -= animationtimestep / 2.0; //  Allow 1/2 frame leeway
    if (elapsed < 0) {
        elapsed = 0;
    }

    int curFrame = (int)(elapsed / animationtimestep);
    int doFrames = (curFrame + 1) - _scrollFrame;

    // This code used to set doFrames to 1 instead of doing nothing but this makes
    // us do the dragging animations prematurely. In particular, on my desktop it caused
    // any kind of animation snapping to be instanteous and look very jerky.
    if (doFrames <= 0) {
        return;
    }

    while (doFrames--) {
        if (applyAnimationToDimension(_scrollPosition.x, _scrollVelocity.x, fabs(_scrollDirection.x), findMinX(self), findMaxX(self))) {
            _animationReason = ANIMATION_BOUNCING;
        }

        if (applyAnimationToDimension(_scrollPosition.y, _scrollVelocity.y, fabs(_scrollDirection.y), findMinY(self), findMaxY(self))) {
            _animationReason = ANIMATION_BOUNCING;
        }

        if (fabs(_scrollVelocity.y) == 0.0f && fabs(_scrollVelocity.x) == 0.0f) {
            changeContentOffset(self, _scrollPosition, FALSE);

            hideScrollersAction(self);
            [_displayLink invalidate];
            _displayLink = nil;
            if ([_delegate respondsToSelector:@selector(scrollViewDidEndDecelerating:)]) {
                [_delegate scrollViewDidEndDecelerating:self];
            }
            return;
        }

        _scrollPosition.x += _scrollVelocity.x * animationtimestep;
        _scrollPosition.y += _scrollVelocity.y * animationtimestep;
        _scrollFrame++;
    }

    changeContentOffset(self, _scrollPosition, FALSE);
}

static void doInertialScroll(UIScrollView* self, CGPoint velocity, AnimationReason reason) {
    self->_animationReason = reason;
    self->_scrollVelocity = velocity;
    self->_scrollPosition = self->_contentOffset;

    // We'll get a bunch of NaNs if we don't handle the case where we have zero velocity.
    // Note that this only blows up in some circumstances (the scroll direction is not always
    // used).
    float len = self->_scrollVelocity.len();
    if (fabs(len) < 0.01f) {
        self->_scrollDirection.x = self->_scrollDirection.y = 0.f;
    } else {
        self->_scrollDirection = self->_scrollVelocity / self->_scrollVelocity.len();
    }

    self->_scrollStartTime = EbrGetMediaTime();
    self->_scrollFrame = 0;

    [self->_displayLink invalidate];

    self->_displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(_inertialAnimTimer)];
    [self->_displayLink addToRunLoop:[NSRunLoop mainRunLoop] forMode:@"kCFRunLoopDefaultMode"];
}

static void animMoveTo(UIScrollView* self, CGPoint target, bool clampTarget) {
    CGPoint diff = target - self->_scrollAnimDest;
    CGPoint startDist = self->_scrollAnimDest - self->_scrollAnimStart;
    CGPoint curDist = target - self->_scrollAnimStart;

    //  Once we get close to or overrun the target, stop scrolling
    if (diff.lenLe(0.5f) || curDist.len() > startDist.len()) {
        [self->_displayLink invalidate];
        self->_displayLink = nil;

        if (clampTarget) {
            clipPoint(self, self->_scrollAnimDest, false);
        }

        changeContentOffset(self, self->_scrollAnimDest, FALSE);

        if (self->_animationReason == ANIMATION_USER) {
            if ([self->_delegate respondsToSelector:@selector(scrollViewDidEndScrollingAnimation:)]) {
                [self->_delegate scrollViewDidEndScrollingAnimation:self];
            }
        } else if (self->_animationReason == ANIMATION_DECELERATING_TARGET || self->_animationReason == ANIMATION_PAGING) {
            hideScrollersAction(self);
            if ([self->_delegate respondsToSelector:@selector(scrollViewDidEndDecelerating:)]) {
                [self->_delegate scrollViewDidEndDecelerating:self];
            }
        }
    } else {
        CGRect bounds;
        bounds = [self bounds];

        bool clampedX = false;
        bool clampedY = false;

        if (clampTarget) {
            clampedX = clamp((float&)target.x, findMinX(self), findMaxX(self));
            clampedY = clamp((float&)target.y, findMinY(self), findMaxY(self));
        }
        changeContentOffset(self, target, FALSE);

        if (clampedX && clampedY) {
            //  Didn't move!
            [self->_displayLink invalidate];
            self->_displayLink = nil;

            if (self->_animationReason == ANIMATION_USER) {
                if ([self->_delegate respondsToSelector:@selector(scrollViewDidEndScrollingAnimation:)]) {
                    [self->_delegate scrollViewDidEndScrollingAnimation:self];
                }
            } else if (self->_animationReason == ANIMATION_DECELERATING_TARGET || self->_animationReason == ANIMATION_PAGING) {
                hideScrollersAction(self);
                if ([self->_delegate respondsToSelector:@selector(scrollViewDidEndDecelerating:)]) {
                    [self->_delegate scrollViewDidEndDecelerating:self];
                }
            }
        }
    }
}

- (void)_animTimer {
    CGPoint dist = _scrollAnimDest - _scrollAnimStart;

    //  Start scrolling timer from first frame
    if (_scrollAnimStartTime < 0.0f) {
        _scrollAnimStartTime = EbrGetMediaTime();
    }

    float t = (float)((EbrGetMediaTime() - _scrollAnimStartTime) * _scrollAnimDecaySpeed);
    CGPoint target = {
        _scrollAnimDest.x + expf(-t) - dist.x * expf(-t / 2.f), _scrollAnimDest.y + expf(-t) - dist.y * expf(-t / 2.f),
    };

    if (fabs(dist.x) < 0.1) {
        target.x = _scrollAnimDest.x;
    }
    if (fabs(dist.y) < 0.1) {
        target.y = _scrollAnimDest.y;
    }

    animMoveTo(self, target, false);
}

static void doAnimatedScroll(UIScrollView* self, CGPoint dest, AnimationReason reason) {
    self->_animationReason = reason;
    self->_scrollAnimStart = self->_contentOffset;
    self->_scrollAnimDest = dest;
    self->_scrollAnimStartTime = -1.0f;
    self->_scrollAnimDecaySpeed = 14.0f;

    [self->_displayLink invalidate];
    self->_displayLink = nil;

    if (self->_displayLink == nil) {
        self->_displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(_animTimer)];
        [self->_displayLink addToRunLoop:[NSRunLoop mainRunLoop] forMode:@"kCFRunLoopDefaultMode"];
    }
}

/**
 @Status Interoperable
*/
- (BOOL)isDragging {
    return _isDragging;
}

/**
 @Status Interoperable
*/
- (BOOL)isZooming {
    return _isZooming;
}

/**
 @Status Interoperable
*/
- (BOOL)isTracking {
    return _isDragging || (_pressTimer != nil);
}

/**
 @Status Interoperable
*/
- (BOOL)isDecelerating {
    return _displayLink != nil;
}

/**
 @Status Stub
*/
- (float)decelerationRate {
    UNIMPLEMENTED();
    return 0.998f;
}

- (void)_pressTimer {
    if (_pressTimer != nil) {
        [_pressTimer invalidate];
        _pressTimer = nil;
    }

    CGPoint curPos;
    curPos = [_savedTouch locationInView:self];
    id viewTouched = [super hitTest:curPos withEvent:_savedEvent];
    if (viewTouched == self && _forwardsToSuperview) {
        viewTouched = [viewTouched superview];
    }

    if (viewTouched != nil && viewTouched != self) {
        _savedTouch = [[_savedTouch copy] autorelease];
        [_savedTouch _redirectTouch:viewTouched];

        _savedEvent = [[UIEvent createWithTouches:[NSSet setWithObject:(id)_savedTouch] touchEvent:(id)_savedTouch] autorelease];
        [[UIApplication sharedApplication] sendEvent:_savedEvent];
    }
}

/**
 @Status Stub
*/
- (void)flashScrollIndicators {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)setMaximumZoomScale:(float)scale {
    _maximumZoomScale = scale;
    float newScale = _zoomScale;
    clamp(newScale, _minimumZoomScale, _maximumZoomScale);
    [self setZoomScale:newScale];
}

/**
 @Status Interoperable
*/
- (float)maximumZoomScale {
    return _maximumZoomScale;
}

/**
 @Status Interoperable
*/
- (void)setMinimumZoomScale:(float)scale {
    _minimumZoomScale = scale;
    if (_minimumZoomScale > _maximumZoomScale) {
        _maximumZoomScale = _minimumZoomScale;
    }
    float newScale = _zoomScale;
    clamp(newScale, _minimumZoomScale, _maximumZoomScale);
    [self setZoomScale:newScale];
}

/**
 @Status Interoperable
*/
- (float)minimumZoomScale {
    return _minimumZoomScale;
}

- (void)_zoomStopped {
    if ([_delegate respondsToSelector:@selector(scrollViewDidEndZooming:withView:atScale:)]) {
        [_delegate scrollViewDidEndZooming:self withView:_zoomView atScale:_zoomScale];
    }
}

static void setZoomTo(UIScrollView* self, float scale, BOOL animated) {
    float oldZoom = self->_zoomScale;
    self->_zoomScale = scale;

    [self->_displayLink invalidate];
    self->_displayLink = nil;

    id view = self;
    if ([self->_delegate respondsToSelector:@selector(viewForZoomingInScrollView:)]) {
        view = [self->_delegate viewForZoomingInScrollView:self];
        self->_zoomView = view;
    }

    if (animated) {
        if ([self->_delegate respondsToSelector:@selector(scrollViewWillBeginZooming:withView:)]) {
            [self->_delegate scrollViewWillBeginZooming:self withView:self->_zoomView];
        }

        [UIView beginAnimations:@"ZoomAnimation" context:nil];
        [UIView setAnimationDelegate:self];
        [UIView setAnimationDidStopSelector:@selector(_zoomStopped)];
        [UIView setAnimationDuration:0.3];
    }

    CGAffineTransform trans;
    trans = CGAffineTransformMakeScale(self->_zoomScale, self->_zoomScale);
    if (self->_zoomView != nil) {
        [view setTransform:trans];

        CGRect frame;
        frame = [view frame];

        [self setContentSize:CGSizeMake(frame.size.width, frame.size.height)];
        clipPoint(self, self->_contentOffset, false);
        [self _refreshOrigin];
        CGPoint oldPos, newPos;
        oldPos = [[view layer] position];
        newPos.x = frame.size.width / 2.0f;
        newPos.y = frame.size.height / 2.0f;

        [self setNeedsLayout];
        [self layoutIfNeeded];

        // This breaks Salmaan's sample app and doesn't really make a lot of sense but I want to keep it
        // in here because it's apparently useful for other apps: document better.
        /*
        CGPoint curPos;
        curPos = [[view layer] position];
        if ( curPos.x == oldPos.x && curPos.y == oldPos.y ) {
        [[view layer] setPosition:newPos];
        }
        */
    } else {
        CGRect bounds;
        bounds = [view bounds];

        [view setTransform:trans];

        bounds.size.width = bounds.size.width * oldZoom / self->_zoomScale;
        bounds.size.height = bounds.size.height * oldZoom / self->_zoomScale;
        [view setBounds:bounds];

        clipPoint(self, self->_contentOffset, false);
        [self _refreshOrigin];

        [self setNeedsLayout];
        [self layoutIfNeeded];
    }

    if ([self->_delegate respondsToSelector:@selector(scrollViewDidZoom:)]) {
        [self->_delegate scrollViewDidZoom:self];
    }

    if (animated) {
        [UIView commitAnimations];
    }
    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (void)setZoomScale:(float)scale animated:(BOOL)animated {
    clamp((float&)scale, _minimumZoomScale, _maximumZoomScale);
    if (scale == _zoomScale) {
        return;
    }

    _isZoomingToRect = TRUE;
    setZoomTo(self, scale, animated);
    _isZoomingToRect = FALSE;
}

/**
 @Status Interoperable
*/
- (void)setZoomScale:(float)scale {
    [self setZoomScale:scale animated:FALSE];
}

// Internal set content offset that notifies the KVO stuff but doesn't do
// any of the external-facing content offset changing behaviour (stopping
// scrolling and killing gestures).
static void setContentOffsetKVOed(UIScrollView* self, CGPoint offs) {
    self->_contentOffset = offs;
    [self setContentOffset:offs];
}

/**
 @Status Interoperable
*/
- (void)zoomToRect:(CGRect)rect animated:(BOOL)animated {
    CGRect bounds;
    bounds = [self bounds];

    float scaleX = bounds.size.width / rect.size.width;
    float scaleY = bounds.size.height / rect.size.height;

    float newScale = min(scaleX, scaleY);
    clamp(newScale, _minimumZoomScale, _maximumZoomScale);

    setContentOffsetKVOed(self, rect.origin * newScale);
    _isZoomingToRect = TRUE;
    [self setZoomScale:newScale animated:animated];
    clipPoint(self, _contentOffset, false);
    _isZoomingToRect = FALSE;
}

/**
 @Status Interoperable
*/
- (float)zoomScale {
    return _zoomScale;
}

/**
 @Status Stub
*/
- (void)setDecelerationRate:(float)rate {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setBouncesZoom:(BOOL)bounces {
    UNIMPLEMENTED();
}

- (void)_setForwardsToSuperview:(BOOL)forwards {
    _forwardsToSuperview = forwards;
}

/**
 @Status Stub
*/
- (void)setScrollIndicatorInsets:(UIEdgeInsets)insets {
    UNIMPLEMENTED();
    _scrollIndicatorInsets = insets;
}

/**
 @Status Stub
*/
- (UIEdgeInsets)scrollIndicatorInsets {
    UNIMPLEMENTED();
    return _scrollIndicatorInsets;
}

/**
 @Status Interoperable
*/
- (void)setContentInset:(UIEdgeInsets)inset {
    if (memcmp(&_contentInset, &inset, sizeof(UIEdgeInsets)) == 0) {
        return;
    }

    _contentInset = inset;
    static int recurse = 0;
    if (recurse == 0) {
        recurse++;
        [self _clampOffset];
        recurse--;
    }
}

- (void)_clampOffset {
    CGPoint curOffset = _contentOffset;
    clipPoint(self, curOffset, false);

    if (curOffset != _contentOffset) {
        [self setContentOffset:curOffset];
    }
}

/**
 @Status Stub
*/
- (void)setIndicatorStyle:(unsigned)style {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setDirectionalLockEnabled:(BOOL)enabled {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setCanCancelContentTouches:(BOOL)canCancel {
    UNIMPLEMENTED();
    _canCancelContentTouches = canCancel;
}

/**
 @Status Interoperable
*/
- (UIEdgeInsets)contentInset {
    return _contentInset;
}

static void cancelScrolling(UIScrollView* self) {
    if (self->_displayLink != nil) {
        hideScrollersAction(self);
    }
    [self->_displayLink invalidate];
    [self->_pressTimer invalidate];
    self->_displayLink = self->_pressTimer = self->_savedTouch = self->_savedEvent = nil;
}

- (void)dealloc {
    cancelScrolling(self);

    _zoomView = nil;
    _panGesture = nil;
    _pinchGesture = nil;
    [_verticalScroller removeFromSuperlayer];
    _verticalScroller = nil;

    [super dealloc];
}

- (void)willMoveToWindow:(id)newWindow {
    cancelScrolling(self);
    [super willMoveToWindow:newWindow];
}

static float findMaxX(UIScrollView* o) {
    CGRect bounds;
    bounds = [o bounds];
    float ret = o->_contentSize.width - bounds.size.width + o->_contentInset.right;
    if (ret < findMinX(o)) {
        ret = findMinX(o);
    }

    return ret;
}

static float findMaxY(UIScrollView* o) {
    CGRect bounds;
    bounds = [o bounds];

    float ret = o->_contentSize.height - bounds.size.height + o->_contentInset.bottom;
    if (ret < findMinY(o)) {
        ret = findMinY(o);
    }

    return ret;
}

static float findMinX(UIScrollView* o) {
    return -o->_contentInset.left;
}

static float findMinY(UIScrollView* o) {
    return -o->_contentInset.top;
}

- (void)_doPan:(UIPanGestureRecognizer*)gesture {
    if (_displayLink) {
        return;
    }

    [_displayLink invalidate];
    _displayLink = nil;

    CGPoint delta;
    delta = [gesture translationInView:self];

    CGRect bounds;
    bounds = [self bounds];

    CGPoint newOffset = _contentOffset;
    int panStage = [gesture stage];

    //  Stage 0: Only freewheeling
    if (panStage == 0 || panStage == 1) {
        float minX = findMinX(self);
        float maxX = findMaxX(self);
        float minY = findMinY(self);
        float maxY = findMaxY(self);
        float oldX = newOffset.x;
        float oldY = newOffset.y;
        float newX = newOffset.x - delta.x;
        float newY = newOffset.y - delta.y;

        //  Stage 1: unstick axis's
        if (panStage == 1) {
            if (delta.x != 0) {
                _xStuck = false;
            }
            if (delta.y != 0) {
                _yStuck = false;
            }
        }

        if (!_xStuck) {
            if (delta.x > 0.0f) {
                if (newX < minX) {
                    _xStuck = true;
                }
                if (newX < minX && oldX > minX) {
                    newX = minX;
                    newOffset.x = newX;
                }
            } else if (delta.x < 0.0f) {
                if (newX > maxX) {
                    _xStuck = true;
                }
                if (newX > maxX && oldX < maxX) {
                    newX = maxX;
                    newOffset.x = newX;
                }
            }
        }

        if (!_yStuck) {
            if (delta.y > 0.0f) {
                if (newY < minY) {
                    _yStuck = true;
                }
                if (newY < minY && oldY > minY) {
                    newY = minY;
                    newOffset.y = newY;
                }
            } else if (delta.y < 0.0f) {
                if (newY > maxY) {
                    _yStuck = true;
                }
                if (newY > maxY && oldY < maxY) {
                    newY = maxY;
                    newOffset.y = newY;
                }
            }
        }

        if (!_xStuck) {
            newOffset.x = newX;
        }
        if (!_yStuck) {
            newOffset.y = newY;
        }

        if (_pagingEnabled) {
            if (!_xStuck) {
                //  Crossing page boundaries is sticky
                int curScrollPage = int((_contentOffset.x + bounds.size.width / 2.0f) / bounds.size.width);

                float scrollPageBoundary = curScrollPage * bounds.size.width;

                float minX = min(newOffset.x, _contentOffset.x);
                float maxX = max(newOffset.x, _contentOffset.x);

                if (minX < scrollPageBoundary && maxX > scrollPageBoundary) {
                    newOffset.x = scrollPageBoundary;
                    _xStuck = true;
                }
            }
        }
    } else if (panStage == 2) {
        // if ( delta.x != 0.0f ) _xStuck = false;
        // if ( delta.y != 0.0f ) _yStuck = false;

        //  Stage 1: overdrag, unsticking
        newOffset.x -= delta.x;
        newOffset.y -= delta.y;
    }

    if (newOffset != _contentOffset) {
        if (!_isDragging) {
            if ([_delegate respondsToSelector:@selector(scrollViewWillBeginDragging:)]) {
                [_delegate scrollViewWillBeginDragging:self];
            }
            _isDragging = true;
            showScrollersAction(self);
        }

        CGPoint oldOffset = _contentOffset;
        clipPoint(self, newOffset);

        //  Use up the amount of translation
        [gesture setTranslation:CGPointMake(delta.x - (oldOffset.x - newOffset.x), delta.y - (oldOffset.y - newOffset.y)) inView:self];

        //  Adjust offset, with bounce
        addPointWithBounce(self, oldOffset, newOffset.x - oldOffset.x, newOffset.y - oldOffset.y);
        changeContentOffset(self, oldOffset, FALSE);
    }
}

- (id)_gestureRecognizerTouchesReached:(id)gesture {
    if (!_scrollEnabled) {
        return self;
    }

    if (_animationReason == ANIMATION_DECELERATING || _animationReason == ANIMATION_DECELERATING_TARGET) {
        stopScrollAnimations(self);
    }

    return self;
}

static void abortGestures(UIScrollView* self) {
    if ([self->_panGesture state] == UIGestureRecognizerStateBegan || [self->_panGesture state] == UIGestureRecognizerStateChanged) {
        [self->_panGesture cancel];
    }
}

static float clipToPage(float start, float curOffset, float velocity, float pageSize, float contentSize) {
    int startScrollPage = int((start + pageSize / 2.0f) / pageSize);
    int dropScrollPage = int((curOffset + pageSize / 2.0f) / pageSize);
    int destScrollPage;

    float physicalVelocity =
        velocity * GetCACompositor()->screenScale() / ((GetCACompositor()->screenXDpi() + GetCACompositor()->screenYDpi()) / 2.0f);

    if (dropScrollPage != startScrollPage) {
        destScrollPage = dropScrollPage;
    } else {
        destScrollPage = startScrollPage;
        if (physicalVelocity < -3.5f) {
            ++destScrollPage;
        } else if (physicalVelocity > 3.5f) {
            --destScrollPage;
        }
    }

    int numPages = max(int(contentSize / pageSize), 1);
    clamp(destScrollPage, 0, numPages - 1);

    return float(destScrollPage) * pageSize;
}

- (id)_panGestureCallback:(id)gesture {
    if (!_scrollEnabled) {
        return self;
    }

    stopScrollAnimations(self);

    CGRect bounds;
    bounds = [self bounds];

    CGSize contentSize = _contentSize;
    contentSize.width += _contentInset.right;
    contentSize.height += _contentInset.bottom;

    CGPoint delta;
    delta = [gesture translationInView:self];

    int state = [gesture state];

    if (state == UIGestureRecognizerStateBegan && [gesture stage] == 0) {
        _xStuck = false;
        _yStuck = false;
        _lockVertical = false;
        _lockHorizontal = false;
        _panStart = _contentOffset;

        if (contentSize.width <= bounds.size.width) {
            if (delta.x != 0 || delta.y != 0) {
                if (fabs(delta.x) <= fabs(delta.y)) {
                    _lockVertical = true;
                } else {
                    _lockHorizontal = true;
                }
            }
        }

        if (contentSize.height <= bounds.size.height) {
            if (delta.x != 0 || delta.y != 0) {
                if (fabs(delta.x) <= fabs(delta.y)) {
                    _lockVertical = true;
                } else {
                    _lockHorizontal = true;
                }
            }
        }
    }

    if (_lockVertical) {
        delta.x = 0;
        [gesture _lockDirection:0];
    } else if (_lockHorizontal == true) {
        delta.y = 0;
        [gesture _lockDirection:1];
    }

    if (state >= UIGestureRecognizerStateBegan && state <= UIGestureRecognizerStateEnded) {
        if (delta.x || delta.y) {
            UIScrollView* touchedView = [gesture _touchedView];
            [self _doPan:gesture];
        }
    }

    if ([gesture state] == UIGestureRecognizerStateEnded || [gesture state] == UIGestureRecognizerStateCancelled) {
        if (!_displayLink && _isDragging) {
            //
            // This is the after-gesture frictiony dragging business:
            //

            CGRect bounds;
            bounds = [self bounds];

            CGPoint velocity = { 0 };

            if ([gesture state] != UIGestureRecognizerStateCancelled) {
                velocity = [gesture velocityInView:self];
            }
            if (_xStuck) {
                velocity.x = 0;
            }

            if (_yStuck) {
                velocity.y = 0;
            }

            if (_lockVertical) {
                velocity.x = 0;
            } else if (_lockHorizontal == true) {
                velocity.y = 0;
            }

            BOOL willDecelerate = TRUE;
            BOOL decelerateAnimation = FALSE;

            CGPoint dest;
            if (self.pagingEnabled) {
                dest.x = clipToPage(_panStart.x, _contentOffset.x, velocity.x, bounds.size.width, contentSize.width);
                dest.y = clipToPage(_panStart.y, _contentOffset.y, velocity.y, bounds.size.height, contentSize.height);
            } else {
                dest = calcInertialDestination(self, _contentOffset, -velocity);
            }

            if ([_delegate respondsToSelector:@selector(scrollViewWillEndDragging:withVelocity:targetContentOffset:)]) {
                CGPoint old = dest;
                [_delegate scrollViewWillEndDragging:self withVelocity:-velocity targetContentOffset:&dest];
                if (old != dest) {
                    doAnimatedScroll(self, dest, ANIMATION_DECELERATING_TARGET);
                    willDecelerate = TRUE;
                    decelerateAnimation = TRUE;
                }
            }

            if (_pagingEnabled || (velocity.x == 0.0f && velocity.y == 0.0f)) {
                willDecelerate = FALSE;
            }

            _isDragging = false;

            if ([_delegate respondsToSelector:@selector(scrollViewDidEndDragging:willDecelerate:)]) {
                [_delegate scrollViewDidEndDragging:self willDecelerate:willDecelerate];
            }

            if (!decelerateAnimation) {
                if (_pagingEnabled) {
                    doAnimatedScroll(self, dest, ANIMATION_PAGING);
                    if ([_delegate respondsToSelector:@selector(scrollViewWillBeginDecelerating:)]) {
                        [_delegate scrollViewWillBeginDecelerating:self];
                    }
                } else {
                    if (willDecelerate) {
                        if ([_delegate respondsToSelector:@selector(scrollViewWillBeginDecelerating:)]) {
                            [_delegate scrollViewWillBeginDecelerating:self];
                        }
                        doInertialScroll(self, -velocity, ANIMATION_DECELERATING);
                    } else {
                        //  We need to do inertial scroll if we're out of bounds
                        if (_contentOffset.x < findMinX(self) || _contentOffset.x > findMaxX(self) || _contentOffset.y < findMinY(self) ||
                            _contentOffset.y > findMaxY(self)) {
                            doInertialScroll(self, -velocity, ANIMATION_BOUNCING);
                        } else {
                            hideScrollersAction(self);
                        }
                    }
                }
            } else {
                hideScrollersAction(self);
            }
        }
    }
    return self;
}

- (void)_didPinch:(UIGestureRecognizer*)gesture {
    if (_minimumZoomScale == _maximumZoomScale) {
        return;
    }

    UIGestureRecognizerState state = (UIGestureRecognizerState)[gesture state];
    UIView* view = self;

    if ([_delegate respondsToSelector:@selector(viewForZoomingInScrollView:)]) {
        view = [_delegate viewForZoomingInScrollView:self];
    }
    if (state == UIGestureRecognizerStateBegan) {
        //  Cancel any other pans
        [UIPanGestureRecognizer cancelActiveExcept:(id)_panGesture];
        [_pinchGesture setScale:_zoomScale];
        _isZooming = true;
        [self setNeedsLayout];
    } else if (state == UIGestureRecognizerStateEnded || state == UIGestureRecognizerStatePossible) {
        BOOL fireEvent = _isZooming;
        _isZooming = false;

        if (fireEvent) {
            if ([_delegate respondsToSelector:@selector(scrollViewDidEndZooming:withView:atScale:)]) {
                [_delegate scrollViewDidEndZooming:self withView:view atScale:_zoomScale];
            }
        }
    } else if (state == UIGestureRecognizerStateChanged) {
        CGFloat scale = [gesture scale];
        clamp(scale, _minimumZoomScale, _maximumZoomScale);
        if (scale == _zoomScale) {
            return;
        }

        CGPoint start = _contentOffset, pinchPoint;
        pinchPoint = [gesture locationInView:self];
        CGPoint diff = pinchPoint - _contentOffset;

        CGRect viewBounds;
        viewBounds = [self bounds];

        CGRect bounds;
        bounds = [self bounds];

        double relativeScale = ((double)scale / (double)_zoomScale);
        //_contentOffset = start * relativeScale + diff * (1 - 1 / relativeScale);
        _contentOffset = ((view == self) ? start : (start * scale / _zoomScale)) + diff * ((float)(1.0 - 1.0 / relativeScale));
        clamp((float&)_contentOffset.x,
              (float)-_contentInset.left,
              max((float)(_contentSize.width - bounds.size.width + _contentInset.right), 0.f));
        clamp((float&)_contentOffset.y,
              (float)-_contentInset.top,
              max((float)(_contentSize.height - bounds.size.height + _contentInset.bottom), 0.f));

        if ([_delegate respondsToSelector:@selector(scrollViewWillBeginZooming:withView:)]) {
            [_delegate scrollViewWillBeginZooming:self withView:view];
        }
        setZoomTo(self, scale, FALSE);
    }
}

- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    if (self.scrollEnabled) {
        // If we get a touch down, cancel any scrolling we were doing:
        cancelScrolling(self);
    }
}

- (void)layoutSubviews {
    [super layoutSubviews];
    //  Make sure we stay within our bounds
    // We don't want to clamp when we have no content since they're doing the positioning manually.
    if (![self isTracking] && _displayLink == nil && !CGSizeEqualToSize(_contentSize, CGSizeZero)) {
        CGPoint curOffset = _contentOffset;
        clipPoint(self, curOffset, false);

        if (curOffset != _contentOffset) {
            [self setContentOffset:curOffset animated:TRUE];
        }
    }
    positionScrollers(self);
}

- (id<CAAction>)actionForLayer:(CALayer*)layer forKey:(NSString*)key {
    if (_isZoomingToRect) {
        return [super actionForLayer:layer forKey:key];
    }

    char* keyName = (char*)[key UTF8String];
    if (strcmp(keyName, "bounds.origin") == 0) {
        return (id<CAAction>)[NSNull null];
    }
    if (strcmp(keyName, "bounds") == 0) {
        return [super actionForLayer:layer forKey:@"bounds.size"];
    }

    return [super actionForLayer:layer forKey:key];
}

- (UIPinchGestureRecognizer*)pinchGestureRecognizer {
    return _pinchGesture;
}

/**
 @Status Interoperable
*/
- (UIPanGestureRecognizer*)panGestureRecognizer {
    return _panGesture;
}

@end
