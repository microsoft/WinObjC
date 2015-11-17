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
#import <Windows.h>

@interface NSURLSessionConfiguration ()
@property (readwrite, copy) NSString* identifier;
@end

@implementation NSURLSessionConfiguration

- (instancetype)_initWithSharedDefaults {
    if (self = [super init]) {
        _allowsCellularAccess = YES;
        _timeoutIntervalForRequest = 60;
        _timeoutIntervalForResource = 7;
        _HTTPCookieAcceptPolicy = NSHTTPCookieAcceptPolicyOnlyFromMainDocumentDomain;
        _HTTPCookieStorage = [[NSHTTPCookieStorage sharedHTTPCookieStorage] retain];
        _HTTPShouldSetCookies = YES;
        _networkServiceType = NSURLNetworkServiceTypeDefault;
        _requestCachePolicy = NSURLRequestUseProtocolCachePolicy;
        _HTTPMaximumConnectionsPerHost = 6;
        //_URLCredentialStorage = [[NSURLCredentialStorage sharedCredentialStorage] retain];
    }

    return self;
}

- (instancetype)_initTLSAndCache {
    if (self = [self _initWithSharedDefaults]) {
        _TLSMaximumSupportedProtocol = kTLSProtocol12;
        _TLSMinimumSupportedProtocol = kTLSProtocol1;
        _URLCache = [[NSURLCache sharedURLCache] retain];
    }
    return self;
}

- (instancetype)init {
    if (self = [self _initWithSharedDefaults]) {
        _TLSMaximumSupportedProtocol = kTLSProtocol12;
        _TLSMinimumSupportedProtocol = kSSLProtocol3;
    }
    return self;
}

- (instancetype)initEphemeralSession {
    self = [self _initTLSAndCache];
    return self;
}

- (instancetype)initBackgroundSession:(NSString*)identifier {
    if (self = [self _initTLSAndCache]) {
        _identifier = identifier;
    }
    return self;
}

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

+ (NSURLSessionConfiguration*)defaultSessionConfiguration {
    return [[[NSURLSessionConfiguration alloc] init] autorelease];
}

+ (NSURLSessionConfiguration*)ephemeralSessionConfiguration {
    return [[[NSURLSessionConfiguration alloc] initEphemeralSession] autorelease];
}

+ (NSURLSessionConfiguration*)backgroundSessionConfigurationWithIdentifier:(NSString*)identifier {
    return [[[NSURLSessionConfiguration alloc] initBackgroundSession:identifier] autorelease];
}

+ (NSURLSessionConfiguration*)backgroundSessionConfiguration:(NSString*)identifier {
    return [NSURLSessionConfiguration backgroundSessionConfigurationWithIdentifier:identifier];
}

@end