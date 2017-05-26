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

// WindowsMediaPlayback.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Playback.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaPlayback.h"
#include "WindowsMediaPlayback_priv.h"

@implementation WMPIMediaPlaybackSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WMPIMediaEnginePlaybackSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaEnginePlaybackSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPMediaPlaybackItem*)currentItem {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaEnginePlaybackSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get());
}

- (void)setPlaybackSource:(RTObject<WMPIMediaPlaybackSource>*)source {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaEnginePlaybackSource>(self);
    THROW_NS_IF_FAILED(_comInst->SetPlaybackSource(_getRtInterface<ABI::Windows::Media::Playback::IMediaPlaybackSource>(source).Get()));
}

@end

@implementation WMPPlaybackMediaMarker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IPlaybackMediaMarker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Playback::IPlaybackMediaMarkerFactory> WMPIPlaybackMediaMarkerFactory_inst() {
    ComPtr<ABI::Windows::Media::Playback::IPlaybackMediaMarkerFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Playback.PlaybackMediaMarker").Get(), &inst));
    return inst;
}

+ (WMPPlaybackMediaMarker*)makeFromTime:(WFTimeSpan*)value {
    ComPtr<ABI::Windows::Media::Playback::IPlaybackMediaMarker> unmarshalledReturn;
    auto _comInst = WMPIPlaybackMediaMarkerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromTime(*[value internalStruct], unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMPPlaybackMediaMarker>(unmarshalledReturn.Get()) retain];
}

+ (WMPPlaybackMediaMarker*)make:(WFTimeSpan*)value mediaMarketType:(NSString*)mediaMarketType text:(NSString*)text {
    ComPtr<ABI::Windows::Media::Playback::IPlaybackMediaMarker> unmarshalledReturn;
    auto _comInst = WMPIPlaybackMediaMarkerFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(*[value internalStruct],
                                        nsStrToHstr(mediaMarketType).Get(),
                                        nsStrToHstr(text).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMPPlaybackMediaMarker>(unmarshalledReturn.Get()) retain];
}

- (WFTimeSpan*)time {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IPlaybackMediaMarker>(self);
    THROW_NS_IF_FAILED(_comInst->get_Time(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (NSString*)mediaMarkerType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IPlaybackMediaMarker>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaMarkerType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IPlaybackMediaMarker>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMPPlaybackMediaMarkerSequence

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IPlaybackMediaMarkerSequence> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)size {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IPlaybackMediaMarkerSequence>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)insert:(WMPPlaybackMediaMarker*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IPlaybackMediaMarkerSequence>(self);
    THROW_NS_IF_FAILED(_comInst->Insert(_getRtInterface<ABI::Windows::Media::Playback::IPlaybackMediaMarker>(value).Get()));
}

- (void)clear {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IPlaybackMediaMarkerSequence>(self);
    THROW_NS_IF_FAILED(_comInst->Clear());
}

@end

@implementation WMPMediaPlayerFailedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlayerFailedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPMediaPlayerError)error {
    ABI::Windows::Media::Playback::MediaPlayerError unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Error(&unmarshalledReturn));
    return (WMPMediaPlayerError)unmarshalledReturn;
}

- (HRESULT)extendedErrorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (NSString*)errorMessage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorMessage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMPMediaPlayerRateChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlayerRateChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)newRate {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerRateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewRate(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMPPlaybackMediaMarkerReachedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IPlaybackMediaMarkerReachedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPPlaybackMediaMarker*)playbackMediaMarker {
    ComPtr<ABI::Windows::Media::Playback::IPlaybackMediaMarker> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IPlaybackMediaMarkerReachedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackMediaMarker(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPlaybackMediaMarker>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaPlayerDataReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlayerDataReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFCValueSet*)data {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerDataReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaPlayer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlayer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Playback.MediaPlayer").Get(), &out));
    return [_createRtProxy<WMPMediaPlayer>(out.Get()) retain];
}

- (BOOL)autoPlay {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoPlay(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAutoPlay:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoPlay((boolean)value));
}

- (WFTimeSpan*)naturalDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->get_NaturalDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)position {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setPosition:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->put_Position(*[value internalStruct]));
}

- (double)bufferingProgress {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->get_BufferingProgress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMPMediaPlayerState)currentState {
    ABI::Windows::Media::Playback::MediaPlayerState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentState(&unmarshalledReturn));
    return (WMPMediaPlayerState)unmarshalledReturn;
}

