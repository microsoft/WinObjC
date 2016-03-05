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

#import <Twitter/TwitterExport.h>
#import <Foundation/NSObject.h>

@class NSData;
@class NSHTTPURLResponse;
@class NSError;
@class NSURL;
@class NSDictionary;
@class ACAccount;
@class NSString;
@class NSURLRequest;

enum TWRequestMethod { TWRequestMethodGET, TWRequestMethodPOST, TWRequestMethodDELETE };
typedef enum TWRequestMethod TWRequestMethod;
typedef void (^TWRequestHandler)(NSData* responseData, NSHTTPURLResponse* urlResponse, NSError* error);

TWITTER_EXPORT_CLASS
@interface TWRequest : NSObject <NSObject>
- (id)initWithURL:(NSURL*)url parameters:(NSDictionary*)parameters requestMethod:(TWRequestMethod)requestMethod STUB_METHOD;
@property (retain, nonatomic) ACAccount* account STUB_PROPERTY;
@property (readonly, nonatomic) TWRequestMethod requestMethod STUB_PROPERTY;
@property (readonly, nonatomic) NSURL* URL STUB_PROPERTY;
@property (readonly, nonatomic) NSDictionary* parameters STUB_PROPERTY;
- (void)addMultiPartData:(NSData*)data withName:(NSString*)name type:(NSString*)type STUB_METHOD;
- (void)performRequestWithHandler:(TWRequestHandler)handler STUB_METHOD;
- (NSURLRequest*)signedURLRequest STUB_METHOD;
@end
