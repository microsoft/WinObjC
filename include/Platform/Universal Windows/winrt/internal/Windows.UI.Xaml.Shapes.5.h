// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.4.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Shapes {

template <typename D, typename ... Interfaces> struct PathT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Shapes::IShape, Windows::UI::Xaml::Shapes::IShape2, Windows::UI::Xaml::Shapes::IPath>
{
    using composable = Path;

protected:

    PathT()
    {
        get_activation_factory<Path, IPathFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ShapeT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4, Windows::UI::Xaml::Shapes::IShape, Windows::UI::Xaml::Shapes::IShape2>
{
    using composable = Shape;

protected:

    ShapeT()
    {
        get_activation_factory<Shape, IShapeFactory>().CreateInstance(*this, this->m_inner);
    }
};

}

}
