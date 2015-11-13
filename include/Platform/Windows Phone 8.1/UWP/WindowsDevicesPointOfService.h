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

// WindowsDevicesPointOfService.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDPUnifiedPosErrorData, WDPBarcodeScannerStatusUpdatedEventArgs, WDPBarcodeSymbologies, WDPBarcodeScannerReport,
    WDPBarcodeScannerDataReceivedEventArgs, WDPBarcodeScannerErrorOccurredEventArgs, WDPBarcodeScannerImagePreviewReceivedEventArgs,
    WDPBarcodeScannerCapabilities, WDPBarcodeScanner, WDPClaimedBarcodeScanner, WDPMagneticStripeReaderEncryptionAlgorithms,
    WDPMagneticStripeReaderCardTypes, WDPMagneticStripeReaderTrackData, WDPMagneticStripeReaderReport,
    WDPMagneticStripeReaderBankCardDataReceivedEventArgs, WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs,
    WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs, WDPMagneticStripeReaderErrorOccurredEventArgs,
    WDPMagneticStripeReaderStatusUpdatedEventArgs, WDPMagneticStripeReaderCapabilities, WDPClaimedMagneticStripeReader,
    WDPMagneticStripeReader;
@protocol WDPIUnifiedPosErrorData
, WDPIBarcodeScannerStatusUpdatedEventArgs, WDPIBarcodeSymbologiesStatics, WDPIBarcodeScannerDataReceivedEventArgs,
    WDPIBarcodeScannerReport, WDPIBarcodeScannerErrorOccurredEventArgs, WDPIBarcodeScannerImagePreviewReceivedEventArgs,
    WDPIBarcodeScannerCapabilities, WDPIBarcodeScannerStatics, WDPIBarcodeScanner, WDPIMagneticStripeReaderEncryptionAlgorithmsStatics,
    WDPIMagneticStripeReaderCardTypesStatics, WDPIMagneticStripeReaderTrackData, WDPIMagneticStripeReaderReport,
    WDPIMagneticStripeReaderBankCardDataReceivedEventArgs, WDPIMagneticStripeReaderAamvaCardDataReceivedEventArgs,
    WDPIMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs, WDPIMagneticStripeReaderErrorOccurredEventArgs,
    WDPIMagneticStripeReaderStatusUpdatedEventArgs, WDPIMagneticStripeReaderCapabilities, WDPIMagneticStripeReaderStatics,
    WDPIMagneticStripeReader, WDPIClaimedBarcodeScanner, WDPIClaimedMagneticStripeReader;

// Windows.Devices.PointOfService.UnifiedPosErrorSeverity
enum _WDPUnifiedPosErrorSeverity {
    WDPUnifiedPosErrorSeverityUnknownErrorSeverity = 0,
    WDPUnifiedPosErrorSeverityWarning = 1,
    WDPUnifiedPosErrorSeverityRecoverable = 2,
    WDPUnifiedPosErrorSeverityUnrecoverable = 3,
    WDPUnifiedPosErrorSeverityAssistanceRequired = 4,
    WDPUnifiedPosErrorSeverityFatal = 5,
};
typedef unsigned WDPUnifiedPosErrorSeverity;

// Windows.Devices.PointOfService.UnifiedPosPowerReportingType
enum _WDPUnifiedPosPowerReportingType {
    WDPUnifiedPosPowerReportingTypeUnknownPowerReportingType = 0,
    WDPUnifiedPosPowerReportingTypeStandard = 1,
    WDPUnifiedPosPowerReportingTypeAdvanced = 2,
};
typedef unsigned WDPUnifiedPosPowerReportingType;

// Windows.Devices.PointOfService.UnifiedPosHealthCheckLevel
enum _WDPUnifiedPosHealthCheckLevel {
    WDPUnifiedPosHealthCheckLevelUnknownHealthCheckLevel = 0,
    WDPUnifiedPosHealthCheckLevelPOSInternal = 1,
    WDPUnifiedPosHealthCheckLevelExternal = 2,
    WDPUnifiedPosHealthCheckLevelInteractive = 3,
};
typedef unsigned WDPUnifiedPosHealthCheckLevel;

