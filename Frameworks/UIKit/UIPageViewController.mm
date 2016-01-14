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

#import <UIKit/UIPanGestureRecognizer.h>
#import <UIKit/UIScrollView.h>
#import <Foundation/NSException.h>
#import <UIKit/UIPageViewController.h>

#include <algorithm>

static const unsigned int c_numVisiblePages = 3;

NSString * const UIPageViewControllerOptionSpineLocationKey = @"SpineLocation";
NSString * const UIPageViewControllerOptionInterPageSpacingKey = @"PageSpacing";

@interface _UIPageViewScrollView : UIScrollView<UIScrollViewDelegate>

- (void)_cancelScroll;
- (void)_scrollToNewViewController:(UIViewController *)controller direction:(UIPageViewControllerNavigationDirection)direction animated:(BOOL)animated completion:(void (^)(BOOL finished))completion;

@end

@implementation _UIPageViewScrollView {
    idretaintype(UIPageViewController) _viewController;
    idretaintype(UIViewController) _controllers[c_numVisiblePages];
    idretainp<void (^)(BOOL)> _completion;
}

- (void)_cancelScroll {
    CGPoint currentOffset = self.contentOffset;
    [self _shiftContent:&currentOffset];
    [self setContentOffset:CGPointMake(self.frame.size.width, 0) animated:NO];
}

- (instancetype)_initWithPageViewController:(UIPageViewController *)viewController {
    [super init];

    // TODO: Multi-page. _controllers will require an array with 6 elements, since we may know about two more views in either direction.
    _viewController = viewController;

    self.delegate = self;

    self.showsHorizontalScrollIndicator = NO;
    self.showsVerticalScrollIndicator = NO;
    self.pagingEnabled = YES;

    return self;
}

- (void)_replaceController:(UIViewController*)controller atIndex:(unsigned int)index {
    [[_controllers[index] view] removeFromSuperview];
    _controllers[index] = controller;
    if (_controllers[index] != nil) {
        [self addSubview:[_controllers[index] view]];
        [self setNeedsLayout];
    }
}

- (void)_scrollToNewViewController:(UIViewController *)controller direction:(UIPageViewControllerNavigationDirection)direction animated:(BOOL)animated completion:(void (^)(BOOL finished))completion {
    CGRect currentFrame = self.frame;

    // In all likelihood if we have a completion handler when this is called we haven't finished the last animation.
    // TODO: Likelihood?
    if (_completion) {
        _completion(YES);
        _completion = nil;
    }

    if (animated) {
        CGPoint targetOffset = CGPointMake(currentFrame.size.width, 0);

        self.scrollEnabled = NO;
        auto copiedCompletion = Block_copy(completion);
        _completion = copiedCompletion; // retained
        Block_release(copiedCompletion);

        // Recenter the view. This will cancel any scroll animations.
        [self setContentOffset:targetOffset animated:NO];

        // TODO: Vertical pages.
        switch (direction) {
            case UIPageViewControllerNavigationDirectionForward:
                targetOffset.x += currentFrame.size.width;
                [self _shiftContent:&targetOffset];
                [self _replaceController:controller atIndex:1];
                [self setContentOffset:CGPointMake(currentFrame.size.width, 0) animated:YES];
                break;
            case UIPageViewControllerNavigationDirectionReverse:
                targetOffset.x -= currentFrame.size.width;
                [self _shiftContent:&targetOffset];
                [self _replaceController:controller atIndex:1];
                [self setContentOffset:CGPointMake(currentFrame.size.width, 0) animated:YES];
                break;
            default:
                NSLog(@"Parameter 'direction' out of range");
                FAIL_FAST();
        }

        // Completion handler called in scrollViewDidEndScrollingAnimation
    } else {
        CGPoint currentOffset = CGPointMake(currentFrame.size.width, 0);

        [self _replaceController:controller atIndex:1];
        [self setContentOffset:currentOffset animated:NO];
        [self _updateVisible];

        if(completion) {
            completion(YES);
        }
    }
}

