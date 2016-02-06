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
#import <UIKit/UISplitViewController.h>
#import <UIKit/UIApplication.h>

@class UISplitViewController;
@class UIViewController;
@class UIBarButtonItem;
@class UIPopoverController;

@protocol UISplitViewControllerDelegate <NSObject>
@optional
- (void)splitViewController:(UISplitViewController*)svc willChangeToDisplayMode:(UISplitViewControllerDisplayMode)displayMode;
- (UISplitViewControllerDisplayMode)targetDisplayModeForActionInSplitViewController:(UISplitViewController*)svc;
- (UIInterfaceOrientation)splitViewControllerPreferredInterfaceOrientationForPresentation:(UISplitViewController*)splitViewController;
- (UIInterfaceOrientationMask)splitViewControllerSupportedInterfaceOrientations:(UISplitViewController*)splitViewController;
- (UIViewController*)primaryViewControllerForCollapsingSplitViewController:(UISplitViewController*)splitViewController;
- (BOOL)splitViewController:(UISplitViewController*)splitViewController
    collapseSecondaryViewController:(UIViewController*)secondaryViewController
          ontoPrimaryViewController:(UIViewController*)primaryViewController;
- (UIViewController*)primaryViewControllerForExpandingSplitViewController:(UISplitViewController*)splitViewController;
- (UIViewController*)splitViewController:(UISplitViewController*)splitViewController
    separateSecondaryViewControllerFromPrimaryViewController:(UIViewController*)primaryViewController;
- (BOOL)splitViewController:(UISplitViewController*)splitViewController showViewController:(UIViewController*)vc sender:(id)sender;
- (BOOL)splitViewController:(UISplitViewController*)splitViewController showDetailViewController:(UIViewController*)vc sender:(id)sender;
- (BOOL)splitViewController:(UISplitViewController*)svc
   shouldHideViewController:(UIViewController*)vc
              inOrientation:(UIInterfaceOrientation)orientation;
- (void)splitViewController:(UISplitViewController*)svc
     willHideViewController:(UIViewController*)aViewController
          withBarButtonItem:(UIBarButtonItem*)barButtonItem
       forPopoverController:(UIPopoverController*)pc;
- (void)splitViewController:(UISplitViewController*)svc
     willShowViewController:(UIViewController*)aViewController
  invalidatingBarButtonItem:(UIBarButtonItem*)button;
- (void)splitViewController:(UISplitViewController*)svc
          popoverController:(UIPopoverController*)pc
  willPresentViewController:(UIViewController*)aViewController;
@end
