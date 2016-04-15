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

#include "gtest-api.h"
#import <Foundation/Foundation.h>
#import <ImageIO/ImageIO.h>
#import <CoreGraphics/CGImage.h>
#include "Starboard.h"
#include <windows.h>

const CFStringRef kUTTypeJPEG = static_cast<const CFStringRef>(@"public.jpeg");
const CFStringRef kUTTypeTIFF = static_cast<const CFStringRef>(@"public.tiff");
const CFStringRef kUTTypeGIF = static_cast<const CFStringRef>(@"com.compuserve.gif");
const CFStringRef kUTTypePNG = static_cast<const CFStringRef>(@"public.png");
const CFStringRef kUTTypeBMP = static_cast<const CFStringRef>(@"com.microsoft.bmp");
const CFStringRef kUTTypeICO = static_cast<const CFStringRef>(@"com.microsoft.ico");
const CFStringRef kUTTypeData = static_cast<const CFStringRef>(@"public.data");

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

static CFURLRef getURLRefFromFilename(const wchar_t* filename) {
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
    wcscat_s(fullPath, _countof(fullPath), filename);
    NSString* directoryWithFile = [NSString stringWithCharacters:(const unichar*)fullPath length:_MAX_PATH];
    return (CFURLRef)[NSURL fileURLWithPath:directoryWithFile];
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
    const wchar_t* imageFile = L"photo6_1024x670.jpg";
    CFURLRef imgUrl = getURLRefFromFilename(imageFile);

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

TEST(ImageIO, CopyJPEGPropertiesTest) {
    const wchar_t* imageFile = L"photo6_1024x670.jpg";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, nil);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CFDictionaryRef imageProperties = CGImageSourceCopyProperties(imageSource, nil);
    ASSERT_TRUE_MSG(imageProperties != nil, "FAILED: ImageIOTest::CGImageSourceCopyProperties returned nullptr");
    if (imageProperties && CFDictionaryContainsKey(imageProperties, kCGImagePropertyFileSize)) {
        int fileSize = [(id)CFDictionaryGetValue(imageProperties, kCGImagePropertyFileSize) intValue];
        checkInt(fileSize, 218940, "FileSize");
    }

    CFRelease(imageSource);
}

TEST(ImageIO, CopyGIFPropertiesTest) {
    const wchar_t* imageFile = L"photo7_4layers_683x1024.gif";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, nil);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CFDictionaryRef imageProperties = CGImageSourceCopyProperties(imageSource, nil);
    ASSERT_TRUE_MSG(imageProperties != nil, "FAILED: ImageIOTest::CGImageSourceCopyProperties returned nullptr");
    if (imageProperties && CFDictionaryContainsKey(imageProperties, kCGImagePropertyFileSize)) {
        int fileSize = [(id)CFDictionaryGetValue(imageProperties, kCGImagePropertyFileSize) intValue];
        checkInt(fileSize, 669893, "FileSize");
    }

    CFRelease(imageSource);
}

TEST(ImageIO, CopyTIFFPropertiesTest) {
    const wchar_t* imageFile = L"photo8_4layers_1024x683.tif";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, nil);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CFDictionaryRef imageProperties = CGImageSourceCopyProperties(imageSource, nil);
    ASSERT_TRUE_MSG(imageProperties != nil, "FAILED: ImageIOTest::CGImageSourceCopyProperties returned nullptr");
    if (imageProperties && CFDictionaryContainsKey(imageProperties, kCGImagePropertyFileSize)) {
        int fileSize = [(id)CFDictionaryGetValue(imageProperties, kCGImagePropertyFileSize) intValue];
        checkInt(fileSize, 4187742, "FileSize");
    }

    CFRelease(imageSource);
}

TEST(ImageIO, CopyPNGPropertiesTest) {
    const wchar_t* imageFile = L"seafloor_256x256.png";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, nil);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CFDictionaryRef imageProperties = CGImageSourceCopyProperties(imageSource, nil);
    ASSERT_TRUE_MSG(imageProperties != nil, "FAILED: ImageIOTest::CGImageSourceCopyProperties returned nullptr");
    if (imageProperties && CFDictionaryContainsKey(imageProperties, kCGImagePropertyFileSize)) {
        int fileSize = [(id)CFDictionaryGetValue(imageProperties, kCGImagePropertyFileSize) intValue];
        checkInt(fileSize, 59506, "FileSize");
    }

    CFRelease(imageSource);
}

TEST(ImageIO, CopyBMPPropertiesTest) {
    const wchar_t* imageFile = L"testimg_227x149.bmp";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, nil);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CFDictionaryRef imageProperties = CGImageSourceCopyProperties(imageSource, nil);
    ASSERT_TRUE_MSG(imageProperties != nil, "FAILED: ImageIOTest::CGImageSourceCopyProperties returned nullptr");
    if (imageProperties && CFDictionaryContainsKey(imageProperties, kCGImagePropertyFileSize)) {
        int fileSize = [(id)CFDictionaryGetValue(imageProperties, kCGImagePropertyFileSize) intValue];
        checkInt(fileSize, 35050, "FileSize");
    }

    CFRelease(imageSource);
}

TEST(ImageIO, CopyICOPropertiesTest) {
    const wchar_t* imageFile = L"photo2_683x1024.ico";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, nil);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CFDictionaryRef imageProperties = CGImageSourceCopyProperties(imageSource, nil);
    ASSERT_TRUE_MSG(imageProperties != nil, "FAILED: ImageIOTest::CGImageSourceCopyProperties returned nullptr");
    if (imageProperties && CFDictionaryContainsKey(imageProperties, kCGImagePropertyFileSize)) {
        int fileSize = [(id)CFDictionaryGetValue(imageProperties, kCGImagePropertyFileSize) intValue];
        checkInt(fileSize, 1041876, "FileSize");
    }

    CFRelease(imageSource);
}

