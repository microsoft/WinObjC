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

// WindowsUIXaml_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUIXamlMedia_priv.h"
#include "WindowsApplicationModelDataTransfer_priv.h"
#include "WindowsUIXamlMediaAnimation_priv.h"
#include "WindowsUIXamlControls_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsGraphicsImaging_priv.h"
#include "WindowsUICore_priv.h"
#include "WindowsApplicationModelDataTransferDragDrop_priv.h"
#include "WindowsUIXamlInterop_priv.h"
#include "WindowsUIXamlMediaImaging_priv.h"
#include "WindowsUIXamlInput_priv.h"
#include "WindowsUIInput_priv.h"
#include "WindowsUIXamlAutomationPeers_priv.h"
#include "WindowsUIXamlMediaMedia3D_priv.h"
#include "WindowsUIXamlData_priv.h"
#include "WindowsUIXamlControlsPrimitives_priv.h"
#include "WindowsApplicationModelActivation_priv.h"
#include "WindowsApplicationModelCore_priv.h"
ComPtr<ABI::Windows::UI::Xaml::ICornerRadiusHelperStatics> WXICornerRadiusHelperStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::IDurationHelperStatics> WXIDurationHelperStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::IThicknessHelperStatics> WXIThicknessHelperStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::IDependencyPropertyStatics> WXIDependencyPropertyStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::IPropertyMetadataStatics> WXIPropertyMetadataStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::IElementSoundPlayerStatics> WXIElementSoundPlayerStatics_inst();
static ComPtr<ABI::Windows::UI::Xaml::ITargetPropertyPathFactory> WXITargetPropertyPathFactory_inst();
ComPtr<ABI::Windows::UI::Xaml::IWindowStatics> WXIWindowStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::IDataTemplateStatics2> WXIDataTemplateStatics2_inst();
static ComPtr<ABI::Windows::UI::Xaml::IPropertyPathFactory> WXIPropertyPathFactory_inst();
static ComPtr<ABI::Windows::UI::Xaml::IStyleFactory> WXIStyleFactory_inst();
ComPtr<ABI::Windows::UI::Xaml::IUIElementStatics4> WXIUIElementStatics4_inst();
ComPtr<ABI::Windows::UI::Xaml::IUIElementStatics> WXIUIElementStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::IUIElementStatics2> WXIUIElementStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::IUIElementStatics3> WXIUIElementStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::IVisualStateManagerStatics> WXIVisualStateManagerStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::IAdaptiveTriggerStatics> WXIAdaptiveTriggerStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::IFrameworkElementStatics> WXIFrameworkElementStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::IFrameworkElementStatics4> WXIFrameworkElementStatics4_inst();
ComPtr<ABI::Windows::UI::Xaml::IFrameworkElementStatics2> WXIFrameworkElementStatics2_inst();
static ComPtr<ABI::Windows::UI::Xaml::ISetterFactory> WXISetterFactory_inst();
ComPtr<ABI::Windows::UI::Xaml::IStateTriggerStatics> WXIStateTriggerStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::IGridLengthHelperStatics> WXIGridLengthHelperStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::IApplicationStatics> WXIApplicationStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::IPointHelperStatics> WXIPointHelperStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::IRectHelperStatics> WXIRectHelperStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::ISizeHelperStatics> WXISizeHelperStatics_inst();
@interface WXCornerRadius (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::CornerRadius)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Xaml::CornerRadius*)internalStruct;
@end
inline WXCornerRadius* WXCornerRadius_create(ABI::Windows::UI::Xaml::CornerRadius val) {
    return [WXCornerRadius createWith:val];
}
@interface WXDuration (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Duration)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Xaml::Duration*)internalStruct;
@end
inline WXDuration* WXDuration_create(ABI::Windows::UI::Xaml::Duration val) {
    return [WXDuration createWith:val];
}
@interface WXThickness (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Thickness)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Xaml::Thickness*)internalStruct;
@end
inline WXThickness* WXThickness_create(ABI::Windows::UI::Xaml::Thickness val) {
    return [WXThickness createWith:val];
}
@interface WXGridLength (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::GridLength)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Xaml::GridLength*)internalStruct;
@end
inline WXGridLength* WXGridLength_create(ABI::Windows::UI::Xaml::GridLength val) {
    return [WXGridLength createWith:val];
}

