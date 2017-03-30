// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Capture::Frames {

struct IBufferMediaFrame;
struct IDepthMediaFrame;
struct IDepthMediaFrameFormat;
struct IInfraredMediaFrame;
struct IMediaFrameArrivedEventArgs;
struct IMediaFrameFormat;
struct IMediaFrameReader;
struct IMediaFrameReference;
struct IMediaFrameSource;
struct IMediaFrameSourceController;
struct IMediaFrameSourceGetPropertyResult;
struct IMediaFrameSourceGroup;
struct IMediaFrameSourceGroupStatics;
struct IMediaFrameSourceInfo;
struct IVideoMediaFrame;
struct IVideoMediaFrameFormat;
struct BufferMediaFrame;
struct DepthMediaFrame;
struct DepthMediaFrameFormat;
struct InfraredMediaFrame;
struct MediaFrameArrivedEventArgs;
struct MediaFrameFormat;
struct MediaFrameReader;
struct MediaFrameReference;
struct MediaFrameSource;
struct MediaFrameSourceController;
struct MediaFrameSourceGetPropertyResult;
struct MediaFrameSourceGroup;
struct MediaFrameSourceInfo;
struct VideoMediaFrame;
struct VideoMediaFrameFormat;

}

namespace Windows::Media::Capture::Frames {

struct IBufferMediaFrame;
struct IDepthMediaFrame;
struct IDepthMediaFrameFormat;
struct IInfraredMediaFrame;
struct IMediaFrameArrivedEventArgs;
struct IMediaFrameFormat;
struct IMediaFrameReader;
struct IMediaFrameReference;
struct IMediaFrameSource;
struct IMediaFrameSourceController;
struct IMediaFrameSourceGetPropertyResult;
struct IMediaFrameSourceGroup;
struct IMediaFrameSourceGroupStatics;
struct IMediaFrameSourceInfo;
struct IVideoMediaFrame;
struct IVideoMediaFrameFormat;
struct BufferMediaFrame;
struct DepthMediaFrame;
struct DepthMediaFrameFormat;
struct InfraredMediaFrame;
struct MediaFrameArrivedEventArgs;
struct MediaFrameFormat;
struct MediaFrameReader;
struct MediaFrameReference;
struct MediaFrameSource;
struct MediaFrameSourceController;
struct MediaFrameSourceGetPropertyResult;
struct MediaFrameSourceGroup;
struct MediaFrameSourceInfo;
struct VideoMediaFrame;
struct VideoMediaFrameFormat;

}

namespace Windows::Media::Capture::Frames {

template <typename T> struct impl_IBufferMediaFrame;
template <typename T> struct impl_IDepthMediaFrame;
template <typename T> struct impl_IDepthMediaFrameFormat;
template <typename T> struct impl_IInfraredMediaFrame;
template <typename T> struct impl_IMediaFrameArrivedEventArgs;
template <typename T> struct impl_IMediaFrameFormat;
template <typename T> struct impl_IMediaFrameReader;
template <typename T> struct impl_IMediaFrameReference;
template <typename T> struct impl_IMediaFrameSource;
template <typename T> struct impl_IMediaFrameSourceController;
template <typename T> struct impl_IMediaFrameSourceGetPropertyResult;
template <typename T> struct impl_IMediaFrameSourceGroup;
template <typename T> struct impl_IMediaFrameSourceGroupStatics;
template <typename T> struct impl_IMediaFrameSourceInfo;
template <typename T> struct impl_IVideoMediaFrame;
template <typename T> struct impl_IVideoMediaFrameFormat;

}

namespace Windows::Media::Capture::Frames {

enum class MediaFrameReaderStartStatus
{
    Success = 0,
    UnknownFailure = 1,
    DeviceNotAvailable = 2,
    OutputFormatNotSupported = 3,
};

enum class MediaFrameSourceGetPropertyStatus
{
    Success = 0,
    UnknownFailure = 1,
    NotSupported = 2,
    DeviceNotAvailable = 3,
};

enum class MediaFrameSourceKind
{
    Custom = 0,
    Color = 1,
    Infrared = 2,
    Depth = 3,
};

enum class MediaFrameSourceSetPropertyStatus
{
    Success = 0,
    UnknownFailure = 1,
    NotSupported = 2,
    InvalidValue = 3,
    DeviceNotAvailable = 4,
    NotInControl = 5,
};

}

}