TEST(ImageIO, CopyJPEGPropertiesAtIndexTest) {
    const wchar_t* imageFile = L"photo6_1024x670.jpg";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    NSDictionary* options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypeJPEG",
                              @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                              @"kCGImageSourceShouldCache":@"kCFBooleanTrue"};
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CFDictionaryRef imageProperties = CGImageSourceCopyPropertiesAtIndex(imageSource, 0, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageProperties != nil, "FAILED: ImageIOTest::CGImageSourceCopyPropertiesAtIndex returned nullptr");

    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyJFIFDictionary),
        "FAILED: ImageIOTest::JFIF dictionary not found");
    CFDictionaryRef jfifDictionary = (CFDictionaryRef)CFDictionaryGetValue(imageProperties, kCGImagePropertyJFIFDictionary);
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(jfifDictionary, kCGImagePropertyJFIFXDensity),
        "FAILED: ImageIOTest::JFIF dictionary does not contain XDensity");
    double actualXDensity = [(id)CFDictionaryGetValue(jfifDictionary, kCGImagePropertyJFIFXDensity) doubleValue];
    ASSERT_NEAR_MSG(actualXDensity, 72.0, 0.01, "FAILED: ImageIOTest::XDensity mismatch");

    CFRelease(imageSource);
}

TEST(ImageIO, CopyGIFPropertiesAtIndexTest) {
    const wchar_t* imageFile = L"photo7_4layers_683x1024.gif";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    NSDictionary* options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypeGIF",
                              @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                              @"kCGImageSourceShouldCache":@"kCFBooleanTrue"};
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CFDictionaryRef imageProperties = CGImageSourceCopyPropertiesAtIndex(imageSource, 0, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageProperties != nil, "FAILED: ImageIOTest::CGImageSourceCopyPropertiesAtIndex returned nullptr");
    
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyPixelHeight),
        "FAILED: ImageIOTest::GIF PixelHeight Property not found");
    int actualHeight = [(id)CFDictionaryGetValue(imageProperties, kCGImagePropertyPixelHeight) intValue];
    checkInt(actualHeight, 1024, "PixelHeight");
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyGIFDictionary),
        "FAILED: ImageIOTest::GIF Dictionary not found");
    CFDictionaryRef gifDictionary = (CFDictionaryRef)CFDictionaryGetValue(imageProperties, kCGImagePropertyGIFDictionary);
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(gifDictionary, kCGImagePropertyGIFDelayTime),
        "FAILED: ImageIOTest::GIF dictionary does not contain Delay Time");
    double actualDelayTime = [(id)CFDictionaryGetValue(gifDictionary, kCGImagePropertyGIFDelayTime) doubleValue];
    ASSERT_NEAR_MSG(actualDelayTime, 0.1, 0.01, "FAILED: ImageIOTest::Delay Time mismatch");

    CFRelease(imageSource);
}

TEST(ImageIO, CopyTIFFPropertiesAtIndexTest) {
    const wchar_t* imageFile = L"photo8_4layers_1024x683.tif";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    NSDictionary* options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypeTIFF",
                              @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                              @"kCGImageSourceShouldCache":@"kCFBooleanTrue"};
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CFDictionaryRef imageProperties = CGImageSourceCopyPropertiesAtIndex(imageSource, 0, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageProperties != nil, "FAILED: ImageIOTest::CGImageSourceCopyPropertiesAtIndex returned nullptr");
    
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyTIFFDictionary),
        "FAILED: ImageIOTest::TIFF dictionary not found");
    CFDictionaryRef tiffDictionary = (CFDictionaryRef)CFDictionaryGetValue(imageProperties, kCGImagePropertyTIFFDictionary);
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(tiffDictionary, kCGImagePropertyTIFFResolutionUnit),
        "FAILED: ImageIOTest::TIFF dictionary does not contain Resolution Unit");
    int actualResolutionUnit = [(id)CFDictionaryGetValue(tiffDictionary, kCGImagePropertyTIFFResolutionUnit) intValue];
    checkInt(actualResolutionUnit, 2, "ResolutionUnit");

    CFRelease(imageSource);
}

TEST(ImageIO, CopyPNGPropertiesAtIndexTest) {
    const wchar_t* imageFile = L"seafloor_256x256.png";
    NSData* imageData = getDataFromImageFile(imageFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", imageFile);
    NSDictionary* options = @{@"kCGImageSourceTypeIdentifierHint":@"kUTTypePNG",
                              @"kCGImageSourceShouldAllowFloat":@"kCFBooleanTrue",
                              @"kCGImageSourceShouldCache":@"kCFBooleanTrue"};
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CFDictionaryRef imageProperties = CGImageSourceCopyPropertiesAtIndex(imageSource, 0, (CFDictionaryRef)options);
    ASSERT_TRUE_MSG(imageProperties != nil, "FAILED: ImageIOTest::CGImageSourceCopyPropertiesAtIndex returned nullptr");
    
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyPNGDictionary),
        "FAILED: ImageIOTest::PNG dictionary not found");
    CFDictionaryRef pngDictionary = (CFDictionaryRef)CFDictionaryGetValue(imageProperties, kCGImagePropertyPNGDictionary);
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(pngDictionary, kCGImagePropertyPNGGamma),
        "FAILED: ImageIOTest::PNG dictionary does not contain Gamma");
    int actualGamma = [(id)CFDictionaryGetValue(pngDictionary, kCGImagePropertyPNGGamma) intValue];
    checkInt(actualGamma, 45455, "PNG Gamma");

    CFRelease(imageSource);
}

