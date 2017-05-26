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

// WindowsMediaCore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaCore.h"
#include "WindowsMediaCore_priv.h"

@implementation WMCIMediaSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WMCIMediaStreamDescriptor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamDescriptor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isSelected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSelected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLanguage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->put_Language(nsStrToHstr(value).Get()));
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMCIMediaCue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaCue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setStartTime:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartTime(*[value internalStruct]));
}

- (WFTimeSpan*)startTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setDuration:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->put_Duration(*[value internalStruct]));
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id(nsStrToHstr(value).Get()));
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMCISingleSelectMediaTrackList

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::ISingleSelectMediaTrackList> defaultInterface;
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

@implementation WMCIMediaTrack

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaTrack> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMCMediaTrackKind)trackKind {
    ABI::Windows::Media::Core::MediaTrackKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrackKind(&unmarshalledReturn));
    return (WMCMediaTrackKind)unmarshalledReturn;
}

- (void)setLabel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->put_Label(nsStrToHstr(value).Get()));
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMCAudioStreamDescriptor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IAudioStreamDescriptor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Core::IAudioStreamDescriptorFactory> WMCIAudioStreamDescriptorFactory_inst() {
    ComPtr<ABI::Windows::Media::Core::IAudioStreamDescriptorFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Core.AudioStreamDescriptor").Get(), &inst));
    return inst;
}

+ (WMCAudioStreamDescriptor*)make:(WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::Core::IAudioStreamDescriptor> unmarshalledReturn;
    auto _comInst = WMCIAudioStreamDescriptorFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(encodingProperties).Get(),
                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMCAudioStreamDescriptor>(unmarshalledReturn.Get()) retain];
}

