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

// WindowsMedia.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMedia.h"
#include "WindowsMedia_priv.h"

@implementation WMIMediaFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IMediaFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@implementation WMIMediaMarker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IMediaMarker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFTimeSpan*)time {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaMarker>(self);
    THROW_NS_IF_FAILED(_comInst->get_Time(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (NSString*)mediaMarkerType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaMarker>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaMarkerType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaMarker>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMIMediaMarkers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IMediaMarkers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* RTObject<WMIMediaMarker>* */)markers {
    ComPtr<IVectorView<ABI::Windows::Media::IMediaMarker*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaMarkers>(self);
    THROW_NS_IF_FAILED(_comInst->get_Markers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_WMIMediaMarker_create(unmarshalledReturn.Get());
}

@end

@implementation WMIMediaExtension

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IMediaExtension> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtension>(self);
    THROW_NS_IF_FAILED(_comInst->SetProperties(_getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get()));
}

@end

@implementation WMMediaProcessingTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IMediaProcessingTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFCValueSet*)arguments {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaProcessingTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Arguments(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

@end

@implementation WMVideoFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IVideoFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::IVideoFrameFactory> WMIVideoFrameFactory_inst() {
    ComPtr<ABI::Windows::Media::IVideoFrameFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.VideoFrame").Get(), &inst));
    return inst;
}

+ (WMVideoFrame*)make:(WGIBitmapPixelFormat)format width:(int)width height:(int)height {
    ComPtr<ABI::Windows::Media::IVideoFrame> unmarshalledReturn;
    auto _comInst = WMIVideoFrameFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)format, width, height, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMVideoFrame>(unmarshalledReturn.Get()) retain];
}

+ (WMVideoFrame*)makeWithAlpha:(WGIBitmapPixelFormat)format width:(int)width height:(int)height alpha:(WGIBitmapAlphaMode)alpha {
    ComPtr<ABI::Windows::Media::IVideoFrame> unmarshalledReturn;
    auto _comInst = WMIVideoFrameFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithAlpha((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)format,
                                                 width,
                                                 height,
                                                 (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alpha,
                                                 unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMVideoFrame>(unmarshalledReturn.Get()) retain];
}

- (WGISoftwareBitmap*)softwareBitmap {
    ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IVideoFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_SoftwareBitmap(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGISoftwareBitmap>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)copyToAsync:(WMVideoFrame*)frame __attribute__((ns_returns_not_retained)) {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IVideoFrame>(self);
    THROW_NS_IF_FAILED(
        _comInst->CopyToAsync(_getRtInterface<ABI::Windows::Media::IVideoFrame>(frame).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WGDDIDirect3DSurface>*)direct3DSurface {
    ComPtr<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IVideoFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_Direct3DSurface(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGDDIDirect3DSurface>(unmarshalledReturn.Get());
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

@implementation WMAudioBuffer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IAudioBuffer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)capacity {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IAudioBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Capacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)length {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IAudioBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLength:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IAudioBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->put_Length(value));
}

- (RTObject<WFIMemoryBufferReference>*)createReference {
    ComPtr<ABI::Windows::Foundation::IMemoryBufferReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IMemoryBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->CreateReference(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIMemoryBufferReference>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMAudioFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IAudioFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::IAudioFrameFactory> WMIAudioFrameFactory_inst() {
    ComPtr<ABI::Windows::Media::IAudioFrameFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.AudioFrame").Get(), &inst));
    return inst;
}

+ (WMAudioFrame*)make:(unsigned int)capacity {
    ComPtr<ABI::Windows::Media::IAudioFrame> unmarshalledReturn;
    auto _comInst = WMIAudioFrameFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(capacity, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMAudioFrame>(unmarshalledReturn.Get()) retain];
}

- (WMAudioBuffer*)lockBuffer:(WMAudioBufferAccessMode)mode {
    ComPtr<ABI::Windows::Media::IAudioBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IAudioFrame>(self);
    THROW_NS_IF_FAILED(_comInst->LockBuffer((ABI::Windows::Media::AudioBufferAccessMode)mode, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAudioBuffer>(unmarshalledReturn.Get());
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

@implementation WMMediaMarkerTypes

ComPtr<ABI::Windows::Media::IMediaMarkerTypesStatics> WMIMediaMarkerTypesStatics_inst() {
    ComPtr<ABI::Windows::Media::IMediaMarkerTypesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.MediaMarkerTypes").Get(), &inst));
    return inst;
}

+ (NSString*)bookmark {
    HSTRING unmarshalledReturn;
    auto _comInst = WMIMediaMarkerTypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Bookmark(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMSystemMediaTransportControlsTimelineProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::ISystemMediaTransportControlsTimelineProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.SystemMediaTransportControlsTimelineProperties").Get(),
                                              &out));
    return [_createRtProxy<WMSystemMediaTransportControlsTimelineProperties>(out.Get()) retain];
}

- (WFTimeSpan*)startTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsTimelineProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setStartTime:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsTimelineProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartTime(*[value internalStruct]));
}

- (WFTimeSpan*)endTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsTimelineProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setEndTime:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsTimelineProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_EndTime(*[value internalStruct]));
}

- (WFTimeSpan*)minSeekTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsTimelineProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinSeekTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setMinSeekTime:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsTimelineProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_MinSeekTime(*[value internalStruct]));
}

- (WFTimeSpan*)maxSeekTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsTimelineProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxSeekTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setMaxSeekTime:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsTimelineProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxSeekTime(*[value internalStruct]));
}

- (WFTimeSpan*)position {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsTimelineProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setPosition:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsTimelineProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Position(*[value internalStruct]));
}

