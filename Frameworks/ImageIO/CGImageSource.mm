//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGDataProvider.h>
#import <ImageIO/ImageIO.h>
#import <ImageIO/CGImageSource.h>
#import <ImageIO/CGImageSourceInternal.h>
#import <StubReturn.h>
#import <objc/runtime.h>
#import <Starboard.h>
#include <NSLogging.h>
#include <vector>

#include "COMIncludes.h"
#include "Wincodec.h"
#include <wrl/client.h>
#include "COMIncludes_End.h"

using namespace Microsoft::WRL;

static const wchar_t* TAG = L"CGImageSource"; 
const CFStringRef kCGImageSourceTypeIdentifierHint = static_cast<CFStringRef>(@"kCGImageSourceTypeIdentifierHint");
const CFStringRef kCGImageSourceShouldAllowFloat = static_cast<CFStringRef>(@"kCGImageSourceShouldAllowFloat");
const CFStringRef kCGImageSourceShouldCache = static_cast<CFStringRef>(@"kCGImageSourceShouldCache");
const CFStringRef kCGImageSourceCreateThumbnailFromImageIfAbsent =
    static_cast<CFStringRef>(@"kCGImageSourceCreateThumbnailFromImageIfAbsent");
const CFStringRef kCGImageSourceCreateThumbnailFromImageAlways = static_cast<CFStringRef>(@"kCGImageSourceCreateThumbnailFromImageAlways");
const CFStringRef kCGImageSourceThumbnailMaxPixelSize = static_cast<CFStringRef>(@"kCGImageSourceThumbnailMaxPixelSize");
const CFStringRef kCGImageSourceCreateThumbnailWithTransform = static_cast<CFStringRef>(@"kCGImageSourceCreateThumbnailWithTransform");
const CFStringRef kUTTypeJPEG = static_cast<const CFStringRef>(@"public.jpeg");
const CFStringRef kUTTypeTIFF = static_cast<const CFStringRef>(@"public.tiff");
const CFStringRef kUTTypeGIF = static_cast<const CFStringRef>(@"com.compuserve.gif");
const CFStringRef kUTTypePNG = static_cast<const CFStringRef>(@"public.png");
const CFStringRef kUTTypeBMP = static_cast<const CFStringRef>(@"com.microsoft.bmp");
const CFStringRef kUTTypeICO = static_cast<const CFStringRef>(@"com.microsoft.ico");

@implementation ImageSource
- (instancetype)initWithData:(CFDataRef)data {
    if (self = [super init]) {
        _data = (NSData*)data;
    }

    return self;
}

- (instancetype)initWithURL:(CFURLRef)url {
    if (self = [super init]) {
        _data = [NSData dataWithContentsOfURL:(NSURL*)url];
    }

    return self;
}

- (instancetype)initWithDataProvider:(CGDataProviderRef)provider {
    if (self = [super init]) {
        _data = (NSData*)CGDataProviderCopyData(provider);
    }

    return self;                               
}

// Helper function to identify image format from image byte stream
- (CFStringRef)getImageType {
    char imageIdentifier[12] = {0};
    [self.data getBytes:&imageIdentifier length:12];
    static const unsigned char BMPIdentifier[] = {'B','M'};
    static const unsigned char GIFIdentifier[] = {'G','I','F'};
    static const unsigned char ICOIdentifier[] = {0x00, 0x00, 0x01, 0x00};
    static const unsigned char JPEGIdentifier[] = {0xFF, 0xD8, 0xFF};
    static const unsigned char PNGIdentifier[] = {0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a};
    static const unsigned char TIFFIdentifier1[] = {'M', 'M', 0x00, 0x2A};
    static const unsigned char TIFFIdentifier2[] = {'I', 'I', 0x2A, 0x00};
    CFStringRef imageFormat;

    if (!memcmp(imageIdentifier, BMPIdentifier, 2)) {
        imageFormat = kUTTypeBMP;
    } else if (!memcmp(imageIdentifier, GIFIdentifier, 3)) {
        imageFormat = kUTTypeGIF;
    } else if (!memcmp(imageIdentifier, ICOIdentifier, 4)) {
        imageFormat = kUTTypeICO;
    } else if (!memcmp(imageIdentifier, JPEGIdentifier, 3)) {
        imageFormat = kUTTypeJPEG;
    } else if (!memcmp(imageIdentifier, PNGIdentifier, 8)) {
        imageFormat = kUTTypePNG;
    } else if (!memcmp(imageIdentifier, TIFFIdentifier1, 4) || !memcmp(imageIdentifier, TIFFIdentifier2, 4)) {
        imageFormat = kUTTypeTIFF;
    } else {
        imageFormat = nullptr;
    }

    if (!imageFormat) {
        UNIMPLEMENTED_WITH_MSG("Image format is not supported. "
                               "Current release supports JPEG, BMP, PNG, GIF, TIFF & ICO image formats only.");
    } 

    return imageFormat;
}
@end

