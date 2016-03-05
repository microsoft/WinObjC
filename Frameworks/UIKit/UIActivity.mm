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

#include "Starboard.h"

#import <StubReturn.h>
#import <UIKit/UIActivity.h>

NSString* const UIActivityTypePostToFacebook = @"UIActivityTypePostToFacebook";
NSString* const UIActivityTypePostToTwitter = @"UIActivityTypePostToTwitter";
NSString* const UIActivityTypePostToWeibo = @"UIActivityTypePostToWeibo";
NSString* const UIActivityTypeMessage = @"UIActivityTypeMessage";
NSString* const UIActivityTypeMail = @"UIActivityTypeMail";
NSString* const UIActivityTypePrint = @"UIActivityTypePrint";
NSString* const UIActivityTypeCopyToPasteboard = @"UIActivityTypeCopyToPasteboard";
NSString* const UIActivityTypeAssignToContact = @"UIActivityTypeAssignToContact";
NSString* const UIActivityTypeSaveToCameraRoll = @"UIActivityTypeSaveToCameraRoll";
NSString* const UIActivityTypeAddToReadingList = @"UIActivityTypeAddToReadingList";
NSString* const UIActivityTypePostToFlickr = @"UIActivityTypePostToFlickr";
NSString* const UIActivityTypePostToVimeo = @"UIActivityTypePostToVimeo";
NSString* const UIActivityTypePostToTencentWeibo = @"UIActivityTypePostToTencentWeibo";
NSString* const UIActivityTypeAirDrop = @"UIActivityTypeAirDrop";

@implementation UIActivity

/**
 @Status Stub
 @Notes
*/
+ (UIActivityCategory)activityCategory {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)activityType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)activityTitle {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (UIImage*)activityImage {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)canPerformWithActivityItems:(NSArray*)activityItems {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)prepareWithActivityItems:(NSArray*)activityItems {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (UIViewController*)activityViewController {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)performActivity {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)activityDidFinish:(BOOL)completed {
    UNIMPLEMENTED();
}

@end