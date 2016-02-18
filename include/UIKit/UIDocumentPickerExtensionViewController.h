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
#import <UIKit/UIDocumentPickerViewController.h>

@class NSURL;
@class NSString;
@class NSArray;

UIKIT_EXPORT_CLASS
@interface UIDocumentPickerExtensionViewController
    : UIViewController <NSCoding, NSObject, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>
- (void)dismissGrantingAccessToURL:(NSURL*)url STUB_METHOD;
@property (readonly, assign, nonatomic) UIDocumentPickerMode documentPickerMode STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSURL* documentStorageURL STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSURL* originalURL STUB_PROPERTY;
- (void)prepareForPresentationInMode:(UIDocumentPickerMode)mode STUB_METHOD;
@property (readonly, copy, nonatomic) NSString* providerIdentifier STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* validTypes STUB_PROPERTY;
@end
