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

const unsigned int c_minutesPerDegree = 60;
const unsigned int c_secondsPerDegree = 3600;

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

CFDictionaryRef readJPEGProperties(IWICMetadataQueryReader* imageMetadataReader) {
    PROPVARIANT propertyValue;
    PropVariantInit(&propertyValue);
    NSMutableDictionary *properties = [[NSMutableDictionary alloc] init];

    // JPEG Properties - Common
    // DPIHeight and DPIWidth are saved in different places for different image formats, and these locations only represent
    // DPI if {ushort=1} is 1, otherwise they are other units.
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=282}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [properties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart]
                       forKey:(id)kCGImagePropertyDPIWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=283}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [properties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart]
                       forKey:(id)kCGImagePropertyDPIHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=256}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=256}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPixelWidth];
    }
    
    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=257}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=257}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=258}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyDepth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=274}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyOrientation];
    }

    // JPEG Properties - Format-specific
    NSMutableDictionary *jfifProperties = [[NSMutableDictionary alloc] init];
    PropVariantClear(&propertyValue);

    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app0/{ushort=0}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        // NSArray doesn't print properly but this is how iOS does it
        NSMutableArray* jfifVersionArray = [NSMutableArray array];
        [jfifVersionArray addObject:[NSNumber numberWithInt:(propertyValue.uiVal >> 8) & 0xF]];
        [jfifVersionArray addObject:[NSNumber numberWithInt:(propertyValue.uiVal >> 4) & 0xF]];
        [jfifVersionArray addObject:[NSNumber numberWithInt:propertyValue.uiVal & 0xF]];
        [jfifProperties setObject:jfifVersionArray forKey:(id)kCGImagePropertyJFIFVersion];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app0/{ushort=2}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [jfifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyJFIFXDensity];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app0/{ushort=3}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [jfifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyJFIFYDensity];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app0/{ushort=1}", &propertyValue)) && propertyValue.vt == VT_UI1) {
        [jfifProperties setObject:[NSNumber numberWithInt:propertyValue.bVal] forKey:(id)kCGImagePropertyJFIFDensityUnit];
    }

    // Add the JFIF dictionary to the properties if there are any JFIF properties
    if ([[jfifProperties allKeys] count] != 0) {
        [properties setObject:jfifProperties forKey:(id)kCGImagePropertyJFIFDictionary];
    }

    // GPS Properties - JPEG
    NSMutableDictionary *gpsProperties = [[NSMutableDictionary alloc] init];
    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=6}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                          forKey:(id)kCGImagePropertyGPSAltitude];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=5}", &propertyValue)) && propertyValue.vt == VT_UI1) {
        [gpsProperties setObject:[NSNumber numberWithInt:propertyValue.bVal] forKey:(id)kCGImagePropertyGPSAltitudeRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=29}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSDateStamp];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=11}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                          forKey:(id)kCGImagePropertyGPSDOP];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=17}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                          forKey:(id)kCGImagePropertyGPSImgDirection];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=16}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSImgDirectionRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=2}", &propertyValue)) && 
        propertyValue.vt == (VT_VECTOR | VT_UI8)) {
        if (propertyValue.caub.cElems == 3) { // Validate number of fields
            double degreesPart = (double)propertyValue.cauh.pElems[0].LowPart/propertyValue.cauh.pElems[0].HighPart;
            double minutesPart = (double)propertyValue.cauh.pElems[1].LowPart/propertyValue.cauh.pElems[1].HighPart;
            double secondsPart = (double)propertyValue.cauh.pElems[2].LowPart/propertyValue.cauh.pElems[2].HighPart;
            [gpsProperties setObject:[NSNumber numberWithDouble:degreesPart + 
                minutesPart/c_minutesPerDegree + secondsPart/(c_secondsPerDegree)] forKey:(id)kCGImagePropertyGPSLatitude];
        }
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=1}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSLatitudeRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=4}", &propertyValue)) &&
        propertyValue.vt == (VT_VECTOR | VT_UI8)) {
        if (propertyValue.caub.cElems == 3) { // Validate number of fields
            double degreesPart = (double)propertyValue.cauh.pElems[0].LowPart/propertyValue.cauh.pElems[0].HighPart;
            double minutesPart = (double)propertyValue.cauh.pElems[1].LowPart/propertyValue.cauh.pElems[1].HighPart;
            double secondsPart = (double)propertyValue.cauh.pElems[2].LowPart/propertyValue.cauh.pElems[2].HighPart;
            [gpsProperties setObject:[NSNumber numberWithDouble:degreesPart + 
                minutesPart/c_minutesPerDegree + secondsPart/(c_secondsPerDegree)] forKey:(id)kCGImagePropertyGPSLongitude];
        }
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=3}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSLongitudeRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=13}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                          forKey:(id)kCGImagePropertyGPSSpeed];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=12}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSSpeedRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=7}", &propertyValue)) && 
        propertyValue.vt == (VT_VECTOR | VT_UI8)) {
        double timeStampHours = (double)propertyValue.cauh.pElems[0].LowPart/propertyValue.cauh.pElems[0].HighPart;
        double timeStampMinutes = (double)propertyValue.cauh.pElems[1].LowPart/propertyValue.cauh.pElems[1].HighPart;
        double timeStampSeconds = (double)propertyValue.cauh.pElems[2].LowPart/propertyValue.cauh.pElems[2].HighPart;
        [gpsProperties setObject:[NSString stringWithFormat:@"%.2d:%.2d:%.2f", (int)timeStampHours, (int)timeStampMinutes, timeStampSeconds]
                          forKey:(id)kCGImagePropertyGPSTimeStamp];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=15}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                          forKey:(id)kCGImagePropertyGPSTrack];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=14}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSTrackRef];
    }
    
    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=0}", &propertyValue)) && 
        propertyValue.vt == (VT_VECTOR | VT_UI1)) {
        if (propertyValue.caub.cElems == 4) {
            NSMutableArray* gpsVersionArray = [NSMutableArray array];
            for (int index = 0; index < 4; index++) {
                [gpsVersionArray addObject:[NSNumber numberWithInt:propertyValue.caub.pElems[index]]];
            }

            [gpsProperties setObject:gpsVersionArray forKey:(id)kCGImagePropertyGPSVersion];
        }
    }

    // Add the GPS dictionary to the properties if there are any GPS properties
    if ([[gpsProperties allKeys] count] != 0) {
        [properties setObject:gpsProperties forKey:(id)kCGImagePropertyGPSDictionary];
    }

    // Exif Properties - JPEG
    NSMutableDictionary *exifProperties = [[NSMutableDictionary alloc] init];
    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=40962}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        // iOS can get both the general image dimension properties as well as Exif ones from this value
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifPixelXDimension];
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=40962}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyExifPixelXDimension];
        [properties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPixelWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=40963}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifPixelYDimension];
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=40963}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyExifPixelYDimension];
        [properties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPixelHeight];
    }
    
    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=33434}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                           forKey:(id)kCGImagePropertyExifExposureTime];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=37378}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                           forKey:(id)kCGImagePropertyExifApertureValue];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=37379}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                           forKey:(id)kCGImagePropertyExifBrightnessValue];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=36868}", &propertyValue)) && 
        propertyValue.vt == VT_LPSTR) {
        [exifProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyExifDateTimeDigitized];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=36867}", &propertyValue)) && 
        propertyValue.vt == VT_LPSTR) {
        [exifProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyExifDateTimeOriginal];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=41988}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                           forKey:(id)kCGImagePropertyExifDigitalZoomRatio];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=41986}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifExposureMode];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=34850}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifExposureProgram];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=37385}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifFlash];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=33437}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                           forKey:(id)kCGImagePropertyExifFNumber];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=37386}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                           forKey:(id)kCGImagePropertyExifFocalLength];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=34867}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyExifISOSpeedRatings];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=42035}", &propertyValue)) && 
        propertyValue.vt == VT_LPSTR) {
        [exifProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyExifLensMake];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=42036}", &propertyValue)) && 
        propertyValue.vt == VT_LPSTR) {
        [exifProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyExifLensModel];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=37500}", &propertyValue)) && 
        propertyValue.vt == VT_BLOB) {
        [exifProperties setObject:[NSData dataWithBytesNoCopy:propertyValue.blob.pBlobData 
                                                       length:propertyValue.blob.cbSize 
                                                 freeWhenDone:YES] 
                           forKey:(id)kCGImagePropertyExifMakerNote];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=37383}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifMeteringMode];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=41990}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifSceneCaptureType];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=37377}", &propertyValue)) && propertyValue.vt == VT_I8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.hVal.LowPart/propertyValue.hVal.HighPart] 
                           forKey:(id)kCGImagePropertyExifShutterSpeedValue];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=37510}", &propertyValue)) && propertyValue.vt == VT_LPWSTR) {
        [exifProperties setObject:[[NSString alloc] initWithBytes:propertyValue.pwszVal 
                                                           length:wcslen(propertyValue.pwszVal)*sizeof(wchar_t)
                                                         encoding:NSUnicodeStringEncoding] 
                           forKey:(id)kCGImagePropertyExifUserComment];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=36864}", &propertyValue)) && propertyValue.vt == VT_BLOB) {
        [exifProperties setObject:[NSData dataWithBytesNoCopy:propertyValue.blob.pBlobData length:propertyValue.blob.cbSize freeWhenDone:YES] 
                           forKey:(id)kCGImagePropertyExifVersion];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=41987}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifWhiteBalance];
    }
    
    // Add the Exif dictionary to the properties if there are any Exif properties
    if ([[exifProperties allKeys] count] != 0) {
        [properties setObject:exifProperties forKey:(id)kCGImagePropertyExifDictionary];
    }

    // The following properties are in TIFF property dictionary, but for /app1/ifd/, which is not a TIFF directory
    // This information gets read for JPEG files on iOS, and do in fact get added to a TIFF dictionary, even for a JPEG
    NSMutableDictionary *tiffProperties = [[NSMutableDictionary alloc] init];
    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=274}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [tiffProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyTIFFOrientation];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=282}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [tiffProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                           forKey:(id)kCGImagePropertyTIFFXResolution];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=283}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [tiffProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                           forKey:(id)kCGImagePropertyTIFFYResolution];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=296}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [tiffProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyTIFFResolutionUnit];
    }

    // Add the TIFF dictionary to the properties if there are any TIFF properties
    if ([[tiffProperties allKeys] count] != 0) {
        [properties setObject:tiffProperties forKey:(id)kCGImagePropertyTIFFDictionary];
    }

    return (CFDictionaryRef)properties;
}

