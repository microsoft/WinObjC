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

#import <Foundation/NSObject.h>
#import <Metal/MetalDataTypes.h>
#import <Metal/MetalExport.h>
#import <Metal/MTLResource.h>

@class MTLRenderPipelineReflection;
@class MTLComputePipelineReflection;
@class NSString;
@class NSError;
@class MTLCompileOptions;
@class MTLTextureDescriptor;
@class MTLSamplerDescriptor;
@class MTLDepthStencilDescriptor;
@class MTLRenderPipelineDescriptor;
@class MTLComputePipelineDescriptor;

@protocol MTLLibrary;
@protocol MTLRenderPipelineState;
@protocol MTLComputePipelineState;
@protocol MTLCommandQueue;
@protocol MTLBuffer;
@protocol MTLTexture;
@protocol MTLSamplerState;
@protocol MTLDepthStencilState;
@protocol MTLFunction;
@protocol MTLDevice <NSObject>

typedef __autoreleasing MTLRenderPipelineReflection* MTLAutoreleasedRenderPipelineReflection;
typedef __autoreleasing MTLComputePipelineReflection* MTLAutoreleasedComputePipelineReflection;
typedef void (^MTLNewLibraryCompletionHandler)(id<MTLLibrary> library, NSError* error);
typedef void (^MTLNewRenderPipelineStateCompletionHandler)(id<MTLRenderPipelineState> renderPipelineState, NSError* error);
typedef void (^MTLNewRenderPipelineStateWithReflectionCompletionHandler)(id<MTLRenderPipelineState> renderPipelineState,
                                                                         MTLRenderPipelineReflection* reflection,
                                                                         NSError* error);
typedef void (^MTLNewComputePipelineStateCompletionHandler)(id<MTLComputePipelineState> computePipelineState, NSError* error);
typedef void (^MTLNewComputePipelineStateWithReflectionCompletionHandler)(id<MTLComputePipelineState> computePipelineState,
                                                                          MTLComputePipelineReflection* reflection,
                                                                          NSError* error);
typedef NS_ENUM(NSUInteger, MTLFeatureSet) {
    MTLFeatureSet_iOS_GPUFamily1_v1 = 0,
    MTLFeatureSet_iOS_GPUFamily2_v1 = 1,
    MTLFeatureSet_iOS_GPUFamily1_v2 = 2,
    MTLFeatureSet_iOS_GPUFamily2_v2 = 3,
    MTLFeatureSet_iOS_GPUFamily3_v1 = 4,
};

typedef NS_OPTIONS(NSUInteger, MTLPipelineOption) {
    MTLPipelineOptionNone = 0,
    MTLPipelineOptionArgumentInfo = 1 << 0,
    MTLPipelineOptionBufferTypeInfo = 1 << 1
};

@property (readonly) MTLSize maxThreadsPerThreadgroup;
@property (readonly) NSString* name;

- (BOOL)supportsFeatureSet:(MTLFeatureSet)featureSet;
- (BOOL)supportsTextureSampleCount:(NSUInteger)sampleCount;
- (id<MTLLibrary>)newDefaultLibrary;
- (id<MTLLibrary>)newLibraryWithFile:(NSString*)filepath error:(NSError* _Nullable*)error;
- (void)newLibraryWithSource:(NSString*)source
                     options:(MTLCompileOptions*)options
           completionHandler:(MTLNewLibraryCompletionHandler)completionHandler;
- (id<MTLLibrary>)newLibraryWithSource:(NSString*)source options:(MTLCompileOptions*)options error:(NSError* _Nullable*)error;

//TODO: 6309370 MTLDevice.h used dispatch_data_t which is only availabe in new version of libdispatch
// - (id<MTLLibrary>)newLibraryWithData:(dispatch_data_t)data error:(NSError * _Nullable *)error;

- (id<MTLCommandQueue>)newCommandQueue;
- (id<MTLCommandQueue>)newCommandQueueWithMaxCommandBufferCount:(NSUInteger)maxCommandBufferCount;
- (id<MTLBuffer>)newBufferWithLength:(NSUInteger)length options:(MTLResourceOptions)options;
- (id<MTLBuffer>)newBufferWithBytes:(const void*)pointer length:(NSUInteger)length options:(MTLResourceOptions)options;
- (id<MTLBuffer>)newBufferWithBytesNoCopy:(void*)pointer
                                   length:(NSUInteger)length
                                  options:(MTLResourceOptions)options
                              deallocator:(void (^)(void* pointer, NSUInteger length))deallocator;
- (id<MTLTexture>)newTextureWithDescriptor:(MTLTextureDescriptor*)descriptor;
- (id<MTLSamplerState>)newSamplerStateWithDescriptor:(MTLSamplerDescriptor*)descriptor;
- (id<MTLDepthStencilState>)newDepthStencilStateWithDescriptor:(MTLDepthStencilDescriptor*)descriptor;
- (void)newRenderPipelineStateWithDescriptor:(MTLRenderPipelineDescriptor*)descriptor
                           completionHandler:(MTLNewRenderPipelineStateCompletionHandler)completionHandler;
- (void)newRenderPipelineStateWithDescriptor:(MTLRenderPipelineDescriptor*)descriptor
                                     options:(MTLPipelineOption)options
                           completionHandler:(MTLNewRenderPipelineStateWithReflectionCompletionHandler)completionHandler;
- (id<MTLRenderPipelineState>)newRenderPipelineStateWithDescriptor:(MTLRenderPipelineDescriptor*)descriptor
                                                             error:(NSError* _Nullable*)error;
- (id<MTLRenderPipelineState>)newRenderPipelineStateWithDescriptor:(MTLRenderPipelineDescriptor*)descriptor
                                                           options:(MTLPipelineOption)options
                                                        reflection:(MTLAutoreleasedRenderPipelineReflection*)reflection
                                                             error:(NSError* _Nullable*)error;
- (void)newComputePipelineStateWithFunction:(id<MTLFunction>)function
                          completionHandler:(MTLNewComputePipelineStateCompletionHandler)completionHandler;
- (void)newComputePipelineStateWithFunction:(id<MTLFunction>)function
                                    options:(MTLPipelineOption)options
                          completionHandler:(MTLNewComputePipelineStateWithReflectionCompletionHandler)completionHandler;
- (id<MTLComputePipelineState>)newComputePipelineStateWithFunction:(id<MTLFunction>)function error:(NSError* _Nullable*)error;
- (id<MTLComputePipelineState>)newComputePipelineStateWithFunction:(id<MTLFunction>)function
                                                           options:(MTLPipelineOption)options
                                                        reflection:(MTLAutoreleasedComputePipelineReflection*)reflection
                                                             error:(NSError* _Nullable*)error;
- (void)newComputePipelineStateWithDescriptor:(MTLComputePipelineDescriptor*)descriptor
                                      options:(MTLPipelineOption)options
                            completionHandler:(MTLNewComputePipelineStateWithReflectionCompletionHandler)completionHandler;
- (id<MTLComputePipelineState>)newComputePipelineStateWithDescriptor:(MTLComputePipelineDescriptor*)descriptor
                                                             options:(MTLPipelineOption)options
                                                          reflection:(MTLAutoreleasedComputePipelineReflection*)reflection
                                                               error:(NSError* _Nullable*)error;
@end
