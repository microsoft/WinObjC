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
#import <Foundation/NSObject.h>
#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UIContentContainer.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UIViewControllerAnimatedTransitioning.h>
#import <UIKit/UIViewControllerTransitioningDelegate.h>
#import <UIKit/UIViewController.h>

@class UISearchBar;
@protocol UISearchResultsUpdating;
@protocol UISearchControllerDelegate;

UIKIT_EXPORT_CLASS
@interface UISearchController : UIViewController <NSCoding,
                                                  NSObject,
                                                  UIAppearanceContainer,
                                                  UIContentContainer,
                                                  UIFocusEnvironment,
                                                  UITraitEnvironment,
                                                  UIViewControllerAnimatedTransitioning,
                                                  UIViewControllerTransitioningDelegate>
- (instancetype)initWithSearchResultsController:(UIViewController*)searchResultsController STUB_METHOD;
@property (readonly, nonatomic, strong) UISearchBar* searchBar STUB_PROPERTY;
@property (nonatomic) id<UISearchResultsUpdating> searchResultsUpdater STUB_PROPERTY;
@property (readonly, nonatomic, strong) UIViewController* searchResultsController STUB_PROPERTY;
@property (getter=isActive, assign, nonatomic) BOOL active STUB_PROPERTY;
@property (assign, nonatomic) BOOL obscuresBackgroundDuringPresentation STUB_PROPERTY;
@property (assign, nonatomic) BOOL dimsBackgroundDuringPresentation STUB_PROPERTY;
@property (assign, nonatomic) BOOL hidesNavigationBarDuringPresentation STUB_PROPERTY;
@property (nonatomic) id<UISearchControllerDelegate> delegate STUB_PROPERTY;
@end
