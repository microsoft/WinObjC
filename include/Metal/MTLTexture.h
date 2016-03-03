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
#import <Metal/MetalExport.h>
#import <Foundation/NSRange.h>
#import <Metal/MetalDataTypes.h>
#import <Metal/MetalConstants.h>
#import <Metal/MTLResource.h>

@protocol MTLBuffer;

typedef NS_ENUM(NSUInteger, MTLTextureType) {
    MTLTextureType1D = 0,
    MTLTextureType1DArray = 1,
    MTLTextureType2D = 2,
    MTLTextureType2DArray = 3,
    MTLTextureType2DMultisample = 4,
    MTLTextureTypeCube = 5,
    MTLTextureType3D = 7
};

typedef NS_ENUM(NSUInteger, MTLTextureUsage) {
    MTLTextureUsageUnknown = 0x0000,
    MTLTextureUsageShaderRead = 0x0001,
    MTLTextureUsageShaderWrite = 0x0002,
    MTLTextureUsageRenderTarget = 0x0004,
    MTLTextureUsagePixelFormatView = 0x0010,
};

@protocol MTLTexture <MTLResource>

@property (readonly)MTLTextureType textureType;
@property (readonly)MTLPixelFormat pixelFormat;
@property (readonly)NSUInteger width;
@property (readonly)NSUInteger height;
@property (readonly)NSUInteger depth;
@property (readonly)NSUInteger mipmapLevelCount;
@property (readonly)NSUInteger arrayLength;
@property (readonly)NSUInteger sampleCount;
@property (readonly, getter = isFramebufferOnly) BOOL framebufferOnly;
@property (readonly)id<MTLResource> rootResource;
@property (readonly)MTLTextureUsage usage;
@property (readonly)id<MTLTexture> parentTexture;
@property (readonly)NSUInteger parentRelativeLevel;
@property (readonly)NSUInteger parentRelativeSlice;
@property (readonly)id<MTLBuffer> buffer;
@property (readonly)NSUInteger bufferOffset;
@property (readonly)NSUInteger bufferBytesPerRow;

- (void)replaceRegion:(MTLRegion)region
          mipmapLevel:(NSUInteger)level
                slice:(NSUInteger)slice
            withBytes:(const void*)pixelBytes
          bytesPerRow:(NSUInteger)bytesPerRow
    bytesPerImage:(NSUInteger)bytesPerImage;

- (void)replaceRegion:(MTLRegion)region mipmapLevel:(NSUInteger)level withBytes:(const void*)pixelBytes bytesPerRow:(NSUInteger)bytesPerRow;

- (void)getBytes:(void*)pixelBytes
     bytesPerRow:(NSUInteger)bytesPerRow
   bytesPerImage:(NSUInteger)bytesPerImage
      fromRegion:(MTLRegion)region
     mipmapLevel:(NSUInteger)mipmapLevel
    slice:(NSUInteger)slice;

- (void)getBytes:(void*)pixelBytes bytesPerRow:(NSUInteger)bytesPerRow fromRegion:(MTLRegion)region mipmapLevel:(NSUInteger)mipmapLevel;

- (id<MTLTexture>)newTextureViewWithPixelFormat:(MTLPixelFormat)pixelFormat;

- (id<MTLTexture>)newTextureViewWithPixelFormat:(MTLPixelFormat)pixelFormat
                                    textureType:(MTLTextureType)textureType
                                         levels:(NSRange)levelRange
                                         slices:(NSRange)sliceRange;
@end