CFDictionaryRef readTIFFProperties(IWICMetadataQueryReader* imageMetadataReader) {
    PROPVARIANT propertyValue;
    PropVariantInit(&propertyValue);
    NSMutableDictionary *properties = [[NSMutableDictionary alloc] init];

    // TIFF Properties - Common
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=283}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [properties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                       forKey:(id)kCGImagePropertyDPIHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=282}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [properties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                       forKey:(id)kCGImagePropertyDPIWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=256}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=256}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPixelWidth];
    }
    
    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=257}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=257}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=258}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyDepth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=274}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyOrientation];
    }

    // TIFF Properties - Format-specific
    NSMutableDictionary *tiffProperties = [[NSMutableDictionary alloc] init];
    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=259}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [tiffProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyTIFFCompression];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=262}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [tiffProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyTIFFPhotometricInterpretation];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=270}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [tiffProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyTIFFImageDescription];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=271}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [tiffProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyTIFFMake];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=272}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [tiffProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyTIFFModel];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=274}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [tiffProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyTIFFOrientation];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=282}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [tiffProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                           forKey:(id)kCGImagePropertyTIFFXResolution];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=283}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [tiffProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                           forKey:(id)kCGImagePropertyTIFFYResolution];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=296}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [tiffProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyTIFFResolutionUnit];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=305}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [tiffProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyTIFFSoftware];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=306}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [tiffProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyTIFFDateTime];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=315}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [tiffProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyTIFFArtist];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=33432}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [tiffProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyTIFFCopyright];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=41987}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [tiffProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyTIFFWhitePoint];
    }

    // Add the TIFF dictionary to the properties if there are any TIFF properties
    if ([[tiffProperties allKeys] count] != 0) {
        [properties setObject:tiffProperties forKey:(id)kCGImagePropertyTIFFDictionary];
    }

    // GPS Properties - TIFF - This is a copy of TIFF properties for JPEG but with different paths.
    NSMutableDictionary *gpsProperties = [[NSMutableDictionary alloc] init];

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=6}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                          forKey:(id)kCGImagePropertyGPSAltitude];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=5}", &propertyValue)) && propertyValue.vt == VT_UI1) {
        [gpsProperties setObject:[NSNumber numberWithInt:propertyValue.bVal] forKey:(id)kCGImagePropertyGPSAltitudeRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=29}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSDateStamp];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=11}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                          forKey:(id)kCGImagePropertyGPSDOP];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=17}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                          forKey:(id)kCGImagePropertyGPSImgDirection];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=16}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSImgDirectionRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=2}", &propertyValue)) && 
        propertyValue.vt == (VT_VECTOR | VT_UI8)) {
        if (propertyValue.caub.cElems == 3) { // Validate number of fields
            double degreesPart = (double)propertyValue.cauh.pElems[0].LowPart/propertyValue.cauh.pElems[0].HighPart;
            double minutesPart = (double)propertyValue.cauh.pElems[1].LowPart/propertyValue.cauh.pElems[1].HighPart;
            double secondsPart = (double)propertyValue.cauh.pElems[2].LowPart/propertyValue.cauh.pElems[2].HighPart;
            [gpsProperties setObject:[NSNumber numberWithDouble:degreesPart + 
                minutesPart/c_minutesPerDegree + secondsPart/(c_secondsPerDegree)] forKey:(id)kCGImagePropertyGPSLatitude];
        }
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=1}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSLatitudeRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=4}", &propertyValue))
                && propertyValue.vt == (VT_VECTOR | VT_UI8)) {
        if (propertyValue.caub.cElems == 3) { // Validate number of fields
            double degreesPart = (double)propertyValue.cauh.pElems[0].LowPart/propertyValue.cauh.pElems[0].HighPart;
            double minutesPart = (double)propertyValue.cauh.pElems[1].LowPart/propertyValue.cauh.pElems[1].HighPart;
            double secondsPart = (double)propertyValue.cauh.pElems[2].LowPart/propertyValue.cauh.pElems[2].HighPart;
            [gpsProperties setObject:[NSNumber numberWithDouble:degreesPart + 
                minutesPart/c_minutesPerDegree + secondsPart/(c_secondsPerDegree)] forKey:(id)kCGImagePropertyGPSLongitude];
        }
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=3}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSLongitudeRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=13}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                          forKey:(id)kCGImagePropertyGPSSpeed];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=12}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSSpeedRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=7}", &propertyValue)) && 
        propertyValue.vt == (VT_VECTOR | VT_UI8)) {
        double timeStampHours = (double)propertyValue.cauh.pElems[0].LowPart/propertyValue.cauh.pElems[0].HighPart;
        double timeStampMinutes = (double)propertyValue.cauh.pElems[1].LowPart/propertyValue.cauh.pElems[1].HighPart;
        double timeStampSeconds = (double)propertyValue.cauh.pElems[2].LowPart/propertyValue.cauh.pElems[2].HighPart;
        [gpsProperties setObject:[NSString stringWithFormat:@"%.2d:%.2d:%.2f", (int)timeStampHours, (int)timeStampMinutes, timeStampSeconds] 
                          forKey:(id)kCGImagePropertyGPSTimeStamp];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=15}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                          forKey:(id)kCGImagePropertyGPSTrack];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=14}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSTrackRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=0}", &propertyValue)) && 
        propertyValue.vt == (VT_VECTOR | VT_UI1)) {
        if (propertyValue.caub.cElems == 4) {
            NSMutableArray* gpsVersionArray = [NSMutableArray array];
            for (int index = 0; index < 4; index++) {
                [gpsVersionArray addObject:[NSNumber numberWithInt:propertyValue.caub.pElems[index]]];
            }

            [gpsProperties setObject:gpsVersionArray forKey:(id)kCGImagePropertyGPSVersion];
        }
    }
    
    // Add the GPS dictionary to the properties if there are any GPS properties
    if ([[gpsProperties allKeys] count] != 0) {
        [properties setObject:gpsProperties forKey:(id)kCGImagePropertyGPSDictionary];
    }

    // Exif Properties - TIFF - This is a copy of Exif properties for JPEG but with different paths.
    NSMutableDictionary *exifProperties = [[NSMutableDictionary alloc] init];

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=40962}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifPixelXDimension];
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=40962}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyExifPixelXDimension];
        [properties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPixelWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=40963}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifPixelYDimension];
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=40963}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyExifPixelYDimension];
        [properties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=33434}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                           forKey:(id)kCGImagePropertyExifExposureTime];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=37378}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                           forKey:(id)kCGImagePropertyExifApertureValue];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=37379}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                           forKey:(id)kCGImagePropertyExifBrightnessValue];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=36868}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [exifProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyExifDateTimeDigitized];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=36867}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [exifProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyExifDateTimeOriginal];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=41988}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                           forKey:(id)kCGImagePropertyExifDigitalZoomRatio];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=41986}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifExposureMode];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=34850}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifExposureProgram];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=37385}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifFlash];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=33437}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                           forKey:(id)kCGImagePropertyExifFNumber];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=37386}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart/propertyValue.uhVal.HighPart] 
                           forKey:(id)kCGImagePropertyExifFocalLength];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=34867}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyExifISOSpeedRatings];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=42035}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [exifProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyExifLensMake];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=42036}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [exifProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyExifLensModel];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=37500}", &propertyValue)) && propertyValue.vt == VT_BLOB) {
        [exifProperties setObject:[NSData dataWithBytesNoCopy:propertyValue.blob.pBlobData length:propertyValue.blob.cbSize freeWhenDone:YES] 
                           forKey:(id)kCGImagePropertyExifMakerNote];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=37383}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifMeteringMode];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=41990}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifSceneCaptureType];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=37377}", &propertyValue)) && propertyValue.vt == VT_I8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.hVal.LowPart/propertyValue.hVal.HighPart] 
                           forKey:(id)kCGImagePropertyExifShutterSpeedValue];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=37510}", &propertyValue)) && propertyValue.vt == VT_LPWSTR) {
        [exifProperties setObject:[[NSString alloc] initWithBytes:propertyValue.pwszVal 
                                                           length:wcslen(propertyValue.pwszVal)*sizeof(wchar_t)
                                                         encoding:NSUnicodeStringEncoding] 
                           forKey:(id)kCGImagePropertyExifUserComment];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=36864}", &propertyValue)) && propertyValue.vt == VT_BLOB) {
        [exifProperties setObject:[NSData dataWithBytesNoCopy:propertyValue.blob.pBlobData 
                                                       length:propertyValue.blob.cbSize 
                                                 freeWhenDone:YES]
                           forKey:(id)kCGImagePropertyExifVersion];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=41987}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifWhiteBalance];
    }

    // Add the Exif dictionary to the properties if there are any Exif properties
    if ([[exifProperties allKeys] count] != 0) {
        [properties setObject:exifProperties forKey:(id)kCGImagePropertyExifDictionary];
    }

    return (CFDictionaryRef)properties;
}

