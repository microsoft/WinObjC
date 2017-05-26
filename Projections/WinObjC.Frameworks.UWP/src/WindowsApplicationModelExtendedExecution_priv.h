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

// WindowsApplicationModelExtendedExecution_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"

#ifndef __ITypedEventHandler_System_Object_Windows_ApplicationModel_ExtendedExecution_ExtendedExecutionRevokedEventArgs__DEFINED
#define __ITypedEventHandler_System_Object_Windows_ApplicationModel_ExtendedExecution_ExtendedExecutionRevokedEventArgs__DEFINED
class ITypedEventHandler_System_Object_Windows_ApplicationModel_ExtendedExecution_ExtendedExecutionRevokedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              IInspectable*,
                              ABI::Windows::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedEventArgs*>> {
    void (^_delegate)(RTObject*, WAEExtendedExecutionRevokedEventArgs*);

public:
    ITypedEventHandler_System_Object_Windows_ApplicationModel_ExtendedExecution_ExtendedExecutionRevokedEventArgs(
        void (^del)(RTObject*, WAEExtendedExecutionRevokedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_System_Object_Windows_ApplicationModel_ExtendedExecution_ExtendedExecutionRevokedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(IInspectable* arg0, ABI::Windows::ApplicationModel::ExtendedExecution::IExtendedExecutionRevokedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WAEExtendedExecutionRevokedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
