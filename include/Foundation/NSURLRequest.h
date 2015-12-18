/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <Foundation/NSObject.h>
#import <Foundation/NSDate.h>

@class NSURL, NSInputStream, NSMutableDictionary;

typedef NS_ENUM(NSUInteger, NSURLRequestCachePolicy) {
    NSURLRequestUseProtocolCachePolicy = 0,
    NSURLRequestReloadIgnoringLocalCacheData = 1,
    NSURLRequestReloadIgnoringCacheData = 1,
    NSURLRequestReturnCacheDataElseLoad = 2,
    NSURLRequestReturnCacheDataDontLoad = 3,
    NSURLRequestReloadIgnoringLocalAndRemoteCacheData = 4,
    NSURLRequestReloadRevalidatingCacheData = 5
};

typedef NS_ENUM(NSUInteger, NSURLRequestNetworkServiceType) {
    NSURLNetworkServiceTypeDefault = 0,
    NSURLNetworkServiceTypeVoIP = 1,
    NSURLNetworkServiceTypeVideo = 2,
    NSURLNetworkServiceTypeBackground = 3,
    NSURLNetworkServiceTypeVoice = 4
};

FOUNDATION_EXPORT_CLASS
@interface NSURLRequest : NSObject <NSCopying, NSSecureCoding, NSMutableCopying>

- (instancetype)initWithURL:(NSURL*)theURL;
- (instancetype)initWithURL:(NSURL*)theURL cachePolicy:(NSURLRequestCachePolicy)cachePolicy timeoutInterval:(NSTimeInterval)timeoutInterval;

+ (instancetype)requestWithURL:(NSURL*)theURL;
+ (instancetype)requestWithURL:(NSURL*)theURL
                   cachePolicy:(NSURLRequestCachePolicy)cachePolicy
               timeoutInterval:(NSTimeInterval)timeoutInterval;

@property (readonly, copy) NSURL* URL;
@property (readonly) NSURLRequestCachePolicy cachePolicy;
@property (readonly) NSTimeInterval timeoutInterval;
@property (readonly, copy) NSURL* mainDocumentURL;
@property (readonly) NSURLRequestNetworkServiceType networkServiceType;
@property (readonly) BOOL HTTPShouldUsePipelining;

@property (readonly, copy) NSString* HTTPMethod;
@property (readonly, copy) NSData* HTTPBody;
@property (readonly, retain) NSInputStream* HTTPBodyStream;
@property (readonly, copy) NSDictionary* allHTTPHeaderFields;
@property (readonly) BOOL HTTPShouldHandleCookies;
@property (readonly) BOOL allowsCellularAccess;

- (NSString*)valueForHTTPHeaderField:(NSString*)field;

@end
