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

// WindowsDevicesPointOfService_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsGraphicsImaging_priv.h"
ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeSymbologiesStatics> WDPIBarcodeSymbologiesStatics_inst();
ComPtr<ABI::Windows::Devices::PointOfService::IBarcodeScannerStatics> WDPIBarcodeScannerStatics_inst();
ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderEncryptionAlgorithmsStatics>
WDPIMagneticStripeReaderEncryptionAlgorithmsStatics_inst();
ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderCardTypesStatics> WDPIMagneticStripeReaderCardTypesStatics_inst();
ComPtr<ABI::Windows::Devices::PointOfService::IMagneticStripeReaderStatics> WDPIMagneticStripeReaderStatics_inst();
ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinterCharacterSetIdsStatics> WDPIPosPrinterCharacterSetIdsStatics_inst();
ComPtr<ABI::Windows::Devices::PointOfService::IPosPrinterStatics> WDPIPosPrinterStatics_inst();
ComPtr<ABI::Windows::Devices::PointOfService::ICashDrawerStatics> WDPICashDrawerStatics_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedIterableNSArray_RTProxiedKeyValuePair_NSString_NSString_create(IInspectable* val);
id RTProxiedIterableNSArray_UInt32_create(IInspectable* val);
id RTProxiedKeyValuePair_NSString_NSString_create(IInspectable* val);
id RTProxiedNSArray_C_UInt32_create(UINT32 size, unsigned int* val);
id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_UInt32_create(IInspectable* val);
id RTProxiedNSArray_WDPPosPrinterRotation_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_NSString_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedIterableNSArray_RTProxiedKeyValuePair_NSString_NSString, RTProxiedIterableNSArray_UInt32;
@class RTProxiedKeyValuePair_NSString_NSString, RTProxiedNSArray_C_UInt32, RTProxiedNSArray_C_UInt8, RTProxiedNSArray_NSString,
    RTProxiedNSArray_UInt32;
@class RTProxiedNSArray_WDPPosPrinterRotation, RTProxiedNSDictionary_NSString_NSString;

