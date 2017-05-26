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

// WindowsMediaCaptureCore_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsMediaCapture_priv.h"

@class Nullable_UInt32;

#ifndef __ITypedEventHandler_Windows_Media_Capture_Core_VariablePhotoSequenceCapture_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Capture_Core_VariablePhotoSequenceCapture_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Capture_Core_VariablePhotoSequenceCapture_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Capture::Core::VariablePhotoSequenceCapture*, IInspectable*>> {
    void (^_delegate)(WMCCVariablePhotoSequenceCapture*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Capture_Core_VariablePhotoSequenceCapture_System_Object(void (^del)(WMCCVariablePhotoSequenceCapture*,
                                                                                                         RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Capture_Core_VariablePhotoSequenceCapture_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Capture::Core::IVariablePhotoSequenceCapture* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCCVariablePhotoSequenceCapture>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Capture_Core_VariablePhotoSequenceCapture_Windows_Media_Capture_Core_VariablePhotoCapturedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Capture_Core_VariablePhotoSequenceCapture_Windows_Media_Capture_Core_VariablePhotoCapturedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Capture_Core_VariablePhotoSequenceCapture_Windows_Media_Capture_Core_VariablePhotoCapturedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Capture::Core::VariablePhotoSequenceCapture*,
                                                       ABI::Windows::Media::Capture::Core::VariablePhotoCapturedEventArgs*>> {
    void (^_delegate)(WMCCVariablePhotoSequenceCapture*, WMCCVariablePhotoCapturedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Capture_Core_VariablePhotoSequenceCapture_Windows_Media_Capture_Core_VariablePhotoCapturedEventArgs(
        void (^del)(WMCCVariablePhotoSequenceCapture*, WMCCVariablePhotoCapturedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Capture_Core_VariablePhotoSequenceCapture_Windows_Media_Capture_Core_VariablePhotoCapturedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Capture::Core::IVariablePhotoSequenceCapture* arg0,
                                             ABI::Windows::Media::Capture::Core::IVariablePhotoCapturedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCCVariablePhotoSequenceCapture>(arg0), _createRtProxy<WMCCVariablePhotoCapturedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
