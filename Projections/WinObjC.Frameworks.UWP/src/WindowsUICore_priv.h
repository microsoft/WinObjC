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

// WindowsUICore_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsSystem_priv.h"
#include "WindowsUIInput_priv.h"
#include "WindowsUIPopups_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsFoundationCollections_priv.h"
static ComPtr<ABI::Windows::UI::Core::ICoreCursorFactory> WUCICoreCursorFactory_inst();
ComPtr<ABI::Windows::UI::Core::ICoreWindowStatic> WUCICoreWindowStatic_inst();
ComPtr<ABI::Windows::UI::Core::ICoreWindowResizeManagerStatics> WUCICoreWindowResizeManagerStatics_inst();
ComPtr<ABI::Windows::UI::Core::ISystemNavigationManagerStatics> WUCISystemNavigationManagerStatics_inst();
static ComPtr<ABI::Windows::UI::Core::ICoreWindowDialogFactory> WUCICoreWindowDialogFactory_inst();
static ComPtr<ABI::Windows::UI::Core::ICoreWindowFlyoutFactory> WUCICoreWindowFlyoutFactory_inst();
@interface WUCCorePhysicalKeyStatus (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Core::CorePhysicalKeyStatus)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Core::CorePhysicalKeyStatus*)internalStruct;
@end
inline WUCCorePhysicalKeyStatus* WUCCorePhysicalKeyStatus_create(ABI::Windows::UI::Core::CorePhysicalKeyStatus val) {
    return [WUCCorePhysicalKeyStatus createWith:val];
}
@interface WUCCoreProximityEvaluation (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Core::CoreProximityEvaluation)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Core::CoreProximityEvaluation*)internalStruct;
@end
inline WUCCoreProximityEvaluation* WUCCoreProximityEvaluation_create(ABI::Windows::UI::Core::CoreProximityEvaluation val) {
    return [WUCCoreProximityEvaluation createWith:val];
}

id RTProxiedNSArray_C_WFPoint_create(UINT32 size, ABI::Windows::Foundation::Point* val);
id RTProxiedNSMutableArray_RTObject_WUPIUICommand_create(IInspectable* val);
id RTProxiedNSMutableArray_WUIPointerPoint_create(IInspectable* val);

@class RTProxiedNSArray_C_WFPoint, RTProxiedNSMutableArray_RTObject_WUPIUICommand, RTProxiedNSMutableArray_WUIPointerPoint;

