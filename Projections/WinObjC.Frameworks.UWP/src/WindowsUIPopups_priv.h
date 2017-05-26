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

// WindowsUIPopups_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
static ComPtr<ABI::Windows::UI::Popups::IMessageDialogFactory> WUPIMessageDialogFactory_inst();
static ComPtr<ABI::Windows::UI::Popups::IUICommandFactory> WUPIUICommandFactory_inst();

id RTProxiedNSMutableArray_RTObject_WUPIUICommand_create(IInspectable* val);

@class RTProxiedNSMutableArray_RTObject_WUPIUICommand;

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
