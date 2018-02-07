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

// WindowsDevicesPointOfService.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
#define OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsDevicesPointOfService.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDPUnifiedPosErrorData, WDPBarcodeScannerStatusUpdatedEventArgs, WDPBarcodeSymbologies, WDPBarcodeSymbologyAttributes, WDPBarcodeScannerReport, WDPBarcodeScannerDataReceivedEventArgs, WDPBarcodeScannerErrorOccurredEventArgs, WDPBarcodeScannerImagePreviewReceivedEventArgs, WDPBarcodeScannerCapabilities, WDPBarcodeScanner, WDPClaimedBarcodeScanner, WDPMagneticStripeReaderEncryptionAlgorithms, WDPMagneticStripeReaderCardTypes, WDPMagneticStripeReaderTrackData, WDPMagneticStripeReaderReport, WDPMagneticStripeReaderBankCardDataReceivedEventArgs, WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs, WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs, WDPMagneticStripeReaderErrorOccurredEventArgs, WDPMagneticStripeReaderStatusUpdatedEventArgs, WDPMagneticStripeReaderCapabilities, WDPClaimedMagneticStripeReader, WDPMagneticStripeReader, WDPPosPrinterCharacterSetIds, WDPReceiptPrinterCapabilities, WDPSlipPrinterCapabilities, WDPJournalPrinterCapabilities, WDPPosPrinterCapabilities, WDPPosPrinterStatus, WDPPosPrinterStatusUpdatedEventArgs, WDPPosPrinterReleaseDeviceRequestedEventArgs, WDPPosPrinter, WDPClaimedPosPrinter, WDPReceiptPrintJob, WDPSlipPrintJob, WDPJournalPrintJob, WDPClaimedReceiptPrinter, WDPClaimedSlipPrinter, WDPClaimedJournalPrinter, WDPCashDrawerStatus, WDPCashDrawerStatusUpdatedEventArgs, WDPCashDrawerCapabilities, WDPCashDrawer, WDPCashDrawerClosedEventArgs, WDPCashDrawerOpenedEventArgs, WDPCashDrawerEventSource, WDPClaimedCashDrawer, WDPCashDrawerCloseAlarm, WDPLineDisplay, WDPLineDisplayStatisticsCategorySelector, WDPClaimedLineDisplay, WDPLineDisplayCursorAttributes, WDPLineDisplayCursor, WDPLineDisplayMarquee, WDPLineDisplayStoredBitmap, WDPLineDisplayWindow, WDPLineDisplayCustomGlyphs, WDPLineDisplayStatusUpdatedEventArgs, WDPLineDisplayCapabilities, WDPLineDisplayAttributes;
@protocol WDPIUnifiedPosErrorData, WDPIBarcodeScannerStatusUpdatedEventArgs, WDPIBarcodeSymbologiesStatics, WDPIBarcodeSymbologiesStatics2, WDPIBarcodeSymbologyAttributes, WDPIBarcodeScannerDataReceivedEventArgs, WDPIBarcodeScannerReport, WDPIBarcodeScannerErrorOccurredEventArgs, WDPIBarcodeScannerImagePreviewReceivedEventArgs, WDPIBarcodeScannerCapabilities, WDPIBarcodeScannerCapabilities1, WDPIBarcodeScannerStatics, WDPIBarcodeScannerStatics2, WDPIBarcodeScanner, WDPIBarcodeScanner2, WDPIClaimedBarcodeScanner, WDPIClaimedBarcodeScanner1, WDPIClaimedBarcodeScanner2, WDPIMagneticStripeReaderEncryptionAlgorithmsStatics, WDPIMagneticStripeReaderCardTypesStatics, WDPIMagneticStripeReaderTrackData, WDPIMagneticStripeReaderReport, WDPIMagneticStripeReaderBankCardDataReceivedEventArgs, WDPIMagneticStripeReaderAamvaCardDataReceivedEventArgs, WDPIMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs, WDPIMagneticStripeReaderErrorOccurredEventArgs, WDPIMagneticStripeReaderStatusUpdatedEventArgs, WDPIMagneticStripeReaderCapabilities, WDPIClaimedMagneticStripeReader, WDPIMagneticStripeReaderStatics, WDPIMagneticStripeReaderStatics2, WDPIMagneticStripeReader, WDPIPosPrinterCharacterSetIdsStatics, WDPICommonPosPrintStationCapabilities, WDPICommonReceiptSlipCapabilities, WDPIReceiptPrinterCapabilities, WDPISlipPrinterCapabilities, WDPIJournalPrinterCapabilities, WDPIPosPrinterCapabilities, WDPIPosPrinterStatus, WDPIPosPrinterStatusUpdatedEventArgs, WDPIPosPrinterReleaseDeviceRequestedEventArgs, WDPIPosPrinterStatics, WDPIPosPrinterStatics2, WDPIPosPrinter, WDPIPosPrinterJob, WDPIReceiptOrSlipJob, WDPIReceiptPrintJob, WDPICommonClaimedPosPrinterStation, WDPIClaimedReceiptPrinter, WDPIClaimedSlipPrinter, WDPIClaimedJournalPrinter, WDPIClaimedPosPrinter, WDPICashDrawerStatusUpdatedEventArgs, WDPICashDrawerStatus, WDPICashDrawerCapabilities, WDPICashDrawerEventSourceEventArgs, WDPICashDrawerEventSource, WDPICashDrawerStatics, WDPICashDrawerStatics2, WDPICashDrawer, WDPICashDrawerCloseAlarm, WDPIClaimedCashDrawer, WDPILineDisplayStatics, WDPILineDisplayStatics2, WDPIClaimedLineDisplayStatics, WDPILineDisplayStatisticsCategorySelector, WDPILineDisplayCursorAttributes, WDPILineDisplayCursor, WDPILineDisplayMarquee, WDPILineDisplayStoredBitmap, WDPILineDisplayWindow, WDPILineDisplayWindow2, WDPILineDisplayCustomGlyphs, WDPILineDisplayStatusUpdatedEventArgs, WDPILineDisplayCapabilities, WDPILineDisplay, WDPILineDisplay2, WDPIClaimedLineDisplay, WDPILineDisplayAttributes, WDPIClaimedLineDisplay2;

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

// Windows.Devices.PointOfService.LineDisplayPowerStatus
enum _WDPLineDisplayPowerStatus {
    WDPLineDisplayPowerStatusUnknown = 0,
    WDPLineDisplayPowerStatusOnline = 1,
    WDPLineDisplayPowerStatusOff = 2,
    WDPLineDisplayPowerStatusOffline = 3,
    WDPLineDisplayPowerStatusOffOrOffline = 4,
};
typedef unsigned WDPLineDisplayPowerStatus;

// Windows.Devices.PointOfService.LineDisplayHorizontalAlignment
enum _WDPLineDisplayHorizontalAlignment {
    WDPLineDisplayHorizontalAlignmentLeft = 0,
    WDPLineDisplayHorizontalAlignmentCenter = 1,
    WDPLineDisplayHorizontalAlignmentRight = 2,
};
typedef unsigned WDPLineDisplayHorizontalAlignment;

// Windows.Devices.PointOfService.LineDisplayVerticalAlignment
enum _WDPLineDisplayVerticalAlignment {
    WDPLineDisplayVerticalAlignmentTop = 0,
    WDPLineDisplayVerticalAlignmentCenter = 1,
    WDPLineDisplayVerticalAlignmentBottom = 2,
};
typedef unsigned WDPLineDisplayVerticalAlignment;

// Windows.Devices.PointOfService.LineDisplayScrollDirection
enum _WDPLineDisplayScrollDirection {
    WDPLineDisplayScrollDirectionUp = 0,
    WDPLineDisplayScrollDirectionDown = 1,
    WDPLineDisplayScrollDirectionLeft = 2,
    WDPLineDisplayScrollDirectionRight = 3,
};
typedef unsigned WDPLineDisplayScrollDirection;

// Windows.Devices.PointOfService.LineDisplayTextAttribute
enum _WDPLineDisplayTextAttribute {
    WDPLineDisplayTextAttributeNormal = 0,
    WDPLineDisplayTextAttributeBlink = 1,
    WDPLineDisplayTextAttributeReverse = 2,
    WDPLineDisplayTextAttributeReverseBlink = 3,
};
typedef unsigned WDPLineDisplayTextAttribute;

// Windows.Devices.PointOfService.LineDisplayCursorType
enum _WDPLineDisplayCursorType {
    WDPLineDisplayCursorTypeNone = 0,
    WDPLineDisplayCursorTypeBlock = 1,
    WDPLineDisplayCursorTypeHalfBlock = 2,
    WDPLineDisplayCursorTypeUnderline = 3,
    WDPLineDisplayCursorTypeReverse = 4,
    WDPLineDisplayCursorTypeOther = 5,
};
typedef unsigned WDPLineDisplayCursorType;

