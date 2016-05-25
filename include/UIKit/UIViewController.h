/*
* Copyright (c) 2011, The Iconfactory. All rights reserved.
*
* Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#pragma once

#include <UIKit/UIKitExport.h>
#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UIContentContainer.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UIResponder.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UISearchDisplayController.h>
#import <UIKit/UITabBarItem.h>
#import <UIKit/UIView.h>

@class NSString, UITabBarController, UIStoryboardSegue, UIStoryboardUnwindSegueSource, UIKeyCommand, NSExtensionContext;
@protocol UILayoutSupport
, UIViewControllerTransitioningDelegate, UIViewControllerPreviewingDelegate, UIViewControllerPreviewing,
    UIViewControllerTransitionCoordinator;

UIKIT_EXPORT NSString* const UIViewControllerHierarchyInconsistencyException;
UIKIT_EXPORT NSString* const UIViewControllerShowDetailTargetDidChangeNotification;

typedef enum UIModalPresentationStyle : NSInteger {
    UIModalPresentationFullScreen = 0,
    UIModalPresentationPageSheet,
    UIModalPresentationFormSheet,
    UIModalPresentationCurrentContext,
    UIModalPresentationCustom,
    UIModalPresentationOverFullScreen,
    UIModalPresentationOverCurrentContext,
    UIModalPresentationPopover,
    UIModalPresentationNone = -1,
} UIModalPresentationStyle;

typedef enum UIModalTransitionStyle : NSInteger {
    UIModalTransitionStyleCoverVertical = 0,
    UIModalTransitionStyleFlipHorizontal,
    UIModalTransitionStyleCrossDissolve,
    UIModalTransitionStylePartialCurl,
} UIModalTransitionStyle;

@class UINavigationItem, UINavigationController, UIBarButtonItem, UISplitViewController, UIStoryboard, UIPresentationController,
    UIPopoverPresentationController;

UIKIT_EXPORT_CLASS
@interface UIViewController
    : UIResponder <NSCoding, NSObject, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>

@property (assign, nonatomic) BOOL definesPresentationContext STUB_PROPERTY;
@property (assign, nonatomic) BOOL modalPresentationCapturesStatusBarAppearance STUB_PROPERTY;
@property (assign, nonatomic) BOOL providesPresentationContextTransitionStyle STUB_PROPERTY;
@property (assign, readwrite, nonatomic) Class restorationClass STUB_PROPERTY;
@property (copy, nonatomic) NSString* restorationIdentifier STUB_PROPERTY;
@property (nonatomic) BOOL automaticallyAdjustsScrollViewInsets;
@property (nonatomic) BOOL extendedLayoutIncludesOpaqueBars;
@property (nonatomic) BOOL hidesBottomBarWhenPushed;
@property (nonatomic) CGSize preferredContentSize;
@property (nonatomic, assign) BOOL wantsFullScreenLayout;
@property (nonatomic, assign) UIModalPresentationStyle modalPresentationStyle;
@property (nonatomic, assign) UIModalTransitionStyle modalTransitionStyle STUB_PROPERTY;
@property (nonatomic, assign) UIRectEdge edgesForExtendedLayout;
@property (nonatomic, copy) NSString* title;
@property (nonatomic, getter=isEditing) BOOL editing;
@property (nonatomic, readonly) NSArray* childViewControllers;
@property (nonatomic, readonly) UIInterfaceOrientation interfaceOrientation; // always returns UIInterfaceOrientationLandscapeLeft
@property (nonatomic, readonly) UIPopoverPresentationController* popoverPresentationController;
@property (nonatomic, readonly) UIPresentationController* presentationController;
@property (nonatomic, readonly) UIViewController* modalViewController;
@property (nonatomic, readonly) UIViewController* parentViewController;
@property (nonatomic, readonly) UIViewController* presentedViewController;
@property (nonatomic, readonly) UIViewController* presentingViewController;
@property (nonatomic, readonly) id<UILayoutSupport> bottomLayoutGuide;
@property (nonatomic, readonly) id<UILayoutSupport> topLayoutGuide;
@property (nonatomic, readonly, retain) NSBundle* nibBundle; // always returns nil
@property (nonatomic, readonly, retain) UINavigationController* navigationController;
@property (nonatomic, readonly, retain) UINavigationItem* navigationItem;
@property (nonatomic, readonly, retain) UISplitViewController* splitViewController;
@property (nonatomic, readonly, retain) UIStoryboard* storyboard;
@property (nonatomic, readonly, retain) UITabBarController* tabBarController;
@property (nonatomic, readwrite) CGSize contentSizeForViewInPopover;
@property (nonatomic, readwrite, getter=isModalInPopover) BOOL modalInPopover;
@property (nonatomic, retain) NSArray* toolbarItems;
@property (nonatomic, retain) UITabBarItem* tabBarItem;
@property (nonatomic, retain) UIView* view;
@property (nonatomic) id<UIViewControllerTransitioningDelegate> transitioningDelegate STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* nibName;
@property (readonly, nonatomic, strong) NSExtensionContext* extensionContext STUB_PROPERTY;
@property (readonly, nonatomic, strong) UISearchDisplayController* searchDisplayController;
@property (readonly, nonatomic, strong) UIView* viewIfLoaded STUB_PROPERTY;

@property (copy) UIBezierPath* accessibilityPath;
@property (nonatomic) CGRect accessibilityFrame;
@property (copy) NSString* accessibilityHint;
@property (copy) NSString* accessibilityIdentifier;
@property (copy) NSString* accessibilityLabel;
@property (copy) NSString* accessibilityValue;
@property (retain) NSString* accessibilityLanguage;
@property BOOL accessibilityElementsHidden;
@property BOOL accessibilityViewIsModal;
@property BOOL isAccessibilityElement;
@property BOOL shouldGroupAccessibilityChildren;
@property CGPoint accessibilityActivationPoint;
@property UIAccessibilityNavigationStyle accessibilityNavigationStyle;
@property UIAccessibilityTraits accessibilityTraits;

+ (UIViewController*)controllerForView:(UIView*)view;
+ (void)attemptRotationToDeviceOrientation STUB_METHOD;
- (BOOL)automaticallyForwardAppearanceAndRotationMethodsToChildViewControllers STUB_METHOD;
- (BOOL)canPerformUnwindSegueAction:(SEL)action fromViewController:(UIViewController*)fromViewController withSender:(id)sender STUB_METHOD;
- (BOOL)disablesAutomaticKeyboardDismissal STUB_METHOD;
- (BOOL)isBeingDismissed STUB_METHOD;
- (BOOL)isBeingPresented STUB_METHOD;
- (BOOL)isMovingFromParentViewController STUB_METHOD;
- (BOOL)isMovingToParentViewController STUB_METHOD;
- (BOOL)isViewLoaded;
- (BOOL)prefersStatusBarHidden STUB_METHOD;
- (BOOL)shouldAutomaticallyForwardAppearanceMethods STUB_METHOD;
- (BOOL)shouldAutomaticallyForwardRotationMethods STUB_METHOD;
- (BOOL)shouldAutorotate;
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation;
- (BOOL)shouldPerformSegueWithIdentifier:(NSString*)identifier sender:(id)sender STUB_METHOD;
- (NSArray*)allowedChildViewControllersForUnwindingFromSource:(UIStoryboardUnwindSegueSource*)source STUB_METHOD;
- (NSArray*)previewActionItems STUB_METHOD;
- (UIInterfaceOrientationMask)supportedInterfaceOrientations;
- (UIBarButtonItem*)editButtonItem;
- (UIInterfaceOrientation)preferredInterfaceOrientationForPresentation;
- (UIStatusBarAnimation)preferredStatusBarUpdateAnimation STUB_METHOD;
- (UIStatusBarStyle)preferredStatusBarStyle STUB_METHOD;
- (UIStoryboardSegue*)segueForUnwindingToViewController:(UIViewController*)toViewController
                                     fromViewController:(UIViewController*)fromViewController
                                             identifier:(NSString*)identifier STUB_METHOD;
- (UITraitCollection*)overrideTraitCollectionForChildViewController:(UIViewController*)childViewController STUB_METHOD;
- (UIView*)rotatingFooterView STUB_METHOD;
- (UIView*)rotatingHeaderView STUB_METHOD;
- (UIViewController*)childViewControllerContainingSegueSource:(UIStoryboardUnwindSegueSource*)source STUB_METHOD;
- (UIViewController*)childViewControllerForStatusBarHidden STUB_METHOD;
- (UIViewController*)childViewControllerForStatusBarStyle STUB_METHOD;
- (UIViewController*)separateSecondaryViewControllerForSplitViewController:(UISplitViewController*)splitViewController STUB_METHOD;
- (UIViewController*)targetViewControllerForAction:(SEL)action sender:(id)sender STUB_METHOD;
- (UIViewController*)viewControllerForUnwindSegueAction:(SEL)action
                                     fromViewController:(UIViewController*)fromViewController
                                             withSender:(id)sender STUB_METHOD;
- (id<UIViewControllerPreviewing>)registerForPreviewingWithDelegate:(id<UIViewControllerPreviewingDelegate>)delegate
                                                         sourceView:(UIView*)sourceView STUB_METHOD;
- (id<UIViewControllerTransitionCoordinator>)transitionCoordinator STUB_METHOD;
- (instancetype)initWithNibName:(NSString*)nibName bundle:(NSBundle*)nibBundle;
- (void)addChildViewController:(UIViewController*)childController;
- (void)addKeyCommand:(UIKeyCommand*)keyCommand STUB_METHOD;
- (void)applicationFinishedRestoringState STUB_METHOD;
- (void)beginAppearanceTransition:(BOOL)isAppearing animated:(BOOL)animated;
- (void)collapseSecondaryViewController:(UIViewController*)secondaryViewController
                 forSplitViewController:(UISplitViewController*)splitViewController STUB_METHOD;
- (void)decodeRestorableStateWithCoder:(NSCoder*)coder;
- (void)didAnimateFirstHalfOfRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation STUB_METHOD;
- (void)didMoveToParentViewController:(UIViewController*)parent;
- (void)didReceiveMemoryWarning;
- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation;
- (void)dismissModalViewControllerAnimated:(BOOL)animated;
- (void)dismissViewControllerAnimated:(BOOL)flag completion:(void (^)(void))completion;
- (void)encodeRestorableStateWithCoder:(NSCoder*)coder;
- (void)endAppearanceTransition;
- (void)loadView;
- (void)loadViewIfNeeded STUB_METHOD;
- (void)performSegueWithDestination:(NSString*)destination sender:(id)sender;
- (void)performSegueWithIdentifier:(NSString*)identifier sender:(id)sender;
- (void)prepareForSegue:(UIStoryboardSegue*)segue sender:(id)sender;
- (void)presentModalViewController:(UIViewController*)modalViewController animated:(BOOL)animated;
- (void)presentViewController:(UIViewController*)viewControllerToPresent animated:(BOOL)flag completion:(void (^)(void))completion;
- (void)removeFromParentViewController;
- (void)removeKeyCommand:(UIKeyCommand*)keyCommand STUB_METHOD;
- (void)setEditing:(BOOL)editing animated:(BOOL)animated;
- (void)setNeedsStatusBarAppearanceUpdate STUB_METHOD;
- (void)setOverrideTraitCollection:(UITraitCollection*)collection forChildViewController:(UIViewController*)childViewController STUB_METHOD;
- (void)setToolbarItems:(NSArray*)toolbarItems animated:(BOOL)animated;
- (void)showDetailViewController:(UIViewController*)vc sender:(id)sender STUB_METHOD;
- (void)showViewController:(UIViewController*)vc sender:(id)sender STUB_METHOD;
- (void)transitionFromViewController:(UIViewController*)fromViewController
                    toViewController:(UIViewController*)toViewController
                            duration:(NSTimeInterval)duration
                             options:(UIViewAnimationOptions)options
                          animations:(void (^)(void))animations
                          completion:(void (^)(BOOL))completion;
- (void)unregisterForPreviewingWithContext:(id<UIViewControllerPreviewing>)previewing STUB_METHOD;
- (void)unwindForSegue:(UIStoryboardSegue*)unwindSegue towardsViewController:(UIViewController*)subsequentVC STUB_METHOD;
- (void)updateViewConstraints;
- (void)viewDidAppear:(BOOL)animated;
- (void)viewDidDisappear:(BOOL)animated;
- (void)viewDidLayoutSubviews;
- (void)viewDidLoad;
- (void)viewDidUnload;
- (void)viewWillAppear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
- (void)viewWillLayoutSubviews;
- (void)viewWillUnload;
- (void)willAnimateFirstHalfOfRotationToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
                                                    duration:(NSTimeInterval)duration;
- (void)willAnimateRotationToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation duration:(NSTimeInterval)duration;
- (void)willAnimateSecondHalfOfRotationFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation
                                                       duration:(NSTimeInterval)duration STUB_METHOD;
- (void)willMoveToParentViewController:(UIViewController*)parent;
- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration;

@end
