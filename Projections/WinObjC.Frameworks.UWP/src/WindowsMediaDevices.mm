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

// WindowsMediaDevices.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Devices.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaDevices.h"
#include "WindowsMediaDevices_priv.h"

@implementation WMDIDefaultAudioDeviceChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMDAudioDeviceRole)role {
    ABI::Windows::Media::Devices::AudioDeviceRole unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Role(&unmarshalledReturn));
    return (WMDAudioDeviceRole)unmarshalledReturn;
}

@end

@implementation WMDIMediaDeviceController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IMediaDeviceController> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* RTObject<WMMIMediaEncodingProperties>* */)getAvailableMediaStreamProperties:(WMCMediaStreamType)mediaStreamType {
    ComPtr<IVectorView<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->GetAvailableMediaStreamProperties((ABI::Windows::Media::Capture::MediaStreamType)mediaStreamType,
                                                                   unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_WMMIMediaEncodingProperties_create(unmarshalledReturn.Get());
}

- (RTObject<WMMIMediaEncodingProperties>*)getMediaStreamProperties:(WMCMediaStreamType)mediaStreamType {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->GetMediaStreamProperties((ABI::Windows::Media::Capture::MediaStreamType)mediaStreamType,
                                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMIMediaEncodingProperties>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)setMediaStreamPropertiesAsync:(WMCMediaStreamType)mediaStreamType
                                   mediaEncodingProperties:(RTObject<WMMIMediaEncodingProperties>*)mediaEncodingProperties {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->SetMediaStreamPropertiesAsync(
        (ABI::Windows::Media::Capture::MediaStreamType)mediaStreamType,
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(mediaEncodingProperties).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WMDDefaultAudioCaptureDeviceChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMDAudioDeviceRole)role {
    ABI::Windows::Media::Devices::AudioDeviceRole unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Role(&unmarshalledReturn));
    return (WMDAudioDeviceRole)unmarshalledReturn;
}

@end

@implementation WMDDefaultAudioRenderDeviceChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMDAudioDeviceRole)role {
    ABI::Windows::Media::Devices::AudioDeviceRole unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IDefaultAudioDeviceChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Role(&unmarshalledReturn));
    return (WMDAudioDeviceRole)unmarshalledReturn;
}

@end

@implementation WMDMediaDevice

ComPtr<ABI::Windows::Media::Devices::IMediaDeviceStatics> WMDIMediaDeviceStatics_inst() {
    ComPtr<ABI::Windows::Media::Devices::IMediaDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Devices.MediaDevice").Get(), &inst));
    return inst;
}