// Windows.Devices.PointOfService.LineDisplayMarqueeFormat
enum _WDPLineDisplayMarqueeFormat {
    WDPLineDisplayMarqueeFormatNone = 0,
    WDPLineDisplayMarqueeFormatWalk = 1,
    WDPLineDisplayMarqueeFormatPlace = 2,
};
typedef unsigned WDPLineDisplayMarqueeFormat;

// Windows.Devices.PointOfService.LineDisplayDescriptorState
enum _WDPLineDisplayDescriptorState {
    WDPLineDisplayDescriptorStateOff = 0,
    WDPLineDisplayDescriptorStateOn = 1,
    WDPLineDisplayDescriptorStateBlink = 2,
};
typedef unsigned WDPLineDisplayDescriptorState;

// Windows.Devices.PointOfService.LineDisplayTextAttributeGranularity
enum _WDPLineDisplayTextAttributeGranularity {
    WDPLineDisplayTextAttributeGranularityNotSupported = 0,
    WDPLineDisplayTextAttributeGranularityEntireDisplay = 1,
    WDPLineDisplayTextAttributeGranularityPerCharacter = 2,
};
typedef unsigned WDPLineDisplayTextAttributeGranularity;

// Windows.Devices.PointOfService.PosConnectionTypes
enum _WDPPosConnectionTypes {
    WDPPosConnectionTypesLocal = 1,
    WDPPosConnectionTypesIP = 2,
    WDPPosConnectionTypesBluetooth = 4,
    WDPPosConnectionTypesAll = -1,
};
typedef unsigned WDPPosConnectionTypes;

// Windows.Devices.PointOfService.BarcodeSymbologyDecodeLengthKind
enum _WDPBarcodeSymbologyDecodeLengthKind {
    WDPBarcodeSymbologyDecodeLengthKindAnyLength = 0,
    WDPBarcodeSymbologyDecodeLengthKindDiscrete = 1,
    WDPBarcodeSymbologyDecodeLengthKindRange = 2,
};
typedef unsigned WDPBarcodeSymbologyDecodeLengthKind;

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

#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"
#include "WindowsStorage.h"
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
@property (readonly) NSArray* /* unsigned int */ supportedCharactersPerLine;
@end

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPICommonPosPrintStationCapabilities : RTObject <WDPICommonPosPrintStationCapabilities>
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
@property (readonly) NSArray* /* WDPPosPrinterRotation */ supportedBarcodeRotations;
@property (readonly) NSArray* /* WDPPosPrinterRotation */ supportedBitmapRotations;
@end

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPICommonReceiptSlipCapabilities : RTObject <WDPICommonReceiptSlipCapabilities>
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

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPIPosPrinterJob : RTObject <WDPIPosPrinterJob>
@end

#endif // __WDPIPosPrinterJob_DEFINED__

// Windows.Devices.PointOfService.IReceiptOrSlipJob
#ifndef __WDPIReceiptOrSlipJob_DEFINED__
#define __WDPIReceiptOrSlipJob_DEFINED__

@protocol WDPIReceiptOrSlipJob <WDPIPosPrinterJob>
- (void)setBarcodeRotation:(WDPPosPrinterRotation)value;
- (void)setPrintRotation:(WDPPosPrinterRotation)value includeBitmaps:(BOOL)includeBitmaps;
- (void)setPrintArea:(WFRect*)value;
- (void)setBitmap:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment;
- (void)setBitmapCustomWidthStandardAlign:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment width:(unsigned int)width;
- (void)setCustomAlignedBitmap:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance;
- (void)setBitmapCustomWidthCustomAlign:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance width:(unsigned int)width;
- (void)printSavedBitmap:(unsigned int)bitmapNumber;
- (void)drawRuledLine:(NSString *)positionList lineDirection:(WDPPosPrinterLineDirection)lineDirection lineWidth:(unsigned int)lineWidth lineStyle:(WDPPosPrinterLineStyle)lineStyle lineColor:(unsigned int)lineColor;
- (void)printBarcode:(NSString *)data symbology:(unsigned int)symbology height:(unsigned int)height width:(unsigned int)width textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition alignment:(WDPPosPrinterAlignment)alignment;
- (void)printBarcodeCustomAlign:(NSString *)data symbology:(unsigned int)symbology height:(unsigned int)height width:(unsigned int)width textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition alignmentDistance:(unsigned int)alignmentDistance;
- (void)printBitmap:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment;
- (void)printBitmapCustomWidthStandardAlign:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment width:(unsigned int)width;
- (void)printCustomAlignedBitmap:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance;
- (void)printBitmapCustomWidthCustomAlign:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance width:(unsigned int)width;
- (void)print:(NSString *)data;
- (void)printLine:(NSString *)data;
- (void)printNewline;
- (void)executeAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPIReceiptOrSlipJob : RTObject <WDPIReceiptOrSlipJob>
@end

#endif // __WDPIReceiptOrSlipJob_DEFINED__

// Windows.Devices.PointOfService.ICommonClaimedPosPrinterStation
#ifndef __WDPICommonClaimedPosPrinterStation_DEFINED__
#define __WDPICommonClaimedPosPrinterStation_DEFINED__

@protocol WDPICommonClaimedPosPrinterStation
@property unsigned int charactersPerLine;
@property WDPPosPrinterColorCartridge colorCartridge;
@property (readonly) BOOL isCartridgeEmpty;
@property (readonly) BOOL isCartridgeRemoved;
@property (readonly) BOOL isCoverOpen;
@property (readonly) BOOL isHeadCleaning;
@property BOOL isLetterQuality;
@property (readonly) BOOL isPaperEmpty;
@property (readonly) BOOL isPaperNearEnd;
@property (readonly) BOOL isReadyToPrint;
@property unsigned int lineHeight;
@property unsigned int lineSpacing;
@property (readonly) unsigned int lineWidth;
- (BOOL)validateData:(NSString *)data;
@end

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPICommonClaimedPosPrinterStation : RTObject <WDPICommonClaimedPosPrinterStation>
@end

#endif // __WDPICommonClaimedPosPrinterStation_DEFINED__

// Windows.Devices.PointOfService.ICashDrawerEventSourceEventArgs
#ifndef __WDPICashDrawerEventSourceEventArgs_DEFINED__
#define __WDPICashDrawerEventSourceEventArgs_DEFINED__

@protocol WDPICashDrawerEventSourceEventArgs
@property (readonly) WDPCashDrawer* cashDrawer;
@end

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPICashDrawerEventSourceEventArgs : RTObject <WDPICashDrawerEventSourceEventArgs>
@end

#endif // __WDPICashDrawerEventSourceEventArgs_DEFINED__

// Windows.Devices.PointOfService.UnifiedPosErrorData
#ifndef __WDPUnifiedPosErrorData_DEFINED__
#define __WDPUnifiedPosErrorData_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPUnifiedPosErrorData : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int extendedReason;
@property (readonly) NSString * message;
@property (readonly) WDPUnifiedPosErrorReason reason;
@property (readonly) WDPUnifiedPosErrorSeverity severity;
@end

#endif // __WDPUnifiedPosErrorData_DEFINED__

// Windows.Devices.PointOfService.BarcodeScannerStatusUpdatedEventArgs
#ifndef __WDPBarcodeScannerStatusUpdatedEventArgs_DEFINED__
#define __WDPBarcodeScannerStatusUpdatedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPBarcodeScannerStatusUpdatedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int extendedStatus;
@property (readonly) WDPBarcodeScannerStatus status;
@end

#endif // __WDPBarcodeScannerStatusUpdatedEventArgs_DEFINED__

