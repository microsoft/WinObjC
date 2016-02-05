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

#import <Metal/MetalExport.h>
#import <Foundation/NSRange.h>
#import <Metal/MetalDataTypes.h>
#import <Metal/MTLCommandEncoder.h>

@protocol MTLBuffer;
@protocol MTLTexture;

typedef NS_OPTIONS(NSUInteger, MTLBlitOption) {
    MTLBlitOptionNone = 0,
    MTLBlitOptionDepthFromDepthStencil = 1 << 0,
    MTLBlitOptionStencilFromDepthStencil = 1 << 1,
    MTLBlitOptionRowLinearPVRTC = 1 << 2
};

@protocol MTLBlitCommandEncoder <MTLCommandEncoder>

- (void)copyFromBuffer:(id<MTLBuffer>)sourceBuffer
          sourceOffset:(NSUInteger)sourceOffset
              toBuffer:(id<MTLBuffer>)destinationBuffer
     destinationOffset:(NSUInteger)destinationOffset
                  size:(NSUInteger)size;

- (void)copyFromBuffer:(id<MTLBuffer>)sourceBuffer
          sourceOffset:(NSUInteger)sourceOffset
     sourceBytesPerRow:(NSUInteger)sourceBytesPerRow
   sourceBytesPerImage:(NSUInteger)sourceBytesPerImage
            sourceSize:(MTLSize)sourceSize
             toTexture:(id<MTLTexture>)destinationTexture
      destinationSlice:(NSUInteger)destinationSlice
      destinationLevel:(NSUInteger)destinationLevel
     destinationOrigin:(MTLOrigin)destinationOrigin;

- (void)copyFromBuffer:(id<MTLBuffer>)sourceBuffer
          sourceOffset:(NSUInteger)sourceOffset
     sourceBytesPerRow:(NSUInteger)sourceBytesPerRow
   sourceBytesPerImage:(NSUInteger)sourceBytesPerImage
            sourceSize:(MTLSize)sourceSize
             toTexture:(id<MTLTexture>)destinationTexture
      destinationSlice:(NSUInteger)destinationSlice
      destinationLevel:(NSUInteger)destinationLevel
     destinationOrigin:(MTLOrigin)destinationOrigin
               options:(MTLBlitOption)options;

- (void)copyFromTexture:(id<MTLTexture>)sourceTexture
            sourceSlice:(NSUInteger)sourceSlice
            sourceLevel:(NSUInteger)sourceLevel
           sourceOrigin:(MTLOrigin)sourceOrigin
             sourceSize:(MTLSize)sourceSize
              toTexture:(id<MTLTexture>)destinationTexture
       destinationSlice:(NSUInteger)destinationSlice
       destinationLevel:(NSUInteger)destinationLevel
      destinationOrigin:(MTLOrigin)destinationOrigin;

- (void)copyFromTexture:(id<MTLTexture>)sourceTexture
                 sourceSlice:(NSUInteger)sourceSlice
                 sourceLevel:(NSUInteger)sourceLevel
                sourceOrigin:(MTLOrigin)sourceOrigin
                  sourceSize:(MTLSize)sourceSize
                    toBuffer:(id<MTLBuffer>)destinationBuffer
           destinationOffset:(NSUInteger)destinationOffset
      destinationBytesPerRow:(NSUInteger)destinationBytesPerRow
    destinationBytesPerImage:(NSUInteger)destinationBytesPerImage;

- (void)copyFromTexture:(id<MTLTexture>)sourceTexture
                 sourceSlice:(NSUInteger)sourceSlice
                 sourceLevel:(NSUInteger)sourceLevel
                sourceOrigin:(MTLOrigin)sourceOrigin
                  sourceSize:(MTLSize)sourceSize
                    toBuffer:(id<MTLBuffer>)destinationBuffer
           destinationOffset:(NSUInteger)destinationOffset
      destinationBytesPerRow:(NSUInteger)destinationBytesPerRow
    destinationBytesPerImage:(NSUInteger)destinationBytesPerImage
                     options:(MTLBlitOption)options;

- (void)fillBuffer:(id<MTLBuffer>)buffer range:(NSRange)range value:(uint8_t)value;

- (void)generateMipmapsForTexture:(id<MTLTexture>)texture;

@end
