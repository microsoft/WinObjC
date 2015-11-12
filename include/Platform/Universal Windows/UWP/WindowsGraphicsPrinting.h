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

// WindowsGraphicsPrinting.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WGPPrintTaskOptions, WGPStandardPrintTaskOptions, WGPPrintTaskProgressingEventArgs, WGPPrintTaskCompletedEventArgs, WGPPrintTask,
    WGPPrintTaskSourceRequestedDeferral, WGPPrintTaskSourceRequestedArgs, WGPPrintTaskRequestedDeferral, WGPPrintTaskRequest,
    WGPPrintTaskRequestedEventArgs, WGPPrintManager;
@class WGPPrintPageDescription;
@protocol WGPIPrintTaskOptionsCoreProperties
, WGPIPrintTaskOptionsCoreUIConfiguration, WGPIPrintTaskOptionsCore, WGPIStandardPrintTaskOptionsStatic, WGPIPrintDocumentSource,
    WGPIPrintTaskProgressingEventArgs, WGPIPrintTaskCompletedEventArgs, WGPIPrintTask, WGPIPrintTaskTargetDeviceSupport,
    WGPIPrintTaskSourceRequestedDeferral, WGPIPrintTaskSourceRequestedArgs, WGPIPrintTaskRequestedDeferral, WGPIPrintTaskRequest,
    WGPIPrintTaskRequestedEventArgs, WGPIPrintManagerStatic, WGPIPrintManager;

