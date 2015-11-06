//******************************************************************************
//
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

// WindowsDevicesScanners.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDSImageScannerAutoConfiguration, WDSImageScannerFlatbedConfiguration, WDSImageScannerFeederConfiguration, WDSImageScannerScanResult,
    WDSImageScannerPreviewResult, WDSImageScanner;
@class WDSImageScannerResolution;
@protocol WDSIImageScannerFormatConfiguration
, WDSIImageScannerSourceConfiguration, WDSIImageScannerFeederConfiguration, WDSIImageScannerScanResult, WDSIImageScannerPreviewResult,
    WDSIImageScanner, WDSIImageScannerStatics;

// Windows.Devices.Scanners.ImageScannerFormat
enum _WDSImageScannerFormat {
    WDSImageScannerFormatJpeg = 0,
    WDSImageScannerFormatPng = 1,
    WDSImageScannerFormatDeviceIndependentBitmap = 2,
    WDSImageScannerFormatTiff = 3,
    WDSImageScannerFormatXps = 4,
    WDSImageScannerFormatOpenXps = 5,
    WDSImageScannerFormatPdf = 6,
};
typedef unsigned WDSImageScannerFormat;

// Windows.Devices.Scanners.ImageScannerAutoCroppingMode
enum _WDSImageScannerAutoCroppingMode {
    WDSImageScannerAutoCroppingModeDisabled = 0,
    WDSImageScannerAutoCroppingModeSingleRegion = 1,
    WDSImageScannerAutoCroppingModeMultipleRegion = 2,
};
typedef unsigned WDSImageScannerAutoCroppingMode;

// Windows.Devices.Scanners.ImageScannerColorMode
enum _WDSImageScannerColorMode {
    WDSImageScannerColorModeColor = 0,
    WDSImageScannerColorModeGrayscale = 1,
    WDSImageScannerColorModeMonochrome = 2,
    WDSImageScannerColorModeAutoColor = 3,
};
typedef unsigned WDSImageScannerColorMode;

// Windows.Devices.Scanners.ImageScannerScanSource
enum _WDSImageScannerScanSource {
    WDSImageScannerScanSourceDefault = 0,
    WDSImageScannerScanSourceFlatbed = 1,
    WDSImageScannerScanSourceFeeder = 2,
    WDSImageScannerScanSourceAutoConfigured = 3,
};
typedef unsigned WDSImageScannerScanSource;

#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
#include "WindowsGraphicsPrinting.h"
#include "WindowsStorage.h"

// [struct] Windows.Devices.Scanners.ImageScannerResolution
WINRT_EXPORT
@interface WDSImageScannerResolution : NSObject
+ (instancetype) new;
@property float dpiX;
@property float dpiY;
@end

// Windows.Devices.Scanners.IImageScannerFormatConfiguration
#ifndef __WDSIImageScannerFormatConfiguration_DEFINED__
#define __WDSIImageScannerFormatConfiguration_DEFINED__

@protocol WDSIImageScannerFormatConfiguration
@property (readonly) WDSImageScannerFormat defaultFormat;
@property WDSImageScannerFormat format;
- (BOOL)isFormatSupported:(WDSImageScannerFormat)value;
@end

#endif // __WDSIImageScannerFormatConfiguration_DEFINED__

// Windows.Devices.Scanners.IImageScannerSourceConfiguration
#ifndef __WDSIImageScannerSourceConfiguration_DEFINED__
#define __WDSIImageScannerSourceConfiguration_DEFINED__

