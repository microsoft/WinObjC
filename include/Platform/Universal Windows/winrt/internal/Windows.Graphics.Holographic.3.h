// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Graphics.Holographic.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Graphics::Holographic {

struct WINRT_EBO HolographicCamera :
    Windows::Graphics::Holographic::IHolographicCamera
{
    HolographicCamera(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HolographicCameraPose :
    Windows::Graphics::Holographic::IHolographicCameraPose
{
    HolographicCameraPose(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HolographicCameraRenderingParameters :
    Windows::Graphics::Holographic::IHolographicCameraRenderingParameters
{
    HolographicCameraRenderingParameters(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HolographicFrame :
    Windows::Graphics::Holographic::IHolographicFrame
{
    HolographicFrame(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HolographicFramePrediction :
    Windows::Graphics::Holographic::IHolographicFramePrediction
{
    HolographicFramePrediction(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HolographicSpace :
    Windows::Graphics::Holographic::IHolographicSpace
{
    HolographicSpace(std::nullptr_t) noexcept {}
    static Windows::Graphics::Holographic::HolographicSpace CreateForCoreWindow(const Windows::UI::Core::CoreWindow & window);
};

struct WINRT_EBO HolographicSpaceCameraAddedEventArgs :
    Windows::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs
{
    HolographicSpaceCameraAddedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO HolographicSpaceCameraRemovedEventArgs :
    Windows::Graphics::Holographic::IHolographicSpaceCameraRemovedEventArgs
{
    HolographicSpaceCameraRemovedEventArgs(std::nullptr_t) noexcept {}
};

}

}
