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
@class WDPUnifiedPosErrorData, WDPBarcodeScannerStatusUpdatedEventArgs, WDPBarcodeSymbologies, WDPBarcodeScannerReport, WDPBarcodeScannerDataReceivedEventArgs, WDPBarcodeScannerErrorOccurredEventArgs, WDPBarcodeScannerImagePreviewReceivedEventArgs, WDPBarcodeScannerCapabilities, WDPBarcodeScanner, WDPClaimedBarcodeScanner, WDPMagneticStripeReaderEncryptionAlgorithms, WDPMagneticStripeReaderCardTypes, WDPMagneticStripeReaderTrackData, WDPMagneticStripeReaderReport, WDPMagneticStripeReaderBankCardDataReceivedEventArgs, WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs, WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs, WDPMagneticStripeReaderErrorOccurredEventArgs, WDPMagneticStripeReaderStatusUpdatedEventArgs, WDPMagneticStripeReaderCapabilities, WDPClaimedMagneticStripeReader, WDPMagneticStripeReader, WDPPosPrinterCharacterSetIds, WDPReceiptPrinterCapabilities, WDPSlipPrinterCapabilities, WDPJournalPrinterCapabilities, WDPPosPrinterCapabilities, WDPPosPrinterStatus, WDPPosPrinterStatusUpdatedEventArgs, WDPPosPrinterReleaseDeviceRequestedEventArgs, WDPPosPrinter, WDPClaimedPosPrinter, WDPReceiptPrintJob, WDPSlipPrintJob, WDPJournalPrintJob, WDPClaimedReceiptPrinter, WDPClaimedSlipPrinter, WDPClaimedJournalPrinter, WDPCashDrawerStatus, WDPCashDrawerStatusUpdatedEventArgs, WDPCashDrawerCapabilities, WDPCashDrawer, WDPCashDrawerClosedEventArgs, WDPCashDrawerOpenedEventArgs, WDPCashDrawerEventSource, WDPClaimedCashDrawer, WDPCashDrawerCloseAlarm;
@protocol WDPIUnifiedPosErrorData, WDPIBarcodeScannerStatusUpdatedEventArgs, WDPIBarcodeSymbologiesStatics, WDPIBarcodeScannerDataReceivedEventArgs, WDPIBarcodeScannerReport, WDPIBarcodeScannerErrorOccurredEventArgs, WDPIBarcodeScannerImagePreviewReceivedEventArgs, WDPIBarcodeScannerCapabilities, WDPIBarcodeScannerCapabilities1, WDPIBarcodeScannerStatics, WDPIBarcodeScanner, WDPIMagneticStripeReaderEncryptionAlgorithmsStatics, WDPIMagneticStripeReaderCardTypesStatics, WDPIMagneticStripeReaderTrackData, WDPIMagneticStripeReaderReport, WDPIMagneticStripeReaderBankCardDataReceivedEventArgs, WDPIMagneticStripeReaderAamvaCardDataReceivedEventArgs, WDPIMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs, WDPIMagneticStripeReaderErrorOccurredEventArgs, WDPIMagneticStripeReaderStatusUpdatedEventArgs, WDPIMagneticStripeReaderCapabilities, WDPIMagneticStripeReaderStatics, WDPIMagneticStripeReader, WDPIPosPrinterCharacterSetIdsStatics, WDPICommonPosPrintStationCapabilities, WDPICommonReceiptSlipCapabilities, WDPIReceiptPrinterCapabilities, WDPISlipPrinterCapabilities, WDPIJournalPrinterCapabilities, WDPIPosPrinterCapabilities, WDPIPosPrinterStatus, WDPIPosPrinterStatusUpdatedEventArgs, WDPIPosPrinterReleaseDeviceRequestedEventArgs, WDPIPosPrinterStatics, WDPIPosPrinter, WDPIPosPrinterJob, WDPIReceiptOrSlipJob, WDPIReceiptPrintJob, WDPICommonClaimedPosPrinterStation, WDPIClaimedReceiptPrinter, WDPIClaimedSlipPrinter, WDPIClaimedJournalPrinter, WDPICashDrawerStatusUpdatedEventArgs, WDPICashDrawerStatus, WDPICashDrawerCapabilities, WDPICashDrawerEventSourceEventArgs, WDPICashDrawerEventSource, WDPICashDrawerStatics, WDPICashDrawer, WDPICashDrawerCloseAlarm, WDPIClaimedBarcodeScanner, WDPIClaimedBarcodeScanner1, WDPIClaimedMagneticStripeReader, WDPIClaimedPosPrinter, WDPIClaimedCashDrawer;

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

// Windows.Devices.PointOfService.PosPrinterMapMode
enum _WDPPosPrinterMapMode {
    WDPPosPrinterMapModeDots = 0,
    WDPPosPrinterMapModeTwips = 1,
    WDPPosPrinterMapModeEnglish = 2,
    WDPPosPrinterMapModeMetric = 3,
};
typedef unsigned WDPPosPrinterMapMode;

// Windows.Devices.PointOfService.PosPrinterCartridgeSensors
enum _WDPPosPrinterCartridgeSensors {
    WDPPosPrinterCartridgeSensorsNone = 0,
    WDPPosPrinterCartridgeSensorsRemoved = 1,
    WDPPosPrinterCartridgeSensorsEmpty = 2,
    WDPPosPrinterCartridgeSensorsHeadCleaning = 4,
    WDPPosPrinterCartridgeSensorsNearEnd = 8,
};
typedef unsigned WDPPosPrinterCartridgeSensors;

// Windows.Devices.PointOfService.PosPrinterColorCapabilities
enum _WDPPosPrinterColorCapabilities {
    WDPPosPrinterColorCapabilitiesNone = 0,
    WDPPosPrinterColorCapabilitiesPrimary = 1,
    WDPPosPrinterColorCapabilitiesCustom1 = 2,
    WDPPosPrinterColorCapabilitiesCustom2 = 4,
    WDPPosPrinterColorCapabilitiesCustom3 = 8,
    WDPPosPrinterColorCapabilitiesCustom4 = 16,
    WDPPosPrinterColorCapabilitiesCustom5 = 32,
    WDPPosPrinterColorCapabilitiesCustom6 = 64,
    WDPPosPrinterColorCapabilitiesCyan = 128,
    WDPPosPrinterColorCapabilitiesMagenta = 256,
    WDPPosPrinterColorCapabilitiesYellow = 512,
    WDPPosPrinterColorCapabilitiesFull = 1024,
};
typedef unsigned WDPPosPrinterColorCapabilities;

// Windows.Devices.PointOfService.PosPrinterColorCartridge
enum _WDPPosPrinterColorCartridge {
    WDPPosPrinterColorCartridgeUnknown = 0,
    WDPPosPrinterColorCartridgePrimary = 1,
    WDPPosPrinterColorCartridgeCustom1 = 2,
    WDPPosPrinterColorCartridgeCustom2 = 3,
    WDPPosPrinterColorCartridgeCustom3 = 4,
    WDPPosPrinterColorCartridgeCustom4 = 5,
    WDPPosPrinterColorCartridgeCustom5 = 6,
    WDPPosPrinterColorCartridgeCustom6 = 7,
    WDPPosPrinterColorCartridgeCyan = 8,
    WDPPosPrinterColorCartridgeMagenta = 9,
    WDPPosPrinterColorCartridgeYellow = 10,
};
typedef unsigned WDPPosPrinterColorCartridge;

