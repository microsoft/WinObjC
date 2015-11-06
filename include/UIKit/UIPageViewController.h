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

#ifndef _UIPAGEVIEWCONTROLLER_H_
#define _UIPAGEVIEWCONTROLLER_H_

#import <Foundation/NSObject.h>
#import <UIKit/UIViewController.h>

enum {
    UIPageViewControllerNavigationDirectionForward,
    UIPageViewControllerNavigationDirectionReverse,
};
typedef int32_t UIPageViewControllerNavigationDirection;

enum {
    UIPageViewControllerTransitionStylePageCurl = 0,
    UIPageViewControllerTransitionStyleScroll = 1,
};
typedef int32_t UIPageViewControllerTransitionStyle;

enum {
    UIPageViewControllerNavigationOrientationHorizontal = 0,
    UIPageViewControllerNavigationOrientationVertical = 1,
};
typedef int32_t UIPageViewControllerNavigationOrientation;

UIKIT_EXPORT_CLASS
@protocol UIPageViewControllerDataSource <NSObject>
@end

UIKIT_EXPORT_CLASS
@protocol UIPageViewControllerDelegate <NSObject>
@optional
@end

UIKIT_EXPORT_CLASS
@interface UIPageViewController : UIViewController

@property (nonatomic, assign) id<UIPageViewControllerDataSource> dataSource;
@property (nonatomic, assign) id<UIPageViewControllerDelegate> delegate;
@property (nonatomic, readonly) NSArray* gestureRecognizers;
@property (nonatomic, readonly) NSArray* viewControllers;

- (void)setViewControllers:(NSArray*)viewControllers
                 direction:(UIPageViewControllerNavigationDirection)direction
                  animated:(BOOL)animated
                completion:(void (^)(BOOL finished))completion;
- (id)initWithTransitionStyle:(UIPageViewControllerTransitionStyle)style
        navigationOrientation:(UIPageViewControllerNavigationOrientation)navigationOrientation
                      options:(NSDictionary*)options;

@end

#endif /* _UIPAGEVIEWCONTROLLER_H_ */