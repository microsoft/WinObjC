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

#import <CoreFoundation/CFDate.h>
#import <Foundation/NSObject.h>
#import <Metal/MetalExport.h>

@class NSString;
@class MTLRenderPassDescriptor;
@class NSError;
@protocol MTLCommandBuffer;
@protocol MTLRenderCommandEncoder;
@protocol MTLComputeCommandEncoder;
@protocol MTLBlitCommandEncoder;
@protocol MTLParallelRenderCommandEncoder;
@protocol MTLDrawable;
@protocol MTLDevice;
@protocol MTLCommandQueue;

typedef void (^MTLCommandBufferHandler)(id<MTLCommandBuffer> buffer);

typedef NS_ENUM(NSUInteger, MTLCommandBufferStatus) {
    MTLCommandBufferStatusNotEnqueued = 0,
    MTLCommandBufferStatusEnqueued = 1,
    MTLCommandBufferStatusCommitted = 2,
    MTLCommandBufferStatusScheduled = 3,
    MTLCommandBufferStatusCompleted = 4,
    MTLCommandBufferStatusError = 5
};

typedef NS_ENUM(NSUInteger, MTLCommandBufferError) {
    MTLCommandBufferErrorNone = 0,
    MTLCommandBufferErrorInternal = 1,
    MTLCommandBufferErrorTimeout = 2,
    MTLCommandBufferErrorPageFault = 3,
    MTLCommandBufferErrorBlacklisted = 4,
    MTLCommandBufferErrorNotPermitted = 7,
    MTLCommandBufferErrorOutOfMemory = 8,
    MTLCommandBufferErrorInvalidResource = 9
};

METAL_EXPORT NSString* const MTLCommandBufferErrorDomain;

@protocol MTLCommandBuffer <NSObject>

@property (readonly)MTLCommandBufferStatus status;
@property (readonly)NSError* error;
@property (readonly)BOOL retainedReferences;
@property (readonly)id<MTLDevice> device;
@property (readonly)id<MTLCommandQueue> commandQueue;
@property (copy, atomic) NSString* label;

- (id<MTLRenderCommandEncoder>)renderCommandEncoderWithDescriptor:(MTLRenderPassDescriptor*)renderPassDescriptor;
- (id<MTLComputeCommandEncoder>)computeCommandEncoder;
- (id<MTLBlitCommandEncoder>)blitCommandEncoder;
- (id<MTLParallelRenderCommandEncoder>)parallelRenderCommandEncoderWithDescriptor:(MTLRenderPassDescriptor*)renderPassDescriptor;
- (void)enqueue;
- (void)commit;
- (void)addScheduledHandler:(MTLCommandBufferHandler)block;
- (void)addCompletedHandler:(MTLCommandBufferHandler)block;
- (void)presentDrawable:(id<MTLDrawable>)drawable;
- (void)presentDrawable:(id<MTLDrawable>)drawable atTime:(CFTimeInterval)presentationTime;
- (void)waitUntilScheduled;
- (void)waitUntilCompleted;

@end
