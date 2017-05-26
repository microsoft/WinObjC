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

// WindowsDevicesGpioProvider_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
static ComPtr<ABI::Windows::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgsFactory>
WDGPIGpioPinProviderValueChangedEventArgsFactory_inst();

id RTProxiedNSArray_RTObject_WDGPIGpioControllerProvider_create(IInspectable* val);

@class RTProxiedNSArray_RTObject_WDGPIGpioControllerProvider;

#ifndef __ITypedEventHandler_Windows_Devices_Gpio_Provider_IGpioPinProvider_Windows_Devices_Gpio_Provider_GpioPinProviderValueChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Gpio_Provider_IGpioPinProvider_Windows_Devices_Gpio_Provider_GpioPinProviderValueChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Gpio_Provider_IGpioPinProvider_Windows_Devices_Gpio_Provider_GpioPinProviderValueChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Gpio::Provider::IGpioPinProvider*,
                                                       ABI::Windows::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs*>> {
    void (^_delegate)(RTObject<WDGPIGpioPinProvider>*, WDGPGpioPinProviderValueChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Gpio_Provider_IGpioPinProvider_Windows_Devices_Gpio_Provider_GpioPinProviderValueChangedEventArgs(
        void (^del)(RTObject<WDGPIGpioPinProvider>*, WDGPGpioPinProviderValueChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Gpio_Provider_IGpioPinProvider_Windows_Devices_Gpio_Provider_GpioPinProviderValueChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Gpio::Provider::IGpioPinProvider* arg0,
                                             ABI::Windows::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDGPIGpioPinProvider>(arg0), _createRtProxy<WDGPGpioPinProviderValueChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
