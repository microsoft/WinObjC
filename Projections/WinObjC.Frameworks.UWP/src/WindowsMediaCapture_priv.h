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

// WindowsMediaCapture_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsMediaCaptureFrames_priv.h"
#include "WindowsMediaCaptureCore_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsMediaCore_priv.h"
#include "WindowsStorage_priv.h"
#include "WindowsMedia_priv.h"
#include "WindowsMediaMediaProperties_priv.h"
#include "WindowsFoundationCollections_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsMediaDevices_priv.h"
#include "WindowsMediaEffects_priv.h"
#include "WindowsGraphicsImaging_priv.h"
#include "WindowsSystem_priv.h"
ComPtr<ABI::Windows::Media::Capture::IAppCaptureStatics> WMCIAppCaptureStatics_inst();
ComPtr<ABI::Windows::Media::Capture::IMediaCaptureStatics> WMCIMediaCaptureStatics_inst();
ComPtr<ABI::Windows::Media::Capture::IAppCaptureManagerStatics> WMCIAppCaptureManagerStatics_inst();
ComPtr<ABI::Windows::Media::Capture::ICameraOptionsUIStatics> WMCICameraOptionsUIStatics_inst();
ComPtr<ABI::Windows::Media::Capture::IScreenCaptureStatics> WMCIScreenCaptureStatics_inst();
@interface WMCWhiteBalanceGain (Internal)
+ (instancetype)createWith:(ABI::Windows::Media::Capture::WhiteBalanceGain)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Media::Capture::WhiteBalanceGain*)internalStruct;
@end
inline WMCWhiteBalanceGain* WMCWhiteBalanceGain_create(ABI::Windows::Media::Capture::WhiteBalanceGain val) {
    return [WMCWhiteBalanceGain createWith:val];
}

id RTProxiedNSArray_WMCMediaCaptureVideoProfile_create(IInspectable* val);
id RTProxiedNSArray_WMCMediaCaptureVideoProfileMediaDescription_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_WMCFMediaFrameSource_create(IInspectable* val);

@class Nullable_Boolean, Nullable_Double, Nullable_Int32, Nullable_Single, Nullable_UInt32, Nullable_WFRect, Nullable_WFTimeSpan,
    Nullable_WMCWhiteBalanceGain;
@class Nullable_WMDCaptureSceneMode, Nullable_WMDMediaCaptureFocusState, RTProxiedNSArray_WMCMediaCaptureVideoProfile,
    RTProxiedNSArray_WMCMediaCaptureVideoProfileMediaDescription;
@class RTProxiedNSDictionary_NSString_WMCFMediaFrameSource;