/**
 @Status Caveat
 @Notes The current implementation supports common image file formats such as JPEG, GIF, TIFF, BMP, PNG and ICO. 
        Not all formats are supported.
        kCGImageSourceTypeIdentifierHint is not supported when passed in as an options dictionary key. 
*/
CGImageSourceRef CGImageSourceCreateWithDataProvider(CGDataProviderRef provider, CFDictionaryRef options) {
    RETURN_NULL_IF(!provider);
    if (options && CFDictionaryContainsKey(options, kCGImageSourceTypeIdentifierHint)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceTypeIdentifierHint is not supported in current implementation.");
    }

    return (CGImageSourceRef)[[ImageSource alloc] initWithDataProvider:provider];
}

/**
 @Status Caveat
 @Notes The current implementation supports common image file formats such as JPEG, GIF, TIFF, BMP, PNG and ICO. 
        Not all formats are supported.
        kCGImageSourceTypeIdentifierHint is not supported when passed in as an options dictionary key. 
*/
CGImageSourceRef CGImageSourceCreateWithData(CFDataRef data, CFDictionaryRef options) {
    RETURN_NULL_IF(!data);
    if (options && CFDictionaryContainsKey(options, kCGImageSourceTypeIdentifierHint)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceTypeIdentifierHint is not supported in current implementation.");
    }

    return (CGImageSourceRef)[[ImageSource alloc] initWithData:data];
}

/**
 @Status Caveat
 @Notes The current implementation supports common image file formats such as JPEG, GIF, TIFF, BMP, PNG and ICO. 
        Not all formats are supported.
        kCGImageSourceTypeIdentifierHint is not supported when passed in as an options dictionary key.
*/
CGImageSourceRef CGImageSourceCreateWithURL(CFURLRef url, CFDictionaryRef options) {
    RETURN_NULL_IF(!url);
    if (options && CFDictionaryContainsKey(options, kCGImageSourceTypeIdentifierHint)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceTypeIdentifierHint is not supported in current implementation.");
    }

    return (CGImageSourceRef)[[ImageSource alloc] initWithURL:url];
}

