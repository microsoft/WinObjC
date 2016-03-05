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

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSDictionary;
@class NSArray;

FOUNDATION_EXPORT NSString* const NSLocalizedDescriptionKey;
FOUNDATION_EXPORT NSString* const NSErrorFailingURLStringKey;
FOUNDATION_EXPORT NSString* const NSFilePathErrorKey;
FOUNDATION_EXPORT NSString* const NSStringEncodingErrorKey;
FOUNDATION_EXPORT NSString* const NSUnderlyingErrorKey;
FOUNDATION_EXPORT NSString* const NSURLErrorKey;
FOUNDATION_EXPORT NSString* const NSLocalizedFailureReasonErrorKey;
FOUNDATION_EXPORT NSString* const NSLocalizedRecoverySuggestionErrorKey;
FOUNDATION_EXPORT NSString* const NSLocalizedRecoveryOptionsErrorKey;
FOUNDATION_EXPORT NSString* const NSRecoveryAttempterErrorKey;
FOUNDATION_EXPORT NSString* const NSHelpAnchorErrorKey;
FOUNDATION_EXPORT NSString* const NSURLErrorFailingURLErrorKey;
FOUNDATION_EXPORT NSString* const NSURLErrorFailingURLStringErrorKey;
FOUNDATION_EXPORT NSString* const NSURLErrorFailingURLPeerTrustErrorKey;
FOUNDATION_EXPORT NSString* const NSCocoaErrorDomain;
FOUNDATION_EXPORT NSString* const NSDebugDescriptionKey;

FOUNDATION_EXPORT NSString* const NSPOSIXErrorDomain;
FOUNDATION_EXPORT NSString* const NSOSStatusErrorDomain;
FOUNDATION_EXPORT NSString* const NSMachErrorDomain;
// temporary until we can map it
FOUNDATION_EXPORT NSString* const NSWINSOCKErrorDomain;
FOUNDATION_EXPORT NSString* const NSWin32ErrorDomain;

FOUNDATION_EXPORT_CLASS
@interface NSError : NSObject <NSCopying, NSSecureCoding>
+ (instancetype)errorWithDomain:(NSString*)domain code:(NSInteger)code userInfo:(NSDictionary*)dict;
- (instancetype)initWithDomain:(NSString*)domain code:(NSInteger)code userInfo:(NSDictionary*)dict;
@property (readonly) NSInteger code;
@property (readonly, copy) NSString* domain;
@property (readonly, copy) NSDictionary* userInfo;
@property (readonly, copy) NSString* localizedDescription;
@property (readonly, copy) NSArray* localizedRecoveryOptions;
@property (readonly, copy) NSString* localizedRecoverySuggestion;
@property (readonly, copy) NSString* localizedFailureReason;
@property (readonly, strong) id recoveryAttempter;
@property (readonly, copy) NSString* helpAnchor;
@end

#define STARBOARD_ENOTCONN 57
#define STARBOARD_ECONNREFUSED 61
