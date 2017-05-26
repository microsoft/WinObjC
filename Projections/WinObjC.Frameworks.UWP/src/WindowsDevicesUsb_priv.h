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

// WindowsDevicesUsb_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
static ComPtr<ABI::Windows::Devices::Usb::IUsbSetupPacketFactory> WDUIUsbSetupPacketFactory_inst();
ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceClassesStatics> WDUIUsbDeviceClassesStatics_inst();
ComPtr<ABI::Windows::Devices::Usb::IUsbDeviceStatics> WDUIUsbDeviceStatics_inst();
ComPtr<ABI::Windows::Devices::Usb::IUsbConfigurationDescriptorStatics> WDUIUsbConfigurationDescriptorStatics_inst();
ComPtr<ABI::Windows::Devices::Usb::IUsbInterfaceDescriptorStatics> WDUIUsbInterfaceDescriptorStatics_inst();
ComPtr<ABI::Windows::Devices::Usb::IUsbEndpointDescriptorStatics> WDUIUsbEndpointDescriptorStatics_inst();

id RTProxiedNSArray_WDUUsbBulkInEndpointDescriptor_create(IInspectable* val);
id RTProxiedNSArray_WDUUsbBulkInPipe_create(IInspectable* val);
id RTProxiedNSArray_WDUUsbBulkOutEndpointDescriptor_create(IInspectable* val);
id RTProxiedNSArray_WDUUsbBulkOutPipe_create(IInspectable* val);
id RTProxiedNSArray_WDUUsbDescriptor_create(IInspectable* val);
id RTProxiedNSArray_WDUUsbInterface_create(IInspectable* val);
id RTProxiedNSArray_WDUUsbInterfaceSetting_create(IInspectable* val);
id RTProxiedNSArray_WDUUsbInterruptInEndpointDescriptor_create(IInspectable* val);
id RTProxiedNSArray_WDUUsbInterruptInPipe_create(IInspectable* val);
id RTProxiedNSArray_WDUUsbInterruptOutEndpointDescriptor_create(IInspectable* val);
id RTProxiedNSArray_WDUUsbInterruptOutPipe_create(IInspectable* val);

@class Nullable_UInt8, RTProxiedNSArray_WDUUsbBulkInEndpointDescriptor, RTProxiedNSArray_WDUUsbBulkInPipe,
    RTProxiedNSArray_WDUUsbBulkOutEndpointDescriptor;
@class RTProxiedNSArray_WDUUsbBulkOutPipe, RTProxiedNSArray_WDUUsbDescriptor, RTProxiedNSArray_WDUUsbInterface,
    RTProxiedNSArray_WDUUsbInterfaceSetting;
@class RTProxiedNSArray_WDUUsbInterruptInEndpointDescriptor, RTProxiedNSArray_WDUUsbInterruptInPipe,
    RTProxiedNSArray_WDUUsbInterruptOutEndpointDescriptor;
@class RTProxiedNSArray_WDUUsbInterruptOutPipe;

#ifndef __ITypedEventHandler_Windows_Devices_Usb_UsbInterruptInPipe_Windows_Devices_Usb_UsbInterruptInEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Usb_UsbInterruptInPipe_Windows_Devices_Usb_UsbInterruptInEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Usb_UsbInterruptInPipe_Windows_Devices_Usb_UsbInterruptInEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Usb::UsbInterruptInPipe*,
                                                                       ABI::Windows::Devices::Usb::UsbInterruptInEventArgs*>> {
    void (^_delegate)(WDUUsbInterruptInPipe*, WDUUsbInterruptInEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Usb_UsbInterruptInPipe_Windows_Devices_Usb_UsbInterruptInEventArgs(
        void (^del)(WDUUsbInterruptInPipe*, WDUUsbInterruptInEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Usb_UsbInterruptInPipe_Windows_Devices_Usb_UsbInterruptInEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Usb::IUsbInterruptInPipe* arg0,
                                             ABI::Windows::Devices::Usb::IUsbInterruptInEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDUUsbInterruptInPipe>(arg0), _createRtProxy<WDUUsbInterruptInEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
