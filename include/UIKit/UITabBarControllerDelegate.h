//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#pragma once

#import <UIKit/UIKitExport.h>
#import <UIKit/UIApplication.h>

@class UITabBarController;
@class UIViewController;
@class NSArray;
@protocol UIViewControllerAnimatedTransitioning;
@protocol UIViewControllerInteractiveTransitioning;

@protocol UITabBarControllerDelegate <NSObject>
@optional
- (BOOL)tabBarController:(UITabBarController*)tabBarController shouldSelectViewController:(UIViewController*)viewController;
- (void)tabBarController:(UITabBarController*)tabBarController didSelectViewController:(UIViewController*)viewController;
- (void)tabBarController:(UITabBarController*)tabBarController willBeginCustomizingViewControllers:(NSArray*)viewControllers;
- (void)tabBarController:(UITabBarController*)tabBarController
    willEndCustomizingViewControllers:(NSArray*)viewControllers
                              changed:(BOOL)changed;
- (void)tabBarController:(UITabBarController*)tabBarController
    didEndCustomizingViewControllers:(NSArray*)viewControllers
                             changed:(BOOL)changed;
- (UIInterfaceOrientationMask)tabBarControllerSupportedInterfaceOrientations:(UITabBarController*)tabBarController;
- (UIInterfaceOrientation)tabBarControllerPreferredInterfaceOrientationForPresentation:(UITabBarController*)tabBarController;
- (id<UIViewControllerAnimatedTransitioning>)tabBarController:(UITabBarController*)tabBarController
           animationControllerForTransitionFromViewController:(UIViewController*)fromVC
                                             toViewController:(UIViewController*)toVC;
- (id<UIViewControllerInteractiveTransitioning>)tabBarController:(UITabBarController*)tabBarController
                     interactionControllerForAnimationController:(id<UIViewControllerAnimatedTransitioning>)animationController;
@end
