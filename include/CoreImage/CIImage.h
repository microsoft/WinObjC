//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <CoreImage/CoreImageExport.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreVideo/CVPixelBuffer.h>
#import <CoreVideo/CVImageBuffer.h>

#import <Foundation/NSObject.h>

@class NSString;
@class CIColor;
@class CIFilter;
@class NSData;
@class NSDictionary;
@class NSURL;
@protocol MTLTexture;
@class UIImage;
@class NSArray;

typedef int CIFormat;
COREIMAGE_EXPORT const CIFormat kCIFormatARGB8;
COREIMAGE_EXPORT const CIFormat kCIFormatBGRA8;
COREIMAGE_EXPORT const CIFormat kCIFormatRGBA8;
COREIMAGE_EXPORT const CIFormat kCIFormatABGR8;
COREIMAGE_EXPORT const CIFormat kCIFormatRGBAf;
COREIMAGE_EXPORT const CIFormat kCIFormatRGBAh;
COREIMAGE_EXPORT const CIFormat kCIFormatA8;
COREIMAGE_EXPORT const CIFormat kCIFormatA16;
COREIMAGE_EXPORT const CIFormat kCIFormatAh;
COREIMAGE_EXPORT const CIFormat kCIFormatAf;
COREIMAGE_EXPORT const CIFormat kCIFormatR8;
COREIMAGE_EXPORT const CIFormat kCIFormatR16;
COREIMAGE_EXPORT const CIFormat kCIFormatRh;
COREIMAGE_EXPORT const CIFormat kCIFormatRf;
COREIMAGE_EXPORT const CIFormat kCIFormatRG8;
COREIMAGE_EXPORT const CIFormat kCIFormatRG16;
COREIMAGE_EXPORT const CIFormat kCIFormatRGh;
COREIMAGE_EXPORT const CIFormat kCIFormatRGf;
COREIMAGE_EXPORT NSString* const kCIImageColorSpace;
COREIMAGE_EXPORT NSString* const kCIImageProperties;
COREIMAGE_EXPORT NSString* const kCIImageAutoAdjustEnhance;
COREIMAGE_EXPORT NSString* const kCIImageAutoAdjustRedEye;
COREIMAGE_EXPORT NSString* const kCIImageAutoAdjustFeatures;
COREIMAGE_EXPORT NSString* const kCIImageAutoAdjustCrop;
COREIMAGE_EXPORT NSString* const kCIImageAutoAdjustLevel;
COREIMAGE_EXPORT_CLASS
@interface CIImage : NSObject <NSCopying, NSSecureCoding>
+ (CIImage*)emptyImage;
+ (CIImage*)imageWithColor:(CIColor*)color;
+ (CIImage*)imageWithBitmapData:(NSData*)d
                    bytesPerRow:(size_t)bpr
                           size:(CGSize)size
                         format:(CIFormat)f
                     colorSpace:(CGColorSpaceRef)cs STUB_METHOD;
+ (CIImage*)imageWithCGImage:(CGImageRef)image;
+ (CIImage*)imageWithCGImage:(CGImageRef)image options:(NSDictionary*)options;
+ (CIImage*)imageWithContentsOfURL:(NSURL*)url STUB_METHOD;
+ (CIImage*)imageWithContentsOfURL:(NSURL*)url options:(NSDictionary*)options STUB_METHOD;
+ (CIImage*)imageWithCVImageBuffer:(CVImageBufferRef)imageBuffer STUB_METHOD;
+ (CIImage*)imageWithCVImageBuffer:(CVImageBufferRef)imageBuffer options:(NSDictionary*)dict STUB_METHOD;
+ (CIImage*)imageWithCVPixelBuffer:(CVPixelBufferRef)buffer STUB_METHOD;
+ (CIImage*)imageWithCVPixelBuffer:(CVPixelBufferRef)buffer options:(NSDictionary*)dict STUB_METHOD;
+ (CIImage*)imageWithData:(NSData*)data;
+ (CIImage*)imageWithData:(NSData*)data options:(NSDictionary*)options;
+ (CIImage*)imageWithImageProvider:(id)p
                              size:(size_t)
                             width:(size_t)height
                            format:(CIFormat)f
                        colorSpace:(CGColorSpaceRef)cs
                           options:(NSDictionary*)dict STUB_METHOD;