id RTProxiedIterableNSArray_RTProxiedIterableNSArray_WFPoint_create(IInspectable* val);
id RTProxiedIterableNSArray_WFPoint_create(IInspectable* val);
id RTProxiedNSArray_WUXIPointer_create(IInspectable* val);
id RTProxiedNSMutableArray_WXResourceDictionary_create(IInspectable* val);
id RTProxiedNSMutableArray_WXStateTriggerBase_create(IInspectable* val);
id RTProxiedNSMutableArray_WXVisualState_create(IInspectable* val);
id RTProxiedNSMutableArray_WXVisualStateGroup_create(IInspectable* val);
id RTProxiedNSMutableArray_WXVisualTransition_create(IInspectable* val);
id RTProxiedNSMutableDictionary_RTObject_RTObject_create(IInspectable* val);

@class RTProxiedIterableNSArray_RTProxiedIterableNSArray_WFPoint, RTProxiedIterableNSArray_WFPoint, RTProxiedNSArray_WUXIPointer,
    RTProxiedNSMutableArray_WXResourceDictionary;
@class RTProxiedNSMutableArray_WXStateTriggerBase, RTProxiedNSMutableArray_WXVisualState, RTProxiedNSMutableArray_WXVisualStateGroup;
@class RTProxiedNSMutableArray_WXVisualTransition, RTProxiedNSMutableDictionary_RTObject_RTObject;

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

