// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.Media.Imaging.0.h"
#include "Windows.ApplicationModel.Background.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Graphics.Imaging.0.h"
#include "Windows.Storage.Streams.0.h"
#include "Windows.UI.Xaml.0.h"
#include "Windows.Storage.Streams.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Media::Imaging {

struct __declspec(uuid("1abaee23-74ee-4cc7-99ba-b171e3cda61e")) __declspec(novtable) DownloadProgressEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Media::Imaging::IDownloadProgressEventArgs * e) = 0;
};

struct __declspec(uuid("31af3271-e3b4-442d-a341-4c0226b2725b")) __declspec(novtable) IBitmapImage : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CreateOptions(winrt::Windows::UI::Xaml::Media::Imaging::BitmapCreateOptions * value) = 0;
    virtual HRESULT __stdcall put_CreateOptions(winrt::Windows::UI::Xaml::Media::Imaging::BitmapCreateOptions value) = 0;
    virtual HRESULT __stdcall get_UriSource(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_UriSource(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_DecodePixelWidth(int32_t * value) = 0;
    virtual HRESULT __stdcall put_DecodePixelWidth(int32_t value) = 0;
    virtual HRESULT __stdcall get_DecodePixelHeight(int32_t * value) = 0;
    virtual HRESULT __stdcall put_DecodePixelHeight(int32_t value) = 0;
    virtual HRESULT __stdcall add_DownloadProgress(Windows::UI::Xaml::Media::Imaging::DownloadProgressEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DownloadProgress(event_token token) = 0;
    virtual HRESULT __stdcall add_ImageOpened(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ImageOpened(event_token token) = 0;
    virtual HRESULT __stdcall add_ImageFailed(Windows::UI::Xaml::ExceptionRoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ImageFailed(event_token token) = 0;
};

struct __declspec(uuid("1069c1b6-8c9b-4762-be3d-759f5698f2b3")) __declspec(novtable) IBitmapImage2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DecodePixelType(winrt::Windows::UI::Xaml::Media::Imaging::DecodePixelType * value) = 0;
    virtual HRESULT __stdcall put_DecodePixelType(winrt::Windows::UI::Xaml::Media::Imaging::DecodePixelType value) = 0;
};

struct __declspec(uuid("f1de6f26-3c73-453f-a7ba-9b85c18b3733")) __declspec(novtable) IBitmapImage3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsAnimatedBitmap(bool * value) = 0;
    virtual HRESULT __stdcall get_IsPlaying(bool * value) = 0;
    virtual HRESULT __stdcall get_AutoPlay(bool * value) = 0;
    virtual HRESULT __stdcall put_AutoPlay(bool value) = 0;
    virtual HRESULT __stdcall abi_Play() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
};

struct __declspec(uuid("c9132978-4810-4e5e-8087-03671ee60d85")) __declspec(novtable) IBitmapImageFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithUriSource(Windows::Foundation::IUriRuntimeClass * uriSource, Windows::UI::Xaml::Media::Imaging::IBitmapImage ** instance) = 0;
};

struct __declspec(uuid("9e282143-70e8-437c-9fa4-2cbf295cff84")) __declspec(novtable) IBitmapImageStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CreateOptionsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_UriSourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DecodePixelWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DecodePixelHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("c5f5576a-75af-41a4-b893-8fe91fee2882")) __declspec(novtable) IBitmapImageStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DecodePixelTypeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("2b44e30d-f6d5-4411-a8cd-bf7603c4faa0")) __declspec(novtable) IBitmapImageStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsAnimatedBitmapProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsPlayingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AutoPlayProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("23d86411-202f-41b2-8c5b-a8a3b333800b")) __declspec(novtable) IBitmapSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PixelWidth(int32_t * value) = 0;
    virtual HRESULT __stdcall get_PixelHeight(int32_t * value) = 0;
    virtual HRESULT __stdcall abi_SetSource(Windows::Storage::Streams::IRandomAccessStream * streamSource) = 0;
    virtual HRESULT __stdcall abi_SetSourceAsync(Windows::Storage::Streams::IRandomAccessStream * streamSource, Windows::Foundation::IAsyncAction ** returnValue) = 0;
};

struct __declspec(uuid("e240420e-d4a7-49a4-a0b4-a59fdd77e508")) __declspec(novtable) IBitmapSourceFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Media::Imaging::IBitmapSource ** instance) = 0;
};

struct __declspec(uuid("9a9c9981-827b-4e51-891b-8a15b511842d")) __declspec(novtable) IBitmapSourceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PixelWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PixelHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("7311e0d4-fe94-4e70-9b90-cdd47ac23afb")) __declspec(novtable) IDownloadProgressEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Progress(int32_t * value) = 0;
    virtual HRESULT __stdcall put_Progress(int32_t value) = 0;
};