#ifndef __EventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner__DEFINED
#define __EventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner__DEFINED
class EventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::Devices::PointOfService::ClaimedBarcodeScanner*>> {
    void (^_delegate)(RTObject*, WDPClaimedBarcodeScanner*);

public:
    EventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner(void (^del)(RTObject*, WDPClaimedBarcodeScanner*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WDPClaimedBarcodeScanner>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __EventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader__DEFINED
#define __EventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader__DEFINED
class EventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::Devices::PointOfService::ClaimedMagneticStripeReader*>> {
    void (^_delegate)(RTObject*, WDPClaimedMagneticStripeReader*);

public:
    EventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader(void (^del)(RTObject*, WDPClaimedMagneticStripeReader*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WDPClaimedMagneticStripeReader>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_PointOfService_BarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerStatusUpdatedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_PointOfService_BarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerStatusUpdatedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_PointOfService_BarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerStatusUpdatedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::PointOfService::BarcodeScanner*,
                                                       ABI::Windows::Devices::PointOfService::BarcodeScannerStatusUpdatedEventArgs*>> {
    void (^_delegate)(WDPBarcodeScanner*, WDPBarcodeScannerStatusUpdatedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_PointOfService_BarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerStatusUpdatedEventArgs(
        void (^del)(WDPBarcodeScanner*, WDPBarcodeScannerStatusUpdatedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_PointOfService_BarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerStatusUpdatedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::PointOfService::IBarcodeScanner* arg0,
                                             ABI::Windows::Devices::PointOfService::IBarcodeScannerStatusUpdatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPBarcodeScanner>(arg0), _createRtProxy<WDPBarcodeScannerStatusUpdatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerCloseAlarm_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerCloseAlarm_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerCloseAlarm_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::PointOfService::CashDrawerCloseAlarm*, IInspectable*>> {
    void (^_delegate)(WDPCashDrawerCloseAlarm*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerCloseAlarm_System_Object(void (^del)(WDPCashDrawerCloseAlarm*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerCloseAlarm_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::PointOfService::ICashDrawerCloseAlarm* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPCashDrawerCloseAlarm>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerEventSource_Windows_Devices_PointOfService_CashDrawerClosedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerEventSource_Windows_Devices_PointOfService_CashDrawerClosedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerEventSource_Windows_Devices_PointOfService_CashDrawerClosedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::PointOfService::CashDrawerEventSource*,
                                                                       ABI::Windows::Devices::PointOfService::CashDrawerClosedEventArgs*>> {
    void (^_delegate)(WDPCashDrawerEventSource*, WDPCashDrawerClosedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerEventSource_Windows_Devices_PointOfService_CashDrawerClosedEventArgs(
        void (^del)(WDPCashDrawerEventSource*, WDPCashDrawerClosedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerEventSource_Windows_Devices_PointOfService_CashDrawerClosedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::PointOfService::ICashDrawerEventSource* arg0,
                                             ABI::Windows::Devices::PointOfService::ICashDrawerEventSourceEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPCashDrawerEventSource>(arg0), _createRtProxy<WDPCashDrawerClosedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerEventSource_Windows_Devices_PointOfService_CashDrawerOpenedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerEventSource_Windows_Devices_PointOfService_CashDrawerOpenedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerEventSource_Windows_Devices_PointOfService_CashDrawerOpenedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::PointOfService::CashDrawerEventSource*,
                                                                       ABI::Windows::Devices::PointOfService::CashDrawerOpenedEventArgs*>> {
    void (^_delegate)(WDPCashDrawerEventSource*, WDPCashDrawerOpenedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerEventSource_Windows_Devices_PointOfService_CashDrawerOpenedEventArgs(
        void (^del)(WDPCashDrawerEventSource*, WDPCashDrawerOpenedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_PointOfService_CashDrawerEventSource_Windows_Devices_PointOfService_CashDrawerOpenedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::PointOfService::ICashDrawerEventSource* arg0,
                                             ABI::Windows::Devices::PointOfService::ICashDrawerEventSourceEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPCashDrawerEventSource>(arg0), _createRtProxy<WDPCashDrawerOpenedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_PointOfService_CashDrawer_Windows_Devices_PointOfService_CashDrawerStatusUpdatedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_PointOfService_CashDrawer_Windows_Devices_PointOfService_CashDrawerStatusUpdatedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_PointOfService_CashDrawer_Windows_Devices_PointOfService_CashDrawerStatusUpdatedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::PointOfService::CashDrawer*,
                                                       ABI::Windows::Devices::PointOfService::CashDrawerStatusUpdatedEventArgs*>> {
    void (^_delegate)(WDPCashDrawer*, WDPCashDrawerStatusUpdatedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_PointOfService_CashDrawer_Windows_Devices_PointOfService_CashDrawerStatusUpdatedEventArgs(
        void (^del)(WDPCashDrawer*, WDPCashDrawerStatusUpdatedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_PointOfService_CashDrawer_Windows_Devices_PointOfService_CashDrawerStatusUpdatedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::PointOfService::ICashDrawer* arg0,
                                             ABI::Windows::Devices::PointOfService::ICashDrawerStatusUpdatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPCashDrawer>(arg0), _createRtProxy<WDPCashDrawerStatusUpdatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerDataReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerDataReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerDataReceivedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::PointOfService::ClaimedBarcodeScanner*,
                                                       ABI::Windows::Devices::PointOfService::BarcodeScannerDataReceivedEventArgs*>> {
    void (^_delegate)(WDPClaimedBarcodeScanner*, WDPBarcodeScannerDataReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerDataReceivedEventArgs(
        void (^del)(WDPClaimedBarcodeScanner*, WDPBarcodeScannerDataReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerDataReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner* arg0,
                                             ABI::Windows::Devices::PointOfService::IBarcodeScannerDataReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPClaimedBarcodeScanner>(arg0), _createRtProxy<WDPBarcodeScannerDataReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerErrorOccurredEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerErrorOccurredEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerErrorOccurredEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::PointOfService::ClaimedBarcodeScanner*,
                                                       ABI::Windows::Devices::PointOfService::BarcodeScannerErrorOccurredEventArgs*>> {
    void (^_delegate)(WDPClaimedBarcodeScanner*, WDPBarcodeScannerErrorOccurredEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerErrorOccurredEventArgs(
        void (^del)(WDPClaimedBarcodeScanner*, WDPBarcodeScannerErrorOccurredEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerErrorOccurredEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner* arg0,
                                             ABI::Windows::Devices::PointOfService::IBarcodeScannerErrorOccurredEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPClaimedBarcodeScanner>(arg0), _createRtProxy<WDPBarcodeScannerErrorOccurredEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerImagePreviewReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerImagePreviewReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerImagePreviewReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::PointOfService::ClaimedBarcodeScanner*,
                              ABI::Windows::Devices::PointOfService::BarcodeScannerImagePreviewReceivedEventArgs*>> {
    void (^_delegate)(WDPClaimedBarcodeScanner*, WDPBarcodeScannerImagePreviewReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerImagePreviewReceivedEventArgs(
        void (^del)(WDPClaimedBarcodeScanner*, WDPBarcodeScannerImagePreviewReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_PointOfService_ClaimedBarcodeScanner_Windows_Devices_PointOfService_BarcodeScannerImagePreviewReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::PointOfService::IClaimedBarcodeScanner* arg0,
           ABI::Windows::Devices::PointOfService::IBarcodeScannerImagePreviewReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPClaimedBarcodeScanner>(arg0), _createRtProxy<WDPBarcodeScannerImagePreviewReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedCashDrawer_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedCashDrawer_System_Object__DEFINED
class ITypedEventHandler_Windows_Devices_PointOfService_ClaimedCashDrawer_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::PointOfService::ClaimedCashDrawer*, IInspectable*>> {
    void (^_delegate)(WDPClaimedCashDrawer*, RTObject*);

public:
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedCashDrawer_System_Object(void (^del)(WDPClaimedCashDrawer*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_PointOfService_ClaimedCashDrawer_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::PointOfService::IClaimedCashDrawer* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPClaimedCashDrawer>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderAamvaCardDataReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderAamvaCardDataReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderAamvaCardDataReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::PointOfService::ClaimedMagneticStripeReader*,
                              ABI::Windows::Devices::PointOfService::MagneticStripeReaderAamvaCardDataReceivedEventArgs*>> {
    void (^_delegate)(WDPClaimedMagneticStripeReader*, WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderAamvaCardDataReceivedEventArgs(
        void (^del)(WDPClaimedMagneticStripeReader*, WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderAamvaCardDataReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader* arg0,
           ABI::Windows::Devices::PointOfService::IMagneticStripeReaderAamvaCardDataReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPClaimedMagneticStripeReader>(arg0),
                      _createRtProxy<WDPMagneticStripeReaderAamvaCardDataReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderBankCardDataReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderBankCardDataReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderBankCardDataReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::PointOfService::ClaimedMagneticStripeReader*,
                              ABI::Windows::Devices::PointOfService::MagneticStripeReaderBankCardDataReceivedEventArgs*>> {
    void (^_delegate)(WDPClaimedMagneticStripeReader*, WDPMagneticStripeReaderBankCardDataReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderBankCardDataReceivedEventArgs(
        void (^del)(WDPClaimedMagneticStripeReader*, WDPMagneticStripeReaderBankCardDataReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderBankCardDataReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader* arg0,
           ABI::Windows::Devices::PointOfService::IMagneticStripeReaderBankCardDataReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPClaimedMagneticStripeReader>(arg0),
                      _createRtProxy<WDPMagneticStripeReaderBankCardDataReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderErrorOccurredEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderErrorOccurredEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderErrorOccurredEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::PointOfService::ClaimedMagneticStripeReader*,
                              ABI::Windows::Devices::PointOfService::MagneticStripeReaderErrorOccurredEventArgs*>> {
    void (^_delegate)(WDPClaimedMagneticStripeReader*, WDPMagneticStripeReaderErrorOccurredEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderErrorOccurredEventArgs(
        void (^del)(WDPClaimedMagneticStripeReader*, WDPMagneticStripeReaderErrorOccurredEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderErrorOccurredEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader* arg0,
           ABI::Windows::Devices::PointOfService::IMagneticStripeReaderErrorOccurredEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPClaimedMagneticStripeReader>(arg0),
                      _createRtProxy<WDPMagneticStripeReaderErrorOccurredEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::PointOfService::ClaimedMagneticStripeReader*,
                              ABI::Windows::Devices::PointOfService::MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs*>> {
    void (^_delegate)(WDPClaimedMagneticStripeReader*, WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs(
        void (^del)(WDPClaimedMagneticStripeReader*, WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_PointOfService_ClaimedMagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderVendorSpecificCardDataReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::PointOfService::IClaimedMagneticStripeReader* arg0,
           ABI::Windows::Devices::PointOfService::IMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPClaimedMagneticStripeReader>(arg0),
                      _createRtProxy<WDPMagneticStripeReaderVendorSpecificCardDataReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedPosPrinter_Windows_Devices_PointOfService_PosPrinterReleaseDeviceRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_PointOfService_ClaimedPosPrinter_Windows_Devices_PointOfService_PosPrinterReleaseDeviceRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedPosPrinter_Windows_Devices_PointOfService_PosPrinterReleaseDeviceRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::PointOfService::ClaimedPosPrinter*,
                                                       ABI::Windows::Devices::PointOfService::PosPrinterReleaseDeviceRequestedEventArgs*>> {
    void (^_delegate)(WDPClaimedPosPrinter*, WDPPosPrinterReleaseDeviceRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_PointOfService_ClaimedPosPrinter_Windows_Devices_PointOfService_PosPrinterReleaseDeviceRequestedEventArgs(
        void (^del)(WDPClaimedPosPrinter*, WDPPosPrinterReleaseDeviceRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_PointOfService_ClaimedPosPrinter_Windows_Devices_PointOfService_PosPrinterReleaseDeviceRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::PointOfService::IClaimedPosPrinter* arg0,
           ABI::Windows::Devices::PointOfService::IPosPrinterReleaseDeviceRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPClaimedPosPrinter>(arg0), _createRtProxy<WDPPosPrinterReleaseDeviceRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_PointOfService_MagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderStatusUpdatedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_PointOfService_MagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderStatusUpdatedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_PointOfService_MagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderStatusUpdatedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::PointOfService::MagneticStripeReader*,
                              ABI::Windows::Devices::PointOfService::MagneticStripeReaderStatusUpdatedEventArgs*>> {
    void (^_delegate)(WDPMagneticStripeReader*, WDPMagneticStripeReaderStatusUpdatedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_PointOfService_MagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderStatusUpdatedEventArgs(
        void (^del)(WDPMagneticStripeReader*, WDPMagneticStripeReaderStatusUpdatedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_PointOfService_MagneticStripeReader_Windows_Devices_PointOfService_MagneticStripeReaderStatusUpdatedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::PointOfService::IMagneticStripeReader* arg0,
           ABI::Windows::Devices::PointOfService::IMagneticStripeReaderStatusUpdatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPMagneticStripeReader>(arg0), _createRtProxy<WDPMagneticStripeReaderStatusUpdatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_PointOfService_PosPrinter_Windows_Devices_PointOfService_PosPrinterStatusUpdatedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_PointOfService_PosPrinter_Windows_Devices_PointOfService_PosPrinterStatusUpdatedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_PointOfService_PosPrinter_Windows_Devices_PointOfService_PosPrinterStatusUpdatedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::PointOfService::PosPrinter*,
                                                       ABI::Windows::Devices::PointOfService::PosPrinterStatusUpdatedEventArgs*>> {
    void (^_delegate)(WDPPosPrinter*, WDPPosPrinterStatusUpdatedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_PointOfService_PosPrinter_Windows_Devices_PointOfService_PosPrinterStatusUpdatedEventArgs(
        void (^del)(WDPPosPrinter*, WDPPosPrinterStatusUpdatedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_PointOfService_PosPrinter_Windows_Devices_PointOfService_PosPrinterStatusUpdatedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::PointOfService::IPosPrinter* arg0,
                                             ABI::Windows::Devices::PointOfService::IPosPrinterStatusUpdatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPPosPrinter>(arg0), _createRtProxy<WDPPosPrinterStatusUpdatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

typedef IKeyValuePair<HSTRING, HSTRING>* IKeyValuePair_HSTRING_HSTRING_Ptr;
