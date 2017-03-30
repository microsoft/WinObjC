// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.MediaProperties.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::MediaProperties {

struct __declspec(uuid("62bc7a16-005c-4b3b-8a0b-0a090e9687f3")) __declspec(novtable) IAudioEncodingProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Bitrate(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Bitrate(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ChannelCount(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ChannelCount(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_SampleRate(uint32_t value) = 0;
    virtual HRESULT __stdcall get_SampleRate(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_BitsPerSample(uint32_t value) = 0;
    virtual HRESULT __stdcall get_BitsPerSample(uint32_t * value) = 0;
};

struct __declspec(uuid("0cad332c-ebe9-4527-b36d-e42a13cf38db")) __declspec(novtable) IAudioEncodingPropertiesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateAac(uint32_t sampleRate, uint32_t channelCount, uint32_t bitrate, Windows::Media::MediaProperties::IAudioEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall abi_CreateAacAdts(uint32_t sampleRate, uint32_t channelCount, uint32_t bitrate, Windows::Media::MediaProperties::IAudioEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall abi_CreateMp3(uint32_t sampleRate, uint32_t channelCount, uint32_t bitrate, Windows::Media::MediaProperties::IAudioEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall abi_CreatePcm(uint32_t sampleRate, uint32_t channelCount, uint32_t bitsPerSample, Windows::Media::MediaProperties::IAudioEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWma(uint32_t sampleRate, uint32_t channelCount, uint32_t bitrate, Windows::Media::MediaProperties::IAudioEncodingProperties ** value) = 0;
};

struct __declspec(uuid("98f10d79-13ea-49ff-be70-2673db69702c")) __declspec(novtable) IAudioEncodingPropertiesWithFormatUserData : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetFormatUserData(uint32_t __valueSize, uint8_t * value) = 0;
    virtual HRESULT __stdcall abi_GetFormatUserData(uint32_t * __valueSize, uint8_t ** value) = 0;
};

struct __declspec(uuid("59ac2a57-b32a-479e-8a61-4b7f2e9e7ea0")) __declspec(novtable) IContainerEncodingProperties : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("38654ca7-846a-4f97-a2e5-c3a15bbf70fd")) __declspec(novtable) IH264ProfileIdsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ConstrainedBaseline(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Baseline(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Extended(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Main(int32_t * value) = 0;
    virtual HRESULT __stdcall get_High(int32_t * value) = 0;
    virtual HRESULT __stdcall get_High10(int32_t * value) = 0;
    virtual HRESULT __stdcall get_High422(int32_t * value) = 0;
    virtual HRESULT __stdcall get_High444(int32_t * value) = 0;
    virtual HRESULT __stdcall get_StereoHigh(int32_t * value) = 0;
    virtual HRESULT __stdcall get_MultiviewHigh(int32_t * value) = 0;
};

struct __declspec(uuid("78625635-f331-4189-b1c3-b48d5ae034f1")) __declspec(novtable) IImageEncodingProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Width(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Width(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Height(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Height(uint32_t * value) = 0;
};

struct __declspec(uuid("257c68dc-8b99-439e-aa59-913a36161297")) __declspec(novtable) IImageEncodingPropertiesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateJpeg(Windows::Media::MediaProperties::IImageEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall abi_CreatePng(Windows::Media::MediaProperties::IImageEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall abi_CreateJpegXR(Windows::Media::MediaProperties::IImageEncodingProperties ** value) = 0;
};

struct __declspec(uuid("f6c25b29-3824-46b0-956e-501329e1be3c")) __declspec(novtable) IImageEncodingPropertiesStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateUncompressed(winrt::Windows::Media::MediaProperties::MediaPixelFormat format, Windows::Media::MediaProperties::IImageEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall abi_CreateBmp(Windows::Media::MediaProperties::IImageEncodingProperties ** value) = 0;
};

struct __declspec(uuid("e7dbf5a8-1db9-4783-876b-3dfe12acfdb3")) __declspec(novtable) IMediaEncodingProfile : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Audio(Windows::Media::MediaProperties::IAudioEncodingProperties * value) = 0;
    virtual HRESULT __stdcall get_Audio(Windows::Media::MediaProperties::IAudioEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall put_Video(Windows::Media::MediaProperties::IVideoEncodingProperties * value) = 0;
    virtual HRESULT __stdcall get_Video(Windows::Media::MediaProperties::IVideoEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall put_Container(Windows::Media::MediaProperties::IContainerEncodingProperties * value) = 0;
    virtual HRESULT __stdcall get_Container(Windows::Media::MediaProperties::IContainerEncodingProperties ** value) = 0;
};

struct __declspec(uuid("197f352c-2ede-4a45-a896-817a4854f8fe")) __declspec(novtable) IMediaEncodingProfileStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateM4a(winrt::Windows::Media::MediaProperties::AudioEncodingQuality quality, Windows::Media::MediaProperties::IMediaEncodingProfile ** value) = 0;
    virtual HRESULT __stdcall abi_CreateMp3(winrt::Windows::Media::MediaProperties::AudioEncodingQuality quality, Windows::Media::MediaProperties::IMediaEncodingProfile ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWma(winrt::Windows::Media::MediaProperties::AudioEncodingQuality quality, Windows::Media::MediaProperties::IMediaEncodingProfile ** value) = 0;
    virtual HRESULT __stdcall abi_CreateMp4(winrt::Windows::Media::MediaProperties::VideoEncodingQuality quality, Windows::Media::MediaProperties::IMediaEncodingProfile ** value) = 0;
    virtual HRESULT __stdcall abi_CreateWmv(winrt::Windows::Media::MediaProperties::VideoEncodingQuality quality, Windows::Media::MediaProperties::IMediaEncodingProfile ** value) = 0;
    virtual HRESULT __stdcall abi_CreateFromFileAsync(Windows::Storage::IStorageFile * file, Windows::Foundation::IAsyncOperation<Windows::Media::MediaProperties::MediaEncodingProfile> ** operation) = 0;
    virtual HRESULT __stdcall abi_CreateFromStreamAsync(Windows::Storage::Streams::IRandomAccessStream * stream, Windows::Foundation::IAsyncOperation<Windows::Media::MediaProperties::MediaEncodingProfile> ** operation) = 0;
};

struct __declspec(uuid("ce8de74f-6af4-4288-8fe2-79adf1f79a43")) __declspec(novtable) IMediaEncodingProfileStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWav(winrt::Windows::Media::MediaProperties::AudioEncodingQuality quality, Windows::Media::MediaProperties::IMediaEncodingProfile ** value) = 0;
    virtual HRESULT __stdcall abi_CreateAvi(winrt::Windows::Media::MediaProperties::VideoEncodingQuality quality, Windows::Media::MediaProperties::IMediaEncodingProfile ** value) = 0;
};

struct __declspec(uuid("b4002af6-acd4-4e5a-a24b-5d7498a8b8c4")) __declspec(novtable) IMediaEncodingProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMap<GUID, Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_Type(hstring * value) = 0;
    virtual HRESULT __stdcall put_Subtype(hstring value) = 0;
    virtual HRESULT __stdcall get_Subtype(hstring * value) = 0;
};

struct __declspec(uuid("37b6580e-a171-4464-ba5a-53189e48c1c8")) __declspec(novtable) IMediaEncodingSubtypesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Aac(hstring * value) = 0;
    virtual HRESULT __stdcall get_AacAdts(hstring * value) = 0;
    virtual HRESULT __stdcall get_Ac3(hstring * value) = 0;
    virtual HRESULT __stdcall get_AmrNb(hstring * value) = 0;
    virtual HRESULT __stdcall get_AmrWb(hstring * value) = 0;
    virtual HRESULT __stdcall get_Argb32(hstring * value) = 0;
    virtual HRESULT __stdcall get_Asf(hstring * value) = 0;
    virtual HRESULT __stdcall get_Avi(hstring * value) = 0;
    virtual HRESULT __stdcall get_Bgra8(hstring * value) = 0;
    virtual HRESULT __stdcall get_Bmp(hstring * value) = 0;
    virtual HRESULT __stdcall get_Eac3(hstring * value) = 0;
    virtual HRESULT __stdcall get_Float(hstring * value) = 0;
    virtual HRESULT __stdcall get_Gif(hstring * value) = 0;
    virtual HRESULT __stdcall get_H263(hstring * value) = 0;
    virtual HRESULT __stdcall get_H264(hstring * value) = 0;
    virtual HRESULT __stdcall get_H264Es(hstring * value) = 0;
    virtual HRESULT __stdcall get_Hevc(hstring * value) = 0;
    virtual HRESULT __stdcall get_HevcEs(hstring * value) = 0;
    virtual HRESULT __stdcall get_Iyuv(hstring * value) = 0;
    virtual HRESULT __stdcall get_Jpeg(hstring * value) = 0;
    virtual HRESULT __stdcall get_JpegXr(hstring * value) = 0;
    virtual HRESULT __stdcall get_Mjpg(hstring * value) = 0;
    virtual HRESULT __stdcall get_Mpeg(hstring * value) = 0;
    virtual HRESULT __stdcall get_Mpeg1(hstring * value) = 0;
    virtual HRESULT __stdcall get_Mpeg2(hstring * value) = 0;
    virtual HRESULT __stdcall get_Mp3(hstring * value) = 0;
    virtual HRESULT __stdcall get_Mpeg4(hstring * value) = 0;
    virtual HRESULT __stdcall get_Nv12(hstring * value) = 0;
    virtual HRESULT __stdcall get_Pcm(hstring * value) = 0;
    virtual HRESULT __stdcall get_Png(hstring * value) = 0;
    virtual HRESULT __stdcall get_Rgb24(hstring * value) = 0;
    virtual HRESULT __stdcall get_Rgb32(hstring * value) = 0;
    virtual HRESULT __stdcall get_Tiff(hstring * value) = 0;
    virtual HRESULT __stdcall get_Wave(hstring * value) = 0;
    virtual HRESULT __stdcall get_Wma8(hstring * value) = 0;
    virtual HRESULT __stdcall get_Wma9(hstring * value) = 0;
    virtual HRESULT __stdcall get_Wmv3(hstring * value) = 0;
    virtual HRESULT __stdcall get_Wvc1(hstring * value) = 0;
    virtual HRESULT __stdcall get_Yuy2(hstring * value) = 0;
    virtual HRESULT __stdcall get_Yv12(hstring * value) = 0;
};

struct __declspec(uuid("d2d0fee5-8929-401d-ac78-7d357e378163")) __declspec(novtable) IMediaRatio : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Numerator(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Numerator(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Denominator(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Denominator(uint32_t * value) = 0;
};

struct __declspec(uuid("a461ff85-e57a-4128-9b21-d5331b04235c")) __declspec(novtable) IMpeg2ProfileIdsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Simple(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Main(int32_t * value) = 0;
    virtual HRESULT __stdcall get_SignalNoiseRatioScalable(int32_t * value) = 0;
    virtual HRESULT __stdcall get_SpatiallyScalable(int32_t * value) = 0;
    virtual HRESULT __stdcall get_High(int32_t * value) = 0;
};

struct __declspec(uuid("76ee6c9a-37c2-4f2a-880a-1282bbb4373d")) __declspec(novtable) IVideoEncodingProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Bitrate(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Bitrate(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Width(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Width(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Height(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Height(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_FrameRate(Windows::Media::MediaProperties::IMediaRatio ** value) = 0;
    virtual HRESULT __stdcall get_PixelAspectRatio(Windows::Media::MediaProperties::IMediaRatio ** value) = 0;
};

struct __declspec(uuid("f743a1ef-d465-4290-a94b-ef0f1528f8e3")) __declspec(novtable) IVideoEncodingProperties2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetFormatUserData(uint32_t __valueSize, uint8_t * value) = 0;
    virtual HRESULT __stdcall abi_GetFormatUserData(uint32_t * __valueSize, uint8_t ** value) = 0;
    virtual HRESULT __stdcall put_ProfileId(int32_t value) = 0;
    virtual HRESULT __stdcall get_ProfileId(int32_t * value) = 0;
};

struct __declspec(uuid("386bcdc4-873a-479f-b3eb-56c1fcbec6d7")) __declspec(novtable) IVideoEncodingProperties3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_StereoscopicVideoPackingMode(winrt::Windows::Media::MediaProperties::StereoscopicVideoPackingMode * value) = 0;
};

struct __declspec(uuid("3ce14d44-1dc5-43db-9f38-ebebf90152cb")) __declspec(novtable) IVideoEncodingPropertiesStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateH264(Windows::Media::MediaProperties::IVideoEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall abi_CreateMpeg2(Windows::Media::MediaProperties::IVideoEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall abi_CreateUncompressed(hstring subtype, uint32_t width, uint32_t height, Windows::Media::MediaProperties::IVideoEncodingProperties ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::MediaProperties::AudioEncodingProperties> { using default_interface = Windows::Media::MediaProperties::IAudioEncodingProperties; };
template <> struct traits<Windows::Media::MediaProperties::ContainerEncodingProperties> { using default_interface = Windows::Media::MediaProperties::IContainerEncodingProperties; };
template <> struct traits<Windows::Media::MediaProperties::ImageEncodingProperties> { using default_interface = Windows::Media::MediaProperties::IImageEncodingProperties; };
template <> struct traits<Windows::Media::MediaProperties::MediaEncodingProfile> { using default_interface = Windows::Media::MediaProperties::IMediaEncodingProfile; };
template <> struct traits<Windows::Media::MediaProperties::MediaPropertySet> { using default_interface = Windows::Foundation::Collections::IMap<GUID, Windows::Foundation::IInspectable>; };
template <> struct traits<Windows::Media::MediaProperties::MediaRatio> { using default_interface = Windows::Media::MediaProperties::IMediaRatio; };
template <> struct traits<Windows::Media::MediaProperties::VideoEncodingProperties> { using default_interface = Windows::Media::MediaProperties::IVideoEncodingProperties; };

}

namespace Windows::Media::MediaProperties {

template <typename D>
struct WINRT_EBO impl_IAudioEncodingProperties
{
    void Bitrate(uint32_t value) const;
    uint32_t Bitrate() const;
    void ChannelCount(uint32_t value) const;
    uint32_t ChannelCount() const;
    void SampleRate(uint32_t value) const;
    uint32_t SampleRate() const;
    void BitsPerSample(uint32_t value) const;
    uint32_t BitsPerSample() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioEncodingPropertiesStatics
{
    Windows::Media::MediaProperties::AudioEncodingProperties CreateAac(uint32_t sampleRate, uint32_t channelCount, uint32_t bitrate) const;
    Windows::Media::MediaProperties::AudioEncodingProperties CreateAacAdts(uint32_t sampleRate, uint32_t channelCount, uint32_t bitrate) const;
    Windows::Media::MediaProperties::AudioEncodingProperties CreateMp3(uint32_t sampleRate, uint32_t channelCount, uint32_t bitrate) const;
    Windows::Media::MediaProperties::AudioEncodingProperties CreatePcm(uint32_t sampleRate, uint32_t channelCount, uint32_t bitsPerSample) const;
    Windows::Media::MediaProperties::AudioEncodingProperties CreateWma(uint32_t sampleRate, uint32_t channelCount, uint32_t bitrate) const;
};

template <typename D>
struct WINRT_EBO impl_IAudioEncodingPropertiesWithFormatUserData
{
    void SetFormatUserData(array_view<const uint8_t> value) const;
    void GetFormatUserData(com_array<uint8_t> & value) const;
};

template <typename D>
struct WINRT_EBO impl_IContainerEncodingProperties
{
};

template <typename D>
struct WINRT_EBO impl_IH264ProfileIdsStatics
{
    int32_t ConstrainedBaseline() const;
    int32_t Baseline() const;
    int32_t Extended() const;
    int32_t Main() const;
    int32_t High() const;
    int32_t High10() const;
    int32_t High422() const;
    int32_t High444() const;
    int32_t StereoHigh() const;
    int32_t MultiviewHigh() const;
};

template <typename D>
struct WINRT_EBO impl_IImageEncodingProperties
{
    void Width(uint32_t value) const;
    uint32_t Width() const;
    void Height(uint32_t value) const;
    uint32_t Height() const;
};

template <typename D>
struct WINRT_EBO impl_IImageEncodingPropertiesStatics
{
    Windows::Media::MediaProperties::ImageEncodingProperties CreateJpeg() const;
    Windows::Media::MediaProperties::ImageEncodingProperties CreatePng() const;
    Windows::Media::MediaProperties::ImageEncodingProperties CreateJpegXR() const;
};

template <typename D>
struct WINRT_EBO impl_IImageEncodingPropertiesStatics2
{
    Windows::Media::MediaProperties::ImageEncodingProperties CreateUncompressed(Windows::Media::MediaProperties::MediaPixelFormat format) const;
    Windows::Media::MediaProperties::ImageEncodingProperties CreateBmp() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaEncodingProfile
{
    void Audio(const Windows::Media::MediaProperties::AudioEncodingProperties & value) const;
    Windows::Media::MediaProperties::AudioEncodingProperties Audio() const;
    void Video(const Windows::Media::MediaProperties::VideoEncodingProperties & value) const;
    Windows::Media::MediaProperties::VideoEncodingProperties Video() const;
    void Container(const Windows::Media::MediaProperties::ContainerEncodingProperties & value) const;
    Windows::Media::MediaProperties::ContainerEncodingProperties Container() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaEncodingProfileStatics
{
    Windows::Media::MediaProperties::MediaEncodingProfile CreateM4a(Windows::Media::MediaProperties::AudioEncodingQuality quality) const;
    Windows::Media::MediaProperties::MediaEncodingProfile CreateMp3(Windows::Media::MediaProperties::AudioEncodingQuality quality) const;
    Windows::Media::MediaProperties::MediaEncodingProfile CreateWma(Windows::Media::MediaProperties::AudioEncodingQuality quality) const;
    Windows::Media::MediaProperties::MediaEncodingProfile CreateMp4(Windows::Media::MediaProperties::VideoEncodingQuality quality) const;
    Windows::Media::MediaProperties::MediaEncodingProfile CreateWmv(Windows::Media::MediaProperties::VideoEncodingQuality quality) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::MediaProperties::MediaEncodingProfile> CreateFromFileAsync(const Windows::Storage::IStorageFile & file) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::MediaProperties::MediaEncodingProfile> CreateFromStreamAsync(const Windows::Storage::Streams::IRandomAccessStream & stream) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaEncodingProfileStatics2
{
    Windows::Media::MediaProperties::MediaEncodingProfile CreateWav(Windows::Media::MediaProperties::AudioEncodingQuality quality) const;
    Windows::Media::MediaProperties::MediaEncodingProfile CreateAvi(Windows::Media::MediaProperties::VideoEncodingQuality quality) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaEncodingProperties
{
    Windows::Media::MediaProperties::MediaPropertySet Properties() const;
    hstring Type() const;
    void Subtype(hstring_view value) const;
    hstring Subtype() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaEncodingSubtypesStatics
{
    hstring Aac() const;
    hstring AacAdts() const;
    hstring Ac3() const;
    hstring AmrNb() const;
    hstring AmrWb() const;
    hstring Argb32() const;
    hstring Asf() const;
    hstring Avi() const;
    hstring Bgra8() const;
    hstring Bmp() const;
    hstring Eac3() const;
    hstring Float() const;
    hstring Gif() const;
    hstring H263() const;
    hstring H264() const;
    hstring H264Es() const;
    hstring Hevc() const;
    hstring HevcEs() const;
    hstring Iyuv() const;
    hstring Jpeg() const;
    hstring JpegXr() const;
    hstring Mjpg() const;
    hstring Mpeg() const;
    hstring Mpeg1() const;
    hstring Mpeg2() const;
    hstring Mp3() const;
    hstring Mpeg4() const;
    hstring Nv12() const;
    hstring Pcm() const;
    hstring Png() const;
    hstring Rgb24() const;
    hstring Rgb32() const;
    hstring Tiff() const;
    hstring Wave() const;
    hstring Wma8() const;
    hstring Wma9() const;
    hstring Wmv3() const;
    hstring Wvc1() const;
    hstring Yuy2() const;
    hstring Yv12() const;
};

template <typename D>
struct WINRT_EBO impl_IMediaRatio
{
    void Numerator(uint32_t value) const;
    uint32_t Numerator() const;
    void Denominator(uint32_t value) const;
    uint32_t Denominator() const;
};

template <typename D>
struct WINRT_EBO impl_IMpeg2ProfileIdsStatics
{
    int32_t Simple() const;
    int32_t Main() const;
    int32_t SignalNoiseRatioScalable() const;
    int32_t SpatiallyScalable() const;
    int32_t High() const;
};

template <typename D>
struct WINRT_EBO impl_IVideoEncodingProperties
{
    void Bitrate(uint32_t value) const;
    uint32_t Bitrate() const;
    void Width(uint32_t value) const;
    uint32_t Width() const;
    void Height(uint32_t value) const;
    uint32_t Height() const;
    Windows::Media::MediaProperties::MediaRatio FrameRate() const;
    Windows::Media::MediaProperties::MediaRatio PixelAspectRatio() const;
};

template <typename D>
struct WINRT_EBO impl_IVideoEncodingProperties2
{
    void SetFormatUserData(array_view<const uint8_t> value) const;
    void GetFormatUserData(com_array<uint8_t> & value) const;
    void ProfileId(int32_t value) const;
    int32_t ProfileId() const;
};

template <typename D>
struct WINRT_EBO impl_IVideoEncodingProperties3
{
    Windows::Media::MediaProperties::StereoscopicVideoPackingMode StereoscopicVideoPackingMode() const;
};

template <typename D>
struct WINRT_EBO impl_IVideoEncodingPropertiesStatics
{
    Windows::Media::MediaProperties::VideoEncodingProperties CreateH264() const;
    Windows::Media::MediaProperties::VideoEncodingProperties CreateMpeg2() const;
    Windows::Media::MediaProperties::VideoEncodingProperties CreateUncompressed(hstring_view subtype, uint32_t width, uint32_t height) const;
};

}

namespace impl {

template <> struct traits<Windows::Media::MediaProperties::IAudioEncodingProperties>
{
    using abi = ABI::Windows::Media::MediaProperties::IAudioEncodingProperties;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IAudioEncodingProperties<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IAudioEncodingPropertiesStatics>
{
    using abi = ABI::Windows::Media::MediaProperties::IAudioEncodingPropertiesStatics;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IAudioEncodingPropertiesStatics<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IAudioEncodingPropertiesWithFormatUserData>
{
    using abi = ABI::Windows::Media::MediaProperties::IAudioEncodingPropertiesWithFormatUserData;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IAudioEncodingPropertiesWithFormatUserData<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IContainerEncodingProperties>
{
    using abi = ABI::Windows::Media::MediaProperties::IContainerEncodingProperties;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IContainerEncodingProperties<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IH264ProfileIdsStatics>
{
    using abi = ABI::Windows::Media::MediaProperties::IH264ProfileIdsStatics;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IH264ProfileIdsStatics<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IImageEncodingProperties>
{
    using abi = ABI::Windows::Media::MediaProperties::IImageEncodingProperties;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IImageEncodingProperties<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IImageEncodingPropertiesStatics>
{
    using abi = ABI::Windows::Media::MediaProperties::IImageEncodingPropertiesStatics;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IImageEncodingPropertiesStatics<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IImageEncodingPropertiesStatics2>
{
    using abi = ABI::Windows::Media::MediaProperties::IImageEncodingPropertiesStatics2;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IImageEncodingPropertiesStatics2<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IMediaEncodingProfile>
{
    using abi = ABI::Windows::Media::MediaProperties::IMediaEncodingProfile;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IMediaEncodingProfile<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IMediaEncodingProfileStatics>
{
    using abi = ABI::Windows::Media::MediaProperties::IMediaEncodingProfileStatics;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IMediaEncodingProfileStatics<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IMediaEncodingProfileStatics2>
{
    using abi = ABI::Windows::Media::MediaProperties::IMediaEncodingProfileStatics2;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IMediaEncodingProfileStatics2<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IMediaEncodingProperties>
{
    using abi = ABI::Windows::Media::MediaProperties::IMediaEncodingProperties;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IMediaEncodingProperties<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IMediaEncodingSubtypesStatics>
{
    using abi = ABI::Windows::Media::MediaProperties::IMediaEncodingSubtypesStatics;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IMediaEncodingSubtypesStatics<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IMediaRatio>
{
    using abi = ABI::Windows::Media::MediaProperties::IMediaRatio;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IMediaRatio<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IMpeg2ProfileIdsStatics>
{
    using abi = ABI::Windows::Media::MediaProperties::IMpeg2ProfileIdsStatics;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IMpeg2ProfileIdsStatics<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IVideoEncodingProperties>
{
    using abi = ABI::Windows::Media::MediaProperties::IVideoEncodingProperties;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IVideoEncodingProperties<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IVideoEncodingProperties2>
{
    using abi = ABI::Windows::Media::MediaProperties::IVideoEncodingProperties2;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IVideoEncodingProperties2<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IVideoEncodingProperties3>
{
    using abi = ABI::Windows::Media::MediaProperties::IVideoEncodingProperties3;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IVideoEncodingProperties3<D>;
};

template <> struct traits<Windows::Media::MediaProperties::IVideoEncodingPropertiesStatics>
{
    using abi = ABI::Windows::Media::MediaProperties::IVideoEncodingPropertiesStatics;
    template <typename D> using consume = Windows::Media::MediaProperties::impl_IVideoEncodingPropertiesStatics<D>;
};

template <> struct traits<Windows::Media::MediaProperties::AudioEncodingProperties>
{
    using abi = ABI::Windows::Media::MediaProperties::AudioEncodingProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.MediaProperties.AudioEncodingProperties"; }
};

template <> struct traits<Windows::Media::MediaProperties::ContainerEncodingProperties>
{
    using abi = ABI::Windows::Media::MediaProperties::ContainerEncodingProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.MediaProperties.ContainerEncodingProperties"; }
};

template <> struct traits<Windows::Media::MediaProperties::H264ProfileIds>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.MediaProperties.H264ProfileIds"; }
};

template <> struct traits<Windows::Media::MediaProperties::ImageEncodingProperties>
{
    using abi = ABI::Windows::Media::MediaProperties::ImageEncodingProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.MediaProperties.ImageEncodingProperties"; }
};

template <> struct traits<Windows::Media::MediaProperties::MediaEncodingProfile>
{
    using abi = ABI::Windows::Media::MediaProperties::MediaEncodingProfile;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.MediaProperties.MediaEncodingProfile"; }
};

template <> struct traits<Windows::Media::MediaProperties::MediaEncodingSubtypes>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.MediaProperties.MediaEncodingSubtypes"; }
};

template <> struct traits<Windows::Media::MediaProperties::MediaPropertySet>
{
    using abi = ABI::Windows::Media::MediaProperties::MediaPropertySet;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.MediaProperties.MediaPropertySet"; }
};

template <> struct traits<Windows::Media::MediaProperties::MediaRatio>
{
    using abi = ABI::Windows::Media::MediaProperties::MediaRatio;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.MediaProperties.MediaRatio"; }
};

template <> struct traits<Windows::Media::MediaProperties::Mpeg2ProfileIds>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.MediaProperties.Mpeg2ProfileIds"; }
};

template <> struct traits<Windows::Media::MediaProperties::VideoEncodingProperties>
{
    using abi = ABI::Windows::Media::MediaProperties::VideoEncodingProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.MediaProperties.VideoEncodingProperties"; }
};

}

}