@end

@implementation WMMusicDisplayProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IMusicDisplayProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMusicDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMusicDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (NSString*)albumArtist {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMusicDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlbumArtist(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAlbumArtist:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMusicDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_AlbumArtist(nsStrToHstr(value).Get()));
}

- (NSString*)artist {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMusicDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Artist(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setArtist:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMusicDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Artist(nsStrToHstr(value).Get()));
}

- (NSString*)albumTitle {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMusicDisplayProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlbumTitle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAlbumTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMusicDisplayProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AlbumTitle(nsStrToHstr(value).Get()));
}

- (unsigned int)trackNumber {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMusicDisplayProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrackNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTrackNumber:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMusicDisplayProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->put_TrackNumber(value));
}

- (NSMutableArray* /* NSString * */)genres {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMusicDisplayProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Genres(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (unsigned int)albumTrackCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMusicDisplayProperties3>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlbumTrackCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setAlbumTrackCount:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMusicDisplayProperties3>(self);
    THROW_NS_IF_FAILED(_comInst->put_AlbumTrackCount(value));
}

@end

@implementation WMVideoDisplayProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IVideoDisplayProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IVideoDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IVideoDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (NSString*)subtitle {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IVideoDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subtitle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSubtitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IVideoDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Subtitle(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* NSString * */)genres {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IVideoDisplayProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Genres(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WMImageDisplayProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IImageDisplayProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IImageDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IImageDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (NSString*)subtitle {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IImageDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subtitle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSubtitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IImageDisplayProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Subtitle(nsStrToHstr(value).Get()));
}

@end

@implementation WMSystemMediaTransportControlsDisplayUpdater

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::ISystemMediaTransportControlsDisplayUpdater> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMMediaPlaybackType)type {
    ABI::Windows::Media::MediaPlaybackType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsDisplayUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WMMediaPlaybackType)unmarshalledReturn;
}

- (void)setType:(WMMediaPlaybackType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsDisplayUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->put_Type((ABI::Windows::Media::MediaPlaybackType)value));
}

- (NSString*)appMediaId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsDisplayUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppMediaId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAppMediaId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsDisplayUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->put_AppMediaId(nsStrToHstr(value).Get()));
}

