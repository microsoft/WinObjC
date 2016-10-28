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

// WindowsStorageCompression.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_STORAGE_COMPRESSION_EXPORT
#define OBJCUWP_WINDOWS_STORAGE_COMPRESSION_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Storage_Compression.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSCCompressor, WSCDecompressor;
@protocol WSCICompressor
, WSCIDecompressor, WSCICompressorFactory, WSCIDecompressorFactory;

// Windows.Storage.Compression.CompressAlgorithm
enum _WSCCompressAlgorithm {
    WSCCompressAlgorithmInvalidAlgorithm = 0,
    WSCCompressAlgorithmNullAlgorithm = 1,
    WSCCompressAlgorithmMszip = 2,
    WSCCompressAlgorithmXpress = 3,
    WSCCompressAlgorithmXpressHuff = 4,
    WSCCompressAlgorithmLzms = 5,
};
typedef unsigned WSCCompressAlgorithm;

#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWP_WINDOWS_STORAGE_COMPRESSION_EXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Storage.Streams.IOutputStream
#ifndef __WSSIOutputStream_DEFINED__
#define __WSSIOutputStream_DEFINED__

@protocol WSSIOutputStream <WFIClosable>
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned int))success
          progress:(void (^)(unsigned int))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

OBJCUWP_WINDOWS_STORAGE_COMPRESSION_EXPORT
@interface WSSIOutputStream : RTObject <WSSIOutputStream>
@end

#endif // __WSSIOutputStream_DEFINED__

// Windows.Storage.Compression.Compressor
#ifndef __WSCCompressor_DEFINED__
#define __WSCCompressor_DEFINED__

OBJCUWP_WINDOWS_STORAGE_COMPRESSION_EXPORT
@interface WSCCompressor : RTObject <WSSIOutputStream, WFIClosable>
+ (WSCCompressor*)makeCompressor:(RTObject<WSSIOutputStream>*)underlyingStream ACTIVATOR;
+ (WSCCompressor*)makeCompressorEx:(RTObject<WSSIOutputStream>*)underlyingStream
                         algorithm:(WSCCompressAlgorithm)algorithm
                         blockSize:(unsigned int)blockSize ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (void)finishAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (RTObject<WSSIOutputStream>*)detachStream;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned int))success
          progress:(void (^)(unsigned int))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSCCompressor_DEFINED__

// Windows.Storage.Streams.IInputStream
#ifndef __WSSIInputStream_DEFINED__
#define __WSSIInputStream_DEFINED__

@protocol WSSIInputStream <WFIClosable>
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned int)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure;
- (void)close;
@end

OBJCUWP_WINDOWS_STORAGE_COMPRESSION_EXPORT
@interface WSSIInputStream : RTObject <WSSIInputStream>
@end

#endif // __WSSIInputStream_DEFINED__

// Windows.Storage.Compression.Decompressor
#ifndef __WSCDecompressor_DEFINED__
#define __WSCDecompressor_DEFINED__

OBJCUWP_WINDOWS_STORAGE_COMPRESSION_EXPORT
@interface WSCDecompressor : RTObject <WSSIInputStream, WFIClosable>
+ (WSCDecompressor*)makeDecompressor:(RTObject<WSSIInputStream>*)underlyingStream ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (RTObject<WSSIInputStream>*)detachStream;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned int)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSCDecompressor_DEFINED__
