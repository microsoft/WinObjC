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

// WindowsMediaPlayTo_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundationCollections_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Media::PlayTo::IPlayToManagerStatics> WMPIPlayToManagerStatics_inst();

id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);

@class Nullable_UInt32, Nullable_WFDateTime, RTProxiedNSDictionary_NSString_RTObject;

#ifndef __ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionErrorEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionErrorEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionErrorEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::PlayTo::PlayToConnection*,
                                                                       ABI::Windows::Media::PlayTo::PlayToConnectionErrorEventArgs*>> {
    void (^_delegate)(WMPPlayToConnection*, WMPPlayToConnectionErrorEventArgs*);

public:
    ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionErrorEventArgs(
        void (^del)(WMPPlayToConnection*, WMPPlayToConnectionErrorEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionErrorEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::PlayTo::IPlayToConnection* arg0,
                                             ABI::Windows::Media::PlayTo::IPlayToConnectionErrorEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPPlayToConnection>(arg0), _createRtProxy<WMPPlayToConnectionErrorEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionStateChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionStateChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionStateChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::PlayTo::PlayToConnection*,
                                                       ABI::Windows::Media::PlayTo::PlayToConnectionStateChangedEventArgs*>> {
    void (^_delegate)(WMPPlayToConnection*, WMPPlayToConnectionStateChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionStateChangedEventArgs(
        void (^del)(WMPPlayToConnection*, WMPPlayToConnectionStateChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionStateChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::PlayTo::IPlayToConnection* arg0,
                                             ABI::Windows::Media::PlayTo::IPlayToConnectionStateChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPPlayToConnection>(arg0), _createRtProxy<WMPPlayToConnectionStateChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionTransferredEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionTransferredEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionTransferredEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::PlayTo::PlayToConnection*,
                                                       ABI::Windows::Media::PlayTo::PlayToConnectionTransferredEventArgs*>> {
    void (^_delegate)(WMPPlayToConnection*, WMPPlayToConnectionTransferredEventArgs*);

public:
    ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionTransferredEventArgs(
        void (^del)(WMPPlayToConnection*, WMPPlayToConnectionTransferredEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionTransferredEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::PlayTo::IPlayToConnection* arg0,
                                             ABI::Windows::Media::PlayTo::IPlayToConnectionTransferredEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPPlayToConnection>(arg0), _createRtProxy<WMPPlayToConnectionTransferredEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_PlayTo_PlayToManager_Windows_Media_PlayTo_PlayToSourceRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_PlayTo_PlayToManager_Windows_Media_PlayTo_PlayToSourceRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_PlayTo_PlayToManager_Windows_Media_PlayTo_PlayToSourceRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::PlayTo::PlayToManager*,
                                                                       ABI::Windows::Media::PlayTo::PlayToSourceRequestedEventArgs*>> {
    void (^_delegate)(WMPPlayToManager*, WMPPlayToSourceRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_PlayTo_PlayToManager_Windows_Media_PlayTo_PlayToSourceRequestedEventArgs(
        void (^del)(WMPPlayToManager*, WMPPlayToSourceRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_PlayTo_PlayToManager_Windows_Media_PlayTo_PlayToSourceRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::PlayTo::IPlayToManager* arg0,
                                             ABI::Windows::Media::PlayTo::IPlayToSourceRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPPlayToManager>(arg0), _createRtProxy<WMPPlayToSourceRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_PlayTo_PlayToManager_Windows_Media_PlayTo_PlayToSourceSelectedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_PlayTo_PlayToManager_Windows_Media_PlayTo_PlayToSourceSelectedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_PlayTo_PlayToManager_Windows_Media_PlayTo_PlayToSourceSelectedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::PlayTo::PlayToManager*,
                                                                       ABI::Windows::Media::PlayTo::PlayToSourceSelectedEventArgs*>> {
    void (^_delegate)(WMPPlayToManager*, WMPPlayToSourceSelectedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_PlayTo_PlayToManager_Windows_Media_PlayTo_PlayToSourceSelectedEventArgs(
        void (^del)(WMPPlayToManager*, WMPPlayToSourceSelectedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_PlayTo_PlayToManager_Windows_Media_PlayTo_PlayToSourceSelectedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::PlayTo::IPlayToManager* arg0,
                                             ABI::Windows::Media::PlayTo::IPlayToSourceSelectedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPPlayToManager>(arg0), _createRtProxy<WMPPlayToSourceSelectedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::PlayTo::PlayToReceiver*, IInspectable*>> {
    void (^_delegate)(WMPPlayToReceiver*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_System_Object(void (^del)(WMPPlayToReceiver*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::PlayTo::IPlayToReceiver* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPPlayToReceiver>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_CurrentTimeChangeRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_CurrentTimeChangeRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_CurrentTimeChangeRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::PlayTo::PlayToReceiver*,
                                                                       ABI::Windows::Media::PlayTo::CurrentTimeChangeRequestedEventArgs*>> {
    void (^_delegate)(WMPPlayToReceiver*, WMPCurrentTimeChangeRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_CurrentTimeChangeRequestedEventArgs(
        void (^del)(WMPPlayToReceiver*, WMPCurrentTimeChangeRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_CurrentTimeChangeRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::PlayTo::IPlayToReceiver* arg0,
                                             ABI::Windows::Media::PlayTo::ICurrentTimeChangeRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPPlayToReceiver>(arg0), _createRtProxy<WMPCurrentTimeChangeRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_MuteChangeRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_MuteChangeRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_MuteChangeRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::PlayTo::PlayToReceiver*,
                                                                       ABI::Windows::Media::PlayTo::MuteChangeRequestedEventArgs*>> {
    void (^_delegate)(WMPPlayToReceiver*, WMPMuteChangeRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_MuteChangeRequestedEventArgs(
        void (^del)(WMPPlayToReceiver*, WMPMuteChangeRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_MuteChangeRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::PlayTo::IPlayToReceiver* arg0,
                                             ABI::Windows::Media::PlayTo::IMuteChangeRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPPlayToReceiver>(arg0), _createRtProxy<WMPMuteChangeRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_PlaybackRateChangeRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_PlaybackRateChangeRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_PlaybackRateChangeRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::PlayTo::PlayToReceiver*,
                                                       ABI::Windows::Media::PlayTo::PlaybackRateChangeRequestedEventArgs*>> {
    void (^_delegate)(WMPPlayToReceiver*, WMPPlaybackRateChangeRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_PlaybackRateChangeRequestedEventArgs(
        void (^del)(WMPPlayToReceiver*, WMPPlaybackRateChangeRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_PlaybackRateChangeRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::PlayTo::IPlayToReceiver* arg0,
                                             ABI::Windows::Media::PlayTo::IPlaybackRateChangeRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPPlayToReceiver>(arg0), _createRtProxy<WMPPlaybackRateChangeRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_SourceChangeRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_SourceChangeRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_SourceChangeRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::PlayTo::PlayToReceiver*,
                                                                       ABI::Windows::Media::PlayTo::SourceChangeRequestedEventArgs*>> {
    void (^_delegate)(WMPPlayToReceiver*, WMPSourceChangeRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_SourceChangeRequestedEventArgs(
        void (^del)(WMPPlayToReceiver*, WMPSourceChangeRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_SourceChangeRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::PlayTo::IPlayToReceiver* arg0,
                                             ABI::Windows::Media::PlayTo::ISourceChangeRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPPlayToReceiver>(arg0), _createRtProxy<WMPSourceChangeRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_VolumeChangeRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_VolumeChangeRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_VolumeChangeRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::PlayTo::PlayToReceiver*,
                                                                       ABI::Windows::Media::PlayTo::VolumeChangeRequestedEventArgs*>> {
    void (^_delegate)(WMPPlayToReceiver*, WMPVolumeChangeRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_VolumeChangeRequestedEventArgs(
        void (^del)(WMPPlayToReceiver*, WMPVolumeChangeRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_VolumeChangeRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::PlayTo::IPlayToReceiver* arg0,
                                             ABI::Windows::Media::PlayTo::IVolumeChangeRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPPlayToReceiver>(arg0), _createRtProxy<WMPVolumeChangeRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
