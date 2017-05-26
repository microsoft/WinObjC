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

// WindowsUIViewManagement_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsDevicesEnumeration_priv.h"
#include "WindowsUI_priv.h"
#include "WindowsUIPopups_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsUICore_priv.h"
ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewStatics2> WUVIApplicationViewStatics2_inst();
ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewFullscreenStatics> WUVIApplicationViewFullscreenStatics_inst();
ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewStatics3> WUVIApplicationViewStatics3_inst();
ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewInteropStatics> WUVIApplicationViewInteropStatics_inst();
ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewStatics> WUVIApplicationViewStatics_inst();
ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewSwitcherStatics> WUVIApplicationViewSwitcherStatics_inst();
ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewSwitcherStatics2> WUVIApplicationViewSwitcherStatics2_inst();
ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewTransferContextStatics> WUVIApplicationViewTransferContextStatics_inst();
ComPtr<ABI::Windows::UI::ViewManagement::IInputPaneStatics> WUVIInputPaneStatics_inst();
ComPtr<ABI::Windows::UI::ViewManagement::IProjectionManagerStatics> WUVIProjectionManagerStatics_inst();
ComPtr<ABI::Windows::UI::ViewManagement::IProjectionManagerStatics2> WUVIProjectionManagerStatics2_inst();
ComPtr<ABI::Windows::UI::ViewManagement::IUIViewSettingsStatics> WUVIUIViewSettingsStatics_inst();
ComPtr<ABI::Windows::UI::ViewManagement::IStatusBarStatics> WUVIStatusBarStatics_inst();
ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewScalingStatics> WUVIApplicationViewScalingStatics_inst();

@class Nullable_Double, Nullable_WUColor;

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

#ifndef __ITypedEventHandler_Windows_UI_ViewManagement_AccessibilitySettings_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_ViewManagement_AccessibilitySettings_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_ViewManagement_AccessibilitySettings_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::ViewManagement::AccessibilitySettings*, IInspectable*>> {
    void (^_delegate)(WUVAccessibilitySettings*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_ViewManagement_AccessibilitySettings_System_Object(void (^del)(WUVAccessibilitySettings*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_ViewManagement_AccessibilitySettings_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::ViewManagement::IAccessibilitySettings* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUVAccessibilitySettings>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_ViewManagement_ApplicationView_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_ViewManagement_ApplicationView_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_ViewManagement_ApplicationView_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::ViewManagement::ApplicationView*, IInspectable*>> {
    void (^_delegate)(WUVApplicationView*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_ViewManagement_ApplicationView_System_Object(void (^del)(WUVApplicationView*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_ViewManagement_ApplicationView_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::ViewManagement::IApplicationView* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUVApplicationView>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_ViewManagement_ApplicationView_Windows_UI_ViewManagement_ApplicationViewConsolidatedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_ViewManagement_ApplicationView_Windows_UI_ViewManagement_ApplicationViewConsolidatedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_ViewManagement_ApplicationView_Windows_UI_ViewManagement_ApplicationViewConsolidatedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::ViewManagement::ApplicationView*,
                                                       ABI::Windows::UI::ViewManagement::ApplicationViewConsolidatedEventArgs*>> {
    void (^_delegate)(WUVApplicationView*, WUVApplicationViewConsolidatedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_ViewManagement_ApplicationView_Windows_UI_ViewManagement_ApplicationViewConsolidatedEventArgs(
        void (^del)(WUVApplicationView*, WUVApplicationViewConsolidatedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_ViewManagement_ApplicationView_Windows_UI_ViewManagement_ApplicationViewConsolidatedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::ViewManagement::IApplicationView* arg0,
                                             ABI::Windows::UI::ViewManagement::IApplicationViewConsolidatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUVApplicationView>(arg0), _createRtProxy<WUVApplicationViewConsolidatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_ViewManagement_InputPane_Windows_UI_ViewManagement_InputPaneVisibilityEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_ViewManagement_InputPane_Windows_UI_ViewManagement_InputPaneVisibilityEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_ViewManagement_InputPane_Windows_UI_ViewManagement_InputPaneVisibilityEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::ViewManagement::InputPane*,
                                                                       ABI::Windows::UI::ViewManagement::InputPaneVisibilityEventArgs*>> {
    void (^_delegate)(WUVInputPane*, WUVInputPaneVisibilityEventArgs*);

public:
    ITypedEventHandler_Windows_UI_ViewManagement_InputPane_Windows_UI_ViewManagement_InputPaneVisibilityEventArgs(
        void (^del)(WUVInputPane*, WUVInputPaneVisibilityEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_ViewManagement_InputPane_Windows_UI_ViewManagement_InputPaneVisibilityEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::ViewManagement::IInputPane* arg0,
                                             ABI::Windows::UI::ViewManagement::IInputPaneVisibilityEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUVInputPane>(arg0), _createRtProxy<WUVInputPaneVisibilityEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_ViewManagement_StatusBar_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_ViewManagement_StatusBar_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_ViewManagement_StatusBar_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::ViewManagement::StatusBar*, IInspectable*>> {
    void (^_delegate)(WUVStatusBar*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_ViewManagement_StatusBar_System_Object(void (^del)(WUVStatusBar*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_ViewManagement_StatusBar_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::ViewManagement::IStatusBar* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUVStatusBar>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_ViewManagement_UISettings_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_ViewManagement_UISettings_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_ViewManagement_UISettings_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::ViewManagement::UISettings*, IInspectable*>> {
    void (^_delegate)(WUVUISettings*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_ViewManagement_UISettings_System_Object(void (^del)(WUVUISettings*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_ViewManagement_UISettings_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::ViewManagement::IUISettings* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUVUISettings>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif
