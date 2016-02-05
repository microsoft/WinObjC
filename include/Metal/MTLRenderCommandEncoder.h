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
#import <Metal/MetalDataTypes.h>
#import <Metal/MTLCommandEncoder.h>
#import <Foundation/NSRange.h>

@protocol MTLDepthStencilState;
@protocol MTLRenderPipelineState;
@protocol MTLBuffer;
@protocol MTLSamplerState;
@protocol MTLTexture;

typedef NS_ENUM(NSUInteger, MTLPrimitiveType) {
    MTLPrimitiveTypePoint = 0,
    MTLPrimitiveTypeLine = 1,
    MTLPrimitiveTypeLineStrip = 2,
    MTLPrimitiveTypeTriangle = 3,
    MTLPrimitiveTypeTriangleStrip = 4
};

typedef NS_ENUM(NSUInteger, MTLIndexType) { MTLIndexTypeUInt16 = 0, MTLIndexTypeUInt32 = 1 };

typedef NS_ENUM(NSUInteger, MTLVisibilityResultMode) {
    MTLVisibilityResultModeDisabled = 0,
    MTLVisibilityResultModeBoolean = 1,
    MTLVisibilityResultModeCounting = 2
};

typedef NS_ENUM(NSUInteger, MTLCullMode) { MTLCullModeNone = 0, MTLCullModeFront = 1, MTLCullModeBack = 2 };
typedef NS_ENUM(NSUInteger, MTLWinding) { MTLWindingClockwise = 0, MTLWindingCounterClockwise = 1 };
typedef NS_ENUM(NSUInteger, MTLDepthClipMode) { MTLDepthClipModeClip = 0, MTLDepthClipModeClamp = 1 };
typedef NS_ENUM(NSUInteger, MTLTriangleFillMode) { MTLTriangleFillModeFill = 0, MTLTriangleFillModeLines = 1 };

@protocol MTLRenderCommandEncoder <MTLCommandEncoder>

- (void)setBlendColorRed:(float)red green:(float)green blue:(float)blue alpha:(float)alpha;
- (void)setCullMode:(MTLCullMode)cullMode;
- (void)setDepthBias:(float)depthBias slopeScale:(float)slopeScale clamp:(float)clamp;
- (void)setDepthClipMode:(MTLDepthClipMode)depthClipMode;
- (void)setDepthStencilState:(id<MTLDepthStencilState>)depthStencilState;
- (void)setFrontFacingWinding:(MTLWinding)frontFacingWinding;
- (void)setRenderPipelineState:(id<MTLRenderPipelineState>)pipelineState;
- (void)setScissorRect:(MTLScissorRect)rect;
- (void)setStencilFrontReferenceValue:(uint32_t)frontReferenceValue backReferenceValue:(uint32_t)backReferenceValue;
- (void)setStencilReferenceValue:(uint32_t)ref;
- (void)setTriangleFillMode:(MTLTriangleFillMode)fillMode;
- (void)setViewport:(MTLViewport)viewport;
- (void)setVisibilityResultMode:(MTLVisibilityResultMode)mode offset:(NSUInteger)offset;
- (void)setVertexBuffer:(id<MTLBuffer>)buffer offset:(NSUInteger)offset atIndex:(NSUInteger)index;
- (void)setVertexBuffers:(id<MTLBuffer> _Nullable const[])buffers offsets:(const NSUInteger[])offsets withRange:(NSRange)range;
- (void)setVertexBufferOffset:(NSUInteger)offset atIndex:(NSUInteger)index;
- (void)setVertexBytes:(const void*)bytes length:(NSUInteger)length atIndex:(NSUInteger)index;
- (void)setVertexSamplerState:(id<MTLSamplerState>)sampler atIndex:(NSUInteger)index;
- (void)setVertexSamplerStates:(id<MTLSamplerState> _Nullable const[])samplers withRange:(NSRange)range;

- (void)setVertexSamplerState:(id<MTLSamplerState>)sampler
                  lodMinClamp:(float)lodMinClamp
                  lodMaxClamp:(float)lodMaxClamp
                      atIndex:(NSUInteger)index;

- (void)setVertexSamplerStates:(id<MTLSamplerState> _Nullable const[])samplers
                  lodMinClamps:(const float[])lodMinClamps
                  lodMaxClamps:(const float[])lodMaxClamps
                     withRange:(NSRange)range;

