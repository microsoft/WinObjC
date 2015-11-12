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

// WindowsStorageStreams.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSSDataReaderLoadOperation, WSSDataReader, WSSDataWriterStoreOperation, WSSDataWriter, WSSRandomAccessStream, WSSBuffer,
    WSSRandomAccessStreamReference, WSSFileRandomAccessStream, WSSFileInputStream, WSSFileOutputStream, WSSRandomAccessStreamOverStream,
    WSSInputStreamOverStream, WSSOutputStreamOverStream, WSSInMemoryRandomAccessStream;
@protocol WSSIDataReader
, WSSIDataReaderFactory, WSSIDataReaderStatics, WSSIDataWriter, WSSIDataWriterFactory, WSSIRandomAccessStreamStatics, WSSIBufferFactory,
    WSSIBuffer, WSSIContentTypeProvider, WSSIRandomAccessStreamReference, WSSIInputStreamReference, WSSIRandomAccessStreamReferenceStatics,
    WSSIInputStream, WSSIOutputStream, WSSIRandomAccessStream, WSSIRandomAccessStreamWithContentType;

// Windows.Storage.Streams.ByteOrder
enum _WSSByteOrder {
    WSSByteOrderLittleEndian = 0,
    WSSByteOrderBigEndian = 1,
};
typedef unsigned WSSByteOrder;

// Windows.Storage.Streams.UnicodeEncoding
enum _WSSUnicodeEncoding {
    WSSUnicodeEncodingUtf8 = 0,
    WSSUnicodeEncodingUtf16LE = 1,
    WSSUnicodeEncodingUtf16BE = 2,
};
typedef unsigned WSSUnicodeEncoding;

// Windows.Storage.Streams.InputStreamOptions
enum _WSSInputStreamOptions {
    WSSInputStreamOptionsNone = 0,
    WSSInputStreamOptionsPartial = 1,
    WSSInputStreamOptionsReadAhead = 2,
};
typedef unsigned WSSInputStreamOptions;

#include "WindowsFoundation.h"
#include "WindowsStorage.h"

#import <Foundation/Foundation.h>

// Windows.Storage.Streams.IDataReader
#ifndef __WSSIDataReader_DEFINED__
#define __WSSIDataReader_DEFINED__

@protocol WSSIDataReader
@property WSSByteOrder byteOrder;
@property WSSInputStreamOptions inputStreamOptions;
@property (readonly) unsigned unconsumedBufferLength;
@property WSSUnicodeEncoding unicodeEncoding;
- (uint8_t)readByte;
// Failed to generate member ReadBytes (Only receive arrays are currently supported.)
- (RTObject<WSSIBuffer>*)readBuffer:(unsigned)length;
- (BOOL)readBoolean;
- (WFGUID*)readGuid;
- (short)readInt16;
- (int)readInt32;
- (int64_t)readInt64;
- (unsigned short)readUInt16;
- (unsigned)readUInt32;
- (uint64_t)readUInt64;
- (float)readSingle;
- (double)readDouble;
- (NSString*)readString:(unsigned)codeUnitCount;
- (WFDateTime*)readDateTime;
- (WFTimeSpan*)readTimeSpan;
- (WSSDataReaderLoadOperation*)loadAsync:(unsigned)count;
- (RTObject<WSSIBuffer>*)detachBuffer;
- (RTObject<WSSIInputStream>*)detachStream;
@end

#endif // __WSSIDataReader_DEFINED__

// Windows.Storage.Streams.IDataWriter
#ifndef __WSSIDataWriter_DEFINED__
#define __WSSIDataWriter_DEFINED__

@protocol WSSIDataWriter
@property WSSByteOrder byteOrder;
@property WSSUnicodeEncoding unicodeEncoding;
@property (readonly) unsigned unstoredBufferLength;
- (void)writeByte:(uint8_t)value;
- (void)writeBytes:(id<NSFastEnumeration> /*UInt8*/)value;
- (void)writeBuffer:(RTObject<WSSIBuffer>*)buffer;
- (void)writeBufferRange:(RTObject<WSSIBuffer>*)buffer start:(unsigned)start count:(unsigned)count;
- (void)writeBoolean:(BOOL)value;
- (void)writeGuid:(WFGUID*)value;
- (void)writeInt16:(short)value;
- (void)writeInt32:(int)value;
- (void)writeInt64:(int64_t)value;
- (void)writeUInt16:(unsigned short)value;
- (void)writeUInt32:(unsigned)value;
- (void)writeUInt64:(uint64_t)value;
- (void)writeSingle:(float)value;
- (void)writeDouble:(double)value;
- (void)writeDateTime:(WFDateTime*)value;
- (void)writeTimeSpan:(WFTimeSpan*)value;
- (unsigned)writeString:(NSString*)value;
- (unsigned)measureString:(NSString*)value;
- (WSSDataWriterStoreOperation*)storeAsync;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (RTObject<WSSIBuffer>*)detachBuffer;
- (RTObject<WSSIOutputStream>*)detachStream;
@end

