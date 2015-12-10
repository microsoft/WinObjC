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
#import <Security/Security.h>

FOUNDATION_EXPORT NSString* NSURLAuthenticationMethodDefault;
FOUNDATION_EXPORT NSString* NSURLAuthenticationMethodHTTPBasic;
FOUNDATION_EXPORT NSString* NSURLAuthenticationMethodHTTPDigest;
FOUNDATION_EXPORT NSString* NSURLAuthenticationMethodHTMLForm;
FOUNDATION_EXPORT NSString* NSURLAuthenticationMethodNegotiate;
FOUNDATION_EXPORT NSString* NSURLAuthenticationMethodNTLM;
FOUNDATION_EXPORT NSString* NSURLAuthenticationMethodClientCertificate;
FOUNDATION_EXPORT NSString* NSURLAuthenticationMethodServerTrust;

FOUNDATION_EXPORT NSString* NSURLProtectionSpaceHTTPProxy;
FOUNDATION_EXPORT NSString* NSURLProtectionSpaceHTTPSProxy;
FOUNDATION_EXPORT NSString* NSURLProtectionSpaceFTPProxy;
FOUNDATION_EXPORT NSString* NSURLProtectionSpaceSOCKSProxy;

FOUNDATION_EXPORT NSString* const NSURLProtectionSpaceHTTP;
FOUNDATION_EXPORT NSString* const NSURLProtectionSpaceHTTPS;
FOUNDATION_EXPORT NSString* const NSURLProtectionSpaceFTP;

FOUNDATION_EXPORT_CLASS
@interface NSURLProtectionSpace : NSObject <NSCoding, NSCopying>

- initWithHost:(NSString*)host
                    port:(NSInteger)port
                protocol:(NSString*)protocol
                   realm:(NSString*)realm
    authenticationMethod:(NSString*)authenticationMethod;

- initWithProxyHost:(NSString*)host
                    port:(NSInteger)port
                    type:(NSString*)proxyType
                   realm:(NSString*)realm
    authenticationMethod:(NSString*)authenticationMethod;
- (BOOL)isProxy;
@property (readonly, copy) NSString* authenticationMethod;
@property (readonly, copy) NSArray* distinguishedNames;
@property (readonly, copy) NSString* host;
@property (readonly) NSInteger port;
@property (readonly, copy) NSString* protocol;
@property (readonly, copy) NSString* realm;
@property (readonly, copy) NSString* proxyType;
@property (readonly) BOOL receivesCredentialSecurely;
@property (readonly) SecTrustRef serverTrust;
@end
