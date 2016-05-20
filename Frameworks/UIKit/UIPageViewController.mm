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
#import "NSLogging.h"
#import <objc/blocks_runtime.h>

#include <algorithm>

static const wchar_t* TAG = L"UIPageViewController";
NSString* const UIPageViewControllerOptionSpineLocationKey = @"SpineLocation";
NSString* const UIPageViewControllerOptionInterPageSpacingKey = @"PageSpacing";

@interface _UIPageViewPage : UIView
- (instancetype)initWithFrame:(CGRect)frame viewController:(UIViewController*)controller;
- (void)unhide;
@end

@interface _UIPageViewScrollView : UIScrollView <UIScrollViewDelegate>
- (NSArray*)_currentPages;
- (void)_resetToCurrent;
- (void)_scrollToNewViewController:(UIViewController*)controller
                         direction:(UIPageViewControllerNavigationDirection)direction
                          animated:(BOOL)animated
                        completion:(void (^)(BOOL finished))completion;
@end

@implementation _UIPageViewPage {
    idretaintype(UIViewController) _controller;
}

- (instancetype)initWithFrame:(CGRect)frame viewController:(UIViewController*)controller {
    auto ret = [super initWithFrame:frame];
    _controller = controller;
    self.hidden = YES;
    return ret;
}

- (void)setFrame:(CGRect)frame {
    [super setFrame:frame];
    CGRect fitFrame = { 0, 0, frame.size.width, frame.size.height };
    for (int i = 0; i < [self.subviews count]; i++) {
        [[self.subviews objectAtIndex:i] setFrame:fitFrame];
    }
}

- (void)unhide {
    [self addSubview:[_controller view]];
    self.hidden = NO;
    [self setNeedsLayout];
}

@end

@implementation _UIPageViewScrollView {
    idretaintype(UIPageViewController) _viewController;
    idretaintype(NSMutableArray) _controllers;
    idretaintype(NSMutableArray) _pages;
    idretaintype(NSMutableArray) _previousControllers;
    idretainp<void (^)(BOOL)> _completion;
    BOOL _keepAdjacent;
    BOOL _skipUpdates;
}

- (instancetype)_initWithPageViewController:(UIPageViewController*)viewController {
    [super init];

    _controllers.attach([NSMutableArray new]);
    _pages.attach([NSMutableArray new]);

    // TODO: Multi-page. _controllers will require an array with 6 elements, since we may know about two more views in either direction.
    _viewController = viewController;

    self.delegate = self;

    self.showsHorizontalScrollIndicator = NO;
    self.showsVerticalScrollIndicator = NO;
    self.pagingEnabled = YES;
    self.scrollEnabled = NO;

    return self;
}

- (NSArray*)_currentPages {
    // TODO: Multiple pages
    // TODO: Vertical orientation
    if ([_controllers count] == 0) {
        return nil;
    }

    // Returns the page that's centered on screen.
    // In the event the user scrolled far enough past either end of the scrollview, clamp to the size of our array.
    NSInteger idx = (NSInteger)(self.contentOffset.x / self.frame.size.width + 0.5f);
    if (idx < 0) {
        return [NSArray arrayWithObjects:[_controllers objectAtIndex:0], nil];
    } else if (idx < [_controllers count]) {
        return [NSArray arrayWithObjects:[_controllers objectAtIndex:idx], nil];
    } else {
        return [NSArray arrayWithObjects:[_controllers objectAtIndex:[_controllers count] - 1], nil];
    }
}

