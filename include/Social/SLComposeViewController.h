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

#import <Social/SocialExport.h>

#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UIContentContainer.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UIViewController.h>

@class NSString;
@class UIImage;
@class NSURL;

typedef NS_ENUM(NSInteger, SLComposeViewControllerResult) { SLComposeViewControllerResultCancelled, SLComposeViewControllerResultDone };
typedef void (^SLComposeViewControllerCompletionHandler)(SLComposeViewControllerResult result);

SOCIAL_EXPORT_CLASS
@interface SLComposeViewController
    : UIViewController <NSCoding, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>
+ (SLComposeViewController*)composeViewControllerForServiceType:(NSString*)serviceType;
+ (BOOL)isAvailableForServiceType:(NSString*)serviceType;
- (BOOL)setInitialText:(NSString*)text;
- (BOOL)addImage:(UIImage*)image;
- (BOOL)removeAllImages STUB_METHOD;
- (BOOL)addURL:(NSURL*)url;
- (BOOL)removeAllURLs STUB_METHOD;
@property (readonly, nonatomic) NSString* serviceType STUB_PROPERTY;
@property (copy, nonatomic) SLComposeViewControllerCompletionHandler completionHandler STUB_PROPERTY;
@property (nonatomic, retain, readonly) UIView* preferredFocusedView STUB_PROPERTY;
@property (nonatomic, readonly) UITraitCollection* traitCollection;
@end