// Windows.Devices.PointOfService.BarcodeSymbologies
#ifndef __WDPBarcodeSymbologies_DEFINED__
#define __WDPBarcodeSymbologies_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPBarcodeSymbologies : RTObject
+ (NSString *)getName:(unsigned int)scanDataType;
+ (unsigned int)extendedBase;
+ (unsigned int)ausPost;
+ (unsigned int)aztec;
+ (unsigned int)canPost;
+ (unsigned int)ccab;
+ (unsigned int)ccc;
+ (unsigned int)chinaPost;
+ (unsigned int)codabar;
+ (unsigned int)codablock128;
+ (unsigned int)codablockA;
+ (unsigned int)codablockF;
+ (unsigned int)code11;
+ (unsigned int)code128;
+ (unsigned int)code16k;
+ (unsigned int)code32;
+ (unsigned int)code39;
+ (unsigned int)code39Ex;
+ (unsigned int)code49;
+ (unsigned int)code93;
+ (unsigned int)code93Ex;
+ (unsigned int)dataCode;
+ (unsigned int)dataMatrix;
+ (unsigned int)dutchKix;
+ (unsigned int)ean13;
+ (unsigned int)ean13Add2;
+ (unsigned int)ean13Add5;
+ (unsigned int)ean8;
+ (unsigned int)ean8Add2;
+ (unsigned int)ean8Add5;
+ (unsigned int)ean99;
+ (unsigned int)ean99Add2;
+ (unsigned int)ean99Add5;
+ (unsigned int)eanv;
+ (unsigned int)eanvAdd2;
+ (unsigned int)eanvAdd5;
+ (unsigned int)telepen;
+ (unsigned int)gs1128;
+ (unsigned int)gs1128Coupon;
+ (unsigned int)gs1DatabarType1;
+ (unsigned int)gs1DatabarType2;
+ (unsigned int)gs1DatabarType3;
+ (unsigned int)hanXin;
+ (unsigned int)infoMail;
+ (unsigned int)isbn;
+ (unsigned int)isbnAdd5;
+ (unsigned int)isbt;
+ (unsigned int)ismn;
+ (unsigned int)ismnAdd2;
+ (unsigned int)ismnAdd5;
+ (unsigned int)issn;
+ (unsigned int)issnAdd2;
+ (unsigned int)issnAdd5;
+ (unsigned int)italianPost25;
+ (unsigned int)italianPost39;
+ (unsigned int)japanPost;
+ (unsigned int)koreanPost;
+ (unsigned int)maxicode;
+ (unsigned int)micr;
+ (unsigned int)microPdf417;
+ (unsigned int)microQr;
+ (unsigned int)msTag;
+ (unsigned int)msi;
+ (unsigned int)ocrA;
+ (unsigned int)ocrB;
+ (unsigned int)pdf417;
+ (unsigned int)plessey;
+ (unsigned int)pzn;
+ (unsigned int)qr;
+ (unsigned int)sisac;
+ (unsigned int)swedenPost;
+ (unsigned int)tfDis;
+ (unsigned int)tfIata;
+ (unsigned int)tfInd;
+ (unsigned int)tfInt;
+ (unsigned int)tfMat;
+ (unsigned int)tfStd;
+ (unsigned int)tlc39;
+ (unsigned int)trioptic39;
+ (unsigned int)uccEan128;
+ (unsigned int)ukPost;
+ (unsigned int)unknown;
+ (unsigned int)upcCoupon;
+ (unsigned int)upca;
+ (unsigned int)upcaAdd2;
+ (unsigned int)upcaAdd5;
+ (unsigned int)upce;
+ (unsigned int)upceAdd2;
+ (unsigned int)upceAdd5;
+ (unsigned int)us4StateFics;
+ (unsigned int)usIntelligent;
+ (unsigned int)usIntelligentPkg;
+ (unsigned int)usPlanet;
+ (unsigned int)usPostNet;
+ (unsigned int)gs1DWCode;
@end

#endif // __WDPBarcodeSymbologies_DEFINED__

// Windows.Devices.PointOfService.BarcodeSymbologyAttributes
#ifndef __WDPBarcodeSymbologyAttributes_DEFINED__
#define __WDPBarcodeSymbologyAttributes_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPBarcodeSymbologyAttributes : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isCheckDigitValidationEnabled;
@property BOOL isCheckDigitTransmissionEnabled;
@property WDPBarcodeSymbologyDecodeLengthKind decodeLengthKind;
@property unsigned int decodeLength2;
@property unsigned int decodeLength1;
@property (readonly) BOOL isCheckDigitTransmissionSupported;
@property (readonly) BOOL isCheckDigitValidationSupported;
@property (readonly) BOOL isDecodeLengthSupported;
@end

#endif // __WDPBarcodeSymbologyAttributes_DEFINED__

// Windows.Devices.PointOfService.BarcodeScannerReport
#ifndef __WDPBarcodeScannerReport_DEFINED__
#define __WDPBarcodeScannerReport_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPBarcodeScannerReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIBuffer>* scanData;
@property (readonly) RTObject<WSSIBuffer>* scanDataLabel;
@property (readonly) unsigned int scanDataType;
@end

#endif // __WDPBarcodeScannerReport_DEFINED__

// Windows.Devices.PointOfService.BarcodeScannerDataReceivedEventArgs
#ifndef __WDPBarcodeScannerDataReceivedEventArgs_DEFINED__
#define __WDPBarcodeScannerDataReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPBarcodeScannerDataReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPBarcodeScannerReport* report;
@end

#endif // __WDPBarcodeScannerDataReceivedEventArgs_DEFINED__

// Windows.Devices.PointOfService.BarcodeScannerErrorOccurredEventArgs
#ifndef __WDPBarcodeScannerErrorOccurredEventArgs_DEFINED__
#define __WDPBarcodeScannerErrorOccurredEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPBarcodeScannerErrorOccurredEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPUnifiedPosErrorData* errorData;
@property (readonly) BOOL isRetriable;
@property (readonly) WDPBarcodeScannerReport* partialInputData;
@end

#endif // __WDPBarcodeScannerErrorOccurredEventArgs_DEFINED__

// Windows.Devices.PointOfService.BarcodeScannerImagePreviewReceivedEventArgs
#ifndef __WDPBarcodeScannerImagePreviewReceivedEventArgs_DEFINED__
#define __WDPBarcodeScannerImagePreviewReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPBarcodeScannerImagePreviewReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIRandomAccessStreamWithContentType>* preview;
@end

#endif // __WDPBarcodeScannerImagePreviewReceivedEventArgs_DEFINED__

// Windows.Devices.PointOfService.BarcodeScannerCapabilities
#ifndef __WDPBarcodeScannerCapabilities_DEFINED__
#define __WDPBarcodeScannerCapabilities_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPBarcodeScannerCapabilities : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isImagePreviewSupported;
@property (readonly) BOOL isStatisticsReportingSupported;
@property (readonly) BOOL isStatisticsUpdatingSupported;
@property (readonly) WDPUnifiedPosPowerReportingType powerReportingType;
@property (readonly) BOOL isSoftwareTriggerSupported;
@end

#endif // __WDPBarcodeScannerCapabilities_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.PointOfService.BarcodeScanner
#ifndef __WDPBarcodeScanner_DEFINED__
#define __WDPBarcodeScanner_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPBarcodeScanner : RTObject <WFIClosable>
+ (NSString *)getDeviceSelectorWithConnectionTypes:(WDPPosConnectionTypes)connectionTypes;
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPBarcodeScanner*))success failure:(void (^)(NSError*))failure;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDPBarcodeScanner*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPBarcodeScannerCapabilities* capabilities;
@property (readonly) NSString * deviceId;
@property (readonly) NSString * videoDeviceId;
- (EventRegistrationToken)addStatusUpdatedEvent:(void(^)(WDPBarcodeScanner*, WDPBarcodeScannerStatusUpdatedEventArgs*))del;
- (void)removeStatusUpdatedEvent:(EventRegistrationToken)tok;
- (void)claimScannerAsyncWithSuccess:(void (^)(WDPClaimedBarcodeScanner*))success failure:(void (^)(NSError*))failure;
- (void)checkHealthAsync:(WDPUnifiedPosHealthCheckLevel)level success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
- (void)getSupportedSymbologiesAsyncWithSuccess:(void (^)(NSArray* /* unsigned int */))success failure:(void (^)(NSError*))failure;
- (void)isSymbologySupportedAsync:(unsigned int)barcodeSymbology success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)retrieveStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories success:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure;
- (NSArray* /* NSString * */)getSupportedProfiles;
- (BOOL)isProfileSupported:(NSString *)profile;
- (void)close;
@end

#endif // __WDPBarcodeScanner_DEFINED__

