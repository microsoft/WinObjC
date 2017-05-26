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

// WindowsUIComposition_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUI_priv.h"
#include "WindowsFoundationNumerics_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsGraphicsDirectX_priv.h"
#include "WindowsGraphicsEffects_priv.h"
#include "WindowsUICore_priv.h"
static ComPtr<ABI::Windows::UI::Composition::ICompositionEffectSourceParameterFactory> WUCICompositionEffectSourceParameterFactory_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString;

#ifndef __ITypedEventHandler_System_Object_Windows_UI_Composition_CompositionBatchCompletedEventArgs__DEFINED
#define __ITypedEventHandler_System_Object_Windows_UI_Composition_CompositionBatchCompletedEventArgs__DEFINED
class ITypedEventHandler_System_Object_Windows_UI_Composition_CompositionBatchCompletedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<IInspectable*, ABI::Windows::UI::Composition::CompositionBatchCompletedEventArgs*>> {
    void (^_delegate)(RTObject*, WUCCompositionBatchCompletedEventArgs*);

public:
    ITypedEventHandler_System_Object_Windows_UI_Composition_CompositionBatchCompletedEventArgs(
        void (^del)(RTObject*, WUCCompositionBatchCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_System_Object_Windows_UI_Composition_CompositionBatchCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Composition::ICompositionBatchCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUCCompositionBatchCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Composition_CompositionGraphicsDevice_Windows_UI_Composition_RenderingDeviceReplacedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Composition_CompositionGraphicsDevice_Windows_UI_Composition_RenderingDeviceReplacedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Composition_CompositionGraphicsDevice_Windows_UI_Composition_RenderingDeviceReplacedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Composition::CompositionGraphicsDevice*,
                                                                       ABI::Windows::UI::Composition::RenderingDeviceReplacedEventArgs*>> {
    void (^_delegate)(WUCCompositionGraphicsDevice*, WUCRenderingDeviceReplacedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Composition_CompositionGraphicsDevice_Windows_UI_Composition_RenderingDeviceReplacedEventArgs(
        void (^del)(WUCCompositionGraphicsDevice*, WUCRenderingDeviceReplacedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Composition_CompositionGraphicsDevice_Windows_UI_Composition_RenderingDeviceReplacedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Composition::ICompositionGraphicsDevice* arg0,
                                             ABI::Windows::UI::Composition::IRenderingDeviceReplacedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCCompositionGraphicsDevice>(arg0), _createRtProxy<WUCRenderingDeviceReplacedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