#ifndef __ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::FrameworkElement*, IInspectable*>> {
    void (^_delegate)(WXFrameworkElement*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_System_Object(void (^del)(WXFrameworkElement*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IFrameworkElement* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXFrameworkElement>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_Windows_UI_Xaml_DataContextChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_Windows_UI_Xaml_DataContextChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_Windows_UI_Xaml_DataContextChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::FrameworkElement*,
                                                                       ABI::Windows::UI::Xaml::DataContextChangedEventArgs*>> {
    void (^_delegate)(WXFrameworkElement*, WXDataContextChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_Windows_UI_Xaml_DataContextChangedEventArgs(
        void (^del)(WXFrameworkElement*, WXDataContextChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_Windows_UI_Xaml_DataContextChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IFrameworkElement* arg0,
                                             ABI::Windows::UI::Xaml::IDataContextChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXFrameworkElement>(arg0), _createRtProxy<WXDataContextChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DragStartingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DragStartingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DragStartingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                                       ABI::Windows::UI::Xaml::DragStartingEventArgs*>> {
    void (^_delegate)(WXUIElement*, WXDragStartingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DragStartingEventArgs(void (^del)(WXUIElement*, WXDragStartingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DragStartingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::IDragStartingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WXDragStartingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DropCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DropCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DropCompletedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                                       ABI::Windows::UI::Xaml::DropCompletedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WXDropCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DropCompletedEventArgs(void (^del)(WXUIElement*,
                                                                                                    WXDropCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DropCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::IDropCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WXDropCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayDismissedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayDismissedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayDismissedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                       ABI::Windows::UI::Xaml::Input::AccessKeyDisplayDismissedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WUXIAccessKeyDisplayDismissedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayDismissedEventArgs(
        void (^del)(WXUIElement*, WUXIAccessKeyDisplayDismissedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayDismissedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::Input::IAccessKeyDisplayDismissedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WUXIAccessKeyDisplayDismissedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                       ABI::Windows::UI::Xaml::Input::AccessKeyDisplayRequestedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WUXIAccessKeyDisplayRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayRequestedEventArgs(
        void (^del)(WXUIElement*, WUXIAccessKeyDisplayRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::Input::IAccessKeyDisplayRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WUXIAccessKeyDisplayRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyInvokedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyInvokedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyInvokedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                                       ABI::Windows::UI::Xaml::Input::AccessKeyInvokedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WUXIAccessKeyInvokedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyInvokedEventArgs(
        void (^del)(WXUIElement*, WUXIAccessKeyInvokedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyInvokedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::Input::IAccessKeyInvokedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WUXIAccessKeyInvokedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_ContextRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_ContextRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_ContextRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                                       ABI::Windows::UI::Xaml::Input::ContextRequestedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WUXIContextRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_ContextRequestedEventArgs(
        void (^del)(WXUIElement*, WUXIContextRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_ContextRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::Input::IContextRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WUXIContextRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_RoutedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_RoutedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_RoutedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*, ABI::Windows::UI::Xaml::RoutedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WXRoutedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_RoutedEventArgs(void (^del)(WXUIElement*, WXRoutedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_RoutedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::IRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WXRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIDoubleTappedEventHandler_shim__DEFINED
#define __WUXIDoubleTappedEventHandler_shim__DEFINED
class WUXIDoubleTappedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IDoubleTappedEventHandler> {
    void (^_delegate)(RTObject*, WUXIDoubleTappedRoutedEventArgs*);

public:
    WUXIDoubleTappedEventHandler_shim(void (^del)(RTObject*, WUXIDoubleTappedRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIDoubleTappedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIDoubleTappedRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIHoldingEventHandler_shim__DEFINED
#define __WUXIHoldingEventHandler_shim__DEFINED
class WUXIHoldingEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IHoldingEventHandler> {
    void (^_delegate)(RTObject*, WUXIHoldingRoutedEventArgs*);

public:
    WUXIHoldingEventHandler_shim(void (^del)(RTObject*, WUXIHoldingRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIHoldingEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Input::IHoldingRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIHoldingRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIKeyEventHandler_shim__DEFINED
#define __WUXIKeyEventHandler_shim__DEFINED
class WUXIKeyEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IKeyEventHandler> {
    void (^_delegate)(RTObject*, WUXIKeyRoutedEventArgs*);

public:
    WUXIKeyEventHandler_shim(void (^del)(RTObject*, WUXIKeyRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIKeyEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIKeyRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIManipulationCompletedEventHandler_shim__DEFINED
#define __WUXIManipulationCompletedEventHandler_shim__DEFINED
class WUXIManipulationCompletedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IManipulationCompletedEventHandler> {
    void (^_delegate)(RTObject*, WUXIManipulationCompletedRoutedEventArgs*);

public:
    WUXIManipulationCompletedEventHandler_shim(void (^del)(RTObject*, WUXIManipulationCompletedRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIManipulationCompletedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIManipulationCompletedRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIManipulationDeltaEventHandler_shim__DEFINED
#define __WUXIManipulationDeltaEventHandler_shim__DEFINED
class WUXIManipulationDeltaEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IManipulationDeltaEventHandler> {
    void (^_delegate)(RTObject*, WUXIManipulationDeltaRoutedEventArgs*);

public:
    WUXIManipulationDeltaEventHandler_shim(void (^del)(RTObject*, WUXIManipulationDeltaRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIManipulationDeltaEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIManipulationDeltaRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIManipulationInertiaStartingEventHandler_shim__DEFINED
#define __WUXIManipulationInertiaStartingEventHandler_shim__DEFINED
class WUXIManipulationInertiaStartingEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingEventHandler> {
    void (^_delegate)(RTObject*, WUXIManipulationInertiaStartingRoutedEventArgs*);

public:
    WUXIManipulationInertiaStartingEventHandler_shim(void (^del)(RTObject*, WUXIManipulationInertiaStartingRoutedEventArgs*))
        : _delegate([del copy]) {
    }
    ~WUXIManipulationInertiaStartingEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIManipulationInertiaStartingRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIManipulationStartedEventHandler_shim__DEFINED
#define __WUXIManipulationStartedEventHandler_shim__DEFINED
class WUXIManipulationStartedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IManipulationStartedEventHandler> {
    void (^_delegate)(RTObject*, WUXIManipulationStartedRoutedEventArgs*);

public:
    WUXIManipulationStartedEventHandler_shim(void (^del)(RTObject*, WUXIManipulationStartedRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIManipulationStartedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIManipulationStartedRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIManipulationStartingEventHandler_shim__DEFINED
#define __WUXIManipulationStartingEventHandler_shim__DEFINED
class WUXIManipulationStartingEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IManipulationStartingEventHandler> {
    void (^_delegate)(RTObject*, WUXIManipulationStartingRoutedEventArgs*);

public:
    WUXIManipulationStartingEventHandler_shim(void (^del)(RTObject*, WUXIManipulationStartingRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIManipulationStartingEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIManipulationStartingRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIPointerEventHandler_shim__DEFINED
#define __WUXIPointerEventHandler_shim__DEFINED
class WUXIPointerEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IPointerEventHandler> {
    void (^_delegate)(RTObject*, WUXIPointerRoutedEventArgs*);

public:
    WUXIPointerEventHandler_shim(void (^del)(RTObject*, WUXIPointerRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIPointerEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIPointerRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIRightTappedEventHandler_shim__DEFINED
#define __WUXIRightTappedEventHandler_shim__DEFINED
class WUXIRightTappedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IRightTappedEventHandler> {
    void (^_delegate)(RTObject*, WUXIRightTappedRoutedEventArgs*);

public:
    WUXIRightTappedEventHandler_shim(void (^del)(RTObject*, WUXIRightTappedRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIRightTappedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIRightTappedRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXITappedEventHandler_shim__DEFINED
#define __WUXITappedEventHandler_shim__DEFINED
class WUXITappedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::ITappedEventHandler> {
    void (^_delegate)(RTObject*, WUXITappedRoutedEventArgs*);

public:
    WUXITappedEventHandler_shim(void (^del)(RTObject*, WUXITappedRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXITappedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Input::ITappedRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXITappedRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXApplicationInitializationCallback_shim__DEFINED
#define __WXApplicationInitializationCallback_shim__DEFINED
class WXApplicationInitializationCallback_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IApplicationInitializationCallback> {
    void (^_delegate)(WXApplicationInitializationCallbackParams*);

public:
    WXApplicationInitializationCallback_shim(void (^del)(WXApplicationInitializationCallbackParams*)) : _delegate([del copy]) {
    }
    ~WXApplicationInitializationCallback_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IApplicationInitializationCallbackParams* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXApplicationInitializationCallbackParams>(arg0));
            return 0;
        };
    }
};
#endif

#ifndef __WXBindingFailedEventHandler_shim__DEFINED
#define __WXBindingFailedEventHandler_shim__DEFINED
class WXBindingFailedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IBindingFailedEventHandler> {
    void (^_delegate)(RTObject*, WXBindingFailedEventArgs*);

public:
    WXBindingFailedEventHandler_shim(void (^del)(RTObject*, WXBindingFailedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXBindingFailedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::IBindingFailedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXBindingFailedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXCreateDefaultValueCallback_shim__DEFINED
#define __WXCreateDefaultValueCallback_shim__DEFINED
class WXCreateDefaultValueCallback_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::ICreateDefaultValueCallback> {
    void (^_delegate)();

public:
    WXCreateDefaultValueCallback_shim(void (^del)()) : _delegate([del copy]) {
    }
    ~WXCreateDefaultValueCallback_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable**) override {
        @autoreleasepool {
            _delegate();
            return 0;
        };
    }
};
#endif

#ifndef __WXDependencyPropertyChangedCallback_shim__DEFINED
#define __WXDependencyPropertyChangedCallback_shim__DEFINED
class WXDependencyPropertyChangedCallback_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IDependencyPropertyChangedCallback> {
    void (^_delegate)(WXDependencyObject*, WXDependencyProperty*);

public:
    WXDependencyPropertyChangedCallback_shim(void (^del)(WXDependencyObject*, WXDependencyProperty*)) : _delegate([del copy]) {
    }
    ~WXDependencyPropertyChangedCallback_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IDependencyObject* arg0,
                                             ABI::Windows::UI::Xaml::IDependencyProperty* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXDependencyObject>(arg0), _createRtProxy<WXDependencyProperty>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXDragEventHandler_shim__DEFINED
#define __WXDragEventHandler_shim__DEFINED
class WXDragEventHandler_shim : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IDragEventHandler> {
    void (^_delegate)(RTObject*, WXDragEventArgs*);

public:
    WXDragEventHandler_shim(void (^del)(RTObject*, WXDragEventArgs*)) : _delegate([del copy]) {
    }
    ~WXDragEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::IDragEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXDragEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXEnteredBackgroundEventHandler_shim__DEFINED
#define __WXEnteredBackgroundEventHandler_shim__DEFINED
class WXEnteredBackgroundEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IEnteredBackgroundEventHandler> {
    void (^_delegate)(RTObject*, WAEnteredBackgroundEventArgs*);

public:
    WXEnteredBackgroundEventHandler_shim(void (^del)(RTObject*, WAEnteredBackgroundEventArgs*)) : _delegate([del copy]) {
    }
    ~WXEnteredBackgroundEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::ApplicationModel::IEnteredBackgroundEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WAEnteredBackgroundEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXLeavingBackgroundEventHandler_shim__DEFINED
#define __WXLeavingBackgroundEventHandler_shim__DEFINED
class WXLeavingBackgroundEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::ILeavingBackgroundEventHandler> {
    void (^_delegate)(RTObject*, WALeavingBackgroundEventArgs*);

public:
    WXLeavingBackgroundEventHandler_shim(void (^del)(RTObject*, WALeavingBackgroundEventArgs*)) : _delegate([del copy]) {
    }
    ~WXLeavingBackgroundEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::ApplicationModel::ILeavingBackgroundEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WALeavingBackgroundEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXPropertyChangedCallback_shim__DEFINED
#define __WXPropertyChangedCallback_shim__DEFINED
class WXPropertyChangedCallback_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IPropertyChangedCallback> {
    void (^_delegate)(WXDependencyObject*, WXDependencyPropertyChangedEventArgs*);

public:
    WXPropertyChangedCallback_shim(void (^del)(WXDependencyObject*, WXDependencyPropertyChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXPropertyChangedCallback_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IDependencyObject* arg0,
                                             ABI::Windows::UI::Xaml::IDependencyPropertyChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXDependencyObject>(arg0), _createRtProxy<WXDependencyPropertyChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXRoutedEventHandler_shim__DEFINED
#define __WXRoutedEventHandler_shim__DEFINED
class WXRoutedEventHandler_shim : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IRoutedEventHandler> {
    void (^_delegate)(RTObject*, WXRoutedEventArgs*);

public:
    WXRoutedEventHandler_shim(void (^del)(RTObject*, WXRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXRoutedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::IRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXSizeChangedEventHandler_shim__DEFINED
#define __WXSizeChangedEventHandler_shim__DEFINED
class WXSizeChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::ISizeChangedEventHandler> {
    void (^_delegate)(RTObject*, WXSizeChangedEventArgs*);

public:
    WXSizeChangedEventHandler_shim(void (^del)(RTObject*, WXSizeChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXSizeChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::ISizeChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXSizeChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXSuspendingEventHandler_shim__DEFINED
#define __WXSuspendingEventHandler_shim__DEFINED
class WXSuspendingEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::ISuspendingEventHandler> {
    void (^_delegate)(RTObject*, WASuspendingEventArgs*);

public:
    WXSuspendingEventHandler_shim(void (^del)(RTObject*, WASuspendingEventArgs*)) : _delegate([del copy]) {
    }
    ~WXSuspendingEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::ApplicationModel::ISuspendingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WASuspendingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXUnhandledExceptionEventHandler_shim__DEFINED
#define __WXUnhandledExceptionEventHandler_shim__DEFINED
class WXUnhandledExceptionEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IUnhandledExceptionEventHandler> {
    void (^_delegate)(RTObject*, WXUnhandledExceptionEventArgs*);

public:
    WXUnhandledExceptionEventHandler_shim(void (^del)(RTObject*, WXUnhandledExceptionEventArgs*)) : _delegate([del copy]) {
    }
    ~WXUnhandledExceptionEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::IUnhandledExceptionEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXUnhandledExceptionEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXVisualStateChangedEventHandler_shim__DEFINED
#define __WXVisualStateChangedEventHandler_shim__DEFINED
class WXVisualStateChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IVisualStateChangedEventHandler> {
    void (^_delegate)(RTObject*, WXVisualStateChangedEventArgs*);

public:
    WXVisualStateChangedEventHandler_shim(void (^del)(RTObject*, WXVisualStateChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXVisualStateChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::IVisualStateChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXVisualStateChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXWindowActivatedEventHandler_shim__DEFINED
#define __WXWindowActivatedEventHandler_shim__DEFINED
class WXWindowActivatedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IWindowActivatedEventHandler> {
    void (^_delegate)(RTObject*, WUCWindowActivatedEventArgs*);

public:
    WXWindowActivatedEventHandler_shim(void (^del)(RTObject*, WUCWindowActivatedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXWindowActivatedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Core::IWindowActivatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUCWindowActivatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXWindowClosedEventHandler_shim__DEFINED
#define __WXWindowClosedEventHandler_shim__DEFINED
class WXWindowClosedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IWindowClosedEventHandler> {
    void (^_delegate)(RTObject*, WUCCoreWindowEventArgs*);

public:
    WXWindowClosedEventHandler_shim(void (^del)(RTObject*, WUCCoreWindowEventArgs*)) : _delegate([del copy]) {
    }
    ~WXWindowClosedEventHandler_shim() {
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

#ifndef __WXWindowSizeChangedEventHandler_shim__DEFINED
#define __WXWindowSizeChangedEventHandler_shim__DEFINED
class WXWindowSizeChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IWindowSizeChangedEventHandler> {
    void (^_delegate)(RTObject*, WUCWindowSizeChangedEventArgs*);

public:
    WXWindowSizeChangedEventHandler_shim(void (^del)(RTObject*, WUCWindowSizeChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXWindowSizeChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Core::IWindowSizeChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUCWindowSizeChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXWindowVisibilityChangedEventHandler_shim__DEFINED
#define __WXWindowVisibilityChangedEventHandler_shim__DEFINED
class WXWindowVisibilityChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IWindowVisibilityChangedEventHandler> {
    void (^_delegate)(RTObject*, WUCVisibilityChangedEventArgs*);

public:
    WXWindowVisibilityChangedEventHandler_shim(void (^del)(RTObject*, WUCVisibilityChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXWindowVisibilityChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Core::IVisibilityChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUCVisibilityChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

class WXIUIElementOverrides_RtProxy : public RuntimeClass<ABI::Windows::UI::Xaml::IUIElementOverrides, ComposableBase<>> {
    InspectableClass(L"WXIUIElementOverrides_RtProxy", TrustLevel::BaseTrust) public : RTObject<WXIUIElementOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE OnCreateAutomationPeer(ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer** ret) override {
        auto unmarshaledRet = [_inner onCreateAutomationPeer];
        *ret = _getRtInterface<ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeer>(unmarshaledRet).Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnDisconnectVisualChildren() override {
        [_inner onDisconnectVisualChildren];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE FindSubElementsForTouchTargeting(ABI::Windows::Foundation::Point point_in,
                                                               ABI::Windows::Foundation::Rect boundingRect_in,
                                                               IIterable<IIterable<ABI::Windows::Foundation::Point>*>** ret) override {
        auto unmarshaledRet =
            [_inner findSubElementsForTouchTargeting:WFPoint_create(point_in) boundingRect:WFRect_create(boundingRect_in)];
        *ret = static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<IIterable<ABI::Windows::Foundation::Point>*,
                                                              IIterable<ABI::Windows::Foundation::Point>*>>::type>*>(
            ConvertToIterable<RTProxiedIterableNSArray,
                              ABI::Windows::Foundation::Internal::AggregateType<IIterable<ABI::Windows::Foundation::Point>*,
                                                                                IIterable<ABI::Windows::Foundation::Point>*>,
                              RTProxiedIterableNSArray_WFPoint_create>(unmarshaledRet)
                .Detach());
        return 0;
    }
};

class WXIVisualStateManagerOverrides_RtProxy : public RuntimeClass<ABI::Windows::UI::Xaml::IVisualStateManagerOverrides, ComposableBase<>> {
    InspectableClass(L"WXIVisualStateManagerOverrides_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WXIVisualStateManagerOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE GoToStateCore(ABI::Windows::UI::Xaml::Controls::IControl* control_in,
                                            ABI::Windows::UI::Xaml::IFrameworkElement* templateRoot_in,
                                            HSTRING stateName_in,
                                            ABI::Windows::UI::Xaml::IVisualStateGroup* group_in,
                                            ABI::Windows::UI::Xaml::IVisualState* state_in,
                                            boolean useTransitions_in,
                                            boolean* ret) override {
        auto unmarshaledRet = [_inner goToStateCore:_createRtProxy<WXCControl>(control_in)
                                       templateRoot:_createRtProxy<WXFrameworkElement>(templateRoot_in)
                                          stateName:hstrToNSStr(stateName_in)
                                              group:_createRtProxy<WXVisualStateGroup>(group_in)
                                              state:_createRtProxy<WXVisualState>(state_in)
                                     useTransitions:(BOOL)useTransitions_in];
        *ret = (boolean)unmarshaledRet;
        return 0;
    }
};

class WXIFrameworkElementOverrides_RtProxy : public RuntimeClass<ABI::Windows::UI::Xaml::IFrameworkElementOverrides, ComposableBase<>> {
    InspectableClass(L"WXIFrameworkElementOverrides_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WXIFrameworkElementOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE MeasureOverride(ABI::Windows::Foundation::Size availableSize_in,
                                              ABI::Windows::Foundation::Size* ret) override {
        auto unmarshaledRet = [_inner measureOverride:WFSize_create(availableSize_in)];
        *ret = *[unmarshaledRet internalStruct];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE ArrangeOverride(ABI::Windows::Foundation::Size finalSize_in, ABI::Windows::Foundation::Size* ret) override {
        auto unmarshaledRet = [_inner arrangeOverride:WFSize_create(finalSize_in)];
        *ret = *[unmarshaledRet internalStruct];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnApplyTemplate() override {
        [_inner onApplyTemplate];
        return 0;
    }
};

class WXIFrameworkElementOverrides2_RtProxy : public RuntimeClass<ABI::Windows::UI::Xaml::IFrameworkElementOverrides2, ComposableBase<>> {
    InspectableClass(L"WXIFrameworkElementOverrides2_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WXIFrameworkElementOverrides2>* _inner;
    HRESULT STDMETHODCALLTYPE GoToElementStateCore(HSTRING stateName_in, boolean useTransitions_in, boolean* ret) override {
        auto unmarshaledRet = [_inner goToElementStateCore:hstrToNSStr(stateName_in) useTransitions:(BOOL)useTransitions_in];
        *ret = (boolean)unmarshaledRet;
        return 0;
    }
};

class WXIApplicationOverrides_RtProxy : public RuntimeClass<ABI::Windows::UI::Xaml::IApplicationOverrides, ComposableBase<>> {
    InspectableClass(L"WXIApplicationOverrides_RtProxy", TrustLevel::BaseTrust) public : RTObject<WXIApplicationOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE OnActivated(ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs* args_in) override {
        [_inner onActivated:_createRtProxy<WAAIActivatedEventArgs>(args_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnLaunched(ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs* args_in) override {
        [_inner onLaunched:_createRtProxy<WAALaunchActivatedEventArgs>(args_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnFileActivated(ABI::Windows::ApplicationModel::Activation::IFileActivatedEventArgs* args_in) override {
        [_inner onFileActivated:_createRtProxy<WAAFileActivatedEventArgs>(args_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnSearchActivated(ABI::Windows::ApplicationModel::Activation::ISearchActivatedEventArgs* args_in) override {
        [_inner onSearchActivated:_createRtProxy<WAASearchActivatedEventArgs>(args_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE
    OnShareTargetActivated(ABI::Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs* args_in) override {
        [_inner onShareTargetActivated:_createRtProxy<WAAShareTargetActivatedEventArgs>(args_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE
    OnFileOpenPickerActivated(ABI::Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs* args_in) override {
        [_inner onFileOpenPickerActivated:_createRtProxy<WAAFileOpenPickerActivatedEventArgs>(args_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE
    OnFileSavePickerActivated(ABI::Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs* args_in) override {
        [_inner onFileSavePickerActivated:_createRtProxy<WAAFileSavePickerActivatedEventArgs>(args_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE
    OnCachedFileUpdaterActivated(ABI::Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs* args_in) override {
        [_inner onCachedFileUpdaterActivated:_createRtProxy<WAACachedFileUpdaterActivatedEventArgs>(args_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnWindowCreated(ABI::Windows::UI::Xaml::IWindowCreatedEventArgs* args_in) override {
        [_inner onWindowCreated:_createRtProxy<WXWindowCreatedEventArgs>(args_in)];
        return 0;
    }
};

class WXIApplicationOverrides2_RtProxy : public RuntimeClass<ABI::Windows::UI::Xaml::IApplicationOverrides2, ComposableBase<>> {
    InspectableClass(L"WXIApplicationOverrides2_RtProxy", TrustLevel::BaseTrust) public : RTObject<WXIApplicationOverrides2>* _inner;
    HRESULT STDMETHODCALLTYPE
    OnBackgroundActivated(ABI::Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs* args_in) override {
        [_inner onBackgroundActivated:_createRtProxy<WAABackgroundActivatedEventArgs>(args_in)];
        return 0;
    }
};