- (void)_scrollToNewViewController:(UIViewController*)controller
                         direction:(UIPageViewControllerNavigationDirection)direction
                          animated:(BOOL)animated
                        completion:(void (^)(BOOL finished))completion {
    CGRect currentFrame = self.frame;
    CGPoint currentOffset = self.contentOffset;

    // In all likelihood if we have a completion handler when this is called we haven't finished the last animation.
    // TODO: Likelihood?
    if (_completion) {
        _completion(YES);
        _completion = nil;
    }

    if (animated) {
        CGPoint targetOffset = CGPointMake(0, 0);

        auto copiedCompletion = Block_copy(completion);
        _completion = copiedCompletion; // retained
        Block_release(copiedCompletion);

        _previousControllers = [self _currentPages];

        [self _resetToCurrent];

        _keepAdjacent = TRUE;

        [self _pushController:controller direction:direction targetOffset:&targetOffset];

        // TODO: Vertical pages.
        switch (direction) {
            case UIPageViewControllerNavigationDirectionForward:
                [self setContentOffset:CGPointMake(self.contentOffset.x + currentFrame.size.width, 0) animated:YES];
                break;
            case UIPageViewControllerNavigationDirectionReverse:
                [self setContentOffset:CGPointMake(0, 0) animated:YES];
                break;
            default:
                NSTraceCritical(TAG, @"Parameter 'direction' out of range");
                FAIL_FAST();
        }

        _keepAdjacent = FALSE;

        // Completion handler called in scrollViewDidEndScrollingAnimation
    } else {
        CGPoint targetOffset = CGPointMake(0, 0);

        _previousControllers = [self _currentPages];

        [self setContentOffset:targetOffset animated:NO];

        for (int i = 0; i < [_pages count]; i++) {
            [[_pages objectAtIndex:i] removeFromSuperview];
        }

        _controllers = [NSMutableArray new];
        _pages = [NSMutableArray new];

        [self _pushController:controller direction:UIPageViewControllerNavigationDirectionForward targetOffset:&targetOffset];

        if (completion) {
            completion(YES);
        }
    }
}

- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    _previousControllers = [self _currentPages];
    if (self.decelerating) {
        [super touchesBegan:touches withEvent:event];
    } else {
        CGPoint targetOffset = self.contentOffset;
        _keepAdjacent = TRUE;
        [self _populatePagesWithOffset:&targetOffset interactive:YES];
        [super touchesBegan:touches withEvent:event];
        _keepAdjacent = FALSE;
    }
}

- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    CGPoint targetOffset = self.contentOffset;
    [super touchesEnded:touches withEvent:event];
    [self _populatePagesWithOffset:&targetOffset interactive:NO];
}

- (void)_resetToCurrent {
    _skipUpdates = TRUE;

    NSArray* currentControllers = [self _currentPages];

    // Recenter the view. This will cancel any scroll animations.
    [self setContentOffset:CGPointMake(0, 0) animated:NO];

    for (int i = 0; i < [_pages count]; i++) {
        [[_pages objectAtIndex:i] removeFromSuperview];
    }

    if (currentControllers) {
        _controllers = [NSMutableArray arrayWithArray:currentControllers];
        _pages = [NSMutableArray new];
        for (int i = 0; i < [_controllers count]; i++) {
            _UIPageViewPage* newPage = [[_UIPageViewPage alloc] initWithFrame:self.frame viewController:[_controllers objectAtIndex:i]];
            [_pages addObject:newPage];
            [self addSubview:newPage];
            [newPage release];
        }
    } else {
        _controllers = [NSMutableArray new];
        _pages = [NSMutableArray new];
    }

    [self _updateVisible];

    _skipUpdates = FALSE;
}

- (void)_updateVisible {
    CGRect currentFrame = self.frame;
    CGPoint currentOffset = self.contentOffset;
    int begin = static_cast<int>(floorf(currentOffset.x / currentFrame.size.width));
    int end = static_cast<int>(ceilf(currentOffset.x / currentFrame.size.width)) + 1;
    int count = [_pages count];

    if (count == 0) {
        return;
    }

    if (begin < 0) {
        begin = 0;
    }

    if (end >= count) {
        end = count;
    }

    // TODO: Multi page
    for (int i = begin; i < end; i++) {
        if ([[_pages objectAtIndex:i] isHidden]) {
            [[_pages objectAtIndex:i] unhide];
            if (self.tracking) {
                if ([[_viewController delegate] respondsToSelector:@selector(pageViewController:willTransitionToViewControllers:)]) {
                    [[_viewController delegate] pageViewController:_viewController
                                   willTransitionToViewControllers:[NSArray arrayWithObjects:[_controllers objectAtIndex:i], nil]];
                }
            }
        }
    }
}