- (BOOL)canSeek {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanSeek(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canPause {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanPause(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isLoopingEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsLoopingEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsLoopingEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsLoopingEnabled((boolean)value));
}

- (BOOL)isProtected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsProtected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isMuted {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsMuted(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsMuted:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsMuted((boolean)value));
}

- (double)playbackRate {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackRate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPlaybackRate:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->put_PlaybackRate(value));
}

- (double)volume {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Volume(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setVolume:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->put_Volume(value));
}

- (WMPPlaybackMediaMarkerSequence*)playbackMediaMarkers {
    ComPtr<ABI::Windows::Media::Playback::IPlaybackMediaMarkerSequence> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackMediaMarkers(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPlaybackMediaMarkerSequence>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addMediaOpenedEvent:(void (^)(WMPMediaPlayer*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->add_MediaOpened(Make<ITypedEventHandler_Windows_Media_Playback_MediaPlayer_System_Object>(value).Get(),
                                                 &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMediaOpenedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MediaOpened(token));
}

- (EventRegistrationToken)addMediaEndedEvent:(void (^)(WMPMediaPlayer*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->add_MediaEnded(Make<ITypedEventHandler_Windows_Media_Playback_MediaPlayer_System_Object>(value).Get(),
                                                &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMediaEndedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MediaEnded(token));
}

- (EventRegistrationToken)addMediaFailedEvent:(void (^)(WMPMediaPlayer*, WMPMediaPlayerFailedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->add_MediaFailed(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_MediaPlayerFailedEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMediaFailedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MediaFailed(token));
}

- (EventRegistrationToken)addCurrentStateChangedEvent:(void (^)(WMPMediaPlayer*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_CurrentStateChanged(Make<ITypedEventHandler_Windows_Media_Playback_MediaPlayer_System_Object>(value).Get(),
                                          &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCurrentStateChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CurrentStateChanged(token));
}

- (EventRegistrationToken)addPlaybackMediaMarkerReachedEvent:(void (^)(WMPMediaPlayer*, WMPPlaybackMediaMarkerReachedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->add_PlaybackMediaMarkerReached(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_PlaybackMediaMarkerReachedEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePlaybackMediaMarkerReachedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PlaybackMediaMarkerReached(token));
}

- (EventRegistrationToken)addMediaPlayerRateChangedEvent:(void (^)(WMPMediaPlayer*, WMPMediaPlayerRateChangedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->add_MediaPlayerRateChanged(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaPlayer_Windows_Media_Playback_MediaPlayerRateChangedEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMediaPlayerRateChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MediaPlayerRateChanged(token));
}

- (EventRegistrationToken)addVolumeChangedEvent:(void (^)(WMPMediaPlayer*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->add_VolumeChanged(Make<ITypedEventHandler_Windows_Media_Playback_MediaPlayer_System_Object>(value).Get(),
                                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVolumeChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VolumeChanged(token));
}

- (EventRegistrationToken)addSeekCompletedEvent:(void (^)(WMPMediaPlayer*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->add_SeekCompleted(Make<ITypedEventHandler_Windows_Media_Playback_MediaPlayer_System_Object>(value).Get(),
                                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSeekCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SeekCompleted(token));
}

- (EventRegistrationToken)addBufferingStartedEvent:(void (^)(WMPMediaPlayer*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_BufferingStarted(Make<ITypedEventHandler_Windows_Media_Playback_MediaPlayer_System_Object>(value).Get(),
                                       &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBufferingStartedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BufferingStarted(token));
}

- (EventRegistrationToken)addBufferingEndedEvent:(void (^)(WMPMediaPlayer*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->add_BufferingEnded(Make<ITypedEventHandler_Windows_Media_Playback_MediaPlayer_System_Object>(value).Get(),
                                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBufferingEndedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BufferingEnded(token));
}

- (void)play {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->Play());
}

- (void)pause {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->Pause());
}

- (void)setUriSource:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer>(self);
    THROW_NS_IF_FAILED(_comInst->SetUriSource(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WMPMediaProtectionManager*)protectionManager {
    ComPtr<ABI::Windows::Media::Protection::IMediaProtectionManager> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionManager(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaProtectionManager>(unmarshalledReturn.Get());
}

- (void)setProtectionManager:(WMPMediaProtectionManager*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerSource>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ProtectionManager(_getRtInterface<ABI::Windows::Media::Protection::IMediaProtectionManager>(value).Get()));
}

- (void)setFileSource:(RTObject<WSIStorageFile>*)file {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerSource>(self);
    THROW_NS_IF_FAILED(_comInst->SetFileSource(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get()));
}

- (void)setStreamSource:(RTObject<WSSIRandomAccessStream>*)stream {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerSource>(self);
    THROW_NS_IF_FAILED(_comInst->SetStreamSource(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(stream).Get()));
}

- (void)setMediaSource:(RTObject<WMCIMediaSource>*)source {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerSource>(self);
    THROW_NS_IF_FAILED(_comInst->SetMediaSource(_getRtInterface<ABI::Windows::Media::Core::IMediaSource>(source).Get()));
}

- (RTObject<WMPIMediaPlaybackSource>*)source {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerSource2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPIMediaPlaybackSource>(unmarshalledReturn.Get());
}

- (void)setSource:(RTObject<WMPIMediaPlaybackSource>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerSource2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Source(_getRtInterface<ABI::Windows::Media::Playback::IMediaPlaybackSource>(value).Get()));
}

- (WMSystemMediaTransportControls*)systemMediaTransportControls {
    ComPtr<ABI::Windows::Media::ISystemMediaTransportControls> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemMediaTransportControls(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMSystemMediaTransportControls>(unmarshalledReturn.Get());
}

- (WMPMediaPlayerAudioCategory)audioCategory {
    ABI::Windows::Media::Playback::MediaPlayerAudioCategory unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioCategory(&unmarshalledReturn));
    return (WMPMediaPlayerAudioCategory)unmarshalledReturn;
}

- (void)setAudioCategory:(WMPMediaPlayerAudioCategory)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AudioCategory((ABI::Windows::Media::Playback::MediaPlayerAudioCategory)value));
}

- (WMPMediaPlayerAudioDeviceType)audioDeviceType {
    ABI::Windows::Media::Playback::MediaPlayerAudioDeviceType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioDeviceType(&unmarshalledReturn));
    return (WMPMediaPlayerAudioDeviceType)unmarshalledReturn;
}

- (void)setAudioDeviceType:(WMPMediaPlayerAudioDeviceType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AudioDeviceType((ABI::Windows::Media::Playback::MediaPlayerAudioDeviceType)value));
}

- (void)addAudioEffect:(NSString*)activatableClassId
        effectOptional:(BOOL)effectOptional
         configuration:(RTObject<WFCIPropertySet>*)configuration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerEffects>(self);
    THROW_NS_IF_FAILED(_comInst->AddAudioEffect(nsStrToHstr(activatableClassId).Get(),
                                                (boolean)effectOptional,
                                                _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get()));
}

- (void)removeAllEffects {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerEffects>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAllEffects());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (EventRegistrationToken)addIsMutedChangedEvent:(void (^)(WMPMediaPlayer*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->add_IsMutedChanged(Make<ITypedEventHandler_Windows_Media_Playback_MediaPlayer_System_Object>(value).Get(),
                                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeIsMutedChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->remove_IsMutedChanged(token));
}

- (EventRegistrationToken)addSourceChangedEvent:(void (^)(WMPMediaPlayer*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourceChanged(Make<ITypedEventHandler_Windows_Media_Playback_MediaPlayer_System_Object>(value).Get(),
                                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceChanged(token));
}

- (double)audioBalance {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioBalance(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setAudioBalance:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->put_AudioBalance(value));
}

- (BOOL)realTimePlayback {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->get_RealTimePlayback(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setRealTimePlayback:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->put_RealTimePlayback((boolean)value));
}

- (WMPStereoscopicVideoRenderMode)stereoscopicVideoRenderMode {
    ABI::Windows::Media::Playback::StereoscopicVideoRenderMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->get_StereoscopicVideoRenderMode(&unmarshalledReturn));
    return (WMPStereoscopicVideoRenderMode)unmarshalledReturn;
}

- (void)setStereoscopicVideoRenderMode:(WMPStereoscopicVideoRenderMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->put_StereoscopicVideoRenderMode((ABI::Windows::Media::Playback::StereoscopicVideoRenderMode)value));
}

- (WMPMediaBreakManager*)breakManager {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreakManager> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->get_BreakManager(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaBreakManager>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackCommandManager*)commandManager {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->get_CommandManager(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackCommandManager>(unmarshalledReturn.Get());
}

- (WDEDeviceInformation*)audioDevice {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioDevice(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformation>(unmarshalledReturn.Get());
}

- (void)setAudioDevice:(WDEDeviceInformation*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->put_AudioDevice(_getRtInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(value).Get()));
}

- (WMMediaTimelineController*)timelineController {
    ComPtr<ABI::Windows::Media::IMediaTimelineController> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimelineController(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMediaTimelineController>(unmarshalledReturn.Get());
}

- (void)setTimelineController:(WMMediaTimelineController*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->put_TimelineController(_getRtInterface<ABI::Windows::Media::IMediaTimelineController>(value).Get()));
}

- (WFTimeSpan*)timelineControllerPositionOffset {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimelineControllerPositionOffset(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setTimelineControllerPositionOffset:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->put_TimelineControllerPositionOffset(*[value internalStruct]));
}

- (WMPMediaPlaybackSession*)playbackSession {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackSession> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackSession(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackSession>(unmarshalledReturn.Get());
}

- (void)stepForwardOneFrame {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->StepForwardOneFrame());
}

- (void)stepBackwardOneFrame {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->StepBackwardOneFrame());
}

- (WMCCastingSource*)getAsCastingSource {
    ComPtr<ABI::Windows::Media::Casting::ICastingSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer3>(self);
    THROW_NS_IF_FAILED(_comInst->GetAsCastingSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCastingSource>(unmarshalledReturn.Get());
}

- (void)setSurfaceSize:(WFSize*)size {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer4>(self);
    THROW_NS_IF_FAILED(_comInst->SetSurfaceSize(*[size internalStruct]));
}

- (WMPMediaPlayerSurface*)getSurface:(WUCCompositor*)compositor {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlayerSurface> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayer4>(self);
    THROW_NS_IF_FAILED(_comInst->GetSurface(_getRtInterface<ABI::Windows::UI::Composition::ICompositor>(compositor).Get(),
                                            unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlayerSurface>(unmarshalledReturn.Get());
}

- (void)addVideoEffect:(NSString*)activatableClassId
         effectOptional:(BOOL)effectOptional
    effectConfiguration:(RTObject<WFCIPropertySet>*)effectConfiguration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerEffects2>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddVideoEffect(nsStrToHstr(activatableClassId).Get(),
                                 (boolean)effectOptional,
                                 _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(effectConfiguration).Get()));
}

@end

@implementation WMPMediaBreakManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreakManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addBreaksSeekedOverEvent:(void (^)(WMPMediaBreakManager*, WMPMediaBreakSeekedOverEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_BreaksSeekedOver(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakSeekedOverEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBreaksSeekedOverEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BreaksSeekedOver(token));
}

- (EventRegistrationToken)addBreakStartedEvent:(void (^)(WMPMediaBreakManager*, WMPMediaBreakStartedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_BreakStarted(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakStartedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBreakStartedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BreakStarted(token));
}

- (EventRegistrationToken)addBreakEndedEvent:(void (^)(WMPMediaBreakManager*, WMPMediaBreakEndedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_BreakEnded(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakEndedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBreakEndedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BreakEnded(token));
}

- (EventRegistrationToken)addBreakSkippedEvent:(void (^)(WMPMediaBreakManager*, WMPMediaBreakSkippedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_BreakSkipped(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaBreakManager_Windows_Media_Playback_MediaBreakSkippedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBreakSkippedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BreakSkipped(token));
}

- (WMPMediaBreak*)currentBreak {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreak> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentBreak(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaBreak>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackSession*)playbackSession {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackSession> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackSession(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackSession>(unmarshalledReturn.Get());
}

- (void)playBreak:(WMPMediaBreak*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakManager>(self);
    THROW_NS_IF_FAILED(_comInst->PlayBreak(_getRtInterface<ABI::Windows::Media::Playback::IMediaBreak>(value).Get()));
}

- (void)skipCurrentBreak {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakManager>(self);
    THROW_NS_IF_FAILED(_comInst->SkipCurrentBreak());
}

@end

@implementation WMPMediaPlaybackCommandManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsEnabled((boolean)value));
}

- (WMPMediaPlayer*)mediaPlayer {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlayer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaPlayer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlayer>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackCommandManagerCommandBehavior*)playBehavior {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlayBehavior(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackCommandManagerCommandBehavior>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackCommandManagerCommandBehavior*)pauseBehavior {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_PauseBehavior(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackCommandManagerCommandBehavior>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackCommandManagerCommandBehavior*)nextBehavior {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_NextBehavior(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackCommandManagerCommandBehavior>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackCommandManagerCommandBehavior*)previousBehavior {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousBehavior(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackCommandManagerCommandBehavior>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackCommandManagerCommandBehavior*)fastForwardBehavior {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_FastForwardBehavior(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackCommandManagerCommandBehavior>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackCommandManagerCommandBehavior*)rewindBehavior {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_RewindBehavior(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackCommandManagerCommandBehavior>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackCommandManagerCommandBehavior*)shuffleBehavior {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShuffleBehavior(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackCommandManagerCommandBehavior>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackCommandManagerCommandBehavior*)autoRepeatModeBehavior {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoRepeatModeBehavior(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackCommandManagerCommandBehavior>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackCommandManagerCommandBehavior*)positionBehavior {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_PositionBehavior(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackCommandManagerCommandBehavior>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackCommandManagerCommandBehavior*)rateBehavior {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_RateBehavior(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackCommandManagerCommandBehavior>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addPlayReceivedEvent:(void (^)(WMPMediaPlaybackCommandManager*,
                                                         WMPMediaPlaybackCommandManagerPlayReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_PlayReceived(
        Make<
            ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPlayReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePlayReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PlayReceived(token));
}

- (EventRegistrationToken)addPauseReceivedEvent:(void (^)(WMPMediaPlaybackCommandManager*,
                                                          WMPMediaPlaybackCommandManagerPauseReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_PauseReceived(
        Make<
            ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPauseReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePauseReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PauseReceived(token));
}

- (EventRegistrationToken)addNextReceivedEvent:(void (^)(WMPMediaPlaybackCommandManager*,
                                                         WMPMediaPlaybackCommandManagerNextReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_NextReceived(
        Make<
            ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerNextReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeNextReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_NextReceived(token));
}

- (EventRegistrationToken)addPreviousReceivedEvent:(void (^)(WMPMediaPlaybackCommandManager*,
                                                             WMPMediaPlaybackCommandManagerPreviousReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_PreviousReceived(
        Make<
            ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPreviousReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePreviousReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PreviousReceived(token));
}

- (EventRegistrationToken)addFastForwardReceivedEvent:(void (^)(WMPMediaPlaybackCommandManager*,
                                                                WMPMediaPlaybackCommandManagerFastForwardReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_FastForwardReceived(
        Make<
            ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerFastForwardReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeFastForwardReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_FastForwardReceived(token));
}

- (EventRegistrationToken)addRewindReceivedEvent:(void (^)(WMPMediaPlaybackCommandManager*,
                                                           WMPMediaPlaybackCommandManagerRewindReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_RewindReceived(
        Make<
            ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerRewindReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRewindReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RewindReceived(token));
}

- (EventRegistrationToken)addShuffleReceivedEvent:(void (^)(WMPMediaPlaybackCommandManager*,
                                                            WMPMediaPlaybackCommandManagerShuffleReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_ShuffleReceived(
        Make<
            ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerShuffleReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeShuffleReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ShuffleReceived(token));
}

- (EventRegistrationToken)addAutoRepeatModeReceivedEvent:(void (^)(WMPMediaPlaybackCommandManager*,
                                                                   WMPMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_AutoRepeatModeReceived(
        Make<
            ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAutoRepeatModeReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AutoRepeatModeReceived(token));
}

- (EventRegistrationToken)addPositionReceivedEvent:(void (^)(WMPMediaPlaybackCommandManager*,
                                                             WMPMediaPlaybackCommandManagerPositionReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_PositionReceived(
        Make<
            ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerPositionReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePositionReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PositionReceived(token));
}

- (EventRegistrationToken)addRateReceivedEvent:(void (^)(WMPMediaPlaybackCommandManager*,
                                                         WMPMediaPlaybackCommandManagerRateReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_RateReceived(
        Make<
            ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManager_Windows_Media_Playback_MediaPlaybackCommandManagerRateReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRateReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RateReceived(token));
}

@end

@implementation WMPMediaPlaybackSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addPlaybackStateChangedEvent:(void (^)(WMPMediaPlaybackSession*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PlaybackStateChanged(Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackSession_System_Object>(value).Get(),
                                           &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePlaybackStateChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PlaybackStateChanged(token));
}

- (EventRegistrationToken)addPlaybackRateChangedEvent:(void (^)(WMPMediaPlaybackSession*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PlaybackRateChanged(Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackSession_System_Object>(value).Get(),
                                          &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePlaybackRateChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PlaybackRateChanged(token));
}

- (EventRegistrationToken)addSeekCompletedEvent:(void (^)(WMPMediaPlaybackSession*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_SeekCompleted(Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackSession_System_Object>(value).Get(),
                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSeekCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SeekCompleted(token));
}

- (EventRegistrationToken)addBufferingStartedEvent:(void (^)(WMPMediaPlaybackSession*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_BufferingStarted(Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackSession_System_Object>(value).Get(),
                                       &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBufferingStartedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BufferingStarted(token));
}

- (EventRegistrationToken)addBufferingEndedEvent:(void (^)(WMPMediaPlaybackSession*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_BufferingEnded(Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackSession_System_Object>(value).Get(),
                                     &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBufferingEndedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BufferingEnded(token));
}

- (EventRegistrationToken)addBufferingProgressChangedEvent:(void (^)(WMPMediaPlaybackSession*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->add_BufferingProgressChanged(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackSession_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBufferingProgressChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BufferingProgressChanged(token));
}

- (EventRegistrationToken)addDownloadProgressChangedEvent:(void (^)(WMPMediaPlaybackSession*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->add_DownloadProgressChanged(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackSession_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDownloadProgressChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DownloadProgressChanged(token));
}

- (EventRegistrationToken)addNaturalDurationChangedEvent:(void (^)(WMPMediaPlaybackSession*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->add_NaturalDurationChanged(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackSession_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeNaturalDurationChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_NaturalDurationChanged(token));
}

- (EventRegistrationToken)addPositionChangedEvent:(void (^)(WMPMediaPlaybackSession*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PositionChanged(Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackSession_System_Object>(value).Get(),
                                      &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePositionChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PositionChanged(token));
}

- (EventRegistrationToken)addNaturalVideoSizeChangedEvent:(void (^)(WMPMediaPlaybackSession*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->add_NaturalVideoSizeChanged(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackSession_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeNaturalVideoSizeChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_NaturalVideoSizeChanged(token));
}

- (WMPMediaPlayer*)mediaPlayer {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlayer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaPlayer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlayer>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)naturalDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_NaturalDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)position {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setPosition:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->put_Position(*[value internalStruct]));
}

- (WMPMediaPlaybackState)playbackState {
    ABI::Windows::Media::Playback::MediaPlaybackState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackState(&unmarshalledReturn));
    return (WMPMediaPlaybackState)unmarshalledReturn;
}

- (BOOL)canSeek {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanSeek(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canPause {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanPause(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isProtected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsProtected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)playbackRate {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackRate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPlaybackRate:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->put_PlaybackRate(value));
}

- (double)bufferingProgress {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_BufferingProgress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)downloadProgress {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_DownloadProgress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)naturalVideoHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_NaturalVideoHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)naturalVideoWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_NaturalVideoWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFRect*)normalizedSourceRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_NormalizedSourceRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)setNormalizedSourceRect:(WFRect*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->put_NormalizedSourceRect(*[value internalStruct]));
}

- (WMMStereoscopicVideoPackingMode)stereoscopicVideoPackingMode {
    ABI::Windows::Media::MediaProperties::StereoscopicVideoPackingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_StereoscopicVideoPackingMode(&unmarshalledReturn));
    return (WMMStereoscopicVideoPackingMode)unmarshalledReturn;
}

- (void)setStereoscopicVideoPackingMode:(WMMStereoscopicVideoPackingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_StereoscopicVideoPackingMode((ABI::Windows::Media::MediaProperties::StereoscopicVideoPackingMode)value));
}

@end

@implementation WMPMediaPlayerSurface

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlayerSurface> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WUCICompositionSurface>*)compositionSurface {
    ComPtr<ABI::Windows::UI::Composition::ICompositionSurface> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerSurface>(self);
    THROW_NS_IF_FAILED(_comInst->get_CompositionSurface(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCICompositionSurface>(unmarshalledReturn.Get());
}

- (WUCCompositor*)compositor {
    ComPtr<ABI::Windows::UI::Composition::ICompositor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerSurface>(self);
    THROW_NS_IF_FAILED(_comInst->get_Compositor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositor>(unmarshalledReturn.Get());
}

- (WMPMediaPlayer*)mediaPlayer {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlayer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlayerSurface>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaPlayer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlayer>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMPMediaBreakSeekedOverEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreakSeekedOverEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WMPMediaBreak* */)seekedOverBreaks {
    ComPtr<IVectorView<ABI::Windows::Media::Playback::MediaBreak*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakSeekedOverEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SeekedOverBreaks(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMPMediaBreak_create(unmarshalledReturn.Get());
}

- (WFTimeSpan*)oldPosition {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakSeekedOverEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldPosition(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)newPosition __attribute__((ns_returns_not_retained)) {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakSeekedOverEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewPosition(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

@end

@implementation WMPMediaBreakStartedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreakStartedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPMediaBreak*)mediaBreak {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreak> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaBreak(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaBreak>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaBreakEndedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreakEndedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPMediaBreak*)mediaBreak {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreak> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakEndedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaBreak(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaBreak>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaBreakSkippedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreakSkippedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPMediaBreak*)mediaBreak {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreak> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakSkippedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaBreak(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaBreak>(unmarshalledReturn.Get());
}

@end

@implementation WMPBackgroundMediaPlayer

ComPtr<ABI::Windows::Media::Playback::IBackgroundMediaPlayerStatics> WMPIBackgroundMediaPlayerStatics_inst() {
    ComPtr<ABI::Windows::Media::Playback::IBackgroundMediaPlayerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Playback.BackgroundMediaPlayer").Get(),
                                                       &inst));
    return inst;
}

+ (WMPMediaPlayer*)current {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlayer> unmarshalledReturn;
    auto _comInst = WMPIBackgroundMediaPlayerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Current(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlayer>(unmarshalledReturn.Get());
}

+ (EventRegistrationToken)addMessageReceivedFromBackgroundEvent:(void (^)(RTObject*, WMPMediaPlayerDataReceivedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WMPIBackgroundMediaPlayerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_MessageReceivedFromBackground(Make<EventHandler_Windows_Media_Playback_MediaPlayerDataReceivedEventArgs>(value).Get(),
                                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeMessageReceivedFromBackgroundEvent:(EventRegistrationToken)token {
    auto _comInst = WMPIBackgroundMediaPlayerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_MessageReceivedFromBackground(token));
}

+ (EventRegistrationToken)addMessageReceivedFromForegroundEvent:(void (^)(RTObject*, WMPMediaPlayerDataReceivedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WMPIBackgroundMediaPlayerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_MessageReceivedFromForeground(Make<EventHandler_Windows_Media_Playback_MediaPlayerDataReceivedEventArgs>(value).Get(),
                                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeMessageReceivedFromForegroundEvent:(EventRegistrationToken)token {
    auto _comInst = WMPIBackgroundMediaPlayerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_MessageReceivedFromForeground(token));
}

+ (void)sendMessageToBackground:(WFCValueSet*)value {
    auto _comInst = WMPIBackgroundMediaPlayerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SendMessageToBackground(_getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(value).Get()));
}

+ (void)sendMessageToForeground:(WFCValueSet*)value {
    auto _comInst = WMPIBackgroundMediaPlayerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SendMessageToForeground(_getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(value).Get()));
}

+ (BOOL)isMediaPlaying {
    boolean unmarshalledReturn;
    auto _comInst = WMPIBackgroundMediaPlayerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsMediaPlaying(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)shutdown {
    auto _comInst = WMPIBackgroundMediaPlayerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Shutdown());
}

@end

@implementation WMPMediaPlaybackCommandManagerPlayReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPlayReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaPlaybackCommandManagerPauseReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPauseReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaPlaybackCommandManagerNextReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerNextReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaPlaybackCommandManagerPreviousReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPreviousReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaPlaybackCommandManagerFastForwardReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerFastForwardReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaPlaybackCommandManagerRewindReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerRewindReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaPlaybackCommandManagerShuffleReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (BOOL)isShuffleRequested {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsShuffleRequested(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerShuffleReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WMMediaPlaybackAutoRepeatMode)autoRepeatMode {
    ABI::Windows::Media::MediaPlaybackAutoRepeatMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoRepeatMode(&unmarshalledReturn));
    return (WMMediaPlaybackAutoRepeatMode)unmarshalledReturn;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerAutoRepeatModeReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaPlaybackCommandManagerPositionReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (WFTimeSpan*)position {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerPositionReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaPlaybackCommandManagerRateReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

- (double)playbackRate {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackRate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerRateReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaPlaybackCommandManagerCommandBehavior

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPMediaPlaybackCommandManager*)commandManager {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackCommandManager> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->get_CommandManager(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackCommandManager>(unmarshalledReturn.Get());
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WMPMediaCommandEnablingRule)enablingRule {
    ABI::Windows::Media::Playback::MediaCommandEnablingRule unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnablingRule(&unmarshalledReturn));
    return (WMPMediaCommandEnablingRule)unmarshalledReturn;
}

- (void)setEnablingRule:(WMPMediaCommandEnablingRule)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->put_EnablingRule((ABI::Windows::Media::Playback::MediaCommandEnablingRule)value));
}

- (EventRegistrationToken)addIsEnabledChangedEvent:(void (^)(WMPMediaPlaybackCommandManagerCommandBehavior*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->add_IsEnabledChanged(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackCommandManagerCommandBehavior_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeIsEnabledChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackCommandManagerCommandBehavior>(self);
    THROW_NS_IF_FAILED(_comInst->remove_IsEnabledChanged(token));
}

@end

@implementation WMPMediaPlaybackItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItemFactory2> WMPIMediaPlaybackItemFactory2_inst() {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItemFactory2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Playback.MediaPlaybackItem").Get(), &inst));
    return inst;
}

+ (WMPMediaPlaybackItem*)makeWithStartTime:(WMCMediaSource*)source startTime:(WFTimeSpan*)startTime {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = WMPIMediaPlaybackItemFactory2_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithStartTime(_getRtInterface<ABI::Windows::Media::Core::IMediaSource2>(source).Get(),
                                                     *[startTime internalStruct],
                                                     unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get()) retain];
}

+ (WMPMediaPlaybackItem*)makeWithStartTimeAndDurationLimit:(WMCMediaSource*)source
                                                 startTime:(WFTimeSpan*)startTime
                                             durationLimit:(WFTimeSpan*)durationLimit {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = WMPIMediaPlaybackItemFactory2_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithStartTimeAndDurationLimit(_getRtInterface<ABI::Windows::Media::Core::IMediaSource2>(source).Get(),
                                                      *[startTime internalStruct],
                                                      *[durationLimit internalStruct],
                                                      unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get()) retain];
}

static ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItemFactory> WMPIMediaPlaybackItemFactory_inst() {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItemFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Playback.MediaPlaybackItem").Get(), &inst));
    return inst;
}

+ (WMPMediaPlaybackItem*)make:(WMCMediaSource*)source {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = WMPIMediaPlaybackItemFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Media::Core::IMediaSource2>(source).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItemStatics> WMPIMediaPlaybackItemStatics_inst() {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItemStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Playback.MediaPlaybackItem").Get(), &inst));
    return inst;
}

+ (WMPMediaPlaybackItem*)findFromMediaSource:(WMCMediaSource*)source {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = WMPIMediaPlaybackItemStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindFromMediaSource(_getRtInterface<ABI::Windows::Media::Core::IMediaSource2>(source).Get(),
                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addAudioTracksChangedEvent:(void (^)(WMPMediaPlaybackItem*, RTObject<WFCIVectorChangedEventArgs>*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem>(self);
    THROW_NS_IF_FAILED(_comInst->add_AudioTracksChanged(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackItem_Windows_Foundation_Collections_IVectorChangedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAudioTracksChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AudioTracksChanged(token));
}

- (EventRegistrationToken)addVideoTracksChangedEvent:(void (^)(WMPMediaPlaybackItem*, RTObject<WFCIVectorChangedEventArgs>*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem>(self);
    THROW_NS_IF_FAILED(_comInst->add_VideoTracksChanged(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackItem_Windows_Foundation_Collections_IVectorChangedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVideoTracksChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VideoTracksChanged(token));
}

- (EventRegistrationToken)addTimedMetadataTracksChangedEvent:(void (^)(WMPMediaPlaybackItem*,
                                                                       RTObject<WFCIVectorChangedEventArgs>*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem>(self);
    THROW_NS_IF_FAILED(_comInst->add_TimedMetadataTracksChanged(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackItem_Windows_Foundation_Collections_IVectorChangedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTimedMetadataTracksChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TimedMetadataTracksChanged(token));
}

- (WMCMediaSource*)source {
    ComPtr<ABI::Windows::Media::Core::IMediaSource2> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaSource>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackAudioTrackList*)audioTracks {
    ComPtr<IVectorView<ABI::Windows::Media::Core::AudioTrack*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioTracks(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackAudioTrackList>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackVideoTrackList*)videoTracks {
    ComPtr<IVectorView<ABI::Windows::Media::Core::VideoTrack*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoTracks(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackVideoTrackList>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackTimedMetadataTrackList*)timedMetadataTracks {
    ComPtr<IVectorView<ABI::Windows::Media::Core::TimedMetadataTrack*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimedMetadataTracks(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackTimedMetadataTrackList>(unmarshalledReturn.Get());
}

- (WMPMediaBreakSchedule*)breakSchedule {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreakSchedule> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem2>(self);
    THROW_NS_IF_FAILED(_comInst->get_BreakSchedule(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaBreakSchedule>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)startTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem2>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (id /* WFTimeSpan* */)durationLimit {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DurationLimit(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (BOOL)canSkip {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanSkip(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanSkip:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanSkip((boolean)value));
}

- (WMPMediaItemDisplayProperties*)getDisplayProperties {
    ComPtr<ABI::Windows::Media::Playback::IMediaItemDisplayProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem2>(self);
    THROW_NS_IF_FAILED(_comInst->GetDisplayProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaItemDisplayProperties>(unmarshalledReturn.Get());
}

- (void)applyDisplayProperties:(WMPMediaItemDisplayProperties*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem2>(self);
    THROW_NS_IF_FAILED(
        _comInst->ApplyDisplayProperties(_getRtInterface<ABI::Windows::Media::Playback::IMediaItemDisplayProperties>(value).Get()));
}

@end

@implementation WMPMediaPlaybackAudioTrackList {
    RTArrayObj<ABI::Windows::Media::Core::IMediaTrack*,
               IVectorView<ABI::Windows::Media::Core::AudioTrack*>,
               WMCAudioTrack,
               ABI::Windows::Media::Core::AudioTrack*,
               dummyObjCCreator,
               dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTORVIEW_FULL(self.comObj, WMCAudioTrack, ABI::Windows::Media::Core::IMediaTrack*, ABI::Windows::Media::Core::AudioTrack*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVectorView<ABI::Windows::Media::Core::AudioTrack*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addSelectedIndexChangedEvent:(void (^)(RTObject<WMCISingleSelectMediaTrackList>*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ISingleSelectMediaTrackList>(self);
    THROW_NS_IF_FAILED(_comInst->add_SelectedIndexChanged(
        Make<ITypedEventHandler_Windows_Media_Core_ISingleSelectMediaTrackList_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSelectedIndexChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ISingleSelectMediaTrackList>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SelectedIndexChanged(token));
}

- (void)setSelectedIndex:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ISingleSelectMediaTrackList>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedIndex(value));
}

- (int)selectedIndex {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ISingleSelectMediaTrackList>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMPMediaPlaybackVideoTrackList {
    RTArrayObj<ABI::Windows::Media::Core::IMediaTrack*,
               IVectorView<ABI::Windows::Media::Core::VideoTrack*>,
               WMCVideoTrack,
               ABI::Windows::Media::Core::VideoTrack*,
               dummyObjCCreator,
               dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTORVIEW_FULL(self.comObj, WMCVideoTrack, ABI::Windows::Media::Core::IMediaTrack*, ABI::Windows::Media::Core::VideoTrack*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVectorView<ABI::Windows::Media::Core::VideoTrack*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addSelectedIndexChangedEvent:(void (^)(RTObject<WMCISingleSelectMediaTrackList>*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ISingleSelectMediaTrackList>(self);
    THROW_NS_IF_FAILED(_comInst->add_SelectedIndexChanged(
        Make<ITypedEventHandler_Windows_Media_Core_ISingleSelectMediaTrackList_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSelectedIndexChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ISingleSelectMediaTrackList>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SelectedIndexChanged(token));
}

- (void)setSelectedIndex:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ISingleSelectMediaTrackList>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedIndex(value));
}

- (int)selectedIndex {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ISingleSelectMediaTrackList>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMPMediaPlaybackTimedMetadataTrackList {
    RTArrayObj<ABI::Windows::Media::Core::ITimedMetadataTrack*,
               IVectorView<ABI::Windows::Media::Core::TimedMetadataTrack*>,
               WMCTimedMetadataTrack,
               ABI::Windows::Media::Core::TimedMetadataTrack*,
               dummyObjCCreator,
               dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTORVIEW_FULL(self.comObj,
                             WMCTimedMetadataTrack,
                             ABI::Windows::Media::Core::ITimedMetadataTrack*,
                             ABI::Windows::Media::Core::TimedMetadataTrack*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVectorView<ABI::Windows::Media::Core::TimedMetadataTrack*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addPresentationModeChangedEvent:(void (^)(WMPMediaPlaybackTimedMetadataTrackList*,
                                                                    WMPTimedMetadataPresentationModeChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackTimedMetadataTrackList>(self);
    THROW_NS_IF_FAILED(_comInst->add_PresentationModeChanged(
        Make<
            ITypedEventHandler_Windows_Media_Playback_MediaPlaybackTimedMetadataTrackList_Windows_Media_Playback_TimedMetadataPresentationModeChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePresentationModeChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackTimedMetadataTrackList>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PresentationModeChanged(token));
}

- (WMPTimedMetadataTrackPresentationMode)getPresentationMode:(unsigned int)index {
    ABI::Windows::Media::Playback::TimedMetadataTrackPresentationMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackTimedMetadataTrackList>(self);
    THROW_NS_IF_FAILED(_comInst->GetPresentationMode(index, &unmarshalledReturn));
    return (WMPTimedMetadataTrackPresentationMode)unmarshalledReturn;
}

- (void)setPresentationMode:(unsigned int)index value:(WMPTimedMetadataTrackPresentationMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackTimedMetadataTrackList>(self);
    THROW_NS_IF_FAILED(_comInst->SetPresentationMode(index, (ABI::Windows::Media::Playback::TimedMetadataTrackPresentationMode)value));
}

@end

@implementation WMPMediaBreakSchedule

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreakSchedule> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addScheduleChangedEvent:(void (^)(WMPMediaBreakSchedule*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakSchedule>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ScheduleChanged(Make<ITypedEventHandler_Windows_Media_Playback_MediaBreakSchedule_System_Object>(handler).Get(),
                                      &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeScheduleChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakSchedule>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ScheduleChanged(token));
}

- (void)insertMidrollBreak:(WMPMediaBreak*)mediaBreak {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakSchedule>(self);
    THROW_NS_IF_FAILED(_comInst->InsertMidrollBreak(_getRtInterface<ABI::Windows::Media::Playback::IMediaBreak>(mediaBreak).Get()));
}

- (void)removeMidrollBreak:(WMPMediaBreak*)mediaBreak {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakSchedule>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveMidrollBreak(_getRtInterface<ABI::Windows::Media::Playback::IMediaBreak>(mediaBreak).Get()));
}

- (NSArray* /* WMPMediaBreak* */)midrollBreaks {
    ComPtr<IVectorView<ABI::Windows::Media::Playback::MediaBreak*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakSchedule>(self);
    THROW_NS_IF_FAILED(_comInst->get_MidrollBreaks(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMPMediaBreak_create(unmarshalledReturn.Get());
}

- (void)setPrerollBreak:(WMPMediaBreak*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakSchedule>(self);
    THROW_NS_IF_FAILED(_comInst->put_PrerollBreak(_getRtInterface<ABI::Windows::Media::Playback::IMediaBreak>(value).Get()));
}

- (WMPMediaBreak*)prerollBreak {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreak> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakSchedule>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrerollBreak(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaBreak>(unmarshalledReturn.Get());
}

- (void)setPostrollBreak:(WMPMediaBreak*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakSchedule>(self);
    THROW_NS_IF_FAILED(_comInst->put_PostrollBreak(_getRtInterface<ABI::Windows::Media::Playback::IMediaBreak>(value).Get()));
}

- (WMPMediaBreak*)postrollBreak {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreak> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakSchedule>(self);
    THROW_NS_IF_FAILED(_comInst->get_PostrollBreak(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaBreak>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackItem*)playbackItem {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreakSchedule>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaItemDisplayProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaItemDisplayProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMMediaPlaybackType)type {
    ABI::Windows::Media::MediaPlaybackType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaItemDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WMMediaPlaybackType)unmarshalledReturn;
}

- (void)setType:(WMMediaPlaybackType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaItemDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Type((ABI::Windows::Media::MediaPlaybackType)value));
}

- (WMMusicDisplayProperties*)musicProperties {
    ComPtr<ABI::Windows::Media::IMusicDisplayProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaItemDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_MusicProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMusicDisplayProperties>(unmarshalledReturn.Get());
}

- (WMVideoDisplayProperties*)videoProperties {
    ComPtr<ABI::Windows::Media::IVideoDisplayProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaItemDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMVideoDisplayProperties>(unmarshalledReturn.Get());
}

- (WSSRandomAccessStreamReference*)thumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaItemDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setThumbnail:(WSSRandomAccessStreamReference*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaItemDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Thumbnail(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (void)clearAll {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaItemDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->ClearAll());
}

@end

@implementation WMPMediaBreak

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreak> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Playback::IMediaBreakFactory> WMPIMediaBreakFactory_inst() {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreakFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Playback.MediaBreak").Get(), &inst));
    return inst;
}

+ (WMPMediaBreak*)make:(WMPMediaBreakInsertionMethod)insertionMethod {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreak> unmarshalledReturn;
    auto _comInst = WMPIMediaBreakFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create((ABI::Windows::Media::Playback::MediaBreakInsertionMethod)insertionMethod, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMPMediaBreak>(unmarshalledReturn.Get()) retain];
}

+ (WMPMediaBreak*)makeWithPresentationPosition:(WMPMediaBreakInsertionMethod)insertionMethod
                          presentationPosition:(WFTimeSpan*)presentationPosition {
    ComPtr<ABI::Windows::Media::Playback::IMediaBreak> unmarshalledReturn;
    auto _comInst = WMPIMediaBreakFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithPresentationPosition((ABI::Windows::Media::Playback::MediaBreakInsertionMethod)insertionMethod,
                                                                *[presentationPosition internalStruct],
                                                                unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMPMediaBreak>(unmarshalledReturn.Get()) retain];
}

- (WMPMediaPlaybackList*)playbackList {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreak>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackList(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackList>(unmarshalledReturn.Get());
}

- (id /* WFTimeSpan* */)presentationPosition {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreak>(self);
    THROW_NS_IF_FAILED(_comInst->get_PresentationPosition(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (WMPMediaBreakInsertionMethod)insertionMethod {
    ABI::Windows::Media::Playback::MediaBreakInsertionMethod unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreak>(self);
    THROW_NS_IF_FAILED(_comInst->get_InsertionMethod(&unmarshalledReturn));
    return (WMPMediaBreakInsertionMethod)unmarshalledReturn;
}

- (WFCValueSet*)customProperties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreak>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

- (BOOL)canStart {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreak>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanStart(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanStart:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaBreak>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanStart((boolean)value));
}

@end

@implementation WMPMediaPlaybackList

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackList> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Playback.MediaPlaybackList").Get(), &out));
    return [_createRtProxy<WMPMediaPlaybackList>(out.Get()) retain];
}

- (EventRegistrationToken)addItemFailedEvent:(void (^)(WMPMediaPlaybackList*, WMPMediaPlaybackItemFailedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList>(self);
    THROW_NS_IF_FAILED(_comInst->add_ItemFailed(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_MediaPlaybackItemFailedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeItemFailedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ItemFailed(token));
}

- (EventRegistrationToken)addCurrentItemChangedEvent:(void (^)(WMPMediaPlaybackList*,
                                                               WMPCurrentMediaPlaybackItemChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList>(self);
    THROW_NS_IF_FAILED(_comInst->add_CurrentItemChanged(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_CurrentMediaPlaybackItemChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCurrentItemChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CurrentItemChanged(token));
}

- (EventRegistrationToken)addItemOpenedEvent:(void (^)(WMPMediaPlaybackList*, WMPMediaPlaybackItemOpenedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList>(self);
    THROW_NS_IF_FAILED(_comInst->add_ItemOpened(
        Make<ITypedEventHandler_Windows_Media_Playback_MediaPlaybackList_Windows_Media_Playback_MediaPlaybackItemOpenedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeItemOpenedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ItemOpened(token));
}

- (NSMutableArray<RTObservableCollection>* /* WMPMediaPlaybackItem* */)items {
    ComPtr<IObservableVector<ABI::Windows::Media::Playback::MediaPlaybackItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedObservableNSMutableArray_WMPMediaPlaybackItem_create(unmarshalledReturn.Get());
}

- (BOOL)autoRepeatEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoRepeatEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAutoRepeatEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoRepeatEnabled((boolean)value));
}

- (BOOL)shuffleEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShuffleEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setShuffleEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList>(self);
    THROW_NS_IF_FAILED(_comInst->put_ShuffleEnabled((boolean)value));
}

- (WMPMediaPlaybackItem*)currentItem {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get());
}

- (unsigned int)currentItemIndex {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentItemIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMPMediaPlaybackItem*)moveNext {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList>(self);
    THROW_NS_IF_FAILED(_comInst->MoveNext(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackItem*)movePrevious {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList>(self);
    THROW_NS_IF_FAILED(_comInst->MovePrevious(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackItem*)moveTo:(unsigned int)itemIndex {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList>(self);
    THROW_NS_IF_FAILED(_comInst->MoveTo(itemIndex, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get());
}

- (id /* WFTimeSpan* */)maxPrefetchTime {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPrefetchTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setMaxPrefetchTime:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList2>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxPrefetchTime(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (WMPMediaPlaybackItem*)startingItem {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList2>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartingItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get());
}

- (void)setStartingItem:(WMPMediaPlaybackItem*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList2>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartingItem(_getRtInterface<ABI::Windows::Media::Playback::IMediaPlaybackItem>(value).Get()));
}

- (NSArray* /* WMPMediaPlaybackItem* */)shuffledItems {
    ComPtr<IVectorView<ABI::Windows::Media::Playback::MediaPlaybackItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShuffledItems(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMPMediaPlaybackItem_create(unmarshalledReturn.Get());
}

- (void)setShuffledItems:(id<NSFastEnumeration> /* WMPMediaPlaybackItem* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackList2>(self);
    THROW_NS_IF_FAILED(_comInst->SetShuffledItems(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Media::Playback::MediaPlaybackItem*,
                                                              ABI::Windows::Media::Playback::IMediaPlaybackItem*>>::type>*>(
            ConvertToIterable<WMPMediaPlaybackItem,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Media::Playback::MediaPlaybackItem*,
                                                                                ABI::Windows::Media::Playback::IMediaPlaybackItem*>>(value)
                .Get())));
}

@end

@implementation WMPMediaPlaybackItemError

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItemError> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPMediaPlaybackItemErrorCode)errorCode {
    ABI::Windows::Media::Playback::MediaPlaybackItemErrorCode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItemError>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (WMPMediaPlaybackItemErrorCode)unmarshalledReturn;
}

- (HRESULT)extendedError {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItemError>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedError(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WMPMediaPlaybackItemFailedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItemFailedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPMediaPlaybackItem*)item {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItemFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Item(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackItemError*)error {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItemError> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItemFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Error(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItemError>(unmarshalledReturn.Get());
}

@end

@implementation WMPCurrentMediaPlaybackItemChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPMediaPlaybackItem*)newItem __attribute__((ns_returns_not_retained)) {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackItem*)oldItem {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::ICurrentMediaPlaybackItemChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get());
}

@end

@implementation WMPMediaPlaybackItemOpenedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItemOpenedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPMediaPlaybackItem*)item {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::IMediaPlaybackItemOpenedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Item(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get());
}

@end

@implementation WMPTimedMetadataPresentationModeChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCTimedMetadataTrack*)track {
    ComPtr<ABI::Windows::Media::Core::ITimedMetadataTrack> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Track(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCTimedMetadataTrack>(unmarshalledReturn.Get());
}

- (WMPTimedMetadataTrackPresentationMode)oldPresentationMode {
    ABI::Windows::Media::Playback::TimedMetadataTrackPresentationMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldPresentationMode(&unmarshalledReturn));
    return (WMPTimedMetadataTrackPresentationMode)unmarshalledReturn;
}

- (WMPTimedMetadataTrackPresentationMode)newPresentationMode {
    ABI::Windows::Media::Playback::TimedMetadataTrackPresentationMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Playback::ITimedMetadataPresentationModeChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewPresentationMode(&unmarshalledReturn));
    return (WMPTimedMetadataTrackPresentationMode)unmarshalledReturn;
}

@end

id RTProxiedIterableNSArray_WMPMediaPlaybackItem_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Media::Playback::MediaPlaybackItem*>,
                                                 RTIterableObj<ABI::Windows::Media::Playback::IMediaPlaybackItem*,
                                                               IIterable<ABI::Windows::Media::Playback::MediaPlaybackItem*>,
                                                               WMPMediaPlaybackItem,
                                                               ABI::Windows::Media::Playback::MediaPlaybackItem*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMPMediaBreak_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Playback::MediaBreak*>,
                                         RTArrayObj<ABI::Windows::Media::Playback::IMediaBreak*,
                                                    IVectorView<ABI::Windows::Media::Playback::MediaBreak*>,
                                                    WMPMediaBreak,
                                                    ABI::Windows::Media::Playback::MediaBreak*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMPMediaPlaybackItem_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Playback::MediaPlaybackItem*>,
                                         RTArrayObj<ABI::Windows::Media::Playback::IMediaPlaybackItem*,
                                                    IVectorView<ABI::Windows::Media::Playback::MediaPlaybackItem*>,
                                                    WMPMediaPlaybackItem,
                                                    ABI::Windows::Media::Playback::MediaPlaybackItem*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedObservableNSMutableArray_WMPMediaPlaybackItem_create(IInspectable* val) {
    std::unique_ptr<ObservableArrayAdapter> adapter =
        std::make_unique<ObservableArrayAdapterObj<IObservableVector<ABI::Windows::Media::Playback::MediaPlaybackItem*>,
                                                   RTObservableArrayObj<ABI::Windows::Media::Playback::IMediaPlaybackItem*,
                                                                        IVector<ABI::Windows::Media::Playback::MediaPlaybackItem*>,
                                                                        WMPMediaPlaybackItem,
                                                                        ABI::Windows::Media::Playback::MediaPlaybackItem*,
                                                                        dummyObjCCreator,
                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedObservableNSMutableArray alloc] initWithAdapter:std::move(adapter)] autorelease];
}