// Windows.Graphics.Printing.PrintMediaSize
enum _WGPPrintMediaSize {
    WGPPrintMediaSizeDefault = 0,
    WGPPrintMediaSizeNotAvailable = 1,
    WGPPrintMediaSizePrinterCustom = 2,
    WGPPrintMediaSizeBusinessCard = 3,
    WGPPrintMediaSizeCreditCard = 4,
    WGPPrintMediaSizeIsoA0 = 5,
    WGPPrintMediaSizeIsoA1 = 6,
    WGPPrintMediaSizeIsoA10 = 7,
    WGPPrintMediaSizeIsoA2 = 8,
    WGPPrintMediaSizeIsoA3 = 9,
    WGPPrintMediaSizeIsoA3Extra = 10,
    WGPPrintMediaSizeIsoA3Rotated = 11,
    WGPPrintMediaSizeIsoA4 = 12,
    WGPPrintMediaSizeIsoA4Extra = 13,
    WGPPrintMediaSizeIsoA4Rotated = 14,
    WGPPrintMediaSizeIsoA5 = 15,
    WGPPrintMediaSizeIsoA5Extra = 16,
    WGPPrintMediaSizeIsoA5Rotated = 17,
    WGPPrintMediaSizeIsoA6 = 18,
    WGPPrintMediaSizeIsoA6Rotated = 19,
    WGPPrintMediaSizeIsoA7 = 20,
    WGPPrintMediaSizeIsoA8 = 21,
    WGPPrintMediaSizeIsoA9 = 22,
    WGPPrintMediaSizeIsoB0 = 23,
    WGPPrintMediaSizeIsoB1 = 24,
    WGPPrintMediaSizeIsoB10 = 25,
    WGPPrintMediaSizeIsoB2 = 26,
    WGPPrintMediaSizeIsoB3 = 27,
    WGPPrintMediaSizeIsoB4 = 28,
    WGPPrintMediaSizeIsoB4Envelope = 29,
    WGPPrintMediaSizeIsoB5Envelope = 30,
    WGPPrintMediaSizeIsoB5Extra = 31,
    WGPPrintMediaSizeIsoB7 = 32,
    WGPPrintMediaSizeIsoB8 = 33,
    WGPPrintMediaSizeIsoB9 = 34,
    WGPPrintMediaSizeIsoC0 = 35,
    WGPPrintMediaSizeIsoC1 = 36,
    WGPPrintMediaSizeIsoC10 = 37,
    WGPPrintMediaSizeIsoC2 = 38,
    WGPPrintMediaSizeIsoC3 = 39,
    WGPPrintMediaSizeIsoC3Envelope = 40,
    WGPPrintMediaSizeIsoC4 = 41,
    WGPPrintMediaSizeIsoC4Envelope = 42,
    WGPPrintMediaSizeIsoC5 = 43,
    WGPPrintMediaSizeIsoC5Envelope = 44,
    WGPPrintMediaSizeIsoC6 = 45,
    WGPPrintMediaSizeIsoC6C5Envelope = 46,
    WGPPrintMediaSizeIsoC6Envelope = 47,
    WGPPrintMediaSizeIsoC7 = 48,
    WGPPrintMediaSizeIsoC8 = 49,
    WGPPrintMediaSizeIsoC9 = 50,
    WGPPrintMediaSizeIsoDLEnvelope = 51,
    WGPPrintMediaSizeIsoDLEnvelopeRotated = 52,
    WGPPrintMediaSizeIsoSRA3 = 53,
    WGPPrintMediaSizeJapan2LPhoto = 54,
    WGPPrintMediaSizeJapanChou3Envelope = 55,
    WGPPrintMediaSizeJapanChou3EnvelopeRotated = 56,
    WGPPrintMediaSizeJapanChou4Envelope = 57,
    WGPPrintMediaSizeJapanChou4EnvelopeRotated = 58,
    WGPPrintMediaSizeJapanDoubleHagakiPostcard = 59,
    WGPPrintMediaSizeJapanDoubleHagakiPostcardRotated = 60,
    WGPPrintMediaSizeJapanHagakiPostcard = 61,
    WGPPrintMediaSizeJapanHagakiPostcardRotated = 62,
    WGPPrintMediaSizeJapanKaku2Envelope = 63,
    WGPPrintMediaSizeJapanKaku2EnvelopeRotated = 64,
    WGPPrintMediaSizeJapanKaku3Envelope = 65,
    WGPPrintMediaSizeJapanKaku3EnvelopeRotated = 66,
    WGPPrintMediaSizeJapanLPhoto = 67,
    WGPPrintMediaSizeJapanQuadrupleHagakiPostcard = 68,
    WGPPrintMediaSizeJapanYou1Envelope = 69,
    WGPPrintMediaSizeJapanYou2Envelope = 70,
    WGPPrintMediaSizeJapanYou3Envelope = 71,
    WGPPrintMediaSizeJapanYou4Envelope = 72,
    WGPPrintMediaSizeJapanYou4EnvelopeRotated = 73,
    WGPPrintMediaSizeJapanYou6Envelope = 74,
    WGPPrintMediaSizeJapanYou6EnvelopeRotated = 75,
    WGPPrintMediaSizeJisB0 = 76,
    WGPPrintMediaSizeJisB1 = 77,
    WGPPrintMediaSizeJisB10 = 78,
    WGPPrintMediaSizeJisB2 = 79,
    WGPPrintMediaSizeJisB3 = 80,
    WGPPrintMediaSizeJisB4 = 81,
    WGPPrintMediaSizeJisB4Rotated = 82,
    WGPPrintMediaSizeJisB5 = 83,
    WGPPrintMediaSizeJisB5Rotated = 84,
    WGPPrintMediaSizeJisB6 = 85,
    WGPPrintMediaSizeJisB6Rotated = 86,
    WGPPrintMediaSizeJisB7 = 87,
    WGPPrintMediaSizeJisB8 = 88,
    WGPPrintMediaSizeJisB9 = 89,
    WGPPrintMediaSizeNorthAmerica10x11 = 90,
    WGPPrintMediaSizeNorthAmerica10x12 = 91,
    WGPPrintMediaSizeNorthAmerica10x14 = 92,
    WGPPrintMediaSizeNorthAmerica11x17 = 93,
    WGPPrintMediaSizeNorthAmerica14x17 = 94,
    WGPPrintMediaSizeNorthAmerica4x6 = 95,
    WGPPrintMediaSizeNorthAmerica4x8 = 96,
    WGPPrintMediaSizeNorthAmerica5x7 = 97,
    WGPPrintMediaSizeNorthAmerica8x10 = 98,
    WGPPrintMediaSizeNorthAmerica9x11 = 99,
    WGPPrintMediaSizeNorthAmericaArchitectureASheet = 100,
    WGPPrintMediaSizeNorthAmericaArchitectureBSheet = 101,
    WGPPrintMediaSizeNorthAmericaArchitectureCSheet = 102,
    WGPPrintMediaSizeNorthAmericaArchitectureDSheet = 103,
    WGPPrintMediaSizeNorthAmericaArchitectureESheet = 104,
    WGPPrintMediaSizeNorthAmericaCSheet = 105,
    WGPPrintMediaSizeNorthAmericaDSheet = 106,
    WGPPrintMediaSizeNorthAmericaESheet = 107,
    WGPPrintMediaSizeNorthAmericaExecutive = 108,
    WGPPrintMediaSizeNorthAmericaGermanLegalFanfold = 109,
    WGPPrintMediaSizeNorthAmericaGermanStandardFanfold = 110,
    WGPPrintMediaSizeNorthAmericaLegal = 111,
    WGPPrintMediaSizeNorthAmericaLegalExtra = 112,
    WGPPrintMediaSizeNorthAmericaLetter = 113,
    WGPPrintMediaSizeNorthAmericaLetterExtra = 114,
    WGPPrintMediaSizeNorthAmericaLetterPlus = 115,
    WGPPrintMediaSizeNorthAmericaLetterRotated = 116,
    WGPPrintMediaSizeNorthAmericaMonarchEnvelope = 117,
    WGPPrintMediaSizeNorthAmericaNote = 118,
    WGPPrintMediaSizeNorthAmericaNumber10Envelope = 119,
    WGPPrintMediaSizeNorthAmericaNumber10EnvelopeRotated = 120,
    WGPPrintMediaSizeNorthAmericaNumber11Envelope = 121,
    WGPPrintMediaSizeNorthAmericaNumber12Envelope = 122,
    WGPPrintMediaSizeNorthAmericaNumber14Envelope = 123,
    WGPPrintMediaSizeNorthAmericaNumber9Envelope = 124,
    WGPPrintMediaSizeNorthAmericaPersonalEnvelope = 125,
    WGPPrintMediaSizeNorthAmericaQuarto = 126,
    WGPPrintMediaSizeNorthAmericaStatement = 127,
    WGPPrintMediaSizeNorthAmericaSuperA = 128,
    WGPPrintMediaSizeNorthAmericaSuperB = 129,
    WGPPrintMediaSizeNorthAmericaTabloid = 130,
    WGPPrintMediaSizeNorthAmericaTabloidExtra = 131,
    WGPPrintMediaSizeOtherMetricA3Plus = 132,
    WGPPrintMediaSizeOtherMetricA4Plus = 133,
    WGPPrintMediaSizeOtherMetricFolio = 134,
    WGPPrintMediaSizeOtherMetricInviteEnvelope = 135,
    WGPPrintMediaSizeOtherMetricItalianEnvelope = 136,
    WGPPrintMediaSizePrc10Envelope = 137,
    WGPPrintMediaSizePrc10EnvelopeRotated = 138,
    WGPPrintMediaSizePrc16K = 139,
    WGPPrintMediaSizePrc16KRotated = 140,
    WGPPrintMediaSizePrc1Envelope = 141,
    WGPPrintMediaSizePrc1EnvelopeRotated = 142,
    WGPPrintMediaSizePrc2Envelope = 143,
    WGPPrintMediaSizePrc2EnvelopeRotated = 144,
    WGPPrintMediaSizePrc32K = 145,
    WGPPrintMediaSizePrc32KBig = 146,
    WGPPrintMediaSizePrc32KRotated = 147,
    WGPPrintMediaSizePrc3Envelope = 148,
    WGPPrintMediaSizePrc3EnvelopeRotated = 149,
    WGPPrintMediaSizePrc4Envelope = 150,
    WGPPrintMediaSizePrc4EnvelopeRotated = 151,
    WGPPrintMediaSizePrc5Envelope = 152,
    WGPPrintMediaSizePrc5EnvelopeRotated = 153,
    WGPPrintMediaSizePrc6Envelope = 154,
    WGPPrintMediaSizePrc6EnvelopeRotated = 155,
    WGPPrintMediaSizePrc7Envelope = 156,
    WGPPrintMediaSizePrc7EnvelopeRotated = 157,
    WGPPrintMediaSizePrc8Envelope = 158,
    WGPPrintMediaSizePrc8EnvelopeRotated = 159,
    WGPPrintMediaSizePrc9Envelope = 160,
    WGPPrintMediaSizePrc9EnvelopeRotated = 161,
    WGPPrintMediaSizeRoll04Inch = 162,
    WGPPrintMediaSizeRoll06Inch = 163,
    WGPPrintMediaSizeRoll08Inch = 164,
    WGPPrintMediaSizeRoll12Inch = 165,
    WGPPrintMediaSizeRoll15Inch = 166,
    WGPPrintMediaSizeRoll18Inch = 167,
    WGPPrintMediaSizeRoll22Inch = 168,
    WGPPrintMediaSizeRoll24Inch = 169,
    WGPPrintMediaSizeRoll30Inch = 170,
    WGPPrintMediaSizeRoll36Inch = 171,
    WGPPrintMediaSizeRoll54Inch = 172,
};
typedef unsigned WGPPrintMediaSize;