+ (NSString*)getAudioCaptureSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WMDIMediaDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetAudioCaptureSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getAudioRenderSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WMDIMediaDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetAudioRenderSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getVideoCaptureSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WMDIMediaDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetVideoCaptureSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDefaultAudioCaptureId:(WMDAudioDeviceRole)role {
    HSTRING unmarshalledReturn;
    auto _comInst = WMDIMediaDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultAudioCaptureId((ABI::Windows::Media::Devices::AudioDeviceRole)role, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDefaultAudioRenderId:(WMDAudioDeviceRole)role {
    HSTRING unmarshalledReturn;
    auto _comInst = WMDIMediaDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefaultAudioRenderId((ABI::Windows::Media::Devices::AudioDeviceRole)role, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (EventRegistrationToken)addDefaultAudioCaptureDeviceChangedEvent:(void (^)(RTObject*,
                                                                             WMDDefaultAudioCaptureDeviceChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WMDIMediaDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_DefaultAudioCaptureDeviceChanged(
        Make<ITypedEventHandler_System_Object_Windows_Media_Devices_DefaultAudioCaptureDeviceChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeDefaultAudioCaptureDeviceChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WMDIMediaDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_DefaultAudioCaptureDeviceChanged(cookie));
}

+ (EventRegistrationToken)addDefaultAudioRenderDeviceChangedEvent:(void (^)(RTObject*,
                                                                            WMDDefaultAudioRenderDeviceChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WMDIMediaDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_DefaultAudioRenderDeviceChanged(
        Make<ITypedEventHandler_System_Object_Windows_Media_Devices_DefaultAudioRenderDeviceChangedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeDefaultAudioRenderDeviceChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WMDIMediaDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_DefaultAudioRenderDeviceChanged(cookie));
}

@end

@implementation WMDAudioDeviceController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IAudioDeviceController> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setMuted:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAudioDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->put_Muted((boolean)value));
}

- (BOOL)muted {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAudioDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Muted(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setVolumePercent:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAudioDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->put_VolumePercent(value));
}

- (float)volumePercent {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAudioDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_VolumePercent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSArray* /* RTObject<WMMIMediaEncodingProperties>* */)getAvailableMediaStreamProperties:(WMCMediaStreamType)mediaStreamType {
    ComPtr<IVectorView<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->GetAvailableMediaStreamProperties((ABI::Windows::Media::Capture::MediaStreamType)mediaStreamType,
                                                                   unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_WMMIMediaEncodingProperties_create(unmarshalledReturn.Get());
}

- (RTObject<WMMIMediaEncodingProperties>*)getMediaStreamProperties:(WMCMediaStreamType)mediaStreamType {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->GetMediaStreamProperties((ABI::Windows::Media::Capture::MediaStreamType)mediaStreamType,
                                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMIMediaEncodingProperties>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)setMediaStreamPropertiesAsync:(WMCMediaStreamType)mediaStreamType
                                   mediaEncodingProperties:(RTObject<WMMIMediaEncodingProperties>*)mediaEncodingProperties {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->SetMediaStreamPropertiesAsync(
        (ABI::Windows::Media::Capture::MediaStreamType)mediaStreamType,
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(mediaEncodingProperties).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WMDVideoDeviceController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IVideoDeviceController> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMDMediaDeviceControl*)brightness {
    ComPtr<ABI::Windows::Media::Devices::IMediaDeviceControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IVideoDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Brightness(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDMediaDeviceControl>(unmarshalledReturn.Get());
}

- (WMDMediaDeviceControl*)contrast {
    ComPtr<ABI::Windows::Media::Devices::IMediaDeviceControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IVideoDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contrast(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDMediaDeviceControl>(unmarshalledReturn.Get());
}

- (WMDMediaDeviceControl*)hue {
    ComPtr<ABI::Windows::Media::Devices::IMediaDeviceControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IVideoDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Hue(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDMediaDeviceControl>(unmarshalledReturn.Get());
}

- (WMDMediaDeviceControl*)whiteBalance {
    ComPtr<ABI::Windows::Media::Devices::IMediaDeviceControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IVideoDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_WhiteBalance(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDMediaDeviceControl>(unmarshalledReturn.Get());
}

- (WMDMediaDeviceControl*)backlightCompensation {
    ComPtr<ABI::Windows::Media::Devices::IMediaDeviceControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IVideoDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_BacklightCompensation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDMediaDeviceControl>(unmarshalledReturn.Get());
}

- (WMDMediaDeviceControl*)pan {
    ComPtr<ABI::Windows::Media::Devices::IMediaDeviceControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IVideoDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Pan(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDMediaDeviceControl>(unmarshalledReturn.Get());
}

- (WMDMediaDeviceControl*)tilt {
    ComPtr<ABI::Windows::Media::Devices::IMediaDeviceControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IVideoDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tilt(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDMediaDeviceControl>(unmarshalledReturn.Get());
}

- (WMDMediaDeviceControl*)zoom {
    ComPtr<ABI::Windows::Media::Devices::IMediaDeviceControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IVideoDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Zoom(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDMediaDeviceControl>(unmarshalledReturn.Get());
}

- (WMDMediaDeviceControl*)roll {
    ComPtr<ABI::Windows::Media::Devices::IMediaDeviceControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IVideoDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Roll(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDMediaDeviceControl>(unmarshalledReturn.Get());
}

- (WMDMediaDeviceControl*)exposure {
    ComPtr<ABI::Windows::Media::Devices::IMediaDeviceControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IVideoDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Exposure(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDMediaDeviceControl>(unmarshalledReturn.Get());
}

- (WMDMediaDeviceControl*)focus {
    ComPtr<ABI::Windows::Media::Devices::IMediaDeviceControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IVideoDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Focus(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDMediaDeviceControl>(unmarshalledReturn.Get());
}

- (BOOL)trySetPowerlineFrequency:(WMCPowerlineFrequency)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IVideoDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetPowerlineFrequency((ABI::Windows::Media::Capture::PowerlineFrequency)value, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)tryGetPowerlineFrequency:(WMCPowerlineFrequency*)value {
    ABI::Windows::Media::Capture::PowerlineFrequency valueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IVideoDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetPowerlineFrequency(&valueOutUnmarshaled, &unmarshalledReturn));
    *value = (WMCPowerlineFrequency)valueOutUnmarshaled;
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* RTObject<WMMIMediaEncodingProperties>* */)getAvailableMediaStreamProperties:(WMCMediaStreamType)mediaStreamType {
    ComPtr<IVectorView<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->GetAvailableMediaStreamProperties((ABI::Windows::Media::Capture::MediaStreamType)mediaStreamType,
                                                                   unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_WMMIMediaEncodingProperties_create(unmarshalledReturn.Get());
}

- (RTObject<WMMIMediaEncodingProperties>*)getMediaStreamProperties:(WMCMediaStreamType)mediaStreamType {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->GetMediaStreamProperties((ABI::Windows::Media::Capture::MediaStreamType)mediaStreamType,
                                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMIMediaEncodingProperties>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)setMediaStreamPropertiesAsync:(WMCMediaStreamType)mediaStreamType
                                   mediaEncodingProperties:(RTObject<WMMIMediaEncodingProperties>*)mediaEncodingProperties {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->SetMediaStreamPropertiesAsync(
        (ABI::Windows::Media::Capture::MediaStreamType)mediaStreamType,
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(mediaEncodingProperties).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)setDeviceProperty:(NSString*)propertyId propertyValue:(RTObject*)propertyValue {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->SetDeviceProperty(nsStrToHstr(propertyId).Get(), [propertyValue comObj].Get()));
}

- (RTObject*)getDeviceProperty:(NSString*)propertyId {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeviceProperty(nsStrToHstr(propertyId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WMDLowLagPhotoSequenceControl*)lowLagPhotoSequence {
    ComPtr<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController2>(self);
    THROW_NS_IF_FAILED(_comInst->get_LowLagPhotoSequence(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDLowLagPhotoSequenceControl>(unmarshalledReturn.Get());
}

- (WMDLowLagPhotoControl*)lowLagPhoto {
    ComPtr<ABI::Windows::Media::Devices::ILowLagPhotoControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController2>(self);
    THROW_NS_IF_FAILED(_comInst->get_LowLagPhoto(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDLowLagPhotoControl>(unmarshalledReturn.Get());
}

- (WMDSceneModeControl*)sceneModeControl {
    ComPtr<ABI::Windows::Media::Devices::ISceneModeControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SceneModeControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDSceneModeControl>(unmarshalledReturn.Get());
}

- (WMDTorchControl*)torchControl {
    ComPtr<ABI::Windows::Media::Devices::ITorchControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TorchControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDTorchControl>(unmarshalledReturn.Get());
}

- (WMDFlashControl*)flashControl {
    ComPtr<ABI::Windows::Media::Devices::IFlashControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FlashControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDFlashControl>(unmarshalledReturn.Get());
}

- (WMDWhiteBalanceControl*)whiteBalanceControl {
    ComPtr<ABI::Windows::Media::Devices::IWhiteBalanceControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController2>(self);
    THROW_NS_IF_FAILED(_comInst->get_WhiteBalanceControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDWhiteBalanceControl>(unmarshalledReturn.Get());
}

- (WMDExposureControl*)exposureControl {
    ComPtr<ABI::Windows::Media::Devices::IExposureControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExposureControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDExposureControl>(unmarshalledReturn.Get());
}

- (WMDFocusControl*)focusControl {
    ComPtr<ABI::Windows::Media::Devices::IFocusControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FocusControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDFocusControl>(unmarshalledReturn.Get());
}

- (WMDExposureCompensationControl*)exposureCompensationControl {
    ComPtr<ABI::Windows::Media::Devices::IExposureCompensationControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExposureCompensationControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDExposureCompensationControl>(unmarshalledReturn.Get());
}

- (WMDIsoSpeedControl*)isoSpeedControl {
    ComPtr<ABI::Windows::Media::Devices::IIsoSpeedControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsoSpeedControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDIsoSpeedControl>(unmarshalledReturn.Get());
}

- (WMDRegionsOfInterestControl*)regionsOfInterestControl {
    ComPtr<ABI::Windows::Media::Devices::IRegionsOfInterestControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RegionsOfInterestControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDRegionsOfInterestControl>(unmarshalledReturn.Get());
}

- (WMDCaptureUse)primaryUse {
    ABI::Windows::Media::Devices::CaptureUse unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrimaryUse(&unmarshalledReturn));
    return (WMDCaptureUse)unmarshalledReturn;
}

- (void)setPrimaryUse:(WMDCaptureUse)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController2>(self);
    THROW_NS_IF_FAILED(_comInst->put_PrimaryUse((ABI::Windows::Media::Devices::CaptureUse)value));
}

- (WMDCVariablePhotoSequenceController*)variablePhotoSequenceController {
    ComPtr<ABI::Windows::Media::Devices::Core::IVariablePhotoSequenceController> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController3>(self);
    THROW_NS_IF_FAILED(_comInst->get_VariablePhotoSequenceController(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCVariablePhotoSequenceController>(unmarshalledReturn.Get());
}

- (WMDPhotoConfirmationControl*)photoConfirmationControl {
    ComPtr<ABI::Windows::Media::Devices::IPhotoConfirmationControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController3>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhotoConfirmationControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDPhotoConfirmationControl>(unmarshalledReturn.Get());
}

- (WMDZoomControl*)zoomControl {
    ComPtr<ABI::Windows::Media::Devices::IZoomControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController3>(self);
    THROW_NS_IF_FAILED(_comInst->get_ZoomControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDZoomControl>(unmarshalledReturn.Get());
}

- (WMDExposurePriorityVideoControl*)exposurePriorityVideoControl {
    ComPtr<ABI::Windows::Media::Devices::IExposurePriorityVideoControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController4>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExposurePriorityVideoControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDExposurePriorityVideoControl>(unmarshalledReturn.Get());
}

- (WMDMediaCaptureOptimization)desiredOptimization {
    ABI::Windows::Media::Devices::MediaCaptureOptimization unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController4>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredOptimization(&unmarshalledReturn));
    return (WMDMediaCaptureOptimization)unmarshalledReturn;
}

- (void)setDesiredOptimization:(WMDMediaCaptureOptimization)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController4>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredOptimization((ABI::Windows::Media::Devices::MediaCaptureOptimization)value));
}

- (WMDHdrVideoControl*)hdrVideoControl {
    ComPtr<ABI::Windows::Media::Devices::IHdrVideoControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController4>(self);
    THROW_NS_IF_FAILED(_comInst->get_HdrVideoControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDHdrVideoControl>(unmarshalledReturn.Get());
}

- (WMDOpticalImageStabilizationControl*)opticalImageStabilizationControl {
    ComPtr<ABI::Windows::Media::Devices::IOpticalImageStabilizationControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController4>(self);
    THROW_NS_IF_FAILED(_comInst->get_OpticalImageStabilizationControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDOpticalImageStabilizationControl>(unmarshalledReturn.Get());
}

- (WMDAdvancedPhotoControl*)advancedPhotoControl {
    ComPtr<ABI::Windows::Media::Devices::IAdvancedPhotoControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedVideoCaptureDeviceController4>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdvancedPhotoControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDAdvancedPhotoControl>(unmarshalledReturn.Get());
}

@end

@implementation WMDSceneModeControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::ISceneModeControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WMDCaptureSceneMode */)supportedModes {
    ComPtr<IVectorView<ABI::Windows::Media::Devices::CaptureSceneMode>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ISceneModeControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedModes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMDCaptureSceneMode_create(unmarshalledReturn.Get());
}

- (WMDCaptureSceneMode)value {
    ABI::Windows::Media::Devices::CaptureSceneMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ISceneModeControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return (WMDCaptureSceneMode)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)setValueAsync:(WMDCaptureSceneMode)sceneMode {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ISceneModeControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetValueAsync((ABI::Windows::Media::Devices::CaptureSceneMode)sceneMode, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WMDTorchControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::ITorchControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ITorchControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)powerSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ITorchControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_PowerSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)enabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ITorchControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Enabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ITorchControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Enabled((boolean)value));
}

- (float)powerPercent {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ITorchControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_PowerPercent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPowerPercent:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ITorchControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_PowerPercent(value));
}

@end

@implementation WMDFlashControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IFlashControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)powerSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_PowerSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)redEyeReductionSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_RedEyeReductionSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)enabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Enabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Enabled((boolean)value));
}

- (BOOL)Auto {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Auto(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAuto:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Auto((boolean)value));
}

- (BOOL)redEyeReduction {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_RedEyeReduction(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setRedEyeReduction:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_RedEyeReduction((boolean)value));
}

- (float)powerPercent {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_PowerPercent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPowerPercent:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_PowerPercent(value));
}

- (BOOL)assistantLightSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFlashControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AssistantLightSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)assistantLightEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFlashControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AssistantLightEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAssistantLightEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFlashControl2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AssistantLightEnabled((boolean)value));
}

@end

@implementation WMDExposureCompensationControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IExposureCompensationControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposureCompensationControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (float)min {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposureCompensationControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Min(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)max {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposureCompensationControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Max(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)step {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposureCompensationControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Step(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)value {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposureCompensationControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)setValueAsync:(float)value {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposureCompensationControl>(self);
    THROW_NS_IF_FAILED(_comInst->SetValueAsync(value, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WMDIsoSpeedControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IIsoSpeedControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IIsoSpeedControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WMDIsoSpeedPreset */)supportedPresets {
    ComPtr<IVectorView<ABI::Windows::Media::Devices::IsoSpeedPreset>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IIsoSpeedControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedPresets(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMDIsoSpeedPreset_create(unmarshalledReturn.Get());
}

- (WMDIsoSpeedPreset)preset {
    ABI::Windows::Media::Devices::IsoSpeedPreset unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IIsoSpeedControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Preset(&unmarshalledReturn));
    return (WMDIsoSpeedPreset)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)setPresetAsync:(WMDIsoSpeedPreset)preset {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IIsoSpeedControl>(self);
    THROW_NS_IF_FAILED(_comInst->SetPresetAsync((ABI::Windows::Media::Devices::IsoSpeedPreset)preset, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (unsigned int)min {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IIsoSpeedControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Min(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)max {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IIsoSpeedControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Max(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)step {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IIsoSpeedControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Step(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)value {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IIsoSpeedControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)setValueAsync:(unsigned int)isoSpeed {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IIsoSpeedControl2>(self);
    THROW_NS_IF_FAILED(_comInst->SetValueAsync(isoSpeed, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (BOOL)Auto {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IIsoSpeedControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Auto(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)setAutoAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IIsoSpeedControl2>(self);
    THROW_NS_IF_FAILED(_comInst->SetAutoAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WMDWhiteBalanceControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IWhiteBalanceControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IWhiteBalanceControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WMDColorTemperaturePreset)preset {
    ABI::Windows::Media::Devices::ColorTemperaturePreset unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IWhiteBalanceControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Preset(&unmarshalledReturn));
    return (WMDColorTemperaturePreset)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)setPresetAsync:(WMDColorTemperaturePreset)preset {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IWhiteBalanceControl>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetPresetAsync((ABI::Windows::Media::Devices::ColorTemperaturePreset)preset, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (unsigned int)min {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IWhiteBalanceControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Min(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)max {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IWhiteBalanceControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Max(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)step {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IWhiteBalanceControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Step(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)value {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IWhiteBalanceControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)setValueAsync:(unsigned int)temperature {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IWhiteBalanceControl>(self);
    THROW_NS_IF_FAILED(_comInst->SetValueAsync(temperature, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WMDExposureControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IExposureControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposureControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)Auto {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposureControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Auto(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)setAutoAsync:(BOOL)value {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposureControl>(self);
    THROW_NS_IF_FAILED(_comInst->SetAutoAsync((boolean)value, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)min {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposureControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Min(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)max {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposureControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Max(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)step {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposureControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Step(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)value {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposureControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)setValueAsync:(WFTimeSpan*)shutterDuration {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposureControl>(self);
    THROW_NS_IF_FAILED(_comInst->SetValueAsync(*[shutterDuration internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WMDZoomSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IZoomSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Devices.ZoomSettings").Get(), &out));
    return [_createRtProxy<WMDZoomSettings>(out.Get()) retain];
}

- (WMDZoomTransitionMode)mode {
    ABI::Windows::Media::Devices::ZoomTransitionMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IZoomSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WMDZoomTransitionMode)unmarshalledReturn;
}

- (void)setMode:(WMDZoomTransitionMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IZoomSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mode((ABI::Windows::Media::Devices::ZoomTransitionMode)value));
}

- (float)value {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IZoomSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setValue:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IZoomSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(value));
}

@end

@implementation WMDZoomControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IZoomControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IZoomControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (float)min {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IZoomControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Min(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)max {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IZoomControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Max(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)step {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IZoomControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Step(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)value {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IZoomControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setValue:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IZoomControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(value));
}

- (NSArray* /* WMDZoomTransitionMode */)supportedModes {
    ComPtr<IVectorView<ABI::Windows::Media::Devices::ZoomTransitionMode>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IZoomControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedModes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMDZoomTransitionMode_create(unmarshalledReturn.Get());
}

- (WMDZoomTransitionMode)mode {
    ABI::Windows::Media::Devices::ZoomTransitionMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IZoomControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WMDZoomTransitionMode)unmarshalledReturn;
}

- (void)configure:(WMDZoomSettings*)settings {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IZoomControl2>(self);
    THROW_NS_IF_FAILED(_comInst->Configure(_getRtInterface<ABI::Windows::Media::Devices::IZoomSettings>(settings).Get()));
}

@end

@implementation WMDFocusSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IFocusSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Devices.FocusSettings").Get(), &out));
    return [_createRtProxy<WMDFocusSettings>(out.Get()) retain];
}

- (WMDFocusMode)mode {
    ABI::Windows::Media::Devices::FocusMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WMDFocusMode)unmarshalledReturn;
}

- (void)setMode:(WMDFocusMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mode((ABI::Windows::Media::Devices::FocusMode)value));
}

- (WMDAutoFocusRange)autoFocusRange {
    ABI::Windows::Media::Devices::AutoFocusRange unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoFocusRange(&unmarshalledReturn));
    return (WMDAutoFocusRange)unmarshalledReturn;
}

- (void)setAutoFocusRange:(WMDAutoFocusRange)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoFocusRange((ABI::Windows::Media::Devices::AutoFocusRange)value));
}

- (id /* unsigned int */)value {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (void)setValue:(id /* unsigned int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(BuildNullable<unsigned int>(value)));
}

- (id /* WMDManualFocusDistance */)distance {
    ComPtr<IReference<ABI::Windows::Media::Devices::ManualFocusDistance>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_Distance(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WMDManualFocusDistance, ABI::Windows::Media::Devices::ManualFocusDistance>::convert(unmarshalledReturn.Get());
}

- (void)setDistance:(id /* WMDManualFocusDistance */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_Distance(BuildNullable<ABI::Windows::Media::Devices::ManualFocusDistance>(value)));
}

- (BOOL)waitForFocus {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_WaitForFocus(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setWaitForFocus:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_WaitForFocus((boolean)value));
}

- (BOOL)disableDriverFallback {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisableDriverFallback(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setDisableDriverFallback:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisableDriverFallback((boolean)value));
}

@end

@implementation WMDFocusControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IFocusControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WMDFocusPreset */)supportedPresets {
    ComPtr<IVectorView<ABI::Windows::Media::Devices::FocusPreset>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedPresets(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMDFocusPreset_create(unmarshalledReturn.Get());
}

- (WMDFocusPreset)preset {
    ABI::Windows::Media::Devices::FocusPreset unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Preset(&unmarshalledReturn));
    return (WMDFocusPreset)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)setPresetAsync:(WMDFocusPreset)preset {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl>(self);
    THROW_NS_IF_FAILED(_comInst->SetPresetAsync((ABI::Windows::Media::Devices::FocusPreset)preset, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)setPresetWithCompletionOptionAsync:(WMDFocusPreset)preset completeBeforeFocus:(BOOL)completeBeforeFocus {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl>(self);
    THROW_NS_IF_FAILED(_comInst->SetPresetWithCompletionOptionAsync((ABI::Windows::Media::Devices::FocusPreset)preset,
                                                                    (boolean)completeBeforeFocus,
                                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (unsigned int)min {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Min(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)max {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Max(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)step {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Step(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)value {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)setValueAsync:(unsigned int)focus {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl>(self);
    THROW_NS_IF_FAILED(_comInst->SetValueAsync(focus, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)focusAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl>(self);
    THROW_NS_IF_FAILED(_comInst->FocusAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (BOOL)focusChangedSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FocusChangedSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)waitForFocusSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_WaitForFocusSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WMDFocusMode */)supportedFocusModes {
    ComPtr<IVectorView<ABI::Windows::Media::Devices::FocusMode>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedFocusModes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMDFocusMode_create(unmarshalledReturn.Get());
}

- (NSArray* /* WMDManualFocusDistance */)supportedFocusDistances {
    ComPtr<IVectorView<ABI::Windows::Media::Devices::ManualFocusDistance>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedFocusDistances(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMDManualFocusDistance_create(unmarshalledReturn.Get());
}

- (NSArray* /* WMDAutoFocusRange */)supportedFocusRanges {
    ComPtr<IVectorView<ABI::Windows::Media::Devices::AutoFocusRange>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedFocusRanges(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMDAutoFocusRange_create(unmarshalledReturn.Get());
}

- (WMDFocusMode)mode {
    ABI::Windows::Media::Devices::FocusMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WMDFocusMode)unmarshalledReturn;
}

- (WMDMediaCaptureFocusState)focusState {
    ABI::Windows::Media::Devices::MediaCaptureFocusState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FocusState(&unmarshalledReturn));
    return (WMDMediaCaptureFocusState)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)unlockAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl2>(self);
    THROW_NS_IF_FAILED(_comInst->UnlockAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)lockAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl2>(self);
    THROW_NS_IF_FAILED(_comInst->LockAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)configure:(WMDFocusSettings*)settings {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IFocusControl2>(self);
    THROW_NS_IF_FAILED(_comInst->Configure(_getRtInterface<ABI::Windows::Media::Devices::IFocusSettings>(settings).Get()));
}

@end

@implementation WMDRegionOfInterest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IRegionOfInterest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Devices.RegionOfInterest").Get(), &out));
    return [_createRtProxy<WMDRegionOfInterest>(out.Get()) retain];
}

- (BOOL)autoFocusEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionOfInterest>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoFocusEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAutoFocusEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionOfInterest>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoFocusEnabled((boolean)value));
}

- (BOOL)autoWhiteBalanceEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionOfInterest>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoWhiteBalanceEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAutoWhiteBalanceEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionOfInterest>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoWhiteBalanceEnabled((boolean)value));
}

- (BOOL)autoExposureEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionOfInterest>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoExposureEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAutoExposureEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionOfInterest>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoExposureEnabled((boolean)value));
}

- (WFRect*)bounds {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionOfInterest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bounds(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)setBounds:(WFRect*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionOfInterest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Bounds(*[value internalStruct]));
}

- (WMDRegionOfInterestType)type {
    ABI::Windows::Media::Devices::RegionOfInterestType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionOfInterest2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WMDRegionOfInterestType)unmarshalledReturn;
}

- (void)setType:(WMDRegionOfInterestType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionOfInterest2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Type((ABI::Windows::Media::Devices::RegionOfInterestType)value));
}

- (BOOL)boundsNormalized {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionOfInterest2>(self);
    THROW_NS_IF_FAILED(_comInst->get_BoundsNormalized(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setBoundsNormalized:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionOfInterest2>(self);
    THROW_NS_IF_FAILED(_comInst->put_BoundsNormalized((boolean)value));
}

- (unsigned int)weight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionOfInterest2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Weight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setWeight:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionOfInterest2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Weight(value));
}

@end

@implementation WMDRegionsOfInterestControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IRegionsOfInterestControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)maxRegions {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionsOfInterestControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxRegions(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)setRegionsAsync:(id<NSFastEnumeration> /* WMDRegionOfInterest* */)regions {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionsOfInterestControl>(self);
    THROW_NS_IF_FAILED(_comInst->SetRegionsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Media::Devices::RegionOfInterest*,
                                                              ABI::Windows::Media::Devices::IRegionOfInterest*>>::type>*>(
            ConvertToIterable<WMDRegionOfInterest,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Media::Devices::RegionOfInterest*,
                                                                                ABI::Windows::Media::Devices::IRegionOfInterest*>>(regions)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)setRegionsWithLockAsync:(id<NSFastEnumeration> /* WMDRegionOfInterest* */)regions lockValues:(BOOL)lockValues {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionsOfInterestControl>(self);
    THROW_NS_IF_FAILED(_comInst->SetRegionsWithLockAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Media::Devices::RegionOfInterest*,
                                                              ABI::Windows::Media::Devices::IRegionOfInterest*>>::type>*>(
            ConvertToIterable<WMDRegionOfInterest,
                              ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Media::Devices::RegionOfInterest*,
                                                                                ABI::Windows::Media::Devices::IRegionOfInterest*>>(regions)
                .Get()),
        (boolean)lockValues,
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)clearRegionsAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionsOfInterestControl>(self);
    THROW_NS_IF_FAILED(_comInst->ClearRegionsAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (BOOL)autoFocusSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionsOfInterestControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoFocusSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)autoWhiteBalanceSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionsOfInterestControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoWhiteBalanceSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)autoExposureSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRegionsOfInterestControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoExposureSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMDExposurePriorityVideoControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IExposurePriorityVideoControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposurePriorityVideoControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)enabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposurePriorityVideoControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Enabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IExposurePriorityVideoControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Enabled((boolean)value));
}

@end

@implementation WMDHdrVideoControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IHdrVideoControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IHdrVideoControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WMDHdrVideoMode */)supportedModes {
    ComPtr<IVectorView<ABI::Windows::Media::Devices::HdrVideoMode>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IHdrVideoControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedModes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMDHdrVideoMode_create(unmarshalledReturn.Get());
}

- (WMDHdrVideoMode)mode {
    ABI::Windows::Media::Devices::HdrVideoMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IHdrVideoControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WMDHdrVideoMode)unmarshalledReturn;
}

- (void)setMode:(WMDHdrVideoMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IHdrVideoControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mode((ABI::Windows::Media::Devices::HdrVideoMode)value));
}

@end

@implementation WMDAdvancedPhotoCaptureSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IAdvancedPhotoCaptureSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Devices.AdvancedPhotoCaptureSettings").Get(), &out));
    return [_createRtProxy<WMDAdvancedPhotoCaptureSettings>(out.Get()) retain];
}

- (WMDAdvancedPhotoMode)mode {
    ABI::Windows::Media::Devices::AdvancedPhotoMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedPhotoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WMDAdvancedPhotoMode)unmarshalledReturn;
}

- (void)setMode:(WMDAdvancedPhotoMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedPhotoCaptureSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mode((ABI::Windows::Media::Devices::AdvancedPhotoMode)value));
}

@end

@implementation WMDAdvancedPhotoControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IAdvancedPhotoControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedPhotoControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WMDAdvancedPhotoMode */)supportedModes {
    ComPtr<IVectorView<ABI::Windows::Media::Devices::AdvancedPhotoMode>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedPhotoControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedModes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMDAdvancedPhotoMode_create(unmarshalledReturn.Get());
}

- (WMDAdvancedPhotoMode)mode {
    ABI::Windows::Media::Devices::AdvancedPhotoMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedPhotoControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WMDAdvancedPhotoMode)unmarshalledReturn;
}

- (void)configure:(WMDAdvancedPhotoCaptureSettings*)settings {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IAdvancedPhotoControl>(self);
    THROW_NS_IF_FAILED(_comInst->Configure(_getRtInterface<ABI::Windows::Media::Devices::IAdvancedPhotoCaptureSettings>(settings).Get()));
}

@end

@implementation WMDOpticalImageStabilizationControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IOpticalImageStabilizationControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IOpticalImageStabilizationControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WMDOpticalImageStabilizationMode */)supportedModes {
    ComPtr<IVectorView<ABI::Windows::Media::Devices::OpticalImageStabilizationMode>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IOpticalImageStabilizationControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedModes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMDOpticalImageStabilizationMode_create(unmarshalledReturn.Get());
}

- (WMDOpticalImageStabilizationMode)mode {
    ABI::Windows::Media::Devices::OpticalImageStabilizationMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IOpticalImageStabilizationControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WMDOpticalImageStabilizationMode)unmarshalledReturn;
}

- (void)setMode:(WMDOpticalImageStabilizationMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IOpticalImageStabilizationControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mode((ABI::Windows::Media::Devices::OpticalImageStabilizationMode)value));
}

@end

@implementation WMDMediaDeviceControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IMediaDeviceControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMDMediaDeviceControlCapabilities*)capabilities {
    ComPtr<ABI::Windows::Media::Devices::IMediaDeviceControlCapabilities> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Capabilities(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDMediaDeviceControlCapabilities>(unmarshalledReturn.Get());
}

- (BOOL)tryGetValue:(double*)value {
    double valueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceControl>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetValue(&valueOutUnmarshaled, &unmarshalledReturn));
    *value = valueOutUnmarshaled;
    return (BOOL)unmarshalledReturn;
}

- (BOOL)trySetValue:(double)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceControl>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetValue(value, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)tryGetAuto:(BOOL*)value {
    boolean valueOutUnmarshaled;
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceControl>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetAuto(&valueOutUnmarshaled, &unmarshalledReturn));
    *value = (BOOL)valueOutUnmarshaled;
    return (BOOL)unmarshalledReturn;
}

- (BOOL)trySetAuto:(BOOL)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceControl>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetAuto((boolean)value, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMDLowLagPhotoSequenceControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (unsigned int)maxPastPhotos {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPastPhotos(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)maxPhotosPerSecond {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPhotosPerSecond(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)pastPhotoLimit {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_PastPhotoLimit(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPastPhotoLimit:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_PastPhotoLimit(value));
}

- (float)photosPerSecondLimit {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhotosPerSecondLimit(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPhotosPerSecondLimit:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_PhotosPerSecondLimit(value));
}

- (WMMMediaRatio*)getHighestConcurrentFrameRate:(RTObject<WMMIMediaEncodingProperties>*)captureProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaRatio> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl>(self);
    THROW_NS_IF_FAILED(_comInst->GetHighestConcurrentFrameRate(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(captureProperties).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaRatio>(unmarshalledReturn.Get());
}

- (WMMMediaRatio*)getCurrentFrameRate {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaRatio> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentFrameRate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaRatio>(unmarshalledReturn.Get());
}

- (BOOL)thumbnailEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ThumbnailEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setThumbnailEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_ThumbnailEnabled((boolean)value));
}

- (WMMMediaThumbnailFormat)thumbnailFormat {
    ABI::Windows::Media::MediaProperties::MediaThumbnailFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ThumbnailFormat(&unmarshalledReturn));
    return (WMMMediaThumbnailFormat)unmarshalledReturn;
}

- (void)setThumbnailFormat:(WMMMediaThumbnailFormat)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_ThumbnailFormat((ABI::Windows::Media::MediaProperties::MediaThumbnailFormat)value));
}

- (unsigned int)desiredThumbnailSize {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredThumbnailSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDesiredThumbnailSize:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredThumbnailSize(value));
}

- (unsigned int)hardwareAcceleratedThumbnailSupported {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoSequenceControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_HardwareAcceleratedThumbnailSupported(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMDLowLagPhotoControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::ILowLagPhotoControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMMMediaRatio*)getHighestConcurrentFrameRate:(RTObject<WMMIMediaEncodingProperties>*)captureProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaRatio> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoControl>(self);
    THROW_NS_IF_FAILED(_comInst->GetHighestConcurrentFrameRate(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(captureProperties).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaRatio>(unmarshalledReturn.Get());
}

- (WMMMediaRatio*)getCurrentFrameRate {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaRatio> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoControl>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentFrameRate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaRatio>(unmarshalledReturn.Get());
}

- (BOOL)thumbnailEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ThumbnailEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setThumbnailEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_ThumbnailEnabled((boolean)value));
}

- (WMMMediaThumbnailFormat)thumbnailFormat {
    ABI::Windows::Media::MediaProperties::MediaThumbnailFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_ThumbnailFormat(&unmarshalledReturn));
    return (WMMMediaThumbnailFormat)unmarshalledReturn;
}

- (void)setThumbnailFormat:(WMMMediaThumbnailFormat)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_ThumbnailFormat((ABI::Windows::Media::MediaProperties::MediaThumbnailFormat)value));
}

- (unsigned int)desiredThumbnailSize {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredThumbnailSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDesiredThumbnailSize:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredThumbnailSize(value));
}

- (unsigned int)hardwareAcceleratedThumbnailSupported {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ILowLagPhotoControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_HardwareAcceleratedThumbnailSupported(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMDPhotoConfirmationControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IPhotoConfirmationControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IPhotoConfirmationControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)enabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IPhotoConfirmationControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Enabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IPhotoConfirmationControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Enabled((boolean)value));
}

- (WMMMediaPixelFormat)pixelFormat {
    ABI::Windows::Media::MediaProperties::MediaPixelFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IPhotoConfirmationControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelFormat(&unmarshalledReturn));
    return (WMMMediaPixelFormat)unmarshalledReturn;
}

- (void)setPixelFormat:(WMMMediaPixelFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IPhotoConfirmationControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_PixelFormat((ABI::Windows::Media::MediaProperties::MediaPixelFormat)format));
}

@end

@implementation WMDMediaDeviceControlCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IMediaDeviceControlCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceControlCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)min {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceControlCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Min(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)max {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceControlCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Max(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)step {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceControlCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Step(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)Default {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceControlCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Default(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)autoModeSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IMediaDeviceControlCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoModeSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMDDialRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IDialRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)handled {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IDialRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->Handled());
}

- (RTObject*)contact {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IDialRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Contact(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WMDRedialRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IRedialRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)handled {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IRedialRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->Handled());
}

@end

@implementation WMDKeypadPressedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::IKeypadPressedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMDTelephonyKey)telephonyKey {
    ABI::Windows::Media::Devices::TelephonyKey unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::IKeypadPressedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TelephonyKey(&unmarshalledReturn));
    return (WMDTelephonyKey)unmarshalledReturn;
}

@end

@implementation WMDCallControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::ICallControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::Devices::ICallControlStatics> WMDICallControlStatics_inst() {
    ComPtr<ABI::Windows::Media::Devices::ICallControlStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Devices.CallControl").Get(), &inst));
    return inst;
}

+ (WMDCallControl*)getDefault {
    ComPtr<ABI::Windows::Media::Devices::ICallControl> unmarshalledReturn;
    auto _comInst = WMDICallControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCallControl>(unmarshalledReturn.Get());
}

+ (WMDCallControl*)fromId:(NSString*)deviceId {
    ComPtr<ABI::Windows::Media::Devices::ICallControl> unmarshalledReturn;
    auto _comInst = WMDICallControlStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromId(nsStrToHstr(deviceId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCallControl>(unmarshalledReturn.Get());
}

- (uint64_t)indicateNewIncomingCall:(BOOL)enableRinger callerId:(NSString*)callerId {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->IndicateNewIncomingCall((boolean)enableRinger, nsStrToHstr(callerId).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)indicateNewOutgoingCall {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->IndicateNewOutgoingCall(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)indicateActiveCall:(uint64_t)callToken {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->IndicateActiveCall(callToken));
}

- (void)endCall:(uint64_t)callToken {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->EndCall(callToken));
}

- (BOOL)hasRinger {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasRinger(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addAnswerRequestedEvent:(WMDCallControlEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->add_AnswerRequested(Make<WMDCallControlEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAnswerRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AnswerRequested(token));
}

- (EventRegistrationToken)addHangUpRequestedEvent:(WMDCallControlEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->add_HangUpRequested(Make<WMDCallControlEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHangUpRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HangUpRequested(token));
}

- (EventRegistrationToken)addDialRequestedEvent:(WMDDialRequestedEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->add_DialRequested(Make<WMDDialRequestedEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDialRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DialRequested(token));
}

- (EventRegistrationToken)addRedialRequestedEvent:(WMDRedialRequestedEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->add_RedialRequested(Make<WMDRedialRequestedEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRedialRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RedialRequested(token));
}

- (EventRegistrationToken)addKeypadPressedEvent:(WMDKeypadPressedEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->add_KeypadPressed(Make<WMDKeypadPressedEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeKeypadPressedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->remove_KeypadPressed(token));
}

- (EventRegistrationToken)addAudioTransferRequestedEvent:(WMDCallControlEventHandler)handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->add_AudioTransferRequested(Make<WMDCallControlEventHandler_shim>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAudioTransferRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::ICallControl>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AudioTransferRequested(token));
}

@end

id RTProxiedIterableNSArray_WMDRegionOfInterest_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Media::Devices::RegionOfInterest*>,
                                                 RTIterableObj<ABI::Windows::Media::Devices::IRegionOfInterest*,
                                                               IIterable<ABI::Windows::Media::Devices::RegionOfInterest*>,
                                                               WMDRegionOfInterest,
                                                               ABI::Windows::Media::Devices::RegionOfInterest*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_RTObject_WMMIMediaEncodingProperties_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties*>,
                                         RTArrayObj<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties*,
                                                    IVectorView<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties*>,
                                                    RTObject<WMMIMediaEncodingProperties>,
                                                    ABI::Windows::Media::MediaProperties::IMediaEncodingProperties*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMDAdvancedPhotoMode_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Devices::AdvancedPhotoMode>,
                                         RTArrayObj<ABI::Windows::Media::Devices::AdvancedPhotoMode,
                                                    IVectorView<ABI::Windows::Media::Devices::AdvancedPhotoMode>,
                                                    WMDAdvancedPhotoMode,
                                                    ABI::Windows::Media::Devices::AdvancedPhotoMode,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMDAutoFocusRange_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Devices::AutoFocusRange>,
                                         RTArrayObj<ABI::Windows::Media::Devices::AutoFocusRange,
                                                    IVectorView<ABI::Windows::Media::Devices::AutoFocusRange>,
                                                    WMDAutoFocusRange,
                                                    ABI::Windows::Media::Devices::AutoFocusRange,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMDCaptureSceneMode_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Devices::CaptureSceneMode>,
                                         RTArrayObj<ABI::Windows::Media::Devices::CaptureSceneMode,
                                                    IVectorView<ABI::Windows::Media::Devices::CaptureSceneMode>,
                                                    WMDCaptureSceneMode,
                                                    ABI::Windows::Media::Devices::CaptureSceneMode,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMDFocusMode_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Devices::FocusMode>,
                                         RTArrayObj<ABI::Windows::Media::Devices::FocusMode,
                                                    IVectorView<ABI::Windows::Media::Devices::FocusMode>,
                                                    WMDFocusMode,
                                                    ABI::Windows::Media::Devices::FocusMode,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMDFocusPreset_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Devices::FocusPreset>,
                                         RTArrayObj<ABI::Windows::Media::Devices::FocusPreset,
                                                    IVectorView<ABI::Windows::Media::Devices::FocusPreset>,
                                                    WMDFocusPreset,
                                                    ABI::Windows::Media::Devices::FocusPreset,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMDHdrVideoMode_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Devices::HdrVideoMode>,
                                         RTArrayObj<ABI::Windows::Media::Devices::HdrVideoMode,
                                                    IVectorView<ABI::Windows::Media::Devices::HdrVideoMode>,
                                                    WMDHdrVideoMode,
                                                    ABI::Windows::Media::Devices::HdrVideoMode,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMDIsoSpeedPreset_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Devices::IsoSpeedPreset>,
                                         RTArrayObj<ABI::Windows::Media::Devices::IsoSpeedPreset,
                                                    IVectorView<ABI::Windows::Media::Devices::IsoSpeedPreset>,
                                                    WMDIsoSpeedPreset,
                                                    ABI::Windows::Media::Devices::IsoSpeedPreset,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMDManualFocusDistance_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Devices::ManualFocusDistance>,
                                         RTArrayObj<ABI::Windows::Media::Devices::ManualFocusDistance,
                                                    IVectorView<ABI::Windows::Media::Devices::ManualFocusDistance>,
                                                    WMDManualFocusDistance,
                                                    ABI::Windows::Media::Devices::ManualFocusDistance,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMDOpticalImageStabilizationMode_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Devices::OpticalImageStabilizationMode>,
                                         RTArrayObj<ABI::Windows::Media::Devices::OpticalImageStabilizationMode,
                                                    IVectorView<ABI::Windows::Media::Devices::OpticalImageStabilizationMode>,
                                                    WMDOpticalImageStabilizationMode,
                                                    ABI::Windows::Media::Devices::OpticalImageStabilizationMode,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMDZoomTransitionMode_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Devices::ZoomTransitionMode>,
                                         RTArrayObj<ABI::Windows::Media::Devices::ZoomTransitionMode,
                                                    IVectorView<ABI::Windows::Media::Devices::ZoomTransitionMode>,
                                                    WMDZoomTransitionMode,
                                                    ABI::Windows::Media::Devices::ZoomTransitionMode,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