CFDictionaryRef readGIFProperties(IWICMetadataQueryReader* imageMetadataReader) {
    // GIF Properties - Common
    PROPVARIANT propertyValue;
    PropVariantInit(&propertyValue);
    NSMutableDictionary *properties = [[NSMutableDictionary alloc] init];

    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/imgdesc/Width", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/imgdesc/Height", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/grctlext/TransparencyFlag", &propertyValue)) && propertyValue.vt == VT_BOOL) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.boolVal] forKey:(id)kCGImagePropertyHasAlpha];
    }
    
    // GIF Properties - Format-specific
    NSMutableDictionary *gifProperties = [[NSMutableDictionary alloc] init];

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/grctlext/Delay", &propertyValue)) && propertyValue.vt == VT_UI2) {
        // Delay time is represented in 1/100ths of a second, iOS records seconds
        double delayTime = propertyValue.uiVal/100.0;
        if (delayTime < 0.1) {
            [gifProperties setObject:[NSNumber numberWithDouble:0.1] forKey:(id)kCGImagePropertyGIFDelayTime];
            [gifProperties setObject:[NSNumber numberWithDouble:delayTime] forKey:(id)kCGImagePropertyGIFUnclampedDelayTime];
        } else {
            [gifProperties setObject:[NSNumber numberWithDouble:delayTime] forKey:(id)kCGImagePropertyGIFDelayTime];
            [gifProperties setObject:[NSNumber numberWithDouble:delayTime] forKey:(id)kCGImagePropertyGIFUnclampedDelayTime];
        }
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/logscrdesc/GlobalColorTableFlag", &propertyValue)) && 
        propertyValue.vt == VT_UI2) {
        [gifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyGIFHasGlobalColorMap];
    }

    // Add the GIF dictionary to the properties if there are any GIF properties
    if ([[gifProperties allKeys] count] != 0) {
        [properties setObject:gifProperties forKey:(id)kCGImagePropertyGIFDictionary];
    }

    return (CFDictionaryRef)properties;
}

