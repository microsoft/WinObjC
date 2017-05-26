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

// WindowsUIInputInkingCore_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsUICore_priv.h"
#include "WindowsUIInputInking_priv.h"
ComPtr<ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSourceStatics> WUIICICoreInkIndependentInputSourceStatics_inst();
ComPtr<ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSourceStatics> WUIICICoreWetStrokeUpdateSourceStatics_inst();

id RTProxiedNSMutableArray_WUIIInkPoint_create(IInspectable* val);

@class RTProxiedNSMutableArray_WUIIInkPoint;

#ifndef __ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreInkIndependentInputSource_Windows_UI_Core_PointerEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreInkIndependentInputSource_Windows_UI_Core_PointerEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreInkIndependentInputSource_Windows_UI_Core_PointerEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Inking::Core::CoreInkIndependentInputSource*,
                                                       ABI::Windows::UI::Core::PointerEventArgs*>> {
    void (^_delegate)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreInkIndependentInputSource_Windows_UI_Core_PointerEventArgs(
        void (^del)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreInkIndependentInputSource_Windows_UI_Core_PointerEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Inking::Core::ICoreInkIndependentInputSource* arg0,
                                             ABI::Windows::UI::Core::IPointerEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIICCoreInkIndependentInputSource>(arg0), _createRtProxy<WUCPointerEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateSource_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateSource_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateSource_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateSource*,
                                                       ABI::Windows::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs*>> {
    void (^_delegate)(WUIICCoreWetStrokeUpdateSource*, WUIICCoreWetStrokeUpdateEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateSource_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateEventArgs(
        void (^del)(WUIICCoreWetStrokeUpdateSource*, WUIICCoreWetStrokeUpdateEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateSource_Windows_UI_Input_Inking_Core_CoreWetStrokeUpdateEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource* arg0,
                                             ABI::Windows::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIICCoreWetStrokeUpdateSource>(arg0), _createRtProxy<WUIICCoreWetStrokeUpdateEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