// Windows.Devices.PointOfService.UnifiedPosErrorReason
enum _WDPUnifiedPosErrorReason {
    WDPUnifiedPosErrorReasonUnknownErrorReason = 0,
    WDPUnifiedPosErrorReasonNoService = 1,
    WDPUnifiedPosErrorReasonDisabled = 2,
    WDPUnifiedPosErrorReasonIllegal = 3,
    WDPUnifiedPosErrorReasonNoHardware = 4,
    WDPUnifiedPosErrorReasonClosed = 5,
    WDPUnifiedPosErrorReasonOffline = 6,
    WDPUnifiedPosErrorReasonFailure = 7,
    WDPUnifiedPosErrorReasonTimeout = 8,
    WDPUnifiedPosErrorReasonBusy = 9,
    WDPUnifiedPosErrorReasonExtended = 10,
};
typedef unsigned WDPUnifiedPosErrorReason;

// Windows.Devices.PointOfService.MagneticStripeReaderAuthenticationLevel
enum _WDPMagneticStripeReaderAuthenticationLevel {
    WDPMagneticStripeReaderAuthenticationLevelNotSupported = 0,
    WDPMagneticStripeReaderAuthenticationLevelOptional = 1,
    WDPMagneticStripeReaderAuthenticationLevelRequired = 2,
};
typedef unsigned WDPMagneticStripeReaderAuthenticationLevel;

// Windows.Devices.PointOfService.BarcodeScannerStatus
enum _WDPBarcodeScannerStatus {
    WDPBarcodeScannerStatusOnline = 0,
    WDPBarcodeScannerStatusOff = 1,
    WDPBarcodeScannerStatusOffline = 2,
    WDPBarcodeScannerStatusOffOrOffline = 3,
    WDPBarcodeScannerStatusExtended = 4,
};
typedef unsigned WDPBarcodeScannerStatus;

// Windows.Devices.PointOfService.MagneticStripeReaderStatus
enum _WDPMagneticStripeReaderStatus {
    WDPMagneticStripeReaderStatusUnauthenticated = 0,
    WDPMagneticStripeReaderStatusAuthenticated = 1,
    WDPMagneticStripeReaderStatusExtended = 2,
};
typedef unsigned WDPMagneticStripeReaderStatus;

// Windows.Devices.PointOfService.MagneticStripeReaderAuthenticationProtocol
enum _WDPMagneticStripeReaderAuthenticationProtocol {
    WDPMagneticStripeReaderAuthenticationProtocolNone = 0,
    WDPMagneticStripeReaderAuthenticationProtocolChallengeResponse = 1,
};
typedef unsigned WDPMagneticStripeReaderAuthenticationProtocol;

// Windows.Devices.PointOfService.MagneticStripeReaderTrackIds
enum _WDPMagneticStripeReaderTrackIds {
    WDPMagneticStripeReaderTrackIdsNone = 0,
    WDPMagneticStripeReaderTrackIdsTrack1 = 1,
    WDPMagneticStripeReaderTrackIdsTrack2 = 2,
    WDPMagneticStripeReaderTrackIdsTrack3 = 4,
    WDPMagneticStripeReaderTrackIdsTrack4 = 8,
};
typedef unsigned WDPMagneticStripeReaderTrackIds;

// Windows.Devices.PointOfService.MagneticStripeReaderErrorReportingType
enum _WDPMagneticStripeReaderErrorReportingType {
    WDPMagneticStripeReaderErrorReportingTypeCardLevel = 0,
    WDPMagneticStripeReaderErrorReportingTypeTrackLevel = 1,
};
typedef unsigned WDPMagneticStripeReaderErrorReportingType;

