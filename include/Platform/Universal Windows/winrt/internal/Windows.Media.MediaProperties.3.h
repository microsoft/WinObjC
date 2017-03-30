// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.MediaProperties.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::MediaProperties {

struct WINRT_EBO AudioEncodingProperties :
    Windows::Media::MediaProperties::IAudioEncodingProperties,
    impl::require<AudioEncodingProperties, Windows::Media::MediaProperties::IAudioEncodingPropertiesWithFormatUserData>
{
    AudioEncodingProperties(std::nullptr_t) noexcept {}
    AudioEncodingProperties();
    static Windows::Media::MediaProperties::AudioEncodingProperties CreateAac(uint32_t sampleRate, uint32_t channelCount, uint32_t bitrate);
    static Windows::Media::MediaProperties::AudioEncodingProperties CreateAacAdts(uint32_t sampleRate, uint32_t channelCount, uint32_t bitrate);
    static Windows::Media::MediaProperties::AudioEncodingProperties CreateMp3(uint32_t sampleRate, uint32_t channelCount, uint32_t bitrate);
    static Windows::Media::MediaProperties::AudioEncodingProperties CreatePcm(uint32_t sampleRate, uint32_t channelCount, uint32_t bitsPerSample);
    static Windows::Media::MediaProperties::AudioEncodingProperties CreateWma(uint32_t sampleRate, uint32_t channelCount, uint32_t bitrate);
};

struct WINRT_EBO ContainerEncodingProperties :
    Windows::Media::MediaProperties::IContainerEncodingProperties
{
    ContainerEncodingProperties(std::nullptr_t) noexcept {}
    ContainerEncodingProperties();
};

struct H264ProfileIds
{
    H264ProfileIds() = delete;
    static int32_t ConstrainedBaseline();
    static int32_t Baseline();
    static int32_t Extended();
    static int32_t Main();
    static int32_t High();
    static int32_t High10();
    static int32_t High422();
    static int32_t High444();
    static int32_t StereoHigh();
    static int32_t MultiviewHigh();
};

struct WINRT_EBO ImageEncodingProperties :
    Windows::Media::MediaProperties::IImageEncodingProperties
{
    ImageEncodingProperties(std::nullptr_t) noexcept {}
    ImageEncodingProperties();
    static Windows::Media::MediaProperties::ImageEncodingProperties CreateJpeg();
    static Windows::Media::MediaProperties::ImageEncodingProperties CreatePng();
    static Windows::Media::MediaProperties::ImageEncodingProperties CreateJpegXR();
    static Windows::Media::MediaProperties::ImageEncodingProperties CreateUncompressed(Windows::Media::MediaProperties::MediaPixelFormat format);
    static Windows::Media::MediaProperties::ImageEncodingProperties CreateBmp();
};

struct WINRT_EBO MediaEncodingProfile :
    Windows::Media::MediaProperties::IMediaEncodingProfile
{
    MediaEncodingProfile(std::nullptr_t) noexcept {}
    MediaEncodingProfile();
    static Windows::Media::MediaProperties::MediaEncodingProfile CreateM4a(Windows::Media::MediaProperties::AudioEncodingQuality quality);
    static Windows::Media::MediaProperties::MediaEncodingProfile CreateMp3(Windows::Media::MediaProperties::AudioEncodingQuality quality);
    static Windows::Media::MediaProperties::MediaEncodingProfile CreateWma(Windows::Media::MediaProperties::AudioEncodingQuality quality);
    static Windows::Media::MediaProperties::MediaEncodingProfile CreateMp4(Windows::Media::MediaProperties::VideoEncodingQuality quality);
    static Windows::Media::MediaProperties::MediaEncodingProfile CreateWmv(Windows::Media::MediaProperties::VideoEncodingQuality quality);
    static Windows::Foundation::IAsyncOperation<Windows::Media::MediaProperties::MediaEncodingProfile> CreateFromFileAsync(const Windows::Storage::IStorageFile & file);
    static Windows::Foundation::IAsyncOperation<Windows::Media::MediaProperties::MediaEncodingProfile> CreateFromStreamAsync(const Windows::Storage::Streams::IRandomAccessStream & stream);
    static Windows::Media::MediaProperties::MediaEncodingProfile CreateWav(Windows::Media::MediaProperties::AudioEncodingQuality quality);
    static Windows::Media::MediaProperties::MediaEncodingProfile CreateAvi(Windows::Media::MediaProperties::VideoEncodingQuality quality);
};

struct MediaEncodingSubtypes
{
    MediaEncodingSubtypes() = delete;
    static hstring Aac();
    static hstring AacAdts();
    static hstring Ac3();
    static hstring AmrNb();
    static hstring AmrWb();
    static hstring Argb32();
    static hstring Asf();
    static hstring Avi();
    static hstring Bgra8();
    static hstring Bmp();
    static hstring Eac3();
    static hstring Float();
    static hstring Gif();
    static hstring H263();
    static hstring H264();
    static hstring H264Es();
    static hstring Hevc();
    static hstring HevcEs();
    static hstring Iyuv();
    static hstring Jpeg();
    static hstring JpegXr();
    static hstring Mjpg();
    static hstring Mpeg();
    static hstring Mpeg1();
    static hstring Mpeg2();
    static hstring Mp3();
    static hstring Mpeg4();
    static hstring Nv12();
    static hstring Pcm();
    static hstring Png();
    static hstring Rgb24();
    static hstring Rgb32();
    static hstring Tiff();
    static hstring Wave();
    static hstring Wma8();
    static hstring Wma9();
    static hstring Wmv3();
    static hstring Wvc1();
    static hstring Yuy2();
    static hstring Yv12();
};

struct WINRT_EBO MediaPropertySet :
    Windows::Foundation::Collections::IMap<GUID, Windows::Foundation::IInspectable>
{
    MediaPropertySet(std::nullptr_t) noexcept {}
    MediaPropertySet();
};

struct WINRT_EBO MediaRatio :
    Windows::Media::MediaProperties::IMediaRatio
{
    MediaRatio(std::nullptr_t) noexcept {}
};

struct Mpeg2ProfileIds
{
    Mpeg2ProfileIds() = delete;
    static int32_t Simple();
    static int32_t Main();
    static int32_t SignalNoiseRatioScalable();
    static int32_t SpatiallyScalable();
    static int32_t High();
};

struct WINRT_EBO VideoEncodingProperties :
    Windows::Media::MediaProperties::IVideoEncodingProperties,
    impl::require<VideoEncodingProperties, Windows::Media::MediaProperties::IVideoEncodingProperties2, Windows::Media::MediaProperties::IVideoEncodingProperties3>
{
    VideoEncodingProperties(std::nullptr_t) noexcept {}
    VideoEncodingProperties();
    static Windows::Media::MediaProperties::VideoEncodingProperties CreateH264();
    static Windows::Media::MediaProperties::VideoEncodingProperties CreateMpeg2();
    static Windows::Media::MediaProperties::VideoEncodingProperties CreateUncompressed(hstring_view subtype, uint32_t width, uint32_t height);
};

}

}