#endif // __WSSIDataWriter_DEFINED__

// Windows.Storage.Streams.IBuffer
#ifndef __WSSIBuffer_DEFINED__
#define __WSSIBuffer_DEFINED__

@protocol WSSIBuffer
@property (readonly) unsigned capacity;
@property unsigned length;
@end

#endif // __WSSIBuffer_DEFINED__

// Windows.Storage.Streams.IContentTypeProvider
#ifndef __WSSIContentTypeProvider_DEFINED__
#define __WSSIContentTypeProvider_DEFINED__

@protocol WSSIContentTypeProvider
@property (readonly) NSString* contentType;
@end

#endif // __WSSIContentTypeProvider_DEFINED__

// Windows.Storage.Streams.IRandomAccessStreamReference
#ifndef __WSSIRandomAccessStreamReference_DEFINED__
#define __WSSIRandomAccessStreamReference_DEFINED__

@protocol WSSIRandomAccessStreamReference
- (void)openReadAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSIRandomAccessStreamReference_DEFINED__

// Windows.Storage.Streams.IInputStreamReference
#ifndef __WSSIInputStreamReference_DEFINED__
#define __WSSIInputStreamReference_DEFINED__

@protocol WSSIInputStreamReference
- (void)openSequentialReadAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSIInputStreamReference_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Storage.Streams.IInputStream
#ifndef __WSSIInputStream_DEFINED__
#define __WSSIInputStream_DEFINED__

@protocol WSSIInputStream <WFIClosable>
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSSIInputStream_DEFINED__

// Windows.Storage.Streams.IOutputStream
#ifndef __WSSIOutputStream_DEFINED__
#define __WSSIOutputStream_DEFINED__

@protocol WSSIOutputStream <WFIClosable>
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned))success
          progress:(void (^)(unsigned))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSSIOutputStream_DEFINED__

// Windows.Storage.Streams.IRandomAccessStream
#ifndef __WSSIRandomAccessStream_DEFINED__
#define __WSSIRandomAccessStream_DEFINED__

@protocol WSSIRandomAccessStream <WFIClosable, WSSIInputStream, WSSIOutputStream>
@property (readonly) BOOL canRead;
@property (readonly) BOOL canWrite;
@property (readonly) uint64_t position;
@property uint64_t size;
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned))success
          progress:(void (^)(unsigned))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSIRandomAccessStream_DEFINED__

// Windows.Storage.Streams.IRandomAccessStreamWithContentType
#ifndef __WSSIRandomAccessStreamWithContentType_DEFINED__
#define __WSSIRandomAccessStreamWithContentType_DEFINED__

@protocol
    WSSIRandomAccessStreamWithContentType <WSSIRandomAccessStream, WFIClosable, WSSIInputStream, WSSIOutputStream, WSSIContentTypeProvider>
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned))success
          progress:(void (^)(unsigned))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSIRandomAccessStreamWithContentType_DEFINED__

// Windows.Foundation.IAsyncInfo
#ifndef __WFIAsyncInfo_DEFINED__
#define __WFIAsyncInfo_DEFINED__

@protocol WFIAsyncInfo
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned id;
@property (readonly) WFAsyncStatus status;
- (void)cancel;
- (void)close;
@end

#endif // __WFIAsyncInfo_DEFINED__

// Windows.Storage.Streams.DataReaderLoadOperation
#ifndef __WSSDataReaderLoadOperation_DEFINED__
#define __WSSDataReaderLoadOperation_DEFINED__

WINRT_EXPORT
@interface WSSDataReaderLoadOperation : RTObject <WFIAsyncInfo>
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned id;
@property (readonly) WFAsyncStatus status;
// Failed to generate property Completed (Can't marshal Windows.Foundation.AsyncOperationCompletedHandler`1<UInt32>)
// Could not find base class Windows.Foundation.IAsyncOperation`1<UInt32> type information
- (void)cancel;
- (void)close;
@end

#endif // __WSSDataReaderLoadOperation_DEFINED__

// Windows.Storage.Streams.DataReader
#ifndef __WSSDataReader_DEFINED__
#define __WSSDataReader_DEFINED__