// Windows.Devices.PointOfService.MagneticStripeReaderTrackErrorType
enum _WDPMagneticStripeReaderTrackErrorType {
    WDPMagneticStripeReaderTrackErrorTypeNone = 0,
    WDPMagneticStripeReaderTrackErrorTypeStartSentinelError = 1,
    WDPMagneticStripeReaderTrackErrorTypeEndSentinelError = 2,
    WDPMagneticStripeReaderTrackErrorTypeParityError = 3,
    WDPMagneticStripeReaderTrackErrorTypeLrcError = 4,
    WDPMagneticStripeReaderTrackErrorTypeUnknown = -1,
};
typedef unsigned WDPMagneticStripeReaderTrackErrorType;

#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"

// Windows.Devices.PointOfService.UnifiedPosErrorData
#ifndef __WDPUnifiedPosErrorData_DEFINED__
#define __WDPUnifiedPosErrorData_DEFINED__

WINRT_EXPORT
@interface WDPUnifiedPosErrorData : RTObject
@property (readonly) unsigned extendedReason;
@property (readonly) NSString* message;
@property (readonly) WDPUnifiedPosErrorReason reason;
@property (readonly) WDPUnifiedPosErrorSeverity severity;
@end

#endif // __WDPUnifiedPosErrorData_DEFINED__

// Windows.Devices.PointOfService.BarcodeScannerStatusUpdatedEventArgs
#ifndef __WDPBarcodeScannerStatusUpdatedEventArgs_DEFINED__
#define __WDPBarcodeScannerStatusUpdatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPBarcodeScannerStatusUpdatedEventArgs : RTObject
@property (readonly) unsigned extendedStatus;
@property (readonly) WDPBarcodeScannerStatus status;
@end

#endif // __WDPBarcodeScannerStatusUpdatedEventArgs_DEFINED__

// Windows.Devices.PointOfService.BarcodeSymbologies
#ifndef __WDPBarcodeSymbologies_DEFINED__
#define __WDPBarcodeSymbologies_DEFINED__

WINRT_EXPORT
@interface WDPBarcodeSymbologies : RTObject
+ (NSString*)getName:(unsigned)scanDataType;
+ (unsigned)ausPost;
+ (unsigned)aztec;
+ (unsigned)canPost;
+ (unsigned)ccab;
+ (unsigned)ccc;
+ (unsigned)chinaPost;
+ (unsigned)codabar;
+ (unsigned)codablock128;
+ (unsigned)codablockA;
+ (unsigned)codablockF;
+ (unsigned)code11;
+ (unsigned)code128;
+ (unsigned)code16k;
+ (unsigned)code32;
+ (unsigned)code39;
+ (unsigned)code39Ex;
+ (unsigned)code49;
+ (unsigned)code93;
+ (unsigned)code93Ex;
+ (unsigned)dataCode;
+ (unsigned)dataMatrix;
+ (unsigned)dutchKix;
+ (unsigned)ean13;
+ (unsigned)ean13Add2;
+ (unsigned)ean13Add5;
+ (unsigned)ean8;
+ (unsigned)ean8Add2;
+ (unsigned)ean8Add5;
+ (unsigned)ean99;
+ (unsigned)ean99Add2;
+ (unsigned)ean99Add5;
+ (unsigned)eanv;
+ (unsigned)eanvAdd2;
+ (unsigned)eanvAdd5;
+ (unsigned)extendedBase;
+ (unsigned)gs1128;
+ (unsigned)gs1128Coupon;
+ (unsigned)gs1DatabarType1;
+ (unsigned)gs1DatabarType2;
+ (unsigned)gs1DatabarType3;
+ (unsigned)hanXin;
+ (unsigned)infoMail;
+ (unsigned)isbn;
+ (unsigned)isbnAdd5;
+ (unsigned)isbt;
+ (unsigned)ismn;
+ (unsigned)ismnAdd2;
+ (unsigned)ismnAdd5;
+ (unsigned)issn;
+ (unsigned)issnAdd2;
+ (unsigned)issnAdd5;
+ (unsigned)italianPost25;
+ (unsigned)italianPost39;
+ (unsigned)japanPost;
+ (unsigned)koreanPost;
+ (unsigned)maxicode;
+ (unsigned)micr;
+ (unsigned)microPdf417;
+ (unsigned)microQr;
+ (unsigned)msTag;
+ (unsigned)msi;
+ (unsigned)ocrA;
+ (unsigned)ocrB;
+ (unsigned)pdf417;
+ (unsigned)plessey;
+ (unsigned)pzn;
+ (unsigned)qr;
+ (unsigned)sisac;
+ (unsigned)swedenPost;
+ (unsigned)telepen;
+ (unsigned)tfDis;
+ (unsigned)tfIata;
+ (unsigned)tfInd;
+ (unsigned)tfInt;
+ (unsigned)tfMat;
+ (unsigned)tfStd;
+ (unsigned)tlc39;
+ (unsigned)trioptic39;
+ (unsigned)uccEan128;
+ (unsigned)ukPost;
+ (unsigned)unknown;
+ (unsigned)upcCoupon;
+ (unsigned)upca;
+ (unsigned)upcaAdd2;
+ (unsigned)upcaAdd5;
+ (unsigned)upce;
+ (unsigned)upceAdd2;
+ (unsigned)upceAdd5;
+ (unsigned)us4StateFics;
+ (unsigned)usIntelligent;
+ (unsigned)usIntelligentPkg;
+ (unsigned)usPlanet;
+ (unsigned)usPostNet;
@end