// Windows.Graphics.Printing.PrintMediaType
enum _WGPPrintMediaType {
    WGPPrintMediaTypeDefault = 0,
    WGPPrintMediaTypeNotAvailable = 1,
    WGPPrintMediaTypePrinterCustom = 2,
    WGPPrintMediaTypeAutoSelect = 3,
    WGPPrintMediaTypeArchival = 4,
    WGPPrintMediaTypeBackPrintFilm = 5,
    WGPPrintMediaTypeBond = 6,
    WGPPrintMediaTypeCardStock = 7,
    WGPPrintMediaTypeContinuous = 8,
    WGPPrintMediaTypeEnvelopePlain = 9,
    WGPPrintMediaTypeEnvelopeWindow = 10,
    WGPPrintMediaTypeFabric = 11,
    WGPPrintMediaTypeHighResolution = 12,
    WGPPrintMediaTypeLabel = 13,
    WGPPrintMediaTypeMultiLayerForm = 14,
    WGPPrintMediaTypeMultiPartForm = 15,
    WGPPrintMediaTypePhotographic = 16,
    WGPPrintMediaTypePhotographicFilm = 17,
    WGPPrintMediaTypePhotographicGlossy = 18,
    WGPPrintMediaTypePhotographicHighGloss = 19,
    WGPPrintMediaTypePhotographicMatte = 20,
    WGPPrintMediaTypePhotographicSatin = 21,
    WGPPrintMediaTypePhotographicSemiGloss = 22,
    WGPPrintMediaTypePlain = 23,
    WGPPrintMediaTypeScreen = 24,
    WGPPrintMediaTypeScreenPaged = 25,
    WGPPrintMediaTypeStationery = 26,
    WGPPrintMediaTypeTabStockFull = 27,
    WGPPrintMediaTypeTabStockPreCut = 28,
    WGPPrintMediaTypeTransparency = 29,
    WGPPrintMediaTypeTShirtTransfer = 30,
    WGPPrintMediaTypeNone = 31,
};
typedef unsigned WGPPrintMediaType;

// Windows.Graphics.Printing.PrintOrientation
enum _WGPPrintOrientation {
    WGPPrintOrientationDefault = 0,
    WGPPrintOrientationNotAvailable = 1,
    WGPPrintOrientationPrinterCustom = 2,
    WGPPrintOrientationPortrait = 3,
    WGPPrintOrientationPortraitFlipped = 4,
    WGPPrintOrientationLandscape = 5,
    WGPPrintOrientationLandscapeFlipped = 6,
};
typedef unsigned WGPPrintOrientation;

// Windows.Graphics.Printing.PrintQuality
enum _WGPPrintQuality {
    WGPPrintQualityDefault = 0,
    WGPPrintQualityNotAvailable = 1,
    WGPPrintQualityPrinterCustom = 2,
    WGPPrintQualityAutomatic = 3,
    WGPPrintQualityDraft = 4,
    WGPPrintQualityFax = 5,
    WGPPrintQualityHigh = 6,
    WGPPrintQualityNormal = 7,
    WGPPrintQualityPhotographic = 8,
    WGPPrintQualityText = 9,
};
typedef unsigned WGPPrintQuality;

// Windows.Graphics.Printing.PrintColorMode
enum _WGPPrintColorMode {
    WGPPrintColorModeDefault = 0,
    WGPPrintColorModeNotAvailable = 1,
    WGPPrintColorModePrinterCustom = 2,
    WGPPrintColorModeColor = 3,
    WGPPrintColorModeGrayscale = 4,
    WGPPrintColorModeMonochrome = 5,
};
typedef unsigned WGPPrintColorMode;