WINRT_EXPORT
@interface WSSDataReader : RTObject <WSSIDataReader, WFIClosable>
+ (WSSDataReader*)fromBuffer:(RTObject<WSSIBuffer>*)buffer;
+ (WSSDataReader*)createDataReader:(RTObject<WSSIInputStream>*)inputStream ACTIVATOR;
@property WSSUnicodeEncoding unicodeEncoding;
@property WSSInputStreamOptions inputStreamOptions;
@property WSSByteOrder byteOrder;
@property (readonly) unsigned unconsumedBufferLength;
- (uint8_t)readByte;
// Failed to generate member ReadBytes (Only receive arrays are currently supported.)
- (RTObject<WSSIBuffer>*)readBuffer:(unsigned)length;
- (BOOL)readBoolean;
- (WFGUID*)readGuid;
- (short)readInt16;
- (int)readInt32;
- (int64_t)readInt64;
- (unsigned short)readUInt16;
- (unsigned)readUInt32;
- (uint64_t)readUInt64;
- (float)readSingle;
- (double)readDouble;
- (NSString*)readString:(unsigned)codeUnitCount;
- (WFDateTime*)readDateTime;
- (WFTimeSpan*)readTimeSpan;
- (WSSDataReaderLoadOperation*)loadAsync:(unsigned)count;
- (RTObject<WSSIBuffer>*)detachBuffer;
- (RTObject<WSSIInputStream>*)detachStream;
- (void)close;
@end

#endif // __WSSDataReader_DEFINED__

// Windows.Storage.Streams.DataWriterStoreOperation
#ifndef __WSSDataWriterStoreOperation_DEFINED__
#define __WSSDataWriterStoreOperation_DEFINED__

WINRT_EXPORT
@interface WSSDataWriterStoreOperation : RTObject <WFIAsyncInfo>
// Failed to generate property Completed (Can't marshal Windows.Foundation.AsyncOperationCompletedHandler`1<UInt32>)
@property (readonly) HRESULT errorCode;
@property (readonly) unsigned id;
@property (readonly) WFAsyncStatus status;
// Could not find base class Windows.Foundation.IAsyncOperation`1<UInt32> type information
- (void)cancel;
- (void)close;
@end

#endif // __WSSDataWriterStoreOperation_DEFINED__

// Windows.Storage.Streams.DataWriter
#ifndef __WSSDataWriter_DEFINED__
#define __WSSDataWriter_DEFINED__

WINRT_EXPORT
@interface WSSDataWriter : RTObject <WSSIDataWriter, WFIClosable>
+ (WSSDataWriter*)createDataWriter:(RTObject<WSSIOutputStream>*)outputStream ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property WSSUnicodeEncoding unicodeEncoding;
@property WSSByteOrder byteOrder;
@property (readonly) unsigned unstoredBufferLength;
- (void)writeByte:(uint8_t)value;
- (void)writeBytes:(id<NSFastEnumeration> /*UInt8*/)value;
- (void)writeBuffer:(RTObject<WSSIBuffer>*)buffer;
- (void)writeBufferRange:(RTObject<WSSIBuffer>*)buffer start:(unsigned)start count:(unsigned)count;
- (void)writeBoolean:(BOOL)value;
- (void)writeGuid:(WFGUID*)value;
- (void)writeInt16:(short)value;
- (void)writeInt32:(int)value;
- (void)writeInt64:(int64_t)value;
- (void)writeUInt16:(unsigned short)value;
- (void)writeUInt32:(unsigned)value;
- (void)writeUInt64:(uint64_t)value;
- (void)writeSingle:(float)value;
- (void)writeDouble:(double)value;
- (void)writeDateTime:(WFDateTime*)value;
- (void)writeTimeSpan:(WFTimeSpan*)value;
- (unsigned)writeString:(NSString*)value;
- (unsigned)measureString:(NSString*)value;
- (WSSDataWriterStoreOperation*)storeAsync;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (RTObject<WSSIBuffer>*)detachBuffer;
- (RTObject<WSSIOutputStream>*)detachStream;
- (void)close;
@end

#endif // __WSSDataWriter_DEFINED__

// Windows.Storage.Streams.RandomAccessStream
#ifndef __WSSRandomAccessStream_DEFINED__
#define __WSSRandomAccessStream_DEFINED__

WINRT_EXPORT
@interface WSSRandomAccessStream : RTObject
+ (void)copyAsync:(RTObject<WSSIInputStream>*)source
      destination:(RTObject<WSSIOutputStream>*)destination
          success:(void (^)(uint64_t))success
         progress:(void (^)(uint64_t))progress
          failure:(void (^)(NSError*))failure;
+ (void)copySizeAsync:(RTObject<WSSIInputStream>*)source
          destination:(RTObject<WSSIOutputStream>*)destination
          bytesToCopy:(uint64_t)bytesToCopy
              success:(void (^)(uint64_t))success
             progress:(void (^)(uint64_t))progress
              failure:(void (^)(NSError*))failure;
+ (void)copyAndCloseAsync:(RTObject<WSSIInputStream>*)source
              destination:(RTObject<WSSIOutputStream>*)destination
                  success:(void (^)(uint64_t))success
                 progress:(void (^)(uint64_t))progress
                  failure:(void (^)(NSError*))failure;
