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
#include "NSRaise.h"

#include <CoreFoundation/CFStream.h>

FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelKey = @"NSStreamSocketSecurityLevelKey";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyConfigurationKey = @"NSStreamSOCKSProxyConfigurationKey";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyHostKey = @"NSStreamSOCKSProxyHostKey";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyPortKey = @"NSStreamSOCKSProxyPortKey";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyVersionKey = @"NSStreamSOCKSProxyVersionKey";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyUserKey = @"NSStreamSOCKSProxyUserKey";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyPasswordKey = @"NSStreamSOCKSProxyPasswordKey";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyVersion4 = @"NSStreamSOCKSProxyVersion4";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyVersion5 = @"NSStreamSOCKSProxyVersion5";
FOUNDATION_EXPORT NSString* const NSStreamDataWrittenToMemoryStreamKey = static_cast<NSString*>(kCFStreamPropertyDataWritten);
FOUNDATION_EXPORT NSString* const NSStreamFileCurrentOffsetKey = static_cast<NSString*>(kCFStreamPropertyFileCurrentOffset);
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
- (unsigned)streamStatus {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (void)close {
    NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (id)propertyForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)setProperty:(id)property forKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
 @Notes
*/
- (void)open {
    NSInvalidAbstractInvocation();
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
