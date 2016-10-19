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
#import <Foundation\Foundation.h>
#import <Starboard/SmartTypes.h>
#import "TestUtils.h"

typedef struct {
    NSString* fileName;
    size_t height;
    size_t width;
    bool isMask;
} _ImageInfo;

static const int number_of_jpeg_files = 4;
static const _ImageInfo imagesJPEG[number_of_jpeg_files] = {
    { @"dog.jpg", 639, 960, false },
    { @"CroppedPhoto2.jpg", 200, 200, false },
    { @"bowl.jpg", 4000, 6000, false },
    { @"photo.jpg", 1024, 683, false },
};

static const int number_of_png_files = 2;
static const _ImageInfo imagesPNG[number_of_png_files] = {
    { @"dog.PNG", 700, 1044, false }, { @"microsoft.png", 136, 370, false },
};

#define EXPECT_IMAGE_DATA(image, imageInfo)               \
    EXPECT_TRUE(image != NULL);                           \
    EXPECT_EQ(imageInfo.isMask, CGImageIsMask(image));    \
    EXPECT_EQ(imageInfo.height, CGImageGetHeight(image)); \
    EXPECT_EQ(imageInfo.width, CGImageGetWidth(image));

static CGImageRef createJPEG(NSString* path) {
    CFDataRef data = (CFDataRef)[NSData dataWithContentsOfFile:getPathToFile(path)];
    CGDataProviderRef dataProvider = CGDataProviderCreateWithCFData(data);
    CGImageRef ret = CGImageCreateWithJPEGDataProvider(dataProvider, NULL, NO, kCGRenderingIntentDefault);
    CGDataProviderRelease(dataProvider);
    return ret;
}

static CGImageRef createPNG(NSString* path) {
    CFDataRef data = (CFDataRef)[NSData dataWithContentsOfFile:getPathToFile(path)];
    CGDataProviderRef dataProvider = CGDataProviderCreateWithCFData(data);
    CGImageRef ret = CGImageCreateWithPNGDataProvider(dataProvider, NULL, NO, kCGRenderingIntentDefault);
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

    CGRect rect = CGRectMake(0, 0, 50, 100);
    CGImageRef cropped = CGImageCreateWithImageInRect(image, rect);
    EXPECT_TRUE(cropped != NULL);

    EXPECT_EQ(false, CGImageIsMask(image));
    EXPECT_EQ(50, CGImageGetHeight(image));
    EXPECT_EQ(100, CGImageGetWidth(image));

    CGImageRelease(image);
    CGImageRelease(cropped);
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