#endif // __WDPBarcodeSymbologies_DEFINED__

// Windows.Devices.PointOfService.BarcodeScannerReport
#ifndef __WDPBarcodeScannerReport_DEFINED__
#define __WDPBarcodeScannerReport_DEFINED__

WINRT_EXPORT
@interface WDPBarcodeScannerReport : RTObject
@property (readonly) RTObject<WSSIBuffer>* scanData;
@property (readonly) RTObject<WSSIBuffer>* scanDataLabel;
@property (readonly) unsigned scanDataType;
@end

#endif // __WDPBarcodeScannerReport_DEFINED__

// Windows.Devices.PointOfService.BarcodeScannerDataReceivedEventArgs
#ifndef __WDPBarcodeScannerDataReceivedEventArgs_DEFINED__
#define __WDPBarcodeScannerDataReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPBarcodeScannerDataReceivedEventArgs : RTObject
@property (readonly) WDPBarcodeScannerReport* report;
@end

#endif // __WDPBarcodeScannerDataReceivedEventArgs_DEFINED__

// Windows.Devices.PointOfService.BarcodeScannerErrorOccurredEventArgs
#ifndef __WDPBarcodeScannerErrorOccurredEventArgs_DEFINED__
#define __WDPBarcodeScannerErrorOccurredEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPBarcodeScannerErrorOccurredEventArgs : RTObject
@property (readonly) WDPUnifiedPosErrorData* errorData;
@property (readonly) BOOL isRetriable;
@property (readonly) WDPBarcodeScannerReport* partialInputData;
@end

#endif // __WDPBarcodeScannerErrorOccurredEventArgs_DEFINED__

// Windows.Devices.PointOfService.BarcodeScannerImagePreviewReceivedEventArgs
#ifndef __WDPBarcodeScannerImagePreviewReceivedEventArgs_DEFINED__
#define __WDPBarcodeScannerImagePreviewReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPBarcodeScannerImagePreviewReceivedEventArgs : RTObject
@property (readonly) RTObject<WSSIRandomAccessStreamWithContentType>* preview;
@end

#endif // __WDPBarcodeScannerImagePreviewReceivedEventArgs_DEFINED__

// Windows.Devices.PointOfService.BarcodeScannerCapabilities
#ifndef __WDPBarcodeScannerCapabilities_DEFINED__
#define __WDPBarcodeScannerCapabilities_DEFINED__

