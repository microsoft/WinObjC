//******************************************************************************
//
// Copyright (c) 2016, Intel Corporation
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

#include "gtest-api.h"
#import <Foundation/Foundation.h>
#import <ImageIO/ImageIO.h>
#import <CoreGraphics/CGImage.h>
#include "Starboard.h"
#include <windows.h>

static void checkInt(int res, int expected, const char* name) {
    ASSERT_NEAR_MSG(res, expected, 0, "TEST FAILED: %s \nEXPECTED: %i\nFOUND: %i", name, expected, res);
}

static NSData* getDataFromImageFile(const wchar_t* imageFilename) {
    // get test startup full path
    wchar_t fullPath[_MAX_PATH];
    GetModuleFileNameW(NULL, fullPath, _MAX_PATH);

    // split test startup full path into components like drive, directory, filename and ext etc.
    wchar_t drive[_MAX_DRIVE];
    wchar_t directory[_MAX_DIR];
    ::_wsplitpath_s(fullPath, drive, _countof(drive), directory, _countof(directory), NULL, 0, NULL, 0);

    // reconstruct fullpath for test artifact file. e.g., C:\WinObjc\WinObjC\build\Debug\data\photo6_1024x670.jpg
    wcscpy_s(fullPath, _countof(fullPath), drive);
    wcscat_s(fullPath, _countof(fullPath), directory);
    wcscat_s(fullPath, _countof(fullPath), L"data\\");
    wcscat_s(fullPath, _countof(fullPath), imageFilename);
    NSString* testFileFullPath = [NSString stringWithCharacters:(const unichar*)fullPath length:_MAX_PATH];
    EbrFile *fp = EbrFopen([testFileFullPath UTF8String], "rb");
    if (!fp) {
        return nil;
    } 
    
    EbrFseek(fp, 0, SEEK_END);
    size_t length = EbrFtell(fp);
    char *byteData = (char *)IwMalloc(length);
    EbrFseek(fp, 0, SEEK_SET);
    size_t newLen = EbrFread(byteData, sizeof(char), length, fp);
    EbrFclose(fp);

    NSData* imgData = [NSData dataWithBytes:(const void *)byteData length:length];
    IwFree(byteData);
    return imgData;
}

TEST(ImageIO, ImageAtIndexWithData) {
    const wchar_t* imageFile = L"photo6_1024x670.jpg";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    NSDictionary* options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypeJPEG",
                              @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                              @"kCGImageSourceShouldCache":@"kCFBooleanTrue"};
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageRef != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRef), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRef), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRef), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRef), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRef)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRef), 670, "Height");
    checkInt(CGImageGetWidth(imageRef), 1024, "Width");
    size_t frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");
    CFRelease(imageSource);
}

TEST(ImageIO, ImageAtIndexWithDataProvider) {
    const wchar_t* imageFile = L"photo6_1024x670.jpg";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    NSDictionary* options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypeJPEG",
                              @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                              @"kCGImageSourceShouldCache":@"kCFBooleanTrue"};
    CGDataProviderRef imgDataProvider = CGDataProviderCreateWithCFData((CFDataRef)imageData);
    CGImageSourceRef imageSource = CGImageSourceCreateWithDataProvider(imgDataProvider, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithDataProvider returned nullptr");
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageRef != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRef), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRef), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRef), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRef), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRef)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRef), 670, "Height");
    checkInt(CGImageGetWidth(imageRef), 1024, "Width");
    size_t frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");
    CFRelease(imageSource);
}

