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

// WindowsDevicesPointOfService.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.PointOfService.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesPointOfService.h"
#include "WindowsDevicesPointOfService_priv.h"

@implementation WDPICommonPosPrintStationCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isPrinterPresent {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPrinterPresent(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDualColorSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDualColorSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDPPosPrinterColorCapabilities)colorCartridgeCapabilities {
    ABI::Windows::Devices::PointOfService::PosPrinterColorCapabilities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorCartridgeCapabilities(&unmarshalledReturn));
    return (WDPPosPrinterColorCapabilities)unmarshalledReturn;
}

- (WDPPosPrinterCartridgeSensors)cartridgeSensors {
    ABI::Windows::Devices::PointOfService::PosPrinterCartridgeSensors unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_CartridgeSensors(&unmarshalledReturn));
    return (WDPPosPrinterCartridgeSensors)unmarshalledReturn;
}

- (BOOL)isBoldSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBoldSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isItalicSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsItalicSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isUnderlineSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsUnderlineSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDoubleHighPrintSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleHighPrintSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDoubleWidePrintSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleWidePrintSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDoubleHighDoubleWidePrintSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleHighDoubleWidePrintSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperEmptySensorSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperEmptySensorSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperNearEndSensorSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperNearEndSensorSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* unsigned int */)supportedCharactersPerLine {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedCharactersPerLine(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

@end

@implementation WDPICommonReceiptSlipCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isBarcodeSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBarcodeSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isBitmapSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBitmapSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isLeft90RotationSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsLeft90RotationSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isRight90RotationSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsRight90RotationSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)is180RotationSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Is180RotationSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPrintAreaSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPrintAreaSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDPPosPrinterRuledLineCapabilities)ruledLineCapabilities {
    ABI::Windows::Devices::PointOfService::PosPrinterRuledLineCapabilities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_RuledLineCapabilities(&unmarshalledReturn));
    return (WDPPosPrinterRuledLineCapabilities)unmarshalledReturn;
}

- (NSArray* /* WDPPosPrinterRotation */)supportedBarcodeRotations {
    ComPtr<IVectorView<ABI::Windows::Devices::PointOfService::PosPrinterRotation>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedBarcodeRotations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDPPosPrinterRotation_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDPPosPrinterRotation */)supportedBitmapRotations {
    ComPtr<IVectorView<ABI::Windows::Devices::PointOfService::PosPrinterRotation>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedBitmapRotations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDPPosPrinterRotation_create(unmarshalledReturn.Get());
}

- (BOOL)isPrinterPresent {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPrinterPresent(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDualColorSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDualColorSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDPPosPrinterColorCapabilities)colorCartridgeCapabilities {
    ABI::Windows::Devices::PointOfService::PosPrinterColorCapabilities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorCartridgeCapabilities(&unmarshalledReturn));
    return (WDPPosPrinterColorCapabilities)unmarshalledReturn;
}

- (WDPPosPrinterCartridgeSensors)cartridgeSensors {
    ABI::Windows::Devices::PointOfService::PosPrinterCartridgeSensors unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_CartridgeSensors(&unmarshalledReturn));
    return (WDPPosPrinterCartridgeSensors)unmarshalledReturn;
}

- (BOOL)isBoldSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBoldSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isItalicSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsItalicSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isUnderlineSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsUnderlineSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDoubleHighPrintSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleHighPrintSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDoubleWidePrintSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleWidePrintSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDoubleHighDoubleWidePrintSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleHighDoubleWidePrintSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperEmptySensorSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperEmptySensorSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperNearEndSensorSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperNearEndSensorSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* unsigned int */)supportedCharactersPerLine {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedCharactersPerLine(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

@end

@implementation WDPIPosPrinterJob

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinterJob> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)print:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->Print(nsStrToHstr(data).Get()));
}

- (void)printLine:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintLine(nsStrToHstr(data).Get()));
}

- (void)printNewline {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintNewline());
}

- (void)executeAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->ExecuteAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WDPIReceiptOrSlipJob

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setBarcodeRotation:(WDPPosPrinterRotation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->SetBarcodeRotation((ABI::Windows::Devices::PointOfService::PosPrinterRotation)value));
}

- (void)setPrintRotation:(WDPPosPrinterRotation)value includeBitmaps:(BOOL)includeBitmaps {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetPrintRotation((ABI::Windows::Devices::PointOfService::PosPrinterRotation)value, (boolean)includeBitmaps));
}

- (void)setPrintArea:(WFRect*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->SetPrintArea(*[value internalStruct]));
}

- (void)setBitmap:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->SetBitmap(bitmapNumber,
                                           _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                           (ABI::Windows::Devices::PointOfService::PosPrinterAlignment)alignment));
}

- (void)setBitmapCustomWidthStandardAlign:(unsigned int)bitmapNumber
                                   bitmap:(WGIBitmapFrame*)bitmap
                                alignment:(WDPPosPrinterAlignment)alignment
                                    width:(unsigned int)width {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetBitmapCustomWidthStandardAlign(bitmapNumber,
                                                    _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                    (ABI::Windows::Devices::PointOfService::PosPrinterAlignment)alignment,
                                                    width));
}

- (void)setCustomAlignedBitmap:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->SetCustomAlignedBitmap(bitmapNumber,
                                                        _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                        alignmentDistance));
}

- (void)setBitmapCustomWidthCustomAlign:(unsigned int)bitmapNumber
                                 bitmap:(WGIBitmapFrame*)bitmap
                      alignmentDistance:(unsigned int)alignmentDistance
                                  width:(unsigned int)width {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetBitmapCustomWidthCustomAlign(bitmapNumber,
                                                  _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                  alignmentDistance,
                                                  width));
}

- (void)printSavedBitmap:(unsigned int)bitmapNumber {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintSavedBitmap(bitmapNumber));
}

- (void)drawRuledLine:(NSString*)positionList
        lineDirection:(WDPPosPrinterLineDirection)lineDirection
            lineWidth:(unsigned int)lineWidth
            lineStyle:(WDPPosPrinterLineStyle)lineStyle
            lineColor:(unsigned int)lineColor {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->DrawRuledLine(nsStrToHstr(positionList).Get(),
                                               (ABI::Windows::Devices::PointOfService::PosPrinterLineDirection)lineDirection,
                                               lineWidth,
                                               (ABI::Windows::Devices::PointOfService::PosPrinterLineStyle)lineStyle,
                                               lineColor));
}

- (void)printBarcode:(NSString*)data
           symbology:(unsigned int)symbology
              height:(unsigned int)height
               width:(unsigned int)width
        textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition
           alignment:(WDPPosPrinterAlignment)alignment {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintBarcode(nsStrToHstr(data).Get(),
                                              symbology,
                                              height,
                                              width,
                                              (ABI::Windows::Devices::PointOfService::PosPrinterBarcodeTextPosition)textPosition,
                                              (ABI::Windows::Devices::PointOfService::PosPrinterAlignment)alignment));
}

- (void)printBarcodeCustomAlign:(NSString*)data
                      symbology:(unsigned int)symbology
                         height:(unsigned int)height
                          width:(unsigned int)width
                   textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition
              alignmentDistance:(unsigned int)alignmentDistance {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintBarcodeCustomAlign(nsStrToHstr(data).Get(),
                                                         symbology,
                                                         height,
                                                         width,
                                                         (ABI::Windows::Devices::PointOfService::PosPrinterBarcodeTextPosition)textPosition,
                                                         alignmentDistance));
}

- (void)printBitmap:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintBitmap(_getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                             (ABI::Windows::Devices::PointOfService::PosPrinterAlignment)alignment));
}

- (void)printBitmapCustomWidthStandardAlign:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment width:(unsigned int)width {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(
        _comInst->PrintBitmapCustomWidthStandardAlign(_getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                      (ABI::Windows::Devices::PointOfService::PosPrinterAlignment)alignment,
                                                      width));
}

- (void)printCustomAlignedBitmap:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintCustomAlignedBitmap(_getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                          alignmentDistance));
}

- (void)printBitmapCustomWidthCustomAlign:(WGIBitmapFrame*)bitmap
                        alignmentDistance:(unsigned int)alignmentDistance
                                    width:(unsigned int)width {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(
        _comInst->PrintBitmapCustomWidthCustomAlign(_getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                    alignmentDistance,
                                                    width));
}

- (void)print:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->Print(nsStrToHstr(data).Get()));
}

- (void)printLine:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintLine(nsStrToHstr(data).Get()));
}

- (void)printNewline {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintNewline());
}

- (void)executeAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->ExecuteAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WDPICommonClaimedPosPrinterStation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setCharactersPerLine:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_CharactersPerLine(value));
}

- (unsigned int)charactersPerLine {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CharactersPerLine(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLineHeight:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_LineHeight(value));
}

- (unsigned int)lineHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLineSpacing:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_LineSpacing(value));
}

- (unsigned int)lineSpacing {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineSpacing(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)lineWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIsLetterQuality:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsLetterQuality((boolean)value));
}