/**
 @Status Caveat
 @Notes Current implementation does not support kCGImageSourceShouldAllowFloat & kCGImageSourceShouldCache 
        when passed in as options dictionary keys
*/
CGImageRef CGImageSourceCreateImageAtIndex(CGImageSourceRef isrc, size_t index, CFDictionaryRef options) {
    RETURN_NULL_IF(!isrc);
    NSData* imageData = ((ImageSource*)isrc).data;
    RETURN_NULL_IF(!imageData);
    RETURN_NULL_IF(index > (CGImageSourceGetCount(isrc) - 1));

    MULTI_QI imageQueryInterface = {0};
    static const GUID IID_IWICImagingFactory = {0xec5ec8a9,0xc395,0x4314,0x9c,0x77,0x54,0xd7,0xa9,0x35,0xff,0x70};
    imageQueryInterface.pIID = &IID_IWICImagingFactory;
    RETURN_NULL_IF_FAILED(
        CoCreateInstanceFromApp(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, nullptr, 1, &imageQueryInterface));

    ComPtr<IWICImagingFactory> imageFactory = (IWICImagingFactory*)imageQueryInterface.pItf;
    ComPtr<IWICStream> imageStream;
    RETURN_NULL_IF_FAILED(imageFactory->CreateStream(&imageStream));

    unsigned char* imageByteArray = (unsigned char*)[imageData bytes];
    int imageLength = [imageData length];
    RETURN_NULL_IF_FAILED(imageStream->InitializeFromMemory(imageByteArray, imageLength));

    if (options && CFDictionaryContainsKey(options, kCGImageSourceShouldCache)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceShouldCache is not supported in current implementation.");
    }

    ComPtr<IWICBitmapDecoder> imageDecoder;                
    RETURN_NULL_IF_FAILED(imageFactory->CreateDecoderFromStream(imageStream.Get(), nullptr, WICDecodeMetadataCacheOnDemand, &imageDecoder));

    ComPtr<IWICBitmapFrameDecode> imageFrame;
    RETURN_NULL_IF_FAILED(imageDecoder->GetFrame(index, &imageFrame));

    unsigned int frameWidth = 0;
    unsigned int frameHeight = 0;
    RETURN_NULL_IF_FAILED(imageFrame->GetSize(&frameWidth, &frameHeight));

    ComPtr<IWICFormatConverter> imageFormatConverter;
    RETURN_NULL_IF_FAILED(imageFactory->CreateFormatConverter(&imageFormatConverter));

    if (options && CFDictionaryContainsKey(options, kCGImageSourceShouldAllowFloat)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceShouldAllowFloat is not supported in current implementation.");
    }

    RETURN_NULL_IF_FAILED(imageFormatConverter->Initialize(imageFrame.Get(), 
                                                           GUID_WICPixelFormat32bppRGBA,
                                                           WICBitmapDitherTypeNone, 
                                                           nullptr, 
                                                           0.f, 
                                                           WICBitmapPaletteTypeCustom));

    const unsigned int frameSize = frameWidth * frameHeight * 4;
    unsigned char* frameByteArray = static_cast<unsigned char*>(IwMalloc(frameSize));
    if (!frameByteArray) {
        NSTraceInfo(TAG, @"CGImageSourceCreateImageAtIndex cannot allocate memory");
        return nullptr;
    }

    auto cleanup = wil::ScopeExit([&]() { IwFree(frameByteArray); });
    RETURN_NULL_IF_FAILED(imageFormatConverter->CopyPixels(0, frameWidth * 4, frameSize, frameByteArray));
    cleanup.Dismiss();

    NSData* frameData = [NSData dataWithBytesNoCopy:frameByteArray length:frameSize freeWhenDone:YES];    
    CGDataProviderRef frameDataProvider =  CGDataProviderCreateWithCFData((CFDataRef)frameData);
    CGColorSpaceRef colorspaceRgb = CGColorSpaceCreateDeviceRGB();
    CGImageRef imageRef = CGImageCreate(frameWidth, 
                                        frameHeight, 
                                        8, 
                                        32, 
                                        frameWidth * 4, 
                                        colorspaceRgb, 
                                        kCGImageAlphaFirst, 
                                        frameDataProvider, 
                                        nullptr, 
                                        true, 
                                        kCGRenderingIntentDefault);
    CGDataProviderRelease(frameDataProvider);
    CGColorSpaceRelease(colorspaceRgb);                                         
    return imageRef;
}

