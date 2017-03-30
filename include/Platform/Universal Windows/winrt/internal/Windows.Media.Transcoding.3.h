// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Transcoding.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Media::Transcoding {

struct WINRT_EBO MediaTranscoder :
    Windows::Media::Transcoding::IMediaTranscoder,
    impl::require<MediaTranscoder, Windows::Media::Transcoding::IMediaTranscoder2>
{
    MediaTranscoder(std::nullptr_t) noexcept {}
    MediaTranscoder();
};

struct WINRT_EBO PrepareTranscodeResult :
    Windows::Media::Transcoding::IPrepareTranscodeResult
{
    PrepareTranscodeResult(std::nullptr_t) noexcept {}
};

}

}
