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

#import <Starboard.h>
#import <StubReturn.h>

#import <CoreImage/CIImage.h>
#import <CoreImage/CIColor.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIGraphics.h>
#import <UIKit/UIImage.h>
#import <math.h>
#import "CIImageInternal.h"
#import "CGImageInternal.h"

/** @Status Stub */
const CIFormat kCIFormatARGB8 = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatBGRA8 = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatRGBA8 = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatABGR8 = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatRGBAf = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatRGBAh = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatA8 = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatA16 = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatAh = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatAf = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatR8 = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatR16 = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatRh = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatRf = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatRG8 = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatRG16 = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatRGh = StubConstant();
/** @Status Stub */
const CIFormat kCIFormatRGf = StubConstant();

NSString* const kCIImageColorSpace = @"kCIImageColorSpace";
NSString* const kCIImageProperties = @"kCIImageProperties";
NSString* const kCIImageAutoAdjustEnhance = @"kCIImageAutoAdjustEnhance";
NSString* const kCIImageAutoAdjustRedEye = @"kCIImageAutoAdjustRedEye";
NSString* const kCIImageAutoAdjustFeatures = @"kCIImageAutoAdjustFeatures";
NSString* const kCIImageAutoAdjustCrop = @"kCIImageAutoAdjustCrop";
NSString* const kCIImageAutoAdjustLevel = @"kCIImageAutoAdjustLevel";

@implementation CIImage

/**
 @Status Interoperable
*/
+ (CIImage*)emptyImage {
    static CIImage* emptyImg = [CIImage new];
    return emptyImg;
}

/**
 @Status Interoperable
*/
- (CGRect)extent {
    return _extent;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self = [super init]) {
        _extent = CGRectInfinite;
    }
    return self;
}