- (WSSRandomAccessStreamReference*)thumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsDisplayUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setThumbnail:(WSSRandomAccessStreamReference*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsDisplayUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->put_Thumbnail(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (WMMusicDisplayProperties*)musicProperties {
    ComPtr<ABI::Windows::Media::IMusicDisplayProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsDisplayUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->get_MusicProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMusicDisplayProperties>(unmarshalledReturn.Get());
}

- (WMVideoDisplayProperties*)videoProperties {
    ComPtr<ABI::Windows::Media::IVideoDisplayProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsDisplayUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMVideoDisplayProperties>(unmarshalledReturn.Get());
}

- (WMImageDisplayProperties*)imageProperties {
    ComPtr<ABI::Windows::Media::IImageDisplayProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsDisplayUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImageProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMImageDisplayProperties>(unmarshalledReturn.Get());
}

- (void)copyFromFileAsync:(WMMediaPlaybackType)type
                   source:(WSStorageFile*)source
                  success:(void (^)(BOOL))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsDisplayUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->CopyFromFileAsync((ABI::Windows::Media::MediaPlaybackType)type,
                                                   _getRtInterface<ABI::Windows::Storage::IStorageFile>(source).Get(),
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

- (void)clearAll {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsDisplayUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->ClearAll());
}

- (void)update {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsDisplayUpdater>(self);
    THROW_NS_IF_FAILED(_comInst->Update());
}

@end

@implementation WMSystemMediaTransportControlsButtonPressedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::ISystemMediaTransportControlsButtonPressedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMSystemMediaTransportControlsButton)button {
    ABI::Windows::Media::SystemMediaTransportControlsButton unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsButtonPressedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Button(&unmarshalledReturn));
    return (WMSystemMediaTransportControlsButton)unmarshalledReturn;
}

@end

@implementation WMSystemMediaTransportControlsPropertyChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::ISystemMediaTransportControlsPropertyChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMSystemMediaTransportControlsProperty)property {
    ABI::Windows::Media::SystemMediaTransportControlsProperty unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControlsPropertyChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Property(&unmarshalledReturn));
    return (WMSystemMediaTransportControlsProperty)unmarshalledReturn;
}

@end

@implementation WMPlaybackPositionChangeRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IPlaybackPositionChangeRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFTimeSpan*)requestedPlaybackPosition {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IPlaybackPositionChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestedPlaybackPosition(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

@end

@implementation WMPlaybackRateChangeRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IPlaybackRateChangeRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)requestedPlaybackRate {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IPlaybackRateChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestedPlaybackRate(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMShuffleEnabledChangeRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IShuffleEnabledChangeRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)requestedShuffleEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IShuffleEnabledChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestedShuffleEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMAutoRepeatModeChangeRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IAutoRepeatModeChangeRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMMediaPlaybackAutoRepeatMode)requestedAutoRepeatMode {
    ABI::Windows::Media::MediaPlaybackAutoRepeatMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IAutoRepeatModeChangeRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestedAutoRepeatMode(&unmarshalledReturn));
    return (WMMediaPlaybackAutoRepeatMode)unmarshalledReturn;
}

@end

@implementation WMSystemMediaTransportControls

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::ISystemMediaTransportControls> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::ISystemMediaTransportControlsStatics> WMISystemMediaTransportControlsStatics_inst() {
    ComPtr<ABI::Windows::Media::ISystemMediaTransportControlsStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.SystemMediaTransportControls").Get(), &inst));
    return inst;
}

+ (WMSystemMediaTransportControls*)getForCurrentView {
    ComPtr<ABI::Windows::Media::ISystemMediaTransportControls> unmarshalledReturn;
    auto _comInst = WMISystemMediaTransportControlsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMSystemMediaTransportControls>(unmarshalledReturn.Get());
}

- (WMMediaPlaybackStatus)playbackStatus {
    ABI::Windows::Media::MediaPlaybackStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackStatus(&unmarshalledReturn));
    return (WMMediaPlaybackStatus)unmarshalledReturn;
}

- (void)setPlaybackStatus:(WMMediaPlaybackStatus)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->put_PlaybackStatus((ABI::Windows::Media::MediaPlaybackStatus)value));
}