// Windows.Graphics.Printing.PrintDuplex
enum _WGPPrintDuplex {
    WGPPrintDuplexDefault = 0,
    WGPPrintDuplexNotAvailable = 1,
    WGPPrintDuplexPrinterCustom = 2,
    WGPPrintDuplexOneSided = 3,
    WGPPrintDuplexTwoSidedShortEdge = 4,
    WGPPrintDuplexTwoSidedLongEdge = 5,
};
typedef unsigned WGPPrintDuplex;

// Windows.Graphics.Printing.PrintCollation
enum _WGPPrintCollation {
    WGPPrintCollationDefault = 0,
    WGPPrintCollationNotAvailable = 1,
    WGPPrintCollationPrinterCustom = 2,
    WGPPrintCollationCollated = 3,
    WGPPrintCollationUncollated = 4,
};
typedef unsigned WGPPrintCollation;

// Windows.Graphics.Printing.PrintStaple
enum _WGPPrintStaple {
    WGPPrintStapleDefault = 0,
    WGPPrintStapleNotAvailable = 1,
    WGPPrintStaplePrinterCustom = 2,
    WGPPrintStapleNone = 3,
    WGPPrintStapleStapleTopLeft = 4,
    WGPPrintStapleStapleTopRight = 5,
    WGPPrintStapleStapleBottomLeft = 6,
    WGPPrintStapleStapleBottomRight = 7,
    WGPPrintStapleStapleDualLeft = 8,
    WGPPrintStapleStapleDualRight = 9,
    WGPPrintStapleStapleDualTop = 10,
    WGPPrintStapleStapleDualBottom = 11,
    WGPPrintStapleSaddleStitch = 12,
};
typedef unsigned WGPPrintStaple;

// Windows.Graphics.Printing.PrintHolePunch
enum _WGPPrintHolePunch {
    WGPPrintHolePunchDefault = 0,
    WGPPrintHolePunchNotAvailable = 1,
    WGPPrintHolePunchPrinterCustom = 2,
    WGPPrintHolePunchNone = 3,
    WGPPrintHolePunchLeftEdge = 4,
    WGPPrintHolePunchRightEdge = 5,
    WGPPrintHolePunchTopEdge = 6,
    WGPPrintHolePunchBottomEdge = 7,
};
typedef unsigned WGPPrintHolePunch;

