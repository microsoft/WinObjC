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

// WindowsDevicesSmartCards_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsSecurityCryptographyCore_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorStatics2> WDSISmartCardEmulatorStatics2_inst();
ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardEmulatorStatics> WDSISmartCardEmulatorStatics_inst();
static ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupFactory> WDSISmartCardAppletIdGroupFactory_inst();
ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardAppletIdGroupStatics> WDSISmartCardAppletIdGroupStatics_inst();
static ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardAutomaticResponseApduFactory> WDSISmartCardAutomaticResponseApduFactory_inst();
ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics> WDSISmartCardCryptogramGeneratorStatics_inst();
ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardReaderStatics> WDSISmartCardReaderStatics_inst();
ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardProvisioningStatics> WDSISmartCardProvisioningStatics_inst();
ComPtr<ABI::Windows::Devices::SmartCards::ISmartCardProvisioningStatics2> WDSISmartCardProvisioningStatics2_inst();

id RTProxiedIterableNSArray_WDSSmartCardAutomaticResponseApdu_create(IInspectable* val);
id RTProxiedIterableNSArray_WDSSmartCardCryptogramPlacementStep_create(IInspectable* val);
id RTProxiedNSArray_WDSSmartCard_create(IInspectable* val);
id RTProxiedNSArray_WDSSmartCardAppletIdGroupRegistration_create(IInspectable* val);
id RTProxiedNSArray_WDSSmartCardCryptogramAlgorithm_create(IInspectable* val);
id RTProxiedNSArray_WDSSmartCardCryptogramMaterialPackageConfirmationResponseFormat_create(IInspectable* val);
id RTProxiedNSArray_WDSSmartCardCryptogramMaterialPackageFormat_create(IInspectable* val);
id RTProxiedNSArray_WDSSmartCardCryptogramMaterialType_create(IInspectable* val);
id RTProxiedNSArray_WDSSmartCardCryptogramStorageKeyCapabilities_create(IInspectable* val);
id RTProxiedNSMutableArray_RTObject_WSSIBuffer_create(IInspectable* val);

@class Nullable_UInt32, RTProxiedIterableNSArray_WDSSmartCardAutomaticResponseApdu,
    RTProxiedIterableNSArray_WDSSmartCardCryptogramPlacementStep;
@class RTProxiedNSArray_WDSSmartCard, RTProxiedNSArray_WDSSmartCardAppletIdGroupRegistration,
    RTProxiedNSArray_WDSSmartCardCryptogramAlgorithm;
@class RTProxiedNSArray_WDSSmartCardCryptogramMaterialPackageConfirmationResponseFormat,
    RTProxiedNSArray_WDSSmartCardCryptogramMaterialPackageFormat;
@class RTProxiedNSArray_WDSSmartCardCryptogramMaterialType, RTProxiedNSArray_WDSSmartCardCryptogramStorageKeyCapabilities,
    RTProxiedNSMutableArray_RTObject_WSSIBuffer;