- (WMSystemMediaTransportControlsDisplayUpdater*)displayUpdater {
    ComPtr<ABI::Windows::Media::ISystemMediaTransportControlsDisplayUpdater> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayUpdater(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMSystemMediaTransportControlsDisplayUpdater>(unmarshalledReturn.Get());
}

- (WMSoundLevel)soundLevel {
    ABI::Windows::Media::SoundLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->get_SoundLevel(&unmarshalledReturn));
    return (WMSoundLevel)unmarshalledReturn;
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsEnabled((boolean)value));
}

- (BOOL)isPlayEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPlayEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsPlayEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsPlayEnabled((boolean)value));
}

- (BOOL)isStopEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStopEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsStopEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsStopEnabled((boolean)value));
}

- (BOOL)isPauseEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPauseEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsPauseEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsPauseEnabled((boolean)value));
}

- (BOOL)isRecordEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsRecordEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsRecordEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsRecordEnabled((boolean)value));
}

- (BOOL)isFastForwardEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsFastForwardEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsFastForwardEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsFastForwardEnabled((boolean)value));
}

- (BOOL)isRewindEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsRewindEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsRewindEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsRewindEnabled((boolean)value));
}

- (BOOL)isPreviousEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPreviousEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsPreviousEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsPreviousEnabled((boolean)value));
}

- (BOOL)isNextEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsNextEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsNextEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsNextEnabled((boolean)value));
}

- (BOOL)isChannelUpEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsChannelUpEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsChannelUpEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsChannelUpEnabled((boolean)value));
}

- (BOOL)isChannelDownEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsChannelDownEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsChannelDownEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsChannelDownEnabled((boolean)value));
}

- (EventRegistrationToken)addButtonPressedEvent:(void (^)(WMSystemMediaTransportControls*,
                                                          WMSystemMediaTransportControlsButtonPressedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->add_ButtonPressed(
        Make<
            ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_SystemMediaTransportControlsButtonPressedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeButtonPressedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ButtonPressed(token));
}

- (EventRegistrationToken)addPropertyChangedEvent:(void (^)(WMSystemMediaTransportControls*,
                                                            WMSystemMediaTransportControlsPropertyChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->add_PropertyChanged(
        Make<
            ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_SystemMediaTransportControlsPropertyChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePropertyChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PropertyChanged(token));
}

- (WMMediaPlaybackAutoRepeatMode)autoRepeatMode {
    ABI::Windows::Media::MediaPlaybackAutoRepeatMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoRepeatMode(&unmarshalledReturn));
    return (WMMediaPlaybackAutoRepeatMode)unmarshalledReturn;
}

- (void)setAutoRepeatMode:(WMMediaPlaybackAutoRepeatMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoRepeatMode((ABI::Windows::Media::MediaPlaybackAutoRepeatMode)value));
}

- (BOOL)shuffleEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShuffleEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setShuffleEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ShuffleEnabled((boolean)value));
}

- (double)playbackRate {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackRate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPlaybackRate:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls2>(self);
    THROW_NS_IF_FAILED(_comInst->put_PlaybackRate(value));
}

- (void)updateTimelineProperties:(WMSystemMediaTransportControlsTimelineProperties*)timelineProperties {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls2>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateTimelineProperties(
        _getRtInterface<ABI::Windows::Media::ISystemMediaTransportControlsTimelineProperties>(timelineProperties).Get()));
}

