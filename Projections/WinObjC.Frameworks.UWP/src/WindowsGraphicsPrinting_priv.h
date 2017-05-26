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

// WindowsGraphicsPrinting_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsApplicationModelDataTransfer_priv.h"
#include "WindowsStorageStreams_priv.h"
ComPtr<ABI::Windows::Graphics::Printing::IStandardPrintTaskOptionsStatic> WGPIStandardPrintTaskOptionsStatic_inst();
ComPtr<ABI::Windows::Graphics::Printing::IStandardPrintTaskOptionsStatic2> WGPIStandardPrintTaskOptionsStatic2_inst();
ComPtr<ABI::Windows::Graphics::Printing::IPrintManagerStatic2> WGPIPrintManagerStatic2_inst();
ComPtr<ABI::Windows::Graphics::Printing::IPrintManagerStatic> WGPIPrintManagerStatic_inst();
@interface WGPPrintPageDescription (Internal)
+ (instancetype)createWith:(ABI::Windows::Graphics::Printing::PrintPageDescription)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Graphics::Printing::PrintPageDescription*)internalStruct;
@end
inline WGPPrintPageDescription* WGPPrintPageDescription_create(ABI::Windows::Graphics::Printing::PrintPageDescription val) {
    return [WGPPrintPageDescription createWith:val];
}

id RTProxiedNSMutableArray_NSString_create(IInspectable* val);

@class RTProxiedNSMutableArray_NSString;

#ifndef __ITypedEventHandler_Windows_Graphics_Printing_PrintManager_Windows_Graphics_Printing_PrintTaskRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Graphics_Printing_PrintManager_Windows_Graphics_Printing_PrintTaskRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Graphics_Printing_PrintManager_Windows_Graphics_Printing_PrintTaskRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Graphics::Printing::PrintManager*,
                                                                       ABI::Windows::Graphics::Printing::PrintTaskRequestedEventArgs*>> {
    void (^_delegate)(WGPPrintManager*, WGPPrintTaskRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Graphics_Printing_PrintManager_Windows_Graphics_Printing_PrintTaskRequestedEventArgs(
        void (^del)(WGPPrintManager*, WGPPrintTaskRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Graphics_Printing_PrintManager_Windows_Graphics_Printing_PrintTaskRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Graphics::Printing::IPrintManager* arg0,
                                             ABI::Windows::Graphics::Printing::IPrintTaskRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WGPPrintManager>(arg0), _createRtProxy<WGPPrintTaskRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Graphics_Printing_PrintTask_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Graphics_Printing_PrintTask_System_Object__DEFINED
class ITypedEventHandler_Windows_Graphics_Printing_PrintTask_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Graphics::Printing::PrintTask*, IInspectable*>> {
    void (^_delegate)(WGPPrintTask*, RTObject*);

public:
    ITypedEventHandler_Windows_Graphics_Printing_PrintTask_System_Object(void (^del)(WGPPrintTask*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Graphics_Printing_PrintTask_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Graphics::Printing::IPrintTask* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WGPPrintTask>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Graphics_Printing_PrintTask_Windows_Graphics_Printing_PrintTaskCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Graphics_Printing_PrintTask_Windows_Graphics_Printing_PrintTaskCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_Graphics_Printing_PrintTask_Windows_Graphics_Printing_PrintTaskCompletedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Graphics::Printing::PrintTask*,
                                                                       ABI::Windows::Graphics::Printing::PrintTaskCompletedEventArgs*>> {
    void (^_delegate)(WGPPrintTask*, WGPPrintTaskCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_Graphics_Printing_PrintTask_Windows_Graphics_Printing_PrintTaskCompletedEventArgs(
        void (^del)(WGPPrintTask*, WGPPrintTaskCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Graphics_Printing_PrintTask_Windows_Graphics_Printing_PrintTaskCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Graphics::Printing::IPrintTask* arg0,
                                             ABI::Windows::Graphics::Printing::IPrintTaskCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WGPPrintTask>(arg0), _createRtProxy<WGPPrintTaskCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Graphics_Printing_PrintTask_Windows_Graphics_Printing_PrintTaskProgressingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Graphics_Printing_PrintTask_Windows_Graphics_Printing_PrintTaskProgressingEventArgs__DEFINED
class ITypedEventHandler_Windows_Graphics_Printing_PrintTask_Windows_Graphics_Printing_PrintTaskProgressingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Graphics::Printing::PrintTask*,
                                                                       ABI::Windows::Graphics::Printing::PrintTaskProgressingEventArgs*>> {
    void (^_delegate)(WGPPrintTask*, WGPPrintTaskProgressingEventArgs*);

public:
    ITypedEventHandler_Windows_Graphics_Printing_PrintTask_Windows_Graphics_Printing_PrintTaskProgressingEventArgs(
        void (^del)(WGPPrintTask*, WGPPrintTaskProgressingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Graphics_Printing_PrintTask_Windows_Graphics_Printing_PrintTaskProgressingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Graphics::Printing::IPrintTask* arg0,
                                             ABI::Windows::Graphics::Printing::IPrintTaskProgressingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WGPPrintTask>(arg0), _createRtProxy<WGPPrintTaskProgressingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WGPPrintTaskSourceRequestedHandler_shim__DEFINED
#define __WGPPrintTaskSourceRequestedHandler_shim__DEFINED
class WGPPrintTaskSourceRequestedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Graphics::Printing::IPrintTaskSourceRequestedHandler> {
    void (^_delegate)(WGPPrintTaskSourceRequestedArgs*);

public:
    WGPPrintTaskSourceRequestedHandler_shim(void (^del)(WGPPrintTaskSourceRequestedArgs*)) : _delegate([del copy]) {
    }
    ~WGPPrintTaskSourceRequestedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Graphics::Printing::IPrintTaskSourceRequestedArgs* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WGPPrintTaskSourceRequestedArgs>(arg0));
            return 0;
        };
    }
};
#endif
