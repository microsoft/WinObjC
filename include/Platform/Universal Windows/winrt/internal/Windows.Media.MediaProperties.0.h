// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::MediaProperties {

struct IAudioEncodingProperties;
struct IAudioEncodingPropertiesStatics;
struct IAudioEncodingPropertiesWithFormatUserData;
struct IContainerEncodingProperties;
struct IH264ProfileIdsStatics;
struct IImageEncodingProperties;
struct IImageEncodingPropertiesStatics;
struct IImageEncodingPropertiesStatics2;
struct IMediaEncodingProfile;
struct IMediaEncodingProfileStatics;
struct IMediaEncodingProfileStatics2;
struct IMediaEncodingProperties;
struct IMediaEncodingSubtypesStatics;
struct IMediaRatio;
struct IMpeg2ProfileIdsStatics;
struct IVideoEncodingProperties;
struct IVideoEncodingProperties2;
struct IVideoEncodingProperties3;
struct IVideoEncodingPropertiesStatics;
struct AudioEncodingProperties;
struct ContainerEncodingProperties;
struct ImageEncodingProperties;
struct MediaEncodingProfile;
struct MediaPropertySet;
struct MediaRatio;
struct VideoEncodingProperties;

}

namespace Windows::Media::MediaProperties {

struct IAudioEncodingProperties;
struct IAudioEncodingPropertiesStatics;
struct IAudioEncodingPropertiesWithFormatUserData;
struct IContainerEncodingProperties;
struct IH264ProfileIdsStatics;
struct IImageEncodingProperties;
struct IImageEncodingPropertiesStatics;
struct IImageEncodingPropertiesStatics2;
struct IMediaEncodingProfile;
struct IMediaEncodingProfileStatics;
struct IMediaEncodingProfileStatics2;
struct IMediaEncodingProperties;
struct IMediaEncodingSubtypesStatics;
struct IMediaRatio;
struct IMpeg2ProfileIdsStatics;
struct IVideoEncodingProperties;
struct IVideoEncodingProperties2;
struct IVideoEncodingProperties3;
struct IVideoEncodingPropertiesStatics;
struct AudioEncodingProperties;
struct ContainerEncodingProperties;
struct H264ProfileIds;
struct ImageEncodingProperties;
struct MediaEncodingProfile;
struct MediaEncodingSubtypes;
struct MediaPropertySet;
struct MediaRatio;
struct Mpeg2ProfileIds;
struct VideoEncodingProperties;

}

namespace Windows::Media::MediaProperties {

template <typename T> struct impl_IAudioEncodingProperties;
template <typename T> struct impl_IAudioEncodingPropertiesStatics;
template <typename T> struct impl_IAudioEncodingPropertiesWithFormatUserData;
template <typename T> struct impl_IContainerEncodingProperties;
template <typename T> struct impl_IH264ProfileIdsStatics;
template <typename T> struct impl_IImageEncodingProperties;
template <typename T> struct impl_IImageEncodingPropertiesStatics;
template <typename T> struct impl_IImageEncodingPropertiesStatics2;
template <typename T> struct impl_IMediaEncodingProfile;
template <typename T> struct impl_IMediaEncodingProfileStatics;
template <typename T> struct impl_IMediaEncodingProfileStatics2;
template <typename T> struct impl_IMediaEncodingProperties;
template <typename T> struct impl_IMediaEncodingSubtypesStatics;
template <typename T> struct impl_IMediaRatio;
template <typename T> struct impl_IMpeg2ProfileIdsStatics;
template <typename T> struct impl_IVideoEncodingProperties;
template <typename T> struct impl_IVideoEncodingProperties2;
template <typename T> struct impl_IVideoEncodingProperties3;
template <typename T> struct impl_IVideoEncodingPropertiesStatics;

}

namespace Windows::Media::MediaProperties {

enum class AudioEncodingQuality
{
    Auto = 0,
    High = 1,
    Medium = 2,
    Low = 3,
};

enum class MediaMirroringOptions : unsigned
{
    None = 0x0,
    Horizontal = 0x1,
    Vertical = 0x2,
};

DEFINE_ENUM_FLAG_OPERATORS(MediaMirroringOptions)

enum class MediaPixelFormat
{
    Nv12 = 0,
    Bgra8 = 1,
};

enum class MediaRotation
{
    None = 0,
    Clockwise90Degrees = 1,
    Clockwise180Degrees = 2,
    Clockwise270Degrees = 3,
};

enum class MediaThumbnailFormat
{
    Bmp = 0,
    Bgra8 = 1,
};

enum class StereoscopicVideoPackingMode
{
    None = 0,
    SideBySide = 1,
    TopBottom = 2,
};

enum class VideoEncodingQuality
{
    Auto = 0,
    HD1080p = 1,
    HD720p = 2,
    Wvga = 3,
    Ntsc = 4,
    Pal = 5,
    Vga = 6,
    Qvga = 7,
};

}

}