TEST(ImageIO, ImageAtIndexWithUrl) {
    // get test startup full path
    wchar_t fullPath[_MAX_PATH];
    GetModuleFileNameW(NULL, fullPath, _MAX_PATH);

    // split test startup full path into components like drive, directory, filename and ext etc.
    wchar_t drive[_MAX_DRIVE];
    wchar_t directory[_MAX_DIR];
    ::_wsplitpath_s(fullPath, drive, _countof(drive), directory, _countof(directory), NULL, 0, NULL, 0);

    // reconstruct fullpath for test artifact file. e.g., C:\WinObjc\WinObjC\build\Debug\data\photo6_1024x670.jpg
    const wchar_t* imageFile = L"photo6_1024x670.jpg";
    wcscpy_s(fullPath, _countof(fullPath), drive);
    wcscat_s(fullPath, _countof(fullPath), directory);
    wcscat_s(fullPath, _countof(fullPath), L"data\\");
    wcscat_s(fullPath, _countof(fullPath), imageFile);
    NSString* directoryWithFile = [NSString stringWithCharacters:(const unichar*)fullPath length:_MAX_PATH];

    CFURLRef imgUrl = (CFURLRef)[NSURL fileURLWithPath:directoryWithFile]; 
    NSDictionary* options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypeJPEG",
                              @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                              @"kCGImageSourceShouldCache":@"kCFBooleanTrue"};
    CGImageSourceRef imageSource = CGImageSourceCreateWithURL(imgUrl, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithURL returned nullptr");
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageRef != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRef), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRef), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRef), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRef), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRef)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRef), 670, "Height");
    checkInt(CGImageGetWidth(imageRef), 1024, "Width");
    size_t frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");
    CFRelease(imageSource);
}

TEST(ImageIO, ImageTypeTest) {
    const wchar_t* imageFile = L"photo6_1024x670.jpg";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, nullptr);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CFStringRef imageType = CGImageSourceGetType(imageSource);
    ASSERT_TRUE_MSG(imageType != nil, "FAILED: ImageIOTest::CGImageSourceGetType returned nullptr");
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(imageType), @"public.jpeg", "FAILED: ImageIOTest::Incorrect Image Type");
    CFRelease(imageSource);
}

TEST(ImageIO, ThumbnailAtIndexFromSrcWithoutThumbnail) {
    const wchar_t* imageFile = L"photo6_1024x670.jpg";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    NSDictionary* options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypeJPEG",
                              @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                              @"kCGImageSourceShouldCache":@"kCFBooleanTrue",
                              @"kCGImageSourceCreateThumbnailFromImageIfAbsent":@"kCFBooleanTrue",
                              @"kCGImageSourceCreateThumbnailFromImageAlways":@"kCFBooleanTrue",
                              @"kCGImageSourceThumbnailMaxPixelSize":[NSNumber numberWithInt:1024],
                              @"kCGImageSourceCreateThumbnailWithTransform":@"kCFBooleanTrue"};
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CGImageRef imageRef = CGImageSourceCreateThumbnailAtIndex(imageSource, 0, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageRef != nil, "FAILED: ImageIOTest::CGImageSourceCreateThumbnailAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRef), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRef), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRef), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRef), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRef)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRef), 670, "Height");
    checkInt(CGImageGetWidth(imageRef), 1024, "Width");
    CFRelease(imageSource);
}

TEST(ImageIO, ThumbnailAtIndexFromAsymmetricSrcWithThumbnail) {
    const wchar_t* imageFile = L"photo6_1024x670_thumbnail_227x149.jpg";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    NSDictionary* options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypeJPEG",
                              @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                              @"kCGImageSourceShouldCache":@"kCFBooleanTrue",
                              @"kCGImageSourceCreateThumbnailFromImageIfAbsent":@"kCFBooleanTrue",
                              @"kCGImageSourceCreateThumbnailFromImageAlways":@"kCFBooleanTrue",
                              @"kCGImageSourceThumbnailMaxPixelSize":[NSNumber numberWithInt:1024],
                              @"kCGImageSourceCreateThumbnailWithTransform":@"kCFBooleanTrue"};
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CGImageRef imageRef = CGImageSourceCreateThumbnailAtIndex(imageSource, 0, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageRef != nil, "FAILED: ImageIOTest::CGImageSourceCreateThumbnailAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRef), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRef), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRef), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRef), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRef)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRef), 149, "Height");
    checkInt(CGImageGetWidth(imageRef), 227, "Width");
    CFRelease(imageSource);
}

