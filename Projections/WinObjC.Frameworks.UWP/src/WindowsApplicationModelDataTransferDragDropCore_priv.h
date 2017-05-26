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

// WindowsApplicationModelDataTransferDragDropCore_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsApplicationModelDataTransfer_priv.h"
#include "WindowsApplicationModelDataTransferDragDrop_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsGraphicsImaging_priv.h"
ComPtr<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManagerStatics> WADDCICoreDragDropManagerStatics_inst();

#ifndef __ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DragDrop_Core_CoreDragDropManager_Windows_ApplicationModel_DataTransfer_DragDrop_Core_CoreDropOperationTargetRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DragDrop_Core_CoreDragDropManager_Windows_ApplicationModel_DataTransfer_DragDrop_Core_CoreDropOperationTargetRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DragDrop_Core_CoreDragDropManager_Windows_ApplicationModel_DataTransfer_DragDrop_Core_CoreDropOperationTargetRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragDropManager*,
                              ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDropOperationTargetRequestedEventArgs*>> {
    void (^_delegate)(WADDCCoreDragDropManager*, WADDCCoreDropOperationTargetRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DragDrop_Core_CoreDragDropManager_Windows_ApplicationModel_DataTransfer_DragDrop_Core_CoreDropOperationTargetRequestedEventArgs(
        void (^del)(WADDCCoreDragDropManager*, WADDCCoreDropOperationTargetRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DragDrop_Core_CoreDragDropManager_Windows_ApplicationModel_DataTransfer_DragDrop_Core_CoreDropOperationTargetRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManager* arg0,
           ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTargetRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WADDCCoreDragDropManager>(arg0), _createRtProxy<WADDCCoreDropOperationTargetRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
