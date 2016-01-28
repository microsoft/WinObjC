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
#pragma once

#ifndef IBAction
#define IBAction void
#endif

#ifndef IBOutlet
#define IBOutlet
#endif
#import <UIKit/UIApplicationDelegate.h>
#import <UIKit/UIScreen.h>
#import <UIKit/UIGeometry.h>
#import <UIKit/UIGraphics.h>
#import <UIKit/UIEvent.h>
#import <UIKit/UIResponder.h>
#import <UIKit/UIImage.h>
#import <UIKit/UIColor.h>
#import <UIKit/UICoordinateSpace.h>
#import <UIKit/UIView.h>
#import <UIKit/UIWindow.h>
#import <UIKit/UITouch.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UIInterface.h>
#import <UIKit/UIImageView.h>
#import <UIKit/UIScrollView.h>
#import <UIKit/UITableView.h>
#import <UIKit/UITableViewCell.h>
#import <UIKit/UIFont.h>
#import <UIKit/UILabel.h>
#import <UIKit/UIStringDrawing.h>
#import <UIKit/UIDevice.h>
#import <UIKit/UIAccessibility.h>
#import <UIKit/UIAccessibilityElement.h>
#import <UIKit/UIControl.h>
#import <UIKit/UIButton.h>
#import <UIKit/UIBezierPath.h>
#import <UIKit/UIViewController.h>
#import <UIKit/UIScreenMode.h>
#import <UIKit/UIActionSheet.h>
#import <UIKit/UIAlertView.h>
#import <UIKit/UITextField.h>
#import <UIKit/UINavigationItem.h>
#import <UIKit/UINavigationController.h>
#import <UIKit/UIBarItem.h>
#import <UIKit/UIBarButtonItem.h>
#import <UIKit/UIPasteboard.h>
#import <UIKit/UITextInputTraits.h>
#import <UIKit/UIWebView.h>
#import <UIKit/UIToolbar.h>
#import <UIKit/UITabBar.h>
#import <UIKit/UITabBarItem.h>
#import <UIKit/UISegmentedControl.h>
#import <UIKit/UIActivityIndicatorView.h>
#import <UIKit/UIPopoverController.h>
#import <UIKit/UIPopoverPresentationController.h>
#import <UIKit/UINavigationBar.h>
#import <UIKit/UITextView.h>
#import <UIKit/UIDataDetectors.h>
#import <UIKit/UITableViewController.h>
#import <UIKit/UISearchBar.h>
#import <UIKit/UISearchDisplayController.h>
#import <UIKit/UIImagePickerController.h>
#import <UIKit/UINibLoading.h>
#import <UIKit/UIGestureRecognizer.h>
#import <UIKit/UITapGestureRecognizer.h>
#import <UIKit/UILongPressGestureRecognizer.h>
#import <UIKit/UISplitViewController.h>
#import <UIKit/UITabBarController.h>
#import <UIKit/UISwitch.h>
#import <UIKit/UISlider.h>
#import <UIKit/UIAcceleration.h>
#import <UIKit/UIAccelerometer.h>
#import <UIKit/UIMenuController.h>
#import <UIKit/UIMenuItem.h>
#import <UIKit/UIViewAdapter.h>
#import <UIKit/UIPageControl.h>
#import <UIKit/UIProgressView.h>
#import <UIKit/UIPickerView.h>
#import <UIKit/UIPanGestureRecognizer.h>
#import <UIKit/UIPinchGestureRecognizer.h>
#import <UIKit/UIRotationGestureRecognizer.h>
#import <UIKit/UISwipeGestureRecognizer.h>
#import <UIKit/UIDatePicker.h>
#import <UIKit/UIAppearance.h>
#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UIUserNotificationSettings.h>
#import <UIKit/UIDocument.h>
#import <UIKit/UIManagedDocument.h>
#import <UIKit/UIStoryboardSegue.h>
#import <UIKit/UIStepper.h>
#import <UIKit/UIContentContainer.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>

// non-standard imports
#import <UIKit/UIKey.h>
#import <UIKit/UIScrollWheelGestureRecognizer.h>

// only add if core data is included on 10.6
//#import <UIKit/NSFetchedResultsController.h>

#import <UIKit/NSAttributedString+UIKitAdditions.h>
#import <UIKit/NSMutableAttributedString+UIKitAdditions.h>
#import <UIKit/NSText.h>
#import <UIKit/NSParagraphStyle.h>
#import <UIKit/UILocalNotification.h>
#import <UIKit/UILocalizedIndexedCollation.h>
#import <UIKit/UIStoryboard.h>
#import <UIKit/UINib.h>
#import <UIKit/UITextPosition.h>
#import <UIKit/UITextInput.h>
#import <UIKit/UIActivity.h>
#import <UIKit/UIActivityItemProvider.h>
#import <UIKit/UIActivityViewController.h>
#import <UIKit/UIRefreshControl.h>
#import <UIKit/UITableViewHeaderFooterView.h>
#import <UIKit/UIPageViewController.h>
#import <UIKit/UIPrintInteractionController.h>
#import <UIKit/NSLayoutConstraint.h>
#import <UIKit/UIPageViewController.h>
#import <UIKit/UICollectionViewCommon.h>
#import <UIKit/UICollectionView.h>
#import <UIKit/UICollectionViewController.h>
#import <UIKit/UICollectionViewCell.h>
#import <UIKit/NSStringDrawing.h>
#import <UIKit/UICollectionViewLayout.h>
#import <UIKit/UICollectionViewFlowLayout.h>
#import <UIKit/UIDynamicAnimator.h>
#import <UIKit/UIDynamicBehavior.h>
#import <UIKit/UIDynamicItem.h>
#import <UIkit/UIAttachmentBehavior.h>
#import <UIKit/UIDocumentInteractionController.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UIMotionEffect.h>
#import <UIKit/UIPrintInfo.h>
#import <UIKit/UIPrintFormatter.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UIContentContainer.h>
#import <UIKit/NSLayoutManager.h>
#import <UIKit/NSTextStorage.h>