@protocol WDSIImageScannerSourceConfiguration <WDSIImageScannerFormatConfiguration>
@property (readonly) WDSImageScannerResolution* actualResolution;
@property WDSImageScannerAutoCroppingMode autoCroppingMode;
@property int brightness;
@property (readonly) unsigned brightnessStep;
@property WDSImageScannerColorMode colorMode;
@property int contrast;
@property (readonly) unsigned contrastStep;
@property (readonly) int defaultBrightness;
@property (readonly) WDSImageScannerColorMode defaultColorMode;
@property (readonly) int defaultContrast;
@property (copy) WDSImageScannerResolution* desiredResolution;
@property (readonly) int maxBrightness;
@property (readonly) int maxContrast;
@property (readonly) WDSImageScannerResolution* maxResolution;
@property (readonly) WFSize* maxScanArea;
@property (readonly) int minBrightness;
@property (readonly) int minContrast;
@property (readonly) WDSImageScannerResolution* minResolution;
@property (readonly) WFSize* minScanArea;
@property (readonly) WDSImageScannerResolution* opticalResolution;
@property (copy) WFRect* selectedScanRegion;
- (BOOL)isAutoCroppingModeSupported:(WDSImageScannerAutoCroppingMode)value;
- (BOOL)isColorModeSupported:(WDSImageScannerColorMode)value;
- (BOOL)isFormatSupported:(WDSImageScannerFormat)value;
@end

#endif // __WDSIImageScannerSourceConfiguration_DEFINED__

// Windows.Devices.Scanners.ImageScannerAutoConfiguration
#ifndef __WDSImageScannerAutoConfiguration_DEFINED__
#define __WDSImageScannerAutoConfiguration_DEFINED__

WINRT_EXPORT
@interface WDSImageScannerAutoConfiguration : RTObject <WDSIImageScannerFormatConfiguration>
@property WDSImageScannerFormat format;
@property (readonly) WDSImageScannerFormat defaultFormat;
- (BOOL)isFormatSupported:(WDSImageScannerFormat)value;
@end

#endif // __WDSImageScannerAutoConfiguration_DEFINED__

// Windows.Devices.Scanners.ImageScannerFlatbedConfiguration
#ifndef __WDSImageScannerFlatbedConfiguration_DEFINED__
#define __WDSImageScannerFlatbedConfiguration_DEFINED__

WINRT_EXPORT
@interface WDSImageScannerFlatbedConfiguration : RTObject <WDSIImageScannerFormatConfiguration, WDSIImageScannerSourceConfiguration>
@property WDSImageScannerFormat format;
@property (readonly) WDSImageScannerFormat defaultFormat;
@property (copy) WFRect* selectedScanRegion;
@property (copy) WDSImageScannerResolution* desiredResolution;
@property int contrast;
@property WDSImageScannerColorMode colorMode;
@property int brightness;
@property WDSImageScannerAutoCroppingMode autoCroppingMode;
@property (readonly) WDSImageScannerResolution* actualResolution;
@property (readonly) unsigned brightnessStep;
@property (readonly) unsigned contrastStep;
@property (readonly) int defaultBrightness;
@property (readonly) WDSImageScannerColorMode defaultColorMode;
@property (readonly) int defaultContrast;
@property (readonly) int maxBrightness;
@property (readonly) int maxContrast;
@property (readonly) WDSImageScannerResolution* maxResolution;
@property (readonly) WFSize* maxScanArea;
@property (readonly) int minBrightness;
@property (readonly) int minContrast;
@property (readonly) WDSImageScannerResolution* minResolution;
@property (readonly) WFSize* minScanArea;
@property (readonly) WDSImageScannerResolution* opticalResolution;
- (BOOL)isFormatSupported:(WDSImageScannerFormat)value;
- (BOOL)isAutoCroppingModeSupported:(WDSImageScannerAutoCroppingMode)value;
- (BOOL)isColorModeSupported:(WDSImageScannerColorMode)value;
@end

#endif // __WDSImageScannerFlatbedConfiguration_DEFINED__

// Windows.Devices.Scanners.ImageScannerFeederConfiguration
#ifndef __WDSImageScannerFeederConfiguration_DEFINED__
#define __WDSImageScannerFeederConfiguration_DEFINED__

