// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Editing {

struct IBackgroundAudioTrack;
struct IBackgroundAudioTrackStatics;
struct IEmbeddedAudioTrack;
struct IMediaClip;
struct IMediaClipStatics;
struct IMediaClipStatics2;
struct IMediaComposition;
struct IMediaComposition2;
struct IMediaCompositionStatics;
struct IMediaOverlay;
struct IMediaOverlayFactory;
struct IMediaOverlayLayer;
struct IMediaOverlayLayerFactory;
struct BackgroundAudioTrack;
struct EmbeddedAudioTrack;
struct MediaClip;
struct MediaComposition;
struct MediaOverlay;
struct MediaOverlayLayer;

}

namespace Windows::Media::Editing {

struct IBackgroundAudioTrack;
struct IBackgroundAudioTrackStatics;
struct IEmbeddedAudioTrack;
struct IMediaClip;
struct IMediaClipStatics;
struct IMediaClipStatics2;
struct IMediaComposition;
struct IMediaComposition2;
struct IMediaCompositionStatics;
struct IMediaOverlay;
struct IMediaOverlayFactory;
struct IMediaOverlayLayer;
struct IMediaOverlayLayerFactory;
struct BackgroundAudioTrack;
struct EmbeddedAudioTrack;
struct MediaClip;
struct MediaComposition;
struct MediaOverlay;
struct MediaOverlayLayer;

}

namespace Windows::Media::Editing {

template <typename T> struct impl_IBackgroundAudioTrack;
template <typename T> struct impl_IBackgroundAudioTrackStatics;
template <typename T> struct impl_IEmbeddedAudioTrack;
template <typename T> struct impl_IMediaClip;
template <typename T> struct impl_IMediaClipStatics;
template <typename T> struct impl_IMediaClipStatics2;
template <typename T> struct impl_IMediaComposition;
template <typename T> struct impl_IMediaComposition2;
template <typename T> struct impl_IMediaCompositionStatics;
template <typename T> struct impl_IMediaOverlay;
template <typename T> struct impl_IMediaOverlayFactory;
template <typename T> struct impl_IMediaOverlayLayer;
template <typename T> struct impl_IMediaOverlayLayerFactory;

}

namespace Windows::Media::Editing {

enum class MediaTrimmingPreference
{
    Fast = 0,
    Precise = 1,
};

enum class VideoFramePrecision
{
    NearestFrame = 0,
    NearestKeyFrame = 1,
};

}

}
