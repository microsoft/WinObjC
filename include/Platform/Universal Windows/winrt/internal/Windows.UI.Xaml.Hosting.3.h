// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Hosting.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Hosting {

struct WINRT_EBO ElementCompositionPreview :
    Windows::UI::Xaml::Hosting::IElementCompositionPreview
{
    ElementCompositionPreview(std::nullptr_t) noexcept {}
    static Windows::UI::Composition::Visual GetElementVisual(const Windows::UI::Xaml::UIElement & element);
    static Windows::UI::Composition::Visual GetElementChildVisual(const Windows::UI::Xaml::UIElement & element);
    static void SetElementChildVisual(const Windows::UI::Xaml::UIElement & element, const Windows::UI::Composition::Visual & visual);
    static Windows::UI::Composition::CompositionPropertySet GetScrollViewerManipulationPropertySet(const Windows::UI::Xaml::Controls::ScrollViewer & scrollViewer);
};

struct WINRT_EBO XamlUIPresenter :
    Windows::UI::Xaml::Hosting::IXamlUIPresenter
{
    XamlUIPresenter(std::nullptr_t) noexcept {}
    static bool CompleteTimelinesAutomatically();
    static void CompleteTimelinesAutomatically(bool value);
    static void SetHost(const Windows::UI::Xaml::Hosting::IXamlUIPresenterHost & host);
    static void NotifyWindowSizeChanged();
    static Windows::Foundation::Rect GetFlyoutPlacementTargetInfo(const Windows::UI::Xaml::FrameworkElement & placementTarget, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode preferredPlacement, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode & targetPreferredPlacement, bool & allowFallbacks);
    static Windows::Foundation::Rect GetFlyoutPlacement(const Windows::Foundation::Rect & placementTargetBounds, const Windows::Foundation::Size & controlSize, const Windows::Foundation::Size & minControlSize, const Windows::Foundation::Rect & containerRect, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode targetPreferredPlacement, bool allowFallbacks, Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode & chosenPlacement);
};

}

}
