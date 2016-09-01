//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <QuickLook/QuickLookExport.h>
#import <Foundation/NSObject.h>
#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UIContentContainer.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UIViewController.h>

@protocol QLPreviewControllerDataSource;
@protocol QLPreviewControllerDelegate;
@protocol QLPreviewItem;

QUICKLOOK_EXPORT_CLASS
@interface QLPreviewController
    : UIViewController <NSCoding, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>
@property (assign) id<QLPreviewControllerDataSource> dataSource STUB_PROPERTY;
@property (assign) id<QLPreviewControllerDelegate> delegate STUB_PROPERTY;
+ (BOOL)canPreviewItem:(id<QLPreviewItem>)item STUB_METHOD;
@property (readonly) id<QLPreviewItem> currentPreviewItem STUB_PROPERTY;
@property NSInteger currentPreviewItemIndex STUB_PROPERTY;
- (void)refreshCurrentPreviewItem STUB_METHOD;
- (void)reloadData STUB_METHOD;

// Conforms to UITraitEnvironment
@property (nonatomic, readonly) UITraitCollection* traitCollection STUB_PROPERTY;

// Conforms to UIFocusEnvironment
@property (nonatomic, assign, readonly) UIView* preferredFocusedView STUB_PROPERTY;
@end
