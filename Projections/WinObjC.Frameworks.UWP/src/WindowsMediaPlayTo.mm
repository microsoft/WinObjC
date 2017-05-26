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

// WindowsMediaPlayTo.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.PlayTo.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaPlayTo.h"
#include "WindowsMediaPlayTo_priv.h"

@implementation WMPSourceChangeRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::PlayTo::ISourceChangeRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIRandomAccessStreamWithContentType>*)stream {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::ISourceChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Stream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamWithContentType>(unmarshalledReturn.Get());
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::ISourceChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)author {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::ISourceChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Author(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)album {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::ISourceChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Album(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)genre {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::ISourceChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Genre(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::ISourceChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id /* WFDateTime* */)date {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::ISourceChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Date(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (RTObject<WSSIRandomAccessStreamReference>*)thumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::ISourceChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (id /* unsigned int */)rating {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::ISourceChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Rating(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (NSDictionary* /* NSString *, RTObject* */)properties {
    ComPtr<IMapView<HSTRING, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::ISourceChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WMPPlaybackRateChangeRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::PlayTo::IPlaybackRateChangeRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)rate {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlaybackRateChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Rate(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMPCurrentTimeChangeRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::PlayTo::ICurrentTimeChangeRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFTimeSpan*)time {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::ICurrentTimeChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Time(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

@end

@implementation WMPMuteChangeRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::PlayTo::IMuteChangeRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)mute {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IMuteChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mute(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMPVolumeChangeRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::PlayTo::IVolumeChangeRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)volume {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IVolumeChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Volume(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMPPlayToReceiver

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToReceiver> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.PlayTo.PlayToReceiver").Get(), &out));
    return [_createRtProxy<WMPPlayToReceiver>(out.Get()) retain];
}

- (EventRegistrationToken)addPlayRequestedEvent:(void (^)(WMPPlayToReceiver*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PlayRequested(Make<ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_System_Object>(handler).Get(),
                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePlayRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PlayRequested(token));
}

- (EventRegistrationToken)addPauseRequestedEvent:(void (^)(WMPPlayToReceiver*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_PauseRequested(Make<ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_System_Object>(handler).Get(),
                                     &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePauseRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PauseRequested(token));
}

- (EventRegistrationToken)addSourceChangeRequestedEvent:(void (^)(WMPPlayToReceiver*, WMPSourceChangeRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourceChangeRequested(
        Make<ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_SourceChangeRequestedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceChangeRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceChangeRequested(token));
}

- (EventRegistrationToken)addPlaybackRateChangeRequestedEvent:(void (^)(WMPPlayToReceiver*,
                                                                        WMPPlaybackRateChangeRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->add_PlaybackRateChangeRequested(
        Make<ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_PlaybackRateChangeRequestedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePlaybackRateChangeRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PlaybackRateChangeRequested(token));
}

- (EventRegistrationToken)addCurrentTimeChangeRequestedEvent:(void (^)(WMPPlayToReceiver*,
                                                                       WMPCurrentTimeChangeRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->add_CurrentTimeChangeRequested(
        Make<ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_CurrentTimeChangeRequestedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCurrentTimeChangeRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CurrentTimeChangeRequested(token));
}

- (EventRegistrationToken)addMuteChangeRequestedEvent:(void (^)(WMPPlayToReceiver*, WMPMuteChangeRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->add_MuteChangeRequested(
        Make<ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_MuteChangeRequestedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeMuteChangeRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->remove_MuteChangeRequested(token));
}

- (EventRegistrationToken)addVolumeChangeRequestedEvent:(void (^)(WMPPlayToReceiver*, WMPVolumeChangeRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->add_VolumeChangeRequested(
        Make<ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_Windows_Media_PlayTo_VolumeChangeRequestedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVolumeChangeRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VolumeChangeRequested(token));
}

- (EventRegistrationToken)addTimeUpdateRequestedEvent:(void (^)(WMPPlayToReceiver*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_TimeUpdateRequested(Make<ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_System_Object>(handler).Get(),
                                          &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTimeUpdateRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TimeUpdateRequested(token));
}

- (EventRegistrationToken)addStopRequestedEvent:(void (^)(WMPPlayToReceiver*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_StopRequested(Make<ITypedEventHandler_Windows_Media_PlayTo_PlayToReceiver_System_Object>(handler).Get(),
                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStopRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StopRequested(token));
}

- (void)notifyVolumeChange:(double)volume mute:(BOOL)mute {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyVolumeChange(volume, (boolean)mute));
}

- (void)notifyRateChange:(double)rate {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyRateChange(rate));
}

- (void)notifyLoadedMetadata {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyLoadedMetadata());
}

- (void)notifyTimeUpdate:(WFTimeSpan*)currentTime {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyTimeUpdate(*[currentTime internalStruct]));
}

- (void)notifyDurationChange:(WFTimeSpan*)duration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyDurationChange(*[duration internalStruct]));
}

- (void)notifySeeking {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->NotifySeeking());
}

- (void)notifySeeked {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->NotifySeeked());
}

- (void)notifyPaused {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyPaused());
}

- (void)notifyPlaying {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyPlaying());
}

- (void)notifyEnded {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyEnded());
}

- (void)notifyError {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyError());
}

- (void)notifyStopped {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyStopped());
}

- (NSString*)friendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->get_FriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFriendlyName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->put_FriendlyName(nsStrToHstr(value).Get()));
}

- (void)setSupportsImage:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->put_SupportsImage((boolean)value));
}

- (BOOL)supportsImage {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportsImage(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSupportsAudio:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->put_SupportsAudio((boolean)value));
}

- (BOOL)supportsAudio {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportsAudio(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSupportsVideo:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->put_SupportsVideo((boolean)value));
}

- (BOOL)supportsVideo {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportsVideo(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)startAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->StartAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)stopAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToReceiver>(self);
    THROW_NS_IF_FAILED(_comInst->StopAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WMPPlayToConnection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToConnection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPPlayToConnectionState)state {
    ABI::Windows::Media::PlayTo::PlayToConnectionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToConnection>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WMPPlayToConnectionState)unmarshalledReturn;
}

- (EventRegistrationToken)addStateChangedEvent:(void (^)(WMPPlayToConnection*, WMPPlayToConnectionStateChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_StateChanged(
        Make<ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionStateChangedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStateChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StateChanged(token));
}

- (EventRegistrationToken)addTransferredEvent:(void (^)(WMPPlayToConnection*, WMPPlayToConnectionTransferredEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_Transferred(
        Make<ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionTransferredEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTransferredEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Transferred(token));
}

- (EventRegistrationToken)addErrorEvent:(void (^)(WMPPlayToConnection*, WMPPlayToConnectionErrorEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_Error(
        Make<ITypedEventHandler_Windows_Media_PlayTo_PlayToConnection_Windows_Media_PlayTo_PlayToConnectionErrorEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeErrorEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Error(token));
}

@end

@implementation WMPPlayToSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPPlayToConnection*)connection {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToConnection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Connection(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPlayToConnection>(unmarshalledReturn.Get());
}

- (WMPPlayToSource*)next {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Next(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPlayToSource>(unmarshalledReturn.Get());
}

- (void)setNext:(WMPPlayToSource*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_Next(_getRtInterface<ABI::Windows::Media::PlayTo::IPlayToSource>(value).Get()));
}

- (void)playNext {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSource>(self);
    THROW_NS_IF_FAILED(_comInst->PlayNext());
}

- (WFUri*)preferredSourceUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSourceWithPreferredSourceUri>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreferredSourceUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setPreferredSourceUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSourceWithPreferredSourceUri>(self);
    THROW_NS_IF_FAILED(_comInst->put_PreferredSourceUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

@end

@implementation WMPPlayToConnectionStateChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToConnectionStateChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPPlayToConnectionState)previousState {
    ABI::Windows::Media::PlayTo::PlayToConnectionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToConnectionStateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousState(&unmarshalledReturn));
    return (WMPPlayToConnectionState)unmarshalledReturn;
}

- (WMPPlayToConnectionState)currentState {
    ABI::Windows::Media::PlayTo::PlayToConnectionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToConnectionStateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentState(&unmarshalledReturn));
    return (WMPPlayToConnectionState)unmarshalledReturn;
}

@end

@implementation WMPPlayToConnectionTransferredEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToConnectionTransferredEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPPlayToSource*)previousSource {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToConnectionTransferredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreviousSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPlayToSource>(unmarshalledReturn.Get());
}

- (WMPPlayToSource*)currentSource {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToConnectionTransferredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPlayToSource>(unmarshalledReturn.Get());
}

@end

@implementation WMPPlayToConnectionErrorEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToConnectionErrorEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPPlayToConnectionError)code {
    ABI::Windows::Media::PlayTo::PlayToConnectionError unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToConnectionErrorEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Code(&unmarshalledReturn));
    return (WMPPlayToConnectionError)unmarshalledReturn;
}