TEST(ImageIO, DestinationTest) {
    const wchar_t* imageFile = L"photo6_1024x670.jpg";
    NSData* imageData = getDataFromImageFile(imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    CFRelease(imageSource);
    
    const wchar_t* outFile = L"outphoto.tif";
    CFURLRef imgUrl = getURLRefFromFilename(outFile);

    // Here we do not release myImageDest right after use to check that images can be read immediately after Finalize
    CGImageDestinationRef myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypeTIFF, 1, NULL);
    CGImageDestinationAddImage(myImageDest, imageRef, NULL);
    CGImageDestinationFinalize(myImageDest);

    // Read back in the newly written image to check properties
    imageData = getDataFromImageFile(outFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CGImageRef imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 670, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 1024, "Width");
    size_t frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");
    CFRelease(imageSource);

    const wchar_t* outFile2 = L"outphoto.jpg";
    imgUrl = getURLRefFromFilename(outFile2);

    CFRelease(myImageDest);
    myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypeJPEG, 1, NULL);
    CGImageDestinationAddImage(myImageDest, imageRef, NULL);
    CGImageDestinationFinalize(myImageDest);

    // Read back in the newly written image to check properties
    imageData = getDataFromImageFile(outFile2);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile2);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 670, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 1024, "Width");
    frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");
    CFRelease(imageSource);

    const wchar_t* outFile3 = L"outphoto.png";
    imgUrl = getURLRefFromFilename(outFile3);

    CFRelease(myImageDest);
    myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypePNG, 1, NULL);
    CGImageDestinationAddImage(myImageDest, imageRef, NULL);
    CGImageDestinationFinalize(myImageDest);

    // Read back in the newly written image to check properties
    imageData = getDataFromImageFile(outFile3);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile3);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 670, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 1024, "Width");
    frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");
    CFRelease(imageSource);

    const wchar_t* outFile4 = L"outphoto.bmp";
    imgUrl = getURLRefFromFilename(outFile4);

    CFRelease(myImageDest);
    myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypeBMP, 1, NULL);
    CGImageDestinationAddImage(myImageDest, imageRef, NULL);
    CGImageDestinationFinalize(myImageDest);
    
    // Read back in the newly written image to check properties
    imageData = getDataFromImageFile(outFile4);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile4);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 670, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 1024, "Width");
    frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");
    CFRelease(imageSource);

    const wchar_t* outFile5 = L"outphoto.gif";
    imgUrl = getURLRefFromFilename(outFile5);

    CFRelease(myImageDest);
    myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypeGIF, 1, NULL);
    CGImageDestinationAddImage(myImageDest, imageRef, NULL);
    CGImageDestinationFinalize(myImageDest);
    
    // Read back in the newly written image to check properties
    imageData = getDataFromImageFile(outFile5);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile5);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 670, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 1024, "Width");
    frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");
    CFRelease(imageSource);
    CFRelease(myImageDest);
}

TEST(ImageIO, DestinationFromSourceTest) {
    const wchar_t* imageFile = L"testimg_227x149.bmp";
    NSData* imageData = getDataFromImageFile(imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    
    const wchar_t* outFile = L"outphoto2.tif";
    CFURLRef imgUrl = getURLRefFromFilename(outFile);

    CGImageDestinationRef myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypeTIFF, 1, NULL);
    CGImageDestinationAddImageFromSource(myImageDest, imageSource, 0, NULL);
    CGImageDestinationFinalize(myImageDest);
    CFRelease(myImageDest);

    // Read back in the newly written image to check properties
    CFRelease(imageSource);
    imageData = getDataFromImageFile(outFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CGImageRef imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 149, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 227, "Width");
    size_t frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");

    const wchar_t* outFile2 = L"outphoto2.jpg";
    imgUrl = getURLRefFromFilename(outFile2);

    myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypeJPEG, 1, NULL);
    CGImageDestinationAddImageFromSource(myImageDest, imageSource, 0, NULL);
    CGImageDestinationFinalize(myImageDest);
    CFRelease(imageSource);
    CFRelease(myImageDest);

    // Read back in the newly written image to check properties
    imageData = getDataFromImageFile(outFile2);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile2);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 149, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 227, "Width");
    frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");

    const wchar_t* outFile3 = L"outphoto2.png";
    imgUrl = getURLRefFromFilename(outFile3);

    myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypePNG, 1, NULL);
    CGImageDestinationAddImageFromSource(myImageDest, imageSource, 0, NULL);
    CGImageDestinationFinalize(myImageDest);
    CFRelease(imageSource);
    CFRelease(myImageDest);

    // Read back in the newly written image to check properties
    imageData = getDataFromImageFile(outFile3);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile3);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 149, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 227, "Width");
    frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");

    const wchar_t* outFile4 = L"outphoto2.bmp";
    imgUrl = getURLRefFromFilename(outFile4);

    myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypeBMP, 1, NULL);
    CGImageDestinationAddImageFromSource(myImageDest, imageSource, 0, NULL);
    CGImageDestinationFinalize(myImageDest);
    CFRelease(imageSource);
    CFRelease(myImageDest);

    // Read back in the newly written image to check properties
    imageData = getDataFromImageFile(outFile4);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile4);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 149, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 227, "Width");
    frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");
    CFRelease(imageSource);
}