WINRT_EXPORT
@interface WDSImageScannerFeederConfiguration : RTObject <WDSIImageScannerFormatConfiguration, WDSIImageScannerSourceConfiguration>
@property unsigned maxNumberOfPages;
@property WGPPrintOrientation pageOrientation;
@property WGPPrintMediaSize pageSize;
@property BOOL autoDetectPageSize;
@property BOOL duplex;
@property BOOL scanAhead;
@property (readonly) BOOL canScanDuplex;
@property (readonly) BOOL canScanAhead;
@property (readonly) BOOL canAutoDetectPageSize;
@property (readonly) WFSize* pageSizeDimensions;
@property WDSImageScannerFormat format;
@property (readonly) WDSImageScannerFormat defaultFormat;
@property int contrast;
@property (copy) WDSImageScannerResolution* desiredResolution;
@property (copy) WFRect* selectedScanRegion;
@property WDSImageScannerColorMode colorMode;
@property int brightness;
@property WDSImageScannerAutoCroppingMode autoCroppingMode;
@property (readonly) WDSImageScannerResolution* actualResolution;
@property (readonly) unsigned brightnessStep;
@property (readonly) int minBrightness;
@property (readonly) int minContrast;
@property (readonly) WDSImageScannerResolution* minResolution;
@property (readonly) WFSize* minScanArea;
@property (readonly) WDSImageScannerResolution* opticalResolution;
@property (readonly) WDSImageScannerResolution* maxResolution;
@property (readonly) int maxContrast;
@property (readonly) int maxBrightness;
@property (readonly) int defaultContrast;
@property (readonly) WDSImageScannerColorMode defaultColorMode;
@property (readonly) int defaultBrightness;
@property (readonly) unsigned contrastStep;
@property (readonly) WFSize* maxScanArea;
- (BOOL)isFormatSupported:(WDSImageScannerFormat)value;
- (BOOL)isAutoCroppingModeSupported:(WDSImageScannerAutoCroppingMode)value;
- (BOOL)isColorModeSupported:(WDSImageScannerColorMode)value;
- (BOOL)isPageSizeSupported:(WGPPrintMediaSize)pageSize pageOrientation:(WGPPrintOrientation)pageOrientation;
@end

#endif // __WDSImageScannerFeederConfiguration_DEFINED__

// Windows.Devices.Scanners.ImageScannerScanResult
#ifndef __WDSImageScannerScanResult_DEFINED__
#define __WDSImageScannerScanResult_DEFINED__

WINRT_EXPORT
@interface WDSImageScannerScanResult : RTObject
@property (readonly) id<NSFastEnumeration> /*WSStorageFile*/ scannedFiles;
@end

#endif // __WDSImageScannerScanResult_DEFINED__

// Windows.Devices.Scanners.ImageScannerPreviewResult
#ifndef __WDSImageScannerPreviewResult_DEFINED__
#define __WDSImageScannerPreviewResult_DEFINED__

WINRT_EXPORT
@interface WDSImageScannerPreviewResult : RTObject
@property (readonly) WDSImageScannerFormat format;
@property (readonly) BOOL succeeded;
@end

#endif // __WDSImageScannerPreviewResult_DEFINED__

// Windows.Devices.Scanners.ImageScanner
#ifndef __WDSImageScanner_DEFINED__
#define __WDSImageScanner_DEFINED__

WINRT_EXPORT
@interface WDSImageScanner : RTObject
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDSImageScanner*))success failure:(void (^)(NSError*))failure;
+ (NSString*)getDeviceSelector;
@property (readonly) WDSImageScannerAutoConfiguration* autoConfiguration;
@property (readonly) WDSImageScannerScanSource defaultScanSource;
@property (readonly) NSString* deviceId;
@property (readonly) WDSImageScannerFeederConfiguration* feederConfiguration;
@property (readonly) WDSImageScannerFlatbedConfiguration* flatbedConfiguration;
- (BOOL)isScanSourceSupported:(WDSImageScannerScanSource)value;
- (BOOL)isPreviewSupported:(WDSImageScannerScanSource)scanSource;
- (void)scanPreviewToStreamAsync:(WDSImageScannerScanSource)scanSource
                    targetStream:(RTObject<WSSIRandomAccessStream>*)targetStream
                         success:(void (^)(WDSImageScannerPreviewResult*))success
                         failure:(void (^)(NSError*))failure;
- (void)scanFilesToFolderAsync:(WDSImageScannerScanSource)scanSource
                 storageFolder:(WSStorageFolder*)storageFolder
                       success:(void (^)(WDSImageScannerScanResult*))success
                      progress:(void (^)(unsigned))progress
                       failure:(void (^)(NSError*))failure;
@end

#endif // __WDSImageScanner_DEFINED__
