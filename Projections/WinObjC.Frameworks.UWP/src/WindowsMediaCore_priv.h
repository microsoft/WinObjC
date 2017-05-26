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

// WindowsMediaCore_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsMediaFaceAnalysis_priv.h"
#include "WindowsMediaProtection_priv.h"
#include "WindowsMediaMediaProperties_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsStorageFileProperties_priv.h"
#include "WindowsMediaDevicesCore_priv.h"
#include "WindowsMedia_priv.h"
#include "WindowsMediaCapture_priv.h"
#include "WindowsMediaEffects_priv.h"
#include "WindowsMediaDevices_priv.h"
#include "WindowsMediaStreamingAdaptive_priv.h"
#include "WindowsStorage_priv.h"
#include "WindowsMediaPlayback_priv.h"
#include "WindowsFoundationCollections_priv.h"
#include "WindowsUI_priv.h"
static ComPtr<ABI::Windows::Media::Core::IAudioStreamDescriptorFactory> WMCIAudioStreamDescriptorFactory_inst();
static ComPtr<ABI::Windows::Media::Core::IVideoStreamDescriptorFactory> WMCIVideoStreamDescriptorFactory_inst();
static ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceFactory> WMCIMediaStreamSourceFactory_inst();
ComPtr<ABI::Windows::Media::Core::IMediaStreamSampleStatics> WMCIMediaStreamSampleStatics_inst();
ComPtr<ABI::Windows::Media::Core::IMseStreamSourceStatics> WMCIMseStreamSourceStatics_inst();
ComPtr<ABI::Windows::Media::Core::IMediaSourceStatics2> WMCIMediaSourceStatics2_inst();
ComPtr<ABI::Windows::Media::Core::IMediaSourceStatics> WMCIMediaSourceStatics_inst();
ComPtr<ABI::Windows::Media::Core::ITimedTextSourceStatics> WMCITimedTextSourceStatics_inst();
static ComPtr<ABI::Windows::Media::Core::ITimedMetadataTrackFactory> WMCITimedMetadataTrackFactory_inst();
@interface WMCMseTimeRange (Internal)
+ (instancetype)createWith:(ABI::Windows::Media::Core::MseTimeRange)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Media::Core::MseTimeRange*)internalStruct;
@end
inline WMCMseTimeRange* WMCMseTimeRange_create(ABI::Windows::Media::Core::MseTimeRange val) {
    return [WMCMseTimeRange createWith:val];
}
@interface WMCTimedTextPadding (Internal)
+ (instancetype)createWith:(ABI::Windows::Media::Core::TimedTextPadding)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Media::Core::TimedTextPadding*)internalStruct;
@end
inline WMCTimedTextPadding* WMCTimedTextPadding_create(ABI::Windows::Media::Core::TimedTextPadding val) {
    return [WMCTimedTextPadding createWith:val];
}
@interface WMCTimedTextSize (Internal)
+ (instancetype)createWith:(ABI::Windows::Media::Core::TimedTextSize)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Media::Core::TimedTextSize*)internalStruct;
@end
inline WMCTimedTextSize* WMCTimedTextSize_create(ABI::Windows::Media::Core::TimedTextSize val) {
    return [WMCTimedTextSize createWith:val];
}
@interface WMCTimedTextDouble (Internal)
+ (instancetype)createWith:(ABI::Windows::Media::Core::TimedTextDouble)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Media::Core::TimedTextDouble*)internalStruct;
@end
inline WMCTimedTextDouble* WMCTimedTextDouble_create(ABI::Windows::Media::Core::TimedTextDouble val) {
    return [WMCTimedTextDouble createWith:val];
}
@interface WMCTimedTextPoint (Internal)
+ (instancetype)createWith:(ABI::Windows::Media::Core::TimedTextPoint)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Media::Core::TimedTextPoint*)internalStruct;
@end
inline WMCTimedTextPoint* WMCTimedTextPoint_create(ABI::Windows::Media::Core::TimedTextPoint val) {
    return [WMCTimedTextPoint createWith:val];
}

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);
id RTProxiedNSArray_RTObject_WMCIMediaCue_create(IInspectable* val);
id RTProxiedNSArray_WMCMseSourceBuffer_create(IInspectable* val);
id RTProxiedNSArray_WMCMseTimeRange_create(IInspectable* val);
id RTProxiedNSArray_WMCTimedMetadataTrack_create(IInspectable* val);
id RTProxiedNSArray_WMDCFrameController_create(IInspectable* val);
id RTProxiedNSArray_WMFDetectedFace_create(IInspectable* val);
id RTProxiedNSMutableArray_WMCTimedTextLine_create(IInspectable* val);
id RTProxiedNSMutableArray_WMCTimedTextSubformat_create(IInspectable* val);
id RTProxiedObservableNSMutableArray_WMCTimedMetadataTrack_create(IInspectable* val);
id RTProxiedObservableNSMutableArray_WMCTimedTextSource_create(IInspectable* val);

