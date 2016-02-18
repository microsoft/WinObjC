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

#import <Social/SocialExport.h>
#import <Foundation/NSObject.h>

@class NSData;
@class NSHTTPURLResponse;
@class NSError;
@class NSString;
@class NSURL;
@class NSDictionary;
@class ACAccount;
@class NSURLRequest;

typedef void (^SLRequestHandler)(NSData* responseData, NSHTTPURLResponse* urlResponse, NSError* error);

typedef NS_ENUM(NSInteger, SLRequestMethod) {
    SLRequestMethodGET,
    SLRequestMethodPOST,
    SLRequestMethodDELETE,
    SLRequestMethodPUT,
};

SOCIAL_EXPORT NSString* const SLServiceTypeFacebook;
SOCIAL_EXPORT NSString* const SLServiceTypeTwitter;
SOCIAL_EXPORT NSString* const SLServiceTypeSinaWeibo;
SOCIAL_EXPORT NSString* const SLServiceTypeTencentWeibo;

SOCIAL_EXPORT_CLASS
@interface SLRequest : NSObject
+ (SLRequest*)requestForServiceType:(NSString*)serviceType
                      requestMethod:(SLRequestMethod)requestMethod
                                URL:(NSURL*)url
                         parameters:(NSDictionary*)parameters STUB_METHOD;
- (void)performRequestWithHandler:(SLRequestHandler)handler STUB_METHOD;
- (NSURLRequest*)preparedURLRequest STUB_METHOD;
- (void)addMultipartData:(NSData*)data withName:(NSString*)name type:(NSString*)type filename:(NSString*)filename STUB_METHOD;
@property (retain, nonatomic) ACAccount* account STUB_PROPERTY;
@property (readonly, nonatomic) SLRequestMethod requestMethod STUB_PROPERTY;
@property (readonly, nonatomic) NSURL* URL STUB_PROPERTY;
@property (readonly, nonatomic) NSDictionary* parameters STUB_PROPERTY;
@end