TEST(ImageIO, ThumbnailSizesRelativeToImage) {
    const wchar_t* imageFile = L"photo6_1024x670_thumbnail_227x149.jpg";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    NSDictionary* options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypeJPEG",
                              @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                              @"kCGImageSourceShouldCache":@"kCFBooleanTrue",
                              @"kCGImageSourceCreateThumbnailFromImageIfAbsent":@"kCFBooleanTrue",
                              @"kCGImageSourceCreateThumbnailFromImageAlways":@"kCFBooleanTrue",
                              @"kCGImageSourceThumbnailMaxPixelSize":[NSNumber numberWithInt:10],
                              @"kCGImageSourceCreateThumbnailWithTransform":@"kCFBooleanTrue"};
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CGImageRef imageRef = CGImageSourceCreateThumbnailAtIndex(imageSource, 0, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageRef != nil, "FAILED: ImageIOTest::CGImageSourceCreateThumbnailAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRef), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRef), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRef), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRef), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRef)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRef), 10, "Height");
    checkInt(CGImageGetWidth(imageRef), 10, "Width");
    CFRelease(imageSource);

    options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypeJPEG",
                @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                @"kCGImageSourceShouldCache":@"kCFBooleanTrue",
                @"kCGImageSourceCreateThumbnailFromImageIfAbsent":@"kCFBooleanTrue",
                @"kCGImageSourceCreateThumbnailFromImageAlways":@"kCFBooleanTrue",
                @"kCGImageSourceThumbnailMaxPixelSize":[NSNumber numberWithInt:1000],
                @"kCGImageSourceCreateThumbnailWithTransform":@"kCFBooleanTrue"};
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    imageRef = CGImageSourceCreateThumbnailAtIndex(imageSource, 0, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageRef != nil, "FAILED: ImageIOTest::CGImageSourceCreateThumbnailAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRef), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRef), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRef), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRef), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRef)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRef), 149, "Height");
    checkInt(CGImageGetWidth(imageRef), 227, "Width");
    CFRelease(imageSource);
}

TEST(ImageIO, GIF_TIFF_MultiFrameSourceTest) {
    const wchar_t* imageFile = L"photo7_4layers_683x1024.gif";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    NSDictionary* options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypeGIF",
                              @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                              @"kCGImageSourceShouldCache":@"kCFBooleanTrue"};
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSource, 2, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageRef != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    CFStringRef imageType = CGImageSourceGetType(imageSource);
    ASSERT_TRUE_MSG(imageType != nil, "FAILED: ImageIOTest::CGImageSourceGetType returned nullptr");
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(imageType), @"com.compuserve.gif", "FAILED: ImageIOTest::Incorrect Image Type");
    size_t frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 4, "FrameCount");
    checkInt(CGImageGetAlphaInfo(imageRef), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRef), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRef), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRef), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRef)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRef), 1024, "Height");
    checkInt(CGImageGetWidth(imageRef), 683, "Width");
    
    imageFile = L"photo8_4layers_1024x683.tif";
    imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypeTIFF",
                @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                @"kCGImageSourceShouldCache":@"kCFBooleanTrue"};
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    imageRef = CGImageSourceCreateImageAtIndex(imageSource, 3, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageRef != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    imageType = CGImageSourceGetType(imageSource);
    ASSERT_TRUE_MSG(imageType != nil, "FAILED: ImageIOTest::CGImageSourceGetType returned nullptr");
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(imageType), @"public.tiff", "FAILED: ImageIOTest::Incorrect Image Type");
    frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 4, "FrameCount");
    checkInt(CGImageGetAlphaInfo(imageRef), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRef), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRef), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRef), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRef)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRef), 1024, "Height");
    checkInt(CGImageGetWidth(imageRef), 683, "Width");
    CFRelease(imageSource);
}