/**
 @Status Caveat
 @Notes Current implementation does not support kCGImageSourceShouldAllowFloat, kCGImageSourceShouldCache & 
        kCGImageSourceCreateThumbnailWithTransform when passed in as options dictionary keys
*/
CGImageRef CGImageSourceCreateThumbnailAtIndex(CGImageSourceRef isrc, size_t index, CFDictionaryRef options) {
    RETURN_NULL_IF(!isrc);
    NSData* imageData = ((ImageSource*)isrc).data;
    RETURN_NULL_IF(!imageData);
    RETURN_NULL_IF(index > (CGImageSourceGetCount(isrc) - 1));

    MULTI_QI imageQueryInterface = {0};
    static const GUID IID_IWICImagingFactory = {0xec5ec8a9,0xc395,0x4314,0x9c,0x77,0x54,0xd7,0xa9,0x35,0xff,0x70};
    imageQueryInterface.pIID = &IID_IWICImagingFactory;
    RETURN_NULL_IF_FAILED(
        CoCreateInstanceFromApp(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, nullptr, 1, &imageQueryInterface));

    ComPtr<IWICImagingFactory> imageFactory = (IWICImagingFactory*)imageQueryInterface.pItf;
    ComPtr<IWICStream> imageStream;        
    RETURN_NULL_IF_FAILED(imageFactory->CreateStream(&imageStream));

    unsigned char* imageByteArray = (unsigned char*)[imageData bytes];
    int imageLength = [imageData length];
    RETURN_NULL_IF_FAILED(imageStream->InitializeFromMemory(imageByteArray, imageLength));

    if (options && CFDictionaryContainsKey(options, kCGImageSourceShouldCache)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceShouldCache is not supported in current implementation.");
    }

    ComPtr<IWICBitmapDecoder> imageDecoder;
    RETURN_NULL_IF_FAILED(imageFactory->CreateDecoderFromStream(imageStream.Get(), nullptr, WICDecodeMetadataCacheOnDemand, &imageDecoder));

    ComPtr<IWICBitmapFrameDecode> imageFrame;
    RETURN_NULL_IF_FAILED(imageDecoder->GetFrame(index, &imageFrame));

    if (options && CFDictionaryContainsKey(options, kCGImageSourceCreateThumbnailWithTransform)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceCreateThumbnailWithTransform is not supported in "
                                "current implementation.");
    }
    
    ComPtr<IWICFormatConverter> imageFormatConverter;                        
    RETURN_NULL_IF_FAILED(imageFactory->CreateFormatConverter(&imageFormatConverter));

    ComPtr<IWICBitmapScaler> imageScaler;
    RETURN_NULL_IF_FAILED(imageFactory->CreateBitmapScaler(&imageScaler));

    unsigned int thumbnailWidth = 0;
    unsigned int thumbnailHeight = 0;
    bool thumbnailExists = false;
    ComPtr<IWICBitmapSource> imageThumbnail;

    //Check if incoming image frame has an existing thumbnail. Return NULL if absent & thumbnail creation flags are not specified.
    if (!SUCCEEDED(imageFrame->GetThumbnail(&imageThumbnail))) {
        if (options && (CFDictionaryContainsKey(options, kCGImageSourceCreateThumbnailFromImageIfAbsent) || 
                        CFDictionaryContainsKey(options, kCGImageSourceCreateThumbnailFromImageAlways))) {
            RETURN_NULL_IF_FAILED(imageFrame->GetSize(&thumbnailWidth, &thumbnailHeight));
        }  
    } else {
        thumbnailExists = true;
        RETURN_NULL_IF_FAILED(imageThumbnail->GetSize(&thumbnailWidth, &thumbnailHeight));
    } 

    unsigned int maxThumbnailSize = 0;
    if (options && CFDictionaryContainsKey(options, kCGImageSourceThumbnailMaxPixelSize)) {
        maxThumbnailSize = [(id)CFDictionaryGetValue(options, kCGImageSourceThumbnailMaxPixelSize) intValue];
    }

    //Maintain aspect ratio if thumbnail size exceeds maximum thumbnail pixel size
    if (maxThumbnailSize && ((thumbnailWidth > maxThumbnailSize) || (thumbnailHeight > maxThumbnailSize))) {
        if (thumbnailWidth >= thumbnailHeight) {
            thumbnailHeight = thumbnailHeight / thumbnailWidth * maxThumbnailSize;
            thumbnailWidth = maxThumbnailSize;
        } else {
            thumbnailWidth = thumbnailWidth / thumbnailHeight * maxThumbnailSize;
            thumbnailHeight = maxThumbnailSize;
        }
                                    
        if (!thumbnailWidth || !thumbnailHeight) {
            thumbnailWidth = maxThumbnailSize;
            thumbnailHeight = maxThumbnailSize;
        }
    }

    //Scale thumbnail according to the calculated dimensions
    if (!thumbnailExists || (thumbnailExists && 
                             options && 
                             CFDictionaryContainsKey(options, kCGImageSourceCreateThumbnailFromImageAlways))) {
        RETURN_NULL_IF_FAILED(imageScaler->Initialize(imageFrame.Get(),
                                                      thumbnailWidth,
                                                      thumbnailHeight,
                                                      WICBitmapInterpolationModeCubic));    
    } else {
        RETURN_NULL_IF_FAILED(imageScaler->Initialize(imageThumbnail.Get(),
                                                      thumbnailWidth,
                                                      thumbnailHeight,
                                                      WICBitmapInterpolationModeCubic));    
    }

    if (options && CFDictionaryContainsKey(options, kCGImageSourceShouldAllowFloat)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceShouldAllowFloat is not supported in current implementation.");
    }

    RETURN_NULL_IF_FAILED(imageFormatConverter->Initialize(imageScaler.Get(), 
                                                           GUID_WICPixelFormat32bppRGBA,
                                                           WICBitmapDitherTypeNone, 
                                                           nullptr, 
                                                           0.f, 
                                                           WICBitmapPaletteTypeCustom));

    const unsigned int thumbnailSize = thumbnailWidth * thumbnailHeight * 4;
    unsigned char* thumbnailByteArray = static_cast<unsigned char*>(IwMalloc(thumbnailSize));
    if (!thumbnailByteArray) {
        NSTraceInfo(TAG, @"CGImageSourceCreateThumbnailAtIndex cannot allocate memory");
        return nullptr;    
    }

    auto cleanup = wil::ScopeExit([&]() { IwFree(thumbnailByteArray); });
    RETURN_NULL_IF_FAILED(imageFormatConverter->CopyPixels(0, 
                                                           thumbnailWidth * 4, 
                                                           thumbnailSize, 
                                                           thumbnailByteArray));
    cleanup.Dismiss();

    NSData* thumbnailData = [NSData dataWithBytesNoCopy:thumbnailByteArray length:thumbnailSize freeWhenDone:YES];    
    CGDataProviderRef thumbnailDataProvider = CGDataProviderCreateWithCFData((CFDataRef)thumbnailData);
    CGColorSpaceRef colorspaceRgb = CGColorSpaceCreateDeviceRGB();
    CGImageRef imageRef = CGImageCreate(thumbnailWidth, 
                                        thumbnailHeight, 
                                        8, 
                                        32, 
                                        thumbnailWidth * 4, 
                                        colorspaceRgb, 
                                        kCGImageAlphaFirst, 
                                        thumbnailDataProvider, 
                                        nullptr, 
                                        true, 
                                        kCGRenderingIntentDefault);
    CGDataProviderRelease(thumbnailDataProvider);
    CGColorSpaceRelease(colorspaceRgb);                                                
    return imageRef;
}

