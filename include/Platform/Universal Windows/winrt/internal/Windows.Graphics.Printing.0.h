// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Graphics::Printing {

struct PrintPageDescription;

}

namespace Windows::Graphics::Printing {

using PrintPageDescription = ABI::Windows::Graphics::Printing::PrintPageDescription;

}

namespace ABI::Windows::Graphics::Printing {

struct IPrintDocumentSource;
struct IPrintManager;
struct IPrintManagerStatic;
struct IPrintManagerStatic2;
struct IPrintPageInfo;
struct IPrintTask;
struct IPrintTask2;
struct IPrintTaskCompletedEventArgs;
struct IPrintTaskOptions;
struct IPrintTaskOptionsCore;
struct IPrintTaskOptionsCoreProperties;
struct IPrintTaskOptionsCoreUIConfiguration;
struct IPrintTaskProgressingEventArgs;
struct IPrintTaskRequest;
struct IPrintTaskRequestedDeferral;
struct IPrintTaskRequestedEventArgs;
struct IPrintTaskSourceRequestedArgs;
struct IPrintTaskSourceRequestedDeferral;
struct IPrintTaskTargetDeviceSupport;
struct IStandardPrintTaskOptionsStatic;
struct IStandardPrintTaskOptionsStatic2;
struct PrintTaskSourceRequestedHandler;
struct PrintManager;
struct PrintPageInfo;
struct PrintTask;
struct PrintTaskCompletedEventArgs;
struct PrintTaskOptions;
struct PrintTaskProgressingEventArgs;
struct PrintTaskRequest;
struct PrintTaskRequestedDeferral;
struct PrintTaskRequestedEventArgs;
struct PrintTaskSourceRequestedArgs;
struct PrintTaskSourceRequestedDeferral;

}

namespace Windows::Graphics::Printing {

struct PrintTaskSourceRequestedHandler;
struct IPrintDocumentSource;
struct IPrintManager;
struct IPrintManagerStatic;
struct IPrintManagerStatic2;
struct IPrintPageInfo;
struct IPrintTask;
struct IPrintTask2;
struct IPrintTaskCompletedEventArgs;
struct IPrintTaskOptions;
struct IPrintTaskOptionsCore;
struct IPrintTaskOptionsCoreProperties;
struct IPrintTaskOptionsCoreUIConfiguration;
struct IPrintTaskProgressingEventArgs;
struct IPrintTaskRequest;
struct IPrintTaskRequestedDeferral;
struct IPrintTaskRequestedEventArgs;
struct IPrintTaskSourceRequestedArgs;
struct IPrintTaskSourceRequestedDeferral;
struct IPrintTaskTargetDeviceSupport;
struct IStandardPrintTaskOptionsStatic;
struct IStandardPrintTaskOptionsStatic2;
struct PrintManager;
struct PrintPageInfo;
struct PrintTask;
struct PrintTaskCompletedEventArgs;
struct PrintTaskOptions;
struct PrintTaskProgressingEventArgs;
struct PrintTaskRequest;
struct PrintTaskRequestedDeferral;
struct PrintTaskRequestedEventArgs;
struct PrintTaskSourceRequestedArgs;
struct PrintTaskSourceRequestedDeferral;
struct StandardPrintTaskOptions;

}

namespace Windows::Graphics::Printing {

template <typename T> struct impl_IPrintDocumentSource;
template <typename T> struct impl_IPrintManager;
template <typename T> struct impl_IPrintManagerStatic;
template <typename T> struct impl_IPrintManagerStatic2;
template <typename T> struct impl_IPrintPageInfo;
template <typename T> struct impl_IPrintTask;
template <typename T> struct impl_IPrintTask2;
template <typename T> struct impl_IPrintTaskCompletedEventArgs;
template <typename T> struct impl_IPrintTaskOptions;
template <typename T> struct impl_IPrintTaskOptionsCore;
template <typename T> struct impl_IPrintTaskOptionsCoreProperties;
template <typename T> struct impl_IPrintTaskOptionsCoreUIConfiguration;
template <typename T> struct impl_IPrintTaskProgressingEventArgs;
template <typename T> struct impl_IPrintTaskRequest;
template <typename T> struct impl_IPrintTaskRequestedDeferral;
template <typename T> struct impl_IPrintTaskRequestedEventArgs;
template <typename T> struct impl_IPrintTaskSourceRequestedArgs;
template <typename T> struct impl_IPrintTaskSourceRequestedDeferral;
template <typename T> struct impl_IPrintTaskTargetDeviceSupport;
template <typename T> struct impl_IStandardPrintTaskOptionsStatic;
template <typename T> struct impl_IStandardPrintTaskOptionsStatic2;
template <typename T> struct impl_PrintTaskSourceRequestedHandler;

}