TEST(ImageIO, DestinationMultiFrameTest) {
    const wchar_t* imageFile = L"photo2_683x1024.ico";
    NSData* imageData = getDataFromImageFile(imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);

    const wchar_t* imageFile2 = L"photo8_4layers_1024x683.tif";
    NSData* imageData2 = getDataFromImageFile(imageFile2);
    CGImageSourceRef imageSource2 = CGImageSourceCreateWithData((CFDataRef)imageData2, NULL);
    CGImageRef imageRef2 = CGImageSourceCreateImageAtIndex(imageSource2, 0, NULL);
    
    const wchar_t* outFile = L"outphoto_multiframe.tif";
    CFURLRef imgUrl = getURLRefFromFilename(outFile);

    CGImageDestinationRef myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypeTIFF, 3, NULL);
    CGImageDestinationAddImage(myImageDest, imageRef, NULL);
    CGImageDestinationAddImageFromSource(myImageDest, imageSource2, 0, NULL);
    CGImageDestinationAddImageFromSource(myImageDest, imageSource2, 2, NULL);
    CGImageDestinationFinalize(myImageDest);
    CFRelease(imageSource);
    CFRelease(imageSource2);
    CFRelease(myImageDest);

    // Read back in the newly written image to check properties
    imageData = getDataFromImageFile(outFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    size_t frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 3, "FrameCount");

    CGImageRef imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 1024, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 683, "Width");

    imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 1, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 683, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 1024, "Width");

    imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 2, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 683, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 1024, "Width");

    CFRelease(imageSource);
}

TEST(ImageIO, DestinationMultiFrameGifTest) {
    const wchar_t* imageFile = L"photo2_683x1024.ico";
    NSData* imageData = getDataFromImageFile(imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);

    const wchar_t* imageFile2 = L"photo8_4layers_1024x683.tif";
    NSData* imageData2 = getDataFromImageFile(imageFile2);
    CGImageSourceRef imageSource2 = CGImageSourceCreateWithData((CFDataRef)imageData2, NULL);
    CGImageRef imageRef2 = CGImageSourceCreateImageAtIndex(imageSource2, 0, NULL);
    
    const wchar_t* outFile = L"outphoto_multiframe.gif";
    CFURLRef imgUrl = getURLRefFromFilename(outFile);

    CGImageDestinationRef myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypeGIF, 3, NULL);
    CGImageDestinationAddImage(myImageDest, imageRef, NULL);
    CGImageDestinationAddImageFromSource(myImageDest, imageSource2, 0, NULL);
    CGImageDestinationAddImageFromSource(myImageDest, imageSource2, 2, NULL);
    CGImageDestinationFinalize(myImageDest);
    CFRelease(imageSource);
    CFRelease(imageSource2);
    CFRelease(myImageDest);

    // Read back in the newly written image to check properties
    imageData = getDataFromImageFile(outFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    size_t frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 3, "FrameCount");

    CGImageRef imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 1024, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 683, "Width");

    imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 1, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 683, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 1024, "Width");

    imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 2, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 683, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 1024, "Width");

    CFRelease(imageSource);
}

TEST(ImageIO, DestinationDataTest) {
    const wchar_t* imageFile = L"photo2_683x1024.ico";
    NSData* imageData = getDataFromImageFile(imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    CFRelease(imageSource);

    // Create buffer to hold destination image in
    NSMutableData* dataBuffer = [NSMutableData dataWithCapacity:10000000];

    CGImageDestinationRef myImageDest = CGImageDestinationCreateWithData((CFMutableDataRef)dataBuffer, kUTTypeTIFF, 1, NULL);
    CGImageDestinationAddImage(myImageDest, imageRef, NULL);
    CGImageDestinationFinalize(myImageDest);
    CFRelease(myImageDest);

    imageSource = CGImageSourceCreateWithData((CFDataRef)dataBuffer, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    size_t frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");
    CGImageRef imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRef)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 1024, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 683, "Width");
    CFRelease(imageSource);
}

TEST(ImageIO, DestinationMultiFrameDataTest) {
    const wchar_t* imageFile = L"photo2_683x1024.ico";
    NSData* imageData = getDataFromImageFile(imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);

    const wchar_t* imageFile2 = L"photo8_4layers_1024x683.tif";
    NSData* imageData2 = getDataFromImageFile(imageFile2);
    CGImageSourceRef imageSource2 = CGImageSourceCreateWithData((CFDataRef)imageData2, NULL);
    CGImageRef imageRef2 = CGImageSourceCreateImageAtIndex(imageSource2, 0, NULL);
    
    NSMutableData* dataBuffer = [NSMutableData dataWithCapacity:10000000];

    CGImageDestinationRef myImageDest = CGImageDestinationCreateWithData((CFMutableDataRef)dataBuffer, kUTTypeTIFF, 3, NULL);
    CGImageDestinationAddImage(myImageDest, imageRef, NULL);
    CGImageDestinationAddImageFromSource(myImageDest, imageSource2, 0, NULL);
    CGImageDestinationAddImageFromSource(myImageDest, imageSource2, 2, NULL);
    CGImageDestinationFinalize(myImageDest);
    CFRelease(imageSource);
    CFRelease(imageSource2);
    CFRelease(myImageDest);

    // Read back in the newly written image to check properties
    imageSource = CGImageSourceCreateWithData((CFDataRef)dataBuffer, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    size_t frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 3, "FrameCount");

    CGImageRef imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 1024, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 683, "Width");

    imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 1, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 683, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 1024, "Width");

    imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 2, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 683, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 1024, "Width");

    CFRelease(imageSource);
}

