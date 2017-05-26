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

// WindowsMediaPlayback_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsFoundationCollections_priv.h"
#include "WindowsDevicesEnumeration_priv.h"
#include "WindowsMedia_priv.h"
#include "WindowsMediaMediaProperties_priv.h"
#include "WindowsMediaCasting_priv.h"
#include "WindowsUIComposition_priv.h"
#include "WindowsMediaProtection_priv.h"
#include "WindowsStorage_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsMediaCore_priv.h"
static ComPtr<ABI::Windows::Media::Playback::IPlaybackMediaMarkerFactory> WMPIPlaybackMediaMarkerFactory_inst();
ComPtr<ABI::Windows::Media::Playback::IBackgroundMediaPlayerStatics> WMPIBackgroundMediaPlayerStatics_inst();
static ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItemFactory2> WMPIMediaPlaybackItemFactory2_inst();
static ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItemFactory> WMPIMediaPlaybackItemFactory_inst();
ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItemStatics> WMPIMediaPlaybackItemStatics_inst();
static ComPtr<ABI::Windows::Media::Playback::IMediaBreakFactory> WMPIMediaBreakFactory_inst();

id RTProxiedIterableNSArray_WMPMediaPlaybackItem_create(IInspectable* val);
id RTProxiedNSArray_WMPMediaBreak_create(IInspectable* val);
id RTProxiedNSArray_WMPMediaPlaybackItem_create(IInspectable* val);
id RTProxiedObservableNSMutableArray_WMPMediaPlaybackItem_create(IInspectable* val);

@class Nullable_WFTimeSpan, RTProxiedIterableNSArray_WMPMediaPlaybackItem, RTProxiedNSArray_WMPMediaBreak,
    RTProxiedNSArray_WMPMediaPlaybackItem;
@class RTProxiedObservableNSMutableArray_WMPMediaPlaybackItem;

