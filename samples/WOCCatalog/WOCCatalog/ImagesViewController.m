//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import "ImagesViewController.h"
#import <CoreImage/CIImage.h>
#import <CoreImage/CIContext.h>
#import <CoreGraphics/CGImage.h>
#import <Accelerate/Accelerate.h>

@implementation ImagesViewController

+ (UIImage*)scaleImage:(CGImageRef)imageRef scaledRect:(CGRect)rect quality:(CGInterpolationQuality)quality {
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();

    CGContextSetInterpolationQuality(context, quality);
    CGAffineTransform flipVertical = CGAffineTransformMake(1, 0, 0, -1, 0, rect.size.height);
    CGContextConcatCTM(context, flipVertical);
    CGContextDrawImage(context, rect, imageRef);
    CGImageRef scaledImageRef = CGBitmapContextCreateImage(context);
    UIImage* scaledImage = [UIImage imageWithCGImage:scaledImageRef];
    CGImageRelease(scaledImageRef);

    UIGraphicsEndImageContext();

    return scaledImage;
}

+ (void)initCGImageFormat:(CGImageRef)imageRef formatInfo:(vImage_CGImageFormat*)formatInfo {
    formatInfo->bitmapInfo = CGImageGetBitmapInfo(imageRef);
    formatInfo->colorSpace = CGImageGetColorSpace(imageRef);
    formatInfo->bitsPerComponent = (uint32_t)CGImageGetBitsPerComponent(imageRef);

    const uint32_t numColorComponents = CGColorSpaceGetNumberOfComponents(formatInfo->colorSpace);
    const uint32_t numAlphaOrPaddingComponents = (kCGImageAlphaNone != CGImageGetAlphaInfo(imageRef)) ? 1 : 0;

    formatInfo->bitsPerPixel = formatInfo->bitsPerComponent * (numColorComponents + numAlphaOrPaddingComponents);
    formatInfo->decode = NULL;
    formatInfo->version = 0;
    formatInfo->renderingIntent = 0;

    const uint32_t byteOrder = formatInfo->bitmapInfo & kCGBitmapByteOrderMask;
    assert(formatInfo->bitsPerComponent == 8);
    assert(CGColorSpaceGetModel(formatInfo->colorSpace) == kCGColorSpaceModelRGB);
    assert(CGImageGetAlphaInfo(imageRef) == (formatInfo->bitmapInfo & kCGBitmapAlphaInfoMask));
    assert((numColorComponents == 3) && (numAlphaOrPaddingComponents == 1));
    assert((byteOrder != kCGBitmapByteOrder16Little) && (byteOrder != kCGBitmapByteOrder16Big));
}