// Windows.Devices.PointOfService.ClaimedBarcodeScanner
#ifndef __WDPClaimedBarcodeScanner_DEFINED__
#define __WDPClaimedBarcodeScanner_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPClaimedBarcodeScanner : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isDisabledOnDataReceived;
@property BOOL isDecodeDataEnabled;
@property (readonly) NSString * deviceId;
@property (readonly) BOOL isEnabled;
- (EventRegistrationToken)addDataReceivedEvent:(void(^)(WDPClaimedBarcodeScanner*, WDPBarcodeScannerDataReceivedEventArgs*))del;
- (void)removeDataReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addErrorOccurredEvent:(void(^)(WDPClaimedBarcodeScanner*, WDPBarcodeScannerErrorOccurredEventArgs*))del;
- (void)removeErrorOccurredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addImagePreviewReceivedEvent:(void(^)(WDPClaimedBarcodeScanner*, WDPBarcodeScannerImagePreviewReceivedEventArgs*))del;
- (void)removeImagePreviewReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addReleaseDeviceRequestedEvent:(void(^)(RTObject*, WDPClaimedBarcodeScanner*))del;
- (void)removeReleaseDeviceRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTriggerPressedEvent:(void(^)(RTObject*, WDPClaimedBarcodeScanner*))del;
- (void)removeTriggerPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTriggerReleasedEvent:(void(^)(RTObject*, WDPClaimedBarcodeScanner*))del;
- (void)removeTriggerReleasedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)enableAsync;
- (RTObject<WFIAsyncAction>*)disableAsync;
- (void)retainDevice;
- (RTObject<WFIAsyncAction>*)setActiveSymbologiesAsync:(id<NSFastEnumeration> /* unsigned int */)symbologies;
- (RTObject<WFIAsyncAction>*)resetStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories;
- (RTObject<WFIAsyncAction>*)updateStatisticsAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, NSString * > */)statistics;
- (RTObject<WFIAsyncAction>*)setActiveProfileAsync:(NSString *)profile;
- (void)close;
- (RTObject<WFIAsyncAction>*)startSoftwareTriggerAsync;
- (RTObject<WFIAsyncAction>*)stopSoftwareTriggerAsync;
- (void)getSymbologyAttributesAsync:(unsigned int)barcodeSymbology success:(void (^)(WDPBarcodeSymbologyAttributes*))success failure:(void (^)(NSError*))failure;
- (void)setSymbologyAttributesAsync:(unsigned int)barcodeSymbology attributes:(WDPBarcodeSymbologyAttributes*)attributes success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPClaimedBarcodeScanner_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderEncryptionAlgorithms
#ifndef __WDPMagneticStripeReaderEncryptionAlgorithms_DEFINED__
#define __WDPMagneticStripeReaderEncryptionAlgorithms_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPMagneticStripeReaderEncryptionAlgorithms : RTObject
+ (unsigned int)extendedBase;
+ (unsigned int)none;
+ (unsigned int)tripleDesDukpt;
@end

#endif // __WDPMagneticStripeReaderEncryptionAlgorithms_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderCardTypes
#ifndef __WDPMagneticStripeReaderCardTypes_DEFINED__
#define __WDPMagneticStripeReaderCardTypes_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPMagneticStripeReaderCardTypes : RTObject
+ (unsigned int)aamva;
+ (unsigned int)bank;
+ (unsigned int)extendedBase;
+ (unsigned int)unknown;
@end

#endif // __WDPMagneticStripeReaderCardTypes_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderTrackData
#ifndef __WDPMagneticStripeReaderTrackData_DEFINED__
#define __WDPMagneticStripeReaderTrackData_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPMagneticStripeReaderTrackData : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIBuffer>* data;
@property (readonly) RTObject<WSSIBuffer>* discretionaryData;
@property (readonly) RTObject<WSSIBuffer>* encryptedData;
@end

#endif // __WDPMagneticStripeReaderTrackData_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderReport
#ifndef __WDPMagneticStripeReaderReport_DEFINED__
#define __WDPMagneticStripeReaderReport_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPMagneticStripeReaderReport : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIBuffer>* additionalSecurityInformation;
@property (readonly) RTObject<WSSIBuffer>* cardAuthenticationData;
@property (readonly) unsigned int cardAuthenticationDataLength;
@property (readonly) unsigned int cardType;
@property (readonly) NSDictionary* /* NSString *, NSString * */ properties;
@property (readonly) WDPMagneticStripeReaderTrackData* track1;
@property (readonly) WDPMagneticStripeReaderTrackData* track2;
@property (readonly) WDPMagneticStripeReaderTrackData* track3;
@property (readonly) WDPMagneticStripeReaderTrackData* track4;
@end

#endif // __WDPMagneticStripeReaderReport_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderBankCardDataReceivedEventArgs
#ifndef __WDPMagneticStripeReaderBankCardDataReceivedEventArgs_DEFINED__
#define __WDPMagneticStripeReaderBankCardDataReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPMagneticStripeReaderBankCardDataReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * accountNumber;
@property (readonly) NSString * expirationDate;
@property (readonly) NSString * firstName;
@property (readonly) NSString * middleInitial;
@property (readonly) WDPMagneticStripeReaderReport* report;
@property (readonly) NSString * serviceCode;
@property (readonly) NSString * suffix;
@property (readonly) NSString * surname;
@property (readonly) NSString * title;
@end

#endif // __WDPMagneticStripeReaderBankCardDataReceivedEventArgs_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderAamvaCardDataReceivedEventArgs
#ifndef __WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs_DEFINED__
#define __WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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
@property (readonly) WDPMagneticStripeReaderReport* report;
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

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPMagneticStripeReaderReport* report;
@end

#endif // __WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderErrorOccurredEventArgs
#ifndef __WDPMagneticStripeReaderErrorOccurredEventArgs_DEFINED__
#define __WDPMagneticStripeReaderErrorOccurredEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPMagneticStripeReaderErrorOccurredEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPMagneticStripeReaderStatusUpdatedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int extendedStatus;
@property (readonly) WDPMagneticStripeReaderStatus status;
@end

#endif // __WDPMagneticStripeReaderStatusUpdatedEventArgs_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReaderCapabilities
#ifndef __WDPMagneticStripeReaderCapabilities_DEFINED__
#define __WDPMagneticStripeReaderCapabilities_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPMagneticStripeReaderCapabilities : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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
@property (readonly) unsigned int supportedEncryptionAlgorithms;
@end

#endif // __WDPMagneticStripeReaderCapabilities_DEFINED__

// Windows.Devices.PointOfService.ClaimedMagneticStripeReader
#ifndef __WDPClaimedMagneticStripeReader_DEFINED__
#define __WDPClaimedMagneticStripeReader_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPClaimedMagneticStripeReader : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WDPMagneticStripeReaderTrackIds tracksToRead;
@property BOOL isTransmitSentinelsEnabled;
@property BOOL isDisabledOnDataReceived;
@property BOOL isDecodeDataEnabled;
@property unsigned int dataEncryptionAlgorithm;
@property (readonly) NSString * deviceId;
@property (readonly) BOOL isDeviceAuthenticated;
@property (readonly) BOOL isEnabled;
- (EventRegistrationToken)addAamvaCardDataReceivedEvent:(void(^)(WDPClaimedMagneticStripeReader*, WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs*))del;
- (void)removeAamvaCardDataReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBankCardDataReceivedEvent:(void(^)(WDPClaimedMagneticStripeReader*, WDPMagneticStripeReaderBankCardDataReceivedEventArgs*))del;
- (void)removeBankCardDataReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addErrorOccurredEvent:(void(^)(WDPClaimedMagneticStripeReader*, WDPMagneticStripeReaderErrorOccurredEventArgs*))del;
- (void)removeErrorOccurredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addReleaseDeviceRequestedEvent:(void(^)(RTObject*, WDPClaimedMagneticStripeReader*))del;
- (void)removeReleaseDeviceRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVendorSpecificDataReceivedEvent:(void(^)(WDPClaimedMagneticStripeReader*, WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs*))del;
- (void)removeVendorSpecificDataReceivedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)enableAsync;
- (RTObject<WFIAsyncAction>*)disableAsync;
- (void)retainDevice;
- (void)setErrorReportingType:(WDPMagneticStripeReaderErrorReportingType)value;
- (void)retrieveDeviceAuthenticationDataAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)authenticateDeviceAsync:(NSArray* /* uint8_t */)responseToken;
- (RTObject<WFIAsyncAction>*)deAuthenticateDeviceAsync:(NSArray* /* uint8_t */)responseToken;
- (RTObject<WFIAsyncAction>*)updateKeyAsync:(NSString *)key keyName:(NSString *)keyName;
- (RTObject<WFIAsyncAction>*)resetStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories;
- (RTObject<WFIAsyncAction>*)updateStatisticsAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, NSString * > */)statistics;
- (void)close;
@end

#endif // __WDPClaimedMagneticStripeReader_DEFINED__