- (BOOL)isLetterQuality {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsLetterQuality(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperNearEnd {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperNearEnd(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setColorCartridge:(WDPPosPrinterColorCartridge)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ColorCartridge((ABI::Windows::Devices::PointOfService::PosPrinterColorCartridge)value));
}

- (WDPPosPrinterColorCartridge)colorCartridge {
    ABI::Windows::Devices::PointOfService::PosPrinterColorCartridge unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorCartridge(&unmarshalledReturn));
    return (WDPPosPrinterColorCartridge)unmarshalledReturn;
}

- (BOOL)isCoverOpen {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCoverOpen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCartridgeRemoved {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCartridgeRemoved(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCartridgeEmpty {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCartridgeEmpty(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isHeadCleaning {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsHeadCleaning(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperEmpty {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperEmpty(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isReadyToPrint {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReadyToPrint(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)validateData:(NSString*)data {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->ValidateData(nsStrToHstr(data).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDPICashDrawerEventSourceEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawerEventSourceEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPCashDrawer*)cashDrawer {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerEventSourceEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CashDrawer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPCashDrawer>(unmarshalledReturn.Get());
}

@end

@implementation WDPUnifiedPosErrorData

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IUnifiedPosErrorData> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)message {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IUnifiedPosErrorData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDPUnifiedPosErrorSeverity)severity {
    ABI::Windows::Devices::PointOfService::UnifiedPosErrorSeverity unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IUnifiedPosErrorData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Severity(&unmarshalledReturn));
    return (WDPUnifiedPosErrorSeverity)unmarshalledReturn;
}

- (WDPUnifiedPosErrorReason)reason {
    ABI::Windows::Devices::PointOfService::UnifiedPosErrorReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IUnifiedPosErrorData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reason(&unmarshalledReturn));
    return (WDPUnifiedPosErrorReason)unmarshalledReturn;
}

- (unsigned int)extendedReason {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IUnifiedPosErrorData>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedReason(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDPBarcodeScannerStatusUpdatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeScannerStatusUpdatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPBarcodeScannerStatus)status {
    ABI::Windows::Devices::PointOfService::BarcodeScannerStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScannerStatusUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDPBarcodeScannerStatus)unmarshalledReturn;
}

- (unsigned int)extendedStatus {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScannerStatusUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedStatus(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDPBarcodeSymbologies

ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeSymbologiesStatics> WDPIBarcodeSymbologiesStatics_inst() {
    ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeSymbologiesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.PointOfService.BarcodeSymbologies").Get(),
                                                       &inst));
    return inst;
}

+ (unsigned int)unknown {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Unknown(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ean8 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ean8(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ean8Add2 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ean8Add2(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ean8Add5 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ean8Add5(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)eanv {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Eanv(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)eanvAdd2 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EanvAdd2(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)eanvAdd5 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EanvAdd5(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ean13 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ean13(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ean13Add2 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ean13Add2(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ean13Add5 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ean13Add5(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)isbn {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Isbn(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)isbnAdd5 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsbnAdd5(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ismn {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ismn(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ismnAdd2 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsmnAdd2(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ismnAdd5 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsmnAdd5(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)issn {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Issn(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)issnAdd2 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IssnAdd2(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)issnAdd5 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IssnAdd5(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ean99 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ean99(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ean99Add2 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ean99Add2(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ean99Add5 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ean99Add5(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)upca {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Upca(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)upcaAdd2 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UpcaAdd2(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)upcaAdd5 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UpcaAdd5(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)upce {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Upce(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)upceAdd2 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UpceAdd2(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)upceAdd5 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UpceAdd5(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)upcCoupon {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UpcCoupon(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)tfStd {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TfStd(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)tfDis {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TfDis(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)tfInt {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TfInt(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)tfInd {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TfInd(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)tfMat {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TfMat(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)tfIata {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TfIata(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)gs1DatabarType1 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gs1DatabarType1(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)gs1DatabarType2 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gs1DatabarType2(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)gs1DatabarType3 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gs1DatabarType3(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)code39 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Code39(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)code39Ex {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Code39Ex(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)trioptic39 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Trioptic39(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)code32 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Code32(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)pzn {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Pzn(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)code93 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Code93(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)code93Ex {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Code93Ex(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)code128 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Code128(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)gs1128 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gs1128(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)gs1128Coupon {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gs1128Coupon(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)uccEan128 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UccEan128(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)sisac {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sisac(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)isbt {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Isbt(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)codabar {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Codabar(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)code11 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Code11(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)msi {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Msi(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)plessey {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Plessey(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)telepen {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Telepen(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)code16k {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Code16k(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)codablockA {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CodablockA(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)codablockF {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CodablockF(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)codablock128 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Codablock128(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)code49 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Code49(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)aztec {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Aztec(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)dataCode {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DataCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)dataMatrix {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DataMatrix(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)hanXin {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HanXin(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)maxicode {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Maxicode(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)microPdf417 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MicroPdf417(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)microQr {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MicroQr(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)pdf417 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Pdf417(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)qr {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Qr(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)msTag {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MsTag(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ccab {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ccab(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ccc {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ccc(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)tlc39 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Tlc39(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ausPost {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AusPost(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)canPost {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CanPost(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)chinaPost {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ChinaPost(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)dutchKix {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DutchKix(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)infoMail {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_InfoMail(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)italianPost25 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ItalianPost25(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)italianPost39 {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ItalianPost39(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)japanPost {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_JapanPost(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)koreanPost {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KoreanPost(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)swedenPost {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SwedenPost(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ukPost {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UkPost(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)usIntelligent {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UsIntelligent(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)usIntelligentPkg {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UsIntelligentPkg(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)usPlanet {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UsPlanet(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)usPostNet {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UsPostNet(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)us4StateFics {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Us4StateFics(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ocrA {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OcrA(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ocrB {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OcrB(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)micr {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Micr(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)extendedBase {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExtendedBase(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (NSString*)getName:(unsigned int)scanDataType {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIBarcodeSymbologiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetName(scanDataType, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDPBarcodeScannerReport

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeScannerReport> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)scanDataType {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScannerReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScanDataType(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)scanData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScannerReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScanData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)scanDataLabel {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScannerReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScanDataLabel(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WDPBarcodeScannerDataReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeScannerDataReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPBarcodeScannerReport*)report {
    ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeScannerReport> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScannerDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Report(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPBarcodeScannerReport>(unmarshalledReturn.Get());
}

@end

@implementation WDPBarcodeScannerErrorOccurredEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeScannerErrorOccurredEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPBarcodeScannerReport*)partialInputData {
    ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeScannerReport> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScannerErrorOccurredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PartialInputData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPBarcodeScannerReport>(unmarshalledReturn.Get());
}

- (BOOL)isRetriable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScannerErrorOccurredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsRetriable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDPUnifiedPosErrorData*)errorData {
    ComPtr<ABI::Windows::Devices::PointOfService::IUnifiedPosErrorData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScannerErrorOccurredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPUnifiedPosErrorData>(unmarshalledReturn.Get());
}

@end

@implementation WDPBarcodeScannerImagePreviewReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeScannerImagePreviewReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIRandomAccessStreamWithContentType>*)preview {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScannerImagePreviewReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Preview(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamWithContentType>(unmarshalledReturn.Get());
}

@end

@implementation WDPBarcodeScannerCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeScannerCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPUnifiedPosPowerReportingType)powerReportingType {
    ABI::Windows::Devices::PointOfService::UnifiedPosPowerReportingType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScannerCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_PowerReportingType(&unmarshalledReturn));
    return (WDPUnifiedPosPowerReportingType)unmarshalledReturn;
}

- (BOOL)isStatisticsReportingSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScannerCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStatisticsReportingSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isStatisticsUpdatingSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScannerCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStatisticsUpdatingSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isImagePreviewSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScannerCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsImagePreviewSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isSoftwareTriggerSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScannerCapabilities1>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSoftwareTriggerSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDPBarcodeScanner

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeScanner> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeScannerStatics> WDPIBarcodeScannerStatics_inst() {
    ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeScannerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.PointOfService.BarcodeScanner").Get(),
                                                       &inst));
    return inst;
}

+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPBarcodeScanner*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::BarcodeScanner*>> unmarshalledReturn;
    auto _comInst = WDPIBarcodeScannerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::PointOfService::BarcodeScanner*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::BarcodeScanner*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeScanner> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDPBarcodeScanner>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDPBarcodeScanner*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::BarcodeScanner*>> unmarshalledReturn;
    auto _comInst = WDPIBarcodeScannerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::PointOfService::BarcodeScanner*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::BarcodeScanner*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeScanner> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDPBarcodeScanner>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIBarcodeScannerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDPBarcodeScannerCapabilities*)capabilities {
    ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeScannerCapabilities> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->get_Capabilities(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPBarcodeScannerCapabilities>(unmarshalledReturn.Get());
}

- (void)claimScannerAsyncWithSuccess:(void (^)(WDPClaimedBarcodeScanner*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::ClaimedBarcodeScanner*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->ClaimScannerAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::PointOfService::ClaimedBarcodeScanner*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::ClaimedBarcodeScanner*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDPClaimedBarcodeScanner>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)checkHealthAsync:(WDPUnifiedPosHealthCheckLevel)level success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScanner>(self);
    THROW_NS_IF_FAILED(
        _comInst->CheckHealthAsync((ABI::Windows::Devices::PointOfService::UnifiedPosHealthCheckLevel)level, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getSupportedSymbologiesAsyncWithSuccess:(void (^)(NSArray* /* unsigned int */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<unsigned int>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->GetSupportedSymbologiesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<unsigned int>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<unsigned int>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<unsigned int>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_UInt32_create(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)isSymbologySupportedAsync:(unsigned int)barcodeSymbology success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->IsSymbologySupportedAsync(barcodeSymbology, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)retrieveStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories
                        success:(void (^)(RTObject<WSSIBuffer>*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->RetrieveStatisticsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(statisticsCategories).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (NSArray* /* NSString * */)getSupportedProfiles {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->GetSupportedProfiles(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (BOOL)isProfileSupported:(NSString*)profile {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->IsProfileSupported(nsStrToHstr(profile).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addStatusUpdatedEvent:(void (^)(WDPBarcodeScanner*, WDPBarcodeScannerStatusUpdatedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->add_StatusUpdated(
        Make<
            ITypedEventHandler_Windows_Devices_PointOfService_BarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerStatusUpdatedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStatusUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StatusUpdated(token));
}

- (NSString*)videoDeviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IBarcodeScanner2>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoDeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDPClaimedBarcodeScanner

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsDisabledOnDataReceived:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsDisabledOnDataReceived((boolean)value));
}

- (BOOL)isDisabledOnDataReceived {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDisabledOnDataReceived(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsDecodeDataEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsDecodeDataEnabled((boolean)value));
}

- (BOOL)isDecodeDataEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDecodeDataEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)enableAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->EnableAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)disableAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->DisableAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)retainDevice {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->RetainDevice());
}

- (RTObject<WFIAsyncAction>*)setActiveSymbologiesAsync:(id<NSFastEnumeration> /* unsigned int */)symbologies {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->SetActiveSymbologiesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<unsigned int>::type>*>(
            ConvertToIterable<unsigned int, unsigned int>(symbologies).Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)resetStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(
        _comInst->ResetStatisticsAsync(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                           ConvertToIterable<NSString, HSTRING>(statisticsCategories).Get()),
                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)updateStatisticsAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, NSString * > */)statistics {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateStatisticsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, HSTRING>*, IKeyValuePair<HSTRING, HSTRING>*>>::type>*>(
            ConvertToIterable<
                RTProxiedKeyValuePair,
                ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, HSTRING>*, IKeyValuePair<HSTRING, HSTRING>*>,
                RTProxiedKeyValuePair_NSString_NSString_create>(statistics)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)setActiveProfileAsync:(NSString*)profile {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->SetActiveProfileAsync(nsStrToHstr(profile).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addDataReceivedEvent:(void (^)(WDPClaimedBarcodeScanner*, WDPBarcodeScannerDataReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->add_DataReceived(
        Make<
            ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerDataReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDataReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DataReceived(token));
}

- (EventRegistrationToken)addTriggerPressedEvent:(void (^)(RTObject*, WDPClaimedBarcodeScanner*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->add_TriggerPressed(Make<EventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner>(handler).Get(),
                                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTriggerPressedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TriggerPressed(token));
}

- (EventRegistrationToken)addTriggerReleasedEvent:(void (^)(RTObject*, WDPClaimedBarcodeScanner*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->add_TriggerReleased(Make<EventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner>(handler).Get(),
                                                     &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTriggerReleasedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TriggerReleased(token));
}

- (EventRegistrationToken)addReleaseDeviceRequestedEvent:(void (^)(RTObject*, WDPClaimedBarcodeScanner*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ReleaseDeviceRequested(Make<EventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner>(handler).Get(),
                                             &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReleaseDeviceRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReleaseDeviceRequested(token));
}

- (EventRegistrationToken)addImagePreviewReceivedEvent:(void (^)(WDPClaimedBarcodeScanner*,
                                                                 WDPBarcodeScannerImagePreviewReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->add_ImagePreviewReceived(
        Make<
            ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerImagePreviewReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeImagePreviewReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ImagePreviewReceived(token));
}

- (EventRegistrationToken)addErrorOccurredEvent:(void (^)(WDPClaimedBarcodeScanner*, WDPBarcodeScannerErrorOccurredEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->add_ErrorOccurred(
        Make<
            ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerErrorOccurredEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeErrorOccurredEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ErrorOccurred(token));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (RTObject<WFIAsyncAction>*)startSoftwareTriggerAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner1>(self);
    THROW_NS_IF_FAILED(_comInst->StartSoftwareTriggerAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)stopSoftwareTriggerAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner1>(self);
    THROW_NS_IF_FAILED(_comInst->StopSoftwareTriggerAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WDPMagneticStripeReaderEncryptionAlgorithms

ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderEncryptionAlgorithmsStatics>
WDPIMagneticStripeReaderEncryptionAlgorithmsStatics_inst() {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderEncryptionAlgorithmsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.PointOfService.MagneticStripeReaderEncryptionAlgorithms").Get(), &inst));
    return inst;
}

+ (unsigned int)none {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIMagneticStripeReaderEncryptionAlgorithmsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_None(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)tripleDesDukpt {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIMagneticStripeReaderEncryptionAlgorithmsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TripleDesDukpt(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)extendedBase {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIMagneticStripeReaderEncryptionAlgorithmsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExtendedBase(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDPMagneticStripeReaderCardTypes

ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderCardTypesStatics> WDPIMagneticStripeReaderCardTypesStatics_inst() {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderCardTypesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.PointOfService.MagneticStripeReaderCardTypes").Get(), &inst));
    return inst;
}

+ (unsigned int)unknown {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIMagneticStripeReaderCardTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Unknown(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)bank {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIMagneticStripeReaderCardTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Bank(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)aamva {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIMagneticStripeReaderCardTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Aamva(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)extendedBase {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIMagneticStripeReaderCardTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExtendedBase(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDPMagneticStripeReaderTrackData

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderTrackData> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderTrackData>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)discretionaryData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderTrackData>(self);
    THROW_NS_IF_FAILED(_comInst->get_DiscretionaryData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)encryptedData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderTrackData>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncryptedData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WDPMagneticStripeReaderReport

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderReport> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)cardType {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_CardType(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDPMagneticStripeReaderTrackData*)track1 {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderTrackData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Track1(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPMagneticStripeReaderTrackData>(unmarshalledReturn.Get());
}

- (WDPMagneticStripeReaderTrackData*)track2 {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderTrackData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Track2(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPMagneticStripeReaderTrackData>(unmarshalledReturn.Get());
}

- (WDPMagneticStripeReaderTrackData*)track3 {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderTrackData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Track3(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPMagneticStripeReaderTrackData>(unmarshalledReturn.Get());
}

- (WDPMagneticStripeReaderTrackData*)track4 {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderTrackData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Track4(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPMagneticStripeReaderTrackData>(unmarshalledReturn.Get());
}

- (NSDictionary* /* NSString *, NSString * */)properties {
    ComPtr<IMapView<HSTRING, HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_NSString_create(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)cardAuthenticationData {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_CardAuthenticationData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (unsigned int)cardAuthenticationDataLength {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_CardAuthenticationDataLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)additionalSecurityInformation {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdditionalSecurityInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WDPMagneticStripeReaderBankCardDataReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPMagneticStripeReaderReport*)report {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderReport> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Report(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPMagneticStripeReaderReport>(unmarshalledReturn.Get());
}

- (NSString*)accountNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccountNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)expirationDate {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationDate(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)serviceCode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ServiceCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)firstName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)middleInitial {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_MiddleInitial(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)surname {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Surname(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)suffix {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Suffix(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPMagneticStripeReaderReport*)report {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderReport> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Report(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPMagneticStripeReaderReport>(unmarshalledReturn.Get());
}

- (NSString*)licenseNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_LicenseNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)expirationDate {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpirationDate(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)restrictions {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Restrictions(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Class {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Class(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)endorsements {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Endorsements(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)birthDate {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_BirthDate(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)firstName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)surname {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Surname(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)suffix {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Suffix(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)gender {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Gender(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)hairColor {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_HairColor(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)eyeColor {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_EyeColor(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)height {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)weight {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Weight(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)address {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Address(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)city {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_City(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)state {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)postalCode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PostalCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPMagneticStripeReaderReport*)report {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderReport> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Report(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPMagneticStripeReaderReport>(unmarshalledReturn.Get());
}

@end

@implementation WDPMagneticStripeReaderErrorOccurredEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderErrorOccurredEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPMagneticStripeReaderTrackErrorType)track1Status {
    ABI::Windows::Devices::PointOfService::MagneticStripeReaderTrackErrorType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderErrorOccurredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Track1Status(&unmarshalledReturn));
    return (WDPMagneticStripeReaderTrackErrorType)unmarshalledReturn;
}

- (WDPMagneticStripeReaderTrackErrorType)track2Status {
    ABI::Windows::Devices::PointOfService::MagneticStripeReaderTrackErrorType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderErrorOccurredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Track2Status(&unmarshalledReturn));
    return (WDPMagneticStripeReaderTrackErrorType)unmarshalledReturn;
}

- (WDPMagneticStripeReaderTrackErrorType)track3Status {
    ABI::Windows::Devices::PointOfService::MagneticStripeReaderTrackErrorType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderErrorOccurredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Track3Status(&unmarshalledReturn));
    return (WDPMagneticStripeReaderTrackErrorType)unmarshalledReturn;
}

- (WDPMagneticStripeReaderTrackErrorType)track4Status {
    ABI::Windows::Devices::PointOfService::MagneticStripeReaderTrackErrorType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderErrorOccurredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Track4Status(&unmarshalledReturn));
    return (WDPMagneticStripeReaderTrackErrorType)unmarshalledReturn;
}

- (WDPUnifiedPosErrorData*)errorData {
    ComPtr<ABI::Windows::Devices::PointOfService::IUnifiedPosErrorData> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderErrorOccurredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPUnifiedPosErrorData>(unmarshalledReturn.Get());
}

- (WDPMagneticStripeReaderReport*)partialInputData {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderReport> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderErrorOccurredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PartialInputData(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPMagneticStripeReaderReport>(unmarshalledReturn.Get());
}

@end

@implementation WDPMagneticStripeReaderStatusUpdatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderStatusUpdatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPMagneticStripeReaderStatus)status {
    ABI::Windows::Devices::PointOfService::MagneticStripeReaderStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderStatusUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WDPMagneticStripeReaderStatus)unmarshalledReturn;
}

- (unsigned int)extendedStatus {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderStatusUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedStatus(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDPMagneticStripeReaderCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)cardAuthentication {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_CardAuthentication(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned int)supportedEncryptionAlgorithms {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedEncryptionAlgorithms(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDPMagneticStripeReaderAuthenticationLevel)authenticationLevel {
    ABI::Windows::Devices::PointOfService::MagneticStripeReaderAuthenticationLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_AuthenticationLevel(&unmarshalledReturn));
    return (WDPMagneticStripeReaderAuthenticationLevel)unmarshalledReturn;
}

- (BOOL)isIsoSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsIsoSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isJisOneSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsJisOneSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isJisTwoSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsJisTwoSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDPUnifiedPosPowerReportingType)powerReportingType {
    ABI::Windows::Devices::PointOfService::UnifiedPosPowerReportingType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_PowerReportingType(&unmarshalledReturn));
    return (WDPUnifiedPosPowerReportingType)unmarshalledReturn;
}

- (BOOL)isStatisticsReportingSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStatisticsReportingSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isStatisticsUpdatingSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStatisticsUpdatingSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isTrackDataMaskingSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTrackDataMaskingSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isTransmitSentinelsSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTransmitSentinelsSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDPClaimedMagneticStripeReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsDisabledOnDataReceived:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsDisabledOnDataReceived((boolean)value));
}

- (BOOL)isDisabledOnDataReceived {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDisabledOnDataReceived(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsDecodeDataEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsDecodeDataEnabled((boolean)value));
}

- (BOOL)isDecodeDataEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDecodeDataEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDeviceAuthenticated {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDeviceAuthenticated(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setDataEncryptionAlgorithm:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->put_DataEncryptionAlgorithm(value));
}

- (unsigned int)dataEncryptionAlgorithm {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataEncryptionAlgorithm(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTracksToRead:(WDPMagneticStripeReaderTrackIds)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->put_TracksToRead((ABI::Windows::Devices::PointOfService::MagneticStripeReaderTrackIds)value));
}

- (WDPMagneticStripeReaderTrackIds)tracksToRead {
    ABI::Windows::Devices::PointOfService::MagneticStripeReaderTrackIds unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_TracksToRead(&unmarshalledReturn));
    return (WDPMagneticStripeReaderTrackIds)unmarshalledReturn;
}

- (void)setIsTransmitSentinelsEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsTransmitSentinelsEnabled((boolean)value));
}

- (BOOL)isTransmitSentinelsEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTransmitSentinelsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)enableAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->EnableAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)disableAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->DisableAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)retainDevice {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->RetainDevice());
}

- (void)setErrorReportingType:(WDPMagneticStripeReaderErrorReportingType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetErrorReportingType((ABI::Windows::Devices::PointOfService::MagneticStripeReaderErrorReportingType)value));
}

- (void)retrieveDeviceAuthenticationDataAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->RetrieveDeviceAuthenticationDataAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)authenticateDeviceAsync:(NSArray* /* uint8_t */)responseToken {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    UINT32 __responseToken_ArrayLen = 0;
    bool __responseToken_IsTemp = false;
    uint8_t* __responseToken_Array = NULL;
    if (!ConvertToCArray<uint8_t>(responseToken, &__responseToken_ArrayLen, &__responseToken_Array, &__responseToken_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(
        _comInst->AuthenticateDeviceAsync(__responseToken_ArrayLen, __responseToken_Array, unmarshalledReturn.GetAddressOf()));
    if (__responseToken_IsTemp)
        CoTaskMemFree(__responseToken_Array);
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)deAuthenticateDeviceAsync:(NSArray* /* uint8_t */)responseToken {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    UINT32 __responseToken_ArrayLen = 0;
    bool __responseToken_IsTemp = false;
    uint8_t* __responseToken_Array = NULL;
    if (!ConvertToCArray<uint8_t>(responseToken, &__responseToken_ArrayLen, &__responseToken_Array, &__responseToken_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(
        _comInst->DeAuthenticateDeviceAsync(__responseToken_ArrayLen, __responseToken_Array, unmarshalledReturn.GetAddressOf()));
    if (__responseToken_IsTemp)
        CoTaskMemFree(__responseToken_Array);
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)updateKeyAsync:(NSString*)key keyName:(NSString*)keyName {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateKeyAsync(nsStrToHstr(key).Get(), nsStrToHstr(keyName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)resetStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(
        _comInst->ResetStatisticsAsync(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                           ConvertToIterable<NSString, HSTRING>(statisticsCategories).Get()),
                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)updateStatisticsAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, NSString * > */)statistics {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateStatisticsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, HSTRING>*, IKeyValuePair<HSTRING, HSTRING>*>>::type>*>(
            ConvertToIterable<
                RTProxiedKeyValuePair,
                ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, HSTRING>*, IKeyValuePair<HSTRING, HSTRING>*>,
                RTProxiedKeyValuePair_NSString_NSString_create>(statistics)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addBankCardDataReceivedEvent:(void (^)(WDPClaimedMagneticStripeReader*,
                                                                 WDPMagneticStripeReaderBankCardDataReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->add_BankCardDataReceived(
        Make<
            ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderBankCardDataReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBankCardDataReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BankCardDataReceived(token));
}

- (EventRegistrationToken)addAamvaCardDataReceivedEvent:(void (^)(WDPClaimedMagneticStripeReader*,
                                                                  WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->add_AamvaCardDataReceived(
        Make<
            ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderAamvaCardDataReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAamvaCardDataReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AamvaCardDataReceived(token));
}

- (EventRegistrationToken)addVendorSpecificDataReceivedEvent:
    (void (^)(WDPClaimedMagneticStripeReader*, WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->add_VendorSpecificDataReceived(
        Make<
            ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVendorSpecificDataReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VendorSpecificDataReceived(token));
}

- (EventRegistrationToken)addReleaseDeviceRequestedEvent:(void (^)(RTObject*, WDPClaimedMagneticStripeReader*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ReleaseDeviceRequested(Make<EventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader>(handler).Get(),
                                             &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReleaseDeviceRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReleaseDeviceRequested(token));
}

- (EventRegistrationToken)addErrorOccurredEvent:(void (^)(WDPClaimedMagneticStripeReader*,
                                                          WDPMagneticStripeReaderErrorOccurredEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->add_ErrorOccurred(
        Make<
            ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderErrorOccurredEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeErrorOccurredEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ErrorOccurred(token));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDPMagneticStripeReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderStatics> WDPIMagneticStripeReaderStatics_inst() {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.PointOfService.MagneticStripeReader").Get(),
                                                       &inst));
    return inst;
}

+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPMagneticStripeReader*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::MagneticStripeReader*>> unmarshalledReturn;
    auto _comInst = WDPIMagneticStripeReaderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::PointOfService::MagneticStripeReader*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::MagneticStripeReader*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReader> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDPMagneticStripeReader>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDPMagneticStripeReader*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::MagneticStripeReader*>> unmarshalledReturn;
    auto _comInst = WDPIMagneticStripeReaderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::PointOfService::MagneticStripeReader*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::MagneticStripeReader*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReader> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDPMagneticStripeReader>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIMagneticStripeReaderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDPMagneticStripeReaderCapabilities*)capabilities {
    ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderCapabilities> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_Capabilities(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPMagneticStripeReaderCapabilities>(unmarshalledReturn.Get());
}

- (NSArray* /* unsigned int */)supportedCardTypes {
    unsigned int* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedCardTypes(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt32_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (WDPMagneticStripeReaderAuthenticationProtocol)deviceAuthenticationProtocol {
    ABI::Windows::Devices::PointOfService::MagneticStripeReaderAuthenticationProtocol unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceAuthenticationProtocol(&unmarshalledReturn));
    return (WDPMagneticStripeReaderAuthenticationProtocol)unmarshalledReturn;
}

- (void)checkHealthAsync:(WDPUnifiedPosHealthCheckLevel)level success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(
        _comInst->CheckHealthAsync((ABI::Windows::Devices::PointOfService::UnifiedPosHealthCheckLevel)level, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)claimReaderAsyncWithSuccess:(void (^)(WDPClaimedMagneticStripeReader*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::ClaimedMagneticStripeReader*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->ClaimReaderAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::PointOfService::ClaimedMagneticStripeReader*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::ClaimedMagneticStripeReader*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDPClaimedMagneticStripeReader>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)retrieveStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories
                        success:(void (^)(RTObject<WSSIBuffer>*))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->RetrieveStatisticsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(statisticsCategories).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (WDPMagneticStripeReaderErrorReportingType)getErrorReportingType {
    ABI::Windows::Devices::PointOfService::MagneticStripeReaderErrorReportingType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->GetErrorReportingType(&unmarshalledReturn));
    return (WDPMagneticStripeReaderErrorReportingType)unmarshalledReturn;
}

- (EventRegistrationToken)addStatusUpdatedEvent:(void (^)(WDPMagneticStripeReader*,
                                                          WDPMagneticStripeReaderStatusUpdatedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->add_StatusUpdated(
        Make<
            ITypedEventHandler_Windows_Devices_PointOfService_MagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderStatusUpdatedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStatusUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IMagneticStripeReader>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StatusUpdated(token));
}

@end

@implementation WDPPosPrinterCharacterSetIds

ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinterCharacterSetIdsStatics> WDPIPosPrinterCharacterSetIdsStatics_inst() {
    ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinterCharacterSetIdsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.PointOfService.PosPrinterCharacterSetIds").Get(), &inst));
    return inst;
}

+ (unsigned int)utf16LE {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIPosPrinterCharacterSetIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Utf16LE(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ascii {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIPosPrinterCharacterSetIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ascii(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (unsigned int)ansi {
    unsigned int unmarshalledReturn;
    auto _comInst = WDPIPosPrinterCharacterSetIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ansi(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDPReceiptPrinterCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IReceiptPrinterCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)canCutPaper {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptPrinterCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanCutPaper(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isStampSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptPrinterCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStampSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDPPosPrinterMarkFeedCapabilities)markFeedCapabilities {
    ABI::Windows::Devices::PointOfService::PosPrinterMarkFeedCapabilities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptPrinterCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_MarkFeedCapabilities(&unmarshalledReturn));
    return (WDPPosPrinterMarkFeedCapabilities)unmarshalledReturn;
}

- (BOOL)isBarcodeSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBarcodeSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isBitmapSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBitmapSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isLeft90RotationSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsLeft90RotationSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isRight90RotationSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsRight90RotationSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)is180RotationSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Is180RotationSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPrintAreaSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPrintAreaSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDPPosPrinterRuledLineCapabilities)ruledLineCapabilities {
    ABI::Windows::Devices::PointOfService::PosPrinterRuledLineCapabilities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_RuledLineCapabilities(&unmarshalledReturn));
    return (WDPPosPrinterRuledLineCapabilities)unmarshalledReturn;
}

- (NSArray* /* WDPPosPrinterRotation */)supportedBarcodeRotations {
    ComPtr<IVectorView<ABI::Windows::Devices::PointOfService::PosPrinterRotation>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedBarcodeRotations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDPPosPrinterRotation_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDPPosPrinterRotation */)supportedBitmapRotations {
    ComPtr<IVectorView<ABI::Windows::Devices::PointOfService::PosPrinterRotation>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedBitmapRotations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDPPosPrinterRotation_create(unmarshalledReturn.Get());
}

- (BOOL)isPrinterPresent {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPrinterPresent(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDualColorSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDualColorSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDPPosPrinterColorCapabilities)colorCartridgeCapabilities {
    ABI::Windows::Devices::PointOfService::PosPrinterColorCapabilities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorCartridgeCapabilities(&unmarshalledReturn));
    return (WDPPosPrinterColorCapabilities)unmarshalledReturn;
}

- (WDPPosPrinterCartridgeSensors)cartridgeSensors {
    ABI::Windows::Devices::PointOfService::PosPrinterCartridgeSensors unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_CartridgeSensors(&unmarshalledReturn));
    return (WDPPosPrinterCartridgeSensors)unmarshalledReturn;
}

- (BOOL)isBoldSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBoldSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isItalicSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsItalicSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isUnderlineSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsUnderlineSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDoubleHighPrintSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleHighPrintSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDoubleWidePrintSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleWidePrintSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDoubleHighDoubleWidePrintSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleHighDoubleWidePrintSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperEmptySensorSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperEmptySensorSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperNearEndSensorSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperNearEndSensorSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* unsigned int */)supportedCharactersPerLine {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedCharactersPerLine(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

@end

@implementation WDPSlipPrinterCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::ISlipPrinterCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isFullLengthSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ISlipPrinterCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsFullLengthSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isBothSidesPrintingSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ISlipPrinterCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBothSidesPrintingSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isBarcodeSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBarcodeSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isBitmapSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBitmapSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isLeft90RotationSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsLeft90RotationSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isRight90RotationSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsRight90RotationSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)is180RotationSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Is180RotationSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPrintAreaSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPrintAreaSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDPPosPrinterRuledLineCapabilities)ruledLineCapabilities {
    ABI::Windows::Devices::PointOfService::PosPrinterRuledLineCapabilities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_RuledLineCapabilities(&unmarshalledReturn));
    return (WDPPosPrinterRuledLineCapabilities)unmarshalledReturn;
}

- (NSArray* /* WDPPosPrinterRotation */)supportedBarcodeRotations {
    ComPtr<IVectorView<ABI::Windows::Devices::PointOfService::PosPrinterRotation>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedBarcodeRotations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDPPosPrinterRotation_create(unmarshalledReturn.Get());
}

- (NSArray* /* WDPPosPrinterRotation */)supportedBitmapRotations {
    ComPtr<IVectorView<ABI::Windows::Devices::PointOfService::PosPrinterRotation>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonReceiptSlipCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedBitmapRotations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WDPPosPrinterRotation_create(unmarshalledReturn.Get());
}

- (BOOL)isPrinterPresent {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPrinterPresent(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDualColorSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDualColorSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDPPosPrinterColorCapabilities)colorCartridgeCapabilities {
    ABI::Windows::Devices::PointOfService::PosPrinterColorCapabilities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorCartridgeCapabilities(&unmarshalledReturn));
    return (WDPPosPrinterColorCapabilities)unmarshalledReturn;
}

- (WDPPosPrinterCartridgeSensors)cartridgeSensors {
    ABI::Windows::Devices::PointOfService::PosPrinterCartridgeSensors unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_CartridgeSensors(&unmarshalledReturn));
    return (WDPPosPrinterCartridgeSensors)unmarshalledReturn;
}

- (BOOL)isBoldSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBoldSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isItalicSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsItalicSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isUnderlineSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsUnderlineSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDoubleHighPrintSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleHighPrintSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDoubleWidePrintSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleWidePrintSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDoubleHighDoubleWidePrintSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleHighDoubleWidePrintSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperEmptySensorSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperEmptySensorSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperNearEndSensorSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperNearEndSensorSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* unsigned int */)supportedCharactersPerLine {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedCharactersPerLine(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

@end

@implementation WDPJournalPrinterCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IJournalPrinterCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isPrinterPresent {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPrinterPresent(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDualColorSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDualColorSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDPPosPrinterColorCapabilities)colorCartridgeCapabilities {
    ABI::Windows::Devices::PointOfService::PosPrinterColorCapabilities unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorCartridgeCapabilities(&unmarshalledReturn));
    return (WDPPosPrinterColorCapabilities)unmarshalledReturn;
}

- (WDPPosPrinterCartridgeSensors)cartridgeSensors {
    ABI::Windows::Devices::PointOfService::PosPrinterCartridgeSensors unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_CartridgeSensors(&unmarshalledReturn));
    return (WDPPosPrinterCartridgeSensors)unmarshalledReturn;
}

- (BOOL)isBoldSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBoldSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isItalicSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsItalicSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isUnderlineSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsUnderlineSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDoubleHighPrintSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleHighPrintSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDoubleWidePrintSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleWidePrintSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDoubleHighDoubleWidePrintSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDoubleHighDoubleWidePrintSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperEmptySensorSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperEmptySensorSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperNearEndSensorSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperNearEndSensorSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* unsigned int */)supportedCharactersPerLine {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonPosPrintStationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedCharactersPerLine(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

@end

@implementation WDPPosPrinterCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinterCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPUnifiedPosPowerReportingType)powerReportingType {
    ABI::Windows::Devices::PointOfService::UnifiedPosPowerReportingType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_PowerReportingType(&unmarshalledReturn));
    return (WDPUnifiedPosPowerReportingType)unmarshalledReturn;
}

- (BOOL)isStatisticsReportingSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStatisticsReportingSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isStatisticsUpdatingSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStatisticsUpdatingSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (unsigned int)defaultCharacterSet {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultCharacterSet(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)hasCoverSensor {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasCoverSensor(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canMapCharacterSet {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanMapCharacterSet(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isTransactionSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTransactionSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDPReceiptPrinterCapabilities*)receipt {
    ComPtr<ABI::Windows::Devices::PointOfService::IReceiptPrinterCapabilities> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Receipt(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPReceiptPrinterCapabilities>(unmarshalledReturn.Get());
}

- (WDPSlipPrinterCapabilities*)slip {
    ComPtr<ABI::Windows::Devices::PointOfService::ISlipPrinterCapabilities> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Slip(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPSlipPrinterCapabilities>(unmarshalledReturn.Get());
}

- (WDPJournalPrinterCapabilities*)journal {
    ComPtr<ABI::Windows::Devices::PointOfService::IJournalPrinterCapabilities> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Journal(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPJournalPrinterCapabilities>(unmarshalledReturn.Get());
}

@end

@implementation WDPPosPrinterStatus

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinterStatus> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPPosPrinterStatusKind)statusKind {
    ABI::Windows::Devices::PointOfService::PosPrinterStatusKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_StatusKind(&unmarshalledReturn));
    return (WDPPosPrinterStatusKind)unmarshalledReturn;
}

- (unsigned int)extendedStatus {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedStatus(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDPPosPrinterStatusUpdatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinterStatusUpdatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPPosPrinterStatus*)status {
    ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinterStatus> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterStatusUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPosPrinterStatus>(unmarshalledReturn.Get());
}

@end

@implementation WDPPosPrinterReleaseDeviceRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinterReleaseDeviceRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WDPPosPrinter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinterStatics> WDPIPosPrinterStatics_inst() {
    ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinterStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.PointOfService.PosPrinter").Get(), &inst));
    return inst;
}

+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPPosPrinter*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::PosPrinter*>> unmarshalledReturn;
    auto _comInst = WDPIPosPrinterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::PointOfService::PosPrinter*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::PosPrinter*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinter> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDPPosPrinter>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDPPosPrinter*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::PosPrinter*>> unmarshalledReturn;
    auto _comInst = WDPIPosPrinterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::PointOfService::PosPrinter*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::PosPrinter*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinter> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDPPosPrinter>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIPosPrinterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDPPosPrinterCapabilities*)capabilities {
    ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinterCapabilities> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Capabilities(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPosPrinterCapabilities>(unmarshalledReturn.Get());
}

- (NSArray* /* unsigned int */)supportedCharacterSets {
    ComPtr<IVectorView<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedCharacterSets(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_UInt32_create(unmarshalledReturn.Get());
}

- (NSArray* /* NSString * */)supportedTypeFaces {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedTypeFaces(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (WDPPosPrinterStatus*)status {
    ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinterStatus> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPosPrinterStatus>(unmarshalledReturn.Get());
}

- (void)claimPrinterAsyncWithSuccess:(void (^)(WDPClaimedPosPrinter*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::ClaimedPosPrinter*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->ClaimPrinterAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::PointOfService::ClaimedPosPrinter*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::ClaimedPosPrinter*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDPClaimedPosPrinter>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)checkHealthAsync:(WDPUnifiedPosHealthCheckLevel)level success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinter>(self);
    THROW_NS_IF_FAILED(
        _comInst->CheckHealthAsync((ABI::Windows::Devices::PointOfService::UnifiedPosHealthCheckLevel)level, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories
                   success:(void (^)(NSString*))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinter>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetStatisticsAsync(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                         ConvertToIterable<NSString, HSTRING>(statisticsCategories).Get()),
                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (EventRegistrationToken)addStatusUpdatedEvent:(void (^)(WDPPosPrinter*, WDPPosPrinterStatusUpdatedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->add_StatusUpdated(
        Make<ITypedEventHandler_Windows_Devices_PointOfService_PosPrinter_Windows_Devices_PointOfService_PosPrinterStatusUpdatedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStatusUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StatusUpdated(token));
}

@end

@implementation WDPClaimedPosPrinter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCharacterSet:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->put_CharacterSet(value));
}

- (unsigned int)characterSet {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_CharacterSet(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isCoverOpen {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCoverOpen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsCharacterSetMappingEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsCharacterSetMappingEnabled((boolean)value));
}

- (BOOL)isCharacterSetMappingEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCharacterSetMappingEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setMapMode:(WDPPosPrinterMapMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->put_MapMode((ABI::Windows::Devices::PointOfService::PosPrinterMapMode)value));
}

- (WDPPosPrinterMapMode)mapMode {
    ABI::Windows::Devices::PointOfService::PosPrinterMapMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_MapMode(&unmarshalledReturn));
    return (WDPPosPrinterMapMode)unmarshalledReturn;
}

- (WDPClaimedReceiptPrinter*)receipt {
    ComPtr<ABI::Windows::Devices::PointOfService::IClaimedReceiptPrinter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Receipt(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPClaimedReceiptPrinter>(unmarshalledReturn.Get());
}

- (WDPClaimedSlipPrinter*)slip {
    ComPtr<ABI::Windows::Devices::PointOfService::IClaimedSlipPrinter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Slip(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPClaimedSlipPrinter>(unmarshalledReturn.Get());
}

- (WDPClaimedJournalPrinter*)journal {
    ComPtr<ABI::Windows::Devices::PointOfService::IClaimedJournalPrinter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Journal(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPClaimedJournalPrinter>(unmarshalledReturn.Get());
}

- (void)enableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->EnableAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)disableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->DisableAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)retainDeviceAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->RetainDeviceAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)resetStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories
                     success:(void (^)(BOOL))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(
        _comInst->ResetStatisticsAsync(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                           ConvertToIterable<NSString, HSTRING>(statisticsCategories).Get()),
                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)updateStatisticsAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, NSString * > */)statistics
                      success:(void (^)(BOOL))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateStatisticsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, HSTRING>*, IKeyValuePair<HSTRING, HSTRING>*>>::type>*>(
            ConvertToIterable<
                RTProxiedKeyValuePair,
                ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, HSTRING>*, IKeyValuePair<HSTRING, HSTRING>*>,
                RTProxiedKeyValuePair_NSString_NSString_create>(statistics)
                .Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (EventRegistrationToken)addReleaseDeviceRequestedEvent:(void (^)(WDPClaimedPosPrinter*,
                                                                   WDPPosPrinterReleaseDeviceRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReleaseDeviceRequested(
        Make<
            ITypedEventHandler_Windows_Devices_PointOfService_ClaimedPosPrinter_Windows_Devices_PointOfService_PosPrinterReleaseDeviceRequestedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReleaseDeviceRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedPosPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReleaseDeviceRequested(token));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDPReceiptPrintJob

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IReceiptPrintJob> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)markFeed:(WDPPosPrinterMarkFeedKind)kind {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptPrintJob>(self);
    THROW_NS_IF_FAILED(_comInst->MarkFeed((ABI::Windows::Devices::PointOfService::PosPrinterMarkFeedKind)kind));
}

- (void)cutPaper:(double)percentage {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptPrintJob>(self);
    THROW_NS_IF_FAILED(_comInst->CutPaper(percentage));
}

- (void)cutPaperDefault {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptPrintJob>(self);
    THROW_NS_IF_FAILED(_comInst->CutPaperDefault());
}

- (void)setBarcodeRotation:(WDPPosPrinterRotation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->SetBarcodeRotation((ABI::Windows::Devices::PointOfService::PosPrinterRotation)value));
}

- (void)setPrintRotation:(WDPPosPrinterRotation)value includeBitmaps:(BOOL)includeBitmaps {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetPrintRotation((ABI::Windows::Devices::PointOfService::PosPrinterRotation)value, (boolean)includeBitmaps));
}

- (void)setPrintArea:(WFRect*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->SetPrintArea(*[value internalStruct]));
}

- (void)setBitmap:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->SetBitmap(bitmapNumber,
                                           _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                           (ABI::Windows::Devices::PointOfService::PosPrinterAlignment)alignment));
}

- (void)setBitmapCustomWidthStandardAlign:(unsigned int)bitmapNumber
                                   bitmap:(WGIBitmapFrame*)bitmap
                                alignment:(WDPPosPrinterAlignment)alignment
                                    width:(unsigned int)width {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetBitmapCustomWidthStandardAlign(bitmapNumber,
                                                    _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                    (ABI::Windows::Devices::PointOfService::PosPrinterAlignment)alignment,
                                                    width));
}

- (void)setCustomAlignedBitmap:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->SetCustomAlignedBitmap(bitmapNumber,
                                                        _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                        alignmentDistance));
}

- (void)setBitmapCustomWidthCustomAlign:(unsigned int)bitmapNumber
                                 bitmap:(WGIBitmapFrame*)bitmap
                      alignmentDistance:(unsigned int)alignmentDistance
                                  width:(unsigned int)width {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetBitmapCustomWidthCustomAlign(bitmapNumber,
                                                  _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                  alignmentDistance,
                                                  width));
}

- (void)printSavedBitmap:(unsigned int)bitmapNumber {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintSavedBitmap(bitmapNumber));
}

- (void)drawRuledLine:(NSString*)positionList
        lineDirection:(WDPPosPrinterLineDirection)lineDirection
            lineWidth:(unsigned int)lineWidth
            lineStyle:(WDPPosPrinterLineStyle)lineStyle
            lineColor:(unsigned int)lineColor {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->DrawRuledLine(nsStrToHstr(positionList).Get(),
                                               (ABI::Windows::Devices::PointOfService::PosPrinterLineDirection)lineDirection,
                                               lineWidth,
                                               (ABI::Windows::Devices::PointOfService::PosPrinterLineStyle)lineStyle,
                                               lineColor));
}

- (void)printBarcode:(NSString*)data
           symbology:(unsigned int)symbology
              height:(unsigned int)height
               width:(unsigned int)width
        textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition
           alignment:(WDPPosPrinterAlignment)alignment {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintBarcode(nsStrToHstr(data).Get(),
                                              symbology,
                                              height,
                                              width,
                                              (ABI::Windows::Devices::PointOfService::PosPrinterBarcodeTextPosition)textPosition,
                                              (ABI::Windows::Devices::PointOfService::PosPrinterAlignment)alignment));
}

- (void)printBarcodeCustomAlign:(NSString*)data
                      symbology:(unsigned int)symbology
                         height:(unsigned int)height
                          width:(unsigned int)width
                   textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition
              alignmentDistance:(unsigned int)alignmentDistance {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintBarcodeCustomAlign(nsStrToHstr(data).Get(),
                                                         symbology,
                                                         height,
                                                         width,
                                                         (ABI::Windows::Devices::PointOfService::PosPrinterBarcodeTextPosition)textPosition,
                                                         alignmentDistance));
}

- (void)printBitmap:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintBitmap(_getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                             (ABI::Windows::Devices::PointOfService::PosPrinterAlignment)alignment));
}

- (void)printBitmapCustomWidthStandardAlign:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment width:(unsigned int)width {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(
        _comInst->PrintBitmapCustomWidthStandardAlign(_getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                      (ABI::Windows::Devices::PointOfService::PosPrinterAlignment)alignment,
                                                      width));
}

- (void)printCustomAlignedBitmap:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintCustomAlignedBitmap(_getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                          alignmentDistance));
}

- (void)printBitmapCustomWidthCustomAlign:(WGIBitmapFrame*)bitmap
                        alignmentDistance:(unsigned int)alignmentDistance
                                    width:(unsigned int)width {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(
        _comInst->PrintBitmapCustomWidthCustomAlign(_getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                    alignmentDistance,
                                                    width));
}

- (void)print:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->Print(nsStrToHstr(data).Get()));
}

- (void)printLine:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintLine(nsStrToHstr(data).Get()));
}

- (void)printNewline {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintNewline());
}

- (void)executeAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->ExecuteAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WDPSlipPrintJob

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setBarcodeRotation:(WDPPosPrinterRotation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->SetBarcodeRotation((ABI::Windows::Devices::PointOfService::PosPrinterRotation)value));
}

- (void)setPrintRotation:(WDPPosPrinterRotation)value includeBitmaps:(BOOL)includeBitmaps {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetPrintRotation((ABI::Windows::Devices::PointOfService::PosPrinterRotation)value, (boolean)includeBitmaps));
}

- (void)setPrintArea:(WFRect*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->SetPrintArea(*[value internalStruct]));
}

- (void)setBitmap:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->SetBitmap(bitmapNumber,
                                           _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                           (ABI::Windows::Devices::PointOfService::PosPrinterAlignment)alignment));
}

- (void)setBitmapCustomWidthStandardAlign:(unsigned int)bitmapNumber
                                   bitmap:(WGIBitmapFrame*)bitmap
                                alignment:(WDPPosPrinterAlignment)alignment
                                    width:(unsigned int)width {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetBitmapCustomWidthStandardAlign(bitmapNumber,
                                                    _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                    (ABI::Windows::Devices::PointOfService::PosPrinterAlignment)alignment,
                                                    width));
}

- (void)setCustomAlignedBitmap:(unsigned int)bitmapNumber bitmap:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->SetCustomAlignedBitmap(bitmapNumber,
                                                        _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                        alignmentDistance));
}

- (void)setBitmapCustomWidthCustomAlign:(unsigned int)bitmapNumber
                                 bitmap:(WGIBitmapFrame*)bitmap
                      alignmentDistance:(unsigned int)alignmentDistance
                                  width:(unsigned int)width {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetBitmapCustomWidthCustomAlign(bitmapNumber,
                                                  _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                  alignmentDistance,
                                                  width));
}

- (void)printSavedBitmap:(unsigned int)bitmapNumber {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintSavedBitmap(bitmapNumber));
}

- (void)drawRuledLine:(NSString*)positionList
        lineDirection:(WDPPosPrinterLineDirection)lineDirection
            lineWidth:(unsigned int)lineWidth
            lineStyle:(WDPPosPrinterLineStyle)lineStyle
            lineColor:(unsigned int)lineColor {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->DrawRuledLine(nsStrToHstr(positionList).Get(),
                                               (ABI::Windows::Devices::PointOfService::PosPrinterLineDirection)lineDirection,
                                               lineWidth,
                                               (ABI::Windows::Devices::PointOfService::PosPrinterLineStyle)lineStyle,
                                               lineColor));
}

- (void)printBarcode:(NSString*)data
           symbology:(unsigned int)symbology
              height:(unsigned int)height
               width:(unsigned int)width
        textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition
           alignment:(WDPPosPrinterAlignment)alignment {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintBarcode(nsStrToHstr(data).Get(),
                                              symbology,
                                              height,
                                              width,
                                              (ABI::Windows::Devices::PointOfService::PosPrinterBarcodeTextPosition)textPosition,
                                              (ABI::Windows::Devices::PointOfService::PosPrinterAlignment)alignment));
}

- (void)printBarcodeCustomAlign:(NSString*)data
                      symbology:(unsigned int)symbology
                         height:(unsigned int)height
                          width:(unsigned int)width
                   textPosition:(WDPPosPrinterBarcodeTextPosition)textPosition
              alignmentDistance:(unsigned int)alignmentDistance {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintBarcodeCustomAlign(nsStrToHstr(data).Get(),
                                                         symbology,
                                                         height,
                                                         width,
                                                         (ABI::Windows::Devices::PointOfService::PosPrinterBarcodeTextPosition)textPosition,
                                                         alignmentDistance));
}

- (void)printBitmap:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintBitmap(_getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                             (ABI::Windows::Devices::PointOfService::PosPrinterAlignment)alignment));
}

- (void)printBitmapCustomWidthStandardAlign:(WGIBitmapFrame*)bitmap alignment:(WDPPosPrinterAlignment)alignment width:(unsigned int)width {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(
        _comInst->PrintBitmapCustomWidthStandardAlign(_getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                      (ABI::Windows::Devices::PointOfService::PosPrinterAlignment)alignment,
                                                      width));
}

- (void)printCustomAlignedBitmap:(WGIBitmapFrame*)bitmap alignmentDistance:(unsigned int)alignmentDistance {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintCustomAlignedBitmap(_getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                          alignmentDistance));
}

- (void)printBitmapCustomWidthCustomAlign:(WGIBitmapFrame*)bitmap
                        alignmentDistance:(unsigned int)alignmentDistance
                                    width:(unsigned int)width {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob>(self);
    THROW_NS_IF_FAILED(
        _comInst->PrintBitmapCustomWidthCustomAlign(_getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(bitmap).Get(),
                                                    alignmentDistance,
                                                    width));
}

- (void)print:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->Print(nsStrToHstr(data).Get()));
}

- (void)printLine:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintLine(nsStrToHstr(data).Get()));
}

- (void)printNewline {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintNewline());
}

- (void)executeAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->ExecuteAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WDPJournalPrintJob

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinterJob> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)print:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->Print(nsStrToHstr(data).Get()));
}

- (void)printLine:(NSString*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintLine(nsStrToHstr(data).Get()));
}

- (void)printNewline {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->PrintNewline());
}

- (void)executeAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IPosPrinterJob>(self);
    THROW_NS_IF_FAILED(_comInst->ExecuteAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WDPClaimedReceiptPrinter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IClaimedReceiptPrinter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)sidewaysMaxLines {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedReceiptPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SidewaysMaxLines(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)sidewaysMaxChars {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedReceiptPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SidewaysMaxChars(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)linesToPaperCut {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedReceiptPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_LinesToPaperCut(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFSize*)pageSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedReceiptPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_PageSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WFRect*)printArea {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedReceiptPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrintArea(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WDPReceiptPrintJob*)createJob {
    ComPtr<ABI::Windows::Devices::PointOfService::IReceiptPrintJob> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedReceiptPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->CreateJob(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPReceiptPrintJob>(unmarshalledReturn.Get());
}

- (void)setCharactersPerLine:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_CharactersPerLine(value));
}

- (unsigned int)charactersPerLine {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CharactersPerLine(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLineHeight:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_LineHeight(value));
}

- (unsigned int)lineHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLineSpacing:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_LineSpacing(value));
}

- (unsigned int)lineSpacing {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineSpacing(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)lineWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIsLetterQuality:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsLetterQuality((boolean)value));
}

- (BOOL)isLetterQuality {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsLetterQuality(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperNearEnd {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperNearEnd(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setColorCartridge:(WDPPosPrinterColorCartridge)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ColorCartridge((ABI::Windows::Devices::PointOfService::PosPrinterColorCartridge)value));
}

- (WDPPosPrinterColorCartridge)colorCartridge {
    ABI::Windows::Devices::PointOfService::PosPrinterColorCartridge unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorCartridge(&unmarshalledReturn));
    return (WDPPosPrinterColorCartridge)unmarshalledReturn;
}

- (BOOL)isCoverOpen {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCoverOpen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCartridgeRemoved {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCartridgeRemoved(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCartridgeEmpty {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCartridgeEmpty(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isHeadCleaning {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsHeadCleaning(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperEmpty {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperEmpty(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isReadyToPrint {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReadyToPrint(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)validateData:(NSString*)data {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->ValidateData(nsStrToHstr(data).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDPClaimedSlipPrinter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IClaimedSlipPrinter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)sidewaysMaxLines {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedSlipPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SidewaysMaxLines(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)sidewaysMaxChars {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedSlipPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SidewaysMaxChars(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)maxLines {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedSlipPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxLines(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)linesNearEndToEnd {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedSlipPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_LinesNearEndToEnd(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDPPosPrinterPrintSide)printSide {
    ABI::Windows::Devices::PointOfService::PosPrinterPrintSide unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedSlipPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrintSide(&unmarshalledReturn));
    return (WDPPosPrinterPrintSide)unmarshalledReturn;
}

- (WFSize*)pageSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedSlipPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_PageSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WFRect*)printArea {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedSlipPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrintArea(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)openJaws {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedSlipPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->OpenJaws());
}

- (void)closeJaws {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedSlipPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->CloseJaws());
}

- (void)insertSlipAsync:(WFTimeSpan*)timeout success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedSlipPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->InsertSlipAsync(*[timeout internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)removeSlipAsync:(WFTimeSpan*)timeout success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedSlipPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveSlipAsync(*[timeout internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)changePrintSide:(WDPPosPrinterPrintSide)printSide {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedSlipPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->ChangePrintSide((ABI::Windows::Devices::PointOfService::PosPrinterPrintSide)printSide));
}

- (WDPSlipPrintJob*)createJob {
    ComPtr<ABI::Windows::Devices::PointOfService::IReceiptOrSlipJob> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedSlipPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->CreateJob(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPSlipPrintJob>(unmarshalledReturn.Get());
}

- (void)setCharactersPerLine:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_CharactersPerLine(value));
}

- (unsigned int)charactersPerLine {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CharactersPerLine(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLineHeight:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_LineHeight(value));
}

- (unsigned int)lineHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLineSpacing:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_LineSpacing(value));
}

- (unsigned int)lineSpacing {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineSpacing(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)lineWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIsLetterQuality:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsLetterQuality((boolean)value));
}

- (BOOL)isLetterQuality {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsLetterQuality(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperNearEnd {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperNearEnd(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setColorCartridge:(WDPPosPrinterColorCartridge)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ColorCartridge((ABI::Windows::Devices::PointOfService::PosPrinterColorCartridge)value));
}

- (WDPPosPrinterColorCartridge)colorCartridge {
    ABI::Windows::Devices::PointOfService::PosPrinterColorCartridge unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorCartridge(&unmarshalledReturn));
    return (WDPPosPrinterColorCartridge)unmarshalledReturn;
}

- (BOOL)isCoverOpen {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCoverOpen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCartridgeRemoved {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCartridgeRemoved(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCartridgeEmpty {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCartridgeEmpty(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isHeadCleaning {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsHeadCleaning(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperEmpty {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperEmpty(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isReadyToPrint {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReadyToPrint(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)validateData:(NSString*)data {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->ValidateData(nsStrToHstr(data).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDPClaimedJournalPrinter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IClaimedJournalPrinter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPJournalPrintJob*)createJob {
    ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinterJob> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedJournalPrinter>(self);
    THROW_NS_IF_FAILED(_comInst->CreateJob(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPJournalPrintJob>(unmarshalledReturn.Get());
}

- (void)setCharactersPerLine:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_CharactersPerLine(value));
}

- (unsigned int)charactersPerLine {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CharactersPerLine(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLineHeight:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_LineHeight(value));
}

- (unsigned int)lineHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLineSpacing:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_LineSpacing(value));
}

- (unsigned int)lineSpacing {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineSpacing(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)lineWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIsLetterQuality:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsLetterQuality((boolean)value));
}

- (BOOL)isLetterQuality {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsLetterQuality(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperNearEnd {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperNearEnd(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setColorCartridge:(WDPPosPrinterColorCartridge)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->put_ColorCartridge((ABI::Windows::Devices::PointOfService::PosPrinterColorCartridge)value));
}

- (WDPPosPrinterColorCartridge)colorCartridge {
    ABI::Windows::Devices::PointOfService::PosPrinterColorCartridge unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorCartridge(&unmarshalledReturn));
    return (WDPPosPrinterColorCartridge)unmarshalledReturn;
}

- (BOOL)isCoverOpen {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCoverOpen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCartridgeRemoved {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCartridgeRemoved(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCartridgeEmpty {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCartridgeEmpty(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isHeadCleaning {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsHeadCleaning(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPaperEmpty {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPaperEmpty(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isReadyToPrint {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReadyToPrint(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)validateData:(NSString*)data {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICommonClaimedPosPrinterStation>(self);
    THROW_NS_IF_FAILED(_comInst->ValidateData(nsStrToHstr(data).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDPCashDrawerStatus

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawerStatus> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPCashDrawerStatusKind)statusKind {
    ABI::Windows::Devices::PointOfService::CashDrawerStatusKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_StatusKind(&unmarshalledReturn));
    return (WDPCashDrawerStatusKind)unmarshalledReturn;
}

- (unsigned int)extendedStatus {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedStatus(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDPCashDrawerStatusUpdatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawerStatusUpdatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPCashDrawerStatus*)status {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawerStatus> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerStatusUpdatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPCashDrawerStatus>(unmarshalledReturn.Get());
}

@end

@implementation WDPCashDrawerCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawerCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPUnifiedPosPowerReportingType)powerReportingType {
    ABI::Windows::Devices::PointOfService::UnifiedPosPowerReportingType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_PowerReportingType(&unmarshalledReturn));
    return (WDPUnifiedPosPowerReportingType)unmarshalledReturn;
}

- (BOOL)isStatisticsReportingSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStatisticsReportingSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isStatisticsUpdatingSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStatisticsUpdatingSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isStatusReportingSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStatusReportingSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isStatusMultiDrawerDetectSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStatusMultiDrawerDetectSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDrawerOpenSensorAvailable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDrawerOpenSensorAvailable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WDPCashDrawer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawerStatics> WDPICashDrawerStatics_inst() {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.PointOfService.CashDrawer").Get(), &inst));
    return inst;
}

+ (void)getDefaultAsyncWithSuccess:(void (^)(WDPCashDrawer*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::CashDrawer*>> unmarshalledReturn;
    auto _comInst = WDPICashDrawerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::PointOfService::CashDrawer*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::CashDrawer*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawer> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDPCashDrawer>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDPCashDrawer*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::CashDrawer*>> unmarshalledReturn;
    auto _comInst = WDPICashDrawerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(deviceId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::PointOfService::CashDrawer*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::CashDrawer*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawer> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDPCashDrawer>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPICashDrawerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDPCashDrawerCapabilities*)capabilities {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawerCapabilities> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Capabilities(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPCashDrawerCapabilities>(unmarshalledReturn.Get());
}

- (WDPCashDrawerStatus*)status {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawerStatus> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPCashDrawerStatus>(unmarshalledReturn.Get());
}

- (BOOL)isDrawerOpen {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDrawerOpen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDPCashDrawerEventSource*)drawerEventSource {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawerEventSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->get_DrawerEventSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPCashDrawerEventSource>(unmarshalledReturn.Get());
}

- (void)claimDrawerAsyncWithSuccess:(void (^)(WDPClaimedCashDrawer*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::ClaimedCashDrawer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->ClaimDrawerAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::PointOfService::ClaimedCashDrawer*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::PointOfService::ClaimedCashDrawer*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Devices::PointOfService::IClaimedCashDrawer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WDPClaimedCashDrawer>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)checkHealthAsync:(WDPUnifiedPosHealthCheckLevel)level success:(void (^)(NSString*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawer>(self);
    THROW_NS_IF_FAILED(
        _comInst->CheckHealthAsync((ABI::Windows::Devices::PointOfService::UnifiedPosHealthCheckLevel)level, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)getStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories
                   success:(void (^)(NSString*))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawer>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetStatisticsAsync(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                         ConvertToIterable<NSString, HSTRING>(statisticsCategories).Get()),
                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (EventRegistrationToken)addStatusUpdatedEvent:(void (^)(WDPCashDrawer*, WDPCashDrawerStatusUpdatedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->add_StatusUpdated(
        Make<ITypedEventHandler_Windows_Devices_PointOfService_CashDrawer_Windows_Devices_PointOfService_CashDrawerStatusUpdatedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStatusUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StatusUpdated(token));
}

@end

@implementation WDPCashDrawerClosedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawerEventSourceEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPCashDrawer*)cashDrawer {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerEventSourceEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CashDrawer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPCashDrawer>(unmarshalledReturn.Get());
}

@end

@implementation WDPCashDrawerOpenedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawerEventSourceEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDPCashDrawer*)cashDrawer {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerEventSourceEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CashDrawer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPCashDrawer>(unmarshalledReturn.Get());
}

@end

@implementation WDPCashDrawerEventSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawerEventSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addDrawerClosedEvent:(void (^)(WDPCashDrawerEventSource*, WDPCashDrawerClosedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerEventSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_DrawerClosed(
        Make<
            ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerEventSource_Windows_Devices_PointOfService_CashDrawerClosedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDrawerClosedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerEventSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DrawerClosed(token));
}

- (EventRegistrationToken)addDrawerOpenedEvent:(void (^)(WDPCashDrawerEventSource*, WDPCashDrawerOpenedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerEventSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_DrawerOpened(
        Make<
            ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerEventSource_Windows_Devices_PointOfService_CashDrawerOpenedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDrawerOpenedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerEventSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DrawerOpened(token));
}

@end

@implementation WDPClaimedCashDrawer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::IClaimedCashDrawer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedCashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedCashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDrawerOpen {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedCashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDrawerOpen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDPCashDrawerCloseAlarm*)closeAlarm {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawerCloseAlarm> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedCashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->get_CloseAlarm(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPCashDrawerCloseAlarm>(unmarshalledReturn.Get());
}

- (void)openDrawerAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedCashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->OpenDrawerAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)enableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedCashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->EnableAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)disableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedCashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->DisableAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)retainDeviceAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedCashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->RetainDeviceAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)resetStatisticsAsync:(id<NSFastEnumeration> /* NSString * */)statisticsCategories
                     success:(void (^)(BOOL))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedCashDrawer>(self);
    THROW_NS_IF_FAILED(
        _comInst->ResetStatisticsAsync(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                           ConvertToIterable<NSString, HSTRING>(statisticsCategories).Get()),
                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)updateStatisticsAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, NSString * > */)statistics
                      success:(void (^)(BOOL))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedCashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateStatisticsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, HSTRING>*, IKeyValuePair<HSTRING, HSTRING>*>>::type>*>(
            ConvertToIterable<
                RTProxiedKeyValuePair,
                ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, HSTRING>*, IKeyValuePair<HSTRING, HSTRING>*>,
                RTProxiedKeyValuePair_NSString_NSString_create>(statistics)
                .Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (EventRegistrationToken)addReleaseDeviceRequestedEvent:(void (^)(WDPClaimedCashDrawer*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedCashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->add_ReleaseDeviceRequested(
        Make<ITypedEventHandler_Windows_Devices_PointOfService_ClaimedCashDrawer_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeReleaseDeviceRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::IClaimedCashDrawer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ReleaseDeviceRequested(token));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WDPCashDrawerCloseAlarm

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawerCloseAlarm> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setAlarmTimeout:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCloseAlarm>(self);
    THROW_NS_IF_FAILED(_comInst->put_AlarmTimeout(*[value internalStruct]));
}

- (WFTimeSpan*)alarmTimeout {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCloseAlarm>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlarmTimeout(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setBeepFrequency:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCloseAlarm>(self);
    THROW_NS_IF_FAILED(_comInst->put_BeepFrequency(value));
}

- (unsigned int)beepFrequency {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCloseAlarm>(self);
    THROW_NS_IF_FAILED(_comInst->get_BeepFrequency(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setBeepDuration:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCloseAlarm>(self);
    THROW_NS_IF_FAILED(_comInst->put_BeepDuration(*[value internalStruct]));
}

- (WFTimeSpan*)beepDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCloseAlarm>(self);
    THROW_NS_IF_FAILED(_comInst->get_BeepDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setBeepDelay:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCloseAlarm>(self);
    THROW_NS_IF_FAILED(_comInst->put_BeepDelay(*[value internalStruct]));
}

- (WFTimeSpan*)beepDelay {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCloseAlarm>(self);
    THROW_NS_IF_FAILED(_comInst->get_BeepDelay(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (EventRegistrationToken)addAlarmTimeoutExpiredEvent:(void (^)(WDPCashDrawerCloseAlarm*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCloseAlarm>(self);
    THROW_NS_IF_FAILED(_comInst->add_AlarmTimeoutExpired(
        Make<ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerCloseAlarm_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAlarmTimeoutExpiredEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCloseAlarm>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AlarmTimeoutExpired(token));
}

- (void)startAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::PointOfService::ICashDrawerCloseAlarm>(self);
    THROW_NS_IF_FAILED(_comInst->StartAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_RTProxiedKeyValuePair_NSString_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<IterableArrayAdapterObj<
        IIterable<IKeyValuePair_HSTRING_HSTRING_Ptr>,
        RTIterableObj<IKeyValuePair_HSTRING_HSTRING_Ptr,
                      IIterable<IKeyValuePair_HSTRING_HSTRING_Ptr>,
                      RTProxiedKeyValuePair,
                      IKeyValuePair_HSTRING_HSTRING_Ptr,
                      RTProxiedKeyValuePair_NSString_NSString_create,
                      ConvertToIterable<RTProxiedKeyValuePair,
                                        ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, HSTRING>*,
                                                                                          IKeyValuePair<HSTRING, HSTRING>*>,
                                        RTProxiedKeyValuePair_NSString_NSString_create>>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_UInt32_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<IterableArrayAdapterObj<
        IIterable<unsigned int>,
        RTIterableObj<unsigned int, IIterable<unsigned int>, unsigned int, unsigned int, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedKeyValuePair_NSString_NSString_create(IInspectable* val) {
    std::unique_ptr<KeyValuePairAdapter> adapter = std::make_unique<KeyValuePairAdapterObj<
        RTKeyValuePairObj<HSTRING, HSTRING, HSTRING, HSTRING, NSString, NSString, dummyObjCCreator, dummyObjCCreator>>>();
    return _createRtProxyWithAdapter<RTProxiedKeyValuePair, KeyValuePairAdapter>(val, std::move(adapter));
    ;
}

id RTProxiedNSArray_C_UInt32_create(UINT32 size, unsigned int* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<unsigned int, RTCArrayObj<unsigned int, unsigned int, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_UInt32_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<
        IVectorView<unsigned int>,
        RTArrayObj<unsigned int, IVectorView<unsigned int>, unsigned int, unsigned int, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WDPPosPrinterRotation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::PointOfService::PosPrinterRotation>,
                                         RTArrayObj<ABI::Windows::Devices::PointOfService::PosPrinterRotation,
                                                    IVectorView<ABI::Windows::Devices::PointOfService::PosPrinterRotation>,
                                                    WDPPosPrinterRotation,
                                                    ABI::Windows::Devices::PointOfService::PosPrinterRotation,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_NSString_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<
        DictionaryAdapterObj<IMapView<HSTRING, HSTRING>,
                             DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, HSTRING>>,
                             RTMapViewObj<HSTRING,
                                          HSTRING,
                                          HSTRING,
                                          HSTRING,
                                          NSString,
                                          NSString,
                                          IMapView<HSTRING, HSTRING>,
                                          dummyObjCCreator,
                                          dummyObjCCreator,
                                          dummyWRLCreator,
                                          dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
