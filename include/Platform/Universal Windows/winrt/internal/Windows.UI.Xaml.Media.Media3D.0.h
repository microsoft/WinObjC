// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Media::Media3D {

struct Matrix3D;

}

namespace Windows::UI::Xaml::Media::Media3D {

using Matrix3D = ABI::Windows::UI::Xaml::Media::Media3D::Matrix3D;

}

namespace ABI::Windows::UI::Xaml::Media::Media3D {

struct ICompositeTransform3D;
struct ICompositeTransform3DStatics;
struct IMatrix3DHelper;
struct IMatrix3DHelperStatics;
struct IPerspectiveTransform3D;
struct IPerspectiveTransform3DStatics;
struct ITransform3D;
struct ITransform3DFactory;
struct CompositeTransform3D;
struct Matrix3DHelper;
struct PerspectiveTransform3D;
struct Transform3D;

}

namespace Windows::UI::Xaml::Media::Media3D {

struct ICompositeTransform3D;
struct ICompositeTransform3DStatics;
struct IMatrix3DHelper;
struct IMatrix3DHelperStatics;
struct IPerspectiveTransform3D;
struct IPerspectiveTransform3DStatics;
struct ITransform3D;
struct ITransform3DFactory;
struct CompositeTransform3D;
struct Matrix3DHelper;
struct PerspectiveTransform3D;
struct Transform3D;

}

namespace Windows::UI::Xaml::Media::Media3D {

template <typename T> struct impl_ICompositeTransform3D;
template <typename T> struct impl_ICompositeTransform3DStatics;
template <typename T> struct impl_IMatrix3DHelper;
template <typename T> struct impl_IMatrix3DHelperStatics;
template <typename T> struct impl_IPerspectiveTransform3D;
template <typename T> struct impl_IPerspectiveTransform3DStatics;
template <typename T> struct impl_ITransform3D;
template <typename T> struct impl_ITransform3DFactory;

}

}
