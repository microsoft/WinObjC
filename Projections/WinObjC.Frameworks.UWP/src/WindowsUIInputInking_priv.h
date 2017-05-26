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

// WindowsUIInputInking_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUICore_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsUIInput_priv.h"
#include "WindowsUI_priv.h"
#include "WindowsFoundationNumerics_priv.h"
#include "WindowsStorageStreams_priv.h"
static ComPtr<ABI::Windows::UI::Input::Inking::IInkPresenterRulerFactory> WUIIIInkPresenterRulerFactory_inst();
static ComPtr<ABI::Windows::UI::Input::Inking::IInkPointFactory> WUIIIInkPointFactory_inst();
ComPtr<ABI::Windows::UI::Input::Inking::IInkDrawingAttributesStatics> WUIIIInkDrawingAttributesStatics_inst();

id RTProxiedIterableNSArray_WFPoint_create(IInspectable* val);
id RTProxiedIterableNSArray_WUIIInkPoint_create(IInspectable* val);
id RTProxiedIterableNSArray_WUIIInkStroke_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WUIIInkPoint_create(IInspectable* val);
id RTProxiedNSArray_WUIIInkRecognitionResult_create(IInspectable* val);
id RTProxiedNSArray_WUIIInkRecognizer_create(IInspectable* val);
id RTProxiedNSArray_WUIIInkStroke_create(IInspectable* val);
id RTProxiedNSArray_WUIIInkStrokeRenderingSegment_create(IInspectable* val);

@class RTProxiedIterableNSArray_WFPoint, RTProxiedIterableNSArray_WUIIInkPoint, RTProxiedIterableNSArray_WUIIInkStroke,
    RTProxiedNSArray_NSString;
@class RTProxiedNSArray_WUIIInkPoint, RTProxiedNSArray_WUIIInkRecognitionResult, RTProxiedNSArray_WUIIInkRecognizer,
    RTProxiedNSArray_WUIIInkStroke;
@class RTProxiedNSArray_WUIIInkStrokeRenderingSegment;

#ifndef __ITypedEventHandler_Windows_UI_Input_Inking_InkPresenter_Windows_UI_Input_Inking_InkStrokesCollectedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Inking_InkPresenter_Windows_UI_Input_Inking_InkStrokesCollectedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Inking_InkPresenter_Windows_UI_Input_Inking_InkStrokesCollectedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Inking::InkPresenter*,
                                                                       ABI::Windows::UI::Input::Inking::InkStrokesCollectedEventArgs*>> {
    void (^_delegate)(WUIIInkPresenter*, WUIIInkStrokesCollectedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Inking_InkPresenter_Windows_UI_Input_Inking_InkStrokesCollectedEventArgs(
        void (^del)(WUIIInkPresenter*, WUIIInkStrokesCollectedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Inking_InkPresenter_Windows_UI_Input_Inking_InkStrokesCollectedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Inking::IInkPresenter* arg0,
                                             ABI::Windows::UI::Input::Inking::IInkStrokesCollectedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIIInkPresenter>(arg0), _createRtProxy<WUIIInkStrokesCollectedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Inking_InkPresenter_Windows_UI_Input_Inking_InkStrokesErasedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Inking_InkPresenter_Windows_UI_Input_Inking_InkStrokesErasedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Inking_InkPresenter_Windows_UI_Input_Inking_InkStrokesErasedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Inking::InkPresenter*,
                                                                       ABI::Windows::UI::Input::Inking::InkStrokesErasedEventArgs*>> {
    void (^_delegate)(WUIIInkPresenter*, WUIIInkStrokesErasedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Inking_InkPresenter_Windows_UI_Input_Inking_InkStrokesErasedEventArgs(
        void (^del)(WUIIInkPresenter*, WUIIInkStrokesErasedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Inking_InkPresenter_Windows_UI_Input_Inking_InkStrokesErasedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Inking::IInkPresenter* arg0,
                                             ABI::Windows::UI::Input::Inking::IInkStrokesErasedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIIInkPresenter>(arg0), _createRtProxy<WUIIInkStrokesErasedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Inking_InkStrokeInput_Windows_UI_Core_PointerEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Inking_InkStrokeInput_Windows_UI_Core_PointerEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Inking_InkStrokeInput_Windows_UI_Core_PointerEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Inking::InkStrokeInput*,
                                                                       ABI::Windows::UI::Core::PointerEventArgs*>> {
    void (^_delegate)(WUIIInkStrokeInput*, WUCPointerEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Inking_InkStrokeInput_Windows_UI_Core_PointerEventArgs(void (^del)(WUIIInkStrokeInput*,
                                                                                                           WUCPointerEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Inking_InkStrokeInput_Windows_UI_Core_PointerEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Inking::IInkStrokeInput* arg0,
                                             ABI::Windows::UI::Core::IPointerEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIIInkStrokeInput>(arg0), _createRtProxy<WUCPointerEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Inking_InkUnprocessedInput_Windows_UI_Core_PointerEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Inking_InkUnprocessedInput_Windows_UI_Core_PointerEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Inking_InkUnprocessedInput_Windows_UI_Core_PointerEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Inking::InkUnprocessedInput*,
                                                                       ABI::Windows::UI::Core::PointerEventArgs*>> {
    void (^_delegate)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Inking_InkUnprocessedInput_Windows_UI_Core_PointerEventArgs(void (^del)(WUIIInkUnprocessedInput*,
                                                                                                                WUCPointerEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Inking_InkUnprocessedInput_Windows_UI_Core_PointerEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Inking::IInkUnprocessedInput* arg0,
                                             ABI::Windows::UI::Core::IPointerEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIIInkUnprocessedInput>(arg0), _createRtProxy<WUCPointerEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