// Windows.Devices.PointOfService.MagneticStripeReader
#ifndef __WDPMagneticStripeReader_DEFINED__
#define __WDPMagneticStripeReader_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPMagneticStripeReader : RTObject <WFIClosable>
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPMagneticStripeReader*))success failure:(void (^)(NSError*))failure;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDPMagneticStripeReader*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
+ (NSString *)getDeviceSelectorWithConnectionTypes:(WDPPosConnectionTypes)connectionTypes;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPMagneticStripeReaderCapabilities* capabilities;
@property (readonly) WDPMagneticStripeReaderAuthenticationProtocol deviceAuthenticationProtocol;
@property (readonly) NSString * deviceId;
@property (readonly) NSArray* /* unsigned int */ supportedCardTypes;
- (EventRegistrationToken)addStatusUpdatedEvent:(void(^)(WDPMagneticStripeReader*, WDPMagneticStripeReaderStatusUpdatedEventArgs*))del;
- (void)removeStatusUpdatedEvent:(EventRegistrationToken)tok;
- (void)checkHealthAsync:(WDPUnifiedPosHealthCheckLevel)level success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
- (void)claimReaderAsyncWithSuccess:(void (^)(WDPClaimedMagneticStripeReader*))success failure:(void (^)(NSError*))failure;
- (void)retrieveStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories success:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure;
- (WDPMagneticStripeReaderErrorReportingType)getErrorReportingType;
- (void)close;
@end

#endif // __WDPMagneticStripeReader_DEFINED__

// Windows.Devices.PointOfService.PosPrinterCharacterSetIds
#ifndef __WDPPosPrinterCharacterSetIds_DEFINED__
#define __WDPPosPrinterCharacterSetIds_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPPosPrinterCharacterSetIds : RTObject
+ (unsigned int)ansi;
+ (unsigned int)ascii;
+ (unsigned int)utf16LE;
@end

#endif // __WDPPosPrinterCharacterSetIds_DEFINED__

// Windows.Devices.PointOfService.ReceiptPrinterCapabilities
#ifndef __WDPReceiptPrinterCapabilities_DEFINED__
#define __WDPReceiptPrinterCapabilities_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPReceiptPrinterCapabilities : RTObject <WDPICommonReceiptSlipCapabilities, WDPICommonPosPrintStationCapabilities>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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
@property (readonly) NSArray* /* unsigned int */ supportedCharactersPerLine;
@property (readonly) WDPPosPrinterCartridgeSensors cartridgeSensors;
@property (readonly) BOOL is180RotationSupported;
@property (readonly) NSArray* /* WDPPosPrinterRotation */ supportedBarcodeRotations;
@property (readonly) NSArray* /* WDPPosPrinterRotation */ supportedBitmapRotations;
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

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPSlipPrinterCapabilities : RTObject <WDPICommonReceiptSlipCapabilities, WDPICommonPosPrintStationCapabilities>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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
@property (readonly) NSArray* /* unsigned int */ supportedCharactersPerLine;
@property (readonly) WDPPosPrinterCartridgeSensors cartridgeSensors;
@property (readonly) BOOL isBarcodeSupported;
@property (readonly) NSArray* /* WDPPosPrinterRotation */ supportedBitmapRotations;
@property (readonly) BOOL isPrintAreaSupported;
@property (readonly) NSArray* /* WDPPosPrinterRotation */ supportedBarcodeRotations;
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

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPJournalPrinterCapabilities : RTObject <WDPICommonPosPrintStationCapabilities>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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
@property (readonly) NSArray* /* unsigned int */ supportedCharactersPerLine;
@end

#endif // __WDPJournalPrinterCapabilities_DEFINED__

// Windows.Devices.PointOfService.PosPrinterCapabilities
#ifndef __WDPPosPrinterCapabilities_DEFINED__
#define __WDPPosPrinterCapabilities_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPPosPrinterCapabilities : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL canMapCharacterSet;
@property (readonly) unsigned int defaultCharacterSet;
@property (readonly) BOOL hasCoverSensor;
@property (readonly) BOOL isStatisticsReportingSupported;
@property (readonly) BOOL isStatisticsUpdatingSupported;
@property (readonly) BOOL isTransactionSupported;
@property (readonly) WDPJournalPrinterCapabilities* journal;
@property (readonly) WDPUnifiedPosPowerReportingType powerReportingType;
@property (readonly) WDPReceiptPrinterCapabilities* receipt;
@property (readonly) WDPSlipPrinterCapabilities* slip;
@end

#endif // __WDPPosPrinterCapabilities_DEFINED__

// Windows.Devices.PointOfService.PosPrinterStatus
#ifndef __WDPPosPrinterStatus_DEFINED__
#define __WDPPosPrinterStatus_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPPosPrinterStatus : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int extendedStatus;
@property (readonly) WDPPosPrinterStatusKind statusKind;
@end

#endif // __WDPPosPrinterStatus_DEFINED__

// Windows.Devices.PointOfService.PosPrinterStatusUpdatedEventArgs
#ifndef __WDPPosPrinterStatusUpdatedEventArgs_DEFINED__
#define __WDPPosPrinterStatusUpdatedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPPosPrinterStatusUpdatedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPPosPrinterStatus* status;
@end

#endif // __WDPPosPrinterStatusUpdatedEventArgs_DEFINED__

// Windows.Devices.PointOfService.PosPrinterReleaseDeviceRequestedEventArgs
#ifndef __WDPPosPrinterReleaseDeviceRequestedEventArgs_DEFINED__
#define __WDPPosPrinterReleaseDeviceRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPPosPrinterReleaseDeviceRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WDPPosPrinterReleaseDeviceRequestedEventArgs_DEFINED__

// Windows.Devices.PointOfService.PosPrinter
#ifndef __WDPPosPrinter_DEFINED__
#define __WDPPosPrinter_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPPosPrinter : RTObject <WFIClosable>
+ (NSString *)getDeviceSelectorWithConnectionTypes:(WDPPosConnectionTypes)connectionTypes;
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPPosPrinter*))success failure:(void (^)(NSError*))failure;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDPPosPrinter*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPPosPrinterCapabilities* capabilities;
@property (readonly) NSString * deviceId;
@property (readonly) WDPPosPrinterStatus* status;
@property (readonly) NSArray* /* unsigned int */ supportedCharacterSets;
@property (readonly) NSArray* /* NSString * */ supportedTypeFaces;
- (EventRegistrationToken)addStatusUpdatedEvent:(void(^)(WDPPosPrinter*, WDPPosPrinterStatusUpdatedEventArgs*))del;
- (void)removeStatusUpdatedEvent:(EventRegistrationToken)tok;
- (void)claimPrinterAsyncWithSuccess:(void (^)(WDPClaimedPosPrinter*))success failure:(void (^)(NSError*))failure;
- (void)checkHealthAsync:(WDPUnifiedPosHealthCheckLevel)level success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
- (void)getStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WDPPosPrinter_DEFINED__

// Windows.Devices.PointOfService.ClaimedPosPrinter
#ifndef __WDPClaimedPosPrinter_DEFINED__
#define __WDPClaimedPosPrinter_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPClaimedPosPrinter : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WDPPosPrinterMapMode mapMode;
@property BOOL isCharacterSetMappingEnabled;
@property unsigned int characterSet;
@property (readonly) NSString * deviceId;
@property (readonly) BOOL isCoverOpen;
@property (readonly) BOOL isEnabled;
@property (readonly) WDPClaimedJournalPrinter* journal;
@property (readonly) WDPClaimedReceiptPrinter* receipt;
@property (readonly) WDPClaimedSlipPrinter* slip;
- (EventRegistrationToken)addReleaseDeviceRequestedEvent:(void(^)(WDPClaimedPosPrinter*, WDPPosPrinterReleaseDeviceRequestedEventArgs*))del;
- (void)removeReleaseDeviceRequestedEvent:(EventRegistrationToken)tok;
- (void)enableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)disableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)retainDeviceAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)resetStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)updateStatisticsAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, NSString * > */)statistics success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WDPClaimedPosPrinter_DEFINED__

