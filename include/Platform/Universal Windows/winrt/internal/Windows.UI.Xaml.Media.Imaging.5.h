// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Media::Imaging {

template <typename D, typename ... Interfaces> struct BitmapSourceT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IImageSource, Windows::UI::Xaml::Media::Imaging::IBitmapSource>
{
    using composable = BitmapSource;

protected:

    BitmapSourceT()
    {
        get_activation_factory<BitmapSource, IBitmapSourceFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SurfaceImageSourceT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IImageSource, Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource>
{
    using composable = SurfaceImageSource;

protected:

    SurfaceImageSourceT(int32_t pixelWidth, int32_t pixelHeight)
    {
        get_activation_factory<SurfaceImageSource, ISurfaceImageSourceFactory>().CreateInstanceWithDimensions(pixelWidth, pixelHeight, *this, this->m_inner);
    }

    SurfaceImageSourceT(int32_t pixelWidth, int32_t pixelHeight, bool isOpaque)
    {
        get_activation_factory<SurfaceImageSource, ISurfaceImageSourceFactory>().CreateInstanceWithDimensionsAndOpacity(pixelWidth, pixelHeight, isOpaque, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct XamlRenderingBackgroundTaskT :
    overrides<D, Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTask>
{
    using composable = XamlRenderingBackgroundTask;

protected:

    XamlRenderingBackgroundTaskT()
    {
        get_activation_factory<XamlRenderingBackgroundTask, IXamlRenderingBackgroundTaskFactory>().CreateInstance(*this, this->m_inner);
    }
};

}

}