CFDictionaryRef readPNGProperties(IWICMetadataQueryReader* imageMetadataReader) {
    PROPVARIANT propertyValue;
    PropVariantInit(&propertyValue);
    NSMutableDictionary *properties = [[NSMutableDictionary alloc] init];

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/iCCP/ProfileName", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [properties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyProfileName];
    }

    // PNG Properties - Format-specific
    NSMutableDictionary *pngProperties = [[NSMutableDictionary alloc] init];

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/gAMA/ImageGamma", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [pngProperties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPNGGamma];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/sRGB/RenderingIntent", &propertyValue)) && propertyValue.vt == VT_UI1) {
        [pngProperties setObject:[NSNumber numberWithInt:propertyValue.bVal] forKey:(id)kCGImagePropertyPNGsRGBIntent];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/chrominance/TableEntry", &propertyValue)) && 
        propertyValue.vt == (VT_VECTOR | VT_UI1)) {
        // [pngProperties setObject:[NSArray arrayWithObjects:(id)propertyValue.caub.pElems count:propertyValue.caub.cElems] 
        //                   forKey:(id)kCGImagePropertyPNGChromaticities];
    }

    // Add the PNG dictionary to the properties if there are any PNG properties
    if ([[pngProperties allKeys] count] != 0) {
        [properties setObject:pngProperties forKey:(id)kCGImagePropertyPNGDictionary];
    }

    return (CFDictionaryRef)properties;
}

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

    // Check if incoming image frame has an existing thumbnail. Return NULL if absent & thumbnail creation flags are not specified.
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

    // Maintain aspect ratio if thumbnail size exceeds maximum thumbnail pixel size
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

    // Scale thumbnail according to the calculated dimensions
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
 @Status Caveat
 @Notes A limited subset of source container properties are supported currently  