- (void)_pushController:(UIViewController*)controller
              direction:(UIPageViewControllerNavigationDirection)direction
           targetOffset:(inout CGPoint*)targetContentOffset {
    _UIPageViewPage* newPage = [[_UIPageViewPage alloc] initWithFrame:self.frame viewController:controller];

    switch (direction) {
        case UIPageViewControllerNavigationDirectionForward:
            [_controllers addObject:controller];
            [_pages addObject:newPage];
            [self setContentSize:CGSizeMake(self.frame.size.width * [_controllers count], 0)];
            break;
        case UIPageViewControllerNavigationDirectionReverse:
            [_controllers insertObject:controller atIndex:0];
            [_pages insertObject:newPage atIndex:0];
            [self setContentSize:CGSizeMake(self.frame.size.width * [_controllers count], 0)];
            [self setContentOffset:CGPointMake(self.contentOffset.x + self.frame.size.width, 0)];
            targetContentOffset->x += self.frame.size.width;
            break;
    }
    [self addSubview:newPage];
    [self _updateVisible];
    [self setNeedsLayout];
    [newPage release];
}

- (void)_popControllerWithDirection:(UIPageViewControllerNavigationDirection)direction {
    switch (direction) {
        case UIPageViewControllerNavigationDirectionForward:
            [[_pages objectAtIndex:([_controllers count] - 1)] removeFromSuperview];
            [_controllers removeObjectAtIndex:([_controllers count] - 1)];
            [_pages removeObjectAtIndex:([_pages count] - 1)];
            [self setContentSize:CGSizeMake(self.frame.size.width * [_controllers count], 0)];
            break;
        case UIPageViewControllerNavigationDirectionReverse:
            [[_pages objectAtIndex:0] removeFromSuperview];
            [_controllers removeObjectAtIndex:0];
            [_pages removeObjectAtIndex:0];
            [self setContentSize:CGSizeMake(self.frame.size.width * [_controllers count], 0)];
            [self setContentOffset:CGPointMake(self.contentOffset.x - self.frame.size.width, 0)];
            break;
    }

    [self setNeedsLayout];
}

- (void)scrollViewWillEndDragging:(UIScrollView*)scrollView
                     withVelocity:(CGPoint)velocity
              targetContentOffset:(inout CGPoint*)targetContentOffset {
    [self _populatePagesWithOffset:targetContentOffset interactive:YES];
}

- (void)scrollViewDidEndScrollingAnimation:(UIScrollView*)scrollView {
    if (_completion) {
        _completion(!self.tracking);
        _completion = nil;
    }

    _previousControllers = nil;

    CGPoint targetOffset = self.contentOffset;
    [self _populatePagesWithOffset:&targetOffset interactive:NO];
}

- (void)scrollViewDidEndDecelerating:(UIScrollView*)scrollView {
    if (_completion) {
        _completion(!self.tracking);
        _completion = nil;
    }

    // We make the assumption that if the previous controllers and current controllers are different, we successfully transited...
    // this may not be correct for multipage.
    if ([[_viewController delegate]
            respondsToSelector:@selector(pageViewController:didFinishAnimating:previousViewControllers:transitionCompleted:)]) {
        [[_viewController delegate] pageViewController:_viewController
                                    didFinishAnimating:!self.tracking
                               previousViewControllers:_previousControllers
                                   transitionCompleted:![_previousControllers isEqualToArray:[self _currentPages]]];
    }

    _previousControllers = nil;

    CGPoint targetOffset = self.contentOffset;
    [self _populatePagesWithOffset:&targetOffset interactive:NO];
}