/**
 @Status Stub
 @Notes
*/
CGImageSourceRef CGImageSourceCreateIncremental(CFDictionaryRef options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGImageSourceUpdateData(CGImageSourceRef isrc, CFDataRef data, bool final) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGImageSourceUpdateDataProvider(CGImageSourceRef isrc, CGDataProviderRef provider, bool final) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CGImageSourceGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Current release supports JPEG, BMP, PNG, GIF, TIFF & ICO image formats only 
*/
CFStringRef CGImageSourceGetType(CGImageSourceRef isrc) {
    RETURN_NULL_IF(!isrc);
    ImageSource* imageSrc = (ImageSource*)isrc;
    RETURN_NULL_IF(!imageSrc.data);
    return [imageSrc getImageType];
}

/**
 @Status Caveat
 @Notes Current release supports JPEG, BMP, PNG, GIF, TIFF & ICO image formats only 
*/
CFArrayRef CGImageSourceCopyTypeIdentifiers() {
    static const CFStringRef typeIdentifiers[] = {kUTTypePNG, kUTTypeJPEG, kUTTypeGIF, kUTTypeTIFF, kUTTypeICO, kUTTypeBMP};
    CFArrayRef imageTypeIdentifiers = CFArrayCreate(nullptr, (const void**)typeIdentifiers, ARRAYSIZE(typeIdentifiers), &kCFTypeArrayCallBacks);
    return imageTypeIdentifiers;
}

size_t CGImageSourceGetCount(CGImageSourceRef isrc) {
    if (!isrc) {
        return 0;
    }

    NSData* imageData = ((ImageSource*)isrc).data;
    if (!imageData) {
        return 0;
    }

    MULTI_QI imageQueryInterface = {0};
    static const GUID IID_IWICImagingFactory = {0xec5ec8a9,0xc395,0x4314,0x9c,0x77,0x54,0xd7,0xa9,0x35,0xff,0x70};
    imageQueryInterface.pIID = &IID_IWICImagingFactory;
    HRESULT status = CoCreateInstanceFromApp(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, nullptr, 1, &imageQueryInterface);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"CoCreateInstanceFromApp failed with status=%x\n", status);
        return 0;
    } 
    
    ComPtr<IWICImagingFactory> imageFactory = (IWICImagingFactory*)imageQueryInterface.pItf;
    ComPtr<IWICStream> imageStream;        
    status = imageFactory->CreateStream(&imageStream);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"IWICImagingFactory::CreateStream failed with status=%x\n", status);
        return 0;
    } 

    unsigned char* imageByteArray = (unsigned char*)[imageData bytes];
    int imageLength = [imageData length];
    status = imageStream->InitializeFromMemory(imageByteArray, imageLength);
    if (!SUCCEEDED(status)) { 
        NSTraceInfo(TAG, @"IWICStream::InitializeFromMemory failed with status=%x\n", status);
        return 0;
    } 
    
    ComPtr<IWICBitmapDecoder> imageDecoder;        
    status = imageFactory->CreateDecoderFromStream(imageStream.Get(), nullptr, WICDecodeMetadataCacheOnDemand, &imageDecoder);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"IWICImagingFactory::CreateDecoderFromStream failed with status=%x\n", status);
        return 0;
    } 
    
    size_t frameCount = 0;
    status = imageDecoder->GetFrameCount(&frameCount);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"IWICBitmapDecoder::GetFrameCount failed with status=%x\n", status);
    } 

    return frameCount;
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CGImageSourceCopyProperties(CGImageSourceRef isrc, CFDictionaryRef options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CGImageSourceCopyPropertiesAtIndex(CGImageSourceRef isrc, size_t index, CFDictionaryRef options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGImageSourceStatus CGImageSourceGetStatus(CGImageSourceRef isrc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGImageSourceStatus CGImageSourceGetStatusAtIndex(CGImageSourceRef isrc, size_t index) {
    UNIMPLEMENTED();
    return StubReturn();
}
