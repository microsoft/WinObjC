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

#import <Foundation/Foundation.h>
#import <MessageUI/MessageUIExport.h>
#import <MessageUI/MFMailComposeViewControllerDelegate.h>
#import <UIKit/UINavigationController.h>
#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UIContentContainer.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>

MESSAGEUI_EXPORT NSString* const MFMailComposeErrorDomain;

MESSAGEUI_EXPORT_CLASS
@interface MFMailComposeViewController
    : UINavigationController <NSCoding, NSObject, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>

+ (BOOL)canSendMail;

@property (nonatomic, assign) id<MFMailComposeViewControllerDelegate> mailComposeDelegate;

- (void)setSubject:(NSString*)subject;
- (void)setToRecipients:(NSArray*)toRecipients;
- (void)setMessageBody:(NSString*)body isHTML:(BOOL)isHTML;
- (void)setCcRecipients:(NSArray*)ccRecipients;
- (void)setBccRecipients:(NSArray*)bccRecipients;
- (void)addAttachmentData:(NSData*)attachment mimeType:(NSString*)mimeType fileName:(NSString*)filename;

@end
