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

// WindowsDevicesScanners.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDEVICESSCANNERSEXPORT
#define OBJCUWPWINDOWSDEVICESSCANNERSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDevicesScanners.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDSImageScannerAutoConfiguration, WDSImageScannerFlatbedConfiguration, WDSImageScannerFeederConfiguration, WDSImageScannerScanResult, WDSImageScannerPreviewResult, WDSImageScanner;
@class WDSImageScannerResolution;
@protocol WDSIImageScannerFormatConfiguration, WDSIImageScannerSourceConfiguration, WDSIImageScannerFeederConfiguration, WDSIImageScannerScanResult, WDSIImageScannerPreviewResult, WDSIImageScanner, WDSIImageScannerStatics;

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
#include "WindowsFoundation.h"
#include "WindowsGraphicsPrinting.h"
#include "WindowsStorage.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Devices.Scanners.ImageScannerResolution
OBJCUWPWINDOWSDEVICESSCANNERSEXPORT
@interface WDSImageScannerResolution : NSObject
+ (instancetype)new;
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

OBJCUWPWINDOWSDEVICESSCANNERSEXPORT
@interface WDSIImageScannerFormatConfiguration : RTObject <WDSIImageScannerFormatConfiguration>
@end

#endif // __WDSIImageScannerFormatConfiguration_DEFINED__

// Windows.Devices.Scanners.IImageScannerSourceConfiguration
#ifndef __WDSIImageScannerSourceConfiguration_DEFINED__
#define __WDSIImageScannerSourceConfiguration_DEFINED__

@protocol WDSIImageScannerSourceConfiguration <WDSIImageScannerFormatConfiguration>
@property (readonly) WDSImageScannerResolution* actualResolution;
@property WDSImageScannerAutoCroppingMode autoCroppingMode;
@property int brightness;
@property (readonly) unsigned int brightnessStep;
@property WDSImageScannerColorMode colorMode;
@property int contrast;
@property (readonly) unsigned int contrastStep;
@property (readonly) int defaultBrightness;
@property (readonly) WDSImageScannerColorMode defaultColorMode;
@property (readonly) int defaultContrast;
@property (retain) WDSImageScannerResolution* desiredResolution;
@property (readonly) int maxBrightness;
@property (readonly) int maxContrast;
@property (readonly) WDSImageScannerResolution* maxResolution;
@property (readonly) WFSize* maxScanArea;
@property (readonly) int minBrightness;
@property (readonly) int minContrast;
@property (readonly) WDSImageScannerResolution* minResolution;
@property (readonly) WFSize* minScanArea;
@property (readonly) WDSImageScannerResolution* opticalResolution;
@property (retain) WFRect* selectedScanRegion;
- (BOOL)isAutoCroppingModeSupported:(WDSImageScannerAutoCroppingMode)value;
- (BOOL)isColorModeSupported:(WDSImageScannerColorMode)value;
- (BOOL)isFormatSupported:(WDSImageScannerFormat)value;
@end

OBJCUWPWINDOWSDEVICESSCANNERSEXPORT
@interface WDSIImageScannerSourceConfiguration : RTObject <WDSIImageScannerSourceConfiguration>
@end

#endif // __WDSIImageScannerSourceConfiguration_DEFINED__

// Windows.Devices.Scanners.ImageScannerAutoConfiguration
#ifndef __WDSImageScannerAutoConfiguration_DEFINED__
#define __WDSImageScannerAutoConfiguration_DEFINED__

OBJCUWPWINDOWSDEVICESSCANNERSEXPORT
@interface WDSImageScannerAutoConfiguration : RTObject <WDSIImageScannerFormatConfiguration>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WDSImageScannerFormat format;
@property (readonly) WDSImageScannerFormat defaultFormat;
- (BOOL)isFormatSupported:(WDSImageScannerFormat)value;
@end

#endif // __WDSImageScannerAutoConfiguration_DEFINED__

// Windows.Devices.Scanners.ImageScannerFlatbedConfiguration
#ifndef __WDSImageScannerFlatbedConfiguration_DEFINED__
#define __WDSImageScannerFlatbedConfiguration_DEFINED__

OBJCUWPWINDOWSDEVICESSCANNERSEXPORT
@interface WDSImageScannerFlatbedConfiguration : RTObject <WDSIImageScannerFormatConfiguration, WDSIImageScannerSourceConfiguration>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WDSImageScannerFormat format;
@property (readonly) WDSImageScannerFormat defaultFormat;
@property (retain) WFRect* selectedScanRegion;
@property (retain) WDSImageScannerResolution* desiredResolution;
@property int contrast;
@property int brightness;
@property WDSImageScannerAutoCroppingMode autoCroppingMode;
@property WDSImageScannerColorMode colorMode;
@property (readonly) unsigned int contrastStep;
@property (readonly) int defaultBrightness;
@property (readonly) WDSImageScannerColorMode defaultColorMode;
@property (readonly) int defaultContrast;
@property (readonly) WDSImageScannerResolution* actualResolution;
@property (readonly) int maxBrightness;
@property (readonly) int maxContrast;
@property (readonly) WDSImageScannerResolution* maxResolution;
@property (readonly) WFSize* maxScanArea;
@property (readonly) int minBrightness;
@property (readonly) unsigned int brightnessStep;
@property (readonly) int minContrast;
@property (readonly) WDSImageScannerResolution* minResolution;
@property (readonly) WDSImageScannerResolution* opticalResolution;
@property (readonly) WFSize* minScanArea;
- (BOOL)isFormatSupported:(WDSImageScannerFormat)value;
- (BOOL)isAutoCroppingModeSupported:(WDSImageScannerAutoCroppingMode)value;
- (BOOL)isColorModeSupported:(WDSImageScannerColorMode)value;
@end