*/
CFDictionaryRef CGImageSourceCopyProperties(CGImageSourceRef isrc, CFDictionaryRef options) {
    RETURN_NULL_IF(!isrc);
    NSData* imageData = ((ImageSource*)isrc).data;
    RETURN_NULL_IF(!imageData);

    NSMutableDictionary *properties = [[NSMutableDictionary alloc] init]; 
    [properties setObject:[NSNumber numberWithInt:[imageData length]] forKey:(id)kCGImagePropertyFileSize];

    // Look for container-level metadata if the file is a GIF.
    CFStringRef imageFormat = CGImageSourceGetType(isrc);
    if (imageFormat == kUTTypeGIF) {
        MULTI_QI imageQueryInterface = {0};
        const GUID IID_IWICImagingFactory = {0xec5ec8a9,0xc395,0x4314,0x9c,0x77,0x54,0xd7,0xa9,0x35,0xff,0x70};
        imageQueryInterface.pIID = &IID_IWICImagingFactory;
        RETURN_NULL_IF_FAILED(
            CoCreateInstanceFromApp(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, nullptr, 1, &imageQueryInterface));

        ComPtr<IWICImagingFactory> imageFactory = (IWICImagingFactory*)imageQueryInterface.pItf;
        ComPtr<IWICStream> imageStream;
        RETURN_NULL_IF_FAILED(imageFactory->CreateStream(&imageStream));

        unsigned char* imageByteArray = (unsigned char*)[imageData bytes];
        RETURN_NULL_IF_FAILED(imageStream->InitializeFromMemory(imageByteArray, [imageData length]));

        if (options && CFDictionaryContainsKey(options, kCGImageSourceShouldCache)) {
            UNIMPLEMENTED_WITH_MSG("kCGImageSourceShouldCache is not supported in current implementation.");
        }

        ComPtr<IWICBitmapDecoder> imageDecoder;                
        RETURN_NULL_IF_FAILED(
            imageFactory->CreateDecoderFromStream(imageStream.Get(), nullptr, WICDecodeMetadataCacheOnDemand, &imageDecoder));    
        ComPtr<IWICMetadataQueryReader> imageMetadataReader;
        RETURN_NULL_IF_FAILED(imageDecoder->GetMetadataQueryReader(&imageMetadataReader));

        PROPVARIANT propertyValue;
        PropVariantInit(&propertyValue);
        NSMutableDictionary *gifProperties = [[NSMutableDictionary alloc] init];

        if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/appext/Data", &propertyValue)) &&
            propertyValue.vt == (VT_VECTOR | VT_UI1)) {
            if (propertyValue.caub.pElems[0] == 3 && propertyValue.caub.pElems[1] == 1) {
                NSNumber* loopCount = [NSNumber numberWithInt:propertyValue.caub.pElems[2] + (propertyValue.caub.pElems[3]<<8)];
                [gifProperties setObject:loopCount forKey:(id)kCGImagePropertyGIFLoopCount];
            }
        }

        if ([[gifProperties allKeys] count] != 0) {
            [properties setObject:gifProperties forKey:(id)kCGImagePropertyGIFDictionary];
        }
    }

    return (CFDictionaryRef)properties;
}

