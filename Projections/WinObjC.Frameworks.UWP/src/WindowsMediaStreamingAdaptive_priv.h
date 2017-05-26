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

// WindowsMediaStreamingAdaptive_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsWebHttp_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsMediaCore_priv.h"
ComPtr<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceStatics> WMSAIAdaptiveMediaSourceStatics_inst();

id RTProxiedNSArray_UInt32_create(IInspectable* val);

@class Nullable_Double, Nullable_UInt32, Nullable_UInt64, RTProxiedNSArray_UInt32;

#ifndef __ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadBitrateChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadBitrateChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadBitrateChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSource*,
                              ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadBitrateChangedEventArgs*>> {
    void (^_delegate)(WMSAAdaptiveMediaSource*, WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadBitrateChangedEventArgs(
        void (^del)(WMSAAdaptiveMediaSource*, WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadBitrateChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource* arg0,
           ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadBitrateChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMSAAdaptiveMediaSource>(arg0),
                      _createRtProxy<WMSAAdaptiveMediaSourceDownloadBitrateChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadCompletedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadCompletedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSource*,
                              ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadCompletedEventArgs*>> {
    void (^_delegate)(WMSAAdaptiveMediaSource*, WMSAAdaptiveMediaSourceDownloadCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadCompletedEventArgs(
        void (^del)(WMSAAdaptiveMediaSource*, WMSAAdaptiveMediaSourceDownloadCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource* arg0,
           ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMSAAdaptiveMediaSource>(arg0),
                      _createRtProxy<WMSAAdaptiveMediaSourceDownloadCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadFailedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadFailedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadFailedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSource*,
                              ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadFailedEventArgs*>> {
    void (^_delegate)(WMSAAdaptiveMediaSource*, WMSAAdaptiveMediaSourceDownloadFailedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadFailedEventArgs(
        void (^del)(WMSAAdaptiveMediaSource*, WMSAAdaptiveMediaSourceDownloadFailedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadFailedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource* arg0,
           ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadFailedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMSAAdaptiveMediaSource>(arg0), _createRtProxy<WMSAAdaptiveMediaSourceDownloadFailedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSource*,
                              ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourceDownloadRequestedEventArgs*>> {
    void (^_delegate)(WMSAAdaptiveMediaSource*, WMSAAdaptiveMediaSourceDownloadRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadRequestedEventArgs(
        void (^del)(WMSAAdaptiveMediaSource*, WMSAAdaptiveMediaSourceDownloadRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourceDownloadRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource* arg0,
           ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourceDownloadRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMSAAdaptiveMediaSource>(arg0),
                      _createRtProxy<WMSAAdaptiveMediaSourceDownloadRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourcePlaybackBitrateChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourcePlaybackBitrateChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourcePlaybackBitrateChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSource*,
                              ABI::Windows::Media::Streaming::Adaptive::AdaptiveMediaSourcePlaybackBitrateChangedEventArgs*>> {
    void (^_delegate)(WMSAAdaptiveMediaSource*, WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourcePlaybackBitrateChangedEventArgs(
        void (^del)(WMSAAdaptiveMediaSource*, WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Streaming_Adaptive_AdaptiveMediaSource_Windows_Media_Streaming_Adaptive_AdaptiveMediaSourcePlaybackBitrateChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource* arg0,
           ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSourcePlaybackBitrateChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMSAAdaptiveMediaSource>(arg0),
                      _createRtProxy<WMSAAdaptiveMediaSourcePlaybackBitrateChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