- (EventRegistrationToken)addPlaybackPositionChangeRequestedEvent:(void (^)(WMSystemMediaTransportControls*,
                                                                            WMPlaybackPositionChangeRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls2>(self);
    THROW_NS_IF_FAILED(_comInst->add_PlaybackPositionChangeRequested(
        Make<ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_PlaybackPositionChangeRequestedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePlaybackPositionChangeRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PlaybackPositionChangeRequested(token));
}

- (EventRegistrationToken)addPlaybackRateChangeRequestedEvent:(void (^)(WMSystemMediaTransportControls*,
                                                                        WMPlaybackRateChangeRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls2>(self);
    THROW_NS_IF_FAILED(_comInst->add_PlaybackRateChangeRequested(
        Make<ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_PlaybackRateChangeRequestedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePlaybackRateChangeRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PlaybackRateChangeRequested(token));
}

- (EventRegistrationToken)addShuffleEnabledChangeRequestedEvent:(void (^)(WMSystemMediaTransportControls*,
                                                                          WMShuffleEnabledChangeRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls2>(self);
    THROW_NS_IF_FAILED(_comInst->add_ShuffleEnabledChangeRequested(
        Make<ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_ShuffleEnabledChangeRequestedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeShuffleEnabledChangeRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ShuffleEnabledChangeRequested(token));
}

- (EventRegistrationToken)addAutoRepeatModeChangeRequestedEvent:(void (^)(WMSystemMediaTransportControls*,
                                                                          WMAutoRepeatModeChangeRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls2>(self);
    THROW_NS_IF_FAILED(_comInst->add_AutoRepeatModeChangeRequested(
        Make<ITypedEventHandler_Windows_Media_SystemMediaTransportControls_Windows_Media_AutoRepeatModeChangeRequestedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAutoRepeatModeChangeRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::ISystemMediaTransportControls2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AutoRepeatModeChangeRequested(token));
}

@end

@implementation WMMediaExtensionManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IMediaExtensionManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.MediaExtensionManager").Get(), &out));
    return [_createRtProxy<WMMediaExtensionManager>(out.Get()) retain];
}

- (void)registerSchemeHandler:(NSString*)activatableClassId scheme:(NSString*)scheme {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtensionManager>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterSchemeHandler(nsStrToHstr(activatableClassId).Get(), nsStrToHstr(scheme).Get()));
}

- (void)registerSchemeHandlerWithSettings:(NSString*)activatableClassId
                                   scheme:(NSString*)scheme
                            configuration:(RTObject<WFCIPropertySet>*)configuration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtensionManager>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterSchemeHandlerWithSettings(
        nsStrToHstr(activatableClassId).Get(),
        nsStrToHstr(scheme).Get(),
        _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get()));
}

- (void)registerByteStreamHandler:(NSString*)activatableClassId fileExtension:(NSString*)fileExtension mimeType:(NSString*)mimeType {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtensionManager>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterByteStreamHandler(nsStrToHstr(activatableClassId).Get(),
                                                           nsStrToHstr(fileExtension).Get(),
                                                           nsStrToHstr(mimeType).Get()));
}

- (void)registerByteStreamHandlerWithSettings:(NSString*)activatableClassId
                                fileExtension:(NSString*)fileExtension
                                     mimeType:(NSString*)mimeType
                                configuration:(RTObject<WFCIPropertySet>*)configuration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtensionManager>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterByteStreamHandlerWithSettings(
        nsStrToHstr(activatableClassId).Get(),
        nsStrToHstr(fileExtension).Get(),
        nsStrToHstr(mimeType).Get(),
        _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get()));
}

- (void)registerAudioDecoder:(NSString*)activatableClassId inputSubtype:(WFGUID*)inputSubtype outputSubtype:(WFGUID*)outputSubtype {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtensionManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->RegisterAudioDecoder(nsStrToHstr(activatableClassId).Get(), inputSubtype.guidValue, outputSubtype.guidValue));
}

- (void)registerAudioDecoderWithSettings:(NSString*)activatableClassId
                            inputSubtype:(WFGUID*)inputSubtype
                           outputSubtype:(WFGUID*)outputSubtype
                           configuration:(RTObject<WFCIPropertySet>*)configuration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtensionManager>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterAudioDecoderWithSettings(
        nsStrToHstr(activatableClassId).Get(),
        inputSubtype.guidValue,
        outputSubtype.guidValue,
        _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get()));
}

- (void)registerAudioEncoder:(NSString*)activatableClassId inputSubtype:(WFGUID*)inputSubtype outputSubtype:(WFGUID*)outputSubtype {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtensionManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->RegisterAudioEncoder(nsStrToHstr(activatableClassId).Get(), inputSubtype.guidValue, outputSubtype.guidValue));
}