// Windows.Devices.PointOfService.ReceiptPrintJob
#ifndef __WDPReceiptPrintJob_DEFINED__
#define __WDPReceiptPrintJob_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPReceiptPrintJob : RTObject <WDPIReceiptOrSlipJob, WDPIPosPrinterJob>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)markFeed:(WDPPosPrinterMarkFeedKind)kind;
- (void)cutPaper:(double)percentage;
- (void)cutPaperDefault;
- (void)setBarcodeRotation:(WDPPosPrinterRotation)value;
- (void)setPrintRotation:(WDPPosPrinterRotation)value includeBitmaps:(BOOL)includeBitmaps;
- (void)setPrintArea:(WFRect*)value;
- (void)setBitmap:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment;
- (void)setBitmapCustomWidthStandardAlign:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment width:(unsigned int)width;
- (void)setCustomAlignedBitmap:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance;
- (void)setBitmapCustomWidthCustomAlign:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance width:(unsigned int)width;
- (void)printSavedBitmap:(unsigned int)bitmapNumber;
- (void)drawRuledLine:(NSString *)positionList lineDirection:(WDPPosPrinterLineDirection)lineDirection lineWidth:(unsigned int)lineWidth lineStyle:(WDPPosPrinterLineStyle)lineStyle lineColor:(unsigned int)lineColor;
- (void)printBarcode:(NSString *)data symbology:(unsigned int)symbology height:(unsigned int)height width:(unsigned int)width textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition alignment:(WDPPosPrinterAlignment)alignment;
- (void)printBarcodeCustomAlign:(NSString *)data symbology:(unsigned int)symbology height:(unsigned int)height width:(unsigned int)width textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition alignmentDistance:(unsigned int)alignmentDistance;
- (void)printBitmap:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment;
- (void)printBitmapCustomWidthStandardAlign:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment width:(unsigned int)width;
- (void)printCustomAlignedBitmap:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance;
- (void)printBitmapCustomWidthCustomAlign:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance width:(unsigned int)width;
- (void)print:(NSString *)data;
- (void)printLine:(NSString *)data;
- (void)printNewline;
- (void)executeAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPReceiptPrintJob_DEFINED__

// Windows.Devices.PointOfService.SlipPrintJob
#ifndef __WDPSlipPrintJob_DEFINED__
#define __WDPSlipPrintJob_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPSlipPrintJob : RTObject <WDPIReceiptOrSlipJob, WDPIPosPrinterJob>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)setBarcodeRotation:(WDPPosPrinterRotation)value;
- (void)setPrintRotation:(WDPPosPrinterRotation)value includeBitmaps:(BOOL)includeBitmaps;
- (void)setPrintArea:(WFRect*)value;
- (void)setBitmap:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment;
- (void)setBitmapCustomWidthStandardAlign:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment width:(unsigned int)width;
- (void)setCustomAlignedBitmap:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance;
- (void)setBitmapCustomWidthCustomAlign:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance width:(unsigned int)width;
- (void)printSavedBitmap:(unsigned int)bitmapNumber;
- (void)drawRuledLine:(NSString *)positionList lineDirection:(WDPPosPrinterLineDirection)lineDirection lineWidth:(unsigned int)lineWidth lineStyle:(WDPPosPrinterLineStyle)lineStyle lineColor:(unsigned int)lineColor;
- (void)printBarcode:(NSString *)data symbology:(unsigned int)symbology height:(unsigned int)height width:(unsigned int)width textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition alignment:(WDPPosPrinterAlignment)alignment;
- (void)printBarcodeCustomAlign:(NSString *)data symbology:(unsigned int)symbology height:(unsigned int)height width:(unsigned int)width textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition alignmentDistance:(unsigned int)alignmentDistance;
- (void)printBitmap:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment;
- (void)printBitmapCustomWidthStandardAlign:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment width:(unsigned int)width;
- (void)printCustomAlignedBitmap:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance;
- (void)printBitmapCustomWidthCustomAlign:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance width:(unsigned int)width;
- (void)print:(NSString *)data;
- (void)printLine:(NSString *)data;
- (void)printNewline;
- (void)executeAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPSlipPrintJob_DEFINED__

// Windows.Devices.PointOfService.JournalPrintJob
#ifndef __WDPJournalPrintJob_DEFINED__
#define __WDPJournalPrintJob_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPJournalPrintJob : RTObject <WDPIPosPrinterJob>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)print:(NSString *)data;
- (void)printLine:(NSString *)data;
- (void)printNewline;
- (void)executeAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPJournalPrintJob_DEFINED__

// Windows.Devices.PointOfService.ClaimedReceiptPrinter
#ifndef __WDPClaimedReceiptPrinter_DEFINED__
#define __WDPClaimedReceiptPrinter_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPClaimedReceiptPrinter : RTObject <WDPICommonClaimedPosPrinterStation>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int linesToPaperCut;
@property (readonly) WFSize* pageSize;
@property (readonly) WFRect* printArea;
@property (readonly) unsigned int sidewaysMaxChars;
@property (readonly) unsigned int sidewaysMaxLines;
@property unsigned int lineSpacing;
@property unsigned int lineHeight;
@property BOOL isLetterQuality;
@property WDPPosPrinterColorCartridge colorCartridge;
@property unsigned int charactersPerLine;
@property (readonly) BOOL isHeadCleaning;
@property (readonly) BOOL isCoverOpen;
@property (readonly) BOOL isPaperEmpty;
@property (readonly) BOOL isPaperNearEnd;
@property (readonly) BOOL isCartridgeRemoved;
@property (readonly) BOOL isReadyToPrint;
@property (readonly) BOOL isCartridgeEmpty;
@property (readonly) unsigned int lineWidth;
- (WDPReceiptPrintJob*)createJob;
- (BOOL)validateData:(NSString *)data;
@end

#endif // __WDPClaimedReceiptPrinter_DEFINED__

// Windows.Devices.PointOfService.ClaimedSlipPrinter
#ifndef __WDPClaimedSlipPrinter_DEFINED__
#define __WDPClaimedSlipPrinter_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPClaimedSlipPrinter : RTObject <WDPICommonClaimedPosPrinterStation>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int linesNearEndToEnd;
@property (readonly) unsigned int maxLines;
@property (readonly) WFSize* pageSize;
@property (readonly) WFRect* printArea;
@property (readonly) WDPPosPrinterPrintSide printSide;
@property (readonly) unsigned int sidewaysMaxChars;
@property (readonly) unsigned int sidewaysMaxLines;
@property unsigned int lineSpacing;
@property unsigned int lineHeight;
@property BOOL isLetterQuality;
@property WDPPosPrinterColorCartridge colorCartridge;
@property unsigned int charactersPerLine;
@property (readonly) BOOL isHeadCleaning;
@property (readonly) BOOL isCartridgeEmpty;
@property (readonly) BOOL isPaperEmpty;
@property (readonly) BOOL isCartridgeRemoved;
@property (readonly) BOOL isReadyToPrint;
@property (readonly) BOOL isPaperNearEnd;
@property (readonly) BOOL isCoverOpen;
@property (readonly) unsigned int lineWidth;
- (void)openJaws;
- (void)closeJaws;
- (void)insertSlipAsync:(WFTimeSpan*)timeout success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)removeSlipAsync:(WFTimeSpan*)timeout success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)changePrintSide:(WDPPosPrinterPrintSide)printSide;
- (WDPSlipPrintJob*)createJob;
- (BOOL)validateData:(NSString *)data;
@end

#endif // __WDPClaimedSlipPrinter_DEFINED__

// Windows.Devices.PointOfService.ClaimedJournalPrinter
#ifndef __WDPClaimedJournalPrinter_DEFINED__
#define __WDPClaimedJournalPrinter_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPClaimedJournalPrinter : RTObject <WDPICommonClaimedPosPrinterStation>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isLetterQuality;
@property WDPPosPrinterColorCartridge colorCartridge;
@property unsigned int charactersPerLine;
@property unsigned int lineSpacing;
@property unsigned int lineHeight;
@property (readonly) BOOL isCartridgeEmpty;
@property (readonly) BOOL isCartridgeRemoved;
@property (readonly) BOOL isCoverOpen;
@property (readonly) BOOL isHeadCleaning;
@property (readonly) BOOL isPaperEmpty;
@property (readonly) BOOL isPaperNearEnd;
@property (readonly) BOOL isReadyToPrint;
@property (readonly) unsigned int lineWidth;
- (WDPJournalPrintJob*)createJob;
- (BOOL)validateData:(NSString *)data;
@end

#endif // __WDPClaimedJournalPrinter_DEFINED__

// Windows.Devices.PointOfService.CashDrawerStatus
#ifndef __WDPCashDrawerStatus_DEFINED__
#define __WDPCashDrawerStatus_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPCashDrawerStatus : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int extendedStatus;
@property (readonly) WDPCashDrawerStatusKind statusKind;
@end

#endif // __WDPCashDrawerStatus_DEFINED__

// Windows.Devices.PointOfService.CashDrawerStatusUpdatedEventArgs
#ifndef __WDPCashDrawerStatusUpdatedEventArgs_DEFINED__
#define __WDPCashDrawerStatusUpdatedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPCashDrawerStatusUpdatedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPCashDrawerStatus* status;
@end

#endif // __WDPCashDrawerStatusUpdatedEventArgs_DEFINED__

