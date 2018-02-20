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

// WindowsGraphicsDisplayCore.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGRAPHICSDISPLAYCOREEXPORT
#define OBJCUWPWINDOWSGRAPHICSDISPLAYCOREEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGraphicsDisplayCore.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGDCHdmiDisplayMode, WGDCHdmiDisplayInformation;
@class WGDCHdmiDisplayHdr2086Metadata;
@protocol WGDCIHdmiDisplayMode, WGDCIHdmiDisplayInformationStatics, WGDCIHdmiDisplayInformation;

// Windows.Graphics.Display.Core.HdmiDisplayColorSpace
enum _WGDCHdmiDisplayColorSpace {
    WGDCHdmiDisplayColorSpaceRgbLimited = 0,
    WGDCHdmiDisplayColorSpaceRgbFull = 1,
    WGDCHdmiDisplayColorSpaceBT2020 = 2,
    WGDCHdmiDisplayColorSpaceBT709 = 3,
};
typedef unsigned WGDCHdmiDisplayColorSpace;

// Windows.Graphics.Display.Core.HdmiDisplayPixelEncoding
enum _WGDCHdmiDisplayPixelEncoding {
    WGDCHdmiDisplayPixelEncodingRgb444 = 0,
    WGDCHdmiDisplayPixelEncodingYcc444 = 1,
    WGDCHdmiDisplayPixelEncodingYcc422 = 2,
    WGDCHdmiDisplayPixelEncodingYcc420 = 3,
};
typedef unsigned WGDCHdmiDisplayPixelEncoding;

// Windows.Graphics.Display.Core.HdmiDisplayHdrOption
enum _WGDCHdmiDisplayHdrOption {
    WGDCHdmiDisplayHdrOptionNone = 0,
    WGDCHdmiDisplayHdrOptionEotfSdr = 1,
    WGDCHdmiDisplayHdrOptionEotf2084 = 2,
};
typedef unsigned WGDCHdmiDisplayHdrOption;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Graphics.Display.Core.HdmiDisplayHdr2086Metadata
OBJCUWPWINDOWSGRAPHICSDISPLAYCOREEXPORT
@interface WGDCHdmiDisplayHdr2086Metadata : NSObject
+ (instancetype)new;
@property unsigned short redPrimaryX;
@property unsigned short redPrimaryY;
@property unsigned short greenPrimaryX;
@property unsigned short greenPrimaryY;
@property unsigned short bluePrimaryX;
@property unsigned short bluePrimaryY;
@property unsigned short whitePointX;
@property unsigned short whitePointY;
@property unsigned short maxMasteringLuminance;
@property unsigned short minMasteringLuminance;
@property unsigned short maxContentLightLevel;
@property unsigned short maxFrameAverageLightLevel;
@end

// Windows.Graphics.Display.Core.HdmiDisplayMode
#ifndef __WGDCHdmiDisplayMode_DEFINED__
#define __WGDCHdmiDisplayMode_DEFINED__

OBJCUWPWINDOWSGRAPHICSDISPLAYCOREEXPORT
@interface WGDCHdmiDisplayMode : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned short bitsPerPixel;
@property (readonly) WGDCHdmiDisplayColorSpace colorSpace;
@property (readonly) BOOL is2086MetadataSupported;
@property (readonly) BOOL isSdrLuminanceSupported;
@property (readonly) BOOL isSmpte2084Supported;
@property (readonly) WGDCHdmiDisplayPixelEncoding pixelEncoding;
@property (readonly) double refreshRate;
@property (readonly) unsigned int resolutionHeightInRawPixels;
@property (readonly) unsigned int resolutionWidthInRawPixels;
@property (readonly) BOOL stereoEnabled;
- (BOOL)IsEqual:(WGDCHdmiDisplayMode*)mode;
@end

#endif // __WGDCHdmiDisplayMode_DEFINED__

// Windows.Graphics.Display.Core.HdmiDisplayInformation
#ifndef __WGDCHdmiDisplayInformation_DEFINED__
#define __WGDCHdmiDisplayInformation_DEFINED__

OBJCUWPWINDOWSGRAPHICSDISPLAYCOREEXPORT
@interface WGDCHdmiDisplayInformation : RTObject
+ (WGDCHdmiDisplayInformation*)getForCurrentView;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addDisplayModesChangedEvent:(void(^)(WGDCHdmiDisplayInformation*, RTObject*))del;
- (void)removeDisplayModesChangedEvent:(EventRegistrationToken)tok;
- (NSArray* /* WGDCHdmiDisplayMode* */)getSupportedDisplayModes;
- (WGDCHdmiDisplayMode*)getCurrentDisplayMode;
- (RTObject<WFIAsyncAction>*)setDefaultDisplayModeAsync;
- (void)requestSetCurrentDisplayModeAsync:(WGDCHdmiDisplayMode*)mode success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestSetCurrentDisplayModeWithHdrAsync:(WGDCHdmiDisplayMode*)mode hdrOption:(WGDCHdmiDisplayHdrOption)hdrOption success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestSetCurrentDisplayModeWithHdrAndMetadataAsync:(WGDCHdmiDisplayMode*)mode hdrOption:(WGDCHdmiDisplayHdrOption)hdrOption hdrMetadata:(WGDCHdmiDisplayHdr2086Metadata*)hdrMetadata success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WGDCHdmiDisplayInformation_DEFINED__

