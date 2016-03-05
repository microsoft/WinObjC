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

#import <Twitter/TwitterExport.h>
#import <UIKit/UIViewController.h>

@class NSString;
@class UIImage;
@class NSURL;
@protocol UIContentContainer;
@protocol UIFocusEnvironment;
@protocol UITraitEnvironment;

enum TWTweetComposeViewControllerResult { TWTweetComposeViewControllerResultCancelled, TWTweetComposeViewControllerResultDone };
typedef enum TWTweetComposeViewControllerResult TWTweetComposeViewControllerResult;
typedef void (^TWTweetComposeViewControllerCompletionHandler)(TWTweetComposeViewControllerResult result);

TWITTER_EXPORT_CLASS
@interface TWTweetComposeViewController
    : UIViewController <NSCoding, NSObject, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>
+ (BOOL)canSendTweet STUB_METHOD;
- (BOOL)setInitialText:(NSString*)text STUB_METHOD;
- (BOOL)addImage:(UIImage*)image STUB_METHOD;
- (BOOL)addURL:(NSURL*)url STUB_METHOD;
- (BOOL)removeAllImages STUB_METHOD;
- (BOOL)removeAllURLs STUB_METHOD;
@property (copy, nonatomic) TWTweetComposeViewControllerCompletionHandler completionHandler STUB_PROPERTY;
@end