struct __declspec(uuid("500dee81-893c-4c0a-8fec-4678ac717589")) __declspec(novtable) IRenderTargetBitmap : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PixelWidth(int32_t * value) = 0;
    virtual HRESULT __stdcall get_PixelHeight(int32_t * value) = 0;
    virtual HRESULT __stdcall abi_RenderAsync(Windows::UI::Xaml::IUIElement * element, Windows::Foundation::IAsyncAction ** returnValue) = 0;
    virtual HRESULT __stdcall abi_RenderToSizeAsync(Windows::UI::Xaml::IUIElement * element, int32_t scaledWidth, int32_t scaledHeight, Windows::Foundation::IAsyncAction ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetPixelsAsync(Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> ** returnValue) = 0;
};

struct __declspec(uuid("f0a1efee-c131-4d40-9c47-f7d7cf2b077f")) __declspec(novtable) IRenderTargetBitmapStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PixelWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PixelHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("d2dd9ed0-d3c5-4056-91b5-b7c1d1e8130e")) __declspec(novtable) ISoftwareBitmapSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetBitmapAsync(Windows::Graphics::Imaging::ISoftwareBitmap * softwareBitmap, Windows::Foundation::IAsyncAction ** returnValue) = 0;
};

struct __declspec(uuid("62f7d416-c714-4c4c-8273-f839bc58135c")) __declspec(novtable) ISurfaceImageSource : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("3ab2212a-ef65-4a5f-bfac-73993e8c12c9")) __declspec(novtable) ISurfaceImageSourceFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithDimensions(int32_t pixelWidth, int32_t pixelHeight, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateInstanceWithDimensionsAndOpacity(int32_t pixelWidth, int32_t pixelHeight, bool isOpaque, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource ** instance) = 0;
};

struct __declspec(uuid("4a711fea-bfac-11e0-a06a-9de44724019b")) __declspec(novtable) IVirtualSurfaceImageSource : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("3ab2212a-bfac-11e0-8a92-69e44724019b")) __declspec(novtable) IVirtualSurfaceImageSourceFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithDimensions(int32_t pixelWidth, int32_t pixelHeight, Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSource ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateInstanceWithDimensionsAndOpacity(int32_t pixelWidth, int32_t pixelHeight, bool isOpaque, Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSource ** instance) = 0;
};

struct __declspec(uuid("bf0b7e6f-df7c-4a85-8413-a1216285835c")) __declspec(novtable) IWriteableBitmap : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PixelBuffer(Windows::Storage::Streams::IBuffer ** value) = 0;
    virtual HRESULT __stdcall abi_Invalidate() = 0;
};

struct __declspec(uuid("5563ebb1-3ef2-42c5-9c6d-1cf5dcc041ff")) __declspec(novtable) IWriteableBitmapFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithDimensions(int32_t pixelWidth, int32_t pixelHeight, Windows::UI::Xaml::Media::Imaging::IWriteableBitmap ** instance) = 0;
};

struct __declspec(uuid("5d5fe9aa-533e-44b8-a975-fc5f1e3bff52")) __declspec(novtable) IXamlRenderingBackgroundTask : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("a3d1bb63-38f8-4da3-9fca-fd8128a2cbf9")) __declspec(novtable) IXamlRenderingBackgroundTaskFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTask ** instance) = 0;
};

struct __declspec(uuid("9c2a6997-a908-4711-b4b2-a960db3d8e5a")) __declspec(novtable) IXamlRenderingBackgroundTaskOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnRun(Windows::ApplicationModel::Background::IBackgroundTaskInstance * taskInstance) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::Media::Imaging::BitmapImage> { using default_interface = Windows::UI::Xaml::Media::Imaging::IBitmapImage; };
template <> struct traits<Windows::UI::Xaml::Media::Imaging::BitmapSource> { using default_interface = Windows::UI::Xaml::Media::Imaging::IBitmapSource; };
template <> struct traits<Windows::UI::Xaml::Media::Imaging::DownloadProgressEventArgs> { using default_interface = Windows::UI::Xaml::Media::Imaging::IDownloadProgressEventArgs; };
template <> struct traits<Windows::UI::Xaml::Media::Imaging::RenderTargetBitmap> { using default_interface = Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmap; };
template <> struct traits<Windows::UI::Xaml::Media::Imaging::SoftwareBitmapSource> { using default_interface = Windows::UI::Xaml::Media::Imaging::ISoftwareBitmapSource; };
template <> struct traits<Windows::UI::Xaml::Media::Imaging::SurfaceImageSource> { using default_interface = Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource; };
template <> struct traits<Windows::UI::Xaml::Media::Imaging::VirtualSurfaceImageSource> { using default_interface = Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSource; };
template <> struct traits<Windows::UI::Xaml::Media::Imaging::WriteableBitmap> { using default_interface = Windows::UI::Xaml::Media::Imaging::IWriteableBitmap; };
template <> struct traits<Windows::UI::Xaml::Media::Imaging::XamlRenderingBackgroundTask> { using default_interface = Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTask; };

}