- (void)_shiftContent:(inout CGPoint *)targetContentOffset {
    CGRect currentFrame = self.frame;
    CGPoint currentOffset = self.contentOffset;

    if (targetContentOffset->x >= currentFrame.size.width * 2) {
        currentOffset.x -= currentFrame.size.width;
        [self setContentOffset:currentOffset];
        targetContentOffset->x = currentFrame.size.width;
        [[_controllers[0] view] removeFromSuperview];
        for (int i = 0; i < c_numVisiblePages-1; i++) {
            _controllers[i] = _controllers[i+1];
        }
        _controllers[c_numVisiblePages-1] = nil;
    } else if (targetContentOffset->x <= 0) {
        currentOffset.x += currentFrame.size.width;
        [self setContentOffset:currentOffset];
        targetContentOffset->x = currentFrame.size.width;
        [[_controllers[c_numVisiblePages-1] view] removeFromSuperview];
        for (int i = c_numVisiblePages-1; i > 0; i--) {
            _controllers[i] = _controllers[i-1];
        }
        _controllers[0] = nil;
    }

    [self setNeedsLayout];
}

- (void)scrollViewWillEndDragging:(UIScrollView *)scrollView withVelocity:(CGPoint)velocity targetContentOffset:(inout CGPoint *)targetContentOffset {
    [self _shiftContent:targetContentOffset];
}

- (void)scrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView {
    if (_completion) {
        _completion(!self.tracking);
        _completion = nil;
    }

    // TODO: Call pageViewController:didFinishAnimating:previousViewControllers:transitionCompleted:

    self.scrollEnabled = ([_viewController delegate] != nil);

    CGPoint currentOffset = self.contentOffset;
    [self _shiftContent:&currentOffset];
    [self _updateVisible];
}

- (void)setFrame:(CGRect)frame {
    CGSize currentContentSize = self.contentSize;

    if (currentContentSize.width != frame.size.width * c_numVisiblePages) {
        // We pull a switcheroo as we page left and right by resetting the content offset to the middle
        [self setContentSize:CGSizeMake(frame.size.width * c_numVisiblePages, 0)];
        // Caveat: If you change the size of the frame while animating the content offset, it'll snap.
        [self setContentOffset:CGPointMake(frame.size.width, 0)];
    }

    [super setFrame:frame];
}

- (void)layoutSubviews {
    CGRect frame = self.frame;
    // TODO: Vertical layout
    for (int i = 0; i < c_numVisiblePages; i++) {
        if (_controllers[i] != nil) {
            CGRect childFrame = frame;
            childFrame.origin.y = 0;
            childFrame.origin.x = i * frame.size.width;

            [[_controllers[i] view] setFrame:childFrame];
        }
    }

    [super layoutSubviews];
}

- (void)_updateVisible {
    CGRect currentFrame = self.frame;
    CGPoint currentOffset = self.contentOffset;

    // TODO: Vertical direction.
    // Check bounds on the items we have visible, and release them if we don't see them anymore.
    for (int i = 0; i < c_numVisiblePages; i++) {
        CGFloat left = i * currentFrame.size.width;
        CGFloat right = left + currentFrame.size.width;

        if (left >= currentOffset.x + currentFrame.size.width || right <= currentOffset.x) {
            [self _replaceController:nil atIndex:i];
        } else {
            // TODO: Should this only be edge-triggered?
            if (_controllers[i] == nil) {
                // TODO: Call delegate to get more, stop scrolling if there are none.
                // TODO: Call pageViewController:willTransitionToViewControllers:
            }
        }
    }
}

@end

@implementation UIPageViewController {
    idretaintype(NSArray) _gestureRecognizers;
    idretaintype(NSArray) _viewControllers;
    idretaintype(_UIPageViewScrollView) _scrollView;
}

- (instancetype)init {
    return [self initWithTransitionStyle:UIPageViewControllerTransitionStyleScroll navigationOrientation:UIPageViewControllerNavigationOrientationVertical options:nil];
}

/**
@Status Interoperable
*/
- (NSArray *)gestureRecognizers {
    if (_gestureRecognizers == nil) {
        _gestureRecognizers = [NSArray arrayWithObjects:[_scrollView panGestureRecognizer], nil];
    }
    return _gestureRecognizers;
}

- (void)_setViewControllers:(NSArray *)viewControllers {
    _viewControllers = viewControllers;
}

- (NSArray *)viewControllers {
    return _viewControllers;
}

/**
@Status Stub
*/
- (BOOL)isDoubleSided {
    // Only valid in curl transition style, which we don't currently support.
    UNIMPLEMENTED();
    return NO;
}

