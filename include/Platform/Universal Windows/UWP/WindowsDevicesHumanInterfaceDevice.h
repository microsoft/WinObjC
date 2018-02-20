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

// WindowsDevicesHumanInterfaceDevice.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDEVICESHUMANINTERFACEDEVICEEXPORT
#define OBJCUWPWINDOWSDEVICESHUMANINTERFACEDEVICEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDevicesHumanInterfaceDevice.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDHHidDevice, WDHHidInputReport, WDHHidFeatureReport, WDHHidOutputReport, WDHHidBooleanControlDescription, WDHHidNumericControlDescription, WDHHidInputReportReceivedEventArgs, WDHHidCollection, WDHHidBooleanControl, WDHHidNumericControl;
@protocol WDHIHidDeviceStatics, WDHIHidDevice, WDHIHidBooleanControlDescription, WDHIHidBooleanControlDescription2, WDHIHidNumericControlDescription, WDHIHidCollection, WDHIHidInputReport, WDHIHidOutputReport, WDHIHidFeatureReport, WDHIHidInputReportReceivedEventArgs, WDHIHidBooleanControl, WDHIHidNumericControl;

// Windows.Devices.HumanInterfaceDevice.HidReportType
enum _WDHHidReportType {
    WDHHidReportTypeInput = 0,
    WDHHidReportTypeOutput = 1,
    WDHHidReportTypeFeature = 2,
};
typedef unsigned WDHHidReportType;

// Windows.Devices.HumanInterfaceDevice.HidCollectionType
enum _WDHHidCollectionType {
    WDHHidCollectionTypePhysical = 0,
    WDHHidCollectionTypeApplication = 1,
    WDHHidCollectionTypeLogical = 2,
    WDHHidCollectionTypeReport = 3,
    WDHHidCollectionTypeNamedArray = 4,
    WDHHidCollectionTypeUsageSwitch = 5,
    WDHHidCollectionTypeUsageModifier = 6,
    WDHHidCollectionTypeOther = 7,
};
typedef unsigned WDHHidCollectionType;

#include "WindowsStorage.h"
#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSDEVICESHUMANINTERFACEDEVICEEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.HumanInterfaceDevice.HidDevice
#ifndef __WDHHidDevice_DEFINED__
#define __WDHHidDevice_DEFINED__

