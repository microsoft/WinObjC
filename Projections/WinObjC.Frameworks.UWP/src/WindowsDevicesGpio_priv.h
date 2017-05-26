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

// WindowsDevicesGpio_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsDevicesGpioProvider_priv.h"
ComPtr<ABI::Windows::Devices::Gpio::IGpioControllerStatics> WDGIGpioControllerStatics_inst();
ComPtr<ABI::Windows::Devices::Gpio::IGpioControllerStatics2> WDGIGpioControllerStatics2_inst();

id RTProxiedNSArray_WDGGpioController_create(IInspectable* val);

@class RTProxiedNSArray_WDGGpioController;

#ifndef __ITypedEventHandler_Windows_Devices_Gpio_GpioPin_Windows_Devices_Gpio_GpioPinValueChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Gpio_GpioPin_Windows_Devices_Gpio_GpioPinValueChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Gpio_GpioPin_Windows_Devices_Gpio_GpioPinValueChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Gpio::GpioPin*,
                                                                       ABI::Windows::Devices::Gpio::GpioPinValueChangedEventArgs*>> {
    void (^_delegate)(WDGGpioPin*, WDGGpioPinValueChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Gpio_GpioPin_Windows_Devices_Gpio_GpioPinValueChangedEventArgs(
        void (^del)(WDGGpioPin*, WDGGpioPinValueChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Gpio_GpioPin_Windows_Devices_Gpio_GpioPinValueChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Gpio::IGpioPin* arg0,
                                             ABI::Windows::Devices::Gpio::IGpioPinValueChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDGGpioPin>(arg0), _createRtProxy<WDGGpioPinValueChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
