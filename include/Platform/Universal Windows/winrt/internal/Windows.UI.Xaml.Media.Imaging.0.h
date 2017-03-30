// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Media::Imaging {

struct DownloadProgressEventHandler;
struct IBitmapImage;
struct IBitmapImage2;
struct IBitmapImage3;
struct IBitmapImageFactory;
struct IBitmapImageStatics;
struct IBitmapImageStatics2;
struct IBitmapImageStatics3;
struct IBitmapSource;
struct IBitmapSourceFactory;
struct IBitmapSourceStatics;
struct IDownloadProgressEventArgs;
struct IRenderTargetBitmap;
struct IRenderTargetBitmapStatics;
struct ISoftwareBitmapSource;
struct ISurfaceImageSource;
struct ISurfaceImageSourceFactory;
struct IVirtualSurfaceImageSource;
struct IVirtualSurfaceImageSourceFactory;
struct IWriteableBitmap;
struct IWriteableBitmapFactory;
struct IXamlRenderingBackgroundTask;
struct IXamlRenderingBackgroundTaskFactory;
struct IXamlRenderingBackgroundTaskOverrides;
struct BitmapImage;
struct BitmapSource;
struct DownloadProgressEventArgs;
struct RenderTargetBitmap;
struct SoftwareBitmapSource;
struct SurfaceImageSource;
struct VirtualSurfaceImageSource;
struct WriteableBitmap;
struct XamlRenderingBackgroundTask;

}

namespace Windows::UI::Xaml::Media::Imaging {

struct DownloadProgressEventHandler;
struct IBitmapImage;
struct IBitmapImage2;
struct IBitmapImage3;
struct IBitmapImageFactory;
struct IBitmapImageStatics;
struct IBitmapImageStatics2;
struct IBitmapImageStatics3;
struct IBitmapSource;
struct IBitmapSourceFactory;
struct IBitmapSourceStatics;
struct IDownloadProgressEventArgs;
struct IRenderTargetBitmap;
struct IRenderTargetBitmapStatics;
struct ISoftwareBitmapSource;
struct ISurfaceImageSource;
struct ISurfaceImageSourceFactory;
struct IVirtualSurfaceImageSource;
struct IVirtualSurfaceImageSourceFactory;
struct IWriteableBitmap;
struct IWriteableBitmapFactory;
struct IXamlRenderingBackgroundTask;
struct IXamlRenderingBackgroundTaskFactory;
struct IXamlRenderingBackgroundTaskOverrides;
struct BitmapImage;
struct BitmapSource;
struct DownloadProgressEventArgs;
struct RenderTargetBitmap;
struct SoftwareBitmapSource;
struct SurfaceImageSource;
struct VirtualSurfaceImageSource;
struct WriteableBitmap;
struct XamlRenderingBackgroundTask;

}

namespace Windows::UI::Xaml::Media::Imaging {

template <typename T> struct impl_IBitmapImage;
template <typename T> struct impl_IBitmapImage2;
template <typename T> struct impl_IBitmapImage3;
template <typename T> struct impl_IBitmapImageFactory;
template <typename T> struct impl_IBitmapImageStatics;
template <typename T> struct impl_IBitmapImageStatics2;
template <typename T> struct impl_IBitmapImageStatics3;
template <typename T> struct impl_IBitmapSource;
template <typename T> struct impl_IBitmapSourceFactory;
template <typename T> struct impl_IBitmapSourceStatics;
template <typename T> struct impl_IDownloadProgressEventArgs;
template <typename T> struct impl_IRenderTargetBitmap;
template <typename T> struct impl_IRenderTargetBitmapStatics;
template <typename T> struct impl_ISoftwareBitmapSource;
template <typename T> struct impl_ISurfaceImageSource;
template <typename T> struct impl_ISurfaceImageSourceFactory;
template <typename T> struct impl_IVirtualSurfaceImageSource;
template <typename T> struct impl_IVirtualSurfaceImageSourceFactory;
template <typename T> struct impl_IWriteableBitmap;
template <typename T> struct impl_IWriteableBitmapFactory;
template <typename T> struct impl_IXamlRenderingBackgroundTask;
template <typename T> struct impl_IXamlRenderingBackgroundTaskFactory;
template <typename T> struct impl_IXamlRenderingBackgroundTaskOverrides;
template <typename T> struct impl_DownloadProgressEventHandler;

}

namespace Windows::UI::Xaml::Media::Imaging {

enum class BitmapCreateOptions : unsigned
{
    None = 0x0,
    IgnoreImageCache = 0x8,
};

DEFINE_ENUM_FLAG_OPERATORS(BitmapCreateOptions)

enum class DecodePixelType
{
    Physical = 0,
    Logical = 1,
};

}

}