WINRT_EXPORT
@interface WDPBarcodeScannerCapabilities : RTObject
@property (readonly) BOOL isImagePreviewSupported;
@property (readonly) BOOL isStatisticsReportingSupported;
@property (readonly) BOOL isStatisticsUpdatingSupported;
@property (readonly) WDPUnifiedPosPowerReportingType powerReportingType;
@end

#endif // __WDPBarcodeScannerCapabilities_DEFINED__

// Windows.Devices.PointOfService.BarcodeScanner
#ifndef __WDPBarcodeScanner_DEFINED__
#define __WDPBarcodeScanner_DEFINED__

WINRT_EXPORT
@interface WDPBarcodeScanner : RTObject
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPBarcodeScanner*))success failure:(void (^)(NSError*))failure;
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDPBarcodeScanner*))success failure:(void (^)(NSError*))failure;
+ (NSString*)getDeviceSelector;
@property (readonly) WDPBarcodeScannerCapabilities* capabilities;
@property (readonly) NSString* deviceId;
- (EventRegistrationToken)addStatusUpdatedEvent:(void (^)(WDPBarcodeScanner*, WDPBarcodeScannerStatusUpdatedEventArgs*))del;
- (void)removeStatusUpdatedEvent:(EventRegistrationToken)tok;
- (void)claimScannerAsyncWithSuccess:(void (^)(WDPClaimedBarcodeScanner*))success failure:(void (^)(NSError*))failure;
- (void)checkHealthAsync:(WDPUnifiedPosHealthCheckLevel)level success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
- (void)getSupportedSymbologiesAsyncWithSuccess:(void (^)(id<NSFastEnumeration> /*UInt32*/))success failure:(void (^)(NSError*))failure;
- (void)isSymbologySupportedAsync:(unsigned)barcodeSymbology success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)retrieveStatisticsAsync:(id<NSFastEnumeration> /*String*/)statisticsCategories
                        success:(void (^)(RTObject<WSSIBuffer>*))success
                        failure:(void (^)(NSError*))failure;
- (id<NSFastEnumeration> /*String*/)getSupportedProfiles;
- (BOOL)isProfileSupported:(NSString*)profile;
@end

#endif // __WDPBarcodeScanner_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.PointOfService.ClaimedBarcodeScanner
#ifndef __WDPClaimedBarcodeScanner_DEFINED__
#define __WDPClaimedBarcodeScanner_DEFINED__

WINRT_EXPORT
@interface WDPClaimedBarcodeScanner : RTObject <WFIClosable>
@property BOOL isDisabledOnDataReceived;
@property BOOL isDecodeDataEnabled;
@property (readonly) NSString* deviceId;
@property (readonly) BOOL isEnabled;
- (EventRegistrationToken)addDataReceivedEvent:(void (^)(WDPClaimedBarcodeScanner*, WDPBarcodeScannerDataReceivedEventArgs*))del;
- (void)removeDataReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addErrorOccurredEvent:(void (^)(WDPClaimedBarcodeScanner*, WDPBarcodeScannerErrorOccurredEventArgs*))del;
- (void)removeErrorOccurredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addImagePreviewReceivedEvent:(void (^)(WDPClaimedBarcodeScanner*,
                                                                 WDPBarcodeScannerImagePreviewReceivedEventArgs*))del;
- (void)removeImagePreviewReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addReleaseDeviceRequestedEvent:(void (^)(RTObject*, WDPClaimedBarcodeScanner*))del;
- (void)removeReleaseDeviceRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTriggerPressedEvent:(void (^)(RTObject*, WDPClaimedBarcodeScanner*))del;
- (void)removeTriggerPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTriggerReleasedEvent:(void (^)(RTObject*, WDPClaimedBarcodeScanner*))del;
- (void)removeTriggerReleasedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)enableAsync;
- (RTObject<WFIAsyncAction>*)disableAsync;
- (void)retainDevice;
- (RTObject<WFIAsyncAction>*)setActiveSymbologiesAsync:(id<NSFastEnumeration> /*UInt32*/)symbologies;
- (RTObject<WFIAsyncAction>*)resetStatisticsAsync:(id<NSFastEnumeration> /*String*/)statisticsCategories;
// Failed to generate member UpdateStatisticsAsync (Can't marshal Windows.Foundation.Collections.IKeyValuePair`2<String,String>)
- (RTObject<WFIAsyncAction>*)setActiveProfileAsync:(NSString*)profile;
- (void)close;
@end