+ (CIImage*)imageWithTexture:(unsigned int)name size:(CGSize)size flipped:(BOOL)flag colorSpace:(CGColorSpaceRef)cs STUB_METHOD;
+ (CIImage*)imageWithMTLTexture:(id<MTLTexture>)texture options:(NSDictionary*)options STUB_METHOD;
- (CIImage*)imageByApplyingFilter:(NSString*)filterName withInputParameters:(NSDictionary*)params STUB_METHOD;
- (CIImage*)imageByApplyingTransform:(CGAffineTransform)matrix STUB_METHOD;
- (CIImage*)imageByCroppingToRect:(CGRect)rect;
- (CIImage*)imageByApplyingOrientation:(int)orientation STUB_METHOD;
- (CIImage*)imageByClampingToExtent STUB_METHOD;
- (CIImage*)imageByCompositingOverImage:(CIImage*)dest STUB_METHOD;
- (instancetype)initWithColor:(CIColor*)color;
- (instancetype)initWithBitmapData:(NSData*)d
                       bytesPerRow:(size_t)bpr
                              size:(CGSize)size
                            format:(CIFormat)f
                        colorSpace:(CGColorSpaceRef)c STUB_METHOD;
- (instancetype)initWithCGImage:(CGImageRef)image;
- (instancetype)initWithCGImage:(CGImageRef)image options:(NSDictionary*)options;
- (instancetype)initWithImage:(UIImage*)image;
- (instancetype)initWithImage:(UIImage*)image options:(NSDictionary*)options;
- (instancetype)initWithContentsOfURL:(NSURL*)url STUB_METHOD;
- (instancetype)initWithContentsOfURL:(NSURL*)url options:(NSDictionary*)d STUB_METHOD;
- (instancetype)initWithCVImageBuffer:(CVImageBufferRef)imageBuffer STUB_METHOD;
- (instancetype)initWithCVImageBuffer:(CVImageBufferRef)imageBuffer options:(NSDictionary*)dict STUB_METHOD;
- (instancetype)initWithCVPixelBuffer:(CVPixelBufferRef)buffer STUB_METHOD;
- (instancetype)initWithCVPixelBuffer:(CVPixelBufferRef)buffer options:(NSDictionary*)dict STUB_METHOD;
- (instancetype)initWithData:(NSData*)data;
- (instancetype)initWithData:(NSData*)data options:(NSDictionary*)options;
- (instancetype)initWithImageProvider:(id)p
                                 size:(size_t)
                                width:(size_t)height
                               format:(CIFormat)f
                           colorSpace:(CGColorSpaceRef)cs
                              options:(NSDictionary*)dict STUB_METHOD;
- (instancetype)initWithTexture:(unsigned int)name size:(CGSize)size flipped:(BOOL)flag colorSpace:(CGColorSpaceRef)cs STUB_METHOD;
- (instancetype)initWithMTLTexture:(id<MTLTexture>)texture options:(NSDictionary*)options STUB_METHOD;
@property (readonly, nonatomic) CGRect extent;
@property (readonly, atomic) NSDictionary* properties STUB_PROPERTY;
@property (readonly, atomic) NSURL* url STUB_PROPERTY;
@property (readonly, atomic) CGColorSpaceRef colorSpace STUB_PROPERTY;
- (CGAffineTransform)imageTransformForOrientation:(int)orientation STUB_METHOD;
- (NSArray*)autoAdjustmentFilters STUB_METHOD;
- (NSArray*)autoAdjustmentFiltersWithOptions:(NSDictionary*)options STUB_METHOD;
- (CGRect)regionOfInterestForImage:(CIImage*)im inRect:(CGRect)r STUB_METHOD;
@end
