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

#import <StubReturn.h>
#import <Starboard.h>
#import <Foundation/NSFileHandle.h>

NSString* const NSFileHandleNotificationFileHandleItem = @"NSFileHandleNotificationFileHandleItem";
NSString* const NSFileHandleNotificationDataItem = @"NSFileHandleNotificationDataItem";
NSString* const NSFileHandleOperationException = @"NSFileHandleOperationException";
NSString* const NSFileHandleNotificationMonitorModes = @"NSFileHandleNotificationMonitorModes";

@implementation NSFileHandle
/**
 @Status Stub
 @Notes
*/
+ (instancetype)fileHandleForReadingAtPath:(NSString*)path {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)fileHandleForReadingFromURL:(NSURL*)url error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)fileHandleForWritingAtPath:(NSString*)path {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)fileHandleForWritingToURL:(NSURL*)url error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)fileHandleForUpdatingAtPath:(NSString*)path {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)fileHandleForUpdatingURL:(NSURL*)url error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSFileHandle*)fileHandleWithStandardError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSFileHandle*)fileHandleWithStandardInput {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSFileHandle*)fileHandleWithStandardOutput {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSFileHandle*)fileHandleWithNullDevice {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithFileDescriptor:(int)fileDescriptor {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithFileDescriptor:(int)fileDescriptor closeOnDealloc:(BOOL)flag {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSData*)readDataToEndOfFile {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSData*)readDataOfLength:(NSUInteger)length {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)writeData:(NSData*)data {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)acceptConnectionInBackgroundAndNotify {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)acceptConnectionInBackgroundAndNotifyForModes:(NSArray*)modes {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)readInBackgroundAndNotify {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)readInBackgroundAndNotifyForModes:(NSArray*)modes {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)readToEndOfFileInBackgroundAndNotify {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)readToEndOfFileInBackgroundAndNotifyForModes:(NSArray*)modes {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)waitForDataInBackgroundAndNotify {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)waitForDataInBackgroundAndNotifyForModes:(NSArray*)modes {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (unsigned long long)seekToEndOfFile {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)seekToFileOffset:(unsigned long long)offset {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)closeFile {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)synchronizeFile {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)truncateFileAtOffset:(unsigned long long)offset {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

@end