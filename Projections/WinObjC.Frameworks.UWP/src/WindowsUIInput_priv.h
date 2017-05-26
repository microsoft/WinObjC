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

// WindowsUIInput_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsDevicesInput_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsUICore_priv.h"
#include "WindowsStorageStreams_priv.h"
ComPtr<ABI::Windows::UI::Input::IEdgeGestureStatics> WUIIEdgeGestureStatics_inst();
ComPtr<ABI::Windows::UI::Input::IKeyboardDeliveryInterceptorStatics> WUIIKeyboardDeliveryInterceptorStatics_inst();
ComPtr<ABI::Windows::UI::Input::IPointerPointStatics> WUIIPointerPointStatics_inst();
ComPtr<ABI::Windows::UI::Input::IPointerVisualizationSettingsStatics> WUIIPointerVisualizationSettingsStatics_inst();
ComPtr<ABI::Windows::UI::Input::IRadialControllerStatics> WUIIRadialControllerStatics_inst();
ComPtr<ABI::Windows::UI::Input::IRadialControllerMenuItemStatics> WUIIRadialControllerMenuItemStatics_inst();
ComPtr<ABI::Windows::UI::Input::IRadialControllerConfigurationStatics> WUIIRadialControllerConfigurationStatics_inst();
@interface WUIManipulationDelta (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Input::ManipulationDelta)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Input::ManipulationDelta*)internalStruct;
@end
inline WUIManipulationDelta* WUIManipulationDelta_create(ABI::Windows::UI::Input::ManipulationDelta val) {
    return [WUIManipulationDelta createWith:val];
}
@interface WUIManipulationVelocities (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Input::ManipulationVelocities)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Input::ManipulationVelocities*)internalStruct;
@end
inline WUIManipulationVelocities* WUIManipulationVelocities_create(ABI::Windows::UI::Input::ManipulationVelocities val) {
    return [WUIManipulationVelocities createWith:val];
}
@interface WUICrossSlideThresholds (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Input::CrossSlideThresholds)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Input::CrossSlideThresholds*)internalStruct;
@end
inline WUICrossSlideThresholds* WUICrossSlideThresholds_create(ABI::Windows::UI::Input::CrossSlideThresholds val) {
    return [WUICrossSlideThresholds createWith:val];
}

id RTProxiedIterableNSArray_WUIRadialControllerSystemMenuItemKind_create(IInspectable* val);
id RTProxiedNSMutableArray_WUIPointerPoint_create(IInspectable* val);
id RTProxiedNSMutableArray_WUIRadialControllerMenuItem_create(IInspectable* val);

@class Nullable_Single, RTProxiedIterableNSArray_WUIRadialControllerSystemMenuItemKind, RTProxiedNSMutableArray_WUIPointerPoint,
    RTProxiedNSMutableArray_WUIRadialControllerMenuItem;

