// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Devices.PointOfService.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::PointOfService {

struct WINRT_EBO BarcodeScanner :
    Windows::Devices::PointOfService::IBarcodeScanner,
    impl::require<BarcodeScanner, Windows::Devices::PointOfService::IBarcodeScanner2>
{
    BarcodeScanner(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::BarcodeScanner> GetDefaultAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::BarcodeScanner> FromIdAsync(hstring_view deviceId);
    static hstring GetDeviceSelector();
};

struct WINRT_EBO BarcodeScannerCapabilities :
    Windows::Devices::PointOfService::IBarcodeScannerCapabilities,
    impl::require<BarcodeScannerCapabilities, Windows::Devices::PointOfService::IBarcodeScannerCapabilities1>
{
    BarcodeScannerCapabilities(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BarcodeScannerDataReceivedEventArgs :
    Windows::Devices::PointOfService::IBarcodeScannerDataReceivedEventArgs
{
    BarcodeScannerDataReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BarcodeScannerErrorOccurredEventArgs :
    Windows::Devices::PointOfService::IBarcodeScannerErrorOccurredEventArgs
{
    BarcodeScannerErrorOccurredEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BarcodeScannerImagePreviewReceivedEventArgs :
    Windows::Devices::PointOfService::IBarcodeScannerImagePreviewReceivedEventArgs
{
    BarcodeScannerImagePreviewReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BarcodeScannerReport :
    Windows::Devices::PointOfService::IBarcodeScannerReport
{
    BarcodeScannerReport(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BarcodeScannerStatusUpdatedEventArgs :
    Windows::Devices::PointOfService::IBarcodeScannerStatusUpdatedEventArgs
{
    BarcodeScannerStatusUpdatedEventArgs(std::nullptr_t) noexcept {}
};

struct BarcodeSymbologies
{
    BarcodeSymbologies() = delete;
    static uint32_t Unknown();
    static uint32_t Ean8();
    static uint32_t Ean8Add2();
    static uint32_t Ean8Add5();
    static uint32_t Eanv();
    static uint32_t EanvAdd2();
    static uint32_t EanvAdd5();
    static uint32_t Ean13();
    static uint32_t Ean13Add2();
    static uint32_t Ean13Add5();
    static uint32_t Isbn();
    static uint32_t IsbnAdd5();
    static uint32_t Ismn();
    static uint32_t IsmnAdd2();
    static uint32_t IsmnAdd5();
    static uint32_t Issn();
    static uint32_t IssnAdd2();
    static uint32_t IssnAdd5();
    static uint32_t Ean99();
    static uint32_t Ean99Add2();
    static uint32_t Ean99Add5();
    static uint32_t Upca();
    static uint32_t UpcaAdd2();
    static uint32_t UpcaAdd5();
    static uint32_t Upce();
    static uint32_t UpceAdd2();
    static uint32_t UpceAdd5();
    static uint32_t UpcCoupon();
    static uint32_t TfStd();
    static uint32_t TfDis();
    static uint32_t TfInt();
    static uint32_t TfInd();
    static uint32_t TfMat();
    static uint32_t TfIata();
    static uint32_t Gs1DatabarType1();
    static uint32_t Gs1DatabarType2();
    static uint32_t Gs1DatabarType3();
    static uint32_t Code39();
    static uint32_t Code39Ex();
    static uint32_t Trioptic39();
    static uint32_t Code32();
    static uint32_t Pzn();
    static uint32_t Code93();
    static uint32_t Code93Ex();
    static uint32_t Code128();
    static uint32_t Gs1128();
    static uint32_t Gs1128Coupon();
    static uint32_t UccEan128();
    static uint32_t Sisac();
    static uint32_t Isbt();
    static uint32_t Codabar();
    static uint32_t Code11();
    static uint32_t Msi();
    static uint32_t Plessey();
    static uint32_t Telepen();
    static uint32_t Code16k();
    static uint32_t CodablockA();
    static uint32_t CodablockF();
    static uint32_t Codablock128();
    static uint32_t Code49();
    static uint32_t Aztec();
    static uint32_t DataCode();
    static uint32_t DataMatrix();
    static uint32_t HanXin();
    static uint32_t Maxicode();
    static uint32_t MicroPdf417();
    static uint32_t MicroQr();
    static uint32_t Pdf417();
    static uint32_t Qr();
    static uint32_t MsTag();
    static uint32_t Ccab();
    static uint32_t Ccc();
    static uint32_t Tlc39();
    static uint32_t AusPost();
    static uint32_t CanPost();
    static uint32_t ChinaPost();
    static uint32_t DutchKix();
    static uint32_t InfoMail();
    static uint32_t ItalianPost25();
    static uint32_t ItalianPost39();
    static uint32_t JapanPost();
    static uint32_t KoreanPost();
    static uint32_t SwedenPost();
    static uint32_t UkPost();
    static uint32_t UsIntelligent();
    static uint32_t UsIntelligentPkg();
    static uint32_t UsPlanet();
    static uint32_t UsPostNet();
    static uint32_t Us4StateFics();
    static uint32_t OcrA();
    static uint32_t OcrB();
    static uint32_t Micr();
    static uint32_t ExtendedBase();
    static hstring GetName(uint32_t scanDataType);
};

struct WINRT_EBO CashDrawer :
    Windows::Devices::PointOfService::ICashDrawer
{
    CashDrawer(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::CashDrawer> GetDefaultAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::CashDrawer> FromIdAsync(hstring_view deviceId);
    static hstring GetDeviceSelector();
};

struct WINRT_EBO CashDrawerCapabilities :
    Windows::Devices::PointOfService::ICashDrawerCapabilities
{
    CashDrawerCapabilities(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CashDrawerCloseAlarm :
    Windows::Devices::PointOfService::ICashDrawerCloseAlarm
{
    CashDrawerCloseAlarm(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CashDrawerClosedEventArgs :
    Windows::Devices::PointOfService::ICashDrawerEventSourceEventArgs
{
    CashDrawerClosedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CashDrawerEventSource :
    Windows::Devices::PointOfService::ICashDrawerEventSource
{
    CashDrawerEventSource(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CashDrawerOpenedEventArgs :
    Windows::Devices::PointOfService::ICashDrawerEventSourceEventArgs
{
    CashDrawerOpenedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CashDrawerStatus :
    Windows::Devices::PointOfService::ICashDrawerStatus
{
    CashDrawerStatus(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CashDrawerStatusUpdatedEventArgs :
    Windows::Devices::PointOfService::ICashDrawerStatusUpdatedEventArgs
{
    CashDrawerStatusUpdatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ClaimedBarcodeScanner :
    Windows::Devices::PointOfService::IClaimedBarcodeScanner,
    impl::require<ClaimedBarcodeScanner, Windows::Devices::PointOfService::IClaimedBarcodeScanner1>
{
    ClaimedBarcodeScanner(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ClaimedCashDrawer :
    Windows::Devices::PointOfService::IClaimedCashDrawer
{
    ClaimedCashDrawer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ClaimedJournalPrinter :
    Windows::Devices::PointOfService::IClaimedJournalPrinter
{
    ClaimedJournalPrinter(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ClaimedMagneticStripeReader :
    Windows::Devices::PointOfService::IClaimedMagneticStripeReader
{
    ClaimedMagneticStripeReader(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ClaimedPosPrinter :
    Windows::Devices::PointOfService::IClaimedPosPrinter
{
    ClaimedPosPrinter(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ClaimedReceiptPrinter :
    Windows::Devices::PointOfService::IClaimedReceiptPrinter
{
    ClaimedReceiptPrinter(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ClaimedSlipPrinter :
    Windows::Devices::PointOfService::IClaimedSlipPrinter
{
    ClaimedSlipPrinter(std::nullptr_t) noexcept {}
};

struct WINRT_EBO JournalPrintJob :
    Windows::Devices::PointOfService::IPosPrinterJob
{
    JournalPrintJob(std::nullptr_t) noexcept {}
};

struct WINRT_EBO JournalPrinterCapabilities :
    Windows::Devices::PointOfService::IJournalPrinterCapabilities
{
    JournalPrinterCapabilities(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MagneticStripeReader :
    Windows::Devices::PointOfService::IMagneticStripeReader
{
    MagneticStripeReader(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::MagneticStripeReader> GetDefaultAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::MagneticStripeReader> FromIdAsync(hstring_view deviceId);
    static hstring GetDeviceSelector();
};

struct WINRT_EBO MagneticStripeReaderAamvaCardDataReceivedEventArgs :
    Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs
{
    MagneticStripeReaderAamvaCardDataReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MagneticStripeReaderBankCardDataReceivedEventArgs :
    Windows::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs
{
    MagneticStripeReaderBankCardDataReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MagneticStripeReaderCapabilities :
    Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities
{
    MagneticStripeReaderCapabilities(std::nullptr_t) noexcept {}
};

struct MagneticStripeReaderCardTypes
{
    MagneticStripeReaderCardTypes() = delete;
    static uint32_t Unknown();
    static uint32_t Bank();
    static uint32_t Aamva();
    static uint32_t ExtendedBase();
};

struct MagneticStripeReaderEncryptionAlgorithms
{
    MagneticStripeReaderEncryptionAlgorithms() = delete;
    static uint32_t None();
    static uint32_t TripleDesDukpt();
    static uint32_t ExtendedBase();
};

struct WINRT_EBO MagneticStripeReaderErrorOccurredEventArgs :
    Windows::Devices::PointOfService::IMagneticStripeReaderErrorOccurredEventArgs
{
    MagneticStripeReaderErrorOccurredEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MagneticStripeReaderReport :
    Windows::Devices::PointOfService::IMagneticStripeReaderReport
{
    MagneticStripeReaderReport(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MagneticStripeReaderStatusUpdatedEventArgs :
    Windows::Devices::PointOfService::IMagneticStripeReaderStatusUpdatedEventArgs
{
    MagneticStripeReaderStatusUpdatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MagneticStripeReaderTrackData :
    Windows::Devices::PointOfService::IMagneticStripeReaderTrackData
{
    MagneticStripeReaderTrackData(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs :
    Windows::Devices::PointOfService::IMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs
{
    MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PosPrinter :
    Windows::Devices::PointOfService::IPosPrinter
{
    PosPrinter(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::PosPrinter> GetDefaultAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Devices::PointOfService::PosPrinter> FromIdAsync(hstring_view deviceId);
    static hstring GetDeviceSelector();
};

struct WINRT_EBO PosPrinterCapabilities :
    Windows::Devices::PointOfService::IPosPrinterCapabilities
{
    PosPrinterCapabilities(std::nullptr_t) noexcept {}
};

struct PosPrinterCharacterSetIds
{
    PosPrinterCharacterSetIds() = delete;
    static uint32_t Utf16LE();
    static uint32_t Ascii();
    static uint32_t Ansi();
};

struct WINRT_EBO PosPrinterReleaseDeviceRequestedEventArgs :
    Windows::Devices::PointOfService::IPosPrinterReleaseDeviceRequestedEventArgs
{
    PosPrinterReleaseDeviceRequestedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PosPrinterStatus :
    Windows::Devices::PointOfService::IPosPrinterStatus
{
    PosPrinterStatus(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PosPrinterStatusUpdatedEventArgs :
    Windows::Devices::PointOfService::IPosPrinterStatusUpdatedEventArgs
{
    PosPrinterStatusUpdatedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ReceiptPrintJob :
    Windows::Devices::PointOfService::IReceiptPrintJob
{
    ReceiptPrintJob(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ReceiptPrinterCapabilities :
    Windows::Devices::PointOfService::IReceiptPrinterCapabilities
{
    ReceiptPrinterCapabilities(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SlipPrintJob :
    Windows::Devices::PointOfService::IReceiptOrSlipJob
{
    SlipPrintJob(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SlipPrinterCapabilities :
    Windows::Devices::PointOfService::ISlipPrinterCapabilities
{
    SlipPrinterCapabilities(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UnifiedPosErrorData :
    Windows::Devices::PointOfService::IUnifiedPosErrorData
{
    UnifiedPosErrorData(std::nullptr_t) noexcept {}
};

}

}