#endif // __WDPClaimedBarcodeScanner_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderEncryptionAlgorithms
#ifndef __WDPMagneticStripeReaderEncryptionAlgorithms_DEFINED__
#define __WDPMagneticStripeReaderEncryptionAlgorithms_DEFINED__

WINRT_EXPORT
@interface WDPMagneticStripeReaderEncryptionAlgorithms : RTObject
+ (unsigned)extendedBase;
+ (unsigned)none;
+ (unsigned)tripleDesDukpt;
@end

#endif // __WDPMagneticStripeReaderEncryptionAlgorithms_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderCardTypes
#ifndef __WDPMagneticStripeReaderCardTypes_DEFINED__
#define __WDPMagneticStripeReaderCardTypes_DEFINED__

WINRT_EXPORT
@interface WDPMagneticStripeReaderCardTypes : RTObject
+ (unsigned)aamva;
+ (unsigned)bank;
+ (unsigned)extendedBase;
+ (unsigned)unknown;
@end

#endif // __WDPMagneticStripeReaderCardTypes_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderTrackData
#ifndef __WDPMagneticStripeReaderTrackData_DEFINED__
#define __WDPMagneticStripeReaderTrackData_DEFINED__

WINRT_EXPORT
@interface WDPMagneticStripeReaderTrackData : RTObject
@property (readonly) RTObject<WSSIBuffer>* data;
@property (readonly) RTObject<WSSIBuffer>* discretionaryData;
@property (readonly) RTObject<WSSIBuffer>* encryptedData;
@end

#endif // __WDPMagneticStripeReaderTrackData_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderReport
#ifndef __WDPMagneticStripeReaderReport_DEFINED__
#define __WDPMagneticStripeReaderReport_DEFINED__

WINRT_EXPORT
@interface WDPMagneticStripeReaderReport : RTObject
@property (readonly) RTObject<WSSIBuffer>* additionalSecurityInformation;
@property (readonly) RTObject<WSSIBuffer>* cardAuthenticationData;
@property (readonly) unsigned cardAuthenticationDataLength;
@property (readonly) unsigned cardType;
@property (readonly) NSDictionary* /*String, String*/ properties;
@property (readonly) WDPMagneticStripeReaderTrackData* track1;
@property (readonly) WDPMagneticStripeReaderTrackData* track2;
@property (readonly) WDPMagneticStripeReaderTrackData* track3;
@property (readonly) WDPMagneticStripeReaderTrackData* track4;
@end

#endif // __WDPMagneticStripeReaderReport_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderBankCardDataReceivedEventArgs
#ifndef __WDPMagneticStripeReaderBankCardDataReceivedEventArgs_DEFINED__
#define __WDPMagneticStripeReaderBankCardDataReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPMagneticStripeReaderBankCardDataReceivedEventArgs : RTObject
@property (readonly) NSString* accountNumber;
@property (readonly) NSString* expirationDate;
@property (readonly) NSString* firstName;
@property (readonly) NSString* middleInitial;
@property (readonly) WDPMagneticStripeReaderReport* report;
@property (readonly) NSString* serviceCode;
@property (readonly) NSString* suffix;
@property (readonly) NSString* surname;
@property (readonly) NSString* title;
@end

#endif // __WDPMagneticStripeReaderBankCardDataReceivedEventArgs_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderAamvaCardDataReceivedEventArgs
#ifndef __WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs_DEFINED__
#define __WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs : RTObject
@property (readonly) NSString* address;
@property (readonly) NSString* birthDate;
@property (readonly) NSString* city;
@property (readonly) NSString* Class;
@property (readonly) NSString* endorsements;
@property (readonly) NSString* expirationDate;
@property (readonly) NSString* eyeColor;
@property (readonly) NSString* firstName;
@property (readonly) NSString* gender;
@property (readonly) NSString* hairColor;
@property (readonly) NSString* height;
@property (readonly) NSString* licenseNumber;
@property (readonly) NSString* postalCode;
@property (readonly) WDPMagneticStripeReaderReport* report;
@property (readonly) NSString* restrictions;
@property (readonly) NSString* state;
@property (readonly) NSString* suffix;
@property (readonly) NSString* surname;
@property (readonly) NSString* weight;
@end

#endif // __WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs
#ifndef __WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs_DEFINED__
#define __WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs : RTObject
@property (readonly) WDPMagneticStripeReaderReport* report;
@end

#endif // __WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderErrorOccurredEventArgs
#ifndef __WDPMagneticStripeReaderErrorOccurredEventArgs_DEFINED__
#define __WDPMagneticStripeReaderErrorOccurredEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPMagneticStripeReaderErrorOccurredEventArgs : RTObject
@property (readonly) WDPUnifiedPosErrorData* errorData;
@property (readonly) WDPMagneticStripeReaderReport* partialInputData;
@property (readonly) WDPMagneticStripeReaderTrackErrorType track1Status;
@property (readonly) WDPMagneticStripeReaderTrackErrorType track2Status;
@property (readonly) WDPMagneticStripeReaderTrackErrorType track3Status;
@property (readonly) WDPMagneticStripeReaderTrackErrorType track4Status;
@end

#endif // __WDPMagneticStripeReaderErrorOccurredEventArgs_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderStatusUpdatedEventArgs
#ifndef __WDPMagneticStripeReaderStatusUpdatedEventArgs_DEFINED__
#define __WDPMagneticStripeReaderStatusUpdatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPMagneticStripeReaderStatusUpdatedEventArgs : RTObject
@property (readonly) unsigned extendedStatus;
@property (readonly) WDPMagneticStripeReaderStatus status;
@end

#endif // __WDPMagneticStripeReaderStatusUpdatedEventArgs_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderCapabilities
#ifndef __WDPMagneticStripeReaderCapabilities_DEFINED__
#define __WDPMagneticStripeReaderCapabilities_DEFINED__

WINRT_EXPORT
@interface WDPMagneticStripeReaderCapabilities : RTObject
@property (readonly) WDPMagneticStripeReaderAuthenticationLevel authenticationLevel;
@property (readonly) NSString* cardAuthentication;
@property (readonly) BOOL isIsoSupported;
@property (readonly) BOOL isJisOneSupported;
@property (readonly) BOOL isJisTwoSupported;
@property (readonly) BOOL isStatisticsReportingSupported;
@property (readonly) BOOL isStatisticsUpdatingSupported;
@property (readonly) BOOL isTrackDataMaskingSupported;
@property (readonly) BOOL isTransmitSentinelsSupported;
@property (readonly) WDPUnifiedPosPowerReportingType powerReportingType;
@property (readonly) unsigned supportedEncryptionAlgorithms;
@end

#endif // __WDPMagneticStripeReaderCapabilities_DEFINED__

// Windows.Devices.PointOfService.ClaimedMagneticStripeReader
#ifndef __WDPClaimedMagneticStripeReader_DEFINED__
#define __WDPClaimedMagneticStripeReader_DEFINED__

