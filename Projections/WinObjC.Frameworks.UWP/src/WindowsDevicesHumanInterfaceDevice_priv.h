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

// WindowsDevicesHumanInterfaceDevice_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorage_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Devices::HumanInterfaceDevice::IHidDeviceStatics> WDHIHidDeviceStatics_inst();

id RTProxiedNSArray_WDHHidBooleanControl_create(IInspectable* val);
id RTProxiedNSArray_WDHHidBooleanControlDescription_create(IInspectable* val);
id RTProxiedNSArray_WDHHidCollection_create(IInspectable* val);
id RTProxiedNSArray_WDHHidNumericControlDescription_create(IInspectable* val);

@class RTProxiedNSArray_WDHHidBooleanControl, RTProxiedNSArray_WDHHidBooleanControlDescription, RTProxiedNSArray_WDHHidCollection,
    RTProxiedNSArray_WDHHidNumericControlDescription;

#ifndef __ITypedEventHandler_Windows_Devices_HumanInterfaceDevice_HidDevice_Windows_Devices_HumanInterfaceDevice_HidInputReportReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_HumanInterfaceDevice_HidDevice_Windows_Devices_HumanInterfaceDevice_HidInputReportReceivedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_HumanInterfaceDevice_HidDevice_Windows_Devices_HumanInterfaceDevice_HidInputReportReceivedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::HumanInterfaceDevice::HidDevice*,
                                                       ABI::Windows::Devices::HumanInterfaceDevice::HidInputReportReceivedEventArgs*>> {
    void (^_delegate)(WDHHidDevice*, WDHHidInputReportReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_HumanInterfaceDevice_HidDevice_Windows_Devices_HumanInterfaceDevice_HidInputReportReceivedEventArgs(
        void (^del)(WDHHidDevice*, WDHHidInputReportReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_HumanInterfaceDevice_HidDevice_Windows_Devices_HumanInterfaceDevice_HidInputReportReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::HumanInterfaceDevice::IHidDevice* arg0,
                                             ABI::Windows::Devices::HumanInterfaceDevice::IHidInputReportReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDHHidDevice>(arg0), _createRtProxy<WDHHidInputReportReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
