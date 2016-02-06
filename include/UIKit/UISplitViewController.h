/*
 * Copyright (c) 2011, The Iconfactory. All rights reserved.
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

#import <UIKit/UIKitExport.h>
#import <Foundation/NSObject.h>
#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UIContentContainer.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UIViewController.h>

@class NSArray;
@class UIBarButtonItem;
@protocol UISplitViewControllerDelegate;

typedef enum UISplitViewControllerDisplayMode : NSInteger {
    UISplitViewControllerDisplayModeAutomatic,
    UISplitViewControllerDisplayModePrimaryHidden,
    UISplitViewControllerDisplayModeAllVisible,
    UISplitViewControllerDisplayModePrimaryOverlay,
} UISplitViewControllerDisplayMode;

UIKIT_EXPORT const CGFloat UISplitViewControllerAutomaticDimension;

UIKIT_EXPORT_CLASS
@interface UISplitViewController
    : UIViewController <NSCoding, NSObject, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>
@property (copy, nonatomic) NSArray* viewControllers STUB_PROPERTY;
@property (nonatomic) BOOL presentsWithGesture STUB_PROPERTY;
@property (nonatomic) UISplitViewControllerDisplayMode preferredDisplayMode STUB_PROPERTY;
@property (readonly, nonatomic) UISplitViewControllerDisplayMode displayMode STUB_PROPERTY;
- (UIBarButtonItem*)displayModeButtonItem STUB_METHOD;
@property (readonly, getter=isCollapsed, nonatomic) BOOL collapsed STUB_PROPERTY;
@property (assign, nonatomic) CGFloat preferredPrimaryColumnWidthFraction STUB_PROPERTY;
@property (readonly, nonatomic) CGFloat primaryColumnWidth STUB_PROPERTY;
@property (assign, nonatomic) CGFloat minimumPrimaryColumnWidth STUB_PROPERTY;
@property (assign, nonatomic) CGFloat maximumPrimaryColumnWidth STUB_PROPERTY;
@property (nonatomic) id<UISplitViewControllerDelegate> delegate STUB_PROPERTY;
- (void)showDetailViewController:(UIViewController*)vc sender:(id)sender STUB_METHOD;
- (void)showViewController:(UIViewController*)vc sender:(id)sender STUB_METHOD;
@end
