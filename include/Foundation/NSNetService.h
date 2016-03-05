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
@class NSData;
@class NSDictionary;
@class NSArray;
@protocol NSNetServiceDelegate;
@class NSRunLoop;

#import <Foundation/NSInputStream.h>
#import <Foundation/NSOutputStream.h>
typedef NSUInteger NSNetServiceOptions;
typedef enum {
    NSNetServicesUnknownError = -72000,
    NSNetServicesCollisionError = -72001,
    NSNetServicesNotFoundError = -72002,
    NSNetServicesActivityInProgress = -72003,
    NSNetServicesBadArgumentError = -72004,
    NSNetServicesCancelledError = -72005,
    NSNetServicesInvalidError = -72006,
    NSNetServicesTimeoutError = -72007,
} NSNetServicesError;
enum { NSNetServiceNoAutoRename = 1 << 0, NSNetServiceListenForConnections = 1UL << 1 };
FOUNDATION_EXPORT NSString* const NSNetServicesErrorCode;
FOUNDATION_EXPORT NSString* const NSNetServicesErrorDomain;

FOUNDATION_EXPORT_CLASS
@interface NSNetService : NSObject
- (instancetype)initWithDomain:(NSString*)domain type:(NSString*)type name:(NSString*)name STUB_METHOD;
- (instancetype)initWithDomain:(NSString*)domain type:(NSString*)type name:(NSString*)name port:(int)port STUB_METHOD;
+ (NSData*)dataFromTXTRecordDictionary:(NSDictionary*)txtDictionary STUB_METHOD;
+ (NSDictionary*)dictionaryFromTXTRecordData:(NSData*)txtData STUB_METHOD;
@property (readonly, copy) NSArray* addresses STUB_PROPERTY;
@property (readonly, copy) NSString* domain STUB_PROPERTY;
@property BOOL includesPeerToPeer STUB_PROPERTY;
- (BOOL)getInputStream:(NSInputStream* _Nullable*)inputStream outputStream:(NSOutputStream* _Nullable*)outputStream STUB_METHOD;
@property (readonly, copy) NSString* name STUB_PROPERTY;
@property (readonly, copy) NSString* type STUB_PROPERTY;
- (NSData*)TXTRecordData STUB_METHOD;
- (BOOL)setTXTRecordData:(NSData*)recordData STUB_METHOD;
@property (assign) id<NSNetServiceDelegate> delegate STUB_PROPERTY;
- (void)scheduleInRunLoop:(NSRunLoop*)aRunLoop forMode:(NSString*)mode STUB_METHOD;
- (void)removeFromRunLoop:(NSRunLoop*)aRunLoop forMode:(NSString*)mode STUB_METHOD;
- (void)publish STUB_METHOD;
- (void)publishWithOptions:(NSNetServiceOptions)serviceOptions STUB_METHOD;
- (void)resolve STUB_METHOD;
- (void)resolveWithTimeout:(NSTimeInterval)timeout STUB_METHOD;
@property (readonly) NSInteger port STUB_PROPERTY;
- (void)startMonitoring STUB_METHOD;
- (void)stop STUB_METHOD;
- (void)stopMonitoring STUB_METHOD;
@property (readonly, copy) NSString* hostName STUB_PROPERTY;
@end

@protocol NSNetServiceDelegate <NSObject>
@optional
- (void)netServiceWillPublish:(NSNetService*)sender;
- (void)netService:(NSNetService*)sender didNotPublish:(NSDictionary*)errorDict;
- (void)netServiceDidPublish:(NSNetService*)sender;
- (void)netServiceWillResolve:(NSNetService*)sender;
- (void)netService:(NSNetService*)sender didNotResolve:(NSDictionary*)errorDict;
- (void)netServiceDidResolveAddress:(NSNetService*)sender;
- (void)netService:(NSNetService*)sender didUpdateTXTRecordData:(NSData*)data;
- (void)netServiceDidStop:(NSNetService*)sender;
- (void)netService:(NSNetService*)sender
    didAcceptConnectionWithInputStream:(NSInputStream*)inputStream
                          outputStream:(NSOutputStream*)outputStream;
@end