namespace Windows::Graphics::Printing {

enum class PrintBinding
{
    Default = 0,
    NotAvailable = 1,
    PrinterCustom = 2,
    None = 3,
    Bale = 4,
    BindBottom = 5,
    BindLeft = 6,
    BindRight = 7,
    BindTop = 8,
    Booklet = 9,
    EdgeStitchBottom = 10,
    EdgeStitchLeft = 11,
    EdgeStitchRight = 12,
    EdgeStitchTop = 13,
    Fold = 14,
    JogOffset = 15,
    Trim = 16,
};

enum class PrintBordering
{
    Default = 0,
    NotAvailable = 1,
    PrinterCustom = 2,
    Bordered = 3,
    Borderless = 4,
};

enum class PrintCollation
{
    Default = 0,
    NotAvailable = 1,
    PrinterCustom = 2,
    Collated = 3,
    Uncollated = 4,
};

enum class PrintColorMode
{
    Default = 0,
    NotAvailable = 1,
    PrinterCustom = 2,
    Color = 3,
    Grayscale = 4,
    Monochrome = 5,
};

enum class PrintDuplex
{
    Default = 0,
    NotAvailable = 1,
    PrinterCustom = 2,
    OneSided = 3,
    TwoSidedShortEdge = 4,
    TwoSidedLongEdge = 5,
};

enum class PrintHolePunch
{
    Default = 0,
    NotAvailable = 1,
    PrinterCustom = 2,
    None = 3,
    LeftEdge = 4,
    RightEdge = 5,
    TopEdge = 6,
    BottomEdge = 7,
};

enum class PrintMediaSize
{
    Default = 0,
    NotAvailable = 1,
    PrinterCustom = 2,
    BusinessCard = 3,
    CreditCard = 4,
    IsoA0 = 5,
    IsoA1 = 6,
    IsoA10 = 7,
    IsoA2 = 8,
    IsoA3 = 9,
    IsoA3Extra = 10,
    IsoA3Rotated = 11,
    IsoA4 = 12,
    IsoA4Extra = 13,
    IsoA4Rotated = 14,
    IsoA5 = 15,
    IsoA5Extra = 16,
    IsoA5Rotated = 17,
    IsoA6 = 18,
    IsoA6Rotated = 19,
    IsoA7 = 20,
    IsoA8 = 21,
    IsoA9 = 22,
    IsoB0 = 23,
    IsoB1 = 24,
    IsoB10 = 25,
    IsoB2 = 26,
    IsoB3 = 27,
    IsoB4 = 28,
    IsoB4Envelope = 29,
    IsoB5Envelope = 30,
    IsoB5Extra = 31,
    IsoB7 = 32,
    IsoB8 = 33,
    IsoB9 = 34,
    IsoC0 = 35,
    IsoC1 = 36,
    IsoC10 = 37,
    IsoC2 = 38,
    IsoC3 = 39,
    IsoC3Envelope = 40,
    IsoC4 = 41,
    IsoC4Envelope = 42,
    IsoC5 = 43,
    IsoC5Envelope = 44,
    IsoC6 = 45,
    IsoC6C5Envelope = 46,
    IsoC6Envelope = 47,
    IsoC7 = 48,
    IsoC8 = 49,
    IsoC9 = 50,
    IsoDLEnvelope = 51,
    IsoDLEnvelopeRotated = 52,
    IsoSRA3 = 53,
    Japan2LPhoto = 54,
    JapanChou3Envelope = 55,
    JapanChou3EnvelopeRotated = 56,
    JapanChou4Envelope = 57,
    JapanChou4EnvelopeRotated = 58,
    JapanDoubleHagakiPostcard = 59,
    JapanDoubleHagakiPostcardRotated = 60,
    JapanHagakiPostcard = 61,
    JapanHagakiPostcardRotated = 62,
    JapanKaku2Envelope = 63,
    JapanKaku2EnvelopeRotated = 64,
    JapanKaku3Envelope = 65,
    JapanKaku3EnvelopeRotated = 66,
    JapanLPhoto = 67,
    JapanQuadrupleHagakiPostcard = 68,
    JapanYou1Envelope = 69,
    JapanYou2Envelope = 70,
    JapanYou3Envelope = 71,
    JapanYou4Envelope = 72,
    JapanYou4EnvelopeRotated = 73,
    JapanYou6Envelope = 74,
    JapanYou6EnvelopeRotated = 75,
    JisB0 = 76,
    JisB1 = 77,
    JisB10 = 78,
    JisB2 = 79,
    JisB3 = 80,
    JisB4 = 81,
    JisB4Rotated = 82,
    JisB5 = 83,
    JisB5Rotated = 84,
    JisB6 = 85,
    JisB6Rotated = 86,
    JisB7 = 87,
    JisB8 = 88,
    JisB9 = 89,
    NorthAmerica10x11 = 90,
    NorthAmerica10x12 = 91,
    NorthAmerica10x14 = 92,
    NorthAmerica11x17 = 93,
    NorthAmerica14x17 = 94,
    NorthAmerica4x6 = 95,
    NorthAmerica4x8 = 96,
    NorthAmerica5x7 = 97,
    NorthAmerica8x10 = 98,
    NorthAmerica9x11 = 99,
    NorthAmericaArchitectureASheet = 100,
    NorthAmericaArchitectureBSheet = 101,
    NorthAmericaArchitectureCSheet = 102,
    NorthAmericaArchitectureDSheet = 103,
    NorthAmericaArchitectureESheet = 104,
    NorthAmericaCSheet = 105,
    NorthAmericaDSheet = 106,
    NorthAmericaESheet = 107,
    NorthAmericaExecutive = 108,
    NorthAmericaGermanLegalFanfold = 109,
    NorthAmericaGermanStandardFanfold = 110,
    NorthAmericaLegal = 111,
    NorthAmericaLegalExtra = 112,
    NorthAmericaLetter = 113,
    NorthAmericaLetterExtra = 114,
    NorthAmericaLetterPlus = 115,
    NorthAmericaLetterRotated = 116,
    NorthAmericaMonarchEnvelope = 117,
    NorthAmericaNote = 118,
    NorthAmericaNumber10Envelope = 119,
    NorthAmericaNumber10EnvelopeRotated = 120,
    NorthAmericaNumber11Envelope = 121,
    NorthAmericaNumber12Envelope = 122,
    NorthAmericaNumber14Envelope = 123,
    NorthAmericaNumber9Envelope = 124,
    NorthAmericaPersonalEnvelope = 125,
    NorthAmericaQuarto = 126,
    NorthAmericaStatement = 127,
    NorthAmericaSuperA = 128,
    NorthAmericaSuperB = 129,
    NorthAmericaTabloid = 130,
    NorthAmericaTabloidExtra = 131,
    OtherMetricA3Plus = 132,
    OtherMetricA4Plus = 133,
    OtherMetricFolio = 134,
    OtherMetricInviteEnvelope = 135,
    OtherMetricItalianEnvelope = 136,
    Prc10Envelope = 137,
    Prc10EnvelopeRotated = 138,
    Prc16K = 139,
    Prc16KRotated = 140,
    Prc1Envelope = 141,
    Prc1EnvelopeRotated = 142,
    Prc2Envelope = 143,
    Prc2EnvelopeRotated = 144,
    Prc32K = 145,
    Prc32KBig = 146,
    Prc32KRotated = 147,
    Prc3Envelope = 148,
    Prc3EnvelopeRotated = 149,
    Prc4Envelope = 150,
    Prc4EnvelopeRotated = 151,
    Prc5Envelope = 152,
    Prc5EnvelopeRotated = 153,
    Prc6Envelope = 154,
    Prc6EnvelopeRotated = 155,
    Prc7Envelope = 156,
    Prc7EnvelopeRotated = 157,
    Prc8Envelope = 158,
    Prc8EnvelopeRotated = 159,
    Prc9Envelope = 160,
    Prc9EnvelopeRotated = 161,
    Roll04Inch = 162,
    Roll06Inch = 163,
    Roll08Inch = 164,
    Roll12Inch = 165,
    Roll15Inch = 166,
    Roll18Inch = 167,
    Roll22Inch = 168,
    Roll24Inch = 169,
    Roll30Inch = 170,
    Roll36Inch = 171,
    Roll54Inch = 172,
};

enum class PrintMediaType
{
    Default = 0,
    NotAvailable = 1,
    PrinterCustom = 2,
    AutoSelect = 3,
    Archival = 4,
    BackPrintFilm = 5,
    Bond = 6,
    CardStock = 7,
    Continuous = 8,
    EnvelopePlain = 9,
    EnvelopeWindow = 10,
    Fabric = 11,
    HighResolution = 12,
    Label = 13,
    MultiLayerForm = 14,
    MultiPartForm = 15,
    Photographic = 16,
    PhotographicFilm = 17,
    PhotographicGlossy = 18,
    PhotographicHighGloss = 19,
    PhotographicMatte = 20,
    PhotographicSatin = 21,
    PhotographicSemiGloss = 22,
    Plain = 23,
    Screen = 24,
    ScreenPaged = 25,
    Stationery = 26,
    TabStockFull = 27,
    TabStockPreCut = 28,
    Transparency = 29,
    TShirtTransfer = 30,
    None = 31,
};

enum class PrintOrientation
{
    Default = 0,
    NotAvailable = 1,
    PrinterCustom = 2,
    Portrait = 3,
    PortraitFlipped = 4,
    Landscape = 5,
    LandscapeFlipped = 6,
};

enum class PrintQuality
{
    Default = 0,
    NotAvailable = 1,
    PrinterCustom = 2,
    Automatic = 3,
    Draft = 4,
    Fax = 5,
    High = 6,
    Normal = 7,
    Photographic = 8,
    Text = 9,
};

enum class PrintStaple
{
    Default = 0,
    NotAvailable = 1,
    PrinterCustom = 2,
    None = 3,
    StapleTopLeft = 4,
    StapleTopRight = 5,
    StapleBottomLeft = 6,
    StapleBottomRight = 7,
    StapleDualLeft = 8,
    StapleDualRight = 9,
    StapleDualTop = 10,
    StapleDualBottom = 11,
    SaddleStitch = 12,
};

enum class PrintTaskCompletion
{
    Abandoned = 0,
    Canceled = 1,
    Failed = 2,
    Submitted = 3,
};

}

}