@class Nullable_UInt32, Nullable_WFTimeSpan, RTProxiedNSArray_C_UInt8, RTProxiedNSArray_RTObject_WMCIMediaCue,
    RTProxiedNSArray_WMCMseSourceBuffer;
@class RTProxiedNSArray_WMCMseTimeRange, RTProxiedNSArray_WMCTimedMetadataTrack, RTProxiedNSArray_WMDCFrameController,
    RTProxiedNSArray_WMFDetectedFace;
@class RTProxiedNSMutableArray_WMCTimedTextLine, RTProxiedNSMutableArray_WMCTimedTextSubformat,
    RTProxiedObservableNSMutableArray_WMCTimedMetadataTrack;
@class RTProxiedObservableNSMutableArray_WMCTimedTextSource;

#ifndef __ITypedEventHandler_Windows_Media_Core_AudioTrack_Windows_Media_Core_AudioTrackOpenFailedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_AudioTrack_Windows_Media_Core_AudioTrackOpenFailedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Core_AudioTrack_Windows_Media_Core_AudioTrackOpenFailedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::AudioTrack*,
                                                                       ABI::Windows::Media::Core::AudioTrackOpenFailedEventArgs*>> {
    void (^_delegate)(WMCAudioTrack*, WMCAudioTrackOpenFailedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Core_AudioTrack_Windows_Media_Core_AudioTrackOpenFailedEventArgs(
        void (^del)(WMCAudioTrack*, WMCAudioTrackOpenFailedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_AudioTrack_Windows_Media_Core_AudioTrackOpenFailedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IMediaTrack* arg0,
                                             ABI::Windows::Media::Core::IAudioTrackOpenFailedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCAudioTrack>(arg0), _createRtProxy<WMCAudioTrackOpenFailedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_FaceDetectionEffect_Windows_Media_Core_FaceDetectedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_FaceDetectionEffect_Windows_Media_Core_FaceDetectedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Core_FaceDetectionEffect_Windows_Media_Core_FaceDetectedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::FaceDetectionEffect*,
                                                                       ABI::Windows::Media::Core::FaceDetectedEventArgs*>> {
    void (^_delegate)(WMCFaceDetectionEffect*, WMCFaceDetectedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Core_FaceDetectionEffect_Windows_Media_Core_FaceDetectedEventArgs(
        void (^del)(WMCFaceDetectionEffect*, WMCFaceDetectedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_FaceDetectionEffect_Windows_Media_Core_FaceDetectedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IFaceDetectionEffect* arg0,
                                             ABI::Windows::Media::Core::IFaceDetectedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCFaceDetectionEffect>(arg0), _createRtProxy<WMCFaceDetectedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_ISingleSelectMediaTrackList_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_ISingleSelectMediaTrackList_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Core_ISingleSelectMediaTrackList_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::ISingleSelectMediaTrackList*, IInspectable*>> {
    void (^_delegate)(RTObject<WMCISingleSelectMediaTrackList>*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Core_ISingleSelectMediaTrackList_System_Object(void (^del)(RTObject<WMCISingleSelectMediaTrackList>*,
                                                                                                RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_ISingleSelectMediaTrackList_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::ISingleSelectMediaTrackList* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCISingleSelectMediaTrackList>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_MediaBinder_Windows_Media_Core_MediaBindingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_MediaBinder_Windows_Media_Core_MediaBindingEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Core_MediaBinder_Windows_Media_Core_MediaBindingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::MediaBinder*,
                                                                       ABI::Windows::Media::Core::MediaBindingEventArgs*>> {
    void (^_delegate)(WMCMediaBinder*, WMCMediaBindingEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Core_MediaBinder_Windows_Media_Core_MediaBindingEventArgs(void (^del)(WMCMediaBinder*,
                                                                                                           WMCMediaBindingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_MediaBinder_Windows_Media_Core_MediaBindingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IMediaBinder* arg0,
                                             ABI::Windows::Media::Core::IMediaBindingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMediaBinder>(arg0), _createRtProxy<WMCMediaBindingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_MediaBindingEventArgs_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_MediaBindingEventArgs_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Core_MediaBindingEventArgs_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::MediaBindingEventArgs*, IInspectable*>> {
    void (^_delegate)(WMCMediaBindingEventArgs*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Core_MediaBindingEventArgs_System_Object(void (^del)(WMCMediaBindingEventArgs*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_MediaBindingEventArgs_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IMediaBindingEventArgs* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMediaBindingEventArgs>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_MediaSource_Windows_Media_Core_MediaSourceOpenOperationCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_MediaSource_Windows_Media_Core_MediaSourceOpenOperationCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Core_MediaSource_Windows_Media_Core_MediaSourceOpenOperationCompletedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::MediaSource*,
                                                       ABI::Windows::Media::Core::MediaSourceOpenOperationCompletedEventArgs*>> {
    void (^_delegate)(WMCMediaSource*, WMCMediaSourceOpenOperationCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Core_MediaSource_Windows_Media_Core_MediaSourceOpenOperationCompletedEventArgs(
        void (^del)(WMCMediaSource*, WMCMediaSourceOpenOperationCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_MediaSource_Windows_Media_Core_MediaSourceOpenOperationCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IMediaSource2* arg0,
                                             ABI::Windows::Media::Core::IMediaSourceOpenOperationCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMediaSource>(arg0), _createRtProxy<WMCMediaSourceOpenOperationCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_MediaSource_Windows_Media_Core_MediaSourceStateChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_MediaSource_Windows_Media_Core_MediaSourceStateChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Core_MediaSource_Windows_Media_Core_MediaSourceStateChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::MediaSource*,
                                                                       ABI::Windows::Media::Core::MediaSourceStateChangedEventArgs*>> {
    void (^_delegate)(WMCMediaSource*, WMCMediaSourceStateChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Core_MediaSource_Windows_Media_Core_MediaSourceStateChangedEventArgs(
        void (^del)(WMCMediaSource*, WMCMediaSourceStateChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_MediaSource_Windows_Media_Core_MediaSourceStateChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IMediaSource2* arg0,
                                             ABI::Windows::Media::Core::IMediaSourceStateChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMediaSource>(arg0), _createRtProxy<WMCMediaSourceStateChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_MediaStreamSample_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_MediaStreamSample_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Core_MediaStreamSample_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::MediaStreamSample*, IInspectable*>> {
    void (^_delegate)(WMCMediaStreamSample*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Core_MediaStreamSample_System_Object(void (^del)(WMCMediaStreamSample*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_MediaStreamSample_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IMediaStreamSample* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMediaStreamSample>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_MediaStreamSource_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_MediaStreamSource_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Core_MediaStreamSource_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::MediaStreamSource*, IInspectable*>> {
    void (^_delegate)(WMCMediaStreamSource*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Core_MediaStreamSource_System_Object(void (^del)(WMCMediaStreamSource*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_MediaStreamSource_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IMediaStreamSource* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMediaStreamSource>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceClosedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceClosedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceClosedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::MediaStreamSource*,
                                                                       ABI::Windows::Media::Core::MediaStreamSourceClosedEventArgs*>> {
    void (^_delegate)(WMCMediaStreamSource*, WMCMediaStreamSourceClosedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceClosedEventArgs(
        void (^del)(WMCMediaStreamSource*, WMCMediaStreamSourceClosedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceClosedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IMediaStreamSource* arg0,
                                             ABI::Windows::Media::Core::IMediaStreamSourceClosedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMediaStreamSource>(arg0), _createRtProxy<WMCMediaStreamSourceClosedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSampleRenderedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSampleRenderedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSampleRenderedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::MediaStreamSource*,
                                                       ABI::Windows::Media::Core::MediaStreamSourceSampleRenderedEventArgs*>> {
    void (^_delegate)(WMCMediaStreamSource*, WMCMediaStreamSourceSampleRenderedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSampleRenderedEventArgs(
        void (^del)(WMCMediaStreamSource*, WMCMediaStreamSourceSampleRenderedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSampleRenderedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IMediaStreamSource* arg0,
                                             ABI::Windows::Media::Core::IMediaStreamSourceSampleRenderedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMediaStreamSource>(arg0), _createRtProxy<WMCMediaStreamSourceSampleRenderedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSampleRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSampleRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSampleRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::MediaStreamSource*,
                                                       ABI::Windows::Media::Core::MediaStreamSourceSampleRequestedEventArgs*>> {
    void (^_delegate)(WMCMediaStreamSource*, WMCMediaStreamSourceSampleRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSampleRequestedEventArgs(
        void (^del)(WMCMediaStreamSource*, WMCMediaStreamSourceSampleRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSampleRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IMediaStreamSource* arg0,
                                             ABI::Windows::Media::Core::IMediaStreamSourceSampleRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMediaStreamSource>(arg0), _createRtProxy<WMCMediaStreamSourceSampleRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceStartingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceStartingEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceStartingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::MediaStreamSource*,
                                                                       ABI::Windows::Media::Core::MediaStreamSourceStartingEventArgs*>> {
    void (^_delegate)(WMCMediaStreamSource*, WMCMediaStreamSourceStartingEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceStartingEventArgs(
        void (^del)(WMCMediaStreamSource*, WMCMediaStreamSourceStartingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceStartingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IMediaStreamSource* arg0,
                                             ABI::Windows::Media::Core::IMediaStreamSourceStartingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMediaStreamSource>(arg0), _createRtProxy<WMCMediaStreamSourceStartingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSwitchStreamsRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSwitchStreamsRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSwitchStreamsRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::MediaStreamSource*,
                                                       ABI::Windows::Media::Core::MediaStreamSourceSwitchStreamsRequestedEventArgs*>> {
    void (^_delegate)(WMCMediaStreamSource*, WMCMediaStreamSourceSwitchStreamsRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSwitchStreamsRequestedEventArgs(
        void (^del)(WMCMediaStreamSource*, WMCMediaStreamSourceSwitchStreamsRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSwitchStreamsRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IMediaStreamSource* arg0,
                                             ABI::Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMediaStreamSource>(arg0),
                      _createRtProxy<WMCMediaStreamSourceSwitchStreamsRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_MseSourceBufferList_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_MseSourceBufferList_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Core_MseSourceBufferList_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::MseSourceBufferList*, IInspectable*>> {
    void (^_delegate)(WMCMseSourceBufferList*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Core_MseSourceBufferList_System_Object(void (^del)(WMCMseSourceBufferList*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_MseSourceBufferList_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IMseSourceBufferList* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMseSourceBufferList>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_MseSourceBuffer_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_MseSourceBuffer_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Core_MseSourceBuffer_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::MseSourceBuffer*, IInspectable*>> {
    void (^_delegate)(WMCMseSourceBuffer*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Core_MseSourceBuffer_System_Object(void (^del)(WMCMseSourceBuffer*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_MseSourceBuffer_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IMseSourceBuffer* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMseSourceBuffer>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_MseStreamSource_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_MseStreamSource_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Core_MseStreamSource_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::MseStreamSource*, IInspectable*>> {
    void (^_delegate)(WMCMseStreamSource*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Core_MseStreamSource_System_Object(void (^del)(WMCMseStreamSource*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_MseStreamSource_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IMseStreamSource* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCMseStreamSource>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_SceneAnalysisEffect_Windows_Media_Core_SceneAnalyzedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_SceneAnalysisEffect_Windows_Media_Core_SceneAnalyzedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Core_SceneAnalysisEffect_Windows_Media_Core_SceneAnalyzedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::SceneAnalysisEffect*,
                                                                       ABI::Windows::Media::Core::SceneAnalyzedEventArgs*>> {
    void (^_delegate)(WMCSceneAnalysisEffect*, WMCSceneAnalyzedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Core_SceneAnalysisEffect_Windows_Media_Core_SceneAnalyzedEventArgs(
        void (^del)(WMCSceneAnalysisEffect*, WMCSceneAnalyzedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_SceneAnalysisEffect_Windows_Media_Core_SceneAnalyzedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::ISceneAnalysisEffect* arg0,
                                             ABI::Windows::Media::Core::ISceneAnalyzedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCSceneAnalysisEffect>(arg0), _createRtProxy<WMCSceneAnalyzedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_TimedMetadataTrack_Windows_Media_Core_MediaCueEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_TimedMetadataTrack_Windows_Media_Core_MediaCueEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Core_TimedMetadataTrack_Windows_Media_Core_MediaCueEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::TimedMetadataTrack*,
                                                                       ABI::Windows::Media::Core::MediaCueEventArgs*>> {
    void (^_delegate)(WMCTimedMetadataTrack*, WMCMediaCueEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Core_TimedMetadataTrack_Windows_Media_Core_MediaCueEventArgs(void (^del)(WMCTimedMetadataTrack*,
                                                                                                              WMCMediaCueEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_TimedMetadataTrack_Windows_Media_Core_MediaCueEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::ITimedMetadataTrack* arg0,
                                             ABI::Windows::Media::Core::IMediaCueEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCTimedMetadataTrack>(arg0), _createRtProxy<WMCMediaCueEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_TimedMetadataTrack_Windows_Media_Core_TimedMetadataTrackFailedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_TimedMetadataTrack_Windows_Media_Core_TimedMetadataTrackFailedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Core_TimedMetadataTrack_Windows_Media_Core_TimedMetadataTrackFailedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::TimedMetadataTrack*,
                                                                       ABI::Windows::Media::Core::TimedMetadataTrackFailedEventArgs*>> {
    void (^_delegate)(WMCTimedMetadataTrack*, WMCTimedMetadataTrackFailedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Core_TimedMetadataTrack_Windows_Media_Core_TimedMetadataTrackFailedEventArgs(
        void (^del)(WMCTimedMetadataTrack*, WMCTimedMetadataTrackFailedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_TimedMetadataTrack_Windows_Media_Core_TimedMetadataTrackFailedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::ITimedMetadataTrack* arg0,
                                             ABI::Windows::Media::Core::ITimedMetadataTrackFailedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCTimedMetadataTrack>(arg0), _createRtProxy<WMCTimedMetadataTrackFailedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_TimedTextSource_Windows_Media_Core_TimedTextSourceResolveResultEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_TimedTextSource_Windows_Media_Core_TimedTextSourceResolveResultEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Core_TimedTextSource_Windows_Media_Core_TimedTextSourceResolveResultEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::TimedTextSource*,
                                                                       ABI::Windows::Media::Core::TimedTextSourceResolveResultEventArgs*>> {
    void (^_delegate)(WMCTimedTextSource*, WMCTimedTextSourceResolveResultEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Core_TimedTextSource_Windows_Media_Core_TimedTextSourceResolveResultEventArgs(
        void (^del)(WMCTimedTextSource*, WMCTimedTextSourceResolveResultEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_TimedTextSource_Windows_Media_Core_TimedTextSourceResolveResultEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::ITimedTextSource* arg0,
                                             ABI::Windows::Media::Core::ITimedTextSourceResolveResultEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCTimedTextSource>(arg0), _createRtProxy<WMCTimedTextSourceResolveResultEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_VideoStabilizationEffect_Windows_Media_Core_VideoStabilizationEffectEnabledChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_VideoStabilizationEffect_Windows_Media_Core_VideoStabilizationEffectEnabledChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Core_VideoStabilizationEffect_Windows_Media_Core_VideoStabilizationEffectEnabledChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::VideoStabilizationEffect*,
                                                       ABI::Windows::Media::Core::VideoStabilizationEffectEnabledChangedEventArgs*>> {
    void (^_delegate)(WMCVideoStabilizationEffect*, WMCVideoStabilizationEffectEnabledChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Core_VideoStabilizationEffect_Windows_Media_Core_VideoStabilizationEffectEnabledChangedEventArgs(
        void (^del)(WMCVideoStabilizationEffect*, WMCVideoStabilizationEffectEnabledChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_VideoStabilizationEffect_Windows_Media_Core_VideoStabilizationEffectEnabledChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IVideoStabilizationEffect* arg0,
                                             ABI::Windows::Media::Core::IVideoStabilizationEffectEnabledChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCVideoStabilizationEffect>(arg0),
                      _createRtProxy<WMCVideoStabilizationEffectEnabledChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Core_VideoTrack_Windows_Media_Core_VideoTrackOpenFailedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Core_VideoTrack_Windows_Media_Core_VideoTrackOpenFailedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Core_VideoTrack_Windows_Media_Core_VideoTrackOpenFailedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Core::VideoTrack*,
                                                                       ABI::Windows::Media::Core::VideoTrackOpenFailedEventArgs*>> {
    void (^_delegate)(WMCVideoTrack*, WMCVideoTrackOpenFailedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Core_VideoTrack_Windows_Media_Core_VideoTrackOpenFailedEventArgs(
        void (^del)(WMCVideoTrack*, WMCVideoTrackOpenFailedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Core_VideoTrack_Windows_Media_Core_VideoTrackOpenFailedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Core::IMediaTrack* arg0,
                                             ABI::Windows::Media::Core::IVideoTrackOpenFailedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMCVideoTrack>(arg0), _createRtProxy<WMCVideoTrackOpenFailedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
