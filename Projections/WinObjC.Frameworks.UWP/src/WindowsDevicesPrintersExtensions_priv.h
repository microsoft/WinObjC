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

// WindowsDevicesPrintersExtensions_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Devices::Printers::Extensions::IPrintExtensionContextStatic> WDPEIPrintExtensionContextStatic_inst();

#ifndef __ITypedEventHandler_Windows_Devices_Printers_Extensions_Print3DWorkflow_Windows_Devices_Printers_Extensions_Print3DWorkflowPrintRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Printers_Extensions_Print3DWorkflow_Windows_Devices_Printers_Extensions_Print3DWorkflowPrintRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Printers_Extensions_Print3DWorkflow_Windows_Devices_Printers_Extensions_Print3DWorkflowPrintRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::Printers::Extensions::Print3DWorkflow*,
                              ABI::Windows::Devices::Printers::Extensions::Print3DWorkflowPrintRequestedEventArgs*>> {
    void (^_delegate)(WDPEPrint3DWorkflow*, WDPEPrint3DWorkflowPrintRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Printers_Extensions_Print3DWorkflow_Windows_Devices_Printers_Extensions_Print3DWorkflowPrintRequestedEventArgs(
        void (^del)(WDPEPrint3DWorkflow*, WDPEPrint3DWorkflowPrintRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Printers_Extensions_Print3DWorkflow_Windows_Devices_Printers_Extensions_Print3DWorkflowPrintRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow* arg0,
           ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPEPrint3DWorkflow>(arg0), _createRtProxy<WDPEPrint3DWorkflowPrintRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Printers_Extensions_Print3DWorkflow_Windows_Devices_Printers_Extensions_Print3DWorkflowPrinterChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Printers_Extensions_Print3DWorkflow_Windows_Devices_Printers_Extensions_Print3DWorkflowPrinterChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Printers_Extensions_Print3DWorkflow_Windows_Devices_Printers_Extensions_Print3DWorkflowPrinterChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::Printers::Extensions::Print3DWorkflow*,
                              ABI::Windows::Devices::Printers::Extensions::Print3DWorkflowPrinterChangedEventArgs*>> {
    void (^_delegate)(WDPEPrint3DWorkflow*, WDPEPrint3DWorkflowPrinterChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Printers_Extensions_Print3DWorkflow_Windows_Devices_Printers_Extensions_Print3DWorkflowPrinterChangedEventArgs(
        void (^del)(WDPEPrint3DWorkflow*, WDPEPrint3DWorkflowPrinterChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Printers_Extensions_Print3DWorkflow_Windows_Devices_Printers_Extensions_Print3DWorkflowPrinterChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflow* arg0,
           ABI::Windows::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPEPrint3DWorkflow>(arg0), _createRtProxy<WDPEPrint3DWorkflowPrinterChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_Printers_Extensions_PrintTaskConfiguration_Windows_Devices_Printers_Extensions_PrintTaskConfigurationSaveRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Printers_Extensions_PrintTaskConfiguration_Windows_Devices_Printers_Extensions_PrintTaskConfigurationSaveRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Devices_Printers_Extensions_PrintTaskConfiguration_Windows_Devices_Printers_Extensions_PrintTaskConfigurationSaveRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Devices::Printers::Extensions::PrintTaskConfiguration*,
                              ABI::Windows::Devices::Printers::Extensions::PrintTaskConfigurationSaveRequestedEventArgs*>> {
    void (^_delegate)(WDPEPrintTaskConfiguration*, WDPEPrintTaskConfigurationSaveRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Printers_Extensions_PrintTaskConfiguration_Windows_Devices_Printers_Extensions_PrintTaskConfigurationSaveRequestedEventArgs(
        void (^del)(WDPEPrintTaskConfiguration*, WDPEPrintTaskConfigurationSaveRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Printers_Extensions_PrintTaskConfiguration_Windows_Devices_Printers_Extensions_PrintTaskConfigurationSaveRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfiguration* arg0,
           ABI::Windows::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDPEPrintTaskConfiguration>(arg0),
                      _createRtProxy<WDPEPrintTaskConfigurationSaveRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