- (void)layoutSubviews {
    CGRect frame = self.frame;

    // TODO: Vertical layout
    
    [self _updateVisible];

    for (int i = 0; i < [_pages count]; i++) {
        CGRect childFrame = frame;
        childFrame.origin.y = 0;
        childFrame.origin.x = i * frame.size.width;
        [[_pages objectAtIndex:i] setFrame:childFrame];
    }

    [super layoutSubviews];
}

- (void)_populatePagesWithOffset:(inout CGPoint*)targetOffset interactive:(BOOL)interactive {
    if ([_controllers count] == 0 && _skipUpdates) {
        return;
    }

    CGRect currentFrame = self.frame;

    // TODO: Vertical direction.
    // TODO: Multiple pages
    // TODO: Probably shouldn't hammer the dataSource when it returns nil.
    if (interactive || _keepAdjacent) {
        if ((self.contentOffset.x + currentFrame.size.width) >= ([_controllers count] * currentFrame.size.width)) {
            // BUG: See https://github.com/Microsoft/WinObjC/issues/291 for the cast
            UIViewController* nextController = [(id<UIPageViewControllerDataSource>)[_viewController dataSource]
                               pageViewController:_viewController
                viewControllerAfterViewController:[_controllers objectAtIndex:([_controllers count] - 1)]];
            if (nextController != nil) {
                [self _pushController:nextController direction:UIPageViewControllerNavigationDirectionForward targetOffset:targetOffset];
            }
        }
        if (self.contentOffset.x <= 0) {
            UIViewController* nextController =
                [(id<UIPageViewControllerDataSource>)[_viewController dataSource] pageViewController:_viewController
                                                                  viewControllerBeforeViewController:[_controllers objectAtIndex:0]];
            if (nextController != nil) {
                [self _pushController:nextController direction:UIPageViewControllerNavigationDirectionReverse targetOffset:targetOffset];
            }
        }
        // This clears out any view not visible, keeps adjacent
        while ((self.contentOffset.x > 0) && ((self.contentOffset.x + currentFrame.size.width) <
                                              (([_controllers count] * currentFrame.size.width) - currentFrame.size.width))) {
            [self _popControllerWithDirection:UIPageViewControllerNavigationDirectionForward];
        }
        while (((self.contentOffset.x + currentFrame.size.width) < ([_controllers count] * currentFrame.size.width)) &&
               (self.contentOffset.x > currentFrame.size.width)) {
            [self _popControllerWithDirection:UIPageViewControllerNavigationDirectionReverse];
        }
    } else {
        // This clears out any view not visible and adjacent
        while ((self.contentOffset.x + currentFrame.size.width) <=
               (([_controllers count] * currentFrame.size.width) - currentFrame.size.width)) {
            [self _popControllerWithDirection:UIPageViewControllerNavigationDirectionForward];
        }
        while (self.contentOffset.x >= currentFrame.size.width) {
            [self _popControllerWithDirection:UIPageViewControllerNavigationDirectionReverse];
        }
    }
}

- (void)scrollViewDidScroll:(UIScrollView*)scrollView {
    CGPoint targetOffset = self.contentOffset;
    [self _populatePagesWithOffset:&targetOffset interactive:(self.tracking || self.decelerating)];
    [self _updateVisible];
}

@end

@implementation UIPageViewController {
    idretaintype(NSArray) _gestureRecognizers;
    idretaintype(_UIPageViewScrollView) _scrollView;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    return [self initWithTransitionStyle:UIPageViewControllerTransitionStyleScroll
                   navigationOrientation:UIPageViewControllerNavigationOrientationVertical
                                 options:nil];
}

/**
@Status Interoperable
*/
- (NSArray*)gestureRecognizers {
    if (_gestureRecognizers == nil) {
        _gestureRecognizers = [NSArray arrayWithObjects:[_scrollView panGestureRecognizer], nil];
    }
    return _gestureRecognizers;
}

