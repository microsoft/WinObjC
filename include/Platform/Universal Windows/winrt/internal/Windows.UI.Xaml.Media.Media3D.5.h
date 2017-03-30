// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Media::Media3D {

template <typename D, typename ... Interfaces> struct Transform3DT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::Media3D::ITransform3D>
{
    using composable = Transform3D;

protected:

    Transform3DT()
    {
        get_activation_factory<Transform3D, ITransform3DFactory>().CreateInstance(*this, this->m_inner);
    }
};

}

}
