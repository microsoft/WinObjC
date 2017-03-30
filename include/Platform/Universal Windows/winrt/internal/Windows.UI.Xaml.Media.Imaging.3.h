// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Media.Imaging.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Media::Imaging {

template <typename H> struct impl_DownloadProgressEventHandler : implements<impl_DownloadProgressEventHandler<H>, abi<DownloadProgressEventHandler>>, H
{
    impl_DownloadProgressEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::Media::Imaging::IDownloadProgressEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::Media::Imaging::DownloadProgressEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Media::Imaging {

struct WINRT_EBO BitmapImage :
    Windows::UI::Xaml::Media::Imaging::IBitmapImage,
    impl::bases<BitmapImage, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::ImageSource, Windows::UI::Xaml::Media::Imaging::BitmapSource>,
    impl::require<BitmapImage, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IImageSource, Windows::UI::Xaml::Media::Imaging::IBitmapSource, Windows::UI::Xaml::Media::Imaging::IBitmapImage2, Windows::UI::Xaml::Media::Imaging::IBitmapImage3>
{
    BitmapImage(std::nullptr_t) noexcept {}
    BitmapImage();
    BitmapImage(const Windows::Foundation::Uri & uriSource);
    static Windows::UI::Xaml::DependencyProperty CreateOptionsProperty();
    static Windows::UI::Xaml::DependencyProperty UriSourceProperty();
    static Windows::UI::Xaml::DependencyProperty DecodePixelWidthProperty();
    static Windows::UI::Xaml::DependencyProperty DecodePixelHeightProperty();
    static Windows::UI::Xaml::DependencyProperty DecodePixelTypeProperty();
    static Windows::UI::Xaml::DependencyProperty IsAnimatedBitmapProperty();
    static Windows::UI::Xaml::DependencyProperty IsPlayingProperty();
    static Windows::UI::Xaml::DependencyProperty AutoPlayProperty();
};

struct WINRT_EBO BitmapSource :
    Windows::UI::Xaml::Media::Imaging::IBitmapSource,
    impl::bases<BitmapSource, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::ImageSource>,
    impl::require<BitmapSource, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IImageSource>
{
    BitmapSource(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty PixelWidthProperty();
    static Windows::UI::Xaml::DependencyProperty PixelHeightProperty();
};

struct WINRT_EBO DownloadProgressEventArgs :
    Windows::UI::Xaml::Media::Imaging::IDownloadProgressEventArgs
{
    DownloadProgressEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RenderTargetBitmap :
    Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmap,
    impl::bases<RenderTargetBitmap, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::ImageSource>,
    impl::require<RenderTargetBitmap, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IImageSource>
{
    RenderTargetBitmap(std::nullptr_t) noexcept {}
    RenderTargetBitmap();
    static Windows::UI::Xaml::DependencyProperty PixelWidthProperty();
    static Windows::UI::Xaml::DependencyProperty PixelHeightProperty();
};

struct WINRT_EBO SoftwareBitmapSource :
    Windows::UI::Xaml::Media::Imaging::ISoftwareBitmapSource,
    impl::bases<SoftwareBitmapSource, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::ImageSource>,
    impl::require<SoftwareBitmapSource, Windows::Foundation::IClosable, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IImageSource>
{
    SoftwareBitmapSource(std::nullptr_t) noexcept {}
    SoftwareBitmapSource();
};

struct WINRT_EBO SurfaceImageSource :
    Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource,
    impl::bases<SurfaceImageSource, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::ImageSource>,
    impl::require<SurfaceImageSource, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IImageSource>
{
    SurfaceImageSource(std::nullptr_t) noexcept {}
    SurfaceImageSource(int32_t pixelWidth, int32_t pixelHeight);
    SurfaceImageSource(int32_t pixelWidth, int32_t pixelHeight, bool isOpaque);
};

struct WINRT_EBO VirtualSurfaceImageSource :
    Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSource,
    impl::bases<VirtualSurfaceImageSource, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::ImageSource, Windows::UI::Xaml::Media::Imaging::SurfaceImageSource>,
    impl::require<VirtualSurfaceImageSource, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IImageSource, Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource>
{
    VirtualSurfaceImageSource(std::nullptr_t) noexcept {}
    VirtualSurfaceImageSource(int32_t pixelWidth, int32_t pixelHeight);
    VirtualSurfaceImageSource(int32_t pixelWidth, int32_t pixelHeight, bool isOpaque);
};

struct WINRT_EBO WriteableBitmap :
    Windows::UI::Xaml::Media::Imaging::IWriteableBitmap,
    impl::bases<WriteableBitmap, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Media::ImageSource, Windows::UI::Xaml::Media::Imaging::BitmapSource>,
    impl::require<WriteableBitmap, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::Media::IImageSource, Windows::UI::Xaml::Media::Imaging::IBitmapSource>
{
    WriteableBitmap(std::nullptr_t) noexcept {}
    WriteableBitmap(int32_t pixelWidth, int32_t pixelHeight);
};

struct WINRT_EBO XamlRenderingBackgroundTask :
    Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTask,
    impl::require<XamlRenderingBackgroundTask, Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverrides>
{
    XamlRenderingBackgroundTask(std::nullptr_t) noexcept {}
};

}

}