#ifndef __EventHandler_Windows_UI_Core_BackRequestedEventArgs__DEFINED
#define __EventHandler_Windows_UI_Core_BackRequestedEventArgs__DEFINED
class EventHandler_Windows_UI_Core_BackRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::UI::Core::BackRequestedEventArgs*>> {
    void (^_delegate)(RTObject*, WUCBackRequestedEventArgs*);

public:
    EventHandler_Windows_UI_Core_BackRequestedEventArgs(void (^del)(RTObject*, WUCBackRequestedEventArgs*)) : _delegate([del copy]) {
    }
    ~EventHandler_Windows_UI_Core_BackRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Core::IBackRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUCBackRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_System_Object_Windows_UI_Core_CharacterReceivedEventArgs__DEFINED
#define __ITypedEventHandler_System_Object_Windows_UI_Core_CharacterReceivedEventArgs__DEFINED
class ITypedEventHandler_System_Object_Windows_UI_Core_CharacterReceivedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<IInspectable*, ABI::Windows::UI::Core::CharacterReceivedEventArgs*>> {
    void (^_delegate)(RTObject*, WUCCharacterReceivedEventArgs*);

public:
    ITypedEventHandler_System_Object_Windows_UI_Core_CharacterReceivedEventArgs(void (^del)(RTObject*, WUCCharacterReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_System_Object_Windows_UI_Core_CharacterReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Core::ICharacterReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUCCharacterReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_System_Object_Windows_UI_Core_CoreWindowEventArgs__DEFINED
#define __ITypedEventHandler_System_Object_Windows_UI_Core_CoreWindowEventArgs__DEFINED
class ITypedEventHandler_System_Object_Windows_UI_Core_CoreWindowEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<IInspectable*, ABI::Windows::UI::Core::CoreWindowEventArgs*>> {
    void (^_delegate)(RTObject*, WUCCoreWindowEventArgs*);

public:
    ITypedEventHandler_System_Object_Windows_UI_Core_CoreWindowEventArgs(void (^del)(RTObject*, WUCCoreWindowEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_System_Object_Windows_UI_Core_CoreWindowEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Core::ICoreWindowEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUCCoreWindowEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_System_Object_Windows_UI_Core_InputEnabledEventArgs__DEFINED
#define __ITypedEventHandler_System_Object_Windows_UI_Core_InputEnabledEventArgs__DEFINED
class ITypedEventHandler_System_Object_Windows_UI_Core_InputEnabledEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<IInspectable*, ABI::Windows::UI::Core::InputEnabledEventArgs*>> {
    void (^_delegate)(RTObject*, WUCInputEnabledEventArgs*);

public:
    ITypedEventHandler_System_Object_Windows_UI_Core_InputEnabledEventArgs(void (^del)(RTObject*, WUCInputEnabledEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_System_Object_Windows_UI_Core_InputEnabledEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Core::IInputEnabledEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUCInputEnabledEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_System_Object_Windows_UI_Core_KeyEventArgs__DEFINED
#define __ITypedEventHandler_System_Object_Windows_UI_Core_KeyEventArgs__DEFINED
class ITypedEventHandler_System_Object_Windows_UI_Core_KeyEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<IInspectable*, ABI::Windows::UI::Core::KeyEventArgs*>> {
    void (^_delegate)(RTObject*, WUCKeyEventArgs*);

public:
    ITypedEventHandler_System_Object_Windows_UI_Core_KeyEventArgs(void (^del)(RTObject*, WUCKeyEventArgs*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_System_Object_Windows_UI_Core_KeyEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Core::IKeyEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUCKeyEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs__DEFINED
#define __ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs__DEFINED
class ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<IInspectable*, ABI::Windows::UI::Core::PointerEventArgs*>> {
    void (^_delegate)(RTObject*, WUCPointerEventArgs*);

public:
    ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs(void (^del)(RTObject*, WUCPointerEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_System_Object_Windows_UI_Core_PointerEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Core::IPointerEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUCPointerEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_System_Object_Windows_UI_Core_TouchHitTestingEventArgs__DEFINED
#define __ITypedEventHandler_System_Object_Windows_UI_Core_TouchHitTestingEventArgs__DEFINED
class ITypedEventHandler_System_Object_Windows_UI_Core_TouchHitTestingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<IInspectable*, ABI::Windows::UI::Core::TouchHitTestingEventArgs*>> {
    void (^_delegate)(RTObject*, WUCTouchHitTestingEventArgs*);

public:
    ITypedEventHandler_System_Object_Windows_UI_Core_TouchHitTestingEventArgs(void (^del)(RTObject*, WUCTouchHitTestingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_System_Object_Windows_UI_Core_TouchHitTestingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Core::ITouchHitTestingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUCTouchHitTestingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Core_CoreComponentInputSource_Windows_UI_Core_ClosestInteractiveBoundsRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Core_CoreComponentInputSource_Windows_UI_Core_ClosestInteractiveBoundsRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Core_CoreComponentInputSource_Windows_UI_Core_ClosestInteractiveBoundsRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Core::CoreComponentInputSource*,
                                                       ABI::Windows::UI::Core::ClosestInteractiveBoundsRequestedEventArgs*>> {
    void (^_delegate)(WUCCoreComponentInputSource*, WUCClosestInteractiveBoundsRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Core_CoreComponentInputSource_Windows_UI_Core_ClosestInteractiveBoundsRequestedEventArgs(
        void (^del)(WUCCoreComponentInputSource*, WUCClosestInteractiveBoundsRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Core_CoreComponentInputSource_Windows_UI_Core_ClosestInteractiveBoundsRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Core::ICoreInputSourceBase* arg0,
                                             ABI::Windows::UI::Core::IClosestInteractiveBoundsRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCCoreComponentInputSource>(arg0),
                      _createRtProxy<WUCClosestInteractiveBoundsRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Core_CoreDispatcher_Windows_UI_Core_AcceleratorKeyEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Core_CoreDispatcher_Windows_UI_Core_AcceleratorKeyEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Core_CoreDispatcher_Windows_UI_Core_AcceleratorKeyEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Core::CoreDispatcher*,
                                                                       ABI::Windows::UI::Core::AcceleratorKeyEventArgs*>> {
    void (^_delegate)(WUCCoreDispatcher*, WUCAcceleratorKeyEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Core_CoreDispatcher_Windows_UI_Core_AcceleratorKeyEventArgs(void (^del)(WUCCoreDispatcher*,
                                                                                                          WUCAcceleratorKeyEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Core_CoreDispatcher_Windows_UI_Core_AcceleratorKeyEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Core::ICoreDispatcher* arg0,
                                             ABI::Windows::UI::Core::IAcceleratorKeyEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCCoreDispatcher>(arg0), _createRtProxy<WUCAcceleratorKeyEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_AutomationProviderRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_AutomationProviderRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_AutomationProviderRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Core::CoreWindow*,
                                                                       ABI::Windows::UI::Core::AutomationProviderRequestedEventArgs*>> {
    void (^_delegate)(WUCCoreWindow*, WUCAutomationProviderRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_AutomationProviderRequestedEventArgs(
        void (^del)(WUCCoreWindow*, WUCAutomationProviderRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_AutomationProviderRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Core::ICoreWindow* arg0,
                                             ABI::Windows::UI::Core::IAutomationProviderRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCCoreWindow>(arg0), _createRtProxy<WUCAutomationProviderRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CharacterReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CharacterReceivedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CharacterReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Core::CoreWindow*,
                                                                       ABI::Windows::UI::Core::CharacterReceivedEventArgs*>> {
    void (^_delegate)(WUCCoreWindow*, WUCCharacterReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CharacterReceivedEventArgs(void (^del)(WUCCoreWindow*,
                                                                                                         WUCCharacterReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CharacterReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Core::ICoreWindow* arg0,
                                             ABI::Windows::UI::Core::ICharacterReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCCoreWindow>(arg0), _createRtProxy<WUCCharacterReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_ClosestInteractiveBoundsRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_ClosestInteractiveBoundsRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_ClosestInteractiveBoundsRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Core::CoreWindow*,
                                                       ABI::Windows::UI::Core::ClosestInteractiveBoundsRequestedEventArgs*>> {
    void (^_delegate)(WUCCoreWindow*, WUCClosestInteractiveBoundsRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_ClosestInteractiveBoundsRequestedEventArgs(
        void (^del)(WUCCoreWindow*, WUCClosestInteractiveBoundsRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_ClosestInteractiveBoundsRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Core::ICoreWindow* arg0,
                                             ABI::Windows::UI::Core::IClosestInteractiveBoundsRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCCoreWindow>(arg0), _createRtProxy<WUCClosestInteractiveBoundsRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CoreWindowEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CoreWindowEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CoreWindowEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Core::CoreWindow*, ABI::Windows::UI::Core::CoreWindowEventArgs*>> {
    void (^_delegate)(WUCCoreWindow*, WUCCoreWindowEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CoreWindowEventArgs(void (^del)(WUCCoreWindow*, WUCCoreWindowEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CoreWindowEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Core::ICoreWindow* arg0,
                                             ABI::Windows::UI::Core::ICoreWindowEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCCoreWindow>(arg0), _createRtProxy<WUCCoreWindowEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CoreWindowPopupShowingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CoreWindowPopupShowingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CoreWindowPopupShowingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Core::CoreWindow*,
                                                                       ABI::Windows::UI::Core::CoreWindowPopupShowingEventArgs*>> {
    void (^_delegate)(WUCCoreWindow*, WUCCoreWindowPopupShowingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CoreWindowPopupShowingEventArgs(
        void (^del)(WUCCoreWindow*, WUCCoreWindowPopupShowingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_CoreWindowPopupShowingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Core::ICoreWindow* arg0,
                                             ABI::Windows::UI::Core::ICoreWindowPopupShowingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCCoreWindow>(arg0), _createRtProxy<WUCCoreWindowPopupShowingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_InputEnabledEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_InputEnabledEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_InputEnabledEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Core::CoreWindow*,
                                                                       ABI::Windows::UI::Core::InputEnabledEventArgs*>> {
    void (^_delegate)(WUCCoreWindow*, WUCInputEnabledEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_InputEnabledEventArgs(void (^del)(WUCCoreWindow*,
                                                                                                    WUCInputEnabledEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_InputEnabledEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Core::ICoreWindow* arg0,
                                             ABI::Windows::UI::Core::IInputEnabledEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCCoreWindow>(arg0), _createRtProxy<WUCInputEnabledEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_KeyEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_KeyEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_KeyEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Core::CoreWindow*, ABI::Windows::UI::Core::KeyEventArgs*>> {
    void (^_delegate)(WUCCoreWindow*, WUCKeyEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_KeyEventArgs(void (^del)(WUCCoreWindow*, WUCKeyEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_KeyEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Core::ICoreWindow* arg0,
                                             ABI::Windows::UI::Core::IKeyEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCCoreWindow>(arg0), _createRtProxy<WUCKeyEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Core::CoreWindow*, ABI::Windows::UI::Core::PointerEventArgs*>> {
    void (^_delegate)(WUCCoreWindow*, WUCPointerEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs(void (^del)(WUCCoreWindow*, WUCPointerEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_PointerEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Core::ICoreWindow* arg0,
                                             ABI::Windows::UI::Core::IPointerEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCCoreWindow>(arg0), _createRtProxy<WUCPointerEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_TouchHitTestingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_TouchHitTestingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_TouchHitTestingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Core::CoreWindow*,
                                                                       ABI::Windows::UI::Core::TouchHitTestingEventArgs*>> {
    void (^_delegate)(WUCCoreWindow*, WUCTouchHitTestingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_TouchHitTestingEventArgs(void (^del)(WUCCoreWindow*,
                                                                                                       WUCTouchHitTestingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_TouchHitTestingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Core::ICoreWindow* arg0,
                                             ABI::Windows::UI::Core::ITouchHitTestingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCCoreWindow>(arg0), _createRtProxy<WUCTouchHitTestingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_VisibilityChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_VisibilityChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_VisibilityChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Core::CoreWindow*,
                                                                       ABI::Windows::UI::Core::VisibilityChangedEventArgs*>> {
    void (^_delegate)(WUCCoreWindow*, WUCVisibilityChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_VisibilityChangedEventArgs(void (^del)(WUCCoreWindow*,
                                                                                                         WUCVisibilityChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_VisibilityChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Core::ICoreWindow* arg0,
                                             ABI::Windows::UI::Core::IVisibilityChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCCoreWindow>(arg0), _createRtProxy<WUCVisibilityChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_WindowActivatedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_WindowActivatedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_WindowActivatedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Core::CoreWindow*,
                                                                       ABI::Windows::UI::Core::WindowActivatedEventArgs*>> {
    void (^_delegate)(WUCCoreWindow*, WUCWindowActivatedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_WindowActivatedEventArgs(void (^del)(WUCCoreWindow*,
                                                                                                       WUCWindowActivatedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_WindowActivatedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Core::ICoreWindow* arg0,
                                             ABI::Windows::UI::Core::IWindowActivatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCCoreWindow>(arg0), _createRtProxy<WUCWindowActivatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_WindowSizeChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_WindowSizeChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_WindowSizeChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Core::CoreWindow*,
                                                                       ABI::Windows::UI::Core::WindowSizeChangedEventArgs*>> {
    void (^_delegate)(WUCCoreWindow*, WUCWindowSizeChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_WindowSizeChangedEventArgs(void (^del)(WUCCoreWindow*,
                                                                                                         WUCWindowSizeChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Core_CoreWindow_Windows_UI_Core_WindowSizeChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Core::ICoreWindow* arg0,
                                             ABI::Windows::UI::Core::IWindowSizeChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCCoreWindow>(arg0), _createRtProxy<WUCWindowSizeChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Core_ICorePointerRedirector_Windows_UI_Core_PointerEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Core_ICorePointerRedirector_Windows_UI_Core_PointerEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Core_ICorePointerRedirector_Windows_UI_Core_PointerEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Core::ICorePointerRedirector*,
                                                                       ABI::Windows::UI::Core::PointerEventArgs*>> {
    void (^_delegate)(RTObject<WUCICorePointerRedirector>*, WUCPointerEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Core_ICorePointerRedirector_Windows_UI_Core_PointerEventArgs(
        void (^del)(RTObject<WUCICorePointerRedirector>*, WUCPointerEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Core_ICorePointerRedirector_Windows_UI_Core_PointerEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Core::ICorePointerRedirector* arg0,
                                             ABI::Windows::UI::Core::IPointerEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCICorePointerRedirector>(arg0), _createRtProxy<WUCPointerEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUCDispatchedHandler_shim__DEFINED
#define __WUCDispatchedHandler_shim__DEFINED
class WUCDispatchedHandler_shim : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Core::IDispatchedHandler> {
    void (^_delegate)();

public:
    WUCDispatchedHandler_shim(void (^del)()) : _delegate([del copy]) {
    }
    ~WUCDispatchedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke() override {
        @autoreleasepool {
            _delegate();
            return 0;
        };
    }
};
#endif

#ifndef __WUCIdleDispatchedHandler_shim__DEFINED
#define __WUCIdleDispatchedHandler_shim__DEFINED
class WUCIdleDispatchedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Core::IIdleDispatchedHandler> {
    void (^_delegate)(WUCIdleDispatchedHandlerArgs*);

public:
    WUCIdleDispatchedHandler_shim(void (^del)(WUCIdleDispatchedHandlerArgs*)) : _delegate([del copy]) {
    }
    ~WUCIdleDispatchedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Core::IIdleDispatchedHandlerArgs* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUCIdleDispatchedHandlerArgs>(arg0));
            return 0;
        };
    }
};
#endif

#ifndef __WUPUICommandInvokedHandler_shim__DEFINED
#define __WUPUICommandInvokedHandler_shim__DEFINED
class WUPUICommandInvokedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Popups::IUICommandInvokedHandler> {
    void (^_delegate)(RTObject<WUPIUICommand>*);

public:
    WUPUICommandInvokedHandler_shim(void (^del)(RTObject<WUPIUICommand>*)) : _delegate([del copy]) {
    }
    ~WUPUICommandInvokedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Popups::IUICommand* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUPIUICommand>(arg0));
            return 0;
        };
    }
};
#endif