- (WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IAudioStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (BOOL)isSelected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSelected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLanguage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->put_Language(nsStrToHstr(value).Get()));
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLeadingEncoderPadding:(id /* unsigned int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IAudioStreamDescriptor2>(self);
    THROW_NS_IF_FAILED(_comInst->put_LeadingEncoderPadding(BuildNullable<unsigned int>(value)));
}

- (id /* unsigned int */)leadingEncoderPadding {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IAudioStreamDescriptor2>(self);
    THROW_NS_IF_FAILED(_comInst->get_LeadingEncoderPadding(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (void)setTrailingEncoderPadding:(id /* unsigned int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IAudioStreamDescriptor2>(self);
    THROW_NS_IF_FAILED(_comInst->put_TrailingEncoderPadding(BuildNullable<unsigned int>(value)));
}

- (id /* unsigned int */)trailingEncoderPadding {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IAudioStreamDescriptor2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrailingEncoderPadding(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

@end

@implementation WMCVideoStreamDescriptor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IVideoStreamDescriptor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Core::IVideoStreamDescriptorFactory> WMCIVideoStreamDescriptorFactory_inst() {
    ComPtr<ABI::Windows::Media::Core::IVideoStreamDescriptorFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Core.VideoStreamDescriptor").Get(), &inst));
    return inst;
}

+ (WMCVideoStreamDescriptor*)make:(WMMVideoEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::Core::IVideoStreamDescriptor> unmarshalledReturn;
    auto _comInst = WMCIVideoStreamDescriptorFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties>(encodingProperties).Get(),
                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMCVideoStreamDescriptor>(unmarshalledReturn.Get()) retain];
}

- (WMMVideoEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IVideoStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMVideoEncodingProperties>(unmarshalledReturn.Get());
}

- (BOOL)isSelected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSelected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLanguage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->put_Language(nsStrToHstr(value).Get()));
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMCMediaStreamSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceFactory> WMCIMediaStreamSourceFactory_inst() {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Core.MediaStreamSource").Get(), &inst));
    return inst;
}

+ (WMCMediaStreamSource*)makeFromDescriptor:(RTObject<WMCIMediaStreamDescriptor>*)descriptor {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSource> unmarshalledReturn;
    auto _comInst = WMCIMediaStreamSourceFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromDescriptor(_getRtInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(descriptor).Get(),
                                                      unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMCMediaStreamSource>(unmarshalledReturn.Get()) retain];
}

+ (WMCMediaStreamSource*)makeFromDescriptors:(RTObject<WMCIMediaStreamDescriptor>*)descriptor
                                 descriptor2:(RTObject<WMCIMediaStreamDescriptor>*)descriptor2 {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSource> unmarshalledReturn;
    auto _comInst = WMCIMediaStreamSourceFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromDescriptors(_getRtInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(descriptor).Get(),
                                        _getRtInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(descriptor2).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMCMediaStreamSource>(unmarshalledReturn.Get()) retain];
}

- (EventRegistrationToken)addClosedEvent:(void (^)(WMCMediaStreamSource*, WMCMediaStreamSourceClosedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_Closed(
        Make<ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceClosedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Closed(token));
}

- (EventRegistrationToken)addStartingEvent:(void (^)(WMCMediaStreamSource*, WMCMediaStreamSourceStartingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_Starting(
        Make<ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceStartingEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStartingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Starting(token));
}

- (EventRegistrationToken)addPausedEvent:(void (^)(WMCMediaStreamSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_Paused(Make<ITypedEventHandler_Windows_Media_Core_MediaStreamSource_System_Object>(handler).Get(),
                                            &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePausedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Paused(token));
}

- (EventRegistrationToken)addSampleRequestedEvent:(void (^)(WMCMediaStreamSource*, WMCMediaStreamSourceSampleRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_SampleRequested(
        Make<ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSampleRequestedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSampleRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SampleRequested(token));
}

- (EventRegistrationToken)addSwitchStreamsRequestedEvent:(void (^)(WMCMediaStreamSource*,
                                                                   WMCMediaStreamSourceSwitchStreamsRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_SwitchStreamsRequested(
        Make<ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSwitchStreamsRequestedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSwitchStreamsRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SwitchStreamsRequested(token));
}

- (void)notifyError:(WMCMediaStreamSourceErrorStatus)errorStatus {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyError((ABI::Windows::Media::Core::MediaStreamSourceErrorStatus)errorStatus));
}

- (void)addStreamDescriptor:(RTObject<WMCIMediaStreamDescriptor>*)descriptor {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->AddStreamDescriptor(_getRtInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(descriptor).Get()));
}

- (void)setMediaProtectionManager:(WMPMediaProtectionManager*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_MediaProtectionManager(_getRtInterface<ABI::Windows::Media::Protection::IMediaProtectionManager>(value).Get()));
}

- (WMPMediaProtectionManager*)mediaProtectionManager {
    ComPtr<ABI::Windows::Media::Protection::IMediaProtectionManager> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaProtectionManager(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaProtectionManager>(unmarshalledReturn.Get());
}

- (void)setDuration:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_Duration(*[value internalStruct]));
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setCanSeek:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanSeek((boolean)value));
}

- (BOOL)canSeek {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanSeek(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setBufferTime:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_BufferTime(*[value internalStruct]));
}

- (WFTimeSpan*)bufferTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_BufferTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setBufferedRange:(WFTimeSpan*)startOffset endOffset:(WFTimeSpan*)endOffset {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->SetBufferedRange(*[startOffset internalStruct], *[endOffset internalStruct]));
}

- (WSFMusicProperties*)musicProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IMusicProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_MusicProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFMusicProperties>(unmarshalledReturn.Get());
}

- (WSFVideoProperties*)videoProperties {
    ComPtr<ABI::Windows::Storage::FileProperties::IVideoProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSFVideoProperties>(unmarshalledReturn.Get());
}

- (void)setThumbnail:(RTObject<WSSIRandomAccessStreamReference>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_Thumbnail(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (RTObject<WSSIRandomAccessStreamReference>*)thumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)addProtectionKey:(RTObject<WMCIMediaStreamDescriptor>*)streamDescriptor
           keyIdentifier:(NSArray* /* uint8_t */)keyIdentifier
             licenseData:(NSArray* /* uint8_t */)licenseData {
    UINT32 __keyIdentifier_ArrayLen = 0;
    bool __keyIdentifier_IsTemp = false;
    uint8_t* __keyIdentifier_Array = NULL;
    if (!ConvertToCArray<uint8_t>(keyIdentifier, &__keyIdentifier_ArrayLen, &__keyIdentifier_Array, &__keyIdentifier_IsTemp))
        assert(0);
    UINT32 __licenseData_ArrayLen = 0;
    bool __licenseData_IsTemp = false;
    uint8_t* __licenseData_Array = NULL;
    if (!ConvertToCArray<uint8_t>(licenseData, &__licenseData_ArrayLen, &__licenseData_Array, &__licenseData_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddProtectionKey(_getRtInterface<ABI::Windows::Media::Core::IMediaStreamDescriptor>(streamDescriptor).Get(),
                                   __keyIdentifier_ArrayLen,
                                   __keyIdentifier_Array,
                                   __licenseData_ArrayLen,
                                   __licenseData_Array));
    if (__keyIdentifier_IsTemp)
        CoTaskMemFree(__keyIdentifier_Array);
    if (__licenseData_IsTemp)
        CoTaskMemFree(__licenseData_Array);
}

- (EventRegistrationToken)addSampleRenderedEvent:(void (^)(WMCMediaStreamSource*, WMCMediaStreamSourceSampleRenderedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource2>(self);
    THROW_NS_IF_FAILED(_comInst->add_SampleRendered(
        Make<ITypedEventHandler_Windows_Media_Core_MediaStreamSource_Windows_Media_Core_MediaStreamSourceSampleRenderedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSampleRenderedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSource2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SampleRendered(token));
}

@end

@implementation WMCMediaStreamSourceClosedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceClosedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCMediaStreamSourceClosedRequest*)request {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceClosedRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceClosedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaStreamSourceClosedRequest>(unmarshalledReturn.Get());
}

@end

@implementation WMCMediaStreamSourceStartingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceStartingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCMediaStreamSourceStartingRequest*)request {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceStartingRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceStartingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaStreamSourceStartingRequest>(unmarshalledReturn.Get());
}

@end

@implementation WMCMediaStreamSourceSampleRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceSampleRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCMediaStreamSourceSampleRequest*)request {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceSampleRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceSampleRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaStreamSourceSampleRequest>(unmarshalledReturn.Get());
}

@end

@implementation WMCMediaStreamSourceSwitchStreamsRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCMediaStreamSourceSwitchStreamsRequest*)request {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaStreamSourceSwitchStreamsRequest>(unmarshalledReturn.Get());
}

@end

@implementation WMCMediaStreamSourceSampleRenderedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceSampleRenderedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFTimeSpan*)sampleLag {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceSampleRenderedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SampleLag(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

@end

@implementation WMCMediaStreamSamplePropertySet {
    RTMapObj<GUID,
             GUID,
             IInspectable*,
             IInspectable*,
             WFGUID,
             RTObject,
             IMap<GUID, IInspectable*>,
             dummyObjCCreator,
             dummyObjCCreator,
             dummyWRLCreator,
             dummyWRLCreator>
        _map;
}
INTEROP_IMPL_MAP(self.comObj, RTProxiedNSMutableDictionary_WFGUID_RTObject, GUID, GUID, IInspectable*, IInspectable*, WFGUID, RTObject)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IMap<GUID, IInspectable*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WMCMediaStreamSample

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSample> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::Core::IMediaStreamSampleStatics> WMCIMediaStreamSampleStatics_inst() {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSampleStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Core.MediaStreamSample").Get(), &inst));
    return inst;
}

+ (WMCMediaStreamSample*)createFromBuffer:(RTObject<WSSIBuffer>*)buffer timestamp:(WFTimeSpan*)timestamp {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSample> unmarshalledReturn;
    auto _comInst = WMCIMediaStreamSampleStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(),
                                                  *[timestamp internalStruct],
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaStreamSample>(unmarshalledReturn.Get());
}

+ (void)createFromStreamAsync:(RTObject<WSSIInputStream>*)stream
                        count:(unsigned int)count
                    timestamp:(WFTimeSpan*)timestamp
                      success:(void (^)(WMCMediaStreamSample*))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Core::MediaStreamSample*>> unmarshalledReturn;
    auto _comInst = WMCIMediaStreamSampleStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(stream).Get(),
                                                       count,
                                                       *[timestamp internalStruct],
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Core::MediaStreamSample*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Core::MediaStreamSample*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Core::IMediaStreamSample> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMCMediaStreamSample>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (EventRegistrationToken)addProcessedEvent:(void (^)(WMCMediaStreamSample*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSample>(self);
    THROW_NS_IF_FAILED(_comInst->add_Processed(Make<ITypedEventHandler_Windows_Media_Core_MediaStreamSample_System_Object>(handler).Get(),
                                               &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeProcessedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSample>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Processed(token));
}

- (WSSBuffer*)buffer {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSample>(self);
    THROW_NS_IF_FAILED(_comInst->get_Buffer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSBuffer>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)timestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSample>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WMCMediaStreamSamplePropertySet*)extendedProperties {
    ComPtr<IMap<GUID, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSample>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaStreamSamplePropertySet>(unmarshalledReturn.Get());
}

- (WMCMediaStreamSampleProtectionProperties*)protection {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSampleProtectionProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSample>(self);
    THROW_NS_IF_FAILED(_comInst->get_Protection(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaStreamSampleProtectionProperties>(unmarshalledReturn.Get());
}

- (void)setDecodeTimestamp:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSample>(self);
    THROW_NS_IF_FAILED(_comInst->put_DecodeTimestamp(*[value internalStruct]));
}

- (WFTimeSpan*)decodeTimestamp {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSample>(self);
    THROW_NS_IF_FAILED(_comInst->get_DecodeTimestamp(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setDuration:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSample>(self);
    THROW_NS_IF_FAILED(_comInst->put_Duration(*[value internalStruct]));
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSample>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setKeyFrame:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSample>(self);
    THROW_NS_IF_FAILED(_comInst->put_KeyFrame((boolean)value));
}

- (BOOL)keyFrame {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSample>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyFrame(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setDiscontinuous:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSample>(self);
    THROW_NS_IF_FAILED(_comInst->put_Discontinuous((boolean)value));
}

- (BOOL)discontinuous {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSample>(self);
    THROW_NS_IF_FAILED(_comInst->get_Discontinuous(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMCMediaStreamSampleProtectionProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSampleProtectionProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setKeyIdentifier:(NSArray* /* uint8_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSampleProtectionProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SetKeyIdentifier(__value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)getKeyIdentifier:(NSArray* /* uint8_t */*)value {
    UINT32 __value_ArrayLen = 0;
    uint8_t* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSampleProtectionProperties>(self);
    THROW_NS_IF_FAILED(_comInst->GetKeyIdentifier(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_UInt8_create(__value_ArrayLen, __value_Array);
}

- (void)setInitializationVector:(NSArray* /* uint8_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSampleProtectionProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SetInitializationVector(__value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)getInitializationVector:(NSArray* /* uint8_t */*)value {
    UINT32 __value_ArrayLen = 0;
    uint8_t* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSampleProtectionProperties>(self);
    THROW_NS_IF_FAILED(_comInst->GetInitializationVector(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_UInt8_create(__value_ArrayLen, __value_Array);
}

- (void)setSubSampleMapping:(NSArray* /* uint8_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSampleProtectionProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SetSubSampleMapping(__value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)getSubSampleMapping:(NSArray* /* uint8_t */*)value {
    UINT32 __value_ArrayLen = 0;
    uint8_t* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSampleProtectionProperties>(self);
    THROW_NS_IF_FAILED(_comInst->GetSubSampleMapping(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_UInt8_create(__value_ArrayLen, __value_Array);
}

@end

@implementation WMCMediaStreamSourceClosedRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceClosedRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCMediaStreamSourceClosedReason)reason {
    ABI::Windows::Media::Core::MediaStreamSourceClosedReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceClosedRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reason(&unmarshalledReturn));
    return (WMCMediaStreamSourceClosedReason)unmarshalledReturn;
}

@end

@implementation WMCMediaStreamSourceStartingRequestDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceStartingRequestDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceStartingRequestDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WMCMediaStreamSourceStartingRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceStartingRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* WFTimeSpan* */)startPosition {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceStartingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartPosition(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (WMCMediaStreamSourceStartingRequestDeferral*)getDeferral {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceStartingRequestDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceStartingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaStreamSourceStartingRequestDeferral>(unmarshalledReturn.Get());
}

- (void)setActualStartPosition:(WFTimeSpan*)position {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceStartingRequest>(self);
    THROW_NS_IF_FAILED(_comInst->SetActualStartPosition(*[position internalStruct]));
}

@end

@implementation WMCMediaStreamSourceSampleRequestDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceSampleRequestDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceSampleRequestDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WMCMediaStreamSourceSampleRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceSampleRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WMCIMediaStreamDescriptor>*)streamDescriptor {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamDescriptor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceSampleRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_StreamDescriptor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCIMediaStreamDescriptor>(unmarshalledReturn.Get());
}

- (WMCMediaStreamSourceSampleRequestDeferral*)getDeferral {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceSampleRequestDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceSampleRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaStreamSourceSampleRequestDeferral>(unmarshalledReturn.Get());
}

- (void)setSample:(WMCMediaStreamSample*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceSampleRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Sample(_getRtInterface<ABI::Windows::Media::Core::IMediaStreamSample>(value).Get()));
}

- (WMCMediaStreamSample*)sample {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSample> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceSampleRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Sample(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaStreamSample>(unmarshalledReturn.Get());
}

- (void)reportSampleProgress:(unsigned int)progress {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceSampleRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportSampleProgress(progress));
}

@end

@implementation WMCMediaStreamSourceSwitchStreamsRequestDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequestDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequestDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WMCMediaStreamSourceSwitchStreamsRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WMCIMediaStreamDescriptor>*)oldStreamDescriptor {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamDescriptor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldStreamDescriptor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCIMediaStreamDescriptor>(unmarshalledReturn.Get());
}

- (RTObject<WMCIMediaStreamDescriptor>*)newStreamDescriptor __attribute__((ns_returns_not_retained)) {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamDescriptor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewStreamDescriptor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCIMediaStreamDescriptor>(unmarshalledReturn.Get());
}

- (WMCMediaStreamSourceSwitchStreamsRequestDeferral*)getDeferral {
    ComPtr<ABI::Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequestDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaStreamSourceSwitchStreamsRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaStreamSourceSwitchStreamsRequestDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WMCMseStreamSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMseStreamSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Core.MseStreamSource").Get(), &out));
    return [_createRtProxy<WMCMseStreamSource>(out.Get()) retain];
}

ComPtr<ABI::Windows::Media::Core::IMseStreamSourceStatics> WMCIMseStreamSourceStatics_inst() {
    ComPtr<ABI::Windows::Media::Core::IMseStreamSourceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Core.MseStreamSource").Get(), &inst));
    return inst;
}

+ (BOOL)isContentTypeSupported:(NSString*)contentType {
    boolean unmarshalledReturn;
    auto _comInst = WMCIMseStreamSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsContentTypeSupported(nsStrToHstr(contentType).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addOpenedEvent:(void (^)(WMCMseStreamSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_Opened(Make<ITypedEventHandler_Windows_Media_Core_MseStreamSource_System_Object>(handler).Get(),
                                            &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOpenedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Opened(token));
}

- (EventRegistrationToken)addEndedEvent:(void (^)(WMCMseStreamSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseStreamSource>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Ended(Make<ITypedEventHandler_Windows_Media_Core_MseStreamSource_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeEndedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Ended(token));
}

- (EventRegistrationToken)addClosedEvent:(void (^)(WMCMseStreamSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_Closed(Make<ITypedEventHandler_Windows_Media_Core_MseStreamSource_System_Object>(handler).Get(),
                                            &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Closed(token));
}

- (WMCMseSourceBufferList*)sourceBuffers {
    ComPtr<ABI::Windows::Media::Core::IMseSourceBufferList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceBuffers(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMseSourceBufferList>(unmarshalledReturn.Get());
}

- (WMCMseSourceBufferList*)activeSourceBuffers {
    ComPtr<ABI::Windows::Media::Core::IMseSourceBufferList> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActiveSourceBuffers(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMseSourceBufferList>(unmarshalledReturn.Get());
}

- (WMCMseReadyState)readyState {
    ABI::Windows::Media::Core::MseReadyState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReadyState(&unmarshalledReturn));
    return (WMCMseReadyState)unmarshalledReturn;
}

- (id /* WFTimeSpan* */)duration {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setDuration:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_Duration(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (WMCMseSourceBuffer*)addSourceBuffer:(NSString*)mimeType {
    ComPtr<ABI::Windows::Media::Core::IMseSourceBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->AddSourceBuffer(nsStrToHstr(mimeType).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMseSourceBuffer>(unmarshalledReturn.Get());
}

- (void)removeSourceBuffer:(WMCMseSourceBuffer*)buffer {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveSourceBuffer(_getRtInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(buffer).Get()));
}

- (void)endOfStream:(WMCMseEndOfStreamStatus)status {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseStreamSource>(self);
    THROW_NS_IF_FAILED(_comInst->EndOfStream((ABI::Windows::Media::Core::MseEndOfStreamStatus)status));
}

@end

@implementation WMCMseSourceBufferList

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMseSourceBufferList> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addSourceBufferAddedEvent:(void (^)(WMCMseSourceBufferList*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBufferList>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_SourceBufferAdded(Make<ITypedEventHandler_Windows_Media_Core_MseSourceBufferList_System_Object>(handler).Get(),
                                        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceBufferAddedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBufferList>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceBufferAdded(token));
}

- (EventRegistrationToken)addSourceBufferRemovedEvent:(void (^)(WMCMseSourceBufferList*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBufferList>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_SourceBufferRemoved(Make<ITypedEventHandler_Windows_Media_Core_MseSourceBufferList_System_Object>(handler).Get(),
                                          &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSourceBufferRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBufferList>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SourceBufferRemoved(token));
}

- (NSArray* /* WMCMseSourceBuffer* */)buffers {
    ComPtr<IVectorView<ABI::Windows::Media::Core::MseSourceBuffer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBufferList>(self);
    THROW_NS_IF_FAILED(_comInst->get_Buffers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMCMseSourceBuffer_create(unmarshalledReturn.Get());
}

@end

@implementation WMCMseSourceBuffer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMseSourceBuffer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addUpdateStartingEvent:(void (^)(WMCMseSourceBuffer*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_UpdateStarting(Make<ITypedEventHandler_Windows_Media_Core_MseSourceBuffer_System_Object>(handler).Get(),
                                     &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUpdateStartingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UpdateStarting(token));
}

- (EventRegistrationToken)addUpdatedEvent:(void (^)(WMCMseSourceBuffer*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->add_Updated(Make<ITypedEventHandler_Windows_Media_Core_MseSourceBuffer_System_Object>(handler).Get(),
                                             &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Updated(token));
}

- (EventRegistrationToken)addUpdateEndedEvent:(void (^)(WMCMseSourceBuffer*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->add_UpdateEnded(Make<ITypedEventHandler_Windows_Media_Core_MseSourceBuffer_System_Object>(handler).Get(),
                                                 &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUpdateEndedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UpdateEnded(token));
}

- (EventRegistrationToken)addErrorOccurredEvent:(void (^)(WMCMseSourceBuffer*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->add_ErrorOccurred(Make<ITypedEventHandler_Windows_Media_Core_MseSourceBuffer_System_Object>(handler).Get(),
                                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeErrorOccurredEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ErrorOccurred(token));
}

- (EventRegistrationToken)addAbortedEvent:(void (^)(WMCMseSourceBuffer*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->add_Aborted(Make<ITypedEventHandler_Windows_Media_Core_MseSourceBuffer_System_Object>(handler).Get(),
                                             &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAbortedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Aborted(token));
}

- (WMCMseAppendMode)mode {
    ABI::Windows::Media::Core::MseAppendMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WMCMseAppendMode)unmarshalledReturn;
}

- (void)setMode:(WMCMseAppendMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mode((ABI::Windows::Media::Core::MseAppendMode)value));
}

- (BOOL)isUpdating {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsUpdating(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WMCMseTimeRange* */)buffered {
    ComPtr<IVectorView<ABI::Windows::Media::Core::MseTimeRange>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Buffered(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMCMseTimeRange_create(unmarshalledReturn.Get());
}

- (WFTimeSpan*)timestampOffset {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimestampOffset(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setTimestampOffset:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->put_TimestampOffset(*[value internalStruct]));
}

- (WFTimeSpan*)appendWindowStart {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppendWindowStart(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setAppendWindowStart:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->put_AppendWindowStart(*[value internalStruct]));
}

- (id /* WFTimeSpan* */)appendWindowEnd {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppendWindowEnd(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setAppendWindowEnd:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->put_AppendWindowEnd(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (void)appendBuffer:(RTObject<WSSIBuffer>*)buffer {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->AppendBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get()));
}

- (void)appendStream:(RTObject<WSSIInputStream>*)stream {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->AppendStream(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(stream).Get()));
}

- (void)appendStreamMaxSize:(RTObject<WSSIInputStream>*)stream maxSize:(uint64_t)maxSize {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->AppendStreamMaxSize(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(stream).Get(), maxSize));
}

- (void)abort {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->Abort());
}

- (void)remove:(WFTimeSpan*)start end:(id /* WFTimeSpan* */)end {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMseSourceBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->Remove(*[start internalStruct], BuildNullable<ABI::Windows::Foundation::TimeSpan>(end)));
}

@end

@implementation WMCHighDynamicRangeControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IHighDynamicRangeControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IHighDynamicRangeControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Enabled((boolean)value));
}

- (BOOL)enabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IHighDynamicRangeControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Enabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMCSceneAnalysisEffect

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::ISceneAnalysisEffect> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCHighDynamicRangeControl*)highDynamicRangeAnalyzer {
    ComPtr<ABI::Windows::Media::Core::IHighDynamicRangeControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ISceneAnalysisEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_HighDynamicRangeAnalyzer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCHighDynamicRangeControl>(unmarshalledReturn.Get());
}

- (void)setDesiredAnalysisInterval:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ISceneAnalysisEffect>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredAnalysisInterval(*[value internalStruct]));
}

- (WFTimeSpan*)desiredAnalysisInterval {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ISceneAnalysisEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredAnalysisInterval(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (EventRegistrationToken)addSceneAnalyzedEvent:(void (^)(WMCSceneAnalysisEffect*, WMCSceneAnalyzedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ISceneAnalysisEffect>(self);
    THROW_NS_IF_FAILED(_comInst->add_SceneAnalyzed(
        Make<ITypedEventHandler_Windows_Media_Core_SceneAnalysisEffect_Windows_Media_Core_SceneAnalyzedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSceneAnalyzedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ISceneAnalysisEffect>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SceneAnalyzed(cookie));
}

- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtension>(self);
    THROW_NS_IF_FAILED(_comInst->SetProperties(_getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get()));
}

@end

@implementation WMCSceneAnalyzedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::ISceneAnalyzedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCSceneAnalysisEffectFrame*)resultFrame {
    ComPtr<ABI::Windows::Media::Core::ISceneAnalysisEffectFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ISceneAnalyzedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResultFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCSceneAnalysisEffectFrame>(unmarshalledReturn.Get());
}

@end

@implementation WMCHighDynamicRangeOutput

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IHighDynamicRangeOutput> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)certainty {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IHighDynamicRangeOutput>(self);
    THROW_NS_IF_FAILED(_comInst->get_Certainty(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSArray* /* WMDCFrameController* */)frameControllers {
    ComPtr<IVectorView<ABI::Windows::Media::Devices::Core::FrameController*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IHighDynamicRangeOutput>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameControllers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMDCFrameController_create(unmarshalledReturn.Get());
}

@end

@implementation WMCSceneAnalysisEffectFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::ISceneAnalysisEffectFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCCapturedFrameControlValues*)frameControlValues {
    ComPtr<ABI::Windows::Media::Capture::ICapturedFrameControlValues> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ISceneAnalysisEffectFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameControlValues(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCCapturedFrameControlValues>(unmarshalledReturn.Get());
}

- (WMCHighDynamicRangeOutput*)highDynamicRange {
    ComPtr<ABI::Windows::Media::Core::IHighDynamicRangeOutput> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ISceneAnalysisEffectFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_HighDynamicRange(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCHighDynamicRangeOutput>(unmarshalledReturn.Get());
}

- (NSString*)type {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isReadOnly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReadOnly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setRelativeTime:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_RelativeTime(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (id /* WFTimeSpan* */)relativeTime {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_RelativeTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setSystemRelativeTime:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_SystemRelativeTime(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (id /* WFTimeSpan* */)systemRelativeTime {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemRelativeTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setDuration:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_Duration(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (id /* WFTimeSpan* */)duration {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setIsDiscontinuous:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsDiscontinuous((boolean)value));
}

- (BOOL)isDiscontinuous {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDiscontinuous(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WFCIPropertySet>*)extendedProperties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMCSceneAnalysisEffectDefinition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IVideoEffectDefinition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Core.SceneAnalysisEffectDefinition").Get(), &out));
    return [_createRtProxy<WMCSceneAnalysisEffectDefinition>(out.Get()) retain];
}

- (NSString*)activatableClassId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatableClassId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

@end

@implementation WMCFaceDetectionEffectFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IFaceDetectionEffectFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WMFDetectedFace* */)detectedFaces {
    ComPtr<IVectorView<ABI::Windows::Media::FaceAnalysis::DetectedFace*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IFaceDetectionEffectFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_DetectedFaces(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMFDetectedFace_create(unmarshalledReturn.Get());
}

- (NSString*)type {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isReadOnly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReadOnly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setRelativeTime:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_RelativeTime(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (id /* WFTimeSpan* */)relativeTime {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_RelativeTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setSystemRelativeTime:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_SystemRelativeTime(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (id /* WFTimeSpan* */)systemRelativeTime {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemRelativeTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setDuration:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_Duration(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (id /* WFTimeSpan* */)duration {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setIsDiscontinuous:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsDiscontinuous((boolean)value));
}

- (BOOL)isDiscontinuous {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDiscontinuous(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WFCIPropertySet>*)extendedProperties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMCFaceDetectedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IFaceDetectedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCFaceDetectionEffectFrame*)resultFrame {
    ComPtr<ABI::Windows::Media::Core::IFaceDetectionEffectFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IFaceDetectedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResultFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFaceDetectionEffectFrame>(unmarshalledReturn.Get());
}

@end

@implementation WMCFaceDetectionEffect

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IFaceDetectionEffect> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IFaceDetectionEffect>(self);
    THROW_NS_IF_FAILED(_comInst->put_Enabled((boolean)value));
}

- (BOOL)enabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IFaceDetectionEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_Enabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setDesiredDetectionInterval:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IFaceDetectionEffect>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredDetectionInterval(*[value internalStruct]));
}

- (WFTimeSpan*)desiredDetectionInterval {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IFaceDetectionEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredDetectionInterval(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (EventRegistrationToken)addFaceDetectedEvent:(void (^)(WMCFaceDetectionEffect*, WMCFaceDetectedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IFaceDetectionEffect>(self);
    THROW_NS_IF_FAILED(_comInst->add_FaceDetected(
        Make<ITypedEventHandler_Windows_Media_Core_FaceDetectionEffect_Windows_Media_Core_FaceDetectedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeFaceDetectedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IFaceDetectionEffect>(self);
    THROW_NS_IF_FAILED(_comInst->remove_FaceDetected(cookie));
}

- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtension>(self);
    THROW_NS_IF_FAILED(_comInst->SetProperties(_getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get()));
}

@end

@implementation WMCFaceDetectionEffectDefinition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IVideoEffectDefinition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Core.FaceDetectionEffectDefinition").Get(), &out));
    return [_createRtProxy<WMCFaceDetectionEffectDefinition>(out.Get()) retain];
}

- (NSString*)activatableClassId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatableClassId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

- (void)setDetectionMode:(WMCFaceDetectionMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IFaceDetectionEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_DetectionMode((ABI::Windows::Media::Core::FaceDetectionMode)value));
}

- (WMCFaceDetectionMode)detectionMode {
    ABI::Windows::Media::Core::FaceDetectionMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IFaceDetectionEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_DetectionMode(&unmarshalledReturn));
    return (WMCFaceDetectionMode)unmarshalledReturn;
}

- (void)setSynchronousDetectionEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IFaceDetectionEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_SynchronousDetectionEnabled((boolean)value));
}

- (BOOL)synchronousDetectionEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IFaceDetectionEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_SynchronousDetectionEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMCVideoStabilizationEffectEnabledChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IVideoStabilizationEffectEnabledChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCVideoStabilizationEffectEnabledChangedReason)reason {
    ABI::Windows::Media::Core::VideoStabilizationEffectEnabledChangedReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IVideoStabilizationEffectEnabledChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reason(&unmarshalledReturn));
    return (WMCVideoStabilizationEffectEnabledChangedReason)unmarshalledReturn;
}

@end

@implementation WMCVideoStabilizationEffect

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IVideoStabilizationEffect> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IVideoStabilizationEffect>(self);
    THROW_NS_IF_FAILED(_comInst->put_Enabled((boolean)value));
}

- (BOOL)enabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IVideoStabilizationEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_Enabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addEnabledChangedEvent:(void (^)(WMCVideoStabilizationEffect*,
                                                           WMCVideoStabilizationEffectEnabledChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IVideoStabilizationEffect>(self);
    THROW_NS_IF_FAILED(_comInst->add_EnabledChanged(
        Make<
            ITypedEventHandler_Windows_Media_Core_VideoStabilizationEffect_Windows_Media_Core_VideoStabilizationEffectEnabledChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeEnabledChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IVideoStabilizationEffect>(self);
    THROW_NS_IF_FAILED(_comInst->remove_EnabledChanged(cookie));
}

- (WMCVideoStreamConfiguration*)getRecommendedStreamConfiguration:(WMDVideoDeviceController*)controller
                                                desiredProperties:(WMMVideoEncodingProperties*)desiredProperties {
    ComPtr<ABI::Windows::Media::Capture::IVideoStreamConfiguration> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IVideoStabilizationEffect>(self);
    THROW_NS_IF_FAILED(_comInst->GetRecommendedStreamConfiguration(
        _getRtInterface<ABI::Windows::Media::Devices::IVideoDeviceController>(controller).Get(),
        _getRtInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties>(desiredProperties).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCVideoStreamConfiguration>(unmarshalledReturn.Get());
}

- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtension>(self);
    THROW_NS_IF_FAILED(_comInst->SetProperties(_getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get()));
}

@end

@implementation WMCVideoStabilizationEffectDefinition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IVideoEffectDefinition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Core.VideoStabilizationEffectDefinition").Get(),
                                              &out));
    return [_createRtProxy<WMCVideoStabilizationEffectDefinition>(out.Get()) retain];
}

- (NSString*)activatableClassId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatableClassId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

@end

@implementation WMCMediaSourceError

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaSourceError> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (HRESULT)extendedError {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaSourceError>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedError(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WMCMediaSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaSource2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::Core::IMediaSourceStatics2> WMCIMediaSourceStatics2_inst() {
    ComPtr<ABI::Windows::Media::Core::IMediaSourceStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Core.MediaSource").Get(), &inst));
    return inst;
}

+ (WMCMediaSource*)createFromMediaBinder:(WMCMediaBinder*)binder {
    ComPtr<ABI::Windows::Media::Core::IMediaSource2> unmarshalledReturn;
    auto _comInst = WMCIMediaSourceStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromMediaBinder(_getRtInterface<ABI::Windows::Media::Core::IMediaBinder>(binder).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaSource>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Media::Core::IMediaSourceStatics> WMCIMediaSourceStatics_inst() {
    ComPtr<ABI::Windows::Media::Core::IMediaSourceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Core.MediaSource").Get(), &inst));
    return inst;
}

+ (WMCMediaSource*)createFromAdaptiveMediaSource:(WMSAAdaptiveMediaSource*)mediaSource {
    ComPtr<ABI::Windows::Media::Core::IMediaSource2> unmarshalledReturn;
    auto _comInst = WMCIMediaSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromAdaptiveMediaSource(
        _getRtInterface<ABI::Windows::Media::Streaming::Adaptive::IAdaptiveMediaSource>(mediaSource).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaSource>(unmarshalledReturn.Get());
}

+ (WMCMediaSource*)createFromMediaStreamSource:(WMCMediaStreamSource*)mediaSource {
    ComPtr<ABI::Windows::Media::Core::IMediaSource2> unmarshalledReturn;
    auto _comInst = WMCIMediaSourceStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromMediaStreamSource(_getRtInterface<ABI::Windows::Media::Core::IMediaStreamSource>(mediaSource).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaSource>(unmarshalledReturn.Get());
}

+ (WMCMediaSource*)createFromMseStreamSource:(WMCMseStreamSource*)mediaSource {
    ComPtr<ABI::Windows::Media::Core::IMediaSource2> unmarshalledReturn;
    auto _comInst = WMCIMediaSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromMseStreamSource(_getRtInterface<ABI::Windows::Media::Core::IMseStreamSource>(mediaSource).Get(),
                                                           unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaSource>(unmarshalledReturn.Get());
}

+ (WMCMediaSource*)createFromIMediaSource:(RTObject<WMCIMediaSource>*)mediaSource {
    ComPtr<ABI::Windows::Media::Core::IMediaSource2> unmarshalledReturn;
    auto _comInst = WMCIMediaSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromIMediaSource(_getRtInterface<ABI::Windows::Media::Core::IMediaSource>(mediaSource).Get(),
                                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaSource>(unmarshalledReturn.Get());
}

+ (WMCMediaSource*)createFromStorageFile:(RTObject<WSIStorageFile>*)file {
    ComPtr<ABI::Windows::Media::Core::IMediaSource2> unmarshalledReturn;
    auto _comInst = WMCIMediaSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromStorageFile(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaSource>(unmarshalledReturn.Get());
}

+ (WMCMediaSource*)createFromStream:(RTObject<WSSIRandomAccessStream>*)stream contentType:(NSString*)contentType {
    ComPtr<ABI::Windows::Media::Core::IMediaSource2> unmarshalledReturn;
    auto _comInst = WMCIMediaSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromStream(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(stream).Get(),
                                                  nsStrToHstr(contentType).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaSource>(unmarshalledReturn.Get());
}

+ (WMCMediaSource*)createFromStreamReference:(RTObject<WSSIRandomAccessStreamReference>*)stream contentType:(NSString*)contentType {
    ComPtr<ABI::Windows::Media::Core::IMediaSource2> unmarshalledReturn;
    auto _comInst = WMCIMediaSourceStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromStreamReference(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(stream).Get(),
                                            nsStrToHstr(contentType).Get(),
                                            unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaSource>(unmarshalledReturn.Get());
}

+ (WMCMediaSource*)createFromUri:(WFUri*)uri {
    ComPtr<ABI::Windows::Media::Core::IMediaSource2> unmarshalledReturn;
    auto _comInst = WMCIMediaSourceStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaSource>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addOpenOperationCompletedEvent:(void (^)(WMCMediaSource*,
                                                                   WMCMediaSourceOpenOperationCompletedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaSource2>(self);
    THROW_NS_IF_FAILED(_comInst->add_OpenOperationCompleted(
        Make<ITypedEventHandler_Windows_Media_Core_MediaSource_Windows_Media_Core_MediaSourceOpenOperationCompletedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOpenOperationCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaSource2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OpenOperationCompleted(token));
}

- (WFCValueSet*)customProperties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaSource2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CustomProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

- (id /* WFTimeSpan* */)duration {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaSource2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (BOOL)isOpen {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaSource2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOpen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSMutableArray<RTObservableCollection>* /* WMCTimedTextSource* */)externalTimedTextSources {
    ComPtr<IObservableVector<ABI::Windows::Media::Core::TimedTextSource*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaSource2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExternalTimedTextSources(unmarshalledReturn.GetAddressOf()));
    return RTProxiedObservableNSMutableArray_WMCTimedTextSource_create(unmarshalledReturn.Get());
}

- (NSMutableArray<RTObservableCollection>* /* WMCTimedMetadataTrack* */)externalTimedMetadataTracks {
    ComPtr<IObservableVector<ABI::Windows::Media::Core::TimedMetadataTrack*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaSource2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExternalTimedMetadataTracks(unmarshalledReturn.GetAddressOf()));
    return RTProxiedObservableNSMutableArray_WMCTimedMetadataTrack_create(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (EventRegistrationToken)addStateChangedEvent:(void (^)(WMCMediaSource*, WMCMediaSourceStateChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaSource3>(self);
    THROW_NS_IF_FAILED(_comInst->add_StateChanged(
        Make<ITypedEventHandler_Windows_Media_Core_MediaSource_Windows_Media_Core_MediaSourceStateChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStateChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaSource3>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StateChanged(token));
}

- (WMCMediaSourceState)state {
    ABI::Windows::Media::Core::MediaSourceState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaSource3>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WMCMediaSourceState)unmarshalledReturn;
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaSource3>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

@end

@implementation WMCMediaBinder

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaBinder> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Core.MediaBinder").Get(), &out));
    return [_createRtProxy<WMCMediaBinder>(out.Get()) retain];
}

- (EventRegistrationToken)addBindingEvent:(void (^)(WMCMediaBinder*, WMCMediaBindingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaBinder>(self);
    THROW_NS_IF_FAILED(_comInst->add_Binding(
        Make<ITypedEventHandler_Windows_Media_Core_MediaBinder_Windows_Media_Core_MediaBindingEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBindingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaBinder>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Binding(token));
}

- (NSString*)token {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaBinder>(self);
    THROW_NS_IF_FAILED(_comInst->get_Token(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setToken:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaBinder>(self);
    THROW_NS_IF_FAILED(_comInst->put_Token(nsStrToHstr(value).Get()));
}

- (WMCMediaSource*)source {
    ComPtr<ABI::Windows::Media::Core::IMediaSource2> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaBinder>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaSource>(unmarshalledReturn.Get());
}

@end

@implementation WMCMediaBindingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaBindingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addCanceledEvent:(void (^)(WMCMediaBindingEventArgs*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaBindingEventArgs>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Canceled(Make<ITypedEventHandler_Windows_Media_Core_MediaBindingEventArgs_System_Object>(handler).Get(),
                               &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCanceledEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaBindingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Canceled(token));
}

- (WMCMediaBinder*)mediaBinder {
    ComPtr<ABI::Windows::Media::Core::IMediaBinder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaBindingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaBinder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaBinder>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaBindingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)uri {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaBindingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->SetUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get()));
}

- (void)setStream:(RTObject<WSSIRandomAccessStream>*)stream contentType:(NSString*)contentType {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaBindingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->SetStream(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(stream).Get(),
                                           nsStrToHstr(contentType).Get()));
}

- (void)setStreamReference:(RTObject<WSSIRandomAccessStreamReference>*)stream contentType:(NSString*)contentType {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaBindingEventArgs>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetStreamReference(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(stream).Get(),
                                     nsStrToHstr(contentType).Get()));
}

@end

@implementation WMCMediaSourceOpenOperationCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaSourceOpenOperationCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCMediaSourceError*)error {
    ComPtr<ABI::Windows::Media::Core::IMediaSourceError> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaSourceOpenOperationCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Error(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCMediaSourceError>(unmarshalledReturn.Get());
}

@end

@implementation WMCTimedTextSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::ITimedTextSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::Core::ITimedTextSourceStatics> WMCITimedTextSourceStatics_inst() {
    ComPtr<ABI::Windows::Media::Core::ITimedTextSourceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Core.TimedTextSource").Get(), &inst));
    return inst;
}

+ (WMCTimedTextSource*)createFromStream:(RTObject<WSSIRandomAccessStream>*)stream {
    ComPtr<ABI::Windows::Media::Core::ITimedTextSource> unmarshalledReturn;
    auto _comInst = WMCITimedTextSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromStream(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(stream).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCTimedTextSource>(unmarshalledReturn.Get());
}

+ (WMCTimedTextSource*)createFromUri:(WFUri*)uri {
    ComPtr<ABI::Windows::Media::Core::ITimedTextSource> unmarshalledReturn;
    auto _comInst = WMCITimedTextSourceStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCTimedTextSource>(unmarshalledReturn.Get());
}

+ (WMCTimedTextSource*)createFromStreamWithLanguage:(RTObject<WSSIRandomAccessStream>*)stream defaultLanguage:(NSString*)defaultLanguage {
    ComPtr<ABI::Windows::Media::Core::ITimedTextSource> unmarshalledReturn;
    auto _comInst = WMCITimedTextSourceStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromStreamWithLanguage(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(stream).Get(),
                                               nsStrToHstr(defaultLanguage).Get(),
                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCTimedTextSource>(unmarshalledReturn.Get());
}

+ (WMCTimedTextSource*)createFromUriWithLanguage:(WFUri*)uri defaultLanguage:(NSString*)defaultLanguage {
    ComPtr<ABI::Windows::Media::Core::ITimedTextSource> unmarshalledReturn;
    auto _comInst = WMCITimedTextSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromUriWithLanguage(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                           nsStrToHstr(defaultLanguage).Get(),
                                                           unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCTimedTextSource>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addResolvedEvent:(void (^)(WMCTimedTextSource*, WMCTimedTextSourceResolveResultEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextSource>(self);
    THROW_NS_IF_FAILED(_comInst->add_Resolved(
        Make<ITypedEventHandler_Windows_Media_Core_TimedTextSource_Windows_Media_Core_TimedTextSourceResolveResultEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeResolvedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Resolved(token));
}

@end

@implementation WMCTimedMetadataTrack

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::ITimedMetadataTrack> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Core::ITimedMetadataTrackFactory> WMCITimedMetadataTrackFactory_inst() {
    ComPtr<ABI::Windows::Media::Core::ITimedMetadataTrackFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Core.TimedMetadataTrack").Get(), &inst));
    return inst;
}

+ (WMCTimedMetadataTrack*)make:(NSString*)id language:(NSString*)language kind:(WMCTimedMetadataKind)kind {
    ComPtr<ABI::Windows::Media::Core::ITimedMetadataTrack> unmarshalledReturn;
    auto _comInst = WMCITimedMetadataTrackFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(id).Get(),
                                        nsStrToHstr(language).Get(),
                                        (ABI::Windows::Media::Core::TimedMetadataKind)kind,
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMCTimedMetadataTrack>(unmarshalledReturn.Get()) retain];
}

- (EventRegistrationToken)addCueEnteredEvent:(void (^)(WMCTimedMetadataTrack*, WMCMediaCueEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrack>(self);
    THROW_NS_IF_FAILED(_comInst->add_CueEntered(
        Make<ITypedEventHandler_Windows_Media_Core_TimedMetadataTrack_Windows_Media_Core_MediaCueEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCueEnteredEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrack>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CueEntered(token));
}

- (EventRegistrationToken)addCueExitedEvent:(void (^)(WMCTimedMetadataTrack*, WMCMediaCueEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrack>(self);
    THROW_NS_IF_FAILED(_comInst->add_CueExited(
        Make<ITypedEventHandler_Windows_Media_Core_TimedMetadataTrack_Windows_Media_Core_MediaCueEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCueExitedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrack>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CueExited(token));
}

- (EventRegistrationToken)addTrackFailedEvent:(void (^)(WMCTimedMetadataTrack*, WMCTimedMetadataTrackFailedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrack>(self);
    THROW_NS_IF_FAILED(_comInst->add_TrackFailed(
        Make<ITypedEventHandler_Windows_Media_Core_TimedMetadataTrack_Windows_Media_Core_TimedMetadataTrackFailedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTrackFailedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrack>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TrackFailed(token));
}

- (NSArray* /* RTObject<WMCIMediaCue>* */)cues {
    ComPtr<IVectorView<ABI::Windows::Media::Core::IMediaCue*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cues(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_WMCIMediaCue_create(unmarshalledReturn.Get());
}

- (NSArray* /* RTObject<WMCIMediaCue>* */)activeCues {
    ComPtr<IVectorView<ABI::Windows::Media::Core::IMediaCue*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActiveCues(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_WMCIMediaCue_create(unmarshalledReturn.Get());
}

- (WMCTimedMetadataKind)timedMetadataKind {
    ABI::Windows::Media::Core::TimedMetadataKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimedMetadataKind(&unmarshalledReturn));
    return (WMCTimedMetadataKind)unmarshalledReturn;
}

- (NSString*)dispatchType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_DispatchType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)addCue:(RTObject<WMCIMediaCue>*)cue {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrack>(self);
    THROW_NS_IF_FAILED(_comInst->AddCue(_getRtInterface<ABI::Windows::Media::Core::IMediaCue>(cue).Get()));
}

- (void)removeCue:(RTObject<WMCIMediaCue>*)cue {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrack>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveCue(_getRtInterface<ABI::Windows::Media::Core::IMediaCue>(cue).Get()));
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMCMediaTrackKind)trackKind {
    ABI::Windows::Media::Core::MediaTrackKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrackKind(&unmarshalledReturn));
    return (WMCMediaTrackKind)unmarshalledReturn;
}

- (void)setLabel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->put_Label(nsStrToHstr(value).Get()));
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMPMediaPlaybackItem*)playbackItem {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrack2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get());
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrack2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMCMediaSourceStateChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaSourceStateChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCMediaSourceState)oldState {
    ABI::Windows::Media::Core::MediaSourceState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaSourceStateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldState(&unmarshalledReturn));
    return (WMCMediaSourceState)unmarshalledReturn;
}

- (WMCMediaSourceState)newState {
    ABI::Windows::Media::Core::MediaSourceState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaSourceStateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewState(&unmarshalledReturn));
    return (WMCMediaSourceState)unmarshalledReturn;
}

@end

@implementation WMCTimedTextRegion

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::ITimedTextRegion> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Core.TimedTextRegion").Get(), &out));
    return [_createRtProxy<WMCTimedTextRegion>(out.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (WMCTimedTextPoint*)position {
    ABI::Windows::Media::Core::TimedTextPoint unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WMCTimedTextPoint_create(unmarshalledReturn);
}

- (void)setPosition:(WMCTimedTextPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->put_Position(*[value internalStruct]));
}

- (WMCTimedTextSize*)extent {
    ABI::Windows::Media::Core::TimedTextSize unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_Extent(&unmarshalledReturn));
    return WMCTimedTextSize_create(unmarshalledReturn);
}

- (void)setExtent:(WMCTimedTextSize*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->put_Extent(*[value internalStruct]));
}

- (WUColor*)background {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_Background(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setBackground:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->put_Background(*[value internalStruct]));
}

- (WMCTimedTextWritingMode)writingMode {
    ABI::Windows::Media::Core::TimedTextWritingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_WritingMode(&unmarshalledReturn));
    return (WMCTimedTextWritingMode)unmarshalledReturn;
}

- (void)setWritingMode:(WMCTimedTextWritingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->put_WritingMode((ABI::Windows::Media::Core::TimedTextWritingMode)value));
}

- (WMCTimedTextDisplayAlignment)displayAlignment {
    ABI::Windows::Media::Core::TimedTextDisplayAlignment unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayAlignment(&unmarshalledReturn));
    return (WMCTimedTextDisplayAlignment)unmarshalledReturn;
}

- (void)setDisplayAlignment:(WMCTimedTextDisplayAlignment)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayAlignment((ABI::Windows::Media::Core::TimedTextDisplayAlignment)value));
}

- (WMCTimedTextDouble*)lineHeight {
    ABI::Windows::Media::Core::TimedTextDouble unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineHeight(&unmarshalledReturn));
    return WMCTimedTextDouble_create(unmarshalledReturn);
}

- (void)setLineHeight:(WMCTimedTextDouble*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->put_LineHeight(*[value internalStruct]));
}

- (BOOL)isOverflowClipped {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOverflowClipped(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsOverflowClipped:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsOverflowClipped((boolean)value));
}

- (WMCTimedTextPadding*)padding {
    ABI::Windows::Media::Core::TimedTextPadding unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_Padding(&unmarshalledReturn));
    return WMCTimedTextPadding_create(unmarshalledReturn);
}

- (void)setPadding:(WMCTimedTextPadding*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->put_Padding(*[value internalStruct]));
}

- (WMCTimedTextWrapping)textWrapping {
    ABI::Windows::Media::Core::TimedTextWrapping unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextWrapping(&unmarshalledReturn));
    return (WMCTimedTextWrapping)unmarshalledReturn;
}

- (void)setTextWrapping:(WMCTimedTextWrapping)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->put_TextWrapping((ABI::Windows::Media::Core::TimedTextWrapping)value));
}

- (int)zIndex {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_ZIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setZIndex:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->put_ZIndex(value));
}

- (WMCTimedTextScrollMode)scrollMode {
    ABI::Windows::Media::Core::TimedTextScrollMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScrollMode(&unmarshalledReturn));
    return (WMCTimedTextScrollMode)unmarshalledReturn;
}

- (void)setScrollMode:(WMCTimedTextScrollMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextRegion>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScrollMode((ABI::Windows::Media::Core::TimedTextScrollMode)value));
}

@end

@implementation WMCTimedTextStyle

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::ITimedTextStyle> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Core.TimedTextStyle").Get(), &out));
    return [_createRtProxy<WMCTimedTextStyle>(out.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (NSString*)fontFamily {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->get_FontFamily(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFontFamily:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->put_FontFamily(nsStrToHstr(value).Get()));
}

- (WMCTimedTextDouble*)fontSize {
    ABI::Windows::Media::Core::TimedTextDouble unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->get_FontSize(&unmarshalledReturn));
    return WMCTimedTextDouble_create(unmarshalledReturn);
}

- (void)setFontSize:(WMCTimedTextDouble*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->put_FontSize(*[value internalStruct]));
}

- (WMCTimedTextWeight)fontWeight {
    ABI::Windows::Media::Core::TimedTextWeight unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->get_FontWeight(&unmarshalledReturn));
    return (WMCTimedTextWeight)unmarshalledReturn;
}

- (void)setFontWeight:(WMCTimedTextWeight)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->put_FontWeight((ABI::Windows::Media::Core::TimedTextWeight)value));
}

- (WUColor*)foreground {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->get_Foreground(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setForeground:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->put_Foreground(*[value internalStruct]));
}

- (WUColor*)background {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->get_Background(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setBackground:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->put_Background(*[value internalStruct]));
}

- (BOOL)isBackgroundAlwaysShown {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBackgroundAlwaysShown(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsBackgroundAlwaysShown:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsBackgroundAlwaysShown((boolean)value));
}

- (WMCTimedTextFlowDirection)flowDirection {
    ABI::Windows::Media::Core::TimedTextFlowDirection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->get_FlowDirection(&unmarshalledReturn));
    return (WMCTimedTextFlowDirection)unmarshalledReturn;
}

- (void)setFlowDirection:(WMCTimedTextFlowDirection)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->put_FlowDirection((ABI::Windows::Media::Core::TimedTextFlowDirection)value));
}

- (WMCTimedTextLineAlignment)lineAlignment {
    ABI::Windows::Media::Core::TimedTextLineAlignment unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineAlignment(&unmarshalledReturn));
    return (WMCTimedTextLineAlignment)unmarshalledReturn;
}

- (void)setLineAlignment:(WMCTimedTextLineAlignment)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->put_LineAlignment((ABI::Windows::Media::Core::TimedTextLineAlignment)value));
}

- (WUColor*)outlineColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutlineColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setOutlineColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutlineColor(*[value internalStruct]));
}

- (WMCTimedTextDouble*)outlineThickness {
    ABI::Windows::Media::Core::TimedTextDouble unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutlineThickness(&unmarshalledReturn));
    return WMCTimedTextDouble_create(unmarshalledReturn);
}

- (void)setOutlineThickness:(WMCTimedTextDouble*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutlineThickness(*[value internalStruct]));
}

- (WMCTimedTextDouble*)outlineRadius {
    ABI::Windows::Media::Core::TimedTextDouble unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutlineRadius(&unmarshalledReturn));
    return WMCTimedTextDouble_create(unmarshalledReturn);
}

- (void)setOutlineRadius:(WMCTimedTextDouble*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextStyle>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutlineRadius(*[value internalStruct]));
}

@end

@implementation WMCTimedTextLine

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::ITimedTextLine> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Core.TimedTextLine").Get(), &out));
    return [_createRtProxy<WMCTimedTextLine>(out.Get()) retain];
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextLine>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextLine>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* WMCTimedTextSubformat* */)subformats {
    ComPtr<IVector<ABI::Windows::Media::Core::TimedTextSubformat*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextLine>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subformats(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WMCTimedTextSubformat_create(unmarshalledReturn.Get());
}

@end

@implementation WMCTimedTextSubformat

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::ITimedTextSubformat> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Core.TimedTextSubformat").Get(), &out));
    return [_createRtProxy<WMCTimedTextSubformat>(out.Get()) retain];
}

- (int)startIndex {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextSubformat>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setStartIndex:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextSubformat>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartIndex(value));
}

- (int)length {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextSubformat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLength:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextSubformat>(self);
    THROW_NS_IF_FAILED(_comInst->put_Length(value));
}

- (WMCTimedTextStyle*)subformatStyle {
    ComPtr<ABI::Windows::Media::Core::ITimedTextStyle> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextSubformat>(self);
    THROW_NS_IF_FAILED(_comInst->get_SubformatStyle(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCTimedTextStyle>(unmarshalledReturn.Get());
}

- (void)setSubformatStyle:(WMCTimedTextStyle*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextSubformat>(self);
    THROW_NS_IF_FAILED(_comInst->put_SubformatStyle(_getRtInterface<ABI::Windows::Media::Core::ITimedTextStyle>(value).Get()));
}

@end

@implementation WMCTimedMetadataTrackError

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::ITimedMetadataTrackError> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCTimedMetadataTrackErrorCode)errorCode {
    ABI::Windows::Media::Core::TimedMetadataTrackErrorCode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrackError>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (WMCTimedMetadataTrackErrorCode)unmarshalledReturn;
}

- (HRESULT)extendedError {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrackError>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedError(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WMCMediaCueEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaCueEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WMCIMediaCue>*)cue {
    ComPtr<ABI::Windows::Media::Core::IMediaCue> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCueEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cue(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCIMediaCue>(unmarshalledReturn.Get());
}

@end

@implementation WMCTimedMetadataTrackFailedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::ITimedMetadataTrackFailedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCTimedMetadataTrackError*)error {
    ComPtr<ABI::Windows::Media::Core::ITimedMetadataTrackError> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedMetadataTrackFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Error(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCTimedMetadataTrackError>(unmarshalledReturn.Get());
}

@end

@implementation WMCTimedTextSourceResolveResultEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::ITimedTextSourceResolveResultEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCTimedMetadataTrackError*)error {
    ComPtr<ABI::Windows::Media::Core::ITimedMetadataTrackError> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextSourceResolveResultEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Error(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCTimedMetadataTrackError>(unmarshalledReturn.Get());
}

- (NSArray* /* WMCTimedMetadataTrack* */)tracks {
    ComPtr<IVectorView<ABI::Windows::Media::Core::TimedMetadataTrack*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextSourceResolveResultEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tracks(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMCTimedMetadataTrack_create(unmarshalledReturn.Get());
}

@end

@implementation WMCVideoTrack

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaTrack> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMCMediaTrackKind)trackKind {
    ABI::Windows::Media::Core::MediaTrackKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrackKind(&unmarshalledReturn));
    return (WMCMediaTrackKind)unmarshalledReturn;
}

- (void)setLabel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->put_Label(nsStrToHstr(value).Get()));
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (EventRegistrationToken)addOpenFailedEvent:(void (^)(WMCVideoTrack*, WMCVideoTrackOpenFailedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IVideoTrack>(self);
    THROW_NS_IF_FAILED(_comInst->add_OpenFailed(
        Make<ITypedEventHandler_Windows_Media_Core_VideoTrack_Windows_Media_Core_VideoTrackOpenFailedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOpenFailedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IVideoTrack>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OpenFailed(token));
}

- (WMMVideoEncodingProperties*)getEncodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IVideoTrack>(self);
    THROW_NS_IF_FAILED(_comInst->GetEncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMVideoEncodingProperties>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackItem*)playbackItem {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IVideoTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get());
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IVideoTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMCVideoTrackSupportInfo*)supportInfo {
    ComPtr<ABI::Windows::Media::Core::IVideoTrackSupportInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IVideoTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCVideoTrackSupportInfo>(unmarshalledReturn.Get());
}

@end

@implementation WMCVideoTrackOpenFailedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IVideoTrackOpenFailedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (HRESULT)extendedError {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IVideoTrackOpenFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedError(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WMCVideoTrackSupportInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IVideoTrackSupportInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCMediaDecoderStatus)decoderStatus {
    ABI::Windows::Media::Core::MediaDecoderStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IVideoTrackSupportInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DecoderStatus(&unmarshalledReturn));
    return (WMCMediaDecoderStatus)unmarshalledReturn;
}

- (WMCMediaSourceStatus)mediaSourceStatus {
    ABI::Windows::Media::Core::MediaSourceStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IVideoTrackSupportInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaSourceStatus(&unmarshalledReturn));
    return (WMCMediaSourceStatus)unmarshalledReturn;
}

@end

@implementation WMCAudioTrack

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IMediaTrack> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMCMediaTrackKind)trackKind {
    ABI::Windows::Media::Core::MediaTrackKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrackKind(&unmarshalledReturn));
    return (WMCMediaTrackKind)unmarshalledReturn;
}

- (void)setLabel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->put_Label(nsStrToHstr(value).Get()));
}

- (NSString*)label {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Label(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (EventRegistrationToken)addOpenFailedEvent:(void (^)(WMCAudioTrack*, WMCAudioTrackOpenFailedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->add_OpenFailed(
        Make<ITypedEventHandler_Windows_Media_Core_AudioTrack_Windows_Media_Core_AudioTrackOpenFailedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOpenFailedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->remove_OpenFailed(token));
}

- (WMMAudioEncodingProperties*)getEncodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->GetEncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (WMPMediaPlaybackItem*)playbackItem {
    ComPtr<ABI::Windows::Media::Playback::IMediaPlaybackItem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMPMediaPlaybackItem>(unmarshalledReturn.Get());
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMCAudioTrackSupportInfo*)supportInfo {
    ComPtr<ABI::Windows::Media::Core::IAudioTrackSupportInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IAudioTrack>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCAudioTrackSupportInfo>(unmarshalledReturn.Get());
}

@end

@implementation WMCAudioTrackOpenFailedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IAudioTrackOpenFailedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (HRESULT)extendedError {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IAudioTrackOpenFailedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedError(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WMCAudioTrackSupportInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IAudioTrackSupportInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCMediaDecoderStatus)decoderStatus {
    ABI::Windows::Media::Core::MediaDecoderStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IAudioTrackSupportInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DecoderStatus(&unmarshalledReturn));
    return (WMCMediaDecoderStatus)unmarshalledReturn;
}

- (WMCAudioDecoderDegradation)degradation {
    ABI::Windows::Media::Core::AudioDecoderDegradation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IAudioTrackSupportInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Degradation(&unmarshalledReturn));
    return (WMCAudioDecoderDegradation)unmarshalledReturn;
}

- (WMCAudioDecoderDegradationReason)degradationReason {
    ABI::Windows::Media::Core::AudioDecoderDegradationReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IAudioTrackSupportInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DegradationReason(&unmarshalledReturn));
    return (WMCAudioDecoderDegradationReason)unmarshalledReturn;
}

- (WMCMediaSourceStatus)mediaSourceStatus {
    ABI::Windows::Media::Core::MediaSourceStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IAudioTrackSupportInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaSourceStatus(&unmarshalledReturn));
    return (WMCMediaSourceStatus)unmarshalledReturn;
}

@end

@implementation WMCTimedTextCue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::ITimedTextCue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Core.TimedTextCue").Get(), &out));
    return [_createRtProxy<WMCTimedTextCue>(out.Get()) retain];
}

- (WMCTimedTextRegion*)cueRegion {
    ComPtr<ABI::Windows::Media::Core::ITimedTextRegion> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextCue>(self);
    THROW_NS_IF_FAILED(_comInst->get_CueRegion(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCTimedTextRegion>(unmarshalledReturn.Get());
}

- (void)setCueRegion:(WMCTimedTextRegion*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextCue>(self);
    THROW_NS_IF_FAILED(_comInst->put_CueRegion(_getRtInterface<ABI::Windows::Media::Core::ITimedTextRegion>(value).Get()));
}

- (WMCTimedTextStyle*)cueStyle {
    ComPtr<ABI::Windows::Media::Core::ITimedTextStyle> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextCue>(self);
    THROW_NS_IF_FAILED(_comInst->get_CueStyle(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCTimedTextStyle>(unmarshalledReturn.Get());
}

- (void)setCueStyle:(WMCTimedTextStyle*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextCue>(self);
    THROW_NS_IF_FAILED(_comInst->put_CueStyle(_getRtInterface<ABI::Windows::Media::Core::ITimedTextStyle>(value).Get()));
}

- (NSMutableArray* /* WMCTimedTextLine* */)lines {
    ComPtr<IVector<ABI::Windows::Media::Core::TimedTextLine*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::ITimedTextCue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Lines(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WMCTimedTextLine_create(unmarshalledReturn.Get());
}

- (void)setStartTime:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartTime(*[value internalStruct]));
}

- (WFTimeSpan*)startTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setDuration:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->put_Duration(*[value internalStruct]));
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id(nsStrToHstr(value).Get()));
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMCDataCue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Core::IDataCue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Core.DataCue").Get(), &out));
    return [_createRtProxy<WMCDataCue>(out.Get()) retain];
}

- (void)setData:(RTObject<WSSIBuffer>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IDataCue>(self);
    THROW_NS_IF_FAILED(_comInst->put_Data(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(value).Get()));
}

- (RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IDataCue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (void)setStartTime:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartTime(*[value internalStruct]));
}

- (WFTimeSpan*)startTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setDuration:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->put_Duration(*[value internalStruct]));
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id(nsStrToHstr(value).Get()));
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Core::IMediaCue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMCMseTimeRange {
    ABI::Windows::Media::Core::MseTimeRange structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Media::Core::MseTimeRange)s {
    WMCMseTimeRange* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Media::Core::MseTimeRange*)internalStruct {
    return &structVal;
}
- (WFTimeSpan*)start {
    return WFTimeSpan_create(structVal.Start);
}
- (void)setStart:(WFTimeSpan*)val {
    structVal.Start = *[val internalStruct];
}
- (WFTimeSpan*)end {
    return WFTimeSpan_create(structVal.End);
}
- (void)setEnd:(WFTimeSpan*)val {
    structVal.End = *[val internalStruct];
}
@end
@implementation WMCTimedTextPadding {
    ABI::Windows::Media::Core::TimedTextPadding structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Media::Core::TimedTextPadding)s {
    WMCTimedTextPadding* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Media::Core::TimedTextPadding*)internalStruct {
    return &structVal;
}
- (double)before {
    return structVal.Before;
}
- (void)setBefore:(double)val {
    structVal.Before = val;
}
- (double)after {
    return structVal.After;
}
- (void)setAfter:(double)val {
    structVal.After = val;
}
- (double)start {
    return structVal.Start;
}
- (void)setStart:(double)val {
    structVal.Start = val;
}
- (double)end {
    return structVal.End;
}
- (void)setEnd:(double)val {
    structVal.End = val;
}
- (WMCTimedTextUnit)unit {
    return (WMCTimedTextUnit)structVal.Unit;
}
- (void)setUnit:(WMCTimedTextUnit)val {
    structVal.Unit = (ABI::Windows::Media::Core::TimedTextUnit)val;
}
@end
@implementation WMCTimedTextSize {
    ABI::Windows::Media::Core::TimedTextSize structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Media::Core::TimedTextSize)s {
    WMCTimedTextSize* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Media::Core::TimedTextSize*)internalStruct {
    return &structVal;
}
- (double)height {
    return structVal.Height;
}
- (void)setHeight:(double)val {
    structVal.Height = val;
}
- (double)width {
    return structVal.Width;
}
- (void)setWidth:(double)val {
    structVal.Width = val;
}
- (WMCTimedTextUnit)unit {
    return (WMCTimedTextUnit)structVal.Unit;
}
- (void)setUnit:(WMCTimedTextUnit)val {
    structVal.Unit = (ABI::Windows::Media::Core::TimedTextUnit)val;
}
@end
@implementation WMCTimedTextDouble {
    ABI::Windows::Media::Core::TimedTextDouble structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Media::Core::TimedTextDouble)s {
    WMCTimedTextDouble* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Media::Core::TimedTextDouble*)internalStruct {
    return &structVal;
}
- (double)value {
    return structVal.Value;
}
- (void)setValue:(double)val {
    structVal.Value = val;
}
- (WMCTimedTextUnit)unit {
    return (WMCTimedTextUnit)structVal.Unit;
}
- (void)setUnit:(WMCTimedTextUnit)val {
    structVal.Unit = (ABI::Windows::Media::Core::TimedTextUnit)val;
}
@end
@implementation WMCTimedTextPoint {
    ABI::Windows::Media::Core::TimedTextPoint structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Media::Core::TimedTextPoint)s {
    WMCTimedTextPoint* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Media::Core::TimedTextPoint*)internalStruct {
    return &structVal;
}
- (double)x {
    return structVal.X;
}
- (void)setX:(double)val {
    structVal.X = val;
}
- (double)y {
    return structVal.Y;
}
- (void)setY:(double)val {
    structVal.Y = val;
}
- (WMCTimedTextUnit)unit {
    return (WMCTimedTextUnit)structVal.Unit;
}
- (void)setUnit:(WMCTimedTextUnit)val {
    structVal.Unit = (ABI::Windows::Media::Core::TimedTextUnit)val;
}
@end
id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_RTObject_WMCIMediaCue_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Core::IMediaCue*>,
                                                                             RTArrayObj<ABI::Windows::Media::Core::IMediaCue*,
                                                                                        IVectorView<ABI::Windows::Media::Core::IMediaCue*>,
                                                                                        RTObject<WMCIMediaCue>,
                                                                                        ABI::Windows::Media::Core::IMediaCue*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMCMseSourceBuffer_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Core::MseSourceBuffer*>,
                                         RTArrayObj<ABI::Windows::Media::Core::IMseSourceBuffer*,
                                                    IVectorView<ABI::Windows::Media::Core::MseSourceBuffer*>,
                                                    WMCMseSourceBuffer,
                                                    ABI::Windows::Media::Core::MseSourceBuffer*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMCMseTimeRange_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Core::MseTimeRange>,
                                         RTArrayObj<ABI::Windows::Media::Core::MseTimeRange,
                                                    IVectorView<ABI::Windows::Media::Core::MseTimeRange>,
                                                    WMCMseTimeRange,
                                                    ABI::Windows::Media::Core::MseTimeRange,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMCTimedMetadataTrack_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Core::TimedMetadataTrack*>,
                                         RTArrayObj<ABI::Windows::Media::Core::ITimedMetadataTrack*,
                                                    IVectorView<ABI::Windows::Media::Core::TimedMetadataTrack*>,
                                                    WMCTimedMetadataTrack,
                                                    ABI::Windows::Media::Core::TimedMetadataTrack*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMDCFrameController_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Devices::Core::FrameController*>,
                                         RTArrayObj<ABI::Windows::Media::Devices::Core::IFrameController*,
                                                    IVectorView<ABI::Windows::Media::Devices::Core::FrameController*>,
                                                    WMDCFrameController,
                                                    ABI::Windows::Media::Devices::Core::FrameController*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMFDetectedFace_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::FaceAnalysis::DetectedFace*>,
                                         RTArrayObj<ABI::Windows::Media::FaceAnalysis::IDetectedFace*,
                                                    IVectorView<ABI::Windows::Media::FaceAnalysis::DetectedFace*>,
                                                    WMFDetectedFace,
                                                    ABI::Windows::Media::FaceAnalysis::DetectedFace*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WMCTimedTextLine_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Media::Core::TimedTextLine*>,
                                                RTMutableArrayObj<ABI::Windows::Media::Core::ITimedTextLine*,
                                                                  IVector<ABI::Windows::Media::Core::TimedTextLine*>,
                                                                  WMCTimedTextLine,
                                                                  ABI::Windows::Media::Core::TimedTextLine*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WMCTimedTextSubformat_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Media::Core::TimedTextSubformat*>,
                                                RTMutableArrayObj<ABI::Windows::Media::Core::ITimedTextSubformat*,
                                                                  IVector<ABI::Windows::Media::Core::TimedTextSubformat*>,
                                                                  WMCTimedTextSubformat,
                                                                  ABI::Windows::Media::Core::TimedTextSubformat*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedObservableNSMutableArray_WMCTimedMetadataTrack_create(IInspectable* val) {
    std::unique_ptr<ObservableArrayAdapter> adapter =
        std::make_unique<ObservableArrayAdapterObj<IObservableVector<ABI::Windows::Media::Core::TimedMetadataTrack*>,
                                                   RTObservableArrayObj<ABI::Windows::Media::Core::ITimedMetadataTrack*,
                                                                        IVector<ABI::Windows::Media::Core::TimedMetadataTrack*>,
                                                                        WMCTimedMetadataTrack,
                                                                        ABI::Windows::Media::Core::TimedMetadataTrack*,
                                                                        dummyObjCCreator,
                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedObservableNSMutableArray alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedObservableNSMutableArray_WMCTimedTextSource_create(IInspectable* val) {
    std::unique_ptr<ObservableArrayAdapter> adapter =
        std::make_unique<ObservableArrayAdapterObj<IObservableVector<ABI::Windows::Media::Core::TimedTextSource*>,
                                                   RTObservableArrayObj<ABI::Windows::Media::Core::ITimedTextSource*,
                                                                        IVector<ABI::Windows::Media::Core::TimedTextSource*>,
                                                                        WMCTimedTextSource,
                                                                        ABI::Windows::Media::Core::TimedTextSource*,
                                                                        dummyObjCCreator,
                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedObservableNSMutableArray alloc] initWithAdapter:std::move(adapter)] autorelease];
}