#endif // __WDSImageScannerFlatbedConfiguration_DEFINED__

// Windows.Devices.Scanners.ImageScannerFeederConfiguration
#ifndef __WDSImageScannerFeederConfiguration_DEFINED__
#define __WDSImageScannerFeederConfiguration_DEFINED__

OBJCUWPWINDOWSDEVICESSCANNERSEXPORT
@interface WDSImageScannerFeederConfiguration : RTObject <WDSIImageScannerFormatConfiguration, WDSIImageScannerSourceConfiguration>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL scanAhead;
@property BOOL autoDetectPageSize;
@property BOOL duplex;
@property unsigned int maxNumberOfPages;
@property WGPPrintOrientation pageOrientation;
@property WGPPrintMediaSize pageSize;
@property (readonly) WFSize* pageSizeDimensions;
@property (readonly) BOOL canScanDuplex;
@property (readonly) BOOL canScanAhead;
@property (readonly) BOOL canAutoDetectPageSize;
@property WDSImageScannerFormat format;
@property (readonly) WDSImageScannerFormat defaultFormat;
@property (retain) WDSImageScannerResolution* desiredResolution;
@property int contrast;
@property WDSImageScannerColorMode colorMode;
@property WDSImageScannerAutoCroppingMode autoCroppingMode;
@property int brightness;
@property (retain) WFRect* selectedScanRegion;
@property (readonly) int minBrightness;
@property (readonly) int minContrast;
@property (readonly) WDSImageScannerResolution* minResolution;
@property (readonly) WFSize* minScanArea;
@property (readonly) WDSImageScannerResolution* opticalResolution;
@property (readonly) WFSize* maxScanArea;
@property (readonly) WDSImageScannerResolution* maxResolution;
@property (readonly) int maxContrast;
@property (readonly) int maxBrightness;
@property (readonly) int defaultContrast;
@property (readonly) WDSImageScannerColorMode defaultColorMode;
@property (readonly) int defaultBrightness;
@property (readonly) unsigned int contrastStep;
@property (readonly) unsigned int brightnessStep;
@property (readonly) WDSImageScannerResolution* actualResolution;
- (BOOL)isFormatSupported:(WDSImageScannerFormat)value;
- (BOOL)isAutoCroppingModeSupported:(WDSImageScannerAutoCroppingMode)value;
- (BOOL)isColorModeSupported:(WDSImageScannerColorMode)value;
- (BOOL)isPageSizeSupported:(WGPPrintMediaSize)pageSize pageOrientation:(WGPPrintOrientation)pageOrientation;
@end

#endif // __WDSImageScannerFeederConfiguration_DEFINED__

// Windows.Devices.Scanners.ImageScannerScanResult
#ifndef __WDSImageScannerScanResult_DEFINED__
#define __WDSImageScannerScanResult_DEFINED__

OBJCUWPWINDOWSDEVICESSCANNERSEXPORT
@interface WDSImageScannerScanResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WSStorageFile* */ scannedFiles;
@end

#endif // __WDSImageScannerScanResult_DEFINED__

// Windows.Devices.Scanners.ImageScannerPreviewResult
#ifndef __WDSImageScannerPreviewResult_DEFINED__
#define __WDSImageScannerPreviewResult_DEFINED__

OBJCUWPWINDOWSDEVICESSCANNERSEXPORT
@interface WDSImageScannerPreviewResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSImageScannerFormat format;
@property (readonly) BOOL succeeded;
@end

#endif // __WDSImageScannerPreviewResult_DEFINED__

// Windows.Devices.Scanners.ImageScanner
#ifndef __WDSImageScanner_DEFINED__
#define __WDSImageScanner_DEFINED__

OBJCUWPWINDOWSDEVICESSCANNERSEXPORT
@interface WDSImageScanner : RTObject
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDSImageScanner*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDSImageScannerAutoConfiguration* autoConfiguration;
@property (readonly) WDSImageScannerScanSource defaultScanSource;
@property (readonly) NSString * deviceId;
@property (readonly) WDSImageScannerFeederConfiguration* feederConfiguration;
@property (readonly) WDSImageScannerFlatbedConfiguration* flatbedConfiguration;
- (BOOL)isScanSourceSupported:(WDSImageScannerScanSource)value;
- (BOOL)isPreviewSupported:(WDSImageScannerScanSource)scanSource;
- (void)scanPreviewToStreamAsync:(WDSImageScannerScanSource)scanSource targetStream:(RTObject<WSSIRandomAccessStream>*)targetStream success:(void (^)(WDSImageScannerPreviewResult*))success failure:(void (^)(NSError*))failure;
- (void)scanFilesToFolderAsync:(WDSImageScannerScanSource)scanSource storageFolder:(WSStorageFolder*)storageFolder success:(void (^)(WDSImageScannerScanResult*))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
@end

#endif // __WDSImageScanner_DEFINED__

