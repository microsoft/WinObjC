// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Perception.3.h"
#include "internal/Windows.Perception.Spatial.3.h"
#include "Windows.Perception.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Perception::Spatial::ISpatialAnchor> : produce_base<D, Windows::Perception::Spatial::ISpatialAnchor>
{
    HRESULT __stdcall get_CoordinateSystem(impl::abi_arg_out<Windows::Perception::Spatial::ISpatialCoordinateSystem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CoordinateSystem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RawCoordinateSystem(impl::abi_arg_out<Windows::Perception::Spatial::ISpatialCoordinateSystem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RawCoordinateSystem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RawCoordinateSystemAdjusted(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::SpatialAnchor, Windows::Perception::Spatial::SpatialAnchorRawCoordinateSystemAdjustedEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().RawCoordinateSystemAdjusted(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::SpatialAnchor, Windows::Perception::Spatial::SpatialAnchorRawCoordinateSystemAdjustedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RawCoordinateSystemAdjusted(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RawCoordinateSystemAdjusted(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::ISpatialAnchor2> : produce_base<D, Windows::Perception::Spatial::ISpatialAnchor2>
{
    HRESULT __stdcall get_RemovedByUser(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RemovedByUser());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::ISpatialAnchorManagerStatics> : produce_base<D, Windows::Perception::Spatial::ISpatialAnchorManagerStatics>
{
    HRESULT __stdcall abi_RequestStoreAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Perception::Spatial::SpatialAnchorStore>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RequestStoreAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::ISpatialAnchorRawCoordinateSystemAdjustedEventArgs> : produce_base<D, Windows::Perception::Spatial::ISpatialAnchorRawCoordinateSystemAdjustedEventArgs>
{
    HRESULT __stdcall get_OldRawCoordinateSystemToNewRawCoordinateSystemTransform(impl::abi_arg_out<Windows::Foundation::Numerics::float4x4> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OldRawCoordinateSystemToNewRawCoordinateSystemTransform());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::ISpatialAnchorStatics> : produce_base<D, Windows::Perception::Spatial::ISpatialAnchorStatics>
{
    HRESULT __stdcall abi_TryCreateRelativeTo(impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> coordinateSystem, impl::abi_arg_out<Windows::Perception::Spatial::ISpatialAnchor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryCreateRelativeTo(*reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&coordinateSystem)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryCreateWithPositionRelativeTo(impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> coordinateSystem, impl::abi_arg_in<Windows::Foundation::Numerics::float3> position, impl::abi_arg_out<Windows::Perception::Spatial::ISpatialAnchor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryCreateRelativeTo(*reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&coordinateSystem), *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&position)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryCreateWithPositionAndOrientationRelativeTo(impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> coordinateSystem, impl::abi_arg_in<Windows::Foundation::Numerics::float3> position, impl::abi_arg_in<Windows::Foundation::Numerics::quaternion> orientation, impl::abi_arg_out<Windows::Perception::Spatial::ISpatialAnchor> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryCreateRelativeTo(*reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&coordinateSystem), *reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&position), *reinterpret_cast<const Windows::Foundation::Numerics::quaternion *>(&orientation)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::ISpatialAnchorStore> : produce_base<D, Windows::Perception::Spatial::ISpatialAnchorStore>
{
    HRESULT __stdcall abi_GetAllSavedAnchors(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Perception::Spatial::SpatialAnchor>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetAllSavedAnchors());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TrySave(impl::abi_arg_in<hstring> id, impl::abi_arg_in<Windows::Perception::Spatial::ISpatialAnchor> anchor, bool * succeeded) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_abi(this->shim().TrySave(*reinterpret_cast<const hstring *>(&id), *reinterpret_cast<const Windows::Perception::Spatial::SpatialAnchor *>(&anchor)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Remove(impl::abi_arg_in<hstring> id) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<const hstring *>(&id));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Clear() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::ISpatialAnchorTransferManagerStatics> : produce_base<D, Windows::Perception::Spatial::ISpatialAnchorTransferManagerStatics>
{
    HRESULT __stdcall abi_TryImportAnchorsAsync(impl::abi_arg_in<Windows::Storage::Streams::IInputStream> stream, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Perception::Spatial::SpatialAnchor>>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().TryImportAnchorsAsync(*reinterpret_cast<const Windows::Storage::Streams::IInputStream *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryExportAnchorsAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Perception::Spatial::SpatialAnchor>>> anchors, impl::abi_arg_in<Windows::Storage::Streams::IOutputStream> stream, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> operation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *operation = detach_abi(this->shim().TryExportAnchorsAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Perception::Spatial::SpatialAnchor>> *>(&anchors), *reinterpret_cast<const Windows::Storage::Streams::IOutputStream *>(&stream)));
            return S_OK;
        }
        catch (...)
        {
            *operation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAccessAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Perception::Spatial::SpatialPerceptionAccessStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAccessAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::ISpatialBoundingVolume> : produce_base<D, Windows::Perception::Spatial::ISpatialBoundingVolume>
{};

template <typename D>
struct produce<D, Windows::Perception::Spatial::ISpatialBoundingVolumeStatics> : produce_base<D, Windows::Perception::Spatial::ISpatialBoundingVolumeStatics>
{
    HRESULT __stdcall abi_FromBox(impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> coordinateSystem, impl::abi_arg_in<Windows::Perception::Spatial::SpatialBoundingBox> box, impl::abi_arg_out<Windows::Perception::Spatial::ISpatialBoundingVolume> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromBox(*reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&coordinateSystem), *reinterpret_cast<const Windows::Perception::Spatial::SpatialBoundingBox *>(&box)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromOrientedBox(impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> coordinateSystem, impl::abi_arg_in<Windows::Perception::Spatial::SpatialBoundingOrientedBox> box, impl::abi_arg_out<Windows::Perception::Spatial::ISpatialBoundingVolume> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromOrientedBox(*reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&coordinateSystem), *reinterpret_cast<const Windows::Perception::Spatial::SpatialBoundingOrientedBox *>(&box)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromSphere(impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> coordinateSystem, impl::abi_arg_in<Windows::Perception::Spatial::SpatialBoundingSphere> sphere, impl::abi_arg_out<Windows::Perception::Spatial::ISpatialBoundingVolume> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromSphere(*reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&coordinateSystem), *reinterpret_cast<const Windows::Perception::Spatial::SpatialBoundingSphere *>(&sphere)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromFrustum(impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> coordinateSystem, impl::abi_arg_in<Windows::Perception::Spatial::SpatialBoundingFrustum> frustum, impl::abi_arg_out<Windows::Perception::Spatial::ISpatialBoundingVolume> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().FromFrustum(*reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&coordinateSystem), *reinterpret_cast<const Windows::Perception::Spatial::SpatialBoundingFrustum *>(&frustum)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::ISpatialCoordinateSystem> : produce_base<D, Windows::Perception::Spatial::ISpatialCoordinateSystem>
{
    HRESULT __stdcall abi_TryGetTransformTo(impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> target, impl::abi_arg_out<Windows::Foundation::IReference<Windows::Foundation::Numerics::float4x4>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryGetTransformTo(*reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&target)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::ISpatialLocation> : produce_base<D, Windows::Perception::Spatial::ISpatialLocation>
{
    HRESULT __stdcall get_Position(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Position());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Orientation(impl::abi_arg_out<Windows::Foundation::Numerics::quaternion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Orientation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AbsoluteLinearVelocity(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AbsoluteLinearVelocity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AbsoluteLinearAcceleration(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AbsoluteLinearAcceleration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AbsoluteAngularVelocity(impl::abi_arg_out<Windows::Foundation::Numerics::quaternion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AbsoluteAngularVelocity());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AbsoluteAngularAcceleration(impl::abi_arg_out<Windows::Foundation::Numerics::quaternion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AbsoluteAngularAcceleration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::ISpatialLocator> : produce_base<D, Windows::Perception::Spatial::ISpatialLocator>
{
    HRESULT __stdcall get_Locatability(Windows::Perception::Spatial::SpatialLocatability * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Locatability());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_LocatabilityChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::SpatialLocator, Windows::Foundation::IInspectable>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().LocatabilityChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::SpatialLocator, Windows::Foundation::IInspectable> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_LocatabilityChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LocatabilityChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_PositionalTrackingDeactivating(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::SpatialLocator, Windows::Perception::Spatial::SpatialLocatorPositionalTrackingDeactivatingEventArgs>> handler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().PositionalTrackingDeactivating(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::SpatialLocator, Windows::Perception::Spatial::SpatialLocatorPositionalTrackingDeactivatingEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_PositionalTrackingDeactivating(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PositionalTrackingDeactivating(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryLocateAtTimestamp(impl::abi_arg_in<Windows::Perception::IPerceptionTimestamp> timestamp, impl::abi_arg_in<Windows::Perception::Spatial::ISpatialCoordinateSystem> coordinateSystem, impl::abi_arg_out<Windows::Perception::Spatial::ISpatialLocation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryLocateAtTimestamp(*reinterpret_cast<const Windows::Perception::PerceptionTimestamp *>(&timestamp), *reinterpret_cast<const Windows::Perception::Spatial::SpatialCoordinateSystem *>(&coordinateSystem)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAttachedFrameOfReferenceAtCurrentHeading(impl::abi_arg_out<Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateAttachedFrameOfReferenceAtCurrentHeading());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAttachedFrameOfReferenceAtCurrentHeadingWithPosition(impl::abi_arg_in<Windows::Foundation::Numerics::float3> relativePosition, impl::abi_arg_out<Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateAttachedFrameOfReferenceAtCurrentHeading(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&relativePosition)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAttachedFrameOfReferenceAtCurrentHeadingWithPositionAndOrientation(impl::abi_arg_in<Windows::Foundation::Numerics::float3> relativePosition, impl::abi_arg_in<Windows::Foundation::Numerics::quaternion> relativeOrientation, impl::abi_arg_out<Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateAttachedFrameOfReferenceAtCurrentHeading(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&relativePosition), *reinterpret_cast<const Windows::Foundation::Numerics::quaternion *>(&relativeOrientation)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateAttachedFrameOfReferenceAtCurrentHeadingWithPositionAndOrientationAndRelativeHeading(impl::abi_arg_in<Windows::Foundation::Numerics::float3> relativePosition, impl::abi_arg_in<Windows::Foundation::Numerics::quaternion> relativeOrientation, double relativeHeadingInRadians, impl::abi_arg_out<Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateAttachedFrameOfReferenceAtCurrentHeading(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&relativePosition), *reinterpret_cast<const Windows::Foundation::Numerics::quaternion *>(&relativeOrientation), relativeHeadingInRadians));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateStationaryFrameOfReferenceAtCurrentLocation(impl::abi_arg_out<Windows::Perception::Spatial::ISpatialStationaryFrameOfReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateStationaryFrameOfReferenceAtCurrentLocation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateStationaryFrameOfReferenceAtCurrentLocationWithPosition(impl::abi_arg_in<Windows::Foundation::Numerics::float3> relativePosition, impl::abi_arg_out<Windows::Perception::Spatial::ISpatialStationaryFrameOfReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateStationaryFrameOfReferenceAtCurrentLocation(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&relativePosition)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateStationaryFrameOfReferenceAtCurrentLocationWithPositionAndOrientation(impl::abi_arg_in<Windows::Foundation::Numerics::float3> relativePosition, impl::abi_arg_in<Windows::Foundation::Numerics::quaternion> relativeOrientation, impl::abi_arg_out<Windows::Perception::Spatial::ISpatialStationaryFrameOfReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateStationaryFrameOfReferenceAtCurrentLocation(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&relativePosition), *reinterpret_cast<const Windows::Foundation::Numerics::quaternion *>(&relativeOrientation)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateStationaryFrameOfReferenceAtCurrentLocationWithPositionAndOrientationAndRelativeHeading(impl::abi_arg_in<Windows::Foundation::Numerics::float3> relativePosition, impl::abi_arg_in<Windows::Foundation::Numerics::quaternion> relativeOrientation, double relativeHeadingInRadians, impl::abi_arg_out<Windows::Perception::Spatial::ISpatialStationaryFrameOfReference> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateStationaryFrameOfReferenceAtCurrentLocation(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&relativePosition), *reinterpret_cast<const Windows::Foundation::Numerics::quaternion *>(&relativeOrientation), relativeHeadingInRadians));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference> : produce_base<D, Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference>
{
    HRESULT __stdcall get_RelativePosition(impl::abi_arg_out<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RelativePosition());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RelativePosition(impl::abi_arg_in<Windows::Foundation::Numerics::float3> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RelativePosition(*reinterpret_cast<const Windows::Foundation::Numerics::float3 *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RelativeOrientation(impl::abi_arg_out<Windows::Foundation::Numerics::quaternion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RelativeOrientation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_RelativeOrientation(impl::abi_arg_in<Windows::Foundation::Numerics::quaternion> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RelativeOrientation(*reinterpret_cast<const Windows::Foundation::Numerics::quaternion *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_AdjustHeading(double headingOffsetInRadians) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AdjustHeading(headingOffsetInRadians);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStationaryCoordinateSystemAtTimestamp(impl::abi_arg_in<Windows::Perception::IPerceptionTimestamp> timestamp, impl::abi_arg_out<Windows::Perception::Spatial::ISpatialCoordinateSystem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetStationaryCoordinateSystemAtTimestamp(*reinterpret_cast<const Windows::Perception::PerceptionTimestamp *>(&timestamp)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryGetRelativeHeadingAtTimestamp(impl::abi_arg_in<Windows::Perception::IPerceptionTimestamp> timestamp, impl::abi_arg_out<Windows::Foundation::IReference<double>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TryGetRelativeHeadingAtTimestamp(*reinterpret_cast<const Windows::Perception::PerceptionTimestamp *>(&timestamp)));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::ISpatialLocatorPositionalTrackingDeactivatingEventArgs> : produce_base<D, Windows::Perception::Spatial::ISpatialLocatorPositionalTrackingDeactivatingEventArgs>
{
    HRESULT __stdcall get_Canceled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Canceled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Canceled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Canceled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::ISpatialLocatorStatics> : produce_base<D, Windows::Perception::Spatial::ISpatialLocatorStatics>
{
    HRESULT __stdcall abi_GetDefault(impl::abi_arg_out<Windows::Perception::Spatial::ISpatialLocator> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GetDefault());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Perception::Spatial::ISpatialStationaryFrameOfReference> : produce_base<D, Windows::Perception::Spatial::ISpatialStationaryFrameOfReference>
{
    HRESULT __stdcall get_CoordinateSystem(impl::abi_arg_out<Windows::Perception::Spatial::ISpatialCoordinateSystem> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CoordinateSystem());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Perception::Spatial {

template <typename D> Windows::Foundation::IReference<Windows::Foundation::Numerics::float4x4> impl_ISpatialCoordinateSystem<D>::TryGetTransformTo(const Windows::Perception::Spatial::SpatialCoordinateSystem & target) const
{
    Windows::Foundation::IReference<Windows::Foundation::Numerics::float4x4> value;
    check_hresult(WINRT_SHIM(ISpatialCoordinateSystem)->abi_TryGetTransformTo(get_abi(target), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float4x4 impl_ISpatialAnchorRawCoordinateSystemAdjustedEventArgs<D>::OldRawCoordinateSystemToNewRawCoordinateSystemTransform() const
{
    Windows::Foundation::Numerics::float4x4 value {};
    check_hresult(WINRT_SHIM(ISpatialAnchorRawCoordinateSystemAdjustedEventArgs)->get_OldRawCoordinateSystemToNewRawCoordinateSystemTransform(put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialCoordinateSystem impl_ISpatialAnchor<D>::CoordinateSystem() const
{
    Windows::Perception::Spatial::SpatialCoordinateSystem value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialAnchor)->get_CoordinateSystem(put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialCoordinateSystem impl_ISpatialAnchor<D>::RawCoordinateSystem() const
{
    Windows::Perception::Spatial::SpatialCoordinateSystem value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialAnchor)->get_RawCoordinateSystem(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ISpatialAnchor<D>::RawCoordinateSystemAdjusted(const Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::SpatialAnchor, Windows::Perception::Spatial::SpatialAnchorRawCoordinateSystemAdjustedEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ISpatialAnchor)->add_RawCoordinateSystemAdjusted(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ISpatialAnchor> impl_ISpatialAnchor<D>::RawCoordinateSystemAdjusted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::SpatialAnchor, Windows::Perception::Spatial::SpatialAnchorRawCoordinateSystemAdjustedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISpatialAnchor>(this, &ABI::Windows::Perception::Spatial::ISpatialAnchor::remove_RawCoordinateSystemAdjusted, RawCoordinateSystemAdjusted(handler));
}

template <typename D> void impl_ISpatialAnchor<D>::RawCoordinateSystemAdjusted(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ISpatialAnchor)->remove_RawCoordinateSystemAdjusted(cookie));
}

template <typename D> bool impl_ISpatialAnchor2<D>::RemovedByUser() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISpatialAnchor2)->get_RemovedByUser(&value));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialAnchor impl_ISpatialAnchorStatics<D>::TryCreateRelativeTo(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem) const
{
    Windows::Perception::Spatial::SpatialAnchor value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialAnchorStatics)->abi_TryCreateRelativeTo(get_abi(coordinateSystem), put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialAnchor impl_ISpatialAnchorStatics<D>::TryCreateRelativeTo(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Foundation::Numerics::float3 & position) const
{
    Windows::Perception::Spatial::SpatialAnchor value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialAnchorStatics)->abi_TryCreateWithPositionRelativeTo(get_abi(coordinateSystem), get_abi(position), put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialAnchor impl_ISpatialAnchorStatics<D>::TryCreateRelativeTo(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Foundation::Numerics::float3 & position, const Windows::Foundation::Numerics::quaternion & orientation) const
{
    Windows::Perception::Spatial::SpatialAnchor value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialAnchorStatics)->abi_TryCreateWithPositionAndOrientationRelativeTo(get_abi(coordinateSystem), get_abi(position), get_abi(orientation), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Perception::Spatial::SpatialAnchor> impl_ISpatialAnchorStore<D>::GetAllSavedAnchors() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Perception::Spatial::SpatialAnchor> value;
    check_hresult(WINRT_SHIM(ISpatialAnchorStore)->abi_GetAllSavedAnchors(put_abi(value)));
    return value;
}

template <typename D> bool impl_ISpatialAnchorStore<D>::TrySave(hstring_view id, const Windows::Perception::Spatial::SpatialAnchor & anchor) const
{
    bool succeeded {};
    check_hresult(WINRT_SHIM(ISpatialAnchorStore)->abi_TrySave(get_abi(id), get_abi(anchor), &succeeded));
    return succeeded;
}

template <typename D> void impl_ISpatialAnchorStore<D>::Remove(hstring_view id) const
{
    check_hresult(WINRT_SHIM(ISpatialAnchorStore)->abi_Remove(get_abi(id)));
}

template <typename D> void impl_ISpatialAnchorStore<D>::Clear() const
{
    check_hresult(WINRT_SHIM(ISpatialAnchorStore)->abi_Clear());
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Perception::Spatial::SpatialAnchorStore> impl_ISpatialAnchorManagerStatics<D>::RequestStoreAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Perception::Spatial::SpatialAnchorStore> value;
    check_hresult(WINRT_SHIM(ISpatialAnchorManagerStatics)->abi_RequestStoreAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Perception::Spatial::SpatialAnchor>> impl_ISpatialAnchorTransferManagerStatics<D>::TryImportAnchorsAsync(const Windows::Storage::Streams::IInputStream & stream) const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Perception::Spatial::SpatialAnchor>> operation;
    check_hresult(WINRT_SHIM(ISpatialAnchorTransferManagerStatics)->abi_TryImportAnchorsAsync(get_abi(stream), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISpatialAnchorTransferManagerStatics<D>::TryExportAnchorsAsync(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Perception::Spatial::SpatialAnchor>> anchors, const Windows::Storage::Streams::IOutputStream & stream) const
{
    Windows::Foundation::IAsyncOperation<bool> operation;
    check_hresult(WINRT_SHIM(ISpatialAnchorTransferManagerStatics)->abi_TryExportAnchorsAsync(get_abi(anchors), get_abi(stream), put_abi(operation)));
    return operation;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Perception::Spatial::SpatialPerceptionAccessStatus> impl_ISpatialAnchorTransferManagerStatics<D>::RequestAccessAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Perception::Spatial::SpatialPerceptionAccessStatus> result;
    check_hresult(WINRT_SHIM(ISpatialAnchorTransferManagerStatics)->abi_RequestAccessAsync(put_abi(result)));
    return result;
}

template <typename D> bool impl_ISpatialLocatorPositionalTrackingDeactivatingEventArgs<D>::Canceled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISpatialLocatorPositionalTrackingDeactivatingEventArgs)->get_Canceled(&value));
    return value;
}

template <typename D> void impl_ISpatialLocatorPositionalTrackingDeactivatingEventArgs<D>::Canceled(bool value) const
{
    check_hresult(WINRT_SHIM(ISpatialLocatorPositionalTrackingDeactivatingEventArgs)->put_Canceled(value));
}

template <typename D> Windows::Foundation::Numerics::float3 impl_ISpatialLocatorAttachedFrameOfReference<D>::RelativePosition() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(ISpatialLocatorAttachedFrameOfReference)->get_RelativePosition(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpatialLocatorAttachedFrameOfReference<D>::RelativePosition(const Windows::Foundation::Numerics::float3 & value) const
{
    check_hresult(WINRT_SHIM(ISpatialLocatorAttachedFrameOfReference)->put_RelativePosition(get_abi(value)));
}

template <typename D> Windows::Foundation::Numerics::quaternion impl_ISpatialLocatorAttachedFrameOfReference<D>::RelativeOrientation() const
{
    Windows::Foundation::Numerics::quaternion value {};
    check_hresult(WINRT_SHIM(ISpatialLocatorAttachedFrameOfReference)->get_RelativeOrientation(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpatialLocatorAttachedFrameOfReference<D>::RelativeOrientation(const Windows::Foundation::Numerics::quaternion & value) const
{
    check_hresult(WINRT_SHIM(ISpatialLocatorAttachedFrameOfReference)->put_RelativeOrientation(get_abi(value)));
}

template <typename D> void impl_ISpatialLocatorAttachedFrameOfReference<D>::AdjustHeading(double headingOffsetInRadians) const
{
    check_hresult(WINRT_SHIM(ISpatialLocatorAttachedFrameOfReference)->abi_AdjustHeading(headingOffsetInRadians));
}

template <typename D> Windows::Perception::Spatial::SpatialCoordinateSystem impl_ISpatialLocatorAttachedFrameOfReference<D>::GetStationaryCoordinateSystemAtTimestamp(const Windows::Perception::PerceptionTimestamp & timestamp) const
{
    Windows::Perception::Spatial::SpatialCoordinateSystem value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialLocatorAttachedFrameOfReference)->abi_GetStationaryCoordinateSystemAtTimestamp(get_abi(timestamp), put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IReference<double> impl_ISpatialLocatorAttachedFrameOfReference<D>::TryGetRelativeHeadingAtTimestamp(const Windows::Perception::PerceptionTimestamp & timestamp) const
{
    Windows::Foundation::IReference<double> value;
    check_hresult(WINRT_SHIM(ISpatialLocatorAttachedFrameOfReference)->abi_TryGetRelativeHeadingAtTimestamp(get_abi(timestamp), put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialCoordinateSystem impl_ISpatialStationaryFrameOfReference<D>::CoordinateSystem() const
{
    Windows::Perception::Spatial::SpatialCoordinateSystem value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialStationaryFrameOfReference)->get_CoordinateSystem(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float3 impl_ISpatialLocation<D>::Position() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(ISpatialLocation)->get_Position(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::quaternion impl_ISpatialLocation<D>::Orientation() const
{
    Windows::Foundation::Numerics::quaternion value {};
    check_hresult(WINRT_SHIM(ISpatialLocation)->get_Orientation(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float3 impl_ISpatialLocation<D>::AbsoluteLinearVelocity() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(ISpatialLocation)->get_AbsoluteLinearVelocity(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::float3 impl_ISpatialLocation<D>::AbsoluteLinearAcceleration() const
{
    Windows::Foundation::Numerics::float3 value {};
    check_hresult(WINRT_SHIM(ISpatialLocation)->get_AbsoluteLinearAcceleration(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::quaternion impl_ISpatialLocation<D>::AbsoluteAngularVelocity() const
{
    Windows::Foundation::Numerics::quaternion value {};
    check_hresult(WINRT_SHIM(ISpatialLocation)->get_AbsoluteAngularVelocity(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Numerics::quaternion impl_ISpatialLocation<D>::AbsoluteAngularAcceleration() const
{
    Windows::Foundation::Numerics::quaternion value {};
    check_hresult(WINRT_SHIM(ISpatialLocation)->get_AbsoluteAngularAcceleration(put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialLocatability impl_ISpatialLocator<D>::Locatability() const
{
    Windows::Perception::Spatial::SpatialLocatability value {};
    check_hresult(WINRT_SHIM(ISpatialLocator)->get_Locatability(&value));
    return value;
}

template <typename D> event_token impl_ISpatialLocator<D>::LocatabilityChanged(const Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::SpatialLocator, Windows::Foundation::IInspectable> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ISpatialLocator)->add_LocatabilityChanged(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ISpatialLocator> impl_ISpatialLocator<D>::LocatabilityChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::SpatialLocator, Windows::Foundation::IInspectable> & handler) const
{
    return impl::make_event_revoker<D, ISpatialLocator>(this, &ABI::Windows::Perception::Spatial::ISpatialLocator::remove_LocatabilityChanged, LocatabilityChanged(handler));
}

template <typename D> void impl_ISpatialLocator<D>::LocatabilityChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ISpatialLocator)->remove_LocatabilityChanged(cookie));
}

template <typename D> event_token impl_ISpatialLocator<D>::PositionalTrackingDeactivating(const Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::SpatialLocator, Windows::Perception::Spatial::SpatialLocatorPositionalTrackingDeactivatingEventArgs> & handler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ISpatialLocator)->add_PositionalTrackingDeactivating(get_abi(handler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ISpatialLocator> impl_ISpatialLocator<D>::PositionalTrackingDeactivating(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Perception::Spatial::SpatialLocator, Windows::Perception::Spatial::SpatialLocatorPositionalTrackingDeactivatingEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISpatialLocator>(this, &ABI::Windows::Perception::Spatial::ISpatialLocator::remove_PositionalTrackingDeactivating, PositionalTrackingDeactivating(handler));
}

template <typename D> void impl_ISpatialLocator<D>::PositionalTrackingDeactivating(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ISpatialLocator)->remove_PositionalTrackingDeactivating(cookie));
}

template <typename D> Windows::Perception::Spatial::SpatialLocation impl_ISpatialLocator<D>::TryLocateAtTimestamp(const Windows::Perception::PerceptionTimestamp & timestamp, const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem) const
{
    Windows::Perception::Spatial::SpatialLocation value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialLocator)->abi_TryLocateAtTimestamp(get_abi(timestamp), get_abi(coordinateSystem), put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialLocatorAttachedFrameOfReference impl_ISpatialLocator<D>::CreateAttachedFrameOfReferenceAtCurrentHeading() const
{
    Windows::Perception::Spatial::SpatialLocatorAttachedFrameOfReference value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialLocator)->abi_CreateAttachedFrameOfReferenceAtCurrentHeading(put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialLocatorAttachedFrameOfReference impl_ISpatialLocator<D>::CreateAttachedFrameOfReferenceAtCurrentHeading(const Windows::Foundation::Numerics::float3 & relativePosition) const
{
    Windows::Perception::Spatial::SpatialLocatorAttachedFrameOfReference value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialLocator)->abi_CreateAttachedFrameOfReferenceAtCurrentHeadingWithPosition(get_abi(relativePosition), put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialLocatorAttachedFrameOfReference impl_ISpatialLocator<D>::CreateAttachedFrameOfReferenceAtCurrentHeading(const Windows::Foundation::Numerics::float3 & relativePosition, const Windows::Foundation::Numerics::quaternion & relativeOrientation) const
{
    Windows::Perception::Spatial::SpatialLocatorAttachedFrameOfReference value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialLocator)->abi_CreateAttachedFrameOfReferenceAtCurrentHeadingWithPositionAndOrientation(get_abi(relativePosition), get_abi(relativeOrientation), put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialLocatorAttachedFrameOfReference impl_ISpatialLocator<D>::CreateAttachedFrameOfReferenceAtCurrentHeading(const Windows::Foundation::Numerics::float3 & relativePosition, const Windows::Foundation::Numerics::quaternion & relativeOrientation, double relativeHeadingInRadians) const
{
    Windows::Perception::Spatial::SpatialLocatorAttachedFrameOfReference value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialLocator)->abi_CreateAttachedFrameOfReferenceAtCurrentHeadingWithPositionAndOrientationAndRelativeHeading(get_abi(relativePosition), get_abi(relativeOrientation), relativeHeadingInRadians, put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialStationaryFrameOfReference impl_ISpatialLocator<D>::CreateStationaryFrameOfReferenceAtCurrentLocation() const
{
    Windows::Perception::Spatial::SpatialStationaryFrameOfReference value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialLocator)->abi_CreateStationaryFrameOfReferenceAtCurrentLocation(put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialStationaryFrameOfReference impl_ISpatialLocator<D>::CreateStationaryFrameOfReferenceAtCurrentLocation(const Windows::Foundation::Numerics::float3 & relativePosition) const
{
    Windows::Perception::Spatial::SpatialStationaryFrameOfReference value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialLocator)->abi_CreateStationaryFrameOfReferenceAtCurrentLocationWithPosition(get_abi(relativePosition), put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialStationaryFrameOfReference impl_ISpatialLocator<D>::CreateStationaryFrameOfReferenceAtCurrentLocation(const Windows::Foundation::Numerics::float3 & relativePosition, const Windows::Foundation::Numerics::quaternion & relativeOrientation) const
{
    Windows::Perception::Spatial::SpatialStationaryFrameOfReference value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialLocator)->abi_CreateStationaryFrameOfReferenceAtCurrentLocationWithPositionAndOrientation(get_abi(relativePosition), get_abi(relativeOrientation), put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialStationaryFrameOfReference impl_ISpatialLocator<D>::CreateStationaryFrameOfReferenceAtCurrentLocation(const Windows::Foundation::Numerics::float3 & relativePosition, const Windows::Foundation::Numerics::quaternion & relativeOrientation, double relativeHeadingInRadians) const
{
    Windows::Perception::Spatial::SpatialStationaryFrameOfReference value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialLocator)->abi_CreateStationaryFrameOfReferenceAtCurrentLocationWithPositionAndOrientationAndRelativeHeading(get_abi(relativePosition), get_abi(relativeOrientation), relativeHeadingInRadians, put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialLocator impl_ISpatialLocatorStatics<D>::GetDefault() const
{
    Windows::Perception::Spatial::SpatialLocator value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialLocatorStatics)->abi_GetDefault(put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialBoundingVolume impl_ISpatialBoundingVolumeStatics<D>::FromBox(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Perception::Spatial::SpatialBoundingBox & box) const
{
    Windows::Perception::Spatial::SpatialBoundingVolume value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialBoundingVolumeStatics)->abi_FromBox(get_abi(coordinateSystem), get_abi(box), put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialBoundingVolume impl_ISpatialBoundingVolumeStatics<D>::FromOrientedBox(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Perception::Spatial::SpatialBoundingOrientedBox & box) const
{
    Windows::Perception::Spatial::SpatialBoundingVolume value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialBoundingVolumeStatics)->abi_FromOrientedBox(get_abi(coordinateSystem), get_abi(box), put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialBoundingVolume impl_ISpatialBoundingVolumeStatics<D>::FromSphere(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Perception::Spatial::SpatialBoundingSphere & sphere) const
{
    Windows::Perception::Spatial::SpatialBoundingVolume value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialBoundingVolumeStatics)->abi_FromSphere(get_abi(coordinateSystem), get_abi(sphere), put_abi(value)));
    return value;
}

template <typename D> Windows::Perception::Spatial::SpatialBoundingVolume impl_ISpatialBoundingVolumeStatics<D>::FromFrustum(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Perception::Spatial::SpatialBoundingFrustum & frustum) const
{
    Windows::Perception::Spatial::SpatialBoundingVolume value { nullptr };
    check_hresult(WINRT_SHIM(ISpatialBoundingVolumeStatics)->abi_FromFrustum(get_abi(coordinateSystem), get_abi(frustum), put_abi(value)));
    return value;
}

inline Windows::Perception::Spatial::SpatialAnchor SpatialAnchor::TryCreateRelativeTo(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem)
{
    return get_activation_factory<SpatialAnchor, ISpatialAnchorStatics>().TryCreateRelativeTo(coordinateSystem);
}

inline Windows::Perception::Spatial::SpatialAnchor SpatialAnchor::TryCreateRelativeTo(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Foundation::Numerics::float3 & position)
{
    return get_activation_factory<SpatialAnchor, ISpatialAnchorStatics>().TryCreateRelativeTo(coordinateSystem, position);
}

inline Windows::Perception::Spatial::SpatialAnchor SpatialAnchor::TryCreateRelativeTo(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Foundation::Numerics::float3 & position, const Windows::Foundation::Numerics::quaternion & orientation)
{
    return get_activation_factory<SpatialAnchor, ISpatialAnchorStatics>().TryCreateRelativeTo(coordinateSystem, position, orientation);
}

inline Windows::Foundation::IAsyncOperation<Windows::Perception::Spatial::SpatialAnchorStore> SpatialAnchorManager::RequestStoreAsync()
{
    return get_activation_factory<SpatialAnchorManager, ISpatialAnchorManagerStatics>().RequestStoreAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IMapView<hstring, Windows::Perception::Spatial::SpatialAnchor>> SpatialAnchorTransferManager::TryImportAnchorsAsync(const Windows::Storage::Streams::IInputStream & stream)
{
    return get_activation_factory<SpatialAnchorTransferManager, ISpatialAnchorTransferManagerStatics>().TryImportAnchorsAsync(stream);
}

inline Windows::Foundation::IAsyncOperation<bool> SpatialAnchorTransferManager::TryExportAnchorsAsync(iterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Perception::Spatial::SpatialAnchor>> anchors, const Windows::Storage::Streams::IOutputStream & stream)
{
    return get_activation_factory<SpatialAnchorTransferManager, ISpatialAnchorTransferManagerStatics>().TryExportAnchorsAsync(anchors, stream);
}

inline Windows::Foundation::IAsyncOperation<winrt::Windows::Perception::Spatial::SpatialPerceptionAccessStatus> SpatialAnchorTransferManager::RequestAccessAsync()
{
    return get_activation_factory<SpatialAnchorTransferManager, ISpatialAnchorTransferManagerStatics>().RequestAccessAsync();
}

inline Windows::Perception::Spatial::SpatialBoundingVolume SpatialBoundingVolume::FromBox(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Perception::Spatial::SpatialBoundingBox & box)
{
    return get_activation_factory<SpatialBoundingVolume, ISpatialBoundingVolumeStatics>().FromBox(coordinateSystem, box);
}

inline Windows::Perception::Spatial::SpatialBoundingVolume SpatialBoundingVolume::FromOrientedBox(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Perception::Spatial::SpatialBoundingOrientedBox & box)
{
    return get_activation_factory<SpatialBoundingVolume, ISpatialBoundingVolumeStatics>().FromOrientedBox(coordinateSystem, box);
}

inline Windows::Perception::Spatial::SpatialBoundingVolume SpatialBoundingVolume::FromSphere(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Perception::Spatial::SpatialBoundingSphere & sphere)
{
    return get_activation_factory<SpatialBoundingVolume, ISpatialBoundingVolumeStatics>().FromSphere(coordinateSystem, sphere);
}

inline Windows::Perception::Spatial::SpatialBoundingVolume SpatialBoundingVolume::FromFrustum(const Windows::Perception::Spatial::SpatialCoordinateSystem & coordinateSystem, const Windows::Perception::Spatial::SpatialBoundingFrustum & frustum)
{
    return get_activation_factory<SpatialBoundingVolume, ISpatialBoundingVolumeStatics>().FromFrustum(coordinateSystem, frustum);
}

inline Windows::Perception::Spatial::SpatialLocator SpatialLocator::GetDefault()
{
    return get_activation_factory<SpatialLocator, ISpatialLocatorStatics>().GetDefault();
}

}

}
#pragma warning(pop)