// Windows.Devices.PointOfService.PosPrinterMarkFeedCapabilities
enum _WDPPosPrinterMarkFeedCapabilities {
    WDPPosPrinterMarkFeedCapabilitiesNone = 0,
    WDPPosPrinterMarkFeedCapabilitiesToTakeUp = 1,
    WDPPosPrinterMarkFeedCapabilitiesToCutter = 2,
    WDPPosPrinterMarkFeedCapabilitiesToCurrentTopOfForm = 4,
    WDPPosPrinterMarkFeedCapabilitiesToNextTopOfForm = 8,
};
typedef unsigned WDPPosPrinterMarkFeedCapabilities;

// Windows.Devices.PointOfService.PosPrinterRuledLineCapabilities
enum _WDPPosPrinterRuledLineCapabilities {
    WDPPosPrinterRuledLineCapabilitiesNone = 0,
    WDPPosPrinterRuledLineCapabilitiesHorizontal = 1,
    WDPPosPrinterRuledLineCapabilitiesVertical = 2,
};
typedef unsigned WDPPosPrinterRuledLineCapabilities;

// Windows.Devices.PointOfService.PosPrinterPrintSide
enum _WDPPosPrinterPrintSide {
    WDPPosPrinterPrintSideUnknown = 0,
    WDPPosPrinterPrintSideSide1 = 1,
    WDPPosPrinterPrintSideSide2 = 2,
};
typedef unsigned WDPPosPrinterPrintSide;

// Windows.Devices.PointOfService.PosPrinterLineDirection
enum _WDPPosPrinterLineDirection {
    WDPPosPrinterLineDirectionHorizontal = 0,
    WDPPosPrinterLineDirectionVertical = 1,
};
typedef unsigned WDPPosPrinterLineDirection;

// Windows.Devices.PointOfService.PosPrinterLineStyle
enum _WDPPosPrinterLineStyle {
    WDPPosPrinterLineStyleSingleSolid = 0,
    WDPPosPrinterLineStyleDoubleSolid = 1,
    WDPPosPrinterLineStyleBroken = 2,
    WDPPosPrinterLineStyleChain = 3,
};
typedef unsigned WDPPosPrinterLineStyle;

// Windows.Devices.PointOfService.PosPrinterMarkFeedKind
enum _WDPPosPrinterMarkFeedKind {
    WDPPosPrinterMarkFeedKindToTakeUp = 0,
    WDPPosPrinterMarkFeedKindToCutter = 1,
    WDPPosPrinterMarkFeedKindToCurrentTopOfForm = 2,
    WDPPosPrinterMarkFeedKindToNextTopOfForm = 3,
};
typedef unsigned WDPPosPrinterMarkFeedKind;

// Windows.Devices.PointOfService.PosPrinterAlignment
enum _WDPPosPrinterAlignment {
    WDPPosPrinterAlignmentLeft = 0,
    WDPPosPrinterAlignmentCenter = 1,
    WDPPosPrinterAlignmentRight = 2,
};
typedef unsigned WDPPosPrinterAlignment;

// Windows.Devices.PointOfService.PosPrinterBarcodeTextPosition
enum _WDPPosPrinterBarcodeTextPosition {
    WDPPosPrinterBarcodeTextPositionNone = 0,
    WDPPosPrinterBarcodeTextPositionAbove = 1,
    WDPPosPrinterBarcodeTextPositionBelow = 2,
};
typedef unsigned WDPPosPrinterBarcodeTextPosition;

// Windows.Devices.PointOfService.PosPrinterRotation
enum _WDPPosPrinterRotation {
    WDPPosPrinterRotationNormal = 0,
    WDPPosPrinterRotationRight90 = 1,
    WDPPosPrinterRotationLeft90 = 2,
    WDPPosPrinterRotationRotate180 = 3,
};
typedef unsigned WDPPosPrinterRotation;

// Windows.Devices.PointOfService.PosPrinterStatusKind
enum _WDPPosPrinterStatusKind {
    WDPPosPrinterStatusKindOnline = 0,
    WDPPosPrinterStatusKindOff = 1,
    WDPPosPrinterStatusKindOffline = 2,
    WDPPosPrinterStatusKindOffOrOffline = 3,
    WDPPosPrinterStatusKindExtended = 4,
};
typedef unsigned WDPPosPrinterStatusKind;

// Windows.Devices.PointOfService.CashDrawerStatusKind
enum _WDPCashDrawerStatusKind {
    WDPCashDrawerStatusKindOnline = 0,
    WDPCashDrawerStatusKindOff = 1,
    WDPCashDrawerStatusKindOffline = 2,
    WDPCashDrawerStatusKindOffOrOffline = 3,
    WDPCashDrawerStatusKindExtended = 4,
};
typedef unsigned WDPCashDrawerStatusKind;

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
#include "WindowsGraphicsImaging.h"

#import <Foundation/Foundation.h>

// Windows.Devices.PointOfService.ICommonPosPrintStationCapabilities
#ifndef __WDPICommonPosPrintStationCapabilities_DEFINED__
#define __WDPICommonPosPrintStationCapabilities_DEFINED__

@protocol WDPICommonPosPrintStationCapabilities
@property (readonly) WDPPosPrinterCartridgeSensors cartridgeSensors;
@property (readonly) WDPPosPrinterColorCapabilities colorCartridgeCapabilities;
@property (readonly) BOOL isBoldSupported;
@property (readonly) BOOL isDoubleHighDoubleWidePrintSupported;
@property (readonly) BOOL isDoubleHighPrintSupported;
@property (readonly) BOOL isDoubleWidePrintSupported;
@property (readonly) BOOL isDualColorSupported;
@property (readonly) BOOL isItalicSupported;
@property (readonly) BOOL isPaperEmptySensorSupported;
@property (readonly) BOOL isPaperNearEndSensorSupported;
@property (readonly) BOOL isPrinterPresent;
@property (readonly) BOOL isUnderlineSupported;
@property (readonly) NSArray* /*UInt32*/  supportedCharactersPerLine;
@end

#endif // __WDPICommonPosPrintStationCapabilities_DEFINED__

// Windows.Devices.PointOfService.ICommonReceiptSlipCapabilities
#ifndef __WDPICommonReceiptSlipCapabilities_DEFINED__
#define __WDPICommonReceiptSlipCapabilities_DEFINED__

@protocol WDPICommonReceiptSlipCapabilities <WDPICommonPosPrintStationCapabilities>
@property (readonly) BOOL is180RotationSupported;
@property (readonly) BOOL isBarcodeSupported;
@property (readonly) BOOL isBitmapSupported;
@property (readonly) BOOL isLeft90RotationSupported;
@property (readonly) BOOL isPrintAreaSupported;
@property (readonly) BOOL isRight90RotationSupported;
@property (readonly) WDPPosPrinterRuledLineCapabilities ruledLineCapabilities;
@property (readonly) NSArray* /*WDPPosPrinterRotation*/  supportedBarcodeRotations;
@property (readonly) NSArray* /*WDPPosPrinterRotation*/  supportedBitmapRotations;
@end

#endif // __WDPICommonReceiptSlipCapabilities_DEFINED__

// Windows.Devices.PointOfService.IPosPrinterJob
#ifndef __WDPIPosPrinterJob_DEFINED__
#define __WDPIPosPrinterJob_DEFINED__

@protocol WDPIPosPrinterJob
- (void)print:(NSString *)data;
- (void)printLine:(NSString *)data;
- (void)printNewline;
- (void)executeAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPIPosPrinterJob_DEFINED__

// Windows.Devices.PointOfService.IReceiptOrSlipJob
#ifndef __WDPIReceiptOrSlipJob_DEFINED__
#define __WDPIReceiptOrSlipJob_DEFINED__

@protocol WDPIReceiptOrSlipJob <WDPIPosPrinterJob>
- (void)setBarcodeRotation:(WDPPosPrinterRotation)value;
- (void)setPrintRotation:(WDPPosPrinterRotation)value includeBitmaps:(BOOL)includeBitmaps;
- (void)setPrintArea:(WFRect *)value;
- (void)setBitmap:(unsigned)bitmapNumber bitmap:(WGIBitmapFrame *)bitmap alignment:(WDPPosPrinterAlignment)alignment;
- (void)setBitmapCustomWidthStandardAlign:(unsigned)bitmapNumber bitmap:(WGIBitmapFrame *)bitmap alignment:(WDPPosPrinterAlignment)alignment width:(unsigned)width;
- (void)setCustomAlignedBitmap:(unsigned)bitmapNumber bitmap:(WGIBitmapFrame *)bitmap alignmentDistance:(unsigned)alignmentDistance;
- (void)setBitmapCustomWidthCustomAlign:(unsigned)bitmapNumber bitmap:(WGIBitmapFrame *)bitmap alignmentDistance:(unsigned)alignmentDistance width:(unsigned)width;
- (void)printSavedBitmap:(unsigned)bitmapNumber;
- (void)drawRuledLine:(NSString *)positionList lineDirection:(WDPPosPrinterLineDirection)lineDirection lineWidth:(unsigned)lineWidth lineStyle:(WDPPosPrinterLineStyle)lineStyle lineColor:(unsigned)lineColor;
- (void)printBarcode:(NSString *)data symbology:(unsigned)symbology height:(unsigned)height width:(unsigned)width textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition alignment:(WDPPosPrinterAlignment)alignment;
- (void)printBarcodeCustomAlign:(NSString *)data symbology:(unsigned)symbology height:(unsigned)height width:(unsigned)width textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition alignmentDistance:(unsigned)alignmentDistance;
- (void)printBitmap:(WGIBitmapFrame *)bitmap alignment:(WDPPosPrinterAlignment)alignment;
- (void)printBitmapCustomWidthStandardAlign:(WGIBitmapFrame *)bitmap alignment:(WDPPosPrinterAlignment)alignment width:(unsigned)width;
- (void)printCustomAlignedBitmap:(WGIBitmapFrame *)bitmap alignmentDistance:(unsigned)alignmentDistance;
- (void)printBitmapCustomWidthCustomAlign:(WGIBitmapFrame *)bitmap alignmentDistance:(unsigned)alignmentDistance width:(unsigned)width;
- (void)print:(NSString *)data;
- (void)printLine:(NSString *)data;
- (void)printNewline;
- (void)executeAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPIReceiptOrSlipJob_DEFINED__

// Windows.Devices.PointOfService.ICommonClaimedPosPrinterStation
#ifndef __WDPICommonClaimedPosPrinterStation_DEFINED__
#define __WDPICommonClaimedPosPrinterStation_DEFINED__

@protocol WDPICommonClaimedPosPrinterStation
@property unsigned charactersPerLine;
@property WDPPosPrinterColorCartridge colorCartridge;
@property (readonly) BOOL isCartridgeEmpty;
@property (readonly) BOOL isCartridgeRemoved;
@property (readonly) BOOL isCoverOpen;
@property (readonly) BOOL isHeadCleaning;
@property BOOL isLetterQuality;
@property (readonly) BOOL isPaperEmpty;
@property (readonly) BOOL isPaperNearEnd;
@property (readonly) BOOL isReadyToPrint;
@property unsigned lineHeight;
@property unsigned lineSpacing;
@property (readonly) unsigned lineWidth;
- (BOOL)validateData:(NSString *)data;
@end

#endif // __WDPICommonClaimedPosPrinterStation_DEFINED__

// Windows.Devices.PointOfService.ICashDrawerEventSourceEventArgs
#ifndef __WDPICashDrawerEventSourceEventArgs_DEFINED__
#define __WDPICashDrawerEventSourceEventArgs_DEFINED__

@protocol WDPICashDrawerEventSourceEventArgs
@property (readonly) WDPCashDrawer * cashDrawer;
@end

#endif // __WDPICashDrawerEventSourceEventArgs_DEFINED__

// Windows.Devices.PointOfService.UnifiedPosErrorData
#ifndef __WDPUnifiedPosErrorData_DEFINED__
#define __WDPUnifiedPosErrorData_DEFINED__

WINRT_EXPORT
@interface WDPUnifiedPosErrorData : RTObject
@property (readonly) unsigned extendedReason;
@property (readonly) NSString * message;
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
+ (NSString *)getName:(unsigned)scanDataType;
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
@property (readonly) WDPBarcodeScannerReport * report;
@end

#endif // __WDPBarcodeScannerDataReceivedEventArgs_DEFINED__

// Windows.Devices.PointOfService.BarcodeScannerErrorOccurredEventArgs
#ifndef __WDPBarcodeScannerErrorOccurredEventArgs_DEFINED__
#define __WDPBarcodeScannerErrorOccurredEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPBarcodeScannerErrorOccurredEventArgs : RTObject
@property (readonly) WDPUnifiedPosErrorData * errorData;
@property (readonly) BOOL isRetriable;
@property (readonly) WDPBarcodeScannerReport * partialInputData;
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
@property (readonly) BOOL isSoftwareTriggerSupported;
@end

#endif // __WDPBarcodeScannerCapabilities_DEFINED__

// Windows.Devices.PointOfService.BarcodeScanner
#ifndef __WDPBarcodeScanner_DEFINED__
#define __WDPBarcodeScanner_DEFINED__

WINRT_EXPORT
@interface WDPBarcodeScanner : RTObject
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPBarcodeScanner *))success failure:(void (^)(NSError*))failure;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDPBarcodeScanner *))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
@property (readonly) WDPBarcodeScannerCapabilities * capabilities;
@property (readonly) NSString * deviceId;
- (EventRegistrationToken)addStatusUpdatedEvent:(void(^)(WDPBarcodeScanner *, WDPBarcodeScannerStatusUpdatedEventArgs *))del;
- (void)removeStatusUpdatedEvent:(EventRegistrationToken)tok;
- (void)claimScannerAsyncWithSuccess:(void (^)(WDPClaimedBarcodeScanner *))success failure:(void (^)(NSError*))failure;
- (void)checkHealthAsync:(WDPUnifiedPosHealthCheckLevel)level success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
- (void)getSupportedSymbologiesAsyncWithSuccess:(void (^)(id<NSFastEnumeration> /*UInt32*/ ))success failure:(void (^)(NSError*))failure;
- (void)isSymbologySupportedAsync:(unsigned)barcodeSymbology success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)retrieveStatisticsAsync:(id<NSFastEnumeration> /*String*/ )statisticsCategories success:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure;
- (NSArray* /*String*/ )getSupportedProfiles;
- (BOOL)isProfileSupported:(NSString *)profile;
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
@property (readonly) NSString * deviceId;
@property (readonly) BOOL isEnabled;
- (EventRegistrationToken)addDataReceivedEvent:(void(^)(WDPClaimedBarcodeScanner *, WDPBarcodeScannerDataReceivedEventArgs *))del;
- (void)removeDataReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addErrorOccurredEvent:(void(^)(WDPClaimedBarcodeScanner *, WDPBarcodeScannerErrorOccurredEventArgs *))del;
- (void)removeErrorOccurredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addImagePreviewReceivedEvent:(void(^)(WDPClaimedBarcodeScanner *, WDPBarcodeScannerImagePreviewReceivedEventArgs *))del;
- (void)removeImagePreviewReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addReleaseDeviceRequestedEvent:(void(^)(RTObject*, WDPClaimedBarcodeScanner *))del;
- (void)removeReleaseDeviceRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTriggerPressedEvent:(void(^)(RTObject*, WDPClaimedBarcodeScanner *))del;
- (void)removeTriggerPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTriggerReleasedEvent:(void(^)(RTObject*, WDPClaimedBarcodeScanner *))del;
- (void)removeTriggerReleasedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)enableAsync;
- (RTObject<WFIAsyncAction>*)disableAsync;
- (void)retainDevice;
- (RTObject<WFIAsyncAction>*)setActiveSymbologiesAsync:(id<NSFastEnumeration> /*UInt32*/ )symbologies;
- (RTObject<WFIAsyncAction>*)resetStatisticsAsync:(id<NSFastEnumeration> /*String*/ )statisticsCategories;
// Failed to generate member UpdateStatisticsAsync (Cannot marshal contained object of unknown type Windows.Foundation.Collections.IKeyValuePair`2<String,String>)
- (RTObject<WFIAsyncAction>*)setActiveProfileAsync:(NSString *)profile;
- (void)close;
- (RTObject<WFIAsyncAction>*)startSoftwareTriggerAsync;
- (RTObject<WFIAsyncAction>*)stopSoftwareTriggerAsync;
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
@property (readonly) NSDictionary * /*String, String*/  properties;
@property (readonly) WDPMagneticStripeReaderTrackData * track1;
@property (readonly) WDPMagneticStripeReaderTrackData * track2;
@property (readonly) WDPMagneticStripeReaderTrackData * track3;
@property (readonly) WDPMagneticStripeReaderTrackData * track4;
@end

#endif // __WDPMagneticStripeReaderReport_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderBankCardDataReceivedEventArgs
#ifndef __WDPMagneticStripeReaderBankCardDataReceivedEventArgs_DEFINED__
#define __WDPMagneticStripeReaderBankCardDataReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPMagneticStripeReaderBankCardDataReceivedEventArgs : RTObject
@property (readonly) NSString * accountNumber;
@property (readonly) NSString * expirationDate;
@property (readonly) NSString * firstName;
@property (readonly) NSString * middleInitial;
@property (readonly) WDPMagneticStripeReaderReport * report;
@property (readonly) NSString * serviceCode;
@property (readonly) NSString * suffix;
@property (readonly) NSString * surname;
@property (readonly) NSString * title;
@end

#endif // __WDPMagneticStripeReaderBankCardDataReceivedEventArgs_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderAamvaCardDataReceivedEventArgs
#ifndef __WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs_DEFINED__
#define __WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs : RTObject
@property (readonly) NSString * address;
@property (readonly) NSString * birthDate;
@property (readonly) NSString * city;
@property (readonly) NSString * Class;
@property (readonly) NSString * endorsements;
@property (readonly) NSString * expirationDate;
@property (readonly) NSString * eyeColor;
@property (readonly) NSString * firstName;
@property (readonly) NSString * gender;
@property (readonly) NSString * hairColor;
@property (readonly) NSString * height;
@property (readonly) NSString * licenseNumber;
@property (readonly) NSString * postalCode;
@property (readonly) WDPMagneticStripeReaderReport * report;
@property (readonly) NSString * restrictions;
@property (readonly) NSString * state;
@property (readonly) NSString * suffix;
@property (readonly) NSString * surname;
@property (readonly) NSString * weight;
@end

#endif // __WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs
#ifndef __WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs_DEFINED__
#define __WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs : RTObject
@property (readonly) WDPMagneticStripeReaderReport * report;
@end

#endif // __WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderErrorOccurredEventArgs
#ifndef __WDPMagneticStripeReaderErrorOccurredEventArgs_DEFINED__
#define __WDPMagneticStripeReaderErrorOccurredEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPMagneticStripeReaderErrorOccurredEventArgs : RTObject
@property (readonly) WDPUnifiedPosErrorData * errorData;
@property (readonly) WDPMagneticStripeReaderReport * partialInputData;
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
@property (readonly) NSString * cardAuthentication;
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
@property (readonly) NSString * deviceId;
@property (readonly) BOOL isDeviceAuthenticated;
@property (readonly) BOOL isEnabled;
- (EventRegistrationToken)addAamvaCardDataReceivedEvent:(void(^)(WDPClaimedMagneticStripeReader *, WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs *))del;
- (void)removeAamvaCardDataReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBankCardDataReceivedEvent:(void(^)(WDPClaimedMagneticStripeReader *, WDPMagneticStripeReaderBankCardDataReceivedEventArgs *))del;
- (void)removeBankCardDataReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addErrorOccurredEvent:(void(^)(WDPClaimedMagneticStripeReader *, WDPMagneticStripeReaderErrorOccurredEventArgs *))del;
- (void)removeErrorOccurredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addReleaseDeviceRequestedEvent:(void(^)(RTObject*, WDPClaimedMagneticStripeReader *))del;
- (void)removeReleaseDeviceRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVendorSpecificDataReceivedEvent:(void(^)(WDPClaimedMagneticStripeReader *, WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs *))del;
- (void)removeVendorSpecificDataReceivedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)enableAsync;
- (RTObject<WFIAsyncAction>*)disableAsync;
- (void)retainDevice;
- (void)setErrorReportingType:(WDPMagneticStripeReaderErrorReportingType)value;
- (void)retrieveDeviceAuthenticationDataAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)authenticateDeviceAsync:(id<NSFastEnumeration> /*UInt8*/ )responseToken;
- (RTObject<WFIAsyncAction>*)deAuthenticateDeviceAsync:(id<NSFastEnumeration> /*UInt8*/ )responseToken;
- (RTObject<WFIAsyncAction>*)updateKeyAsync:(NSString *)key keyName:(NSString *)keyName;
- (RTObject<WFIAsyncAction>*)resetStatisticsAsync:(id<NSFastEnumeration> /*String*/ )statisticsCategories;
// Failed to generate member UpdateStatisticsAsync (Cannot marshal contained object of unknown type Windows.Foundation.Collections.IKeyValuePair`2<String,String>)
- (void)close;
@end

#endif // __WDPClaimedMagneticStripeReader_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReader
#ifndef __WDPMagneticStripeReader_DEFINED__
#define __WDPMagneticStripeReader_DEFINED__

WINRT_EXPORT
@interface WDPMagneticStripeReader : RTObject
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPMagneticStripeReader *))success failure:(void (^)(NSError*))failure;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDPMagneticStripeReader *))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
@property (readonly) WDPMagneticStripeReaderCapabilities * capabilities;
@property (readonly) WDPMagneticStripeReaderAuthenticationProtocol deviceAuthenticationProtocol;
@property (readonly) NSString * deviceId;
@property (readonly) id<NSFastEnumeration> /*UInt32*/  supportedCardTypes;
- (EventRegistrationToken)addStatusUpdatedEvent:(void(^)(WDPMagneticStripeReader *, WDPMagneticStripeReaderStatusUpdatedEventArgs *))del;
- (void)removeStatusUpdatedEvent:(EventRegistrationToken)tok;
- (void)checkHealthAsync:(WDPUnifiedPosHealthCheckLevel)level success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
- (void)claimReaderAsyncWithSuccess:(void (^)(WDPClaimedMagneticStripeReader *))success failure:(void (^)(NSError*))failure;
- (void)retrieveStatisticsAsync:(id<NSFastEnumeration> /*String*/ )statisticsCategories success:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure;
- (WDPMagneticStripeReaderErrorReportingType)getErrorReportingType;
@end

#endif // __WDPMagneticStripeReader_DEFINED__

// Windows.Devices.PointOfService.PosPrinterCharacterSetIds
#ifndef __WDPPosPrinterCharacterSetIds_DEFINED__
#define __WDPPosPrinterCharacterSetIds_DEFINED__

WINRT_EXPORT
@interface WDPPosPrinterCharacterSetIds : RTObject
+ (unsigned)ansi;
+ (unsigned)ascii;
+ (unsigned)utf16LE;
@end

#endif // __WDPPosPrinterCharacterSetIds_DEFINED__

// Windows.Devices.PointOfService.ReceiptPrinterCapabilities
#ifndef __WDPReceiptPrinterCapabilities_DEFINED__
#define __WDPReceiptPrinterCapabilities_DEFINED__

WINRT_EXPORT
@interface WDPReceiptPrinterCapabilities : RTObject <WDPICommonReceiptSlipCapabilities, WDPICommonPosPrintStationCapabilities>
@property (readonly) WDPPosPrinterColorCapabilities colorCartridgeCapabilities;
@property (readonly) BOOL isBoldSupported;
@property (readonly) BOOL isDoubleHighDoubleWidePrintSupported;
@property (readonly) BOOL isDoubleHighPrintSupported;
@property (readonly) BOOL isDoubleWidePrintSupported;
@property (readonly) BOOL isDualColorSupported;
@property (readonly) BOOL isItalicSupported;
@property (readonly) BOOL isPaperEmptySensorSupported;
@property (readonly) BOOL isPaperNearEndSensorSupported;
@property (readonly) BOOL isPrinterPresent;
@property (readonly) BOOL isUnderlineSupported;
@property (readonly) NSArray* /*UInt32*/  supportedCharactersPerLine;
@property (readonly) WDPPosPrinterCartridgeSensors cartridgeSensors;
@property (readonly) BOOL is180RotationSupported;
@property (readonly) NSArray* /*WDPPosPrinterRotation*/  supportedBarcodeRotations;
@property (readonly) NSArray* /*WDPPosPrinterRotation*/  supportedBitmapRotations;
@property (readonly) BOOL isLeft90RotationSupported;
@property (readonly) BOOL isBarcodeSupported;
@property (readonly) BOOL isBitmapSupported;
@property (readonly) BOOL isPrintAreaSupported;
@property (readonly) BOOL isRight90RotationSupported;
@property (readonly) WDPPosPrinterRuledLineCapabilities ruledLineCapabilities;
@property (readonly) BOOL isStampSupported;
@property (readonly) WDPPosPrinterMarkFeedCapabilities markFeedCapabilities;
@property (readonly) BOOL canCutPaper;
@end

#endif // __WDPReceiptPrinterCapabilities_DEFINED__

// Windows.Devices.PointOfService.SlipPrinterCapabilities
#ifndef __WDPSlipPrinterCapabilities_DEFINED__
#define __WDPSlipPrinterCapabilities_DEFINED__

WINRT_EXPORT
@interface WDPSlipPrinterCapabilities : RTObject <WDPICommonReceiptSlipCapabilities, WDPICommonPosPrintStationCapabilities>
@property (readonly) BOOL isBoldSupported;
@property (readonly) BOOL isDoubleHighDoubleWidePrintSupported;
@property (readonly) BOOL isDoubleWidePrintSupported;
@property (readonly) BOOL isDoubleHighPrintSupported;
@property (readonly) BOOL isDualColorSupported;
@property (readonly) BOOL isItalicSupported;
@property (readonly) BOOL isPaperEmptySensorSupported;
@property (readonly) BOOL isPaperNearEndSensorSupported;
@property (readonly) BOOL isPrinterPresent;
@property (readonly) BOOL isUnderlineSupported;
@property (readonly) WDPPosPrinterColorCapabilities colorCartridgeCapabilities;
@property (readonly) NSArray* /*UInt32*/  supportedCharactersPerLine;
@property (readonly) WDPPosPrinterCartridgeSensors cartridgeSensors;
@property (readonly) BOOL isBarcodeSupported;
@property (readonly) NSArray* /*WDPPosPrinterRotation*/  supportedBitmapRotations;
@property (readonly) BOOL isPrintAreaSupported;
@property (readonly) NSArray* /*WDPPosPrinterRotation*/  supportedBarcodeRotations;
@property (readonly) BOOL is180RotationSupported;
@property (readonly) BOOL isBitmapSupported;
@property (readonly) BOOL isLeft90RotationSupported;
@property (readonly) BOOL isRight90RotationSupported;
@property (readonly) WDPPosPrinterRuledLineCapabilities ruledLineCapabilities;
@property (readonly) BOOL isFullLengthSupported;
@property (readonly) BOOL isBothSidesPrintingSupported;
@end

#endif // __WDPSlipPrinterCapabilities_DEFINED__

// Windows.Devices.PointOfService.JournalPrinterCapabilities
#ifndef __WDPJournalPrinterCapabilities_DEFINED__
#define __WDPJournalPrinterCapabilities_DEFINED__

WINRT_EXPORT
@interface WDPJournalPrinterCapabilities : RTObject <WDPICommonPosPrintStationCapabilities>
@property (readonly) WDPPosPrinterCartridgeSensors cartridgeSensors;
@property (readonly) WDPPosPrinterColorCapabilities colorCartridgeCapabilities;
@property (readonly) BOOL isBoldSupported;
@property (readonly) BOOL isDoubleHighDoubleWidePrintSupported;
@property (readonly) BOOL isDoubleHighPrintSupported;
@property (readonly) BOOL isDoubleWidePrintSupported;
@property (readonly) BOOL isDualColorSupported;
@property (readonly) BOOL isItalicSupported;
@property (readonly) BOOL isPaperEmptySensorSupported;
@property (readonly) BOOL isPaperNearEndSensorSupported;
@property (readonly) BOOL isPrinterPresent;
@property (readonly) BOOL isUnderlineSupported;
@property (readonly) NSArray* /*UInt32*/  supportedCharactersPerLine;
@end

#endif // __WDPJournalPrinterCapabilities_DEFINED__

// Windows.Devices.PointOfService.PosPrinterCapabilities
#ifndef __WDPPosPrinterCapabilities_DEFINED__
#define __WDPPosPrinterCapabilities_DEFINED__