#ifndef __ITypedEventHandler_Windows_Media_Capture_AdvancedPhotoCapture_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Capture_AdvancedPhotoCapture_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Capture_AdvancedPhotoCapture_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Capture::AdvancedPhotoCapture*, IInspectable*>> {
    void (^_delegate)(WMCAdvancedPhotoCapture*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Capture_AdvancedPhotoCapture_System_Object(void (^del)(WMCAdvancedPhotoCapture*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Capture_AdvancedPhotoCapture_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Capture::IAdvancedPhotoCapture* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCAdvancedPhotoCapture>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Capture_AdvancedPhotoCapture_Windows_Media_Capture_OptionalReferencePhotoCapturedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Capture_AdvancedPhotoCapture_Windows_Media_Capture_OptionalReferencePhotoCapturedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Capture_AdvancedPhotoCapture_Windows_Media_Capture_OptionalReferencePhotoCapturedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Capture::AdvancedPhotoCapture*,
                                                       ABI::Windows::Media::Capture::OptionalReferencePhotoCapturedEventArgs*>> {
    void (^_delegate)(WMCAdvancedPhotoCapture*, WMCOptionalReferencePhotoCapturedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Capture_AdvancedPhotoCapture_Windows_Media_Capture_OptionalReferencePhotoCapturedEventArgs(
        void (^del)(WMCAdvancedPhotoCapture*, WMCOptionalReferencePhotoCapturedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Capture_AdvancedPhotoCapture_Windows_Media_Capture_OptionalReferencePhotoCapturedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Capture::IAdvancedPhotoCapture* arg0,
                                             ABI::Windows::Media::Capture::IOptionalReferencePhotoCapturedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCAdvancedPhotoCapture>(arg0), _createRtProxy<WMCOptionalReferencePhotoCapturedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Capture_AppCapture_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Capture_AppCapture_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Capture_AppCapture_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Capture::AppCapture*, IInspectable*>> {
    void (^_delegate)(WMCAppCapture*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Capture_AppCapture_System_Object(void (^del)(WMCAppCapture*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Capture_AppCapture_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Capture::IAppCapture* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCAppCapture>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Capture_LowLagPhotoSequenceCapture_Windows_Media_Capture_PhotoCapturedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Capture_LowLagPhotoSequenceCapture_Windows_Media_Capture_PhotoCapturedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Capture_LowLagPhotoSequenceCapture_Windows_Media_Capture_PhotoCapturedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Capture::LowLagPhotoSequenceCapture*,
                                                                       ABI::Windows::Media::Capture::PhotoCapturedEventArgs*>> {
    void (^_delegate)(WMCLowLagPhotoSequenceCapture*, WMCPhotoCapturedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Capture_LowLagPhotoSequenceCapture_Windows_Media_Capture_PhotoCapturedEventArgs(
        void (^del)(WMCLowLagPhotoSequenceCapture*, WMCPhotoCapturedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Capture_LowLagPhotoSequenceCapture_Windows_Media_Capture_PhotoCapturedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Capture::ILowLagPhotoSequenceCapture* arg0,
                                             ABI::Windows::Media::Capture::IPhotoCapturedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCLowLagPhotoSequenceCapture>(arg0), _createRtProxy<WMCPhotoCapturedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Capture_MediaCapture_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Capture_MediaCapture_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Capture_MediaCapture_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Capture::MediaCapture*, IInspectable*>> {
    void (^_delegate)(WMCMediaCapture*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Capture_MediaCapture_System_Object(void (^del)(WMCMediaCapture*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Capture_MediaCapture_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Capture::IMediaCapture* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMediaCapture>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Capture_MediaCapture_Windows_Media_Capture_MediaCaptureFocusChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Capture_MediaCapture_Windows_Media_Capture_MediaCaptureFocusChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Capture_MediaCapture_Windows_Media_Capture_MediaCaptureFocusChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Capture::MediaCapture*,
                                                                       ABI::Windows::Media::Capture::MediaCaptureFocusChangedEventArgs*>> {
    void (^_delegate)(WMCMediaCapture*, WMCMediaCaptureFocusChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Capture_MediaCapture_Windows_Media_Capture_MediaCaptureFocusChangedEventArgs(
        void (^del)(WMCMediaCapture*, WMCMediaCaptureFocusChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Capture_MediaCapture_Windows_Media_Capture_MediaCaptureFocusChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Capture::IMediaCapture* arg0,
                                             ABI::Windows::Media::Capture::IMediaCaptureFocusChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMediaCapture>(arg0), _createRtProxy<WMCMediaCaptureFocusChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Capture_MediaCapture_Windows_Media_Capture_PhotoConfirmationCapturedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Capture_MediaCapture_Windows_Media_Capture_PhotoConfirmationCapturedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Capture_MediaCapture_Windows_Media_Capture_PhotoConfirmationCapturedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Capture::MediaCapture*,
                                                                       ABI::Windows::Media::Capture::PhotoConfirmationCapturedEventArgs*>> {
    void (^_delegate)(WMCMediaCapture*, WMCPhotoConfirmationCapturedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Capture_MediaCapture_Windows_Media_Capture_PhotoConfirmationCapturedEventArgs(
        void (^del)(WMCMediaCapture*, WMCPhotoConfirmationCapturedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Capture_MediaCapture_Windows_Media_Capture_PhotoConfirmationCapturedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Capture::IMediaCapture* arg0,
                                             ABI::Windows::Media::Capture::IPhotoConfirmationCapturedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMediaCapture>(arg0), _createRtProxy<WMCPhotoConfirmationCapturedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Capture_ScreenCapture_Windows_Media_Capture_SourceSuspensionChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Capture_ScreenCapture_Windows_Media_Capture_SourceSuspensionChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Capture_ScreenCapture_Windows_Media_Capture_SourceSuspensionChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Capture::ScreenCapture*,
                                                                       ABI::Windows::Media::Capture::SourceSuspensionChangedEventArgs*>> {
    void (^_delegate)(WMCScreenCapture*, WMCSourceSuspensionChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Capture_ScreenCapture_Windows_Media_Capture_SourceSuspensionChangedEventArgs(
        void (^del)(WMCScreenCapture*, WMCSourceSuspensionChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Capture_ScreenCapture_Windows_Media_Capture_SourceSuspensionChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Capture::IScreenCapture* arg0,
                                             ABI::Windows::Media::Capture::ISourceSuspensionChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCScreenCapture>(arg0), _createRtProxy<WMCSourceSuspensionChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WMCMediaCaptureFailedEventHandler_shim__DEFINED
#define __WMCMediaCaptureFailedEventHandler_shim__DEFINED
class WMCMediaCaptureFailedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Media::Capture::IMediaCaptureFailedEventHandler> {
    void (^_delegate)(WMCMediaCapture*, WMCMediaCaptureFailedEventArgs*);

public:
    WMCMediaCaptureFailedEventHandler_shim(void (^del)(WMCMediaCapture*, WMCMediaCaptureFailedEventArgs*)) : _delegate([del copy]) {
    }
    ~WMCMediaCaptureFailedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Capture::IMediaCapture* arg0,
                                             ABI::Windows::Media::Capture::IMediaCaptureFailedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMediaCapture>(arg0), _createRtProxy<WMCMediaCaptureFailedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WMCRecordLimitationExceededEventHandler_shim__DEFINED
#define __WMCRecordLimitationExceededEventHandler_shim__DEFINED
class WMCRecordLimitationExceededEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Media::Capture::IRecordLimitationExceededEventHandler> {
    void (^_delegate)(WMCMediaCapture*);

public:
    WMCRecordLimitationExceededEventHandler_shim(void (^del)(WMCMediaCapture*)) : _delegate([del copy]) {
    }
    ~WMCRecordLimitationExceededEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Capture::IMediaCapture* arg0) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMediaCapture>(arg0));
            return 0;
        };
    }
};
#endif