OBJCUWPWINDOWSDEVICESHUMANINTERFACEDEVICEEXPORT
@interface WDHHidDevice : RTObject <WFIClosable>
+ (NSString *)getDeviceSelector:(unsigned short)usagePage usageId:(unsigned short)usageId;
+ (NSString *)getDeviceSelectorVidPid:(unsigned short)usagePage usageId:(unsigned short)usageId vendorId:(unsigned short)vendorId productId:(unsigned short)productId;
+ (void)fromIdAsync:(NSString *)deviceId accessMode:(WSFileAccessMode)accessMode success:(void (^)(WDHHidDevice*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned short productId;
@property (readonly) unsigned short usageId;
@property (readonly) unsigned short usagePage;
@property (readonly) unsigned short vendorId;
@property (readonly) unsigned short Version;
- (EventRegistrationToken)addInputReportReceivedEvent:(void(^)(WDHHidDevice*, WDHHidInputReportReceivedEventArgs*))del;
- (void)removeInputReportReceivedEvent:(EventRegistrationToken)tok;
- (void)getInputReportAsyncWithSuccess:(void (^)(WDHHidInputReport*))success failure:(void (^)(NSError*))failure;
- (void)getInputReportByIdAsync:(unsigned short)reportId success:(void (^)(WDHHidInputReport*))success failure:(void (^)(NSError*))failure;
- (void)getFeatureReportAsyncWithSuccess:(void (^)(WDHHidFeatureReport*))success failure:(void (^)(NSError*))failure;
- (void)getFeatureReportByIdAsync:(unsigned short)reportId success:(void (^)(WDHHidFeatureReport*))success failure:(void (^)(NSError*))failure;
- (WDHHidOutputReport*)createOutputReport;
- (WDHHidOutputReport*)createOutputReportById:(unsigned short)reportId;
- (WDHHidFeatureReport*)createFeatureReport;
- (WDHHidFeatureReport*)createFeatureReportById:(unsigned short)reportId;
- (void)sendOutputReportAsync:(WDHHidOutputReport*)outputReport success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (void)sendFeatureReportAsync:(WDHHidFeatureReport*)featureReport success:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (NSArray* /* WDHHidBooleanControlDescription* */)getBooleanControlDescriptions:(WDHHidReportType)reportType usagePage:(unsigned short)usagePage usageId:(unsigned short)usageId;
- (NSArray* /* WDHHidNumericControlDescription* */)getNumericControlDescriptions:(WDHHidReportType)reportType usagePage:(unsigned short)usagePage usageId:(unsigned short)usageId;
- (void)close;
@end

#endif // __WDHHidDevice_DEFINED__

// Windows.Devices.HumanInterfaceDevice.HidInputReport
#ifndef __WDHHidInputReport_DEFINED__
#define __WDHHidInputReport_DEFINED__

OBJCUWPWINDOWSDEVICESHUMANINTERFACEDEVICEEXPORT
@interface WDHHidInputReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WDHHidBooleanControl* */ activatedBooleanControls;
@property (readonly) RTObject<WSSIBuffer>* data;
@property (readonly) unsigned short id;
@property (readonly) NSArray* /* WDHHidBooleanControl* */ transitionedBooleanControls;
- (WDHHidBooleanControl*)getBooleanControl:(unsigned short)usagePage usageId:(unsigned short)usageId;
- (WDHHidBooleanControl*)getBooleanControlByDescription:(WDHHidBooleanControlDescription*)controlDescription;
- (WDHHidNumericControl*)getNumericControl:(unsigned short)usagePage usageId:(unsigned short)usageId;
- (WDHHidNumericControl*)getNumericControlByDescription:(WDHHidNumericControlDescription*)controlDescription;
@end

#endif // __WDHHidInputReport_DEFINED__

// Windows.Devices.HumanInterfaceDevice.HidFeatureReport
#ifndef __WDHHidFeatureReport_DEFINED__
#define __WDHHidFeatureReport_DEFINED__

OBJCUWPWINDOWSDEVICESHUMANINTERFACEDEVICEEXPORT
@interface WDHHidFeatureReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) RTObject<WSSIBuffer>* data;
@property (readonly) unsigned short id;
- (WDHHidBooleanControl*)getBooleanControl:(unsigned short)usagePage usageId:(unsigned short)usageId;
- (WDHHidBooleanControl*)getBooleanControlByDescription:(WDHHidBooleanControlDescription*)controlDescription;
- (WDHHidNumericControl*)getNumericControl:(unsigned short)usagePage usageId:(unsigned short)usageId;
- (WDHHidNumericControl*)getNumericControlByDescription:(WDHHidNumericControlDescription*)controlDescription;
@end

#endif // __WDHHidFeatureReport_DEFINED__

// Windows.Devices.HumanInterfaceDevice.HidOutputReport
#ifndef __WDHHidOutputReport_DEFINED__
#define __WDHHidOutputReport_DEFINED__

OBJCUWPWINDOWSDEVICESHUMANINTERFACEDEVICEEXPORT
@interface WDHHidOutputReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) RTObject<WSSIBuffer>* data;
@property (readonly) unsigned short id;
- (WDHHidBooleanControl*)getBooleanControl:(unsigned short)usagePage usageId:(unsigned short)usageId;
- (WDHHidBooleanControl*)getBooleanControlByDescription:(WDHHidBooleanControlDescription*)controlDescription;
- (WDHHidNumericControl*)getNumericControl:(unsigned short)usagePage usageId:(unsigned short)usageId;
- (WDHHidNumericControl*)getNumericControlByDescription:(WDHHidNumericControlDescription*)controlDescription;
@end

#endif // __WDHHidOutputReport_DEFINED__