TEST(ImageIO, BMP_ICO_PNG_SingleFrameSourceTest) {
    const wchar_t* imageFile = L"testimg_227x149.bmp";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    NSDictionary* options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypeBMP",
                              @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                              @"kCGImageSourceShouldCache":@"kCFBooleanTrue"};
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageRef != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    CFStringRef imageType = CGImageSourceGetType(imageSource);
    ASSERT_TRUE_MSG(imageType != nil, "FAILED: ImageIOTest::CGImageSourceGetType returned nullptr");
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(imageType), @"com.microsoft.bmp", "FAILED: ImageIOTest::Incorrect Image Type");
    size_t frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");
    checkInt(CGImageGetAlphaInfo(imageRef), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRef), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRef), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRef), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRef)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRef), 149, "Height");
    checkInt(CGImageGetWidth(imageRef), 227, "Width");

    imageFile = L"photo2_683x1024.ico";
    imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypeICO",
                @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                @"kCGImageSourceShouldCache":@"kCFBooleanTrue"};
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageRef != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    imageType = CGImageSourceGetType(imageSource);
    ASSERT_TRUE_MSG(imageType != nil, "FAILED: ImageIOTest::CGImageSourceGetType returned nullptr");
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(imageType), @"com.microsoft.ico", "FAILED: ImageIOTest::Incorrect Image Type");
    frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");
    checkInt(CGImageGetAlphaInfo(imageRef), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRef), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRef), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRef), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRef)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRef), 1024, "Height");
    checkInt(CGImageGetWidth(imageRef), 683, "Width");

    imageFile = L"seafloor_256x256.png";
    imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypePNG",
                @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                @"kCGImageSourceShouldCache":@"kCFBooleanTrue"};
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageRef != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    imageType = CGImageSourceGetType(imageSource);
    ASSERT_TRUE_MSG(imageType != nil, "FAILED: ImageIOTest::CGImageSourceGetType returned nullptr");
    ASSERT_OBJCEQ_MSG(static_cast<NSString*>(imageType), @"public.png", "FAILED: ImageIOTest::Incorrect Image Type");
    frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");
    checkInt(CGImageGetAlphaInfo(imageRef), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRef), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRef), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRef), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRef)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRef), 256, "Height");
    checkInt(CGImageGetWidth(imageRef), 256, "Width");
    CFRelease(imageSource);
}

