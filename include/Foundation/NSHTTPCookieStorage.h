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

@class NSURL;
@class NSHTTPCookie;
@class NSArray;

typedef enum {
    NSHTTPCookieAcceptPolicyAlways,
    NSHTTPCookieAcceptPolicyNever,
    NSHTTPCookieAcceptPolicyOnlyFromMainDocumentDomain
} NSHTTPCookieAcceptPolicy;

FOUNDATION_EXPORT const NSString* NSHTTPCookieManagerCookiesChangedNotification;
FOUNDATION_EXPORT const NSString* NSHTTPCookieManagerAcceptPolicyChangedNotification;

FOUNDATION_EXPORT_CLASS
@interface NSHTTPCookieStorage : NSObject {
    id _cookies;
    id _lock;
    id _lastModification;
    NSHTTPCookieAcceptPolicy _cookieAcceptPolicy;
    id _timer;
    BOOL _touched;
}

- (id)initWithStorageLocation:(NSURL*)storageFileURL STUB_METHOD;
+ (NSHTTPCookieStorage*)sharedHTTPCookieStorage;
@property NSHTTPCookieAcceptPolicy cookieAcceptPolicy;
- (void)deleteCookie:(NSHTTPCookie*)aCookie;
- (void)setCookie:(NSHTTPCookie*)aCookie;
- (void)setCookies:(NSArray*)cookies forURL:(NSURL*)theURL mainDocumentURL:(NSURL*)mainDocumentURL;
@property (readonly, copy) NSArray* cookies;
- (NSArray*)cookiesForURL:(NSURL*)theURL;
- (NSArray*)sortedCookiesUsingDescriptors:(NSArray*)sortOrder STUB_METHOD;
@end
