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

// WindowsPhoneMediaDevices_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Phone::Media::Devices::IAudioRoutingManagerStatics> WPMDIAudioRoutingManagerStatics_inst();

#ifndef __ITypedEventHandler_Windows_Phone_Media_Devices_AudioRoutingManager_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Phone_Media_Devices_AudioRoutingManager_System_Object__DEFINED
class ITypedEventHandler_Windows_Phone_Media_Devices_AudioRoutingManager_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Phone::Media::Devices::AudioRoutingManager*, IInspectable*>> {
    void (^_delegate)(WPMDAudioRoutingManager*, RTObject*);

public:
    ITypedEventHandler_Windows_Phone_Media_Devices_AudioRoutingManager_System_Object(void (^del)(WPMDAudioRoutingManager*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Phone_Media_Devices_AudioRoutingManager_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Phone::Media::Devices::IAudioRoutingManager* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WPMDAudioRoutingManager>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif
