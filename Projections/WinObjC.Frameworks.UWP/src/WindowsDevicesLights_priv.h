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

// WindowsDevicesLights_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsUI_priv.h"
ComPtr<ABI::Windows::Devices::Lights::ILampStatics> WDLILampStatics_inst();

#ifndef __ITypedEventHandler_Windows_Devices_Lights_Lamp_Windows_Devices_Lights_LampAvailabilityChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Lights_Lamp_Windows_Devices_Lights_LampAvailabilityChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Lights_Lamp_Windows_Devices_Lights_LampAvailabilityChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Lights::Lamp*,
                                                                       ABI::Windows::Devices::Lights::LampAvailabilityChangedEventArgs*>> {
    void (^_delegate)(WDLLamp*, WDLLampAvailabilityChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Lights_Lamp_Windows_Devices_Lights_LampAvailabilityChangedEventArgs(
        void (^del)(WDLLamp*, WDLLampAvailabilityChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Lights_Lamp_Windows_Devices_Lights_LampAvailabilityChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Lights::ILamp* arg0,
                                             ABI::Windows::Devices::Lights::ILampAvailabilityChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDLLamp>(arg0), _createRtProxy<WDLLampAvailabilityChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