- (void)registerAudioEncoderWithSettings:(NSString*)activatableClassId
                            inputSubtype:(WFGUID*)inputSubtype
                           outputSubtype:(WFGUID*)outputSubtype
                           configuration:(RTObject<WFCIPropertySet>*)configuration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtensionManager>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterAudioEncoderWithSettings(
        nsStrToHstr(activatableClassId).Get(),
        inputSubtype.guidValue,
        outputSubtype.guidValue,
        _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get()));
}

- (void)registerVideoDecoder:(NSString*)activatableClassId inputSubtype:(WFGUID*)inputSubtype outputSubtype:(WFGUID*)outputSubtype {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtensionManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->RegisterVideoDecoder(nsStrToHstr(activatableClassId).Get(), inputSubtype.guidValue, outputSubtype.guidValue));
}

- (void)registerVideoDecoderWithSettings:(NSString*)activatableClassId
                            inputSubtype:(WFGUID*)inputSubtype
                           outputSubtype:(WFGUID*)outputSubtype
                           configuration:(RTObject<WFCIPropertySet>*)configuration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtensionManager>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterVideoDecoderWithSettings(
        nsStrToHstr(activatableClassId).Get(),
        inputSubtype.guidValue,
        outputSubtype.guidValue,
        _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get()));
}

- (void)registerVideoEncoder:(NSString*)activatableClassId inputSubtype:(WFGUID*)inputSubtype outputSubtype:(WFGUID*)outputSubtype {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtensionManager>(self);
    THROW_NS_IF_FAILED(
        _comInst->RegisterVideoEncoder(nsStrToHstr(activatableClassId).Get(), inputSubtype.guidValue, outputSubtype.guidValue));
}

- (void)registerVideoEncoderWithSettings:(NSString*)activatableClassId
                            inputSubtype:(WFGUID*)inputSubtype
                           outputSubtype:(WFGUID*)outputSubtype
                           configuration:(RTObject<WFCIPropertySet>*)configuration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtensionManager>(self);
    THROW_NS_IF_FAILED(_comInst->RegisterVideoEncoderWithSettings(
        nsStrToHstr(activatableClassId).Get(),
        inputSubtype.guidValue,
        outputSubtype.guidValue,
        _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get()));
}

@end

@implementation WMVideoEffects

ComPtr<ABI::Windows::Media::IVideoEffectsStatics> WMIVideoEffectsStatics_inst() {
    ComPtr<ABI::Windows::Media::IVideoEffectsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.VideoEffects").Get(), &inst));
    return inst;
}

+ (NSString*)videoStabilization {
    HSTRING unmarshalledReturn;
    auto _comInst = WMIVideoEffectsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VideoStabilization(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMMediaTimelineController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::IMediaTimelineController> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.MediaTimelineController").Get(), &out));
    return [_createRtProxy<WMMediaTimelineController>(out.Get()) retain];
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaTimelineController>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)resume {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaTimelineController>(self);
    THROW_NS_IF_FAILED(_comInst->Resume());
}

- (void)pause {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaTimelineController>(self);
    THROW_NS_IF_FAILED(_comInst->Pause());
}

- (WFTimeSpan*)position {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaTimelineController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setPosition:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaTimelineController>(self);
    THROW_NS_IF_FAILED(_comInst->put_Position(*[value internalStruct]));
}

- (double)clockRate {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaTimelineController>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClockRate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setClockRate:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaTimelineController>(self);
    THROW_NS_IF_FAILED(_comInst->put_ClockRate(value));
}

- (WMMediaTimelineControllerState)state {
    ABI::Windows::Media::MediaTimelineControllerState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaTimelineController>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WMMediaTimelineControllerState)unmarshalledReturn;
}

