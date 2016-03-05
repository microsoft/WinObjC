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
#import <UIKit/UINavigationController.h>
#import <UIKit/UIImagePickerController.h>
#import <Foundation/Foundation.h>

@class NSString;
@protocol UIVideoEditorControllerDelegate;
@protocol UINavigationControllerDelegate;

UIKIT_EXPORT_CLASS
@interface UIVideoEditorController
    : UINavigationController <NSCoding, NSObject, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>
+ (BOOL)canEditVideoAtPath:(NSString*)videoPath STUB_METHOD;
@property (assign, nonatomic) id<UINavigationControllerDelegate, UIVideoEditorControllerDelegate> delegate STUB_PROPERTY;
@property (nonatomic) NSTimeInterval videoMaximumDuration STUB_PROPERTY;
@property (copy, nonatomic) NSString* videoPath STUB_PROPERTY;
@property (nonatomic) UIImagePickerControllerQualityType videoQuality STUB_PROPERTY;
@end
