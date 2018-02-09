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

// WindowsSystemProfile.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSSYSTEMPROFILEEXPORT
#define OBJCUWPWINDOWSSYSTEMPROFILEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsSystemProfile.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSPSystemIdentificationInfo, WSPSystemIdentification, WSPAnalyticsVersionInfo, WSPAnalyticsInfo, WSPEducationSettings, WSPPlatformDiagnosticsAndUsageDataSettings, WSPHardwareToken, WSPHardwareIdentification, WSPRetailInfo, WSPKnownRetailInfoProperties, WSPSharedModeSettings;
@protocol WSPISystemIdentificationInfo, WSPISystemIdentificationStatics, WSPIAnalyticsInfoStatics, WSPIAnalyticsVersionInfo, WSPIEducationSettingsStatics, WSPIPlatformDiagnosticsAndUsageDataSettingsStatics, WSPIHardwareToken, WSPIHardwareIdentificationStatics, WSPIRetailInfoStatics, WSPIKnownRetailInfoPropertiesStatics, WSPISharedModeSettingsStatics, WSPISharedModeSettingsStatics2;

// Windows.System.Profile.SystemIdentificationSource
enum _WSPSystemIdentificationSource {
    WSPSystemIdentificationSourceNone = 0,
    WSPSystemIdentificationSourceTpm = 1,
    WSPSystemIdentificationSourceUefi = 2,
    WSPSystemIdentificationSourceRegistry = 3,
};
typedef unsigned WSPSystemIdentificationSource;

// Windows.System.Profile.PlatformDataCollectionLevel
enum _WSPPlatformDataCollectionLevel {
    WSPPlatformDataCollectionLevelSecurity = 0,
    WSPPlatformDataCollectionLevelBasic = 1,
    WSPPlatformDataCollectionLevelEnhanced = 2,
    WSPPlatformDataCollectionLevelFull = 3,
};
typedef unsigned WSPPlatformDataCollectionLevel;

#include "WindowsStorageStreams.h"
#include "WindowsSystem.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.System.Profile.SystemIdentificationInfo
#ifndef __WSPSystemIdentificationInfo_DEFINED__
#define __WSPSystemIdentificationInfo_DEFINED__

OBJCUWPWINDOWSSYSTEMPROFILEEXPORT
@interface WSPSystemIdentificationInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIBuffer>* id;
@property (readonly) WSPSystemIdentificationSource source;
@end

#endif // __WSPSystemIdentificationInfo_DEFINED__

// Windows.System.Profile.SystemIdentification
#ifndef __WSPSystemIdentification_DEFINED__
#define __WSPSystemIdentification_DEFINED__

OBJCUWPWINDOWSSYSTEMPROFILEEXPORT
@interface WSPSystemIdentification : RTObject
+ (WSPSystemIdentificationInfo*)getSystemIdForPublisher;
+ (WSPSystemIdentificationInfo*)getSystemIdForUser:(WSUser*)user;
@end

#endif // __WSPSystemIdentification_DEFINED__

// Windows.System.Profile.AnalyticsVersionInfo
#ifndef __WSPAnalyticsVersionInfo_DEFINED__
#define __WSPAnalyticsVersionInfo_DEFINED__

OBJCUWPWINDOWSSYSTEMPROFILEEXPORT
@interface WSPAnalyticsVersionInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * deviceFamily;
@property (readonly) NSString * deviceFamilyVersion;
@end

#endif // __WSPAnalyticsVersionInfo_DEFINED__

// Windows.System.Profile.AnalyticsInfo
#ifndef __WSPAnalyticsInfo_DEFINED__
#define __WSPAnalyticsInfo_DEFINED__

OBJCUWPWINDOWSSYSTEMPROFILEEXPORT
@interface WSPAnalyticsInfo : RTObject
+ (NSString *)deviceForm;
+ (WSPAnalyticsVersionInfo*)versionInfo;
@end

#endif // __WSPAnalyticsInfo_DEFINED__

// Windows.System.Profile.EducationSettings
#ifndef __WSPEducationSettings_DEFINED__
#define __WSPEducationSettings_DEFINED__

