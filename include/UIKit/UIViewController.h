/*
* Copyright (c) 2011, The Iconfactory. All rights reserved.
*
* Copyright (c) 2015 Microsoft Corporation. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
* 3. Neither the name of The Iconfactory nor the names of its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE ICONFACTORY BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _UIVIEWCONTROLLER_H_
#define _UIVIEWCONTROLLER_H_

#import "UIResponder.h"
#import "UIApplication.h"
#import "UISearchDisplayController.h"
#import "UITabBarItem.h"
#import "UIView.h"

@class UITabBarController;
@class UIStoryboardSegue;

@protocol UILayoutSupport

/**
 @Status Stub
*/
@property (nonatomic, readonly) CGFloat length;
@end

typedef enum {
    UIModalPresentationFullScreen = 0,
    UIModalPresentationPageSheet,
    UIModalPresentationFormSheet,
    UIModalPresentationCurrentContext,
} UIModalPresentationStyle;

typedef enum {
    UIModalTransitionStyleCoverVertical = 0,
    UIModalTransitionStyleFlipHorizontal,
    UIModalTransitionStyleCrossDissolve,
    UIModalTransitionStylePartialCurl,
} UIModalTransitionStyle;

@class UINavigationItem, UINavigationController, UIBarButtonItem, UISplitViewController, UIStoryboard;

UIKIT_EXPORT_CLASS
@interface UIViewController : UIResponder <NSCoding>

+ (UIViewController*)controllerForView:(UIView*)view;

- (id)initWithNibName:(NSString*)nibName bundle:(NSBundle*)nibBundle; // won't load a nib no matter what you do!

- (BOOL)isViewLoaded;
- (void)loadView;
- (void)viewDidLoad;
- (void)viewDidUnload;

- (void)viewWillAppear:(BOOL)animated;
- (void)viewDidAppear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
- (void)viewDidDisappear:(BOOL)animated;

@property (nonatomic, readonly) id<UILayoutSupport> topLayoutGuide;
@property (nonatomic, readonly) id<UILayoutSupport> bottomLayoutGuide;
- (void)viewWillLayoutSubviews;
- (void)viewDidLayoutSubviews;
- (void)updateViewConstraints;

- (void)presentModalViewController:(UIViewController*)modalViewController animated:(BOOL)animated; // works, but not exactly correctly.
- (void)dismissModalViewControllerAnimated:(BOOL)animated; // see comments in dismissModalViewController

- (void)didReceiveMemoryWarning; // doesn't do anything and is never called...

- (void)setToolbarItems:(NSArray*)toolbarItems animated:(BOOL)animated;
- (void)setEditing:(BOOL)editing animated:(BOOL)animated;
- (UIBarButtonItem*)editButtonItem; // not implemented

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;
- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration;
- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation duration:(NSTimeInterval)duration;
- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation;

- (void)performSegueWithIdentifier:(NSString*)identifier sender:(id)sender;
- (void)performSegueWithDestination:(NSString*)destination sender:(id)sender;

- (void)dismissViewControllerAnimated:(BOOL)flag completion:(void (^)(void))completion;

- (void)presentViewController:(UIViewController*)viewControllerToPresent animated:(BOOL)flag completion:(void (^)(void))completion;
- (void)addChildViewController:(UIViewController*)childController;
- (void)didMoveToParentViewController:(UIViewController*)parent;
- (UIInterfaceOrientation)preferredInterfaceOrientationForPresentation;
- (NSUInteger)supportedInterfaceOrientations;
- (BOOL)shouldAutorotate;

@property (nonatomic) CGSize preferredContentSize;
- (void)willMoveToParentViewController:(UIViewController*)parent;
- (void)removeFromParentViewController;

- (void)willAnimateFirstHalfOfRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
                                                    duration:(NSTimeInterval)duration;

- (void)encodeRestorableStateWithCoder:(NSCoder*)coder;
- (void)decodeRestorableStateWithCoder:(NSCoder*)coder;

- (void)beginAppearanceTransition:(BOOL)isAppearing animated:(BOOL)animated;
- (void)endAppearanceTransition;
- (BOOL)isBeingDismissed;
- (void)prepareForSegue:(UIStoryboardSegue*)segue sender:(id)sender;
- (void)setNeedsStatusBarAppearanceUpdate;

@property (nonatomic, readonly, copy) NSString* nibName; // always returns nil
@property (nonatomic, readonly, retain) NSBundle* nibBundle; // always returns nil
@property (nonatomic, retain) UIView* view;
@property (nonatomic, assign) BOOL wantsFullScreenLayout; // doesn't do anything right now
@property (nonatomic, copy) NSString* title;
@property (nonatomic, readonly) UIInterfaceOrientation interfaceOrientation; // always returns UIInterfaceOrientationLandscapeLeft
@property (nonatomic, readonly, retain) UINavigationItem* navigationItem;
@property (nonatomic, retain) NSArray* toolbarItems;
@property (nonatomic, getter=isEditing) BOOL editing;
@property (nonatomic) BOOL hidesBottomBarWhenPushed;

@property (nonatomic, readwrite) CGSize contentSizeForViewInPopover;
@property (nonatomic, readwrite, getter=isModalInPopover) BOOL modalInPopover;

@property (nonatomic, readonly) UIViewController* modalViewController;
@property (nonatomic, assign) UIModalPresentationStyle modalPresentationStyle;
@property (nonatomic, assign) UIModalTransitionStyle modalTransitionStyle; // not used right now

@property (nonatomic, readonly) UIViewController* parentViewController;
@property (nonatomic, readonly, retain) UINavigationController* navigationController;
@property (nonatomic, readonly, retain) UISplitViewController* splitViewController;
@property (nonatomic, readonly, retain) UISearchDisplayController* searchDisplayController; // stub

// stubs
@property (nonatomic, retain) UITabBarItem* tabBarItem;
@property (nonatomic, readonly, retain) UITabBarController* tabBarController;

@property (nonatomic, readonly) UIViewController* presentedViewController;
@property (nonatomic, readonly) UIViewController* presentingViewController;

@property (nonatomic, readonly, retain) UIStoryboard* storyboard;
@property (nonatomic, readonly) NSArray* childViewControllers;

@property (nonatomic, assign) UIRectEdge edgesForExtendedLayout;

@property (nonatomic) BOOL automaticallyAdjustsScrollViewInsets;
@property (nonatomic) BOOL extendedLayoutIncludesOpaqueBars;

@end

UIKIT_EXPORT NSString* const UITransitionContextFromViewControllerKey;
UIKIT_EXPORT NSString* const UITransitionContextToViewControllerKey;

@protocol UIViewControllerContextTransitioning
- (UIView*)containerView;
- (UIViewController*)viewControllerForKey:(NSString*)key;
- (void)completeTransition:(BOOL)animated;
@end

@protocol UIViewControllerAnimatedTransitioning
@end

#endif /* _UIVIEWCONTROLLER_H_ */
