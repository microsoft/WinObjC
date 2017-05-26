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

// WindowsUIInputSpatial_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsPerceptionPeople_priv.h"
#include "WindowsPerception_priv.h"
#include "WindowsFoundationNumerics_priv.h"
#include "WindowsPerceptionSpatial_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialPointerPoseStatics> WUISISpatialPointerPoseStatics_inst();
static ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizerFactory> WUISISpatialGestureRecognizerFactory_inst();
ComPtr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManagerStatics> WUISISpatialInteractionManagerStatics_inst();

id RTProxiedNSArray_WUISSpatialInteractionSourceState_create(IInspectable* val);

@class Nullable_WFNQuaternion, Nullable_WFNVector3, RTProxiedNSArray_WUISSpatialInteractionSourceState;

#ifndef __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldCanceledEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldCanceledEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldCanceledEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Spatial::SpatialGestureRecognizer*,
                                                                       ABI::Windows::UI::Input::Spatial::SpatialHoldCanceledEventArgs*>> {
    void (^_delegate)(WUISSpatialGestureRecognizer*, WUISSpatialHoldCanceledEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldCanceledEventArgs(
        void (^del)(WUISSpatialGestureRecognizer*, WUISSpatialHoldCanceledEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldCanceledEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::Spatial::ISpatialHoldCanceledEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUISSpatialGestureRecognizer>(arg0), _createRtProxy<WUISSpatialHoldCanceledEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldCompletedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Spatial::SpatialGestureRecognizer*,
                                                                       ABI::Windows::UI::Input::Spatial::SpatialHoldCompletedEventArgs*>> {
    void (^_delegate)(WUISSpatialGestureRecognizer*, WUISSpatialHoldCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldCompletedEventArgs(
        void (^del)(WUISSpatialGestureRecognizer*, WUISSpatialHoldCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::Spatial::ISpatialHoldCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUISSpatialGestureRecognizer>(arg0), _createRtProxy<WUISSpatialHoldCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldStartedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldStartedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldStartedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Spatial::SpatialGestureRecognizer*,
                                                                       ABI::Windows::UI::Input::Spatial::SpatialHoldStartedEventArgs*>> {
    void (^_delegate)(WUISSpatialGestureRecognizer*, WUISSpatialHoldStartedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldStartedEventArgs(
        void (^del)(WUISSpatialGestureRecognizer*, WUISSpatialHoldStartedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialHoldStartedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::Spatial::ISpatialHoldStartedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUISSpatialGestureRecognizer>(arg0), _createRtProxy<WUISSpatialHoldStartedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationCanceledEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationCanceledEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationCanceledEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Spatial::SpatialGestureRecognizer*,
                                                       ABI::Windows::UI::Input::Spatial::SpatialManipulationCanceledEventArgs*>> {
    void (^_delegate)(WUISSpatialGestureRecognizer*, WUISSpatialManipulationCanceledEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationCanceledEventArgs(
        void (^del)(WUISSpatialGestureRecognizer*, WUISSpatialManipulationCanceledEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationCanceledEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::Spatial::ISpatialManipulationCanceledEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUISSpatialGestureRecognizer>(arg0), _createRtProxy<WUISSpatialManipulationCanceledEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationCompletedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Spatial::SpatialGestureRecognizer*,
                                                       ABI::Windows::UI::Input::Spatial::SpatialManipulationCompletedEventArgs*>> {
    void (^_delegate)(WUISSpatialGestureRecognizer*, WUISSpatialManipulationCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationCompletedEventArgs(
        void (^del)(WUISSpatialGestureRecognizer*, WUISSpatialManipulationCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::Spatial::ISpatialManipulationCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUISSpatialGestureRecognizer>(arg0), _createRtProxy<WUISSpatialManipulationCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationStartedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationStartedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationStartedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Spatial::SpatialGestureRecognizer*,
                                                       ABI::Windows::UI::Input::Spatial::SpatialManipulationStartedEventArgs*>> {
    void (^_delegate)(WUISSpatialGestureRecognizer*, WUISSpatialManipulationStartedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationStartedEventArgs(
        void (^del)(WUISSpatialGestureRecognizer*, WUISSpatialManipulationStartedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationStartedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::Spatial::ISpatialManipulationStartedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUISSpatialGestureRecognizer>(arg0), _createRtProxy<WUISSpatialManipulationStartedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationUpdatedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationUpdatedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationUpdatedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Spatial::SpatialGestureRecognizer*,
                                                       ABI::Windows::UI::Input::Spatial::SpatialManipulationUpdatedEventArgs*>> {
    void (^_delegate)(WUISSpatialGestureRecognizer*, WUISSpatialManipulationUpdatedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationUpdatedEventArgs(
        void (^del)(WUISSpatialGestureRecognizer*, WUISSpatialManipulationUpdatedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialManipulationUpdatedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::Spatial::ISpatialManipulationUpdatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUISSpatialGestureRecognizer>(arg0), _createRtProxy<WUISSpatialManipulationUpdatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationCanceledEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationCanceledEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationCanceledEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Spatial::SpatialGestureRecognizer*,
                                                       ABI::Windows::UI::Input::Spatial::SpatialNavigationCanceledEventArgs*>> {
    void (^_delegate)(WUISSpatialGestureRecognizer*, WUISSpatialNavigationCanceledEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationCanceledEventArgs(
        void (^del)(WUISSpatialGestureRecognizer*, WUISSpatialNavigationCanceledEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationCanceledEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::Spatial::ISpatialNavigationCanceledEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUISSpatialGestureRecognizer>(arg0), _createRtProxy<WUISSpatialNavigationCanceledEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationCompletedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Spatial::SpatialGestureRecognizer*,
                                                       ABI::Windows::UI::Input::Spatial::SpatialNavigationCompletedEventArgs*>> {
    void (^_delegate)(WUISSpatialGestureRecognizer*, WUISSpatialNavigationCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationCompletedEventArgs(
        void (^del)(WUISSpatialGestureRecognizer*, WUISSpatialNavigationCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::Spatial::ISpatialNavigationCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUISSpatialGestureRecognizer>(arg0), _createRtProxy<WUISSpatialNavigationCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationStartedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationStartedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationStartedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Spatial::SpatialGestureRecognizer*,
                                                       ABI::Windows::UI::Input::Spatial::SpatialNavigationStartedEventArgs*>> {
    void (^_delegate)(WUISSpatialGestureRecognizer*, WUISSpatialNavigationStartedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationStartedEventArgs(
        void (^del)(WUISSpatialGestureRecognizer*, WUISSpatialNavigationStartedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationStartedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::Spatial::ISpatialNavigationStartedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUISSpatialGestureRecognizer>(arg0), _createRtProxy<WUISSpatialNavigationStartedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationUpdatedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationUpdatedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationUpdatedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Spatial::SpatialGestureRecognizer*,
                                                       ABI::Windows::UI::Input::Spatial::SpatialNavigationUpdatedEventArgs*>> {
    void (^_delegate)(WUISSpatialGestureRecognizer*, WUISSpatialNavigationUpdatedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationUpdatedEventArgs(
        void (^del)(WUISSpatialGestureRecognizer*, WUISSpatialNavigationUpdatedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialNavigationUpdatedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::Spatial::ISpatialNavigationUpdatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUISSpatialGestureRecognizer>(arg0), _createRtProxy<WUISSpatialNavigationUpdatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialRecognitionEndedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialRecognitionEndedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialRecognitionEndedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Spatial::SpatialGestureRecognizer*,
                                                       ABI::Windows::UI::Input::Spatial::SpatialRecognitionEndedEventArgs*>> {
    void (^_delegate)(WUISSpatialGestureRecognizer*, WUISSpatialRecognitionEndedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialRecognitionEndedEventArgs(
        void (^del)(WUISSpatialGestureRecognizer*, WUISSpatialRecognitionEndedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialRecognitionEndedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::Spatial::ISpatialRecognitionEndedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUISSpatialGestureRecognizer>(arg0), _createRtProxy<WUISSpatialRecognitionEndedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialRecognitionStartedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialRecognitionStartedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialRecognitionStartedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Spatial::SpatialGestureRecognizer*,
                                                       ABI::Windows::UI::Input::Spatial::SpatialRecognitionStartedEventArgs*>> {
    void (^_delegate)(WUISSpatialGestureRecognizer*, WUISSpatialRecognitionStartedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialRecognitionStartedEventArgs(
        void (^del)(WUISSpatialGestureRecognizer*, WUISSpatialRecognitionStartedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialRecognitionStartedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::Spatial::ISpatialRecognitionStartedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUISSpatialGestureRecognizer>(arg0), _createRtProxy<WUISSpatialRecognitionStartedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialTappedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialTappedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialTappedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Spatial::SpatialGestureRecognizer*,
                                                                       ABI::Windows::UI::Input::Spatial::SpatialTappedEventArgs*>> {
    void (^_delegate)(WUISSpatialGestureRecognizer*, WUISSpatialTappedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialTappedEventArgs(
        void (^del)(WUISSpatialGestureRecognizer*, WUISSpatialTappedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Spatial_SpatialGestureRecognizer_Windows_UI_Input_Spatial_SpatialTappedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Spatial::ISpatialGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::Spatial::ISpatialTappedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUISSpatialGestureRecognizer>(arg0), _createRtProxy<WUISSpatialTappedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialInteractionManager_Windows_UI_Input_Spatial_SpatialInteractionDetectedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialInteractionManager_Windows_UI_Input_Spatial_SpatialInteractionDetectedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Spatial_SpatialInteractionManager_Windows_UI_Input_Spatial_SpatialInteractionDetectedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Spatial::SpatialInteractionManager*,
                                                       ABI::Windows::UI::Input::Spatial::SpatialInteractionDetectedEventArgs*>> {
    void (^_delegate)(WUISSpatialInteractionManager*, WUISSpatialInteractionDetectedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Spatial_SpatialInteractionManager_Windows_UI_Input_Spatial_SpatialInteractionDetectedEventArgs(
        void (^del)(WUISSpatialInteractionManager*, WUISSpatialInteractionDetectedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Spatial_SpatialInteractionManager_Windows_UI_Input_Spatial_SpatialInteractionDetectedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager* arg0,
                                             ABI::Windows::UI::Input::Spatial::ISpatialInteractionDetectedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUISSpatialInteractionManager>(arg0), _createRtProxy<WUISSpatialInteractionDetectedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialInteractionManager_Windows_UI_Input_Spatial_SpatialInteractionSourceEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_Spatial_SpatialInteractionManager_Windows_UI_Input_Spatial_SpatialInteractionSourceEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_Spatial_SpatialInteractionManager_Windows_UI_Input_Spatial_SpatialInteractionSourceEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::Spatial::SpatialInteractionManager*,
                                                       ABI::Windows::UI::Input::Spatial::SpatialInteractionSourceEventArgs*>> {
    void (^_delegate)(WUISSpatialInteractionManager*, WUISSpatialInteractionSourceEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_Spatial_SpatialInteractionManager_Windows_UI_Input_Spatial_SpatialInteractionSourceEventArgs(
        void (^del)(WUISSpatialInteractionManager*, WUISSpatialInteractionSourceEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_Spatial_SpatialInteractionManager_Windows_UI_Input_Spatial_SpatialInteractionSourceEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager* arg0,
                                             ABI::Windows::UI::Input::Spatial::ISpatialInteractionSourceEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUISSpatialInteractionManager>(arg0), _createRtProxy<WUISSpatialInteractionSourceEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