TEST(ImageIO, DestinationOptionsTest) {
    const wchar_t* imageFile = L"photo6_1024x670.jpg";
    NSData* imageData = getDataFromImageFile(imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    CFRelease(imageSource);

    const wchar_t* outFile = L"outphotoLQ.jpg";
    CFURLRef imgUrl = getURLRefFromFilename(outFile);

    // Note that to verify quality is much lower with quality = 0.0, you have to open the image file.
    // There is no option for image quality stored with the file as that would not make sense.
    float quality = 0.0;
    NSNumber* encodeQuality = [NSNumber numberWithFloat:quality];
    NSDictionary* encodeOptions = @{@"kCGImageDestinationLossyCompressionQuality":encodeQuality};

    CGImageDestinationRef myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypeJPEG, 1, NULL);
    CGImageDestinationAddImage(myImageDest, imageRef, (CFDictionaryRef)encodeOptions);
    CGImageDestinationFinalize(myImageDest);
    CFRelease(myImageDest);

    // Read back in the newly written image to check properties
    imageData = getDataFromImageFile(outFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CGImageRef imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 670, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 1024, "Width");
    size_t frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 1, "FrameCount");
    CFRelease(imageSource);

    imageFile = L"photo2_683x1024.ico";
    imageData = getDataFromImageFile(imageFile);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);

    const wchar_t* imageFile2 = L"photo8_4layers_1024x683.tif";
    NSData* imageData2 = getDataFromImageFile(imageFile2);
    CGImageSourceRef imageSource2 = CGImageSourceCreateWithData((CFDataRef)imageData2, NULL);
    CGImageRef imageRef2 = CGImageSourceCreateImageAtIndex(imageSource2, 0, NULL);
    
    const wchar_t* outFile2 = L"outphoto_loopcount.gif";
    imgUrl = getURLRefFromFilename(outFile2);

    int loopCount = 15;
    float delayTime = 0.5;
    NSDictionary *gifEncodeOptions = @{
        (id)kCGImagePropertyGIFLoopCount:[NSNumber numberWithInt:loopCount],
        (id)kCGImagePropertyGIFDelayTime:[NSNumber numberWithFloat:delayTime],
    };

    NSDictionary *encodeDictionary = @{
        (id)kCGImagePropertyGIFDictionary:gifEncodeOptions,
    };

    myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypeGIF, 3, NULL);
    CGImageDestinationSetProperties(myImageDest, (CFDictionaryRef)encodeDictionary);
    CGImageDestinationAddImage(myImageDest, imageRef, (CFDictionaryRef)encodeDictionary);
    CGImageDestinationAddImageFromSource(myImageDest, imageSource2, 0, (CFDictionaryRef)encodeDictionary);
    CGImageDestinationAddImageFromSource(myImageDest, imageSource2, 2, (CFDictionaryRef)encodeDictionary);
    CGImageDestinationFinalize(myImageDest);
    CFRelease(imageSource);
    CFRelease(imageSource2);
    CFRelease(myImageDest);

    // Read back in the newly written image to check properties
    imageData = getDataFromImageFile(outFile2);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile2);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    frameCount = CGImageSourceGetCount(imageSource);
    checkInt(frameCount, 3, "FrameCount");

    CFDictionaryRef imageProperties = CGImageSourceCopyProperties(imageSource, NULL);
    ASSERT_TRUE_MSG(imageProperties != nil, "FAILED: ImageIOTest::CGImageSourceCopyProperties returned nullptr");

    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyGIFDictionary),
        "FAILED: ImageIOTest::GIF dictionary not found");
    CFDictionaryRef gifDictionary = (CFDictionaryRef)CFDictionaryGetValue(imageProperties, kCGImagePropertyGIFDictionary);
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(gifDictionary, kCGImagePropertyGIFLoopCount),
        "FAILED: ImageIOTest::GIF dictionary does not contain Loop Count");
    int actualLoopCount = [(id)CFDictionaryGetValue(gifDictionary, kCGImagePropertyGIFLoopCount) intValue];
    checkInt(actualLoopCount, loopCount, "Loop Count");

    imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 1024, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 683, "Width");

    imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 1, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 683, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 1024, "Width");

    imageRefOut = CGImageSourceCreateImageAtIndex(imageSource, 2, NULL);
    ASSERT_TRUE_MSG(imageRefOut != nil, "FAILED: ImageIOTest::CGImageSourceCreateImageAtIndex returned nullptr");
    checkInt(CGImageGetAlphaInfo(imageRefOut), 4, "AlphaInfo");
    checkInt(CGImageGetBitmapInfo(imageRefOut), 4, "BitmapInfo");
    checkInt(CGImageGetBitsPerComponent(imageRefOut), 8, "BitsPerComponent");
    checkInt(CGImageGetBitsPerPixel(imageRefOut), 32, "BitsPerPixel");
    checkInt(CGColorSpaceGetNumberOfComponents(CGImageGetColorSpace(imageRefOut)), 3, "ColorSpaceComponentCount");
    checkInt(CGImageGetHeight(imageRefOut), 683, "Height");
    checkInt(CGImageGetWidth(imageRefOut), 1024, "Width");

    CFRelease(imageSource);
}