WINRT_EXPORT
@interface WDPPosPrinterCapabilities : RTObject
@property (readonly) BOOL canMapCharacterSet;
@property (readonly) unsigned defaultCharacterSet;
@property (readonly) BOOL hasCoverSensor;
@property (readonly) BOOL isStatisticsReportingSupported;
@property (readonly) BOOL isStatisticsUpdatingSupported;
@property (readonly) BOOL isTransactionSupported;
@property (readonly) WDPJournalPrinterCapabilities * journal;
@property (readonly) WDPUnifiedPosPowerReportingType powerReportingType;
@property (readonly) WDPReceiptPrinterCapabilities * receipt;
@property (readonly) WDPSlipPrinterCapabilities * slip;
@end

#endif // __WDPPosPrinterCapabilities_DEFINED__

// Windows.Devices.PointOfService.PosPrinterStatus
#ifndef __WDPPosPrinterStatus_DEFINED__
#define __WDPPosPrinterStatus_DEFINED__

WINRT_EXPORT
@interface WDPPosPrinterStatus : RTObject
@property (readonly) unsigned extendedStatus;
@property (readonly) WDPPosPrinterStatusKind statusKind;
@end

#endif // __WDPPosPrinterStatus_DEFINED__

// Windows.Devices.PointOfService.PosPrinterStatusUpdatedEventArgs
#ifndef __WDPPosPrinterStatusUpdatedEventArgs_DEFINED__
#define __WDPPosPrinterStatusUpdatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPPosPrinterStatusUpdatedEventArgs : RTObject
@property (readonly) WDPPosPrinterStatus * status;
@end

#endif // __WDPPosPrinterStatusUpdatedEventArgs_DEFINED__

// Windows.Devices.PointOfService.PosPrinterReleaseDeviceRequestedEventArgs
#ifndef __WDPPosPrinterReleaseDeviceRequestedEventArgs_DEFINED__
#define __WDPPosPrinterReleaseDeviceRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPPosPrinterReleaseDeviceRequestedEventArgs : RTObject
@end

#endif // __WDPPosPrinterReleaseDeviceRequestedEventArgs_DEFINED__

// Windows.Devices.PointOfService.PosPrinter
#ifndef __WDPPosPrinter_DEFINED__
#define __WDPPosPrinter_DEFINED__

WINRT_EXPORT
@interface WDPPosPrinter : RTObject
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPPosPrinter *))success failure:(void (^)(NSError*))failure;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDPPosPrinter *))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
@property (readonly) WDPPosPrinterCapabilities * capabilities;
@property (readonly) NSString * deviceId;
@property (readonly) WDPPosPrinterStatus * status;
@property (readonly) NSArray* /*UInt32*/  supportedCharacterSets;
@property (readonly) NSArray* /*String*/  supportedTypeFaces;
- (EventRegistrationToken)addStatusUpdatedEvent:(void(^)(WDPPosPrinter *, WDPPosPrinterStatusUpdatedEventArgs *))del;
- (void)removeStatusUpdatedEvent:(EventRegistrationToken)tok;
- (void)claimPrinterAsyncWithSuccess:(void (^)(WDPClaimedPosPrinter *))success failure:(void (^)(NSError*))failure;
- (void)checkHealthAsync:(WDPUnifiedPosHealthCheckLevel)level success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
- (void)getStatisticsAsync:(id<NSFastEnumeration> /*String*/ )statisticsCategories success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPPosPrinter_DEFINED__

// Windows.Devices.PointOfService.ClaimedPosPrinter
#ifndef __WDPClaimedPosPrinter_DEFINED__
#define __WDPClaimedPosPrinter_DEFINED__

WINRT_EXPORT
@interface WDPClaimedPosPrinter : RTObject <WFIClosable>
@property WDPPosPrinterMapMode mapMode;
@property BOOL isCharacterSetMappingEnabled;
@property unsigned characterSet;
@property (readonly) NSString * deviceId;
@property (readonly) BOOL isCoverOpen;
@property (readonly) BOOL isEnabled;
@property (readonly) WDPClaimedJournalPrinter * journal;
@property (readonly) WDPClaimedReceiptPrinter * receipt;
@property (readonly) WDPClaimedSlipPrinter * slip;
- (EventRegistrationToken)addReleaseDeviceRequestedEvent:(void(^)(WDPClaimedPosPrinter *, WDPPosPrinterReleaseDeviceRequestedEventArgs *))del;
- (void)removeReleaseDeviceRequestedEvent:(EventRegistrationToken)tok;
- (void)enableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)disableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)retainDeviceAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)resetStatisticsAsync:(id<NSFastEnumeration> /*String*/ )statisticsCategories success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
// Failed to generate member UpdateStatisticsAsync (Cannot marshal contained object of unknown type Windows.Foundation.Collections.IKeyValuePair`2<String,String>)
- (void)close;
@end

#endif // __WDPClaimedPosPrinter_DEFINED__

// Windows.Devices.PointOfService.ReceiptPrintJob
#ifndef __WDPReceiptPrintJob_DEFINED__
#define __WDPReceiptPrintJob_DEFINED__

WINRT_EXPORT
@interface WDPReceiptPrintJob : RTObject <WDPIReceiptOrSlipJob, WDPIPosPrinterJob>
- (void)markFeed:(WDPPosPrinterMarkFeedKind)kind;
- (void)cutPaper:(double)percentage;
- (void)cutPaperDefault;
- (void)setBarcodeRotation:(WDPPosPrinterRotation)value;
- (void)setPrintRotation:(WDPPosPrinterRotation)value includeBitmaps:(BOOL)includeBitmaps;
- (void)setPrintArea:(WFRect *)value;
- (void)setBitmap:(unsigned)bitmapNumber bitmap:(WGIBitmapFrame *)bitmap alignment:(WDPPosPrinterAlignment)alignment;
- (void)setBitmapCustomWidthStandardAlign:(unsigned)bitmapNumber bitmap:(WGIBitmapFrame *)bitmap alignment:(WDPPosPrinterAlignment)alignment width:(unsigned)width;
- (void)setCustomAlignedBitmap:(unsigned)bitmapNumber bitmap:(WGIBitmapFrame *)bitmap alignmentDistance:(unsigned)alignmentDistance;
- (void)setBitmapCustomWidthCustomAlign:(unsigned)bitmapNumber bitmap:(WGIBitmapFrame *)bitmap alignmentDistance:(unsigned)alignmentDistance width:(unsigned)width;
- (void)printSavedBitmap:(unsigned)bitmapNumber;
- (void)drawRuledLine:(NSString *)positionList lineDirection:(WDPPosPrinterLineDirection)lineDirection lineWidth:(unsigned)lineWidth lineStyle:(WDPPosPrinterLineStyle)lineStyle lineColor:(unsigned)lineColor;
- (void)printBarcode:(NSString *)data symbology:(unsigned)symbology height:(unsigned)height width:(unsigned)width textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition alignment:(WDPPosPrinterAlignment)alignment;
- (void)printBarcodeCustomAlign:(NSString *)data symbology:(unsigned)symbology height:(unsigned)height width:(unsigned)width textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition alignmentDistance:(unsigned)alignmentDistance;
- (void)printBitmap:(WGIBitmapFrame *)bitmap alignment:(WDPPosPrinterAlignment)alignment;
- (void)printBitmapCustomWidthStandardAlign:(WGIBitmapFrame *)bitmap alignment:(WDPPosPrinterAlignment)alignment width:(unsigned)width;
- (void)printCustomAlignedBitmap:(WGIBitmapFrame *)bitmap alignmentDistance:(unsigned)alignmentDistance;
- (void)printBitmapCustomWidthCustomAlign:(WGIBitmapFrame *)bitmap alignmentDistance:(unsigned)alignmentDistance width:(unsigned)width;
- (void)print:(NSString *)data;
- (void)printLine:(NSString *)data;
- (void)printNewline;
- (void)executeAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPReceiptPrintJob_DEFINED__