// Windows.Devices.PointOfService.CashDrawerCapabilities
#ifndef __WDPCashDrawerCapabilities_DEFINED__
#define __WDPCashDrawerCapabilities_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPCashDrawerCapabilities : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPCashDrawer : RTObject <WFIClosable>
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPCashDrawer*))success failure:(void (^)(NSError*))failure;
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDPCashDrawer*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
+ (NSString *)getDeviceSelectorWithConnectionTypes:(WDPPosConnectionTypes)connectionTypes;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPCashDrawerCapabilities* capabilities;
@property (readonly) NSString * deviceId;
@property (readonly) WDPCashDrawerEventSource* drawerEventSource;
@property (readonly) BOOL isDrawerOpen;
@property (readonly) WDPCashDrawerStatus* status;
- (EventRegistrationToken)addStatusUpdatedEvent:(void(^)(WDPCashDrawer*, WDPCashDrawerStatusUpdatedEventArgs*))del;
- (void)removeStatusUpdatedEvent:(EventRegistrationToken)tok;
- (void)claimDrawerAsyncWithSuccess:(void (^)(WDPClaimedCashDrawer*))success failure:(void (^)(NSError*))failure;
- (void)checkHealthAsync:(WDPUnifiedPosHealthCheckLevel)level success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
- (void)getStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WDPCashDrawer_DEFINED__

// Windows.Devices.PointOfService.CashDrawerClosedEventArgs
#ifndef __WDPCashDrawerClosedEventArgs_DEFINED__
#define __WDPCashDrawerClosedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPCashDrawerClosedEventArgs : RTObject <WDPICashDrawerEventSourceEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPCashDrawer* cashDrawer;
@end

#endif // __WDPCashDrawerClosedEventArgs_DEFINED__

// Windows.Devices.PointOfService.CashDrawerOpenedEventArgs
#ifndef __WDPCashDrawerOpenedEventArgs_DEFINED__
#define __WDPCashDrawerOpenedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPCashDrawerOpenedEventArgs : RTObject <WDPICashDrawerEventSourceEventArgs>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPCashDrawer* cashDrawer;
@end

#endif // __WDPCashDrawerOpenedEventArgs_DEFINED__

// Windows.Devices.PointOfService.CashDrawerEventSource
#ifndef __WDPCashDrawerEventSource_DEFINED__
#define __WDPCashDrawerEventSource_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPCashDrawerEventSource : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addDrawerClosedEvent:(void(^)(WDPCashDrawerEventSource*, WDPCashDrawerClosedEventArgs*))del;
- (void)removeDrawerClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDrawerOpenedEvent:(void(^)(WDPCashDrawerEventSource*, WDPCashDrawerOpenedEventArgs*))del;
- (void)removeDrawerOpenedEvent:(EventRegistrationToken)tok;
@end

#endif // __WDPCashDrawerEventSource_DEFINED__

// Windows.Devices.PointOfService.ClaimedCashDrawer
#ifndef __WDPClaimedCashDrawer_DEFINED__
#define __WDPClaimedCashDrawer_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPClaimedCashDrawer : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPCashDrawerCloseAlarm* closeAlarm;
@property (readonly) NSString * deviceId;
@property (readonly) BOOL isDrawerOpen;
@property (readonly) BOOL isEnabled;
- (EventRegistrationToken)addReleaseDeviceRequestedEvent:(void(^)(WDPClaimedCashDrawer*, RTObject*))del;
- (void)removeReleaseDeviceRequestedEvent:(EventRegistrationToken)tok;
- (void)openDrawerAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)enableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)disableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)retainDeviceAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)resetStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)updateStatisticsAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, NSString * > */)statistics success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WDPClaimedCashDrawer_DEFINED__

// Windows.Devices.PointOfService.CashDrawerCloseAlarm
#ifndef __WDPCashDrawerCloseAlarm_DEFINED__
#define __WDPCashDrawerCloseAlarm_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPCashDrawerCloseAlarm : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int beepFrequency;
@property (retain) WFTimeSpan* beepDuration;
@property (retain) WFTimeSpan* beepDelay;
@property (retain) WFTimeSpan* alarmTimeout;
- (EventRegistrationToken)addAlarmTimeoutExpiredEvent:(void(^)(WDPCashDrawerCloseAlarm*, RTObject*))del;
- (void)removeAlarmTimeoutExpiredEvent:(EventRegistrationToken)tok;
- (void)startAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPCashDrawerCloseAlarm_DEFINED__

// Windows.Devices.PointOfService.LineDisplay
#ifndef __WDPLineDisplay_DEFINED__
#define __WDPLineDisplay_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPLineDisplay : RTObject <WFIClosable>
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDPLineDisplay*))success failure:(void (^)(NSError*))failure;
+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPLineDisplay*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
+ (NSString *)getDeviceSelectorWithConnectionTypes:(WDPPosConnectionTypes)connectionTypes;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPLineDisplayCapabilities* capabilities;
@property (readonly) NSString * deviceControlDescription;
@property (readonly) NSString * deviceControlVersion;
@property (readonly) NSString * deviceId;
@property (readonly) NSString * deviceServiceVersion;
@property (readonly) NSString * physicalDeviceDescription;
@property (readonly) NSString * physicalDeviceName;
+ (WDPLineDisplayStatisticsCategorySelector*)statisticsCategorySelector;
- (void)claimAsyncWithSuccess:(void (^)(WDPClaimedLineDisplay*))success failure:(void (^)(NSError*))failure;
- (void)close;
- (void)checkPowerStatusAsyncWithSuccess:(void (^)(WDPLineDisplayPowerStatus))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPLineDisplay_DEFINED__

// Windows.Devices.PointOfService.LineDisplayStatisticsCategorySelector
#ifndef __WDPLineDisplayStatisticsCategorySelector_DEFINED__
#define __WDPLineDisplayStatisticsCategorySelector_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPLineDisplayStatisticsCategorySelector : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * allStatistics;
@property (readonly) NSString * manufacturerStatistics;
@property (readonly) NSString * unifiedPosStatistics;
@end

#endif // __WDPLineDisplayStatisticsCategorySelector_DEFINED__

