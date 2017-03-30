// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::StartScreen {

struct IJumpList;
struct IJumpListItem;
struct IJumpListItemStatics;
struct IJumpListStatics;
struct ISecondaryTile;
struct ISecondaryTile2;
struct ISecondaryTileFactory;
struct ISecondaryTileFactory2;
struct ISecondaryTileStatics;
struct ISecondaryTileVisualElements;
struct ISecondaryTileVisualElements2;
struct ISecondaryTileVisualElements3;
struct IVisualElementsRequest;
struct IVisualElementsRequestDeferral;
struct IVisualElementsRequestedEventArgs;
struct JumpList;
struct JumpListItem;
struct SecondaryTile;
struct SecondaryTileVisualElements;
struct VisualElementsRequest;
struct VisualElementsRequestDeferral;
struct VisualElementsRequestedEventArgs;

}

namespace Windows::UI::StartScreen {

struct IJumpList;
struct IJumpListItem;
struct IJumpListItemStatics;
struct IJumpListStatics;
struct ISecondaryTile;
struct ISecondaryTile2;
struct ISecondaryTileFactory;
struct ISecondaryTileFactory2;
struct ISecondaryTileStatics;
struct ISecondaryTileVisualElements;
struct ISecondaryTileVisualElements2;
struct ISecondaryTileVisualElements3;
struct IVisualElementsRequest;
struct IVisualElementsRequestDeferral;
struct IVisualElementsRequestedEventArgs;
struct JumpList;
struct JumpListItem;
struct SecondaryTile;
struct SecondaryTileVisualElements;
struct VisualElementsRequest;
struct VisualElementsRequestDeferral;
struct VisualElementsRequestedEventArgs;

}

namespace Windows::UI::StartScreen {

template <typename T> struct impl_IJumpList;
template <typename T> struct impl_IJumpListItem;
template <typename T> struct impl_IJumpListItemStatics;
template <typename T> struct impl_IJumpListStatics;
template <typename T> struct impl_ISecondaryTile;
template <typename T> struct impl_ISecondaryTile2;
template <typename T> struct impl_ISecondaryTileFactory;
template <typename T> struct impl_ISecondaryTileFactory2;
template <typename T> struct impl_ISecondaryTileStatics;
template <typename T> struct impl_ISecondaryTileVisualElements;
template <typename T> struct impl_ISecondaryTileVisualElements2;
template <typename T> struct impl_ISecondaryTileVisualElements3;
template <typename T> struct impl_IVisualElementsRequest;
template <typename T> struct impl_IVisualElementsRequestDeferral;
template <typename T> struct impl_IVisualElementsRequestedEventArgs;

}

namespace Windows::UI::StartScreen {

enum class ForegroundText
{
    Dark = 0,
    Light = 1,
};

enum class JumpListItemKind
{
    Arguments = 0,
    Separator = 1,
};

enum class JumpListSystemGroupKind
{
    None = 0,
    Frequent = 1,
    Recent = 2,
};

enum class TileOptions : unsigned
{
    None = 0x0,
    ShowNameOnLogo = 0x1,
    ShowNameOnWideLogo = 0x2,
    CopyOnDeployment = 0x4,
};

DEFINE_ENUM_FLAG_OPERATORS(TileOptions)

enum class TileSize
{
    Default = 0,
    Square30x30 [[deprecated("TileSize.Square30x30 may be altered or unavailable for release after Windows 10.")]] = 1,
    Square70x70 [[deprecated("TileSize.Square70x70 may be altered or unavailable for release after Windows Phone 8.1.")]] = 2,
    Square150x150 = 3,
    Wide310x150 = 4,
    Square310x310 = 5,
    Square71x71 = 6,
    Square44x44 = 7,
};

}

}
