// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.UI.Xaml.3.h"
#include "internal/Windows.ApplicationModel.Background.3.h"
#include "internal/Windows.Graphics.Imaging.3.h"
#include "internal/Windows.UI.Xaml.Media.Imaging.3.h"
#include "Windows.UI.Xaml.Media.h"
#include "Windows.Foundation.h"
#include "internal/Windows.UI.Xaml.Media.Imaging.4.h"
#include "internal/Windows.UI.Xaml.Media.Imaging.5.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Media::Imaging {

template <typename L> DownloadProgressEventHandler::DownloadProgressEventHandler(L lambda) :
    DownloadProgressEventHandler(impl::make_delegate<impl_DownloadProgressEventHandler<L>, DownloadProgressEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> DownloadProgressEventHandler::DownloadProgressEventHandler(F * function) :
    DownloadProgressEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> DownloadProgressEventHandler::DownloadProgressEventHandler(O * object, M method) :
    DownloadProgressEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void DownloadProgressEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Media::Imaging::DownloadProgressEventArgs & e) const
{
    check_hresult((*(abi<DownloadProgressEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IBitmapImage> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IBitmapImage>
{
    HRESULT __stdcall get_CreateOptions(Windows::UI::Xaml::Media::Imaging::BitmapCreateOptions * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateOptions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CreateOptions(Windows::UI::Xaml::Media::Imaging::BitmapCreateOptions value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CreateOptions(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UriSource(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UriSource());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UriSource(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UriSource(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DecodePixelWidth(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DecodePixelWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DecodePixelWidth(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DecodePixelWidth(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DecodePixelHeight(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DecodePixelHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DecodePixelHeight(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DecodePixelHeight(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_DownloadProgress(impl::abi_arg_in<Windows::UI::Xaml::Media::Imaging::DownloadProgressEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().DownloadProgress(*reinterpret_cast<const Windows::UI::Xaml::Media::Imaging::DownloadProgressEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_DownloadProgress(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DownloadProgress(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ImageOpened(impl::abi_arg_in<Windows::UI::Xaml::RoutedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ImageOpened(*reinterpret_cast<const Windows::UI::Xaml::RoutedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ImageOpened(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ImageOpened(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ImageFailed(impl::abi_arg_in<Windows::UI::Xaml::ExceptionRoutedEventHandler> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ImageFailed(*reinterpret_cast<const Windows::UI::Xaml::ExceptionRoutedEventHandler *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ImageFailed(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ImageFailed(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IBitmapImage2> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IBitmapImage2>
{
    HRESULT __stdcall get_DecodePixelType(Windows::UI::Xaml::Media::Imaging::DecodePixelType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DecodePixelType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DecodePixelType(Windows::UI::Xaml::Media::Imaging::DecodePixelType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DecodePixelType(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IBitmapImage3> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IBitmapImage3>
{
    HRESULT __stdcall get_IsAnimatedBitmap(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAnimatedBitmap());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPlaying(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPlaying());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoPlay(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoPlay());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutoPlay(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoPlay(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Play() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Play();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Stop() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IBitmapImageFactory> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IBitmapImageFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithUriSource(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> uriSource, impl::abi_arg_out<Windows::UI::Xaml::Media::Imaging::IBitmapImage> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithUriSource(*reinterpret_cast<const Windows::Foundation::Uri *>(&uriSource)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics>
{
    HRESULT __stdcall get_CreateOptionsProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CreateOptionsProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UriSourceProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UriSourceProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DecodePixelWidthProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DecodePixelWidthProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_DecodePixelHeightProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DecodePixelHeightProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics2> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics2>
{
    HRESULT __stdcall get_DecodePixelTypeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DecodePixelTypeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics3> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IBitmapImageStatics3>
{
    HRESULT __stdcall get_IsAnimatedBitmapProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsAnimatedBitmapProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsPlayingProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsPlayingProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutoPlayProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoPlayProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IBitmapSource> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IBitmapSource>
{
    HRESULT __stdcall get_PixelWidth(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PixelWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PixelHeight(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PixelHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetSource(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> streamSource) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSource(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&streamSource));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetSourceAsync(impl::abi_arg_in<Windows::Storage::Streams::IRandomAccessStream> streamSource, impl::abi_arg_out<Windows::Foundation::IAsyncAction> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().SetSourceAsync(*reinterpret_cast<const Windows::Storage::Streams::IRandomAccessStream *>(&streamSource)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IBitmapSourceFactory> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IBitmapSourceFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::Imaging::IBitmapSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IBitmapSourceStatics> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IBitmapSourceStatics>
{
    HRESULT __stdcall get_PixelWidthProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PixelWidthProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PixelHeightProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PixelHeightProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IDownloadProgressEventArgs> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IDownloadProgressEventArgs>
{
    HRESULT __stdcall get_Progress(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Progress());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Progress(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Progress(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmap> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmap>
{
    HRESULT __stdcall get_PixelWidth(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PixelWidth());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PixelHeight(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PixelHeight());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RenderAsync(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, impl::abi_arg_out<Windows::Foundation::IAsyncAction> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().RenderAsync(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RenderToSizeAsync(impl::abi_arg_in<Windows::UI::Xaml::IUIElement> element, int32_t scaledWidth, int32_t scaledHeight, impl::abi_arg_out<Windows::Foundation::IAsyncAction> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().RenderAsync(*reinterpret_cast<const Windows::UI::Xaml::UIElement *>(&element), scaledWidth, scaledHeight));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPixelsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetPixelsAsync());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmapStatics> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IRenderTargetBitmapStatics>
{
    HRESULT __stdcall get_PixelWidthProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PixelWidthProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PixelHeightProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PixelHeightProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::ISoftwareBitmapSource> : produce_base<D, Windows::UI::Xaml::Media::Imaging::ISoftwareBitmapSource>
{
    HRESULT __stdcall abi_SetBitmapAsync(impl::abi_arg_in<Windows::Graphics::Imaging::ISoftwareBitmap> softwareBitmap, impl::abi_arg_out<Windows::Foundation::IAsyncAction> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().SetBitmapAsync(*reinterpret_cast<const Windows::Graphics::Imaging::SoftwareBitmap *>(&softwareBitmap)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource> : produce_base<D, Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::ISurfaceImageSourceFactory> : produce_base<D, Windows::UI::Xaml::Media::Imaging::ISurfaceImageSourceFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithDimensions(int32_t pixelWidth, int32_t pixelHeight, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithDimensions(pixelWidth, pixelHeight, *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInstanceWithDimensionsAndOpacity(int32_t pixelWidth, int32_t pixelHeight, bool isOpaque, impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::Imaging::ISurfaceImageSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithDimensionsAndOpacity(pixelWidth, pixelHeight, isOpaque, *reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSource> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSource>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSourceFactory> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSourceFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithDimensions(int32_t pixelWidth, int32_t pixelHeight, impl::abi_arg_out<Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithDimensions(pixelWidth, pixelHeight));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateInstanceWithDimensionsAndOpacity(int32_t pixelWidth, int32_t pixelHeight, bool isOpaque, impl::abi_arg_out<Windows::UI::Xaml::Media::Imaging::IVirtualSurfaceImageSource> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithDimensionsAndOpacity(pixelWidth, pixelHeight, isOpaque));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IWriteableBitmap> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IWriteableBitmap>
{
    HRESULT __stdcall get_PixelBuffer(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PixelBuffer());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Invalidate() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Invalidate();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IWriteableBitmapFactory> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IWriteableBitmapFactory>
{
    HRESULT __stdcall abi_CreateInstanceWithDimensions(int32_t pixelWidth, int32_t pixelHeight, impl::abi_arg_out<Windows::UI::Xaml::Media::Imaging::IWriteableBitmap> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstanceWithDimensions(pixelWidth, pixelHeight));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTask> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTask>
{};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskFactory> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::Foundation::IInspectable> outer, impl::abi_arg_out<Windows::Foundation::IInspectable> inner, impl::abi_arg_out<Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTask> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&outer), *inner));
            return S_OK;
        }
        catch (...)
        {
            *inner = nullptr;
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverrides> : produce_base<D, Windows::UI::Xaml::Media::Imaging::IXamlRenderingBackgroundTaskOverrides>
{
    HRESULT __stdcall abi_OnRun(impl::abi_arg_in<Windows::ApplicationModel::Background::IBackgroundTaskInstance> taskInstance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OnRun(*reinterpret_cast<const Windows::ApplicationModel::Background::IBackgroundTaskInstance *>(&taskInstance));
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

template <typename D> int32_t impl_IDownloadProgressEventArgs<D>::Progress() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IDownloadProgressEventArgs)->get_Progress(&value));
    return value;
}

template <typename D> void impl_IDownloadProgressEventArgs<D>::Progress(int32_t value) const
{
    check_hresult(WINRT_SHIM(IDownloadProgressEventArgs)->put_Progress(value));
}

template <typename D> int32_t impl_IBitmapSource<D>::PixelWidth() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IBitmapSource)->get_PixelWidth(&value));
    return value;
}

template <typename D> int32_t impl_IBitmapSource<D>::PixelHeight() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IBitmapSource)->get_PixelHeight(&value));
    return value;
}

template <typename D> void impl_IBitmapSource<D>::SetSource(const Windows::Storage::Streams::IRandomAccessStream & streamSource) const
{
    check_hresult(WINRT_SHIM(IBitmapSource)->abi_SetSource(get_abi(streamSource)));
}

template <typename D> Windows::Foundation::IAsyncAction impl_IBitmapSource<D>::SetSourceAsync(const Windows::Storage::Streams::IRandomAccessStream & streamSource) const
{
    Windows::Foundation::IAsyncAction returnValue;
    check_hresult(WINRT_SHIM(IBitmapSource)->abi_SetSourceAsync(get_abi(streamSource), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBitmapSourceStatics<D>::PixelWidthProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapSourceStatics)->get_PixelWidthProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBitmapSourceStatics<D>::PixelHeightProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapSourceStatics)->get_PixelHeightProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Imaging::BitmapSource impl_IBitmapSourceFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::Imaging::BitmapSource instance { nullptr };
    check_hresult(WINRT_SHIM(IBitmapSourceFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> int32_t impl_IRenderTargetBitmap<D>::PixelWidth() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IRenderTargetBitmap)->get_PixelWidth(&value));
    return value;
}

template <typename D> int32_t impl_IRenderTargetBitmap<D>::PixelHeight() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IRenderTargetBitmap)->get_PixelHeight(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IRenderTargetBitmap<D>::RenderAsync(const Windows::UI::Xaml::UIElement & element) const
{
    Windows::Foundation::IAsyncAction returnValue;
    check_hresult(WINRT_SHIM(IRenderTargetBitmap)->abi_RenderAsync(get_abi(element), put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IRenderTargetBitmap<D>::RenderAsync(const Windows::UI::Xaml::UIElement & element, int32_t scaledWidth, int32_t scaledHeight) const
{
    Windows::Foundation::IAsyncAction returnValue;
    check_hresult(WINRT_SHIM(IRenderTargetBitmap)->abi_RenderToSizeAsync(get_abi(element), scaledWidth, scaledHeight, put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_IRenderTargetBitmap<D>::GetPixelsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> returnValue;
    check_hresult(WINRT_SHIM(IRenderTargetBitmap)->abi_GetPixelsAsync(put_abi(returnValue)));
    return returnValue;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IRenderTargetBitmapStatics<D>::PixelWidthProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IRenderTargetBitmapStatics)->get_PixelWidthProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IRenderTargetBitmapStatics<D>::PixelHeightProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IRenderTargetBitmapStatics)->get_PixelHeightProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Imaging::SurfaceImageSource impl_ISurfaceImageSourceFactory<D>::CreateInstanceWithDimensions(int32_t pixelWidth, int32_t pixelHeight, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::Imaging::SurfaceImageSource instance { nullptr };
    check_hresult(WINRT_SHIM(ISurfaceImageSourceFactory)->abi_CreateInstanceWithDimensions(pixelWidth, pixelHeight, get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Media::Imaging::SurfaceImageSource impl_ISurfaceImageSourceFactory<D>::CreateInstanceWithDimensionsAndOpacity(int32_t pixelWidth, int32_t pixelHeight, bool isOpaque, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::Imaging::SurfaceImageSource instance { nullptr };
    check_hresult(WINRT_SHIM(ISurfaceImageSourceFactory)->abi_CreateInstanceWithDimensionsAndOpacity(pixelWidth, pixelHeight, isOpaque, get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Media::Imaging::BitmapCreateOptions impl_IBitmapImage<D>::CreateOptions() const
{
    Windows::UI::Xaml::Media::Imaging::BitmapCreateOptions value {};
    check_hresult(WINRT_SHIM(IBitmapImage)->get_CreateOptions(&value));
    return value;
}

template <typename D> void impl_IBitmapImage<D>::CreateOptions(Windows::UI::Xaml::Media::Imaging::BitmapCreateOptions value) const
{
    check_hresult(WINRT_SHIM(IBitmapImage)->put_CreateOptions(value));
}

template <typename D> Windows::Foundation::Uri impl_IBitmapImage<D>::UriSource() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapImage)->get_UriSource(put_abi(value)));
    return value;
}

template <typename D> void impl_IBitmapImage<D>::UriSource(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(IBitmapImage)->put_UriSource(get_abi(value)));
}

template <typename D> int32_t impl_IBitmapImage<D>::DecodePixelWidth() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IBitmapImage)->get_DecodePixelWidth(&value));
    return value;
}

template <typename D> void impl_IBitmapImage<D>::DecodePixelWidth(int32_t value) const
{
    check_hresult(WINRT_SHIM(IBitmapImage)->put_DecodePixelWidth(value));
}

template <typename D> int32_t impl_IBitmapImage<D>::DecodePixelHeight() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(IBitmapImage)->get_DecodePixelHeight(&value));
    return value;
}

template <typename D> void impl_IBitmapImage<D>::DecodePixelHeight(int32_t value) const
{
    check_hresult(WINRT_SHIM(IBitmapImage)->put_DecodePixelHeight(value));
}

template <typename D> event_token impl_IBitmapImage<D>::DownloadProgress(const Windows::UI::Xaml::Media::Imaging::DownloadProgressEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IBitmapImage)->add_DownloadProgress(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IBitmapImage> impl_IBitmapImage<D>::DownloadProgress(auto_revoke_t, const Windows::UI::Xaml::Media::Imaging::DownloadProgressEventHandler & value) const
{
    return impl::make_event_revoker<D, IBitmapImage>(this, &ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage::remove_DownloadProgress, DownloadProgress(value));
}

template <typename D> void impl_IBitmapImage<D>::DownloadProgress(event_token token) const
{
    check_hresult(WINRT_SHIM(IBitmapImage)->remove_DownloadProgress(token));
}

template <typename D> event_token impl_IBitmapImage<D>::ImageOpened(const Windows::UI::Xaml::RoutedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IBitmapImage)->add_ImageOpened(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IBitmapImage> impl_IBitmapImage<D>::ImageOpened(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const
{
    return impl::make_event_revoker<D, IBitmapImage>(this, &ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage::remove_ImageOpened, ImageOpened(value));
}

template <typename D> void impl_IBitmapImage<D>::ImageOpened(event_token token) const
{
    check_hresult(WINRT_SHIM(IBitmapImage)->remove_ImageOpened(token));
}

template <typename D> event_token impl_IBitmapImage<D>::ImageFailed(const Windows::UI::Xaml::ExceptionRoutedEventHandler & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(IBitmapImage)->add_ImageFailed(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<IBitmapImage> impl_IBitmapImage<D>::ImageFailed(auto_revoke_t, const Windows::UI::Xaml::ExceptionRoutedEventHandler & value) const
{
    return impl::make_event_revoker<D, IBitmapImage>(this, &ABI::Windows::UI::Xaml::Media::Imaging::IBitmapImage::remove_ImageFailed, ImageFailed(value));
}

template <typename D> void impl_IBitmapImage<D>::ImageFailed(event_token token) const
{
    check_hresult(WINRT_SHIM(IBitmapImage)->remove_ImageFailed(token));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBitmapImageStatics<D>::CreateOptionsProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapImageStatics)->get_CreateOptionsProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBitmapImageStatics<D>::UriSourceProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapImageStatics)->get_UriSourceProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBitmapImageStatics<D>::DecodePixelWidthProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapImageStatics)->get_DecodePixelWidthProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBitmapImageStatics<D>::DecodePixelHeightProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapImageStatics)->get_DecodePixelHeightProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Imaging::BitmapImage impl_IBitmapImageFactory<D>::CreateInstanceWithUriSource(const Windows::Foundation::Uri & uriSource) const
{
    Windows::UI::Xaml::Media::Imaging::BitmapImage instance { nullptr };
    check_hresult(WINRT_SHIM(IBitmapImageFactory)->abi_CreateInstanceWithUriSource(get_abi(uriSource), put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Media::Imaging::DecodePixelType impl_IBitmapImage2<D>::DecodePixelType() const
{
    Windows::UI::Xaml::Media::Imaging::DecodePixelType value {};
    check_hresult(WINRT_SHIM(IBitmapImage2)->get_DecodePixelType(&value));
    return value;
}

template <typename D> void impl_IBitmapImage2<D>::DecodePixelType(Windows::UI::Xaml::Media::Imaging::DecodePixelType value) const
{
    check_hresult(WINRT_SHIM(IBitmapImage2)->put_DecodePixelType(value));
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBitmapImageStatics2<D>::DecodePixelTypeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapImageStatics2)->get_DecodePixelTypeProperty(put_abi(value)));
    return value;
}

template <typename D> bool impl_IBitmapImage3<D>::IsAnimatedBitmap() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBitmapImage3)->get_IsAnimatedBitmap(&value));
    return value;
}

template <typename D> bool impl_IBitmapImage3<D>::IsPlaying() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBitmapImage3)->get_IsPlaying(&value));
    return value;
}

template <typename D> bool impl_IBitmapImage3<D>::AutoPlay() const
{
    bool value {};
    check_hresult(WINRT_SHIM(IBitmapImage3)->get_AutoPlay(&value));
    return value;
}

template <typename D> void impl_IBitmapImage3<D>::AutoPlay(bool value) const
{
    check_hresult(WINRT_SHIM(IBitmapImage3)->put_AutoPlay(value));
}

template <typename D> void impl_IBitmapImage3<D>::Play() const
{
    check_hresult(WINRT_SHIM(IBitmapImage3)->abi_Play());
}

template <typename D> void impl_IBitmapImage3<D>::Stop() const
{
    check_hresult(WINRT_SHIM(IBitmapImage3)->abi_Stop());
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBitmapImageStatics3<D>::IsAnimatedBitmapProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapImageStatics3)->get_IsAnimatedBitmapProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBitmapImageStatics3<D>::IsPlayingProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapImageStatics3)->get_IsPlayingProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IBitmapImageStatics3<D>::AutoPlayProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IBitmapImageStatics3)->get_AutoPlayProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Imaging::VirtualSurfaceImageSource impl_IVirtualSurfaceImageSourceFactory<D>::CreateInstanceWithDimensions(int32_t pixelWidth, int32_t pixelHeight) const
{
    Windows::UI::Xaml::Media::Imaging::VirtualSurfaceImageSource instance { nullptr };
    check_hresult(WINRT_SHIM(IVirtualSurfaceImageSourceFactory)->abi_CreateInstanceWithDimensions(pixelWidth, pixelHeight, put_abi(instance)));
    return instance;
}

template <typename D> Windows::UI::Xaml::Media::Imaging::VirtualSurfaceImageSource impl_IVirtualSurfaceImageSourceFactory<D>::CreateInstanceWithDimensionsAndOpacity(int32_t pixelWidth, int32_t pixelHeight, bool isOpaque) const
{
    Windows::UI::Xaml::Media::Imaging::VirtualSurfaceImageSource instance { nullptr };
    check_hresult(WINRT_SHIM(IVirtualSurfaceImageSourceFactory)->abi_CreateInstanceWithDimensionsAndOpacity(pixelWidth, pixelHeight, isOpaque, put_abi(instance)));
    return instance;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_IWriteableBitmap<D>::PixelBuffer() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(IWriteableBitmap)->get_PixelBuffer(put_abi(value)));
    return value;
}

template <typename D> void impl_IWriteableBitmap<D>::Invalidate() const
{
    check_hresult(WINRT_SHIM(IWriteableBitmap)->abi_Invalidate());
}

template <typename D> Windows::UI::Xaml::Media::Imaging::WriteableBitmap impl_IWriteableBitmapFactory<D>::CreateInstanceWithDimensions(int32_t pixelWidth, int32_t pixelHeight) const
{
    Windows::UI::Xaml::Media::Imaging::WriteableBitmap instance { nullptr };
    check_hresult(WINRT_SHIM(IWriteableBitmapFactory)->abi_CreateInstanceWithDimensions(pixelWidth, pixelHeight, put_abi(instance)));
    return instance;
}

template <typename D> void impl_IXamlRenderingBackgroundTaskOverrides<D>::OnRun(const Windows::ApplicationModel::Background::IBackgroundTaskInstance & taskInstance) const
{
    check_hresult(WINRT_SHIM(IXamlRenderingBackgroundTaskOverrides)->abi_OnRun(get_abi(taskInstance)));
}

template <typename D> Windows::UI::Xaml::Media::Imaging::XamlRenderingBackgroundTask impl_IXamlRenderingBackgroundTaskFactory<D>::CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const
{
    Windows::UI::Xaml::Media::Imaging::XamlRenderingBackgroundTask instance { nullptr };
    check_hresult(WINRT_SHIM(IXamlRenderingBackgroundTaskFactory)->abi_CreateInstance(get_abi(outer), put_abi(inner), put_abi(instance)));
    return instance;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISoftwareBitmapSource<D>::SetBitmapAsync(const Windows::Graphics::Imaging::SoftwareBitmap & softwareBitmap) const
{
    Windows::Foundation::IAsyncAction returnValue;
    check_hresult(WINRT_SHIM(ISoftwareBitmapSource)->abi_SetBitmapAsync(get_abi(softwareBitmap), put_abi(returnValue)));
    return returnValue;
}

inline BitmapImage::BitmapImage() :
    BitmapImage(activate_instance<BitmapImage>())
{}

inline BitmapImage::BitmapImage(const Windows::Foundation::Uri & uriSource) :
    BitmapImage(get_activation_factory<BitmapImage, IBitmapImageFactory>().CreateInstanceWithUriSource(uriSource))
{}

inline Windows::UI::Xaml::DependencyProperty BitmapImage::CreateOptionsProperty()
{
    return get_activation_factory<BitmapImage, IBitmapImageStatics>().CreateOptionsProperty();
}

inline Windows::UI::Xaml::DependencyProperty BitmapImage::UriSourceProperty()
{
    return get_activation_factory<BitmapImage, IBitmapImageStatics>().UriSourceProperty();
}

inline Windows::UI::Xaml::DependencyProperty BitmapImage::DecodePixelWidthProperty()
{
    return get_activation_factory<BitmapImage, IBitmapImageStatics>().DecodePixelWidthProperty();
}

inline Windows::UI::Xaml::DependencyProperty BitmapImage::DecodePixelHeightProperty()
{
    return get_activation_factory<BitmapImage, IBitmapImageStatics>().DecodePixelHeightProperty();
}

inline Windows::UI::Xaml::DependencyProperty BitmapImage::DecodePixelTypeProperty()
{
    return get_activation_factory<BitmapImage, IBitmapImageStatics2>().DecodePixelTypeProperty();
}

inline Windows::UI::Xaml::DependencyProperty BitmapImage::IsAnimatedBitmapProperty()
{
    return get_activation_factory<BitmapImage, IBitmapImageStatics3>().IsAnimatedBitmapProperty();
}

inline Windows::UI::Xaml::DependencyProperty BitmapImage::IsPlayingProperty()
{
    return get_activation_factory<BitmapImage, IBitmapImageStatics3>().IsPlayingProperty();
}

inline Windows::UI::Xaml::DependencyProperty BitmapImage::AutoPlayProperty()
{
    return get_activation_factory<BitmapImage, IBitmapImageStatics3>().AutoPlayProperty();
}

inline Windows::UI::Xaml::DependencyProperty BitmapSource::PixelWidthProperty()
{
    return get_activation_factory<BitmapSource, IBitmapSourceStatics>().PixelWidthProperty();
}

inline Windows::UI::Xaml::DependencyProperty BitmapSource::PixelHeightProperty()
{
    return get_activation_factory<BitmapSource, IBitmapSourceStatics>().PixelHeightProperty();
}

inline RenderTargetBitmap::RenderTargetBitmap() :
    RenderTargetBitmap(activate_instance<RenderTargetBitmap>())
{}

inline Windows::UI::Xaml::DependencyProperty RenderTargetBitmap::PixelWidthProperty()
{
    return get_activation_factory<RenderTargetBitmap, IRenderTargetBitmapStatics>().PixelWidthProperty();
}

inline Windows::UI::Xaml::DependencyProperty RenderTargetBitmap::PixelHeightProperty()
{
    return get_activation_factory<RenderTargetBitmap, IRenderTargetBitmapStatics>().PixelHeightProperty();
}

inline SoftwareBitmapSource::SoftwareBitmapSource() :
    SoftwareBitmapSource(activate_instance<SoftwareBitmapSource>())
{}

inline SurfaceImageSource::SurfaceImageSource(int32_t pixelWidth, int32_t pixelHeight)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<SurfaceImageSource, ISurfaceImageSourceFactory>().CreateInstanceWithDimensions(pixelWidth, pixelHeight, outer, inner));
}

inline SurfaceImageSource::SurfaceImageSource(int32_t pixelWidth, int32_t pixelHeight, bool isOpaque)
{
    Windows::Foundation::IInspectable outer, inner;
    impl_move(get_activation_factory<SurfaceImageSource, ISurfaceImageSourceFactory>().CreateInstanceWithDimensionsAndOpacity(pixelWidth, pixelHeight, isOpaque, outer, inner));
}

inline VirtualSurfaceImageSource::VirtualSurfaceImageSource(int32_t pixelWidth, int32_t pixelHeight) :
    VirtualSurfaceImageSource(get_activation_factory<VirtualSurfaceImageSource, IVirtualSurfaceImageSourceFactory>().CreateInstanceWithDimensions(pixelWidth, pixelHeight))
{}

inline VirtualSurfaceImageSource::VirtualSurfaceImageSource(int32_t pixelWidth, int32_t pixelHeight, bool isOpaque) :
    VirtualSurfaceImageSource(get_activation_factory<VirtualSurfaceImageSource, IVirtualSurfaceImageSourceFactory>().CreateInstanceWithDimensionsAndOpacity(pixelWidth, pixelHeight, isOpaque))
{}

inline WriteableBitmap::WriteableBitmap(int32_t pixelWidth, int32_t pixelHeight) :
    WriteableBitmap(get_activation_factory<WriteableBitmap, IWriteableBitmapFactory>().CreateInstanceWithDimensions(pixelWidth, pixelHeight))
{}

}

}
#pragma warning(pop)
