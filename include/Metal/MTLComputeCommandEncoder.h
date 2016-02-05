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

#import <Metal/MetalDataTypes.h>
#import <Metal/MetalExport.h>
#import <Metal/MTLCommandEncoder.h>
#import <Foundation/NSRange.h>

@protocol MTLComputePipelineState;
@protocol MTLBuffer;
@protocol MTLTexture;
@protocol MTLSamplerState;

@protocol MTLComputeCommandEncoder <MTLCommandEncoder>

- (void)setComputePipelineState:(id<MTLComputePipelineState>)state;
- (void)setBuffer:(id<MTLBuffer>)buffer offset:(NSUInteger)offset atIndex:(NSUInteger)index;
- (void)setBuffers:(id<MTLBuffer> _Nullable const[])buffers offsets:(const NSUInteger[])offsets withRange:(NSRange)range;
- (void)setBufferOffset:(NSUInteger)offset atIndex:(NSUInteger)index;
- (void)setBytes:(const void*)bytes length:(NSUInteger)length atIndex:(NSUInteger)index;
- (void)setTexture:(id<MTLTexture>)texture atIndex:(NSUInteger)index;
- (void)setTextures:(id<MTLTexture> _Nullable const[])textures withRange:(NSRange)range;
- (void)setSamplerState:(id<MTLSamplerState>)sampler atIndex:(NSUInteger)index;
- (void)setSamplerStates:(id<MTLSamplerState> _Nullable const[])samplers withRange:(NSRange)range;
- (void)setSamplerState:(id<MTLSamplerState>)sampler
            lodMinClamp:(float)lodMinClamp
            lodMaxClamp:(float)lodMaxClamp
                atIndex:(NSUInteger)index;
- (void)setSamplerStates:(id<MTLSamplerState> _Nullable const[])samplers
            lodMinClamps:(const float[])lodMinClamps
            lodMaxClamps:(const float[])lodMaxClamps
               withRange:(NSRange)range;
- (void)setThreadgroupMemoryLength:(NSUInteger)length atIndex:(NSUInteger)index;
- (void)dispatchThreadgroups:(MTLSize)threadgroupsPerGrid threadsPerThreadgroup:(MTLSize)threadsPerThreadgroup;
- (void)dispatchThreadgroupsWithIndirectBuffer:(id<MTLBuffer>)indirectBuffer
                          indirectBufferOffset:(NSUInteger)indirectBufferOffset
                         threadsPerThreadgroup:(MTLSize)threadsPerThreadgroup;

@end