OBJCUWPWINDOWSSYSTEMPROFILEEXPORT
@interface WSPEducationSettings : RTObject
+ (BOOL)isEducationEnvironment;
@end

#endif // __WSPEducationSettings_DEFINED__

// Windows.System.Profile.PlatformDiagnosticsAndUsageDataSettings
#ifndef __WSPPlatformDiagnosticsAndUsageDataSettings_DEFINED__
#define __WSPPlatformDiagnosticsAndUsageDataSettings_DEFINED__

OBJCUWPWINDOWSSYSTEMPROFILEEXPORT
@interface WSPPlatformDiagnosticsAndUsageDataSettings : RTObject
+ (BOOL)canCollectDiagnostics:(WSPPlatformDataCollectionLevel)level;
+ (WSPPlatformDataCollectionLevel)collectionLevel;
+ (EventRegistrationToken)addCollectionLevelChangedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeCollectionLevelChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WSPPlatformDiagnosticsAndUsageDataSettings_DEFINED__

// Windows.System.Profile.HardwareToken
#ifndef __WSPHardwareToken_DEFINED__
#define __WSPHardwareToken_DEFINED__

OBJCUWPWINDOWSSYSTEMPROFILEEXPORT
@interface WSPHardwareToken : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIBuffer>* certificate;
@property (readonly) RTObject<WSSIBuffer>* id;
@property (readonly) RTObject<WSSIBuffer>* signature;
@end

#endif // __WSPHardwareToken_DEFINED__

// Windows.System.Profile.HardwareIdentification
#ifndef __WSPHardwareIdentification_DEFINED__
#define __WSPHardwareIdentification_DEFINED__

OBJCUWPWINDOWSSYSTEMPROFILEEXPORT
@interface WSPHardwareIdentification : RTObject
+ (WSPHardwareToken*)getPackageSpecificToken:(RTObject<WSSIBuffer>*)nonce;
@end

#endif // __WSPHardwareIdentification_DEFINED__

// Windows.System.Profile.RetailInfo
#ifndef __WSPRetailInfo_DEFINED__
#define __WSPRetailInfo_DEFINED__

OBJCUWPWINDOWSSYSTEMPROFILEEXPORT
@interface WSPRetailInfo : RTObject
+ (BOOL)isDemoModeEnabled;
+ (NSDictionary* /* NSString *, RTObject* */)properties;
@end

#endif // __WSPRetailInfo_DEFINED__

// Windows.System.Profile.KnownRetailInfoProperties
#ifndef __WSPKnownRetailInfoProperties_DEFINED__
#define __WSPKnownRetailInfoProperties_DEFINED__

OBJCUWPWINDOWSSYSTEMPROFILEEXPORT
@interface WSPKnownRetailInfoProperties : RTObject
+ (NSString *)batteryLifeDescription;
+ (NSString *)displayDescription;
+ (NSString *)displayModelName;
+ (NSString *)formFactor;
+ (NSString *)frontCameraDescription;
+ (NSString *)graphicsDescription;
+ (NSString *)hasNfc;
+ (NSString *)hasOpticalDrive;
+ (NSString *)hasSdSlot;
+ (NSString *)isFeatured;
+ (NSString *)isOfficeInstalled;
+ (NSString *)manufacturerName;
+ (NSString *)memory;
+ (NSString *)modelName;
+ (NSString *)price;
+ (NSString *)processorDescription;
+ (NSString *)rearCameraDescription;
+ (NSString *)retailAccessCode;
+ (NSString *)screenSize;
+ (NSString *)storageDescription;
+ (NSString *)weight;
+ (NSString *)windowsEdition;
@end

#endif // __WSPKnownRetailInfoProperties_DEFINED__

// Windows.System.Profile.SharedModeSettings
#ifndef __WSPSharedModeSettings_DEFINED__
#define __WSPSharedModeSettings_DEFINED__

OBJCUWPWINDOWSSYSTEMPROFILEEXPORT
@interface WSPSharedModeSettings : RTObject
+ (BOOL)isEnabled;
+ (BOOL)shouldAvoidLocalStorage;
@end

#endif // __WSPSharedModeSettings_DEFINED__

