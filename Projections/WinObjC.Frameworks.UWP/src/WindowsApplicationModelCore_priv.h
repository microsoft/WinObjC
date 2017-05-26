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

// WindowsApplicationModelCore_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundationCollections_priv.h"
#include "WindowsApplicationModel_priv.h"
#include "WindowsUICore_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsApplicationModelActivation_priv.h"
ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationExit> WACICoreApplicationExit_inst();
ComPtr<ABI::Windows::ApplicationModel::Core::ICoreImmersiveApplication> WACICoreImmersiveApplication_inst();
ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationUnhandledError> WACICoreApplicationUnhandledError_inst();
ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationUseCount> WACICoreApplicationUseCount_inst();
ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplication2> WACICoreApplication2_inst();
ComPtr<ABI::Windows::ApplicationModel::Core::ICoreImmersiveApplication2> WACICoreImmersiveApplication2_inst();
ComPtr<ABI::Windows::ApplicationModel::Core::ICoreImmersiveApplication3> WACICoreImmersiveApplication3_inst();
ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplication> WACICoreApplication_inst();

id RTProxiedNSArray_WACCoreApplicationView_create(IInspectable* val);

@class RTProxiedNSArray_WACCoreApplicationView;

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

#ifndef __EventHandler_Windows_ApplicationModel_Activation_BackgroundActivatedEventArgs__DEFINED
#define __EventHandler_Windows_ApplicationModel_Activation_BackgroundActivatedEventArgs__DEFINED
class EventHandler_Windows_ApplicationModel_Activation_BackgroundActivatedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::IEventHandler<ABI::Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs*>> {
    void (^_delegate)(RTObject*, WAABackgroundActivatedEventArgs*);

public:
    EventHandler_Windows_ApplicationModel_Activation_BackgroundActivatedEventArgs(void (^del)(RTObject*, WAABackgroundActivatedEventArgs*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_ApplicationModel_Activation_BackgroundActivatedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WAABackgroundActivatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __EventHandler_Windows_ApplicationModel_Core_UnhandledErrorDetectedEventArgs__DEFINED
#define __EventHandler_Windows_ApplicationModel_Core_UnhandledErrorDetectedEventArgs__DEFINED
class EventHandler_Windows_ApplicationModel_Core_UnhandledErrorDetectedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::ApplicationModel::Core::UnhandledErrorDetectedEventArgs*>> {
    void (^_delegate)(RTObject*, WACUnhandledErrorDetectedEventArgs*);

public:
    EventHandler_Windows_ApplicationModel_Core_UnhandledErrorDetectedEventArgs(void (^del)(RTObject*, WACUnhandledErrorDetectedEventArgs*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_ApplicationModel_Core_UnhandledErrorDetectedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::ApplicationModel::Core::IUnhandledErrorDetectedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WACUnhandledErrorDetectedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __EventHandler_Windows_ApplicationModel_EnteredBackgroundEventArgs__DEFINED
#define __EventHandler_Windows_ApplicationModel_EnteredBackgroundEventArgs__DEFINED
class EventHandler_Windows_ApplicationModel_EnteredBackgroundEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::ApplicationModel::EnteredBackgroundEventArgs*>> {
    void (^_delegate)(RTObject*, WAEnteredBackgroundEventArgs*);

public:
    EventHandler_Windows_ApplicationModel_EnteredBackgroundEventArgs(void (^del)(RTObject*, WAEnteredBackgroundEventArgs*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_ApplicationModel_EnteredBackgroundEventArgs() {
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

#ifndef __EventHandler_Windows_ApplicationModel_LeavingBackgroundEventArgs__DEFINED
#define __EventHandler_Windows_ApplicationModel_LeavingBackgroundEventArgs__DEFINED
class EventHandler_Windows_ApplicationModel_LeavingBackgroundEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::ApplicationModel::LeavingBackgroundEventArgs*>> {
    void (^_delegate)(RTObject*, WALeavingBackgroundEventArgs*);

public:
    EventHandler_Windows_ApplicationModel_LeavingBackgroundEventArgs(void (^del)(RTObject*, WALeavingBackgroundEventArgs*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_ApplicationModel_LeavingBackgroundEventArgs() {
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

#ifndef __EventHandler_Windows_ApplicationModel_SuspendingEventArgs__DEFINED
#define __EventHandler_Windows_ApplicationModel_SuspendingEventArgs__DEFINED
class EventHandler_Windows_ApplicationModel_SuspendingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::ApplicationModel::SuspendingEventArgs*>> {
    void (^_delegate)(RTObject*, WASuspendingEventArgs*);

public:
    EventHandler_Windows_ApplicationModel_SuspendingEventArgs(void (^del)(RTObject*, WASuspendingEventArgs*)) : _delegate([del copy]) {
    }
    ~EventHandler_Windows_ApplicationModel_SuspendingEventArgs() {
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

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationViewTitleBar_System_Object__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationViewTitleBar_System_Object__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationViewTitleBar_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Core::CoreApplicationViewTitleBar*, IInspectable*>> {
    void (^_delegate)(WACCoreApplicationViewTitleBar*, RTObject*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationViewTitleBar_System_Object(void (^del)(WACCoreApplicationViewTitleBar*,
                                                                                                           RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationViewTitleBar_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACCoreApplicationViewTitleBar>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationView_Windows_ApplicationModel_Activation_IActivatedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationView_Windows_ApplicationModel_Activation_IActivatedEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationView_Windows_ApplicationModel_Activation_IActivatedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Core::CoreApplicationView*,
                                                                       ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs*>> {
    void (^_delegate)(WACCoreApplicationView*, RTObject<WAAIActivatedEventArgs>*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationView_Windows_ApplicationModel_Activation_IActivatedEventArgs(
        void (^del)(WACCoreApplicationView*, RTObject<WAAIActivatedEventArgs>*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationView_Windows_ApplicationModel_Activation_IActivatedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Core::ICoreApplicationView* arg0,
                                             ABI::Windows::ApplicationModel::Activation::IActivatedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACCoreApplicationView>(arg0), _createRtProxy<WAAIActivatedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationView_Windows_ApplicationModel_Core_HostedViewClosingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationView_Windows_ApplicationModel_Core_HostedViewClosingEventArgs__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationView_Windows_ApplicationModel_Core_HostedViewClosingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Core::CoreApplicationView*,
                                                                       ABI::Windows::ApplicationModel::Core::HostedViewClosingEventArgs*>> {
    void (^_delegate)(WACCoreApplicationView*, WACHostedViewClosingEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationView_Windows_ApplicationModel_Core_HostedViewClosingEventArgs(
        void (^del)(WACCoreApplicationView*, WACHostedViewClosingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationView_Windows_ApplicationModel_Core_HostedViewClosingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Core::ICoreApplicationView* arg0,
                                             ABI::Windows::ApplicationModel::Core::IHostedViewClosingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WACCoreApplicationView>(arg0), _createRtProxy<WACHostedViewClosingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
