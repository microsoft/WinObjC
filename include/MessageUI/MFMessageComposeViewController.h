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

#import <MessageUI/MessageUIExport.h>
#import <MessageUI/MFMessageComposeViewControllerDelegate.h>
#import <UIKit/UINavigationController.h>
#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UIContentContainer.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>

@class NSString;
@class NSArray;
@class NSURL;
@class NSData;

MESSAGEUI_EXPORT NSString* const MFMessageComposeViewControllerTextMessageAvailabilityKey;
MESSAGEUI_EXPORT NSString* const MFMessageComposeViewControllerAttachmentURL;
MESSAGEUI_EXPORT NSString* const MFMessageComposeViewControllerAttachmentAlternateFilename;

MESSAGEUI_EXPORT_CLASS
@interface MFMessageComposeViewController
    : UINavigationController <NSCoding, NSObject, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>

+ (BOOL)canSendText;
+ (BOOL)canSendAttachments;
+ (BOOL)canSendSubject;
+ (BOOL)isSupportedAttachmentUTI:(NSString*)uti;

@property (nonatomic, assign) id<MFMessageComposeViewControllerDelegate> messageComposeDelegate;
@property (nonatomic, copy) NSArray* recipients;
@property (nonatomic, copy) NSString* subject;
@property (nonatomic, copy) NSString* body;
@property (readonly, copy, nonatomic) NSArray* attachments;

- (BOOL)addAttachmentURL:(NSURL*)attachmentURL withAlternateFilename:(NSString*)alternateFilename;
- (BOOL)addAttachmentData:(NSData*)attachmentData typeIdentifier:(NSString*)uti filename:(NSString*)filename;
- (void)disableUserAttachments;

@end