// Windows.Devices.PointOfService.ClaimedLineDisplay
#ifndef __WDPClaimedLineDisplay_DEFINED__
#define __WDPClaimedLineDisplay_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPClaimedLineDisplay : RTObject <WFIClosable>
+ (void)fromIdAsync:(NSString *)deviceId success:(void (^)(WDPClaimedLineDisplay*))success failure:(void (^)(NSError*))failure;
+ (NSString *)getDeviceSelector;
+ (NSString *)getDeviceSelectorWithConnectionTypes:(WDPPosConnectionTypes)connectionTypes;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPLineDisplayCapabilities* capabilities;
@property (readonly) WDPLineDisplayWindow* defaultWindow;
@property (readonly) NSString * deviceControlDescription;
@property (readonly) NSString * deviceControlVersion;
@property (readonly) NSString * deviceId;
@property (readonly) NSString * deviceServiceVersion;
@property (readonly) NSString * physicalDeviceDescription;
@property (readonly) NSString * physicalDeviceName;
@property (readonly) WDPLineDisplayCustomGlyphs* customGlyphs;
@property (readonly) WFSize* maxBitmapSizeInPixels;
@property (readonly) NSArray* /* int */ supportedCharacterSets;
@property (readonly) NSArray* /* WFSize* */ supportedScreenSizesInCharacters;
- (EventRegistrationToken)addReleaseDeviceRequestedEvent:(void(^)(WDPClaimedLineDisplay*, RTObject*))del;
- (void)removeReleaseDeviceRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStatusUpdatedEvent:(void(^)(WDPClaimedLineDisplay*, WDPLineDisplayStatusUpdatedEventArgs*))del;
- (void)removeStatusUpdatedEvent:(EventRegistrationToken)tok;
- (void)retainDevice;
- (void)close;
- (void)getStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
- (void)checkHealthAsync:(WDPUnifiedPosHealthCheckLevel)level success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
- (void)checkPowerStatusAsyncWithSuccess:(void (^)(WDPLineDisplayPowerStatus))success failure:(void (^)(NSError*))failure;
- (WDPLineDisplayAttributes*)getAttributes;
- (void)tryUpdateAttributesAsync:(WDPLineDisplayAttributes*)attributes success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)trySetDescriptorAsync:(unsigned int)descriptor descriptorState:(WDPLineDisplayDescriptorState)descriptorState success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryClearDescriptorsAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryCreateWindowAsync:(WFRect*)viewport windowSize:(WFSize*)windowSize success:(void (^)(WDPLineDisplayWindow*))success failure:(void (^)(NSError*))failure;
- (void)tryStoreStorageFileBitmapAsync:(WSStorageFile*)bitmap success:(void (^)(WDPLineDisplayStoredBitmap*))success failure:(void (^)(NSError*))failure;
- (void)tryStoreStorageFileBitmapWithAlignmentAsync:(WSStorageFile*)bitmap horizontalAlignment:(WDPLineDisplayHorizontalAlignment)horizontalAlignment verticalAlignment:(WDPLineDisplayVerticalAlignment)verticalAlignment success:(void (^)(WDPLineDisplayStoredBitmap*))success failure:(void (^)(NSError*))failure;
- (void)tryStoreStorageFileBitmapWithAlignmentAndWidthAsync:(WSStorageFile*)bitmap horizontalAlignment:(WDPLineDisplayHorizontalAlignment)horizontalAlignment verticalAlignment:(WDPLineDisplayVerticalAlignment)verticalAlignment widthInPixels:(int)widthInPixels success:(void (^)(WDPLineDisplayStoredBitmap*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPClaimedLineDisplay_DEFINED__

// Windows.Devices.PointOfService.LineDisplayCursorAttributes
#ifndef __WDPLineDisplayCursorAttributes_DEFINED__
#define __WDPLineDisplayCursorAttributes_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPLineDisplayCursorAttributes : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFPoint* position;
@property BOOL isBlinkEnabled;
@property BOOL isAutoAdvanceEnabled;
@property WDPLineDisplayCursorType cursorType;
@end

#endif // __WDPLineDisplayCursorAttributes_DEFINED__

// Windows.Devices.PointOfService.LineDisplayCursor
#ifndef __WDPLineDisplayCursor_DEFINED__
#define __WDPLineDisplayCursor_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPLineDisplayCursor : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL canCustomize;
@property (readonly) BOOL isBlinkSupported;
@property (readonly) BOOL isBlockSupported;
@property (readonly) BOOL isHalfBlockSupported;
@property (readonly) BOOL isOtherSupported;
@property (readonly) BOOL isReverseSupported;
@property (readonly) BOOL isUnderlineSupported;
- (WDPLineDisplayCursorAttributes*)getAttributes;
- (void)tryUpdateAttributesAsync:(WDPLineDisplayCursorAttributes*)attributes success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPLineDisplayCursor_DEFINED__

// Windows.Devices.PointOfService.LineDisplayMarquee
#ifndef __WDPLineDisplayMarquee_DEFINED__
#define __WDPLineDisplayMarquee_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPLineDisplayMarquee : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFTimeSpan* scrollWaitInterval;
@property (retain) WFTimeSpan* repeatWaitInterval;
@property WDPLineDisplayMarqueeFormat format;
- (void)tryStartScrollingAsync:(WDPLineDisplayScrollDirection)direction success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryStopScrollingAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPLineDisplayMarquee_DEFINED__

// Windows.Devices.PointOfService.LineDisplayStoredBitmap
#ifndef __WDPLineDisplayStoredBitmap_DEFINED__
#define __WDPLineDisplayStoredBitmap_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPLineDisplayStoredBitmap : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * escapeSequence;
- (void)tryDeleteAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPLineDisplayStoredBitmap_DEFINED__

// Windows.Devices.PointOfService.LineDisplayWindow
#ifndef __WDPLineDisplayWindow_DEFINED__
#define __WDPLineDisplayWindow_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPLineDisplayWindow : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFTimeSpan* interCharacterWaitInterval;
@property (readonly) WFSize* sizeInCharacters;
@property (readonly) WDPLineDisplayCursor* cursor;
@property (readonly) WDPLineDisplayMarquee* marquee;
- (void)tryRefreshAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryDisplayTextAsync:(NSString *)text displayAttribute:(WDPLineDisplayTextAttribute)displayAttribute success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryDisplayTextAtPositionAsync:(NSString *)text displayAttribute:(WDPLineDisplayTextAttribute)displayAttribute startPosition:(WFPoint*)startPosition success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryDisplayTextNormalAsync:(NSString *)text success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryScrollTextAsync:(WDPLineDisplayScrollDirection)direction numberOfColumnsOrRows:(unsigned int)numberOfColumnsOrRows success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryClearTextAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
- (void)readCharacterAtCursorAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (void)tryDisplayStoredBitmapAtCursorAsync:(WDPLineDisplayStoredBitmap*)bitmap success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryDisplayStorageFileBitmapAtCursorAsync:(WSStorageFile*)bitmap success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryDisplayStorageFileBitmapAtCursorWithAlignmentAsync:(WSStorageFile*)bitmap horizontalAlignment:(WDPLineDisplayHorizontalAlignment)horizontalAlignment verticalAlignment:(WDPLineDisplayVerticalAlignment)verticalAlignment success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryDisplayStorageFileBitmapAtCursorWithAlignmentAndWidthAsync:(WSStorageFile*)bitmap horizontalAlignment:(WDPLineDisplayHorizontalAlignment)horizontalAlignment verticalAlignment:(WDPLineDisplayVerticalAlignment)verticalAlignment widthInPixels:(int)widthInPixels success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryDisplayStorageFileBitmapAtPointAsync:(WSStorageFile*)bitmap offsetInPixels:(WFPoint*)offsetInPixels success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryDisplayStorageFileBitmapAtPointWithWidthAsync:(WSStorageFile*)bitmap offsetInPixels:(WFPoint*)offsetInPixels widthInPixels:(int)widthInPixels success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPLineDisplayWindow_DEFINED__

// Windows.Devices.PointOfService.LineDisplayCustomGlyphs
#ifndef __WDPLineDisplayCustomGlyphs_DEFINED__
#define __WDPLineDisplayCustomGlyphs_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPLineDisplayCustomGlyphs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFSize* sizeInPixels;
@property (readonly) NSArray* /* unsigned int */ supportedGlyphCodes;
- (void)tryRedefineAsync:(unsigned int)glyphCode glyphData:(RTObject<WSSIBuffer>*)glyphData success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WDPLineDisplayCustomGlyphs_DEFINED__

// Windows.Devices.PointOfService.LineDisplayStatusUpdatedEventArgs
#ifndef __WDPLineDisplayStatusUpdatedEventArgs_DEFINED__
#define __WDPLineDisplayStatusUpdatedEventArgs_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPLineDisplayStatusUpdatedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPLineDisplayPowerStatus status;
@end

#endif // __WDPLineDisplayStatusUpdatedEventArgs_DEFINED__

// Windows.Devices.PointOfService.LineDisplayCapabilities
#ifndef __WDPLineDisplayCapabilities_DEFINED__
#define __WDPLineDisplayCapabilities_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPLineDisplayCapabilities : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WDPLineDisplayTextAttributeGranularity canBlink;
@property (readonly) BOOL canChangeBlinkRate;
@property (readonly) BOOL canChangeScreenSize;
@property (readonly) BOOL canDisplayBitmaps;
@property (readonly) BOOL canDisplayCustomGlyphs;
@property (readonly) BOOL canMapCharacterSets;
@property (readonly) BOOL canReadCharacterAtCursor;
@property (readonly) WDPLineDisplayTextAttributeGranularity canReverse;
@property (readonly) BOOL isBrightnessSupported;
@property (readonly) BOOL isCursorSupported;
@property (readonly) BOOL isHorizontalMarqueeSupported;
@property (readonly) BOOL isInterCharacterWaitSupported;
@property (readonly) BOOL isStatisticsReportingSupported;
@property (readonly) BOOL isStatisticsUpdatingSupported;
@property (readonly) BOOL isVerticalMarqueeSupported;
@property (readonly) WDPUnifiedPosPowerReportingType powerReportingType;
@property (readonly) unsigned int supportedDescriptors;
@property (readonly) unsigned int supportedWindows;
@end

#endif // __WDPLineDisplayCapabilities_DEFINED__

// Windows.Devices.PointOfService.LineDisplayAttributes
#ifndef __WDPLineDisplayAttributes_DEFINED__
#define __WDPLineDisplayAttributes_DEFINED__

OBJCUWPWINDOWSDEVICESPOINTOFSERVICEEXPORT
@interface WDPLineDisplayAttributes : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFSize* screenSizeInCharacters;
@property BOOL isPowerNotifyEnabled;
@property BOOL isCharacterSetMappingEnabled;
@property (retain) WDPLineDisplayWindow* currentWindow;
@property int characterSet;
@property int brightness;
@property (retain) WFTimeSpan* blinkRate;
@end

#endif // __WDPLineDisplayAttributes_DEFINED__

