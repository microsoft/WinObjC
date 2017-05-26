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

// WindowsGraphicsDisplay_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
ComPtr<ABI::Windows::Graphics::Display::IDisplayInformationStatics> WGDIDisplayInformationStatics_inst();
ComPtr<ABI::Windows::Graphics::Display::IDisplayPropertiesStatics> WGDIDisplayPropertiesStatics_inst();

@class Nullable_Double;

#ifndef __ITypedEventHandler_Windows_Graphics_Display_DisplayInformation_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Graphics_Display_DisplayInformation_System_Object__DEFINED
class ITypedEventHandler_Windows_Graphics_Display_DisplayInformation_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Graphics::Display::DisplayInformation*, IInspectable*>> {
    void (^_delegate)(WGDDisplayInformation*, RTObject*);

public:
    ITypedEventHandler_Windows_Graphics_Display_DisplayInformation_System_Object(void (^del)(WGDDisplayInformation*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Graphics_Display_DisplayInformation_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Graphics::Display::IDisplayInformation* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WGDDisplayInformation>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WGDDisplayPropertiesEventHandler_shim__DEFINED
#define __WGDDisplayPropertiesEventHandler_shim__DEFINED
class WGDDisplayPropertiesEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Graphics::Display::IDisplayPropertiesEventHandler> {
    void (^_delegate)(RTObject*);

public:
    WGDDisplayPropertiesEventHandler_shim(void (^del)(RTObject*)) : _delegate([del copy]) {
    }
    ~WGDDisplayPropertiesEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0));
            return 0;
        };
    }
};
#endif
