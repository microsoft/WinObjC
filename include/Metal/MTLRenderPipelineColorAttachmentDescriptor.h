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

typedef NS_ENUM(NSUInteger, MTLBlendOperation) {
    MTLBlendOperationAdd = 0,
    MTLBlendOperationSubtract = 1,
    MTLBlendOperationReverseSubtract = 2,
    MTLBlendOperationMin = 3,
    MTLBlendOperationMax = 4
};

typedef NS_ENUM(NSUInteger, MTLBlendFactor) {
    MTLBlendFactorZero = 0,
    MTLBlendFactorOne = 1,
    MTLBlendFactorSourceColor = 2,
    MTLBlendFactorOneMinusSourceColor = 3,
    MTLBlendFactorSourceAlpha = 4,
    MTLBlendFactorOneMinusSourceAlpha = 5,
    MTLBlendFactorDestinationColor = 6,
    MTLBlendFactorOneMinusDestinationColor = 7,
    MTLBlendFactorDestinationAlpha = 8,
    MTLBlendFactorOneMinusDestinationAlpha = 9,
    MTLBlendFactorSourceAlphaSaturated = 10,
    MTLBlendFactorBlendColor = 11,
    MTLBlendFactorOneMinusBlendColor = 12,
    MTLBlendFactorBlendAlpha = 13,
    MTLBlendFactorOneMinusBlendAlpha = 14
};

typedef NS_ENUM(NSUInteger, MTLColorWriteMask) {
    MTLColorWriteMaskNone = 0,
    MTLColorWriteMaskRed = 0x1 << 3,
    MTLColorWriteMaskGreen = 0x1 << 2,
    MTLColorWriteMaskBlue = 0x1 << 1,
    MTLColorWriteMaskAlpha = 0x1 << 0,
    MTLColorWriteMaskAll = 0xf
};

METAL_EXPORT_CLASS
@interface MTLRenderPipelineColorAttachmentDescriptor : NSObject <NSCopying>

@property (nonatomic) MTLPixelFormat pixelFormat STUB_PROPERTY;
@property (nonatomic) MTLColorWriteMask writeMask STUB_PROPERTY;
@property (getter=isBlendingEnabled, nonatomic) BOOL blendingEnabled STUB_PROPERTY;
@property (nonatomic) MTLBlendOperation alphaBlendOperation STUB_PROPERTY;
@property (nonatomic) MTLBlendOperation rgbBlendOperation STUB_PROPERTY;
@property (nonatomic) MTLBlendFactor destinationAlphaBlendFactor STUB_PROPERTY;
@property (nonatomic) MTLBlendFactor destinationRGBBlendFactor STUB_PROPERTY;
@property (nonatomic) MTLBlendFactor sourceAlphaBlendFactor STUB_PROPERTY;
@property (nonatomic) MTLBlendFactor sourceRGBBlendFactor STUB_PROPERTY;

@end
