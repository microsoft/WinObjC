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

#include "ErrorHandling.h"
#import <MessageUI/MFMailComposeViewController.h>

NSString* const MFMailComposeErrorDomain = @"MFMailComposeErrorDomain";

@implementation MFMailComposeViewController
/**
 @Status Stub
 @Notes
*/
+ (BOOL)canSendMail {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
 @Notes
*/
- (void)setSubject:(NSString*)subject {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setToRecipients:(NSArray*)toRecipients {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setCcRecipients:(NSArray*)ccRecipients {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setBccRecipients:(NSArray*)bccRecipients {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setMessageBody:(NSString*)body isHTML:(BOOL)isHTML {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addAttachmentData:(NSData*)attachment mimeType:(NSString*)mimeType fileName:(NSString*)filename {
    UNIMPLEMENTED();
}

@end