// Windows.Devices.PointOfService.SlipPrintJob
#ifndef __WDPSlipPrintJob_DEFINED__
#define __WDPSlipPrintJob_DEFINED__

WINRT_EXPORT
@interface WDPSlipPrintJob : RTObject <WDPIReceiptOrSlipJob, WDPIPosPrinterJob>
- (void)setBarcodeRotation:(WDPPosPrinterRotation)value;
- (void)setPrintRotation:(WDPPosPrinterRotation)value includeBitmaps:(BOOL)includeBitmaps;
- (void)setPrintArea:(WFRect *)value;
- (void)setBitmap:(unsigned)bitmapNumber bitmap:(WGIBitmapFrame *)bitmap alignment:(WDPPosPrinterAlignment)alignment;
- (void)setBitmapCustomWidthStandardAlign:(unsigned)bitmapNumber bitmap:(WGIBitmapFrame *)bitmap alignment:(WDPPosPrinterAlignment)alignment width:(unsigned)width;
- (void)setCustomAlignedBitmap:(unsigned)bitmapNumber bitmap:(WGIBitmapFrame *)bitmap alignmentDistance:(unsigned)alignmentDistance;
- (void)setBitmapCustomWidthCustomAlign:(unsigned)bitmapNumber bitmap:(WGIBitmapFrame *)bitmap alignmentDistance:(unsigned)alignmentDistance width:(unsigned)width;
- (void)printSavedBitmap:(unsigned)bitmapNumber;
- (void)drawRuledLine:(NSString *)positionList lineDirection:(WDPPosPrinterLineDirection)lineDirection lineWidth:(unsigned)lineWidth lineStyle:(WDPPosPrinterLineStyle)lineStyle lineColor:(unsigned)lineColor;
- (void)printBarcode:(NSString *)data symbology:(unsigned)symbology height:(unsigned)height width:(unsigned)width textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition alignment:(WDPPosPrinterAlignment)alignment;
- (void)printBarcodeCustomAlign:(NSString *)data symbology:(unsigned)symbology height:(unsigned)height width:(unsigned)width textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition alignmentDistance:(unsigned)alignmentDistance;
- (void)printBitmap:(WGIBitmapFrame *)bitmap alignment:(WDPPosPrinterAlignment)alignment;
- (void)printBitmapCustomWidthStandardAlign:(WGIBitmapFrame *)bitmap alignment:(WDPPosPrinterAlignment)alignment width:(unsigned)width;
- (void)printCustomAlignedBitmap:(WGIBitmapFrame *)bitmap alignmentDistance:(unsigned)alignmentDistance;
- (void)printBitmapCustomWidthCustomAlign:(WGIBitmapFrame *)bitmap alignmentDistance:(unsigned)alignmentDistance width:(unsigned)width;
- (void)print:(NSString *)data;
- (void)printLine:(NSString *)data;
- (void)printNewline;
- (void)executeAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPSlipPrintJob_DEFINED__

// Windows.Devices.PointOfService.JournalPrintJob
#ifndef __WDPJournalPrintJob_DEFINED__
#define __WDPJournalPrintJob_DEFINED__

WINRT_EXPORT
@interface WDPJournalPrintJob : RTObject <WDPIPosPrinterJob>
- (void)print:(NSString *)data;
- (void)printLine:(NSString *)data;
- (void)printNewline;
- (void)executeAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPJournalPrintJob_DEFINED__

// Windows.Devices.PointOfService.ClaimedReceiptPrinter
#ifndef __WDPClaimedReceiptPrinter_DEFINED__
#define __WDPClaimedReceiptPrinter_DEFINED__

WINRT_EXPORT
@interface WDPClaimedReceiptPrinter : RTObject <WDPICommonClaimedPosPrinterStation>
@property (readonly) unsigned linesToPaperCut;
@property (readonly) WFSize * pageSize;
@property (readonly) WFRect * printArea;
@property (readonly) unsigned sidewaysMaxChars;
@property (readonly) unsigned sidewaysMaxLines;
@property unsigned lineSpacing;
@property unsigned lineHeight;
@property BOOL isLetterQuality;
@property WDPPosPrinterColorCartridge colorCartridge;
@property unsigned charactersPerLine;
@property (readonly) BOOL isHeadCleaning;
@property (readonly) BOOL isCoverOpen;
@property (readonly) BOOL isPaperEmpty;
@property (readonly) BOOL isPaperNearEnd;
@property (readonly) BOOL isCartridgeRemoved;
@property (readonly) BOOL isReadyToPrint;
@property (readonly) BOOL isCartridgeEmpty;
@property (readonly) unsigned lineWidth;
- (WDPReceiptPrintJob *)createJob;
- (BOOL)validateData:(NSString *)data;
@end

#endif // __WDPClaimedReceiptPrinter_DEFINED__

// Windows.Devices.PointOfService.ClaimedSlipPrinter
#ifndef __WDPClaimedSlipPrinter_DEFINED__
#define __WDPClaimedSlipPrinter_DEFINED__

WINRT_EXPORT
@interface WDPClaimedSlipPrinter : RTObject <WDPICommonClaimedPosPrinterStation>
@property (readonly) unsigned linesNearEndToEnd;
@property (readonly) unsigned maxLines;
@property (readonly) WFSize * pageSize;
@property (readonly) WFRect * printArea;
@property (readonly) WDPPosPrinterPrintSide printSide;
@property (readonly) unsigned sidewaysMaxChars;
@property (readonly) unsigned sidewaysMaxLines;
@property unsigned lineSpacing;
@property unsigned lineHeight;
@property BOOL isLetterQuality;
@property WDPPosPrinterColorCartridge colorCartridge;
@property unsigned charactersPerLine;
@property (readonly) BOOL isHeadCleaning;
@property (readonly) BOOL isCartridgeEmpty;
@property (readonly) BOOL isPaperEmpty;
@property (readonly) BOOL isCartridgeRemoved;
@property (readonly) BOOL isReadyToPrint;
@property (readonly) BOOL isPaperNearEnd;
@property (readonly) BOOL isCoverOpen;
@property (readonly) unsigned lineWidth;
- (void)openJaws;
- (void)closeJaws;
- (void)insertSlipAsync:(WFTimeSpan *)timeout success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)removeSlipAsync:(WFTimeSpan *)timeout success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)changePrintSide:(WDPPosPrinterPrintSide)printSide;
- (WDPSlipPrintJob *)createJob;
- (BOOL)validateData:(NSString *)data;
@end

#endif // __WDPClaimedSlipPrinter_DEFINED__

// Windows.Devices.PointOfService.ClaimedJournalPrinter
#ifndef __WDPClaimedJournalPrinter_DEFINED__
#define __WDPClaimedJournalPrinter_DEFINED__

