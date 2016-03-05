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

@class MTLStencilDescriptor;
@class NSString;

METAL_EXPORT_CLASS
@interface MTLDepthStencilDescriptor : NSObject <NSCopying>

@property (nonatomic) MTLCompareFunction depthCompareFunction STUB_PROPERTY;
@property (getter=isDepthWriteEnabled, nonatomic) BOOL depthWriteEnabled STUB_PROPERTY;
@property (copy, nonatomic) MTLStencilDescriptor* backFaceStencil STUB_PROPERTY;
@property (copy, nonatomic) MTLStencilDescriptor* frontFaceStencil STUB_PROPERTY;
@property (copy, nonatomic) NSString* label STUB_PROPERTY;

@end