@end

#endif // __WSSRandomAccessStream_DEFINED__

// Windows.Storage.Streams.Buffer
#ifndef __WSSBuffer_DEFINED__
#define __WSSBuffer_DEFINED__

WINRT_EXPORT
@interface WSSBuffer : RTObject <WSSIBuffer>
+ (WSSBuffer*)create:(unsigned)capacity ACTIVATOR;
@property unsigned length;
@property (readonly) unsigned capacity;
@end

#endif // __WSSBuffer_DEFINED__

// Windows.Storage.Streams.RandomAccessStreamReference
#ifndef __WSSRandomAccessStreamReference_DEFINED__
#define __WSSRandomAccessStreamReference_DEFINED__

WINRT_EXPORT
@interface WSSRandomAccessStreamReference : RTObject <WSSIRandomAccessStreamReference>
+ (WSSRandomAccessStreamReference*)createFromFile:(RTObject<WSIStorageFile>*)file;
+ (WSSRandomAccessStreamReference*)createFromUri:(WFUri*)uri;
+ (WSSRandomAccessStreamReference*)createFromStream:(RTObject<WSSIRandomAccessStream>*)stream;
- (void)openReadAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSRandomAccessStreamReference_DEFINED__

// Windows.Storage.Streams.FileRandomAccessStream
#ifndef __WSSFileRandomAccessStream_DEFINED__
#define __WSSFileRandomAccessStream_DEFINED__

WINRT_EXPORT
@interface WSSFileRandomAccessStream : RTObject <WSSIRandomAccessStream, WSSIOutputStream, WFIClosable, WSSIInputStream>
@property uint64_t size;
@property (readonly) BOOL canRead;
@property (readonly) BOOL canWrite;
@property (readonly) uint64_t position;
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned))success
          progress:(void (^)(unsigned))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSFileRandomAccessStream_DEFINED__

// Windows.Storage.Streams.FileInputStream
#ifndef __WSSFileInputStream_DEFINED__
#define __WSSFileInputStream_DEFINED__

WINRT_EXPORT
@interface WSSFileInputStream : RTObject <WSSIInputStream, WFIClosable>
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSSFileInputStream_DEFINED__

// Windows.Storage.Streams.FileOutputStream
#ifndef __WSSFileOutputStream_DEFINED__
#define __WSSFileOutputStream_DEFINED__

WINRT_EXPORT
@interface WSSFileOutputStream : RTObject <WSSIOutputStream, WFIClosable>
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned))success
          progress:(void (^)(unsigned))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSSFileOutputStream_DEFINED__

// Windows.Storage.Streams.RandomAccessStreamOverStream
#ifndef __WSSRandomAccessStreamOverStream_DEFINED__
#define __WSSRandomAccessStreamOverStream_DEFINED__

WINRT_EXPORT
@interface WSSRandomAccessStreamOverStream : RTObject <WSSIRandomAccessStream, WSSIOutputStream, WFIClosable, WSSIInputStream>
@property uint64_t size;
@property (readonly) BOOL canRead;
@property (readonly) BOOL canWrite;
@property (readonly) uint64_t position;
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned))success
          progress:(void (^)(unsigned))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSRandomAccessStreamOverStream_DEFINED__

// Windows.Storage.Streams.InputStreamOverStream
#ifndef __WSSInputStreamOverStream_DEFINED__
#define __WSSInputStreamOverStream_DEFINED__

WINRT_EXPORT
@interface WSSInputStreamOverStream : RTObject <WSSIInputStream, WFIClosable>
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSSInputStreamOverStream_DEFINED__

// Windows.Storage.Streams.OutputStreamOverStream
#ifndef __WSSOutputStreamOverStream_DEFINED__
#define __WSSOutputStreamOverStream_DEFINED__

WINRT_EXPORT
@interface WSSOutputStreamOverStream : RTObject <WSSIOutputStream, WFIClosable>
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned))success
          progress:(void (^)(unsigned))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSSOutputStreamOverStream_DEFINED__

// Windows.Storage.Streams.InMemoryRandomAccessStream
#ifndef __WSSInMemoryRandomAccessStream_DEFINED__
#define __WSSInMemoryRandomAccessStream_DEFINED__

WINRT_EXPORT
@interface WSSInMemoryRandomAccessStream : RTObject <WSSIRandomAccessStream, WSSIOutputStream, WFIClosable, WSSIInputStream>
+ (instancetype)create ACTIVATOR;
@property uint64_t size;
@property (readonly) BOOL canRead;
@property (readonly) BOOL canWrite;
@property (readonly) uint64_t position;
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned))success
          progress:(void (^)(unsigned))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSInMemoryRandomAccessStream_DEFINED__
