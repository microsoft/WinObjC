//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef _UIACTIVITY_H_
#define _UIACTIVITY_H_

#import <UIKit/UIKitExport.h>
#import <Foundation/NSObject.h>

UIKIT_EXPORT NSString* const UIActivityTypePostToFacebook;
UIKIT_EXPORT NSString* const UIActivityTypePostToTwitter;
UIKIT_EXPORT NSString* const UIActivityTypePostToWeibo;
UIKIT_EXPORT NSString* const UIActivityTypeMessage;
UIKIT_EXPORT NSString* const UIActivityTypeMail;
UIKIT_EXPORT NSString* const UIActivityTypePrint;
UIKIT_EXPORT NSString* const UIActivityTypeCopyToPasteboard;
UIKIT_EXPORT NSString* const UIActivityTypeAssignToContact;
UIKIT_EXPORT NSString* const UIActivityTypeSaveToCameraRoll;
UIKIT_EXPORT NSString* const UIActivityTypeAirDrop;

UIKIT_EXPORT_CLASS
@interface UIActivity : NSObject

- (void)activityDidFinish:(BOOL)finished;

@end

#endif /* _UIACTIVITY_H_ */