TEST(ImageIO, DestinationImageOptionsTIFFTest) {
    const wchar_t* imageFile = L"photo2_683x1024.ico";
    NSData* imageData = getDataFromImageFile(imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    CFRelease(imageSource);

    const wchar_t* outFile = L"outphoto_options.tif";
    CFURLRef imgUrl = getURLRefFromFilename(outFile);

    NSDictionary *gpsOptions = @{
        (id)kCGImagePropertyGPSLatitude:[NSNumber numberWithDouble:100.55],
        (id)kCGImagePropertyGPSLongitude:[NSNumber numberWithDouble:200.0],
        (id)kCGImagePropertyGPSLatitudeRef:@"N",
        (id)kCGImagePropertyGPSLongitudeRef:@"W",
        (id)kCGImagePropertyGPSAltitude:[NSNumber numberWithDouble:150.25],
        (id)kCGImagePropertyGPSAltitudeRef:[NSNumber numberWithShort:1],
        (id)kCGImagePropertyGPSImgDirection:[NSNumber numberWithFloat:2.4],
        (id)kCGImagePropertyGPSImgDirectionRef:@"test",
        (id)kCGImagePropertyGPSTimeStamp:@"04:30:51.71",
        (id)kCGImagePropertyGPSVersion:@"2.2.0.0",
    };

    NSDictionary *exifOptions = @{
        (id)kCGImagePropertyExifUserComment:@"Test2",
        (id)kCGImagePropertyExifExposureTime:[NSNumber numberWithDouble:12.34],
    };

    NSDictionary *tiffOptions = @{
        (id)kCGImagePropertyTIFFXResolution:[NSNumber numberWithDouble:100],
        (id)kCGImagePropertyTIFFYResolution:[NSNumber numberWithDouble:120],
        (id)kCGImagePropertyTIFFResolutionUnit:[NSNumber numberWithInt:1],
    };

    int orientation = 3;
    NSNumber* encodeOrientation = [NSNumber numberWithInt:orientation];

    NSDictionary *encodeOptions = @{
        (id)kCGImagePropertyGPSDictionary:gpsOptions,
        (id)kCGImagePropertyOrientation:encodeOrientation,
        (id)kCGImagePropertyExifDictionary:exifOptions,
        (id)kCGImagePropertyTIFFDictionary:tiffOptions,
        (id)kCGImagePropertyDPIWidth:[NSNumber numberWithDouble:1000],
        (id)kCGImagePropertyDPIHeight:[NSNumber numberWithDouble:200],
    };

    CGImageDestinationRef myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypeTIFF, 1, NULL);
    CGImageDestinationAddImage(myImageDest, imageRef, (CFDictionaryRef)encodeOptions);
    CGImageDestinationFinalize(myImageDest);
    CFRelease(myImageDest);

    imageData = getDataFromImageFile(outFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CFDictionaryRef imageProperties = CGImageSourceCopyPropertiesAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageProperties != nil, "FAILED: ImageIOTest::CGImageSourceCopyPropertiesAtIndex returned nullptr");
    
    // Print the properties due to high number of properties written, only checking a few properties
    NSLog(@"TIFF Dictionary - [%@]", (NSDictionary*)imageProperties);

    // Note that this XResolution was actually passed in as 100. This field aliases with DPIWidth.
    // As observed on iOS, for TIFF, DPIWidth takes precedence, while for JPEG, XResolution takes precedence.
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyTIFFDictionary),
        "FAILED: ImageIOTest::TIFF dictionary not found");
    CFDictionaryRef tiffDictionary = (CFDictionaryRef)CFDictionaryGetValue(imageProperties, kCGImagePropertyTIFFDictionary);
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(tiffDictionary, kCGImagePropertyTIFFXResolution),
        "FAILED: ImageIOTest::TIFF dictionary does not contain XResolution");
    double actualXDensity = [(id)CFDictionaryGetValue(tiffDictionary, kCGImagePropertyTIFFXResolution) doubleValue];
    ASSERT_NEAR_MSG(actualXDensity, 1000.0, 0.01, "FAILED: ImageIOTest::XResolution mismatch");

    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyExifDictionary),
        "FAILED: ImageIOTest::Exif dictionary not found");
    CFDictionaryRef exifDictionary = (CFDictionaryRef)CFDictionaryGetValue(imageProperties, kCGImagePropertyExifDictionary);
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(exifDictionary, kCGImagePropertyExifExposureTime),
        "FAILED: ImageIOTest::Exif dictionary does not contain Exposure Time");
    double actualAltitude = [(id)CFDictionaryGetValue(exifDictionary, kCGImagePropertyExifExposureTime) doubleValue];
    ASSERT_NEAR_MSG(actualAltitude, 12.34, 0.01, "FAILED: ImageIOTest::Exposure Time mismatch");

    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyPixelHeight),
        "FAILED: ImageIOTest::Pixel Height not found");
    int actualPixelHeight = [(id)CFDictionaryGetValue(imageProperties, kCGImagePropertyPixelHeight) intValue];
    checkInt(actualPixelHeight, 1024, "Height");

    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyOrientation),
        "FAILED: ImageIOTest::Orientation not found");
    int actualOrientation = [(id)CFDictionaryGetValue(imageProperties, kCGImagePropertyOrientation) intValue];
    checkInt(actualOrientation, 3, "Orientation");

    CFRelease(imageSource);
}

