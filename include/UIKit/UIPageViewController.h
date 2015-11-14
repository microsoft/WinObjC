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

#import "UIKitExport.h"

#import <Foundation/Foundation.h>
#import <UIKit/UIViewController.h>

typedef NS_ENUM(NSInteger, UIPageViewControllerNavigationDirection) {
    UIPageViewControllerNavigationDirectionForward,
    UIPageViewControllerNavigationDirectionReverse
};

typedef NS_ENUM(NSInteger, UIPageViewControllerTransitionStyle) {
    UIPageViewControllerTransitionStylePageCurl = 0,
    UIPageViewControllerTransitionStyleScroll = 1
};

typedef NS_ENUM(NSInteger, UIPageViewControllerNavigationOrientation) {
    UIPageViewControllerNavigationOrientationHorizontal = 0,
    UIPageViewControllerNavigationOrientationVertical = 1
};

typedef NS_ENUM(NSInteger, UIPageViewControllerSpineLocation) {
    UIPageViewControllerSpineLocationNone = 0,
    UIPageViewControllerSpineLocationMin = 1,
    UIPageViewControllerSpineLocationMid = 2,
    UIPageViewControllerSpineLocationMax = 3
};

UIKIT_EXPORT extern NSString* const UIPageViewControllerOptionSpineLocationKey;
UIKIT_EXPORT extern NSString* const UIPageViewControllerOptionInterPageSpacingKey;

@class UIPageViewController;

UIKIT_EXPORT_CLASS
@protocol UIPageViewControllerDataSource <NSObject>

- (UIViewController*)pageViewController:(UIPageViewController*)pageViewController 
     viewControllerBeforeViewController:(UIViewController*)viewController;
- (UIViewController*)pageViewController:(UIPageViewController*)pageViewController 
      viewControllerAfterViewController:(UIViewController*)viewController;

@optional
- (NSInteger)presentationCountForPageViewController:(UIPageViewController*)pageViewController;
- (NSInteger)presentationIndexForPageViewController:(UIPageViewController*)pageViewController;

@end

UIKIT_EXPORT_CLASS
@protocol UIPageViewControllerDelegate <NSObject>

@optional
- (void)pageViewController:(UIPageViewController*)pageViewController willTransitionToViewControllers:(NSArray*)pendingViewControllers;
- (void)pageViewController:(UIPageViewController*)pageViewController 
        didFinishAnimating:(BOOL)finished 
   previousViewControllers:(NSArray*)previousViewControllers 
       transitionCompleted:(BOOL)completed;
- (UIPageViewControllerSpineLocation)pageViewController:(UIPageViewController*)pageViewController 
                   spineLocationForInterfaceOrientation:(UIInterfaceOrientation)orientation;
- (UIInterfaceOrientationMask)pageViewControllerSupportedInterfaceOrientations:(UIPageViewController*)pageViewController;
- (UIInterfaceOrientation)pageViewControllerPreferredInterfaceOrientationForPresentation:(UIPageViewController*)pageViewController;

@end

UIKIT_EXPORT_CLASS
@interface UIPageViewController : UIViewController

@property (nonatomic, assign) id<UIPageViewControllerDataSource> dataSource;
@property (nonatomic, assign) id<UIPageViewControllerDelegate> delegate;
@property (nonatomic, readonly) NSArray* gestureRecognizers;
@property (nonatomic, readonly) NSArray* viewControllers;
@property (nonatomic, readonly) UIPageViewControllerNavigationOrientation navigationOrientation;
@property (nonatomic, readonly) UIPageViewControllerSpineLocation spineLocation;
@property (nonatomic, readonly) UIPageViewControllerTransitionStyle transitionStyle;
@property (nonatomic, getter=isDoubleSided) BOOL doubleSided;

- (void)setViewControllers:(NSArray*)viewControllers
                 direction:(UIPageViewControllerNavigationDirection)direction
                  animated:(BOOL)animated
                completion:(void (^)(BOOL finished))completion;
- (instancetype)initWithTransitionStyle:(UIPageViewControllerTransitionStyle)style
                  navigationOrientation:(UIPageViewControllerNavigationOrientation)navigationOrientation
                                options:(NSDictionary*)options;
                      
@end

#endif /* _UIPAGEVIEWCONTROLLER_H_ */