// Windows.Graphics.Printing.PrintBinding
enum _WGPPrintBinding {
    WGPPrintBindingDefault = 0,
    WGPPrintBindingNotAvailable = 1,
    WGPPrintBindingPrinterCustom = 2,
    WGPPrintBindingNone = 3,
    WGPPrintBindingBale = 4,
    WGPPrintBindingBindBottom = 5,
    WGPPrintBindingBindLeft = 6,
    WGPPrintBindingBindRight = 7,
    WGPPrintBindingBindTop = 8,
    WGPPrintBindingBooklet = 9,
    WGPPrintBindingEdgeStitchBottom = 10,
    WGPPrintBindingEdgeStitchLeft = 11,
    WGPPrintBindingEdgeStitchRight = 12,
    WGPPrintBindingEdgeStitchTop = 13,
    WGPPrintBindingFold = 14,
    WGPPrintBindingJogOffset = 15,
    WGPPrintBindingTrim = 16,
};
typedef unsigned WGPPrintBinding;

// Windows.Graphics.Printing.PrintTaskCompletion
enum _WGPPrintTaskCompletion {
    WGPPrintTaskCompletionAbandoned = 0,
    WGPPrintTaskCompletionCanceled = 1,
    WGPPrintTaskCompletionFailed = 2,
    WGPPrintTaskCompletionSubmitted = 3,
};
typedef unsigned WGPPrintTaskCompletion;

#include "WindowsApplicationModelDataTransfer.h"
#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
// Windows.Graphics.Printing.PrintTaskSourceRequestedHandler
#ifndef __WGPPrintTaskSourceRequestedHandler__DEFINED
#define __WGPPrintTaskSourceRequestedHandler__DEFINED
typedef void (^WGPPrintTaskSourceRequestedHandler)(WGPPrintTaskSourceRequestedArgs* args);
#endif // __WGPPrintTaskSourceRequestedHandler__DEFINED

#import <Foundation/Foundation.h>

// [struct] Windows.Graphics.Printing.PrintPageDescription
WINRT_EXPORT
@interface WGPPrintPageDescription : NSObject
+ (instancetype) new;
@property (copy) WFSize* pageSize;
@property (copy) WFRect* imageableRect;
@property unsigned int dpiX;
@property unsigned int dpiY;
@end

// Windows.Graphics.Printing.PrintTaskSourceRequestedHandler
#ifndef __WGPPrintTaskSourceRequestedHandler__DEFINED
#define __WGPPrintTaskSourceRequestedHandler__DEFINED
typedef void (^WGPPrintTaskSourceRequestedHandler)(WGPPrintTaskSourceRequestedArgs* args);
#endif // __WGPPrintTaskSourceRequestedHandler__DEFINED

// Windows.Graphics.Printing.IPrintTaskOptionsCoreProperties
#ifndef __WGPIPrintTaskOptionsCoreProperties_DEFINED__
#define __WGPIPrintTaskOptionsCoreProperties_DEFINED__

@protocol WGPIPrintTaskOptionsCoreProperties
@property WGPPrintBinding binding;
@property WGPPrintCollation collation;
@property WGPPrintColorMode colorMode;
@property WGPPrintDuplex duplex;
@property WGPPrintHolePunch holePunch;
@property (readonly) unsigned int maxCopies;
@property WGPPrintMediaSize mediaSize;
@property WGPPrintMediaType mediaType;
@property (readonly) unsigned int minCopies;
@property unsigned int numberOfCopies;
@property WGPPrintOrientation orientation;
@property WGPPrintQuality printQuality;
@property WGPPrintStaple staple;
@end

#endif // __WGPIPrintTaskOptionsCoreProperties_DEFINED__

// Windows.Graphics.Printing.IPrintTaskOptionsCoreUIConfiguration
#ifndef __WGPIPrintTaskOptionsCoreUIConfiguration_DEFINED__
#define __WGPIPrintTaskOptionsCoreUIConfiguration_DEFINED__

@protocol WGPIPrintTaskOptionsCoreUIConfiguration
@property (readonly) NSMutableArray* displayedOptions;
@end

#endif // __WGPIPrintTaskOptionsCoreUIConfiguration_DEFINED__

