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

@class NSURL;
@class NSDictionary;
@class NSData;
@class NSInputStream;

typedef NSUInteger NSURLRequestCachePolicy;
typedef NSUInteger NSURLRequestNetworkServiceType;
enum {
    NSURLNetworkServiceTypeDefault = 0,
    NSURLNetworkServiceTypeVoIP = 1,
    NSURLNetworkServiceTypeVideo = 2,
    NSURLNetworkServiceTypeBackground = 3,
    NSURLNetworkServiceTypeVoice = 4
};

enum {
    NSURLRequestUseProtocolCachePolicy = 0,
    NSURLRequestReloadIgnoringLocalCacheData = 1,
    NSURLRequestReloadIgnoringLocalAndRemoteCacheData = 4, // Unimplemented
    NSURLRequestReloadIgnoringCacheData = NSURLRequestReloadIgnoringLocalCacheData,
    NSURLRequestReturnCacheDataElseLoad = 2,
    NSURLRequestReturnCacheDataDontLoad = 3,
    NSURLRequestReloadRevalidatingCacheData = 5 // Unimplemented
};

FOUNDATION_EXPORT_CLASS
@interface NSURLRequest : NSObject <NSCopying, NSMutableCopying, NSSecureCoding>
+ (instancetype)requestWithURL:(NSURL*)theURL;
- (instancetype)initWithURL:(NSURL*)theURL;
+ (instancetype)requestWithURL:(NSURL*)theURL
                   cachePolicy:(NSURLRequestCachePolicy)cachePolicy
               timeoutInterval:(NSTimeInterval)timeoutInterval;
- (instancetype)initWithURL:(NSURL*)theURL cachePolicy:(NSURLRequestCachePolicy)cachePolicy timeoutInterval:(NSTimeInterval)timeoutInterval;
@property (readonly) NSURLRequestCachePolicy cachePolicy;
@property (readonly) BOOL HTTPShouldUsePipelining;
@property (readonly, copy) NSURL* mainDocumentURL;
@property (readonly) NSTimeInterval timeoutInterval;
@property (readonly) NSURLRequestNetworkServiceType networkServiceType;
@property (readonly, copy) NSURL* URL;
@property (readonly, copy) NSDictionary* allHTTPHeaderFields;
@property (readonly, copy) NSData* HTTPBody;
@property (readonly, retain) NSInputStream* HTTPBodyStream;
@property (readonly, copy) NSString* HTTPMethod;
@property (readonly) BOOL HTTPShouldHandleCookies;
- (NSString*)valueForHTTPHeaderField:(NSString*)field;
@property (readonly) BOOL allowsCellularAccess;
- (BOOL)supportsSecureCoding;
@end
