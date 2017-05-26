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

// WindowsMediaMediaProperties.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.MediaProperties.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaMediaProperties.h"
#include "WindowsMediaMediaProperties_priv.h"

@implementation WMMIMediaEncodingProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMMMediaPropertySet*)properties {
    ComPtr<IMap<GUID, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaPropertySet>(unmarshalledReturn.Get());
}

- (NSString*)type {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSubtype:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Subtype(nsStrToHstr(value).Get()));
}

- (NSString*)subtype {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subtype(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMMMediaRatio

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaRatio> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setNumerator:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaRatio>(self);
    THROW_NS_IF_FAILED(_comInst->put_Numerator(value));
}

- (unsigned int)numerator {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaRatio>(self);
    THROW_NS_IF_FAILED(_comInst->get_Numerator(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDenominator:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaRatio>(self);
    THROW_NS_IF_FAILED(_comInst->put_Denominator(value));
}

- (unsigned int)denominator {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaRatio>(self);
    THROW_NS_IF_FAILED(_comInst->get_Denominator(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMMMediaPropertySet {
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

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.MediaProperties.MediaPropertySet").Get(), &out));
    return [_createRtProxy<WMMMediaPropertySet>(out.Get()) retain];
}

@end

@implementation WMMAudioEncodingProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.MediaProperties.AudioEncodingProperties").Get(),
                                              &out));
    return [_createRtProxy<WMMAudioEncodingProperties>(out.Get()) retain];
}

ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingPropertiesStatics> WMMIAudioEncodingPropertiesStatics_inst() {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingPropertiesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.MediaProperties.AudioEncodingProperties").Get(), &inst));
    return inst;
}

+ (WMMAudioEncodingProperties*)createAac:(unsigned int)sampleRate channelCount:(unsigned int)channelCount bitrate:(unsigned int)bitrate {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = WMMIAudioEncodingPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateAac(sampleRate, channelCount, bitrate, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

+ (WMMAudioEncodingProperties*)createAacAdts:(unsigned int)sampleRate
                                channelCount:(unsigned int)channelCount
                                     bitrate:(unsigned int)bitrate {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = WMMIAudioEncodingPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateAacAdts(sampleRate, channelCount, bitrate, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

+ (WMMAudioEncodingProperties*)createMp3:(unsigned int)sampleRate channelCount:(unsigned int)channelCount bitrate:(unsigned int)bitrate {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = WMMIAudioEncodingPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMp3(sampleRate, channelCount, bitrate, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

+ (WMMAudioEncodingProperties*)createPcm:(unsigned int)sampleRate
                            channelCount:(unsigned int)channelCount
                           bitsPerSample:(unsigned int)bitsPerSample {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = WMMIAudioEncodingPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreatePcm(sampleRate, channelCount, bitsPerSample, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

+ (WMMAudioEncodingProperties*)createWma:(unsigned int)sampleRate channelCount:(unsigned int)channelCount bitrate:(unsigned int)bitrate {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = WMMIAudioEncodingPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWma(sampleRate, channelCount, bitrate, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (void)setBitrate:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Bitrate(value));
}

- (unsigned int)bitrate {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bitrate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setChannelCount:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_ChannelCount(value));
}

- (unsigned int)channelCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChannelCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSampleRate:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_SampleRate(value));
}

- (unsigned int)sampleRate {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_SampleRate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setBitsPerSample:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_BitsPerSample(value));
}

- (unsigned int)bitsPerSample {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitsPerSample(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMMediaPropertySet*)properties {
    ComPtr<IMap<GUID, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaPropertySet>(unmarshalledReturn.Get());
}

- (NSString*)type {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSubtype:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Subtype(nsStrToHstr(value).Get()));
}

- (NSString*)subtype {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subtype(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFormatUserData:(NSArray* /* uint8_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingPropertiesWithFormatUserData>(self);
    THROW_NS_IF_FAILED(_comInst->SetFormatUserData(__value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)getFormatUserData:(NSArray* /* uint8_t */*)value {
    UINT32 __value_ArrayLen = 0;
    uint8_t* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingPropertiesWithFormatUserData>(self);
    THROW_NS_IF_FAILED(_comInst->GetFormatUserData(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_UInt8_create(__value_ArrayLen, __value_Array);
}

@end

@implementation WMMMediaEncodingSubtypes

ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingSubtypesStatics> WMMIMediaEncodingSubtypesStatics_inst() {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingSubtypesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.MediaProperties.MediaEncodingSubtypes").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)aac {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Aac(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aacAdts {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AacAdts(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)ac3 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Ac3(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)amrNb {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AmrNb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)amrWb {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AmrWb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)argb32 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Argb32(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)asf {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Asf(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)avi {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Avi(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bgra8 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Bgra8(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bmp {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Bmp(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)eac3 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Eac3(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)Float {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Float(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)gif {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gif(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)h263 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_H263(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)h264 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_H264(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)h264Es {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_H264Es(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hevc {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Hevc(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hevcEs {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HevcEs(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)iyuv {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Iyuv(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)jpeg {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Jpeg(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)jpegXr {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_JpegXr(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mjpg {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Mjpg(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mpeg {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Mpeg(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mpeg1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Mpeg1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mpeg2 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Mpeg2(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mp3 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Mp3(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mpeg4 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Mpeg4(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)nv12 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Nv12(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)pcm {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Pcm(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)png {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Png(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rgb24 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Rgb24(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rgb32 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Rgb32(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tiff {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Tiff(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)wave {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Wave(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)wma8 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Wma8(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)wma9 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Wma9(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)wmv3 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Wmv3(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)wvc1 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Wvc1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)yuy2 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Yuy2(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)yv12 {
    HSTRING unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingSubtypesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Yv12(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMMH264ProfileIds

ComPtr<ABI::Windows::Media::MediaProperties::IH264ProfileIdsStatics> WMMIH264ProfileIdsStatics_inst() {
    ComPtr<ABI::Windows::Media::MediaProperties::IH264ProfileIdsStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.MediaProperties.H264ProfileIds").Get(),
                                                       &inst));
    return inst;
}

+ (int)constrainedBaseline {
    int unmarshalledReturn;
    auto _comInst = WMMIH264ProfileIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ConstrainedBaseline(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)baseline {
    int unmarshalledReturn;
    auto _comInst = WMMIH264ProfileIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Baseline(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)extended {
    int unmarshalledReturn;
    auto _comInst = WMMIH264ProfileIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Extended(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)main {
    int unmarshalledReturn;
    auto _comInst = WMMIH264ProfileIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Main(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)high {
    int unmarshalledReturn;
    auto _comInst = WMMIH264ProfileIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_High(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)high10 {
    int unmarshalledReturn;
    auto _comInst = WMMIH264ProfileIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_High10(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)high422 {
    int unmarshalledReturn;
    auto _comInst = WMMIH264ProfileIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_High422(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)high444 {
    int unmarshalledReturn;
    auto _comInst = WMMIH264ProfileIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_High444(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)stereoHigh {
    int unmarshalledReturn;
    auto _comInst = WMMIH264ProfileIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StereoHigh(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)multiviewHigh {
    int unmarshalledReturn;
    auto _comInst = WMMIH264ProfileIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MultiviewHigh(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMMMpeg2ProfileIds

ComPtr<ABI::Windows::Media::MediaProperties::IMpeg2ProfileIdsStatics> WMMIMpeg2ProfileIdsStatics_inst() {
    ComPtr<ABI::Windows::Media::MediaProperties::IMpeg2ProfileIdsStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.MediaProperties.Mpeg2ProfileIds").Get(),
                                                       &inst));
    return inst;
}

+ (int)simple {
    int unmarshalledReturn;
    auto _comInst = WMMIMpeg2ProfileIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Simple(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)main {
    int unmarshalledReturn;
    auto _comInst = WMMIMpeg2ProfileIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Main(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)signalNoiseRatioScalable {
    int unmarshalledReturn;
    auto _comInst = WMMIMpeg2ProfileIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SignalNoiseRatioScalable(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)spatiallyScalable {
    int unmarshalledReturn;
    auto _comInst = WMMIMpeg2ProfileIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SpatiallyScalable(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (int)high {
    int unmarshalledReturn;
    auto _comInst = WMMIMpeg2ProfileIdsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_High(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMMVideoEncodingProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.MediaProperties.VideoEncodingProperties").Get(),
                                              &out));
    return [_createRtProxy<WMMVideoEncodingProperties>(out.Get()) retain];
}

ComPtr<ABI::Windows::Media::MediaProperties::IVideoEncodingPropertiesStatics> WMMIVideoEncodingPropertiesStatics_inst() {
    ComPtr<ABI::Windows::Media::MediaProperties::IVideoEncodingPropertiesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.MediaProperties.VideoEncodingProperties").Get(), &inst));
    return inst;
}

+ (WMMVideoEncodingProperties*)createH264 {
    ComPtr<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties> unmarshalledReturn;
    auto _comInst = WMMIVideoEncodingPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateH264(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMVideoEncodingProperties>(unmarshalledReturn.Get());
}

+ (WMMVideoEncodingProperties*)createMpeg2 {
    ComPtr<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties> unmarshalledReturn;
    auto _comInst = WMMIVideoEncodingPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMpeg2(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMVideoEncodingProperties>(unmarshalledReturn.Get());
}

+ (WMMVideoEncodingProperties*)createUncompressed:(NSString*)subtype width:(unsigned int)width height:(unsigned int)height {
    ComPtr<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties> unmarshalledReturn;
    auto _comInst = WMMIVideoEncodingPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateUncompressed(nsStrToHstr(subtype).Get(), width, height, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMVideoEncodingProperties>(unmarshalledReturn.Get());
}

- (void)setBitrate:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Bitrate(value));
}

- (unsigned int)bitrate {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bitrate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setWidth:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Width(value));
}

- (unsigned int)width {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Width(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setHeight:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Height(value));
}

- (unsigned int)height {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMMediaRatio*)frameRate {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaRatio> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameRate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaRatio>(unmarshalledReturn.Get());
}

- (WMMMediaRatio*)pixelAspectRatio {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaRatio> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelAspectRatio(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaRatio>(unmarshalledReturn.Get());
}

- (WMMMediaPropertySet*)properties {
    ComPtr<IMap<GUID, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaPropertySet>(unmarshalledReturn.Get());
}

- (NSString*)type {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSubtype:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Subtype(nsStrToHstr(value).Get()));
}

- (NSString*)subtype {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subtype(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setFormatUserData:(NSArray* /* uint8_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->SetFormatUserData(__value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)getFormatUserData:(NSArray* /* uint8_t */*)value {
    UINT32 __value_ArrayLen = 0;
    uint8_t* __value_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->GetFormatUserData(&__value_ArrayLen, &__value_Array));
    *value = RTProxiedNSArray_C_UInt8_create(__value_ArrayLen, __value_Array);
}

- (void)setProfileId:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProfileId(value));
}

- (int)profileId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProfileId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMStereoscopicVideoPackingMode)stereoscopicVideoPackingMode {
    ABI::Windows::Media::MediaProperties::StereoscopicVideoPackingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties3>(self);
    THROW_NS_IF_FAILED(_comInst->get_StereoscopicVideoPackingMode(&unmarshalledReturn));
    return (WMMStereoscopicVideoPackingMode)unmarshalledReturn;
}

@end

@implementation WMMImageEncodingProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::MediaProperties::IImageEncodingProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.MediaProperties.ImageEncodingProperties").Get(),
                                              &out));
    return [_createRtProxy<WMMImageEncodingProperties>(out.Get()) retain];
}

ComPtr<ABI::Windows::Media::MediaProperties::IImageEncodingPropertiesStatics2> WMMIImageEncodingPropertiesStatics2_inst() {
    ComPtr<ABI::Windows::Media::MediaProperties::IImageEncodingPropertiesStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.MediaProperties.ImageEncodingProperties").Get(), &inst));
    return inst;
}

+ (WMMImageEncodingProperties*)createUncompressed:(WMMMediaPixelFormat)format {
    ComPtr<ABI::Windows::Media::MediaProperties::IImageEncodingProperties> unmarshalledReturn;
    auto _comInst = WMMIImageEncodingPropertiesStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateUncompressed((ABI::Windows::Media::MediaProperties::MediaPixelFormat)format, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMImageEncodingProperties>(unmarshalledReturn.Get());
}

+ (WMMImageEncodingProperties*)createBmp {
    ComPtr<ABI::Windows::Media::MediaProperties::IImageEncodingProperties> unmarshalledReturn;
    auto _comInst = WMMIImageEncodingPropertiesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->CreateBmp(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMImageEncodingProperties>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Media::MediaProperties::IImageEncodingPropertiesStatics> WMMIImageEncodingPropertiesStatics_inst() {
    ComPtr<ABI::Windows::Media::MediaProperties::IImageEncodingPropertiesStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.MediaProperties.ImageEncodingProperties").Get(), &inst));
    return inst;
}

+ (WMMImageEncodingProperties*)createJpeg {
    ComPtr<ABI::Windows::Media::MediaProperties::IImageEncodingProperties> unmarshalledReturn;
    auto _comInst = WMMIImageEncodingPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateJpeg(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMImageEncodingProperties>(unmarshalledReturn.Get());
}

+ (WMMImageEncodingProperties*)createPng {
    ComPtr<ABI::Windows::Media::MediaProperties::IImageEncodingProperties> unmarshalledReturn;
    auto _comInst = WMMIImageEncodingPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreatePng(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMImageEncodingProperties>(unmarshalledReturn.Get());
}

+ (WMMImageEncodingProperties*)createJpegXR {
    ComPtr<ABI::Windows::Media::MediaProperties::IImageEncodingProperties> unmarshalledReturn;
    auto _comInst = WMMIImageEncodingPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateJpegXR(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMImageEncodingProperties>(unmarshalledReturn.Get());
}

- (void)setWidth:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IImageEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Width(value));
}

- (unsigned int)width {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IImageEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Width(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setHeight:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IImageEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Height(value));
}

- (unsigned int)height {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IImageEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMMediaPropertySet*)properties {
    ComPtr<IMap<GUID, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaPropertySet>(unmarshalledReturn.Get());
}

- (NSString*)type {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSubtype:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Subtype(nsStrToHstr(value).Get()));
}

- (NSString*)subtype {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subtype(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMMContainerEncodingProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::MediaProperties::IContainerEncodingProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.MediaProperties.ContainerEncodingProperties").Get(),
                                              &out));
    return [_createRtProxy<WMMContainerEncodingProperties>(out.Get()) retain];
}

- (WMMMediaPropertySet*)properties {
    ComPtr<IMap<GUID, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaPropertySet>(unmarshalledReturn.Get());
}

- (NSString*)type {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSubtype:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Subtype(nsStrToHstr(value).Get()));
}

- (NSString*)subtype {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subtype(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMMMediaEncodingProfile

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.MediaProperties.MediaEncodingProfile").Get(), &out));
    return [_createRtProxy<WMMMediaEncodingProfile>(out.Get()) retain];
}

ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfileStatics> WMMIMediaEncodingProfileStatics_inst() {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfileStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.MediaProperties.MediaEncodingProfile").Get(),
                                                       &inst));
    return inst;
}

+ (WMMMediaEncodingProfile*)createM4a:(WMMAudioEncodingQuality)quality {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile> unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingProfileStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateM4a((ABI::Windows::Media::MediaProperties::AudioEncodingQuality)quality, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaEncodingProfile>(unmarshalledReturn.Get());
}

+ (WMMMediaEncodingProfile*)createMp3:(WMMAudioEncodingQuality)quality {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile> unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingProfileStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateMp3((ABI::Windows::Media::MediaProperties::AudioEncodingQuality)quality, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaEncodingProfile>(unmarshalledReturn.Get());
}

+ (WMMMediaEncodingProfile*)createWma:(WMMAudioEncodingQuality)quality {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile> unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingProfileStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWma((ABI::Windows::Media::MediaProperties::AudioEncodingQuality)quality, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaEncodingProfile>(unmarshalledReturn.Get());
}

+ (WMMMediaEncodingProfile*)createMp4:(WMMVideoEncodingQuality)quality {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile> unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingProfileStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateMp4((ABI::Windows::Media::MediaProperties::VideoEncodingQuality)quality, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaEncodingProfile>(unmarshalledReturn.Get());
}

+ (WMMMediaEncodingProfile*)createWmv:(WMMVideoEncodingQuality)quality {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile> unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingProfileStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWmv((ABI::Windows::Media::MediaProperties::VideoEncodingQuality)quality, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaEncodingProfile>(unmarshalledReturn.Get());
}

+ (void)createFromFileAsync:(RTObject<WSIStorageFile>*)file
                    success:(void (^)(WMMMediaEncodingProfile*))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::MediaProperties::MediaEncodingProfile*>> unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingProfileStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromFileAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::MediaProperties::MediaEncodingProfile*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::MediaProperties::MediaEncodingProfile*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMMMediaEncodingProfile>(result.Get()));
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

+ (void)createFromStreamAsync:(RTObject<WSSIRandomAccessStream>*)stream
                      success:(void (^)(WMMMediaEncodingProfile*))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::MediaProperties::MediaEncodingProfile*>> unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingProfileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(stream).Get(),
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::MediaProperties::MediaEncodingProfile*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::MediaProperties::MediaEncodingProfile*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMMMediaEncodingProfile>(result.Get()));
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

ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfileStatics2> WMMIMediaEncodingProfileStatics2_inst() {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfileStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.MediaProperties.MediaEncodingProfile").Get(),
                                                       &inst));
    return inst;
}

+ (WMMMediaEncodingProfile*)createWav:(WMMAudioEncodingQuality)quality {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile> unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingProfileStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWav((ABI::Windows::Media::MediaProperties::AudioEncodingQuality)quality, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaEncodingProfile>(unmarshalledReturn.Get());
}

+ (WMMMediaEncodingProfile*)createAvi:(WMMVideoEncodingQuality)quality {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile> unmarshalledReturn;
    auto _comInst = WMMIMediaEncodingProfileStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateAvi((ABI::Windows::Media::MediaProperties::VideoEncodingQuality)quality, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaEncodingProfile>(unmarshalledReturn.Get());
}

- (void)setAudio:(WMMAudioEncodingProperties*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_Audio(_getRtInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(value).Get()));
}

- (WMMAudioEncodingProperties*)audio {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_Audio(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (void)setVideo:(WMMVideoEncodingProperties*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(self);
    THROW_NS_IF_FAILED(_comInst->put_Video(_getRtInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties>(value).Get()));
}

- (WMMVideoEncodingProperties*)video {
    ComPtr<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_Video(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMVideoEncodingProperties>(unmarshalledReturn.Get());
}

- (void)setContainer:(WMMContainerEncodingProperties*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Container(_getRtInterface<ABI::Windows::Media::MediaProperties::IContainerEncodingProperties>(value).Get()));
}

- (WMMContainerEncodingProperties*)container {
    ComPtr<ABI::Windows::Media::MediaProperties::IContainerEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(self);
    THROW_NS_IF_FAILED(_comInst->get_Container(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMContainerEncodingProperties>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
