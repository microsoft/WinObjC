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

@class NSString;
@protocol NSStreamDelegate;
@class NSRunLoop;
@class NSError;

typedef NSUInteger NSStreamStatus;
typedef enum : NSUInteger {
    NSStreamEventNone = 0,
    NSStreamEventOpenCompleted = 1 << 0,
    NSStreamEventHasBytesAvailable = 1 << 1,
    NSStreamEventHasSpaceAvailable = 1 << 2,
    NSStreamEventErrorOccurred = 1 << 3,
    NSStreamEventEndEncountered = 1 << 4
} NSStreamEvent;
enum {
    NSStreamStatusNotOpen = 0,
    NSStreamStatusOpening = 1,
    NSStreamStatusOpen = 2,
    NSStreamStatusReading = 3,
    NSStreamStatusWriting = 4,
    NSStreamStatusAtEnd = 5,
    NSStreamStatusClosed = 6,
    NSStreamStatusError = 7
};

FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelKey;
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyConfigurationKey;
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyHostKey;
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyPortKey;
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyVersionKey;
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyUserKey;
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyPasswordKey;
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyVersion4;
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyVersion5;
FOUNDATION_EXPORT NSString* const NSStreamDataWrittenToMemoryStreamKey;
FOUNDATION_EXPORT NSString* const NSStreamFileCurrentOffsetKey;
FOUNDATION_EXPORT NSString* const NSStreamNetworkServiceType;
FOUNDATION_EXPORT NSString* const NSStreamSocketSSLErrorDomain;

FOUNDATION_EXPORT NSString* const NSStreamSOCKSErrorDomain;

FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelNone;
FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelSSLv2;
FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelSSLv3;
FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelTLSv1;
FOUNDATION_EXPORT NSString* const NSStreamSocketSecurityLevelNegotiatedSSL;
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyHostKey;
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyPortKey;
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyVersionKey;
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyUserKey;
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyPasswordKey;
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyVersion4;
FOUNDATION_EXPORT NSString* const NSStreamSOCKSProxyVersion5;
FOUNDATION_EXPORT NSString* const NSStreamNetworkServiceTypeVoIP;

FOUNDATION_EXPORT NSString* const NSStreamNetworkServiceTypeVideo;
FOUNDATION_EXPORT NSString* const NSStreamNetworkServiceTypeBackground;

FOUNDATION_EXPORT NSString* const NSStreamNetworkServiceTypeVoice;

FOUNDATION_EXPORT_CLASS
@interface NSStream : NSObject
/* Abstract */
- (void)open;
- (void)close;

- (id)propertyForKey:(NSString*)key;
- (BOOL)setProperty:(id)property forKey:(NSString*)key;

- (void)scheduleInRunLoop:(NSRunLoop*)aRunLoop forMode:(NSString*)mode;
- (void)removeFromRunLoop:(NSRunLoop*)aRunLoop forMode:(NSString*)mode;

@property (assign) id<NSStreamDelegate> delegate;

@property (readonly) NSStreamStatus streamStatus;
@property (readonly, copy) NSError* streamError;
@end

@protocol NSStreamDelegate <NSObject>
@optional
- (void)stream:(NSStream*)theStream handleEvent:(NSStreamEvent)streamEvent;
@end
