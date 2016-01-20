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

#import <Foundation/NSHTTPCookieStorage.h>
#import <Foundation/NSURLRequest.h>
#import <Foundation/NSURLCredentialStorage.h>
#import <Foundation/NSURLCache.h>
#import <Security/SecureTransport.h>

@class NSDictionary, NSObject;

FOUNDATION_EXPORT_CLASS
@interface NSURLSessionConfiguration : NSObject <NSCopying, NSObject>

+ (NSURLSessionConfiguration*)defaultSessionConfiguration;
+ (NSURLSessionConfiguration*)ephemeralSessionConfiguration;
+ (NSURLSessionConfiguration*)backgroundSessionConfigurationWithIdentifier:(NSString*)identifier;
// Deprecated, calls into backgroundSessionConfigurationWithIdentifier
+ (NSURLSessionConfiguration*)backgroundSessionConfiguration:(NSString*)identifier;
@property (readonly, copy) NSString* identifier;
@property (copy) NSDictionary* HTTPAdditionalHeaders;
@property NSURLRequestNetworkServiceType networkServiceType;
@property BOOL allowsCellularAccess;
@property NSTimeInterval timeoutIntervalForRequest;
@property NSTimeInterval timeoutIntervalForResource;
@property (copy) NSString* sharedContainerIdentifier;
@property NSHTTPCookieAcceptPolicy HTTPCookieAcceptPolicy;
@property (retain) NSHTTPCookieStorage* HTTPCookieStorage;
@property BOOL HTTPShouldSetCookies;
@property SSLProtocol TLSMaximumSupportedProtocol;
@property SSLProtocol TLSMinimumSupportedProtocol;
@property (retain) NSURLCredentialStorage* URLCredentialStorage;
@property (retain) NSURLCache* URLCache;
@property NSURLRequestCachePolicy requestCachePolicy;
@property BOOL sessionSendsLaunchEvents;
@property (getter=isDiscretionary) BOOL discretionary;
@property (copy) NSArray* protocolClasses;
@property NSInteger HTTPMaximumConnectionsPerHost;
@property BOOL HTTPShouldUsePipelining;
@property (copy) NSDictionary* connectionProxyDictionary;
@end
