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

#import <StarboardExport.h>
#import <Foundation/NSObject.h>

SB_EXPORT NSString *const UIActivityTypePostToFacebook;
SB_EXPORT NSString *const UIActivityTypePostToTwitter;
SB_EXPORT NSString *const UIActivityTypePostToWeibo;
SB_EXPORT NSString *const UIActivityTypeMessage;
SB_EXPORT NSString *const UIActivityTypeMail;
SB_EXPORT NSString *const UIActivityTypePrint;
SB_EXPORT NSString *const UIActivityTypeCopyToPasteboard;
SB_EXPORT NSString *const UIActivityTypeAssignToContact;
SB_EXPORT NSString *const UIActivityTypeSaveToCameraRoll;

@interface UIActivity : NSObject
@end

#endif /* _UIACTIVITY_H_ */