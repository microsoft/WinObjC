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
#import <Metal/MetalExport.h>

@class MTLVertexAttributeDescriptorArray;
@class MTLVertexBufferLayoutDescriptorArray;

METAL_EXPORT_CLASS
@interface MTLVertexDescriptor : NSObject <NSCopying>

+ (MTLVertexDescriptor*)vertexDescriptor STUB_METHOD;

@property (readonly)MTLVertexAttributeDescriptorArray* attributes STUB_PROPERTY;
@property (readonly)MTLVertexBufferLayoutDescriptorArray* layouts STUB_PROPERTY;

- (void)reset STUB_METHOD;

@end
