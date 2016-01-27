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

@protocol MTLTexture;

typedef NS_ENUM(NSUInteger, MTLLoadAction) { MTLLoadActionDontCare = 0, MTLLoadActionLoad = 1, MTLLoadActionClear = 2 };
typedef NS_ENUM(NSUInteger, MTLStoreAction) { MTLStoreActionDontCare = 0, MTLStoreActionStore = 1, MTLStoreActionMultisampleResolve = 2 };

METAL_EXPORT_CLASS
@interface MTLRenderPassAttachmentDescriptor : NSObject <NSCopying>

@property (nonatomic, strong) id<MTLTexture> texture STUB_PROPERTY;
@property (nonatomic) NSUInteger level STUB_PROPERTY;
@property (nonatomic) NSUInteger slice STUB_PROPERTY;
@property (nonatomic) NSUInteger depthPlane STUB_PROPERTY;
@property (nonatomic) MTLLoadAction loadAction STUB_PROPERTY;
@property (nonatomic) MTLStoreAction storeAction STUB_PROPERTY;
@property (nonatomic, strong) id<MTLTexture> resolveTexture STUB_PROPERTY;
@property (nonatomic) NSUInteger resolveLevel STUB_PROPERTY;
@property (nonatomic) NSUInteger resolveSlice STUB_PROPERTY;
@property (nonatomic) NSUInteger resolveDepthPlane STUB_PROPERTY;

@end