- (EventRegistrationToken)addPositionChangedEvent:(void (^)(WMMediaTimelineController*, RTObject*))positionChangedEventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaTimelineController>(self);
    THROW_NS_IF_FAILED(_comInst->add_PositionChanged(
        Make<ITypedEventHandler_Windows_Media_MediaTimelineController_System_Object>(positionChangedEventHandler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePositionChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaTimelineController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PositionChanged(eventCookie));
}

- (EventRegistrationToken)addStateChangedEvent:(void (^)(WMMediaTimelineController*, RTObject*))stateChangedEventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaTimelineController>(self);
    THROW_NS_IF_FAILED(_comInst->add_StateChanged(
        Make<ITypedEventHandler_Windows_Media_MediaTimelineController_System_Object>(stateChangedEventHandler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStateChangedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaTimelineController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StateChanged(eventCookie));
}

@end

@implementation WMMediaControl

ComPtr<ABI::Windows::Media::IMediaControl> WMIMediaControl_inst() {
    ComPtr<ABI::Windows::Media::IMediaControl> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.MediaControl").Get(), &inst));
    return inst;
}

+ (EventRegistrationToken)addSoundLevelChangedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->add_SoundLevelChanged(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeSoundLevelChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->remove_SoundLevelChanged(cookie));
}

+ (EventRegistrationToken)addPlayPressedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->add_PlayPressed(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removePlayPressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->remove_PlayPressed(cookie));
}

+ (EventRegistrationToken)addPausePressedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->add_PausePressed(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removePausePressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->remove_PausePressed(cookie));
}

+ (EventRegistrationToken)addStopPressedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->add_StopPressed(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeStopPressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->remove_StopPressed(cookie));
}

+ (EventRegistrationToken)addPlayPauseTogglePressedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->add_PlayPauseTogglePressed(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removePlayPauseTogglePressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->remove_PlayPauseTogglePressed(cookie));
}

+ (EventRegistrationToken)addRecordPressedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->add_RecordPressed(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeRecordPressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->remove_RecordPressed(cookie));
}

+ (EventRegistrationToken)addNextTrackPressedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->add_NextTrackPressed(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeNextTrackPressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->remove_NextTrackPressed(cookie));
}

+ (EventRegistrationToken)addPreviousTrackPressedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->add_PreviousTrackPressed(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removePreviousTrackPressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->remove_PreviousTrackPressed(cookie));
}

+ (EventRegistrationToken)addFastForwardPressedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->add_FastForwardPressed(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeFastForwardPressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->remove_FastForwardPressed(cookie));
}

+ (EventRegistrationToken)addRewindPressedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->add_RewindPressed(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeRewindPressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->remove_RewindPressed(cookie));
}

+ (EventRegistrationToken)addChannelUpPressedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->add_ChannelUpPressed(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeChannelUpPressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->remove_ChannelUpPressed(cookie));
}

+ (EventRegistrationToken)addChannelDownPressedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->add_ChannelDownPressed(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeChannelDownPressedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->remove_ChannelDownPressed(cookie));
}

+ (WMSoundLevel)soundLevel {
    ABI::Windows::Media::SoundLevel unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->get_SoundLevel(&unmarshalledReturn));
    return (WMSoundLevel)unmarshalledReturn;
}

+ (void)setTrackName:(NSString*)value {
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->put_TrackName(nsStrToHstr(value).Get()));
}

+ (NSString*)trackName {
    HSTRING unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->get_TrackName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setArtistName:(NSString*)value {
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->put_ArtistName(nsStrToHstr(value).Get()));
}

+ (NSString*)artistName {
    HSTRING unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->get_ArtistName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setIsPlaying:(BOOL)value {
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->put_IsPlaying((boolean)value));
}

+ (BOOL)isPlaying {
    boolean unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsPlaying(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setAlbumArt:(WFUri*)value {
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->put_AlbumArt(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

+ (WFUri*)albumArt {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = WMIMediaControl_inst();
    THROW_NS_IF_FAILED(_comInst->get_AlbumArt(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_RTObject_WMIMediaMarker_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::IMediaMarker*>,
                                                                             RTArrayObj<ABI::Windows::Media::IMediaMarker*,
                                                                                        IVectorView<ABI::Windows::Media::IMediaMarker*>,
                                                                                        RTObject<WMIMediaMarker>,
                                                                                        ABI::Windows::Media::IMediaMarker*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