#ifndef __EventHandler_Windows_Media_Playback_MediaPlayerDataReceivedEventArgs__DEFINED
#define __EventHandler_Windows_Media_Playback_MediaPlayerDataReceivedEventArgs__DEFINED
class EventHandler_Windows_Media_Playback_MediaPlayerDataReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::Media::Playback::MediaPlayerDataReceivedEventArgs*>> {
    void (^_delegate)(RTObject*, WMPMediaPlayerDataReceivedEventArgs*);

public:
    EventHandler_Windows_Media_Playback_MediaPlayerDataReceivedEventArgs(void (^del)(RTObject*, WMPMediaPlayerDataReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_Media_Playback_MediaPlayerDataReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::Media::Playback::IMediaPlayerDataReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WMPMediaPlayerDataReceivedEventArgs>(arg1));
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

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakEndedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakEndedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakEndedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaBreakManager*,
                                                                       ABI::Windows::Media::Playback::MediaBreakEndedEventArgs*>> {
    void (^_delegate)(WMPMediaBreakManager*, WMPMediaBreakEndedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakEndedEventArgs(
        void (^del)(WMPMediaBreakManager*, WMPMediaBreakEndedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakEndedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Playback::IMediaBreakManager* arg0,
                                             ABI::Windows::Media::Playback::IMediaBreakEndedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaBreakManager>(arg0), _createRtProxy<WMPMediaBreakEndedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakSeekedOverEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakSeekedOverEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakSeekedOverEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaBreakManager*,
                                                                       ABI::Windows::Media::Playback::MediaBreakSeekedOverEventArgs*>> {
    void (^_delegate)(WMPMediaBreakManager*, WMPMediaBreakSeekedOverEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakSeekedOverEventArgs(
        void (^del)(WMPMediaBreakManager*, WMPMediaBreakSeekedOverEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakSeekedOverEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Playback::IMediaBreakManager* arg0,
                                             ABI::Windows::Media::Playback::IMediaBreakSeekedOverEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaBreakManager>(arg0), _createRtProxy<WMPMediaBreakSeekedOverEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakSkippedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakSkippedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakSkippedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaBreakManager*,
                                                                       ABI::Windows::Media::Playback::MediaBreakSkippedEventArgs*>> {
    void (^_delegate)(WMPMediaBreakManager*, WMPMediaBreakSkippedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakSkippedEventArgs(
        void (^del)(WMPMediaBreakManager*, WMPMediaBreakSkippedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakSkippedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Playback::IMediaBreakManager* arg0,
                                             ABI::Windows::Media::Playback::IMediaBreakSkippedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaBreakManager>(arg0), _createRtProxy<WMPMediaBreakSkippedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakStartedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakStartedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakStartedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaBreakManager*,
                                                                       ABI::Windows::Media::Playback::MediaBreakStartedEventArgs*>> {
    void (^_delegate)(WMPMediaBreakManager*, WMPMediaBreakStartedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakStartedEventArgs(
        void (^del)(WMPMediaBreakManager*, WMPMediaBreakStartedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakStartedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Playback::IMediaBreakManager* arg0,
                                             ABI::Windows::Media::Playback::IMediaBreakStartedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaBreakManager>(arg0), _createRtProxy<WMPMediaBreakStartedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaBreakSchedule_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaBreakSchedule_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Playback_MediaBreakSchedule_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaBreakSchedule*, IInspectable*>> {
    void (^_delegate)(WMPMediaBreakSchedule*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaBreakSchedule_System_Object(void (^del)(WMPMediaBreakSchedule*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaBreakSchedule_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Playback::IMediaBreakSchedule* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaBreakSchedule>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManagerCommandBehavior_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManagerCommandBehavior_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManagerCommandBehavior_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaPlaybackCommandManagerCommandBehavior*,
                                                       IInspectable*>> {
    void (^_delegate)(WMPMediaPlaybackCommandManagerCommandBehavior*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManagerCommandBehavior_System_Object(
        void (^del)(WMPMediaPlaybackCommandManagerCommandBehavior*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManagerCommandBehavior_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackCommandManagerCommandBehavior>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::Playback::MediaPlaybackCommandManager*,
                              ABI::Windows::Media::Playback::MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs*>> {
    void (^_delegate)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs(
        void (^del)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Playback::IMediaPlaybackCommandManager* arg0,
           ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackCommandManager>(arg0),
                      _createRtProxy<WMPMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerFastForwardReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerFastForwardReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerFastForwardReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::Playback::MediaPlaybackCommandManager*,
                              ABI::Windows::Media::Playback::MediaPlaybackCommandManagerFastForwardReceivedEventArgs*>> {
    void (^_delegate)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerFastForwardReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerFastForwardReceivedEventArgs(
        void (^del)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerFastForwardReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerFastForwardReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Playback::IMediaPlaybackCommandManager* arg0,
           ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackCommandManager>(arg0),
                      _createRtProxy<WMPMediaPlaybackCommandManagerFastForwardReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerNextReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerNextReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerNextReceivedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaPlaybackCommandManager*,
                                                       ABI::Windows::Media::Playback::MediaPlaybackCommandManagerNextReceivedEventArgs*>> {
    void (^_delegate)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerNextReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerNextReceivedEventArgs(
        void (^del)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerNextReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerNextReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Playback::IMediaPlaybackCommandManager* arg0,
           ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackCommandManager>(arg0),
                      _createRtProxy<WMPMediaPlaybackCommandManagerNextReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPauseReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPauseReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPauseReceivedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaPlaybackCommandManager*,
                                                       ABI::Windows::Media::Playback::MediaPlaybackCommandManagerPauseReceivedEventArgs*>> {
    void (^_delegate)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerPauseReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPauseReceivedEventArgs(
        void (^del)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerPauseReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPauseReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Playback::IMediaPlaybackCommandManager* arg0,
           ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackCommandManager>(arg0),
                      _createRtProxy<WMPMediaPlaybackCommandManagerPauseReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPlayReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPlayReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPlayReceivedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaPlaybackCommandManager*,
                                                       ABI::Windows::Media::Playback::MediaPlaybackCommandManagerPlayReceivedEventArgs*>> {
    void (^_delegate)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerPlayReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPlayReceivedEventArgs(
        void (^del)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerPlayReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPlayReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Playback::IMediaPlaybackCommandManager* arg0,
           ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackCommandManager>(arg0),
                      _createRtProxy<WMPMediaPlaybackCommandManagerPlayReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPositionReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPositionReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPositionReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::Playback::MediaPlaybackCommandManager*,
                              ABI::Windows::Media::Playback::MediaPlaybackCommandManagerPositionReceivedEventArgs*>> {
    void (^_delegate)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerPositionReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPositionReceivedEventArgs(
        void (^del)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerPositionReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPositionReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Playback::IMediaPlaybackCommandManager* arg0,
           ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackCommandManager>(arg0),
                      _createRtProxy<WMPMediaPlaybackCommandManagerPositionReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPreviousReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPreviousReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPreviousReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::Playback::MediaPlaybackCommandManager*,
                              ABI::Windows::Media::Playback::MediaPlaybackCommandManagerPreviousReceivedEventArgs*>> {
    void (^_delegate)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerPreviousReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPreviousReceivedEventArgs(
        void (^del)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerPreviousReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPreviousReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Playback::IMediaPlaybackCommandManager* arg0,
           ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackCommandManager>(arg0),
                      _createRtProxy<WMPMediaPlaybackCommandManagerPreviousReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerRateReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerRateReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerRateReceivedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaPlaybackCommandManager*,
                                                       ABI::Windows::Media::Playback::MediaPlaybackCommandManagerRateReceivedEventArgs*>> {
    void (^_delegate)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerRateReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerRateReceivedEventArgs(
        void (^del)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerRateReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerRateReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Playback::IMediaPlaybackCommandManager* arg0,
           ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackCommandManager>(arg0),
                      _createRtProxy<WMPMediaPlaybackCommandManagerRateReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerRewindReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerRewindReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerRewindReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::Playback::MediaPlaybackCommandManager*,
                              ABI::Windows::Media::Playback::MediaPlaybackCommandManagerRewindReceivedEventArgs*>> {
    void (^_delegate)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerRewindReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerRewindReceivedEventArgs(
        void (^del)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerRewindReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerRewindReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Playback::IMediaPlaybackCommandManager* arg0,
           ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackCommandManager>(arg0),
                      _createRtProxy<WMPMediaPlaybackCommandManagerRewindReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerShuffleReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerShuffleReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerShuffleReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::Playback::MediaPlaybackCommandManager*,
                              ABI::Windows::Media::Playback::MediaPlaybackCommandManagerShuffleReceivedEventArgs*>> {
    void (^_delegate)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerShuffleReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerShuffleReceivedEventArgs(
        void (^del)(WMPMediaPlaybackCommandManager*, WMPMediaPlaybackCommandManagerShuffleReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerShuffleReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::Playback::IMediaPlaybackCommandManager* arg0,
           ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackCommandManager>(arg0),
                      _createRtProxy<WMPMediaPlaybackCommandManagerShuffleReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackItem_Windows_Foundation_Collections_IVectorChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackItem_Windows_Foundation_Collections_IVectorChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Playback_MediaPlaybackItem_Windows_Foundation_Collections_IVectorChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaPlaybackItem*,
                                                                       ABI::Windows::Foundation::Collections::IVectorChangedEventArgs*>> {
    void (^_delegate)(WMPMediaPlaybackItem*, RTObject<WFCIVectorChangedEventArgs>*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackItem_Windows_Foundation_Collections_IVectorChangedEventArgs(
        void (^del)(WMPMediaPlaybackItem*, RTObject<WFCIVectorChangedEventArgs>*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackItem_Windows_Foundation_Collections_IVectorChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Playback::IMediaPlaybackItem* arg0,
                                             ABI::Windows::Foundation::Collections::IVectorChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackItem>(arg0), _createRtProxy<WFCIVectorChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_CurrentMediaPlaybackItemChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_CurrentMediaPlaybackItemChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_CurrentMediaPlaybackItemChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaPlaybackList*,
                                                       ABI::Windows::Media::Playback::CurrentMediaPlaybackItemChangedEventArgs*>> {
    void (^_delegate)(WMPMediaPlaybackList*, WMPCurrentMediaPlaybackItemChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_CurrentMediaPlaybackItemChangedEventArgs(
        void (^del)(WMPMediaPlaybackList*, WMPCurrentMediaPlaybackItemChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_CurrentMediaPlaybackItemChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Playback::IMediaPlaybackList* arg0,
                                             ABI::Windows::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackList>(arg0), _createRtProxy<WMPCurrentMediaPlaybackItemChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_MediaPlaybackItemFailedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_MediaPlaybackItemFailedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_MediaPlaybackItemFailedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaPlaybackList*,
                                                                       ABI::Windows::Media::Playback::MediaPlaybackItemFailedEventArgs*>> {
    void (^_delegate)(WMPMediaPlaybackList*, WMPMediaPlaybackItemFailedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_MediaPlaybackItemFailedEventArgs(
        void (^del)(WMPMediaPlaybackList*, WMPMediaPlaybackItemFailedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_MediaPlaybackItemFailedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Playback::IMediaPlaybackList* arg0,
                                             ABI::Windows::Media::Playback::IMediaPlaybackItemFailedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackList>(arg0), _createRtProxy<WMPMediaPlaybackItemFailedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_MediaPlaybackItemOpenedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_MediaPlaybackItemOpenedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_MediaPlaybackItemOpenedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaPlaybackList*,
                                                                       ABI::Windows::Media::Playback::MediaPlaybackItemOpenedEventArgs*>> {
    void (^_delegate)(WMPMediaPlaybackList*, WMPMediaPlaybackItemOpenedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_MediaPlaybackItemOpenedEventArgs(
        void (^del)(WMPMediaPlaybackList*, WMPMediaPlaybackItemOpenedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_MediaPlaybackItemOpenedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Playback::IMediaPlaybackList* arg0,
                                             ABI::Windows::Media::Playback::IMediaPlaybackItemOpenedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackList>(arg0), _createRtProxy<WMPMediaPlaybackItemOpenedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackSession_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackSession_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Playback_MediaPlaybackSession_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaPlaybackSession*, IInspectable*>> {
    void (^_delegate)(WMPMediaPlaybackSession*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackSession_System_Object(void (^del)(WMPMediaPlaybackSession*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackSession_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Playback::IMediaPlaybackSession* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackSession>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackTimedMetadataTrackList_Windows_Media_Playback_TimedMetadataPresentationModeChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlaybackTimedMetadataTrackList_Windows_Media_Playback_TimedMetadataPresentationModeChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackTimedMetadataTrackList_Windows_Media_Playback_TimedMetadataPresentationModeChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaPlaybackTimedMetadataTrackList*,
                                                       ABI::Windows::Media::Playback::TimedMetadataPresentationModeChangedEventArgs*>> {
    void (^_delegate)(WMPMediaPlaybackTimedMetadataTrackList*, WMPTimedMetadataPresentationModeChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlaybackTimedMetadataTrackList_Windows_Media_Playback_TimedMetadataPresentationModeChangedEventArgs(
        void (^del)(WMPMediaPlaybackTimedMetadataTrackList*, WMPTimedMetadataPresentationModeChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlaybackTimedMetadataTrackList_Windows_Media_Playback_TimedMetadataPresentationModeChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IVectorView<ABI::Windows::Media::Core::TimedMetadataTrack*>* arg0,
                                             ABI::Windows::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlaybackTimedMetadataTrackList>(arg0),
                      _createRtProxy<WMPTimedMetadataPresentationModeChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlayer_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlayer_System_Object__DEFINED
class ITypedEventHandler_Windows_Media_Playback_MediaPlayer_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaPlayer*, IInspectable*>> {
    void (^_delegate)(WMPMediaPlayer*, RTObject*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlayer_System_Object(void (^del)(WMPMediaPlayer*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlayer_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Playback::IMediaPlayer* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlayer>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_MediaPlayerFailedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_MediaPlayerFailedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_MediaPlayerFailedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaPlayer*,
                                                                       ABI::Windows::Media::Playback::MediaPlayerFailedEventArgs*>> {
    void (^_delegate)(WMPMediaPlayer*, WMPMediaPlayerFailedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_MediaPlayerFailedEventArgs(
        void (^del)(WMPMediaPlayer*, WMPMediaPlayerFailedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_MediaPlayerFailedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Playback::IMediaPlayer* arg0,
                                             ABI::Windows::Media::Playback::IMediaPlayerFailedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlayer>(arg0), _createRtProxy<WMPMediaPlayerFailedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_MediaPlayerRateChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_MediaPlayerRateChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_MediaPlayerRateChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaPlayer*,
                                                                       ABI::Windows::Media::Playback::MediaPlayerRateChangedEventArgs*>> {
    void (^_delegate)(WMPMediaPlayer*, WMPMediaPlayerRateChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_MediaPlayerRateChangedEventArgs(
        void (^del)(WMPMediaPlayer*, WMPMediaPlayerRateChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_MediaPlayerRateChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Playback::IMediaPlayer* arg0,
                                             ABI::Windows::Media::Playback::IMediaPlayerRateChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlayer>(arg0), _createRtProxy<WMPMediaPlayerRateChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_PlaybackMediaMarkerReachedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_PlaybackMediaMarkerReachedEventArgs__DEFINED
class ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_PlaybackMediaMarkerReachedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::Playback::MediaPlayer*,
                                                       ABI::Windows::Media::Playback::PlaybackMediaMarkerReachedEventArgs*>> {
    void (^_delegate)(WMPMediaPlayer*, WMPPlaybackMediaMarkerReachedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_PlaybackMediaMarkerReachedEventArgs(
        void (^del)(WMPMediaPlayer*, WMPPlaybackMediaMarkerReachedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_PlaybackMediaMarkerReachedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Media::Playback::IMediaPlayer* arg0,
                                             ABI::Windows::Media::Playback::IPlaybackMediaMarkerReachedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMPMediaPlayer>(arg0), _createRtProxy<WMPPlaybackMediaMarkerReachedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
