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

// WindowsDevicesInput_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Devices::Input::IPointerDeviceStatics> WDIIPointerDeviceStatics_inst();
ComPtr<ABI::Windows::Devices::Input::IMouseDeviceStatics> WDIIMouseDeviceStatics_inst();
@interface WDIPointerDeviceUsage (Internal)
+ (instancetype)createWith:(ABI::Windows::Devices::Input::PointerDeviceUsage)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Devices::Input::PointerDeviceUsage*)internalStruct;
@end
inline WDIPointerDeviceUsage* WDIPointerDeviceUsage_create(ABI::Windows::Devices::Input::PointerDeviceUsage val) {
    return [WDIPointerDeviceUsage createWith:val];
}
@interface WDIMouseDelta (Internal)
+ (instancetype)createWith:(ABI::Windows::Devices::Input::MouseDelta)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Devices::Input::MouseDelta*)internalStruct;
@end
inline WDIMouseDelta* WDIMouseDelta_create(ABI::Windows::Devices::Input::MouseDelta val) {
    return [WDIMouseDelta createWith:val];
}

id RTProxiedNSArray_WDIPointerDevice_create(IInspectable* val);
id RTProxiedNSArray_WDIPointerDeviceUsage_create(IInspectable* val);

@class RTProxiedNSArray_WDIPointerDevice, RTProxiedNSArray_WDIPointerDeviceUsage;

#ifndef __ITypedEventHandler_Windows_Devices_Input_MouseDevice_Windows_Devices_Input_MouseEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Devices_Input_MouseDevice_Windows_Devices_Input_MouseEventArgs__DEFINED
class ITypedEventHandler_Windows_Devices_Input_MouseDevice_Windows_Devices_Input_MouseEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Devices::Input::MouseDevice*,
                                                                       ABI::Windows::Devices::Input::MouseEventArgs*>> {
    void (^_delegate)(WDIMouseDevice*, WDIMouseEventArgs*);

public:
    ITypedEventHandler_Windows_Devices_Input_MouseDevice_Windows_Devices_Input_MouseEventArgs(void (^del)(WDIMouseDevice*,
                                                                                                          WDIMouseEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Devices_Input_MouseDevice_Windows_Devices_Input_MouseEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Devices::Input::IMouseDevice* arg0,
                                             ABI::Windows::Devices::Input::IMouseEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WDIMouseDevice>(arg0), _createRtProxy<WDIMouseEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
