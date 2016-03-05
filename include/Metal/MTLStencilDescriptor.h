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

typedef NS_ENUM(NSUInteger, MTLStencilOperation) {
    MTLStencilOperationKeep = 0,
    MTLStencilOperationZero = 1,
    MTLStencilOperationReplace = 2,
    MTLStencilOperationIncrementClamp = 3,
    MTLStencilOperationDecrementClamp = 4,
    MTLStencilOperationInvert = 5,
    MTLStencilOperationIncrementWrap = 6,
    MTLStencilOperationDecrementWrap = 7
};

METAL_EXPORT_CLASS
@interface MTLStencilDescriptor : NSObject <NSCopying>

@property (nonatomic) MTLStencilOperation stencilFailureOperation STUB_PROPERTY;
@property (nonatomic) MTLStencilOperation depthFailureOperation STUB_PROPERTY;
@property (nonatomic) MTLStencilOperation depthStencilPassOperation STUB_PROPERTY;
@property (nonatomic) MTLCompareFunction stencilCompareFunction STUB_PROPERTY;
@property (nonatomic) uint32_t readMask STUB_PROPERTY;
@property (nonatomic) uint32_t writeMask STUB_PROPERTY;

@end
