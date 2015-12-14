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

#import <Starboard.h>
#import <Windows.h>
#import <Foundation/NSURLCredential.h>

@interface NSURLCredential ()
@property (readwrite, copy) NSString* user;
@property (readwrite, copy) NSArray* certificates;
@property (readwrite, copy) NSString* password;
@property (readwrite) SecIdentityRef identity;
@property (readwrite) NSURLCredentialPersistence persistence;
@property (readwrite) SecTrustRef trust;
@end

@implementation NSURLCredential

/**
 @Status Interoperable
*/
+ (NSURLCredential*)credentialWithUser:(NSString*)user password:(NSString*)password persistence:(NSURLCredentialPersistence)persistence {
    return [[[NSURLCredential alloc] initWithUser:user password:password persistence:persistence] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSURLCredential*)credentialWithIdentity:(SecIdentityRef)identity
                              certificates:(NSArray*)certArray
                               persistence:(NSURLCredentialPersistence)persistence {
    return [[[NSURLCredential alloc] initWithIdentity:identity certificates:certArray persistence:persistence] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSURLCredential*)credentialForTrust:(SecTrustRef)trust {
    return [[[NSURLCredential alloc] initWithTrust:trust] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithIdentity:(SecIdentityRef)identity
                    certificates:(NSArray*)certArray
                     persistence:(NSURLCredentialPersistence)persistence {
    if (self = [self _initWithPersistence:persistence]) {
        _identity = identity;
        _certificates = [certArray copy];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithTrust:(SecTrustRef)trust {
    if (self = [super init]) {
        _trust = trust;
    }
    return self;
}

/**
 @Status Interoperable
*/
- (BOOL)hasPassword {
    return (_password != nil);
}

- (instancetype)_initWithPersistence:(NSURLCredentialPersistence)persistence {
    if (self = [super init]) {
        _persistence = persistence;
    }
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithUser:(NSString*)user password:(NSString*)password persistence:(NSURLCredentialPersistence)persistence {
    if (self = [self _initWithPersistence:persistence]) {
        _user = [user copy];
        _password = [password copy];
    }

    return self;
}

- (id)copyWithZone:(NSZone*)zone {
    NSURLCredential* copy = [[self class] allocWithZone:zone];
    if (copy != nil) {
        copy.user = _user;
        copy.password = _password;
        copy.persistence = _persistence;
        copy.certificates = _certificates;
        copy.identity = _identity;
        copy.trust = _trust;
    }

    return copy;
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeObject:_user forKey:@"user"];
    [coder encodeObject:_password forKey:@"password"];
    [coder encodeInt64:_persistence forKey:@"persistence"];
    [coder encodeObject:_certificates forKey:@"certificates"];
}

/**
 @Status Caveat
 @Notes Does not support encoding/decoding of SecTrustRef and SecIdentityRef.
*/
- (id)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        _user = [[coder decodeObjectForKey:@"user"] retain];
        _password = [[coder decodeObjectForKey:@"password"] retain];
        _persistence = (NSURLCredentialPersistence)[coder decodeInt64ForKey:@"persistence"];
        _certificates = [[coder decodeObjectForKey:@"certificates"] retain];
        // TODO: Implement encoding/decoding for SecTrustRef and when security apis are implemented.
    }
    return self;
}

- (void)dealloc {
    [_user release];
    [_password release];
    [_certificates release];
    [super dealloc];
}
@end