- (NSArray*)viewControllers {
    return [_scrollView _currentPages];
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
- (void)setViewControllers:(NSArray*)viewControllers
                 direction:(UIPageViewControllerNavigationDirection)direction
                  animated:(BOOL)animated
                completion:(void (^)(BOOL finished))completion {
    if (viewControllers == nil) {
        THROW_NS_HR_MSG(E_INVALIDARG, "Parameter viewControllers nil!");
    }

    switch (self.spineLocation) {
        case UIPageViewControllerSpineLocationNone:
        case UIPageViewControllerSpineLocationMin:
        case UIPageViewControllerSpineLocationMax:
            if (self.doubleSided) {
                if (viewControllers.count != 2) {
                    THROW_NS_HR_MSG(E_INVALIDARG, "Doublesided spine type requires 2 UIViewControllers!");
                } else {
                    NSTraceWarning(TAG, @"Double sided transitions not supported. Only first element will be used for transition.");
                    viewControllers = [[NSArray arrayWithObjects:[viewControllers objectAtIndex:0]] autorelease];
                }
            }
            if (viewControllers.count != 1) {
                THROW_NS_HR_MSG(E_INVALIDARG, "Spine type requires 1 UIViewController!");
            }
            break;
        case UIPageViewControllerSpineLocationMid:
            if (viewControllers.count > 2) {
                THROW_NS_HR_MSG(E_INVALIDARG, "Spine type requires 2 UIViewControllers!");
            }
            break;
        default:
            THROW_NS_HR_MSG(E_INVALIDARG, "Parameter 'direction' out of range.");
    }

    for (int i = 0; i < viewControllers.count; i++) {
        id viewController = [viewControllers objectAtIndex:i];
        if ((viewController != nil) && ![viewController isKindOfClass:[UIViewController class]]) {
            THROW_NS_HR_MSG(E_INVALIDARG, "Not all elements in viewControllers conform to UIViewController.");
        }
    }

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
            THROW_NS_HR_MSG(E_INVALIDARG, "Invalid navigation direction.");
    }
}

/**
@Status Interoperable
*/
- (void)setDataSource:(id<UIPageViewControllerDataSource>)dataSource {
    _dataSource = dataSource;
    [_scrollView setScrollEnabled:(self.dataSource != nil)];
    [_scrollView _resetToCurrent];
}

/**
@Status Caveat
@Notes Only single page scroll style transitions supported. Only vertical orientation. Options ignored.
*/
- (instancetype)initWithTransitionStyle:(UIPageViewControllerTransitionStyle)style
                  navigationOrientation:(UIPageViewControllerNavigationOrientation)navigationOrientation
                                options:(NSDictionary*)options {
    // TODO: What happens when someone tries to set the view property? Should we fail out?
    _scrollView = [[_UIPageViewScrollView alloc] _initWithPageViewController:self];

    self.view = [_scrollView retain];

    switch (style) {
        case UIPageViewControllerTransitionStylePageCurl:
            NSTraceWarning(TAG,
                                 @"UIPageViewControllerTransitionStylePageCurl unsupported. Transition style will fall back to Scroll.");
        // Fallthrough
        case UIPageViewControllerTransitionStyleScroll:
            _transitionStyle = style;
            break;
        default:
            THROW_NS_HR_MSG(E_INVALIDARG, "Parameter \"style\" out of range");
    }

    switch (navigationOrientation) {
        case UIPageViewControllerNavigationOrientationHorizontal:
        case UIPageViewControllerNavigationOrientationVertical:
            _navigationOrientation = navigationOrientation;
            break;
        default:
            THROW_NS_HR_MSG(E_INVALIDARG, "Parameter \"navigationOrientation\" out of range");
    }

    if (options != nil) {
        NSTraceWarning(TAG, @"UIPageViewController parameter \"options\" unsupported.");
    }

    // TODO: Should we pull the pan gesture recognizer from UIScrollView?

    return self;
}

@end