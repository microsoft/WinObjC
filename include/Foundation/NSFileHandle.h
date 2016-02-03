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
@class NSURL;
@class NSError;
@class NSData;
@class NSArray;

FOUNDATION_EXPORT NSString* const NSFileHandleNotificationFileHandleItem;
FOUNDATION_EXPORT NSString* const NSFileHandleNotificationDataItem;
FOUNDATION_EXPORT NSString* const NSFileHandleOperationException;
FOUNDATION_EXPORT NSString* const NSFileHandleNotificationMonitorModes;
FOUNDATION_EXPORT NSString* const NSFileHandleConnectionAcceptedNotification;
FOUNDATION_EXPORT NSString* const NSFileHandleDataAvailableNotification;
FOUNDATION_EXPORT NSString* const NSFileHandleReadCompletionNotification;
FOUNDATION_EXPORT NSString* const NSFileHandleReadToEndOfFileCompletionNotification;

FOUNDATION_EXPORT_CLASS
@interface NSFileHandle : NSObject <NSSecureCoding>
+ (instancetype)fileHandleForReadingAtPath:(NSString*)path STUB_METHOD;
+ (instancetype)fileHandleForReadingFromURL:(NSURL*)url error:(NSError* _Nullable*)error STUB_METHOD;
+ (instancetype)fileHandleForWritingAtPath:(NSString*)path STUB_METHOD;
+ (instancetype)fileHandleForWritingToURL:(NSURL*)url error:(NSError* _Nullable*)error STUB_METHOD;
+ (instancetype)fileHandleForUpdatingAtPath:(NSString*)path STUB_METHOD;
+ (instancetype)fileHandleForUpdatingURL:(NSURL*)url error:(NSError* _Nullable*)error STUB_METHOD;
+ (NSFileHandle*)fileHandleWithStandardError STUB_METHOD;
+ (NSFileHandle*)fileHandleWithStandardInput STUB_METHOD;
+ (NSFileHandle*)fileHandleWithStandardOutput STUB_METHOD;
+ (NSFileHandle*)fileHandleWithNullDevice STUB_METHOD;
- (instancetype)initWithFileDescriptor:(int)fileDescriptor STUB_METHOD;
- (instancetype)initWithFileDescriptor:(int)fileDescriptor closeOnDealloc:(BOOL)flag STUB_METHOD;
@property (readonly) int fileDescriptor STUB_PROPERTY;
@property (readonly, copy) NSData* availableData STUB_PROPERTY;
- (NSData*)readDataToEndOfFile STUB_METHOD;
- (NSData*)readDataOfLength:(NSUInteger)length STUB_METHOD;
- (void)writeData:(NSData*)data STUB_METHOD;
@property (copy, nonnull) void (^readabilityHandler)(NSFileHandle*) STUB_PROPERTY;
@property (copy, nonnull) void (^writeabilityHandler)(NSFileHandle*) STUB_PROPERTY;
- (void)acceptConnectionInBackgroundAndNotify STUB_METHOD;
- (void)acceptConnectionInBackgroundAndNotifyForModes:(NSArray*)modes STUB_METHOD;
- (void)readInBackgroundAndNotify STUB_METHOD;
- (void)readInBackgroundAndNotifyForModes:(NSArray*)modes STUB_METHOD;
- (void)readToEndOfFileInBackgroundAndNotify STUB_METHOD;
- (void)readToEndOfFileInBackgroundAndNotifyForModes:(NSArray*)modes STUB_METHOD;
- (void)waitForDataInBackgroundAndNotify STUB_METHOD;
- (void)waitForDataInBackgroundAndNotifyForModes:(NSArray*)modes STUB_METHOD;
@property (readonly) unsigned long long offsetInFile STUB_PROPERTY;
- (unsigned long long)seekToEndOfFile STUB_METHOD;
- (void)seekToFileOffset:(unsigned long long)offset STUB_METHOD;
- (void)closeFile STUB_METHOD;
- (void)synchronizeFile STUB_METHOD;
- (void)truncateFileAtOffset:(unsigned long long)offset STUB_METHOD;
@end
