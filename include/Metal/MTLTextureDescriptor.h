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
#import <Metal/MTLResource.h>
#import <Metal/MTLTexture.h>

METAL_EXPORT_CLASS
@interface MTLTextureDescriptor : NSObject <NSCopying>

+ (MTLTextureDescriptor*)texture2DDescriptorWithPixelFormat:(MTLPixelFormat)pixelFormat
                                                      width:(NSUInteger)width
                                                     height:(NSUInteger)height
                                                  mipmapped:(BOOL)mipmapped STUB_METHOD;

+ (MTLTextureDescriptor*)textureCubeDescriptorWithPixelFormat:(MTLPixelFormat)pixelFormat
                                                         size:(NSUInteger)size
                                                    mipmapped:(BOOL)mipmapped STUB_METHOD;

@property (readwrite, nonatomic) MTLTextureType textureType STUB_PROPERTY;
@property (readwrite, nonatomic) MTLPixelFormat pixelFormat STUB_PROPERTY;
@property (readwrite, nonatomic) NSUInteger width STUB_PROPERTY;
@property (readwrite, nonatomic) NSUInteger height STUB_PROPERTY;
@property (readwrite, nonatomic) NSUInteger depth STUB_PROPERTY;
@property (readwrite, nonatomic) NSUInteger mipmapLevelCount STUB_PROPERTY;
@property (readwrite, nonatomic) NSUInteger sampleCount STUB_PROPERTY;
@property (readwrite, nonatomic) NSUInteger arrayLength STUB_PROPERTY;
@property (readwrite, nonatomic) MTLResourceOptions resourceOptions STUB_PROPERTY;
@property (readwrite, nonatomic) MTLCPUCacheMode cpuCacheMode STUB_PROPERTY;
@property (readwrite, nonatomic) MTLStorageMode storageMode STUB_PROPERTY;
@property (readwrite, nonatomic) MTLTextureUsage usage STUB_PROPERTY;

@end
