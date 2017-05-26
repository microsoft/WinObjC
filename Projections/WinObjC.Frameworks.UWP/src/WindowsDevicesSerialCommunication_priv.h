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

// WindowsDevicesSerialCommunication_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
ComPtr<ABI::Windows::Devices::SerialCommunication::ISerialDeviceStatics> WDSISerialDeviceStatics_inst();

#ifndef __ITypedEventHandler_Windows_Devices_SerialCommunication_SerialDevice_Windows_Devices_SerialCommunication_ErrorReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_SerialCommunication_SerialDevice_Windows_Devices_SerialCommunication_ErrorReceivedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_SerialCommunication_SerialDevice_Windows_Devices_SerialCommunication_ErrorReceivedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::SerialCommunication::SerialDevice*,
                                                       ABI::Windows::Devices::SerialCommunication::ErrorReceivedEventArgs*>> {
    void (^_delegate)(WDSSerialDevice*, WDSErrorReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_SerialCommunication_SerialDevice_Windows_Devices_SerialCommunication_ErrorReceivedEventArgs(
        void (^del)(WDSSerialDevice*, WDSErrorReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_SerialCommunication_SerialDevice_Windows_Devices_SerialCommunication_ErrorReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::SerialCommunication::ISerialDevice* arg0,
                                             ABI::Windows::Devices::SerialCommunication::IErrorReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSSerialDevice>(arg0), _createRtProxy<WDSErrorReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Devices_SerialCommunication_SerialDevice_Windows_Devices_SerialCommunication_PinChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_SerialCommunication_SerialDevice_Windows_Devices_SerialCommunication_PinChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_SerialCommunication_SerialDevice_Windows_Devices_SerialCommunication_PinChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::SerialCommunication::SerialDevice*,
                                                                       ABI::Windows::Devices::SerialCommunication::PinChangedEventArgs*>> {
    void (^_delegate)(WDSSerialDevice*, WDSPinChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_SerialCommunication_SerialDevice_Windows_Devices_SerialCommunication_PinChangedEventArgs(
        void (^del)(WDSSerialDevice*, WDSPinChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_SerialCommunication_SerialDevice_Windows_Devices_SerialCommunication_PinChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::SerialCommunication::ISerialDevice* arg0,
                                             ABI::Windows::Devices::SerialCommunication::IPinChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDSSerialDevice>(arg0), _createRtProxy<WDSPinChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
