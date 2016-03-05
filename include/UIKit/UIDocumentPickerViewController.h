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
#import <UIKit/UIViewController.h>

@class NSArray;
@class NSURL;
@protocol UIDocumentPickerDelegate;

typedef NS_ENUM(NSUInteger, UIDocumentPickerMode) {
    UIDocumentPickerModeImport,
    UIDocumentPickerModeOpen,
    UIDocumentPickerModeExportToService,
    UIDocumentPickerModeMoveToService,
};

UIKIT_EXPORT_CLASS
@interface UIDocumentPickerViewController
    : UIViewController <NSCoding, NSObject, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>
- (instancetype)initWithDocumentTypes:(NSArray*)allowedUTIs inMode:(UIDocumentPickerMode)mode STUB_METHOD;
- (instancetype)initWithURL:(NSURL*)url inMode:(UIDocumentPickerMode)mode STUB_METHOD;
@property (nonatomic) id<UIDocumentPickerDelegate> delegate STUB_PROPERTY;
@property (readonly, assign, nonatomic) UIDocumentPickerMode documentPickerMode STUB_PROPERTY;
@end
