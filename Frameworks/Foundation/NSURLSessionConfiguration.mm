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

#import <Foundation/NSURLSessionConfiguration.h>
#import <Starboard.h>
#import <windows.h>

@interface NSURLSessionConfiguration ()
@property (readwrite, copy) NSString* identifier;
@end

@implementation NSURLSessionConfiguration

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self = [super init]) {
        _allowsCellularAccess = YES;
        _timeoutIntervalForRequest = 60;
        _timeoutIntervalForResource = 7 * 24 * 60 * 60;
        _HTTPCookieAcceptPolicy = NSHTTPCookieAcceptPolicyOnlyFromMainDocumentDomain;
        _HTTPCookieStorage = [[NSHTTPCookieStorage sharedHTTPCookieStorage] retain];
        _HTTPShouldSetCookies = YES;
        _networkServiceType = NSURLNetworkServiceTypeDefault;
        _requestCachePolicy = NSURLRequestUseProtocolCachePolicy;
        _HTTPMaximumConnectionsPerHost = 6;
        _TLSMaximumSupportedProtocol = kTLSProtocol12;
        _TLSMinimumSupportedProtocol = kTLSProtocol1;
        _URLCredentialStorage = [[NSURLCredentialStorage sharedCredentialStorage] retain];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initEphemeralSession {
    if (self = [self init]) {
        _URLCache = [[NSURLCache sharedURLCache] retain];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initBackgroundSession:(NSString*)identifier {
    if (self = [self init]) {
        _identifier = [identifier copy];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    NSURLSessionConfiguration* copy = [[[self class] allocWithZone:zone] init];
    copy.identifier = _identifier;
    copy.networkServiceType = _networkServiceType;
    copy.allowsCellularAccess = _allowsCellularAccess;
    copy.timeoutIntervalForRequest = _timeoutIntervalForRequest;
    copy.timeoutIntervalForResource = _timeoutIntervalForResource;
    copy.HTTPCookieAcceptPolicy = _HTTPCookieAcceptPolicy;
    copy.HTTPCookieStorage = _HTTPCookieStorage;
    copy.HTTPShouldSetCookies = _HTTPShouldSetCookies;
    copy.TLSMaximumSupportedProtocol = _TLSMaximumSupportedProtocol;
    copy.TLSMinimumSupportedProtocol = _TLSMinimumSupportedProtocol;
    copy.URLCredentialStorage = _URLCredentialStorage;
    copy.URLCache = _URLCache;
    copy.requestCachePolicy = _requestCachePolicy;
    copy.HTTPMaximumConnectionsPerHost = _HTTPMaximumConnectionsPerHost;
    copy.HTTPAdditionalHeaders = _HTTPAdditionalHeaders;
    copy.sharedContainerIdentifier = _sharedContainerIdentifier;
    copy.sessionSendsLaunchEvents = _sessionSendsLaunchEvents;
    copy.discretionary = _discretionary;
    copy.protocolClasses = _protocolClasses;
    copy.HTTPShouldUsePipelining = _HTTPShouldUsePipelining;
    copy.connectionProxyDictionary = _connectionProxyDictionary;
    return copy;
}

/**
 @Status Interoperable
*/
+ (NSURLSessionConfiguration*)defaultSessionConfiguration {
    return [[[NSURLSessionConfiguration alloc] init] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSURLSessionConfiguration*)ephemeralSessionConfiguration {
    return [[[NSURLSessionConfiguration alloc] initEphemeralSession] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSURLSessionConfiguration*)backgroundSessionConfigurationWithIdentifier:(NSString*)identifier {
    return [[[NSURLSessionConfiguration alloc] initBackgroundSession:identifier] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSURLSessionConfiguration*)backgroundSessionConfiguration:(NSString*)identifier {
    return [NSURLSessionConfiguration backgroundSessionConfigurationWithIdentifier:identifier];
}

- (void)dealloc {
    [_identifier release];
    [_HTTPAdditionalHeaders release];
    [_sharedContainerIdentifier release];
    [_HTTPCookieStorage release];
    [_URLCredentialStorage release];
    [_URLCache release];
    [_protocolClasses release];
    [_connectionProxyDictionary release];
    [super dealloc];
}

@end