TEST(ImageIO, NegativeScenarioTest) {
    const wchar_t* imageFile = L"photo6_1024x670.jpg";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    NSDictionary* options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypeJPEG",
                              @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                              @"kCGImageSourceShouldCache":@"kCFBooleanTrue"};
    CGImageSourceRef imageSource = CGImageSourceCreateWithData(nullptr, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource == nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData should return nullptr");

    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, nullptr);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");

    imageSource = CGImageSourceCreateWithData(nullptr, nullptr);
    ASSERT_TRUE_MSG(imageSource == nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData should return nullptr");

    CGDataProviderRef imgDataProvider = CGDataProviderCreateWithCFData((CFDataRef)imageData);
    imageSource = CGImageSourceCreateWithDataProvider(nullptr, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource == nil, "FAILED: ImageIOTest::CGImageSourceCreateWithDataProvider should return nullptr");

    imageSource = CGImageSourceCreateWithDataProvider(imgDataProvider, nullptr);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithDataProvider returned nullptr");

    imageSource = CGImageSourceCreateWithDataProvider(nullptr, nullptr);
    ASSERT_TRUE_MSG(imageSource == nil, "FAILED: ImageIOTest::CGImageSourceCreateWithDataProvider should return nullptr");

    // get test startup full path
    wchar_t fullPath[_MAX_PATH];
    GetModuleFileNameW(NULL, fullPath, _MAX_PATH);

    // split test startup full path into components like drive, directory, filename and ext etc.
    wchar_t drive[_MAX_DRIVE];
    wchar_t directory[_MAX_DIR];
    ::_wsplitpath_s(fullPath, drive, _countof(drive), directory, _countof(directory), NULL, 0, NULL, 0);

    // reconstruct fullpath for test artifact file. e.g., C:\WinObjc\WinObjC\build\Debug\data\photo6_1024x670.jpg
    wcscpy_s(fullPath, _countof(fullPath), drive);
    wcscat_s(fullPath, _countof(fullPath), directory);
    wcscat_s(fullPath, _countof(fullPath), L"data\\");
    wcscat_s(fullPath, _countof(fullPath), imageFile);
    NSString* directoryWithFile = [NSString stringWithCharacters:(const unichar*)fullPath length:_MAX_PATH];

    CFURLRef imgUrl = (CFURLRef)[NSURL fileURLWithPath:directoryWithFile]; 
    imageSource = CGImageSourceCreateWithURL(nullptr, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource == nil, "FAILED: ImageIOTest::CGImageSourceCreateWithURL should return nullptr");

    imageSource = CGImageSourceCreateWithURL(nullptr, nullptr);
    ASSERT_TRUE_MSG(imageSource == nil, "FAILED: ImageIOTest::CGImageSourceCreateWithURL should return nullptr");

    imageSource = CGImageSourceCreateWithURL(imgUrl, nullptr);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithURL returned nullptr");
    
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSource, 5, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageRef == nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex should return nullptr");

    imageRef = CGImageSourceCreateImageAtIndex(imageSource, -1, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageRef == nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex should return nullptr");

    imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, nullptr);
    ASSERT_TRUE_MSG(imageRef != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");

    imageRef = CGImageSourceCreateImageAtIndex(nullptr, 0, nullptr);
    ASSERT_TRUE_MSG(imageRef == nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex should return nullptr");

    size_t frameCount = CGImageSourceGetCount(nullptr);
    checkInt(frameCount, 0, "FrameCount");
    options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypeJPEG",
                @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                @"kCGImageSourceShouldCache":@"kCFBooleanTrue",
                @"kCGImageSourceCreateThumbnailFromImageIfAbsent":@"kCFBooleanTrue",
                @"kCGImageSourceCreateThumbnailFromImageAlways":@"kCFBooleanTrue",
                @"kCGImageSourceThumbnailMaxPixelSize":[NSNumber numberWithInt:1024],
                @"kCGImageSourceCreateThumbnailWithTransform":@"kCFBooleanTrue"};
 
    imageRef = CGImageSourceCreateThumbnailAtIndex(imageSource, 5, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageRef == nil, "FAILED: ImageIOTest::CGImageSourceCreateThumbnailAtIndex should return nullptr");

    imageRef = CGImageSourceCreateThumbnailAtIndex(nullptr, 0, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageRef == nil, "FAILED: ImageIOTest::CGImageSourceCreateThumbnailAtIndex should return nullptr");

    imageRef = CGImageSourceCreateThumbnailAtIndex(imageSource, 0, nullptr);
    ASSERT_TRUE_MSG(imageRef == nil, "FAILED: ImageIOTest::CGImageSourceCreateThumbnailAtIndex should return nullptr");
    CFRelease(imageSource);
}

TEST(ImageIO, TypeIdentifierTest) {
    NSArray* expectedTypeIdentifiers = [NSArray arrayWithObjects:@"public.png", 
                                                                 @"public.jpeg", 
                                                                 @"com.compuserve.gif", 
                                                                 @"public.tiff", 
                                                                 @"com.microsoft.ico", 
                                                                 @"com.microsoft.bmp", 
                                                                 nil];
    NSArray* actualTypeIdentifiers = (NSArray*)CGImageSourceCopyTypeIdentifiers();
    ASSERT_TRUE_MSG([expectedTypeIdentifiers isEqualToArray:actualTypeIdentifiers], 
                    "FAILED: ImageIOTest::Incorrect TypeIdentifier list returned");
}