// Windows.Graphics.Printing.IPrintTaskOptionsCore
#ifndef __WGPIPrintTaskOptionsCore_DEFINED__
#define __WGPIPrintTaskOptionsCore_DEFINED__

@protocol WGPIPrintTaskOptionsCore
- (WGPPrintPageDescription*)getPageDescription:(unsigned int)jobPageNumber;
@end

#endif // __WGPIPrintTaskOptionsCore_DEFINED__

// Windows.Graphics.Printing.IPrintDocumentSource
#ifndef __WGPIPrintDocumentSource_DEFINED__
#define __WGPIPrintDocumentSource_DEFINED__

@protocol WGPIPrintDocumentSource
@end

#endif // __WGPIPrintDocumentSource_DEFINED__

// Windows.Graphics.Printing.PrintTaskOptions
#ifndef __WGPPrintTaskOptions_DEFINED__
#define __WGPPrintTaskOptions_DEFINED__

WINRT_EXPORT
@interface WGPPrintTaskOptions
    : RTObject <WGPIPrintTaskOptionsCore, WGPIPrintTaskOptionsCoreProperties, WGPIPrintTaskOptionsCoreUIConfiguration>
@property WGPPrintMediaSize mediaSize;
@property WGPPrintMediaType mediaType;
@property WGPPrintHolePunch holePunch;
@property WGPPrintBinding binding;
@property WGPPrintDuplex duplex;
@property WGPPrintColorMode colorMode;
@property WGPPrintStaple staple;
@property WGPPrintCollation collation;
@property WGPPrintQuality printQuality;
@property WGPPrintOrientation orientation;
@property unsigned int numberOfCopies;
@property (readonly) unsigned int maxCopies;
@property (readonly) unsigned int minCopies;
@property (readonly) NSMutableArray* displayedOptions;
- (WGPPrintPageDescription*)getPageDescription:(unsigned int)jobPageNumber;
@end

#endif // __WGPPrintTaskOptions_DEFINED__

// Windows.Graphics.Printing.StandardPrintTaskOptions
#ifndef __WGPStandardPrintTaskOptions_DEFINED__
#define __WGPStandardPrintTaskOptions_DEFINED__

WINRT_EXPORT
@interface WGPStandardPrintTaskOptions : RTObject
+ (NSString*)binding;
+ (NSString*)collation;
+ (NSString*)colorMode;
+ (NSString*)copies;
+ (NSString*)duplex;
+ (NSString*)holePunch;
+ (NSString*)inputBin;
+ (NSString*)mediaSize;
+ (NSString*)mediaType;
+ (NSString*)nUp;
+ (NSString*)orientation;
+ (NSString*)printQuality;
+ (NSString*)staple;
@end

#endif // __WGPStandardPrintTaskOptions_DEFINED__

// Windows.Graphics.Printing.PrintTaskProgressingEventArgs
#ifndef __WGPPrintTaskProgressingEventArgs_DEFINED__
#define __WGPPrintTaskProgressingEventArgs_DEFINED__

WINRT_EXPORT
@interface WGPPrintTaskProgressingEventArgs : RTObject
@property (readonly) unsigned int documentPageCount;
@end

#endif // __WGPPrintTaskProgressingEventArgs_DEFINED__

// Windows.Graphics.Printing.PrintTaskCompletedEventArgs
#ifndef __WGPPrintTaskCompletedEventArgs_DEFINED__
#define __WGPPrintTaskCompletedEventArgs_DEFINED__

WINRT_EXPORT
@interface WGPPrintTaskCompletedEventArgs : RTObject
@property (readonly) WGPPrintTaskCompletion completion;
@end

#endif // __WGPPrintTaskCompletedEventArgs_DEFINED__

// Windows.Graphics.Printing.PrintTask
#ifndef __WGPPrintTask_DEFINED__
#define __WGPPrintTask_DEFINED__

