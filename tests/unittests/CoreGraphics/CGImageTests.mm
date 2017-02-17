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

#import <TestFramework.h>
#import <Starboard.h>
#import <CoreGraphics/CGImage.h>
#import <Foundation/Foundation.h>
#import <Starboard/SmartTypes.h>
#import "TestUtils.h"

typedef struct {
    NSString* fileName;
    size_t height;
    size_t width;
    bool isMask;
    BYTE bitPerPixel;
    BYTE bitPerComponent;
} _ImageInfo;

static const _ImageInfo imagesJPEG[] = {
    /*{"filename",height,width,isMask,bit per pixel, bits per component} */
    { @"data/jpg1.jpg", 639, 960, false, 24, 8 },
    { @"data/jpg2.jpg", 995, 1039, false, 24, 8 },
    { @"data/jpg3.jpg", 4000, 6000, false, 24, 8 },
    { @"data/jpg4.jpg", 979, 1468, false, 24, 8 },
};

static const _ImageInfo imagesPNG[] = {
    /*{"filename",height,width,isMask,bit per pixel, bits per component} */
    { @"data/png1.png", 700, 1044, false, 32, 8 },
    { @"data/png2.png", 136, 370, false, 8, 8 },
    { @"data/png3.png", 795, 1197, false, 32, 8 },
};

#define EXPECT_IMAGE_DATA(image, imageInfo)                                                  \
    EXPECT_TRUE(image != NULL);                                                              \
    EXPECT_EQ(imageInfo.isMask, CGImageIsMask(image));                                       \
    EXPECT_EQ(imageInfo.height, CGImageGetHeight(image));                                    \
    EXPECT_EQ(imageInfo.width, CGImageGetWidth(image));                                      \
    EXPECT_EQ(imageInfo.bitPerPixel, CGImageGetBitsPerPixel(image));                         \
    EXPECT_EQ(imageInfo.bitPerComponent, CGImageGetBitsPerComponent(image));                 \
    EXPECT_EQ((imageInfo.bitPerPixel >> 3) * imageInfo.width, CGImageGetBytesPerRow(image)); \
    EXPECT_NE(nullptr, CGImageGetDataProvider(image));

static CGImageRef createJPEG(NSString* path) {
    CFDataRef data = (CFDataRef)[[NSData alloc] initWithContentsOfFile:getPathToFile(path)];
    CGDataProviderRef dataProvider = CGDataProviderCreateWithCFData(data);
    CGImageRef ret = CGImageCreateWithJPEGDataProvider(dataProvider, NULL, NO, kCGRenderingIntentDefault);
    CFRelease(data);
    CGDataProviderRelease(dataProvider);
    return ret;
}

static CGImageRef createPNG(NSString* path) {
    CFDataRef data = (CFDataRef)[[NSData alloc] initWithContentsOfFile:getPathToFile(path)];
    CGDataProviderRef dataProvider = CGDataProviderCreateWithCFData(data);
    CGImageRef ret = CGImageCreateWithPNGDataProvider(dataProvider, NULL, NO, kCGRenderingIntentDefault);
    CFRelease(data);
    CGDataProviderRelease(dataProvider);
    return ret;
}

TEST(CGImage, CreateWithJPEGGDataAndCreateWithCopy) {
    for (int i = 0; i < _countof(imagesJPEG); ++i) {
        CGImageRef image = createJPEG(imagesJPEG[i].fileName);

        EXPECT_IMAGE_DATA(image, imagesJPEG[i]);

        CGImageRef copy = CGImageCreateCopy(image);
        EXPECT_TRUE(copy != NULL);
        EXPECT_IMAGE_DATA(copy, imagesJPEG[i]);

        CGImageRelease(image);
        CGImageRelease(copy);
    }
}

TEST(CGImage, CreateWithPNGGDataAndCreateWithCopy) {
    for (int i = 0; i < _countof(imagesPNG); ++i) {
        CGImageRef image = createPNG(imagesPNG[i].fileName);
        EXPECT_IMAGE_DATA(image, imagesPNG[i]);

        CGImageRef copy = CGImageCreateCopy(image);
        EXPECT_TRUE(copy != NULL);
        EXPECT_IMAGE_DATA(copy, imagesPNG[i]);

        CGImageRelease(image);
        CGImageRelease(copy);
    }
}

TEST(CGImage, CreateWithImageInRect) {
    CGImageRef image = createPNG(imagesPNG[0].fileName);
    EXPECT_TRUE(image != NULL);
    EXPECT_EQ(imagesPNG[0].isMask, CGImageIsMask(image));
    EXPECT_EQ(imagesPNG[0].height, CGImageGetHeight(image));
    EXPECT_EQ(imagesPNG[0].width, CGImageGetWidth(image));

    CGRect rect = CGRectMake(0, 0, 100, 50);
    CGImageRef cropped = CGImageCreateWithImageInRect(image, rect);
    EXPECT_TRUE(cropped != NULL);

    EXPECT_EQ(false, CGImageIsMask(cropped));
    EXPECT_EQ(100, CGImageGetWidth(cropped));
    EXPECT_EQ(50, CGImageGetHeight(cropped));

    CGImageRelease(cropped);

    rect = CGRectMake(0, 0, 50, 100);
    cropped = CGImageCreateWithImageInRect(image, rect);
    EXPECT_TRUE(cropped != NULL);

    EXPECT_EQ(false, CGImageIsMask(cropped));
    EXPECT_EQ(50, CGImageGetWidth(cropped));
    EXPECT_EQ(100, CGImageGetHeight(cropped));

    CGImageRelease(cropped);
    CGImageRelease(image);
}

TEST(CGImage, CreateMask) {
    unsigned char data[1] = { 127 };

    CGDataProviderRef provider = CGDataProviderCreateWithData(NULL, data, 1, NULL);
    CGImageRef mask = CGImageMaskCreate(1, 1, 8, 8, 1, provider, NULL, YES);
    EXPECT_TRUE(mask != NULL);
    EXPECT_TRUE(CGImageIsMask(mask));
    EXPECT_EQ(1, CGImageGetHeight(mask));
    EXPECT_EQ(1, CGImageGetWidth(mask));
    EXPECT_TRUE(CGImageGetShouldInterpolate(mask));

    CGImageRelease(mask);
    CGDataProviderRelease(provider);

    //
    provider = CGDataProviderCreateWithData(NULL, data, 1, NULL);
    mask = CGImageMaskCreate(1, 1, 8, 32, 1, provider, NULL, YES);
    EXPECT_TRUE(mask == NULL);
    CGImageRelease(mask);
    CGDataProviderRelease(provider);

    //
    mask = CGImageMaskCreate(1, 1, 8, 8, 1, NULL, NULL, YES);
    EXPECT_TRUE(mask == NULL);
    CGImageRelease(mask);
}