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

#import <Security/Security.h>
@class NSString;
@class NSArray;

FOUNDATION_EXPORT NSString* const NSURLProtectionSpaceHTTP;
FOUNDATION_EXPORT NSString* const NSURLProtectionSpaceHTTPS;
FOUNDATION_EXPORT NSString* const NSURLProtectionSpaceFTP;
FOUNDATION_EXPORT NSString* const NSURLProtectionSpaceHTTPProxy;
FOUNDATION_EXPORT NSString* const NSURLProtectionSpaceHTTPSProxy;
FOUNDATION_EXPORT NSString* const NSURLProtectionSpaceFTPProxy;
FOUNDATION_EXPORT NSString* const NSURLProtectionSpaceSOCKSProxy;
FOUNDATION_EXPORT NSString* const NSURLAuthenticationMethodDefault;
FOUNDATION_EXPORT NSString* const NSURLAuthenticationMethodHTTPBasic;
FOUNDATION_EXPORT NSString* const NSURLAuthenticationMethodHTTPDigest;
FOUNDATION_EXPORT NSString* const NSURLAuthenticationMethodHTMLForm;
FOUNDATION_EXPORT NSString* const NSURLAuthenticationMethodNegotiate;
FOUNDATION_EXPORT NSString* const NSURLAuthenticationMethodNTLM;
FOUNDATION_EXPORT NSString* const NSURLAuthenticationMethodClientCertificate;
FOUNDATION_EXPORT NSString* const NSURLAuthenticationMethodServerTrust;

FOUNDATION_EXPORT_CLASS
@interface NSURLProtectionSpace : NSObject <NSCopying, NSSecureCoding>
- (instancetype)initWithHost:(NSString*)host
                        port:(NSInteger)port
                    protocol:(NSString*)protocol
                       realm:(NSString*)realm
        authenticationMethod:(NSString*)authenticationMethod;
- (instancetype)initWithProxyHost:(NSString*)host
                             port:(NSInteger)port
                             type:(NSString*)proxyType
                            realm:(NSString*)realm
             authenticationMethod:(NSString*)authenticationMethod;
@property (readonly, copy) NSString* authenticationMethod;
@property (readonly, copy) NSArray* distinguishedNames;
@property (readonly, copy) NSString* host;
@property (readonly) BOOL isProxy;
@property (readonly) NSInteger port;
@property (readonly, copy) NSString* protocol;
@property (readonly, copy) NSString* proxyType;
@property (readonly, copy) NSString* realm;
@property (readonly) BOOL receivesCredentialSecurely;
@property (readonly) SecTrustRef serverTrust;
@end