- (instancetype)_initWithCGImage:(CGImageRef)image color:(CIColor*)color {
    if (self = [self initWithCGImage:image]) {
        _color.attach([static_cast<id>(color) copy]);
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithColor:(CIColor*)color {
    if (!color) {
        [self release];
        return nil;
    }

    if (self = [self init]) {
        _color.attach([static_cast<id>(color) copy]);
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCGImage:(CGImageRef)cgImage {
    return [self initWithCGImage:cgImage options:nil];
}

/**
 @Status Caveat
 @Notes options not supported
*/
- (instancetype)initWithCGImage:(CGImageRef)image options:(NSDictionary*)options {
    if (!image) {
        [self release];
        return nil;
    }

    if (self = [self init]) {
        _cgImage.reset(CGImageRetain(image));
        _extent = CGRectMake(0, 0, CGImageGetWidth(image), CGImageGetHeight(image));
        _options.attach([options copy]);
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithImage:(UIImage*)image {
    return [self initWithImage:image options:nil];
}

/**
 @Status Caveat
 @Notes options not supported
*/
- (instancetype)initWithImage:(UIImage*)image options:(NSDictionary*)options {
    if (!image) {
        [self release];
        return nil;
    }
    return [self initWithCGImage:[image CGImage] options:options];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithData:(NSData*)data {
    return [self initWithData:data options:nil];
}

/**
 @Status Caveat
 @Notes options not supported
*/
- (instancetype)initWithData:(NSData*)data options:(NSDictionary*)options {
    if (!data) {
        [self release];
        return nil;
    }
    return [self initWithCGImage:_CGImageGetImageFromData((void*)[data bytes], [data length]) options:options];
}

/**
 @Status Interoperable
*/
+ (CIImage*)imageWithColor:(CIColor*)color {
    RETURN_NULL_IF(!color);
    return [[[CIImage alloc] initWithColor:color] autorelease];
}

/**
 @Status Stub
 @Notes
*/
+ (CIImage*)imageWithBitmapData:(NSData*)d bytesPerRow:(size_t)bpr size:(CGSize)size format:(CIFormat)f colorSpace:(CGColorSpaceRef)cs {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
+ (CIImage*)imageWithData:(NSData*)data {
    return [CIImage imageWithData:data options:nil];
}

/**
 @Status Caveat
 @Notes options not supported
*/
+ (CIImage*)imageWithData:(NSData*)data options:(NSDictionary*)options {
    RETURN_NULL_IF(!data);
    return [[[CIImage alloc] initWithData:data options:options] autorelease];
}

/**
 @Status Interoperable
*/
+ (CIImage*)imageWithCGImage:(CGImageRef)image {
    return [self imageWithCGImage:image options:nil];
}

/**
 @Status Caveat
 @Notes options not supported
*/
+ (CIImage*)imageWithCGImage:(CGImageRef)image options:(NSDictionary*)options {
    RETURN_NULL_IF(!image);
    return [[[CIImage alloc] initWithCGImage:image options:options] autorelease];
}

/**
 @Status Stub
 @Notes
*/
+ (CIImage*)imageWithContentsOfURL:(NSURL*)url {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (CIImage*)imageWithContentsOfURL:(NSURL*)url options:(NSDictionary*)d {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (CIImage*)imageWithCVImageBuffer:(CVImageBufferRef)imageBuffer {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (CIImage*)imageWithCVImageBuffer:(CVImageBufferRef)imageBuffer options:(NSDictionary*)dict {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (CIImage*)imageWithCVPixelBuffer:(CVPixelBufferRef)buffer {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (CIImage*)imageWithCVPixelBuffer:(CVPixelBufferRef)buffer options:(NSDictionary*)dict {
    UNIMPLEMENTED();
    return StubReturn();
}

// clang-format off
// clang format doesn't approve of unlabeled parameters
/**
 @Status Stub
 @Notes
*/
+ (CIImage*)imageWithImageProvider:(id)p
                              size:(size_t)width
                                  :(size_t)height
                            format:(CIFormat)f
                        colorSpace:(CGColorSpaceRef)cs
                           options:(NSDictionary*)dict {
    UNIMPLEMENTED();
    return StubReturn();
}
// clang-format on

/**
 @Status Stub
 @Notes
*/
+ (CIImage*)imageWithTexture:(unsigned int)name size:(CGSize)size flipped:(BOOL)flag colorSpace:(CGColorSpaceRef)cs {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (CIImage*)imageWithMTLTexture:(id<MTLTexture>)texture options:(NSDictionary*)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (CIImage*)imageByApplyingFilter:(NSString*)filterName withInputParameters:(NSDictionary*)params {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (CIImage*)imageByApplyingTransform:(CGAffineTransform)matrix {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (CIImage*)imageByCroppingToRect:(CGRect)rect {
    if (_cgImage != nil) {
        woc::unique_cf<CGImageRef> croppedImage{ CGImageCreateWithImageInRect(_cgImage.get(), rect) };
        return [CIImage imageWithCGImage:croppedImage.get()];
    } else if (_color != nil) {
        UIGraphicsBeginImageContext(rect.size);
        CGContextRef context = UIGraphicsGetCurrentContext();
        CIColor* color = static_cast<CIColor*>(_color);
        CGContextSetRGBFillColor(context, color.red, color.green, color.blue, color.alpha);
        CGContextFillRect(context, rect);
        woc::unique_cf<CGImageRef> imageRef{ CGBitmapContextCreateImage(context) };
        UIGraphicsEndImageContext();
        return [[[CIImage alloc] _initWithCGImage:imageRef.get() color:_color] autorelease];
    }

    return [CIImage emptyImage];
}

/**
 @Status Stub
 @Notes
*/
- (CIImage*)imageByApplyingOrientation:(int)orientation {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (CIImage*)imageByClampingToExtent {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (CIImage*)imageByCompositingOverImage:(CIImage*)dest {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithBitmapData:(NSData*)d bytesPerRow:(size_t)bpr size:(CGSize)size format:(CIFormat)f colorSpace:(CGColorSpaceRef)c {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithContentsOfURL:(NSURL*)url {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithContentsOfURL:(NSURL*)url options:(NSDictionary*)d {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCVImageBuffer:(CVImageBufferRef)imageBuffer {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCVImageBuffer:(CVImageBufferRef)imageBuffer options:(NSDictionary*)dict {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCVPixelBuffer:(CVPixelBufferRef)buffer {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCVPixelBuffer:(CVPixelBufferRef)buffer options:(NSDictionary*)dict {
    UNIMPLEMENTED();
    return StubReturn();
}

// clang-format off
// clang format doesn't approve of unlabeled parameters
/**
  @Status Stub
  @Notes
 */
- (instancetype)initWithImageProvider:(id)p
                                 size:(size_t)width
                                     :(size_t)height
                               format:(CIFormat)f
                           colorSpace:(CGColorSpaceRef)cs
                              options:(NSDictionary*)dict {
    UNIMPLEMENTED();
    return StubReturn();
}
// clang-format on

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithTexture:(unsigned int)name size:(CGSize)size flipped:(BOOL)flag colorSpace:(CGColorSpaceRef)cs {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithMTLTexture:(id<MTLTexture>)texture options:(NSDictionary*)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (CGAffineTransform)imageTransformForOrientation:(int)orientation {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)autoAdjustmentFilters {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)autoAdjustmentFiltersWithOptions:(NSDictionary*)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (CGRect)regionOfInterestForImage:(CIImage*)im inRect:(CGRect)r {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

- (CGImageRef)_CGImageFromRect:(CGRect)rect {
    CIImage* croppedImage = [self imageByCroppingToRect:rect];
    return static_cast<CGImageRef>(croppedImage->_cgImage.get());
}
@end