WINRT_EXPORT
@interface WDPClaimedJournalPrinter : RTObject <WDPICommonClaimedPosPrinterStation>
@property BOOL isLetterQuality;
@property WDPPosPrinterColorCartridge colorCartridge;
@property unsigned charactersPerLine;
@property unsigned lineSpacing;
@property unsigned lineHeight;
@property (readonly) BOOL isCartridgeEmpty;
@property (readonly) BOOL isCartridgeRemoved;
@property (readonly) BOOL isCoverOpen;
@property (readonly) BOOL isHeadCleaning;
@property (readonly) BOOL isPaperEmpty;
@property (readonly) BOOL isPaperNearEnd;
@property (readonly) BOOL isReadyToPrint;
@property (readonly) unsigned lineWidth;
- (WDPJournalPrintJob *)createJob;
- (BOOL)validateData:(NSString *)data;
@end

#endif // __WDPClaimedJournalPrinter_DEFINED__

// Windows.Devices.PointOfService.CashDrawerStatus
#ifndef __WDPCashDrawerStatus_DEFINED__
#define __WDPCashDrawerStatus_DEFINED__

WINRT_EXPORT
@interface WDPCashDrawerStatus : RTObject
@property (readonly) unsigned extendedStatus;
@property (readonly) WDPCashDrawerStatusKind statusKind;
@end

#endif // __WDPCashDrawerStatus_DEFINED__

// Windows.Devices.PointOfService.CashDrawerStatusUpdatedEventArgs
#ifndef __WDPCashDrawerStatusUpdatedEventArgs_DEFINED__
#define __WDPCashDrawerStatusUpdatedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPCashDrawerStatusUpdatedEventArgs : RTObject
@property (readonly) WDPCashDrawerStatus * status;
@end

#endif // __WDPCashDrawerStatusUpdatedEventArgs_DEFINED__

// Windows.Devices.PointOfService.CashDrawerCapabilities
#ifndef __WDPCashDrawerCapabilities_DEFINED__
#define __WDPCashDrawerCapabilities_DEFINED__

WINRT_EXPORT
@interface WDPCashDrawerCapabilities : RTObject
@property (readonly) BOOL isDrawerOpenSensorAvailable;
@property (readonly) BOOL isStatisticsReportingSupported;
@property (readonly) BOOL isStatisticsUpdatingSupported;
@property (readonly) BOOL isStatusMultiDrawerDetectSupported;
@property (readonly) BOOL isStatusReportingSupported;
@property (readonly) WDPUnifiedPosPowerReportingType powerReportingType;
@end

#endif // __WDPCashDrawerCapabilities_DEFINED__

// Windows.Devices.PointOfService.CashDrawer
#ifndef __WDPCashDrawer_DEFINED__
#define __WDPCashDrawer_DEFINED__

WINRT_EXPORT
@interface WDPCashDrawer : RTObject
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPCashDrawer *))success failure:(void (^)(NSError*))failure;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDPCashDrawer *))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
@property (readonly) WDPCashDrawerCapabilities * capabilities;
@property (readonly) NSString * deviceId;
@property (readonly) WDPCashDrawerEventSource * drawerEventSource;
@property (readonly) BOOL isDrawerOpen;
@property (readonly) WDPCashDrawerStatus * status;
- (EventRegistrationToken)addStatusUpdatedEvent:(void(^)(WDPCashDrawer *, WDPCashDrawerStatusUpdatedEventArgs *))del;
- (void)removeStatusUpdatedEvent:(EventRegistrationToken)tok;
- (void)claimDrawerAsyncWithSuccess:(void (^)(WDPClaimedCashDrawer *))success failure:(void (^)(NSError*))failure;
- (void)checkHealthAsync:(WDPUnifiedPosHealthCheckLevel)level success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
- (void)getStatisticsAsync:(id<NSFastEnumeration> /*String*/ )statisticsCategories success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPCashDrawer_DEFINED__

// Windows.Devices.PointOfService.CashDrawerClosedEventArgs
#ifndef __WDPCashDrawerClosedEventArgs_DEFINED__
#define __WDPCashDrawerClosedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPCashDrawerClosedEventArgs : RTObject <WDPICashDrawerEventSourceEventArgs>
@property (readonly) WDPCashDrawer * cashDrawer;
@end

#endif // __WDPCashDrawerClosedEventArgs_DEFINED__

// Windows.Devices.PointOfService.CashDrawerOpenedEventArgs
#ifndef __WDPCashDrawerOpenedEventArgs_DEFINED__
#define __WDPCashDrawerOpenedEventArgs_DEFINED__

WINRT_EXPORT
@interface WDPCashDrawerOpenedEventArgs : RTObject <WDPICashDrawerEventSourceEventArgs>
@property (readonly) WDPCashDrawer * cashDrawer;
@end

#endif // __WDPCashDrawerOpenedEventArgs_DEFINED__

// Windows.Devices.PointOfService.CashDrawerEventSource
#ifndef __WDPCashDrawerEventSource_DEFINED__
#define __WDPCashDrawerEventSource_DEFINED__

WINRT_EXPORT
@interface WDPCashDrawerEventSource : RTObject
- (EventRegistrationToken)addDrawerClosedEvent:(void(^)(WDPCashDrawerEventSource *, WDPCashDrawerClosedEventArgs *))del;
- (void)removeDrawerClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDrawerOpenedEvent:(void(^)(WDPCashDrawerEventSource *, WDPCashDrawerOpenedEventArgs *))del;
- (void)removeDrawerOpenedEvent:(EventRegistrationToken)tok;
@end

#endif // __WDPCashDrawerEventSource_DEFINED__

// Windows.Devices.PointOfService.ClaimedCashDrawer
#ifndef __WDPClaimedCashDrawer_DEFINED__
#define __WDPClaimedCashDrawer_DEFINED__

WINRT_EXPORT
@interface WDPClaimedCashDrawer : RTObject <WFIClosable>
@property (readonly) WDPCashDrawerCloseAlarm * closeAlarm;
@property (readonly) NSString * deviceId;
@property (readonly) BOOL isDrawerOpen;
@property (readonly) BOOL isEnabled;
- (EventRegistrationToken)addReleaseDeviceRequestedEvent:(void(^)(WDPClaimedCashDrawer *, RTObject *))del;
- (void)removeReleaseDeviceRequestedEvent:(EventRegistrationToken)tok;
- (void)openDrawerAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)enableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)disableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)retainDeviceAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)resetStatisticsAsync:(id<NSFastEnumeration> /*String*/ )statisticsCategories success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
// Failed to generate member UpdateStatisticsAsync (Cannot marshal contained object of unknown type Windows.Foundation.Collections.IKeyValuePair`2<String,String>)
- (void)close;
@end

#endif // __WDPClaimedCashDrawer_DEFINED__

// Windows.Devices.PointOfService.CashDrawerCloseAlarm
#ifndef __WDPCashDrawerCloseAlarm_DEFINED__
#define __WDPCashDrawerCloseAlarm_DEFINED__

WINRT_EXPORT
@interface WDPCashDrawerCloseAlarm : RTObject
@property unsigned beepFrequency;
@property (copy) WFTimeSpan * beepDuration;
@property (copy) WFTimeSpan * beepDelay;
@property (copy) WFTimeSpan * alarmTimeout;
- (EventRegistrationToken)addAlarmTimeoutExpiredEvent:(void(^)(WDPCashDrawerCloseAlarm *, RTObject *))del;
- (void)removeAlarmTimeoutExpiredEvent:(EventRegistrationToken)tok;
- (void)startAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPCashDrawerCloseAlarm_DEFINED__

