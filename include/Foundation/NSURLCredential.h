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

typedef NS_ENUM(NSUInteger, NSURLCredentialPersistence) {
    NSURLCredentialPersistenceNone,
    NSURLCredentialPersistenceForSession,
    NSURLCredentialPersistencePermanent,
    NSURLCredentialPersistenceSynchronizable
};

FOUNDATION_EXPORT_CLASS
@interface NSURLCredential : NSObject <NSCopying, NSSecureCoding>
+ (NSURLCredential*)credentialForTrust:(SecTrustRef)trust;
+ (NSURLCredential*)credentialWithUser:(NSString*)user password:(NSString*)password persistence:(NSURLCredentialPersistence)persistence;
+ (NSURLCredential*)credentialWithIdentity:(SecIdentityRef)identity
                              certificates:(NSArray*)certArray
                               persistence:(NSURLCredentialPersistence)persistence;
- (instancetype)initWithIdentity:(SecIdentityRef)identity
                    certificates:(NSArray*)certArray
                     persistence:(NSURLCredentialPersistence)persistence;
- (instancetype)initWithTrust:(SecTrustRef)trust;
- (instancetype)initWithUser:(NSString*)user password:(NSString*)password persistence:(NSURLCredentialPersistence)persistence;
@property (readonly, copy) NSString* user;
@property (readonly, copy) NSArray* certificates;
@property (readonly) BOOL hasPassword;
@property (readonly, copy) NSString* password;
@property (readonly) SecIdentityRef identity;
@property (readonly) NSURLCredentialPersistence persistence;
@end
