// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Playlists {

struct IPlaylist;
struct IPlaylistStatics;
struct Playlist;

}

namespace Windows::Media::Playlists {

struct IPlaylist;
struct IPlaylistStatics;
struct Playlist;

}

namespace Windows::Media::Playlists {

template <typename T> struct impl_IPlaylist;
template <typename T> struct impl_IPlaylistStatics;

}

namespace Windows::Media::Playlists {

enum class PlaylistFormat
{
    WindowsMedia = 0,
    Zune = 1,
    M3u = 2,
};

}

}
