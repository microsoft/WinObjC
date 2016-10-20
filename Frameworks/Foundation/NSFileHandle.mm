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

#import <Starboard.h>
#import <Platform/EbrPlatform.h>
#import <Foundation/NSData.h>
#import <Foundation/NSFileHandle.h>
#import <_NSFileHandleNullDevice.h>
#import <StubReturn.h>

#import <memory>
#import <fcntl.h>

NSString* const NSFileHandleNotificationFileHandleItem = @"NSFileHandleNotificationFileHandleItem";
NSString* const NSFileHandleNotificationDataItem = @"NSFileHandleNotificationDataItem";
NSString* const NSFileHandleOperationException = @"NSFileHandleOperationException";
NSString* const NSFileHandleNotificationMonitorModes = @"NSFileHandleNotificationMonitorModes";

typedef NS_ENUM(NSUInteger, _NSFileOpenMode) { _NSFileOpenModeRead, _NSFileOpenModeWrite, _NSFileOpenModeUpdate };

@implementation NSFileHandle {
    BOOL _closeOnDealloc;
    int _fileDescriptor;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFileDescriptor:(int)fileDescriptor closeOnDealloc:(BOOL)flag {
    if (self = [super init]) {
        _fileDescriptor = fileDescriptor;
        _closeOnDealloc = flag;
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFileDescriptor:(int)fileDescriptor {
    return [self initWithFileDescriptor:fileDescriptor closeOnDealloc:NO];
}

- (instancetype)_initWithFileAtPath:(NSString*)file openType:(_NSFileOpenMode)type {
    if (file == nil) {
        [self release];
        return nil;
    }
    if (self = [self initWithFileDescriptor:-1 closeOnDealloc:YES]) {
        _fileDescriptor = [self _openFile:file openType:type];

        if (_fileDescriptor == -1) {
            TraceError(L"NSFileHandle", L"Unable to open file, errno:%d", errno);
            [self release];
            return nil;
        }

        if (type == _NSFileOpenModeUpdate) {
            [self seekToFileOffset:0];
        }
    }

    return self;
}

- (int)_openFile:(NSString*)file openType:(_NSFileOpenMode)type {
    switch (type) {
        case _NSFileOpenModeRead:
            return EbrOpenWithPermission((char*)([file UTF8String]), O_RDONLY | _O_BINARY, _SH_DENYWR, _S_IREAD);
        case _NSFileOpenModeWrite:
            return EbrOpenWithPermission((char*)([file UTF8String]), _O_WRONLY | _O_BINARY | _O_CREAT, _SH_DENYNO, _S_IREAD | _S_IWRITE);
        case _NSFileOpenModeUpdate:
            return EbrOpenWithPermission((char*)([file UTF8String]),
                                         O_RDWR | _O_CREAT | O_APPEND | _O_BINARY,
                                         _SH_DENYNO,
                                         _S_IREAD | _S_IWRITE);
        default:
            break;
    }
    return -1;
}

/**
 @Status Caveat
 @Notes NSFileHandle only supports file URLs.
 */
+ (instancetype)fileHandleForReadingFromURL:(NSURL*)url error:(NSError* _Nullable*)error {
    return [NSFileHandle _fileHandleForURl:url error:error openType:_NSFileOpenModeRead];
}

/**
 @Status Interoperable
*/
+ (instancetype)fileHandleForReadingAtPath:(NSString*)file {
    return [[[self alloc] _initWithFileAtPath:file openType:_NSFileOpenModeRead] autorelease];
}

/**
 @Status Caveat
 @Notes NSFileHandle only supports file URLs.
 */
+ (instancetype)fileHandleForWritingToURL:(NSURL*)url error:(NSError* _Nullable*)error {
    return [NSFileHandle _fileHandleForURl:url error:error openType:_NSFileOpenModeWrite];
}

/**
 @Status Interoperable
*/
+ (instancetype)fileHandleForWritingAtPath:(NSString*)file {
    return [[[self alloc] _initWithFileAtPath:file openType:_NSFileOpenModeWrite] autorelease];
}

/**
 @Status Caveat
 @Notes NSFileHandle only supports file URLs.
 */
+ (instancetype)fileHandleForUpdatingURL:(NSURL*)url error:(NSError* _Nullable*)error {
    return [NSFileHandle _fileHandleForURl:url error:error openType:_NSFileOpenModeUpdate];
}

+ (instancetype)_fileHandleForURl:(NSURL*)url error:(NSError* _Nullable*)error openType:(_NSFileOpenMode)type {
    if (url == nil) {
        return nil;
    }

    if (![url isFileURL]) {
        UNIMPLEMENTED_WITH_MSG("NSFileHandle only supports file URLs.");
        return nil;
    }

    NSFileHandle* ret = nil;
    switch (type) {
        case _NSFileOpenModeRead:
            ret = [NSFileHandle fileHandleForReadingAtPath:[url path]];
            break;
        case _NSFileOpenModeWrite:
            ret = [NSFileHandle fileHandleForWritingAtPath:[url path]];
            break;
        case _NSFileOpenModeUpdate:
            ret = [NSFileHandle fileHandleForUpdatingAtPath:[url path]];
            break;
        default:
            break;
    }

    if (ret == nil) {
        if (error) {
            *error = [NSError errorWithDomain:NSFileHandleOperationException code:errno userInfo:nil];
        }
        return nil;
    }

    return ret;
}

/**
 @Status Interoperable
*/
+ (instancetype)fileHandleForUpdatingAtPath:(NSString*)file {
    return [[[self alloc] _initWithFileAtPath:file openType:_NSFileOpenModeUpdate] autorelease];
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
 @Status Interoperable
*/
+ (NSFileHandle*)fileHandleWithNullDevice {
    return [[_NSFileHandleNullDevice new] autorelease];
}

/**
 @Status Interoperable
*/
- (void)closeFile {
    if (_fileDescriptor >= 0) {
        EbrClose(_fileDescriptor);
        _fileDescriptor = -1;
    }
}

/**
 @Status Interoperable
*/
- (void)seekToFileOffset:(unsigned long long)offset {
    if (EbrLseek(_fileDescriptor, offset, SEEK_SET) == -1) {
        [NSException raise:NSFileHandleOperationException format:@"Unable to seek to offset %llu.", offset];
    }
}

/**
 @Status Interoperable
*/
- (void)truncateFileAtOffset:(unsigned long long)size {
    if (EbrTruncate64(_fileDescriptor, size) != 0) {
        [NSException raise:NSFileHandleOperationException format:@"Unable to truncate to size %llu.", size];
    }
}

/**
 @Status Interoperable
*/
- (unsigned long long)seekToEndOfFile {
    unsigned long long newPos = EbrLseek(_fileDescriptor, 0, SEEK_END);
    if (newPos == -1) {
        [NSException raise:NSFileHandleOperationException format:@"Unable to seek to end of file."];
    }

    return newPos;
}

/**
 @Status Interoperable
*/
- (unsigned long long)offsetInFile {
    return EbrLseek(_fileDescriptor, 0, SEEK_CUR);
}

/**
 @Status Interoperable
*/
- (NSData*)availableData {
    return [self readDataToEndOfFile];
}

- (int)_readIntoData:(NSMutableData*)data atOffSet:(NSUInteger)offset length:(NSUInteger)len {
    int bytesRead = 0;

    // check if we need more space.
    if (([data length] - offset) < len) {
        // grow the mutable data
        [data increaseLengthBy:(len - [data length] + offset)];
    }

    while (bytesRead < len) {
        int readByteSize = EbrRead(_fileDescriptor, ((char*)[data mutableBytes] + offset) + bytesRead, len - bytesRead);
        if (readByteSize == 0) {
            // early eof
            break;
        }
        if (readByteSize < 0) {
            [NSException raise:NSFileHandleOperationException format:@"Unable to read the required length of %u. errno:%d", len, errno];
        }

        bytesRead += readByteSize;
    }

    // set the new length
    data.length = (offset + bytesRead);
    return bytesRead;
}

/**
 @Status Interoperable
*/
- (NSData*)readDataOfLength:(NSUInteger)len {
    NSMutableData* resultData = [NSMutableData dataWithLength:len];

    int readLen = [self _readIntoData:resultData atOffSet:0 length:len];
    if (readLen == 0) {
        return [NSData data];
    }
    return [[resultData copy] autorelease];
}

/**
 @Status Interoperable
*/
- (NSData*)readDataToEndOfFile {
    NSMutableData* resultData = [NSMutableData dataWithLength:(1024 * 128)];
    int readLen = -1;
    int offset = 0;
    while ((readLen = [self _readIntoData:resultData atOffSet:offset length:1024 * 128]) > 0) {
        offset += readLen;
    }

    if (offset == 0) {
        return [NSData data];
    }

    return [[resultData copy] autorelease];
}

/**
 @Status Interoperable
*/
- (void)writeData:(NSData*)data {
    char* bytes = (char*)([data bytes]);
    unsigned long bytesLen = [data length];

    while (bytesLen > 0) {
        int writtenLen = EbrWrite(_fileDescriptor, bytes, bytesLen);

        if (writtenLen < 0) {
            [NSException raise:NSFileHandleOperationException format:@"Unable to write data. errno:", bytesLen];
        }
        bytesLen = bytesLen - writtenLen;
    }
}

/**
 @Status Interoperable
*/
- (int)fileDescriptor {
    return _fileDescriptor;
}

/**
 @Status Interoperable
*/
- (void)synchronizeFile {
    if (EbrFflush(_fileDescriptor) != 0) {
        [NSException raise:NSFileHandleOperationException format:@"Unable to synchronize file."];
    }
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    if (_closeOnDealloc) {
        [self closeFile];
    }
    [super dealloc];
}
@end
