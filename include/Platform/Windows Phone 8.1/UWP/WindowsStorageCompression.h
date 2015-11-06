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

#include "interopBase.h"
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

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

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

// Windows.Storage.Compression.Compressor
#ifndef __WSCCompressor_DEFINED__
#define __WSCCompressor_DEFINED__

WINRT_EXPORT
@interface WSCCompressor : RTObject <WSSIOutputStream, WFIClosable>
+ (WSCCompressor*)createCompressor:(RTObject<WSSIOutputStream>*)underlyingStream ACTIVATOR;
+ (WSCCompressor*)createCompressorEx:(RTObject<WSSIOutputStream>*)underlyingStream
                           algorithm:(WSCCompressAlgorithm)algorithm
                           blockSize:(unsigned)blockSize ACTIVATOR;
- (void)finishAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (RTObject<WSSIOutputStream>*)detachStream;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned))success
          progress:(void (^)(unsigned))progress
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
            count:(unsigned)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSSIInputStream_DEFINED__

// Windows.Storage.Compression.Decompressor
#ifndef __WSCDecompressor_DEFINED__
#define __WSCDecompressor_DEFINED__

WINRT_EXPORT
@interface WSCDecompressor : RTObject <WSSIInputStream, WFIClosable>
+ (WSCDecompressor*)createDecompressor:(RTObject<WSSIInputStream>*)underlyingStream ACTIVATOR;
- (RTObject<WSSIInputStream>*)detachStream;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSCDecompressor_DEFINED__