TEST(ImageIO, DestinationImageOptionsJPEGTest) {
    const wchar_t* imageFile = L"photo2_683x1024.ico";
    NSData* imageData = getDataFromImageFile(imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    CFRelease(imageSource);

    const wchar_t* outFile = L"outphoto_options.jpg";
    CFURLRef imgUrl = getURLRefFromFilename(outFile);

    NSDictionary *gpsOptions = @{
        (id)kCGImagePropertyGPSLatitude:[NSNumber numberWithDouble:100.55],
        (id)kCGImagePropertyGPSLongitude:[NSNumber numberWithDouble:200.0],
        (id)kCGImagePropertyGPSLatitudeRef:@"N",
        (id)kCGImagePropertyGPSLongitudeRef:@"W",
        (id)kCGImagePropertyGPSAltitude:[NSNumber numberWithDouble:150.25],
        (id)kCGImagePropertyGPSAltitudeRef:[NSNumber numberWithShort:1],
        (id)kCGImagePropertyGPSImgDirection:[NSNumber numberWithFloat:2.4],
        (id)kCGImagePropertyGPSImgDirectionRef:@"test",
        (id)kCGImagePropertyGPSTimeStamp:@"04:30:51.71",
        (id)kCGImagePropertyGPSVersion:@"2.2.0.0",
    };

    NSDictionary *exifOptions = @{
        (id)kCGImagePropertyExifUserComment:@"Test2",
        (id)kCGImagePropertyExifExposureTime:[NSNumber numberWithDouble:12.34],
    };

    NSDictionary *tiffOptions = @{
        (id)kCGImagePropertyTIFFXResolution:[NSNumber numberWithDouble:100],
        (id)kCGImagePropertyTIFFYResolution:[NSNumber numberWithDouble:120],
        (id)kCGImagePropertyTIFFResolutionUnit:[NSNumber numberWithInt:1],
    };

    int orientation = 2;
    NSNumber* encodeOrientation = [NSNumber numberWithInt:orientation];

    NSDictionary *encodeOptions = @{
        (id)kCGImagePropertyGPSDictionary:gpsOptions,
        (id)kCGImagePropertyOrientation:encodeOrientation,
        (id)kCGImagePropertyExifDictionary:exifOptions,
        (id)kCGImagePropertyTIFFDictionary:tiffOptions,
        (id)kCGImagePropertyDPIWidth:[NSNumber numberWithDouble:1000],
        (id)kCGImagePropertyDPIHeight:[NSNumber numberWithDouble:200],
    };

    CGImageDestinationRef myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypeJPEG, 1, NULL);
    CGImageDestinationAddImage(myImageDest, imageRef, (CFDictionaryRef)encodeOptions);
    CGImageDestinationFinalize(myImageDest);
    CFRelease(myImageDest);

    imageData = getDataFromImageFile(outFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CFDictionaryRef imageProperties = CGImageSourceCopyPropertiesAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageProperties != nil, "FAILED: ImageIOTest::CGImageSourceCopyPropertiesAtIndex returned nullptr");
    
    // Print the properties due to high number of properties written, only checking a few properties
    NSLog(@"JPEG Dictionary - [%@]", (NSDictionary*)imageProperties);

    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyJFIFDictionary),
        "FAILED: ImageIOTest::JFIF dictionary not found");
    CFDictionaryRef jfifDictionary = (CFDictionaryRef)CFDictionaryGetValue(imageProperties, kCGImagePropertyJFIFDictionary);
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(jfifDictionary, kCGImagePropertyJFIFXDensity),
        "FAILED: ImageIOTest::JFIF dictionary does not contain XDensity");
    double actualXDensity = [(id)CFDictionaryGetValue(jfifDictionary, kCGImagePropertyJFIFXDensity) doubleValue];
    ASSERT_NEAR_MSG(actualXDensity, 72.0, 0.01, "FAILED: ImageIOTest::XDensity mismatch");

    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyGPSDictionary),
        "FAILED: ImageIOTest::GPS dictionary not found");
    CFDictionaryRef gpsDictionary = (CFDictionaryRef)CFDictionaryGetValue(imageProperties, kCGImagePropertyGPSDictionary);
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(gpsDictionary, kCGImagePropertyGPSAltitude),
        "FAILED: ImageIOTest::GPS dictionary does not contain Altitude");
    double actualAltitude = [(id)CFDictionaryGetValue(gpsDictionary, kCGImagePropertyGPSAltitude) doubleValue];
    ASSERT_NEAR_MSG(actualAltitude, 150.25, 0.01, "FAILED: ImageIOTest::Altitude mismatch");

    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyPixelHeight),
        "FAILED: ImageIOTest::Pixel Height not found");
    int actualPixelHeight = [(id)CFDictionaryGetValue(imageProperties, kCGImagePropertyPixelHeight) intValue];
    checkInt(actualPixelHeight, 1024, "Height");

    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyOrientation),
        "FAILED: ImageIOTest::Orientation not found");
    int actualOrientation = [(id)CFDictionaryGetValue(imageProperties, kCGImagePropertyOrientation) intValue];
    checkInt(actualOrientation, 2, "Orientation");

    CFRelease(imageSource);
}

