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

@class NSString;

typedef NS_ENUM(NSUInteger, MTLSamplerAddressMode) {
    MTLSamplerAddressModeClampToEdge = 0,
    MTLSamplerAddressModeRepeat = 2,
    MTLSamplerAddressModeMirrorRepeat = 3,
    MTLSamplerAddressModeClampToZero = 4
};

typedef NS_ENUM(NSUInteger, MTLSamplerMinMagFilter) { MTLSamplerMinMagFilterNearest = 0, MTLSamplerMinMagFilterLinear = 1 };

typedef NS_ENUM(NSUInteger, MTLSamplerMipFilter) {
    MTLSamplerMipFilterNotMipmapped = 0,
    MTLSamplerMipFilterNearest = 1,
    MTLSamplerMipFilterLinear = 2
};

METAL_EXPORT_CLASS
@interface MTLSamplerDescriptor : NSObject <NSCopying>

@property (nonatomic) MTLSamplerAddressMode rAddressMode STUB_PROPERTY;
@property (nonatomic) MTLSamplerAddressMode sAddressMode STUB_PROPERTY;
@property (nonatomic) MTLSamplerAddressMode tAddressMode STUB_PROPERTY;
@property (nonatomic) MTLSamplerMinMagFilter minFilter STUB_PROPERTY;
@property (nonatomic) MTLSamplerMinMagFilter magFilter STUB_PROPERTY;
@property (nonatomic) MTLSamplerMipFilter mipFilter STUB_PROPERTY;
@property (nonatomic) float lodMinClamp STUB_PROPERTY;
@property (nonatomic) float lodMaxClamp STUB_PROPERTY;
@property (nonatomic) BOOL lodAverage STUB_PROPERTY;
@property (nonatomic) NSUInteger maxAnisotropy STUB_PROPERTY;
@property (nonatomic) BOOL normalizedCoordinates STUB_PROPERTY;
@property (nonatomic) MTLCompareFunction compareFunction STUB_PROPERTY;
@property (copy, nonatomic) NSString* label STUB_PROPERTY;

@end
