// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Storage::FileProperties {

struct IBasicProperties;
struct IDocumentProperties;
struct IGeotagHelperStatics;
struct IImageProperties;
struct IMusicProperties;
struct IStorageItemContentProperties;
struct IStorageItemExtraProperties;
struct IThumbnailProperties;
struct IVideoProperties;
struct BasicProperties;
struct DocumentProperties;
struct ImageProperties;
struct MusicProperties;
struct StorageItemContentProperties;
struct StorageItemThumbnail;
struct VideoProperties;

}

namespace Windows::Storage::FileProperties {

struct IBasicProperties;
struct IDocumentProperties;
struct IGeotagHelperStatics;
struct IImageProperties;
struct IMusicProperties;
struct IStorageItemContentProperties;
struct IStorageItemExtraProperties;
struct IThumbnailProperties;
struct IVideoProperties;
struct BasicProperties;
struct DocumentProperties;
struct GeotagHelper;
struct ImageProperties;
struct MusicProperties;
struct StorageItemContentProperties;
struct StorageItemThumbnail;
struct VideoProperties;

}

namespace Windows::Storage::FileProperties {

template <typename T> struct impl_IBasicProperties;
template <typename T> struct impl_IDocumentProperties;
template <typename T> struct impl_IGeotagHelperStatics;
template <typename T> struct impl_IImageProperties;
template <typename T> struct impl_IMusicProperties;
template <typename T> struct impl_IStorageItemContentProperties;
template <typename T> struct impl_IStorageItemExtraProperties;
template <typename T> struct impl_IThumbnailProperties;
template <typename T> struct impl_IVideoProperties;

}

namespace Windows::Storage::FileProperties {

enum class PhotoOrientation
{
    Unspecified = 0,
    Normal = 1,
    FlipHorizontal = 2,
    Rotate180 = 3,
    FlipVertical = 4,
    Transpose = 5,
    Rotate270 = 6,
    Transverse = 7,
    Rotate90 = 8,
};

enum class PropertyPrefetchOptions : unsigned
{
    None = 0x0,
    MusicProperties = 0x1,
    VideoProperties = 0x2,
    ImageProperties = 0x4,
    DocumentProperties = 0x8,
    BasicProperties = 0x10,
};

DEFINE_ENUM_FLAG_OPERATORS(PropertyPrefetchOptions)

enum class ThumbnailMode
{
    PicturesView = 0,
    VideosView = 1,
    MusicView = 2,
    DocumentsView = 3,
    ListView = 4,
    SingleItem = 5,
};

enum class ThumbnailOptions : unsigned
{
    None = 0x0,
    ReturnOnlyIfCached = 0x1,
    ResizeThumbnail = 0x2,
    UseCurrentScale = 0x4,
};

DEFINE_ENUM_FLAG_OPERATORS(ThumbnailOptions)

enum class ThumbnailType
{
    Image = 0,
    Icon = 1,
};

enum class VideoOrientation
{
    Normal = 0,
    Rotate90 = 90,
    Rotate180 = 180,
    Rotate270 = 270,
};

}

}