/**
@Status Stub
*/
- (void)setDoubleSided:(BOOL)doubleSided {
    UNIMPLEMENTED();
}

/**
@Status Caveat
@Notes Only single page scroll style transitions supported.
*/
- (void)setViewControllers:(NSArray *)viewControllers direction:(UIPageViewControllerNavigationDirection)direction animated:(BOOL)animated completion:(void (^)(BOOL finished))completion {
    if (viewControllers == nil) { 
        @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Parameter viewControllers nil!" userInfo:nil];
    }

    switch (self.spineLocation) {
        case UIPageViewControllerSpineLocationNone:
        case UIPageViewControllerSpineLocationMin:
        case UIPageViewControllerSpineLocationMax:
            if (self.doubleSided) {
                if (viewControllers.count != 2) {
                    @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Doublesided spine type requires 2 UIViewControllers!" userInfo:nil];
                } else {
                    NSLog(@"Double sided transitions not supported. Only first element will be used for transition.");
                    viewControllers = [[NSArray arrayWithObjects:[viewControllers objectAtIndex:0]] autorelease];
                }
            } 
            if (viewControllers.count != 1) {
                @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Spine type requires 1 UIViewController!" userInfo:nil];
            }
            break;
        case UIPageViewControllerSpineLocationMid:
            if (viewControllers.count > 2) {
                @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Spine type requires 2 UIViewControllers!" userInfo:nil];
            }
            break;
        default:
            @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Parameter 'direction' out of range." userInfo:nil];
    }

    for (int i = 0; i < viewControllers.count; i++) {
        id viewController = [viewControllers objectAtIndex:i];
        if ((viewController != nil) && ![viewController isKindOfClass:[UIViewController class]]) {
            @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Not all elements in viewControllers conform to UIViewController" userInfo:nil];
        }
    }

    // TODO: Call pageViewController:willTransitionToViewControllers:

    // TODO: Multi-page navigation
    switch (direction) {
        case UIPageViewControllerNavigationDirectionForward:
        case UIPageViewControllerNavigationDirectionReverse:
            [_scrollView _scrollToNewViewController:[viewControllers objectAtIndex:0] 
                                          direction:direction 
                                           animated:animated 
                                         completion:completion];
            break;
        default:
            @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Invalid navigation direction" userInfo:nil];
    }

    [self _setViewControllers:viewControllers];
}

/**
@Status Interoperable
*/
- (void)setDelegate:(id<UIPageViewControllerDelegate>)delegate {
    [_scrollView _cancelScroll];
    _delegate = delegate;
    [_scrollView setScrollEnabled:(_delegate != nil)];
}

/**
@Status Caveat
@Notes Only single page scroll style transitions supported. Only vertical orientation. Options ignored.
*/
- (instancetype)initWithTransitionStyle:(UIPageViewControllerTransitionStyle)style navigationOrientation:(UIPageViewControllerNavigationOrientation)navigationOrientation options:(NSDictionary *)options {
    // TODO: What happens when someone tries to set the view property? Should we fail out?
    _scrollView = [[_UIPageViewScrollView alloc] _initWithPageViewController:self]; 

    [_scrollView setScrollEnabled:NO];

    self.view = [_scrollView retain];

    switch (style) {
        case UIPageViewControllerTransitionStylePageCurl:
            NSLog(@"UIPageViewControllerTransitionStylePageCurl unsupported. Transition style will fall back to Scroll.");
            // Fallthrough
        case UIPageViewControllerTransitionStyleScroll:
            _transitionStyle = style;
            break;
        default:
            @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Parameter \"style\" out of range" userInfo:nil];
    }

    switch (navigationOrientation) {
        case UIPageViewControllerNavigationOrientationHorizontal:
        case UIPageViewControllerNavigationOrientationVertical:
            _navigationOrientation = navigationOrientation;
            break;
        default:
            @throw [NSException exceptionWithName:NSInvalidArgumentException reason:@"Parameter \"navigationOrientation\" out of range" userInfo:nil];
    }

    if (options != nil) {
        NSLog(@"UIPageViewController parameter \"options\" unsupported.");
    }

    // TODO: Should we pull the pan gesture recognizer from UIScrollView?
    
    return self;
}

@end