WINRT_EXPORT
@interface WGPPrintTask : RTObject
@property (readonly) WGPPrintTaskOptions* options;
@property (readonly) WADDataPackagePropertySet* properties;
@property (readonly) RTObject<WGPIPrintDocumentSource>* source;
@property BOOL isPrinterTargetEnabled;
@property BOOL is3DManufacturingTargetEnabled;
- (EventRegistrationToken)addCompletedEvent:(void (^)(WGPPrintTask*, WGPPrintTaskCompletedEventArgs*))del;
- (void)removeCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPreviewingEvent:(void (^)(WGPPrintTask*, RTObject*))del;
- (void)removePreviewingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addProgressingEvent:(void (^)(WGPPrintTask*, WGPPrintTaskProgressingEventArgs*))del;
- (void)removeProgressingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSubmittingEvent:(void (^)(WGPPrintTask*, RTObject*))del;
- (void)removeSubmittingEvent:(EventRegistrationToken)tok;
@end

#endif // __WGPPrintTask_DEFINED__

// Windows.Graphics.Printing.PrintTaskSourceRequestedDeferral
#ifndef __WGPPrintTaskSourceRequestedDeferral_DEFINED__
#define __WGPPrintTaskSourceRequestedDeferral_DEFINED__

WINRT_EXPORT
@interface WGPPrintTaskSourceRequestedDeferral : RTObject
- (void)complete;
@end

#endif // __WGPPrintTaskSourceRequestedDeferral_DEFINED__

// Windows.Graphics.Printing.PrintTaskSourceRequestedArgs
#ifndef __WGPPrintTaskSourceRequestedArgs_DEFINED__
#define __WGPPrintTaskSourceRequestedArgs_DEFINED__

WINRT_EXPORT
@interface WGPPrintTaskSourceRequestedArgs : RTObject
@property (readonly) WFDateTime* deadline;
- (void)setSource:(RTObject<WGPIPrintDocumentSource>*)source;
- (WGPPrintTaskSourceRequestedDeferral*)getDeferral;
@end

#endif // __WGPPrintTaskSourceRequestedArgs_DEFINED__

// Windows.Graphics.Printing.PrintTaskRequestedDeferral
#ifndef __WGPPrintTaskRequestedDeferral_DEFINED__
#define __WGPPrintTaskRequestedDeferral_DEFINED__

WINRT_EXPORT
@interface WGPPrintTaskRequestedDeferral : RTObject
- (void)complete;
@end

#endif // __WGPPrintTaskRequestedDeferral_DEFINED__

// Windows.Graphics.Printing.PrintTaskRequest
#ifndef __WGPPrintTaskRequest_DEFINED__
#define __WGPPrintTaskRequest_DEFINED__

WINRT_EXPORT
@interface WGPPrintTaskRequest : RTObject
@property (readonly) WFDateTime* deadline;
- (WGPPrintTask*)createPrintTask:(NSString*)title handler:(WGPPrintTaskSourceRequestedHandler)handler;
- (WGPPrintTaskRequestedDeferral*)getDeferral;
@end

#endif // __WGPPrintTaskRequest_DEFINED__

// Windows.Graphics.Printing.PrintTaskRequestedEventArgs
#ifndef __WGPPrintTaskRequestedEventArgs_DEFINED__
#define __WGPPrintTaskRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WGPPrintTaskRequestedEventArgs : RTObject
@property (readonly) WGPPrintTaskRequest* request;
@end

#endif // __WGPPrintTaskRequestedEventArgs_DEFINED__

// Windows.Graphics.Printing.PrintManager
#ifndef __WGPPrintManager_DEFINED__
#define __WGPPrintManager_DEFINED__

WINRT_EXPORT
@interface WGPPrintManager : RTObject
+ (WGPPrintManager*)getForCurrentView;
+ (void)showPrintUIAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (EventRegistrationToken)addPrintTaskRequestedEvent:(void (^)(WGPPrintManager*, WGPPrintTaskRequestedEventArgs*))del;
- (void)removePrintTaskRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WGPPrintManager_DEFINED__
