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

NSString * const UIPageViewControllerOptionSpineLocationKey = @"SpineLocation";
NSString * const UIPageViewControllerOptionInterPageSpacingKey = @"PageSpacing";

@interface _UIPageViewScrollView : UIScrollView<UIScrollViewDelegate>

- (NSArray *)_currentPages;
- (void)_resetToCurrent;
- (void)_scrollToNewViewController:(UIViewController *)controller direction:(UIPageViewControllerNavigationDirection)direction animated:(BOOL)animated completion:(void (^)(BOOL finished))completion;

@end

@implementation _UIPageViewScrollView {
    idretaintype(UIPageViewController) _viewController;
    idretaintype(NSMutableArray) _controllers;
    idretainp<void (^)(BOOL)> _completion;
    BOOL _keepAdjacent;
    BOOL _skipUpdates;
}

- (instancetype)_initWithPageViewController:(UIPageViewController *)viewController {
    [super init];

    _controllers.attach([NSMutableArray new]);

    // TODO: Multi-page. _controllers will require an array with 6 elements, since we may know about two more views in either direction.
    _viewController = viewController;

    self.delegate = self;

    self.showsHorizontalScrollIndicator = NO;
    self.showsVerticalScrollIndicator = NO;
    self.pagingEnabled = YES;

    return self;
}

- (NSArray *)_currentPages {
    // TODO: Multiple pages
    // TODO: Vertical orientation
    if ([_controllers count] == 0) {
        return nil;
    }

    NSInteger idx = (NSInteger)(self.contentOffset.x / self.frame.size.width + 0.5f);
    if (idx < 0) {
        return [NSArray arrayWithObjects:[_controllers objectAtIndex:0], nil];
    } else if (idx < [_controllers count]) {
        return [NSArray arrayWithObjects:[_controllers objectAtIndex:idx], nil];
    } else {
        return [NSArray arrayWithObjects:[_controllers objectAtIndex:[_controllers count] - 1], nil];
    }
}

- (void)_scrollToNewViewController:(UIViewController *)controller direction:(UIPageViewControllerNavigationDirection)direction animated:(BOOL)animated completion:(void (^)(BOOL finished))completion {
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
                NSLog(@"Parameter 'direction' out of range");
                FAIL_FAST();
        }

        _keepAdjacent = FALSE;
        
        // Completion handler called in scrollViewDidEndScrollingAnimation
    } else {
        CGPoint targetOffset = CGPointMake(0, 0);

        [self setContentOffset:targetOffset animated:NO];
        
        for (int i = 0; i < [_controllers count]; i++) {
            [[(UIViewController *)[_controllers objectAtIndex:i] view] removeFromSuperview];
        }

        _controllers = [NSMutableArray new];

        [self _pushController:controller direction:UIPageViewControllerNavigationDirectionForward targetOffset:&targetOffset];

        if(completion) {
            completion(YES);
        }
    }
}

- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
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

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
    CGPoint targetOffset = self.contentOffset;
    [super touchesEnded:touches withEvent:event];
    [self _populatePagesWithOffset:&targetOffset interactive:NO];
}

- (void)_resetToCurrent {
    _skipUpdates = TRUE;

    NSArray* currentControllers = [self _currentPages];

    // Recenter the view. This will cancel any scroll animations.
    [self setContentOffset:CGPointMake(0, 0) animated:NO];

    for (int i = 0; i < [_controllers count]; i++) {
        [[[_controllers objectAtIndex:i] view] removeFromSuperview];
    }

    if (currentControllers) {
        _controllers = [NSMutableArray arrayWithArray:currentControllers];
    } else {
        _controllers = [NSMutableArray new];
    }

    for (int i = 0; i < [_controllers count]; i++) {
        [self addSubview:[[_controllers objectAtIndex:i] view]];
    }

    _skipUpdates = FALSE;
}

- (void)_pushController:(UIViewController *)controller 
              direction:(UIPageViewControllerNavigationDirection)direction 
           targetOffset:(inout CGPoint *)targetContentOffset {
    switch (direction) {
        case UIPageViewControllerNavigationDirectionForward:
            NSLog(@"Pushing controller forward.");
            [_controllers addObject:controller];
            [self setContentSize:CGSizeMake(self.frame.size.width * [_controllers count], 0)];
            break;
        case UIPageViewControllerNavigationDirectionReverse:
            NSLog(@"Pushing controller reverse.");
            [_controllers insertObject:controller atIndex:0];
            [self setContentSize:CGSizeMake(self.frame.size.width * [_controllers count], 0)];
            [self setContentOffset:CGPointMake(self.contentOffset.x + self.frame.size.width, 0)];
            targetContentOffset->x += self.frame.size.width;
            break;
    }
    [self addSubview:controller.view];
    [self setNeedsLayout];
}

