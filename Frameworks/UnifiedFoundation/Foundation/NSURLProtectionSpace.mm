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
#import <Foundation/NSURLProtectionSpace.h>

@interface NSURLProtectionSpace ()
@property (readwrite, copy) NSString* authenticationMethod;
@property (readwrite, copy) NSArray* distinguishedNames;
@property (readwrite, copy) NSString* host;
@property (readwrite) NSInteger port;
@property (readwrite, copy) NSString* protocol;
@property (readwrite, copy) NSString* realm;
@property (readwrite, copy) NSString* proxyType;
@property (readwrite) BOOL receivesCredentialSecurely;
@property (readwrite) SecTrustRef serverTrust;
@end

@interface NSURLProtectionSpace () {
    volatile NSUInteger _hashCode;
}
@end

NSString* NSURLAuthenticationMethodDefault = @"NSURLAuthenticationMethodDefault";
NSString* NSURLAuthenticationMethodHTTPBasic = @"NSURLAuthenticationMethodHTTPBasic";
NSString* NSURLAuthenticationMethodHTTPDigest = @"NSURLAuthenticationMethodHTTPDigest";
NSString* NSURLAuthenticationMethodHTMLForm = @"NSURLAuthenticationMethodHTMLForm";
NSString* NSURLAuthenticationMethodNegotiate = @"NSURLAuthenticationMethodNegotiate";
NSString* NSURLAuthenticationMethodNTLM = @"NSURLAuthenticationMethodNTLM";
NSString* NSURLAuthenticationMethodClientCertificate = @"NSURLAuthenticationMethodClientCertificate";
NSString* NSURLAuthenticationMethodServerTrust = @"NSURLAuthenticationMethodServerTrust";

NSString* NSURLProtectionSpaceHTTPProxy = @"NSURLProtectionSpaceHTTPProxy";
NSString* NSURLProtectionSpaceHTTPSProxy = @"NSURLProtectionSpaceHTTPSProxy";
NSString* NSURLProtectionSpaceFTPProxy = @"NSURLProtectionSpaceFTPProxy";
NSString* NSURLProtectionSpaceSOCKSProxy = @"NSURLProtectionSpaceSOCKSProxy";

NSString* const NSURLProtectionSpaceHTTP = @"NSURLProtectionSpaceHTTP";
NSString* const NSURLProtectionSpaceHTTPS = @"NSURLProtectionSpaceHTTPS";
NSString* const NSURLProtectionSpaceFTP = @"NSURLProtectionSpaceFTP";

@implementation NSURLProtectionSpace

/**
 @Status Interoperable
*/
- (instancetype)initWithHost:(NSString*)host
                        port:(NSInteger)port
                    protocol:(NSString*)protocol
                       realm:(NSString*)realm
        authenticationMethod:(NSString*)authenticationMethod {
    if (self = [self _initWithHost:host port:port realm:realm authenticationMethod:authenticationMethod]) {
        _protocol = [protocol copy];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithProxyHost:(NSString*)host
                             port:(NSInteger)port
                             type:(NSString*)proxyType
                            realm:(NSString*)realm
             authenticationMethod:(NSString*)authenticationMethod {
    if (self = [self _initWithHost:host port:port realm:realm authenticationMethod:authenticationMethod]) {
        _proxyType = [proxyType copy];
    }

    return self;
}

- (instancetype)_initWithHost:(NSString*)host
                         port:(NSInteger)port
                        realm:(NSString*)realm
         authenticationMethod:(NSString*)authenticationMethod {
    if (self = [super init]) {
        _host = [host copy];
        _port = port;
        _realm = [realm copy];
        _authenticationMethod = (authenticationMethod == nil ? NSURLAuthenticationMethodDefault : [authenticationMethod copy]);
    }

    return self;
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    NSURLProtectionSpace* copy = [[self class] allocWithZone:zone];
    if (copy != nil) {
        copy.authenticationMethod = _authenticationMethod;
        copy.distinguishedNames = _distinguishedNames;
        copy.host = _host;
        copy.port = _port;
        copy.protocol = _protocol;
        copy.realm = _realm;
        copy.proxyType = _proxyType;
        copy.receivesCredentialSecurely = _receivesCredentialSecurely;
        copy.serverTrust = _serverTrust;
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
    [coder encodeObject:_authenticationMethod forKey:@"authenticationMethod"];
    [coder encodeObject:_distinguishedNames forKey:@"distinguishedNames"];
    [coder encodeObject:_host forKey:@"host"];
    [coder encodeInt64:_port forKey:@"port"];
    [coder encodeObject:_protocol forKey:@"protocol"];
    [coder encodeObject:_realm forKey:@"realm"];
    [coder encodeObject:_proxyType forKey:@"proxyType"];
    [coder encodeBool:_receivesCredentialSecurely forKey:@"receivesCredentialSecurely"];
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(id)anObject {
    if (self == anObject) {
        return YES;
    }
    if ((!anObject) || (![anObject isKindOfClass:[self class]])) {
        return NO;
    }

    NSURLProtectionSpace* object = (NSURLProtectionSpace*)anObject;

    if (![_authenticationMethod isEqual:object.authenticationMethod]) {
        return NO;
    }

    if (![_protocol isEqualToString:object.protocol]) {
        return NO;
    }

    if (![_distinguishedNames isEqualToArray:object.distinguishedNames]) {
        return NO;
    }

    if (![_realm isEqualToString:object.realm]) {
        return NO;
    }

    if (![_proxyType isEqualToString:object.proxyType]) {
        return NO;
    }

    if (_serverTrust != object.serverTrust) {
        return NO;
    }

    if ((_port != object.port) || (_receivesCredentialSecurely != object.receivesCredentialSecurely)) {
        return NO;
    }

    return YES;
}

- (NSUInteger)hash {
    NSUInteger result = _hashCode;
    if (result == 0) {
        NSUInteger prime = 31;
        result = prime * result + _port;
        result = prime * result + [_serverTrust hash];
        result = prime * result + [_authenticationMethod hash];
        result = prime * result + [_distinguishedNames hash];
        result = prime * result + [_host hash];
        result = prime * result + [_protocol hash];

        result = prime * result + [_realm hash];

        result = prime * result + [_proxyType hash];
        result = prime * result + _receivesCredentialSecurely;
    }
    return result;
}

/**
 @Status Caveat
 @Notes Does not support encoding/decoding of SecTrustRef.
*/
- (id)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        _authenticationMethod = [[coder decodeObjectForKey:@"authenticationMethod"] retain];
        _distinguishedNames = [[coder decodeObjectForKey:@"distinguishedNames"] retain];
        _host = [[coder decodeObjectForKey:@"host"] retain];
        _port = [coder decodeInt64ForKey:@"port"];
        _protocol = [[coder decodeObjectForKey:@"protocol"] retain];
        _realm = [[coder decodeObjectForKey:@"realm"] retain];
        _proxyType = [[coder decodeObjectForKey:@"proxyType"] retain];
        _receivesCredentialSecurely = [coder decodeBoolForKey:@"receivesCredentialSecurely"];
        // TODO: Implement encoding/decoding for SecTrustRef and when security apis are implemented.
    }
    return self;
}

- (void)dealloc {
    [_authenticationMethod release];
    [_distinguishedNames release];
    [_host release];
    [_protocol release];
    [_realm release];
    [_proxyType release];
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (BOOL)isProxy {
    return (_proxyType != nil);
}

@end