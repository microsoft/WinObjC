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

#include "Starboard.h"
#include "StubReturn.h"
#include "Foundation/NSString.h"
#include "Foundation/NSStream.h"
#include "NSSocket.h"
#include "NSInputStream_socket.h"
#include "NSOutputStream_socket.h"
#include "NSStreamInternal.h"

FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelKey = @"NSStreamSocketSecurityLevelKey";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyConfigurationKey = @"NSStreamSOCKSProxyConfigurationKey";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyHostKey = @"NSStreamSOCKSProxyHostKey";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyPortKey = @"NSStreamSOCKSProxyPortKey";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyVersionKey = @"NSStreamSOCKSProxyVersionKey";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyUserKey = @"NSStreamSOCKSProxyUserKey";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyPasswordKey = @"NSStreamSOCKSProxyPasswordKey";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyVersion4 = @"NSStreamSOCKSProxyVersion4";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyVersion5 = @"NSStreamSOCKSProxyVersion5";
FOUNDATION_EXPORT NSString* const NSStreamDataWrittenToMemoryStreamKey = @"NSStreamDataWrittenToMemoryStreamKey";
FOUNDATION_EXPORT NSString* const NSStreamFileCurrentOffsetKey = @"NSStreamFileCurrentOffsetKey";
FOUNDATION_EXPORT NSString* const NSStreamNetworkServiceType = @"NSStreamNetworkServiceType";
FOUNDATION_EXPORT NSString* const NSStreamSocketSSLErrorDomain = @"NSStreamSocketSSLErrorDomain";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSErrorDomain = @"NSStreamSOCKSErrorDomain";
FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelNone = @"NSStreamSocketSecurityLevelNone";
FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelSSLv2 = @"NSStreamSocketSecurityLevelSSLv2";
FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelSSLv3 = @"NSStreamSocketSecurityLevelSSLv3";
FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelTLSv1 = @"NSStreamSocketSecurityLevelTLSv1";
FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelNegotiatedSSL = @"NSStreamSocketSecurityLevelNegotiatedSSL";
FOUNDATION_EXPORT NSString* const NSStreamNetworkServiceTypeVoIP = @"NSStreamNetworkServiceTypeVoIP";
FOUNDATION_EXPORT NSString* const NSStreamNetworkServiceTypeVideo = @"NSStreamNetworkServiceTypeVideo";
FOUNDATION_EXPORT NSString* const NSStreamNetworkServiceTypeBackground = @"NSStreamNetworkServiceTypeBackground";
FOUNDATION_EXPORT NSString* const NSStreamNetworkServiceTypeVoice = @"NSStreamNetworkServiceTypeVoice";

@implementation NSStream

/**
 @Status Interoperable
*/
+ (void)initialize {
}

/**
 @Status Interoperable
*/
- (unsigned)streamStatus {
    return _status;
}

/**
 @Status Interoperable
*/
- (void)close {
    if (fp) {
        EbrFclose(fp);
        fp = NULL;
    }
    _status = NSStreamStatusClosed;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    if (fp) {
        EbrFclose(fp);
        fp = NULL;
    }
    _data = nil;

    [super dealloc];
}

/**
 @Status Stub
*/
- (id)propertyForKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)setProperty:(id)property forKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)open {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)scheduleInRunLoop:(NSRunLoop*)aRunLoop forMode:(NSString*)mode {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeFromRunLoop:(NSRunLoop*)aRunLoop forMode:(NSString*)mode {
    UNIMPLEMENTED();
}

@end