- (void)_popControllerWithDirection:(UIPageViewControllerNavigationDirection)direction {
    UIViewController *controller = nil;

    NSLog(@"Number of pages before pop: %d", [_controllers count]);

    switch (direction) {
        case UIPageViewControllerNavigationDirectionForward:
            NSLog(@"Popping controller forward.");
            controller = [_controllers objectAtIndex:([_controllers count] - 1)];
            [_controllers removeObjectAtIndex:([_controllers count] - 1)];
            [self setContentSize:CGSizeMake(self.frame.size.width * [_controllers count], 0)];
            break;
        case UIPageViewControllerNavigationDirectionReverse:
            NSLog(@"Popping controller reverse.");
            controller = [_controllers objectAtIndex:0];
            [_controllers removeObjectAtIndex:0];
            [self setContentSize:CGSizeMake(self.frame.size.width * [_controllers count], 0)];
            [self setContentOffset:CGPointMake(self.contentOffset.x - self.frame.size.width, 0)];
            break;
    }
    
    // It's possible we have multiple of the same controller, say if we have two looping controllers.
    for (int i = 0; i < [_controllers count]; i++) {
        if ([_controllers objectAtIndex:i] == controller) {
            controller = nil;
        }
    }
    [controller.view removeFromSuperview];
    
    [self setNeedsLayout];
}

- (void)scrollViewWillEndDragging:(UIScrollView *)scrollView withVelocity:(CGPoint)velocity targetContentOffset:(inout CGPoint *)targetContentOffset {
    [self _populatePagesWithOffset:targetContentOffset interactive:YES];
}

- (void)scrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView {
    if (_completion) {
        _completion(!self.tracking);
        _completion = nil;
    }

    // TODO: Call pageViewController:didFinishAnimating:previousViewControllers:transitionCompleted:
    
    CGPoint targetOffset = self.contentOffset;
    [self _populatePagesWithOffset:&targetOffset interactive:NO];
}

- (void)scrollViewDidEndDecelerating:(UIScrollView *)scrollView {
    if (_completion) {
        _completion(!self.tracking);
        _completion = nil;
    }

    // TODO: Call pageViewController:didFinishAnimating:previousViewControllers:transitionCompleted:
    
    CGPoint targetOffset = self.contentOffset;
    [self _populatePagesWithOffset:&targetOffset interactive:NO];
}
 

- (void)layoutSubviews {
    CGRect frame = self.frame;

    // TODO: Vertical layout

    for (int i = 0; i < [_controllers count]; i++) {
        CGFloat pageOrigin = i * self.frame.size.width;
        CGFloat contentOffset = self.contentOffset.x;
        CGFloat contentSpan = self.frame.size.width;
        CGRect childFrame = frame;
        childFrame.origin.y = 0;
        childFrame.origin.x = i * frame.size.width;
        [[[_controllers objectAtIndex:i] view] setFrame:childFrame];
    }

    [super layoutSubviews];
}

- (void)_populatePagesWithOffset:(inout CGPoint *)targetOffset interactive:(BOOL)interactive {
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
            UIViewController* nextController = 
                [(id<UIPageViewControllerDataSource>)[_viewController dataSource] pageViewController:_viewController 
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
        while ((self.contentOffset.x > 0) && ((self.contentOffset.x + currentFrame.size.width) < (([_controllers count] * currentFrame.size.width) - currentFrame.size.width))) {
            [self _popControllerWithDirection:UIPageViewControllerNavigationDirectionForward];
        }
        while (((self.contentOffset.x + currentFrame.size.width) < ([_controllers count] * currentFrame.size.width)) && (self.contentOffset.x > currentFrame.size.width)) {
            [self _popControllerWithDirection:UIPageViewControllerNavigationDirectionReverse];
        }
    } else {
        // This clears out any view not visible and adjacent
        while ((self.contentOffset.x + currentFrame.size.width) <= (([_controllers count] * currentFrame.size.width) - currentFrame.size.width)) {
            [self _popControllerWithDirection:UIPageViewControllerNavigationDirectionForward];
        }
        while (self.contentOffset.x >= currentFrame.size.width) {
            [self _popControllerWithDirection:UIPageViewControllerNavigationDirectionReverse];
        }
    }
}

- (void)scrollViewDidScroll:(UIScrollView *)scrollView {
    CGPoint targetOffset = self.contentOffset;
    [self _populatePagesWithOffset:&targetOffset interactive:(self.tracking || self.decelerating)];
}

@end

@implementation UIPageViewController {
    idretaintype(NSArray) _gestureRecognizers;
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

- (NSArray *)viewControllers {
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
- (instancetype)initWithTransitionStyle:(UIPageViewControllerTransitionStyle)style navigationOrientation:(UIPageViewControllerNavigationOrientation)navigationOrientation options:(NSDictionary *)options {
    // TODO: What happens when someone tries to set the view property? Should we fail out?
    _scrollView = [[_UIPageViewScrollView alloc] _initWithPageViewController:self]; 

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