#ifndef __ITypedEventHandler_Windows_Devices_SmartCards_SmartCardEmulator_Windows_Devices_SmartCards_SmartCardEmulatorApduReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_SmartCards_SmartCardEmulator_Windows_Devices_SmartCards_SmartCardEmulatorApduReceivedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_SmartCards_SmartCardEmulator_Windows_Devices_SmartCards_SmartCardEmulatorApduReceivedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::SmartCards::SmartCardEmulator*,
                                                       ABI::Windows::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs*>> {
    void (^_delegate)(WDSSmartCardEmulator*, WDSSmartCardEmulatorApduReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_SmartCards_SmartCardEmulator_Windows_Devices_SmartCards_SmartCardEmulatorApduReceivedEventArgs(
        void (^del)(WDSSmartCardEmulator*, WDSSmartCardEmulatorApduReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_SmartCards_SmartCardEmulator_Windows_Devices_SmartCards_SmartCardEmulatorApduReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::SmartCards::ISmartCardEmulator* arg0,
                                             ABI::Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSSmartCardEmulator>(arg0), _createRtProxy<WDSSmartCardEmulatorApduReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_SmartCards_SmartCardEmulator_Windows_Devices_SmartCards_SmartCardEmulatorConnectionDeactivatedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_SmartCards_SmartCardEmulator_Windows_Devices_SmartCards_SmartCardEmulatorConnectionDeactivatedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_SmartCards_SmartCardEmulator_Windows_Devices_SmartCards_SmartCardEmulatorConnectionDeactivatedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::SmartCards::SmartCardEmulator*,
                              ABI::Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs*>> {
    void (^_delegate)(WDSSmartCardEmulator*, WDSSmartCardEmulatorConnectionDeactivatedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_SmartCards_SmartCardEmulator_Windows_Devices_SmartCards_SmartCardEmulatorConnectionDeactivatedEventArgs(
        void (^del)(WDSSmartCardEmulator*, WDSSmartCardEmulatorConnectionDeactivatedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_SmartCards_SmartCardEmulator_Windows_Devices_SmartCards_SmartCardEmulatorConnectionDeactivatedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::SmartCards::ISmartCardEmulator* arg0,
           ABI::Windows::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSSmartCardEmulator>(arg0), _createRtProxy<WDSSmartCardEmulatorConnectionDeactivatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_SmartCards_SmartCardReader_Windows_Devices_SmartCards_CardAddedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_SmartCards_SmartCardReader_Windows_Devices_SmartCards_CardAddedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_SmartCards_SmartCardReader_Windows_Devices_SmartCards_CardAddedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::SmartCards::SmartCardReader*,
                                                                       ABI::Windows::Devices::SmartCards::CardAddedEventArgs*>> {
    void (^_delegate)(WDSSmartCardReader*, WDSCardAddedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_SmartCards_SmartCardReader_Windows_Devices_SmartCards_CardAddedEventArgs(
        void (^del)(WDSSmartCardReader*, WDSCardAddedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_SmartCards_SmartCardReader_Windows_Devices_SmartCards_CardAddedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::SmartCards::ISmartCardReader* arg0,
                                             ABI::Windows::Devices::SmartCards::ICardAddedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSSmartCardReader>(arg0), _createRtProxy<WDSCardAddedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_SmartCards_SmartCardReader_Windows_Devices_SmartCards_CardRemovedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_SmartCards_SmartCardReader_Windows_Devices_SmartCards_CardRemovedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_SmartCards_SmartCardReader_Windows_Devices_SmartCards_CardRemovedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::SmartCards::SmartCardReader*,
                                                                       ABI::Windows::Devices::SmartCards::CardRemovedEventArgs*>> {
    void (^_delegate)(WDSSmartCardReader*, WDSCardRemovedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_SmartCards_SmartCardReader_Windows_Devices_SmartCards_CardRemovedEventArgs(
        void (^del)(WDSSmartCardReader*, WDSCardRemovedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_SmartCards_SmartCardReader_Windows_Devices_SmartCards_CardRemovedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::SmartCards::ISmartCardReader* arg0,
                                             ABI::Windows::Devices::SmartCards::ICardRemovedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSSmartCardReader>(arg0), _createRtProxy<WDSCardRemovedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WDSSmartCardPinResetHandler_shim__DEFINED
#define __WDSSmartCardPinResetHandler_shim__DEFINED
class WDSSmartCardPinResetHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Devices::SmartCards::ISmartCardPinResetHandler> {
    void (^_delegate)(WDSSmartCardProvisioning*, WDSSmartCardPinResetRequest*);

public:
    WDSSmartCardPinResetHandler_shim(void (^del)(WDSSmartCardProvisioning*, WDSSmartCardPinResetRequest*)) : _delegate([del copy]) {
    }
    ~WDSSmartCardPinResetHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::SmartCards::ISmartCardProvisioning* arg0,
                                             ABI::Windows::Devices::SmartCards::ISmartCardPinResetRequest* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSSmartCardProvisioning>(arg0), _createRtProxy<WDSSmartCardPinResetRequest>(arg1));
            return 0;
        };
    }
};
#endif