/**
 @Status Caveat
 @Notes A limited subset of frame properties are supported currently  
*/
CFDictionaryRef CGImageSourceCopyPropertiesAtIndex(CGImageSourceRef isrc, size_t index, CFDictionaryRef options) {
    RETURN_NULL_IF(!isrc);
    NSData* imageData = ((ImageSource*)isrc).data;
    RETURN_NULL_IF(!imageData);

    MULTI_QI imageQueryInterface = {0};
    const GUID IID_IWICImagingFactory = {0xec5ec8a9,0xc395,0x4314,0x9c,0x77,0x54,0xd7,0xa9,0x35,0xff,0x70};
    imageQueryInterface.pIID = &IID_IWICImagingFactory;
    RETURN_NULL_IF_FAILED(
        CoCreateInstanceFromApp(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, nullptr, 1, &imageQueryInterface));

    ComPtr<IWICImagingFactory> imageFactory = (IWICImagingFactory*)imageQueryInterface.pItf;
    ComPtr<IWICStream> imageStream;
    RETURN_NULL_IF_FAILED(imageFactory->CreateStream(&imageStream));

    unsigned char* imageByteArray = (unsigned char*)[imageData bytes];
    RETURN_NULL_IF_FAILED(imageStream->InitializeFromMemory(imageByteArray, [imageData length]));

    if (options && CFDictionaryContainsKey(options, kCGImageSourceShouldCache)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceShouldCache is not supported in current implementation.");
    }

    ComPtr<IWICBitmapDecoder> imageDecoder;                
    RETURN_NULL_IF_FAILED(
        imageFactory->CreateDecoderFromStream(imageStream.Get(), nullptr, WICDecodeMetadataCacheOnDemand, &imageDecoder));    
    ComPtr<IWICBitmapFrameDecode> imageFrame;
    RETURN_NULL_IF_FAILED(imageDecoder->GetFrame(index, &imageFrame));
    ComPtr<IWICMetadataQueryReader> imageMetadataReader;
    RETURN_NULL_IF_FAILED(imageFrame->GetMetadataQueryReader(&imageMetadataReader));

    CFStringRef imageFormat = CGImageSourceGetType(isrc);
    if (imageFormat == kUTTypeJPEG) {
        return readJPEGProperties(imageMetadataReader.Get());
    } else if (imageFormat == kUTTypeTIFF) {
        return readTIFFProperties(imageMetadataReader.Get());
    } else if (imageFormat == kUTTypeGIF) {
        return readGIFProperties(imageMetadataReader.Get());
    } else if (imageFormat == kUTTypePNG) {
        return readPNGProperties(imageMetadataReader.Get());
    } else {
        return nullptr;
    }
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
