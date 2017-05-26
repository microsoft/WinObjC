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

// WindowsSystemProfile_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsSystem_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::System::Profile::IAnalyticsInfoStatics> WSPIAnalyticsInfoStatics_inst();
ComPtr<ABI::Windows::System::Profile::ISystemIdentificationStatics> WSPISystemIdentificationStatics_inst();
ComPtr<ABI::Windows::System::Profile::IPlatformDiagnosticsAndUsageDataSettingsStatics>
WSPIPlatformDiagnosticsAndUsageDataSettingsStatics_inst();
ComPtr<ABI::Windows::System::Profile::IHardwareIdentificationStatics> WSPIHardwareIdentificationStatics_inst();
ComPtr<ABI::Windows::System::Profile::IRetailInfoStatics> WSPIRetailInfoStatics_inst();
ComPtr<ABI::Windows::System::Profile::IKnownRetailInfoPropertiesStatics> WSPIKnownRetailInfoPropertiesStatics_inst();
ComPtr<ABI::Windows::System::Profile::ISharedModeSettingsStatics> WSPISharedModeSettingsStatics_inst();

id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);

@class RTProxiedNSDictionary_NSString_RTObject;

#ifndef __EventHandler_System_Object__DEFINED
#define __EventHandler_System_Object__DEFINED
class EventHandler_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Foundation::IEventHandler<IInspectable*>> {
    void (^_delegate)(RTObject*, RTObject*);

public:
    EventHandler_System_Object(void (^del)(RTObject*, RTObject*)) : _delegate([del copy]) {
    }
    ~EventHandler_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif
