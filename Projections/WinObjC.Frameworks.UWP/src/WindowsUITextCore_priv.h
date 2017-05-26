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

// WindowsUITextCore_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsGlobalization_priv.h"
#include "WindowsUIViewManagement_priv.h"
#include "WindowsUIText_priv.h"
ComPtr<ABI::Windows::UI::Text::Core::ICoreTextServicesManagerStatics> WUTCICoreTextServicesManagerStatics_inst();
ComPtr<ABI::Windows::UI::Text::Core::ICoreTextServicesStatics> WUTCICoreTextServicesStatics_inst();
@interface WUTCCoreTextRange (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Text::Core::CoreTextRange)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Text::Core::CoreTextRange*)internalStruct;
@end
inline WUTCCoreTextRange* WUTCCoreTextRange_create(ABI::Windows::UI::Text::Core::CoreTextRange val) {
    return [WUTCCoreTextRange createWith:val];
}

id RTProxiedNSArray_WUTCCoreTextCompositionSegment_create(IInspectable* val);

@class Nullable_WUTUnderlineType, Nullable_WUVUIElementType, RTProxiedNSArray_WUTCCoreTextCompositionSegment;

#ifndef __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Text::Core::CoreTextEditContext*, IInspectable*>> {
    void (^_delegate)(WUTCCoreTextEditContext*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_System_Object(void (^del)(WUTCCoreTextEditContext*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Text::Core::ICoreTextEditContext* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUTCCoreTextEditContext>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextCompositionCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextCompositionCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextCompositionCompletedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Text::Core::CoreTextEditContext*,
                                                       ABI::Windows::UI::Text::Core::CoreTextCompositionCompletedEventArgs*>> {
    void (^_delegate)(WUTCCoreTextEditContext*, WUTCCoreTextCompositionCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextCompositionCompletedEventArgs(
        void (^del)(WUTCCoreTextEditContext*, WUTCCoreTextCompositionCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextCompositionCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Text::Core::ICoreTextEditContext* arg0,
                                             ABI::Windows::UI::Text::Core::ICoreTextCompositionCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUTCCoreTextEditContext>(arg0), _createRtProxy<WUTCCoreTextCompositionCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextCompositionStartedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextCompositionStartedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextCompositionStartedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Text::Core::CoreTextEditContext*,
                                                       ABI::Windows::UI::Text::Core::CoreTextCompositionStartedEventArgs*>> {
    void (^_delegate)(WUTCCoreTextEditContext*, WUTCCoreTextCompositionStartedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextCompositionStartedEventArgs(
        void (^del)(WUTCCoreTextEditContext*, WUTCCoreTextCompositionStartedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextCompositionStartedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Text::Core::ICoreTextEditContext* arg0,
                                             ABI::Windows::UI::Text::Core::ICoreTextCompositionStartedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUTCCoreTextEditContext>(arg0), _createRtProxy<WUTCCoreTextCompositionStartedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextFormatUpdatingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextFormatUpdatingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextFormatUpdatingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Text::Core::CoreTextEditContext*,
                                                                       ABI::Windows::UI::Text::Core::CoreTextFormatUpdatingEventArgs*>> {
    void (^_delegate)(WUTCCoreTextEditContext*, WUTCCoreTextFormatUpdatingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextFormatUpdatingEventArgs(
        void (^del)(WUTCCoreTextEditContext*, WUTCCoreTextFormatUpdatingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextFormatUpdatingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Text::Core::ICoreTextEditContext* arg0,
                                             ABI::Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUTCCoreTextEditContext>(arg0), _createRtProxy<WUTCCoreTextFormatUpdatingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextLayoutRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextLayoutRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextLayoutRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Text::Core::CoreTextEditContext*,
                                                                       ABI::Windows::UI::Text::Core::CoreTextLayoutRequestedEventArgs*>> {
    void (^_delegate)(WUTCCoreTextEditContext*, WUTCCoreTextLayoutRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextLayoutRequestedEventArgs(
        void (^del)(WUTCCoreTextEditContext*, WUTCCoreTextLayoutRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextLayoutRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Text::Core::ICoreTextEditContext* arg0,
                                             ABI::Windows::UI::Text::Core::ICoreTextLayoutRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUTCCoreTextEditContext>(arg0), _createRtProxy<WUTCCoreTextLayoutRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextSelectionRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextSelectionRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextSelectionRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Text::Core::CoreTextEditContext*,
                                                       ABI::Windows::UI::Text::Core::CoreTextSelectionRequestedEventArgs*>> {
    void (^_delegate)(WUTCCoreTextEditContext*, WUTCCoreTextSelectionRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextSelectionRequestedEventArgs(
        void (^del)(WUTCCoreTextEditContext*, WUTCCoreTextSelectionRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextSelectionRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Text::Core::ICoreTextEditContext* arg0,
                                             ABI::Windows::UI::Text::Core::ICoreTextSelectionRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUTCCoreTextEditContext>(arg0), _createRtProxy<WUTCCoreTextSelectionRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextSelectionUpdatingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextSelectionUpdatingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextSelectionUpdatingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Text::Core::CoreTextEditContext*,
                                                                       ABI::Windows::UI::Text::Core::CoreTextSelectionUpdatingEventArgs*>> {
    void (^_delegate)(WUTCCoreTextEditContext*, WUTCCoreTextSelectionUpdatingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextSelectionUpdatingEventArgs(
        void (^del)(WUTCCoreTextEditContext*, WUTCCoreTextSelectionUpdatingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextSelectionUpdatingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Text::Core::ICoreTextEditContext* arg0,
                                             ABI::Windows::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUTCCoreTextEditContext>(arg0), _createRtProxy<WUTCCoreTextSelectionUpdatingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextTextRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextTextRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextTextRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Text::Core::CoreTextEditContext*,
                                                                       ABI::Windows::UI::Text::Core::CoreTextTextRequestedEventArgs*>> {
    void (^_delegate)(WUTCCoreTextEditContext*, WUTCCoreTextTextRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextTextRequestedEventArgs(
        void (^del)(WUTCCoreTextEditContext*, WUTCCoreTextTextRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextTextRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Text::Core::ICoreTextEditContext* arg0,
                                             ABI::Windows::UI::Text::Core::ICoreTextTextRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUTCCoreTextEditContext>(arg0), _createRtProxy<WUTCCoreTextTextRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextTextUpdatingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextTextUpdatingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextTextUpdatingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Text::Core::CoreTextEditContext*,
                                                                       ABI::Windows::UI::Text::Core::CoreTextTextUpdatingEventArgs*>> {
    void (^_delegate)(WUTCCoreTextEditContext*, WUTCCoreTextTextUpdatingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextTextUpdatingEventArgs(
        void (^del)(WUTCCoreTextEditContext*, WUTCCoreTextTextUpdatingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextTextUpdatingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Text::Core::ICoreTextEditContext* arg0,
                                             ABI::Windows::UI::Text::Core::ICoreTextTextUpdatingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUTCCoreTextEditContext>(arg0), _createRtProxy<WUTCCoreTextTextUpdatingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Text_Core_CoreTextServicesManager_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_Text_Core_CoreTextServicesManager_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_Text_Core_CoreTextServicesManager_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Text::Core::CoreTextServicesManager*, IInspectable*>> {
    void (^_delegate)(WUTCCoreTextServicesManager*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_Text_Core_CoreTextServicesManager_System_Object(void (^del)(WUTCCoreTextServicesManager*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Text_Core_CoreTextServicesManager_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Text::Core::ICoreTextServicesManager* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUTCCoreTextServicesManager>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif
