//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
<<<<<<< HEAD
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************
=======
/*
 * Copyright (c) 2011, The Iconfactory. All rights reserved.
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
>>>>>>> d4c53ec... Stub all missing methods and classes in Metal library
#pragma once

#import <MessageUI/MessageUIExport.h>
#import <MessageUI/MFMessageComposeViewControllerDelegate.h>
#import <UIKit/UINavigationController.h>

@class NSString;
@class NSArray;
@class NSURL;
@class NSData;

MESSAGEUI_EXPORT NSString* const MFMessageComposeViewControllerTextMessageAvailabilityKey;
MESSAGEUI_EXPORT NSString* const MFMessageComposeViewControllerAttachmentURL;
MESSAGEUI_EXPORT NSString* const MFMessageComposeViewControllerAttachmentAlternateFilename;

typedef NS_ENUM(NSUInteger, MessageComposeResult) {
    MessageComposeResultCancelled,
    MessageComposeResultSent,
    MessageComposeResultFailed
};

MESSAGEUI_EXPORT_CLASS
@interface MFMessageComposeViewController : UINavigationController <NSCoding, UIAppearanceContainer>

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

@protocol MFMessageComposeViewControllerDelegate <NSObject>

- (void)messageComposeViewController:(MFMessageComposeViewController *)controller didFinishWithResult:(MessageComposeResult)result;

@end
