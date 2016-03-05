//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
// Copyright (c) 2006-2007 Christopher J. W. Lloyd
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
@class NSArray;
@class NSDictionary;
@class NSURL;
@class NSDate;

FOUNDATION_EXPORT NSString* const NSHTTPCookieComment;
FOUNDATION_EXPORT NSString* const NSHTTPCookieCommentURL;
FOUNDATION_EXPORT NSString* const NSHTTPCookieDiscard;
FOUNDATION_EXPORT NSString* const NSHTTPCookieDomain;
FOUNDATION_EXPORT NSString* const NSHTTPCookieExpires;
FOUNDATION_EXPORT NSString* const NSHTTPCookieMaximumAge;
FOUNDATION_EXPORT NSString* const NSHTTPCookieName;
FOUNDATION_EXPORT NSString* const NSHTTPCookieOriginURL;
FOUNDATION_EXPORT NSString* const NSHTTPCookiePath;
FOUNDATION_EXPORT NSString* const NSHTTPCookiePort;
FOUNDATION_EXPORT NSString* const NSHTTPCookieSecure;
FOUNDATION_EXPORT NSString* const NSHTTPCookieValue;
FOUNDATION_EXPORT NSString* const NSHTTPCookieVersion;

FOUNDATION_EXPORT_CLASS
@interface NSHTTPCookie : NSObject

+ (NSArray*)cookiesWithResponseHeaderFields:(NSDictionary*)headerFields forURL:(NSURL*)theURL;
+ (NSHTTPCookie*)cookieWithProperties:(NSDictionary*)properties;
- (instancetype)initWithProperties:(NSDictionary*)properties;
+ (NSDictionary*)requestHeaderFieldsWithCookies:(NSArray*)cookies;
@property (readonly, copy) NSString* comment;
@property (readonly, copy) NSURL* commentURL;
@property (readonly, copy) NSString* domain;
@property (readonly, copy) NSDate* expiresDate;
@property (readonly, getter=isHTTPOnly) BOOL HTTPOnly;
@property (readonly, getter=isSecure) BOOL secure;
@property (readonly, getter=isSessionOnly) BOOL sessionOnly;
@property (readonly, copy) NSString* name;
@property (readonly, copy) NSString* path;
@property (readonly, copy) NSArray* portList;
@property (readonly, copy) NSDictionary* properties;
@property (readonly, copy) NSString* value;
@property (readonly) NSUInteger version;
@end