// Windows.Devices.HumanInterfaceDevice.HidBooleanControlDescription
#ifndef __WDHHidBooleanControlDescription_DEFINED__
#define __WDHHidBooleanControlDescription_DEFINED__

OBJCUWPWINDOWSDEVICESHUMANINTERFACEDEVICEEXPORT
@interface WDHHidBooleanControlDescription : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int id;
@property (readonly) NSArray* /* WDHHidCollection* */ parentCollections;
@property (readonly) unsigned short reportId;
@property (readonly) WDHHidReportType reportType;
@property (readonly) unsigned short usageId;
@property (readonly) unsigned short usagePage;
@property (readonly) BOOL isAbsolute;
@end

#endif // __WDHHidBooleanControlDescription_DEFINED__

// Windows.Devices.HumanInterfaceDevice.HidNumericControlDescription
#ifndef __WDHHidNumericControlDescription_DEFINED__
#define __WDHHidNumericControlDescription_DEFINED__

OBJCUWPWINDOWSDEVICESHUMANINTERFACEDEVICEEXPORT
@interface WDHHidNumericControlDescription : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL hasNull;
@property (readonly) unsigned int id;
@property (readonly) BOOL isAbsolute;
@property (readonly) int logicalMaximum;
@property (readonly) int logicalMinimum;
@property (readonly) NSArray* /* WDHHidCollection* */ parentCollections;
@property (readonly) int physicalMaximum;
@property (readonly) int physicalMinimum;
@property (readonly) unsigned int reportCount;
@property (readonly) unsigned short reportId;
@property (readonly) unsigned int reportSize;
@property (readonly) WDHHidReportType reportType;
@property (readonly) unsigned int unit;
@property (readonly) unsigned int unitExponent;
@property (readonly) unsigned short usageId;
@property (readonly) unsigned short usagePage;
@end

#endif // __WDHHidNumericControlDescription_DEFINED__

// Windows.Devices.HumanInterfaceDevice.HidInputReportReceivedEventArgs
#ifndef __WDHHidInputReportReceivedEventArgs_DEFINED__
#define __WDHHidInputReportReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESHUMANINTERFACEDEVICEEXPORT
@interface WDHHidInputReportReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDHHidInputReport* report;
@end

#endif // __WDHHidInputReportReceivedEventArgs_DEFINED__

// Windows.Devices.HumanInterfaceDevice.HidCollection
#ifndef __WDHHidCollection_DEFINED__
#define __WDHHidCollection_DEFINED__

OBJCUWPWINDOWSDEVICESHUMANINTERFACEDEVICEEXPORT
@interface WDHHidCollection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int id;
@property (readonly) WDHHidCollectionType type;
@property (readonly) unsigned int usageId;
@property (readonly) unsigned int usagePage;
@end

#endif // __WDHHidCollection_DEFINED__

// Windows.Devices.HumanInterfaceDevice.HidBooleanControl
#ifndef __WDHHidBooleanControl_DEFINED__
#define __WDHHidBooleanControl_DEFINED__

OBJCUWPWINDOWSDEVICESHUMANINTERFACEDEVICEEXPORT
@interface WDHHidBooleanControl : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isActive;
@property (readonly) WDHHidBooleanControlDescription* controlDescription;
@property (readonly) unsigned int id;
@property (readonly) unsigned short usageId;
@property (readonly) unsigned short usagePage;
@end

#endif // __WDHHidBooleanControl_DEFINED__

// Windows.Devices.HumanInterfaceDevice.HidNumericControl
#ifndef __WDHHidNumericControl_DEFINED__
#define __WDHHidNumericControl_DEFINED__

OBJCUWPWINDOWSDEVICESHUMANINTERFACEDEVICEEXPORT
@interface WDHHidNumericControl : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property int64_t value;
@property int64_t scaledValue;
@property (readonly) WDHHidNumericControlDescription* controlDescription;
@property (readonly) unsigned int id;
@property (readonly) BOOL isGrouped;
@property (readonly) unsigned short usageId;
@property (readonly) unsigned short usagePage;
@end

#endif // __WDHHidNumericControl_DEFINED__