- (void)setVertexTexture:(id<MTLTexture>)texture atIndex:(NSUInteger)index;
- (void)setVertexTextures:(id<MTLTexture> _Nullable const[])textures withRange:(NSRange)range;
- (void)setFragmentBuffer:(id<MTLBuffer>)buffer offset:(NSUInteger)offset atIndex:(NSUInteger)index;
- (void)setFragmentBuffers:(id<MTLBuffer> _Nullable const[])buffers offsets:(const NSUInteger[])offsets withRange:(NSRange)range;
- (void)setFragmentBufferOffset:(NSUInteger)offset atIndex:(NSUInteger)index;
- (void)setFragmentBytes:(const void*)bytes length:(NSUInteger)length atIndex:(NSUInteger)index;
- (void)setFragmentSamplerState:(id<MTLSamplerState>)sampler atIndex:(NSUInteger)index;
- (void)setFragmentSamplerStates:(id<MTLSamplerState> _Nullable const[])samplers withRange:(NSRange)range;

- (void)setFragmentSamplerState:(id<MTLSamplerState>)sampler
                    lodMinClamp:(float)lodMinClamp
                    lodMaxClamp:(float)lodMaxClamp
                        atIndex:(NSUInteger)index;

- (void)setFragmentSamplerStates:(id<MTLSamplerState> _Nullable const[])samplers
                    lodMinClamps:(const float[])lodMinClamps
                    lodMaxClamps:(const float[])lodMaxClamps
                       withRange:(NSRange)range;

- (void)setFragmentTexture:(id<MTLTexture>)texture atIndex:(NSUInteger)index;
- (void)setFragmentTextures:(id<MTLTexture> _Nullable const[])textures withRange:(NSRange)range;

- (void)drawPrimitives:(MTLPrimitiveType)primitiveType
           vertexStart:(NSUInteger)vertexStart
           vertexCount:(NSUInteger)vertexCount
         instanceCount:(NSUInteger)instanceCount
          baseInstance:(NSUInteger)baseInstance;

- (void)drawPrimitives:(MTLPrimitiveType)primitiveType
           vertexStart:(NSUInteger)vertexStart
           vertexCount:(NSUInteger)vertexCount
         instanceCount:(NSUInteger)instanceCount;

- (void)drawPrimitives:(MTLPrimitiveType)primitiveType vertexStart:(NSUInteger)vertexStart vertexCount:(NSUInteger)vertexCount;

- (void)drawPrimitives:(MTLPrimitiveType)primitiveType
        indirectBuffer:(id<MTLBuffer>)indirectBuffer
  indirectBufferOffset:(NSUInteger)indirectBufferOffset;

- (void)drawIndexedPrimitives:(MTLPrimitiveType)primitiveType
                   indexCount:(NSUInteger)indexCount
                    indexType:(MTLIndexType)indexType
                  indexBuffer:(id<MTLBuffer>)indexBuffer
            indexBufferOffset:(NSUInteger)indexBufferOffset
                instanceCount:(NSUInteger)instanceCount
                   baseVertex:(NSInteger)baseVertex
                 baseInstance:(NSUInteger)baseInstance;

- (void)drawIndexedPrimitives:(MTLPrimitiveType)primitiveType
                   indexCount:(NSUInteger)indexCount
                    indexType:(MTLIndexType)indexType
                  indexBuffer:(id<MTLBuffer>)indexBuffer
            indexBufferOffset:(NSUInteger)indexBufferOffset
                instanceCount:(NSUInteger)instanceCount;

- (void)drawIndexedPrimitives:(MTLPrimitiveType)primitiveType
                   indexCount:(NSUInteger)indexCount
                    indexType:(MTLIndexType)indexType
                  indexBuffer:(id<MTLBuffer>)indexBuffer
            indexBufferOffset:(NSUInteger)indexBufferOffset;

- (void)drawIndexedPrimitives:(MTLPrimitiveType)primitiveType
                    indexType:(MTLIndexType)indexType
                  indexBuffer:(id<MTLBuffer>)indexBuffer
            indexBufferOffset:(NSUInteger)indexBufferOffset
               indirectBuffer:(id<MTLBuffer>)indirectBuffer
         indirectBufferOffset:(NSUInteger)indirectBufferOffset;

@end