TEST(ImageIO, DestinationImageOptionsGIFTest) {
    const wchar_t* imageFile = L"photo2_683x1024.ico";
    NSData* imageData = getDataFromImageFile(imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    CFRelease(imageSource);

    const wchar_t* outFile = L"outphoto_options.gif";
    CFURLRef imgUrl = getURLRefFromFilename(outFile);
    
    NSDictionary *gifOptions = @{
        (id)kCGImagePropertyGIFDelayTime:[NSNumber numberWithFloat:0.05],
    };

    int orientation = 2;
    NSNumber* encodeOrientation = [NSNumber numberWithInt:orientation];

    NSDictionary *encodeOptions = @{
        (id)kCGImagePropertyOrientation:encodeOrientation,
        (id)kCGImagePropertyGIFDictionary:gifOptions,
        (id)kCGImagePropertyDPIWidth:[NSNumber numberWithDouble:1000],
        (id)kCGImagePropertyDPIHeight:[NSNumber numberWithDouble:200],
    };

    CGImageDestinationRef myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypeGIF, 1, NULL);
    CGImageDestinationAddImage(myImageDest, imageRef, (CFDictionaryRef)encodeOptions);
    CGImageDestinationFinalize(myImageDest);
    CFRelease(myImageDest);

    imageData = getDataFromImageFile(outFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CFDictionaryRef imageProperties = CGImageSourceCopyPropertiesAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageProperties != nil, "FAILED: ImageIOTest::CGImageSourceCopyPropertiesAtIndex returned nullptr");
    
    // Print the properties due to high number of properties written, only checking a few properties
    NSLog(@"GIF Dictionary - [%@]", (NSDictionary*)imageProperties);

    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyGIFDictionary),
        "FAILED: ImageIOTest::GIF dictionary not found");
    CFDictionaryRef gifDictionary = (CFDictionaryRef)CFDictionaryGetValue(imageProperties, kCGImagePropertyGIFDictionary);
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(gifDictionary, kCGImagePropertyGIFUnclampedDelayTime),
        "FAILED: ImageIOTest::GIF dictionary does not contain Unclamped Delay Time");
    double actualUnclampedDelayTime = [(id)CFDictionaryGetValue(gifDictionary, kCGImagePropertyGIFUnclampedDelayTime) doubleValue];
    ASSERT_NEAR_MSG(actualUnclampedDelayTime, 0.05, 0.01, "FAILED: ImageIOTest::Unclamped Delay Time mismatch");
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(gifDictionary, kCGImagePropertyGIFDelayTime),
        "FAILED: ImageIOTest::GIF dictionary does not contain Delay Time");
    double actualDelayTime = [(id)CFDictionaryGetValue(gifDictionary, kCGImagePropertyGIFDelayTime) doubleValue];
    ASSERT_NEAR_MSG(actualDelayTime, 0.1, 0.01, "FAILED: ImageIOTest::Delay Time mismatch");

    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyPixelHeight),
        "FAILED: ImageIOTest::Pixel Height not found");
    int actualPixelHeight = [(id)CFDictionaryGetValue(imageProperties, kCGImagePropertyPixelHeight) intValue];
    checkInt(actualPixelHeight, 1024, "Height");

    CFRelease(imageSource);
}

TEST(ImageIO, DestinationImageOptionsPNGTest) {
    const wchar_t* imageFile = L"photo2_683x1024.ico";
    NSData* imageData = getDataFromImageFile(imageFile);
    CGImageSourceRef imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    CGImageRef imageRef = CGImageSourceCreateImageAtIndex(imageSource, 0, NULL);
    CFRelease(imageSource);

    const wchar_t* outFile = L"outphoto_options.png";
    CFURLRef imgUrl = getURLRefFromFilename(outFile);
    
    NSDictionary *pngOtions = @{
        (id)kCGImagePropertyPNGGamma:[NSNumber numberWithInt:45045],
    };

    int orientation = 2;
    NSNumber* encodeOrientation = [NSNumber numberWithInt:orientation];

    NSDictionary *encodeOptions = @{
        (id)kCGImagePropertyOrientation:encodeOrientation,
        (id)kCGImagePropertyPNGDictionary:pngOtions,
        (id)kCGImagePropertyDPIWidth:[NSNumber numberWithDouble:1000],
        (id)kCGImagePropertyDPIHeight:[NSNumber numberWithDouble:200],
    };

    CGImageDestinationRef myImageDest = CGImageDestinationCreateWithURL(imgUrl, kUTTypePNG, 1, NULL);
    CGImageDestinationAddImage(myImageDest, imageRef, (CFDictionaryRef)encodeOptions);
    CGImageDestinationFinalize(myImageDest);
    CFRelease(myImageDest);

    imageData = getDataFromImageFile(outFile);
    ASSERT_TRUE_MSG(imageData != nil, "FAILED: ImageIOTest::Could not find file: [%s]", outFile);
    imageSource = CGImageSourceCreateWithData((CFDataRef)imageData, NULL);
    ASSERT_TRUE_MSG(imageSource != nil, "FAILED: ImageIOTest::CGImageSourceCreateWithData returned nullptr");
    CFDictionaryRef imageProperties = CGImageSourceCopyPropertiesAtIndex(imageSource, 0, NULL);
    ASSERT_TRUE_MSG(imageProperties != nil, "FAILED: ImageIOTest::CGImageSourceCopyPropertiesAtIndex returned nullptr");
    
    // Print the properties due to high number of properties written, only checking a few properties
    NSLog(@"PNG Dictionary - [%@]", (NSDictionary*)imageProperties);

    ASSERT_TRUE_MSG(CFDictionaryContainsKey(imageProperties, kCGImagePropertyPNGDictionary),
        "FAILED: ImageIOTest::PNG dictionary not found");
    CFDictionaryRef pngDictionary = (CFDictionaryRef)CFDictionaryGetValue(imageProperties, kCGImagePropertyPNGDictionary);
    ASSERT_TRUE_MSG(CFDictionaryContainsKey(pngDictionary, kCGImagePropertyPNGGamma),
        "FAILED: ImageIOTest::PNG dictionary does not contain Gamma");
    int actualGamma = [(id)CFDictionaryGetValue(pngDictionary, kCGImagePropertyPNGGamma) intValue];
    checkInt(actualGamma, 45045, "Gamma");
    
    CFRelease(imageSource);
}