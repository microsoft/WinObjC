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

typedef enum : NSInteger {
    UIActivityCategoryAction,
    UIActivityCategoryShare,
} UIActivityCategory;

UIKIT_EXPORT NSString* const UIActivityTypePostToFacebook;
UIKIT_EXPORT NSString* const UIActivityTypePostToTwitter;
UIKIT_EXPORT NSString* const UIActivityTypePostToWeibo;
UIKIT_EXPORT NSString* const UIActivityTypeMessage;
UIKIT_EXPORT NSString* const UIActivityTypeMail;
UIKIT_EXPORT NSString* const UIActivityTypePrint;
UIKIT_EXPORT NSString* const UIActivityTypeCopyToPasteboard;
UIKIT_EXPORT NSString* const UIActivityTypeAssignToContact;
UIKIT_EXPORT NSString* const UIActivityTypeSaveToCameraRoll;
UIKIT_EXPORT NSString* const UIActivityTypeAddToReadingList;
UIKIT_EXPORT NSString* const UIActivityTypePostToFlickr;
UIKIT_EXPORT NSString* const UIActivityTypePostToVimeo;
UIKIT_EXPORT NSString* const UIActivityTypePostToTencentWeibo;
UIKIT_EXPORT NSString* const UIActivityTypeAirDrop;

@class UIViewController;
@class UIImage;

UIKIT_EXPORT_CLASS
@interface UIActivity : NSObject
+ (UIActivityCategory)activityCategory STUB_METHOD;
- (NSString*)activityType STUB_METHOD;
- (NSString*)activityTitle STUB_METHOD;
- (UIImage*)activityImage STUB_METHOD;
- (BOOL)canPerformWithActivityItems:(NSArray*)activityItems STUB_METHOD;
- (void)prepareWithActivityItems:(NSArray*)activityItems STUB_METHOD;
- (UIViewController*)activityViewController STUB_METHOD;
- (void)performActivity STUB_METHOD;
- (void)activityDidFinish:(BOOL)completed STUB_METHOD;
@end