namespace Windows::UI::Xaml::Media::Imaging {

template <typename D>
struct WINRT_EBO impl_IBitmapImage
{
    Windows::UI::Xaml::Media::Imaging::BitmapCreateOptions CreateOptions() const;
    void CreateOptions(Windows::UI::Xaml::Media::Imaging::BitmapCreateOptions value) const;
    Windows::Foundation::Uri UriSource() const;
    void UriSource(const Windows::Foundation::Uri & value) const;
    int32_t DecodePixelWidth() const;
    void DecodePixelWidth(int32_t value) const;
    int32_t DecodePixelHeight() const;
    void DecodePixelHeight(int32_t value) const;
    event_token DownloadProgress(const Windows::UI::Xaml::Media::Imaging::DownloadProgressEventHandler & value) const;
    using DownloadProgress_revoker = event_revoker<IBitmapImage>;
    DownloadProgress_revoker DownloadProgress(auto_revoke_t, const Windows::UI::Xaml::Media::Imaging::DownloadProgressEventHandler & value) const;
    void DownloadProgress(event_token token) const;
    event_token ImageOpened(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using ImageOpened_revoker = event_revoker<IBitmapImage>;
    ImageOpened_revoker ImageOpened(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void ImageOpened(event_token token) const;
    event_token ImageFailed(const Windows::UI::Xaml::ExceptionRoutedEventHandler & value) const;
    using ImageFailed_revoker = event_revoker<IBitmapImage>;
    ImageFailed_revoker ImageFailed(auto_revoke_t, const Windows::UI::Xaml::ExceptionRoutedEventHandler & value) const;
    void ImageFailed(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapImage2
{
    Windows::UI::Xaml::Media::Imaging::DecodePixelType DecodePixelType() const;
    void DecodePixelType(Windows::UI::Xaml::Media::Imaging::DecodePixelType value) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapImage3
{
    bool IsAnimatedBitmap() const;
    bool IsPlaying() const;
    bool AutoPlay() const;
    void AutoPlay(bool value) const;
    void Play() const;
    void Stop() const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapImageFactory
{
    Windows::UI::Xaml::Media::Imaging::BitmapImage CreateInstanceWithUriSource(const Windows::Foundation::Uri & uriSource) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapImageStatics
{
    Windows::UI::Xaml::DependencyProperty CreateOptionsProperty() const;
    Windows::UI::Xaml::DependencyProperty UriSourceProperty() const;
    Windows::UI::Xaml::DependencyProperty DecodePixelWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty DecodePixelHeightProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapImageStatics2
{
    Windows::UI::Xaml::DependencyProperty DecodePixelTypeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapImageStatics3
{
    Windows::UI::Xaml::DependencyProperty IsAnimatedBitmapProperty() const;
    Windows::UI::Xaml::DependencyProperty IsPlayingProperty() const;
    Windows::UI::Xaml::DependencyProperty AutoPlayProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapSource
{
    int32_t PixelWidth() const;
    int32_t PixelHeight() const;
    void SetSource(const Windows::Storage::Streams::IRandomAccessStream & streamSource) const;
    Windows::Foundation::IAsyncAction SetSourceAsync(const Windows::Storage::Streams::IRandomAccessStream & streamSource) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapSourceFactory
{
    Windows::UI::Xaml::Media::Imaging::BitmapSource CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IBitmapSourceStatics
{
    Windows::UI::Xaml::DependencyProperty PixelWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty PixelHeightProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IDownloadProgressEventArgs
{
    int32_t Progress() const;
    void Progress(int32_t value) const;
};

template <typename D>
struct WINRT_EBO impl_IRenderTargetBitmap
{
    int32_t PixelWidth() const;
    int32_t PixelHeight() const;
    Windows::Foundation::IAsyncAction RenderAsync(const Windows::UI::Xaml::UIElement & element) const;
    Windows::Foundation::IAsyncAction RenderAsync(const Windows::UI::Xaml::UIElement & element, int32_t scaledWidth, int32_t scaledHeight) const;
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> GetPixelsAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IRenderTargetBitmapStatics
{
    Windows::UI::Xaml::DependencyProperty PixelWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty PixelHeightProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ISoftwareBitmapSource
{
    Windows::Foundation::IAsyncAction SetBitmapAsync(const Windows::Graphics::Imaging::SoftwareBitmap & softwareBitmap) const;
};

template <typename D>
struct WINRT_EBO impl_ISurfaceImageSource
{
};

template <typename D>
struct WINRT_EBO impl_ISurfaceImageSourceFactory
{
    Windows::UI::Xaml::Media::Imaging::SurfaceImageSource CreateInstanceWithDimensions(int32_t pixelWidth, int32_t pixelHeight, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
    Windows::UI::Xaml::Media::Imaging::SurfaceImageSource CreateInstanceWithDimensionsAndOpacity(int32_t pixelWidth, int32_t pixelHeight, bool isOpaque, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IVirtualSurfaceImageSource
{
};

template <typename D>
struct WINRT_EBO impl_IVirtualSurfaceImageSourceFactory
{
    Windows::UI::Xaml::Media::Imaging::VirtualSurfaceImageSource CreateInstanceWithDimensions(int32_t pixelWidth, int32_t pixelHeight) const;
    Windows::UI::Xaml::Media::Imaging::VirtualSurfaceImageSource CreateInstanceWithDimensionsAndOpacity(int32_t pixelWidth, int32_t pixelHeight, bool isOpaque) const;
};

template <typename D>
struct WINRT_EBO impl_IWriteableBitmap
{
    Windows::Storage::Streams::IBuffer PixelBuffer() const;
    void Invalidate() const;
};

template <typename D>
struct WINRT_EBO impl_IWriteableBitmapFactory
{
    Windows::UI::Xaml::Media::Imaging::WriteableBitmap CreateInstanceWithDimensions(int32_t pixelWidth, int32_t pixelHeight) const;
};

template <typename D>
struct WINRT_EBO impl_IXamlRenderingBackgroundTask
{
};

template <typename D>
struct WINRT_EBO impl_IXamlRenderingBackgroundTaskFactory
{
    Windows::UI::Xaml::Media::Imaging::XamlRenderingBackgroundTask CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IXamlRenderingBackgroundTaskOverrides
{
    void OnRun(const Windows::ApplicationModel::Background::IBackgroundTaskInstance & taskInstance) const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Media::Imaging::DownloadProgressEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::DownloadProgressEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IBitmapImage>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IBitmapImage<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IBitmapImage2>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage2;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IBitmapImage2<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IBitmapImage3>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage3;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IBitmapImage3<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IBitmapImageFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImageFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IBitmapImageFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IBitmapImageStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics2>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics2;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IBitmapImageStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics3>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics3;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IBitmapImageStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IBitmapSource>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IBitmapSource;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IBitmapSource<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IBitmapSourceFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IBitmapSourceFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IBitmapSourceFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IBitmapSourceStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IBitmapSourceStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IBitmapSourceStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IDownloadProgressEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IDownloadProgressEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IDownloadProgressEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmap>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmap;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IRenderTargetBitmap<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmapStatics>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmapStatics;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IRenderTargetBitmapStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::ISoftwareBitmapSource>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::ISoftwareBitmapSource;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_ISoftwareBitmapSource<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_ISurfaceImageSource<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::ISurfaceImageSourceFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::ISurfaceImageSourceFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_ISurfaceImageSourceFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSource>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSource;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IVirtualSurfaceImageSource<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSourceFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSourceFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IVirtualSurfaceImageSourceFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IWriteableBitmap>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IWriteableBitmap;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IWriteableBitmap<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IWriteableBitmapFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IWriteableBitmapFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IWriteableBitmapFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTask>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTask;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IXamlRenderingBackgroundTask<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskFactory>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskFactory;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IXamlRenderingBackgroundTaskFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverrides>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverrides;
    template <typename D> using consume = Windows::UI::Xaml::Media::Imaging::impl_IXamlRenderingBackgroundTaskOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::BitmapImage>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::BitmapImage;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.Imaging.BitmapImage"; }
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::BitmapSource>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::BitmapSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.Imaging.BitmapSource"; }
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::DownloadProgressEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::DownloadProgressEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.Imaging.DownloadProgressEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::RenderTargetBitmap>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::RenderTargetBitmap;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.Imaging.RenderTargetBitmap"; }
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::SoftwareBitmapSource>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::SoftwareBitmapSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.Imaging.SoftwareBitmapSource"; }
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::SurfaceImageSource>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::SurfaceImageSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.Imaging.SurfaceImageSource"; }
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::VirtualSurfaceImageSource>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::VirtualSurfaceImageSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.Imaging.VirtualSurfaceImageSource"; }
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::WriteableBitmap>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::WriteableBitmap;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.Imaging.WriteableBitmap"; }
};

template <> struct traits<Windows::UI::Xaml::Media::Imaging::XamlRenderingBackgroundTask>
{
    using abi = ABI::Windows::UI::Xaml::Media::Imaging::XamlRenderingBackgroundTask;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Media.Imaging.XamlRenderingBackgroundTask"; }
};

}

}
