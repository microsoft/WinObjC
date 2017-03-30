// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Capture.Frames.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::Capture::Frames {

struct WINRT_EBO BufferMediaFrame :
    Windows::Media::Capture::Frames::IBufferMediaFrame
{
    BufferMediaFrame(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DepthMediaFrame :
    Windows::Media::Capture::Frames::IDepthMediaFrame
{
    DepthMediaFrame(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DepthMediaFrameFormat :
    Windows::Media::Capture::Frames::IDepthMediaFrameFormat
{
    DepthMediaFrameFormat(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InfraredMediaFrame :
    Windows::Media::Capture::Frames::IInfraredMediaFrame
{
    InfraredMediaFrame(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaFrameArrivedEventArgs :
    Windows::Media::Capture::Frames::IMediaFrameArrivedEventArgs
{
    MediaFrameArrivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaFrameFormat :
    Windows::Media::Capture::Frames::IMediaFrameFormat
{
    MediaFrameFormat(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaFrameReader :
    Windows::Media::Capture::Frames::IMediaFrameReader
{
    MediaFrameReader(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaFrameReference :
    Windows::Media::Capture::Frames::IMediaFrameReference
{
    MediaFrameReference(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaFrameSource :
    Windows::Media::Capture::Frames::IMediaFrameSource
{
    MediaFrameSource(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaFrameSourceController :
    Windows::Media::Capture::Frames::IMediaFrameSourceController
{
    MediaFrameSourceController(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaFrameSourceGetPropertyResult :
    Windows::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult
{
    MediaFrameSourceGetPropertyResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO MediaFrameSourceGroup :
    Windows::Media::Capture::Frames::IMediaFrameSourceGroup
{
    MediaFrameSourceGroup(std::nullptr_t) noexcept {}
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Media::Capture::Frames::MediaFrameSourceGroup>> FindAllAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Media::Capture::Frames::MediaFrameSourceGroup> FromIdAsync(hstring_view id);
    static hstring GetDeviceSelector();
};

struct WINRT_EBO MediaFrameSourceInfo :
    Windows::Media::Capture::Frames::IMediaFrameSourceInfo
{
    MediaFrameSourceInfo(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VideoMediaFrame :
    Windows::Media::Capture::Frames::IVideoMediaFrame
{
    VideoMediaFrame(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VideoMediaFrameFormat :
    Windows::Media::Capture::Frames::IVideoMediaFrameFormat
{
    VideoMediaFrameFormat(std::nullptr_t) noexcept {}
};

}

}