- (NSString*)message {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToConnectionErrorEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMPPlayToSourceSelectedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToSourceSelectedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)friendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSourceSelectedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_FriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WSSIRandomAccessStreamWithContentType>*)icon {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSourceSelectedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Icon(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamWithContentType>(unmarshalledReturn.Get());
}

- (BOOL)supportsImage {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSourceSelectedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportsImage(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)supportsAudio {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSourceSelectedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportsAudio(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)supportsVideo {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSourceSelectedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportsVideo(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMPPlayToSourceDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToSourceDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSourceDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WMPPlayToSourceRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToSourceRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)deadline {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSourceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Deadline(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)displayErrorString:(NSString*)errorString {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSourceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->DisplayErrorString(nsStrToHstr(errorString).Get()));
}

- (WMPPlayToSourceDeferral*)getDeferral {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToSourceDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSourceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPlayToSourceDeferral>(unmarshalledReturn.Get());
}

- (void)setSource:(WMPPlayToSource*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSourceRequest>(self);
    THROW_NS_IF_FAILED(_comInst->SetSource(_getRtInterface<ABI::Windows::Media::PlayTo::IPlayToSource>(value).Get()));
}

@end

@implementation WMPPlayToSourceRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToSourceRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMPPlayToSourceRequest*)sourceRequest {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToSourceRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToSourceRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPlayToSourceRequest>(unmarshalledReturn.Get());
}

@end

@implementation WMPPlayToManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::PlayTo::IPlayToManagerStatics> WMPIPlayToManagerStatics_inst() {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.PlayTo.PlayToManager").Get(), &inst));
    return inst;
}

+ (WMPPlayToManager*)getForCurrentView {
    ComPtr<ABI::Windows::Media::PlayTo::IPlayToManager> unmarshalledReturn;
    auto _comInst = WMPIPlayToManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPPlayToManager>(unmarshalledReturn.Get());
}

+ (void)showPlayToUI {
    auto _comInst = WMPIPlayToManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowPlayToUI());
}

- (EventRegistrationToken)addSourceRequestedEvent:(void (^)(WMPPlayToManager*, WMPPlayToSourceRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourceRequested(
        Make<ITypedEventHandler_Windows_Media_PlayTo_PlayToManager_Windows_Media_PlayTo_PlayToSourceRequestedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceRequested(token));
}

- (EventRegistrationToken)addSourceSelectedEvent:(void (^)(WMPPlayToManager*, WMPPlayToSourceSelectedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_SourceSelected(
        Make<ITypedEventHandler_Windows_Media_PlayTo_PlayToManager_Windows_Media_PlayTo_PlayToSourceSelectedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceSelectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceSelected(token));
}

- (void)setDefaultSourceSelection:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToManager>(self);
    THROW_NS_IF_FAILED(_comInst->put_DefaultSourceSelection((boolean)value));
}

- (BOOL)defaultSourceSelection {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::PlayTo::IPlayToManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_DefaultSourceSelection(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<
        DictionaryAdapterObj<IMapView<HSTRING, IInspectable*>,
                             DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, IInspectable*>>,
                             RTMapViewObj<HSTRING,
                                          HSTRING,
                                          IInspectable*,
                                          IInspectable*,
                                          NSString,
                                          RTObject,
                                          IMapView<HSTRING, IInspectable*>,
                                          dummyObjCCreator,
                                          dummyObjCCreator,
                                          dummyWRLCreator,
                                          dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
