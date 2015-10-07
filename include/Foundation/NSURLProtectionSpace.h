/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <Foundation/NSObject.h>
#import <Security/Security.h>

SB_EXPORT const NSString *NSURLAuthenticationMethodDefault;
SB_EXPORT const NSString *NSURLAuthenticationMethodHTTPBasic;
SB_EXPORT const NSString *NSURLAuthenticationMethodHTTPDigest;
SB_EXPORT const NSString *NSURLAuthenticationMethodHTMLForm;
SB_EXPORT const NSString *NSURLAuthenticationMethodNegotiate;
SB_EXPORT const NSString *NSURLAuthenticationMethodNTLM;
SB_EXPORT const NSString *NSURLAuthenticationMethodClientCertificate;
SB_EXPORT const NSString *NSURLAuthenticationMethodServerTrust;

SB_EXPORT const NSString *NSURLProtectionSpaceHTTPProxy;
SB_EXPORT const NSString *NSURLProtectionSpaceHTTPSProxy;
SB_EXPORT const NSString *NSURLProtectionSpaceFTPProxy;
SB_EXPORT const NSString *NSURLProtectionSpaceSOCKSProxy;

@interface NSURLProtectionSpace : NSObject <NSCopying>

-initWithHost:(NSString *)host port:(int)port protocol:(NSString *)protocol realm:(NSString *)realm authenticationMethod:(NSString *)authenticationMethod;
-initWithProxyHost:(NSString *)host port:(int)port protocol:(NSString *)protocol realm:(NSString *)realm authenticationMethod:(NSString *)authenticationMethod;
-(id)initWithProxyHost:(NSString *)host port:(NSInteger)port type:(NSString *)proxyType realm:(NSString *)realm authenticationMethod:(NSString *)authenticationMethod;

-(NSString *)host;
-(int)port;
-(NSString *)protocol;
-(NSString *)realm;
-(NSString *)authenticationMethod;

-(NSString *)proxyType;

-(BOOL)receivesCredentialsSecurely;
-(BOOL)isProxy;

-(SecTrustRef)serverTrust;

@end
