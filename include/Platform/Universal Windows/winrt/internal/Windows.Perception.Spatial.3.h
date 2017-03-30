// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Perception.Spatial.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Perception::Spatial {

struct WINRT_EBO SpatialAnchor :
    Windows::Perception::Spatial::ISpatialAnchor,
    impl::require<SpatialAnchor, Windows::Perception::Spatial::ISpatialAnchor2>
{
    SpatialAnchor(std::nullptr_t) noexcept {}
    static Windows::Perception::Spatial::SpatialAnchor TryCreateRelativeTo(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem);
    static Windows::Perception::Spatial::SpatialAnchor TryCreateRelativeTo(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Foundation::Numerics::float3 & position);
    static Windows::Perception::Spatial::SpatialAnchor TryCreateRelativeTo(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Foundation::Numerics::float3 & position, const Windows::Foundation::Numerics::quaternion & orientation);
};

struct SpatialAnchorManager
{
    SpatialAnchorManager() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Perception::Spatial::SpatialAnchorStore> RequestStoreAsync();
};

struct WINRT_EBO SpatialAnchorRawCoordinateSystemAdjustedEventArgs :
    Windows::Perception::Spatial::ISpatialAnchorRawCoordinateSystemAdjustedEventArgs
{
    SpatialAnchorRawCoordinateSystemAdjustedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialAnchorStore :
    Windows::Perception::Spatial::ISpatialAnchorStore
{
    SpatialAnchorStore(std::nullptr_t) noexcept {}
};

struct SpatialAnchorTransferManager
{
    SpatialAnchorTransferManager() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Perception::Spatial::SpatialAnchor>> TryImportAnchorsAsync(const Windows::Storage::Streams::IInputStream & stream);
    static Windows::Foundation::IAsyncOperation<bool> TryExportAnchorsAsync(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Perception::Spatial::SpatialAnchor>> anchors, const Windows::Storage::Streams::IOutputStream & stream);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::Perception::Spatial::SpatialPerceptionAccessStatus> RequestAccessAsync();
};

struct WINRT_EBO SpatialBoundingVolume :
    Windows::Perception::Spatial::ISpatialBoundingVolume
{
    SpatialBoundingVolume(std::nullptr_t) noexcept {}
    static Windows::Perception::Spatial::SpatialBoundingVolume FromBox(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Perception::Spatial::SpatialBoundingBox & box);
    static Windows::Perception::Spatial::SpatialBoundingVolume FromOrientedBox(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Perception::Spatial::SpatialBoundingOrientedBox & box);
    static Windows::Perception::Spatial::SpatialBoundingVolume FromSphere(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Perception::Spatial::SpatialBoundingSphere & sphere);
    static Windows::Perception::Spatial::SpatialBoundingVolume FromFrustum(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Perception::Spatial::SpatialBoundingFrustum & frustum);
};

struct WINRT_EBO SpatialCoordinateSystem :
    Windows::Perception::Spatial::ISpatialCoordinateSystem
{
    SpatialCoordinateSystem(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialLocation :
    Windows::Perception::Spatial::ISpatialLocation
{
    SpatialLocation(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialLocator :
    Windows::Perception::Spatial::ISpatialLocator
{
    SpatialLocator(std::nullptr_t) noexcept {}
    static Windows::Perception::Spatial::SpatialLocator GetDefault();
};

struct WINRT_EBO SpatialLocatorAttachedFrameOfReference :
    Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference
{
    SpatialLocatorAttachedFrameOfReference(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialLocatorPositionalTrackingDeactivatingEventArgs :
    Windows::Perception::Spatial::ISpatialLocatorPositionalTrackingDeactivatingEventArgs
{
    SpatialLocatorPositionalTrackingDeactivatingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SpatialStationaryFrameOfReference :
    Windows::Perception::Spatial::ISpatialStationaryFrameOfReference
{
    SpatialStationaryFrameOfReference(std::nullptr_t) noexcept {}
};

}

}
