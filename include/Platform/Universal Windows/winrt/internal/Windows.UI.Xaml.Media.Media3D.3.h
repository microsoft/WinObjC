// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Media.Media3D.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Media::Media3D {

struct WINRT_EBO CompositeTransform3D :
    Windows::UI::Xaml::Media::Media3D::ICompositeTransform3D,
    impl::bases<CompositeTransform3D, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Media3D::Transform3D>,
    impl::require<CompositeTransform3D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Media3D::ITransform3D>
{
    CompositeTransform3D(std::nullptr_t) noexcept {}
    CompositeTransform3D();
    static Windows::UI::Xaml::DependencyProperty CenterXProperty();
    static Windows::UI::Xaml::DependencyProperty CenterYProperty();
    static Windows::UI::Xaml::DependencyProperty CenterZProperty();
    static Windows::UI::Xaml::DependencyProperty RotationXProperty();
    static Windows::UI::Xaml::DependencyProperty RotationYProperty();
    static Windows::UI::Xaml::DependencyProperty RotationZProperty();
    static Windows::UI::Xaml::DependencyProperty ScaleXProperty();
    static Windows::UI::Xaml::DependencyProperty ScaleYProperty();
    static Windows::UI::Xaml::DependencyProperty ScaleZProperty();
    static Windows::UI::Xaml::DependencyProperty TranslateXProperty();
    static Windows::UI::Xaml::DependencyProperty TranslateYProperty();
    static Windows::UI::Xaml::DependencyProperty TranslateZProperty();
};

struct WINRT_EBO Matrix3DHelper :
    Windows::UI::Xaml::Media::Media3D::IMatrix3DHelper
{
    Matrix3DHelper(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Media::Media3D::Matrix3D Identity();
    static Windows::UI::Xaml::Media::Media3D::Matrix3D Multiply(const Windows::UI::Xaml::Media::Media3D::Matrix3D & matrix1, const Windows::UI::Xaml::Media::Media3D::Matrix3D & matrix2);
    static Windows::UI::Xaml::Media::Media3D::Matrix3D FromElements(double m11, double m12, double m13, double m14, double m21, double m22, double m23, double m24, double m31, double m32, double m33, double m34, double offsetX, double offsetY, double offsetZ, double m44);
    static bool GetHasInverse(const Windows::UI::Xaml::Media::Media3D::Matrix3D & target);
    static bool GetIsIdentity(const Windows::UI::Xaml::Media::Media3D::Matrix3D & target);
    static Windows::UI::Xaml::Media::Media3D::Matrix3D Invert(const Windows::UI::Xaml::Media::Media3D::Matrix3D & target);
};

struct WINRT_EBO PerspectiveTransform3D :
    Windows::UI::Xaml::Media::Media3D::IPerspectiveTransform3D,
    impl::bases<PerspectiveTransform3D, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::Media3D::Transform3D>,
    impl::require<PerspectiveTransform3D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Media3D::ITransform3D>
{
    PerspectiveTransform3D(std::nullptr_t) noexcept {}
    PerspectiveTransform3D();
    static Windows::UI::Xaml::DependencyProperty DepthProperty();
    static Windows::UI::Xaml::DependencyProperty OffsetXProperty();
    static Windows::UI::Xaml::DependencyProperty OffsetYProperty();
};

struct WINRT_EBO Transform3D :
    Windows::UI::Xaml::Media::Media3D::ITransform3D,
    impl::bases<Transform3D, Windows::UI::Xaml::DependencyObject>,
    impl::require<Transform3D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    Transform3D(std::nullptr_t) noexcept {}
};

}

}
