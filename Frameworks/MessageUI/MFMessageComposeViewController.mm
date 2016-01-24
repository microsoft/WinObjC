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
#import <MessageUI/MFMessageComposeViewController.h>

NSString* const MFMessageComposeViewControllerTextMessageAvailabilityKey = @"MFMessageComposeViewControllerTextMessageAvailabilityKey";
NSString* const MFMessageComposeViewControllerAttachmentURL = @"MFMessageComposeViewControllerAttachmentURL";
NSString* const MFMessageComposeViewControllerAttachmentAlternateFilename = @"MFMessageComposeViewControllerAttachmentAlternateFilename";

@implementation MFMessageComposeViewController
/**
 @Status Stub
 @Notes
*/
+ (BOOL)canSendText {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)canSendAttachments {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)canSendSubject {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)isSupportedAttachmentUTI:(NSString*)uti {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)addAttachmentURL:(NSURL*)attachmentURL withAlternateFilename:(NSString*)alternateFilename {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)addAttachmentData:(NSData*)attachmentData typeIdentifier:(NSString*)uti filename:(NSString*)filename {
    UNIMPLEMENTED();
    return NO;
}

/**
 @Status Stub
 @Notes
*/
- (void)disableUserAttachments {
    UNIMPLEMENTED();
}

@end
