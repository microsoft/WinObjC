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
#include "NSRaise.h"

#include <CoreFoundation/CFStream.h>

FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelKey = static_cast<NSString*>(kCFStreamPropertySocketSecurityLevel);

FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyConfigurationKey = static_cast<NSString*>(kCFStreamPropertySOCKSProxy);
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyHostKey = static_cast<NSString*>(kCFStreamPropertySOCKSProxyHost);
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyPortKey = static_cast<NSString*>(kCFStreamPropertySOCKSProxyPort);
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyVersionKey = static_cast<NSString*>(kCFStreamPropertySOCKSVersion);
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyUserKey = static_cast<NSString*>(kCFStreamPropertySOCKSUser);
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyPasswordKey = static_cast<NSString*>(kCFStreamPropertySOCKSPassword);

FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyVersion4 = static_cast<NSString*>(kCFStreamSocketSOCKSVersion4);
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyVersion5 = static_cast<NSString*>(kCFStreamSocketSOCKSVersion5);
FOUNDATION_EXPORT NSString* const NSStreamDataWrittenToMemoryStreamKey = static_cast<NSString*>(kCFStreamPropertyDataWritten);
FOUNDATION_EXPORT NSString* const NSStreamFileCurrentOffsetKey = static_cast<NSString*>(kCFStreamPropertyFileCurrentOffset);

FOUNDATION_EXPORT NSString* const NSStreamNetworkServiceType = static_cast<NSString*>(kCFStreamNetworkServiceType);
FOUNDATION_EXPORT NSString* const NSStreamSocketSSLErrorDomain = @"NSStreamSocketSSLErrorDomain";
FOUNDATION_EXPORT NSString* const NSStreamSOCKSErrorDomain = @"NSStreamSOCKSErrorDomain";
FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelNone = static_cast<NSString*>(kCFStreamSocketSecurityLevelNone);
FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelSSLv2 = static_cast<NSString*>(kCFStreamSocketSecurityLevelSSLv2);
FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelSSLv3 = static_cast<NSString*>(kCFStreamSocketSecurityLevelSSLv3);
FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelTLSv1 = static_cast<NSString*>(kCFStreamSocketSecurityLevelTLSv1);
FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelNegotiatedSSL =
    static_cast<NSString*>(kCFStreamSocketSecurityLevelNegotiatedSSL);
FOUNDATION_EXPORT NSString* const NSStreamNetworkServiceTypeVoIP = static_cast<NSString*>(kCFStreamNetworkServiceTypeVoIP);
FOUNDATION_EXPORT NSString* const NSStreamNetworkServiceTypeVideo = static_cast<NSString*>(kCFStreamNetworkServiceTypeVideo);
FOUNDATION_EXPORT NSString* const NSStreamNetworkServiceTypeBackground = static_cast<NSString*>(kCFStreamNetworkServiceTypeBackground);
FOUNDATION_EXPORT NSString* const NSStreamNetworkServiceTypeVoice = static_cast<NSString*>(kCFStreamNetworkServiceTypeVoice);

@implementation NSStream

/**
 @Status Interoperable
*/
- (NSStreamStatus)streamStatus {
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