#ifndef __ITypedEventHandler_Windows_UI_Input_EdgeGesture_Windows_UI_Input_EdgeGestureEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_EdgeGesture_Windows_UI_Input_EdgeGestureEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_EdgeGesture_Windows_UI_Input_EdgeGestureEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::EdgeGesture*,
                                                                       ABI::Windows::UI::Input::EdgeGestureEventArgs*>> {
    void (^_delegate)(WUIEdgeGesture*, WUIEdgeGestureEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_EdgeGesture_Windows_UI_Input_EdgeGestureEventArgs(void (^del)(WUIEdgeGesture*,
                                                                                                      WUIEdgeGestureEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_EdgeGesture_Windows_UI_Input_EdgeGestureEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IEdgeGesture* arg0,
                                             ABI::Windows::UI::Input::IEdgeGestureEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIEdgeGesture>(arg0), _createRtProxy<WUIEdgeGestureEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_CrossSlidingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_CrossSlidingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_CrossSlidingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::GestureRecognizer*,
                                                                       ABI::Windows::UI::Input::CrossSlidingEventArgs*>> {
    void (^_delegate)(WUIGestureRecognizer*, WUICrossSlidingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_CrossSlidingEventArgs(void (^del)(WUIGestureRecognizer*,
                                                                                                             WUICrossSlidingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_CrossSlidingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::ICrossSlidingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIGestureRecognizer>(arg0), _createRtProxy<WUICrossSlidingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_DraggingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_DraggingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_DraggingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::GestureRecognizer*,
                                                                       ABI::Windows::UI::Input::DraggingEventArgs*>> {
    void (^_delegate)(WUIGestureRecognizer*, WUIDraggingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_DraggingEventArgs(void (^del)(WUIGestureRecognizer*,
                                                                                                         WUIDraggingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_DraggingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::IDraggingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIGestureRecognizer>(arg0), _createRtProxy<WUIDraggingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_HoldingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_HoldingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_HoldingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::GestureRecognizer*,
                                                                       ABI::Windows::UI::Input::HoldingEventArgs*>> {
    void (^_delegate)(WUIGestureRecognizer*, WUIHoldingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_HoldingEventArgs(void (^del)(WUIGestureRecognizer*,
                                                                                                        WUIHoldingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_HoldingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::IHoldingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIGestureRecognizer>(arg0), _createRtProxy<WUIHoldingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationCompletedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::GestureRecognizer*,
                                                                       ABI::Windows::UI::Input::ManipulationCompletedEventArgs*>> {
    void (^_delegate)(WUIGestureRecognizer*, WUIManipulationCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationCompletedEventArgs(
        void (^del)(WUIGestureRecognizer*, WUIManipulationCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::IManipulationCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIGestureRecognizer>(arg0), _createRtProxy<WUIManipulationCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationInertiaStartingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationInertiaStartingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationInertiaStartingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::GestureRecognizer*,
                                                                       ABI::Windows::UI::Input::ManipulationInertiaStartingEventArgs*>> {
    void (^_delegate)(WUIGestureRecognizer*, WUIManipulationInertiaStartingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationInertiaStartingEventArgs(
        void (^del)(WUIGestureRecognizer*, WUIManipulationInertiaStartingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationInertiaStartingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::IManipulationInertiaStartingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIGestureRecognizer>(arg0), _createRtProxy<WUIManipulationInertiaStartingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationStartedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationStartedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationStartedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::GestureRecognizer*,
                                                                       ABI::Windows::UI::Input::ManipulationStartedEventArgs*>> {
    void (^_delegate)(WUIGestureRecognizer*, WUIManipulationStartedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationStartedEventArgs(
        void (^del)(WUIGestureRecognizer*, WUIManipulationStartedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationStartedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::IManipulationStartedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIGestureRecognizer>(arg0), _createRtProxy<WUIManipulationStartedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationUpdatedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationUpdatedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationUpdatedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::GestureRecognizer*,
                                                                       ABI::Windows::UI::Input::ManipulationUpdatedEventArgs*>> {
    void (^_delegate)(WUIGestureRecognizer*, WUIManipulationUpdatedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationUpdatedEventArgs(
        void (^del)(WUIGestureRecognizer*, WUIManipulationUpdatedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_ManipulationUpdatedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::IManipulationUpdatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIGestureRecognizer>(arg0), _createRtProxy<WUIManipulationUpdatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_RightTappedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_RightTappedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_RightTappedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::GestureRecognizer*,
                                                                       ABI::Windows::UI::Input::RightTappedEventArgs*>> {
    void (^_delegate)(WUIGestureRecognizer*, WUIRightTappedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_RightTappedEventArgs(void (^del)(WUIGestureRecognizer*,
                                                                                                            WUIRightTappedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_RightTappedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::IRightTappedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIGestureRecognizer>(arg0), _createRtProxy<WUIRightTappedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_TappedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_TappedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_TappedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::GestureRecognizer*,
                                                                       ABI::Windows::UI::Input::TappedEventArgs*>> {
    void (^_delegate)(WUIGestureRecognizer*, WUITappedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_TappedEventArgs(void (^del)(WUIGestureRecognizer*,
                                                                                                       WUITappedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_GestureRecognizer_Windows_UI_Input_TappedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IGestureRecognizer* arg0,
                                             ABI::Windows::UI::Input::ITappedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIGestureRecognizer>(arg0), _createRtProxy<WUITappedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_KeyboardDeliveryInterceptor_Windows_UI_Core_KeyEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_KeyboardDeliveryInterceptor_Windows_UI_Core_KeyEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_KeyboardDeliveryInterceptor_Windows_UI_Core_KeyEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::KeyboardDeliveryInterceptor*,
                                                                       ABI::Windows::UI::Core::KeyEventArgs*>> {
    void (^_delegate)(WUIKeyboardDeliveryInterceptor*, WUCKeyEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_KeyboardDeliveryInterceptor_Windows_UI_Core_KeyEventArgs(
        void (^del)(WUIKeyboardDeliveryInterceptor*, WUCKeyEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_KeyboardDeliveryInterceptor_Windows_UI_Core_KeyEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IKeyboardDeliveryInterceptor* arg0,
                                             ABI::Windows::UI::Core::IKeyEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIKeyboardDeliveryInterceptor>(arg0), _createRtProxy<WUCKeyEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_RadialControllerMenuItem_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_RadialControllerMenuItem_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_Input_RadialControllerMenuItem_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::RadialControllerMenuItem*, IInspectable*>> {
    void (^_delegate)(WUIRadialControllerMenuItem*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_Input_RadialControllerMenuItem_System_Object(void (^del)(WUIRadialControllerMenuItem*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_RadialControllerMenuItem_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IRadialControllerMenuItem* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIRadialControllerMenuItem>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_RadialController_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_RadialController_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_Input_RadialController_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::RadialController*, IInspectable*>> {
    void (^_delegate)(WUIRadialController*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_Input_RadialController_System_Object(void (^del)(WUIRadialController*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_RadialController_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IRadialController* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIRadialController>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerButtonClickedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerButtonClickedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerButtonClickedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::RadialController*,
                                                                       ABI::Windows::UI::Input::RadialControllerButtonClickedEventArgs*>> {
    void (^_delegate)(WUIRadialController*, WUIRadialControllerButtonClickedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerButtonClickedEventArgs(
        void (^del)(WUIRadialController*, WUIRadialControllerButtonClickedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerButtonClickedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IRadialController* arg0,
                                             ABI::Windows::UI::Input::IRadialControllerButtonClickedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIRadialController>(arg0), _createRtProxy<WUIRadialControllerButtonClickedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerControlAcquiredEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerControlAcquiredEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerControlAcquiredEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::RadialController*,
                                                       ABI::Windows::UI::Input::RadialControllerControlAcquiredEventArgs*>> {
    void (^_delegate)(WUIRadialController*, WUIRadialControllerControlAcquiredEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerControlAcquiredEventArgs(
        void (^del)(WUIRadialController*, WUIRadialControllerControlAcquiredEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerControlAcquiredEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IRadialController* arg0,
                                             ABI::Windows::UI::Input::IRadialControllerControlAcquiredEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIRadialController>(arg0), _createRtProxy<WUIRadialControllerControlAcquiredEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerRotationChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerRotationChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerRotationChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::RadialController*,
                                                       ABI::Windows::UI::Input::RadialControllerRotationChangedEventArgs*>> {
    void (^_delegate)(WUIRadialController*, WUIRadialControllerRotationChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerRotationChangedEventArgs(
        void (^del)(WUIRadialController*, WUIRadialControllerRotationChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerRotationChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IRadialController* arg0,
                                             ABI::Windows::UI::Input::IRadialControllerRotationChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIRadialController>(arg0), _createRtProxy<WUIRadialControllerRotationChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerScreenContactContinuedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerScreenContactContinuedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerScreenContactContinuedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::RadialController*,
                                                       ABI::Windows::UI::Input::RadialControllerScreenContactContinuedEventArgs*>> {
    void (^_delegate)(WUIRadialController*, WUIRadialControllerScreenContactContinuedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerScreenContactContinuedEventArgs(
        void (^del)(WUIRadialController*, WUIRadialControllerScreenContactContinuedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerScreenContactContinuedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IRadialController* arg0,
                                             ABI::Windows::UI::Input::IRadialControllerScreenContactContinuedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIRadialController>(arg0), _createRtProxy<WUIRadialControllerScreenContactContinuedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerScreenContactStartedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerScreenContactStartedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerScreenContactStartedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Input::RadialController*,
                                                       ABI::Windows::UI::Input::RadialControllerScreenContactStartedEventArgs*>> {
    void (^_delegate)(WUIRadialController*, WUIRadialControllerScreenContactStartedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerScreenContactStartedEventArgs(
        void (^del)(WUIRadialController*, WUIRadialControllerScreenContactStartedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Input_RadialController_Windows_UI_Input_RadialControllerScreenContactStartedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Input::IRadialController* arg0,
                                             ABI::Windows::UI::Input::IRadialControllerScreenContactStartedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUIRadialController>(arg0), _createRtProxy<WUIRadialControllerScreenContactStartedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
