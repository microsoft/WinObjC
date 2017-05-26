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

// WindowsPhoneUIInput_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Phone::UI::Input::IHardwareButtonsStatics2> WPUIIHardwareButtonsStatics2_inst();
ComPtr<ABI::Windows::Phone::UI::Input::IHardwareButtonsStatics> WPUIIHardwareButtonsStatics_inst();

#ifndef __EventHandler_Windows_Phone_UI_Input_BackPressedEventArgs__DEFINED
#define __EventHandler_Windows_Phone_UI_Input_BackPressedEventArgs__DEFINED
class EventHandler_Windows_Phone_UI_Input_BackPressedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::Phone::UI::Input::BackPressedEventArgs*>> {
    void (^_delegate)(RTObject*, WPUIBackPressedEventArgs*);

public:
    EventHandler_Windows_Phone_UI_Input_BackPressedEventArgs(void (^del)(RTObject*, WPUIBackPressedEventArgs*)) : _delegate([del copy]) {
    }
    ~EventHandler_Windows_Phone_UI_Input_BackPressedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::Phone::UI::Input::IBackPressedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WPUIBackPressedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __EventHandler_Windows_Phone_UI_Input_CameraEventArgs__DEFINED
#define __EventHandler_Windows_Phone_UI_Input_CameraEventArgs__DEFINED
class EventHandler_Windows_Phone_UI_Input_CameraEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::Phone::UI::Input::CameraEventArgs*>> {
    void (^_delegate)(RTObject*, WPUICameraEventArgs*);

public:
    EventHandler_Windows_Phone_UI_Input_CameraEventArgs(void (^del)(RTObject*, WPUICameraEventArgs*)) : _delegate([del copy]) {
    }
    ~EventHandler_Windows_Phone_UI_Input_CameraEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::Phone::UI::Input::ICameraEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WPUICameraEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
