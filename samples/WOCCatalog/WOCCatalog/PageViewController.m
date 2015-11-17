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

#import <Foundation/Foundation.h>
#import "PageViewController.h"

static const int c_numControllers = 3;

@interface PageViewController () <UIPageViewControllerDataSource, UIPageViewControllerDelegate>
- (void)_forward;
- (void)_reverse;
@end

@interface PageViewPage : UIViewController

- (instancetype)initwithIndex:(NSUInteger)idx controller:(UIPageViewController*)controller;

- (NSUInteger)index;

@end

@implementation PageViewPage {
    NSUInteger _index;
    UIPageViewController* _controller;
}

- (instancetype)initwithIndex:(NSUInteger)idx controller:(UIPageViewController*)controller {
    _index = idx;
    _controller = controller;
    return [self init];
}

- (void)viewDidLoad {
    UILabel* label = [UILabel new];
    
    self.view = [UIView new];
    self.view.backgroundColor = [UIColor whiteColor];
    self.view.autoresizesSubviews = YES;

    [label setText:[NSString stringWithFormat:@"Page %lu", (unsigned long)[self index]]];
    label.frame = CGRectMake(0, 200, self.view.frame.size.width, 25);
    label.textAlignment = NSTextAlignmentCenter;
    label.autoresizingMask = UIViewAutoresizingFlexibleWidth;

// TODO: Bar button items.   
#ifdef WINOBJC
    UIButton* forwardButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    UIButton* reverseButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    
    forwardButton.frame = CGRectMake(self.view.frame.size.width - 75, 100, 50, 50);
    reverseButton.frame = CGRectMake(50, 100, 50, 50);
    forwardButton.autoresizingMask = UIViewAutoresizingFlexibleLeftMargin;
    
    [forwardButton setTitle:@">>" forState:UIControlStateNormal];
    [reverseButton setTitle:@"<<" forState:UIControlStateNormal];
    
    [forwardButton addTarget:_controller action:@selector(_forward) forControlEvents:UIControlEventTouchUpInside];
    [reverseButton addTarget:_controller action:@selector(_reverse) forControlEvents:UIControlEventTouchUpInside];
    
    [self.view addSubview:forwardButton];
    [self.view addSubview:reverseButton];
#endif
    
    [self.view addSubview:label];
}

- (NSUInteger)index {
    return _index;
}

@end

@implementation PageViewController {
    NSMutableArray* _controllers;
}

- (instancetype)init {
    return [self initWithTransitionStyle:UIPageViewControllerTransitionStyleScroll navigationOrientation:UIPageViewControllerNavigationOrientationHorizontal options:nil];
}

- (UIViewController*)pageViewController:(UIPageViewController *)pageViewController viewControllerBeforeViewController:(UIViewController *)viewController {
    NSUInteger idx = [(PageViewPage*)viewController index];
    
    idx = ((idx + c_numControllers - 1) % c_numControllers);
    
    return [_controllers objectAtIndex:idx];
}

- (UIViewController*)pageViewController:(UIPageViewController *)pageViewController viewControllerAfterViewController:(UIViewController *)viewController {
    NSUInteger idx = [(PageViewPage*)viewController index];
    
    idx = ((idx + 1) % c_numControllers);
    
    return [_controllers objectAtIndex:idx];
}

- (void)viewDidLoad {
    _controllers = [NSMutableArray new];
    
    for (int i = 0; i < c_numControllers; i++) {
        UIViewController* pageController = [[PageViewPage alloc] initwithIndex:i controller:self];
        [_controllers addObject:pageController];
    }

    [self setViewControllers:[NSArray arrayWithObjects:[_controllers objectAtIndex:0], nil]
                   direction:UIPageViewControllerNavigationDirectionForward
                    animated:NO
                  completion:nil];

// TODO: Re-enable when feature complete    
#ifndef WINOBJC
    [self setDelegate:self];
    [self setDataSource:self];
#endif
    
// TODO: Bar button items.
#ifndef WINOBJC
    UIBarButtonItem* forward = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFastForward target:self action:@selector(_forward)];
    UIBarButtonItem* reverse = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemRewind target:self action:@selector(_reverse)];
    
    self.navigationItem.rightBarButtonItems = [NSArray arrayWithObjects:forward, reverse, nil];
#endif
    
    self.view.backgroundColor = [UIColor grayColor];
}

- (void)_forward {
    NSUInteger idx = [(PageViewPage*)[self.viewControllers objectAtIndex:0] index];
    
    idx = ((idx + 1) % c_numControllers);
    
    [self setViewControllers:[NSArray arrayWithObjects:[_controllers objectAtIndex:idx], nil] direction:UIPageViewControllerNavigationDirectionForward animated:YES completion:nil];
}

- (void)_reverse {
    NSUInteger idx = [(PageViewPage*)[self.viewControllers objectAtIndex:0] index];
    
    idx = ((idx + c_numControllers - 1) % c_numControllers);
    
    [self setViewControllers:[NSArray arrayWithObjects:[_controllers objectAtIndex:idx], nil] direction:UIPageViewControllerNavigationDirectionReverse animated:YES completion:nil];
}

- (void)pageViewController:(UIPageViewController *)pageViewController willTransitionToViewControllers:(NSArray *)pendingViewControllers {
    PageViewPage* pageFrom = (PageViewPage*)[pageViewController.viewControllers objectAtIndex:0];
    PageViewPage* pageTo = (PageViewPage*)[pendingViewControllers objectAtIndex:0];
    NSLog(@"Will transition from page %lu to page %lu.", (unsigned long)pageFrom.index, (unsigned long)pageTo.index);
}

- (NSInteger)presentationCountForPageViewController:(UIPageViewController *)pageViewController {
    return _controllers.count;
}

- (NSInteger)presentationIndexForPageViewController:(UIPageViewController *)pageViewController {
    return [(PageViewPage *)[self.viewControllers objectAtIndex:0] index];
}

- (void)pageViewController:(UIPageViewController *)pageViewController
        didFinishAnimating:(BOOL)finished
   previousViewControllers:(NSArray *)previousViewControllers
       transitionCompleted:(BOOL)completed {
    PageViewPage* pageFrom = (PageViewPage*)[previousViewControllers objectAtIndex:0];
    PageViewPage* pageTo = (PageViewPage*)[pageViewController.viewControllers objectAtIndex:0];
    NSString* finishedString;
    NSString* completedString;
    
    if (finished) {
        finishedString = @"finished";
    } else {
        finishedString = @"didn't finish";
    }
    
    if (completed) {
        completedString = @"completed";
    } else {
        completedString = @"didn't complete";
    }
    
    NSLog(@"Transition from page %lu to page %lu %@, and the animation %@.",
          (unsigned long)pageFrom.index, (unsigned long)pageTo.index, completedString, finishedString);
}

@end