WINRT_EXPORT
@interface WDPClaimedMagneticStripeReader : RTObject <WFIClosable>
@property WDPMagneticStripeReaderTrackIds tracksToRead;
@property BOOL isTransmitSentinelsEnabled;
@property BOOL isDisabledOnDataReceived;
@property BOOL isDecodeDataEnabled;
@property unsigned dataEncryptionAlgorithm;
@property (readonly) NSString* deviceId;
@property (readonly) BOOL isDeviceAuthenticated;
@property (readonly) BOOL isEnabled;
- (EventRegistrationToken)addAamvaCardDataReceivedEvent:(void (^)(WDPClaimedMagneticStripeReader*,
                                                                  WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs*))del;
- (void)removeAamvaCardDataReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBankCardDataReceivedEvent:(void (^)(WDPClaimedMagneticStripeReader*,
                                                                 WDPMagneticStripeReaderBankCardDataReceivedEventArgs*))del;
- (void)removeBankCardDataReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addErrorOccurredEvent:(void (^)(WDPClaimedMagneticStripeReader*,
                                                          WDPMagneticStripeReaderErrorOccurredEventArgs*))del;
- (void)removeErrorOccurredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addReleaseDeviceRequestedEvent:(void (^)(RTObject*, WDPClaimedMagneticStripeReader*))del;
- (void)removeReleaseDeviceRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVendorSpecificDataReceivedEvent:(void (^)(WDPClaimedMagneticStripeReader*,
                                                                       WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs*))del;
- (void)removeVendorSpecificDataReceivedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)enableAsync;
- (RTObject<WFIAsyncAction>*)disableAsync;
- (void)retainDevice;
- (void)setErrorReportingType:(WDPMagneticStripeReaderErrorReportingType)value;
- (void)retrieveDeviceAuthenticationDataAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)authenticateDeviceAsync:(id<NSFastEnumeration> /*UInt8*/)responseToken;
- (RTObject<WFIAsyncAction>*)deAuthenticateDeviceAsync:(id<NSFastEnumeration> /*UInt8*/)responseToken;
- (RTObject<WFIAsyncAction>*)updateKeyAsync:(NSString*)key keyName:(NSString*)keyName;
- (RTObject<WFIAsyncAction>*)resetStatisticsAsync:(id<NSFastEnumeration> /*String*/)statisticsCategories;
// Failed to generate member UpdateStatisticsAsync (Can't marshal Windows.Foundation.Collections.IKeyValuePair`2<String,String>)
- (void)close;
@end

#endif // __WDPClaimedMagneticStripeReader_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReader
#ifndef __WDPMagneticStripeReader_DEFINED__
#define __WDPMagneticStripeReader_DEFINED__

WINRT_EXPORT
@interface WDPMagneticStripeReader : RTObject
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPMagneticStripeReader*))success failure:(void (^)(NSError*))failure;
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDPMagneticStripeReader*))success failure:(void (^)(NSError*))failure;
+ (NSString*)getDeviceSelector;
@property (readonly) WDPMagneticStripeReaderCapabilities* capabilities;
@property (readonly) WDPMagneticStripeReaderAuthenticationProtocol deviceAuthenticationProtocol;
@property (readonly) NSString* deviceId;
@property (readonly) id<NSFastEnumeration> /*UInt32*/ supportedCardTypes;
- (EventRegistrationToken)addStatusUpdatedEvent:(void (^)(WDPMagneticStripeReader*, WDPMagneticStripeReaderStatusUpdatedEventArgs*))del;
- (void)removeStatusUpdatedEvent:(EventRegistrationToken)tok;
- (void)checkHealthAsync:(WDPUnifiedPosHealthCheckLevel)level success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
- (void)claimReaderAsyncWithSuccess:(void (^)(WDPClaimedMagneticStripeReader*))success failure:(void (^)(NSError*))failure;
- (void)retrieveStatisticsAsync:(id<NSFastEnumeration> /*String*/)statisticsCategories
                        success:(void (^)(RTObject<WSSIBuffer>*))success
                        failure:(void (^)(NSError*))failure;
- (WDPMagneticStripeReaderErrorReportingType)getErrorReportingType;
@end

#endif // __WDPMagneticStripeReader_DEFINED__
