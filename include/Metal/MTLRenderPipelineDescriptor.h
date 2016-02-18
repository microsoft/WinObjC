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
#import <Metal/MetalConstants.h>
#import <Metal/MetalExport.h>

@protocol MTLFunction;
@class MTLVertexDescriptor;
@class MTLRenderPipelineColorAttachmentDescriptorArray;
@class NSString;

METAL_EXPORT_CLASS
@interface MTLRenderPipelineDescriptor : NSObject <NSCopying>

@property (readwrite, nonatomic, strong) id<MTLFunction> fragmentFunction STUB_PROPERTY;
@property (readwrite, nonatomic, strong) id<MTLFunction> vertexFunction STUB_PROPERTY;
@property (copy, nonatomic) MTLVertexDescriptor* vertexDescriptor STUB_PROPERTY;
@property (readonly)MTLRenderPipelineColorAttachmentDescriptorArray* colorAttachments STUB_PROPERTY;
@property (nonatomic)MTLPixelFormat depthAttachmentPixelFormat STUB_PROPERTY;
@property (nonatomic)MTLPixelFormat stencilAttachmentPixelFormat STUB_PROPERTY;
@property (readwrite, nonatomic) NSUInteger sampleCount STUB_PROPERTY;
@property (getter = isAlphaToCoverageEnabled, readwrite, nonatomic) BOOL alphaToCoverageEnabled STUB_PROPERTY;
@property (getter = isAlphaToOneEnabled, readwrite, nonatomic) BOOL alphaToOneEnabled STUB_PROPERTY;
@property (getter = isRasterizationEnabled, readwrite, nonatomic) BOOL rasterizationEnabled STUB_PROPERTY;
@property (copy, nonatomic) NSString* label STUB_PROPERTY;

- (void)reset STUB_METHOD;

@end