+ (UIImage*)applyCMYStripes:(CGImageRef)imageRef {
    vImage_CGImageFormat format;
    [ImagesViewController initCGImageFormat:imageRef formatInfo:&format];

    const uint32_t alphaInfo = format.bitmapInfo & kCGBitmapAlphaInfoMask;
    const uint32_t byteOrder = format.bitmapInfo & kCGBitmapByteOrderMask;

    int indexR, indexG, indexB, indexA;

    // Use the byteorder and alpha info of the input image to get the byte index of each component
    // Note: vImage uses little endian notation for byte order as opposed to CoreGraphics which uses big endian or networkByte order notation
    if (byteOrder == kCGBitmapByteOrder32Big) {
        // XBGR_le or BGRX_le
        if (alphaInfo == kCGImageAlphaLast || alphaInfo == kCGImageAlphaNoneSkipLast) {
            indexA = 0; indexB = 1; indexG = 2; indexR = 3; 
        } else {
            indexB = 0; indexG = 1; indexR = 2; indexA = 3; 
        }
    }
    else {
        // RGBX_le or XRGB_le
        if (alphaInfo == kCGImageAlphaLast || alphaInfo == kCGImageAlphaNoneSkipLast) {
            indexR = 0; indexG = 1; indexB = 2; indexA = 3;
        } else {
            indexA = 0; indexR = 1; indexG = 2; indexB = 3;
        }
    }

    vImage_Error result;
    vImage_Buffer imageBuffer8888;
    result = vImageBuffer_InitWithCGImage(&imageBuffer8888, &format, nil, imageRef, 0);

    assert(result == kvImageNoError);

    // Create plane buffers
    vImage_Buffer planeBuffer[4];

    result = vImageBuffer_Init(&planeBuffer[0], imageBuffer8888.height, imageBuffer8888.width, format.bitsPerComponent, 0);
    assert(result == kvImageNoError);
    result = vImageBuffer_Init(&planeBuffer[1], planeBuffer[0].height, planeBuffer[0].width, format.bitsPerComponent, 0);
    assert(result == kvImageNoError);
    result = vImageBuffer_Init(&planeBuffer[2], planeBuffer[0].height, planeBuffer[0].width, format.bitsPerComponent, 0);
    assert(result == kvImageNoError);
    result = vImageBuffer_Init(&planeBuffer[3], planeBuffer[0].height, planeBuffer[0].width, format.bitsPerComponent, 0);
    assert(result == kvImageNoError);

    // Note: Although the function calls for ARGB input, a different input format can be used if the output planes are swizzled
    if (indexA == 0) {
        if (indexR == 1) {
            //XRGB or ARGB
            result = vImageConvert_ARGB8888toPlanar8(&imageBuffer8888, &planeBuffer[indexA], &planeBuffer[indexR], &planeBuffer[indexG], &planeBuffer[indexB], 0);
        } else {
            //XBGR or ABGR
            result = vImageConvert_ARGB8888toPlanar8(&imageBuffer8888, &planeBuffer[indexA], &planeBuffer[indexB], &planeBuffer[indexG], &planeBuffer[indexR], 0);
        }
    } else if (indexA == 3) {
        if (indexR == 0) {
            //RGBX or RGBA
            result = vImageConvert_ARGB8888toPlanar8(&imageBuffer8888, &planeBuffer[indexR], &planeBuffer[indexG], &planeBuffer[indexB], &planeBuffer[indexA], 0);
        } else {
            //BGRX or BGRA
            result = vImageConvert_ARGB8888toPlanar8(&imageBuffer8888, &planeBuffer[indexB], &planeBuffer[indexG], &planeBuffer[indexR], &planeBuffer[indexA], 0);
        }
    }

    assert(result == kvImageNoError);
    // Divide the image into three slices and remove components to produce strips with different colors
    const uint32_t height = imageBuffer8888.height;
    const uint32_t endOfFirstSlice = height / 3;
    const uint32_t endOfSecondSlice = endOfFirstSlice * 2;
    const uint32_t endOfThirdSlice = height;

    // Slice 0: Remove Red to produce Cyan output
    unsigned char* colorData;
    uint32_t rowPitch;

    rowPitch = planeBuffer[indexR].rowBytes;
    colorData = (unsigned char*)(planeBuffer[indexR].data);
    for (uint32_t i = 0; i < endOfFirstSlice; i++) {
        memset(colorData, 0, rowPitch);
        colorData += rowPitch;
    }

    // Slice 1: Remove Green to produce Magenta output
    rowPitch = planeBuffer[indexG].rowBytes;
    colorData = (unsigned char*)(planeBuffer[indexG].data) + endOfFirstSlice * rowPitch;
    for (uint32_t i = endOfFirstSlice; i < endOfSecondSlice; i++) {
        memset(colorData, 0, rowPitch);
        colorData += rowPitch;
    }

    // Slice 2: Remove Blue to produce Yellow output
    rowPitch = planeBuffer[indexB].rowBytes;
    colorData = (unsigned char*)(planeBuffer[indexB].data) + endOfSecondSlice * rowPitch;
    for (uint32_t i = endOfSecondSlice; i < endOfThirdSlice; i++) {
        memset(colorData, 0, rowPitch);
        colorData += rowPitch;
    }

    // All slices: Set alpha value to 128 (effectively 0.5f) to make image more saturated when unpremultiplied
    rowPitch = planeBuffer[indexA].rowBytes;
    colorData = (unsigned char*)(planeBuffer[indexA].data);
    for (uint32_t i = 0; i < height; i++) {
        memset(colorData, -128, rowPitch);
        colorData += rowPitch;
    }

    // Note: Although the function calls for ARGB input, a different input format can be used if the output planes are swizzled
    if (indexA == 0) {
        if (indexR == 1) {
            //XRGB or ARGB
            result = vImageConvert_Planar8toARGB8888(&planeBuffer[indexA], &planeBuffer[indexR], &planeBuffer[indexG], &planeBuffer[indexB], &imageBuffer8888, 0);
        } else {
            //XBGR or ABGR
            result = vImageConvert_Planar8toARGB8888(&planeBuffer[indexA], &planeBuffer[indexB], &planeBuffer[indexG], &planeBuffer[indexR], &imageBuffer8888, 0);
        }
    } else if (indexA == 3) {
        if (indexR == 0) {
            //RGBX or RGBA
            result = vImageConvert_Planar8toARGB8888(&planeBuffer[indexR], &planeBuffer[indexG], &planeBuffer[indexB], &planeBuffer[indexA], &imageBuffer8888, 0);
        } else {
            //BGRX or BGRA
            result = vImageConvert_Planar8toARGB8888(&planeBuffer[indexB], &planeBuffer[indexG], &planeBuffer[indexR], &planeBuffer[indexA], &imageBuffer8888, 0);
        }
    }

    vImage_Buffer imageBufferUnPremultiplied8888;
    result = vImageBuffer_Init(&imageBufferUnPremultiplied8888, imageBuffer8888.height, imageBuffer8888.width, 32, 0);
    assert(result == kvImageNoError);

    if (indexA == 3) {
        vImageUnpremultiplyData_RGBA8888(&imageBuffer8888, &imageBufferUnPremultiplied8888, 0);
    } else {
        vImageUnpremultiplyData_ARGB8888(&imageBuffer8888, &imageBufferUnPremultiplied8888, 0);
    }

    assert(result == kvImageNoError);
    CGImageRef cgImageFromBuffer = vImageCreateCGImageFromBuffer(&imageBufferUnPremultiplied8888, &format, nil, nil, 0, nil);
    UIImage* uiImageFromBuffer = [UIImage imageWithCGImage:cgImageFromBuffer];

    CGColorSpaceRelease(format.colorSpace);
    CGImageRelease(cgImageFromBuffer);

    free(imageBuffer8888.data);
    free(planeBuffer[0].data);
    free(planeBuffer[1].data);
    free(planeBuffer[2].data);
    free(planeBuffer[3].data);
    free(imageBufferUnPremultiplied8888.data);

    return uiImageFromBuffer;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor blackColor];
    CGRect rect = CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height);
    UIImageView* imagesView = [[UIImageView alloc] initWithFrame:rect];
    UIImage* photo = [UIImage imageNamed:@"photo9.jpg"];
    UIImage* scaledPhotoHighInterpolation = [ImagesViewController scaleImage:photo.CGImage scaledRect:rect quality:kCGInterpolationHigh];
    UIImage* scaledPhotoNoInterpolation = [ImagesViewController scaleImage:photo.CGImage scaledRect:rect quality:kCGInterpolationNone];

    CIContext* context = [CIContext contextWithOptions:nil];
    photo = [UIImage imageNamed:@"photo2.jpg"];
    CIImage* ciImage = [CIImage imageWithCGImage:photo.CGImage];
    CGImageRef cgImage = [context createCGImage:ciImage fromRect:CGRectMake(300, 600, 200, 200)];

    UIImage* cmyStripedAndBrightenedPhoto = [ImagesViewController applyCMYStripes:photo.CGImage];

    imagesView.animationImages = [NSArray arrayWithObjects:scaledPhotoHighInterpolation,
                                                           scaledPhotoNoInterpolation,
                                                           [UIImage imageNamed:@"photo1.jpg"],
                                                           [UIImage imageNamed:@"photo2.jpg"],
                                                           cmyStripedAndBrightenedPhoto,
                                                           [UIImage imageWithCGImage:cgImage],
                                                           [UIImage imageNamed:@"photo3.jpg"],
                                                           [UIImage imageNamed:@"photo4.jpg"],
                                                           [UIImage imageNamed:@"photo5.jpg"],
                                                           [UIImage imageNamed:@"photo6.jpg"],
                                                           [UIImage imageNamed:@"photo7.gif"],
                                                           [UIImage imageNamed:@"photo8.tif"],
                                                           nil];

    imagesView.animationDuration = 10.0;

    [imagesView setContentMode:UIViewContentModeScaleAspectFit];
    [imagesView startAnimating];
    imagesView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [[self view] addSubview:imagesView];
}

@end
