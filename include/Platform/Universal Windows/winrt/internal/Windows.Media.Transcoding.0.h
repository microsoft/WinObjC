// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Transcoding {

struct IMediaTranscoder;
struct IMediaTranscoder2;
struct IPrepareTranscodeResult;
struct MediaTranscoder;
struct PrepareTranscodeResult;

}

namespace Windows::Media::Transcoding {

struct IMediaTranscoder;
struct IMediaTranscoder2;
struct IPrepareTranscodeResult;
struct MediaTranscoder;
struct PrepareTranscodeResult;

}

namespace Windows::Media::Transcoding {

template <typename T> struct impl_IMediaTranscoder;
template <typename T> struct impl_IMediaTranscoder2;
template <typename T> struct impl_IPrepareTranscodeResult;

}

namespace Windows::Media::Transcoding {

enum class MediaVideoProcessingAlgorithm
{
    Default = 0,
    MrfCrf444 = 1,
};

enum class TranscodeFailureReason
{
    None = 0,
    Unknown = 1,
    InvalidProfile = 2,
    CodecNotFound = 3,
};

}

}
